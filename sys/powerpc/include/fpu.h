begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1996 Wolfgang Solfrank.  * Copyright (C) 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: fpu.h,v 1.2 1999/12/07 15:14:56 danw Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FPU_H_
end_define

begin_define
define|#
directive|define
name|FPSCR_FX
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FPSCR_FEX
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FPSCR_VX
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FPSCR_OX
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FPSCR_UX
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FPSCR_ZX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FPSCR_XX
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXSNAN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXISI
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXIDI
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXZDZ
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXIMZ
value|0x00100000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXVC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|FPSCR_FR
value|0x00040000
end_define

begin_define
define|#
directive|define
name|FPSCR_FI
value|0x00020000
end_define

begin_define
define|#
directive|define
name|FPSCR_FPRF
value|0x0001f000
end_define

begin_define
define|#
directive|define
name|FPSCR_C
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FPSCR_FPCC
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|FPSCR_FL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|FPSCR_FG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FPSCR_FE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FPSCR_FU
value|0x00001000
end_define

begin_define
define|#
directive|define
name|FPSCR_VXSOFT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|FPSCR_VXSQRT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FPSCR_VXCVI
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FPSCR_VE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FPSCR_OE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FPSCR_UE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FPSCR_ZE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FPSCR_XE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FPSCR_NI
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FPSCR_RN
value|0x00000003
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* List of PowerPC architectures that support FPUs. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OEA
argument_list|)
end_if

begin_define
define|#
directive|define
name|PPC_HAVE_FPU
end_define

begin_function_decl
name|void
name|enable_fpu
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_fpu
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPC_HAVE_FPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FPU_H_ */
end_comment

end_unit

