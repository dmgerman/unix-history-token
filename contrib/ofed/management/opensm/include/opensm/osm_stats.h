begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_stats_t.  *	This object represents the OpenSM statistics object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_STATS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_STATS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBPTHREAD
end_ifdef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<complib/cl_event.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<complib/cl_atomic.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****h* OpenSM/Statistics * NAME *	OpenSM * * DESCRIPTION *	The OpenSM object encapsulates the information needed by the *	OpenSM to track interesting traffic and internal statistics. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Statistics/osm_stats_t * NAME *	osm_stats_t * * DESCRIPTION *	OpenSM statistics block. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_stats
block|{
name|atomic32_t
name|qp0_mads_outstanding
decl_stmt|;
name|atomic32_t
name|qp0_mads_outstanding_on_wire
decl_stmt|;
name|atomic32_t
name|qp0_mads_rcvd
decl_stmt|;
name|atomic32_t
name|qp0_mads_sent
decl_stmt|;
name|atomic32_t
name|qp0_unicasts_sent
decl_stmt|;
name|atomic32_t
name|qp0_mads_rcvd_unknown
decl_stmt|;
name|atomic32_t
name|sa_mads_outstanding
decl_stmt|;
name|atomic32_t
name|sa_mads_rcvd
decl_stmt|;
name|atomic32_t
name|sa_mads_sent
decl_stmt|;
name|atomic32_t
name|sa_mads_rcvd_unknown
decl_stmt|;
name|atomic32_t
name|sa_mads_ignored
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_LIBPTHREAD
name|pthread_mutex_t
name|mutex
decl_stmt|;
name|pthread_cond_t
name|cond
decl_stmt|;
else|#
directive|else
name|cl_event_t
name|event
decl_stmt|;
endif|#
directive|endif
block|}
name|osm_stats_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	qp0_mads_outstanding *		Contains the number of MADs outstanding on QP0. *		When this value reaches zero, OpenSM has discovered all *		nodes on the subnet, and finished retrieving attributes. *		At that time, subnet configuration may begin. *		This variable must be manipulated using atomic instructions. * *	qp0_mads_outstanding_on_wire *		The number of MADs outstanding on the wire at any moment. * *	qp0_mads_rcvd *		Total number of QP0 MADs received. * *	qp0_mads_sent *		Total number of QP0 MADs sent. * *	qp0_unicasts_sent *		Total number of response-less MADs sent on the wire.  This count *		includes getresp(), send() and trap() methods. * *	qp0_mads_rcvd_unknown *		Total number of unknown QP0 MADs received. This includes *		unrecognized attribute IDs and methods. * *	sa_mads_outstanding *		Contains the number of SA MADs outstanding on QP1. * *	sa_mads_rcvd *		Total number of SA MADs received. * *	sa_mads_sent *		Total number of SA MADs sent. * *	sa_mads_rcvd_unknown *		Total number of unknown SA MADs received. This includes *		unrecognized attribute IDs and methods. * *	sa_mads_ignored *		Total number of SA MADs received because SM is not *		master or SM is in first time sweep. * * SEE ALSO ***************/
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osm_stats_inc_qp0_outstanding
parameter_list|(
name|osm_stats_t
modifier|*
name|stats
parameter_list|)
block|{
name|uint32_t
name|outstanding
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_LIBPTHREAD
name|pthread_mutex_lock
argument_list|(
operator|&
name|stats
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|outstanding
operator|=
operator|++
name|stats
operator|->
name|qp0_mads_outstanding
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|stats
operator|->
name|mutex
argument_list|)
expr_stmt|;
else|#
directive|else
name|outstanding
operator|=
name|cl_atomic_inc
argument_list|(
operator|&
name|stats
operator|->
name|qp0_mads_outstanding
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|outstanding
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint32_t
name|osm_stats_dec_qp0_outstanding
parameter_list|(
name|osm_stats_t
modifier|*
name|stats
parameter_list|)
block|{
name|uint32_t
name|outstanding
decl_stmt|;
ifdef|#
directive|ifdef
name|HAVE_LIBPTHREAD
name|pthread_mutex_lock
argument_list|(
operator|&
name|stats
operator|->
name|mutex
argument_list|)
expr_stmt|;
name|outstanding
operator|=
operator|--
name|stats
operator|->
name|qp0_mads_outstanding
expr_stmt|;
if|if
condition|(
operator|!
name|outstanding
condition|)
name|pthread_cond_signal
argument_list|(
operator|&
name|stats
operator|->
name|cond
argument_list|)
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|stats
operator|->
name|mutex
argument_list|)
expr_stmt|;
else|#
directive|else
name|outstanding
operator|=
name|cl_atomic_dec
argument_list|(
operator|&
name|stats
operator|->
name|qp0_mads_outstanding
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|outstanding
condition|)
name|cl_event_signal
argument_list|(
operator|&
name|stats
operator|->
name|event
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|outstanding
return|;
block|}
end_function

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_STATS_H_ */
end_comment

end_unit

