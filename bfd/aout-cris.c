begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD backend for CRIS a.out binaries.    Copyright 2000, 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Axis Communications AB.    Written by Hans-Peter Nilsson.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* See info in the file PORTING for documentation of these macros and    functions.  Beware; some of the information there is outdated.  */
end_comment

begin_define
define|#
directive|define
name|N_HEADER_IN_TEXT
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|N_TXTOFF
parameter_list|(
name|x
parameter_list|)
value|32
end_define

begin_define
define|#
directive|define
name|ENTRY_CAN_BE_ZERO
end_define

begin_define
define|#
directive|define
name|TEXT_START_ADDR
value|0
end_define

begin_comment
comment|/* Without reading symbols to get the text start symbol, there is no way    to know where the text segment starts in an a.out file.  Defaulting to    anything as constant as TEXT_START_ADDR is bad.  But we can guess from    the entry point, which is usually within the first 64k of the text    segment.  We also assume here that the text segment is 64k-aligned.    FIXME: It is also wrong to assume that data and bss follow immediately    after text, but with those, we don't have any choice besides reading    symbol info, and luckily there's no pressing need for correctness for    those vma:s at this time.  */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|x
parameter_list|)
value|((x).a_entry& ~(bfd_vma) 0xffff)
end_define

begin_comment
comment|/* If you change this to 4, you can not link to an address N*4+2.  */
end_comment

begin_define
define|#
directive|define
name|SEGMENT_SIZE
value|2
end_define

begin_comment
comment|/* For some reason, if the a.out file has Z_MAGIC, then    adata(abfd).exec_bytes_size is not used, but rather    adata(abfd).zmagic_disk_block_size, even though the exec_header is    *not* included in the text segment.  A simple workaround is to    #define ZMAGIC_DISK_BLOCK_SIZE, which is used if defined; otherwise    TARGET_PAGE_SIZE is used.  */
end_comment

begin_define
define|#
directive|define
name|ZMAGIC_DISK_BLOCK_SIZE
value|N_TXTOFF (0)
end_define

begin_comment
comment|/* It seems odd at first to set a page-size this low, but gives greater    freedom in where things can be linked.  The drawback is that you have    to set alignment and padding in linker scripts.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PAGE_SIZE
value|SEGMENT_SIZE
end_define

begin_define
define|#
directive|define
name|TARGETNAME
value|"a.out-cris"
end_define

begin_comment
comment|/* N_SHARED_LIB gets this reasonable default as of 1999-07-12, but we    have to work with 2.9.1.  Note that N_SHARED_LIB is used in a    SUN-specific context, not applicable to CRIS.  */
end_comment

begin_define
define|#
directive|define
name|N_SHARED_LIB
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_comment
comment|/* The definition here seems not used; just provided as a convention.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_ARCH
value|bfd_arch_cris
end_define

begin_comment
comment|/* Do not "beautify" the CONCAT* macro args.  Traditional C will not    remove whitespace added here, and thus will fail to concatenate    the tokens.  */
end_comment

begin_define
define|#
directive|define
name|MY
parameter_list|(
name|OP
parameter_list|)
value|CONCAT2 (cris_aout_,OP)
end_define

begin_define
define|#
directive|define
name|NAME
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT3 (cris_aout,_32_,y)
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_comment
comment|/* Version 1 of the header.  */
end_comment

begin_define
define|#
directive|define
name|MY_exec_hdr_flags
value|1
end_define

begin_define
define|#
directive|define
name|MY_write_object_contents
value|MY(write_object_contents)
end_define

begin_function_decl
specifier|static
name|bfd_boolean
name|MY
parameter_list|(
name|write_object_contents
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
comment|/* Forward this, so we can use a pointer to it in PARAMS.  */
end_comment

begin_struct_decl
struct_decl|struct
name|reloc_ext_external
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|MY_swap_ext_reloc_out
value|MY(swap_ext_reloc_out)
end_define

begin_function_decl
specifier|static
name|void
name|MY
parameter_list|(
name|swap_ext_reloc_out
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|arelent *
operator|,
function_decl|struct reloc_ext_external *
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|MY_swap_ext_reloc_in
value|MY(swap_ext_reloc_in)
end_define

begin_function_decl
specifier|static
name|void
name|MY
parameter_list|(
name|swap_ext_reloc_in
parameter_list|)
function_decl|PARAMS
parameter_list|(
function_decl|(bfd *
operator|,
function_decl|struct 					   reloc_ext_external *
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

begin_define
define|#
directive|define
name|MY_set_sizes
value|MY(set_sizes)
end_define

begin_function_decl
specifier|static
name|bfd_boolean
name|MY
parameter_list|(
name|set_sizes
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
comment|/* To set back reloc_size to ext, we make MY(set_sizes) be called    through this construct.  Note that MY_set_arch_mach is only called    through SET_ARCH_MACH.  The default bfd_default_set_arch_mach will    not call set_sizes.  */
end_comment

begin_define
define|#
directive|define
name|MY_set_arch_mach
value|NAME (aout, set_arch_mach)
end_define

begin_define
define|#
directive|define
name|SET_ARCH_MACH
parameter_list|(
name|BFD
parameter_list|,
name|EXEC
parameter_list|)
define|\
value|MY_set_arch_mach (BFD, DEFAULT_ARCH, N_MACHTYPE (EXEC))
end_define

begin_comment
comment|/* These macros describe the binary layout of the reloc information we    use in a file.  */
end_comment

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_EXTERN_LITTLE
value|0x80
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_LITTLE
value|3
end_define

begin_define
define|#
directive|define
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_section_contents
end_ifndef

begin_define
define|#
directive|define
name|MY_get_section_contents
value|aout_32_get_section_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MACHTYPE_OK
parameter_list|(
name|mtype
parameter_list|)
value|((mtype) == M_CRIS)
end_define

begin_comment
comment|/* Include generic functions (some are overridden above).  */
end_comment

begin_include
include|#
directive|include
file|"aout32.c"
end_include

begin_include
include|#
directive|include
file|"aout-target.h"
end_include

begin_comment
comment|/* We need our own version to set header flags.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|MY
function|(
name|write_object_contents
function|)
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|external_exec
name|exec_bytes
decl_stmt|;
name|struct
name|internal_exec
modifier|*
name|execp
init|=
name|exec_hdr
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
comment|/* We set the reloc type to RELOC_EXT_SIZE, although setting it at all      seems unnecessary when inspecting as and ld behavior (not an      exhaustive inspection).  The default write_object_contents      definition sets RELOC_EXT_SIZE, so we follow suite and set it too.  */
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_EXT_SIZE
expr_stmt|;
comment|/* Setting N_SET_MACHTYPE and using N_SET_FLAGS is not performed by      the default definition.  */
if|if
condition|(
name|bfd_get_arch
argument_list|(
name|abfd
argument_list|)
operator|==
name|bfd_arch_cris
condition|)
name|N_SET_MACHTYPE
argument_list|(
operator|*
name|execp
argument_list|,
name|M_CRIS
argument_list|)
expr_stmt|;
name|N_SET_FLAGS
argument_list|(
operator|*
name|execp
argument_list|,
name|aout_backend_info
argument_list|(
name|abfd
argument_list|)
operator|->
name|exec_hdr_flags
argument_list|)
expr_stmt|;
name|WRITE_HEADERS
argument_list|(
name|abfd
argument_list|,
name|execp
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* We need our own for these reasons:    - Assert that a normal 8, 16 or 32 reloc is output.    - Fix what seems to be a weak-bug (perhaps there for valid reasons).  */
end_comment

begin_function
specifier|static
name|void
name|MY
function|(
name|swap_ext_reloc_out
function|)
parameter_list|(
name|abfd
parameter_list|,
name|g
parameter_list|,
name|natptr
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|arelent
modifier|*
name|g
decl_stmt|;
name|struct
name|reloc_ext_external
modifier|*
name|natptr
decl_stmt|;
block|{
name|int
name|r_index
decl_stmt|;
name|int
name|r_extern
decl_stmt|;
name|unsigned
name|int
name|r_type
decl_stmt|;
name|bfd_vma
name|r_addend
decl_stmt|;
name|asymbol
modifier|*
name|sym
init|=
operator|*
operator|(
name|g
operator|->
name|sym_ptr_ptr
operator|)
decl_stmt|;
name|asection
modifier|*
name|output_section
init|=
name|sym
operator|->
name|section
operator|->
name|output_section
decl_stmt|;
name|PUT_WORD
argument_list|(
name|abfd
argument_list|,
name|g
operator|->
name|address
argument_list|,
name|natptr
operator|->
name|r_address
argument_list|)
expr_stmt|;
name|r_type
operator|=
operator|(
name|unsigned
name|int
operator|)
name|g
operator|->
name|howto
operator|->
name|type
expr_stmt|;
name|r_addend
operator|=
name|g
operator|->
name|addend
expr_stmt|;
if|if
condition|(
operator|(
name|sym
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|!=
literal|0
condition|)
name|r_addend
operator|+=
operator|(
operator|*
operator|(
name|g
operator|->
name|sym_ptr_ptr
operator|)
operator|)
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
comment|/* If this relocation is relative to a symbol then set the      r_index to the symbols index, and the r_extern bit.       Absolute symbols can come in in two ways, either as an offset      from the abs section, or as a symbol which has an abs value.      check for that here.  */
if|if
condition|(
name|bfd_is_abs_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
condition|)
block|{
name|r_extern
operator|=
literal|0
expr_stmt|;
name|r_index
operator|=
name|N_ABS
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|sym
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
comment|/* Remember to check for weak symbols; they count as global.  */
operator|||
operator|(
name|sym
operator|->
name|flags
operator|&
operator|(
name|BSF_GLOBAL
operator||
name|BSF_WEAK
operator|)
operator|)
operator|!=
literal|0
condition|)
name|r_extern
operator|=
literal|1
expr_stmt|;
else|else
name|r_extern
operator|=
literal|0
expr_stmt|;
name|r_index
operator|=
operator|(
operator|*
operator|(
name|g
operator|->
name|sym_ptr_ptr
operator|)
operator|)
operator|->
name|KEEPIT
expr_stmt|;
block|}
else|else
block|{
comment|/* Just an ordinary section.  */
name|r_extern
operator|=
literal|0
expr_stmt|;
name|r_index
operator|=
name|output_section
operator|->
name|target_index
expr_stmt|;
block|}
comment|/* The relocation type is the same as the canonical ones, but only      the first 3 are used: RELOC_8, RELOC_16, RELOC_32.      We may change this later, but assert this for the moment.  */
if|if
condition|(
name|r_type
operator|>
literal|2
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"%s: Invalid relocation type exported: %d"
argument_list|)
argument_list|,
name|bfd_get_filename
argument_list|(
name|abfd
argument_list|)
argument_list|,
name|r_type
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_wrong_format
argument_list|)
expr_stmt|;
block|}
comment|/* Now the fun stuff.  */
name|natptr
operator|->
name|r_index
index|[
literal|2
index|]
operator|=
name|r_index
operator|>>
literal|16
expr_stmt|;
name|natptr
operator|->
name|r_index
index|[
literal|1
index|]
operator|=
name|r_index
operator|>>
literal|8
expr_stmt|;
name|natptr
operator|->
name|r_index
index|[
literal|0
index|]
operator|=
name|r_index
expr_stmt|;
name|natptr
operator|->
name|r_type
index|[
literal|0
index|]
operator|=
operator|(
name|r_extern
condition|?
name|RELOC_EXT_BITS_EXTERN_LITTLE
else|:
literal|0
operator|)
operator||
operator|(
name|r_type
operator|<<
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
operator|)
expr_stmt|;
name|PUT_WORD
argument_list|(
name|abfd
argument_list|,
name|r_addend
argument_list|,
name|natptr
operator|->
name|r_addend
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* We need our own to assert that a normal 8, 16 or 32 reloc is input.  */
end_comment

begin_function
specifier|static
name|void
name|MY
function|(
name|swap_ext_reloc_in
function|)
parameter_list|(
name|abfd
parameter_list|,
name|bytes
parameter_list|,
name|cache_ptr
parameter_list|,
name|symbols
parameter_list|,
name|symcount
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|reloc_ext_external
modifier|*
name|bytes
decl_stmt|;
name|arelent
modifier|*
name|cache_ptr
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|;
name|bfd_size_type
name|symcount
decl_stmt|;
block|{
name|unsigned
name|int
name|r_index
decl_stmt|;
name|int
name|r_extern
decl_stmt|;
name|unsigned
name|int
name|r_type
decl_stmt|;
name|struct
name|aoutdata
modifier|*
name|su
init|=
operator|&
operator|(
name|abfd
operator|->
name|tdata
operator|.
name|aout_data
operator|->
name|a
operator|)
decl_stmt|;
name|cache_ptr
operator|->
name|address
operator|=
operator|(
name|GET_SWORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|r_address
argument_list|)
operator|)
expr_stmt|;
comment|/* Now the fun stuff.  */
name|r_index
operator|=
operator|(
name|bytes
operator|->
name|r_index
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|bytes
operator|->
name|r_index
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
name|bytes
operator|->
name|r_index
index|[
literal|0
index|]
expr_stmt|;
name|r_extern
operator|=
operator|(
literal|0
operator|!=
operator|(
name|bytes
operator|->
name|r_type
index|[
literal|0
index|]
operator|&
name|RELOC_EXT_BITS_EXTERN_LITTLE
operator|)
operator|)
expr_stmt|;
name|r_type
operator|=
operator|(
operator|(
name|bytes
operator|->
name|r_type
index|[
literal|0
index|]
operator|)
operator|>>
name|RELOC_EXT_BITS_TYPE_SH_LITTLE
operator|)
operator|&
name|RELOC_EXT_BITS_TYPE_LITTLE
expr_stmt|;
if|if
condition|(
name|r_type
operator|>
literal|2
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"%s: Invalid relocation type imported: %d"
argument_list|)
argument_list|,
name|bfd_archive_filename
argument_list|(
name|abfd
argument_list|)
argument_list|,
name|r_type
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_wrong_format
argument_list|)
expr_stmt|;
block|}
name|cache_ptr
operator|->
name|howto
operator|=
name|howto_table_ext
operator|+
name|r_type
expr_stmt|;
if|if
condition|(
name|r_extern
operator|&&
name|r_index
operator|>
name|symcount
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"%s: Bad relocation record imported: %d"
argument_list|)
argument_list|,
name|bfd_archive_filename
argument_list|(
name|abfd
argument_list|)
argument_list|,
name|r_index
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_wrong_format
argument_list|)
expr_stmt|;
comment|/* We continue, so we can catch further errors.  */
name|r_extern
operator|=
literal|0
expr_stmt|;
name|r_index
operator|=
name|N_ABS
expr_stmt|;
block|}
comment|/* Magically uses r_extern, symbols etc.  Ugly, but it's what's in the      default.  */
name|MOVE_ADDRESS
argument_list|(
name|GET_SWORD
argument_list|(
name|abfd
argument_list|,
name|bytes
operator|->
name|r_addend
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* We use the same as the default, except that we also set    "obj_reloc_entry_size (abfd) = RELOC_EXT_SIZE;", to avoid changing    NAME (aout, set_arch_mach) in aoutx.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|MY
function|(
name|set_sizes
function|)
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
comment|/* Just as the default in aout-target.h (with some #ifdefs folded)...  */
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|page_size
operator|=
name|TARGET_PAGE_SIZE
expr_stmt|;
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|segment_size
operator|=
name|SEGMENT_SIZE
expr_stmt|;
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|zmagic_disk_block_size
operator|=
name|ZMAGIC_DISK_BLOCK_SIZE
expr_stmt|;
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|exec_bytes_size
operator|=
name|EXEC_BYTES_SIZE
expr_stmt|;
comment|/* ... except for that we have the extended reloc.  The alternative      would be to add a check on bfd_arch_cris in NAME (aout,      set_arch_mach) in aoutx.h, but I don't want to do that since      target-specific things should not be added there.  */
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_EXT_SIZE
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/*  * Local variables:  * eval: (c-set-style "gnu")  * indent-tabs-mode: t  * End:  */
end_comment

end_unit

