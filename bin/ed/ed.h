begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ed.h: type and constant definitions for the ed editor. */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Andrew Moore, Talke Studio.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ed.h	5.5 (Berkeley) 3/28/93  */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD
argument_list|)
operator|&&
name|BSD
operator|>=
literal|199103
operator|||
name|defined
argument_list|(
name|__386BSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for MAXPATHLEN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_define
define|#
directive|define
name|BITS
parameter_list|(
name|type
parameter_list|)
value|(BITSPERBYTE * (int)sizeof(type))
end_define

begin_define
define|#
directive|define
name|CHARBITS
value|BITS(char)
end_define

begin_define
define|#
directive|define
name|INTBITS
value|BITS(int)
end_define

begin_define
define|#
directive|define
name|INTHIBIT
value|(1<< (INTBITS - 1))
end_define

begin_define
define|#
directive|define
name|ERR
value|(-2)
end_define

begin_define
define|#
directive|define
name|EMOD
value|(-3)
end_define

begin_define
define|#
directive|define
name|FATAL
value|(-4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|255
end_define

begin_comment
comment|/* _POSIX_PATH_MAX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAXFNAME
value|MAXPATHLEN
end_define

begin_comment
comment|/* max file name size */
end_comment

begin_define
define|#
directive|define
name|MINBUFSZ
value|512
end_define

begin_comment
comment|/* minimum buffer size - must be> 0 */
end_comment

begin_define
define|#
directive|define
name|LINECHARS
value|(INTHIBIT - 1)
end_define

begin_comment
comment|/* max chars per line */
end_comment

begin_define
define|#
directive|define
name|SE_MAX
value|30
end_define

begin_comment
comment|/* max subexpressions in a regular expression */
end_comment

begin_typedef
typedef|typedef
name|regex_t
name|pattern_t
typedef|;
end_typedef

begin_comment
comment|/* Line node */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|line
block|{
name|struct
name|line
modifier|*
name|next
decl_stmt|;
name|struct
name|line
modifier|*
name|prev
decl_stmt|;
name|off_t
name|seek
decl_stmt|;
comment|/* address of line in scratch buffer */
define|#
directive|define
name|ACTV
value|INTHIBIT
comment|/* active bit: high bit of len */
name|int
name|len
decl_stmt|;
comment|/* length of line */
block|}
name|line_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|undo
block|{
comment|/* type of undo nodes */
define|#
directive|define
name|UADD
value|0
define|#
directive|define
name|UDEL
value|1
define|#
directive|define
name|UMOV
value|2
define|#
directive|define
name|VMOV
value|3
name|int
name|type
decl_stmt|;
comment|/* command type */
name|line_t
modifier|*
name|h
decl_stmt|;
comment|/* head of list */
name|line_t
modifier|*
name|t
decl_stmt|;
comment|/* tail of list */
block|}
name|undo_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)> (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|min
end_ifndef

begin_define
define|#
directive|define
name|min
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)< (b) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nextln: return line after l mod k */
end_comment

begin_define
define|#
directive|define
name|nextln
parameter_list|(
name|l
parameter_list|,
name|k
parameter_list|)
value|((l)+1> (k) ? 0 : (l)+1)
end_define

begin_comment
comment|/* nextln: return line before l mod k */
end_comment

begin_define
define|#
directive|define
name|prevln
parameter_list|(
name|l
parameter_list|,
name|k
parameter_list|)
value|((l)-1< 0 ? (k) : (l)-1)
end_define

begin_define
define|#
directive|define
name|skipblanks
parameter_list|()
value|while (isspace(*ibufp)&& *ibufp != '\n') ibufp++
end_define

begin_comment
comment|/* spl1: disable some interrupts (requires reliable signals) */
end_comment

begin_define
define|#
directive|define
name|spl1
parameter_list|()
value|mutex++
end_define

begin_comment
comment|/* spl0: enable all interrupts; check sigflags (requires reliable signals) */
end_comment

begin_define
define|#
directive|define
name|spl0
parameter_list|()
define|\
value|if (--mutex == 0) { \ 	if (sigflags& (1<< SIGHUP)) dohup(SIGHUP); \ 	if (sigflags& (1<< SIGINT)) dointr(SIGINT); \ }
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|NO_REALLOC_NULL
argument_list|)
end_if

begin_comment
comment|/* CKBUF: assure at least a minimum size for buffer b */
end_comment

begin_define
define|#
directive|define
name|CKBUF
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|i
parameter_list|,
name|err
parameter_list|)
define|\
value|if ((i)> (n)) { \ 	int ti = (n); \ 	char *ts; \ 	spl1(); \ 	if ((b) != NULL) { \ 		if ((ts = (char *) realloc((b), ti += max((i), MINBUFSZ))) == NULL) { \ 			fprintf(stderr, "%s\n", strerror(errno)); \ 			sprintf(errmsg, "out of memory"); \ 			spl0(); \ 			return err; \ 		} \ 	} else { \ 		if ((ts = (char *) malloc(ti += max((i), MINBUFSZ))) == NULL) { \ 			fprintf(stderr, "%s\n", strerror(errno)); \ 			sprintf(errmsg, "out of memory"); \ 			spl0(); \ 			return err; \ 		} \ 	} \ 	(n) = ti; \ 	(b) = ts; \ 	spl0(); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_REALLOC_NULL */
end_comment

begin_comment
comment|/* CKBUF: assure at least a minimum size for buffer b */
end_comment

begin_define
define|#
directive|define
name|CKBUF
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|i
parameter_list|,
name|err
parameter_list|)
define|\
value|if ((i)> (n)) { \ 	int ti = (n); \ 	char *ts; \ 	spl1(); \ 	if ((ts = (char *) realloc((b), ti += max((i), MINBUFSZ))) == NULL) { \ 		fprintf(stderr, "%s\n", strerror(errno)); \ 		sprintf(errmsg, "out of memory"); \ 		spl0(); \ 		return err; \ 	} \ 	(n) = ti; \ 	(b) = ts; \ 	spl0(); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_REALLOC_NULL */
end_comment

begin_comment
comment|/* requeue: link pred before succ */
end_comment

begin_define
define|#
directive|define
name|requeue
parameter_list|(
name|pred
parameter_list|,
name|succ
parameter_list|)
value|(pred)->next = (succ), (succ)->prev = (pred)
end_define

begin_comment
comment|/* insqueue: insert elem in circular queue after pred */
end_comment

begin_define
define|#
directive|define
name|insqueue
parameter_list|(
name|elem
parameter_list|,
name|pred
parameter_list|)
define|\
value|{ \ 	requeue((elem), (pred)->next); \ 	requeue((pred), elem); \ }
end_define

begin_comment
comment|/* remqueue: remove elem from circular queue */
end_comment

begin_define
define|#
directive|define
name|remqueue
parameter_list|(
name|elem
parameter_list|)
value|requeue((elem)->prev, (elem)->next);
end_define

begin_comment
comment|/* nultonl: overwrite ASCII NULs with newlines */
end_comment

begin_define
define|#
directive|define
name|nultonl
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|translit(s, l, '\0', '\n')
end_define

begin_comment
comment|/* nltonul: overwrite newlines with ASCII NULs */
end_comment

begin_define
define|#
directive|define
name|nltonul
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|translit(s, l, '\n', '\0')
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|strerror
end_ifndef

begin_define
define|#
directive|define
name|strerror
parameter_list|(
name|n
parameter_list|)
value|sys_errlist[n]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__P
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|proto
parameter_list|)
value|()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__P
parameter_list|(
name|proto
parameter_list|)
value|proto
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
comment|/* local function declarations */
end_comment

begin_decl_stmt
name|int
name|append
name|__P
argument_list|(
operator|(
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cbcdec
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|cbcenc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ckfn
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ckglob
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ckrange
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|desflush
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|desgetc
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|desinit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|desputc
name|__P
argument_list|(
operator|(
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|docmd
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|err
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ccl
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cvtkey
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|doglob
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dohup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dointr
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dowinch
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|doprint
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|doread
name|__P
argument_list|(
operator|(
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|dowrite
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|esctos
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|patscan
name|__P
argument_list|(
operator|(
name|pattern_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|getaddr
name|__P
argument_list|(
operator|(
name|line_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getcmdv
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getfn
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getkey
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|getlhs
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getline
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getlist
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|getnum
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|getone
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|line_t
modifier|*
name|getlp
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getrhs
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|getshcmd
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|gettxt
name|__P
argument_list|(
operator|(
name|line_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_buf
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|join
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lndelete
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|line_t
modifier|*
name|lpdup
name|__P
argument_list|(
operator|(
name|line_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|lpqueue
name|__P
argument_list|(
operator|(
name|line_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|makekey
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|makesub
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|translit
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|move
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oddesc
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onhup
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|onintr
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pattern_t
modifier|*
name|optpat
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|putstr
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|long
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|puttxt
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|quit
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|regsub
name|__P
argument_list|(
operator|(
name|pattern_t
operator|*
operator|,
name|line_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbclose
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sbopen
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sgetline
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|catsub
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|regmatch_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|subst
name|__P
argument_list|(
operator|(
name|pattern_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tobinhex
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|transfer
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|undo
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|undo_t
modifier|*
name|upush
name|__P
argument_list|(
operator|(
name|int
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ureset
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mutex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sigflags
decl_stmt|;
end_decl_stmt

end_unit

