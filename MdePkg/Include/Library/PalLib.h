begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Provides library services to make PAL Calls.      The PAL Library provides a service to make a PAL CALL.  This service is identical   in functionality to AsmPalCall() in the functions of the Base Library specific to Intel Itanium architecture.   The only difference is that the PAL Entry Point is not passed in.  Implementations   of this library class must manage PAL Entry Point on their own.  For example, a PEI   implementation can use a PPI to lookup the PAL Entry Point, and a DXE implementation   can contain a constructor to look up the PAL Entry Point from a HOB.  This library class    is only available on Intel Itanium-based platforms.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials                           are licensed and made available under the terms and conditions of the BSD License          which accompanies this distribution.  The full text of the license may be found at         http://opensource.org/licenses/bsd-license.php                                              THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAL_CALL_LIB_H__
end_ifndef

begin_define
define|#
directive|define
name|__PAL_CALL_LIB_H__
end_define

begin_include
include|#
directive|include
file|<IndustryStandard/Pal.h>
end_include

begin_comment
comment|/**   Makes a PAL procedure call.    This is a wrapper function to make a PAL procedure call.  Based on the Index value,   this API will make static or stacked PAL call. Architected procedures may be designated   as required or optional.  If a PAL procedure is specified as optional, a unique return   code of 0xFFFFFFFFFFFFFFFF is returned in the Status field of the PAL_CALL_RETURN structure.   This indicates that the procedure is not present in this PAL implementation.  It is the   caller's responsibility to check for this return code after calling any optional PAL   procedure. No parameter checking is performed on the 4 input parameters, but there are   some common rules that the caller should follow when making a PAL call.  Any address   passed to PAL as buffers for return parameters must be 8-byte aligned.  Unaligned addresses   may cause undefined results.  For those parameters defined as reserved or some fields   defined as reserved must be zero filled or the invalid argument return value may be   returned or undefined result may occur during the execution of the procedure.   This function is only available on Intel Itanium-based platforms.    @param Index  The PAL procedure Index number.   @param Arg2   The 2nd parameter for PAL procedure calls.   @param Arg3   The 3rd parameter for PAL procedure calls.   @param Arg4   The 4th parameter for PAL procedure calls.    @return Structure returned from the PAL Call procedure, including the status and return value.  **/
end_comment

begin_function_decl
name|PAL_CALL_RETURN
name|EFIAPI
name|PalCall
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
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

