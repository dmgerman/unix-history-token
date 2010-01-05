begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Luigi Rizzo, Alessandro Cerri. All rights reserved.  * Copyright (c) 2004-2008 Qing Li. All rights reserved.  * Copyright (c) 2008 Kip Macy. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_LLATBL_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_LLATBL_H_
end_define

begin_include
include|#
directive|include
file|<sys/_rwlock.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_req
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rt_msghdr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rt_addrinfo
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|llentry
struct_decl|;
end_struct_decl

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|llentries
argument_list|,
name|llentry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|lltable_rwlock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LLTABLE_RLOCK
parameter_list|()
value|rw_rlock(&lltable_rwlock)
end_define

begin_define
define|#
directive|define
name|LLTABLE_RUNLOCK
parameter_list|()
value|rw_runlock(&lltable_rwlock)
end_define

begin_define
define|#
directive|define
name|LLTABLE_WLOCK
parameter_list|()
value|rw_wlock(&lltable_rwlock)
end_define

begin_define
define|#
directive|define
name|LLTABLE_WUNLOCK
parameter_list|()
value|rw_wunlock(&lltable_rwlock)
end_define

begin_define
define|#
directive|define
name|LLTABLE_LOCK_ASSERT
parameter_list|()
value|rw_assert(&lltable_rwlock, RA_LOCKED)
end_define

begin_comment
comment|/*  * Code referencing llentry must at least hold  * a shared lock  */
end_comment

begin_struct
struct|struct
name|llentry
block|{
name|LIST_ENTRY
argument_list|(
argument|llentry
argument_list|)
name|lle_next
expr_stmt|;
name|struct
name|rwlock
name|lle_lock
decl_stmt|;
name|struct
name|lltable
modifier|*
name|lle_tbl
decl_stmt|;
name|struct
name|llentries
modifier|*
name|lle_head
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|la_hold
decl_stmt|;
name|time_t
name|la_expire
decl_stmt|;
name|uint16_t
name|la_flags
decl_stmt|;
name|uint16_t
name|la_asked
decl_stmt|;
name|uint16_t
name|la_preempt
decl_stmt|;
name|uint16_t
name|ln_byhint
decl_stmt|;
name|int16_t
name|ln_state
decl_stmt|;
comment|/* IPv6 has ND6_LLINFO_NOSTATE == -2 */
name|uint16_t
name|ln_router
decl_stmt|;
name|time_t
name|ln_ntick
decl_stmt|;
name|int
name|lle_refcnt
decl_stmt|;
union|union
block|{
name|uint64_t
name|mac_aligned
decl_stmt|;
name|uint16_t
name|mac16
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ll_addr
union|;
comment|/* XXX af-private? */
union|union
block|{
name|struct
name|callout
name|ln_timer_ch
decl_stmt|;
name|struct
name|callout
name|la_timer
decl_stmt|;
block|}
name|lle_timer
union|;
comment|/* NB: struct sockaddr must immediately follow */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LLE_WLOCK
parameter_list|(
name|lle
parameter_list|)
value|rw_wlock(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_RLOCK
parameter_list|(
name|lle
parameter_list|)
value|rw_rlock(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_WUNLOCK
parameter_list|(
name|lle
parameter_list|)
value|rw_wunlock(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_RUNLOCK
parameter_list|(
name|lle
parameter_list|)
value|rw_runlock(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_DOWNGRADE
parameter_list|(
name|lle
parameter_list|)
value|rw_downgrade(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_TRY_UPGRADE
parameter_list|(
name|lle
parameter_list|)
value|rw_try_upgrade(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_LOCK_INIT
parameter_list|(
name|lle
parameter_list|)
value|rw_init_flags(&(lle)->lle_lock, "lle", RW_DUPOK)
end_define

begin_define
define|#
directive|define
name|LLE_LOCK_DESTROY
parameter_list|(
name|lle
parameter_list|)
value|rw_destroy(&(lle)->lle_lock)
end_define

begin_define
define|#
directive|define
name|LLE_WLOCK_ASSERT
parameter_list|(
name|lle
parameter_list|)
value|rw_assert(&(lle)->lle_lock, RA_WLOCKED)
end_define

begin_define
define|#
directive|define
name|LLE_IS_VALID
parameter_list|(
name|lle
parameter_list|)
value|(((lle) != NULL)&& ((lle) != (void *)-1))
end_define

begin_define
define|#
directive|define
name|LLE_ADDREF
parameter_list|(
name|lle
parameter_list|)
value|do {					\ 	LLE_WLOCK_ASSERT(lle);					\ 	KASSERT((lle)->lle_refcnt>= 0,				\ 		("negative refcnt %d", (lle)->lle_refcnt));	\ 	(lle)->lle_refcnt++;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LLE_REMREF
parameter_list|(
name|lle
parameter_list|)
value|do {					\ 	LLE_WLOCK_ASSERT(lle);					\ 	KASSERT((lle)->lle_refcnt> 1,				\ 		("bogus refcnt %d", (lle)->lle_refcnt));	\ 	(lle)->lle_refcnt--;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|LLE_FREE_LOCKED
parameter_list|(
name|lle
parameter_list|)
value|do {				\ 	if ((lle)->lle_refcnt<= 1)				\ 		(lle)->lle_tbl->llt_free((lle)->lle_tbl, (lle));\ 	else {							\ 		(lle)->lle_refcnt--;				\ 		LLE_WUNLOCK(lle);				\ 	}							\
comment|/* guard against invalid refs */
value|\ 	lle = 0;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|LLE_FREE
parameter_list|(
name|lle
parameter_list|)
value|do {					\ 	LLE_WLOCK(lle);						\ 	if ((lle)->lle_refcnt<= 1)				\ 		(lle)->lle_tbl->llt_free((lle)->lle_tbl, (lle));\ 	else {							\ 		(lle)->lle_refcnt--;				\ 		LLE_WUNLOCK(lle);				\ 	}							\
comment|/* guard against invalid refs */
value|\ 	lle = NULL;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|ln_timer_ch
value|lle_timer.ln_timer_ch
end_define

begin_define
define|#
directive|define
name|la_timer
value|lle_timer.la_timer
end_define

begin_comment
comment|/* XXX bad name */
end_comment

begin_define
define|#
directive|define
name|L3_ADDR
parameter_list|(
name|lle
parameter_list|)
value|((struct sockaddr *)(&lle[1]))
end_define

begin_define
define|#
directive|define
name|L3_ADDR_LEN
parameter_list|(
name|lle
parameter_list|)
value|(((struct sockaddr *)(&lle[1]))->sa_len)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LLTBL_HASHTBL_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LLTBL_HASHTBL_SIZE
value|32
end_define

begin_comment
comment|/* default 32 ? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LLTBL_HASHMASK
end_ifndef

begin_define
define|#
directive|define
name|LLTBL_HASHMASK
value|(LLTBL_HASHTBL_SIZE - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|lltable
block|{
name|SLIST_ENTRY
argument_list|(
argument|lltable
argument_list|)
name|llt_link
expr_stmt|;
name|struct
name|llentries
name|lle_head
index|[
name|LLTBL_HASHTBL_SIZE
index|]
decl_stmt|;
name|int
name|llt_af
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|llt_ifp
decl_stmt|;
name|struct
name|llentry
modifier|*
function_decl|(
modifier|*
name|llt_new
function_decl|)
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|llt_free
function_decl|)
parameter_list|(
name|struct
name|lltable
modifier|*
parameter_list|,
name|struct
name|llentry
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|llt_prefix_free
function_decl|)
parameter_list|(
name|struct
name|lltable
modifier|*
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|prefix
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|mask
parameter_list|)
function_decl|;
name|struct
name|llentry
modifier|*
function_decl|(
modifier|*
name|llt_lookup
function_decl|)
parameter_list|(
name|struct
name|lltable
modifier|*
parameter_list|,
name|u_int
name|flags
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
name|l3addr
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|llt_rtcheck
function_decl|)
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|u_int
name|flags
parameter_list|,
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|llt_dump
function_decl|)
parameter_list|(
name|struct
name|lltable
modifier|*
parameter_list|,
name|struct
name|sysctl_req
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_LLTABLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * flags to be passed to arplookup.  */
end_comment

begin_define
define|#
directive|define
name|LLE_DELETED
value|0x0001
end_define

begin_comment
comment|/* entry must be deleted */
end_comment

begin_define
define|#
directive|define
name|LLE_STATIC
value|0x0002
end_define

begin_comment
comment|/* entry is static */
end_comment

begin_define
define|#
directive|define
name|LLE_IFADDR
value|0x0004
end_define

begin_comment
comment|/* entry is interface addr */
end_comment

begin_define
define|#
directive|define
name|LLE_VALID
value|0x0008
end_define

begin_comment
comment|/* ll_addr is valid */
end_comment

begin_define
define|#
directive|define
name|LLE_PROXY
value|0x0010
end_define

begin_comment
comment|/* proxy entry ??? */
end_comment

begin_define
define|#
directive|define
name|LLE_PUB
value|0x0020
end_define

begin_comment
comment|/* publish entry ??? */
end_comment

begin_define
define|#
directive|define
name|LLE_DELETE
value|0x4000
end_define

begin_comment
comment|/* delete on a lookup - match LLE_IFADDR */
end_comment

begin_define
define|#
directive|define
name|LLE_CREATE
value|0x8000
end_define

begin_comment
comment|/* create on a lookup miss */
end_comment

begin_define
define|#
directive|define
name|LLE_EXCLUSIVE
value|0x2000
end_define

begin_comment
comment|/* return lle xlocked  */
end_comment

begin_define
define|#
directive|define
name|LLATBL_HASH
parameter_list|(
name|key
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((((((key>> 8) ^ key)>> 8) ^ key)>> 8) ^ key)& mask)
end_define

begin_function_decl
name|struct
name|lltable
modifier|*
name|lltable_init
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lltable_free
parameter_list|(
name|struct
name|lltable
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lltable_prefix_free
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lltable_drain
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lltable_sysctl_dumparp
parameter_list|(
name|int
parameter_list|,
name|struct
name|sysctl_req
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|llentry_free
parameter_list|(
name|struct
name|llentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|llentry_update
parameter_list|(
name|struct
name|llentry
modifier|*
modifier|*
parameter_list|,
name|struct
name|lltable
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Generic link layer address lookup function.  */
end_comment

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|llentry
operator|*
name|lla_lookup
argument_list|(
argument|struct lltable *llt
argument_list|,
argument|u_int flags
argument_list|,
argument|const struct sockaddr *l3addr
argument_list|)
block|{
return|return
name|llt
operator|->
name|llt_lookup
argument_list|(
name|llt
argument_list|,
name|flags
argument_list|,
name|l3addr
argument_list|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|int
name|lla_rt_output
parameter_list|(
name|struct
name|rt_msghdr
modifier|*
parameter_list|,
name|struct
name|rt_addrinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET_IF_LLATBL_H_ */
end_comment

end_unit

