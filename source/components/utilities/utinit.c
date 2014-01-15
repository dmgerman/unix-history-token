begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: utinit - Common ACPI subsystem initialization  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__UTINIT_C__
end_define

begin_include
include|#
directive|include
file|"acpi.h"
end_include

begin_include
include|#
directive|include
file|"accommon.h"
end_include

begin_include
include|#
directive|include
file|"acnamesp.h"
end_include

begin_include
include|#
directive|include
file|"acevents.h"
end_include

begin_include
include|#
directive|include
file|"actables.h"
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"utinit"
argument_list|)
end_macro

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|void
name|AcpiUtTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_function_decl
specifier|static
name|void
name|AcpiUtFreeGpeLists
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AcpiUtFreeGpeLists
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiUtFreeGpeLists  *  * PARAMETERS:  none  *  * RETURN:      none  *  * DESCRIPTION: Free global GPE lists  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|AcpiUtFreeGpeLists
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
decl_stmt|;
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|NextGpeBlock
decl_stmt|;
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
decl_stmt|;
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|NextGpeXruptInfo
decl_stmt|;
comment|/* Free global GPE blocks and related info structures */
name|GpeXruptInfo
operator|=
name|AcpiGbl_GpeXruptListHead
expr_stmt|;
while|while
condition|(
name|GpeXruptInfo
condition|)
block|{
name|GpeBlock
operator|=
name|GpeXruptInfo
operator|->
name|GpeBlockListHead
expr_stmt|;
while|while
condition|(
name|GpeBlock
condition|)
block|{
name|NextGpeBlock
operator|=
name|GpeBlock
operator|->
name|Next
expr_stmt|;
name|ACPI_FREE
argument_list|(
name|GpeBlock
operator|->
name|EventInfo
argument_list|)
expr_stmt|;
name|ACPI_FREE
argument_list|(
name|GpeBlock
operator|->
name|RegisterInfo
argument_list|)
expr_stmt|;
name|ACPI_FREE
argument_list|(
name|GpeBlock
argument_list|)
expr_stmt|;
name|GpeBlock
operator|=
name|NextGpeBlock
expr_stmt|;
block|}
name|NextGpeXruptInfo
operator|=
name|GpeXruptInfo
operator|->
name|Next
expr_stmt|;
name|ACPI_FREE
argument_list|(
name|GpeXruptInfo
argument_list|)
expr_stmt|;
name|GpeXruptInfo
operator|=
name|NextGpeXruptInfo
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiUtTerminate  *  * PARAMETERS:  none  *  * RETURN:      none  *  * DESCRIPTION: Free global memory  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|AcpiUtTerminate
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_FUNCTION_TRACE
argument_list|(
name|UtTerminate
argument_list|)
expr_stmt|;
name|AcpiUtFreeGpeLists
argument_list|()
expr_stmt|;
name|AcpiUtDeleteAddressLists
argument_list|()
expr_stmt|;
name|return_VOID
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtSubsystemShutdown  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Shutdown the various components. Do not delete the mutex  *              objects here, because the AML debugger may be still running.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiUtSubsystemShutdown
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_FUNCTION_TRACE
argument_list|(
name|UtSubsystemShutdown
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|ACPI_ASL_COMPILER
comment|/* Close the AcpiEvent Handling */
name|AcpiEvTerminate
argument_list|()
expr_stmt|;
comment|/* Delete any dynamic _OSI interfaces */
name|AcpiUtInterfaceTerminate
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* Close the Namespace */
name|AcpiNsTerminate
argument_list|()
expr_stmt|;
comment|/* Delete the ACPI tables */
name|AcpiTbTerminate
argument_list|()
expr_stmt|;
comment|/* Close the globals */
name|AcpiUtTerminate
argument_list|()
expr_stmt|;
comment|/* Purge the local caches */
operator|(
name|void
operator|)
name|AcpiUtDeleteCaches
argument_list|()
expr_stmt|;
name|return_VOID
expr_stmt|;
block|}
end_function

end_unit

