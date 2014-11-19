begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: utdecode - Utility decoding routines (value-to-string)  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__UTDECODE_C__
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
literal|"utdecode"
argument_list|)
end_macro

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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetRegionName  *  * PARAMETERS:  Space ID            - ID for the region  *  * RETURN:      Decoded region SpaceId name  *  * DESCRIPTION: Translate a Space ID into a name string (Debug only)  *  ******************************************************************************/
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
comment|/* 0x00 */
literal|"SystemIO"
block|,
comment|/* 0x01 */
literal|"PCI_Config"
block|,
comment|/* 0x02 */
literal|"EmbeddedControl"
block|,
comment|/* 0x03 */
literal|"SMBus"
block|,
comment|/* 0x04 */
literal|"SystemCMOS"
block|,
comment|/* 0x05 */
literal|"PCIBARTarget"
block|,
comment|/* 0x06 */
literal|"IPMI"
block|,
comment|/* 0x07 */
literal|"GeneralPurposeIo"
block|,
comment|/* 0x08 */
literal|"GenericSerialBus"
block|,
comment|/* 0x09 */
literal|"PCC"
comment|/* 0x0A */
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
operator|==
name|ACPI_ADR_SPACE_DATA_TABLE
condition|)
block|{
return|return
operator|(
literal|"DataTable"
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|SpaceId
operator|==
name|ACPI_ADR_SPACE_FIXED_HARDWARE
condition|)
block|{
return|return
operator|(
literal|"FunctionalFixedHW"
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetEventName  *  * PARAMETERS:  EventId             - Fixed event ID  *  * RETURN:      Decoded event ID name  *  * DESCRIPTION: Translate a Event ID into a name string (Debug only)  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetTypeName  *  * PARAMETERS:  Type                - An ACPI object type  *  * RETURN:      Decoded ACPI object type name  *  * DESCRIPTION: Translate a Type ID into a name string (Debug only)  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetNodeName  *  * PARAMETERS:  Object               - A namespace node  *  * RETURN:      ASCII name of the node  *  * DESCRIPTION: Validate the node and return the node's ACPI name.  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetDescriptorName  *  * PARAMETERS:  Object               - An ACPI object  *  * RETURN:      Decoded name of the descriptor type  *  * DESCRIPTION: Validate object and return the descriptor type  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetReferenceName  *  * PARAMETERS:  Object               - An ACPI reference object  *  * RETURN:      Decoded name of the type of reference  *  * DESCRIPTION: Decode a reference object sub-type to a string.  *  ******************************************************************************/
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetMutexName  *  * PARAMETERS:  MutexId         - The predefined ID for this mutex.  *  * RETURN:      Decoded name of the internal mutex  *  * DESCRIPTION: Translate a mutex ID into a name string (Debug only)  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Names for internal mutex objects, used for debug output */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|AcpiGbl_MutexNames
index|[
name|ACPI_NUM_MUTEX
index|]
init|=
block|{
literal|"ACPI_MTX_Interpreter"
block|,
literal|"ACPI_MTX_Namespace"
block|,
literal|"ACPI_MTX_Tables"
block|,
literal|"ACPI_MTX_Events"
block|,
literal|"ACPI_MTX_Caches"
block|,
literal|"ACPI_MTX_Memory"
block|,
literal|"ACPI_MTX_CommandComplete"
block|,
literal|"ACPI_MTX_CommandReady"
block|}
decl_stmt|;
end_decl_stmt

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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiUtGetNotifyName  *  * PARAMETERS:  NotifyValue     - Value from the Notify() request  *  * RETURN:      Decoded name for the notify value  *  * DESCRIPTION: Translate a Notify Value to a notify namestring.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* Names for Notify() values, used for debug output */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_GenericNotify
index|[
name|ACPI_NOTIFY_MAX
operator|+
literal|1
index|]
init|=
block|{
comment|/* 00 */
literal|"Bus Check"
block|,
comment|/* 01 */
literal|"Device Check"
block|,
comment|/* 02 */
literal|"Device Wake"
block|,
comment|/* 03 */
literal|"Eject Request"
block|,
comment|/* 04 */
literal|"Device Check Light"
block|,
comment|/* 05 */
literal|"Frequency Mismatch"
block|,
comment|/* 06 */
literal|"Bus Mode Mismatch"
block|,
comment|/* 07 */
literal|"Power Fault"
block|,
comment|/* 08 */
literal|"Capabilities Check"
block|,
comment|/* 09 */
literal|"Device PLD Check"
block|,
comment|/* 0A */
literal|"Reserved"
block|,
comment|/* 0B */
literal|"System Locality Update"
block|,
comment|/* 0C */
literal|"Shutdown Request"
block|,
comment|/* 0D */
literal|"System Resource Affinity Update"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_DeviceNotify
index|[
literal|4
index|]
init|=
block|{
comment|/* 80 */
literal|"Status Change"
block|,
comment|/* 81 */
literal|"Information Change"
block|,
comment|/* 82 */
literal|"Device-Specific Change"
block|,
comment|/* 83 */
literal|"Device-Specific Change"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_ProcessorNotify
index|[
literal|4
index|]
init|=
block|{
comment|/* 80 */
literal|"Performance Capability Change"
block|,
comment|/* 81 */
literal|"C-State Change"
block|,
comment|/* 82 */
literal|"Throttling Capability Change"
block|,
comment|/* 83 */
literal|"Device-Specific Change"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|AcpiGbl_ThermalNotify
index|[
literal|4
index|]
init|=
block|{
comment|/* 80 */
literal|"Thermal Status Change"
block|,
comment|/* 81 */
literal|"Thermal Trip Point Change"
block|,
comment|/* 82 */
literal|"Thermal Device List Change"
block|,
comment|/* 83 */
literal|"Thermal Relationship Change"
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
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
block|{
comment|/* 00 - 0D are common to all object types */
if|if
condition|(
name|NotifyValue
operator|<=
name|ACPI_NOTIFY_MAX
condition|)
block|{
return|return
operator|(
name|AcpiGbl_GenericNotify
index|[
name|NotifyValue
index|]
operator|)
return|;
block|}
comment|/* 0D - 7F are reserved */
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
comment|/* 80 - 83 are per-object-type */
if|if
condition|(
name|NotifyValue
operator|<=
literal|0x83
condition|)
block|{
switch|switch
condition|(
name|Type
condition|)
block|{
case|case
name|ACPI_TYPE_ANY
case|:
case|case
name|ACPI_TYPE_DEVICE
case|:
return|return
operator|(
name|AcpiGbl_DeviceNotify
index|[
name|NotifyValue
operator|-
literal|0x80
index|]
operator|)
return|;
case|case
name|ACPI_TYPE_PROCESSOR
case|:
return|return
operator|(
name|AcpiGbl_ProcessorNotify
index|[
name|NotifyValue
operator|-
literal|0x80
index|]
operator|)
return|;
case|case
name|ACPI_TYPE_THERMAL
case|:
return|return
operator|(
name|AcpiGbl_ThermalNotify
index|[
name|NotifyValue
operator|-
literal|0x80
index|]
operator|)
return|;
default|default:
return|return
operator|(
literal|"Target object type does not support notifies"
operator|)
return|;
block|}
block|}
comment|/* 84 - BF are device-specific */
if|if
condition|(
name|NotifyValue
operator|<=
name|ACPI_MAX_DEVICE_SPECIFIC_NOTIFY
condition|)
block|{
return|return
operator|(
literal|"Device-Specific"
operator|)
return|;
block|}
comment|/* C0 and above are hardware-specific */
return|return
operator|(
literal|"Hardware-Specific"
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

end_unit

