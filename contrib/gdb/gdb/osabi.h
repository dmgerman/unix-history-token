begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OS ABI variant handling for GDB.    Copyright 2001, 2002, 2003 Free Software Foundation, Inc.        This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSABI_H
end_ifndef

begin_define
define|#
directive|define
name|OSABI_H
end_define

begin_comment
comment|/* Register an OS ABI sniffer.  Each arch/flavour may have more than    one sniffer.  This is used to e.g. differentiate one OS's a.out from    another.  The first sniffer to return something other than    GDB_OSABI_UNKNOWN wins, so a sniffer should be careful to claim a file    only if it knows for sure what it is.  */
end_comment

begin_decl_stmt
name|void
name|gdbarch_register_osabi_sniffer
argument_list|(
expr|enum
name|bfd_architecture
argument_list|,
expr|enum
name|bfd_flavour
argument_list|,
expr|enum
name|gdb_osabi
argument_list|(
operator|*
argument_list|)
argument_list|(
name|bfd
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register a handler for an OS ABI variant for a given architecture    and machine type.  There should be only one handler for a given OS    ABI for each architecture and machine type combination.  */
end_comment

begin_decl_stmt
name|void
name|gdbarch_register_osabi
argument_list|(
expr|enum
name|bfd_architecture
argument_list|,
name|unsigned
name|long
argument_list|,
expr|enum
name|gdb_osabi
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
expr|struct
name|gdbarch_info
argument_list|,
expr|struct
name|gdbarch
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lookup the OS ABI corresponding to the specified BFD.  */
end_comment

begin_function_decl
name|enum
name|gdb_osabi
name|gdbarch_lookup_osabi
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize the gdbarch for the specified OS ABI variant.  */
end_comment

begin_function_decl
name|void
name|gdbarch_init_osabi
parameter_list|(
name|struct
name|gdbarch_info
parameter_list|,
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the name of the specified OS ABI.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|gdbarch_osabi_name
parameter_list|(
name|enum
name|gdb_osabi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper routine for ELF file sniffers.  This looks at ABI tag note    sections to determine the OS ABI from the note.  It should be called    via bfd_map_over_sections.  */
end_comment

begin_function_decl
name|void
name|generic_elf_osabi_sniff_abi_tag_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSABI_H */
end_comment

end_unit

