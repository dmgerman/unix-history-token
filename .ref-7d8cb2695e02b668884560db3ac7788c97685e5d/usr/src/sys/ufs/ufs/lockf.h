begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Scooter Morris at Genentech Inc.  *  * %sccs.include.redist.c%  *  *	@(#)lockf.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The lockf structure is a kernel structure which contains the information  * associated with a byte range lock.  The lockf structures are linked into  * the inode structure. Locks are sorted by the starting byte of the lock for  * efficiency.  */
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
comment|/* Maximum length of sleep chains to traverse to try and detect deadlock. */
end_comment

begin_define
define|#
directive|define
name|MAXDEPTH
value|50
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|lf_addblock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|,
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lf_clearlock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lf_findoverlap
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|,
expr|struct
name|lockf
operator|*
operator|,
name|int
operator|,
expr|struct
name|lockf
operator|*
operator|*
operator|*
operator|,
expr|struct
name|lockf
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|lockf
modifier|*
name|lf_getblock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lf_getlock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|,
expr|struct
name|flock
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lf_setlock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lf_split
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|,
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lf_wakelock
name|__P
argument_list|(
operator|(
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__END_DECLS
ifdef|#
directive|ifdef
name|LOCKF_DEBUG
specifier|extern
name|int
name|lockf_debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|lf_print
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|lockf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lf_printlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
expr|struct
name|lockf
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

end_unit

