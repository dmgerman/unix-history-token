begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_API_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_API_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efiapi.h  Abstract:      Global EFI runtime& boot service interfaces     Revision History  --*/
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Specification Revision
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SPECIFICATION_MAJOR_REVISION
value|1
end_define

begin_define
define|#
directive|define
name|EFI_SPECIFICATION_MINOR_REVISION
value|02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Declare forward referenced data structures
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|INTERFACE_DECL
argument_list|(
name|_EFI_SYSTEM_TABLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Memory
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ALLOCATE_PAGES
function_decl|)
parameter_list|(
name|IN
name|EFI_ALLOCATE_TYPE
name|Type
parameter_list|,
name|IN
name|EFI_MEMORY_TYPE
name|MemoryType
parameter_list|,
name|IN
name|UINTN
name|NoPages
parameter_list|,
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|Memory
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FREE_PAGES
function_decl|)
parameter_list|(
name|IN
name|EFI_PHYSICAL_ADDRESS
name|Memory
parameter_list|,
name|IN
name|UINTN
name|NoPages
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_MEMORY_MAP
function_decl|)
parameter_list|(
name|IN
name|OUT
name|UINTN
modifier|*
name|MemoryMapSize
parameter_list|,
name|IN
name|OUT
name|EFI_MEMORY_DESCRIPTOR
modifier|*
name|MemoryMap
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|MapKey
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|DescriptorSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|DescriptorVersion
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|NextMemoryDescriptor
parameter_list|(
name|Ptr
parameter_list|,
name|Size
parameter_list|)
value|((EFI_MEMORY_DESCRIPTOR *) (((UINT8 *) Ptr) + Size))
end_define

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ALLOCATE_POOL
function_decl|)
parameter_list|(
name|IN
name|EFI_MEMORY_TYPE
name|PoolType
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_FREE_POOL
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_VIRTUAL_ADDRESS_MAP
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|MemoryMapSize
parameter_list|,
name|IN
name|UINTN
name|DescriptorSize
parameter_list|,
name|IN
name|UINT32
name|DescriptorVersion
parameter_list|,
name|IN
name|EFI_MEMORY_DESCRIPTOR
modifier|*
name|VirtualMap
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|EFI_OPTIONAL_PTR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_INTERNAL_FNC
value|0x00000002
end_define

begin_comment
comment|// Pointer to internal runtime fnc
end_comment

begin_define
define|#
directive|define
name|EFI_INTERNAL_PTR
value|0x00000004
end_define

begin_comment
comment|// Pointer to internal runtime data
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONVERT_POINTER
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|DebugDisposition
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
modifier|*
name|Address
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Events
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EVT_TIMER
value|0x80000000
end_define

begin_define
define|#
directive|define
name|EVT_RUNTIME
value|0x40000000
end_define

begin_define
define|#
directive|define
name|EVT_RUNTIME_CONTEXT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|EVT_NOTIFY_WAIT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EVT_NOTIFY_SIGNAL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|EVT_SIGNAL_EXIT_BOOT_SERVICES
value|0x00000201
end_define

begin_define
define|#
directive|define
name|EVT_SIGNAL_VIRTUAL_ADDRESS_CHANGE
value|0x60000202
end_define

begin_define
define|#
directive|define
name|EVT_EFI_SIGNAL_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|EVT_EFI_SIGNAL_MAX
value|2
end_define

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EVENT_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_EVENT
name|Event
parameter_list|,
name|IN
name|VOID
modifier|*
name|Context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREATE_EVENT
function_decl|)
parameter_list|(
name|IN
name|UINT32
name|Type
parameter_list|,
name|IN
name|EFI_TPL
name|NotifyTpl
parameter_list|,
name|IN
name|EFI_EVENT_NOTIFY
name|NotifyFunction
parameter_list|,
name|IN
name|VOID
modifier|*
name|NotifyContext
parameter_list|,
name|OUT
name|EFI_EVENT
modifier|*
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|TimerCancel
block|,
name|TimerPeriodic
block|,
name|TimerRelative
block|,
name|TimerTypeMax
block|}
name|EFI_TIMER_DELAY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_TIMER
function_decl|)
parameter_list|(
name|IN
name|EFI_EVENT
name|Event
parameter_list|,
name|IN
name|EFI_TIMER_DELAY
name|Type
parameter_list|,
name|IN
name|UINT64
name|TriggerTime
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SIGNAL_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WAIT_FOR_EVENT
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|NumberOfEvents
parameter_list|,
name|IN
name|EFI_EVENT
modifier|*
name|Event
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Index
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CLOSE_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CHECK_EVENT
function_decl|)
parameter_list|(
name|IN
name|EFI_EVENT
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Task priority level
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|TPL_APPLICATION
value|4
end_define

begin_define
define|#
directive|define
name|TPL_CALLBACK
value|8
end_define

begin_define
define|#
directive|define
name|TPL_NOTIFY
value|16
end_define

begin_define
define|#
directive|define
name|TPL_HIGH_LEVEL
value|31
end_define

begin_typedef
typedef|typedef
name|EFI_TPL
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RAISE_TPL
function_decl|)
parameter_list|(
name|IN
name|EFI_TPL
name|NewTpl
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RESTORE_TPL
function_decl|)
parameter_list|(
name|IN
name|EFI_TPL
name|OldTpl
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI platform varibles
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_GLOBAL_VARIABLE
define|\
value|{ 0x8BE4DF61, 0x93CA, 0x11d2, 0xAA, 0x0D, 0x00, 0xE0, 0x98, 0x03, 0x2B, 0x8C }
end_define

begin_comment
comment|// Variable attributes
end_comment

begin_define
define|#
directive|define
name|EFI_VARIABLE_NON_VOLATILE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_BOOTSERVICE_ACCESS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_VARIABLE_RUNTIME_ACCESS
value|0x00000004
end_define

begin_comment
comment|// Variable size limitation
end_comment

begin_define
define|#
directive|define
name|EFI_MAXIMUM_VARIABLE_SIZE
value|1024
end_define

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_VARIABLE
function_decl|)
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|VariableName
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|VendorGuid
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Attributes
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|DataSize
parameter_list|,
name|OUT
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_NEXT_VARIABLE_NAME
function_decl|)
parameter_list|(
name|IN
name|OUT
name|UINTN
modifier|*
name|VariableNameSize
parameter_list|,
name|IN
name|OUT
name|CHAR16
modifier|*
name|VariableName
parameter_list|,
name|IN
name|OUT
name|EFI_GUID
modifier|*
name|VendorGuid
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_VARIABLE
function_decl|)
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|VariableName
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|VendorGuid
parameter_list|,
name|IN
name|UINT32
name|Attributes
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|VOID
modifier|*
name|Data
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Time
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Resolution
decl_stmt|;
comment|// 1e-6 parts per million
name|UINT32
name|Accuracy
decl_stmt|;
comment|// hertz
name|BOOLEAN
name|SetsToZero
decl_stmt|;
comment|// Set clears sub-second time
block|}
name|EFI_TIME_CAPABILITIES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_TIME
function_decl|)
parameter_list|(
name|OUT
name|EFI_TIME
modifier|*
name|Time
parameter_list|,
name|OUT
name|EFI_TIME_CAPABILITIES
modifier|*
name|Capabilities
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_TIME
function_decl|)
parameter_list|(
name|IN
name|EFI_TIME
modifier|*
name|Time
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_WAKEUP_TIME
function_decl|)
parameter_list|(
name|OUT
name|BOOLEAN
modifier|*
name|Enabled
parameter_list|,
name|OUT
name|BOOLEAN
modifier|*
name|Pending
parameter_list|,
name|OUT
name|EFI_TIME
modifier|*
name|Time
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_WAKEUP_TIME
function_decl|)
parameter_list|(
name|IN
name|BOOLEAN
name|Enable
parameter_list|,
name|IN
name|EFI_TIME
modifier|*
name|Time
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Image functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// PE32+ Subsystem type for EFI images
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IMAGE_SUBSYSTEM_EFI_APPLICATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_APPLICATION
value|10
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER
value|11
end_define

begin_define
define|#
directive|define
name|IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER
value|12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// PE32+ Machine type for EFI images
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EFI_IMAGE_MACHINE_IA32
argument_list|)
end_if

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_IA32
value|0x014c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EFI_IMAGE_MACHINE_IA64
argument_list|)
end_if

begin_define
define|#
directive|define
name|EFI_IMAGE_MACHINE_IA64
value|0x0200
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// Image Entry prototype
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IMAGE_ENTRY_POINT
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|struct
name|_EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IMAGE_LOAD
function_decl|)
parameter_list|(
name|IN
name|BOOLEAN
name|BootPolicy
parameter_list|,
name|IN
name|EFI_HANDLE
name|ParentImageHandle
parameter_list|,
name|IN
name|EFI_DEVICE_PATH
modifier|*
name|FilePath
parameter_list|,
name|IN
name|VOID
modifier|*
name|SourceBuffer
name|OPTIONAL
parameter_list|,
name|IN
name|UINTN
name|SourceSize
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|ImageHandle
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IMAGE_START
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ExitDataSize
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|ExitData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EXIT
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|EFI_STATUS
name|ExitStatus
parameter_list|,
name|IN
name|UINTN
name|ExitDataSize
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ExitData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_IMAGE_UNLOAD
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// Image handle
end_comment

begin_define
define|#
directive|define
name|LOADED_IMAGE_PROTOCOL
define|\
value|{ 0x5B1B31A1, 0x9562, 0x11d2, 0x8E, 0x3F, 0x00, 0xA0, 0xC9, 0x69, 0x72, 0x3B }
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_INFORMATION_REVISION
value|0x1000
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Revision
decl_stmt|;
name|EFI_HANDLE
name|ParentHandle
decl_stmt|;
name|struct
name|_EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
decl_stmt|;
comment|// Source location of image
name|EFI_HANDLE
name|DeviceHandle
decl_stmt|;
name|EFI_DEVICE_PATH
modifier|*
name|FilePath
decl_stmt|;
name|VOID
modifier|*
name|Reserved
decl_stmt|;
comment|// Images load options
name|UINT32
name|LoadOptionsSize
decl_stmt|;
name|VOID
modifier|*
name|LoadOptions
decl_stmt|;
comment|// Location of where image was loaded
name|VOID
modifier|*
name|ImageBase
decl_stmt|;
name|UINT64
name|ImageSize
decl_stmt|;
name|EFI_MEMORY_TYPE
name|ImageCodeType
decl_stmt|;
name|EFI_MEMORY_TYPE
name|ImageDataType
decl_stmt|;
comment|// If the driver image supports a dynamic unload request
name|EFI_IMAGE_UNLOAD
name|Unload
decl_stmt|;
block|}
name|EFI_LOADED_IMAGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_EXIT_BOOT_SERVICES
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|UINTN
name|MapKey
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Misc
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_STALL
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|Microseconds
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_WATCHDOG_TIMER
function_decl|)
parameter_list|(
name|IN
name|UINTN
name|Timeout
parameter_list|,
name|IN
name|UINT64
name|WatchdogCode
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|WatchdogData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiResetCold
block|,
name|EfiResetWarm
block|}
name|EFI_RESET_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RESET_SYSTEM
function_decl|)
parameter_list|(
name|IN
name|EFI_RESET_TYPE
name|ResetType
parameter_list|,
name|IN
name|EFI_STATUS
name|ResetStatus
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|IN
name|CHAR16
modifier|*
name|ResetData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_NEXT_MONOTONIC_COUNT
function_decl|)
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|Count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GET_NEXT_HIGH_MONO_COUNT
function_decl|)
parameter_list|(
name|OUT
name|UINT32
modifier|*
name|HighCount
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Protocol handler functions
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_NATIVE_INTERFACE
block|,
name|EFI_PCODE_INTERFACE
block|}
name|EFI_INTERFACE_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INSTALL_PROTOCOL_INTERFACE
function_decl|)
parameter_list|(
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|Handle
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|EFI_INTERFACE_TYPE
name|InterfaceType
parameter_list|,
name|IN
name|VOID
modifier|*
name|Interface
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REINSTALL_PROTOCOL_INTERFACE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|VOID
modifier|*
name|OldInterface
parameter_list|,
name|IN
name|VOID
modifier|*
name|NewInterface
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNINSTALL_PROTOCOL_INTERFACE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|VOID
modifier|*
name|Interface
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HANDLE_PROTOCOL
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Interface
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_REGISTER_PROTOCOL_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|EFI_EVENT
name|Event
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Registration
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|AllHandles
block|,
name|ByRegisterNotify
block|,
name|ByProtocol
block|}
name|EFI_LOCATE_SEARCH_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOCATE_HANDLE
function_decl|)
parameter_list|(
name|IN
name|EFI_LOCATE_SEARCH_TYPE
name|SearchType
parameter_list|,
name|IN
name|EFI_GUID
modifier|*
name|Protocol
name|OPTIONAL
parameter_list|,
name|IN
name|VOID
modifier|*
name|SearchKey
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|BufferSize
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOCATE_DEVICE_PATH
function_decl|)
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|OUT
name|EFI_DEVICE_PATH
modifier|*
modifier|*
name|DevicePath
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|Device
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INSTALL_CONFIGURATION_TABLE
function_decl|)
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|IN
name|VOID
modifier|*
name|Table
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_RESERVED_SERVICE
function_decl|)
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Standard EFI table header
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_TABLE_HEARDER
block|{
name|UINT64
name|Signature
decl_stmt|;
name|UINT32
name|Revision
decl_stmt|;
name|UINT32
name|HeaderSize
decl_stmt|;
name|UINT32
name|CRC32
decl_stmt|;
name|UINT32
name|Reserved
decl_stmt|;
block|}
name|EFI_TABLE_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Runtime Serivces Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_SIGNATURE
value|0x56524553544e5552
end_define

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_REVISION
value|(EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// Time services
comment|//
name|EFI_GET_TIME
name|GetTime
decl_stmt|;
name|EFI_SET_TIME
name|SetTime
decl_stmt|;
name|EFI_GET_WAKEUP_TIME
name|GetWakeupTime
decl_stmt|;
name|EFI_SET_WAKEUP_TIME
name|SetWakeupTime
decl_stmt|;
comment|//
comment|// Virtual memory services
comment|//
name|EFI_SET_VIRTUAL_ADDRESS_MAP
name|SetVirtualAddressMap
decl_stmt|;
name|EFI_CONVERT_POINTER
name|ConvertPointer
decl_stmt|;
comment|//
comment|// Variable serviers
comment|//
name|EFI_GET_VARIABLE
name|GetVariable
decl_stmt|;
name|EFI_GET_NEXT_VARIABLE_NAME
name|GetNextVariableName
decl_stmt|;
name|EFI_SET_VARIABLE
name|SetVariable
decl_stmt|;
comment|//
comment|// Misc
comment|//
name|EFI_GET_NEXT_HIGH_MONO_COUNT
name|GetNextHighMonotonicCount
decl_stmt|;
name|EFI_RESET_SYSTEM
name|ResetSystem
decl_stmt|;
block|}
name|EFI_RUNTIME_SERVICES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Boot Services Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_SIGNATURE
value|0x56524553544f4f42
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_REVISION
value|(EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_BOOT_SERVICES
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// Task priority functions
comment|//
name|EFI_RAISE_TPL
name|RaiseTPL
decl_stmt|;
name|EFI_RESTORE_TPL
name|RestoreTPL
decl_stmt|;
comment|//
comment|// Memory functions
comment|//
name|EFI_ALLOCATE_PAGES
name|AllocatePages
decl_stmt|;
name|EFI_FREE_PAGES
name|FreePages
decl_stmt|;
name|EFI_GET_MEMORY_MAP
name|GetMemoryMap
decl_stmt|;
name|EFI_ALLOCATE_POOL
name|AllocatePool
decl_stmt|;
name|EFI_FREE_POOL
name|FreePool
decl_stmt|;
comment|//
comment|// Event& timer functions
comment|//
name|EFI_CREATE_EVENT
name|CreateEvent
decl_stmt|;
name|EFI_SET_TIMER
name|SetTimer
decl_stmt|;
name|EFI_WAIT_FOR_EVENT
name|WaitForEvent
decl_stmt|;
name|EFI_SIGNAL_EVENT
name|SignalEvent
decl_stmt|;
name|EFI_CLOSE_EVENT
name|CloseEvent
decl_stmt|;
name|EFI_CHECK_EVENT
name|CheckEvent
decl_stmt|;
comment|//
comment|// Protocol handler functions
comment|//
name|EFI_INSTALL_PROTOCOL_INTERFACE
name|InstallProtocolInterface
decl_stmt|;
name|EFI_REINSTALL_PROTOCOL_INTERFACE
name|ReinstallProtocolInterface
decl_stmt|;
name|EFI_UNINSTALL_PROTOCOL_INTERFACE
name|UninstallProtocolInterface
decl_stmt|;
name|EFI_HANDLE_PROTOCOL
name|HandleProtocol
decl_stmt|;
name|EFI_HANDLE_PROTOCOL
name|PCHandleProtocol
decl_stmt|;
name|EFI_REGISTER_PROTOCOL_NOTIFY
name|RegisterProtocolNotify
decl_stmt|;
name|EFI_LOCATE_HANDLE
name|LocateHandle
decl_stmt|;
name|EFI_LOCATE_DEVICE_PATH
name|LocateDevicePath
decl_stmt|;
name|EFI_INSTALL_CONFIGURATION_TABLE
name|InstallConfigurationTable
decl_stmt|;
comment|//
comment|// Image functions
comment|//
name|EFI_IMAGE_LOAD
name|LoadImage
decl_stmt|;
name|EFI_IMAGE_START
name|StartImage
decl_stmt|;
name|EFI_EXIT
name|Exit
decl_stmt|;
name|EFI_IMAGE_UNLOAD
name|UnloadImage
decl_stmt|;
name|EFI_EXIT_BOOT_SERVICES
name|ExitBootServices
decl_stmt|;
comment|//
comment|// Misc functions
comment|//
name|EFI_GET_NEXT_MONOTONIC_COUNT
name|GetNextMonotonicCount
decl_stmt|;
name|EFI_STALL
name|Stall
decl_stmt|;
name|EFI_SET_WATCHDOG_TIMER
name|SetWatchdogTimer
decl_stmt|;
block|}
name|EFI_BOOT_SERVICES
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Configuration Table and GUID definitions
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|MPS_TABLE_GUID
define|\
value|{ 0xeb9d2d2f, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
end_define

begin_define
define|#
directive|define
name|ACPI_TABLE_GUID
define|\
value|{ 0xeb9d2d30, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
end_define

begin_define
define|#
directive|define
name|ACPI_20_TABLE_GUID
define|\
value|{ 0x8868e871, 0xe4f1, 0x11d3, { 0xbc, 0x22, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } }
end_define

begin_define
define|#
directive|define
name|SMBIOS_TABLE_GUID
define|\
value|{ 0xeb9d2d31, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
end_define

begin_define
define|#
directive|define
name|SAL_SYSTEM_TABLE_GUID
define|\
value|{ 0xeb9d2d32, 0x2d88, 0x11d3, { 0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } }
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_CONFIGURATION_TABLE
block|{
name|EFI_GUID
name|VendorGuid
decl_stmt|;
name|VOID
modifier|*
name|VendorTable
decl_stmt|;
block|}
name|EFI_CONFIGURATION_TABLE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI System Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SYSTEM_TABLE_SIGNATURE
value|0x5453595320494249
end_define

begin_define
define|#
directive|define
name|EFI_SYSTEM_TABLE_REVISION
value|(EFI_SPECIFICATION_MAJOR_REVISION<<16) | (EFI_SPECIFICATION_MINOR_REVISION)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_SYSTEM_TABLE
block|{
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
name|CHAR16
modifier|*
name|FirmwareVendor
decl_stmt|;
name|UINT32
name|FirmwareRevision
decl_stmt|;
name|EFI_HANDLE
name|ConsoleInHandle
decl_stmt|;
name|SIMPLE_INPUT_INTERFACE
modifier|*
name|ConIn
decl_stmt|;
name|EFI_HANDLE
name|ConsoleOutHandle
decl_stmt|;
name|SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|ConOut
decl_stmt|;
name|EFI_HANDLE
name|StandardErrorHandle
decl_stmt|;
name|SIMPLE_TEXT_OUTPUT_INTERFACE
modifier|*
name|StdErr
decl_stmt|;
name|EFI_RUNTIME_SERVICES
modifier|*
name|RuntimeServices
decl_stmt|;
name|EFI_BOOT_SERVICES
modifier|*
name|BootServices
decl_stmt|;
name|UINTN
name|NumberOfTableEntries
decl_stmt|;
name|EFI_CONFIGURATION_TABLE
modifier|*
name|ConfigurationTable
decl_stmt|;
block|}
name|EFI_SYSTEM_TABLE
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

