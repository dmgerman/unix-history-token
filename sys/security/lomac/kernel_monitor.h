begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LOMAC_MONITOR_H_
end_ifndef

begin_define
define|#
directive|define
name|_LOMAC_MONITOR_H_
end_define

begin_function_decl
name|int
name|monitor_read_object
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|,
name|lomac_object_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|monitor_pipe_write
parameter_list|(
name|lomac_subject_t
modifier|*
parameter_list|,
name|lomac_object_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|monitor_read_net_socket
parameter_list|(
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void monitor_open( lomac_subject_t *p_subject, lomac_object_t *p_object ); void monitor_pipe_create( lomac_subject_t *p_subject, 			  lomac_object_t *p_pipe ); void monitor_unix_socket_bind( lomac_subject_t *p_subject,                                lomac_object_t *p_socket,  			       lomac_object_t *p_name ); void monitor_unix_socket_abstract( lomac_subject_t *p_subject, 				   lomac_object_t *p_socket );  void monitor_unix_socketpair( lomac_subject_t *p_subject, 			      lomac_object_t *p_socket1, 			      lomac_object_t *p_socket2 );  void monitor_unix_socket_accept_connect( lomac_subject_t *p_subject, 					 lomac_object_t *p_old_socket, 					 lomac_object_t *p_new_socket );
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

