begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header comes from linux, but it has no license. The author  * (Alan Cox @ Redhat) gave explicit permissions to use it in FreeBSD.  * The freeBSD vendor branch for v4l gives a more detailed description  * about this.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LINUX_VIDEODEV_H
end_ifndef

begin_define
define|#
directive|define
name|__LINUX_VIDEODEV_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|int32_t
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__u8
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|HAVE_V4L1
value|1
end_define

begin_include
include|#
directive|include
file|<linux/videodev2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

begin_struct
struct|struct
name|video_capability
block|{
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|channels
decl_stmt|;
comment|/* Num channels */
name|int
name|audios
decl_stmt|;
comment|/* Num audio devices */
name|int
name|maxwidth
decl_stmt|;
comment|/* Supported width */
name|int
name|maxheight
decl_stmt|;
comment|/* And height */
name|int
name|minwidth
decl_stmt|;
comment|/* Supported width */
name|int
name|minheight
decl_stmt|;
comment|/* And height */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_channel
block|{
name|int
name|channel
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|tuners
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
define|#
directive|define
name|VIDEO_VC_TUNER
value|1
comment|/* Channel has a tuner */
define|#
directive|define
name|VIDEO_VC_AUDIO
value|2
comment|/* Channel has audio */
name|__u16
name|type
decl_stmt|;
define|#
directive|define
name|VIDEO_TYPE_TV
value|1
define|#
directive|define
name|VIDEO_TYPE_CAMERA
value|2
name|__u16
name|norm
decl_stmt|;
comment|/* Norm set by channel */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_tuner
block|{
name|int
name|tuner
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|long
name|rangelow
decl_stmt|,
name|rangehigh
decl_stmt|;
comment|/* Tuner range */
name|__u32
name|flags
decl_stmt|;
define|#
directive|define
name|VIDEO_TUNER_PAL
value|1
define|#
directive|define
name|VIDEO_TUNER_NTSC
value|2
define|#
directive|define
name|VIDEO_TUNER_SECAM
value|4
define|#
directive|define
name|VIDEO_TUNER_LOW
value|8
comment|/* Uses KHz not MHz */
define|#
directive|define
name|VIDEO_TUNER_NORM
value|16
comment|/* Tuner can set norm */
define|#
directive|define
name|VIDEO_TUNER_STEREO_ON
value|128
comment|/* Tuner is seeing stereo */
define|#
directive|define
name|VIDEO_TUNER_RDS_ON
value|256
comment|/* Tuner is seeing an RDS datastream */
define|#
directive|define
name|VIDEO_TUNER_MBS_ON
value|512
comment|/* Tuner is seeing an MBS datastream */
name|__u16
name|mode
decl_stmt|;
comment|/* PAL/NTSC/SECAM/OTHER */
define|#
directive|define
name|VIDEO_MODE_PAL
value|0
define|#
directive|define
name|VIDEO_MODE_NTSC
value|1
define|#
directive|define
name|VIDEO_MODE_SECAM
value|2
define|#
directive|define
name|VIDEO_MODE_AUTO
value|3
name|__u16
name|signal
decl_stmt|;
comment|/* Signal strength 16bit scale */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_picture
block|{
name|__u16
name|brightness
decl_stmt|;
name|__u16
name|hue
decl_stmt|;
name|__u16
name|colour
decl_stmt|;
name|__u16
name|contrast
decl_stmt|;
name|__u16
name|whiteness
decl_stmt|;
comment|/* Black and white only */
name|__u16
name|depth
decl_stmt|;
comment|/* Capture depth */
name|__u16
name|palette
decl_stmt|;
comment|/* Palette in use */
define|#
directive|define
name|VIDEO_PALETTE_GREY
value|1
comment|/* Linear greyscale */
define|#
directive|define
name|VIDEO_PALETTE_HI240
value|2
comment|/* High 240 cube (BT848) */
define|#
directive|define
name|VIDEO_PALETTE_RGB565
value|3
comment|/* 565 16 bit RGB */
define|#
directive|define
name|VIDEO_PALETTE_RGB24
value|4
comment|/* 24bit RGB */
define|#
directive|define
name|VIDEO_PALETTE_RGB32
value|5
comment|/* 32bit RGB */
define|#
directive|define
name|VIDEO_PALETTE_RGB555
value|6
comment|/* 555 15bit RGB */
define|#
directive|define
name|VIDEO_PALETTE_YUV422
value|7
comment|/* YUV422 capture */
define|#
directive|define
name|VIDEO_PALETTE_YUYV
value|8
define|#
directive|define
name|VIDEO_PALETTE_UYVY
value|9
comment|/* The great thing about standards is ... */
define|#
directive|define
name|VIDEO_PALETTE_YUV420
value|10
define|#
directive|define
name|VIDEO_PALETTE_YUV411
value|11
comment|/* YUV411 capture */
define|#
directive|define
name|VIDEO_PALETTE_RAW
value|12
comment|/* RAW capture (BT848) */
define|#
directive|define
name|VIDEO_PALETTE_YUV422P
value|13
comment|/* YUV 4:2:2 Planar */
define|#
directive|define
name|VIDEO_PALETTE_YUV411P
value|14
comment|/* YUV 4:1:1 Planar */
define|#
directive|define
name|VIDEO_PALETTE_YUV420P
value|15
comment|/* YUV 4:2:0 Planar */
define|#
directive|define
name|VIDEO_PALETTE_YUV410P
value|16
comment|/* YUV 4:1:0 Planar */
define|#
directive|define
name|VIDEO_PALETTE_PLANAR
value|13
comment|/* start of planar entries */
define|#
directive|define
name|VIDEO_PALETTE_COMPONENT
value|7
comment|/* start of component entries */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_audio
block|{
name|int
name|audio
decl_stmt|;
comment|/* Audio channel */
name|__u16
name|volume
decl_stmt|;
comment|/* If settable */
name|__u16
name|bass
decl_stmt|,
name|treble
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
define|#
directive|define
name|VIDEO_AUDIO_MUTE
value|1
define|#
directive|define
name|VIDEO_AUDIO_MUTABLE
value|2
define|#
directive|define
name|VIDEO_AUDIO_VOLUME
value|4
define|#
directive|define
name|VIDEO_AUDIO_BASS
value|8
define|#
directive|define
name|VIDEO_AUDIO_TREBLE
value|16
define|#
directive|define
name|VIDEO_AUDIO_BALANCE
value|32
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
define|#
directive|define
name|VIDEO_SOUND_MONO
value|1
define|#
directive|define
name|VIDEO_SOUND_STEREO
value|2
define|#
directive|define
name|VIDEO_SOUND_LANG1
value|4
define|#
directive|define
name|VIDEO_SOUND_LANG2
value|8
name|__u16
name|mode
decl_stmt|;
name|__u16
name|balance
decl_stmt|;
comment|/* Stereo balance */
name|__u16
name|step
decl_stmt|;
comment|/* Step actual volume uses */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_clip
block|{
name|__s32
name|x
decl_stmt|,
name|y
decl_stmt|;
name|__s32
name|width
decl_stmt|,
name|height
decl_stmt|;
name|struct
name|video_clip
modifier|*
name|next
decl_stmt|;
comment|/* For user use/driver use only */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_window
block|{
name|__u32
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Position of window */
name|__u32
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* Its size */
name|__u32
name|chromakey
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
name|struct
name|video_clip
modifier|*
name|clips
decl_stmt|;
comment|/* Set only */
name|int
name|clipcount
decl_stmt|;
define|#
directive|define
name|VIDEO_WINDOW_INTERLACE
value|1
define|#
directive|define
name|VIDEO_WINDOW_CHROMAKEY
value|16
comment|/* Overlay by chromakey */
define|#
directive|define
name|VIDEO_CLIP_BITMAP
value|-1
comment|/* bitmap is 1024x625, a '1' bit represents a clipped pixel */
define|#
directive|define
name|VIDEO_CLIPMAP_SIZE
value|(128 * 625)
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_capture
block|{
name|__u32
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* Offsets into image */
name|__u32
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* Area to capture */
name|__u16
name|decimation
decl_stmt|;
comment|/* Decimation divider */
name|__u16
name|flags
decl_stmt|;
comment|/* Flags for capture */
define|#
directive|define
name|VIDEO_CAPTURE_ODD
value|0
comment|/* Temporal */
define|#
directive|define
name|VIDEO_CAPTURE_EVEN
value|1
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_buffer
block|{
name|void
modifier|*
name|base
decl_stmt|;
name|int
name|height
decl_stmt|,
name|width
decl_stmt|;
name|int
name|depth
decl_stmt|;
name|int
name|bytesperline
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_mmap
block|{
name|unsigned
name|int
name|frame
decl_stmt|;
comment|/* Frame (0 - n) for double buffer */
name|int
name|height
decl_stmt|,
name|width
decl_stmt|;
name|unsigned
name|int
name|format
decl_stmt|;
comment|/* should be VIDEO_PALETTE_* */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|video_key
block|{
name|__u8
name|key
index|[
literal|8
index|]
decl_stmt|;
name|__u32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIDEO_MAX_FRAME
value|32
end_define

begin_struct
struct|struct
name|video_mbuf
block|{
name|int
name|size
decl_stmt|;
comment|/* Total memory to map */
name|int
name|frames
decl_stmt|;
comment|/* Frames */
name|int
name|offsets
index|[
name|VIDEO_MAX_FRAME
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIDEO_NO_UNIT
value|(-1)
end_define

begin_struct
struct|struct
name|video_unit
block|{
name|int
name|video
decl_stmt|;
comment|/* Video minor */
name|int
name|vbi
decl_stmt|;
comment|/* VBI minor */
name|int
name|radio
decl_stmt|;
comment|/* Radio minor */
name|int
name|audio
decl_stmt|;
comment|/* Audio minor */
name|int
name|teletext
decl_stmt|;
comment|/* Teletext minor */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vbi_format
block|{
name|__u32
name|sampling_rate
decl_stmt|;
comment|/* in Hz */
name|__u32
name|samples_per_line
decl_stmt|;
name|__u32
name|sample_format
decl_stmt|;
comment|/* VIDEO_PALETTE_RAW only (1 byte) */
name|__s32
name|start
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting line for each frame */
name|__u32
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* count of lines for each frame */
name|__u32
name|flags
decl_stmt|;
define|#
directive|define
name|VBI_UNSYNC
value|1
comment|/* can distingues between top/bottom field */
define|#
directive|define
name|VBI_INTERLACED
value|2
comment|/* lines are interlaced */
block|}
struct|;
end_struct

begin_comment
comment|/* video_info is biased towards hardware mpeg encode/decode */
end_comment

begin_comment
comment|/* but it could apply generically to any hardware compressor/decompressor */
end_comment

begin_struct
struct|struct
name|video_info
block|{
name|__u32
name|frame_count
decl_stmt|;
comment|/* frames output since decode/encode began */
name|__u32
name|h_size
decl_stmt|;
comment|/* current unscaled horizontal size */
name|__u32
name|v_size
decl_stmt|;
comment|/* current unscaled veritcal size */
name|__u32
name|smpte_timecode
decl_stmt|;
comment|/* current SMPTE timecode (for current GOP) */
name|__u32
name|picture_type
decl_stmt|;
comment|/* current picture type */
name|__u32
name|temporal_reference
decl_stmt|;
comment|/* current temporal reference */
name|__u8
name|user_data
index|[
literal|256
index|]
decl_stmt|;
comment|/* user data last found in compressed stream */
comment|/* user_data[0] contains user data flags, user_data[1] has count */
block|}
struct|;
end_struct

begin_comment
comment|/* generic structure for setting playback modes */
end_comment

begin_struct
struct|struct
name|video_play_mode
block|{
name|int
name|mode
decl_stmt|;
name|int
name|p1
decl_stmt|;
name|int
name|p2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* for loading microcode / fpga programming */
end_comment

begin_struct
struct|struct
name|video_code
block|{
name|char
name|loadwhat
index|[
literal|16
index|]
decl_stmt|;
comment|/* name or tag of file being passed */
name|int
name|datasize
decl_stmt|;
name|__u8
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VIDIOCGCAP
value|_IOR('v',1,struct video_capability)
end_define

begin_comment
comment|/* Get capabilities */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGCHAN
value|_IOWR('v',2,struct video_channel)
end_define

begin_comment
comment|/* Get channel info (sources) */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSCHAN
value|_IOW('v',3,struct video_channel)
end_define

begin_comment
comment|/* Set channel 	*/
end_comment

begin_define
define|#
directive|define
name|VIDIOCGTUNER
value|_IOWR('v',4,struct video_tuner)
end_define

begin_comment
comment|/* Get tuner abilities */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSTUNER
value|_IOW('v',5,struct video_tuner)
end_define

begin_comment
comment|/* Tune the tuner for the current channel */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGPICT
value|_IOR('v',6,struct video_picture)
end_define

begin_comment
comment|/* Get picture properties */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSPICT
value|_IOW('v',7,struct video_picture)
end_define

begin_comment
comment|/* Set picture properties */
end_comment

begin_define
define|#
directive|define
name|VIDIOCCAPTURE
value|_IOW('v',8,int)
end_define

begin_comment
comment|/* Start, end capture */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGWIN
value|_IOR('v',9, struct video_window)
end_define

begin_comment
comment|/* Get the video overlay window */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSWIN
value|_IOW('v',10, struct video_window)
end_define

begin_comment
comment|/* Set the video overlay window - passes clip list for hardware smarts , chromakey etc */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGFBUF
value|_IOR('v',11, struct video_buffer)
end_define

begin_comment
comment|/* Get frame buffer */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSFBUF
value|_IOW('v',12, struct video_buffer)
end_define

begin_comment
comment|/* Set frame buffer - root only */
end_comment

begin_define
define|#
directive|define
name|VIDIOCKEY
value|_IOR('v',13, struct video_key)
end_define

begin_comment
comment|/* Video key event - to dev 255 is to all - cuts capture on all DMA windows with this key (0xFFFFFFFF == all) */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGFREQ
value|_IOR('v',14, unsigned long)
end_define

begin_comment
comment|/* Set tuner */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSFREQ
value|_IOW('v',15, unsigned long)
end_define

begin_comment
comment|/* Set tuner */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGAUDIO
value|_IOR('v',16, struct video_audio)
end_define

begin_comment
comment|/* Get audio info */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSAUDIO
value|_IOW('v',17, struct video_audio)
end_define

begin_comment
comment|/* Audio source, mute etc */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSYNC
value|_IOW('v',18, int)
end_define

begin_comment
comment|/* Sync with mmap grabbing */
end_comment

begin_define
define|#
directive|define
name|VIDIOCMCAPTURE
value|_IOW('v',19, struct video_mmap)
end_define

begin_comment
comment|/* Grab frames */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGMBUF
value|_IOR('v',20, struct video_mbuf)
end_define

begin_comment
comment|/* Memory map buffer info */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGUNIT
value|_IOR('v',21, struct video_unit)
end_define

begin_comment
comment|/* Get attached units */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGCAPTURE
value|_IOR('v',22, struct video_capture)
end_define

begin_comment
comment|/* Get subcapture */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSCAPTURE
value|_IOW('v',23, struct video_capture)
end_define

begin_comment
comment|/* Set subcapture */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSPLAYMODE
value|_IOW('v',24, struct video_play_mode)
end_define

begin_comment
comment|/* Set output video mode/feature */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSWRITEMODE
value|_IOW('v',25, int)
end_define

begin_comment
comment|/* Set write mode */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGPLAYINFO
value|_IOR('v',26, struct video_info)
end_define

begin_comment
comment|/* Get current playback info from hardware */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSMICROCODE
value|_IOW('v',27, struct video_code)
end_define

begin_comment
comment|/* Load microcode into hardware */
end_comment

begin_define
define|#
directive|define
name|VIDIOCGVBIFMT
value|_IOR('v',28, struct vbi_format)
end_define

begin_comment
comment|/* Get VBI information */
end_comment

begin_define
define|#
directive|define
name|VIDIOCSVBIFMT
value|_IOW('v',29, struct vbi_format)
end_define

begin_comment
comment|/* Set VBI information */
end_comment

begin_define
define|#
directive|define
name|BASE_VIDIOCPRIVATE
value|192
end_define

begin_comment
comment|/* 192-255 are private */
end_comment

begin_comment
comment|/* VIDIOCSWRITEMODE */
end_comment

begin_define
define|#
directive|define
name|VID_WRITE_MPEG_AUD
value|0
end_define

begin_define
define|#
directive|define
name|VID_WRITE_MPEG_VID
value|1
end_define

begin_define
define|#
directive|define
name|VID_WRITE_OSD
value|2
end_define

begin_define
define|#
directive|define
name|VID_WRITE_TTX
value|3
end_define

begin_define
define|#
directive|define
name|VID_WRITE_CC
value|4
end_define

begin_define
define|#
directive|define
name|VID_WRITE_MJPEG
value|5
end_define

begin_comment
comment|/* VIDIOCSPLAYMODE */
end_comment

begin_define
define|#
directive|define
name|VID_PLAY_VID_OUT_MODE
value|0
end_define

begin_comment
comment|/* p1: = VIDEO_MODE_PAL, VIDEO_MODE_NTSC, etc ... */
end_comment

begin_define
define|#
directive|define
name|VID_PLAY_GENLOCK
value|1
end_define

begin_comment
comment|/* p1: 0 = OFF, 1 = ON */
end_comment

begin_comment
comment|/* p2: GENLOCK FINE DELAY value */
end_comment

begin_define
define|#
directive|define
name|VID_PLAY_NORMAL
value|2
end_define

begin_define
define|#
directive|define
name|VID_PLAY_PAUSE
value|3
end_define

begin_define
define|#
directive|define
name|VID_PLAY_SINGLE_FRAME
value|4
end_define

begin_define
define|#
directive|define
name|VID_PLAY_FAST_FORWARD
value|5
end_define

begin_define
define|#
directive|define
name|VID_PLAY_SLOW_MOTION
value|6
end_define

begin_define
define|#
directive|define
name|VID_PLAY_IMMEDIATE_NORMAL
value|7
end_define

begin_define
define|#
directive|define
name|VID_PLAY_SWITCH_CHANNELS
value|8
end_define

begin_define
define|#
directive|define
name|VID_PLAY_FREEZE_FRAME
value|9
end_define

begin_define
define|#
directive|define
name|VID_PLAY_STILL_MODE
value|10
end_define

begin_define
define|#
directive|define
name|VID_PLAY_MASTER_MODE
value|11
end_define

begin_comment
comment|/* p1: see below */
end_comment

begin_define
define|#
directive|define
name|VID_PLAY_MASTER_NONE
value|1
end_define

begin_define
define|#
directive|define
name|VID_PLAY_MASTER_VIDEO
value|2
end_define

begin_define
define|#
directive|define
name|VID_PLAY_MASTER_AUDIO
value|3
end_define

begin_define
define|#
directive|define
name|VID_PLAY_ACTIVE_SCANLINES
value|12
end_define

begin_comment
comment|/* p1 = first active; p2 = last active */
end_comment

begin_define
define|#
directive|define
name|VID_PLAY_RESET
value|13
end_define

begin_define
define|#
directive|define
name|VID_PLAY_END_MARK
value|14
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_BT848
value|1
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_QCAM_BW
value|2
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_PMS
value|3
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_QCAM_C
value|4
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_PSEUDO
value|5
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SAA5249
value|6
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_AZTECH
value|7
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SF16MI
value|8
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_RTRACK
value|9
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_ZOLTRIX
value|10
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SAA7146
value|11
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_VIDEUM
value|12
end_define

begin_comment
comment|/* Reserved for Winnov videum */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_RTRACK2
value|13
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_PERMEDIA2
value|14
end_define

begin_comment
comment|/* Reserved for Permedia2 */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_RIVA128
value|15
end_define

begin_comment
comment|/* Reserved for RIVA 128 */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_PLANB
value|16
end_define

begin_comment
comment|/* PowerMac motherboard video-in */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_BROADWAY
value|17
end_define

begin_comment
comment|/* Broadway project */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_GEMTEK
value|18
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_TYPHOON
value|19
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_VINO
value|20
end_define

begin_comment
comment|/* SGI Indy Vino */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_CADET
value|21
end_define

begin_comment
comment|/* Cadet radio */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_TRUST
value|22
end_define

begin_comment
comment|/* Trust FM Radio */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_TERRATEC
value|23
end_define

begin_comment
comment|/* TerraTec ActiveRadio */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_CPIA
value|24
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_ZR36120
value|25
end_define

begin_comment
comment|/* Zoran ZR36120/ZR36125 */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_ZR36067
value|26
end_define

begin_comment
comment|/* Zoran ZR36067/36060 */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_OV511
value|27
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_ZR356700
value|28
end_define

begin_comment
comment|/* Zoran 36700 series */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_W9966
value|29
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SE401
value|30
end_define

begin_comment
comment|/* SE401 USB webcams */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_PWC
value|31
end_define

begin_comment
comment|/* Philips webcams */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_MEYE
value|32
end_define

begin_comment
comment|/* Sony Vaio MotionEye cameras */
end_comment

begin_define
define|#
directive|define
name|VID_HARDWARE_CPIA2
value|33
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_VICAM
value|34
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SF16FMR2
value|35
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_W9968CF
value|36
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SAA7114H
value|37
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_SN9C102
value|38
end_define

begin_define
define|#
directive|define
name|VID_HARDWARE_ARV
value|39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LINUX_VIDEODEV_H */
end_comment

begin_comment
comment|/*  * Local variables:  * c-basic-offset: 8  * End:  */
end_comment

end_unit

