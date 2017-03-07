begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides calibrated delay and performance counter services.  Copyright (c) 2006 - 2011, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TIMER_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__TIMER_LIB__
end_define

begin_comment
comment|/**   Stalls the CPU for at least the given number of microseconds.    Stalls the CPU for the number of microseconds specified by MicroSeconds.    @param  MicroSeconds  The minimum number of microseconds to delay.    @return The value of MicroSeconds inputted.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|MicroSecondDelay
parameter_list|(
name|IN
name|UINTN
name|MicroSeconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Stalls the CPU for at least the given number of nanoseconds.    Stalls the CPU for the number of nanoseconds specified by NanoSeconds.    @param  NanoSeconds The minimum number of nanoseconds to delay.    @return The value of NanoSeconds inputted.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|NanoSecondDelay
parameter_list|(
name|IN
name|UINTN
name|NanoSeconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the current value of a 64-bit free running performance counter.    The counter can either count up by 1 or count down by 1. If the physical   performance counter counts by a larger increment, then the counter values   must be translated. The properties of the counter can be retrieved from   GetPerformanceCounterProperties().    @return The current value of the free running performance counter.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|GetPerformanceCounter
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Retrieves the 64-bit frequency in Hz and the range of performance counter   values.    If StartValue is not NULL, then the value that the performance counter starts   with immediately after is it rolls over is returned in StartValue. If   EndValue is not NULL, then the value that the performance counter end with   immediately before it rolls over is returned in EndValue. The 64-bit   frequency of the performance counter in Hz is always returned. If StartValue   is less than EndValue, then the performance counter counts up. If StartValue   is greater than EndValue, then the performance counter counts down. For   example, a 64-bit free running counter that counts up would have a StartValue   of 0 and an EndValue of 0xFFFFFFFFFFFFFFFF. A 24-bit free running counter   that counts down would have a StartValue of 0xFFFFFF and an EndValue of 0.    @param  StartValue  The value the performance counter starts with when it                       rolls over.   @param  EndValue    The value that the performance counter ends with before                       it rolls over.    @return The frequency in Hz.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|GetPerformanceCounterProperties
parameter_list|(
name|OUT
name|UINT64
modifier|*
name|StartValue
parameter_list|,
name|OPTIONAL
name|OUT
name|UINT64
modifier|*
name|EndValue
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Converts elapsed ticks of performance counter to time in nanoseconds.    This function converts the elapsed ticks of running performance counter to   time value in unit of nanoseconds.    @param  Ticks     The number of elapsed ticks of running performance counter.    @return The elapsed time in nanoseconds.  **/
end_comment

begin_function_decl
name|UINT64
name|EFIAPI
name|GetTimeInNanoSecond
parameter_list|(
name|IN
name|UINT64
name|Ticks
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

