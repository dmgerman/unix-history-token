begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Variables and structures for declaration processing.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* C++: Keep these around to reduce calls to `get_identifier'.    Identifiers for `this' in member functions and the auto-delete    parameter for destructors.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|this_identifier
decl_stmt|,
name|in_charge_identifier
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Parsing a function declarator leaves a list of parameter names    or a chain or parameter decls here.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|last_function_parms
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of static class variables.  This is needed, because a    static class variable can be declared inside the class without    an initializer, and then initialized, staticly, outside the class.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|pending_statics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of objects which have constructors or destructors    which reside in the global scope.  The decl is stored in    the TREE_VALUE slot and the initializer is stored    in the TREE_PURPOSE slot.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|static_aggregates
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A list of functions which were declared inline, but later had their    address taken.  Used only for non-virtual member functions, since we can    find other functions easily enough.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|pending_addressable_inlines
decl_stmt|;
end_decl_stmt

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

