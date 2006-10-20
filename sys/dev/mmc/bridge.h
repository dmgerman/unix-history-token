begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEV_MMC_BRIDGE_H
end_ifndef

begin_define
define|#
directive|define
name|DEV_MMC_BRIDGE_H
end_define

begin_comment
comment|/*  * This file defines interfaces for the mmc bridge.  The names chosen  * are similar to or the same as the names used in Linux to allow for  * easy porting of what Linux calls mmc host drivers.  I use the  * FreeBSD terminology of bridge and bus for consistancy with other  * drivers in the system.  This file corresponds roughly to the Linux  * linux/mmc/host.h file.  *  * A mmc bridge is a chipset that can have one or more mmc and/or sd  * cards attached to it.  mmc cards are attached on a bus topology,  * while sd and sdio cards are attached using a star topology (meaning  * in practice each sd card has its own, independent slot).  Each  * mmcbr is assumed to be derived from the mmcbr.  This is done to  * allow for easier addition of bridges (as each bridge does not need  * to be added to the mmcbus file).  *  * Attached to the mmc bridge is an mmcbus.  The mmcbus is described  * in dev/mmc/bus.h.  */
end_comment

begin_comment
comment|/*  * mmc_ios is a structure that is used to store the state of the mmc/sd  * bus configuration.  This include the bus' clock speed, its voltage,  * the bus mode for command output, the SPI chip select, some power  * states and the bus width.  */
end_comment

begin_enum
enum|enum
name|mmc_vdd
block|{
name|vdd_150
init|=
literal|0
block|,
name|vdd_155
block|,
name|vdd_160
block|,
name|vdd_165
block|,
name|vdd_170
block|,
name|vdd_180
block|,
name|vdd_190
block|,
name|vdd_200
block|,
name|vdd_210
block|,
name|vdd_220
block|,
name|vdd_230
block|,
name|vdd_240
block|,
name|vdd_250
block|,
name|vdd_260
block|,
name|vdd_270
block|,
name|vdd_280
block|,
name|vdd_290
block|,
name|vdd_300
block|,
name|vdd_310
block|,
name|vdd_320
block|,
name|vdd_330
block|,
name|vdd_340
block|,
name|vdd_350
block|,
name|vdd_360
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mmc_power_mode
block|{
name|power_off
init|=
literal|0
block|,
name|power_up
block|,
name|power_on
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mmc_bus_mode
block|{
name|opendrain
init|=
literal|1
block|,
name|pushpull
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mmc_chip_select
block|{
name|cs_dontcare
init|=
literal|0
block|,
name|cs_high
block|,
name|cs_low
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mmc_bus_width
block|{
name|bus_width_1
init|=
literal|0
block|,
name|bus_width_4
init|=
literal|2
block|,
name|bus_width_8
init|=
literal|3
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mmc_ios
block|{
name|uint32_t
name|clock
decl_stmt|;
comment|/* Speed of the clock in Hz to move data */
name|enum
name|mmc_vdd
name|vdd
decl_stmt|;
comment|/* Voltage to apply to the power pins/ */
name|enum
name|mmc_bus_mode
name|bus_mode
decl_stmt|;
name|enum
name|mmc_chip_select
name|chip_select
decl_stmt|;
name|enum
name|mmc_bus_width
name|bus_width
decl_stmt|;
name|enum
name|mmc_power_mode
name|power_mode
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|mmc_card_mode
block|{
name|mode_mmc
block|,
name|mode_sd
block|}
enum|;
end_enum

begin_struct
struct|struct
name|mmc_host
block|{
name|int
name|f_min
decl_stmt|;
name|int
name|f_max
decl_stmt|;
name|uint32_t
name|host_ocr
decl_stmt|;
name|uint32_t
name|ocr
decl_stmt|;
name|uint32_t
name|caps
decl_stmt|;
define|#
directive|define
name|MMC_CAP_4_BIT_DATA
value|(1<< 0)
comment|/* Can do 4-bit data transfers */
define|#
directive|define
name|MMC_CAP_8_BIT_DATA
value|(1<< 1)
comment|/* Can do 8-bit data transfers */
name|enum
name|mmc_card_mode
name|mode
decl_stmt|;
name|struct
name|mmc_ios
name|ios
decl_stmt|;
comment|/* Current state of the host */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMC_BRIDGE_H */
end_comment

end_unit

