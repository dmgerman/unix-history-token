begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libthread_db helper functions for the remote server for GDB.    Copyright 2002    Free Software Foundation, Inc.     Contributed by MontaVista Software.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_comment
comment|/* This file is currently tied to GNU/Linux.  It should scale well to    another libthread_db implementation, with the approriate gdbserver    hooks, but for now this means we can use GNU/Linux's target data.  */
end_comment

begin_include
include|#
directive|include
file|"linux-low.h"
end_include

begin_comment
comment|/* Correct for all GNU/Linux targets (for quite some time).  */
end_comment

begin_define
define|#
directive|define
name|GDB_GREGSET_T
value|elf_gregset_t
end_define

begin_define
define|#
directive|define
name|GDB_FPREGSET_T
value|elf_fpregset_t
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_ELF_FPREGSET_T
end_ifndef

begin_comment
comment|/* Make sure we have said types.  Not all platforms bring in<linux/elf.h>    via<sys/procfs.h>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINUX_ELF_H
end_ifdef

begin_include
include|#
directive|include
file|<linux/elf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"../gdb_proc_service.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|ps_prochandle
modifier|*
name|gdb_ps_prochandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|gdb_ps_read_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|void
modifier|*
name|gdb_ps_write_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
name|gdb_ps_size_t
typedef|;
end_typedef

begin_comment
comment|/* FIXME redo this right */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_LINUX_REGSETS
end_ifndef

begin_error
error|#
directive|error
error|HAVE_LINUX_REGSETS required!
end_error

begin_else
else|#
directive|else
end_else

begin_endif
unit|static struct regset_info * gregset_info(void) {   int i = 0;    while (target_regsets[i].size != -1)     {       if (target_regsets[i].type == GENERAL_REGS) 	break;       i++;     }    return&target_regsets[i]; }  static struct regset_info * fpregset_info(void) {   int i = 0;    while (target_regsets[i].size != -1)     {       if (target_regsets[i].type == FP_REGS) 	break;       i++;     }    return&target_regsets[i]; }
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Search for the symbol named NAME within the object named OBJ within    the target process PH.  If the symbol is found the address of the    symbol is stored in SYM_ADDR.  */
end_comment

begin_function
name|ps_err_e
name|ps_pglobal_lookup
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
specifier|const
name|char
modifier|*
name|obj
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|paddr_t
modifier|*
name|sym_addr
parameter_list|)
block|{
name|CORE_ADDR
name|addr
decl_stmt|;
if|if
condition|(
name|look_up_one_symbol
argument_list|(
name|name
argument_list|,
operator|&
name|addr
argument_list|)
operator|==
literal|0
condition|)
return|return
name|PS_NOSYM
return|;
operator|*
name|sym_addr
operator|=
operator|(
name|paddr_t
operator|)
operator|(
name|unsigned
name|long
operator|)
name|addr
expr_stmt|;
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Read SIZE bytes from the target process PH at address ADDR and copy    them into BUF.  */
end_comment

begin_function
name|ps_err_e
name|ps_pdread
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|paddr_t
name|addr
parameter_list|,
name|gdb_ps_read_buf_t
name|buf
parameter_list|,
name|gdb_ps_size_t
name|size
parameter_list|)
block|{
name|read_inferior_memory
argument_list|(
name|addr
argument_list|,
name|buf
argument_list|,
name|size
argument_list|)
expr_stmt|;
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Write SIZE bytes from BUF into the target process PH at address ADDR.  */
end_comment

begin_function
name|ps_err_e
name|ps_pdwrite
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|paddr_t
name|addr
parameter_list|,
name|gdb_ps_write_buf_t
name|buf
parameter_list|,
name|gdb_ps_size_t
name|size
parameter_list|)
block|{
return|return
name|write_inferior_memory
argument_list|(
name|addr
argument_list|,
name|buf
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Get the general registers of LWP LWPID within the target process PH    and store them in GREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lgetregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
name|prgregset_t
name|gregset
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct thread_info *reg_inferior, *save_inferior;   void *regcache;    reg_inferior = (struct thread_info *) find_inferior_id (&all_threads, 							  lwpid);   if (reg_inferior == NULL)     return PS_ERR;    save_inferior = current_inferior;   current_inferior = reg_inferior;    regcache = new_register_cache ();   the_target->fetch_registers (0, regcache);   gregset_info()->fill_function (gregset, regcache);   free_register_cache (regcache);    current_inferior = save_inferior;   return PS_OK;
endif|#
directive|endif
comment|/* FIXME */
return|return
name|PS_ERR
return|;
block|}
end_function

begin_comment
comment|/* Set the general registers of LWP LWPID within the target process PH    from GREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lsetregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
specifier|const
name|prgregset_t
name|gregset
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct thread_info *reg_inferior, *save_inferior;   void *regcache;    reg_inferior = (struct thread_info *) find_inferior_id (&all_threads, lwpid);   if (reg_inferior == NULL)     return PS_ERR;    save_inferior = current_inferior;   current_inferior = reg_inferior;    regcache = new_register_cache ();   gregset_info()->store_function (gregset, regcache);   the_target->store_registers (0, regcache);   free_register_cache (regcache);    current_inferior = save_inferior;    return PS_OK;
endif|#
directive|endif
comment|/* FIXME */
return|return
name|PS_ERR
return|;
block|}
end_function

begin_comment
comment|/* Get the floating-point registers of LWP LWPID within the target    process PH and store them in FPREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lgetfpregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
name|gdb_prfpregset_t
modifier|*
name|fpregset
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct thread_info *reg_inferior, *save_inferior;   void *regcache;    reg_inferior = (struct thread_info *) find_inferior_id (&all_threads, lwpid);   if (reg_inferior == NULL)     return PS_ERR;    save_inferior = current_inferior;   current_inferior = reg_inferior;    regcache = new_register_cache ();   the_target->fetch_registers (0, regcache);   fpregset_info()->fill_function (fpregset, regcache);   free_register_cache (regcache);    current_inferior = save_inferior;    return PS_OK;
endif|#
directive|endif
comment|/* FIXME */
return|return
name|PS_ERR
return|;
block|}
end_function

begin_comment
comment|/* Set the floating-point registers of LWP LWPID within the target    process PH from FPREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lsetfpregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
specifier|const
name|gdb_prfpregset_t
modifier|*
name|fpregset
parameter_list|)
block|{
if|#
directive|if
literal|0
block|struct thread_info *reg_inferior, *save_inferior;   void *regcache;    reg_inferior = (struct thread_info *) find_inferior_id (&all_threads, lwpid);   if (reg_inferior == NULL)     return PS_ERR;    save_inferior = current_inferior;   current_inferior = reg_inferior;    regcache = new_register_cache ();   fpregset_info()->store_function (fpregset, regcache);   the_target->store_registers (0, regcache);   free_register_cache (regcache);    current_inferior = save_inferior;    return PS_OK;
endif|#
directive|endif
comment|/* FIXME */
return|return
name|PS_ERR
return|;
block|}
end_function

begin_comment
comment|/* Return overall process id of the target PH.  Special for GNU/Linux    -- not used on Solaris.  */
end_comment

begin_function
name|pid_t
name|ps_getpid
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|)
block|{
return|return
name|ph
operator|->
name|pid
return|;
block|}
end_function

end_unit

