begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)stdlib.h	8.5 (Berkeley) 5/19/95  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_STDLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_STDLIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_null.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_RUNE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__rune_t
name|rune_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_RUNE_T_DECLARED
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
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|_WCHAR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__wchar_t
name|wchar_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_WCHAR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|quot
decl_stmt|;
comment|/* quotient */
name|int
name|rem
decl_stmt|;
comment|/* remainder */
block|}
name|div_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|quot
decl_stmt|;
name|long
name|rem
decl_stmt|;
block|}
name|ldiv_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|RAND_MAX
value|0x7fffffff
end_define

begin_decl_stmt
specifier|extern
name|int
name|__mb_cur_max
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MB_CUR_MAX
value|__mb_cur_max
end_define

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|abort
argument_list|(
name|void
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|abort2
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|void
operator|*
operator|*
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|abs
argument_list|(
name|int
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|atexit
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|atof
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|atoi
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|atol
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bsearch
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|calloc
parameter_list|(
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|div_t
name|div
argument_list|(
name|int
argument_list|,
name|int
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exit
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|free
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|long
name|labs
argument_list|(
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ldiv_t
name|ldiv
argument_list|(
name|long
argument_list|,
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
modifier|*
name|malloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mblen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbstowcs
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mbtowc
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsort
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rand
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srand
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|strtod
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|strtof
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|strtold
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|system
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wctomb
parameter_list|(
name|char
modifier|*
parameter_list|,
name|wchar_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcstombs
parameter_list|(
name|char
modifier|*
name|__restrict
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|__restrict
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions added in C99 which we make conditionally available in the  * BSD^C89 namespace if the compiler supports `long long'.  * The #if test is more complicated than it ought to be because  * __BSD_VISIBLE implies __ISO_C_VISIBLE == 1999 *even if* `long long'  * is not supported in the compilation environment (which therefore means  * that it can't really be ISO C99).  *  * (The only other extension made by C99 in thie header is _Exit().)  */
end_comment

begin_if
if|#
directive|if
name|__ISO_C_VISIBLE
operator|>=
literal|1999
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__LONG_LONG_SUPPORTED
end_ifdef

begin_comment
comment|/* LONGLONG */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|long
name|quot
decl_stmt|;
name|long
name|long
name|rem
decl_stmt|;
block|}
name|lldiv_t
typedef|;
end_typedef

begin_comment
comment|/* LONGLONG */
end_comment

begin_function_decl
name|long
name|long
name|atoll
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LONGLONG */
end_comment

begin_decl_stmt
name|long
name|long
name|llabs
argument_list|(
name|long
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LONGLONG */
end_comment

begin_decl_stmt
name|lldiv_t
name|lldiv
argument_list|(
name|long
name|long
argument_list|,
name|long
name|long
argument_list|)
name|__pure2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* LONGLONG */
end_comment

begin_function_decl
name|long
name|long
name|strtoll
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* LONGLONG */
end_comment

begin_function_decl
name|unsigned
name|long
name|long
name|strtoull
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
parameter_list|,
name|char
modifier|*
modifier|*
name|__restrict
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LONG_LONG_SUPPORTED */
end_comment

begin_decl_stmt
name|void
name|_Exit
argument_list|(
name|int
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ISO_C_VISIBLE>= 1999 */
end_comment

begin_comment
comment|/*  * Extensions made by POSIX relative to C.  We don't know yet which edition  * of POSIX made these extensions, so assume they've always been there until  * research can be done.  */
end_comment

begin_if
if|#
directive|if
name|__POSIX_VISIBLE
end_if

begin_comment
comment|/*>= ??? */
end_comment

begin_function_decl
name|int
name|posix_memalign
parameter_list|(
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* (ADV) */
end_comment

begin_function_decl
name|int
name|rand_r
parameter_list|(
name|unsigned
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* (TSF) */
end_comment

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|unsetenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The only changes to the XSI namespace in revision 6 were the deletion  * of the ttyslot() and valloc() functions, which FreeBSD never declared  * in this header.  For revision 7, ecvt(), fcvt(), and gcvt(), which  * FreeBSD also does not have, and mktemp(), are to be deleted.  */
end_comment

begin_if
if|#
directive|if
name|__XSI_VISIBLE
end_if

begin_comment
comment|/* XXX XSI requires pollution from<sys/wait.h> here.  We'd rather not. */
end_comment

begin_function_decl
name|long
name|a64l
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|drand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* char	*ecvt(double, int, int * __restrict, int * __restrict); */
end_comment

begin_function_decl
name|double
name|erand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* char	*fcvt(double, int, int * __restrict, int * __restrict); */
end_comment

begin_comment
comment|/* char	*gcvt(double, int, int * __restrict, int * __restrict); */
end_comment

begin_function_decl
name|int
name|getsubopt
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
specifier|const
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|grantpt
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|initstate
parameter_list|(
name|unsigned
name|long
comment|/* XSI requires u_int */
parameter_list|,
name|char
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|jrand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|l64a
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lcong48
parameter_list|(
name|unsigned
name|short
index|[
literal|7
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|lrand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_MKSTEMP_DECLARED
end_ifndef

begin_function_decl
name|int
name|mkstemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKSTEMP_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MKTEMP_DECLARED
end_ifndef

begin_function_decl
name|char
modifier|*
name|mktemp
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_MKTEMP_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|long
name|mrand48
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|nrand48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|posix_openpt
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ptsname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|putenv
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|realpath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
name|resolved_path
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|short
modifier|*
name|seed48
parameter_list|(
name|unsigned
name|short
index|[
literal|3
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|_SETKEY_DECLARED
end_ifndef

begin_function_decl
name|int
name|setkey
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_SETKEY_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|char
modifier|*
name|setstate
parameter_list|(
comment|/* const */
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srand48
parameter_list|(
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srandom
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unlockpt
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XSI_VISIBLE */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|_malloc_options
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|_malloc_message
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The alloca() function can't be implemented in C, and on some  * platforms it can't be implemented at all as a callable function.  * The GNU C compiler provides a built-in alloca() which we can use;  * in all other cases, provide a prototype, mainly to pacify various  * incarnations of lint.  On platforms where alloca() is not in libc,  * programs which use it will fail to link when compiled with non-GNU  * compilers.  */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
operator|||
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|alloca
end_undef

begin_comment
comment|/* some GNU bits try to get cute and define this on their own */
end_comment

begin_define
define|#
directive|define
name|alloca
parameter_list|(
name|sz
parameter_list|)
value|__builtin_alloca(sz)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|lint
argument_list|)
end_elif

begin_function_decl
name|void
modifier|*
name|alloca
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|__uint32_t
name|arc4random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc4random_addrandom
parameter_list|(
name|unsigned
name|char
modifier|*
name|dat
parameter_list|,
name|int
name|datlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arc4random_stir
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getbsize
parameter_list|(
name|int
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* getcap(3) functions */
end_comment

begin_function_decl
name|char
modifier|*
name|cgetcap
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetclose
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetent
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetfirst
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetmatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetnext
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetnum
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetset
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetstr
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cgetustr
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|daemon
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|devname
parameter_list|(
name|__dev_t
parameter_list|,
name|__mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|devname_r
parameter_list|(
name|__dev_t
parameter_list|,
name|__mode_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getloadavg
parameter_list|(
name|double
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__const
name|char
modifier|*
name|getprogname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|heapsort
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|l64a_r
parameter_list|(
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mergesort
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|qsort_r
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radixsort
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|reallocf
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rpmatch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setprogname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sradixsort
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sranddev
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|srandomdev
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|long
name|strtonum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|long
name|long
parameter_list|,
name|long
name|long
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deprecated interfaces, to be removed in FreeBSD 6.0. */
end_comment

begin_function_decl
name|__int64_t
name|strtoq
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__uint64_t
name|strtouq
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|suboptarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* getsubopt(3) external variable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BSD_VISIBLE */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_STDLIB_H_ */
end_comment

end_unit

