begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)dir.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/* dir.h --  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIR
end_ifndef

begin_define
define|#
directive|define
name|_DIR
end_define

begin_typedef
typedef|typedef
struct|struct
name|Path
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of directory */
name|int
name|refCount
decl_stmt|;
comment|/* Number of paths with this directory */
name|int
name|hits
decl_stmt|;
comment|/* the number of times a file in this 				 * directory has been found */
name|Hash_Table
name|files
decl_stmt|;
comment|/* Hash table of files in directory */
block|}
name|Path
typedef|;
end_typedef

begin_decl_stmt
name|void
name|Dir_Init
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_End
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Boolean
name|Dir_HasWildcards
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Expand
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dir_FindFile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Dir_MTime
name|__P
argument_list|(
operator|(
name|GNode
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_AddDir
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dir_MakeFlags
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_ClearPath
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Concat
name|__P
argument_list|(
operator|(
name|Lst
operator|,
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_PrintDirectories
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_PrintPath
name|__P
argument_list|(
operator|(
name|Lst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Dir_Destroy
name|__P
argument_list|(
operator|(
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ClientData
name|Dir_CopyDir
name|__P
argument_list|(
operator|(
name|ClientData
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIR */
end_comment

end_unit

