begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  Peter Wemm<peter@FreeBSD.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBUTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBUTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_define
define|#
directive|define
name|PROPERTY_MAX_NAME
value|64
end_define

begin_define
define|#
directive|define
name|PROPERTY_MAX_VALUE
value|512
end_define

begin_comment
comment|/* for properties.c */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_property
block|{
name|struct
name|_property
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
block|}
typedef|*
name|properties
typedef|;
end_typedef

begin_comment
comment|/* Avoid pulling in all the include files for no need */
end_comment

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|winsize
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|utmp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|__BEGIN_DECLS
name|void
name|login
name|__P
argument_list|(
operator|(
expr|struct
name|utmp
operator|*
name|_ut
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|login_tty
name|__P
argument_list|(
operator|(
name|int
name|_fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|logout
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_line
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|logwtmp
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_line
operator|,
specifier|const
name|char
operator|*
name|_name
operator|,
specifier|const
name|char
operator|*
name|_host
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|trimdomain
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_fullhost
operator|,
name|int
name|_hostsize
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|openpty
name|__P
argument_list|(
operator|(
name|int
operator|*
name|_amaster
operator|,
name|int
operator|*
name|_aslave
operator|,
name|char
operator|*
name|_name
operator|,
expr|struct
name|termios
operator|*
name|_termp
operator|,
expr|struct
name|winsize
operator|*
name|_winp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|forkpty
name|__P
argument_list|(
operator|(
name|int
operator|*
name|_amaster
operator|,
name|char
operator|*
name|_name
operator|,
expr|struct
name|termios
operator|*
name|_termp
operator|,
expr|struct
name|winsize
operator|*
name|_winp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
name|uu_lockerr
name|__P
argument_list|(
operator|(
name|int
name|_uu_lockresult
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_lock
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_unlock
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_ttyname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uu_lock_txfr
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_ttyname
operator|,
name|pid_t
name|_pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_secure_path
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_path
operator|,
name|uid_t
name|_uid
operator|,
name|gid_t
name|_gid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|properties
name|properties_read
name|__P
argument_list|(
operator|(
name|int
name|fd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|properties_free
name|__P
argument_list|(
operator|(
name|properties
name|list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|property_find
name|__P
argument_list|(
operator|(
name|properties
name|list
operator|,
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|auth_getval
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|realhostname
name|__P
argument_list|(
operator|(
name|char
operator|*
name|host
operator|,
name|size_t
name|hsize
operator|,
specifier|const
expr|struct
name|in_addr
operator|*
name|ip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|realhostname_sa
name|__P
argument_list|(
operator|(
name|char
operator|*
name|host
operator|,
name|size_t
name|hsize
operator|,
expr|struct
name|sockaddr
operator|*
name|addr
operator|,
name|int
name|addrlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_H_
end_ifdef

begin_comment
comment|/* avoid adding new includes */
end_comment

begin_decl_stmt
name|char
modifier|*
name|fparseln
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|*
operator|,
specifier|const
name|char
index|[
literal|3
index|]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|UU_LOCK_INUSE
value|(1)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OK
value|(0)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OPEN_ERR
value|(-1)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_READ_ERR
value|(-2)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_CREAT_ERR
value|(-3)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_WRITE_ERR
value|(-4)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_LINK_ERR
value|(-5)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_TRY_ERR
value|(-6)
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OWNER_ERR
value|(-7)
end_define

begin_comment
comment|/* return values from realhostname() */
end_comment

begin_define
define|#
directive|define
name|HOSTNAME_FOUND
value|(0)
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INCORRECTNAME
value|(1)
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INVALIDADDR
value|(2)
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INVALIDNAME
value|(3)
end_define

begin_comment
comment|/* fparseln(3) */
end_comment

begin_define
define|#
directive|define
name|FPARSELN_UNESCESC
value|0x01
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCONT
value|0x02
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCCOMM
value|0x04
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCREST
value|0x08
end_define

begin_define
define|#
directive|define
name|FPARSELN_UNESCALL
value|0x0f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBUTIL_H_ */
end_comment

end_unit

