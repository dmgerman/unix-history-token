begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Edward Tomasz Napierala<trasz@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<geom/mountver/g_mountver.h>
end_include

begin_include
include|#
directive|include
file|"core/geom.h"
end_include

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
name|G_MOUNTVER_VERSION
decl_stmt|;
end_decl_stmt

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
name|NULL
block|,
block|{
name|G_OPT_SENTINEL
block|}
block|,
name|NULL
block|,
literal|"[-v] dev ..."
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
name|NULL
block|,
literal|"[-fv] prov ..."
block|}
block|,
name|G_CMD_SENTINEL
block|}
decl_stmt|;
end_decl_stmt

end_unit

