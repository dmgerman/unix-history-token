begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: accommon.h -- prototypes for the common (subsystem-wide) procedures  *       $Revision: 90 $  *  *****************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  * 1. Copyright Notice  *  * Some or all of this work - Copyright (c) 1999, 2000, 2001, Intel Corp.  * All rights reserved.  *  * 2. License  *  * 2.1. This is your license from Intel Corp. under its intellectual property  * rights.  You may have additional license terms from the party that provided  * you this software, covering your right to use that party's intellectual  * property rights.  *  * 2.2. Intel grants, free of charge, to any person ("Licensee") obtaining a  * copy of the source code appearing in this file ("Covered Code") an  * irrevocable, perpetual, worldwide license under Intel's copyrights in the  * base code distributed originally by Intel ("Original Intel Code") to copy,  * make derivatives, distribute, use and display any portion of the Covered  * Code in any form, with the right to sublicense such rights; and  *  * 2.3. Intel grants Licensee a non-exclusive and non-transferable patent  * license (with the right to sublicense), under only those claims of Intel  * patents that are infringed by the Original Intel Code, to make, use, sell,  * offer to sell, and import the Covered Code and derivative works thereof  * solely to the minimum extent necessary to exercise the above copyright  * license, and in no event shall the patent license extend to any additions  * to or modifications of the Original Intel Code.  No other license or right  * is granted directly or by implication, estoppel or otherwise;  *  * The above copyright and patent license is granted only if the following  * conditions are met:  *  * 3. Conditions  *  * 3.1. Redistribution of Source with Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification with rights to further distribute source must include  * the above Copyright Notice, the above License, this list of Conditions,  * and the following Disclaimer and Export Compliance provision.  In addition,  * Licensee must cause all Covered Code to which Licensee contributes to  * contain a file documenting the changes Licensee made to create that Covered  * Code and the date of any change.  Licensee must include in that file the  * documentation of any changes made by any predecessor Licensee.  Licensee  * must include a prominent statement that the modification is derived,  * directly or indirectly, from Original Intel Code.  *  * 3.2. Redistribution of Source with no Rights to Further Distribute Source.  * Redistribution of source code of any substantial portion of the Covered  * Code or modification without rights to further distribute source must  * include the following Disclaimer and Export Compliance provision in the  * documentation and/or other materials provided with distribution.  In  * addition, Licensee may not authorize further sublicense of source of any  * portion of the Covered Code, and must include terms to the effect that the  * license from Licensee to its licensee is limited to the intellectual  * property embodied in the software Licensee provides to its licensee, and  * not to intellectual property embodied in modifications its licensee may  * make.  *  * 3.3. Redistribution of Executable. Redistribution in executable form of any  * substantial portion of the Covered Code or modification must reproduce the  * above Copyright Notice, and the following Disclaimer and Export Compliance  * provision in the documentation and/or other materials provided with the  * distribution.  *  * 3.4. Intel retains all right, title, and interest in and to the Original  * Intel Code.  *  * 3.5. Neither the name Intel nor any other trademark owned or controlled by  * Intel shall be used in advertising or otherwise to promote the sale, use or  * other dealings in products derived from or relating to the Covered Code  * without prior written authorization from Intel.  *  * 4. Disclaimer and Export Compliance  *  * 4.1. INTEL MAKES NO WARRANTY OF ANY KIND REGARDING ANY SOFTWARE PROVIDED  * HERE.  ANY SOFTWARE ORIGINATING FROM INTEL OR DERIVED FROM INTEL SOFTWARE  * IS PROVIDED "AS IS," AND INTEL WILL NOT PROVIDE ANY SUPPORT,  ASSISTANCE,  * INSTALLATION, TRAINING OR OTHER SERVICES.  INTEL WILL NOT PROVIDE ANY  * UPDATES, ENHANCEMENTS OR EXTENSIONS.  INTEL SPECIFICALLY DISCLAIMS ANY  * IMPLIED WARRANTIES OF MERCHANTABILITY, NONINFRINGEMENT AND FITNESS FOR A  * PARTICULAR PURPOSE.  *  * 4.2. IN NO EVENT SHALL INTEL HAVE ANY LIABILITY TO LICENSEE, ITS LICENSEES  * OR ANY OTHER THIRD PARTY, FOR ANY LOST PROFITS, LOST DATA, LOSS OF USE OR  * COSTS OF PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, OR FOR ANY INDIRECT,  * SPECIAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THIS AGREEMENT, UNDER ANY  * CAUSE OF ACTION OR THEORY OF LIABILITY, AND IRRESPECTIVE OF WHETHER INTEL  * HAS ADVANCE NOTICE OF THE POSSIBILITY OF SUCH DAMAGES.  THESE LIMITATIONS  * SHALL APPLY NOTWITHSTANDING THE FAILURE OF THE ESSENTIAL PURPOSE OF ANY  * LIMITED REMEDY.  *  * 4.3. Licensee shall not export, either directly or indirectly, any of this  * software or system incorporating such software without first obtaining any  * required license or other approval from the U. S. Department of Commerce or  * any other agency or department of the United States Government.  In the  * event Licensee exports any such software from the United States or  * re-exports any such software from a foreign destination, Licensee shall  * ensure that the distribution and export/re-export of the software is in  * compliance with all laws, regulations, orders, or other restrictions of the  * U.S. Export Administration Regulations. Licensee agrees that neither it nor  * any of its subsidiaries will export/re-export any technical data, process,  * software, or service, directly or indirectly, to any country for which the  * United States government or any agency thereof requires an export license,  * other governmental approval, or letter of assurance, without first obtaining  * such license, approval or letter.  *  *****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_ACCOMMON_H
end_define

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_PKG_CALLBACK
function_decl|)
parameter_list|(
name|UINT8
name|ObjectType
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObject
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|ACPI_STATUS
name|AcpiCmWalkPackageTree
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObject
parameter_list|,
name|void
modifier|*
name|TargetObject
parameter_list|,
name|ACPI_PKG_CALLBACK
name|WalkCallback
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|acpi_pkg_info
block|{
name|UINT8
modifier|*
name|FreeSpace
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
name|UINT32
name|ObjectSpace
decl_stmt|;
name|UINT32
name|NumPackages
decl_stmt|;
block|}
name|ACPI_PKG_INFO
typedef|;
end_typedef

begin_define
define|#
directive|define
name|REF_INCREMENT
value|(UINT16) 0
end_define

begin_define
define|#
directive|define
name|REF_DECREMENT
value|(UINT16) 1
end_define

begin_define
define|#
directive|define
name|REF_FORCE_DELETE
value|(UINT16) 2
end_define

begin_comment
comment|/* AcpiCmDumpBuffer */
end_comment

begin_define
define|#
directive|define
name|DB_BYTE_DISPLAY
value|1
end_define

begin_define
define|#
directive|define
name|DB_WORD_DISPLAY
value|2
end_define

begin_define
define|#
directive|define
name|DB_DWORD_DISPLAY
value|4
end_define

begin_define
define|#
directive|define
name|DB_QWORD_DISPLAY
value|8
end_define

begin_comment
comment|/* Global initialization interfaces */
end_comment

begin_function_decl
name|void
name|AcpiCmInitGlobals
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmInit - miscellaneous initialization and shutdown  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiCmHardwareInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmSubsystemShutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmValidateFadt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmGlobal - Global data structures and procedures  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmGetMutexName
parameter_list|(
name|UINT32
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmGetTypeName
parameter_list|(
name|UINT32
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmGetRegionName
parameter_list|(
name|UINT8
name|SpaceId
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|BOOLEAN
name|AcpiCmValidObjectType
parameter_list|(
name|UINT32
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OWNER_ID
name|AcpiCmAllocateOwnerId
parameter_list|(
name|UINT32
name|IdType
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmClib - Local implementations of C library functions  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_USE_SYSTEM_CLIBRARY
end_ifndef

begin_function_decl
name|NATIVE_UINT
name|AcpiCmStrlen
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrcpy
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|DstString
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrncpy
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|DstString
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|SrcString
parameter_list|,
name|NATIVE_UINT
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCmStrncmp
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|String1
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|String2
parameter_list|,
name|NATIVE_UINT
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCmStrcmp
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|String1
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|String2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrcat
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|DstString
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrncat
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|DstString
parameter_list|,
specifier|const
name|NATIVE_CHAR
modifier|*
name|SrcString
parameter_list|,
name|NATIVE_UINT
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCmStrtoul
parameter_list|(
specifier|const
name|NATIVE_CHAR
modifier|*
name|String
parameter_list|,
name|NATIVE_CHAR
modifier|*
modifier|*
name|Terminator
parameter_list|,
name|NATIVE_UINT
name|Base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrstr
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|String1
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|String2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmStrupr
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|SrcString
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AcpiCmMemcpy
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
specifier|const
name|void
modifier|*
name|Src
parameter_list|,
name|NATIVE_UINT
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|AcpiCmMemset
parameter_list|(
name|void
modifier|*
name|Dest
parameter_list|,
name|NATIVE_UINT
name|Value
parameter_list|,
name|NATIVE_UINT
name|Count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCmToUpper
parameter_list|(
name|UINT32
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCmToLower
parameter_list|(
name|UINT32
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ACPI_USE_SYSTEM_CLIBRARY */
end_comment

begin_comment
comment|/*  * CmCopy - Object construction and conversion interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiCmBuildSimpleObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_OBJECT
modifier|*
name|UserObj
parameter_list|,
name|UINT8
modifier|*
name|DataSpace
parameter_list|,
name|UINT32
modifier|*
name|BufferSpaceUsed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmBuildPackageObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
modifier|*
name|SpaceUsed
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCopyIobjectToEobject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCopyEsimpleToIsimple
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|UserObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCopyEobjectToIobject
parameter_list|(
name|ACPI_OBJECT
modifier|*
name|Obj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|InternalObj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCopyISimpleToIsimple
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|DestObj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCopyIpackageToIpackage
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|SourceObj
parameter_list|,
name|ACPI_OPERAND_OBJECT
modifier|*
name|DestObj
parameter_list|,
name|ACPI_WALK_STATE
modifier|*
name|WalkState
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmCreate - Object creation  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiCmUpdateObjectReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_OPERAND_OBJECT
modifier|*
name|_CmCreateInternalObject
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|OBJECT_TYPE_INTERNAL
name|Type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmDebug - Debug interfaces  */
end_comment

begin_function_decl
name|UINT32
name|GetDebugLevel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDebugLevel
parameter_list|(
name|UINT32
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionTrace
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionTracePtr
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|void
modifier|*
name|Pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionTraceU32
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|UINT32
name|Integer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionTraceStr
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionExit
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionStatusExit
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionValueExit
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|ACPI_INTEGER
name|Value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FunctionPtrExit
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|FunctionName
parameter_list|,
name|UINT8
modifier|*
name|Ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DebugPrintPrefix
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DebugPrint
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
name|UINT32
name|PrintLevel
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DebugPrintRaw
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_ReportInfo
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_ReportError
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_ReportWarning
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDumpBuffer
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|,
name|UINT32
name|Count
parameter_list|,
name|UINT32
name|Display
parameter_list|,
name|UINT32
name|componentId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmDelete - Object deletion  */
end_comment

begin_function_decl
name|void
name|AcpiCmDeleteInternalObj
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDeleteInternalPackageObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDeleteInternalSimpleObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmDeleteInternalObjectList
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
modifier|*
name|ObjList
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmEval - object evaluation  */
end_comment

begin_comment
comment|/* Method name strings */
end_comment

begin_define
define|#
directive|define
name|METHOD_NAME__HID
value|"_HID"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__UID
value|"_UID"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__ADR
value|"_ADR"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__STA
value|"_STA"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__REG
value|"_REG"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__SEG
value|"_SEG"
end_define

begin_define
define|#
directive|define
name|METHOD_NAME__BBN
value|"_BBN"
end_define

begin_function_decl
name|ACPI_STATUS
name|AcpiCmEvaluateNumericObject
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ObjectName
parameter_list|,
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|ACPI_INTEGER
modifier|*
name|Address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmExecute_HID
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|DEVICE_ID
modifier|*
name|Hid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmExecute_STA
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|UINT32
modifier|*
name|StatusFlags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmExecute_UID
parameter_list|(
name|ACPI_NAMESPACE_NODE
modifier|*
name|DeviceNode
parameter_list|,
name|DEVICE_ID
modifier|*
name|Uid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmError - exception interfaces  */
end_comment

begin_function_decl
name|NATIVE_CHAR
modifier|*
name|AcpiCmFormatException
parameter_list|(
name|ACPI_STATUS
name|Status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmMutex - mutual exclusion interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiCmMutexInitialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmMutexTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCreateMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmDeleteMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmAcquireMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmReleaseMutex
parameter_list|(
name|ACPI_MUTEX_HANDLE
name|MutexId
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmObject - internal object create/delete/cache routines  */
end_comment

begin_function_decl
name|void
modifier|*
name|_CmAllocateObjectDesc
parameter_list|(
name|NATIVE_CHAR
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AcpiCmCreateInternalObject
parameter_list|(
name|t
parameter_list|)
value|_CmCreateInternalObject(_THIS_MODULE,__LINE__,_COMPONENT,t)
end_define

begin_define
define|#
directive|define
name|AcpiCmAllocateObjectDesc
parameter_list|()
value|_CmAllocateObjectDesc(_THIS_MODULE,__LINE__,_COMPONENT)
end_define

begin_function_decl
name|void
name|AcpiCmDeleteObjectDesc
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiCmValidInternalObject
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmRefCnt - Object reference count management  */
end_comment

begin_function_decl
name|void
name|AcpiCmAddReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmRemoveReference
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmSize - Object size routines  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiCmGetSimpleObjectSize
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|UINT32
modifier|*
name|ObjLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmGetPackageObjectSize
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|UINT32
modifier|*
name|ObjLength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmGetObjectSize
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Obj
parameter_list|,
name|UINT32
modifier|*
name|ObjLength
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * CmState - Generic state creation/cache routines  */
end_comment

begin_function_decl
name|void
name|AcpiCmPushGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|ListHead
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiCmPopGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|ListHead
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiCmCreateGenericState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiCmCreateUpdateState
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiCmCreatePkgState
parameter_list|(
name|void
modifier|*
name|InternalObject
parameter_list|,
name|void
modifier|*
name|ExternalObject
parameter_list|,
name|UINT16
name|Index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCreateUpdateStateAndPush
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|Object
parameter_list|,
name|UINT16
name|Action
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|StateList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmCreatePkgStateAndPush
parameter_list|(
name|void
modifier|*
name|InternalObject
parameter_list|,
name|void
modifier|*
name|ExternalObject
parameter_list|,
name|UINT16
name|Index
parameter_list|,
name|ACPI_GENERIC_STATE
modifier|*
modifier|*
name|StateList
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_GENERIC_STATE
modifier|*
name|AcpiCmCreateControlState
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDeleteGenericState
parameter_list|(
name|ACPI_GENERIC_STATE
modifier|*
name|State
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDeleteGenericStateCache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmDeleteObjectCache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Cmutils  */
end_comment

begin_function_decl
name|BOOLEAN
name|AcpiCmValidAcpiName
parameter_list|(
name|UINT32
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|BOOLEAN
name|AcpiCmValidAcpiCharacter
parameter_list|(
name|NATIVE_CHAR
name|Character
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiCmResolvePackageReferences
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG
end_ifdef

begin_function_decl
name|void
name|AcpiCmDisplayInitPathname
parameter_list|(
name|ACPI_HANDLE
name|ObjHandle
parameter_list|,
name|char
modifier|*
name|Path
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Memory allocation functions and related macros.  * Macros that expand to include filename and line number  */
end_comment

begin_function_decl
name|void
modifier|*
name|_CmAllocate
parameter_list|(
name|UINT32
name|Size
parameter_list|,
name|UINT32
name|Component
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|_CmCallocate
parameter_list|(
name|UINT32
name|Size
parameter_list|,
name|UINT32
name|Component
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_CmFree
parameter_list|(
name|void
modifier|*
name|Address
parameter_list|,
name|UINT32
name|Component
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Module
parameter_list|,
name|UINT32
name|Line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AcpiCmInitStaticObject
parameter_list|(
name|ACPI_OPERAND_OBJECT
modifier|*
name|ObjDesc
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AcpiCmAllocate
parameter_list|(
name|a
parameter_list|)
value|_CmAllocate(a,_COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|AcpiCmCallocate
parameter_list|(
name|a
parameter_list|)
value|_CmCallocate(a, _COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_define
define|#
directive|define
name|AcpiCmFree
parameter_list|(
name|a
parameter_list|)
value|_CmFree(a,_COMPONENT,_THIS_MODULE,__LINE__)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ACPI_DEBUG_TRACK_ALLOCATIONS
end_ifndef

begin_define
define|#
directive|define
name|AcpiCmAddElementToAllocList
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AcpiCmDeleteElementFromAllocList
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AcpiCmDumpCurrentAllocations
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
end_define

begin_define
define|#
directive|define
name|AcpiCmDumpAllocationInfo
parameter_list|()
end_define

begin_define
define|#
directive|define
name|DECREMENT_OBJECT_METRICS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INCREMENT_OBJECT_METRICS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INITIALIZE_ALLOCATION_METRICS
parameter_list|()
end_define

begin_define
define|#
directive|define
name|DECREMENT_NAME_TABLE_METRICS
parameter_list|(
name|a
parameter_list|)
end_define

begin_define
define|#
directive|define
name|INCREMENT_NAME_TABLE_METRICS
parameter_list|(
name|a
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INITIALIZE_ALLOCATION_METRICS
parameter_list|()
define|\
value|AcpiGbl_CurrentObjectCount = 0; \     AcpiGbl_CurrentObjectSize = 0; \     AcpiGbl_RunningObjectCount = 0; \     AcpiGbl_RunningObjectSize = 0; \     AcpiGbl_MaxConcurrentObjectCount = 0; \     AcpiGbl_MaxConcurrentObjectSize = 0; \     AcpiGbl_CurrentAllocSize = 0; \     AcpiGbl_CurrentAllocCount = 0; \     AcpiGbl_RunningAllocSize = 0; \     AcpiGbl_RunningAllocCount = 0; \     AcpiGbl_MaxConcurrentAllocSize = 0; \     AcpiGbl_MaxConcurrentAllocCount = 0; \     AcpiGbl_CurrentNodeCount = 0; \     AcpiGbl_CurrentNodeSize = 0; \     AcpiGbl_MaxConcurrentNodeCount = 0
end_define

begin_define
define|#
directive|define
name|DECREMENT_OBJECT_METRICS
parameter_list|(
name|a
parameter_list|)
define|\
value|AcpiGbl_CurrentObjectCount--; \     AcpiGbl_CurrentObjectSize -= a
end_define

begin_define
define|#
directive|define
name|INCREMENT_OBJECT_METRICS
parameter_list|(
name|a
parameter_list|)
define|\
value|AcpiGbl_CurrentObjectCount++; \     AcpiGbl_RunningObjectCount++; \     if (AcpiGbl_MaxConcurrentObjectCount< AcpiGbl_CurrentObjectCount) \     { \         AcpiGbl_MaxConcurrentObjectCount = AcpiGbl_CurrentObjectCount; \     } \     AcpiGbl_RunningObjectSize += a; \     AcpiGbl_CurrentObjectSize += a; \     if (AcpiGbl_MaxConcurrentObjectSize< AcpiGbl_CurrentObjectSize) \     { \         AcpiGbl_MaxConcurrentObjectSize = AcpiGbl_CurrentObjectSize; \     }
end_define

begin_define
define|#
directive|define
name|DECREMENT_NAME_TABLE_METRICS
parameter_list|(
name|a
parameter_list|)
define|\
value|AcpiGbl_CurrentNodeCount--; \     AcpiGbl_CurrentNodeSize -= (a)
end_define

begin_define
define|#
directive|define
name|INCREMENT_NAME_TABLE_METRICS
parameter_list|(
name|a
parameter_list|)
define|\
value|AcpiGbl_CurrentNodeCount++; \     AcpiGbl_CurrentNodeSize+= (a); \     if (AcpiGbl_MaxConcurrentNodeCount< AcpiGbl_CurrentNodeCount) \     { \         AcpiGbl_MaxConcurrentNodeCount = AcpiGbl_CurrentNodeCount; \     } \   void
end_define

begin_expr_stmt
name|AcpiCmDumpAllocationInfo
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|AcpiCmDumpCurrentAllocations
parameter_list|(
name|UINT32
name|Component
parameter_list|,
name|NATIVE_CHAR
modifier|*
name|Module
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACCOMMON_H */
end_comment

end_unit

