begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bnep.h,v 1.1 2008/08/17 13:20:57 plunky Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2008 Iain Hibbert  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Constants defined in the Bluetooth Network Encapsulation  * Protocol (BNEP) specification v1.0  */
end_comment

begin_define
define|#
directive|define
name|BNEP_MTU_MIN
value|1691
end_define

begin_define
define|#
directive|define
name|BNEP_EXT
value|0x80
end_define

begin_define
define|#
directive|define
name|BNEP_TYPE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7f)
end_define

begin_define
define|#
directive|define
name|BNEP_TYPE_EXT
parameter_list|(
name|x
parameter_list|)
value|(((x)& BNEP_EXT) == BNEP_EXT)
end_define

begin_comment
comment|/* BNEP packet types */
end_comment

begin_define
define|#
directive|define
name|BNEP_GENERAL_ETHERNET
value|0x00
end_define

begin_define
define|#
directive|define
name|BNEP_CONTROL
value|0x01
end_define

begin_define
define|#
directive|define
name|BNEP_COMPRESSED_ETHERNET
value|0x02
end_define

begin_define
define|#
directive|define
name|BNEP_COMPRESSED_ETHERNET_SRC_ONLY
value|0x03
end_define

begin_define
define|#
directive|define
name|BNEP_COMPRESSED_ETHERNET_DST_ONLY
value|0x04
end_define

begin_comment
comment|/* BNEP extension header types */
end_comment

begin_define
define|#
directive|define
name|BNEP_EXTENSION_CONTROL
value|0x00
end_define

begin_comment
comment|/* BNEP control types */
end_comment

begin_define
define|#
directive|define
name|BNEP_CONTROL_COMMAND_NOT_UNDERSTOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_CONNECTION_REQUEST
value|0x01
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_CONNECTION_RESPONSE
value|0x02
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_NET_TYPE_SET
value|0x03
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_NET_TYPE_RESPONSE
value|0x04
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_MULTI_ADDR_SET
value|0x05
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_MULTI_ADDR_RESPONSE
value|0x06
end_define

begin_comment
comment|/* BNEP setup response codes */
end_comment

begin_define
define|#
directive|define
name|BNEP_SETUP_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_INVALID_SRC_UUID
value|0x0001
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_INVALID_DST_UUID
value|0x0002
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_INVALID_UUID_SIZE
value|0x0003
end_define

begin_define
define|#
directive|define
name|BNEP_SETUP_NOT_ALLOWED
value|0x0004
end_define

begin_comment
comment|/* BNEP filter return codes */
end_comment

begin_define
define|#
directive|define
name|BNEP_FILTER_SUCCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_UNSUPPORTED_REQUEST
value|0x0001
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_INVALID_RANGE
value|0x0002
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_TOO_MANY_FILTERS
value|0x0003
end_define

begin_define
define|#
directive|define
name|BNEP_FILTER_SECURITY_FAILURE
value|0x0004
end_define

end_unit

