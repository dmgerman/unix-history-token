begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)fsinfo.h	8.1 (Berkeley) 6/6/93  *  * $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Get this in now so that OS_HDR can use it  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_define
define|#
directive|define
name|P_void
value|void
end_define

begin_define
define|#
directive|define
name|Const
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|P_void
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_define
define|#
directive|define
name|Const
end_define

begin_comment
comment|/* as nothing */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|INLINE
end_define

begin_comment
comment|/* __inline */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INLINE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_comment
comment|/*  * Pick up target dependent definitions  */
end_comment

begin_include
include|#
directive|include
file|"os-defaults.h"
end_include

begin_include
include|#
directive|include
include|OS_HDR
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VOIDP
end_ifdef

begin_typedef
typedef|typedef
name|void
modifier|*
name|voidp
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|voidp
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VOIDP */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * Bogosity to deal with ether { ... }  */
end_comment

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_include
include|#
directive|include
file|"fsi_data.h"
end_include

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strchr
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strrchr
name|P
argument_list|(
operator|(
name|Const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strdup
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* C */
end_comment

begin_function_decl
specifier|extern
name|void
name|fatal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|warning
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|analyze_automounts
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|analyze_hosts
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compute_automount_point
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|host
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|automount
modifier|*
name|new_automount
name|P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|auto_tree
modifier|*
name|new_auto_tree
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|host
modifier|*
name|new_host
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|disk_fs
modifier|*
name|new_disk_fs
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_disk_fs
name|P
argument_list|(
operator|(
name|disk_fs
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ether_if
modifier|*
name|new_ether_if
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|mount
modifier|*
name|new_mount
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_mount
name|P
argument_list|(
operator|(
name|mount
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fsmount
modifier|*
name|new_fsmount
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_fsmount
name|P
argument_list|(
operator|(
name|fsmount
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|qelem
modifier|*
name|new_que
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_que
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ins_que
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|,
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rem_que
name|P
argument_list|(
operator|(
name|qelem
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dict
modifier|*
name|new_dict
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dict_ent
modifier|*
name|dict_locate
name|P
argument_list|(
operator|(
name|dict
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dict_add
name|P
argument_list|(
operator|(
name|dict
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dict_iter
name|P
argument_list|(
operator|(
name|dict
operator|*
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|info_hdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gen_hdr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|pref_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pref_close
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ioloc
modifier|*
name|current_location
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|disk_fs_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mount_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fsmount_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|host_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ether_if_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|autodir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|username
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|g_argv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fstab_pref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|exportfs_pref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mount_pref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dumpset_pref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|bootparams_pref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|idvbuf
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|file_io_errors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|parse_errors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|errors
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dict
modifier|*
name|dict_of_hosts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|dict
modifier|*
name|dict_of_volnames
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|xcalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ALLOC
parameter_list|(
name|x
parameter_list|)
value|((struct x *) xcalloc(1, sizeof(struct x)))
end_define

begin_define
define|#
directive|define
name|STREQ
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(*(s) == *(t)&& strcmp((s)+1,(t)+1) == 0)
end_define

begin_define
define|#
directive|define
name|ISSET
parameter_list|(
name|m
parameter_list|,
name|b
parameter_list|)
value|((m)& (1<<(b)))
end_define

begin_define
define|#
directive|define
name|BITSET
parameter_list|(
name|m
parameter_list|,
name|b
parameter_list|)
value|((m) |= (1<<(b)))
end_define

begin_define
define|#
directive|define
name|FIRST
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) ((q)->q_forw))
end_define

begin_define
define|#
directive|define
name|LAST
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) ((q)->q_back))
end_define

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) (((qelem *) q)->q_forw))
end_define

begin_define
define|#
directive|define
name|HEAD
parameter_list|(
name|ty
parameter_list|,
name|q
parameter_list|)
value|((ty *) q)
end_define

begin_define
define|#
directive|define
name|ITER
parameter_list|(
name|v
parameter_list|,
name|ty
parameter_list|,
name|q
parameter_list|)
define|\
value|for ((v) = FIRST(ty,(q)); (v) != HEAD(ty,(q)); (v) = NEXT(ty,(v)))
end_define

end_unit

