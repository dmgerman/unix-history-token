begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * fake library for ssh  *  * This file is included in getaddrinfo.c and getnameinfo.c.  * See getaddrinfo.c and getnameinfo.c.  */
end_comment

begin_comment
comment|/* $Id: fake-gai-errnos.h,v 1.2 2001/02/09 01:55:36 djm Exp $ */
end_comment

begin_comment
comment|/* for old netdb.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EAI_NODATA
end_ifndef

begin_define
define|#
directive|define
name|EAI_NODATA
value|1
end_define

begin_define
define|#
directive|define
name|EAI_MEMORY
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

