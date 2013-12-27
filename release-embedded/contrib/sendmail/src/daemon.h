begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: daemon.h,v 8.3 2006/07/13 22:57:03 ca Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DAEMON_H
end_ifndef

begin_define
define|#
directive|define
name|DAEMON_H
value|1
end_define

begin_if
if|#
directive|if
name|DAEMON_C
end_if

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* structure to describe a daemon or a client */
end_comment

begin_struct
struct|struct
name|daemon
block|{
name|int
name|d_socket
decl_stmt|;
comment|/* fd for socket */
name|SOCKADDR
name|d_addr
decl_stmt|;
comment|/* socket for incoming */
name|unsigned
name|short
name|d_port
decl_stmt|;
comment|/* port number */
name|int
name|d_listenqueue
decl_stmt|;
comment|/* size of listen queue */
name|int
name|d_tcprcvbufsize
decl_stmt|;
comment|/* size of TCP receive buffer */
name|int
name|d_tcpsndbufsize
decl_stmt|;
comment|/* size of TCP send buffer */
name|time_t
name|d_refuse_connections_until
decl_stmt|;
name|bool
name|d_firsttime
decl_stmt|;
name|int
name|d_socksize
decl_stmt|;
name|BITMAP256
name|d_flags
decl_stmt|;
comment|/* flags; see sendmail.h */
name|char
modifier|*
name|d_mflags
decl_stmt|;
comment|/* flags for use in macro */
name|char
modifier|*
name|d_name
decl_stmt|;
comment|/* user-supplied name */
name|int
name|d_dm
decl_stmt|;
comment|/* DeliveryMode */
name|int
name|d_refuseLA
decl_stmt|;
name|int
name|d_queueLA
decl_stmt|;
name|int
name|d_delayLA
decl_stmt|;
name|int
name|d_maxchildren
decl_stmt|;
if|#
directive|if
name|MILTER
name|char
modifier|*
name|d_inputfilterlist
decl_stmt|;
name|struct
name|milter
modifier|*
name|d_inputfilters
index|[
name|MAXFILTERS
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* MILTER */
if|#
directive|if
name|_FFR_SS_PER_DAEMON
name|int
name|d_supersafe
decl_stmt|;
endif|#
directive|endif
comment|/* _FFR_SS_PER_DAEMON */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|daemon
name|DAEMON_T
typedef|;
end_typedef

begin_decl_stmt
name|EXTERN
name|DAEMON_T
name|Daemons
index|[
name|MAXDAEMONS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DPO_NOTSET
value|(-1)
end_define

begin_comment
comment|/* daemon option (int) not set */
end_comment

begin_comment
comment|/* see also sendmail.h: SuperSafe values */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|refuseconnections
name|__P
argument_list|(
operator|(
name|ENVELOPE
operator|*
operator|,
name|int
operator|,
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|EXTERN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! DAEMON_H */
end_comment

end_unit

