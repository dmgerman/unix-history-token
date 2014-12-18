begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Advanced Computing Technologies LLC  * Written by: John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PROCCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PROCCTL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PROC_SPROTECT
value|1
end_define

begin_comment
comment|/* set protected state */
end_comment

begin_define
define|#
directive|define
name|PROC_REAP_ACQUIRE
value|2
end_define

begin_comment
comment|/* reaping enable */
end_comment

begin_define
define|#
directive|define
name|PROC_REAP_RELEASE
value|3
end_define

begin_comment
comment|/* reaping disable */
end_comment

begin_define
define|#
directive|define
name|PROC_REAP_STATUS
value|4
end_define

begin_comment
comment|/* reaping status */
end_comment

begin_define
define|#
directive|define
name|PROC_REAP_GETPIDS
value|5
end_define

begin_comment
comment|/* get descendants */
end_comment

begin_define
define|#
directive|define
name|PROC_REAP_KILL
value|6
end_define

begin_comment
comment|/* kill descendants */
end_comment

begin_comment
comment|/* Operations for PROC_SPROTECT (passed in integer arg). */
end_comment

begin_define
define|#
directive|define
name|PPROT_OP
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xf)
end_define

begin_define
define|#
directive|define
name|PPROT_SET
value|1
end_define

begin_define
define|#
directive|define
name|PPROT_CLEAR
value|2
end_define

begin_comment
comment|/* Flags for PROC_SPROTECT (ORed in with operation). */
end_comment

begin_define
define|#
directive|define
name|PPROT_FLAGS
parameter_list|(
name|x
parameter_list|)
value|((x)& ~0xf)
end_define

begin_define
define|#
directive|define
name|PPROT_DESCEND
value|0x10
end_define

begin_define
define|#
directive|define
name|PPROT_INHERIT
value|0x20
end_define

begin_comment
comment|/* Result of PREAP_STATUS (returned by value). */
end_comment

begin_struct
struct|struct
name|procctl_reaper_status
block|{
name|u_int
name|rs_flags
decl_stmt|;
name|u_int
name|rs_children
decl_stmt|;
name|u_int
name|rs_descendants
decl_stmt|;
name|pid_t
name|rs_reaper
decl_stmt|;
name|pid_t
name|rs_pid
decl_stmt|;
name|u_int
name|rs_pad0
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* struct procctl_reaper_status rs_flags */
end_comment

begin_define
define|#
directive|define
name|REAPER_STATUS_OWNED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|REAPER_STATUS_REALINIT
value|0x00000002
end_define

begin_struct
struct|struct
name|procctl_reaper_pidinfo
block|{
name|pid_t
name|pi_pid
decl_stmt|;
name|pid_t
name|pi_subtree
decl_stmt|;
name|u_int
name|pi_flags
decl_stmt|;
name|u_int
name|pi_pad0
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REAPER_PIDINFO_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|REAPER_PIDINFO_CHILD
value|0x00000002
end_define

begin_struct
struct|struct
name|procctl_reaper_pids
block|{
name|u_int
name|rp_count
decl_stmt|;
name|u_int
name|rp_pad0
index|[
literal|15
index|]
decl_stmt|;
name|struct
name|procctl_reaper_pidinfo
modifier|*
name|rp_pids
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|procctl_reaper_kill
block|{
name|int
name|rk_sig
decl_stmt|;
comment|/* in  - signal to send */
name|u_int
name|rk_flags
decl_stmt|;
comment|/* in  - REAPER_KILL flags */
name|pid_t
name|rk_subtree
decl_stmt|;
comment|/* in  - subtree, if REAPER_KILL_SUBTREE */
name|u_int
name|rk_killed
decl_stmt|;
comment|/* out - count of processes sucessfully 				   killed */
name|pid_t
name|rk_fpid
decl_stmt|;
comment|/* out - first failed pid for which error 				   is returned */
name|u_int
name|rk_pad0
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REAPER_KILL_CHILDREN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|REAPER_KILL_SUBTREE
value|0x00000002
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_function_decl
name|__BEGIN_DECLS
name|int
name|procctl
parameter_list|(
name|idtype_t
parameter_list|,
name|id_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_PROCCTL_H_ */
end_comment

end_unit

