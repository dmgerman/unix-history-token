begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	cd1400.h  -- cd1400 UART hardware info.  *  * Copyright (c) 1995 Greg Ungerer (gerg@stallion.oz.au).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Greg Ungerer.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CD1400_H
end_ifndef

begin_define
define|#
directive|define
name|_CD1400_H
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the number of async ports per cd1400 uart chip.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_PORTS
value|4
end_define

begin_comment
comment|/*  *	Define the cd1400 uarts internal FIFO sizes.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_TXFIFOSIZE
value|12
end_define

begin_define
define|#
directive|define
name|CD1400_RXFIFOSIZE
value|12
end_define

begin_comment
comment|/*  *	Local RX FIFO thresh hold level. Also define the RTS thresh hold  *	based on the RX thresh hold.  */
end_comment

begin_define
define|#
directive|define
name|FIFO_RXTHRESHOLD
value|6
end_define

begin_define
define|#
directive|define
name|FIFO_RTSTHRESHOLD
value|7
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the cd1400 register addresses. These are all the valid  *	registers with the cd1400. Some are global, some virtual, some  *	per port.  */
end_comment

begin_define
define|#
directive|define
name|GFRCR
value|0x40
end_define

begin_define
define|#
directive|define
name|CAR
value|0x68
end_define

begin_define
define|#
directive|define
name|GCR
value|0x4b
end_define

begin_define
define|#
directive|define
name|SVRR
value|0x67
end_define

begin_define
define|#
directive|define
name|RICR
value|0x44
end_define

begin_define
define|#
directive|define
name|TICR
value|0x45
end_define

begin_define
define|#
directive|define
name|MICR
value|0x46
end_define

begin_define
define|#
directive|define
name|RIR
value|0x6b
end_define

begin_define
define|#
directive|define
name|TIR
value|0x6a
end_define

begin_define
define|#
directive|define
name|MIR
value|0x69
end_define

begin_define
define|#
directive|define
name|PPR
value|0x7e
end_define

begin_define
define|#
directive|define
name|RIVR
value|0x43
end_define

begin_define
define|#
directive|define
name|TIVR
value|0x42
end_define

begin_define
define|#
directive|define
name|MIVR
value|0x41
end_define

begin_define
define|#
directive|define
name|TDR
value|0x63
end_define

begin_define
define|#
directive|define
name|RDSR
value|0x62
end_define

begin_define
define|#
directive|define
name|MISR
value|0x4c
end_define

begin_define
define|#
directive|define
name|EOSRR
value|0x60
end_define

begin_define
define|#
directive|define
name|LIVR
value|0x18
end_define

begin_define
define|#
directive|define
name|CCR
value|0x05
end_define

begin_define
define|#
directive|define
name|SRER
value|0x06
end_define

begin_define
define|#
directive|define
name|COR1
value|0x08
end_define

begin_define
define|#
directive|define
name|COR2
value|0x09
end_define

begin_define
define|#
directive|define
name|COR3
value|0x0a
end_define

begin_define
define|#
directive|define
name|COR4
value|0x1e
end_define

begin_define
define|#
directive|define
name|COR5
value|0x1f
end_define

begin_define
define|#
directive|define
name|CCSR
value|0x0b
end_define

begin_define
define|#
directive|define
name|RDCR
value|0x0e
end_define

begin_define
define|#
directive|define
name|SCHR1
value|0x1a
end_define

begin_define
define|#
directive|define
name|SCHR2
value|0x1b
end_define

begin_define
define|#
directive|define
name|SCHR3
value|0x1c
end_define

begin_define
define|#
directive|define
name|SCHR4
value|0x1d
end_define

begin_define
define|#
directive|define
name|SCRL
value|0x22
end_define

begin_define
define|#
directive|define
name|SCRH
value|0x23
end_define

begin_define
define|#
directive|define
name|LNC
value|0x24
end_define

begin_define
define|#
directive|define
name|MCOR1
value|0x15
end_define

begin_define
define|#
directive|define
name|MCOR2
value|0x16
end_define

begin_define
define|#
directive|define
name|RTPR
value|0x21
end_define

begin_define
define|#
directive|define
name|MSVR1
value|0x6c
end_define

begin_define
define|#
directive|define
name|MSVR2
value|0x6d
end_define

begin_define
define|#
directive|define
name|PSVR
value|0x6f
end_define

begin_define
define|#
directive|define
name|RBPR
value|0x78
end_define

begin_define
define|#
directive|define
name|RCOR
value|0x7c
end_define

begin_define
define|#
directive|define
name|TBPR
value|0x72
end_define

begin_define
define|#
directive|define
name|TCOR
value|0x76
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the set of baud rate clock divisors.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_CLK0
value|8
end_define

begin_define
define|#
directive|define
name|CD1400_CLK1
value|32
end_define

begin_define
define|#
directive|define
name|CD1400_CLK2
value|128
end_define

begin_define
define|#
directive|define
name|CD1400_CLK3
value|512
end_define

begin_define
define|#
directive|define
name|CD1400_CLK4
value|2048
end_define

begin_define
define|#
directive|define
name|CD1400_NUMCLKS
value|5
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the clock pre-scalar value to be a 5 ms clock. This should be  *	OK for now. It would probably be better to make it 10 ms, but we  *	can't fit that divisor into 8 bits!  */
end_comment

begin_define
define|#
directive|define
name|PPR_SCALAR
value|244
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define values used to set character size options.  */
end_comment

begin_define
define|#
directive|define
name|COR1_CHL5
value|0x00
end_define

begin_define
define|#
directive|define
name|COR1_CHL6
value|0x01
end_define

begin_define
define|#
directive|define
name|COR1_CHL7
value|0x02
end_define

begin_define
define|#
directive|define
name|COR1_CHL8
value|0x03
end_define

begin_comment
comment|/*  *	Define values used to set the number of stop bits.  */
end_comment

begin_define
define|#
directive|define
name|COR1_STOP1
value|0x00
end_define

begin_define
define|#
directive|define
name|COR1_STOP15
value|0x04
end_define

begin_define
define|#
directive|define
name|COR1_STOP2
value|0x08
end_define

begin_comment
comment|/*  *	Define values used to set the parity scheme in use.  */
end_comment

begin_define
define|#
directive|define
name|COR1_PARNONE
value|0x00
end_define

begin_define
define|#
directive|define
name|COR1_PARFORCE
value|0x20
end_define

begin_define
define|#
directive|define
name|COR1_PARENB
value|0x40
end_define

begin_define
define|#
directive|define
name|COR1_PARIGNORE
value|0x10
end_define

begin_define
define|#
directive|define
name|COR1_PARODD
value|0x80
end_define

begin_define
define|#
directive|define
name|COR1_PAREVEN
value|0x00
end_define

begin_define
define|#
directive|define
name|COR2_IXM
value|0x80
end_define

begin_define
define|#
directive|define
name|COR2_TXIBE
value|0x40
end_define

begin_define
define|#
directive|define
name|COR2_ETC
value|0x20
end_define

begin_define
define|#
directive|define
name|COR2_LLM
value|0x10
end_define

begin_define
define|#
directive|define
name|COR2_RLM
value|0x08
end_define

begin_define
define|#
directive|define
name|COR2_RTSAO
value|0x04
end_define

begin_define
define|#
directive|define
name|COR2_CTSAE
value|0x02
end_define

begin_define
define|#
directive|define
name|COR3_SCDRNG
value|0x80
end_define

begin_define
define|#
directive|define
name|COR3_SCD34
value|0x40
end_define

begin_define
define|#
directive|define
name|COR3_FCT
value|0x20
end_define

begin_define
define|#
directive|define
name|COR3_SCD12
value|0x10
end_define

begin_comment
comment|/*  *	Define the bit values of COR4.  */
end_comment

begin_define
define|#
directive|define
name|COR4_BRKINT
value|0x08
end_define

begin_define
define|#
directive|define
name|COR4_IGNBRK
value|0x18
end_define

begin_comment
comment|/*  *	Define the bit values of COR5.  */
end_comment

begin_define
define|#
directive|define
name|COR5_ISTRIP
value|0x80
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the modem control register values.  *	Note that the actual hardware is a little different to the conventional  *	pin names on the cd1400.  */
end_comment

begin_define
define|#
directive|define
name|MSVR1_DTR
value|0x01
end_define

begin_define
define|#
directive|define
name|MSVR1_DSR
value|0x10
end_define

begin_define
define|#
directive|define
name|MSVR1_RI
value|0x20
end_define

begin_define
define|#
directive|define
name|MSVR1_CTS
value|0x40
end_define

begin_define
define|#
directive|define
name|MSVR1_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MSVR2_RTS
value|0x02
end_define

begin_define
define|#
directive|define
name|MSVR2_DSR
value|0x10
end_define

begin_define
define|#
directive|define
name|MSVR2_RI
value|0x20
end_define

begin_define
define|#
directive|define
name|MSVR2_CTS
value|0x40
end_define

begin_define
define|#
directive|define
name|MSVR2_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MCOR1_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MCOR1_CTS
value|0x40
end_define

begin_define
define|#
directive|define
name|MCOR1_RI
value|0x20
end_define

begin_define
define|#
directive|define
name|MCOR1_DSR
value|0x10
end_define

begin_define
define|#
directive|define
name|MCOR2_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MCOR2_CTS
value|0x40
end_define

begin_define
define|#
directive|define
name|MCOR2_RI
value|0x20
end_define

begin_define
define|#
directive|define
name|MCOR2_DSR
value|0x10
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the bits used with the service (interrupt) enable register.  */
end_comment

begin_define
define|#
directive|define
name|SRER_NNDT
value|0x01
end_define

begin_define
define|#
directive|define
name|SRER_TXEMPTY
value|0x02
end_define

begin_define
define|#
directive|define
name|SRER_TXDATA
value|0x04
end_define

begin_define
define|#
directive|define
name|SRER_RXDATA
value|0x10
end_define

begin_define
define|#
directive|define
name|SRER_MODEM
value|0x80
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define operational commands for the command register.  */
end_comment

begin_define
define|#
directive|define
name|CCR_RESET
value|0x80
end_define

begin_define
define|#
directive|define
name|CCR_CORCHANGE
value|0x4e
end_define

begin_define
define|#
directive|define
name|CCR_SENDCH
value|0x20
end_define

begin_define
define|#
directive|define
name|CCR_CHANCTRL
value|0x10
end_define

begin_define
define|#
directive|define
name|CCR_TXENABLE
value|(CCR_CHANCTRL | 0x08)
end_define

begin_define
define|#
directive|define
name|CCR_TXDISABLE
value|(CCR_CHANCTRL | 0x04)
end_define

begin_define
define|#
directive|define
name|CCR_RXENABLE
value|(CCR_CHANCTRL | 0x02)
end_define

begin_define
define|#
directive|define
name|CCR_RXDISABLE
value|(CCR_CHANCTRL | 0x01)
end_define

begin_define
define|#
directive|define
name|CCR_SENDSCHR1
value|(CCR_SENDCH | 0x01)
end_define

begin_define
define|#
directive|define
name|CCR_SENDSCHR2
value|(CCR_SENDCH | 0x02)
end_define

begin_define
define|#
directive|define
name|CCR_SENDSCHR3
value|(CCR_SENDCH | 0x03)
end_define

begin_define
define|#
directive|define
name|CCR_SENDSCHR4
value|(CCR_SENDCH | 0x04)
end_define

begin_define
define|#
directive|define
name|CCR_RESETCHAN
value|(CCR_RESET | 0x00)
end_define

begin_define
define|#
directive|define
name|CCR_RESETFULL
value|(CCR_RESET | 0x01)
end_define

begin_define
define|#
directive|define
name|CCR_TXFLUSHFIFO
value|(CCR_RESET | 0x02)
end_define

begin_define
define|#
directive|define
name|CCR_MAXWAIT
value|10000
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the valid acknowledgement types (for hw ack cycle).  */
end_comment

begin_define
define|#
directive|define
name|ACK_TYPMASK
value|0x07
end_define

begin_define
define|#
directive|define
name|ACK_TYPTX
value|0x02
end_define

begin_define
define|#
directive|define
name|ACK_TYPMDM
value|0x01
end_define

begin_define
define|#
directive|define
name|ACK_TYPRXGOOD
value|0x03
end_define

begin_define
define|#
directive|define
name|ACK_TYPRXBAD
value|0x07
end_define

begin_define
define|#
directive|define
name|SVRR_RX
value|0x01
end_define

begin_define
define|#
directive|define
name|SVRR_TX
value|0x02
end_define

begin_define
define|#
directive|define
name|SVRR_MDM
value|0x04
end_define

begin_define
define|#
directive|define
name|ST_OVERRUN
value|0x01
end_define

begin_define
define|#
directive|define
name|ST_FRAMING
value|0x02
end_define

begin_define
define|#
directive|define
name|ST_PARITY
value|0x04
end_define

begin_define
define|#
directive|define
name|ST_BREAK
value|0x08
end_define

begin_define
define|#
directive|define
name|ST_SCHAR1
value|0x10
end_define

begin_define
define|#
directive|define
name|ST_SCHAR2
value|0x20
end_define

begin_define
define|#
directive|define
name|ST_SCHAR3
value|0x30
end_define

begin_define
define|#
directive|define
name|ST_SCHAR4
value|0x40
end_define

begin_define
define|#
directive|define
name|ST_RANGE
value|0x70
end_define

begin_define
define|#
directive|define
name|ST_SCHARMASK
value|0x70
end_define

begin_define
define|#
directive|define
name|ST_TIMEOUT
value|0x80
end_define

begin_define
define|#
directive|define
name|MISR_DCD
value|0x80
end_define

begin_define
define|#
directive|define
name|MISR_CTS
value|0x40
end_define

begin_define
define|#
directive|define
name|MISR_RI
value|0x20
end_define

begin_define
define|#
directive|define
name|MISR_DSR
value|0x10
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Defines for the CCSR status register.  */
end_comment

begin_define
define|#
directive|define
name|CCSR_RXENABLED
value|0x80
end_define

begin_define
define|#
directive|define
name|CCSR_RXFLOWON
value|0x40
end_define

begin_define
define|#
directive|define
name|CCSR_RXFLOWOFF
value|0x20
end_define

begin_define
define|#
directive|define
name|CCSR_TXENABLED
value|0x08
end_define

begin_define
define|#
directive|define
name|CCSR_TXFLOWON
value|0x04
end_define

begin_define
define|#
directive|define
name|CCSR_TXFLOWOFF
value|0x02
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_comment
comment|/*  *	Define the embedded commands.  */
end_comment

begin_define
define|#
directive|define
name|ETC_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|ETC_STARTBREAK
value|0x81
end_define

begin_define
define|#
directive|define
name|ETC_DELAY
value|0x82
end_define

begin_define
define|#
directive|define
name|ETC_STOPBREAK
value|0x83
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

