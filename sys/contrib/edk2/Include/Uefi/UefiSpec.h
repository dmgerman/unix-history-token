begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Include file that supports UEFI.    This include file must contain things defined in the UEFI 2.6 specification.   If a code construct is defined in the UEFI 2.6 specification it must be included   by this include file.  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_SPEC_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_SPEC_H__
end_define

begin_include
include|#
directive|include
file|<Uefi/UefiMultiPhase.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DevicePath.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SimpleTextIn.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SimpleTextInEx.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/SimpleTextOut.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of EFI memory allocation types.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Allocate any available range of pages that satisfies the request.
comment|///
name|AllocateAnyPages
block|,
comment|///
comment|/// Allocate any available range of pages whose uppermost address is less than
comment|/// or equal to a specified maximum address.
comment|///
name|AllocateMaxAddress
block|,
comment|///
comment|/// Allocate pages at a specified address.
comment|///
name|AllocateAddress
block|,
comment|///
comment|/// Maximum enumeration value that may be used for bounds checking.
comment|///
name|MaxAllocateType
block|}
name|EFI_ALLOCATE_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit definitions for EFI_TIME.Daylight
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_TIME_ADJUST_DAYLIGHT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_TIME_IN_DAYLIGHT
value|0x02
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Value definition for EFI_TIME.TimeZone.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_UNSPECIFIED_TIMEZONE
value|0x07FF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Memory cacheability attributes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_UC
value|0x0000000000000001ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WC
value|0x0000000000000002ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WT
value|0x0000000000000004ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_WB
value|0x0000000000000008ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_UCE
value|0x0000000000000010ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Physical memory protection attributes
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: UEFI spec 2.5 and following: use EFI_MEMORY_RO as write-protected physical memory
end_comment

begin_comment
comment|// protection attribute. Also, EFI_MEMORY_WP means cacheability attribute.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_WP
value|0x0000000000001000ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_RP
value|0x0000000000002000ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_XP
value|0x0000000000004000ULL
end_define

begin_define
define|#
directive|define
name|EFI_MEMORY_RO
value|0x0000000000020000ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Physical memory persistence attribute.
end_comment

begin_comment
comment|// The memory region supports byte-addressable non-volatility.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_NV
value|0x0000000000008000ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// The memory region provides higher reliability relative to other memory in the system.
end_comment

begin_comment
comment|// If all memory has the same reliability, then this bit is not used.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_MORE_RELIABLE
value|0x0000000000010000ULL
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Runtime memory attribute
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_RUNTIME
value|0x8000000000000000ULL
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Memory descriptor version number.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_MEMORY_DESCRIPTOR_VERSION
value|1
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Definition of an EFI memory descriptor.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Type of the memory region.  See EFI_MEMORY_TYPE.
comment|///
name|UINT32
name|Type
decl_stmt|;
comment|///
comment|/// Physical address of the first byte of the memory region.  Must aligned
comment|/// on a 4 KB boundary.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|PhysicalStart
decl_stmt|;
comment|///
comment|/// Virtual address of the first byte of the memory region.  Must aligned
comment|/// on a 4 KB boundary.
comment|///
name|EFI_VIRTUAL_ADDRESS
name|VirtualStart
decl_stmt|;
comment|///
comment|/// Number of 4KB pages in the memory region.
comment|///
name|UINT64
name|NumberOfPages
decl_stmt|;
comment|///
comment|/// Attributes of the memory region that describe the bit mask of capabilities
comment|/// for that memory region, and not necessarily the current settings for that
comment|/// memory region.
comment|///
name|UINT64
name|Attribute
decl_stmt|;
block|}
name|EFI_MEMORY_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|/**   Allocates memory pages from the system.    @param[in]       Type         The type of allocation to perform.   @param[in]       MemoryType   The type of memory to allocate.                                 MemoryType values in the range 0x70000000..0x7FFFFFFF                                 are reserved for OEM use. MemoryType values in the range                                 0x80000000..0xFFFFFFFF are reserved for use by UEFI OS loaders                                 that are provided by operating system vendors.   @param[in]       Pages        The number of contiguous 4 KB pages to allocate.   @param[in, out]  Memory       The pointer to a physical address. On input, the way in which the address is                                 used depends on the value of Type.    @retval EFI_SUCCESS           The requested pages were allocated.   @retval EFI_INVALID_PARAMETER 1) Type is not AllocateAnyPages or                                 AllocateMaxAddress or AllocateAddress.                                 2) MemoryType is in the range                                 EfiMaxMemoryType..0x6FFFFFFF.                                 3) Memory is NULL.                                 4) MemoryType is EfiPersistentMemory.   @retval EFI_OUT_OF_RESOURCES  The pages could not be allocated.   @retval EFI_NOT_FOUND         The requested pages could not be found.  **/
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
name|Pages
parameter_list|,
name|IN
name|OUT
name|EFI_PHYSICAL_ADDRESS
modifier|*
name|Memory
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Frees memory pages.    @param[in]  Memory      The base physical address of the pages to be freed.   @param[in]  Pages       The number of contiguous 4 KB pages to free.    @retval EFI_SUCCESS           The requested pages were freed.   @retval EFI_INVALID_PARAMETER Memory is not a page-aligned address or Pages is invalid.   @retval EFI_NOT_FOUND         The requested memory pages were not allocated with                                 AllocatePages().  **/
end_comment

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
name|Pages
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the current memory map.    @param[in, out]  MemoryMapSize         A pointer to the size, in bytes, of the MemoryMap buffer.                                          On input, this is the size of the buffer allocated by the caller.                                          On output, it is the size of the buffer returned by the firmware if                                          the buffer was large enough, or the size of the buffer needed to contain                                          the map if the buffer was too small.   @param[in, out]  MemoryMap             A pointer to the buffer in which firmware places the current memory                                          map.   @param[out]      MapKey                A pointer to the location in which firmware returns the key for the                                          current memory map.   @param[out]      DescriptorSize        A pointer to the location in which firmware returns the size, in bytes, of                                          an individual EFI_MEMORY_DESCRIPTOR.   @param[out]      DescriptorVersion     A pointer to the location in which firmware returns the version number                                          associated with the EFI_MEMORY_DESCRIPTOR.    @retval EFI_SUCCESS           The memory map was returned in the MemoryMap buffer.   @retval EFI_BUFFER_TOO_SMALL  The MemoryMap buffer was too small. The current buffer size                                 needed to hold the memory map is returned in MemoryMapSize.   @retval EFI_INVALID_PARAMETER 1) MemoryMapSize is NULL.                                 2) The MemoryMap buffer is not too small and MemoryMap is                                    NULL.  **/
end_comment

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

begin_comment
comment|/**   Allocates pool memory.    @param[in]   PoolType         The type of pool to allocate.                                 MemoryType values in the range 0x70000000..0x7FFFFFFF                                 are reserved for OEM use. MemoryType values in the range                                 0x80000000..0xFFFFFFFF are reserved for use by UEFI OS loaders                                 that are provided by operating system vendors.   @param[in]   Size             The number of bytes to allocate from the pool.   @param[out]  Buffer           A pointer to a pointer to the allocated buffer if the call succeeds;                                 undefined otherwise.    @retval EFI_SUCCESS           The requested number of bytes was allocated.   @retval EFI_OUT_OF_RESOURCES  The pool requested could not be allocated.   @retval EFI_INVALID_PARAMETER Buffer is NULL.                                 PoolType is in the range EfiMaxMemoryType..0x6FFFFFFF.                                 PoolType is EfiPersistentMemory.  **/
end_comment

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

begin_comment
comment|/**   Returns pool memory to the system.    @param[in]  Buffer            The pointer to the buffer to free.    @retval EFI_SUCCESS           The memory was returned to the system.   @retval EFI_INVALID_PARAMETER Buffer was invalid.  **/
end_comment

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

begin_comment
comment|/**   Changes the runtime addressing mode of EFI firmware from physical to virtual.    @param[in]  MemoryMapSize     The size in bytes of VirtualMap.   @param[in]  DescriptorSize    The size in bytes of an entry in the VirtualMap.   @param[in]  DescriptorVersion The version of the structure entries in VirtualMap.   @param[in]  VirtualMap        An array of memory descriptors which contain new virtual                                 address mapping information for all runtime ranges.    @retval EFI_SUCCESS           The virtual address map has been applied.   @retval EFI_UNSUPPORTED       EFI firmware is not at runtime, or the EFI firmware is already in                                 virtual address mapped mode.   @retval EFI_INVALID_PARAMETER DescriptorSize or DescriptorVersion is invalid.   @retval EFI_NO_MAPPING        A virtual address was not supplied for a range in the memory                                 map that requires a mapping.   @retval EFI_NOT_FOUND         A virtual address was supplied for an address that is not found                                 in the memory map.  **/
end_comment

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

begin_comment
comment|/**   Connects one or more drivers to a controller.    @param[in]  ControllerHandle      The handle of the controller to which driver(s) are to be connected.   @param[in]  DriverImageHandle     A pointer to an ordered list handles that support the                                     EFI_DRIVER_BINDING_PROTOCOL.   @param[in]  RemainingDevicePath   A pointer to the device path that specifies a child of the                                     controller specified by ControllerHandle.   @param[in]  Recursive             If TRUE, then ConnectController() is called recursively                                     until the entire tree of controllers below the controller specified                                     by ControllerHandle have been created. If FALSE, then                                     the tree of controllers is only expanded one level.    @retval EFI_SUCCESS           1) One or more drivers were connected to ControllerHandle.                                 2) No drivers were connected to ControllerHandle, but                                 RemainingDevicePath is not NULL, and it is an End Device                                 Path Node.   @retval EFI_INVALID_PARAMETER ControllerHandle is NULL.   @retval EFI_NOT_FOUND         1) There are no EFI_DRIVER_BINDING_PROTOCOL instances                                 present in the system.                                 2) No drivers were connected to ControllerHandle.   @retval EFI_SECURITY_VIOLATION                                  The user has no permission to start UEFI device drivers on the device path                                  associated with the ControllerHandle or specified by the RemainingDevicePath. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CONNECT_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
modifier|*
name|DriverImageHandle
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|RemainingDevicePath
parameter_list|,
name|OPTIONAL
name|IN
name|BOOLEAN
name|Recursive
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Disconnects one or more drivers from a controller.    @param[in]  ControllerHandle      The handle of the controller from which driver(s) are to be disconnected.   @param[in]  DriverImageHandle     The driver to disconnect from ControllerHandle.                                     If DriverImageHandle is NULL, then all the drivers currently managing                                     ControllerHandle are disconnected from ControllerHandle.   @param[in]  ChildHandle           The handle of the child to destroy.                                     If ChildHandle is NULL, then all the children of ControllerHandle are                                     destroyed before the drivers are disconnected from ControllerHandle.    @retval EFI_SUCCESS           1) One or more drivers were disconnected from the controller.                                 2) On entry, no drivers are managing ControllerHandle.                                 3) DriverImageHandle is not NULL, and on entry                                    DriverImageHandle is not managing ControllerHandle.   @retval EFI_INVALID_PARAMETER 1) ControllerHandle is NULL.                                 2) DriverImageHandle is not NULL, and it is not a valid EFI_HANDLE.                                 3) ChildHandle is not NULL, and it is not a valid EFI_HANDLE.                                 4) DriverImageHandle does not support the EFI_DRIVER_BINDING_PROTOCOL.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to disconnect any drivers from                                 ControllerHandle.   @retval EFI_DEVICE_ERROR      The controller could not be disconnected because of a device error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_DISCONNECT_CONTROLLER
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverImageHandle
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_HANDLE
name|ChildHandle
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// ConvertPointer DebugDisposition type.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_OPTIONAL_PTR
value|0x00000001
end_define

begin_comment
comment|/**   Determines the new virtual address that is to be used on subsequent memory accesses.    @param[in]       DebugDisposition  Supplies type information for the pointer being converted.   @param[in, out]  Address           A pointer to a pointer that is to be fixed to be the value needed                                      for the new virtual address mappings being applied.    @retval EFI_SUCCESS           The pointer pointed to by Address was modified.   @retval EFI_INVALID_PARAMETER 1) Address is NULL.                                 2) *Address is NULL and DebugDisposition does                                 not have the EFI_OPTIONAL_PTR bit set.   @retval EFI_NOT_FOUND         The pointer pointed to by Address was not found to be part                                 of the current memory map. This is normally fatal.  **/
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
comment|// These types can be ORed together as needed - for example,
end_comment

begin_comment
comment|// EVT_TIMER might be Ored with EVT_NOTIFY_WAIT or
end_comment

begin_comment
comment|// EVT_NOTIFY_SIGNAL.
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

begin_comment
comment|//
end_comment

begin_comment
comment|// The event's NotifyContext pointer points to a runtime memory
end_comment

begin_comment
comment|// address.
end_comment

begin_comment
comment|// The event is deprecated in UEFI2.0 and later specifications.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EVT_RUNTIME_CONTEXT
value|0x20000000
end_define

begin_comment
comment|/**   Invoke a notification event    @param[in]  Event                 Event whose notification function is being invoked.   @param[in]  Context               The pointer to the notification function's context,                                     which is implementation-dependent.  **/
end_comment

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

begin_comment
comment|/**   Creates an event.    @param[in]   Type             The type of event to create and its mode and attributes.   @param[in]   NotifyTpl        The task priority level of event notifications, if needed.   @param[in]   NotifyFunction   The pointer to the event's notification function, if any.   @param[in]   NotifyContext    The pointer to the notification function's context; corresponds to parameter                                 Context in the notification function.   @param[out]  Event            The pointer to the newly created event if the call succeeds; undefined                                 otherwise.    @retval EFI_SUCCESS           The event structure was created.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The event could not be allocated.  **/
end_comment

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

begin_comment
comment|/**   Creates an event in a group.    @param[in]   Type             The type of event to create and its mode and attributes.   @param[in]   NotifyTpl        The task priority level of event notifications,if needed.   @param[in]   NotifyFunction   The pointer to the event's notification function, if any.   @param[in]   NotifyContext    The pointer to the notification function's context; corresponds to parameter                                 Context in the notification function.   @param[in]   EventGroup       The pointer to the unique identifier of the group to which this event belongs.                                 If this is NULL, then the function behaves as if the parameters were passed                                 to CreateEvent.   @param[out]  Event            The pointer to the newly created event if the call succeeds; undefined                                 otherwise.    @retval EFI_SUCCESS           The event structure was created.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_OUT_OF_RESOURCES  The event could not be allocated.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CREATE_EVENT_EX
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
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|VOID
modifier|*
name|NotifyContext
name|OPTIONAL
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|EventGroup
name|OPTIONAL
parameter_list|,
name|OUT
name|EFI_EVENT
modifier|*
name|Event
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Timer delay types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// An event's timer settings is to be cancelled and not trigger time is to be set/
comment|///
name|TimerCancel
block|,
comment|///
comment|/// An event is to be signaled periodically at a specified interval from the current time.
comment|///
name|TimerPeriodic
block|,
comment|///
comment|/// An event is to be signaled once at a specified interval from the current time.
comment|///
name|TimerRelative
block|}
name|EFI_TIMER_DELAY
typedef|;
end_typedef

begin_comment
comment|/**   Sets the type of timer and the trigger time for a timer event.    @param[in]  Event             The timer event that is to be signaled at the specified time.   @param[in]  Type              The type of time that is specified in TriggerTime.   @param[in]  TriggerTime       The number of 100ns units until the timer expires.                                 A TriggerTime of 0 is legal.                                 If Type is TimerRelative and TriggerTime is 0, then the timer                                 event will be signaled on the next timer tick.                                 If Type is TimerPeriodic and TriggerTime is 0, then the timer                                 event will be signaled on every timer tick.    @retval EFI_SUCCESS           The event has been set to be signaled at the requested time.   @retval EFI_INVALID_PARAMETER Event or Type is not valid.  **/
end_comment

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

begin_comment
comment|/**   Signals an event.    @param[in]  Event             The event to signal.    @retval EFI_SUCCESS           The event has been signaled.  **/
end_comment

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

begin_comment
comment|/**   Stops execution until an event is signaled.    @param[in]   NumberOfEvents   The number of events in the Event array.   @param[in]   Event            An array of EFI_EVENT.   @param[out]  Index            The pointer to the index of the event which satisfied the wait condition.    @retval EFI_SUCCESS           The event indicated by Index was signaled.   @retval EFI_INVALID_PARAMETER 1) NumberOfEvents is 0.                                 2) The event indicated by Index is of type                                    EVT_NOTIFY_SIGNAL.   @retval EFI_UNSUPPORTED       The current TPL is not TPL_APPLICATION.  **/
end_comment

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

begin_comment
comment|/**   Closes an event.    @param[in]  Event             The event to close.    @retval EFI_SUCCESS           The event has been closed.  **/
end_comment

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

begin_comment
comment|/**   Checks whether an event is in the signaled state.    @param[in]  Event             The event to check.    @retval EFI_SUCCESS           The event is in the signaled state.   @retval EFI_NOT_READY         The event is not in the signaled state.   @retval EFI_INVALID_PARAMETER Event is of type EVT_NOTIFY_SIGNAL.  **/
end_comment

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

begin_comment
comment|/**   Raises a task's priority level and returns its previous level.    @param[in]  NewTpl          The new task priority level.    @return Previous task priority level  **/
end_comment

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

begin_comment
comment|/**   Restores a task's priority level to its previous value.    @param[in]  OldTpl          The previous task priority level to restore.  **/
end_comment

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
comment|/**   Returns the value of a variable.    @param[in]       VariableName  A Null-terminated string that is the name of the vendor's                                  variable.   @param[in]       VendorGuid    A unique identifier for the vendor.   @param[out]      Attributes    If not NULL, a pointer to the memory location to return the                                  attributes bitmask for the variable.   @param[in, out]  DataSize      On input, the size in bytes of the return Data buffer.                                  On output the size of data returned in Data.   @param[out]      Data          The buffer to return the contents of the variable. May be NULL                                  with a zero DataSize in order to determine the size buffer needed.    @retval EFI_SUCCESS            The function completed successfully.   @retval EFI_NOT_FOUND          The variable was not found.   @retval EFI_BUFFER_TOO_SMALL   The DataSize is too small for the result.   @retval EFI_INVALID_PARAMETER  VariableName is NULL.   @retval EFI_INVALID_PARAMETER  VendorGuid is NULL.   @retval EFI_INVALID_PARAMETER  DataSize is NULL.   @retval EFI_INVALID_PARAMETER  The DataSize is not too small and Data is NULL.   @retval EFI_DEVICE_ERROR       The variable could not be retrieved due to a hardware error.   @retval EFI_SECURITY_VIOLATION The variable could not be retrieved due to an authentication failure.  **/
end_comment

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
parameter_list|,
name|OPTIONAL
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
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Enumerates the current variable names.    @param[in, out]  VariableNameSize The size of the VariableName buffer.   @param[in, out]  VariableName     On input, supplies the last VariableName that was returned                                     by GetNextVariableName(). On output, returns the Nullterminated                                     string of the current variable.   @param[in, out]  VendorGuid       On input, supplies the last VendorGuid that was returned by                                     GetNextVariableName(). On output, returns the                                     VendorGuid of the current variable.    @retval EFI_SUCCESS           The function completed successfully.   @retval EFI_NOT_FOUND         The next variable was not found.   @retval EFI_BUFFER_TOO_SMALL  The VariableNameSize is too small for the result.   @retval EFI_INVALID_PARAMETER VariableNameSize is NULL.   @retval EFI_INVALID_PARAMETER VariableName is NULL.   @retval EFI_INVALID_PARAMETER VendorGuid is NULL.   @retval EFI_DEVICE_ERROR      The variable could not be retrieved due to a hardware error.  **/
end_comment

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

begin_comment
comment|/**   Sets the value of a variable.    @param[in]  VariableName       A Null-terminated string that is the name of the vendor's variable.                                  Each VariableName is unique for each VendorGuid. VariableName must                                  contain 1 or more characters. If VariableName is an empty string,                                  then EFI_INVALID_PARAMETER is returned.   @param[in]  VendorGuid         A unique identifier for the vendor.   @param[in]  Attributes         Attributes bitmask to set for the variable.   @param[in]  DataSize           The size in bytes of the Data buffer. Unless the EFI_VARIABLE_APPEND_WRITE,                                   EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS, or                                   EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS attribute is set, a size of zero                                   causes the variable to be deleted. When the EFI_VARIABLE_APPEND_WRITE attribute is                                   set, then a SetVariable() call with a DataSize of zero will not cause any change to                                   the variable value (the timestamp associated with the variable may be updated however                                   even if no new data value is provided,see the description of the                                   EFI_VARIABLE_AUTHENTICATION_2 descriptor below. In this case the DataSize will not                                   be zero since the EFI_VARIABLE_AUTHENTICATION_2 descriptor will be populated).    @param[in]  Data               The contents for the variable.    @retval EFI_SUCCESS            The firmware has successfully stored the variable and its data as                                  defined by the Attributes.   @retval EFI_INVALID_PARAMETER  An invalid combination of attribute bits, name, and GUID was supplied, or the                                  DataSize exceeds the maximum allowed.   @retval EFI_INVALID_PARAMETER  VariableName is an empty string.   @retval EFI_OUT_OF_RESOURCES   Not enough storage is available to hold the variable and its data.   @retval EFI_DEVICE_ERROR       The variable could not be retrieved due to a hardware error.   @retval EFI_WRITE_PROTECTED    The variable in question is read-only.   @retval EFI_WRITE_PROTECTED    The variable in question cannot be deleted.   @retval EFI_SECURITY_VIOLATION The variable could not be written due to EFI_VARIABLE_AUTHENTICATED_WRITE_ACCESS                                   or EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACESS being set, but the AuthInfo                                   does NOT pass the validation check carried out by the firmware.      @retval EFI_NOT_FOUND          The variable trying to be updated or deleted was not found.  **/
end_comment

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
comment|///
end_comment

begin_comment
comment|/// This provides the capabilities of the
end_comment

begin_comment
comment|/// real time clock device as exposed through the EFI interfaces.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Provides the reporting resolution of the real-time clock device in
comment|/// counts per second. For a normal PC-AT CMOS RTC device, this
comment|/// value would be 1 Hz, or 1, to indicate that the device only reports
comment|/// the time to the resolution of 1 second.
comment|///
name|UINT32
name|Resolution
decl_stmt|;
comment|///
comment|/// Provides the timekeeping accuracy of the real-time clock in an
comment|/// error rate of 1E-6 parts per million. For a clock with an accuracy
comment|/// of 50 parts per million, the value in this field would be
comment|/// 50,000,000.
comment|///
name|UINT32
name|Accuracy
decl_stmt|;
comment|///
comment|/// A TRUE indicates that a time set operation clears the device's
comment|/// time below the Resolution reporting level. A FALSE
comment|/// indicates that the state below the Resolution level of the
comment|/// device is not cleared when the time is set. Normal PC-AT CMOS
comment|/// RTC devices set this value to FALSE.
comment|///
name|BOOLEAN
name|SetsToZero
decl_stmt|;
block|}
name|EFI_TIME_CAPABILITIES
typedef|;
end_typedef

begin_comment
comment|/**   Returns the current time and date information, and the time-keeping capabilities   of the hardware platform.    @param[out]  Time             A pointer to storage to receive a snapshot of the current time.   @param[out]  Capabilities     An optional pointer to a buffer to receive the real time clock                                 device's capabilities.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_INVALID_PARAMETER Time is NULL.   @retval EFI_DEVICE_ERROR      The time could not be retrieved due to hardware error.  **/
end_comment

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

begin_comment
comment|/**   Sets the current local time and date information.    @param[in]  Time              A pointer to the current time.    @retval EFI_SUCCESS           The operation completed successfully.   @retval EFI_INVALID_PARAMETER A time field is out of range.   @retval EFI_DEVICE_ERROR      The time could not be set due due to hardware error.  **/
end_comment

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

begin_comment
comment|/**   Returns the current wakeup alarm clock setting.    @param[out]  Enabled          Indicates if the alarm is currently enabled or disabled.   @param[out]  Pending          Indicates if the alarm signal is pending and requires acknowledgement.   @param[out]  Time             The current alarm setting.    @retval EFI_SUCCESS           The alarm settings were returned.   @retval EFI_INVALID_PARAMETER Enabled is NULL.   @retval EFI_INVALID_PARAMETER Pending is NULL.   @retval EFI_INVALID_PARAMETER Time is NULL.   @retval EFI_DEVICE_ERROR      The wakeup time could not be retrieved due to a hardware error.   @retval EFI_UNSUPPORTED       A wakeup timer is not supported on this platform.  **/
end_comment

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

begin_comment
comment|/**   Sets the system wakeup alarm clock time.    @param[in]  Enable            Enable or disable the wakeup alarm.   @param[in]  Time              If Enable is TRUE, the time to set the wakeup alarm for.                                 If Enable is FALSE, then this parameter is optional, and may be NULL.    @retval EFI_SUCCESS           If Enable is TRUE, then the wakeup alarm was enabled. If                                 Enable is FALSE, then the wakeup alarm was disabled.   @retval EFI_INVALID_PARAMETER A time field is out of range.   @retval EFI_DEVICE_ERROR      The wakeup time could not be set due to a hardware error.   @retval EFI_UNSUPPORTED       A wakeup timer is not supported on this platform.  **/
end_comment

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
comment|/**   Loads an EFI image into memory.    @param[in]   BootPolicy        If TRUE, indicates that the request originates from the boot                                  manager, and that the boot manager is attempting to load                                  FilePath as a boot selection. Ignored if SourceBuffer is                                  not NULL.   @param[in]   ParentImageHandle The caller's image handle.   @param[in]   DevicePath        The DeviceHandle specific file path from which the image is                                  loaded.   @param[in]   SourceBuffer      If not NULL, a pointer to the memory location containing a copy                                  of the image to be loaded.   @param[in]   SourceSize        The size in bytes of SourceBuffer. Ignored if SourceBuffer is NULL.   @param[out]  ImageHandle       The pointer to the returned image handle that is created when the                                  image is successfully loaded.    @retval EFI_SUCCESS            Image was loaded into memory correctly.   @retval EFI_NOT_FOUND          Both SourceBuffer and DevicePath are NULL.   @retval EFI_INVALID_PARAMETER  One or more parametes are invalid.   @retval EFI_UNSUPPORTED        The image type is not supported.   @retval EFI_OUT_OF_RESOURCES   Image was not loaded due to insufficient resources.   @retval EFI_LOAD_ERROR         Image was not loaded because the image format was corrupt or not                                  understood.   @retval EFI_DEVICE_ERROR       Image was not loaded because the device returned a read error.   @retval EFI_ACCESS_DENIED      Image was not loaded because the platform policy prohibits the                                   image from being loaded. NULL is returned in *ImageHandle.   @retval EFI_SECURITY_VIOLATION Image was loaded and an ImageHandle was created with a                                   valid EFI_LOADED_IMAGE_PROTOCOL. However, the current                                   platform policy specifies that the image should not be started. **/
end_comment

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
name|EFI_DEVICE_PATH_PROTOCOL
modifier|*
name|DevicePath
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

begin_comment
comment|/**   Transfers control to a loaded image's entry point.    @param[in]   ImageHandle       Handle of image to be started.   @param[out]  ExitDataSize      The pointer to the size, in bytes, of ExitData.   @param[out]  ExitData          The pointer to a pointer to a data buffer that includes a Null-terminated                                  string, optionally followed by additional binary data.    @retval EFI_INVALID_PARAMETER  ImageHandle is either an invalid image handle or the image                                  has already been initialized with StartImage.   @retval EFI_SECURITY_VIOLATION The current platform policy specifies that the image should not be started.   @return Exit code from image  **/
end_comment

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

begin_comment
comment|/**   Terminates a loaded EFI image and returns control to boot services.    @param[in]  ImageHandle       Handle that identifies the image. This parameter is passed to the                                  image on entry.   @param[in]  ExitStatus        The image's exit code.   @param[in]  ExitDataSize      The size, in bytes, of ExitData. Ignored if ExitStatus is EFI_SUCCESS.   @param[in]  ExitData          The pointer to a data buffer that includes a Null-terminated string,                                 optionally followed by additional binary data. The string is a                                  description that the caller may use to further indicate the reason                                  for the image's exit. ExitData is only valid if ExitStatus                                  is something other than EFI_SUCCESS. The ExitData buffer                                  must be allocated by calling AllocatePool().    @retval EFI_SUCCESS           The image specified by ImageHandle was unloaded.   @retval EFI_INVALID_PARAMETER The image specified by ImageHandle has been loaded and                                 started with LoadImage() and StartImage(), but the                                 image is not the currently executing image.  **/
end_comment

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

begin_comment
comment|/**   Unloads an image.    @param[in]  ImageHandle       Handle that identifies the image to be unloaded.    @retval EFI_SUCCESS           The image has been unloaded.   @retval EFI_INVALID_PARAMETER ImageHandle is not a valid image handle.  **/
end_comment

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
comment|/**   Terminates all boot services.    @param[in]  ImageHandle       Handle that identifies the exiting image.   @param[in]  MapKey            Key to the latest memory map.    @retval EFI_SUCCESS           Boot services have been terminated.   @retval EFI_INVALID_PARAMETER MapKey is incorrect.  **/
end_comment

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
comment|/**   Induces a fine-grained stall.    @param[in]  Microseconds      The number of microseconds to stall execution.    @retval EFI_SUCCESS           Execution was stalled at least the requested number of                                 Microseconds.  **/
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

begin_comment
comment|/**   Sets the system's watchdog timer.    @param[in]  Timeout           The number of seconds to set the watchdog timer to.   @param[in]  WatchdogCode      The numeric code to log on a watchdog timer timeout event.   @param[in]  DataSize          The size, in bytes, of WatchdogData.   @param[in]  WatchdogData      A data buffer that includes a Null-terminated string, optionally                                 followed by additional binary data.    @retval EFI_SUCCESS           The timeout has been set.   @retval EFI_INVALID_PARAMETER The supplied WatchdogCode is invalid.   @retval EFI_UNSUPPORTED       The system does not have a watchdog timer.   @retval EFI_DEVICE_ERROR      The watchdog timer could not be programmed due to a hardware                                 error.  **/
end_comment

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

begin_comment
comment|/**   Resets the entire platform.    @param[in]  ResetType         The type of reset to perform.   @param[in]  ResetStatus       The status code for the reset.   @param[in]  DataSize          The size, in bytes, of ResetData.   @param[in]  ResetData         For a ResetType of EfiResetCold, EfiResetWarm, or                                 EfiResetShutdown the data buffer starts with a Null-terminated                                 string, optionally followed by additional binary data.                                 The string is a description that the caller may use to further                                 indicate the reason for the system reset. ResetData is only                                 valid if ResetStatus is something other than EFI_SUCCESS                                 unless the ResetType is EfiResetPlatformSpecific                                 where a minimum amount of ResetData is always required. **/
end_comment

begin_typedef
typedef|typedef
name|VOID
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
name|VOID
modifier|*
name|ResetData
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns a monotonically increasing count for the platform.    @param[out]  Count            The pointer to returned value.    @retval EFI_SUCCESS           The next monotonic count was returned.   @retval EFI_INVALID_PARAMETER Count is NULL.   @retval EFI_DEVICE_ERROR      The device is not functioning properly.  **/
end_comment

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

begin_comment
comment|/**   Returns the next high 32 bits of the platform's monotonic counter.    @param[out]  HighCount        The pointer to returned value.    @retval EFI_SUCCESS           The next high monotonic count was returned.   @retval EFI_INVALID_PARAMETER HighCount is NULL.   @retval EFI_DEVICE_ERROR      The device is not functioning properly.  **/
end_comment

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
comment|/**   Computes and returns a 32-bit CRC for a data buffer.    @param[in]   Data             A pointer to the buffer on which the 32-bit CRC is to be computed.   @param[in]   DataSize         The number of bytes in the buffer Data.   @param[out]  Crc32            The 32-bit CRC that was computed for the data buffer specified by Data                                 and DataSize.    @retval EFI_SUCCESS           The 32-bit CRC was computed for the data buffer and returned in                                 Crc32.   @retval EFI_INVALID_PARAMETER Data is NULL.   @retval EFI_INVALID_PARAMETER Crc32 is NULL.   @retval EFI_INVALID_PARAMETER DataSize is 0.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CALCULATE_CRC32
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Data
parameter_list|,
name|IN
name|UINTN
name|DataSize
parameter_list|,
name|OUT
name|UINT32
modifier|*
name|Crc32
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Copies the contents of one buffer to another buffer.    @param[in]  Destination       The pointer to the destination buffer of the memory copy.   @param[in]  Source            The pointer to the source buffer of the memory copy.   @param[in]  Length            Number of bytes to copy from Source to Destination.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_COPY_MEM
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Destination
parameter_list|,
name|IN
name|VOID
modifier|*
name|Source
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   The SetMem() function fills a buffer with a specified value.    @param[in]  Buffer            The pointer to the buffer to fill.   @param[in]  Size              Number of bytes in Buffer to fill.   @param[in]  Value             Value to fill Buffer with.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SET_MEM
function_decl|)
parameter_list|(
name|IN
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|IN
name|UINTN
name|Size
parameter_list|,
name|IN
name|UINT8
name|Value
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of EFI Interface Types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Indicates that the supplied protocol interface is supplied in native form.
comment|///
name|EFI_NATIVE_INTERFACE
block|}
name|EFI_INTERFACE_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   Installs a protocol interface on a device handle. If the handle does not exist, it is created and added   to the list of handles in the system. InstallMultipleProtocolInterfaces() performs   more error checking than InstallProtocolInterface(), so it is recommended that   InstallMultipleProtocolInterfaces() be used in place of   InstallProtocolInterface()    @param[in, out]  Handle         A pointer to the EFI_HANDLE on which the interface is to be installed.   @param[in]       Protocol       The numeric ID of the protocol interface.   @param[in]       InterfaceType  Indicates whether Interface is supplied in native form.   @param[in]       Interface      A pointer to the protocol interface.    @retval EFI_SUCCESS           The protocol interface was installed.   @retval EFI_OUT_OF_RESOURCES  Space for a new handle could not be allocated.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Protocol is NULL.   @retval EFI_INVALID_PARAMETER InterfaceType is not EFI_NATIVE_INTERFACE.   @retval EFI_INVALID_PARAMETER Protocol is already installed on the handle specified by Handle.  **/
end_comment

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

begin_comment
comment|/**   Installs one or more protocol interfaces into the boot services environment.    @param[in, out]  Handle       The pointer to a handle to install the new protocol interfaces on,                                 or a pointer to NULL if a new handle is to be allocated.   @param  ...                   A variable argument list containing pairs of protocol GUIDs and protocol                                 interfaces.    @retval EFI_SUCCESS           All the protocol interface was installed.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory in pool to install all the protocols.   @retval EFI_ALREADY_STARTED   A Device Path Protocol instance was passed in that is already present in                                 the handle database.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Protocol is already installed on the handle specified by Handle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES
function_decl|)
parameter_list|(
name|IN
name|OUT
name|EFI_HANDLE
modifier|*
name|Handle
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Reinstalls a protocol interface on a device handle.    @param[in]  Handle            Handle on which the interface is to be reinstalled.   @param[in]  Protocol          The numeric ID of the interface.   @param[in]  OldInterface      A pointer to the old interface. NULL can be used if a structure is not                                 associated with Protocol.   @param[in]  NewInterface      A pointer to the new interface.    @retval EFI_SUCCESS           The protocol interface was reinstalled.   @retval EFI_NOT_FOUND         The OldInterface on the handle was not found.   @retval EFI_ACCESS_DENIED     The protocol interface could not be reinstalled,                                 because OldInterface is still being used by a                                 driver that will not release it.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Protocol is NULL.  **/
end_comment

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

begin_comment
comment|/**   Removes a protocol interface from a device handle. It is recommended that   UninstallMultipleProtocolInterfaces() be used in place of   UninstallProtocolInterface().    @param[in]  Handle            The handle on which the interface was installed.   @param[in]  Protocol          The numeric ID of the interface.   @param[in]  Interface         A pointer to the interface.    @retval EFI_SUCCESS           The interface was removed.   @retval EFI_NOT_FOUND         The interface was not found.   @retval EFI_ACCESS_DENIED     The interface was not removed because the interface                                 is still being used by a driver.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Protocol is NULL.  **/
end_comment

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

begin_comment
comment|/**   Removes one or more protocol interfaces into the boot services environment.    @param[in]  Handle            The handle to remove the protocol interfaces from.   @param  ...                   A variable argument list containing pairs of protocol GUIDs and                                 protocol interfaces.    @retval EFI_SUCCESS           All the protocol interfaces were removed.   @retval EFI_INVALID_PARAMETER One of the protocol interfaces was not previously installed on Handle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Queries a handle to determine if it supports a specified protocol.    @param[in]   Handle           The handle being queried.   @param[in]   Protocol         The published unique identifier of the protocol.   @param[out]  Interface        Supplies the address where a pointer to the corresponding Protocol                                 Interface is returned.    @retval EFI_SUCCESS           The interface information for the specified protocol was returned.   @retval EFI_UNSUPPORTED       The device does not support the specified protocol.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Protocol is NULL.   @retval EFI_INVALID_PARAMETER Interface is NULL.  **/
end_comment

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

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_GET_PROTOCOL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_TEST_PROTOCOL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_BY_DRIVER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_OPEN_PROTOCOL_EXCLUSIVE
value|0x00000020
end_define

begin_comment
comment|/**   Queries a handle to determine if it supports a specified protocol. If the protocol is supported by the   handle, it opens the protocol on behalf of the calling agent.    @param[in]   Handle           The handle for the protocol interface that is being opened.   @param[in]   Protocol         The published unique identifier of the protocol.   @param[out]  Interface        Supplies the address where a pointer to the corresponding Protocol                                 Interface is returned.   @param[in]   AgentHandle      The handle of the agent that is opening the protocol interface                                 specified by Protocol and Interface.   @param[in]   ControllerHandle If the agent that is opening a protocol is a driver that follows the                                 UEFI Driver Model, then this parameter is the controller handle                                 that requires the protocol interface. If the agent does not follow                                 the UEFI Driver Model, then this parameter is optional and may                                 be NULL.   @param[in]   Attributes       The open mode of the protocol interface specified by Handle                                 and Protocol.    @retval EFI_SUCCESS           An item was added to the open list for the protocol interface, and the                                 protocol interface was returned in Interface.   @retval EFI_UNSUPPORTED       Handle does not support Protocol.   @retval EFI_INVALID_PARAMETER One or more parameters are invalid.   @retval EFI_ACCESS_DENIED     Required attributes can't be supported in current environment.   @retval EFI_ALREADY_STARTED   Item on the open list already has requierd attributes whose agent                                 handle is the same as AgentHandle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_OPEN_PROTOCOL
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
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_HANDLE
name|AgentHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|UINT32
name|Attributes
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Closes a protocol on a handle that was opened using OpenProtocol().    @param[in]  Handle            The handle for the protocol interface that was previously opened                                 with OpenProtocol(), and is now being closed.   @param[in]  Protocol          The published unique identifier of the protocol.   @param[in]  AgentHandle       The handle of the agent that is closing the protocol interface.   @param[in]  ControllerHandle  If the agent that opened a protocol is a driver that follows the                                 UEFI Driver Model, then this parameter is the controller handle                                 that required the protocol interface.    @retval EFI_SUCCESS           The protocol instance was closed.   @retval EFI_INVALID_PARAMETER 1) Handle is NULL.                                 2) AgentHandle is NULL.                                 3) ControllerHandle is not NULL and ControllerHandle is not a valid EFI_HANDLE.                                 4) Protocol is NULL.   @retval EFI_NOT_FOUND         1) Handle does not support the protocol specified by Protocol.                                 2) The protocol interface specified by Handle and Protocol is not                                    currently open by AgentHandle and ControllerHandle.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_CLOSE_PROTOCOL
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
name|EFI_HANDLE
name|AgentHandle
parameter_list|,
name|IN
name|EFI_HANDLE
name|ControllerHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Oprn Protocol Information Entry
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HANDLE
name|AgentHandle
decl_stmt|;
name|EFI_HANDLE
name|ControllerHandle
decl_stmt|;
name|UINT32
name|Attributes
decl_stmt|;
name|UINT32
name|OpenCount
decl_stmt|;
block|}
name|EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
typedef|;
end_typedef

begin_comment
comment|/**   Retrieves the list of agents that currently have a protocol interface opened.    @param[in]   Handle           The handle for the protocol interface that is being queried.   @param[in]   Protocol         The published unique identifier of the protocol.   @param[out]  EntryBuffer      A pointer to a buffer of open protocol information in the form of                                 EFI_OPEN_PROTOCOL_INFORMATION_ENTRY structures.   @param[out]  EntryCount       A pointer to the number of entries in EntryBuffer.    @retval EFI_SUCCESS           The open protocol information was returned in EntryBuffer, and the                                 number of entries was returned EntryCount.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources available to allocate EntryBuffer.   @retval EFI_NOT_FOUND         Handle does not support the protocol specified by Protocol.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_OPEN_PROTOCOL_INFORMATION
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
name|EFI_OPEN_PROTOCOL_INFORMATION_ENTRY
modifier|*
modifier|*
name|EntryBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|EntryCount
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Retrieves the list of protocol interface GUIDs that are installed on a handle in a buffer allocated   from pool.    @param[in]   Handle              The handle from which to retrieve the list of protocol interface                                    GUIDs.   @param[out]  ProtocolBuffer      A pointer to the list of protocol interface GUID pointers that are                                    installed on Handle.   @param[out]  ProtocolBufferCount A pointer to the number of GUID pointers present in                                    ProtocolBuffer.    @retval EFI_SUCCESS           The list of protocol interface GUIDs installed on Handle was returned in                                 ProtocolBuffer. The number of protocol interface GUIDs was                                 returned in ProtocolBufferCount.   @retval EFI_OUT_OF_RESOURCES  There is not enough pool memory to store the results.   @retval EFI_INVALID_PARAMETER Handle is NULL.   @retval EFI_INVALID_PARAMETER Handle is not a valid EFI_HANDLE.   @retval EFI_INVALID_PARAMETER ProtocolBuffer is NULL.   @retval EFI_INVALID_PARAMETER ProtocolBufferCount is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PROTOCOLS_PER_HANDLE
function_decl|)
parameter_list|(
name|IN
name|EFI_HANDLE
name|Handle
parameter_list|,
name|OUT
name|EFI_GUID
modifier|*
modifier|*
modifier|*
name|ProtocolBuffer
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ProtocolBufferCount
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Creates an event that is to be signaled whenever an interface is installed for a specified protocol.    @param[in]   Protocol         The numeric ID of the protocol for which the event is to be registered.   @param[in]   Event            Event that is to be signaled whenever a protocol interface is registered                                 for Protocol.   @param[out]  Registration     A pointer to a memory location to receive the registration value.    @retval EFI_SUCCESS           The notification event has been registered.   @retval EFI_OUT_OF_RESOURCES  Space for the notification event could not be allocated.   @retval EFI_INVALID_PARAMETER Protocol is NULL.   @retval EFI_INVALID_PARAMETER Event is NULL.   @retval EFI_INVALID_PARAMETER Registration is NULL.  **/
end_comment

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

begin_comment
comment|///
end_comment

begin_comment
comment|/// Enumeration of EFI Locate Search Types
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Retrieve all the handles in the handle database.
comment|///
name|AllHandles
block|,
comment|///
comment|/// Retrieve the next handle fron a RegisterProtocolNotify() event.
comment|///
name|ByRegisterNotify
block|,
comment|///
comment|/// Retrieve the set of handles from the handle database that support a
comment|/// specified protocol.
comment|///
name|ByProtocol
block|}
name|EFI_LOCATE_SEARCH_TYPE
typedef|;
end_typedef

begin_comment
comment|/**   Returns an array of handles that support a specified protocol.    @param[in]       SearchType   Specifies which handle(s) are to be returned.   @param[in]       Protocol     Specifies the protocol to search by.   @param[in]       SearchKey    Specifies the search key.   @param[in, out]  BufferSize   On input, the size in bytes of Buffer. On output, the size in bytes of                                 the array returned in Buffer (if the buffer was large enough) or the                                 size, in bytes, of the buffer needed to obtain the array (if the buffer was                                 not large enough).   @param[out]      Buffer       The buffer in which the array is returned.    @retval EFI_SUCCESS           The array of handles was returned.   @retval EFI_NOT_FOUND         No handles match the search.   @retval EFI_BUFFER_TOO_SMALL  The BufferSize is too small for the result.   @retval EFI_INVALID_PARAMETER SearchType is not a member of EFI_LOCATE_SEARCH_TYPE.   @retval EFI_INVALID_PARAMETER SearchType is ByRegisterNotify and SearchKey is NULL.   @retval EFI_INVALID_PARAMETER SearchType is ByProtocol and Protocol is NULL.   @retval EFI_INVALID_PARAMETER One or more matches are found and BufferSize is NULL.   @retval EFI_INVALID_PARAMETER BufferSize is large enough for the result and Buffer is NULL.  **/
end_comment

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
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|SearchKey
parameter_list|,
name|OPTIONAL
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

begin_comment
comment|/**   Locates the handle to a device on the device path that supports the specified protocol.    @param[in]       Protocol     Specifies the protocol to search for.   @param[in, out]  DevicePath   On input, a pointer to a pointer to the device path. On output, the device                                 path pointer is modified to point to the remaining part of the device                                 path.   @param[out]      Device       A pointer to the returned device handle.    @retval EFI_SUCCESS           The resulting handle was returned.   @retval EFI_NOT_FOUND         No handles match the search.   @retval EFI_INVALID_PARAMETER Protocol is NULL.   @retval EFI_INVALID_PARAMETER DevicePath is NULL.   @retval EFI_INVALID_PARAMETER A handle matched the search and Device is NULL.  **/
end_comment

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
name|EFI_DEVICE_PATH_PROTOCOL
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

begin_comment
comment|/**   Adds, updates, or removes a configuration table entry from the EFI System Table.    @param[in]  Guid              A pointer to the GUID for the entry to add, update, or remove.   @param[in]  Table             A pointer to the configuration table for the entry to add, update, or                                 remove. May be NULL.    @retval EFI_SUCCESS           The (Guid, Table) pair was added, updated, or removed.   @retval EFI_NOT_FOUND         An attempt was made to delete a nonexistent entry.   @retval EFI_INVALID_PARAMETER Guid is NULL.   @retval EFI_OUT_OF_RESOURCES  There is not enough memory available to complete the operation.  **/
end_comment

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

begin_comment
comment|/**   Returns an array of handles that support the requested protocol in a buffer allocated from pool.    @param[in]       SearchType   Specifies which handle(s) are to be returned.   @param[in]       Protocol     Provides the protocol to search by.                                 This parameter is only valid for a SearchType of ByProtocol.   @param[in]       SearchKey    Supplies the search key depending on the SearchType.   @param[in, out]  NoHandles    The number of handles returned in Buffer.   @param[out]      Buffer       A pointer to the buffer to return the requested array of handles that                                 support Protocol.    @retval EFI_SUCCESS           The array of handles was returned in Buffer, and the number of                                 handles in Buffer was returned in NoHandles.   @retval EFI_NOT_FOUND         No handles match the search.   @retval EFI_OUT_OF_RESOURCES  There is not enough pool memory to store the matching results.   @retval EFI_INVALID_PARAMETER NoHandles is NULL.   @retval EFI_INVALID_PARAMETER Buffer is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOCATE_HANDLE_BUFFER
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
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|SearchKey
parameter_list|,
name|OPTIONAL
name|IN
name|OUT
name|UINTN
modifier|*
name|NoHandles
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
modifier|*
name|Buffer
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the first protocol instance that matches the given protocol.    @param[in]  Protocol          Provides the protocol to search for.   @param[in]  Registration      Optional registration key returned from                                 RegisterProtocolNotify().   @param[out]  Interface        On return, a pointer to the first interface that matches Protocol and                                 Registration.    @retval EFI_SUCCESS           A protocol instance matching Protocol was found and returned in                                 Interface.   @retval EFI_NOT_FOUND         No protocol instances were found that match Protocol and                                 Registration.   @retval EFI_INVALID_PARAMETER Interface is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_LOCATE_PROTOCOL
function_decl|)
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|Protocol
parameter_list|,
name|IN
name|VOID
modifier|*
name|Registration
parameter_list|,
name|OPTIONAL
name|OUT
name|VOID
modifier|*
modifier|*
name|Interface
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Capsule Block Descriptor
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Length in bytes of the data pointed to by DataBlock/ContinuationPointer.
comment|///
name|UINT64
name|Length
decl_stmt|;
union|union
block|{
comment|///
comment|/// Physical address of the data block. This member of the union is
comment|/// used if Length is not equal to zero.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|DataBlock
decl_stmt|;
comment|///
comment|/// Physical address of another block of
comment|/// EFI_CAPSULE_BLOCK_DESCRIPTOR structures. This
comment|/// member of the union is used if Length is equal to zero. If
comment|/// ContinuationPointer is zero this entry represents the end of the list.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|ContinuationPointer
decl_stmt|;
block|}
name|Union
union|;
block|}
name|EFI_CAPSULE_BLOCK_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Capsule Header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// A GUID that defines the contents of a capsule.
comment|///
name|EFI_GUID
name|CapsuleGuid
decl_stmt|;
comment|///
comment|/// The size of the capsule header. This may be larger than the size of
comment|/// the EFI_CAPSULE_HEADER since CapsuleGuid may imply
comment|/// extended header entries
comment|///
name|UINT32
name|HeaderSize
decl_stmt|;
comment|///
comment|/// Bit-mapped list describing the capsule attributes. The Flag values
comment|/// of 0x0000 - 0xFFFF are defined by CapsuleGuid. Flag values
comment|/// of 0x10000 - 0xFFFFFFFF are defined by this specification
comment|///
name|UINT32
name|Flags
decl_stmt|;
comment|///
comment|/// Size in bytes of the capsule.
comment|///
name|UINT32
name|CapsuleImageSize
decl_stmt|;
block|}
name|EFI_CAPSULE_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI System Table entry must point to an array of capsules
end_comment

begin_comment
comment|/// that contain the same CapsuleGuid value. The array must be
end_comment

begin_comment
comment|/// prefixed by a UINT32 that represents the size of the array of capsules.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// the size of the array of capsules.
comment|///
name|UINT32
name|CapsuleArrayNumber
decl_stmt|;
comment|///
comment|/// Point to an array of capsules that contain the same CapsuleGuid value.
comment|///
name|VOID
modifier|*
name|CapsulePtr
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_CAPSULE_TABLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CAPSULE_FLAGS_PERSIST_ACROSS_RESET
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CAPSULE_FLAGS_INITIATE_RESET
value|0x00040000
end_define

begin_comment
comment|/**   Passes capsules to the firmware with both virtual and physical mapping. Depending on the intended   consumption, the firmware may process the capsule immediately. If the payload should persist   across a system reset, the reset value returned from EFI_QueryCapsuleCapabilities must   be passed into ResetSystem() and will cause the capsule to be processed by the firmware as   part of the reset process.    @param[in]  CapsuleHeaderArray Virtual pointer to an array of virtual pointers to the capsules                                  being passed into update capsule.   @param[in]  CapsuleCount       Number of pointers to EFI_CAPSULE_HEADER in                                  CaspuleHeaderArray.   @param[in]  ScatterGatherList  Physical pointer to a set of                                  EFI_CAPSULE_BLOCK_DESCRIPTOR that describes the                                  location in physical memory of a set of capsules.    @retval EFI_SUCCESS           Valid capsule was passed. If                                 CAPSULE_FLAGS_PERSIT_ACROSS_RESET is not set, the                                 capsule has been successfully processed by the firmware.   @retval EFI_INVALID_PARAMETER CapsuleSize is NULL, or an incompatible set of flags were                                 set in the capsule header.   @retval EFI_INVALID_PARAMETER CapsuleCount is 0.   @retval EFI_DEVICE_ERROR      The capsule update was started, but failed due to a device error.   @retval EFI_UNSUPPORTED       The capsule type is not supported on this platform.   @retval EFI_OUT_OF_RESOURCES  When ExitBootServices() has been previously called this error indicates the capsule                                  is compatible with this platform but is not capable of being submitted or processed                                  in runtime. The caller may resubmit the capsule prior to ExitBootServices().   @retval EFI_OUT_OF_RESOURCES  When ExitBootServices() has not been previously called then this error indicates                                  the capsule is compatible with this platform but there are insufficient resources to process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_UPDATE_CAPSULE
function_decl|)
parameter_list|(
name|IN
name|EFI_CAPSULE_HEADER
modifier|*
modifier|*
name|CapsuleHeaderArray
parameter_list|,
name|IN
name|UINTN
name|CapsuleCount
parameter_list|,
name|IN
name|EFI_PHYSICAL_ADDRESS
name|ScatterGatherList
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns if the capsule can be supported via UpdateCapsule().    @param[in]   CapsuleHeaderArray  Virtual pointer to an array of virtual pointers to the capsules                                    being passed into update capsule.   @param[in]   CapsuleCount        Number of pointers to EFI_CAPSULE_HEADER in                                    CaspuleHeaderArray.   @param[out]  MaxiumCapsuleSize   On output the maximum size that UpdateCapsule() can                                    support as an argument to UpdateCapsule() via                                    CapsuleHeaderArray and ScatterGatherList.   @param[out]  ResetType           Returns the type of reset required for the capsule update.    @retval EFI_SUCCESS           Valid answer returned.   @retval EFI_UNSUPPORTED       The capsule type is not supported on this platform, and                                 MaximumCapsuleSize and ResetType are undefined.   @retval EFI_INVALID_PARAMETER MaximumCapsuleSize is NULL.   @retval EFI_OUT_OF_RESOURCES  When ExitBootServices() has been previously called this error indicates the capsule                                  is compatible with this platform but is not capable of being submitted or processed                                  in runtime. The caller may resubmit the capsule prior to ExitBootServices().   @retval EFI_OUT_OF_RESOURCES  When ExitBootServices() has not been previously called then this error indicates                                  the capsule is compatible with this platform but there are insufficient resources to process.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_QUERY_CAPSULE_CAPABILITIES
function_decl|)
parameter_list|(
name|IN
name|EFI_CAPSULE_HEADER
modifier|*
modifier|*
name|CapsuleHeaderArray
parameter_list|,
name|IN
name|UINTN
name|CapsuleCount
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|MaximumCapsuleSize
parameter_list|,
name|OUT
name|EFI_RESET_TYPE
modifier|*
name|ResetType
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns information about the EFI variables.    @param[in]   Attributes                   Attributes bitmask to specify the type of variables on                                             which to return information.   @param[out]  MaximumVariableStorageSize   On output the maximum size of the storage space                                             available for the EFI variables associated with the                                             attributes specified.   @param[out]  RemainingVariableStorageSize Returns the remaining size of the storage space                                             available for the EFI variables associated with the                                             attributes specified.   @param[out]  MaximumVariableSize          Returns the maximum size of the individual EFI                                             variables associated with the attributes specified.    @retval EFI_SUCCESS                  Valid answer returned.   @retval EFI_INVALID_PARAMETER        An invalid combination of attribute bits was supplied   @retval EFI_UNSUPPORTED              The attribute is not supported on this platform, and the                                        MaximumVariableStorageSize,                                        RemainingVariableStorageSize, MaximumVariableSize                                        are undefined.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_QUERY_VARIABLE_INFO
function_decl|)
parameter_list|(
name|IN
name|UINT32
name|Attributes
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|MaximumVariableStorageSize
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|RemainingVariableStorageSize
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|MaximumVariableSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Firmware should stop at a firmware user interface on next boot
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_BOOT_TO_FW_UI
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_TIMESTAMP_REVOCATION
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_FILE_CAPSULE_DELIVERY_SUPPORTED
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_FMP_CAPSULE_SUPPORTED
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_CAPSULE_RESULT_VAR_SUPPORTED
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|EFI_OS_INDICATIONS_START_PLATFORM_RECOVERY
value|0x0000000000000040
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Runtime Services Table
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_SYSTEM_TABLE_SIGNATURE
value|SIGNATURE_64 ('I','B','I',' ','S','Y','S','T')
end_define

begin_define
define|#
directive|define
name|EFI_2_60_SYSTEM_TABLE_REVISION
value|((2<< 16) | (60))
end_define

begin_define
define|#
directive|define
name|EFI_2_50_SYSTEM_TABLE_REVISION
value|((2<< 16) | (50))
end_define

begin_define
define|#
directive|define
name|EFI_2_40_SYSTEM_TABLE_REVISION
value|((2<< 16) | (40))
end_define

begin_define
define|#
directive|define
name|EFI_2_31_SYSTEM_TABLE_REVISION
value|((2<< 16) | (31))
end_define

begin_define
define|#
directive|define
name|EFI_2_30_SYSTEM_TABLE_REVISION
value|((2<< 16) | (30))
end_define

begin_define
define|#
directive|define
name|EFI_2_20_SYSTEM_TABLE_REVISION
value|((2<< 16) | (20))
end_define

begin_define
define|#
directive|define
name|EFI_2_10_SYSTEM_TABLE_REVISION
value|((2<< 16) | (10))
end_define

begin_define
define|#
directive|define
name|EFI_2_00_SYSTEM_TABLE_REVISION
value|((2<< 16) | (00))
end_define

begin_define
define|#
directive|define
name|EFI_1_10_SYSTEM_TABLE_REVISION
value|((1<< 16) | (10))
end_define

begin_define
define|#
directive|define
name|EFI_1_02_SYSTEM_TABLE_REVISION
value|((1<< 16) | (02))
end_define

begin_define
define|#
directive|define
name|EFI_SYSTEM_TABLE_REVISION
value|EFI_2_60_SYSTEM_TABLE_REVISION
end_define

begin_define
define|#
directive|define
name|EFI_SPECIFICATION_VERSION
value|EFI_SYSTEM_TABLE_REVISION
end_define

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_SIGNATURE
value|SIGNATURE_64 ('R','U','N','T','S','E','R','V')
end_define

begin_define
define|#
directive|define
name|EFI_RUNTIME_SERVICES_REVISION
value|EFI_SPECIFICATION_VERSION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Runtime Services Table.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The table header for the EFI Runtime Services Table.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// Time Services
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
comment|// Virtual Memory Services
comment|//
name|EFI_SET_VIRTUAL_ADDRESS_MAP
name|SetVirtualAddressMap
decl_stmt|;
name|EFI_CONVERT_POINTER
name|ConvertPointer
decl_stmt|;
comment|//
comment|// Variable Services
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
comment|// Miscellaneous Services
comment|//
name|EFI_GET_NEXT_HIGH_MONO_COUNT
name|GetNextHighMonotonicCount
decl_stmt|;
name|EFI_RESET_SYSTEM
name|ResetSystem
decl_stmt|;
comment|//
comment|// UEFI 2.0 Capsule Services
comment|//
name|EFI_UPDATE_CAPSULE
name|UpdateCapsule
decl_stmt|;
name|EFI_QUERY_CAPSULE_CAPABILITIES
name|QueryCapsuleCapabilities
decl_stmt|;
comment|//
comment|// Miscellaneous UEFI 2.0 Service
comment|//
name|EFI_QUERY_VARIABLE_INFO
name|QueryVariableInfo
decl_stmt|;
block|}
name|EFI_RUNTIME_SERVICES
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_SIGNATURE
value|SIGNATURE_64 ('B','O','O','T','S','E','R','V')
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SERVICES_REVISION
value|EFI_SPECIFICATION_VERSION
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Boot Services Table.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The table header for the EFI Boot Services Table.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|//
comment|// Task Priority Services
comment|//
name|EFI_RAISE_TPL
name|RaiseTPL
decl_stmt|;
name|EFI_RESTORE_TPL
name|RestoreTPL
decl_stmt|;
comment|//
comment|// Memory Services
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
comment|// Event& Timer Services
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
comment|// Protocol Handler Services
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
name|VOID
modifier|*
name|Reserved
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
comment|// Image Services
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
comment|// Miscellaneous Services
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
comment|//
comment|// DriverSupport Services
comment|//
name|EFI_CONNECT_CONTROLLER
name|ConnectController
decl_stmt|;
name|EFI_DISCONNECT_CONTROLLER
name|DisconnectController
decl_stmt|;
comment|//
comment|// Open and Close Protocol Services
comment|//
name|EFI_OPEN_PROTOCOL
name|OpenProtocol
decl_stmt|;
name|EFI_CLOSE_PROTOCOL
name|CloseProtocol
decl_stmt|;
name|EFI_OPEN_PROTOCOL_INFORMATION
name|OpenProtocolInformation
decl_stmt|;
comment|//
comment|// Library Services
comment|//
name|EFI_PROTOCOLS_PER_HANDLE
name|ProtocolsPerHandle
decl_stmt|;
name|EFI_LOCATE_HANDLE_BUFFER
name|LocateHandleBuffer
decl_stmt|;
name|EFI_LOCATE_PROTOCOL
name|LocateProtocol
decl_stmt|;
name|EFI_INSTALL_MULTIPLE_PROTOCOL_INTERFACES
name|InstallMultipleProtocolInterfaces
decl_stmt|;
name|EFI_UNINSTALL_MULTIPLE_PROTOCOL_INTERFACES
name|UninstallMultipleProtocolInterfaces
decl_stmt|;
comment|//
comment|// 32-bit CRC Services
comment|//
name|EFI_CALCULATE_CRC32
name|CalculateCrc32
decl_stmt|;
comment|//
comment|// Miscellaneous Services
comment|//
name|EFI_COPY_MEM
name|CopyMem
decl_stmt|;
name|EFI_SET_MEM
name|SetMem
decl_stmt|;
name|EFI_CREATE_EVENT_EX
name|CreateEventEx
decl_stmt|;
block|}
name|EFI_BOOT_SERVICES
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Contains a set of GUID/pointer pairs comprised of the ConfigurationTable field in the
end_comment

begin_comment
comment|/// EFI System Table.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The 128-bit GUID value that uniquely identifies the system configuration table.
comment|///
name|EFI_GUID
name|VendorGuid
decl_stmt|;
comment|///
comment|/// A pointer to the table associated with VendorGuid.
comment|///
name|VOID
modifier|*
name|VendorTable
decl_stmt|;
block|}
name|EFI_CONFIGURATION_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI System Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The table header for the EFI System Table.
comment|///
name|EFI_TABLE_HEADER
name|Hdr
decl_stmt|;
comment|///
comment|/// A pointer to a null terminated string that identifies the vendor
comment|/// that produces the system firmware for the platform.
comment|///
name|CHAR16
modifier|*
name|FirmwareVendor
decl_stmt|;
comment|///
comment|/// A firmware vendor specific value that identifies the revision
comment|/// of the system firmware for the platform.
comment|///
name|UINT32
name|FirmwareRevision
decl_stmt|;
comment|///
comment|/// The handle for the active console input device. This handle must support
comment|/// EFI_SIMPLE_TEXT_INPUT_PROTOCOL and EFI_SIMPLE_TEXT_INPUT_EX_PROTOCOL.
comment|///
name|EFI_HANDLE
name|ConsoleInHandle
decl_stmt|;
comment|///
comment|/// A pointer to the EFI_SIMPLE_TEXT_INPUT_PROTOCOL interface that is
comment|/// associated with ConsoleInHandle.
comment|///
name|EFI_SIMPLE_TEXT_INPUT_PROTOCOL
modifier|*
name|ConIn
decl_stmt|;
comment|///
comment|/// The handle for the active console output device.
comment|///
name|EFI_HANDLE
name|ConsoleOutHandle
decl_stmt|;
comment|///
comment|/// A pointer to the EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL interface
comment|/// that is associated with ConsoleOutHandle.
comment|///
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|ConOut
decl_stmt|;
comment|///
comment|/// The handle for the active standard error console device.
comment|/// This handle must support the EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL.
comment|///
name|EFI_HANDLE
name|StandardErrorHandle
decl_stmt|;
comment|///
comment|/// A pointer to the EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL interface
comment|/// that is associated with StandardErrorHandle.
comment|///
name|EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL
modifier|*
name|StdErr
decl_stmt|;
comment|///
comment|/// A pointer to the EFI Runtime Services Table.
comment|///
name|EFI_RUNTIME_SERVICES
modifier|*
name|RuntimeServices
decl_stmt|;
comment|///
comment|/// A pointer to the EFI Boot Services Table.
comment|///
name|EFI_BOOT_SERVICES
modifier|*
name|BootServices
decl_stmt|;
comment|///
comment|/// The number of system configuration tables in the buffer ConfigurationTable.
comment|///
name|UINTN
name|NumberOfTableEntries
decl_stmt|;
comment|///
comment|/// A pointer to the system configuration tables.
comment|/// The number of entries in the table is NumberOfTableEntries.
comment|///
name|EFI_CONFIGURATION_TABLE
modifier|*
name|ConfigurationTable
decl_stmt|;
block|}
name|EFI_SYSTEM_TABLE
typedef|;
end_typedef

begin_comment
comment|/**   This is the declaration of an EFI image entry point. This entry point is   the same for UEFI Applications, UEFI OS Loaders, and UEFI Drivers including   both device drivers and bus drivers.    @param[in]  ImageHandle       The firmware allocated handle for the UEFI image.   @param[in]  SystemTable       A pointer to the EFI System Table.    @retval EFI_SUCCESS           The operation completed successfully.   @retval Others                An unexpected error occurred. **/
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
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Load Option. This data structure describes format of UEFI boot option variables.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// NOTE: EFI Load Option is a byte packed buffer of variable length fields.
end_comment

begin_comment
comment|// The first two fields have fixed length. They are declared as members of the
end_comment

begin_comment
comment|// EFI_LOAD_OPTION structure. All the other fields are variable length fields.
end_comment

begin_comment
comment|// They are listed in the comment block below for reference purposes.
end_comment

begin_comment
comment|//
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|_EFI_LOAD_OPTION
block|{
comment|///
comment|/// The attributes for this load option entry. All unused bits must be zero
comment|/// and are reserved by the UEFI specification for future growth.
comment|///
name|UINT32
name|Attributes
decl_stmt|;
comment|///
comment|/// Length in bytes of the FilePathList. OptionalData starts at offset
comment|/// sizeof(UINT32) + sizeof(UINT16) + StrSize(Description) + FilePathListLength
comment|/// of the EFI_LOAD_OPTION descriptor.
comment|///
name|UINT16
name|FilePathListLength
decl_stmt|;
comment|///
comment|/// The user readable description for the load option.
comment|/// This field ends with a Null character.
comment|///
comment|// CHAR16                        Description[];
comment|///
comment|/// A packed array of UEFI device paths. The first element of the array is a
comment|/// device path that describes the device and location of the Image for this
comment|/// load option. The FilePathList[0] is specific to the device type. Other
comment|/// device paths may optionally exist in the FilePathList, but their usage is
comment|/// OSV specific. Each element in the array is variable length, and ends at
comment|/// the device path end structure. Because the size of Description is
comment|/// arbitrary, this data structure is not guaranteed to be aligned on a
comment|/// natural boundary. This data structure may have to be copied to an aligned
comment|/// natural boundary before it is used.
comment|///
comment|// EFI_DEVICE_PATH_PROTOCOL      FilePathList[];
comment|///
comment|/// The remaining bytes in the load option descriptor are a binary data buffer
comment|/// that is passed to the loaded image. If the field is zero bytes long, a
comment|/// NULL pointer is passed to the loaded image. The number of bytes in
comment|/// OptionalData can be computed by subtracting the starting offset of
comment|/// OptionalData from total size in bytes of the EFI_LOAD_OPTION.
comment|///
comment|// UINT8                         OptionalData[];
block|}
name|EFI_LOAD_OPTION
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI Load Options Attributes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|LOAD_OPTION_ACTIVE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LOAD_OPTION_FORCE_RECONNECT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LOAD_OPTION_HIDDEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LOAD_OPTION_CATEGORY
value|0x00001F00
end_define

begin_define
define|#
directive|define
name|LOAD_OPTION_CATEGORY_BOOT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LOAD_OPTION_CATEGORY_APP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_OPTION_SUPPORT_KEY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_OPTION_SUPPORT_APP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_OPTION_SUPPORT_SYSPREP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_OPTION_SUPPORT_COUNT
value|0x00000300
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Boot Key Data
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
comment|///
comment|/// Indicates the revision of the EFI_KEY_OPTION structure. This revision level should be 0.
comment|///
name|UINT32
name|Revision
range|:
literal|8
decl_stmt|;
comment|///
comment|/// Either the left or right Shift keys must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|ShiftPressed
range|:
literal|1
decl_stmt|;
comment|///
comment|/// Either the left or right Control keys must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|ControlPressed
range|:
literal|1
decl_stmt|;
comment|///
comment|/// Either the left or right Alt keys must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|AltPressed
range|:
literal|1
decl_stmt|;
comment|///
comment|/// Either the left or right Logo keys must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|LogoPressed
range|:
literal|1
decl_stmt|;
comment|///
comment|/// The Menu key must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|MenuPressed
range|:
literal|1
decl_stmt|;
comment|///
comment|/// The SysReq key must be pressed (1) or must not be pressed (0).
comment|///
name|UINT32
name|SysReqPressed
range|:
literal|1
decl_stmt|;
name|UINT32
name|Reserved
range|:
literal|16
decl_stmt|;
comment|///
comment|/// Specifies the actual number of entries in EFI_KEY_OPTION.Keys, from 0-3. If
comment|/// zero, then only the shift state is considered. If more than one, then the boot option will
comment|/// only be launched if all of the specified keys are pressed with the same shift state.
comment|///
name|UINT32
name|InputKeyCount
range|:
literal|2
decl_stmt|;
block|}
name|Options
struct|;
name|UINT32
name|PackedValue
decl_stmt|;
block|}
name|EFI_BOOT_KEY_DATA
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Key Option.
end_comment

begin_comment
comment|///
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Specifies options about how the key will be processed.
comment|///
name|EFI_BOOT_KEY_DATA
name|KeyData
decl_stmt|;
comment|///
comment|/// The CRC-32 which should match the CRC-32 of the entire EFI_LOAD_OPTION to
comment|/// which BootOption refers. If the CRC-32s do not match this value, then this key
comment|/// option is ignored.
comment|///
name|UINT32
name|BootOptionCrc
decl_stmt|;
comment|///
comment|/// The Boot#### option which will be invoked if this key is pressed and the boot option
comment|/// is active (LOAD_OPTION_ACTIVE is set).
comment|///
name|UINT16
name|BootOption
decl_stmt|;
comment|///
comment|/// The key codes to compare against those returned by the
comment|/// EFI_SIMPLE_TEXT_INPUT and EFI_SIMPLE_TEXT_INPUT_EX protocols.
comment|/// The number of key codes (0-3) is specified by the EFI_KEY_CODE_COUNT field in KeyOptions.
comment|///
comment|//EFI_INPUT_KEY      Keys[];
block|}
name|EFI_KEY_OPTION
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI File location to boot from on removable media devices
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME_IA32
value|L"\\EFI\\BOOT\\BOOTIA32.EFI"
end_define

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME_IA64
value|L"\\EFI\\BOOT\\BOOTIA64.EFI"
end_define

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME_X64
value|L"\\EFI\\BOOT\\BOOTX64.EFI"
end_define

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME_ARM
value|L"\\EFI\\BOOT\\BOOTARM.EFI"
end_define

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64
value|L"\\EFI\\BOOT\\BOOTAA64.EFI"
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MDE_CPU_IA32
argument_list|)
end_if

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME
value|EFI_REMOVABLE_MEDIA_FILE_NAME_IA32
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_IPF
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME
value|EFI_REMOVABLE_MEDIA_FILE_NAME_IA64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_X64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME
value|EFI_REMOVABLE_MEDIA_FILE_NAME_X64
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_EBC
argument_list|)
end_elif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_ARM
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME
value|EFI_REMOVABLE_MEDIA_FILE_NAME_ARM
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|MDE_CPU_AARCH64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EFI_REMOVABLE_MEDIA_FILE_NAME
value|EFI_REMOVABLE_MEDIA_FILE_NAME_AARCH64
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Unknown Processor Type
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<Uefi/UefiPxe.h>
end_include

begin_include
include|#
directive|include
file|<Uefi/UefiGpt.h>
end_include

begin_include
include|#
directive|include
file|<Uefi/UefiInternalFormRepresentation.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

end_unit

