begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2013 Kai Wang  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: ld.h 2940 2013-05-04 22:22:10Z kaiwang27 $  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<ar.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<fnmatch.h>
end_include

begin_include
include|#
directive|include
file|<gelf.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<libelftc.h>
end_include

begin_include
include|#
directive|include
file|<libgen.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"dwarf.h"
end_include

begin_define
define|#
directive|define
name|oom
parameter_list|()
value|ld_fatal(ld, "out of memory")
end_define

begin_include
include|#
directive|include
file|"utarray.h"
end_include

begin_define
define|#
directive|define
name|uthash_fatal
parameter_list|(
name|msg
parameter_list|)
value|ld_fatal(ld, msg)
end_define

begin_include
include|#
directive|include
file|"uthash.h"
end_include

begin_include
include|#
directive|include
file|"_elftc.h"
end_include

begin_struct_decl
struct_decl|struct
name|ld_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_input_section_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_path
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_symbol
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_symbol_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_output_data_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_wildcard_match
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_ehframe_cie_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_ehframe_fde_head
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ld_section_group
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|LD_MAX_NESTED_GROUP
value|16
end_define

begin_struct
struct|struct
name|ld_state
block|{
name|Elftc_Bfd_Target
modifier|*
name|ls_itgt
decl_stmt|;
comment|/* input bfd target set by -b */
name|struct
name|ld_file
modifier|*
name|ls_file
decl_stmt|;
comment|/* current open file */
name|unsigned
name|ls_static
decl_stmt|;
comment|/* use static library */
name|unsigned
name|ls_whole_archive
decl_stmt|;
comment|/* include whole archive */
name|unsigned
name|ls_as_needed
decl_stmt|;
comment|/* DT_NEEDED */
name|unsigned
name|ls_group_level
decl_stmt|;
comment|/* archive group level */
name|unsigned
name|ls_extracted
index|[
name|LD_MAX_NESTED_GROUP
operator|+
literal|1
index|]
decl_stmt|;
comment|/* extracted from archive group */
name|unsigned
name|ls_search_dir
decl_stmt|;
comment|/* search library directories */
name|uint64_t
name|ls_loc_counter
decl_stmt|;
comment|/* location counter */
name|uint64_t
name|ls_offset
decl_stmt|;
comment|/* cur. output section file offset */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_path
argument_list|)
name|ls_lplist
expr_stmt|;
comment|/* search path list */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_path
argument_list|)
name|ls_rplist
expr_stmt|;
comment|/* rpath list */
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ld_path
argument_list|)
name|ls_rllist
expr_stmt|;
comment|/* rpath-link list */
name|unsigned
name|ls_arch_conflict
decl_stmt|;
comment|/* input arch conflict with output */
name|unsigned
name|ls_first_elf_object
decl_stmt|;
comment|/* first ELF object to process */
name|unsigned
name|ls_rerun
decl_stmt|;
comment|/* ld(1) restarted */
name|unsigned
name|ls_archive_mb_header
decl_stmt|;
comment|/* extracted list header printed */
name|unsigned
name|ls_first_output_sec
decl_stmt|;
comment|/* flag indicates 1st output section */
name|unsigned
name|ls_ignore_next_plt
decl_stmt|;
comment|/* ignore next PLT relocation */
name|unsigned
name|ls_version_local
decl_stmt|;
comment|/* version entry is local */
name|uint64_t
name|ls_relative_reloc
decl_stmt|;
comment|/* number of *_RELATIVE relocations */
name|struct
name|ld_input_section_head
modifier|*
name|ls_gc
decl_stmt|;
comment|/* garbage collection search list */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ld
block|{
specifier|const
name|char
modifier|*
name|ld_progname
decl_stmt|;
comment|/* ld(1) program name */
name|struct
name|ld_arch
modifier|*
name|ld_arch
decl_stmt|;
comment|/* arch-specific callbacks */
name|struct
name|ld_arch
modifier|*
name|ld_arch_list
decl_stmt|;
comment|/* list of supported archs */
name|Elftc_Bfd_Target
modifier|*
name|ld_otgt
decl_stmt|;
comment|/* default output format */
name|Elftc_Bfd_Target
modifier|*
name|ld_otgt_be
decl_stmt|;
comment|/* big-endian output format */
name|Elftc_Bfd_Target
modifier|*
name|ld_otgt_le
decl_stmt|;
comment|/* little-endian output format */
name|char
modifier|*
name|ld_otgt_name
decl_stmt|;
comment|/* output format name */
name|char
modifier|*
name|ld_otgt_be_name
decl_stmt|;
comment|/* big-endian output format name */
name|char
modifier|*
name|ld_otgt_le_name
decl_stmt|;
comment|/* little-endian output format name */
name|struct
name|ld_output
modifier|*
name|ld_output
decl_stmt|;
comment|/* output object */
name|char
modifier|*
name|ld_output_file
decl_stmt|;
comment|/* output file name */
name|char
modifier|*
name|ld_entry
decl_stmt|;
comment|/* entry point set by -e */
name|char
modifier|*
name|ld_scp_entry
decl_stmt|;
comment|/* entry point set by linker script */
name|char
modifier|*
name|ld_interp
decl_stmt|;
comment|/* dynamic linker */
name|char
modifier|*
name|ld_soname
decl_stmt|;
comment|/* DT_SONAME */
name|struct
name|ld_script
modifier|*
name|ld_scp
decl_stmt|;
comment|/* linker script */
name|struct
name|ld_state
name|ld_state
decl_stmt|;
comment|/* linker state */
name|struct
name|ld_strtab
modifier|*
name|ld_shstrtab
decl_stmt|;
comment|/* section name table */
name|struct
name|ld_symbol_head
modifier|*
name|ld_ext_symbols
decl_stmt|;
comment|/* -u/EXTERN symbols */
name|struct
name|ld_symbol_head
modifier|*
name|ld_var_symbols
decl_stmt|;
comment|/* ldscript var symbols */
name|struct
name|ld_symbol
modifier|*
name|ld_sym
decl_stmt|;
comment|/* internal symbol table */
name|struct
name|ld_symbol
modifier|*
name|ld_symtab_import
decl_stmt|;
comment|/* hash for import symbols */
name|struct
name|ld_symbol
modifier|*
name|ld_symtab_export
decl_stmt|;
comment|/* hash for export symbols */
name|struct
name|ld_symbol_defver
modifier|*
name|ld_defver
decl_stmt|;
comment|/* default version table */
name|struct
name|ld_symbol_table
modifier|*
name|ld_symtab
decl_stmt|;
comment|/* .symtab symbol table */
name|struct
name|ld_strtab
modifier|*
name|ld_strtab
decl_stmt|;
comment|/* .strtab string table */
name|struct
name|ld_symbol_table
modifier|*
name|ld_dynsym
decl_stmt|;
comment|/* .dynsym symbol table */
name|struct
name|ld_strtab
modifier|*
name|ld_dynstr
decl_stmt|;
comment|/* .dynstr string table */
name|struct
name|ld_symbol_head
modifier|*
name|ld_dyn_symbols
decl_stmt|;
comment|/* dynamic symbol list */
name|struct
name|ld_wildcard_match
modifier|*
name|ld_wm
decl_stmt|;
comment|/* wildcard hash table */
name|struct
name|ld_input_section
modifier|*
name|ld_dynbss
decl_stmt|;
comment|/* .dynbss section */
name|struct
name|ld_input_section
modifier|*
name|ld_got
decl_stmt|;
comment|/* .got section */
name|struct
name|ld_ehframe_cie_head
modifier|*
name|ld_cie
decl_stmt|;
comment|/* ehframe CIE list */
name|struct
name|ld_ehframe_fde_head
modifier|*
name|ld_fde
decl_stmt|;
comment|/* ehframe FDE list */
name|struct
name|ld_section_group
modifier|*
name|ld_sg
decl_stmt|;
comment|/* included section groups */
name|unsigned
name|char
name|ld_common_alloc
decl_stmt|;
comment|/* always alloc space for common sym */
name|unsigned
name|char
name|ld_common_no_alloc
decl_stmt|;
comment|/* never alloc space for common sym */
name|unsigned
name|char
name|ld_emit_reloc
decl_stmt|;
comment|/* emit relocations */
name|unsigned
name|char
name|ld_gen_gnustack
decl_stmt|;
comment|/* generate PT_GNUSTACK */
name|unsigned
name|char
name|ld_print_linkmap
decl_stmt|;
comment|/* print link map */
name|unsigned
name|char
name|ld_stack_exec
decl_stmt|;
comment|/* stack executable */
name|unsigned
name|char
name|ld_stack_exec_set
decl_stmt|;
comment|/* stack executable override */
name|unsigned
name|char
name|ld_exec
decl_stmt|;
comment|/* output normal executable */
name|unsigned
name|char
name|ld_pie
decl_stmt|;
comment|/* position-independent executable */
name|unsigned
name|char
name|ld_dso
decl_stmt|;
comment|/* output shared library */
name|unsigned
name|char
name|ld_reloc
decl_stmt|;
comment|/* output relocatable object */
name|unsigned
name|char
name|ld_dynamic_link
decl_stmt|;
comment|/* perform dynamic linking */
name|unsigned
name|char
name|ld_print_version
decl_stmt|;
comment|/* linker version printed */
name|unsigned
name|char
name|ld_gc
decl_stmt|;
comment|/* perform garbage collection */
name|unsigned
name|char
name|ld_gc_print
decl_stmt|;
comment|/* print removed sections */
name|unsigned
name|char
name|ld_ehframe_hdr
decl_stmt|;
comment|/* create .eh_frame_hdr section */
name|STAILQ_HEAD
argument_list|(
argument|ld_input_head
argument_list|,
argument|ld_input
argument_list|)
name|ld_lilist
expr_stmt|;
comment|/* input object list */
name|TAILQ_HEAD
argument_list|(
argument|ld_file_head
argument_list|,
argument|ld_file
argument_list|)
name|ld_lflist
expr_stmt|;
comment|/* input file list */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ld_err
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_fatal
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_fatal_std
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_warn
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ld_info
parameter_list|(
name|struct
name|ld
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

