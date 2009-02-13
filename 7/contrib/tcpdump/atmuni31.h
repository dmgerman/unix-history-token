begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997 Yen Yen Lim and North Dakota State University  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Yen Yen Lim and         North Dakota State University  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * @(#) $Header: /tcpdump/master/tcpdump/atmuni31.h,v 1.2 2002/08/05 07:47:23 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/* Based on UNI3.1 standard by ATM Forum */
end_comment

begin_comment
comment|/* ATM traffic types based on VPI=0 and (the following VCI */
end_comment

begin_define
define|#
directive|define
name|PPC
value|0x05
end_define

begin_comment
comment|/* Point-to-point signal msg */
end_comment

begin_define
define|#
directive|define
name|BCC
value|0x02
end_define

begin_comment
comment|/* Broadcast signal msg */
end_comment

begin_define
define|#
directive|define
name|OAMF4SC
value|0x03
end_define

begin_comment
comment|/* Segment OAM F4 flow cell */
end_comment

begin_define
define|#
directive|define
name|OAMF4EC
value|0x04
end_define

begin_comment
comment|/* End-to-end OAM F4 flow cell */
end_comment

begin_define
define|#
directive|define
name|METAC
value|0x01
end_define

begin_comment
comment|/* Meta signal msg */
end_comment

begin_define
define|#
directive|define
name|ILMIC
value|0x10
end_define

begin_comment
comment|/* ILMI msg */
end_comment

begin_comment
comment|/* Q.2931 signalling messages */
end_comment

begin_define
define|#
directive|define
name|CALL_PROCEED
value|0x02
end_define

begin_comment
comment|/* call proceeding */
end_comment

begin_define
define|#
directive|define
name|CONNECT
value|0x07
end_define

begin_comment
comment|/* connect */
end_comment

begin_define
define|#
directive|define
name|CONNECT_ACK
value|0x0f
end_define

begin_comment
comment|/* connect_ack */
end_comment

begin_define
define|#
directive|define
name|SETUP
value|0x05
end_define

begin_comment
comment|/* setup */
end_comment

begin_define
define|#
directive|define
name|RELEASE
value|0x4d
end_define

begin_comment
comment|/* release */
end_comment

begin_define
define|#
directive|define
name|RELEASE_DONE
value|0x5a
end_define

begin_comment
comment|/* release_done */
end_comment

begin_define
define|#
directive|define
name|RESTART
value|0x46
end_define

begin_comment
comment|/* restart */
end_comment

begin_define
define|#
directive|define
name|RESTART_ACK
value|0x4e
end_define

begin_comment
comment|/* restart ack */
end_comment

begin_define
define|#
directive|define
name|STATUS
value|0x7d
end_define

begin_comment
comment|/* status */
end_comment

begin_define
define|#
directive|define
name|STATUS_ENQ
value|0x75
end_define

begin_comment
comment|/* status ack */
end_comment

begin_define
define|#
directive|define
name|ADD_PARTY
value|0x80
end_define

begin_comment
comment|/* add party */
end_comment

begin_define
define|#
directive|define
name|ADD_PARTY_ACK
value|0x81
end_define

begin_comment
comment|/* add party ack */
end_comment

begin_define
define|#
directive|define
name|ADD_PARTY_REJ
value|0x82
end_define

begin_comment
comment|/* add party rej */
end_comment

begin_define
define|#
directive|define
name|DROP_PARTY
value|0x83
end_define

begin_comment
comment|/* drop party */
end_comment

begin_define
define|#
directive|define
name|DROP_PARTY_ACK
value|0x84
end_define

begin_comment
comment|/* drop party ack */
end_comment

begin_comment
comment|/* Information Element Parameters in the signalling messages */
end_comment

begin_define
define|#
directive|define
name|CAUSE
value|0x08
end_define

begin_comment
comment|/* cause */
end_comment

begin_define
define|#
directive|define
name|ENDPT_REF
value|0x54
end_define

begin_comment
comment|/* endpoint reference */
end_comment

begin_define
define|#
directive|define
name|AAL_PARA
value|0x58
end_define

begin_comment
comment|/* ATM adaptation layer parameters */
end_comment

begin_define
define|#
directive|define
name|TRAFF_DESCRIP
value|0x59
end_define

begin_comment
comment|/* atm traffic descriptors */
end_comment

begin_define
define|#
directive|define
name|CONNECT_ID
value|0x5a
end_define

begin_comment
comment|/* connection identifier */
end_comment

begin_define
define|#
directive|define
name|QOS_PARA
value|0x5c
end_define

begin_comment
comment|/* quality of service parameters */
end_comment

begin_define
define|#
directive|define
name|B_HIGHER
value|0x5d
end_define

begin_comment
comment|/* broadband higher layer information */
end_comment

begin_define
define|#
directive|define
name|B_BEARER
value|0x5e
end_define

begin_comment
comment|/* broadband bearer capability */
end_comment

begin_define
define|#
directive|define
name|B_LOWER
value|0x5f
end_define

begin_comment
comment|/* broadband lower information */
end_comment

begin_define
define|#
directive|define
name|CALLING_PARTY
value|0x6c
end_define

begin_comment
comment|/* calling party number */
end_comment

begin_define
define|#
directive|define
name|CALLED_PARTY
value|0x70
end_define

begin_comment
comment|/* called party nmber */
end_comment

begin_define
define|#
directive|define
name|Q2931
value|0x09
end_define

begin_comment
comment|/* Q.2931 signalling general messages format */
end_comment

begin_define
define|#
directive|define
name|PROTO_POS
value|0
end_define

begin_comment
comment|/* offset of protocol discriminator */
end_comment

begin_define
define|#
directive|define
name|CALL_REF_POS
value|2
end_define

begin_comment
comment|/* offset of call reference value */
end_comment

begin_define
define|#
directive|define
name|MSG_TYPE_POS
value|5
end_define

begin_comment
comment|/* offset of message type */
end_comment

begin_define
define|#
directive|define
name|MSG_LEN_POS
value|7
end_define

begin_comment
comment|/* offset of mesage length */
end_comment

begin_define
define|#
directive|define
name|IE_BEGIN_POS
value|9
end_define

begin_comment
comment|/* offset of first information element */
end_comment

begin_comment
comment|/* format of signalling messages */
end_comment

begin_define
define|#
directive|define
name|TYPE_POS
value|0
end_define

begin_define
define|#
directive|define
name|LEN_POS
value|2
end_define

begin_define
define|#
directive|define
name|FIELD_BEGIN_POS
value|4
end_define

end_unit

