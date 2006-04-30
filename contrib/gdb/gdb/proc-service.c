begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*<proc_service.h> implementation.     Copyright 1999, 2000, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"gdb_proc_service.h"
end_include

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

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
file|"target.h"
end_include

begin_comment
comment|/* Prototypes for supply_gregset etc.  */
end_comment

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Fix-up some broken systems.  */
end_comment

begin_comment
comment|/* The prototypes in<proc_service.h> are slightly different on older    systems.  Compensate for the discrepancies.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROC_SERVICE_IS_OLD
end_ifdef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|ps_prochandle
modifier|*
name|gdb_ps_prochandle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|gdb_ps_read_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|gdb_ps_write_buf_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gdb_ps_size_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Building process ids.  */
end_comment

begin_define
define|#
directive|define
name|BUILD_LWP
parameter_list|(
name|lwp
parameter_list|,
name|pid
parameter_list|)
value|ptid_build (pid, lwp, 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Helper functions.  */
end_comment

begin_comment
comment|/* Transfer LEN bytes of memory between BUF and address ADDR in the    process specified by PH.  If WRITE, transfer them to the process,    else transfer them from the process.  Returns PS_OK for success,    PS_ERR on failure.     This is a helper function for ps_pdread, ps_pdwrite, ps_ptread and    ps_ptwrite.  */
end_comment

begin_function
specifier|static
name|ps_err_e
name|ps_xfer_memory
parameter_list|(
specifier|const
name|struct
name|ps_prochandle
modifier|*
name|ph
parameter_list|,
name|paddr_t
name|addr
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|write
parameter_list|)
block|{
name|struct
name|cleanup
modifier|*
name|old_chain
init|=
name|save_inferior_ptid
argument_list|()
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|inferior_ptid
operator|=
name|pid_to_ptid
argument_list|(
name|ph
operator|->
name|pid
argument_list|)
expr_stmt|;
if|if
condition|(
name|write
condition|)
name|ret
operator|=
name|target_write_memory
argument_list|(
name|addr
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
else|else
name|ret
operator|=
name|target_read_memory
argument_list|(
name|addr
argument_list|,
name|buf
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|do_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
return|return
operator|(
name|ret
operator|==
literal|0
condition|?
name|PS_OK
else|:
name|PS_ERR
operator|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Stop the target process PH.  */
end_comment

begin_function
name|ps_err_e
name|ps_pstop
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|)
block|{
comment|/* The process is always stopped when under control of GDB.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Resume the target process PH.  */
end_comment

begin_function
name|ps_err_e
name|ps_pcontinue
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|)
block|{
comment|/* Pretend we did successfully continue the process.  GDB will take      care of it later on.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Stop the lightweight process LWPID within the target process PH.  */
end_comment

begin_function
name|ps_err_e
name|ps_lstop
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|)
block|{
comment|/* All lightweight processes are stopped when under control of GDB.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Resume the lightweight process (LWP) LWPID within the target    process PH.  */
end_comment

begin_function
name|ps_err_e
name|ps_lcontinue
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|)
block|{
comment|/* Pretend we did successfully continue LWPID.  GDB will take care      of it later on.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Get the size of the architecture-dependent extra state registers    for LWP LWPID within the target process PH and return it in    *XREGSIZE.  */
end_comment

begin_function
name|ps_err_e
name|ps_lgetxregsize
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
name|int
modifier|*
name|xregsize
parameter_list|)
block|{
comment|/* FIXME: Not supported yet.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Get the extra state registers of LWP LWPID within the target    process PH and store them in XREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lgetxregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
name|caddr_t
name|xregset
parameter_list|)
block|{
comment|/* FIXME: Not supported yet.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Set the extra state registers of LWP LWPID within the target    process PH from XREGSET.  */
end_comment

begin_function
name|ps_err_e
name|ps_lsetxregs
parameter_list|(
name|gdb_ps_prochandle_t
name|ph
parameter_list|,
name|lwpid_t
name|lwpid
parameter_list|,
name|caddr_t
name|xregset
parameter_list|)
block|{
comment|/* FIXME: Not supported yet.  */
return|return
name|PS_OK
return|;
block|}
end_function

begin_comment
comment|/* Log (additional) diognostic information.  */
end_comment

begin_function
name|void
name|ps_plog
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vfprintf_filtered
argument_list|(
name|gdb_stderr
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
expr_stmt|;
block|}
end_function

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
name|struct
name|minimal_symbol
modifier|*
name|ms
decl_stmt|;
comment|/* FIXME: kettenis/2000-09-03: What should we do with OBJ?  */
name|ms
operator|=
name|lookup_minimal_symbol
argument_list|(
name|name
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|ms
operator|==
name|NULL
condition|)
return|return
name|PS_NOSYM
return|;
operator|*
name|sym_addr
operator|=
name|SYMBOL_VALUE_ADDRESS
argument_list|(
name|ms
argument_list|)
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
return|return
name|ps_xfer_memory
argument_list|(
name|ph
argument_list|,
name|addr
argument_list|,
name|buf
argument_list|,
name|size
argument_list|,
literal|0
argument_list|)
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
name|ps_xfer_memory
argument_list|(
name|ph
argument_list|,
name|addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|size
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Read SIZE bytes from the target process PH at address ADDR and copy    them into BUF.  */
end_comment

begin_function
name|ps_err_e
name|ps_ptread
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
return|return
name|ps_xfer_memory
argument_list|(
name|ph
argument_list|,
name|addr
argument_list|,
name|buf
argument_list|,
name|size
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Write SIZE bytes from BUF into the target process PH at address ADDR.  */
end_comment

begin_function
name|ps_err_e
name|ps_ptwrite
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
name|ps_xfer_memory
argument_list|(
name|ph
argument_list|,
name|addr
argument_list|,
operator|(
name|char
operator|*
operator|)
name|buf
argument_list|,
name|size
argument_list|,
literal|1
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
name|struct
name|cleanup
modifier|*
name|old_chain
init|=
name|save_inferior_ptid
argument_list|()
decl_stmt|;
name|inferior_ptid
operator|=
name|BUILD_LWP
argument_list|(
name|lwpid
argument_list|,
name|ph
operator|->
name|pid
argument_list|)
expr_stmt|;
name|target_fetch_registers
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|fill_gregset
argument_list|(
operator|(
name|gdb_gregset_t
operator|*
operator|)
name|gregset
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|do_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
return|return
name|PS_OK
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
name|struct
name|cleanup
modifier|*
name|old_chain
init|=
name|save_inferior_ptid
argument_list|()
decl_stmt|;
name|inferior_ptid
operator|=
name|BUILD_LWP
argument_list|(
name|lwpid
argument_list|,
name|ph
operator|->
name|pid
argument_list|)
expr_stmt|;
comment|/* FIXME: We should really make supply_gregset const-correct.  */
name|supply_gregset
argument_list|(
operator|(
name|gdb_gregset_t
operator|*
operator|)
name|gregset
argument_list|)
expr_stmt|;
name|target_store_registers
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|do_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
return|return
name|PS_OK
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
name|struct
name|cleanup
modifier|*
name|old_chain
init|=
name|save_inferior_ptid
argument_list|()
decl_stmt|;
name|inferior_ptid
operator|=
name|BUILD_LWP
argument_list|(
name|lwpid
argument_list|,
name|ph
operator|->
name|pid
argument_list|)
expr_stmt|;
name|target_fetch_registers
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|fill_fpregset
argument_list|(
operator|(
name|gdb_fpregset_t
operator|*
operator|)
name|fpregset
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|do_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
return|return
name|PS_OK
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
name|struct
name|cleanup
modifier|*
name|old_chain
init|=
name|save_inferior_ptid
argument_list|()
decl_stmt|;
name|inferior_ptid
operator|=
name|BUILD_LWP
argument_list|(
name|lwpid
argument_list|,
name|ph
operator|->
name|pid
argument_list|)
expr_stmt|;
comment|/* FIXME: We should really make supply_fpregset const-correct.  */
name|supply_fpregset
argument_list|(
operator|(
name|gdb_fpregset_t
operator|*
operator|)
name|fpregset
argument_list|)
expr_stmt|;
name|target_store_registers
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|do_cleanups
argument_list|(
name|old_chain
argument_list|)
expr_stmt|;
return|return
name|PS_OK
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

begin_function
name|void
name|_initialize_proc_service
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* This function solely exists to make sure this module is linked      into the final binary.  */
block|}
end_function

end_unit

