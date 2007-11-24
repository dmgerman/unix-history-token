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

begin_decl_stmt
specifier|extern
name|int
name|g_collectstats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_debugflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * 1	G_T_TOPOLOGY  * 2	G_T_BIO  * 4	G_T_ACCESS  * 8	(unused)  * 16	Allow footshooting on rank#1 providers  * 32	G_T_DETAILS  */
end_comment

begin_define
define|#
directive|define
name|G_F_DISKIOCTL
value|64
end_define

begin_define
define|#
directive|define
name|G_F_CTLDUMP
value|128
end_define

begin_comment
comment|/* geom_dump.c */
end_comment

begin_function_decl
name|void
name|g_confxml
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_conf_specific
parameter_list|(
name|struct
name|sbuf
modifier|*
name|sb
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
name|g_confdot
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_conftxt
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
name|flag
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
name|g_run_events
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_do_wither
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

begin_function_decl
name|int
name|g_wither_washer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_decl_stmt
specifier|extern
name|int
name|g_shutdown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* geom_ctl.c */
end_comment

begin_function_decl
name|void
name|g_ctl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

