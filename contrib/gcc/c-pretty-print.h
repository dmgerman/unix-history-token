begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for the C and C++ pretty-printers.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_typedef
typedef|typedef
enum|enum
block|{
name|pp_c_flag_abstract
init|=
literal|1
operator|<<
literal|1
block|,
name|pp_c_flag_last_bit
init|=
literal|2
block|}
name|pp_c_pretty_print_flags
typedef|;
end_typedef

begin_comment
comment|/* The data type used to bundle information necessary for pretty-printing    a C or C++ entity.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|c_pretty_print_info
name|c_pretty_printer
typedef|;
end_typedef

begin_comment
comment|/* The type of a C pretty-printer 'member' function.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|c_pretty_print_fn
function_decl|)
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The datatype that contains information necessary for pretty-printing    a tree that represents a C construct.  Any pretty-printer for a    language using C/c++ syntax can derive from this datatype and reuse    facilities provided here.  It can do so by having a subobject of type    c_pretty_printer and override the macro pp_c_base to return a pointer    to that subobject.  Such a pretty-printer has the responsibility to    initialize the pp_base() part, then call pp_c_pretty_printer_init    to set up the components that are specific to the C pretty-printer.    A derived pretty-printer can override any function listed in the    vtable below.  See cp/cxx-pretty-print.h and cp/cxx-pretty-print.c    for an example of derivation.  */
end_comment

begin_struct
struct|struct
name|c_pretty_print_info
block|{
name|pretty_printer
name|base
decl_stmt|;
comment|/* Points to the first element of an array of offset-list.      Not used yet.  */
name|int
modifier|*
name|offset_list
decl_stmt|;
name|pp_flags
name|flags
decl_stmt|;
comment|/* These must be overridden by each of the C and C++ front-end to      reflect their understanding of syntactic productions when they differ.  */
name|c_pretty_print_fn
name|declaration
decl_stmt|;
name|c_pretty_print_fn
name|declaration_specifiers
decl_stmt|;
name|c_pretty_print_fn
name|declarator
decl_stmt|;
name|c_pretty_print_fn
name|abstract_declarator
decl_stmt|;
name|c_pretty_print_fn
name|direct_abstract_declarator
decl_stmt|;
name|c_pretty_print_fn
name|type_specifier_seq
decl_stmt|;
name|c_pretty_print_fn
name|direct_declarator
decl_stmt|;
name|c_pretty_print_fn
name|ptr_operator
decl_stmt|;
name|c_pretty_print_fn
name|parameter_list
decl_stmt|;
name|c_pretty_print_fn
name|type_id
decl_stmt|;
name|c_pretty_print_fn
name|simple_type_specifier
decl_stmt|;
name|c_pretty_print_fn
name|function_specifier
decl_stmt|;
name|c_pretty_print_fn
name|storage_class_specifier
decl_stmt|;
name|c_pretty_print_fn
name|initializer
decl_stmt|;
name|c_pretty_print_fn
name|statement
decl_stmt|;
name|c_pretty_print_fn
name|id_expression
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
name|multiplicative_expression
decl_stmt|;
name|c_pretty_print_fn
name|conditional_expression
decl_stmt|;
name|c_pretty_print_fn
name|assignment_expression
decl_stmt|;
name|c_pretty_print_fn
name|expression
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Override the pp_base macro.  Derived pretty-printers should not    touch this macro.  Instead they should override pp_c_base instead.  */
end_comment

begin_undef
undef|#
directive|undef
name|pp_base
end_undef

begin_define
define|#
directive|define
name|pp_base
parameter_list|(
name|PP
parameter_list|)
value|(&pp_c_base (PP)->base)
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
value|pp_c_base (PPI)->declaration (pp_c_base (PPI), T)
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
value|pp_c_base (PPI)->declaration_specifiers (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_abstract_declarator
parameter_list|(
name|PP
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PP)->abstract_declarator (pp_c_base (PP), D)
end_define

begin_define
define|#
directive|define
name|pp_type_specifier_seq
parameter_list|(
name|PPI
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PPI)->type_specifier_seq (pp_c_base (PPI), D)
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
value|pp_c_base (PPI)->declarator (pp_c_base (PPI), D)
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
value|pp_c_base (PPI)->direct_declarator (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_direct_abstract_declarator
parameter_list|(
name|PP
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PP)->direct_abstract_declarator (pp_c_base (PP), D)
end_define

begin_define
define|#
directive|define
name|pp_ptr_operator
parameter_list|(
name|PP
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PP)->ptr_operator (pp_c_base (PP), D)
end_define

begin_define
define|#
directive|define
name|pp_parameter_list
parameter_list|(
name|PPI
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_c_base (PPI)->parameter_list (pp_c_base (PPI), T)
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
value|pp_c_base (PPI)->type_id (pp_c_base (PPI), D)
end_define

begin_define
define|#
directive|define
name|pp_simple_type_specifier
parameter_list|(
name|PP
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_c_base (PP)->simple_type_specifier (pp_c_base (PP), T)
end_define

begin_define
define|#
directive|define
name|pp_function_specifier
parameter_list|(
name|PP
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PP)->function_specifier (pp_c_base (PP), D)
end_define

begin_define
define|#
directive|define
name|pp_storage_class_specifier
parameter_list|(
name|PP
parameter_list|,
name|D
parameter_list|)
define|\
value|pp_c_base (PP)->storage_class_specifier (pp_c_base (PP), D);
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
value|pp_c_base (PPI)->statement (pp_c_base (PPI), S)
end_define

begin_define
define|#
directive|define
name|pp_id_expression
parameter_list|(
name|PP
parameter_list|,
name|E
parameter_list|)
define|\
value|pp_c_base (PP)->id_expression (pp_c_base (PP), E)
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
value|pp_c_base (PPI)->primary_expression (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->postfix_expression (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->unary_expression (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->initializer (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->multiplicative_expression (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->conditional_expression (pp_c_base (PPI), E)
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
value|pp_c_base (PPI)->assignment_expression (pp_c_base (PPI), E)
end_define

begin_define
define|#
directive|define
name|pp_expression
parameter_list|(
name|PP
parameter_list|,
name|E
parameter_list|)
define|\
value|pp_c_base (PP)->expression (pp_c_base (PP), E)
end_define

begin_comment
comment|/* Returns the c_pretty_printer base object of PRETTY-PRINTER.  This    macro must be overridden by any subclass of c_pretty_print_info.  */
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

begin_function_decl
specifier|extern
name|void
name|pp_c_pretty_printer_init
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_whitespace
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_left_paren
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_right_paren
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_left_brace
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_right_brace
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_dot
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_ampersand
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_arrow
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_semicolon
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_space_for_pointer_operator
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Declarations.  */
end_comment

begin_function_decl
name|void
name|pp_c_function_definition
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_attributes
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_type_qualifier_list
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_parameter_type_list
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_declaration
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_declaration_specifiers
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_declarator
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_direct_declarator
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_specifier_qualifier_list
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_function_specifier
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_type_id
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_direct_abstract_declarator
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_type_specifier
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_storage_class_specifier
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Statements.  */
end_comment

begin_function_decl
name|void
name|pp_c_statement
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Expressions.  */
end_comment

begin_function_decl
name|void
name|pp_c_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_logical_or_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_expression_list
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_call_argument_list
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_unary_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_cast_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_postfix_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_primary_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_init_declarator
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_constant
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_id_expression
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_identifier
parameter_list|(
name|c_pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pp_c_string_literal
parameter_list|(
name|c_pretty_printer
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
comment|/* GCC_C_PRETTY_PRINTER */
end_comment

end_unit

