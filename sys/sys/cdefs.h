begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CDEFS_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__BEGIN_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|__END_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__BEGIN_DECLS
end_define

begin_define
define|#
directive|define
name|__END_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * This code has been put in place to help reduce the addition of  * compiler specific defines in FreeBSD code.  It helps to aid in  * having a compiler-agnostic source tree.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|3
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__GNUCLIKE_ASM
value|3
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE_MATH_BUILTIN_CONSTANTS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__GNUCLIKE_ASM
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__GNUCLIKE___TYPEOF
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE___OFFSETOF
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE___SECTION
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE_ATTRIBUTE_MODE_DI
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__INTEL_COMPILER
end_ifndef

begin_define
define|#
directive|define
name|__GNUCLIKE_CTOR_SECTION_HANDLING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_CONSTANT_P
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
name|defined
argument_list|(
name|__cplusplus
argument_list|)
expr|\
operator|&&
name|__INTEL_COMPILER
operator|<
literal|800
end_if

begin_undef
undef|#
directive|undef
name|__GNUCLIKE_BUILTIN_CONSTANT_P
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__GNUC_MINOR__
operator|>
literal|95
operator|||
name|__GNUC__
operator|>=
literal|3
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_VARARGS
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_STDARG
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_VAALIST
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__GNUC_VA_LIST_COMPATIBILITY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__INTEL_COMPILER
end_ifndef

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_NEXT_ARG
value|1
end_define

begin_define
define|#
directive|define
name|__GNUCLIKE_MATH_BUILTIN_RELOPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__GNUCLIKE_BUILTIN_MEMCPY
value|1
end_define

begin_comment
comment|/* XXX: if __GNUC__>= 2: not tested everywhere originally, where replaced */
end_comment

begin_define
define|#
directive|define
name|__CC_SUPPORTS_INLINE
value|1
end_define

begin_define
define|#
directive|define
name|__CC_SUPPORTS___INLINE
value|1
end_define

begin_define
define|#
directive|define
name|__CC_SUPPORTS___INLINE__
value|1
end_define

begin_define
define|#
directive|define
name|__CC_SUPPORTS___FUNC__
value|1
end_define

begin_define
define|#
directive|define
name|__CC_SUPPORTS_WARNING
value|1
end_define

begin_define
define|#
directive|define
name|__CC_SUPPORTS_VARADIC_XXX
value|1
end_define

begin_comment
comment|/* see varargs.h */
end_comment

begin_define
define|#
directive|define
name|__CC_SUPPORTS_DYNAMIC_ARRAY_INIT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ || __INTEL_COMPILER */
end_comment

begin_comment
comment|/*  * Macro to test if we're using a specific version of gcc or later.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__GNUC_PREREQ__
parameter_list|(
name|ma
parameter_list|,
name|mi
parameter_list|)
define|\
value|(__GNUC__> (ma) || __GNUC__ == (ma)&& __GNUC_MINOR__>= (mi))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__GNUC_PREREQ__
parameter_list|(
name|ma
parameter_list|,
name|mi
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The __CONCAT macro is used to concatenate parts of symbol names, e.g.  * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.  * The __CONCAT macro is a bit tricky to use if it must work in non-ANSI  * mode -- there must be no spaces between its arguments, and for nested  * __CONCAT's, all the __CONCAT's must be at the left.  __CONCAT can also  * concatenate double-quoted strings produced by the __STRING macro, but  * this only works with ANSI C.  *  * __XSTRING is like __STRING, but it expands any macros in its argument  * first.  It is only available with ANSI C.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|protos
end_define

begin_comment
comment|/* full-blown ANSI C */
end_comment

begin_define
define|#
directive|define
name|__CONCAT1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x ## y
end_define

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__CONCAT1(x,y)
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

begin_comment
comment|/* stringify without expanding x */
end_comment

begin_define
define|#
directive|define
name|__XSTRING
parameter_list|(
name|x
parameter_list|)
value|__STRING(x)
end_define

begin_comment
comment|/* expand x, then stringify */
end_comment

begin_define
define|#
directive|define
name|__const
value|const
end_define

begin_comment
comment|/* define reserved names to standard */
end_comment

begin_define
define|#
directive|define
name|__signed
value|signed
end_define

begin_define
define|#
directive|define
name|__volatile
value|volatile
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_define
define|#
directive|define
name|__inline
value|inline
end_define

begin_comment
comment|/* convert to C++ keyword */
end_comment

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|__CC_SUPPORTS___INLINE
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|__inline
end_define

begin_comment
comment|/* delete GCC keyword */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! __CC_SUPPORTS___INLINE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__cplusplus */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !(__STDC__ || __cplusplus) */
end_comment

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|protos
parameter_list|)
value|()
end_define

begin_comment
comment|/* traditional C preprocessor */
end_comment

begin_define
define|#
directive|define
name|__CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|x
comment|/**/
value|y
end_define

begin_define
define|#
directive|define
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|"x"
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__CC_SUPPORTS___INLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|__const
end_define

begin_comment
comment|/* delete pseudo-ANSI C keywords */
end_comment

begin_define
define|#
directive|define
name|__inline
end_define

begin_define
define|#
directive|define
name|__signed
end_define

begin_define
define|#
directive|define
name|__volatile
end_define

begin_comment
comment|/*  * In non-ANSI C environments, new programs will want ANSI-only C keywords  * deleted from the program and old programs will want them left alone.  * When using a compiler other than gcc, programs using the ANSI C keywords  * const, inline etc. as normal identifiers should define -DNO_ANSI_KEYWORDS.  * When using "gcc -traditional", we assume that this is the intent; if  * __GNUC__ is defined but __STDC__ is not, we leave the new keywords alone.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_ANSI_KEYWORDS
end_ifndef

begin_define
define|#
directive|define
name|const
end_define

begin_comment
comment|/* delete ANSI C keywords */
end_comment

begin_define
define|#
directive|define
name|inline
end_define

begin_define
define|#
directive|define
name|signed
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NO_ANSI_KEYWORDS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__CC_SUPPORTS___INLINE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(__STDC__ || __cplusplus) */
end_comment

begin_comment
comment|/*  * Compiler-dependent macros to help declare dead (non-returning) and  * pure (no side effects) functions, and unused variables.  They are  * null except for versions of gcc that are known to support the features  * properly (old versions of gcc-2 supported the dead and pure features  * in a different (wrong) way).  If we do not provide an implementation  * for a given compiler, let the compile fail if it is told to use  * a feature that we cannot live without.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_define
define|#
directive|define
name|__dead2
end_define

begin_define
define|#
directive|define
name|__pure2
end_define

begin_define
define|#
directive|define
name|__unused
end_define

begin_define
define|#
directive|define
name|__packed
end_define

begin_define
define|#
directive|define
name|__aligned
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__section
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
operator|!
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead2
end_define

begin_define
define|#
directive|define
name|__pure2
end_define

begin_define
define|#
directive|define
name|__unused
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|>=
literal|5
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead2
value|__attribute__((__noreturn__))
end_define

begin_define
define|#
directive|define
name|__pure2
value|__attribute__((__const__))
end_define

begin_define
define|#
directive|define
name|__unused
end_define

begin_comment
comment|/* XXX Find out what to do for __packed, __aligned and __section */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead2
value|__attribute__((__noreturn__))
end_define

begin_define
define|#
directive|define
name|__pure2
value|__attribute__((__const__))
end_define

begin_define
define|#
directive|define
name|__unused
value|__attribute__((__unused__))
end_define

begin_define
define|#
directive|define
name|__used
value|__attribute__((__used__))
end_define

begin_define
define|#
directive|define
name|__packed
value|__attribute__((__packed__))
end_define

begin_define
define|#
directive|define
name|__aligned
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__aligned__(x)))
end_define

begin_define
define|#
directive|define
name|__section
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__section__(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead2
value|__attribute__((__noreturn__))
end_define

begin_define
define|#
directive|define
name|__pure2
value|__attribute__((__const__))
end_define

begin_define
define|#
directive|define
name|__unused
value|__attribute__((__unused__))
end_define

begin_define
define|#
directive|define
name|__used
value|__attribute__((__used__))
end_define

begin_define
define|#
directive|define
name|__packed
value|__attribute__((__packed__))
end_define

begin_define
define|#
directive|define
name|__aligned
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__aligned__(x)))
end_define

begin_define
define|#
directive|define
name|__section
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__section__(x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|96
argument_list|)
end_if

begin_define
define|#
directive|define
name|__malloc_like
value|__attribute__((__malloc__))
end_define

begin_define
define|#
directive|define
name|__pure
value|__attribute__((__pure__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__malloc_like
end_define

begin_define
define|#
directive|define
name|__pure
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|3
operator|,
literal|1
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|&&
name|__INTEL_COMPILER
operator|>=
literal|800
operator|)
end_if

begin_define
define|#
directive|define
name|__always_inline
value|__attribute__((__always_inline__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__always_inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|3
operator|,
literal|1
argument_list|)
end_if

begin_define
define|#
directive|define
name|__noinline
value|__attribute__ ((__noinline__))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__noinline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|3
operator|,
literal|3
argument_list|)
end_if

begin_define
define|#
directive|define
name|__nonnull
parameter_list|(
name|x
parameter_list|)
value|__attribute__((__nonnull__(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__nonnull
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XXX: should use `#if __STDC_VERSION__< 199901'. */
end_comment

begin_if
if|#
directive|if
operator|!
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__func__
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
operator|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|||
name|__STDC_VERSION__
operator|>=
literal|199901
end_if

begin_define
define|#
directive|define
name|__LONG_LONG_SUPPORTED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GCC 2.95 provides `__restrict' as an extension to C90 to support the  * C99-specific `restrict' type qualifier.  We happen to use `__restrict' as  * a way to define the `restrict' type qualifier without disturbing older  * software that is unaware of C99 keywords.  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|==
literal|95
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC_VERSION__
argument_list|)
operator|||
name|__STDC_VERSION__
operator|<
literal|199901
operator|||
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_define
define|#
directive|define
name|__restrict
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__restrict
value|restrict
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
comment|/*  * GNU C version 2.96 adds explicit branch prediction so that  * the CPU back-end can hint the processor and also so that  * code blocks can be reordered such that the predicted path  * sees a more linear flow, thus improving cache behavior, etc.  *  * The following two macros provide us with a way to utilize this  * compiler feature.  Use __predict_true() if you expect the expression  * to evaluate to true, and __predict_false() if you expect the  * expression to evaluate to false.  *  * A few notes about usage:  *  *	* Generally, __predict_false() error condition checks (unless  *	  you have some _strong_ reason to do otherwise, in which case  *	  document it), and/or __predict_true() `no-error' condition  *	  checks, assuming you want to optimize for the no-error case.  *  *	* Other than that, if you don't know the likelihood of a test  *	  succeeding from empirical or other `hard' evidence, don't  *	  make predictions.  *  *	* These are meant to be used in places that are run `a lot'.  *	  It is wasteful to make predictions in code that is run  *	  seldomly (e.g. at subsystem initialization time) as the  *	  basic block reordering that this affects can often generate  *	  larger code.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|96
argument_list|)
end_if

begin_define
define|#
directive|define
name|__predict_true
parameter_list|(
name|exp
parameter_list|)
value|__builtin_expect((exp), 1)
end_define

begin_define
define|#
directive|define
name|__predict_false
parameter_list|(
name|exp
parameter_list|)
value|__builtin_expect((exp), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__predict_true
parameter_list|(
name|exp
parameter_list|)
value|(exp)
end_define

begin_define
define|#
directive|define
name|__predict_false
parameter_list|(
name|exp
parameter_list|)
value|(exp)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We define this here since<stddef.h>,<sys/queue.h>, and<sys/types.h>  * require it.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC_PREREQ__
argument_list|(
literal|4
operator|,
literal|1
argument_list|)
end_if

begin_define
define|#
directive|define
name|__offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
value|__builtin_offsetof(type, field)
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__offsetof
parameter_list|(
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|(__offsetof__ (reinterpret_cast<size_t>			\                  (&reinterpret_cast<const volatile char&>	\                   (static_cast<type *> (0)->field))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__rangeof
parameter_list|(
name|type
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|(__offsetof(type, end) - __offsetof(type, start))
end_define

begin_comment
comment|/*  * Compiler-dependent macros to declare that functions take printf-like  * or scanf-like arguments.  They are null except for versions of gcc  * that are known to support the features properly (old versions of gcc-2  * didn't permit keeping the keywords out of the application namespace).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|__GNUC_PREREQ__
argument_list|(
literal|2
operator|,
literal|7
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__scanflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|__format_arg
parameter_list|(
name|fmtarg
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
define|\
value|__attribute__((__format__ (__printf__, fmtarg, firstvararg)))
end_define

begin_define
define|#
directive|define
name|__scanflike
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
define|\
value|__attribute__((__format__ (__scanf__, fmtarg, firstvararg)))
end_define

begin_define
define|#
directive|define
name|__format_arg
parameter_list|(
name|fmtarg
parameter_list|)
value|__attribute__((__format_arg__ (fmtarg)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compiler-dependent macros that rely on FreeBSD-specific extensions. */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_cc_version
operator|>=
literal|300001
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__printf0like
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
define|\
value|__attribute__((__format__ (__printf0__, fmtarg, firstvararg)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__printf0like
parameter_list|(
name|fmtarg
parameter_list|,
name|firstvararg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__INTEL_COMPILER
end_ifndef

begin_define
define|#
directive|define
name|__strong_reference
parameter_list|(
name|sym
parameter_list|,
name|aliassym
parameter_list|)
define|\
value|extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|__weak_reference
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
define|\
value|__asm__(".weak " #alias);	\ 	__asm__(".equ "  #alias ", " #sym)
end_define

begin_define
define|#
directive|define
name|__warn_references
parameter_list|(
name|sym
parameter_list|,
name|msg
parameter_list|)
define|\
value|__asm__(".section .gnu.warning." #sym);	\ 	__asm__(".asciz \"" msg "\"");	\ 	__asm__(".previous")
end_define

begin_define
define|#
directive|define
name|__sym_compat
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|verid
parameter_list|)
define|\
value|__asm__(".symver " #impl ", " #sym "@" #verid)
end_define

begin_define
define|#
directive|define
name|__sym_default
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|verid
parameter_list|)
define|\
value|__asm__(".symver " #impl ", " #sym "@@" #verid)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__weak_reference
parameter_list|(
name|sym
parameter_list|,
name|alias
parameter_list|)
define|\
value|__asm__(".weak alias");		\ 	__asm__(".equ alias, sym")
end_define

begin_define
define|#
directive|define
name|__warn_references
parameter_list|(
name|sym
parameter_list|,
name|msg
parameter_list|)
define|\
value|__asm__(".section .gnu.warning.sym"); \ 	__asm__(".asciz \"msg\"");	\ 	__asm__(".previous")
end_define

begin_define
define|#
directive|define
name|__sym_compat
parameter_list|(
name|sym
parameter_list|,
name|impl
parameter_list|,
name|verid
parameter_list|)
define|\
value|__asm__(".symver impl, sym@verid")
end_define

begin_define
define|#
directive|define
name|__sym_default
parameter_list|(
name|impl
parameter_list|,
name|sym
parameter_list|,
name|verid
parameter_list|)
define|\
value|__asm__(".symver impl, sym@@verid")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ || __INTEL_COMPILER */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_define
define|#
directive|define
name|__IDSTRING
parameter_list|(
name|name
parameter_list|,
name|string
parameter_list|)
value|__asm__(".ident\t\"" string "\"")
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * The following definition might not work well if used in header files,  * but it should be better than nothing.  If you want a "do nothing"  * version, then it should generate some harmless declaration, such as:  *    #define __IDSTRING(name,string)	struct __hack  */
end_comment

begin_define
define|#
directive|define
name|__IDSTRING
parameter_list|(
name|name
parameter_list|,
name|string
parameter_list|)
value|static const char name[] __unused = string
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Embed the rcs id of a source file in the resulting library.  Note that in  * more recent ELF binutils, we use .ident allowing the ID to be stripped.  * Usage:  *	__FBSDID("$FreeBSD$");  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FBSDID
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STRIP_FBSDID
argument_list|)
end_if

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(__CONCAT(__rcsid_,__LINE__),s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__FBSDID
parameter_list|(
name|s
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RCSID
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO__RCSID
end_ifndef

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(__CONCAT(__rcsid_,__LINE__),s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|s
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RCSID_SOURCE
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO__RCSID_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|__RCSID_SOURCE
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(__CONCAT(__rcsid_source_,__LINE__),s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__RCSID_SOURCE
parameter_list|(
name|s
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__SCCSID
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO__SCCSID
end_ifndef

begin_define
define|#
directive|define
name|__SCCSID
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(__CONCAT(__sccsid_,__LINE__),s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__SCCSID
parameter_list|(
name|s
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__COPYRIGHT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO__COPYRIGHT
end_ifndef

begin_define
define|#
directive|define
name|__COPYRIGHT
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(__CONCAT(__copyright_,__LINE__),s)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__COPYRIGHT
parameter_list|(
name|s
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__DECONST
end_ifndef

begin_define
define|#
directive|define
name|__DECONST
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintptr_t)(const void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVOLATILE
end_ifndef

begin_define
define|#
directive|define
name|__DEVOLATILE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintptr_t)(volatile void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__DEQUALIFY
end_ifndef

begin_define
define|#
directive|define
name|__DEQUALIFY
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|)
value|((type)(uintptr_t)(const volatile void *)(var))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*-  * The following definitions are an extension of the behavior originally  * implemented in<sys/_posix.h>, but with a different level of granularity.  * POSIX.1 requires that the macros we test be defined before any standard  * header file is included.  *  * Here's a quick run-down of the versions:  *  defined(_POSIX_SOURCE)		1003.1-1988  *  _POSIX_C_SOURCE == 1		1003.1-1990  *  _POSIX_C_SOURCE == 2		1003.2-1992 C Language Binding Option  *  _POSIX_C_SOURCE == 199309		1003.1b-1993  *  _POSIX_C_SOURCE == 199506		1003.1c-1995, 1003.1i-1995,  *					and the omnibus ISO/IEC 9945-1: 1996  *  _POSIX_C_SOURCE == 200112		1003.1-2001  *  _POSIX_C_SOURCE == 200809		1003.1-2008  *  * In addition, the X/Open Portability Guide, which is now the Single UNIX  * Specification, defines a feature-test macro which indicates the version of  * that specification, and which subsumes _POSIX_C_SOURCE.  *  * Our macros begin with two underscores to avoid namespace screwage.  */
end_comment

begin_comment
comment|/* Deal with IEEE Std. 1003.1-1990, in which _POSIX_C_SOURCE == 1. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
name|_POSIX_C_SOURCE
operator|==
literal|1
end_if

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_comment
comment|/* Probably illegal, but beyond caring now. */
end_comment

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|199009
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Deal with IEEE Std. 1003.2-1992, in which _POSIX_C_SOURCE == 2. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
operator|&&
name|_POSIX_C_SOURCE
operator|==
literal|2
end_if

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|199209
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Deal with various X/Open Portability Guides and Single UNIX Spec. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_XOPEN_SOURCE
end_ifdef

begin_if
if|#
directive|if
name|_XOPEN_SOURCE
operator|-
literal|0
operator|>=
literal|700
end_if

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|700
end_define

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|200809
end_define

begin_elif
elif|#
directive|elif
name|_XOPEN_SOURCE
operator|-
literal|0
operator|>=
literal|600
end_elif

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|600
end_define

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|200112
end_define

begin_elif
elif|#
directive|elif
name|_XOPEN_SOURCE
operator|-
literal|0
operator|>=
literal|500
end_elif

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|500
end_define

begin_undef
undef|#
directive|undef
name|_POSIX_C_SOURCE
end_undef

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|199506
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
comment|/*  * Deal with all versions of POSIX.  The ordering relative to the tests above is  * important.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_C_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|_POSIX_C_SOURCE
value|198808
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_C_SOURCE
end_ifdef

begin_if
if|#
directive|if
name|_POSIX_C_SOURCE
operator|>=
literal|200809
end_if

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|200809
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1999
end_define

begin_elif
elif|#
directive|elif
name|_POSIX_C_SOURCE
operator|>=
literal|200112
end_elif

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|200112
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1999
end_define

begin_elif
elif|#
directive|elif
name|_POSIX_C_SOURCE
operator|>=
literal|199506
end_elif

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|199506
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1990
end_define

begin_elif
elif|#
directive|elif
name|_POSIX_C_SOURCE
operator|>=
literal|199309
end_elif

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|199309
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1990
end_define

begin_elif
elif|#
directive|elif
name|_POSIX_C_SOURCE
operator|>=
literal|199209
end_elif

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|199209
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1990
end_define

begin_elif
elif|#
directive|elif
name|_POSIX_C_SOURCE
operator|>=
literal|199009
end_elif

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|199009
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1990
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|198808
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POSIX_C_SOURCE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*-  * Deal with _ANSI_SOURCE:  * If it is defined, and no other compilation environment is explicitly  * requested, then define our internal feature-test macros to zero.  This  * makes no difference to the preprocessor (undefined symbols in preprocessing  * expressions are defined to have value zero), but makes it more convenient for  * a test program to print out the values.  *  * If a program mistakenly defines _ANSI_SOURCE and some other macro such as  * _POSIX_C_SOURCE, we will assume that it wants the broader compilation  * environment (and in fact we will never get here).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
end_if

begin_comment
comment|/* Hide almost everything. */
end_comment

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__BSD_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1990
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_C99_SOURCE
argument_list|)
end_elif

begin_comment
comment|/* Localism to specify strict C99 env. */
end_comment

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__BSD_VISIBLE
value|0
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1999
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Default environment: show everything. */
end_comment

begin_define
define|#
directive|define
name|__POSIX_VISIBLE
value|200809
end_define

begin_define
define|#
directive|define
name|__XSI_VISIBLE
value|700
end_define

begin_define
define|#
directive|define
name|__BSD_VISIBLE
value|1
end_define

begin_define
define|#
directive|define
name|__ISO_C_VISIBLE
value|1999
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CDEFS_H_ */
end_comment

end_unit

