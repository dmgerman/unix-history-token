begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Fabio Checconi  * Copyright (c) 2010 Luigi Rizzo, Universita` di Pisa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  * $FreeBSD$  *  * This file implements the userspace library used by the 'geom'  * command to load and manipulate disk schedulers.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<libgeom.h>
end_include

begin_include
include|#
directive|include
file|"core/geom.h"
end_include

begin_include
include|#
directive|include
file|"misc/subr.h"
end_include

begin_define
define|#
directive|define
name|G_SCHED_VERSION
value|0
end_define

begin_decl_stmt
name|uint32_t
name|lib_version
init|=
name|G_LIB_VERSION
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uint32_t
name|version
init|=
name|G_SCHED_VERSION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * storage for parameters used by this geom class.  * Right now only the scheduler name is used.  */
end_comment

begin_define
define|#
directive|define
name|GSCHED_ALGO
value|"rr"
end_define

begin_comment
comment|/* default scheduler */
end_comment

begin_comment
comment|/*  * Adapt to differences in geom library.  * in V1 struct g_command misses gc_argname, eld, and G_BOOL is undefined  */
end_comment

begin_if
if|#
directive|if
name|G_LIB_VERSION
operator|<=
literal|1
end_if

begin_define
define|#
directive|define
name|G_TYPE_BOOL
value|G_TYPE_NUMBER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|G_LIB_VERSION
operator|>=
literal|3
operator|&&
name|G_LIB_VERSION
operator|<=
literal|4
end_if

begin_define
define|#
directive|define
name|G_ARGNAME
value|NULL,
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|G_ARGNAME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|static
name|void
name|gcmd_createinsert
parameter_list|(
name|struct
name|gctl_req
modifier|*
name|req
parameter_list|,
name|unsigned
name|flags
name|__unused
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|reqalgo
decl_stmt|;
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
if|if
condition|(
name|gctl_has_param
argument_list|(
name|req
argument_list|,
literal|"algo"
argument_list|)
condition|)
name|reqalgo
operator|=
name|gctl_get_ascii
argument_list|(
name|req
argument_list|,
literal|"algo"
argument_list|)
expr_stmt|;
else|else
name|reqalgo
operator|=
name|GSCHED_ALGO
expr_stmt|;
name|snprintf
argument_list|(
name|name
argument_list|,
sizeof|sizeof
argument_list|(
name|name
argument_list|)
argument_list|,
literal|"gsched_%s"
argument_list|,
name|reqalgo
argument_list|)
expr_stmt|;
comment|/* 	 * Do not complain about errors here, gctl_issue() 	 * will fail anyway. 	 */
if|if
condition|(
name|modfind
argument_list|(
name|name
argument_list|)
operator|<
literal|0
condition|)
name|kldload
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|gctl_issue
argument_list|(
name|req
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|struct
name|g_command
name|class_commands
index|[]
init|=
block|{
block|{
literal|"create"
block|,
name|G_FLAG_VERBOSE
operator||
name|G_FLAG_LOADKLD
block|,
name|gcmd_createinsert
block|,
block|{
block|{
literal|'a'
block|,
literal|"algo"
block|,
name|GSCHED_ALGO
block|,
name|G_TYPE_STRING
block|}
block|,
name|G_OPT_SENTINEL
block|}
block|,
name|G_ARGNAME
literal|"[-v] [-a algorithm_name] dev ..."
block|}
block|,
block|{
literal|"insert"
block|,
name|G_FLAG_VERBOSE
operator||
name|G_FLAG_LOADKLD
block|,
name|gcmd_createinsert
block|,
block|{
block|{
literal|'a'
block|,
literal|"algo"
block|,
name|GSCHED_ALGO
block|,
name|G_TYPE_STRING
block|}
block|,
name|G_OPT_SENTINEL
block|}
block|,
name|G_ARGNAME
literal|"[-v] [-a algorithm_name] dev ..."
block|}
block|,
block|{
literal|"configure"
block|,
name|G_FLAG_VERBOSE
block|,
name|NULL
block|,
block|{
block|{
literal|'a'
block|,
literal|"algo"
block|,
name|GSCHED_ALGO
block|,
name|G_TYPE_STRING
block|}
block|,
name|G_OPT_SENTINEL
block|}
block|,
name|G_ARGNAME
literal|"[-v] [-a algorithm_name] prov ..."
block|}
block|,
block|{
literal|"destroy"
block|,
name|G_FLAG_VERBOSE
block|,
name|NULL
block|,
block|{
block|{
literal|'f'
block|,
literal|"force"
block|,
name|NULL
block|,
name|G_TYPE_BOOL
block|}
block|,
name|G_OPT_SENTINEL
block|}
block|,
name|G_ARGNAME
literal|"[-fv] prov ..."
block|}
block|,
block|{
literal|"reset"
block|,
name|G_FLAG_VERBOSE
block|,
name|NULL
block|,
name|G_NULL_OPTS
block|,
name|G_ARGNAME
literal|"[-v] prov ..."
block|}
block|,
name|G_CMD_SENTINEL
block|}
decl_stmt|;
end_decl_stmt

end_unit

