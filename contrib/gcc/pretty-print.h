begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for language-independent pretty-print subroutines.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PRETTY_PRINT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_PRETTY_PRINT_H
end_define

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_comment
comment|/* The type of pretty-printer flags passed to clients.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|pp_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|pp_none
block|,
name|pp_before
block|,
name|pp_after
block|}
name|pp_padding
typedef|;
end_typedef

begin_struct
struct|struct
name|pretty_print_info
block|{
comment|/* Where we print external representation of ENTITY.  */
name|output_buffer
modifier|*
name|buffer
decl_stmt|;
name|pp_flags
name|flags
decl_stmt|;
comment|/* Where to put whitespace around the entity being formatted.  */
name|pp_padding
name|padding
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pp_left_paren
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '(')
end_define

begin_define
define|#
directive|define
name|pp_right_paren
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), ')')
end_define

begin_define
define|#
directive|define
name|pp_left_bracket
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '[')
end_define

begin_define
define|#
directive|define
name|pp_right_bracket
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), ']')
end_define

begin_define
define|#
directive|define
name|pp_left_brace
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '{')
end_define

begin_define
define|#
directive|define
name|pp_right_brace
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '}')
end_define

begin_define
define|#
directive|define
name|pp_semicolon
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), ';')
end_define

begin_define
define|#
directive|define
name|pp_comma
parameter_list|(
name|PPI
parameter_list|)
value|output_add_string (pp_buffer (PPI), ", ")
end_define

begin_define
define|#
directive|define
name|pp_dot
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '.')
end_define

begin_define
define|#
directive|define
name|pp_colon
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), ':')
end_define

begin_define
define|#
directive|define
name|pp_colon_colon
parameter_list|(
name|PPI
parameter_list|)
value|output_add_string (pp_buffer (PPI), "::")
end_define

begin_define
define|#
directive|define
name|pp_arrow
parameter_list|(
name|PPI
parameter_list|)
value|output_add_string (pp_buffer (PPI), "->")
end_define

begin_define
define|#
directive|define
name|pp_equal
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '=')
end_define

begin_define
define|#
directive|define
name|pp_question
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '?')
end_define

begin_define
define|#
directive|define
name|pp_bar
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '|')
end_define

begin_define
define|#
directive|define
name|pp_carret
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '^')
end_define

begin_define
define|#
directive|define
name|pp_ampersand
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '&')
end_define

begin_define
define|#
directive|define
name|pp_less
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '<')
end_define

begin_define
define|#
directive|define
name|pp_greater
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '>')
end_define

begin_define
define|#
directive|define
name|pp_plus
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '+')
end_define

begin_define
define|#
directive|define
name|pp_minus
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '-')
end_define

begin_define
define|#
directive|define
name|pp_star
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '*')
end_define

begin_define
define|#
directive|define
name|pp_slash
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '/')
end_define

begin_define
define|#
directive|define
name|pp_modulo
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '%')
end_define

begin_define
define|#
directive|define
name|pp_exclamation
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '!')
end_define

begin_define
define|#
directive|define
name|pp_complement
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '~')
end_define

begin_define
define|#
directive|define
name|pp_quote
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '\'')
end_define

begin_define
define|#
directive|define
name|pp_backquote
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '`')
end_define

begin_define
define|#
directive|define
name|pp_doublequote
parameter_list|(
name|PPI
parameter_list|)
value|output_add_character (pp_buffer (PPI), '"')
end_define

begin_define
define|#
directive|define
name|pp_newline
parameter_list|(
name|PPI
parameter_list|)
value|output_add_newline (pp_buffer (PPI))
end_define

begin_define
define|#
directive|define
name|pp_character
parameter_list|(
name|PPI
parameter_list|,
name|C
parameter_list|)
value|output_add_character (pp_buffer (PPI), C)
end_define

begin_define
define|#
directive|define
name|pp_whitespace
parameter_list|(
name|PPI
parameter_list|)
value|output_add_space (pp_buffer (PPI))
end_define

begin_define
define|#
directive|define
name|pp_indentation
parameter_list|(
name|PPI
parameter_list|)
value|output_indentation (pp_buffer (PPI))
end_define

begin_define
define|#
directive|define
name|pp_newline_and_indent
parameter_list|(
name|PPI
parameter_list|,
name|N
parameter_list|)
define|\
value|do {                                \     pp_indentation (PPI) += N;        \     pp_newline (PPI);                 \   } while (0)
end_define

begin_define
define|#
directive|define
name|pp_separate_with
parameter_list|(
name|PPI
parameter_list|,
name|C
parameter_list|)
define|\
value|do {                          \      pp_character (PPI, C);      \      pp_whitespace (PPI);        \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_format_scalar
parameter_list|(
name|PPI
parameter_list|,
name|F
parameter_list|,
name|S
parameter_list|)
define|\
value|output_formatted_scalar (pp_buffer (PPI), F, S)
end_define

begin_define
define|#
directive|define
name|pp_wide_integer
parameter_list|(
name|PPI
parameter_list|,
name|I
parameter_list|)
define|\
value|pp_format_scalar (PPI, HOST_WIDE_INT_PRINT_DEC, (HOST_WIDE_INT) I)
end_define

begin_define
define|#
directive|define
name|pp_pointer
parameter_list|(
name|PPI
parameter_list|,
name|P
parameter_list|)
value|pp_format_scalar (PPI, "%p", p)
end_define

begin_define
define|#
directive|define
name|pp_identifier
parameter_list|(
name|PPI
parameter_list|,
name|ID
parameter_list|)
value|output_add_string (pp_buffer (PPI), ID)
end_define

begin_define
define|#
directive|define
name|pp_tree_identifier
parameter_list|(
name|PPI
parameter_list|,
name|T
parameter_list|)
value|pp_identifier(PPI, IDENTIFIER_POINTER (T))
end_define

begin_define
define|#
directive|define
name|pp_unsupported_tree
parameter_list|(
name|PPI
parameter_list|,
name|T
parameter_list|)
define|\
value|output_verbatim (pp_buffer(PPI), "#`%s' not supported by %s#",\                    tree_code_name[(int) TREE_CODE (T)], __FUNCTION__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_PRETTY_PRINT_H */
end_comment

end_unit

