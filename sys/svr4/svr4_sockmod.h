begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_SOCKMOD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_SOCKMOD_H_
end_define

begin_define
define|#
directive|define
name|SVR4_SIMOD
value|('I'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_OGETUDATA
value|(SVR4_SIMOD|101)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SHUTDOWN
value|(SVR4_SIMOD|102)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_LISTEN
value|(SVR4_SIMOD|103)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SETMYNAME
value|(SVR4_SIMOD|104)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SETPEERNAME
value|(SVR4_SIMOD|105)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_GETINTRANSIT
value|(SVR4_SIMOD|106)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_TCL_LINK
value|(SVR4_SIMOD|107)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_TCL_UNLINK
value|(SVR4_SIMOD|108)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_SOCKPARAMS
value|(SVR4_SIMOD|109)
end_define

begin_define
define|#
directive|define
name|SVR4_SI_GETUDATA
value|(SVR4_SIMOD|110)
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_DGRAM
value|1
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_STREAM
value|2
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_STREAM_ORD
value|3
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_RAW
value|4
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_RDM
value|5
end_define

begin_define
define|#
directive|define
name|SVR4_SOCK_SEQPACKET
value|6
end_define

begin_struct
struct|struct
name|svr4_si_sockparms
block|{
name|int
name|family
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|protocol
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_si_oudata
block|{
name|int
name|tidusize
decl_stmt|;
name|int
name|addrsize
decl_stmt|;
name|int
name|optsize
decl_stmt|;
name|int
name|etsdusize
decl_stmt|;
name|int
name|servtype
decl_stmt|;
name|int
name|so_state
decl_stmt|;
name|int
name|so_options
decl_stmt|;
name|int
name|tsdusize
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svr4_si_udata
block|{
name|int
name|tidusize
decl_stmt|;
name|int
name|addrsize
decl_stmt|;
name|int
name|optsize
decl_stmt|;
name|int
name|etsdusize
decl_stmt|;
name|int
name|servtype
decl_stmt|;
name|int
name|so_state
decl_stmt|;
name|int
name|so_options
decl_stmt|;
name|int
name|tsdusize
decl_stmt|;
name|struct
name|svr4_si_sockparms
name|sockparms
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_SOCKMOD_H_ */
end_comment

end_unit

