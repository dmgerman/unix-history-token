begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: edidreg.h,v 1.3 2011/03/30 18:49:56 jdc Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 Itronix Inc.  * All rights reserved.  *  * Written by Garrett D'Amore for Itronix Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Itronix Inc. may not be used to endorse  *    or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ITRONIX INC. ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL ITRONIX INC. BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VIDEOMODE_EDIDREG_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VIDEOMODE_EDIDREG_H
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_SIGNATURE
value|0x00
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_MANUFACTURER_ID
value|0x08
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_PRODUCT_ID
value|0x0a
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_SERIAL_NUMBER
value|0x0c
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_MANUFACTURE_WEEK
value|0x10
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_MANUFACTURE_YEAR
value|0x11
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_VERSION
value|0x12
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_REVISION
value|0x13
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_VIDEO_INPUT
value|0x14
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_MAX_HSIZE
value|0x15
end_define

begin_comment
comment|/* in cm */
end_comment

begin_define
define|#
directive|define
name|EDID_OFFSET_MAX_VSIZE
value|0x16
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_GAMMA
value|0x17
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_FEATURE
value|0x18
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_CHROMA
value|0x19
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_EST_TIMING_1
value|0x23
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_EST_TIMING_2
value|0x24
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_MFG_TIMING
value|0x25
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_STD_TIMING
value|0x26
end_define

begin_define
define|#
directive|define
name|EDID_OFFSET_DESC_BLOCK
value|0x36
end_define

begin_define
define|#
directive|define
name|EDID_SIGNATURE
value|{ 0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0 }
end_define

begin_comment
comment|/* assume x is 16-bit value */
end_comment

begin_define
define|#
directive|define
name|EDID_VENDOR_ID
parameter_list|(
name|ptr
parameter_list|)
value|((((ptr)[8])<< 8) + ptr[9])
end_define

begin_define
define|#
directive|define
name|EDID_MANFID_0
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 10)& 0x1f) + '@')
end_define

begin_define
define|#
directive|define
name|EDID_MANFID_1
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 5)& 0x1f) + '@')
end_define

begin_define
define|#
directive|define
name|EDID_MANFID_2
parameter_list|(
name|x
parameter_list|)
value|((((x)>> 0)& 0x1f) + '@')
end_define

begin_comment
comment|/* relative to edid block */
end_comment

begin_define
define|#
directive|define
name|EDID_PRODUCT_ID
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[10]) | (((ptr)[11])<< 8))
end_define

begin_define
define|#
directive|define
name|EDID_SERIAL_NUMBER
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[12]<< 24) + \ 					((ptr)[13]<< 16) + \ 					((ptr)[14]<< 8) + \ 					(ptr)[15])
end_define

begin_comment
comment|/* relative to edid block */
end_comment

begin_define
define|#
directive|define
name|EDID_WEEK
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[16])
end_define

begin_define
define|#
directive|define
name|EDID_YEAR
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[17]) + 1990)
end_define

begin_define
define|#
directive|define
name|EDID_VERSION
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[18])
end_define

begin_define
define|#
directive|define
name|EDID_REVISION
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[19])
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[20])
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_DIGITAL
value|0x80
end_define

begin_comment
comment|/* if INPUT_BIT_DIGITAL set */
end_comment

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_DFP1_COMPAT
value|0x01
end_define

begin_comment
comment|/* if INPUT_BIT_DIGITAL not set */
end_comment

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_BLANK_TO_BLACK
value|0x10
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_SEPARATE_SYNCS
value|0x08
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_COMPOSITE_SYNC
value|0x04
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_SYNC_ON_GRN
value|0x02
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_SERRATION
value|0x01
end_define

begin_define
define|#
directive|define
name|EDID_VIDEO_INPUT_LEVEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x60)>> 5)
end_define

begin_comment
comment|/* meanings of level bits are as follows, I don't know names */
end_comment

begin_comment
comment|/* 0 = 0.7,0.3,  1 = 0.714,0.286, 2 = 1.0,0.4, 3 = 0.7,0.0 */
end_comment

begin_comment
comment|/* relative to edid block */
end_comment

begin_define
define|#
directive|define
name|EDID_MAX_HSIZE
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[21])
end_define

begin_comment
comment|/* cm */
end_comment

begin_define
define|#
directive|define
name|EDID_MAX_VSIZE
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[22])
end_define

begin_comment
comment|/* cm */
end_comment

begin_comment
comment|/* gamma is scaled by 100 (avoid fp), e.g. 213 == 2.13 */
end_comment

begin_define
define|#
directive|define
name|_GAMMA
parameter_list|(
name|x
parameter_list|)
value|((x) == 0xff ? 100 : ((x) + 100))
end_define

begin_define
define|#
directive|define
name|EDID_GAMMA
parameter_list|(
name|ptr
parameter_list|)
value|_GAMMA(ptr[23])
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[24])
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_STANDBY
value|0x80
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_SUSPEND
value|0x40
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_ACTIVE_OFF
value|0x20
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DISP_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x18)>> 3)
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DISP_TYPE_MONO
value|0
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DISP_TYPE_RGB
value|1
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DISP_TYPE_NON_RGB
value|2
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DISP_TYPE_UNDEFINED
value|3
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_STD_COLOR
value|0x04
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_PREFERRED_TIMING
value|0x02
end_define

begin_define
define|#
directive|define
name|EDID_FEATURES_DEFAULT_GTF
value|0x01
end_define

begin_comment
comment|/* chroma values 0.0 - 0.999 scaled as 0-999 */
end_comment

begin_define
define|#
directive|define
name|_CHLO
parameter_list|(
name|byt
parameter_list|,
name|shft
parameter_list|)
value|(((byt)>> (shft))& 0x3)
end_define

begin_define
define|#
directive|define
name|_CHHI
parameter_list|(
name|byt
parameter_list|)
value|((byt)<< 2)
end_define

begin_define
define|#
directive|define
name|_CHHILO
parameter_list|(
name|ptr
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|,
name|h
parameter_list|)
value|(_CHLO((ptr)[l], s) | _CHHI((ptr)[h]))
end_define

begin_define
define|#
directive|define
name|_CHROMA
parameter_list|(
name|ptr
parameter_list|,
name|l
parameter_list|,
name|s
parameter_list|,
name|h
parameter_list|)
value|((_CHHILO(ptr, l, s, h) * 1000) / 1024)
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_REDX
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 25, 6, 27))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_REDY
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 25, 4, 28))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_GREENX
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 25, 2, 29))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_GREENY
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 25, 0, 30))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_BLUEX
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 26, 6, 31))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_BLUEY
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 26, 4, 32))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_WHITEX
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 26, 2, 33))
end_define

begin_define
define|#
directive|define
name|EDID_CHROMA_WHITEY
parameter_list|(
name|ptr
parameter_list|)
value|(_CHROMA(ptr, 26, 0, 34))
end_define

begin_comment
comment|/* relative to edid block */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[35]<< 8) | (ptr)[36])
end_define

begin_define
define|#
directive|define
name|EDID_EST_TIMING_720_400_70
value|0x8000
end_define

begin_comment
comment|/* 720x400 @ 70Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_720_400_88
value|0x4000
end_define

begin_comment
comment|/* 720x400 @ 88Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_640_480_60
value|0x2000
end_define

begin_comment
comment|/* 640x480 @ 60Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_640_480_67
value|0x1000
end_define

begin_comment
comment|/* 640x480 @ 67Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_640_480_72
value|0x0800
end_define

begin_comment
comment|/* 640x480 @ 72Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_640_480_75
value|0x0400
end_define

begin_comment
comment|/* 640x480 @ 75Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_800_600_56
value|0x0200
end_define

begin_comment
comment|/* 800x600 @ 56Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_800_600_60
value|0x0100
end_define

begin_comment
comment|/* 800x600 @ 60Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_800_600_72
value|0x0080
end_define

begin_comment
comment|/* 800x600 @ 72Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_800_600_75
value|0x0040
end_define

begin_comment
comment|/* 800x600 @ 75Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_832_624_75
value|0x0020
end_define

begin_comment
comment|/* 832x624 @ 75Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_1024_768_87I
value|0x0010
end_define

begin_comment
comment|/* 1024x768i @ 87Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_1024_768_60
value|0x0008
end_define

begin_comment
comment|/* 1024x768 @ 60Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_1024_768_70
value|0x0004
end_define

begin_comment
comment|/* 1024x768 @ 70Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_1024_768_75
value|0x0002
end_define

begin_comment
comment|/* 1024x768 @ 75Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_EST_TIMING_1280_1024_75
value|0x0001
end_define

begin_comment
comment|/* 1280x1024 @ 75Hz */
end_comment

begin_comment
comment|/*  * N.B.: ptr is relative to standard timing block - used for standard timing  * descriptors as well as standard timings section of edid!  */
end_comment

begin_define
define|#
directive|define
name|EDID_STD_TIMING_HRES
parameter_list|(
name|ptr
parameter_list|)
value|((((ptr)[0]) * 8) + 248)
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_VFREQ
parameter_list|(
name|ptr
parameter_list|)
value|((((ptr)[1])& 0x3f) + 60)
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_RATIO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[1]& 0xc0)
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_RATIO_16_10
value|0x00
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_RATIO_4_3
value|0x40
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_RATIO_5_4
value|0x80
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_RATIO_16_9
value|0xc0
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|EDID_STD_TIMING_COUNT
value|8
end_define

begin_comment
comment|/*  * N.B.: ptr is relative to descriptor block start  */
end_comment

begin_define
define|#
directive|define
name|EDID_BLOCK_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|EDID_BLOCK_COUNT
value|4
end_define

begin_comment
comment|/* detailed timing block.... what a mess */
end_comment

begin_define
define|#
directive|define
name|EDID_BLOCK_IS_DET_TIMING
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[0] | (ptr)[1])
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_DOT_CLOCK
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[0] | ((ptr)[1]<< 8)) * 10000)
end_define

begin_define
define|#
directive|define
name|_HACT_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[2])
end_define

begin_define
define|#
directive|define
name|_HBLK_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[3])
end_define

begin_define
define|#
directive|define
name|_HACT_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[4]& 0xf0)<< 4)
end_define

begin_define
define|#
directive|define
name|_HBLK_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[4]& 0x0f)<< 8)
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HACTIVE
parameter_list|(
name|ptr
parameter_list|)
value|(_HACT_LO(ptr) | _HACT_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HBLANK
parameter_list|(
name|ptr
parameter_list|)
value|(_HBLK_LO(ptr) | _HBLK_HI(ptr))
end_define

begin_define
define|#
directive|define
name|_VACT_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[5])
end_define

begin_define
define|#
directive|define
name|_VBLK_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[6])
end_define

begin_define
define|#
directive|define
name|_VACT_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[7]& 0xf0)<< 4)
end_define

begin_define
define|#
directive|define
name|_VBLK_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[7]& 0x0f)<< 8)
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VACTIVE
parameter_list|(
name|ptr
parameter_list|)
value|(_VACT_LO(ptr) | _VACT_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VBLANK
parameter_list|(
name|ptr
parameter_list|)
value|(_VBLK_LO(ptr) | _VBLK_HI(ptr))
end_define

begin_define
define|#
directive|define
name|_HOFF_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[8])
end_define

begin_define
define|#
directive|define
name|_HWID_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[9])
end_define

begin_define
define|#
directive|define
name|_VOFF_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[10]>> 4)
end_define

begin_define
define|#
directive|define
name|_VWID_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[10]& 0xf)
end_define

begin_define
define|#
directive|define
name|_HOFF_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[11]& 0xc0)<< 2)
end_define

begin_define
define|#
directive|define
name|_HWID_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[11]& 0x30)<< 4)
end_define

begin_define
define|#
directive|define
name|_VOFF_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[11]& 0x0c)<< 2)
end_define

begin_define
define|#
directive|define
name|_VWID_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[11]& 0x03)<< 4)
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HSYNC_OFFSET
parameter_list|(
name|ptr
parameter_list|)
value|(_HOFF_LO(ptr) | _HOFF_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HSYNC_WIDTH
parameter_list|(
name|ptr
parameter_list|)
value|(_HWID_LO(ptr) | _HWID_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VSYNC_OFFSET
parameter_list|(
name|ptr
parameter_list|)
value|(_VOFF_LO(ptr) | _VOFF_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VSYNC_WIDTH
parameter_list|(
name|ptr
parameter_list|)
value|(_VWID_LO(ptr) | _VWID_HI(ptr))
end_define

begin_define
define|#
directive|define
name|_HSZ_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[12])
end_define

begin_define
define|#
directive|define
name|_VSZ_LO
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[13])
end_define

begin_define
define|#
directive|define
name|_HSZ_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[14]& 0xf0)<< 4)
end_define

begin_define
define|#
directive|define
name|_VSZ_HI
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[14]& 0x0f)<< 8)
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HSIZE
parameter_list|(
name|ptr
parameter_list|)
value|(_HSZ_LO(ptr) | _HSZ_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VSIZE
parameter_list|(
name|ptr
parameter_list|)
value|(_VSZ_LO(ptr) | _VSZ_HI(ptr))
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_HBORDER
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[15])
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_VBORDER
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[16])
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAGS
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[17])
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_INTERLACE
value|0x80
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_STEREO
value|0x60
end_define

begin_comment
comment|/* stereo or not */
end_comment

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_SYNC_SEPARATE
value|0x18
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_VSYNC_POSITIVE
value|0x04
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_HSYNC_POSITIVE
value|0x02
end_define

begin_define
define|#
directive|define
name|EDID_DET_TIMING_FLAG_STEREO_MODE
value|0x01
end_define

begin_comment
comment|/* stereo mode */
end_comment

begin_comment
comment|/* N.B.: these tests assume that we already checked for detailed timing! */
end_comment

begin_define
define|#
directive|define
name|EDID_BLOCK_TYPE
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[3])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_SIZE
value|18
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_SERIAL
value|0xFF
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_ASCII
value|0xFE
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_RANGE
value|0xFD
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_NAME
value|0xFC
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_COLOR_POINT
value|0xFB
end_define

begin_define
define|#
directive|define
name|EDID_DESC_BLOCK_TYPE_STD_TIMING
value|0xFA
end_define

begin_comment
comment|/* used for descriptors 0xFF, 0xFE, and 0xFC */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_ASCII_DATA_OFFSET
value|5
end_define

begin_define
define|#
directive|define
name|EDID_DESC_ASCII_DATA_LEN
value|13
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_MIN_VFREQ
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[5])
end_define

begin_comment
comment|/* Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_MAX_VFREQ
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[6])
end_define

begin_comment
comment|/* Hz */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_MIN_HFREQ
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[7])
end_define

begin_comment
comment|/* kHz */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_MAX_HFREQ
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[8])
end_define

begin_comment
comment|/* kHz */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_MAX_CLOCK
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[9]) * 10)
end_define

begin_comment
comment|/* MHz */
end_comment

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_HAVE_GTF2
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[10]) == 0x02)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_GTF2_HFREQ
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[12]) * 2)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_GTF2_C
parameter_list|(
name|ptr
parameter_list|)
value|(((ptr)[13]) / 2)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_GTF2_M
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[14] + ((ptr)[15]<< 8))
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_GTF2_K
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[16])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_RANGE_GTF2_J
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[17] / 2)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITEX
parameter_list|(
name|ptr
parameter_list|)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITE_INDEX_1
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[5])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITEX_1
parameter_list|(
name|ptr
parameter_list|)
value|_CHROMA(ptr, 6, 2, 7)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITEY_1
parameter_list|(
name|ptr
parameter_list|)
value|_CHROMA(ptr, 6, 0, 8)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_GAMMA_1
parameter_list|(
name|ptr
parameter_list|)
value|_GAMMA(ptr[9])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITE_INDEX_2
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[10])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITEX_2
parameter_list|(
name|ptr
parameter_list|)
value|_CHROMA(ptr, 11, 2, 12)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_WHITEY_2
parameter_list|(
name|ptr
parameter_list|)
value|_CHROMA(ptr, 11, 0, 13)
end_define

begin_define
define|#
directive|define
name|EDID_DESC_COLOR_GAMMA_2
parameter_list|(
name|ptr
parameter_list|)
value|_GAMMA(ptr[14])
end_define

begin_define
define|#
directive|define
name|EDID_DESC_STD_TIMING_START
value|5
end_define

begin_define
define|#
directive|define
name|EDID_DESC_STD_TIMING_COUNT
value|6
end_define

begin_define
define|#
directive|define
name|EDID_EXT_BLOCK_COUNT
parameter_list|(
name|ptr
parameter_list|)
value|((ptr)[126])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_VIDEOMODE_EDIDREG_H */
end_comment

end_unit

