begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 2008-2011 Freescale Semiconductor, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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

begin_decl_stmt
specifier|const
name|char
modifier|*
name|errTypeStrings
index|[]
init|=
block|{
literal|"Invalid State"
comment|/* E_INVALID_STATE */
block|,
literal|"Invalid Operation"
comment|/* E_INVALID_OPERATION */
block|,
literal|"Unsupported Operation"
comment|/* E_NOT_SUPPORTED */
block|,
literal|"No Device"
comment|/* E_NO_DEVICE */
block|,
literal|"Invalid Handle"
comment|/* E_INVALID_HANDLE */
block|,
literal|"Invalid ID"
comment|/* E_INVALID_ID */
block|,
literal|"Unexpected NULL Pointer"
comment|/* E_NULL_POINTER */
block|,
literal|"Invalid Value"
comment|/* E_INVALID_VALUE */
block|,
literal|"Invalid Selection"
comment|/* E_INVALID_SELECTION */
block|,
literal|"Invalid Communication Mode"
comment|/* E_INVALID_COMM_MODE */
block|,
literal|"Invalid Byte Order"
comment|/* E_INVALID_BYTE_ORDER */
block|,
literal|"Invalid Memory Type"
comment|/* E_INVALID_MEMORY_TYPE */
block|,
literal|"Invalid Interrupt Queue"
comment|/* E_INVALID_INTR_QUEUE */
block|,
literal|"Invalid Priority"
comment|/* E_INVALID_PRIORITY */
block|,
literal|"Invalid Clock"
comment|/* E_INVALID_CLOCK */
block|,
literal|"Invalid Rate"
comment|/* E_INVALID_RATE */
block|,
literal|"Invalid Address"
comment|/* E_INVALID_ADDRESS */
block|,
literal|"Invalid Bus"
comment|/* E_INVALID_BUS */
block|,
literal|"Conflict In Bus Selection"
comment|/* E_BUS_CONFLICT */
block|,
literal|"Conflict In Settings"
comment|/* E_CONFLICT */
block|,
literal|"Incorrect Alignment"
comment|/* E_NOT_ALIGNED */
block|,
literal|"Value Out Of Range"
comment|/* E_NOT_IN_RANGE */
block|,
literal|"Invalid Frame"
comment|/* E_INVALID_FRAME */
block|,
literal|"Frame Is Empty"
comment|/* E_EMPTY_FRAME */
block|,
literal|"Buffer Is Empty"
comment|/* E_EMPTY_BUFFER */
block|,
literal|"Memory Allocation Failed"
comment|/* E_NO_MEMORY */
block|,
literal|"Resource Not Found"
comment|/* E_NOT_FOUND */
block|,
literal|"Resource Is Unavailable"
comment|/* E_NOT_AVAILABLE */
block|,
literal|"Resource Already Exists"
comment|/* E_ALREADY_EXISTS */
block|,
literal|"Resource Is Full"
comment|/* E_FULL */
block|,
literal|"Resource Is Empty"
comment|/* E_EMPTY */
block|,
literal|"Resource Is Busy"
comment|/* E_BUSY */
block|,
literal|"Resource Already Free"
comment|/* E_ALREADY_FREE */
block|,
literal|"Read Access Failed"
comment|/* E_READ_FAILED */
block|,
literal|"Write Access Failed"
comment|/* E_WRITE_FAILED */
block|,
literal|"Send Operation Failed"
comment|/* E_SEND_FAILED */
block|,
literal|"Receive Operation Failed"
comment|/* E_RECEIVE_FAILED */
block|,
literal|"Operation Timed Out"
comment|/* E_TIMEOUT */
block|}
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|REPORT_EVENTS
argument_list|)
operator|&&
operator|(
name|REPORT_EVENTS
operator|>
literal|0
operator|)
operator|)
end_if

begin_decl_stmt
specifier|const
name|char
modifier|*
name|eventStrings
index|[]
init|=
block|{
literal|"Rx Discard"
comment|/* EV_RX_DISCARD */
block|,
literal|"Rx Error"
comment|/* EV_RX_ERROR */
block|,
literal|"Tx Error"
comment|/* EV_TX_ERROR */
block|,
literal|"No Buffer Objects"
comment|/* EV_NO_BUFFERS */
block|,
literal|"No MB-Frame Objects"
comment|/* EV_NO_MB_FRAMES */
block|,
literal|"No SB-Frame Objects"
comment|/* EV_NO_SB_FRAMES */
block|,
literal|"Tx Queue Is Full"
comment|/* EV_TX_QUEUE_FULL */
block|,
literal|"Rx Queue Is Full"
comment|/* EV_RX_QUEUE_FULL */
block|,
literal|"Interrupts Queue Is Full"
comment|/* EV_INTR_QUEUE_FULL */
block|,
literal|"Data Buffer Is Unavailable"
comment|/* EV_NO_DATA_BUFFER */
block|,
literal|"Objects Pool Is Empty"
comment|/* EV_OBJ_POOL_EMPTY */
block|,
literal|"Illegal bus access"
comment|/* EV_BUS_ERROR */
block|,
literal|"PTP Tx Timestamps Queue Is Full"
comment|/* EV_PTP_TXTS_QUEUE_FULL */
block|,
literal|"PTP Rx Timestamps Queue Is Full"
comment|/* EV_PTP_RXTS_QUEUE_FULL */
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(REPORT_EVENTS)&& (REPORT_EVENTS> 0)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (defined(DEBUG_ERRORS)&& (DEBUG_ERRORS> 0)) */
end_comment

end_unit

