begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RADLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_RADLIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* Message types */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCESS_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|RAD_ACCESS_ACCEPT
value|2
end_define

begin_define
define|#
directive|define
name|RAD_ACCESS_REJECT
value|3
end_define

begin_define
define|#
directive|define
name|RAD_ACCOUNTING_REQUEST
value|4
end_define

begin_define
define|#
directive|define
name|RAD_ACCOUNTING_RESPONSE
value|5
end_define

begin_define
define|#
directive|define
name|RAD_ACCESS_CHALLENGE
value|11
end_define

begin_comment
comment|/* Attribute types and values */
end_comment

begin_define
define|#
directive|define
name|RAD_USER_NAME
value|1
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_USER_PASSWORD
value|2
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_CHAP_PASSWORD
value|3
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_NAS_IP_ADDRESS
value|4
end_define

begin_comment
comment|/* IP address */
end_comment

begin_define
define|#
directive|define
name|RAD_NAS_PORT
value|5
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_SERVICE_TYPE
value|6
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN
value|1
end_define

begin_define
define|#
directive|define
name|RAD_FRAMED
value|2
end_define

begin_define
define|#
directive|define
name|RAD_CALLBACK_LOGIN
value|3
end_define

begin_define
define|#
directive|define
name|RAD_CALLBACK_FRAMED
value|4
end_define

begin_define
define|#
directive|define
name|RAD_OUTBOUND
value|5
end_define

begin_define
define|#
directive|define
name|RAD_ADMINISTRATIVE
value|6
end_define

begin_define
define|#
directive|define
name|RAD_NAS_PROMPT
value|7
end_define

begin_define
define|#
directive|define
name|RAD_AUTHENTICATE_ONLY
value|8
end_define

begin_define
define|#
directive|define
name|RAD_CALLBACK_NAS_PROMPT
value|9
end_define

begin_define
define|#
directive|define
name|RAD_FRAMED_PROTOCOL
value|7
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_PPP
value|1
end_define

begin_define
define|#
directive|define
name|RAD_SLIP
value|2
end_define

begin_define
define|#
directive|define
name|RAD_ARAP
value|3
end_define

begin_comment
comment|/* Appletalk */
end_comment

begin_define
define|#
directive|define
name|RAD_GANDALF
value|4
end_define

begin_define
define|#
directive|define
name|RAD_XYLOGICS
value|5
end_define

begin_define
define|#
directive|define
name|RAD_FRAMED_IP_ADDRESS
value|8
end_define

begin_comment
comment|/* IP address */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_IP_NETMASK
value|9
end_define

begin_comment
comment|/* IP address */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_ROUTING
value|10
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_FILTER_ID
value|11
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_MTU
value|12
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_COMPRESSION
value|13
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_COMP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RAD_COMP_VJ
value|1
end_define

begin_define
define|#
directive|define
name|RAD_COMP_IPXHDR
value|2
end_define

begin_define
define|#
directive|define
name|RAD_LOGIN_IP_HOST
value|14
end_define

begin_comment
comment|/* IP address */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_SERVICE
value|15
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_TCP_PORT
value|16
end_define

begin_comment
comment|/* Integer */
end_comment

begin_comment
comment|/* unassiged			17 */
end_comment

begin_define
define|#
directive|define
name|RAD_REPLY_MESSAGE
value|18
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_CALLBACK_NUMBER
value|19
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_CALLBACK_ID
value|20
end_define

begin_comment
comment|/* String */
end_comment

begin_comment
comment|/* unassiged			21 */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_ROUTE
value|22
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_IPX_NETWORK
value|23
end_define

begin_comment
comment|/* IP address */
end_comment

begin_define
define|#
directive|define
name|RAD_STATE
value|24
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_CLASS
value|25
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_VENDOR_SPECIFIC
value|26
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_SESSION_TIMEOUT
value|27
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_IDLE_TIMEOUT
value|28
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_TERMINATION_ACTION
value|29
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_CALLED_STATION_ID
value|30
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_CALLING_STATION_ID
value|31
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_NAS_IDENTIFIER
value|32
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_PROXY_STATE
value|33
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_LAT_SERVICE
value|34
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_LAT_NODE
value|35
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_LAT_GROUP
value|36
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_APPLETALK_LINK
value|37
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_APPLETALK_NETWORK
value|38
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_FRAMED_APPLETALK_ZONE
value|39
end_define

begin_comment
comment|/* Integer */
end_comment

begin_comment
comment|/* reserved for accounting		40-59 */
end_comment

begin_define
define|#
directive|define
name|RAD_CHAP_CHALLENGE
value|60
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_NAS_PORT_TYPE
value|61
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ASYNC
value|0
end_define

begin_define
define|#
directive|define
name|RAD_SYNC
value|1
end_define

begin_define
define|#
directive|define
name|RAD_ISDN_SYNC
value|2
end_define

begin_define
define|#
directive|define
name|RAD_ISDN_ASYNC_V120
value|3
end_define

begin_define
define|#
directive|define
name|RAD_ISDN_ASYNC_V110
value|4
end_define

begin_define
define|#
directive|define
name|RAD_VIRTUAL
value|5
end_define

begin_define
define|#
directive|define
name|RAD_PORT_LIMIT
value|62
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_LOGIN_LAT_PORT
value|63
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_CONNECT_INFO
value|77
end_define

begin_comment
comment|/* String */
end_comment

begin_comment
comment|/* Accounting attribute types and values */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_STATUS_TYPE
value|40
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_START
value|1
end_define

begin_define
define|#
directive|define
name|RAD_STOP
value|2
end_define

begin_define
define|#
directive|define
name|RAD_ACCOUNTING_ON
value|7
end_define

begin_define
define|#
directive|define
name|RAD_ACCOUNTING_OFF
value|8
end_define

begin_define
define|#
directive|define
name|RAD_ACCT_DELAY_TIME
value|41
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_INPUT_OCTETS
value|42
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_OUTPUT_OCTETS
value|43
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_SESSION_ID
value|44
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_AUTHENTIC
value|45
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_AUTH_RADIUS
value|1
end_define

begin_define
define|#
directive|define
name|RAD_AUTH_LOCAL
value|2
end_define

begin_define
define|#
directive|define
name|RAD_AUTH_REMOTE
value|3
end_define

begin_define
define|#
directive|define
name|RAD_ACCT_SESSION_TIME
value|46
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_INPUT_PACKETS
value|47
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_OUTPUT_PACKETS
value|48
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_TERMINATE_CAUSE
value|49
end_define

begin_comment
comment|/* Integer */
end_comment

begin_define
define|#
directive|define
name|RAD_TERM_USER_REQUEST
value|1
end_define

begin_define
define|#
directive|define
name|RAD_TERM_LOST_CARRIER
value|2
end_define

begin_define
define|#
directive|define
name|RAD_TERM_LOST_SERVICE
value|3
end_define

begin_define
define|#
directive|define
name|RAD_TERM_IDLE_TIMEOUT
value|4
end_define

begin_define
define|#
directive|define
name|RAD_TERM_SESSION_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|RAD_TERM_ADMIN_RESET
value|6
end_define

begin_define
define|#
directive|define
name|RAD_TERM_ADMIN_REBOOT
value|7
end_define

begin_define
define|#
directive|define
name|RAD_TERM_PORT_ERROR
value|8
end_define

begin_define
define|#
directive|define
name|RAD_TERM_NAS_ERROR
value|9
end_define

begin_define
define|#
directive|define
name|RAD_TERM_NAS_REQUEST
value|10
end_define

begin_define
define|#
directive|define
name|RAD_TERM_NAS_REBOOT
value|11
end_define

begin_define
define|#
directive|define
name|RAD_TERM_PORT_UNNEEDED
value|12
end_define

begin_define
define|#
directive|define
name|RAD_TERM_PORT_PREEMPTED
value|13
end_define

begin_define
define|#
directive|define
name|RAD_TERM_PORT_SUSPENDED
value|14
end_define

begin_define
define|#
directive|define
name|RAD_TERM_SERVICE_UNAVAILABLE
value|15
end_define

begin_define
define|#
directive|define
name|RAD_TERM_CALLBACK
value|16
end_define

begin_define
define|#
directive|define
name|RAD_TERM_USER_ERROR
value|17
end_define

begin_define
define|#
directive|define
name|RAD_TERM_HOST_REQUEST
value|18
end_define

begin_define
define|#
directive|define
name|RAD_ACCT_MULTI_SESSION_ID
value|50
end_define

begin_comment
comment|/* String */
end_comment

begin_define
define|#
directive|define
name|RAD_ACCT_LINK_COUNT
value|51
end_define

begin_comment
comment|/* Integer */
end_comment

begin_struct_decl
struct_decl|struct
name|rad_handle
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|rad_handle
modifier|*
name|rad_acct_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_add_server
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rad_handle
modifier|*
name|rad_auth_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rad_close
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_config
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_continue_send_request
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_create_request
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|rad_cvt_addr
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int32_t
name|rad_cvt_int
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|rad_cvt_string
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_get_attr
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_init_send_request
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|struct
name|timeval
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|rad_handle
modifier|*
name|rad_open
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Deprecated, == rad_auth_open */
end_comment

begin_function_decl
name|int
name|rad_put_addr
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_attr
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_int
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_put_string
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rad_send_request
parameter_list|(
name|struct
name|rad_handle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|rad_strerror
parameter_list|(
name|struct
name|rad_handle
modifier|*
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
comment|/* _RADLIB_H_ */
end_comment

end_unit

