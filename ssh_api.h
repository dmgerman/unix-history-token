begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: ssh_api.h,v 1.1 2015/01/19 20:30:23 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2012 Markus Friedl.  All rights reserved.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|API_H
end_ifndef

begin_define
define|#
directive|define
name|API_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|"openbsd-compat/sys-queue.h"
end_include

begin_include
include|#
directive|include
file|"cipher.h"
end_include

begin_include
include|#
directive|include
file|"sshkey.h"
end_include

begin_include
include|#
directive|include
file|"kex.h"
end_include

begin_include
include|#
directive|include
file|"ssh.h"
end_include

begin_include
include|#
directive|include
file|"ssh2.h"
end_include

begin_include
include|#
directive|include
file|"packet.h"
end_include

begin_struct
struct|struct
name|kex_params
block|{
name|char
modifier|*
name|proposal
index|[
name|PROPOSAL_MAX
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* public SSH API functions */
end_comment

begin_comment
comment|/*  * ssh_init() create a ssh connection object with given (optional)  * key exchange parameters.  */
end_comment

begin_function_decl
name|int
name|ssh_init
parameter_list|(
name|struct
name|ssh
modifier|*
modifier|*
parameter_list|,
name|int
name|is_server
parameter_list|,
name|struct
name|kex_params
modifier|*
name|kex_params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * release ssh connection state.  */
end_comment

begin_function_decl
name|void
name|ssh_free
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * attach application specific data to the connection state  */
end_comment

begin_function_decl
name|void
name|ssh_set_app_data
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|ssh_get_app_data
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_add_hostkey() registers a private/public hostkey for an ssh  * connection.  * ssh_add_hostkey() needs to be called before a key exchange is  * initiated with ssh_packet_next().  * private hostkeys are required if we need to act as a server.  * public hostkeys are used to verify the servers hostkey.  */
end_comment

begin_function_decl
name|int
name|ssh_add_hostkey
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|struct
name|sshkey
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_set_verify_host_key_callback() registers a callback function  * which should be called instead of the default verification. The  * function given must return 0 if the hostkey is ok, -1 if the  * verification has failed.  */
end_comment

begin_function_decl
name|int
name|ssh_set_verify_host_key_callback
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|int
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|struct
name|sshkey
modifier|*
parameter_list|,
name|struct
name|ssh
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_packet_next() advances to the next input packet and returns  * the packet type in typep.  * ssh_packet_next() works by processing an input byte-stream,  * decrypting the received data and hiding the key-exchange from  * the caller.  * ssh_packet_next() sets typep if there is no new packet available.  * in this case the caller must fill the input byte-stream by passing  * the data received over network to ssh_input_append().  * additinally, the caller needs to send the resulting output  * byte-stream back over the network. otherwise the key exchange  * would not proceed. the output byte-stream is accessed through  * ssh_output_ptr().  */
end_comment

begin_function_decl
name|int
name|ssh_packet_next
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|u_char
modifier|*
name|typep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_packet_payload() returns a pointer to the raw payload data of  * the current input packet and the length of this payload.  * the payload is accessible until ssh_packet_next() is called again.  */
end_comment

begin_function_decl
specifier|const
name|u_char
modifier|*
name|ssh_packet_payload
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|size_t
modifier|*
name|lenp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_packet_put() creates an encrypted packet with the given type  * and payload.  * the encrypted packet is appended to the output byte-stream.  */
end_comment

begin_function_decl
name|int
name|ssh_packet_put
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|int
name|type
parameter_list|,
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_input_space() checks if 'len' bytes can be appended to the  * input byte-stream.  */
end_comment

begin_function_decl
name|int
name|ssh_input_space
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_input_append() appends data to the input byte-stream.  */
end_comment

begin_function_decl
name|int
name|ssh_input_append
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
specifier|const
name|u_char
modifier|*
name|data
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_output_space() checks if 'len' bytes can be appended to the  * output byte-stream. XXX  */
end_comment

begin_function_decl
name|int
name|ssh_output_space
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_output_ptr() retrieves both a pointer and the length of the  * current output byte-stream. the bytes need to be sent over the  * network. the number of bytes that have been successfully sent can  * be removed from the output byte-stream with ssh_output_consume().  */
end_comment

begin_function_decl
specifier|const
name|u_char
modifier|*
name|ssh_output_ptr
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ssh_output_consume() removes the given number of bytes from  * the output byte-stream.  */
end_comment

begin_function_decl
name|int
name|ssh_output_consume
parameter_list|(
name|struct
name|ssh
modifier|*
name|ssh
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

