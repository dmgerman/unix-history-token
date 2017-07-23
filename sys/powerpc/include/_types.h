begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Mike Barcroft<mike@FreeBSD.org>  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)ansi.h	8.2 (Berkeley) 1/4/94  *	From: @(#)types.h	8.3 (Berkeley) 1/5/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE__TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE__TYPES_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_error
error|#
directive|error
error|this file needs sys/cdefs.h as a prerequisite
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Basic types upon which most other types are built.  */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|__int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|__int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint32_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_typedef
typedef|typedef
name|long
name|__int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_macro
name|__extension__
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONGLONG */
end_comment

begin_typedef
typedef|typedef
name|long
name|long
name|__int64_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_macro
name|__extension__
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LONGLONG */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|__uint64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Standard type definitions.  */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__clock_t
typedef|;
end_typedef

begin_comment
comment|/* clock()... */
end_comment

begin_typedef
typedef|typedef
name|double
name|__double_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|__float_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_typedef
typedef|typedef
name|__int64_t
name|__critical_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__intfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__intptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__int32_t
name|__critical_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__intfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__int64_t
name|__intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int8_t
name|__int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16_t
name|__int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__int_least64_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_typedef
typedef|typedef
name|__int64_t
name|__ptrdiff_t
typedef|;
end_typedef

begin_comment
comment|/* ptr1 - ptr2 */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|__register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size (in pages) */
end_comment

begin_typedef
typedef|typedef
name|__uint64_t
name|__size_t
typedef|;
end_typedef

begin_comment
comment|/* sizeof() */
end_comment

begin_typedef
typedef|typedef
name|__int64_t
name|__ssize_t
typedef|;
end_typedef

begin_comment
comment|/* byte count or error */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__int32_t
name|__ptrdiff_t
typedef|;
end_typedef

begin_comment
comment|/* ptr1 - ptr2 */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|__register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__segsz_t
typedef|;
end_typedef

begin_comment
comment|/* segment size (in pages) */
end_comment

begin_typedef
typedef|typedef
name|__uint32_t
name|__size_t
typedef|;
end_typedef

begin_comment
comment|/* sizeof() */
end_comment

begin_typedef
typedef|typedef
name|__int32_t
name|__ssize_t
typedef|;
end_typedef

begin_comment
comment|/* byte count or error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__int64_t
name|__time_t
typedef|;
end_typedef

begin_comment
comment|/* time()... */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uintfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uintptr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint32_t
name|__uintfptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__uintptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint64_t
name|__uintmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__uint_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__uint_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__uint_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uint_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint8_t
name|__uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|__uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uint_least64_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_typedef
typedef|typedef
name|__uint64_t
name|__u_register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__vm_offset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__vm_paddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__vm_size_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint32_t
name|__u_register_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint32_t
name|__vm_offset_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BOOKE
end_ifdef

begin_typedef
typedef|typedef
name|__uint64_t
name|__vm_paddr_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|__uint32_t
name|__vm_paddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__uint32_t
name|__vm_size_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
name|___wchar_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__WCHAR_MIN
value|__INT_MIN
end_define

begin_comment
comment|/* min value for a wchar_t */
end_comment

begin_define
define|#
directive|define
name|__WCHAR_MAX
value|__INT_MAX
end_define

begin_comment
comment|/* max value for a wchar_t */
end_comment

begin_comment
comment|/*  * Unusual type definitions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_BUILTIN_VARARGS
argument_list|)
end_if

begin_typedef
typedef|typedef
name|__builtin_va_list
name|__va_list
typedef|;
end_typedef

begin_comment
comment|/* internally known to gcc */
end_comment

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|__gpr
decl_stmt|;
name|char
name|__fpr
decl_stmt|;
name|char
name|__pad
index|[
literal|2
index|]
decl_stmt|;
name|char
modifier|*
name|__stack
decl_stmt|;
name|char
modifier|*
name|__base
decl_stmt|;
block|}
name|__va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* post GCC 2.95 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC_VA_LIST_COMPATIBILITY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC_VA_LIST
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|__NO_GNUC_VA_LIST
argument_list|)
end_if

begin_define
define|#
directive|define
name|__GNUC_VA_LIST
end_define

begin_typedef
typedef|typedef
name|__va_list
name|__gnuc_va_list
typedef|;
end_typedef

begin_comment
comment|/* compatibility w/GNU headers*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE__TYPES_H_ */
end_comment

end_unit

