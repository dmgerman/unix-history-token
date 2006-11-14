begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000-2005, LSI Logic Corporation and its contributors.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon including  *    a substantially similar Disclaimer requirement for further binary  *    redistribution.  * 3. Neither the name of the LSI Logic Corporation nor the names of its  *    contributors may be used to endorse or promote products derived from  *    this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF THE COPYRIGHT  * OWNER OR CONTRIBUTOR IS ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *  NAME:           fc_log.h  *  SUMMARY:        MPI IocLogInfo definitions for the SYMFC9xx chips  *  DESCRIPTION:    Contains the enumerated list of values that may be returned  *                  in the IOCLogInfo field of a MPI Default Reply Message.  *  *  CREATION DATE:  6/02/2000  *  ID:             $Id: //prod/main/platform/os/linux/drivers/message/fusion/lsi/mpi_log_fc.h#1 $  */
end_comment

begin_comment
comment|/*  * MpiIocLogInfo_t enum  *  * These 32 bit values are used in the IOCLogInfo field of the MPI reply  * messages.  * The value is 0xabcccccc where  *          a = The type of log info as per the MPI spec. Since these codes are  *              all for Fibre Channel this value will always be 2.  *          b = Specifies a subclass of the firmware where  *                  0 = FCP Initiator  *                  1 = FCP Target  *                  2 = LAN  *                  3 = MPI Message Layer  *                  4 = FC Link  *                  5 = Context Manager  *                  6 = Invalid Field Offset  *                  7 = State Change Info  *                  all others are reserved for future use  *          c = A specific value within the subclass.  *  * NOTE: Any new values should be added to the end of each subclass so that the  *       codes remain consistent across firmware releases.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_MpiIocLogInfoFc
block|{
name|MPI_IOCLOGINFO_FC_INIT_BASE
init|=
literal|0x20000000
block|,
name|MPI_IOCLOGINFO_FC_INIT_ERROR_OUT_OF_ORDER_FRAME
init|=
literal|0x20000001
block|,
comment|/* received an out of order frame - unsupported */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_BAD_START_OF_FRAME
init|=
literal|0x20000002
block|,
comment|/* Bad Rx Frame, bad start of frame primative */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_BAD_END_OF_FRAME
init|=
literal|0x20000003
block|,
comment|/* Bad Rx Frame, bad end of frame primative */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_OVER_RUN
init|=
literal|0x20000004
block|,
comment|/* Bad Rx Frame, overrun */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_RX_OTHER
init|=
literal|0x20000005
block|,
comment|/* Other errors caught by IOC which require retries */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_SUBPROC_DEAD
init|=
literal|0x20000006
block|,
comment|/* Main processor could not initialize sub-processor */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_RX_OVERRUN
init|=
literal|0x20000007
block|,
comment|/* Scatter Gather overrun  */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_RX_BAD_STATUS
init|=
literal|0x20000008
block|,
comment|/* Receiver detected context mismatch via invalid header */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_RX_UNEXPECTED_FRAME
init|=
literal|0x20000009
block|,
comment|/* CtxMgr detected unsupported frame type  */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_LINK_FAILURE
init|=
literal|0x2000000A
block|,
comment|/* Link failure occurred  */
name|MPI_IOCLOGINFO_FC_INIT_ERROR_TX_TIMEOUT
init|=
literal|0x2000000B
block|,
comment|/* Transmitter timeout error */
name|MPI_IOCLOGINFO_FC_TARGET_BASE
init|=
literal|0x21000000
block|,
name|MPI_IOCLOGINFO_FC_TARGET_NO_PDISC
init|=
literal|0x21000001
block|,
comment|/* not sent because we are waiting for a PDISC from the initiator */
name|MPI_IOCLOGINFO_FC_TARGET_NO_LOGIN
init|=
literal|0x21000002
block|,
comment|/* not sent because we are not logged in to the remote node */
name|MPI_IOCLOGINFO_FC_TARGET_DOAR_KILLED_BY_LIP
init|=
literal|0x21000003
block|,
comment|/* Data Out, Auto Response, not sent due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_DIAR_KILLED_BY_LIP
init|=
literal|0x21000004
block|,
comment|/* Data In, Auto Response, not sent due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_DIAR_MISSING_DATA
init|=
literal|0x21000005
block|,
comment|/* Data In, Auto Response, missing data frames */
name|MPI_IOCLOGINFO_FC_TARGET_DONR_KILLED_BY_LIP
init|=
literal|0x21000006
block|,
comment|/* Data Out, No Response, not sent due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_WRSP_KILLED_BY_LIP
init|=
literal|0x21000007
block|,
comment|/* Auto-response after a write not sent due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_DINR_KILLED_BY_LIP
init|=
literal|0x21000008
block|,
comment|/* Data In, No Response, not completed due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_DINR_MISSING_DATA
init|=
literal|0x21000009
block|,
comment|/* Data In, No Response, missing data frames */
name|MPI_IOCLOGINFO_FC_TARGET_MRSP_KILLED_BY_LIP
init|=
literal|0x2100000a
block|,
comment|/* Manual Response not sent due to a LIP */
name|MPI_IOCLOGINFO_FC_TARGET_NO_CLASS_3
init|=
literal|0x2100000b
block|,
comment|/* not sent because remote node does not support Class 3 */
name|MPI_IOCLOGINFO_FC_TARGET_LOGIN_NOT_VALID
init|=
literal|0x2100000c
block|,
comment|/* not sent because login to remote node not validated */
name|MPI_IOCLOGINFO_FC_TARGET_FROM_OUTBOUND
init|=
literal|0x2100000e
block|,
comment|/* cleared from the outbound queue after a logout */
name|MPI_IOCLOGINFO_FC_TARGET_WAITING_FOR_DATA_IN
init|=
literal|0x2100000f
block|,
comment|/* cleared waiting for data after a logout */
name|MPI_IOCLOGINFO_FC_LAN_BASE
init|=
literal|0x22000000
block|,
name|MPI_IOCLOGINFO_FC_LAN_TRANS_SGL_MISSING
init|=
literal|0x22000001
block|,
comment|/* Transaction Context Sgl Missing */
name|MPI_IOCLOGINFO_FC_LAN_TRANS_WRONG_PLACE
init|=
literal|0x22000002
block|,
comment|/* Transaction Context found before an EOB */
name|MPI_IOCLOGINFO_FC_LAN_TRANS_RES_BITS_SET
init|=
literal|0x22000003
block|,
comment|/* Transaction Context value has reserved bits set */
name|MPI_IOCLOGINFO_FC_LAN_WRONG_SGL_FLAG
init|=
literal|0x22000004
block|,
comment|/* Invalid SGL Flags */
name|MPI_IOCLOGINFO_FC_MSG_BASE
init|=
literal|0x23000000
block|,
name|MPI_IOCLOGINFO_FC_LINK_BASE
init|=
literal|0x24000000
block|,
name|MPI_IOCLOGINFO_FC_LINK_LOOP_INIT_TIMEOUT
init|=
literal|0x24000001
block|,
comment|/* Loop initialization timed out */
name|MPI_IOCLOGINFO_FC_LINK_ALREADY_INITIALIZED
init|=
literal|0x24000002
block|,
comment|/* Another system controller already initialized the loop */
name|MPI_IOCLOGINFO_FC_LINK_LINK_NOT_ESTABLISHED
init|=
literal|0x24000003
block|,
comment|/* Not synchronized to signal or still negotiating (possible cable problem) */
name|MPI_IOCLOGINFO_FC_LINK_CRC_ERROR
init|=
literal|0x24000004
block|,
comment|/* CRC check detected error on received frame */
name|MPI_IOCLOGINFO_FC_CTX_BASE
init|=
literal|0x25000000
block|,
name|MPI_IOCLOGINFO_FC_INVALID_FIELD_BYTE_OFFSET
init|=
literal|0x26000000
block|,
comment|/* The lower 24 bits give the byte offset of the field in the request message that is invalid */
name|MPI_IOCLOGINFO_FC_INVALID_FIELD_MAX_OFFSET
init|=
literal|0x26ffffff
block|,
name|MPI_IOCLOGINFO_FC_STATE_CHANGE
init|=
literal|0x27000000
comment|/* The lower 24 bits give additional information concerning state change */
block|}
name|MpiIocLogInfoFc_t
typedef|;
end_typedef

end_unit

