begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)find.h	5.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* node definition */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_plandata
block|{
name|struct
name|_plandata
modifier|*
name|next
decl_stmt|;
comment|/* next node */
name|int
function_decl|(
modifier|*
name|eval
function_decl|)
parameter_list|()
function_decl|;
comment|/* node evaluation function */
name|int
name|flags
decl_stmt|;
comment|/* private flags */
name|int
name|type
decl_stmt|;
comment|/* plan node type */
union|union
block|{
name|gid_t
name|_g_data
decl_stmt|;
comment|/* gid */
name|ino_t
name|_i_data
decl_stmt|;
comment|/* inode */
name|mode_t
name|_m_data
decl_stmt|;
comment|/* mode mask */
name|nlink_t
name|_l_data
decl_stmt|;
comment|/* link count */
name|off_t
name|_o_data
decl_stmt|;
comment|/* file size */
name|time_t
name|_t_data
decl_stmt|;
comment|/* time value */
name|uid_t
name|_u_data
decl_stmt|;
comment|/* uid */
name|struct
name|_plandata
modifier|*
name|_p_data
index|[
literal|2
index|]
decl_stmt|;
comment|/* PLAN trees */
struct|struct
name|_ex
block|{
name|char
modifier|*
modifier|*
name|_e_argv
decl_stmt|;
comment|/* argv array */
name|char
modifier|*
modifier|*
name|_e_orig
decl_stmt|;
comment|/* original strings */
name|int
modifier|*
name|_e_len
decl_stmt|;
comment|/* allocated length */
block|}
name|ex
struct|;
name|char
modifier|*
name|_a_data
index|[
literal|2
index|]
decl_stmt|;
comment|/* array of char pointers */
name|char
modifier|*
name|_c_data
decl_stmt|;
comment|/* char pointer */
block|}
name|p_un
union|;
define|#
directive|define
name|a_data
value|p_un._a_data
define|#
directive|define
name|c_data
value|p_un._c_data
define|#
directive|define
name|i_data
value|p_un._i_data
define|#
directive|define
name|g_data
value|p_un._g_data
define|#
directive|define
name|l_data
value|p_un._l_data
define|#
directive|define
name|m_data
value|p_un._m_data
define|#
directive|define
name|o_data
value|p_un._o_data
define|#
directive|define
name|p_data
value|p_un._p_data
define|#
directive|define
name|t_data
value|p_un._t_data
define|#
directive|define
name|u_data
value|p_un._u_data
define|#
directive|define
name|e_argv
value|p_un.ex._e_argv
define|#
directive|define
name|e_orig
value|p_un.ex._e_orig
define|#
directive|define
name|e_len
value|p_un.ex._e_len
block|}
name|PLAN
typedef|;
end_typedef

begin_comment
comment|/* node types */
end_comment

begin_define
define|#
directive|define
name|T_AND
value|1
end_define

begin_comment
comment|/* must start at>0 */
end_comment

begin_define
define|#
directive|define
name|T_ATIME
value|2
end_define

begin_define
define|#
directive|define
name|T_CLOSEPAREN
value|3
end_define

begin_define
define|#
directive|define
name|T_CTIME
value|4
end_define

begin_define
define|#
directive|define
name|T_DEPTH
value|5
end_define

begin_define
define|#
directive|define
name|T_EXEC
value|6
end_define

begin_define
define|#
directive|define
name|T_EXPR
value|7
end_define

begin_define
define|#
directive|define
name|T_FOLLOW
value|8
end_define

begin_define
define|#
directive|define
name|T_FSTYPE
value|9
end_define

begin_define
define|#
directive|define
name|T_GROUP
value|10
end_define

begin_define
define|#
directive|define
name|T_INUM
value|11
end_define

begin_define
define|#
directive|define
name|T_LINKS
value|12
end_define

begin_define
define|#
directive|define
name|T_LS
value|13
end_define

begin_define
define|#
directive|define
name|T_MTIME
value|14
end_define

begin_define
define|#
directive|define
name|T_NAME
value|15
end_define

begin_define
define|#
directive|define
name|T_NEWER
value|16
end_define

begin_define
define|#
directive|define
name|T_NOGROUP
value|17
end_define

begin_define
define|#
directive|define
name|T_NOT
value|18
end_define

begin_define
define|#
directive|define
name|T_NOUSER
value|19
end_define

begin_define
define|#
directive|define
name|T_OK
value|20
end_define

begin_define
define|#
directive|define
name|T_OPENPAREN
value|21
end_define

begin_define
define|#
directive|define
name|T_OR
value|22
end_define

begin_define
define|#
directive|define
name|T_PERM
value|23
end_define

begin_define
define|#
directive|define
name|T_PRINT
value|24
end_define

begin_define
define|#
directive|define
name|T_PRUNE
value|25
end_define

begin_define
define|#
directive|define
name|T_SIZE
value|26
end_define

begin_define
define|#
directive|define
name|T_TYPE
value|27
end_define

begin_define
define|#
directive|define
name|T_USER
value|28
end_define

begin_define
define|#
directive|define
name|T_XDEV
value|29
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftsoptions
decl_stmt|,
name|output_specified
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|emalloc
parameter_list|()
function_decl|;
end_function_decl

end_unit

