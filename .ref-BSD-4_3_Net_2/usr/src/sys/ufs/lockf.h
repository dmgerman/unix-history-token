begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Scooter Morris at Genentech Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)lockf.h	7.1 (Berkeley) 2/1/91  */
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

