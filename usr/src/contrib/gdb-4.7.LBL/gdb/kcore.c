begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Work with kernel crash dumps and live systems through kvm.    This module was developed at Lawrence Berkeley Laboratory    by Steven McCanne (mccanne@ee.lbl.gov).  It is derived from    the gdb module core.c.     Copyright 1986, 1987, 1989, 1991 Free Software Foundation, Inc.        This file is part of GDB.        This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_comment
comment|/* required by inferior.h */
end_comment

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_comment
comment|/* KVM library handle */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL_XFER_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|KERNEL_XFER_MEMORY
value|kernel_xfer_memory
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|kvm_t
modifier|*
name|kd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward decl */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_ops
name|kernel_core_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Discard all vestiges of any previous core file    and mark data and stack spaces as empty.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|kernel_core_close
parameter_list|(
name|quitting
parameter_list|)
name|int
name|quitting
decl_stmt|;
block|{
if|if
condition|(
name|kd
operator|!=
literal|0
condition|)
block|{
name|kvm_close
argument_list|(
name|kd
argument_list|)
expr_stmt|;
name|kd
operator|=
literal|0
expr_stmt|;
block|}
name|kernel_debugging
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This routine opens and sets up the core file bfd */
end_comment

begin_function
name|void
name|kernel_core_open
parameter_list|(
name|filename
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|struct
name|cleanup
modifier|*
name|old_chain
decl_stmt|;
name|int
name|ontop
decl_stmt|;
name|char
modifier|*
name|execfile
decl_stmt|;
name|struct
name|stat
name|stb
decl_stmt|;
name|char
modifier|*
name|get_exec_file_name
parameter_list|()
function_decl|;
if|if
condition|(
name|kd
operator|!=
literal|0
condition|)
name|error
argument_list|(
literal|"kvm already target -- must detach first"
argument_list|)
expr_stmt|;
name|target_preopen
argument_list|(
name|from_tty
argument_list|)
expr_stmt|;
if|if
condition|(
name|filename
operator|==
literal|0
condition|)
name|error
argument_list|(
literal|"No core file specified."
argument_list|)
expr_stmt|;
name|filename
operator|=
name|tilde_expand
argument_list|(
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
name|filename
index|[
literal|0
index|]
operator|!=
literal|'/'
condition|)
block|{
name|cp
operator|=
name|concat
argument_list|(
name|current_directory
argument_list|,
literal|"/"
argument_list|,
name|filename
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|filename
argument_list|)
expr_stmt|;
name|filename
operator|=
name|cp
expr_stmt|;
block|}
name|old_chain
operator|=
name|make_cleanup
argument_list|(
name|free
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|execfile
operator|=
name|get_exec_file_name
argument_list|()
expr_stmt|;
if|if
condition|(
name|execfile
operator|==
literal|0
condition|)
name|error
argument_list|(
literal|"No executable image specified"
argument_list|)
expr_stmt|;
comment|/* 	 * If we want the active memory file, just use a null arg for kvm. 	 * The SunOS kvm can't read from the default swap device, unless 	 * /dev/mem is indicated with a null pointer.  This has got to be  	 * a bug. 	 */
if|if
condition|(
name|stat
argument_list|(
name|filename
argument_list|,
operator|&
name|stb
argument_list|)
operator|==
literal|0
operator|&&
name|S_ISCHR
argument_list|(
name|stb
operator|.
name|st_mode
argument_list|)
condition|)
name|filename
operator|=
literal|0
expr_stmt|;
name|kd
operator|=
name|kvm_open
argument_list|(
name|execfile
argument_list|,
name|filename
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|write_files
condition|?
name|O_RDWR
else|:
name|O_RDONLY
argument_list|,
literal|"gdb"
argument_list|)
expr_stmt|;
if|if
condition|(
name|kd
operator|==
literal|0
condition|)
name|error
argument_list|(
literal|"Cannot open kernel core image"
argument_list|)
expr_stmt|;
name|kernel_debugging
operator|=
literal|1
expr_stmt|;
name|unpush_target
argument_list|(
operator|&
name|kernel_core_ops
argument_list|)
expr_stmt|;
name|old_chain
operator|=
name|make_cleanup
argument_list|(
name|kernel_core_close
argument_list|,
operator|(
name|int
operator|)
name|kd
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|notdef
name|validate_files
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|ontop
operator|=
operator|!
name|push_target
argument_list|(
operator|&
name|kernel_core_ops
argument_list|)
expr_stmt|;
name|discard_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
if|if
condition|(
name|ontop
condition|)
block|{
comment|/* Fetch all registers from core file */
name|target_fetch_registers
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Now, set up the frame cache, and print the top of stack */
name|set_current_frame
argument_list|(
name|create_new_frame
argument_list|(
name|read_register
argument_list|(
name|FP_REGNUM
argument_list|)
argument_list|,
name|read_pc
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|select_frame
argument_list|(
name|get_current_frame
argument_list|()
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|print_stack_frame
argument_list|(
name|selected_frame
argument_list|,
name|selected_frame_level
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"Warning: you won't be able to access this core file until you terminate\n\ your %s; do ``info files''\n"
argument_list|,
name|current_target
operator|->
name|to_longname
argument_list|)
expr_stmt|;
block|}
comment|/* Machine dependent call to print out panic string etc. */
name|kerninfo
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|kernel_core_detach
parameter_list|(
name|args
parameter_list|,
name|from_tty
parameter_list|)
name|char
modifier|*
name|args
decl_stmt|;
name|int
name|from_tty
decl_stmt|;
block|{
if|if
condition|(
name|args
condition|)
name|error
argument_list|(
literal|"Too many arguments"
argument_list|)
expr_stmt|;
name|unpush_target
argument_list|(
operator|&
name|kernel_core_ops
argument_list|)
expr_stmt|;
if|if
condition|(
name|from_tty
condition|)
name|printf
argument_list|(
literal|"No kernel core file now.\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|kernel_core_files_info
parameter_list|(
name|t
parameter_list|)
name|struct
name|target_ops
modifier|*
name|t
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|notdef
name|struct
name|section_table
modifier|*
name|p
decl_stmt|;
name|printf_filtered
argument_list|(
literal|"\t`%s', "
argument_list|,
name|bfd_get_filename
argument_list|(
name|core_bfd
argument_list|)
argument_list|)
expr_stmt|;
name|wrap_here
argument_list|(
literal|"        "
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|"file type %s.\n"
argument_list|,
name|bfd_get_target
argument_list|(
name|core_bfd
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|p
operator|=
name|t
operator|->
name|sections
init|;
name|p
operator|<
name|t
operator|->
name|sections_end
condition|;
name|p
operator|++
control|)
block|{
name|printf_filtered
argument_list|(
literal|"\t%s"
argument_list|,
name|local_hex_string_custom
argument_list|(
name|p
operator|->
name|addr
argument_list|,
literal|"08"
argument_list|)
argument_list|)
expr_stmt|;
name|printf_filtered
argument_list|(
literal|" - %s is %s"
argument_list|,
name|local_hex_string_custom
argument_list|(
name|p
operator|->
name|endaddr
argument_list|,
literal|"08"
argument_list|)
argument_list|,
name|bfd_section_name
argument_list|(
name|p
operator|->
name|bfd
argument_list|,
name|p
operator|->
name|sec_ptr
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|bfd
operator|!=
name|core_bfd
condition|)
block|{
name|printf_filtered
argument_list|(
literal|" in %s"
argument_list|,
name|bfd_get_filename
argument_list|(
name|p
operator|->
name|bfd
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|printf_filtered
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Called by the machine dependent module to set a user context.  * We call kvm_getu() for this desired side effect.  * BSD kvm doesn't need to do this.  */
end_comment

begin_macro
name|kernel_getu
argument_list|(
argument|p
argument_list|)
end_macro

begin_decl_stmt
name|u_long
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|#
directive|if
name|BSD
operator|<
literal|199103
operator|&&
operator|!
name|defined
argument_list|(
name|ultrix
argument_list|)
if|if
condition|(
name|kd
operator|!=
literal|0
condition|)
return|return
operator|(
name|kvm_getu
argument_list|(
name|kd
argument_list|,
name|p
argument_list|)
operator|!=
literal|0
operator|)
return|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_function
name|int
name|kernel_xfer_memory
parameter_list|(
name|addr
parameter_list|,
name|cp
parameter_list|,
name|len
parameter_list|,
name|write
parameter_list|,
name|target
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|int
name|len
decl_stmt|;
name|int
name|write
decl_stmt|;
name|struct
name|target_ops
modifier|*
name|target
decl_stmt|;
block|{
if|if
condition|(
name|write
condition|)
return|return
name|kvm_write
argument_list|(
name|kd
argument_list|,
name|addr
argument_list|,
name|cp
argument_list|,
name|len
argument_list|)
return|;
else|else
return|return
name|kvm_read
argument_list|(
name|kd
argument_list|,
name|addr
argument_list|,
name|cp
argument_list|,
name|len
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*   * In target dependent module.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|kernel_core_registers
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|target_ops
name|kernel_core_ops
init|=
block|{
literal|"kvm"
block|,
comment|/* shortname */
literal|"Kernel core file"
block|,
comment|/* longname */
literal|"Use a kernel core file as a target.\   Specify the filename of the core file."
block|,
comment|/* doc */
name|kernel_core_open
block|,
comment|/* open */
name|kernel_core_close
block|,
comment|/* close */
literal|0
block|,
comment|/* attach */
name|kernel_core_detach
block|,
comment|/* detach */
literal|0
block|,
comment|/* resume */
literal|0
block|,
comment|/* wait */
name|kernel_core_registers
block|,
comment|/* fetch_registers */
literal|0
block|,
comment|/* store_registers */
literal|0
block|,
comment|/* prepare_to_store */
name|KERNEL_XFER_MEMORY
block|,
comment|/* xfer_memory */
name|kernel_core_files_info
block|,
comment|/* files_info */
literal|0
block|,
comment|/* insert_breakpoint */
literal|0
block|,
comment|/* remove_breakpoint */
literal|0
block|,
comment|/* terminal_init */
literal|0
block|,
comment|/* terminal_inferior */
literal|0
block|,
comment|/* terminal_ours_for_output */
literal|0
block|,
comment|/* terminal_ours */
literal|0
block|,
comment|/* terminal_info */
literal|0
block|,
comment|/* kill */
literal|0
block|,
comment|/* load */
literal|0
block|,
comment|/* lookup_symbol */
literal|0
block|,
comment|/* create_inferior */
literal|0
block|,
comment|/* mourn_inferior */
literal|0
block|,
comment|/* can_run */
literal|0
block|,
comment|/* notice_signals */
name|core_stratum
block|,
comment|/* stratum */
literal|0
block|,
comment|/* next */
literal|0
block|,
comment|/* has_all_memory */
literal|1
block|,
comment|/* has_memory */
literal|1
block|,
comment|/* has_stack */
literal|1
block|,
comment|/* has_registers */
literal|0
block|,
comment|/* has_execution */
literal|0
block|,
comment|/* sections */
literal|0
block|,
comment|/* sections_end */
name|OPS_MAGIC
block|,
comment|/* magic */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|_initialize_kernel_core
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|KERNELDEBUG
ifdef|#
directive|ifdef
name|notdef
name|add_com
argument_list|(
literal|"kcore"
argument_list|,
name|class_files
argument_list|,
name|core_file_command
argument_list|,
literal|"Use FILE as core dump for examining memory and registers.\n\ No arg means have no core file.  This command has been superseded by the\n\ `target core' and `detach' commands."
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|add_target
argument_list|(
operator|&
name|kernel_core_ops
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

end_unit

