begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: fake-socket.h,v 1.3 2002/04/12 03:35:40 tim Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FAKE_SOCKET_H
end_ifndef

begin_define
define|#
directive|define
name|_FAKE_SOCKET_H
end_define

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|"sys/types.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_SOCKADDR_STORAGE
end_ifndef

begin_define
define|#
directive|define
name|_SS_MAXSIZE
value|128
end_define

begin_comment
comment|/* Implementation specific max size */
end_comment

begin_define
define|#
directive|define
name|_SS_PADSIZE
value|(_SS_MAXSIZE - sizeof (struct sockaddr))
end_define

begin_struct
struct|struct
name|sockaddr_storage
block|{
name|struct
name|sockaddr
name|ss_sa
decl_stmt|;
name|char
name|__ss_pad2
index|[
name|_SS_PADSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ss_family
value|ss_sa.sa_family
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_SOCKADDR_STORAGE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN6_IS_ADDR_LOOPBACK
end_ifndef

begin_define
define|#
directive|define
name|IN6_IS_ADDR_LOOPBACK
parameter_list|(
name|a
parameter_list|)
define|\
value|(((u_int32_t *) (a))[0] == 0&& ((u_int32_t *) (a))[1] == 0&& \ 	 ((u_int32_t *) (a))[2] == 0&& ((u_int32_t *) (a))[3] == htonl (1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IN6_IS_ADDR_LOOPBACK */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_IN6_ADDR
end_ifndef

begin_struct
struct|struct
name|in6_addr
block|{
name|u_int8_t
name|s6_addr
index|[
literal|16
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
comment|/* !HAVE_STRUCT_IN6_ADDR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_SOCKADDR_IN6
end_ifndef

begin_struct
struct|struct
name|sockaddr_in6
block|{
name|unsigned
name|short
name|sin6_family
decl_stmt|;
name|u_int16_t
name|sin6_port
decl_stmt|;
name|u_int32_t
name|sin6_flowinfo
decl_stmt|;
name|struct
name|in6_addr
name|sin6_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_SOCKADDR_IN6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AF_INET6
end_ifndef

begin_comment
comment|/* Define it to something that should never appear */
end_comment

begin_define
define|#
directive|define
name|AF_INET6
value|AF_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FAKE_SOCKET_H */
end_comment

end_unit

