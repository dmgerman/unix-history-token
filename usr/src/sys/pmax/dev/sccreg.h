begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * %sccs.include.redist.c%  *  *	@(#)sccreg.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1991,1990,1989 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  * Definitions for Intel 82530 serial communications chip.  * Each chip is a dual uart with the A channels used for the keyboard and  * mouse with the B channel(s) for comm ports with modem control. Since  * some registers are used for the other channel, the following macros  * are used to access the register ports.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Channel B is first, then A */
struct|struct
block|{
name|char
name|scc_pad0
decl_stmt|;
specifier|volatile
name|u_char
name|scc_command
decl_stmt|;
comment|/* reg select */
name|char
name|scc_pad1
index|[
literal|3
index|]
decl_stmt|;
specifier|volatile
name|u_char
name|scc_data
decl_stmt|;
comment|/* Rx/Tx buffer */
name|char
name|scc_pad3
index|[
literal|2
index|]
decl_stmt|;
block|}
name|scc_channel
index|[
literal|2
index|]
struct|;
block|}
name|scc_regmap_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SCC_CHANNEL_A
value|1
end_define

begin_define
define|#
directive|define
name|SCC_CHANNEL_B
value|0
end_define

begin_define
define|#
directive|define
name|SCC_INIT_REG
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|)
value|{ \ 		char tmp; \ 		tmp = (scc)->scc_channel[(chan)].scc_command; \ 		tmp = (scc)->scc_channel[(chan)].scc_command; \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_READ_REG
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(scc)->scc_channel[(chan)].scc_command = (reg); \ 		(val) = (scc)->scc_channel[(chan)].scc_command; \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_READ_REG_ZERO
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(val) = (scc)->scc_channel[(chan)].scc_command; \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_WRITE_REG
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(scc)->scc_channel[(chan)].scc_command = (reg); \ 		(scc)->scc_channel[(chan)].scc_command = (val); \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_WRITE_REG_ZERO
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(scc)->scc_channel[(chan)].scc_command = (val); \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_READ_DATA
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(val) = (scc)->scc_channel[(chan)].scc_data; \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_WRITE_DATA
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		(scc)->scc_channel[(chan)].scc_data = (val); \ 	}
end_define

begin_define
define|#
directive|define
name|SCC_RR0
value|0
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1
value|1
end_define

begin_comment
comment|/* special receive conditions */
end_comment

begin_define
define|#
directive|define
name|SCC_RR2
value|2
end_define

begin_comment
comment|/* (modified) interrupt vector */
end_comment

begin_define
define|#
directive|define
name|SCC_RR3
value|3
end_define

begin_comment
comment|/* interrupts pending (cha A only) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR8
value|8
end_define

begin_comment
comment|/* recv buffer (alias for data) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR10
value|10
end_define

begin_comment
comment|/* sdlc status */
end_comment

begin_define
define|#
directive|define
name|SCC_RR12
value|12
end_define

begin_comment
comment|/* BRG constant, low part */
end_comment

begin_define
define|#
directive|define
name|SCC_RR13
value|13
end_define

begin_comment
comment|/* BRG constant, high part */
end_comment

begin_define
define|#
directive|define
name|SCC_RR15
value|15
end_define

begin_comment
comment|/* interrupts currently enabled */
end_comment

begin_define
define|#
directive|define
name|SCC_WR0
value|0
end_define

begin_comment
comment|/* reg select, and commands */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1
value|1
end_define

begin_comment
comment|/* interrupt and DMA enables */
end_comment

begin_define
define|#
directive|define
name|SCC_WR2
value|2
end_define

begin_comment
comment|/* interrupt vector */
end_comment

begin_define
define|#
directive|define
name|SCC_WR3
value|3
end_define

begin_comment
comment|/* receiver params and enables */
end_comment

begin_define
define|#
directive|define
name|SCC_WR4
value|4
end_define

begin_comment
comment|/* clock/char/parity params */
end_comment

begin_define
define|#
directive|define
name|SCC_WR5
value|5
end_define

begin_comment
comment|/* xmit params and enables */
end_comment

begin_define
define|#
directive|define
name|SCC_WR6
value|6
end_define

begin_comment
comment|/* synchr SYNCH/address */
end_comment

begin_define
define|#
directive|define
name|SCC_WR7
value|7
end_define

begin_comment
comment|/* synchr SYNCH/flag */
end_comment

begin_define
define|#
directive|define
name|SCC_WR8
value|8
end_define

begin_comment
comment|/* xmit buffer (alias for data) */
end_comment

begin_define
define|#
directive|define
name|SCC_WR9
value|9
end_define

begin_comment
comment|/* vectoring and resets */
end_comment

begin_define
define|#
directive|define
name|SCC_WR10
value|10
end_define

begin_comment
comment|/* synchr params */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11
value|11
end_define

begin_comment
comment|/* clocking definitions */
end_comment

begin_define
define|#
directive|define
name|SCC_WR12
value|12
end_define

begin_comment
comment|/* BRG constant, low part */
end_comment

begin_define
define|#
directive|define
name|SCC_WR13
value|13
end_define

begin_comment
comment|/* BRG constant, high part */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14
value|14
end_define

begin_comment
comment|/* BRG enables and commands */
end_comment

begin_define
define|#
directive|define
name|SCC_WR15
value|15
end_define

begin_comment
comment|/* interrupt enables */
end_comment

begin_comment
comment|/*  * Read registers defines  */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_BREAK
value|0x80
end_define

begin_comment
comment|/* break detected (rings twice), or */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_ABORT
value|0x80
end_define

begin_comment
comment|/* abort (synchr) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_TX_UNDERRUN
value|0x40
end_define

begin_comment
comment|/* xmit buffer empty/end of message */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_CTS
value|0x20
end_define

begin_comment
comment|/* clear-to-send pin active (sampled 					   only on intr and after RESI cmd */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_SYNCH
value|0x10
end_define

begin_comment
comment|/* SYNCH found/still hunting */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_DCD
value|0x08
end_define

begin_comment
comment|/* carrier-detect (same as CTS) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_TX_EMPTY
value|0x04
end_define

begin_comment
comment|/* xmit buffer empty */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_ZERO_COUNT
value|0x02
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|SCC_RR0_RX_AVAIL
value|0x01
end_define

begin_comment
comment|/* recv fifo not empty */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_EOF
value|0x80
end_define

begin_comment
comment|/* end-of-frame, SDLC mode */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_CRC_ERR
value|0x40
end_define

begin_comment
comment|/* incorrect CRC or.. */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_FRAME_ERR
value|0x40
end_define

begin_comment
comment|/* ..bad frame */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_RX_OVERRUN
value|0x20
end_define

begin_comment
comment|/* rcv fifo overflow */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_PARITY_ERR
value|0x10
end_define

begin_comment
comment|/* incorrect parity in data */
end_comment

begin_define
define|#
directive|define
name|SCC_RR1_RESIDUE0
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_RR1_RESIDUE1
value|0x04
end_define

begin_define
define|#
directive|define
name|SCC_RR1_RESIDUE2
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_RR1_ALL_SENT
value|0x01
end_define

begin_comment
comment|/* RR2 contains the interrupt vector unmodified (channel A) or    modified as follows (channel B, if vector-include-status) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR2_STATUS
parameter_list|(
name|val
parameter_list|)
value|((val)&0xf)
end_define

begin_define
define|#
directive|define
name|SCC_RR2_B_XMIT_DONE
value|0x0
end_define

begin_define
define|#
directive|define
name|SCC_RR2_B_EXT_STATUS
value|0x2
end_define

begin_define
define|#
directive|define
name|SCC_RR2_B_RECV_DONE
value|0x4
end_define

begin_define
define|#
directive|define
name|SCC_RR2_B_RECV_SPECIAL
value|0x6
end_define

begin_define
define|#
directive|define
name|SCC_RR2_A_XMIT_DONE
value|0x8
end_define

begin_define
define|#
directive|define
name|SCC_RR2_A_EXT_STATUS
value|0xa
end_define

begin_define
define|#
directive|define
name|SCC_RR2_A_RECV_DONE
value|0xc
end_define

begin_define
define|#
directive|define
name|SCC_RR2_A_RECV_SPECIAL
value|0xe
end_define

begin_comment
comment|/* Interrupts pending, to be read from channel A only (B raz) */
end_comment

begin_define
define|#
directive|define
name|SCC_RR3_zero
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCC_RR3_RX_IP_A
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_RR3_TX_IP_A
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_RR3_EXT_IP_A
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_RR3_RX_IP_B
value|0x04
end_define

begin_define
define|#
directive|define
name|SCC_RR3_TX_IP_B
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_RR3_EXT_IP_B
value|0x01
end_define

begin_comment
comment|/* RR8 is the receive data buffer, a 3 deep FIFO */
end_comment

begin_define
define|#
directive|define
name|SCC_RECV_BUFFER
value|SCC_RR8
end_define

begin_define
define|#
directive|define
name|SCC_RECV_FIFO_DEEP
value|3
end_define

begin_define
define|#
directive|define
name|SCC_RR10_1CLKS
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_RR10_2CLKS
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_RR10_zero
value|0x2d
end_define

begin_define
define|#
directive|define
name|SCC_RR10_LOOP_SND
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_RR10_ON_LOOP
value|0x02
end_define

begin_comment
comment|/* RR12/RR13 hold the timing base, upper byte in RR13 */
end_comment

begin_define
define|#
directive|define
name|SCC_GET_TIMING_BASE
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		register char	tmp;	\ 		SCC_READ_REG(scc,chan,SCC_RR12,val);\ 		SCC_READ_REG(scc,chan,SCC_RR13,tmp);\ 		(val) = ((val)<<8)|(tmp&0xff);\ 	}
end_define

begin_define
define|#
directive|define
name|SCC_RR15_BREAK_IE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_RR15_TX_UNDERRUN_IE
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_RR15_CTS_IE
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_RR15_SYNCH_IE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_RR15_DCD_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_RR15_zero
value|0x05
end_define

begin_define
define|#
directive|define
name|SCC_RR15_ZERO_COUNT_IE
value|0x02
end_define

begin_comment
comment|/*  * Write registers defines  */
end_comment

begin_comment
comment|/* WR0 is used for commands too */
end_comment

begin_define
define|#
directive|define
name|SCC_RESET_TXURUN_LATCH
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCC_RESET_TX_CRC
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_RESET_RX_CRC
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_RESET_HIGHEST_IUS
value|0x38
end_define

begin_comment
comment|/* channel A only */
end_comment

begin_define
define|#
directive|define
name|SCC_RESET_ERROR
value|0x30
end_define

begin_define
define|#
directive|define
name|SCC_RESET_TX_IP
value|0x28
end_define

begin_define
define|#
directive|define
name|SCC_IE_NEXT_CHAR
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_SEND_SDLC_ABORT
value|0x18
end_define

begin_define
define|#
directive|define
name|SCC_RESET_EXT_IP
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR1_DMA_ENABLE
value|0x80
end_define

begin_comment
comment|/* dma control */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_DMA_MODE
value|0x40
end_define

begin_comment
comment|/* drive ~req for DMA controller */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_DMA_RECV_DATA
value|0x20
end_define

begin_comment
comment|/* from wire to host memory */
end_comment

begin_comment
comment|/* interrupt enable/conditions */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_RXI_SPECIAL_O
value|0x18
end_define

begin_comment
comment|/* on special only */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_RXI_ALL_CHAR
value|0x10
end_define

begin_comment
comment|/* on each char, or special */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_RXI_FIRST_CHAR
value|0x08
end_define

begin_comment
comment|/* on first char, or special */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_RXI_DISABLE
value|0x00
end_define

begin_comment
comment|/* never on recv */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_PARITY_IE
value|0x04
end_define

begin_comment
comment|/* on parity errors */
end_comment

begin_define
define|#
directive|define
name|SCC_WR1_TX_IE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_WR1_EXT_IE
value|0x01
end_define

begin_comment
comment|/* WR2 is common and contains the interrupt vector (high nibble) */
end_comment

begin_define
define|#
directive|define
name|SCC_WR3_RX_8_BITS
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCC_WR3_RX_6_BITS
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_WR3_RX_7_BITS
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR3_RX_5_BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR3_AUTO_ENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_WR3_HUNT_MODE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR3_RX_CRC_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR3_SDLC_SRCH
value|0x04
end_define

begin_define
define|#
directive|define
name|SCC_WR3_INHIBIT_SYNCH
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_WR3_RX_ENABLE
value|0x01
end_define

begin_comment
comment|/* Should be re-written after reset */
end_comment

begin_define
define|#
directive|define
name|SCC_WR4_CLK_x64
value|0xc0
end_define

begin_comment
comment|/* clock divide factor */
end_comment

begin_define
define|#
directive|define
name|SCC_WR4_CLK_x32
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_WR4_CLK_x16
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR4_CLK_x1
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR4_EXT_SYNCH_MODE
value|0x30
end_define

begin_comment
comment|/* synch modes */
end_comment

begin_define
define|#
directive|define
name|SCC_WR4_SDLC_MODE
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_WR4_16BIT_SYNCH
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR4_8BIT_SYNCH
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR4_2_STOP
value|0x0c
end_define

begin_comment
comment|/* asynch modes */
end_comment

begin_define
define|#
directive|define
name|SCC_WR4_1_5_STOP
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR4_1_STOP
value|0x04
end_define

begin_define
define|#
directive|define
name|SCC_WR4_SYNCH_MODE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR4_EVEN_PARITY
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_WR4_PARITY_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCC_WR5_DTR
value|0x80
end_define

begin_comment
comment|/* drive DTR pin */
end_comment

begin_define
define|#
directive|define
name|SCC_WR5_TX_8_BITS
value|0x60
end_define

begin_define
define|#
directive|define
name|SCC_WR5_TX_6_BITS
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR5_TX_7_BITS
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_WR5_TX_5_BITS
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR5_SEND_BREAK
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR5_TX_ENABLE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR5_CRC_16
value|0x04
end_define

begin_comment
comment|/* CRC if non zero, .. */
end_comment

begin_define
define|#
directive|define
name|SCC_WR5_SDLC
value|0x00
end_define

begin_comment
comment|/* ..SDLC otherwise  */
end_comment

begin_define
define|#
directive|define
name|SCC_WR5_RTS
value|0x02
end_define

begin_comment
comment|/* drive RTS pin */
end_comment

begin_define
define|#
directive|define
name|SCC_WR5_TX_CRC_ENABLE
value|0x01
end_define

begin_comment
comment|/* Registers WR6 and WR7 are for synch modes data, with among other things: */
end_comment

begin_define
define|#
directive|define
name|SCC_WR6_BISYNCH_12
value|0x0f
end_define

begin_define
define|#
directive|define
name|SCC_WR6_SDLC_RANGE_MASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|SCC_WR7_SDLC_FLAG
value|0x7e
end_define

begin_comment
comment|/* WR8 is the transmit data buffer (no FIFO) */
end_comment

begin_define
define|#
directive|define
name|SCC_XMT_BUFFER
value|SCC_WR8
end_define

begin_define
define|#
directive|define
name|SCC_WR9_HW_RESET
value|0xc0
end_define

begin_comment
comment|/* force hardware reset */
end_comment

begin_define
define|#
directive|define
name|SCC_WR9_RESET_CHA_A
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_WR9_RESET_CHA_B
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR9_NON_VECTORED
value|0x20
end_define

begin_comment
comment|/* mbz for Zilog chip */
end_comment

begin_define
define|#
directive|define
name|SCC_WR9_STATUS_HIGH
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR9_MASTER_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR9_DLC
value|0x04
end_define

begin_comment
comment|/* disable-lower-chain */
end_comment

begin_define
define|#
directive|define
name|SCC_WR9_NV
value|0x02
end_define

begin_comment
comment|/* no vector */
end_comment

begin_define
define|#
directive|define
name|SCC_WR9_VIS
value|0x01
end_define

begin_comment
comment|/* vector-includes-status */
end_comment

begin_define
define|#
directive|define
name|SCC_WR10_CRC_PRESET
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_WR10_FM0
value|0x60
end_define

begin_define
define|#
directive|define
name|SCC_WR10_FM1
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR10_NRZI
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_WR10_NRZ
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR10_ACTIVE_ON_POLL
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR10_MARK_IDLE
value|0x08
end_define

begin_comment
comment|/* flag if zero */
end_comment

begin_define
define|#
directive|define
name|SCC_WR10_ABORT_ON_URUN
value|0x04
end_define

begin_comment
comment|/* flag if zero */
end_comment

begin_define
define|#
directive|define
name|SCC_WR10_LOOP_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_WR10_6BIT_SYNCH
value|0x01
end_define

begin_define
define|#
directive|define
name|SCC_WR10_8BIT_SYNCH
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR11_RTxC_XTAL
value|0x80
end_define

begin_comment
comment|/* RTxC pin is input (ext oscill) */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_RCLK_DPLL
value|0x60
end_define

begin_comment
comment|/* clock received data on dpll */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_RCLK_BAUDR
value|0x40
end_define

begin_comment
comment|/* .. on BRG */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_RCLK_TRc_PIN
value|0x20
end_define

begin_comment
comment|/* .. on TRxC pin */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_RCLK_RTc_PIN
value|0x00
end_define

begin_comment
comment|/* .. on RTxC pin */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_XTLK_DPLL
value|0x18
end_define

begin_define
define|#
directive|define
name|SCC_WR11_XTLK_BAUDR
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR11_XTLK_TRc_PIN
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR11_XTLK_RTc_PIN
value|0x00
end_define

begin_define
define|#
directive|define
name|SCC_WR11_TRc_OUT
value|0x04
end_define

begin_comment
comment|/* drive TRxC pin as output from..*/
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_TRcOUT_DPLL
value|0x03
end_define

begin_comment
comment|/* .. the dpll */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_TRcOUT_BAUDR
value|0x02
end_define

begin_comment
comment|/* .. the BRG */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_TRcOUT_XMTCLK
value|0x01
end_define

begin_comment
comment|/* .. the xmit clock */
end_comment

begin_define
define|#
directive|define
name|SCC_WR11_TRcOUT_XTAL
value|0x00
end_define

begin_comment
comment|/* .. the external oscillator */
end_comment

begin_comment
comment|/* WR12/WR13 are for timing base preset */
end_comment

begin_define
define|#
directive|define
name|SCC_SET_TIMING_BASE
parameter_list|(
name|scc
parameter_list|,
name|chan
parameter_list|,
name|val
parameter_list|)
value|{ \ 		SCC_WRITE_REG(scc,chan,SCC_RR12,val);\ 		SCC_WRITE_REG(scc,chan,SCC_RR13,(val)>>8);\ 	}
end_define

begin_comment
comment|/* More commands in this register */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14_NRZI_MODE
value|0xe0
end_define

begin_comment
comment|/* synch modulations */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14_FM_MODE
value|0xc0
end_define

begin_define
define|#
directive|define
name|SCC_WR14_RTc_SOURCE
value|0xa0
end_define

begin_comment
comment|/* clock is from pin .. */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14_BAUDR_SOURCE
value|0x80
end_define

begin_comment
comment|/* .. or internal BRG */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14_DISABLE_DPLL
value|0x60
end_define

begin_define
define|#
directive|define
name|SCC_WR14_RESET_CLKMISS
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR14_SEARCH_MODE
value|0x20
end_define

begin_comment
comment|/* ..and more bitsy */
end_comment

begin_define
define|#
directive|define
name|SCC_WR14_LOCAL_LOOPB
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR14_AUTO_ECHO
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR14_DTR_REQUEST
value|0x04
end_define

begin_define
define|#
directive|define
name|SCC_WR14_BAUDR_SRC
value|0x02
end_define

begin_define
define|#
directive|define
name|SCC_WR14_BAUDR_ENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|SCC_WR15_BREAK_IE
value|0x80
end_define

begin_define
define|#
directive|define
name|SCC_WR15_TX_UNDERRUN_IE
value|0x40
end_define

begin_define
define|#
directive|define
name|SCC_WR15_CTS_IE
value|0x20
end_define

begin_define
define|#
directive|define
name|SCC_WR15_SYNCHUNT_IE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCC_WR15_DCD_IE
value|0x08
end_define

begin_define
define|#
directive|define
name|SCC_WR15_zero
value|0x05
end_define

begin_define
define|#
directive|define
name|SCC_WR15_ZERO_COUNT_IE
value|0x02
end_define

begin_comment
comment|/* bits in dm lsr, copied from dmreg.h */
end_comment

begin_define
define|#
directive|define
name|DML_DSR
value|0000400
end_define

begin_comment
comment|/* data set ready, not a real DM bit */
end_comment

begin_define
define|#
directive|define
name|DML_RNG
value|0000200
end_define

begin_comment
comment|/* ring */
end_comment

begin_define
define|#
directive|define
name|DML_CAR
value|0000100
end_define

begin_comment
comment|/* carrier detect */
end_comment

begin_define
define|#
directive|define
name|DML_CTS
value|0000040
end_define

begin_comment
comment|/* clear to send */
end_comment

begin_define
define|#
directive|define
name|DML_SR
value|0000020
end_define

begin_comment
comment|/* secondary receive */
end_comment

begin_define
define|#
directive|define
name|DML_ST
value|0000010
end_define

begin_comment
comment|/* secondary transmit */
end_comment

begin_define
define|#
directive|define
name|DML_RTS
value|0000004
end_define

begin_comment
comment|/* request to send */
end_comment

begin_define
define|#
directive|define
name|DML_DTR
value|0000002
end_define

begin_comment
comment|/* data terminal ready */
end_comment

begin_define
define|#
directive|define
name|DML_LE
value|0000001
end_define

begin_comment
comment|/* line enable */
end_comment

begin_comment
comment|/*  * Minor device numbers for scc. Weird because B channel comes  * first and the A channels are wired for keyboard/mouse and the  * B channels for the comm port(s).  */
end_comment

begin_define
define|#
directive|define
name|SCCCOMM2_PORT
value|0x0
end_define

begin_define
define|#
directive|define
name|SCCMOUSE_PORT
value|0x1
end_define

begin_define
define|#
directive|define
name|SCCCOMM3_PORT
value|0x2
end_define

begin_define
define|#
directive|define
name|SCCKBD_PORT
value|0x3
end_define

end_unit

