begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1993, David Greenman. This software may be used, modified,  *   copied, distributed, and sold, in both source and binary form provided  *   that the above copyright and these terms are retained. Under no  *   circumstances is the author responsible for the proper functioning  *   of this software, nor does the author assume any responsibility  *   for damages incurred with its use.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * National Semiconductor DS8390 NIC register definitions  *  *  * Modification history  *  * Revision 2.2  1993/11/29  16:33:39  davidg  * From Thomas Sandford<t.d.g.sandford@comp.brad.ac.uk>  * Add support for the 8013W board type  *  * Revision 2.1  1993/11/22  10:52:33  davidg  * patch to add support for SMC8216 (Elite-Ultra) boards  * from Glen H. Lowe  *  * Revision 2.0  93/09/29  00:37:15  davidg  * changed double buffering flag to multi buffering  * made changes/additions for 3c503 multi-buffering  * ...companion to Rev. 2.0 of 'ed' driver.  *  * Revision 1.1  93/06/23  03:01:07  davidg  * Initial revision  *  */
end_comment

begin_comment
comment|/*  * Page 0 register offsets  */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CR
value|0x00
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CLDA0
value|0x01
end_define

begin_comment
comment|/* Current Local DMA Addr low (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_PSTART
value|0x01
end_define

begin_comment
comment|/* Page Start register (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CLDA1
value|0x02
end_define

begin_comment
comment|/* Current Local DMA Addr high (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_PSTOP
value|0x02
end_define

begin_comment
comment|/* Page Stop register (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_BNRY
value|0x03
end_define

begin_comment
comment|/* Boundary Pointer */
end_comment

begin_define
define|#
directive|define
name|ED_P0_TSR
value|0x04
end_define

begin_comment
comment|/* Transmit Status Register (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_TPSR
value|0x04
end_define

begin_comment
comment|/* Transmit Page Start (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_NCR
value|0x05
end_define

begin_comment
comment|/* Number of Collisions Reg (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_TBCR0
value|0x05
end_define

begin_comment
comment|/* Transmit Byte count, low (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_FIFO
value|0x06
end_define

begin_comment
comment|/* FIFO register (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_TBCR1
value|0x06
end_define

begin_comment
comment|/* Transmit Byte count, high (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_ISR
value|0x07
end_define

begin_comment
comment|/* Interrupt Status Register */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CRDA0
value|0x08
end_define

begin_comment
comment|/* Current Remote DMA Addr low (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RSAR0
value|0x08
end_define

begin_comment
comment|/* Remote Start Address low (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CRDA1
value|0x09
end_define

begin_comment
comment|/* Current Remote DMA Addr high (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RSAR1
value|0x09
end_define

begin_comment
comment|/* Remote Start Address high (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RBCR0
value|0x0a
end_define

begin_comment
comment|/* Remote Byte Count low (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RBCR1
value|0x0b
end_define

begin_comment
comment|/* Remote Byte Count high (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RSR
value|0x0c
end_define

begin_comment
comment|/* Receive Status (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_RCR
value|0x0c
end_define

begin_comment
comment|/* Receive Configuration Reg (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CNTR0
value|0x0d
end_define

begin_comment
comment|/* frame alignment error counter (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_TCR
value|0x0d
end_define

begin_comment
comment|/* Transmit Configuration Reg (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CNTR1
value|0x0e
end_define

begin_comment
comment|/* CRC error counter (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_DCR
value|0x0e
end_define

begin_comment
comment|/* Data Configuration Reg (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_CNTR2
value|0x0f
end_define

begin_comment
comment|/* missed packet counter (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P0_IMR
value|0x0f
end_define

begin_comment
comment|/* Interrupt Mask Register (write) */
end_comment

begin_comment
comment|/*  * Page 1 register offsets  */
end_comment

begin_define
define|#
directive|define
name|ED_P1_CR
value|0x00
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR0
value|0x01
end_define

begin_comment
comment|/* Physical Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR1
value|0x02
end_define

begin_comment
comment|/* Physical Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR2
value|0x03
end_define

begin_comment
comment|/* Physical Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR3
value|0x04
end_define

begin_comment
comment|/* Physical Address Register 3 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR4
value|0x05
end_define

begin_comment
comment|/* Physical Address Register 4 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR5
value|0x06
end_define

begin_comment
comment|/* Physical Address Register 5 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_PAR
parameter_list|(
name|i
parameter_list|)
value|(ED_P1_PAR0 + i)
end_define

begin_define
define|#
directive|define
name|ED_P1_CURR
value|0x07
end_define

begin_comment
comment|/* Current RX ring-buffer page */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR0
value|0x08
end_define

begin_comment
comment|/* Multicast Address Register 0 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR1
value|0x09
end_define

begin_comment
comment|/* Multicast Address Register 1 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR2
value|0x0a
end_define

begin_comment
comment|/* Multicast Address Register 2 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR3
value|0x0b
end_define

begin_comment
comment|/* Multicast Address Register 3 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR4
value|0x0c
end_define

begin_comment
comment|/* Multicast Address Register 4 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR5
value|0x0d
end_define

begin_comment
comment|/* Multicast Address Register 5 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR6
value|0x0e
end_define

begin_comment
comment|/* Multicast Address Register 6 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR7
value|0x0f
end_define

begin_comment
comment|/* Multicast Address Register 7 */
end_comment

begin_define
define|#
directive|define
name|ED_P1_MAR
parameter_list|(
name|i
parameter_list|)
value|(ED_P1_MAR0 + i)
end_define

begin_comment
comment|/*  * Page 2 register offsets  */
end_comment

begin_define
define|#
directive|define
name|ED_P2_CR
value|0x00
end_define

begin_comment
comment|/* Command Register */
end_comment

begin_define
define|#
directive|define
name|ED_P2_PSTART
value|0x01
end_define

begin_comment
comment|/* Page Start (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_CLDA0
value|0x01
end_define

begin_comment
comment|/* Current Local DMA Addr 0 (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_PSTOP
value|0x02
end_define

begin_comment
comment|/* Page Stop (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_CLDA1
value|0x02
end_define

begin_comment
comment|/* Current Local DMA Addr 1 (write) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_RNPP
value|0x03
end_define

begin_comment
comment|/* Remote Next Packet Pointer */
end_comment

begin_define
define|#
directive|define
name|ED_P2_TPSR
value|0x04
end_define

begin_comment
comment|/* Transmit Page Start (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_LNPP
value|0x05
end_define

begin_comment
comment|/* Local Next Packet Pointer */
end_comment

begin_define
define|#
directive|define
name|ED_P2_ACU
value|0x06
end_define

begin_comment
comment|/* Address Counter Upper */
end_comment

begin_define
define|#
directive|define
name|ED_P2_ACL
value|0x07
end_define

begin_comment
comment|/* Address Counter Lower */
end_comment

begin_define
define|#
directive|define
name|ED_P2_RCR
value|0x0c
end_define

begin_comment
comment|/* Receive Configuration Register (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_TCR
value|0x0d
end_define

begin_comment
comment|/* Transmit Configuration Register (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_DCR
value|0x0e
end_define

begin_comment
comment|/* Data Configuration Register (read) */
end_comment

begin_define
define|#
directive|define
name|ED_P2_IMR
value|0x0f
end_define

begin_comment
comment|/* Interrupt Mask Register (read) */
end_comment

begin_comment
comment|/*  *		Command Register (CR) definitions  */
end_comment

begin_comment
comment|/*  * STP: SToP. Software reset command. Takes the controller offline. No  *	packets will be received or transmitted. Any reception or  *	transmission in progress will continue to completion before  *	entering reset state. To exit this state, the STP bit must  *	reset and the STA bit must be set. The software reset has  *	executed only when indicated by the RST bit in the ISR being  *	set.  */
end_comment

begin_define
define|#
directive|define
name|ED_CR_STP
value|0x01
end_define

begin_comment
comment|/*  * STA: STArt. This bit is used to activate the NIC after either power-up,  *	or when the NIC has been put in reset mode by software command  *	or error.  */
end_comment

begin_define
define|#
directive|define
name|ED_CR_STA
value|0x02
end_define

begin_comment
comment|/*  * TXP: Transmit Packet. This bit must be set to indicate transmission of  *	a packet. TXP is internally reset either after the transmission is  *	completed or aborted. This bit should be set only after the Transmit  *	Byte Count and Transmit Page Start register have been programmed.  */
end_comment

begin_define
define|#
directive|define
name|ED_CR_TXP
value|0x04
end_define

begin_comment
comment|/*  * RD0, RD1, RD2: Remote DMA Command. These three bits control the operation  *	of the remote DMA channel. RD2 can be set to abort any remote DMA  *	command in progress. The Remote Byte Count registers should be cleared  *	when a remote DMA has been aborted. The Remote Start Addresses are not  *	restored to the starting address if the remote DMA is aborted.  *  *	RD2 RD1 RD0	function  *	 0   0   0	not allowed  *	 0   0   1	remote read  *	 0   1   0	remote write  *	 0   1   1	send packet  *	 1   X   X	abort  */
end_comment

begin_define
define|#
directive|define
name|ED_CR_RD0
value|0x08
end_define

begin_define
define|#
directive|define
name|ED_CR_RD1
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_CR_RD2
value|0x20
end_define

begin_comment
comment|/*  * PS0, PS1: Page Select. The two bits select which register set or 'page' to  *	access.  *  *	PS1 PS0		page  *	 0   0		0  *	 0   1		1  *	 1   0		2  *	 1   1		reserved  */
end_comment

begin_define
define|#
directive|define
name|ED_CR_PS0
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_CR_PS1
value|0x80
end_define

begin_comment
comment|/* bit encoded aliases */
end_comment

begin_define
define|#
directive|define
name|ED_CR_PAGE_0
value|0x00
end_define

begin_comment
comment|/* (for consistency) */
end_comment

begin_define
define|#
directive|define
name|ED_CR_PAGE_1
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_CR_PAGE_2
value|0x80
end_define

begin_comment
comment|/*  *		Interrupt Status Register (ISR) definitions  */
end_comment

begin_comment
comment|/*  * PRX: Packet Received. Indicates packet received with no errors.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_PRX
value|0x01
end_define

begin_comment
comment|/*  * PTX: Packet Transmitted. Indicates packet transmitted with no errors.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_PTX
value|0x02
end_define

begin_comment
comment|/*  * RXE: Receive Error. Indicates that a packet was received with one or more  *	the following errors: CRC error, frame alignment error, FIFO overrun,  *	missed packet.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_RXE
value|0x04
end_define

begin_comment
comment|/*  * TXE: Transmission Error. Indicates that an attempt to transmit a packet  *	resulted in one or more of the following errors: excessive  *	collisions, FIFO underrun.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_TXE
value|0x08
end_define

begin_comment
comment|/*  * OVW: OverWrite. Indicates a receive ring-buffer overrun. Incoming network  *	would exceed (has exceeded?) the boundary pointer, resulting in data  *	that was previously received and not yet read from the buffer to be  *	overwritten.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_OVW
value|0x10
end_define

begin_comment
comment|/*  * CNT: Counter Overflow. Set when the MSB of one or more of the Network Talley  *	Counters has been set.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_CNT
value|0x20
end_define

begin_comment
comment|/*  * RDC: Remote Data Complete. Indicates that a Remote DMA operation has completed.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_RDC
value|0x40
end_define

begin_comment
comment|/*  * RST: Reset status. Set when the NIC enters the reset state and cleared when a  *	Start Command is issued to the CR. This bit is also set when a receive  *	ring-buffer overrun (OverWrite) occurs and is cleared when one or more  *	packets have been removed from the ring. This is a read-only bit.  */
end_comment

begin_define
define|#
directive|define
name|ED_ISR_RST
value|0x80
end_define

begin_comment
comment|/*  *		Interrupt Mask Register (IMR) definitions  */
end_comment

begin_comment
comment|/*  * PRXE: Packet Received interrupt Enable. If set, a received packet will cause  *	an interrupt.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_PRXE
value|0x01
end_define

begin_comment
comment|/*  * PTXE: Packet Transmit interrupt Enable. If set, an interrupt is generated when  *	a packet transmission completes.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_PTXE
value|0x02
end_define

begin_comment
comment|/*  * RXEE: Receive Error interrupt Enable. If set, an interrupt will occur whenever a  *	packet is received with an error.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_RXEE
value|0x04
end_define

begin_comment
comment|/*  * TXEE: Transmit Error interrupt Enable. If set, an interrupt will occur whenever  *	a transmission results in an error.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_TXEE
value|0x08
end_define

begin_comment
comment|/*  * OVWE: OverWrite error interrupt Enable. If set, an interrupt is generated whenever  *	the receive ring-buffer is overrun. i.e. when the boundary pointer is exceeded.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_OVWE
value|0x10
end_define

begin_comment
comment|/*  * CNTE: Counter overflow interrupt Enable. If set, an interrupt is generated whenever  *	the MSB of one or more of the Network Statistics counters has been set.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_CNTE
value|0x20
end_define

begin_comment
comment|/*  * RDCE: Remote DMA Complete interrupt Enable. If set, an interrupt is generated  *	when a remote DMA transfer has completed.  */
end_comment

begin_define
define|#
directive|define
name|ED_IMR_RDCE
value|0x40
end_define

begin_comment
comment|/*  * bit 7 is unused/reserved  */
end_comment

begin_comment
comment|/*  *		Data Configuration Register (DCR) definitions  */
end_comment

begin_comment
comment|/*  * WTS: Word Transfer Select. WTS establishes byte or word transfers for  *	both remote and local DMA transfers  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_WTS
value|0x01
end_define

begin_comment
comment|/*  * BOS: Byte Order Select. BOS sets the byte order for the host.  *	Should be 0 for 80x86, and 1 for 68000 series processors  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_BOS
value|0x02
end_define

begin_comment
comment|/*  * LAS: Long Address Select. When LAS is 1, the contents of the remote  *	DMA registers RSAR0 and RSAR1 are used to provide A16-A31  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_LAS
value|0x04
end_define

begin_comment
comment|/*  * LS: Loopback Select. When 0, loopback mode is selected. Bits D1 and D2  *	of the TCR must also be programmed for loopback operation.  *	When 1, normal operation is selected.  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_LS
value|0x08
end_define

begin_comment
comment|/*  * AR: Auto-initialize Remote. When 0, data must be removed from ring-buffer  *	under program control. When 1, remote DMA is automatically initiated  *	and the boundary pointer is automatically updated  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_AR
value|0x10
end_define

begin_comment
comment|/*  * FT0, FT1: Fifo Threshold select.  *		FT1	FT0	Word-width	Byte-width  *		 0	 0	1 word		2 bytes  *		 0	 1	2 words		4 bytes  *		 1	 0	4 words		8 bytes  *		 1	 1	8 words		12 bytes  *  *	During transmission, the FIFO threshold indicates the number of bytes  *	or words that the FIFO has filled from the local DMA before BREQ is  *	asserted. The transmission threshold is 16 bytes minus the receiver  *	threshold.  */
end_comment

begin_define
define|#
directive|define
name|ED_DCR_FT0
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_DCR_FT1
value|0x40
end_define

begin_comment
comment|/*  * bit 7 (0x80) is unused/reserved  */
end_comment

begin_comment
comment|/*  *		Transmit Configuration Register (TCR) definitions  */
end_comment

begin_comment
comment|/*  * CRC: Inhibit CRC. If 0, CRC will be appended by the transmitter, if 0, CRC  *	is not appended by the transmitter.  */
end_comment

begin_define
define|#
directive|define
name|ED_TCR_CRC
value|0x01
end_define

begin_comment
comment|/*  * LB0, LB1: Loopback control. These two bits set the type of loopback that is  *	to be performed.  *  *	LB1 LB0		mode  *	 0   0		0 - normal operation (DCR_LS = 0)  *	 0   1		1 - internal loopback (DCR_LS = 0)  *	 1   0		2 - external loopback (DCR_LS = 1)  *	 1   1		3 - external loopback (DCR_LS = 0)  */
end_comment

begin_define
define|#
directive|define
name|ED_TCR_LB0
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_TCR_LB1
value|0x04
end_define

begin_comment
comment|/*  * ATD: Auto Transmit Disable. Clear for normal operation. When set, allows  *	another station to disable the NIC's transmitter by transmitting to  *	a multicast address hashing to bit 62. Reception of a multicast address  *	hashing to bit 63 enables the transmitter.  */
end_comment

begin_define
define|#
directive|define
name|ED_TCR_ATD
value|0x08
end_define

begin_comment
comment|/*  * OFST: Collision Offset enable. This bit when set modifies the backoff  *	algorithm to allow prioritization of nodes.  */
end_comment

begin_define
define|#
directive|define
name|ED_TCR_OFST
value|0x10
end_define

begin_comment
comment|/*  * bits 5, 6, and 7 are unused/reserved  */
end_comment

begin_comment
comment|/*  *		Transmit Status Register (TSR) definitions  */
end_comment

begin_comment
comment|/*  * PTX: Packet Transmitted. Indicates successful transmission of packet.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_PTX
value|0x01
end_define

begin_comment
comment|/*  * bit 1 (0x02) is unused/reserved  */
end_comment

begin_comment
comment|/*  * COL: Transmit Collided. Indicates that the transmission collided at least  *	once with another station on the network.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_COL
value|0x04
end_define

begin_comment
comment|/*  * ABT: Transmit aborted. Indicates that the transmission was aborted due to  *	excessive collisions.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_ABT
value|0x08
end_define

begin_comment
comment|/*  * CRS: Carrier Sense Lost. Indicates that carrier was lost during the  *	transmission of the packet. (Transmission is not aborted because  *	of a loss of carrier)  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_CRS
value|0x10
end_define

begin_comment
comment|/*  * FU: FIFO Underrun. Indicates that the NIC wasn't able to access bus/  *	transmission memory before the FIFO emptied. Transmission of the  *	packet was aborted.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_FU
value|0x20
end_define

begin_comment
comment|/*  * CDH: CD Heartbeat. Indicates that the collision detection circuitry  *	isn't working correctly during a collision heartbeat test.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_CDH
value|0x40
end_define

begin_comment
comment|/*  * OWC: Out of Window Collision: Indicates that a collision occurred after  *	a slot time (51.2us). The transmission is rescheduled just as in  *	normal collisions.  */
end_comment

begin_define
define|#
directive|define
name|ED_TSR_OWC
value|0x80
end_define

begin_comment
comment|/*  *		Receiver Configuration Register (RCR) definitions  */
end_comment

begin_comment
comment|/*  * SEP: Save Errored Packets. If 0, error packets are discarded. If set to 1,  *	packets with CRC and frame errors are not discarded.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_SEP
value|0x01
end_define

begin_comment
comment|/*  * AR: Accept Runt packet. If 0, packet with less than 64 byte are discarded.  *	If set to 1, packets with less than 64 byte are not discarded.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_AR
value|0x02
end_define

begin_comment
comment|/*  * AB: Accept Broadcast. If set, packets sent to the broadcast address will be  *	accepted.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_AB
value|0x04
end_define

begin_comment
comment|/*  * AM: Accept Multicast. If set, packets sent to a multicast address are checked  *	for a match in the hashing array. If clear, multicast packets are ignored.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_AM
value|0x08
end_define

begin_comment
comment|/*  * PRO: Promiscuous Physical. If set, all packets with a physical addresses are  *	accepted. If clear, a physical destination address must match this  *	station's address. Note: for full promiscuous mode, RCR_AB and RCR_AM  *	must also be set. In addition, the multicast hashing array must be set  *	to all 1's so that all multicast addresses are accepted.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_PRO
value|0x10
end_define

begin_comment
comment|/*  * MON: Monitor Mode. If set, packets will be checked for good CRC and framing,  *	but are not stored in the ring-buffer. If clear, packets are stored (normal  *	operation).  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_MON
value|0x20
end_define

begin_comment
comment|/*  * INTT: Interrupt Trigger Mode for AX88190.  */
end_comment

begin_define
define|#
directive|define
name|ED_RCR_INTT
value|0x40
end_define

begin_comment
comment|/*  * bit 7 is unused/reserved.  */
end_comment

begin_comment
comment|/*  *		Receiver Status Register (RSR) definitions  */
end_comment

begin_comment
comment|/*  * PRX: Packet Received without error.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_PRX
value|0x01
end_define

begin_comment
comment|/*  * CRC: CRC error. Indicates that a packet has a CRC error. Also set for frame  *	alignment errors.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_CRC
value|0x02
end_define

begin_comment
comment|/*  * FAE: Frame Alignment Error. Indicates that the incoming packet did not end on  *	a byte boundary and the CRC did not match at the last byte boundary.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_FAE
value|0x04
end_define

begin_comment
comment|/*  * FO: FIFO Overrun. Indicates that the FIFO was not serviced (during local DMA)  *	causing it to overrun. Reception of the packet is aborted.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_FO
value|0x08
end_define

begin_comment
comment|/*  * MPA: Missed Packet. Indicates that the received packet couldn't be stored in  *	the ring-buffer because of insufficient buffer space (exceeding the  *	boundary pointer), or because the transfer to the ring-buffer was inhibited  *	by RCR_MON - monitor mode.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_MPA
value|0x10
end_define

begin_comment
comment|/*  * PHY: Physical address. If 0, the packet received was sent to a physical address.  *	If 1, the packet was accepted because of a multicast/broadcast address  *	match.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_PHY
value|0x20
end_define

begin_comment
comment|/*  * DIS: Receiver Disabled. Set to indicate that the receiver has entered monitor  *	mode. Cleared when the receiver exits monitor mode.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_DIS
value|0x40
end_define

begin_comment
comment|/*  * DFR: Deferring. Set to indicate a 'jabber' condition. The CRS and COL inputs  *	are active, and the transceiver has set the CD line as a result of the  *	jabber.  */
end_comment

begin_define
define|#
directive|define
name|ED_RSR_DFR
value|0x80
end_define

begin_comment
comment|/*  * receive ring descriptor  *  * The National Semiconductor DS8390 Network interface controller uses  * the following receive ring headers.  The way this works is that the  * memory on the interface card is chopped up into 256 bytes blocks.  * A contiguous portion of those blocks are marked for receive packets  * by setting start and end block #'s in the NIC.  For each packet that  * is put into the receive ring, one of these headers (4 bytes each) is  * tacked onto the front. The first byte is a copy of the receiver status  * register at the time the packet was received.  */
end_comment

begin_struct
struct|struct
name|ed_ring
block|{
name|u_char
name|rsr
decl_stmt|;
comment|/* receiver status */
name|u_char
name|next_packet
decl_stmt|;
comment|/* pointer to next packet	*/
name|u_short
name|count
decl_stmt|;
comment|/* bytes in packet (length + 4)	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  * 				Common constants  */
end_comment

begin_define
define|#
directive|define
name|ED_PAGE_SIZE
value|256
end_define

begin_comment
comment|/* Size of RAM pages in bytes */
end_comment

begin_define
define|#
directive|define
name|ED_TXBUF_SIZE
value|6
end_define

begin_comment
comment|/* Size of TX buffer in pages */
end_comment

begin_comment
comment|/*  * Vendor types  */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_WD_SMC
value|0x00
end_define

begin_comment
comment|/* Western Digital/SMC */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_3COM
value|0x01
end_define

begin_comment
comment|/* 3Com */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_NOVELL
value|0x02
end_define

begin_comment
comment|/* Novell */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_PCCARD
value|0x03
end_define

begin_comment
comment|/* PCMCIA/PCCARD */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_HP
value|0x04
end_define

begin_comment
comment|/* Hewlett Packard */
end_comment

begin_define
define|#
directive|define
name|ED_VENDOR_LINKSYS
value|0x05
end_define

begin_comment
comment|/* Linksys (Dlink) */
end_comment

begin_comment
comment|/*  * Compile-time config flags  */
end_comment

begin_comment
comment|/*  * this sets the default for enabling/disabling the transceiver  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_DISABLE_TRANCEIVER
value|0x0001
end_define

begin_comment
comment|/*  * This forces the board to be used in 8/16bit mode even if it  *	autoconfigs differently  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_8BIT_MODE
value|0x0002
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_16BIT_MODE
value|0x0004
end_define

begin_comment
comment|/*  * This disables the use of double transmit buffers.  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_NO_MULTI_BUFFERING
value|0x0008
end_define

begin_comment
comment|/*  * This forces all operations with the NIC memory to use Programmed  *	I/O (i.e. not via shared memory)  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_FORCE_PIO
value|0x0010
end_define

begin_comment
comment|/*  * These are flags describing the chip type.  */
end_comment

begin_define
define|#
directive|define
name|ED_FLAGS_TOSH_ETHER
value|0x10000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_GWETHER
value|0x20000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_AX88190
value|0x30000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_LINKSYS
value|0x80000
end_define

begin_define
define|#
directive|define
name|ED_FLAGS_GETTYPE
parameter_list|(
name|flg
parameter_list|)
value|((flg)& 0xff0000)
end_define

begin_comment
comment|/*  *		Definitions for Western digital/SMC WD80x3 series ASIC  */
end_comment

begin_comment
comment|/*  * Memory Select Register (MSR)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR
value|0
end_define

begin_comment
comment|/* next three definitions for Toshiba */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_POW
value|0x02
end_define

begin_comment
comment|/* 0 = power save, 1 = normal (R/W) */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_BSY
value|0x04
end_define

begin_comment
comment|/* gate array busy (R) */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_LEN
value|0x20
end_define

begin_comment
comment|/* data bus width, 0 = 16 bits, 				   1 = 8 bits (R/W) */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_ADDR
value|0x3f
end_define

begin_comment
comment|/* Memory decode bits 18-13 */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_MENB
value|0x40
end_define

begin_comment
comment|/* Memory enable */
end_comment

begin_define
define|#
directive|define
name|ED_WD_MSR_RST
value|0x80
end_define

begin_comment
comment|/* Reset board */
end_comment

begin_comment
comment|/*  * Interface Configuration Register (ICR)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR
value|1
end_define

begin_define
define|#
directive|define
name|ED_WD_ICR_16BIT
value|0x01
end_define

begin_comment
comment|/* 16-bit interface */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_OAR
value|0x02
end_define

begin_comment
comment|/* select register. 0=BIO 1=EAR */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_IR2
value|0x04
end_define

begin_comment
comment|/* high order bit of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_MSZ
value|0x08
end_define

begin_comment
comment|/* memory size (0=8k 1=32k) */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_RLA
value|0x10
end_define

begin_comment
comment|/* recall LAN address */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_RX7
value|0x20
end_define

begin_comment
comment|/* recall all but i/o and LAN address */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_RIO
value|0x40
end_define

begin_comment
comment|/* recall i/o address */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_STO
value|0x80
end_define

begin_comment
comment|/* store to non-volatile memory */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_MEM
value|0xe0
end_define

begin_comment
comment|/* shared mem address A15-A13 (R/W) */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ICR_MSZ1
value|0x0f
end_define

begin_comment
comment|/* memory size, 0x08 = 64K, 0x04 = 32K, 				   0x02 = 16K, 0x01 = 8K */
end_comment

begin_comment
comment|/* 64K can only be used if mem address 				   above 1Mb */
end_comment

begin_comment
comment|/* IAR holds address A23-A16 (R/W) */
end_comment

begin_comment
comment|/*  * IO Address Register (IAR)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IAR
value|2
end_define

begin_comment
comment|/*  * EEROM Address Register  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_EAR
value|3
end_define

begin_comment
comment|/*  * Interrupt Request Register (IRR)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR
value|4
end_define

begin_define
define|#
directive|define
name|ED_WD_IRR_0WS
value|0x01
end_define

begin_comment
comment|/* use 0 wait-states on 8 bit bus */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_OUT1
value|0x02
end_define

begin_comment
comment|/* WD83C584 pin 1 output */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_OUT2
value|0x04
end_define

begin_comment
comment|/* WD83C584 pin 2 output */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_OUT3
value|0x08
end_define

begin_comment
comment|/* WD83C584 pin 3 output */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_FLASH
value|0x10
end_define

begin_comment
comment|/* Flash RAM is in the ROM socket */
end_comment

begin_comment
comment|/*  * The three bits of the encoded IRQ are decoded as follows:  *  *	IR2 IR1 IR0	IRQ  *	 0   0   0	 2/9  *	 0   0   1	 3  *	 0   1   0	 5  *	 0   1   1	 7  *	 1   0   0	 10  *	 1   0   1	 11  *	 1   1   0	 15  *	 1   1   1	 4  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_IR0
value|0x20
end_define

begin_comment
comment|/* bit 0 of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_IR1
value|0x40
end_define

begin_comment
comment|/* bit 1 of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IRR_IEN
value|0x80
end_define

begin_comment
comment|/* Interrupt enable */
end_comment

begin_comment
comment|/*  * LA Address Register (LAAR)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_LAAR
value|5
end_define

begin_define
define|#
directive|define
name|ED_WD_LAAR_ADDRHI
value|0x1f
end_define

begin_comment
comment|/* bits 23-19 of RAM address */
end_comment

begin_define
define|#
directive|define
name|ED_WD_LAAR_0WS16
value|0x20
end_define

begin_comment
comment|/* enable 0 wait-states on 16 bit bus */
end_comment

begin_define
define|#
directive|define
name|ED_WD_LAAR_L16EN
value|0x40
end_define

begin_comment
comment|/* enable 16-bit operation */
end_comment

begin_define
define|#
directive|define
name|ED_WD_LAAR_M16EN
value|0x80
end_define

begin_comment
comment|/* enable 16-bit memory access */
end_comment

begin_comment
comment|/* i/o base offset to station address/card-ID PROM */
end_comment

begin_define
define|#
directive|define
name|ED_WD_PROM
value|8
end_define

begin_comment
comment|/*  *	83C790 specific registers  */
end_comment

begin_comment
comment|/*  * Hardware Support Register (HWR) ('790)  */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_HWR
value|4
end_define

begin_define
define|#
directive|define
name|WD_WD790_HWR_NUKE
value|0x10
end_define

begin_comment
comment|/* hardware reset */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_HWR_LPRM
value|0x40
end_define

begin_comment
comment|/* LAN PROM select */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_HWR_SWH
value|0x80
end_define

begin_comment
comment|/* switch register set */
end_comment

begin_comment
comment|/*  * ICR790 Interrupt Control Register for the 83C790  */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_ICR
value|6
end_define

begin_define
define|#
directive|define
name|ED_WD790_ICR_EIL
value|0x01
end_define

begin_comment
comment|/* enable interrupts */
end_comment

begin_comment
comment|/*  * REV/IOPA Revision / I/O Pipe register for the 83C79X  */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_REV
value|7
end_define

begin_define
define|#
directive|define
name|ED_WD790
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_WD795
value|0x40
end_define

begin_comment
comment|/*  * 79X RAM Address Register (RAR)  *	Enabled with SWH bit=1 in HWR register  */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_RAR
value|0x0b
end_define

begin_define
define|#
directive|define
name|ED_WD790_RAR_SZ8
value|0x00
end_define

begin_comment
comment|/* 8k memory buffer */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_RAR_SZ16
value|0x10
end_define

begin_comment
comment|/* 16k memory buffer */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_RAR_SZ32
value|0x20
end_define

begin_comment
comment|/* 32k memory buffer */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_RAR_SZ64
value|0x30
end_define

begin_comment
comment|/* 64k memory buffer */
end_comment

begin_comment
comment|/*  * General Control Register (GCR)  *	Enabled with SWH bit=1 in HWR register  */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_GCR
value|0x0d
end_define

begin_define
define|#
directive|define
name|ED_WD790_GCR_IR0
value|0x04
end_define

begin_comment
comment|/* bit 0 of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_GCR_IR1
value|0x08
end_define

begin_comment
comment|/* bit 1 of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_GCR_ZWSEN
value|0x20
end_define

begin_comment
comment|/* zero wait state enable */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_GCR_IR2
value|0x40
end_define

begin_comment
comment|/* bit 2 of encoded IRQ */
end_comment

begin_define
define|#
directive|define
name|ED_WD790_GCR_LIT
value|0x01
end_define

begin_comment
comment|/* Link Integrity Test Enable */
end_comment

begin_comment
comment|/*  * The three bits of the encoded IRQ are decoded as follows:  *  *	IR2 IR1 IR0	IRQ  *	 0   0   0	 none  *	 0   0   1	 9  *	 0   1   0	 3  *	 0   1   1	 5  *	 1   0   0	 7  *	 1   0   1	 10  *	 1   1   0	 11  *	 1   1   1	 15  */
end_comment

begin_comment
comment|/* i/o base offset to CARD ID */
end_comment

begin_define
define|#
directive|define
name|ED_WD_CARD_ID
value|ED_WD_PROM+6
end_define

begin_comment
comment|/* Board type codes in card ID */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_WD8003S
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8003E
value|0x03
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013EBT
value|0x05
end_define

begin_define
define|#
directive|define
name|ED_TYPE_TOSHIBA1
value|0x11
end_define

begin_comment
comment|/* named PCETA1 */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_TOSHIBA2
value|0x12
end_define

begin_comment
comment|/* named PCETA2 */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_TOSHIBA3
value|0x13
end_define

begin_comment
comment|/* named PCETB  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_TOSHIBA4
value|0x14
end_define

begin_comment
comment|/* named PCETC  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_WD8003W
value|0x24
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8003EB
value|0x25
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013W
value|0x26
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013EP
value|0x27
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013WC
value|0x28
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013EPC
value|0x29
end_define

begin_define
define|#
directive|define
name|ED_TYPE_SMC8216T
value|0x2a
end_define

begin_define
define|#
directive|define
name|ED_TYPE_SMC8216C
value|0x2b
end_define

begin_define
define|#
directive|define
name|ED_TYPE_WD8013EBP
value|0x2c
end_define

begin_comment
comment|/* Bit definitions in card ID */
end_comment

begin_define
define|#
directive|define
name|ED_WD_REV_MASK
value|0x1f
end_define

begin_comment
comment|/* Revision mask */
end_comment

begin_define
define|#
directive|define
name|ED_WD_SOFTCONFIG
value|0x20
end_define

begin_comment
comment|/* Soft config */
end_comment

begin_define
define|#
directive|define
name|ED_WD_LARGERAM
value|0x40
end_define

begin_comment
comment|/* Large RAM */
end_comment

begin_define
define|#
directive|define
name|ED_MICROCHANEL
value|0x80
end_define

begin_comment
comment|/* Microchannel bus (vs. isa) */
end_comment

begin_comment
comment|/*  * Checksum total. All 8 bytes in station address PROM will add up to this  */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ROM_CHECKSUM_TOTAL
value|0xFF
end_define

begin_define
define|#
directive|define
name|ED_WD_ROM_CHECKSUM_TOTAL_TOSH_ETHER
value|0xA5
end_define

begin_define
define|#
directive|define
name|ED_WD_NIC_OFFSET
value|0x10
end_define

begin_comment
comment|/* I/O base offset to NIC */
end_comment

begin_define
define|#
directive|define
name|ED_WD_ASIC_OFFSET
value|0
end_define

begin_comment
comment|/* I/O base offset to ASIC */
end_comment

begin_define
define|#
directive|define
name|ED_WD_IO_PORTS
value|32
end_define

begin_comment
comment|/* # of i/o addresses used */
end_comment

begin_define
define|#
directive|define
name|ED_WD_PAGE_OFFSET
value|0
end_define

begin_comment
comment|/* page offset for NIC access to mem */
end_comment

begin_comment
comment|/*  *			Definitions for 3Com 3c503  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_NIC_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|ED_3COM_ASIC_OFFSET
value|0x400
end_define

begin_comment
comment|/* offset to nic i/o regs */
end_comment

begin_comment
comment|/*  * XXX - The I/O address range is fragmented in the 3c503; this is the  *	number of regs at iobase.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IO_PORTS
value|16
end_define

begin_comment
comment|/* # of i/o addresses used */
end_comment

begin_comment
comment|/* tx memory starts in second bank on 8bit cards */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_TX_PAGE_OFFSET_8BIT
value|0x20
end_define

begin_comment
comment|/* tx memory starts in first bank on 16bit cards */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_TX_PAGE_OFFSET_16BIT
value|0x0
end_define

begin_comment
comment|/* ...and rx memory starts in second bank */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_RX_PAGE_OFFSET_16BIT
value|0x20
end_define

begin_comment
comment|/*  *	Page Start Register. Must match PSTART in NIC  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_PSTR
value|0
end_define

begin_comment
comment|/*  *	Page Stop Register. Must match PSTOP in NIC  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_PSPR
value|1
end_define

begin_comment
comment|/*  *	Drq Timer Register. Determines number of bytes to be transfered during  *		a DMA burst.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_DQTR
value|2
end_define

begin_comment
comment|/*  *	Base Configuration Register. Read-only register which contains the  *		board-configured I/O base address of the adapter. Bit encoded.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_BCFR
value|3
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_2E0
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_2A0
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_280
value|0x04
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_250
value|0x08
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_350
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_330
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_310
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_3COM_BCFR_300
value|0x80
end_define

begin_comment
comment|/*  *	EPROM Configuration Register. Read-only register which contains the  *		board-configured memory base address. Bit encoded.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_PCFR
value|4
end_define

begin_define
define|#
directive|define
name|ED_3COM_PCFR_C8000
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_3COM_PCFR_CC000
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_3COM_PCFR_D8000
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_3COM_PCFR_DC000
value|0x80
end_define

begin_comment
comment|/*  *	GA Configuration Register. Gate-Array Configuration Register.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR
value|5
end_define

begin_comment
comment|/*  * mbs2  mbs1  mbs0		start address  *  0     0     0		0x0000  *  0     0     1		0x2000  *  0     1     0		0x4000  *  0     1     1		0x6000  *  *	Note that with adapters with only 8K, the setting for 0x2000 must  *		always be used.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR_MBS0
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_3COM_GACFR_MBS1
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_3COM_GACFR_MBS2
value|0x04
end_define

begin_define
define|#
directive|define
name|ED_3COM_GACFR_RSEL
value|0x08
end_define

begin_comment
comment|/* enable shared memory */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR_TEST
value|0x10
end_define

begin_comment
comment|/* for GA testing */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR_OWS
value|0x20
end_define

begin_comment
comment|/* select 0WS access to GA */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR_TCM
value|0x40
end_define

begin_comment
comment|/* Mask DMA interrupts */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_GACFR_NIM
value|0x80
end_define

begin_comment
comment|/* Mask NIC interrupts */
end_comment

begin_comment
comment|/*  *	Control Register. Miscellaneous control functions.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR
value|6
end_define

begin_define
define|#
directive|define
name|ED_3COM_CR_RST
value|0x01
end_define

begin_comment
comment|/* Reset GA and NIC */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_XSEL
value|0x02
end_define

begin_comment
comment|/* Transceiver select. BNC=1(def) AUI=0 */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_EALO
value|0x04
end_define

begin_comment
comment|/* window EA PROM 0-15 to I/O base */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_EAHI
value|0x08
end_define

begin_comment
comment|/* window EA PROM 16-31 to I/O base */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_SHARE
value|0x10
end_define

begin_comment
comment|/* select interrupt sharing option */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_DBSEL
value|0x20
end_define

begin_comment
comment|/* Double buffer select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_DDIR
value|0x40
end_define

begin_comment
comment|/* DMA direction select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_CR_START
value|0x80
end_define

begin_comment
comment|/* Start DMA controller */
end_comment

begin_comment
comment|/*  *	Status Register. Miscellaneous status information.  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG
value|7
end_define

begin_define
define|#
directive|define
name|ED_3COM_STREG_REV
value|0x07
end_define

begin_comment
comment|/* GA revision */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG_DIP
value|0x08
end_define

begin_comment
comment|/* DMA in progress */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG_DTC
value|0x10
end_define

begin_comment
comment|/* DMA terminal count */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG_OFLW
value|0x20
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG_UFLW
value|0x40
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_STREG_DPRDY
value|0x80
end_define

begin_comment
comment|/* Data port ready */
end_comment

begin_comment
comment|/*  *	Interrupt/DMA Configuration Register  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR
value|8
end_define

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_DRQ0
value|0x01
end_define

begin_comment
comment|/* DMA request 1 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_DRQ1
value|0x02
end_define

begin_comment
comment|/* DMA request 2 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_DRQ2
value|0x04
end_define

begin_comment
comment|/* DMA request 3 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_UNUSED
value|0x08
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_IRQ2
value|0x10
end_define

begin_comment
comment|/* Interrupt request 2 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_IRQ3
value|0x20
end_define

begin_comment
comment|/* Interrupt request 3 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_IRQ4
value|0x40
end_define

begin_comment
comment|/* Interrupt request 4 select */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_IDCFR_IRQ5
value|0x80
end_define

begin_comment
comment|/* Interrupt request 5 select */
end_comment

begin_comment
comment|/*  *	DMA Address Register MSB  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_DAMSB
value|9
end_define

begin_comment
comment|/*  *	DMA Address Register LSB  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_DALSB
value|0x0a
end_define

begin_comment
comment|/*  *	Vector Pointer Register 2  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_VPTR2
value|0x0b
end_define

begin_comment
comment|/*  *	Vector Pointer Register 1  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_VPTR1
value|0x0c
end_define

begin_comment
comment|/*  *	Vector Pointer Register 0  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_VPTR0
value|0x0d
end_define

begin_comment
comment|/*  *	Register File Access MSB  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_RFMSB
value|0x0e
end_define

begin_comment
comment|/*  *	Register File Access LSB  */
end_comment

begin_define
define|#
directive|define
name|ED_3COM_RFLSB
value|0x0f
end_define

begin_comment
comment|/*  *		 Definitions for Novell NE1000/2000 boards  */
end_comment

begin_comment
comment|/*  * Board type codes  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_NE1000
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_TYPE_NE2000
value|0x02
end_define

begin_comment
comment|/*  * Register offsets/total  */
end_comment

begin_define
define|#
directive|define
name|ED_NOVELL_NIC_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|ED_NOVELL_ASIC_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_NOVELL_IO_PORTS
value|32
end_define

begin_comment
comment|/*  * Remote DMA data register; for reading or writing to the NIC mem  *	via programmed I/O (offset from ASIC base)  */
end_comment

begin_define
define|#
directive|define
name|ED_NOVELL_DATA
value|0x00
end_define

begin_comment
comment|/*  * Reset register; reading from this register causes a board reset  */
end_comment

begin_define
define|#
directive|define
name|ED_NOVELL_RESET
value|0x0f
end_define

begin_comment
comment|/*  *		Definitions for PCCARD  */
end_comment

begin_define
define|#
directive|define
name|ED_PC_PAGE_OFFSET
value|0x40
end_define

begin_comment
comment|/* page offset for NIC access to mem */
end_comment

begin_define
define|#
directive|define
name|ED_PC_IO_PORTS
value|32
end_define

begin_define
define|#
directive|define
name|ED_PC_ASIC_OFFSET
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_PC_RESET
value|0x0f
end_define

begin_comment
comment|/* Reset(offset from ASIC base) */
end_comment

begin_define
define|#
directive|define
name|ED_PC_MISC
value|0x08
end_define

begin_comment
comment|/* Misc (offset from ASIC base) */
end_comment

begin_comment
comment|/*   * if_ze.h  constants  */
end_comment

begin_define
define|#
directive|define
name|ZE_PAGE_OFFSET
value|0x40
end_define

begin_comment
comment|/* mem buffer starts at 0x4000 */
end_comment

begin_define
define|#
directive|define
name|ZE_DATA_IO
value|0x10
end_define

begin_define
define|#
directive|define
name|ZE_MISC
value|0x18
end_define

begin_define
define|#
directive|define
name|ZE_RESET
value|0x1F
end_define

begin_comment
comment|/*  * Definitions for HP PC LAN Adapter Plus; based on the CRYNWR packet  * driver for the card.  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ASIC_OFFSET
value|0x00
end_define

begin_comment
comment|/* Offset to ASIC registers */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_NIC_OFFSET
value|0x10
end_define

begin_comment
comment|/* Offset to 8390 registers */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ID
value|0x00
end_define

begin_comment
comment|/* ID register, always 0x4850 */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGING
value|0x02
end_define

begin_comment
comment|/* Page select register */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_OPTION
value|0x04
end_define

begin_comment
comment|/* Bitmask of supported options */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_0
value|0x08
end_define

begin_comment
comment|/* Page 0 */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_2
value|0x0A
end_define

begin_comment
comment|/* Page 2 */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_4
value|0x0C
end_define

begin_comment
comment|/* Page 4 */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_6
value|0x0E
end_define

begin_comment
comment|/* Page 6 */
end_comment

begin_comment
comment|/* PERF PAGE */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_OUT_ADDR
value|ED_HPP_PAGE_0
end_define

begin_comment
comment|/* I/O output location */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_IN_ADDR
value|ED_HPP_PAGE_2
end_define

begin_comment
comment|/* I/O input location */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_DATAPORT
value|ED_HPP_PAGE_4
end_define

begin_comment
comment|/* I/O data transfer */
end_comment

begin_comment
comment|/* MAC PAGE */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_MAC_ADDR
value|0x08
end_define

begin_comment
comment|/* Offset of MAC address in MAC page */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_IO_PORTS
value|32
end_define

begin_comment
comment|/* Number of IO ports */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_TX_PAGE_OFFSET
value|0x00
end_define

begin_comment
comment|/* first page of TX buffer */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_RX_PAGE_START
value|0x06
end_define

begin_comment
comment|/* start at page 6 */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_RX_PAGE_STOP
value|0x80
end_define

begin_comment
comment|/* end at page 128 */
end_comment

begin_comment
comment|/*  * Register pages supported.  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_PERF
value|0
end_define

begin_comment
comment|/* Normal operation */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_MAC
value|1
end_define

begin_comment
comment|/* The ethernet address and checksum */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_HW
value|2
end_define

begin_comment
comment|/* Hardware parameters in EEPROM */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_LAN
value|4
end_define

begin_comment
comment|/* Transciever selection etc */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_PAGE_ID
value|6
end_define

begin_comment
comment|/* ID */
end_comment

begin_comment
comment|/*  * Options supported.  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_OPTION_NIC_RESET
value|0x0001
end_define

begin_comment
comment|/* active low */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_OPTION_CHIP_RESET
value|0x0002
end_define

begin_comment
comment|/* active low */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_OPTION_ENABLE_IRQ
value|0x0004
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_FAKE_INTR
value|0x0008
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_BOOT_ROM_ENB
value|0x0010
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_IO_ENB
value|0x0020
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_MEM_ENABLE
value|0x0040
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_ZERO_WAIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|ED_HPP_OPTION_MEM_DISABLE
value|0x1000
end_define

begin_comment
comment|/*  * Page ID configuration.  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ID_REVISION_MASK
value|0x0300
end_define

begin_comment
comment|/* revision id */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ID_SOFT_MODEL_MASK
value|0xFC00
end_define

begin_comment
comment|/* soft model number */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ID_16_BIT_ACCESS
value|0x0010
end_define

begin_comment
comment|/* if set use 16 bit accesses */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_ID_TWISTED_PAIR
value|0x0040
end_define

begin_comment
comment|/*  * Hardware configuration.  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_HW_MEM_MAP
value|0x09
end_define

begin_comment
comment|/* low mem map location in HW page */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_HW_ID
value|0x0C
end_define

begin_comment
comment|/* revision number, capabilities */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_HW_IRQ
value|0x0D
end_define

begin_comment
comment|/* IRQ channel register in HW page */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_HW_WRAP
value|0x0E
end_define

begin_comment
comment|/* mem wrap page for rcv */
end_comment

begin_comment
comment|/*  * Lan configuration  */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_LAN_AUI
value|0x01
end_define

begin_comment
comment|/* Use AUI */
end_comment

begin_define
define|#
directive|define
name|ED_HPP_LAN_TL
value|0x40
end_define

begin_comment
comment|/* Don't use AUI */
end_comment

begin_comment
comment|/*  * Card types.  */
end_comment

begin_define
define|#
directive|define
name|ED_TYPE_HP_PCLANPLUS
value|0x00
end_define

begin_comment
comment|/*  * Chip types.  */
end_comment

begin_define
define|#
directive|define
name|ED_CHIP_TYPE_DP8390
value|0x00
end_define

begin_define
define|#
directive|define
name|ED_CHIP_TYPE_WD790
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_CHIP_TYPE_AX88190
value|0x02
end_define

begin_comment
comment|/*  * AX88190 IOBASE registers.  */
end_comment

begin_define
define|#
directive|define
name|ED_AX88190_IOBASE0
value|0x3ca
end_define

begin_define
define|#
directive|define
name|ED_AX88190_IOBASE1
value|0x3cc
end_define

begin_comment
comment|/*  * MII bus definitions.  */
end_comment

begin_define
define|#
directive|define
name|ED_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|ED_MII_IDLE
value|0x01
end_define

begin_define
define|#
directive|define
name|ED_MII_STARTDELIM_BITS
value|2
end_define

begin_define
define|#
directive|define
name|ED_MII_OP_BITS
value|2
end_define

begin_define
define|#
directive|define
name|ED_MII_PHY_BITS
value|5
end_define

begin_define
define|#
directive|define
name|ED_MII_REG_BITS
value|5
end_define

begin_define
define|#
directive|define
name|ED_MII_TURNAROUND_BITS
value|2
end_define

begin_define
define|#
directive|define
name|ED_MII_DATA_BITS
value|16
end_define

begin_define
define|#
directive|define
name|ED_MII_ACK_BITS
value|1
end_define

begin_define
define|#
directive|define
name|ED_MII_IDLE_BITS
value|1
end_define

begin_comment
comment|/* Dlink chipset used on some Netgear and Dlink PCMCIA cards */
end_comment

begin_define
define|#
directive|define
name|ED_DLINK_MIIBUS
value|0x0c
end_define

begin_comment
comment|/* MII bus register on ASIC */
end_comment

begin_define
define|#
directive|define
name|ED_DLINK_MII_RESET1
value|0x04
end_define

begin_define
define|#
directive|define
name|ED_DLINK_MII_RESET2
value|0x08
end_define

begin_define
define|#
directive|define
name|ED_DLINK_MII_DATATIN
value|0x10
end_define

begin_define
define|#
directive|define
name|ED_DLINK_MII_DIROUT
value|0x20
end_define

begin_define
define|#
directive|define
name|ED_DLINK_MII_DATAOUT
value|0x40
end_define

begin_define
define|#
directive|define
name|ED_DLINK_MII_CLK
value|0x80
end_define

end_unit

