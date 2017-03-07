begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library functions for common UEFI operations. Only available to DXE   and UEFI module types.    The UEFI Library provides functions and macros that simplify the development of    UEFI Drivers and UEFI Applications.  These functions and macros help manage EFI    events, build simple locks utilizing EFI Task Priority Levels (TPLs), install    EFI Driver Model related protocols, manage Unicode string tables for UEFI Drivers,    and print messages on the console output and standard error devices.    Note that a reserved macro named MDEPKG_NDEBUG is introduced for the intention   of size reduction when compiler optimization is disabled. If MDEPKG_NDEBUG is   defined, then debug and assert related macros wrapped by it are the NULL implementations.  Copyright (c) 2006 - 2017, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_LIB_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/DriverBinding.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverConfiguration.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/ComponentName.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/ComponentName2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverDiagnostics.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/DriverDiagnostics2.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Unicode String Table
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CHAR8
modifier|*
name|Language
decl_stmt|;
name|CHAR16
modifier|*
name|UnicodeString
decl_stmt|;
block|}
name|EFI_UNICODE_STRING_TABLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Lock Status
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiLockUninitialized
init|=
literal|0
block|,
name|EfiLockReleased
init|=
literal|1
block|,
name|EfiLockAcquired
init|=
literal|2
block|}
name|EFI_LOCK_STATE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI Lock
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_TPL
name|Tpl
decl_stmt|;
name|EFI_TPL
name|OwnerTpl
decl_stmt|;
name|EFI_LOCK_STATE
name|Lock
decl_stmt|;
block|}
name|EFI_LOCK
typedef|;
end_typedef

begin_comment
comment|/**   Macro that returns the number of 100 ns units for a specified number of microseconds.   This is useful for managing EFI timer events.    @param  Microseconds           The number of microseconds.    @return The number of 100 ns units equivalent to the number of microseconds specified           by Microseconds.  **/
end_comment

begin_define
define|#
directive|define
name|EFI_TIMER_PERIOD_MICROSECONDS
parameter_list|(
name|Microseconds
parameter_list|)
value|MultU64x32((UINT64)(Microseconds), 10)
end_define

begin_comment
comment|/**   Macro that returns the number of 100 ns units for a specified number of milliseconds.   This is useful for managing EFI timer events.    @param  Milliseconds           The number of milliseconds.    @return The number of 100 ns units equivalent to the number of milliseconds specified           by Milliseconds.  **/
end_comment

begin_define
define|#
directive|define
name|EFI_TIMER_PERIOD_MILLISECONDS
parameter_list|(
name|Milliseconds
parameter_list|)
value|MultU64x32((UINT64)(Milliseconds), 10000)
end_define

begin_comment
comment|/**   Macro that returns the number of 100 ns units for a specified number of seconds.   This is useful for managing EFI timer events.    @param  Seconds                The number of seconds.    @return The number of 100 ns units equivalent to the number of seconds specified           by Seconds.  **/
end_comment

begin_define
define|#
directive|define
name|EFI_TIMER_PERIOD_SECONDS
parameter_list|(
name|Seconds
parameter_list|)
value|MultU64x32((UINT64)(Seconds), 10000000)
end_define

begin_comment
comment|/**   Macro that returns the a pointer to the next EFI_MEMORY_DESCRIPTOR in an array    returned from GetMemoryMap().      @param  MemoryDescriptor  A pointer to an EFI_MEMORY_DESCRIPTOR.    @param  Size              The size, in bytes, of the current EFI_MEMORY_DESCRIPTOR.    @return A pointer to the next EFI_MEMORY_DESCRIPTOR.  **/
end_comment

begin_define
define|#
directive|define
name|NEXT_MEMORY_DESCRIPTOR
parameter_list|(
name|MemoryDescriptor
parameter_list|,
name|Size
parameter_list|)
define|\
value|((EFI_MEMORY_DESCRIPTOR *)((UINT8 *)(MemoryDescriptor) + (Size)))
end_define

begin_comment
comment|/**   Retrieves a pointer to the system configuration table from the EFI System Table   based on a specified GUID.      This function searches the list of configuration tables stored in the EFI System Table   for a table with a GUID that matches TableGuid. If a match is found, then a pointer to   the configuration table is returned in Table, and EFI_SUCCESS is returned. If a matching GUID   is not found, then EFI_NOT_FOUND is returned.   If TableGuid is NULL, then ASSERT().   If Table is NULL, then ASSERT().    @param  TableGuid       The pointer to table's GUID type..   @param  Table           The pointer to the table associated with TableGuid in the EFI System Table.    @retval EFI_SUCCESS     A configuration table matching TableGuid was found.   @retval EFI_NOT_FOUND   A configuration table matching TableGuid could not be found.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiGetSystemConfigurationTable
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|TableGuid
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates and returns a notification event and registers that event with all the protocol   instances specified by ProtocolGuid.    This function causes the notification function to be executed for every protocol of type   ProtocolGuid instance that exists in the system when this function is invoked. If there are   no instances of ProtocolGuid in the handle database at the time this function is invoked,   then the notification function is still executed one time. In addition, every time a protocol   of type ProtocolGuid instance is installed or reinstalled, the notification function is also   executed. This function returns the notification event that was created.    If ProtocolGuid is NULL, then ASSERT().   If NotifyTpl is not a legal TPL value, then ASSERT().   If NotifyFunction is NULL, then ASSERT().   If Registration is NULL, then ASSERT().     @param  ProtocolGuid    Supplies GUID of the protocol upon whose installation the event is fired.   @param  NotifyTpl       Supplies the task priority level of the event notifications.   @param  NotifyFunction  Supplies the function to notify when the event is signaled.   @param  NotifyContext   The context parameter to pass to NotifyFunction.   @param  Registration    A pointer to a memory location to receive the registration value.                           This value is passed to LocateHandle() to obtain new handles that                           have been added that support the ProtocolGuid-specified protocol.     @return The notification event that was created.  **/
end_comment

begin_function_decl
name|EFI_EVENT
name|EFIAPI
name|EfiCreateProtocolNotifyEvent
parameter_list|(
name|IN
name|EFI_GUID
modifier|*
name|ProtocolGuid
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
name|OPTIONAL
name|OUT
name|VOID
modifier|*
modifier|*
name|Registration
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates a named event that can be signaled with EfiNamedEventSignal().    This function creates an event using NotifyTpl, NoifyFunction, and NotifyContext.   This event is signaled with EfiNamedEventSignal(). This provides the ability for one or more   listeners on the same event named by the GUID specified by Name.    If Name is NULL, then ASSERT().   If NotifyTpl is not a legal TPL value, then ASSERT().   If NotifyFunction is NULL, then ASSERT().    @param  Name                  Supplies GUID name of the event.   @param  NotifyTpl             Supplies the task priority level of the event notifications.   @param  NotifyFunction        Supplies the function to notify when the event is signaled.   @param  NotifyContext         The context parameter to pass to NotifyFunction.    @param  Registration          A pointer to a memory location to receive the registration value.    @retval EFI_SUCCESS           A named event was created.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to create the named event.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiNamedEventListen
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Name
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
name|CONST
name|VOID
modifier|*
name|NotifyContext
parameter_list|,
name|OPTIONAL
name|OUT
name|VOID
modifier|*
name|Registration
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Signals a named event created with EfiNamedEventListen().    This function signals the named event specified by Name. The named event must have been   created with EfiNamedEventListen().   If Name is NULL, then ASSERT().    @param  Name                  Supplies the GUID name of the event.    @retval EFI_SUCCESS           A named event was signaled.   @retval EFI_OUT_OF_RESOURCES  There are not enough resources to signal the named event.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiNamedEventSignal
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Signals an event group by placing a new event in the group temporarily and   signaling it.    @param[in] EventGroup          Supplies the unique identifier of the event                                  group to signal.    @retval EFI_SUCCESS            The event group was signaled successfully.   @retval EFI_INVALID_PARAMETER  EventGroup is NULL.   @return                        Error codes that report problems about event                                  creation or signaling. **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiEventGroupSignal
parameter_list|(
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|EventGroup
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   An empty function that can be used as NotifyFunction parameter of   CreateEvent() or CreateEventEx().    @param Event              Event whose notification function is being invoked.   @param Context            The pointer to the notification function's context,                             which is implementation-dependent.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiEventEmptyFunction
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
end_function_decl

begin_comment
comment|/**    Returns the current TPL.    This function returns the current TPL.  There is no EFI service to directly    retrieve the current TPL. Instead, the RaiseTPL() function is used to raise    the TPL to TPL_HIGH_LEVEL.  This will return the current TPL.  The TPL level    can then immediately be restored back to the current TPL level with a call    to RestoreTPL().    @return The current TPL.  **/
end_comment

begin_function_decl
name|EFI_TPL
name|EFIAPI
name|EfiGetCurrentTpl
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Initializes a basic mutual exclusion lock.    This function initializes a basic mutual exclusion lock to the released state    and returns the lock.  Each lock provides mutual exclusion access at its task    priority level.  Since there is no preemption or multiprocessor support in EFI,   acquiring the lock only consists of raising to the locks TPL.   If Lock is NULL, then ASSERT().   If Priority is not a valid TPL value, then ASSERT().    @param  Lock       A pointer to the lock data structure to initialize.   @param  Priority   The EFI TPL associated with the lock.    @return The lock.  **/
end_comment

begin_function_decl
name|EFI_LOCK
modifier|*
name|EFIAPI
name|EfiInitializeLock
parameter_list|(
name|IN
name|OUT
name|EFI_LOCK
modifier|*
name|Lock
parameter_list|,
name|IN
name|EFI_TPL
name|Priority
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Initializes a basic mutual exclusion lock.    This macro initializes the contents of a basic mutual exclusion lock to the    released state.  Each lock provides mutual exclusion access at its task    priority level.  Since there is no preemption or multiprocessor support in EFI,   acquiring the lock only consists of raising to the locks TPL.    @param  Priority  The task priority level of the lock.    @return The lock.  **/
end_comment

begin_define
define|#
directive|define
name|EFI_INITIALIZE_LOCK_VARIABLE
parameter_list|(
name|Priority
parameter_list|)
define|\
value|{Priority, TPL_APPLICATION, EfiLockReleased }
end_define

begin_comment
comment|/**   Macro that calls DebugAssert() if an EFI_LOCK structure is not in the locked state.    If MDEPKG_NDEBUG is not defined and the DEBUG_PROPERTY_DEBUG_ASSERT_ENABLED    bit of PcdDebugProperyMask is set, then this macro evaluates the EFI_LOCK    structure specified by Lock.  If Lock is not in the locked state, then   DebugAssert() is called passing in the source filename, source line number,    and Lock.    If Lock is NULL, then ASSERT().    @param  LockParameter  A pointer to the lock to acquire.  **/
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MDEPKG_NDEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASSERT_LOCKED
parameter_list|(
name|LockParameter
parameter_list|)
define|\
value|do {                                                \       if (DebugAssertEnabled ()) {                      \         ASSERT (LockParameter != NULL);                 \         if ((LockParameter)->Lock != EfiLockAcquired) { \           _ASSERT (LockParameter not locked);           \         }                                               \       }                                                 \     } while (FALSE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_LOCKED
parameter_list|(
name|LockParameter
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Acquires ownership of a lock.    This function raises the system's current task priority level to the task    priority level of the mutual exclusion lock.  Then, it places the lock in the    acquired state.   If Lock is NULL, then ASSERT().   If Lock is not initialized, then ASSERT().   If Lock is already in the acquired state, then ASSERT().    @param  Lock              A pointer to the lock to acquire.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiAcquireLock
parameter_list|(
name|IN
name|EFI_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Acquires ownership of a lock.    This function raises the system's current task priority level to the task priority   level of the mutual exclusion lock.  Then, it attempts to place the lock in the acquired state.   If the lock is already in the acquired state, then EFI_ACCESS_DENIED is returned.   Otherwise, EFI_SUCCESS is returned.   If Lock is NULL, then ASSERT().   If Lock is not initialized, then ASSERT().    @param  Lock              A pointer to the lock to acquire.    @retval EFI_SUCCESS       The lock was acquired.   @retval EFI_ACCESS_DENIED The lock could not be acquired because it is already owned.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiAcquireLockOrFail
parameter_list|(
name|IN
name|EFI_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Releases ownership of a lock.    This function transitions a mutual exclusion lock from the acquired state to    the released state, and restores the system's task priority level to its    previous level.   If Lock is NULL, then ASSERT().   If Lock is not initialized, then ASSERT().   If Lock is already in the released state, then ASSERT().    @param  Lock  A pointer to the lock to release.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiReleaseLock
parameter_list|(
name|IN
name|EFI_LOCK
modifier|*
name|Lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Tests whether a controller handle is being managed by a specific driver.    This function tests whether the driver specified by DriverBindingHandle is   currently managing the controller specified by ControllerHandle.  This test   is performed by evaluating if the the protocol specified by ProtocolGuid is   present on ControllerHandle and is was opened by DriverBindingHandle with an   attribute of EFI_OPEN_PROTOCOL_BY_DRIVER.    If ProtocolGuid is NULL, then ASSERT().    @param  ControllerHandle     A handle for a controller to test.   @param  DriverBindingHandle  Specifies the driver binding handle for the                                driver.   @param  ProtocolGuid         Specifies the protocol that the driver specified                                by DriverBindingHandle opens in its Start()                                function.    @retval EFI_SUCCESS          ControllerHandle is managed by the driver                                specified by DriverBindingHandle.   @retval EFI_UNSUPPORTED      ControllerHandle is not managed by the driver                                specified by DriverBindingHandle.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiTestManagedDevice
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|DriverBindingHandle
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ProtocolGuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Tests whether a child handle is a child device of the controller.    This function tests whether ChildHandle is one of the children of   ControllerHandle.  This test is performed by checking to see if the protocol   specified by ProtocolGuid is present on ControllerHandle and opened by   ChildHandle with an attribute of EFI_OPEN_PROTOCOL_BY_CHILD_CONTROLLER.   If ProtocolGuid is NULL, then ASSERT().    @param  ControllerHandle     A handle for a (parent) controller to test.    @param  ChildHandle          A child handle to test.   @param  ProtocolGuid         Supplies the protocol that the child controller                                opens on its parent controller.     @retval EFI_SUCCESS          ChildHandle is a child of the ControllerHandle.   @retval EFI_UNSUPPORTED      ChildHandle is not a child of the                                ControllerHandle.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiTestChildHandle
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ControllerHandle
parameter_list|,
name|IN
name|CONST
name|EFI_HANDLE
name|ChildHandle
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|ProtocolGuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function looks up a Unicode string in UnicodeStringTable.    If Language is a member of SupportedLanguages and a Unicode string is found in   UnicodeStringTable that matches the language code specified by Language, then it   is returned in UnicodeString.    @param  Language                A pointer to the ISO 639-2 language code for the                                    Unicode string to look up and return.   @param  SupportedLanguages      A pointer to the set of ISO 639-2 language codes                                    that the Unicode string table supports.  Language                                    must be a member of this set.   @param  UnicodeStringTable      A pointer to the table of Unicode strings.   @param  UnicodeString           A pointer to the Unicode string from UnicodeStringTable                                   that matches the language specified by Language.    @retval EFI_SUCCESS             The Unicode string that matches the language                                    specified by Language was found                                   in the table of Unicode strings UnicodeStringTable,                                    and it was returned in UnicodeString.   @retval EFI_INVALID_PARAMETER   Language is NULL.   @retval EFI_INVALID_PARAMETER   UnicodeString is NULL.   @retval EFI_UNSUPPORTED         SupportedLanguages is NULL.   @retval EFI_UNSUPPORTED         UnicodeStringTable is NULL.   @retval EFI_UNSUPPORTED         The language specified by Language is not a                                    member of SupportedLanguages.   @retval EFI_UNSUPPORTED         The language specified by Language is not                                    supported by UnicodeStringTable.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|LookupUnicodeString
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SupportedLanguages
parameter_list|,
name|IN
name|CONST
name|EFI_UNICODE_STRING_TABLE
modifier|*
name|UnicodeStringTable
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|UnicodeString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function looks up a Unicode string in UnicodeStringTable.    If Language is a member of SupportedLanguages and a Unicode string is found in   UnicodeStringTable that matches the language code specified by Language, then   it is returned in UnicodeString.    @param  Language             A pointer to an ASCII string containing the ISO 639-2 or the                                RFC 4646 language code for the Unicode string to look up and                                return. If Iso639Language is TRUE, then this ASCII string is                                not assumed to be Null-terminated, and only the first three                                characters are used. If Iso639Language is FALSE, then this ASCII                                string must be Null-terminated.    @param  SupportedLanguages   A pointer to a Null-terminated ASCII string that contains a                                set of ISO 639-2 or RFC 4646 language codes that the Unicode                                string table supports.  Language must be a member of this set.                                If Iso639Language is TRUE, then this string contains one or more                                ISO 639-2 language codes with no separator characters. If Iso639Language                                is FALSE, then is string contains one or more RFC 4646 language                                codes separated by ';'.   @param  UnicodeStringTable   A pointer to the table of Unicode strings. Type EFI_UNICODE_STRING_TABLE                                is defined in "Related Definitions".   @param  UnicodeString        A pointer to the Null-terminated Unicode string from UnicodeStringTable                                that matches the language specified by Language.   @param  Iso639Language       Specifies the supported language code format. If it is TRUE, then                                Language and SupportedLanguages follow ISO 639-2 language code format.                                Otherwise, they follow the RFC 4646 language code format.     @retval  EFI_SUCCESS            The Unicode string that matches the language specified by Language                                   was found in the table of Unicode strings UnicodeStringTable, and                                   it was returned in UnicodeString.   @retval  EFI_INVALID_PARAMETER  Language is NULL.     @retval  EFI_INVALID_PARAMETER  UnicodeString is NULL.     @retval  EFI_UNSUPPORTED        SupportedLanguages is NULL.     @retval  EFI_UNSUPPORTED        UnicodeStringTable is NULL.     @retval  EFI_UNSUPPORTED        The language specified by Language is not a member of SupportedLanguages.     @retval  EFI_UNSUPPORTED        The language specified by Language is not supported by UnicodeStringTable.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|LookupUnicodeString2
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SupportedLanguages
parameter_list|,
name|IN
name|CONST
name|EFI_UNICODE_STRING_TABLE
modifier|*
name|UnicodeStringTable
parameter_list|,
name|OUT
name|CHAR16
modifier|*
modifier|*
name|UnicodeString
parameter_list|,
name|IN
name|BOOLEAN
name|Iso639Language
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function adds a Unicode string to UnicodeStringTable.    If Language is a member of SupportedLanguages then UnicodeString is added to    UnicodeStringTable.  New buffers are allocated for both Language and    UnicodeString.  The contents of Language and UnicodeString are copied into    these new buffers.  These buffers are automatically freed when    FreeUnicodeStringTable() is called.    @param  Language                A pointer to the ISO 639-2 language code for the Unicode                                    string to add.   @param  SupportedLanguages      A pointer to the set of ISO 639-2 language codes                                   that the Unicode string table supports.                                   Language must be a member of this set.   @param  UnicodeStringTable      A pointer to the table of Unicode strings.   @param  UnicodeString           A pointer to the Unicode string to add.    @retval EFI_SUCCESS             The Unicode string that matches the language                                    specified by Language was found in the table of                                    Unicode strings UnicodeStringTable, and it was                                    returned in UnicodeString.   @retval EFI_INVALID_PARAMETER   Language is NULL.   @retval EFI_INVALID_PARAMETER   UnicodeString is NULL.   @retval EFI_INVALID_PARAMETER   UnicodeString is an empty string.   @retval EFI_UNSUPPORTED         SupportedLanguages is NULL.   @retval EFI_ALREADY_STARTED     A Unicode string with language Language is                                    already present in UnicodeStringTable.   @retval EFI_OUT_OF_RESOURCES    There is not enough memory to add another                                    Unicode string to UnicodeStringTable.   @retval EFI_UNSUPPORTED         The language specified by Language is not a                                    member of SupportedLanguages.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|AddUnicodeString
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SupportedLanguages
parameter_list|,
name|IN
name|EFI_UNICODE_STRING_TABLE
modifier|*
modifier|*
name|UnicodeStringTable
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|UnicodeString
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function adds the Null-terminated Unicode string specified by UnicodeString   to UnicodeStringTable.    If Language is a member of SupportedLanguages then UnicodeString is added to   UnicodeStringTable.  New buffers are allocated for both Language and UnicodeString.   The contents of Language and UnicodeString are copied into these new buffers.   These buffers are automatically freed when EfiLibFreeUnicodeStringTable() is called.    @param  Language            A pointer to an ASCII string containing the ISO 639-2 or                               the RFC 4646 language code for the Unicode string to add.                               If Iso639Language is TRUE, then this ASCII string is not                               assumed to be Null-terminated, and only the first three                               chacters are used. If Iso639Language is FALSE, then this                               ASCII string must be Null-terminated.   @param  SupportedLanguages  A pointer to a Null-terminated ASCII string that contains                               a set of ISO 639-2 or RFC 4646 language codes that the Unicode                               string table supports.  Language must be a member of this set.                               If Iso639Language is TRUE, then this string contains one or more                               ISO 639-2 language codes with no separator characters.                               If Iso639Language is FALSE, then is string contains one or more                               RFC 4646 language codes separated by ';'.   @param  UnicodeStringTable  A pointer to the table of Unicode strings. Type EFI_UNICODE_STRING_TABLE                               is defined in "Related Definitions".   @param  UnicodeString       A pointer to the Unicode string to add.     @param  Iso639Language      Specifies the supported language code format. If it is TRUE,                               then Language and SupportedLanguages follow ISO 639-2 language code format.                               Otherwise, they follow RFC 4646 language code format.    @retval EFI_SUCCESS            The Unicode string that matches the language specified by                                  Language was found in the table of Unicode strings UnicodeStringTable,                                  and it was returned in UnicodeString.     @retval EFI_INVALID_PARAMETER  Language is NULL.     @retval EFI_INVALID_PARAMETER  UnicodeString is NULL.     @retval EFI_INVALID_PARAMETER  UnicodeString is an empty string.     @retval EFI_UNSUPPORTED        SupportedLanguages is NULL.     @retval EFI_ALREADY_STARTED    A Unicode string with language Language is already present in                                  UnicodeStringTable.     @retval EFI_OUT_OF_RESOURCES   There is not enough memory to add another Unicode string UnicodeStringTable.     @retval EFI_UNSUPPORTED        The language specified by Language is not a member of SupportedLanguages.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|AddUnicodeString2
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|SupportedLanguages
parameter_list|,
name|IN
name|EFI_UNICODE_STRING_TABLE
modifier|*
modifier|*
name|UnicodeStringTable
parameter_list|,
name|IN
name|CONST
name|CHAR16
modifier|*
name|UnicodeString
parameter_list|,
name|IN
name|BOOLEAN
name|Iso639Language
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   This function frees the table of Unicode strings in UnicodeStringTable.    If UnicodeStringTable is NULL, then EFI_SUCCESS is returned.   Otherwise, each language code, and each Unicode string in the Unicode string    table are freed, and EFI_SUCCESS is returned.    @param  UnicodeStringTable  A pointer to the table of Unicode strings.    @retval EFI_SUCCESS         The Unicode string table was freed.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|FreeUnicodeStringTable
parameter_list|(
name|IN
name|EFI_UNICODE_STRING_TABLE
modifier|*
name|UnicodeStringTable
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|DISABLE_NEW_DEPRECATED_INTERFACES
end_ifndef

begin_comment
comment|/**   [ATTENTION] This function will be deprecated for security reason.    Returns a pointer to an allocated buffer that contains the contents of a    variable retrieved through the UEFI Runtime Service GetVariable().  The    returned buffer is allocated using AllocatePool().  The caller is responsible   for freeing this buffer with FreePool().    If Name is NULL, then ASSERT().   If Guid is NULL, then ASSERT().    @param[in]  Name  The pointer to a Null-terminated Unicode string.   @param[in]  Guid  The pointer to an EFI_GUID structure.    @retval NULL   The variable could not be retrieved.   @retval NULL   There are not enough resources available for the variable contents.   @retval Other  A pointer to allocated buffer containing the variable contents.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|GetVariable
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   [ATTENTION] This function will be deprecated for security reason.    Returns a pointer to an allocated buffer that contains the contents of a    variable retrieved through the UEFI Runtime Service GetVariable().  This    function always uses the EFI_GLOBAL_VARIABLE GUID to retrieve variables.   The returned buffer is allocated using AllocatePool().  The caller is    responsible for freeing this buffer with FreePool().    If Name is NULL, then ASSERT().    @param[in]  Name  The pointer to a Null-terminated Unicode string.    @retval NULL   The variable could not be retrieved.   @retval NULL   There are not enough resources available for the variable contents.   @retval Other  A pointer to allocated buffer containing the variable contents.  **/
end_comment

begin_function_decl
name|VOID
modifier|*
name|EFIAPI
name|GetEfiGlobalVariable
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/**   Returns the status whether get the variable success. The function retrieves    variable  through the UEFI Runtime Service GetVariable().  The    returned buffer is allocated using AllocatePool().  The caller is responsible   for freeing this buffer with FreePool().    If Name  is NULL, then ASSERT().   If Guid  is NULL, then ASSERT().   If Value is NULL, then ASSERT().    @param[in]  Name  The pointer to a Null-terminated Unicode string.   @param[in]  Guid  The pointer to an EFI_GUID structure   @param[out] Value The buffer point saved the variable info.   @param[out] Size  The buffer size of the variable.    @return EFI_OUT_OF_RESOURCES      Allocate buffer failed.   @return EFI_SUCCESS               Find the specified variable.   @return Others Errors             Return errors from call to gRT->GetVariable.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetVariable2
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|Guid
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Value
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a pointer to an allocated buffer that contains the contents of a    variable retrieved through the UEFI Runtime Service GetVariable().  This    function always uses the EFI_GLOBAL_VARIABLE GUID to retrieve variables.   The returned buffer is allocated using AllocatePool().  The caller is    responsible for freeing this buffer with FreePool().    If Name  is NULL, then ASSERT().   If Value is NULL, then ASSERT().    @param[in]  Name  The pointer to a Null-terminated Unicode string.   @param[out] Value The buffer point saved the variable info.   @param[out] Size  The buffer size of the variable.    @return EFI_OUT_OF_RESOURCES      Allocate buffer failed.   @return EFI_SUCCESS               Find the specified variable.   @return Others Errors             Return errors from call to gRT->GetVariable.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|GetEfiGlobalVariable2
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Name
parameter_list|,
name|OUT
name|VOID
modifier|*
modifier|*
name|Value
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Size
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Returns a pointer to an allocated buffer that contains the best matching language    from a set of supported languages.        This function supports both ISO 639-2 and RFC 4646 language codes, but language    code types may not be mixed in a single call to this function.  The language    code returned is allocated using AllocatePool().  The caller is responsible for    freeing the allocated buffer using FreePool().  This function supports a variable   argument list that allows the caller to pass in a prioritized list of language    codes to test against all the language codes in SupportedLanguages.     If SupportedLanguages is NULL, then ASSERT().    @param[in]  SupportedLanguages  A pointer to a Null-terminated ASCII string that                                   contains a set of language codes in the format                                    specified by Iso639Language.   @param[in]  Iso639Language      If TRUE, then all language codes are assumed to be                                   in ISO 639-2 format.  If FALSE, then all language                                   codes are assumed to be in RFC 4646 language format   @param[in]  ...                 A variable argument list that contains pointers to                                    Null-terminated ASCII strings that contain one or more                                   language codes in the format specified by Iso639Language.                                   The first language code from each of these language                                   code lists is used to determine if it is an exact or                                   close match to any of the language codes in                                    SupportedLanguages.  Close matches only apply to RFC 4646                                   language codes, and the matching algorithm from RFC 4647                                   is used to determine if a close match is present.  If                                    an exact or close match is found, then the matching                                   language code from SupportedLanguages is returned.  If                                   no matches are found, then the next variable argument                                   parameter is evaluated.  The variable argument list                                    is terminated by a NULL.    @retval NULL   The best matching language could not be found in SupportedLanguages.   @retval NULL   There are not enough resources available to return the best matching                   language.   @retval Other  A pointer to a Null-terminated ASCII string that is the best matching                   language in SupportedLanguages.  **/
end_comment

begin_function_decl
name|CHAR8
modifier|*
name|EFIAPI
name|GetBestLanguage
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|SupportedLanguages
parameter_list|,
name|IN
name|BOOLEAN
name|Iso639Language
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Draws a dialog box to the console output device specified by    ConOut defined in the EFI_SYSTEM_TABLE and waits for a keystroke   from the console input device specified by ConIn defined in the    EFI_SYSTEM_TABLE.    If there are no strings in the variable argument list, then ASSERT().   If all the strings in the variable argument list are empty, then ASSERT().    @param[in]   Attribute  Specifies the foreground and background color of the popup.   @param[out]  Key        A pointer to the EFI_KEY value of the key that was                            pressed.  This is an optional parameter that may be NULL.                           If it is NULL then no wait for a keypress will be performed.   @param[in]  ...         The variable argument list that contains pointers to Null-                           terminated Unicode strings to display in the dialog box.                             The variable argument list is terminated by a NULL.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CreatePopUp
parameter_list|(
name|IN
name|UINTN
name|Attribute
parameter_list|,
name|OUT
name|EFI_INPUT_KEY
modifier|*
name|Key
parameter_list|,
name|OPTIONAL
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the width of a Unicode character.    This function computes and returns the width of the Unicode character specified   by UnicodeChar.    @param  UnicodeChar   A Unicode character.    @retval 0             The width if UnicodeChar could not be determined.   @retval 1             UnicodeChar is a narrow glyph.   @retval 2             UnicodeChar is a wide glyph.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|GetGlyphWidth
parameter_list|(
name|IN
name|CHAR16
name|UnicodeChar
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Computes the display length of a Null-terminated Unicode String.    This function computes and returns the display length of the Null-terminated Unicode   string specified by String.  If String is NULL then 0 is returned. If any of the widths   of the Unicode characters in String can not be determined, then 0 is returned. The display   width of String can be computed by summing the display widths of each Unicode character   in String.  Unicode characters that are narrow glyphs have a width of 1, and Unicode   characters that are width glyphs have a width of 2.    If String is not aligned on a 16-bit boundary, then ASSERT().    @param  String      A pointer to a Null-terminated Unicode string.    @return The display length of the Null-terminated Unicode string specified by String.    **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|UnicodeStringDisplayLength
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|String
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//
end_comment

begin_comment
comment|// Functions that abstract early Framework contamination of UEFI.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Create, Signal, and Close the Ready to Boot event using EfiSignalEventReadyToBoot().      This function abstracts the signaling of the Ready to Boot Event. The Framework moved   from a proprietary to UEFI 2.0 based mechanism. This library abstracts the caller   from how this event is created to prevent to code form having to change with the   version of the specification supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiSignalEventReadyToBoot
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Create, Signal, and Close the Ready to Boot event using EfiSignalEventLegacyBoot().    This function abstracts the signaling of the Legacy Boot Event. The Framework moved from   a proprietary to UEFI 2.0 based mechanism.  This library abstracts the caller from how   this event is created to prevent to code form having to change with the version of the   specification supported.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiSignalEventLegacyBoot
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Creates an EFI event in the Legacy Boot Event Group.    Prior to UEFI 2.0 this was done via a non blessed UEFI extensions and this library   abstracts the implementation mechanism of this event from the caller. This function   abstracts the creation of the Legacy Boot Event. The Framework moved from a proprietary   to UEFI 2.0 based mechanism.  This library abstracts the caller from how this event   is created to prevent to code form having to change with the version of the   specification supported.   If LegacyBootEvent is NULL, then ASSERT().    @param  LegacyBootEvent   Returns the EFI event returned from gBS->CreateEvent(Ex).    @retval EFI_SUCCESS       The event was created.   @retval Other             The event was not created.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiCreateEventLegacyBoot
parameter_list|(
name|OUT
name|EFI_EVENT
modifier|*
name|LegacyBootEvent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Create an EFI event in the Legacy Boot Event Group and allows   the caller to specify a notification function.        This function abstracts the creation of the Legacy Boot Event.   The Framework moved from a proprietary to UEFI 2.0 based mechanism.   This library abstracts the caller from how this event is created to prevent   to code form having to change with the version of the specification supported.   If LegacyBootEvent is NULL, then ASSERT().    @param  NotifyTpl         The task priority level of the event.   @param  NotifyFunction    The notification function to call when the event is signaled.   @param  NotifyContext     The content to pass to NotifyFunction when the event is signaled.   @param  LegacyBootEvent   Returns the EFI event returned from gBS->CreateEvent(Ex).    @retval EFI_SUCCESS       The event was created.   @retval Other             The event was not created.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiCreateEventLegacyBootEx
parameter_list|(
name|IN
name|EFI_TPL
name|NotifyTpl
parameter_list|,
name|IN
name|EFI_EVENT_NOTIFY
name|NotifyFunction
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|NotifyContext
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_EVENT
modifier|*
name|LegacyBootEvent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Create an EFI event in the Ready To Boot Event Group.    Prior to UEFI 2.0 this was done via a non-standard UEFI extension, and this library   abstracts the implementation mechanism of this event from the caller.      This function abstracts the creation of the Ready to Boot Event.  The Framework    moved from a proprietary to UEFI 2.0-based mechanism.  This library abstracts    the caller from how this event is created to prevent the code form having to    change with the version of the specification supported.   If ReadyToBootEvent is NULL, then ASSERT().    @param  ReadyToBootEvent   Returns the EFI event returned from gBS->CreateEvent(Ex).    @retval EFI_SUCCESS       The event was created.   @retval Other             The event was not created.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiCreateEventReadyToBoot
parameter_list|(
name|OUT
name|EFI_EVENT
modifier|*
name|ReadyToBootEvent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Create an EFI event in the Ready To Boot Event Group and allows   the caller to specify a notification function.        This function abstracts the creation of the Ready to Boot Event.   The Framework moved from a proprietary to UEFI 2.0 based mechanism.   This library abstracts the caller from how this event is created to prevent   to code form having to change with the version of the specification supported.   If ReadyToBootEvent is NULL, then ASSERT().    @param  NotifyTpl         The task priority level of the event.   @param  NotifyFunction    The notification function to call when the event is signaled.   @param  NotifyContext     The content to pass to NotifyFunction when the event is signaled.   @param  ReadyToBootEvent  Returns the EFI event returned from gBS->CreateEvent(Ex).    @retval EFI_SUCCESS       The event was created.   @retval Other             The event was not created.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiCreateEventReadyToBootEx
parameter_list|(
name|IN
name|EFI_TPL
name|NotifyTpl
parameter_list|,
name|IN
name|EFI_EVENT_NOTIFY
name|NotifyFunction
parameter_list|,
name|OPTIONAL
name|IN
name|VOID
modifier|*
name|NotifyContext
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_EVENT
modifier|*
name|ReadyToBootEvent
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Initialize a Firmware Volume (FV) Media Device Path node.      The Framework FwVol Device Path changed to conform to the UEFI 2.0 specification.     This library function abstracts initializing a device path node.     Initialize the MEDIA_FW_VOL_FILEPATH_DEVICE_PATH data structure.  This device    path changed in the DXE CIS version 0.92 in a non back ward compatible way to    not conflict with the UEFI 2.0 specification.  This function abstracts the    differences from the caller.   If FvDevicePathNode is NULL, then ASSERT().   If NameGuid is NULL, then ASSERT().      @param  FvDevicePathNode  The pointer to a FV device path node to initialize   @param  NameGuid          FV file name to use in FvDevicePathNode  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|EfiInitializeFwVolDevicepathNode
parameter_list|(
name|IN
name|OUT
name|MEDIA_FW_VOL_FILEPATH_DEVICE_PATH
modifier|*
name|FvDevicePathNode
parameter_list|,
name|IN
name|CONST
name|EFI_GUID
modifier|*
name|NameGuid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Check to see if the Firmware Volume (FV) Media Device Path is valid       The Framework FwVol Device Path changed to conform to the UEFI 2.0 specification.     This library function abstracts validating a device path node.   Check the MEDIA_FW_VOL_FILEPATH_DEVICE_PATH data structure to see if it's valid.     If it is valid, then return the GUID file name from the device path node.  Otherwise,    return NULL.  This device path changed in the DXE CIS version 0.92 in a non backward    compatible way to not conflict with the UEFI 2.0 specification.  This function abstracts    the differences from the caller.   If FvDevicePathNode is NULL, then ASSERT().    @param  FvDevicePathNode  The pointer to FV device path to check.    @retval NULL              FvDevicePathNode is not valid.   @retval Other             FvDevicePathNode is valid and pointer to NameGuid was returned.  **/
end_comment

begin_function_decl
name|EFI_GUID
modifier|*
name|EFIAPI
name|EfiGetNameGuidFromFwVolDevicePathNode
parameter_list|(
name|IN
name|CONST
name|MEDIA_FW_VOL_FILEPATH_DEVICE_PATH
modifier|*
name|FvDevicePathNode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Prints a formatted Unicode string to the console output device specified by    ConOut defined in the EFI_SYSTEM_TABLE.    This function prints a formatted Unicode string to the console output device    specified by ConOut in EFI_SYSTEM_TABLE and returns the number of Unicode    characters that printed to ConOut.  If the length of the formatted Unicode    string is greater than PcdUefiLibMaxPrintBufferSize, then only the first    PcdUefiLibMaxPrintBufferSize characters are sent to ConOut.   If Format is NULL, then ASSERT().   If Format is not aligned on a 16-bit boundary, then ASSERT().   If gST->ConOut is NULL, then ASSERT().    @param Format   A null-terminated Unicode format string.   @param ...      The variable argument list whose contents are accessed based                    on the format string specified by Format.      @return Number of Unicode characters printed to ConOut.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|Print
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Prints a formatted Unicode string to the console output device specified by    StdErr defined in the EFI_SYSTEM_TABLE.    This function prints a formatted Unicode string to the console output device    specified by StdErr in EFI_SYSTEM_TABLE and returns the number of Unicode    characters that printed to StdErr.  If the length of the formatted Unicode    string is greater than PcdUefiLibMaxPrintBufferSize, then only the first    PcdUefiLibMaxPrintBufferSize characters are sent to StdErr.   If Format is NULL, then ASSERT().   If Format is not aligned on a 16-bit boundary, then ASSERT().   If gST->StdErr is NULL, then ASSERT().    @param Format   A null-terminated Unicode format string.   @param ...      The variable argument list whose contents are accessed based                    on the format string specified by Format.      @return Number of Unicode characters printed to StdErr.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|ErrorPrint
parameter_list|(
name|IN
name|CONST
name|CHAR16
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Prints a formatted ASCII string to the console output device specified by    ConOut defined in the EFI_SYSTEM_TABLE.    This function prints a formatted ASCII string to the console output device    specified by ConOut in EFI_SYSTEM_TABLE and returns the number of ASCII    characters that printed to ConOut.  If the length of the formatted ASCII    string is greater than PcdUefiLibMaxPrintBufferSize, then only the first    PcdUefiLibMaxPrintBufferSize characters are sent to ConOut.   If Format is NULL, then ASSERT().   If gST->ConOut is NULL, then ASSERT().    @param Format   A null-terminated ASCII format string.   @param ...      The variable argument list whose contents are accessed based                    on the format string specified by Format.      @return Number of ASCII characters printed to ConOut.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiPrint
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Prints a formatted ASCII string to the console output device specified by    StdErr defined in the EFI_SYSTEM_TABLE.    This function prints a formatted ASCII string to the console output device    specified by StdErr in EFI_SYSTEM_TABLE and returns the number of ASCII    characters that printed to StdErr.  If the length of the formatted ASCII    string is greater than PcdUefiLibMaxPrintBufferSize, then only the first    PcdUefiLibMaxPrintBufferSize characters are sent to StdErr.   If Format is NULL, then ASSERT().   If gST->StdErr is NULL, then ASSERT().    @param Format   A null-terminated ASCII format string.   @param ...      The variable argument list whose contents are accessed based                    on the format string specified by Format.      @return Number of ASCII characters printed to ConErr.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiErrorPrint
parameter_list|(
name|IN
name|CONST
name|CHAR8
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prints a formatted Unicode string to a graphics console device specified by    ConsoleOutputHandle defined in the EFI_SYSTEM_TABLE at the given (X,Y) coordinates.    This function prints a formatted Unicode string to the graphics console device    specified by ConsoleOutputHandle in EFI_SYSTEM_TABLE and returns the number of    Unicode characters displayed, not including partial characters that may be clipped    by the right edge of the display.  If the length of the formatted Unicode string is   greater than PcdUefiLibMaxPrintBufferSize, then at most the first    PcdUefiLibMaxPrintBufferSize characters are printed.  The EFI_HII_FONT_PROTOCOL   is used to convert the string to a bitmap using the glyphs registered with the    HII database.  No wrapping is performed, so any portions of the string the fall   outside the active display region will not be displayed.    If a graphics console device is not associated with the ConsoleOutputHandle    defined in the EFI_SYSTEM_TABLE then no string is printed, and 0 is returned.   If the EFI_HII_FONT_PROTOCOL is not present in the handle database, then no    string is printed, and 0 is returned.   If Format is NULL, then ASSERT().   If Format is not aligned on a 16-bit boundary, then ASSERT().   If gST->ConsoleOutputHandle is NULL, then ASSERT().    @param  PointX       X coordinate to print the string.   @param  PointY       Y coordinate to print the string.   @param  ForeGround   The foreground color of the string being printed.  This is                        an optional parameter that may be NULL.  If it is NULL,                        then the foreground color of the current ConOut device                        in the EFI_SYSTEM_TABLE is used.   @param  BackGround   The background color of the string being printed.  This is                        an optional parameter that may be NULL.  If it is NULL,                         then the background color of the current ConOut device                        in the EFI_SYSTEM_TABLE is used.   @param  Format       A null-terminated Unicode format string.  See Print Library                         for the supported format string syntax.   @param  ...          Variable argument list whose contents are accessed based on                         the format string specified by Format.             @return  The number of Unicode characters printed.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|PrintXY
parameter_list|(
name|IN
name|UINTN
name|PointX
parameter_list|,
name|IN
name|UINTN
name|PointY
parameter_list|,
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|ForeGround
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|BackGround
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR16
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Prints a formatted ASCII string to a graphics console device specified by    ConsoleOutputHandle defined in the EFI_SYSTEM_TABLE at the given (X,Y) coordinates.    This function prints a formatted ASCII string to the graphics console device    specified by ConsoleOutputHandle in EFI_SYSTEM_TABLE and returns the number of    ASCII characters displayed, not including partial characters that may be clipped    by the right edge of the display.  If the length of the formatted ASCII string is   greater than PcdUefiLibMaxPrintBufferSize, then at most the first    PcdUefiLibMaxPrintBufferSize characters are printed.  The EFI_HII_FONT_PROTOCOL   is used to convert the string to a bitmap using the glyphs registered with the    HII database.  No wrapping is performed, so any portions of the string the fall   outside the active display region will not be displayed.    If a graphics console device is not associated with the ConsoleOutputHandle    defined in the EFI_SYSTEM_TABLE then no string is printed, and 0 is returned.   If the EFI_HII_FONT_PROTOCOL is not present in the handle database, then no    string is printed, and 0 is returned.   If Format is NULL, then ASSERT().   If gST->ConsoleOutputHandle is NULL, then ASSERT().    @param  PointX       X coordinate to print the string.   @param  PointY       Y coordinate to print the string.   @param  ForeGround   The foreground color of the string being printed.  This is                        an optional parameter that may be NULL.  If it is NULL,                        then the foreground color of the current ConOut device                        in the EFI_SYSTEM_TABLE is used.   @param  BackGround   The background color of the string being printed.  This is                        an optional parameter that may be NULL.  If it is NULL,                         then the background color of the current ConOut device                        in the EFI_SYSTEM_TABLE is used.   @param  Format       A null-terminated ASCII format string.  See Print Library                         for the supported format string syntax.   @param  ...          The variable argument list whose contents are accessed based on                         the format string specified by Format.             @return  The number of ASCII characters printed.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|AsciiPrintXY
parameter_list|(
name|IN
name|UINTN
name|PointX
parameter_list|,
name|IN
name|UINTN
name|PointY
parameter_list|,
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|ForeGround
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|BackGround
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR8
modifier|*
name|Format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Installs and completes the initialization of a Driver Binding Protocol instance.      Installs the Driver Binding Protocol specified by DriverBinding onto the handle   specified by DriverBindingHandle. If DriverBindingHandle is NULL, then DriverBinding   is installed onto a newly created handle. DriverBindingHandle is typically the same   as the driver's ImageHandle, but it can be different if the driver produces multiple   Driver Binding Protocols.    If DriverBinding is NULL, then ASSERT().    If DriverBinding can not be installed onto a handle, then ASSERT().    @param  ImageHandle          The image handle of the driver.   @param  SystemTable          The EFI System Table that was passed to the driver's entry point.   @param  DriverBinding        A Driver Binding Protocol instance that this driver is producing.   @param  DriverBindingHandle  The handle that DriverBinding is to be installed onto.  If this                                parameter is NULL, then a new handle is created.    @retval EFI_SUCCESS           The protocol installation completed successfully.   @retval EFI_OUT_OF_RESOURCES  There was not enough system resources to install the protocol.   @retval Others                Status from gBS->InstallMultipleProtocolInterfaces().  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiLibInstallDriverBinding
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|CONST
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|DriverBinding
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverBindingHandle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Installs and completes the initialization of a Driver Binding Protocol instance and   optionally installs the Component Name, Driver Configuration and Driver Diagnostics Protocols.    Initializes a driver by installing the Driver Binding Protocol together with the   optional Component Name, optional Driver Configure and optional Driver Diagnostic   Protocols onto the driver's DriverBindingHandle. If DriverBindingHandle is NULL,   then the protocols are installed onto a newly created handle. DriverBindingHandle   is typically the same as the driver's ImageHandle, but it can be different if the   driver produces multiple Driver Binding Protocols.    If DriverBinding is NULL, then ASSERT().    If the installation fails, then ASSERT().      @param  ImageHandle          The image handle of the driver.   @param  SystemTable          The EFI System Table that was passed to the driver's entry point.   @param  DriverBinding        A Driver Binding Protocol instance that this driver is producing.   @param  DriverBindingHandle  The handle that DriverBinding is to be installed onto.  If this                                parameter is NULL, then a new handle is created.   @param  ComponentName        A Component Name Protocol instance that this driver is producing.   @param  DriverConfiguration  A Driver Configuration Protocol instance that this driver is producing.   @param  DriverDiagnostics    A Driver Diagnostics Protocol instance that this driver is producing.    @retval EFI_SUCCESS           The protocol installation completed successfully.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory in the pool to install all the protocols.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiLibInstallAllDriverProtocols
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|CONST
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|DriverBinding
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverBindingHandle
parameter_list|,
name|IN
name|CONST
name|EFI_COMPONENT_NAME_PROTOCOL
modifier|*
name|ComponentName
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|DriverConfiguration
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_DIAGNOSTICS_PROTOCOL
modifier|*
name|DriverDiagnostics
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Installs Driver Binding Protocol with optional Component Name and Component Name 2 Protocols.    Initializes a driver by installing the Driver Binding Protocol together with the   optional Component Name and optional Component Name 2 protocols onto the driver's   DriverBindingHandle.  If DriverBindingHandle is NULL, then the protocols are installed   onto a newly created handle.  DriverBindingHandle is typically the same as the driver's   ImageHandle, but it can be different if the driver produces multiple Driver Binding Protocols.    If DriverBinding is NULL, then ASSERT().    If the installation fails, then ASSERT().    @param  ImageHandle          The image handle of the driver.   @param  SystemTable          The EFI System Table that was passed to the driver's entry point.   @param  DriverBinding        A Driver Binding Protocol instance that this driver is producing.   @param  DriverBindingHandle  The handle that DriverBinding is to be installed onto.  If this                                parameter is NULL, then a new handle is created.   @param  ComponentName        A Component Name Protocol instance that this driver is producing.   @param  ComponentName2       A Component Name 2 Protocol instance that this driver is producing.    @retval EFI_SUCCESS           The protocol installation completed successfully.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory in pool to install all the protocols.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiLibInstallDriverBindingComponentName2
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|CONST
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|DriverBinding
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverBindingHandle
parameter_list|,
name|IN
name|CONST
name|EFI_COMPONENT_NAME_PROTOCOL
modifier|*
name|ComponentName
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_COMPONENT_NAME2_PROTOCOL
modifier|*
name|ComponentName2
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Installs Driver Binding Protocol with optional Component Name, Component Name 2, Driver   Configuration, Driver Configuration 2, Driver Diagnostics, and Driver Diagnostics 2 Protocols.    Initializes a driver by installing the Driver Binding Protocol together with the optional   Component Name, optional Component Name 2, optional Driver Configuration, optional Driver Configuration 2,   optional Driver Diagnostic, and optional Driver Diagnostic 2 Protocols onto the driver's DriverBindingHandle.   DriverBindingHandle is typically the same as the driver's ImageHandle, but it can be different if the driver   produces multiple Driver Binding Protocols.    If DriverBinding is NULL, then ASSERT().    If the installation fails, then ASSERT().     @param  ImageHandle           The image handle of the driver.   @param  SystemTable           The EFI System Table that was passed to the driver's entry point.   @param  DriverBinding         A Driver Binding Protocol instance that this driver is producing.   @param  DriverBindingHandle   The handle that DriverBinding is to be installed onto.  If this                                 parameter is NULL, then a new handle is created.   @param  ComponentName         A Component Name Protocol instance that this driver is producing.   @param  ComponentName2        A Component Name 2 Protocol instance that this driver is producing.   @param  DriverConfiguration   A Driver Configuration Protocol instance that this driver is producing.   @param  DriverConfiguration2  A Driver Configuration Protocol 2 instance that this driver is producing.   @param  DriverDiagnostics     A Driver Diagnostics Protocol instance that this driver is producing.   @param  DriverDiagnostics2    A Driver Diagnostics Protocol 2 instance that this driver is producing.    @retval EFI_SUCCESS           The protocol installation completed successfully.   @retval EFI_OUT_OF_RESOURCES  There was not enough memory in pool to install all the protocols.  **/
end_comment

begin_function_decl
name|EFI_STATUS
name|EFIAPI
name|EfiLibInstallAllDriverProtocols2
parameter_list|(
name|IN
name|CONST
name|EFI_HANDLE
name|ImageHandle
parameter_list|,
name|IN
name|CONST
name|EFI_SYSTEM_TABLE
modifier|*
name|SystemTable
parameter_list|,
name|IN
name|EFI_DRIVER_BINDING_PROTOCOL
modifier|*
name|DriverBinding
parameter_list|,
name|IN
name|EFI_HANDLE
name|DriverBindingHandle
parameter_list|,
name|IN
name|CONST
name|EFI_COMPONENT_NAME_PROTOCOL
modifier|*
name|ComponentName
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_COMPONENT_NAME2_PROTOCOL
modifier|*
name|ComponentName2
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_CONFIGURATION_PROTOCOL
modifier|*
name|DriverConfiguration
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_CONFIGURATION2_PROTOCOL
modifier|*
name|DriverConfiguration2
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_DIAGNOSTICS_PROTOCOL
modifier|*
name|DriverDiagnostics
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|EFI_DRIVER_DIAGNOSTICS2_PROTOCOL
modifier|*
name|DriverDiagnostics2
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Appends a formatted Unicode string to a Null-terminated Unicode string     This function appends a formatted Unicode string to the Null-terminated    Unicode string specified by String.   String is optional and may be NULL.   Storage for the formatted Unicode string returned is allocated using    AllocatePool().  The pointer to the appended string is returned.  The caller   is responsible for freeing the returned string.     If String is not NULL and not aligned on a 16-bit boundary, then ASSERT().   If FormatString is NULL, then ASSERT().   If FormatString is not aligned on a 16-bit boundary, then ASSERT().     @param[in] String         A Null-terminated Unicode string.   @param[in] FormatString   A Null-terminated Unicode format string.   @param[in]  Marker        VA_LIST marker for the variable argument list.    @retval NULL    There was not enough available memory.   @return         Null-terminated Unicode string is that is the formatted                    string appended to String. **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|CatVSPrint
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR16
modifier|*
name|FormatString
parameter_list|,
name|IN
name|VA_LIST
name|Marker
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**    Appends a formatted Unicode string to a Null-terminated Unicode string     This function appends a formatted Unicode string to the Null-terminated    Unicode string specified by String.   String is optional and may be NULL.   Storage for the formatted Unicode string returned is allocated using    AllocatePool().  The pointer to the appended string is returned.  The caller   is responsible for freeing the returned string.     If String is not NULL and not aligned on a 16-bit boundary, then ASSERT().   If FormatString is NULL, then ASSERT().   If FormatString is not aligned on a 16-bit boundary, then ASSERT().     @param[in] String         A Null-terminated Unicode string.   @param[in] FormatString   A Null-terminated Unicode format string.   @param[in] ...            The variable argument list whose contents are                              accessed based on the format string specified by                              FormatString.    @retval NULL    There was not enough available memory.   @return         Null-terminated Unicode string is that is the formatted                    string appended to String. **/
end_comment

begin_function_decl
name|CHAR16
modifier|*
name|EFIAPI
name|CatSPrint
parameter_list|(
name|IN
name|CHAR16
modifier|*
name|String
parameter_list|,
name|OPTIONAL
name|IN
name|CONST
name|CHAR16
modifier|*
name|FormatString
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

