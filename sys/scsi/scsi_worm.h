begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_WORM_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_WORM_H
end_define

begin_define
define|#
directive|define
name|PAGE_HEADERLEN
value|2
end_define

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|REZERO_UNIT
value|0x01
end_define

begin_comment
comment|/* re-init; XXX belongs to scsi_all? */
end_comment

begin_define
define|#
directive|define
name|SYNCHRONIZE_CACHE
value|0x35
end_define

begin_comment
comment|/* flush write buffer, close wr chn */
end_comment

begin_define
define|#
directive|define
name|FIRST_WRITEABLE_ADDR
value|0xe2
end_define

begin_comment
comment|/* return first available LBA */
end_comment

begin_define
define|#
directive|define
name|RESERVE_TRACK
value|0xe4
end_define

begin_comment
comment|/* reserve a track for later write */
end_comment

begin_define
define|#
directive|define
name|READ_TRACK_INFORMATION
value|0xe5
end_define

begin_comment
comment|/* get info for a particular track */
end_comment

begin_define
define|#
directive|define
name|WRITE_TRACK
value|0xe6
end_define

begin_comment
comment|/* open the write channel */
end_comment

begin_define
define|#
directive|define
name|LOAD_UNLOAD
value|0xe7
end_define

begin_comment
comment|/* resembles part of START_STOP */
end_comment

begin_define
define|#
directive|define
name|FIXATION
value|0xe9
end_define

begin_comment
comment|/* write leadin/leadout */
end_comment

begin_define
define|#
directive|define
name|WRITE_SESSION
value|0xed
end_define

begin_comment
comment|/* guide to write a new session */
end_comment

begin_define
define|#
directive|define
name|READ_SESSION_INFO
value|0xee
end_define

begin_comment
comment|/* read leadin/leadout lengths */
end_comment

begin_struct
struct|struct
name|scsi_rezero_unit
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
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

begin_struct
struct|struct
name|scsi_synchronize_cache
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|7
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct scsi_first_writeable_address; */
end_comment

begin_struct
struct|struct
name|scsi_reserve_track
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|reserve_length_3
decl_stmt|;
comment|/* MSB */
name|u_char
name|reserve_length_2
decl_stmt|;
name|u_char
name|reserve_length_1
decl_stmt|;
name|u_char
name|reserve_length_0
decl_stmt|;
comment|/* LSB */
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct scsi_read_track_information; */
end_comment

begin_struct
struct|struct
name|scsi_write_track
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|track_number
decl_stmt|;
comment|/* 0 means: use next available */
name|u_char
name|mode
decl_stmt|;
define|#
directive|define
name|WORM_TRACK_MODE_RAW
value|0x08
define|#
directive|define
name|WORM_TRACK_MODE_AUDIO
value|0x04
define|#
directive|define
name|WORM_TRACK_MODE_MODE1
value|0x01
comment|/* also audio with preemphasis */
define|#
directive|define
name|WORM_TRACK_MODE_MODE2
value|0x02
name|u_char
name|transfer_length_1
decl_stmt|;
comment|/* number of blocks to transfer, MSB */
name|u_char
name|transfer_length_0
decl_stmt|;
comment|/* LSB */
name|u_char
name|control
decl_stmt|;
define|#
directive|define
name|WORM_TRACK_CONTROL_MIX
value|0x40
comment|/* mixed mode blocks */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_load_unload
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|load
decl_stmt|;
define|#
directive|define
name|WORM_LOAD_MEDIUM
value|0x01
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_fixation
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|action
decl_stmt|;
define|#
directive|define
name|WORM_FIXATION_ONP
value|0x08
comment|/* open next program area (new session) */
define|#
directive|define
name|WORM_TOC_TYPE_AUDIO
value|0x00
define|#
directive|define
name|WORM_TOC_TYPE_CDROM
value|0x01
define|#
directive|define
name|WORM_TOC_TYPE_CDROM_1
value|0x02
comment|/* CD-ROM, first track mode 1 (?) */
define|#
directive|define
name|WORM_TOC_TYPE_CDROM_2
value|0x03
comment|/* CD-ROM, first track mode 2 */
define|#
directive|define
name|WORM_TOC_TYPE_CDI
value|0x04
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_write_session
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|action
decl_stmt|;
comment|/* see scsi_fixation above */
define|#
directive|define
name|WORM_LOFP_MODE_MODE1
value|0x10
define|#
directive|define
name|WORM_LOFP_MODE_MODE2
value|0x20
name|u_char
name|transfer_length_2
decl_stmt|;
comment|/* number of blocks to transfer, MSB */
name|u_char
name|transfer_length_1
decl_stmt|;
comment|/* LSB */
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_read_session_info
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|reserved
index|[
literal|6
index|]
decl_stmt|;
name|u_char
name|transfer_length
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_first_writable_address
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|track_number
decl_stmt|;
name|u_char
name|mode
decl_stmt|;
name|u_char
name|reserved
index|[
literal|4
index|]
decl_stmt|;
name|u_char
name|transfer_length
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_SCSI_WORM_H */
end_comment

end_unit

