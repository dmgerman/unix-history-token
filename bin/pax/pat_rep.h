begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Keith Muller.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Keith Muller of the University of California, San Diego.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)pat_rep.h	8.1 (Berkeley) 5/31/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * data structure for storing user supplied replacement strings (-s)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|replace
block|{
name|char
modifier|*
name|nstr
decl_stmt|;
comment|/* the new string we will substitute with */
ifdef|#
directive|ifdef
name|NET2_REGEX
name|regexp
modifier|*
name|rcmp
decl_stmt|;
comment|/* compiled regular expression used to match */
else|#
directive|else
name|regex_t
name|rcmp
decl_stmt|;
comment|/* compiled regular expression used to match */
endif|#
directive|endif
name|int
name|flgs
decl_stmt|;
comment|/* print conversions? global in operation?  */
define|#
directive|define
name|PRNT
value|0x1
define|#
directive|define
name|GLOB
value|0x2
name|struct
name|replace
modifier|*
name|fow
decl_stmt|;
comment|/* pointer to next pattern */
block|}
name|REPLACE
typedef|;
end_typedef

end_unit

