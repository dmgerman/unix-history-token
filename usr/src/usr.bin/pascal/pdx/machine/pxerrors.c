begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)pxerrors.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * px error messages  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pxerrmsg
index|[]
init|=
block|{
literal|"not an error!"
block|,
literal|"argument to chr out of range"
block|,
literal|"div (integer divide) by zero"
block|,
literal|"real divide by zero"
block|,
literal|"call to procedure halt"
block|,
literal|"reference through a nil pointer"
block|,
literal|"tried to read past end-of-file"
block|,
literal|"negative parameter to sqrt"
block|,
literal|"pi/px error: stack not empty"
block|,
literal|"subscript out of range"
block|,
literal|"reference to an inactive file"
block|,
literal|"pi/px error: write failed"
block|,
literal|"pi/px error: create failed"
block|,
literal|"non-positive argument to ln"
block|,
literal|"pi/px error: bad op"
block|,
literal|"bad data on integer read"
block|,
literal|"pi/px error: active frame not found in goto"
block|,
literal|"label not found in case"
block|,
literal|"pi/px error: seek failed"
block|,
literal|"pi/px error: bad parameter to alloc"
block|,
literal|"out of memory"
block|,
literal|"constructed set parameter exceeds set bounds"
block|,
literal|"too many digits in number"
block|,
literal|"mod (integer remainder) by 0"
block|,
literal|"bad data on real read"
block|,
literal|"pi/px error: remove failed"
block|,
literal|"pi/px error: close failed"
block|,
literal|"pi/px error: open failed"
block|,
literal|"parameter to argv out of range"
block|,
literal|"bad i to pack(a, i, z)"
block|,
literal|"bad i to unpack(z, a, i)"
block|,
literal|"value out of range"
block|,
literal|"assertion failed"
block|,
literal|"tried to read, but open for writing"
block|,
literal|"tried to write, but open for reading"
block|,
literal|"integer number too large"
block|,
literal|"statement limit exceeded"
block|,
literal|"runtime stack overflow"
block|,
literal|"interrupt"
block|,
literal|"overflow, underflow, or divide by zero in arithmetic operation"
block|, }
decl_stmt|;
end_decl_stmt

end_unit

