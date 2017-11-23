begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: timer.h,v 1.5 2002/05/31 13:30:38 jinmei Exp $	*/
end_comment

begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (C) 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_extern
extern|extern TAILQ_HEAD(rtadvd_timer_head_t
operator|,
extern|rtadvd_timer
end_extern

begin_expr_stmt
unit|)
name|ra_timer
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|rtadvd_timer
block|{
name|TAILQ_ENTRY
argument_list|(
argument|rtadvd_timer
argument_list|)
name|rat_next
expr_stmt|;
name|struct
name|rainfo
modifier|*
name|rat_rai
decl_stmt|;
name|struct
name|timespec
name|rat_tm
decl_stmt|;
name|struct
name|rtadvd_timer
modifier|*
function_decl|(
modifier|*
name|rat_expire
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|rat_expire_data
decl_stmt|;
name|void
function_decl|(
modifier|*
name|rat_update
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|rat_update_data
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|rtadvd_timer_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtadvd_update_timeout_handler
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|rtadvd_timer
modifier|*
name|rtadvd_add_timer
argument_list|(
expr|struct
name|rtadvd_timer
operator|*
call|(
modifier|*
call|)
argument_list|(
name|void
operator|*
argument_list|)
argument_list|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
name|void
operator|*
argument_list|,
expr|struct
name|timespec
operator|*
argument_list|)
argument_list|,
name|void
operator|*
argument_list|,
name|void
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|rtadvd_set_timer
parameter_list|(
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|rtadvd_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rtadvd_remove_timer
parameter_list|(
name|struct
name|rtadvd_timer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|timespec
modifier|*
name|rtadvd_check_timer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

