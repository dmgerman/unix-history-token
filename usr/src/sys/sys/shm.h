begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.proprietary.c%  *  *	@(#)shm.h	8.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * SVID compatible shm.h file  */
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
name|struct
name|shmid_ds
modifier|*
name|shmsegs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|shminfo
name|shminfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SHM_H_ */
end_comment

end_unit

