begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cyclades cyclom-y serial driver  *	Andrew Herbert<andrew@werple.apana.org.au>, 17 August 1993  *  * Copyright (c) 1993 Andrew Herbert.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name Andrew Herbert may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL I BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_define
define|#
directive|define
name|CD1400_NO_OF_CHANNELS
value|4
end_define

begin_comment
comment|/* four serial channels per chip */
end_comment

begin_define
define|#
directive|define
name|CD1400_FIFOSIZE
value|12
end_define

begin_comment
comment|/* 12 chars */
end_comment

begin_comment
comment|/* register definitions */
end_comment

begin_define
define|#
directive|define
name|CD1400_CCR
value|2*0x05
end_define

begin_comment
comment|/* channel control */
end_comment

begin_define
define|#
directive|define
name|CD1400_CMD_RESET
value|0x81
end_define

begin_comment
comment|/* full reset */
end_comment

begin_define
define|#
directive|define
name|CD1400_SRER
value|2*0x06
end_define

begin_comment
comment|/* service request enable */
end_comment

begin_define
define|#
directive|define
name|CD1400_GFRCR
value|2*0x40
end_define

begin_comment
comment|/* global firmware revision code */
end_comment

begin_define
define|#
directive|define
name|CD1400_LIVR
value|2*0x18
end_define

begin_comment
comment|/* local intr vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIVR
value|2*0x41
end_define

begin_comment
comment|/* modem intr vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIVR
value|2*0x42
end_define

begin_comment
comment|/* transmit intr vector */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIVR
value|2*0x43
end_define

begin_comment
comment|/* receive intr vector */
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
name|CD1400_RICR
value|2*0x44
end_define

begin_comment
comment|/* receive intr channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_TICR
value|2*0x45
end_define

begin_comment
comment|/* transmit intr channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_MICR
value|2*0x46
end_define

begin_comment
comment|/* modem intr channel */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDCR
value|2*0x0e
end_define

begin_comment
comment|/* rx data count */
end_comment

begin_define
define|#
directive|define
name|CD1400_EOSRR
value|2*0x60
end_define

begin_comment
comment|/* end of service request */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR
value|2*0x62
end_define

begin_comment
comment|/* rx data/status */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_OVERRUN
value|(1<<0)
end_define

begin_comment
comment|/* rx overrun error */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_FRAMING
value|(1<<1)
end_define

begin_comment
comment|/* rx framing error */
end_comment

begin_define
define|#
directive|define
name|CD1400_RDSR_PARITY
value|(1<<2)
end_define

begin_comment
comment|/* rx parity error */
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
name|CD1400_RDSR_SPECIAL
value|(7<<4)
end_define

begin_comment
comment|/* rx special char */
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
name|CD1400_RDSR_TIMEOUT
value|(1<<7)
end_define

begin_comment
comment|/* rx timeout */
end_comment

begin_define
define|#
directive|define
name|CD1400_TDR
value|2*0x63
end_define

begin_comment
comment|/* tx data */
end_comment

begin_define
define|#
directive|define
name|CD1400_MISR
value|2*0x4c
end_define

begin_comment
comment|/* modem intr status */
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
name|CD1400_MSVR
value|2*0x6d
end_define

begin_comment
comment|/* modem signals */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR_DSR
value|(1<<7)
end_define

begin_comment
comment|/* !DSR line */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR_CTS
value|(1<<6)
end_define

begin_comment
comment|/* !CTS line */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR_RI
value|(1<<5)
end_define

begin_comment
comment|/* !RI line */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR_CD
value|(1<<4)
end_define

begin_comment
comment|/* !CD line */
end_comment

begin_define
define|#
directive|define
name|CD1400_MSVR_DTR
value|(1<<1)
end_define

begin_comment
comment|/* DTR line */
end_comment

begin_define
define|#
directive|define
name|CD1400_DTR
value|2*0x6d
end_define

begin_comment
comment|/* dtr control */
end_comment

begin_define
define|#
directive|define
name|CD1400_DTR_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|CD1400_DTR_SET
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CD1400_PPR
value|2*0x7e
end_define

begin_define
define|#
directive|define
name|CD1400_CLOCK_25_1MS
value|0x31
end_define

begin_define
define|#
directive|define
name|CD1400_CAR
value|2*0x68
end_define

begin_comment
comment|/* channel access */
end_comment

begin_define
define|#
directive|define
name|CD1400_RIR
value|2*0x6B
end_define

begin_comment
comment|/* receive interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_TIR
value|2*0x6A
end_define

begin_comment
comment|/* transmit interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_MIR
value|2*0x69
end_define

begin_comment
comment|/* modem interrupt status */
end_comment

begin_define
define|#
directive|define
name|CD1400_RBPR
value|2*0x78
end_define

begin_comment
comment|/* receive baud rate period */
end_comment

begin_define
define|#
directive|define
name|CD1400_RCOR
value|2*0x7C
end_define

begin_comment
comment|/* receive clock option */
end_comment

begin_define
define|#
directive|define
name|CD1400_TBPR
value|2*0x72
end_define

begin_comment
comment|/* transmit baud rate period */
end_comment

begin_define
define|#
directive|define
name|CD1400_TCOR
value|2*0x76
end_define

begin_comment
comment|/* transmit clock option */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR1
value|2*0x08
end_define

begin_comment
comment|/* channel option 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR2
value|2*0x09
end_define

begin_comment
comment|/* channel option 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR3
value|2*0x0A
end_define

begin_comment
comment|/* channel option 3 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR4
value|2*0x1E
end_define

begin_comment
comment|/* channel option 4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_COR5
value|2*0x1F
end_define

begin_comment
comment|/* channel option 5 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR1
value|2*0x1A
end_define

begin_comment
comment|/* special character 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR2
value|2*0x1B
end_define

begin_comment
comment|/* special character 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR3
value|2*0x1C
end_define

begin_comment
comment|/* special character 3 */
end_comment

begin_define
define|#
directive|define
name|CD1400_SCHR4
value|2*0x1D
end_define

begin_comment
comment|/* special character 4 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR1
value|2*0x15
end_define

begin_comment
comment|/* modem change 1 */
end_comment

begin_define
define|#
directive|define
name|CD1400_MCOR2
value|2*0x16
end_define

begin_comment
comment|/* modem change 2 */
end_comment

begin_define
define|#
directive|define
name|CD1400_RTPR
value|2*0x21
end_define

begin_comment
comment|/* receive timeout period */
end_comment

begin_define
define|#
directive|define
name|CD1400_SVRR
value|2*0x67
end_define

begin_comment
comment|/* service request */
end_comment

begin_define
define|#
directive|define
name|CD1400_SVRR_RX
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|CD1400_SVRR_TX
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|CD1400_SVRR_MDM
value|(1<<2)
end_define

begin_comment
comment|/* hardware SVCACK addresses, for use in interrupt handlers */
end_comment

begin_define
define|#
directive|define
name|CD1400_SVCACKR
value|0x100
end_define

begin_define
define|#
directive|define
name|CD1400_SVCACKT
value|0x200
end_define

begin_define
define|#
directive|define
name|CD1400_SVCACKM
value|0x300
end_define

end_unit

