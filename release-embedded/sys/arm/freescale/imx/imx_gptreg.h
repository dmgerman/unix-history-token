begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Oleksandr Rybalko under sponsorship  * from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Registers definition for Freescale i.MX515 Generic Periodic Timer */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_CR
value|0x0000
end_define

begin_comment
comment|/* Control Register          R/W */
end_comment

begin_define
define|#
directive|define
name|GPT_CR_FO3
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|GPT_CR_FO2
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|GPT_CR_FO1
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM3_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM3_MASK
value|0x1c000000
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM2_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM2_MASK
value|0x03800000
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|GPT_CR_OM1_MASK
value|0x00700000
end_define

begin_define
define|#
directive|define
name|GPT_CR_OMX_NONE
value|0
end_define

begin_define
define|#
directive|define
name|GPT_CR_OMX_TOGGLE
value|1
end_define

begin_define
define|#
directive|define
name|GPT_CR_OMX_CLEAR
value|2
end_define

begin_define
define|#
directive|define
name|GPT_CR_OMX_SET
value|3
end_define

begin_define
define|#
directive|define
name|GPT_CR_OMX_PULSE
value|4
end_define

begin_comment
comment|/* Run CLKSRC on output pin */
end_comment

begin_define
define|#
directive|define
name|GPT_CR_IM2_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|GPT_CR_IM2_MASK
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|GPT_CR_IM1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GPT_CR_IM1_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|GPT_CR_IMX_NONE
value|0
end_define

begin_define
define|#
directive|define
name|GPT_CR_IMX_REDGE
value|1
end_define

begin_define
define|#
directive|define
name|GPT_CR_IMX_FEDGE
value|2
end_define

begin_define
define|#
directive|define
name|GPT_CR_IMX_BOTH
value|3
end_define

begin_define
define|#
directive|define
name|GPT_CR_SWR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|GPT_CR_24MEN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|GPT_CR_FRR
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_NONE
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_IPG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_IPG_HIGH
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_EXT
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_32K
value|(4<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_CLKSRC_24M
value|(5<< 6)
end_define

begin_define
define|#
directive|define
name|GPT_CR_STOPEN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GPT_CR_DOZEEN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GPT_CR_WAITEN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GPT_CR_DBGEN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GPT_CR_ENMOD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GPT_CR_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|IMX_GPT_PR
value|0x0004
end_define

begin_comment
comment|/* Prescaler Register        R/W */
end_comment

begin_define
define|#
directive|define
name|GPT_PR_VALUE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GPT_PR_VALUE_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|GPT_PR_VALUE_SHIFT_24M
value|12
end_define

begin_define
define|#
directive|define
name|GPT_PR_VALUE_MASK_24M
value|0x0000f000
end_define

begin_comment
comment|/* Same map for SR and IR */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_SR
value|0x0008
end_define

begin_comment
comment|/* Status Register           R/W */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_IR
value|0x000c
end_define

begin_comment
comment|/* Interrupt Register        R/W */
end_comment

begin_define
define|#
directive|define
name|GPT_IR_ROV
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|GPT_IR_IF2
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|GPT_IR_IF1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|GPT_IR_OF3
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|GPT_IR_OF2
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|GPT_IR_OF1
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|GPT_IR_ALL
define|\
value|(GPT_IR_ROV |	\ 			GPT_IR_IF2 |	\ 			GPT_IR_IF1 |	\ 			GPT_IR_OF3 |	\ 			GPT_IR_OF2 |	\ 			GPT_IR_OF1)
end_define

begin_define
define|#
directive|define
name|IMX_GPT_OCR1
value|0x0010
end_define

begin_comment
comment|/* Output Compare Register 1 R/W */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_OCR2
value|0x0014
end_define

begin_comment
comment|/* Output Compare Register 2 R/W */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_OCR3
value|0x0018
end_define

begin_comment
comment|/* Output Compare Register 3 R/W */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_ICR1
value|0x001c
end_define

begin_comment
comment|/* Input capture Register 1  RO */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_ICR2
value|0x0020
end_define

begin_comment
comment|/* Input capture Register 2  RO */
end_comment

begin_define
define|#
directive|define
name|IMX_GPT_CNT
value|0x0024
end_define

begin_comment
comment|/* Counter Register          RO */
end_comment

end_unit

