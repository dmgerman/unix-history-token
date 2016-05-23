begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
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
file|"bhnd_debug.h"
end_include

begin_include
include|#
directive|include
file|"bhnd_bus_if.h"
end_include

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
comment|/**< Busses and bridges */
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
comment|/**  * A hardware revision match descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_hwrev_match
block|{
name|uint16_t
name|start
decl_stmt|;
comment|/**< first revision, or BHND_HWREV_INVALID 					     to match on any revision. */
name|uint16_t
name|end
decl_stmt|;
comment|/**< last revision, or BHND_HWREV_INVALID 					     to match on any revision. */
block|}
struct|;
end_struct

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
comment|/**   * Wildcard hardware revision match descriptor.  */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_ANY
value|{ BHND_HWREV_INVALID, BHND_HWREV_INVALID }
end_define

begin_define
define|#
directive|define
name|BHND_HWREV_IS_ANY
parameter_list|(
name|_m
parameter_list|)
define|\
value|((_m)->start == BHND_HWREV_INVALID&& (_m)->end == BHND_HWREV_INVALID)
end_define

begin_comment
comment|/**  * Hardware revision match descriptor for an inclusive range.  *   * @param _start The first applicable hardware revision.  * @param _end The last applicable hardware revision, or BHND_HWREV_INVALID  * to match on any revision.  */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_RANGE
parameter_list|(
name|_start
parameter_list|,
name|_end
parameter_list|)
value|{ _start, _end }
end_define

begin_comment
comment|/**  * Hardware revision match descriptor for a single revision.  *   * @param _hwrev The hardware revision to match on.  */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_EQ
parameter_list|(
name|_hwrev
parameter_list|)
value|BHND_HWREV_RANGE(_hwrev, _hwrev)
end_define

begin_comment
comment|/**  * Hardware revision match descriptor for any revision equal to or greater  * than @p _start.  *   * @param _start The first hardware revision to match on.  */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_GTE
parameter_list|(
name|_start
parameter_list|)
value|BHND_HWREV_RANGE(_start, BHND_HWREV_INVALID)
end_define

begin_comment
comment|/**  * Hardware revision match descriptor for any revision equal to or less  * than @p _end.  *   * @param _end The last hardware revision to match on.  */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_LTE
parameter_list|(
name|_end
parameter_list|)
value|BHND_HWREV_RANGE(0, _end)
end_define

begin_comment
comment|/** A core match descriptor. */
end_comment

begin_struct
struct|struct
name|bhnd_core_match
block|{
name|uint16_t
name|vendor
decl_stmt|;
comment|/**< required JEP106 device vendor or BHND_MFGID_INVALID. */
name|uint16_t
name|device
decl_stmt|;
comment|/**< required core ID or BHND_COREID_INVALID */
name|struct
name|bhnd_hwrev_match
name|hwrev
decl_stmt|;
comment|/**< matching revisions. */
name|bhnd_devclass_t
name|class
decl_stmt|;
comment|/**< required class or BHND_DEVCLASS_INVALID */
name|int
name|unit
decl_stmt|;
comment|/**< required core unit, or -1 */
block|}
struct|;
end_struct

begin_comment
comment|/**  * Core match descriptor matching against the given @p _vendor, @p _device,  * and @p _hwrev match descriptors.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CORE_MATCH
parameter_list|(
name|_vendor
parameter_list|,
name|_device
parameter_list|,
name|_hwrev
parameter_list|)
define|\
value|{ _vendor, _device, _hwrev, BHND_DEVCLASS_INVALID, -1 }
end_define

begin_comment
comment|/**   * Wildcard core match descriptor.  */
end_comment

begin_define
define|#
directive|define
name|BHND_CORE_MATCH_ANY
define|\
value|{					\ 		.vendor = BHND_MFGID_INVALID,	\ 		.device = BHND_COREID_INVALID,	\ 		.hwrev = BHND_HWREV_ANY,	\ 		.class = BHND_DEVCLASS_INVALID,	\ 		.unit = -1			\ 	}
end_define

begin_comment
comment|/**  * A chipset match descriptor.  *   * @warning Matching on board/nvram attributes relies on NVRAM access, and will  * fail if a valid NVRAM device cannot be found, or is not yet attached.  */
end_comment

begin_struct
struct|struct
name|bhnd_chip_match
block|{
comment|/** Select fields to be matched */
name|uint16_t
name|match_id
range|:
literal|1
decl_stmt|,
name|match_rev
range|:
literal|1
decl_stmt|,
name|match_pkg
range|:
literal|1
decl_stmt|,
name|match_bvendor
range|:
literal|1
decl_stmt|,
name|match_btype
range|:
literal|1
decl_stmt|,
name|match_brev
range|:
literal|1
decl_stmt|,
name|match_srom_rev
range|:
literal|1
decl_stmt|,
name|match_any
range|:
literal|1
decl_stmt|,
name|match_flags_unused
range|:
literal|8
decl_stmt|;
name|uint16_t
name|chip_id
decl_stmt|;
comment|/**< required chip id */
name|struct
name|bhnd_hwrev_match
name|chip_rev
decl_stmt|;
comment|/**< matching chip revisions */
name|uint8_t
name|chip_pkg
decl_stmt|;
comment|/**< required package */
name|uint16_t
name|board_vendor
decl_stmt|;
comment|/**< required board vendor */
name|uint16_t
name|board_type
decl_stmt|;
comment|/**< required board type */
name|struct
name|bhnd_hwrev_match
name|board_rev
decl_stmt|;
comment|/**< matching board revisions */
name|struct
name|bhnd_hwrev_match
name|board_srom_rev
decl_stmt|;
comment|/**< matching board srom revisions */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BHND_CHIP_MATCH_ANY
define|\
value|{ .match_any = 1 }
end_define

begin_define
define|#
directive|define
name|BHND_CHIP_MATCH_IS_ANY
parameter_list|(
name|_m
parameter_list|)
define|\
value|((_m)->match_any == 1)
end_define

begin_define
define|#
directive|define
name|BHND_CHIP_MATCH_REQ_BOARD_INFO
parameter_list|(
name|_m
parameter_list|)
define|\
value|((_m)->match_srom_rev || (_m)->match_bvendor ||	\ 	    (_m)->match_btype || (_m)->match_brev)
end_define

begin_comment
comment|/** Set the required chip ID within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_ID
parameter_list|(
name|_cid
parameter_list|)
define|\
value|.match_id = 1, .chip_id = BHND_CHIPID_BCM ## _cid
end_define

begin_comment
comment|/** Set the required chip revision range within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_REV
parameter_list|(
name|_rev
parameter_list|)
define|\
value|.match_rev = 1, .chip_rev = BHND_ ## _rev
end_define

begin_comment
comment|/** Set the required package ID within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_PKG
parameter_list|(
name|_pkg
parameter_list|)
define|\
value|.match_pkg = 1, .chip_pkg = BHND_PKGID_BCM ## _pkg
end_define

begin_comment
comment|/** Set the required board vendor within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_BVENDOR
parameter_list|(
name|_vend
parameter_list|)
define|\
value|.match_bvendor = 1, .board_vendor = _vend
end_define

begin_comment
comment|/** Set the required board type within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_BTYPE
parameter_list|(
name|_btype
parameter_list|)
define|\
value|.match_btype = 1, .board_type = BHND_BOARD_ ## _btype
end_define

begin_comment
comment|/** Set the required SROM revision range within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_SROMREV
parameter_list|(
name|_rev
parameter_list|)
define|\
value|.match_srom_rev = 1, .board_srom_rev = BHND_ ## _rev
end_define

begin_comment
comment|/** Set the required board revision range within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_BREV
parameter_list|(
name|_rev
parameter_list|)
define|\
value|.match_brev = 1, .board_rev = BHND_ ## _rev
end_define

begin_comment
comment|/** Set the required board vendor and type within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_BVT
parameter_list|(
name|_vend
parameter_list|,
name|_type
parameter_list|)
define|\
value|BHND_CHIP_BVENDOR(_vend), BHND_CHIP_BTYPE(_type)
end_define

begin_comment
comment|/** Set the required board vendor, type, and revision within a bhnd_chip_match  *  instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_BVTR
parameter_list|(
name|_vend
parameter_list|,
name|_type
parameter_list|,
name|_rev
parameter_list|)
define|\
value|BHND_CHIP_BVT(_vend, _type), BHND_CHIP_BREV(_rev)
end_define

begin_comment
comment|/** Set the required chip and package ID within a bhnd_chip_match instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_IP
parameter_list|(
name|_cid
parameter_list|,
name|_pkg
parameter_list|)
define|\
value|BHND_CHIP_ID(_cid), BHND_CHIP_PKG(_pkg)
end_define

begin_comment
comment|/** Set the required chip ID, package ID, and revision within a bhnd_chip_match  *  instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_IPR
parameter_list|(
name|_cid
parameter_list|,
name|_pkg
parameter_list|,
name|_rev
parameter_list|)
define|\
value|BHND_CHIP_ID(_cid), BHND_CHIP_PKG(_pkg), BHND_CHIP_REV(_rev)
end_define

begin_comment
comment|/** Set the required chip ID and revision within a bhnd_chip_match  *  instance */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIP_IR
parameter_list|(
name|_cid
parameter_list|,
name|_rev
parameter_list|)
define|\
value|BHND_CHIP_ID(_cid), BHND_CHIP_REV(_rev)
end_define

begin_comment
comment|/**  * Chipset quirk table descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_chip_quirk
block|{
specifier|const
name|struct
name|bhnd_chip_match
name|chip
decl_stmt|;
comment|/**< chip match descriptor */
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
name|BHND_CHIP_QUIRK_END
value|{ BHND_CHIP_MATCH_ANY, 0 }
end_define

begin_define
define|#
directive|define
name|BHND_CHIP_QUIRK_IS_END
parameter_list|(
name|_q
parameter_list|)
define|\
value|(BHND_CHIP_MATCH_IS_ANY(&(_q)->chip)&& (_q)->quirks == 0)
end_define

begin_comment
comment|/**  * Device quirk table descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_device_quirk
block|{
name|struct
name|bhnd_hwrev_match
name|hwrev
decl_stmt|;
comment|/**< applicable hardware revisions */
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
name|BHND_DEVICE_QUIRK_END
value|{ BHND_HWREV_ANY, 0 }
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_QUIRK_IS_END
parameter_list|(
name|_q
parameter_list|)
define|\
value|(BHND_HWREV_IS_ANY(&(_q)->hwrev)&& (_q)->quirks == 0)
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
comment|/**< core is serving as the bus' 					  *  host bridge */
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
name|bhnd_core_match
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
specifier|const
name|struct
name|bhnd_chip_quirk
modifier|*
name|chip_quirks_table
decl_stmt|;
comment|/**< chipset-specific quirks for this device, or NULL */
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
parameter_list|,
name|_chip_quirks
parameter_list|,	\
name|_flags
parameter_list|,
modifier|...
parameter_list|)
define|\
value|{ BHND_CORE_MATCH(BHND_MFGID_ ## _vendor,			\ 	    BHND_COREID_ ## _device, BHND_HWREV_ANY), _desc, _quirks,	\ 	    _chip_quirks, _flags }
end_define

begin_define
define|#
directive|define
name|BHND_MIPS_DEVICE
parameter_list|(
name|_device
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|,
name|_chip_quirks
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVICE(MIPS, _device, _desc, _quirks, _chip_quirks,	\ 	    ## __VA_ARGS__, 0)
end_define

begin_define
define|#
directive|define
name|BHND_ARM_DEVICE
parameter_list|(
name|_device
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|,
name|_chip_quirks
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVICE(ARM, _device, _desc, _quirks, _chip_quirks,	\ 	    ## __VA_ARGS__, 0)
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE
parameter_list|(
name|_device
parameter_list|,
name|_desc
parameter_list|,
name|_quirks
parameter_list|,
name|_chip_quirks
parameter_list|,
modifier|...
parameter_list|)
define|\
value|_BHND_DEVICE(BCM, _device, _desc, _quirks, _chip_quirks,	\ 	    ## __VA_ARGS__, 0)
end_define

begin_define
define|#
directive|define
name|BHND_DEVICE_END
value|{ BHND_CORE_MATCH_ANY, NULL, NULL, NULL, 0 }
end_define

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
name|device_t
name|bhnd_match_child
parameter_list|(
name|device_t
name|dev
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
name|bhnd_find_child
parameter_list|(
name|device_t
name|dev
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
name|bhnd_board_info
modifier|*
name|binfo
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
name|uint32_t
name|bhnd_chip_quirks
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|bhnd_chip_quirk
modifier|*
name|table
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
name|bhnd_core_match
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
name|bhnd_bus_generic_read_nvram_var
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

begin_comment
comment|/**  * Return the active host bridge core for the bhnd bus, if any, or NULL if  * not found.  *  * @param dev A bhnd bus device.  */
end_comment

begin_function
specifier|static
specifier|inline
name|device_t
name|bhnd_find_hostb_device
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
comment|/**  * Determine an NVRAM variable's expected size.  *  * @param 	dev	A bhnd bus child device.  * @param	name	The variable name.  * @param[out]	len	On success, the variable's size, in bytes.  *  * @retval 0		success  * @retval ENOENT	The requested variable was not found.  * @retval ENODEV	No valid NVRAM source could be found.  * @retval non-zero	If reading @p name otherwise fails, a regular unix  *			error code will be returned.  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|bhnd_nvram_getvarlen
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|size_t
modifier|*
name|len
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
name|NULL
argument_list|,
name|len
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/**  * Read an NVRAM variable.  *  * @param 	dev	A bhnd bus child device.  * @param	name	The NVRAM variable name.  * @param	buf	A buffer large enough to hold @p len bytes. On success,  * 			the requested value will be written to this buffer.  * @param	len	The required variable length.  *  * @retval 0		success  * @retval ENOENT	The requested variable was not found.  * @retval EINVAL	If @p len does not match the actual variable size.  * @retval ENODEV	No valid NVRAM source could be found.  * @retval non-zero	If reading @p name otherwise fails, a regular unix  *			error code will be returned.  */
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
name|len
parameter_list|)
block|{
name|size_t
name|var_len
decl_stmt|;
name|int
name|error
decl_stmt|;
if|if
condition|(
operator|(
name|error
operator|=
name|bhnd_nvram_getvarlen
argument_list|(
name|dev
argument_list|,
name|name
argument_list|,
operator|&
name|var_len
argument_list|)
operator|)
condition|)
return|return
operator|(
name|error
operator|)
return|;
if|if
condition|(
name|len
operator|!=
name|var_len
condition|)
return|return
operator|(
name|EINVAL
operator|)
return|;
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
operator|&
name|len
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

