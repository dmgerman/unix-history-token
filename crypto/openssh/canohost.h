begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: canohost.h,v 1.6 2001/04/12 19:15:24 markus Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Return the canonical name of the host in the other side of the current  * connection (as returned by packet_get_connection).  The host name is  * cached, so it is efficient to call this several times.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_canonical_hostname
parameter_list|(
name|int
name|reverse_mapping_check
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Returns the IP-address of the remote host as a string.  The returned  * string is cached and must not be freed.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|get_remote_ipaddr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|get_remote_name_or_ip
parameter_list|(
name|u_int
name|utmp_len
parameter_list|,
name|int
name|reverse_mapping_check
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the ipaddr/port number of the peer of the socket. */
end_comment

begin_function_decl
name|char
modifier|*
name|get_peer_ipaddr
parameter_list|(
name|int
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_peer_port
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_local_ipaddr
parameter_list|(
name|int
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|get_local_name
parameter_list|(
name|int
name|socket
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns the port number of the remote/local host. */
end_comment

begin_function_decl
name|int
name|get_remote_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|get_local_port
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

