begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ed.h: type and constant definitions for the ed editor. */
end_comment

begin_comment
comment|/*  * Copyright (c) 1993 Andrew Moore  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ed.h,v 1.5 1994/02/01 00:34:39 alm Exp  *	$Id: ed.h,v 1.10 1997/02/22 14:03:14 peter Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* for MAXPATHLEN */
end_comment

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
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<limits.h>
end_include

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
file|<unistd.h>
end_include

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
name|MINBUFSZ
value|512
end_define

begin_comment
comment|/* minimum buffer size - must be> 0 */
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

begin_ifdef
ifdef|#
directive|ifdef
name|INT_MAX
end_ifdef

begin_define
define|#
directive|define
name|LINECHARS
value|INT_MAX
end_define

begin_comment
comment|/* max chars per line */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINECHARS
value|MAXINT
end_define

begin_comment
comment|/* max chars per line */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gflags */
end_comment

begin_define
define|#
directive|define
name|GLB
value|001
end_define

begin_comment
comment|/* global command */
end_comment

begin_define
define|#
directive|define
name|GPR
value|002
end_define

begin_comment
comment|/* print after command */
end_comment

begin_define
define|#
directive|define
name|GLS
value|004
end_define

begin_comment
comment|/* list after command */
end_comment

begin_define
define|#
directive|define
name|GNP
value|010
end_define

begin_comment
comment|/* enumerate after command */
end_comment

begin_define
define|#
directive|define
name|GSG
value|020
end_define

begin_comment
comment|/* global substitute */
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
name|q_forw
decl_stmt|;
name|struct
name|line
modifier|*
name|q_back
decl_stmt|;
name|off_t
name|seek
decl_stmt|;
comment|/* address of line in scratch buffer */
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

begin_define
define|#
directive|define
name|INC_MOD
parameter_list|(
name|l
parameter_list|,
name|k
parameter_list|)
value|((l) + 1> (k) ? 0 : (l) + 1)
end_define

begin_define
define|#
directive|define
name|DEC_MOD
parameter_list|(
name|l
parameter_list|,
name|k
parameter_list|)
value|((l) - 1< 0 ? (k) : (l) - 1)
end_define

begin_comment
comment|/* SPL1: disable some interrupts (requires reliable signals) */
end_comment

begin_define
define|#
directive|define
name|SPL1
parameter_list|()
value|mutex++
end_define

begin_comment
comment|/* SPL0: enable all interrupts; check sigflags (requires reliable signals) */
end_comment

begin_define
define|#
directive|define
name|SPL0
parameter_list|()
define|\
value|if (--mutex == 0) { \ 	if (sigflags& (1<< (SIGHUP - 1))) handle_hup(SIGHUP); \ 	if (sigflags& (1<< (SIGINT - 1))) handle_int(SIGINT); \ }
end_define

begin_comment
comment|/* STRTOL: convert a string to long */
end_comment

begin_define
define|#
directive|define
name|STRTOL
parameter_list|(
name|i
parameter_list|,
name|p
parameter_list|)
value|{ \ 	if (((i = strtol(p,&p, 10)) == LONG_MIN || i == LONG_MAX)&& \ 	    errno == ERANGE) { \ 		sprintf(errmsg, "number out of range"); \ 	    	i = 0; \ 		return ERR; \ 	} \ }
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
comment|/* REALLOC: assure at least a minimum size for buffer b */
end_comment

begin_define
define|#
directive|define
name|REALLOC
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
value|if ((i)> (n)) { \ 	int ti = (n); \ 	char *ts; \ 	SPL1(); \ 	if ((b) != NULL) { \ 		if ((ts = (char *) realloc((b), ti += max((i), MINBUFSZ))) == NULL) { \ 			fprintf(stderr, "%s\n", strerror(errno)); \ 			sprintf(errmsg, "out of memory"); \ 			SPL0(); \ 			return err; \ 		} \ 	} else { \ 		if ((ts = (char *) malloc(ti += max((i), MINBUFSZ))) == NULL) { \ 			fprintf(stderr, "%s\n", strerror(errno)); \ 			sprintf(errmsg, "out of memory"); \ 			SPL0(); \ 			return err; \ 		} \ 	} \ 	(n) = ti; \ 	(b) = ts; \ 	SPL0(); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NO_REALLOC_NULL */
end_comment

begin_comment
comment|/* REALLOC: assure at least a minimum size for buffer b */
end_comment

begin_define
define|#
directive|define
name|REALLOC
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
value|if ((i)> (n)) { \ 	int ti = (n); \ 	char *ts; \ 	SPL1(); \ 	if ((ts = (char *) realloc((b), ti += max((i), MINBUFSZ))) == NULL) { \ 		fprintf(stderr, "%s\n", strerror(errno)); \ 		sprintf(errmsg, "out of memory"); \ 		SPL0(); \ 		return err; \ 	} \ 	(n) = ti; \ 	(b) = ts; \ 	SPL0(); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_REALLOC_NULL */
end_comment

begin_comment
comment|/* REQUE: link pred before succ */
end_comment

begin_define
define|#
directive|define
name|REQUE
parameter_list|(
name|pred
parameter_list|,
name|succ
parameter_list|)
value|(pred)->q_forw = (succ), (succ)->q_back = (pred)
end_define

begin_comment
comment|/* INSQUE: insert elem in circular queue after pred */
end_comment

begin_define
define|#
directive|define
name|INSQUE
parameter_list|(
name|elem
parameter_list|,
name|pred
parameter_list|)
define|\
value|{ \ 	REQUE((elem), (pred)->q_forw); \ 	REQUE((pred), elem); \ }
end_define

begin_comment
comment|/* REMQUE: remove_lines elem from circular queue */
end_comment

begin_define
define|#
directive|define
name|REMQUE
parameter_list|(
name|elem
parameter_list|)
value|REQUE((elem)->q_back, (elem)->q_forw);
end_define

begin_comment
comment|/* NUL_TO_NEWLINE: overwrite ASCII NULs with newlines */
end_comment

begin_define
define|#
directive|define
name|NUL_TO_NEWLINE
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|translit_text(s, l, '\0', '\n')
end_define

begin_comment
comment|/* NEWLINE_TO_NUL: overwrite newlines with ASCII NULs */
end_comment

begin_define
define|#
directive|define
name|NEWLINE_TO_NUL
parameter_list|(
name|s
parameter_list|,
name|l
parameter_list|)
value|translit_text(s, l, '\n', '\0')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

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
comment|/* Local Function Declarations */
end_comment

begin_decl_stmt
name|void
name|add_line_node
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
name|int
name|append_lines
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
name|apply_subst_template
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
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|build_active_list
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
name|cbc_decode
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
name|cbc_encode
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
name|int
name|check_addr_range
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
name|void
name|clear_active_list
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
name|clear_undo_stack
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
name|close_sbuf
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
name|copy_lines
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
name|delete_lines
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
name|void
name|des_error
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
name|display_lines
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
name|line_t
modifier|*
name|dup_line_node
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
name|int
name|exec_command
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
name|exec_global
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
name|void
name|expand_des_key
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
name|int
name|extract_addr_range
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
name|extract_pattern
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
name|extract_subst_tail
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|extract_subst_template
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
name|filter_lines
name|__P
argument_list|(
operator|(
name|long
operator|,
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|flush_des_file
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
name|line_t
modifier|*
name|get_addressed_line_node
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pattern_t
modifier|*
name|get_compiled_pattern
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
name|get_des_char
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
name|char
modifier|*
name|get_extended_line
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
name|get_filename
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
name|get_keyword
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
name|get_line_node_addr
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
name|long
name|get_matching_node_addr
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
name|get_marked_node_addr
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
name|get_sbuf_line
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
name|int
name|get_shell_command
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
name|get_stream_line
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
name|get_tty_line
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
name|handle_hup
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
name|handle_int
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
name|handle_winch
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
name|has_trailing_escape
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
name|int
name|hex_to_binary
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
name|void
name|init_buffers
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
name|init_des_cipher
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
name|is_legal_filename
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
name|join_lines
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
name|mark_line_node
name|__P
argument_list|(
operator|(
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
name|move_lines
name|__P
argument_list|(
operator|(
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|line_t
modifier|*
name|next_active_node
name|__P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|next_addr
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
name|open_sbuf
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
name|parse_char_class
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
name|pop_undo_stack
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
name|push_undo_stack
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
name|int
name|put_des_char
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
name|char
modifier|*
name|put_sbuf_line
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
name|put_stream_line
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|put_tty_line
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
name|long
name|read_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|read_stream
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|search_and_replace
name|__P
argument_list|(
operator|(
name|pattern_t
operator|*
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
name|set_active_node
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
name|set_des_key
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
name|signal_hup
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
name|signal_int
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
name|strip_escapes
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
name|substitute_matching_text
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
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|translit_text
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
name|void
name|unmark_line_node
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
name|unset_active_nodes
name|__P
argument_list|(
operator|(
name|line_t
operator|*
operator|,
name|line_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|write_file
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|write_stream
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|long
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global buffers */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|stdinbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ibuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ibufp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibufsz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* global flags */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|isbinary
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|isglobal
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|modified
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

begin_comment
comment|/* global vars */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|addr_last
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|current_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|errmsg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|first_addr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|second_addr
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

