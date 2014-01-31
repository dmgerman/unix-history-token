begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: misc.h,v 1.50 2013/10/14 23:28:23 djm Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_MISC_H
end_define

begin_comment
comment|/* misc.c */
end_comment

begin_function_decl
name|char
modifier|*
name|chop
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strdelim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|set_nonblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unset_nonblock
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_nodelay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a2port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|a2tun
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|put_host_port
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|hpdelim
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|cleanhostname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|colon
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|convtime
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|tilde_expand_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|uid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|percent_expand
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__sentinel__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|tohex
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sanitise_stdfd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ms_subtract_diff
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ms_to_timeval
parameter_list|(
name|struct
name|timeval
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|time_t
name|monotime
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lowercase
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sock_set_v6only
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sock_get_rcvbuf
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|pwcopy
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ssh_gai_strerror
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|arglist
name|arglist
typedef|;
end_typedef

begin_struct
struct|struct
name|arglist
block|{
name|char
modifier|*
modifier|*
name|list
decl_stmt|;
name|u_int
name|num
decl_stmt|;
name|u_int
name|nalloc
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|addargs
parameter_list|(
name|arglist
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|replacearg
parameter_list|(
name|arglist
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|freeargs
parameter_list|(
name|arglist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tun_open
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Common definitions for ssh tunnel device forwarding */
end_comment

begin_define
define|#
directive|define
name|SSH_TUNMODE_NO
value|0x00
end_define

begin_define
define|#
directive|define
name|SSH_TUNMODE_POINTOPOINT
value|0x01
end_define

begin_define
define|#
directive|define
name|SSH_TUNMODE_ETHERNET
value|0x02
end_define

begin_define
define|#
directive|define
name|SSH_TUNMODE_DEFAULT
value|SSH_TUNMODE_POINTOPOINT
end_define

begin_define
define|#
directive|define
name|SSH_TUNMODE_YES
value|(SSH_TUNMODE_POINTOPOINT|SSH_TUNMODE_ETHERNET)
end_define

begin_define
define|#
directive|define
name|SSH_TUNID_ANY
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|SSH_TUNID_ERR
value|(SSH_TUNID_ANY - 1)
end_define

begin_define
define|#
directive|define
name|SSH_TUNID_MAX
value|(SSH_TUNID_ANY - 2)
end_define

begin_comment
comment|/* Functions to extract or store big-endian words of various sizes */
end_comment

begin_function_decl
name|u_int64_t
name|get_u64
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|8
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|u_int32_t
name|get_u32
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|u_int16_t
name|get_u16
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|put_u64
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|8
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|put_u32
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|put_u16
parameter_list|(
name|void
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|bwlimit
block|{
name|size_t
name|buflen
decl_stmt|;
name|u_int64_t
name|rate
decl_stmt|,
name|thresh
decl_stmt|,
name|lamt
decl_stmt|;
name|struct
name|timeval
name|bwstart
decl_stmt|,
name|bwend
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|bandwidth_limit_init
parameter_list|(
name|struct
name|bwlimit
modifier|*
parameter_list|,
name|u_int64_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bandwidth_limit
parameter_list|(
name|struct
name|bwlimit
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|parse_ipqos
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|iptos2str
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mktemp_proto
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* readpass.c */
end_comment

begin_define
define|#
directive|define
name|RP_ECHO
value|0x0001
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_STDIN
value|0x0002
end_define

begin_define
define|#
directive|define
name|RP_ALLOW_EOF
value|0x0004
end_define

begin_define
define|#
directive|define
name|RP_USE_ASKPASS
value|0x0008
end_define

begin_function_decl
name|char
modifier|*
name|read_passphrase
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ask_permission
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|read_keyfile_line
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MISC_H */
end_comment

end_unit

