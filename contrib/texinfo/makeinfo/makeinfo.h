begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* makeinfo.h -- Declarations for Makeinfo.    $Id: makeinfo.h,v 1.3 1997/07/15 18:28:38 karl Exp $     Copyright (C) 1996, 97 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_comment
comment|/* Why, oh why, did I ever listen to rms when he said:    "Don't make lots of small files, just make one big one!"  I've    regretted it ever since with this program, and with readline.    bfox@ai.mit.edu Thu Jul 11 07:54:32 1996 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAKEINFO_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAKEINFO_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPILING_MAKEINFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|,
name|init
parameter_list|)
value|type var = init
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DECLARE
parameter_list|(
name|type
parameter_list|,
name|var
parameter_list|,
name|init
parameter_list|)
value|extern type var
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|insertion_type
block|{
name|cartouche
block|,
name|defcv
block|,
name|deffn
block|,
name|defivar
block|,
name|defmac
block|,
name|defmethod
block|,
name|defop
block|,
name|defopt
block|,
name|defspec
block|,
name|deftp
block|,
name|deftypefn
block|,
name|deftypefun
block|,
name|deftypemethod
block|,
name|deftypevar
block|,
name|deftypevr
block|,
name|defun
block|,
name|defvar
block|,
name|defvr
block|,
name|detailmenu
block|,
name|direntry
block|,
name|display
block|,
name|enumerate
block|,
name|example
block|,
name|flushleft
block|,
name|flushright
block|,
name|format
block|,
name|ftable
block|,
name|group
block|,
name|ifclear
block|,
name|ifinfo
block|,
name|ifnothtml
block|,
name|ifnottex
block|,
name|ifset
block|,
name|itemize
block|,
name|lisp
block|,
name|menu
block|,
name|multitable
block|,
name|quotation
block|,
name|smallexample
block|,
name|smalllisp
block|,
name|table
block|,
name|vtable
block|,
name|bad_type
block|}
enum|;
end_enum

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|insertion_level
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPILING_MAKEINFO
argument_list|)
end_if

begin_decl_stmt
name|char
modifier|*
name|insertion_type_names
index|[]
init|=
block|{
literal|"cartouche"
block|,
literal|"defcv"
block|,
literal|"deffn"
block|,
literal|"defivar"
block|,
literal|"defmac"
block|,
literal|"defmethod"
block|,
literal|"defop"
block|,
literal|"defopt"
block|,
literal|"defspec"
block|,
literal|"deftp"
block|,
literal|"deftypefn"
block|,
literal|"deftypefun"
block|,
literal|"deftypemethod"
block|,
literal|"deftypevar"
block|,
literal|"deftypevr"
block|,
literal|"defun"
block|,
literal|"defvar"
block|,
literal|"defvr"
block|,
literal|"detailmenu"
block|,
literal|"direntry"
block|,
literal|"display"
block|,
literal|"enumerate"
block|,
literal|"example"
block|,
literal|"flushleft"
block|,
literal|"flushright"
block|,
literal|"format"
block|,
literal|"ftable"
block|,
literal|"group"
block|,
literal|"ifclear"
block|,
literal|"ifinfo"
block|,
literal|"ifnothtml"
block|,
literal|"ifnottex"
block|,
literal|"ifset"
block|,
literal|"itemize"
block|,
literal|"lisp"
block|,
literal|"menu"
block|,
literal|"multitable"
block|,
literal|"quotation"
block|,
literal|"smallexample"
block|,
literal|"smalllisp"
block|,
literal|"table"
block|,
literal|"vtable"
block|,
literal|"bad_type"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|istack_elt
block|{
name|struct
name|istack_elt
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|item_function
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|line_number
decl_stmt|;
name|int
name|filling_enabled
decl_stmt|;
name|int
name|indented_fill
decl_stmt|;
name|enum
name|insertion_type
name|insertion
decl_stmt|;
name|int
name|inhibited
decl_stmt|;
name|int
name|in_fixed_width_font
decl_stmt|;
block|}
name|INSERTION_ELT
typedef|;
end_typedef

begin_expr_stmt
name|DECLARE
argument_list|(
name|INSERTION_ELT
operator|*
argument_list|,
name|insertion_stack
argument_list|,
operator|(
name|INSERTION_ELT
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Current output stream. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|FILE
operator|*
argument_list|,
name|output_stream
argument_list|,
operator|(
name|FILE
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Output paragraph buffer. */
end_comment

begin_macro
name|DECLARE
argument_list|(
argument|unsigned char *
argument_list|,
argument|output_paragraph
argument_list|,
argument|(unsigned char *)NULL
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Offset into OUTPUT_PARAGRAPH. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_paragraph_offset
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The output paragraph "cursor" horizontal position. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|output_column
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Non-zero means output_paragraph contains text. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|paragraph_is_open
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The amount of indentation to apply at the start of each line. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|current_indent
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* nonzero if we are currently processing a multitable command */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|multitable_active
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The column at which long lines are broken. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|fill_column
argument_list|,
literal|72
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* The current input file state. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|input_filename
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|char
operator|*
argument_list|,
name|input_text
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|size_of_input_text
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|input_text_offset
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|line_number
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|curchar
parameter_list|()
value|input_text[input_text_offset]
end_define

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*                            Global Defines                        */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* Error levels */
end_comment

begin_define
define|#
directive|define
name|NO_ERROR
value|0
end_define

begin_define
define|#
directive|define
name|SYNTAX
value|2
end_define

begin_define
define|#
directive|define
name|FATAL
value|4
end_define

begin_comment
comment|/* C's standard macros don't check to make sure that the characters being    changed are within range.  So I have to check explicitly. */
end_comment

begin_comment
comment|/* GNU Library doesn't have toupper().  Until GNU gets this fixed, I will    have to do it. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|toupper
end_ifndef

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c) - 32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|coerce_to_upper
parameter_list|(
name|c
parameter_list|)
value|((islower(c) ? toupper(c) : (c)))
end_define

begin_define
define|#
directive|define
name|coerce_to_lower
parameter_list|(
name|c
parameter_list|)
value|((isupper(c) ? tolower(c) : (c)))
end_define

begin_define
define|#
directive|define
name|control_character_bit
value|0x40
end_define

begin_comment
comment|/* %01000000, must be off. */
end_comment

begin_define
define|#
directive|define
name|meta_character_bit
value|0x080
end_define

begin_comment
comment|/* %10000000, must be on.  */
end_comment

begin_define
define|#
directive|define
name|CTL
parameter_list|(
name|c
parameter_list|)
value|((c)& (~control_character_bit))
end_define

begin_define
define|#
directive|define
name|UNCTL
parameter_list|(
name|c
parameter_list|)
value|coerce_to_upper(((c)|control_character_bit))
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | (meta_character_bit))
end_define

begin_define
define|#
directive|define
name|UNMETA
parameter_list|(
name|c
parameter_list|)
value|((c)& (~meta_character_bit))
end_define

begin_define
define|#
directive|define
name|whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == '\t') || ((c) == ' '))
end_define

begin_define
define|#
directive|define
name|sentence_ender
parameter_list|(
name|c
parameter_list|)
value|((c) == '.' || (c) == '?' || (c) == '!')
end_define

begin_define
define|#
directive|define
name|cr_or_whitespace
parameter_list|(
name|c
parameter_list|)
value|(((c) == '\t') || ((c) == ' ') || ((c) == '\n'))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|isletter
end_ifndef

begin_define
define|#
directive|define
name|isletter
parameter_list|(
name|c
parameter_list|)
value|(((c)>= 'A'&& (c)<= 'Z') || ((c)>= 'a'&& (c)<= 'z'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isupper
end_ifndef

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|isdigit
end_ifndef

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|digit_value
end_ifndef

begin_define
define|#
directive|define
name|digit_value
parameter_list|(
name|c
parameter_list|)
value|((c) - '0')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|member
parameter_list|(
name|c
parameter_list|,
name|s
parameter_list|)
value|(strchr (s, c) != NULL)
end_define

begin_define
define|#
directive|define
name|COMMAND_PREFIX
value|'@'
end_define

begin_comment
comment|/* Stuff for splitting large files. */
end_comment

begin_define
define|#
directive|define
name|SPLIT_SIZE_THRESHOLD
value|70000
end_define

begin_comment
comment|/* What's good enough for Stallman... */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SPLIT_SIZE
value|50000
end_define

begin_comment
comment|/* Is probably good enough for me. */
end_comment

begin_expr_stmt
name|DECLARE
argument_list|(
name|int
argument_list|,
name|splitting
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Defaults to true for now. */
end_comment

begin_typedef
typedef|typedef
name|void
name|COMMAND_FUNCTION
parameter_list|()
function_decl|;
end_typedef

begin_comment
comment|/* So I can say COMMAND_FUNCTION *foo; */
end_comment

begin_define
define|#
directive|define
name|command_char
parameter_list|(
name|c
parameter_list|)
value|((!whitespace(c))&& \                          ((c) != '\n')&& \                          ((c) != '{')&& \                          ((c) != '}')&& \                          ((c) != '='))
end_define

begin_define
define|#
directive|define
name|skip_whitespace
parameter_list|()
define|\
value|while ((input_text_offset != size_of_input_text)&& \              whitespace (curchar())) \        input_text_offset++
end_define

begin_define
define|#
directive|define
name|skip_whitespace_and_newlines
parameter_list|()
define|\
value|do { \    while ((input_text_offset != size_of_input_text)&& \           (whitespace (curchar ()) || (curchar () == '\n'))) \       { \          if (curchar () == '\n') \            line_number++; \          input_text_offset++; \       } \    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MAKEINFO_H */
end_comment

end_unit

