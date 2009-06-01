begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acnamesp.h - Namespace subcomponent prototypes and defines  *       $Revision: 1.152 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999 - 2007, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
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
name|ACPI_NATIVE_UINT
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
name|UserFunction
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
name|ACPI_NATIVE_UINT
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
name|ACPI_NATIVE_UINT
name|PassNumber
parameter_list|,
name|ACPI_NATIVE_UINT
name|TableIndex
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
name|void
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
name|BOOLEAN
name|AcpiNsValidRootPrefix
parameter_list|(
name|char
name|Prefix
parameter_list|)
function_decl|;
end_function_decl

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
name|AcpiNsReportError
parameter_list|(
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|char
modifier|*
name|InternalName
parameter_list|,
name|ACPI_STATUS
name|LookupStatus
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiNsReportMethodError
parameter_list|(
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|char
modifier|*
name|Message
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|,
name|char
modifier|*
name|Path
parameter_list|,
name|ACPI_STATUS
name|LookupStatus
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
name|AcpiNsMapHandleToNode
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_HANDLE
name|AcpiNsConvertEntryToHandle
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
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

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsGetParentNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_NAMESPACE_NODE
modifier|*
name|AcpiNsGetNextValidNode
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|Node
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

