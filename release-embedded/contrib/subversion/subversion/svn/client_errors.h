begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * client_errors.h:  error codes this command line client features  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_comment
comment|/* ==================================================================== */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SVN_CLIENT_ERRORS_H
end_ifndef

begin_define
define|#
directive|define
name|SVN_CLIENT_ERRORS_H
end_define

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
comment|/* __cplusplus */
comment|/*  * This error defining system is copied from and explained in  * ../../include/svn_error_codes.h  */
comment|/* Process this file if we're building an error array, or if we have    not defined the enumerated constants yet.  */
if|#
directive|if
name|defined
argument_list|(
name|SVN_ERROR_BUILD_ARRAY
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|SVN_CMDLINE_ERROR_ENUM_DEFINED
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|SVN_ERROR_BUILD_ARRAY
argument_list|)
error|#
directive|error
literal|"Need to update err_defn for r1464679 and un-typo 'CDMLINE'"
define|#
directive|define
name|SVN_ERROR_START
define|\
value|static const err_defn error_table[] = { \           { SVN_ERR_CDMLINE__WARNING, "Warning" },
define|#
directive|define
name|SVN_ERRDEF
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|{ n, s },
define|#
directive|define
name|SVN_ERROR_END
value|{ 0, NULL } };
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SVN_CMDLINE_ERROR_ENUM_DEFINED
argument_list|)
define|#
directive|define
name|SVN_ERROR_START
define|\
value|typedef enum svn_client_errno_t { \           SVN_ERR_CDMLINE__WARNING = SVN_ERR_LAST + 1,
define|#
directive|define
name|SVN_ERRDEF
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|n,
define|#
directive|define
name|SVN_ERROR_END
value|SVN_ERR_CMDLINE__ERR_LAST } svn_client_errno_t;
define|#
directive|define
name|SVN_CMDLINE_ERROR_ENUM_DEFINED
endif|#
directive|endif
comment|/* Define custom command line client error numbers */
name|SVN_ERROR_START
comment|/* BEGIN Client errors */
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CMDLINE__TMPFILE_WRITE
argument_list|,
literal|"Failed writing to temporary file."
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CMDLINE__TMPFILE_STAT
argument_list|,
literal|"Failed getting info about temporary file."
argument_list|)
name|SVN_ERRDEF
argument_list|(
name|SVN_ERR_CMDLINE__TMPFILE_OPEN
argument_list|,
literal|"Failed opening temporary file."
argument_list|)
comment|/* END Client errors */
name|SVN_ERROR_END
undef|#
directive|undef
name|SVN_ERROR_START
undef|#
directive|undef
name|SVN_ERRDEF
undef|#
directive|undef
name|SVN_ERROR_END
endif|#
directive|endif
comment|/* SVN_ERROR_BUILD_ARRAY || !SVN_CMDLINE_ERROR_ENUM_DEFINED */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVN_CLIENT_ERRORS_H */
end_comment

end_unit

