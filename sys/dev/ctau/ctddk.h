begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Defines for Cronyx-Tau adapter driver.  *  * Copyright (C) 1994-2003 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: ctddk.h,v 1.1.2.3 2003/12/11 17:33:44 rik Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NBRD
value|3
end_define

begin_comment
comment|/* the maximum number of installed boards */
end_comment

begin_define
define|#
directive|define
name|NPORT
value|32
end_define

begin_comment
comment|/* the number of i/o ports per board */
end_comment

begin_define
define|#
directive|define
name|NCHAN
value|2
end_define

begin_comment
comment|/* the number of channels on the board */
end_comment

begin_define
define|#
directive|define
name|NBUF
value|4
end_define

begin_comment
comment|/* the number of buffers per direction */
end_comment

begin_define
define|#
directive|define
name|DMABUFSZ
value|1600
end_define

begin_comment
comment|/* buffer size */
end_comment

begin_define
define|#
directive|define
name|SCCBUFSZ
value|50
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|port_t
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|_M_ALPHA
end_ifdef

begin_comment
comment|/* port address on Alpha under */
end_comment

begin_define
define|#
directive|define
name|port_t
value|unsigned long
end_define

begin_comment
comment|/* Windows NT is 32 bit long */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|port_t
value|unsigned short
end_define

begin_comment
comment|/* all other architectures */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* have 16-bit port addresses */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * There are tree models of Tau adapters.  * Each of two channels of the adapter is assigned a type:  *  *		Channel 0	Channel 1  * ------------------------------------------  * Tau		T_SERIAL	T_SERIAL  * Tau/E1	T_E1		T_E1_SERIAL  * Tau/G703	T_G703		T_G703_SERIAL  *  * Each channel could work in one of several modes:  *  *		Channel 0	Channel 1  * ------------------------------------------  * Tau		M_ASYNC,	M_ASYNC,  *		M_HDLC		M_HDLC  * ------------------------------------------  * Tau/E1	M_E1,		M_E1,  *		M_E1& CFG_D,	M_E1& CFG_D,  *				M_ASYNC,  *				M_HDLC  * ------------------------------------------  * Tau/G703	M_G703, 	M_G703,  *				M_ASYNC,  *				M_HDLC  * ------------------------------------------  */
end_comment

begin_define
define|#
directive|define
name|B_TAU
value|0
end_define

begin_comment
comment|/* Tau - basic model */
end_comment

begin_define
define|#
directive|define
name|B_TAU_E1
value|1
end_define

begin_comment
comment|/* Tau/E1 */
end_comment

begin_define
define|#
directive|define
name|B_TAU_G703
value|2
end_define

begin_comment
comment|/* Tau/G.703 */
end_comment

begin_define
define|#
directive|define
name|B_TAU_E1C
value|3
end_define

begin_comment
comment|/* Tau/E1 revision C */
end_comment

begin_define
define|#
directive|define
name|B_TAU_E1D
value|4
end_define

begin_comment
comment|/* Tau/E1 revision C with phony mode support */
end_comment

begin_define
define|#
directive|define
name|B_TAU_G703C
value|5
end_define

begin_comment
comment|/* Tau/G.703 revision C */
end_comment

begin_define
define|#
directive|define
name|B_TAU2
value|6
end_define

begin_comment
comment|/* Tau2 - basic model */
end_comment

begin_define
define|#
directive|define
name|B_TAU2_E1
value|7
end_define

begin_comment
comment|/* Tau2/E1 */
end_comment

begin_define
define|#
directive|define
name|B_TAU2_E1D
value|8
end_define

begin_comment
comment|/* Tau2/E1 with phony mode support */
end_comment

begin_define
define|#
directive|define
name|B_TAU2_G703
value|9
end_define

begin_comment
comment|/* Tau2/G.703 */
end_comment

begin_define
define|#
directive|define
name|T_SERIAL
value|1
end_define

begin_define
define|#
directive|define
name|T_E1
value|2
end_define

begin_define
define|#
directive|define
name|T_G703
value|4
end_define

begin_define
define|#
directive|define
name|T_E1_SERIAL
value|(T_E1 | T_SERIAL)
end_define

begin_define
define|#
directive|define
name|T_G703_SERIAL
value|(T_G703 | T_SERIAL)
end_define

begin_define
define|#
directive|define
name|M_ASYNC
value|0
end_define

begin_comment
comment|/* asynchronous mode */
end_comment

begin_define
define|#
directive|define
name|M_HDLC
value|1
end_define

begin_comment
comment|/* bit-sync mode (HDLC) */
end_comment

begin_define
define|#
directive|define
name|M_G703
value|2
end_define

begin_define
define|#
directive|define
name|M_E1
value|3
end_define

begin_define
define|#
directive|define
name|CFG_A
value|0
end_define

begin_define
define|#
directive|define
name|CFG_B
value|1
end_define

begin_define
define|#
directive|define
name|CFG_C
value|2
end_define

begin_define
define|#
directive|define
name|CFG_D
value|3
end_define

begin_comment
comment|/* E1/G.703 interfaces - i0, i1  * Digital interface   - d0  *  *  * Configuration  * ---------------------------------------------------  * CFG_A	 | i0<->ct0   i1<->ct1  * ---------------------------------------------------  * CFG_B	 | i0<->ct0   d0<->ct1  *		 |  ^  *		 |  |  *		 |  v  *		 | i1  * ---------------------------------------------------  * CFG_C	 | ct0<->i0<->ct1  *		 |	  ^  *		 |	  |  *		 |	  v  *		 |	 i1  * ---------------------------------------------------  * CFG_D	 | i0(e1)<->hdlc<->hdlc<->ct0(e1)  * ONLY TAU/E1	 | i1(e1)<->hdlc<->hdlc<->ct1(e1)  *		 |  */
end_comment

begin_comment
comment|/*  * Mode register 0 (MD0) bits.  */
end_comment

begin_define
define|#
directive|define
name|MD0_STOPB_1
value|0
end_define

begin_comment
comment|/* 1 stop bit */
end_comment

begin_define
define|#
directive|define
name|MD0_STOPB_15
value|1
end_define

begin_comment
comment|/* 1.5 stop bits */
end_comment

begin_define
define|#
directive|define
name|MD0_STOPB_2
value|2
end_define

begin_comment
comment|/* 2 stop bits */
end_comment

begin_define
define|#
directive|define
name|MD0_MODE_ASYNC
value|0
end_define

begin_comment
comment|/* asynchronous mode */
end_comment

begin_define
define|#
directive|define
name|MD0_MODE_EXTSYNC
value|3
end_define

begin_comment
comment|/* external byte-sync mode */
end_comment

begin_define
define|#
directive|define
name|MD0_MODE_HDLC
value|4
end_define

begin_comment
comment|/* HDLC mode */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|stopb
range|:
literal|2
decl_stmt|;
comment|/* stop bit length */
name|unsigned
label|:
literal|2
expr_stmt|;
name|unsigned
name|cts_rts_dcd
range|:
literal|1
decl_stmt|;
comment|/* auto-enable CTS/DCD/RTS */
name|unsigned
name|mode
range|:
literal|3
decl_stmt|;
comment|/* protocol mode */
block|}
name|ct_md0_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|crcpre
range|:
literal|1
decl_stmt|;
comment|/* CRC preset 1s / 0s */
name|unsigned
name|ccitt
range|:
literal|1
decl_stmt|;
comment|/* CRC-CCITT / CRC-16 */
name|unsigned
name|crc
range|:
literal|1
decl_stmt|;
comment|/* CRC enable */
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|cts_dcd
range|:
literal|1
decl_stmt|;
comment|/* auto-enable CTS/DCD */
name|unsigned
name|mode
range|:
literal|3
decl_stmt|;
comment|/* protocol mode */
block|}
name|ct_md0_hdlc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Mode register 1 (MD1) bits.  */
end_comment

begin_define
define|#
directive|define
name|MD1_PAR_NO
value|0
end_define

begin_comment
comment|/* no parity */
end_comment

begin_define
define|#
directive|define
name|MD1_PAR_CMD
value|1
end_define

begin_comment
comment|/* parity bit appended by command */
end_comment

begin_define
define|#
directive|define
name|MD1_PAR_EVEN
value|2
end_define

begin_comment
comment|/* even parity */
end_comment

begin_define
define|#
directive|define
name|MD1_PAR_ODD
value|3
end_define

begin_comment
comment|/* odd parity */
end_comment

begin_define
define|#
directive|define
name|MD1_CLEN_8
value|0
end_define

begin_comment
comment|/* 8 bits/character */
end_comment

begin_define
define|#
directive|define
name|MD1_CLEN_7
value|1
end_define

begin_comment
comment|/* 7 bits/character */
end_comment

begin_define
define|#
directive|define
name|MD1_CLEN_6
value|2
end_define

begin_comment
comment|/* 6 bits/character */
end_comment

begin_define
define|#
directive|define
name|MD1_CLEN_5
value|3
end_define

begin_comment
comment|/* 5 bits/character */
end_comment

begin_define
define|#
directive|define
name|MD1_CLK_1
value|0
end_define

begin_comment
comment|/* 1/1 clock rate */
end_comment

begin_define
define|#
directive|define
name|MD1_CLK_16
value|1
end_define

begin_comment
comment|/* 1/16 clock rate */
end_comment

begin_define
define|#
directive|define
name|MD1_CLK_32
value|2
end_define

begin_comment
comment|/* 1/32 clock rate */
end_comment

begin_define
define|#
directive|define
name|MD1_CLK_64
value|3
end_define

begin_comment
comment|/* 1/64 clock rate */
end_comment

begin_define
define|#
directive|define
name|MD1_ADDR_NOCHK
value|0
end_define

begin_comment
comment|/* do not check address field */
end_comment

begin_define
define|#
directive|define
name|MD1_ADDR_SNGLE1
value|1
end_define

begin_comment
comment|/* single address 1 */
end_comment

begin_define
define|#
directive|define
name|MD1_ADDR_SNGLE2
value|2
end_define

begin_comment
comment|/* single address 2 */
end_comment

begin_define
define|#
directive|define
name|MD1_ADDR_DUAL
value|3
end_define

begin_comment
comment|/* dual address */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|parmode
range|:
literal|2
decl_stmt|;
comment|/* parity mode */
name|unsigned
name|rxclen
range|:
literal|2
decl_stmt|;
comment|/* receive character length */
name|unsigned
name|txclen
range|:
literal|2
decl_stmt|;
comment|/* transmit character length */
name|unsigned
name|clk
range|:
literal|2
decl_stmt|;
comment|/* clock rate */
block|}
name|ct_md1_async_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
label|:
literal|6
expr_stmt|;
name|unsigned
name|addr
range|:
literal|2
decl_stmt|;
comment|/* address field check */
block|}
name|ct_md1_hdlc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Mode register 2 (MD2) bits.  */
end_comment

begin_define
define|#
directive|define
name|MD2_FDX
value|0
end_define

begin_comment
comment|/* full duplex communication */
end_comment

begin_define
define|#
directive|define
name|MD2_RLOOP
value|1
end_define

begin_comment
comment|/* remote loopback (auto echo) */
end_comment

begin_define
define|#
directive|define
name|MD2_LLOOP
value|3
end_define

begin_comment
comment|/* local+remote loopback */
end_comment

begin_define
define|#
directive|define
name|MD2_DPLL_CLK_8
value|0
end_define

begin_comment
comment|/* x8 ADPLL clock rate */
end_comment

begin_define
define|#
directive|define
name|MD2_DPLL_CLK_16
value|1
end_define

begin_comment
comment|/* x16 ADPLL clock rate */
end_comment

begin_define
define|#
directive|define
name|MD2_DPLL_CLK_32
value|2
end_define

begin_comment
comment|/* x32 ADPLL clock rate */
end_comment

begin_define
define|#
directive|define
name|MD2_ENCOD_NRZ
value|0
end_define

begin_comment
comment|/* NRZ encoding */
end_comment

begin_define
define|#
directive|define
name|MD2_ENCOD_NRZI
value|1
end_define

begin_comment
comment|/* NRZI encoding */
end_comment

begin_define
define|#
directive|define
name|MD2_ENCOD_MANCHESTER
value|4
end_define

begin_comment
comment|/* Manchester encoding */
end_comment

begin_define
define|#
directive|define
name|MD2_ENCOD_FM0
value|5
end_define

begin_comment
comment|/* FM0 encoding */
end_comment

begin_define
define|#
directive|define
name|MD2_ENCOD_FM1
value|6
end_define

begin_comment
comment|/* FM1 encoding */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|loop
range|:
literal|2
decl_stmt|;
comment|/* loopback mode */
name|unsigned
label|:
literal|1
expr_stmt|;
name|unsigned
name|dpll_clk
range|:
literal|2
decl_stmt|;
comment|/* ADPLL clock rate */
name|unsigned
name|encod
range|:
literal|3
decl_stmt|;
comment|/* signal encoding NRZ/NRZI/etc. */
block|}
name|ct_md2_t
typedef|;
end_typedef

begin_comment
comment|/*  * DMA priority control register (PCR) values.  */
end_comment

begin_define
define|#
directive|define
name|PCR_PRIO_0_1
value|0
end_define

begin_comment
comment|/* priority c0r> c0t> c1r> c1t */
end_comment

begin_define
define|#
directive|define
name|PCR_PRIO_1_0
value|1
end_define

begin_comment
comment|/* priority c1r> c1t> c0r> c0t */
end_comment

begin_define
define|#
directive|define
name|PCR_PRIO_RX_TX
value|2
end_define

begin_comment
comment|/* priority c0r> c1r> c0t> c1t */
end_comment

begin_define
define|#
directive|define
name|PCR_PRIO_TX_RX
value|3
end_define

begin_comment
comment|/* priority c0t> c1t> c0r> c1r */
end_comment

begin_define
define|#
directive|define
name|PCR_PRIO_ROTATE
value|4
end_define

begin_comment
comment|/* rotation priority -c0r-c0t-c1r-c1t- */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|prio
range|:
literal|3
decl_stmt|;
comment|/* priority of channels */
name|unsigned
name|noshare
range|:
literal|1
decl_stmt|;
comment|/* 1 - chan holds the bus until end of data */
comment|/* 0 - all channels share the the bus hold */
name|unsigned
name|release
range|:
literal|1
decl_stmt|;
comment|/* 1 - release the bus between transfers */
comment|/* 0 - hold the bus until all transfers done */
block|}
name|ct_pcr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* hdlc channel options */
name|ct_md0_hdlc_t
name|md0
decl_stmt|;
comment|/* mode register 0 */
name|ct_md1_hdlc_t
name|md1
decl_stmt|;
comment|/* mode register 1 */
name|unsigned
name|char
name|ctl
decl_stmt|;
comment|/* control register */
name|unsigned
name|char
name|sa0
decl_stmt|;
comment|/* sync/address register 0 */
name|unsigned
name|char
name|sa1
decl_stmt|;
comment|/* sync/address register 1 */
name|unsigned
name|char
name|rxs
decl_stmt|;
comment|/* receive clock source */
name|unsigned
name|char
name|txs
decl_stmt|;
comment|/* transmit clock source */
block|}
name|ct_opt_hdlc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|ct_md2_t
name|md2
decl_stmt|;
comment|/* mode register 2 */
name|unsigned
name|char
name|dma_rrc
decl_stmt|;
comment|/* DMA mode receive FIFO ready level */
name|unsigned
name|char
name|dma_trc0
decl_stmt|;
comment|/* DMA mode transmit FIFO empty mark */
name|unsigned
name|char
name|dma_trc1
decl_stmt|;
comment|/* DMA mode transmit FIFO full mark */
name|unsigned
name|char
name|pio_rrc
decl_stmt|;
comment|/* port i/o mode receive FIFO ready level */
name|unsigned
name|char
name|pio_trc0
decl_stmt|;
comment|/* port i/o transmit FIFO empty mark */
name|unsigned
name|char
name|pio_trc1
decl_stmt|;
comment|/* port i/o transmit FIFO full mark */
block|}
name|ct_chan_opt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Option CLK is valid for both E1 and G.703 models.  * Options RATE, PCE, TEST are for G.703 only.  */
end_comment

begin_define
define|#
directive|define
name|GCLK_INT
value|0
end_define

begin_comment
comment|/* internal transmit clock source */
end_comment

begin_define
define|#
directive|define
name|GCLK_RCV
value|1
end_define

begin_comment
comment|/* transmit clock source = receive */
end_comment

begin_define
define|#
directive|define
name|GCLK_RCLKO
value|2
end_define

begin_comment
comment|/* tclk = receive clock of another channel */
end_comment

begin_define
define|#
directive|define
name|GTEST_DIS
value|0
end_define

begin_comment
comment|/* test disabled, normal operation */
end_comment

begin_define
define|#
directive|define
name|GTEST_0
value|1
end_define

begin_comment
comment|/* test "all zeros" */
end_comment

begin_define
define|#
directive|define
name|GTEST_1
value|2
end_define

begin_comment
comment|/* test "all ones" */
end_comment

begin_define
define|#
directive|define
name|GTEST_01
value|3
end_define

begin_comment
comment|/* test "0/1" */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* E1/G.703 channel options */
name|unsigned
name|char
name|hdb3
decl_stmt|;
comment|/* encoding HDB3/AMI */
name|unsigned
name|char
name|pce
decl_stmt|;
comment|/* precoder enable */
name|unsigned
name|char
name|test
decl_stmt|;
comment|/* test mode 0/1/01/disable */
name|unsigned
name|char
name|crc4
decl_stmt|;
comment|/* E1 CRC4 enable */
name|unsigned
name|char
name|cas
decl_stmt|;
comment|/* E1 signalling mode CAS/CCS */
name|unsigned
name|char
name|higain
decl_stmt|;
comment|/* E1 high gain amplifier (30 dB) */
name|unsigned
name|char
name|phony
decl_stmt|;
comment|/* E1 phony mode */
name|unsigned
name|char
name|pce2
decl_stmt|;
comment|/* old PCM2 precoder compatibility */
name|unsigned
name|long
name|rate
decl_stmt|;
comment|/* data rate 2048/1024/512/256/128/64 kbit/s */
name|unsigned
name|short
name|level
decl_stmt|;
comment|/* G.703 input signal level, -cB */
block|}
name|ct_opt_g703_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|bcr2
decl_stmt|;
comment|/* board control register 2 */
name|ct_pcr_t
name|pcr
decl_stmt|;
comment|/* DMA priority control register */
name|unsigned
name|char
name|clk0
decl_stmt|;
comment|/* E1/G.703 chan 0 txclk src int/rcv/rclki */
name|unsigned
name|char
name|clk1
decl_stmt|;
comment|/* E1/G.703 chan 1 txclk src int/rcv/rclki */
name|unsigned
name|char
name|cfg
decl_stmt|;
comment|/* E1 configuration II/HI/K */
name|unsigned
name|long
name|s0
decl_stmt|;
comment|/* E1 channel 0 timeslot mask */
name|unsigned
name|long
name|s1
decl_stmt|;
comment|/* E1 channel 1 timeslot mask */
name|unsigned
name|long
name|s2
decl_stmt|;
comment|/* E1 subchannel pass-through timeslot mask */
block|}
name|ct_board_opt_t
typedef|;
end_typedef

begin_comment
comment|/*  * Board control register 2 bits.  */
end_comment

begin_define
define|#
directive|define
name|BCR2_INVTXC0
value|0x10
end_define

begin_comment
comment|/* channel 0 invert transmit clock */
end_comment

begin_define
define|#
directive|define
name|BCR2_INVTXC1
value|0x20
end_define

begin_comment
comment|/* channel 1 invert transmit clock */
end_comment

begin_define
define|#
directive|define
name|BCR2_INVRXC0
value|0x40
end_define

begin_comment
comment|/* channel 0 invert receive clock */
end_comment

begin_define
define|#
directive|define
name|BCR2_INVRXC1
value|0x80
end_define

begin_comment
comment|/* channel 1 invert receive clock */
end_comment

begin_define
define|#
directive|define
name|BCR2_BUS_UNLIM
value|0x01
end_define

begin_comment
comment|/* unlimited DMA master burst length */
end_comment

begin_define
define|#
directive|define
name|BCR2_BUS_RFST
value|0x02
end_define

begin_comment
comment|/* fast read cycle bus timing */
end_comment

begin_define
define|#
directive|define
name|BCR2_BUS_WFST
value|0x04
end_define

begin_comment
comment|/* fast write cycle bus timing */
end_comment

begin_comment
comment|/*  * Receive/transmit clock source register (RXS/TXS) bits - from hdc64570.h.  */
end_comment

begin_define
define|#
directive|define
name|CLK_MASK
value|0x70
end_define

begin_comment
comment|/* RXC/TXC clock input mask */
end_comment

begin_define
define|#
directive|define
name|CLK_LINE
value|0x00
end_define

begin_comment
comment|/* RXC/TXC line input */
end_comment

begin_define
define|#
directive|define
name|CLK_INT
value|0x40
end_define

begin_comment
comment|/* internal baud rate generator */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_LINE_NS
value|0x20
end_define

begin_comment
comment|/* RXC line with noise suppression */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_DPLL_INT
value|0x60
end_define

begin_comment
comment|/* ADPLL based on internal BRG */
end_comment

begin_define
define|#
directive|define
name|CLK_RXS_DPLL_LINE
value|0x70
end_define

begin_comment
comment|/* ADPLL based on RXC line */
end_comment

begin_define
define|#
directive|define
name|CLK_TXS_RECV
value|0x60
end_define

begin_comment
comment|/* receive clock */
end_comment

begin_comment
comment|/*  * Control register (CTL) bits - from hdc64570.h.  */
end_comment

begin_define
define|#
directive|define
name|CTL_RTS_INV
value|0x01
end_define

begin_comment
comment|/* RTS control bit (inverted) */
end_comment

begin_define
define|#
directive|define
name|CTL_SYNCLD
value|0x04
end_define

begin_comment
comment|/* load SYN characters */
end_comment

begin_define
define|#
directive|define
name|CTL_BRK
value|0x08
end_define

begin_comment
comment|/* async: send break */
end_comment

begin_define
define|#
directive|define
name|CTL_IDLE_MARK
value|0
end_define

begin_comment
comment|/* HDLC: when idle, transmit mark */
end_comment

begin_define
define|#
directive|define
name|CTL_IDLE_PTRN
value|0x10
end_define

begin_comment
comment|/* HDLC: when idle, transmit an idle pattern */
end_comment

begin_define
define|#
directive|define
name|CTL_UDRN_ABORT
value|0
end_define

begin_comment
comment|/* HDLC: on underrun - abort */
end_comment

begin_define
define|#
directive|define
name|CTL_UDRN_FCS
value|0x20
end_define

begin_comment
comment|/* HDLC: on underrun - send FCS/flag */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|long
name|bpv
decl_stmt|;
comment|/* bipolar violations */
name|unsigned
name|long
name|fse
decl_stmt|;
comment|/* frame sync errors */
name|unsigned
name|long
name|crce
decl_stmt|;
comment|/* CRC errors */
name|unsigned
name|long
name|rcrce
decl_stmt|;
comment|/* remote CRC errors (E-bit) */
name|unsigned
name|long
name|uas
decl_stmt|;
comment|/* unavailable seconds */
name|unsigned
name|long
name|les
decl_stmt|;
comment|/* line errored seconds */
name|unsigned
name|long
name|es
decl_stmt|;
comment|/* errored seconds */
name|unsigned
name|long
name|bes
decl_stmt|;
comment|/* bursty errored seconds */
name|unsigned
name|long
name|ses
decl_stmt|;
comment|/* severely errored seconds */
name|unsigned
name|long
name|oofs
decl_stmt|;
comment|/* out of frame seconds */
name|unsigned
name|long
name|css
decl_stmt|;
comment|/* controlled slip seconds */
name|unsigned
name|long
name|dm
decl_stmt|;
comment|/* degraded minutes */
block|}
name|ct_gstat_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ESTS_NOALARM
value|0x0001
end_define

begin_comment
comment|/* no alarm present */
end_comment

begin_define
define|#
directive|define
name|ESTS_FARLOF
value|0x0002
end_define

begin_comment
comment|/* receiving far loss of framing */
end_comment

begin_define
define|#
directive|define
name|ESTS_AIS
value|0x0008
end_define

begin_comment
comment|/* receiving all ones */
end_comment

begin_define
define|#
directive|define
name|ESTS_LOF
value|0x0020
end_define

begin_comment
comment|/* loss of framing */
end_comment

begin_define
define|#
directive|define
name|ESTS_LOS
value|0x0040
end_define

begin_comment
comment|/* loss of signal */
end_comment

begin_define
define|#
directive|define
name|ESTS_AIS16
value|0x0100
end_define

begin_comment
comment|/* receiving all ones in timeslot 16 */
end_comment

begin_define
define|#
directive|define
name|ESTS_FARLOMF
value|0x0200
end_define

begin_comment
comment|/* receiving alarm in timeslot 16 */
end_comment

begin_define
define|#
directive|define
name|ESTS_LOMF
value|0x0400
end_define

begin_comment
comment|/* loss of multiframe sync */
end_comment

begin_define
define|#
directive|define
name|ESTS_TSTREQ
value|0x0800
end_define

begin_comment
comment|/* test code detected */
end_comment

begin_define
define|#
directive|define
name|ESTS_TSTERR
value|0x1000
end_define

begin_comment
comment|/* test error */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|data
index|[
literal|10
index|]
decl_stmt|;
block|}
name|ct_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|tbuffer
index|[
name|NBUF
index|]
index|[
name|DMABUFSZ
index|]
decl_stmt|;
comment|/* transmit buffers */
name|unsigned
name|char
name|rbuffer
index|[
name|NBUF
index|]
index|[
name|DMABUFSZ
index|]
decl_stmt|;
comment|/* receive buffers  */
name|ct_desc_t
name|descbuf
index|[
literal|4
operator|*
name|NBUF
index|]
decl_stmt|;
comment|/* descriptors */
comment|/* double size for alignment */
block|}
name|ct_buf_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|B_NEXT
parameter_list|(
name|b
parameter_list|)
value|(*(unsigned short*)(b).data)
end_define

begin_comment
comment|/* next descriptor ptr */
end_comment

begin_define
define|#
directive|define
name|B_PTR
parameter_list|(
name|b
parameter_list|)
value|(*(unsigned long*) ((b).data+2))
end_define

begin_comment
comment|/* ptr to data buffer */
end_comment

begin_define
define|#
directive|define
name|B_LEN
parameter_list|(
name|b
parameter_list|)
value|(*(unsigned short*)((b).data+6))
end_define

begin_comment
comment|/* data buffer length */
end_comment

begin_define
define|#
directive|define
name|B_STATUS
parameter_list|(
name|b
parameter_list|)
value|(*(unsigned short*)((b).data+8))
end_define

begin_comment
comment|/* buf status, see FST */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|port_t
name|DAR
decl_stmt|,
name|DARB
decl_stmt|,
name|SAR
decl_stmt|,
name|SARB
decl_stmt|,
name|CDA
decl_stmt|,
name|EDA
decl_stmt|,
name|BFL
decl_stmt|,
name|BCR
decl_stmt|,
name|DSR
decl_stmt|,
name|DMR
decl_stmt|,
name|FCT
decl_stmt|,
name|DIR
decl_stmt|,
name|DCR
decl_stmt|,
name|TCNT
decl_stmt|,
name|TCONR
decl_stmt|,
name|TCSR
decl_stmt|,
name|TEPR
decl_stmt|;
block|}
name|ct_dmareg_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|NDIS_MINIPORT_DRIVER
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|_ct_queue_t
block|{
comment|/* packet queue */
name|PNDIS_WAN_PACKET
name|head
decl_stmt|;
comment|/* first packet in queue */
name|PNDIS_WAN_PACKET
name|tail
decl_stmt|;
comment|/* last packet in queue */
block|}
name|ct_queue_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_ct_chan_t
block|{
name|port_t
name|MD0
decl_stmt|,
name|MD1
decl_stmt|,
name|MD2
decl_stmt|,
name|CTL
decl_stmt|,
name|RXS
decl_stmt|,
name|TXS
decl_stmt|,
name|TMC
decl_stmt|,
name|CMD
decl_stmt|,
name|ST0
decl_stmt|,
name|ST1
decl_stmt|,
name|ST2
decl_stmt|,
name|ST3
decl_stmt|,
name|FST
decl_stmt|,
name|IE0
decl_stmt|,
name|IE1
decl_stmt|,
name|IE2
decl_stmt|,
name|FIE
decl_stmt|,
name|SA0
decl_stmt|,
name|SA1
decl_stmt|,
name|IDL
decl_stmt|,
name|TRB
decl_stmt|,
name|RRC
decl_stmt|,
name|TRC0
decl_stmt|,
name|TRC1
decl_stmt|,
name|CST
decl_stmt|;
name|ct_dmareg_t
name|RX
decl_stmt|;
comment|/* RX DMA/timer registers */
name|ct_dmareg_t
name|TX
decl_stmt|;
comment|/* TX DMA/timer registers */
name|unsigned
name|char
name|num
decl_stmt|;
comment|/* channel number, 0..1 */
name|struct
name|_ct_board_t
modifier|*
name|board
decl_stmt|;
comment|/* board pointer */
name|unsigned
name|long
name|baud
decl_stmt|;
comment|/* data rate */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* channel type */
name|unsigned
name|char
name|mode
decl_stmt|;
comment|/* channel mode */
name|ct_chan_opt_t
name|opt
decl_stmt|;
comment|/* common channel options */
name|ct_opt_hdlc_t
name|hopt
decl_stmt|;
comment|/* hdlc mode options */
name|ct_opt_g703_t
name|gopt
decl_stmt|;
comment|/* E1/G.703 options */
name|unsigned
name|char
name|dtr
decl_stmt|;
comment|/* DTR signal value */
name|unsigned
name|char
name|rts
decl_stmt|;
comment|/* RTS signal value */
name|unsigned
name|char
name|lx
decl_stmt|;
comment|/* LXT input bit settings */
name|unsigned
name|char
modifier|*
name|tbuf
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* transmit buffer */
name|ct_desc_t
modifier|*
name|tdesc
decl_stmt|;
comment|/* transmit buffer descriptors */
name|unsigned
name|long
name|tphys
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* transmit buffer phys address */
name|unsigned
name|long
name|tdphys
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* transmit descr phys addresses */
name|int
name|tn
decl_stmt|;
comment|/* first active transmit buffer */
name|int
name|te
decl_stmt|;
comment|/* first active transmit buffer */
name|unsigned
name|char
modifier|*
name|rbuf
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* receive buffers */
name|ct_desc_t
modifier|*
name|rdesc
decl_stmt|;
comment|/* receive buffer descriptors */
name|unsigned
name|long
name|rphys
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* receive buffer phys address */
name|unsigned
name|long
name|rdphys
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* receive descr phys addresses */
name|int
name|rn
decl_stmt|;
comment|/* first active receive buffer */
name|unsigned
name|long
name|rintr
decl_stmt|;
comment|/* receive interrupts */
name|unsigned
name|long
name|tintr
decl_stmt|;
comment|/* transmit interrupts */
name|unsigned
name|long
name|mintr
decl_stmt|;
comment|/* modem interrupts */
name|unsigned
name|long
name|ibytes
decl_stmt|;
comment|/* input bytes */
name|unsigned
name|long
name|ipkts
decl_stmt|;
comment|/* input packets */
name|unsigned
name|long
name|ierrs
decl_stmt|;
comment|/* input errors */
name|unsigned
name|long
name|obytes
decl_stmt|;
comment|/* output bytes */
name|unsigned
name|long
name|opkts
decl_stmt|;
comment|/* output packets */
name|unsigned
name|long
name|oerrs
decl_stmt|;
comment|/* output errors */
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* line status bit mask */
name|unsigned
name|long
name|totsec
decl_stmt|;
comment|/* total seconds elapsed */
name|unsigned
name|long
name|cursec
decl_stmt|;
comment|/* total seconds elapsed */
name|unsigned
name|long
name|degsec
decl_stmt|;
comment|/* degraded seconds */
name|unsigned
name|long
name|degerr
decl_stmt|;
comment|/* errors during degraded seconds */
name|ct_gstat_t
name|currnt
decl_stmt|;
comment|/* current 15-min interval data */
name|ct_gstat_t
name|total
decl_stmt|;
comment|/* total statistics data */
name|ct_gstat_t
name|interval
index|[
literal|48
index|]
decl_stmt|;
comment|/* 12 hour period data */
name|void
modifier|*
name|attach
index|[
name|NBUF
index|]
decl_stmt|;
comment|/* system dependent data per buffer */
name|void
modifier|*
name|sys
decl_stmt|;
comment|/* system dependent data per channel */
name|int
name|debug
decl_stmt|;
name|int
name|e1_first_int
decl_stmt|;
name|unsigned
name|char
modifier|*
name|sccrx
decl_stmt|,
modifier|*
name|scctx
decl_stmt|;
comment|/* pointers to SCC rx and tx buffers */
name|int
name|sccrx_empty
decl_stmt|,
name|scctx_empty
decl_stmt|;
comment|/* flags : set when buffer is empty  */
name|int
name|sccrx_b
decl_stmt|,
name|scctx_b
decl_stmt|;
comment|/* first byte in queue	   */
name|int
name|sccrx_e
decl_stmt|,
name|scctx_e
decl_stmt|;
comment|/* first free byte in queue */
comment|/* pointers to callback functions */
name|void
function_decl|(
modifier|*
name|call_on_tx
function_decl|)
parameter_list|(
name|struct
name|_ct_chan_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_rx
function_decl|)
parameter_list|(
name|struct
name|_ct_chan_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_msig
function_decl|)
parameter_list|(
name|struct
name|_ct_chan_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_scc
function_decl|)
parameter_list|(
name|struct
name|_ct_chan_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|call_on_err
function_decl|)
parameter_list|(
name|struct
name|_ct_chan_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|NDIS_MINIPORT_DRIVER
comment|/* NDIS 3 - WinNT/Win95 */
name|HTAPI_LINE
name|htline
decl_stmt|;
comment|/* TAPI line descriptor */
name|HTAPI_CALL
name|htcall
decl_stmt|;
comment|/* TAPI call descriptor */
name|NDIS_HANDLE
name|connect
decl_stmt|;
comment|/* WAN connection context */
name|ct_queue_t
name|sendq
decl_stmt|;
comment|/* packets to transmit queue */
name|ct_queue_t
name|busyq
decl_stmt|;
comment|/* transmit busy queue */
name|UINT
name|state
decl_stmt|;
comment|/* line state mask */
name|int
name|timo
decl_stmt|;
comment|/* state timeout counter */
endif|#
directive|endif
block|}
name|ct_chan_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ct_board_t
block|{
name|port_t
name|port
decl_stmt|;
comment|/* base board port, 200..3e0 */
name|unsigned
name|short
name|num
decl_stmt|;
comment|/* board number, 0..2 */
name|unsigned
name|char
name|irq
decl_stmt|;
comment|/* intterupt request {3 5 7 10 11 12 15} */
name|unsigned
name|char
name|dma
decl_stmt|;
comment|/* DMA request {5 6 7} */
name|unsigned
name|long
name|osc
decl_stmt|;
comment|/* oscillator frequency: 10MHz or 8.192 */
name|unsigned
name|char
name|type
decl_stmt|;
comment|/* board type Tau/TauE1/TauG703 */
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* board version name */
name|unsigned
name|char
name|bcr0
decl_stmt|;
comment|/* BCR0 image */
name|unsigned
name|char
name|bcr1
decl_stmt|;
comment|/* BCR1 image */
name|unsigned
name|char
name|bcr2
decl_stmt|;
comment|/* BCR2 image */
name|unsigned
name|char
name|gmd0
decl_stmt|;
comment|/* G.703 MD0 register image */
name|unsigned
name|char
name|gmd1
decl_stmt|;
comment|/* G.703 MD1 register image */
name|unsigned
name|char
name|gmd2
decl_stmt|;
comment|/* G.703 MD2 register image */
name|unsigned
name|char
name|e1cfg
decl_stmt|;
comment|/* E1 CFG register image */
name|unsigned
name|char
name|e1syn
decl_stmt|;
comment|/* E1 SYN register image */
name|ct_board_opt_t
name|opt
decl_stmt|;
comment|/* board options */
name|ct_chan_t
name|chan
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* channel structures */
ifdef|#
directive|ifdef
name|NDIS_MINIPORT_DRIVER
comment|/* NDIS 3 - WinNT/Win95 */
name|PVOID
name|ioaddr
decl_stmt|;
comment|/* mapped i/o port address */
name|NDIS_HANDLE
name|mh
decl_stmt|;
comment|/* miniport adapter handler */
name|NDIS_MINIPORT_INTERRUPT
name|irqh
decl_stmt|;
comment|/* interrupt handler */
name|NDIS_HANDLE
name|dmah
decl_stmt|;
comment|/* dma channel handler */
name|ULONG
name|bufsz
decl_stmt|;
comment|/* size of shared memory buffer */
name|PVOID
name|buf
decl_stmt|;
comment|/* shared memory for adapter */
name|NDIS_PHYSICAL_ADDRESS
name|bphys
decl_stmt|;
comment|/* shared memory phys address */
name|NDIS_SPIN_LOCK
name|lock
decl_stmt|;
comment|/* lock descriptor */
name|ULONG
name|debug
decl_stmt|;
comment|/* debug flags */
name|ULONG
name|idbase
decl_stmt|;
comment|/* TAPI device identifier base number */
name|ULONG
name|anum
decl_stmt|;
comment|/* adapter number, from inf setup script */
name|NDIS_MINIPORT_TIMER
name|timer
decl_stmt|;
comment|/* periodic timer structure */
endif|#
directive|endif
block|}
name|ct_board_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|long
name|ct_baud
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|ct_chan_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ct_board_opt_t
name|ct_board_opt_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default board options */
end_comment

begin_decl_stmt
specifier|extern
name|ct_chan_opt_t
name|ct_chan_opt_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default channel options */
end_comment

begin_decl_stmt
specifier|extern
name|ct_opt_hdlc_t
name|ct_opt_hdlc_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default hdlc mode options */
end_comment

begin_decl_stmt
specifier|extern
name|ct_opt_g703_t
name|ct_opt_g703_dflt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default E1/G.703 options */
end_comment

begin_struct_decl
struct_decl|struct
name|_cr_dat_tst
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ct_probe_board
parameter_list|(
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_init
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|,
name|long
name|bits
parameter_list|,
specifier|const
name|struct
name|_cr_dat_tst
modifier|*
name|tst
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_init_board
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|,
name|int
name|type
parameter_list|,
name|long
name|osc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_download
parameter_list|(
name|port_t
name|port
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|,
name|long
name|bits
parameter_list|,
specifier|const
name|struct
name|_cr_dat_tst
modifier|*
name|tst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_download2
parameter_list|(
name|port_t
name|port
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_setup_board
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|firmware
parameter_list|,
name|long
name|bits
parameter_list|,
specifier|const
name|struct
name|_cr_dat_tst
modifier|*
name|tst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_setup_e1
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_setup_g703
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_setup_chan
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_update_chan
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_start_receiver
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|dma
parameter_list|,
name|unsigned
name|long
name|buf1
parameter_list|,
name|unsigned
name|len
parameter_list|,
name|unsigned
name|long
name|buf
parameter_list|,
name|unsigned
name|long
name|lim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_start_transmitter
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|dma
parameter_list|,
name|unsigned
name|long
name|buf1
parameter_list|,
name|unsigned
name|len
parameter_list|,
name|unsigned
name|long
name|buf
parameter_list|,
name|unsigned
name|long
name|lim
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_dtr
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_rts
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_brk
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_led
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_cmd
parameter_list|(
name|port_t
name|base
parameter_list|,
name|int
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_disable_dma
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_reinit_board
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_reinit_chan
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_dsr
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_cd
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_cts
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_lq
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_compute_clock
parameter_list|(
name|long
name|hz
parameter_list|,
name|long
name|baud
parameter_list|,
name|int
modifier|*
name|txbr
parameter_list|,
name|int
modifier|*
name|tmc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|cte_in
parameter_list|(
name|port_t
name|base
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cte_out
parameter_list|(
name|port_t
name|base
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|cte_ins
parameter_list|(
name|port_t
name|base
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|,
name|unsigned
name|char
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|cte_in2
parameter_list|(
name|port_t
name|base
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cte_out2
parameter_list|(
name|port_t
name|base
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctg_outx
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|ctg_inx
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|char
name|cte_in2d
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cte_out2d
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cte_out2c
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* functions dealing with interrupt vector in DOS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MSDOS
argument_list|)
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_function_decl
name|int
name|ddk_int_alloc
parameter_list|(
name|int
name|irq
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|()
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ddk_int_restore
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ct_probe_irq
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_int_handler
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_g703_timer
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DDK errors */
end_comment

begin_define
define|#
directive|define
name|CT_FRAME
value|1
end_define

begin_define
define|#
directive|define
name|CT_CRC
value|2
end_define

begin_define
define|#
directive|define
name|CT_OVERRUN
value|3
end_define

begin_define
define|#
directive|define
name|CT_OVERFLOW
value|4
end_define

begin_define
define|#
directive|define
name|CT_UNDERRUN
value|5
end_define

begin_define
define|#
directive|define
name|CT_SCC_OVERRUN
value|6
end_define

begin_define
define|#
directive|define
name|CT_SCC_FRAME
value|7
end_define

begin_define
define|#
directive|define
name|CT_SCC_OVERFLOW
value|8
end_define

begin_function_decl
name|int
name|ct_open_board
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|num
parameter_list|,
name|port_t
name|port
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_close_board
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_find
parameter_list|(
name|port_t
modifier|*
name|board_ports
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_set_config
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|int
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_set_clk
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|clk
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_set_ts
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|long
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_set_subchan
parameter_list|(
name|ct_board_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|long
name|ts
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_set_higain
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_phony
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ct_get_config
parameter_list|(
name|b
parameter_list|)
value|((b)->opt.cfg)
end_define

begin_define
define|#
directive|define
name|ct_get_subchan
parameter_list|(
name|b
parameter_list|)
value|((b)->opt.s2)
end_define

begin_define
define|#
directive|define
name|ct_get_higain
parameter_list|(
name|c
parameter_list|)
value|((c)->gopt.higain)
end_define

begin_define
define|#
directive|define
name|ct_get_phony
parameter_list|(
name|c
parameter_list|)
value|((c)->gopt.phony)
end_define

begin_function_decl
name|int
name|ct_get_clk
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|ct_get_ts
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_start_chan
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|ct_buf_t
modifier|*
name|cb
parameter_list|,
name|unsigned
name|long
name|phys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_enable_receive
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_enable_transmit
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_receive_enabled
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_transmit_enabled
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_baud
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|long
name|baud
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|ct_get_baud
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_dpll
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_dpll
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_nrzi
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_nrzi
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_loop
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_loop
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_invtxc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_invtxc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_set_invrxc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_get_invrxc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_buf_free
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ct_send_packet
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|,
name|void
modifier|*
name|attachment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_start_scc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|char
modifier|*
name|rxbuf
parameter_list|,
name|char
modifier|*
name|txbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sccrx_check
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scc_read
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scc_write
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
modifier|*
name|d
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scc_read_byte
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|scc_write_byte
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|unsigned
name|char
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_register_transmit
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ct_chan_t
modifier|*
parameter_list|,
name|void
modifier|*
name|attachment
parameter_list|,
name|int
name|len
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_register_receive
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ct_chan_t
modifier|*
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_register_error
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|int
name|data
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_register_modem
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ct_register_scc
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|ct_chan_t
modifier|*
name|c
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

end_unit

