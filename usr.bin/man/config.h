begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)config.h	8.4 (Berkeley) 12/18/93  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_tag
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_tag
argument_list|)
name|q
expr_stmt|;
comment|/* Queue of tags. */
name|TAILQ_HEAD
argument_list|(
argument|tqh
argument_list|,
argument|_entry
argument_list|)
name|list
expr_stmt|;
comment|/* Queue of entries. */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* Associated string. */
name|size_t
name|len
decl_stmt|;
comment|/* Length of 's'. */
block|}
name|TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|_entry
argument_list|)
name|q
expr_stmt|;
comment|/* Queue of entries. */
name|char
modifier|*
name|s
decl_stmt|;
comment|/* Associated string. */
name|size_t
name|len
decl_stmt|;
comment|/* Length of 's'. */
block|}
name|ENTRY
typedef|;
end_typedef

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|_head
argument_list|,
name|_tag
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_head
name|head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|TAG
modifier|*
name|addlist
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
name|config
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
name|debug
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
name|TAG
modifier|*
name|getlist
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

