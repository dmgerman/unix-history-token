begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 Keith Muller.  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      @(#)pr.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * parameter defaults  */
end_comment

begin_define
define|#
directive|define
name|CLCNT
value|1
end_define

begin_define
define|#
directive|define
name|INCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|INGAP
value|8
end_define

begin_define
define|#
directive|define
name|OCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|OGAP
value|8
end_define

begin_define
define|#
directive|define
name|LINES
value|66
end_define

begin_define
define|#
directive|define
name|NMWD
value|5
end_define

begin_define
define|#
directive|define
name|NMCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|SCHAR
value|'\t'
end_define

begin_define
define|#
directive|define
name|PGWD
value|72
end_define

begin_define
define|#
directive|define
name|SPGWD
value|512
end_define

begin_comment
comment|/*  * misc default values  */
end_comment

begin_define
define|#
directive|define
name|HDFMT
value|"%s %s Page %d\n\n\n"
end_define

begin_define
define|#
directive|define
name|HEADLEN
value|5
end_define

begin_define
define|#
directive|define
name|TAILLEN
value|5
end_define

begin_define
define|#
directive|define
name|TIMEFMT
value|"%Ef %H:%M %Y"
end_define

begin_define
define|#
directive|define
name|FNAME
value|""
end_define

begin_define
define|#
directive|define
name|LBUF
value|8192
end_define

begin_define
define|#
directive|define
name|HDBUF
value|512
end_define

begin_comment
comment|/*  * structure for vertical columns. Used to balance cols on last page  */
end_comment

begin_struct
struct|struct
name|vcol
block|{
name|char
modifier|*
name|pt
decl_stmt|;
comment|/* ptr to col */
name|int
name|cnt
decl_stmt|;
comment|/* char count */
block|}
struct|;
end_struct

end_unit

