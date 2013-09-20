begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stuff that should go into include/linux/socket.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SDP_SOCKET_H
end_ifndef

begin_define
define|#
directive|define
name|SDP_SOCKET_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET_SDP
end_ifndef

begin_define
define|#
directive|define
name|AF_INET_SDP
value|27
end_define

begin_define
define|#
directive|define
name|PF_INET_SDP
value|AF_INET_SDP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SDP_ZCOPY_THRESH
end_ifndef

begin_define
define|#
directive|define
name|SDP_ZCOPY_THRESH
value|80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SDP_LAST_BIND_ERR
end_ifndef

begin_define
define|#
directive|define
name|SDP_LAST_BIND_ERR
value|81
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TODO: AF_INET6_SDP ? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

