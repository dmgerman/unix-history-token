begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1984. */
end_comment

begin_comment
comment|/* $Header: b2syn.h,v 1.1 84/06/28 00:48:52 timo Exp $ */
end_comment

begin_comment
comment|/* bsyn.h: syntax */
end_comment

begin_comment
comment|/* General parsing routines */
end_comment

begin_define
define|#
directive|define
name|Eotc
value|'\0'
end_define

begin_define
define|#
directive|define
name|Eouc
value|'\036'
end_define

begin_comment
comment|/* The character Eotc (end of text char)		*/
end_comment

begin_comment
comment|/* is placed after the last read character in txbuf.	*/
end_comment

begin_comment
comment|/* In general it follows a newline.			*/
end_comment

begin_comment
comment|/* If Eotc is encountered and more input is required,	*/
end_comment

begin_comment
comment|/* getline() is called.					*/
end_comment

begin_comment
comment|/* Eouc (end of unit char) is similar except the system	*/
end_comment

begin_comment
comment|/* never has to read beyond it.				*/
end_comment

begin_define
define|#
directive|define
name|Char
parameter_list|(
name|tx
parameter_list|)
value|(*(tx))
end_define

begin_define
define|#
directive|define
name|Eol
parameter_list|(
name|tx
parameter_list|)
value|(Char(tx) == '\n' || Char(tx) == Eouc)
end_define

begin_define
define|#
directive|define
name|Ceol
parameter_list|(
name|tx
parameter_list|)
value|(Char(tx) == '\\' || Eol(tx))
end_define

begin_define
define|#
directive|define
name|To_eol
parameter_list|(
name|tx
parameter_list|)
value|while (!Eol(tx)) tx++;
end_define

begin_define
define|#
directive|define
name|Mark_unit_end
parameter_list|(
name|tx
parameter_list|)
value|*tx= Eouc;
end_define

begin_define
define|#
directive|define
name|Space
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || (c) == '\t')
end_define

begin_define
define|#
directive|define
name|Skipsp
parameter_list|(
name|tx
parameter_list|)
value|while(Space(Char(tx))) tx++
end_define

begin_define
define|#
directive|define
name|Letter
parameter_list|(
name|c
parameter_list|)
value|('a'<=c&&c<='z')
end_define

begin_define
define|#
directive|define
name|Cap
parameter_list|(
name|c
parameter_list|)
value|('A'<=c&&c<='Z')
end_define

begin_define
define|#
directive|define
name|Dig
parameter_list|(
name|c
parameter_list|)
value|('0'<=c&&c<='9')
end_define

begin_define
define|#
directive|define
name|Keymark
parameter_list|(
name|c
parameter_list|)
value|(Cap(c) || Dig(c) || c=='\'' || c=='"')
end_define

begin_define
define|#
directive|define
name|Tagmark
parameter_list|(
name|c
parameter_list|)
value|(Letter(c) || Dig(c) || c=='\'' || c=='"')
end_define

begin_define
define|#
directive|define
name|Keytagmark
parameter_list|(
name|c
parameter_list|)
value|(Keymark(c) || Letter(c))
end_define

begin_define
define|#
directive|define
name|Anytormark
parameter_list|(
name|c
parameter_list|)
value|(c=='+' || c=='-' || c=='*' || c=='/' || c=='#')
end_define

begin_define
define|#
directive|define
name|Montormark
parameter_list|(
name|c
parameter_list|)
value|(c=='~' || Anytormark(c))
end_define

begin_define
define|#
directive|define
name|Dyatormark
parameter_list|(
name|c
parameter_list|)
value|(Anytormark(c) || c=='^' || c=='<' || c=='>')
end_define

begin_comment
comment|/* Procedure upto(); */
end_comment

begin_comment
comment|/* Procedure need(); */
end_comment

begin_comment
comment|/* Procedure nothing(); */
end_comment

begin_comment
comment|/* Procedure thought(); */
end_comment

begin_comment
comment|/* Procedure findceol(); */
end_comment

begin_function_decl
name|bool
name|ateol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|findkw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|value
name|keyword
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure reqkw(); */
end_comment

begin_comment
comment|/* Procedure req(); */
end_comment

begin_function_decl
name|value
name|tag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|atkw
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|intlet
name|count
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|txptr
name|fcol
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|txptr
name|lcol
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|intlet
name|alino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|txptr
name|txstart
decl_stmt|,
name|txend
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*TEMPORARY if possible*/
end_comment

begin_comment
comment|/* Procedure getline(); */
end_comment

begin_function_decl
name|intlet
name|ilev
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Procedure veli(); */
end_comment

begin_comment
comment|/* Procedure inistreams(); */
end_comment

begin_comment
comment|/* Procedure re_streams(); */
end_comment

begin_comment
comment|/* Procedure open_stream(); */
end_comment

begin_comment
comment|/* Procedure close_stream(); */
end_comment

end_unit

