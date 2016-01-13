begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<efi.h>
end_include

begin_include
include|#
directive|include
file|<efilib.h>
end_include

begin_include
include|#
directive|include
file|<fdt_platform.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_decl_stmt
specifier|static
name|EFI_GUID
name|fdtdtb
init|=
name|FDT_TABLE_GUID
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|fdt_platform_load_dtb
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|fdt_header
modifier|*
name|hdr
decl_stmt|;
name|hdr
operator|=
name|efi_get_table
argument_list|(
operator|&
name|fdtdtb
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|fdt_load_dtb_addr
argument_list|(
name|hdr
argument_list|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Using DTB provided by EFI at %p.\n"
argument_list|,
name|hdr
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|fdt_platform_fixups
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

end_unit

