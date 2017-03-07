begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file Internal header file for Smbus library.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License which accompanies this distribution.  The full text of the license may be found at http://opensource.org/licenses/bsd-license.php  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.   **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__INTERNAL_SMBUS_LIB_H_
end_ifndef

begin_define
define|#
directive|define
name|__INTERNAL_SMBUS_LIB_H_
end_define

begin_include
include|#
directive|include
file|<PiPei.h>
end_include

begin_include
include|#
directive|include
file|<Ppi/Smbus2.h>
end_include

begin_include
include|#
directive|include
file|<Library/SmbusLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/DebugLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/PeiServicesLib.h>
end_include

begin_include
include|#
directive|include
file|<Library/BaseMemoryLib.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Declaration for internal functions
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/**   Gets Smbus PPIs.    This internal function retrieves Smbus PPI from PPI database.    @param  VOID    @return The pointer to Smbus PPI.  **/
end_comment

begin_function_decl
name|EFI_PEI_SMBUS2_PPI
modifier|*
name|InternalGetSmbusPpi
parameter_list|(
name|VOID
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   Executes an SMBus operation to an SMBus controller.    This function provides a standard way to execute Smbus script   as defined in the SmBus Specification. The data can either be of   the Length byte, word, or a block of data.    @param  SmbusOperation  Signifies which particular SMBus hardware protocol                            instance that it will use to execute the SMBus transactions.   @param  SmBusAddress    The address that encodes the SMBUS Slave Address,                           SMBUS Command, SMBUS Data Length, and PEC.   @param  Length          Signifies the number of bytes that this operation will                            do. The maximum number of bytes can be revision specific                            and operation specific.   @param  Buffer          Contains the value of data to execute to the SMBus slave                            device. Not all operations require this argument. The                            length of this buffer is identified by Length.   @param  Status          Return status for the executed command.                           This is an optional parameter and may be NULL.    @return The actual number of bytes that are executed for this operation.  **/
end_comment

begin_function_decl
name|UINTN
name|InternalSmBusExec
parameter_list|(
name|IN
name|EFI_SMBUS_OPERATION
name|SmbusOperation
parameter_list|,
name|IN
name|UINTN
name|SmBusAddress
parameter_list|,
name|IN
name|UINTN
name|Length
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|Buffer
parameter_list|,
name|OUT
name|RETURN_STATUS
modifier|*
name|Status
name|OPTIONAL
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

