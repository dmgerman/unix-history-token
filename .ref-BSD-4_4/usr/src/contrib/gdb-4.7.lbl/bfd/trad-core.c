begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back end for traditional Unix core files (U-area and raw sections)    Copyright (C) 1988, 1989, 1991 Free Software Foundation, Inc.    Written by John Gilmore of Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

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
comment|/* This struct is just for allocating two things with one zalloc, so      they will be freed together, without violating alignment constraints. */
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
return|return
literal|0
return|;
comment|/* Too small to be a core file */
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
return|return
literal|0
return|;
if|if
condition|(
name|u
operator|.
name|u_ssize
operator|>
literal|0x1000000
condition|)
return|return
literal|0
return|;
comment|/* Check that the size claimed is no greater than the file size. FIXME. */
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
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_CORE_COMMAND
argument_list|)
operator|&&
name|BSD
operator|<
literal|199207
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
return|return
operator|-
literal|1
return|;
comment|/* FIXME, where is it? */
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
value|(PROTO (boolean, (*),	\      (bfd *arch, unsigned int elength, struct orl *map, \       unsigned int orl_count, int stridx))) bfd_false
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
value|(PROTO(boolean, (*),	\          (bfd *abfd, asection *section, PTR data, file_ptr offset,	\          bfd_size_type count))) bfd_false
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
value|(PROTO (boolean, (*),	\ 	(bfd *, sec_ptr))) bfd_true
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
value|(PROTO (unsigned int, (*), \         (bfd *, struct symbol_cache_entry **))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_get_reloc_upper_bound
value|(PROTO (unsigned int, (*), \ 	(bfd *, sec_ptr))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_canonicalize_reloc
value|(PROTO (unsigned int, (*), \ 	(bfd *, sec_ptr, arelent **, struct symbol_cache_entry**))) bfd_0u
end_define

begin_define
define|#
directive|define
name|trad_unix_make_empty_symbol
value|(PROTO (		\ 	struct symbol_cache_entry *, (*), (bfd *))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_print_symbol
value|(PROTO (void, (*),	\ 	(bfd *, PTR, struct symbol_cache_entry  *,			\ 	 bfd_print_symbol_type))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_get_lineno
value|(PROTO (alent *, (*),	\ 	(bfd *, struct symbol_cache_entry *))) bfd_nullvoidptr
end_define

begin_define
define|#
directive|define
name|trad_unix_set_arch_mach
value|(PROTO (boolean, (*),	\ 	(bfd *, enum bfd_architecture, unsigned long))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_find_nearest_line
value|(PROTO (boolean, (*),	\         (bfd *abfd, struct sec  *section,				\          struct symbol_cache_entry  **symbols,bfd_vma offset,		\          CONST char **file, CONST char **func, unsigned int *line))) bfd_false
end_define

begin_define
define|#
directive|define
name|trad_unix_sizeof_headers
value|(PROTO (int, (*),	\ 	(bfd *, boolean))) bfd_0
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
value|(PROTO (void, (*),	\ 	(bfd *, struct sec *))) bfd_void
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
value|((PROTO(bfd_vma, (*), (         bfd_byte *))) swap_abort )
end_define

begin_define
define|#
directive|define
name|NO_PUT
value|((PROTO(void,    (*), (bfd_vma, bfd_byte *))) swap_abort )
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
literal|'_'
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
name|NO_PUT
block|,
name|NO_GET
block|,
name|NO_PUT
block|,
name|NO_GET
block|,
name|NO_PUT
block|,
comment|/* data */
name|NO_GET
block|,
name|NO_PUT
block|,
name|NO_GET
block|,
name|NO_PUT
block|,
name|NO_GET
block|,
name|NO_PUT
block|,
comment|/* hdrs */
block|{
name|_bfd_dummy_target
block|,
name|_bfd_dummy_target
block|,
name|_bfd_dummy_target
block|,
name|trad_unix_core_file_p
block|}
block|,
block|{
name|bfd_false
block|,
name|bfd_false
block|,
comment|/* bfd_create_object */
name|bfd_false
block|,
name|bfd_false
block|}
block|,
block|{
name|bfd_false
block|,
name|bfd_false
block|,
comment|/* bfd_write_contents */
name|bfd_false
block|,
name|bfd_false
block|}
block|,
name|JUMP_TABLE
argument_list|(
argument|trad_unix
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

end_unit

