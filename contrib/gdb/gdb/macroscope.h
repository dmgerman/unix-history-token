begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface to functions for deciding which macros are currently in scope.    Copyright 2002 Free Software Foundation, Inc.    Contributed by Red Hat, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACROSCOPE_H
end_ifndef

begin_define
define|#
directive|define
name|MACROSCOPE_H
end_define

begin_include
include|#
directive|include
file|"macrotab.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_comment
comment|/* All the information we need to decide which macro definitions are    in scope: a source file (either a main source file or an    #inclusion), and a line number in that file.  */
end_comment

begin_struct
struct|struct
name|macro_scope
block|{
name|struct
name|macro_source_file
modifier|*
name|file
decl_stmt|;
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Return a `struct macro_scope' object corresponding to the symtab    and line given in SAL.  If we have no macro information for that    location, or if SAL's pc is zero, return zero.  */
end_comment

begin_function_decl
name|struct
name|macro_scope
modifier|*
name|sal_macro_scope
parameter_list|(
name|struct
name|symtab_and_line
name|sal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a `struct macro_scope' object describing the scope the `macro    expand' and `macro expand-once' commands should use for looking up    macros.  If we have a selected frame, this is the source location of    its PC; otherwise, this is the last listing position.     If we have no macro information for the current location, return zero.     The object returned is allocated using xmalloc; the caller is    responsible for freeing it.  */
end_comment

begin_function_decl
name|struct
name|macro_scope
modifier|*
name|default_macro_scope
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Look up the definition of the macro named NAME in scope at the source    location given by BATON, which must be a pointer to a `struct    macro_scope' structure.  This function is suitable for use as    a macro_lookup_ftype function.  */
end_comment

begin_function_decl
name|struct
name|macro_definition
modifier|*
name|standard_macro_lookup
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MACROSCOPE_H */
end_comment

end_unit

