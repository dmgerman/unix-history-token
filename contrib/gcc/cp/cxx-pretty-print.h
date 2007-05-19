begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for the GNU C++ pretty-printer.    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CXX_PRETTY_PRINT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CXX_PRETTY_PRINT_H
end_define

begin_include
include|#
directive|include
file|"c-pretty-print.h"
end_include

begin_undef
undef|#
directive|undef
name|pp_c_base
end_undef

begin_define
define|#
directive|define
name|pp_c_base
parameter_list|(
name|PP
parameter_list|)
value|(&(PP)->c_base)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Ask for a qualified-id.  */
name|pp_cxx_flag_default_argument
init|=
literal|1
operator|<<
name|pp_c_flag_last_bit
block|}
name|cxx_pretty_printer_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|c_pretty_printer
name|c_base
decl_stmt|;
comment|/* This is the enclosing scope of the entity being pretty-printed.  */
name|tree
name|enclosing_scope
decl_stmt|;
block|}
name|cxx_pretty_printer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pp_cxx_cv_qualifier_seq
parameter_list|(
name|PP
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_c_type_qualifier_list (pp_c_base (PP), T)
end_define

begin_define
define|#
directive|define
name|pp_cxx_whitespace
parameter_list|(
name|PP
parameter_list|)
value|pp_c_whitespace (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_left_paren
parameter_list|(
name|PP
parameter_list|)
value|pp_c_left_paren (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_right_paren
parameter_list|(
name|PP
parameter_list|)
value|pp_c_right_paren (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_left_brace
parameter_list|(
name|PP
parameter_list|)
value|pp_c_left_brace (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_right_brace
parameter_list|(
name|PP
parameter_list|)
value|pp_c_right_brace (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_left_bracket
parameter_list|(
name|PP
parameter_list|)
value|pp_c_left_bracket (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_right_bracket
parameter_list|(
name|PP
parameter_list|)
value|pp_c_right_bracket (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_dot
parameter_list|(
name|PP
parameter_list|)
value|pp_c_dot (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_ampersand
parameter_list|(
name|PP
parameter_list|)
value|pp_c_ampersand (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_star
parameter_list|(
name|PP
parameter_list|)
value|pp_c_star (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_arrow
parameter_list|(
name|PP
parameter_list|)
value|pp_c_arrow (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_semicolon
parameter_list|(
name|PP
parameter_list|)
value|pp_c_semicolon (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_complement
parameter_list|(
name|PP
parameter_list|)
value|pp_c_complement (pp_c_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_cxx_identifier
parameter_list|(
name|PP
parameter_list|,
name|I
parameter_list|)
value|pp_c_identifier (pp_c_base (PP), I)
end_define

begin_define
define|#
directive|define
name|pp_cxx_tree_identifier
parameter_list|(
name|PP
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_c_tree_identifier (pp_c_base (PP), T)
end_define

begin_function_decl
name|void
name|pp_cxx_pretty_printer_init
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_begin_template_argument_list
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_end_template_argument_list
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_colon_colon
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_separate_with
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_declaration
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_cxx_canonical_template_parameter
parameter_list|(
name|cxx_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CXX_PRETTY_PRINT_H */
end_comment

end_unit

