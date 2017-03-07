begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Stall Services that do stall and also enable the Stall operatation   to be replayed during an S3 resume. This library class maps directly on top   of the Timer class.     Copyright (c) 2007, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/TimerLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/S3BootScriptLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/S3StallLib.h>
end_include

begin_comment
comment|/**   Stalls the CPU for at least the given number of microseconds and and saves   the value in the S3 script to be replayed on S3 resume.    Stalls the CPU for the number of microseconds specified by MicroSeconds.    @param  MicroSeconds  The minimum number of microseconds to delay.    @return MicroSeconds  **/
end_comment

begin_function
name|UINTN
name|EFIAPI
name|S3Stall
parameter_list|(
name|IN
name|UINTN
name|MicroSeconds
parameter_list|)
block|{
name|RETURN_STATUS
name|Status
decl_stmt|;
name|Status
operator|=
name|S3BootScriptSaveStall
argument_list|(
name|MicroSecondDelay
argument_list|(
name|MicroSeconds
argument_list|)
argument_list|)
expr_stmt|;
name|ASSERT
argument_list|(
name|Status
operator|==
name|RETURN_SUCCESS
argument_list|)
expr_stmt|;
return|return
name|MicroSeconds
return|;
block|}
end_function

end_unit

