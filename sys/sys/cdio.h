begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 16 Feb 93	Julian Elischer	(julian@dialix.oz.au)  */
end_comment

begin_comment
comment|/* Shared between kernel& process */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_CDIO_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_CDIO_H
end_define

begin_struct
struct|struct
name|cd_toc_entry
block|{
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|control
range|:
literal|4
decl_stmt|;
name|u_char
name|addr_type
range|:
literal|4
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|addr
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cd_sub_channel_header
block|{
name|u_char
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
name|u_char
name|control
range|:
literal|4
decl_stmt|;
name|u_char
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
name|u_char
name|absaddr
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|reladdr
index|[
literal|4
index|]
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
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|7
expr_stmt|;
name|u_char
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
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
name|track_number
decl_stmt|;
name|u_char
label|:
literal|8
expr_stmt|;
name|u_char
label|:
literal|7
expr_stmt|;
name|u_char
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_CDIO_H */
end_comment

end_unit

