begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: exstubs - Stub routines for the Example program  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|"examples.h"
end_include

begin_include
include|#
directive|include
file|<acutils.h>
end_include

begin_include
include|#
directive|include
file|<acevents.h>
end_include

begin_include
include|#
directive|include
file|<acdispat.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_EXAMPLE
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"exstubs"
argument_list|)
end_macro

begin_comment
comment|/******************************************************************************  *  * DESCRIPTION: Stubs used to facilitate linkage of the example program  *  *****************************************************************************/
end_comment

begin_comment
comment|/* Hardware manager */
end_comment

begin_function
name|ACPI_STATUS
name|AcpiHwReadPort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|,
name|UINT32
name|Width
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
name|AcpiHwWritePort
parameter_list|(
name|ACPI_IO_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|UINT32
name|Width
parameter_list|)
block|{
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Event manager */
end_comment

begin_function
name|ACPI_STATUS
name|AcpiEvInitializeEvents
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

end_unit

