begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations having to do with GNU Emacs syntax tables.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Qsyntax_table_p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Fsyntax_table_p
argument_list|()
decl_stmt|,
name|Fsyntax_table
argument_list|()
decl_stmt|,
name|Fset_syntax_table
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Lisp_Object
name|Vstandard_syntax_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A syntax table is a Lisp vector of length 0400, whose elements are integers.  The low 8 bits of the integer is a code, as follows: */
end_comment

begin_enum
enum|enum
name|syntaxcode
block|{
name|Swhitespace
block|,
comment|/* for a whitespace character */
name|Spunct
block|,
comment|/* for random punctuation characters */
name|Sword
block|,
comment|/* for a word constituent */
name|Ssymbol
block|,
comment|/* symbol constituent but not word constituent */
name|Sopen
block|,
comment|/* for a beginning delimiter */
name|Sclose
block|,
comment|/* for an ending delimiter */
name|Squote
block|,
comment|/* for a prefix character like Lisp ' */
name|Sstring
block|,
comment|/* for a string-grouping character like Lisp " */
name|Smath
block|,
comment|/* for delimiters like $ in Tex. */
name|Sescape
block|,
comment|/* for a character that begins a C-style escape */
name|Scharquote
block|,
comment|/* for a character that quotes the following character */
name|Scomment
block|,
comment|/* for a comment-starting character */
name|Sendcomment
block|,
comment|/* for a comment-ending character */
name|Smax
comment|/* Upper bound on codes that are meaningful */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|SYNTAX
parameter_list|(
name|c
parameter_list|)
define|\
value|((enum syntaxcode) (XINT (bf_cur->syntax_table_v->contents[c])& 0377))
end_define

begin_comment
comment|/* The next 8 bits of the number is a character,  the matching delimiter in the case of Sopen or Sclose. */
end_comment

begin_define
define|#
directive|define
name|SYNTAX_MATCH
parameter_list|(
name|c
parameter_list|)
define|\
value|((XINT (bf_cur->syntax_table_v->contents[c])>> 8)& 0377)
end_define

begin_comment
comment|/* Then there are four single-bit flags that have the following meanings:   1. This character is the first of a two-character comment-start sequence.   2. This character is the second of a two-character comment-start sequence.   3. This character is the first of a two-character comment-end sequence.   4. This character is the second of a two-character comment-end sequence.  Note that any two-character sequence whose first character has flag 1   and whose second character has flag 2 will be interpreted as a comment start. */
end_comment

begin_define
define|#
directive|define
name|SYNTAX_COMSTART_FIRST
parameter_list|(
name|c
parameter_list|)
define|\
value|((XINT (bf_cur->syntax_table_v->contents[c])>> 16)& 1)
end_define

begin_define
define|#
directive|define
name|SYNTAX_COMSTART_SECOND
parameter_list|(
name|c
parameter_list|)
define|\
value|((XINT (bf_cur->syntax_table_v->contents[c])>> 17)& 1)
end_define

begin_define
define|#
directive|define
name|SYNTAX_COMEND_FIRST
parameter_list|(
name|c
parameter_list|)
define|\
value|((XINT (bf_cur->syntax_table_v->contents[c])>> 18)& 1)
end_define

begin_define
define|#
directive|define
name|SYNTAX_COMEND_SECOND
parameter_list|(
name|c
parameter_list|)
define|\
value|((XINT (bf_cur->syntax_table_v->contents[c])>> 19)& 1)
end_define

begin_comment
comment|/* This array, indexed by a character, contains the syntax code which that  character signifies (as a char).  For example,  (enum syntaxcode) syntax_spec_code['w'] is Sword. */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|syntax_spec_code
index|[
literal|0400
index|]
decl_stmt|;
end_decl_stmt

end_unit

