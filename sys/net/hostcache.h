begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1997 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and  * its documentation for any purpose and without fee is hereby  * granted, provided that both the above copyright notice and this  * permission notice appear in all copies, that both the above  * copyright notice and this permission notice appear in all  * supporting documentation, and that the name of M.I.T. not be used  * in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission.  M.I.T. makes  * no representations about the suitability of this software for any  * purpose.  It is provided "as is" without express or implied  * warranty.  *   * THIS SOFTWARE IS PROVIDED BY M.I.T. ``AS IS''.  M.I.T. DISCLAIMS  * ALL EXPRESS OR IMPLIED WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT  * SHALL M.I.T. BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: hostcache.h,v 1.1 1997/06/18 01:24:22 wollman Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_HOSTCACHE_H
end_ifndef

begin_define
define|#
directive|define
name|_NET_HOSTCACHE_H
value|1
end_define

begin_comment
comment|/*  * This file defines the interface between network protocols and  * the cache of host-specific information maintained by the kernel.  * The generic interface takes care of inserting and deleting entries,  * maintaining mutual exclusion, and enforcing policy constraint on the  * size of the cache and the maximum age of its entries.  * It replaces an earlier scheme which overloaded the routing table  * for this purpose, and should be significantly more efficient  * at performing most operations.  (It does keep a route to each  * entry in the cache.)  Most protocols will want to define a  * structure which begins with `struct hcentry' so that they  * can keep additional, protocol-specific information in it.  */
end_comment

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|hcentry
block|{
name|LIST_ENTRY
argument_list|(
argument|hcentry
argument_list|)
name|hc_link
expr_stmt|;
name|struct
name|timeval
name|hc_idlesince
decl_stmt|;
comment|/* time last ref dropped */
name|struct
name|sockaddr
modifier|*
name|hc_host
decl_stmt|;
comment|/* address of this entry's host */
name|struct
name|rtentry
modifier|*
name|hc_rt
decl_stmt|;
comment|/* route to get there */
comment|/* struct nexthop *hc_nh; */
name|int
name|hc_refcnt
decl_stmt|;
comment|/* reference count */
name|struct
name|hctable
modifier|*
name|hc_hct
decl_stmt|;
comment|/* back ref to table */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hccallback
block|{
name|u_long
function_decl|(
modifier|*
name|hccb_hash
function_decl|)
parameter_list|(
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|hccb_delete
function_decl|)
parameter_list|(
name|struct
name|hcentry
modifier|*
parameter_list|)
function_decl|;
name|u_long
function_decl|(
modifier|*
name|hccb_bump
function_decl|)
parameter_list|(
name|u_long
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|hchead
argument_list|,
name|hcentry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|hctable
block|{
name|u_long
name|hct_nentries
decl_stmt|;
name|u_long
name|hct_active
decl_stmt|;
name|u_long
name|hct_idle
decl_stmt|;
name|struct
name|hchead
modifier|*
name|hct_heads
decl_stmt|;
name|struct
name|hccallback
modifier|*
name|hct_cb
decl_stmt|;
name|int
name|hct_primes
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_HOSTCACHE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The table-modification functions must be called from user mode, as  * they may block waiting for memory and/or locks.  */
end_comment

begin_function_decl
name|int
name|hc_init
parameter_list|(
name|int
name|af
parameter_list|,
name|struct
name|hccallback
modifier|*
name|hccb
parameter_list|,
name|int
name|init_nelem
parameter_list|,
name|int
name|primes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hcentry
modifier|*
name|hc_get
parameter_list|(
name|struct
name|sockaddr
modifier|*
name|sa
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hc_ref
parameter_list|(
name|struct
name|hcentry
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hc_rele
parameter_list|(
name|struct
name|hcentry
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hc_insert
parameter_list|(
name|struct
name|hcentry
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hc_delete
parameter_list|(
name|struct
name|hcentry
modifier|*
name|hc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_HOSTCACHE_H */
end_comment

end_unit

