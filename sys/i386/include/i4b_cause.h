begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_cause.h - causes and cause handling for i4b  *	-----------------------------------------------  *  *	$Id: i4b_cause.h,v 1.13 2000/02/06 19:01:14 hm Exp $  *  * $FreeBSD$  *  *      last edit-date: [Sun Feb  6 19:46:41 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_CAUSE_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_CAUSE_H_
end_define

begin_comment
comment|/*---------------------------------------------------------------------------*  *	ISDN4BSD internal causes specification  *---------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_VAL
value|0x000000ff
end_define

begin_comment
comment|/* cause value			*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_TYPE
value|0x0000ff00
end_define

begin_comment
comment|/* cause type			*/
end_comment

begin_define
define|#
directive|define
name|CAUSET_Q850
value|0
end_define

begin_comment
comment|/* value coded according to Q.850 */
end_comment

begin_define
define|#
directive|define
name|CAUSET_I4B
value|1
end_define

begin_comment
comment|/* i4b protocol independent causes*/
end_comment

begin_define
define|#
directive|define
name|GET_CAUSE_VAL
parameter_list|(
name|cause
parameter_list|)
value|((cause)& 0xff)
end_define

begin_define
define|#
directive|define
name|SET_CAUSE_VAL
parameter_list|(
name|dest
parameter_list|,
name|val
parameter_list|)
value|((dest) = ((dest& 0xffffff00) | \ 						(val& 0x000000ff)))
end_define

begin_define
define|#
directive|define
name|GET_CAUSE_TYPE
parameter_list|(
name|cause
parameter_list|)
value|(((cause)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|SET_CAUSE_TYPE
parameter_list|(
name|dest
parameter_list|,
name|type
parameter_list|)
value|((dest) = ((dest& 0xffff00ff) | \ 						((type<< 8)& 0x0000ff00)))
end_define

begin_define
define|#
directive|define
name|SET_CAUSE_TV
parameter_list|(
name|dest
parameter_list|,
name|type
parameter_list|,
name|val
parameter_list|)
value|((dest) = ((val& 0x000000ff) | \ 						 ((type<< 8)& 0x0000ff00)))
end_define

begin_comment
comment|/* CAUSET_I4B - protocol independent cause values */
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_NORMAL
value|0
end_define

begin_comment
comment|/* normal call clearing 	*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_BUSY
value|1
end_define

begin_comment
comment|/* user busy			*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_NOCHAN
value|2
end_define

begin_comment
comment|/* circuit/channel not available*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_INCOMP
value|3
end_define

begin_comment
comment|/* incompatible source/dest	*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_REJECT
value|4
end_define

begin_comment
comment|/* call rejected		*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_OOO
value|5
end_define

begin_comment
comment|/* destination out of order	*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_TMPFAIL
value|6
end_define

begin_comment
comment|/* temporary failure		*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_L1ERROR
value|7
end_define

begin_comment
comment|/* L1 error / persistent deact	*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_LLDIAL
value|8
end_define

begin_comment
comment|/* no dialout on leased line	*/
end_comment

begin_define
define|#
directive|define
name|CAUSE_I4B_MAX
value|9
end_define

begin_comment
comment|/* NOTE: update isdnd/pcause.c when adding causes !!!!!		*/
end_comment

begin_comment
comment|/* NOTE: update layer3/i4b_q931.c when adding causes !!!!!	*/
end_comment

begin_comment
comment|/* CAUSET_Q850 - causes defined in Q.850 */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SHUTDN
value|0x00
end_define

begin_comment
comment|/* normal D-channel shutdown */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NUNALLC
value|0x01
end_define

begin_comment
comment|/* Unallocated (unassigned) number */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NRTTN
value|0x02
end_define

begin_comment
comment|/* No route to specified transit network */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NRTDST
value|0x03
end_define

begin_comment
comment|/* No route to destination */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SSINFTN
value|0x04
end_define

begin_comment
comment|/* Send special information tone */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MDIALTP
value|0x05
end_define

begin_comment
comment|/* Misdialled trunk prefix */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CHUNACC
value|0x06
end_define

begin_comment
comment|/* Channel unacceptable */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CALLAWD
value|0x07
end_define

begin_comment
comment|/* Call awarded and being delivered in an established channel */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PREEMPT
value|0x08
end_define

begin_comment
comment|/* Preemption */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PREECRR
value|0x09
end_define

begin_comment
comment|/* Preemption - circuit reserved for reuse */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NCCLR
value|0x10
end_define

begin_comment
comment|/* Normal call clearing */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_USRBSY
value|0x11
end_define

begin_comment
comment|/* User busy */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NOUSRRSP
value|0x12
end_define

begin_comment
comment|/* No user responding */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NOANSWR
value|0x13
end_define

begin_comment
comment|/* No answer from user (user alerted) */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SUBSABS
value|0x14
end_define

begin_comment
comment|/* Subscriber absent */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CALLREJ
value|0x15
end_define

begin_comment
comment|/* Call rejected */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NUCHNG
value|0x16
end_define

begin_comment
comment|/* Number changed */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NONSELUC
value|0x1A
end_define

begin_comment
comment|/* Non-selected user clearing */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_DSTOOORDR
value|0x1B
end_define

begin_comment
comment|/* Destination out of order */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INVNUFMT
value|0x1C
end_define

begin_comment
comment|/* Invalid number format */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_FACREJ
value|0x1D
end_define

begin_comment
comment|/* Facility rejected */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_STENQRSP
value|0x1E
end_define

begin_comment
comment|/* Response to STATUS ENQUIRY */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NORMUNSP
value|0x1F
end_define

begin_comment
comment|/* Normal, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NOCAVAIL
value|0x22
end_define

begin_comment
comment|/* No circuit / channel available */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NETOOORDR
value|0x26
end_define

begin_comment
comment|/* Network out of order */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PFMCDOOSERV
value|0x27
end_define

begin_comment
comment|/* Permanent frame mode connection out of service */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PFMCOPER
value|0x28
end_define

begin_comment
comment|/* Permanent frame mode connection operational */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_TMPFAIL
value|0x29
end_define

begin_comment
comment|/* Temporary failure */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SWEQCONG
value|0x2A
end_define

begin_comment
comment|/* Switching equipment congestion */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_ACCINFDIS
value|0x2B
end_define

begin_comment
comment|/* Access information discarded */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_REQCNOTAV
value|0x2C
end_define

begin_comment
comment|/* Requested circuit/channel not available */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PRECALBLK
value|0x2E
end_define

begin_comment
comment|/* Precedence call blocked */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_RESUNAVAIL
value|0x2F
end_define

begin_comment
comment|/* Resources unavailable, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_QOSUNAVAIL
value|0x31
end_define

begin_comment
comment|/* Quality of service unavailable */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_REQSERVNS
value|0x32
end_define

begin_comment
comment|/* Requested facility not subscribed */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_OCBARRCUG
value|0x35
end_define

begin_comment
comment|/* Outgoing calls barred within CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_ICBARRCUG
value|0x36
end_define

begin_comment
comment|/* Incoming calls barred within CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_BCAPNAUTH
value|0x39
end_define

begin_comment
comment|/* Bearer capability not authorized */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_BCAPNAVAIL
value|0x3A
end_define

begin_comment
comment|/* Bearer capability not presently available */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INCSTOACISC
value|0x3E
end_define

begin_comment
comment|/* Inconsistenciy in designated outgoing access information and subscriber class */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SOONOTAVAIL
value|0x3F
end_define

begin_comment
comment|/* Service or option not available, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_BCAPNOTIMPL
value|0x41
end_define

begin_comment
comment|/* Bearer capability not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CHTYPNIMPL
value|0x42
end_define

begin_comment
comment|/* Channel type not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_REQFACNIMPL
value|0x45
end_define

begin_comment
comment|/* Requested facility not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_ORDINBCAVL
value|0x46
end_define

begin_comment
comment|/* Only restricted digital information bearer capability is available */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SOONOTIMPL
value|0x4F
end_define

begin_comment
comment|/* Service or option not implemented, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INVCLRFVAL
value|0x51
end_define

begin_comment
comment|/* Invalid call reference value */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_IDCHDNOEX
value|0x52
end_define

begin_comment
comment|/* Identified channel does not exist */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_SUSCAEXIN
value|0x53
end_define

begin_comment
comment|/* A suspended call exists, but this call identity does not */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CLIDINUSE
value|0x54
end_define

begin_comment
comment|/* Call identity in use */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NOCLSUSP
value|0x55
end_define

begin_comment
comment|/* No call suspended */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_CLIDCLRD
value|0x56
end_define

begin_comment
comment|/* Call having the requested call identity has been cleared */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_UNOTMEMCUG
value|0x57
end_define

begin_comment
comment|/* User not member of CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INCDEST
value|0x58
end_define

begin_comment
comment|/* Incompatible destination */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_NONEXCUG
value|0x5A
end_define

begin_comment
comment|/* Non-existent CUG */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INVNTWSEL
value|0x5B
end_define

begin_comment
comment|/* Invalid transit network selection */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INVMSG
value|0x5F
end_define

begin_comment
comment|/* Invalid message, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MIEMISS
value|0x60
end_define

begin_comment
comment|/* Mandatory information element is missing */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MSGTNI
value|0x61
end_define

begin_comment
comment|/* Message type non-existent or not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MSGNCMPT
value|0x62
end_define

begin_comment
comment|/* Message not compatible with call state or message type non-existent or not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_IENENI
value|0x63
end_define

begin_comment
comment|/* Information element/parameter non-existent or not implemented */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INVIEC
value|0x64
end_define

begin_comment
comment|/* Invalid information element contents */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MSGNCWCS
value|0x65
end_define

begin_comment
comment|/* Message not compatible with call state */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_RECOTIMEXP
value|0x66
end_define

begin_comment
comment|/* Recovery on timer expiry */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PARMNENIPO
value|0x67
end_define

begin_comment
comment|/* Parameter non-existent or not implemented, passed on */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MSGUNRDPRM
value|0x6E
end_define

begin_comment
comment|/* Message with unrecognized parameter, discarded */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_PROTERR
value|0x6F
end_define

begin_comment
comment|/* Protocol error, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_INTWRKU
value|0x7F
end_define

begin_comment
comment|/* Interworking, unspecified */
end_comment

begin_define
define|#
directive|define
name|CAUSE_Q850_MAX
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_CAUSE_H_ */
end_comment

end_unit

