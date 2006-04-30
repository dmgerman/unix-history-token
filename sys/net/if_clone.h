begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)if.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_CLONE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_CLONE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|IFC_CLONE_INITIALIZER
parameter_list|(
name|name
parameter_list|,
name|data
parameter_list|,
name|maxunit
parameter_list|,			\
name|attach
parameter_list|,
name|match
parameter_list|,
name|create
parameter_list|,
name|destroy
parameter_list|)
define|\
value|{ { 0 }, name, maxunit, NULL, 0, data, attach, match, create, destroy }
end_define

begin_comment
comment|/*  * Structure describing a `cloning' interface.  *  * List of locks  * (c)		const until freeing  * (d)		driver specific data, may need external protection.  * (e)		locked by if_cloners_mtx  * (i)		locked by ifc_mtx mtx  */
end_comment

begin_struct
struct|struct
name|if_clone
block|{
name|LIST_ENTRY
argument_list|(
argument|if_clone
argument_list|)
name|ifc_list
expr_stmt|;
comment|/* (e) On list of cloners */
specifier|const
name|char
modifier|*
name|ifc_name
decl_stmt|;
comment|/* (c) Name of device, e.g. `gif' */
name|int
name|ifc_maxunit
decl_stmt|;
comment|/* (c) Maximum unit number */
name|unsigned
name|char
modifier|*
name|ifc_units
decl_stmt|;
comment|/* (i) Bitmap to handle units. */
comment|/*     Considered private, access */
comment|/*     via ifc_(alloc|free)_unit(). */
name|int
name|ifc_bmlen
decl_stmt|;
comment|/* (c) Bitmap length. */
name|void
modifier|*
name|ifc_data
decl_stmt|;
comment|/* (*) Data for ifc_* functions. */
comment|/* (c) Driver specific cloning functions.  Called with no locks held. */
name|void
function_decl|(
modifier|*
name|ifc_attach
function_decl|)
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ifc_match
function_decl|)
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ifc_create
function_decl|)
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ifc_destroy
function_decl|)
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
name|long
name|ifc_refcnt
decl_stmt|;
comment|/* (i) Refrence count. */
name|struct
name|mtx
name|ifc_mtx
decl_stmt|;
comment|/* Muted to protect members. */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|if_clone_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_clone_attach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|if_clone_detach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_create
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_destroy
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|if_clone_list
parameter_list|(
name|struct
name|if_clonereq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_name2unit
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_alloc_unit
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ifc_free_unit
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The ifc_simple functions, structures, and macros implement basic  * cloning as in 5.[012].  */
end_comment

begin_struct
struct|struct
name|ifc_simple_data
block|{
name|int
name|ifcs_minifs
decl_stmt|;
comment|/* minimum number of interfaces */
name|int
function_decl|(
modifier|*
name|ifcs_create
function_decl|)
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ifcs_destroy
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* interface clone event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|if_clone_event_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|if_clone_event
argument_list|,
name|if_clone_event_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|IFC_SIMPLE_DECLARE
parameter_list|(
name|name
parameter_list|,
name|minifs
parameter_list|)
define|\
value|struct ifc_simple_data name##_cloner_data =				\     {minifs, name##_clone_create, name##_clone_destroy};		\ struct if_clone name##_cloner =						\     IFC_CLONE_INITIALIZER(#name,&name##_cloner_data, IF_MAXUNIT,	\     ifc_simple_attach, ifc_simple_match, ifc_simple_create, ifc_simple_destroy)
end_define

begin_function_decl
name|void
name|ifc_simple_attach
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_simple_match
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_simple_create
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ifc_simple_destroy
parameter_list|(
name|struct
name|if_clone
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* !_NET_IF_CLONE_H_ */
end_comment

end_unit

