begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ken Arnold.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)strfile.h	8.1 (Berkeley) 5/31/93  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|STR_ENDSTRING
parameter_list|(
name|line
parameter_list|,
name|tbl
parameter_list|)
define|\
value|(((unsigned char)(line)[0]) == (tbl).str_delim&& (line)[1] == '\n')
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* information table */
define|#
directive|define
name|VERSION
value|1
name|unsigned
name|long
name|str_version
decl_stmt|;
comment|/* version number */
name|unsigned
name|long
name|str_numstr
decl_stmt|;
comment|/* # of strings in the file */
name|unsigned
name|long
name|str_longlen
decl_stmt|;
comment|/* length of longest string */
name|unsigned
name|long
name|str_shortlen
decl_stmt|;
comment|/* length of shortest string */
define|#
directive|define
name|STR_RANDOM
value|0x1
comment|/* randomized pointers */
define|#
directive|define
name|STR_ORDERED
value|0x2
comment|/* ordered pointers */
define|#
directive|define
name|STR_ROTATED
value|0x4
comment|/* rot-13'd text */
define|#
directive|define
name|STR_COMMENTS
value|0x8
comment|/* embedded comments */
name|unsigned
name|long
name|str_flags
decl_stmt|;
comment|/* bit field for flags */
name|unsigned
name|char
name|stuff
index|[
literal|4
index|]
decl_stmt|;
comment|/* long aligned space */
define|#
directive|define
name|str_delim
value|stuff[0]
comment|/* delimiting character */
block|}
name|STRFILE
typedef|;
end_typedef

end_unit

