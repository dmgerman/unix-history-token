begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	pcause.c - printing cause values  *	--------------------------------  *  *	$Id: pcause.c,v 1.5 1999/12/13 21:25:25 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Mon Dec 13 21:51:20 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"decode.h"
end_include

begin_include
include|#
directive|include
file|"pcause.h"
end_include

begin_function
name|char
modifier|*
name|print_cause_q850
parameter_list|(
name|unsigned
name|char
name|code
parameter_list|)
block|{
specifier|static
name|char
name|error_message
index|[
literal|120
index|]
decl_stmt|;
name|char
modifier|*
name|e
decl_stmt|;
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|CAUSE_Q850_SHUTDN
case|:
name|e
operator|=
literal|"normal D-channel shutdown"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NUNALLC
case|:
name|e
operator|=
literal|"Unallocated (unassigned) number"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NRTTN
case|:
name|e
operator|=
literal|"No route to specified transit network"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NRTDST
case|:
name|e
operator|=
literal|"No route to destination"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SSINFTN
case|:
name|e
operator|=
literal|"Send special information tone"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MDIALTP
case|:
name|e
operator|=
literal|"Misdialled trunk prefix"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CHUNACC
case|:
name|e
operator|=
literal|"Channel unacceptable"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CALLAWD
case|:
name|e
operator|=
literal|"Call awarded and being delivered in an established channel"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PREEMPT
case|:
name|e
operator|=
literal|"Preemption"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PREECRR
case|:
name|e
operator|=
literal|"Preemption - circuit reserved for reuse"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NCCLR
case|:
name|e
operator|=
literal|"Normal call clearing"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_USRBSY
case|:
name|e
operator|=
literal|"User busy"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NOUSRRSP
case|:
name|e
operator|=
literal|"No user responding"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NOANSWR
case|:
name|e
operator|=
literal|"No answer from user (user alerted)"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SUBSABS
case|:
name|e
operator|=
literal|"Subscriber absent"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CALLREJ
case|:
name|e
operator|=
literal|"Call rejected"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NUCHNG
case|:
name|e
operator|=
literal|"Number changed"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NONSELUC
case|:
name|e
operator|=
literal|"Non-selected user clearing"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_DSTOOORDR
case|:
name|e
operator|=
literal|"Destination out of order"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INVNUFMT
case|:
name|e
operator|=
literal|"Invalid number format"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_FACREJ
case|:
name|e
operator|=
literal|"Facility rejected"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_STENQRSP
case|:
name|e
operator|=
literal|"Response to STATUS ENQUIRY"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NORMUNSP
case|:
name|e
operator|=
literal|"Normal, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NOCAVAIL
case|:
name|e
operator|=
literal|"No circuit / channel available"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NETOOORDR
case|:
name|e
operator|=
literal|"Network out of order"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PFMCDOOSERV
case|:
name|e
operator|=
literal|"Permanent frame mode connection out of service"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PFMCOPER
case|:
name|e
operator|=
literal|"Permanent frame mode connection operational"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_TMPFAIL
case|:
name|e
operator|=
literal|"Temporary failure"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SWEQCONG
case|:
name|e
operator|=
literal|"Switching equipment congestion"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_ACCINFDIS
case|:
name|e
operator|=
literal|"Access information discarded"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_REQCNOTAV
case|:
name|e
operator|=
literal|"Requested circuit/channel not available"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PRECALBLK
case|:
name|e
operator|=
literal|"Precedence call blocked"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_RESUNAVAIL
case|:
name|e
operator|=
literal|"Resources unavailable, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_QOSUNAVAIL
case|:
name|e
operator|=
literal|"Quality of service unavailable"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_REQSERVNS
case|:
name|e
operator|=
literal|"Requested facility not subscribed"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_OCBARRCUG
case|:
name|e
operator|=
literal|"Outgoing calls barred within CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_ICBARRCUG
case|:
name|e
operator|=
literal|"Incoming calls barred within CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_BCAPNAUTH
case|:
name|e
operator|=
literal|"Bearer capability not authorized"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_BCAPNAVAIL
case|:
name|e
operator|=
literal|"Bearer capability not presently available"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INCSTOACISC
case|:
name|e
operator|=
literal|"Inconsistenciy in designated outg. access info and subscriber class"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SOONOTAVAIL
case|:
name|e
operator|=
literal|"Service or option not available, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_BCAPNOTIMPL
case|:
name|e
operator|=
literal|"Bearer capability not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CHTYPNIMPL
case|:
name|e
operator|=
literal|"Channel type not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_REQFACNIMPL
case|:
name|e
operator|=
literal|"Requested facility not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_ORDINBCAVL
case|:
name|e
operator|=
literal|"Only restricted digital information bearer capability is available"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SOONOTIMPL
case|:
name|e
operator|=
literal|"Service or option not implemented, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INVCLRFVAL
case|:
name|e
operator|=
literal|"Invalid call reference value"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_IDCHDNOEX
case|:
name|e
operator|=
literal|"Identified channel does not exist"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_SUSCAEXIN
case|:
name|e
operator|=
literal|"A suspended call exists, but this call identity does not"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CLIDINUSE
case|:
name|e
operator|=
literal|"Call identity in use"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NOCLSUSP
case|:
name|e
operator|=
literal|"No call suspended"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_CLIDCLRD
case|:
name|e
operator|=
literal|"Call having the requested call identity has been cleared"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_UNOTMEMCUG
case|:
name|e
operator|=
literal|"User not member of CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INCDEST
case|:
name|e
operator|=
literal|"Incompatible destination"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_NONEXCUG
case|:
name|e
operator|=
literal|"Non-existent CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INVNTWSEL
case|:
name|e
operator|=
literal|"Invalid transit network selection"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INVMSG
case|:
name|e
operator|=
literal|"Invalid message, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MIEMISS
case|:
name|e
operator|=
literal|"Mandatory information element is missing"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MSGTNI
case|:
name|e
operator|=
literal|"Message type non-existent or not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MSGNCMPT
case|:
name|e
operator|=
literal|"Msg incompatible with call state/message type non-existent/not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_IENENI
case|:
name|e
operator|=
literal|"Information element/parameter non-existent or not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INVIEC
case|:
name|e
operator|=
literal|"Invalid information element contents"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MSGNCWCS
case|:
name|e
operator|=
literal|"Message not compatible with call state"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_RECOTIMEXP
case|:
name|e
operator|=
literal|"Recovery on timer expiry"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PARMNENIPO
case|:
name|e
operator|=
literal|"Parameter non-existent or not implemented, passed on"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_MSGUNRDPRM
case|:
name|e
operator|=
literal|"Message with unrecognized parameter, discarded"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_PROTERR
case|:
name|e
operator|=
literal|"Protocol error, unspecified"
expr_stmt|;
break|break;
case|case
name|CAUSE_Q850_INTWRKU
case|:
name|e
operator|=
literal|"Interworking, unspecified"
expr_stmt|;
break|break;
default|default:
name|e
operator|=
literal|"ERROR, unknown cause value!"
expr_stmt|;
break|break;
block|}
name|sprintf
argument_list|(
name|error_message
argument_list|,
literal|"%d: %s (Q.850)"
argument_list|,
name|code
argument_list|,
name|e
argument_list|)
expr_stmt|;
return|return
operator|(
name|error_message
operator|)
return|;
block|}
end_function

begin_comment
comment|/* EOF */
end_comment

end_unit

