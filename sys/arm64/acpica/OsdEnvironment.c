begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/aclocal.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/actables.h>
end_include

begin_decl_stmt
specifier|static
name|u_long
name|acpi_root_phys
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_ULONG
argument_list|(
name|_machdep
argument_list|,
name|OID_AUTO
argument_list|,
name|acpi_root
argument_list|,
name|CTLFLAG_RD
argument_list|,
operator|&
name|acpi_root_phys
argument_list|,
literal|0
argument_list|,
literal|"The physical address of the RSDP"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|ACPI_STATUS
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_function
name|ACPI_STATUS
name|AcpiOsTerminate
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|u_long
name|acpi_get_root_from_loader
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|acpi_root
decl_stmt|;
if|if
condition|(
name|resource_long_value
argument_list|(
literal|"acpi"
argument_list|,
literal|0
argument_list|,
literal|"rsdp"
argument_list|,
operator|&
name|acpi_root
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|acpi_root
operator|)
return|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|ACPI_PHYSICAL_ADDRESS
name|AcpiOsGetRootPointer
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|acpi_root_phys
operator|==
literal|0
condition|)
name|acpi_root_phys
operator|=
name|acpi_get_root_from_loader
argument_list|()
expr_stmt|;
return|return
operator|(
name|acpi_root_phys
operator|)
return|;
block|}
end_function

end_unit

