begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  *	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: bsnmp/snmpd/trans_udp.h,v 1.3 2004/08/06 08:47:16 brandt Exp $  *  * UDP transport  */
end_comment

begin_struct
struct|struct
name|udp_port
block|{
name|struct
name|tport
name|tport
decl_stmt|;
comment|/* must begin with this */
name|uint8_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* host byteorder */
name|uint16_t
name|port
decl_stmt|;
comment|/* host byteorder */
name|struct
name|port_input
name|input
decl_stmt|;
comment|/* common input stuff */
name|struct
name|sockaddr_in
name|ret
decl_stmt|;
comment|/* the return address */
block|}
struct|;
end_struct

begin_comment
comment|/* argument for open call */
end_comment

begin_struct
struct|struct
name|udp_open
block|{
name|uint8_t
name|addr
index|[
literal|4
index|]
decl_stmt|;
comment|/* host byteorder */
name|uint16_t
name|port
decl_stmt|;
comment|/* host byteorder */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|transport_def
name|udp_trans
decl_stmt|;
end_decl_stmt

end_unit

