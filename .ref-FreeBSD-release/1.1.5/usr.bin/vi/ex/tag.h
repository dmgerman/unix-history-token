begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)tag.h	8.11 (Berkeley) 11/22/93  */
end_comment

begin_struct
struct|struct
name|_tagf
block|{
comment|/* Tag file. */
name|TAILQ_ENTRY
argument_list|(
argument|_tagf
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of tag files. */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Tag file name. */
define|#
directive|define
name|TAGF_DNE
value|0x01
comment|/* Didn't exist. */
define|#
directive|define
name|TAGF_DNE_WARN
value|0x02
comment|/* DNE error reported. */
name|u_char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_tag
block|{
comment|/* Tag stack. */
name|TAILQ_ENTRY
argument_list|(
argument|_tag
argument_list|)
name|q
expr_stmt|;
comment|/* Linked list of tags. */
name|FREF
modifier|*
name|frp
decl_stmt|;
comment|/* Saved file name. */
name|recno_t
name|lno
decl_stmt|;
comment|/* Saved line number. */
name|size_t
name|cno
decl_stmt|;
comment|/* Saved column number. */
name|char
modifier|*
name|search
decl_stmt|;
comment|/* Search string. */
name|size_t
name|slen
decl_stmt|;
comment|/* Search string length. */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|ex_tagalloc
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_tagcopy
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_tagdisplay
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|EXF
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_tagfirst
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ex_tagfree
name|__P
argument_list|(
operator|(
name|SCR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

