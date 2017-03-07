begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   NULL instance of SMM Library.    Copyright (c) 2009 - 2010, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_include
include|#
directive|include
file|<Base.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmmLib.h>
end_include

begin_comment
comment|/**   Triggers an SMI at boot time.      This function triggers a software SMM interrupt at boot time.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|TriggerBootServiceSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/**   Triggers an SMI at run time.      This function triggers a software SMM interrupt at run time.  **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|TriggerRuntimeSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/**   Test if a boot time software SMI happened.      This function tests if a software SMM interrupt happened. If a software SMM    interrupt happened and it was triggered at boot time, it returns TRUE. Otherwise,    it returns FALSE.    @retval TRUE   A software SMI triggered at boot time happened.   @retval FALSE  No software SMI happened or the software SMI was triggered at run time.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|IsBootServiceSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Test if a run time software SMI happened.      This function tests if a software SMM interrupt happened. If a software SMM    interrupt happened and it was triggered at run time, it returns TRUE. Otherwise,    it returns FALSE.    @retval TRUE   A software SMI triggered at run time happened.   @retval FALSE  No software SMI happened or the software SMI was triggered at boot time.  **/
end_comment

begin_function
name|BOOLEAN
name|EFIAPI
name|IsRuntimeSoftwareSmi
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/**   Clear APM SMI Status Bit; Set the EOS bit.     **/
end_comment

begin_function
name|VOID
name|EFIAPI
name|ClearSmi
parameter_list|(
name|VOID
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

