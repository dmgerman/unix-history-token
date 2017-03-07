begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides CPU architecture specific functions that can not be defined   in the Base Library due to dependencies on the PAL Library      The CPU Library provides services to flush CPU TLBs and place the CPU in a sleep state.   The implementation of these services on Itanium processors requires the use of PAL Calls.   PAL Calls require PEI and DXE specific mechanisms to look up PAL Entry Point.   As a result, these services could not be defined in the Base Library.  Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CPU_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__CPU_LIB_H__
end_define

begin_comment
comment|/**   Places the CPU in a sleep state until an interrupt is received.    Places the CPU in a sleep state until an interrupt is received. If interrupts   are disabled prior to calling this function, then the CPU will be placed in a   sleep state indefinitely.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CpuSleep
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Flushes all the Translation Lookaside Buffers(TLB) entries in a CPU.    Flushes all the Translation Lookaside Buffers(TLB) entries in a CPU.  **/
end_comment

begin_function_decl
name|VOID
name|EFIAPI
name|CpuFlushTlb
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

