begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data definitions for internal representation of bison's input,    Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.  This file is part of Bison, the GNU Compiler Compiler.  Bison is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  Bison is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with Bison; see the file COPYING.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* representation of the grammar rules:  ntokens is the number of tokens, and nvars is the number of variables (nonterminals).  nsyms is the total number, ntokens + nvars.  	(the true number of token values assigned is ntokens 	reduced by one for each alias declaration)  Each symbol (either token or variable) receives a symbol number. Numbers 0 to ntokens-1 are for tokens, and ntokens to nsyms-1 are for variables.  Symbol number zero is the end-of-input token.  This token is counted in ntokens.  The rules receive rule numbers 1 to nrules in the order they are written. Actions and guards are accessed via the rule number.  The rules themselves are described by three arrays: rrhs, rlhs and ritem.  rlhs[R] is the symbol number of the left hand side of rule R. The right hand side is stored as symbol numbers in a portion of ritem.  rrhs[R] contains the index in ritem of the beginning of the portion for rule R.  If rlhs[R] is -1, the rule has been thrown out by reduce.c and should be ignored.  The length of the portion is one greater  than the number of symbols in the rule's right hand side. The last element in the portion contains minus R, which identifies it as the end of a portion and says which rule it is for.  The portions of ritem come in order of increasing rule number and are followed by an element which is zero to mark the end.  nitems is the total length of ritem, not counting the final zero.  Each element of ritem is called an "item" and its index in ritem is an item number.  Item numbers are used in the finite state machine to represent places that parsing can get to.  Precedence levels are recorded in the vectors sprec and rprec. sprec records the precedence level of each symbol, rprec the precedence level of each rule. rprecsym is the symbol-number of the symbol in %prec for this rule (if any).  Precedence levels are assigned in increasing order starting with 1 so that numerically higher precedence values mean tighter binding as they ought to.  Zero as a symbol or rule's precedence means none is assigned.  Associativities are recorded similarly in rassoc and sassoc.  */
end_comment

begin_define
define|#
directive|define
name|ISTOKEN
parameter_list|(
name|s
parameter_list|)
value|((s)< ntokens)
end_define

begin_define
define|#
directive|define
name|ISVAR
parameter_list|(
name|s
parameter_list|)
value|((s)>= ntokens)
end_define

begin_decl_stmt
specifier|extern
name|int
name|nitems
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nrules
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nsyms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ntokens
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nvars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|ritem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rlhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rrhs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rprecsym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|sprec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|sassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|rline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Source line number of each rule */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|start_symbol
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* associativity values in elements of rassoc, sassoc.  */
end_comment

begin_define
define|#
directive|define
name|RIGHT_ASSOC
value|1
end_define

begin_define
define|#
directive|define
name|LEFT_ASSOC
value|2
end_define

begin_define
define|#
directive|define
name|NON_ASSOC
value|3
end_define

begin_comment
comment|/* token translation table: indexed by a token number as returned by the user's yylex routine, it yields the internal token number used by the parser and throughout bison. If translations is zero, the translation table is not used because the two kinds of token numbers are the same.   (It is noted in reader.c that "Nowadays translations is always set to 1...") */
end_comment

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|token_translations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|translations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_user_token_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* semantic_parser is nonzero if the input file says to use the hairy parser that provides for semantic error recovery.  If it is zero, the yacc-compatible simplified parser is used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|semantic_parser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pure_parser is nonzero if should generate a parser that is all pure and reentrant. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pure_parser
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error_token_number is the token number of the error token.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|error_token_number
decl_stmt|;
end_decl_stmt

end_unit

