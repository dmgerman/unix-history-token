begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
enum|enum
block|{
name|STRING1
block|,
name|STRING2
block|}
name|which
enum|;
enum|enum
block|{
name|EOS
block|,
name|INFINITE
block|,
name|NORMAL
block|,
name|RANGE
block|,
name|SEQUENCE
block|,
name|SET
block|}
name|state
enum|;
name|int
name|cnt
decl_stmt|;
comment|/* character count */
name|int
name|lastch
decl_stmt|;
comment|/* last character */
name|int
name|equiv
index|[
literal|2
index|]
decl_stmt|;
comment|/* equivalence set */
name|int
modifier|*
name|set
decl_stmt|;
comment|/* set of characters */
name|char
modifier|*
name|str
decl_stmt|;
comment|/* user's string */
block|}
name|STR
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_define
define|#
directive|define
name|NCHARS
value|(UCHAR_MAX + 1)
end_define

begin_comment
comment|/* Number of possible characters. */
end_comment

begin_define
define|#
directive|define
name|OOBCH
value|(UCHAR_MAX + 1)
end_define

begin_comment
comment|/* Out of band character value. */
end_comment

begin_decl_stmt
name|int
name|next
name|__P
argument_list|(
operator|(
name|STR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

