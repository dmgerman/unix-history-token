begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NPORTS
value|5
end_define

begin_define
define|#
directive|define
name|NGPIO
value|(NPORTS * 32)
end_define

begin_enum
enum|enum
name|ev_type
block|{
name|DMA_RISING_EDGE
block|,
name|DMA_FALLING_EDGE
block|,
name|DMA_EITHER_EDGE
block|,
name|INT_LOGIC_ZERO
block|,
name|INT_RISING_EDGE
block|,
name|INT_FALLING_EDGE
block|,
name|INT_EITHER_EDGE
block|,
name|INT_LOGIC_ONE
block|, }
enum|;
end_enum

begin_decl_stmt
name|int
name|port_setup
argument_list|(
name|int
argument_list|,
expr|enum
name|ev_type
argument_list|,
name|void
argument_list|(
operator|*
name|ih
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
operator|*
name|ih_user
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

