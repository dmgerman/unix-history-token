begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for the C and C++ pretty-printers.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_PRETTY_PRINTER
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_PRETTY_PRINTER
end_define

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"c-common.h"
end_include

begin_include
include|#
directive|include
file|"pretty-print.h"
end_include

begin_comment
comment|/* The data type used to bundle information necessary for pretty-printing    a C or C++ entity.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|c_pretty_print_info
modifier|*
name|c_pretty_printer
typedef|;
end_typedef

begin_comment
comment|/* The type of a C pretty-printer 'member' function.  */
end_comment

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*c_pretty_print_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|c_pretty_print_info
block|{
name|struct
name|pretty_print_info
name|base
decl_stmt|;
comment|/* Points to the first element of an array of offset-list.      Not used yet.  */
name|int
modifier|*
name|offset_list
decl_stmt|;
comment|/* These must be overriden by each of the C and C++ front-end to      reflect their understanding of syntatic productions when they differ.  */
name|c_pretty_print_fn
name|declaration
decl_stmt|;
name|c_pretty_print_fn
name|declaration_specifiers
decl_stmt|;
name|c_pretty_print_fn
name|type_specifier
decl_stmt|;
name|c_pretty_print_fn
name|declarator
decl_stmt|;
name|c_pretty_print_fn
name|direct_declarator
decl_stmt|;
name|c_pretty_print_fn
name|parameter_declaration
decl_stmt|;
name|c_pretty_print_fn
name|type_id
decl_stmt|;
name|c_pretty_print_fn
name|statement
decl_stmt|;
name|c_pretty_print_fn
name|primary_expression
decl_stmt|;
name|c_pretty_print_fn
name|postfix_expression
decl_stmt|;
name|c_pretty_print_fn
name|unary_expression
decl_stmt|;
name|c_pretty_print_fn
name|initializer
decl_stmt|;
name|c_pretty_print_fn
name|multiplicative_expression
decl_stmt|;
name|c_pretty_print_fn
name|conditional_expression
decl_stmt|;
name|c_pretty_print_fn
name|assignment_expression
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pp_c_left_paren
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      pp_left_paren (PPI);                          \      pp_c_base (PPI)->base.padding = pp_none;      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_right_paren
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      pp_right_paren (PPI);                         \      pp_c_base (PPI)->base.padding = pp_none;      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_left_bracket
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      pp_left_bracket (PPI);                        \      pp_c_base (PPI)->base.padding = pp_none;      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_right_bracket
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      pp_right_bracket (PPI);                       \      pp_c_base (PPI)->base.padding = pp_none;      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_whitespace
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      pp_whitespace (PPI);                          \      pp_c_base (PPI)->base.padding = pp_none;      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_maybe_whitespace
parameter_list|(
name|PPI
parameter_list|)
define|\
value|do {                                            \      if (pp_c_base (PPI)->base.padding != pp_none) \        pp_c_whitespace (PPI);                      \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_identifier
parameter_list|(
name|PPI
parameter_list|,
name|ID
parameter_list|)
define|\
value|do {                                            \      pp_c_maybe_whitespace (PPI);                  \      pp_identifier (PPI, ID);                      \      pp_c_base (PPI)->base.padding = pp_before;    \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_c_tree_identifier
parameter_list|(
name|PPI
parameter_list|,
name|ID
parameter_list|)
define|\
value|pp_c_identifier (PPI, IDENTIFIER_POINTER (ID))
end_define

begin_comment
comment|/* Returns the 'output_buffer *' associated with a PRETTY-PRINTER, the latter    being something digestible by pp_c_base.  */
end_comment

begin_define
define|#
directive|define
name|pp_buffer
parameter_list|(
name|PPI
parameter_list|)
value|pp_c_base (PPI)->base.buffer
end_define

begin_define
define|#
directive|define
name|pp_declaration
parameter_list|(
name|PPI
parameter_list|,
name|T
parameter_list|)
define|\
value|(*pp_c_base (PPI)->declaration) (pp_c_base (PPI), T)
end_define

begin_define
define|#
directive|define
name|pp_declaration_specifiers
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|(*pp_c_base (PPI)->declaration_specifiers) (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_type_specifier
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|(*pp_c_base (PPI)->type_specifier) (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_declarator
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|(*pp_c_base (PPI)->declarator) (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_direct_declarator
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|(*pp_c_base (PPI)->direct_declarator) (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_parameter_declaration
parameter_list|(
name|PPI
parameter_list|,
name|T
parameter_list|)
define|\
value|(*pp_c_base (PPI)->parameter_declaration) (pp_c_base (PPI), T)
end_define

begin_define
define|#
directive|define
name|pp_type_id
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|(*pp_c_base (PPI)->type_id) (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_statement
parameter_list|(
name|PPI
parameter_list|,
name|S
parameter_list|)
define|\
value|(*pp_c_base (PPI)->statement) (pp_c_base (PPI), S)
end_define

begin_define
define|#
directive|define
name|pp_primary_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->primary_expression) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_postfix_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->postfix_expression) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_unary_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->unary_expression) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_initializer
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->initializer) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_multiplicative_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->multiplicative_expression) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_conditional_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->conditional_expression) (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_assignment_expression
parameter_list|(
name|PPI
parameter_list|,
name|E
parameter_list|)
define|\
value|(*pp_c_base (PPI)->assignment_expression) (pp_c_base (PPI), E)
end_define

begin_comment
comment|/* Returns the c_pretty_printer base object of PRETTY-PRINTER.  This    macro must be overriden by any subclass of c_pretty_print_info.  */
end_comment

begin_define
define|#
directive|define
name|pp_c_base
parameter_list|(
name|PP
parameter_list|)
value|(PP)
end_define

begin_decl_stmt
specifier|extern
name|void
name|pp_c_pretty_printer_init
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declarations.  */
end_comment

begin_decl_stmt
name|void
name|pp_c_attributes
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_cv_qualifier
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_parameter_declaration_clause
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_declaration
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Statements.  */
end_comment

begin_decl_stmt
name|void
name|pp_c_statement
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Expressions.  */
end_comment

begin_decl_stmt
name|void
name|pp_c_expression
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_logical_or_expression
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_expression_list
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_cast_expression
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_postfix_expression
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_initializer
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pp_c_literal
name|PARAMS
argument_list|(
operator|(
name|c_pretty_printer
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_PRETTY_PRINTER */
end_comment

end_unit

