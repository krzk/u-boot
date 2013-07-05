/*
 * Copyright (C) 2013 Samsung Electronics
 *
 * Configuration settings for the SAMSUNG Arndale board.
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

#ifndef __CONFIG_ARNDALE_H
#define __CONFIG_ARNDALE_H

#include <configs/exynos5250-dt.h>

#define CONFIG_ARNDALE

#undef CONFIG_DEFAULT_DEVICE_TREE
#define CONFIG_DEFAULT_DEVICE_TREE	exynos5250-arndale

#undef CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_BOOTM_BOOTARGS_APPEND_MAC
#define CONFIG_BOARD_LATE_INIT

#undef CONFIG_KEYBOARD
#undef CONFIG_CROS_EC_KEYB
#undef CONFIG_CROS_EC_SPI

#define CONFIG_SYS_USB_EHCI_MAX_ROOT_PORTS	3
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_ASIX

/* SYSFLAGS register */
#define CONFIG_SYSFLAGS_ADDR	0x02020000

/* secondary SMP pens */
#define CONFIG_SPL_MAX_SIZE	(14 * 1024)
#define CONFIG_SPL_SMP_PEN	(CONFIG_SPL_TEXT_BASE + CONFIG_SPL_MAX_SIZE - 8)

#endif	/* __CONFIG_ARNDALE_H */
