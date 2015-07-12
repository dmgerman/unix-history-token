begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Semihalf under  * the sponsorship of the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/pci_cfgreg.h>
end_include

begin_comment
comment|/*  * This file contains stubs for ACPI PCI functions  */
end_comment

begin_comment
comment|/*  * Read configuration space register  */
end_comment

begin_function
name|uint32_t
name|pci_cfgregread
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|func
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|bytes
parameter_list|)
block|{
comment|/* ARM64TODO */
name|panic
argument_list|(
literal|"pci_cfgregread not implemented"
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
comment|/*  * Write configuration space register  */
end_comment

begin_function
name|void
name|pci_cfgregwrite
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|slot
parameter_list|,
name|int
name|func
parameter_list|,
name|int
name|reg
parameter_list|,
name|u_int32_t
name|data
parameter_list|,
name|int
name|bytes
parameter_list|)
block|{
comment|/* ARM64TODO */
name|panic
argument_list|(
literal|"pci_cfgregwrite not implemented"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Initialize access to configuration space  */
end_comment

begin_function
name|int
name|pci_cfgregopen
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* ARM64TODO */
name|panic
argument_list|(
literal|"pci_cfgregopen not implemented"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

