begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables and structures for declaration processing.    Copyright (C) 1993, 2000, 2002, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* In grokdeclarator, distinguish syntactic contexts of declarators.  */
end_comment

begin_enum
enum|enum
name|decl_context
block|{
name|NORMAL
block|,
comment|/* Ordinary declaration */
name|FUNCDEF
block|,
comment|/* Function definition */
name|PARM
block|,
comment|/* Declaration of parm before function body */
name|CATCHPARM
block|,
comment|/* Declaration of catch parm */
name|FIELD
block|,
comment|/* Declaration inside struct or union */
name|BITFIELD
block|,
comment|/* Likewise but with specified width */
name|TYPENAME
block|,
comment|/* Typename (inside cast or sizeof)  */
comment|/* APPLE LOCAL blocks 6339747 */
name|BLOCKDEF
block|,
comment|/* Declaratin of block literal */
name|MEMFUNCDEF
comment|/* Member function definition */
block|}
enum|;
end_enum

begin_comment
comment|/* We need this in here to get the decl_context definition.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|grokdeclarator
parameter_list|(
specifier|const
name|cp_declarator
modifier|*
parameter_list|,
specifier|const
name|cp_decl_specifier_seq
modifier|*
parameter_list|,
name|enum
name|decl_context
parameter_list|,
name|int
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL radar 4721858 */
end_comment

begin_function_decl
specifier|extern
name|void
name|emit_instantiate_pending_templates
parameter_list|(
name|location_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* APPLE LOCAL blocks 6040305 (ce) */
end_comment

begin_function_decl
specifier|extern
name|tree
name|grokparms
parameter_list|(
name|cp_parameter_declarator
modifier|*
name|first_parm
parameter_list|,
name|tree
modifier|*
name|parms
parameter_list|)
function_decl|;
end_function_decl

end_unit

