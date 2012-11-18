/*
 * Copyright (C) 2013 Samsung Electronics
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/dwmmc.h>
#include <asm/arch/power.h>
#include <asm/arch/gpio.h>

#include "setup.h"

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_USB_EHCI_EXYNOS
void board_usb_init(int value)
{
	struct exynos5_gpio_part1 *gpio = (struct exynos5_gpio_part1 *)
						samsung_get_base_gpio_part1();

	/* Configure gpios for usb 3503 hub's reset and connect */
	s5p_gpio_direction_output(&gpio->x3, 5, value);
	s5p_gpio_direction_output(&gpio->d1, 7, value);
}
#endif

int board_init(void)
{
	gd->bd->bi_boot_params = (PHYS_SDRAM_1 + 0x100UL);
	return 0;
}

int dram_init(void)
{
	int i;
	u32 addr;

	for (i = 0; i < CONFIG_NR_DRAM_BANKS; i++) {
		addr = CONFIG_SYS_SDRAM_BASE + (i * SDRAM_BANK_SIZE);
		gd->ram_size += get_ram_size((long *)addr, SDRAM_BANK_SIZE);
	}
	return 0;
}

int power_init_board(void)
{
	set_ps_hold_ctrl();
	return 0;
}

void dram_init_banksize(void)
{
	int i;
	u32 addr, size;

	for (i = 0; i < CONFIG_NR_DRAM_BANKS; i++) {
		addr = CONFIG_SYS_SDRAM_BASE + (i * SDRAM_BANK_SIZE);
		size = get_ram_size((long *)addr, SDRAM_BANK_SIZE);

		gd->bd->bi_dram[i].start = addr;
		gd->bd->bi_dram[i].size = size;
	}
}

#ifdef CONFIG_GENERIC_MMC
int board_mmc_init(bd_t *bis)
{
	int ret;
	/* dwmmc initializattion for available channels */
	ret = exynos_dwmmc_init(gd->fdt_blob);
	if (ret)
		debug("dwmmc init failed\n");

	return ret;
}
#endif

static int board_uart_init(void)
{
	int err, uart_id, ret = 0;

	for (uart_id = PERIPH_ID_UART0; uart_id <= PERIPH_ID_UART3; uart_id++) {
		err = exynos_pinmux_config(uart_id, PINMUX_FLAG_NONE);
		if (err) {
			debug("UART%d not configured\n",
					 (uart_id - PERIPH_ID_UART0));
			ret |= err;
		}
	}
	return ret;
}

#ifdef CONFIG_BOARD_EARLY_INIT_F
int board_early_init_f(void)
{
	int err;
	err = board_uart_init();
	if (err) {
		debug("UART init failed\n");
		return err;
	}
	return err;
}
#endif

#ifdef CONFIG_BOARD_LATE_INIT
int board_late_init(void)
{
	int i;
	uchar mac[6];
	unsigned int guid_high = readl(EXYNOS5_GUID_HIGH);
	unsigned int guid_low = readl(EXYNOS5_GUID_LOW);

	for (i = 0; i < 2; i++)
		mac[i] = (guid_high >> (8 * (1 - i))) & 0xFF;

	for (i = 0; i < 4; i++)
		mac[i+2] = (guid_low >> (8 * (3 - i))) & 0xFF;

	/* mark it as not multicast and outside official 80211 MAC namespace */
	mac[0] = (mac[0] & ~0x1) | 0x2;

	eth_setenv_enetaddr("ethaddr", mac);
	eth_setenv_enetaddr("usbethaddr", mac);

#ifdef CONFIG_PREBOOT
	setenv("preboot", CONFIG_PREBOOT);
#endif
}
#endif


#ifdef CONFIG_DISPLAY_BOARDINFO
int checkboard(void)
{
	printf("\nBoard: Arndale\n");

	return 0;
}
#endif

void arch_preboot_os(void)
{
	/*
	 * We should now long be done with accessing any peripherals or
	 * setting up any other hardware state that needs to be set up from
	 * the secure mode (TrustZone), so we can switch to non-secure mode
	 * and we rely on board-specific logic to put a board-specific monitor
	 * in place for stuff like L2 cache maintenance and power management.
	 */
	enter_ns();

	/*
	 * Enter Hyp mode immediately before booting the kernel to allow
	 * the first Linux kernel access to and control of Hyp mode so that
	 * modules like KVM can run VMs.
	 *
	 * Without further ado...
	 */
	enter_hyp();
}
