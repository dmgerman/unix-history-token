begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95  * $FreeBSD$  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

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
comment|/* !__GNUC__ */
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

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

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
comment|/* !__GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !(__STDC__ || __cplusplus) */
end_comment

begin_comment
comment|/*  * Compiler-dependent macros to help declare dead (non-returning) and  * pure (no side effects) functions, and unused variables.  They are  * null except for versions of gcc that are known to support the features  * properly (old versions of gcc-2 supported the dead and pure features  * in a different (wrong) way).  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
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
literal|7
operator|||
name|__GNUC__
operator|==
literal|3
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Compiler-dependent macros to declare that functions take printf-like  * or scanf-like arguments.  They are null except for versions of gcc  * that are known to support the features properly (old versions of gcc-2  * didn't permit keeping the keywords out of the application namespace).  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|7
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

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

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
value|extern __typeof (sym) aliassym __attribute__ ((__alias__ (#sym)));
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__ELF__ */
end_comment

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
value|__asm__(".stabs \"_" #alias "\",11,0,0,0");	\ 	__asm__(".stabs \"_" #sym "\",1,0,0,0")
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
value|__asm__(".stabs \"" msg "\",30,0,0,0");		\ 	__asm__(".stabs \"_" #sym "\",1,0,0,0")
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
value|__asm__(".stabs \"_/**/alias\",11,0,0,0");	\ 	__asm__(".stabs \"_/**/sym\",1,0,0,0")
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
value|__asm__(".stabs msg,30,0,0,0");			\ 	__asm__(".stabs \"_/**/sym\",1,0,0,0")
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
comment|/* __ELF__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ELF__
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

begin_ifndef
ifndef|#
directive|ifndef
name|__RCSID
end_ifndef

begin_define
define|#
directive|define
name|__RCSID
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(rcsid,s)
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
name|__RCSID_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|__RCSID_SOURCE
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(rcsid_source,s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__COPYRIGHT
end_ifndef

begin_define
define|#
directive|define
name|__COPYRIGHT
parameter_list|(
name|s
parameter_list|)
value|__IDSTRING(copyright,s)
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
comment|/* !_SYS_CDEFS_H_ */
end_comment

end_unit

