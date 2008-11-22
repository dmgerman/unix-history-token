begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ucred.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_UCRED_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_UCRED_H_
end_define

begin_comment
comment|/*  * Credentials.  *  * Please do not inspect cr_uid directly to determine superuserness.  * Only the suser() or suser_cred() function should be used for this.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_UCRED
argument_list|)
end_if

begin_struct
struct|struct
name|ucred
block|{
name|u_int
name|cr_ref
decl_stmt|;
comment|/* reference count */
define|#
directive|define
name|cr_startcopy
value|cr_uid
name|uid_t
name|cr_uid
decl_stmt|;
comment|/* effective user id */
name|uid_t
name|cr_ruid
decl_stmt|;
comment|/* real user id */
name|uid_t
name|cr_svuid
decl_stmt|;
comment|/* saved user id */
name|short
name|cr_ngroups
decl_stmt|;
comment|/* number of groups */
name|gid_t
name|cr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* groups */
name|gid_t
name|cr_rgid
decl_stmt|;
comment|/* real group id */
name|gid_t
name|cr_svgid
decl_stmt|;
comment|/* saved group id */
name|struct
name|uidinfo
modifier|*
name|cr_uidinfo
decl_stmt|;
comment|/* per euid resource consumption */
name|struct
name|uidinfo
modifier|*
name|cr_ruidinfo
decl_stmt|;
comment|/* per ruid resource consumption */
name|struct
name|prison
modifier|*
name|cr_prison
decl_stmt|;
comment|/* jail(2) */
define|#
directive|define
name|cr_endcopy
value|cr_label
name|struct
name|label
modifier|*
name|cr_label
decl_stmt|;
comment|/* MAC label */
name|void
modifier|*
name|cr_pad0
decl_stmt|;
comment|/* dummy, for KBI compat */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NOCRED
value|((struct ucred *)0)
end_define

begin_comment
comment|/* no credential available */
end_comment

begin_define
define|#
directive|define
name|FSCRED
value|((struct ucred *)-1)
end_define

begin_comment
comment|/* filesystem credential */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL || _WANT_UCRED */
end_comment

begin_comment
comment|/*  * This is the external representation of struct ucred.  */
end_comment

begin_struct
struct|struct
name|xucred
block|{
name|u_int
name|cr_version
decl_stmt|;
comment|/* structure layout version */
name|uid_t
name|cr_uid
decl_stmt|;
comment|/* effective user id */
name|short
name|cr_ngroups
decl_stmt|;
comment|/* number of groups */
name|gid_t
name|cr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* groups */
name|void
modifier|*
name|_cr_unused1
decl_stmt|;
comment|/* compatibility with old ucred */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XUCRED_VERSION
value|0
end_define

begin_comment
comment|/* This can be used for both ucred and xucred structures. */
end_comment

begin_define
define|#
directive|define
name|cr_gid
value|cr_groups[0]
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|change_egid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|gid_t
name|egid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_euid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|struct
name|uidinfo
modifier|*
name|euip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_rgid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|gid_t
name|rgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_ruid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|struct
name|uidinfo
modifier|*
name|ruip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_svgid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|gid_t
name|svgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|change_svuid
parameter_list|(
name|struct
name|ucred
modifier|*
name|newcred
parameter_list|,
name|uid_t
name|svuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crcopy
parameter_list|(
name|struct
name|ucred
modifier|*
name|dest
parameter_list|,
name|struct
name|ucred
modifier|*
name|src
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crdup
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cred_update_thread
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|crfree
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crget
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ucred
modifier|*
name|crhold
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|crshared
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cru2x
parameter_list|(
name|struct
name|ucred
modifier|*
name|cr
parameter_list|,
name|struct
name|xucred
modifier|*
name|xcr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|groupmember
parameter_list|(
name|gid_t
name|gid
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_SYS_UCRED_H_ */
end_comment

end_unit

