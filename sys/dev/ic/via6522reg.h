begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2004 by Peter Grehan. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIA6522REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIA6522REG_H_
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|REG_OIRB
value|0
end_define

begin_comment
comment|/* Input/output register B */
end_comment

begin_define
define|#
directive|define
name|REG_OIRA
value|1
end_define

begin_comment
comment|/* Input/output register A */
end_comment

begin_define
define|#
directive|define
name|REG_DDRB
value|2
end_define

begin_comment
comment|/* Data direction register B */
end_comment

begin_define
define|#
directive|define
name|REG_DDRA
value|3
end_define

begin_comment
comment|/* Data direction register A */
end_comment

begin_define
define|#
directive|define
name|REG_T1CL
value|4
end_define

begin_comment
comment|/* T1 low-order latch/low-order counter */
end_comment

begin_define
define|#
directive|define
name|REG_T1CH
value|5
end_define

begin_comment
comment|/* T1 high-order counter */
end_comment

begin_define
define|#
directive|define
name|REG_T1LL
value|6
end_define

begin_comment
comment|/* T1 low-order latches */
end_comment

begin_define
define|#
directive|define
name|REG_T1LH
value|7
end_define

begin_comment
comment|/* T1 high-order latches */
end_comment

begin_define
define|#
directive|define
name|REG_T2CL
value|8
end_define

begin_comment
comment|/* T2 low-order latch/low-order counter */
end_comment

begin_define
define|#
directive|define
name|REG_T2CH
value|9
end_define

begin_comment
comment|/* T2 high-order counter */
end_comment

begin_define
define|#
directive|define
name|REG_SR
value|10
end_define

begin_comment
comment|/* Shift register */
end_comment

begin_define
define|#
directive|define
name|REG_ACR
value|11
end_define

begin_comment
comment|/* Auxiliary control register */
end_comment

begin_define
define|#
directive|define
name|REG_PCR
value|12
end_define

begin_comment
comment|/* Peripheral control register */
end_comment

begin_define
define|#
directive|define
name|REG_IFR
value|13
end_define

begin_comment
comment|/* Interrupt flag register */
end_comment

begin_define
define|#
directive|define
name|REG_IER
value|14
end_define

begin_comment
comment|/* Interrupt-enable register */
end_comment

begin_define
define|#
directive|define
name|REG_OIRA_NH
value|15
end_define

begin_comment
comment|/* Input/output register A: no handshake */
end_comment

begin_comment
comment|/* Auxiliary control register (11) */
end_comment

begin_define
define|#
directive|define
name|ACR_SR_NONE
value|0x0
end_define

begin_comment
comment|/* Disabled */
end_comment

begin_define
define|#
directive|define
name|ACR_SR_DIR
value|0x4
end_define

begin_comment
comment|/* Bit for shift-register direction 1=out */
end_comment

begin_define
define|#
directive|define
name|ACR_SRI_T2
value|0x1
end_define

begin_comment
comment|/* Shift in under control of T2 */
end_comment

begin_define
define|#
directive|define
name|ACR_SRI_PHI2
value|0x2
end_define

begin_comment
comment|/*   "    "   "     "      " PHI2 */
end_comment

begin_define
define|#
directive|define
name|ACR_SRI_EXTCLK
value|0x3
end_define

begin_comment
comment|/*   "    "   "     "      " external clk */
end_comment

begin_define
define|#
directive|define
name|ACR_SRO
value|0x4
end_define

begin_comment
comment|/* Shift out free running at T2 rate */
end_comment

begin_define
define|#
directive|define
name|ACR_SRO_T2
value|0x5
end_define

begin_comment
comment|/* Shift out under control of T2 */
end_comment

begin_define
define|#
directive|define
name|ACR_SRO_PHI2
value|0x6
end_define

begin_comment
comment|/*   "    "   "     "      "  PHI2 */
end_comment

begin_define
define|#
directive|define
name|ACR_SRO_EXTCLK
value|0x7
end_define

begin_comment
comment|/*   "    "   "     "      "  external clk */
end_comment

begin_define
define|#
directive|define
name|ACR_T1_SHIFT
value|5
end_define

begin_comment
comment|/* bits 7-5 */
end_comment

begin_define
define|#
directive|define
name|ACR_SR_SHIFT
value|2
end_define

begin_comment
comment|/* bits 4-2 */
end_comment

begin_comment
comment|/* Peripheral control register (12) */
end_comment

begin_define
define|#
directive|define
name|PCR_INTCNTL
value|0x01
end_define

begin_comment
comment|/* interrupt active edge: +ve=1, -ve=0 */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_MASK
value|0x3
end_define

begin_comment
comment|/* 3 bits */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_NEDGE
value|0x0
end_define

begin_comment
comment|/* Input - negative active edge */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_INEDGE
value|0x1
end_define

begin_comment
comment|/* Interrupt - negative active edge */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_PEDGE
value|0x2
end_define

begin_comment
comment|/* Input - positive active edge */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_IPEDGE
value|0x3
end_define

begin_comment
comment|/* Interrupt - positive active edge */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_HSHAKE
value|0x4
end_define

begin_comment
comment|/* Handshake output */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_PULSE
value|0x5
end_define

begin_comment
comment|/* Pulse output */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_LOW
value|0x6
end_define

begin_comment
comment|/* Low output */
end_comment

begin_define
define|#
directive|define
name|PCR_CNTL_HIGH
value|0x7
end_define

begin_comment
comment|/* High output */
end_comment

begin_define
define|#
directive|define
name|PCR_CB2_SHIFT
value|5
end_define

begin_comment
comment|/* bits 7-5 */
end_comment

begin_define
define|#
directive|define
name|PCR_CB1_SHIFT
value|4
end_define

begin_comment
comment|/* bit 4 */
end_comment

begin_define
define|#
directive|define
name|PCR_CA2_SHIFT
value|1
end_define

begin_comment
comment|/* bits 3-1 */
end_comment

begin_define
define|#
directive|define
name|PCR_CA1_SHIFT
value|0
end_define

begin_comment
comment|/* bit 0 */
end_comment

begin_comment
comment|/* Interrupt flag register (13) */
end_comment

begin_define
define|#
directive|define
name|IFR_CA2
value|0x01
end_define

begin_define
define|#
directive|define
name|IFR_CA1
value|0x02
end_define

begin_define
define|#
directive|define
name|IFR_SR
value|0x04
end_define

begin_define
define|#
directive|define
name|IFR_CB2
value|0x08
end_define

begin_define
define|#
directive|define
name|IFR_CB1
value|0x10
end_define

begin_define
define|#
directive|define
name|IFR_T2
value|0x20
end_define

begin_define
define|#
directive|define
name|IFR_T1
value|0x40
end_define

begin_define
define|#
directive|define
name|IFR_IRQB
value|0x80
end_define

begin_comment
comment|/* status of IRQB output pin */
end_comment

begin_comment
comment|/* Interrupt enable register (14) */
end_comment

begin_define
define|#
directive|define
name|IER_CA2
value|IFR_CA2
end_define

begin_define
define|#
directive|define
name|IER_CA1
value|IFR_CA1
end_define

begin_define
define|#
directive|define
name|IER_SR
value|IFR_SR
end_define

begin_define
define|#
directive|define
name|IER_CB2
value|IFR_CB2
end_define

begin_define
define|#
directive|define
name|IER_CB1
value|IFR_CB1
end_define

begin_define
define|#
directive|define
name|IER_T2
value|IFR_T2
end_define

begin_define
define|#
directive|define
name|IER_T1
value|IFR_T1
end_define

begin_define
define|#
directive|define
name|IER_IRQB
value|IFR_IRQB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIA6522REG_H_ */
end_comment

end_unit

