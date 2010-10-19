begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SH ELF support for BFD.    Copyright 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELF32_SH64_H
end_ifndef

begin_define
define|#
directive|define
name|ELF32_SH64_H
end_define

begin_define
define|#
directive|define
name|SH64_CRANGES_SECTION_NAME
value|".cranges"
end_define

begin_enum
enum|enum
name|sh64_elf_cr_type
block|{
name|CRT_NONE
init|=
literal|0
block|,
name|CRT_DATA
init|=
literal|1
block|,
name|CRT_SH5_ISA16
init|=
literal|2
block|,
name|CRT_SH5_ISA32
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* The official definition is this:      typedef struct {       Elf32_Addr cr_addr;       Elf32_Word cr_size;       Elf32_Half cr_type;     } Elf32_CRange;     but we have no use for that exact type.  Instead we use this struct for    the internal representation.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|bfd_vma
name|cr_addr
decl_stmt|;
name|bfd_size_type
name|cr_size
decl_stmt|;
name|enum
name|sh64_elf_cr_type
name|cr_type
decl_stmt|;
block|}
name|sh64_elf_crange
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SH64_CRANGE_SIZE
value|(4 + 4 + 2)
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_ADDR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_SIZE_OFFSET
value|4
end_define

begin_define
define|#
directive|define
name|SH64_CRANGE_CR_TYPE_OFFSET
value|(4 + 4)
end_define

begin_comment
comment|/* Get the contents type of an arbitrary address, or return CRT_NONE.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|sh64_elf_cr_type
name|sh64_get_contents_type
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|sh64_elf_crange
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Simpler interface.    FIXME: This seems redundant now that we export the interface above.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|sh64_address_is_shmedia
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_sh64_crange_qsort_cmpb
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_sh64_crange_qsort_cmpl
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_sh64_crange_bsearch_cmpb
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_sh64_crange_bsearch_cmpl
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|sh64_section_data
block|{
name|flagword
name|contents_flags
decl_stmt|;
comment|/* Only used in the cranges section, but we don't have an official      backend-specific bfd field.  */
name|bfd_size_type
name|cranges_growth
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_sh64_elf_section_data
block|{
name|struct
name|bfd_elf_section_data
name|elf
decl_stmt|;
name|struct
name|sh64_section_data
modifier|*
name|sh64_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sh64_elf_section_data
parameter_list|(
name|sec
parameter_list|)
define|\
value|((struct _sh64_elf_section_data *) elf_section_data (sec))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELF32_SH64_H */
end_comment

end_unit

