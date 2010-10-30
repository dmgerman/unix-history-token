begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARC-specific support for 32-bit ELF    Copyright 1994, 1995, 1997, 1999, 2001, 2002, 2005, 2007    Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"elf-bfd.h"
end_include

begin_include
include|#
directive|include
file|"elf/arc.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_comment
comment|/* Try to minimize the amount of space occupied by relocation tables    on the ROM (not that the ROM won't be swamped by other ELF overhead).  */
end_comment

begin_define
define|#
directive|define
name|USE_REL
value|1
end_define

begin_function
specifier|static
name|bfd_reloc_status_type
name|arc_elf_b22_pcrel
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|arelent
modifier|*
name|reloc_entry
parameter_list|,
name|asymbol
modifier|*
name|symbol
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd
modifier|*
name|output_bfd
parameter_list|,
name|char
modifier|*
modifier|*
name|error_message
parameter_list|)
block|{
comment|/* If linking, back up the final symbol address by the address of the      reloc.  This cannot be accomplished by setting the pcrel_offset      field to TRUE, as bfd_install_relocation will detect this and refuse      to install the offset in the first place, but bfd_perform_relocation      will still insist on removing it.  */
if|if
condition|(
name|output_bfd
operator|==
name|NULL
condition|)
name|reloc_entry
operator|->
name|addend
operator|-=
name|reloc_entry
operator|->
name|address
expr_stmt|;
comment|/* Fall through to the default elf reloc handler.  */
return|return
name|bfd_elf_generic_reloc
argument_list|(
name|abfd
argument_list|,
name|reloc_entry
argument_list|,
name|symbol
argument_list|,
name|data
argument_list|,
name|input_section
argument_list|,
name|output_bfd
argument_list|,
name|error_message
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_arc_howto_table
index|[]
init|=
block|{
comment|/* This reloc does nothing.  */
name|HOWTO
argument_list|(
name|R_ARC_NONE
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_ARC_NONE"
argument_list|,
comment|/* Name.  */
name|TRUE
argument_list|,
comment|/* Partial_inplace.  */
literal|0
argument_list|,
comment|/* Src_mask.  */
literal|0
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A standard 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_ARC_32
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_ARC_32"
argument_list|,
comment|/* Name.  */
name|TRUE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xffffffff
argument_list|,
comment|/* Src_mask.  */
literal|0xffffffff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A 26 bit absolute branch, right shifted by 2.  */
name|HOWTO
argument_list|(
name|R_ARC_B26
argument_list|,
comment|/* Type.  */
literal|2
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|26
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_ARC_B26"
argument_list|,
comment|/* Name.  */
name|TRUE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x00ffffff
argument_list|,
comment|/* Src_mask.  */
literal|0x00ffffff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 22 bit branch; bits 21-2 are stored in bits 26-7.  */
name|HOWTO
argument_list|(
name|R_ARC_B22_PCREL
argument_list|,
comment|/* Type.  */
literal|2
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|22
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|7
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|arc_elf_b22_pcrel
argument_list|,
comment|/* Special_function.  */
literal|"R_ARC_B22_PCREL"
argument_list|,
comment|/* Name.  */
name|TRUE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x07ffff80
argument_list|,
comment|/* Src_mask.  */
literal|0x07ffff80
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map BFD reloc types to ARC ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|arc_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|unsigned
name|char
name|elf_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|arc_reloc_map
name|arc_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_ARC_NONE
block|, }
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_ARC_32
block|}
block|,
block|{
name|BFD_RELOC_CTOR
block|,
name|R_ARC_32
block|}
block|,
block|{
name|BFD_RELOC_ARC_B26
block|,
name|R_ARC_B26
block|}
block|,
block|{
name|BFD_RELOC_ARC_B22_PCREL
block|,
name|R_ARC_B22_PCREL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bfd_reloc_code_real_type
name|code
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
name|ARRAY_SIZE
argument_list|(
name|arc_reloc_map
argument_list|)
init|;
name|i
operator|--
condition|;
control|)
if|if
condition|(
name|arc_reloc_map
index|[
name|i
index|]
operator|.
name|bfd_reloc_val
operator|==
name|code
condition|)
return|return
name|elf_arc_howto_table
operator|+
name|arc_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_name_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|r_name
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|elf_arc_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf_arc_howto_table
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|elf_arc_howto_table
index|[
name|i
index|]
operator|.
name|name
operator|!=
name|NULL
operator|&&
name|strcasecmp
argument_list|(
name|elf_arc_howto_table
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|r_name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|&
name|elf_arc_howto_table
index|[
name|i
index|]
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Set the howto pointer for an ARC ELF reloc.  */
end_comment

begin_function
specifier|static
name|void
name|arc_info_to_howto_rel
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|unsigned
name|int
name|r_type
decl_stmt|;
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|dst
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|r_type
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_ARC_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
operator|&
name|elf_arc_howto_table
index|[
name|r_type
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set the right machine number for an ARC ELF file.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|arc_elf_object_p
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
name|unsigned
name|int
name|mach
init|=
name|bfd_mach_arc_6
decl_stmt|;
if|if
condition|(
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_machine
operator|==
name|EM_ARC
condition|)
block|{
name|unsigned
name|long
name|arch
init|=
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator|&
name|EF_ARC_MACH
decl_stmt|;
switch|switch
condition|(
name|arch
condition|)
block|{
case|case
name|E_ARC_MACH_ARC5
case|:
name|mach
operator|=
name|bfd_mach_arc_5
expr_stmt|;
break|break;
default|default:
case|case
name|E_ARC_MACH_ARC6
case|:
name|mach
operator|=
name|bfd_mach_arc_6
expr_stmt|;
break|break;
case|case
name|E_ARC_MACH_ARC7
case|:
name|mach
operator|=
name|bfd_mach_arc_7
expr_stmt|;
break|break;
case|case
name|E_ARC_MACH_ARC8
case|:
name|mach
operator|=
name|bfd_mach_arc_8
expr_stmt|;
break|break;
block|}
block|}
return|return
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_arc
argument_list|,
name|mach
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* The final processing done just before writing out an ARC ELF object file.    This gets the ARC architecture right based on the machine number.  */
end_comment

begin_function
specifier|static
name|void
name|arc_elf_final_write_processing
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|bfd_boolean
name|linker
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|unsigned
name|long
name|val
decl_stmt|;
switch|switch
condition|(
name|bfd_get_mach
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
case|case
name|bfd_mach_arc_5
case|:
name|val
operator|=
name|E_ARC_MACH_ARC5
expr_stmt|;
break|break;
default|default:
case|case
name|bfd_mach_arc_6
case|:
name|val
operator|=
name|E_ARC_MACH_ARC6
expr_stmt|;
break|break;
case|case
name|bfd_mach_arc_7
case|:
name|val
operator|=
name|E_ARC_MACH_ARC7
expr_stmt|;
break|break;
case|case
name|bfd_mach_arc_8
case|:
name|val
operator|=
name|E_ARC_MACH_ARC8
expr_stmt|;
break|break;
block|}
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator|&=
operator|~
name|EF_ARC_MACH
expr_stmt|;
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator||=
name|val
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_littlearc_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-littlearc"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_bigarc_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-bigarc"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_arc
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_ARC
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|0
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|arc_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|arc_elf_object_p
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|arc_elf_final_write_processing
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

