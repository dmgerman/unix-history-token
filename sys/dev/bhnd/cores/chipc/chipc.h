begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPC_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPC_H_
end_define

begin_include
include|#
directive|include
file|<dev/bhnd/bhnd.h>
end_include

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_nvram.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_chipc_if.h"
end_include

begin_comment
comment|/**  * Supported ChipCommon flash types.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CHIPC_FLASH_NONE
init|=
literal|0
block|,
comment|/**< No flash, or a type unrecognized 					     by the ChipCommon driver */
name|CHIPC_PFLASH_CFI
init|=
literal|1
block|,
comment|/**< CFI-compatible parallel flash */
name|CHIPC_SFLASH_ST
init|=
literal|2
block|,
comment|/**< ST serial flash */
name|CHIPC_SFLASH_AT
init|=
literal|3
block|,
comment|/**< Atmel serial flash */
name|CHIPC_QSFLASH_ST
init|=
literal|4
block|,
comment|/**< ST quad-SPI flash */
name|CHIPC_QSFLASH_AT
init|=
literal|5
block|,
comment|/**< Atmel quad-SPI flash */
name|CHIPC_NFLASH
init|=
literal|6
block|,
comment|/**< NAND flash */
name|CHIPC_NFLASH_4706
init|=
literal|7
comment|/**< BCM4706 NAND flash */
block|}
name|chipc_flash
typedef|;
end_typedef

begin_comment
comment|/**  * ChipCommon capability flags;  */
end_comment

begin_struct
struct|struct
name|chipc_caps
block|{
name|uint8_t
name|num_uarts
decl_stmt|;
comment|/**< Number of attached UARTS (1-3) */
name|bool
name|mipseb
decl_stmt|;
comment|/**< MIPS is big-endian */
name|uint8_t
name|uart_clock
decl_stmt|;
comment|/**< UART clock source (see CHIPC_CAP_UCLKSEL_*) */
name|uint8_t
name|uart_gpio
decl_stmt|;
comment|/**< UARTs own GPIO pins 12-15 */
name|uint8_t
name|extbus_type
decl_stmt|;
comment|/**< ExtBus type (CHIPC_CAP_EXTBUS_*) */
name|chipc_flash
name|flash_type
decl_stmt|;
comment|/**< flash type */
name|uint8_t
name|cfi_width
decl_stmt|;
comment|/**< CFI bus width, 0 if unknown or CFI 					     not present */
name|bhnd_nvram_src
name|nvram_src
decl_stmt|;
comment|/**< identified NVRAM source */
name|bus_size_t
name|sprom_offset
decl_stmt|;
comment|/**< Offset to SPROM data within 					     SPROM/OTP, 0 if unknown or not 					     present */
name|uint8_t
name|otp_size
decl_stmt|;
comment|/**< OTP (row?) size, 0 if not present */
name|uint8_t
name|pll_type
decl_stmt|;
comment|/**< PLL type */
name|bool
name|pwr_ctrl
decl_stmt|;
comment|/**< Power/clock control available */
name|bool
name|jtag_master
decl_stmt|;
comment|/**< JTAG Master present */
name|bool
name|boot_rom
decl_stmt|;
comment|/**< Internal boot ROM is active */
name|uint8_t
name|backplane_64
decl_stmt|;
comment|/**< Backplane supports 64-bit addressing. 					     Note that this does not gaurantee 					     the CPU itself supports 64-bit 					     addressing. */
name|bool
name|pmu
decl_stmt|;
comment|/**< PMU is present. */
name|bool
name|eci
decl_stmt|;
comment|/**< ECI (enhanced coexistence inteface) is present. */
name|bool
name|seci
decl_stmt|;
comment|/**< SECI (serial ECI) is present */
name|bool
name|sprom
decl_stmt|;
comment|/**< SPROM is present */
name|bool
name|gsio
decl_stmt|;
comment|/**< GSIO (SPI/I2C) present */
name|bool
name|aob
decl_stmt|;
comment|/**< AOB (always on bus) present. 					     If set, PMU and GCI registers are 					     not accessible via ChipCommon, 					     and are instead accessible via 					     dedicated cores on the bhnd bus */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPC_H_ */
end_comment

end_unit

