begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * cyclades cyclom-y serial driver  *	Andrew Herbert<andrew@werple.apana.org.au>, 17 August 1993  *  * Copyright (c) 1993 Andrew Herbert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name Andrew Herbert may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Definitions for Cirrus Logic CD1400 serial/parallel chips.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_NO_OF_CHANNELS
value|4
end_define

begin_comment
comment|/* 4 serial channels per chip */
end_comment

begin_define
define|#
directive|define
name|CD1400_RX_FIFO_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|CD1400_TX_FIFO_SIZE
value|12
end_define

begin_comment
comment|/*  * Global registers.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_GFRCR
value|0x40
end_define

begin_comment
comment|/* global firmware revision code */
end_comment

begin_define
define|#
directive|define
name|CD1400_CAR
value|0x68
end_define

begin_comment
comment|/* channel access */
end_comment

begin_define
define|#
directive|define
name|CD1400_CAR_CHAN
value|(3<<0)
end_define

begin_comment
comment|/* channel select */
end_comment

begin_define
define|#
directive|define
name|CD1400_GCR
value|0x4B
end_define

begin_comment
comment|/* global configuration */
end_comment

begin_define
define|#
directive|define
name|CD1400_GCR_PARALLEL
value|(1<<7)
end_define

begin_comment
comment|/* channel 0 is parallel */
end_comment

begin_define
define|#
directive|define
name|CD1400_SVRR
value|0x67
end_define

begin_comment
comment|/* service request */
end_comment

begin_define
define|#
directive|define
name|CD1400_SVRR_MDMCH
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|CD1400_SVRR_TXRDY
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CD1400_SVRR_RXRDY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_RICR
value|0x44
end_define

begin_comment
comment|/* receive interrupting channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_TICR
value|0x45
end_define

begin_comment
comment|/* transmit interrupting channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_MICR
value|0x46
end_define

begin_comment
comment|/* modem interrupting channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIR
value|0x6B
end_define

begin_comment
comment|/* receive interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIR_RDIREQ
value|(1<<7)
end_define

begin_comment
comment|/* rx service required */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIR_RBUSY
value|(1<<6)
end_define

begin_comment
comment|/* rx service in progress */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIR_CHAN
value|(3<<0)
end_define

begin_comment
comment|/* channel select */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIR
value|0x6A
end_define

begin_comment
comment|/* transmit interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIR_RDIREQ
value|(1<<7)
end_define

begin_comment
comment|/* tx service required */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIR_RBUSY
value|(1<<6)
end_define

begin_comment
comment|/* tx service in progress */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIR_CHAN
value|(3<<0)
end_define

begin_comment
comment|/* channel select */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIR
value|0x69
end_define

begin_comment
comment|/* modem interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIR_RDIREQ
value|(1<<7)
end_define

begin_comment
comment|/* modem service required */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIR_RBUSY
value|(1<<6)
end_define

begin_comment
comment|/* modem service in progress */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIR_CHAN
value|(3<<0)
end_define

begin_comment
comment|/* channel select */
end_comment

begin_define
define|#
directive|define
name|CD1400_PPR
value|0x7E
end_define

begin_comment
comment|/* prescaler period */
end_comment

begin_define
define|#
directive|define
name|CD1400_PPR_PRESCALER
value|512
end_define

begin_comment
comment|/*  * Virtual registers.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIVR
value|0x43
end_define

begin_comment
comment|/* receive interrupt vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIVR_EXCEPTION
value|(1<<2)
end_define

begin_comment
comment|/* receive exception bit */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIVR
value|0x42
end_define

begin_comment
comment|/* transmit interrupt vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIVR
value|0x41
end_define

begin_comment
comment|/* modem interrupt vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_TDR
value|0x63
end_define

begin_comment
comment|/* transmit data */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR
value|0x62
end_define

begin_comment
comment|/* receive data/status */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_TIMEOUT
value|(1<<7)
end_define

begin_comment
comment|/* rx timeout */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_SPECIAL_SHIFT
value|4
end_define

begin_comment
comment|/* rx special char shift */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_SPECIAL
value|(7<<4)
end_define

begin_comment
comment|/* rx special char */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_BREAK
value|(1<<3)
end_define

begin_comment
comment|/* rx break */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_PE
value|(1<<2)
end_define

begin_comment
comment|/* rx parity error */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_FE
value|(1<<1)
end_define

begin_comment
comment|/* rx framing error */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_OE
value|(1<<0)
end_define

begin_comment
comment|/* rx overrun error */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR
value|0x4C
end_define

begin_comment
comment|/* modem interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR_DSRd
value|(1<<7)
end_define

begin_comment
comment|/* DSR delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR_CTSd
value|(1<<6)
end_define

begin_comment
comment|/* CTS delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR_RId
value|(1<<5)
end_define

begin_comment
comment|/* RI delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR_CDd
value|(1<<4)
end_define

begin_comment
comment|/* CD delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_EOSRR
value|0x60
end_define

begin_comment
comment|/* end of service request */
end_comment

begin_comment
comment|/*  * Channel registers.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_LIVR
value|0x18
end_define

begin_comment
comment|/* local interrupt vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR
value|0x05
end_define

begin_comment
comment|/* channel control */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_CMDRESET
value|(1<<7)
end_define

begin_comment
comment|/* enables following: */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_FTF
value|(1<<1)
end_define

begin_comment
comment|/* flush tx fifo */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_FULLRESET
value|(1<<0)
end_define

begin_comment
comment|/* full reset */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_CHANRESET
value|0
end_define

begin_comment
comment|/*  current channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_CMDCORCHG
value|(1<<6)
end_define

begin_comment
comment|/* enables following: */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_COR3
value|(1<<3)
end_define

begin_comment
comment|/* COR3 changed */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_COR2
value|(1<<2)
end_define

begin_comment
comment|/* COR2 changed */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_COR1
value|(1<<1)
end_define

begin_comment
comment|/* COR1 changed */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_CMDSENDSC
value|(1<<5)
end_define

begin_comment
comment|/* enables following: */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_SC
value|(7<<0)
end_define

begin_comment
comment|/* special char 1-4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_CMDCHANCTL
value|(1<<4)
end_define

begin_comment
comment|/* enables following: */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_XMTEN
value|(1<<3)
end_define

begin_comment
comment|/* tx enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_XMTDIS
value|(1<<2)
end_define

begin_comment
comment|/* tx disable */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_RCVEN
value|(1<<1)
end_define

begin_comment
comment|/* rx enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR_RCVDIS
value|(1<<0)
end_define

begin_comment
comment|/* rx disable */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER
value|0x06
end_define

begin_comment
comment|/* service request enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER_MDMCH
value|(1<<7)
end_define

begin_comment
comment|/* modem change */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER_RXDATA
value|(1<<4)
end_define

begin_comment
comment|/* rx data */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER_TXRDY
value|(1<<2)
end_define

begin_comment
comment|/* tx fifo empty */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER_TXMPTY
value|(1<<1)
end_define

begin_comment
comment|/* tx shift reg empty */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER_NNDT
value|(1<<0)
end_define

begin_comment
comment|/* no new data */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR1
value|0x08
end_define

begin_comment
comment|/* channel option 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR1_PARODD
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_PARNORMAL
value|(2<<5)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_PARFORCE
value|(1<<5)
end_define

begin_comment
comment|/* odd/even = force 1/0 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR1_PARNONE
value|(0<<5)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_NOINPCK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_STOP2
value|(2<<2)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_STOP15
value|(1<<2)
end_define

begin_comment
comment|/* 1.5 stop bits */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR1_STOP1
value|(0<<2)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_CS8
value|(3<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_CS7
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_CS6
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR1_CS5
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR2
value|0x09
end_define

begin_comment
comment|/* channel option 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_IXANY
value|(1<<7)
end_define

begin_comment
comment|/* implied XON mode */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_IXOFF
value|(1<<6)
end_define

begin_comment
comment|/* in-band tx flow control */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_ETC
value|(1<<5)
end_define

begin_comment
comment|/* embedded tx command */
end_comment

begin_define
define|#
directive|define
name|CD1400_ETC_CMD
value|0x00
end_define

begin_comment
comment|/* start an ETC */
end_comment

begin_define
define|#
directive|define
name|CD1400_ETC_SENDBREAK
value|0x81
end_define

begin_define
define|#
directive|define
name|CD1400_ETC_INSERTDELAY
value|0x82
end_define

begin_define
define|#
directive|define
name|CD1400_ETC_STOPBREAK
value|0x83
end_define

begin_define
define|#
directive|define
name|CD1400_COR2_LLM
value|(1<<4)
end_define

begin_comment
comment|/* local loopback mode */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_RLM
value|(1<<3)
end_define

begin_comment
comment|/* remote loopback mode */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_RTSAO
value|(1<<2)
end_define

begin_comment
comment|/* RTS auto output */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_CCTS_OFLOW
value|(1<<1)
end_define

begin_comment
comment|/* CTS auto enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2_CDSR_OFLOW
value|(1<<0)
end_define

begin_comment
comment|/* DSR auto enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3
value|0x0A
end_define

begin_comment
comment|/* channel option 3 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3_SCDRNG
value|(1<<7)
end_define

begin_comment
comment|/* special char detect range */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3_SCD34
value|(1<<6)
end_define

begin_comment
comment|/* special char detect 3-4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3_FTC
value|(1<<5)
end_define

begin_comment
comment|/* flow control transparency */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3_SCD12
value|(1<<4)
end_define

begin_comment
comment|/* special char detect 1-2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3_RXTH
value|(15<<0)
end_define

begin_comment
comment|/* rx fifo threshold */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR4
value|0x1E
end_define

begin_comment
comment|/* channel option 4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR4_IGNCR
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_ICRNL
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_INLCR
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_IGNBRK
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_NOBRKINT
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_PFO_ESC
value|(4<<0)
end_define

begin_comment
comment|/* parity/framing/overrun... */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR4_PFO_NUL
value|(3<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_PFO_DISCARD
value|(2<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_PFO_GOOD
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR4_PFO_EXCEPTION
value|(0<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_COR5
value|0x1F
end_define

begin_comment
comment|/* channel option 5 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR5_ISTRIP
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|CD1400_COR5_LNEXT
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CD1400_COR5_CMOE
value|(1<<5)
end_define

begin_comment
comment|/* char matching on error */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR5_EBD
value|(1<<2)
end_define

begin_comment
comment|/* end of break detected */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR5_ONLCR
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CD1400_COR5_OCRNL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_CCSR
value|0x0B
end_define

begin_comment
comment|/* channel control status */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDCR
value|0x0E
end_define

begin_comment
comment|/* received data count */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR1
value|0x1A
end_define

begin_comment
comment|/* special character 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR2
value|0x1B
end_define

begin_comment
comment|/* special character 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR3
value|0x1C
end_define

begin_comment
comment|/* special character 3 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR4
value|0x1D
end_define

begin_comment
comment|/* special character 4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCRL
value|0x22
end_define

begin_comment
comment|/* special character range, low */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCRH
value|0x23
end_define

begin_comment
comment|/* special character range, high */
end_comment

begin_define
define|#
directive|define
name|CD1400_LNC
value|0x24
end_define

begin_comment
comment|/* lnext character */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR1
value|0x15
end_define

begin_comment
comment|/* modem change option 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR1_DSRzd
value|(1<<7)
end_define

begin_comment
comment|/* DSR one-to-zero delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR1_CTSzd
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CD1400_MCOR1_RIzd
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CD1400_MCOR1_CDzd
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CD1400_MCOR1_DTRth
value|(15<<0)
end_define

begin_comment
comment|/* dtrflow threshold */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR2
value|0x16
end_define

begin_comment
comment|/* modem change option 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR2_DSRod
value|(1<<7)
end_define

begin_comment
comment|/* DSR zero-to-one delta */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR2_CTSod
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|CD1400_MCOR2_RIod
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|CD1400_MCOR2_CDod
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|CD1400_RTPR
value|0x21
end_define

begin_comment
comment|/* receive timeout period */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR1
value|0x6C
end_define

begin_comment
comment|/* modem signal value 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR1_RTS
value|(1<<0)
end_define

begin_comment
comment|/* RTS line (r/w) */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2
value|0x6D
end_define

begin_comment
comment|/* modem signal value 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2_DSR
value|(1<<7)
end_define

begin_comment
comment|/* !DSR line (r) */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2_CTS
value|(1<<6)
end_define

begin_comment
comment|/* !CTS line (r) */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2_RI
value|(1<<5)
end_define

begin_comment
comment|/* !RI line (r) */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2_CD
value|(1<<4)
end_define

begin_comment
comment|/* !CD line (r) */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR2_DTR
value|(1<<1)
end_define

begin_comment
comment|/* DTR line (r/w) */
end_comment

begin_define
define|#
directive|define
name|CD1400_PSVR
value|0x6F
end_define

begin_comment
comment|/* printer signal value */
end_comment

begin_define
define|#
directive|define
name|CD1400_RBPR
value|0x78
end_define

begin_comment
comment|/* receive baud rate period */
end_comment

begin_define
define|#
directive|define
name|CD1400_RCOR
value|0x7C
end_define

begin_comment
comment|/* receive clock option */
end_comment

begin_define
define|#
directive|define
name|CD1400_TBPR
value|0x72
end_define

begin_comment
comment|/* transmit baud rate period */
end_comment

begin_define
define|#
directive|define
name|CD1400_TCOR
value|0x76
end_define

begin_comment
comment|/* transmit clock option */
end_comment

end_unit

