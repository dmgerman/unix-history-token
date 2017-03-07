begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM Periodic Timer Dispatch Protocol as defined in PI 1.1 Specification   Volume 4 System Management Mode Core Interface.    This protocol provides the parent dispatch service for the periodical timer SMI source generator.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This protocol is from PI Version 1.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_PERIODIC_TIMER_DISPATCH2_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_PERIODIC_TIMER_DISPATCH2_H_
end_define

begin_include
include|#
directive|include
file|<Pi/PiSmmCis.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL_GUID
define|\
value|{ \     0x4cec368e, 0x8e8e, 0x4d71, {0x8b, 0xe1, 0x95, 0x8c, 0x45, 0xfc, 0x8a, 0x53 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example: A chipset supports periodic SMIs on every 64ms or 2 seconds.
end_comment

begin_comment
comment|///   A child wishes schedule a period SMI to fire on a period of 3 seconds, there
end_comment

begin_comment
comment|///   are several ways to approach the problem:
end_comment

begin_comment
comment|///   1. The child may accept a 4 second periodic rate, in which case it registers with
end_comment

begin_comment
comment|///        Period = 40000
end_comment

begin_comment
comment|///        SmiTickInterval = 20000
end_comment

begin_comment
comment|///      The resulting SMI will occur every 2 seconds with the child called back on
end_comment

begin_comment
comment|///      every 2nd SMI.
end_comment

begin_comment
comment|///      NOTE: the same result would occur if the child set SmiTickInterval = 0.
end_comment

begin_comment
comment|///   2. The child may choose the finer granularity SMI (64ms):
end_comment

begin_comment
comment|///        Period = 30000
end_comment

begin_comment
comment|///        SmiTickInterval = 640
end_comment

begin_comment
comment|///      The resulting SMI will occur every 64ms with the child called back on
end_comment

begin_comment
comment|///      every 47th SMI.
end_comment

begin_comment
comment|///      NOTE: the child driver should be aware that this will result in more
end_comment

begin_comment
comment|///        SMIs occuring during system runtime which can negatively impact system
end_comment

begin_comment
comment|///        performance.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The minimum period of time in 100 nanosecond units that the child gets called. The
comment|/// child will be called back after a time greater than the time Period.
comment|///
name|UINT64
name|Period
decl_stmt|;
comment|///
comment|/// The period of time interval between SMIs. Children of this interface should use this
comment|/// field when registering for periodic timer intervals when a finer granularity periodic
comment|/// SMI is desired.
comment|///
name|UINT64
name|SmiTickInterval
decl_stmt|;
block|}
name|EFI_SMM_PERIODIC_TIMER_REGISTER_CONTEXT
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The DispatchFunction will be called with Context set to the same value as was passed into
end_comment

begin_comment
comment|/// Register() in RegisterContext and with CommBuffer pointing to an instance of
end_comment

begin_comment
comment|/// EFI_SMM_PERIODIC_TIMER_CONTEXT and CommBufferSize pointing to its size.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// ElapsedTime is the actual time in 100 nanosecond units elapsed since last called, a
comment|/// value of 0 indicates an unknown amount of time.
comment|///
name|UINT64
name|ElapsedTime
decl_stmt|;
block|}
name|EFI_SMM_PERIODIC_TIMER_CONTEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Register a child SMI source dispatch function for SMM periodic timer.    This service registers a function (DispatchFunction) which will be called when at least the    amount of time specified by RegisterContext has elapsed. On return, DispatchHandle    contains a unique handle which may be used later to unregister the function using UnRegister().   The DispatchFunction will be called with Context set to the same value as was passed into    this function in RegisterContext and with CommBuffer pointing to an instance of    EFI_SMM_PERIODIC_TIMER_CONTEXT and CommBufferSize pointing to its size.    @param[in]  This               Pointer to the EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL instance.   @param[in]  DispatchFunction   Function to register for handler when at least the specified amount                                  of time has elapsed.    @param[in]  RegisterContext    Pointer to the dispatch function's context.                                  The caller fills this context in before calling                                  the register function to indicate to the register                                  function the period at which the dispatch function                                  should be invoked.   @param[out] DispatchHandle     Handle generated by the dispatcher to track the function instance.     @retval EFI_SUCCESS            The dispatch function has been successfully                                  registered and the SMI source has been enabled.   @retval EFI_DEVICE_ERROR       The driver was unable to enable the SMI source.   @retval EFI_INVALID_PARAMETER  RegisterContext is invalid. The period input value                                  is not within valid range.   @retval EFI_OUT_OF_RESOURCES   There is not enough memory (system or SMM) to manage this child. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_PERIODIC_TIMER_REGISTER2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_SMM_HANDLER_ENTRY_POINT2
name|DispatchFunction
parameter_list|,
name|IN
name|CONST
name|EFI_SMM_PERIODIC_TIMER_REGISTER_CONTEXT
modifier|*
name|RegisterContext
parameter_list|,
name|OUT
name|EFI_HANDLE
modifier|*
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Unregisters a periodic timer service.    This service removes the handler associated with DispatchHandle so that it will no longer be    called when the time has elapsed.    @param[in] This                Pointer to the EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL instance.   @param[in] DispatchHandle      Handle of the service to remove.    @retval EFI_SUCCESS            The service has been successfully removed.   @retval EFI_INVALID_PARAMETER  The DispatchHandle was not valid. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_PERIODIC_TIMER_UNREGISTER2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HANDLE
name|DispatchHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Returns the next SMI tick period supported by the chipset.    The order returned is from longest to shortest interval period.    @param[in]     This             Pointer to the EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL instance.   @param[in,out] SmiTickInterval  Pointer to pointer of next shorter SMI interval                                   period supported by the child. This parameter works as a get-first,                                   get-next field.The first time this function is called, *SmiTickInterval                                   should be set to NULL to get the longest SMI interval.The returned                                   *SmiTickInterval should be passed in on subsequent calls to get the                                   next shorter interval period until *SmiTickInterval = NULL.    @retval EFI_SUCCESS             The service returned successfully. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_PERIODIC_TIMER_INTERVAL2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|UINT64
modifier|*
modifier|*
name|SmiTickInterval
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Interface structure for the SMM Periodic Timer Dispatch Protocol
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the parent dispatch service for the periodical timer SMI source generator.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_PERIODIC_TIMER_DISPATCH2_PROTOCOL
block|{
name|EFI_SMM_PERIODIC_TIMER_REGISTER2
name|Register
decl_stmt|;
name|EFI_SMM_PERIODIC_TIMER_UNREGISTER2
name|UnRegister
decl_stmt|;
name|EFI_SMM_PERIODIC_TIMER_INTERVAL2
name|GetNextShorterInterval
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmPeriodicTimerDispatch2ProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

