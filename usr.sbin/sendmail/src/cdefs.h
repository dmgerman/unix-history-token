begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Berkeley Software Design, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)cdefs.h	8.8 (Berkeley) 1/9/95  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CDEFS_H_
end_ifndef

begin_define
define|#
directive|define
name|_CDEFS_H_
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
value|};
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
comment|/*  * The __CONCAT macro is used to concatenate parts of symbol names, e.g.  * with "#define OLD(foo) __CONCAT(old,foo)", OLD(foo) produces oldfoo.  * The __CONCAT macro is a bit tricky -- make sure you don't put spaces  * in between its arguments.  __CONCAT can also concatenate double-quoted  * strings produced by the __STRING macro, but this only works with ANSI C.  */
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
name|__CONCAT
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
name|__STRING
parameter_list|(
name|x
parameter_list|)
value|#x
end_define

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
comment|/*  * GCC1 and some versions of GCC2 declare dead (non-returning) and  * pure (no side effects) functions using "volatile" and "const";  * unfortunately, these then cause warnings under "-ansi -pedantic".  * GCC2 uses a new, peculiar __attribute__((attrs)) style.  All of  * these work for GNU C++ (modulo a slight glitch in the C++ grammar  * in the distribution version of 2.5.5).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|__GNUC__
operator|<
literal|2
operator|||
expr|\
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* delete __attribute__ if non-gcc or gcc1 */
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
name|__STRICT_ANSI__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__dead
value|__volatile
end_define

begin_define
define|#
directive|define
name|__pure
value|__const
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
comment|/* Delete pseudo-keywords wherever they are not available or needed. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__dead
end_ifndef

begin_define
define|#
directive|define
name|__dead
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CDEFS_H_ */
end_comment

end_unit

