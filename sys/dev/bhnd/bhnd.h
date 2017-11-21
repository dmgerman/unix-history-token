begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 2017 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Landon Fuller  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|"bhnd_ids.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_types.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_erom_types.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_debug.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_bus_if.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_match.h"
end_include

begin_include
include|#
directive|include
file|"nvram/bhnd_nvram.h"
end_include

begin_struct_decl
struct_decl|struct
name|bhnd_core_pmu_info
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_hostb_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|bhnd_nvram_devclass
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BHND_CHIPID_MAX_NAMELEN
value|32
end_define

begin_comment
comment|/**< maximum buffer required for a 					     bhnd_format_chip_id() */
end_comment

begin_comment
comment|/**  * bhnd child instance variables  */
end_comment

begin_enum
enum|enum
name|bhnd_device_vars
block|{
name|BHND_IVAR_VENDOR
block|,
comment|/**< Designer's JEP-106 manufacturer ID. */
name|BHND_IVAR_DEVICE
block|,
comment|/**< Part number */
name|BHND_IVAR_HWREV
block|,
comment|/**< Core revision */
name|BHND_IVAR_DEVICE_CLASS
block|,
comment|/**< Core class (@sa bhnd_devclass_t) */
name|BHND_IVAR_VENDOR_NAME
block|,
comment|/**< Core vendor name */
name|BHND_IVAR_DEVICE_NAME
block|,
comment|/**< Core name */
name|BHND_IVAR_CORE_INDEX
block|,
comment|/**< Bus-assigned core number */
name|BHND_IVAR_CORE_UNIT
block|,
comment|/**< Bus-assigned core unit number, 				     assigned sequentially (starting at 0) for 				     each vendor/device pair. */
name|BHND_IVAR_PMU_INFO
block|,
comment|/**< Internal bus-managed PMU state */
block|}
enum|;
end_enum

begin_comment
comment|/**  * bhnd device probe priority bands.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_PROBE_ROOT
init|=
literal|0
block|,
comment|/**< Nexus or host bridge */
name|BHND_PROBE_BUS
init|=
literal|1000
block|,
comment|/**< Buses and bridges */
name|BHND_PROBE_CPU
init|=
literal|2000
block|,
comment|/**< CPU devices */
name|BHND_PROBE_INTERRUPT
init|=
literal|3000
block|,
comment|/**< Interrupt controllers. */
name|BHND_PROBE_TIMER
init|=
literal|4000
block|,
comment|/**< Timers and clocks. */
name|BHND_PROBE_RESOURCE
init|=
literal|5000
block|,
comment|/**< Resource discovery (including NVRAM/SPROM) */
name|BHND_PROBE_DEFAULT
init|=
literal|6000
block|,
comment|/**< Default device priority */
block|}
enum|;
end_enum

begin_comment
comment|/**  * Constants defining fine grained ordering within a BHND_PROBE_* priority band.  *   * Example:  * @code  * BHND_PROBE_BUS + BHND_PROBE_ORDER_FIRST  * @endcode  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_PROBE_ORDER_FIRST
init|=
literal|0
block|,
name|BHND_PROBE_ORDER_EARLY
init|=
literal|25
block|,
name|BHND_PROBE_ORDER_MIDDLE
init|=
literal|50
block|,
name|BHND_PROBE_ORDER_LATE
init|=
literal|75
block|,
name|BHND_PROBE_ORDER_LAST
init|=
literal|100
block|}
enum|;
end_enum

begin_comment
comment|/**  * Per-core IOCTL flags common to all bhnd(4) cores.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_IOCTL_BIST
init|=
literal|0x8000
block|,
comment|/**< Initiate a built-in self-test (BIST). Must be cleared 						     after BIST results are read via BHND_IOST_BIST_* */
name|BHND_IOCTL_PME
init|=
literal|0x4000
block|,
comment|/**< Enable posting of power management events by the core. */
name|BHND_IOCTL_CFLAGS
init|=
literal|0x3FFC
block|,
comment|/**< Reserved for core-specific ioctl flags. */
name|BHND_IOCTL_CLK_FORCE
init|=
literal|0x0002
block|,
comment|/**< Force disable of clock gating, resulting in all clocks 						     being distributed within the core. Should be set when 						     asserting/deasserting reset to ensure the reset signal 						     fully propagates to the entire core. */
name|BHND_IOCTL_CLK_EN
init|=
literal|0x0001
block|,
comment|/**< If cleared, the core clock will be disabled. Should be 						     set during normal operation, and cleared when the core is 						     held in reset. */
block|}
enum|;
end_enum

begin_comment
comment|/**  * Per-core IOST flags common to all bhnd(4) cores.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_IOST_BIST_DONE
init|=
literal|0x8000
block|,
comment|/**< Set upon BIST completion (see BHND_IOCTL_BIST), and cleared 						     if 0 is written to BHND_IOCTL_BIST. */
name|BHND_IOST_BIST_FAIL
init|=
literal|0x4000
block|,
comment|/**< Set upon detection of a BIST error; the value is unspecified 						     if BIST has not completed and BHND_IOST_BIST_DONE is not set. */
name|BHND_IOST_CLK
init|=
literal|0x2000
block|,
comment|/**< Set if the core has requested that gated clocks be enabled, or 						     cleared otherwise. The value is undefined if a core does not 						     support clock gating. */
name|BHND_IOST_DMA64
init|=
literal|0x1000
block|,
comment|/**< Set if this core supports 64-bit DMA */
name|BHND_IOST_CFLAGS
init|=
literal|0x0FFC
block|,
comment|/**< Reserved for core-specific status flags. */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Simplified accessors for bhnd device ivars  */
end_comment

begin_define
define|#
directive|define
name|BHND_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(bhnd, var, BHND, ivar, type)
end_define

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|vendor
argument_list|,
name|VENDOR
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|device
argument_list|,
name|DEVICE
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|hwrev
argument_list|,
name|HWREV
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|class
argument_list|,
name|DEVICE_CLASS
argument_list|,
name|bhnd_devclass_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|vendor_name
argument_list|,
name|VENDOR_NAME
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|device_name
argument_list|,
name|DEVICE_NAME
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|core_index
argument_list|,
name|CORE_INDEX
argument_list|,
name|u_int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|core_unit
argument_list|,
name|CORE_UNIT
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|BHND_ACCESSOR
argument_list|(
name|pmu_info
argument_list|,
name|PMU_INFO
argument_list|,
expr|struct
name|bhnd_core_pmu_info
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|BHND_ACCESSOR
end_undef

begin_comment
comment|/**  * A bhnd(4) board descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_board_info
block|{
name|uint16_t
name|board_vendor
decl_stmt|;
comment|/**< PCI-SIG vendor ID (even on non-PCI 					  *  devices). 					  * 					  *  On PCI devices, this will generally 					  *  be the subsystem vendor ID, but the 					  *  value may be overridden in device 					  *  NVRAM. 					  */
name|uint16_t
name|board_type
decl_stmt|;
comment|/**< Board type (See BHND_BOARD_*) 					  * 					  *  On PCI devices, this will generally 					  *  be the subsystem device ID, but the 					  *  value may be overridden in device 					  *  NVRAM. 					  */
name|uint16_t
name|board_rev
decl_stmt|;
comment|/**< Board revision. */
name|uint8_t
name|board_srom_rev
decl_stmt|;
comment|/**< Board SROM format revision */
name|uint32_t
name|board_flags
decl_stmt|;
comment|/**< Board flags (see BHND_BFL_*) */
name|uint32_t
name|board_flags2
decl_stmt|;
comment|/**< Board flags 2 (see BHND_BFL2_*) */
name|uint32_t
name|board_flags3
decl_stmt|;
comment|/**< Board flags 3 (see BHND_BFL3_*) */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Chip Identification  *   * This is read from the ChipCommon ID register; on earlier bhnd(4) devices  * where ChipCommon is unavailable, known values must be supplied.  */
end_comment

begin_struct
struct|struct
name|bhnd_chipid
block|{
name|uint16_t
name|chip_id
decl_stmt|;
comment|/**< chip id (BHND_CHIPID_*) */
name|uint8_t
name|chip_rev
decl_stmt|;
comment|/**< chip revision */
name|uint8_t
name|chip_pkg
decl_stmt|;
comment|/**< chip package (BHND_PKGID_*) */
name|uint8_t
name|chip_type
decl_stmt|;
comment|/**< chip type (BHND_CHIPTYPE_*) */
name|bhnd_addr_t
name|enum_addr
decl_stmt|;
comment|/**< chip_type-specific enumeration 					  *  address; either the siba(4) base 					  *  core register block, or the bcma(4) 					  *  EROM core address. */
name|uint8_t
name|ncores
decl_stmt|;
comment|/**< number of cores, if known. 0 if 					  *  not available. */
block|}
struct|;
end_struct

begin_comment
comment|/**  * A bhnd(4) core descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_core_info
block|{
name|uint16_t
name|vendor
decl_stmt|;
comment|/**< JEP-106 vendor (BHND_MFGID_*) */
name|uint16_t
name|device
decl_stmt|;
comment|/**< device */
name|uint16_t
name|hwrev
decl_stmt|;
comment|/**< hardware revision */
name|u_int
name|core_idx
decl_stmt|;
comment|/**< bus-assigned core index */
name|int
name|unit
decl_stmt|;
comment|/**< bus-assigned core unit */
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhnd(4) DMA address widths.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_DMA_ADDR_30BIT
init|=
literal|30
block|,
comment|/**< 30-bit DMA */
name|BHND_DMA_ADDR_32BIT
init|=
literal|32
block|,
comment|/**< 32-bit DMA */
name|BHND_DMA_ADDR_64BIT
init|=
literal|64
block|,
comment|/**< 64-bit DMA */
block|}
name|bhnd_dma_addrwidth
typedef|;
end_typedef

begin_comment
comment|/**  * Convert an address width (in bits) to its corresponding mask.  */
end_comment

begin_define
define|#
directive|define
name|BHND_DMA_ADDR_BITMASK
parameter_list|(
name|_width
parameter_list|)
define|\
value|((_width>= 64) ? ~0ULL :	\ 	 (_width == 0) ? 0x0 :		\ 	 ((1ULL<< (_width)) - 1))
end_define

begin_comment
unit|\
comment|/**  * bhnd(4) DMA address translation descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_dma_translation
block|{
comment|/** 	 * Host-to-device physical address translation. 	 *  	 * This may be added to the host physical address to produce a device 	 * DMA address. 	 */
name|bhnd_addr_t
name|base_addr
decl_stmt|;
comment|/** 	 * Device-addressable address mask. 	 *  	 * This defines the device's DMA address range, excluding any bits 	 * reserved for mapping the address to the base_addr. 	 */
name|bhnd_addr_t
name|addr_mask
decl_stmt|;
comment|/** 	 * Device-addressable extended address mask. 	 * 	 * If a per-core bhnd(4) DMA engine supports the 'addrext' control 	 * field, it can be used to provide address bits excluded by addr_mask. 	 * 	 * Support for DMA extended address changes â including coordination 	 * with the core providing DMA translation â is handled transparently by 	 * the DMA engine. For example, on PCI(e) Wi-Fi chipsets, the Wi-Fi 	 * core DMA engine will (in effect) update the PCI core's DMA 	 * sbtopcitranslation base address to map the full address prior to 	 * performing a DMA transaction. 	 */
name|bhnd_addr_t
name|addrext_mask
decl_stmt|;
comment|/** 	 * Translation flags (see bhnd_dma_translation_flags) 	 */
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_DMA_TRANSLATION_TABLE_END
value|{ 0, 0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|BHND_DMA_IS_TRANSLATION_TABLE_END
parameter_list|(
name|_dt
parameter_list|)
define|\
value|((_dt)->base_addr == 0&& (_dt)->addr_mask == 0&&	\ 	 (_dt)->addrext_mask == 0&& (_dt)->flags == 0)
end_define

begin_comment
comment|/**  * bhnd(4) DMA address translation flags.  */
end_comment

begin_enum
enum|enum
name|bhnd_dma_translation_flags
block|{
comment|/** 	 * The translation remaps the device's physical address space. 	 *  	 * This is used in conjunction with BHND_DMA_TRANSLATION_BYTESWAPPED to 	 * define a DMA translation that provides byteswapped access to 	 * physical memory on big-endian MIPS SoCs. 	 */
name|BHND_DMA_TRANSLATION_PHYSMAP
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/** 	 * Provides a byte-swapped mapping; write requests will be byte-swapped 	 * before being written to memory, and read requests will be 	 * byte-swapped before being returned. 	 * 	 * This is primarily used to perform efficient byte swapping of DMA 	 * data on embedded MIPS SoCs executing in big-endian mode. 	 */
name|BHND_DMA_TRANSLATION_BYTESWAPPED
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,	 }
enum|;
end_enum

begin_comment
comment|/** * A bhnd(4) bus resource. *  * This provides an abstract interface to per-core resources that may require * bus-level remapping of address windows prior to access. */
end_comment

begin_struct
struct|struct
name|bhnd_resource
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
comment|/**< the system resource. */
name|bool
name|direct
decl_stmt|;
comment|/**< false if the resource requires 					 *   bus window remapping before it 					 *   is MMIO accessible. */
block|}
struct|;
end_struct

begin_comment
comment|/** Wrap the active resource @p _r in a bhnd_resource structure */
end_comment

begin_define
define|#
directive|define
name|BHND_DIRECT_RESOURCE
parameter_list|(
name|_r
parameter_list|)
value|((struct bhnd_resource) {	\ 	.res = (_r),							\ 	.direct = true,							\ })
end_define

begin_comment
comment|/**  * Device quirk table descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_device_quirk
block|{
name|struct
name|bhnd_device_match
name|desc
decl_stmt|;
comment|/**< device match descriptor */
name|uint32_t
name|quirks
decl_stmt|;
comment|/**< quirk flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_CORE_QUIRK
parameter_list|(
name|_rev
parameter_list|,
name|_flags
parameter_list|)
define|\
value|{{ BHND_MATCH_CORE_REV(_rev) }, (_flags) }
end_define

begin_define
define|#
directive|define
name|BHND_CHIP_QUIRK
parameter_list|(
name|_chip
parameter_list|,
name|_rev
parameter_list|,
name|_flags
parameter_list|)
define|\
value|{{ BHND_MATCH_CHIP_IR(BCM ## _chip, _rev) }, (_flags) }
end_define

begin_define
define|#
directive|define
name|BHND_PKG_QUIRK
parameter_list|(
name|_chip
parameter_list|,
name|_pkg
parameter_list|,
name|_flags
parameter_list|)
define|\
value|{{ BHND_MATCH_CHIP_IP(BCM ## _chip, BCM ## _chip ## _pkg) }, (_flags) }
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_QUIRK
parameter_list|(
name|_board
parameter_list|,
name|_flags
parameter_list|)
define|\
value|{{ BHND_MATCH_BOARD_TYPE(_board) },	\ 	    (_flags) }
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_QUIRK_END
value|{ { BHND_MATCH_ANY }, 0 }
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_QUIRK_IS_END
parameter_list|(
name|_q
parameter_list|)
define|\
value|(((_q)->desc.m.match_flags == 0)&& (_q)->quirks == 0)
end_define

begin_enum
enum|enum
block|{
name|BHND_DF_ANY
init|=
literal|0
block|,
name|BHND_DF_HOSTB
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**< core is serving as the bus' host 					  *  bridge. implies BHND_DF_ADAPTER */
name|BHND_DF_SOC
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/**< core is attached to a native 					     bus (BHND_ATTACH_NATIVE) */
name|BHND_DF_ADAPTER
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/**< core is attached to a bridged 					  *  adapter (BHND_ATTACH_ADAPTER) */
block|}
enum|;
end_enum

begin_comment
comment|/** Device probe table descriptor */
end_comment

begin_struct
struct|struct
name|bhnd_device
block|{
specifier|const
name|struct
name|bhnd_device_match
name|core
decl_stmt|;
comment|/**< core match descriptor */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/**< device description, or NULL. */
specifier|const
name|struct
name|bhnd_device_quirk
modifier|*
name|quirks_table
decl_stmt|;
comment|/**< quirks table for this device, or NULL */
name|uint32_t
name|device_flags
decl_stmt|;
comment|/**< required BHND_DF_* flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_BHND_DEVICE
parameter_list|(
name|_vendor
parameter_list|,
name|_device
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|,		\
name|_flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|{ { BHND_MATCH_CORE(BHND_MFGID_ ## _vendor,		\ 	    BHND_COREID_ ## _device) }, _desc, _quirks,		\ 	    _flags }
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE
parameter_list|(
name|_vendor
parameter_list|,
name|_device
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVICE(_vendor, _device, _desc, _quirks,		\ 	    ## __VA_ARGS__, 0)
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_END
value|{ { BHND_MATCH_ANY }, NULL, NULL, 0 }
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_IS_END
parameter_list|(
name|_d
parameter_list|)
define|\
value|(BHND_MATCH_IS_ANY(&(_d)->core)&& (_d)->desc == NULL)
end_define

begin_comment
comment|/**  * bhnd device sort order.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BHND_DEVICE_ORDER_ATTACH
block|,
comment|/**< sort by bhnd(4) device attach order; 					     child devices should be probed/attached 					     in this order */
name|BHND_DEVICE_ORDER_DETACH
block|,
comment|/**< sort by bhnd(4) device detach order; 					     child devices should be detached, suspended, 					     and shutdown in this order */
block|}
name|bhnd_device_order
typedef|;
end_typedef

begin_comment
comment|/**  * A registry of bhnd service providers.  */
end_comment

begin_struct
struct|struct
name|bhnd_service_registry
block|{
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|bhnd_service_entry
argument_list|)
name|entries
expr_stmt|;
comment|/**< registered services */
name|struct
name|mtx
name|lock
decl_stmt|;
comment|/**< state lock */
block|}
struct|;
end_struct

begin_comment
comment|/**  * bhnd service provider flags.  */
end_comment

begin_enum
enum|enum
block|{
name|BHND_SPF_INHERITED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/**< service provider reference was inherited from 						     a parent bus, and should be deregistered when the 						     last active reference is released */
block|}
enum|;
end_enum

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_vendor_name
parameter_list|(
name|uint16_t
name|vendor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_port_type_name
parameter_list|(
name|bhnd_port_type
name|port_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_nvram_src_name
parameter_list|(
name|bhnd_nvram_src
name|nvram_src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_find_core_name
parameter_list|(
name|uint16_t
name|vendor
parameter_list|,
name|uint16_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_devclass_t
name|bhnd_find_core_class
parameter_list|(
name|uint16_t
name|vendor
parameter_list|,
name|uint16_t
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bhnd_core_name
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|ci
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bhnd_devclass_t
name|bhnd_core_class
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|ci
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_format_chip_id
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint16_t
name|chip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_bus_match_child
parameter_list|(
name|device_t
name|bus
parameter_list|,
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_bus_find_child
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|,
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_get_children
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
modifier|*
modifier|*
name|devlistp
parameter_list|,
name|int
modifier|*
name|devcountp
parameter_list|,
name|bhnd_device_order
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_bus_free_children
parameter_list|(
name|device_t
modifier|*
name|devlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_probe_children
parameter_list|(
name|device_t
name|bus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_sort_devices
parameter_list|(
name|device_t
modifier|*
name|devlist
parameter_list|,
name|size_t
name|devcount
parameter_list|,
name|bhnd_device_order
name|order
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_find_bridge_root
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|devclass_t
name|bus_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|bhnd_match_core
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|cores
parameter_list|,
name|u_int
name|num_cores
parameter_list|,
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|bhnd_find_core
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|cores
parameter_list|,
name|u_int
name|num_cores
parameter_list|,
name|bhnd_devclass_t
name|class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_core_match
name|bhnd_core_get_match_desc
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_cores_equal
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|lhs
parameter_list|,
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_core_matches
parameter_list|(
specifier|const
name|struct
name|bhnd_core_info
modifier|*
name|core
parameter_list|,
specifier|const
name|struct
name|bhnd_core_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_chip_matches
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|chipid
parameter_list|,
specifier|const
name|struct
name|bhnd_chip_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_board_matches
parameter_list|(
specifier|const
name|struct
name|bhnd_board_info
modifier|*
name|info
parameter_list|,
specifier|const
name|struct
name|bhnd_board_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_hwrev_matches
parameter_list|(
name|uint16_t
name|hwrev
parameter_list|,
specifier|const
name|struct
name|bhnd_hwrev_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_device_matches
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhnd_device_match
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_device
modifier|*
name|bhnd_device_lookup
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhnd_device
modifier|*
name|table
parameter_list|,
name|size_t
name|entry_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bhnd_device_quirks
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhnd_device
modifier|*
name|table
parameter_list|,
name|size_t
name|entry_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_core_info
name|bhnd_get_core_info
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_alloc_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource_spec
modifier|*
name|rs
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_release_resources
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|resource_spec
modifier|*
name|rs
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_chipid
name|bhnd_parse_chipid
parameter_list|(
name|uint32_t
name|idreg
parameter_list|,
name|bhnd_addr_t
name|enum_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_chipid_fixed_ncores
parameter_list|(
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|cid
parameter_list|,
name|uint16_t
name|chipc_hwrev
parameter_list|,
name|uint8_t
modifier|*
name|ncores
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_read_chipid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|resource_spec
modifier|*
name|rs
parameter_list|,
name|bus_size_t
name|chipc_offset
parameter_list|,
name|struct
name|bhnd_chipid
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_set_custom_core_desc
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_set_default_core_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_set_default_bus_desc
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|chip_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_str
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|size_t
modifier|*
name|rlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_uint
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|value
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_uint8
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint8_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_uint16
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint16_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_uint32
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint32_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_int
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|value
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_int8
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int8_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_int16
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int16_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_int32
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int32_t
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_nvram_getvar_array
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|count
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_service_registry_init
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_service_registry_fini
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_service_registry_add
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_service_registry_remove
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_service_registry_retain
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_service_registry_release
parameter_list|(
name|struct
name|bhnd_service_registry
modifier|*
name|bsr
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_register_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_deregister_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_bus_generic_retain_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_bus_generic_release_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_sr_register_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_sr_deregister_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|bhnd_bus_generic_sr_retain_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bhnd_bus_generic_sr_release_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_bus_generic_is_hw_disabled
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|bhnd_bus_generic_is_region_valid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_get_nvram_var
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|size
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|bhnd_bus_generic_get_chipid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_get_dma_translation
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|u_int
name|width
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|bus_dma_tag_t
modifier|*
name|dmat
parameter_list|,
name|struct
name|bhnd_dma_translation
modifier|*
name|translation
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_read_board_info
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|bhnd_board_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bhnd_resource
modifier|*
name|bhnd_bus_generic_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_activate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bhnd_bus_generic_deactivate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uintptr_t
name|bhnd_bus_generic_get_intr_domain
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|bool
name|self
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return the bhnd(4) bus driver's device enumeration parser class  *  * @param driver A bhnd bus driver instance.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bhnd_erom_class_t
modifier|*
name|bhnd_driver_get_erom_class
parameter_list|(
name|driver_t
modifier|*
name|driver
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_EROM_CLASS
argument_list|(
name|driver
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the active host bridge core for the bhnd bus, if any, or NULL if  * not found.  *  * @param dev A bhnd bus device.  */
end_comment

begin_function
specifier|static
specifier|inline
name|device_t
name|bhnd_bus_find_hostb_device
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_FIND_HOSTB_DEVICE
argument_list|(
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Register a provider for a given @p service.  *  * @param dev		The device to register as a service provider  *			with its parent bus.  * @param service	The service for which @p dev will be registered.  *  * @retval 0		success  * @retval EEXIST	if an entry for @p service already exists.  * @retval non-zero	if registering @p dev otherwise fails, a regular  *			unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_register_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_REGISTER_PROVIDER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|dev
argument_list|,
name|service
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Attempt to remove a service provider registration for @p dev.  *  * @param dev		The device to be deregistered as a service provider.  * @param service	The service for which @p dev will be deregistered, or  *			BHND_SERVICE_INVALID to remove all service registrations  *			for @p dev.  *  * @retval 0		success  * @retval EBUSY	if active references to @p dev exist; @see  *			bhnd_retain_provider() and bhnd_release_provider().  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_deregister_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_DEREGISTER_PROVIDER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|dev
argument_list|,
name|service
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Retain and return a reference to the registered @p service provider, if any.  *  * @param dev		The requesting device.  * @param service	The service for which a provider should be returned.  *  * On success, the caller assumes ownership the returned provider, and  * is responsible for releasing this reference via  * BHND_BUS_RELEASE_PROVIDER().  *  * @retval device_t	success  * @retval NULL		if no provider is registered for @p service.   */
end_comment

begin_function
specifier|static
specifier|inline
name|device_t
name|bhnd_retain_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_RETAIN_PROVIDER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|service
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Release a reference to a provider device previously returned by  * bhnd_retain_provider().  *  * @param dev The requesting device.  * @param provider The provider to be released.  * @param service The service for which @p provider was previously retained.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_release_provider
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|provider
parameter_list|,
name|bhnd_service_t
name|service
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_RELEASE_PROVIDER
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|provider
argument_list|,
name|service
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return true if the hardware components required by @p dev are known to be  * unpopulated or otherwise unusable.  *  * In some cases, enumerated devices may have pins that are left floating, or  * the hardware may otherwise be non-functional; this method allows a parent  * device to explicitly specify if a successfully enumerated @p dev should  * be disabled.  *  * @param dev A bhnd bus child device.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bhnd_is_hw_disabled
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_IS_HW_DISABLED
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the BHND chip identification info for the bhnd bus.  *  * @param dev A bhnd bus child device.  */
end_comment

begin_function
specifier|static
specifier|inline
specifier|const
name|struct
name|bhnd_chipid
modifier|*
name|bhnd_get_chipid
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_CHIPID
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/**  * Read the current value of a bhnd(4) device's per-core I/O control register.  *  * @param dev The bhnd bus child device to be queried.  * @param[out] ioctl On success, the I/O control register value.  *  * @retval 0 success  * @retval EINVAL If @p child is not a direct child of @p dev.  * @retval ENODEV If agent/config space for @p child is unavailable.  * @retval non-zero If reading the IOCTL register otherwise fails, a regular  * unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_read_ioctl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
modifier|*
name|ioctl
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_READ_IOCTL
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|ioctl
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Write @p value and @p mask to a bhnd(4) device's per-core I/O control  * register.  *   * @param dev The bhnd bus child device for which the IOCTL register will be  * written.  * @param value The value to be written (see BHND_IOCTL_*).  * @param mask Only the bits defined by @p mask will be updated from @p value.  *  * @retval 0 success  * @retval EINVAL If @p child is not a direct child of @p dev.  * @retval ENODEV If agent/config space for @p child is unavailable.  * @retval non-zero If writing the IOCTL register otherwise fails, a regular  * unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_write_ioctl
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|value
parameter_list|,
name|uint16_t
name|mask
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_WRITE_IOCTL
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|value
argument_list|,
name|mask
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Read the current value of a bhnd(4) device's per-core I/O status register.  *  * @param dev The bhnd bus child device to be queried.  * @param[out] iost On success, the I/O status register value.  *  * @retval 0 success  * @retval EINVAL If @p child is not a direct child of @p dev.  * @retval ENODEV If agent/config space for @p child is unavailable.  * @retval non-zero If reading the IOST register otherwise fails, a regular  * unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_read_iost
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
modifier|*
name|iost
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_READ_IOST
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|iost
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return true if the given bhnd device's hardware is currently held  * in a RESET state or otherwise not clocked (BHND_IOCTL_CLK_EN).  *   * @param dev The device to query.  *  * @retval true If @p dev is held in RESET or not clocked (BHND_IOCTL_CLK_EN),  * or an error occured determining @p dev's hardware state.  * @retval false If @p dev is clocked and is not held in RESET.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bhnd_is_hw_suspended
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_IS_HW_SUSPENDED
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Place the bhnd(4) device's hardware into a reset state, and then bring the  * hardware out of reset with BHND_IOCTL_CLK_EN and @p ioctl flags set.  *   * Any clock or resource PMU requests previously made by @p dev will be  * invalidated.  *  * @param dev The device to be reset.  * @param ioctl Device-specific core ioctl flags to be supplied on reset  * (see BHND_IOCTL_*).  *  * @retval 0 success  * @retval non-zero error  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_reset_hw
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|ioctl
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_RESET_HW
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|ioctl
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Suspend @p child's hardware in a low-power reset state.  *  * Any clock or resource PMU requests previously made by @p dev will be  * invalidated.  *  * The hardware may be brought out of reset via bhnd_reset_hw().  *  * @param dev The device to be suspended.  *  * @retval 0 success  * @retval non-zero error  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_suspend_hw
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_SUSPEND_HW
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * If supported by the chipset, return the clock source for the given clock.  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock for which a clock source will be returned.  *  * @retval	bhnd_clksrc		The clock source for @p clock.  * @retval	BHND_CLKSRC_UNKNOWN	If @p clock is unsupported, or its  *					clock source is not known to the bus.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bhnd_clksrc
name|bhnd_pwrctl_get_clksrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_PWRCTL_GET_CLKSRC
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * If supported by the chipset, gate @p clock  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock to be disabled.  *  * @retval 0 success  * @retval ENODEV If bus-level clock source management is not supported.  * @retval ENXIO If bus-level management of @p clock is not supported.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_gate_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_PWRCTL_GATE_CLOCK
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * If supported by the chipset, ungate @p clock  *  * This function is only supported on early PWRCTL-equipped chipsets  * that expose clock management via their host bridge interface. Currently,  * this includes PCI (not PCIe) devices, with ChipCommon core revisions 0-9.  *  * @param dev A bhnd bus child device.  * @param clock The clock to be enabled.  *  * @retval 0 success  * @retval ENODEV If bus-level clock source management is not supported.  * @retval ENXIO If bus-level management of @p clock is not supported.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_pwrctl_ungate_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_PWRCTL_UNGATE_CLOCK
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the BHND attachment type of the parent bhnd bus.  *  * @param dev A bhnd bus child device.  *  * @retval BHND_ATTACH_ADAPTER if the bus is resident on a bridged adapter,  * such as a WiFi chipset.  * @retval BHND_ATTACH_NATIVE if the bus provides hardware services (clock,  * CPU, etc) to a directly attached native host.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bhnd_attach_type
name|bhnd_get_attach_type
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_ATTACH_TYPE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Find the best available DMA address translation capable of mapping a  * physical host address to a BHND DMA device address of @p width with  * @p flags.  *  * @param dev A bhnd bus child device.  * @param width The address width within which the translation window must  * reside (see BHND_DMA_ADDR_*).  * @param flags Required translation flags (see BHND_DMA_TRANSLATION_*).  * @param[out] dmat On success, will be populated with a DMA tag specifying the  * @p translation DMA address restrictions. This argment may be NULL if the DMA  * tag is not desired.  * the set of valid host DMA addresses reachable via @p translation.  * @param[out] translation On success, will be populated with a DMA address  * translation descriptor for @p child. This argment may be NULL if the  * descriptor is not desired.  *  * @retval 0 success  * @retval ENODEV If DMA is not supported.  * @retval ENOENT If no DMA translation matching @p width and @p flags is  * available.  * @retval non-zero If determining the DMA address translation for @p child  * otherwise fails, a regular unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_get_dma_translation
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|width
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|bus_dma_tag_t
modifier|*
name|dmat
parameter_list|,
name|struct
name|bhnd_dma_translation
modifier|*
name|translation
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_DMA_TRANSLATION
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|width
argument_list|,
name|flags
argument_list|,
name|dmat
argument_list|,
name|translation
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Attempt to read the BHND board identification from the bhnd bus.  *  * This relies on NVRAM access, and will fail if a valid NVRAM device cannot  * be found, or is not yet attached.  *  * @param dev The parent of @p child.  * @param child The bhnd device requesting board info.  * @param[out] info On success, will be populated with the bhnd(4) device's  * board information.  *  * @retval 0 success  * @retval ENODEV	No valid NVRAM source could be found.  * @retval non-zero	If reading @p name otherwise fails, a regular unix  *			error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_read_board_info
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|struct
name|bhnd_board_info
modifier|*
name|info
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_READ_BOARD_INFO
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|info
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the number of interrupt lines assigned to @p dev.  *   * @param dev A bhnd bus child device.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|bhnd_get_intr_count
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_INTR_COUNT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Get the backplane interrupt vector of the @p intr line attached to @p dev.  *   * @param dev A bhnd bus child device.  * @param intr The index of the interrupt line being queried.  * @param[out] ivec On success, the assigned hardware interrupt vector will be  * written to this pointer.  *  * On bcma(4) devices, this returns the OOB bus line assigned to the  * interrupt.  *  * On siba(4) devices, this returns the target OCP slave flag number assigned  * to the interrupt.  *  * @retval 0		success  * @retval ENXIO	If @p intr exceeds the number of interrupt lines  *			assigned to @p child.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_get_intr_ivec
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|intr
parameter_list|,
name|u_int
modifier|*
name|ivec
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_INTR_IVEC
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|intr
argument_list|,
name|ivec
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Map the given @p intr to an IRQ number; until unmapped, this IRQ may be used  * to allocate a resource of type SYS_RES_IRQ.  *   * On success, the caller assumes ownership of the interrupt mapping, and  * is responsible for releasing the mapping via bhnd_unmap_intr().  *   * @param dev The requesting device.  * @param intr The interrupt being mapped.  * @param[out] irq On success, the bus interrupt value mapped for @p intr.  *  * @retval 0		If an interrupt was assigned.  * @retval non-zero	If mapping an interrupt otherwise fails, a regular  *			unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_map_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|intr
parameter_list|,
name|rman_res_t
modifier|*
name|irq
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_MAP_INTR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|intr
argument_list|,
name|irq
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Unmap an bus interrupt previously mapped via bhnd_map_intr().  *   * @param dev The requesting device.  * @param intr The interrupt number being unmapped. This is equivalent to the  * bus resource ID for the interrupt.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|bhnd_unmap_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|rman_res_t
name|irq
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_UNMAP_INTR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|irq
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Allocate and enable per-core PMU request handling for @p child.  *  * The region containing the core's PMU register block (if any) must be  * allocated via bus_alloc_resource(9) (or bhnd_alloc_resource) before  * calling bhnd_alloc_pmu(), and must not be released until after  * calling bhnd_release_pmu().  *  * @param dev The parent of @p child.  * @param child The requesting bhnd device.  *   * @retval 0           success  * @retval non-zero    If allocating PMU request state otherwise fails, a  *                     regular unix error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_alloc_pmu
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_ALLOC_PMU
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Release any per-core PMU resources allocated for @p child. Any outstanding  * PMU requests are are discarded.  *  * @param dev The parent of @p child.  * @param child The requesting bhnd device.  *   * @retval 0           success  * @retval non-zero    If releasing PMU request state otherwise fails, a  *                     regular unix error code will be returned, and  *                     the core state will be left unmodified.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_release_pmu
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_RELEASE_PMU
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**   * Request that @p clock (or faster) be routed to @p dev.  *   * @note A driver must ask the bhnd bus to allocate clock request state  * via bhnd_alloc_pmu() before it can request clock resources.  *   * @note Any outstanding PMU clock requests will be discarded upon calling  * BHND_BUS_RESET_HW() or BHND_BUS_SUSPEND_HW().  *  * @param dev The bhnd(4) device to which @p clock should be routed.  * @param clock The requested clock source.   *  * @retval 0 success  * @retval ENODEV If an unsupported clock was requested.  * @retval ENXIO If the PMU has not been initialized or is otherwise unvailable,  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_request_clock
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_clock
name|clock
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_REQUEST_CLOCK
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clock
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Request that @p clocks be powered on behalf of @p dev.  *  * This will power any clock sources (e.g. XTAL, PLL, etc) required for  * @p clocks and wait until they are ready, discarding any previous  * requests by @p dev.  *   * @note A driver must ask the bhnd bus to allocate clock request state  * via bhnd_alloc_pmu() before it can request clock resources.  *   * @note Any outstanding PMU clock requests will be discarded upon calling  * BHND_BUS_RESET_HW() or BHND_BUS_SUSPEND_HW().  *   * @param dev The requesting bhnd(4) device.  * @param clocks The clock(s) to be enabled.  *  * @retval 0 success  * @retval ENODEV If an unsupported clock was requested.  * @retval ENXIO If the PMU has not been initialized or is otherwise unvailable.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_enable_clocks
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
name|clocks
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_ENABLE_CLOCKS
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|clocks
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Power up an external PMU-managed resource assigned to @p dev.  *   * @note A driver must ask the bhnd bus to allocate PMU request state  * via bhnd_alloc_pmu() before it can request PMU resources.  *  * @note Any outstanding PMU resource requests will be released upon calling  * bhnd_reset_hw() or bhnd_suspend_hw().  *  * @param dev The requesting bhnd(4) device.  * @param rsrc The core-specific external resource identifier.  *  * @retval 0 success  * @retval ENODEV If the PMU does not support @p rsrc.  * @retval ENXIO If the PMU has not been initialized or is otherwise unvailable.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_request_ext_rsrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|rsrc
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_REQUEST_EXT_RSRC
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|rsrc
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Power down an external PMU-managed resource assigned to @p dev.  *   * A driver must ask the bhnd bus to allocate PMU request state  * via bhnd_alloc_pmu() before it can request PMU resources.  *  * @param dev The requesting bhnd(4) device.  * @param rsrc The core-specific external resource identifier.  *  * @retval 0 success  * @retval ENODEV If the PMU does not support @p rsrc.  * @retval ENXIO If the PMU has not been initialized or is otherwise unvailable.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_release_ext_rsrc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|u_int
name|rsrc
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_RELEASE_EXT_RSRC
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|rsrc
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Read @p width bytes at @p offset from the bus-specific agent/config  * space of @p dev.  *  * @param dev The bhnd device for which @p offset should be read.  * @param offset The offset to be read.  * @param[out] value On success, the will be set to the @p width value read  * at @p offset.  * @param width The size of the access. Must be 1, 2 or 4 bytes.  *  * The exact behavior of this method is bus-specific. In the case of  * bcma(4), this method provides access to the first agent port of @p child.  *  * @note Device drivers should only use this API for functionality  * that is not available via another bhnd(4) function.  *   * @retval 0 success  * @retval EINVAL If @p child is not a direct child of @p dev.  * @retval EINVAL If @p width is not one of 1, 2, or 4 bytes.  * @retval ENODEV If accessing agent/config space for @p child is unsupported.  * @retval EFAULT If reading @p width at @p offset exceeds the bounds of  * the mapped agent/config space  for @p child.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|bhnd_read_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|void
modifier|*
name|value
parameter_list|,
name|u_int
name|width
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_READ_CONFIG
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|value
argument_list|,
name|width
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Write @p width bytes at @p offset to the bus-specific agent/config  * space of @p dev.  *  * @param dev The bhnd device for which @p offset should be read.  * @param offset The offset to be written.  * @param value A pointer to the value to be written.  * @param width The size of @p value. Must be 1, 2 or 4 bytes.  *  * The exact behavior of this method is bus-specific. In the case of  * bcma(4), this method provides access to the first agent port of @p child.  *  * @note Device drivers should only use this API for functionality  * that is not available via another bhnd(4) function.  *   * @retval 0 success  * @retval EINVAL If @p child is not a direct child of @p dev.  * @retval EINVAL If @p width is not one of 1, 2, or 4 bytes.  * @retval ENODEV If accessing agent/config space for @p child is unsupported.  * @retval EFAULT If reading @p width at @p offset exceeds the bounds of  * the mapped agent/config space  for @p child.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_write_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
specifier|const
name|void
modifier|*
name|value
parameter_list|,
name|u_int
name|width
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_WRITE_CONFIG
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|offset
argument_list|,
name|value
argument_list|,
name|width
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Read an NVRAM variable, coerced to the requested @p type.  *  * @param 		dev	A bhnd bus child device.  * @param		name	The NVRAM variable name.  * @param[out]		buf	A buffer large enough to hold @p len bytes. On  *				success, the requested value will be written to  *				this buffer. This argment may be NULL if  *				the value is not desired.  * @param[in,out]	len	The maximum capacity of @p buf. On success,  *				will be set to the actual size of the requested  *				value.  * @param		type	The desired data representation to be written  *				to @p buf.  *   * @retval 0		success  * @retval ENOENT	The requested variable was not found.  * @retval ENODEV	No valid NVRAM source could be found.  * @retval ENOMEM	If a buffer of @p size is too small to hold the  *			requested value.  * @retval EOPNOTSUPP	If the value cannot be coerced to @p type.  * @retval ERANGE	If value coercion would overflow @p type.  * @retval non-zero	If reading @p name otherwise fails, a regular unix  *			error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_nvram_getvar
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|bhnd_nvram_type
name|type
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_NVRAM_VAR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|name
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
name|type
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Allocate a resource from a device's parent bhnd(4) bus.  *   * @param dev The device requesting resource ownership.  * @param type The type of resource to allocate. This may be any type supported  * by the standard bus APIs.  * @param rid The bus-specific handle identifying the resource being allocated.  * @param start The start address of the resource.  * @param end The end address of the resource.  * @param count The size of the resource.  * @param flags The flags for the resource to be allocated. These may be any  * values supported by the standard bus APIs.  *   * To request the resource's default addresses, pass @p start and  * @p end values of @c 0 and @c ~0, respectively, and  * a @p count of @c 1.  *   * @retval NULL The resource could not be allocated.  * @retval resource The allocated resource.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|bhnd_resource
modifier|*
name|bhnd_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
block|{
return|return
name|BHND_BUS_ALLOC_RESOURCE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
name|start
argument_list|,
name|end
argument_list|,
name|count
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Allocate a resource from a device's parent bhnd(4) bus, using the  * resource's default start, end, and count values.  *   * @param dev The device requesting resource ownership.  * @param type The type of resource to allocate. This may be any type supported  * by the standard bus APIs.  * @param rid The bus-specific handle identifying the resource being allocated.  * @param flags The flags for the resource to be allocated. These may be any  * values supported by the standard bus APIs.  *   * @retval NULL The resource could not be allocated.  * @retval resource The allocated resource.  */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|bhnd_resource
modifier|*
name|bhnd_alloc_resource_any
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_int
name|flags
parameter_list|)
block|{
return|return
name|bhnd_alloc_resource
argument_list|(
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
literal|1
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Activate a previously allocated bhnd resource.  *  * @param dev The device holding ownership of the allocated resource.  * @param type The type of the resource.   * @param rid The bus-specific handle identifying the resource.  * @param r A pointer to the resource returned by bhnd_alloc_resource or  * BHND_BUS_ALLOC_RESOURCE.  *   * @retval 0 success  * @retval non-zero an error occurred while activating the resource.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_activate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
block|{
return|return
name|BHND_BUS_ACTIVATE_RESOURCE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Deactivate a previously activated bhnd resource.  *  * @param dev The device holding ownership of the activated resource.  * @param type The type of the resource.   * @param rid The bus-specific handle identifying the resource.  * @param r A pointer to the resource returned by bhnd_alloc_resource or  * BHND_BUS_ALLOC_RESOURCE.  *   * @retval 0 success  * @retval non-zero an error occurred while activating the resource.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_deactivate_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
block|{
return|return
name|BHND_BUS_DEACTIVATE_RESOURCE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Free a resource allocated by bhnd_alloc_resource().  *  * @param dev The device holding ownership of the resource.  * @param type The type of the resource.   * @param rid The bus-specific handle identifying the resource.  * @param r A pointer to the resource returned by bhnd_alloc_resource or  * BHND_ALLOC_RESOURCE.  *   * @retval 0 success  * @retval non-zero an error occurred while activating the resource.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|bhnd_resource
modifier|*
name|r
parameter_list|)
block|{
return|return
name|BHND_BUS_RELEASE_RESOURCE
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return true if @p region_num is a valid region on @p port_num of  * @p type attached to @p dev.  *  * @param dev A bhnd bus child device.  * @param type The port type being queried.  * @param port_num The port number being queried.  * @param region_num The region number being queried.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bhnd_is_region_valid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port_num
parameter_list|,
name|u_int
name|region_num
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_IS_REGION_VALID
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|port_num
argument_list|,
name|region_num
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the number of ports of type @p type attached to @p def.  *  * @param dev A bhnd bus child device.  * @param type The port type being queried.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|bhnd_get_port_count
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_PORT_COUNT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the number of memory regions mapped to @p child @p port of  * type @p type.  *  * @param dev A bhnd bus child device.  * @param port The port number being queried.  * @param type The port type being queried.  */
end_comment

begin_function
specifier|static
specifier|inline
name|u_int
name|bhnd_get_region_count
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|)
block|{
return|return
operator|(
name|BHND_BUS_GET_REGION_COUNT
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|port
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Return the resource-ID for a memory region on the given device port.  *  * @param dev A bhnd bus child device.  * @param type The port type.  * @param port The port identifier.  * @param region The identifier of the memory region on @p port.  *   * @retval int The RID for the given @p port and @p region on @p device.  * @retval -1 No such port/region found.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_get_port_rid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_port_type
name|type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|)
block|{
return|return
name|BHND_BUS_GET_PORT_RID
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|port
argument_list|,
name|region
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Decode a port / region pair on @p dev defined by @p rid.  *  * @param dev A bhnd bus child device.  * @param type The resource type.  * @param rid The resource identifier.  * @param[out] port_type The decoded port type.  * @param[out] port The decoded port identifier.  * @param[out] region The decoded region identifier.  *  * @retval 0 success  * @retval non-zero No matching port/region found.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_decode_port_rid
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|bhnd_port_type
modifier|*
name|port_type
parameter_list|,
name|u_int
modifier|*
name|port
parameter_list|,
name|u_int
modifier|*
name|region
parameter_list|)
block|{
return|return
name|BHND_BUS_DECODE_PORT_RID
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|type
argument_list|,
name|rid
argument_list|,
name|port_type
argument_list|,
name|port
argument_list|,
name|region
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/**  * Get the address and size of @p region on @p port.  *  * @param dev A bhnd bus child device.  * @param port_type The port type.  * @param port The port identifier.  * @param region The identifier of the memory region on @p port.  * @param[out] region_addr The region's base address.  * @param[out] region_size The region's size.  *  * @retval 0 success  * @retval non-zero No matching port/region found.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_get_region_addr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|bhnd_port_type
name|port_type
parameter_list|,
name|u_int
name|port
parameter_list|,
name|u_int
name|region
parameter_list|,
name|bhnd_addr_t
modifier|*
name|region_addr
parameter_list|,
name|bhnd_size_t
modifier|*
name|region_size
parameter_list|)
block|{
return|return
name|BHND_BUS_GET_REGION_ADDR
argument_list|(
name|device_get_parent
argument_list|(
name|dev
argument_list|)
argument_list|,
name|dev
argument_list|,
name|port_type
argument_list|,
name|port
argument_list|,
name|region
argument_list|,
name|region_addr
argument_list|,
name|region_size
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/*  * bhnd bus-level equivalents of the bus_(read|write|set|barrier|...)  * macros (compatible with bhnd_resource).  *  * Generated with bhnd/tools/bus_macro.sh  */
end_comment

begin_define
define|#
directive|define
name|bhnd_bus_barrier
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|l
parameter_list|,
name|f
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_barrier((r)->res, (o), (l), (f)) : \ 	BHND_BUS_BARRIER( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (l), (f))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_1((r)->res, (o)) : \ 	BHND_BUS_READ_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_1((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_stream_1((r)->res, (o)) : \ 	BHND_BUS_READ_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_stream_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_stream_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_stream_1((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_stream_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_stream_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_stream_1((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_STREAM_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_multi_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_multi_1((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_MULTI_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_region_1
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_region_1((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_REGION_1( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_2((r)->res, (o)) : \ 	BHND_BUS_READ_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_2((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_stream_2((r)->res, (o)) : \ 	BHND_BUS_READ_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_stream_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_stream_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_stream_2((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_stream_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_stream_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_stream_2((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_STREAM_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_multi_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_multi_2((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_MULTI_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_region_2
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_region_2((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_REGION_2( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_4((r)->res, (o)) : \ 	BHND_BUS_READ_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_4((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_stream_4((r)->res, (o)) : \ 	BHND_BUS_READ_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_multi_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_multi_stream_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_MULTI_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_read_region_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_read_region_stream_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_READ_REGION_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_stream_4((r)->res, (o), (v)) : \ 	BHND_BUS_WRITE_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_multi_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_multi_stream_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_MULTI_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_write_region_stream_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|d
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_write_region_stream_4((r)->res, (o), (d), (c)) : \ 	BHND_BUS_WRITE_REGION_STREAM_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (d), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_multi_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_multi_4((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_MULTI_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_define
define|#
directive|define
name|bhnd_bus_set_region_4
parameter_list|(
name|r
parameter_list|,
name|o
parameter_list|,
name|v
parameter_list|,
name|c
parameter_list|)
define|\
value|((r)->direct) ? \ 	bus_set_region_4((r)->res, (o), (v), (c)) : \ 	BHND_BUS_SET_REGION_4( \ 	    device_get_parent(rman_get_device((r)->res)),	\ 	    rman_get_device((r)->res), (r), (o), (v), (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_H_ */
end_comment

end_unit

