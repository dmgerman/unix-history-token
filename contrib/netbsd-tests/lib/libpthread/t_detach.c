begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: t_detach.c,v 1.2 2017/01/16 16:29:54 christos Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2011 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jukka Ruohonen.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__RCSID
argument_list|(
literal|"$NetBSD: t_detach.c,v 1.2 2017/01/16 16:29:54 christos Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<atf-c.h>
end_include

begin_include
include|#
directive|include
file|"h_common.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
modifier|*
name|func
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
modifier|*
name|func
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|sleep
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
end_function

begin_expr_stmt
name|ATF_TC
argument_list|(
name|pthread_detach
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
name|ATF_TC_HEAD
argument_list|(
argument|pthread_detach
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
name|atf_tc_set_md_var
argument_list|(
name|tc
argument_list|,
literal|"descr"
argument_list|,
literal|"A test of pthread_detach(3)"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TC_BODY
argument_list|(
argument|pthread_detach
argument_list|,
argument|tc
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|int
name|state
init|=
name|PTHREAD_CREATE_JOINABLE
decl_stmt|;
name|pthread_attr_t
name|attr
decl_stmt|;
name|pthread_t
name|t
decl_stmt|;
name|int
name|rv
decl_stmt|;
comment|/* 	 * Create a joinable thread. 	 */
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_attr_init
argument_list|(
operator|&
name|attr
argument_list|)
argument_list|)
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_attr_setdetachstate
argument_list|(
operator|&
name|attr
argument_list|,
name|state
argument_list|)
argument_list|)
expr_stmt|;
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_create
argument_list|(
operator|&
name|t
argument_list|,
operator|&
name|attr
argument_list|,
name|func
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * Detach the thread and try to 	 * join it; EINVAL should follow. 	 */
name|PTHREAD_REQUIRE
argument_list|(
name|pthread_detach
argument_list|(
name|t
argument_list|)
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|rv
operator|=
name|pthread_join
argument_list|(
name|t
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|rv
operator|==
name|EINVAL
argument_list|)
expr_stmt|;
name|sleep
argument_list|(
literal|3
argument_list|)
expr_stmt|;
comment|/* 	 * As usual, ESRCH should follow if 	 * we try to detach an invalid thread. 	 */
name|rv
operator|=
name|pthread_cancel
argument_list|(
name|t
argument_list|)
expr_stmt|;
name|ATF_REQUIRE
argument_list|(
name|rv
operator|==
name|ESRCH
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ATF_TP_ADD_TCS
argument_list|(
argument|tp
argument_list|)
end_macro

begin_block
block|{
name|ATF_TP_ADD_TC
argument_list|(
name|tp
argument_list|,
name|pthread_detach
argument_list|)
expr_stmt|;
return|return
name|atf_no_error
argument_list|()
return|;
block|}
end_block

end_unit

