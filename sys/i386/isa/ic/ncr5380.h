begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  * Modified by Serge Vakulenko (vak@cronyx.ru)  *  * ncr_5380.h,v 1.2 1994/09/11 20:29:18 phk Exp  *  * Definitions for 5380 SCSI-controller chip.  *  * Derived from "NCR 53C80 Family SCSI Protocol Controller Data Manual"  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IC_NCR_5380_H_
end_ifndef

begin_define
define|#
directive|define
name|_IC_NCR_5380_H_
end_define

begin_define
define|#
directive|define
name|C80_CSDR
value|0
end_define

begin_comment
comment|/* ro - Current SCSI Data Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_ODR
value|0
end_define

begin_comment
comment|/* wo - Output Data Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_ICR
value|1
end_define

begin_comment
comment|/* rw - Initiator Command Reg. */
end_comment

begin_define
define|#
directive|define
name|ICR_ASSERT_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|ICR_ARBITRATION_IN_PROGRESS
value|0x40
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|ICR_TRI_STATE_MODE
value|0x40
end_define

begin_comment
comment|/* write only */
end_comment

begin_define
define|#
directive|define
name|ICR_LOST_ARBITRATION
value|0x20
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|ICR_DIFF_ENABLE
value|0x20
end_define

begin_comment
comment|/* write only */
end_comment

begin_define
define|#
directive|define
name|ICR_ASSERT_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|ICR_ASSERT_BSY
value|0x08
end_define

begin_define
define|#
directive|define
name|ICR_ASSERT_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|ICR_ASSERT_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|ICR_ASSERT_DATA_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|ICR_BITS
value|"\20\1dbus\2atn\3sel\4bsy\5ack\6arblost\7arb\10rst"
end_define

begin_comment
comment|/*   * The mask to use when doing read_modify_write on ICR.  */
end_comment

begin_define
define|#
directive|define
name|ICR_MASK
value|(~(ICR_DIFF_ENABLE | ICR_TRI_STATE_MODE))
end_define

begin_define
define|#
directive|define
name|C80_MR
value|2
end_define

begin_comment
comment|/* rw - Mode Reg. */
end_comment

begin_define
define|#
directive|define
name|MR_BLOCK_MODE_DMA
value|0x80
end_define

begin_define
define|#
directive|define
name|MR_TARGET_MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|MR_ENABLE_PARITY_CHECKING
value|0x20
end_define

begin_define
define|#
directive|define
name|MR_ENABLE_PARITY_INTERRUPT
value|0x10
end_define

begin_define
define|#
directive|define
name|MR_ENABLE_EOP_INTERRUPT
value|0x08
end_define

begin_define
define|#
directive|define
name|MR_MONITOR_BUSY
value|0x04
end_define

begin_define
define|#
directive|define
name|MR_DMA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|MR_ARBITRATE
value|0x01
end_define

begin_define
define|#
directive|define
name|MR_BITS
value|"\20\1arb\2dma\3mbusy\4eopintr\5parintr\6pcheck\7targ\10blk"
end_define

begin_define
define|#
directive|define
name|C80_TCR
value|3
end_define

begin_comment
comment|/* rw - Target Command Reg. */
end_comment

begin_define
define|#
directive|define
name|TCR_LAST_BYTE_SENT
value|0x80
end_define

begin_comment
comment|/* read only */
end_comment

begin_define
define|#
directive|define
name|TCR_ASSERT_REQ
value|0x08
end_define

begin_define
define|#
directive|define
name|TCR_ASSERT_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|TCR_ASSERT_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|TCR_ASSERT_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|TCR_BITS
value|"\20\1i/o\2c/d\3msg\4req\10lastbyte"
end_define

begin_define
define|#
directive|define
name|C80_CSBR
value|4
end_define

begin_comment
comment|/* ro - Current SCSI Bus Status Reg. */
end_comment

begin_define
define|#
directive|define
name|CSBR_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|CSBR_BSY
value|0x40
end_define

begin_define
define|#
directive|define
name|CSBR_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|CSBR_MSG
value|0x10
end_define

begin_define
define|#
directive|define
name|CSBR_CD
value|0x08
end_define

begin_define
define|#
directive|define
name|CSBR_IO
value|0x04
end_define

begin_define
define|#
directive|define
name|CSBR_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|CSBR_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|CSBR_BITS
value|"\20\1ack\2sel\3i/o\4c/d\5msg\6req\7bsy\10rst"
end_define

begin_define
define|#
directive|define
name|C80_SER
value|4
end_define

begin_comment
comment|/* wo - Select Enable Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_BSR
value|5
end_define

begin_comment
comment|/* ro - Bus and Status Reg. */
end_comment

begin_define
define|#
directive|define
name|BSR_END_OF_DMA_XFER
value|0x80
end_define

begin_define
define|#
directive|define
name|BSR_DMA_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|BSR_PARITY_ERROR
value|0x20
end_define

begin_define
define|#
directive|define
name|BSR_INTERRUPT_REQUEST_ACTIVE
value|0x10
end_define

begin_define
define|#
directive|define
name|BSR_PHASE_MISMATCH
value|0x08
end_define

begin_define
define|#
directive|define
name|BSR_BUSY_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|BSR_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|BSR_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|BSR_BITS
value|"\20\1ack\2atn\3busyerr\4pherr\5irq\6parerr\7drq\10dend"
end_define

begin_define
define|#
directive|define
name|C80_SDSR
value|5
end_define

begin_comment
comment|/* wo - Start DMA Send Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_IDR
value|6
end_define

begin_comment
comment|/* ro - Input Data Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_SDTR
value|6
end_define

begin_comment
comment|/* wo - Start DMA Target Receive Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_RPIR
value|7
end_define

begin_comment
comment|/* ro - Reset Parity/Interrupt Reg. */
end_comment

begin_define
define|#
directive|define
name|C80_SDIR
value|7
end_define

begin_comment
comment|/* wo - Start DMA Initiator Receive Reg. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IC_NCR_5380_H_ */
end_comment

end_unit

