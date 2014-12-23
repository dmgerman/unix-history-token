begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: if_gif.h,v 1.17 2000/09/11 11:36:41 sumikawa Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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

begin_struct_decl
struct_decl|struct
name|ip
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ip6_hdr
struct_decl|;
end_struct_decl

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
modifier|*
name|gif_ifp
decl_stmt|;
name|struct
name|rmlock
name|gif_lock
decl_stmt|;
specifier|const
name|struct
name|encaptab
modifier|*
name|gif_ecookie
decl_stmt|;
name|int
name|gif_family
decl_stmt|;
name|int
name|gif_flags
decl_stmt|;
name|u_int
name|gif_fibnum
decl_stmt|;
name|u_int
name|gif_options
decl_stmt|;
name|void
modifier|*
name|gif_netgraph
decl_stmt|;
comment|/* netgraph node info */
union|union
block|{
name|void
modifier|*
name|hdr
decl_stmt|;
name|struct
name|ip
modifier|*
name|iphdr
decl_stmt|;
ifdef|#
directive|ifdef
name|INET6
name|struct
name|ip6_hdr
modifier|*
name|ip6hdr
decl_stmt|;
endif|#
directive|endif
block|}
name|gif_uhdr
union|;
name|LIST_ENTRY
argument_list|(
argument|gif_softc
argument_list|)
name|gif_list
expr_stmt|;
comment|/* all gif's are linked */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GIF2IFP
parameter_list|(
name|sc
parameter_list|)
value|((sc)->gif_ifp)
end_define

begin_define
define|#
directive|define
name|GIF_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|rm_init(&(sc)->gif_lock, "gif softc")
end_define

begin_define
define|#
directive|define
name|GIF_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|rm_destroy(&(sc)->gif_lock)
end_define

begin_define
define|#
directive|define
name|GIF_RLOCK_TRACKER
value|struct rm_priotracker gif_tracker
end_define

begin_define
define|#
directive|define
name|GIF_RLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_rlock(&(sc)->gif_lock,&gif_tracker)
end_define

begin_define
define|#
directive|define
name|GIF_RUNLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_runlock(&(sc)->gif_lock,&gif_tracker)
end_define

begin_define
define|#
directive|define
name|GIF_RLOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|rm_assert(&(sc)->gif_lock, RA_RLOCKED)
end_define

begin_define
define|#
directive|define
name|GIF_WLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_wlock(&(sc)->gif_lock)
end_define

begin_define
define|#
directive|define
name|GIF_WUNLOCK
parameter_list|(
name|sc
parameter_list|)
value|rm_wunlock(&(sc)->gif_lock)
end_define

begin_define
define|#
directive|define
name|GIF_WLOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|rm_assert(&(sc)->gif_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|gif_iphdr
value|gif_uhdr.iphdr
end_define

begin_define
define|#
directive|define
name|gif_hdr
value|gif_uhdr.hdr
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|gif_ip6hdr
value|gif_uhdr.ip6hdr
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

begin_define
define|#
directive|define
name|MTAG_GIF
value|1080679712
end_define

begin_define
define|#
directive|define
name|MTAG_GIF_CALLED
value|0
end_define

begin_struct
struct|struct
name|etherip_header
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
name|u_int
name|eip_resvl
range|:
literal|4
decl_stmt|,
comment|/* reserved */
name|eip_ver
range|:
literal|4
decl_stmt|;
comment|/* version */
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_int
name|eip_ver
range|:
literal|4
decl_stmt|,
comment|/* version */
name|eip_resvl
range|:
literal|4
decl_stmt|;
comment|/* reserved */
endif|#
directive|endif
name|u_int8_t
name|eip_resvh
decl_stmt|;
comment|/* reserved */
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|ETHERIP_VERSION
value|0x3
end_define

begin_comment
comment|/* mbuf adjust factor to force 32-bit alignment of IP header */
end_comment

begin_define
define|#
directive|define
name|ETHERIP_ALIGN
value|2
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_function_decl
name|void
name|gif_input
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gif_output
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|route
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gif_encapcheck
parameter_list|(
specifier|const
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
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

begin_define
define|#
directive|define
name|GIFGOPTS
value|_IOWR('i', 150, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GIFSOPTS
value|_IOW('i', 151, struct ifreq)
end_define

begin_define
define|#
directive|define
name|GIF_ACCEPT_REVETHIP
value|0x0001
end_define

begin_define
define|#
directive|define
name|GIF_SEND_REVETHIP
value|0x0010
end_define

begin_define
define|#
directive|define
name|GIF_OPTMASK
value|(GIF_ACCEPT_REVETHIP|GIF_SEND_REVETHIP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_GIF_H_ */
end_comment

end_unit

