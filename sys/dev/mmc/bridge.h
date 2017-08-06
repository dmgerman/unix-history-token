begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Portions of this software may have been developed with reference to  * the SD Simplified Specification.  The following disclaimer may apply:  *  * The following conditions apply to the release of the simplified  * specification ("Simplified Specification") by the SD Card Association and  * the SD Group. The Simplified Specification is a subset of the complete SD  * Specification which is owned by the SD Card Association and the SD  * Group. This Simplified Specification is provided on a non-confidential  * basis subject to the disclaimers below. Any implementation of the  * Simplified Specification may require a license from the SD Card  * Association, SD Group, SD-3C LLC or other third parties.  *  * Disclaimers:  *  * The information contained in the Simplified Specification is presented only  * as a standard specification for SD Cards and SD Host/Ancillary products and  * is provided "AS-IS" without any representations or warranties of any  * kind. No responsibility is assumed by the SD Group, SD-3C LLC or the SD  * Card Association for any damages, any infringements of patents or other  * right of the SD Group, SD-3C LLC, the SD Card Association or any third  * parties, which may result from its use. No license is granted by  * implication, estoppel or otherwise under any patent or other rights of the  * SD Group, SD-3C LLC, the SD Card Association or any third party. Nothing  * herein shall be construed as an obligation by the SD Group, the SD-3C LLC  * or the SD Card Association to disclose or distribute any technical  * information, know-how or other confidential information to any third party.  *  * $FreeBSD$  */
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

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_comment
comment|/*  * This file defines interfaces for the mmc bridge.  The names chosen  * are similar to or the same as the names used in Linux to allow for  * easy porting of what Linux calls mmc host drivers.  I use the  * FreeBSD terminology of bridge and bus for consistency with other  * drivers in the system.  This file corresponds roughly to the Linux  * linux/mmc/host.h file.  *  * A mmc bridge is a chipset that can have one or more mmc and/or sd  * cards attached to it.  mmc devices are attached on a bus topology,  * while sd and sdio cards usually are attached using a star topology  * (meaning in practice each sd card has its own, independent slot).  * Since SDHCI v3.00, buses for esd and esdio are possible, though.  *  * Attached to the mmc bridge is an mmcbus.  The mmcbus is described  * in dev/mmc/mmcbus_if.m.  */
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
name|mmc_vccq
block|{
name|vccq_120
init|=
literal|0
block|,
name|vccq_180
block|,
name|vccq_330
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

begin_enum
enum|enum
name|mmc_drv_type
block|{
name|drv_type_b
init|=
literal|0
block|,
name|drv_type_a
block|,
name|drv_type_c
block|,
name|drv_type_d
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mmc_bus_timing
block|{
name|bus_timing_normal
init|=
literal|0
block|,
name|bus_timing_hs
block|,
name|bus_timing_uhs_sdr12
block|,
name|bus_timing_uhs_sdr25
block|,
name|bus_timing_uhs_sdr50
block|,
name|bus_timing_uhs_ddr50
block|,
name|bus_timing_uhs_sdr104
block|,
name|bus_timing_mmc_ddr52
block|,
name|bus_timing_mmc_hs200
block|,
name|bus_timing_mmc_hs400
block|,
name|bus_timing_mmc_hs400es
block|,
name|bus_timing_max
init|=
name|bus_timing_mmc_hs400es
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
comment|/* Voltage to apply to the power pins */
name|enum
name|mmc_vccq
name|vccq
decl_stmt|;
comment|/* Voltage to use for signaling */
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
name|enum
name|mmc_bus_timing
name|timing
decl_stmt|;
name|enum
name|mmc_drv_type
name|drv_type
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

begin_enum
enum|enum
name|mmc_retune_req
block|{
name|retune_req_none
init|=
literal|0
block|,
name|retune_req_normal
block|,
name|retune_req_reset
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
value|(1<<  0)
comment|/* Can do 4-bit data transfers */
define|#
directive|define
name|MMC_CAP_8_BIT_DATA
value|(1<<  1)
comment|/* Can do 8-bit data transfers */
define|#
directive|define
name|MMC_CAP_HSPEED
value|(1<<  2)
comment|/* Can do High Speed transfers */
define|#
directive|define
name|MMC_CAP_BOOT_NOACC
value|(1<<  4)
comment|/* Cannot access boot partitions */
define|#
directive|define
name|MMC_CAP_WAIT_WHILE_BUSY
value|(1<<  5)
comment|/* Host waits for busy responses */
define|#
directive|define
name|MMC_CAP_UHS_SDR12
value|(1<<  6)
comment|/* Can do UHS SDR12 */
define|#
directive|define
name|MMC_CAP_UHS_SDR25
value|(1<<  7)
comment|/* Can do UHS SDR25 */
define|#
directive|define
name|MMC_CAP_UHS_SDR50
value|(1<<  8)
comment|/* Can do UHS SDR50 */
define|#
directive|define
name|MMC_CAP_UHS_SDR104
value|(1<<  9)
comment|/* Can do UHS SDR104 */
define|#
directive|define
name|MMC_CAP_UHS_DDR50
value|(1<< 10)
comment|/* Can do UHS DDR50 */
define|#
directive|define
name|MMC_CAP_MMC_DDR52_120
value|(1<< 11)
comment|/* Can do eMMC DDR52 at 1.2 V */
define|#
directive|define
name|MMC_CAP_MMC_DDR52_180
value|(1<< 12)
comment|/* Can do eMMC DDR52 at 1.8 V */
define|#
directive|define
name|MMC_CAP_MMC_DDR52
value|(MMC_CAP_MMC_DDR52_120 | MMC_CAP_MMC_DDR52_180)
define|#
directive|define
name|MMC_CAP_MMC_HS200_120
value|(1<< 13)
comment|/* Can do eMMC HS200 at 1.2 V */
define|#
directive|define
name|MMC_CAP_MMC_HS200_180
value|(1<< 14)
comment|/* Can do eMMC HS200 at 1.8 V */
define|#
directive|define
name|MMC_CAP_MMC_HS200
value|(MMC_CAP_MMC_HS200_120| MMC_CAP_MMC_HS200_180)
define|#
directive|define
name|MMC_CAP_MMC_HS400_120
value|(1<< 15)
comment|/* Can do eMMC HS400 at 1.2 V */
define|#
directive|define
name|MMC_CAP_MMC_HS400_180
value|(1<< 16)
comment|/* Can do eMMC HS400 at 1.8 V */
define|#
directive|define
name|MMC_CAP_MMC_HS400
value|(MMC_CAP_MMC_HS400_120 | MMC_CAP_MMC_HS400_180)
define|#
directive|define
name|MMC_CAP_MMC_HSX00_120
value|(MMC_CAP_MMC_HS200_120 | MMC_CAP_MMC_HS400_120)
define|#
directive|define
name|MMC_CAP_MMC_ENH_STROBE
value|(1<< 17)
comment|/* Can do eMMC Enhanced Strobe */
define|#
directive|define
name|MMC_CAP_SIGNALING_120
value|(1<< 18)
comment|/* Can do signaling at 1.2 V */
define|#
directive|define
name|MMC_CAP_SIGNALING_180
value|(1<< 19)
comment|/* Can do signaling at 1.8 V */
define|#
directive|define
name|MMC_CAP_SIGNALING_330
value|(1<< 20)
comment|/* Can do signaling at 3.3 V */
define|#
directive|define
name|MMC_CAP_DRIVER_TYPE_A
value|(1<< 21)
comment|/* Can do Driver Type A */
define|#
directive|define
name|MMC_CAP_DRIVER_TYPE_C
value|(1<< 22)
comment|/* Can do Driver Type C */
define|#
directive|define
name|MMC_CAP_DRIVER_TYPE_D
value|(1<< 23)
comment|/* Can do Driver Type D */
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

begin_decl_stmt
specifier|extern
name|driver_t
name|mmc_driver
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|mmc_devclass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MMC_VERSION
value|4
end_define

begin_define
define|#
directive|define
name|MMC_DECLARE_BRIDGE
parameter_list|(
name|name
parameter_list|)
define|\
value|DRIVER_MODULE(mmc, name, mmc_driver, mmc_devclass, NULL, NULL);	\     MODULE_DEPEND(name, mmc, MMC_VERSION, MMC_VERSION, MMC_VERSION);
end_define

begin_define
define|#
directive|define
name|MMC_DEPEND
parameter_list|(
name|name
parameter_list|)
define|\
value|MODULE_DEPEND(name, mmc, MMC_VERSION, MMC_VERSION, MMC_VERSION);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_MMC_BRIDGE_H */
end_comment

end_unit

