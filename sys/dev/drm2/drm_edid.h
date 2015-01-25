begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright Â© 2007-2008 Intel Corporation  *   Jesse Barnes<jesse.barnes@intel.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DRM_EDID_H__
end_ifndef

begin_define
define|#
directive|define
name|__DRM_EDID_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drmP.h>
end_include

begin_define
define|#
directive|define
name|EDID_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|DDC_ADDR
value|0x50
end_define

begin_define
define|#
directive|define
name|CEA_EXT
value|0x02
end_define

begin_define
define|#
directive|define
name|VTB_EXT
value|0x10
end_define

begin_define
define|#
directive|define
name|DI_EXT
value|0x40
end_define

begin_define
define|#
directive|define
name|LS_EXT
value|0x50
end_define

begin_define
define|#
directive|define
name|MI_EXT
value|0x60
end_define

begin_struct
struct|struct
name|est_timings
block|{
name|u8
name|t1
decl_stmt|;
name|u8
name|t2
decl_stmt|;
name|u8
name|mfg_rsvd
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
comment|/* 00=16:10, 01=4:3, 10=5:4, 11=16:9 */
end_comment

begin_define
define|#
directive|define
name|EDID_TIMING_ASPECT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|EDID_TIMING_ASPECT_MASK
value|(0x3<< EDID_TIMING_ASPECT_SHIFT)
end_define

begin_comment
comment|/* need to add 60 */
end_comment

begin_define
define|#
directive|define
name|EDID_TIMING_VFREQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EDID_TIMING_VFREQ_MASK
value|(0x3f<< EDID_TIMING_VFREQ_SHIFT)
end_define

begin_struct
struct|struct
name|std_timing
block|{
name|u8
name|hsize
decl_stmt|;
comment|/* need to multiply by 8 then add 248 */
name|u8
name|vfreq_aspect
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
name|DRM_EDID_PT_HSYNC_POSITIVE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_PT_VSYNC_POSITIVE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_PT_SEPARATE_SYNC
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_PT_STEREO
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_PT_INTERLACED
value|(1<< 7)
end_define

begin_comment
comment|/* If detailed data is pixel timing */
end_comment

begin_struct
struct|struct
name|detailed_pixel_timing
block|{
name|u8
name|hactive_lo
decl_stmt|;
name|u8
name|hblank_lo
decl_stmt|;
name|u8
name|hactive_hblank_hi
decl_stmt|;
name|u8
name|vactive_lo
decl_stmt|;
name|u8
name|vblank_lo
decl_stmt|;
name|u8
name|vactive_vblank_hi
decl_stmt|;
name|u8
name|hsync_offset_lo
decl_stmt|;
name|u8
name|hsync_pulse_width_lo
decl_stmt|;
name|u8
name|vsync_offset_pulse_width_lo
decl_stmt|;
name|u8
name|hsync_vsync_offset_pulse_width_hi
decl_stmt|;
name|u8
name|width_mm_lo
decl_stmt|;
name|u8
name|height_mm_lo
decl_stmt|;
name|u8
name|width_height_mm_hi
decl_stmt|;
name|u8
name|hborder
decl_stmt|;
name|u8
name|vborder
decl_stmt|;
name|u8
name|misc
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
comment|/* If it's not pixel timing, it'll be one of the below */
end_comment

begin_struct
struct|struct
name|detailed_data_string
block|{
name|u8
name|str
index|[
literal|13
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
name|detailed_data_monitor_range
block|{
name|u8
name|min_vfreq
decl_stmt|;
name|u8
name|max_vfreq
decl_stmt|;
name|u8
name|min_hfreq_khz
decl_stmt|;
name|u8
name|max_hfreq_khz
decl_stmt|;
name|u8
name|pixel_clock_mhz
decl_stmt|;
comment|/* need to multiply by 10 */
name|u8
name|flags
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|u8
name|reserved
decl_stmt|;
name|u8
name|hfreq_start_khz
decl_stmt|;
comment|/* need to multiply by 2 */
name|u8
name|c
decl_stmt|;
comment|/* need to divide by 2 */
name|u16
name|m
decl_stmt|;
name|u8
name|k
decl_stmt|;
name|u8
name|j
decl_stmt|;
comment|/* need to divide by 2 */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|gtf2
struct|;
struct|struct
block|{
name|u8
name|version
decl_stmt|;
name|u8
name|data1
decl_stmt|;
comment|/* high 6 bits: extra clock resolution */
name|u8
name|data2
decl_stmt|;
comment|/* plus low 2 of above: max hactive */
name|u8
name|supported_aspects
decl_stmt|;
name|u8
name|flags
decl_stmt|;
comment|/* preferred aspect and blanking support */
name|u8
name|supported_scalings
decl_stmt|;
name|u8
name|preferred_refresh
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|cvt
struct|;
block|}
name|formula
union|;
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
name|detailed_data_wpindex
block|{
name|u8
name|white_yx_lo
decl_stmt|;
comment|/* Lower 2 bits each */
name|u8
name|white_x_hi
decl_stmt|;
name|u8
name|white_y_hi
decl_stmt|;
name|u8
name|gamma
decl_stmt|;
comment|/* need to divide by 100 then add 1 */
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
name|detailed_data_color_point
block|{
name|u8
name|windex1
decl_stmt|;
name|u8
name|wpindex1
index|[
literal|3
index|]
decl_stmt|;
name|u8
name|windex2
decl_stmt|;
name|u8
name|wpindex2
index|[
literal|3
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
name|cvt_timing
block|{
name|u8
name|code
index|[
literal|3
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
name|detailed_non_pixel
block|{
name|u8
name|pad1
decl_stmt|;
name|u8
name|type
decl_stmt|;
comment|/* ff=serial, fe=string, fd=monitor range, fc=monitor name 		    fb=color point data, fa=standard timing data, 		    f9=undefined, f8=mfg. reserved */
name|u8
name|pad2
decl_stmt|;
union|union
block|{
name|struct
name|detailed_data_string
name|str
decl_stmt|;
name|struct
name|detailed_data_monitor_range
name|range
decl_stmt|;
name|struct
name|detailed_data_wpindex
name|color
decl_stmt|;
name|struct
name|std_timing
name|timings
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|cvt_timing
name|cvt
index|[
literal|4
index|]
decl_stmt|;
block|}
name|data
union|;
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
name|EDID_DETAIL_EST_TIMINGS
value|0xf7
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_CVT_3BYTE
value|0xf8
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_COLOR_MGMT_DATA
value|0xf9
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_STD_MODES
value|0xfa
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_MONITOR_CPDATA
value|0xfb
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_MONITOR_NAME
value|0xfc
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_MONITOR_RANGE
value|0xfd
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_MONITOR_STRING
value|0xfe
end_define

begin_define
define|#
directive|define
name|EDID_DETAIL_MONITOR_SERIAL
value|0xff
end_define

begin_struct
struct|struct
name|detailed_timing
block|{
name|u16
name|pixel_clock
decl_stmt|;
comment|/* need to multiply by 10 KHz */
union|union
block|{
name|struct
name|detailed_pixel_timing
name|pixel_data
decl_stmt|;
name|struct
name|detailed_non_pixel
name|other_data
decl_stmt|;
block|}
name|data
union|;
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
name|DRM_EDID_INPUT_SERRATION_VSYNC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_SYNC_ON_GREEN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_COMPOSITE_SYNC
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_SEPARATE_SYNCS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_BLANK_TO_BLACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_VIDEO_LEVEL
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_INPUT_DIGITAL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_MASK
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_UNDEF
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_6
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_8
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_10
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_12
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_14
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_16
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_DEPTH_RSVD
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_UNDEF
value|(0)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_DVI
value|(1)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_HDMI_A
value|(2)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_HDMI_B
value|(3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_MDDI
value|(4)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_DIGITAL_TYPE_DP
value|(5)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_DEFAULT_GTF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_PREFERRED_TIMING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_STANDARD_COLOR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_DISPLAY_TYPE
value|(3<< 3)
end_define

begin_comment
comment|/* 00=mono, 01=rgb, 10=non-rgb, 11=unknown */
end_comment

begin_comment
comment|/* If digital */
end_comment

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_COLOR_MASK
value|(3<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_RGB
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_RGB_YCRCB444
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_RGB_YCRCB422
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_RGB_YCRCB
value|(3<< 3)
end_define

begin_comment
comment|/* both 4:4:4 and 4:2:2 */
end_comment

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_PM_ACTIVE_OFF
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_PM_SUSPEND
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|DRM_EDID_FEATURE_PM_STANDBY
value|(1<< 7)
end_define

begin_struct
struct|struct
name|edid
block|{
name|u8
name|header
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor& product info */
name|u8
name|mfg_id
index|[
literal|2
index|]
decl_stmt|;
name|u8
name|prod_code
index|[
literal|2
index|]
decl_stmt|;
name|u32
name|serial
decl_stmt|;
comment|/* FIXME: byte order */
name|u8
name|mfg_week
decl_stmt|;
name|u8
name|mfg_year
decl_stmt|;
comment|/* EDID version */
name|u8
name|version
decl_stmt|;
name|u8
name|revision
decl_stmt|;
comment|/* Display info: */
name|u8
name|input
decl_stmt|;
name|u8
name|width_cm
decl_stmt|;
name|u8
name|height_cm
decl_stmt|;
name|u8
name|gamma
decl_stmt|;
name|u8
name|features
decl_stmt|;
comment|/* Color characteristics */
name|u8
name|red_green_lo
decl_stmt|;
name|u8
name|black_white_lo
decl_stmt|;
name|u8
name|red_x
decl_stmt|;
name|u8
name|red_y
decl_stmt|;
name|u8
name|green_x
decl_stmt|;
name|u8
name|green_y
decl_stmt|;
name|u8
name|blue_x
decl_stmt|;
name|u8
name|blue_y
decl_stmt|;
name|u8
name|white_x
decl_stmt|;
name|u8
name|white_y
decl_stmt|;
comment|/* Est. timings and mfg rsvd timings*/
name|struct
name|est_timings
name|established_timings
decl_stmt|;
comment|/* Standard timings 1-8*/
name|struct
name|std_timing
name|standard_timings
index|[
literal|8
index|]
decl_stmt|;
comment|/* Detailing timings 1-4 */
name|struct
name|detailed_timing
name|detailed_timings
index|[
literal|4
index|]
decl_stmt|;
comment|/* Number of 128 byte ext. blocks */
name|u8
name|extensions
decl_stmt|;
comment|/* Checksum */
name|u8
name|checksum
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
name|EDID_PRODUCT_ID
parameter_list|(
name|e
parameter_list|)
value|((e)->prod_code[0] | ((e)->prod_code[1]<< 8))
end_define

begin_struct_decl
struct_decl|struct
name|drm_encoder
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|drm_connector
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|drm_display_mode
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|drm_edid_to_eld
parameter_list|(
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|,
name|struct
name|edid
modifier|*
name|edid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_av_sync_delay
parameter_list|(
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_connector
modifier|*
name|drm_select_eld
parameter_list|(
name|struct
name|drm_encoder
modifier|*
name|encoder
parameter_list|,
name|struct
name|drm_display_mode
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DRM_EDID_H__ */
end_comment

end_unit

