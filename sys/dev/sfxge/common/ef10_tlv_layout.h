begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012-2015 Solarflare Communications Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * 1. Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright notice,  *    this list of conditions and the following disclaimer in the documentation  *    and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * The views and conclusions contained in the software and documentation are  * those of the authors and should not be interpreted as representing official  * policies, either expressed or implied, of the FreeBSD Project.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* These structures define the layouts for the TLV items stored in static and  * dynamic configuration partitions in NVRAM for EF10 (Huntington etc.).  *  * They contain the same sort of information that was kept in the  * siena_mc_static_config_hdr_t and siena_mc_dynamic_config_hdr_t structures  * (defined in<ci/mgmt/mc_flash_layout.h> and<ci/mgmt/mc_dynamic_cfg.h>) for  * Siena.  *  * These are used directly by the MC and should also be usable directly on host  * systems which are little-endian and do not do strange things with structure  * padding.  (Big-endian host systems will require some byte-swapping.)  *  *                                    -----  *  * Please refer to SF-108797-SW for a general overview of the TLV partition  * format.  *  *                                    -----  *  * The current tag IDs have a general structure: with the exception of the  * special values defined in the document, they are of the form 0xLTTTNNNN,  * where:  *  *   -  L is a location, indicating where this tag is expected to be found:  *        0: static configuration  *        1: dynamic configuration  *        2: firmware internal use  *        3: license partition  *  *   -  TTT is a type, which is just a unique value.  The same type value  *      might appear in both locations, indicating a relationship between  *      the items (e.g. static and dynamic VPD below).  *  *   -  NNNN is an index of some form.  Some item types are per-port, some  *      are per-PF, some are per-partition-type.  *  *                                    -----  *  * As with the previous Siena structures, each structure here is laid out  * carefully: values are aligned to their natural boundary, with explicit  * padding fields added where necessary.  (No, technically this does not  * absolutely guarantee portability.  But, in practice, compilers are generally  * sensible enough not to introduce completely pointless padding, and it works  * well enough.)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CI_MGMT_TLV_LAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|CI_MGMT_TLV_LAYOUT_H
end_define

begin_comment
comment|/* ----------------------------------------------------------------------------  *  General structure (defined by SF-108797-SW)  * ----------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/* The "end" tag.  *  * (Note that this is *not* followed by length or value fields: anything after  * the tag itself is irrelevant.)  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_END
value|(0xEEEEEEEE)
end_define

begin_comment
comment|/* Other special reserved tag values.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_SKIP
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|TLV_TAG_INVALID
value|(0xFFFFFFFF)
end_define

begin_comment
comment|/* TLV partition header.  *  * In a TLV partition, this must be the first item in the sequence, at offset  * 0.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PARTITION_HEADER
value|(0xEF10DA7A)
end_define

begin_struct
struct|struct
name|tlv_partition_header
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|type_id
decl_stmt|;
comment|/* 0 indicates the default segment (always located at offset 0), while other values  * are for RFID-selectable presets that should immediately follow the default segment.  * The default segment may also have preset> 0, which means that it is a preset  * selected through an RFID command and copied by FW to the location at offset 0. */
name|uint16_t
name|preset
decl_stmt|;
name|uint32_t
name|generation
decl_stmt|;
name|uint32_t
name|total_length
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* TLV partition trailer.  *  * In a TLV partition, this must be the last item in the sequence, immediately  * preceding the TLV_TAG_END word.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PARTITION_TRAILER
value|(0xEF101A57)
end_define

begin_struct
struct|struct
name|tlv_partition_trailer
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|generation
decl_stmt|;
name|uint32_t
name|checksum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Appendable TLV partition header.  *  * In an appendable TLV partition, this must be the first item in the sequence,  * at offset 0.  (Note that, unlike the configuration partitions, there is no  * trailer before the TLV_TAG_END word.)  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_APPENDABLE_PARTITION_HEADER
value|(0xEF10ADA7)
end_define

begin_struct
struct|struct
name|tlv_appendable_partition_header
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|type_id
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ----------------------------------------------------------------------------  *  Configuration items  * ----------------------------------------------------------------------------  */
end_comment

begin_comment
comment|/* NIC global capabilities.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_CAPABILITIES
value|(0x00010000)
end_define

begin_struct
struct|struct
name|tlv_global_capabilities
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Siena-style per-port MAC address allocation.  *  * There are<count> addresses, starting at<base_address> and incrementing  * by adding<stride> to the low-order byte(s).  *  * (See also TLV_TAG_GLOBAL_MAC for an alternative, specifying a global pool  * of contiguous MAC addresses for the firmware to allocate as it sees fit.)  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PORT_MAC
parameter_list|(
name|port
parameter_list|)
value|(0x00020000 + (port))
end_define

begin_struct
struct|struct
name|tlv_port_mac
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|base_address
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
name|uint16_t
name|count
decl_stmt|;
name|uint16_t
name|stride
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Static VPD.  *  * This is the portion of VPD which is set at manufacturing time and not  * expected to change.  It is formatted as a standard PCI VPD block. There are  * global and per-pf TLVs for this, the global TLV is new for Medford and is  * used in preference to the per-pf TLV.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PF_STATIC_VPD
parameter_list|(
name|pf
parameter_list|)
value|(0x00030000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_pf_static_vpd
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|bytes
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_STATIC_VPD
value|(0x001f0000)
end_define

begin_struct
struct|struct
name|tlv_global_static_vpd
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|bytes
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Dynamic VPD.  *  * This is the portion of VPD which may be changed (e.g. by firmware updates).  * It is formatted as a standard PCI VPD block. There are global and per-pf TLVs  * for this, the global TLV is new for Medford and is used in preference to the  * per-pf TLV.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PF_DYNAMIC_VPD
parameter_list|(
name|pf
parameter_list|)
value|(0x10030000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_pf_dynamic_vpd
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|bytes
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_DYNAMIC_VPD
value|(0x10200000)
end_define

begin_struct
struct|struct
name|tlv_global_dynamic_vpd
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|bytes
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* "DBI" PCI config space changes.  *  * This is a set of edits made to the default PCI config space values before  * the device is allowed to enumerate. There are global and per-pf TLVs for  * this, the global TLV is new for Medford and is used in preference to the  * per-pf TLV.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PF_DBI
parameter_list|(
name|pf
parameter_list|)
value|(0x00040000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_pf_dbi
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|addr
decl_stmt|;
name|uint16_t
name|byte_enables
decl_stmt|;
name|uint32_t
name|value
decl_stmt|;
block|}
name|items
index|[]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_DBI
value|(0x00210000)
end_define

begin_struct
struct|struct
name|tlv_global_dbi
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
struct|struct
block|{
name|uint16_t
name|addr
decl_stmt|;
name|uint16_t
name|byte_enables
decl_stmt|;
name|uint32_t
name|value
decl_stmt|;
block|}
name|items
index|[]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* Partition subtype codes.  *  * A subtype may optionally be stored for each type of partition present in  * the NVRAM.  For example, this may be used to allow a generic firmware update  * utility to select a specific variant of firmware for a specific variant of  * board.  *  * The description[] field is an optional string which is returned in the  * MC_CMD_NVRAM_METADATA response if present.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PARTITION_SUBTYPE
parameter_list|(
name|type
parameter_list|)
value|(0x00050000 + (type))
end_define

begin_struct
struct|struct
name|tlv_partition_subtype
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|subtype
decl_stmt|;
name|uint8_t
name|description
index|[]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Partition version codes.  *  * A version may optionally be stored for each type of partition present in  * the NVRAM.  This provides a standard way of tracking the currently stored  * version of each of the various component images.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PARTITION_VERSION
parameter_list|(
name|type
parameter_list|)
value|(0x10060000 + (type))
end_define

begin_struct
struct|struct
name|tlv_partition_version
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|version_w
decl_stmt|;
name|uint16_t
name|version_x
decl_stmt|;
name|uint16_t
name|version_y
decl_stmt|;
name|uint16_t
name|version_z
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global PCIe configuration */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_PCIE_CONFIG
value|(0x10070000)
end_define

begin_struct
struct|struct
name|tlv_pcie_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|int16_t
name|max_pf_number
decl_stmt|;
comment|/**< Largest PF RID (lower PFs may be hidden) */
name|uint16_t
name|pf_aper
decl_stmt|;
comment|/**< BIU aperture for PF BAR2 */
name|uint16_t
name|vf_aper
decl_stmt|;
comment|/**< BIU aperture for VF BAR0 */
name|uint16_t
name|int_aper
decl_stmt|;
comment|/**< BIU aperture for PF BAR4 and VF BAR2 */
define|#
directive|define
name|TLV_MAX_PF_DEFAULT
value|(-1)
comment|/* Use FW default for largest PF RID  */
define|#
directive|define
name|TLV_APER_DEFAULT
value|(0xFFFF)
comment|/* Use FW default for a given aperture */
block|}
struct|;
end_struct

begin_comment
comment|/* Per-PF configuration. Note that not all these fields are necessarily useful  * as the apertures are constrained by the BIU settings (the one case we do  * use is to make BAR2 bigger than the BIU thinks to reserve space), but we can  * tidy things up later */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PF_PCIE_CONFIG
parameter_list|(
name|pf
parameter_list|)
value|(0x10080000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_per_pf_pcie_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|vfs_total
decl_stmt|;
name|uint8_t
name|port_allocation
decl_stmt|;
name|uint16_t
name|vectors_per_pf
decl_stmt|;
name|uint16_t
name|vectors_per_vf
decl_stmt|;
name|uint8_t
name|pf_bar0_aperture
decl_stmt|;
name|uint8_t
name|pf_bar2_aperture
decl_stmt|;
name|uint8_t
name|vf_bar0_aperture
decl_stmt|;
name|uint8_t
name|vf_base
decl_stmt|;
name|uint16_t
name|supp_pagesz
decl_stmt|;
name|uint16_t
name|msix_vec_base
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Development ONLY. This is a single TLV tag for all the gubbins  * that can be set through the MC command-line other than the PCIe  * settings. This is a temporary measure. */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_TMP_GUBBINS
value|(0x10090000)
end_define

begin_comment
comment|/* legacy symbol - do not use */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_TMP_GUBBINS_HUNT
value|TLV_TAG_TMP_GUBBINS
end_define

begin_struct
struct|struct
name|tlv_tmp_gubbins
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
comment|/* Consumed by dpcpu.c */
name|uint64_t
name|tx0_tags
decl_stmt|;
comment|/* Bitmap */
name|uint64_t
name|tx1_tags
decl_stmt|;
comment|/* Bitmap */
name|uint64_t
name|dl_tags
decl_stmt|;
comment|/* Bitmap */
name|uint32_t
name|flags
decl_stmt|;
define|#
directive|define
name|TLV_DPCPU_TX_STRIPE
value|(1)
comment|/* No longer used, has no effect */
define|#
directive|define
name|TLV_DPCPU_BIU_TAGS
value|(2)
comment|/* Use BIU tag manager */
define|#
directive|define
name|TLV_DPCPU_TX0_TAGS
value|(4)
comment|/* tx0_tags is valid */
define|#
directive|define
name|TLV_DPCPU_TX1_TAGS
value|(8)
comment|/* tx1_tags is valid */
define|#
directive|define
name|TLV_DPCPU_DL_TAGS
value|(16)
comment|/* dl_tags is valid */
comment|/* Consumed by features.c */
name|uint32_t
name|dut_features
decl_stmt|;
comment|/* All 1s -> leave alone */
name|int8_t
name|with_rmon
decl_stmt|;
comment|/* 0 -> off, 1 -> on, -1 -> leave alone */
comment|/* Consumed by clocks_hunt.c */
name|int8_t
name|clk_mode
decl_stmt|;
comment|/* 0 -> off, 1 -> on, -1 -> leave alone */
comment|/* No longer used, superseded by TLV_TAG_DESCRIPTOR_CACHE_CONFIG. */
name|int8_t
name|rx_dc_size
decl_stmt|;
comment|/* -1 -> leave alone */
name|int8_t
name|tx_dc_size
decl_stmt|;
name|int16_t
name|num_q_allocs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global port configuration  *  * This is now deprecated in favour of a platform-provided default  * and dynamic config override via tlv_global_port_options.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_PORT_CONFIG
value|(0x000a0000)
end_define

begin_struct
struct|struct
name|tlv_global_port_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|ports_per_core
decl_stmt|;
name|uint32_t
name|max_port_speed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Firmware options.  *  * This is intended for user-configurable selection of optional firmware  * features and variants.  *  * Initially, this consists only of the satellite CPU firmware variant  * selection, but this tag could be extended in the future (using the  * tag length to determine whether additional fields are present).  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_FIRMWARE_OPTIONS
value|(0x100b0000)
end_define

begin_struct
struct|struct
name|tlv_firmware_options
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|firmware_variant
decl_stmt|;
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_DRIVER_SELECTED
value|(0xffffffff)
comment|/* These are the values for overriding the driver's choice; the definitions  * are taken from MCDI so that they don't get out of step.  Include  *<ci/mgmt/mc_driver_pcol.h> or the equivalent from your driver's tree if  * you need to use these constants.  */
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_FULL_FEATURED
value|MC_CMD_FW_FULL_FEATURED
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_LOW_LATENCY
value|MC_CMD_FW_LOW_LATENCY
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_PACKED_STREAM
value|MC_CMD_FW_PACKED_STREAM
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_HIGH_TX_RATE
value|MC_CMD_FW_HIGH_TX_RATE
define|#
directive|define
name|TLV_FIRMWARE_VARIANT_PACKED_STREAM_HASH_MODE_1
define|\
value|MC_CMD_FW_PACKED_STREAM_HASH_MODE_1
block|}
struct|;
end_struct

begin_comment
comment|/* Voltage settings  *  * Intended for boards with A0 silicon where the core voltage may  * need tweaking. Most likely set once when the pass voltage is  * determined. */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_0V9_SETTINGS
value|(0x000c0000)
end_define

begin_struct
struct|struct
name|tlv_0v9_settings
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
comment|/* Boards with high 0v9 settings may need active cooling */
define|#
directive|define
name|TLV_TAG_0V9_REQUIRES_FAN
value|(1)
name|uint16_t
name|target_voltage
decl_stmt|;
comment|/* In millivolts */
comment|/* Since the limits are meant to be centred to the target (and must at least    * contain it) they need setting as well. */
name|uint16_t
name|warn_low
decl_stmt|;
comment|/* In millivolts */
name|uint16_t
name|warn_high
decl_stmt|;
comment|/* In millivolts */
name|uint16_t
name|panic_low
decl_stmt|;
comment|/* In millivolts */
name|uint16_t
name|panic_high
decl_stmt|;
comment|/* In millivolts */
block|}
struct|;
end_struct

begin_comment
comment|/* Clock configuration */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_CLOCK_CONFIG
value|(0x000d0000)
end_define

begin_comment
comment|/* legacy symbol - do not use */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_CLOCK_CONFIG_HUNT
value|TLV_TAG_CLOCK_CONFIG
end_define

begin_struct
struct|struct
name|tlv_clock_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|clk_sys
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_dpcpu
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_icore
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_pcs
decl_stmt|;
comment|/* MHz */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_CLOCK_CONFIG_MEDFORD
value|(0x00100000)
end_define

begin_struct
struct|struct
name|tlv_clock_config_medford
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|clk_sys
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_mc
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_rmon
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_vswitch
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_dpcpu
decl_stmt|;
comment|/* MHz */
name|uint16_t
name|clk_pcs
decl_stmt|;
comment|/* MHz */
block|}
struct|;
end_struct

begin_comment
comment|/* EF10-style global pool of MAC addresses.  *  * There are<count> addresses, starting at<base_address>, which are  * contiguous.  Firmware is responsible for allocating addresses from this  * pool to ports / PFs as appropriate.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_MAC
value|(0x000e0000)
end_define

begin_struct
struct|struct
name|tlv_global_mac
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|base_address
index|[
literal|6
index|]
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|count
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_ATB_0V9_TARGET
value|(0x000f0000)
end_define

begin_comment
comment|/* legacy symbol - do not use */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_ATB_0V9_TARGET_HUNT
value|TLV_TAG_ATB_0V9_TARGET
end_define

begin_comment
comment|/* The target value for the 0v9 power rail measured on-chip at the  * analogue test bus */
end_comment

begin_struct
struct|struct
name|tlv_0v9_atb_target
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|millivolts
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Global PCIe configuration, second revision. This represents the visible PFs  * by a bitmap rather than having the number of the highest visible one. As such  * it can (for a 16-PF chip) represent a superset of what TLV_TAG_GLOBAL_PCIE_CONFIG  * can and it should be used in place of that tag in future (but compatibility with  * the old tag will be left in the firmware indefinitely).  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_PCIE_CONFIG_R2
value|(0x10100000)
end_define

begin_struct
struct|struct
name|tlv_pcie_config_r2
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|visible_pfs
decl_stmt|;
comment|/**< Bitmap of visible PFs */
name|uint16_t
name|pf_aper
decl_stmt|;
comment|/**< BIU aperture for PF BAR2 */
name|uint16_t
name|vf_aper
decl_stmt|;
comment|/**< BIU aperture for VF BAR0 */
name|uint16_t
name|int_aper
decl_stmt|;
comment|/**< BIU aperture for PF BAR4 and VF BAR2 */
block|}
struct|;
end_struct

begin_comment
comment|/* Dynamic port mode.  *  * Allows selecting alternate port configuration for platforms that support it  * (e.g. 1x40G vs 2x10G on Milano, 1x40G vs 4x10G on Medford). This affects the  * number of externally visible ports (and, hence, PF to port mapping), so must  * be done at boot time.  *  * This tag supercedes tlv_global_port_config.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_GLOBAL_PORT_MODE
value|(0x10110000)
end_define

begin_struct
struct|struct
name|tlv_global_port_mode
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|port_mode
decl_stmt|;
define|#
directive|define
name|TLV_PORT_MODE_DEFAULT
value|(0xffffffff)
comment|/* Default for given platform */
define|#
directive|define
name|TLV_PORT_MODE_10G
value|(0)
comment|/* 10G, single SFP/10G-KR */
define|#
directive|define
name|TLV_PORT_MODE_40G
value|(1)
comment|/* 40G, single QSFP/40G-KR */
define|#
directive|define
name|TLV_PORT_MODE_10G_10G
value|(2)
comment|/* 2x10G, dual SFP/10G-KR or single QSFP */
define|#
directive|define
name|TLV_PORT_MODE_40G_40G
value|(3)
comment|/* 40G + 40G, dual QSFP/40G-KR (Greenport, Medford) */
define|#
directive|define
name|TLV_PORT_MODE_10G_10G_10G_10G
value|(4)
comment|/* 2x10G + 2x10G, quad SFP/10G-KR or dual QSFP (Greenport, Medford) */
define|#
directive|define
name|TLV_PORT_MODE_10G_10G_10G_10G_Q
value|(5)
comment|/* 4x10G, single QSFP, cage 0 (Medford) */
define|#
directive|define
name|TLV_PORT_MODE_40G_10G_10G
value|(6)
comment|/* 1x40G + 2x10G, dual QSFP (Greenport, Medford) */
define|#
directive|define
name|TLV_PORT_MODE_10G_10G_40G
value|(7)
comment|/* 2x10G + 1x40G, dual QSFP (Greenport, Medford) */
define|#
directive|define
name|TLV_PORT_MODE_10G_10G_10G_10G_Q2
value|(8)
comment|/* 4x10G, single QSFP, cage 1 (Medford) */
define|#
directive|define
name|TLV_PORT_MODE_MAX
value|TLV_PORT_MODE_10G_10G_10G_10G_Q2
block|}
struct|;
end_struct

begin_comment
comment|/* Type of the v-switch created implicitly by the firmware */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_VSWITCH_TYPE
parameter_list|(
name|port
parameter_list|)
value|(0x10120000 + (port))
end_define

begin_struct
struct|struct
name|tlv_vswitch_type
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|vswitch_type
decl_stmt|;
define|#
directive|define
name|TLV_VSWITCH_TYPE_DEFAULT
value|(0xffffffff)
comment|/* Firmware default; equivalent to no TLV present for a given port */
define|#
directive|define
name|TLV_VSWITCH_TYPE_NONE
value|(0)
define|#
directive|define
name|TLV_VSWITCH_TYPE_VLAN
value|(1)
define|#
directive|define
name|TLV_VSWITCH_TYPE_VEB
value|(2)
define|#
directive|define
name|TLV_VSWITCH_TYPE_VEPA
value|(3)
define|#
directive|define
name|TLV_VSWITCH_TYPE_MUX
value|(4)
define|#
directive|define
name|TLV_VSWITCH_TYPE_TEST
value|(5)
block|}
struct|;
end_struct

begin_comment
comment|/* A VLAN tag for the v-port created implicitly by the firmware */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_VPORT_VLAN_TAG
parameter_list|(
name|pf
parameter_list|)
value|(0x10130000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_vport_vlan_tag
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|vlan_tag
decl_stmt|;
define|#
directive|define
name|TLV_VPORT_NO_VLAN_TAG
value|(0xFFFFFFFF)
comment|/* Default in the absence of TLV for a given PF */
block|}
struct|;
end_struct

begin_comment
comment|/* Offset to be applied to the 0v9 setting, wherever it came from */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_ATB_0V9_OFFSET
value|(0x10140000)
end_define

begin_struct
struct|struct
name|tlv_0v9_atb_offset
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|int16_t
name|offset_millivolts
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A privilege mask given on reset to all non-admin PCIe functions (that is other than first-PF-per-port).  * The meaning of particular bits is defined in mcdi_ef10.yml under MC_CMD_PRIVILEGE_MASK, see also bug 44583.  * TLV_TAG_PRIVILEGE_MASK_ADD specifies bits that should be added (ORed) to firmware default while  * TLV_TAG_PRIVILEGE_MASK_REM specifies bits that should be removed (ANDed) from firmware default:  * Initial_privilege_mask = (firmware_default_mask | privilege_mask_add)& ~privilege_mask_rem */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PRIVILEGE_MASK
value|(0x10150000)
end_define

begin_comment
comment|/* legacy symbol - do not use */
end_comment

begin_struct
struct|struct
name|tlv_privilege_mask
block|{
comment|/* legacy structure - do not use */
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|privilege_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_PRIVILEGE_MASK_ADD
value|(0x10150000)
end_define

begin_struct
struct|struct
name|tlv_privilege_mask_add
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|privilege_mask_add
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_PRIVILEGE_MASK_REM
value|(0x10160000)
end_define

begin_struct
struct|struct
name|tlv_privilege_mask_rem
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|privilege_mask_rem
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional privileges given to all PFs.  * This tag takes precedence over TLV_TAG_PRIVILEGE_MASK_REM. */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PRIVILEGE_MASK_ADD_ALL_PFS
value|(0x10190000)
end_define

begin_struct
struct|struct
name|tlv_privilege_mask_add_all_pfs
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|privilege_mask_add
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Additional privileges given to a selected PF.  * This tag takes precedence over TLV_TAG_PRIVILEGE_MASK_REM. */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PRIVILEGE_MASK_ADD_SINGLE_PF
parameter_list|(
name|pf
parameter_list|)
value|(0x101A0000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_privilege_mask_add_single_pf
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|privilege_mask_add
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Turning on/off the PFIOV mode.  * This tag only takes effect if TLV_TAG_VSWITCH_TYPE is missing or set to DEFAULT. */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_PFIOV
parameter_list|(
name|port
parameter_list|)
value|(0x10170000 + (port))
end_define

begin_struct
struct|struct
name|tlv_pfiov
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|pfiov
decl_stmt|;
define|#
directive|define
name|TLV_PFIOV_OFF
value|(0)
comment|/* Default */
define|#
directive|define
name|TLV_PFIOV_ON
value|(1)
block|}
struct|;
end_struct

begin_comment
comment|/* Multicast filter chaining mode selection.  *  * When enabled, multicast packets are delivered to all recipients of all  * matching multicast filters, with the exception that IP multicast filters  * will steal traffic from MAC multicast filters on a per-function basis.  * (New behaviour.)  *  * When disabled, multicast packets will always be delivered only to the  * recipients of the highest priority matching multicast filter.  * (Legacy behaviour.)  *  * The DEFAULT mode (which is the same as the tag not being present at all)  * is equivalent to ENABLED in production builds, and DISABLED in eftest  * builds.  *  * This option is intended to provide run-time control over this feature  * while it is being stabilised and may be withdrawn at some point in the  * future; the new behaviour is intended to become the standard behaviour.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_MCAST_FILTER_CHAINING
value|(0x10180000)
end_define

begin_struct
struct|struct
name|tlv_mcast_filter_chaining
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|mode
decl_stmt|;
define|#
directive|define
name|TLV_MCAST_FILTER_CHAINING_DEFAULT
value|(0xffffffff)
define|#
directive|define
name|TLV_MCAST_FILTER_CHAINING_DISABLED
value|(0)
define|#
directive|define
name|TLV_MCAST_FILTER_CHAINING_ENABLED
value|(1)
block|}
struct|;
end_struct

begin_comment
comment|/* Pacer rate limit per PF */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_RATE_LIMIT
parameter_list|(
name|pf
parameter_list|)
value|(0x101b0000 + (pf))
end_define

begin_struct
struct|struct
name|tlv_rate_limit
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|rate_mbps
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* OCSD Enable/Disable  *  * This setting allows OCSD to be disabled. This is a requirement for HP  * servers to support PCI passthrough for virtualization.  *  * The DEFAULT mode (which is the same as the tag not being present) is  * equivalent to ENABLED.  *  * This option is not used by the MCFW, and is entirely handled by the various  * drivers that support OCSD, by reading the setting before they attempt  * to enable OCSD.  *  * bit0: OCSD Disabled/Enabled  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_OCSD
value|(0x101C0000)
end_define

begin_struct
struct|struct
name|tlv_ocsd
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|mode
decl_stmt|;
define|#
directive|define
name|TLV_OCSD_DISABLED
value|0
define|#
directive|define
name|TLV_OCSD_ENABLED
value|1
comment|/* Default */
block|}
struct|;
end_struct

begin_comment
comment|/* Descriptor cache config.  *  * Sets the sizes of the TX and RX descriptor caches as a power of 2. It also  * sets the total number of VIs. When the number of VIs is reduced VIs are taken  * away from the highest numbered port first, so a vi_count of 1024 means 1024  * VIs on the first port and 0 on the second (on a Torino).  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_DESCRIPTOR_CACHE_CONFIG
value|(0x101d0000)
end_define

begin_struct
struct|struct
name|tlv_descriptor_cache_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|rx_desc_cache_size
decl_stmt|;
name|uint8_t
name|tx_desc_cache_size
decl_stmt|;
name|uint16_t
name|vi_count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_DESC_CACHE_DEFAULT
value|(0xff)
end_define

begin_define
define|#
directive|define
name|TLV_VI_COUNT_DEFAULT
value|(0xffff)
end_define

begin_comment
comment|/* RX event merging config (read batching).  *  * Sets the global maximum number of events for the merging bins, and the  * global timeout configuration for the bins.  */
end_comment

begin_define
define|#
directive|define
name|TLV_TAG_RX_EVENT_MERGING_CONFIG
value|(0x101e0000)
end_define

begin_struct
struct|struct
name|tlv_rx_event_merging_config
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|max_events
decl_stmt|;
define|#
directive|define
name|TLV_RX_EVENT_MERGING_CONFIG_MAX_EVENTS_MAX
value|((1<< 4) - 1)
name|uint32_t
name|timeout_ns
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_RX_EVENT_MERGING_MAX_EVENTS_DEFAULT
value|7
end_define

begin_define
define|#
directive|define
name|TLV_RX_EVENT_MERGING_TIMEOUT_NS_DEFAULT
value|8740
end_define

begin_define
define|#
directive|define
name|TLV_TAG_PCIE_LINK_SETTINGS
value|(0x101f0000)
end_define

begin_struct
struct|struct
name|tlv_pcie_link_settings
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint16_t
name|gen
decl_stmt|;
comment|/* Target PCIe generation: 1, 2, 3 */
name|uint16_t
name|width
decl_stmt|;
comment|/* Number of lanes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TLV_TAG_LICENSE
value|(0x30800000)
end_define

begin_typedef
typedef|typedef
struct|struct
name|tlv_license
block|{
name|uint32_t
name|tag
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint8_t
name|data
index|[]
decl_stmt|;
block|}
name|tlv_license_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CI_MGMT_TLV_LAYOUT_H */
end_comment

end_unit

