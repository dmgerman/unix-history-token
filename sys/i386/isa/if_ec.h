begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Tim L. Tucker.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * A lot of this was derived from if_wereg.h and 3c503.asm.  */
end_comment

begin_comment
comment|/*  * receive ring discriptor  *  * The National Semiconductor DS8390 Network interface controller uses  * the following receive ring headers.  The way this works is that the  * memory on the interface card is chopped up into 256 bytes blocks.  * A contiguous portion of those blocks are marked for receive packets  * by setting start and end block #'s in the NIC.  For each packet that  * is put into the receive ring, one of these headers (4 bytes each) is  * tacked onto the front.  */
end_comment

begin_struct
struct|struct
name|ec_ring
block|{
struct|struct
name|ecr_status
block|{
comment|/* received packet status	*/
name|u_char
name|rs_prx
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_crc
range|:
literal|1
decl_stmt|,
comment|/* crc error		*/
name|rs_fae
range|:
literal|1
decl_stmt|,
comment|/* frame alignment error	*/
name|rs_fo
range|:
literal|1
decl_stmt|,
comment|/* fifo overrun		*/
name|rs_mpa
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_phy
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_dis
range|:
literal|1
decl_stmt|,
comment|/* packet received intack	*/
name|rs_dfr
range|:
literal|1
decl_stmt|;
comment|/* packet received intack	*/
block|}
name|ec_rcv_status
struct|;
comment|/* received packet status	*/
name|u_char
name|ec_next_packet
decl_stmt|;
comment|/* pointer to next packet	*/
name|u_short
name|ec_count
decl_stmt|;
comment|/* bytes in packet (length + 4)	*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EC_PAGE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|EC_TXBUF_SIZE
value|0x06
end_define

begin_define
define|#
directive|define
name|EC_VMEM_OFFSET
value|0x20
end_define

begin_define
define|#
directive|define
name|EC_RXBUF_OFFSET
value|0x26
end_define

begin_define
define|#
directive|define
name|EC_RXBUF_END
value|0x40
end_define

begin_define
define|#
directive|define
name|EC_ROM_OFFSET
value|8
end_define

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_define
define|#
directive|define
name|ETHER_HDR_SIZE
value|14
end_define

begin_comment
comment|/*  * Share memory management parameters.  */
end_comment

begin_define
define|#
directive|define
name|XMIT_MTU
value|0x600
end_define

begin_define
define|#
directive|define
name|SM_TSTART_PG
value|0x020
end_define

begin_define
define|#
directive|define
name|SM_RSTART_PG
value|0x026
end_define

begin_define
define|#
directive|define
name|SM_RSTOP_PG
value|0x040
end_define

begin_comment
comment|/*  * Description of header of each packet in receive area of shared memory.  */
end_comment

begin_define
define|#
directive|define
name|EN_RBUF_STAT
value|0x0
end_define

begin_comment
comment|/* Received frame status. */
end_comment

begin_define
define|#
directive|define
name|EN_RBUF_NXT_PG
value|0x1
end_define

begin_comment
comment|/* Page after this frame */
end_comment

begin_define
define|#
directive|define
name|EN_RBUF_SIZE_LO
value|0x2
end_define

begin_comment
comment|/* Length of this frame */
end_comment

begin_define
define|#
directive|define
name|EN_RBUF_SIZE_HI
value|0x3
end_define

begin_comment
comment|/* Length of this frame */
end_comment

begin_define
define|#
directive|define
name|EN_RBUF_NHDR
value|0x4
end_define

begin_comment
comment|/* Length of above header area */
end_comment

begin_comment
comment|/*  * E33 Control registers. (base + 40x)  */
end_comment

begin_define
define|#
directive|define
name|E33G
value|0x0
end_define

begin_define
define|#
directive|define
name|E33G_STARTPG
value|0x0
end_define

begin_define
define|#
directive|define
name|E33G_STOPPG
value|0x1
end_define

begin_define
define|#
directive|define
name|E33G_NBURST
value|0x2
end_define

begin_define
define|#
directive|define
name|E33G_IOBASE
value|0x3
end_define

begin_define
define|#
directive|define
name|E33G_ROMBASE
value|0x4
end_define

begin_define
define|#
directive|define
name|E33G_GACFR
value|0x5
end_define

begin_define
define|#
directive|define
name|E33G_CNTRL
value|0x6
end_define

begin_define
define|#
directive|define
name|E33G_STATUS
value|0x7
end_define

begin_define
define|#
directive|define
name|E33G_IDCFR
value|0x8
end_define

begin_define
define|#
directive|define
name|E33G_DMAAH
value|0x9
end_define

begin_define
define|#
directive|define
name|E33G_DMAAL
value|0xa
end_define

begin_define
define|#
directive|define
name|E33G_VP2
value|0xb
end_define

begin_define
define|#
directive|define
name|E33G_VP1
value|0xc
end_define

begin_define
define|#
directive|define
name|E33G_VP0
value|0xd
end_define

begin_define
define|#
directive|define
name|E33G_FIFOH
value|0xe
end_define

begin_define
define|#
directive|define
name|E33G_FIFOL
value|0xf
end_define

begin_comment
comment|/*  * Bits in E33G_GACFR register.  */
end_comment

begin_define
define|#
directive|define
name|EGACFR_NORM
value|0x49
end_define

begin_define
define|#
directive|define
name|EGACFR_IRQOFF
value|0xc9
end_define

begin_comment
comment|/*  *  Control bits for E33G_CNTRL  */
end_comment

begin_define
define|#
directive|define
name|ECNTRL_RESET
value|0x01
end_define

begin_comment
comment|/* Software reset of ASIC and 8390. */
end_comment

begin_define
define|#
directive|define
name|ECNTRL_THIN
value|0x02
end_define

begin_comment
comment|/* Enable thinnet interface. */
end_comment

begin_define
define|#
directive|define
name|ECNTRL_SAPROM
value|0x04
end_define

begin_comment
comment|/* Map Address Prom.         */
end_comment

begin_define
define|#
directive|define
name|ECNTRL_DBLBFR
value|0x20
end_define

begin_comment
comment|/* FIFO Configuration bit    */
end_comment

begin_define
define|#
directive|define
name|ECNTRL_OUTPUT
value|0x40
end_define

begin_comment
comment|/* PC->3c503 direction if set*/
end_comment

begin_define
define|#
directive|define
name|ECNTRL_START
value|0x80
end_define

begin_comment
comment|/* Start DMA Logic.          */
end_comment

begin_comment
comment|/*  * Bits in E33G status register.  */
end_comment

begin_define
define|#
directive|define
name|ESTAT_DPRDY
value|0x80
end_define

begin_comment
comment|/* Data port of FIFO ready */
end_comment

begin_define
define|#
directive|define
name|ESTAT_UFLW
value|0x40
end_define

begin_comment
comment|/* Tried to read FIFO when it was empty. */
end_comment

begin_define
define|#
directive|define
name|ESTAT_OFLW
value|0x20
end_define

begin_comment
comment|/* Tried to write FIFO when it was full */
end_comment

begin_define
define|#
directive|define
name|ESTAT_DTC
value|0x10
end_define

begin_comment
comment|/* Terminal count from PC bus DMA Logic */
end_comment

begin_define
define|#
directive|define
name|ESTAT_DIP
value|0x8
end_define

begin_comment
comment|/* DMA in progress */
end_comment

begin_comment
comment|/*  * 8390 chip registers.  */
end_comment

begin_define
define|#
directive|define
name|EN_CCMD
value|0x0
end_define

begin_comment
comment|/* Chip's command register. */
end_comment

begin_define
define|#
directive|define
name|EN0_STARTPG
value|0x1
end_define

begin_comment
comment|/* Starting page of ring buffer. */
end_comment

begin_define
define|#
directive|define
name|EN0_STOPPG
value|0x2
end_define

begin_comment
comment|/* Ending page + 1 of ring buffer */
end_comment

begin_define
define|#
directive|define
name|EN0_BOUNDARY
value|0x3
end_define

begin_comment
comment|/* Boundary page of ring buffer */
end_comment

begin_define
define|#
directive|define
name|EN0_TSR
value|0x4
end_define

begin_comment
comment|/* Transmit status register. */
end_comment

begin_define
define|#
directive|define
name|EN0_TPSR
value|0x4
end_define

begin_comment
comment|/* Transmit starting page. */
end_comment

begin_define
define|#
directive|define
name|EN0_TCNTLO
value|0x5
end_define

begin_comment
comment|/* Low byte of tx byte count */
end_comment

begin_define
define|#
directive|define
name|EN0_TCNTHI
value|0x6
end_define

begin_comment
comment|/* High byte of tx byte count */
end_comment

begin_define
define|#
directive|define
name|EN0_ISR
value|0x7
end_define

begin_comment
comment|/* Interrupt status register. */
end_comment

begin_define
define|#
directive|define
name|EN0_RSARLO
value|0x8
end_define

begin_comment
comment|/* Remote start address reg 0 */
end_comment

begin_define
define|#
directive|define
name|EN0_RSARHI
value|0x9
end_define

begin_comment
comment|/* Remote start address reg 1 */
end_comment

begin_define
define|#
directive|define
name|EN0_RCNTLO
value|0xa
end_define

begin_comment
comment|/* Remote byte count reg */
end_comment

begin_define
define|#
directive|define
name|EN0_RCNTHI
value|0xb
end_define

begin_comment
comment|/* Remote byte count reg */
end_comment

begin_define
define|#
directive|define
name|EN0_RXCR
value|0xc
end_define

begin_comment
comment|/* RX Control reg */
end_comment

begin_define
define|#
directive|define
name|EN0_TXCR
value|0xd
end_define

begin_comment
comment|/* TX Control reg */
end_comment

begin_define
define|#
directive|define
name|EN0_COUNTER0
value|0xd
end_define

begin_comment
comment|/* Rcv alignment error counter */
end_comment

begin_define
define|#
directive|define
name|EN0_DCFG
value|0xe
end_define

begin_comment
comment|/* Data configuration reg */
end_comment

begin_define
define|#
directive|define
name|EN0_COUNTER1
value|0xe
end_define

begin_comment
comment|/* rcv CRC error counter */
end_comment

begin_define
define|#
directive|define
name|EN0_IMR
value|0xf
end_define

begin_comment
comment|/* Interrupt mask reg */
end_comment

begin_define
define|#
directive|define
name|EN0_COUNTER2
value|0xf
end_define

begin_comment
comment|/* rcv missed frame error counter */
end_comment

begin_define
define|#
directive|define
name|EN1_PHYS
value|0x1
end_define

begin_comment
comment|/* boards physical enet addr. */
end_comment

begin_define
define|#
directive|define
name|EN1_CURPAG
value|0x7
end_define

begin_comment
comment|/* current memory page. */
end_comment

begin_define
define|#
directive|define
name|EN1_MULT
value|0x8
end_define

begin_comment
comment|/* multicast filter mask array (8 bytes) */
end_comment

begin_comment
comment|/*  * Chip commands in EN_CCMD  */
end_comment

begin_define
define|#
directive|define
name|ENC_STOP
value|0x1
end_define

begin_comment
comment|/* Stop the chip. */
end_comment

begin_define
define|#
directive|define
name|ENC_START
value|0x2
end_define

begin_comment
comment|/* Start the chip */
end_comment

begin_define
define|#
directive|define
name|ENC_TRANS
value|0x4
end_define

begin_comment
comment|/* Transmit a frame. */
end_comment

begin_define
define|#
directive|define
name|ENC_RREAD
value|0x8
end_define

begin_comment
comment|/* Remote read. */
end_comment

begin_define
define|#
directive|define
name|ENC_RWRITE
value|0x10
end_define

begin_comment
comment|/* Remote write */
end_comment

begin_define
define|#
directive|define
name|ENC_NODMA
value|0x20
end_define

begin_comment
comment|/* No remote DMA used on this card */
end_comment

begin_define
define|#
directive|define
name|ENC_PAGE0
value|0x0
end_define

begin_comment
comment|/* Select page 0 of chip regs */
end_comment

begin_define
define|#
directive|define
name|ENC_PAGE1
value|0x40
end_define

begin_comment
comment|/* Select page 1 of chip regs */
end_comment

begin_comment
comment|/*  * Commands for RX control reg  */
end_comment

begin_define
define|#
directive|define
name|ENRXCR_MON
value|0x20
end_define

begin_comment
comment|/* Monitor mode (no packets rcvd) */
end_comment

begin_define
define|#
directive|define
name|ENRXCR_PROMP
value|0x10
end_define

begin_comment
comment|/* Promiscuous phys addresses. */
end_comment

begin_define
define|#
directive|define
name|ENRXCR_MULTI
value|0x8
end_define

begin_comment
comment|/* Multicast (if pass filter) */
end_comment

begin_define
define|#
directive|define
name|ENRXCR_BCST
value|0x4
end_define

begin_comment
comment|/* Accept broadcasts */
end_comment

begin_define
define|#
directive|define
name|ENRXCR_BAD
value|0x3
end_define

begin_comment
comment|/* Accept runts and bad CRC frames */
end_comment

begin_comment
comment|/*  * Commands for TX control reg  */
end_comment

begin_define
define|#
directive|define
name|ENTXCR_LOOP
value|0x2
end_define

begin_comment
comment|/* Set loopback mode */
end_comment

begin_comment
comment|/*  * bits on the EN0_DCFG config register.  */
end_comment

begin_define
define|#
directive|define
name|ENDCFG_BM8
value|0x48
end_define

begin_comment
comment|/* Set bust mode, 8 deep FIFO */
end_comment

begin_comment
comment|/*  * Bits in the EN0_ISR Interrup Status Register  */
end_comment

begin_define
define|#
directive|define
name|ENISR_RX
value|0x1
end_define

begin_comment
comment|/* receiver, no error */
end_comment

begin_define
define|#
directive|define
name|ENISR_TX
value|0x2
end_define

begin_comment
comment|/* transmitter, no error */
end_comment

begin_define
define|#
directive|define
name|ENISR_RX_ERR
value|0x4
end_define

begin_comment
comment|/* Receiver with error */
end_comment

begin_define
define|#
directive|define
name|ENISR_TX_ERR
value|0x8
end_define

begin_comment
comment|/* Transmitter with error */
end_comment

begin_define
define|#
directive|define
name|ENISR_OVER
value|0x10
end_define

begin_comment
comment|/* receiver overwrote the ring */
end_comment

begin_define
define|#
directive|define
name|ENISR_COUNTERS
value|0x20
end_define

begin_comment
comment|/* Counters need emptying. */
end_comment

begin_define
define|#
directive|define
name|ENISR_RDC
value|0x40
end_define

begin_comment
comment|/* Remote DMA complete. */
end_comment

begin_define
define|#
directive|define
name|ENISR_RESET
value|0x80
end_define

begin_comment
comment|/* Reset completed */
end_comment

begin_define
define|#
directive|define
name|ENISR_ALL
value|0x3f
end_define

begin_comment
comment|/* Interrupts we will enable */
end_comment

begin_comment
comment|/*  *  Bits in received packet status byte and EN0_RSR  */
end_comment

begin_define
define|#
directive|define
name|ENPS_RXOK
value|0x1
end_define

begin_comment
comment|/* received a good packet */
end_comment

begin_comment
comment|/*  * Bits in TX status reg.  */
end_comment

begin_define
define|#
directive|define
name|ENTSR_PTX
value|0x1
end_define

begin_comment
comment|/* Packet transmitted without error */
end_comment

begin_define
define|#
directive|define
name|ENTSR_COLL
value|0x4
end_define

begin_comment
comment|/* Collided at least once */
end_comment

begin_define
define|#
directive|define
name|ENTSR_COLL16
value|0x8
end_define

begin_comment
comment|/* Collided 16 times and was dropped */
end_comment

begin_define
define|#
directive|define
name|ENTSR_FU
value|0x20
end_define

begin_comment
comment|/* TX FIFO Underrun */
end_comment

end_unit

