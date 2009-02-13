begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: fiq.h,v 1.1 2001/12/20 01:20:23 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_FIQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_FIQ_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|fiqregs
block|{
name|u_int
name|fr_r8
decl_stmt|;
comment|/* FIQ mode r8 */
name|u_int
name|fr_r9
decl_stmt|;
comment|/* FIQ mode r9 */
name|u_int
name|fr_r10
decl_stmt|;
comment|/* FIQ mode r10 */
name|u_int
name|fr_r11
decl_stmt|;
comment|/* FIQ mode r11 */
name|u_int
name|fr_r12
decl_stmt|;
comment|/* FIQ mode r12 */
name|u_int
name|fr_r13
decl_stmt|;
comment|/* FIQ mode r13 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fiqhandler
block|{
name|TAILQ_ENTRY
argument_list|(
argument|fiqhandler
argument_list|)
name|fh_list
expr_stmt|;
comment|/* link in the FIQ handler stack */
name|void
modifier|*
name|fh_func
decl_stmt|;
comment|/* FIQ handler routine */
name|size_t
name|fh_size
decl_stmt|;
comment|/* size of FIQ handler */
name|int
name|fh_flags
decl_stmt|;
comment|/* flags; see below */
name|struct
name|fiqregs
modifier|*
name|fh_regs
decl_stmt|;
comment|/* pointer to regs structure */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FH_CANPUSH
value|0x01
end_define

begin_comment
comment|/* can push this handler out of the way */
end_comment

begin_function_decl
name|int
name|fiq_claim
parameter_list|(
name|struct
name|fiqhandler
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fiq_release
parameter_list|(
name|struct
name|fiqhandler
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fiq_getregs
parameter_list|(
name|struct
name|fiqregs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fiq_setregs
parameter_list|(
name|struct
name|fiqregs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_FIQ_H_ */
end_comment

end_unit

