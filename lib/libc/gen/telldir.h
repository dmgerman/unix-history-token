begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 2000  * 	Daniel Eischen.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TELLDIR_H_
end_ifndef

begin_define
define|#
directive|define
name|_TELLDIR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_comment
comment|/*  * One of these structures is malloced to describe the current directory  * position each time telldir is called. It records the current magic  * cookie returned by getdirentries and the offset within the buffer  * associated with that return value.  */
end_comment

begin_struct
struct|struct
name|ddloc
block|{
name|LIST_ENTRY
argument_list|(
argument|ddloc
argument_list|)
name|loc_lqe
expr_stmt|;
comment|/* entry in list */
name|long
name|loc_index
decl_stmt|;
comment|/* key associated with structure */
name|off_t
name|loc_seek
decl_stmt|;
comment|/* magic cookie returned by getdirentries */
name|long
name|loc_loc
decl_stmt|;
comment|/* offset of entry in buffer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * One of these structures is malloced for each DIR to record telldir  * positions.  */
end_comment

begin_struct
struct|struct
name|_telldir
block|{
name|LIST_HEAD
argument_list|(
argument_list|,
argument|ddloc
argument_list|)
name|td_locq
expr_stmt|;
comment|/* list of locations */
name|long
name|td_loccnt
decl_stmt|;
comment|/* index of entry for sequential readdir's */
block|}
struct|;
end_struct

begin_function_decl
name|bool
name|_filldir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dirent
modifier|*
name|_readdir_unlocked
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_reclaim_telldir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_seekdir
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_fixtelldir
parameter_list|(
name|DIR
modifier|*
name|dirp
parameter_list|,
name|long
name|oldseek
parameter_list|,
name|long
name|oldloc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|RDU_SKIP
value|0x0001
end_define

begin_define
define|#
directive|define
name|RDU_SHORT
value|0x0002
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

