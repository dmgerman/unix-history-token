begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ds8390.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Nominal Semidestructor DS8390 Ethernet Chip  * Register and bit definitions  */
end_comment

begin_comment
comment|/*  * Page register offset values  */
end_comment

begin_define
define|#
directive|define
name|ds_cmd
value|0x00
end_define

begin_comment
comment|/* Command register: 		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_STOP
value|0x01
end_define

begin_comment
comment|/*	Stop controller		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_START
value|0x02
end_define

begin_comment
comment|/*	Start controller	*/
end_comment

begin_define
define|#
directive|define
name|DSCM_TRANS
value|0x04
end_define

begin_comment
comment|/*	Transmit packet		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_RREAD
value|0x08
end_define

begin_comment
comment|/*	Remote read 		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_RWRITE
value|0x10
end_define

begin_comment
comment|/*	Remote write 		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_NODMA
value|0x20
end_define

begin_comment
comment|/*	No Remote DMA present	*/
end_comment

begin_define
define|#
directive|define
name|DSCM_PG0
value|0x00
end_define

begin_comment
comment|/*	Select Page 0		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_PG1
value|0x40
end_define

begin_comment
comment|/*	Select Page 1		*/
end_comment

begin_define
define|#
directive|define
name|DSCM_PG2
value|0x80
end_define

begin_comment
comment|/*	Select Page 2?		*/
end_comment

begin_define
define|#
directive|define
name|ds0_pstart
value|0x01
end_define

begin_comment
comment|/* Page Start register		*/
end_comment

begin_define
define|#
directive|define
name|ds0_pstop
value|0x02
end_define

begin_comment
comment|/* Page Stop register		*/
end_comment

begin_define
define|#
directive|define
name|ds0_bnry
value|0x03
end_define

begin_comment
comment|/* Boundary Pointer		*/
end_comment

begin_define
define|#
directive|define
name|ds0_tsr
value|0x04
end_define

begin_comment
comment|/* Transmit Status (read-only)	*/
end_comment

begin_define
define|#
directive|define
name|DSTS_PTX
value|0x01
end_define

begin_comment
comment|/*  Successful packet transmit  */
end_comment

begin_define
define|#
directive|define
name|DSTS_COLL
value|0x04
end_define

begin_comment
comment|/*  Packet transmit w/ collision*/
end_comment

begin_define
define|#
directive|define
name|DSTS_COLL16
value|0x04
end_define

begin_comment
comment|/*  Packet had>16 collisions& fail */
end_comment

begin_define
define|#
directive|define
name|DSTS_UND
value|0x20
end_define

begin_comment
comment|/*  FIFO Underrun on transmission*/
end_comment

begin_define
define|#
directive|define
name|ds0_tpsr
value|ds0_tsr
end_define

begin_comment
comment|/* Transmit Page (write-only)	*/
end_comment

begin_define
define|#
directive|define
name|ds0_tbcr0
value|0x05
end_define

begin_comment
comment|/* Transmit Byte count, low  WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_tbcr1
value|0x06
end_define

begin_comment
comment|/* Transmit Byte count, high WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_isr
value|0x07
end_define

begin_comment
comment|/* Interrupt status register	*/
end_comment

begin_define
define|#
directive|define
name|DSIS_RX
value|0x01
end_define

begin_comment
comment|/*  Successful packet reception */
end_comment

begin_define
define|#
directive|define
name|DSIS_TX
value|0x02
end_define

begin_comment
comment|/*  Successful packet transmission  */
end_comment

begin_define
define|#
directive|define
name|DSIS_RXE
value|0x04
end_define

begin_comment
comment|/*  Packet reception  w/error   */
end_comment

begin_define
define|#
directive|define
name|DSIS_TXE
value|0x08
end_define

begin_comment
comment|/*  Packet transmission  w/error*/
end_comment

begin_define
define|#
directive|define
name|DSIS_ROVRN
value|0x10
end_define

begin_comment
comment|/*  Receiver overrun in the ring*/
end_comment

begin_define
define|#
directive|define
name|DSIS_CTRS
value|0x20
end_define

begin_comment
comment|/*  Diagnostic counters need attn */
end_comment

begin_define
define|#
directive|define
name|DSIS_RDC
value|0x40
end_define

begin_comment
comment|/*  Remote DMA Complete         */
end_comment

begin_define
define|#
directive|define
name|DSIS_RESET
value|0x80
end_define

begin_comment
comment|/*  Reset Complete              */
end_comment

begin_define
define|#
directive|define
name|ds0_rsar0
value|0x08
end_define

begin_comment
comment|/* Remote start address low  WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rsar1
value|0x09
end_define

begin_comment
comment|/* Remote start address high WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rbcr0
value|0x0A
end_define

begin_comment
comment|/* Remote byte count low     WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rbcr1
value|0x0B
end_define

begin_comment
comment|/* Remote byte count high    WO	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rsr
value|0x0C
end_define

begin_comment
comment|/* Receive status            RO	*/
end_comment

begin_define
define|#
directive|define
name|DSRS_RPC
value|0x01
end_define

begin_comment
comment|/*  Received Packet Complete    */
end_comment

begin_define
define|#
directive|define
name|ds0_rcr
value|ds0_rsr
end_define

begin_comment
comment|/* Receive configuration     WO */
end_comment

begin_define
define|#
directive|define
name|DSRC_SEP
value|0x01
end_define

begin_comment
comment|/* Save error packets		*/
end_comment

begin_define
define|#
directive|define
name|DSRC_AR
value|0x02
end_define

begin_comment
comment|/* Accept Runt packets		*/
end_comment

begin_define
define|#
directive|define
name|DSRC_AB
value|0x04
end_define

begin_comment
comment|/* Accept Broadcast packets	*/
end_comment

begin_define
define|#
directive|define
name|DSRC_AM
value|0x08
end_define

begin_comment
comment|/* Accept Multicast packets	*/
end_comment

begin_define
define|#
directive|define
name|DSRC_PRO
value|0x10
end_define

begin_comment
comment|/* Promiscuous physical		*/
end_comment

begin_define
define|#
directive|define
name|DSRC_MON
value|0x20
end_define

begin_comment
comment|/* Monitor mode			*/
end_comment

begin_define
define|#
directive|define
name|ds0_tcr
value|0x0D
end_define

begin_comment
comment|/* Transmit configuration    WO */
end_comment

begin_define
define|#
directive|define
name|DSTC_CRC
value|0x01
end_define

begin_comment
comment|/* Inhibit CRC			*/
end_comment

begin_define
define|#
directive|define
name|DSTC_LB0
value|0x02
end_define

begin_comment
comment|/* Encoded Loopback Control	*/
end_comment

begin_define
define|#
directive|define
name|DSTC_LB1
value|0x04
end_define

begin_comment
comment|/* Encoded Loopback Control	*/
end_comment

begin_define
define|#
directive|define
name|DSTC_ATD
value|0x08
end_define

begin_comment
comment|/* Auto Transmit Disable	*/
end_comment

begin_define
define|#
directive|define
name|DSTC_OFST
value|0x10
end_define

begin_comment
comment|/* Collision Offset Enable	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rcvalctr
value|ds0_tcr
end_define

begin_comment
comment|/* Receive alignment err ctr RO */
end_comment

begin_define
define|#
directive|define
name|ds0_dcr
value|0x0E
end_define

begin_comment
comment|/* Data configuration	     WO */
end_comment

begin_define
define|#
directive|define
name|DSDC_WTS
value|0x01
end_define

begin_comment
comment|/* Word Transfer Select		*/
end_comment

begin_define
define|#
directive|define
name|DSDC_BOS
value|0x02
end_define

begin_comment
comment|/* Byte Order Select		*/
end_comment

begin_define
define|#
directive|define
name|DSDC_LAS
value|0x04
end_define

begin_comment
comment|/* Long Address Select		*/
end_comment

begin_define
define|#
directive|define
name|DSDC_BMS
value|0x08
end_define

begin_comment
comment|/* Burst Mode Select		*/
end_comment

begin_define
define|#
directive|define
name|DSDC_AR
value|0x10
end_define

begin_comment
comment|/* Autoinitialize Remote	*/
end_comment

begin_define
define|#
directive|define
name|DSDC_FT0
value|0x20
end_define

begin_comment
comment|/* Fifo Threshold Select	*/
end_comment

begin_define
define|#
directive|define
name|DSDC_FT1
value|0x40
end_define

begin_comment
comment|/* Fifo Threshold Select	*/
end_comment

begin_define
define|#
directive|define
name|ds0_rcvcrcctr
value|ds0_dcr
end_define

begin_comment
comment|/* Receive CRC error counter RO */
end_comment

begin_define
define|#
directive|define
name|ds0_imr
value|0x0F
end_define

begin_comment
comment|/* Interrupt mask register   WO	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_PRXE
value|0x01
end_define

begin_comment
comment|/*  Packet received enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_PTXE
value|0x02
end_define

begin_comment
comment|/*  Packet transmitted enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_RXEE
value|0x04
end_define

begin_comment
comment|/*  Receive error enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_TXEE
value|0x08
end_define

begin_comment
comment|/*  Transmit error enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_OVWE
value|0x10
end_define

begin_comment
comment|/*  Overwrite warning enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_CNTE
value|0x20
end_define

begin_comment
comment|/*  Counter overflow enable	*/
end_comment

begin_define
define|#
directive|define
name|DSIM_RDCE
value|0x40
end_define

begin_comment
comment|/*  Dma complete enable		*/
end_comment

begin_define
define|#
directive|define
name|ds0_rcvfrmctr
value|ds0_imr
end_define

begin_comment
comment|/* Receive Frame error cntr  RO */
end_comment

begin_define
define|#
directive|define
name|ds1_par0
value|ds0_pstart
end_define

begin_comment
comment|/* Physical address register 0	*/
end_comment

begin_comment
comment|/* Physical address registers 1-4 	*/
end_comment

begin_define
define|#
directive|define
name|ds1_par5
value|ds0_tbcr1
end_define

begin_comment
comment|/* Physical address register 5	*/
end_comment

begin_define
define|#
directive|define
name|ds1_curr
value|ds0_isr
end_define

begin_comment
comment|/* Current page (receive unit)  */
end_comment

begin_define
define|#
directive|define
name|ds1_mar0
value|ds0_rsar0
end_define

begin_comment
comment|/* Multicast address register 0	*/
end_comment

begin_comment
comment|/* Multicast address registers 1-6 	*/
end_comment

begin_define
define|#
directive|define
name|ds1_mar7
value|ds0_imr
end_define

begin_comment
comment|/* Multicast address register 7	*/
end_comment

begin_define
define|#
directive|define
name|ds1_curr
value|ds0_isr
end_define

begin_comment
comment|/* Current page (receive unit)  */
end_comment

begin_define
define|#
directive|define
name|DS_PGSIZE
value|256
end_define

begin_comment
comment|/* Size of RAM pages in bytes	*/
end_comment

begin_comment
comment|/*  * Packet receive header, 1 per each buffer page used in receive packet  */
end_comment

begin_struct
struct|struct
name|prhdr
block|{
name|u_char
name|pr_status
decl_stmt|;
comment|/* is this a good packet, same as ds0_rsr */
name|u_char
name|pr_nxtpg
decl_stmt|;
comment|/* next page of packet or next packet */
name|u_char
name|pr_sz0
decl_stmt|;
name|u_char
name|pr_sz1
decl_stmt|;
block|}
struct|;
end_struct

end_unit

