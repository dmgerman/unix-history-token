begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 1999 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	printing cause values  *	---------------------  *  *	$Id: pcause_1tr6.c,v 1.6 1999/12/13 21:25:26 hm Exp $  *  * $FreeBSD$  *  *	last edit-date: [Mon Dec 13 21:56:03 1999]  *  *---------------------------------------------------------------------------*/
end_comment

begin_include
include|#
directive|include
file|"trace.h"
end_include

begin_include
include|#
directive|include
file|"pcause_1tr6.h"
end_include

begin_function
name|char
modifier|*
name|print_cause_1tr6
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
name|CAUSE_1TR6_SHUTDN
case|:
name|e
operator|=
literal|"normal D-channel shutdown"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_ICRV
case|:
name|e
operator|=
literal|"invalid call reference value"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_BSNI
case|:
name|e
operator|=
literal|"bearer service not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_CIDNE
case|:
name|e
operator|=
literal|"call identity does not exist"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_CIIU
case|:
name|e
operator|=
literal|"call identity in use"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NCA
case|:
name|e
operator|=
literal|"no channel available"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RFNI
case|:
name|e
operator|=
literal|"requested facility not implemented"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RFNS
case|:
name|e
operator|=
literal|"requested facility not subscribed"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_OCB
case|:
name|e
operator|=
literal|"outgoing calls barred"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_UAB
case|:
name|e
operator|=
literal|"user access busy"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NECUG
case|:
name|e
operator|=
literal|"non existent CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NECUG1
case|:
name|e
operator|=
literal|"non existent CUG"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_SPV
case|:
name|e
operator|=
literal|"kommunikationsbeziehung als SPV nicht erlaubt"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_DNO
case|:
name|e
operator|=
literal|"destination not obtainable"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NC
case|:
name|e
operator|=
literal|"number changed"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_OOO
case|:
name|e
operator|=
literal|"out of order"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NUR
case|:
name|e
operator|=
literal|"no user responding"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_UB
case|:
name|e
operator|=
literal|"user busy"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_ICB
case|:
name|e
operator|=
literal|"incoming calls barred"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_CR
case|:
name|e
operator|=
literal|"call rejected"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_NCO
case|:
name|e
operator|=
literal|"network congestion"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RUI
case|:
name|e
operator|=
literal|"remote user initiated"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_LPE
case|:
name|e
operator|=
literal|"local procedure error"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RPE
case|:
name|e
operator|=
literal|"remote procedure error"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RUS
case|:
name|e
operator|=
literal|"remote user suspended"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_RUR
case|:
name|e
operator|=
literal|"remote user resumed"
expr_stmt|;
break|break;
case|case
name|CAUSE_1TR6_UIDL
case|:
name|e
operator|=
literal|"user info discharded locally"
expr_stmt|;
break|break;
default|default:
name|e
operator|=
literal|"UNKNOWN error occured"
expr_stmt|;
break|break;
block|}
name|sprintf
argument_list|(
name|error_message
argument_list|,
literal|"0x%02x: %s"
argument_list|,
name|code
operator|&
literal|0x7f
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

