begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 Fabio Checconi  * Copyright (c) 2009-2010 Luigi Rizzo, Universita` di Pisa  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $Id$  * $FreeBSD$  *  * Prototypes for GEOM-based disk scheduling algorithms.  * See g_sched.c for generic documentation.  *  * This file is used by the kernel modules implementing the various  * scheduling algorithms. They should provide all the methods  * defined in struct g_gsched, and also invoke the macro  *	DECLARE_GSCHED_MODULE  * which registers the scheduling algorithm with the geom_sched module.  *  * The various scheduling algorithms do not need to know anything  * about geom, they only need to handle the 'bio' requests they  * receive, pass them down when needed, and use the locking interface  * defined below.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_G_GSCHED_H_
end_ifndef

begin_define
define|#
directive|define
name|_G_GSCHED_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
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

begin_include
include|#
directive|include
file|"g_sched.h"
end_include

begin_comment
comment|/*  * This is the interface exported to scheduling modules.  *  * gs_init() is called when our scheduling algorithm  *    starts being used by a geom 'sched'  *  * gs_fini() is called when the algorithm is released.  *  * gs_start() is called when a new request comes in. It should  *    enqueue the request and return 0 if success, or return non-zero  *    in case of failure (meaning the request is passed down).  *    The scheduler can use bio->bio_caller1 to store a non-null  *    pointer meaning the request is under its control.  *  * gs_next() is called in a loop by g_sched_dispatch(), right after  *    gs_start(), or on timeouts or 'done' events. It should return  *    immediately, either a pointer to the bio to be served or NULL  *    if no bio should be served now.  If force is specified, a  *    work-conserving behavior is expected.  *  * gs_done() is called when a request under service completes.  *    In turn the scheduler may decide to call the dispatch loop  *    to serve other pending requests (or make sure there is a pending  *    timeout to avoid stalls).  *  * gs_init_class() is called when a new client (as determined by  *    the classifier) starts being used.  *  * gs_hash_unref() is called right before the class hashtable is  *    destroyed; after this call, the scheduler is supposed to hold no  *    more references to the elements in the table.  */
end_comment

begin_comment
comment|/* Forward declarations for prototypes. */
end_comment

begin_struct_decl
struct_decl|struct
name|g_geom
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|g_sched_class
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
modifier|*
name|gs_init_t
parameter_list|(
name|struct
name|g_geom
modifier|*
name|geom
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gs_fini_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gs_start_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|bio
modifier|*
name|bio
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gs_done_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|bio
modifier|*
name|bio
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bio
modifier|*
name|gs_next_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|int
name|force
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|gs_init_class_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gs_fini_class_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|gs_hash_unref_t
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|g_gsched
block|{
specifier|const
name|char
modifier|*
name|gs_name
decl_stmt|;
name|int
name|gs_refs
decl_stmt|;
name|int
name|gs_priv_size
decl_stmt|;
name|gs_init_t
modifier|*
name|gs_init
decl_stmt|;
name|gs_fini_t
modifier|*
name|gs_fini
decl_stmt|;
name|gs_start_t
modifier|*
name|gs_start
decl_stmt|;
name|gs_done_t
modifier|*
name|gs_done
decl_stmt|;
name|gs_next_t
modifier|*
name|gs_next
decl_stmt|;
name|g_dumpconf_t
modifier|*
name|gs_dumpconf
decl_stmt|;
name|gs_init_class_t
modifier|*
name|gs_init_class
decl_stmt|;
name|gs_fini_class_t
modifier|*
name|gs_fini_class
decl_stmt|;
name|gs_hash_unref_t
modifier|*
name|gs_hash_unref
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|g_gsched
argument_list|)
name|glist
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KTR_GSCHED
value|KTR_SPARE4
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_GEOM_SCHED
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Basic classification mechanism.  Each request is associated to  * a g_sched_class, and each scheduler has the opportunity to set  * its own private data for the given (class, geom) pair.  The  * private data have a base type of g_sched_private, and are  * extended at the end with the actual private fields of each  * scheduler.  */
end_comment

begin_struct
struct|struct
name|g_sched_class
block|{
name|int
name|gsc_refs
decl_stmt|;
name|int
name|gsc_expire
decl_stmt|;
name|u_long
name|gsc_key
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|g_sched_class
argument_list|)
name|gsc_clist
expr_stmt|;
name|void
modifier|*
name|gsc_priv
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Manipulate the classifier's data.  g_sched_get_class() gets a reference  * to the class corresponding to bp in gp, allocating and initializing  * it if necessary.  g_sched_put_class() releases the reference.  * The returned value points to the private data for the class.  */
end_comment

begin_function_decl
name|void
modifier|*
name|g_sched_get_class
parameter_list|(
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|,
name|struct
name|bio
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_sched_put_class
parameter_list|(
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|,
name|void
modifier|*
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|struct
name|g_sched_class
modifier|*
name|g_sched_priv2class
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
block|{
return|return
operator|(
operator|(
expr|struct
name|g_sched_class
operator|*
operator|)
operator|(
operator|(
name|u_long
operator|)
name|priv
operator|-
name|offsetof
argument_list|(
expr|struct
name|g_sched_class
argument_list|,
name|gsc_priv
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|g_sched_priv_ref
parameter_list|(
name|void
modifier|*
name|priv
parameter_list|)
block|{
name|struct
name|g_sched_class
modifier|*
name|gsc
decl_stmt|;
name|gsc
operator|=
name|g_sched_priv2class
argument_list|(
name|priv
argument_list|)
expr_stmt|;
name|gsc
operator|->
name|gsc_refs
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Locking interface.  When each operation registered with the  * scheduler is invoked, a per-instance lock is taken to protect  * the data associated with it.  If the scheduler needs something  * else to access the same data (e.g., a callout) it must use  * these functions.  */
end_comment

begin_function_decl
name|void
name|g_sched_lock
parameter_list|(
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|g_sched_unlock
parameter_list|(
name|struct
name|g_geom
modifier|*
name|gp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Restart request dispatching.  Must be called with the per-instance  * mutex held.  */
end_comment

begin_function_decl
name|void
name|g_sched_dispatch
parameter_list|(
name|struct
name|g_geom
modifier|*
name|geom
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Simple gathering of statistical data, used by schedulers to collect  * info on process history.  Just keep an exponential average of the  * samples, with some extra bits of precision.  */
end_comment

begin_struct
struct|struct
name|g_savg
block|{
name|uint64_t
name|gs_avg
decl_stmt|;
name|unsigned
name|int
name|gs_smpl
decl_stmt|;
block|}
struct|;
end_struct

begin_function
specifier|static
specifier|inline
name|void
name|g_savg_add_sample
parameter_list|(
name|struct
name|g_savg
modifier|*
name|ss
parameter_list|,
name|uint64_t
name|sample
parameter_list|)
block|{
comment|/* EMA with alpha = 0.125, fixed point, 3 bits of precision. */
name|ss
operator|->
name|gs_avg
operator|=
name|sample
operator|+
name|ss
operator|->
name|gs_avg
operator|-
operator|(
name|ss
operator|->
name|gs_avg
operator|>>
literal|3
operator|)
expr_stmt|;
name|ss
operator|->
name|gs_smpl
operator|=
literal|1
operator|+
name|ss
operator|->
name|gs_smpl
operator|-
operator|(
name|ss
operator|->
name|gs_smpl
operator|>>
literal|3
operator|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|g_savg_valid
parameter_list|(
name|struct
name|g_savg
modifier|*
name|ss
parameter_list|)
block|{
comment|/* We want at least 8 samples to deem an average as valid. */
return|return
operator|(
name|ss
operator|->
name|gs_smpl
operator|>
literal|7
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|g_savg_read
parameter_list|(
name|struct
name|g_savg
modifier|*
name|ss
parameter_list|)
block|{
return|return
operator|(
name|ss
operator|->
name|gs_avg
operator|/
name|ss
operator|->
name|gs_smpl
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Declaration of a scheduler module.  */
end_comment

begin_function_decl
name|int
name|g_gsched_modevent
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|cmd
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DECLARE_GSCHED_MODULE
parameter_list|(
name|name
parameter_list|,
name|gsched
parameter_list|)
define|\
value|static moduledata_t name##_mod = {			\ 		#name,						\ 		g_gsched_modevent,				\ 		gsched,						\ 	};							\ 	DECLARE_MODULE(name, name##_mod, SI_SUB_DRIVERS, SI_ORDER_MIDDLE); \ 	MODULE_DEPEND(name, geom_sched, 0, 0, 0);
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
comment|/* _G_GSCHED_H_ */
end_comment

end_unit

