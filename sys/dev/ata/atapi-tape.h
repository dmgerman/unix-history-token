begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ATAPI tape commands not in std ATAPI command set */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TAPE_REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_READ_CMD
value|0x08
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_WRITE_CMD
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_WEOF
value|0x10
end_define

begin_define
define|#
directive|define
name|WEOF_WRITE_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_SPACE_CMD
value|0x11
end_define

begin_define
define|#
directive|define
name|SP_FM
value|0x01
end_define

begin_define
define|#
directive|define
name|SP_EOD
value|0x03
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_ERASE
value|0x19
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_MODE_SENSE
value|0x1a
end_define

begin_define
define|#
directive|define
name|ATAPI_TAPE_LOAD_UNLOAD
value|0x1b
end_define

begin_define
define|#
directive|define
name|LU_LOAD_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|LU_RETENSION_MASK
value|0x02
end_define

begin_define
define|#
directive|define
name|LU_EOT_MASK
value|0x04
end_define

begin_define
define|#
directive|define
name|DSC_POLL_INTERVAL
value|10
end_define

begin_comment
comment|/*   * MODE SENSE parameter header  */
end_comment

begin_struct
struct|struct
name|ast_header
block|{
name|u_int8_t
name|data_length
decl_stmt|;
comment|/* Total length of data */
name|u_int8_t
name|medium_type
decl_stmt|;
comment|/* Medium type (if any) */
name|u_int8_t
name|dsp
decl_stmt|;
comment|/* Device specific parameter */
name|u_int8_t
name|bdl
decl_stmt|;
comment|/* Block Descriptor Length */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ATAPI tape drive Capabilities and Mechanical Status Page  */
end_comment

begin_define
define|#
directive|define
name|ATAPI_TAPE_CAP_PAGE
value|0x2a
end_define

begin_struct
struct|struct
name|ast_cappage
block|{
name|u_int8_t
name|page_code
range|:
literal|6
decl_stmt|;
comment|/* Page code == 0x2a */
name|u_int8_t
name|reserved1_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* Page Length == 0x12 */
name|u_int8_t
name|reserved2
decl_stmt|;
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int8_t
name|readonly
range|:
literal|1
decl_stmt|;
comment|/* Read Only Mode */
name|u_int8_t
name|reserved4_1234
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|reverse
range|:
literal|1
decl_stmt|;
comment|/* Supports reverse direction */
name|u_int8_t
name|reserved4_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|reserved5_012
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|eformat
range|:
literal|1
decl_stmt|;
comment|/* Supports ERASE formatting */
name|u_int8_t
name|reserved5_4
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|qfa
range|:
literal|1
decl_stmt|;
comment|/* Supports QFA formats */
name|u_int8_t
name|reserved5_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|lock
range|:
literal|1
decl_stmt|;
comment|/* Supports locking media */
name|u_int8_t
name|locked
range|:
literal|1
decl_stmt|;
comment|/* The media is locked */
name|u_int8_t
name|prevent
range|:
literal|1
decl_stmt|;
comment|/* Defaults  to prevent state */
name|u_int8_t
name|eject
range|:
literal|1
decl_stmt|;
comment|/* Supports eject */
name|u_int8_t
name|disconnect
range|:
literal|1
decl_stmt|;
comment|/* Can break request> ctl */
name|u_int8_t
name|reserved6_5
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ecc
range|:
literal|1
decl_stmt|;
comment|/* Supports error correction */
name|u_int8_t
name|compress
range|:
literal|1
decl_stmt|;
comment|/* Supports data compression */
name|u_int8_t
name|reserved7_0
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|blk512
range|:
literal|1
decl_stmt|;
comment|/* Supports 512b block size */
name|u_int8_t
name|blk1024
range|:
literal|1
decl_stmt|;
comment|/* Supports 1024b block size */
name|u_int8_t
name|reserved7_3456
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|slowb
range|:
literal|1
decl_stmt|;
comment|/* Restricts byte count */
name|u_int16_t
name|max_speed
decl_stmt|;
comment|/* Supported speed in KBps */
name|u_int16_t
name|max_defects
decl_stmt|;
comment|/* Max stored defect entries */
name|u_int16_t
name|ctl
decl_stmt|;
comment|/* Continuous Transfer Limit */
name|u_int16_t
name|speed
decl_stmt|;
comment|/* Current Speed, in KBps */
name|u_int16_t
name|buffer_size
decl_stmt|;
comment|/* Buffer Size, in 512 bytes */
name|u_int8_t
name|reserved18
decl_stmt|;
name|u_int8_t
name|reserved19
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * REQUEST SENSE structure  */
end_comment

begin_struct
struct|struct
name|ast_reqsense
block|{
name|u_int8_t
name|error_code
range|:
literal|7
decl_stmt|;
comment|/* Current or deferred errors */
name|u_int8_t
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Follows QIC-157C */
name|u_int8_t
name|reserved1
decl_stmt|;
comment|/* Segment Number - Reserved */
name|u_int8_t
name|sense_key
range|:
literal|4
decl_stmt|;
comment|/* Sense Key */
name|u_int8_t
name|reserved2_4
range|:
literal|1
decl_stmt|;
comment|/* Reserved */
name|u_int8_t
name|ili
range|:
literal|1
decl_stmt|;
comment|/* Incorrect Length Indicator */
name|u_int8_t
name|eom
range|:
literal|1
decl_stmt|;
comment|/* End Of Medium */
name|u_int8_t
name|filemark
range|:
literal|1
decl_stmt|;
comment|/* Filemark */
name|u_int8_t
name|info
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
comment|/* Cmd specific info */
name|u_int8_t
name|asl
decl_stmt|;
comment|/* Additional sense length (n-7) */
name|u_int8_t
name|command_specific
decl_stmt|;
comment|/* Additional cmd specific info */
name|u_int8_t
name|asc
decl_stmt|;
comment|/* Additional Sense Code */
name|u_int8_t
name|ascq
decl_stmt|;
comment|/* Additional Sense Code Qualifier */
name|u_int8_t
name|replaceable_unit_code
decl_stmt|;
comment|/* Field Replaceable Unit Code */
name|u_int8_t
name|sk_specific1
range|:
literal|7
decl_stmt|;
comment|/* Sense Key Specific */
name|u_int8_t
name|sksv
range|:
literal|1
decl_stmt|;
comment|/* Sense Key Specific info valid */
name|u_int8_t
name|sk_specific2
decl_stmt|;
comment|/* Sense Key Specific */
name|u_int8_t
name|sk_specific3
decl_stmt|;
comment|/* Sense Key Specific */
name|u_int8_t
name|pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Padding */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ast_softc
block|{
name|struct
name|atapi_softc
modifier|*
name|atp
decl_stmt|;
comment|/* Controller structure */
name|int32_t
name|lun
decl_stmt|;
comment|/* Logical device unit */
name|int32_t
name|flags
decl_stmt|;
comment|/* Device state flags */
name|int32_t
name|blksize
decl_stmt|;
comment|/* Block size (512 | 1024) */
name|struct
name|buf_queue_head
name|buf_queue
decl_stmt|;
comment|/* Queue of i/o requests */
name|struct
name|atapi_params
modifier|*
name|param
decl_stmt|;
comment|/* Drive parameters table */
name|struct
name|ast_header
name|header
decl_stmt|;
comment|/* MODE SENSE param header */
name|struct
name|ast_cappage
name|cap
decl_stmt|;
comment|/* Capabilities page info */
name|struct
name|devstat
name|stats
decl_stmt|;
comment|/* devstat entry */
ifdef|#
directive|ifdef
name|DEVFS
name|void
modifier|*
name|cdevs
decl_stmt|;
name|void
modifier|*
name|bdevs
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

end_unit

