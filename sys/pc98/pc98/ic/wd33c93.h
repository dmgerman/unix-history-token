begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * PC9801 SCSI I/F (PC-9801-55)  * modified for PC9801 by A.Kojima  *			Kyoto University Microcomputer Club (KMC)  */
end_comment

begin_comment
comment|/* I/O address */
end_comment

begin_comment
comment|/* WD33C93 */
end_comment

begin_define
define|#
directive|define
name|SCSI_ADR_REG
value|0xcc0
end_define

begin_comment
comment|/* write       Address Register */
end_comment

begin_define
define|#
directive|define
name|SCSI_AUX_REG
value|0xcc0
end_define

begin_comment
comment|/* read        Aux. Status Register */
end_comment

begin_define
define|#
directive|define
name|SCSI_CTL_REG
value|0xcc2
end_define

begin_comment
comment|/* read/write  Control Registers */
end_comment

begin_comment
comment|/* Port */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_RD
value|0xcc4
end_define

begin_comment
comment|/* read        Status Read */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_WRT
value|0xcc4
end_define

begin_comment
comment|/* write       Command Write */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* H98 extended mode */
end_comment

begin_comment
comment|/* WD33C93 */
end_comment

begin_define
define|#
directive|define
name|SCSI_ADR_REG
value|0xee0
end_define

begin_comment
comment|/* write       Address Register */
end_comment

begin_define
define|#
directive|define
name|SCSI_AUX_REG
value|0xee0
end_define

begin_comment
comment|/* read        Control Register */
end_comment

begin_define
define|#
directive|define
name|SCSI_CTL_REG
value|0xee2
end_define

begin_comment
comment|/* read/write  Registers */
end_comment

begin_comment
comment|/* Port */
end_comment

begin_define
define|#
directive|define
name|SCSI_STAT_RD
value|0xee4
end_define

begin_comment
comment|/* read        Status Read */
end_comment

begin_define
define|#
directive|define
name|SCSI_CMD_WRT
value|0xee4
end_define

begin_comment
comment|/* write       Command Write */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/* WD33C93 Registers */
end_comment

begin_define
define|#
directive|define
name|REG_OWN_ID
value|0x00
end_define

begin_comment
comment|/* Own ID */
end_comment

begin_define
define|#
directive|define
name|REG_CONTROL
value|0x01
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|REG_TIMEOUT_PERIOD
value|0x02
end_define

begin_comment
comment|/* Timeout Period */
end_comment

begin_define
define|#
directive|define
name|REG_TOTAL_SECTORS
value|0x03
end_define

begin_comment
comment|/* Total Sectors */
end_comment

begin_define
define|#
directive|define
name|REG_TOTAL_HEADS
value|0x04
end_define

begin_comment
comment|/* Total Heads */
end_comment

begin_define
define|#
directive|define
name|REG_TOTAL_CYL_H
value|0x05
end_define

begin_comment
comment|/* Total Cylinders (MSB) */
end_comment

begin_define
define|#
directive|define
name|REG_TOTAL_CYL_L
value|0x06
end_define

begin_comment
comment|/* Total Cylinders (LSB) */
end_comment

begin_define
define|#
directive|define
name|REG_LOG_SECTOR_HH
value|0x07
end_define

begin_comment
comment|/* Logical Address (MSB) */
end_comment

begin_define
define|#
directive|define
name|REG_LOG_SECTOR_HL
value|0x08
end_define

begin_comment
comment|/* Logical Address       */
end_comment

begin_define
define|#
directive|define
name|REG_LOG_SECTOR_LH
value|0x09
end_define

begin_comment
comment|/* Logical Address       */
end_comment

begin_define
define|#
directive|define
name|REG_LOG_SECTOR_LL
value|0x0a
end_define

begin_comment
comment|/* Logical Address (LSB) */
end_comment

begin_define
define|#
directive|define
name|REG_SECTOR_NUMBER
value|0x0b
end_define

begin_comment
comment|/* Sector Number */
end_comment

begin_define
define|#
directive|define
name|REG_HEAD_NUMBER
value|0x0c
end_define

begin_comment
comment|/* Head Number */
end_comment

begin_define
define|#
directive|define
name|REG_CYL_NUMBER_H
value|0x0d
end_define

begin_comment
comment|/* Cylinder Number (MSB) */
end_comment

begin_define
define|#
directive|define
name|REG_CYL_NUMBER_L
value|0x0e
end_define

begin_comment
comment|/* Cylinder Number (LSB) */
end_comment

begin_define
define|#
directive|define
name|REG_TARGET_LUN
value|0x0f
end_define

begin_comment
comment|/* Target LUN */
end_comment

begin_define
define|#
directive|define
name|REG_CMD_PHASE
value|0x10
end_define

begin_comment
comment|/* Command Phase */
end_comment

begin_define
define|#
directive|define
name|REG_SYNC_TFR
value|0x11
end_define

begin_comment
comment|/* Synchronous Transfer */
end_comment

begin_define
define|#
directive|define
name|REG_TFR_COUNT_H
value|0x12
end_define

begin_comment
comment|/* Transfer Count (MSB) */
end_comment

begin_define
define|#
directive|define
name|REG_TFR_COUNT_M
value|0x13
end_define

begin_comment
comment|/* Transfer Count      */
end_comment

begin_define
define|#
directive|define
name|REG_TFR_COUNT_L
value|0x14
end_define

begin_comment
comment|/* Transfer Count (LSB) */
end_comment

begin_define
define|#
directive|define
name|REG_DST_ID
value|0x15
end_define

begin_comment
comment|/* Destination ID */
end_comment

begin_define
define|#
directive|define
name|REG_SRC_ID
value|0x16
end_define

begin_comment
comment|/* Source ID */
end_comment

begin_define
define|#
directive|define
name|REG_SCSI_STATUS
value|0x17
end_define

begin_comment
comment|/* SCSI Status (Read Only) */
end_comment

begin_define
define|#
directive|define
name|REG_COMMAND
value|0x18
end_define

begin_comment
comment|/* Command */
end_comment

begin_define
define|#
directive|define
name|REG_DATA
value|0x19
end_define

begin_comment
comment|/* Data */
end_comment

begin_comment
comment|/* PC98 only */
end_comment

begin_define
define|#
directive|define
name|REG_MEM_BANK
value|0x30
end_define

begin_comment
comment|/* Memory Bank */
end_comment

begin_define
define|#
directive|define
name|REG_MEM_WIN
value|0x31
end_define

begin_comment
comment|/* Memery Window */
end_comment

begin_define
define|#
directive|define
name|REG_RESERVED1
value|0x32
end_define

begin_comment
comment|/* NEC Reserved 1 */
end_comment

begin_define
define|#
directive|define
name|REG_RESET_INT
value|0x33
end_define

begin_comment
comment|/* Reset/Int */
end_comment

begin_define
define|#
directive|define
name|REG_RESERVED2
value|0x34
end_define

begin_comment
comment|/* NEC Reserved 2 */
end_comment

begin_comment
comment|/****************************************************************/
end_comment

begin_comment
comment|/* WD33C93 Commands */
end_comment

begin_define
define|#
directive|define
name|CMD_RESET
value|0x00
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|CMD_ABORT
value|0x01
end_define

begin_comment
comment|/* Abort */
end_comment

begin_define
define|#
directive|define
name|CMD_ASSERT_ATN
value|0x02
end_define

begin_comment
comment|/* Assert ATN */
end_comment

begin_define
define|#
directive|define
name|CMD_NEGATE_ATN
value|0x03
end_define

begin_comment
comment|/* Negate ATN */
end_comment

begin_define
define|#
directive|define
name|CMD_DISCONNECT
value|0x04
end_define

begin_comment
comment|/* Disconnect */
end_comment

begin_define
define|#
directive|define
name|CMD_RESELECT
value|0x05
end_define

begin_comment
comment|/* Reselect */
end_comment

begin_define
define|#
directive|define
name|CMD_SELECT_ATN
value|0x06
end_define

begin_comment
comment|/* Select with ATN */
end_comment

begin_define
define|#
directive|define
name|CMD_SELECT_NO_ATN
value|0x07
end_define

begin_comment
comment|/* Select without ATN */
end_comment

begin_define
define|#
directive|define
name|CMD_SELECT_ATN_TFR
value|0x08
end_define

begin_comment
comment|/* Select with ATN and Transfer */
end_comment

begin_define
define|#
directive|define
name|CMD_SELECT_NO_ATN_TFR
value|0x09
end_define

begin_comment
comment|/* Select without ATN and Transfer */
end_comment

begin_define
define|#
directive|define
name|CMD_RESELECT_RCV_DATA
value|0x0a
end_define

begin_comment
comment|/* Reselect and Recieve Data */
end_comment

begin_define
define|#
directive|define
name|CMD_RESELECT_SEND_DATA
value|0x0b
end_define

begin_comment
comment|/* Reselect and Send Data */
end_comment

begin_define
define|#
directive|define
name|CMD_WAIT_SELECT_RCV
value|0x0c
end_define

begin_comment
comment|/* Wait for Select and Recieve */
end_comment

begin_define
define|#
directive|define
name|CMD_RCV_CMD
value|0x10
end_define

begin_comment
comment|/* Recieve Command */
end_comment

begin_define
define|#
directive|define
name|CMD_RCV_DATA
value|0x11
end_define

begin_comment
comment|/* Recieve Data */
end_comment

begin_define
define|#
directive|define
name|CMD_RCV_MSG_OUT
value|0x12
end_define

begin_comment
comment|/* Recieve Message Info Out*/
end_comment

begin_define
define|#
directive|define
name|CMD_RCV_UNSP_INFO_OUT
value|0x13
end_define

begin_comment
comment|/* Recieve Unspecified Info Out */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND_STATUS
value|0x14
end_define

begin_comment
comment|/* Send Status */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND_DATA
value|0x15
end_define

begin_comment
comment|/* Send Data */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND_MSG_IN
value|0x16
end_define

begin_comment
comment|/* Send Message In */
end_comment

begin_define
define|#
directive|define
name|CMD_SEND_UNSP_INFO_IN
value|0x17
end_define

begin_comment
comment|/* Send Unspecified Info In */
end_comment

begin_define
define|#
directive|define
name|CMD_TRANSLATE_ADDRESS
value|0x18
end_define

begin_comment
comment|/* Translate Address */
end_comment

begin_define
define|#
directive|define
name|CMD_TFR_INFO
value|0x20
end_define

begin_comment
comment|/* Transfer Info */
end_comment

begin_define
define|#
directive|define
name|CMD_TFR_PAD
value|0x21
end_define

begin_comment
comment|/* Transfer Pad */
end_comment

begin_define
define|#
directive|define
name|CMD_SBT_SFX
value|0x80
end_define

begin_comment
comment|/* single byte suffix */
end_comment

begin_comment
comment|/* WD33C93 bus status register (lower nibble) */
end_comment

begin_define
define|#
directive|define
name|STAT_DATAOUT
value|0x08
end_define

begin_comment
comment|/* Data out phase */
end_comment

begin_define
define|#
directive|define
name|STAT_DATAIN
value|0x09
end_define

begin_comment
comment|/* Data in phase */
end_comment

begin_define
define|#
directive|define
name|STAT_CMDOUT
value|0x0a
end_define

begin_comment
comment|/* Command out phase */
end_comment

begin_define
define|#
directive|define
name|STAT_STATIN
value|0x0b
end_define

begin_comment
comment|/* Status in phase */
end_comment

begin_define
define|#
directive|define
name|STAT_MSGOUT
value|0x0e
end_define

begin_comment
comment|/* Message out phase */
end_comment

begin_define
define|#
directive|define
name|STAT_MSGIN
value|0x0f
end_define

begin_comment
comment|/* Message in phase */
end_comment

begin_comment
comment|/* SCSI Status byte */
end_comment

begin_define
define|#
directive|define
name|SS_GOOD
value|0x00
end_define

begin_comment
comment|/* Good status */
end_comment

begin_define
define|#
directive|define
name|SS_CHKCOND
value|0x02
end_define

begin_define
define|#
directive|define
name|SS_MET
value|0x04
end_define

begin_define
define|#
directive|define
name|SS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SS_INTERGOOD
value|0x10
end_define

begin_define
define|#
directive|define
name|SS_INTERMET
value|0x14
end_define

begin_define
define|#
directive|define
name|SS_CONFLICT
value|0x18
end_define

begin_comment
comment|/* SCSI message system */
end_comment

begin_define
define|#
directive|define
name|MSG_COMPLETE
value|0x00
end_define

begin_comment
comment|/* Command complete message */
end_comment

begin_define
define|#
directive|define
name|MSG_EXTEND
value|0x01
end_define

begin_comment
comment|/* Extend message */
end_comment

begin_define
define|#
directive|define
name|MSG_SAVEPTR
value|0x02
end_define

begin_comment
comment|/* Save data pointer message */
end_comment

begin_define
define|#
directive|define
name|MSG_RESTORE
value|0x03
end_define

begin_comment
comment|/* Restore data pointer message */
end_comment

begin_define
define|#
directive|define
name|MSG_DISCON
value|0x04
end_define

begin_comment
comment|/* Disconnect message */
end_comment

begin_define
define|#
directive|define
name|MSG_INIERROR
value|0x05
end_define

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_REJECT
value|0x07
end_define

begin_define
define|#
directive|define
name|MSG_NOP
value|0x08
end_define

begin_define
define|#
directive|define
name|MSG_PARERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|MSG_LCOMPLETE
value|0x0a
end_define

begin_define
define|#
directive|define
name|MSG_LCOMPLETEF
value|0x0b
end_define

begin_define
define|#
directive|define
name|MSG_DEVRESET
value|0x0c
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY
value|0x80
end_define

begin_comment
comment|/* Identify message */
end_comment

end_unit

