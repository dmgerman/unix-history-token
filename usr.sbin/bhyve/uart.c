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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|"inout.h"
end_include

begin_define
define|#
directive|define
name|COM1
value|0x3F8
end_define

begin_define
define|#
directive|define
name|COM2
value|0x2F8
end_define

begin_define
define|#
directive|define
name|REG_IIR
value|2
end_define

begin_function
specifier|static
name|int
name|com_handler
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|int
name|in
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|bytes
parameter_list|,
name|uint32_t
modifier|*
name|eax
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|assert
argument_list|(
name|in
argument_list|)
expr_stmt|;
if|if
condition|(
name|bytes
operator|!=
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* 	 * COM port is not implemented so we return 0xFF for all registers 	 */
operator|*
name|eax
operator|=
literal|0xFF
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_expr_stmt
name|INOUT_PORT
argument_list|(
name|uart
argument_list|,
name|COM1
operator|+
name|REG_IIR
argument_list|,
name|IOPORT_F_IN
argument_list|,
name|com_handler
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|INOUT_PORT
argument_list|(
name|uart
argument_list|,
name|COM2
operator|+
name|REG_IIR
argument_list|,
name|IOPORT_F_IN
argument_list|,
name|com_handler
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

