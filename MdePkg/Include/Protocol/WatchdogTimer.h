begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Watchdog Timer Architectural Protocol as defined in PI Specification VOLUME 2 DXE    Used to provide system watchdog timer services    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.              **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_WATCHDOG_TIMER_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_WATCHDOG_TIMER_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Watchdog Timer Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_WATCHDOG_TIMER_ARCH_PROTOCOL_GUID
define|\
value|{ 0x665E3FF5, 0x46CC, 0x11d4, {0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare forward reference for the Timer Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
name|EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   A function of this type is called when the watchdog timer fires if a    handler has been registered.    @param  Time             The time in 100 ns units that has passed since the watchdog                            timer was armed. For the notify function to be called, this                            must be greater than TimerPeriod.    @return None.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WATCHDOG_TIMER_NOTIFY
function_decl|)
parameter_list|(
name|IN
name|UINT64
name|Time
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function registers a handler that is to be invoked when the watchdog    timer fires.  By default, the EFI_WATCHDOG_TIMER protocol will call the    Runtime Service ResetSystem() when the watchdog timer fires.  If a    NotifyFunction is registered, then the NotifyFunction will be called before    the Runtime Service ResetSystem() is called.  If NotifyFunction is NULL, then    the watchdog handler is unregistered.  If a watchdog handler is registered,    then EFI_SUCCESS is returned.  If an attempt is made to register a handler    when a handler is already registered, then EFI_ALREADY_STARTED is returned.     If an attempt is made to uninstall a handler when a handler is not installed,    then return EFI_INVALID_PARAMETER.    @param  This             The EFI_WATCHDOG_TIMER_ARCH_PROTOCOL instance.   @param  NotifyFunction   The function to call when the watchdog timer fires. If this                            is NULL, then the handler will be unregistered.    @retval EFI_SUCCESS           The watchdog timer handler was registered or                                 unregistered.   @retval EFI_ALREADY_STARTED   NotifyFunction is not NULL, and a handler is already                                 registered.   @retval EFI_INVALID_PARAMETER NotifyFunction is NULL, and a handler was not                                 previously registered.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WATCHDOG_TIMER_REGISTER_HANDLER
function_decl|)
parameter_list|(
name|IN
name|EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_WATCHDOG_TIMER_NOTIFY
name|NotifyFunction
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function sets the amount of time to wait before firing the watchdog    timer to TimerPeriod 100 nS units.  If TimerPeriod is 0, then the watchdog    timer is disabled.    @param  This             The EFI_WATCHDOG_TIMER_ARCH_PROTOCOL instance.   @param  TimerPeriod      The amount of time in 100 nS units to wait before the watchdog                            timer is fired. If TimerPeriod is zero, then the watchdog                            timer is disabled.    @retval EFI_SUCCESS           The watchdog timer has been programmed to fire in Time                                 100 nS units.   @retval EFI_DEVICE_ERROR      A watchdog timer could not be programmed due to a device                                 error.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WATCHDOG_TIMER_SET_TIMER_PERIOD
function_decl|)
parameter_list|(
name|IN
name|EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|TimerPeriod
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function retrieves the amount of time the system will wait before firing    the watchdog timer.  This period is returned in TimerPeriod, and EFI_SUCCESS    is returned.  If TimerPeriod is NULL, then EFI_INVALID_PARAMETER is returned.    @param  This             The EFI_WATCHDOG_TIMER_ARCH_PROTOCOL instance.   @param  TimerPeriod      A pointer to the amount of time in 100 nS units that the system                            will wait before the watchdog timer is fired. If TimerPeriod of                            zero is returned, then the watchdog timer is disabled.    @retval EFI_SUCCESS           The amount of time that the system will wait before                                 firing the watchdog timer was returned in TimerPeriod.   @retval EFI_INVALID_PARAMETER TimerPeriod is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_WATCHDOG_TIMER_GET_TIMER_PERIOD
function_decl|)
parameter_list|(
name|IN
name|EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|TimerPeriod
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the services required to implement the Boot Service
end_comment

begin_comment
comment|/// SetWatchdogTimer().  It provides a service to set the amount of time to wait
end_comment

begin_comment
comment|/// before firing the watchdog timer, and it also provides a service to register
end_comment

begin_comment
comment|/// a handler that is invoked when the watchdog timer fires.  This protocol can
end_comment

begin_comment
comment|/// implement the watchdog timer by using the event and timer Boot Services, or
end_comment

begin_comment
comment|/// it can make use of custom hardware.  When the watchdog timer fires, control
end_comment

begin_comment
comment|/// will be passed to a handler if one has been registered.  If no handler has
end_comment

begin_comment
comment|/// been registered, or the registered handler returns, then the system will be
end_comment

begin_comment
comment|/// reset by calling the Runtime Service ResetSystem().
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_WATCHDOG_TIMER_ARCH_PROTOCOL
block|{
name|EFI_WATCHDOG_TIMER_REGISTER_HANDLER
name|RegisterHandler
decl_stmt|;
name|EFI_WATCHDOG_TIMER_SET_TIMER_PERIOD
name|SetTimerPeriod
decl_stmt|;
name|EFI_WATCHDOG_TIMER_GET_TIMER_PERIOD
name|GetTimerPeriod
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiWatchdogTimerArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

