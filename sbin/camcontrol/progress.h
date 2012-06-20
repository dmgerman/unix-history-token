begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: progressbar.c,v 1.21 2009/04/12 10:18:52 lukem Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997-2012 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Luke Mewburn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROGRESS_H_
end_ifndef

begin_define
define|#
directive|define
name|PROGRESS_H_
value|20100228
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_comment
comment|/* structure used to display a progress meter */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|progress_t
block|{
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* any prefix explanation */
name|uint64_t
name|size
decl_stmt|;
comment|/* total of bytes/units to be counted */
name|uint64_t
name|done
decl_stmt|;
comment|/* number of units counted to date */
name|uint64_t
name|percent
decl_stmt|;
comment|/* cache the percentage complete */
name|time_t
name|start
decl_stmt|;
comment|/* time we started this */
name|time_t
name|now
decl_stmt|;
comment|/* time now */
name|time_t
name|eta
decl_stmt|;
comment|/* estimated # of secs until completion */
name|int64_t
name|elapsed
decl_stmt|;
comment|/* cached # of elapsed seconds */
name|int32_t
name|ttywidth
decl_stmt|;
comment|/* width of tty in columns */
block|}
name|progress_t
typedef|;
end_typedef

begin_function_decl
name|int
name|progress_init
parameter_list|(
name|progress_t
modifier|*
comment|/*meter*/
parameter_list|,
specifier|const
name|char
modifier|*
comment|/*prefix*/
parameter_list|,
name|uint64_t
comment|/*size*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|progress_update
parameter_list|(
name|progress_t
modifier|*
comment|/*meter*/
parameter_list|,
name|uint64_t
comment|/*done*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|progress_draw
parameter_list|(
name|progress_t
modifier|*
comment|/*meter*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|progress_reset_size
parameter_list|(
name|progress_t
modifier|*
comment|/*meter*/
parameter_list|,
name|uint64_t
comment|/*size*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|progress_complete
parameter_list|(
name|progress_t
modifier|*
comment|/*meter*/
parameter_list|,
name|uint64_t
comment|/*done*/
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

