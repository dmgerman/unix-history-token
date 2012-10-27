begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<gdb/gdb.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_decl_stmt
specifier|static
name|gdb_probe_f
name|bvm_dbg_probe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gdb_init_f
name|bvm_dbg_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gdb_term_f
name|bvm_dbg_term
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gdb_getc_f
name|bvm_dbg_getc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|gdb_putc_f
name|bvm_dbg_putc
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GDB_DBGPORT
argument_list|(
name|bvm
argument_list|,
name|bvm_dbg_probe
argument_list|,
name|bvm_dbg_init
argument_list|,
name|bvm_dbg_term
argument_list|,
name|bvm_dbg_getc
argument_list|,
name|bvm_dbg_putc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|BVM_DBG_PORT
value|0x224
end_define

begin_decl_stmt
specifier|static
name|int
name|bvm_dbg_port
init|=
name|BVM_DBG_PORT
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BVM_DBG_SIG
value|('B'<< 8 | 'V')
end_define

begin_function
specifier|static
name|int
name|bvm_dbg_probe
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|disabled
decl_stmt|,
name|port
decl_stmt|;
name|disabled
operator|=
literal|0
expr_stmt|;
name|resource_int_value
argument_list|(
literal|"bvmdbg"
argument_list|,
literal|0
argument_list|,
literal|"disabled"
argument_list|,
operator|&
name|disabled
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|disabled
condition|)
block|{
if|if
condition|(
name|resource_int_value
argument_list|(
literal|"bvmdbg"
argument_list|,
literal|0
argument_list|,
literal|"port"
argument_list|,
operator|&
name|port
argument_list|)
operator|==
literal|0
condition|)
name|bvm_dbg_port
operator|=
name|port
expr_stmt|;
if|if
condition|(
name|inw
argument_list|(
name|bvm_dbg_port
argument_list|)
operator|==
name|BVM_DBG_SIG
condition|)
block|{
comment|/* 			 * Return a higher priority than 0 to override other 			 * gdb dbgport providers that may be present (e.g. uart) 			 */
return|return
operator|(
literal|1
operator|)
return|;
block|}
block|}
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|bvm_dbg_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|bvm_dbg_term
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
specifier|static
name|void
name|bvm_dbg_putc
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|outl
argument_list|(
name|bvm_dbg_port
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|bvm_dbg_getc
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|inl
argument_list|(
name|bvm_dbg_port
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

