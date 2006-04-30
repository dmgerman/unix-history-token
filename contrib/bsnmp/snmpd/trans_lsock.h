begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/snmpd/trans_lsock.h,v 1.3 2004/08/06 08:47:15 brandt Exp $  *  * Local domain socket transport  */
end_comment

begin_enum
enum|enum
name|locp
block|{
name|LOCP_DGRAM_UNPRIV
init|=
literal|1
block|,
name|LOCP_DGRAM_PRIV
init|=
literal|2
block|,
name|LOCP_STREAM_UNPRIV
init|=
literal|3
block|,
name|LOCP_STREAM_PRIV
init|=
literal|4
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|lsock_peer
block|{
name|LIST_ENTRY
argument_list|(
argument|lsock_peer
argument_list|)
name|link
expr_stmt|;
name|struct
name|port_input
name|input
decl_stmt|;
name|struct
name|sockaddr_un
name|peer
decl_stmt|;
name|struct
name|lsock_port
modifier|*
name|port
decl_stmt|;
comment|/* parent port */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lsock_port
block|{
name|struct
name|tport
name|tport
decl_stmt|;
comment|/* must begin with this */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* unix path name */
name|enum
name|locp
name|type
decl_stmt|;
comment|/* type of port */
name|int
name|str_sock
decl_stmt|;
comment|/* stream socket */
name|void
modifier|*
name|str_id
decl_stmt|;
comment|/* select handle */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|lsock_peer
argument_list|)
name|peers
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|transport_def
name|lsock_trans
decl_stmt|;
end_decl_stmt

end_unit

