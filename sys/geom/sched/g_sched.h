begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 Fabio Checconi  * Copyright (c) 2009-2010 Luigi Rizzo, Universita` di Pisa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_SCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_SCHED_H_
end_define

begin_comment
comment|/*  * $Id$  * $FreeBSD$  *  * Header for the geom_sched class (userland library and kernel part).  * See g_sched.c for documentation.  * The userland code only needs the three G_SCHED_* values below.  */
end_comment

begin_define
define|#
directive|define
name|G_SCHED_CLASS_NAME
value|"SCHED"
end_define

begin_define
define|#
directive|define
name|G_SCHED_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|G_SCHED_SUFFIX
value|".sched."
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|G_SCHED_DEBUG
parameter_list|(
name|lvl
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (me.gs_debug>= (lvl)) {				\ 		printf("GEOM_SCHED");				\ 		if (me.gs_debug> 0)				\ 			printf("[%u]", lvl);			\ 		printf(": ");					\ 		printf(__VA_ARGS__);				\ 		printf("\n");					\ 	}							\ } while (0)
end_define

begin_define
define|#
directive|define
name|G_SCHED_LOGREQ
parameter_list|(
name|bp
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (me.gs_debug>= 2) {					\ 		printf("GEOM_SCHED[2]: ");			\ 		printf(__VA_ARGS__);				\ 		printf(" ");					\ 		g_print_bio(bp);				\ 		printf("\n");					\ 	}							\ } while (0)
end_define

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|g_hash
argument_list|,
name|g_sched_class
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Descriptor of a scheduler.  * In addition to the obvious fields, sc_flushing and sc_pending  * support dynamic switching of scheduling algorithm.  * Normally, sc_flushing is 0, and requests that are scheduled are  * also added to the sc_pending queue, and removed when we receive  * the 'done' event.  *  * When we are transparently inserted on an existing provider,  * sc_proxying is set. The detach procedure is slightly different.  *  * When switching schedulers, sc_flushing is set so requests bypass us,  * and at the same time we update the pointer in the pending bios  * to ignore us when they return up.  * XXX it would be more efficient to implement sc_pending with  * a generation number: the softc generation is increased when  * we change scheduling algorithm, we store the current generation  * number in the pending bios, and when they come back we ignore  * the done() call if the generation number do not match.  */
end_comment

begin_struct
struct|struct
name|g_sched_softc
block|{
comment|/* 	 * Generic fields used by any scheduling algorithm: 	 * a mutex, the class descriptor, flags, list of pending 	 * requests (used when flushing the module) and support 	 * for hash tables where we store per-flow queues. 	 */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
name|struct
name|g_gsched
modifier|*
name|sc_gsched
decl_stmt|;
comment|/* Scheduler descriptor. */
name|int
name|sc_pending
decl_stmt|;
comment|/* Pending requests. */
name|int
name|sc_flags
decl_stmt|;
comment|/* Various flags. */
comment|/* 	 * Hash tables to store per-flow queues are generally useful 	 * so we handle them in the common code. 	 * sc_hash and sc_mask are parameters of the hash table, 	 * the last two fields are used to periodically remove 	 * expired items from the hash table. 	 */
name|struct
name|g_hash
modifier|*
name|sc_hash
decl_stmt|;
name|u_long
name|sc_mask
decl_stmt|;
name|int
name|sc_flush_ticks
decl_stmt|;
comment|/* Next tick for a flush. */
name|int
name|sc_flush_bucket
decl_stmt|;
comment|/* Next bucket to flush. */
comment|/* 	 * Pointer to the algorithm's private data, which is the value 	 * returned by sc_gsched->gs_init() . A NULL here means failure. 	 * XXX intptr_t might be more appropriate. 	 */
name|void
modifier|*
name|sc_data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|G_SCHED_PROXYING
value|1
end_define

begin_define
define|#
directive|define
name|G_SCHED_FLUSHING
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _G_SCHED_H_ */
end_comment

end_unit

