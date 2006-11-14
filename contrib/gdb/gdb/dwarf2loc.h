begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Dwarf2 location expression support for GDB.    Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2LOC_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2LOC_H
end_define

begin_struct_decl
struct_decl|struct
name|symbol_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* This header is private to the DWARF-2 reader.  It is shared between    dwarf2read.c and dwarf2loc.c.  */
end_comment

begin_comment
comment|/* The symbol location baton types used by the DWARF-2 reader (i.e.    SYMBOL_LOCATION_BATON for a LOC_COMPUTED symbol).  "struct    dwarf2_locexpr_baton" is for a symbol with a single location    expression; "struct dwarf2_loclist_baton" is for a symbol with a    location list.  */
end_comment

begin_struct
struct|struct
name|dwarf2_locexpr_baton
block|{
comment|/* Pointer to the start of the location expression.  */
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Length of the location expression.  */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* The objfile containing the symbol whose location we're computing.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dwarf2_loclist_baton
block|{
comment|/* The initial base address for the location list, based on the compilation      unit.  */
name|CORE_ADDR
name|base_address
decl_stmt|;
comment|/* Pointer to the start of the location list.  */
name|unsigned
name|char
modifier|*
name|data
decl_stmt|;
comment|/* Length of the location list.  */
name|unsigned
name|short
name|size
decl_stmt|;
comment|/* The objfile containing the symbol whose location we're computing.  */
comment|/* Used (only???) by thread local variables.  The objfile in which      this symbol is defined.  To find a thread-local variable (e.g., a      variable declared with the `__thread' storage class), we may need      to know which object file it's in.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|symbol_ops
name|dwarf2_locexpr_funcs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|symbol_ops
name|dwarf2_loclist_funcs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

