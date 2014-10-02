begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: evsci - System Control Interrupt configuration and  *                      legacy to ACPI mode state transition functions  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/accommon.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acevents.h>
end_include

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_EVENTS
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"evsci"
argument_list|)
end_macro

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_comment
comment|/* Entire module */
end_comment

begin_comment
comment|/* Local prototypes */
end_comment

begin_function_decl
specifier|static
name|UINT32
name|ACPI_SYSTEM_XFACE
name|AcpiEvSciXruptHandler
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiEvSciDispatch  *  * PARAMETERS:  None  *  * RETURN:      Status code indicates whether interrupt was handled.  *  * DESCRIPTION: Dispatch the SCI to all host-installed SCI handlers.  *  ******************************************************************************/
end_comment

begin_function
name|UINT32
name|AcpiEvSciDispatch
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_SCI_HANDLER_INFO
modifier|*
name|SciHandler
decl_stmt|;
name|ACPI_CPU_FLAGS
name|Flags
decl_stmt|;
name|UINT32
name|IntStatus
init|=
name|ACPI_INTERRUPT_NOT_HANDLED
decl_stmt|;
name|ACPI_FUNCTION_NAME
argument_list|(
name|EvSciDispatch
argument_list|)
expr_stmt|;
comment|/* Are there any host-installed SCI handlers? */
if|if
condition|(
operator|!
name|AcpiGbl_SciHandlerList
condition|)
block|{
return|return
operator|(
name|IntStatus
operator|)
return|;
block|}
name|Flags
operator|=
name|AcpiOsAcquireLock
argument_list|(
name|AcpiGbl_GpeLock
argument_list|)
expr_stmt|;
comment|/* Invoke all host-installed SCI handlers */
name|SciHandler
operator|=
name|AcpiGbl_SciHandlerList
expr_stmt|;
while|while
condition|(
name|SciHandler
condition|)
block|{
comment|/* Invoke the installed handler (at interrupt level) */
name|IntStatus
operator||=
name|SciHandler
operator|->
name|Address
argument_list|(
name|SciHandler
operator|->
name|Context
argument_list|)
expr_stmt|;
name|SciHandler
operator|=
name|SciHandler
operator|->
name|Next
expr_stmt|;
block|}
name|AcpiOsReleaseLock
argument_list|(
name|AcpiGbl_GpeLock
argument_list|,
name|Flags
argument_list|)
expr_stmt|;
return|return
operator|(
name|IntStatus
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiEvSciXruptHandler  *  * PARAMETERS:  Context   - Calling Context  *  * RETURN:      Status code indicates whether interrupt was handled.  *  * DESCRIPTION: Interrupt handler that will figure out what function or  *              control method to call to deal with a SCI.  *  ******************************************************************************/
end_comment

begin_function
specifier|static
name|UINT32
name|ACPI_SYSTEM_XFACE
name|AcpiEvSciXruptHandler
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
block|{
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptList
init|=
name|Context
decl_stmt|;
name|UINT32
name|InterruptHandled
init|=
name|ACPI_INTERRUPT_NOT_HANDLED
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|EvSciXruptHandler
argument_list|)
expr_stmt|;
comment|/*      * We are guaranteed by the ACPICA initialization/shutdown code that      * if this interrupt handler is installed, ACPI is enabled.      */
comment|/*      * Fixed Events:      * Check for and dispatch any Fixed Events that have occurred      */
name|InterruptHandled
operator||=
name|AcpiEvFixedEventDetect
argument_list|()
expr_stmt|;
comment|/*      * General Purpose Events:      * Check for and dispatch any GPEs that have occurred      */
name|InterruptHandled
operator||=
name|AcpiEvGpeDetect
argument_list|(
name|GpeXruptList
argument_list|)
expr_stmt|;
comment|/* Invoke all host-installed SCI handlers */
name|InterruptHandled
operator||=
name|AcpiEvSciDispatch
argument_list|()
expr_stmt|;
name|AcpiSciCount
operator|++
expr_stmt|;
name|return_UINT32
argument_list|(
name|InterruptHandled
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiEvGpeXruptHandler  *  * PARAMETERS:  Context   - Calling Context  *  * RETURN:      Status code indicates whether interrupt was handled.  *  * DESCRIPTION: Handler for GPE Block Device interrupts  *  ******************************************************************************/
end_comment

begin_function
name|UINT32
name|ACPI_SYSTEM_XFACE
name|AcpiEvGpeXruptHandler
parameter_list|(
name|void
modifier|*
name|Context
parameter_list|)
block|{
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptList
init|=
name|Context
decl_stmt|;
name|UINT32
name|InterruptHandled
init|=
name|ACPI_INTERRUPT_NOT_HANDLED
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|EvGpeXruptHandler
argument_list|)
expr_stmt|;
comment|/*      * We are guaranteed by the ACPICA initialization/shutdown code that      * if this interrupt handler is installed, ACPI is enabled.      */
comment|/* GPEs: Check for and dispatch any GPEs that have occurred */
name|InterruptHandled
operator||=
name|AcpiEvGpeDetect
argument_list|(
name|GpeXruptList
argument_list|)
expr_stmt|;
name|return_UINT32
argument_list|(
name|InterruptHandled
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiEvInstallSciHandler  *  * PARAMETERS:  none  *  * RETURN:      Status  *  * DESCRIPTION: Installs SCI handler.  *  ******************************************************************************/
end_comment

begin_function
name|UINT32
name|AcpiEvInstallSciHandler
parameter_list|(
name|void
parameter_list|)
block|{
name|UINT32
name|Status
init|=
name|AE_OK
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|EvInstallSciHandler
argument_list|)
expr_stmt|;
name|Status
operator|=
name|AcpiOsInstallInterruptHandler
argument_list|(
operator|(
name|UINT32
operator|)
name|AcpiGbl_FADT
operator|.
name|SciInterrupt
argument_list|,
name|AcpiEvSciXruptHandler
argument_list|,
name|AcpiGbl_GpeXruptListHead
argument_list|)
expr_stmt|;
name|return_ACPI_STATUS
argument_list|(
name|Status
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * FUNCTION:    AcpiEvRemoveAllSciHandlers  *  * PARAMETERS:  none  *  * RETURN:      AE_OK if handler uninstalled, AE_ERROR if handler was not  *              installed to begin with  *  * DESCRIPTION: Remove the SCI interrupt handler. No further SCIs will be  *              taken. Remove all host-installed SCI handlers.  *  * Note:  It doesn't seem important to disable all events or set the event  *        enable registers to their original values. The OS should disable  *        the SCI interrupt level when the handler is removed, so no more  *        events will come in.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiEvRemoveAllSciHandlers
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_SCI_HANDLER_INFO
modifier|*
name|SciHandler
decl_stmt|;
name|ACPI_CPU_FLAGS
name|Flags
decl_stmt|;
name|ACPI_STATUS
name|Status
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|EvRemoveAllSciHandlers
argument_list|)
expr_stmt|;
comment|/* Just let the OS remove the handler and disable the level */
name|Status
operator|=
name|AcpiOsRemoveInterruptHandler
argument_list|(
operator|(
name|UINT32
operator|)
name|AcpiGbl_FADT
operator|.
name|SciInterrupt
argument_list|,
name|AcpiEvSciXruptHandler
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|AcpiGbl_SciHandlerList
condition|)
block|{
return|return
operator|(
name|Status
operator|)
return|;
block|}
name|Flags
operator|=
name|AcpiOsAcquireLock
argument_list|(
name|AcpiGbl_GpeLock
argument_list|)
expr_stmt|;
comment|/* Free all host-installed SCI handlers */
while|while
condition|(
name|AcpiGbl_SciHandlerList
condition|)
block|{
name|SciHandler
operator|=
name|AcpiGbl_SciHandlerList
expr_stmt|;
name|AcpiGbl_SciHandlerList
operator|=
name|SciHandler
operator|->
name|Next
expr_stmt|;
name|ACPI_FREE
argument_list|(
name|SciHandler
argument_list|)
expr_stmt|;
block|}
name|AcpiOsReleaseLock
argument_list|(
name|AcpiGbl_GpeLock
argument_list|,
name|Flags
argument_list|)
expr_stmt|;
name|return_ACPI_STATUS
argument_list|(
name|Status
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

end_unit

