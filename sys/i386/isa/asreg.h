begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|scsicmd
block|{
name|int
name|lun
decl_stmt|;
name|int
name|readflag
decl_stmt|;
comment|/* 1=read, 0=write */
name|int
name|blkno
decl_stmt|;
comment|/* just used in seek sorting */
name|unsigned
name|int
name|cdblen
decl_stmt|;
name|caddr_t
name|cdb
decl_stmt|;
name|unsigned
name|int
name|datalen
decl_stmt|;
name|caddr_t
name|data
decl_stmt|;
name|unsigned
name|int
name|ccblen
decl_stmt|;
name|caddr_t
name|ccb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCSICMD
value|_IOWR('a', 150, struct scsicmd)
end_define

begin_comment
comment|/* write regs */
end_comment

begin_define
define|#
directive|define
name|AS_CONTROL
value|0
end_define

begin_define
define|#
directive|define
name|AS_DATA_OUT
value|1
end_define

begin_comment
comment|/* read regs */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS
value|0
end_define

begin_define
define|#
directive|define
name|AS_DATA_IN
value|1
end_define

begin_define
define|#
directive|define
name|AS_INTR
value|2
end_define

begin_comment
comment|/* control port bits */
end_comment

begin_define
define|#
directive|define
name|AS_CONTROL_HRST
value|0x80
end_define

begin_comment
comment|/* hard reset */
end_comment

begin_define
define|#
directive|define
name|AS_CONTROL_SRST
value|0x40
end_define

begin_comment
comment|/* soft reset */
end_comment

begin_define
define|#
directive|define
name|AS_CONTROL_IRST
value|0x20
end_define

begin_comment
comment|/* interrupt reset */
end_comment

begin_define
define|#
directive|define
name|AS_CONTROL_SCRST
value|0x10
end_define

begin_comment
comment|/* scsi bus reset */
end_comment

begin_comment
comment|/* status port bits */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_STST
value|0x80
end_define

begin_comment
comment|/* self test in progress */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_DIAGF
value|0x40
end_define

begin_comment
comment|/* internal diagnostic failure */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_INIT
value|0x20
end_define

begin_comment
comment|/* mailbox initialization required */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_IDLE
value|0x10
end_define

begin_comment
comment|/* scsi host adapter idle */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_CDF
value|0x08
end_define

begin_comment
comment|/* command/data out port full */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_DF
value|0x04
end_define

begin_comment
comment|/* data in port full */
end_comment

begin_comment
comment|/* 0x02 reserved */
end_comment

begin_define
define|#
directive|define
name|AS_STATUS_INVDCMD
value|0x01
end_define

begin_comment
comment|/* invalid host adapter command */
end_comment

begin_comment
comment|/* interrupt port bits */
end_comment

begin_define
define|#
directive|define
name|AS_INTR_ANY
value|0x80
end_define

begin_define
define|#
directive|define
name|AS_INTR_SCRD
value|0x08
end_define

begin_comment
comment|/* scsi reset detected */
end_comment

begin_define
define|#
directive|define
name|AS_INTR_HACC
value|0x04
end_define

begin_comment
comment|/* host adapter command complete */
end_comment

begin_define
define|#
directive|define
name|AS_INTR_MBOA
value|0x02
end_define

begin_comment
comment|/* mailbox out available */
end_comment

begin_define
define|#
directive|define
name|AS_INTR_MBIF
value|0x01
end_define

begin_comment
comment|/* mailbox in available */
end_comment

begin_comment
comment|/* command bytes */
end_comment

begin_define
define|#
directive|define
name|AS_CMD_NOP
value|0x00
end_define

begin_define
define|#
directive|define
name|AS_CMD_MAILBOX_INIT
value|0x01
end_define

begin_define
define|#
directive|define
name|AS_CMD_START_SCSI_COMMAND
value|0x02
end_define

begin_define
define|#
directive|define
name|AS_CMD_START_BIOS_COMMAND
value|0x03
end_define

begin_define
define|#
directive|define
name|AS_CMD_ADAPTER_INQUIRY
value|0x04
end_define

begin_define
define|#
directive|define
name|AS_CMD_ENABLE_MBOA_INTR
value|0x05
end_define

begin_define
define|#
directive|define
name|AS_CMD_SET_SELECTION_TIMEOUT
value|0x06
end_define

begin_define
define|#
directive|define
name|AS_CMD_SET_BUS_ON_TIME
value|0x07
end_define

begin_define
define|#
directive|define
name|AS_CMD_SET_BUS_OFF_TIME
value|0x08
end_define

begin_define
define|#
directive|define
name|AS_CMD_SET_TRANSFER_SPEED
value|0x09
end_define

begin_define
define|#
directive|define
name|AS_CMD_RETURN_INSTALLED_DEVICES
value|0x0a
end_define

begin_define
define|#
directive|define
name|AS_CMD_RETURN_CONFIGURATION_DATA
value|0x0b
end_define

begin_define
define|#
directive|define
name|AS_CMD_ENABLE_TARGET_MODE
value|0x0c
end_define

begin_define
define|#
directive|define
name|AS_CMD_RETURN_SETUP_DATA
value|0x0d
end_define

begin_define
define|#
directive|define
name|AS_CMD_WRITE_ADAPTER_CHANNEL_2_BUFFER
value|0x1a
end_define

begin_define
define|#
directive|define
name|AS_CMD_READ_ADAPTER_CHANNEL_2_BUFGFER
value|0x1b
end_define

begin_define
define|#
directive|define
name|AS_CMD_WRITE_ADAPTER_FIFO_BUFFER
value|0x1c
end_define

begin_define
define|#
directive|define
name|AS_CMD_READ_ADAPTER_FIFO_BUFFER
value|0x1d
end_define

begin_define
define|#
directive|define
name|AS_CMD_ECHO
value|0x1f
end_define

begin_define
define|#
directive|define
name|AS_CMD_ADAPTER_DIAG
value|0x20
end_define

begin_define
define|#
directive|define
name|AS_CMD_SET_ADAPTER_OPTIONS
value|0x21
end_define

begin_struct
struct|struct
name|mailbox_entry
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
name|unsigned
name|char
name|msb
decl_stmt|;
name|unsigned
name|char
name|mid
decl_stmt|;
name|unsigned
name|char
name|lsb
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXCDB
value|50
end_define

begin_define
define|#
directive|define
name|MAXSENSE
value|100
end_define

begin_struct
struct|struct
name|ccb
block|{
name|unsigned
name|char
name|ccb_opcode
decl_stmt|;
name|unsigned
name|char
name|ccb_addr_and_control
decl_stmt|;
name|unsigned
name|char
name|ccb_scsi_command_len
decl_stmt|;
name|unsigned
name|char
name|ccb_requst_sense_allocation_len
decl_stmt|;
name|unsigned
name|char
name|ccb_data_len_msb
decl_stmt|;
name|unsigned
name|char
name|ccb_data_len_mid
decl_stmt|;
name|unsigned
name|char
name|ccb_data_len_lsb
decl_stmt|;
name|unsigned
name|char
name|ccb_data_ptr_msb
decl_stmt|;
name|unsigned
name|char
name|ccb_data_ptr_mid
decl_stmt|;
name|unsigned
name|char
name|ccb_data_ptr_lsb
decl_stmt|;
name|unsigned
name|char
name|ccb_link_msb
decl_stmt|;
name|unsigned
name|char
name|ccb_link_mid
decl_stmt|;
name|unsigned
name|char
name|ccb_link_lsb
decl_stmt|;
name|unsigned
name|char
name|ccb_link_id
decl_stmt|;
name|unsigned
name|char
name|ccb_host_status
decl_stmt|;
name|unsigned
name|char
name|ccb_target_status
decl_stmt|;
name|unsigned
name|char
name|ccb_zero1
decl_stmt|;
name|unsigned
name|char
name|ccb_zero2
decl_stmt|;
name|unsigned
name|char
name|ccb_cdb
index|[
name|MAXCDB
operator|+
name|MAXSENSE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ccb_sense
parameter_list|(
name|ccb
parameter_list|)
value|((ccb)->ccb_cdb + (ccb)->ccb_scsi_command_len)
end_define

end_unit

