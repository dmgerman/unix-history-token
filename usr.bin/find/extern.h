begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)extern.h	8.3 (Berkeley) 4/16/94  *	$FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|void
name|brace_subst
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAN
modifier|*
name|find_create
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|find_execute
name|__P
argument_list|(
operator|(
name|PLAN
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAN
modifier|*
name|find_formplan
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAN
modifier|*
name|not_squish
name|__P
argument_list|(
operator|(
name|PLAN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAN
modifier|*
name|or_squish
name|__P
argument_list|(
operator|(
name|PLAN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PLAN
modifier|*
name|paren_squish
name|__P
argument_list|(
operator|(
name|PLAN
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|printlong
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|queryuser
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPTION
modifier|*
name|lookup_option
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_Xmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_Xtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_and
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_delete
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_empty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_follow
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_decl_stmt
name|creat_f
name|c_fstype
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|creat_f
name|c_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_inum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_links
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_ls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_mXXdepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_newer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_nogroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_nouser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_perm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_regex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_simple
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|creat_f
name|c_xdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_Xmin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_Xtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_always_true
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_closeparen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_delete
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_empty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_exec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_expr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_fstype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_inum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_links
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_ls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_newer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_nogroup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_not
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_nouser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_openparen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_or
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_perm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_print
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_print0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_prune
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_regex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|exec_f
name|f_user
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftsoptions
decl_stmt|,
name|isdeprecated
decl_stmt|,
name|isdepth
decl_stmt|,
name|isoutput
decl_stmt|,
name|issort
decl_stmt|,
name|isxargs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mindepth
decl_stmt|,
name|maxdepth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|regexp_flags
decl_stmt|;
end_decl_stmt

end_unit

