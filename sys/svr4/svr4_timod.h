begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1998 Mark Newton  * Copyright (c) 1994 Christos Zoulas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVR4_TIMOD_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVR4_TIMOD_H_
end_define

begin_define
define|#
directive|define
name|SVR4_TIMOD
value|('T'<< 8)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_GETINFO
value|(SVR4_TIMOD|140)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OPTMGMT
value|(SVR4_TIMOD|141)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_BIND
value|(SVR4_TIMOD|142)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_UNBIND
value|(SVR4_TIMOD|143)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_GETMYNAME
value|(SVR4_TIMOD|144)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_GETPEERNAME
value|(SVR4_TIMOD|145)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_SETMYNAME
value|(SVR4_TIMOD|146)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_SETPEERNAME
value|(SVR4_TIMOD|147)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_SYNC
value|(SVR4_TIMOD|148)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_GETADDRS
value|(SVR4_TIMOD|149)
end_define

begin_define
define|#
directive|define
name|SVR4_TI_CONNECT_REQUEST
value|0x00
end_define

begin_define
define|#
directive|define
name|SVR4_TI_CONNECT_RESPONSE
value|0x01
end_define

begin_define
define|#
directive|define
name|SVR4_TI_DISCONNECT_REQUEST
value|0x02
end_define

begin_define
define|#
directive|define
name|SVR4_TI_DATA_REQUEST
value|0x03
end_define

begin_define
define|#
directive|define
name|SVR4_TI_EXPDATA_REQUEST
value|0x04
end_define

begin_define
define|#
directive|define
name|SVR4_TI_INFO_REQUEST
value|0x05
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OLD_BIND_REQUEST
value|0x06
end_define

begin_define
define|#
directive|define
name|SVR4_TI_UNBIND_REQUEST
value|0x07
end_define

begin_define
define|#
directive|define
name|SVR4_TI_SENDTO_REQUEST
value|0x08
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OLD_OPTMGMT_REQUEST
value|0x09
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ORDREL_REQUEST
value|0x0a
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ACCEPT_REPLY
value|0x0b
end_define

begin_define
define|#
directive|define
name|SVR4_TI_CONNECT_REPLY
value|0x0c
end_define

begin_define
define|#
directive|define
name|SVR4_TI_DISCONNECT_IND
value|0x0d
end_define

begin_define
define|#
directive|define
name|SVR4_TI_DATA_IND
value|0x0e
end_define

begin_define
define|#
directive|define
name|SVR4_TI_EXPDATA_IND
value|0x0f
end_define

begin_define
define|#
directive|define
name|SVR4_TI_INFO_REPLY
value|0x10
end_define

begin_define
define|#
directive|define
name|SVR4_TI_BIND_REPLY
value|0x11
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ERROR_REPLY
value|0x12
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OK_REPLY
value|0x13
end_define

begin_define
define|#
directive|define
name|SVR4_TI_RECVFROM_IND
value|0x14
end_define

begin_define
define|#
directive|define
name|SVR4_TI_RECVFROM_ERROR_IND
value|0x15
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OPTMGMT_REPLY
value|0x16
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ORDREL_IND
value|0x17
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ADDRESS_REQUEST
value|0x18
end_define

begin_define
define|#
directive|define
name|SVR4_TI_ADDRESS_REPLY
value|0x19
end_define

begin_define
define|#
directive|define
name|SVR4_TI_BIND_REQUEST
value|0x20
end_define

begin_define
define|#
directive|define
name|SVR4_TI_OPTMGMT_REQUEST
value|0x21
end_define

begin_define
define|#
directive|define
name|SVR4_TI__ACCEPT_WAIT
value|0x10000001
end_define

begin_define
define|#
directive|define
name|SVR4_TI__ACCEPT_OK
value|0x10000002
end_define

begin_struct
struct|struct
name|svr4_netbuf
block|{
name|u_int
name|maxlen
decl_stmt|;
name|u_int
name|len
decl_stmt|;
name|char
modifier|*
name|buf
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SVR4_TIMOD_H_ */
end_comment

end_unit

