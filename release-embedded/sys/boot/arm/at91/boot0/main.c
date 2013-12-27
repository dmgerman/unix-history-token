begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"at91rm9200_lowlevel.h"
end_include

begin_typedef
typedef|typedef
name|void
name|fn_t
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|char
modifier|*
name|addr
init|=
operator|(
name|char
operator|*
operator|)
name|SDRAM_BASE
operator|+
operator|(
literal|1
operator|<<
literal|20
operator|)
decl_stmt|;
comment|/* Load to base + 1MB */
name|fn_t
modifier|*
name|fn
init|=
operator|(
name|fn_t
operator|*
operator|)
operator|(
name|SDRAM_BASE
operator|+
operator|(
literal|1
operator|<<
literal|20
operator|)
operator|)
decl_stmt|;
comment|/* Load to base + 1MB */
while|while
condition|(
name|xmodem_rx
argument_list|(
name|addr
argument_list|)
operator|==
operator|-
literal|1
condition|)
continue|continue;
name|fn
argument_list|()
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

