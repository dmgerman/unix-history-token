begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"opt_platform.h"
end_include

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
file|<arm/include/platform.h>
end_include

begin_include
include|#
directive|include
file|<arm/include/platformvar.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|"platform_if.h"
end_include

begin_define
define|#
directive|define
name|FDT_PLATFORM
parameter_list|(
name|plat
parameter_list|)
define|\
value|((fdt_platform_def_t *)(plat)->cls->baseclasses[0])
end_define

begin_function
specifier|static
name|int
name|fdt_platform_probe
parameter_list|(
name|platform_t
name|plat
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|compat
decl_stmt|;
name|phandle_t
name|root
decl_stmt|;
comment|/* 	 * TODO: Make these KASSERTs, we should only be here if we 	 * are using the FDT platform magic. 	 */
if|if
condition|(
name|plat
operator|->
name|cls
operator|==
name|NULL
operator|||
name|FDT_PLATFORM
argument_list|(
name|plat
argument_list|)
operator|==
name|NULL
condition|)
return|return
literal|1
return|;
comment|/* Is the device is compatible? */
name|root
operator|=
name|OF_finddevice
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
name|compat
operator|=
name|FDT_PLATFORM
argument_list|(
name|plat
argument_list|)
operator|->
name|fdt_compatible
expr_stmt|;
if|if
condition|(
name|fdt_is_compatible
argument_list|(
name|root
argument_list|,
name|compat
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|0
return|;
comment|/* Not compatible, return an error */
return|return
literal|1
return|;
block|}
end_function

begin_decl_stmt
name|platform_method_t
name|fdt_platform_methods
index|[]
init|=
block|{
name|PLATFORMMETHOD
argument_list|(
name|platform_probe
argument_list|,
name|fdt_platform_probe
argument_list|)
block|,
name|PLATFORMMETHOD_END
block|}
decl_stmt|;
end_decl_stmt

end_unit

