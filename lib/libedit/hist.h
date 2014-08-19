begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)hist.h	8.1 (Berkeley) 6/4/93  *	$NetBSD: hist.h,v 1.10 2003/08/07 16:44:31 agc Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * el.hist.c: History functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_h_el_hist
end_ifndef

begin_define
define|#
directive|define
name|_h_el_hist
end_define

begin_include
include|#
directive|include
file|"histedit.h"
end_include

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hist_fun_t
function_decl|)
parameter_list|(
name|ptr_t
parameter_list|,
name|HistEvent
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|el_history_t
block|{
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* The history buffer		*/
name|size_t
name|sz
decl_stmt|;
comment|/* Size of history buffer	*/
name|char
modifier|*
name|last
decl_stmt|;
comment|/* The last character		*/
name|int
name|eventno
decl_stmt|;
comment|/* Event we are looking for	*/
name|ptr_t
name|ref
decl_stmt|;
comment|/* Argument for history fcns	*/
name|hist_fun_t
name|fun
decl_stmt|;
comment|/* Event access			*/
name|HistEvent
name|ev
decl_stmt|;
comment|/* Event cookie			*/
block|}
name|el_history_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HIST_FUN
parameter_list|(
name|el
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|)
define|\
value|((((*(el)->el_history.fun) ((el)->el_history.ref,&(el)->el_history.ev, \ 	fn, arg)) == -1) ? NULL : (el)->el_history.ev.str)
end_define

begin_define
define|#
directive|define
name|HIST_NEXT
parameter_list|(
name|el
parameter_list|)
value|HIST_FUN(el, H_NEXT, NULL)
end_define

begin_define
define|#
directive|define
name|HIST_FIRST
parameter_list|(
name|el
parameter_list|)
value|HIST_FUN(el, H_FIRST, NULL)
end_define

begin_define
define|#
directive|define
name|HIST_LAST
parameter_list|(
name|el
parameter_list|)
value|HIST_FUN(el, H_LAST, NULL)
end_define

begin_define
define|#
directive|define
name|HIST_PREV
parameter_list|(
name|el
parameter_list|)
value|HIST_FUN(el, H_PREV, NULL)
end_define

begin_define
define|#
directive|define
name|HIST_SET
parameter_list|(
name|el
parameter_list|,
name|num
parameter_list|)
value|HIST_FUN(el, H_SET, num)
end_define

begin_define
define|#
directive|define
name|HIST_LOAD
parameter_list|(
name|el
parameter_list|,
name|fname
parameter_list|)
value|HIST_FUN(el, H_LOAD fname)
end_define

begin_define
define|#
directive|define
name|HIST_SAVE
parameter_list|(
name|el
parameter_list|,
name|fname
parameter_list|)
value|HIST_FUN(el, H_SAVE fname)
end_define

begin_define
define|#
directive|define
name|HIST_SAVE_FP
parameter_list|(
name|el
parameter_list|,
name|fp
parameter_list|)
value|HIST_FUN(el, H_SAVE_FP fp)
end_define

begin_function_decl
name|protected
name|int
name|hist_init
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|void
name|hist_end
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|el_action_t
name|hist_get
parameter_list|(
name|EditLine
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|hist_set
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|hist_fun_t
parameter_list|,
name|ptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|protected
name|int
name|hist_command
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

begin_function_decl
name|protected
name|int
name|hist_enlargebuf
parameter_list|(
name|EditLine
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _h_el_hist */
end_comment

end_unit

