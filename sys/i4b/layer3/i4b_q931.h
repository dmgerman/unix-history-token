begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997, 2000 Hellmuth Michaelis. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *---------------------------------------------------------------------------  *  *	i4b_q931.h - Q931 handling header file  *	--------------------------------------  *  *	$Id: i4b_q931.h,v 1.9 2000/04/27 09:25:22 hm Exp $   *  * $FreeBSD$  *  *      last edit-date: [Thu Apr 27 11:07:37 2000]  *  *---------------------------------------------------------------------------*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I4B_Q931_H_
end_ifndef

begin_define
define|#
directive|define
name|_I4B_Q931_H_
end_define

begin_comment
comment|/* extension bit */
end_comment

begin_define
define|#
directive|define
name|EXT_LAST
value|0x80
end_define

begin_comment
comment|/* last octett */
end_comment

begin_comment
comment|/* reserve space in mbuf */
end_comment

begin_define
define|#
directive|define
name|I_FRAME_HDRLEN
value|4
end_define

begin_comment
comment|/* to be added by layer 2 */
end_comment

begin_comment
comment|/* SHIFT */
end_comment

begin_define
define|#
directive|define
name|CODESET_MASK
value|0x07
end_define

begin_define
define|#
directive|define
name|UNSHIFTED
value|0
end_define

begin_define
define|#
directive|define
name|SHIFTED
value|1
end_define

begin_define
define|#
directive|define
name|CRLENGTH_MASK
value|0x0f
end_define

begin_comment
comment|/* CONNECT */
end_comment

begin_define
define|#
directive|define
name|MSG_CONNECT_LEN
value|4
end_define

begin_comment
comment|/* length of a connect message */
end_comment

begin_comment
comment|/* DISCONNECT */
end_comment

begin_define
define|#
directive|define
name|MSG_DISCONNECT_LEN
value|8
end_define

begin_comment
comment|/* length of a disconnect message */
end_comment

begin_comment
comment|/* RELEASE COMPLETE */
end_comment

begin_define
define|#
directive|define
name|MSG_RELEASE_COMPLETE_LEN
value|8
end_define

begin_comment
comment|/* length of release complete msg */
end_comment

begin_comment
comment|/* for outgoing causes */
end_comment

begin_define
define|#
directive|define
name|CAUSE_LEN
value|2
end_define

begin_define
define|#
directive|define
name|CAUSE_STD_LOC_OUT
value|0x80
end_define

begin_comment
comment|/* std = CCITT, loc = user */
end_comment

begin_comment
comment|/* SETUP */
end_comment

begin_define
define|#
directive|define
name|MSG_SETUP_LEN
value|18
end_define

begin_comment
comment|/* without number strings ! */
end_comment

begin_define
define|#
directive|define
name|IEI_BEARERCAP_LEN
value|2
end_define

begin_comment
comment|/* 2 octetts lenght */
end_comment

begin_define
define|#
directive|define
name|IT_CAP_SPEECH
value|0x80
end_define

begin_comment
comment|/* BC: information xfer capability */
end_comment

begin_define
define|#
directive|define
name|IT_CAP_UNR_DIG_INFO
value|0x88
end_define

begin_comment
comment|/* BC: information xfer capability */
end_comment

begin_define
define|#
directive|define
name|IT_RATE_64K
value|0x90
end_define

begin_comment
comment|/* BC: information xfer rate */
end_comment

begin_define
define|#
directive|define
name|IT_UL1_G711A
value|0xa3
end_define

begin_comment
comment|/* layer1 proto G.711 A-law */
end_comment

begin_define
define|#
directive|define
name|IEI_CHANNELID_LEN
value|0x01
end_define

begin_comment
comment|/* length of channel id		*/
end_comment

begin_define
define|#
directive|define
name|CHANNELID_B1
value|0x81
end_define

begin_comment
comment|/* channel = B1 (outgoing) */
end_comment

begin_define
define|#
directive|define
name|CHANNELID_B2
value|0x82
end_define

begin_comment
comment|/* channel = B2 (outgoing) */
end_comment

begin_define
define|#
directive|define
name|CHANNELID_ANY
value|0x83
end_define

begin_comment
comment|/* channel = any channel (outgoing) */
end_comment

begin_define
define|#
directive|define
name|IE_CHAN_ID_NO
value|0x00
end_define

begin_comment
comment|/* no channel (incoming)	*/
end_comment

begin_define
define|#
directive|define
name|IE_CHAN_ID_B1
value|0x01
end_define

begin_comment
comment|/* B1 channel (incoming)	*/
end_comment

begin_define
define|#
directive|define
name|IE_CHAN_ID_B2
value|0x02
end_define

begin_comment
comment|/* B2 channel (incoming)	*/
end_comment

begin_define
define|#
directive|define
name|IE_CHAN_ID_ANY
value|0x03
end_define

begin_comment
comment|/* ANY channel (incoming)	*/
end_comment

begin_define
define|#
directive|define
name|NUMBER_TYPEPLAN
value|0x81
end_define

begin_comment
comment|/* type of number/numbering plan */
end_comment

begin_define
define|#
directive|define
name|IEI_CALLINGPN_LEN
value|1
end_define

begin_comment
comment|/* without number string ! */
end_comment

begin_define
define|#
directive|define
name|IEI_CALLEDPN_LEN
value|1
end_define

begin_comment
comment|/* without number string ! */
end_comment

begin_comment
comment|/* CONNECT_ACK */
end_comment

begin_define
define|#
directive|define
name|MSG_CONNECT_ACK_LEN
value|4
end_define

begin_comment
comment|/* length of a connect ack message */
end_comment

begin_comment
comment|/* STATUS */
end_comment

begin_define
define|#
directive|define
name|MSG_STATUS_LEN
value|11
end_define

begin_define
define|#
directive|define
name|CALLSTATE_LEN
value|1
end_define

begin_comment
comment|/* RELEASE */
end_comment

begin_define
define|#
directive|define
name|MSG_RELEASE_LEN
value|8
end_define

begin_comment
comment|/* length of release msg */
end_comment

begin_comment
comment|/* ALERT */
end_comment

begin_define
define|#
directive|define
name|MSG_ALERT_LEN
value|4
end_define

begin_comment
comment|/* length of a alert message */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I4B_Q931_H_ */
end_comment

begin_comment
comment|/* EOF */
end_comment

end_unit

