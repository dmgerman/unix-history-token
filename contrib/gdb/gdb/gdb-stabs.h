begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for symbol-reading containing "stabs", for GDB.    Copyright 1992 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by John Gilmore.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file exists to hold the common definitions required of most of    the symbol-readers that end up using stabs.  The common use of    these `symbol-type-specific' customizations of the generic data    structures makes the stabs-oriented symbol readers able to call    each others' functions as required.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDBSTABS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|GDBSTABS_H
end_define

begin_comment
comment|/* Offsets in the psymtab's section_offsets array for various kinds of    stabs symbols.  Every psymtab built from stabs will have these offsets    filled in by these guidelines, so that when actually reading symbols, the    proper offset can simply be selected and added to the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|SECT_OFF_TEXT
value|0
end_define

begin_define
define|#
directive|define
name|SECT_OFF_DATA
value|1
end_define

begin_define
define|#
directive|define
name|SECT_OFF_BSS
value|2
end_define

begin_define
define|#
directive|define
name|SECT_OFF_RODATA
value|3
end_define

begin_define
define|#
directive|define
name|SECT_OFF_MAX
value|4
end_define

begin_comment
comment|/* Count of possible values */
end_comment

begin_comment
comment|/* The stab_section_info chain remembers info from the ELF symbol table,    while psymtabs are being built for the other symbol tables in the     objfile.  It is destroyed at the complation of psymtab-reading.    Any info that was used from it has been copied into psymtabs.  */
end_comment

begin_struct
struct|struct
name|stab_section_info
block|{
name|char
modifier|*
name|filename
decl_stmt|;
name|CORE_ADDR
name|sections
index|[
name|SECT_OFF_MAX
index|]
decl_stmt|;
name|struct
name|stab_section_info
modifier|*
name|next
decl_stmt|;
name|int
name|found
decl_stmt|;
comment|/* Count of times it's found in searching */
block|}
struct|;
end_struct

begin_comment
comment|/* Information is passed among various dbxread routines for accessing    symbol files.  A pointer to this structure is kept in the sym_stab_info    field of the objfile struct.  */
end_comment

begin_struct
struct|struct
name|dbx_symfile_info
block|{
name|CORE_ADDR
name|text_addr
decl_stmt|;
comment|/* Start of text section */
name|int
name|text_size
decl_stmt|;
comment|/* Size of text section */
name|int
name|symcount
decl_stmt|;
comment|/* How many symbols are there in the file */
name|char
modifier|*
name|stringtab
decl_stmt|;
comment|/* The actual string table */
name|int
name|stringtab_size
decl_stmt|;
comment|/* Its size */
name|file_ptr
name|symtab_offset
decl_stmt|;
comment|/* Offset in file to symbol table */
name|int
name|symbol_size
decl_stmt|;
comment|/* Bytes in a single symbol */
name|struct
name|stab_section_info
modifier|*
name|stab_section_info
decl_stmt|;
comment|/* section starting points 				   of the original .o files before linking. */
comment|/* See stabsread.h for the use of the following. */
name|struct
name|header_file
modifier|*
name|header_files
decl_stmt|;
name|int
name|n_header_files
decl_stmt|;
name|int
name|n_allocated_header_files
decl_stmt|;
comment|/* Pointers to BFD sections.  These are used to speed up the building of      minimal symbols.  */
name|asection
modifier|*
name|text_section
decl_stmt|;
name|asection
modifier|*
name|data_section
decl_stmt|;
name|asection
modifier|*
name|bss_section
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DBX_SYMFILE_INFO
parameter_list|(
name|o
parameter_list|)
value|((o)->sym_stab_info)
end_define

begin_define
define|#
directive|define
name|DBX_TEXT_ADDR
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->text_addr)
end_define

begin_define
define|#
directive|define
name|DBX_TEXT_SIZE
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->text_size)
end_define

begin_define
define|#
directive|define
name|DBX_SYMCOUNT
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->symcount)
end_define

begin_define
define|#
directive|define
name|DBX_STRINGTAB
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->stringtab)
end_define

begin_define
define|#
directive|define
name|DBX_STRINGTAB_SIZE
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->stringtab_size)
end_define

begin_define
define|#
directive|define
name|DBX_SYMTAB_OFFSET
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->symtab_offset)
end_define

begin_define
define|#
directive|define
name|DBX_SYMBOL_SIZE
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->symbol_size)
end_define

begin_define
define|#
directive|define
name|DBX_TEXT_SECTION
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->text_section)
end_define

begin_define
define|#
directive|define
name|DBX_DATA_SECTION
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->data_section)
end_define

begin_define
define|#
directive|define
name|DBX_BSS_SECTION
parameter_list|(
name|o
parameter_list|)
value|(DBX_SYMFILE_INFO(o)->bss_section)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBSTABS_H */
end_comment

end_unit

