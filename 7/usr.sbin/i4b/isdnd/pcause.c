begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	printing cause values  *	---------------------  *  *	$Id: pcause.c,v 1.13 2000/10/09 12:53:29 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Mon Dec 13 21:48:07 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"isdnd.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cause_i4b_tab
index|[
name|CAUSE_I4B_MAX
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cause_q850_tab
index|[
name|CAUSE_Q850_MAX
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|print_i4b_cause
parameter_list|(
name|cause_t
name|code
parameter_list|)
block|{
specifier|static
name|char
name|error_message
index|[
literal|128
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|error_message
argument_list|,
sizeof|sizeof
argument_list|(
name|error_message
argument_list|)
argument_list|,
literal|"%d: "
argument_list|,
name|GET_CAUSE_VAL
argument_list|(
name|code
argument_list|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|GET_CAUSE_TYPE
argument_list|(
name|code
argument_list|)
condition|)
block|{
case|case
name|CAUSET_Q850
case|:
name|strcat
argument_list|(
name|error_message
argument_list|,
name|cause_q850_tab
index|[
name|GET_CAUSE_VAL
argument_list|(
name|code
argument_list|)
index|]
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|error_message
argument_list|,
literal|" (Q.850)"
argument_list|)
expr_stmt|;
break|break;
case|case
name|CAUSET_I4B
case|:
if|if
condition|(
operator|(
name|GET_CAUSE_VAL
argument_list|(
name|code
argument_list|)
operator|<
name|CAUSE_I4B_NORMAL
operator|)
operator|||
operator|(
name|GET_CAUSE_VAL
argument_list|(
name|code
argument_list|)
operator|>=
name|CAUSE_I4B_MAX
operator|)
condition|)
block|{
name|SET_CAUSE_VAL
argument_list|(
name|code
argument_list|,
name|CAUSE_I4B_MAX
argument_list|)
expr_stmt|;
block|}
name|strcat
argument_list|(
name|error_message
argument_list|,
name|cause_i4b_tab
index|[
name|GET_CAUSE_VAL
argument_list|(
name|code
argument_list|)
index|]
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|error_message
argument_list|,
literal|" (I4B)"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|strcat
argument_list|(
name|error_message
argument_list|,
literal|"ERROR: unknown cause type!"
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|error_message
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cause_i4b_tab
index|[
name|CAUSE_I4B_MAX
operator|+
literal|1
index|]
init|=
block|{
literal|"normal call clearing"
block|,
literal|"user busy"
block|,
literal|"channel not available"
block|,
literal|"incompatible source or destination"
block|,
literal|"call rejected"
block|,
literal|"destination out of order"
block|,
literal|"temporary failure"
block|,
literal|"layer 1 error / persistent deactivation"
block|,
literal|"dialing impossible on leased line"
block|,
literal|"ERROR, invalid I4B cause value!"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|cause_q850_tab
index|[
name|CAUSE_Q850_MAX
index|]
init|=
block|{
literal|"Normal D-channel shutdown"
block|,
literal|"Unallocated (unassigned) number"
block|,
literal|"No route to specified transit network (national use)"
block|,
literal|"No route to destination"
block|,
literal|"Send special information tone"
block|,
literal|"Misdialled trunk prefix (national use)"
block|,
literal|"Channel unacceptable"
block|,
literal|"Call awarded and being delivered in an established channel"
block|,
literal|"Preemption"
block|,
literal|"Preemption - circuit reserved for reuse"
block|,
comment|/*10*/
literal|"cause code 10: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 11: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 12: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 13: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 14: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 15: error, unassigned in Q.850 (03/93)"
block|,
literal|"Normal call clearing"
block|,
literal|"User busy"
block|,
literal|"No user responding"
block|,
literal|"No answer from user (user alerted)"
block|,
comment|/*20*/
literal|"Subscriber absent"
block|,
literal|"Call rejected"
block|,
literal|"Number changed"
block|,
literal|"cause code 23: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 24: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 25: error, unassigned in Q.850 (03/93)"
block|,
literal|"Non-selected user clearing"
block|,
literal|"Destination out of order"
block|,
literal|"Invalid number format"
block|,
literal|"Facility rejected"
block|,
comment|/*30*/
literal|"Response to STATUS ENQUIRY"
block|,
literal|"Normal, unspecified"
block|,
literal|"cause code 32: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 33: error, unassigned in Q.850 (03/93)"
block|,
literal|"No circuit / channel available"
block|,
literal|"cause code 35: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 36: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 37: error, unassigned in Q.850 (03/93)"
block|,
literal|"Network out of order"
block|,
literal|"Permanent frame mode connection out of service"
block|,
comment|/*40*/
literal|"Permanent frame mode connection operational"
block|,
literal|"Temporary failure"
block|,
literal|"Switching equipment congestion"
block|,
literal|"Access information discarded"
block|,
literal|"Requested circuit/channel not available"
block|,
literal|"cause code 45: error, unassigned in Q.850 (03/93)"
block|,
literal|"Precedence call blocked"
block|,
literal|"Resources unavailable, unspecified"
block|,
literal|"cause code 48: error, unassigned in Q.850 (03/93)"
block|,
literal|"Quality of service unavailable"
block|,
comment|/*50*/
literal|"Requested facility not subscribed"
block|,
literal|"cause code 51: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 52: error, unassigned in Q.850 (03/93)"
block|,
literal|"Outgoing calls barred within CUG"
block|,
literal|"cause code 54: error, unassigned in Q.850 (03/93)"
block|,
literal|"Incoming calls barred within CUG"
block|,
literal|"cause code 56: error, unassigned in Q.850 (03/93)"
block|,
literal|"Bearer capability not authorized"
block|,
literal|"Bearer capability not presently available"
block|,
literal|"cause code 59: error, unassigned in Q.850 (03/93)"
block|,
comment|/*60*/
literal|"cause code 60: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 61: error, unassigned in Q.850 (03/93)"
block|,
literal|"Inconsistenciy in designated outg. access info and subscriber class"
block|,
literal|"Service or option not available, unspecified"
block|,
literal|"cause code 64: error, unassigned in Q.850 (03/93)"
block|,
literal|"Bearer capability not implemented"
block|,
literal|"Channel type not implemented"
block|,
literal|"cause code 67: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 68: error, unassigned in Q.850 (03/93)"
block|,
literal|"Requested facility not implemented"
block|,
comment|/*70*/
literal|"Only restricted digital information bearer capability is available"
block|,
literal|"cause code 71: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 72: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 73: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 74: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 75: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 76: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 77: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 78: error, unassigned in Q.850 (03/93)"
block|,
literal|"Service or option not implemented, unspecified"
block|,
comment|/*80*/
literal|"cause code 80: error, unassigned in Q.850 (03/93)"
block|,
literal|"Invalid call reference value"
block|,
literal|"Identified channel does not exist"
block|,
literal|"A suspended call exists, but this call identity does not"
block|,
literal|"Call identity in use"
block|,
literal|"No call suspended"
block|,
literal|"Call having the requested call identity has been cleared"
block|,
literal|"User not member of CUG"
block|,
literal|"Incompatible destination"
block|,
literal|"cause code 89: error, unassigned in Q.850 (03/93)"
block|,
comment|/*90*/
literal|"Non-existent CUG"
block|,
literal|"Invalid transit network selection"
block|,
literal|"cause code 92: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 93: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 94: error, unassigned in Q.850 (03/93)"
block|,
literal|"Invalid message, unspecified"
block|,
literal|"Mandatory information element is missing"
block|,
literal|"Message type non-existent or not implemented"
block|,
literal|"Message not compatible with call state or message type non-existent or not implemented"
block|,
literal|"Information element/parameter non-existent or not implemented"
block|,
comment|/*100*/
literal|"Invalid information element contents"
block|,
literal|"Message not compatible with call state"
block|,
literal|"Recovery on timer expiry"
block|,
literal|"Parameter non-existent or not implemented, passed on"
block|,
literal|"cause code 104: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 105: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 106: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 107: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 108: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 109: error, unassigned in Q.850 (03/93)"
block|,
comment|/*110*/
literal|"Message with unrecognized parameter, discarded"
block|,
literal|"Protocol error, unspecified"
block|,
literal|"cause code 112: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 113: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 114: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 115: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 116: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 117: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 118: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 119: error, unassigned in Q.850 (03/93)"
block|,
comment|/*120*/
literal|"cause code 120: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 121: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 122: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 123: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 124: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 125: error, unassigned in Q.850 (03/93)"
block|,
literal|"cause code 126: error, unassigned in Q.850 (03/93)"
block|,
literal|"Interworking, unspecified"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* EOF */
end_comment

end_unit

