begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structures and definitions for SCSI commands to the SG passthrough device.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SG_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SG_H
end_define

begin_define
define|#
directive|define
name|SGIOC
value|'"'
end_define

begin_define
define|#
directive|define
name|SG_SET_TIMEOUT
value|_IO(SGIOC, 0x01)
end_define

begin_define
define|#
directive|define
name|SG_GET_TIMEOUT
value|_IO(SGIOC, 0x02)
end_define

begin_define
define|#
directive|define
name|SG_EMULATED_HOST
value|_IO(SGIOC, 0x03)
end_define

begin_define
define|#
directive|define
name|SG_SET_TRANSFORM
value|_IO(SGIOC, 0x04)
end_define

begin_define
define|#
directive|define
name|SG_GET_TRANSFORM
value|_IO(SGIOC, 0x05)
end_define

begin_define
define|#
directive|define
name|SG_GET_COMMAND_Q
value|_IO(SGIOC, 0x70)
end_define

begin_define
define|#
directive|define
name|SG_SET_COMMAND_Q
value|_IO(SGIOC, 0x71)
end_define

begin_define
define|#
directive|define
name|SG_GET_RESERVED_SIZE
value|_IO(SGIOC, 0x72)
end_define

begin_define
define|#
directive|define
name|SG_SET_RESERVED_SIZE
value|_IO(SGIOC, 0x75)
end_define

begin_define
define|#
directive|define
name|SG_GET_SCSI_ID
value|_IO(SGIOC, 0x76)
end_define

begin_define
define|#
directive|define
name|SG_SET_FORCE_LOW_DMA
value|_IO(SGIOC, 0x79)
end_define

begin_define
define|#
directive|define
name|SG_GET_LOW_DMA
value|_IO(SGIOC, 0x7a)
end_define

begin_define
define|#
directive|define
name|SG_SET_FORCE_PACK_ID
value|_IO(SGIOC, 0x7b)
end_define

begin_define
define|#
directive|define
name|SG_GET_PACK_ID
value|_IO(SGIOC, 0x7c)
end_define

begin_define
define|#
directive|define
name|SG_GET_NUM_WAITING
value|_IO(SGIOC, 0x7d)
end_define

begin_define
define|#
directive|define
name|SG_SET_DEBUG
value|_IO(SGIOC, 0x7e)
end_define

begin_define
define|#
directive|define
name|SG_GET_SG_TABLESIZE
value|_IO(SGIOC, 0x7f)
end_define

begin_define
define|#
directive|define
name|SG_GET_VERSION_NUM
value|_IO(SGIOC, 0x82)
end_define

begin_define
define|#
directive|define
name|SG_NEXT_CMD_LEN
value|_IO(SGIOC, 0x83)
end_define

begin_define
define|#
directive|define
name|SG_SCSI_RESET
value|_IO(SGIOC, 0x84)
end_define

begin_define
define|#
directive|define
name|SG_IO
value|_IO(SGIOC, 0x85)
end_define

begin_define
define|#
directive|define
name|SG_GET_REQUEST_TABLE
value|_IO(SGIOC, 0x86)
end_define

begin_define
define|#
directive|define
name|SG_SET_KEEP_ORPHAN
value|_IO(SGIOC, 0x87)
end_define

begin_define
define|#
directive|define
name|SG_GET_KEEP_ORPHAN
value|_IO(SGIOC, 0x88)
end_define

begin_define
define|#
directive|define
name|SG_GET_ACCESS_COUNT
value|_IO(SGIOC, 0x89)
end_define

begin_struct
struct|struct
name|sg_io_hdr
block|{
name|int
name|interface_id
decl_stmt|;
name|int
name|dxfer_direction
decl_stmt|;
name|u_char
name|cmd_len
decl_stmt|;
name|u_char
name|mx_sb_len
decl_stmt|;
name|u_short
name|iovec_count
decl_stmt|;
name|u_int
name|dxfer_len
decl_stmt|;
name|void
modifier|*
name|dxferp
decl_stmt|;
name|u_char
modifier|*
name|cmdp
decl_stmt|;
name|u_char
modifier|*
name|sbp
decl_stmt|;
name|u_int
name|timeout
decl_stmt|;
name|u_int
name|flags
decl_stmt|;
name|int
name|pack_id
decl_stmt|;
name|void
modifier|*
name|usr_ptr
decl_stmt|;
name|u_char
name|status
decl_stmt|;
name|u_char
name|masked_status
decl_stmt|;
name|u_char
name|msg_status
decl_stmt|;
name|u_char
name|sb_len_wr
decl_stmt|;
name|u_short
name|host_status
decl_stmt|;
name|u_short
name|driver_status
decl_stmt|;
name|int
name|resid
decl_stmt|;
name|u_int
name|duration
decl_stmt|;
name|u_int
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SG_DXFER_NONE
value|-1
end_define

begin_define
define|#
directive|define
name|SG_DXFER_TO_DEV
value|-2
end_define

begin_define
define|#
directive|define
name|SG_DXFER_FROM_DEV
value|-3
end_define

begin_define
define|#
directive|define
name|SG_DXFER_TO_FROM_DEV
value|-4
end_define

begin_define
define|#
directive|define
name|SG_DXFER_UNKNOWN
value|-5
end_define

begin_define
define|#
directive|define
name|SG_MAX_SENSE
value|16
end_define

begin_struct
struct|struct
name|sg_header
block|{
name|int
name|pack_len
decl_stmt|;
name|int
name|reply_len
decl_stmt|;
name|int
name|pack_id
decl_stmt|;
name|int
name|result
decl_stmt|;
name|u_int
name|twelve_byte
range|:
literal|1
decl_stmt|;
name|u_int
name|target_status
range|:
literal|5
decl_stmt|;
name|u_int
name|host_status
range|:
literal|8
decl_stmt|;
name|u_int
name|driver_status
range|:
literal|8
decl_stmt|;
name|u_int
name|other_flags
range|:
literal|10
decl_stmt|;
name|u_char
name|sense_buffer
index|[
name|SG_MAX_SENSE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sg_scsi_id
block|{
name|int
name|host_no
decl_stmt|;
name|int
name|channel
decl_stmt|;
name|int
name|scsi_id
decl_stmt|;
name|int
name|lun
decl_stmt|;
name|int
name|scsi_type
decl_stmt|;
name|short
name|h_cmd_per_lun
decl_stmt|;
name|short
name|d_queue_depth
decl_stmt|;
name|int
name|unused
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_idlun
block|{
name|uint32_t
name|dev_id
decl_stmt|;
name|uint32_t
name|host_unique_id
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Host codes  */
end_comment

begin_define
define|#
directive|define
name|DID_OK
value|0x00
end_define

begin_comment
comment|/* OK */
end_comment

begin_define
define|#
directive|define
name|DID_NO_CONNECT
value|0x01
end_define

begin_comment
comment|/* timeout during connect */
end_comment

begin_define
define|#
directive|define
name|DID_BUS_BUSY
value|0x02
end_define

begin_comment
comment|/* timeout during command */
end_comment

begin_define
define|#
directive|define
name|DID_TIME_OUT
value|0x03
end_define

begin_comment
comment|/* other timeout */
end_comment

begin_define
define|#
directive|define
name|DID_BAD_TARGET
value|0x04
end_define

begin_comment
comment|/* bad target */
end_comment

begin_define
define|#
directive|define
name|DID_ABORT
value|0x05
end_define

begin_comment
comment|/* abort */
end_comment

begin_define
define|#
directive|define
name|DID_PARITY
value|0x06
end_define

begin_comment
comment|/* parity error */
end_comment

begin_define
define|#
directive|define
name|DID_ERROR
value|0x07
end_define

begin_comment
comment|/* internal error */
end_comment

begin_define
define|#
directive|define
name|DID_RESET
value|0x08
end_define

begin_comment
comment|/* reset by somebody */
end_comment

begin_define
define|#
directive|define
name|DID_BAD_INTR
value|0x09
end_define

begin_comment
comment|/* unexpected interrupt */
end_comment

begin_define
define|#
directive|define
name|DID_PASSTHROUGH
value|0x0a
end_define

begin_comment
comment|/* passthrough */
end_comment

begin_define
define|#
directive|define
name|DID_SOFT_ERROR
value|0x0b
end_define

begin_comment
comment|/* low driver wants retry */
end_comment

begin_define
define|#
directive|define
name|DID_IMM_RETRY
value|0x0c
end_define

begin_comment
comment|/* retry without decreasing retrycnt */
end_comment

begin_comment
comment|/*  * Driver codes  */
end_comment

begin_define
define|#
directive|define
name|DRIVER_OK
value|0x00
end_define

begin_define
define|#
directive|define
name|DRIVER_BUSY
value|0x01
end_define

begin_define
define|#
directive|define
name|DRIVER_SOFT
value|0x02
end_define

begin_define
define|#
directive|define
name|DRIVER_MEDIA
value|0x03
end_define

begin_define
define|#
directive|define
name|DRIVER_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|DRIVER_INVALID
value|0x05
end_define

begin_define
define|#
directive|define
name|DRIVER_TIMEOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|DRIVER_HARD
value|0x07
end_define

begin_define
define|#
directive|define
name|DRIVER_SENSE
value|0x08
end_define

begin_define
define|#
directive|define
name|SUGGEST_RETRY
value|0x10
end_define

begin_define
define|#
directive|define
name|SUGGEST_ABORT
value|0x20
end_define

begin_define
define|#
directive|define
name|SUGGEST_REMAP
value|0x30
end_define

begin_define
define|#
directive|define
name|SUGGEST_DIE
value|0x40
end_define

begin_define
define|#
directive|define
name|SUGGEST_SENSE
value|0x80
end_define

begin_define
define|#
directive|define
name|SUGGEST_IS_OK
value|0xff
end_define

begin_define
define|#
directive|define
name|DRIVER_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|SUGGEST_MASK
value|0xf0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SCSI_SG_H */
end_comment

end_unit

