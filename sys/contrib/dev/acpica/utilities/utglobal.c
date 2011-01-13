begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: utglobal - Global variables for the ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2011, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
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
file|<contrib/dev/acpica/include/acnamesp.h>
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
name|AcpiGbl_LowestDstateNames
index|[
name|ACPI_NUM_SxW_METHODS
index|]
init|=
block|{
literal|"_S0W"
block|,
literal|"_S1W"
block|,
literal|"_S2W"
block|,
literal|"_S3W"
block|,
literal|"_S4W"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AcpiGbl_HighestDstateNames
index|[
name|ACPI_NUM_SxD_METHODS
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
comment|/*  * Predefined ACPI Names (Built-in to the Interpreter)  *  * NOTES:  * 1) _SB_ is defined to be a device to allow \_SB_._INI to be run  *    during the initialization sequence.  * 2) _TZ_ is defined to be a thermal zone in order to allow ASL code to  *    perform a Notify() operation on it. 09/2010: Changed to type Device.  *    This still allows notifies, but does not confuse host code that  *    searches for valid ThermalZone objects.  */
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
name|ACPI_TYPE_DEVICE
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
index|[
name|ACPI_NUM_NS_TYPES
index|]
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
name|UINT64
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
comment|/* ACPI_BITREG_SLEEP_TYPE           */
block|{
name|ACPI_REGISTER_PM1_CONTROL
block|,
name|ACPI_BITPOSITION_SLEEP_TYPE
block|,
name|ACPI_BITMASK_SLEEP_TYPE
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
literal|"SystemCMOS"
block|,
literal|"PCIBARTarget"
block|,
literal|"IPMI"
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
name|ObjDesc
operator|->
name|Common
operator|.
name|Type
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
comment|/*      * Ensure name is valid. The name was validated/repaired when the node      * was created, but make sure it has not been corrupted.      */
name|AcpiUtRepairName
argument_list|(
name|Node
operator|->
name|Name
operator|.
name|Ascii
argument_list|)
expr_stmt|;
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
literal|"Not a Descriptor"
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
literal|"Not a Descriptor"
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

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetReferenceName  *  * PARAMETERS:  Object               - An ACPI reference object  *  * RETURN:      Pointer to a string  *  * DESCRIPTION: Decode a reference object sub-type to a string.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Printable names of reference object sub-types */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_RefClassNames
index|[]
init|=
block|{
comment|/* 00 */
literal|"Local"
block|,
comment|/* 01 */
literal|"Argument"
block|,
comment|/* 02 */
literal|"RefOf"
block|,
comment|/* 03 */
literal|"Index"
block|,
comment|/* 04 */
literal|"DdbHandle"
block|,
comment|/* 05 */
literal|"Named Object"
block|,
comment|/* 06 */
literal|"Debug"
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|AcpiUtGetReferenceName
parameter_list|(
name|ACPI_OPERAND_OBJECT
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
literal|"NULL Object"
operator|)
return|;
block|}
if|if
condition|(
name|ACPI_GET_DESCRIPTOR_TYPE
argument_list|(
name|Object
argument_list|)
operator|!=
name|ACPI_DESC_TYPE_OPERAND
condition|)
block|{
return|return
operator|(
literal|"Not an Operand object"
operator|)
return|;
block|}
if|if
condition|(
name|Object
operator|->
name|Common
operator|.
name|Type
operator|!=
name|ACPI_TYPE_LOCAL_REFERENCE
condition|)
block|{
return|return
operator|(
literal|"Not a Reference object"
operator|)
return|;
block|}
if|if
condition|(
name|Object
operator|->
name|Reference
operator|.
name|Class
operator|>
name|ACPI_REFCLASS_MAX
condition|)
block|{
return|return
operator|(
literal|"Unknown Reference class"
operator|)
return|;
block|}
return|return
operator|(
name|AcpiGbl_RefClassNames
index|[
name|Object
operator|->
name|Reference
operator|.
name|Class
index|]
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

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetNotifyName  *  * PARAMETERS:  NotifyValue     - Value from the Notify() request  *  * RETURN:      String corresponding to the Notify Value.  *  * DESCRIPTION: Translate a Notify Value to a notify namestring.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Names for Notify() values, used for debug output */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_NotifyValueNames
index|[]
init|=
block|{
literal|"Bus Check"
block|,
literal|"Device Check"
block|,
literal|"Device Wake"
block|,
literal|"Eject Request"
block|,
literal|"Device Check Light"
block|,
literal|"Frequency Mismatch"
block|,
literal|"Bus Mode Mismatch"
block|,
literal|"Power Fault"
block|,
literal|"Capabilities Check"
block|,
literal|"Device PLD Check"
block|,
literal|"Reserved"
block|,
literal|"System Locality Update"
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|const
name|char
modifier|*
name|AcpiUtGetNotifyName
parameter_list|(
name|UINT32
name|NotifyValue
parameter_list|)
block|{
if|if
condition|(
name|NotifyValue
operator|<=
name|ACPI_NOTIFY_MAX
condition|)
block|{
return|return
operator|(
name|AcpiGbl_NotifyValueNames
index|[
name|NotifyValue
index|]
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|NotifyValue
operator|<=
name|ACPI_MAX_SYS_NOTIFY
condition|)
block|{
return|return
operator|(
literal|"Reserved"
operator|)
return|;
block|}
else|else
comment|/* Greater or equal to 0x80 */
block|{
return|return
operator|(
literal|"**Device Specific**"
operator|)
return|;
block|}
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtInitGlobals  *  * PARAMETERS:  None  *  * RETURN:      Status  *  * DESCRIPTION: Init library globals.  All globals that require specific  *              initialization should be initialized here!  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
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
name|return_ACPI_STATUS
argument_list|(
name|Status
argument_list|)
expr_stmt|;
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
comment|/* Last OwnerID is never valid */
name|AcpiGbl_OwnerIdMask
index|[
name|ACPI_NUM_OWNERID_MASKS
operator|-
literal|1
index|]
operator|=
literal|0x80000000
expr_stmt|;
comment|/* Event counters */
name|AcpiMethodCount
operator|=
literal|0
expr_stmt|;
name|AcpiSciCount
operator|=
literal|0
expr_stmt|;
name|AcpiGpeCount
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ACPI_NUM_FIXED_EVENTS
condition|;
name|i
operator|++
control|)
block|{
name|AcpiFixedEventCount
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
comment|/* GPE support */
name|AcpiGbl_AllGpesInitialized
operator|=
name|FALSE
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
name|AcpiCurrentGpeCount
operator|=
literal|0
expr_stmt|;
comment|/* Global handlers */
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
name|AcpiGbl_TableHandler
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_InterfaceHandler
operator|=
name|NULL
expr_stmt|;
name|AcpiGbl_GlobalEventHandler
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
name|AcpiGbl_GlobalLockPresent
operator|=
name|FALSE
expr_stmt|;
comment|/* Miscellaneous variables */
name|AcpiGbl_DSDT
operator|=
name|NULL
expr_stmt|;
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
name|AcpiGbl_OsiData
operator|=
literal|0
expr_stmt|;
name|AcpiGbl_OsiMutex
operator|=
name|NULL
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
name|AcpiGbl_ModuleCodeList
operator|=
name|NULL
expr_stmt|;
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
name|Parent
operator|=
name|NULL
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
ifdef|#
directive|ifdef
name|ACPI_DISASSEMBLER
name|AcpiGbl_ExternalList
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
name|AcpiGbl_LowestStackPointer
operator|=
name|ACPI_CAST_PTR
argument_list|(
name|ACPI_SIZE
argument_list|,
name|ACPI_SIZE_MAX
argument_list|)
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
name|AcpiGbl_DisableMemTracking
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
name|return_ACPI_STATUS
argument_list|(
name|AE_OK
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Public globals */
end_comment

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiGbl_FADT
argument_list|)
end_macro

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

begin_macro
name|ACPI_EXPORT_SYMBOL
argument_list|(
argument|AcpiCurrentGpeCount
argument_list|)
end_macro

end_unit

