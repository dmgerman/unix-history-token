begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_SE_SEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_SE_SEREG_H_
end_define

begin_define
define|#
directive|define
name|SE_DIV
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|(((m)<< 6) | ((n) - 1))
end_define

begin_define
define|#
directive|define
name|SE_DIV_9600
value|SE_DIV(48, 2)
end_define

begin_define
define|#
directive|define
name|SE_DIV_19200
value|SE_DIV(48, 1)
end_define

begin_define
define|#
directive|define
name|SE_DIV_38400
value|SE_DIV(24, 1)
end_define

begin_define
define|#
directive|define
name|SE_DIV_115200
value|SE_DIV(8, 1)
end_define

begin_define
define|#
directive|define
name|SE_CHA
value|0x0
end_define

begin_comment
comment|/* channel a offset */
end_comment

begin_define
define|#
directive|define
name|SE_CHB
value|0x40
end_define

begin_comment
comment|/* channel b offset */
end_comment

begin_define
define|#
directive|define
name|SE_RFIFO
value|0x0
end_define

begin_comment
comment|/* receive fifo */
end_comment

begin_define
define|#
directive|define
name|SE_XFIFO
value|0x0
end_define

begin_comment
comment|/* transmit fifo */
end_comment

begin_define
define|#
directive|define
name|SE_STAR
value|0x20
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|STAR_CTS
value|0x2
end_define

begin_comment
comment|/*  clear to send state */
end_comment

begin_define
define|#
directive|define
name|STAR_CEC
value|0x4
end_define

begin_comment
comment|/*  command executing */
end_comment

begin_define
define|#
directive|define
name|STAR_TEC
value|0x8
end_define

begin_comment
comment|/*  tic executing */
end_comment

begin_define
define|#
directive|define
name|STAR_FCS
value|0x10
end_define

begin_comment
comment|/*  flow control status */
end_comment

begin_define
define|#
directive|define
name|STAR_RFNE
value|0x20
end_define

begin_comment
comment|/*  receive fifo not empty */
end_comment

begin_define
define|#
directive|define
name|STAR_XFW
value|0x40
end_define

begin_comment
comment|/*  transmit fifo write enable */
end_comment

begin_define
define|#
directive|define
name|STAR_XDOV
value|0x80
end_define

begin_comment
comment|/*  transmit data overflow */
end_comment

begin_define
define|#
directive|define
name|SE_CMDR
value|0x20
end_define

begin_comment
comment|/* command register */
end_comment

begin_define
define|#
directive|define
name|CMDR_XRES
value|0x1
end_define

begin_comment
comment|/*  transmitter reset */
end_comment

begin_define
define|#
directive|define
name|CMDR_XF
value|0x8
end_define

begin_comment
comment|/*  transmit frame */
end_comment

begin_define
define|#
directive|define
name|CMDR_STI
value|0x10
end_define

begin_comment
comment|/*  start timer */
end_comment

begin_define
define|#
directive|define
name|CMDR_RFRD
value|0x20
end_define

begin_comment
comment|/*  receive fifo read enable */
end_comment

begin_define
define|#
directive|define
name|CMDR_RRES
value|0x40
end_define

begin_comment
comment|/*  reveiver reset */
end_comment

begin_define
define|#
directive|define
name|CMDR_RMC
value|0x80
end_define

begin_comment
comment|/*  receive message complete */
end_comment

begin_define
define|#
directive|define
name|SE_MODE
value|0x22
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|MODE_TLP
value|0x1
end_define

begin_comment
comment|/*  test loop */
end_comment

begin_define
define|#
directive|define
name|MODE_TRS
value|0x2
end_define

begin_comment
comment|/*  timer resolution */
end_comment

begin_define
define|#
directive|define
name|MODE_RTS
value|0x4
end_define

begin_comment
comment|/*  request to send */
end_comment

begin_define
define|#
directive|define
name|MODE_RAC
value|0x8
end_define

begin_comment
comment|/*  receiver active */
end_comment

begin_define
define|#
directive|define
name|MODE_FLON
value|0x10
end_define

begin_comment
comment|/*  flow control on */
end_comment

begin_define
define|#
directive|define
name|MODE_FCTS
value|0x20
end_define

begin_comment
comment|/*  flow control using cts */
end_comment

begin_define
define|#
directive|define
name|MODE_FRTS
value|0x40
end_define

begin_comment
comment|/*  flow control using rts */
end_comment

begin_define
define|#
directive|define
name|SE_TIMR
value|0x23
end_define

begin_comment
comment|/* timer register */
end_comment

begin_define
define|#
directive|define
name|SE_XON
value|0x24
end_define

begin_comment
comment|/* xon character */
end_comment

begin_define
define|#
directive|define
name|SE_XOFF
value|0x25
end_define

begin_comment
comment|/* xoff character */
end_comment

begin_define
define|#
directive|define
name|SE_TCR
value|0x26
end_define

begin_comment
comment|/* transmit character register */
end_comment

begin_define
define|#
directive|define
name|SE_DAFO
value|0x27
end_define

begin_comment
comment|/* data format */
end_comment

begin_define
define|#
directive|define
name|DAFO_CHL
value|0x2
end_define

begin_comment
comment|/*  character length */
end_comment

begin_define
define|#
directive|define
name|DAFO_CHL_8
value|0x0
end_define

begin_comment
comment|/*   8 bits */
end_comment

begin_define
define|#
directive|define
name|DAFO_CHL_7
value|0x1
end_define

begin_comment
comment|/*   7 bits */
end_comment

begin_define
define|#
directive|define
name|DAFO_CHL_6
value|0x2
end_define

begin_comment
comment|/*   6 bits */
end_comment

begin_define
define|#
directive|define
name|DAFO_CHL_5
value|0x3
end_define

begin_comment
comment|/*   5 bits */
end_comment

begin_define
define|#
directive|define
name|DAFO_PARE
value|0x4
end_define

begin_comment
comment|/*  parity enable */
end_comment

begin_define
define|#
directive|define
name|DAFO_PAR
value|0x18
end_define

begin_comment
comment|/*  parity format */
end_comment

begin_define
define|#
directive|define
name|DAFO_STOP
value|0x20
end_define

begin_comment
comment|/*  stop bit */
end_comment

begin_define
define|#
directive|define
name|DAFO_XBRK
value|0x40
end_define

begin_comment
comment|/*  transmit break */
end_comment

begin_define
define|#
directive|define
name|SE_RFC
value|0x28
end_define

begin_comment
comment|/* rfifo control register */
end_comment

begin_define
define|#
directive|define
name|RFC_TCDE
value|0x1
end_define

begin_comment
comment|/*  termination character detection enable */
end_comment

begin_define
define|#
directive|define
name|RFC_RFTH
value|0xc
end_define

begin_comment
comment|/*  rfifo threshold level */
end_comment

begin_define
define|#
directive|define
name|RFC_RFTH_2
value|0x0
end_define

begin_comment
comment|/*   2 bytes */
end_comment

begin_define
define|#
directive|define
name|RFC_RFTH_4
value|0x4
end_define

begin_comment
comment|/*   4 bytes */
end_comment

begin_define
define|#
directive|define
name|RFC_RFTH_16
value|0x8
end_define

begin_comment
comment|/*   16 bytes */
end_comment

begin_define
define|#
directive|define
name|RFC_RFTH_32
value|0xc
end_define

begin_comment
comment|/*   32 bytes */
end_comment

begin_define
define|#
directive|define
name|RFC_RFDF
value|0x10
end_define

begin_comment
comment|/*  rfifo data format */
end_comment

begin_define
define|#
directive|define
name|RFC_DXS
value|0x20
end_define

begin_comment
comment|/*  disable storage of xon/xoff characters */
end_comment

begin_define
define|#
directive|define
name|RFC_DPS
value|0x40
end_define

begin_comment
comment|/*  disable parity storage */
end_comment

begin_define
define|#
directive|define
name|SE_RBCL
value|0x2a
end_define

begin_comment
comment|/* receive byte count low */
end_comment

begin_define
define|#
directive|define
name|SE_XBCL
value|0x2a
end_define

begin_comment
comment|/* transmit byte count low */
end_comment

begin_define
define|#
directive|define
name|SE_RBCH
value|0x2b
end_define

begin_comment
comment|/* receive byte count high */
end_comment

begin_define
define|#
directive|define
name|SE_XBCH
value|0x2b
end_define

begin_comment
comment|/* transmit byte count high */
end_comment

begin_define
define|#
directive|define
name|SE_CCR0
value|0x2c
end_define

begin_comment
comment|/* channel configuration register 0 */
end_comment

begin_define
define|#
directive|define
name|CCR0_SM
value|0x3
end_define

begin_comment
comment|/*  serial mode */
end_comment

begin_define
define|#
directive|define
name|CCR0_SM_HDLC
value|0x0
end_define

begin_comment
comment|/*   hdlc/sdlc mode */
end_comment

begin_define
define|#
directive|define
name|CCR0_SM_SDLC
value|0x1
end_define

begin_comment
comment|/*   sdlc loop mode */
end_comment

begin_define
define|#
directive|define
name|CCR0_SM_BISYNC
value|0x2
end_define

begin_comment
comment|/*   bisync mode */
end_comment

begin_define
define|#
directive|define
name|CCR0_SM_ASYNC
value|0x3
end_define

begin_comment
comment|/*   async mode */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC
value|0x1c
end_define

begin_comment
comment|/*  serial configuration */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC_NRZ
value|0x0
end_define

begin_comment
comment|/*   nrz data encoding */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC_NRZI
value|0x2
end_define

begin_comment
comment|/*   nrzi data encoding */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC_FM0
value|0x4
end_define

begin_comment
comment|/*   fm0 data encoding */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC_FM1
value|0x5
end_define

begin_comment
comment|/*   fm1 data encoding */
end_comment

begin_define
define|#
directive|define
name|CCR0_SC_MCHSTR
value|0x6
end_define

begin_comment
comment|/*   manchester data encoding */
end_comment

begin_define
define|#
directive|define
name|CCR0_MCE
value|0x40
end_define

begin_comment
comment|/*  master clock enable */
end_comment

begin_define
define|#
directive|define
name|CCR0_PU
value|0x80
end_define

begin_comment
comment|/*  power up */
end_comment

begin_define
define|#
directive|define
name|SE_CCR1
value|0x2d
end_define

begin_comment
comment|/* channel configuration register 1 */
end_comment

begin_define
define|#
directive|define
name|CCR1_CM
value|0x7
end_define

begin_comment
comment|/*  clock mode */
end_comment

begin_define
define|#
directive|define
name|CCR1_CM_7
value|0x7
end_define

begin_comment
comment|/*   clock mode 7 */
end_comment

begin_define
define|#
directive|define
name|CCR1_BCR
value|0x8
end_define

begin_comment
comment|/*  bit clock rate */
end_comment

begin_define
define|#
directive|define
name|CCR1_ODS
value|0x10
end_define

begin_comment
comment|/*  output driver select */
end_comment

begin_define
define|#
directive|define
name|SE_CCR2
value|0x2e
end_define

begin_comment
comment|/* channel configuration register 2 */
end_comment

begin_define
define|#
directive|define
name|CCR2_DIV
value|0x1
end_define

begin_comment
comment|/*  data inversion */
end_comment

begin_define
define|#
directive|define
name|CCR2_RWX
value|0x4
end_define

begin_comment
comment|/*  read/write exchange */
end_comment

begin_define
define|#
directive|define
name|CCR2_TOE
value|0x8
end_define

begin_comment
comment|/*  txclk ouput enable */
end_comment

begin_define
define|#
directive|define
name|CCR2_SSEL
value|0x10
end_define

begin_comment
comment|/*  clock source select */
end_comment

begin_define
define|#
directive|define
name|CCR2_BDF
value|0x20
end_define

begin_comment
comment|/*  baud rate division factor */
end_comment

begin_define
define|#
directive|define
name|CCR2_BR8
value|0x40
end_define

begin_comment
comment|/*  baud rate 8 */
end_comment

begin_define
define|#
directive|define
name|CCR2_BR9
value|0x80
end_define

begin_comment
comment|/*  baud rate 9 */
end_comment

begin_define
define|#
directive|define
name|CCR2_RCS0
value|0x10
end_define

begin_comment
comment|/*  receive clock shift 0 (5) */
end_comment

begin_define
define|#
directive|define
name|CCR2_XCS0
value|0x20
end_define

begin_comment
comment|/*  transmit clock shift 0 (5) */
end_comment

begin_define
define|#
directive|define
name|CCR2_SOC0
value|0x40
end_define

begin_comment
comment|/*  special output control 0 (0a, 1, 4, 5) */
end_comment

begin_define
define|#
directive|define
name|CCR2_SOC1
value|0x80
end_define

begin_comment
comment|/*  special output control 1 (0a, 1, 4, 5) */
end_comment

begin_define
define|#
directive|define
name|SE_CCR3
value|0x2f
end_define

begin_comment
comment|/* channel configuration register 3 */
end_comment

begin_define
define|#
directive|define
name|CCR3_PSD
value|0x1
end_define

begin_comment
comment|/*  dpll phase shift disable */
end_comment

begin_define
define|#
directive|define
name|SE_TSAX
value|0x30
end_define

begin_comment
comment|/* transmit timeslot assignment register */
end_comment

begin_define
define|#
directive|define
name|SE_TSAR
value|0x31
end_define

begin_comment
comment|/* receive timeslot assignment register */
end_comment

begin_define
define|#
directive|define
name|SE_XCCR
value|0x32
end_define

begin_comment
comment|/* transmit channel capacity register */
end_comment

begin_define
define|#
directive|define
name|SE_RCCR
value|0x33
end_define

begin_comment
comment|/* receive channel capacity register */
end_comment

begin_define
define|#
directive|define
name|SE_VSTR
value|0x34
end_define

begin_comment
comment|/* version status register */
end_comment

begin_define
define|#
directive|define
name|VSTR_VN
value|0xf
end_define

begin_comment
comment|/*  version number 0 */
end_comment

begin_define
define|#
directive|define
name|VSTR_DPLA
value|0x40
end_define

begin_comment
comment|/*  dpll asynchronous */
end_comment

begin_define
define|#
directive|define
name|VSTR_CD
value|0x80
end_define

begin_comment
comment|/*  carrier detect */
end_comment

begin_define
define|#
directive|define
name|SE_BGR
value|0x34
end_define

begin_comment
comment|/* baud rate generator register */
end_comment

begin_define
define|#
directive|define
name|SE_TIC
value|0x35
end_define

begin_comment
comment|/* trasmit immediate character */
end_comment

begin_define
define|#
directive|define
name|SE_MXN
value|0x36
end_define

begin_comment
comment|/* mask xon character */
end_comment

begin_define
define|#
directive|define
name|SE_MXF
value|0x37
end_define

begin_comment
comment|/* mask xoff character */
end_comment

begin_define
define|#
directive|define
name|SE_GIS
value|0x38
end_define

begin_comment
comment|/* global interrupt status */
end_comment

begin_define
define|#
directive|define
name|GIS_ISB0
value|0x1
end_define

begin_comment
comment|/*  interrupt status channel B 0 */
end_comment

begin_define
define|#
directive|define
name|GIS_ISB1
value|0x2
end_define

begin_comment
comment|/*  interrupt status channel B 1 */
end_comment

begin_define
define|#
directive|define
name|GIS_ISA0
value|0x4
end_define

begin_comment
comment|/*  interrupt status channel A 0 */
end_comment

begin_define
define|#
directive|define
name|GIS_ISA1
value|0x8
end_define

begin_comment
comment|/*  interrupt status channel A 1 */
end_comment

begin_define
define|#
directive|define
name|GIS_PI
value|0x80
end_define

begin_comment
comment|/*  univerisal port interrupt */
end_comment

begin_define
define|#
directive|define
name|SE_IVA
value|0x38
end_define

begin_comment
comment|/* interrupt vector address */
end_comment

begin_define
define|#
directive|define
name|SE_IPC
value|0x39
end_define

begin_comment
comment|/* interrupt port configuration */
end_comment

begin_define
define|#
directive|define
name|IPC_IC0
value|0x1
end_define

begin_comment
comment|/*  interrupt configuration 0 */
end_comment

begin_define
define|#
directive|define
name|IPC_IC1
value|0x2
end_define

begin_comment
comment|/*  interrupt configuration 1 */
end_comment

begin_define
define|#
directive|define
name|IPC_CASM
value|0x4
end_define

begin_comment
comment|/*  cascading mode */
end_comment

begin_define
define|#
directive|define
name|IPC_SLA0
value|0x8
end_define

begin_comment
comment|/*  slave address 0 */
end_comment

begin_define
define|#
directive|define
name|IPC_SLA1
value|0x10
end_define

begin_comment
comment|/*  slave address 1 */
end_comment

begin_define
define|#
directive|define
name|IPC_VIS
value|0x80
end_define

begin_comment
comment|/*  masked interrupts visible */
end_comment

begin_define
define|#
directive|define
name|SE_ISR0
value|0x3a
end_define

begin_comment
comment|/* interrupt status 0 */
end_comment

begin_define
define|#
directive|define
name|ISR0_RPF
value|0x1
end_define

begin_comment
comment|/*  receive pool full */
end_comment

begin_define
define|#
directive|define
name|ISR0_RFO
value|0x2
end_define

begin_comment
comment|/*  receive frame overflow */
end_comment

begin_define
define|#
directive|define
name|ISR0_CDSC
value|0x4
end_define

begin_comment
comment|/*  carrier detect status change */
end_comment

begin_define
define|#
directive|define
name|ISR0_PLLA
value|0x8
end_define

begin_comment
comment|/*  dpll asynchronous */
end_comment

begin_define
define|#
directive|define
name|ISR0_FERR
value|0x10
end_define

begin_comment
comment|/*  framing error */
end_comment

begin_define
define|#
directive|define
name|ISR0_PERR
value|0x20
end_define

begin_comment
comment|/*  parity error */
end_comment

begin_define
define|#
directive|define
name|ISR0_TIME
value|0x40
end_define

begin_comment
comment|/*  time out */
end_comment

begin_define
define|#
directive|define
name|ISR0_TCD
value|0x80
end_define

begin_comment
comment|/*  termination character detected */
end_comment

begin_define
define|#
directive|define
name|SE_IMR0
value|0x3a
end_define

begin_comment
comment|/* interrupt mask 0 */
end_comment

begin_define
define|#
directive|define
name|SE_ISR1
value|0x3b
end_define

begin_comment
comment|/* interrupt status 1 */
end_comment

begin_define
define|#
directive|define
name|ISR1_XPR
value|0x1
end_define

begin_comment
comment|/*  transmit pool ready */
end_comment

begin_define
define|#
directive|define
name|ISR1_XON
value|0x2
end_define

begin_comment
comment|/*  transmit message repeat */
end_comment

begin_define
define|#
directive|define
name|ISR1_CSC
value|0x4
end_define

begin_comment
comment|/*  clear to send status change */
end_comment

begin_define
define|#
directive|define
name|ISR1_TIN
value|0x8
end_define

begin_comment
comment|/*  timer interrupt */
end_comment

begin_define
define|#
directive|define
name|ISR1_XOFF
value|0x10
end_define

begin_comment
comment|/*  xoff character detected */
end_comment

begin_define
define|#
directive|define
name|ISR1_ALLS
value|0x20
end_define

begin_comment
comment|/*  all sent */
end_comment

begin_define
define|#
directive|define
name|ISR1_BRKT
value|0x40
end_define

begin_comment
comment|/*  break terminated */
end_comment

begin_define
define|#
directive|define
name|ISR1_BRK
value|0x80
end_define

begin_comment
comment|/*  break */
end_comment

begin_define
define|#
directive|define
name|SE_IMR1
value|0x3b
end_define

begin_comment
comment|/* interrupt mask 1 */
end_comment

begin_define
define|#
directive|define
name|SE_PVR
value|0x3c
end_define

begin_comment
comment|/* port value register */
end_comment

begin_define
define|#
directive|define
name|SE_PIS
value|0x3d
end_define

begin_comment
comment|/* port interrupt status */
end_comment

begin_define
define|#
directive|define
name|SE_PIM
value|0x3d
end_define

begin_comment
comment|/* port interrupt mask */
end_comment

begin_define
define|#
directive|define
name|SE_PCR
value|0x3e
end_define

begin_comment
comment|/* port configuration register */
end_comment

begin_define
define|#
directive|define
name|SE_CCR4
value|0x3f
end_define

begin_comment
comment|/* channel configuration register 4 */
end_comment

begin_define
define|#
directive|define
name|CCR4_ICD
value|0x10
end_define

begin_comment
comment|/*  invert polarity of carrier detect signal */
end_comment

begin_define
define|#
directive|define
name|CCR4_TST1
value|0x20
end_define

begin_comment
comment|/*  test pin */
end_comment

begin_define
define|#
directive|define
name|CCR4_EBRG
value|0x40
end_define

begin_comment
comment|/*  enhanced baud rate generator mode */
end_comment

begin_define
define|#
directive|define
name|CCR4_MCK4
value|0x80
end_define

begin_comment
comment|/*  master clock divide by 4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

