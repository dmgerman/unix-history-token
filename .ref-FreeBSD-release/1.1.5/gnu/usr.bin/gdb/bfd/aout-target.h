begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define a target vector and some small routines for a variant of a.out.    Copyright (C) 1990, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"aout/aout64.h"
end_include

begin_include
include|#
directive|include
file|"aout/stab_gnu.h"
end_include

begin_include
include|#
directive|include
file|"aout/ar.h"
end_include

begin_comment
comment|/*#include "libaout.h"*/
end_comment

begin_extern
extern|extern CONST struct reloc_howto_struct * NAME(aout
operator|,
extern|reloc_type_lookup
end_extern

begin_expr_stmt
unit|)
operator|(
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Set parameters about this a.out file that are machine-dependent.    This routine is called from some_aout_object_p just before it returns.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_callback
end_ifndef

begin_decl_stmt
specifier|static
name|bfd_target
modifier|*
name|DEFUN
argument_list|(
name|MY
argument_list|(
name|callback
argument_list|)
argument_list|,
operator|(
name|abfd
operator|)
argument_list|,
name|bfd
operator|*
name|abfd
argument_list|)
block|{
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
comment|/* Calculate the file positions of the parts of a newly read aout header */
name|obj_textsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|_raw_size
operator|=
name|N_TXTSIZE
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
comment|/* The virtual memory addresses of the sections */
name|obj_textsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|N_TXTADDR
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
name|obj_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|N_DATADDR
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
name|obj_bsssec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|N_BSSADDR
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
comment|/* The file offsets of the sections */
name|obj_textsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
name|N_TXTOFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
name|obj_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
name|N_DATOFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
comment|/* The file offsets of the relocation info */
name|obj_textsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|rel_filepos
operator|=
name|N_TRELOFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
name|obj_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|rel_filepos
operator|=
name|N_DRELOFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
comment|/* The file offsets of the string table and symbol table.  */
name|obj_sym_filepos
argument_list|(
name|abfd
argument_list|)
operator|=
name|N_SYMOFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
name|obj_str_filepos
argument_list|(
name|abfd
argument_list|)
operator|=
name|N_STROFF
argument_list|(
operator|*
name|execp
argument_list|)
expr_stmt|;
comment|/* Determine the architecture and machine type of the object file.  */
ifdef|#
directive|ifdef
name|SET_ARCH_MACH
name|SET_ARCH_MACH
argument_list|(
name|abfd
argument_list|,
operator|*
name|execp
argument_list|)
expr_stmt|;
else|#
directive|else
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|DEFAULT_ARCH
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Don't set sizes now -- can't be sure until we know arch& mach.      Sizes get set in set_sizes callback, later.  */
if|#
directive|if
literal|0
block|adata(abfd).page_size = PAGE_SIZE;
ifdef|#
directive|ifdef
name|SEGMENT_SIZE
block|adata(abfd).segment_size = SEGMENT_SIZE;
else|#
directive|else
block|adata(abfd).segment_size = PAGE_SIZE;
endif|#
directive|endif
block|adata(abfd).exec_bytes_size = EXEC_BYTES_SIZE;
endif|#
directive|endif
return|return
name|abfd
operator|->
name|xvec
return|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_object_p
end_ifndef

begin_comment
comment|/* Finish up the reading of an a.out file header */
end_comment

begin_decl_stmt
specifier|static
name|bfd_target
modifier|*
name|DEFUN
argument_list|(
name|MY
argument_list|(
name|object_p
argument_list|)
argument_list|,
operator|(
name|abfd
operator|)
argument_list|,
name|bfd
operator|*
name|abfd
argument_list|)
block|{
name|struct
name|external_exec
name|exec_bytes
decl_stmt|;
comment|/* Raw exec header from file */
name|struct
name|internal_exec
name|exec
decl_stmt|;
comment|/* Cleaned-up exec header */
name|bfd_target
modifier|*
name|target
decl_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
operator|(
name|PTR
operator|)
operator|&
name|exec_bytes
argument_list|,
literal|1
argument_list|,
name|EXEC_BYTES_SIZE
argument_list|,
name|abfd
argument_list|)
operator|!=
name|EXEC_BYTES_SIZE
condition|)
block|{
name|bfd_error
operator|=
name|wrong_format
expr_stmt|;
return|return
literal|0
return|;
block|}
ifdef|#
directive|ifdef
name|NO_SWAP_MAGIC
name|memcpy
argument_list|(
operator|&
name|exec
operator|.
name|a_info
argument_list|,
name|exec_bytes
operator|.
name|e_info
argument_list|,
sizeof|sizeof
argument_list|(
name|exec
operator|.
name|a_info
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|exec
operator|.
name|a_info
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|exec_bytes
operator|.
name|e_info
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NO_SWAP_MAGIC */
if|if
condition|(
name|N_BADMAG
argument_list|(
name|exec
argument_list|)
condition|)
return|return
literal|0
return|;
ifdef|#
directive|ifdef
name|MACHTYPE_OK
if|if
condition|(
operator|!
operator|(
name|MACHTYPE_OK
argument_list|(
name|N_MACHTYPE
argument_list|(
name|exec
argument_list|)
argument_list|)
operator|)
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
name|NAME
argument_list|(
name|aout
argument_list|,
name|swap_exec_header_in
argument_list|)
argument_list|(
name|abfd
argument_list|,
operator|&
name|exec_bytes
argument_list|,
operator|&
name|exec
argument_list|)
expr_stmt|;
name|target
operator|=
name|NAME
argument_list|(
name|aout
argument_list|,
name|some_aout_object_p
argument_list|)
argument_list|(
name|abfd
argument_list|,
operator|&
name|exec
argument_list|,
name|MY
argument_list|(
name|callback
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ENTRY_CAN_BE_ZERO
comment|/* The NEWSOS3 entry-point is/was 0, which (amongst other lossage)    * means that it isn't obvious if EXEC_P should be set.    * All of the following must be true for an executable:    * There must be no relocations, the bfd can be neither an    * archive nor an archive element, and the file must be executable. */
if|if
condition|(
name|exec
operator|.
name|a_trsize
operator|+
name|exec
operator|.
name|a_drsize
operator|==
literal|0
operator|&&
name|bfd_get_format
argument_list|(
name|abfd
argument_list|)
operator|==
name|bfd_object
operator|&&
name|abfd
operator|->
name|my_archive
operator|==
name|NULL
condition|)
block|{
name|struct
name|stat
name|buf
decl_stmt|;
ifndef|#
directive|ifndef
name|S_IXUSR
define|#
directive|define
name|S_IXUSR
value|0100
comment|/* Execute by owner.  */
endif|#
directive|endif
if|if
condition|(
name|stat
argument_list|(
name|abfd
operator|->
name|filename
argument_list|,
operator|&
name|buf
argument_list|)
operator|==
literal|0
operator|&&
operator|(
name|buf
operator|.
name|st_mode
operator|&
name|S_IXUSR
operator|)
condition|)
name|abfd
operator|->
name|flags
operator||=
name|EXEC_P
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* ENTRY_CAN_BE_ZERO */
return|return
name|target
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|MY_object_p
value|MY(object_p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_mkobject
end_ifndef

begin_decl_stmt
specifier|static
name|boolean
name|DEFUN
argument_list|(
name|MY
argument_list|(
name|mkobject
argument_list|)
argument_list|,
operator|(
name|abfd
operator|)
argument_list|,
name|bfd
operator|*
name|abfd
argument_list|)
block|{
if|if
condition|(
name|NAME
argument_list|(
name|aout
argument_list|,
name|mkobject
argument_list|)
argument_list|(
name|abfd
argument_list|)
operator|==
name|false
condition|)
return|return
name|false
return|;
if|#
directive|if
literal|0
comment|/* Sizes get set in set_sizes callback, later, after we know 	 the architecture and machine.  */
block|adata(abfd).page_size = PAGE_SIZE;
ifdef|#
directive|ifdef
name|SEGMENT_SIZE
block|adata(abfd).segment_size = SEGMENT_SIZE;
else|#
directive|else
block|adata(abfd).segment_size = PAGE_SIZE;
endif|#
directive|endif
block|adata(abfd).exec_bytes_size = EXEC_BYTES_SIZE;
endif|#
directive|endif
return|return
name|true
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|MY_mkobject
value|MY(mkobject)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Write an object file.    Section contents have already been written.  We write the    file header, symbols, and relocation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_write_object_contents
end_ifndef

begin_decl_stmt
specifier|static
name|boolean
name|DEFUN
argument_list|(
name|MY
argument_list|(
name|write_object_contents
argument_list|)
argument_list|,
operator|(
name|abfd
operator|)
argument_list|,
name|bfd
operator|*
name|abfd
argument_list|)
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
if|#
directive|if
name|CHOOSE_RELOC_SIZE
name|CHOOSE_RELOC_SIZE
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
else|#
directive|else
name|obj_reloc_entry_size
argument_list|(
name|abfd
argument_list|)
operator|=
name|RELOC_STD_SIZE
expr_stmt|;
endif|#
directive|endif
name|WRITE_HEADERS
argument_list|(
name|abfd
argument_list|,
name|execp
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|MY_write_object_contents
value|MY(write_object_contents)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_set_sizes
end_ifndef

begin_decl_stmt
specifier|static
name|boolean
name|DEFUN
argument_list|(
name|MY
argument_list|(
name|set_sizes
argument_list|)
argument_list|,
operator|(
name|abfd
operator|)
argument_list|,
name|bfd
operator|*
name|abfd
argument_list|)
block|{
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|page_size
operator|=
name|PAGE_SIZE
expr_stmt|;
ifdef|#
directive|ifdef
name|SEGMENT_SIZE
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|segment_size
operator|=
name|SEGMENT_SIZE
expr_stmt|;
else|#
directive|else
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|segment_size
operator|=
name|PAGE_SIZE
expr_stmt|;
endif|#
directive|endif
name|adata
argument_list|(
name|abfd
argument_list|)
operator|.
name|exec_bytes_size
operator|=
name|EXEC_BYTES_SIZE
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_define
define|#
directive|define
name|MY_set_sizes
value|MY(set_sizes)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_backend_data
end_ifndef

begin_expr_stmt
specifier|static
name|CONST
expr|struct
name|aout_backend_data
name|MY
argument_list|(
name|backend_data
argument_list|)
operator|=
block|{
literal|0
block|,
comment|/* zmagic contiguous */
literal|0
block|,
comment|/* text incl header */
literal|0
block|,
comment|/* text vma? */
name|MY_set_sizes
block|,
literal|0
block|,
comment|/* exec header is counted */
block|}
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|MY_backend_data
value|&MY(backend_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We assume BFD generic archive files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_openr_next_archived_file
end_ifndef

begin_define
define|#
directive|define
name|MY_openr_next_archived_file
value|bfd_generic_openr_next_archived_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_generic_stat_arch_elt
end_ifndef

begin_define
define|#
directive|define
name|MY_generic_stat_arch_elt
value|bfd_generic_stat_arch_elt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_slurp_armap
end_ifndef

begin_define
define|#
directive|define
name|MY_slurp_armap
value|bfd_slurp_bsd_armap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_slurp_extended_name_table
end_ifndef

begin_define
define|#
directive|define
name|MY_slurp_extended_name_table
value|_bfd_slurp_extended_name_table
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_write_armap
end_ifndef

begin_define
define|#
directive|define
name|MY_write_armap
value|bsd_write_armap
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_truncate_arname
end_ifndef

begin_define
define|#
directive|define
name|MY_truncate_arname
value|bfd_bsd_truncate_arname
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No core file defined here -- configure in trad-core.c separately.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_failing_command
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_failing_command
value|_bfd_dummy_core_file_failing_command
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_failing_signal
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_failing_signal
value|_bfd_dummy_core_file_failing_signal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_matches_executable_p
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_matches_executable_p
define|\
value|_bfd_dummy_core_file_matches_executable_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_p
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_p
value|_bfd_dummy_target
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_start
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_start
value|bfd_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_end
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_end
value|bfd_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_accumulate
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_accumulate
define|\
value|(void (*) PARAMS ((bfd*, struct sec *))) bfd_void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_failing_command
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_failing_command
value|NAME(aout,core_file_failing_command)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_failing_signal
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_failing_signal
value|NAME(aout,core_file_failing_signal)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_core_file_matches_executable_p
end_ifndef

begin_define
define|#
directive|define
name|MY_core_file_matches_executable_p
value|NAME(aout,core_file_matches_executable_p)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_slurp_armap
end_ifndef

begin_define
define|#
directive|define
name|MY_slurp_armap
value|NAME(aout,slurp_armap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_slurp_extended_name_table
end_ifndef

begin_define
define|#
directive|define
name|MY_slurp_extended_name_table
value|NAME(aout,slurp_extended_name_table)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_truncate_arname
end_ifndef

begin_define
define|#
directive|define
name|MY_truncate_arname
value|NAME(aout,truncate_arname)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_write_armap
end_ifndef

begin_define
define|#
directive|define
name|MY_write_armap
value|NAME(aout,write_armap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_close_and_cleanup
end_ifndef

begin_define
define|#
directive|define
name|MY_close_and_cleanup
value|NAME(aout,close_and_cleanup)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_set_section_contents
end_ifndef

begin_define
define|#
directive|define
name|MY_set_section_contents
value|NAME(aout,set_section_contents)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_section_contents
end_ifndef

begin_define
define|#
directive|define
name|MY_get_section_contents
value|NAME(aout,get_section_contents)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_new_section_hook
end_ifndef

begin_define
define|#
directive|define
name|MY_new_section_hook
value|NAME(aout,new_section_hook)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_symtab_upper_bound
end_ifndef

begin_define
define|#
directive|define
name|MY_get_symtab_upper_bound
value|NAME(aout,get_symtab_upper_bound)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_symtab
end_ifndef

begin_define
define|#
directive|define
name|MY_get_symtab
value|NAME(aout,get_symtab)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_reloc_upper_bound
end_ifndef

begin_define
define|#
directive|define
name|MY_get_reloc_upper_bound
value|NAME(aout,get_reloc_upper_bound)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_canonicalize_reloc
end_ifndef

begin_define
define|#
directive|define
name|MY_canonicalize_reloc
value|NAME(aout,canonicalize_reloc)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_make_empty_symbol
end_ifndef

begin_define
define|#
directive|define
name|MY_make_empty_symbol
value|NAME(aout,make_empty_symbol)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_print_symbol
end_ifndef

begin_define
define|#
directive|define
name|MY_print_symbol
value|NAME(aout,print_symbol)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_symbol_info
end_ifndef

begin_define
define|#
directive|define
name|MY_get_symbol_info
value|NAME(aout,get_symbol_info)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_get_lineno
end_ifndef

begin_define
define|#
directive|define
name|MY_get_lineno
value|NAME(aout,get_lineno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_set_arch_mach
end_ifndef

begin_define
define|#
directive|define
name|MY_set_arch_mach
value|NAME(aout,set_arch_mach)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_openr_next_archived_file
end_ifndef

begin_define
define|#
directive|define
name|MY_openr_next_archived_file
value|NAME(aout,openr_next_archived_file)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_find_nearest_line
end_ifndef

begin_define
define|#
directive|define
name|MY_find_nearest_line
value|NAME(aout,find_nearest_line)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_generic_stat_arch_elt
end_ifndef

begin_define
define|#
directive|define
name|MY_generic_stat_arch_elt
value|NAME(aout,generic_stat_arch_elt)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_sizeof_headers
end_ifndef

begin_define
define|#
directive|define
name|MY_sizeof_headers
value|NAME(aout,sizeof_headers)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_start
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_start
value|NAME(aout,bfd_debug_info_start)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_end
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_end
value|NAME(aout,bfd_debug_info_end)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_bfd_debug_info_accumulat
end_ifndef

begin_define
define|#
directive|define
name|MY_bfd_debug_info_accumulat
value|NAME(aout,bfd_debug_info_accumulat)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_reloc_howto_type_lookup
end_ifndef

begin_define
define|#
directive|define
name|MY_reloc_howto_type_lookup
value|NAME(aout,reloc_type_lookup)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_make_debug_symbol
end_ifndef

begin_define
define|#
directive|define
name|MY_make_debug_symbol
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Aout symbols normally have leading underscores */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MY_symbol_leading_char
end_ifndef

begin_define
define|#
directive|define
name|MY_symbol_leading_char
value|'_'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Aout archives normally use spaces for padding */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AR_PAD_CHAR
end_ifndef

begin_define
define|#
directive|define
name|AR_PAD_CHAR
value|' '
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MY_BFD_TARGET
end_ifndef

begin_function_decl
name|bfd_target
name|MY
parameter_list|(
name|vec
parameter_list|)
init|=
block|{
name|TARGETNAME
operator|,
comment|/* name */
function_decl|bfd_target_aout_flavour
operator|,
ifdef|#
directive|ifdef
name|TARGET_IS_BIG_ENDIAN_P
function_decl|true
operator|,
comment|/* target byte order (big) */
function_decl|true
operator|,
comment|/* target headers byte order (big) */
else|#
directive|else
function_decl|false
operator|,
comment|/* target byte order (little) */
function_decl|false
operator|,
comment|/* target headers byte order (little) */
endif|#
directive|endif
parameter_list|(
function_decl|HAS_RELOC | EXEC_P |
comment|/* object flags */
function_decl|HAS_LINENO | HAS_DEBUG |    HAS_SYMS | HAS_LOCALS | DYNAMIC | WP_TEXT | D_PAGED
end_function_decl

begin_operator
unit|)
operator|,
end_operator

begin_expr_stmt
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
operator|,
comment|/* section flags */
name|MY_symbol_leading_char
operator|,
name|AR_PAD_CHAR
operator|,
comment|/* ar_pad_char */
literal|15
operator|,
comment|/* ar_max_namelen */
literal|3
operator|,
comment|/* minimum alignment */
ifdef|#
directive|ifdef
name|TARGET_IS_BIG_ENDIAN_P
name|bfd_getb64
operator|,
name|bfd_getb_signed_64
operator|,
name|bfd_putb64
operator|,
name|bfd_getb32
operator|,
name|bfd_getb_signed_32
operator|,
name|bfd_putb32
operator|,
name|bfd_getb16
operator|,
name|bfd_getb_signed_16
operator|,
name|bfd_putb16
operator|,
comment|/* data */
name|bfd_getb64
operator|,
name|bfd_getb_signed_64
operator|,
name|bfd_putb64
operator|,
name|bfd_getb32
operator|,
name|bfd_getb_signed_32
operator|,
name|bfd_putb32
operator|,
name|bfd_getb16
operator|,
name|bfd_getb_signed_16
operator|,
name|bfd_putb16
operator|,
comment|/* hdrs */
else|#
directive|else
name|bfd_getl64
operator|,
name|bfd_getl_signed_64
operator|,
name|bfd_putl64
operator|,
name|bfd_getl32
operator|,
name|bfd_getl_signed_32
operator|,
name|bfd_putl32
operator|,
name|bfd_getl16
operator|,
name|bfd_getl_signed_16
operator|,
name|bfd_putl16
operator|,
comment|/* data */
name|bfd_getl64
operator|,
name|bfd_getl_signed_64
operator|,
name|bfd_putl64
operator|,
name|bfd_getl32
operator|,
name|bfd_getl_signed_32
operator|,
name|bfd_putl32
operator|,
name|bfd_getl16
operator|,
name|bfd_getl_signed_16
operator|,
name|bfd_putl16
operator|,
comment|/* hdrs */
endif|#
directive|endif
block|{
name|_bfd_dummy_target
block|,
name|MY_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|MY_core_file_p
block|}
operator|,
block|{
name|bfd_false
block|,
name|MY_mkobject
block|,
comment|/* bfd_set_format */
name|_bfd_generic_mkarchive
block|,
name|bfd_false
block|}
operator|,
block|{
name|bfd_false
block|,
name|MY_write_object_contents
block|,
comment|/* bfd_write_contents */
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
operator|,
name|MY_core_file_failing_command
operator|,
name|MY_core_file_failing_signal
operator|,
name|MY_core_file_matches_executable_p
operator|,
name|MY_slurp_armap
operator|,
name|MY_slurp_extended_name_table
operator|,
name|MY_truncate_arname
operator|,
name|MY_write_armap
operator|,
name|MY_close_and_cleanup
operator|,
name|MY_set_section_contents
operator|,
name|MY_get_section_contents
operator|,
name|MY_new_section_hook
operator|,
name|MY_get_symtab_upper_bound
operator|,
name|MY_get_symtab
operator|,
name|MY_get_reloc_upper_bound
operator|,
name|MY_canonicalize_reloc
operator|,
name|MY_make_empty_symbol
operator|,
name|MY_print_symbol
operator|,
name|MY_get_symbol_info
operator|,
name|MY_get_lineno
operator|,
name|MY_set_arch_mach
operator|,
name|MY_openr_next_archived_file
operator|,
name|MY_find_nearest_line
operator|,
name|MY_generic_stat_arch_elt
operator|,
name|MY_sizeof_headers
operator|,
name|MY_bfd_debug_info_start
operator|,
name|MY_bfd_debug_info_end
operator|,
name|MY_bfd_debug_info_accumulate
operator|,
name|bfd_generic_get_relocated_section_contents
operator|,
name|bfd_generic_relax_section
operator|,
name|bfd_generic_seclet_link
operator|,
name|MY_reloc_howto_type_lookup
operator|,
name|MY_make_debug_symbol
operator|,
operator|(
name|PTR
operator|)
name|MY_backend_data
operator|,
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* MY_BFD_TARGET */
end_comment

end_unit

