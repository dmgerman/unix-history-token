begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end data structures for a.out (and similar) files.    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003    Free Software Foundation, Inc.    Written by Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBAOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LIBAOUT_H
end_define

begin_comment
comment|/* We try to encapsulate the differences in the various a.out file    variants in a few routines, and otherwise share large masses of code.    This means we only have to fix bugs in one place, most of the time.  */
end_comment

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_comment
comment|/* Macros for accessing components in an aout header.  */
end_comment

begin_define
define|#
directive|define
name|H_PUT_64
value|bfd_h_put_64
end_define

begin_define
define|#
directive|define
name|H_PUT_32
value|bfd_h_put_32
end_define

begin_define
define|#
directive|define
name|H_PUT_16
value|bfd_h_put_16
end_define

begin_define
define|#
directive|define
name|H_PUT_8
value|bfd_h_put_8
end_define

begin_define
define|#
directive|define
name|H_PUT_S64
value|bfd_h_put_signed_64
end_define

begin_define
define|#
directive|define
name|H_PUT_S32
value|bfd_h_put_signed_32
end_define

begin_define
define|#
directive|define
name|H_PUT_S16
value|bfd_h_put_signed_16
end_define

begin_define
define|#
directive|define
name|H_PUT_S8
value|bfd_h_put_signed_8
end_define

begin_define
define|#
directive|define
name|H_GET_64
value|bfd_h_get_64
end_define

begin_define
define|#
directive|define
name|H_GET_32
value|bfd_h_get_32
end_define

begin_define
define|#
directive|define
name|H_GET_16
value|bfd_h_get_16
end_define

begin_define
define|#
directive|define
name|H_GET_8
value|bfd_h_get_8
end_define

begin_define
define|#
directive|define
name|H_GET_S64
value|bfd_h_get_signed_64
end_define

begin_define
define|#
directive|define
name|H_GET_S32
value|bfd_h_get_signed_32
end_define

begin_define
define|#
directive|define
name|H_GET_S16
value|bfd_h_get_signed_16
end_define

begin_define
define|#
directive|define
name|H_GET_S8
value|bfd_h_get_signed_8
end_define

begin_comment
comment|/* Parameterize the a.out code based on whether it is being built    for a 32-bit architecture or a 64-bit architecture.  */
end_comment

begin_comment
comment|/* Do not "beautify" the CONCAT* macro args.  Traditional C will not    remove whitespace added here, and thus will fail to concatenate    the tokens.  */
end_comment

begin_if
if|#
directive|if
name|ARCH_SIZE
operator|==
literal|64
end_if

begin_define
define|#
directive|define
name|GET_WORD
value|H_GET_64
end_define

begin_define
define|#
directive|define
name|GET_SWORD
value|H_GET_S64
end_define

begin_define
define|#
directive|define
name|GET_MAGIC
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_WORD
value|H_PUT_64
end_define

begin_define
define|#
directive|define
name|PUT_MAGIC
value|H_PUT_32
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NAME
end_ifndef

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (x,_64_,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JNAME
parameter_list|(
name|x
parameter_list|)
value|CONCAT2 (x,_64)
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|ARCH_SIZE
operator|==
literal|16
end_if

begin_define
define|#
directive|define
name|GET_WORD
value|H_GET_16
end_define

begin_define
define|#
directive|define
name|GET_SWORD
value|H_GET_S16
end_define

begin_define
define|#
directive|define
name|GET_MAGIC
value|H_GET_16
end_define

begin_define
define|#
directive|define
name|PUT_WORD
value|H_PUT_16
end_define

begin_define
define|#
directive|define
name|PUT_MAGIC
value|H_PUT_16
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NAME
end_ifndef

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (x,_16_,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JNAME
parameter_list|(
name|x
parameter_list|)
value|CONCAT2 (x,_16)
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ARCH_SIZE == 32 */
end_comment

begin_define
define|#
directive|define
name|GET_WORD
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|GET_SWORD
value|H_GET_S32
end_define

begin_define
define|#
directive|define
name|GET_MAGIC
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|PUT_WORD
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|PUT_MAGIC
value|H_PUT_32
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NAME
end_ifndef

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (x,_32_,y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|JNAME
parameter_list|(
name|x
parameter_list|)
value|CONCAT2 (x,_32)
end_define

begin_define
define|#
directive|define
name|BYTES_IN_WORD
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCH_SIZE==32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCH_SIZE==64 */
end_comment

begin_comment
comment|/* Declare at file level, since used in parameter lists, which have    weird scope.  */
end_comment

begin_struct_decl
struct_decl|struct
name|external_exec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|external_nlist
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reloc_ext_external
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reloc_std_external
struct_decl|;
end_struct_decl

begin_escape
end_escape

begin_comment
comment|/* a.out backend linker hash table entries.  */
end_comment

begin_struct
struct|struct
name|aout_link_hash_entry
block|{
name|struct
name|bfd_link_hash_entry
name|root
decl_stmt|;
comment|/* Whether this symbol has been written out.  */
name|bfd_boolean
name|written
decl_stmt|;
comment|/* Symbol index in output file.  */
name|int
name|indx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* a.out backend linker hash table.  */
end_comment

begin_struct
struct|struct
name|aout_link_hash_table
block|{
name|struct
name|bfd_link_hash_table
name|root
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in an a.out link hash table.  */
end_comment

begin_define
define|#
directive|define
name|aout_link_hash_lookup
parameter_list|(
name|table
parameter_list|,
name|string
parameter_list|,
name|create
parameter_list|,
name|copy
parameter_list|,
name|follow
parameter_list|)
define|\
value|((struct aout_link_hash_entry *) \    bfd_link_hash_lookup (&(table)->root, (string), (create), (copy), (follow)))
end_define

begin_comment
comment|/* Traverse an a.out link hash table.  */
end_comment

begin_define
define|#
directive|define
name|aout_link_hash_traverse
parameter_list|(
name|table
parameter_list|,
name|func
parameter_list|,
name|info
parameter_list|)
define|\
value|(bfd_link_hash_traverse						\    (&(table)->root,							\     (bfd_boolean (*) PARAMS ((struct bfd_link_hash_entry *, PTR))) (func), \     (info)))
end_define

begin_comment
comment|/* Get the a.out link hash table from the info structure.  This is    just a cast.  */
end_comment

begin_define
define|#
directive|define
name|aout_hash_table
parameter_list|(
name|p
parameter_list|)
value|((struct aout_link_hash_table *) ((p)->hash))
end_define

begin_escape
end_escape

begin_comment
comment|/* Back-end information for various a.out targets.  */
end_comment

begin_struct
struct|struct
name|aout_backend_data
block|{
comment|/* Are ZMAGIC files mapped contiguously?  If so, the text section may      need more padding, if the segment size (granularity for memory access      control) is larger than the page size.  */
name|unsigned
name|char
name|zmagic_mapped_contiguous
decl_stmt|;
comment|/* If this flag is set, ZMAGIC/NMAGIC file headers get mapped in with the      text section, which starts immediately after the file header.      If not, the text section starts on the next page.  */
name|unsigned
name|char
name|text_includes_header
decl_stmt|;
comment|/* If this flag is set, then if the entry address is not in the      first SEGMENT_SIZE bytes of the text section, it is taken to be      the address of the start of the text section.  This can be useful      for kernels.  */
name|unsigned
name|char
name|entry_is_text_address
decl_stmt|;
comment|/* The value to pass to N_SET_FLAGS.  */
name|unsigned
name|char
name|exec_hdr_flags
decl_stmt|;
comment|/* If the text section VMA isn't specified, and we need an absolute      address, use this as the default.  If we're producing a relocatable      file, zero is always used.  */
comment|/* ?? Perhaps a callback would be a better choice?  Will this do anything      reasonable for a format that handles multiple CPUs with different      load addresses for each?  */
name|bfd_vma
name|default_text_vma
decl_stmt|;
comment|/* Callback for setting the page and segment sizes, if they can't be      trivially determined from the architecture.  */
name|bfd_boolean
argument_list|(
argument|*set_sizes
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* zmagic files only. For go32, the length of the exec header contributes      to the size of the text section in the file for alignment purposes but      does *not* get counted in the length of the text section. */
name|unsigned
name|char
name|exec_header_not_counted
decl_stmt|;
comment|/* Callback from the add symbols phase of the linker code to handle      a dynamic object.  */
name|bfd_boolean
argument_list|(
argument|*add_dynamic_symbols
argument_list|)
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
expr|struct
name|external_nlist
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Callback from the add symbols phase of the linker code to handle      adding a single symbol to the global linker hash table.  */
name|bfd_boolean
argument_list|(
argument|*add_one_symbol
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
name|bfd
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|flagword
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_boolean
operator|,
name|bfd_boolean
operator|,
expr|struct
name|bfd_link_hash_entry
operator|*
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Called to handle linking a dynamic object.  */
name|bfd_boolean
argument_list|(
argument|*link_dynamic_object
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Called for each global symbol being written out by the linker.      This should write out the dynamic symbol information.  */
name|bfd_boolean
argument_list|(
argument|*write_dynamic_symbol
argument_list|)
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
expr|struct
name|aout_link_hash_entry
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* If this callback is not NULL, the linker calls it for each reloc.      RELOC is a pointer to the unswapped reloc.  If *SKIP is set to      TRUE, the reloc will be skipped.  *RELOCATION may be changed to      change the effects of the relocation.  */
name|bfd_boolean
argument_list|(
argument|*check_dynamic_reloc
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
name|info
operator|,
name|bfd
operator|*
name|input_bfd
operator|,
name|asection
operator|*
name|input_section
operator|,
expr|struct
name|aout_link_hash_entry
operator|*
name|h
operator|,
name|PTR
name|reloc
operator|,
name|bfd_byte
operator|*
name|contents
operator|,
name|bfd_boolean
operator|*
name|skip
operator|,
name|bfd_vma
operator|*
name|relocation
operator|)
argument_list|)
expr_stmt|;
comment|/* Called at the end of a link to finish up any dynamic linking      information.  */
name|bfd_boolean
argument_list|(
argument|*finish_dynamic_link
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|aout_backend_info
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((const struct aout_backend_data *)((abfd)->xvec->backend_data))
end_define

begin_comment
comment|/* This is the layout in memory of a "struct exec" while we process it.    All 'lengths' are given as a number of bytes.    All 'alignments' are for relinkable files only;  an alignment of 	'n' indicates the corresponding segment must begin at an 	address that is a multiple of (2**n).  */
end_comment

begin_struct
struct|struct
name|internal_exec
block|{
name|long
name|a_info
decl_stmt|;
comment|/* Magic number and flags, packed */
name|bfd_vma
name|a_text
decl_stmt|;
comment|/* length of text, in bytes  */
name|bfd_vma
name|a_data
decl_stmt|;
comment|/* length of data, in bytes  */
name|bfd_vma
name|a_bss
decl_stmt|;
comment|/* length of uninitialized data area in mem */
name|bfd_vma
name|a_syms
decl_stmt|;
comment|/* length of symbol table data in file */
name|bfd_vma
name|a_entry
decl_stmt|;
comment|/* start address */
name|bfd_vma
name|a_trsize
decl_stmt|;
comment|/* length of text's relocation info, in bytes */
name|bfd_vma
name|a_drsize
decl_stmt|;
comment|/* length of data's relocation info, in bytes */
comment|/* Added for i960 */
name|bfd_vma
name|a_tload
decl_stmt|;
comment|/* Text runtime load address */
name|bfd_vma
name|a_dload
decl_stmt|;
comment|/* Data runtime load address */
name|unsigned
name|char
name|a_talign
decl_stmt|;
comment|/* Alignment of text segment */
name|unsigned
name|char
name|a_dalign
decl_stmt|;
comment|/* Alignment of data segment */
name|unsigned
name|char
name|a_balign
decl_stmt|;
comment|/* Alignment of bss segment */
name|char
name|a_relaxable
decl_stmt|;
comment|/* Enough info for linker relax */
block|}
struct|;
end_struct

begin_comment
comment|/* Magic number is written< MSB> 3130292827262524232221201918171615141312111009080706050403020100< FLAGS>< MACHINE TYPE><  MAGIC NUMBER> */
end_comment

begin_comment
comment|/* Magic number for NetBSD is<MSB> 3130292827262524232221201918171615141312111009080706050403020100< FLAGS>< MACHINE TYPE><  MAGIC NUMBER> */
end_comment

begin_enum
enum|enum
name|machine_type
block|{
name|M_UNKNOWN
init|=
literal|0
block|,
name|M_68010
init|=
literal|1
block|,
name|M_68020
init|=
literal|2
block|,
name|M_SPARC
init|=
literal|3
block|,
comment|/* Skip a bunch so we don't run into any of SUN's numbers.  */
comment|/* Make these up for the ns32k.  */
name|M_NS32032
init|=
operator|(
literal|64
operator|)
block|,
comment|/* ns32032 running ? */
name|M_NS32532
init|=
operator|(
literal|64
operator|+
literal|5
operator|)
block|,
comment|/* ns32532 running mach */
name|M_386
init|=
literal|100
block|,
name|M_29K
init|=
literal|101
block|,
comment|/* AMD 29000 */
name|M_386_DYNIX
init|=
literal|102
block|,
comment|/* Sequent running dynix */
name|M_ARM
init|=
literal|103
block|,
comment|/* Advanced Risc Machines ARM */
name|M_SPARCLET
init|=
literal|131
block|,
comment|/* SPARClet = M_SPARC + 128 */
name|M_386_NETBSD
init|=
literal|134
block|,
comment|/* NetBSD/i386 binary */
name|M_68K_NETBSD
init|=
literal|135
block|,
comment|/* NetBSD/m68k binary */
name|M_68K4K_NETBSD
init|=
literal|136
block|,
comment|/* NetBSD/m68k4k binary */
name|M_532_NETBSD
init|=
literal|137
block|,
comment|/* NetBSD/ns32k binary */
name|M_SPARC_NETBSD
init|=
literal|138
block|,
comment|/* NetBSD/sparc binary */
name|M_PMAX_NETBSD
init|=
literal|139
block|,
comment|/* NetBSD/pmax (MIPS little-endian) binary */
name|M_VAX_NETBSD
init|=
literal|140
block|,
comment|/* NetBSD/vax binary */
name|M_ALPHA_NETBSD
init|=
literal|141
block|,
comment|/* NetBSD/alpha binary */
name|M_ARM6_NETBSD
init|=
literal|143
block|,
comment|/* NetBSD/arm32 binary */
name|M_SPARCLET_1
init|=
literal|147
block|,
comment|/* 0x93, reserved */
name|M_VAX4K_NETBSD
init|=
literal|150
block|,
comment|/* NetBSD/vax 4K pages binary */
name|M_MIPS1
init|=
literal|151
block|,
comment|/* MIPS R2000/R3000 binary */
name|M_MIPS2
init|=
literal|152
block|,
comment|/* MIPS R4000/R6000 binary */
name|M_SPARCLET_2
init|=
literal|163
block|,
comment|/* 0xa3, reserved */
name|M_SPARCLET_3
init|=
literal|179
block|,
comment|/* 0xb3, reserved */
name|M_SPARCLET_4
init|=
literal|195
block|,
comment|/* 0xc3, reserved */
name|M_HP200
init|=
literal|200
block|,
comment|/* HP 200 (68010) BSD binary */
name|M_HP300
init|=
operator|(
literal|300
operator|%
literal|256
operator|)
block|,
comment|/* HP 300 (68020+68881) BSD binary */
name|M_HPUX
init|=
operator|(
literal|0x20c
operator|%
literal|256
operator|)
block|,
comment|/* HP 200/300 HPUX binary */
name|M_SPARCLET_5
init|=
literal|211
block|,
comment|/* 0xd3, reserved */
name|M_SPARCLET_6
init|=
literal|227
block|,
comment|/* 0xe3, reserved */
comment|/*  M_SPARCLET_7 = 243	/ * 0xf3, reserved */
name|M_SPARCLITE_LE
init|=
literal|243
block|,
name|M_CRIS
init|=
literal|255
comment|/* Axis CRIS binary.  */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_DYNAMIC
parameter_list|(
name|exec
parameter_list|)
value|((exec).a_info& 0x80000000)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|N_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|N_MAGIC
parameter_list|(
name|exec
parameter_list|)
value|((exec).a_info& 0xffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_MACHTYPE
end_ifndef

begin_define
define|#
directive|define
name|N_MACHTYPE
parameter_list|(
name|exec
parameter_list|)
value|((enum machine_type)(((exec).a_info>> 16)& 0xff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|N_FLAGS
parameter_list|(
name|exec
parameter_list|)
value|(((exec).a_info>> 24)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SET_INFO
end_ifndef

begin_define
define|#
directive|define
name|N_SET_INFO
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = ((magic)& 0xffff) \  | (((int)(type)& 0xff)<< 16) \  | (((flags)& 0xff)<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SET_DYNAMIC
end_ifndef

begin_define
define|#
directive|define
name|N_SET_DYNAMIC
parameter_list|(
name|exec
parameter_list|,
name|dynamic
parameter_list|)
define|\
value|((exec).a_info = (dynamic) ? (long) ((exec).a_info | 0x80000000) : \ ((exec).a_info& 0x7fffffff))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SET_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|N_SET_MAGIC
parameter_list|(
name|exec
parameter_list|,
name|magic
parameter_list|)
define|\
value|((exec).a_info = (((exec).a_info& 0xffff0000) | ((magic)& 0xffff)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SET_MACHTYPE
end_ifndef

begin_define
define|#
directive|define
name|N_SET_MACHTYPE
parameter_list|(
name|exec
parameter_list|,
name|machtype
parameter_list|)
define|\
value|((exec).a_info = \  ((exec).a_info&0xff00ffff) | ((((int)(machtype))&0xff)<< 16))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|N_SET_FLAGS
end_ifndef

begin_define
define|#
directive|define
name|N_SET_FLAGS
parameter_list|(
name|exec
parameter_list|,
name|flags
parameter_list|)
define|\
value|((exec).a_info = \  ((exec).a_info&0x00ffffff) | (((flags)& 0xff)<< 24))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|aout_symbol
block|{
name|asymbol
name|symbol
decl_stmt|;
name|short
name|desc
decl_stmt|;
name|char
name|other
decl_stmt|;
name|unsigned
name|char
name|type
decl_stmt|;
block|}
name|aout_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* The `tdata' struct for all a.out-like object file formats.    Various things depend on this struct being around any time an a.out    file is being handled.  An example is dbxread.c in GDB.  */
end_comment

begin_struct
struct|struct
name|aoutdata
block|{
name|struct
name|internal_exec
modifier|*
name|hdr
decl_stmt|;
comment|/* exec file header */
name|aout_symbol_type
modifier|*
name|symbols
decl_stmt|;
comment|/* symtab for input bfd */
comment|/* For ease, we do this.  */
name|asection
modifier|*
name|textsec
decl_stmt|;
name|asection
modifier|*
name|datasec
decl_stmt|;
name|asection
modifier|*
name|bsssec
decl_stmt|;
comment|/* We remember these offsets so that after check_file_format, we have      no dependencies on the particular format of the exec_hdr.  */
name|file_ptr
name|sym_filepos
decl_stmt|;
name|file_ptr
name|str_filepos
decl_stmt|;
comment|/* Size of a relocation entry in external form.  */
name|unsigned
name|reloc_entry_size
decl_stmt|;
comment|/* Size of a symbol table entry in external form.  */
name|unsigned
name|symbol_entry_size
decl_stmt|;
comment|/* Page size - needed for alignment of demand paged files.  */
name|unsigned
name|long
name|page_size
decl_stmt|;
comment|/* Segment size - needed for alignment of demand paged files.  */
name|unsigned
name|long
name|segment_size
decl_stmt|;
comment|/* Zmagic disk block size - need to align the start of the text      section in ZMAGIC binaries.  Normally the same as page_size.  */
name|unsigned
name|long
name|zmagic_disk_block_size
decl_stmt|;
name|unsigned
name|exec_bytes_size
decl_stmt|;
name|unsigned
name|vma_adjusted
range|:
literal|1
decl_stmt|;
comment|/* Used when a bfd supports several highly similar formats.  */
enum|enum
block|{
name|default_format
init|=
literal|0
block|,
comment|/* Used on HP 9000/300 running HP/UX.  See hp300hpux.c.  */
name|gnu_encap_format
block|,
comment|/* Used on Linux, 386BSD, etc.  See include/aout/aout64.h.  */
name|q_magic_format
block|}
name|subformat
enum|;
enum|enum
block|{
name|undecided_magic
init|=
literal|0
block|,
name|z_magic
block|,
name|o_magic
block|,
name|n_magic
block|}
name|magic
enum|;
comment|/* A buffer for find_nearest_line.  */
name|char
modifier|*
name|line_buf
decl_stmt|;
comment|/* The external symbol information.  */
name|struct
name|external_nlist
modifier|*
name|external_syms
decl_stmt|;
name|bfd_size_type
name|external_sym_count
decl_stmt|;
name|bfd_window
name|sym_window
decl_stmt|;
name|char
modifier|*
name|external_strings
decl_stmt|;
name|bfd_size_type
name|external_string_size
decl_stmt|;
name|bfd_window
name|string_window
decl_stmt|;
name|struct
name|aout_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
decl_stmt|;
comment|/* A pointer for shared library information.  */
name|PTR
name|dynamic_info
decl_stmt|;
comment|/* A mapping from local symbols to offsets into the global offset      table, used when linking on SunOS.  This is indexed by the symbol      index.  */
name|bfd_vma
modifier|*
name|local_got_offsets
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|aout_data_struct
block|{
name|struct
name|aoutdata
name|a
decl_stmt|;
name|struct
name|internal_exec
name|e
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|adata
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.aout_data->a)
end_define

begin_define
define|#
directive|define
name|exec_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).hdr)
end_define

begin_define
define|#
directive|define
name|obj_aout_symbols
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).symbols)
end_define

begin_define
define|#
directive|define
name|obj_textsec
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).textsec)
end_define

begin_define
define|#
directive|define
name|obj_datasec
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).datasec)
end_define

begin_define
define|#
directive|define
name|obj_bsssec
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).bsssec)
end_define

begin_define
define|#
directive|define
name|obj_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_str_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).str_filepos)
end_define

begin_define
define|#
directive|define
name|obj_reloc_entry_size
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).reloc_entry_size)
end_define

begin_define
define|#
directive|define
name|obj_symbol_entry_size
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).symbol_entry_size)
end_define

begin_define
define|#
directive|define
name|obj_aout_subformat
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).subformat)
end_define

begin_define
define|#
directive|define
name|obj_aout_external_syms
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).external_syms)
end_define

begin_define
define|#
directive|define
name|obj_aout_external_sym_count
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).external_sym_count)
end_define

begin_define
define|#
directive|define
name|obj_aout_sym_window
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).sym_window)
end_define

begin_define
define|#
directive|define
name|obj_aout_external_strings
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).external_strings)
end_define

begin_define
define|#
directive|define
name|obj_aout_external_string_size
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).external_string_size)
end_define

begin_define
define|#
directive|define
name|obj_aout_string_window
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).string_window)
end_define

begin_define
define|#
directive|define
name|obj_aout_sym_hashes
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).sym_hashes)
end_define

begin_define
define|#
directive|define
name|obj_aout_dynamic_info
parameter_list|(
name|bfd
parameter_list|)
value|(adata(bfd).dynamic_info)
end_define

begin_comment
comment|/* We take the address of the first element of an asymbol to ensure that the    macro is only ever applied to an asymbol.  */
end_comment

begin_define
define|#
directive|define
name|aout_symbol
parameter_list|(
name|asymbol
parameter_list|)
value|((aout_symbol_type *)(&(asymbol)->the_bfd))
end_define

begin_comment
comment|/* Information we keep for each a.out section.  This is currently only    used by the a.out backend linker.  */
end_comment

begin_struct
struct|struct
name|aout_section_data_struct
block|{
comment|/* The unswapped relocation entries for this section.  */
name|PTR
name|relocs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|aout_section_data
parameter_list|(
name|s
parameter_list|)
define|\
value|((struct aout_section_data_struct *) (s)->used_by_bfd)
end_define

begin_define
define|#
directive|define
name|set_aout_section_data
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
define|\
value|((s)->used_by_bfd = (PTR)&(v)->relocs)
end_define

begin_comment
comment|/* Prototype declarations for functions defined in aoutx.h.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|squirt_out_relocs
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|make_sections
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|some_aout_object_p
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct internal_exec *
operator|,
function_decl|const bfd_target *
parameter_list|(
function_decl|*
end_function_decl

begin_expr_stmt
unit|)
operator|(
name|bfd
operator|*
operator|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|mkobject
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|enum
name|machine_type
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|machine_type
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|enum
name|bfd_architecture
decl_stmt|,
name|unsigned
name|long
decl_stmt|,
name|bfd_boolean
modifier|*
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|set_arch_mach
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|enum bfd_architecture
operator|,
function_decl|unsigned long
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|new_section_hook
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|set_section_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|sec_ptr
operator|,
function_decl|const PTR
operator|,
function_decl|file_ptr
operator|,
function_decl|bfd_size_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|make_empty_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|translate_symbol_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|aout_symbol_type *
operator|,
function_decl|struct external_nlist *
operator|,
function_decl|bfd_size_type
operator|,
function_decl|char *
operator|,
function_decl|bfd_size_type
operator|,
function_decl|bfd_boolean
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|slurp_symbol_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|write_syms
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|reclaim_symbol_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_symtab_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|canonicalize_symtab
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asymbol **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_ext_reloc_in
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct reloc_ext_external *
operator|,
function_decl|arelent *
operator|,
function_decl|asymbol **
operator|,
function_decl|bfd_size_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_std_reloc_in
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct reloc_std_external *
operator|,
function_decl|arelent *
operator|,
function_decl|asymbol **
operator|,
function_decl|bfd_size_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|reloc_howto_type
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|reloc_type_lookup
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|bfd_reloc_code_real_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|slurp_reloc_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|sec_ptr
operator|,
function_decl|asymbol **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|canonicalize_reloc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|sec_ptr
operator|,
function_decl|arelent **
operator|,
function_decl|asymbol **
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_reloc_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|sec_ptr
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|reclaim_reloc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|sec_ptr
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|alent
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_lineno
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asymbol *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|print_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|PTR
operator|,
function_decl|asymbol *
operator|,
function_decl|bfd_print_symbol_type
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_symbol_info
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asymbol *
operator|,
function_decl|symbol_info *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|find_nearest_line
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|asection *
operator|,
function_decl|asymbol **
operator|,
function_decl|bfd_vma
operator|,
function_decl|const char **
operator|,
function_decl|const char **
operator|,
function_decl|unsigned int *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|long
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|read_minisymbols
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|bfd_boolean
operator|,
function_decl|PTR *
operator|,
function_decl|unsigned int *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|minisymbol_to_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|bfd_boolean
operator|,
function_decl|const PTR
operator|,
function_decl|asymbol *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|sizeof_headers
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|bfd_boolean
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|adjust_sizes_and_vmas
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|bfd_size_type *
operator|,
function_decl|file_ptr *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_exec_header_in
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct external_exec *
operator|,
function_decl|struct internal_exec *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_exec_header_out
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct internal_exec *
operator|,
function_decl|struct external_exec *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|link_hash_newfunc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(struct bfd_hash_entry *
operator|,
function_decl|struct bfd_hash_table *
operator|,
function_decl|const char *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|link_hash_table_init
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(struct aout_link_hash_table *
operator|,
function_decl|bfd *
operator|,
function_decl|struct bfd_hash_entry *
parameter_list|(
function_decl|*
end_function_decl

begin_expr_stmt
unit|)
operator|(
expr|struct
name|bfd_hash_entry
operator|*
operator|,
expr|struct
name|bfd_hash_table
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|link_hash_table_create
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|link_add_symbols
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct bfd_link_info *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|final_link
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct bfd_link_info *
operator|,
function_decl|void
parameter_list|(
function_decl|*
end_function_decl

begin_expr_stmt
unit|)
operator|(
name|bfd
operator|*
operator|,
name|file_ptr
operator|*
operator|,
name|file_ptr
operator|*
operator|,
name|file_ptr
operator|*
operator|)
end_expr_stmt

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|bfd_boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|bfd_free_cached_info
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A.out uses the generic versions of these routines...  */
end_comment

begin_define
define|#
directive|define
name|aout_16_get_section_contents
value|_bfd_generic_get_section_contents
end_define

begin_define
define|#
directive|define
name|aout_32_get_section_contents
value|_bfd_generic_get_section_contents
end_define

begin_define
define|#
directive|define
name|aout_64_get_section_contents
value|_bfd_generic_get_section_contents
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_WRITE_HEADER_KLUDGE
end_ifndef

begin_define
define|#
directive|define
name|NO_WRITE_HEADER_KLUDGE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|aout_32_bfd_is_local_label_name
end_ifndef

begin_define
define|#
directive|define
name|aout_32_bfd_is_local_label_name
value|bfd_generic_is_local_label_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WRITE_HEADERS
end_ifndef

begin_define
define|#
directive|define
name|WRITE_HEADERS
parameter_list|(
name|abfd
parameter_list|,
name|execp
parameter_list|)
define|\
value|{									      \ 	bfd_size_type text_size;
comment|/* dummy vars */
value|\ 	file_ptr text_end;						      \ 	if (adata(abfd).magic == undecided_magic)			      \ 	  NAME(aout,adjust_sizes_and_vmas) (abfd,&text_size,&text_end);     \     									      \ 	execp->a_syms = bfd_get_symcount (abfd) * EXTERNAL_NLIST_SIZE;	      \ 	execp->a_entry = bfd_get_start_address (abfd);			      \     									      \ 	execp->a_trsize = ((obj_textsec (abfd)->reloc_count) *		      \ 			   obj_reloc_entry_size (abfd));		      \ 	execp->a_drsize = ((obj_datasec (abfd)->reloc_count) *		      \ 			   obj_reloc_entry_size (abfd));		      \ 	NAME(aout,swap_exec_header_out) (abfd, execp,&exec_bytes);	      \ 									      \ 	if (bfd_seek (abfd, (file_ptr) 0, SEEK_SET) != 0		      \ 	    || bfd_bwrite ((PTR)&exec_bytes, (bfd_size_type) EXEC_BYTES_SIZE, \ 			  abfd) != EXEC_BYTES_SIZE)			      \ 	  return FALSE;							      \
comment|/* Now write out reloc info, followed by syms and strings.  */
value|\   									      \ 	if (bfd_get_outsymbols (abfd) != (asymbol **) NULL		      \&& bfd_get_symcount (abfd) != 0) 				      \ 	  {								      \ 	    if (bfd_seek (abfd, (file_ptr) (N_SYMOFF(*execp)), SEEK_SET) != 0)\ 	      return FALSE;						      \ 									      \ 	    if (! NAME(aout,write_syms) (abfd))				      \ 	      return FALSE;						      \ 	  }								      \ 									      \ 	if (bfd_seek (abfd, (file_ptr) (N_TRELOFF(*execp)), SEEK_SET) != 0)   \ 	  return FALSE;						      	      \ 	if (!NAME(aout,squirt_out_relocs) (abfd, obj_textsec (abfd)))         \ 	  return FALSE;						      	      \ 									      \ 	if (bfd_seek (abfd, (file_ptr) (N_DRELOFF(*execp)), SEEK_SET) != 0)   \ 	  return FALSE;						      	      \ 	if (!NAME(aout,squirt_out_relocs) (abfd, obj_datasec (abfd)))         \ 	  return FALSE;						      	      \       }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Test if a read-only section can be merged with .text.  This is    possible if:     1. Section has file contents and is read-only.    2. The VMA of the section is after the end of .text and before       the start of .data.    3. The image is demand-pageable (otherwise, a_text in the header       will not reflect the gap between .text and .data).  */
end_comment

begin_define
define|#
directive|define
name|aout_section_merge_with_text_p
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
define|\
value|(((sec)->flags& (SEC_HAS_CONTENTS | SEC_READONLY)) ==		\       (SEC_HAS_CONTENTS | SEC_READONLY)					\&& obj_textsec (abfd) != NULL					\&& obj_datasec (abfd) != NULL					\&& (sec)->vma>= (obj_textsec (abfd)->vma +				\ 		     obj_textsec (abfd)->_cooked_size)			\&& ((sec)->vma + (sec)->_cooked_size)<= obj_datasec (abfd)->vma	\&& ((abfd)->flags& D_PAGED) != 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (LIBAOUT_H) */
end_comment

end_unit

