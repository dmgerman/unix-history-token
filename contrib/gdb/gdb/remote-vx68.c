begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 68k-dependent portions of the RPC protocol    used with a VxWorks target   Contributed by Wind River Systems.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
file|"vx-share/regPacket.h"
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
file|"wait.h"
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
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"symtab.h"
end_include

begin_include
include|#
directive|include
file|"symfile.h"
end_include

begin_comment
comment|/* for struct complaint */
end_comment

begin_include
include|#
directive|include
file|"gdb_string.h"
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_comment
comment|/* IBM claims "void *malloc()" not char * */
end_comment

begin_define
define|#
directive|define
name|malloc
value|bogon_malloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX
end_ifdef

begin_undef
undef|#
directive|undef
name|malloc
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* UTek's<rpc/rpc.h> doesn't #incl this */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|"vx-share/ptrace.h"
end_include

begin_include
include|#
directive|include
file|"vx-share/xdr_ptrace.h"
end_include

begin_include
include|#
directive|include
file|"vx-share/xdr_ld.h"
end_include

begin_include
include|#
directive|include
file|"vx-share/xdr_rdb.h"
end_include

begin_include
include|#
directive|include
file|"vx-share/dbgRpcLib.h"
end_include

begin_comment
comment|/* get rid of value.h if possible */
end_comment

begin_include
include|#
directive|include
file|<value.h>
end_include

begin_include
include|#
directive|include
file|<symtab.h>
end_include

begin_comment
comment|/* Flag set if target has fpu */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_has_fp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic register read/write routines in remote-vx.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|net_read_registers
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|net_write_registers
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Read a register or registers from the VxWorks target.    REGNO is the register to read, or -1 for all; currently,    it is ignored.  FIXME look at regno to improve efficiency.  */
end_comment

begin_function
name|void
name|vx_read_register
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
name|char
name|mc68k_greg_packet
index|[
name|MC68K_GREG_PLEN
index|]
decl_stmt|;
name|char
name|mc68k_fpreg_packet
index|[
name|MC68K_FPREG_PLEN
index|]
decl_stmt|;
comment|/* Get general-purpose registers.  */
name|net_read_registers
argument_list|(
name|mc68k_greg_packet
argument_list|,
name|MC68K_GREG_PLEN
argument_list|,
name|PTRACE_GETREGS
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_D0
index|]
argument_list|,
name|registers
argument_list|,
literal|16
operator|*
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_SR
index|]
argument_list|,
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|PS_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_PC
index|]
argument_list|,
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|PC_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
comment|/* Get floating-point registers, if the target system has them.      Otherwise, zero them.  */
if|if
condition|(
name|target_has_fp
condition|)
block|{
name|net_read_registers
argument_list|(
name|mc68k_fpreg_packet
argument_list|,
name|MC68K_FPREG_PLEN
argument_list|,
name|PTRACE_GETFPREGS
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mc68k_fpreg_packet
index|[
name|MC68K_R_FP0
index|]
argument_list|,
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FP0_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_FPREG_SIZE
operator|*
literal|8
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|mc68k_fpreg_packet
index|[
name|MC68K_R_FPCR
index|]
argument_list|,
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FPC_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_FPREG_PLEN
operator|-
operator|(
name|MC68K_FPREG_SIZE
operator|*
literal|8
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|bzero
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FP0_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_FPREG_SIZE
operator|*
literal|8
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FPC_REGNUM
argument_list|)
index|]
argument_list|,
name|MC68K_FPREG_PLEN
operator|-
operator|(
name|MC68K_FPREG_SIZE
operator|*
literal|8
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* Mark the register cache valid.  */
name|registers_fetched
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Store a register or registers into the VxWorks target.    REGNO is the register to store, or -1 for all; currently,    it is ignored.  FIXME look at regno to improve efficiency.  */
end_comment

begin_function
name|void
name|vx_write_register
parameter_list|(
name|regno
parameter_list|)
name|int
name|regno
decl_stmt|;
block|{
name|char
name|mc68k_greg_packet
index|[
name|MC68K_GREG_PLEN
index|]
decl_stmt|;
name|char
name|mc68k_fpreg_packet
index|[
name|MC68K_FPREG_PLEN
index|]
decl_stmt|;
comment|/* Store general-purpose registers.  */
name|bcopy
argument_list|(
name|registers
argument_list|,
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_D0
index|]
argument_list|,
literal|16
operator|*
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|PS_REGNUM
argument_list|)
index|]
argument_list|,
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_SR
index|]
argument_list|,
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|PC_REGNUM
argument_list|)
index|]
argument_list|,
operator|&
name|mc68k_greg_packet
index|[
name|MC68K_R_PC
index|]
argument_list|,
name|MC68K_GREG_SIZE
argument_list|)
expr_stmt|;
name|net_write_registers
argument_list|(
name|mc68k_greg_packet
argument_list|,
name|MC68K_GREG_PLEN
argument_list|,
name|PTRACE_SETREGS
argument_list|)
expr_stmt|;
comment|/* Store floating point registers if the target has them.  */
if|if
condition|(
name|target_has_fp
condition|)
block|{
name|bcopy
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FP0_REGNUM
argument_list|)
index|]
argument_list|,
operator|&
name|mc68k_fpreg_packet
index|[
name|MC68K_R_FP0
index|]
argument_list|,
name|MC68K_FPREG_SIZE
operator|*
literal|8
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
operator|&
name|registers
index|[
name|REGISTER_BYTE
argument_list|(
name|FPC_REGNUM
argument_list|)
index|]
argument_list|,
operator|&
name|mc68k_fpreg_packet
index|[
name|MC68K_R_FPCR
index|]
argument_list|,
name|MC68K_FPREG_PLEN
operator|-
operator|(
name|MC68K_FPREG_SIZE
operator|*
literal|8
operator|)
argument_list|)
expr_stmt|;
name|net_write_registers
argument_list|(
name|mc68k_fpreg_packet
argument_list|,
name|MC68K_FPREG_PLEN
argument_list|,
name|PTRACE_SETFPREGS
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

