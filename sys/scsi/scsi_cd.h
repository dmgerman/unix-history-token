begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with  * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  *	$Id: scsi_cd.h,v 1.10 1997/02/22 09:44:28 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_CD_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_CD_H
value|1
end_define

begin_comment
comment|/*  *	Define two bits always in the same place in byte 2 (flag byte)  */
end_comment

begin_define
define|#
directive|define
name|CD_RELADDR
value|0x01
end_define

begin_define
define|#
directive|define
name|CD_MSF
value|0x02
end_define

begin_comment
comment|/*  * SCSI command format  */
end_comment

begin_struct
struct|struct
name|scsi_pause
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|unused
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|resume
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PA_PAUSE
value|1
end_define

begin_define
define|#
directive|define
name|PA_RESUME
value|0
end_define

begin_struct
struct|struct
name|scsi_play_msf
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|unused
decl_stmt|;
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
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_play_track
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|start_track
decl_stmt|;
name|u_char
name|start_index
decl_stmt|;
name|u_char
name|unused1
decl_stmt|;
name|u_char
name|end_track
decl_stmt|;
name|u_char
name|end_index
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_play
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|blk_addr
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|unused
decl_stmt|;
name|u_char
name|xfer_len
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_play_big
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
comment|/* same as above */
name|u_char
name|blk_addr
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|xfer_len
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|unused
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_play_rel_big
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
comment|/* same as above */
name|u_char
name|blk_addr
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|xfer_len
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_header
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|blk_addr
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|unused
decl_stmt|;
name|u_char
name|data_len
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_subchannel
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|byte3
decl_stmt|;
define|#
directive|define
name|SRS_SUBQ
value|0x40
name|u_char
name|subchan_format
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_char
name|data_len
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_toc
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|unused
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|from_track
decl_stmt|;
name|u_char
name|data_len
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_cd_capacity
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|addr_3
decl_stmt|;
comment|/* Most Significant */
name|u_char
name|addr_2
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* Least Significant */
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|READ_CD_CAPACITY
value|0x25
end_define

begin_comment
comment|/* slightly different from disk */
end_comment

begin_define
define|#
directive|define
name|READ_SUBCHANNEL
value|0x42
end_define

begin_comment
comment|/* cdrom read Subchannel */
end_comment

begin_define
define|#
directive|define
name|READ_TOC
value|0x43
end_define

begin_comment
comment|/* cdrom read TOC */
end_comment

begin_define
define|#
directive|define
name|READ_HEADER
value|0x44
end_define

begin_comment
comment|/* cdrom read header */
end_comment

begin_define
define|#
directive|define
name|PLAY
value|0x45
end_define

begin_comment
comment|/* cdrom play  'play audio' mode */
end_comment

begin_define
define|#
directive|define
name|PLAY_MSF
value|0x47
end_define

begin_comment
comment|/* cdrom play Min,Sec,Frames mode */
end_comment

begin_define
define|#
directive|define
name|PLAY_TRACK
value|0x48
end_define

begin_comment
comment|/* cdrom play track/index mode */
end_comment

begin_define
define|#
directive|define
name|PLAY_TRACK_REL
value|0x49
end_define

begin_comment
comment|/* cdrom play track/index mode */
end_comment

begin_define
define|#
directive|define
name|PAUSE
value|0x4b
end_define

begin_comment
comment|/* cdrom pause in 'play audio' mode */
end_comment

begin_define
define|#
directive|define
name|PLAY_BIG
value|0xa5
end_define

begin_comment
comment|/* cdrom pause in 'play audio' mode */
end_comment

begin_define
define|#
directive|define
name|PLAY_TRACK_REL_BIG
value|0xa9
end_define

begin_comment
comment|/* cdrom play track/index mode */
end_comment

begin_struct
struct|struct
name|scsi_read_cd_cap_data
block|{
name|u_char
name|addr_3
decl_stmt|;
comment|/* Most significant */
name|u_char
name|addr_2
decl_stmt|;
name|u_char
name|addr_1
decl_stmt|;
name|u_char
name|addr_0
decl_stmt|;
comment|/* Least significant */
name|u_char
name|length_3
decl_stmt|;
comment|/* Most significant */
name|u_char
name|length_2
decl_stmt|;
name|u_char
name|length_1
decl_stmt|;
name|u_char
name|length_0
decl_stmt|;
comment|/* Least significant */
block|}
struct|;
end_struct

begin_union
union|union
name|cd_pages
block|{
struct|struct
name|audio_page
block|{
name|u_char
name|page_code
decl_stmt|;
define|#
directive|define
name|CD_PAGE_CODE
value|0x3F
define|#
directive|define
name|AUDIO_PAGE
value|0x0e
define|#
directive|define
name|CD_PAGE_PS
value|0x80
name|u_char
name|param_len
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
define|#
directive|define
name|CD_PA_SOTC
value|0x02
define|#
directive|define
name|CD_PA_IMMED
value|0x04
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|format_lba
decl_stmt|;
define|#
directive|define
name|CD_PA_FORMAT_LBA
value|0x0F
define|#
directive|define
name|CD_PA_APR_VALID
value|0x80
name|u_char
name|lb_per_sec
index|[
literal|2
index|]
decl_stmt|;
struct|struct
name|port_control
block|{
name|u_char
name|channels
decl_stmt|;
define|#
directive|define
name|CHANNEL
value|0x0F
define|#
directive|define
name|CHANNEL_0
value|1
define|#
directive|define
name|CHANNEL_1
value|2
define|#
directive|define
name|CHANNEL_2
value|4
define|#
directive|define
name|CHANNEL_3
value|8
define|#
directive|define
name|LEFT_CHANNEL
value|CHANNEL_0
define|#
directive|define
name|RIGHT_CHANNEL
value|CHANNEL_1
name|u_char
name|volume
decl_stmt|;
block|}
name|port
index|[
literal|4
index|]
struct|;
define|#
directive|define
name|LEFT_PORT
value|0
define|#
directive|define
name|RIGHT_PORT
value|1
block|}
name|audio
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|cd_mode_data
block|{
name|struct
name|scsi_mode_header
name|header
decl_stmt|;
name|struct
name|blk_desc
name|blk_desc
decl_stmt|;
name|union
name|cd_pages
name|page
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_SCSI_SCSI_CD_H*/
end_comment

end_unit

