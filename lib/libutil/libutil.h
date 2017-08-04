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

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<sys/_stdint.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_GID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__gid_t
name|gid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_GID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_MODE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__mode_t
name|mode_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_MODE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_PID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__pid_t
name|pid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_PID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UID_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uid_t
name|uid_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UID_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* For properties.c. */
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
comment|/* Avoid pulling in all the include files for no need. */
end_comment

begin_struct_decl
struct_decl|struct
name|in_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pidfh
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sockaddr
struct_decl|;
end_struct_decl

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

begin_function_decl
name|__BEGIN_DECLS
name|char
modifier|*
name|auth_getval
parameter_list|(
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
name|expand_number
parameter_list|(
specifier|const
name|char
modifier|*
name|_buf
parameter_list|,
name|uint64_t
modifier|*
name|_num
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
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flopenat
parameter_list|(
name|int
name|_dirfd
parameter_list|,
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|int
name|_flags
parameter_list|,
modifier|...
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
name|void
name|hexdump
parameter_list|(
specifier|const
name|void
modifier|*
name|_ptr
parameter_list|,
name|int
name|_length
parameter_list|,
specifier|const
name|char
modifier|*
name|_hdr
parameter_list|,
name|int
name|_flags
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
name|struct
name|kinfo_file
modifier|*
name|kinfo_getfile
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|int
modifier|*
name|_cntp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kinfo_vmentry
modifier|*
name|kinfo_getvmmap
parameter_list|(
name|pid_t
name|_pid
parameter_list|,
name|int
modifier|*
name|_cntp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kinfo_vmobject
modifier|*
name|kinfo_getvmobject
parameter_list|(
name|int
modifier|*
name|_cntp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kinfo_proc
modifier|*
name|kinfo_getallproc
parameter_list|(
name|int
modifier|*
name|_cntp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kinfo_proc
modifier|*
name|kinfo_getproc
parameter_list|(
name|pid_t
name|_pid
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
name|_name
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
name|_name
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
name|pidfile_close
parameter_list|(
name|struct
name|pidfh
modifier|*
name|_pfh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pidfile_fileno
parameter_list|(
specifier|const
name|struct
name|pidfh
modifier|*
name|_pfh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|pidfh
modifier|*
name|pidfile_open
parameter_list|(
specifier|const
name|char
modifier|*
name|_path
parameter_list|,
name|mode_t
name|_mode
parameter_list|,
name|pid_t
modifier|*
name|_pidptr
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
name|_pfh
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
name|_pfh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|properties_free
parameter_list|(
name|properties
name|_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|property_find
parameter_list|(
name|properties
name|_list
parameter_list|,
specifier|const
name|char
modifier|*
name|_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|properties
name|properties_read
parameter_list|(
name|int
name|_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|realhostname
parameter_list|(
name|char
modifier|*
name|_host
parameter_list|,
name|size_t
name|_hsize
parameter_list|,
specifier|const
name|struct
name|in_addr
modifier|*
name|_ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|realhostname_sa
parameter_list|(
name|char
modifier|*
name|_host
parameter_list|,
name|size_t
name|_hsize
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|_addr
parameter_list|,
name|int
name|_addrlen
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

begin_comment
comment|/*  * Conditionally prototype the following functions if the include  * files upon which they depend have been included.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_STDIO_H_
end_ifdef

begin_function_decl
name|char
modifier|*
name|fparseln
parameter_list|(
name|FILE
modifier|*
name|_fp
parameter_list|,
name|size_t
modifier|*
name|_len
parameter_list|,
name|size_t
modifier|*
name|_lineno
parameter_list|,
specifier|const
name|char
name|_delim
index|[
literal|3
index|]
parameter_list|,
name|int
name|_flags
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
name|char
modifier|*
name|pw_make_v7
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
name|_GRP_H_
end_ifdef

begin_function_decl
name|int
name|gr_copy
parameter_list|(
name|int
name|__ffd
parameter_list|,
name|int
name|_tfd
parameter_list|,
specifier|const
name|struct
name|group
modifier|*
name|_gr
parameter_list|,
name|struct
name|group
modifier|*
name|_old_gr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|gr_dup
parameter_list|(
specifier|const
name|struct
name|group
modifier|*
name|_gr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|gr_add
parameter_list|(
specifier|const
name|struct
name|group
modifier|*
name|_gr
parameter_list|,
specifier|const
name|char
modifier|*
name|_newmember
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gr_equal
parameter_list|(
specifier|const
name|struct
name|group
modifier|*
name|_gr1
parameter_list|,
specifier|const
name|struct
name|group
modifier|*
name|_gr2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gr_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gr_init
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
name|int
name|gr_lock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|gr_make
parameter_list|(
specifier|const
name|struct
name|group
modifier|*
name|_gr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gr_mkdb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|group
modifier|*
name|gr_scan
parameter_list|(
specifier|const
name|char
modifier|*
name|_line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gr_tmp
parameter_list|(
name|int
name|_mdf
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
name|_UFS_UFS_QUOTA_H_
end_ifdef

begin_struct_decl
struct_decl|struct
name|fstab
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|quotafile
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|quota_check_path
parameter_list|(
specifier|const
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|,
specifier|const
name|char
modifier|*
name|_path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|quota_close
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_convert
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|,
name|int
name|_wordsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|quota_fsname
parameter_list|(
specifier|const
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_maxid
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_off
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_on
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|quotafile
modifier|*
name|quota_open
parameter_list|(
name|struct
name|fstab
modifier|*
name|_fs
parameter_list|,
name|int
name|_quotatype
parameter_list|,
name|int
name|_openflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|quota_qfname
parameter_list|(
specifier|const
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_read
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|,
name|struct
name|dqblk
modifier|*
name|_dqb
parameter_list|,
name|int
name|_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_write_limits
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|,
name|struct
name|dqblk
modifier|*
name|_dqb
parameter_list|,
name|int
name|_id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|quota_write_usage
parameter_list|(
name|struct
name|quotafile
modifier|*
name|_qf
parameter_list|,
name|struct
name|dqblk
modifier|*
name|_dqb
parameter_list|,
name|int
name|_id
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
comment|/* Flags for hexdump(3). */
end_comment

begin_define
define|#
directive|define
name|HD_COLUMN_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|HD_DELIM_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|HD_OMIT_COUNT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_HEX
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|HD_OMIT_CHARS
value|(1<< 18)
end_define

begin_comment
comment|/* Values for humanize_number(3)'s flags parameter. */
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
name|HN_IEC_PREFIXES
value|0x10
end_define

begin_comment
comment|/* Values for humanize_number(3)'s scale parameter. */
end_comment

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

begin_comment
comment|/* Return values from realhostname(). */
end_comment

begin_define
define|#
directive|define
name|HOSTNAME_FOUND
value|0
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INCORRECTNAME
value|1
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INVALIDADDR
value|2
end_define

begin_define
define|#
directive|define
name|HOSTNAME_INVALIDNAME
value|3
end_define

begin_comment
comment|/* Flags for pw_scan(). */
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
comment|/* Return values from uu_lock(). */
end_comment

begin_define
define|#
directive|define
name|UU_LOCK_INUSE
value|1
end_define

begin_define
define|#
directive|define
name|UU_LOCK_OK
value|0
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBUTIL_H_ */
end_comment

end_unit

