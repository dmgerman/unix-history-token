begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  *  * Module Name: dmresrc.c - Resource Descriptor disassembly  *              $Revision: 1.35 $  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acpi.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/amlcode.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/acdisasm.h>
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

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ACPI_RESOURCE_HANDLER
function_decl|)
parameter_list|(
name|AML_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|UINT32
name|Level
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
specifier|static
name|ACPI_RESOURCE_HANDLER
name|AcpiGbl_DumpResourceDispatch
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
name|NULL
block|,
comment|/* 0x0A, Reserved */
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
comment|/* 0x0B, ACPI_RESOURCE_NAME_EXTENDED_ADDRESS_SPACE */
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
literal|"%d"
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
name|ACPI_NATIVE_UINT
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
name|AcpiGbl_DumpResourceDispatch
index|[
name|ResourceIndex
index|]
operator|(
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
comment|/*******************************************************************************  *  * FUNCTION:    AcpiDmIsResourceTemplate  *  * PARAMETERS:  Op          - Buffer Op to be examined  *  * RETURN:      Status. AE_OK if valid template  *  * DESCRIPTION: Walk a byte list to determine if it consists of a valid set  *              of resource descriptors.  Nothing is output.  *  ******************************************************************************/
end_comment

begin_function
name|ACPI_STATUS
name|AcpiDmIsResourceTemplate
parameter_list|(
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
name|Aml
argument_list|,
name|Length
argument_list|,
name|NULL
argument_list|,
operator|&
name|EndAml
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

