begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_CORES_CHIPC_CHIPCVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_CORES_CHIPC_CHIPCVAR_H_
end_define

begin_include
include|#
directive|include
file|<dev/bhnd/nvram/bhnd_spromvar.h>
end_include

begin_include
include|#
directive|include
file|"chipc.h"
end_include

begin_expr_stmt
name|DECLARE_CLASS
argument_list|(
name|bhnd_chipc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_chipc_devclass
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|chipc_region
struct_decl|;
end_struct_decl

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
comment|/**< Flash type */
name|uint8_t
name|otp_size
decl_stmt|;
comment|/**< OTP (row?) size, 0 if not present */
name|uint8_t
name|cfi_width
decl_stmt|;
comment|/**< CFI bus width, 0 if unknown or CFI not present */
name|uint8_t
name|pll_type
decl_stmt|;
comment|/**< PLL type */
name|bool
name|power_control
decl_stmt|;
comment|/**< Power control available */
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

begin_comment
comment|/*   * ChipCommon device quirks / features  */
end_comment

begin_enum
enum|enum
block|{
comment|/** No quirks */
name|CHIPC_QUIRK_NONE
init|=
literal|0
block|,
comment|/** 	 * ChipCommon-controlled SPROM/OTP is supported, along with the 	 * CHIPC_CAP_SPROM capability flag. 	 */
name|CHIPC_QUIRK_SUPPORTS_SPROM
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/** 	 * The BCM4706 NAND flash interface is supported, along with the 	 * CHIPC_CAP_4706_NFLASH capability flag. 	 */
name|CHIPC_QUIRK_4706_NFLASH
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/** 	 * The SPROM is attached via muxed pins. The pins must be switched 	 * to allow reading/writing. 	 */
name|CHIPC_QUIRK_MUX_SPROM
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/** 	 * Access to the SPROM uses pins shared with the 802.11a external PA. 	 *  	 * On modules using these 4331 packages, the CCTRL4331_EXTPA_EN flag 	 * must be cleared to allow SPROM access. 	 */
name|CHIPC_QUIRK_4331_EXTPA_MUX_SPROM
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
operator||
name|CHIPC_QUIRK_MUX_SPROM
block|,
comment|/** 	 * Access to the SPROM uses pins shared with the 802.11a external PA. 	 *  	 * On modules using these 4331 chip packages, the external PA is 	 * attached via GPIO 2, 5, and sprom_dout pins. 	 *  	 * When enabling and disabling EXTPA to allow SPROM access, the 	 * CCTRL4331_EXTPA_ON_GPIO2_5 flag must also be set or cleared, 	 * respectively. 	 */
name|CHIPC_QUIRK_4331_GPIO2_5_MUX_SPROM
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
operator||
name|CHIPC_QUIRK_4331_EXTPA_MUX_SPROM
block|,
comment|/** 	 * Access to the SPROM uses pins shared with two 802.11a external PAs. 	 *  	 * When enabling and disabling EXTPA, the CCTRL4331_EXTPA_EN2 must also 	 * be cleared to allow SPROM access. 	 */
name|CHIPC_QUIRK_4331_EXTPA2_MUX_SPROM
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
operator||
name|CHIPC_QUIRK_4331_EXTPA_MUX_SPROM
block|,
comment|/** 	 * SPROM pins are muxed with the FEM control lines on this 4360-family 	 * device. The muxed pins must be switched to allow reading/writing 	 * the SPROM. 	 */
name|CHIPC_QUIRK_4360_FEM_MUX_SPROM
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
operator||
name|CHIPC_QUIRK_MUX_SPROM
block|,
comment|/** Supports CHIPC_CAPABILITIES_EXT register */
name|CHIPC_QUIRK_SUPPORTS_CAP_EXT
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/** OTP size is defined via CHIPC_OTPLAYOUT register in later 	 *  ChipCommon revisions using the 'IPX' OTP controller. */
name|CHIPC_QUIRK_IPX_OTPLAYOUT_SIZE
init|=
operator|(
literal|1
operator|<<
literal|7
operator|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * chipc child device info.  */
end_comment

begin_struct
struct|struct
name|chipc_devinfo
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
comment|/**< child resources */
block|}
struct|;
end_struct

begin_comment
comment|/**  * chipc driver instance state.  */
end_comment

begin_struct
struct|struct
name|chipc_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|bhnd_resource
modifier|*
name|core
decl_stmt|;
comment|/**< core registers. */
name|struct
name|chipc_region
modifier|*
name|core_region
decl_stmt|;
comment|/**< region containing core registers */
name|struct
name|bhnd_chipid
name|ccid
decl_stmt|;
comment|/**< chip identification */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< chipc quirk flags */
name|struct
name|chipc_caps
name|caps
decl_stmt|;
comment|/**< chipc capabilities */
name|bhnd_nvram_src_t
name|nvram_src
decl_stmt|;
comment|/**< identified NVRAM source */
name|struct
name|mtx
name|mtx
decl_stmt|;
comment|/**< state mutex. */
name|struct
name|bhnd_sprom
name|sprom
decl_stmt|;
comment|/**< OTP/SPROM shadow, if any */
name|size_t
name|sprom_refcnt
decl_stmt|;
comment|/**< SPROM hardware refcount */
name|struct
name|rman
name|mem_rman
decl_stmt|;
comment|/**< port memory manager */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|chipc_region
argument_list|)
name|mem_regions
expr_stmt|;
comment|/**< memory allocation records */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHIPC_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, device_get_nameunit((sc)->dev), \ 	    "BHND chipc driver lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|CHIPC_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CHIPC_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|CHIPC_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|CHIPC_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_CORES_CHIPC_CHIPCVAR_H_ */
end_comment

end_unit

