begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  * The apr_vsnprintf/apr_snprintf functions are based on, and used with the  * permission of, the  SIO stdio-replacement strx_* functions by Panos  * Tsirigotis<panos@alumni.cs.colorado.edu> for xinetd.  */
end_comment

begin_comment
comment|/**  * @file apr_base64.h  * @brief APR-UTIL Base64 Encoding  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_BASE64_H
end_ifndef

begin_define
define|#
directive|define
name|APR_BASE64_H
end_define

begin_include
include|#
directive|include
file|"apu.h"
end_include

begin_include
include|#
directive|include
file|"apr_general.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/**  * @defgroup APR_Util_Base64 Base64 Encoding  * @ingroup APR_Util  * @{  */
comment|/* Simple BASE64 encode/decode functions.  *   * As we might encode binary strings, hence we require the length of  * the incoming plain source. And return the length of what we decoded.  *  * The decoding function takes any non valid char (i.e. whitespace, \0  * or anything non A-Z,0-9 etc as terminal.  *   * plain strings/binary sequences are not assumed '\0' terminated. Encoded  * strings are neither. But probably should.  *  */
comment|/**  * Given the length of an un-encoded string, get the length of the  * encoded string.  * @param len the length of an unencoded string.  * @return the length of the string after it is encoded, including the  * trailing \0  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_encode_len
argument_list|(
argument|int len
argument_list|)
empty_stmt|;
comment|/**  * Encode a text string using base64encoding.  * @param coded_dst The destination string for the encoded string.  * @param plain_src The original string in plain text  * @param len_plain_src The length of the plain text string  * @return the length of the encoded string  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_encode
argument_list|(
argument|char * coded_dst
argument_list|,
argument|const char *plain_src
argument_list|,
argument|int len_plain_src
argument_list|)
empty_stmt|;
comment|/**  * Encode an EBCDIC string using base64encoding.  * @param coded_dst The destination string for the encoded string.  * @param plain_src The original string in plain text  * @param len_plain_src The length of the plain text string  * @return the length of the encoded string  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_encode_binary
argument_list|(
argument|char * coded_dst
argument_list|,
argument|const unsigned char *plain_src
argument_list|,
argument|int len_plain_src
argument_list|)
empty_stmt|;
comment|/**  * Determine the maximum buffer length required to decode the plain text  * string given the encoded string.  * @param coded_src The encoded string  * @return the maximum required buffer length for the plain text string  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_decode_len
argument_list|(
specifier|const
name|char
operator|*
name|coded_src
argument_list|)
expr_stmt|;
comment|/**  * Decode a string to plain text  * @param plain_dst The destination string for the plain text  * @param coded_src The encoded string   * @return the length of the plain text string  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_decode
argument_list|(
name|char
operator|*
name|plain_dst
argument_list|,
specifier|const
name|char
operator|*
name|coded_src
argument_list|)
expr_stmt|;
comment|/**  * Decode an EBCDIC string to plain text  * @param plain_dst The destination string for the plain text  * @param coded_src The encoded string   * @return the length of the plain text string  */
name|APU_DECLARE
argument_list|(
argument|int
argument_list|)
name|apr_base64_decode_binary
argument_list|(
argument|unsigned char * plain_dst
argument_list|,
argument|const char *coded_src
argument_list|)
empty_stmt|;
comment|/** @} */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !APR_BASE64_H */
end_comment

end_unit

