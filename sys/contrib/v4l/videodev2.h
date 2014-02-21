begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Video for Linux Two header file  *  *  Copyright (C) 1999-2007 the contributors  *  *  This program is free software; you can redistribute it and/or modify  *  it under the terms of the GNU General Public License as published by  *  the Free Software Foundation; either version 2 of the License, or  *  (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *  GNU General Public License for more details.  *  *  Alternatively you can redistribute this file under the terms of the  *  BSD license as stated below:  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  3. The names of its contributors may not be used to endorse or promote  *     products derived from this software without specific prior written  *     permission.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  *  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  *  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  *  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  *  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	Header file for v4l or V4L2 drivers and applications  * with public API.  * All kernel-specific stuff were moved to media/v4l2-dev.h, so  * no #if __KERNEL tests are allowed here  *  *	See http://linuxtv.org for more info  *  *	Author: Bill Dirks<bill@thedirks.org>  *		Justin Schoeman  *              Hans Verkuil<hverkuil@xs4all.nl>  *		et al.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LINUX_VIDEODEV2_H
end_ifndef

begin_define
define|#
directive|define
name|__LINUX_VIDEODEV2_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|__user
end_define

begin_typedef
typedef|typedef
name|uint64_t
name|__u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|__s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__le32
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_include
include|#
directive|include
file|<linux/time.h>
end_include

begin_comment
comment|/* need struct timeval */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<linux/compiler.h>
end_include

begin_include
include|#
directive|include
file|<linux/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Common stuff for both V4L1 and V4L2  * Moved from videodev.h  */
end_comment

begin_define
define|#
directive|define
name|VIDEO_MAX_FRAME
value|32
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_comment
comment|/* These defines are V4L1 specific and should not be used with the V4L2 API!    They will be removed from this header in the future. */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_CAPTURE
value|1
end_define

begin_comment
comment|/* Can capture */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_TUNER
value|2
end_define

begin_comment
comment|/* Can tune */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_TELETEXT
value|4
end_define

begin_comment
comment|/* Does teletext */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_OVERLAY
value|8
end_define

begin_comment
comment|/* Overlay onto frame buffer */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_CHROMAKEY
value|16
end_define

begin_comment
comment|/* Overlay by chromakey */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_CLIPPING
value|32
end_define

begin_comment
comment|/* Can clip */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_FRAMERAM
value|64
end_define

begin_comment
comment|/* Uses the frame buffer memory */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_SCALES
value|128
end_define

begin_comment
comment|/* Scalable */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_MONOCHROME
value|256
end_define

begin_comment
comment|/* Monochrome only */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_SUBCAPTURE
value|512
end_define

begin_comment
comment|/* Can capture subareas of the image */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_MPEG_DECODER
value|1024
end_define

begin_comment
comment|/* Can decode MPEG streams */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_MPEG_ENCODER
value|2048
end_define

begin_comment
comment|/* Can encode MPEG streams */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_MJPEG_DECODER
value|4096
end_define

begin_comment
comment|/* Can decode MJPEG streams */
end_comment

begin_define
define|#
directive|define
name|VID_TYPE_MJPEG_ENCODER
value|8192
end_define

begin_comment
comment|/* Can encode MJPEG streams */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	M I S C E L L A N E O U S  */
end_comment

begin_comment
comment|/*  Four-character-code (FOURCC) */
end_comment

begin_define
define|#
directive|define
name|v4l2_fourcc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|((__u32)(a) | ((__u32)(b)<< 8) | ((__u32)(c)<< 16) | ((__u32)(d)<< 24))
end_define

begin_comment
comment|/*  *	E N U M S  */
end_comment

begin_enum
enum|enum
name|v4l2_field
block|{
name|V4L2_FIELD_ANY
init|=
literal|0
block|,
comment|/* driver can choose from none, 					 top, bottom, interlaced 					 depending on whatever it thinks 					 is approximate ... */
name|V4L2_FIELD_NONE
init|=
literal|1
block|,
comment|/* this device has no fields ... */
name|V4L2_FIELD_TOP
init|=
literal|2
block|,
comment|/* top field only */
name|V4L2_FIELD_BOTTOM
init|=
literal|3
block|,
comment|/* bottom field only */
name|V4L2_FIELD_INTERLACED
init|=
literal|4
block|,
comment|/* both fields interlaced */
name|V4L2_FIELD_SEQ_TB
init|=
literal|5
block|,
comment|/* both fields sequential into one 					 buffer, top-bottom order */
name|V4L2_FIELD_SEQ_BT
init|=
literal|6
block|,
comment|/* same as above + bottom-top order */
name|V4L2_FIELD_ALTERNATE
init|=
literal|7
block|,
comment|/* both fields alternating into 					 separate buffers */
name|V4L2_FIELD_INTERLACED_TB
init|=
literal|8
block|,
comment|/* both fields interlaced, top field 					 first and the top field is 					 transmitted first */
name|V4L2_FIELD_INTERLACED_BT
init|=
literal|9
block|,
comment|/* both fields interlaced, top field 					 first and the bottom field is 					 transmitted first */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_FIELD_HAS_TOP
parameter_list|(
name|field
parameter_list|)
define|\
value|((field) == V4L2_FIELD_TOP 	||\ 	 (field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_INTERLACED_TB ||\ 	 (field) == V4L2_FIELD_INTERLACED_BT ||\ 	 (field) == V4L2_FIELD_SEQ_TB	||\ 	 (field) == V4L2_FIELD_SEQ_BT)
end_define

begin_define
define|#
directive|define
name|V4L2_FIELD_HAS_BOTTOM
parameter_list|(
name|field
parameter_list|)
define|\
value|((field) == V4L2_FIELD_BOTTOM 	||\ 	 (field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_INTERLACED_TB ||\ 	 (field) == V4L2_FIELD_INTERLACED_BT ||\ 	 (field) == V4L2_FIELD_SEQ_TB	||\ 	 (field) == V4L2_FIELD_SEQ_BT)
end_define

begin_define
define|#
directive|define
name|V4L2_FIELD_HAS_BOTH
parameter_list|(
name|field
parameter_list|)
define|\
value|((field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_INTERLACED_TB ||\ 	 (field) == V4L2_FIELD_INTERLACED_BT ||\ 	 (field) == V4L2_FIELD_SEQ_TB ||\ 	 (field) == V4L2_FIELD_SEQ_BT)
end_define

begin_enum
enum|enum
name|v4l2_buf_type
block|{
name|V4L2_BUF_TYPE_VIDEO_CAPTURE
init|=
literal|1
block|,
name|V4L2_BUF_TYPE_VIDEO_OUTPUT
init|=
literal|2
block|,
name|V4L2_BUF_TYPE_VIDEO_OVERLAY
init|=
literal|3
block|,
name|V4L2_BUF_TYPE_VBI_CAPTURE
init|=
literal|4
block|,
name|V4L2_BUF_TYPE_VBI_OUTPUT
init|=
literal|5
block|,
name|V4L2_BUF_TYPE_SLICED_VBI_CAPTURE
init|=
literal|6
block|,
name|V4L2_BUF_TYPE_SLICED_VBI_OUTPUT
init|=
literal|7
block|,
if|#
directive|if
literal|1
comment|/* Experimental */
name|V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY
init|=
literal|8
block|,
endif|#
directive|endif
name|V4L2_BUF_TYPE_PRIVATE
init|=
literal|0x80
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_ctrl_type
block|{
name|V4L2_CTRL_TYPE_INTEGER
init|=
literal|1
block|,
name|V4L2_CTRL_TYPE_BOOLEAN
init|=
literal|2
block|,
name|V4L2_CTRL_TYPE_MENU
init|=
literal|3
block|,
name|V4L2_CTRL_TYPE_BUTTON
init|=
literal|4
block|,
name|V4L2_CTRL_TYPE_INTEGER64
init|=
literal|5
block|,
name|V4L2_CTRL_TYPE_CTRL_CLASS
init|=
literal|6
block|,
name|V4L2_CTRL_TYPE_STRING
init|=
literal|7
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_tuner_type
block|{
name|V4L2_TUNER_RADIO
init|=
literal|1
block|,
name|V4L2_TUNER_ANALOG_TV
init|=
literal|2
block|,
name|V4L2_TUNER_DIGITAL_TV
init|=
literal|3
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_memory
block|{
name|V4L2_MEMORY_MMAP
init|=
literal|1
block|,
name|V4L2_MEMORY_USERPTR
init|=
literal|2
block|,
name|V4L2_MEMORY_OVERLAY
init|=
literal|3
block|, }
enum|;
end_enum

begin_comment
comment|/* see also http://vektor.theorem.ca/graphics/ycbcr/ */
end_comment

begin_enum
enum|enum
name|v4l2_colorspace
block|{
comment|/* ITU-R 601 -- broadcast NTSC/PAL */
name|V4L2_COLORSPACE_SMPTE170M
init|=
literal|1
block|,
comment|/* 1125-Line (US) HDTV */
name|V4L2_COLORSPACE_SMPTE240M
init|=
literal|2
block|,
comment|/* HD and modern captures. */
name|V4L2_COLORSPACE_REC709
init|=
literal|3
block|,
comment|/* broken BT878 extents (601, luma range 16-253 instead of 16-235) */
name|V4L2_COLORSPACE_BT878
init|=
literal|4
block|,
comment|/* These should be useful.  Assume 601 extents. */
name|V4L2_COLORSPACE_470_SYSTEM_M
init|=
literal|5
block|,
name|V4L2_COLORSPACE_470_SYSTEM_BG
init|=
literal|6
block|,
comment|/* I know there will be cameras that send this.  So, this is 	 * unspecified chromaticities and full 0-255 on each of the 	 * Y'CbCr components 	 */
name|V4L2_COLORSPACE_JPEG
init|=
literal|7
block|,
comment|/* For RGB colourspaces, this is probably a good start. */
name|V4L2_COLORSPACE_SRGB
init|=
literal|8
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_priority
block|{
name|V4L2_PRIORITY_UNSET
init|=
literal|0
block|,
comment|/* not initialized */
name|V4L2_PRIORITY_BACKGROUND
init|=
literal|1
block|,
name|V4L2_PRIORITY_INTERACTIVE
init|=
literal|2
block|,
name|V4L2_PRIORITY_RECORD
init|=
literal|3
block|,
name|V4L2_PRIORITY_DEFAULT
init|=
name|V4L2_PRIORITY_INTERACTIVE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|v4l2_rect
block|{
name|__s32
name|left
decl_stmt|;
name|__s32
name|top
decl_stmt|;
name|__s32
name|width
decl_stmt|;
name|__s32
name|height
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_fract
block|{
name|__u32
name|numerator
decl_stmt|;
name|__u32
name|denominator
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	D R I V E R   C A P A B I L I T I E S  */
end_comment

begin_struct
struct|struct
name|v4l2_capability
block|{
name|__u8
name|driver
index|[
literal|16
index|]
decl_stmt|;
comment|/* i.e. "bttv" */
name|__u8
name|card
index|[
literal|32
index|]
decl_stmt|;
comment|/* i.e. "Hauppauge WinTV" */
name|__u8
name|bus_info
index|[
literal|32
index|]
decl_stmt|;
comment|/* "PCI:" + pci_name(pci_dev) */
name|__u32
name|version
decl_stmt|;
comment|/* should use KERNEL_VERSION() */
name|__u32
name|capabilities
decl_stmt|;
comment|/* Device capabilities */
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Values for 'capabilities' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VIDEO_CAPTURE
value|0x00000001
end_define

begin_comment
comment|/* Is a video capture device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VIDEO_OUTPUT
value|0x00000002
end_define

begin_comment
comment|/* Is a video output device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VIDEO_OVERLAY
value|0x00000004
end_define

begin_comment
comment|/* Can do video overlay */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VBI_CAPTURE
value|0x00000010
end_define

begin_comment
comment|/* Is a raw VBI capture device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VBI_OUTPUT
value|0x00000020
end_define

begin_comment
comment|/* Is a raw VBI output device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_SLICED_VBI_CAPTURE
value|0x00000040
end_define

begin_comment
comment|/* Is a sliced VBI capture device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_SLICED_VBI_OUTPUT
value|0x00000080
end_define

begin_comment
comment|/* Is a sliced VBI output device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_RDS_CAPTURE
value|0x00000100
end_define

begin_comment
comment|/* RDS data capture */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_VIDEO_OUTPUT_OVERLAY
value|0x00000200
end_define

begin_comment
comment|/* Can do video output overlay */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_HW_FREQ_SEEK
value|0x00000400
end_define

begin_comment
comment|/* Can do hardware frequency seek  */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_RDS_OUTPUT
value|0x00000800
end_define

begin_comment
comment|/* Is an RDS encoder */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_TUNER
value|0x00010000
end_define

begin_comment
comment|/* has a tuner */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_AUDIO
value|0x00020000
end_define

begin_comment
comment|/* has audio support */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_RADIO
value|0x00040000
end_define

begin_comment
comment|/* is a radio device */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_MODULATOR
value|0x00080000
end_define

begin_comment
comment|/* has a modulator */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_READWRITE
value|0x01000000
end_define

begin_comment
comment|/* read/write systemcalls */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_ASYNCIO
value|0x02000000
end_define

begin_comment
comment|/* async I/O */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_STREAMING
value|0x04000000
end_define

begin_comment
comment|/* streaming I/O ioctls */
end_comment

begin_comment
comment|/*  *	V I D E O   I M A G E   F O R M A T  */
end_comment

begin_struct
struct|struct
name|v4l2_pix_format
block|{
name|__u32
name|width
decl_stmt|;
name|__u32
name|height
decl_stmt|;
name|__u32
name|pixelformat
decl_stmt|;
name|enum
name|v4l2_field
name|field
decl_stmt|;
name|__u32
name|bytesperline
decl_stmt|;
comment|/* for padding, zero if unused */
name|__u32
name|sizeimage
decl_stmt|;
name|enum
name|v4l2_colorspace
name|colorspace
decl_stmt|;
name|__u32
name|priv
decl_stmt|;
comment|/* private data, depends on pixelformat */
block|}
struct|;
end_struct

begin_comment
comment|/*      Pixel format         FOURCC                          depth  Description  */
end_comment

begin_comment
comment|/* RGB formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB332
value|v4l2_fourcc('R', 'G', 'B', '1')
end_define

begin_comment
comment|/*  8  RGB-3-3-2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB444
value|v4l2_fourcc('R', '4', '4', '4')
end_define

begin_comment
comment|/* 16  xxxxrrrr ggggbbbb */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB555
value|v4l2_fourcc('R', 'G', 'B', 'O')
end_define

begin_comment
comment|/* 16  RGB-5-5-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB565
value|v4l2_fourcc('R', 'G', 'B', 'P')
end_define

begin_comment
comment|/* 16  RGB-5-6-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB555X
value|v4l2_fourcc('R', 'G', 'B', 'Q')
end_define

begin_comment
comment|/* 16  RGB-5-5-5 BE  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB565X
value|v4l2_fourcc('R', 'G', 'B', 'R')
end_define

begin_comment
comment|/* 16  RGB-5-6-5 BE  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_BGR24
value|v4l2_fourcc('B', 'G', 'R', '3')
end_define

begin_comment
comment|/* 24  BGR-8-8-8     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB24
value|v4l2_fourcc('R', 'G', 'B', '3')
end_define

begin_comment
comment|/* 24  RGB-8-8-8     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_BGR32
value|v4l2_fourcc('B', 'G', 'R', '4')
end_define

begin_comment
comment|/* 32  BGR-8-8-8-8   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB32
value|v4l2_fourcc('R', 'G', 'B', '4')
end_define

begin_comment
comment|/* 32  RGB-8-8-8-8   */
end_comment

begin_comment
comment|/* Grey formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_GREY
value|v4l2_fourcc('G', 'R', 'E', 'Y')
end_define

begin_comment
comment|/*  8  Greyscale     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_Y10
value|v4l2_fourcc('Y', '1', '0', ' ')
end_define

begin_comment
comment|/* 10  Greyscale     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_Y16
value|v4l2_fourcc('Y', '1', '6', ' ')
end_define

begin_comment
comment|/* 16  Greyscale     */
end_comment

begin_comment
comment|/* Palette formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PAL8
value|v4l2_fourcc('P', 'A', 'L', '8')
end_define

begin_comment
comment|/*  8  8-bit palette */
end_comment

begin_comment
comment|/* Luminance+Chrominance formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YVU410
value|v4l2_fourcc('Y', 'V', 'U', '9')
end_define

begin_comment
comment|/*  9  YVU 4:1:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YVU420
value|v4l2_fourcc('Y', 'V', '1', '2')
end_define

begin_comment
comment|/* 12  YVU 4:2:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUYV
value|v4l2_fourcc('Y', 'U', 'Y', 'V')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YYUV
value|v4l2_fourcc('Y', 'Y', 'U', 'V')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YVYU
value|v4l2_fourcc('Y', 'V', 'Y', 'U')
end_define

begin_comment
comment|/* 16 YVU 4:2:2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_UYVY
value|v4l2_fourcc('U', 'Y', 'V', 'Y')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_VYUY
value|v4l2_fourcc('V', 'Y', 'U', 'Y')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV422P
value|v4l2_fourcc('4', '2', '2', 'P')
end_define

begin_comment
comment|/* 16  YVU422 planar */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV411P
value|v4l2_fourcc('4', '1', '1', 'P')
end_define

begin_comment
comment|/* 16  YVU411 planar */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_Y41P
value|v4l2_fourcc('Y', '4', '1', 'P')
end_define

begin_comment
comment|/* 12  YUV 4:1:1     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV444
value|v4l2_fourcc('Y', '4', '4', '4')
end_define

begin_comment
comment|/* 16  xxxxyyyy uuuuvvvv */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV555
value|v4l2_fourcc('Y', 'U', 'V', 'O')
end_define

begin_comment
comment|/* 16  YUV-5-5-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV565
value|v4l2_fourcc('Y', 'U', 'V', 'P')
end_define

begin_comment
comment|/* 16  YUV-5-6-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV32
value|v4l2_fourcc('Y', 'U', 'V', '4')
end_define

begin_comment
comment|/* 32  YUV-8-8-8-8   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV410
value|v4l2_fourcc('Y', 'U', 'V', '9')
end_define

begin_comment
comment|/*  9  YUV 4:1:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV420
value|v4l2_fourcc('Y', 'U', '1', '2')
end_define

begin_comment
comment|/* 12  YUV 4:2:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_HI240
value|v4l2_fourcc('H', 'I', '2', '4')
end_define

begin_comment
comment|/*  8  8-bit color   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_HM12
value|v4l2_fourcc('H', 'M', '1', '2')
end_define

begin_comment
comment|/*  8  YUV 4:2:0 16x16 macroblocks */
end_comment

begin_comment
comment|/* two planes -- one Y, one Cr + Cb interleaved  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV12
value|v4l2_fourcc('N', 'V', '1', '2')
end_define

begin_comment
comment|/* 12  Y/CbCr 4:2:0  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV21
value|v4l2_fourcc('N', 'V', '2', '1')
end_define

begin_comment
comment|/* 12  Y/CrCb 4:2:0  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV16
value|v4l2_fourcc('N', 'V', '1', '6')
end_define

begin_comment
comment|/* 16  Y/CbCr 4:2:2  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV61
value|v4l2_fourcc('N', 'V', '6', '1')
end_define

begin_comment
comment|/* 16  Y/CrCb 4:2:2  */
end_comment

begin_comment
comment|/* Bayer formats - see http://www.siliconimaging.com/RGB%20Bayer.htm */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SBGGR8
value|v4l2_fourcc('B', 'A', '8', '1')
end_define

begin_comment
comment|/*  8  BGBG.. GRGR.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SGBRG8
value|v4l2_fourcc('G', 'B', 'R', 'G')
end_define

begin_comment
comment|/*  8  GBGB.. RGRG.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SGRBG8
value|v4l2_fourcc('G', 'R', 'B', 'G')
end_define

begin_comment
comment|/*  8  GRGR.. BGBG.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SRGGB8
value|v4l2_fourcc('R', 'G', 'G', 'B')
end_define

begin_comment
comment|/*  8  RGRG.. GBGB.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SBGGR10
value|v4l2_fourcc('B', 'G', '1', '0')
end_define

begin_comment
comment|/* 10  BGBG.. GRGR.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SGBRG10
value|v4l2_fourcc('G', 'B', '1', '0')
end_define

begin_comment
comment|/* 10  GBGB.. RGRG.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SGRBG10
value|v4l2_fourcc('B', 'A', '1', '0')
end_define

begin_comment
comment|/* 10  GRGR.. BGBG.. */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SRGGB10
value|v4l2_fourcc('R', 'G', '1', '0')
end_define

begin_comment
comment|/* 10  RGRG.. GBGB.. */
end_comment

begin_comment
comment|/* 10bit raw bayer DPCM compressed to 8 bits */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SGRBG10DPCM8
value|v4l2_fourcc('B', 'D', '1', '0')
end_define

begin_comment
comment|/* 	 * 10bit raw bayer, expanded to 16 bits 	 * xxxxrrrrrrrrrrxxxxgggggggggg xxxxggggggggggxxxxbbbbbbbbbb... 	 */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SBGGR16
value|v4l2_fourcc('B', 'Y', 'R', '2')
end_define

begin_comment
comment|/* 16  BGBG.. GRGR.. */
end_comment

begin_comment
comment|/* compressed formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_MJPEG
value|v4l2_fourcc('M', 'J', 'P', 'G')
end_define

begin_comment
comment|/* Motion-JPEG   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_JPEG
value|v4l2_fourcc('J', 'P', 'E', 'G')
end_define

begin_comment
comment|/* JFIF JPEG     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_DV
value|v4l2_fourcc('d', 'v', 's', 'd')
end_define

begin_comment
comment|/* 1394          */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_MPEG
value|v4l2_fourcc('M', 'P', 'E', 'G')
end_define

begin_comment
comment|/* MPEG-1/2/4    */
end_comment

begin_comment
comment|/*  Vendor-specific formats   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_CPIA1
value|v4l2_fourcc('C', 'P', 'I', 'A')
end_define

begin_comment
comment|/* cpia1 YUV */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_WNVA
value|v4l2_fourcc('W', 'N', 'V', 'A')
end_define

begin_comment
comment|/* Winnov hw compress */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SN9C10X
value|v4l2_fourcc('S', '9', '1', '0')
end_define

begin_comment
comment|/* SN9C10x compression */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SN9C20X_I420
value|v4l2_fourcc('S', '9', '2', '0')
end_define

begin_comment
comment|/* SN9C20x YUV 4:2:0 */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PWC1
value|v4l2_fourcc('P', 'W', 'C', '1')
end_define

begin_comment
comment|/* pwc older webcam */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PWC2
value|v4l2_fourcc('P', 'W', 'C', '2')
end_define

begin_comment
comment|/* pwc newer webcam */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_ET61X251
value|v4l2_fourcc('E', '6', '2', '5')
end_define

begin_comment
comment|/* ET61X251 compression */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SPCA501
value|v4l2_fourcc('S', '5', '0', '1')
end_define

begin_comment
comment|/* YUYV per line */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SPCA505
value|v4l2_fourcc('S', '5', '0', '5')
end_define

begin_comment
comment|/* YYUV per line */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SPCA508
value|v4l2_fourcc('S', '5', '0', '8')
end_define

begin_comment
comment|/* YUVY per line */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SPCA561
value|v4l2_fourcc('S', '5', '6', '1')
end_define

begin_comment
comment|/* compressed GBRG bayer */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PAC207
value|v4l2_fourcc('P', '2', '0', '7')
end_define

begin_comment
comment|/* compressed BGGR bayer */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_MR97310A
value|v4l2_fourcc('M', '3', '1', '0')
end_define

begin_comment
comment|/* compressed BGGR bayer */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SN9C2028
value|v4l2_fourcc('S', 'O', 'N', 'X')
end_define

begin_comment
comment|/* compressed GBRG bayer */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SQ905C
value|v4l2_fourcc('9', '0', '5', 'C')
end_define

begin_comment
comment|/* compressed RGGB bayer */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PJPG
value|v4l2_fourcc('P', 'J', 'P', 'G')
end_define

begin_comment
comment|/* Pixart 73xx JPEG */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_OV511
value|v4l2_fourcc('O', '5', '1', '1')
end_define

begin_comment
comment|/* ov511 JPEG */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_OV518
value|v4l2_fourcc('O', '5', '1', '8')
end_define

begin_comment
comment|/* ov518 JPEG */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_STV0680
value|v4l2_fourcc('S', '6', '8', '0')
end_define

begin_comment
comment|/* stv0680 bayer */
end_comment

begin_comment
comment|/*  *	F O R M A T   E N U M E R A T I O N  */
end_comment

begin_struct
struct|struct
name|v4l2_fmtdesc
block|{
name|__u32
name|index
decl_stmt|;
comment|/* Format number      */
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
comment|/* buffer type        */
name|__u32
name|flags
decl_stmt|;
name|__u8
name|description
index|[
literal|32
index|]
decl_stmt|;
comment|/* Description string */
name|__u32
name|pixelformat
decl_stmt|;
comment|/* Format fourcc      */
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|V4L2_FMT_FLAG_COMPRESSED
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_FMT_FLAG_EMULATED
value|0x0002
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* Experimental Frame Size and frame rate enumeration */
end_comment

begin_comment
comment|/*  *	F R A M E   S I Z E   E N U M E R A T I O N  */
end_comment

begin_enum
enum|enum
name|v4l2_frmsizetypes
block|{
name|V4L2_FRMSIZE_TYPE_DISCRETE
init|=
literal|1
block|,
name|V4L2_FRMSIZE_TYPE_CONTINUOUS
init|=
literal|2
block|,
name|V4L2_FRMSIZE_TYPE_STEPWISE
init|=
literal|3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|v4l2_frmsize_discrete
block|{
name|__u32
name|width
decl_stmt|;
comment|/* Frame width [pixel] */
name|__u32
name|height
decl_stmt|;
comment|/* Frame height [pixel] */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_frmsize_stepwise
block|{
name|__u32
name|min_width
decl_stmt|;
comment|/* Minimum frame width [pixel] */
name|__u32
name|max_width
decl_stmt|;
comment|/* Maximum frame width [pixel] */
name|__u32
name|step_width
decl_stmt|;
comment|/* Frame width step size [pixel] */
name|__u32
name|min_height
decl_stmt|;
comment|/* Minimum frame height [pixel] */
name|__u32
name|max_height
decl_stmt|;
comment|/* Maximum frame height [pixel] */
name|__u32
name|step_height
decl_stmt|;
comment|/* Frame height step size [pixel] */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_frmsizeenum
block|{
name|__u32
name|index
decl_stmt|;
comment|/* Frame size number */
name|__u32
name|pixel_format
decl_stmt|;
comment|/* Pixel format */
name|__u32
name|type
decl_stmt|;
comment|/* Frame size type the device supports. */
union|union
block|{
comment|/* Frame size */
name|struct
name|v4l2_frmsize_discrete
name|discrete
decl_stmt|;
name|struct
name|v4l2_frmsize_stepwise
name|stepwise
decl_stmt|;
block|}
name|x
union|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved space for future use */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	F R A M E   R A T E   E N U M E R A T I O N  */
end_comment

begin_enum
enum|enum
name|v4l2_frmivaltypes
block|{
name|V4L2_FRMIVAL_TYPE_DISCRETE
init|=
literal|1
block|,
name|V4L2_FRMIVAL_TYPE_CONTINUOUS
init|=
literal|2
block|,
name|V4L2_FRMIVAL_TYPE_STEPWISE
init|=
literal|3
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|v4l2_frmival_stepwise
block|{
name|struct
name|v4l2_fract
name|min
decl_stmt|;
comment|/* Minimum frame interval [s] */
name|struct
name|v4l2_fract
name|max
decl_stmt|;
comment|/* Maximum frame interval [s] */
name|struct
name|v4l2_fract
name|step
decl_stmt|;
comment|/* Frame interval step size [s] */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_frmivalenum
block|{
name|__u32
name|index
decl_stmt|;
comment|/* Frame format index */
name|__u32
name|pixel_format
decl_stmt|;
comment|/* Pixel format */
name|__u32
name|width
decl_stmt|;
comment|/* Frame width */
name|__u32
name|height
decl_stmt|;
comment|/* Frame height */
name|__u32
name|type
decl_stmt|;
comment|/* Frame interval type the device supports. */
union|union
block|{
comment|/* Frame interval */
name|struct
name|v4l2_fract
name|discrete
decl_stmt|;
name|struct
name|v4l2_frmival_stepwise
name|stepwise
decl_stmt|;
block|}
name|x
union|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved space for future use */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	T I M E C O D E  */
end_comment

begin_struct
struct|struct
name|v4l2_timecode
block|{
name|__u32
name|type
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u8
name|frames
decl_stmt|;
name|__u8
name|seconds
decl_stmt|;
name|__u8
name|minutes
decl_stmt|;
name|__u8
name|hours
decl_stmt|;
name|__u8
name|userbits
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Type  */
end_comment

begin_define
define|#
directive|define
name|V4L2_TC_TYPE_24FPS
value|1
end_define

begin_define
define|#
directive|define
name|V4L2_TC_TYPE_25FPS
value|2
end_define

begin_define
define|#
directive|define
name|V4L2_TC_TYPE_30FPS
value|3
end_define

begin_define
define|#
directive|define
name|V4L2_TC_TYPE_50FPS
value|4
end_define

begin_define
define|#
directive|define
name|V4L2_TC_TYPE_60FPS
value|5
end_define

begin_comment
comment|/*  Flags  */
end_comment

begin_define
define|#
directive|define
name|V4L2_TC_FLAG_DROPFRAME
value|0x0001
end_define

begin_comment
comment|/* "drop-frame" mode */
end_comment

begin_define
define|#
directive|define
name|V4L2_TC_FLAG_COLORFRAME
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_TC_USERBITS_field
value|0x000C
end_define

begin_define
define|#
directive|define
name|V4L2_TC_USERBITS_USERDEFINED
value|0x0000
end_define

begin_define
define|#
directive|define
name|V4L2_TC_USERBITS_8BITCHARS
value|0x0008
end_define

begin_comment
comment|/* The above is based on SMPTE timecodes */
end_comment

begin_struct
struct|struct
name|v4l2_jpegcompression
block|{
name|int
name|quality
decl_stmt|;
name|int
name|APPn
decl_stmt|;
comment|/* Number of APP segment to be written, 				 * must be 0..15 */
name|int
name|APP_len
decl_stmt|;
comment|/* Length of data in JPEG APPn segment */
name|char
name|APP_data
index|[
literal|60
index|]
decl_stmt|;
comment|/* Data in the JPEG APPn segment. */
name|int
name|COM_len
decl_stmt|;
comment|/* Length of data in JPEG COM segment */
name|char
name|COM_data
index|[
literal|60
index|]
decl_stmt|;
comment|/* Data in JPEG COM segment */
name|__u32
name|jpeg_markers
decl_stmt|;
comment|/* Which markers should go into the JPEG 				 * output. Unless you exactly know what 				 * you do, leave them untouched. 				 * Inluding less markers will make the 				 * resulting code smaller, but there will 				 * be fewer applications which can read it. 				 * The presence of the APP and COM marker 				 * is influenced by APP_len and COM_len 				 * ONLY, not by this property! */
define|#
directive|define
name|V4L2_JPEG_MARKER_DHT
value|(1<<3)
comment|/* Define Huffman Tables */
define|#
directive|define
name|V4L2_JPEG_MARKER_DQT
value|(1<<4)
comment|/* Define Quantization Tables */
define|#
directive|define
name|V4L2_JPEG_MARKER_DRI
value|(1<<5)
comment|/* Define Restart Interval */
define|#
directive|define
name|V4L2_JPEG_MARKER_COM
value|(1<<6)
comment|/* Comment segment */
define|#
directive|define
name|V4L2_JPEG_MARKER_APP
value|(1<<7)
comment|/* App segment, driver will 					* allways use APP0 */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	M E M O R Y - M A P P I N G   B U F F E R S  */
end_comment

begin_struct
struct|struct
name|v4l2_requestbuffers
block|{
name|__u32
name|count
decl_stmt|;
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
name|enum
name|v4l2_memory
name|memory
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_buffer
block|{
name|__u32
name|index
decl_stmt|;
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
name|__u32
name|bytesused
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|enum
name|v4l2_field
name|field
decl_stmt|;
name|struct
name|timeval
name|timestamp
decl_stmt|;
name|struct
name|v4l2_timecode
name|timecode
decl_stmt|;
name|__u32
name|sequence
decl_stmt|;
comment|/* memory location */
name|enum
name|v4l2_memory
name|memory
decl_stmt|;
union|union
block|{
name|__u32
name|offset
decl_stmt|;
name|unsigned
name|long
name|userptr
decl_stmt|;
block|}
name|m
union|;
name|__u32
name|length
decl_stmt|;
name|__u32
name|input
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for 'flags' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_MAPPED
value|0x0001
end_define

begin_comment
comment|/* Buffer is mapped (flag) */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_QUEUED
value|0x0002
end_define

begin_comment
comment|/* Buffer is queued for processing */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_DONE
value|0x0004
end_define

begin_comment
comment|/* Buffer is ready */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_KEYFRAME
value|0x0008
end_define

begin_comment
comment|/* Image is a keyframe (I-frame) */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_PFRAME
value|0x0010
end_define

begin_comment
comment|/* Image is a P-frame */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_BFRAME
value|0x0020
end_define

begin_comment
comment|/* Image is a B-frame */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_TIMECODE
value|0x0100
end_define

begin_comment
comment|/* timecode field is valid */
end_comment

begin_define
define|#
directive|define
name|V4L2_BUF_FLAG_INPUT
value|0x0200
end_define

begin_comment
comment|/* input field is valid */
end_comment

begin_comment
comment|/*  *	O V E R L A Y   P R E V I E W  */
end_comment

begin_struct
struct|struct
name|v4l2_framebuffer
block|{
name|__u32
name|capability
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
comment|/* FIXME: in theory we should pass something like PCI device + memory  * region + offset instead of some physical address */
name|void
modifier|*
name|base
decl_stmt|;
name|struct
name|v4l2_pix_format
name|fmt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for the 'capability' field. Read only */
end_comment

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_EXTERNOVERLAY
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_CHROMAKEY
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_LIST_CLIPPING
value|0x0004
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_BITMAP_CLIPPING
value|0x0008
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_LOCAL_ALPHA
value|0x0010
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_GLOBAL_ALPHA
value|0x0020
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_LOCAL_INV_ALPHA
value|0x0040
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_CAP_SRC_CHROMAKEY
value|0x0080
end_define

begin_comment
comment|/*  Flags for the 'flags' field. */
end_comment

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_PRIMARY
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_OVERLAY
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_CHROMAKEY
value|0x0004
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_LOCAL_ALPHA
value|0x0008
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_GLOBAL_ALPHA
value|0x0010
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_LOCAL_INV_ALPHA
value|0x0020
end_define

begin_define
define|#
directive|define
name|V4L2_FBUF_FLAG_SRC_CHROMAKEY
value|0x0040
end_define

begin_struct
struct|struct
name|v4l2_clip
block|{
name|struct
name|v4l2_rect
name|c
decl_stmt|;
name|struct
name|v4l2_clip
name|__user
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_window
block|{
name|struct
name|v4l2_rect
name|w
decl_stmt|;
name|enum
name|v4l2_field
name|field
decl_stmt|;
name|__u32
name|chromakey
decl_stmt|;
name|struct
name|v4l2_clip
name|__user
modifier|*
name|clips
decl_stmt|;
name|__u32
name|clipcount
decl_stmt|;
name|void
name|__user
modifier|*
name|bitmap
decl_stmt|;
name|__u8
name|global_alpha
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	C A P T U R E   P A R A M E T E R S  */
end_comment

begin_struct
struct|struct
name|v4l2_captureparm
block|{
name|__u32
name|capability
decl_stmt|;
comment|/*  Supported modes */
name|__u32
name|capturemode
decl_stmt|;
comment|/*  Current mode */
name|struct
name|v4l2_fract
name|timeperframe
decl_stmt|;
comment|/*  Time per frame in .1us units */
name|__u32
name|extendedmode
decl_stmt|;
comment|/*  Driver-specific extensions */
name|__u32
name|readbuffers
decl_stmt|;
comment|/*  # of buffers for read */
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for 'capability' and 'capturemode' fields */
end_comment

begin_define
define|#
directive|define
name|V4L2_MODE_HIGHQUALITY
value|0x0001
end_define

begin_comment
comment|/*  High quality imaging mode */
end_comment

begin_define
define|#
directive|define
name|V4L2_CAP_TIMEPERFRAME
value|0x1000
end_define

begin_comment
comment|/*  timeperframe field is supported */
end_comment

begin_struct
struct|struct
name|v4l2_outputparm
block|{
name|__u32
name|capability
decl_stmt|;
comment|/*  Supported modes */
name|__u32
name|outputmode
decl_stmt|;
comment|/*  Current mode */
name|struct
name|v4l2_fract
name|timeperframe
decl_stmt|;
comment|/*  Time per frame in seconds */
name|__u32
name|extendedmode
decl_stmt|;
comment|/*  Driver-specific extensions */
name|__u32
name|writebuffers
decl_stmt|;
comment|/*  # of buffers for write */
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	I N P U T   I M A G E   C R O P P I N G  */
end_comment

begin_struct
struct|struct
name|v4l2_cropcap
block|{
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
name|struct
name|v4l2_rect
name|bounds
decl_stmt|;
name|struct
name|v4l2_rect
name|defrect
decl_stmt|;
name|struct
name|v4l2_fract
name|pixelaspect
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_crop
block|{
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
name|struct
name|v4l2_rect
name|c
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *      A N A L O G   V I D E O   S T A N D A R D  */
end_comment

begin_typedef
typedef|typedef
name|__u64
name|v4l2_std_id
typedef|;
end_typedef

begin_comment
comment|/* one bit for each */
end_comment

begin_define
define|#
directive|define
name|V4L2_STD_PAL_B
value|((v4l2_std_id)0x00000001)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_B1
value|((v4l2_std_id)0x00000002)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_G
value|((v4l2_std_id)0x00000004)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_H
value|((v4l2_std_id)0x00000008)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_I
value|((v4l2_std_id)0x00000010)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_D
value|((v4l2_std_id)0x00000020)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_D1
value|((v4l2_std_id)0x00000040)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_K
value|((v4l2_std_id)0x00000080)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_M
value|((v4l2_std_id)0x00000100)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_N
value|((v4l2_std_id)0x00000200)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_Nc
value|((v4l2_std_id)0x00000400)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_60
value|((v4l2_std_id)0x00000800)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_NTSC_M
value|((v4l2_std_id)0x00001000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_NTSC_M_JP
value|((v4l2_std_id)0x00002000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_NTSC_443
value|((v4l2_std_id)0x00004000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_NTSC_M_KR
value|((v4l2_std_id)0x00008000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_B
value|((v4l2_std_id)0x00010000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_D
value|((v4l2_std_id)0x00020000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_G
value|((v4l2_std_id)0x00040000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_H
value|((v4l2_std_id)0x00080000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_K
value|((v4l2_std_id)0x00100000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_K1
value|((v4l2_std_id)0x00200000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_L
value|((v4l2_std_id)0x00400000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_LC
value|((v4l2_std_id)0x00800000)
end_define

begin_comment
comment|/* ATSC/HDTV */
end_comment

begin_define
define|#
directive|define
name|V4L2_STD_ATSC_8_VSB
value|((v4l2_std_id)0x01000000)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_ATSC_16_VSB
value|((v4l2_std_id)0x02000000)
end_define

begin_comment
comment|/* FIXME:    Although std_id is 64 bits, there is an issue on PPC32 architecture that    makes switch(__u64) to break. So, there's a hack on v4l2-common.c rounding    this value to 32 bits.    As, currently, the max value is for V4L2_STD_ATSC_16_VSB (30 bits wide),    it should work fine. However, if needed to add more than two standards,    v4l2-common.c should be fixed.  */
end_comment

begin_comment
comment|/* some merged standards */
end_comment

begin_define
define|#
directive|define
name|V4L2_STD_MN
value|(V4L2_STD_PAL_M|V4L2_STD_PAL_N|V4L2_STD_PAL_Nc|V4L2_STD_NTSC)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_B
value|(V4L2_STD_PAL_B|V4L2_STD_PAL_B1|V4L2_STD_SECAM_B)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_GH
value|(V4L2_STD_PAL_G|V4L2_STD_PAL_H|V4L2_STD_SECAM_G|V4L2_STD_SECAM_H)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_DK
value|(V4L2_STD_PAL_DK|V4L2_STD_SECAM_DK)
end_define

begin_comment
comment|/* some common needed stuff */
end_comment

begin_define
define|#
directive|define
name|V4L2_STD_PAL_BG
value|(V4L2_STD_PAL_B		|\ 				 V4L2_STD_PAL_B1	|\ 				 V4L2_STD_PAL_G)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL_DK
value|(V4L2_STD_PAL_D		|\ 				 V4L2_STD_PAL_D1	|\ 				 V4L2_STD_PAL_K)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_PAL
value|(V4L2_STD_PAL_BG	|\ 				 V4L2_STD_PAL_DK	|\ 				 V4L2_STD_PAL_H		|\ 				 V4L2_STD_PAL_I)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_NTSC
value|(V4L2_STD_NTSC_M	|\ 				 V4L2_STD_NTSC_M_JP     |\ 				 V4L2_STD_NTSC_M_KR)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM_DK
value|(V4L2_STD_SECAM_D	|\ 				 V4L2_STD_SECAM_K	|\ 				 V4L2_STD_SECAM_K1)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_SECAM
value|(V4L2_STD_SECAM_B	|\ 				 V4L2_STD_SECAM_G	|\ 				 V4L2_STD_SECAM_H	|\ 				 V4L2_STD_SECAM_DK	|\ 				 V4L2_STD_SECAM_L       |\ 				 V4L2_STD_SECAM_LC)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_525_60
value|(V4L2_STD_PAL_M		|\ 				 V4L2_STD_PAL_60	|\ 				 V4L2_STD_NTSC		|\ 				 V4L2_STD_NTSC_443)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_625_50
value|(V4L2_STD_PAL		|\ 				 V4L2_STD_PAL_N		|\ 				 V4L2_STD_PAL_Nc	|\ 				 V4L2_STD_SECAM)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_ATSC
value|(V4L2_STD_ATSC_8_VSB    |\ 				 V4L2_STD_ATSC_16_VSB)
end_define

begin_define
define|#
directive|define
name|V4L2_STD_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|V4L2_STD_ALL
value|(V4L2_STD_525_60	|\ 				 V4L2_STD_625_50)
end_define

begin_struct
struct|struct
name|v4l2_standard
block|{
name|__u32
name|index
decl_stmt|;
name|v4l2_std_id
name|id
decl_stmt|;
name|__u8
name|name
index|[
literal|24
index|]
decl_stmt|;
name|struct
name|v4l2_fract
name|frameperiod
decl_stmt|;
comment|/* Frames, not fields */
name|__u32
name|framelines
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	V I D E O	T I M I N G S	D V	P R E S E T  */
end_comment

begin_struct
struct|struct
name|v4l2_dv_preset
block|{
name|__u32
name|preset
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	D V	P R E S E T S	E N U M E R A T I O N  */
end_comment

begin_struct
struct|struct
name|v4l2_dv_enum_preset
block|{
name|__u32
name|index
decl_stmt|;
name|__u32
name|preset
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Name of the preset timing */
name|__u32
name|width
decl_stmt|;
name|__u32
name|height
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * 	D V	P R E S E T	V A L U E S  */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|V4L2_DV_480P59_94
value|1
end_define

begin_comment
comment|/* BT.1362 */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_576P50
value|2
end_define

begin_comment
comment|/* BT.1362 */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P24
value|3
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P25
value|4
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P30
value|5
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P50
value|6
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P59_94
value|7
end_define

begin_comment
comment|/* SMPTE 274M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_720P60
value|8
end_define

begin_comment
comment|/* SMPTE 274M/296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080I29_97
value|9
end_define

begin_comment
comment|/* BT.1120/ SMPTE 274M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080I30
value|10
end_define

begin_comment
comment|/* BT.1120/ SMPTE 274M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080I25
value|11
end_define

begin_comment
comment|/* BT.1120 */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080I50
value|12
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080I60
value|13
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080P24
value|14
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080P25
value|15
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080P30
value|16
end_define

begin_comment
comment|/* SMPTE 296M */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080P50
value|17
end_define

begin_comment
comment|/* BT.1120 */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_1080P60
value|18
end_define

begin_comment
comment|/* BT.1120 */
end_comment

begin_comment
comment|/*  *	D V 	B T	T I M I N G S  */
end_comment

begin_comment
comment|/* BT.656/BT.1120 timing data */
end_comment

begin_struct
struct|struct
name|v4l2_bt_timings
block|{
name|__u32
name|width
decl_stmt|;
comment|/* width in pixels */
name|__u32
name|height
decl_stmt|;
comment|/* height in lines */
name|__u32
name|interlaced
decl_stmt|;
comment|/* Interlaced or progressive */
name|__u32
name|polarities
decl_stmt|;
comment|/* Positive or negative polarity */
name|__u64
name|pixelclock
decl_stmt|;
comment|/* Pixel clock in HZ. Ex. 74.25MHz->74250000 */
name|__u32
name|hfrontporch
decl_stmt|;
comment|/* Horizpontal front porch in pixels */
name|__u32
name|hsync
decl_stmt|;
comment|/* Horizontal Sync length in pixels */
name|__u32
name|hbackporch
decl_stmt|;
comment|/* Horizontal back porch in pixels */
name|__u32
name|vfrontporch
decl_stmt|;
comment|/* Vertical front porch in pixels */
name|__u32
name|vsync
decl_stmt|;
comment|/* Vertical Sync length in lines */
name|__u32
name|vbackporch
decl_stmt|;
comment|/* Vertical back porch in lines */
name|__u32
name|il_vfrontporch
decl_stmt|;
comment|/* Vertical front porch for bottom field of 				 * interlaced field formats 				 */
name|__u32
name|il_vsync
decl_stmt|;
comment|/* Vertical sync length for bottom field of 				 * interlaced field formats 				 */
name|__u32
name|il_vbackporch
decl_stmt|;
comment|/* Vertical back porch for bottom field of 				 * interlaced field formats 				 */
name|__u32
name|reserved
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
comment|/* Interlaced or progressive format */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_PROGRESSIVE
value|0
end_define

begin_define
define|#
directive|define
name|V4L2_DV_INTERLACED
value|1
end_define

begin_comment
comment|/* Polarities. If bit is not set, it is assumed to be negative polarity */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_VSYNC_POS_POL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|V4L2_DV_HSYNC_POS_POL
value|0x00000002
end_define

begin_comment
comment|/* DV timings */
end_comment

begin_struct
struct|struct
name|v4l2_dv_timings
block|{
name|__u32
name|type
decl_stmt|;
union|union
block|{
name|struct
name|v4l2_bt_timings
name|bt
decl_stmt|;
name|__u32
name|reserved
index|[
literal|32
index|]
decl_stmt|;
block|}
name|x
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

begin_comment
comment|/* Values for the type field */
end_comment

begin_define
define|#
directive|define
name|V4L2_DV_BT_656_1120
value|0
end_define

begin_comment
comment|/* BT.656/1120 timing type */
end_comment

begin_comment
comment|/*  *	V I D E O   I N P U T S  */
end_comment

begin_struct
struct|struct
name|v4l2_input
block|{
name|__u32
name|index
decl_stmt|;
comment|/*  Which input */
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/*  Label */
name|__u32
name|type
decl_stmt|;
comment|/*  Type of input */
name|__u32
name|audioset
decl_stmt|;
comment|/*  Associated audios (bitfield) */
name|__u32
name|tuner
decl_stmt|;
comment|/*  Associated tuner */
name|v4l2_std_id
name|std
decl_stmt|;
name|__u32
name|status
decl_stmt|;
name|__u32
name|capabilities
decl_stmt|;
name|__u32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Values for the 'type' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_INPUT_TYPE_TUNER
value|1
end_define

begin_define
define|#
directive|define
name|V4L2_INPUT_TYPE_CAMERA
value|2
end_define

begin_comment
comment|/* field 'status' - general */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_POWER
value|0x00000001
end_define

begin_comment
comment|/* Attached device is off */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_SIGNAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_COLOR
value|0x00000004
end_define

begin_comment
comment|/* field 'status' - sensor orientation */
end_comment

begin_comment
comment|/* If sensor is mounted upside down set both bits */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_HFLIP
value|0x00000010
end_define

begin_comment
comment|/* Frames are flipped horizontally */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_VFLIP
value|0x00000020
end_define

begin_comment
comment|/* Frames are flipped vertically */
end_comment

begin_comment
comment|/* field 'status' - analog */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_H_LOCK
value|0x00000100
end_define

begin_comment
comment|/* No horizontal sync lock */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_COLOR_KILL
value|0x00000200
end_define

begin_comment
comment|/* Color killer is active */
end_comment

begin_comment
comment|/* field 'status' - digital */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_SYNC
value|0x00010000
end_define

begin_comment
comment|/* No synchronization lock */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_EQU
value|0x00020000
end_define

begin_comment
comment|/* No equalizer lock */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_CARRIER
value|0x00040000
end_define

begin_comment
comment|/* Carrier recovery failed */
end_comment

begin_comment
comment|/* field 'status' - VCR and set-top box */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_MACROVISION
value|0x01000000
end_define

begin_comment
comment|/* Macrovision detected */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_NO_ACCESS
value|0x02000000
end_define

begin_comment
comment|/* Conditional access denied */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_ST_VTR
value|0x04000000
end_define

begin_comment
comment|/* VTR time constant */
end_comment

begin_comment
comment|/* capabilities flags */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_CAP_PRESETS
value|0x00000001
end_define

begin_comment
comment|/* Supports S_DV_PRESET */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_CAP_CUSTOM_TIMINGS
value|0x00000002
end_define

begin_comment
comment|/* Supports S_DV_TIMINGS */
end_comment

begin_define
define|#
directive|define
name|V4L2_IN_CAP_STD
value|0x00000004
end_define

begin_comment
comment|/* Supports S_STD */
end_comment

begin_comment
comment|/*  *	V I D E O   O U T P U T S  */
end_comment

begin_struct
struct|struct
name|v4l2_output
block|{
name|__u32
name|index
decl_stmt|;
comment|/*  Which output */
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/*  Label */
name|__u32
name|type
decl_stmt|;
comment|/*  Type of output */
name|__u32
name|audioset
decl_stmt|;
comment|/*  Associated audios (bitfield) */
name|__u32
name|modulator
decl_stmt|;
comment|/*  Associated modulator */
name|v4l2_std_id
name|std
decl_stmt|;
name|__u32
name|capabilities
decl_stmt|;
name|__u32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Values for the 'type' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_OUTPUT_TYPE_MODULATOR
value|1
end_define

begin_define
define|#
directive|define
name|V4L2_OUTPUT_TYPE_ANALOG
value|2
end_define

begin_define
define|#
directive|define
name|V4L2_OUTPUT_TYPE_ANALOGVGAOVERLAY
value|3
end_define

begin_comment
comment|/* capabilities flags */
end_comment

begin_define
define|#
directive|define
name|V4L2_OUT_CAP_PRESETS
value|0x00000001
end_define

begin_comment
comment|/* Supports S_DV_PRESET */
end_comment

begin_define
define|#
directive|define
name|V4L2_OUT_CAP_CUSTOM_TIMINGS
value|0x00000002
end_define

begin_comment
comment|/* Supports S_DV_TIMINGS */
end_comment

begin_define
define|#
directive|define
name|V4L2_OUT_CAP_STD
value|0x00000004
end_define

begin_comment
comment|/* Supports S_STD */
end_comment

begin_comment
comment|/*  *	C O N T R O L S  */
end_comment

begin_struct
struct|struct
name|v4l2_control
block|{
name|__u32
name|id
decl_stmt|;
name|__s32
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_ext_control
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|size
decl_stmt|;
name|__u32
name|reserved2
index|[
literal|1
index|]
decl_stmt|;
union|union
block|{
name|__s32
name|value
decl_stmt|;
name|__s64
name|value64
decl_stmt|;
name|char
modifier|*
name|string
decl_stmt|;
block|}
name|x
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
name|v4l2_ext_controls
block|{
name|__u32
name|ctrl_class
decl_stmt|;
name|__u32
name|count
decl_stmt|;
name|__u32
name|error_idx
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|v4l2_ext_control
modifier|*
name|controls
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Values for ctrl_class field */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_CLASS_USER
value|0x00980000
end_define

begin_comment
comment|/* Old-style 'user' controls */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_CLASS_MPEG
value|0x00990000
end_define

begin_comment
comment|/* MPEG-compression controls */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_CLASS_CAMERA
value|0x009a0000
end_define

begin_comment
comment|/* Camera class controls */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_CLASS_FM_TX
value|0x009b0000
end_define

begin_comment
comment|/* FM Modulator control class */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_ID_MASK
value|(0x0fffffff)
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_ID2CLASS
parameter_list|(
name|id
parameter_list|)
value|((id)& 0x0fff0000UL)
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_DRIVER_PRIV
parameter_list|(
name|id
parameter_list|)
value|(((id)& 0xffff)>= 0x1000)
end_define

begin_comment
comment|/*  Used in the VIDIOC_QUERYCTRL ioctl for querying controls */
end_comment

begin_struct
struct|struct
name|v4l2_queryctrl
block|{
name|__u32
name|id
decl_stmt|;
name|enum
name|v4l2_ctrl_type
name|type
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Whatever */
name|__s32
name|minimum
decl_stmt|;
comment|/* Note signedness */
name|__s32
name|maximum
decl_stmt|;
name|__s32
name|step
decl_stmt|;
name|__s32
name|default_value
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Used in the VIDIOC_QUERYMENU ioctl for querying menu items */
end_comment

begin_struct
struct|struct
name|v4l2_querymenu
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|index
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
comment|/* Whatever */
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Control flags  */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_DISABLED
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_GRABBED
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_READ_ONLY
value|0x0004
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_UPDATE
value|0x0008
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_INACTIVE
value|0x0010
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_SLIDER
value|0x0020
end_define

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_WRITE_ONLY
value|0x0040
end_define

begin_comment
comment|/*  Query flag, to be ORed with the control ID */
end_comment

begin_define
define|#
directive|define
name|V4L2_CTRL_FLAG_NEXT_CTRL
value|0x80000000
end_define

begin_comment
comment|/*  User-class control IDs defined by V4L2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_BASE
value|(V4L2_CTRL_CLASS_USER | 0x900)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_USER_BASE
value|V4L2_CID_BASE
end_define

begin_comment
comment|/*  IDs reserved for driver specific controls */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_PRIVATE_BASE
value|0x08000000
end_define

begin_define
define|#
directive|define
name|V4L2_CID_USER_CLASS
value|(V4L2_CTRL_CLASS_USER | 1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BRIGHTNESS
value|(V4L2_CID_BASE+0)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_CONTRAST
value|(V4L2_CID_BASE+1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_SATURATION
value|(V4L2_CID_BASE+2)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_HUE
value|(V4L2_CID_BASE+3)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_VOLUME
value|(V4L2_CID_BASE+5)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_BALANCE
value|(V4L2_CID_BASE+6)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_BASS
value|(V4L2_CID_BASE+7)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_TREBLE
value|(V4L2_CID_BASE+8)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_MUTE
value|(V4L2_CID_BASE+9)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_LOUDNESS
value|(V4L2_CID_BASE+10)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BLACK_LEVEL
value|(V4L2_CID_BASE+11)
end_define

begin_comment
comment|/* Deprecated */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_AUTO_WHITE_BALANCE
value|(V4L2_CID_BASE+12)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_DO_WHITE_BALANCE
value|(V4L2_CID_BASE+13)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RED_BALANCE
value|(V4L2_CID_BASE+14)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BLUE_BALANCE
value|(V4L2_CID_BASE+15)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_GAMMA
value|(V4L2_CID_BASE+16)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_WHITENESS
value|(V4L2_CID_GAMMA)
end_define

begin_comment
comment|/* Deprecated */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_EXPOSURE
value|(V4L2_CID_BASE+17)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUTOGAIN
value|(V4L2_CID_BASE+18)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_GAIN
value|(V4L2_CID_BASE+19)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_HFLIP
value|(V4L2_CID_BASE+20)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_VFLIP
value|(V4L2_CID_BASE+21)
end_define

begin_comment
comment|/* Deprecated; use V4L2_CID_PAN_RESET and V4L2_CID_TILT_RESET */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_HCENTER
value|(V4L2_CID_BASE+22)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_VCENTER
value|(V4L2_CID_BASE+23)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_POWER_LINE_FREQUENCY
value|(V4L2_CID_BASE+24)
end_define

begin_enum
enum|enum
name|v4l2_power_line_frequency
block|{
name|V4L2_CID_POWER_LINE_FREQUENCY_DISABLED
init|=
literal|0
block|,
name|V4L2_CID_POWER_LINE_FREQUENCY_50HZ
init|=
literal|1
block|,
name|V4L2_CID_POWER_LINE_FREQUENCY_60HZ
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_HUE_AUTO
value|(V4L2_CID_BASE+25)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_WHITE_BALANCE_TEMPERATURE
value|(V4L2_CID_BASE+26)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_SHARPNESS
value|(V4L2_CID_BASE+27)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BACKLIGHT_COMPENSATION
value|(V4L2_CID_BASE+28)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_CHROMA_AGC
value|(V4L2_CID_BASE+29)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_COLOR_KILLER
value|(V4L2_CID_BASE+30)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_COLORFX
value|(V4L2_CID_BASE+31)
end_define

begin_enum
enum|enum
name|v4l2_colorfx
block|{
name|V4L2_COLORFX_NONE
init|=
literal|0
block|,
name|V4L2_COLORFX_BW
init|=
literal|1
block|,
name|V4L2_COLORFX_SEPIA
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_AUTOBRIGHTNESS
value|(V4L2_CID_BASE+32)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BAND_STOP_FILTER
value|(V4L2_CID_BASE+33)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_ROTATE
value|(V4L2_CID_BASE+34)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_BG_COLOR
value|(V4L2_CID_BASE+35)
end_define

begin_comment
comment|/* last CID + 1 */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_LASTP1
value|(V4L2_CID_BASE+36)
end_define

begin_comment
comment|/*  MPEG-class control IDs defined by V4L2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_BASE
value|(V4L2_CTRL_CLASS_MPEG | 0x900)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CLASS
value|(V4L2_CTRL_CLASS_MPEG | 1)
end_define

begin_comment
comment|/*  MPEG streams */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_TYPE
value|(V4L2_CID_MPEG_BASE+0)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_stream_type
block|{
name|V4L2_MPEG_STREAM_TYPE_MPEG2_PS
init|=
literal|0
block|,
comment|/* MPEG-2 program stream */
name|V4L2_MPEG_STREAM_TYPE_MPEG2_TS
init|=
literal|1
block|,
comment|/* MPEG-2 transport stream */
name|V4L2_MPEG_STREAM_TYPE_MPEG1_SS
init|=
literal|2
block|,
comment|/* MPEG-1 system stream */
name|V4L2_MPEG_STREAM_TYPE_MPEG2_DVD
init|=
literal|3
block|,
comment|/* MPEG-2 DVD-compatible stream */
name|V4L2_MPEG_STREAM_TYPE_MPEG1_VCD
init|=
literal|4
block|,
comment|/* MPEG-1 VCD-compatible stream */
name|V4L2_MPEG_STREAM_TYPE_MPEG2_SVCD
init|=
literal|5
block|,
comment|/* MPEG-2 SVCD-compatible stream */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PID_PMT
value|(V4L2_CID_MPEG_BASE+1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PID_AUDIO
value|(V4L2_CID_MPEG_BASE+2)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PID_VIDEO
value|(V4L2_CID_MPEG_BASE+3)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PID_PCR
value|(V4L2_CID_MPEG_BASE+4)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PES_ID_AUDIO
value|(V4L2_CID_MPEG_BASE+5)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_PES_ID_VIDEO
value|(V4L2_CID_MPEG_BASE+6)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_STREAM_VBI_FMT
value|(V4L2_CID_MPEG_BASE+7)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_stream_vbi_fmt
block|{
name|V4L2_MPEG_STREAM_VBI_FMT_NONE
init|=
literal|0
block|,
comment|/* No VBI in the MPEG stream */
name|V4L2_MPEG_STREAM_VBI_FMT_IVTV
init|=
literal|1
block|,
comment|/* VBI in private packets, IVTV format */
block|}
enum|;
end_enum

begin_comment
comment|/*  MPEG audio */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_SAMPLING_FREQ
value|(V4L2_CID_MPEG_BASE+100)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_sampling_freq
block|{
name|V4L2_MPEG_AUDIO_SAMPLING_FREQ_44100
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_SAMPLING_FREQ_48000
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_SAMPLING_FREQ_32000
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_ENCODING
value|(V4L2_CID_MPEG_BASE+101)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_encoding
block|{
name|V4L2_MPEG_AUDIO_ENCODING_LAYER_1
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_ENCODING_LAYER_2
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_ENCODING_LAYER_3
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_ENCODING_AAC
init|=
literal|3
block|,
name|V4L2_MPEG_AUDIO_ENCODING_AC3
init|=
literal|4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_L1_BITRATE
value|(V4L2_CID_MPEG_BASE+102)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_l1_bitrate
block|{
name|V4L2_MPEG_AUDIO_L1_BITRATE_32K
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_64K
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_96K
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_128K
init|=
literal|3
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_160K
init|=
literal|4
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_192K
init|=
literal|5
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_224K
init|=
literal|6
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_256K
init|=
literal|7
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_288K
init|=
literal|8
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_320K
init|=
literal|9
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_352K
init|=
literal|10
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_384K
init|=
literal|11
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_416K
init|=
literal|12
block|,
name|V4L2_MPEG_AUDIO_L1_BITRATE_448K
init|=
literal|13
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_L2_BITRATE
value|(V4L2_CID_MPEG_BASE+103)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_l2_bitrate
block|{
name|V4L2_MPEG_AUDIO_L2_BITRATE_32K
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_48K
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_56K
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_64K
init|=
literal|3
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_80K
init|=
literal|4
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_96K
init|=
literal|5
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_112K
init|=
literal|6
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_128K
init|=
literal|7
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_160K
init|=
literal|8
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_192K
init|=
literal|9
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_224K
init|=
literal|10
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_256K
init|=
literal|11
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_320K
init|=
literal|12
block|,
name|V4L2_MPEG_AUDIO_L2_BITRATE_384K
init|=
literal|13
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_L3_BITRATE
value|(V4L2_CID_MPEG_BASE+104)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_l3_bitrate
block|{
name|V4L2_MPEG_AUDIO_L3_BITRATE_32K
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_40K
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_48K
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_56K
init|=
literal|3
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_64K
init|=
literal|4
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_80K
init|=
literal|5
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_96K
init|=
literal|6
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_112K
init|=
literal|7
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_128K
init|=
literal|8
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_160K
init|=
literal|9
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_192K
init|=
literal|10
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_224K
init|=
literal|11
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_256K
init|=
literal|12
block|,
name|V4L2_MPEG_AUDIO_L3_BITRATE_320K
init|=
literal|13
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_MODE
value|(V4L2_CID_MPEG_BASE+105)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_mode
block|{
name|V4L2_MPEG_AUDIO_MODE_STEREO
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_MODE_JOINT_STEREO
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_MODE_DUAL
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_MODE_MONO
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_MODE_EXTENSION
value|(V4L2_CID_MPEG_BASE+106)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_mode_extension
block|{
name|V4L2_MPEG_AUDIO_MODE_EXTENSION_BOUND_4
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_MODE_EXTENSION_BOUND_8
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_MODE_EXTENSION_BOUND_12
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_MODE_EXTENSION_BOUND_16
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_EMPHASIS
value|(V4L2_CID_MPEG_BASE+107)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_emphasis
block|{
name|V4L2_MPEG_AUDIO_EMPHASIS_NONE
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_EMPHASIS_50_DIV_15_uS
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_EMPHASIS_CCITT_J17
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_CRC
value|(V4L2_CID_MPEG_BASE+108)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_crc
block|{
name|V4L2_MPEG_AUDIO_CRC_NONE
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_CRC_CRC16
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_MUTE
value|(V4L2_CID_MPEG_BASE+109)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_AAC_BITRATE
value|(V4L2_CID_MPEG_BASE+110)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_AUDIO_AC3_BITRATE
value|(V4L2_CID_MPEG_BASE+111)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_audio_ac3_bitrate
block|{
name|V4L2_MPEG_AUDIO_AC3_BITRATE_32K
init|=
literal|0
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_40K
init|=
literal|1
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_48K
init|=
literal|2
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_56K
init|=
literal|3
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_64K
init|=
literal|4
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_80K
init|=
literal|5
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_96K
init|=
literal|6
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_112K
init|=
literal|7
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_128K
init|=
literal|8
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_160K
init|=
literal|9
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_192K
init|=
literal|10
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_224K
init|=
literal|11
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_256K
init|=
literal|12
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_320K
init|=
literal|13
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_384K
init|=
literal|14
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_448K
init|=
literal|15
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_512K
init|=
literal|16
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_576K
init|=
literal|17
block|,
name|V4L2_MPEG_AUDIO_AC3_BITRATE_640K
init|=
literal|18
block|, }
enum|;
end_enum

begin_comment
comment|/*  MPEG video */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_ENCODING
value|(V4L2_CID_MPEG_BASE+200)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_video_encoding
block|{
name|V4L2_MPEG_VIDEO_ENCODING_MPEG_1
init|=
literal|0
block|,
name|V4L2_MPEG_VIDEO_ENCODING_MPEG_2
init|=
literal|1
block|,
name|V4L2_MPEG_VIDEO_ENCODING_MPEG_4_AVC
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_ASPECT
value|(V4L2_CID_MPEG_BASE+201)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_video_aspect
block|{
name|V4L2_MPEG_VIDEO_ASPECT_1x1
init|=
literal|0
block|,
name|V4L2_MPEG_VIDEO_ASPECT_4x3
init|=
literal|1
block|,
name|V4L2_MPEG_VIDEO_ASPECT_16x9
init|=
literal|2
block|,
name|V4L2_MPEG_VIDEO_ASPECT_221x100
init|=
literal|3
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_B_FRAMES
value|(V4L2_CID_MPEG_BASE+202)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_GOP_SIZE
value|(V4L2_CID_MPEG_BASE+203)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_GOP_CLOSURE
value|(V4L2_CID_MPEG_BASE+204)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_PULLDOWN
value|(V4L2_CID_MPEG_BASE+205)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_BITRATE_MODE
value|(V4L2_CID_MPEG_BASE+206)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_video_bitrate_mode
block|{
name|V4L2_MPEG_VIDEO_BITRATE_MODE_VBR
init|=
literal|0
block|,
name|V4L2_MPEG_VIDEO_BITRATE_MODE_CBR
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_BITRATE
value|(V4L2_CID_MPEG_BASE+207)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_BITRATE_PEAK
value|(V4L2_CID_MPEG_BASE+208)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_TEMPORAL_DECIMATION
value|(V4L2_CID_MPEG_BASE+209)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_MUTE
value|(V4L2_CID_MPEG_BASE+210)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_VIDEO_MUTE_YUV
value|(V4L2_CID_MPEG_BASE+211)
end_define

begin_comment
comment|/*  MPEG-class control IDs specific to the CX2341x driver as defined by V4L2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_BASE
value|(V4L2_CTRL_CLASS_MPEG | 0x1000)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_SPATIAL_FILTER_MODE
value|(V4L2_CID_MPEG_CX2341X_BASE+0)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_cx2341x_video_spatial_filter_mode
block|{
name|V4L2_MPEG_CX2341X_VIDEO_SPATIAL_FILTER_MODE_MANUAL
init|=
literal|0
block|,
name|V4L2_MPEG_CX2341X_VIDEO_SPATIAL_FILTER_MODE_AUTO
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_SPATIAL_FILTER
value|(V4L2_CID_MPEG_CX2341X_BASE+1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE
value|(V4L2_CID_MPEG_CX2341X_BASE+2)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_cx2341x_video_luma_spatial_filter_type
block|{
name|V4L2_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE_OFF
init|=
literal|0
block|,
name|V4L2_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE_1D_HOR
init|=
literal|1
block|,
name|V4L2_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE_1D_VERT
init|=
literal|2
block|,
name|V4L2_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE_2D_HV_SEPARABLE
init|=
literal|3
block|,
name|V4L2_MPEG_CX2341X_VIDEO_LUMA_SPATIAL_FILTER_TYPE_2D_SYM_NON_SEPARABLE
init|=
literal|4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_CHROMA_SPATIAL_FILTER_TYPE
value|(V4L2_CID_MPEG_CX2341X_BASE+3)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_cx2341x_video_chroma_spatial_filter_type
block|{
name|V4L2_MPEG_CX2341X_VIDEO_CHROMA_SPATIAL_FILTER_TYPE_OFF
init|=
literal|0
block|,
name|V4L2_MPEG_CX2341X_VIDEO_CHROMA_SPATIAL_FILTER_TYPE_1D_HOR
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_TEMPORAL_FILTER_MODE
value|(V4L2_CID_MPEG_CX2341X_BASE+4)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_cx2341x_video_temporal_filter_mode
block|{
name|V4L2_MPEG_CX2341X_VIDEO_TEMPORAL_FILTER_MODE_MANUAL
init|=
literal|0
block|,
name|V4L2_MPEG_CX2341X_VIDEO_TEMPORAL_FILTER_MODE_AUTO
init|=
literal|1
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_TEMPORAL_FILTER
value|(V4L2_CID_MPEG_CX2341X_BASE+5)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE
value|(V4L2_CID_MPEG_CX2341X_BASE+6)
end_define

begin_enum
enum|enum
name|v4l2_mpeg_cx2341x_video_median_filter_type
block|{
name|V4L2_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE_OFF
init|=
literal|0
block|,
name|V4L2_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE_HOR
init|=
literal|1
block|,
name|V4L2_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE_VERT
init|=
literal|2
block|,
name|V4L2_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE_HOR_VERT
init|=
literal|3
block|,
name|V4L2_MPEG_CX2341X_VIDEO_MEDIAN_FILTER_TYPE_DIAG
init|=
literal|4
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_LUMA_MEDIAN_FILTER_BOTTOM
value|(V4L2_CID_MPEG_CX2341X_BASE+7)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_LUMA_MEDIAN_FILTER_TOP
value|(V4L2_CID_MPEG_CX2341X_BASE+8)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_CHROMA_MEDIAN_FILTER_BOTTOM
value|(V4L2_CID_MPEG_CX2341X_BASE+9)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_VIDEO_CHROMA_MEDIAN_FILTER_TOP
value|(V4L2_CID_MPEG_CX2341X_BASE+10)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_MPEG_CX2341X_STREAM_INSERT_NAV_PACKETS
value|(V4L2_CID_MPEG_CX2341X_BASE+11)
end_define

begin_comment
comment|/*  Camera class control IDs */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_CAMERA_CLASS_BASE
value|(V4L2_CTRL_CLASS_CAMERA | 0x900)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_CAMERA_CLASS
value|(V4L2_CTRL_CLASS_CAMERA | 1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_EXPOSURE_AUTO
value|(V4L2_CID_CAMERA_CLASS_BASE+1)
end_define

begin_enum
enum|enum
name|v4l2_exposure_auto_type
block|{
name|V4L2_EXPOSURE_AUTO
init|=
literal|0
block|,
name|V4L2_EXPOSURE_MANUAL
init|=
literal|1
block|,
name|V4L2_EXPOSURE_SHUTTER_PRIORITY
init|=
literal|2
block|,
name|V4L2_EXPOSURE_APERTURE_PRIORITY
init|=
literal|3
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_EXPOSURE_ABSOLUTE
value|(V4L2_CID_CAMERA_CLASS_BASE+2)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_EXPOSURE_AUTO_PRIORITY
value|(V4L2_CID_CAMERA_CLASS_BASE+3)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PAN_RELATIVE
value|(V4L2_CID_CAMERA_CLASS_BASE+4)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_TILT_RELATIVE
value|(V4L2_CID_CAMERA_CLASS_BASE+5)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PAN_RESET
value|(V4L2_CID_CAMERA_CLASS_BASE+6)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_TILT_RESET
value|(V4L2_CID_CAMERA_CLASS_BASE+7)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PAN_ABSOLUTE
value|(V4L2_CID_CAMERA_CLASS_BASE+8)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_TILT_ABSOLUTE
value|(V4L2_CID_CAMERA_CLASS_BASE+9)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_FOCUS_ABSOLUTE
value|(V4L2_CID_CAMERA_CLASS_BASE+10)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_FOCUS_RELATIVE
value|(V4L2_CID_CAMERA_CLASS_BASE+11)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_FOCUS_AUTO
value|(V4L2_CID_CAMERA_CLASS_BASE+12)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_ZOOM_ABSOLUTE
value|(V4L2_CID_CAMERA_CLASS_BASE+13)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_ZOOM_RELATIVE
value|(V4L2_CID_CAMERA_CLASS_BASE+14)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_ZOOM_CONTINUOUS
value|(V4L2_CID_CAMERA_CLASS_BASE+15)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PRIVACY
value|(V4L2_CID_CAMERA_CLASS_BASE+16)
end_define

begin_comment
comment|/* FM Modulator class control IDs */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_FM_TX_CLASS_BASE
value|(V4L2_CTRL_CLASS_FM_TX | 0x900)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_FM_TX_CLASS
value|(V4L2_CTRL_CLASS_FM_TX | 1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RDS_TX_DEVIATION
value|(V4L2_CID_FM_TX_CLASS_BASE + 1)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RDS_TX_PI
value|(V4L2_CID_FM_TX_CLASS_BASE + 2)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RDS_TX_PTY
value|(V4L2_CID_FM_TX_CLASS_BASE + 3)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RDS_TX_PS_NAME
value|(V4L2_CID_FM_TX_CLASS_BASE + 5)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_RDS_TX_RADIO_TEXT
value|(V4L2_CID_FM_TX_CLASS_BASE + 6)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_LIMITER_ENABLED
value|(V4L2_CID_FM_TX_CLASS_BASE + 64)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_LIMITER_RELEASE_TIME
value|(V4L2_CID_FM_TX_CLASS_BASE + 65)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_LIMITER_DEVIATION
value|(V4L2_CID_FM_TX_CLASS_BASE + 66)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_COMPRESSION_ENABLED
value|(V4L2_CID_FM_TX_CLASS_BASE + 80)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_COMPRESSION_GAIN
value|(V4L2_CID_FM_TX_CLASS_BASE + 81)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_COMPRESSION_THRESHOLD
value|(V4L2_CID_FM_TX_CLASS_BASE + 82)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_COMPRESSION_ATTACK_TIME
value|(V4L2_CID_FM_TX_CLASS_BASE + 83)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_AUDIO_COMPRESSION_RELEASE_TIME
value|(V4L2_CID_FM_TX_CLASS_BASE + 84)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PILOT_TONE_ENABLED
value|(V4L2_CID_FM_TX_CLASS_BASE + 96)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PILOT_TONE_DEVIATION
value|(V4L2_CID_FM_TX_CLASS_BASE + 97)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_PILOT_TONE_FREQUENCY
value|(V4L2_CID_FM_TX_CLASS_BASE + 98)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_TUNE_PREEMPHASIS
value|(V4L2_CID_FM_TX_CLASS_BASE + 112)
end_define

begin_enum
enum|enum
name|v4l2_preemphasis
block|{
name|V4L2_PREEMPHASIS_DISABLED
init|=
literal|0
block|,
name|V4L2_PREEMPHASIS_50_uS
init|=
literal|1
block|,
name|V4L2_PREEMPHASIS_75_uS
init|=
literal|2
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|V4L2_CID_TUNE_POWER_LEVEL
value|(V4L2_CID_FM_TX_CLASS_BASE + 113)
end_define

begin_define
define|#
directive|define
name|V4L2_CID_TUNE_ANTENNA_CAPACITOR
value|(V4L2_CID_FM_TX_CLASS_BASE + 114)
end_define

begin_comment
comment|/*  *	T U N I N G  */
end_comment

begin_struct
struct|struct
name|v4l2_tuner
block|{
name|__u32
name|index
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
name|enum
name|v4l2_tuner_type
name|type
decl_stmt|;
name|__u32
name|capability
decl_stmt|;
name|__u32
name|rangelow
decl_stmt|;
name|__u32
name|rangehigh
decl_stmt|;
name|__u32
name|rxsubchans
decl_stmt|;
name|__u32
name|audmode
decl_stmt|;
name|__s32
name|signal
decl_stmt|;
name|__s32
name|afc
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_modulator
block|{
name|__u32
name|index
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
name|__u32
name|capability
decl_stmt|;
name|__u32
name|rangelow
decl_stmt|;
name|__u32
name|rangehigh
decl_stmt|;
name|__u32
name|txsubchans
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for the 'capability' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_LOW
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_NORM
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_STEREO
value|0x0010
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_LANG2
value|0x0020
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_SAP
value|0x0020
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_LANG1
value|0x0040
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_CAP_RDS
value|0x0080
end_define

begin_comment
comment|/*  Flags for the 'rxsubchans' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_MONO
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_STEREO
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_LANG2
value|0x0004
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_SAP
value|0x0004
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_LANG1
value|0x0008
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_SUB_RDS
value|0x0010
end_define

begin_comment
comment|/*  Values for the 'audmode' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_MONO
value|0x0000
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_STEREO
value|0x0001
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_LANG2
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_SAP
value|0x0002
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_LANG1
value|0x0003
end_define

begin_define
define|#
directive|define
name|V4L2_TUNER_MODE_LANG1_LANG2
value|0x0004
end_define

begin_struct
struct|struct
name|v4l2_frequency
block|{
name|__u32
name|tuner
decl_stmt|;
name|enum
name|v4l2_tuner_type
name|type
decl_stmt|;
name|__u32
name|frequency
decl_stmt|;
name|__u32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_hw_freq_seek
block|{
name|__u32
name|tuner
decl_stmt|;
name|enum
name|v4l2_tuner_type
name|type
decl_stmt|;
name|__u32
name|seek_upward
decl_stmt|;
name|__u32
name|wrap_around
decl_stmt|;
name|__u32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	R D S  */
end_comment

begin_struct
struct|struct
name|v4l2_rds_data
block|{
name|__u8
name|lsb
decl_stmt|;
name|__u8
name|msb
decl_stmt|;
name|__u8
name|block
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
name|V4L2_RDS_BLOCK_MSK
value|0x7
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_A
value|0
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_B
value|1
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_C
value|2
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_D
value|3
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_C_ALT
value|4
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_INVALID
value|7
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_CORRECTED
value|0x40
end_define

begin_define
define|#
directive|define
name|V4L2_RDS_BLOCK_ERROR
value|0x80
end_define

begin_comment
comment|/*  *	A U D I O  */
end_comment

begin_struct
struct|struct
name|v4l2_audio
block|{
name|__u32
name|index
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
name|__u32
name|capability
decl_stmt|;
name|__u32
name|mode
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for the 'capability' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_AUDCAP_STEREO
value|0x00001
end_define

begin_define
define|#
directive|define
name|V4L2_AUDCAP_AVL
value|0x00002
end_define

begin_comment
comment|/*  Flags for the 'mode' field */
end_comment

begin_define
define|#
directive|define
name|V4L2_AUDMODE_AVL
value|0x00001
end_define

begin_struct
struct|struct
name|v4l2_audioout
block|{
name|__u32
name|index
decl_stmt|;
name|__u8
name|name
index|[
literal|32
index|]
decl_stmt|;
name|__u32
name|capability
decl_stmt|;
name|__u32
name|mode
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	M P E G   S E R V I C E S  *  *	NOTE: EXPERIMENTAL API  */
end_comment

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|V4L2_ENC_IDX_FRAME_I
value|(0)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_IDX_FRAME_P
value|(1)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_IDX_FRAME_B
value|(2)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_IDX_FRAME_MASK
value|(0xf)
end_define

begin_struct
struct|struct
name|v4l2_enc_idx_entry
block|{
name|__u64
name|offset
decl_stmt|;
name|__u64
name|pts
decl_stmt|;
name|__u32
name|length
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|V4L2_ENC_IDX_ENTRIES
value|(64)
end_define

begin_struct
struct|struct
name|v4l2_enc_idx
block|{
name|__u32
name|entries
decl_stmt|;
name|__u32
name|entries_cap
decl_stmt|;
name|__u32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|v4l2_enc_idx_entry
name|entry
index|[
name|V4L2_ENC_IDX_ENTRIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|V4L2_ENC_CMD_START
value|(0)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_CMD_STOP
value|(1)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_CMD_PAUSE
value|(2)
end_define

begin_define
define|#
directive|define
name|V4L2_ENC_CMD_RESUME
value|(3)
end_define

begin_comment
comment|/* Flags for V4L2_ENC_CMD_STOP */
end_comment

begin_define
define|#
directive|define
name|V4L2_ENC_CMD_STOP_AT_GOP_END
value|(1<< 0)
end_define

begin_struct
struct|struct
name|v4l2_encoder_cmd
block|{
name|__u32
name|cmd
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|__u32
name|data
index|[
literal|8
index|]
decl_stmt|;
block|}
name|raw
struct|;
block|}
name|x
union|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	D A T A   S E R V I C E S   ( V B I )  *  *	Data services API by Michael Schimek  */
end_comment

begin_comment
comment|/* Raw VBI */
end_comment

begin_struct
struct|struct
name|v4l2_vbi_format
block|{
name|__u32
name|sampling_rate
decl_stmt|;
comment|/* in 1 Hz */
name|__u32
name|offset
decl_stmt|;
name|__u32
name|samples_per_line
decl_stmt|;
name|__u32
name|sample_format
decl_stmt|;
comment|/* V4L2_PIX_FMT_* */
name|__s32
name|start
index|[
literal|2
index|]
decl_stmt|;
name|__u32
name|count
index|[
literal|2
index|]
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
comment|/* V4L2_VBI_* */
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be zero */
block|}
struct|;
end_struct

begin_comment
comment|/*  VBI flags  */
end_comment

begin_define
define|#
directive|define
name|V4L2_VBI_UNSYNC
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|V4L2_VBI_INTERLACED
value|(1<< 1)
end_define

begin_comment
comment|/* Sliced VBI  *  *    This implements is a proposal V4L2 API to allow SLICED VBI  * required for some hardware encoders. It should change without  * notice in the definitive implementation.  */
end_comment

begin_struct
struct|struct
name|v4l2_sliced_vbi_format
block|{
name|__u16
name|service_set
decl_stmt|;
comment|/* service_lines[0][...] specifies lines 0-23 (1-23 used) of the first field 	   service_lines[1][...] specifies lines 0-23 (1-23 used) of the second field 				 (equals frame lines 313-336 for 625 line video 				  standards, 263-286 for 525 line standards) */
name|__u16
name|service_lines
index|[
literal|2
index|]
index|[
literal|24
index|]
decl_stmt|;
name|__u32
name|io_size
decl_stmt|;
name|__u32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* must be zero */
block|}
struct|;
end_struct

begin_comment
comment|/* Teletext World System Teletext    (WST), defined on ITU-R BT.653-2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_SLICED_TELETEXT_B
value|(0x0001)
end_define

begin_comment
comment|/* Video Program System, defined on ETS 300 231*/
end_comment

begin_define
define|#
directive|define
name|V4L2_SLICED_VPS
value|(0x0400)
end_define

begin_comment
comment|/* Closed Caption, defined on EIA-608 */
end_comment

begin_define
define|#
directive|define
name|V4L2_SLICED_CAPTION_525
value|(0x1000)
end_define

begin_comment
comment|/* Wide Screen System, defined on ITU-R BT1119.1 */
end_comment

begin_define
define|#
directive|define
name|V4L2_SLICED_WSS_625
value|(0x4000)
end_define

begin_define
define|#
directive|define
name|V4L2_SLICED_VBI_525
value|(V4L2_SLICED_CAPTION_525)
end_define

begin_define
define|#
directive|define
name|V4L2_SLICED_VBI_625
value|(V4L2_SLICED_TELETEXT_B | V4L2_SLICED_VPS | V4L2_SLICED_WSS_625)
end_define

begin_struct
struct|struct
name|v4l2_sliced_vbi_cap
block|{
name|__u16
name|service_set
decl_stmt|;
comment|/* service_lines[0][...] specifies lines 0-23 (1-23 used) of the first field 	   service_lines[1][...] specifies lines 0-23 (1-23 used) of the second field 				 (equals frame lines 313-336 for 625 line video 				  standards, 263-286 for 525 line standards) */
name|__u16
name|service_lines
index|[
literal|2
index|]
index|[
literal|24
index|]
decl_stmt|;
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
name|__u32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* must be 0 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|v4l2_sliced_vbi_data
block|{
name|__u32
name|id
decl_stmt|;
name|__u32
name|field
decl_stmt|;
comment|/* 0: first field, 1: second field */
name|__u32
name|line
decl_stmt|;
comment|/* 1-23 */
name|__u32
name|reserved
decl_stmt|;
comment|/* must be 0 */
name|__u8
name|data
index|[
literal|48
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sliced VBI data inserted into MPEG Streams  */
end_comment

begin_comment
comment|/*  * V4L2_MPEG_STREAM_VBI_FMT_IVTV:  *  * Structure of payload contained in an MPEG 2 Private Stream 1 PES Packet in an  * MPEG-2 Program Pack that contains V4L2_MPEG_STREAM_VBI_FMT_IVTV Sliced VBI  * data  *  * Note, the MPEG-2 Program Pack and Private Stream 1 PES packet header  * definitions are not included here.  See the MPEG-2 specifications for details  * on these headers.  */
end_comment

begin_comment
comment|/* Line type IDs */
end_comment

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_TELETEXT_B
value|(1)
end_define

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_CAPTION_525
value|(4)
end_define

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_WSS_625
value|(5)
end_define

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_VPS
value|(7)
end_define

begin_struct
struct|struct
name|v4l2_mpeg_vbi_itv0_line
block|{
name|__u8
name|id
decl_stmt|;
comment|/* One of V4L2_MPEG_VBI_IVTV_* above */
name|__u8
name|data
index|[
literal|42
index|]
decl_stmt|;
comment|/* Sliced VBI data for the line */
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
name|v4l2_mpeg_vbi_itv0
block|{
name|__le32
name|linemask
index|[
literal|2
index|]
decl_stmt|;
comment|/* Bitmasks of VBI service lines present */
name|struct
name|v4l2_mpeg_vbi_itv0_line
name|line
index|[
literal|35
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
name|v4l2_mpeg_vbi_ITV0
block|{
name|struct
name|v4l2_mpeg_vbi_itv0_line
name|line
index|[
literal|36
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

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_MAGIC0
value|"itv0"
end_define

begin_define
define|#
directive|define
name|V4L2_MPEG_VBI_IVTV_MAGIC1
value|"ITV0"
end_define

begin_struct
struct|struct
name|v4l2_mpeg_vbi_fmt_ivtv
block|{
name|__u8
name|magic
index|[
literal|4
index|]
decl_stmt|;
union|union
block|{
name|struct
name|v4l2_mpeg_vbi_itv0
name|itv0
decl_stmt|;
name|struct
name|v4l2_mpeg_vbi_ITV0
name|ITV0
decl_stmt|;
block|}
name|x
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

begin_comment
comment|/*  *	A G G R E G A T E   S T R U C T U R E S  */
end_comment

begin_comment
comment|/*	Stream data format  */
end_comment

begin_struct
struct|struct
name|v4l2_format
block|{
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
union|union
block|{
name|struct
name|v4l2_pix_format
name|pix
decl_stmt|;
comment|/* V4L2_BUF_TYPE_VIDEO_CAPTURE */
name|struct
name|v4l2_window
name|win
decl_stmt|;
comment|/* V4L2_BUF_TYPE_VIDEO_OVERLAY */
name|struct
name|v4l2_vbi_format
name|vbi
decl_stmt|;
comment|/* V4L2_BUF_TYPE_VBI_CAPTURE */
name|struct
name|v4l2_sliced_vbi_format
name|sliced
decl_stmt|;
comment|/* V4L2_BUF_TYPE_SLICED_VBI_CAPTURE */
name|__u8
name|raw_data
index|[
literal|200
index|]
decl_stmt|;
comment|/* user-defined */
block|}
name|fmt
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*	Stream type-dependent parameters  */
end_comment

begin_struct
struct|struct
name|v4l2_streamparm
block|{
name|enum
name|v4l2_buf_type
name|type
decl_stmt|;
union|union
block|{
name|struct
name|v4l2_captureparm
name|capture
decl_stmt|;
name|struct
name|v4l2_outputparm
name|output
decl_stmt|;
name|__u8
name|raw_data
index|[
literal|200
index|]
decl_stmt|;
comment|/* user-defined */
block|}
name|parm
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *	A D V A N C E D   D E B U G G I N G  *  *	NOTE: EXPERIMENTAL API, NEVER RELY ON THIS IN APPLICATIONS!  *	FOR DEBUGGING, TESTING AND INTERNAL USE ONLY!  */
end_comment

begin_comment
comment|/* VIDIOC_DBG_G_REGISTER and VIDIOC_DBG_S_REGISTER */
end_comment

begin_define
define|#
directive|define
name|V4L2_CHIP_MATCH_HOST
value|0
end_define

begin_comment
comment|/* Match against chip ID on host (0 for the host) */
end_comment

begin_define
define|#
directive|define
name|V4L2_CHIP_MATCH_I2C_DRIVER
value|1
end_define

begin_comment
comment|/* Match against I2C driver name */
end_comment

begin_define
define|#
directive|define
name|V4L2_CHIP_MATCH_I2C_ADDR
value|2
end_define

begin_comment
comment|/* Match against I2C 7-bit address */
end_comment

begin_define
define|#
directive|define
name|V4L2_CHIP_MATCH_AC97
value|3
end_define

begin_comment
comment|/* Match against anciliary AC97 chip */
end_comment

begin_struct
struct|struct
name|v4l2_dbg_match
block|{
name|__u32
name|type
decl_stmt|;
comment|/* Match type */
union|union
block|{
comment|/* Match this chip, meaning determined by type */
name|__u32
name|addr
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
block|}
name|x
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
name|v4l2_dbg_register
block|{
name|struct
name|v4l2_dbg_match
name|match
decl_stmt|;
name|__u32
name|size
decl_stmt|;
comment|/* register size in bytes */
name|__u64
name|reg
decl_stmt|;
name|__u64
name|val
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
comment|/* VIDIOC_DBG_G_CHIP_IDENT */
end_comment

begin_struct
struct|struct
name|v4l2_dbg_chip_ident
block|{
name|struct
name|v4l2_dbg_match
name|match
decl_stmt|;
name|__u32
name|ident
decl_stmt|;
comment|/* chip identifier as specified in<media/v4l2-chip-ident.h> */
name|__u32
name|revision
decl_stmt|;
comment|/* chip revision, chip specific */
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
comment|/*  *	I O C T L   C O D E S   F O R   V I D E O   D E V I C E S  *  */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_QUERYCAP
value|_IOR('V',  0, struct v4l2_capability)
end_define

begin_define
define|#
directive|define
name|VIDIOC_RESERVED
value|_IO('V',  1)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUM_FMT
value|_IOWR('V',  2, struct v4l2_fmtdesc)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FMT
value|_IOWR('V',  4, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FMT
value|_IOWR('V',  5, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_REQBUFS
value|_IOWR('V',  8, struct v4l2_requestbuffers)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYBUF
value|_IOWR('V',  9, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FBUF
value|_IOR('V', 10, struct v4l2_framebuffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FBUF
value|_IOW('V', 11, struct v4l2_framebuffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_OVERLAY
value|_IOW('V', 14, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QBUF
value|_IOWR('V', 15, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_DQBUF
value|_IOWR('V', 17, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_STREAMON
value|_IOW('V', 18, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_STREAMOFF
value|_IOW('V', 19, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_PARM
value|_IOWR('V', 21, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PARM
value|_IOWR('V', 22, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_STD
value|_IOR('V', 23, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_STD
value|_IOW('V', 24, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMSTD
value|_IOWR('V', 25, struct v4l2_standard)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMINPUT
value|_IOWR('V', 26, struct v4l2_input)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_CTRL
value|_IOWR('V', 27, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CTRL
value|_IOWR('V', 28, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_TUNER
value|_IOWR('V', 29, struct v4l2_tuner)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_TUNER
value|_IOW('V', 30, struct v4l2_tuner)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDIO
value|_IOR('V', 33, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_AUDIO
value|_IOW('V', 34, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYCTRL
value|_IOWR('V', 36, struct v4l2_queryctrl)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYMENU
value|_IOWR('V', 37, struct v4l2_querymenu)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_INPUT
value|_IOR('V', 38, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_INPUT
value|_IOWR('V', 39, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_OUTPUT
value|_IOR('V', 46, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_OUTPUT
value|_IOWR('V', 47, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMOUTPUT
value|_IOWR('V', 48, struct v4l2_output)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDOUT
value|_IOR('V', 49, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_AUDOUT
value|_IOW('V', 50, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_MODULATOR
value|_IOWR('V', 54, struct v4l2_modulator)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_MODULATOR
value|_IOW('V', 55, struct v4l2_modulator)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FREQUENCY
value|_IOWR('V', 56, struct v4l2_frequency)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FREQUENCY
value|_IOW('V', 57, struct v4l2_frequency)
end_define

begin_define
define|#
directive|define
name|VIDIOC_CROPCAP
value|_IOWR('V', 58, struct v4l2_cropcap)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_CROP
value|_IOWR('V', 59, struct v4l2_crop)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CROP
value|_IOW('V', 60, struct v4l2_crop)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_JPEGCOMP
value|_IOR('V', 61, struct v4l2_jpegcompression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_JPEGCOMP
value|_IOW('V', 62, struct v4l2_jpegcompression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYSTD
value|_IOR('V', 63, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_TRY_FMT
value|_IOWR('V', 64, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMAUDIO
value|_IOWR('V', 65, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMAUDOUT
value|_IOWR('V', 66, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_PRIORITY
value|_IOR('V', 67, enum v4l2_priority)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PRIORITY
value|_IOW('V', 68, enum v4l2_priority)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_SLICED_VBI_CAP
value|_IOWR('V', 69, struct v4l2_sliced_vbi_cap)
end_define

begin_define
define|#
directive|define
name|VIDIOC_LOG_STATUS
value|_IO('V', 70)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_EXT_CTRLS
value|_IOWR('V', 71, struct v4l2_ext_controls)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_EXT_CTRLS
value|_IOWR('V', 72, struct v4l2_ext_controls)
end_define

begin_define
define|#
directive|define
name|VIDIOC_TRY_EXT_CTRLS
value|_IOWR('V', 73, struct v4l2_ext_controls)
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|VIDIOC_ENUM_FRAMESIZES
value|_IOWR('V', 74, struct v4l2_frmsizeenum)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUM_FRAMEINTERVALS
value|_IOWR('V', 75, struct v4l2_frmivalenum)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_ENC_INDEX
value|_IOR('V', 76, struct v4l2_enc_idx)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENCODER_CMD
value|_IOWR('V', 77, struct v4l2_encoder_cmd)
end_define

begin_define
define|#
directive|define
name|VIDIOC_TRY_ENCODER_CMD
value|_IOWR('V', 78, struct v4l2_encoder_cmd)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* Experimental, meant for debugging, testing and internal use.    Only implemented if CONFIG_VIDEO_ADV_DEBUG is defined.    You must be root to use these ioctls. Never use these in applications! */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_DBG_S_REGISTER
value|_IOW('V', 79, struct v4l2_dbg_register)
end_define

begin_define
define|#
directive|define
name|VIDIOC_DBG_G_REGISTER
value|_IOWR('V', 80, struct v4l2_dbg_register)
end_define

begin_comment
comment|/* Experimental, meant for debugging, testing and internal use.    Never use this ioctl in applications! */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_DBG_G_CHIP_IDENT
value|_IOWR('V', 81, struct v4l2_dbg_chip_ident)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIDIOC_S_HW_FREQ_SEEK
value|_IOW('V', 82, struct v4l2_hw_freq_seek)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUM_DV_PRESETS
value|_IOWR('V', 83, struct v4l2_dv_enum_preset)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_DV_PRESET
value|_IOWR('V', 84, struct v4l2_dv_preset)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_DV_PRESET
value|_IOWR('V', 85, struct v4l2_dv_preset)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERY_DV_PRESET
value|_IOR('V',  86, struct v4l2_dv_preset)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_DV_TIMINGS
value|_IOWR('V', 87, struct v4l2_dv_timings)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_DV_TIMINGS
value|_IOWR('V', 88, struct v4l2_dv_timings)
end_define

begin_comment
comment|/* Reminder: when adding new ioctls please add support for them to    drivers/media/video/v4l2-compat-ioctl32.c as well! */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__OLD_VIDIOC_
end_ifdef

begin_comment
comment|/* for compatibility, will go away some day */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_OVERLAY_OLD
value|_IOWR('V', 14, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PARM_OLD
value|_IOW('V', 22, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CTRL_OLD
value|_IOW('V', 28, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDIO_OLD
value|_IOWR('V', 33, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDOUT_OLD
value|_IOWR('V', 49, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_CROPCAP_OLD
value|_IOR('V', 58, struct v4l2_cropcap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BASE_VIDIOC_PRIVATE
value|192
end_define

begin_comment
comment|/* 192-255 are private */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LINUX_VIDEODEV2_H */
end_comment

end_unit

