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

begin_comment
comment|/*  * 6.1 : Environmental support  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_decl_stmt
specifier|static
name|u_long
name|amd64_acpi_root
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
name|amd64_acpi_root
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
literal|0
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
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|ACPI_STATUS
name|AcpiOsGetRootPointer
parameter_list|(
name|UINT32
name|Flags
parameter_list|,
name|ACPI_POINTER
modifier|*
name|RsdpPhysicalAddress
parameter_list|)
block|{
name|ACPI_POINTER
name|ptr
decl_stmt|;
name|ACPI_STATUS
name|status
decl_stmt|;
if|if
condition|(
name|amd64_acpi_root
operator|==
literal|0
condition|)
block|{
comment|/* 		 * The loader passes the physical address at which it found the 		 * RSDP in a hint.  We could recover this rather than searching 		 * manually here. 		 */
name|status
operator|=
name|AcpiFindRootPointer
argument_list|(
name|Flags
argument_list|,
operator|&
name|ptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|AE_OK
condition|)
name|amd64_acpi_root
operator|=
name|ptr
operator|.
name|Pointer
operator|.
name|Physical
expr_stmt|;
block|}
else|else
name|status
operator|=
name|AE_OK
expr_stmt|;
name|RsdpPhysicalAddress
operator|->
name|PointerType
operator|=
name|ACPI_PHYSICAL_POINTER
expr_stmt|;
name|RsdpPhysicalAddress
operator|->
name|Pointer
operator|.
name|Physical
operator|=
name|amd64_acpi_root
expr_stmt|;
return|return
operator|(
name|status
operator|)
return|;
block|}
end_function

end_unit

