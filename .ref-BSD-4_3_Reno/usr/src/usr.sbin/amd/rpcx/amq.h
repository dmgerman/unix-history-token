begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id: amq.h,v 5.2 90/06/23 22:20:13 jsp Rel $  *  * Copyright (c) 1990 Jan-Simon Pendry  * Copyright (c) 1990 Imperial College of Science, Technology& Medicine  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)amq.h	5.1 (Berkeley) 7/19/90  */
end_comment

begin_define
define|#
directive|define
name|AMQ_STRLEN
value|1024
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|amq_string
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_string
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|long
modifier|*
name|time_type
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_time_type
parameter_list|()
function_decl|;
end_function_decl

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

begin_typedef
typedef|typedef
name|struct
name|amq_mount_tree
name|amq_mount_tree
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_mount_tree
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|amq_mount_tree
modifier|*
name|amq_mount_tree_p
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_mount_tree_p
parameter_list|()
function_decl|;
end_function_decl

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
name|struct
name|amq_mount_info
name|amq_mount_info
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_mount_info
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|bool_t
name|xdr_amq_mount_info_list
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|bool_t
name|xdr_amq_mount_tree_list
parameter_list|()
function_decl|;
end_function_decl

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

begin_typedef
typedef|typedef
name|struct
name|amq_mount_stats
name|amq_mount_stats
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_mount_stats
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
name|bool_t
name|xdr_amq_opt
parameter_list|()
function_decl|;
end_function_decl

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

begin_typedef
typedef|typedef
name|struct
name|amq_setopt
name|amq_setopt
typedef|;
end_typedef

begin_function_decl
name|bool_t
name|xdr_amq_setopt
parameter_list|()
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|voidp
name|amqproc_null_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_MNTTREE
value|((u_long)1)
end_define

begin_function_decl
specifier|extern
name|amq_mount_tree_p
modifier|*
name|amqproc_mnttree_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_UMNT
value|((u_long)2)
end_define

begin_function_decl
specifier|extern
name|voidp
name|amqproc_umnt_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_STATS
value|((u_long)3)
end_define

begin_function_decl
specifier|extern
name|amq_mount_stats
modifier|*
name|amqproc_stats_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_EXPORT
value|((u_long)4)
end_define

begin_function_decl
specifier|extern
name|amq_mount_tree_list
modifier|*
name|amqproc_export_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_SETOPT
value|((u_long)5)
end_define

begin_function_decl
specifier|extern
name|int
modifier|*
name|amqproc_setopt_1
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AMQPROC_GETMNTFS
value|((u_long)6)
end_define

begin_function_decl
specifier|extern
name|amq_mount_info_list
modifier|*
name|amqproc_getmntfs_1
parameter_list|()
function_decl|;
end_function_decl

end_unit

