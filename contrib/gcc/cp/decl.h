begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables and structures for declaration processing.    Copyright (C) 1993, 2000, 2002 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|tree
parameter_list|,
name|tree
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

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_CP_BINDING_LEVELS
end_ifdef

begin_comment
comment|/* Purely for debugging purposes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug_bindings_indentation
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

