begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: imx51_dpllreg.h,v 1.1 2012/04/17 09:33:31 bsh Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2012  Genetec Corporation.  All rights reserved.  * Written by Hashimoto Kenichi for Genetec Corporation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY GENETEC CORPORATION ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GENETEC CORPORATION  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2012, 2013 The FreeBSD Foundation  * All rights reserved.  *  * Portions of this software were developed by Oleksandr Rybalko  * under sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.	Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2.	Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IMX51_DPLLREG_H
end_ifndef

begin_define
define|#
directive|define
name|_IMX51_DPLLREG_H
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* register offset address */
end_comment

begin_define
define|#
directive|define
name|IMX51_N_DPLLS
value|3
end_define

begin_comment
comment|/* 1..3 */
end_comment

begin_define
define|#
directive|define
name|DPLL_BASE
parameter_list|(
name|n
parameter_list|)
value|(0x83F80000 + (0x4000 * ((n)-1)))
end_define

begin_define
define|#
directive|define
name|DPLL_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|DPLL_DP_CTL
value|0x0000
end_define

begin_comment
comment|/* 0x1223 */
end_comment

begin_define
define|#
directive|define
name|DP_CTL_LRF
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DP_CTL_BRM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DP_CTL_PLM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DP_CTL_RCP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DP_CTL_RST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DP_CTL_UPEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DP_CTL_PRE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DP_CTL_HFSM
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DP_CTL_REF_CLK_SEL_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|DP_CTL_REF_CLK_SEL_COSC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DP_CTL_REF_CLK_SEL_FPM
value|0x00000300
end_define

begin_define
define|#
directive|define
name|DP_CTL_REF_CLK_DIV
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DP_CTL_DPDCK0_2_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DP_CTL_HIGHCLK_EN
value|DP_CTL_DPDCK0_2_EN
end_define

begin_define
define|#
directive|define
name|DP_CTL_MULCTRL
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DPLL_DP_CONFIG
value|0x0004
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_CONFIG_APEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DPLL_DP_CONFIG_LDREQ
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DPLL_DP_OP
value|0x0008
end_define

begin_comment
comment|/* 0x80 */
end_comment

begin_define
define|#
directive|define
name|DP_OP_PDF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DP_OP_PDF_MASK
value|(0xf<< DP_OP_PDF_SHIFT)
end_define

begin_define
define|#
directive|define
name|DP_OP_MFI_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|DP_OP_MFI_MASK
value|(0xf<< DP_OP_MFI_SHIFT)
end_define

begin_define
define|#
directive|define
name|DPLL_DP_MFD
value|0x000C
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_MFN
value|0x0010
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_MFNMINUS
value|0x0014
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_MFNPLUS
value|0x0018
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_HFS_OP
value|0x001C
end_define

begin_comment
comment|/* 0x80 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_HFS_MFD
value|0x0020
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_HFS_MFN
value|0x0024
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_TOGC
value|0x0028
end_define

begin_comment
comment|/* 0x20000 */
end_comment

begin_define
define|#
directive|define
name|DPLL_DP_DESTAT
value|0x002C
end_define

begin_comment
comment|/* 1 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IMX51_DPLLREG_H */
end_comment

end_unit

