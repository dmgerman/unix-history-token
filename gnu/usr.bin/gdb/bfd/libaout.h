begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end data structures for a.out (and similar) files.    Copyright 1990, 1991, 1992 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* We try to encapsulate the differences in the various a.out file    variants in a few routines, and otherwise share large masses of code.    This means we only have to fix bugs in one place, most of the time.  */
end_comment

begin_comment
comment|/* Parameterize the a.out code based on whether it is being built    for a 32-bit architecture or a 64-bit architecture.  */
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
value|bfd_h_get_64
end_define

begin_define
define|#
directive|define
name|GET_SWORD
value|bfd_h_get_signed_64
end_define

begin_define
define|#
directive|define
name|PUT_WORD
value|bfd_h_put_64
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
value|CAT3(x,_64_,y)
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
value|CAT(x,_64)
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

begin_comment
comment|/* ARCH_SIZE == 32 */
end_comment

begin_define
define|#
directive|define
name|GET_WORD
value|bfd_h_get_32
end_define

begin_define
define|#
directive|define
name|GET_SWORD
value|bfd_h_get_signed_32
end_define

begin_define
define|#
directive|define
name|PUT_WORD
value|bfd_h_put_32
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
value|CAT3(x,_32_,y)
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
value|CAT(x,_32)
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

begin_comment
comment|/* Declare these types at file level, since they are used in parameter    lists, which have wierd scope.  */
end_comment

begin_struct_decl
struct_decl|struct
name|external_exec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_exec
struct_decl|;
end_struct_decl

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
comment|/* If the text section VMA isn't specified, and we need an absolute      address, use this as the default.  If we're producing a relocatable      file, zero is always used.  */
comment|/* ?? Perhaps a callback would be a better choice?  Will this do anything      reasonable for a format that handles multiple CPUs with different      load addresses for each?  */
name|bfd_vma
name|default_text_vma
decl_stmt|;
comment|/* Callback for setting the page and segment sizes, if they can't be      trivially determined from the architecture.  */
name|boolean
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
value|((CONST struct aout_backend_data *)((abfd)->xvec->backend_data))
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
comment|/* Magic number for NetBSD is<MSB> 3130292827262524232221201918171615141312111009080706050403020100< FLAGS><><  MAGIC NUMBER> */
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
comment|/* skip a bunch so we don't run into any of suns numbers */
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
name|M_386_NETBSD
init|=
literal|134
block|,
comment|/* NetBSD/386 binary */
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
comment|/* HP 200/300 HPUX binary */
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
value|((exec).a_info& 0x8000000)
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
comment|/* For ease, we do this */
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
comment|/* Size of a relocation entry in external form */
name|unsigned
name|reloc_entry_size
decl_stmt|;
comment|/* Size of a symbol table entry in external form */
name|unsigned
name|symbol_entry_size
decl_stmt|;
comment|/* Page size - needed for alignment of demand paged files. */
name|unsigned
name|long
name|page_size
decl_stmt|;
comment|/* Segment size - needed for alignment of demand paged files. */
name|unsigned
name|long
name|segment_size
decl_stmt|;
name|unsigned
name|exec_bytes_size
decl_stmt|;
name|unsigned
name|vma_adjusted
range|:
literal|1
decl_stmt|;
comment|/* used when a bfd supports several highly similar formats */
enum|enum
block|{
name|default_format
init|=
literal|0
block|,
name|gnu_encap_format
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

begin_comment
comment|/* We take the address of the first element of an asymbol to ensure that the    macro is only ever applied to an asymbol */
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
comment|/* Prototype declarations for functions defined in aoutx.h  */
end_comment

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|squirt_out_relocs
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|asection
modifier|*
name|section
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
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
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
decl|struct
name|internal_exec
modifier|*
name|execp
decl_stmt|,
name|bfd_target
modifier|*
argument_list|(
operator|*
name|callback
argument_list|)
argument_list|(
name|bfd
operator|*
argument_list|)
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|mkobject
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
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
name|arch
decl_stmt|,
name|unsigned
name|long
name|machine
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|set_arch_mach
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
decl|enum
name|bfd_architecture
name|arch
decl_stmt|,
name|unsigned
name|long
name|machine
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|new_section_hook
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|asection
modifier|*
name|newsect
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|set_section_contents
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|sec_ptr
name|section
decl_stmt|,
name|PTR
name|location
decl_stmt|,
name|file_ptr
name|offset
decl_stmt|,
name|bfd_size_type
name|count
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
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
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|slurp_symbol_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|write_syms
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|reclaim_symbol_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|unsigned
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_symtab_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|unsigned
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_symtab
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|asymbol
modifier|*
modifier|*
name|location
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|slurp_reloc_table
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|sec_ptr
name|asect
decl_stmt|,
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|unsigned
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|canonicalize_reloc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|sec_ptr
name|section
decl_stmt|,
name|arelent
modifier|*
modifier|*
name|relptr
decl_stmt|,
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|unsigned
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_reloc_upper_bound
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|sec_ptr
name|asect
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|reclaim_reloc
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|ignore_abfd
decl_stmt|,
name|sec_ptr
name|ignore
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
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
function_decl|(
name|bfd
modifier|*
name|ignore_abfd
decl_stmt|,
name|asymbol
modifier|*
name|ignore_symbol
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|print_symbol
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|ignore_abfd
decl_stmt|,
name|PTR
name|file
decl_stmt|,
name|asymbol
modifier|*
name|symbol
decl_stmt|,
name|bfd_print_symbol_type
name|how
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|get_symbol_info
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|ignore_abfd
decl_stmt|,
name|asymbol
modifier|*
name|symbol
decl_stmt|,
name|symbol_info
modifier|*
name|ret
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|close_and_cleanup
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *abfd
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|find_nearest_line
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|asection
modifier|*
name|section
decl_stmt|,
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|,
name|bfd_vma
name|offset
decl_stmt|,
name|CONST
name|char
modifier|*
modifier|*
name|filename_ptr
decl_stmt|,
name|CONST
name|char
modifier|*
modifier|*
name|functionname_ptr
decl_stmt|,
name|unsigned
name|int
modifier|*
name|line_ptr
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|sizeof_headers
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|boolean
name|exec
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|boolean
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|adjust_sizes_and_vmas
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
name|bfd_size_type
modifier|*
name|text_size
decl_stmt|,
name|file_ptr
modifier|*
name|text_end
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_exec_header_in
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
decl|struct
name|external_exec
modifier|*
name|raw_bytes
decl_stmt|, struct
name|internal_exec
modifier|*
name|execp
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|NAME
parameter_list|(
name|aout
parameter_list|,
name|swap_exec_header_out
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(
name|bfd
modifier|*
name|abfd
decl_stmt|,
decl|struct
name|internal_exec
modifier|*
name|execp
decl_stmt|, struct
name|external_exec
modifier|*
name|raw_bytes
decl_stmt|)
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Prototypes for functions in stab-syms.c. */
end_comment

begin_decl_stmt
name|CONST
name|char
modifier|*
name|aout_stab_name
name|PARAMS
argument_list|(
operator|(
name|int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A.out uses the generic versions of these routines... */
end_comment

begin_define
define|#
directive|define
name|aout_32_get_section_contents
value|bfd_generic_get_section_contents
end_define

begin_define
define|#
directive|define
name|aout_32_close_and_cleanup
value|bfd_generic_close_and_cleanup
end_define

begin_define
define|#
directive|define
name|aout_64_get_section_contents
value|bfd_generic_get_section_contents
end_define

begin_define
define|#
directive|define
name|aout_64_close_and_cleanup
value|bfd_generic_close_and_cleanup
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
value|\ 	file_ptr text_end;						      \ 	if (adata(abfd).magic == undecided_magic)			      \ 	  NAME(aout,adjust_sizes_and_vmas) (abfd,&text_size,&text_end);     \     									      \ 	execp->a_syms = bfd_get_symcount (abfd) * EXTERNAL_NLIST_SIZE;	      \ 	execp->a_entry = bfd_get_start_address (abfd);			      \     									      \ 	execp->a_trsize = ((obj_textsec (abfd)->reloc_count) *		      \ 			   obj_reloc_entry_size (abfd));		      \ 	execp->a_drsize = ((obj_datasec (abfd)->reloc_count) *		      \ 			   obj_reloc_entry_size (abfd));		      \ 	NAME(aout,swap_exec_header_out) (abfd, execp,&exec_bytes);	      \ 									      \ 	bfd_seek (abfd, (file_ptr) 0, SEEK_SET);			      \ 	bfd_write ((PTR)&exec_bytes, 1, EXEC_BYTES_SIZE, abfd);	      \
comment|/* Now write out reloc info, followed by syms and strings */
value|\   									      \ 	if (bfd_get_symcount (abfd) != 0) 				      \ 	    {								      \ 	      bfd_seek (abfd, (file_ptr)(N_SYMOFF(*execp)), SEEK_SET);	      \ 									      \ 	      NAME(aout,write_syms)(abfd);				      \ 									      \ 	      bfd_seek (abfd, (file_ptr)(N_TRELOFF(*execp)), SEEK_SET);	      \ 									      \ 	      if (!NAME(aout,squirt_out_relocs) (abfd, obj_textsec (abfd))) return false; \ 	      bfd_seek (abfd, (file_ptr)(N_DRELOFF(*execp)), SEEK_SET);	      \ 									      \ 	      if (!NAME(aout,squirt_out_relocs)(abfd, obj_datasec (abfd))) return false; \ 	    }								      \       }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

