begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Helper routines for C++ support in GDB.    Copyright 2002, 2003, 2004 Free Software Foundation, Inc.     Contributed by MontaVista Software.    Namespace support contributed by David Carlton.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CP_SUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|CP_SUPPORT_H
end_define

begin_comment
comment|/* We need this for 'domain_enum', alas...  */
end_comment

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_comment
comment|/* Opaque declarations.  */
end_comment

begin_struct_decl
struct_decl|struct
name|symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|obstack
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_comment
comment|/* This struct is designed to store data from using directives.  It    says that names from namespace INNER should be visible within    namespace OUTER.  OUTER should always be a strict initial substring    of INNER.  These form a linked list; NEXT is the next element of    the list.  */
end_comment

begin_struct
struct|struct
name|using_direct
block|{
name|char
modifier|*
name|inner
decl_stmt|;
name|char
modifier|*
name|outer
decl_stmt|;
name|struct
name|using_direct
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Functions from cp-support.c.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|class_name_from_physname
parameter_list|(
specifier|const
name|char
modifier|*
name|physname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|method_name_from_physname
parameter_list|(
specifier|const
name|char
modifier|*
name|physname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|cp_find_first_component
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|cp_entire_prefix_len
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|cp_func_name
parameter_list|(
specifier|const
name|char
modifier|*
name|full_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
modifier|*
name|make_symbol_overload_list
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|cp_lookup_rtti_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions/variables from cp-namespace.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|processing_has_namespace_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|processing_current_prefix
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|cp_is_anonymous
parameter_list|(
specifier|const
name|char
modifier|*
name|namespace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_add_using_directive
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|outer_length
parameter_list|,
name|unsigned
name|int
name|inner_length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_initialize_namespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_finalize_namespace
parameter_list|(
name|struct
name|block
modifier|*
name|static_block
parameter_list|,
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_set_block_scope
parameter_list|(
specifier|const
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|,
name|struct
name|block
modifier|*
name|block
parameter_list|,
name|struct
name|obstack
modifier|*
name|obstack
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_scan_for_anonymous_namespaces
parameter_list|(
specifier|const
name|struct
name|symbol
modifier|*
name|symbol
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|cp_lookup_symbol_nonlocal
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|,
specifier|const
name|domain_enum
name|domain
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|symtab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|cp_lookup_symbol_namespace
parameter_list|(
specifier|const
name|char
modifier|*
name|namespace
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|linkage_name
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|,
specifier|const
name|domain_enum
name|domain
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
name|symtab
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|cp_lookup_nested_type
parameter_list|(
name|struct
name|type
modifier|*
name|parent_type
parameter_list|,
specifier|const
name|char
modifier|*
name|nested_name
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
name|block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cp_check_possible_namespace_symbols
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type
modifier|*
name|cp_lookup_transparent_type
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The list of "maint cplus" commands.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cmd_list_element
modifier|*
name|maint_cplus_cmd_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CP_SUPPORT_H */
end_comment

end_unit

