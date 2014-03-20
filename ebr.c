begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Juniper Networks, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<uuid.h>
end_include

begin_include
include|#
directive|include
file|"mkimg.h"
end_include

begin_include
include|#
directive|include
file|"scheme.h"
end_include

begin_decl_stmt
specifier|static
name|struct
name|mkimg_alias
name|ebr_aliases
index|[]
init|=
block|{
block|{
name|NULL
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|off_t
name|ebr_get_leader
parameter_list|(
name|u_int
name|parts
name|__unused
parameter_list|)
block|{
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|off_t
name|ebr_get_trailer
parameter_list|(
name|u_int
name|parts
name|__unused
parameter_list|)
block|{
comment|/* 	 * Compensate for having reserved a sector for the EBR after 	 * the last partition. 	 */
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|mkimg_scheme
name|ebr_scheme
init|=
block|{
operator|.
name|name
operator|=
literal|"ebr"
block|,
operator|.
name|description
operator|=
literal|"Extended Boot Record"
block|,
operator|.
name|nparts
operator|=
literal|4096
block|,
operator|.
name|padding
operator|=
literal|1
block|,
comment|/* See ebr_get_trailer() above */
operator|.
name|aliases
operator|=
name|ebr_aliases
block|,
operator|.
name|get_leader
operator|=
name|ebr_get_leader
block|,
operator|.
name|get_trailer
operator|=
name|ebr_get_trailer
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SCHEME_DEFINE
argument_list|(
name|ebr_scheme
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

