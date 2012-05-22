begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Â© 2006 Intel Corporation  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  * Authors:  *    Eric Anholt<eric@anholt.net>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I830_BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_I830_BIOS_H_
end_define

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_struct
struct|struct
name|vbt_header
block|{
name|u8
name|signature
index|[
literal|20
index|]
decl_stmt|;
comment|/**< Always starts with 'VBT$' */
name|u16
name|version
decl_stmt|;
comment|/**< decimal */
name|u16
name|header_size
decl_stmt|;
comment|/**< in bytes */
name|u16
name|vbt_size
decl_stmt|;
comment|/**< in bytes */
name|u8
name|vbt_checksum
decl_stmt|;
name|u8
name|reserved0
decl_stmt|;
name|u32
name|bdb_offset
decl_stmt|;
comment|/**< from beginning of VBT */
name|u32
name|aim_offset
index|[
literal|4
index|]
decl_stmt|;
comment|/**< from beginning of VBT */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_header
block|{
name|u8
name|signature
index|[
literal|16
index|]
decl_stmt|;
comment|/**< Always 'BIOS_DATA_BLOCK' */
name|u16
name|version
decl_stmt|;
comment|/**< decimal */
name|u16
name|header_size
decl_stmt|;
comment|/**< in bytes */
name|u16
name|bdb_size
decl_stmt|;
comment|/**< in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/* strictly speaking, this is a "skip" block, but it has interesting info */
end_comment

begin_struct
struct|struct
name|vbios_data
block|{
name|u8
name|type
decl_stmt|;
comment|/* 0 == desktop, 1 == mobile */
name|u8
name|relstage
decl_stmt|;
name|u8
name|chipset
decl_stmt|;
name|u8
name|lvds_present
range|:
literal|1
decl_stmt|;
name|u8
name|tv_present
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd2
range|:
literal|6
decl_stmt|;
comment|/* finish byte */
name|u8
name|rsvd3
index|[
literal|4
index|]
decl_stmt|;
name|u8
name|signon
index|[
literal|155
index|]
decl_stmt|;
name|u8
name|copyright
index|[
literal|61
index|]
decl_stmt|;
name|u16
name|code_segment
decl_stmt|;
name|u8
name|dos_boot_mode
decl_stmt|;
name|u8
name|bandwidth_percent
decl_stmt|;
name|u8
name|rsvd4
decl_stmt|;
comment|/* popup memory size */
name|u8
name|resize_pci_bios
decl_stmt|;
name|u8
name|rsvd5
decl_stmt|;
comment|/* is crt already on ddc2 */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * There are several types of BIOS data blocks (BDBs), each block has  * an ID and size in the first 3 bytes (ID in first, size in next 2).  * Known types are listed below.  */
end_comment

begin_define
define|#
directive|define
name|BDB_GENERAL_FEATURES
value|1
end_define

begin_define
define|#
directive|define
name|BDB_GENERAL_DEFINITIONS
value|2
end_define

begin_define
define|#
directive|define
name|BDB_OLD_TOGGLE_LIST
value|3
end_define

begin_define
define|#
directive|define
name|BDB_MODE_SUPPORT_LIST
value|4
end_define

begin_define
define|#
directive|define
name|BDB_GENERIC_MODE_TABLE
value|5
end_define

begin_define
define|#
directive|define
name|BDB_EXT_MMIO_REGS
value|6
end_define

begin_define
define|#
directive|define
name|BDB_SWF_IO
value|7
end_define

begin_define
define|#
directive|define
name|BDB_SWF_MMIO
value|8
end_define

begin_define
define|#
directive|define
name|BDB_DOT_CLOCK_TABLE
value|9
end_define

begin_define
define|#
directive|define
name|BDB_MODE_REMOVAL_TABLE
value|10
end_define

begin_define
define|#
directive|define
name|BDB_CHILD_DEVICE_TABLE
value|11
end_define

begin_define
define|#
directive|define
name|BDB_DRIVER_FEATURES
value|12
end_define

begin_define
define|#
directive|define
name|BDB_DRIVER_PERSISTENCE
value|13
end_define

begin_define
define|#
directive|define
name|BDB_EXT_TABLE_PTRS
value|14
end_define

begin_define
define|#
directive|define
name|BDB_DOT_CLOCK_OVERRIDE
value|15
end_define

begin_define
define|#
directive|define
name|BDB_DISPLAY_SELECT
value|16
end_define

begin_comment
comment|/* 17 rsvd */
end_comment

begin_define
define|#
directive|define
name|BDB_DRIVER_ROTATION
value|18
end_define

begin_define
define|#
directive|define
name|BDB_DISPLAY_REMOVE
value|19
end_define

begin_define
define|#
directive|define
name|BDB_OEM_CUSTOM
value|20
end_define

begin_define
define|#
directive|define
name|BDB_EFP_LIST
value|21
end_define

begin_comment
comment|/* workarounds for VGA hsync/vsync */
end_comment

begin_define
define|#
directive|define
name|BDB_SDVO_LVDS_OPTIONS
value|22
end_define

begin_define
define|#
directive|define
name|BDB_SDVO_PANEL_DTDS
value|23
end_define

begin_define
define|#
directive|define
name|BDB_SDVO_LVDS_PNP_IDS
value|24
end_define

begin_define
define|#
directive|define
name|BDB_SDVO_LVDS_POWER_SEQ
value|25
end_define

begin_define
define|#
directive|define
name|BDB_TV_OPTIONS
value|26
end_define

begin_define
define|#
directive|define
name|BDB_EDP
value|27
end_define

begin_define
define|#
directive|define
name|BDB_LVDS_OPTIONS
value|40
end_define

begin_define
define|#
directive|define
name|BDB_LVDS_LFP_DATA_PTRS
value|41
end_define

begin_define
define|#
directive|define
name|BDB_LVDS_LFP_DATA
value|42
end_define

begin_define
define|#
directive|define
name|BDB_LVDS_BACKLIGHT
value|43
end_define

begin_define
define|#
directive|define
name|BDB_LVDS_POWER
value|44
end_define

begin_define
define|#
directive|define
name|BDB_SKIP
value|254
end_define

begin_comment
comment|/* VBIOS private block, ignore */
end_comment

begin_struct
struct|struct
name|bdb_general_features
block|{
comment|/* bits 1 */
name|u8
name|panel_fitting
range|:
literal|2
decl_stmt|;
name|u8
name|flexaim
range|:
literal|1
decl_stmt|;
name|u8
name|msg_enable
range|:
literal|1
decl_stmt|;
name|u8
name|clear_screen
range|:
literal|3
decl_stmt|;
name|u8
name|color_flip
range|:
literal|1
decl_stmt|;
comment|/* bits 2 */
name|u8
name|download_ext_vbt
range|:
literal|1
decl_stmt|;
name|u8
name|enable_ssc
range|:
literal|1
decl_stmt|;
name|u8
name|ssc_freq
range|:
literal|1
decl_stmt|;
name|u8
name|enable_lfp_on_override
range|:
literal|1
decl_stmt|;
name|u8
name|disable_ssc_ddt
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd7
range|:
literal|1
decl_stmt|;
name|u8
name|display_clock_mode
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd8
range|:
literal|1
decl_stmt|;
comment|/* finish byte */
comment|/* bits 3 */
name|u8
name|disable_smooth_vision
range|:
literal|1
decl_stmt|;
name|u8
name|single_dvi
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd9
range|:
literal|6
decl_stmt|;
comment|/* finish byte */
comment|/* bits 4 */
name|u8
name|legacy_monitor_detect
decl_stmt|;
comment|/* bits 5 */
name|u8
name|int_crt_support
range|:
literal|1
decl_stmt|;
name|u8
name|int_tv_support
range|:
literal|1
decl_stmt|;
name|u8
name|int_efp_support
range|:
literal|1
decl_stmt|;
name|u8
name|dp_ssc_enb
range|:
literal|1
decl_stmt|;
comment|/* PCH attached eDP supports SSC */
name|u8
name|dp_ssc_freq
range|:
literal|1
decl_stmt|;
comment|/* SSC freq for PCH attached eDP */
name|u8
name|rsvd11
range|:
literal|3
decl_stmt|;
comment|/* finish byte */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* pre-915 */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_DVI_LVDS
value|0x03
end_define

begin_comment
comment|/* "DVI/LVDS DDC GPIO pins" */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_ADD_I2C
value|0x05
end_define

begin_comment
comment|/* "ADDCARD I2C GPIO pins" */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_ADD_DDC
value|0x04
end_define

begin_comment
comment|/* "ADDCARD DDC GPIO pins" */
end_comment

begin_define
define|#
directive|define
name|GPIO_PIN_ADD_DDC_I2C
value|0x06
end_define

begin_comment
comment|/* "ADDCARD DDC/I2C GPIO pins" */
end_comment

begin_comment
comment|/* Pre 915 */
end_comment

begin_define
define|#
directive|define
name|DEVICE_TYPE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_CRT
value|0x01
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV
value|0x09
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP
value|0x12
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP
value|0x22
end_define

begin_comment
comment|/* On 915+ */
end_comment

begin_define
define|#
directive|define
name|DEVICE_TYPE_CRT_DPMS
value|0x6001
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_CRT_DPMS_HOTPLUG
value|0x4001
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_COMPOSITE
value|0x0209
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_MACROVISION
value|0x0289
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_RF_COMPOSITE
value|0x020c
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_SVIDEO_COMPOSITE
value|0x0609
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_SCART
value|0x0209
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_TV_CODEC_HOTPLUG_PWR
value|0x6009
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP_HOTPLUG_PWR
value|0x6012
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP_DVI_HOTPLUG_PWR
value|0x6052
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP_DVI_I
value|0x6053
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP_DVI_D_DUAL
value|0x6152
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_EFP_DVI_D_HDCP
value|0x60d2
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_OPENLDI_HOTPLUG_PWR
value|0x6062
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_OPENLDI_DUALPIX
value|0x6162
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP_PANELLINK
value|0x5012
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP_CMOS_PWR
value|0x5042
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP_LVDS_PWR
value|0x5062
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP_LVDS_DUAL
value|0x5162
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_LFP_LVDS_DUAL_HDCP
value|0x51e2
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_12BIT_DVOB
value|0x01
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_12BIT_DVOC
value|0x02
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_24BIT_DVOBC
value|0x09
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_24BIT_DVOCB
value|0x0a
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_DUAL_DVOB
value|0x11
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_DUAL_DVOC
value|0x12
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_DUAL_DVOBC
value|0x13
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_DUAL_LINK_DVOBC
value|0x19
end_define

begin_define
define|#
directive|define
name|DEVICE_CFG_DUAL_LINK_DVOCB
value|0x1a
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOB
value|0x01
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOC
value|0x02
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOBC
value|0x03
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOBB
value|0x05
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOCC
value|0x06
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOB_MASTER
value|0x0d
end_define

begin_define
define|#
directive|define
name|DEVICE_WIRE_DVOC_MASTER
value|0x0e
end_define

begin_define
define|#
directive|define
name|DEVICE_PORT_DVOA
value|0x00
end_define

begin_comment
comment|/* none on 845+ */
end_comment

begin_define
define|#
directive|define
name|DEVICE_PORT_DVOB
value|0x01
end_define

begin_define
define|#
directive|define
name|DEVICE_PORT_DVOC
value|0x02
end_define

begin_struct
struct|struct
name|child_device_config
block|{
name|u16
name|handle
decl_stmt|;
name|u16
name|device_type
decl_stmt|;
name|u8
name|device_id
index|[
literal|10
index|]
decl_stmt|;
comment|/* ascii string */
name|u16
name|addin_offset
decl_stmt|;
name|u8
name|dvo_port
decl_stmt|;
comment|/* See Device_PORT_* above */
name|u8
name|i2c_pin
decl_stmt|;
name|u8
name|slave_addr
decl_stmt|;
name|u8
name|ddc_pin
decl_stmt|;
name|u16
name|edid_ptr
decl_stmt|;
name|u8
name|dvo_cfg
decl_stmt|;
comment|/* See DEVICE_CFG_* above */
name|u8
name|dvo2_port
decl_stmt|;
name|u8
name|i2c2_pin
decl_stmt|;
name|u8
name|slave2_addr
decl_stmt|;
name|u8
name|ddc2_pin
decl_stmt|;
name|u8
name|capabilities
decl_stmt|;
name|u8
name|dvo_wiring
decl_stmt|;
comment|/* See DEVICE_WIRE_* above */
name|u8
name|dvo2_wiring
decl_stmt|;
name|u16
name|extended_type
decl_stmt|;
name|u8
name|dvo_function
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_general_definitions
block|{
comment|/* DDC GPIO */
name|u8
name|crt_ddc_gmbus_pin
decl_stmt|;
comment|/* DPMS bits */
name|u8
name|dpms_acpi
range|:
literal|1
decl_stmt|;
name|u8
name|skip_boot_crt_detect
range|:
literal|1
decl_stmt|;
name|u8
name|dpms_aim
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd1
range|:
literal|5
decl_stmt|;
comment|/* finish byte */
comment|/* boot device bits */
name|u8
name|boot_display
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|child_dev_size
decl_stmt|;
comment|/* 	 * Device info: 	 * If TV is present, it'll be at devices[0]. 	 * LVDS will be next, either devices[0] or [1], if present. 	 * On some platforms the number of device is 6. But could be as few as 	 * 4 if both TV and LVDS are missing. 	 * And the device num is related with the size of general definition 	 * block. It is obtained by using the following formula: 	 * number = (block_size - sizeof(bdb_general_definitions))/ 	 *	     sizeof(child_device_config); 	 */
name|struct
name|child_device_config
name|devices
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_lvds_options
block|{
name|u8
name|panel_type
decl_stmt|;
name|u8
name|rsvd1
decl_stmt|;
comment|/* LVDS capabilities, stored in a dword */
name|u8
name|pfit_mode
range|:
literal|2
decl_stmt|;
name|u8
name|pfit_text_mode_enhanced
range|:
literal|1
decl_stmt|;
name|u8
name|pfit_gfx_mode_enhanced
range|:
literal|1
decl_stmt|;
name|u8
name|pfit_ratio_auto
range|:
literal|1
decl_stmt|;
name|u8
name|pixel_dither
range|:
literal|1
decl_stmt|;
name|u8
name|lvds_edid
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd2
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd4
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* LFP pointer table contains entries to the struct below */
end_comment

begin_struct
struct|struct
name|bdb_lvds_lfp_data_ptr
block|{
name|u16
name|fp_timing_offset
decl_stmt|;
comment|/* offsets are from start of bdb */
name|u8
name|fp_table_size
decl_stmt|;
name|u16
name|dvo_timing_offset
decl_stmt|;
name|u8
name|dvo_table_size
decl_stmt|;
name|u16
name|panel_pnp_id_offset
decl_stmt|;
name|u8
name|pnp_table_size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_lvds_lfp_data_ptrs
block|{
name|u8
name|lvds_entries
decl_stmt|;
comment|/* followed by one or more lvds_data_ptr structs */
name|struct
name|bdb_lvds_lfp_data_ptr
name|ptr
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/* LFP data has 3 blocks per entry */
end_comment

begin_struct
struct|struct
name|lvds_fp_timing
block|{
name|u16
name|x_res
decl_stmt|;
name|u16
name|y_res
decl_stmt|;
name|u32
name|lvds_reg
decl_stmt|;
name|u32
name|lvds_reg_val
decl_stmt|;
name|u32
name|pp_on_reg
decl_stmt|;
name|u32
name|pp_on_reg_val
decl_stmt|;
name|u32
name|pp_off_reg
decl_stmt|;
name|u32
name|pp_off_reg_val
decl_stmt|;
name|u32
name|pp_cycle_reg
decl_stmt|;
name|u32
name|pp_cycle_reg_val
decl_stmt|;
name|u32
name|pfit_reg
decl_stmt|;
name|u32
name|pfit_reg_val
decl_stmt|;
name|u16
name|terminator
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|lvds_dvo_timing
block|{
name|u16
name|clock
decl_stmt|;
comment|/**< In 10khz */
name|u8
name|hactive_lo
decl_stmt|;
name|u8
name|hblank_lo
decl_stmt|;
name|u8
name|hblank_hi
range|:
literal|4
decl_stmt|;
name|u8
name|hactive_hi
range|:
literal|4
decl_stmt|;
name|u8
name|vactive_lo
decl_stmt|;
name|u8
name|vblank_lo
decl_stmt|;
name|u8
name|vblank_hi
range|:
literal|4
decl_stmt|;
name|u8
name|vactive_hi
range|:
literal|4
decl_stmt|;
name|u8
name|hsync_off_lo
decl_stmt|;
name|u8
name|hsync_pulse_width
decl_stmt|;
name|u8
name|vsync_pulse_width
range|:
literal|4
decl_stmt|;
name|u8
name|vsync_off
range|:
literal|4
decl_stmt|;
name|u8
name|rsvd0
range|:
literal|6
decl_stmt|;
name|u8
name|hsync_off_hi
range|:
literal|2
decl_stmt|;
name|u8
name|h_image
decl_stmt|;
name|u8
name|v_image
decl_stmt|;
name|u8
name|max_hv
decl_stmt|;
name|u8
name|h_border
decl_stmt|;
name|u8
name|v_border
decl_stmt|;
name|u8
name|rsvd1
range|:
literal|3
decl_stmt|;
name|u8
name|digital
range|:
literal|2
decl_stmt|;
name|u8
name|vsync_positive
range|:
literal|1
decl_stmt|;
name|u8
name|hsync_positive
range|:
literal|1
decl_stmt|;
name|u8
name|rsvd2
range|:
literal|1
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|lvds_pnp_id
block|{
name|u16
name|mfg_name
decl_stmt|;
name|u16
name|product_code
decl_stmt|;
name|u32
name|serial
decl_stmt|;
name|u8
name|mfg_week
decl_stmt|;
name|u8
name|mfg_year
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_lvds_lfp_data_entry
block|{
name|struct
name|lvds_fp_timing
name|fp_timing
decl_stmt|;
name|struct
name|lvds_dvo_timing
name|dvo_timing
decl_stmt|;
name|struct
name|lvds_pnp_id
name|pnp_id
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_lvds_lfp_data
block|{
name|struct
name|bdb_lvds_lfp_data_entry
name|data
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aimdb_header
block|{
name|char
name|signature
index|[
literal|16
index|]
decl_stmt|;
name|char
name|oem_device
index|[
literal|20
index|]
decl_stmt|;
name|u16
name|aimdb_version
decl_stmt|;
name|u16
name|aimdb_header_size
decl_stmt|;
name|u16
name|aimdb_size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|aimdb_block
block|{
name|u8
name|aimdb_id
decl_stmt|;
name|u16
name|aimdb_size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|vch_panel_data
block|{
name|u16
name|fp_timing_offset
decl_stmt|;
name|u8
name|fp_timing_size
decl_stmt|;
name|u16
name|dvo_timing_offset
decl_stmt|;
name|u8
name|dvo_timing_size
decl_stmt|;
name|u16
name|text_fitting_offset
decl_stmt|;
name|u8
name|text_fitting_size
decl_stmt|;
name|u16
name|graphics_fitting_offset
decl_stmt|;
name|u8
name|graphics_fitting_size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|vch_bdb_22
block|{
name|struct
name|aimdb_block
name|aimdb_block
decl_stmt|;
name|struct
name|vch_panel_data
name|panels
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_sdvo_lvds_options
block|{
name|u8
name|panel_backlight
decl_stmt|;
name|u8
name|h40_set_panel_type
decl_stmt|;
name|u8
name|panel_type
decl_stmt|;
name|u8
name|ssc_clk_freq
decl_stmt|;
name|u16
name|als_low_trip
decl_stmt|;
name|u16
name|als_high_trip
decl_stmt|;
name|u8
name|sclalarcoeff_tab_row_num
decl_stmt|;
name|u8
name|sclalarcoeff_tab_row_size
decl_stmt|;
name|u8
name|coefficient
index|[
literal|8
index|]
decl_stmt|;
name|u8
name|panel_misc_bits_1
decl_stmt|;
name|u8
name|panel_misc_bits_2
decl_stmt|;
name|u8
name|panel_misc_bits_3
decl_stmt|;
name|u8
name|panel_misc_bits_4
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|BDB_DRIVER_FEATURE_NO_LVDS
value|0
end_define

begin_define
define|#
directive|define
name|BDB_DRIVER_FEATURE_INT_LVDS
value|1
end_define

begin_define
define|#
directive|define
name|BDB_DRIVER_FEATURE_SDVO_LVDS
value|2
end_define

begin_define
define|#
directive|define
name|BDB_DRIVER_FEATURE_EDP
value|3
end_define

begin_struct
struct|struct
name|bdb_driver_features
block|{
name|u8
name|boot_dev_algorithm
range|:
literal|1
decl_stmt|;
name|u8
name|block_display_switch
range|:
literal|1
decl_stmt|;
name|u8
name|allow_display_switch
range|:
literal|1
decl_stmt|;
name|u8
name|hotplug_dvo
range|:
literal|1
decl_stmt|;
name|u8
name|dual_view_zoom
range|:
literal|1
decl_stmt|;
name|u8
name|int15h_hook
range|:
literal|1
decl_stmt|;
name|u8
name|sprite_in_clone
range|:
literal|1
decl_stmt|;
name|u8
name|primary_lfp_id
range|:
literal|1
decl_stmt|;
name|u16
name|boot_mode_x
decl_stmt|;
name|u16
name|boot_mode_y
decl_stmt|;
name|u8
name|boot_mode_bpp
decl_stmt|;
name|u8
name|boot_mode_refresh
decl_stmt|;
name|u16
name|enable_lfp_primary
range|:
literal|1
decl_stmt|;
name|u16
name|selective_mode_pruning
range|:
literal|1
decl_stmt|;
name|u16
name|dual_frequency
range|:
literal|1
decl_stmt|;
name|u16
name|render_clock_freq
range|:
literal|1
decl_stmt|;
comment|/* 0: high freq; 1: low freq */
name|u16
name|nt_clone_support
range|:
literal|1
decl_stmt|;
name|u16
name|power_scheme_ui
range|:
literal|1
decl_stmt|;
comment|/* 0: CUI; 1: 3rd party */
name|u16
name|sprite_display_assign
range|:
literal|1
decl_stmt|;
comment|/* 0: secondary; 1: primary */
name|u16
name|cui_aspect_scaling
range|:
literal|1
decl_stmt|;
name|u16
name|preserve_aspect_ratio
range|:
literal|1
decl_stmt|;
name|u16
name|sdvo_device_power_down
range|:
literal|1
decl_stmt|;
name|u16
name|crt_hotplug
range|:
literal|1
decl_stmt|;
name|u16
name|lvds_config
range|:
literal|2
decl_stmt|;
name|u16
name|tv_hotplug
range|:
literal|1
decl_stmt|;
name|u16
name|hdmi_config
range|:
literal|2
decl_stmt|;
name|u8
name|static_display
range|:
literal|1
decl_stmt|;
name|u8
name|reserved2
range|:
literal|7
decl_stmt|;
name|u16
name|legacy_crt_max_x
decl_stmt|;
name|u16
name|legacy_crt_max_y
decl_stmt|;
name|u8
name|legacy_crt_max_refresh
decl_stmt|;
name|u8
name|hdmi_termination
decl_stmt|;
name|u8
name|custom_vbt_version
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|EDP_18BPP
value|0
end_define

begin_define
define|#
directive|define
name|EDP_24BPP
value|1
end_define

begin_define
define|#
directive|define
name|EDP_30BPP
value|2
end_define

begin_define
define|#
directive|define
name|EDP_RATE_1_62
value|0
end_define

begin_define
define|#
directive|define
name|EDP_RATE_2_7
value|1
end_define

begin_define
define|#
directive|define
name|EDP_LANE_1
value|0
end_define

begin_define
define|#
directive|define
name|EDP_LANE_2
value|1
end_define

begin_define
define|#
directive|define
name|EDP_LANE_4
value|3
end_define

begin_define
define|#
directive|define
name|EDP_PREEMPHASIS_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EDP_PREEMPHASIS_3_5dB
value|1
end_define

begin_define
define|#
directive|define
name|EDP_PREEMPHASIS_6dB
value|2
end_define

begin_define
define|#
directive|define
name|EDP_PREEMPHASIS_9_5dB
value|3
end_define

begin_define
define|#
directive|define
name|EDP_VSWING_0_4V
value|0
end_define

begin_define
define|#
directive|define
name|EDP_VSWING_0_6V
value|1
end_define

begin_define
define|#
directive|define
name|EDP_VSWING_0_8V
value|2
end_define

begin_define
define|#
directive|define
name|EDP_VSWING_1_2V
value|3
end_define

begin_struct
struct|struct
name|edp_power_seq
block|{
name|u16
name|t1_t3
decl_stmt|;
name|u16
name|t8
decl_stmt|;
name|u16
name|t9
decl_stmt|;
name|u16
name|t10
decl_stmt|;
name|u16
name|t11_t12
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|edp_link_params
block|{
name|u8
name|rate
range|:
literal|4
decl_stmt|;
name|u8
name|lanes
range|:
literal|4
decl_stmt|;
name|u8
name|preemphasis
range|:
literal|4
decl_stmt|;
name|u8
name|vswing
range|:
literal|4
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|bdb_edp
block|{
name|struct
name|edp_power_seq
name|power_seqs
index|[
literal|16
index|]
decl_stmt|;
name|u32
name|color_depth
decl_stmt|;
name|struct
name|edp_link_params
name|link_params
index|[
literal|16
index|]
decl_stmt|;
name|u32
name|sdrrs_msa_timing_delay
decl_stmt|;
comment|/* ith bit indicates enabled/disabled for (i+1)th panel */
name|u16
name|edp_s3d_feature
decl_stmt|;
name|u16
name|edp_t3_optimization
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_function_decl
name|void
name|intel_setup_bios
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|intel_parse_bios
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Driver<->VBIOS interaction occurs through scratch bits in  * GR18& SWF*.  */
end_comment

begin_comment
comment|/* GR18 bits are set on display switch and hotkey events */
end_comment

begin_define
define|#
directive|define
name|GR18_DRIVER_SWITCH_EN
value|(1<<7)
end_define

begin_comment
comment|/* 0: VBIOS control, 1: driver control */
end_comment

begin_define
define|#
directive|define
name|GR18_HOTKEY_MASK
value|0x78
end_define

begin_comment
comment|/* See also SWF4 15:0 */
end_comment

begin_define
define|#
directive|define
name|GR18_HK_NONE
value|(0x0<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_LFP_STRETCH
value|(0x1<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_TOGGLE_DISP
value|(0x2<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_DISP_SWITCH
value|(0x4<<3)
end_define

begin_comment
comment|/* see SWF14 15:0 for what to enable */
end_comment

begin_define
define|#
directive|define
name|GR18_HK_POPUP_DISABLED
value|(0x6<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_POPUP_ENABLED
value|(0x7<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_PFIT
value|(0x8<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_APM_CHANGE
value|(0xa<<3)
end_define

begin_define
define|#
directive|define
name|GR18_HK_MULTIPLE
value|(0xc<<3)
end_define

begin_define
define|#
directive|define
name|GR18_USER_INT_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|GR18_A0000_FLUSH_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|GR18_SMM_EN
value|(1<<0)
end_define

begin_comment
comment|/* Set by driver, cleared by VBIOS */
end_comment

begin_define
define|#
directive|define
name|SWF00_YRES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SWF00_XRES_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SWF00_RES_MASK
value|0xffff
end_define

begin_comment
comment|/* Set by VBIOS at boot time and driver at runtime */
end_comment

begin_define
define|#
directive|define
name|SWF01_TV2_FORMAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SWF01_TV1_FORMAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SWF01_TV_FORMAT_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|SWF10_VBIOS_BLC_I2C_EN
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|SWF10_GTT_OVERRIDE_EN
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|SWF10_LFP_DPMS_OVR
value|(1<<27)
end_define

begin_comment
comment|/* override DPMS on display switch */
end_comment

begin_define
define|#
directive|define
name|SWF10_ACTIVE_TOGGLE_LIST_MASK
value|(7<<24)
end_define

begin_define
define|#
directive|define
name|SWF10_OLD_TOGGLE
value|0x0
end_define

begin_define
define|#
directive|define
name|SWF10_TOGGLE_LIST_1
value|0x1
end_define

begin_define
define|#
directive|define
name|SWF10_TOGGLE_LIST_2
value|0x2
end_define

begin_define
define|#
directive|define
name|SWF10_TOGGLE_LIST_3
value|0x3
end_define

begin_define
define|#
directive|define
name|SWF10_TOGGLE_LIST_4
value|0x4
end_define

begin_define
define|#
directive|define
name|SWF10_PANNING_EN
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|SWF10_DRIVER_LOADED
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|SWF10_EXTENDED_DESKTOP
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|SWF10_EXCLUSIVE_MODE
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|SWF10_OVERLAY_EN
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|SWF10_PLANEB_HOLDOFF
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|SWF10_PLANEA_HOLDOFF
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|SWF10_VGA_HOLDOFF
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|SWF10_ACTIVE_DISP_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_LFP2
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_EFP2
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_TV2
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_CRT2
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_LFP
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_EFP
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_TV
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEB_CRT
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_LFP2
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_EFP2
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_TV2
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_CRT2
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_LFP
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_EFP
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_TV
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SWF10_PIPEA_CRT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SWF11_MEMORY_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SWF11_SV_TEST_EN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|SWF11_IS_AGP
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SWF11_DISPLAY_HOLDOFF
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|SWF11_DPMS_REDUCED
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SWF11_IS_VBE_MODE
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|SWF11_PIPEB_ACCESS
value|(1<<10)
end_define

begin_comment
comment|/* 0 here means pipe a */
end_comment

begin_define
define|#
directive|define
name|SWF11_DPMS_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|SWF11_DPMS_OFF
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SWF11_DPMS_SUSPEND
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SWF11_DPMS_STANDBY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|SWF11_DPMS_ON
value|0
end_define

begin_define
define|#
directive|define
name|SWF14_GFX_PFIT_EN
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|SWF14_TEXT_PFIT_EN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|SWF14_LID_STATUS_CLOSED
value|(1<<29)
end_define

begin_comment
comment|/* 0 here means open */
end_comment

begin_define
define|#
directive|define
name|SWF14_POPUP_EN
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|SWF14_DISPLAY_HOLDOFF
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|SWF14_DISP_DETECT_EN
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|SWF14_DOCKING_STATUS_DOCKED
value|(1<<25)
end_define

begin_comment
comment|/* 0 here means undocked */
end_comment

begin_define
define|#
directive|define
name|SWF14_DRIVER_STATUS
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|SWF14_OS_TYPE_WIN9X
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|SWF14_OS_TYPE_WINNT
value|(1<<22)
end_define

begin_comment
comment|/* 21:19 rsvd */
end_comment

begin_define
define|#
directive|define
name|SWF14_PM_TYPE_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|SWF14_PM_ACPI_VIDEO
value|(0x4<< 16)
end_define

begin_define
define|#
directive|define
name|SWF14_PM_ACPI
value|(0x3<< 16)
end_define

begin_define
define|#
directive|define
name|SWF14_PM_APM_12
value|(0x2<< 16)
end_define

begin_define
define|#
directive|define
name|SWF14_PM_APM_11
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|SWF14_HK_REQUEST_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* see GR18 6:3 for event type */
end_comment

begin_comment
comment|/* if GR18 indicates a display switch */
end_comment

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_LFP2_EN
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_EFP2_EN
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_TV2_EN
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_CRT2_EN
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_LFP_EN
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_EFP_EN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_TV_EN
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEB_CRT_EN
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_LFP2_EN
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_EFP2_EN
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_TV2_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_CRT2_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_LFP_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_EFP_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_TV_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|SWF14_DS_PIPEA_CRT_EN
value|(1<<0)
end_define

begin_comment
comment|/* if GR18 indicates a panel fitting request */
end_comment

begin_define
define|#
directive|define
name|SWF14_PFIT_EN
value|(1<<0)
end_define

begin_comment
comment|/* 0 means disable */
end_comment

begin_comment
comment|/* if GR18 indicates an APM change request */
end_comment

begin_define
define|#
directive|define
name|SWF14_APM_HIBERNATE
value|0x4
end_define

begin_define
define|#
directive|define
name|SWF14_APM_SUSPEND
value|0x3
end_define

begin_define
define|#
directive|define
name|SWF14_APM_STANDBY
value|0x1
end_define

begin_define
define|#
directive|define
name|SWF14_APM_RESTORE
value|0x0
end_define

begin_comment
comment|/* Add the device class for LFP, TV, HDMI */
end_comment

begin_define
define|#
directive|define
name|DEVICE_TYPE_INT_LFP
value|0x1022
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_INT_TV
value|0x1009
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_HDMI
value|0x60D2
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_DP
value|0x68C6
end_define

begin_define
define|#
directive|define
name|DEVICE_TYPE_eDP
value|0x78C6
end_define

begin_comment
comment|/* define the DVO port for HDMI output type */
end_comment

begin_define
define|#
directive|define
name|DVO_B
value|1
end_define

begin_define
define|#
directive|define
name|DVO_C
value|2
end_define

begin_define
define|#
directive|define
name|DVO_D
value|3
end_define

begin_comment
comment|/* define the PORT for DP output type */
end_comment

begin_define
define|#
directive|define
name|PORT_IDPB
value|7
end_define

begin_define
define|#
directive|define
name|PORT_IDPC
value|8
end_define

begin_define
define|#
directive|define
name|PORT_IDPD
value|9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I830_BIOS_H_ */
end_comment

end_unit

