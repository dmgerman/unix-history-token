begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/dhcp6opt.h,v 1.3 2000/12/17 23:07:49 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (C) 1998 and 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * draft-ietf-dhc-v6exts-11  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DHCP6OPT_H_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|__DHCP6OPT_H_DEFINED
end_define

begin_define
define|#
directive|define
name|OL6_N
value|-1
end_define

begin_define
define|#
directive|define
name|OL6_16N
value|-2
end_define

begin_define
define|#
directive|define
name|OL6_Z
value|-3
end_define

begin_define
define|#
directive|define
name|OT6_NONE
value|0
end_define

begin_define
define|#
directive|define
name|OT6_V6
value|1
end_define

begin_define
define|#
directive|define
name|OT6_STR
value|2
end_define

begin_define
define|#
directive|define
name|OT6_NUM
value|3
end_define

begin_struct
struct|struct
name|dhcp6_opt
block|{
name|u_int
name|code
decl_stmt|;
name|int
name|len
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* index to parameters */
end_comment

begin_define
define|#
directive|define
name|DH6T_CLIENT_ADV_WAIT
value|1
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_DEFAULT_SOLICIT_HOPCOUNT
value|2
end_define

begin_comment
comment|/* times */
end_comment

begin_define
define|#
directive|define
name|DH6T_SERVER_MIN_ADV_DELAY
value|3
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_SERVER_MAX_ADV_DELAY
value|4
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_REQUEST_MSG_MIN_RETRANS
value|5
end_define

begin_comment
comment|/* retransmissions */
end_comment

begin_define
define|#
directive|define
name|DH6T_REPLY_MSG_TIMEOUT
value|6
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_REPLY_MSG_RETRANS_INTERVAL
value|7
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MSG_TIMEOUT
value|8
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MSG_MIN_RETRANS
value|9
end_define

begin_comment
comment|/* retransmissions */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MSG_RETRANS_INTERVAL
value|10
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MMSG_MIN_RESP
value|11
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MMSG_MAX_RESP
value|12
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_MIN_SOLICIT_DELAY
value|13
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_MAX_SOLICIT_DELAY
value|14
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_XID_TIMEOUT
value|15
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_define
define|#
directive|define
name|DH6T_RECONF_MULTICAST_REQUEST_WAIT
value|16
end_define

begin_comment
comment|/* milliseconds */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern struct dhcp6_opt *dh6o_pad; extern struct dhcp6_opt *dh6o_end; extern int dhcp6_param[]; extern void dhcp6opttab_init (void); extern struct dhcp6_opt *dhcp6opttab_byname (char *); extern struct dhcp6_opt *dhcp6opttab_bycode (u_int);
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__DHCP6OPT_H_DEFINED*/
end_comment

end_unit

