begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1995, 1996 Wolfgang Solfrank.  * Copyright (C) 1995, 1996 TooLs GmbH.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$NetBSD: signal.h,v 1.4 1998/09/14 02:48:34 thorpej Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SIGNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGNAL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_define
define|#
directive|define
name|MINSIGSTKSZ
value|(512 * 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|sig_atomic_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_include
include|#
directive|include
file|<machine/frame.h>
end_include

begin_struct
struct|struct
name|sigcontext
block|{
name|int
name|sc_onstack
decl_stmt|;
comment|/* saved onstack flag */
name|int
name|__sc_mask13
decl_stmt|;
comment|/* saved signal mask (old style) */
name|struct
name|trapframe
name|sc_frame
decl_stmt|;
comment|/* saved registers */
name|struct
name|__sigset
name|sc_mask
decl_stmt|;
comment|/* saved signal mask (new style) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SIGNAL_H_ */
end_comment

end_unit

