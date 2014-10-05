begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: dmresrc.c - Resource Descriptor disassembly  *  ******************************************************************************/
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
file|<contrib/dev/acpica/include/amlcode.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acdisasm.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DISASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|_COMPONENT
value|ACPI_CA_DEBUGGER
end_define

begin_macro
name|ACPI_MODULE_NAME
argument_list|(
literal|"dbresrc"
argument_list|)
end_macro

begin_comment
comment|/* Dispatch tables for Resource disassembly functions */
end_comment

begin_decl_stmt
specifier|static
name|ACPI_RESOURCE_HANDLER
name|AcpiGbl_DmResourceDispatch
index|[]
init|=
block|{
comment|/* Small descriptors */
name|NULL
block|,
comment|/* 0x00, Reserved */
name|NULL
block|,
comment|/* 0x01, Reserved */
name|NULL
block|,
comment|/* 0x02, Reserved */
name|NULL
block|,
comment|/* 0x03, Reserved */
name|AcpiDmIrqDescriptor
block|,
comment|/* 0x04, ACPI_RESOURCE_NAME_IRQ_FORMAT */
name|AcpiDmDmaDescriptor
block|,
comment|/* 0x05, ACPI_RESOURCE_NAME_DMA_FORMAT */
name|AcpiDmStartDependentDescriptor
block|,
comment|/* 0x06, ACPI_RESOURCE_NAME_START_DEPENDENT */
name|AcpiDmEndDependentDescriptor
block|,
comment|/* 0x07, ACPI_RESOURCE_NAME_END_DEPENDENT */
name|AcpiDmIoDescriptor
block|,
comment|/* 0x08, ACPI_RESOURCE_NAME_IO_PORT */
name|AcpiDmFixedIoDescriptor
block|,
comment|/* 0x09, ACPI_RESOURCE_NAME_FIXED_IO_PORT */
name|AcpiDmFixedDmaDescriptor
block|,
comment|/* 0x0A, ACPI_RESOURCE_NAME_FIXED_DMA */
name|NULL
block|,
comment|/* 0x0B, Reserved */
name|NULL
block|,
comment|/* 0x0C, Reserved */
name|NULL
block|,
comment|/* 0x0D, Reserved */
name|AcpiDmVendorSmallDescriptor
block|,
comment|/* 0x0E, ACPI_RESOURCE_NAME_SMALL_VENDOR */
name|NULL
block|,
comment|/* 0x0F, ACPI_RESOURCE_NAME_END_TAG (not used) */
comment|/* Large descriptors */
name|NULL
block|,
comment|/* 0x00, Reserved */
name|AcpiDmMemory24Descriptor
block|,
comment|/* 0x01, ACPI_RESOURCE_NAME_MEMORY_24 */
name|AcpiDmGenericRegisterDescriptor
block|,
comment|/* 0x02, ACPI_RESOURCE_NAME_GENERIC_REGISTER */
name|NULL
block|,
comment|/* 0x03, Reserved */
name|AcpiDmVendorLargeDescriptor
block|,
comment|/* 0x04, ACPI_RESOURCE_NAME_LARGE_VENDOR */
name|AcpiDmMemory32Descriptor
block|,
comment|/* 0x05, ACPI_RESOURCE_NAME_MEMORY_32 */
name|AcpiDmFixedMemory32Descriptor
block|,
comment|/* 0x06, ACPI_RESOURCE_NAME_FIXED_MEMORY_32 */
name|AcpiDmDwordDescriptor
block|,
comment|/* 0x07, ACPI_RESOURCE_NAME_DWORD_ADDRESS_SPACE */
name|AcpiDmWordDescriptor
block|,
comment|/* 0x08, ACPI_RESOURCE_NAME_WORD_ADDRESS_SPACE */
name|AcpiDmInterruptDescriptor
block|,
comment|/* 0x09, ACPI_RESOURCE_NAME_EXTENDED_XRUPT */
name|AcpiDmQwordDescriptor
block|,
comment|/* 0x0A, ACPI_RESOURCE_NAME_QWORD_ADDRESS_SPACE */
name|AcpiDmExtendedDescriptor
block|,
comment|/* 0x0B, ACPI_RESOURCE_NAME_EXTENDED_ADDRESS_SPACE */
name|AcpiDmGpioDescriptor
block|,
comment|/* 0x0C, ACPI_RESOURCE_NAME_GPIO */
name|NULL
block|,
comment|/* 0x0D, Reserved */
name|AcpiDmSerialBusDescriptor
comment|/* 0x0E, ACPI_RESOURCE_NAME_SERIAL_BUS */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Only used for single-threaded applications */
end_comment

begin_comment
comment|/* TBD: remove when name is passed as parameter to the dump functions */
end_comment

begin_decl_stmt
specifier|static
name|UINT32
name|ResourceName
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmDescriptorName  *  * PARAMETERS:  None  *  * RETURN:      None  *  * DESCRIPTION: Emit a name for the descriptor if one is present (indicated  *              by the name being changed from the default name.) A name is only  *              emitted if a reference to the descriptor has been made somewhere  *              in the original ASL code.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDmDescriptorName
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|ResourceName
operator|==
name|ACPI_DEFAULT_RESNAME
condition|)
block|{
return|return;
block|}
name|AcpiOsPrintf
argument_list|(
literal|"%4.4s"
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|ResourceName
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmDumpInteger*  *  * PARAMETERS:  Value               - Value to emit  *              Name                - Associated name (emitted as a comment)  *  * RETURN:      None  *  * DESCRIPTION: Integer output helper functions  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDmDumpInteger8
parameter_list|(
name|UINT8
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"0x%2.2X,               // %s\n"
argument_list|,
name|Value
argument_list|,
name|Name
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|AcpiDmDumpInteger16
parameter_list|(
name|UINT16
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"0x%4.4X,             // %s\n"
argument_list|,
name|Value
argument_list|,
name|Name
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|AcpiDmDumpInteger32
parameter_list|(
name|UINT32
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"0x%8.8X,         // %s\n"
argument_list|,
name|Value
argument_list|,
name|Name
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|AcpiDmDumpInteger64
parameter_list|(
name|UINT64
name|Value
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"0x%8.8X%8.8X, // %s\n"
argument_list|,
name|ACPI_FORMAT_UINT64
argument_list|(
name|Value
argument_list|)
argument_list|,
name|Name
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmBitList  *  * PARAMETERS:  Mask            - 16-bit value corresponding to 16 interrupt  *                                or DMA values  *  * RETURN:      None  *  * DESCRIPTION: Dump a bit mask as a list of individual interrupt/DMA levels.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDmBitList
parameter_list|(
name|UINT16
name|Mask
parameter_list|)
block|{
name|UINT32
name|i
decl_stmt|;
name|BOOLEAN
name|Previous
init|=
name|FALSE
decl_stmt|;
comment|/* Open the initializer list */
name|AcpiOsPrintf
argument_list|(
literal|"{"
argument_list|)
expr_stmt|;
comment|/* Examine each bit */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
block|{
comment|/* Only interested in bits that are set to 1 */
if|if
condition|(
name|Mask
operator|&
literal|1
condition|)
block|{
if|if
condition|(
name|Previous
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|","
argument_list|)
expr_stmt|;
block|}
name|Previous
operator|=
name|TRUE
expr_stmt|;
name|AcpiOsPrintf
argument_list|(
literal|"%u"
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
name|Mask
operator|>>=
literal|1
expr_stmt|;
block|}
comment|/* Close list */
name|AcpiOsPrintf
argument_list|(
literal|"}\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmResourceTemplate  *  * PARAMETERS:  Info            - Curent parse tree walk info  *              ByteData        - Pointer to the byte list data  *              ByteCount       - Length of the byte list  *  * RETURN:      None  *  * DESCRIPTION: Dump the contents of a Resource Template containing a set of  *              Resource Descriptors.  *  ******************************************************************************/
end_comment

begin_function
name|void
name|AcpiDmResourceTemplate
parameter_list|(
name|ACPI_OP_WALK_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|,
name|UINT8
modifier|*
name|ByteData
parameter_list|,
name|UINT32
name|ByteCount
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|UINT32
name|CurrentByteOffset
decl_stmt|;
name|UINT8
name|ResourceType
decl_stmt|;
name|UINT32
name|ResourceLength
decl_stmt|;
name|void
modifier|*
name|Aml
decl_stmt|;
name|UINT32
name|Level
decl_stmt|;
name|BOOLEAN
name|DependentFns
init|=
name|FALSE
decl_stmt|;
name|UINT8
name|ResourceIndex
decl_stmt|;
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
decl_stmt|;
if|if
condition|(
name|Op
operator|->
name|Asl
operator|.
name|AmlOpcode
operator|!=
name|AML_FIELD_OP
condition|)
block|{
name|Info
operator|->
name|MappingOp
operator|=
name|Op
expr_stmt|;
block|}
name|Level
operator|=
name|Info
operator|->
name|Level
expr_stmt|;
name|ResourceName
operator|=
name|ACPI_DEFAULT_RESNAME
expr_stmt|;
name|Node
operator|=
name|Op
operator|->
name|Common
operator|.
name|Node
expr_stmt|;
if|if
condition|(
name|Node
condition|)
block|{
name|Node
operator|=
name|Node
operator|->
name|Child
expr_stmt|;
block|}
for|for
control|(
name|CurrentByteOffset
operator|=
literal|0
init|;
name|CurrentByteOffset
operator|<
name|ByteCount
condition|;
control|)
block|{
name|Aml
operator|=
operator|&
name|ByteData
index|[
name|CurrentByteOffset
index|]
expr_stmt|;
comment|/* Get the descriptor type and length */
name|ResourceType
operator|=
name|AcpiUtGetResourceType
argument_list|(
name|Aml
argument_list|)
expr_stmt|;
name|ResourceLength
operator|=
name|AcpiUtGetResourceLength
argument_list|(
name|Aml
argument_list|)
expr_stmt|;
comment|/* Validate the Resource Type and Resource Length */
name|Status
operator|=
name|AcpiUtValidateResource
argument_list|(
name|NULL
argument_list|,
name|Aml
argument_list|,
operator|&
name|ResourceIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"/*** Could not validate Resource, type (%X) %s***/\n"
argument_list|,
name|ResourceType
argument_list|,
name|AcpiFormatException
argument_list|(
name|Status
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* Point to next descriptor */
name|CurrentByteOffset
operator|+=
name|AcpiUtGetDescriptorLength
argument_list|(
name|Aml
argument_list|)
expr_stmt|;
comment|/* Descriptor pre-processing */
switch|switch
condition|(
name|ResourceType
condition|)
block|{
case|case
name|ACPI_RESOURCE_NAME_START_DEPENDENT
case|:
comment|/* Finish a previous StartDependentFns */
if|if
condition|(
name|DependentFns
condition|)
block|{
name|Level
operator|--
expr_stmt|;
name|AcpiDmIndent
argument_list|(
name|Level
argument_list|)
expr_stmt|;
name|AcpiOsPrintf
argument_list|(
literal|"}\n"
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|ACPI_RESOURCE_NAME_END_DEPENDENT
case|:
name|Level
operator|--
expr_stmt|;
name|DependentFns
operator|=
name|FALSE
expr_stmt|;
break|break;
case|case
name|ACPI_RESOURCE_NAME_END_TAG
case|:
comment|/* Normal exit, the resource list is finished */
if|if
condition|(
name|DependentFns
condition|)
block|{
comment|/*                  * Close an open StartDependentDescriptor. This indicates a                  * missing EndDependentDescriptor.                  */
name|Level
operator|--
expr_stmt|;
name|DependentFns
operator|=
name|FALSE
expr_stmt|;
comment|/* Go ahead and insert EndDependentFn() */
name|AcpiDmEndDependentDescriptor
argument_list|(
name|Info
argument_list|,
name|Aml
argument_list|,
name|ResourceLength
argument_list|,
name|Level
argument_list|)
expr_stmt|;
name|AcpiDmIndent
argument_list|(
name|Level
argument_list|)
expr_stmt|;
name|AcpiOsPrintf
argument_list|(
literal|"/*** Disassembler: inserted missing EndDependentFn () ***/\n"
argument_list|)
expr_stmt|;
block|}
return|return;
default|default:
break|break;
block|}
comment|/* Disassemble the resource structure */
if|if
condition|(
name|Node
condition|)
block|{
name|ResourceName
operator|=
name|Node
operator|->
name|Name
operator|.
name|Integer
expr_stmt|;
name|Node
operator|=
name|Node
operator|->
name|Peer
expr_stmt|;
block|}
name|AcpiGbl_DmResourceDispatch
index|[
name|ResourceIndex
index|]
operator|(
name|Info
operator|,
name|Aml
operator|,
name|ResourceLength
operator|,
name|Level
operator|)
expr_stmt|;
comment|/* Descriptor post-processing */
if|if
condition|(
name|ResourceType
operator|==
name|ACPI_RESOURCE_NAME_START_DEPENDENT
condition|)
block|{
name|DependentFns
operator|=
name|TRUE
expr_stmt|;
name|Level
operator|++
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmIsResourceTemplate  *  * PARAMETERS:  WalkState           - Current walk info  *              Op                  - Buffer Op to be examined  *  * RETURN:      Status. AE_OK if valid template  *  * DESCRIPTION: Walk a byte list to determine if it consists of a valid set  *              of resource descriptors. Nothing is output.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDmIsResourceTemplate
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_PARSE_OBJECT
modifier|*
name|Op
parameter_list|)
block|{
name|ACPI_STATUS
name|Status
decl_stmt|;
name|ACPI_PARSE_OBJECT
modifier|*
name|NextOp
decl_stmt|;
name|UINT8
modifier|*
name|Aml
decl_stmt|;
name|UINT8
modifier|*
name|EndAml
decl_stmt|;
name|ACPI_SIZE
name|Length
decl_stmt|;
comment|/* This op must be a buffer */
if|if
condition|(
name|Op
operator|->
name|Common
operator|.
name|AmlOpcode
operator|!=
name|AML_BUFFER_OP
condition|)
block|{
return|return
operator|(
name|AE_TYPE
operator|)
return|;
block|}
comment|/* Get the ByteData list and length */
name|NextOp
operator|=
name|Op
operator|->
name|Common
operator|.
name|Value
operator|.
name|Arg
expr_stmt|;
if|if
condition|(
operator|!
name|NextOp
condition|)
block|{
name|AcpiOsPrintf
argument_list|(
literal|"NULL byte list in buffer\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|AE_TYPE
operator|)
return|;
block|}
name|NextOp
operator|=
name|NextOp
operator|->
name|Common
operator|.
name|Next
expr_stmt|;
if|if
condition|(
operator|!
name|NextOp
condition|)
block|{
return|return
operator|(
name|AE_TYPE
operator|)
return|;
block|}
name|Aml
operator|=
name|NextOp
operator|->
name|Named
operator|.
name|Data
expr_stmt|;
name|Length
operator|=
operator|(
name|ACPI_SIZE
operator|)
name|NextOp
operator|->
name|Common
operator|.
name|Value
operator|.
name|Integer
expr_stmt|;
comment|/* Walk the byte list, abort on any invalid descriptor type or length */
name|Status
operator|=
name|AcpiUtWalkAmlResources
argument_list|(
name|WalkState
argument_list|,
name|Aml
argument_list|,
name|Length
argument_list|,
name|NULL
argument_list|,
name|ACPI_CAST_INDIRECT_PTR
argument_list|(
name|void
argument_list|,
operator|&
name|EndAml
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ACPI_FAILURE
argument_list|(
name|Status
argument_list|)
condition|)
block|{
return|return
operator|(
name|AE_TYPE
operator|)
return|;
block|}
comment|/*      * For the resource template to be valid, one EndTag must appear      * at the very end of the ByteList, not before. (For proper disassembly      * of a ResourceTemplate, the buffer must not have any extra data after      * the EndTag.)      */
if|if
condition|(
operator|(
name|Aml
operator|+
name|Length
operator|-
sizeof|sizeof
argument_list|(
name|AML_RESOURCE_END_TAG
argument_list|)
operator|)
operator|!=
name|EndAml
condition|)
block|{
return|return
operator|(
name|AE_AML_NO_RESOURCE_END_TAG
operator|)
return|;
block|}
comment|/*      * All resource descriptors are valid, therefore this list appears      * to be a valid resource template      */
return|return
operator|(
name|AE_OK
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

