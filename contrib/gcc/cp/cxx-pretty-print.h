begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface for the GNU C++ pretty-printer.    Copyright (C) 2003 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Ask for an qualified-id.  */
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
name|pp_cxx_function_definition
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

begin_function_decl
name|void
name|pp_cxx_statement
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

