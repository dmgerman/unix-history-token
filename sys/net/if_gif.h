begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: if_gif.h,v 1.17 2000/09/11 11:36:41 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * if_gif.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_GIF_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_GIF_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"opt_inet.h"
end_include

begin_include
include|#
directive|include
file|"opt_inet6.h"
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* xxx sigh, why route have struct route instead of pointer? */
end_comment

begin_struct_decl
struct_decl|struct
name|encaptab
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ng_gif_input_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ng_gif_input_orphan_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|af
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|ng_gif_output_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ng_gif_attach_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|ng_gif_detach_p
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|gif_softc
block|{
name|struct
name|ifnet
name|gif_if
decl_stmt|;
comment|/* common area - must be at the top */
name|struct
name|sockaddr
modifier|*
name|gif_psrc
decl_stmt|;
comment|/* Physical src addr */
name|struct
name|sockaddr
modifier|*
name|gif_pdst
decl_stmt|;
comment|/* Physical dst addr */
union|union
block|{
name|struct
name|route
name|gifscr_ro
decl_stmt|;
comment|/* xxx */
ifdef|#
directive|ifdef
name|INET6
name|struct
name|route_in6
name|gifscr_ro6
decl_stmt|;
comment|/* xxx */
endif|#
directive|endif
block|}
name|gifsc_gifscr
union|;
name|int
name|gif_flags
decl_stmt|;
specifier|const
name|struct
name|encaptab
modifier|*
name|encap_cookie4
decl_stmt|;
specifier|const
name|struct
name|encaptab
modifier|*
name|encap_cookie6
decl_stmt|;
name|void
modifier|*
name|gif_netgraph
decl_stmt|;
comment|/* ng_gif(4) netgraph node info */
name|LIST_ENTRY
argument_list|(
argument|gif_softc
argument_list|)
name|gif_link
expr_stmt|;
comment|/* all gif's are linked */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gif_ro
value|gifsc_gifscr.gifscr_ro
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|gif_ro6
value|gifsc_gifscr.gifscr_ro6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GIF_MTU
value|(1280)
end_define

begin_comment
comment|/* Default MTU */
end_comment

begin_define
define|#
directive|define
name|GIF_MTU_MIN
value|(1280)
end_define

begin_comment
comment|/* Minimum MTU */
end_comment

begin_define
define|#
directive|define
name|GIF_MTU_MAX
value|(8192)
end_define

begin_comment
comment|/* Maximum MTU */
end_comment

begin_comment
comment|/* Prototypes */
end_comment

begin_decl_stmt
name|void
name|gif_input
name|__P
argument_list|(
operator|(
expr|struct
name|mbuf
operator|*
operator|,
name|int
operator|,
expr|struct
name|ifnet
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gif_output
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
expr|struct
name|mbuf
operator|*
operator|,
expr|struct
name|sockaddr
operator|*
operator|,
expr|struct
name|rtentry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gif_ioctl
name|__P
argument_list|(
operator|(
expr|struct
name|ifnet
operator|*
operator|,
name|u_long
operator|,
name|caddr_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* _NET_IF_GIF_H_ */
end_comment

end_unit

