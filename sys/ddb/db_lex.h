begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *  * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DDB_DB_LEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_DDB_DB_LEX_H_
end_define

begin_comment
comment|/*  *	Author: David B. Golub, Carnegie Mellon University  *	Date:	7/90  */
end_comment

begin_comment
comment|/*  * Lexical analyzer.  */
end_comment

begin_function_decl
name|void
name|db_flush_lex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_read_line
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|db_read_token
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|db_unread_token
parameter_list|(
name|int
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|db_expr_t
name|db_tok_number
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TOK_STRING_SIZE
value|120
end_define

begin_decl_stmt
specifier|extern
name|char
name|db_tok_string
index|[
name|TOK_STRING_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tEOF
value|(-1)
end_define

begin_define
define|#
directive|define
name|tEOL
value|1
end_define

begin_define
define|#
directive|define
name|tNUMBER
value|2
end_define

begin_define
define|#
directive|define
name|tIDENT
value|3
end_define

begin_define
define|#
directive|define
name|tPLUS
value|4
end_define

begin_define
define|#
directive|define
name|tMINUS
value|5
end_define

begin_define
define|#
directive|define
name|tDOT
value|6
end_define

begin_define
define|#
directive|define
name|tSTAR
value|7
end_define

begin_define
define|#
directive|define
name|tSLASH
value|8
end_define

begin_define
define|#
directive|define
name|tEQ
value|9
end_define

begin_define
define|#
directive|define
name|tLPAREN
value|10
end_define

begin_define
define|#
directive|define
name|tRPAREN
value|11
end_define

begin_define
define|#
directive|define
name|tPCT
value|12
end_define

begin_define
define|#
directive|define
name|tHASH
value|13
end_define

begin_define
define|#
directive|define
name|tCOMMA
value|14
end_define

begin_define
define|#
directive|define
name|tDITTO
value|15
end_define

begin_define
define|#
directive|define
name|tDOLLAR
value|16
end_define

begin_define
define|#
directive|define
name|tEXCL
value|17
end_define

begin_define
define|#
directive|define
name|tSHIFT_L
value|18
end_define

begin_define
define|#
directive|define
name|tSHIFT_R
value|19
end_define

begin_define
define|#
directive|define
name|tDOTDOT
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DDB_DB_LEX_H_ */
end_comment

end_unit

