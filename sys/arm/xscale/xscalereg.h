begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: xscalereg.h,v 1.2 2002/08/07 05:15:02 briggs Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_XSCALE_XSCALEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_XSCALE_XSCALEREG_H_
end_define

begin_comment
comment|/*  * Register definitions for the Intel XScale processor core.  */
end_comment

begin_comment
comment|/*  * Performance Monitoring Unit		(CP14)  *  *	CP14.0		Performance Monitor Control Register  *	CP14.1		Clock Counter  *	CP14.2		Performance Counter Register 0  *	CP14.3		Performance Counter Register 1  */
end_comment

begin_define
define|#
directive|define
name|PMNC_E
value|0x00000001
end_define

begin_comment
comment|/* enable counters */
end_comment

begin_define
define|#
directive|define
name|PMNC_P
value|0x00000002
end_define

begin_comment
comment|/* reset both PMNs to 0 */
end_comment

begin_define
define|#
directive|define
name|PMNC_C
value|0x00000004
end_define

begin_comment
comment|/* clock counter reset */
end_comment

begin_define
define|#
directive|define
name|PMNC_D
value|0x00000008
end_define

begin_comment
comment|/* clock counter / 64 */
end_comment

begin_define
define|#
directive|define
name|PMNC_PMN0_IE
value|0x00000010
end_define

begin_comment
comment|/* enable PMN0 interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_PMN1_IE
value|0x00000020
end_define

begin_comment
comment|/* enable PMN1 interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_CC_IE
value|0x00000040
end_define

begin_comment
comment|/* enable clock counter interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_PMN0_IF
value|0x00000100
end_define

begin_comment
comment|/* PMN0 overflow/interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_PMN1_IF
value|0x00000200
end_define

begin_comment
comment|/* PMN1 overflow/interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_CC_IF
value|0x00000400
end_define

begin_comment
comment|/* clock counter overflow/interrupt */
end_comment

begin_define
define|#
directive|define
name|PMNC_EVCNT0_MASK
value|0x000ff000
end_define

begin_comment
comment|/* event to count for PMN0 */
end_comment

begin_define
define|#
directive|define
name|PMNC_EVCNT0_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PMNC_EVCNT1_MASK
value|0x0ff00000
end_define

begin_comment
comment|/* event to count for PMN1 */
end_comment

begin_define
define|#
directive|define
name|PMNC_EVCNT1_SHIFT
value|20
end_define

begin_function_decl
name|void
name|xscale_pmu_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_XSCALE_XSCALEREG_H_ */
end_comment

end_unit

