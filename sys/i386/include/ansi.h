begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ansi.h	8.2 (Berkeley) 1/4/94  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ANSI_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ANSI_H_
end_define

begin_comment
comment|/*  * Types which are fundamental to the implementation and may appear in  * more than one standard header are defined here.  Standard headers  * then use:  *	#ifdef	_BSD_SIZE_T_  *	typedef	_BSD_SIZE_T_	size_t;  *	#undef	_BSD_SIZE_T_  *	#endif  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLOCK_T_
value|unsigned long
end_define

begin_comment
comment|/* clock()... */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLOCKID_T_
value|int
end_define

begin_comment
comment|/* clock_gettime()... */
end_comment

begin_define
define|#
directive|define
name|_BSD_FFLAGS_T_
value|__uint_least32_t
end_define

begin_comment
comment|/* file flags */
end_comment

begin_define
define|#
directive|define
name|_BSD_MBSTATE_T_
value|__mbstate_t
end_define

begin_comment
comment|/* mbstate_t */
end_comment

begin_define
define|#
directive|define
name|_BSD_PTRDIFF_T_
value|int
end_define

begin_comment
comment|/* ptr1 - ptr2 */
end_comment

begin_define
define|#
directive|define
name|_BSD_RUNE_T_
value|_BSD_CT_RUNE_T_
end_define

begin_comment
comment|/* rune_t (see below) */
end_comment

begin_define
define|#
directive|define
name|_BSD_SIZE_T_
value|unsigned int
end_define

begin_comment
comment|/* sizeof() */
end_comment

begin_define
define|#
directive|define
name|_BSD_SOCKLEN_T_
value|__uint32_t
end_define

begin_comment
comment|/* socklen_t (duh) */
end_comment

begin_define
define|#
directive|define
name|_BSD_SSIZE_T_
value|int
end_define

begin_comment
comment|/* byte count or error */
end_comment

begin_define
define|#
directive|define
name|_BSD_TIME_T_
value|int
end_define

begin_comment
comment|/* time()... */
end_comment

begin_define
define|#
directive|define
name|_BSD_TIMER_T_
value|int
end_define

begin_comment
comment|/* timer_gettime()... */
end_comment

begin_define
define|#
directive|define
name|_BSD_WCHAR_T_
value|_BSD_CT_RUNE_T_
end_define

begin_comment
comment|/* wchar_t (see below) */
end_comment

begin_define
define|#
directive|define
name|_BSD_WINT_T_
value|_BSD_CT_RUNE_T_
end_define

begin_comment
comment|/* wint_t (see below) */
end_comment

begin_comment
comment|/*  * Types which are fundamental to the implementation and must be used  * in more than one standard header although they are only declared in  * one (perhaps nonstandard) header are defined here.  Standard headers  * use _BSD_XXX_T_ without undef'ing it.  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CT_RUNE_T_
value|int
end_define

begin_comment
comment|/* arg type for ctype funcs */
end_comment

begin_define
define|#
directive|define
name|_BSD_OFF_T_
value|__int64_t
end_define

begin_comment
comment|/* file offset */
end_comment

begin_define
define|#
directive|define
name|_BSD_PID_T_
value|int
end_define

begin_comment
comment|/* process [group] */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|>
literal|2
operator|||
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>
literal|95
operator|)
end_if

begin_define
define|#
directive|define
name|_BSD_VA_LIST_
value|__builtin_va_list
end_define

begin_comment
comment|/* internally known to gcc */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BSD_VA_LIST_
value|char *
end_define

begin_comment
comment|/* va_list */
end_comment

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
name|__GNUC__
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC_VA_LIST
argument_list|)
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
name|_BSD_VA_LIST_
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

begin_comment
comment|/*  * The rune type above is declared to be an ``int'' instead of the more natural  * ``unsigned long'' or ``long''.  Two things are happening here.  It is not  * unsigned so that EOF (-1) can be naturally assigned to it and used.  Also,  * it looks like 10646 will be a 31 bit standard.  This means that if your  * ints cannot hold 32 bits, you will be in trouble.  The reason an int was  * chosen over a long is that the is*() and to*() routines take ints (says  * ANSI C), but they use _BSD_CT_RUNE_T_ instead of int.  By changing it  * here, you lose a bit of ANSI conformance, but your programs will still  * work.  *  * NOTE: rune_t is not covered by ANSI nor other standards, and should not  * be instantiated outside of lib/libc/locale.  Use wchar_t.  wchar_t and  * rune_t must be the same type.  Also wint_t must be no narrower than  * wchar_t, and should also be able to hold all members of the largest  * character set plus one extra value (WEOF). wint_t must be at least 16 bits.  */
end_comment

begin_comment
comment|/*  * Frequencies of the clock ticks reported by clock() and times().  They  * are the same as stathz for bogus historical reasons.  They should be  * 1e6 because clock() and times() are implemented using getrusage() and  * there is no good reason why they should be less accurate.  There is  * the bad reason that (broken) programs might not like clock_t or  * CLOCKS_PER_SEC being ``double'' (``unsigned long'' is not large enough  * to hold the required 24 hours worth of ticks if the frequency is  * 1000000ul, and ``unsigned long long'' would be nonstandard).  */
end_comment

begin_define
define|#
directive|define
name|_BSD_CLK_TCK_
value|128
end_define

begin_define
define|#
directive|define
name|_BSD_CLOCKS_PER_SEC_
value|128
end_define

begin_comment
comment|/*  * We define this here since both<stddef.h> and<sys/types.h> needs it.  */
end_comment

begin_define
define|#
directive|define
name|__offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|((size_t)(&((type *)0)->field))
end_define

begin_comment
comment|/*  * XXX this paragraph is very out of date.  * Typedefs for especially magic types.  #define's wouldn't work in the  * __GNUC__ case, since __attribute__(()) only works in certain contexts.  * This is not in<machine/types.h>, since that has too much namespace  * pollution for inclusion in ANSI headers, yet we need __int64_t in at  * least<stdio.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|__attribute__
argument_list|(
operator|(
name|__mode__
argument_list|(
name|__DI__
argument_list|)
operator|)
argument_list|)
name|__int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__attribute__
typedef|((
name|__mode__
typedef|(
name|__DI__
typedef|)))
name|__uint64_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

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
comment|/*  * Internal names for basic integral types.  Omit the typedef if  * not possible for a machine/compiler combination.  */
end_comment

begin_typedef
typedef|typedef
name|__signed
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

begin_typedef
typedef|typedef
name|int
name|__intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__signed
name|char
name|__int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|__uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|__int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|__uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uint_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|__int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|__uint_fast32_t
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
name|__uint64_t
name|__uint_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint64_t
name|__uintmax_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__INT8_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__INT16_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__INT32_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__INT64_C
parameter_list|(
name|c
parameter_list|)
value|(c ## LL)
end_define

begin_define
define|#
directive|define
name|__UINT8_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__UINT16_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|__UINT32_C
parameter_list|(
name|c
parameter_list|)
value|(c ## U)
end_define

begin_define
define|#
directive|define
name|__UINT64_C
parameter_list|(
name|c
parameter_list|)
value|(c ## ULL)
end_define

begin_define
define|#
directive|define
name|__INTMAX_C
parameter_list|(
name|c
parameter_list|)
value|(c ## LL)
end_define

begin_define
define|#
directive|define
name|__UINTMAX_C
parameter_list|(
name|c
parameter_list|)
value|(c ## ULL)
end_define

begin_comment
comment|/*  * mbstate_t is an opaque object to keep conversion state, during multibyte  * stream conversions.  The content must not be referenced by user programs.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|char
name|__mbstate8
index|[
literal|128
index|]
decl_stmt|;
name|__int64_t
name|_mbstateL
decl_stmt|;
comment|/* for alignment */
block|}
name|__mbstate_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ANSI_H_ */
end_comment

end_unit

