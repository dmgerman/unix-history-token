begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)send.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_define
define|#
directive|define
name|RINIT
value|1
end_define

begin_define
define|#
directive|define
name|RENQ
value|2
end_define

begin_define
define|#
directive|define
name|RTREE
value|3
end_define

begin_define
define|#
directive|define
name|RTRFREE
value|4
end_define

begin_define
define|#
directive|define
name|RTRCHK
value|5
end_define

begin_define
define|#
directive|define
name|REVENIT
value|6
end_define

begin_define
define|#
directive|define
name|RSTRING
value|7
end_define

begin_define
define|#
directive|define
name|REVLAB
value|8
end_define

begin_define
define|#
directive|define
name|REVCNST
value|9
end_define

begin_define
define|#
directive|define
name|REVTBEG
value|10
end_define

begin_define
define|#
directive|define
name|REVTYPE
value|11
end_define

begin_define
define|#
directive|define
name|REVTEND
value|12
end_define

begin_define
define|#
directive|define
name|REVVBEG
value|13
end_define

begin_define
define|#
directive|define
name|REVVAR
value|14
end_define

begin_define
define|#
directive|define
name|REVVEND
value|15
end_define

begin_define
define|#
directive|define
name|REVFHDR
value|16
end_define

begin_define
define|#
directive|define
name|REVFFWD
value|17
end_define

begin_define
define|#
directive|define
name|REVFBDY
value|18
end_define

begin_define
define|#
directive|define
name|REVFEND
value|19
end_define

begin_define
define|#
directive|define
name|ROPUSH
value|20
end_define

begin_define
define|#
directive|define
name|ROPOP
value|21
end_define

begin_define
define|#
directive|define
name|ROSET
value|22
end_define

begin_define
define|#
directive|define
name|RKILL
value|23
end_define

begin_define
define|#
directive|define
name|RFINISH
value|24
end_define

begin_define
define|#
directive|define
name|RLAST
value|24
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|trdesc
index|[]
decl_stmt|;
end_decl_stmt

end_unit

