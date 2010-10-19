begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Motorola 68HC12-specific support for 32-bit ELF    Copyright 1999, 2000, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Stephane Carrez (stcarrez@nerim.fr)    (Heavily copied from the D10V port by Martin Hunt (hunt@cygnus.com))  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"bfdlink.h"
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
file|"elf32-m68hc1x.h"
end_include

begin_include
include|#
directive|include
file|"elf/m68hc11.h"
end_include

begin_include
include|#
directive|include
file|"opcode/m68hc11.h"
end_include

begin_comment
comment|/* Relocation functions.  */
end_comment

begin_function_decl
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_reloc_code_real_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|m68hc11_info_to_howto_rel
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|Elf_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Trampoline generation.  */
end_comment

begin_function_decl
specifier|static
name|bfd_boolean
name|m68hc12_elf_size_one_stub
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
name|gen_entry
parameter_list|,
name|void
modifier|*
name|in_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|m68hc12_elf_build_one_stub
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
name|gen_entry
parameter_list|,
name|void
modifier|*
name|in_arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|struct
name|bfd_link_hash_table
modifier|*
name|m68hc12_elf_bfd_link_hash_table_create
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|bfd_boolean
name|m68hc12_elf_set_mach_from_flags
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use REL instead of RELA to save space */
end_comment

begin_define
define|#
directive|define
name|USE_REL
value|1
end_define

begin_comment
comment|/* The 68HC12 microcontroler has a memory bank switching system    with a 16Kb window in the 64Kb address space.  The extended memory    is mapped in the 16Kb window (at 0x8000).  The page register controls    which 16Kb bank is mapped.  The call/rtc instructions take care of    bank switching in function calls/returns.     For GNU Binutils to work, we consider there is a physical memory    at 0..0x0ffff and a kind of virtual memory above that.  Symbols    in virtual memory have their addresses treated in a special way    when disassembling and when linking.     For the linker to work properly, we must always relocate the virtual    memory as if it is mapped at 0x8000.  When a 16-bit relocation is    made in the virtual memory, we check that it does not cross the    memory bank where it is used.  This would involve a page change    which would be wrong.  The 24-bit relocation is for that and it    treats the address as a physical address + page number.   					Banked 					Address Space                                         |               |       Page n 					+---------------+ 0x1010000                                         |               |                                         | jsr _foo      |                                         | ..            |       Page 3                                         | _foo:         | 					+---------------+ 0x100C000 					|	        |                                         | call _bar     | 					| ..	        |	Page 2 					| _bar:	        | 					+---------------+ 0x1008000 				/------>|	        | 				|	| call _foo     |	Page 1 				|	|       	| 				|	+---------------+ 0x1004000       Physical			|	|	        |       Address Space		|	|	        |	Page 0 				|	|	        |     +-----------+ 0x00FFFF	|	+---------------+ 0x1000000     |		|		|     | call _foo	|		|     |		|		|     +-----------+ 0x00BFFF -+---/     |		|           |     |		|	    |     |		| 16K	    |     |		|	    |     +-----------+ 0x008000 -+     |		|     |		|     =		=     |		|     |		|     +-----------+ 0000      The 'call _foo' must be relocated with page 3 and 16-bit address    mapped at 0x8000.     The 3-bit and 16-bit PC rel relocation is only used by 68HC12.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_m68hc11_howto_table
index|[]
init|=
block|{
comment|/* This reloc does nothing.  */
name|HOWTO
argument_list|(
name|R_M68HC11_NONE
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
literal|"R_M68HC12_NONE"
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
comment|/* A 8 bit absolute relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_8
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00ff
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 8 bit absolute relocation (upper address) */
name|HOWTO
argument_list|(
name|R_M68HC11_HI8
argument_list|,
comment|/* type */
literal|8
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_HI8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00ff
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 8 bit absolute relocation (upper address) */
name|HOWTO
argument_list|(
name|R_M68HC11_LO8
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
literal|"R_M68HC12_LO8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00ff
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 8 bit PC-rel relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_PCREL_8
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
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_PCREL_8"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00ff
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16 bit absolute relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_16
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
comment|/*bitfield */
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_16"
argument_list|,
comment|/* name */
name|FALSE
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
comment|/* A 32 bit absolute relocation.  This one is never used for the      code relocation.  It's used by gas for -gstabs generation.  */
name|HOWTO
argument_list|(
name|R_M68HC11_32
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
literal|"R_M68HC12_32"
argument_list|,
comment|/* name */
name|FALSE
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
comment|/* A 3 bit absolute relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_3B
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|3
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
literal|"R_M68HC12_4B"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x003
argument_list|,
comment|/* src_mask */
literal|0x003
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16 bit PC-rel relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_PCREL_16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_PCREL_16"
argument_list|,
comment|/* name */
name|FALSE
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
block|,
comment|/* pcrel_offset */
comment|/* GNU extension to record C++ vtable hierarchy */
name|HOWTO
argument_list|(
name|R_M68HC11_GNU_VTINHERIT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
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
literal|"R_M68HC11_GNU_VTINHERIT"
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
name|R_M68HC11_GNU_VTENTRY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
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
name|_bfd_elf_rel_vtable_reloc_fn
argument_list|,
comment|/* special_function */
literal|"R_M68HC11_GNU_VTENTRY"
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
comment|/* A 24 bit relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_24
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|24
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
name|m68hc11_elf_special_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_24"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xffffff
argument_list|,
comment|/* src_mask */
literal|0xffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16-bit low relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_LO16
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
name|m68hc11_elf_special_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_LO16"
argument_list|,
comment|/* name */
name|FALSE
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
comment|/* A page relocation */
name|HOWTO
argument_list|(
name|R_M68HC11_PAGE
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
name|m68hc11_elf_special_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_PAGE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00ff
argument_list|,
comment|/* src_mask */
literal|0x00ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|14
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|15
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|16
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|17
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|18
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|19
argument_list|)
block|,
comment|/* Mark beginning of a jump instruction (any form).  */
name|HOWTO
argument_list|(
name|R_M68HC11_RL_JUMP
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
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
name|m68hc11_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_RL_JUMP"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Mark beginning of Gcc relaxation group instruction.  */
name|HOWTO
argument_list|(
name|R_M68HC11_RL_GROUP
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
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
name|m68hc11_elf_ignore_reloc
argument_list|,
comment|/* special_function */
literal|"R_M68HC12_RL_GROUP"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map BFD reloc types to M68HC11 ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|m68hc11_reloc_map
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
name|m68hc11_reloc_map
name|m68hc11_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_M68HC11_NONE
block|,}
block|,
block|{
name|BFD_RELOC_8
block|,
name|R_M68HC11_8
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_HI8
block|,
name|R_M68HC11_HI8
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_LO8
block|,
name|R_M68HC11_LO8
block|}
block|,
block|{
name|BFD_RELOC_8_PCREL
block|,
name|R_M68HC11_PCREL_8
block|}
block|,
block|{
name|BFD_RELOC_16_PCREL
block|,
name|R_M68HC11_PCREL_16
block|}
block|,
block|{
name|BFD_RELOC_16
block|,
name|R_M68HC11_16
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_M68HC11_32
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_3B
block|,
name|R_M68HC11_3B
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_INHERIT
block|,
name|R_M68HC11_GNU_VTINHERIT
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_ENTRY
block|,
name|R_M68HC11_GNU_VTENTRY
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_LO16
block|,
name|R_M68HC11_LO16
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_PAGE
block|,
name|R_M68HC11_PAGE
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_24
block|,
name|R_M68HC11_24
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_RL_JUMP
block|,
name|R_M68HC11_RL_JUMP
block|}
block|,
block|{
name|BFD_RELOC_M68HC11_RL_GROUP
block|,
name|R_M68HC11_RL_GROUP
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
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|m68hc11_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|m68hc11_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|m68hc11_reloc_map
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
name|elf_m68hc11_howto_table
index|[
name|m68hc11_reloc_map
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
comment|/* Set the howto pointer for an M68HC11 ELF reloc.  */
end_comment

begin_function
specifier|static
name|void
name|m68hc11_info_to_howto_rel
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
name|R_M68HC11_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
operator|&
name|elf_m68hc11_howto_table
index|[
name|r_type
index|]
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Far trampoline generation.  */
end_comment

begin_comment
comment|/* Build a 68HC12 trampoline stub.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|m68hc12_elf_build_one_stub
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
name|gen_entry
parameter_list|,
name|void
modifier|*
name|in_arg
parameter_list|)
block|{
name|struct
name|elf32_m68hc11_stub_hash_entry
modifier|*
name|stub_entry
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|struct
name|m68hc11_elf_link_hash_table
modifier|*
name|htab
decl_stmt|;
name|asection
modifier|*
name|stub_sec
decl_stmt|;
name|bfd
modifier|*
name|stub_bfd
decl_stmt|;
name|bfd_byte
modifier|*
name|loc
decl_stmt|;
name|bfd_vma
name|sym_value
decl_stmt|,
name|phys_page
decl_stmt|,
name|phys_addr
decl_stmt|;
comment|/* Massage our args to the form they really have.  */
name|stub_entry
operator|=
operator|(
expr|struct
name|elf32_m68hc11_stub_hash_entry
operator|*
operator|)
name|gen_entry
expr_stmt|;
name|info
operator|=
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|)
name|in_arg
expr_stmt|;
name|htab
operator|=
name|m68hc11_elf_hash_table
argument_list|(
name|info
argument_list|)
expr_stmt|;
name|stub_sec
operator|=
name|stub_entry
operator|->
name|stub_sec
expr_stmt|;
comment|/* Make a note of the offset within the stubs for this entry.  */
name|stub_entry
operator|->
name|stub_offset
operator|=
name|stub_sec
operator|->
name|size
expr_stmt|;
name|stub_sec
operator|->
name|size
operator|+=
literal|7
expr_stmt|;
name|loc
operator|=
name|stub_sec
operator|->
name|contents
operator|+
name|stub_entry
operator|->
name|stub_offset
expr_stmt|;
name|stub_bfd
operator|=
name|stub_sec
operator|->
name|owner
expr_stmt|;
comment|/* Create the trampoline call stub:       ldy #%addr(symbol)      call %page(symbol), __trampoline    */
name|sym_value
operator|=
operator|(
name|stub_entry
operator|->
name|target_value
operator|+
name|stub_entry
operator|->
name|target_section
operator|->
name|output_offset
operator|+
name|stub_entry
operator|->
name|target_section
operator|->
name|output_section
operator|->
name|vma
operator|)
expr_stmt|;
name|phys_addr
operator|=
name|m68hc11_phys_addr
argument_list|(
operator|&
name|htab
operator|->
name|pinfo
argument_list|,
name|sym_value
argument_list|)
expr_stmt|;
name|phys_page
operator|=
name|m68hc11_phys_page
argument_list|(
operator|&
name|htab
operator|->
name|pinfo
argument_list|,
name|sym_value
argument_list|)
expr_stmt|;
comment|/* ldy #%page(sym) */
name|bfd_put_8
argument_list|(
name|stub_bfd
argument_list|,
literal|0xCD
argument_list|,
name|loc
argument_list|)
expr_stmt|;
name|bfd_put_16
argument_list|(
name|stub_bfd
argument_list|,
name|phys_addr
argument_list|,
name|loc
operator|+
literal|1
argument_list|)
expr_stmt|;
name|loc
operator|+=
literal|3
expr_stmt|;
comment|/* call %page(sym), __trampoline  */
name|bfd_put_8
argument_list|(
name|stub_bfd
argument_list|,
literal|0x4a
argument_list|,
name|loc
argument_list|)
expr_stmt|;
name|bfd_put_16
argument_list|(
name|stub_bfd
argument_list|,
name|htab
operator|->
name|pinfo
operator|.
name|trampoline_addr
argument_list|,
name|loc
operator|+
literal|1
argument_list|)
expr_stmt|;
name|bfd_put_8
argument_list|(
name|stub_bfd
argument_list|,
name|phys_page
argument_list|,
name|loc
operator|+
literal|3
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* As above, but don't actually build the stub.  Just bump offset so    we know stub section sizes.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|m68hc12_elf_size_one_stub
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
name|gen_entry
parameter_list|,
name|void
modifier|*
name|in_arg
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|struct
name|elf32_m68hc11_stub_hash_entry
modifier|*
name|stub_entry
decl_stmt|;
comment|/* Massage our args to the form they really have.  */
name|stub_entry
operator|=
operator|(
expr|struct
name|elf32_m68hc11_stub_hash_entry
operator|*
operator|)
name|gen_entry
expr_stmt|;
name|stub_entry
operator|->
name|stub_sec
operator|->
name|size
operator|+=
literal|7
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Create a 68HC12 ELF linker hash table.  */
end_comment

begin_function
specifier|static
name|struct
name|bfd_link_hash_table
modifier|*
name|m68hc12_elf_bfd_link_hash_table_create
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
name|struct
name|m68hc11_elf_link_hash_table
modifier|*
name|ret
decl_stmt|;
name|ret
operator|=
name|m68hc11_elf_hash_table_create
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|==
operator|(
expr|struct
name|m68hc11_elf_link_hash_table
operator|*
operator|)
name|NULL
condition|)
return|return
name|NULL
return|;
name|ret
operator|->
name|size_one_stub
operator|=
name|m68hc12_elf_size_one_stub
expr_stmt|;
name|ret
operator|->
name|build_one_stub
operator|=
name|m68hc12_elf_build_one_stub
expr_stmt|;
return|return
operator|&
name|ret
operator|->
name|root
operator|.
name|root
return|;
block|}
end_function

begin_escape
end_escape

begin_function
specifier|static
name|bfd_boolean
name|m68hc12_elf_set_mach_from_flags
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
name|flagword
name|flags
init|=
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
decl_stmt|;
switch|switch
condition|(
name|flags
operator|&
name|EF_M68HC11_MACH_MASK
condition|)
block|{
case|case
name|EF_M68HC12_MACH
case|:
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_m68hc12
argument_list|,
name|bfd_mach_m6812
argument_list|)
expr_stmt|;
break|break;
case|case
name|EF_M68HCS12_MACH
case|:
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_m68hc12
argument_list|,
name|bfd_mach_m6812s
argument_list|)
expr_stmt|;
break|break;
case|case
name|EF_M68HC11_GENERIC
case|:
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_m68hc12
argument_list|,
name|bfd_mach_m6812_default
argument_list|)
expr_stmt|;
break|break;
default|default:
return|return
name|FALSE
return|;
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Specific sections:    - The .page0 is a data section that is mapped in [0x0000..0x00FF].      Page0 accesses are faster on the M68HC12.    - The .vectors is the section that represents the interrupt      vectors.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|bfd_elf_special_section
name|elf32_m68hc12_special_sections
index|[]
init|=
block|{
block|{
literal|".eeprom"
block|,
literal|7
block|,
literal|0
block|,
name|SHT_PROGBITS
block|,
name|SHF_ALLOC
operator|+
name|SHF_WRITE
block|}
block|,
block|{
literal|".page0"
block|,
literal|6
block|,
literal|0
block|,
name|SHT_PROGBITS
block|,
name|SHF_ALLOC
operator|+
name|SHF_WRITE
block|}
block|,
block|{
literal|".softregs"
block|,
literal|9
block|,
literal|0
block|,
name|SHT_NOBITS
block|,
name|SHF_ALLOC
operator|+
name|SHF_WRITE
block|}
block|,
block|{
literal|".vectors"
block|,
literal|8
block|,
literal|0
block|,
name|SHT_PROGBITS
block|,
name|SHF_ALLOC
block|}
block|,
block|{
name|NULL
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_m68hc12
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_68HC12
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
name|TARGET_BIG_SYM
value|bfd_elf32_m68hc12_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-m68hc12"
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
value|m68hc11_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_gc_mark_hook
value|elf32_m68hc11_gc_mark_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_gc_sweep_hook
value|elf32_m68hc11_gc_sweep_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_check_relocs
value|elf32_m68hc11_check_relocs
end_define

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|elf32_m68hc11_relocate_section
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|m68hc12_elf_set_mach_from_flags
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|0
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
name|elf_backend_special_sections
value|elf32_m68hc12_special_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_post_process_headers
value|elf32_m68hc11_post_process_headers
end_define

begin_define
define|#
directive|define
name|elf_backend_add_symbol_hook
value|elf32_m68hc11_add_symbol_hook
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_create
define|\
value|m68hc12_elf_bfd_link_hash_table_create
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_free
define|\
value|m68hc11_elf_bfd_link_hash_table_free
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_merge_private_bfd_data
define|\
value|_bfd_m68hc11_elf_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_set_private_flags
value|_bfd_m68hc11_elf_set_private_flags
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_print_private_bfd_data
define|\
value|_bfd_m68hc11_elf_print_private_bfd_data
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

