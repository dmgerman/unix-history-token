begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Infineon XC16X-specific support for 16-bit ELF.    Copyright 2006  Free Software Foundation, Inc.    Contributed by KPIT Cummins Infosystems      This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"elf/xc16x.h"
end_include

begin_include
include|#
directive|include
file|"elf/dwarf2.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|xc16x_elf_howto_table
index|[]
init|=
block|{
comment|/* This reloc does nothing.  */
name|HOWTO
argument_list|(
name|R_XC16X_NONE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
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
literal|"R_XC16X_NONE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* An 8 bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_XC16X_ABS_8
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|8
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_XC16X_ABS_8"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x0000
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16 bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_XC16X_ABS_16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_XC16X_ABS_16"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_XC16X_ABS_32
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
name|FALSE
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
literal|"R_XC16X_ABS_32"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A PC relative 8 bit relocation.  */
name|HOWTO
argument_list|(
name|R_XC16X_8_PCREL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|8
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_XC16X_8_PCREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0000
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Relocation regarding page number.  */
name|HOWTO
argument_list|(
name|R_XC16X_PAG
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_XC16X_PAG"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Relocation regarding page number.  */
name|HOWTO
argument_list|(
name|R_XC16X_POF
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos  */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function  */
literal|"R_XC16X_POF"
argument_list|,
comment|/* name  */
name|TRUE
argument_list|,
comment|/* partial_inplace  */
literal|0x00000000
argument_list|,
comment|/* src_mask  */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask  */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset  */
comment|/* Relocation regarding segment number.   */
name|HOWTO
argument_list|(
name|R_XC16X_SEG
argument_list|,
comment|/* type  */
literal|0
argument_list|,
comment|/* rightshift  */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long)  */
literal|16
argument_list|,
comment|/* bitsize  */
name|FALSE
argument_list|,
comment|/* pc_relative  */
literal|0
argument_list|,
comment|/* bitpos  */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function  */
literal|"R_XC16X_SEG"
argument_list|,
comment|/* name  */
name|TRUE
argument_list|,
comment|/* partial_inplace  */
literal|0x00000000
argument_list|,
comment|/* src_mask  */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask  */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset  */
comment|/* Relocation regarding segment offset.  */
name|HOWTO
argument_list|(
argument|R_XC16X_SOF
argument_list|,
comment|/* type  */
literal|0
argument_list|,
comment|/* rightshift  */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long)  */
literal|16
argument_list|,
comment|/* bitsize  */
argument|FALSE
argument_list|,
comment|/* pc_relative  */
literal|0
argument_list|,
comment|/* bitpos  */
argument|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow  */
argument|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function  */
literal|"R_XC16X_SOF"
argument_list|,
comment|/* name */
argument|TRUE
argument_list|,
comment|/* partial_inplace  */
literal|0x00000000
argument_list|,
comment|/* src_mask  */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask  */
argument|FALSE
argument_list|)
comment|/* pcrel_offset  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map BFD reloc types to XC16X ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|xc16x_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|unsigned
name|int
name|xc16x_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|xc16x_reloc_map
name|xc16x_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_XC16X_NONE
block|}
block|,
block|{
name|BFD_RELOC_8
block|,
name|R_XC16X_ABS_8
block|}
block|,
block|{
name|BFD_RELOC_16
block|,
name|R_XC16X_ABS_16
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_XC16X_ABS_32
block|}
block|,
block|{
name|BFD_RELOC_8_PCREL
block|,
name|R_XC16X_8_PCREL
block|}
block|,
block|{
name|BFD_RELOC_XC16X_PAG
block|,
name|R_XC16X_PAG
block|}
block|,
block|{
name|BFD_RELOC_XC16X_POF
block|,
name|R_XC16X_POF
block|}
block|,
block|{
name|BFD_RELOC_XC16X_SEG
block|,
name|R_XC16X_SEG
block|}
block|,
block|{
name|BFD_RELOC_XC16X_SOF
block|,
name|R_XC16X_SOF
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is used to search for correct relocation type from    howto structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|xc16x_reloc_type_lookup
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
name|xc16x_reloc_map
argument_list|)
init|;
operator|--
name|i
condition|;
control|)
if|if
condition|(
name|xc16x_reloc_map
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
name|xc16x_elf_howto_table
index|[
name|xc16x_reloc_map
index|[
name|i
index|]
operator|.
name|xc16x_reloc_val
index|]
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* For a particular operand this function is    called to finalise the type of relocation.  */
end_comment

begin_function
specifier|static
name|void
name|elf32_xc16x_info_to_howto
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|bfd_reloc
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|elf_reloc
parameter_list|)
block|{
name|unsigned
name|int
name|r
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
name|r
operator|=
name|ELF32_R_TYPE
argument_list|(
name|elf_reloc
operator|->
name|r_info
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ARRAY_SIZE
argument_list|(
name|xc16x_elf_howto_table
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|xc16x_elf_howto_table
index|[
name|i
index|]
operator|.
name|type
operator|==
name|r
condition|)
block|{
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|xc16x_elf_howto_table
index|[
name|i
index|]
expr_stmt|;
return|return;
block|}
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_xc16x_final_link_relocate
parameter_list|(
name|unsigned
name|long
name|r_type
parameter_list|,
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|bfd_vma
name|offset
parameter_list|,
name|bfd_vma
name|value
parameter_list|,
name|bfd_vma
name|addend
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
name|info
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asection
modifier|*
name|sym_sec
name|ATTRIBUTE_UNUSED
parameter_list|,
name|int
name|is_local
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|bfd_byte
modifier|*
name|hit_data
init|=
name|contents
operator|+
name|offset
decl_stmt|;
name|bfd_vma
name|val1
decl_stmt|;
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|R_XC16X_NONE
case|:
return|return
name|bfd_reloc_ok
return|;
case|case
name|R_XC16X_ABS_16
case|:
name|value
operator|+=
name|addend
expr_stmt|;
name|bfd_put_16
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
case|case
name|R_XC16X_8_PCREL
case|:
name|bfd_put_8
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
comment|/* Following case is to find page number from actual 	 address for this divide value by 16k i.e. page size.  */
case|case
name|R_XC16X_PAG
case|:
name|value
operator|+=
name|addend
expr_stmt|;
name|value
operator|/=
literal|0x4000
expr_stmt|;
name|bfd_put_16
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
comment|/* Following case is to find page offset from actual address 	 for this take modulo of value by 16k i.e. page size.  */
case|case
name|R_XC16X_POF
case|:
name|value
operator|+=
name|addend
expr_stmt|;
name|value
operator|%=
literal|0x4000
expr_stmt|;
name|bfd_put_16
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
comment|/* Following case is to find segment number from actual 	 address for this divide value by 64k i.e. segment size.  */
case|case
name|R_XC16X_SEG
case|:
name|value
operator|+=
name|addend
expr_stmt|;
name|value
operator|/=
literal|0x10000
expr_stmt|;
name|bfd_put_16
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
comment|/* Following case is to find segment offset from actual address 	 for this take modulo of value by 64k i.e. segment size.  */
case|case
name|R_XC16X_SOF
case|:
name|value
operator|+=
name|addend
expr_stmt|;
name|value
operator|%=
literal|0x10000
expr_stmt|;
name|bfd_put_16
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
case|case
name|R_XC16X_ABS_32
case|:
if|if
condition|(
operator|!
name|strstr
argument_list|(
name|input_section
operator|->
name|name
argument_list|,
literal|".debug"
argument_list|)
condition|)
block|{
name|value
operator|+=
name|addend
expr_stmt|;
name|val1
operator|=
name|value
expr_stmt|;
name|value
operator|%=
literal|0x4000
expr_stmt|;
name|val1
operator|/=
literal|0x4000
expr_stmt|;
name|val1
operator|=
name|val1
operator|<<
literal|16
expr_stmt|;
name|value
operator|+=
name|val1
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|value
operator|+=
name|addend
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|value
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
block|}
return|return
name|bfd_reloc_ok
return|;
default|default:
return|return
name|bfd_reloc_notsupported
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|bfd_boolean
name|elf32_xc16x_relocate_section
parameter_list|(
name|bfd
modifier|*
name|output_bfd
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
name|info
parameter_list|,
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|relocs
parameter_list|,
name|Elf_Internal_Sym
modifier|*
name|local_syms
parameter_list|,
name|asection
modifier|*
modifier|*
name|local_sections
parameter_list|)
block|{
name|Elf_Internal_Shdr
modifier|*
name|symtab_hdr
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|rel
decl_stmt|,
modifier|*
name|relend
decl_stmt|;
if|if
condition|(
name|info
operator|->
name|relocatable
condition|)
return|return
name|TRUE
return|;
name|symtab_hdr
operator|=
operator|&
name|elf_tdata
argument_list|(
name|input_bfd
argument_list|)
operator|->
name|symtab_hdr
expr_stmt|;
name|sym_hashes
operator|=
name|elf_sym_hashes
argument_list|(
name|input_bfd
argument_list|)
expr_stmt|;
name|rel
operator|=
name|relocs
expr_stmt|;
name|relend
operator|=
name|relocs
operator|+
name|input_section
operator|->
name|reloc_count
expr_stmt|;
for|for
control|(
init|;
name|rel
operator|<
name|relend
condition|;
name|rel
operator|++
control|)
block|{
name|unsigned
name|int
name|r_type
decl_stmt|;
name|unsigned
name|long
name|r_symndx
decl_stmt|;
name|Elf_Internal_Sym
modifier|*
name|sym
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_reloc_status_type
name|r
decl_stmt|;
comment|/* This is a final link.  */
name|r_symndx
operator|=
name|ELF32_R_SYM
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|h
operator|=
name|NULL
expr_stmt|;
name|sym
operator|=
name|NULL
expr_stmt|;
name|sec
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|r_symndx
operator|<
name|symtab_hdr
operator|->
name|sh_info
condition|)
block|{
name|sym
operator|=
name|local_syms
operator|+
name|r_symndx
expr_stmt|;
name|sec
operator|=
name|local_sections
index|[
name|r_symndx
index|]
expr_stmt|;
name|relocation
operator|=
name|_bfd_elf_rela_local_sym
argument_list|(
name|output_bfd
argument_list|,
name|sym
argument_list|,
operator|&
name|sec
argument_list|,
name|rel
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bfd_boolean
name|unresolved_reloc
decl_stmt|,
name|warned
decl_stmt|;
name|RELOC_FOR_GLOBAL_SYMBOL
argument_list|(
name|info
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
argument_list|,
name|r_symndx
argument_list|,
name|symtab_hdr
argument_list|,
name|sym_hashes
argument_list|,
name|h
argument_list|,
name|sec
argument_list|,
name|relocation
argument_list|,
name|unresolved_reloc
argument_list|,
name|warned
argument_list|)
expr_stmt|;
block|}
name|r
operator|=
name|elf32_xc16x_final_link_relocate
argument_list|(
name|r_type
argument_list|,
name|input_bfd
argument_list|,
name|output_bfd
argument_list|,
name|input_section
argument_list|,
name|contents
argument_list|,
name|rel
operator|->
name|r_offset
argument_list|,
name|relocation
argument_list|,
name|rel
operator|->
name|r_addend
argument_list|,
name|info
argument_list|,
name|sec
argument_list|,
name|h
operator|==
name|NULL
argument_list|)
expr_stmt|;
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|elf32_xc16x_final_write_processing
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
default|default:
case|case
name|bfd_mach_xc16x
case|:
name|val
operator|=
literal|0x1000
expr_stmt|;
break|break;
case|case
name|bfd_mach_xc16xl
case|:
name|val
operator|=
literal|0x1001
expr_stmt|;
break|break;
case|case
name|bfd_mach_xc16xs
case|:
name|val
operator|=
literal|0x1002
expr_stmt|;
break|break;
block|}
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

begin_function
specifier|static
name|unsigned
name|long
name|elf32_xc16x_mach
parameter_list|(
name|flagword
name|flags
parameter_list|)
block|{
switch|switch
condition|(
name|flags
condition|)
block|{
case|case
literal|0x1000
case|:
default|default:
return|return
name|bfd_mach_xc16x
return|;
case|case
literal|0x1001
case|:
return|return
name|bfd_mach_xc16xl
return|;
case|case
literal|0x1002
case|:
return|return
name|bfd_mach_xc16xs
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|bfd_boolean
name|elf32_xc16x_object_p
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_xc16x
argument_list|,
name|elf32_xc16x_mach
argument_list|(
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_xc16x
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_XC16X
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_xc16x_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-xc16x"
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|elf32_xc16x_final_write_processing
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|elf32_xc16x_object_p
end_define

begin_define
define|#
directive|define
name|elf_backend_can_gc_sections
value|1
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
value|xc16x_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|elf32_xc16x_info_to_howto
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|elf32_xc16x_info_to_howto
end_define

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|elf32_xc16x_relocate_section
end_define

begin_define
define|#
directive|define
name|elf_backend_rela_normal
value|1
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

