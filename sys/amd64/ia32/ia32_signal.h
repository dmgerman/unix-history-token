begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * Copyright (c) 2003 Peter Wemm  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|ia32_sigaltstack
block|{
name|u_int32_t
name|ss_sp
decl_stmt|;
comment|/* signal stack base */
name|u_int32_t
name|ss_size
decl_stmt|;
comment|/* signal stack length */
name|int
name|ss_flags
decl_stmt|;
comment|/* SS_DISABLE and/or SS_ONSTACK */
block|}
struct|;
end_struct

begin_comment
comment|/* XXX should be 640 bytes long; check and see if __packed is needed */
end_comment

begin_struct
struct|struct
name|ia32_mcontext
block|{
name|int
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|int
name|mc_gs
decl_stmt|;
comment|/* machine state (struct trapframe) */
name|int
name|mc_fs
decl_stmt|;
name|int
name|mc_es
decl_stmt|;
name|int
name|mc_ds
decl_stmt|;
name|int
name|mc_edi
decl_stmt|;
name|int
name|mc_esi
decl_stmt|;
name|int
name|mc_ebp
decl_stmt|;
name|int
name|mc_isp
decl_stmt|;
name|int
name|mc_ebx
decl_stmt|;
name|int
name|mc_edx
decl_stmt|;
name|int
name|mc_ecx
decl_stmt|;
name|int
name|mc_eax
decl_stmt|;
name|int
name|mc_trapno
decl_stmt|;
name|int
name|mc_err
decl_stmt|;
name|int
name|mc_eip
decl_stmt|;
name|int
name|mc_cs
decl_stmt|;
name|int
name|mc_eflags
decl_stmt|;
name|int
name|mc_esp
decl_stmt|;
name|int
name|mc_ss
decl_stmt|;
name|int
name|mc_len
decl_stmt|;
comment|/* sizeof(struct ia32_mcontext) */
comment|/* We use the same values for fpformat and ownedfp */
name|int
name|mc_fpformat
decl_stmt|;
name|int
name|mc_ownedfp
decl_stmt|;
name|int
name|mc_spare1
index|[
literal|1
index|]
decl_stmt|;
comment|/* align next field to 16 bytes */
comment|/* 	 * See<machine/npx.h> for the internals of mc_fpstate[]. 	 */
name|int
name|mc_fpstate
index|[
literal|128
index|]
name|__aligned
argument_list|(
literal|16
argument_list|)
decl_stmt|;
name|int
name|mc_spare2
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX should be 704 bytes long; check and see if __packed is needed */
end_comment

begin_struct
struct|struct
name|ia32_ucontext
block|{
name|sigset_t
name|uc_sigmask
decl_stmt|;
name|struct
name|ia32_mcontext
name|uc_mcontext
decl_stmt|;
name|u_int32_t
name|uc_link
decl_stmt|;
name|struct
name|ia32_sigaltstack
name|uc_stack
decl_stmt|;
name|int
name|uc_flags
decl_stmt|;
name|int
name|__spare__
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPAT_FREEBSD4
argument_list|)
end_if

begin_struct
struct|struct
name|ia32_mcontext4
block|{
name|int
name|mc_onstack
decl_stmt|;
comment|/* XXX - sigcontext compat. */
name|int
name|mc_gs
decl_stmt|;
comment|/* machine state (struct trapframe) */
name|int
name|mc_fs
decl_stmt|;
name|int
name|mc_es
decl_stmt|;
name|int
name|mc_ds
decl_stmt|;
name|int
name|mc_edi
decl_stmt|;
name|int
name|mc_esi
decl_stmt|;
name|int
name|mc_ebp
decl_stmt|;
name|int
name|mc_isp
decl_stmt|;
name|int
name|mc_ebx
decl_stmt|;
name|int
name|mc_edx
decl_stmt|;
name|int
name|mc_ecx
decl_stmt|;
name|int
name|mc_eax
decl_stmt|;
name|int
name|mc_trapno
decl_stmt|;
name|int
name|mc_err
decl_stmt|;
name|int
name|mc_eip
decl_stmt|;
name|int
name|mc_cs
decl_stmt|;
name|int
name|mc_eflags
decl_stmt|;
name|int
name|mc_esp
decl_stmt|;
name|int
name|mc_ss
decl_stmt|;
name|int
name|mc_fpregs
index|[
literal|28
index|]
decl_stmt|;
name|int
name|__spare__
index|[
literal|17
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ia32_ucontext4
block|{
name|sigset_t
name|uc_sigmask
decl_stmt|;
name|struct
name|ia32_mcontext4
name|uc_mcontext
decl_stmt|;
name|u_int32_t
name|uc_link
decl_stmt|;
name|struct
name|ia32_sigaltstack
name|uc_stack
decl_stmt|;
name|int
name|__spare__
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Signal frames, arguments passed to application signal handlers.  */
end_comment

begin_union
union|union
name|ia32_sigval
block|{
name|int
name|sigval_int
decl_stmt|;
name|u_int32_t
name|sigval_ptr
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ia32_siginfo
block|{
name|int
name|si_signo
decl_stmt|;
comment|/* signal number */
name|int
name|si_errno
decl_stmt|;
comment|/* errno association */
name|int
name|si_code
decl_stmt|;
comment|/* signal code */
name|int32_t
name|si_pid
decl_stmt|;
comment|/* sending process */
name|u_int32_t
name|si_uid
decl_stmt|;
comment|/* sender's ruid */
name|int
name|si_status
decl_stmt|;
comment|/* exit value */
name|u_int32_t
name|si_addr
decl_stmt|;
comment|/* faulting instruction */
name|union
name|ia32_sigval
name|si_value
decl_stmt|;
comment|/* signal value */
name|int32_t
name|si_band
decl_stmt|;
comment|/* band event for SIGPOLL */
name|int
name|__spare__
index|[
literal|7
index|]
decl_stmt|;
comment|/* gimme some slack */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD4
end_ifdef

begin_struct
struct|struct
name|ia32_sigframe4
block|{
name|u_int32_t
name|sf_signum
decl_stmt|;
name|u_int32_t
name|sf_siginfo
decl_stmt|;
comment|/* code or pointer to sf_si */
name|u_int32_t
name|sf_ucontext
decl_stmt|;
comment|/* points to sf_uc */
name|u_int32_t
name|sf_addr
decl_stmt|;
comment|/* undocumented 4th arg */
name|u_int32_t
name|sf_ah
decl_stmt|;
comment|/* action/handler pointer */
name|struct
name|ia32_ucontext4
name|sf_uc
decl_stmt|;
comment|/* = *sf_ucontext */
name|struct
name|ia32_siginfo
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

begin_struct
struct|struct
name|ia32_sigframe
block|{
name|u_int32_t
name|sf_signum
decl_stmt|;
name|u_int32_t
name|sf_siginfo
decl_stmt|;
comment|/* code or pointer to sf_si */
name|u_int32_t
name|sf_ucontext
decl_stmt|;
comment|/* points to sf_uc */
name|u_int32_t
name|sf_addr
decl_stmt|;
comment|/* undocumented 4th arg */
name|u_int32_t
name|sf_ah
decl_stmt|;
comment|/* action/handler pointer */
name|struct
name|ia32_ucontext
name|sf_uc
decl_stmt|;
comment|/* = *sf_ucontext */
name|struct
name|ia32_siginfo
name|sf_si
decl_stmt|;
comment|/* = *sf_siginfo (SA_SIGINFO case) */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|ia32_sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|freebsd4_ia32_sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sz_ia32_sigcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sz_freebsd4_ia32_sigcode
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ia32_sendsig
parameter_list|(
name|sig_t
parameter_list|,
name|int
parameter_list|,
name|sigset_t
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

end_unit

