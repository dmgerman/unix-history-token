begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 16 Feb 93	Julian Elischer	(julian@dialix.oz.au)  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*<1>	Fixed a conflict with ioctl usage.  There were two different 	functions using code #25.  Made file formatting consistent. 	Added two new ioctl codes: door closing and audio pitch playback. 	Added a STEREO union called STEREO. 	5-Mar-95  Frank Durda IV	bsdmail@nemesis.lonestar.org<2>	Added a new ioctl that allows you to find out what capabilities 	a drive has and what commands it will accept.  This allows a 	user application to only offer controls (buttons, sliders, etc) 	for functions that drive can actually do.   Things it can't do 	can disappear or be greyed-out (like some other system). 	If the driver doesn't respond to this call, well, handle it the 	way you used to do it. 	2-Apr-95  Frank Durda IV	bsdmail@nemesis.lonestar.org */
end_comment

begin_comment
comment|/* Shared between kernel& process */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CDIO_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_union
union|union
name|msf_lba
block|{
struct|struct
block|{
name|unsigned
name|char
name|unused
decl_stmt|;
name|unsigned
name|char
name|minute
decl_stmt|;
name|unsigned
name|char
name|second
decl_stmt|;
name|unsigned
name|char
name|frame
decl_stmt|;
block|}
name|msf
struct|;
name|int
name|lba
decl_stmt|;
comment|/* network byte order */
name|u_char
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|cd_toc_entry
block|{
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
name|control
range|:
literal|4
decl_stmt|;
name|u_int
name|addr_type
range|:
literal|4
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|union
name|msf_lba
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_header
block|{
name|u_int
label|:
literal|8
expr_stmt|;
name|u_char
name|audio_status
decl_stmt|;
define|#
directive|define
name|CD_AS_AUDIO_INVALID
value|0x00
define|#
directive|define
name|CD_AS_PLAY_IN_PROGRESS
value|0x11
define|#
directive|define
name|CD_AS_PLAY_PAUSED
value|0x12
define|#
directive|define
name|CD_AS_PLAY_COMPLETED
value|0x13
define|#
directive|define
name|CD_AS_PLAY_ERROR
value|0x14
define|#
directive|define
name|CD_AS_NO_STATUS
value|0x15
name|u_char
name|data_len
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_position_data
block|{
name|u_char
name|data_format
decl_stmt|;
name|u_int
name|control
range|:
literal|4
decl_stmt|;
name|u_int
name|addr_type
range|:
literal|4
decl_stmt|;
name|u_char
name|track_number
decl_stmt|;
name|u_char
name|index_number
decl_stmt|;
name|union
name|msf_lba
name|absaddr
decl_stmt|;
name|union
name|msf_lba
name|reladdr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_media_catalog
block|{
name|u_char
name|data_format
decl_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
label|:
literal|7
expr_stmt|;
name|u_int
name|mc_valid
range|:
literal|1
decl_stmt|;
name|u_char
name|mc_number
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_track_info
block|{
name|u_char
name|data_format
decl_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_char
name|track_number
decl_stmt|;
name|u_int
label|:
literal|8
expr_stmt|;
name|u_int
label|:
literal|7
expr_stmt|;
name|u_int
name|ti_valid
range|:
literal|1
decl_stmt|;
name|u_char
name|ti_number
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_info
block|{
name|struct
name|cd_sub_channel_header
name|header
decl_stmt|;
union|union
block|{
name|struct
name|cd_sub_channel_position_data
name|position
decl_stmt|;
name|struct
name|cd_sub_channel_media_catalog
name|media_catalog
decl_stmt|;
name|struct
name|cd_sub_channel_track_info
name|track_info
decl_stmt|;
block|}
name|what
union|;
block|}
struct|;
end_struct

begin_comment
comment|/***************************************************************\ * Ioctls for the CD drive					* \***************************************************************/
end_comment

begin_struct
struct|struct
name|ioc_play_track
block|{
name|u_char
name|start_track
decl_stmt|;
name|u_char
name|start_index
decl_stmt|;
name|u_char
name|end_track
decl_stmt|;
name|u_char
name|end_index
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCPLAYTRACKS
value|_IOW('c',1,struct ioc_play_track)
end_define

begin_struct
struct|struct
name|ioc_play_blocks
block|{
name|int
name|blk
decl_stmt|;
name|int
name|len
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCPLAYBLOCKS
value|_IOW('c',2,struct ioc_play_blocks)
end_define

begin_struct
struct|struct
name|ioc_read_subchannel
block|{
name|u_char
name|address_format
decl_stmt|;
define|#
directive|define
name|CD_LBA_FORMAT
value|1
define|#
directive|define
name|CD_MSF_FORMAT
value|2
name|u_char
name|data_format
decl_stmt|;
define|#
directive|define
name|CD_SUBQ_DATA
value|0
define|#
directive|define
name|CD_CURRENT_POSITION
value|1
define|#
directive|define
name|CD_MEDIA_CATALOG
value|2
define|#
directive|define
name|CD_TRACK_INFO
value|3
name|u_char
name|track
decl_stmt|;
name|int
name|data_len
decl_stmt|;
name|struct
name|cd_sub_channel_info
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCREADSUBCHANNEL
value|_IOWR('c', 3 , struct ioc_read_subchannel )
end_define

begin_struct
struct|struct
name|ioc_toc_header
block|{
name|u_short
name|len
decl_stmt|;
name|u_char
name|starting_track
decl_stmt|;
name|u_char
name|ending_track
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOREADTOCHEADER
value|_IOR('c',4,struct ioc_toc_header)
end_define

begin_struct
struct|struct
name|ioc_read_toc_entry
block|{
name|u_char
name|address_format
decl_stmt|;
name|u_char
name|starting_track
decl_stmt|;
name|u_short
name|data_len
decl_stmt|;
name|struct
name|cd_toc_entry
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOREADTOCENTRYS
value|_IOWR('c',5,struct ioc_read_toc_entry)
end_define

begin_struct
struct|struct
name|ioc_read_toc_single_entry
block|{
name|u_char
name|address_format
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|struct
name|cd_toc_entry
name|entry
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOREADTOCENTRY
value|_IOWR('c',6,struct ioc_read_toc_single_entry)
end_define

begin_struct
struct|struct
name|ioc_patch
block|{
name|u_char
name|patch
index|[
literal|4
index|]
decl_stmt|;
comment|/* one for each channel */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCSETPATCH
value|_IOW('c',9,struct ioc_patch)
end_define

begin_struct
struct|struct
name|ioc_vol
block|{
name|u_char
name|vol
index|[
literal|4
index|]
decl_stmt|;
comment|/* one for each channel */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCGETVOL
value|_IOR('c',10,struct ioc_vol)
end_define

begin_define
define|#
directive|define
name|CDIOCSETVOL
value|_IOW('c',11,struct ioc_vol)
end_define

begin_define
define|#
directive|define
name|CDIOCSETMONO
value|_IO('c',12)
end_define

begin_define
define|#
directive|define
name|CDIOCSETSTERIO
value|_IO('c',13)
end_define

begin_define
define|#
directive|define
name|CDIOCSETSTEREO
value|_IO('c',13)
end_define

begin_define
define|#
directive|define
name|CDIOCSETMUTE
value|_IO('c',14)
end_define

begin_define
define|#
directive|define
name|CDIOCSETLEFT
value|_IO('c',15)
end_define

begin_define
define|#
directive|define
name|CDIOCSETRIGHT
value|_IO('c',16)
end_define

begin_define
define|#
directive|define
name|CDIOCSETDEBUG
value|_IO('c',17)
end_define

begin_define
define|#
directive|define
name|CDIOCCLRDEBUG
value|_IO('c',18)
end_define

begin_define
define|#
directive|define
name|CDIOCPAUSE
value|_IO('c',19)
end_define

begin_define
define|#
directive|define
name|CDIOCRESUME
value|_IO('c',20)
end_define

begin_define
define|#
directive|define
name|CDIOCRESET
value|_IO('c',21)
end_define

begin_define
define|#
directive|define
name|CDIOCSTART
value|_IO('c',22)
end_define

begin_define
define|#
directive|define
name|CDIOCSTOP
value|_IO('c',23)
end_define

begin_define
define|#
directive|define
name|CDIOCEJECT
value|_IO('c',24)
end_define

begin_struct
struct|struct
name|ioc_play_msf
block|{
name|u_char
name|start_m
decl_stmt|;
name|u_char
name|start_s
decl_stmt|;
name|u_char
name|start_f
decl_stmt|;
name|u_char
name|end_m
decl_stmt|;
name|u_char
name|end_s
decl_stmt|;
name|u_char
name|end_f
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCPLAYMSF
value|_IOW('c',25,struct ioc_play_msf)
end_define

begin_define
define|#
directive|define
name|CDIOCALLOW
value|_IO('c',26)
end_define

begin_define
define|#
directive|define
name|CDIOCPREVENT
value|_IO('c',27)
end_define

begin_comment
comment|/*<1>For drives that support it, this*/
end_comment

begin_comment
comment|/*<1>causes the drive to close its door*/
end_comment

begin_comment
comment|/*<1>and make the media (if any) ready*/
end_comment

begin_define
define|#
directive|define
name|CDIOCCLOSE
value|_IO('c',28)
end_define

begin_comment
comment|/*<1>*/
end_comment

begin_struct
struct|struct
name|ioc_pitch
comment|/*<1>For drives that support it, this*/
block|{
comment|/*<1>call instructs the drive to play the*/
name|short
name|speed
decl_stmt|;
comment|/*<1>audio at a faster or slower-than-normal*/
block|}
struct|;
end_struct

begin_comment
comment|/*<1>rate. -32767 to -1 is slower, 0==normal,*/
end_comment

begin_comment
comment|/*<1>and 1 to 32767 is faster.  LSB bits are*/
end_comment

begin_comment
comment|/*<1>discarded first by drives with less res.*/
end_comment

begin_define
define|#
directive|define
name|CDIOCPITCH
value|_IOW('c',29,struct ioc_pitch)
end_define

begin_comment
comment|/*<1>*/
end_comment

begin_struct
struct|struct
name|ioc_capability
block|{
comment|/*<2>*/
name|u_long
name|play_function
decl_stmt|;
comment|/*<2>*/
define|#
directive|define
name|CDDOPLAYTRK
value|0x00000001
comment|/*<2>Can Play tracks/index*/
define|#
directive|define
name|CDDOPLAYMSF
value|0x00000002
comment|/*<2>Can Play msf to msf*/
define|#
directive|define
name|CDDOPLAYBLOCKS
value|0x00000004
comment|/*<2>Can Play range of blocks*/
define|#
directive|define
name|CDDOPAUSE
value|0x00000100
comment|/*<2>Output can be paused*/
define|#
directive|define
name|CDDORESUME
value|0x00000200
comment|/*<2>Output can be resumed*/
define|#
directive|define
name|CDDORESET
value|0x00000400
comment|/*<2>Drive can be completely reset*/
define|#
directive|define
name|CDDOSTART
value|0x00000800
comment|/*<2>Audio can be started*/
define|#
directive|define
name|CDDOSTOP
value|0x00001000
comment|/*<2>Audio can be stopped*/
define|#
directive|define
name|CDDOPITCH
value|0x00002000
comment|/*<2>Audio pitch */
name|u_long
name|routing_function
decl_stmt|;
comment|/*<2>*/
define|#
directive|define
name|CDREADVOLUME
value|0x00000001
comment|/*<2>Volume settings can be read*/
define|#
directive|define
name|CDSETVOLUME
value|0x00000002
comment|/*<2>Volume settings can be set*/
define|#
directive|define
name|CDSETMONO
value|0x00000100
comment|/*<2>Output can be set to mono*/
define|#
directive|define
name|CDSETSTEREO
value|0x00000200
comment|/*<2>Output can be set to stereo (def)*/
define|#
directive|define
name|CDSETLEFT
value|0x00000400
comment|/*<2>Output can be set to left only*/
define|#
directive|define
name|CDSETRIGHT
value|0x00000800
comment|/*<2>Output can be set to right only*/
define|#
directive|define
name|CDSETMUTE
value|0x00001000
comment|/*<2>Output can be muted*/
define|#
directive|define
name|CDSETPATCH
value|0x00008000
comment|/*<2>Direct routing control allowed*/
name|u_long
name|special_function
decl_stmt|;
comment|/*<2>*/
define|#
directive|define
name|CDDOEJECT
value|0x00000001
comment|/*<2>The tray can be opened*/
define|#
directive|define
name|CDDOCLOSE
value|0x00000002
comment|/*<2>The tray can be closed*/
define|#
directive|define
name|CDDOLOCK
value|0x00000004
comment|/*<2>The tray can be locked*/
define|#
directive|define
name|CDREADHEADER
value|0x00000100
comment|/*<2>Can read Table of Contents*/
define|#
directive|define
name|CDREADENTRIES
value|0x00000200
comment|/*<2>Can read TOC Entries*/
define|#
directive|define
name|CDREADSUBQ
value|0x00000200
comment|/*<2>Can read Subchannel info*/
define|#
directive|define
name|CDREADRW
value|0x00000400
comment|/*<2>Can read subcodes R-W*/
define|#
directive|define
name|CDHASDEBUG
value|0x00004000
comment|/*<2>The tray has dynamic debugging*/
block|}
struct|;
end_struct

begin_comment
comment|/*<2>*/
end_comment

begin_define
define|#
directive|define
name|CDIOCCAPABILITY
value|_IOR('c',30,struct ioc_capability)
end_define

begin_comment
comment|/*<2>*/
end_comment

begin_struct
struct|struct
name|ioc_read_audio
block|{
name|u_char
name|address_format
decl_stmt|;
name|union
name|msf_lba
name|address
decl_stmt|;
name|int
name|nframes
decl_stmt|;
name|u_char
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CDIOCREADAUDIO
value|_IOWR('c',31,struct ioc_read_audio)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CDIO_H_ */
end_comment

end_unit

