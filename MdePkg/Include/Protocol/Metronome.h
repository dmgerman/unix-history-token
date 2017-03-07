begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Metronome Architectural Protocol as defined in PI SPEC VOLUME 2 DXE    This code abstracts the DXE core to provide delay services.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_METRONOME_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_METRONOME_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Metronome Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_METRONOME_ARCH_PROTOCOL_GUID
define|\
value|{ 0x26baccb2, 0x6f42, 0x11d4, {0xbc, 0xe7, 0x0, 0x80, 0xc7, 0x3c, 0x88, 0x81 } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare forward reference for the Metronome Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_METRONOME_ARCH_PROTOCOL
name|EFI_METRONOME_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The WaitForTick() function waits for the number of ticks specified by    TickNumber from a known time source in the platform.  If TickNumber of    ticks are detected, then EFI_SUCCESS is returned.  The actual time passed    between entry of this function and the first tick is between 0 and    TickPeriod 100 nS units.  If you want to guarantee that at least TickPeriod    time has elapsed, wait for two ticks.  This function waits for a hardware    event to determine when a tick occurs.  It is possible for interrupt    processing, or exception processing to interrupt the execution of the    WaitForTick() function.  Depending on the hardware source for the ticks, it    is possible for a tick to be missed.  This function cannot guarantee that    ticks will not be missed.  If a timeout occurs waiting for the specified    number of ticks, then EFI_TIMEOUT is returned.    @param  This             The EFI_METRONOME_ARCH_PROTOCOL instance.   @param  TickNumber       Number of ticks to wait.    @retval EFI_SUCCESS           The wait for the number of ticks specified by TickNumber                                 succeeded.   @retval EFI_TIMEOUT           A timeout occurred waiting for the specified number of ticks.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_METRONOME_WAIT_FOR_TICK
function_decl|)
parameter_list|(
name|IN
name|EFI_METRONOME_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|TickNumber
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides access to a known time source in the platform to the
end_comment

begin_comment
comment|/// core.  The core uses this known time source to produce core services that
end_comment

begin_comment
comment|/// require calibrated delays.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_METRONOME_ARCH_PROTOCOL
block|{
name|EFI_METRONOME_WAIT_FOR_TICK
name|WaitForTick
decl_stmt|;
comment|///
comment|/// The period of platform's known time source in 100 nS units.
comment|/// This value on any platform must be at least 10 uS, and must not
comment|/// exceed 200 uS.  The value in this field is a constant that must
comment|/// not be modified after the Metronome architectural protocol is
comment|/// installed.  All consumers must treat this as a read-only field.
comment|///
name|UINT32
name|TickPeriod
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiMetronomeArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

