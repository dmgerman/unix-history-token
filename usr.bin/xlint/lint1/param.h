begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: param.h,v 1.4 1995/07/23 18:14:41 ragge Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994, 1995 Jochen Pohl  * All Rights Reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Jochen Pohl for  *	The NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/*  * Should be set to 1 if the difference of two pointers is of type long  * or the value of sizeof is of type unsigned long.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|1
end_define

begin_elif
elif|#
directive|elif
name|__alpha__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|1
end_define

begin_elif
elif|#
directive|elif
name|__i386__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|0
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|0
end_define

begin_elif
elif|#
directive|elif
name|__m68k__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|0
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|0
end_define

begin_elif
elif|#
directive|elif
name|__ns32k__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|0
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|0
end_define

begin_elif
elif|#
directive|elif
name|__sparc__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|0
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|0
end_define

begin_elif
elif|#
directive|elif
name|__sparc64__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|1
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|1
end_define

begin_elif
elif|#
directive|elif
name|__vax__
end_elif

begin_define
define|#
directive|define
name|PTRDIFF_IS_LONG
value|0
end_define

begin_define
define|#
directive|define
name|SIZEOF_IS_ULONG
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|unknown machine type
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Make sure this matches wchar_t.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR
value|SHORT
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|QUAD_MAX
end_ifndef

begin_comment
comment|/* necessary for mkdep */
end_comment

begin_define
define|#
directive|define
name|QUAD_MAX
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|QUAD_MIN
value|LONG_MIN
end_define

begin_define
define|#
directive|define
name|UQUAD_MAX
value|ULONG_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|quad_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_long
name|u_quad_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * long double only in ANSI C.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

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

