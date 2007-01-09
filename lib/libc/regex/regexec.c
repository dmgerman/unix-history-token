begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993, 1994 Henry Spencer.  * Copyright (c) 1992, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)regexec.c	8.3 (Berkeley) 3/20/94  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)regexec.c	8.3 (Berkeley) 3/20/94"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * the outer shell of regexec()  *  * This file includes engine.c three times, after muchos fiddling with the  * macros that code uses.  This lets the same code operate on two different  * representations for state sets and characters.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_include
include|#
directive|include
file|"utils.h"
end_include

begin_include
include|#
directive|include
file|"regex2.h"
end_include

begin_decl_stmt
specifier|static
name|int
name|nope
name|__unused
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for use in asserts; shuts lint up */
end_comment

begin_function
specifier|static
name|__inline
name|size_t
name|xmbrtowc
parameter_list|(
name|wi
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|mbs
parameter_list|,
name|dummy
parameter_list|)
name|wint_t
modifier|*
name|wi
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|size_t
name|n
decl_stmt|;
name|mbstate_t
modifier|*
name|mbs
decl_stmt|;
name|wint_t
name|dummy
decl_stmt|;
block|{
name|size_t
name|nr
decl_stmt|;
name|wchar_t
name|wc
decl_stmt|;
name|nr
operator|=
name|mbrtowc
argument_list|(
operator|&
name|wc
argument_list|,
name|s
argument_list|,
name|n
argument_list|,
name|mbs
argument_list|)
expr_stmt|;
if|if
condition|(
name|wi
operator|!=
name|NULL
condition|)
operator|*
name|wi
operator|=
name|wc
expr_stmt|;
if|if
condition|(
name|nr
operator|==
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
elseif|else
if|if
condition|(
name|nr
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|1
operator|||
name|nr
operator|==
operator|(
name|size_t
operator|)
operator|-
literal|2
condition|)
block|{
name|memset
argument_list|(
name|mbs
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|mbs
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|wi
operator|!=
name|NULL
condition|)
operator|*
name|wi
operator|=
name|dummy
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
return|return
operator|(
name|nr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|size_t
name|xmbrtowc_dummy
parameter_list|(
name|wi
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|mbs
parameter_list|,
name|dummy
parameter_list|)
name|wint_t
modifier|*
name|wi
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
name|size_t
name|n
name|__unused
decl_stmt|;
name|mbstate_t
modifier|*
name|mbs
name|__unused
decl_stmt|;
name|wint_t
name|dummy
name|__unused
decl_stmt|;
block|{
if|if
condition|(
name|wi
operator|!=
name|NULL
condition|)
operator|*
name|wi
operator|=
operator|(
name|unsigned
name|char
operator|)
operator|*
name|s
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* macros for manipulating states, small version */
end_comment

begin_define
define|#
directive|define
name|states
value|long
end_define

begin_define
define|#
directive|define
name|states1
value|states
end_define

begin_comment
comment|/* for later use in regexec() decision */
end_comment

begin_define
define|#
directive|define
name|CLEAR
parameter_list|(
name|v
parameter_list|)
value|((v) = 0)
end_define

begin_define
define|#
directive|define
name|SET0
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)&= ~((unsigned long)1<< (n)))
end_define

begin_define
define|#
directive|define
name|SET1
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v) |= (unsigned long)1<< (n))
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(((v)& ((unsigned long)1<< (n))) != 0)
end_define

begin_define
define|#
directive|define
name|ASSIGN
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|((d) = (s))
end_define

begin_define
define|#
directive|define
name|EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a) == (b))
end_define

begin_define
define|#
directive|define
name|STATEVARS
value|long dummy
end_define

begin_comment
comment|/* dummy version */
end_comment

begin_define
define|#
directive|define
name|STATESETUP
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|STATETEARDOWN
parameter_list|(
name|m
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|SETUP
parameter_list|(
name|v
parameter_list|)
value|((v) = 0)
end_define

begin_define
define|#
directive|define
name|onestate
value|long
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|o
parameter_list|,
name|n
parameter_list|)
value|((o) = (unsigned long)1<< (n))
end_define

begin_define
define|#
directive|define
name|INC
parameter_list|(
name|o
parameter_list|)
value|((o)<<= 1)
end_define

begin_define
define|#
directive|define
name|ISSTATEIN
parameter_list|(
name|v
parameter_list|,
name|o
parameter_list|)
value|(((v)& (o)) != 0)
end_define

begin_comment
comment|/* some abbreviations; note that some of these know variable names! */
end_comment

begin_comment
comment|/* do "if I'm here, I can also be there" etc without branches */
end_comment

begin_define
define|#
directive|define
name|FWD
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|((dst) |= ((unsigned long)(src)&(here))<< (n))
end_define

begin_define
define|#
directive|define
name|BACK
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|((dst) |= ((unsigned long)(src)&(here))>> (n))
end_define

begin_define
define|#
directive|define
name|ISSETBACK
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|(((v)& ((unsigned long)here>> (n))) != 0)
end_define

begin_comment
comment|/* no multibyte support */
end_comment

begin_define
define|#
directive|define
name|XMBRTOWC
value|xmbrtowc_dummy
end_define

begin_define
define|#
directive|define
name|ZAPSTATE
parameter_list|(
name|mbs
parameter_list|)
value|((void)(mbs))
end_define

begin_comment
comment|/* function names */
end_comment

begin_define
define|#
directive|define
name|SNAMES
end_define

begin_comment
comment|/* engine.c looks after details */
end_comment

begin_include
include|#
directive|include
file|"engine.c"
end_include

begin_comment
comment|/* now undo things */
end_comment

begin_undef
undef|#
directive|undef
name|states
end_undef

begin_undef
undef|#
directive|undef
name|CLEAR
end_undef

begin_undef
undef|#
directive|undef
name|SET0
end_undef

begin_undef
undef|#
directive|undef
name|SET1
end_undef

begin_undef
undef|#
directive|undef
name|ISSET
end_undef

begin_undef
undef|#
directive|undef
name|ASSIGN
end_undef

begin_undef
undef|#
directive|undef
name|EQ
end_undef

begin_undef
undef|#
directive|undef
name|STATEVARS
end_undef

begin_undef
undef|#
directive|undef
name|STATESETUP
end_undef

begin_undef
undef|#
directive|undef
name|STATETEARDOWN
end_undef

begin_undef
undef|#
directive|undef
name|SETUP
end_undef

begin_undef
undef|#
directive|undef
name|onestate
end_undef

begin_undef
undef|#
directive|undef
name|INIT
end_undef

begin_undef
undef|#
directive|undef
name|INC
end_undef

begin_undef
undef|#
directive|undef
name|ISSTATEIN
end_undef

begin_undef
undef|#
directive|undef
name|FWD
end_undef

begin_undef
undef|#
directive|undef
name|BACK
end_undef

begin_undef
undef|#
directive|undef
name|ISSETBACK
end_undef

begin_undef
undef|#
directive|undef
name|SNAMES
end_undef

begin_undef
undef|#
directive|undef
name|XMBRTOWC
end_undef

begin_undef
undef|#
directive|undef
name|ZAPSTATE
end_undef

begin_comment
comment|/* macros for manipulating states, large version */
end_comment

begin_define
define|#
directive|define
name|states
value|char *
end_define

begin_define
define|#
directive|define
name|CLEAR
parameter_list|(
name|v
parameter_list|)
value|memset(v, 0, m->g->nstates)
end_define

begin_define
define|#
directive|define
name|SET0
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)[n] = 0)
end_define

begin_define
define|#
directive|define
name|SET1
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)[n] = 1)
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)[n])
end_define

begin_define
define|#
directive|define
name|ASSIGN
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|)
value|memcpy(d, s, m->g->nstates)
end_define

begin_define
define|#
directive|define
name|EQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(memcmp(a, b, m->g->nstates) == 0)
end_define

begin_define
define|#
directive|define
name|STATEVARS
value|long vn; char *space
end_define

begin_define
define|#
directive|define
name|STATESETUP
parameter_list|(
name|m
parameter_list|,
name|nv
parameter_list|)
value|{ (m)->space = malloc((nv)*(m)->g->nstates); \ 				if ((m)->space == NULL) return(REG_ESPACE); \ 				(m)->vn = 0; }
end_define

begin_define
define|#
directive|define
name|STATETEARDOWN
parameter_list|(
name|m
parameter_list|)
value|{ free((m)->space); }
end_define

begin_define
define|#
directive|define
name|SETUP
parameter_list|(
name|v
parameter_list|)
value|((v) =&m->space[m->vn++ * m->g->nstates])
end_define

begin_define
define|#
directive|define
name|onestate
value|long
end_define

begin_define
define|#
directive|define
name|INIT
parameter_list|(
name|o
parameter_list|,
name|n
parameter_list|)
value|((o) = (n))
end_define

begin_define
define|#
directive|define
name|INC
parameter_list|(
name|o
parameter_list|)
value|((o)++)
end_define

begin_define
define|#
directive|define
name|ISSTATEIN
parameter_list|(
name|v
parameter_list|,
name|o
parameter_list|)
value|((v)[o])
end_define

begin_comment
comment|/* some abbreviations; note that some of these know variable names! */
end_comment

begin_comment
comment|/* do "if I'm here, I can also be there" etc without branches */
end_comment

begin_define
define|#
directive|define
name|FWD
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|((dst)[here+(n)] |= (src)[here])
end_define

begin_define
define|#
directive|define
name|BACK
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|n
parameter_list|)
value|((dst)[here-(n)] |= (src)[here])
end_define

begin_define
define|#
directive|define
name|ISSETBACK
parameter_list|(
name|v
parameter_list|,
name|n
parameter_list|)
value|((v)[here - (n)])
end_define

begin_comment
comment|/* no multibyte support */
end_comment

begin_define
define|#
directive|define
name|XMBRTOWC
value|xmbrtowc_dummy
end_define

begin_define
define|#
directive|define
name|ZAPSTATE
parameter_list|(
name|mbs
parameter_list|)
value|((void)(mbs))
end_define

begin_comment
comment|/* function names */
end_comment

begin_define
define|#
directive|define
name|LNAMES
end_define

begin_comment
comment|/* flag */
end_comment

begin_include
include|#
directive|include
file|"engine.c"
end_include

begin_comment
comment|/* multibyte character& large states version */
end_comment

begin_undef
undef|#
directive|undef
name|LNAMES
end_undef

begin_undef
undef|#
directive|undef
name|XMBRTOWC
end_undef

begin_undef
undef|#
directive|undef
name|ZAPSTATE
end_undef

begin_define
define|#
directive|define
name|XMBRTOWC
value|xmbrtowc
end_define

begin_define
define|#
directive|define
name|ZAPSTATE
parameter_list|(
name|mbs
parameter_list|)
value|memset((mbs), 0, sizeof(*(mbs)))
end_define

begin_define
define|#
directive|define
name|MNAMES
end_define

begin_include
include|#
directive|include
file|"engine.c"
end_include

begin_comment
comment|/*  - regexec - interface for matching  = extern int regexec(const regex_t *, const char *, size_t, \  =					regmatch_t [], int);  = #define	REG_NOTBOL	00001  = #define	REG_NOTEOL	00002  = #define	REG_STARTEND	00004  = #define	REG_TRACE	00400	// tracing of execution  = #define	REG_LARGE	01000	// force large representation  = #define	REG_BACKR	02000	// force use of backref code  *  * We put this here so we can exploit knowledge of the state representation  * when choosing which matcher to call.  Also, by this point the matchers  * have been prototyped.  */
end_comment

begin_function
name|int
comment|/* 0 success, REG_NOMATCH failure */
name|regexec
parameter_list|(
name|preg
parameter_list|,
name|string
parameter_list|,
name|nmatch
parameter_list|,
name|pmatch
parameter_list|,
name|eflags
parameter_list|)
specifier|const
name|regex_t
modifier|*
name|__restrict
name|preg
decl_stmt|;
specifier|const
name|char
modifier|*
name|__restrict
name|string
decl_stmt|;
name|size_t
name|nmatch
decl_stmt|;
name|regmatch_t
name|pmatch
index|[
name|__restrict
index|]
decl_stmt|;
name|int
name|eflags
decl_stmt|;
block|{
name|struct
name|re_guts
modifier|*
name|g
init|=
name|preg
operator|->
name|re_g
decl_stmt|;
ifdef|#
directive|ifdef
name|REDEBUG
define|#
directive|define
name|GOODFLAGS
parameter_list|(
name|f
parameter_list|)
value|(f)
else|#
directive|else
define|#
directive|define
name|GOODFLAGS
parameter_list|(
name|f
parameter_list|)
value|((f)&(REG_NOTBOL|REG_NOTEOL|REG_STARTEND))
endif|#
directive|endif
if|if
condition|(
name|preg
operator|->
name|re_magic
operator|!=
name|MAGIC1
operator|||
name|g
operator|->
name|magic
operator|!=
name|MAGIC2
condition|)
return|return
operator|(
name|REG_BADPAT
operator|)
return|;
name|assert
argument_list|(
operator|!
operator|(
name|g
operator|->
name|iflags
operator|&
name|BAD
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|g
operator|->
name|iflags
operator|&
name|BAD
condition|)
comment|/* backstop for no-debug case */
return|return
operator|(
name|REG_BADPAT
operator|)
return|;
name|eflags
operator|=
name|GOODFLAGS
argument_list|(
name|eflags
argument_list|)
expr_stmt|;
if|if
condition|(
name|MB_CUR_MAX
operator|>
literal|1
condition|)
return|return
operator|(
name|mmatcher
argument_list|(
name|g
argument_list|,
operator|(
name|char
operator|*
operator|)
name|string
argument_list|,
name|nmatch
argument_list|,
name|pmatch
argument_list|,
name|eflags
argument_list|)
operator|)
return|;
elseif|else
if|if
condition|(
name|g
operator|->
name|nstates
operator|<=
name|CHAR_BIT
operator|*
sizeof|sizeof
argument_list|(
name|states1
argument_list|)
operator|&&
operator|!
operator|(
name|eflags
operator|&
name|REG_LARGE
operator|)
condition|)
return|return
operator|(
name|smatcher
argument_list|(
name|g
argument_list|,
operator|(
name|char
operator|*
operator|)
name|string
argument_list|,
name|nmatch
argument_list|,
name|pmatch
argument_list|,
name|eflags
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|lmatcher
argument_list|(
name|g
argument_list|,
operator|(
name|char
operator|*
operator|)
name|string
argument_list|,
name|nmatch
argument_list|,
name|pmatch
argument_list|,
name|eflags
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

