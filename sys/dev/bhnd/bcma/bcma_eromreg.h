begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  *   * Portions of this file were derived from the aidmp.h header  * distributed with Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCMA_BCMA_EROM_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCMA_BCMA_EROM_REG_H_
end_define

begin_comment
comment|/* Enumeration ROM device registers */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_TABLE_START
value|0x000
end_define

begin_comment
comment|/**< device enumeration table offset */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REMAPCONTROL
value|0xe00
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REMAPSELECT
value|0xe04
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_MASTERSELECT
value|0xe10
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_ITCR
value|0xf00
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_ITIP
value|0xf04
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_TABLE_SIZE
value|BCMA_EROM_REMAPCONTROL - BCMA_EROM_TABLE_START
end_define

begin_comment
comment|/**  * Extract an entry attribute by applying _MASK and _SHIFT defines.  *   * @param _entry The entry containing the desired attribute  * @param _attr The BCMA EROM attribute name (e.g. ENTRY_ISVALID), to be  * concatenated with the `BCMA_EROM_` prefix and `_MASK`/`_SHIFT` suffixes.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_GET_ATTR
parameter_list|(
name|_entry
parameter_list|,
name|_attr
parameter_list|)
define|\
value|((_entry& BCMA_EROM_ ## _attr ## _MASK)	\>> BCMA_EROM_ ## _attr ## _SHIFT)
end_define

begin_comment
comment|/**  * Test an EROM entry's validity and type.  *  * @param _entry The entry to test.  * @param _type The required type  * @retval true if the entry type matches and the BCMA_EROM_ENTRY_ISVALID flag  * is set.  * @retval false if the entry is not valid, or if the type does not match.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_IS
parameter_list|(
name|_entry
parameter_list|,
name|_type
parameter_list|)
define|\
value|(BCMA_EROM_GET_ATTR(_entry, ENTRY_ISVALID)&&			\ 	 BCMA_EROM_GET_ATTR(_entry, ENTRY_TYPE) == BCMA_EROM_ENTRY_TYPE_ ## _type)
end_define

begin_comment
comment|/*  * Enumeration ROM Constants  */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_TABLE_EOF
value|0xF
end_define

begin_comment
comment|/* end of EROM table */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_ISVALID_MASK
value|0x1
end_define

begin_comment
comment|/* is entry valid? */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_ISVALID_SHIFT
value|0
end_define

begin_comment
comment|/* EROM Entry Types */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_TYPE_MASK
value|0x6
end_define

begin_comment
comment|/* entry type mask */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_TYPE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_TYPE_CORE
value|0x0
end_define

begin_comment
comment|/* core descriptor */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_TYPE_MPORT
value|0x2
end_define

begin_comment
comment|/* master port descriptor */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_ENTRY_TYPE_REGION
value|0x4
end_define

begin_comment
comment|/* address region descriptor */
end_comment

begin_comment
comment|/* EROM Core DescriptorA (31:0) */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_DESIGNER_MASK
value|0xFFF00000
end_define

begin_comment
comment|/* core designer (JEP-106 mfg id) */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_DESIGNER_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_ID_MASK
value|0x000FFF00
end_define

begin_comment
comment|/* broadcom-assigned core id */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_ID_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_CLASS_MASK
value|0x000000F0
end_define

begin_comment
comment|/* core class */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREA_CLASS_SHIFT
value|4
end_define

begin_comment
comment|/* EROM Core DescriptorB (63:32) */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_MP_MASK
value|0x000001F0
end_define

begin_comment
comment|/* master port count */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_MP_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_DP_MASK
value|0x00003E00
end_define

begin_comment
comment|/* device/bridge port count */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_DP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_WMP_MASK
value|0x0007C000
end_define

begin_comment
comment|/* master wrapper port count */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_WMP_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_WSP_MASK
value|0x00F80000
end_define

begin_comment
comment|/* slave wrapper port count */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_NUM_WSP_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_REV_MASK
value|0xFF000000
end_define

begin_comment
comment|/* broadcom-assigned core revision */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_COREB_REV_SHIFT
value|24
end_define

begin_comment
comment|/* EROM Master Port Descriptor   *   * The attribute descriptions are derived from background information  * on the AXI bus and PL301 interconnect, but are undocumented  * by Broadcom and may be incorrect.  */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_MPORT_NUM_MASK
value|0x0000FF00
end_define

begin_comment
comment|/* AXI master number (unique per interconnect) */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_MPORT_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_MPORT_ID_MASK
value|0x000000F0
end_define

begin_comment
comment|/* AXI master ID (unique per master). */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_MPORT_ID_SHIFT
value|4
end_define

begin_comment
comment|/* EROM Slave Port MMIO Region Descriptor */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_BASE_MASK
value|0xFFFFF000
end_define

begin_comment
comment|/* region base address */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_BASE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_64BIT_MASK
value|0x00000008
end_define

begin_comment
comment|/* base address spans two 32-bit entries */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_64BIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_PORT_MASK
value|0x00000F00
end_define

begin_comment
comment|/* region's associated port */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_PORT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_MASK
value|0x000000C0
end_define

begin_comment
comment|/* region type */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_DEVICE
value|0
end_define

begin_comment
comment|/* region maps to a device */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_BRIDGE
value|1
end_define

begin_comment
comment|/* region maps to a bridge (e.g. AXI2APB) */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_SWRAP
value|2
end_define

begin_comment
comment|/* region maps to a slave port's DMP agent/wrapper */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_TYPE_MWRAP
value|3
end_define

begin_comment
comment|/* region maps to a master port's DMP agent/wrapper */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_MASK
value|0x00000030
end_define

begin_comment
comment|/* region size encoding */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_4K
value|0
end_define

begin_comment
comment|/* 4K region */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_8K
value|1
end_define

begin_comment
comment|/* 8K region */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_16K
value|2
end_define

begin_comment
comment|/* 16K region */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_OTHER
value|3
end_define

begin_comment
comment|/* defined by an additional size descriptor entry. */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_REGION_SIZE_BASE
value|0x1000
end_define

begin_comment
comment|/* Region Size Descriptor */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_RSIZE_VAL_MASK
value|0xFFFFF000
end_define

begin_comment
comment|/* region size */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_RSIZE_VAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BCMA_EROM_RSIZE_64BIT_MASK
value|0x00000008
end_define

begin_comment
comment|/* size spans two 32-bit entries */
end_comment

begin_define
define|#
directive|define
name|BCMA_EROM_RSIZE_64BIT_SHIFT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCMA_BCMA_EROM_REG_H_ */
end_comment

end_unit

