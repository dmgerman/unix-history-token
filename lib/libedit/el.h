begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)el.h	8.1 (Berkeley) 6/4/93  *	$NetBSD: el.h,v 1.16 2003/10/18 23:48:42 christos Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * el.h: Internal structures.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el
end_ifndef

begin_define
define|#
directive|define
name|_h_el
end_define

begin_comment
comment|/*  * Local defaults  */
end_comment

begin_define
define|#
directive|define
name|KSHVI
end_define

begin_define
define|#
directive|define
name|VIDEFAULT
end_define

begin_define
define|#
directive|define
name|ANCHOR
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|EL_BUFSIZ
value|1024
end_define

begin_comment
comment|/* Maximum line size		*/
end_comment

begin_define
define|#
directive|define
name|HANDLE_SIGNALS
value|0x01
end_define

begin_define
define|#
directive|define
name|NO_TTY
value|0x02
end_define

begin_define
define|#
directive|define
name|EDIT_DISABLED
value|0x04
end_define

begin_define
define|#
directive|define
name|UNBUFFERED
value|0x08
end_define

begin_typedef
typedef|typedef
name|int
name|bool_t
typedef|;
end_typedef

begin_comment
comment|/* True or not			*/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|el_action_t
typedef|;
end_typedef

begin_comment
comment|/* Index to command array	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coord_t
block|{
comment|/* Position on the screen	*/
name|int
name|h
decl_stmt|;
name|int
name|v
decl_stmt|;
block|}
name|coord_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_line_t
block|{
name|char
modifier|*
name|buffer
decl_stmt|;
comment|/* Input line			*/
name|char
modifier|*
name|cursor
decl_stmt|;
comment|/* Cursor position		*/
name|char
modifier|*
name|lastchar
decl_stmt|;
comment|/* Last character		*/
specifier|const
name|char
modifier|*
name|limit
decl_stmt|;
comment|/* Max position			*/
block|}
name|el_line_t
typedef|;
end_typedef

begin_comment
comment|/*  * Editor state  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|el_state_t
block|{
name|int
name|inputmode
decl_stmt|;
comment|/* What mode are we in?		*/
name|int
name|doingarg
decl_stmt|;
comment|/* Are we getting an argument?	*/
name|int
name|argument
decl_stmt|;
comment|/* Numeric argument		*/
name|int
name|metanext
decl_stmt|;
comment|/* Is the next char a meta char */
name|el_action_t
name|lastcmd
decl_stmt|;
comment|/* Previous command		*/
name|el_action_t
name|thiscmd
decl_stmt|;
comment|/* this command 		*/
name|char
name|thisch
decl_stmt|;
comment|/* char that generated it	*/
block|}
name|el_state_t
typedef|;
end_typedef

begin_comment
comment|/*  * Until we come up with something better...  */
end_comment

begin_define
define|#
directive|define
name|el_strdup
parameter_list|(
name|a
parameter_list|)
value|strdup(a)
end_define

begin_define
define|#
directive|define
name|el_malloc
parameter_list|(
name|a
parameter_list|)
value|malloc(a)
end_define

begin_define
define|#
directive|define
name|el_realloc
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|realloc(a, b)
end_define

begin_define
define|#
directive|define
name|el_free
parameter_list|(
name|a
parameter_list|)
value|free(a)
end_define

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"prompt.h"
end_include

begin_include
include|#
directive|include
file|"key.h"
end_include

begin_include
include|#
directive|include
file|"term.h"
end_include

begin_include
include|#
directive|include
file|"refresh.h"
end_include

begin_include
include|#
directive|include
file|"chared.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"search.h"
end_include

begin_include
include|#
directive|include
file|"hist.h"
end_include

begin_include
include|#
directive|include
file|"map.h"
end_include

begin_include
include|#
directive|include
file|"parse.h"
end_include

begin_include
include|#
directive|include
file|"sig.h"
end_include

begin_include
include|#
directive|include
file|"help.h"
end_include

begin_include
include|#
directive|include
file|"read.h"
end_include

begin_struct
struct|struct
name|editline
block|{
name|char
modifier|*
name|el_prog
decl_stmt|;
comment|/* the program name		*/
name|FILE
modifier|*
name|el_outfile
decl_stmt|;
comment|/* Stdio stuff			*/
name|FILE
modifier|*
name|el_errfile
decl_stmt|;
comment|/* Stdio stuff			*/
name|int
name|el_infd
decl_stmt|;
comment|/* Input file descriptor	*/
name|int
name|el_flags
decl_stmt|;
comment|/* Various flags.		*/
name|coord_t
name|el_cursor
decl_stmt|;
comment|/* Cursor location		*/
name|char
modifier|*
modifier|*
name|el_display
decl_stmt|;
comment|/* Real screen image = what is there */
name|char
modifier|*
modifier|*
name|el_vdisplay
decl_stmt|;
comment|/* Virtual screen image = what we see */
name|void
modifier|*
name|el_data
decl_stmt|;
comment|/* Client data			*/
name|el_line_t
name|el_line
decl_stmt|;
comment|/* The current line information	*/
name|el_state_t
name|el_state
decl_stmt|;
comment|/* Current editor state		*/
name|el_term_t
name|el_term
decl_stmt|;
comment|/* Terminal dependent stuff	*/
name|el_tty_t
name|el_tty
decl_stmt|;
comment|/* Tty dependent stuff		*/
name|el_refresh_t
name|el_refresh
decl_stmt|;
comment|/* Refresh stuff		*/
name|el_prompt_t
name|el_prompt
decl_stmt|;
comment|/* Prompt stuff			*/
name|el_prompt_t
name|el_rprompt
decl_stmt|;
comment|/* Prompt stuff			*/
name|el_chared_t
name|el_chared
decl_stmt|;
comment|/* Characted editor stuff	*/
name|el_map_t
name|el_map
decl_stmt|;
comment|/* Key mapping stuff		*/
name|el_key_t
name|el_key
decl_stmt|;
comment|/* Key binding stuff		*/
name|el_history_t
name|el_history
decl_stmt|;
comment|/* History stuff		*/
name|el_search_t
name|el_search
decl_stmt|;
comment|/* Search stuff			*/
name|el_signal_t
name|el_signal
decl_stmt|;
comment|/* Signal handling stuff	*/
name|el_read_t
name|el_read
decl_stmt|;
comment|/* Character reading stuff	*/
block|}
struct|;
end_struct

begin_function_decl
name|protected
name|int
name|el_editmode
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|EL_ABORT
parameter_list|(
name|a
parameter_list|)
value|do { \ 				fprintf(el->el_errfile, "%s, %d: ", \ 					 __FILE__, __LINE__); \ 				fprintf a; \ 				abort(); \ 			} while(
comment|/*CONSTCOND*/
value|0);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EL_ABORT
parameter_list|(
name|a
parameter_list|)
value|abort()
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
comment|/* _h_el */
end_comment

end_unit

