begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This file is in the public domain.  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Messages (1 byte) */
end_comment

begin_comment
comment|/* I/T (M)andatory or (O)ptional */
end_comment

begin_define
define|#
directive|define
name|MSG_CMDCOMPLETE
value|0x00
end_define

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_TASK_COMPLETE
value|0x00
end_define

begin_comment
comment|/* M/M */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_EXTENDED
value|0x01
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_SAVEDATAPOINTER
value|0x02
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_RESTOREPOINTERS
value|0x03
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_DISCONNECT
value|0x04
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_INITIATOR_DET_ERR
value|0x05
end_define

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT
value|0x06
end_define

begin_comment
comment|/* O/M */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT_TASK_SET
value|0x06
end_define

begin_comment
comment|/* O/M */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_MESSAGE_REJECT
value|0x07
end_define

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_NOOP
value|0x08
end_define

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_PARITY_ERROR
value|0x09
end_define

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_LINK_CMD_COMPLETE
value|0x0a
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_LINK_CMD_COMPLETEF
value|0x0b
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_BUS_DEV_RESET
value|0x0c
end_define

begin_comment
comment|/* O/M */
end_comment

begin_define
define|#
directive|define
name|MSG_TARGET_RESET
value|0x0c
end_define

begin_comment
comment|/* O/M */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT_TAG
value|0x0d
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_ABORT_TASK
value|0x0d
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_CLEAR_QUEUE
value|0x0e
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_CLEAR_TASK_SET
value|0x0e
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_INIT_RECOVERY
value|0x0f
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* Deprecated in SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_REL_RECOVERY
value|0x10
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* Deprecated in SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_TERM_IO_PROC
value|0x11
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* Deprecated in SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_CLEAR_ACA
value|0x16
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_LOGICAL_UNIT_RESET
value|0x17
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_QAS_REQUEST
value|0x55
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 */
end_comment

begin_comment
comment|/* Messages (2 byte) */
end_comment

begin_define
define|#
directive|define
name|MSG_SIMPLE_Q_TAG
value|0x20
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_SIMPLE_TASK
value|0x20
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_HEAD_OF_Q_TAG
value|0x21
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_HEAD_OF_QUEUE_TASK
value|0x21
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_ORDERED_Q_TAG
value|0x22
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_ORDERED_TASK
value|0x22
end_define

begin_comment
comment|/* O/O */
end_comment

begin_comment
comment|/* SPI3 Terminology */
end_comment

begin_define
define|#
directive|define
name|MSG_IGN_WIDE_RESIDUE
value|0x23
end_define

begin_comment
comment|/* O/O */
end_comment

begin_define
define|#
directive|define
name|MSG_ACA_TASK
value|0x24
end_define

begin_comment
comment|/* 0/0 */
end_comment

begin_comment
comment|/* SPI3 */
end_comment

begin_comment
comment|/* Identify message */
end_comment

begin_comment
comment|/* M/M */
end_comment

begin_define
define|#
directive|define
name|MSG_IDENTIFYFLAG
value|0x80
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY_DISCFLAG
value|0x40
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY
parameter_list|(
name|lun
parameter_list|,
name|disc
parameter_list|)
value|(((disc) ? 0xc0 : MSG_IDENTIFYFLAG) | (lun))
end_define

begin_define
define|#
directive|define
name|MSG_ISIDENTIFY
parameter_list|(
name|m
parameter_list|)
value|((m)& MSG_IDENTIFYFLAG)
end_define

begin_define
define|#
directive|define
name|MSG_IDENTIFY_LUNMASK
value|0x3F
end_define

begin_comment
comment|/* Extended messages (opcode and length) */
end_comment

begin_define
define|#
directive|define
name|MSG_EXT_SDTR
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_EXT_SDTR_LEN
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR
value|0x03
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_LEN
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_8_BIT
value|0x00
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_16_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|MSG_EXT_WDTR_BUS_32_BIT
value|0x02
end_define

begin_comment
comment|/* Deprecated in SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_EXT_PPR
value|0x04
end_define

begin_comment
comment|/* SPI3 */
end_comment

begin_define
define|#
directive|define
name|MSG_EXT_PPR_LEN
value|0x06
end_define

begin_define
define|#
directive|define
name|MSG_EXT_PPR_QAS_REQ
value|0x04
end_define

begin_define
define|#
directive|define
name|MSG_EXT_PPR_DT_REQ
value|0x02
end_define

begin_define
define|#
directive|define
name|MSG_EXT_PPR_IU_REQ
value|0x01
end_define

end_unit

