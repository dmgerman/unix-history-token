begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Scooter Morris at Genentech Inc.  *  * %sccs.include.redist.c%  *  *	@(#)lockf.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The lockf structure is a kernel structure which contains all the  * information associated with a byte range lock. The lockf structures  * are linked into the inode structure. Locks are sorted by the starting  * byte of the lock for efficiency.  */
end_comment

begin_struct
struct|struct
name|lockf
block|{
name|short
name|lf_flags
decl_stmt|;
comment|/* Lock semantics: F_POSIX, F_FLOCK, F_WAIT */
name|short
name|lf_type
decl_stmt|;
comment|/* Lock type: F_RDLCK, F_WRLCK */
name|off_t
name|lf_start
decl_stmt|;
comment|/* The byte # of the start of the lock */
name|off_t
name|lf_end
decl_stmt|;
comment|/* The byte # of the end of the lock (-1=EOF)*/
name|caddr_t
name|lf_id
decl_stmt|;
comment|/* The id of the resource holding the lock */
name|struct
name|inode
modifier|*
name|lf_inode
decl_stmt|;
comment|/* Back pointer to the inode */
name|struct
name|lockf
modifier|*
name|lf_next
decl_stmt|;
comment|/* A pointer to the next lock on this inode */
name|struct
name|lockf
modifier|*
name|lf_block
decl_stmt|;
comment|/* The list of blocked locks */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Maximum length of sleep chains to traverse to try and detect deadlock.  */
end_comment

begin_define
define|#
directive|define
name|MAXDEPTH
value|50
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Public lock manipulation routines  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|lockf
modifier|*
name|lf_remove
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Remove a lock */
end_comment

begin_function_decl
specifier|extern
name|struct
name|lockf
modifier|*
name|lf_getblock
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return the first blocking lock */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOCKF_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|lockf_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|LOCKF_DEBUG
end_endif

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

