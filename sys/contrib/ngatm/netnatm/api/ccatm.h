begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003-2004  *	Hartmut Brandt  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE AND DOCUMENTATION IS PROVIDED BY THE AUTHOR  * AND ITS CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL  * THE AUTHOR OR ITS CONTRIBUTORS  BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $Begemot: libunimsg/netnatm/api/ccatm.h,v 1.1 2004/07/08 08:21:58 brandt Exp $  *  * ATM API as defined per af-saa-0108  *  * Interface to the supporting code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_API_CCATM_H_
end_ifndef

begin_define
define|#
directive|define
name|_API_CCATM_H_
end_define

begin_struct_decl
struct_decl|struct
name|ccuser
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccconn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccport
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ccdata
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|cc_funcs
block|{
comment|/* send signal to API user */
name|void
function_decl|(
modifier|*
name|send_user
function_decl|)
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* respond API user */
name|void
function_decl|(
modifier|*
name|respond_user
function_decl|)
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
comment|/* send signal to uni for connection */
name|void
function_decl|(
modifier|*
name|send_uni
function_decl|)
parameter_list|(
name|struct
name|ccconn
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* send global signal to uni */
name|void
function_decl|(
modifier|*
name|send_uni_glob
function_decl|)
parameter_list|(
name|struct
name|ccport
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
comment|/* log a message */
name|void
function_decl|(
modifier|*
name|log
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|CCLOG_USER_STATE
init|=
literal|0x00000001
block|,
name|CCLOG_USER_INST
init|=
literal|0x00000002
block|,
name|CCLOG_USER_SIG
init|=
literal|0x00000004
block|,
name|CCLOG_CONN_STATE
init|=
literal|0x00000010
block|,
name|CCLOG_CONN_INST
init|=
literal|0x00000020
block|,
name|CCLOG_CONN_SIG
init|=
literal|0x00000040
block|,
name|CCLOG_PARTY_STATE
init|=
literal|0x00000100
block|,
name|CCLOG_PARTY_INST
init|=
literal|0x00000200
block|,
name|CCLOG_PARTY_SIG
init|=
literal|0x00000400
block|,
name|CCLOG_SIGS
init|=
literal|0x00001000
block|, }
enum|;
end_enum

begin_comment
comment|/* instance handling */
end_comment

begin_function_decl
name|struct
name|ccdata
modifier|*
name|cc_create
parameter_list|(
specifier|const
name|struct
name|cc_funcs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_destroy
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cc_reset
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* input a response from the UNI layer to CC */
end_comment

begin_function_decl
name|int
name|cc_uni_response
parameter_list|(
name|struct
name|ccport
modifier|*
parameter_list|,
name|u_int
name|cookie
parameter_list|,
name|u_int
name|reason
parameter_list|,
name|u_int
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Signal from UNI on this port */
end_comment

begin_function_decl
name|int
name|cc_uni_signal
parameter_list|(
name|struct
name|ccport
modifier|*
parameter_list|,
name|u_int
name|cookie
parameter_list|,
name|u_int
name|sig
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* retrieve addresses */
end_comment

begin_function_decl
name|int
name|cc_get_addrs
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|uni_addr
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dump state */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cc_dump_f
function_decl|)
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|cc_dump
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|cc_dump_f
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* start/stop port */
end_comment

begin_function_decl
name|int
name|cc_port_stop
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cc_port_start
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* is port running? */
end_comment

begin_function_decl
name|int
name|cc_port_isrunning
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* return port number */
end_comment

begin_function_decl
name|u_int
name|cc_port_no
parameter_list|(
name|struct
name|ccport
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clear address and prefix information from the named port. */
end_comment

begin_function_decl
name|int
name|cc_port_clear
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Address registered.  */
end_comment

begin_function_decl
name|int
name|cc_addr_register
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|uni_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Address unregistered. */
end_comment

begin_function_decl
name|int
name|cc_addr_unregister
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
specifier|const
name|struct
name|uni_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get port info */
end_comment

begin_function_decl
name|int
name|cc_port_get_param
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|atm_port_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set port info */
end_comment

begin_function_decl
name|int
name|cc_port_set_param
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
specifier|const
name|struct
name|atm_port_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get port list */
end_comment

begin_function_decl
name|int
name|cc_port_getlist
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* create a port */
end_comment

begin_function_decl
name|struct
name|ccport
modifier|*
name|cc_port_create
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy a port */
end_comment

begin_function_decl
name|void
name|cc_port_destroy
parameter_list|(
name|struct
name|ccport
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* New endpoint created */
end_comment

begin_function_decl
name|struct
name|ccuser
modifier|*
name|cc_user_create
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy user endpoint */
end_comment

begin_function_decl
name|void
name|cc_user_destroy
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* signal from user */
end_comment

begin_function_decl
name|int
name|cc_user_signal
parameter_list|(
name|struct
name|ccuser
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Management is given up on this node. */
end_comment

begin_function_decl
name|void
name|cc_unmanage
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* handle all queued signals */
end_comment

begin_function_decl
name|void
name|cc_work
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set/get logging flags */
end_comment

begin_function_decl
name|void
name|cc_set_log
parameter_list|(
name|struct
name|ccdata
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|cc_get_log
parameter_list|(
specifier|const
name|struct
name|ccdata
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get extended status */
end_comment

begin_function_decl
name|int
name|cc_get_extended_status
parameter_list|(
specifier|const
name|struct
name|ccdata
modifier|*
parameter_list|,
name|struct
name|atm_exstatus
modifier|*
parameter_list|,
name|struct
name|atm_exstatus_ep
modifier|*
modifier|*
parameter_list|,
name|struct
name|atm_exstatus_port
modifier|*
modifier|*
parameter_list|,
name|struct
name|atm_exstatus_conn
modifier|*
modifier|*
parameter_list|,
name|struct
name|atm_exstatus_party
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

