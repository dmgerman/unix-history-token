begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1997-1999 Erez Zadok  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgment:  *      This product includes software developed by the University of  *      California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      %W% (Berkeley) %G%  *  * $Id: amq_defs.h,v 1.3 1999/09/08 23:36:52 ezk Exp $  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMQ_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|_AMQ_DEFS_H
end_define

begin_comment
comment|/*  * MACROS  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMQ_SIZE
end_ifndef

begin_define
define|#
directive|define
name|AMQ_SIZE
value|16384
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not AMQ_SIZE */
end_comment

begin_define
define|#
directive|define
name|AMQ_STRLEN
value|2048
end_define

begin_define
define|#
directive|define
name|AMQ_PROGRAM
value|((u_long)300019)
end_define

begin_define
define|#
directive|define
name|AMQ_VERSION
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|AMQPROC_NULL
value|((u_long)0)
end_define

begin_define
define|#
directive|define
name|AMQPROC_MNTTREE
value|((u_long)1)
end_define

begin_define
define|#
directive|define
name|AMQPROC_UMNT
value|((u_long)2)
end_define

begin_define
define|#
directive|define
name|AMQPROC_STATS
value|((u_long)3)
end_define

begin_define
define|#
directive|define
name|AMQPROC_EXPORT
value|((u_long)4)
end_define

begin_define
define|#
directive|define
name|AMQPROC_SETOPT
value|((u_long)5)
end_define

begin_define
define|#
directive|define
name|AMQPROC_GETMNTFS
value|((u_long)6)
end_define

begin_define
define|#
directive|define
name|AMQPROC_MOUNT
value|((u_long)7)
end_define

begin_define
define|#
directive|define
name|AMQPROC_GETVERS
value|((u_long)8)
end_define

begin_define
define|#
directive|define
name|AMQPROC_GETPID
value|((u_long)9)
end_define

begin_comment
comment|/*  * TYPEDEFS  */
end_comment

begin_typedef
typedef|typedef
name|long
modifier|*
name|time_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|amq_mount_info
name|amq_mount_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|amq_mount_stats
name|amq_mount_stats
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|amq_mount_tree
name|amq_mount_tree
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|amq_setopt
name|amq_setopt
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|amq_mount_tree
modifier|*
name|amq_mount_tree_p
typedef|;
end_typedef

begin_comment
comment|/*  * STRUCTURES:  */
end_comment

begin_struct
struct|struct
name|amq_mount_tree
block|{
name|amq_string
name|mt_mountinfo
decl_stmt|;
name|amq_string
name|mt_directory
decl_stmt|;
name|amq_string
name|mt_mountpoint
decl_stmt|;
name|amq_string
name|mt_type
decl_stmt|;
name|time_type
name|mt_mounttime
decl_stmt|;
name|u_short
name|mt_mountuid
decl_stmt|;
name|int
name|mt_getattr
decl_stmt|;
name|int
name|mt_lookup
decl_stmt|;
name|int
name|mt_readdir
decl_stmt|;
name|int
name|mt_readlink
decl_stmt|;
name|int
name|mt_statfs
decl_stmt|;
name|struct
name|amq_mount_tree
modifier|*
name|mt_next
decl_stmt|;
name|struct
name|amq_mount_tree
modifier|*
name|mt_child
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|amq_mount_info
block|{
name|amq_string
name|mi_type
decl_stmt|;
name|amq_string
name|mi_mountpt
decl_stmt|;
name|amq_string
name|mi_mountinfo
decl_stmt|;
name|amq_string
name|mi_fserver
decl_stmt|;
name|int
name|mi_error
decl_stmt|;
name|int
name|mi_refc
decl_stmt|;
name|int
name|mi_up
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|amq_mount_info_list_len
decl_stmt|;
name|amq_mount_info
modifier|*
name|amq_mount_info_list_val
decl_stmt|;
block|}
name|amq_mount_info_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int
name|amq_mount_tree_list_len
decl_stmt|;
name|amq_mount_tree_p
modifier|*
name|amq_mount_tree_list_val
decl_stmt|;
block|}
name|amq_mount_tree_list
typedef|;
end_typedef

begin_struct
struct|struct
name|amq_mount_stats
block|{
name|int
name|as_drops
decl_stmt|;
name|int
name|as_stale
decl_stmt|;
name|int
name|as_mok
decl_stmt|;
name|int
name|as_merr
decl_stmt|;
name|int
name|as_uerr
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|amq_opt
block|{
name|AMOPT_DEBUG
init|=
literal|0
block|,
name|AMOPT_LOGFILE
init|=
literal|1
block|,
name|AMOPT_XLOG
init|=
literal|2
block|,
name|AMOPT_FLUSHMAPC
init|=
literal|3
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|amq_opt
name|amq_opt
typedef|;
end_typedef

begin_comment
comment|/* enum typedefs should be after enum */
end_comment

begin_struct
struct|struct
name|amq_setopt
block|{
name|amq_opt
name|as_opt
decl_stmt|;
name|amq_string
name|as_str
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * EXTERNALS:  *  * external definitions for amqproc_*_1() have been moved off to private  * headers in lib/amu.h, amd/amd.h, etc.  They have to be private since the  * same named functions appear in different places with different prototypes  * an functionality.  */
end_comment

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_info
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_info
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_info_list
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_info_list
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_stats
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_stats
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_tree
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_tree
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_tree_list
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_tree_list
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_mount_tree_p
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_mount_tree_p
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_opt
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_opt
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_amq_setopt
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|amq_setopt
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_pri_free
parameter_list|(
name|XDRPROC_T_TYPE
name|xdr_args
parameter_list|,
name|caddr_t
name|args_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool_t
name|xdr_time_type
parameter_list|(
name|XDR
modifier|*
name|xdrs
parameter_list|,
name|time_type
modifier|*
name|objp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not _AMQ_DEFS_H */
end_comment

end_unit

