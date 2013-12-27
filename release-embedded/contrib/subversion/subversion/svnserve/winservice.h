begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * winservice.h : Public definitions for Windows Service support  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINSERVICE_H
end_ifndef

begin_define
define|#
directive|define
name|WINSERVICE_H
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
ifdef|#
directive|ifdef
name|WIN32
comment|/* Connects to the Windows Service Control Manager and allows this    process to run as a service.  This function can only succeed if the    process was started by the SCM, not directly by a user.  After this    call succeeds, the service should perform whatever work it needs to    start the service, and then the service should call    winservice_running() (if no errors occurred) or winservice_stop()    (if something failed during startup). */
name|svn_error_t
modifier|*
name|winservice_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Notifies the SCM that the service is now running.  The caller must    already have called winservice_start successfully. */
name|void
name|winservice_running
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* This function is called by the SCM in an arbitrary thread when the    SCM wants the service to stop.  The implementation of this function    can return immediately; all that is necessary is that the service    eventually stop in response. */
name|void
name|winservice_notify_stop
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Evaluates to TRUE if the SCM has requested that the service stop.    This allows for the service to poll, in addition to being notified    in the winservice_notify_stop callback. */
name|svn_boolean_t
name|winservice_is_stopping
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* WIN32 */
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
comment|/* WINSERVICE_H */
end_comment

end_unit

