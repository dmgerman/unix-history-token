begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* krb5-types.h -- this file was generated for i386-unknown-freebsd5.0 by                    $Id: bits.c,v 1.22 2002/08/28 16:08:44 joda Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__krb5_types_h__
end_ifndef

begin_define
define|#
directive|define
name|__krb5_types_h__
end_define

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_typedef
typedef|typedef
name|socklen_t
name|krb5_socklen_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_typedef
typedef|typedef
name|ssize_t
name|krb5_ssize_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __krb5_types_h__ */
end_comment

end_unit

