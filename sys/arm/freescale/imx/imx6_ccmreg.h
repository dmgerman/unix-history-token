begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ian Lepore<ian@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IMX6_CCMREG_H
end_ifndef

begin_define
define|#
directive|define
name|IMX6_CCMREG_H
end_define

begin_define
define|#
directive|define
name|CCM_CSCMR1
value|0x01C
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_SEL_S
value|10
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_SEL_S
value|12
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_SEL_S
value|14
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_M
value|0x3
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_508_PFD
value|0
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_454_PFD
value|1
end_define

begin_define
define|#
directive|define
name|SSI_CLK_SEL_PLL4
value|2
end_define

begin_define
define|#
directive|define
name|CCM_CSCMR2
value|0x020
end_define

begin_define
define|#
directive|define
name|CCM_CS1CDR
value|0x028
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SSI1_CLK_PRED_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_PODF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SSI3_CLK_PRED_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|SSI_CLK_PODF_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|SSI_CLK_PRED_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|CCM_CS2CDR
value|0x02C
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_PODF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SSI2_CLK_PRED_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CCM_CSCDR2
value|0x038
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR
value|0x054
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_RUN
value|0x00
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_WAIT
value|0x01
end_define

begin_define
define|#
directive|define
name|CCM_CLPCR_LPM_STOP
value|0x02
end_define

begin_define
define|#
directive|define
name|CCM_CGPR
value|0x064
end_define

begin_define
define|#
directive|define
name|CCM_CGPR_INT_MEM_CLK_LPM
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CCM_CCGR0
value|0x068
end_define

begin_define
define|#
directive|define
name|CCM_CCGR1
value|0x06C
end_define

begin_define
define|#
directive|define
name|CCM_CCGR2
value|0x070
end_define

begin_define
define|#
directive|define
name|CCM_CCGR3
value|0x074
end_define

begin_define
define|#
directive|define
name|CCM_CCGR4
value|0x078
end_define

begin_define
define|#
directive|define
name|CCM_CCGR5
value|0x07C
end_define

begin_define
define|#
directive|define
name|CCM_CCGR6
value|0x080
end_define

begin_define
define|#
directive|define
name|CCM_CMEOR
value|0x088
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

