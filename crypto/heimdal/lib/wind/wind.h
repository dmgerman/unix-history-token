begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WIND_H_
end_ifndef

begin_define
define|#
directive|define
name|_WIND_H_
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_include
include|#
directive|include
file|<wind_err.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|wind_profile_flags
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WIND_PROFILE_NAME
value|0x00000001
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_SASL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP_CASE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP_CASE_EXACT_ATTRIBUTE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP_CASE_EXACT_ASSERTION
value|0x00020000
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP_NUMERIC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|WIND_PROFILE_LDAP_TELEPHONE
value|0x00080000
end_define

begin_comment
comment|/* flags to wind_ucs2read/wind_ucs2write */
end_comment

begin_define
define|#
directive|define
name|WIND_RW_LE
value|1
end_define

begin_define
define|#
directive|define
name|WIND_RW_BE
value|2
end_define

begin_define
define|#
directive|define
name|WIND_RW_BOM
value|4
end_define

begin_function_decl
name|int
name|wind_stringprep
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|wind_profile_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_profile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|wind_profile_flags
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_punycode_label_toascii
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_utf8ucs4
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_utf8ucs4_length
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs4utf8
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs4utf8_length
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_utf8ucs2
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_utf8ucs2_length
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs2utf8
parameter_list|(
specifier|const
name|uint16_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs2utf8_length
parameter_list|(
specifier|const
name|uint16_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs2read
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wind_ucs2write
parameter_list|(
specifier|const
name|uint16_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIND_H_ */
end_comment

end_unit

