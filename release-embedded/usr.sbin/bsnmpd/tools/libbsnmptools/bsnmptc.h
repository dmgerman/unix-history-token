begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 The FreeBSD Project  * All rights reserved.  *  * Author: Shteryana Shopova<syrinx@FreeBSD.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Textual conventions for snmp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSNMP_TEXT_CONV_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSNMP_TEXT_CONV_H_
end_define

begin_comment
comment|/* Variable display length string. */
end_comment

begin_define
define|#
directive|define
name|SNMP_VAR_STRSZ
value|-1
end_define

begin_comment
comment|/*  * 11 bytes - octets that represent DateAndTime Textual convention  * and the size of string used to diplay that.  */
end_comment

begin_define
define|#
directive|define
name|SNMP_DATETIME_OCTETS
value|11
end_define

begin_define
define|#
directive|define
name|SNMP_DATETIME_STRSZ
value|32
end_define

begin_comment
comment|/*  * 6 bytes - octets that represent PhysAddress Textual convention  * and the size of string used to diplay that.  */
end_comment

begin_define
define|#
directive|define
name|SNMP_PHYSADDR_OCTETS
value|6
end_define

begin_define
define|#
directive|define
name|SNMP_PHYSADDR_STRSZ
value|19
end_define

begin_comment
comment|/* NTPTimeStamp. */
end_comment

begin_define
define|#
directive|define
name|SNMP_NTP_TS_OCTETS
value|8
end_define

begin_define
define|#
directive|define
name|SNMP_NTP_TS_STRSZ
value|10
end_define

begin_comment
comment|/* BridgeId. */
end_comment

begin_define
define|#
directive|define
name|SNMP_BRIDGEID_OCTETS
value|8
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGEID_STRSZ
value|25
end_define

begin_define
define|#
directive|define
name|SNMP_MAX_BRIDGE_PRIORITY
value|65535
end_define

begin_comment
comment|/* BridgePortId. */
end_comment

begin_define
define|#
directive|define
name|SNMP_BPORT_OCTETS
value|2
end_define

begin_define
define|#
directive|define
name|SNMP_BPORT_STRSZ
value|7
end_define

begin_define
define|#
directive|define
name|SNMP_MAX_BPORT_PRIORITY
value|255
end_define

begin_comment
comment|/* InetAddress. */
end_comment

begin_define
define|#
directive|define
name|SNMP_INADDRS_STRSZ
value|INET6_ADDRSTRLEN
end_define

begin_enum
enum|enum
name|snmp_tc
block|{
name|SNMP_STRING
init|=
literal|0
block|,
name|SNMP_DISPLAYSTRING
init|=
literal|1
block|,
name|SNMP_DATEANDTIME
init|=
literal|2
block|,
name|SNMP_PHYSADDR
init|=
literal|3
block|,
name|SNMP_ATMESI
init|=
literal|4
block|,
name|SNMP_NTP_TIMESTAMP
init|=
literal|5
block|,
name|SNMP_MACADDRESS
init|=
literal|6
block|,
name|SNMP_BRIDGE_ID
init|=
literal|7
block|,
name|SNMP_BPORT_ID
init|=
literal|8
block|,
name|SNMP_INETADDRESS
init|=
literal|9
block|,
name|SNMP_TC_OWN
init|=
literal|10
block|,
name|SNMP_UNKNOWN
block|,
comment|/* keep last */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|snmp_oct2tc_f
function_decl|)
parameter_list|(
name|uint32_t
name|len
parameter_list|,
name|char
modifier|*
name|octs
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
modifier|*
name|snmp_tc2oid_f
function_decl|)
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|asn_oid
modifier|*
name|oid
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|snmp_tc2oct_f
function_decl|)
parameter_list|(
name|struct
name|snmp_value
modifier|*
name|value
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|enum
name|snmp_tc
name|snmp_get_tc
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|snmp_oct2tc
parameter_list|(
name|enum
name|snmp_tc
name|tc
parameter_list|,
name|uint32_t
name|len
parameter_list|,
name|char
modifier|*
name|octets
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|snmp_tc2oid
parameter_list|(
name|enum
name|snmp_tc
name|tc
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|struct
name|asn_oid
modifier|*
name|oid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_tc2oct
parameter_list|(
name|enum
name|snmp_tc
name|tc
parameter_list|,
name|struct
name|snmp_value
modifier|*
name|value
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSNMP_TEXT_CONV_H_ */
end_comment

end_unit

