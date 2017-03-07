begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Stall Services that perform stalls and also enable the Stall operatation   to be replayed during an S3 resume. This library class maps directly on top   of the Timer class.     Copyright (c) 2007 - 2010, Intel Corporation. All rights reserved.<BR>    This program and the accompanying materials   are licensed and made available under the terms and conditions   of the BSD License which accompanies this distribution.  The   full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__S3_STALL_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__S3_STALL_LIB_H__
end_define

begin_comment
comment|/**   Stalls the CPU for at least the given number of microseconds and saves   the value in the S3 script to be replayed on S3 resume.    Stalls the CPU for the number of microseconds specified by MicroSeconds.    @param[in] MicroSeconds   The minimum number of microseconds to delay.    @return   MicroSeconds.  **/
end_comment

begin_function_decl
name|UINTN
name|EFIAPI
name|S3Stall
parameter_list|(
name|IN
name|UINTN
name|MicroSeconds
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

