begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bluetooth.h  *  * Copyright (c) 2001-2003 Maksim Yevmenkin<m_evmenkin@yahoo.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: bluetooth.h,v 1.5 2003/09/14 23:28:42 max Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BLUETOOTH_H_
end_ifndef

begin_define
define|#
directive|define
name|_BLUETOOTH_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bitstring.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/include/ng_hci.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/include/ng_l2cap.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/bluetooth/include/ng_btsocket.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
comment|/*  * Linux BlueZ compatibility  */
define|#
directive|define
name|bacmp
parameter_list|(
name|ba1
parameter_list|,
name|ba2
parameter_list|)
value|memcmp((ba1), (ba2), sizeof(bdaddr_t))
define|#
directive|define
name|bacpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
value|memcpy((dst), (src), sizeof(bdaddr_t))
define|#
directive|define
name|ba2str
parameter_list|(
name|ba
parameter_list|,
name|str
parameter_list|)
value|bt_ntoa((ba), (str))
define|#
directive|define
name|str2ba
parameter_list|(
name|str
parameter_list|,
name|ba
parameter_list|)
value|(bt_aton((str), (ba)) == 1? 0 : -1)
comment|/*  * Interface to the outside world  */
name|struct
name|hostent
modifier|*
name|bt_gethostbyname
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|bt_gethostbyaddr
parameter_list|(
name|char
specifier|const
modifier|*
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|bt_gethostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_sethostent
parameter_list|(
name|int
name|stayopen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_endhostent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|bt_getprotobyname
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|bt_getprotobynumber
parameter_list|(
name|int
name|proto
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|protoent
modifier|*
name|bt_getprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_setprotoent
parameter_list|(
name|int
name|stayopen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bt_endprotoent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
specifier|const
modifier|*
name|bt_ntoa
parameter_list|(
name|bdaddr_t
specifier|const
modifier|*
name|ba
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bt_aton
parameter_list|(
name|char
specifier|const
modifier|*
name|str
parameter_list|,
name|bdaddr_t
modifier|*
name|ba
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef _BLUETOOTH_H_ */
end_comment

end_unit

