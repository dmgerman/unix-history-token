begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996  Peter Wemm<peter@FreeBSD.org>.  * All rights reserved.  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * Portions of this software were developed for the FreeBSD Project by  * ThinkSec AS and NAI Labs, the Security Research Division of Network  * Associates, Inc.  under DARPA/SPAWAR contract N66001-01-C-8035  * ("CBOSS"), as part of the DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, is permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_PARAM_H_
end_ifdef

begin_comment
comment|/* for pidfile.c */
end_comment

begin_struct
struct|struct
name|pidfh
block|{
name|int
name|pf_fd
decl_stmt|;
name|char
name|pf_path
index|[
name|MAXPATHLEN
operator|+
literal|1
index|]
decl_stmt|;
name|__dev_t
name|pf_dev
decl_stmt|;
name|ino_t
name|pf_ino
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
name|__BEGIN_DECLS
name|void
name|clean_environment
parameter_list|(
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|_white
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|_more_white
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_namespace_to_string
parameter_list|(
name|int
name|_attrnamespace
parameter_list|,
name|char
modifier|*
modifier|*
name|_string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|extattr_string_to_namespace
parameter_list|(
specifier|const
name|char
modifier|*
name|_string
parameter_list|,
name|int
modifier|*
name|_attrnamespace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flopen
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_flags
parameter_list|,
name|mode_t
name|_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|login
parameter_list|(
name|struct
name|utmp
modifier|*
name|_ut
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|login_tty
parameter_list|(
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|logout
parameter_list|(
specifier|const
name|char
modifier|*
name|_line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|logwtmp
parameter_list|(
specifier|const
name|char
modifier|*
name|_line
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|,
specifier|const
name|char
modifier|*
name|_host
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|trimdomain
parameter_list|(
name|char
modifier|*
name|_fullhost
parameter_list|,
name|int
name|_hostsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|openpty
parameter_list|(
name|int
modifier|*
name|_amaster
parameter_list|,
name|int
modifier|*
name|_aslave
parameter_list|,
name|char
modifier|*
name|_name
parameter_list|,
name|struct
name|termios
modifier|*
name|_termp
parameter_list|,
name|struct
name|winsize
modifier|*
name|_winp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|forkpty
parameter_list|(
name|int
modifier|*
name|_amaster
parameter_list|,
name|char
modifier|*
name|_name
parameter_list|,
name|struct
name|termios
modifier|*
name|_termp
parameter_list|,
name|struct
name|winsize
modifier|*
name|_winp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|humanize_number
parameter_list|(
name|char
modifier|*
name|_buf
parameter_list|,
name|size_t
name|_len
parameter_list|,
name|int64_t
name|_number
parameter_list|,
specifier|const
name|char
modifier|*
name|_suffix
parameter_list|,
name|int
name|_scale
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|uu_lockerr
parameter_list|(
name|int
name|_uu_lockresult
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uu_lock
parameter_list|(
specifier|const
name|char
modifier|*
name|_ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uu_unlock
parameter_list|(
specifier|const
name|char
modifier|*
name|_ttyname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uu_lock_txfr
parameter_list|(
specifier|const
name|char
modifier|*
name|_ttyname
parameter_list|,
name|pid_t
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_secure_path
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|uid_t
name|_uid
parameter_list|,
name|gid_t
name|_gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|properties
name|properties_read
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|properties_free
parameter_list|(
name|properties
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|property_find
parameter_list|(
name|properties
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|auth_getval
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|realhostname
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|size_t
name|hsize
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|realhostname_sa
parameter_list|(
name|char
modifier|*
name|host
parameter_list|,
name|size_t
name|hsize
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|int
name|addrlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kld_isloaded
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kld_load
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_H_
end_ifdef

begin_comment
comment|/* avoid adding new includes */
end_comment

begin_function_decl
name|char
modifier|*
name|fparseln
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
specifier|const
name|char
index|[
literal|3
index|]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_PWD_H_
end_ifdef

begin_function_decl
name|int
name|pw_copy
parameter_list|(
name|int
name|_ffd
parameter_list|,
name|int
name|_tfd
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
name|_pw
parameter_list|,
name|struct
name|passwd
modifier|*
name|_old_pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|pw_dup
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
name|_pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_edit
parameter_list|(
name|int
name|_notsetuid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_equal
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
name|_pw1
parameter_list|,
specifier|const
name|struct
name|passwd
modifier|*
name|_pw2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pw_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_init
parameter_list|(
specifier|const
name|char
modifier|*
name|_dir
parameter_list|,
specifier|const
name|char
modifier|*
name|_master
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pw_make
parameter_list|(
specifier|const
name|struct
name|passwd
modifier|*
name|_pw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_mkdb
parameter_list|(
specifier|const
name|char
modifier|*
name|_user
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|passwd
modifier|*
name|pw_scan
parameter_list|(
specifier|const
name|char
modifier|*
name|_line
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|pw_tempname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pw_tmp
parameter_list|(
name|int
name|_mfd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_SYS_PARAM_H_
end_ifdef

begin_function_decl
name|struct
name|pidfh
modifier|*
name|pidfile_open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|mode_t
name|mode
parameter_list|,
name|pid_t
modifier|*
name|pidptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pidfile_write
parameter_list|(
name|struct
name|pidfh
modifier|*
name|pfh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pidfile_close
parameter_list|(
name|struct
name|pidfh
modifier|*
name|pfh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pidfile_remove
parameter_list|(
name|struct
name|pidfh
modifier|*
name|pfh
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* pw_scan() */
end_comment

begin_define
define|#
directive|define
name|PWSCAN_MASTER
value|0x01
end_define

begin_define
define|#
directive|define
name|PWSCAN_WARN
value|0x02
end_define

begin_comment
comment|/* humanize_number(3) */
end_comment

begin_define
define|#
directive|define
name|HN_DECIMAL
value|0x01
end_define

begin_define
define|#
directive|define
name|HN_NOSPACE
value|0x02
end_define

begin_define
define|#
directive|define
name|HN_B
value|0x04
end_define

begin_define
define|#
directive|define
name|HN_DIVISOR_1000
value|0x08
end_define

begin_define
define|#
directive|define
name|HN_GETSCALE
value|0x10
end_define

begin_define
define|#
directive|define
name|HN_AUTOSCALE
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBUTIL_H_ */
end_comment

end_unit

