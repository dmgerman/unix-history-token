begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: getmode.c,v 1.6 2004/01/13 00:53:06 simonb Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Todd Vierling.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|"nbtool_config.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_function
name|void
modifier|*
name|setmode
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
block|{
name|mode_t
modifier|*
name|mp
init|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|mode_t
argument_list|)
argument_list|)
decl_stmt|;
operator|*
name|mp
operator|=
name|strtoul
argument_list|(
name|str
argument_list|,
name|NULL
argument_list|,
literal|8
argument_list|)
expr_stmt|;
return|return
name|mp
return|;
block|}
end_function

begin_function
name|mode_t
name|getmode
parameter_list|(
specifier|const
name|void
modifier|*
name|mp
parameter_list|,
name|mode_t
name|mode
parameter_list|)
block|{
name|mode_t
name|m
decl_stmt|;
name|m
operator|=
operator|*
operator|(
operator|(
specifier|const
name|mode_t
operator|*
operator|)
name|mp
operator|)
expr_stmt|;
name|mode
operator|&=
operator|~
name|ALLPERMS
expr_stmt|;
comment|/* input mode less RWX permissions */
name|m
operator|&=
name|ALLPERMS
expr_stmt|;
comment|/* new RWX permissions */
return|return
name|m
operator||
name|mode
return|;
block|}
end_function

end_unit

