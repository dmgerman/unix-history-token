begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARC-specific support for 32-bit ELF    Copyright (C) 1994, 1995, 1997, 1999 Free Software Foundation, Inc.    Contributed by Doug Evans (dje@cygnus.com).  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
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

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|arc_info_to_howto_rel
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|Elf32_Internal_Rel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|arc_elf_object_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|arc_elf_final_write_processing
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Try to minimize the amount of space occupied by relocation tables    on the ROM (not that the ROM won't be swamped by other ELF overhead).  */
end_comment

begin_define
define|#
directive|define
name|USE_REL
end_define

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
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARC_NONE"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A standard 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_ARC_32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARC_32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 26 bit absolute branch, right shifted by 2.  */
name|HOWTO
argument_list|(
name|R_ARC_B26
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARC_B26"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x00ffffff
argument_list|,
comment|/* src_mask */
literal|0x00ffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A relative 22 bit branch; bits 21-2 are stored in bits 26-7.  */
name|HOWTO
argument_list|(
name|R_ARC_B22_PCREL
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|22
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|7
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARC_B22_PCREL"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x07ffff80
argument_list|,
comment|/* src_mask */
literal|0x07ffff80
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
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
name|abfd
parameter_list|,
name|code
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd_reloc_code_real_type
name|code
decl_stmt|;
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
name|arc_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|arc_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
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
operator|&
name|elf_arc_howto_table
index|[
name|arc_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
index|]
return|;
block|}
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
name|abfd
parameter_list|,
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|cache_ptr
decl_stmt|;
name|Elf32_Internal_Rel
modifier|*
name|dst
decl_stmt|;
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
name|boolean
name|arc_elf_object_p
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|int
name|mach
decl_stmt|;
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
name|E_ARC_MACH_BASE
case|:
name|mach
operator|=
name|bfd_mach_arc_base
expr_stmt|;
break|break;
default|default:
comment|/* Unknown cpu type.  ??? What to do?  */
return|return
name|false
return|;
block|}
operator|(
name|void
operator|)
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_arc
argument_list|,
name|mach
argument_list|)
expr_stmt|;
return|return
name|true
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
name|abfd
parameter_list|,
name|linker
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|boolean
name|linker
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|int
name|mach
decl_stmt|;
name|unsigned
name|long
name|val
decl_stmt|;
switch|switch
condition|(
name|mach
operator|=
name|bfd_get_mach
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
case|case
name|bfd_mach_arc_base
case|:
name|val
operator|=
name|E_ARC_MACH_BASE
expr_stmt|;
break|break;
default|default:
return|return;
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
value|EM_CYGNUS_ARC
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
define|\
value|arc_elf_final_write_processing
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

