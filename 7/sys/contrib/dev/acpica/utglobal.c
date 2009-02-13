begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: utglobal - Global variables for the ACPI subsystem  *              $Revision: 1.249 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|__UTGLOBAL_C__
end_define

begin_define
define|#
directive|define
name|DEFINE_ACPI_GLOBALS
end_define

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acnamesp.h>
end_include

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiGbl_FADT
argument_list|)
end_macro

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_UTILITIES
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"utglobal"
argument_list|)
end_macro

begin_comment
comment|/*******************************************************************************  *  * Static global variable initialization.  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * We want the debug switches statically initialized so they  * are already set when the debugger is entered.  */
end_comment

begin_comment
comment|/* Debug switch - level and trace mask */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_decl_stmt
name|UINT32
name|AcpiDbgLevel
init|=
name|ACPI_DEBUG_DEFAULT
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|UINT32
name|AcpiDbgLevel
init|=
name|ACPI_NORMAL_DEFAULT
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Debug switch - layer (component) mask */
end_comment

begin_decl_stmt
name|UINT32
name|AcpiDbgLayer
init|=
name|ACPI_COMPONENT_DEFAULT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|UINT32
name|AcpiGbl_NestingLevel
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugger globals */
end_comment

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_DbTerminateThreads
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_AbortMethod
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_MethodExecuting
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System flags */
end_comment

begin_decl_stmt
name|UINT32
name|AcpiGbl_StartupFlags
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* System starts uninitialized */
end_comment

begin_decl_stmt
name|BOOLEAN
name|AcpiGbl_Shutdown
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_SleepStateNames
index|[
name|ACPI_S_STATE_COUNT
index|]
init|=
block|{
literal|"\\_S0_"
block|,
literal|"\\_S1_"
block|,
literal|"\\_S2_"
block|,
literal|"\\_S3_"
block|,
literal|"\\_S4_"
block|,
literal|"\\_S5_"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_HighestDstateNames
index|[
literal|4
index|]
init|=
block|{
literal|"_S1D"
block|,
literal|"_S2D"
block|,
literal|"_S3D"
block|,
literal|"_S4D"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiFormatException  *  * PARAMETERS:  Status       - The ACPI_STATUS code to be formatted  *  * RETURN:      A string containing the exception text. A valid pointer is  *              always returned.  *  * DESCRIPTION: This function translates an ACPI exception into an ASCII string  *              It is here instead of utxface.c so it is always present.  *  ******************************************************************************/
end_comment

begin_function
specifier|const
name|char
modifier|*
name|AcpiFormatException
parameter_list|(
name|ACPI_STATUS
name|Status
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|Exception
init|=
name|NULL
decl_stmt|;
name|ACPI_FUNCTION_ENTRY
argument_list|()
expr_stmt|;
name|Exception
operator|=
name|AcpiUtValidateException
argument_list|(
name|Status
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|Exception
condition|)
block|{
comment|/* Exception code was not recognized */
name|ACPI_ERROR
argument_list|(
operator|(
name|AE_INFO
operator|,
literal|"Unknown exception code: 0x%8.8X"
operator|,
name|Status
operator|)
argument_list|)
expr_stmt|;
name|Exception
operator|=
literal|"UNKNOWN_STATUS_CODE"
expr_stmt|;
block|}
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
specifier|const
name|char
argument_list|,
name|Exception
argument_list|)
operator|)
return|;
block|}
end_function

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiFormatException
argument_list|)
end_macro

begin_comment
comment|/*******************************************************************************  *  * Namespace globals  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Predefined ACPI Names (Built-in to the Interpreter)  *  * NOTES:  * 1) _SB_ is defined to be a device to allow \_SB_._INI to be run  *    during the initialization sequence.  * 2) _TZ_ is defined to be a thermal zone in order to allow ASL code to  *    perform a Notify() operation on it.  */
end_comment

begin_decl_stmt
specifier|const
name|ACPI_PREDEFINED_NAMES
name|AcpiGbl_PreDefinedNames
index|[]
init|=
block|{
block|{
literal|"_GPE"
block|,
name|ACPI_TYPE_LOCAL_SCOPE
block|,
name|NULL
block|}
block|,
block|{
literal|"_PR_"
block|,
name|ACPI_TYPE_LOCAL_SCOPE
block|,
name|NULL
block|}
block|,
block|{
literal|"_SB_"
block|,
name|ACPI_TYPE_DEVICE
block|,
name|NULL
block|}
block|,
block|{
literal|"_SI_"
block|,
name|ACPI_TYPE_LOCAL_SCOPE
block|,
name|NULL
block|}
block|,
block|{
literal|"_TZ_"
block|,
name|ACPI_TYPE_THERMAL
block|,
name|NULL
block|}
block|,
block|{
literal|"_REV"
block|,
name|ACPI_TYPE_INTEGER
block|,
operator|(
name|char
operator|*
operator|)
name|ACPI_CA_SUPPORT_LEVEL
block|}
block|,
block|{
literal|"_OS_"
block|,
name|ACPI_TYPE_STRING
block|,
name|ACPI_OS_NAME
block|}
block|,
block|{
literal|"_GL_"
block|,
name|ACPI_TYPE_MUTEX
block|,
operator|(
name|char
operator|*
operator|)
literal|1
block|}
block|,
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ACPI_NO_METHOD_EXECUTION
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_CONSTANT_EVAL_ONLY
argument_list|)
block|{
literal|"_OSI"
block|,
name|ACPI_TYPE_METHOD
block|,
operator|(
name|char
operator|*
operator|)
literal|1
block|}
block|,
endif|#
directive|endif
comment|/* Table terminator */
block|{
name|NULL
block|,
name|ACPI_TYPE_ANY
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Properties of the ACPI Object Types, both internal and external.  * The table is indexed by values of ACPI_OBJECT_TYPE  */
end_comment

begin_decl_stmt
specifier|const
name|UINT8
name|AcpiGbl_NsProperties
index|[]
init|=
block|{
name|ACPI_NS_NORMAL
block|,
comment|/* 00 Any              */
name|ACPI_NS_NORMAL
block|,
comment|/* 01 Number           */
name|ACPI_NS_NORMAL
block|,
comment|/* 02 String           */
name|ACPI_NS_NORMAL
block|,
comment|/* 03 Buffer           */
name|ACPI_NS_NORMAL
block|,
comment|/* 04 Package          */
name|ACPI_NS_NORMAL
block|,
comment|/* 05 FieldUnit        */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 06 Device           */
name|ACPI_NS_NORMAL
block|,
comment|/* 07 Event            */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 08 Method           */
name|ACPI_NS_NORMAL
block|,
comment|/* 09 Mutex            */
name|ACPI_NS_NORMAL
block|,
comment|/* 10 Region           */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 11 Power            */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 12 Processor        */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 13 Thermal          */
name|ACPI_NS_NORMAL
block|,
comment|/* 14 BufferField      */
name|ACPI_NS_NORMAL
block|,
comment|/* 15 DdbHandle        */
name|ACPI_NS_NORMAL
block|,
comment|/* 16 Debug Object     */
name|ACPI_NS_NORMAL
block|,
comment|/* 17 DefField         */
name|ACPI_NS_NORMAL
block|,
comment|/* 18 BankField        */
name|ACPI_NS_NORMAL
block|,
comment|/* 19 IndexField       */
name|ACPI_NS_NORMAL
block|,
comment|/* 20 Reference        */
name|ACPI_NS_NORMAL
block|,
comment|/* 21 Alias            */
name|ACPI_NS_NORMAL
block|,
comment|/* 22 MethodAlias      */
name|ACPI_NS_NORMAL
block|,
comment|/* 23 Notify           */
name|ACPI_NS_NORMAL
block|,
comment|/* 24 Address Handler  */
name|ACPI_NS_NEWSCOPE
operator||
name|ACPI_NS_LOCAL
block|,
comment|/* 25 Resource Desc    */
name|ACPI_NS_NEWSCOPE
operator||
name|ACPI_NS_LOCAL
block|,
comment|/* 26 Resource Field   */
name|ACPI_NS_NEWSCOPE
block|,
comment|/* 27 Scope            */
name|ACPI_NS_NORMAL
block|,
comment|/* 28 Extra            */
name|ACPI_NS_NORMAL
block|,
comment|/* 29 Data             */
name|ACPI_NS_NORMAL
comment|/* 30 Invalid          */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hex to ASCII conversion table */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|AcpiGbl_HexToAscii
index|[]
init|=
block|{
literal|'0'
block|,
literal|'1'
block|,
literal|'2'
block|,
literal|'3'
block|,
literal|'4'
block|,
literal|'5'
block|,
literal|'6'
block|,
literal|'7'
block|,
literal|'8'
block|,
literal|'9'
block|,
literal|'A'
block|,
literal|'B'
block|,
literal|'C'
block|,
literal|'D'
block|,
literal|'E'
block|,
literal|'F'
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtHexToAsciiChar  *  * PARAMETERS:  Integer             - Contains the hex digit  *              Position            - bit position of the digit within the  *                                    integer (multiple of 4)  *  * RETURN:      The converted Ascii character  *  * DESCRIPTION: Convert a hex digit to an Ascii character  *  ******************************************************************************/
end_comment

begin_function
name|char
name|AcpiUtHexToAsciiChar
parameter_list|(
name|ACPI_INTEGER
name|Integer
parameter_list|,
name|UINT32
name|Position
parameter_list|)
block|{
return|return
operator|(
name|AcpiGbl_HexToAscii
index|[
operator|(
name|Integer
operator|>>
name|Position
operator|)
operator|&
literal|0xF
index|]
operator|)
return|;
block|}
end_function

begin_comment
comment|/******************************************************************************  *  * Event and Hardware globals  *  ******************************************************************************/
end_comment

begin_decl_stmt
name|ACPI_BIT_REGISTER_INFO
name|AcpiGbl_BitRegisterInfo
index|[
name|ACPI_NUM_BITREG
index|]
init|=
block|{
comment|/* Name                                     Parent Register             Register Bit Position                   Register Bit Mask       */
comment|/* ACPI_BITREG_TIMER_STATUS         */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_TIMER_STATUS
block|,
name|ACPI_BITMASK_TIMER_STATUS
block|}
block|,
comment|/* ACPI_BITREG_BUS_MASTER_STATUS    */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_BUS_MASTER_STATUS
block|,
name|ACPI_BITMASK_BUS_MASTER_STATUS
block|}
block|,
comment|/* ACPI_BITREG_GLOBAL_LOCK_STATUS   */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_GLOBAL_LOCK_STATUS
block|,
name|ACPI_BITMASK_GLOBAL_LOCK_STATUS
block|}
block|,
comment|/* ACPI_BITREG_POWER_BUTTON_STATUS  */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_POWER_BUTTON_STATUS
block|,
name|ACPI_BITMASK_POWER_BUTTON_STATUS
block|}
block|,
comment|/* ACPI_BITREG_SLEEP_BUTTON_STATUS  */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_SLEEP_BUTTON_STATUS
block|,
name|ACPI_BITMASK_SLEEP_BUTTON_STATUS
block|}
block|,
comment|/* ACPI_BITREG_RT_CLOCK_STATUS      */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_RT_CLOCK_STATUS
block|,
name|ACPI_BITMASK_RT_CLOCK_STATUS
block|}
block|,
comment|/* ACPI_BITREG_WAKE_STATUS          */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_WAKE_STATUS
block|,
name|ACPI_BITMASK_WAKE_STATUS
block|}
block|,
comment|/* ACPI_BITREG_PCIEXP_WAKE_STATUS   */
block|{
name|ACPI_REGISTER_PM1_STATUS
block|,
name|ACPI_BITPOSITION_PCIEXP_WAKE_STATUS
block|,
name|ACPI_BITMASK_PCIEXP_WAKE_STATUS
block|}
block|,
comment|/* ACPI_BITREG_TIMER_ENABLE         */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_TIMER_ENABLE
block|,
name|ACPI_BITMASK_TIMER_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_GLOBAL_LOCK_ENABLE   */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_GLOBAL_LOCK_ENABLE
block|,
name|ACPI_BITMASK_GLOBAL_LOCK_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_POWER_BUTTON_ENABLE  */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_POWER_BUTTON_ENABLE
block|,
name|ACPI_BITMASK_POWER_BUTTON_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_SLEEP_BUTTON_ENABLE  */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_SLEEP_BUTTON_ENABLE
block|,
name|ACPI_BITMASK_SLEEP_BUTTON_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_RT_CLOCK_ENABLE      */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_RT_CLOCK_ENABLE
block|,
name|ACPI_BITMASK_RT_CLOCK_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_WAKE_ENABLE          */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* ACPI_BITREG_PCIEXP_WAKE_DISABLE  */
block|{
name|ACPI_REGISTER_PM1_ENABLE
block|,
name|ACPI_BITPOSITION_PCIEXP_WAKE_DISABLE
block|,
name|ACPI_BITMASK_PCIEXP_WAKE_DISABLE
block|}
block|,
comment|/* ACPI_BITREG_SCI_ENABLE           */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_SCI_ENABLE
block|,
name|ACPI_BITMASK_SCI_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_BUS_MASTER_RLD       */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_BUS_MASTER_RLD
block|,
name|ACPI_BITMASK_BUS_MASTER_RLD
block|}
block|,
comment|/* ACPI_BITREG_GLOBAL_LOCK_RELEASE  */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_GLOBAL_LOCK_RELEASE
block|,
name|ACPI_BITMASK_GLOBAL_LOCK_RELEASE
block|}
block|,
comment|/* ACPI_BITREG_SLEEP_TYPE_A         */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_SLEEP_TYPE_X
block|,
name|ACPI_BITMASK_SLEEP_TYPE_X
block|}
block|,
comment|/* ACPI_BITREG_SLEEP_TYPE_B         */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_SLEEP_TYPE_X
block|,
name|ACPI_BITMASK_SLEEP_TYPE_X
block|}
block|,
comment|/* ACPI_BITREG_SLEEP_ENABLE         */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_SLEEP_ENABLE
block|,
name|ACPI_BITMASK_SLEEP_ENABLE
block|}
block|,
comment|/* ACPI_BITREG_ARB_DIS              */
block|{
name|ACPI_REGISTER_PM2_CONTROL
block|,
name|ACPI_BITPOSITION_ARB_DISABLE
block|,
name|ACPI_BITMASK_ARB_DISABLE
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ACPI_FIXED_EVENT_INFO
name|AcpiGbl_FixedEventInfo
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
init|=
block|{
comment|/* ACPI_EVENT_PMTIMER       */
block|{
name|ACPI_BITREG_TIMER_STATUS
block|,
name|ACPI_BITREG_TIMER_ENABLE
block|,
name|ACPI_BITMASK_TIMER_STATUS
block|,
name|ACPI_BITMASK_TIMER_ENABLE
block|}
block|,
comment|/* ACPI_EVENT_GLOBAL        */
block|{
name|ACPI_BITREG_GLOBAL_LOCK_STATUS
block|,
name|ACPI_BITREG_GLOBAL_LOCK_ENABLE
block|,
name|ACPI_BITMASK_GLOBAL_LOCK_STATUS
block|,
name|ACPI_BITMASK_GLOBAL_LOCK_ENABLE
block|}
block|,
comment|/* ACPI_EVENT_POWER_BUTTON  */
block|{
name|ACPI_BITREG_POWER_BUTTON_STATUS
block|,
name|ACPI_BITREG_POWER_BUTTON_ENABLE
block|,
name|ACPI_BITMASK_POWER_BUTTON_STATUS
block|,
name|ACPI_BITMASK_POWER_BUTTON_ENABLE
block|}
block|,
comment|/* ACPI_EVENT_SLEEP_BUTTON  */
block|{
name|ACPI_BITREG_SLEEP_BUTTON_STATUS
block|,
name|ACPI_BITREG_SLEEP_BUTTON_ENABLE
block|,
name|ACPI_BITMASK_SLEEP_BUTTON_STATUS
block|,
name|ACPI_BITMASK_SLEEP_BUTTON_ENABLE
block|}
block|,
comment|/* ACPI_EVENT_RTC           */
block|{
name|ACPI_BITREG_RT_CLOCK_STATUS
block|,
name|ACPI_BITREG_RT_CLOCK_ENABLE
block|,
name|ACPI_BITMASK_RT_CLOCK_STATUS
block|,
name|ACPI_BITMASK_RT_CLOCK_ENABLE
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetRegionName  *  * PARAMETERS:  None.  *  * RETURN:      Status  *  * DESCRIPTION: Translate a Space ID into a name string (Debug only)  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Region type decoding */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_RegionTypes
index|[
name|ACPI_NUM_PREDEFINED_REGIONS
index|]
init|=
block|{
literal|"SystemMemory"
block|,
literal|"SystemIO"
block|,
literal|"PCI_Config"
block|,
literal|"EmbeddedControl"
block|,
literal|"SMBus"
block|,
literal|"CMOS"
block|,
literal|"PCIBARTarget"
block|,
literal|"DataTable"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|AcpiUtGetRegionName
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|)
block|{
if|if
condition|(
name|SpaceId
operator|>=
name|ACPI_USER_REGION_BEGIN
condition|)
block|{
return|return
operator|(
literal|"UserDefinedRegion"
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|SpaceId
operator|>=
name|ACPI_NUM_PREDEFINED_REGIONS
condition|)
block|{
return|return
operator|(
literal|"InvalidSpaceId"
operator|)
return|;
block|}
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_RegionTypes
index|[
name|SpaceId
index|]
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetEventName  *  * PARAMETERS:  None.  *  * RETURN:      Status  *  * DESCRIPTION: Translate a Event ID into a name string (Debug only)  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Event type decoding */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_EventTypes
index|[
name|ACPI_NUM_FIXED_EVENTS
index|]
init|=
block|{
literal|"PM_Timer"
block|,
literal|"GlobalLock"
block|,
literal|"PowerButton"
block|,
literal|"SleepButton"
block|,
literal|"RealTimeClock"
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|AcpiUtGetEventName
parameter_list|(
name|UINT32
name|EventId
parameter_list|)
block|{
if|if
condition|(
name|EventId
operator|>
name|ACPI_EVENT_MAX
condition|)
block|{
return|return
operator|(
literal|"InvalidEventID"
operator|)
return|;
block|}
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_EventTypes
index|[
name|EventId
index|]
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetTypeName  *  * PARAMETERS:  None.  *  * RETURN:      Status  *  * DESCRIPTION: Translate a Type ID into a name string (Debug only)  *  ******************************************************************************/
end_comment

begin_comment
comment|/*  * Elements of AcpiGbl_NsTypeNames below must match  * one-to-one with values of ACPI_OBJECT_TYPE  *  * The type ACPI_TYPE_ANY (Untyped) is used as a "don't care" when searching;  * when stored in a table it really means that we have thus far seen no  * evidence to indicate what type is actually going to be stored for this entry.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
name|AcpiGbl_BadType
index|[]
init|=
literal|"UNDEFINED"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Printable names of the ACPI object types */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_NsTypeNames
index|[]
init|=
block|{
comment|/* 00 */
literal|"Untyped"
block|,
comment|/* 01 */
literal|"Integer"
block|,
comment|/* 02 */
literal|"String"
block|,
comment|/* 03 */
literal|"Buffer"
block|,
comment|/* 04 */
literal|"Package"
block|,
comment|/* 05 */
literal|"FieldUnit"
block|,
comment|/* 06 */
literal|"Device"
block|,
comment|/* 07 */
literal|"Event"
block|,
comment|/* 08 */
literal|"Method"
block|,
comment|/* 09 */
literal|"Mutex"
block|,
comment|/* 10 */
literal|"Region"
block|,
comment|/* 11 */
literal|"Power"
block|,
comment|/* 12 */
literal|"Processor"
block|,
comment|/* 13 */
literal|"Thermal"
block|,
comment|/* 14 */
literal|"BufferField"
block|,
comment|/* 15 */
literal|"DdbHandle"
block|,
comment|/* 16 */
literal|"DebugObject"
block|,
comment|/* 17 */
literal|"RegionField"
block|,
comment|/* 18 */
literal|"BankField"
block|,
comment|/* 19 */
literal|"IndexField"
block|,
comment|/* 20 */
literal|"Reference"
block|,
comment|/* 21 */
literal|"Alias"
block|,
comment|/* 22 */
literal|"MethodAlias"
block|,
comment|/* 23 */
literal|"Notify"
block|,
comment|/* 24 */
literal|"AddrHandler"
block|,
comment|/* 25 */
literal|"ResourceDesc"
block|,
comment|/* 26 */
literal|"ResourceFld"
block|,
comment|/* 27 */
literal|"Scope"
block|,
comment|/* 28 */
literal|"Extra"
block|,
comment|/* 29 */
literal|"Data"
block|,
comment|/* 30 */
literal|"Invalid"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|AcpiUtGetTypeName
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
block|{
if|if
condition|(
name|Type
operator|>
name|ACPI_TYPE_INVALID
condition|)
block|{
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_BadType
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_NsTypeNames
index|[
name|Type
index|]
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|AcpiUtGetObjectTypeName
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ObjDesc
condition|)
block|{
return|return
operator|(
literal|"[NULL Object Descriptor]"
operator|)
return|;
block|}
return|return
operator|(
name|AcpiUtGetTypeName
argument_list|(
name|ACPI_GET_OBJECT_TYPE
argument_list|(
name|ObjDesc
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetNodeName  *  * PARAMETERS:  Object               - A namespace node  *  * RETURN:      Pointer to a string  *  * DESCRIPTION: Validate the node and return the node's ACPI name.  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtGetNodeName
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
block|{
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
init|=
operator|(
name|ACPI_NAMESPACE_NODE
operator|*
operator|)
name|Object
decl_stmt|;
comment|/* Must return a string of exactly 4 characters == ACPI_NAME_SIZE */
if|if
condition|(
operator|!
name|Object
condition|)
block|{
return|return
operator|(
literal|"NULL"
operator|)
return|;
block|}
comment|/* Check for Root node */
if|if
condition|(
operator|(
name|Object
operator|==
name|ACPI_ROOT_OBJECT
operator|)
operator|||
operator|(
name|Object
operator|==
name|AcpiGbl_RootNode
operator|)
condition|)
block|{
return|return
operator|(
literal|"\"\\\" "
operator|)
return|;
block|}
comment|/* Descriptor must be a namespace node */
if|if
condition|(
name|ACPI_GET_DESCRIPTOR_TYPE
argument_list|(
name|Node
argument_list|)
operator|!=
name|ACPI_DESC_TYPE_NAMED
condition|)
block|{
return|return
operator|(
literal|"####"
operator|)
return|;
block|}
comment|/* Name must be a valid ACPI name */
if|if
condition|(
operator|!
name|AcpiUtValidAcpiName
argument_list|(
name|Node
operator|->
name|Name
operator|.
name|Integer
argument_list|)
condition|)
block|{
name|Node
operator|->
name|Name
operator|.
name|Integer
operator|=
name|AcpiUtRepairName
argument_list|(
name|Node
operator|->
name|Name
operator|.
name|Ascii
argument_list|)
expr_stmt|;
block|}
comment|/* Return the name */
return|return
operator|(
name|Node
operator|->
name|Name
operator|.
name|Ascii
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetDescriptorName  *  * PARAMETERS:  Object               - An ACPI object  *  * RETURN:      Pointer to a string  *  * DESCRIPTION: Validate object and return the descriptor type  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Printable names of object descriptor types */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_DescTypeNames
index|[]
init|=
block|{
comment|/* 00 */
literal|"Invalid"
block|,
comment|/* 01 */
literal|"Cached"
block|,
comment|/* 02 */
literal|"State-Generic"
block|,
comment|/* 03 */
literal|"State-Update"
block|,
comment|/* 04 */
literal|"State-Package"
block|,
comment|/* 05 */
literal|"State-Control"
block|,
comment|/* 06 */
literal|"State-RootParseScope"
block|,
comment|/* 07 */
literal|"State-ParseScope"
block|,
comment|/* 08 */
literal|"State-WalkScope"
block|,
comment|/* 09 */
literal|"State-Result"
block|,
comment|/* 10 */
literal|"State-Notify"
block|,
comment|/* 11 */
literal|"State-Thread"
block|,
comment|/* 12 */
literal|"Walk"
block|,
comment|/* 13 */
literal|"Parser"
block|,
comment|/* 14 */
literal|"Operand"
block|,
comment|/* 15 */
literal|"Node"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|AcpiUtGetDescriptorName
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
block|{
if|if
condition|(
operator|!
name|Object
condition|)
block|{
return|return
operator|(
literal|"NULL OBJECT"
operator|)
return|;
block|}
if|if
condition|(
name|ACPI_GET_DESCRIPTOR_TYPE
argument_list|(
name|Object
argument_list|)
operator|>
name|ACPI_DESC_TYPE_MAX
condition|)
block|{
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_BadType
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
name|ACPI_CAST_PTR
argument_list|(
name|char
argument_list|,
name|AcpiGbl_DescTypeNames
index|[
name|ACPI_GET_DESCRIPTOR_TYPE
argument_list|(
name|Object
argument_list|)
index|]
argument_list|)
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ACPI_DEBUG_OUTPUT
argument_list|)
operator|||
name|defined
argument_list|(
name|ACPI_DEBUGGER
argument_list|)
end_if

begin_comment
comment|/*  * Strings and procedures used for debug only  */
end_comment

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetMutexName  *  * PARAMETERS:  MutexId         - The predefined ID for this mutex.  *  * RETURN:      String containing the name of the mutex. Always returns a valid  *              pointer.  *  * DESCRIPTION: Translate a mutex ID into a name string (Debug only)  *  ******************************************************************************/
end_comment

begin_function
name|char
modifier|*
name|AcpiUtGetMutexName
parameter_list|(
name|UINT32
name|MutexId
parameter_list|)
block|{
if|if
condition|(
name|MutexId
operator|>
name|ACPI_MAX_MUTEX
condition|)
block|{
return|return
operator|(
literal|"Invalid Mutex ID"
operator|)
return|;
block|}
return|return
operator|(
name|AcpiGbl_MutexNames
index|[
name|MutexId
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtValidObjectType  *  * PARAMETERS:  Type            - Object type to be validated  *  * RETURN:      TRUE if valid object type, FALSE otherwise  *  * DESCRIPTION: Validate an object type  *  ******************************************************************************/
end_comment

begin_function
name|BOOLEAN
name|AcpiUtValidObjectType
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
block|{
if|if
condition|(
name|Type
operator|>
name|ACPI_TYPE_LOCAL_MAX
condition|)
block|{
comment|/* Note: Assumes all TYPEs are contiguous (external/local) */
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtInitGlobals  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Init library globals.  All globals that require specific  *              initialization should be initialized here!  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiUtInitGlobals
parameter_list|(
name|void
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|UINT32
name|i
decl_stmt|;
name|ACPI_FUNCTION_TRACE
argument_list|(
name|UtInitGlobals
argument_list|)
expr_stmt|;
comment|/* Create all memory caches */
name|Status
operator|=
name|AcpiUtCreateCaches
argument_list|()
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
return|return;
block|}
comment|/* Mutex locked flags */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ACPI_NUM_MUTEX
condition|;
name|i
operator|++
control|)
block|{
name|AcpiGbl_MutexInfo
index|[
name|i
index|]
operator|.
name|Mutex
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_MutexInfo
index|[
name|i
index|]
operator|.
name|ThreadId
operator|=
name|ACPI_MUTEX_NOT_ACQUIRED
expr_stmt|;
name|AcpiGbl_MutexInfo
index|[
name|i
index|]
operator|.
name|UseCount
operator|=
literal|0
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ACPI_NUM_OWNERID_MASKS
condition|;
name|i
operator|++
control|)
block|{
name|AcpiGbl_OwnerIdMask
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
name|AcpiGbl_OwnerIdMask
index|[
name|ACPI_NUM_OWNERID_MASKS
operator|-
literal|1
index|]
operator|=
literal|0x80000000
expr_stmt|;
comment|/* Last ID is never valid */
comment|/* GPE support */
name|AcpiGpeCount
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_GpeXruptListHead
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_GpeFadtBlocks
index|[
literal|0
index|]
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_GpeFadtBlocks
index|[
literal|1
index|]
operator|=
name|NULL
expr_stmt|;
comment|/* Global notify handlers */
name|AcpiGbl_SystemNotify
operator|.
name|Handler
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_DeviceNotify
operator|.
name|Handler
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_ExceptionHandler
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_InitHandler
operator|=
name|NULL
expr_stmt|;
comment|/* Global Lock support */
name|AcpiGbl_GlobalLockSemaphore
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_GlobalLockMutex
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_GlobalLockAcquired
operator|=
name|FALSE
expr_stmt|;
name|AcpiGbl_GlobalLockHandle
operator|=
literal|0
expr_stmt|;
comment|/* Miscellaneous variables */
name|AcpiGbl_CmSingleStep
operator|=
name|FALSE
expr_stmt|;
name|AcpiGbl_DbTerminateThreads
operator|=
name|FALSE
expr_stmt|;
name|AcpiGbl_Shutdown
operator|=
name|FALSE
expr_stmt|;
name|AcpiGbl_NsLookupCount
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_PsFindCount
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_AcpiHardwarePresent
operator|=
name|TRUE
expr_stmt|;
name|AcpiGbl_LastOwnerIdIndex
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_NextOwnerIdOffset
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_TraceMethodName
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_TraceDbgLevel
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_TraceDbgLayer
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_DebuggerConfiguration
operator|=
name|DEBUGGER_THREADING
expr_stmt|;
name|AcpiGbl_DbOutputFlags
operator|=
name|ACPI_DB_CONSOLE_OUTPUT
expr_stmt|;
comment|/* Hardware oriented */
name|AcpiGbl_EventsInitialized
operator|=
name|FALSE
expr_stmt|;
name|AcpiGbl_SystemAwakeAndRunning
operator|=
name|TRUE
expr_stmt|;
comment|/* Namespace */
name|AcpiGbl_RootNode
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Name
operator|.
name|Integer
operator|=
name|ACPI_ROOT_NAME
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|DescriptorType
operator|=
name|ACPI_DESC_TYPE_NAMED
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Type
operator|=
name|ACPI_TYPE_DEVICE
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Child
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Peer
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Object
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_RootNodeStruct
operator|.
name|Flags
operator|=
name|ANOBJ_END_OF_PEER_LIST
expr_stmt|;
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
name|AcpiGbl_LowestStackPointer
operator|=
name|ACPI_SIZE_MAX
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ACPI_DBG_TRACK_ALLOCATIONS
name|AcpiGbl_DisplayFinalMemStats
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
name|return_VOID
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Public globals */
end_comment

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiDbgLevel
argument_list|)
end_macro

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiDbgLayer
argument_list|)
end_macro

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiGpeCount
argument_list|)
end_macro

end_unit

