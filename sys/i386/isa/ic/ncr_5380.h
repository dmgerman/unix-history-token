begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dkuug.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id$  *  * Definitions for 5380 SCSI-controller chip.  *  * Derived from "NCR 53C80 Family SCSI Protocol Controller Data Manual"  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * Register map  */
end_comment

begin_comment
unit|typedef struct {     volatile u_char sci_data;
comment|/* r: Current data */
end_comment

begin_define
define|#
directive|define
name|sci_odata
value|sci_data
end_define

begin_comment
comment|/* w: Out data */
end_comment

begin_comment
unit|volatile u_char sci_icmd;
comment|/* rw:Initiator command */
end_comment

begin_comment
unit|volatile u_char sci_mode;
comment|/* rw:Mode */
end_comment

begin_comment
unit|volatile u_char sci_tcmd;
comment|/* rw:Target command */
end_comment

begin_comment
unit|volatile u_char sci_bus_csr;
comment|/* r: Bus Status */
end_comment

begin_define
define|#
directive|define
name|sci_sel_enb
value|sci_bus_csr
end_define

begin_comment
comment|/* w: Select enable */
end_comment

begin_comment
unit|volatile u_char sci_csr;
comment|/* r: Status */
end_comment

begin_define
define|#
directive|define
name|sci_dma_send
value|sci_csr
end_define

begin_comment
comment|/* w: Start dma send data */
end_comment

begin_comment
unit|volatile u_char sci_idata;
comment|/* r: Input data */
end_comment

begin_define
define|#
directive|define
name|sci_trecv
value|sci_idata
end_define

begin_comment
comment|/* w: Start dma recv, target */
end_comment

begin_comment
unit|volatile u_char sci_iack;
comment|/* r: Interrupt Acknowledge  */
end_comment

begin_define
define|#
directive|define
name|sci_irecv
value|sci_iack
end_define

begin_comment
comment|/* w: Start dma recv, initiator */
end_comment

begin_comment
unit|} sci_regmap_t;
comment|/*  * Initiator command register  */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_DATA
value|0x01
end_define

begin_comment
comment|/* rw:Assert data bus   */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_ATN
value|0x02
end_define

begin_comment
comment|/* rw:Assert ATN signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_SEL
value|0x04
end_define

begin_comment
comment|/* rw:Assert SEL signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_BSY
value|0x08
end_define

begin_comment
comment|/* rw:Assert BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_ACK
value|0x10
end_define

begin_comment
comment|/* rw:Assert ACK signal */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_LST
value|0x20
end_define

begin_comment
comment|/* r: Lost arbitration */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_DIFF
value|SCI_ICMD_LST
end_define

begin_comment
comment|/* w: Differential cable */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_AIP
value|0x40
end_define

begin_comment
comment|/* r: Arbitration in progress */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_TEST
value|SCI_ICMD_AIP
end_define

begin_comment
comment|/* w: Test mode */
end_comment

begin_define
define|#
directive|define
name|SCI_ICMD_RST
value|0x80
end_define

begin_comment
comment|/* rw:Assert RST signal */
end_comment

begin_comment
comment|/*  * Mode register  */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_ARB
value|0x01
end_define

begin_comment
comment|/* rw: Start arbitration */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_DMA
value|0x02
end_define

begin_comment
comment|/* rw: Enable DMA xfers */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_MONBSY
value|0x04
end_define

begin_comment
comment|/* rw: Monitor BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_DMA_IE
value|0x08
end_define

begin_comment
comment|/* rw: Enable DMA complete interrupt */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_PERR_IE
value|0x10
end_define

begin_comment
comment|/* rw: Interrupt on parity errors */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_PAR_CHK
value|0x20
end_define

begin_comment
comment|/* rw: Check parity */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_TARGET
value|0x40
end_define

begin_comment
comment|/* rw: Target mode (Initiator if 0) */
end_comment

begin_define
define|#
directive|define
name|SCI_MODE_BLOCKDMA
value|0x80
end_define

begin_comment
comment|/* rw: Block-mode DMA handshake (MBZ) */
end_comment

begin_comment
comment|/*  * Target command register  */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_IO
value|0x01
end_define

begin_comment
comment|/* rw: Assert I/O signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_CD
value|0x02
end_define

begin_comment
comment|/* rw: Assert C/D signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_MSG
value|0x04
end_define

begin_comment
comment|/* rw: Assert MSG signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_PHASE_MASK
value|0x07
end_define

begin_comment
comment|/* r:  Mask for current bus phase */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_REQ
value|0x08
end_define

begin_comment
comment|/* rw: Assert REQ signal */
end_comment

begin_define
define|#
directive|define
name|SCI_TCMD_LAST_SENT
value|0x80
end_define

begin_comment
comment|/* ro: Last byte was xferred 					 *     (not on 5380/1) */
end_comment

begin_define
define|#
directive|define
name|SCI_PHASE
parameter_list|(
name|x
parameter_list|)
value|SCSI_PHASE(x)
end_define

begin_comment
comment|/*  * Current (SCSI) Bus status  */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_DBP
value|0x01
end_define

begin_comment
comment|/* r:  Data Bus parity */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_SEL
value|0x02
end_define

begin_comment
comment|/* r:  SEL signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_IO
value|0x04
end_define

begin_comment
comment|/* r:  I/O signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_CD
value|0x08
end_define

begin_comment
comment|/* r:  C/D signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_MSG
value|0x10
end_define

begin_comment
comment|/* r:  MSG signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_REQ
value|0x20
end_define

begin_comment
comment|/* r:  REQ signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_BSY
value|0x40
end_define

begin_comment
comment|/* r:  BSY signal */
end_comment

begin_define
define|#
directive|define
name|SCI_BUS_RST
value|0x80
end_define

begin_comment
comment|/* r:  RST signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CUR_PHASE
parameter_list|(
name|x
parameter_list|)
value|SCSI_PHASE((x)>>2)
end_define

begin_comment
comment|/*  * Bus and Status register  */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_ACK
value|0x01
end_define

begin_comment
comment|/* r:  ACK signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_ATN
value|0x02
end_define

begin_comment
comment|/* r:  ATN signal */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DISC
value|0x04
end_define

begin_comment
comment|/* r:  Disconnected (BSY==0) */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_PHASE_MATCH
value|0x08
end_define

begin_comment
comment|/* r:  Bus and SCI_TCMD match */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_INT
value|0x10
end_define

begin_comment
comment|/* r:  Interrupt request */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_PERR
value|0x20
end_define

begin_comment
comment|/* r:  Parity error */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DREQ
value|0x40
end_define

begin_comment
comment|/* r:  DMA request */
end_comment

begin_define
define|#
directive|define
name|SCI_CSR_DONE
value|0x80
end_define

begin_comment
comment|/* r:  DMA count is zero */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|R_CSDR
value|0
end_define

begin_comment
comment|/* R   Current SCSI Data Reg.		*/
end_comment

begin_define
define|#
directive|define
name|W_ODR
value|0
end_define

begin_comment
comment|/* W   Output Data Reg.			*/
end_comment

begin_define
define|#
directive|define
name|R_ICR
value|1
end_define

begin_comment
comment|/* R   Initiator Command Reg.		*/
end_comment

begin_define
define|#
directive|define
name|R_ICR_ASSERT_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|R_ICR_ARBITRATION_IN_PROGRESS
value|0x40
end_define

begin_define
define|#
directive|define
name|R_ICR_LOST_ARBITRATION
value|0x20
end_define

begin_define
define|#
directive|define
name|R_ICR_ASSERT_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|R_ICR_ASSERT_BSY
value|0x08
end_define

begin_define
define|#
directive|define
name|R_ICR_ASSERT_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|R_ICR_ASSERT_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|R_ICR_ASSERT_DATA_BUS
value|0x01
end_define

begin_define
define|#
directive|define
name|W_ICR
value|1
end_define

begin_comment
comment|/* W   Initiator Command Reg.		*/
end_comment

begin_define
define|#
directive|define
name|W_ICR_ASSERT_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|W_ICR_TRI_STATE_MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|W_ICR_DIFF_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|W_ICR_ASSERT_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|W_ICR_ASSERT_BSY
value|0x08
end_define

begin_define
define|#
directive|define
name|W_ICR_ASSERT_SEL
value|0x04
end_define

begin_define
define|#
directive|define
name|W_ICR_ASSERT_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|W_ICR_ASSERT_DATA_BUS
value|0x01
end_define

begin_comment
comment|/*   * The mask to use when doing read_modify_write on ICR.  */
end_comment

begin_define
define|#
directive|define
name|RW_ICR_MASK
value|(~(W_ICR_DIFF_ENABLE|W_ICR_TRI_STATE_MODE))
end_define

begin_define
define|#
directive|define
name|RW_MR
value|2
end_define

begin_comment
comment|/* RW  Mode Reg.			*/
end_comment

begin_define
define|#
directive|define
name|RW_MR_BLOCK_MODE_DMA
value|0x80
end_define

begin_define
define|#
directive|define
name|RW_MR_TARGET_MODE
value|0x40
end_define

begin_define
define|#
directive|define
name|RW_MR_ENABLE_PARITY_CHECKING
value|0x20
end_define

begin_define
define|#
directive|define
name|RW_MR_ENABLE_PARITY_INTERRUPT
value|0x10
end_define

begin_define
define|#
directive|define
name|RW_MR_ENABLE_EOP_INTERRUPT
value|0x08
end_define

begin_define
define|#
directive|define
name|RW_MR_MONITOR_BUSY
value|0x04
end_define

begin_define
define|#
directive|define
name|RW_MR_DMA_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|RW_MR_ARBITRATE
value|0x01
end_define

begin_define
define|#
directive|define
name|R_TCR
value|3
end_define

begin_comment
comment|/* R   Target Command Reg.		*/
end_comment

begin_define
define|#
directive|define
name|R_TCR_LAST_BYTE_SENT
value|0x80
end_define

begin_comment
comment|/*      R_TCR_RESERVED			0x40 */
end_comment

begin_comment
comment|/*      R_TCR_RESERVED			0x20 */
end_comment

begin_comment
comment|/*      R_TCR_RESERVED			0x10 */
end_comment

begin_define
define|#
directive|define
name|R_TCR_ASSERT_REQ
value|0x08
end_define

begin_define
define|#
directive|define
name|R_TCR_ASSERT_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|R_TCR_ASSERT_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|R_TCR_ASSERT_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|W_TCR
value|3
end_define

begin_comment
comment|/* W   Target Command Reg.		*/
end_comment

begin_comment
comment|/*      W_TCR_RESERVED			0x80 */
end_comment

begin_comment
comment|/*      W_TCR_RESERVED			0x40 */
end_comment

begin_comment
comment|/*      W_TCR_RESERVED			0x20 */
end_comment

begin_comment
comment|/*      W_TCR_RESERVED			0x10 */
end_comment

begin_define
define|#
directive|define
name|W_TCR_ASSERT_REQ
value|0x08
end_define

begin_define
define|#
directive|define
name|W_TCR_ASSERT_MSG
value|0x04
end_define

begin_define
define|#
directive|define
name|W_TCR_ASSERT_CD
value|0x02
end_define

begin_define
define|#
directive|define
name|W_TCR_ASSERT_IO
value|0x01
end_define

begin_define
define|#
directive|define
name|R_CSCR
value|4
end_define

begin_comment
comment|/* R   Current SCSI Bus Status Reg.	*/
end_comment

begin_define
define|#
directive|define
name|R_CSCR_RST
value|0x80
end_define

begin_define
define|#
directive|define
name|R_CSCR_BSY
value|0x40
end_define

begin_define
define|#
directive|define
name|R_CSCR_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|R_CSCR_MSG
value|0x10
end_define

begin_define
define|#
directive|define
name|R_CSCR_CD
value|0x08
end_define

begin_define
define|#
directive|define
name|R_CSCR_IO
value|0x04
end_define

begin_define
define|#
directive|define
name|R_CSCR_SEL
value|0x02
end_define

begin_define
define|#
directive|define
name|R_CSCR_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|W_SER
value|4
end_define

begin_comment
comment|/* W   Select Enable Reg.		*/
end_comment

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_7
value|0x80
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_6
value|0x40
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_5
value|0x20
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_4
value|0x10
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_3
value|0x08
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_2
value|0x04
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_1
value|0x02
end_define

begin_define
define|#
directive|define
name|W_SER_SCSI_ID_0
value|0x01
end_define

begin_define
define|#
directive|define
name|R_BSR
value|5
end_define

begin_comment
comment|/* R   Bus and Status Reg.		*/
end_comment

begin_define
define|#
directive|define
name|R_BSR_END_OF_DMA_XFER
value|0x80
end_define

begin_define
define|#
directive|define
name|R_BSR_DMA_REQUEST
value|0x40
end_define

begin_define
define|#
directive|define
name|R_BSR_PARITY_ERROR
value|0x20
end_define

begin_define
define|#
directive|define
name|R_BSR_INTERRUPT_REQUEST_ACTIVE
value|0x10
end_define

begin_define
define|#
directive|define
name|R_BSR_PHASE_MISMATCH
value|0x08
end_define

begin_define
define|#
directive|define
name|R_BSR_BUSY_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|R_BSR_ATN
value|0x02
end_define

begin_define
define|#
directive|define
name|R_BSR_ACK
value|0x01
end_define

begin_define
define|#
directive|define
name|W_SDSR
value|5
end_define

begin_comment
comment|/* W   Start DMA Send Reg.		*/
end_comment

begin_define
define|#
directive|define
name|R_IDR
value|6
end_define

begin_comment
comment|/* R   Input Data Reg.			*/
end_comment

begin_define
define|#
directive|define
name|W_SDTR
value|6
end_define

begin_comment
comment|/* W   Start DMA Target Receive Reg.	*/
end_comment

begin_define
define|#
directive|define
name|R_RPIR
value|7
end_define

begin_comment
comment|/* R   Reset Parity/Interrupt Reg.	*/
end_comment

begin_define
define|#
directive|define
name|W_SDIR
value|7
end_define

begin_comment
comment|/* W  Start DMA Initiator Receive Reg.	*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IC_NCR_5380_H_ */
end_comment

end_unit

