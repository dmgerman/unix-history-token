begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: extern.h,v 1.52 2012/04/12 17:00:11 espie Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: extern.h,v 1.3 1996/01/13 23:25:24 pk Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ozan Yigit at York University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_comment
comment|/* eval.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|eval
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dodefine
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

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|expansion_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* expr.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|expr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* gnum4.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|addtoincludepath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|input_file
modifier|*
name|fopen_trypath
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doindir
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dobuiltin
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dopatsubst
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doregexp
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doprintlineno
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doprintfilename
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doesyscmd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getdivfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doformat
parameter_list|(
specifier|const
name|char
modifier|*
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* look.c */
end_comment

begin_define
define|#
directive|define
name|FLAG_UNTRACED
value|0
end_define

begin_define
define|#
directive|define
name|FLAG_TRACED
value|1
end_define

begin_define
define|#
directive|define
name|FLAG_NO_TRACE
value|2
end_define

begin_function_decl
specifier|extern
name|void
name|init_macros
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ndptr
name|lookup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_traced
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|ohash
name|macros
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|macro_definition
modifier|*
name|lookup_macro_definition
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|macro_define
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
specifier|extern
name|void
name|macro_pushdef
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
specifier|extern
name|void
name|macro_popdef
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|macro_undefine
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|setup_builtin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|macro_for_all
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|macro_definition
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|macro_getdef
parameter_list|(
name|p
parameter_list|)
value|((p)->d)
end_define

begin_define
define|#
directive|define
name|macro_name
parameter_list|(
name|p
parameter_list|)
value|((p)->name)
end_define

begin_define
define|#
directive|define
name|macro_builtin_type
parameter_list|(
name|p
parameter_list|)
value|((p)->builtin_type)
end_define

begin_define
define|#
directive|define
name|is_traced
parameter_list|(
name|p
parameter_list|)
value|((p)->trace_flags == FLAG_NO_TRACE ? (trace_flags& TRACE_ALL) : (p)->trace_flags)
end_define

begin_function_decl
specifier|extern
name|ndptr
name|macro_getbuiltin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* main.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|outputstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|do_emit_synchline
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|exit_code
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|emit_synchline
parameter_list|()
value|do { if (synch_lines) do_emit_synchline(); } while(0)
end_define

begin_comment
comment|/* misc.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|chrsave
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|compute_prevep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|getdiv
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ptrdiff_t
name|indx
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
specifier|extern
name|void
name|initspaces
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|killdiv
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|onintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbnum
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbnumbase
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbunsigned
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pbstr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pushback
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xalloc
parameter_list|(
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|resizedivs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|buffer_mark
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_buffer
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|m4errx
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|obtain_char
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_input
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|release_input
parameter_list|(
name|struct
name|input_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* speeded-up versions of chrsave/pushback */
end_comment

begin_define
define|#
directive|define
name|PUSHBACK
parameter_list|(
name|c
parameter_list|)
define|\
value|do {					\ 		if (bp>= endpbb)		\ 			enlarge_bufspace();	\ 		*bp++ = (c);			\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|CHRSAVE
parameter_list|(
name|c
parameter_list|)
define|\
value|do {					\ 		if (ep>= endest)		\ 			enlarge_strspace();	\ 		*ep++ = (c);			\ 	} while(0)
end_define

begin_comment
comment|/* and corresponding exposure for local symbols */
end_comment

begin_function_decl
specifier|extern
name|void
name|enlarge_bufspace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|enlarge_strspace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|endpbb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|endest
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* trace.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|trace_flags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRACE_ALL
value|512
end_define

begin_function_decl
specifier|extern
name|void
name|trace_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|size_t
name|trace
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|input_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_trace
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_trace_flags
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|traceout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|stae
modifier|*
name|mstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of m4 machine */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* shadow stack, for string space extension */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* active output file pointer */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|input_file
name|infile
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack (0=stdin) */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
modifier|*
name|outfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion array(0=bitbucket) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum number of diversions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4 call frame pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ilevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file stack pointer */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|oindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* diversion index. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current m4 stack pointer */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first available character */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* push-back buffer */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bufbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer base for this ilevel */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
modifier|*
name|bbase
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer base per ilevel */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|ecommt
index|[
name|MAXCCHARS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* end character for comment */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* first free char in strspace */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|lquote
index|[
name|MAXCCHARS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* left quote character (`) */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|m4wraps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* m4wrap string default. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|maxwraps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of m4wraps array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|wrapindex
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current index in m4wraps */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|null
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* as it says.. just a null. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|rquote
index|[
name|MAXCCHARS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* right quote character (') */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|scommt
index|[
name|MAXCCHARS
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* start character for comment */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|synch_lines
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line synchronisation directives */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mimic_gnu
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* behaves like gnu-m4 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|prefix_builtins
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prefix builtin macros with m4_ */
end_comment

end_unit

