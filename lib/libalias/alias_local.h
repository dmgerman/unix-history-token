begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* -*- mode: c; tab-width: 3; c-basic-offset: 3; -*-     Alias_local.h contains the function prototypes for alias.c,     alias_db.c, alias_util.c and alias_ftp.c, alias_irc.c (as well     as any future add-ons).  It is intended to be used only within     the aliasing software.  Outside world interfaces are defined     in alias.h      This software is placed into the public domain with no restrictions     on its distribution.      Initial version:  August, 1996  (cjm)<updated several times by original author and Eivind Eiklund> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIAS_LOCAL_H
end_ifndef

begin_define
define|#
directive|define
name|ALIAS_LOCAL_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|packetAliasMode
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|alias_link
struct_decl|;
end_struct_decl

begin_comment
comment|/* General utilities */
end_comment

begin_function_decl
name|u_short
name|IpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|TcpChecksum
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|DifferentialChecksum
parameter_list|(
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Internal data access */
end_comment

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpIn
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindIcmpOut
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn1
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentIn2
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|AddFragmentPtrLink
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindFragmentPtr
parameter_list|(
name|struct
name|in_addr
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|alias_link
modifier|*
name|FindUdpTcpIn
parameter_list|(
name|struct
name|in_addr
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
name|struct
name|alias_link
modifier|*
name|FindUdpTcpOut
parameter_list|(
name|struct
name|in_addr
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
name|struct
name|in_addr
name|FindOriginalAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|FindAliasAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* External data access/modification */
end_comment

begin_function_decl
name|void
name|GetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentAddr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|GetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetFragmentPtr
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateIn
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetStateOut
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetOriginalAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDestAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetAliasAddress
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|in_addr
name|GetDefaultAliasAddress
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetDefaultAliasAddress
parameter_list|(
name|struct
name|in_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetOriginalPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_short
name|GetAliasPort
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetAckModified
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaAckIn
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|GetDeltaSeqOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AddSeq
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SetExpire
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ClearCheckNewLink
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PunchFWHole
parameter_list|(
name|struct
name|alias_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Housekeeping function */
end_comment

begin_function_decl
name|void
name|HouseKeeping
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Tcp specfic routines */
end_comment

begin_comment
comment|/*lint -save -library Suppress flexelint warnings */
end_comment

begin_function_decl
name|void
name|AliasHandleFtpOut
parameter_list|(
name|struct
name|ip
modifier|*
parameter_list|,
name|struct
name|alias_link
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|AliasHandleIrcOut
parameter_list|(
name|struct
name|ip
modifier|*
name|pip
parameter_list|,
name|struct
name|alias_link
modifier|*
name|link
parameter_list|,
name|int
name|maxsize
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|alias_tcp_state
block|{
name|ALIAS_TCP_STATE_NOT_CONNECTED
block|,
name|ALIAS_TCP_STATE_CONNECTED
block|,
name|ALIAS_TCP_STATE_DISCONNECTED
block|}
enum|;
end_enum

begin_comment
comment|/*lint -restore */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(ALIAS_LOCAL_H) */
end_comment

end_unit

