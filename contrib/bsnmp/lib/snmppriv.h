begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/lib/snmppriv.h,v 1.9 2004/08/06 08:46:58 brandt Exp $  *  * Private functions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|enum
name|asn_err
name|snmp_binding_encode
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_code
name|snmp_pdu_encode_header
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_code
name|snmp_fix_encoding
parameter_list|(
name|struct
name|asn_buf
modifier|*
parameter_list|,
specifier|const
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|snmp_parse_message_hdr
parameter_list|(
name|struct
name|asn_buf
modifier|*
name|b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|asn_len_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|asn_err
name|snmp_parse_pdus_hdr
parameter_list|(
name|struct
name|asn_buf
modifier|*
name|b
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
name|pdu
parameter_list|,
name|asn_len_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DEFAULT_HOST
value|"localhost"
end_define

begin_define
define|#
directive|define
name|DEFAULT_PORT
value|"snmp"
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOCAL
value|"/var/run/snmp.sock"
end_define

end_unit

