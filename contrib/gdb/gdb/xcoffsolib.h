begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Data structures for RS/6000 shared libraries, for GDB.    Copyright 1991, 1992, 1994, 1997 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* The vmap struct is used to describe the virtual address space of    the target we are manipulating.  The first entry is always the "exec"    file.  Subsequent entries correspond to other objects that are    mapped into the address space of a process created from the "exec" file.    These are either in response to exec()ing the file, in which case all    shared libraries are loaded, or a "load" system call, followed by the    user's issuance of a "load" command.  */
end_comment

begin_struct
struct|struct
name|vmap
block|{
name|struct
name|vmap
modifier|*
name|nxt
decl_stmt|;
comment|/* ptr to next in chain			*/
name|bfd
modifier|*
name|bfd
decl_stmt|;
comment|/* BFD for mappable object library	*/
name|char
modifier|*
name|name
decl_stmt|;
comment|/* ptr to object file name		*/
name|char
modifier|*
name|member
decl_stmt|;
comment|/* ptr to member name			*/
name|CORE_ADDR
name|tstart
decl_stmt|;
comment|/* virtual addr where member is mapped	*/
name|CORE_ADDR
name|tend
decl_stmt|;
comment|/* virtual upper bound of member	*/
name|CORE_ADDR
name|tvma
decl_stmt|;
comment|/* virtual addr of text section in object file */
name|CORE_ADDR
name|toffs
decl_stmt|;
comment|/* offset of text section in object file */
name|CORE_ADDR
name|dstart
decl_stmt|;
comment|/* virtual address of data start	*/
name|CORE_ADDR
name|dend
decl_stmt|;
comment|/* virtual address of data end		*/
name|CORE_ADDR
name|dvma
decl_stmt|;
comment|/* virtual addr of data section in object file */
comment|/* This is NULL for the exec-file.  */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
name|unsigned
name|loaded
range|:
literal|1
decl_stmt|;
comment|/* True if symbols are loaded		*/
name|unsigned
name|padding
range|:
literal|15
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmap_and_bfd
block|{
name|bfd
modifier|*
name|pbfd
decl_stmt|;
name|struct
name|vmap
modifier|*
name|pvmap
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|vmap
modifier|*
name|vmap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hook for symbol table relocation at runtime. */
end_comment

begin_extern
extern|extern void (*xcoff_relocate_symtab_hook
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

