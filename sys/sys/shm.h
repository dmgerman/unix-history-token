begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: shm.h,v 1.15 1994/06/29 06:45:17 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Adam Glass  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Adam Glass.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * As defined+described in "X/Open System Interfaces and Headers"  *                         Issue 4, p. XXX  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SHM_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SHM_H_
end_define

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_define
define|#
directive|define
name|SHM_RDONLY
value|010000
end_define

begin_comment
comment|/* Attach read-only (else read-write) */
end_comment

begin_define
define|#
directive|define
name|SHM_RND
value|020000
end_define

begin_comment
comment|/* Round attach address to SHMLBA */
end_comment

begin_define
define|#
directive|define
name|SHMLBA
value|PAGE_SIZE
end_define

begin_comment
comment|/* Segment low boundary address multiple */
end_comment

begin_comment
comment|/* "official" access mode definitions; somewhat braindead since you have    to specify (SHM_*>> 3) for group and (SHM_*>> 6) for world permissions */
end_comment

begin_define
define|#
directive|define
name|SHM_R
value|(IPC_R)
end_define

begin_define
define|#
directive|define
name|SHM_W
value|(IPC_W)
end_define

begin_comment
comment|/* predefine tbd *LOCK shmctl commands */
end_comment

begin_define
define|#
directive|define
name|SHM_LOCK
value|11
end_define

begin_define
define|#
directive|define
name|SHM_UNLOCK
value|12
end_define

begin_comment
comment|/* ipcs shmctl commands */
end_comment

begin_define
define|#
directive|define
name|SHM_STAT
value|13
end_define

begin_define
define|#
directive|define
name|SHM_INFO
value|14
end_define

begin_struct
struct|struct
name|shmid_ds
block|{
name|struct
name|ipc_perm
name|shm_perm
decl_stmt|;
comment|/* operation permission structure */
name|int
name|shm_segsz
decl_stmt|;
comment|/* size of segment in bytes */
name|pid_t
name|shm_lpid
decl_stmt|;
comment|/* process ID of last shared memory op */
name|pid_t
name|shm_cpid
decl_stmt|;
comment|/* process ID of creator */
name|short
name|shm_nattch
decl_stmt|;
comment|/* number of current attaches */
name|time_t
name|shm_atime
decl_stmt|;
comment|/* time of last shmat() */
name|time_t
name|shm_dtime
decl_stmt|;
comment|/* time of last shmdt() */
name|time_t
name|shm_ctime
decl_stmt|;
comment|/* time of last change by shmctl() */
name|void
modifier|*
name|shm_internal
decl_stmt|;
comment|/* sysv stupidity */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * System 5 style catch-all structure for shared memory constants that  * might be of interest to user programs.  Do we really want/need this?  */
end_comment

begin_struct
struct|struct
name|shminfo
block|{
name|int
name|shmmax
decl_stmt|,
comment|/* max shared memory segment size (bytes) */
name|shmmin
decl_stmt|,
comment|/* min shared memory segment size (bytes) */
name|shmmni
decl_stmt|,
comment|/* max number of shared memory identifiers */
name|shmseg
decl_stmt|,
comment|/* max shared memory segments per process */
name|shmall
decl_stmt|;
comment|/* max amount of shared memory (pages) */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|shminfo
name|shminfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|shmid_ds
modifier|*
name|shmsegs
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|shm_info
block|{
name|int
name|used_ids
decl_stmt|;
name|unsigned
name|long
name|shm_tot
decl_stmt|;
name|unsigned
name|long
name|shm_rss
decl_stmt|;
name|unsigned
name|long
name|shm_swp
decl_stmt|;
name|unsigned
name|long
name|swap_attempts
decl_stmt|;
name|unsigned
name|long
name|swap_successes
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|shmexit
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|shmfork
parameter_list|(
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|shmsys
parameter_list|(
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|shmat
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shmget
parameter_list|(
name|key_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shmctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|shmid_ds
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|shmdt
parameter_list|(
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

begin_comment
comment|/* !_KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SHM_H_ */
end_comment

end_unit

