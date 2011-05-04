begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header comes from linux, but it has no license. The author  * (Bill Dirks) gave explicit permissions to use it in FreeBSD.  * The FreeBSD vendor branch for v4l gives a more detailed description  * about this in the README.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  *	Video for Linux Two  *  *	Header file for v4l or V4L2 drivers and applications, for  *	Linux kernels 2.2.x or 2.4.x.  *  *	See http://bytesex.org/v4l/ for API specs and other  *	v4l2 documentation.  *  *	Author: Bill Dirks<bdirks@pacbell.net>  *		Justin Schoeman  *		et al.  */
end_comment

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

begin_include
include|#
directive|include
file|<linux/poll.h>
end_include

begin_include
include|#
directive|include
file|<linux/device.h>
end_include

begin_include
include|#
directive|include
file|<linux/mutex.h>
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

begin_comment
comment|/* need __user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBSOLETE_OWNER
value|1
end_define

begin_comment
comment|/* It will be removed for 2.6.17 */
end_comment

begin_define
define|#
directive|define
name|HAVE_V4L2
value|1
end_define

begin_comment
comment|/*  * Common stuff for both V4L1 and V4L2  * Moved from videodev.h  */
end_comment

begin_define
define|#
directive|define
name|VIDEO_MAX_FRAME
value|32
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/* Minor device allocation */
end_comment

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_GRABBER_MIN
value|0
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_GRABBER_MAX
value|63
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_RADIO_MIN
value|64
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_RADIO_MAX
value|127
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_VTX_MIN
value|192
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_VTX_MAX
value|223
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_VBI_MIN
value|224
end_define

begin_define
define|#
directive|define
name|MINOR_VFL_TYPE_VBI_MAX
value|255
end_define

begin_define
define|#
directive|define
name|VFL_TYPE_GRABBER
value|0
end_define

begin_define
define|#
directive|define
name|VFL_TYPE_VBI
value|1
end_define

begin_define
define|#
directive|define
name|VFL_TYPE_RADIO
value|2
end_define

begin_define
define|#
directive|define
name|VFL_TYPE_VTX
value|3
end_define

begin_struct
struct|struct
name|video_device
block|{
comment|/* device info */
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|type
decl_stmt|;
comment|/* v4l1 */
name|int
name|type2
decl_stmt|;
comment|/* v4l2 */
name|int
name|hardware
decl_stmt|;
name|int
name|minor
decl_stmt|;
comment|/* device ops + callbacks */
specifier|const
name|struct
name|file_operations
modifier|*
name|fops
decl_stmt|;
name|void
function_decl|(
modifier|*
name|release
function_decl|)
parameter_list|(
name|struct
name|video_device
modifier|*
name|vfd
parameter_list|)
function_decl|;
if|#
directive|if
name|OBSOLETE_OWNER
comment|/* to be removed in 2.6.15 */
comment|/* obsolete -- fops->owner is used instead */
name|struct
name|module
modifier|*
name|owner
decl_stmt|;
comment|/* dev->driver_data will be used instead some day. 	 * Use the video_{get|set}_drvdata() helper functions, 	 * so the switch over will be transparent for you. 	 * Or use {pci|usb}_{get|set}_drvdata() directly. */
name|void
modifier|*
name|priv
decl_stmt|;
endif|#
directive|endif
comment|/* for videodev.c intenal usage -- please don't touch */
name|int
name|users
decl_stmt|;
comment|/* video_exclusive_{open|close} ... */
name|struct
name|mutex
name|lock
decl_stmt|;
comment|/* ... helper function uses these   */
name|char
name|devfs_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* devfs */
name|struct
name|class_device
name|class_dev
decl_stmt|;
comment|/* sysfs */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIDEO_MAJOR
value|81
end_define

begin_function_decl
specifier|extern
name|int
name|video_register_device
parameter_list|(
name|struct
name|video_device
modifier|*
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|video_unregister_device
parameter_list|(
name|struct
name|video_device
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|video_usercopy
parameter_list|(
name|struct
name|inode
modifier|*
name|inode
parameter_list|,
name|struct
name|file
modifier|*
name|file
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|,
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|inode
modifier|*
name|inode
parameter_list|,
name|struct
name|file
modifier|*
name|file
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* helper functions to alloc / release struct video_device, the    later can be used for video_device->release() */
end_comment

begin_function_decl
name|struct
name|video_device
modifier|*
name|video_device_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|video_device_release
parameter_list|(
name|struct
name|video_device
modifier|*
name|vfd
parameter_list|)
function_decl|;
end_function_decl

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
value|(((__u32)(a)<<0)|((__u32)(b)<<8)|((__u32)(c)<<16)|((__u32)(d)<<24))
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
comment|/* driver can choose from none, 				      top, bottom, interlaced 				      depending on whatever it thinks 				      is approximate ... */
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
comment|/* both fields sequential into one 				      buffer, top-bottom order */
name|V4L2_FIELD_SEQ_BT
init|=
literal|6
block|,
comment|/* same as above + bottom-top order */
name|V4L2_FIELD_ALTERNATE
init|=
literal|7
block|,
comment|/* both fields alternating into 				      separate buffers */
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
value|((field) == V4L2_FIELD_TOP 	||\ 	 (field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_SEQ_TB	||\ 	 (field) == V4L2_FIELD_SEQ_BT)
end_define

begin_define
define|#
directive|define
name|V4L2_FIELD_HAS_BOTTOM
parameter_list|(
name|field
parameter_list|)
define|\
value|((field) == V4L2_FIELD_BOTTOM 	||\ 	 (field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_SEQ_TB	||\ 	 (field) == V4L2_FIELD_SEQ_BT)
end_define

begin_define
define|#
directive|define
name|V4L2_FIELD_HAS_BOTH
parameter_list|(
name|field
parameter_list|)
define|\
value|((field) == V4L2_FIELD_INTERLACED ||\ 	 (field) == V4L2_FIELD_SEQ_TB	||\ 	 (field) == V4L2_FIELD_SEQ_BT)
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
if|#
directive|if
literal|1
comment|/* Experimental Sliced VBI */
name|V4L2_BUF_TYPE_SLICED_VBI_CAPTURE
init|=
literal|6
block|,
name|V4L2_BUF_TYPE_SLICED_VBI_OUTPUT
init|=
literal|7
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

begin_if
if|#
directive|if
literal|1
end_if

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

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*           Pixel format    FOURCC                  depth  Description   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB332
value|v4l2_fourcc('R','G','B','1')
end_define

begin_comment
comment|/*  8  RGB-3-3-2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB555
value|v4l2_fourcc('R','G','B','O')
end_define

begin_comment
comment|/* 16  RGB-5-5-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB565
value|v4l2_fourcc('R','G','B','P')
end_define

begin_comment
comment|/* 16  RGB-5-6-5     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB555X
value|v4l2_fourcc('R','G','B','Q')
end_define

begin_comment
comment|/* 16  RGB-5-5-5 BE  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB565X
value|v4l2_fourcc('R','G','B','R')
end_define

begin_comment
comment|/* 16  RGB-5-6-5 BE  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_BGR24
value|v4l2_fourcc('B','G','R','3')
end_define

begin_comment
comment|/* 24  BGR-8-8-8     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB24
value|v4l2_fourcc('R','G','B','3')
end_define

begin_comment
comment|/* 24  RGB-8-8-8     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_BGR32
value|v4l2_fourcc('B','G','R','4')
end_define

begin_comment
comment|/* 32  BGR-8-8-8-8   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_RGB32
value|v4l2_fourcc('R','G','B','4')
end_define

begin_comment
comment|/* 32  RGB-8-8-8-8   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_GREY
value|v4l2_fourcc('G','R','E','Y')
end_define

begin_comment
comment|/*  8  Greyscale     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YVU410
value|v4l2_fourcc('Y','V','U','9')
end_define

begin_comment
comment|/*  9  YVU 4:1:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YVU420
value|v4l2_fourcc('Y','V','1','2')
end_define

begin_comment
comment|/* 12  YVU 4:2:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUYV
value|v4l2_fourcc('Y','U','Y','V')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_UYVY
value|v4l2_fourcc('U','Y','V','Y')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV422P
value|v4l2_fourcc('4','2','2','P')
end_define

begin_comment
comment|/* 16  YVU422 planar */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV411P
value|v4l2_fourcc('4','1','1','P')
end_define

begin_comment
comment|/* 16  YVU411 planar */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_Y41P
value|v4l2_fourcc('Y','4','1','P')
end_define

begin_comment
comment|/* 12  YUV 4:1:1     */
end_comment

begin_comment
comment|/* two planes -- one Y, one Cr + Cb interleaved  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV12
value|v4l2_fourcc('N','V','1','2')
end_define

begin_comment
comment|/* 12  Y/CbCr 4:2:0  */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_NV21
value|v4l2_fourcc('N','V','2','1')
end_define

begin_comment
comment|/* 12  Y/CrCb 4:2:0  */
end_comment

begin_comment
comment|/*  The following formats are not defined in the V4L2 specification */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV410
value|v4l2_fourcc('Y','U','V','9')
end_define

begin_comment
comment|/*  9  YUV 4:1:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YUV420
value|v4l2_fourcc('Y','U','1','2')
end_define

begin_comment
comment|/* 12  YUV 4:2:0     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_YYUV
value|v4l2_fourcc('Y','Y','U','V')
end_define

begin_comment
comment|/* 16  YUV 4:2:2     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_HI240
value|v4l2_fourcc('H','I','2','4')
end_define

begin_comment
comment|/*  8  8-bit color   */
end_comment

begin_comment
comment|/* see http://www.siliconimaging.com/RGB%20Bayer.htm */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SBGGR8
value|v4l2_fourcc('B','A','8','1')
end_define

begin_comment
comment|/*  8  BGBG.. GRGR.. */
end_comment

begin_comment
comment|/* compressed formats */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_MJPEG
value|v4l2_fourcc('M','J','P','G')
end_define

begin_comment
comment|/* Motion-JPEG   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_JPEG
value|v4l2_fourcc('J','P','E','G')
end_define

begin_comment
comment|/* JFIF JPEG     */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_DV
value|v4l2_fourcc('d','v','s','d')
end_define

begin_comment
comment|/* 1394          */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_MPEG
value|v4l2_fourcc('M','P','E','G')
end_define

begin_comment
comment|/* MPEG          */
end_comment

begin_comment
comment|/*  Vendor-specific formats   */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_WNVA
value|v4l2_fourcc('W','N','V','A')
end_define

begin_comment
comment|/* Winnov hw compress */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_SN9C10X
value|v4l2_fourcc('S','9','1','0')
end_define

begin_comment
comment|/* SN9C10x compression */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PWC1
value|v4l2_fourcc('P','W','C','1')
end_define

begin_comment
comment|/* pwc older webcam */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_PWC2
value|v4l2_fourcc('P','W','C','2')
end_define

begin_comment
comment|/* pwc newer webcam */
end_comment

begin_define
define|#
directive|define
name|V4L2_PIX_FMT_ET61X251
value|v4l2_fourcc('E','6','2','5')
end_define

begin_comment
comment|/* ET61X251 compression */
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

begin_comment
comment|/*  *	M P E G   C O M P R E S S I O N   P A R A M E T E R S  *  *  ### WARNING: this is still work-in-progress right now, most likely  *  ###          there will be some incompatible changes.  *  */
end_comment

begin_enum
enum|enum
name|v4l2_bitrate_mode
block|{
name|V4L2_BITRATE_NONE
init|=
literal|0
block|,
comment|/* not specified */
name|V4L2_BITRATE_CBR
block|,
comment|/* constant bitrate */
name|V4L2_BITRATE_VBR
block|,
comment|/* variable bitrate */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|v4l2_bitrate
block|{
comment|/* rates are specified in kbit/sec */
name|enum
name|v4l2_bitrate_mode
name|mode
decl_stmt|;
name|__u32
name|min
decl_stmt|;
name|__u32
name|target
decl_stmt|;
comment|/* use this one for CBR */
name|__u32
name|max
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|v4l2_mpeg_streamtype
block|{
name|V4L2_MPEG_SS_1
block|,
comment|/* MPEG-1 system stream */
name|V4L2_MPEG_PS_2
block|,
comment|/* MPEG-2 program stream */
name|V4L2_MPEG_TS_2
block|,
comment|/* MPEG-2 transport stream */
name|V4L2_MPEG_PS_DVD
block|,
comment|/* MPEG-2 program stream with DVD header fixups */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_mpeg_audiotype
block|{
name|V4L2_MPEG_AU_2_I
block|,
comment|/* MPEG-2 layer 1 */
name|V4L2_MPEG_AU_2_II
block|,
comment|/* MPEG-2 layer 2 */
name|V4L2_MPEG_AU_2_III
block|,
comment|/* MPEG-2 layer 3 */
name|V4L2_MPEG_AC3
block|,
comment|/* AC3 */
name|V4L2_MPEG_LPCM
block|,
comment|/* LPCM */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_mpeg_videotype
block|{
name|V4L2_MPEG_VI_1
block|,
comment|/* MPEG-1 */
name|V4L2_MPEG_VI_2
block|,
comment|/* MPEG-2 */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|v4l2_mpeg_aspectratio
block|{
name|V4L2_MPEG_ASPECT_SQUARE
init|=
literal|1
block|,
comment|/* square pixel */
name|V4L2_MPEG_ASPECT_4_3
init|=
literal|2
block|,
comment|/*  4 : 3       */
name|V4L2_MPEG_ASPECT_16_9
init|=
literal|3
block|,
comment|/* 16 : 9       */
name|V4L2_MPEG_ASPECT_1_221
init|=
literal|4
block|,
comment|/*  1 : 2,21    */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|v4l2_mpeg_compression
block|{
comment|/* general */
name|enum
name|v4l2_mpeg_streamtype
name|st_type
decl_stmt|;
name|struct
name|v4l2_bitrate
name|st_bitrate
decl_stmt|;
comment|/* transport streams */
name|__u16
name|ts_pid_pmt
decl_stmt|;
name|__u16
name|ts_pid_audio
decl_stmt|;
name|__u16
name|ts_pid_video
decl_stmt|;
name|__u16
name|ts_pid_pcr
decl_stmt|;
comment|/* program stream */
name|__u16
name|ps_size
decl_stmt|;
name|__u16
name|reserved_1
decl_stmt|;
comment|/* align */
comment|/* audio */
name|enum
name|v4l2_mpeg_audiotype
name|au_type
decl_stmt|;
name|struct
name|v4l2_bitrate
name|au_bitrate
decl_stmt|;
name|__u32
name|au_sample_rate
decl_stmt|;
name|__u8
name|au_pesid
decl_stmt|;
name|__u8
name|reserved_2
index|[
literal|3
index|]
decl_stmt|;
comment|/* align */
comment|/* video */
name|enum
name|v4l2_mpeg_videotype
name|vi_type
decl_stmt|;
name|enum
name|v4l2_mpeg_aspectratio
name|vi_aspect_ratio
decl_stmt|;
name|struct
name|v4l2_bitrate
name|vi_bitrate
decl_stmt|;
name|__u32
name|vi_frame_rate
decl_stmt|;
name|__u16
name|vi_frames_per_gop
decl_stmt|;
name|__u16
name|vi_bframes_count
decl_stmt|;
name|__u8
name|vi_pesid
decl_stmt|;
name|__u8
name|reserved_3
index|[
literal|3
index|]
decl_stmt|;
comment|/* align */
comment|/* misc flags */
name|__u32
name|closed_gops
range|:
literal|1
decl_stmt|;
name|__u32
name|pulldown
range|:
literal|1
decl_stmt|;
name|__u32
name|reserved_4
range|:
literal|30
decl_stmt|;
comment|/* align */
comment|/* I don't expect the above being perfect yet ;) */
name|__u32
name|reserved_5
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* Which markers should go into the JPEG 				 * output. Unless you exactly know what 				 * you do, leave them untouched. 				 * Inluding less markers will make the 				 * resulting code smaller, but there will 				 * be fewer aplications which can read it. 				 * The presence of the APP and COM marker 				 * is influenced by APP_len and COM_len 				 * ONLY, not by this property! */
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
name|reserved
index|[
literal|4
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
name|reserved
index|[
literal|4
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

begin_comment
comment|/*  Control IDs defined by V4L2 */
end_comment

begin_define
define|#
directive|define
name|V4L2_CID_BASE
value|0x00980900
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
comment|/* ? Not sure */
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
name|V4L2_CID_LASTP1
value|(V4L2_CID_BASE+24)
end_define

begin_comment
comment|/* last CID + 1 */
end_comment

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

begin_if
if|#
directive|if
literal|1
end_if

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
name|__u32
name|reserved
index|[
literal|4
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

begin_endif
endif|#
directive|endif
end_endif

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
comment|// V4L2_BUF_TYPE_VIDEO_CAPTURE
name|struct
name|v4l2_window
name|win
decl_stmt|;
comment|// V4L2_BUF_TYPE_VIDEO_OVERLAY
name|struct
name|v4l2_vbi_format
name|vbi
decl_stmt|;
comment|// V4L2_BUF_TYPE_VBI_CAPTURE
if|#
directive|if
literal|1
name|struct
name|v4l2_sliced_vbi_format
name|sliced
decl_stmt|;
comment|// V4L2_BUF_TYPE_SLICED_VBI_CAPTURE
endif|#
directive|endif
name|__u8
name|raw_data
index|[
literal|200
index|]
decl_stmt|;
comment|// user-defined
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
comment|/*  *	I O C T L   C O D E S   F O R   V I D E O   D E V I C E S  *  */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_QUERYCAP
value|_IOR  ('V',  0, struct v4l2_capability)
end_define

begin_define
define|#
directive|define
name|VIDIOC_RESERVED
value|_IO   ('V',  1)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUM_FMT
value|_IOWR ('V',  2, struct v4l2_fmtdesc)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FMT
value|_IOWR ('V',  4, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FMT
value|_IOWR ('V',  5, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_MPEGCOMP
value|_IOR  ('V',  6, struct v4l2_mpeg_compression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_MPEGCOMP
value|_IOW  ('V',  7, struct v4l2_mpeg_compression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_REQBUFS
value|_IOWR ('V',  8, struct v4l2_requestbuffers)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYBUF
value|_IOWR ('V',  9, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FBUF
value|_IOR  ('V', 10, struct v4l2_framebuffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FBUF
value|_IOW  ('V', 11, struct v4l2_framebuffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_OVERLAY
value|_IOW  ('V', 14, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QBUF
value|_IOWR ('V', 15, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_DQBUF
value|_IOWR ('V', 17, struct v4l2_buffer)
end_define

begin_define
define|#
directive|define
name|VIDIOC_STREAMON
value|_IOW  ('V', 18, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_STREAMOFF
value|_IOW  ('V', 19, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_PARM
value|_IOWR ('V', 21, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PARM
value|_IOWR ('V', 22, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_STD
value|_IOR  ('V', 23, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_STD
value|_IOW  ('V', 24, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMSTD
value|_IOWR ('V', 25, struct v4l2_standard)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMINPUT
value|_IOWR ('V', 26, struct v4l2_input)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_CTRL
value|_IOWR ('V', 27, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CTRL
value|_IOWR ('V', 28, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_TUNER
value|_IOWR ('V', 29, struct v4l2_tuner)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_TUNER
value|_IOW  ('V', 30, struct v4l2_tuner)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDIO
value|_IOR  ('V', 33, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_AUDIO
value|_IOW  ('V', 34, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYCTRL
value|_IOWR ('V', 36, struct v4l2_queryctrl)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYMENU
value|_IOWR ('V', 37, struct v4l2_querymenu)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_INPUT
value|_IOR  ('V', 38, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_INPUT
value|_IOWR ('V', 39, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_OUTPUT
value|_IOR  ('V', 46, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_OUTPUT
value|_IOWR ('V', 47, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMOUTPUT
value|_IOWR ('V', 48, struct v4l2_output)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDOUT
value|_IOR  ('V', 49, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_AUDOUT
value|_IOW  ('V', 50, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_MODULATOR
value|_IOWR ('V', 54, struct v4l2_modulator)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_MODULATOR
value|_IOW  ('V', 55, struct v4l2_modulator)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_FREQUENCY
value|_IOWR ('V', 56, struct v4l2_frequency)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_FREQUENCY
value|_IOW  ('V', 57, struct v4l2_frequency)
end_define

begin_define
define|#
directive|define
name|VIDIOC_CROPCAP
value|_IOWR ('V', 58, struct v4l2_cropcap)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_CROP
value|_IOWR ('V', 59, struct v4l2_crop)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CROP
value|_IOW  ('V', 60, struct v4l2_crop)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_JPEGCOMP
value|_IOR  ('V', 61, struct v4l2_jpegcompression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_JPEGCOMP
value|_IOW  ('V', 62, struct v4l2_jpegcompression)
end_define

begin_define
define|#
directive|define
name|VIDIOC_QUERYSTD
value|_IOR  ('V', 63, v4l2_std_id)
end_define

begin_define
define|#
directive|define
name|VIDIOC_TRY_FMT
value|_IOWR ('V', 64, struct v4l2_format)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMAUDIO
value|_IOWR ('V', 65, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_ENUMAUDOUT
value|_IOWR ('V', 66, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_PRIORITY
value|_IOR  ('V', 67, enum v4l2_priority)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PRIORITY
value|_IOW  ('V', 68, enum v4l2_priority)
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_define
define|#
directive|define
name|VIDIOC_G_SLICED_VBI_CAP
value|_IOR  ('V', 69, struct v4l2_sliced_vbi_cap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VIDIOC_LOG_STATUS
value|_IO   ('V', 70)
end_define

begin_comment
comment|/* for compatibility, will go away some day */
end_comment

begin_define
define|#
directive|define
name|VIDIOC_OVERLAY_OLD
value|_IOWR ('V', 14, int)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_PARM_OLD
value|_IOW  ('V', 22, struct v4l2_streamparm)
end_define

begin_define
define|#
directive|define
name|VIDIOC_S_CTRL_OLD
value|_IOW  ('V', 28, struct v4l2_control)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDIO_OLD
value|_IOWR ('V', 33, struct v4l2_audio)
end_define

begin_define
define|#
directive|define
name|VIDIOC_G_AUDOUT_OLD
value|_IOWR ('V', 49, struct v4l2_audioout)
end_define

begin_define
define|#
directive|define
name|VIDIOC_CROPCAP_OLD
value|_IOR  ('V', 58, struct v4l2_cropcap)
end_define

begin_define
define|#
directive|define
name|BASE_VIDIOC_PRIVATE
value|192
end_define

begin_comment
comment|/* 192-255 are private */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_comment
comment|/*  *  *	V 4 L 2   D R I V E R   H E L P E R   A P I  *  *	Some commonly needed functions for drivers (v4l2-common.o module)  */
end_comment

begin_include
include|#
directive|include
file|<linux/fs.h>
end_include

begin_comment
comment|/*  Video standard functions  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|v4l2_video_std_fps
parameter_list|(
name|struct
name|v4l2_standard
modifier|*
name|vs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|v4l2_video_std_construct
parameter_list|(
name|struct
name|v4l2_standard
modifier|*
name|vs
parameter_list|,
name|int
name|id
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* prority handling */
end_comment

begin_struct
struct|struct
name|v4l2_prio_state
block|{
name|atomic_t
name|prios
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|v4l2_prio_init
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|v4l2_prio_change
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|,
name|enum
name|v4l2_priority
modifier|*
name|local
parameter_list|,
name|enum
name|v4l2_priority
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|v4l2_prio_open
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|,
name|enum
name|v4l2_priority
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|v4l2_prio_close
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|,
name|enum
name|v4l2_priority
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|v4l2_priority
name|v4l2_prio_max
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|v4l2_prio_check
parameter_list|(
name|struct
name|v4l2_prio_state
modifier|*
name|global
parameter_list|,
name|enum
name|v4l2_priority
modifier|*
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* names for fancy debug output */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|v4l2_field_names
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|v4l2_type_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  Compatibility layer interface  --  v4l1-compat module */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|v4l2_kioctl
function_decl|)
parameter_list|(
name|struct
name|inode
modifier|*
name|inode
parameter_list|,
name|struct
name|file
modifier|*
name|file
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_VIDEO_V4L1_COMPAT
end_ifdef

begin_function_decl
name|int
name|v4l_compat_translate_ioctl
parameter_list|(
name|struct
name|inode
modifier|*
name|inode
parameter_list|,
name|struct
name|file
modifier|*
name|file
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|v4l2_kioctl
name|driver_ioctl
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|v4l_compat_translate_ioctl
parameter_list|(
name|inode
parameter_list|,
name|file
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|,
name|ioctl
parameter_list|)
value|-EINVAL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 32 Bits compatibility layer for 64 bits processors */
end_comment

begin_function_decl
specifier|extern
name|long
name|v4l_compat_ioctl32
parameter_list|(
name|struct
name|file
modifier|*
name|file
parameter_list|,
name|unsigned
name|int
name|cmd
parameter_list|,
name|unsigned
name|long
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LINUX_VIDEODEV2_H */
end_comment

begin_comment
comment|/*  * Local variables:  * c-basic-offset: 8  * End:  */
end_comment

end_unit

