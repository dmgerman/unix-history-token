begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000,2001 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * 6.1 : Environmental support  */
end_comment

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_decl_stmt
specifier|extern
name|u_int64_t
name|ia64_efi_acpi_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int64_t
name|ia64_efi_acpi20_table
decl_stmt|;
end_decl_stmt

begin_function
name|ACPI_STATUS
name|AcpiOsInitialize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|NULL
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
name|NULL
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
name|ACPI_PHYSICAL_ADDRESS
modifier|*
name|RsdpPhysicalAddress
parameter_list|)
block|{
if|if
condition|(
name|ia64_efi_acpi20_table
condition|)
operator|*
name|RsdpPhysicalAddress
operator|=
name|ia64_efi_acpi20_table
expr_stmt|;
elseif|else
if|if
condition|(
name|ia64_efi_acpi_table
condition|)
operator|*
name|RsdpPhysicalAddress
operator|=
name|ia64_efi_acpi_table
expr_stmt|;
else|else
return|return
operator|(
name|AE_NOT_FOUND
operator|)
return|;
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

end_unit

