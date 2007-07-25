begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2005, Gleb Smirnoff<glebius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|NG_NAT_NODE_TYPE
value|"nat"
end_define

begin_define
define|#
directive|define
name|NGM_NAT_COOKIE
value|1107718711
end_define

begin_define
define|#
directive|define
name|NG_NAT_HOOK_IN
value|"in"
end_define

begin_define
define|#
directive|define
name|NG_NAT_HOOK_OUT
value|"out"
end_define

begin_comment
comment|/* Arguments for NGM_NAT_SET_MODE message */
end_comment

begin_struct
struct|struct
name|ng_nat_mode
block|{
name|uint32_t
name|flags
decl_stmt|;
name|uint32_t
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_NAT_MODE_INFO
value|{				\ 	  { "flags",&ng_parse_uint32_type	},	\ 	  { "mask",&ng_parse_uint32_type	},	\ 	  { NULL }					\ }
end_define

begin_define
define|#
directive|define
name|NG_NAT_LOG
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_NAT_DENY_INCOMING
value|0x02
end_define

begin_define
define|#
directive|define
name|NG_NAT_SAME_PORTS
value|0x04
end_define

begin_define
define|#
directive|define
name|NG_NAT_UNREGISTERED_ONLY
value|0x10
end_define

begin_define
define|#
directive|define
name|NG_NAT_RESET_ON_ADDR_CHANGE
value|0x20
end_define

begin_define
define|#
directive|define
name|NG_NAT_PROXY_ONLY
value|0x40
end_define

begin_define
define|#
directive|define
name|NG_NAT_REVERSE
value|0x80
end_define

begin_enum
enum|enum
block|{
name|NGM_NAT_SET_IPADDR
init|=
literal|1
block|,
name|NGM_NAT_SET_MODE
block|,
name|NGM_NAT_SET_TARGET
block|, }
enum|;
end_enum

end_unit

