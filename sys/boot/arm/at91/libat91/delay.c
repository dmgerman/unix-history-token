begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software is derived from software provide by Kwikbyte who specifically  * disclaimed copyright on the code.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_include
include|#
directive|include
file|"spi_flash.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_function
name|void
name|Delay
parameter_list|(
name|int
name|us
parameter_list|)
block|{
name|unsigned
name|later
decl_stmt|,
name|now
decl_stmt|;
name|now
operator|=
name|AT91C_BASE_ST
operator|->
name|ST_CRTR
expr_stmt|;
name|later
operator|=
operator|(
name|now
operator|+
name|us
operator|/
literal|25
operator|+
literal|1
operator|)
operator|&
name|AT91C_ST_CRTV
expr_stmt|;
while|while
condition|(
name|later
operator|!=
name|AT91C_BASE_ST
operator|->
name|ST_CRTR
condition|)
continue|continue;
block|}
end_function

end_unit

