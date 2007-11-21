begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctype.h	8.4 (Berkeley) 1/21/94  *      $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTYPE_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<_ctype.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|int
name|isalnum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isalpha
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iscntrl
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isdigit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isgraph
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|islower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isprint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ispunct
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isspace
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isxdigit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_function_decl
name|int
name|_tolower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_toupper
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isascii
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|toascii
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_function_decl
name|int
name|isblank
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_function_decl
name|int
name|digittoint
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ishexnumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isideogram
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isnumber
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isphonogram
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isrune
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isspecial
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|isalnum
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_A|_CTYPE_D)
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_A)
end_define

begin_define
define|#
directive|define
name|iscntrl
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_C)
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _CTYPE_D)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

begin_define
define|#
directive|define
name|isgraph
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_G)
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_L)
end_define

begin_define
define|#
directive|define
name|isprint
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_R)
end_define

begin_define
define|#
directive|define
name|ispunct
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_P)
end_define

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_S)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_U)
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|__isctype((c), _CTYPE_X)
end_define

begin_comment
comment|/* ANSI -- locale independent */
end_comment

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|__tolower(c)
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|__toupper(c)
end_define

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/*  * POSIX.1-2001 specifies _tolower() and _toupper() to be macros equivalent to  * tolower() and toupper() respectively, minus extra checking to ensure that  * the argument is a lower or uppercase letter respectively.  We've chosen to  * implement these macros with the same error checking as tolower() and  * toupper() since this doesn't violate the specification itself, only its  * intent.  We purposely leave _tolower() and _toupper() undocumented to  * discourage their use.  *  * XXX isascii() and toascii() should similarly be undocumented.  */
end_comment

begin_define
define|#
directive|define
name|_tolower
parameter_list|(
name|c
parameter_list|)
value|__tolower(c)
end_define

begin_define
define|#
directive|define
name|_toupper
parameter_list|(
name|c
parameter_list|)
value|__toupper(c)
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|(((c)& ~0x7F) == 0)
end_define

begin_define
define|#
directive|define
name|toascii
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x7F)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_define
define|#
directive|define
name|isblank
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_B)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|digittoint
parameter_list|(
name|c
parameter_list|)
value|__maskrune((c), 0xFF)
end_define

begin_define
define|#
directive|define
name|ishexnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_X)
end_define

begin_define
define|#
directive|define
name|isideogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_I)
end_define

begin_define
define|#
directive|define
name|isnumber
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_D)
end_define

begin_define
define|#
directive|define
name|isphonogram
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_Q)
end_define

begin_define
define|#
directive|define
name|isrune
parameter_list|(
name|c
parameter_list|)
value|__istype((c), 0xFFFFFF00L)
end_define

begin_define
define|#
directive|define
name|isspecial
parameter_list|(
name|c
parameter_list|)
value|__istype((c), _CTYPE_T)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CTYPE_H_ */
end_comment

end_unit

