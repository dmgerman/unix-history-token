begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: param.h,v 1.1 2002/01/18 20:39:24 thorpej Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Minimun size of string buffer. If this is not enough, the buffer  * is enlarged in steps of STRBLEN bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRBLEN
value|256
end_define

begin_comment
comment|/*  * This defines the size of memory blocks which are used to allocate  * memory in larger chunks.  */
end_comment

begin_define
define|#
directive|define
name|MBLKSIZ
value|((size_t)0x4000)
end_define

begin_comment
comment|/*  * Sizes of hash tables  * Should be a prime. Possible primes are  * 307, 401, 503, 601, 701, 809, 907, 1009, 1103, 1201, 1301, 1409, 1511.  *  * HSHSIZ1	symbol table 1st pass  * HSHSIZ2	symbol table 2nd pass  * THSHSIZ2	type table 2nd pass  */
end_comment

begin_define
define|#
directive|define
name|HSHSIZ1
value|503
end_define

begin_define
define|#
directive|define
name|HSHSIZ2
value|1009
end_define

begin_define
define|#
directive|define
name|THSHSIZ2
value|1009
end_define

begin_comment
comment|/*  * Pull in target-specific parameters.  */
end_comment

begin_include
include|#
directive|include
file|"targparam.h"
end_include

begin_comment
comment|/*  * Make sure this matches wchar_t.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR
value|INT
end_define

begin_comment
comment|/*  * long double only in ANSI C.  *  * And the sparc64 long double code generation is broken.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|double
name|ldbl_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|double
name|ldbl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some traditional compilers are not able to assign structures.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|STRUCT_ASSIGN
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(dest) = (src)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STRUCT_ASSIGN
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|)
value|(void)memcpy(&(dest),&(src), \ 						     sizeof (dest));
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

