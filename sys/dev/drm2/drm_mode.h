begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2007 Dave Airlie<airlied@linux.ie>  * Copyright (c) 2007 Jakob Bornecrantz<wallbraker@gmail.com>  * Copyright (c) 2008 Red Hat Inc.  * Copyright (c) 2007-2008 Tungsten Graphics, Inc., Cedar Park, TX., USA  * Copyright (c) 2007-2008 Intel Corporation  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS  * IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_MODE_H
end_ifndef

begin_define
define|#
directive|define
name|_DRM_MODE_H
end_define

begin_define
define|#
directive|define
name|DRM_DISPLAY_INFO_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DRM_CONNECTOR_NAME_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DRM_DISPLAY_MODE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DRM_PROP_NAME_LEN
value|32
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_BUILTIN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_CLOCK_C
value|((1<<1) | DRM_MODE_TYPE_BUILTIN)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_CRTC_C
value|((1<<2) | DRM_MODE_TYPE_BUILTIN)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_PREFERRED
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_DEFAULT
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_USERDEF
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_TYPE_DRIVER
value|(1<<6)
end_define

begin_comment
comment|/* Video mode flags */
end_comment

begin_comment
comment|/* bit compatible with the xorg definitions. */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_PHSYNC
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_NHSYNC
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_PVSYNC
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_NVSYNC
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_INTERLACE
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_DBLSCAN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_CSYNC
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_PCSYNC
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_NCSYNC
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_HSKEW
value|(1<<9)
end_define

begin_comment
comment|/* hskew provided */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_BCAST
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_PIXMUX
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_DBLCLK
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FLAG_CLKDIV2
value|(1<<13)
end_define

begin_comment
comment|/* DPMS flags */
end_comment

begin_comment
comment|/* bit compatible with the xorg definitions. */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_DPMS_ON
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DPMS_STANDBY
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DPMS_SUSPEND
value|2
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DPMS_OFF
value|3
end_define

begin_comment
comment|/* Scaling mode options */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_SCALE_NONE
value|0
end_define

begin_comment
comment|/* Unmodified timing (display or 					     software can still scale) */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_SCALE_FULLSCREEN
value|1
end_define

begin_comment
comment|/* Full screen, ignore aspect */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_SCALE_CENTER
value|2
end_define

begin_comment
comment|/* Centered, no scaling */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_SCALE_ASPECT
value|3
end_define

begin_comment
comment|/* Full screen, preserve aspect */
end_comment

begin_comment
comment|/* Dithering mode options */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_DITHERING_OFF
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DITHERING_ON
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DITHERING_AUTO
value|2
end_define

begin_comment
comment|/* Dirty info options */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_DIRTY_OFF
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DIRTY_ON
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MODE_DIRTY_ANNOTATE
value|2
end_define

begin_struct
struct|struct
name|drm_mode_modeinfo
block|{
name|uint32_t
name|clock
decl_stmt|;
name|uint16_t
name|hdisplay
decl_stmt|,
name|hsync_start
decl_stmt|,
name|hsync_end
decl_stmt|,
name|htotal
decl_stmt|,
name|hskew
decl_stmt|;
name|uint16_t
name|vdisplay
decl_stmt|,
name|vsync_start
decl_stmt|,
name|vsync_end
decl_stmt|,
name|vtotal
decl_stmt|,
name|vscan
decl_stmt|;
name|uint32_t
name|vrefresh
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|type
decl_stmt|;
name|char
name|name
index|[
name|DRM_DISPLAY_MODE_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_card_res
block|{
name|uint64_t
name|fb_id_ptr
decl_stmt|;
name|uint64_t
name|crtc_id_ptr
decl_stmt|;
name|uint64_t
name|connector_id_ptr
decl_stmt|;
name|uint64_t
name|encoder_id_ptr
decl_stmt|;
name|uint32_t
name|count_fbs
decl_stmt|;
name|uint32_t
name|count_crtcs
decl_stmt|;
name|uint32_t
name|count_connectors
decl_stmt|;
name|uint32_t
name|count_encoders
decl_stmt|;
name|uint32_t
name|min_width
decl_stmt|,
name|max_width
decl_stmt|;
name|uint32_t
name|min_height
decl_stmt|,
name|max_height
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_crtc
block|{
name|uint64_t
name|set_connectors_ptr
decl_stmt|;
name|uint32_t
name|count_connectors
decl_stmt|;
name|uint32_t
name|crtc_id
decl_stmt|;
comment|/**< Id */
name|uint32_t
name|fb_id
decl_stmt|;
comment|/**< Id of framebuffer */
name|uint32_t
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/**< Position on the frameuffer */
name|uint32_t
name|gamma_size
decl_stmt|;
name|uint32_t
name|mode_valid
decl_stmt|;
name|struct
name|drm_mode_modeinfo
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_PRESENT_TOP_FIELD
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PRESENT_BOTTOM_FIELD
value|(1<<1)
end_define

begin_comment
comment|/* Planes blend with or override other bits on the CRTC */
end_comment

begin_struct
struct|struct
name|drm_mode_set_plane
block|{
name|uint32_t
name|plane_id
decl_stmt|;
name|uint32_t
name|crtc_id
decl_stmt|;
name|uint32_t
name|fb_id
decl_stmt|;
comment|/* fb object contains surface format type */
name|uint32_t
name|flags
decl_stmt|;
comment|/* see above flags */
comment|/* Signed dest location allows it to be partially off screen */
name|int32_t
name|crtc_x
decl_stmt|,
name|crtc_y
decl_stmt|;
name|uint32_t
name|crtc_w
decl_stmt|,
name|crtc_h
decl_stmt|;
comment|/* Source values are 16.16 fixed point */
name|uint32_t
name|src_x
decl_stmt|,
name|src_y
decl_stmt|;
name|uint32_t
name|src_h
decl_stmt|,
name|src_w
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_get_plane
block|{
name|uint32_t
name|plane_id
decl_stmt|;
name|uint32_t
name|crtc_id
decl_stmt|;
name|uint32_t
name|fb_id
decl_stmt|;
name|uint32_t
name|possible_crtcs
decl_stmt|;
name|uint32_t
name|gamma_size
decl_stmt|;
name|uint32_t
name|count_format_types
decl_stmt|;
name|uint64_t
name|format_type_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_get_plane_res
block|{
name|uint64_t
name|plane_id_ptr
decl_stmt|;
name|uint32_t
name|count_planes
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_ENCODER_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_ENCODER_DAC
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MODE_ENCODER_TMDS
value|2
end_define

begin_define
define|#
directive|define
name|DRM_MODE_ENCODER_LVDS
value|3
end_define

begin_define
define|#
directive|define
name|DRM_MODE_ENCODER_TVDAC
value|4
end_define

begin_struct
struct|struct
name|drm_mode_get_encoder
block|{
name|uint32_t
name|encoder_id
decl_stmt|;
name|uint32_t
name|encoder_type
decl_stmt|;
name|uint32_t
name|crtc_id
decl_stmt|;
comment|/**< Id of crtc */
name|uint32_t
name|possible_crtcs
decl_stmt|;
name|uint32_t
name|possible_clones
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is for connectors with multiple signal types. */
end_comment

begin_comment
comment|/* Try to match DRM_MODE_CONNECTOR_X as closely as possible. */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_Automatic
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_Unknown
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_DVID
value|3
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_DVIA
value|4
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_Composite
value|5
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_SVIDEO
value|6
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_Component
value|8
end_define

begin_define
define|#
directive|define
name|DRM_MODE_SUBCONNECTOR_SCART
value|9
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_Unknown
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_VGA
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_DVII
value|2
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_DVID
value|3
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_DVIA
value|4
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_Composite
value|5
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_SVIDEO
value|6
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_LVDS
value|7
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_Component
value|8
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_9PinDIN
value|9
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_DisplayPort
value|10
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_HDMIA
value|11
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_HDMIB
value|12
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_TV
value|13
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CONNECTOR_eDP
value|14
end_define

begin_struct
struct|struct
name|drm_mode_get_connector
block|{
name|uint64_t
name|encoders_ptr
decl_stmt|;
name|uint64_t
name|modes_ptr
decl_stmt|;
name|uint64_t
name|props_ptr
decl_stmt|;
name|uint64_t
name|prop_values_ptr
decl_stmt|;
name|uint32_t
name|count_modes
decl_stmt|;
name|uint32_t
name|count_props
decl_stmt|;
name|uint32_t
name|count_encoders
decl_stmt|;
name|uint32_t
name|encoder_id
decl_stmt|;
comment|/**< Current Encoder */
name|uint32_t
name|connector_id
decl_stmt|;
comment|/**< Id */
name|uint32_t
name|connector_type
decl_stmt|;
name|uint32_t
name|connector_type_id
decl_stmt|;
name|uint32_t
name|connection
decl_stmt|;
name|uint32_t
name|mm_width
decl_stmt|,
name|mm_height
decl_stmt|;
comment|/**< HxW in millimeters */
name|uint32_t
name|subpixel
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_PROP_PENDING
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PROP_RANGE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PROP_IMMUTABLE
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PROP_ENUM
value|(1<<3)
end_define

begin_comment
comment|/* enumerated type with text strings */
end_comment

begin_define
define|#
directive|define
name|DRM_MODE_PROP_BLOB
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PROP_BITMASK
value|(1<<5)
end_define

begin_comment
comment|/* bitmask of enumerated types */
end_comment

begin_struct
struct|struct
name|drm_mode_property_enum
block|{
name|uint64_t
name|value
decl_stmt|;
name|char
name|name
index|[
name|DRM_PROP_NAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_get_property
block|{
name|uint64_t
name|values_ptr
decl_stmt|;
comment|/* values and blob lengths */
name|uint64_t
name|enum_blob_ptr
decl_stmt|;
comment|/* enum and blob id ptrs */
name|uint32_t
name|prop_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|char
name|name
index|[
name|DRM_PROP_NAME_LEN
index|]
decl_stmt|;
name|uint32_t
name|count_values
decl_stmt|;
name|uint32_t
name|count_enum_blobs
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_connector_set_property
block|{
name|uint64_t
name|value
decl_stmt|;
name|uint32_t
name|prop_id
decl_stmt|;
name|uint32_t
name|connector_id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_obj_get_properties
block|{
name|uint64_t
name|props_ptr
decl_stmt|;
name|uint64_t
name|prop_values_ptr
decl_stmt|;
name|uint32_t
name|count_props
decl_stmt|;
name|uint32_t
name|obj_id
decl_stmt|;
name|uint32_t
name|obj_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_obj_set_property
block|{
name|uint64_t
name|value
decl_stmt|;
name|uint32_t
name|prop_id
decl_stmt|;
name|uint32_t
name|obj_id
decl_stmt|;
name|uint32_t
name|obj_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_get_blob
block|{
name|uint32_t
name|blob_id
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint64_t
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_fb_cmd
block|{
name|uint32_t
name|fb_id
decl_stmt|;
name|uint32_t
name|width
decl_stmt|,
name|height
decl_stmt|;
name|uint32_t
name|pitch
decl_stmt|;
name|uint32_t
name|bpp
decl_stmt|;
name|uint32_t
name|depth
decl_stmt|;
comment|/* driver specific handle */
name|uint32_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_FB_INTERLACED
value|(1<<0
end_define

begin_comment
comment|/* for interlaced framebuffers */
end_comment

begin_struct
struct|struct
name|drm_mode_fb_cmd2
block|{
name|uint32_t
name|fb_id
decl_stmt|;
name|uint32_t
name|width
decl_stmt|,
name|height
decl_stmt|;
name|uint32_t
name|pixel_format
decl_stmt|;
comment|/* fourcc code from drm_fourcc.h */
name|uint32_t
name|flags
decl_stmt|;
comment|/* see above flags */
comment|/* 	 * In case of planar formats, this ioctl allows up to 4 	 * buffer objects with offets and pitches per plane. 	 * The pitch and offset order is dictated by the fourcc, 	 * e.g. NV12 (http://fourcc.org/yuv.php#NV12) is described as: 	 * 	 *   YUV 4:2:0 image with a plane of 8 bit Y samples 	 *   followed by an interleaved U/V plane containing 	 *   8 bit 2x2 subsampled colour difference samples. 	 * 	 * So it would consist of Y as offset[0] and UV as 	 * offeset[1].  Note that offset[0] will generally 	 * be 0. 	 */
name|uint32_t
name|handles
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|pitches
index|[
literal|4
index|]
decl_stmt|;
comment|/* pitch for each plane */
name|uint32_t
name|offsets
index|[
literal|4
index|]
decl_stmt|;
comment|/* offset of each plane */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_FB_DIRTY_ANNOTATE_COPY
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FB_DIRTY_ANNOTATE_FILL
value|0x02
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FB_DIRTY_FLAGS
value|0x03
end_define

begin_define
define|#
directive|define
name|DRM_MODE_FB_DIRTY_MAX_CLIPS
value|256
end_define

begin_comment
comment|/*  * Mark a region of a framebuffer as dirty.  *  * Some hardware does not automatically update display contents  * as a hardware or software draw to a framebuffer. This ioctl  * allows userspace to tell the kernel and the hardware what  * regions of the framebuffer have changed.  *  * The kernel or hardware is free to update more then just the  * region specified by the clip rects. The kernel or hardware  * may also delay and/or coalesce several calls to dirty into a  * single update.  *  * Userspace may annotate the updates, the annotates are a  * promise made by the caller that the change is either a copy  * of pixels or a fill of a single color in the region specified.  *  * If the DRM_MODE_FB_DIRTY_ANNOTATE_COPY flag is given then  * the number of updated regions are half of num_clips given,  * where the clip rects are paired in src and dst. The width and  * height of each one of the pairs must match.  *  * If the DRM_MODE_FB_DIRTY_ANNOTATE_FILL flag is given the caller  * promises that the region specified of the clip rects is filled  * completely with a single color as given in the color argument.  */
end_comment

begin_struct
struct|struct
name|drm_mode_fb_dirty_cmd
block|{
name|uint32_t
name|fb_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|color
decl_stmt|;
name|uint32_t
name|num_clips
decl_stmt|;
name|uint64_t
name|clips_ptr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_mode_cmd
block|{
name|uint32_t
name|connector_id
decl_stmt|;
name|struct
name|drm_mode_modeinfo
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_CURSOR_BO
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|DRM_MODE_CURSOR_MOVE
value|(1<<1)
end_define

begin_comment
comment|/*  * depending on the value in flags diffrent members are used.  *  * CURSOR_BO uses  *    crtc  *    width  *    height  *    handle - if 0 turns the cursor of  *  * CURSOR_MOVE uses  *    crtc  *    x  *    y  */
end_comment

begin_struct
struct|struct
name|drm_mode_cursor
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|crtc_id
decl_stmt|;
name|int32_t
name|x
decl_stmt|;
name|int32_t
name|y
decl_stmt|;
name|uint32_t
name|width
decl_stmt|;
name|uint32_t
name|height
decl_stmt|;
comment|/* driver specific handle */
name|uint32_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_crtc_lut
block|{
name|uint32_t
name|crtc_id
decl_stmt|;
name|uint32_t
name|gamma_size
decl_stmt|;
comment|/* pointers to arrays */
name|uint64_t
name|red
decl_stmt|;
name|uint64_t
name|green
decl_stmt|;
name|uint64_t
name|blue
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_MODE_PAGE_FLIP_EVENT
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_MODE_PAGE_FLIP_FLAGS
value|DRM_MODE_PAGE_FLIP_EVENT
end_define

begin_comment
comment|/*  * Request a page flip on the specified crtc.  *  * This ioctl will ask KMS to schedule a page flip for the specified  * crtc.  Once any pending rendering targeting the specified fb (as of  * ioctl time) has completed, the crtc will be reprogrammed to display  * that fb after the next vertical refresh.  The ioctl returns  * immediately, but subsequent rendering to the current fb will block  * in the execbuffer ioctl until the page flip happens.  If a page  * flip is already pending as the ioctl is called, EBUSY will be  * returned.  *  * The ioctl supports one flag, DRM_MODE_PAGE_FLIP_EVENT, which will  * request that drm sends back a vblank event (see drm.h: struct  * drm_event_vblank) when the page flip is done.  The user_data field  * passed in with this ioctl will be returned as the user_data field  * in the vblank event struct.  *  * The reserved field must be zero until we figure out something  * clever to use it for.  */
end_comment

begin_struct
struct|struct
name|drm_mode_crtc_page_flip
block|{
name|uint32_t
name|crtc_id
decl_stmt|;
name|uint32_t
name|fb_id
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint64_t
name|user_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* create a dumb scanout buffer */
end_comment

begin_struct
struct|struct
name|drm_mode_create_dumb
block|{
name|uint32_t
name|height
decl_stmt|;
name|uint32_t
name|width
decl_stmt|;
name|uint32_t
name|bpp
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
comment|/* handle, pitch, size will be returned */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pitch
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* set up for mmap of a dumb scanout buffer */
end_comment

begin_struct
struct|struct
name|drm_mode_map_dumb
block|{
comment|/** Handle for the object being mapped. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
comment|/** 	 * Fake offset to use for subsequent mmap call 	 * 	 * This is a fixed-size type for 32/64 compatibility. 	 */
name|uint64_t
name|offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mode_destroy_dumb
block|{
name|uint32_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

