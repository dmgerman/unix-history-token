begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Cimarron D. Taylor of the University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)find.h	8.1 (Berkeley) 6/6/93  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_comment
comment|/* forward declarations */
end_comment

begin_struct_decl
struct_decl|struct
name|_plandata
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|_option
struct_decl|;
end_struct_decl

begin_comment
comment|/* execute function */
end_comment

begin_typedef
typedef|typedef
name|int
name|exec_f
name|__P
typedef|((struct
name|_plandata
modifier|*
typedef|,
name|FTSENT
modifier|*
typedef|));
end_typedef

begin_comment
comment|/* create function */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_plandata
modifier|*
name|creat_f
parameter_list|(
name|struct
name|_option
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* function modifiers */
end_comment

begin_define
define|#
directive|define
name|F_NEEDOK
value|0x00000001
end_define

begin_comment
comment|/* -ok vs. -exec */
end_comment

begin_define
define|#
directive|define
name|F_EXECDIR
value|0x00000002
end_define

begin_comment
comment|/* -execdir vs. -exec */
end_comment

begin_define
define|#
directive|define
name|F_TIME_A
value|0x00000004
end_define

begin_comment
comment|/* one of -atime, -anewer, -newera* */
end_comment

begin_define
define|#
directive|define
name|F_TIME_C
value|0x00000008
end_define

begin_comment
comment|/* one of -ctime, -cnewer, -newerc* */
end_comment

begin_define
define|#
directive|define
name|F_TIME2_A
value|0x00000010
end_define

begin_comment
comment|/* one of -newer?a */
end_comment

begin_define
define|#
directive|define
name|F_TIME2_C
value|0x00000020
end_define

begin_comment
comment|/* one of -newer?c */
end_comment

begin_define
define|#
directive|define
name|F_TIME2_T
value|0x00000040
end_define

begin_comment
comment|/* one of -newer?t */
end_comment

begin_define
define|#
directive|define
name|F_MAXDEPTH
value|F_TIME_A
end_define

begin_comment
comment|/* maxdepth vs. mindepth */
end_comment

begin_comment
comment|/* command line function modifiers */
end_comment

begin_define
define|#
directive|define
name|F_EQUAL
value|0x00000000
end_define

begin_comment
comment|/* [acm]min [acm]time inum links size */
end_comment

begin_define
define|#
directive|define
name|F_LESSTHAN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|F_GREATER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|F_ELG_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|F_ATLEAST
value|0x00000400
end_define

begin_comment
comment|/* flags perm */
end_comment

begin_define
define|#
directive|define
name|F_ANY
value|0x00000800
end_define

begin_comment
comment|/* perm */
end_comment

begin_define
define|#
directive|define
name|F_MTMASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|F_MTFLAG
value|0x00000000
end_define

begin_comment
comment|/* fstype */
end_comment

begin_define
define|#
directive|define
name|F_MTTYPE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|F_IGNCASE
value|0x00010000
end_define

begin_comment
comment|/* iname ipath iregex */
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
name|exec_f
modifier|*
name|execute
decl_stmt|;
comment|/* node evaluation function */
name|int
name|flags
decl_stmt|;
comment|/* private flags */
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
struct|struct
block|{
name|u_long
name|_f_flags
decl_stmt|;
name|u_long
name|_f_mask
decl_stmt|;
block|}
name|fl
struct|;
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
name|short
name|_mt_data
decl_stmt|;
comment|/* mount flags */
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
name|regex_t
modifier|*
name|_re_data
decl_stmt|;
comment|/* regex */
block|}
name|p_un
union|;
block|}
name|PLAN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|a_data
value|p_un._a_data
end_define

begin_define
define|#
directive|define
name|c_data
value|p_un._c_data
end_define

begin_define
define|#
directive|define
name|fl_flags
value|p_un.fl._f_flags
end_define

begin_define
define|#
directive|define
name|fl_mask
value|p_un.fl._f_mask
end_define

begin_define
define|#
directive|define
name|g_data
value|p_un._g_data
end_define

begin_define
define|#
directive|define
name|i_data
value|p_un._i_data
end_define

begin_define
define|#
directive|define
name|l_data
value|p_un._l_data
end_define

begin_define
define|#
directive|define
name|m_data
value|p_un._m_data
end_define

begin_define
define|#
directive|define
name|mt_data
value|p_un._mt_data
end_define

begin_define
define|#
directive|define
name|o_data
value|p_un._o_data
end_define

begin_define
define|#
directive|define
name|p_data
value|p_un._p_data
end_define

begin_define
define|#
directive|define
name|t_data
value|p_un._t_data
end_define

begin_define
define|#
directive|define
name|u_data
value|p_un._u_data
end_define

begin_define
define|#
directive|define
name|re_data
value|p_un._re_data
end_define

begin_define
define|#
directive|define
name|e_argv
value|p_un.ex._e_argv
end_define

begin_define
define|#
directive|define
name|e_orig
value|p_un.ex._e_orig
end_define

begin_define
define|#
directive|define
name|e_len
value|p_un.ex._e_len
end_define

begin_typedef
typedef|typedef
struct|struct
name|_option
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* option name */
name|creat_f
modifier|*
name|create
decl_stmt|;
comment|/* create function */
name|exec_f
modifier|*
name|execute
decl_stmt|;
comment|/* execute function */
name|int
name|flags
decl_stmt|;
block|}
name|OPTION
typedef|;
end_typedef

begin_include
include|#
directive|include
file|"extern.h"
end_include

end_unit

