begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, Stefan Esser<se@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Id: interrupt.h,v 1.4 1997/06/02 10:46:20 dfr Exp $  */
end_comment

begin_comment
comment|/* XXX currently dev_instance must be set to the ISA device_id or -1 for PCI */
end_comment

begin_define
define|#
directive|define
name|INTR_FAST
value|0x00000001
end_define

begin_comment
comment|/* fast interrupt handler */
end_comment

begin_define
define|#
directive|define
name|INTR_EXCL
value|0x00010000
end_define

begin_comment
comment|/* excl. intr, default is shared */
end_comment

begin_function_decl
name|struct
name|intrec
modifier|*
name|intr_create
parameter_list|(
name|void
modifier|*
name|dev_instance
parameter_list|,
name|int
name|irq
parameter_list|,
name|inthand2_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|intrmask_t
modifier|*
name|maskptr
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_destroy
parameter_list|(
name|struct
name|intrec
modifier|*
name|idesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_connect
parameter_list|(
name|struct
name|intrec
modifier|*
name|idesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_disconnect
parameter_list|(
name|struct
name|intrec
modifier|*
name|idesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|intr_registered
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX emulate old interface for now ... */
end_comment

begin_decl_stmt
name|int
name|register_intr
name|__P
argument_list|(
operator|(
name|int
name|intr
operator|,
name|int
name|device_id
operator|,
name|u_int
name|flags
operator|,
name|inthand2_t
operator|*
name|handler
operator|,
name|u_int
operator|*
name|maskptr
operator|,
name|int
name|unit
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|unregister_intr
parameter_list|(
name|int
name|intr
parameter_list|,
name|inthand2_t
name|handler
parameter_list|)
function_decl|;
end_function_decl

end_unit

