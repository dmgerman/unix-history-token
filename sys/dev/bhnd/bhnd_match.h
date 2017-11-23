begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_MATCH_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_MATCH_H_
end_define

begin_include
include|#
directive|include
file|"bhnd_types.h"
end_include

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
comment|/* Copy match field @p _name from @p _src */
end_comment

begin_define
define|#
directive|define
name|_BHND_COPY_MATCH_FIELD
parameter_list|(
name|_src
parameter_list|,
name|_name
parameter_list|)
define|\
value|.m.match._name = (_src)->m.match._name,	\ 	._name = (_src)->_name
end_define

begin_comment
comment|/* Set match field @p _name with @p _value */
end_comment

begin_define
define|#
directive|define
name|_BHND_SET_MATCH_FIELD
parameter_list|(
name|_name
parameter_list|,
name|_value
parameter_list|)
define|\
value|.m.match._name = 1, ._name = _value
end_define

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
comment|/**  * A bhnd(4) core match descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_core_match
block|{
comment|/** Select fields to be matched */
union|union
block|{
name|uint8_t
name|match_flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|core_vendor
range|:
literal|1
decl_stmt|,
name|core_id
range|:
literal|1
decl_stmt|,
name|core_rev
range|:
literal|1
decl_stmt|,
name|core_class
range|:
literal|1
decl_stmt|,
name|core_idx
range|:
literal|1
decl_stmt|,
name|core_unit
range|:
literal|1
decl_stmt|,
name|flags_unused
range|:
literal|2
decl_stmt|;
block|}
name|match
struct|;
block|}
name|m
union|;
name|uint16_t
name|core_vendor
decl_stmt|;
comment|/**< required JEP106 device vendor */
name|uint16_t
name|core_id
decl_stmt|;
comment|/**< required core ID */
name|struct
name|bhnd_hwrev_match
name|core_rev
decl_stmt|;
comment|/**< matching core revisions. */
name|bhnd_devclass_t
name|core_class
decl_stmt|;
comment|/**< required bhnd class */
name|u_int
name|core_idx
decl_stmt|;
comment|/**< required core index */
name|int
name|core_unit
decl_stmt|;
comment|/**< required core unit */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_BHND_CORE_MATCH_COPY
parameter_list|(
name|_src
parameter_list|)
define|\
value|_BHND_COPY_MATCH_FIELD(_src, core_vendor),	\ 	_BHND_COPY_MATCH_FIELD(_src, core_id),		\ 	_BHND_COPY_MATCH_FIELD(_src, core_rev),		\ 	_BHND_COPY_MATCH_FIELD(_src, core_class),	\ 	_BHND_COPY_MATCH_FIELD(_src, core_idx),		\ 	_BHND_COPY_MATCH_FIELD(_src, core_unit)		\  #define	BHND_MATCH_CORE_VENDOR(_v)	_BHND_SET_MATCH_FIELD(core_vendor, _v)
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_CORE_ID
parameter_list|(
name|_id
parameter_list|)
value|_BHND_SET_MATCH_FIELD(core_id, _id)
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_CORE_REV
parameter_list|(
name|_rev
parameter_list|)
value|_BHND_SET_MATCH_FIELD(core_rev,	\ 					    BHND_ ## _rev)
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_CORE_CLASS
parameter_list|(
name|_cls
parameter_list|)
value|_BHND_SET_MATCH_FIELD(core_class, _cls)
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_CORE_IDX
parameter_list|(
name|_idx
parameter_list|)
value|_BHND_SET_MATCH_FIELD(core_idx, _idx)
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_CORE_UNIT
parameter_list|(
name|_unit
parameter_list|)
value|_BHND_SET_MATCH_FIELD(core_unit, _unit)
end_define

begin_comment
comment|/**  * Match against the given @p _vendor and @p _id,  */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CORE
parameter_list|(
name|_vendor
parameter_list|,
name|_id
parameter_list|)
define|\
value|BHND_MATCH_CORE_VENDOR(_vendor),	\ 	BHND_MATCH_CORE_ID(_id)
end_define

begin_comment
comment|/**  * A bhnd(4) chip match descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_chip_match
block|{
comment|/** Select fields to be matched */
union|union
block|{
name|uint8_t
name|match_flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|chip_id
range|:
literal|1
decl_stmt|,
name|chip_rev
range|:
literal|1
decl_stmt|,
name|chip_pkg
range|:
literal|1
decl_stmt|,
name|chip_type
range|:
literal|1
decl_stmt|,
name|flags_unused
range|:
literal|4
decl_stmt|;
block|}
name|match
struct|;
block|}
name|m
union|;
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
name|uint8_t
name|chip_type
decl_stmt|;
comment|/**< required chip type (BHND_CHIPTYPE_*) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|_BHND_CHIP_MATCH_COPY
parameter_list|(
name|_src
parameter_list|)
define|\
value|_BHND_COPY_MATCH_FIELD(_src, chip_id),	\ 	_BHND_COPY_MATCH_FIELD(_src, chip_rev),	\ 	_BHND_COPY_MATCH_FIELD(_src, chip_pkg),	\ 	_BHND_COPY_MATCH_FIELD(_src, chip_type),
end_define

begin_comment
unit|\
comment|/** Set the required chip ID within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_ID
parameter_list|(
name|_cid
parameter_list|)
value|_BHND_SET_MATCH_FIELD(chip_id,	\ 					    BHND_CHIPID_ ## _cid)
end_define

begin_comment
comment|/** Set the required chip revision range within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_REV
parameter_list|(
name|_rev
parameter_list|)
value|_BHND_SET_MATCH_FIELD(chip_rev,	\ 					    BHND_ ## _rev)
end_define

begin_comment
comment|/** Set the required package ID within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_PKG
parameter_list|(
name|_pkg
parameter_list|)
value|_BHND_SET_MATCH_FIELD(chip_pkg,	\ 					    BHND_PKGID_ ## _pkg)
end_define

begin_comment
comment|/** Set the required chip type within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_TYPE
parameter_list|(
name|_type
parameter_list|)
value|_BHND_SET_MATCH_FIELD(chip_type,	\ 					    BHND_CHIPTYPE_ ## _type)
end_define

begin_comment
comment|/** Set the required chip and package ID within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_IP
parameter_list|(
name|_cid
parameter_list|,
name|_pkg
parameter_list|)
define|\
value|BHND_MATCH_CHIP_ID(_cid), BHND_MATCH_CHIP_PKG(_pkg)
end_define

begin_comment
comment|/** Set the required chip ID, package ID, and revision within a bhnd_device_match  *  instance */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_IPR
parameter_list|(
name|_cid
parameter_list|,
name|_pkg
parameter_list|,
name|_rev
parameter_list|)
define|\
value|BHND_MATCH_CHIP_ID(_cid),			\     BHND_MATCH_CHIP_PKG(_pkg),			\     BHND_MATCH_CHIP_REV(_rev)
end_define

begin_comment
comment|/** Set the required chip ID and revision within a bhnd_device_match  *  instance */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_CHIP_IR
parameter_list|(
name|_cid
parameter_list|,
name|_rev
parameter_list|)
define|\
value|BHND_MATCH_CHIP_ID(_cid), BHND_MATCH_CHIP_REV(_rev)
end_define

begin_comment
comment|/**  * A bhnd(4) board match descriptor.  */
end_comment

begin_struct
struct|struct
name|bhnd_board_match
block|{
comment|/** Select fields to be matched */
union|union
block|{
name|uint8_t
name|match_flags
decl_stmt|;
struct|struct
block|{
name|uint8_t
name|board_vendor
range|:
literal|1
decl_stmt|,
name|board_type
range|:
literal|1
decl_stmt|,
name|board_rev
range|:
literal|1
decl_stmt|,
name|board_srom_rev
range|:
literal|1
decl_stmt|,
name|flags_unused
range|:
literal|4
decl_stmt|;
block|}
name|match
struct|;
block|}
name|m
union|;
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
name|_BHND_BOARD_MATCH_COPY
parameter_list|(
name|_src
parameter_list|)
define|\
value|_BHND_COPY_MATCH_FIELD(_src, board_vendor),	\ 	_BHND_COPY_MATCH_FIELD(_src, board_type),	\ 	_BHND_COPY_MATCH_FIELD(_src, board_rev),	\ 	_BHND_COPY_MATCH_FIELD(_src, board_srom_rev)
end_define

begin_comment
comment|/** Set the required board vendor within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_BOARD_VENDOR
parameter_list|(
name|_v
parameter_list|)
value|_BHND_SET_MATCH_FIELD(board_vendor, _v)
end_define

begin_comment
comment|/** Set the required board type within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_BOARD_TYPE
parameter_list|(
name|_type
parameter_list|)
value|_BHND_SET_MATCH_FIELD(board_type, \ 					    BHND_BOARD_ ## _type)
end_define

begin_comment
comment|/** Set the required SROM revision range within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_SROMREV
parameter_list|(
name|_rev
parameter_list|)
value|_BHND_SET_MATCH_FIELD(board_srom_rev, \ 					    BHND_HWREV_ ## _rev)
end_define

begin_comment
comment|/** Set the required board revision range within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_BOARD_REV
parameter_list|(
name|_rev
parameter_list|)
value|_BHND_SET_MATCH_FIELD(board_rev, \ 					    BHND_ ## _rev)
end_define

begin_comment
comment|/** Set the required board vendor and type within a bhnd match descriptor */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_BOARD
parameter_list|(
name|_vend
parameter_list|,
name|_type
parameter_list|)
define|\
value|BHND_MATCH_BOARD_VENDOR(_vend), BHND_MATCH_BOARD_TYPE(_type)
end_define

begin_comment
comment|/**  * A bhnd(4) device match descriptor.  *  * @warning Matching on board attributes relies on NVRAM access, and will  * fail if a valid NVRAM device cannot be found, or is not yet attached.  */
end_comment

begin_struct
struct|struct
name|bhnd_device_match
block|{
comment|/** Select fields to be matched */
union|union
block|{
name|uint32_t
name|match_flags
decl_stmt|;
struct|struct
block|{
name|uint32_t
name|core_vendor
range|:
literal|1
decl_stmt|,
name|core_id
range|:
literal|1
decl_stmt|,
name|core_rev
range|:
literal|1
decl_stmt|,
name|core_class
range|:
literal|1
decl_stmt|,
name|core_idx
range|:
literal|1
decl_stmt|,
name|core_unit
range|:
literal|1
decl_stmt|,
name|chip_id
range|:
literal|1
decl_stmt|,
name|chip_rev
range|:
literal|1
decl_stmt|,
name|chip_pkg
range|:
literal|1
decl_stmt|,
name|chip_type
range|:
literal|1
decl_stmt|,
name|board_vendor
range|:
literal|1
decl_stmt|,
name|board_type
range|:
literal|1
decl_stmt|,
name|board_rev
range|:
literal|1
decl_stmt|,
name|board_srom_rev
range|:
literal|1
decl_stmt|,
name|flags_unused
range|:
literal|16
decl_stmt|;
block|}
name|match
struct|;
block|}
name|m
union|;
name|uint16_t
name|core_vendor
decl_stmt|;
comment|/**< required JEP106 device vendor */
name|uint16_t
name|core_id
decl_stmt|;
comment|/**< required core ID */
name|struct
name|bhnd_hwrev_match
name|core_rev
decl_stmt|;
comment|/**< matching core revisions. */
name|bhnd_devclass_t
name|core_class
decl_stmt|;
comment|/**< required bhnd class */
name|u_int
name|core_idx
decl_stmt|;
comment|/**< required core index */
name|int
name|core_unit
decl_stmt|;
comment|/**< required core unit */
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
name|uint8_t
name|chip_type
decl_stmt|;
comment|/**< required chip type (BHND_CHIPTYPE_*) */
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

begin_comment
comment|/** Define a wildcard match requirement (matches on any device). */
end_comment

begin_define
define|#
directive|define
name|BHND_MATCH_ANY
value|.m.match_flags = 0
end_define

begin_define
define|#
directive|define
name|BHND_MATCH_IS_ANY
parameter_list|(
name|_m
parameter_list|)
define|\
value|((_m)->m.match_flags == 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_MATCH_H_ */
end_comment

end_unit

