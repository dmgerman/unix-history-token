begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)shm.h	7.2 (Berkeley) 2/5/91  *	$Id: shm.h,v 1.4 1993/10/16 17:17:37 rgrimes Exp $  */
end_comment

begin_comment
comment|/*  * SVID compatible shm.h file  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SHM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SHM_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"ipc.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|shmid_ds
block|{
name|struct
name|ipc_perm
name|shm_perm
decl_stmt|;
comment|/* operation perms */
name|int
name|shm_segsz
decl_stmt|;
comment|/* size of segment (bytes) */
name|ushort
name|shm_cpid
decl_stmt|;
comment|/* pid, creator */
name|ushort
name|shm_lpid
decl_stmt|;
comment|/* pid, last operation */
name|short
name|shm_nattch
decl_stmt|;
comment|/* no. of current attaches */
name|time_t
name|shm_atime
decl_stmt|;
comment|/* last attach time */
name|time_t
name|shm_dtime
decl_stmt|;
comment|/* last detach time */
name|time_t
name|shm_ctime
decl_stmt|;
comment|/* last change time */
name|void
modifier|*
name|shm_handle
decl_stmt|;
comment|/* internal handle for shm segment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * System 5 style catch-all structure for shared memory constants that  * might be of interest to user programs.  Do we really want/need this?  */
end_comment

begin_struct
struct|struct
name|shminfo
block|{
name|int
name|shmmax
decl_stmt|;
comment|/* max shared memory segment size (bytes) */
name|int
name|shmmin
decl_stmt|;
comment|/* min shared memory segment size (bytes) */
name|int
name|shmmni
decl_stmt|;
comment|/* max number of shared memory identifiers */
name|int
name|shmseg
decl_stmt|;
comment|/* max shared memory segments per process */
name|int
name|shmall
decl_stmt|;
comment|/* max amount of shared memory (pages) */
block|}
struct|;
end_struct

begin_comment
comment|/* internal "mode" bits */
end_comment

begin_define
define|#
directive|define
name|SHM_ALLOC
value|01000
end_define

begin_comment
comment|/* segment is allocated */
end_comment

begin_define
define|#
directive|define
name|SHM_DEST
value|02000
end_define

begin_comment
comment|/* segment will be destroyed on last detach */
end_comment

begin_comment
comment|/* SVID required constants (same values as system 5) */
end_comment

begin_define
define|#
directive|define
name|SHM_RDONLY
value|010000
end_define

begin_comment
comment|/* read-only access */
end_comment

begin_define
define|#
directive|define
name|SHM_RND
value|020000
end_define

begin_comment
comment|/* round attach address to SHMLBA boundary */
end_comment

begin_comment
comment|/* implementation constants */
end_comment

begin_define
define|#
directive|define
name|SHMLBA
value|CLBYTES
end_define

begin_comment
comment|/* segment low boundary address multiple */
end_comment

begin_define
define|#
directive|define
name|SHMMMNI
value|512
end_define

begin_comment
comment|/* maximum value for shminfo.shmmni */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|shmid_ds
modifier|*
name|shmsegs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|shminfo
name|shminfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|shmsys
name|__P
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|shmat
name|__P
argument_list|(
operator|(
name|int
operator|,
name|void
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shmget
name|__P
argument_list|(
operator|(
name|key_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shmctl
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|shmdt
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* !_SHM_H_ */
end_comment

end_unit

