begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: ipsec_strerror.h,v 1.8 2000/07/30 00:45:12 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, 1998, and 1999 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__ipsec_errcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|__ipsec_set_strerror
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EIPSEC_NO_ERROR
value|0
end_define

begin_comment
comment|/*success*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_NOT_SUPPORTED
value|1
end_define

begin_comment
comment|/*not supported*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_ARGUMENT
value|2
end_define

begin_comment
comment|/*invalid argument*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_SADBMSG
value|3
end_define

begin_comment
comment|/*invalid sadb message*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_VERSION
value|4
end_define

begin_comment
comment|/*invalid version*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_POLICY
value|5
end_define

begin_comment
comment|/*invalid security policy*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_ADDRESS
value|6
end_define

begin_comment
comment|/*invalid address specification*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_PROTO
value|7
end_define

begin_comment
comment|/*invalid ipsec protocol*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_MODE
value|8
end_define

begin_comment
comment|/*Invalid ipsec mode*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_LEVEL
value|9
end_define

begin_comment
comment|/*invalid ipsec level*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_SATYPE
value|10
end_define

begin_comment
comment|/*invalid SA type*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_MSGTYPE
value|11
end_define

begin_comment
comment|/*invalid message type*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_EXTTYPE
value|12
end_define

begin_comment
comment|/*invalid extension type*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_ALGS
value|13
end_define

begin_comment
comment|/*Invalid algorithm type*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_KEYLEN
value|14
end_define

begin_comment
comment|/*invalid key length*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_FAMILY
value|15
end_define

begin_comment
comment|/*invalid address family*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_PREFIXLEN
value|16
end_define

begin_comment
comment|/*SPI range violation*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_DIR
value|17
end_define

begin_comment
comment|/*Invalid direciton*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_INVAL_SPI
value|18
end_define

begin_comment
comment|/*invalid prefixlen*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_NO_PROTO
value|19
end_define

begin_comment
comment|/*no protocol specified*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_NO_ALGS
value|20
end_define

begin_comment
comment|/*No algorithm specified*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_NO_BUFS
value|21
end_define

begin_comment
comment|/*no buffers available*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_DO_GET_SUPP_LIST
value|22
end_define

begin_comment
comment|/*must get supported algorithm first*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_PROTO_MISMATCH
value|23
end_define

begin_comment
comment|/*protocol mismatch*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_FAMILY_MISMATCH
value|24
end_define

begin_comment
comment|/*family mismatch*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_FEW_ARGUMENTS
value|25
end_define

begin_comment
comment|/*Too few arguments*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_SYSTEM_ERROR
value|26
end_define

begin_comment
comment|/*system error*/
end_comment

begin_define
define|#
directive|define
name|EIPSEC_MAX
value|27
end_define

begin_comment
comment|/*unknown error*/
end_comment

end_unit

