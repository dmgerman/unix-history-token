begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lint -save -library Flexelint comment for external headers */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Charles Mott<cm@linktel.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Alias.h defines the outside world interfaces for the packet aliasing  * software.  *   * This software is placed into the public domain with no restrictions on its  * distribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALIAS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALIAS_H_
end_define

begin_comment
comment|/* Alias link representative (incomplete struct) */
end_comment

begin_struct_decl
struct_decl|struct
name|alias_link
struct_decl|;
end_struct_decl

begin_comment
comment|/* External interfaces (API) to packet aliasing engine */
end_comment

begin_comment
comment|/* Initialization and Control */
end_comment

begin_function_decl
specifier|extern
name|void
name|PacketAliasInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PacketAliasUninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PacketAliasSetAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|PacketAliasSetMode
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FW_PUNCH
end_ifndef

begin_function_decl
specifier|extern
name|void
name|PacketAliasSetFWBase
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Packet Handling */
end_comment

begin_function_decl
specifier|extern
name|int
name|PacketAliasIn
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
name|maxpacketsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasOut
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
name|maxpacketsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketUnaliasOut
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
name|maxpacketsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Port and Address Redirection */
end_comment

begin_function_decl
specifier|extern
name|struct
name|alias_link
modifier|*
name|PacketAliasRedirectPort
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasAddServer
parameter_list|(
name|struct
name|alias_link
modifier|*
name|link
parameter_list|,
name|struct
name|in_addr
name|addr
parameter_list|,
name|u_short
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|alias_link
modifier|*
name|PacketAliasRedirectProto
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|alias_link
modifier|*
name|PacketAliasRedirectAddr
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PacketAliasRedirectDelete
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fragment Handling */
end_comment

begin_function_decl
specifier|extern
name|int
name|PacketAliasSaveFragment
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|PacketAliasGetFragment
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PacketAliasFragmentIn
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Miscellaneous Functions */
end_comment

begin_function_decl
specifier|extern
name|void
name|PacketAliasSetTarget
parameter_list|(
name|struct
name|in_addr
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasCheckNewLink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|PacketAliasInternetChecksum
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Transparent Proxying */
end_comment

begin_function_decl
specifier|extern
name|int
name|PacketAliasProxyRule
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************** Mode flags ********************/
end_comment

begin_comment
comment|/* Set these flags using PacketAliasSetMode() */
end_comment

begin_comment
comment|/* If PKT_ALIAS_LOG is set, a message will be printed to 	/var/log/alias.log every time a link is created or deleted.  This 	is useful for debugging */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_LOG
value|0x01
end_define

begin_comment
comment|/* If PKT_ALIAS_DENY_INCOMING is set, then incoming connections (e.g. 	to ftp, telnet or web servers will be prevented by the aliasing 	mechanism.  */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_DENY_INCOMING
value|0x02
end_define

begin_comment
comment|/* If PKT_ALIAS_SAME_PORTS is set, packets will be attempted sent from 	the same port as they originated on.  This allows e.g. rsh to work 	*99% of the time*, but _not_ 100%.  (It will be slightly flakey 	instead of not working at all.)  This mode bit is set by         PacketAliasInit(), so it is a default mode of operation. */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_SAME_PORTS
value|0x04
end_define

begin_comment
comment|/* If PKT_ALIAS_USE_SOCKETS is set, then when partially specified 	links (e.g. destination port and/or address is zero), the packet 	aliasing engine will attempt to allocate a socket for the aliasing 	port it chooses.  This will avoid interference with the host 	machine.  Fully specified links do not require this.  This bit         is set after a call to PacketAliasInit(), so it is a default         mode of operation. */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_USE_SOCKETS
value|0x08
end_define

begin_comment
comment|/* If PKT_ALIAS_UNREGISTERED_ONLY is set, then only packets with 	unregistered source addresses will be aliased.  Private 	addresses are those in the following ranges: 		10.0.0.0     ->   10.255.255.255 		172.16.0.0   ->   172.31.255.255 		192.168.0.0  ->   192.168.255.255  */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_UNREGISTERED_ONLY
value|0x10
end_define

begin_comment
comment|/* If PKT_ALIAS_RESET_ON_ADDR_CHANGE is set, then the table of dynamic 	aliasing links will be reset whenever PacketAliasSetAddress()         changes the default aliasing address.  If the default aliasing         address is left unchanged by this function call, then the         table of dynamic aliasing links will be left intact.  This         bit is set after a call to PacketAliasInit(). */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_RESET_ON_ADDR_CHANGE
value|0x20
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_FW_PUNCH
end_ifndef

begin_comment
comment|/* If PKT_ALIAS_PUNCH_FW is set, active FTP and IRC DCC connections    will create a 'hole' in the firewall to allow the transfers to    work.  Where (IPFW "line-numbers") the hole is created is    controlled by PacketAliasSetFWBase(base, size). The hole will be    attached to that particular alias_link, so when the link goes away    so do the hole.  */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_PUNCH_FW
value|0x100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If PKT_ALIAS_PROXY_ONLY is set, then NAT will be disabled and only       transparent proxying performed */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_PROXY_ONLY
value|0x40
end_define

begin_comment
comment|/* If PKT_ALIAS_REVERSE is set, the actions of PacketAliasIn()       and PacketAliasOut() are reversed */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_REVERSE
value|0x80
end_define

begin_comment
comment|/* Return Codes */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|PKT_ALIAS_OK
value|1
end_define

begin_define
define|#
directive|define
name|PKT_ALIAS_IGNORED
value|2
end_define

begin_define
define|#
directive|define
name|PKT_ALIAS_UNRESOLVED_FRAGMENT
value|3
end_define

begin_define
define|#
directive|define
name|PKT_ALIAS_FOUND_HEADER_FRAGMENT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint -restore */
end_comment

end_unit

