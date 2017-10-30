begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*   @File          error.c   @Description   General errors and events reporting utilities. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|DEBUG_ERRORS
argument_list|)
operator|&&
operator|(
name|DEBUG_ERRORS
operator|>
literal|0
operator|)
operator|)
end_if

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|dbgLevelStrings
index|[]
init|=
block|{
literal|"CRITICAL"
block|,
literal|"MAJOR"
block|,
literal|"MINOR"
block|,
literal|"WARNING"
block|,
literal|"INFO"
block|,
literal|"TRACE"
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|ErrTypeStrings
parameter_list|(
name|e_ErrorType
name|err
parameter_list|)
block|{
switch|switch
condition|(
name|err
condition|)
block|{
case|case
operator|(
name|E_OK
operator|)
case|:
return|return
literal|"OK"
return|;
case|case
operator|(
name|E_WRITE_FAILED
operator|)
case|:
return|return
literal|"Write Access Failed"
return|;
case|case
operator|(
name|E_NO_DEVICE
operator|)
case|:
return|return
literal|"No Device"
return|;
case|case
operator|(
name|E_NOT_AVAILABLE
operator|)
case|:
return|return
literal|"Resource Is Unavailable"
return|;
case|case
operator|(
name|E_NO_MEMORY
operator|)
case|:
return|return
literal|"Memory Allocation Failed"
return|;
case|case
operator|(
name|E_INVALID_ADDRESS
operator|)
case|:
return|return
literal|"Invalid Address"
return|;
case|case
operator|(
name|E_BUSY
operator|)
case|:
return|return
literal|"Resource Is Busy"
return|;
case|case
operator|(
name|E_ALREADY_EXISTS
operator|)
case|:
return|return
literal|"Resource Already Exists"
return|;
case|case
operator|(
name|E_INVALID_OPERATION
operator|)
case|:
return|return
literal|"Invalid Operation"
return|;
case|case
operator|(
name|E_INVALID_VALUE
operator|)
case|:
return|return
literal|"Invalid Value"
return|;
case|case
operator|(
name|E_NOT_IN_RANGE
operator|)
case|:
return|return
literal|"Value Out Of Range"
return|;
case|case
operator|(
name|E_NOT_SUPPORTED
operator|)
case|:
return|return
literal|"Unsupported Operation"
return|;
case|case
operator|(
name|E_INVALID_STATE
operator|)
case|:
return|return
literal|"Invalid State"
return|;
case|case
operator|(
name|E_INVALID_HANDLE
operator|)
case|:
return|return
literal|"Invalid Handle"
return|;
case|case
operator|(
name|E_INVALID_ID
operator|)
case|:
return|return
literal|"Invalid ID"
return|;
case|case
operator|(
name|E_NULL_POINTER
operator|)
case|:
return|return
literal|"Unexpected NULL Pointer"
return|;
case|case
operator|(
name|E_INVALID_SELECTION
operator|)
case|:
return|return
literal|"Invalid Selection"
return|;
case|case
operator|(
name|E_INVALID_COMM_MODE
operator|)
case|:
return|return
literal|"Invalid Communication Mode"
return|;
case|case
operator|(
name|E_INVALID_MEMORY_TYPE
operator|)
case|:
return|return
literal|"Invalid Memory Type"
return|;
case|case
operator|(
name|E_INVALID_CLOCK
operator|)
case|:
return|return
literal|"Invalid Clock"
return|;
case|case
operator|(
name|E_CONFLICT
operator|)
case|:
return|return
literal|"Conflict In Settings"
return|;
case|case
operator|(
name|E_NOT_ALIGNED
operator|)
case|:
return|return
literal|"Incorrect Alignment"
return|;
case|case
operator|(
name|E_NOT_FOUND
operator|)
case|:
return|return
literal|"Resource Not Found"
return|;
case|case
operator|(
name|E_FULL
operator|)
case|:
return|return
literal|"Resource Is Full"
return|;
case|case
operator|(
name|E_EMPTY
operator|)
case|:
return|return
literal|"Resource Is Empty"
return|;
case|case
operator|(
name|E_ALREADY_FREE
operator|)
case|:
return|return
literal|"Resource Already Free"
return|;
case|case
operator|(
name|E_READ_FAILED
operator|)
case|:
return|return
literal|"Read Access Failed"
return|;
case|case
operator|(
name|E_INVALID_FRAME
operator|)
case|:
return|return
literal|"Invalid Frame"
return|;
case|case
operator|(
name|E_SEND_FAILED
operator|)
case|:
return|return
literal|"Send Operation Failed"
return|;
case|case
operator|(
name|E_RECEIVE_FAILED
operator|)
case|:
return|return
literal|"Receive Operation Failed"
return|;
case|case
operator|(
name|E_TIMEOUT
operator|)
case|:
return|return
literal|"Operation Timed Out"
return|;
default|default:
break|break;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& (DEBUG_ERRORS> 0)) */
end_comment

end_unit

