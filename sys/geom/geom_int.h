begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Poul-Henning Kamp  * Copyright (c) 2002 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by Poul-Henning Kamp  * and NAI Labs, the Security Research Division of Network Associates, Inc.  * under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the  * DARPA CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|class_list_head
argument_list|,
name|g_class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|g_tailq_head
argument_list|,
name|g_geom
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|event_tailq_head
argument_list|,
name|g_event
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|g_tailq_head
name|geoms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|event_tailq_head
name|events
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_debugflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Various internal actions are tracked by tagging g_event[s] onto  * an internal eventqueue.  */
end_comment

begin_enum
enum|enum
name|g_events
block|{
name|EV_NEW_CLASS
block|,
comment|/* class */
name|EV_NEW_PROVIDER
block|,
comment|/* provider */
name|EV_SPOILED
block|,
comment|/* provider, consumer */
name|EV_LAST
block|}
enum|;
end_enum

begin_struct
struct|struct
name|g_event
block|{
name|enum
name|g_events
name|event
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|g_event
argument_list|)
name|events
expr_stmt|;
name|struct
name|g_class
modifier|*
name|class
decl_stmt|;
name|struct
name|g_geom
modifier|*
name|geom
decl_stmt|;
name|struct
name|g_provider
modifier|*
name|provider
decl_stmt|;
name|struct
name|g_consumer
modifier|*
name|consumer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* geom_dump.c */
end_comment

begin_function_decl
name|struct
name|sbuf
modifier|*
name|g_conf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sbuf
modifier|*
name|g_conf_specific
parameter_list|(
name|struct
name|g_class
modifier|*
name|mp
parameter_list|,
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|,
name|struct
name|g_provider
modifier|*
name|pp
parameter_list|,
name|struct
name|g_consumer
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|sbuf
modifier|*
name|g_confdot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_event.c */
end_comment

begin_function_decl
name|void
name|g_event_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_post_event
parameter_list|(
name|enum
name|g_events
name|ev
parameter_list|,
name|struct
name|g_class
modifier|*
name|mp
parameter_list|,
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|,
name|struct
name|g_provider
modifier|*
name|pp
parameter_list|,
name|struct
name|g_consumer
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_run_events
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_subr.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|class_list_head
name|g_classes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|g_wait_event
decl_stmt|,
modifier|*
name|g_wait_sim
decl_stmt|,
modifier|*
name|g_wait_up
decl_stmt|,
modifier|*
name|g_wait_down
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* geom_io.c */
end_comment

begin_function_decl
name|void
name|g_io_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_io_schedule_down
parameter_list|(
name|struct
name|thread
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_io_schedule_up
parameter_list|(
name|struct
name|thread
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* geom_kern.c / geom_kernsim.c */
end_comment

begin_function_decl
name|void
name|g_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

