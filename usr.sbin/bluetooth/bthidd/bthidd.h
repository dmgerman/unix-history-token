begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bthidd.h  *  * Copyright (c) 2004 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: bthidd.h,v 1.6 2004/11/17 21:59:42 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BTHIDD_H_
end_ifndef

begin_define
define|#
directive|define
name|_BTHIDD_H_
value|1
end_define

begin_define
define|#
directive|define
name|BTHIDD_IDENT
value|"bthidd"
end_define

begin_define
define|#
directive|define
name|BTHIDD_PIDFILE
value|"/var/run/" BTHIDD_IDENT ".pid"
end_define

begin_struct_decl
struct_decl|struct
name|bthid_session
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|bthid_server
block|{
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* local bdaddr */
name|int
name|cons
decl_stmt|;
comment|/* /dev/consolectl */
name|int
name|vkbd
decl_stmt|;
comment|/* /dev/vkbdctl */
name|char
specifier|const
modifier|*
name|script
decl_stmt|;
comment|/* keyboard switching script */
name|int
name|windex
decl_stmt|;
comment|/* wired keyboard index */
name|bitstr_t
modifier|*
name|keys
decl_stmt|;
comment|/* pressed keys map */
name|int
name|ctrl
decl_stmt|;
comment|/* control channel (listen) */
name|int
name|intr
decl_stmt|;
comment|/* intr. channel (listen) */
name|int
name|maxfd
decl_stmt|;
comment|/* max fd in sets */
name|fd_set
name|rfdset
decl_stmt|;
comment|/* read descriptor set */
name|fd_set
name|wfdset
decl_stmt|;
comment|/* write descriptor set */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|bthid_session
argument_list|)
name|sessions
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bthid_server
name|bthid_server_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bthid_server
modifier|*
name|bthid_server_p
typedef|;
end_typedef

begin_struct
struct|struct
name|bthid_session
block|{
name|bthid_server_p
name|srv
decl_stmt|;
comment|/* pointer back to server */
name|int
name|ctrl
decl_stmt|;
comment|/* control channel */
name|int
name|intr
decl_stmt|;
comment|/* interrupt channel */
name|bdaddr_t
name|bdaddr
decl_stmt|;
comment|/* remote bdaddr */
name|short
name|state
decl_stmt|;
comment|/* session state */
define|#
directive|define
name|CLOSED
value|0
define|#
directive|define
name|W4CTRL
value|1
define|#
directive|define
name|W4INTR
value|2
define|#
directive|define
name|OPEN
value|3
name|bitstr_t
modifier|*
name|keys
decl_stmt|;
comment|/* pressed keys map */
name|LIST_ENTRY
argument_list|(
argument|bthid_session
argument_list|)
name|next
expr_stmt|;
comment|/* link to next */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bthid_session
name|bthid_session_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bthid_session
modifier|*
name|bthid_session_p
typedef|;
end_typedef

begin_function_decl
name|int
name|server_init
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|server_shutdown
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|server_do
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|client_rescan
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|client_connect
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bthid_session_p
name|session_open
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|,
name|bdaddr_p
name|bdaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bthid_session_p
name|session_by_bdaddr
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|,
name|bdaddr_p
name|bdaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bthid_session_p
name|session_by_fd
parameter_list|(
name|bthid_server_p
name|srv
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close
parameter_list|(
name|bthid_session_p
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_control
parameter_list|(
name|bthid_session_p
name|s
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hid_interrupt
parameter_list|(
name|bthid_session_p
name|s
parameter_list|,
name|char
modifier|*
name|data
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _BTHIDD_H_ */
end_comment

end_unit

