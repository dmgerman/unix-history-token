begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent code for the SPARC for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * This is the target dependent code for an hp300 running BSD.  */
end_comment

begin_define
define|#
directive|define
name|__sys_stdtypes_h
end_define

begin_comment
comment|/* XXX defeat sun types file */
end_comment

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
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_include
include|#
directive|include
file|"ieee-float.h"
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|"gdbcore.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_include
include|#
directive|include
file|<kvm.h>
end_include

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_function_decl
name|CORE_ADDR
name|ksym_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read the "thing" at address 'addr' into the space pointed to by P.  * The length of the "thing" is determined by the type of P.  * Result is non-zero if transfer fails.  */
end_comment

begin_define
define|#
directive|define
name|READMEM
parameter_list|(
name|addr
parameter_list|,
name|p
parameter_list|)
define|\
value|(target_read_memory((CORE_ADDR)(addr), (char *)(p), sizeof(*(p))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_comment
comment|/*  * The code below implements kernel debugging of crashdumps (or /dev/kmem)  * or remote systems (via a serial link).  For remote kernels, the remote  * context does most the work, so there is very little to do -- we just  * manage the kernel stack boundaries so we know where to stop a backtrace.  *  * The crashdump/kmem (kvm) support is a bit more grungy, but thanks to  * libkvm (see kcore.c) not too bad.  The main work is kvm_fetch_registers  * which sucks the register state out of the current processes pcb.  * There is a command that let's you set the current process -- hopefully,  * to something that's blocked (in the live kernel case).  */
end_comment

begin_comment
comment|/* XXX For misc_function_vector. */
end_comment

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_comment
comment|/*  * Address ranges for the current process' kernel stack (fixed).  */
end_comment

begin_decl_stmt
specifier|static
name|CORE_ADDR
name|kernstack_top
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|CORE_ADDR
name|kernstack_bottom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|pcb
modifier|*
name|cpcb
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_curproc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return true if ADDR is a valid stack address according to the  * current boundaries (which are determined by the currently running   * user process).  */
end_comment

begin_function
name|int
name|inside_kernstack
parameter_list|(
name|addr
parameter_list|)
name|CORE_ADDR
name|addr
decl_stmt|;
block|{
if|if
condition|(
name|cpcb
operator|==
literal|0
condition|)
name|set_curproc
argument_list|()
expr_stmt|;
return|return
operator|(
name|addr
operator|>
name|kernstack_bottom
operator|&&
name|addr
operator|<
name|kernstack_top
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * (re-)set the variables that make inside_kernstack() work.  */
end_comment

begin_function
name|void
name|set_kernel_boundaries
parameter_list|(
name|p
parameter_list|)
name|struct
name|pcb
modifier|*
name|p
decl_stmt|;
block|{
specifier|static
name|CORE_ADDR
name|kstack
decl_stmt|;
if|if
condition|(
name|kstack
operator|==
literal|0
condition|)
name|kstack
operator|=
name|ksym_lookup
argument_list|(
literal|"kstack"
argument_list|)
expr_stmt|;
name|kernstack_bottom
operator|=
name|kstack
expr_stmt|;
name|kernstack_top
operator|=
name|kstack
operator|+
name|UPAGES
operator|*
name|NBPG
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Return the current proc.  masterprocp points to  * current proc which points to current u area.  */
end_comment

begin_function
name|struct
name|pcb
modifier|*
name|fetch_cpcb
parameter_list|()
block|{
name|struct
name|pcb
modifier|*
name|p
decl_stmt|;
specifier|static
name|CORE_ADDR
name|addr
decl_stmt|;
if|if
condition|(
name|addr
operator|==
literal|0
condition|)
name|addr
operator|=
name|ksym_lookup
argument_list|(
literal|"curpcb"
argument_list|)
expr_stmt|;
if|if
condition|(
name|READMEM
argument_list|(
name|addr
argument_list|,
operator|&
name|p
argument_list|)
condition|)
name|error
argument_list|(
literal|"cannot read curpcb pointer at 0x%x\n"
argument_list|,
name|addr
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Called from remote_wait, after the remote kernel has stopped.  * Look up the current proc, and set up boundaries.  * This is for active kernels only.  */
end_comment

begin_function
name|void
name|set_curproc
parameter_list|()
block|{
name|cpcb
operator|=
name|fetch_cpcb
argument_list|()
expr_stmt|;
name|set_kernel_boundaries
argument_list|(
name|cpcb
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * All code below is exclusively for support of kernel core files.  */
end_comment

begin_comment
comment|/*  * Fetch registers from a crashdump or /dev/kmem.  */
end_comment

begin_function
specifier|static
name|void
name|kvm_fetch_registers
parameter_list|(
name|p
parameter_list|)
name|struct
name|pcb
modifier|*
name|p
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|u_long
name|v
decl_stmt|;
name|struct
name|pcb
name|pcb
decl_stmt|;
comment|/* find the pcb for the current process */
if|if
condition|(
name|READMEM
argument_list|(
name|p
argument_list|,
operator|&
name|pcb
argument_list|)
condition|)
name|error
argument_list|(
literal|"cannot read pcb at 0x%x"
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/*          * Invalidate all the registers then fill in the ones we know about.          */
name|registers_changed
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|2
init|;
name|i
operator|<=
literal|7
condition|;
operator|++
name|i
control|)
name|supply_register
argument_list|(
name|i
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|pcb
operator|.
name|pcb_regs
index|[
name|i
operator|-
literal|2
index|]
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|10
init|;
name|i
operator|<=
literal|15
condition|;
operator|++
name|i
control|)
name|supply_register
argument_list|(
name|i
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|pcb
operator|.
name|pcb_regs
index|[
name|i
operator|-
literal|4
index|]
argument_list|)
expr_stmt|;
name|v
operator|=
name|pcb
operator|.
name|pcb_ps
expr_stmt|;
name|supply_register
argument_list|(
name|PS_REGNUM
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|v
argument_list|)
expr_stmt|;
comment|/* PC is on top of the stack */
if|if
condition|(
name|READMEM
argument_list|(
name|pcb
operator|.
name|pcb_regs
index|[
literal|11
index|]
argument_list|,
operator|&
name|v
argument_list|)
operator|==
literal|0
condition|)
name|supply_register
argument_list|(
name|PC_REGNUM
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Set the process context to that of the proc structure at  * system address paddr.  Read in the register state.  */
end_comment

begin_function
name|int
name|set_procaddr
parameter_list|(
name|paddr
parameter_list|)
name|CORE_ADDR
name|paddr
decl_stmt|;
block|{
name|struct
name|pcb
modifier|*
name|ppcb
decl_stmt|;
if|if
condition|(
name|paddr
operator|==
literal|0
condition|)
name|cpcb
operator|=
name|fetch_cpcb
argument_list|()
expr_stmt|;
else|else
block|{
name|struct
name|proc
modifier|*
name|p
init|=
operator|(
expr|struct
name|proc
operator|*
operator|)
name|paddr
decl_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|p
operator|<
name|KERNBASE
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|READMEM
argument_list|(
operator|&
name|p
operator|->
name|p_addr
argument_list|,
operator|&
name|ppcb
argument_list|)
condition|)
name|error
argument_list|(
literal|"cannot read p_addr at 0x%x"
argument_list|,
operator|&
name|p
operator|->
name|p_addr
argument_list|)
expr_stmt|;
name|cpcb
operator|=
name|ppcb
expr_stmt|;
block|}
comment|/*          * Need to find current u area to get kernel stack and pcb          * where "panic" saved registers.          * (libkvm also needs to know current u area to get user          * address space mapping). 	 */
name|set_kernel_boundaries
argument_list|(
name|cpcb
argument_list|)
expr_stmt|;
name|kvm_fetch_registers
argument_list|(
name|cpcb
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get the registers out of a crashdump or /dev/kmem.  * XXX This somehow belongs in kcore.c.  *  * We just get all the registers, so we don't use regno.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
name|void
name|kernel_core_registers
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
if|if
condition|(
name|cpcb
operator|==
literal|0
condition|)
operator|(
name|void
operator|)
name|set_procaddr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|kvm_fetch_registers
argument_list|(
name|cpcb
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * XXX We intercept memory transfers since we must translate  * fixed kernel stack addresses into per-process kernel addresses.  */
end_comment

begin_function
name|int
name|Xkernel_xfer_memory
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
name|cpcb
operator|&&
name|inside_kernstack
argument_list|(
name|addr
argument_list|)
condition|)
name|addr
operator|=
name|addr
operator|-
name|kernstack_bottom
operator|+
operator|(
name|CORE_ADDR
operator|)
name|cpcb
expr_stmt|;
return|return
name|kernel_xfer_memory
argument_list|(
name|addr
argument_list|,
name|cp
argument_list|,
name|len
argument_list|,
name|write
argument_list|,
name|target
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

