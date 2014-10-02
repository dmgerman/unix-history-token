begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Module Name: dtcompiler.h - header for data table compiler  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_define
define|#
directive|define
name|__DTCOMPILER_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_DTCOMPILER
end_ifndef

begin_define
define|#
directive|define
name|_DTCOMPILER
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<contrib/dev/acpica/include/acdisasm.h>
end_include

begin_define
define|#
directive|define
name|ASL_FIELD_CACHE_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|ASL_SUBTABLE_CACHE_SIZE
value|128
end_define

begin_undef
undef|#
directive|undef
name|DT_EXTERN
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_DECLARE_DT_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|DT_EXTERN
end_define

begin_define
define|#
directive|define
name|DT_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)=(b)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DT_EXTERN
value|extern
end_define

begin_define
define|#
directive|define
name|DT_INIT_GLOBAL
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Types for individual fields (one per input line) */
end_comment

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_STRING
value|0
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_INTEGER
value|1
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_BUFFER
value|2
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_PCI_PATH
value|3
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_FLAG
value|4
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_FLAGS_INTEGER
value|5
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_INLINE_SUBTABLE
value|6
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_UUID
value|7
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_UNICODE
value|8
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_DEVICE_PATH
value|9
end_define

begin_define
define|#
directive|define
name|DT_FIELD_TYPE_LABEL
value|10
end_define

begin_comment
comment|/*  * Structure used for each individual field within an ACPI table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dt_field
block|{
name|char
modifier|*
name|Name
decl_stmt|;
comment|/* Field name (from name : value) */
name|char
modifier|*
name|Value
decl_stmt|;
comment|/* Field value (from name : value) */
name|struct
name|dt_field
modifier|*
name|Next
decl_stmt|;
comment|/* Next field */
name|struct
name|dt_field
modifier|*
name|NextLabel
decl_stmt|;
comment|/* If field is a label, next label */
name|UINT32
name|Line
decl_stmt|;
comment|/* Line number for this field */
name|UINT32
name|ByteOffset
decl_stmt|;
comment|/* Offset in source file for field */
name|UINT32
name|NameColumn
decl_stmt|;
comment|/* Start column for field name */
name|UINT32
name|Column
decl_stmt|;
comment|/* Start column for field value */
name|UINT32
name|TableOffset
decl_stmt|;
comment|/* Binary offset within ACPI table */
name|UINT8
name|Flags
decl_stmt|;
block|}
name|DT_FIELD
typedef|;
end_typedef

begin_comment
comment|/* Flags for above */
end_comment

begin_define
define|#
directive|define
name|DT_FIELD_NOT_ALLOCATED
value|1
end_define

begin_comment
comment|/*  * Structure used for individual subtables within an ACPI table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dt_subtable
block|{
name|struct
name|dt_subtable
modifier|*
name|Parent
decl_stmt|;
name|struct
name|dt_subtable
modifier|*
name|Child
decl_stmt|;
name|struct
name|dt_subtable
modifier|*
name|Peer
decl_stmt|;
name|struct
name|dt_subtable
modifier|*
name|StackTop
decl_stmt|;
name|UINT8
modifier|*
name|Buffer
decl_stmt|;
name|UINT8
modifier|*
name|LengthField
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|TotalLength
decl_stmt|;
name|UINT32
name|SizeOfLengthField
decl_stmt|;
name|UINT16
name|Depth
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|DT_SUBTABLE
typedef|;
end_typedef

begin_comment
comment|/*  * Globals  */
end_comment

begin_comment
comment|/* List of all field names and values from the input source */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|DT_FIELD
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_FieldList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of all compiled tables and subtables */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|DT_SUBTABLE
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_RootTable
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stack for subtables */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|DT_SUBTABLE
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_SubtableStack
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List for defined labels */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|DT_FIELD
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_LabelList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current offset within the binary output table */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|UINT32
name|DT_INIT_GLOBAL
argument_list|(
name|Gbl_CurrentTableOffset
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local caches */
end_comment

begin_decl_stmt
name|DT_EXTERN
name|UINT32
name|DT_INIT_GLOBAL
argument_list|(
name|Gbl_SubtableCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|ASL_CACHE_INFO
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_SubtableCacheList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|DT_SUBTABLE
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_SubtableCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|DT_SUBTABLE
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_SubtableCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|UINT32
name|DT_INIT_GLOBAL
argument_list|(
name|Gbl_FieldCount
argument_list|,
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|ASL_CACHE_INFO
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_FieldCacheList
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|DT_FIELD
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_FieldCacheNext
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DT_EXTERN
name|DT_FIELD
name|DT_INIT_GLOBAL
argument_list|(
operator|*
name|Gbl_FieldCacheLast
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dtcompiler - main module */
end_comment

begin_function_decl
name|ACPI_STATUS
name|DtCompileTable
parameter_list|(
name|DT_FIELD
modifier|*
modifier|*
name|Field
parameter_list|,
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|,
name|DT_SUBTABLE
modifier|*
modifier|*
name|RetSubtable
parameter_list|,
name|BOOLEAN
name|Required
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtio - binary and text input/output */
end_comment

begin_function_decl
name|UINT32
name|DtGetNextLine
parameter_list|(
name|FILE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_FIELD
modifier|*
name|DtScanFile
parameter_list|(
name|FILE
modifier|*
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtOutputBinary
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|RootTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtDumpSubtableList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtDumpFieldList
parameter_list|(
name|DT_FIELD
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtWriteFieldToListing
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|UINT32
name|Length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtWriteTableToListing
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtsubtable - compile subtables */
end_comment

begin_function_decl
name|void
name|DtCreateSubtable
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Length
parameter_list|,
name|DT_SUBTABLE
modifier|*
modifier|*
name|RetSubtable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|DtGetSubtableLength
parameter_list|(
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtSetSubtableLength
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|Subtable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtPushSubtable
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|Subtable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtPopSubtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_SUBTABLE
modifier|*
name|DtPeekSubtable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtInsertSubtable
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|ParentTable
parameter_list|,
name|DT_SUBTABLE
modifier|*
name|Subtable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_SUBTABLE
modifier|*
name|DtGetNextSubtable
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|ParentTable
parameter_list|,
name|DT_SUBTABLE
modifier|*
name|ChildTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_SUBTABLE
modifier|*
name|DtGetParentSubtable
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|Subtable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtexpress - Integer expressions and labels */
end_comment

begin_function_decl
name|ACPI_STATUS
name|DtResolveIntegerExpression
parameter_list|(
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|UINT64
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|DtDoOperator
parameter_list|(
name|UINT64
name|LeftValue
parameter_list|,
name|UINT32
name|Operator
parameter_list|,
name|UINT64
name|RightValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT64
name|DtResolveLabel
parameter_list|(
name|char
modifier|*
name|LabelString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtDetectAllLabels
parameter_list|(
name|DT_FIELD
modifier|*
name|FieldList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtfield - Compile individual fields within a table */
end_comment

begin_function_decl
name|void
name|DtCompileOneField
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|,
name|UINT8
name|Type
parameter_list|,
name|UINT8
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtCompileInteger
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|,
name|UINT8
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|DtCompileBuffer
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|char
modifier|*
name|Value
parameter_list|,
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|UINT32
name|ByteLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtCompileFlag
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtparser - lex/yacc files */
end_comment

begin_function_decl
name|UINT64
name|DtEvaluateExpression
parameter_list|(
name|char
modifier|*
name|ExprString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|DtInitLexer
parameter_list|(
name|char
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtTerminateLexer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|DtGetOpName
parameter_list|(
name|UINT32
name|ParseOpcode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dtutils - Miscellaneous utilities */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|DT_WALK_CALLBACK
function_decl|)
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|Subtable
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|DtWalkTableTree
parameter_list|(
name|DT_SUBTABLE
modifier|*
name|StartTable
parameter_list|,
name|DT_WALK_CALLBACK
name|UserFunction
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtError
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|DT_FIELD
modifier|*
name|FieldObject
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtNameError
parameter_list|(
name|UINT8
name|Level
parameter_list|,
name|UINT16
name|MessageId
parameter_list|,
name|DT_FIELD
modifier|*
name|FieldObject
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtFatal
parameter_list|(
name|UINT16
name|MessageId
parameter_list|,
name|DT_FIELD
modifier|*
name|FieldObject
parameter_list|,
name|char
modifier|*
name|ExtraMessage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtStrtoul64
parameter_list|(
name|char
modifier|*
name|String
parameter_list|,
name|UINT64
modifier|*
name|ReturnInteger
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|DtGetFieldValue
parameter_list|(
name|DT_FIELD
modifier|*
name|Field
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT8
name|DtGetFieldType
parameter_list|(
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|DtGetBufferLength
parameter_list|(
name|char
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|DtGetFieldLength
parameter_list|(
name|DT_FIELD
modifier|*
name|Field
parameter_list|,
name|ACPI_DMTABLE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtSetTableChecksum
parameter_list|(
name|UINT8
modifier|*
name|ChecksumPointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtSetTableLength
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_SUBTABLE
modifier|*
name|UtSubtableCacheCalloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|DT_FIELD
modifier|*
name|UtFieldCacheCalloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DtDeleteCaches
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dttable - individual table compilation */
end_comment

begin_function_decl
name|ACPI_STATUS
name|DtCompileFacs
parameter_list|(
name|DT_FIELD
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileRsdp
parameter_list|(
name|DT_FIELD
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileAsf
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileCpep
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileCsrt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileDbg2
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileDmar
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileEinj
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileErst
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileFadt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileFpdt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileGtdt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileHest
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileIvrs
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileLpit
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileMadt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileMcfg
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileMpst
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileMsct
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileMtmr
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompilePmtt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompilePcct
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileRsdt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileS3pt
parameter_list|(
name|DT_FIELD
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileSlic
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileSlit
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileSrat
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileUefi
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileVrtc
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileWdat
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileXsdt
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|DtCompileGeneric
parameter_list|(
name|void
modifier|*
modifier|*
name|PFieldList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_DMTABLE_INFO
modifier|*
name|DtGetGenericTableInfo
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ACPI Table templates */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateAsf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateBoot
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateBert
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateBgrt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateCpep
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateCsrt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateDbg2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateDbgp
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateDmar
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateEcdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateEinj
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateErst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateFadt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateFpdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateGtdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateHest
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateHpet
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateIvrs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateLpit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMadt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMcfg
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMchi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMpst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMsct
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateMtmr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplatePcct
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplatePmtt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateRsdt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateS3pt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSbst
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSlic
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSlit
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSpcr
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSpmi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateSrat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateTcpa
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateTpm2
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateUefi
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateVrtc
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateWaet
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateWdat
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateWddt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateWdrt
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|char
name|TemplateXsdt
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

