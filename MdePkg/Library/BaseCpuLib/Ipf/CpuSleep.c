begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Base Library CPU functions for Itanium    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php.    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Library/PalLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseLib.h>
end_include

begin_comment
comment|/**   Places the CPU in a sleep state until an interrupt is received.    Places the CPU in a sleep state until an interrupt is received. If interrupts   are disabled prior to calling this function, then the CPU will be placed in a   sleep state indefinitely.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|CpuSleep
parameter_list|(
name|VOID
parameter_list|)
block|{
name|UINT64
name|Tpr
decl_stmt|;
comment|//
comment|// It is the TPR register that controls if external interrupt would bring processor in LIGHT HALT low-power state
comment|// back to normal state. PAL_HALT_LIGHT does not depend on PSR setting.
comment|// So here if interrupts are disabled (via PSR.i), TRP.mmi needs to be set to prevent processor being interrupted by external interrupts.
comment|// If interrupts are enabled, then just use current TRP setting.
comment|//
if|if
condition|(
name|GetInterruptState
argument_list|()
condition|)
block|{
comment|//
comment|// If interrupts are enabled, then call PAL_HALT_LIGHT with the current TPR setting.
comment|//
name|PalCall
argument_list|(
name|PAL_HALT_LIGHT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|//
comment|// If interrupts are disabled on entry, then mask all interrupts in TPR before calling PAL_HALT_LIGHT.
comment|//
comment|//
comment|// Save TPR
comment|//
name|Tpr
operator|=
name|AsmReadTpr
argument_list|()
expr_stmt|;
comment|//
comment|// Set TPR.mmi to mask all external interrupts
comment|//
name|AsmWriteTpr
argument_list|(
name|BIT16
operator||
name|Tpr
argument_list|)
expr_stmt|;
name|PalCall
argument_list|(
name|PAL_HALT_LIGHT
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//
comment|// Restore TPR
comment|//
name|AsmWriteTpr
argument_list|(
name|Tpr
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

