begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back end for traditional Unix core files (U-area and raw sections)    Copyright 1988, 1989, 1991, 1992, 1993 Free Software Foundation, Inc.    Written by John Gilmore of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* To use this file on a particular host, configure the host with these    parameters in the config/h-HOST file:  	HDEFINES=-DTRAD_CORE 	HDEPFILES=trad-core.o   */
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
file|"libaout.h"
end_include

begin_comment
comment|/* BFD a.out internal data structures */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_comment
comment|/* After a.out.h  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* file.h is included by std-host.h.  So we better not try to include it    twice; on some systems (dpx2) it is not protected against multiple    inclusion.  I have checked that all the hosts which use this file    include sys/file.h in the hosts file.  */
end_comment

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_struct
struct|struct
name|trad_core_struct
block|{
name|asection
modifier|*
name|data_section
decl_stmt|;
name|asection
modifier|*
name|stack_section
decl_stmt|;
name|asection
modifier|*
name|reg_section
decl_stmt|;
name|struct
name|user
name|u
decl_stmt|;
block|}
modifier|*
name|rawptr
struct|;
end_struct

begin_define
define|#
directive|define
name|core_upage
parameter_list|(
name|bfd
parameter_list|)
value|(&((bfd)->tdata.trad_core_data->u))
end_define

begin_define
define|#
directive|define
name|core_datasec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.trad_core_data->data_section)
end_define

begin_define
define|#
directive|define
name|core_stacksec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.trad_core_data->stack_section)
end_define

begin_define
define|#
directive|define
name|core_regsec
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.trad_core_data->reg_section)
end_define

begin_comment
comment|/* forward declarations */
end_comment

begin_decl_stmt
name|bfd_target
modifier|*
name|trad_unix_core_file_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|trad_unix_core_file_failing_command
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|trad_unix_core_file_failing_signal
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|trad_unix_core_file_matches_executable_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|core_bfd
operator|,
name|bfd
operator|*
name|exec_bfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Handle 4.2-style (and perhaps also sysV-style) core dump file.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|bfd_target
modifier|*
name|trad_unix_core_file_p
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|int
name|val
decl_stmt|;
name|struct
name|user
name|u
decl_stmt|;
ifdef|#
directive|ifdef
name|TRAD_CORE_USER_OFFSET
comment|/* If defined, this macro is the file position of the user struct.  */
if|if
condition|(
name|bfd_seek
argument_list|(
name|abfd
argument_list|,
name|TRAD_CORE_USER_OFFSET
argument_list|,
name|SEEK_SET
argument_list|)
operator|==
literal|0
condition|)
return|return
literal|0
return|;
endif|#
directive|endif
name|val
operator|=
name|bfd_read
argument_list|(
operator|(
name|void
operator|*
operator|)
operator|&
name|u
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
name|u
argument_list|,
name|abfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|!=
sizeof|sizeof
name|u
condition|)
block|{
comment|/* Too small to be a core file */
name|bfd_error
operator|=
name|wrong_format
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* Sanity check perhaps??? */
if|if
condition|(
name|u
operator|.
name|u_dsize
operator|>
literal|0x1000000
condition|)
comment|/* Remember, it's in pages... */
block|{
name|bfd_error
operator|=
name|wrong_format
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|u
operator|.
name|u_ssize
operator|>
literal|0x1000000
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
comment|/* Check that the size claimed is no greater than the file size.  */
block|{
name|FILE
modifier|*
name|stream
init|=
name|bfd_cache_lookup
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
name|struct
name|stat
name|statbuf
decl_stmt|;
if|if
condition|(
name|stream
operator|==
name|NULL
condition|)
return|return
literal|0
return|;
if|if
condition|(
name|fstat
argument_list|(
name|fileno
argument_list|(
name|stream
argument_list|)
argument_list|,
operator|&
name|statbuf
argument_list|)
operator|<
literal|0
condition|)
block|{
name|bfd_error
operator|=
name|system_call_error
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|NBPG
operator|*
operator|(
name|UPAGES
operator|+
name|u
operator|.
name|u_dsize
operator|+
name|u
operator|.
name|u_ssize
operator|)
operator|>
name|statbuf
operator|.
name|st_size
condition|)
block|{
name|bfd_error
operator|=
name|file_truncated
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|NBPG
operator|*
operator|(
name|UPAGES
operator|+
name|u
operator|.
name|u_dsize
operator|+
name|u
operator|.
name|u_ssize
operator|)
ifdef|#
directive|ifdef
name|TRAD_CORE_EXTRA_SIZE_ALLOWED
comment|/* Some systems write the file too big.  */
operator|+
name|TRAD_CORE_EXTRA_SIZE_ALLOWED
endif|#
directive|endif
operator|<
name|statbuf
operator|.
name|st_size
condition|)
block|{
comment|/* The file is too big.  Maybe it's not a core file 	   or we otherwise have bad values for u_dsize and u_ssize).  */
name|bfd_error
operator|=
name|wrong_format
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
comment|/* OK, we believe you.  You're a core file (sure, sure).  */
comment|/* Allocate both the upage and the struct core_data at once, so      a single free() will free them both.  */
name|rawptr
operator|=
operator|(
expr|struct
name|trad_core_struct
operator|*
operator|)
name|bfd_zalloc
argument_list|(
name|abfd
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|trad_core_struct
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|rawptr
operator|==
name|NULL
condition|)
block|{
name|bfd_error
operator|=
name|no_memory
expr_stmt|;
return|return
literal|0
return|;
block|}
name|abfd
operator|->
name|tdata
operator|.
name|trad_core_data
operator|=
name|rawptr
expr_stmt|;
name|rawptr
operator|->
name|u
operator|=
name|u
expr_stmt|;
comment|/*Copy the uarea into the tdata part of the bfd */
comment|/* Create the sections.  This is raunchy, but bfd_close wants to free      them separately.  */
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|=
operator|(
name|asection
operator|*
operator|)
name|zalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|asection
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|loser
label|:
name|bfd_error
operator|=
name|no_memory
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|rawptr
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|=
operator|(
name|asection
operator|*
operator|)
name|zalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|asection
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|loser1
label|:
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
argument_list|)
expr_stmt|;
goto|goto
name|loser
goto|;
block|}
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|=
operator|(
name|asection
operator|*
operator|)
name|zalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|asection
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|core_datasec
argument_list|(
name|abfd
argument_list|)
argument_list|)
expr_stmt|;
goto|goto
name|loser1
goto|;
block|}
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|name
operator|=
literal|".stack"
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|name
operator|=
literal|".data"
expr_stmt|;
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|name
operator|=
literal|".reg"
expr_stmt|;
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|flags
operator|=
name|SEC_ALLOC
operator|+
name|SEC_LOAD
operator|+
name|SEC_HAS_CONTENTS
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|flags
operator|=
name|SEC_ALLOC
operator|+
name|SEC_LOAD
operator|+
name|SEC_HAS_CONTENTS
expr_stmt|;
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|flags
operator|=
name|SEC_ALLOC
operator|+
name|SEC_HAS_CONTENTS
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|_raw_size
operator|=
name|NBPG
operator|*
name|u
operator|.
name|u_dsize
expr_stmt|;
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|_raw_size
operator|=
name|NBPG
operator|*
name|u
operator|.
name|u_ssize
expr_stmt|;
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|_raw_size
operator|=
name|NBPG
operator|*
name|UPAGES
expr_stmt|;
comment|/* Larger than sizeof struct u */
comment|/* What a hack... we'd like to steal it from the exec file,      since the upage does not seem to provide it.  FIXME.  */
ifdef|#
directive|ifdef
name|HOST_DATA_START_ADDR
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|HOST_DATA_START_ADDR
expr_stmt|;
else|#
directive|else
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|HOST_TEXT_START_ADDR
operator|+
operator|(
name|NBPG
operator|*
name|u
operator|.
name|u_tsize
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* a hack, but it works for FreeBSD !! */
include|#
directive|include
file|<vm/vm_param.h>
comment|/* this should really be in<vm/vm_param.h>, but somebody forgot it */
ifndef|#
directive|ifndef
name|vm_page_size
define|#
directive|define
name|vm_page_size
value|4096
endif|#
directive|endif
define|#
directive|define
name|HOST_STACK_START_ADDR
value|trunc_page(u.u_kproc.kp_eproc.e_vm.vm_maxsaddr \ + MAXSSIZ - ctob(u.u_ssize))
ifdef|#
directive|ifdef
name|HOST_STACK_START_ADDR
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|HOST_STACK_START_ADDR
expr_stmt|;
else|#
directive|else
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
name|HOST_STACK_END_ADDR
operator|-
operator|(
name|NBPG
operator|*
name|u
operator|.
name|u_ssize
operator|)
expr_stmt|;
endif|#
directive|endif
comment|/* This is tricky.  As the "register section", we give them the entire      upage and stack.  u.u_ar0 points to where "register 0" is stored.      There are two tricks with this, though.  One is that the rest of the      registers might be at positive or negative (or both) displacements      from *u_ar0.  The other is that u_ar0 is sometimes an absolute address      in kernel memory, and on other systems it is an offset from the beginning      of the `struct user'.            As a practical matter, we don't know where the registers actually are,      so we have to pass the whole area to GDB.  We encode the value of u_ar0      by setting the .regs section up so that its virtual memory address      0 is at the place pointed to by u_ar0 (by setting the vma of the start      of the section to -u_ar0).  GDB uses this info to locate the regs,      using minor trickery to get around the offset-or-absolute-addr problem. */
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|vma
operator|=
literal|0
operator|-
operator|(
name|int
operator|)
name|u
operator|.
name|u_ar0
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
name|NBPG
operator|*
name|UPAGES
expr_stmt|;
ifdef|#
directive|ifdef
name|TRAD_CORE_STACK_FILEPOS
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
name|TRAD_CORE_STACK_FILEPOS
expr_stmt|;
else|#
directive|else
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
operator|(
name|NBPG
operator|*
name|UPAGES
operator|)
operator|+
name|NBPG
operator|*
name|u
operator|.
name|u_dsize
expr_stmt|;
endif|#
directive|endif
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|filepos
operator|=
literal|0
expr_stmt|;
comment|/* Register segment is the upage */
comment|/* Align to word at least */
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|alignment_power
operator|=
literal|2
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|alignment_power
operator|=
literal|2
expr_stmt|;
name|core_regsec
argument_list|(
name|abfd
argument_list|)
operator|->
name|alignment_power
operator|=
literal|2
expr_stmt|;
name|abfd
operator|->
name|sections
operator|=
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|core_stacksec
argument_list|(
name|abfd
argument_list|)
operator|->
name|next
operator|=
name|core_datasec
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|core_datasec
argument_list|(
name|abfd
argument_list|)
operator|->
name|next
operator|=
name|core_regsec
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|abfd
operator|->
name|section_count
operator|=
literal|3
expr_stmt|;
return|return
name|abfd
operator|->
name|xvec
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|trad_unix_core_file_failing_command
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
ifndef|#
directive|ifndef
name|NO_CORE_COMMAND
name|char
modifier|*
name|com
init|=
name|abfd
operator|->
name|tdata
operator|.
name|trad_core_data
operator|->
name|u
operator|.
name|u_comm
decl_stmt|;
if|if
condition|(
operator|*
name|com
condition|)
return|return
name|com
return|;
else|else
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|int
name|trad_unix_core_file_failing_signal
parameter_list|(
name|ignore_abfd
parameter_list|)
name|bfd
modifier|*
name|ignore_abfd
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
return|return
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
argument_list|(
name|ignore_abfd
argument_list|)
return|;
else|#
directive|else
return|return
operator|-
literal|1
return|;
comment|/* FIXME, where is it? */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|boolean
name|trad_unix_core_file_matches_executable_p
parameter_list|(
name|core_bfd
parameter_list|,
name|exec_bfd
parameter_list|)
name|bfd
modifier|*
name|core_bfd
decl_stmt|,
decl|*
name|exec_bfd
decl_stmt|;
end_function

begin_block
block|{
return|return
name|true
return|;
comment|/* FIXME, We have no way of telling at this point */
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/* No archive file support via this BFD */
end_comment

begin_define
define|#
directive|define
name|trad_unix_openr_next_archived_file
value|bfd_generic_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|trad_unix_generic_stat_arch_elt
value|bfd_generic_stat_arch_elt
end_define

begin_define
define|#
directive|define
name|trad_unix_slurp_armap
value|bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_slurp_extended_name_table
value|bfd_true
end_define

begin_define
define|#
directive|define
name|trad_unix_write_armap
value|(boolean (*) PARAMS	\     ((bfd *arch, unsigned int elength, struct orl *map, \       unsigned int orl_count, int stridx))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_truncate_arname
value|bfd_dont_truncate_arname
end_define

begin_define
define|#
directive|define
name|aout_32_openr_next_archived_file
value|bfd_generic_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|trad_unix_close_and_cleanup
value|bfd_generic_close_and_cleanup
end_define

begin_define
define|#
directive|define
name|trad_unix_set_section_contents
value|(boolean (*) PARAMS	\         ((bfd *abfd, asection *section, PTR data, file_ptr offset,	\         bfd_size_type count))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_get_section_contents
value|bfd_generic_get_section_contents
end_define

begin_define
define|#
directive|define
name|trad_unix_new_section_hook
value|(boolean (*) PARAMS	\ 	((bfd *, sec_ptr))) bfd_true
end_define

begin_define
define|#
directive|define
name|trad_unix_get_symtab_upper_bound
value|bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_get_symtab
value|(unsigned int (*) PARAMS \         ((bfd *, struct symbol_cache_entry **))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_get_reloc_upper_bound
value|(unsigned int (*) PARAMS \ 	((bfd *, sec_ptr))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_canonicalize_reloc
value|(unsigned int (*) PARAMS \ 	((bfd *, sec_ptr, arelent **, struct symbol_cache_entry**))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_make_empty_symbol
value|(struct symbol_cache_entry * \ 	(*) PARAMS ((bfd *))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_print_symbol
value|(void (*) PARAMS	\ 	((bfd *, PTR, struct symbol_cache_entry  *,			\ 	bfd_print_symbol_type))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_get_symbol_info
value|(void (*) PARAMS	\ 	((bfd *, struct symbol_cache_entry  *,			\ 	symbol_info *))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_get_lineno
value|(alent * (*) PARAMS	\ 	((bfd *, struct symbol_cache_entry *))) bfd_nullvoidptr
end_define

begin_define
define|#
directive|define
name|trad_unix_set_arch_mach
value|(boolean (*) PARAMS	\ 	((bfd *, enum bfd_architecture, unsigned long))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_find_nearest_line
value|(boolean (*) PARAMS	\         ((bfd *abfd, struct sec  *section,				\          struct symbol_cache_entry  **symbols,bfd_vma offset,		\          CONST char **file, CONST char **func, unsigned int *line))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_sizeof_headers
value|(int (*) PARAMS	\ 	((bfd *, boolean))) bfd_0
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_debug_info_start
value|bfd_void
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_debug_info_end
value|bfd_void
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_debug_info_accumulate
value|(void (*) PARAMS	\ 	((bfd *, struct sec *))) bfd_void
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_get_relocated_section_contents
value|bfd_generic_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_relax_section
value|bfd_generic_relax_section
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_seclet_link
define|\
value|((boolean (*) PARAMS ((bfd *, PTR, boolean))) bfd_false)
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_reloc_type_lookup
define|\
value|((CONST struct reloc_howto_struct *(*) PARAMS ((bfd *, bfd_reloc_code_real_type))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|trad_unix_bfd_make_debug_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *, void *, unsigned long))) bfd_nullvoidptr)
end_define

begin_comment
comment|/* If somebody calls any byte-swapping routines, shoot them.  */
end_comment

begin_function
name|void
name|swap_abort
parameter_list|()
block|{
name|abort
argument_list|()
expr_stmt|;
comment|/* This way doesn't require any declaration for ANSI to fuck up */
block|}
end_function

begin_define
define|#
directive|define
name|NO_GET
value|((bfd_vma (*) PARAMS ((         bfd_byte *))) swap_abort )
end_define

begin_define
define|#
directive|define
name|NO_PUT
value|((void    (*) PARAMS ((bfd_vma, bfd_byte *))) swap_abort )
end_define

begin_define
define|#
directive|define
name|NO_SIGNED_GET
value|((bfd_signed_vma (*) PARAMS ((bfd_byte *))) swap_abort )
end_define

begin_decl_stmt
name|bfd_target
name|trad_core_vec
init|=
block|{
literal|"trad-core"
block|,
name|bfd_target_unknown_flavour
block|,
name|true
block|,
comment|/* target byte order */
name|true
block|,
comment|/* target headers byte order */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* object flags */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator||
name|D_PAGED
operator|)
block|,
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* section flags */
literal|0
block|,
comment|/* symbol prefix */
literal|' '
block|,
comment|/* ar_pad_char */
literal|16
block|,
comment|/* ar_max_namelen */
literal|3
block|,
comment|/* minimum alignment power */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 64 bit data */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 32 bit data */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 16 bit data */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 64 bit hdrs */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 32 bit hdrs */
name|NO_GET
block|,
name|NO_SIGNED_GET
block|,
name|NO_PUT
block|,
comment|/* 16 bit hdrs */
block|{
comment|/* bfd_check_format */
name|_bfd_dummy_target
block|,
comment|/* unknown format */
name|_bfd_dummy_target
block|,
comment|/* object file */
name|_bfd_dummy_target
block|,
comment|/* archive */
name|trad_unix_core_file_p
comment|/* a core file */
block|}
block|,
block|{
comment|/* bfd_set_format */
name|bfd_false
block|,
name|bfd_false
block|,
name|bfd_false
block|,
name|bfd_false
block|}
block|,
block|{
comment|/* bfd_write_contents */
name|bfd_false
block|,
name|bfd_false
block|,
name|bfd_false
block|,
name|bfd_false
block|}
block|,
name|JUMP_TABLE
argument_list|(
name|trad_unix
argument_list|)
block|,
operator|(
name|PTR
operator|)
literal|0
comment|/* backend_data */
block|}
decl_stmt|;
end_decl_stmt

end_unit

