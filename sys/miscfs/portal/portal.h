begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software donated to Berkeley by  * Jan-Simon Pendry.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)portal.h	8.4 (Berkeley) 1/21/94  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|portal_args
block|{
name|char
modifier|*
name|pa_config
decl_stmt|;
comment|/* Config file */
name|int
name|pa_socket
decl_stmt|;
comment|/* Socket to server */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|portal_cred
block|{
name|int
name|pcr_flag
decl_stmt|;
comment|/* File open mode */
name|uid_t
name|pcr_uid
decl_stmt|;
comment|/* From ucred */
name|short
name|pcr_ngroups
decl_stmt|;
comment|/* From ucred */
name|gid_t
name|pcr_groups
index|[
name|NGROUPS
index|]
decl_stmt|;
comment|/* From ucred */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|portalmount
block|{
name|struct
name|vnode
modifier|*
name|pm_root
decl_stmt|;
comment|/* Root node */
name|struct
name|file
modifier|*
name|pm_server
decl_stmt|;
comment|/* Held reference to server socket */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|portalnode
block|{
name|int
name|pt_size
decl_stmt|;
comment|/* Length of Arg */
name|char
modifier|*
name|pt_arg
decl_stmt|;
comment|/* Arg to send to server */
name|int
name|pt_fileid
decl_stmt|;
comment|/* cookie */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VFSTOPORTAL
parameter_list|(
name|mp
parameter_list|)
value|((struct portalmount *)((mp)->mnt_data))
end_define

begin_define
define|#
directive|define
name|VTOPORTAL
parameter_list|(
name|vp
parameter_list|)
value|((struct portalnode *)(vp)->v_data)
end_define

begin_define
define|#
directive|define
name|PORTAL_ROOTFILEID
value|2
end_define

begin_decl_stmt
specifier|extern
name|vop_t
modifier|*
modifier|*
name|portal_vnodeop_p
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

