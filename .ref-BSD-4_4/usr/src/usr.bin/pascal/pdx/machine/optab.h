begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)optab.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * px opcode information structure  */
end_comment

begin_define
define|#
directive|define
name|MAXNARGS
value|10
end_define

begin_comment
comment|/*  * argument types  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ARGTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ADDR2
value|1
end_define

begin_define
define|#
directive|define
name|ADDR4
value|2
end_define

begin_define
define|#
directive|define
name|DISP
value|3
end_define

begin_define
define|#
directive|define
name|PSUBOP
value|5
end_define

begin_define
define|#
directive|define
name|SUBOP
value|6
end_define

begin_define
define|#
directive|define
name|VLEN
value|7
end_define

begin_define
define|#
directive|define
name|HWORD
value|8
end_define

begin_define
define|#
directive|define
name|LWORD
value|9
end_define

begin_define
define|#
directive|define
name|STRING
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|opname
decl_stmt|;
name|ARGTYPE
name|argtype
index|[
name|MAXNARGS
index|]
decl_stmt|;
block|}
name|OPTAB
typedef|;
end_typedef

begin_decl_stmt
name|OPTAB
name|optab
index|[]
decl_stmt|;
end_decl_stmt

end_unit

