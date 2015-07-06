begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* dnstap support for Unbound */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013-2014, Farsight Security, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the copyright holder nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR  * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,  * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNBOUND_DNSTAP_H
end_ifndef

begin_define
define|#
directive|define
name|UNBOUND_DNSTAP_H
end_define

begin_include
include|#
directive|include
file|"dnstap/dnstap_config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_DNSTAP
end_ifdef

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fstrm_io
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fstrm_queue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|dt_env
block|{
comment|/** dnstap I/O thread */
name|struct
name|fstrm_iothr
modifier|*
name|iothr
decl_stmt|;
comment|/** dnstap I/O thread input queue */
name|struct
name|fstrm_iothr_queue
modifier|*
name|ioq
decl_stmt|;
comment|/** dnstap "identity" field, NULL if disabled */
name|char
modifier|*
name|identity
decl_stmt|;
comment|/** dnstap "version" field, NULL if disabled */
name|char
modifier|*
name|version
decl_stmt|;
comment|/** length of "identity" field */
name|unsigned
name|len_identity
decl_stmt|;
comment|/** length of "version" field */
name|unsigned
name|len_version
decl_stmt|;
comment|/** whether to log Message/RESOLVER_QUERY */
name|unsigned
name|log_resolver_query_messages
range|:
literal|1
decl_stmt|;
comment|/** whether to log Message/RESOLVER_RESPONSE */
name|unsigned
name|log_resolver_response_messages
range|:
literal|1
decl_stmt|;
comment|/** whether to log Message/CLIENT_QUERY */
name|unsigned
name|log_client_query_messages
range|:
literal|1
decl_stmt|;
comment|/** whether to log Message/CLIENT_RESPONSE */
name|unsigned
name|log_client_response_messages
range|:
literal|1
decl_stmt|;
comment|/** whether to log Message/FORWARDER_QUERY */
name|unsigned
name|log_forwarder_query_messages
range|:
literal|1
decl_stmt|;
comment|/** whether to log Message/FORWARDER_RESPONSE */
name|unsigned
name|log_forwarder_response_messages
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create dnstap environment object. Afterwards, call dt_apply_cfg() to fill in  * the config variables and dt_init() to fill in the per-worker state. Each  * worker needs a copy of this object but with its own I/O queue (the fq field  * of the structure) to ensure lock-free access to its own per-worker circular  * queue.  Duplicate the environment object if more than one worker needs to  * share access to the dnstap I/O socket.  * @param socket_path: path to dnstap logging socket, must be non-NULL.  * @param num_workers: number of worker threads, must be> 0.  * @return dt_env object, NULL on failure.  */
end_comment

begin_function_decl
name|struct
name|dt_env
modifier|*
name|dt_create
parameter_list|(
specifier|const
name|char
modifier|*
name|socket_path
parameter_list|,
name|unsigned
name|num_workers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Apply config settings.  * @param env: dnstap environment object.  * @param cfg: new config settings.  */
end_comment

begin_function_decl
name|void
name|dt_apply_cfg
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize per-worker state in dnstap environment object.  * @param env: dnstap environment object to initialize, created with dt_create().  * @return: true on success, false on failure.  */
end_comment

begin_function_decl
name|int
name|dt_init
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete dnstap environment object. Closes dnstap I/O socket and deletes all  * per-worker I/O queues.  */
end_comment

begin_function_decl
name|void
name|dt_delete
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and send a new dnstap "Message" event of type CLIENT_QUERY.  * @param env: dnstap environment object.  * @param qsock: address/port of client.  * @param cptype: comm_udp or comm_tcp.  * @param qmsg: query message.  */
end_comment

begin_function_decl
name|void
name|dt_msg_send_client_query
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|qsock
parameter_list|,
name|enum
name|comm_point_type
name|cptype
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|qmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and send a new dnstap "Message" event of type CLIENT_RESPONSE.  * @param env: dnstap environment object.  * @param qsock: address/port of client.  * @param cptype: comm_udp or comm_tcp.  * @param rmsg: response message.  */
end_comment

begin_function_decl
name|void
name|dt_msg_send_client_response
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|qsock
parameter_list|,
name|enum
name|comm_point_type
name|cptype
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|rmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and send a new dnstap "Message" event of type RESOLVER_QUERY or  * FORWARDER_QUERY. The type used is dependent on the value of the RD bit  * in the query header.  * @param env: dnstap environment object.  * @param rsock: address/port of server the query is being sent to.  * @param cptype: comm_udp or comm_tcp.  * @param zone: query zone.  * @param zone_len: length of zone.  * @param qmsg: query message.  */
end_comment

begin_function_decl
name|void
name|dt_msg_send_outside_query
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|rsock
parameter_list|,
name|enum
name|comm_point_type
name|cptype
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|size_t
name|zone_len
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|qmsg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create and send a new dnstap "Message" event of type RESOLVER_RESPONSE or  * FORWARDER_RESPONSE. The type used is dependent on the value of the RD bit  * in the query header.  * @param env: dnstap environment object.  * @param rsock: address/port of server the response was received from.  * @param cptype: comm_udp or comm_tcp.  * @param zone: query zone.  * @param zone_len: length of zone.  * @param qbuf: outside_network's qbuf key.  * @param qbuf_len: length of outside_network's qbuf key.  * @param qtime: time query message was sent.  * @param rtime: time response message was sent.  * @param rmsg: response message.  */
end_comment

begin_function_decl
name|void
name|dt_msg_send_outside_response
parameter_list|(
name|struct
name|dt_env
modifier|*
name|env
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|rsock
parameter_list|,
name|enum
name|comm_point_type
name|cptype
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|,
name|size_t
name|zone_len
parameter_list|,
name|uint8_t
modifier|*
name|qbuf
parameter_list|,
name|size_t
name|qbuf_len
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|qtime
parameter_list|,
specifier|const
name|struct
name|timeval
modifier|*
name|rtime
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|rmsg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_DNSTAP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UNBOUND_DNSTAP_H */
end_comment

end_unit

