begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- mode: c; tab-width: 3; c-basic-offset: 3; -*- */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Charles Mott<cmott@scientech.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Alias_local.h contains the function prototypes for alias.c,  * alias_db.c, alias_util.c and alias_ftp.c, alias_irc.c (as well  * as any future add-ons).  It also includes macros, globals and  * struct definitions shared by more than one alias*.c file.  *  * This include file is intended to be used only within the aliasing  * software.  Outside world interfaces are defined in alias.h  *  * This software is placed into the public domain with no restrictions  * on its distribution.  *  * Initial version:  August, 1996  (cjm)      *  *<updated several times by original author and Eivind Eklund>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_LOCAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_LOCAL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Macros */
end_comment

begin_comment
comment|/*  * The following macro is used to update an  * internet checksum.  "delta" is a 32-bit  * accumulation of all the changes to the  * checksum (adding in new 16-bit words and  * subtracting out old words), and "cksum"  * is the checksum value to be updated.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_CHECKSUM
parameter_list|(
name|acc
parameter_list|,
name|cksum
parameter_list|)
define|\
value|do { \ 		acc += cksum; \ 		if (acc< 0) { \ 			acc = -acc; \ 			acc = (acc>> 16) + (acc& 0xffff); \ 			acc += acc>> 16; \ 			cksum = (u_short) ~acc; \ 		} else { \ 			acc = (acc>> 16) + (acc& 0xffff); \ 			acc += acc>> 16; \ 			cksum = (u_short) acc; \ 		} \ 	} while (0)
end_define

begin_comment
comment|/* Globals */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|packetAliasMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structs */
end_comment

begin_struct_decl
struct_decl|struct
name|alias_link
struct_decl|;
end_struct_decl

begin_comment
comment|/* Incomplete structure */
end_comment

begin_comment
comment|/* Prototypes */
end_comment

begin_comment
comment|/* General utilities */
end_comment

begin_function_decl
name|u_short
name|IpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|TcpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DifferentialChecksum
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Internal data access */
end_comment

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpIn
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpOut
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn1
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn2
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|AddFragmentPtrLink
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentPtr
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindProtoIn
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindProtoOut
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindUdpTcpIn
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindUdpTcpOut
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_char
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|AddPptp
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpOutByCallId
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpInByCallId
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpOutByPeerCallId
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindPptpInByPeerCallId
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindRtspOut
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|FindOriginalAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|FindAliasAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* External data access/modification */
end_comment

begin_function_decl
name|int
name|FindNewPortGroup
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_short
parameter_list|,
name|u_char
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetOriginalAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDestAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetAliasAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDefaultAliasAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDefaultAliasAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetOriginalPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetAliasPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetProxyAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetProxyAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetProxyPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetProxyPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaAckIn
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaSeqOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddSeq
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetExpire
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ClearCheckNewLink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetLastLineCrlfTermed
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetLastLineCrlfTermed
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDestCallId
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FW_PUNCH
end_ifndef

begin_function_decl
name|void
name|PunchFWHole
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Housekeeping function */
end_comment

begin_function_decl
name|void
name|HouseKeeping
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tcp specfic routines */
end_comment

begin_comment
comment|/*lint -save -library Suppress flexelint warnings */
end_comment

begin_comment
comment|/* FTP routines */
end_comment

begin_function_decl
name|void
name|AliasHandleFtpOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* IRC routines */
end_comment

begin_function_decl
name|void
name|AliasHandleIrcOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* RTSP routines */
end_comment

begin_function_decl
name|void
name|AliasHandleRtspOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PPTP routines */
end_comment

begin_function_decl
name|void
name|AliasHandlePptpOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AliasHandlePptpIn
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AliasHandlePptpGreOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AliasHandlePptpGreIn
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NetBIOS routines */
end_comment

begin_function_decl
name|int
name|AliasHandleUdpNbt
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|AliasHandleUdpNbtNS
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CUSeeMe routines */
end_comment

begin_function_decl
name|void
name|AliasHandleCUSeeMeOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AliasHandleCUSeeMeIn
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transparent proxy routines */
end_comment

begin_function_decl
name|int
name|ProxyCheck
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ProxyModify
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|alias_tcp_state
block|{
name|ALIAS_TCP_STATE_NOT_CONNECTED
block|,
name|ALIAS_TCP_STATE_CONNECTED
block|,
name|ALIAS_TCP_STATE_DISCONNECTED
block|}
enum|;
end_enum

begin_comment
comment|/*lint -restore */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ALIAS_LOCAL_H_ */
end_comment

end_unit

