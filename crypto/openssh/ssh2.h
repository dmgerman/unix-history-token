begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * draft-ietf-secsh-architecture-05.txt  *  *   Transport layer protocol:  *  *     1-19     Transport layer generic (e.g. disconnect, ignore, debug,  *              etc)  *     20-29    Algorithm negotiation  *     30-49    Key exchange method specific (numbers can be reused for  *              different authentication methods)  *  *   User authentication protocol:  *  *     50-59    User authentication generic  *     60-79    User authentication method specific (numbers can be reused  *              for different authentication methods)  *  *   Connection protocol:  *  *     80-89    Connection protocol generic  *     90-127   Channel related messages  *  *   Reserved for client protocols:  *  *     128-191  Reserved  *  *   Local extensions:  *  *     192-255  Local extensions  */
end_comment

begin_comment
comment|/* RCSID("$OpenBSD: ssh2.h,v 1.5 2000/10/11 04:02:17 provos Exp $"); */
end_comment

begin_comment
comment|/* transport layer: generic */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_DISCONNECT
value|1
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_IGNORE
value|2
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_UNIMPLEMENTED
value|3
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_DEBUG
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_SERVICE_REQUEST
value|5
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_SERVICE_ACCEPT
value|6
end_define

begin_comment
comment|/* transport layer: alg negotiation */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_KEXINIT
value|20
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_NEWKEYS
value|21
end_define

begin_comment
comment|/* transport layer: kex specific messages, can be reused */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_KEXDH_INIT
value|30
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_KEXDH_REPLY
value|31
end_define

begin_comment
comment|/* dh-group-exchange */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_KEX_DH_GEX_REQUEST
value|30
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_KEX_DH_GEX_GROUP
value|31
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_KEX_DH_GEX_INIT
value|32
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_KEX_DH_GEX_REPLY
value|33
end_define

begin_comment
comment|/* user authentication: generic */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_REQUEST
value|50
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_FAILURE
value|51
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_SUCCESS
value|52
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_BANNER
value|53
end_define

begin_comment
comment|/* user authentication: method specific, can be reused */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_PK_OK
value|60
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_PASSWD_CHANGEREQ
value|60
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_INFO_REQUEST
value|60
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_USERAUTH_INFO_RESPONSE
value|61
end_define

begin_comment
comment|/* connection protocol: generic */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_GLOBAL_REQUEST
value|80
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_REQUEST_SUCCESS
value|81
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_REQUEST_FAILURE
value|82
end_define

begin_comment
comment|/* channel related messages */
end_comment

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_OPEN
value|90
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_OPEN_CONFIRMATION
value|91
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_OPEN_FAILURE
value|92
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_WINDOW_ADJUST
value|93
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_DATA
value|94
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_EXTENDED_DATA
value|95
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_EOF
value|96
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_CLOSE
value|97
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_REQUEST
value|98
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_SUCCESS
value|99
end_define

begin_define
define|#
directive|define
name|SSH2_MSG_CHANNEL_FAILURE
value|100
end_define

begin_comment
comment|/* disconnect reason code */
end_comment

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_HOST_NOT_ALLOWED_TO_CONNECT
value|1
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_PROTOCOL_ERROR
value|2
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_KEY_EXCHANGE_FAILED
value|3
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_HOST_AUTHENTICATION_FAILED
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_RESERVED
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_MAC_ERROR
value|5
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_COMPRESSION_ERROR
value|6
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_SERVICE_NOT_AVAILABLE
value|7
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_PROTOCOL_VERSION_NOT_SUPPORTED
value|8
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_HOST_KEY_NOT_VERIFIABLE
value|9
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_CONNECTION_LOST
value|10
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_BY_APPLICATION
value|11
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_TOO_MANY_CONNECTIONS
value|12
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_AUTH_CANCELLED_BY_USER
value|13
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_NO_MORE_AUTH_METHODS_AVAILABLE
value|14
end_define

begin_define
define|#
directive|define
name|SSH2_DISCONNECT_ILLEGAL_USER_NAME
value|15
end_define

begin_comment
comment|/* misc */
end_comment

begin_define
define|#
directive|define
name|SSH2_OPEN_ADMINISTRATIVELY_PROHIBITED
value|1
end_define

begin_define
define|#
directive|define
name|SSH2_OPEN_CONNECT_FAILED
value|2
end_define

begin_define
define|#
directive|define
name|SSH2_OPEN_UNKNOWN_CHANNEL_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|SSH2_OPEN_RESOURCE_SHORTAGE
value|4
end_define

begin_define
define|#
directive|define
name|SSH2_EXTENDED_DATA_STDERR
value|1
end_define

end_unit

