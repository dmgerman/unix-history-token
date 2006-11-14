begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_comment
comment|/*  * i386-specific module functionality.  *  */
end_comment

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"bootstrap.h"
end_include

begin_include
include|#
directive|include
file|"libi386.h"
end_include

begin_comment
comment|/*  * Use voodoo to load modules required by current hardware.  */
end_comment

begin_function
name|int
name|i386_autoload
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|int
name|disabled
decl_stmt|;
name|char
modifier|*
name|rv
decl_stmt|;
comment|/* XXX use PnP to locate stuff here */
comment|/* autoload ACPI support */
comment|/* XXX should be in 4th keyed off acpi_load */
name|disabled
operator|=
literal|0
expr_stmt|;
name|rv
operator|=
name|getenv
argument_list|(
literal|"hint.acpi.0.disabled"
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|!=
name|NULL
operator|&&
name|strncmp
argument_list|(
name|rv
argument_list|,
literal|"0"
argument_list|,
literal|1
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|disabled
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|getenv
argument_list|(
literal|"acpi_load"
argument_list|)
operator|&&
operator|(
operator|!
name|disabled
operator|)
condition|)
block|{
name|error
operator|=
name|mod_load
argument_list|(
literal|"acpi"
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|!=
literal|0
condition|)
name|printf
argument_list|(
literal|"ACPI autoload failed - %s\n"
argument_list|,
name|strerror
argument_list|(
name|error
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

