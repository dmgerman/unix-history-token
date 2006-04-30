begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004-2005 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_GATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_GATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<geom/geom.h>
end_include

begin_define
define|#
directive|define
name|G_GATE_CLASS_NAME
value|"GATE"
end_define

begin_define
define|#
directive|define
name|G_GATE_PROVIDER_NAME
value|"ggate"
end_define

begin_define
define|#
directive|define
name|G_GATE_MOD_NAME
value|"ggate"
end_define

begin_define
define|#
directive|define
name|G_GATE_CTL_NAME
value|"ggctl"
end_define

begin_define
define|#
directive|define
name|G_GATE_VERSION
value|1
end_define

begin_comment
comment|/*  * Maximum number of request that can be stored in  * the queue when there are no workers.  */
end_comment

begin_define
define|#
directive|define
name|G_GATE_MAX_QUEUE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|G_GATE_FLAG_READONLY
value|0x0001
end_define

begin_define
define|#
directive|define
name|G_GATE_FLAG_WRITEONLY
value|0x0002
end_define

begin_define
define|#
directive|define
name|G_GATE_FLAG_DESTROY
value|0x1000
end_define

begin_define
define|#
directive|define
name|G_GATE_USERFLAGS
value|(G_GATE_FLAG_READONLY | G_GATE_FLAG_WRITEONLY)
end_define

begin_define
define|#
directive|define
name|G_GATE_CMD_CREATE
value|_IOWR('m', 0, struct g_gate_ctl_create)
end_define

begin_define
define|#
directive|define
name|G_GATE_CMD_DESTROY
value|_IOWR('m', 1, struct g_gate_ctl_destroy)
end_define

begin_define
define|#
directive|define
name|G_GATE_CMD_CANCEL
value|_IOWR('m', 2, struct g_gate_ctl_cancel)
end_define

begin_define
define|#
directive|define
name|G_GATE_CMD_START
value|_IOWR('m', 3, struct g_gate_ctl_io)
end_define

begin_define
define|#
directive|define
name|G_GATE_CMD_DONE
value|_IOWR('m', 4, struct g_gate_ctl_io)
end_define

begin_define
define|#
directive|define
name|G_GATE_INFOSIZE
value|2048
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * 'P:' means 'Protected by'.  */
end_comment

begin_struct
struct|struct
name|g_gate_softc
block|{
name|int
name|sc_unit
decl_stmt|;
comment|/* P: (read-only) */
name|int16_t
name|sc_ref
decl_stmt|;
comment|/* P: g_gate_list_mtx */
name|struct
name|g_provider
modifier|*
name|sc_provider
decl_stmt|;
comment|/* P: (read-only) */
name|uint32_t
name|sc_flags
decl_stmt|;
comment|/* P: (read-only) */
name|struct
name|bio_queue_head
name|sc_inqueue
decl_stmt|;
comment|/* P: sc_queue_mtx */
name|struct
name|bio_queue_head
name|sc_outqueue
decl_stmt|;
comment|/* P: sc_queue_mtx */
name|struct
name|mtx
name|sc_queue_mtx
decl_stmt|;
name|uint32_t
name|sc_queue_count
decl_stmt|;
comment|/* P: sc_queue_mtx */
name|uint32_t
name|sc_queue_size
decl_stmt|;
comment|/* P: (read-only) */
name|u_int
name|sc_timeout
decl_stmt|;
comment|/* P: (read-only) */
name|struct
name|callout
name|sc_callout
decl_stmt|;
comment|/* P: (modified only 							       from callout 							       thread) */
name|uintptr_t
name|sc_seq
decl_stmt|;
comment|/* P: (modified only 							       from g_down 							       thread) */
name|LIST_ENTRY
argument_list|(
argument|g_gate_softc
argument_list|)
name|sc_next
expr_stmt|;
comment|/* P: g_gate_list_mtx */
name|char
name|sc_info
index|[
name|G_GATE_INFOSIZE
index|]
decl_stmt|;
comment|/* P: (read-only) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_name
value|sc_provider->geom->name
end_define

begin_define
define|#
directive|define
name|G_GATE_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if (g_gate_debug>= (lvl)) {					\ 		printf("GEOM_GATE");					\ 		if (g_gate_debug> 0)					\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_GATE_LOGREQ
parameter_list|(
name|lvl
parameter_list|,
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (g_gate_debug>= (lvl)) {					\ 		printf("GEOM_GATE");					\ 		if (g_gate_debug> 0)					\ 			printf("[%u]", lvl);				\ 		printf(": ");						\ 		printf(__VA_ARGS__);					\ 		printf(" ");						\ 		g_print_bio(bp);					\ 		printf("\n");						\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_KERNEL */
end_comment

begin_struct
struct|struct
name|g_gate_ctl_create
block|{
name|u_int
name|gctl_version
decl_stmt|;
name|off_t
name|gctl_mediasize
decl_stmt|;
name|u_int
name|gctl_sectorsize
decl_stmt|;
name|u_int
name|gctl_flags
decl_stmt|;
name|u_int
name|gctl_maxcount
decl_stmt|;
name|u_int
name|gctl_timeout
decl_stmt|;
name|char
name|gctl_info
index|[
name|G_GATE_INFOSIZE
index|]
decl_stmt|;
name|int
name|gctl_unit
decl_stmt|;
comment|/* out */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|g_gate_ctl_destroy
block|{
name|u_int
name|gctl_version
decl_stmt|;
name|int
name|gctl_unit
decl_stmt|;
name|int
name|gctl_force
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|g_gate_ctl_cancel
block|{
name|u_int
name|gctl_version
decl_stmt|;
name|int
name|gctl_unit
decl_stmt|;
name|uintptr_t
name|gctl_seq
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|g_gate_ctl_io
block|{
name|u_int
name|gctl_version
decl_stmt|;
name|int
name|gctl_unit
decl_stmt|;
name|uintptr_t
name|gctl_seq
decl_stmt|;
name|u_int
name|gctl_cmd
decl_stmt|;
name|off_t
name|gctl_offset
decl_stmt|;
name|off_t
name|gctl_length
decl_stmt|;
name|void
modifier|*
name|gctl_data
decl_stmt|;
name|int
name|gctl_error
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_G_GATE_H_ */
end_comment

end_unit

