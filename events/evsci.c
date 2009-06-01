begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: evsci - System Control Interrupt configuration and  *                      legacy to ACPI mode state transition functions  *              $Revision: 1.102 $  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may   * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acevents.h>
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
comment|/*      * We are guaranteed by the ACPI CA initialization/shutdown code that      * if this interrupt handler is installed, ACPI is enabled.      */
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
comment|/*      * We are guaranteed by the ACPI CA initialization/shutdown code that      * if this interrupt handler is installed, ACPI is enabled.      */
comment|/*      * GPEs:      * Check for and dispatch any GPEs that have occurred      */
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
comment|/******************************************************************************  *  * FUNCTION:    AcpiEvRemoveSciHandler  *  * PARAMETERS:  none  *  * RETURN:      E_OK if handler uninstalled OK, E_ERROR if handler was not  *              installed to begin with  *  * DESCRIPTION: Remove the SCI interrupt handler.  No further SCIs will be  *              taken.  *  * Note:  It doesn't seem important to disable all events or set the event  *        enable registers to their original values.  The OS should disable  *        the SCI interrupt level when the handler is removed, so no more  *        events will come in.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiEvRemoveSciHandler
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|EvRemoveSciHandler
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
name|return_ACPI_STATUS
argument_list|(
name|Status
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

