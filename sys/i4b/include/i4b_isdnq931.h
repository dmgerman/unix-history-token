begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2002 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_isdnq931.h - DSS1 layer 3 message types  *	-------------------------------------------  *  * $FreeBSD$  *  *	last edit-date: [Sat Mar  9 15:53:49 2002]  *  *---------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/* protocol discriminators */
end_comment

begin_define
define|#
directive|define
name|PD_Q931
value|0x08
end_define

begin_comment
comment|/* Q.931/I.451				*/
end_comment

begin_comment
comment|/* Q.931 single octett information element identifiers */
end_comment

begin_define
define|#
directive|define
name|IEI_SENDCOMPL
value|0xa1
end_define

begin_comment
comment|/* sending complete			*/
end_comment

begin_comment
comment|/* Q.931 variable length information element identifiers */
end_comment

begin_define
define|#
directive|define
name|IEI_SEGMMSG
value|0x00
end_define

begin_comment
comment|/* segmented message			*/
end_comment

begin_define
define|#
directive|define
name|IEI_BEARERCAP
value|0x04
end_define

begin_comment
comment|/* bearer capabilities			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CAUSE
value|0x08
end_define

begin_comment
comment|/* cause 				*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLID
value|0x10
end_define

begin_comment
comment|/* call identity			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLSTATE
value|0x14
end_define

begin_comment
comment|/* call state				*/
end_comment

begin_define
define|#
directive|define
name|IEI_CHANNELID
value|0x18
end_define

begin_comment
comment|/* channel identification 		*/
end_comment

begin_define
define|#
directive|define
name|IEI_PROGRESSI
value|0x1e
end_define

begin_comment
comment|/* progress indicator			*/
end_comment

begin_define
define|#
directive|define
name|IEI_NETSPCFAC
value|0x20
end_define

begin_comment
comment|/* network specific facilities		*/
end_comment

begin_define
define|#
directive|define
name|IEI_NOTIFIND
value|0x27
end_define

begin_comment
comment|/* notification indicator		*/
end_comment

begin_define
define|#
directive|define
name|IEI_DISPLAY
value|0x28
end_define

begin_comment
comment|/* display				*/
end_comment

begin_define
define|#
directive|define
name|IEI_DATETIME
value|0x29
end_define

begin_comment
comment|/* date/time				*/
end_comment

begin_define
define|#
directive|define
name|IEI_KEYPAD
value|0x2c
end_define

begin_comment
comment|/* keypad facility			*/
end_comment

begin_define
define|#
directive|define
name|IEI_SIGNAL
value|0x34
end_define

begin_comment
comment|/* signal				*/
end_comment

begin_define
define|#
directive|define
name|IEI_INFRATE
value|0x40
end_define

begin_comment
comment|/* information rate			*/
end_comment

begin_define
define|#
directive|define
name|IEI_ETETDEL
value|0x42
end_define

begin_comment
comment|/* end to end transit delay		*/
end_comment

begin_define
define|#
directive|define
name|IEI_TDELSELIND
value|0x43
end_define

begin_comment
comment|/* transit delay selection and indication */
end_comment

begin_define
define|#
directive|define
name|IEI_PLBPARMS
value|0x44
end_define

begin_comment
comment|/* packet layer binary parameters	*/
end_comment

begin_define
define|#
directive|define
name|IEI_PLWSIZE
value|0x45
end_define

begin_comment
comment|/* packet layer window size		*/
end_comment

begin_define
define|#
directive|define
name|IEI_PSIZE
value|0x46
end_define

begin_comment
comment|/* packet size				*/
end_comment

begin_define
define|#
directive|define
name|IEI_CUG
value|0x47
end_define

begin_comment
comment|/* closed user group			*/
end_comment

begin_define
define|#
directive|define
name|IEI_REVCHRGI
value|0x4a
end_define

begin_comment
comment|/* reverse charge indication		*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLINGPN
value|0x6c
end_define

begin_comment
comment|/* calling party number			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLINGPS
value|0x6d
end_define

begin_comment
comment|/* calling party subaddress		*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLEDPN
value|0x70
end_define

begin_comment
comment|/* called party number			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CALLEDPS
value|0x71
end_define

begin_comment
comment|/* called party subaddress		*/
end_comment

begin_define
define|#
directive|define
name|IEI_REDIRNO
value|0x74
end_define

begin_comment
comment|/* redirecting number			*/
end_comment

begin_define
define|#
directive|define
name|IEI_TRNSEL
value|0x78
end_define

begin_comment
comment|/* transit network selection		*/
end_comment

begin_define
define|#
directive|define
name|IEI_RESTARTI
value|0x79
end_define

begin_comment
comment|/* restart indicator			*/
end_comment

begin_define
define|#
directive|define
name|IEI_LLCOMPAT
value|0x7c
end_define

begin_comment
comment|/* low layer compatibility		*/
end_comment

begin_define
define|#
directive|define
name|IEI_HLCOMPAT
value|0x7d
end_define

begin_comment
comment|/* high layer compatibility		*/
end_comment

begin_define
define|#
directive|define
name|IEI_USERUSER
value|0x7e
end_define

begin_comment
comment|/* user-user				*/
end_comment

begin_define
define|#
directive|define
name|IEI_ESCAPE
value|0x7f
end_define

begin_comment
comment|/* escape for extension			*/
end_comment

begin_comment
comment|/* Q.932 variable length information element identifiers */
end_comment

begin_define
define|#
directive|define
name|IEI_EXTFAC
value|0x0d
end_define

begin_comment
comment|/* extended facility			*/
end_comment

begin_define
define|#
directive|define
name|IEI_FACILITY
value|0x1c
end_define

begin_comment
comment|/* facility				*/
end_comment

begin_define
define|#
directive|define
name|IEI_INFOREQ
value|0x32
end_define

begin_comment
comment|/* information request 			*/
end_comment

begin_define
define|#
directive|define
name|IEI_FEATACT
value|0x38
end_define

begin_comment
comment|/* feature activation 			*/
end_comment

begin_define
define|#
directive|define
name|IEI_FEATIND
value|0x39
end_define

begin_comment
comment|/* feature indication			*/
end_comment

begin_define
define|#
directive|define
name|IEI_SERVPID
value|0x3a
end_define

begin_comment
comment|/* service profile identification	*/
end_comment

begin_define
define|#
directive|define
name|IEI_ENDPTID
value|0x3b
end_define

begin_comment
comment|/* endpoint identifier			*/
end_comment

begin_comment
comment|/* Q.933 variable length information element identifiers */
end_comment

begin_define
define|#
directive|define
name|IEI_DATALCID
value|0x19
end_define

begin_comment
comment|/* data link connection identifier	*/
end_comment

begin_define
define|#
directive|define
name|IEI_LLCOREP
value|0x48
end_define

begin_comment
comment|/* link layer core parameters		*/
end_comment

begin_define
define|#
directive|define
name|IEI_LLPROTP
value|0x49
end_define

begin_comment
comment|/* link layer protocol parameters	*/
end_comment

begin_define
define|#
directive|define
name|IEI_X213PRI
value|0x50
end_define

begin_comment
comment|/* X.213 priority 			*/
end_comment

begin_define
define|#
directive|define
name|IEI_REPORTT
value|0x51
end_define

begin_comment
comment|/* report type				*/
end_comment

begin_define
define|#
directive|define
name|IEI_LNKITYVERF
value|0x53
end_define

begin_comment
comment|/* link integrity verification		*/
end_comment

begin_define
define|#
directive|define
name|IEI_PVCSTAT
value|0x57
end_define

begin_comment
comment|/* PVC status				*/
end_comment

begin_comment
comment|/* Q.95x variable length information element identifiers */
end_comment

begin_define
define|#
directive|define
name|IEI_PRECLEV
value|0x41
end_define

begin_comment
comment|/* precedence level			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CONCTDNO
value|0x4c
end_define

begin_comment
comment|/* connected number			*/
end_comment

begin_define
define|#
directive|define
name|IEI_CONCTDSA
value|0x4d
end_define

begin_comment
comment|/* connected subaddress			*/
end_comment

begin_define
define|#
directive|define
name|IEI_REDICNNO
value|0x76
end_define

begin_comment
comment|/* redirection number			*/
end_comment

begin_comment
comment|/* single octett information elements */
end_comment

begin_define
define|#
directive|define
name|SOIE_SHIFT
value|0x90
end_define

begin_comment
comment|/* shift codeset			*/
end_comment

begin_define
define|#
directive|define
name|SHIFT_LOCK
value|0x08
end_define

begin_comment
comment|/* shift codeset, locking shift bit	*/
end_comment

begin_define
define|#
directive|define
name|SOIE_MDSC
value|0xa0
end_define

begin_comment
comment|/* more data AND/OR sending complete	*/
end_comment

begin_define
define|#
directive|define
name|SOIE_SENDC
value|0xa1
end_define

begin_comment
comment|/* sending complete			*/
end_comment

begin_define
define|#
directive|define
name|SOIE_CONGL
value|0xb0
end_define

begin_comment
comment|/* congestion level			*/
end_comment

begin_define
define|#
directive|define
name|SOIE_REPTI
value|0xd0
end_define

begin_comment
comment|/* repeat indicator			*/
end_comment

begin_comment
comment|/* codesets */
end_comment

begin_define
define|#
directive|define
name|CODESET_0
value|0
end_define

begin_comment
comment|/* codeset 0, normal DSS1 codeset	*/
end_comment

begin_comment
comment|/* Q.931/Q.932 message types (see Q.931 03/93 p10 and p311) */
end_comment

begin_comment
comment|/* call establishment messages */
end_comment

begin_define
define|#
directive|define
name|ALERT
value|0x01
end_define

begin_define
define|#
directive|define
name|CALL_PROCEEDING
value|0x02
end_define

begin_define
define|#
directive|define
name|PROGRESS
value|0x03
end_define

begin_define
define|#
directive|define
name|SETUP
value|0x05
end_define

begin_define
define|#
directive|define
name|CONNECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SETUP_ACKNOWLEDGE
value|0x0d
end_define

begin_define
define|#
directive|define
name|CONNECT_ACKNOWLEDGE
value|0x0f
end_define

begin_comment
comment|/* call information phase messages */
end_comment

begin_define
define|#
directive|define
name|USER_INFORMATION
value|0x20
end_define

begin_define
define|#
directive|define
name|SUSPEND_REJECT
value|0x21
end_define

begin_define
define|#
directive|define
name|RESUME_REJECT
value|0x22
end_define

begin_define
define|#
directive|define
name|HOLD
value|0x24
end_define

begin_define
define|#
directive|define
name|SUSPEND
value|0x25
end_define

begin_define
define|#
directive|define
name|RESUME
value|0x26
end_define

begin_define
define|#
directive|define
name|HOLD_ACKNOWLEDGE
value|0x28
end_define

begin_define
define|#
directive|define
name|SUSPEND_ACKNOWLEDGE
value|0x2d
end_define

begin_define
define|#
directive|define
name|RESUME_ACKNOWLEDGE
value|0x2e
end_define

begin_define
define|#
directive|define
name|HOLD_REJECT
value|0x30
end_define

begin_define
define|#
directive|define
name|RETRIEVE
value|0x31
end_define

begin_define
define|#
directive|define
name|RETRIEVE_ACKNOWLEDGE
value|0x32
end_define

begin_define
define|#
directive|define
name|RETRIEVE_REJECT
value|0x37
end_define

begin_comment
comment|/* call clearing */
end_comment

begin_define
define|#
directive|define
name|DISCONNECT
value|0x45
end_define

begin_define
define|#
directive|define
name|RESTART
value|0x46
end_define

begin_define
define|#
directive|define
name|RELEASE
value|0x4d
end_define

begin_define
define|#
directive|define
name|RESTART_ACKNOWLEDGE
value|0x4e
end_define

begin_define
define|#
directive|define
name|RELEASE_COMPLETE
value|0x5a
end_define

begin_comment
comment|/* misc messages */
end_comment

begin_define
define|#
directive|define
name|SEGMENT
value|0x60
end_define

begin_define
define|#
directive|define
name|FACILITY
value|0x62
end_define

begin_define
define|#
directive|define
name|REGISTER
value|0x64
end_define

begin_define
define|#
directive|define
name|NOTIFY
value|0x6e
end_define

begin_define
define|#
directive|define
name|STATUS_ENQUIRY
value|0x75
end_define

begin_define
define|#
directive|define
name|CONGESTION_CONTROL
value|0x79
end_define

begin_define
define|#
directive|define
name|INFORMATION
value|0x7b
end_define

begin_define
define|#
directive|define
name|STATUS
value|0x7d
end_define

begin_comment
comment|/* EOF */
end_comment

end_unit

