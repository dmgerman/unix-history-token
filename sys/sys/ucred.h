begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ucred.h	8.4 (Berkeley) 1/9/95  * $FreeBSD$  */
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
comment|/*  * Credentials.  *  * Please do not inspect cr_uid directly to determine superuserness.  * Only the suser()/suser_xxx() function should be used for this.  */
end_comment

begin_struct
struct|struct
name|ucred
block|{
name|u_int
name|cr_ref
decl_stmt|;
comment|/* reference count */
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
name|struct
name|uidinfo
modifier|*
name|cr_uidinfo
decl_stmt|;
comment|/* per uid resource consumption */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|cr_gid
value|cr_groups[0]
end_define

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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|change_euid
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|uid_t
name|euid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|change_ruid
name|__P
argument_list|(
operator|(
expr|struct
name|proc
operator|*
name|p
operator|,
name|uid_t
name|ruid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|crcopy
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|crdup
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|crfree
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ucred
modifier|*
name|crget
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|crhold
name|__P
argument_list|(
operator|(
expr|struct
name|ucred
operator|*
name|cr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|groupmember
name|__P
argument_list|(
operator|(
name|gid_t
name|gid
operator|,
expr|struct
name|ucred
operator|*
name|cred
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

