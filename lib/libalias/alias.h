begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*lint -save -library Flexelint comment for external headers */
end_comment

begin_comment
comment|/*     Alias.h defines the outside world interfaces for the packet     aliasing software.      This software is placed into the public domain with no restrictions     on its distribution. */
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

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*    In version 2.2, the function names were rationalized    to all be of the form PacketAlias...  These are the    old function names for backwards compatibility */
end_comment

begin_function_decl
specifier|extern
name|int
name|SaveFragmentPtr
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
name|GetNextFragmentPtr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FragmentAliasIn
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SetPacketAliasAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|InitPacketAlias
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|SetPacketAliasMode
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasIn2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
name|maxpacketsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasOut2
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|int
name|maxpacketsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PacketAliasPermanentLink
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
name|u_short
parameter_list|,
name|u_char
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_short
name|InternetChecksum
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obsolete constant */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_NEW_LINK
value|5
end_define

begin_comment
comment|/********************** Mode flags ********************/
end_comment

begin_comment
comment|/* Set these flags using SetPacketAliasMode() */
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
comment|/* If PKT_ALIAS_SAME_PORTS is set, packets will be attempted sent from 	the same port as they originated on.  This allows eg rsh to work 	*99% of the time*, but _not_ 100%.  (It will be slightly flakey 	instead of not working at all.)  This mode bit is set by         PacketAliasInit(), so it is a default mode of operation. */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_SAME_PORTS
value|0x04
end_define

begin_comment
comment|/* If PKT_ALIAS_USE_SOCKETS is set, then when partially specified 	links (e.g. destination port and/or address is zero), the packet 	aliasing engine will attempt to allocate a socket for the aliasing 	port it chooses.  This will avoid interference with the host 	machine.  Fully specified links do not require this.  This bit         is set after a call to PacketAliasInit(), so it is a default         mode of operation.*/
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_USE_SOCKETS
value|0x08
end_define

begin_comment
comment|/* If PKT_ALIAS_UNREGISTERED_ONLY is set, then only packets with with 	unregistered source addresses will be aliased (along with those 	of the ppp host maching itself.  Private addresses are those         in the following ranges:  		10.0.0.0     ->   10.255.255.255 		172.16.0.0   ->   172.31.255.255 		192.168.0.0  ->   192.168.255.255  */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_UNREGISTERED_ONLY
value|0x10
end_define

begin_comment
comment|/* If PKT_ALIAS_RESET_ON_ADDR_CHANGE is set, then the table of dynamic 	aliasing links will be reset whenever PacketAliasSetAddress()         changes the default aliasing address.  If the default aliasing         address is left unchanged by this functions call, then the         table of dynamic aliasing links will be left intact.  This         bit is set after a call to PacketAliasInit(). */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_RESET_ON_ADDR_CHANGE
value|0x20
end_define

begin_comment
comment|/* If PKT_ALIAS_PUNCH_FW is set, active FTP and IRC DCC connections    will create a 'hole' in the firewall to allow the transfers to    work.  Where (IPFW "line-numbers") the hole is created is    controlled by PacketAliasSetFWBase(base, size). The hole will be    attached to that particular alias_link, so when the link goes away    so do the hole.  */
end_comment

begin_define
define|#
directive|define
name|PKT_ALIAS_PUNCH_FW
value|0x40
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

begin_undef
undef|#
directive|undef
name|__libalias_version
end_undef

begin_define
define|#
directive|define
name|__libalias_version
value|"2.5"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*lint -restore */
end_comment

end_unit

