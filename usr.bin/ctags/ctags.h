begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctags.h	8.3 (Berkeley) 4/2/94  *  * $FreeBSD$  *  */
end_comment

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|YES
value|1
end_define

begin_define
define|#
directive|define
name|NO
value|0
end_define

begin_define
define|#
directive|define
name|EOS
value|'\0'
end_define

begin_define
define|#
directive|define
name|ENDLINE
value|50
end_define

begin_comment
comment|/* max length of pattern */
end_comment

begin_define
define|#
directive|define
name|MAXTOKEN
value|250
end_define

begin_comment
comment|/* max size of single token */
end_comment

begin_define
define|#
directive|define
name|SETLINE
value|{++lineno;lineftell = ftell(inf);}
end_define

begin_define
define|#
directive|define
name|GETC
parameter_list|(
name|op
parameter_list|,
name|exp
parameter_list|)
value|((c = getc(inf)) op (int)exp)
end_define

begin_comment
comment|/*  * These character classification macros assume that the (EOF& 0xff) element  * of the arrays is always 'NO', as the EOF return from getc() gets masked  * to that value.  Masking with 0xff has no effect for normal characters  * returned by getc() provided chars have 8 bits.  */
end_comment

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|arg
parameter_list|)
value|_wht[arg& 0xff]
end_define

begin_comment
comment|/* T if char is white */
end_comment

begin_define
define|#
directive|define
name|begtoken
parameter_list|(
name|arg
parameter_list|)
value|_btk[arg& 0xff]
end_define

begin_comment
comment|/* T if char can start token */
end_comment

begin_define
define|#
directive|define
name|intoken
parameter_list|(
name|arg
parameter_list|)
value|_itk[arg& 0xff]
end_define

begin_comment
comment|/* T if char can be in token */
end_comment

begin_define
define|#
directive|define
name|endtoken
parameter_list|(
name|arg
parameter_list|)
value|_etk[arg& 0xff]
end_define

begin_comment
comment|/* T if char ends tokens */
end_comment

begin_define
define|#
directive|define
name|isgood
parameter_list|(
name|arg
parameter_list|)
value|_gd[arg& 0xff]
end_define

begin_comment
comment|/* T if char can be after ')' */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nd_st
block|{
comment|/* sorting structure */
name|struct
name|nd_st
modifier|*
name|left
decl_stmt|,
modifier|*
name|right
decl_stmt|;
comment|/* left and right sons */
name|char
modifier|*
name|entry
decl_stmt|,
comment|/* function or type name */
modifier|*
name|file
decl_stmt|,
comment|/* file name */
modifier|*
name|pat
decl_stmt|;
comment|/* search pattern */
name|int
name|lno
decl_stmt|;
comment|/* for -x option */
name|bool
name|been_warned
decl_stmt|;
comment|/* set if noticed dup */
block|}
name|NODE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|curfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current input file name */
end_comment

begin_decl_stmt
specifier|extern
name|NODE
modifier|*
name|head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of the sorted binary tree */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|inf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ioptr for current input file */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|outf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ioptr for current output file */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|lineftell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ftell after getc( inf ) == '\n' */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lineno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* line number of current line */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -d: non-macro defines */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -t: create tags for typedefs */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -v: vgrind style index output */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|wflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -w: suppress warnings */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -x: cxref style output */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|_wht
index|[]
decl_stmt|,
name|_etk
index|[]
decl_stmt|,
name|_itk
index|[]
decl_stmt|,
name|_btk
index|[]
decl_stmt|,
name|_gd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|lbuf
index|[
name|LINE_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lbp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|searchar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ex search character */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cicmp
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
specifier|extern
name|void
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
specifier|extern
name|void
name|pfnote
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|skip_key
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|put_entries
name|__P
argument_list|(
operator|(
name|NODE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|toss_yysec
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
name|void
name|l_entries
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
name|void
name|y_entries
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
name|int
name|PF_funcs
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
name|void
name|c_entries
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
name|void
name|skip_comment
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

