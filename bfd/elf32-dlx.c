begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DLX specific support for 32-bit ELF    Copyright 2002, 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"elf/dlx.h"
end_include

begin_decl_stmt
name|int
name|set_dlx_skip_hi16_flag
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_boolean
name|elf32_dlx_check_relocs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|asection
operator|*
operator|,
specifier|const
name|Elf_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|elf32_dlx_info_to_howto
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|Elf_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|elf32_dlx_info_to_howto_rel
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|Elf_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|elf32_dlx_relocate16
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|elf32_dlx_relocate26
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_dlx_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_reloc_code_real_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|_bfd_dlx_elf_hi16_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|dlx_rtype_to_howto
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|USE_REL
value|1
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
value|elf32_dlx_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|elf32_dlx_info_to_howto
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|elf32_dlx_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_check_relocs
value|elf32_dlx_check_relocs
end_define

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|dlx_elf_howto_table
index|[]
init|=
block|{
comment|/* No relocation.  */
name|HOWTO
argument_list|(
name|R_DLX_NONE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
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
literal|"R_DLX_NONE"
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
comment|/* 8 bit relocation.  */
name|HOWTO
argument_list|(
name|R_DLX_RELOC_8
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
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_DLX_RELOC_8"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xff
argument_list|,
comment|/* src_mask */
literal|0xff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit relocation.  */
name|HOWTO
argument_list|(
name|R_DLX_RELOC_16
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
literal|"R_DLX_RELOC_16"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
if|#
directive|if
literal|0
comment|/* 26 bit jump address.  */
block|HOWTO (R_DLX_RELOC_26,
comment|/* type */
block|0,
comment|/* rightshift */
block|2,
comment|/* size (0 = byte, 1 = short, 2 = long) */
block|26,
comment|/* bitsize */
block|FALSE,
comment|/* pc_relative */
block|0,
comment|/* bitpos */
block|complain_overflow_dont,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow detection, because the upper four 	      bits must match the PC + 4.  */
block|bfd_elf_generic_reloc,
comment|/* special_function */
block|"R_DLX_RELOC_26",
comment|/* name */
block|TRUE,
comment|/* partial_inplace */
block|0x3ffffff,
comment|/* src_mask */
block|0x3ffffff,
comment|/* dst_mask */
block|FALSE),
comment|/* pcrel_offset */
endif|#
directive|endif
comment|/* 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_DLX_RELOC_32
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_DLX_RELOC_32"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* GNU extension to record C++ vtable hierarchy */
name|HOWTO
argument_list|(
name|R_DLX_GNU_VTINHERIT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
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
name|NULL
argument_list|,
comment|/* special_function */
literal|"R_DLX_GNU_VTINHERIT"
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
comment|/* GNU extension to record C++ vtable member usage */
name|HOWTO
argument_list|(
argument|R_DLX_GNU_VTENTRY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
argument|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
argument|_bfd_elf_rel_vtable_reloc_fn
argument_list|,
comment|/* special_function */
literal|"R_DLX_GNU_VTENTRY"
argument_list|,
comment|/* name */
argument|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
argument|FALSE
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 16 bit offset for pc-relative branches.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_dlx_gnu_rel16_s2
init|=
name|HOWTO
argument_list|(
name|R_DLX_RELOC_16_PCREL
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
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|elf32_dlx_relocate16
argument_list|,
comment|/* special_function */
literal|"R_DLX_RELOC_16_PCREL"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* 26 bit offset for pc-relative branches.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_dlx_gnu_rel26_s2
init|=
name|HOWTO
argument_list|(
name|R_DLX_RELOC_26_PCREL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|elf32_dlx_relocate26
argument_list|,
comment|/* special_function */
literal|"R_DLX_RELOC_26_PCREL"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* High 16 bits of symbol value.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_dlx_reloc_16_hi
init|=
name|HOWTO
argument_list|(
name|R_DLX_RELOC_16_HI
argument_list|,
comment|/* type */
literal|16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_dlx_elf_hi16_reloc
argument_list|,
comment|/* special_function */
literal|"R_DLX_RELOC_16_HI"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xFFFF
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* Low 16 bits of symbol value.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_dlx_reloc_16_lo
init|=
name|HOWTO
argument_list|(
name|R_DLX_RELOC_16_LO
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
literal|"R_DLX_RELOC_16_LO"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* The gas default behavior is not to preform the %hi modifier so that the    GNU assembler can have the lower 16 bits offset placed in the insn, BUT    we do like the gas to indicate it is %hi reloc type so when we in the link    loader phase we can have the corrected hi16 vale replace the buggous lo16    value that was placed there by gas.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|skip_dlx_elf_hi16_reloc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|set_dlx_skip_hi16_flag
parameter_list|(
name|flag
parameter_list|)
name|int
name|flag
decl_stmt|;
block|{
name|skip_dlx_elf_hi16_reloc
operator|=
name|flag
expr_stmt|;
return|return
name|flag
return|;
block|}
end_function

begin_function
specifier|static
name|bfd_reloc_status_type
name|_bfd_dlx_elf_hi16_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
decl_stmt|;
name|asymbol
modifier|*
name|symbol
decl_stmt|;
name|PTR
name|data
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
decl_stmt|;
block|{
name|bfd_reloc_status_type
name|ret
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
comment|/* If the skip flag is set then we simply do the generic relocating, this      is more of a hack for dlx gas/gld, so we do not need to do the %hi/%lo      fixup like mips gld did.   */
if|#
directive|if
literal|0
block|printf ("DEBUG: skip_dlx_elf_hi16_reloc = 0x%08x\n", skip_dlx_elf_hi16_reloc);
endif|#
directive|endif
if|if
condition|(
name|skip_dlx_elf_hi16_reloc
condition|)
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
comment|/* If we're relocating, and this an external symbol, we don't want      to change anything.  */
if|if
condition|(
name|output_bfd
operator|!=
operator|(
name|bfd
operator|*
operator|)
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
name|reloc_entry
operator|->
name|addend
operator|==
literal|0
condition|)
block|{
name|reloc_entry
operator|->
name|address
operator|+=
name|input_section
operator|->
name|output_offset
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
name|ret
operator|=
name|bfd_reloc_ok
expr_stmt|;
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
name|ret
operator|=
name|bfd_reloc_undefined
expr_stmt|;
if|#
directive|if
literal|0
block|{     unsigned long vallo, val;      vallo = bfd_get_16 (abfd, (bfd_byte *) data + reloc_entry->address);     printf ("DEBUG: The relocation address = 0x%08x\n", reloc_entry->address);     printf ("DEBUG: The symbol        = 0x%08x\n", vallo);     printf ("DEBUG: The symbol name   = %s\n", bfd_asymbol_name (symbol));     printf ("DEBUG: The symbol->value = 0x%08x\n", symbol->value);     printf ("DEBUG: The vma           = 0x%08x\n", symbol->section->output_section->vma);     printf ("DEBUG: The output_offset = 0x%08x\n", symbol->section->output_offset);     printf ("DEBUG: The input_offset  = 0x%08x\n", input_section->output_offset);     printf ("DEBUG: The input_vma     = 0x%08x\n", input_section->vma);     printf ("DEBUG: The addend        = 0x%08x\n", reloc_entry->addend);   }
endif|#
directive|endif
name|relocation
operator|=
operator|(
name|bfd_is_com_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|)
condition|?
literal|0
else|:
name|symbol
operator|->
name|value
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
name|relocation
operator|+=
name|bfd_get_16
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|address
operator|>
name|input_section
operator|->
name|_cooked_size
condition|)
return|return
name|bfd_reloc_outofrange
return|;
if|#
directive|if
literal|0
block|printf ("DEBUG: The finial relocation value = 0x%08x\n", relocation);
endif|#
directive|endif
name|bfd_put_16
argument_list|(
name|abfd
argument_list|,
call|(
name|short
call|)
argument_list|(
operator|(
name|relocation
operator|>>
literal|16
operator|)
operator|&
literal|0xFFFF
argument_list|)
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* ELF relocs are against symbols.  If we are producing relocatable    output, and the reloc is against an external symbol, and nothing    has given us any additional addend, the resulting reloc will also    be against the same symbol.  In such a case, we don't want to    change anything about the way the reloc is handled, since it will    all be done at final link time.  Rather than put special case code    into bfd_perform_relocation, all the reloc types use this howto    function.  It just short circuits the reloc if producing    relocatable output against an external symbol.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_dlx_relocate16
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
decl_stmt|;
name|asymbol
modifier|*
name|symbol
decl_stmt|;
name|PTR
name|data
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|unsigned
name|long
name|insn
decl_stmt|,
name|vallo
decl_stmt|,
name|allignment
decl_stmt|;
name|int
name|val
decl_stmt|;
comment|/* HACK: I think this first condition is necessary when producing      relocatable output.  After the end of HACK, the code is identical      to bfd_elf_generic_reloc().  I would _guess_ the first change      belongs there rather than here.  martindo 1998-10-23.  */
if|if
condition|(
name|skip_dlx_elf_hi16_reloc
condition|)
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
comment|/* Check undefined section and undefined symbols  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
comment|/* Can not support a long jump to sections other then .text   */
if|if
condition|(
name|strcmp
argument_list|(
name|input_section
operator|->
name|name
argument_list|,
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|name
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"BFD Link Error: branch (PC rel16) to section (%s) not supported\n"
argument_list|,
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|name
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_undefined
return|;
block|}
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
name|allignment
operator|=
literal|1
operator|<<
operator|(
name|input_section
operator|->
name|output_section
operator|->
name|alignment_power
operator|-
literal|1
operator|)
expr_stmt|;
name|vallo
operator|=
name|insn
operator|&
literal|0x0000FFFF
expr_stmt|;
if|if
condition|(
name|vallo
operator|&
literal|0x8000
condition|)
name|vallo
operator|=
operator|~
operator|(
name|vallo
operator||
literal|0xFFFF0000
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* vallo points to the vma of next instruction.  */
name|vallo
operator|+=
operator|(
operator|(
call|(
name|unsigned
name|long
call|)
argument_list|(
name|input_section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|input_section
operator|->
name|output_offset
argument_list|)
operator|+
name|allignment
operator|)
operator|&
operator|~
name|allignment
operator|)
expr_stmt|;
comment|/* val is the displacement (PC relative to next instruction).  */
name|val
operator|=
operator|(
name|symbol
operator|->
name|section
operator|->
name|output_offset
operator|+
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|symbol
operator|->
name|value
operator|)
operator|-
name|vallo
expr_stmt|;
if|#
directive|if
literal|0
block|printf ("DEBUG elf32_dlx_relocate: We are here\n");   printf ("DEBUG: The insn            = 0x%08x\n", insn);   printf ("DEBUG: The vallo           = 0x%08x\n", vallo);   printf ("DEBUG: The val             = 0x%08x\n", val);   printf ("DEBUG: The symbol name     = %s\n", bfd_asymbol_name (symbol));   printf ("DEBUG: The symbol->value   = 0x%08x\n", symbol->value);   printf ("DEBUG: The vma             = 0x%08x\n", symbol->section->output_section->vma);   printf ("DEBUG: The lma             = 0x%08x\n", symbol->section->output_section->lma);   printf ("DEBUG: The alignment_power = 0x%08x\n", symbol->section->output_section->alignment_power);   printf ("DEBUG: The output_offset   = 0x%08x\n", symbol->section->output_offset);   printf ("DEBUG: The addend          = 0x%08x\n", reloc_entry->addend);
endif|#
directive|endif
if|if
condition|(
name|abs
argument_list|(
operator|(
name|int
operator|)
name|val
argument_list|)
operator|>
literal|0x00007FFF
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|insn
operator|=
operator|(
name|insn
operator|&
literal|0xFFFF0000
operator|)
operator||
operator|(
name|val
operator|&
literal|0x0000FFFF
operator|)
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|insn
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_dlx_relocate26
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
decl_stmt|;
name|asymbol
modifier|*
name|symbol
decl_stmt|;
name|PTR
name|data
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|unsigned
name|long
name|insn
decl_stmt|,
name|vallo
decl_stmt|,
name|allignment
decl_stmt|;
name|int
name|val
decl_stmt|;
comment|/* HACK: I think this first condition is necessary when producing      relocatable output.  After the end of HACK, the code is identical      to bfd_elf_generic_reloc().  I would _guess_ the first change      belongs there rather than here.  martindo 1998-10-23.  */
if|if
condition|(
name|skip_dlx_elf_hi16_reloc
condition|)
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
comment|/* Check undefined section and undefined symbols.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
comment|/* Can not support a long jump to sections other then .text   */
if|if
condition|(
name|strcmp
argument_list|(
name|input_section
operator|->
name|name
argument_list|,
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|name
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"BFD Link Error: jump (PC rel26) to section (%s) not supported\n"
argument_list|,
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|name
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_undefined
return|;
block|}
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
name|allignment
operator|=
literal|1
operator|<<
operator|(
name|input_section
operator|->
name|output_section
operator|->
name|alignment_power
operator|-
literal|1
operator|)
expr_stmt|;
name|vallo
operator|=
name|insn
operator|&
literal|0x03FFFFFF
expr_stmt|;
if|if
condition|(
name|vallo
operator|&
literal|0x03000000
condition|)
name|vallo
operator|=
operator|~
operator|(
name|vallo
operator||
literal|0xFC000000
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* vallo is the vma for the next instruction.  */
name|vallo
operator|+=
operator|(
operator|(
call|(
name|unsigned
name|long
call|)
argument_list|(
name|input_section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|input_section
operator|->
name|output_offset
argument_list|)
operator|+
name|allignment
operator|)
operator|&
operator|~
name|allignment
operator|)
expr_stmt|;
comment|/* val is the displacement (PC relative to next instruction).  */
name|val
operator|=
operator|(
name|symbol
operator|->
name|section
operator|->
name|output_offset
operator|+
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|symbol
operator|->
name|value
operator|)
operator|-
name|vallo
expr_stmt|;
if|#
directive|if
literal|0
block|printf ("DEBUG elf32_dlx_relocate26: We are here\n");   printf ("DEBUG: The insn          = 0x%08x\n", insn);   printf ("DEBUG: The vallo         = 0x%08x\n", vallo);   printf ("DEBUG: The val           = 0x%08x\n", val);   printf ("DEBUG: The abs(val)      = 0x%08x\n", abs (val));   printf ("DEBUG: The symbol name   = %s\n", bfd_asymbol_name (symbol));   printf ("DEBUG: The symbol->value = 0x%08x\n", symbol->value);   printf ("DEBUG: The vma           = 0x%08x\n", symbol->section->output_section->vma);   printf ("DEBUG: The output_offset = 0x%08x\n", symbol->section->output_offset);   printf ("DEBUG: The input_vma     = 0x%08x\n", input_section->output_section->vma);   printf ("DEBUG: The input_offset  = 0x%08x\n", input_section->output_offset);   printf ("DEBUG: The input_name    = %s\n", input_section->name);   printf ("DEBUG: The addend        = 0x%08x\n", reloc_entry->addend);
endif|#
directive|endif
if|if
condition|(
name|abs
argument_list|(
operator|(
name|int
operator|)
name|val
argument_list|)
operator|>
literal|0x01FFFFFF
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|insn
operator|=
operator|(
name|insn
operator|&
literal|0xFC000000
operator|)
operator||
operator|(
name|val
operator|&
literal|0x03FFFFFF
operator|)
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|insn
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* A mapping from BFD reloc types to DLX ELF reloc types.    Stolen from elf32-mips.c.     More about this table - for dlx elf relocation we do not really    need this table, if we have a rtype defined in this table will    caused tc_gen_relocate confused and die on us, but if we remove    this table it will caused more problem, so for now simple solution    is to remove those entries which may cause problem.  */
end_comment

begin_struct
struct|struct
name|elf_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|enum
name|elf_dlx_reloc_type
name|elf_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf_reloc_map
name|dlx_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_DLX_NONE
block|}
block|,
block|{
name|BFD_RELOC_16
block|,
name|R_DLX_RELOC_16
block|}
block|,
if|#
directive|if
literal|0
block|{ BFD_RELOC_DLX_JMP26,      R_DLX_RELOC_26_PCREL },
endif|#
directive|endif
block|{
name|BFD_RELOC_32
block|,
name|R_DLX_RELOC_32
block|}
block|,
block|{
name|BFD_RELOC_DLX_HI16_S
block|,
name|R_DLX_RELOC_16_HI
block|}
block|,
block|{
name|BFD_RELOC_DLX_LO16
block|,
name|R_DLX_RELOC_16_LO
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_INHERIT
block|,
name|R_DLX_GNU_VTINHERIT
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_ENTRY
block|,
name|R_DLX_GNU_VTENTRY
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Look through the relocs for a section during the first phase.    Since we don't do .gots or .plts, we just need to consider the    virtual table relocs for gc.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|elf32_dlx_check_relocs
parameter_list|(
name|abfd
parameter_list|,
name|info
parameter_list|,
name|sec
parameter_list|,
name|relocs
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|relocs
decl_stmt|;
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
decl_stmt|,
modifier|*
modifier|*
name|sym_hashes_end
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|rel
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|rel_end
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
name|abfd
argument_list|)
operator|->
name|symtab_hdr
expr_stmt|;
name|sym_hashes
operator|=
name|elf_sym_hashes
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|sym_hashes_end
operator|=
name|sym_hashes
operator|+
name|symtab_hdr
operator|->
name|sh_size
operator|/
sizeof|sizeof
argument_list|(
name|Elf32_External_Sym
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|elf_bad_symtab
argument_list|(
name|abfd
argument_list|)
condition|)
name|sym_hashes_end
operator|-=
name|symtab_hdr
operator|->
name|sh_info
expr_stmt|;
name|rel_end
operator|=
name|relocs
operator|+
name|sec
operator|->
name|reloc_count
expr_stmt|;
for|for
control|(
name|rel
operator|=
name|relocs
init|;
name|rel
operator|<
name|rel_end
condition|;
name|rel
operator|++
control|)
block|{
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|unsigned
name|long
name|r_symndx
decl_stmt|;
name|r_symndx
operator|=
name|ELF32_R_SYM
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
expr_stmt|;
if|if
condition|(
name|r_symndx
operator|<
name|symtab_hdr
operator|->
name|sh_info
condition|)
name|h
operator|=
name|NULL
expr_stmt|;
else|else
name|h
operator|=
name|sym_hashes
index|[
name|r_symndx
operator|-
name|symtab_hdr
operator|->
name|sh_info
index|]
expr_stmt|;
switch|switch
condition|(
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
condition|)
block|{
comment|/* This relocation describes the C++ object vtable hierarchy.            Reconstruct it for later use during GC.  */
case|case
name|R_DLX_GNU_VTINHERIT
case|:
if|if
condition|(
operator|!
name|bfd_elf_gc_record_vtinherit
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|,
name|h
argument_list|,
name|rel
operator|->
name|r_offset
argument_list|)
condition|)
return|return
name|FALSE
return|;
break|break;
comment|/* This relocation describes which C++ vtable entries are actually            used.  Record for later use during GC.  */
case|case
name|R_DLX_GNU_VTENTRY
case|:
if|if
condition|(
operator|!
name|bfd_elf_gc_record_vtentry
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|,
name|h
argument_list|,
name|rel
operator|->
name|r_addend
argument_list|)
condition|)
return|return
name|FALSE
return|;
break|break;
block|}
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Given a BFD reloc type, return a howto structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_dlx_reloc_type_lookup
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
name|dlx_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|elf_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|dlx_reloc_map
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
name|dlx_elf_howto_table
index|[
operator|(
name|int
operator|)
name|dlx_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
index|]
return|;
switch|switch
condition|(
name|code
condition|)
block|{
default|default:
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
case|case
name|BFD_RELOC_16_PCREL_S2
case|:
return|return
operator|&
name|elf_dlx_gnu_rel16_s2
return|;
case|case
name|BFD_RELOC_DLX_JMP26
case|:
return|return
operator|&
name|elf_dlx_gnu_rel26_s2
return|;
case|case
name|BFD_RELOC_HI16_S
case|:
return|return
operator|&
name|elf_dlx_reloc_16_hi
return|;
case|case
name|BFD_RELOC_LO16
case|:
return|return
operator|&
name|elf_dlx_reloc_16_lo
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|dlx_rtype_to_howto
parameter_list|(
name|r_type
parameter_list|)
name|unsigned
name|int
name|r_type
decl_stmt|;
block|{
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|R_DLX_RELOC_16_PCREL
case|:
return|return
operator|&
name|elf_dlx_gnu_rel16_s2
return|;
break|break;
case|case
name|R_DLX_RELOC_26_PCREL
case|:
return|return
operator|&
name|elf_dlx_gnu_rel26_s2
return|;
break|break;
case|case
name|R_DLX_RELOC_16_HI
case|:
return|return
operator|&
name|elf_dlx_reloc_16_hi
return|;
break|break;
case|case
name|R_DLX_RELOC_16_LO
case|:
return|return
operator|&
name|elf_dlx_reloc_16_lo
return|;
break|break;
default|default:
name|BFD_ASSERT
argument_list|(
name|r_type
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_DLX_max
argument_list|)
expr_stmt|;
return|return
operator|&
name|dlx_elf_howto_table
index|[
name|r_type
index|]
return|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|void
name|elf32_dlx_info_to_howto
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
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|dst
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|elf32_dlx_info_to_howto_rel
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
name|Elf_Internal_Rela
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
name|cache_ptr
operator|->
name|howto
operator|=
name|dlx_rtype_to_howto
argument_list|(
name|r_type
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_dlx_big_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-dlx"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_dlx
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_DLX
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|1
end_define

begin_comment
comment|/* FIXME: This number is wrong,  It should be the page size in bytes.  */
end_comment

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

