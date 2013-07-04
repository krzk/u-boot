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

#undef CONFIG_DEFAULT_DEVICE_TREE
#define CONFIG_DEFAULT_DEVICE_TREE	exynos5250-arndale

#undef CONFIG_ENV_IS_IN_SPI_FLASH
#define CONFIG_ENV_IS_IN_MMC

#undef CONFIG_KEYBOARD
#undef CONFIG_CROS_EC_KEYB
#undef CONFIG_CROS_EC_SPI

#endif	/* __CONFIG_ARNDALE_H */
