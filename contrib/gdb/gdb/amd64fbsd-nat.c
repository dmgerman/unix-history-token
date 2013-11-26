begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for FreeBSD/amd64.     Copyright 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_include
include|#
directive|include
file|"gdb_assert.h"
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ptrace.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_PROCFS_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/procfs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|reg
name|gregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FPREGSET_T
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|fpreg
name|fpregset_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"gregset.h"
end_include

begin_include
include|#
directive|include
file|"amd64-tdep.h"
end_include

begin_include
include|#
directive|include
file|"amd64-nat.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Offset to the gregset_t location where REG is stored.  */
end_comment

begin_define
define|#
directive|define
name|REG_OFFSET
parameter_list|(
name|reg
parameter_list|)
value|offsetof (gregset_t, reg)
end_define

begin_comment
comment|/* At reg_offset[REGNUM] you'll find the offset to the gregset_t    location where the GDB register REGNUM is stored.  Unsupported    registers are marked with `-1'.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|reg_offset
index|[]
init|=
block|{
name|REG_OFFSET
argument_list|(
name|r_rax
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rbx
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rcx
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rdx
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rsi
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rdi
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rbp
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rsp
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r8
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r9
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r10
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r11
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r12
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r13
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r14
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_r15
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rip
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_rflags
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_cs
argument_list|)
block|,
name|REG_OFFSET
argument_list|(
name|r_ss
argument_list|)
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Mapping between the general-purpose registers in FreeBSD/amd64    `struct reg' format and GDB's register cache layout for    FreeBSD/i386.     Note that most FreeBSD/amd64 registers are 64-bit, while the    FreeBSD/i386 registers are all 32-bit, but since we're    little-endian we get away with that.  */
end_comment

begin_comment
comment|/* From<machine/reg.h>.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|amd64fbsd32_r_reg_offset
index|[
name|I386_NUM_GREGS
index|]
init|=
block|{
literal|14
operator|*
literal|8
block|,
literal|13
operator|*
literal|8
block|,
comment|/* %eax, %ecx */
literal|12
operator|*
literal|8
block|,
literal|11
operator|*
literal|8
block|,
comment|/* %edx, %ebx */
literal|20
operator|*
literal|8
block|,
literal|10
operator|*
literal|8
block|,
comment|/* %esp, %ebp */
literal|9
operator|*
literal|8
block|,
literal|8
operator|*
literal|8
block|,
comment|/* %esi, %edi */
literal|17
operator|*
literal|8
block|,
literal|19
operator|*
literal|8
block|,
comment|/* %eip, %eflags */
literal|18
operator|*
literal|8
block|,
literal|21
operator|*
literal|8
block|,
comment|/* %cs, %ss */
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
comment|/* %ds, %es, %fs, %gs */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Transfering the registers between GDB, inferiors and core files.  */
end_comment

begin_comment
comment|/* Fill GDB's register array with the general-purpose register values    in *GREGSETP.  */
end_comment

begin_function
name|void
name|supply_gregset
parameter_list|(
name|gregset_t
modifier|*
name|gregsetp
parameter_list|)
block|{
name|amd64_supply_native_gregset
argument_list|(
name|current_regcache
argument_list|,
name|gregsetp
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Fill register REGNUM (if it is a general-purpose register) in    *GREGSETPS with the value in GDB's register array.  If REGNUM is -1,    do this for all registers.  */
end_comment

begin_function
name|void
name|fill_gregset
parameter_list|(
name|gregset_t
modifier|*
name|gregsetp
parameter_list|,
name|int
name|regnum
parameter_list|)
block|{
name|amd64_collect_native_gregset
argument_list|(
name|current_regcache
argument_list|,
name|gregsetp
argument_list|,
name|regnum
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Fill GDB's register array with the floating-point register values    in *FPREGSETP.  */
end_comment

begin_function
name|void
name|supply_fpregset
parameter_list|(
name|fpregset_t
modifier|*
name|fpregsetp
parameter_list|)
block|{
name|amd64_supply_fxsave
argument_list|(
name|current_regcache
argument_list|,
operator|-
literal|1
argument_list|,
name|fpregsetp
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point register) in    *FPREGSETP with the value in GDB's register array.  If REGNUM is -1,    do this for all registers.  */
end_comment

begin_function
name|void
name|fill_fpregset
parameter_list|(
name|fpregset_t
modifier|*
name|fpregsetp
parameter_list|,
name|int
name|regnum
parameter_list|)
block|{
name|amd64_fill_fxsave
argument_list|(
operator|(
name|char
operator|*
operator|)
name|fpregsetp
argument_list|,
name|regnum
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_amd64fbsd_nat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_amd64fbsd_nat
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|offset
decl_stmt|;
name|amd64_native_gregset32_reg_offset
operator|=
name|amd64fbsd32_r_reg_offset
expr_stmt|;
name|amd64_native_gregset64_reg_offset
operator|=
name|reg_offset
expr_stmt|;
comment|/* To support the recognition of signal handlers, i386bsd-tdep.c      hardcodes some constants.  Inclusion of this file means that we      are compiling a native debugger, which means that we can use the      system header files and sysctl(3) to get at the relevant      information.  */
define|#
directive|define
name|SC_REG_OFFSET
value|amd64fbsd_sc_reg_offset
comment|/* We only check the program counter, stack pointer and frame      pointer since these members of `struct sigcontext' are essential      for providing backtraces.  */
define|#
directive|define
name|SC_RIP_OFFSET
value|SC_REG_OFFSET[AMD64_RIP_REGNUM]
define|#
directive|define
name|SC_RSP_OFFSET
value|SC_REG_OFFSET[AMD64_RSP_REGNUM]
define|#
directive|define
name|SC_RBP_OFFSET
value|SC_REG_OFFSET[AMD64_RBP_REGNUM]
comment|/* Override the default value for the offset of the program counter      in the sigcontext structure.  */
name|offset
operator|=
name|offsetof
argument_list|(
expr|struct
name|sigcontext
argument_list|,
name|sc_rip
argument_list|)
expr_stmt|;
if|if
condition|(
name|SC_RIP_OFFSET
operator|!=
name|offset
condition|)
block|{
name|warning
argument_list|(
literal|"\ offsetof (struct sigcontext, sc_rip) yields %d instead of %d.\n\ Please report this to<bug-gdb@gnu.org>."
argument_list|,
name|offset
argument_list|,
name|SC_RIP_OFFSET
argument_list|)
expr_stmt|;
block|}
name|SC_RIP_OFFSET
operator|=
name|offset
expr_stmt|;
comment|/* Likewise for the stack pointer.  */
name|offset
operator|=
name|offsetof
argument_list|(
expr|struct
name|sigcontext
argument_list|,
name|sc_rsp
argument_list|)
expr_stmt|;
if|if
condition|(
name|SC_RSP_OFFSET
operator|!=
name|offset
condition|)
block|{
name|warning
argument_list|(
literal|"\ offsetof (struct sigcontext, sc_rsp) yields %d instead of %d.\n\ Please report this to<bug-gdb@gnu.org>."
argument_list|,
name|offset
argument_list|,
name|SC_RSP_OFFSET
argument_list|)
expr_stmt|;
block|}
name|SC_RSP_OFFSET
operator|=
name|offset
expr_stmt|;
comment|/* And the frame pointer.  */
name|offset
operator|=
name|offsetof
argument_list|(
expr|struct
name|sigcontext
argument_list|,
name|sc_rbp
argument_list|)
expr_stmt|;
if|if
condition|(
name|SC_RBP_OFFSET
operator|!=
name|offset
condition|)
block|{
name|warning
argument_list|(
literal|"\ offsetof (struct sigcontext, sc_rbp) yields %d instead of %d.\n\ Please report this to<bug-gdb@gnu.org>."
argument_list|,
name|offset
argument_list|,
name|SC_RBP_OFFSET
argument_list|)
expr_stmt|;
block|}
name|SC_RBP_OFFSET
operator|=
name|offset
expr_stmt|;
comment|/* FreeBSD provides a kern.proc.sigtramp sysctl that we can use to      locate the sigtramp.  That way we can still recognize a sigtramp      if its location is changed in a new kernel. */
block|{
name|int
name|mib
index|[
literal|4
index|]
decl_stmt|;
name|struct
name|kinfo_sigtramp
name|kst
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|mib
index|[
literal|0
index|]
operator|=
name|CTL_KERN
expr_stmt|;
name|mib
index|[
literal|1
index|]
operator|=
name|KERN_PROC
expr_stmt|;
name|mib
index|[
literal|2
index|]
operator|=
name|KERN_PROC_SIGTRAMP
expr_stmt|;
name|mib
index|[
literal|3
index|]
operator|=
name|getpid
argument_list|()
expr_stmt|;
name|len
operator|=
sizeof|sizeof
argument_list|(
name|kst
argument_list|)
expr_stmt|;
if|if
condition|(
name|sysctl
argument_list|(
name|mib
argument_list|,
sizeof|sizeof
argument_list|(
name|mib
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mib
index|[
literal|0
index|]
argument_list|)
argument_list|,
operator|&
name|kst
argument_list|,
operator|&
name|len
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|)
operator|==
literal|0
condition|)
block|{
name|amd64fbsd_sigtramp_start_addr
operator|=
name|kst
operator|.
name|ksigtramp_start
expr_stmt|;
name|amd64fbsd_sigtramp_end_addr
operator|=
name|kst
operator|.
name|ksigtramp_end
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

