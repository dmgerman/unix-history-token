begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 M. Warner Losh.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * This software is derived from software provided by kwikbyte without  * copyright as follows:  *  * No warranty, expressed or implied, is included with this software.  It is  * provided "AS IS" and no warranty of any kind including statutory or aspects  * relating to merchantability or fitness for any purpose is provided.  All  * intellectual property rights of others is maintained with the respective  * owners.  This software is not copyrighted and is intended for reference  * only.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"env_vars.h"
end_include

begin_include
include|#
directive|include
file|"at91rm9200.h"
end_include

begin_include
include|#
directive|include
file|"at91rm9200_lowlevel.h"
end_include

begin_include
include|#
directive|include
file|"loader_prompt.h"
end_include

begin_include
include|#
directive|include
file|"emac.h"
end_include

begin_include
include|#
directive|include
file|"lib.h"
end_include

begin_include
include|#
directive|include
file|"spi_flash.h"
end_include

begin_include
include|#
directive|include
file|"ee.h"
end_include

begin_function_decl
name|int
name|main
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|printf
argument_list|(
literal|"\nBoot\n"
argument_list|)
expr_stmt|;
name|EEInit
argument_list|()
expr_stmt|;
name|SPI_InitFlash
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|TSC_FPGA
name|fpga_load
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|EMAC_Init
argument_list|()
expr_stmt|;
name|LoadBootCommands
argument_list|()
expr_stmt|;
if|if
condition|(
name|getc
argument_list|(
literal|1
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|start_wdog
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|ExecuteEnvironmentFunctions
argument_list|()
expr_stmt|;
block|}
name|Bootloader
argument_list|(
name|getc
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

end_unit

