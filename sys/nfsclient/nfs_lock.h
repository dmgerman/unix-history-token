begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Berkeley Software Design, Inc. All rights reserved.  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      from nfs_lock.h,v 2.2 1998/04/28 19:38:41 don Exp  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * lockd uses the nfssvc system call to get the unique kernel services it needs.  * It passes in a request structure with a version number at the start.  * This prevents libc from needing to change if the information passed  * between lockd and the kernel needs to change.  *  * If a structure changes, you must bump the version number.  */
end_comment

begin_include
include|#
directive|include
file|<nfs/nfsproto.h>
end_include

begin_comment
comment|/*  * The fifo where the kernel writes requests for locks on remote NFS files,  * and where lockd reads these requests.  *  */
end_comment

begin_define
define|#
directive|define
name|_PATH_NFSLCKDEV
value|"nfslock"
end_define

begin_comment
comment|/*  * This structure is used to uniquely identify the process which originated  * a particular message to lockd.  A sequence number is used to differentiate  * multiple messages from the same process.  A process start time is used to  * detect the unlikely, but possible, event of the recycling of a pid.  */
end_comment

begin_struct
struct|struct
name|lockd_msg_ident
block|{
name|pid_t
name|pid
decl_stmt|;
comment|/* The process ID. */
name|struct
name|timeval
name|pid_start
decl_stmt|;
comment|/* Start time of process id */
name|int
name|msg_seq
decl_stmt|;
comment|/* Sequence number of message */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LOCKD_MSG_VERSION
value|3
end_define

begin_comment
comment|/*  * The structure that the kernel hands us for each lock request.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|__lock_msg
block|{
name|TAILQ_ENTRY
argument_list|(
argument|__lock_msg
argument_list|)
name|lm_link
expr_stmt|;
comment|/* internal linkage */
name|int
name|lm_version
decl_stmt|;
comment|/* which version is this */
name|struct
name|lockd_msg_ident
name|lm_msg_ident
decl_stmt|;
comment|/* originator of the message */
name|struct
name|flock
name|lm_fl
decl_stmt|;
comment|/* The lock request. */
name|int
name|lm_wait
decl_stmt|;
comment|/* The F_WAIT flag. */
name|int
name|lm_getlk
decl_stmt|;
comment|/* is this a F_GETLK request */
name|struct
name|sockaddr_storage
name|lm_addr
decl_stmt|;
comment|/* The address. */
name|int
name|lm_nfsv3
decl_stmt|;
comment|/* If NFS version 3. */
name|size_t
name|lm_fh_len
decl_stmt|;
comment|/* The file handle length. */
name|struct
name|xucred
name|lm_cred
decl_stmt|;
comment|/* user cred for lock req */
name|u_int8_t
name|lm_fh
index|[
name|NFS_SMALLFH
index|]
decl_stmt|;
comment|/* The file handle. */
block|}
name|LOCKD_MSG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOCKD_ANS_VERSION
value|1
end_define

begin_struct
struct|struct
name|lockd_ans
block|{
name|int
name|la_vers
decl_stmt|;
name|struct
name|lockd_msg_ident
name|la_msg_ident
decl_stmt|;
comment|/* originator of the message */
name|int
name|la_errno
decl_stmt|;
name|int
name|la_set_getlk_pid
decl_stmt|;
comment|/* use returned pid */
name|int
name|la_getlk_pid
decl_stmt|;
comment|/* returned pid for F_GETLK */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|nfs_dolock
parameter_list|(
name|struct
name|vop_advlock_args
modifier|*
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

