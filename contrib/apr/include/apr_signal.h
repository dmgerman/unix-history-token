begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|APR_SIGNAL_H
end_ifndef

begin_define
define|#
directive|define
name|APR_SIGNAL_H
end_define

begin_comment
comment|/**  * @file apr_signal.h  * @brief APR Signal Handling  */
end_comment

begin_include
include|#
directive|include
file|"apr.h"
end_include

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_if
if|#
directive|if
name|APR_HAVE_SIGNAL_H
end_if

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|/**  * @defgroup apr_signal Signal Handling  * @ingroup APR  * @{  */
if|#
directive|if
name|APR_HAVE_SIGACTION
operator|||
name|defined
argument_list|(
name|DOXYGEN
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|DARWIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_ANSI_SOURCE
argument_list|)
comment|/* work around Darwin header file bugs  *   http://www.opensource.apple.com/bugs/X/BSD%20Kernel/2657228.html  */
undef|#
directive|undef
name|SIG_DFL
undef|#
directive|undef
name|SIG_IGN
undef|#
directive|undef
name|SIG_ERR
define|#
directive|define
name|SIG_DFL
value|(void (*)(int))0
define|#
directive|define
name|SIG_IGN
value|(void (*)(int))1
define|#
directive|define
name|SIG_ERR
value|(void (*)(int))-1
endif|#
directive|endif
comment|/** Function prototype for signal handlers */
typedef|typedef
name|void
name|apr_sigfunc_t
parameter_list|(
name|int
parameter_list|)
function_decl|;
comment|/**  * Set the signal handler function for a given signal  * @param signo The signal (eg... SIGWINCH)  * @param func the function to get called  */
name|APR_DECLARE
argument_list|(
argument|apr_sigfunc_t *
argument_list|)
name|apr_signal
argument_list|(
argument|int signo
argument_list|,
argument|apr_sigfunc_t * func
argument_list|)
empty_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|SIG_IGN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SIG_ERR
argument_list|)
define|#
directive|define
name|SIG_ERR
value|((apr_sigfunc_t *) -1)
endif|#
directive|endif
else|#
directive|else
comment|/* !APR_HAVE_SIGACTION */
define|#
directive|define
name|apr_signal
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|signal(a, b)
endif|#
directive|endif
comment|/**  * Get the description for a specific signal number  * @param signum The signal number  * @return The description of the signal  */
name|APR_DECLARE
argument_list|(
argument|const char *
argument_list|)
name|apr_signal_description_get
argument_list|(
argument|int signum
argument_list|)
empty_stmt|;
comment|/**  * APR-private function for initializing the signal package  * @internal  * @param pglobal The internal, global pool  */
name|void
name|apr_signal_init
parameter_list|(
name|apr_pool_t
modifier|*
name|pglobal
parameter_list|)
function_decl|;
comment|/**  * Block the delivery of a particular signal  * @param signum The signal number  * @return status  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_signal_block
argument_list|(
argument|int signum
argument_list|)
empty_stmt|;
comment|/**  * Enable the delivery of a particular signal  * @param signum The signal number  * @return status  */
name|APR_DECLARE
argument_list|(
argument|apr_status_t
argument_list|)
name|apr_signal_unblock
argument_list|(
argument|int signum
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

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_SIGNAL_H */
end_comment

end_unit

