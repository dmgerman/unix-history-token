begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)find.h	5.8 (Berkeley) 5/24/91  */
end_comment

begin_comment
comment|/* node type */
end_comment

begin_enum
enum|enum
name|ntype
block|{
name|N_AND
init|=
literal|1
block|,
comment|/* must start> 0 */
name|N_ATIME
block|,
name|N_CLOSEPAREN
block|,
name|N_CTIME
block|,
name|N_DEPTH
block|,
name|N_EXEC
block|,
name|N_EXPR
block|,
name|N_FOLLOW
block|,
name|N_FSTYPE
block|,
name|N_GROUP
block|,
name|N_INUM
block|,
name|N_LINKS
block|,
name|N_LS
block|,
name|N_MTIME
block|,
name|N_NAME
block|,
name|N_NEWER
block|,
name|N_NOGROUP
block|,
name|N_NOT
block|,
name|N_NOUSER
block|,
name|N_OK
block|,
name|N_OPENPAREN
block|,
name|N_OR
block|,
name|N_PERM
block|,
name|N_PRINT
block|,
name|N_PRUNE
block|,
name|N_SIZE
block|,
name|N_TYPE
block|,
name|N_USER
block|,
name|N_XDEV
block|, }
enum|;
end_enum

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
name|enum
name|ntype
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

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

