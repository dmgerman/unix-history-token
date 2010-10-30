begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPU specific support for 32-bit ELF.     Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Extra info kept for SPU sections.  */
end_comment

begin_struct_decl
struct_decl|struct
name|spu_elf_stack_info
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|_spu_elf_section_data
block|{
name|struct
name|bfd_elf_section_data
name|elf
decl_stmt|;
comment|/* Stack analysis info kept for this section.  */
name|struct
name|spu_elf_stack_info
modifier|*
name|stack_info
decl_stmt|;
comment|/* Non-zero for overlay output sections.  */
name|unsigned
name|int
name|ovl_index
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|spu_elf_section_data
parameter_list|(
name|sec
parameter_list|)
define|\
value|((struct _spu_elf_section_data *) elf_section_data (sec))
end_define

begin_struct
struct|struct
name|_ovl_stream
block|{
specifier|const
name|void
modifier|*
name|start
decl_stmt|;
specifier|const
name|void
modifier|*
name|end
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|spu_elf_plugin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|spu_elf_open_builtin_lib
parameter_list|(
name|bfd
modifier|*
modifier|*
parameter_list|,
specifier|const
name|struct
name|_ovl_stream
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|spu_elf_create_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|spu_elf_find_overlays
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|spu_elf_size_stubs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|spu_elf_build_stubs
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|asection
modifier|*
name|spu_elf_check_vma
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

end_unit

