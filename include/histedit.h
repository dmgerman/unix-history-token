begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)histedit.h	8.2 (Berkeley) 1/3/94  *	$NetBSD: histedit.h,v 1.15 2000/02/28 17:41:05 chopps Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * histedit.h: Line editor and history interface.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HISTEDIT_H_
end_ifndef

begin_define
define|#
directive|define
name|_HISTEDIT_H_
end_define

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

begin_macro
name|__BEGIN_DECLS
end_macro

begin_comment
comment|/*  * ==== Editing ====  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|editline
name|EditLine
typedef|;
end_typedef

begin_comment
comment|/*  * For user-defined function interface  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|lineinfo
block|{
specifier|const
name|char
modifier|*
name|buffer
decl_stmt|;
specifier|const
name|char
modifier|*
name|cursor
decl_stmt|;
specifier|const
name|char
modifier|*
name|lastchar
decl_stmt|;
block|}
name|LineInfo
typedef|;
end_typedef

begin_comment
comment|/*  * EditLine editor function return codes.  * For user-defined function interface  */
end_comment

begin_define
define|#
directive|define
name|CC_NORM
value|0
end_define

begin_define
define|#
directive|define
name|CC_NEWLINE
value|1
end_define

begin_define
define|#
directive|define
name|CC_EOF
value|2
end_define

begin_define
define|#
directive|define
name|CC_ARGHACK
value|3
end_define

begin_define
define|#
directive|define
name|CC_REFRESH
value|4
end_define

begin_define
define|#
directive|define
name|CC_CURSOR
value|5
end_define

begin_define
define|#
directive|define
name|CC_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|CC_FATAL
value|7
end_define

begin_define
define|#
directive|define
name|CC_REDISPLAY
value|8
end_define

begin_define
define|#
directive|define
name|CC_REFRESH_BEEP
value|9
end_define

begin_comment
comment|/*  * Initialization, cleanup, and resetting  */
end_comment

begin_function_decl
name|EditLine
modifier|*
name|el_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|el_reset
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|el_end
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get a line, a character or push a string back in the input queue  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|el_gets
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|el_getc
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|el_push
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Beep!  */
end_comment

begin_function_decl
name|void
name|el_beep
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * High level function internals control  * Parses argc, argv array and executes builtin editline commands  */
end_comment

begin_function_decl
name|int
name|el_parse
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Low level editline access functions  */
end_comment

begin_function_decl
name|int
name|el_set
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|el_get
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * el_set/el_get parameters  */
end_comment

begin_define
define|#
directive|define
name|EL_PROMPT
value|0
end_define

begin_comment
comment|/* , el_pfunc_t);		*/
end_comment

begin_define
define|#
directive|define
name|EL_TERMINAL
value|1
end_define

begin_comment
comment|/* , const char *);		*/
end_comment

begin_define
define|#
directive|define
name|EL_EDITOR
value|2
end_define

begin_comment
comment|/* , const char *);		*/
end_comment

begin_define
define|#
directive|define
name|EL_SIGNAL
value|3
end_define

begin_comment
comment|/* , int);			*/
end_comment

begin_define
define|#
directive|define
name|EL_BIND
value|4
end_define

begin_comment
comment|/* , const char *, ..., NULL);	*/
end_comment

begin_define
define|#
directive|define
name|EL_TELLTC
value|5
end_define

begin_comment
comment|/* , const char *, ..., NULL);	*/
end_comment

begin_define
define|#
directive|define
name|EL_SETTC
value|6
end_define

begin_comment
comment|/* , const char *, ..., NULL);	*/
end_comment

begin_define
define|#
directive|define
name|EL_ECHOTC
value|7
end_define

begin_comment
comment|/* , const char *, ..., NULL);	*/
end_comment

begin_define
define|#
directive|define
name|EL_SETTY
value|8
end_define

begin_comment
comment|/* , const char *, ..., NULL);	*/
end_comment

begin_define
define|#
directive|define
name|EL_ADDFN
value|9
end_define

begin_comment
comment|/* , const char *, const char *	*/
end_comment

begin_comment
comment|/* , el_func_t);		*/
end_comment

begin_define
define|#
directive|define
name|EL_HIST
value|10
end_define

begin_comment
comment|/* , hist_fun_t, const char *);	*/
end_comment

begin_define
define|#
directive|define
name|EL_EDITMODE
value|11
end_define

begin_comment
comment|/* , int);			*/
end_comment

begin_define
define|#
directive|define
name|EL_RPROMPT
value|12
end_define

begin_comment
comment|/* , el_pfunc_t);		*/
end_comment

begin_comment
comment|/*  * Source named file or $PWD/.editrc or $HOME/.editrc  */
end_comment

begin_function_decl
name|int
name|el_source
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Must be called when the terminal changes size; If EL_SIGNAL  * is set this is done automatically otherwise it is the responsibility  * of the application  */
end_comment

begin_function_decl
name|void
name|el_resize
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set user private data.  */
end_comment

begin_decl_stmt
name|void
name|el_data_set
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
modifier|*
name|el_data_get
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * User-defined function interface.  */
end_comment

begin_function_decl
specifier|const
name|LineInfo
modifier|*
name|el_line
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|el_insertstr
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|el_deletestr
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ==== History ====  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|history
name|History
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|HistEvent
block|{
name|int
name|num
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
name|HistEvent
typedef|;
end_typedef

begin_comment
comment|/*  * History access functions.  */
end_comment

begin_function_decl
name|History
modifier|*
name|history_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|history_end
parameter_list|(
name|History
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|history
parameter_list|(
name|History
modifier|*
parameter_list|,
name|HistEvent
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|H_FUNC
value|0
end_define

begin_comment
comment|/* , UTSL		*/
end_comment

begin_define
define|#
directive|define
name|H_SETSIZE
value|1
end_define

begin_comment
comment|/* , const int);	*/
end_comment

begin_define
define|#
directive|define
name|H_EVENT
value|1
end_define

begin_comment
comment|/* , const int);	*/
end_comment

begin_define
define|#
directive|define
name|H_GETSIZE
value|2
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_FIRST
value|3
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_LAST
value|4
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_PREV
value|5
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_NEXT
value|6
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_CURR
value|8
end_define

begin_comment
comment|/* , const int);	*/
end_comment

begin_define
define|#
directive|define
name|H_SET
value|7
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_ADD
value|9
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_ENTER
value|10
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_APPEND
value|11
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_END
value|12
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_define
define|#
directive|define
name|H_NEXT_STR
value|13
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_PREV_STR
value|14
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_NEXT_EVENT
value|15
end_define

begin_comment
comment|/* , const int);	*/
end_comment

begin_define
define|#
directive|define
name|H_PREV_EVENT
value|16
end_define

begin_comment
comment|/* , const int);	*/
end_comment

begin_define
define|#
directive|define
name|H_LOAD
value|17
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_SAVE
value|18
end_define

begin_comment
comment|/* , const char *);	*/
end_comment

begin_define
define|#
directive|define
name|H_CLEAR
value|19
end_define

begin_comment
comment|/* , void);		*/
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _HISTEDIT_H_ */
end_comment

end_unit

