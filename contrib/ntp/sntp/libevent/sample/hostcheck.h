begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_CURL_HOSTCHECK_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_CURL_HOSTCHECK_H
end_define

begin_comment
comment|/***************************************************************************  *                                  _   _ ____  _  *  Project                     ___| | | |  _ \| |  *                             / __| | | | |_) | |  *                            | (__| |_| |  _<| |___  *                             \___|\___/|_| \_\_____|  *  * Copyright (C) 1998 - 2012, Daniel Stenberg,<daniel@haxx.se>, et al.  *  * This software is licensed as described in the file COPYING, which  * you should have received as part of this distribution. The terms  * are also available at http://curl.haxx.se/docs/copyright.html.  *  * You may opt to use, copy, modify, merge, publish, distribute and/or sell  * copies of the Software, and permit persons to whom the Software is  * furnished to do so, under the terms of the COPYING file.  *  * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY  * KIND, either express or implied.  *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CURL_HOST_NOMATCH
value|0
end_define

begin_define
define|#
directive|define
name|CURL_HOST_MATCH
value|1
end_define

begin_function_decl
name|int
name|Curl_cert_hostcheck
parameter_list|(
specifier|const
name|char
modifier|*
name|match_pattern
parameter_list|,
specifier|const
name|char
modifier|*
name|hostname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEADER_CURL_HOSTCHECK_H */
end_comment

end_unit

