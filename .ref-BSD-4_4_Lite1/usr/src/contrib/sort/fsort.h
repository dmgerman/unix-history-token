begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Peter McIlroy.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fsort.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|POW
value|20
end_define

begin_comment
comment|/* exponent for buffer size */
end_comment

begin_define
define|#
directive|define
name|BUFSIZE
value|(1<< POW)
end_define

begin_define
define|#
directive|define
name|MAXNUM
value|(BUFSIZE/10)
end_define

begin_comment
comment|/* lowish guess at average record size */
end_comment

begin_define
define|#
directive|define
name|BUFFEND
value|(EOF-2)
end_define

begin_define
define|#
directive|define
name|MAXFCT
value|1000
end_define

begin_define
define|#
directive|define
name|MAXLLEN
value|((1<< min(POW-4, 16)) - 14)
end_define

begin_decl_stmt
specifier|extern
name|u_char
modifier|*
modifier|*
name|keylist
decl_stmt|,
modifier|*
modifier|*
name|l2buf
decl_stmt|,
modifier|*
name|buffer
decl_stmt|,
modifier|*
name|linebuf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* temp files in the stack have a file descriptor, a largest bin (maxb)  * which becomes the last non-empty bin (lastb) when the actual largest  * bin is smaller than max(half the total file, BUFSIZE)  * Max_o is the offset of maxb so it can be sought after the other bins  * are sorted. */
end_comment

begin_struct
struct|struct
name|tempfile
block|{
name|FILE
modifier|*
name|fd
decl_stmt|;
name|u_char
name|maxb
decl_stmt|;
name|u_char
name|lastb
decl_stmt|;
name|long
name|max_o
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|tempfile
name|fstack
index|[
name|MAXFCT
index|]
decl_stmt|;
end_decl_stmt

end_unit

