begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acnamesp.h - Namespace subcomponent prototypes and defines  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACNAMESP_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACNAMESP_H__
end_define

begin_comment
comment|/* To search the entire name space, pass this as SearchBase */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_ALL
value|((ACPI_HANDLE)0)
end_define

begin_comment
comment|/*  * Elements of AcpiNsProperties are bit significant  * and should be one-to-one with values of ACPI_OBJECT_TYPE  */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_NS_NEWSCOPE
value|1
end_define

begin_comment
comment|/* a definition of this type opens a name scope */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_LOCAL
value|2
end_define

begin_comment
comment|/* suppress search of enclosing scopes */
end_comment

begin_comment
comment|/* Flags for AcpiNsLookup, AcpiNsSearchAndEnter */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_NO_UPSEARCH
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_NS_SEARCH_PARENT
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NS_DONT_OPEN_SCOPE
value|0x02
end_define

begin_define
define|#
directive|define
name|ACPI_NS_NO_PEER_SEARCH
value|0x04
end_define

begin_define
define|#
directive|define
name|ACPI_NS_ERROR_IF_FOUND
value|0x08
end_define

begin_define
define|#
directive|define
name|ACPI_NS_PREFIX_IS_SCOPE
value|0x10
end_define

begin_define
define|#
directive|define
name|ACPI_NS_EXTERNAL
value|0x20
end_define

begin_define
define|#
directive|define
name|ACPI_NS_TEMPORARY
value|0x40
end_define

begin_comment
comment|/* Flags for AcpiNsWalkNamespace */
end_comment

begin_define
define|#
directive|define
name|ACPI_NS_WALK_NO_UNLOCK
value|0
end_define

begin_define
define|#
directive|define
name|ACPI_NS_WALK_UNLOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|ACPI_NS_WALK_TEMP_NODES
value|0x02
end_define

begin_comment
comment|/* Object is not a package element */
end_comment

begin_define
define|#
directive|define
name|ACPI_NOT_PACKAGE_ELEMENT
value|ACPI_UINT32_MAX
end_define

begin_comment
comment|/* Always emit warning message, not dependent on node flags */
end_comment

begin_define
define|#
directive|define
name|ACPI_WARN_ALWAYS
value|0
end_define

begin_comment
comment|/*  * nsinit - Namespace initialization  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsInitializeObjects
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsInitializeDevices
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsload -  Namespace loading  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsLoadNamespace
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsLoadTable
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nswalk - walk the namespace  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsWalkNamespace
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|ACPI_HANDLE
name|StartObject
parameter_list|,
name|UINT32
name|MaxDepth
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|ACPI_WALK_CALLBACK
name|DescendingCallback
parameter_list|,
name|ACPI_WALK_CALLBACK
name|AscendingCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsGetNextNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Parent
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsGetNextNodeTyped
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Parent
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Child
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsparse - table parsing  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsParseTable
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|StartNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsOneCompleteParse
parameter_list|(
name|UINT32
name|PassNumber
parameter_list|,
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|StartNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsaccess - Top-level namespace access  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsRootInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsLookup
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
name|ScopeInfo
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|ACPI_INTERPRETER_MODE
name|InterpreterMode
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|RetNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsalloc - Named object allocation/deallocation  */
end_comment

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsCreateNode
parameter_list|(
name|UINT32
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDeleteNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsRemoveNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDeleteNamespaceSubtree
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|ParentHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDeleteNamespaceByOwner
parameter_list|(
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDetachObject
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDeleteChildren
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Parent
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AcpiNsCompareNames
parameter_list|(
name|char
modifier|*
name|Name1
parameter_list|,
name|char
modifier|*
name|Name2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsconvert - Dynamic object conversion routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsConvertToInteger
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsConvertToString
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsConvertToBuffer
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsConvertToUnicode
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsConvertToResource
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsdump - Namespace dump/print utilities  */
end_comment

begin_function_decl
name|void
name|AcpiNsDumpTables
parameter_list|(
name|ACPI_HANDLE
name|SearchBase
parameter_list|,
name|UINT32
name|MaxDepth
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDumpEntry
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|UINT32
name|DebugLevel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDumpPathname
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|char
modifier|*
name|Msg
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|UINT32
name|Component
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsPrintPathname
parameter_list|(
name|UINT32
name|NumSegments
parameter_list|,
name|char
modifier|*
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsDumpOneObject
parameter_list|(
name|ACPI_HANDLE
name|ObjHandle
parameter_list|,
name|UINT32
name|Level
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|,
name|void
modifier|*
modifier|*
name|ReturnValue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDumpObjects
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|UINT8
name|DisplayType
parameter_list|,
name|UINT32
name|MaxDepth
parameter_list|,
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|,
name|ACPI_HANDLE
name|StartHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsDumpObjectPaths
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|UINT8
name|DisplayType
parameter_list|,
name|UINT32
name|MaxDepth
parameter_list|,
name|ACPI_OWNER_ID
name|OwnerId
parameter_list|,
name|ACPI_HANDLE
name|StartHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nseval - Namespace evaluation functions  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsEvaluate
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsExecModuleCodeList
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsarguments - Argument count/type checking for predefined/reserved names  */
end_comment

begin_function_decl
name|void
name|AcpiNsCheckArgumentCount
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|UINT32
name|UserParamCount
parameter_list|,
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsCheckAcpiCompliance
parameter_list|(
name|char
modifier|*
name|Pathname
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
specifier|const
name|ACPI_PREDEFINED_INFO
modifier|*
name|Predefined
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsCheckArgumentTypes
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nspredef - Return value checking for predefined/reserved names  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsCheckReturnValue
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|UINT32
name|UserParamCount
parameter_list|,
name|ACPI_STATUS
name|ReturnStatus
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsCheckObjectType
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObjectPtr
parameter_list|,
name|UINT32
name|ExpectedBtypes
parameter_list|,
name|UINT32
name|PackageIndex
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsprepkg - Validation of predefined name packages  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsCheckPackage
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObjectPtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsnames - Name and Scope manipulation  */
end_comment

begin_function_decl
name|UINT32
name|AcpiNsOpensScope
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsBuildExternalPath
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_SIZE
name|Size
parameter_list|,
name|char
modifier|*
name|NameBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiNsGetExternalPathname
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|AcpiNsNameOfCurrentScope
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsHandleToPathname
parameter_list|(
name|ACPI_HANDLE
name|TargetHandle
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiNsPatternMatch
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|ObjNode
parameter_list|,
name|char
modifier|*
name|SearchFor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsGetNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|PrefixNode
parameter_list|,
specifier|const
name|char
modifier|*
name|ExternalPathname
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|OutNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_SIZE
name|AcpiNsGetPathnameLength
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsobject - Object management for namespace nodes  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsAttachObject
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiNsGetAttachedObject
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|AcpiNsGetSecondaryObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsAttachData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OBJECT_HANDLER
name|Handler
parameter_list|,
name|void
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsDetachData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OBJECT_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsGetAttachedData
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OBJECT_HANDLER
name|Handler
parameter_list|,
name|void
modifier|*
modifier|*
name|Data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsrepair - General return object repair for all  * predefined methods/objects  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsSimpleRepair
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|UINT32
name|ExpectedBtypes
parameter_list|,
name|UINT32
name|PackageIndex
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObjectPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsWrapWithPackage
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|OriginalObject
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ObjDescPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsRepairNullElement
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|UINT32
name|ExpectedBtypes
parameter_list|,
name|UINT32
name|PackageIndex
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObjectPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsRemoveNullElements
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|UINT8
name|PackageType
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsrepair2 - Return object repair for specific  * predefined methods/objects  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsComplexRepairs
parameter_list|(
name|ACPI_EVALUATE_INFO
modifier|*
name|Info
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_STATUS
name|ValidateStatus
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ReturnObjectPtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nssearch - Namespace searching and entry  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiNsSearchAndEnter
parameter_list|(
name|UINT32
name|EntryName
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_INTERPRETER_MODE
name|InterpreterMode
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|UINT32
name|Flags
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|RetNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsSearchOneScope
parameter_list|(
name|UINT32
name|EntryName
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
modifier|*
name|RetNode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsInstallNode
parameter_list|(
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|ParentNode
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * nsutils - Utility functions  */
end_comment

begin_function_decl
name|ACPI_OBJECT_TYPE
name|AcpiNsGetType
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiNsLocal
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsPrintNodePathname
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsBuildInternalName
parameter_list|(
name|ACPI_NAMESTRING_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsGetInternalNameLength
parameter_list|(
name|ACPI_NAMESTRING_INFO
modifier|*
name|Info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsInternalizeName
parameter_list|(
specifier|const
name|char
modifier|*
name|DottedName
parameter_list|,
name|char
modifier|*
modifier|*
name|ConvertedName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiNsExternalizeName
parameter_list|(
name|UINT32
name|InternalNameLength
parameter_list|,
specifier|const
name|char
modifier|*
name|InternalName
parameter_list|,
name|UINT32
modifier|*
name|ConvertedNameLength
parameter_list|,
name|char
modifier|*
modifier|*
name|ConvertedName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsValidateHandle
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ACNAMESP_H__ */
end_comment

end_unit

