begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library services to make SAL Calls.  Copyright (c) 2007 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAL_LIB__
end_ifndef

begin_define
define|#
directive|define
name|__SAL_LIB__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Sal.h>
end_include

begin_comment
comment|/**   Makes a SAL procedure call.      This is a wrapper function to make a SAL procedure call.     No parameter checking is performed on the 8 input parameters,   but there are some common rules that the caller should follow   when making a SAL call.  Any address passed to SAL as buffers   for return parameters must be 8-byte aligned.  Unaligned   addresses may cause undefined results.  For those parameters   defined as reserved or some fields defined as reserved must be   zero filled or the invalid argument return value may be returned   or undefined result may occur during the execution of the procedure.   This function is only available on Intel Itanium-based platforms.    @param  Index       The SAL procedure Index number   @param  Arg2        The 2nd parameter for SAL procedure calls   @param  Arg3        The 3rd parameter for SAL procedure calls   @param  Arg4        The 4th parameter for SAL procedure calls   @param  Arg5        The 5th parameter for SAL procedure calls   @param  Arg6        The 6th parameter for SAL procedure calls   @param  Arg7        The 7th parameter for SAL procedure calls   @param  Arg8        The 8th parameter for SAL procedure calls    @return SAL returned registers.  **/
end_comment

begin_function_decl
name|SAL_RETURN_REGS
name|EFIAPI
name|SalCall
parameter_list|(
name|IN
name|UINT64
name|Index
parameter_list|,
name|IN
name|UINT64
name|Arg2
parameter_list|,
name|IN
name|UINT64
name|Arg3
parameter_list|,
name|IN
name|UINT64
name|Arg4
parameter_list|,
name|IN
name|UINT64
name|Arg5
parameter_list|,
name|IN
name|UINT64
name|Arg6
parameter_list|,
name|IN
name|UINT64
name|Arg7
parameter_list|,
name|IN
name|UINT64
name|Arg8
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

