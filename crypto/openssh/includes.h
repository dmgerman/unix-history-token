begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   * includes.h  *   * Author: Tatu Ylonen<ylo@cs.hut.fi>  *   * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *   * Created: Thu Mar 23 16:29:37 1995 ylo  *   * This file includes most of the needed system headers.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDES_H
end_ifndef

begin_define
define|#
directive|define
name|INCLUDES_H
end_define

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|msg
parameter_list|)
define|\
value|static
comment|/**/
value|const char *const rcsid[] = { (char *)rcsid, "\100(#)" msg }
end_define

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

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/wait.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/un.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_include
include|#
directive|include
file|<grp.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_comment
comment|/* Define this to be the path of the xauth program. */
end_comment

begin_define
define|#
directive|define
name|XAUTH_PATH
value|"/usr/X11R6/bin/xauth"
end_define

begin_comment
comment|/*  * Define this to use pipes instead of socketpairs for communicating with the  * client program.  Socketpairs do not seem to work on all systems.  * Although pipes are bi-directional in FreeBSD, using pipes here will  * make<stdin> uni-directional !  */
end_comment

begin_comment
comment|/* #define USE_PIPES 1 */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
name|__FreeBSD__
operator|<=
literal|3
end_if

begin_comment
comment|/*  * Data types.  */
end_comment

begin_typedef
typedef|typedef
name|u_char
name|sa_family_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|socklen_t
typedef|;
end_typedef

begin_comment
comment|/*  * bsd-api-new-02a: protocol-independent placeholder for socket addresses  */
end_comment

begin_define
define|#
directive|define
name|_SS_MAXSIZE
value|128
end_define

begin_define
define|#
directive|define
name|_SS_ALIGNSIZE
value|(sizeof(int64_t))
end_define

begin_define
define|#
directive|define
name|_SS_PAD1SIZE
value|(_SS_ALIGNSIZE - sizeof(u_char) * 2)
end_define

begin_define
define|#
directive|define
name|_SS_PAD2SIZE
value|(_SS_MAXSIZE - sizeof(u_char) * 2 - \ 				_SS_PAD1SIZE - _SS_ALIGNSIZE)
end_define

begin_struct
struct|struct
name|sockaddr_storage
block|{
name|u_char
name|ss_len
decl_stmt|;
comment|/* address length */
name|sa_family_t
name|ss_family
decl_stmt|;
comment|/* address family */
name|char
name|__ss_pad1
index|[
name|_SS_PAD1SIZE
index|]
decl_stmt|;
name|int64_t
name|__ss_align
decl_stmt|;
comment|/* force desired structure storage alignment */
name|char
name|__ss_pad2
index|[
name|_SS_PAD2SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INCLUDES_H */
end_comment

end_unit

