begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: fake-getnameinfo.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FAKE_GETNAMEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|_FAKE_GETNAMEINFO_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_GETNAMEINFO
end_ifndef

begin_function_decl
name|int
name|getnameinfo
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|,
name|size_t
name|salen
parameter_list|,
name|char
modifier|*
name|host
parameter_list|,
name|size_t
name|hostlen
parameter_list|,
name|char
modifier|*
name|serv
parameter_list|,
name|size_t
name|servlen
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_GETNAMEINFO */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_MAXSERV
end_ifndef

begin_define
define|#
directive|define
name|NI_MAXSERV
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NI_MAXSERV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NI_MAXHOST
end_ifndef

begin_define
define|#
directive|define
name|NI_MAXHOST
value|1025
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NI_MAXHOST */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FAKE_GETNAMEINFO_H */
end_comment

end_unit

