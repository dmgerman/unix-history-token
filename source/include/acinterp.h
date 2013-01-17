begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acinterp.h - Interpreter subcomponent prototypes and defines  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2013, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACINTERP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACINTERP_H__
end_define

begin_define
define|#
directive|define
name|ACPI_WALK_OPERANDS
value|(&(WalkState->Operands [WalkState->NumOperands -1]))
end_define

begin_comment
comment|/* Macros for tables used for debug output */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXD_OFFSET
parameter_list|(
name|f
parameter_list|)
value|(UINT8) ACPI_OFFSET (ACPI_OPERAND_OBJECT,f)
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_NSOFFSET
parameter_list|(
name|f
parameter_list|)
value|(UINT8) ACPI_OFFSET (ACPI_NAMESPACE_NODE,f)
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_TABLE_SIZE
parameter_list|(
name|name
parameter_list|)
value|(sizeof(name) / sizeof (ACPI_EXDUMP_INFO))
end_define

begin_comment
comment|/*  * If possible, pack the following structures to byte alignment, since we  * don't care about performance for debug output. Two cases where we cannot  * pack the structures:  *  * 1) Hardware does not support misaligned memory transfers  * 2) Compiler does not support pointers within packed structures  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|defined
argument_list|(
name|ACPI_MISALIGNMENT_NOT_SUPPORTED
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ACPI_PACKED_POINTERS_NOT_SUPPORTED
argument_list|)
operator|)
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
specifier|const
struct|struct
name|acpi_exdump_info
block|{
name|UINT8
name|Opcode
decl_stmt|;
name|UINT8
name|Offset
decl_stmt|;
name|char
modifier|*
name|Name
decl_stmt|;
block|}
name|ACPI_EXDUMP_INFO
typedef|;
end_typedef

begin_comment
comment|/* Values for the Opcode field above */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXD_INIT
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_UINT8
value|2
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_UINT16
value|3
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_UINT32
value|4
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_UINT64
value|5
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_LITERAL
value|6
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_POINTER
value|7
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_ADDRESS
value|8
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_STRING
value|9
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_BUFFER
value|10
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_PACKAGE
value|11
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_FIELD
value|12
end_define

begin_define
define|#
directive|define
name|ACPI_EXD_REFERENCE
value|13
end_define

begin_comment
comment|/* restore default alignment */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/*  * exconvrt - object conversion  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExConvertToInteger
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ResultDesc
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExConvertToBuffer
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ResultDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExConvertToString
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ResultDesc
parameter_list|,
name|UINT32
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Types for ->String conversion */
end_comment

begin_define
define|#
directive|define
name|ACPI_EXPLICIT_BYTE_COPY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|ACPI_EXPLICIT_CONVERT_HEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|ACPI_IMPLICIT_CONVERT_HEX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ACPI_EXPLICIT_CONVERT_DECIMAL
value|0x00000003
end_define

begin_function_decl
name|ACPI_STATUS
name|AcpiExConvertToTargetType
parameter_list|(
name|ACPI_OBJECT_TYPE
name|DestinationType
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ResultDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exdebug - AML debug object  */
end_comment

begin_function_decl
name|void
name|AcpiExDoDebugObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|UINT32
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exfield - ACPI AML (p-code) execution - field manipulation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExCommonBufferSetup
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|,
name|UINT32
modifier|*
name|DatumCount
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExWriteWithUpdateRule
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT64
name|Mask
parameter_list|,
name|UINT64
name|FieldValue
parameter_list|,
name|UINT32
name|FieldDatumByteOffset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExGetBufferDatum
parameter_list|(
name|UINT64
modifier|*
name|Datum
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|,
name|UINT32
name|ByteGranularity
parameter_list|,
name|UINT32
name|BufferOffset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExSetBufferDatum
parameter_list|(
name|UINT64
name|MergedDatum
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|,
name|UINT32
name|ByteGranularity
parameter_list|,
name|UINT32
name|BufferOffset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExReadDataFromField
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|RetBufferDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExWriteDataToField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ResultDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exfldio - low level field I/O  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExExtractFromField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExInsertIntoField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|void
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|BufferLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExAccessRegion
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT32
name|FieldDatumByteOffset
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|UINT32
name|ReadWrite
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exmisc - misc support routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExGetObjectReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExConcatTemplate
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc2
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ActualReturnDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExDoConcatenate
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc2
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ActualReturnDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExDoLogicalNumericOp
parameter_list|(
name|UINT16
name|Opcode
parameter_list|,
name|UINT64
name|Integer0
parameter_list|,
name|UINT64
name|Integer1
parameter_list|,
name|BOOLEAN
modifier|*
name|LogicalResult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExDoLogicalOp
parameter_list|(
name|UINT16
name|Opcode
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Operand0
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Operand1
parameter_list|,
name|BOOLEAN
modifier|*
name|LogicalResult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|AcpiExDoMathOp
parameter_list|(
name|UINT16
name|Opcode
parameter_list|,
name|UINT64
name|Operand0
parameter_list|,
name|UINT64
name|Operand1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateMutex
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateProcessor
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreatePowerResource
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateRegion
parameter_list|(
name|UINT8
modifier|*
name|AmlStart
parameter_list|,
name|UINT32
name|AmlLength
parameter_list|,
name|UINT8
name|RegionSpace
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateEvent
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateAlias
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCreateMethod
parameter_list|(
name|UINT8
modifier|*
name|AmlStart
parameter_list|,
name|UINT32
name|AmlLength
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exconfig - dynamic table load/unload  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExLoadOp
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Target
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExLoadTableOp
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExUnloadTable
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|DdbHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exmutex - mutex support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExAcquireMutex
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|TimeDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExAcquireMutexObject
parameter_list|(
name|UINT16
name|Timeout
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_THREAD_ID
name|ThreadId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExReleaseMutex
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExReleaseMutexObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExReleaseAllMutexes
parameter_list|(
name|ACPI_THREAD_STATE
modifier|*
name|Thread
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExUnlinkMutex
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exprep - ACPI AML execution - prep utilities  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExPrepCommonFieldObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT8
name|FieldFlags
parameter_list|,
name|UINT8
name|FieldAttribute
parameter_list|,
name|UINT32
name|FieldBitPosition
parameter_list|,
name|UINT32
name|FieldBitLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExPrepFieldValue
parameter_list|(
name|ACPI_CREATE_FIELD_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exsystem - Interface to OS services  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemDoNotifyOp
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Value
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemDoSleep
parameter_list|(
name|UINT64
name|Time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemDoStall
parameter_list|(
name|UINT32
name|Time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemSignalEvent
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemWaitEvent
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Time
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemResetEvent
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemWaitSemaphore
parameter_list|(
name|ACPI_SEMAPHORE
name|Semaphore
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemWaitMutex
parameter_list|(
name|ACPI_MUTEX
name|Mutex
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exoparg1 - ACPI AML execution, 1 operand  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_0A_0T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_1A_0T_0R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_1A_0T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_1A_1T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_1A_1T_0R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exoparg2 - ACPI AML execution, 2 operands  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_2A_0T_0R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_2A_0T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_2A_1T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_2A_2T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exoparg3 - ACPI AML execution, 3 operands  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_3A_0T_0R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_3A_1T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exoparg6 - ACPI AML execution, 6 operands  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExOpcode_6A_0T_1R
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exresolv - Object resolution and get value functions  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExResolveToValue
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|StackPtr
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExResolveMultiple
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Operand
parameter_list|,
name|ACPI_OBJECT_TYPE
modifier|*
name|ReturnType
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exresnte - resolve namespace node  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExResolveNodeToValue
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|StackPtr
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exresop - resolve operand to value  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExResolveOperands
parameter_list|(
name|UINT16
name|Opcode
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|StackPtr
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exdump - Interpreter debug output routines  */
end_comment

begin_function_decl
name|void
name|AcpiExDumpOperand
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|,
name|UINT32
name|Depth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExDumpOperands
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|Operands
parameter_list|,
specifier|const
name|char
modifier|*
name|OpcodeName
parameter_list|,
name|UINT32
name|NumOpcodes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExDumpObjectDescriptor
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExDumpNamespaceNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exnames - AML namestring support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExGetNameString
parameter_list|(
name|ACPI_OBJECT_TYPE
name|DataType
parameter_list|,
name|UINT8
modifier|*
name|InAmlAddress
parameter_list|,
name|char
modifier|*
modifier|*
name|OutNameString
parameter_list|,
name|UINT32
modifier|*
name|OutNameLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exstore - Object store support  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExStore
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ValDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|DestDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExStoreObjectToNode
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|UINT8
name|ImplicitConversion
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACPI_IMPLICIT_CONVERSION
value|TRUE
end_define

begin_define
define|#
directive|define
name|ACPI_NO_IMPLICIT_CONVERSION
value|FALSE
end_define

begin_comment
comment|/*  * exstoren - resolve/store object  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExResolveObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|SourceDescPtr
parameter_list|,
name|ACPI_OBJECT_TYPE
name|TargetType
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExStoreObjectToObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|DestDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|NewDesc
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exstorob - store object - buffer/string  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExStoreBufferToBuffer
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|TargetDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExStoreStringToString
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|TargetDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * excopy - object copy  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExCopyIntegerToIndexField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|TargetDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCopyIntegerToBankField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|TargetDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCopyDataToNamedField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCopyIntegerToBufferField
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceDesc
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|TargetDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exutils - interpreter/scanner utilities  */
end_comment

begin_function_decl
name|void
name|AcpiExEnterInterpreter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExExitInterpreter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExReacquireInterpreter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExRelinquishInterpreter
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiExTruncateFor32bitTable
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExAcquireGlobalLock
parameter_list|(
name|UINT32
name|Rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExReleaseGlobalLock
parameter_list|(
name|UINT32
name|Rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExEisaIdToString
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
name|UINT64
name|CompressedId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiExIntegerToString
parameter_list|(
name|char
modifier|*
name|Dest
parameter_list|,
name|UINT64
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiIsValidSpaceId
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * exregion - default OpRegion handlers  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemMemorySpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSystemIoSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExPciConfigSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExCmosSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExPciBarSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExEmbeddedControllerSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExSmBusSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiExDataTableSpaceHandler
parameter_list|(
name|UINT32
name|Function
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|UINT32
name|BitWidth
parameter_list|,
name|UINT64
modifier|*
name|Value
parameter_list|,
name|void
modifier|*
name|HandlerContext
parameter_list|,
name|void
modifier|*
name|RegionContext
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __INTERP_H__ */
end_comment

end_unit

