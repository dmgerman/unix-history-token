begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: Xdmcp.h,v 1.8 91/07/23 22:28:07 keith Exp $ */
end_comment

begin_comment
comment|/*  * Copyright 1989 Network Computing Devices, Inc., Mountain View, California.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of N.C.D. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  N.C.D. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XDMCP_H_
end_ifndef

begin_define
define|#
directive|define
name|_XDMCP_H_
end_define

begin_define
define|#
directive|define
name|XDM_PROTOCOL_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|XDM_UDP_PORT
value|177
end_define

begin_define
define|#
directive|define
name|XDM_MAX_MSGLEN
value|8192
end_define

begin_define
define|#
directive|define
name|XDM_MIN_RTX
value|2
end_define

begin_define
define|#
directive|define
name|XDM_MAX_RTX
value|32
end_define

begin_define
define|#
directive|define
name|XDM_RTX_LIMIT
value|7
end_define

begin_define
define|#
directive|define
name|XDM_KA_RTX_LIMIT
value|4
end_define

begin_define
define|#
directive|define
name|XDM_DEF_DORMANCY
value|(3 * 60)
end_define

begin_comment
comment|/* 3 minutes */
end_comment

begin_define
define|#
directive|define
name|XDM_MAX_DORMANCY
value|(24 * 60 * 60)
end_define

begin_comment
comment|/* 24 hours */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BROADCAST_QUERY
init|=
literal|1
block|,
name|QUERY
block|,
name|INDIRECT_QUERY
block|,
name|FORWARD_QUERY
block|,
name|WILLING
block|,
name|UNWILLING
block|,
name|REQUEST
block|,
name|ACCEPT
block|,
name|DECLINE
block|,
name|MANAGE
block|,
name|REFUSE
block|,
name|FAILED
block|,
name|KEEPALIVE
block|,
name|ALIVE
block|}
name|xdmOpCode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|XDM_QUERY
block|,
name|XDM_BROADCAST
block|,
name|XDM_INDIRECT
block|,
name|XDM_COLLECT_QUERY
block|,
name|XDM_COLLECT_BROADCAST_QUERY
block|,
name|XDM_COLLECT_INDIRECT_QUERY
block|,
name|XDM_START_CONNECTION
block|,
name|XDM_AWAIT_REQUEST_RESPONSE
block|,
name|XDM_AWAIT_MANAGE_RESPONSE
block|,
name|XDM_MANAGE
block|,
name|XDM_RUN_SESSION
block|,
name|XDM_OFF
block|,
name|XDM_AWAIT_USER_INPUT
block|,
name|XDM_KEEPALIVE
block|,
name|XDM_AWAIT_ALIVE_RESPONSE
block|}
name|xdmcp_states
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|NOTDEF
end_ifdef

begin_comment
comment|/* table of hosts */
end_comment

begin_define
define|#
directive|define
name|XDM_MAX_STR_LEN
value|21
end_define

begin_define
define|#
directive|define
name|XDM_MAX_HOSTS
value|20
end_define

begin_struct
struct|struct
name|xdm_host_table
block|{
name|struct
name|sockaddr_in
name|sockaddr
decl_stmt|;
name|char
name|name
index|[
name|XDM_MAX_STR_LEN
index|]
decl_stmt|;
name|char
name|status
index|[
name|XDM_MAX_STR_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTDEF */
end_comment

begin_typedef
typedef|typedef
name|CARD8
modifier|*
name|CARD8Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD16
modifier|*
name|CARD16Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CARD32
modifier|*
name|CARD32Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ARRAY8
block|{
name|CARD16
name|length
decl_stmt|;
name|CARD8Ptr
name|data
decl_stmt|;
block|}
name|ARRAY8
operator|,
typedef|*
name|ARRAY8Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ARRAY16
block|{
name|CARD8
name|length
decl_stmt|;
name|CARD16Ptr
name|data
decl_stmt|;
block|}
name|ARRAY16
operator|,
typedef|*
name|ARRAY16Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ARRAY32
block|{
name|CARD8
name|length
decl_stmt|;
name|CARD32Ptr
name|data
decl_stmt|;
block|}
name|ARRAY32
operator|,
typedef|*
name|ARRAY32Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ARRAYofARRAY8
block|{
name|CARD8
name|length
decl_stmt|;
name|ARRAY8Ptr
name|data
decl_stmt|;
block|}
name|ARRAYofARRAY8
operator|,
typedef|*
name|ARRAYofARRAY8Ptr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XdmcpHeader
block|{
name|CARD16
name|version
decl_stmt|,
name|opcode
decl_stmt|,
name|length
decl_stmt|;
block|}
name|XdmcpHeader
operator|,
typedef|*
name|XdmcpHeaderPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XdmcpBuffer
block|{
name|BYTE
modifier|*
name|data
decl_stmt|;
name|int
name|size
decl_stmt|;
comment|/* size of buffer pointed by to data */
name|int
name|pointer
decl_stmt|;
comment|/* current index into data */
name|int
name|count
decl_stmt|;
comment|/* bytes read from network into data */
block|}
name|XdmcpBuffer
operator|,
typedef|*
name|XdmcpBufferPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_XdmAuthKey
block|{
name|BYTE
name|data
index|[
literal|8
index|]
decl_stmt|;
block|}
name|XdmAuthKeyRec
operator|,
typedef|*
name|XdmAuthKeyPtr
typedef|;
end_typedef

begin_comment
comment|/* implementation-independent network address structure.    Equiv to sockaddr* for sockets and netbuf* for STREAMS. */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|XdmcpNetaddr
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|XdmcpWriteCARD8
argument_list|()
decl_stmt|,
name|XdmcpWriteCARD16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|XdmcpWriteCARD32
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|XdmcpWriteARRAY8
argument_list|()
decl_stmt|,
name|XdmcpWriteARRAY16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XdmcpWriteARRAY32
argument_list|()
decl_stmt|,
name|XdmcpWriteARRAYofARRAY8
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XdmcpWriteHeader
argument_list|()
decl_stmt|,
name|XdmcpFlush
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XdmcpReadCARD8
argument_list|()
decl_stmt|,
name|XdmcpReadCARD16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|XdmcpReadCARD32
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|XdmcpReadARRAY8
argument_list|()
decl_stmt|,
name|XdmcpReadARRAY16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XdmcpReadARRAY32
argument_list|()
decl_stmt|,
name|XdmcpReadARRAYofARRAY8
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XdmcpReadHeader
argument_list|()
decl_stmt|,
name|XdmcpFill
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|XdmcpReadRemaining
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|XdmcpDisposeARRAY8
argument_list|()
decl_stmt|,
name|XdmcpDisposeARRAY16
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|XdmcpDisposeARRAY32
argument_list|()
decl_stmt|,
name|XdmcpDisposeARRAYofARRAY8
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|XdmcpCopyARRAY8
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|XdmcpARRAY8Equal
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HASXDMAUTH
end_ifdef

begin_function_decl
specifier|extern
name|void
name|XdmcpGenerateKey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XdmcpIncrementKey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XdmcpDecrementKey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XdmcpWrap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|XdmcpUnwrap
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|Xalloc
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|xalloc
end_ifndef

begin_decl_stmt
specifier|extern
name|long
modifier|*
name|Xalloc
argument_list|()
decl_stmt|,
modifier|*
name|Xrealloc
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|Xfree
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XDMCP_H_ */
end_comment

end_unit

