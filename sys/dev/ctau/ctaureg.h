begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Defines for Cronyx-Tau adapter, based on Hitachi HD64570 controller.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: ctaureg.h,v 1.1.2.1 2003/11/12 17:16:10 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Chip register address, B is chip base port, R is chip register number.  */
end_comment

begin_define
define|#
directive|define
name|R
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|((b) | 0x8000 | (((r)<<6& 0x3c00) | ((r)& 0xf)))
end_define

begin_comment
comment|/*  * Interface board registers, R is register number 0..7.  */
end_comment

begin_define
define|#
directive|define
name|GR
parameter_list|(
name|p
parameter_list|,
name|r
parameter_list|)
value|((p) | 0x0010 | (r)<<1)
end_define

begin_comment
comment|/*------------------------------------------------------------  * Basic Tau model.  */
end_comment

begin_define
define|#
directive|define
name|BSR0
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_comment
comment|/* board status register 0, read only */
end_comment

begin_define
define|#
directive|define
name|BSR1
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x2000)
end_define

begin_comment
comment|/* board status register 1, read only */
end_comment

begin_define
define|#
directive|define
name|BSR2
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x4010)
end_define

begin_comment
comment|/* board status register 2, read only */
end_comment

begin_define
define|#
directive|define
name|BSR3
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x4000)
end_define

begin_comment
comment|/* board status register 3, read only */
end_comment

begin_define
define|#
directive|define
name|BCR0
parameter_list|(
name|p
parameter_list|)
value|(p)
end_define

begin_comment
comment|/* board command register 0, write only */
end_comment

begin_define
define|#
directive|define
name|BCR1
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x2000)
end_define

begin_comment
comment|/* board command register 1, write only */
end_comment

begin_define
define|#
directive|define
name|BCR2
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x4010)
end_define

begin_comment
comment|/* board command register 2, write only */
end_comment

begin_define
define|#
directive|define
name|BCR3
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x4000)
end_define

begin_comment
comment|/* board command register 3, write only */
end_comment

begin_define
define|#
directive|define
name|IACK
parameter_list|(
name|p
parameter_list|)
value|((p) | 0x6000)
end_define

begin_comment
comment|/* interrupt acknowledge register, ro */
end_comment

begin_comment
comment|/*  * Board status register 0 bits.  */
end_comment

begin_define
define|#
directive|define
name|BSR0_INTR
value|0x01
end_define

begin_comment
comment|/* interrupt pending flag */
end_comment

begin_define
define|#
directive|define
name|BSR0_HDINT
value|0x02
end_define

begin_comment
comment|/* HD64570 interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BSR0_GINT
value|0x04
end_define

begin_comment
comment|/* interface board interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BSR0_RDYERR
value|0x10
end_define

begin_comment
comment|/* HD64570 reg.i/o error - not ready */
end_comment

begin_define
define|#
directive|define
name|BSR0_TE1
value|0x02
end_define

begin_comment
comment|/* 0 - E1 daughter board installed */
end_comment

begin_define
define|#
directive|define
name|BSR0_T703
value|0x04
end_define

begin_comment
comment|/* 0 - G.703 daughter board installed */
end_comment

begin_comment
comment|/*  * Board status register 1 bits.  */
end_comment

begin_define
define|#
directive|define
name|BSR1_DSR0
value|0x01
end_define

begin_comment
comment|/* DSR from channel 0 */
end_comment

begin_define
define|#
directive|define
name|BSR1_DSR1
value|0x02
end_define

begin_comment
comment|/* DSR from channel 1 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH0_CABLE
value|0x0c
end_define

begin_comment
comment|/* channel 0 cable type mask */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH0_V35
value|0x0c
end_define

begin_comment
comment|/* channel 0 is V.35 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH0_RS232
value|0x08
end_define

begin_comment
comment|/* channel 0 is RS-232 or not connected */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH0_X21
value|0x04
end_define

begin_comment
comment|/* channel 0 is X.21 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH0_RS530
value|0x00
end_define

begin_comment
comment|/* channel 0 is RS-530 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH1_CABLE
value|0x30
end_define

begin_comment
comment|/* channel 1 cable type mask */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH1_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BSR1_CH1_V35
value|0x0c
end_define

begin_comment
comment|/* channel 1 is V.35 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH1_RS232
value|0x08
end_define

begin_comment
comment|/* channel 1 is RS-232 or not connected */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH1_X21
value|0x04
end_define

begin_comment
comment|/* channel 1 is X.21 */
end_comment

begin_define
define|#
directive|define
name|BSR1_CH1_RS530
value|0x00
end_define

begin_comment
comment|/* channel 1 is RS-530 */
end_comment

begin_comment
comment|/*  * Board status register 2 bits.  */
end_comment

begin_define
define|#
directive|define
name|BSR2_GINT0
value|0x08
end_define

begin_comment
comment|/* interface board chan0 interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BSR2_GINT1
value|0x40
end_define

begin_comment
comment|/* interface board chan1 interrupt pending */
end_comment

begin_define
define|#
directive|define
name|BSR2_LERR
value|0x80
end_define

begin_comment
comment|/* firmware download error signal */
end_comment

begin_comment
comment|/*  * Board status register 3 bits.  */
end_comment

begin_define
define|#
directive|define
name|BSR3_IB
value|0x08
end_define

begin_comment
comment|/* identification bit */
end_comment

begin_define
define|#
directive|define
name|BSR3_NSTATUS
value|0x10
end_define

begin_comment
comment|/* firmware download status */
end_comment

begin_define
define|#
directive|define
name|BSR3_CONF_DN
value|0x20
end_define

begin_comment
comment|/* firmware download done */
end_comment

begin_define
define|#
directive|define
name|BSR3_IB_NEG
value|0x40
end_define

begin_comment
comment|/* negated identification bit */
end_comment

begin_define
define|#
directive|define
name|BSR3_ZERO
value|0x80
end_define

begin_comment
comment|/* always zero */
end_comment

begin_comment
comment|/*  * Board control register 0 bits.  */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_DIS
value|0x00
end_define

begin_comment
comment|/* no interrupt generated */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_3
value|0x01
end_define

begin_comment
comment|/* select IRQ number 3 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_5
value|0x02
end_define

begin_comment
comment|/* select IRQ number 5 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_7
value|0x03
end_define

begin_comment
comment|/* select IRQ number 7 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_10
value|0x04
end_define

begin_comment
comment|/* select IRQ number 10 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_11
value|0x05
end_define

begin_comment
comment|/* select IRQ number 11 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_12
value|0x06
end_define

begin_comment
comment|/* select IRQ number 12 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_15
value|0x07
end_define

begin_comment
comment|/* select IRQ number 15 */
end_comment

begin_define
define|#
directive|define
name|BCR0_IRQ_MASK
value|0x07
end_define

begin_comment
comment|/* IRQ mask */
end_comment

begin_define
define|#
directive|define
name|BCR0_HDRUN
value|0x08
end_define

begin_comment
comment|/* inverted board reset flag */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_DIS
value|0x00
end_define

begin_comment
comment|/* no interrupt generated */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_5
value|0x10
end_define

begin_comment
comment|/* select DMA channel 5 */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_6
value|0x20
end_define

begin_comment
comment|/* select DMA channel 6 */
end_comment

begin_define
define|#
directive|define
name|BCR0_DMA_7
value|0x30
end_define

begin_comment
comment|/* select DMA channel 7 */
end_comment

begin_define
define|#
directive|define
name|BCR0_TCK
value|0x80
end_define

begin_comment
comment|/* firmware download TCK signal */
end_comment

begin_comment
comment|/*  * Board control register 1 bits.  */
end_comment

begin_define
define|#
directive|define
name|BCR1_DTR0
value|0x01
end_define

begin_comment
comment|/* channel 0 DTR enable */
end_comment

begin_define
define|#
directive|define
name|BCR1_DTR1
value|0x02
end_define

begin_comment
comment|/* channel 1 DTR enable */
end_comment

begin_define
define|#
directive|define
name|BCR1_TXCOUT0
value|0x10
end_define

begin_comment
comment|/* channel 0 TXCOUT enable */
end_comment

begin_define
define|#
directive|define
name|BCR1_TXCOUT1
value|0x20
end_define

begin_comment
comment|/* channel 1 TXCOUT enable */
end_comment

begin_define
define|#
directive|define
name|BCR1_TMS
value|0x08
end_define

begin_comment
comment|/* firmware download TMS signal */
end_comment

begin_define
define|#
directive|define
name|BCR1_TDI
value|0x80
end_define

begin_comment
comment|/* firmware download TDI signal */
end_comment

begin_define
define|#
directive|define
name|BCR1_NCONFIGI
value|0x08
end_define

begin_comment
comment|/* firmware download start */
end_comment

begin_define
define|#
directive|define
name|BCR1_DCLK
value|0x40
end_define

begin_comment
comment|/* firmware download clock */
end_comment

begin_define
define|#
directive|define
name|BCR1_1KDAT
value|0x80
end_define

begin_comment
comment|/* firmware download data */
end_comment

begin_comment
comment|/*  * Board control register 2 bits -- see ctau.h.  */
end_comment

begin_define
define|#
directive|define
name|IMVR
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_IMVR)
end_define

begin_comment
comment|/* interrupt modified vector reg. */
end_comment

begin_define
define|#
directive|define
name|ITCR
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_ITCR)
end_define

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|ISR0
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_ISR0)
end_define

begin_comment
comment|/* interrupt status register 0, ro */
end_comment

begin_define
define|#
directive|define
name|ISR1
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_ISR1)
end_define

begin_comment
comment|/* interrupt status register 1, ro */
end_comment

begin_define
define|#
directive|define
name|ISR2
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_ISR2)
end_define

begin_comment
comment|/* interrupt status register 2, ro */
end_comment

begin_define
define|#
directive|define
name|IER0
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_IER0)
end_define

begin_comment
comment|/* interrupt enable register 0 */
end_comment

begin_define
define|#
directive|define
name|IER1
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_IER1)
end_define

begin_comment
comment|/* interrupt enable register 1 */
end_comment

begin_define
define|#
directive|define
name|IER2
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_IER2)
end_define

begin_comment
comment|/* interrupt enable register 2 */
end_comment

begin_define
define|#
directive|define
name|PCR
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_PCR)
end_define

begin_comment
comment|/* DMA priority control register */
end_comment

begin_define
define|#
directive|define
name|DMER
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_DMER)
end_define

begin_comment
comment|/* DMA master enable register */
end_comment

begin_define
define|#
directive|define
name|WCRL
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_WCRL)
end_define

begin_comment
comment|/* wait control register L */
end_comment

begin_define
define|#
directive|define
name|WCRM
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_WCRM)
end_define

begin_comment
comment|/* wait control register M */
end_comment

begin_define
define|#
directive|define
name|WCRH
parameter_list|(
name|b
parameter_list|)
value|R(b,HD_WCRH)
end_define

begin_comment
comment|/* wait control register H */
end_comment

begin_comment
comment|/*------------------------------------------------------------  * Tau/E1 model.  */
end_comment

begin_define
define|#
directive|define
name|E1CFG
parameter_list|(
name|p
parameter_list|)
value|GR(p,0)
end_define

begin_comment
comment|/* control register 0, write only */
end_comment

begin_define
define|#
directive|define
name|E1SR
parameter_list|(
name|p
parameter_list|)
value|GR(p,0)
end_define

begin_comment
comment|/* status register, read only */
end_comment

begin_define
define|#
directive|define
name|E1CS2
parameter_list|(
name|p
parameter_list|)
value|GR(p,1)
end_define

begin_comment
comment|/* chip select 2/IACK, read/write */
end_comment

begin_define
define|#
directive|define
name|E1SYN
parameter_list|(
name|p
parameter_list|)
value|GR(p,3)
end_define

begin_comment
comment|/* sync mode enable, write only */
end_comment

begin_define
define|#
directive|define
name|E1CS0
parameter_list|(
name|p
parameter_list|)
value|GR(p,4)
end_define

begin_comment
comment|/* chip select 0, write only */
end_comment

begin_define
define|#
directive|define
name|E1CS1
parameter_list|(
name|p
parameter_list|)
value|GR(p,5)
end_define

begin_comment
comment|/* chip select 1, write only */
end_comment

begin_define
define|#
directive|define
name|E1DAT
parameter_list|(
name|p
parameter_list|)
value|GR(p,7)
end_define

begin_comment
comment|/* selected chip read/write */
end_comment

begin_comment
comment|/*  * Tau/E1 CS2/IACK register bits.  */
end_comment

begin_define
define|#
directive|define
name|E1CS2_IACK
value|0x08
end_define

begin_comment
comment|/* serial controller interrupt acknowledge */
end_comment

begin_define
define|#
directive|define
name|E1CS2_SCC
value|0x04
end_define

begin_comment
comment|/* serial controller select */
end_comment

begin_define
define|#
directive|define
name|E1CS2_AB
value|0x02
end_define

begin_comment
comment|/* serial controller A/B signal */
end_comment

begin_define
define|#
directive|define
name|E1CS2_DC
value|0x01
end_define

begin_comment
comment|/* serial controller D/C signal */
end_comment

begin_comment
comment|/*  * Tau/E1 control register bits.  */
end_comment

begin_define
define|#
directive|define
name|E1CFG_II
value|0x00
end_define

begin_comment
comment|/* configuration II */
end_comment

begin_define
define|#
directive|define
name|E1CFG_K
value|0x01
end_define

begin_comment
comment|/* configuration K */
end_comment

begin_define
define|#
directive|define
name|E1CFG_HI
value|0x02
end_define

begin_comment
comment|/* configuration HI */
end_comment

begin_define
define|#
directive|define
name|E1CFG_D
value|0x03
end_define

begin_comment
comment|/* configuration D */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK0_INT
value|0x00
end_define

begin_comment
comment|/* channel E0 transmit clock - internal */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK0_RCV
value|0x04
end_define

begin_comment
comment|/* channel E0 transmit clock - RCLK0 */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK0_RCLK1
value|0x08
end_define

begin_comment
comment|/* channel E0 transmit clock - RCLK1 */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK1_INT
value|0x00
end_define

begin_comment
comment|/* channel E1 transmit clock - internal */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK1_RCLK0
value|0x10
end_define

begin_comment
comment|/* channel E1 transmit clock - RCLK0 */
end_comment

begin_define
define|#
directive|define
name|E1CFG_CLK1_RCV
value|0x20
end_define

begin_comment
comment|/* channel E1 transmit clock - RCLK1 */
end_comment

begin_define
define|#
directive|define
name|E1CFG_LED
value|0x40
end_define

begin_comment
comment|/* LED control */
end_comment

begin_define
define|#
directive|define
name|E1CFG_GRUN
value|0x80
end_define

begin_comment
comment|/* global run flag */
end_comment

begin_comment
comment|/*  * Tau/E1 sync control register bits.  */
end_comment

begin_define
define|#
directive|define
name|E1SYN_ENS0
value|0x01
end_define

begin_comment
comment|/* enable channel 0 sync mode */
end_comment

begin_define
define|#
directive|define
name|E1SYN_ENS1
value|0x02
end_define

begin_comment
comment|/* enable channel 1 sync mode */
end_comment

begin_comment
comment|/*  * Tau/E1 status register bits.  */
end_comment

begin_define
define|#
directive|define
name|E1SR_E0_IRQ0
value|0x01
end_define

begin_comment
comment|/* E0 controller interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|E1SR_E0_IRQ1
value|0x02
end_define

begin_comment
comment|/* E0 controller interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|E1SR_E1_IRQ0
value|0x04
end_define

begin_comment
comment|/* E1 controller interrupt 0 */
end_comment

begin_define
define|#
directive|define
name|E1SR_E1_IRQ1
value|0x08
end_define

begin_comment
comment|/* E1 controller interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|E1SR_SCC_IRQ
value|0x10
end_define

begin_comment
comment|/* serial controller interrupt */
end_comment

begin_define
define|#
directive|define
name|E1SR_TP0
value|0x20
end_define

begin_comment
comment|/* channel 0 is twisted pair */
end_comment

begin_define
define|#
directive|define
name|E1SR_TP1
value|0x40
end_define

begin_comment
comment|/* channel 1 is twisted pair */
end_comment

begin_define
define|#
directive|define
name|E1SR_REV
value|0x80
end_define

begin_comment
comment|/* Tau/E1 revision */
end_comment

begin_comment
comment|/*  * Tau/E1 serial memory register bits.  */
end_comment

begin_comment
comment|/*------------------------------------------------------------  * Tau/G.703 model.  */
end_comment

begin_define
define|#
directive|define
name|GLCR0
parameter_list|(
name|p
parameter_list|)
value|GR(p,3)
end_define

begin_comment
comment|/* line control register 0, write only */
end_comment

begin_define
define|#
directive|define
name|GMD0
parameter_list|(
name|p
parameter_list|)
value|GR(p,4)
end_define

begin_comment
comment|/* mode register 0, write only */
end_comment

begin_define
define|#
directive|define
name|GMD1
parameter_list|(
name|p
parameter_list|)
value|GR(p,5)
end_define

begin_comment
comment|/* mode register 1, write only */
end_comment

begin_define
define|#
directive|define
name|GMD2
parameter_list|(
name|p
parameter_list|)
value|GR(p,6)
end_define

begin_comment
comment|/* mode register 2, write only */
end_comment

begin_define
define|#
directive|define
name|GLCR1
parameter_list|(
name|p
parameter_list|)
value|GR(p,7)
end_define

begin_comment
comment|/* line control register 1, write only */
end_comment

begin_define
define|#
directive|define
name|GERR
parameter_list|(
name|p
parameter_list|)
value|GR(p,0)
end_define

begin_comment
comment|/* error register, read/write */
end_comment

begin_define
define|#
directive|define
name|GLQ
parameter_list|(
name|p
parameter_list|)
value|GR(p,1)
end_define

begin_comment
comment|/* line quality register, read only */
end_comment

begin_define
define|#
directive|define
name|GLDR
parameter_list|(
name|p
parameter_list|)
value|GR(p,2)
end_define

begin_comment
comment|/* loop detect request, read only */
end_comment

begin_comment
comment|/*  * Tau/G.703 mode register 0/1 bits.  */
end_comment

begin_define
define|#
directive|define
name|GMD_2048
value|0x00
end_define

begin_comment
comment|/* 2048 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_1024
value|0x02
end_define

begin_comment
comment|/* 1024 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_512
value|0x03
end_define

begin_comment
comment|/* 512 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_256
value|0x04
end_define

begin_comment
comment|/* 256 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_128
value|0x05
end_define

begin_comment
comment|/* 128 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_64
value|0x06
end_define

begin_comment
comment|/* 64 kbit/sec */
end_comment

begin_define
define|#
directive|define
name|GMD_RSYNC
value|0x08
end_define

begin_comment
comment|/* receive synchronization */
end_comment

begin_define
define|#
directive|define
name|GMD_PCE_PCM2
value|0x10
end_define

begin_comment
comment|/* precoder enable, mode PCM2 */
end_comment

begin_define
define|#
directive|define
name|GMD_PCE_PCM2D
value|0x20
end_define

begin_comment
comment|/* precoder enable, mode PCM2D */
end_comment

begin_define
define|#
directive|define
name|GMD0_SDI
value|0x40
end_define

begin_comment
comment|/* serial data input */
end_comment

begin_define
define|#
directive|define
name|GMD0_SCLK
value|0x80
end_define

begin_comment
comment|/* serial data clock */
end_comment

begin_define
define|#
directive|define
name|GMD1_NCS0
value|0x40
end_define

begin_comment
comment|/* chip select 0 inverted */
end_comment

begin_define
define|#
directive|define
name|GMD1_NCS1
value|0x80
end_define

begin_comment
comment|/* chip select 1 inverted */
end_comment

begin_comment
comment|/*  * Tau/G.703 mode register 2 bits.  */
end_comment

begin_define
define|#
directive|define
name|GMD2_SERIAL
value|0x01
end_define

begin_comment
comment|/* channel 1 serial interface V.35/RS-232/etc */
end_comment

begin_define
define|#
directive|define
name|GMD2_LED
value|0x02
end_define

begin_comment
comment|/* LED control */
end_comment

begin_define
define|#
directive|define
name|GMD2_RAW0
value|0x04
end_define

begin_comment
comment|/* channel 0 raw mode (byte-sync) */
end_comment

begin_define
define|#
directive|define
name|GMD2_RAW1
value|0x08
end_define

begin_comment
comment|/* channel 1 raw mode (byte-sync) */
end_comment

begin_comment
comment|/*  * Tau/G.703 interrupt status register bits.  */
end_comment

begin_define
define|#
directive|define
name|GERR_BPV0
value|0x01
end_define

begin_comment
comment|/* channel 0 bipolar violation */
end_comment

begin_define
define|#
directive|define
name|GERR_ERR0
value|0x02
end_define

begin_comment
comment|/* channel 0 test error */
end_comment

begin_define
define|#
directive|define
name|GERR_BPV1
value|0x04
end_define

begin_comment
comment|/* channel 1 bipolar violation */
end_comment

begin_define
define|#
directive|define
name|GERR_ERR1
value|0x08
end_define

begin_comment
comment|/* channel 1 test error */
end_comment

begin_comment
comment|/*  * Tau/G.703 line quality register bits.  */
end_comment

begin_define
define|#
directive|define
name|GLQ_MASK
value|0x03
end_define

begin_comment
comment|/* channel 0 mask */
end_comment

begin_define
define|#
directive|define
name|GLQ_SHIFT
value|2
end_define

begin_comment
comment|/* channel 1 shift */
end_comment

begin_define
define|#
directive|define
name|GLQ_DB0
value|0x00
end_define

begin_comment
comment|/* channel 0 level 0.0 dB */
end_comment

begin_define
define|#
directive|define
name|GLQ_DB95
value|0x01
end_define

begin_comment
comment|/* channel 0 level -9.5 dB */
end_comment

begin_define
define|#
directive|define
name|GLQ_DB195
value|0x02
end_define

begin_comment
comment|/* channel 0 level -19.5 dB */
end_comment

begin_define
define|#
directive|define
name|GLQ_DB285
value|0x03
end_define

begin_comment
comment|/* channel 0 level -28.5 dB */
end_comment

begin_comment
comment|/*  * Tau/G.703 serial data output register bits.  */
end_comment

begin_define
define|#
directive|define
name|GLDR_C0
value|0x01
end_define

begin_comment
comment|/* chip 0 serial data output */
end_comment

begin_define
define|#
directive|define
name|GLDR_LREQ0
value|0x02
end_define

begin_comment
comment|/* channel 0 remote loop request */
end_comment

begin_define
define|#
directive|define
name|GLDR_C1
value|0x04
end_define

begin_comment
comment|/* chip 1 serial data output */
end_comment

begin_define
define|#
directive|define
name|GLDR_LREQ1
value|0x08
end_define

begin_comment
comment|/* channel 1 remote loop request */
end_comment

begin_comment
comment|/*  * Tau/G.703 line control register 0/1 bits.  */
end_comment

begin_define
define|#
directive|define
name|GLCR_RENABLE
value|0x00
end_define

begin_comment
comment|/* normal mode, auto remote loop enabled */
end_comment

begin_define
define|#
directive|define
name|GLCR_RDISABLE
value|0x01
end_define

begin_comment
comment|/* normal mode, auto remote loop disabled */
end_comment

begin_define
define|#
directive|define
name|GLCR_RREFUSE
value|0x02
end_define

begin_comment
comment|/* send the remote loop request sequence */
end_comment

begin_define
define|#
directive|define
name|GLCR_RREQUEST
value|0x03
end_define

begin_comment
comment|/* send the remote loop refuse sequence */
end_comment

end_unit

