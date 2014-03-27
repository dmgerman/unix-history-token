begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name: acpixf.h - External interfaces to the ACPI subsystem  *  *****************************************************************************/
end_comment

begin_comment
comment|/*  * Copyright (C) 2000 - 2014, Intel Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  * 3. Neither the names of the above-listed copyright holders nor the names  *    of any contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ACXFACE_H__
end_ifndef

begin_define
define|#
directive|define
name|__ACXFACE_H__
end_define

begin_comment
comment|/* Current ACPICA subsystem version in YYYYMMDD format */
end_comment

begin_define
define|#
directive|define
name|ACPI_CA_VERSION
value|0x20140325
end_define

begin_include
include|#
directive|include
file|"acconfig.h"
end_include

begin_include
include|#
directive|include
file|"actypes.h"
end_include

begin_include
include|#
directive|include
file|"actbl.h"
end_include

begin_include
include|#
directive|include
file|"acbuffer.h"
end_include

begin_comment
comment|/*  * Globals that are publically available  */
end_comment

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiCurrentGpeCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_TABLE_FADT
name|AcpiGbl_FADT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_SystemAwakeAndRunning
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOLEAN
name|AcpiGbl_ReducedHardware
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ACPI 5.0 */
end_comment

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_OsiData
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Runtime configuration of debug print levels */
end_comment

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiDbgLevel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiDbgLayer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ACPICA runtime options */
end_comment

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_AutoSerializeMethods
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_CopyDsdtLocally
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_CreateOsiMethod
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_DisableAutoRepair
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_DisableSsdtTableInstall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_DoNotUseXsdt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_EnableAmlDebugObject
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_EnableInterpreterSlack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT32
name|AcpiGbl_TraceFlags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ACPI_NAME
name|AcpiGbl_TraceMethodName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_TruncateIoAddresses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_Use32BitFadtAddresses
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|UINT8
name|AcpiGbl_UseDefaultRegisterWidths
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Hardware-reduced prototypes. All interfaces that use these macros will  * be configured out of the ACPICA build if the ACPI_REDUCED_HARDWARE flag  * is set to TRUE.  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|ACPI_REDUCED_HARDWARE
operator|)
end_if

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|Prototype;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_STATUS
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_NOT_CONFIGURED);}
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_OK
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return(AE_OK);}
end_define

begin_define
define|#
directive|define
name|ACPI_HW_DEPENDENT_RETURN_VOID
parameter_list|(
name|Prototype
parameter_list|)
define|\
value|static ACPI_INLINE Prototype {return;}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !ACPI_REDUCED_HARDWARE */
end_comment

begin_comment
comment|/*  * Initialization  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiInitializeTables
parameter_list|(
name|ACPI_TABLE_DESC
modifier|*
name|InitialStorage
parameter_list|,
name|UINT32
name|InitialTableCount
parameter_list|,
name|BOOLEAN
name|AllowResize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInitializeSubsystem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEnableSubsystem
parameter_list|(
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInitializeObjects
parameter_list|(
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiTerminate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Miscellaneous global interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnable (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisable (     void)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiSubsystemStatus
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetSystemInfo
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetStatistics
parameter_list|(
name|ACPI_STATISTICS
modifier|*
name|Stats
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|AcpiFormatException
parameter_list|(
name|ACPI_STATUS
name|Exception
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiPurgeCachedObjects
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallInterface
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRemoveInterface
parameter_list|(
name|ACPI_STRING
name|InterfaceName
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUpdateInterfaces
parameter_list|(
name|UINT8
name|Action
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|UINT32
name|AcpiCheckAddressRange
parameter_list|(
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|,
name|BOOLEAN
name|Warn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiDecodePldBuffer
parameter_list|(
name|UINT8
modifier|*
name|InBuffer
parameter_list|,
name|ACPI_SIZE
name|Length
parameter_list|,
name|ACPI_PLD_INFO
modifier|*
modifier|*
name|ReturnBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ACPI table load/unload interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallTable
parameter_list|(
name|ACPI_PHYSICAL_ADDRESS
name|Address
parameter_list|,
name|BOOLEAN
name|Physical
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiLoadTable
parameter_list|(
name|ACPI_TABLE_HEADER
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiUnloadParentTable
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiLoadTables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ACPI table manipulation interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiReallocateRootTable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiFindRootPointer
parameter_list|(
name|ACPI_SIZE
modifier|*
name|RsdpAddress
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTableHeader
parameter_list|(
name|ACPI_STRING
name|Signature
parameter_list|,
name|UINT32
name|Instance
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
name|OutTableHeader
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTable
parameter_list|(
name|ACPI_STRING
name|Signature
parameter_list|,
name|UINT32
name|Instance
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|OutTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetTableByIndex
parameter_list|(
name|UINT32
name|TableIndex
parameter_list|,
name|ACPI_TABLE_HEADER
modifier|*
modifier|*
name|OutTable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallTableHandler
parameter_list|(
name|ACPI_TABLE_HANDLER
name|Handler
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRemoveTableHandler
parameter_list|(
name|ACPI_TABLE_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Namespace and name interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiWalkNamespace
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
name|ACPI_STATUS
name|AcpiGetDevices
parameter_list|(
name|char
modifier|*
name|HID
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
name|ACPI_STATUS
name|AcpiGetName
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|UINT32
name|NameType
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetPathPtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetHandle
parameter_list|(
name|ACPI_HANDLE
name|Parent
parameter_list|,
name|ACPI_STRING
name|Pathname
parameter_list|,
name|ACPI_HANDLE
modifier|*
name|RetHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiAttachData
parameter_list|(
name|ACPI_HANDLE
name|Object
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
name|AcpiDetachData
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_OBJECT_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetData
parameter_list|(
name|ACPI_HANDLE
name|Object
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

begin_function_decl
name|ACPI_STATUS
name|AcpiDebugTrace
parameter_list|(
name|char
modifier|*
name|Name
parameter_list|,
name|UINT32
name|DebugLevel
parameter_list|,
name|UINT32
name|DebugLayer
parameter_list|,
name|UINT32
name|Flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Object manipulation and enumeration  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiEvaluateObject
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_STRING
name|Pathname
parameter_list|,
name|ACPI_OBJECT_LIST
modifier|*
name|ParameterObjects
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|ReturnObjectBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEvaluateObjectTyped
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_STRING
name|Pathname
parameter_list|,
name|ACPI_OBJECT_LIST
modifier|*
name|ExternalParams
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|ReturnBuffer
parameter_list|,
name|ACPI_OBJECT_TYPE
name|ReturnType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetObjectInfo
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_DEVICE_INFO
modifier|*
modifier|*
name|ReturnBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallMethod
parameter_list|(
name|UINT8
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetNextObject
parameter_list|(
name|ACPI_OBJECT_TYPE
name|Type
parameter_list|,
name|ACPI_HANDLE
name|Parent
parameter_list|,
name|ACPI_HANDLE
name|Child
parameter_list|,
name|ACPI_HANDLE
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetType
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_OBJECT_TYPE
modifier|*
name|OutType
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetParent
parameter_list|(
name|ACPI_HANDLE
name|Object
parameter_list|,
name|ACPI_HANDLE
modifier|*
name|OutHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Handler interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallInitializationHandler
parameter_list|(
name|ACPI_INIT_HANDLER
name|Handler
parameter_list|,
name|UINT32
name|Function
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallSciHandler (     ACPI_SCI_HANDLER        Address,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveSciHandler (     ACPI_SCI_HANDLER        Address)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGlobalEventHandler (     ACPI_GBL_EVENT_HANDLER  Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallFixedEventHandler (     UINT32                  AcpiEvent,     ACPI_EVENT_HANDLER      Handler,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveFixedEventHandler (     UINT32                  AcpiEvent,     ACPI_EVENT_HANDLER      Handler)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGpeHandler (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT32                  Type,     ACPI_GPE_HANDLER        Address,     void                    *Context)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveGpeHandler (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     ACPI_GPE_HANDLER        Address)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallNotifyHandler
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|UINT32
name|HandlerType
parameter_list|,
name|ACPI_NOTIFY_HANDLER
name|Handler
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRemoveNotifyHandler
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|UINT32
name|HandlerType
parameter_list|,
name|ACPI_NOTIFY_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallAddressSpaceHandler
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_ADR_SPACE_HANDLER
name|Handler
parameter_list|,
name|ACPI_ADR_SPACE_SETUP
name|Setup
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRemoveAddressSpaceHandler
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_ADR_SPACE_TYPE
name|SpaceId
parameter_list|,
name|ACPI_ADR_SPACE_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallExceptionHandler
parameter_list|(
name|ACPI_EXCEPTION_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiInstallInterfaceHandler
parameter_list|(
name|ACPI_INTERFACE_HANDLER
name|Handler
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Global Lock interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiAcquireGlobalLock (     UINT16                  Timeout,     UINT32                  *Handle)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReleaseGlobalLock (     UINT32                  Handle)
argument_list|)
end_macro

begin_comment
comment|/*  * Interfaces to AML mutex objects  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiAcquireMutex
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|ACPI_STRING
name|Pathname
parameter_list|,
name|UINT16
name|Timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiReleaseMutex
parameter_list|(
name|ACPI_HANDLE
name|Handle
parameter_list|,
name|ACPI_STRING
name|Pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fixed Event interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableEvent (     UINT32                  Event,     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableEvent (     UINT32                  Event,     UINT32                  Flags)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiClearEvent (     UINT32                  Event)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetEventStatus (     UINT32                  Event,     ACPI_EVENT_STATUS       *EventStatus)
argument_list|)
end_macro

begin_comment
comment|/*  * General Purpose Event (GPE) Interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiUpdateAllGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiClearGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT8                   Action)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiFinishGpe (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetupGpeForWake (     ACPI_HANDLE             ParentDevice,     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetGpeWakeMask (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     UINT8                   Action)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetGpeStatus (     ACPI_HANDLE             GpeDevice,     UINT32                  GpeNumber,     ACPI_EVENT_STATUS       *EventStatus)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiDisableAllGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnableAllRuntimeGpes (     void)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetGpeDevice (     UINT32                  GpeIndex,     ACPI_HANDLE             *GpeDevice)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiInstallGpeBlock (     ACPI_HANDLE             GpeDevice,     ACPI_GENERIC_ADDRESS    *GpeBlockAddress,     UINT32                  RegisterCount,     UINT32                  InterruptNumber)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiRemoveGpeBlock (     ACPI_HANDLE             GpeDevice)
argument_list|)
end_macro

begin_comment
comment|/*  * Resource interfaces  */
end_comment

begin_typedef
typedef|typedef
name|ACPI_STATUS
function_decl|(
modifier|*
name|ACPI_WALK_RESOURCE_CALLBACK
function_decl|)
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|ACPI_STATUS
name|AcpiGetVendorResource
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|,
name|ACPI_VENDOR_UUID
modifier|*
name|Uuid
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetCurrentResources
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetPossibleResources
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetEventResources
parameter_list|(
name|ACPI_HANDLE
name|DeviceHandle
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiWalkResourceBuffer
parameter_list|(
name|ACPI_BUFFER
modifier|*
name|Buffer
parameter_list|,
name|ACPI_WALK_RESOURCE_CALLBACK
name|UserFunction
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiWalkResources
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|char
modifier|*
name|Name
parameter_list|,
name|ACPI_WALK_RESOURCE_CALLBACK
name|UserFunction
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiSetCurrentResources
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|InBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiGetIrqRoutingTable
parameter_list|(
name|ACPI_HANDLE
name|Device
parameter_list|,
name|ACPI_BUFFER
modifier|*
name|RetBuffer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiResourceToAddress64
parameter_list|(
name|ACPI_RESOURCE
modifier|*
name|Resource
parameter_list|,
name|ACPI_RESOURCE_ADDRESS64
modifier|*
name|Out
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiBufferToResource
parameter_list|(
name|UINT8
modifier|*
name|AmlBuffer
parameter_list|,
name|UINT16
name|AmlBufferLength
parameter_list|,
name|ACPI_RESOURCE
modifier|*
modifier|*
name|ResourcePtr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Hardware (ACPI device) interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiReset
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiRead
parameter_list|(
name|UINT64
modifier|*
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiWrite
parameter_list|(
name|UINT64
name|Value
parameter_list|,
name|ACPI_GENERIC_ADDRESS
modifier|*
name|Reg
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiReadBitRegister (     UINT32                  RegisterId,     UINT32                  *ReturnValue)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiWriteBitRegister (     UINT32                  RegisterId,     UINT32                  Value)
argument_list|)
end_macro

begin_comment
comment|/*  * Sleep/Wake interfaces  */
end_comment

begin_function_decl
name|ACPI_STATUS
name|AcpiGetSleepTypeData
parameter_list|(
name|UINT8
name|SleepState
parameter_list|,
name|UINT8
modifier|*
name|Slp_TypA
parameter_list|,
name|UINT8
modifier|*
name|Slp_TypB
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEnterSleepStatePrep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiEnterSleepState
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiEnterSleepStateS4bios (     void)
argument_list|)
end_macro

begin_function_decl
name|ACPI_STATUS
name|AcpiLeaveSleepStatePrep
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ACPI_STATUS
name|AcpiLeaveSleepState
parameter_list|(
name|UINT8
name|SleepState
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetFirmwareWakingVector (     UINT32                  PhysicalAddress)
argument_list|)
end_macro

begin_if
if|#
directive|if
name|ACPI_MACHINE_WIDTH
operator|==
literal|64
end_if

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiSetFirmwareWakingVector64 (     UINT64                  PhysicalAddress)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ACPI Timer interfaces  */
end_comment

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimerResolution (     UINT32                  *Resolution)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimer (     UINT32                  *Ticks)
argument_list|)
end_macro

begin_macro
name|ACPI_HW_DEPENDENT_RETURN_STATUS
argument_list|(
argument|ACPI_STATUS AcpiGetTimerDuration (     UINT32                  StartTicks,     UINT32                  EndTicks,     UINT32                  *TimeElapsed)
argument_list|)
end_macro

begin_comment
comment|/*  * Error/Warning output  */
end_comment

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|3
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiError
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|4
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiException
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
name|ACPI_STATUS
name|Status
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|3
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|3
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|3
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiBiosError
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|3
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiBiosWarning
parameter_list|(
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Debug output  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ACPI_DEBUG_OUTPUT
end_ifdef

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|6
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiDebugPrint
parameter_list|(
name|UINT32
name|RequestedDebugLevel
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ACPI_PRINTF_LIKE
argument_list|(
literal|6
argument_list|)
end_macro

begin_function_decl
name|void
name|ACPI_INTERNAL_VAR_XFACE
name|AcpiDebugPrintRaw
parameter_list|(
name|UINT32
name|RequestedDebugLevel
parameter_list|,
name|UINT32
name|LineNumber
parameter_list|,
specifier|const
name|char
modifier|*
name|FunctionName
parameter_list|,
specifier|const
name|char
modifier|*
name|ModuleName
parameter_list|,
name|UINT32
name|ComponentId
parameter_list|,
specifier|const
name|char
modifier|*
name|Format
parameter_list|,
modifier|...
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
comment|/* __ACXFACE_H__ */
end_comment

end_unit

