begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Scooter Morris at Genentech Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lockf.h	8.2 (Berkeley) 10/26/94  */
end_comment

begin_comment
comment|/*  * The lockf structure is a kernel structure which contains the information  * associated with a byte range lock.  The lockf structures are linked into  * the inode structure. Locks are sorted by the starting byte of the lock for  * efficiency.  */
end_comment

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|locklist
argument_list|,
name|lockf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|lockf
block|{
name|short
name|lf_flags
decl_stmt|;
comment|/* Semantics: F_POSIX, F_FLOCK, F_WAIT */
name|short
name|lf_type
decl_stmt|;
comment|/* Lock type: F_RDLCK, F_WRLCK */
name|off_t
name|lf_start
decl_stmt|;
comment|/* Byte # of the start of the lock */
name|off_t
name|lf_end
decl_stmt|;
comment|/* Byte # of the end of the lock (-1=EOF) */
name|caddr_t
name|lf_id
decl_stmt|;
comment|/* Id of the resource holding the lock */
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
comment|/* Pointer to the next lock on this inode */
name|struct
name|locklist
name|lf_blkhd
decl_stmt|;
comment|/* List of requests blocked on this lock */
name|TAILQ_ENTRY
argument_list|(
argument|lockf
argument_list|)
name|lf_block
expr_stmt|;
comment|/* A request waiting for a lock */
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

