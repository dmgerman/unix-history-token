begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: achware.h -- hardware specific interfaces  *       $Revision: 1.83 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACHWARE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACHWARE_H__
end_define

begin_comment
comment|/* PM Timer ticks per second (HZ) */
end_comment

begin_define
define|#
directive|define
name|PM_TIMER_FREQUENCY
value|3579545
end_define

begin_comment
comment|/* Values for the _SST reserved method */
end_comment

begin_define
define|#
directive|define
name|ACPI_SST_INDICATOR_OFF
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_SST_WORKING
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_SST_WAKING
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_SST_SLEEPING
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_SST_SLEEP_CONTEXT
value|4
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_comment
comment|/*  * hwacpi - high level functions  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwSetMode
parameter_list|(
name|UINT32
name|Mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiHwGetMode
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwregs - ACPI Register I/O  */
end_comment

begin_function_decl
name|ACPI_BIT_REGISTER_INFO
modifier|*
name|AcpiHwGetBitRegisterInfo
parameter_list|(
name|UINT32
name|RegisterId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwRegisterRead
parameter_list|(
name|BOOLEAN
name|UseLock
parameter_list|,
name|UINT32
name|RegisterId
parameter_list|,
name|UINT32
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwRegisterWrite
parameter_list|(
name|BOOLEAN
name|UseLock
parameter_list|,
name|UINT32
name|RegisterId
parameter_list|,
name|UINT32
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLowLevelRead
parameter_list|(
name|UINT32
name|Width
parameter_list|,
name|UINT32
modifier|*
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwLowLevelWrite
parameter_list|(
name|UINT32
name|Width
parameter_list|,
name|UINT32
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearAcpiStatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwgpe - GPE support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiHwWriteGpeEnableReg
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwDisableGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearGpe
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwClearGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwGetGpeStatus
parameter_list|(
name|ACPI_GPE_EVENT_INFO
modifier|*
name|GpeEventInfo
parameter_list|,
name|ACPI_EVENT_STATUS
modifier|*
name|EventStatus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwDisableAllGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableAllRuntimeGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableAllWakeupGpes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiHwEnableRuntimeGpeBlock
parameter_list|(
name|ACPI_GPE_XRUPT_INFO
modifier|*
name|GpeXruptInfo
parameter_list|,
name|ACPI_GPE_BLOCK_INFO
modifier|*
name|GpeBlock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hwtimer - ACPI Timer prototypes  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTimerResolution
parameter_list|(
name|UINT32
modifier|*
name|Resolution
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTimer
parameter_list|(
name|UINT32
modifier|*
name|Ticks
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTimerDuration
parameter_list|(
name|UINT32
name|StartTicks
parameter_list|,
name|UINT32
name|EndTicks
parameter_list|,
name|UINT32
modifier|*
name|TimeElapsed
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACHWARE_H__ */
end_comment

end_unit

