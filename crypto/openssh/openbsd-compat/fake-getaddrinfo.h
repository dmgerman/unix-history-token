begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: fake-getaddrinfo.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FAKE_GETADDRINFO_H
end_ifndef

begin_define
define|#
directive|define
name|_FAKE_GETADDRINFO_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"fake-gai-errnos.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|AI_PASSIVE
end_ifndef

begin_define
define|#
directive|define
name|AI_PASSIVE
value|1
end_define

begin_define
define|#
directive|define
name|AI_CANONNAME
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NI_NUMERICHOST
end_ifndef

begin_define
define|#
directive|define
name|NI_NUMERICHOST
value|2
end_define

begin_define
define|#
directive|define
name|NI_NAMEREQD
value|4
end_define

begin_define
define|#
directive|define
name|NI_NUMERICSERV
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_ADDRINFO
end_ifndef

begin_struct
struct|struct
name|addrinfo
block|{
name|int
name|ai_flags
decl_stmt|;
comment|/* AI_PASSIVE, AI_CANONNAME */
name|int
name|ai_family
decl_stmt|;
comment|/* PF_xxx */
name|int
name|ai_socktype
decl_stmt|;
comment|/* SOCK_xxx */
name|int
name|ai_protocol
decl_stmt|;
comment|/* 0 or IPPROTO_xxx for IPv4 and IPv6 */
name|size_t
name|ai_addrlen
decl_stmt|;
comment|/* length of ai_addr */
name|char
modifier|*
name|ai_canonname
decl_stmt|;
comment|/* canonical name for hostname */
name|struct
name|sockaddr
modifier|*
name|ai_addr
decl_stmt|;
comment|/* binary address */
name|struct
name|addrinfo
modifier|*
name|ai_next
decl_stmt|;
comment|/* next structure in linked list */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRUCT_ADDRINFO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETADDRINFO
end_ifndef

begin_function_decl
name|int
name|getaddrinfo
parameter_list|(
specifier|const
name|char
modifier|*
name|hostname
parameter_list|,
specifier|const
name|char
modifier|*
name|servname
parameter_list|,
specifier|const
name|struct
name|addrinfo
modifier|*
name|hints
parameter_list|,
name|struct
name|addrinfo
modifier|*
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GETADDRINFO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GAI_STRERROR
end_ifndef

begin_function_decl
name|char
modifier|*
name|gai_strerror
parameter_list|(
name|int
name|ecode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GAI_STRERROR */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FREEADDRINFO
end_ifndef

begin_function_decl
name|void
name|freeaddrinfo
parameter_list|(
name|struct
name|addrinfo
modifier|*
name|ai
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_FREEADDRINFO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FAKE_GETADDRINFO_H */
end_comment

end_unit

