begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Atsushi Onoe  * Copyright (c) 2002-2005 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * GNU General Public License ("GPL") version 2 as published by the Free  * Software Foundation.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_H_
end_define

begin_comment
comment|/*  * 802.11 protocol definitions.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_VERSION_0
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_MGT
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_CTL
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_TYPE_DATA
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_MASK
value|0xf0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_SHIFT
value|4
end_define

begin_comment
comment|/* for TYPE_MGT */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ASSOC_REQ
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ASSOC_RESP
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_REASSOC_REQ
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_REASSOC_RESP
value|0x30
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PROBE_REQ
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PROBE_RESP
value|0x50
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_BEACON
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ATIM
value|0x90
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DISASSOC
value|0xa0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_AUTH
value|0xb0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DEAUTH
value|0xc0
end_define

begin_comment
comment|/* for TYPE_CTL */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_PS_POLL
value|0xa0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_RTS
value|0xb0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CTS
value|0xc0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_ACK
value|0xd0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_END
value|0xe0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_END_ACK
value|0xf0
end_define

begin_comment
comment|/* for TYPE_DATA (bit combination) */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_ACK
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_POLL
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_CF_ACPL
value|0x30
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_NODATA
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACK
value|0x50
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL
value|0x70
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_QOS
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC0_SUBTYPE_QOS_NULL
value|0xc0
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_NODS
value|0x00
end_define

begin_comment
comment|/* STA->STA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_TODS
value|0x01
end_define

begin_comment
comment|/* STA->AP  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_FROMDS
value|0x02
end_define

begin_comment
comment|/* AP ->STA */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_DIR_DSTODS
value|0x03
end_define

begin_comment
comment|/* AP ->AP  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_FC1_MORE_FRAG
value|0x04
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_RETRY
value|0x08
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_PWR_MGT
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_MORE_DATA
value|0x20
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_PROTECTED
value|0x40
end_define

begin_define
define|#
directive|define
name|IEEE80211_FC1_ORDER
value|0x80
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_FRAG_MASK
value|0x000f
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_FRAG_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_SEQ_MASK
value|0xfff0
end_define

begin_define
define|#
directive|define
name|IEEE80211_SEQ_SEQ_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_NWID_LEN
value|32
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_TXOP
value|0x00ff
end_define

begin_comment
comment|/* bit 8 is reserved */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY
value|0x60
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ACKPOLICY_S
value|5
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ESOP
value|0x10
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_ESOP_S
value|4
end_define

begin_define
define|#
directive|define
name|IEEE80211_QOS_TID
value|0x0f
end_define

begin_define
define|#
directive|define
name|IEEE80211_MGT_SUBTYPE_NAMES
value|{			\ 	"assoc-req",		"assoc-resp",		\ 	"reassoc-req",		"reassoc-resp",		\ 	"probe-req",		"probe-resp",		\ 	"reserved#6",		"reserved#7",		\ 	"beacon",		"atim",			\ 	"disassoc",		"auth",			\ 	"deauth",		"reserved#13",		\ 	"reserved#14",		"reserved#15"		\ }
end_define

begin_define
define|#
directive|define
name|IEEE80211_CTL_SUBTYPE_NAMES
value|{			\ 	"reserved#0",		"reserved#1",		\ 	"reserved#2",		"reserved#3",		\ 	"reserved#3",		"reserved#5",		\ 	"reserved#6",		"reserved#7",		\ 	"reserved#8",		"reserved#9",		\ 	"ps-poll",		"rts",			\ 	"cts",			"ack",			\ 	"cf-end",		"cf-end-ack"		\ }
end_define

begin_define
define|#
directive|define
name|IEEE80211_DATA_SUBTYPE_NAMES
value|{			\ 	"data",			"data-cf-ack",		\ 	"data-cf-poll",		"data-cf-ack-poll",	\ 	"null",			"cf-ack",		\ 	"cf-poll",		"cf-ack-poll",		\ 	"qos-data",		"qos-data-cf-ack",	\ 	"qos-data-cf-poll",	"qos-data-cf-ack-poll",	\ 	"qos",			"reserved#13",		\ 	"qos-cf-poll",		"qos-cf-ack-poll"	\ }
end_define

begin_define
define|#
directive|define
name|IEEE80211_TYPE_NAMES
value|{ "mgt", "ctl", "data", "reserved#4" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_H_ */
end_comment

end_unit

