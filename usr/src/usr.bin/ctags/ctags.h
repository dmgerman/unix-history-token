begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ctags.h	5.4 (Berkeley) 2/26/91  */
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

begin_define
define|#
directive|define
name|iswhite
parameter_list|(
name|arg
parameter_list|)
value|(_wht[arg])
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
value|(_btk[arg])
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
value|(_itk[arg])
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
value|(_etk[arg])
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
value|(_gd[arg])
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
decl_stmt|,
comment|/* line number of current line */
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
index|[
literal|0177
index|]
decl_stmt|,
name|_etk
index|[
literal|0177
index|]
decl_stmt|,
name|_itk
index|[
literal|0177
index|]
decl_stmt|,
name|_btk
index|[
literal|0177
index|]
decl_stmt|,
name|_gd
index|[
literal|0177
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|lbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

end_unit

