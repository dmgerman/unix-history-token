begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * logger.h : Public definitions for the Repository Cache  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOGGER_H
end_ifndef

begin_define
define|#
directive|define
name|LOGGER_H
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
include|#
directive|include
file|"server.h"
comment|/* Opaque svnserve log file writer data structure.  Access to the log  * file will be serialized among threads within the same process.  */
typedef|typedef
name|struct
name|logger_t
name|logger_t
typedef|;
comment|/* In POOL, create a writer object that will write log messages to stderr  * and return it in *LOGGER.  The log file will not add any buffering  * on top of stderr.  */
name|svn_error_t
modifier|*
name|logger__create_for_stderr
parameter_list|(
name|logger_t
modifier|*
modifier|*
name|logger
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* In POOL, create a writer object for log file FILENAME and return it  * in *LOGGER.  The log file will be flushed& closed when POOL gets  * cleared or destroyed.  */
name|svn_error_t
modifier|*
name|logger__create
parameter_list|(
name|logger_t
modifier|*
modifier|*
name|logger
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|apr_pool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
comment|/* Write the first LEN bytes from ERRSTR to the log file managed by LOGGER.  */
name|svn_error_t
modifier|*
name|logger__write
parameter_list|(
name|logger_t
modifier|*
name|logger
parameter_list|,
specifier|const
name|char
modifier|*
name|errstr
parameter_list|,
name|apr_size_t
name|len
parameter_list|)
function_decl|;
comment|/* Write a description of ERR with additional information from REPOSITORY  * and CLIENT_INFO to the log file managed by LOGGER.  REPOSITORY as well  * as CLIENT_INFO may be NULL.  If either ERR or LOGGER are NULL, this  * becomes a no-op.  */
name|void
name|logger__log_error
parameter_list|(
name|logger_t
modifier|*
name|logger
parameter_list|,
name|svn_error_t
modifier|*
name|err
parameter_list|,
name|repository_t
modifier|*
name|repository
parameter_list|,
name|client_info_t
modifier|*
name|client_info
parameter_list|)
function_decl|;
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
comment|/* LOGGER_H */
end_comment

end_unit

