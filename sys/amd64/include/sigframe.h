begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SIGFRAME_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SIGFRAME_H_
end_define

begin_comment
comment|/*  * Signal frames, arguments passed to application signal handlers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|osigframe
block|{
comment|/* 	 * The first four members may be used by applications. 	 */
name|register_t
name|sf_signum
decl_stmt|;
comment|/* 	 * Either 'int' for old-style FreeBSD handler or 'siginfo_t *' 	 * pointing to sf_siginfo for SA_SIGINFO handlers. 	 */
name|register_t
name|sf_arg2
decl_stmt|;
comment|/* Points to sf_siginfo.si_sc. */
name|register_t
name|sf_scp
decl_stmt|;
name|register_t
name|sf_addr
decl_stmt|;
comment|/* 	 * The following arguments are not constrained by the 	 * function call protocol. 	 * Applications are not supposed to access these members, 	 * except using the pointers we provide in the first three 	 * arguments. 	 */
union|union
block|{
name|__osiginfohandler_t
modifier|*
name|sf_action
decl_stmt|;
name|__sighandler_t
modifier|*
name|sf_handler
decl_stmt|;
block|}
name|sf_ahu
union|;
comment|/* In the SA_SIGINFO case, sf_arg2 points here. */
name|osiginfo_t
name|sf_siginfo
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|sigframe
block|{
comment|/* 	 * The first four members may be used by applications. 	 * 	 * NOTE: The 4th argument is undocumented, ill commented 	 * on and seems to be somewhat BSD "standard".  Handlers 	 * installed with sigvec may be using it. 	 */
name|register_t
name|sf_signum
decl_stmt|;
name|register_t
name|sf_siginfo
decl_stmt|;
comment|/* code or pointer to sf_si */
name|register_t
name|sf_ucontext
decl_stmt|;
comment|/* points to sf_uc */
name|register_t
name|sf_addr
decl_stmt|;
comment|/* undocumented 4th arg */
union|union
block|{
name|__siginfohandler_t
modifier|*
name|sf_action
decl_stmt|;
name|__sighandler_t
modifier|*
name|sf_handler
decl_stmt|;
block|}
name|sf_ahu
union|;
name|ucontext_t
name|sf_uc
decl_stmt|;
comment|/* = *sf_ucontext */
name|siginfo_t
name|sf_si
decl_stmt|;
comment|/* = *sf_siginfo (SA_SIGINFO case) */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_SIGFRAME_H_ */
end_comment

end_unit

