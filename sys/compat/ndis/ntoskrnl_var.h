begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NTOSKRNL_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NTOSKRNL_VAR_H_
end_define

begin_comment
comment|/* Note: assumes x86 page size of 4K. */
end_comment

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SPAN_PAGES
parameter_list|(
name|ptr
parameter_list|,
name|len
parameter_list|)
define|\
value|((uint32_t)((((uintptr_t)(ptr)& (PAGE_SIZE -1)) +	\ 	(len) + (PAGE_SIZE - 1))>> PAGE_SHIFT))
end_define

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|ptr
parameter_list|)
define|\
value|((void *)((uintptr_t)(ptr)& ~(PAGE_SIZE - 1)))
end_define

begin_define
define|#
directive|define
name|BYTE_OFFSET
parameter_list|(
name|ptr
parameter_list|)
define|\
value|((uint32_t)((uintptr_t)(ptr)& (PAGE_SIZE - 1)))
end_define

begin_define
define|#
directive|define
name|MDL_INIT
parameter_list|(
name|b
parameter_list|,
name|baseva
parameter_list|,
name|len
parameter_list|)
define|\
value|(b)->nb_next = NULL;						\ 	(b)->nb_size = (uint16_t)(sizeof(struct ndis_buffer) +		\ 		(sizeof(uint32_t) * SPAN_PAGES((baseva), (len))));	\ 	(b)->nb_flags = 0;						\ 	(b)->nb_startva = (void *)PAGE_ALIGN((baseva));			\ 	(b)->nb_byteoffset = BYTE_OFFSET((baseva));			\ 	(b)->nb_bytecount = (uint32_t)(len);
end_define

begin_define
define|#
directive|define
name|MDL_VA
parameter_list|(
name|b
parameter_list|)
define|\
value|((void *)((char *)((b)->nb_startva) + (b)->nb_byteoffset))
end_define

begin_define
define|#
directive|define
name|WDM_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|WDM_MINOR_WIN98
value|0x00
end_define

begin_define
define|#
directive|define
name|WDM_MINOR_WINME
value|0x05
end_define

begin_define
define|#
directive|define
name|WDM_MINOR_WIN2000
value|0x10
end_define

begin_define
define|#
directive|define
name|WDM_MINOR_WINXP
value|0x20
end_define

begin_define
define|#
directive|define
name|WDM_MINOR_WIN2003
value|0x30
end_define

begin_comment
comment|/*-  * The ndis_kspin_lock type is called KSPIN_LOCK in MS-Windows.  * According to the Windows DDK header files, KSPIN_LOCK is defined like this:  *	typedef ULONG_PTR KSPIN_LOCK;  *  * From basetsd.h (SDK, Feb. 2003):  * 	typedef [public] unsigned __int3264 ULONG_PTR, *PULONG_PTR;  * 	typedef unsigned __int64 ULONG_PTR, *PULONG_PTR;  * 	typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;  *   * The keyword __int3264 specifies an integral type that has the following  * properties:  *	+ It is 32-bit on 32-bit platforms  *	+ It is 64-bit on 64-bit platforms  *	+ It is 32-bit on the wire for backward compatibility.  *	  It gets truncated on the sending side and extended appropriately  *	  (signed or unsigned) on the receiving side.  *  * Thus register_t seems the proper mapping onto FreeBSD for spin locks.  */
end_comment

begin_typedef
typedef|typedef
name|register_t
name|kspin_lock
typedef|;
end_typedef

begin_struct
struct|struct
name|slist_entry
block|{
name|struct
name|slist_entry
modifier|*
name|sl_next
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|slist_entry
name|slist_entry
typedef|;
end_typedef

begin_union
union|union
name|slist_header
block|{
name|uint64_t
name|slh_align
decl_stmt|;
struct|struct
block|{
name|struct
name|slist_entry
modifier|*
name|slh_next
decl_stmt|;
name|uint16_t
name|slh_depth
decl_stmt|;
name|uint16_t
name|slh_seq
decl_stmt|;
block|}
name|slh_list
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|slist_header
name|slist_header
typedef|;
end_typedef

begin_struct
struct|struct
name|list_entry
block|{
name|struct
name|list_entry
modifier|*
name|nle_flink
decl_stmt|;
name|struct
name|list_entry
modifier|*
name|nle_blink
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|list_entry
name|list_entry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|INIT_LIST_HEAD
parameter_list|(
name|l
parameter_list|)
define|\
value|l->nle_flink = l->nle_blink = l
end_define

begin_define
define|#
directive|define
name|REMOVE_LIST_ENTRY
parameter_list|(
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*b;	\ 		list_entry		*f;	\ 						\ 		f = e->nle_flink;		\ 		b = e->nle_blink;		\ 		b->nle_flink = f;		\ 		f->nle_blink = b;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|REMOVE_LIST_HEAD
parameter_list|(
name|l
parameter_list|)
define|\
value|do {					\ 		list_entry		*f;	\ 		list_entry		*e;	\ 						\ 		e = l->nle_flink;		\ 		f = e->nle_flink;		\ 		l->nle_flink = f;		\ 		f->nle_blink = l;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|REMOVE_LIST_TAIL
parameter_list|(
name|l
parameter_list|)
define|\
value|do {					\ 		list_entry		*b;	\ 		list_entry		*e;	\ 						\ 		e = l->nle_blink;		\ 		b = e->nle_blink;		\ 		l->nle_blink = b;		\ 		b->nle_flink = l;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_LIST_TAIL
parameter_list|(
name|l
parameter_list|,
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*b;	\ 						\ 		b = l->nle_blink;		\ 		e->nle_flink = l;		\ 		e->nle_blink = b;		\ 		b->nle_flink = e;		\ 		l->nle_blink = e;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|INSERT_LIST_HEAD
parameter_list|(
name|l
parameter_list|,
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*f;	\ 						\ 		f = l->nle_flink;		\ 		e->nle_flink = f;		\ 		e->nle_blink = l;		\ 		f->nle_blink = e;		\ 		l->nle_flink = e;		\ 	} while (0)
end_define

begin_struct
struct|struct
name|nt_dispatch_header
block|{
name|uint8_t
name|dh_type
decl_stmt|;
name|uint8_t
name|dh_abs
decl_stmt|;
name|uint8_t
name|dh_size
decl_stmt|;
name|uint8_t
name|dh_inserted
decl_stmt|;
name|uint32_t
name|dh_sigstate
decl_stmt|;
name|list_entry
name|dh_waitlisthead
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nt_dispatch_header
name|nt_dispatch_header
typedef|;
end_typedef

begin_define
define|#
directive|define
name|OTYPE_EVENT
value|0
end_define

begin_define
define|#
directive|define
name|OTYPE_MUTEX
value|1
end_define

begin_define
define|#
directive|define
name|OTYPE_THREAD
value|2
end_define

begin_define
define|#
directive|define
name|OTYPE_TIMER
value|3
end_define

begin_comment
comment|/* Windows dispatcher levels. */
end_comment

begin_define
define|#
directive|define
name|PASSIVE_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|LOW_LEVEL
value|0
end_define

begin_define
define|#
directive|define
name|APC_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|DISPATCH_LEVEL
value|2
end_define

begin_define
define|#
directive|define
name|DEVICE_LEVEL
value|(DISPATCH_LEVEL + 1)
end_define

begin_define
define|#
directive|define
name|PROFILE_LEVEL
value|27
end_define

begin_define
define|#
directive|define
name|CLOCK1_LEVEL
value|28
end_define

begin_define
define|#
directive|define
name|CLOCK2_LEVEL
value|28
end_define

begin_define
define|#
directive|define
name|IPI_LEVEL
value|29
end_define

begin_define
define|#
directive|define
name|POWER_LEVEL
value|30
end_define

begin_define
define|#
directive|define
name|HIGH_LEVEL
value|31
end_define

begin_define
define|#
directive|define
name|SYNC_LEVEL_UP
value|DISPATCH_LEVEL
end_define

begin_define
define|#
directive|define
name|SYNC_LEVEL_MP
value|(IPI_LEVEL - 1)
end_define

begin_define
define|#
directive|define
name|AT_PASSIVE_LEVEL
parameter_list|(
name|td
parameter_list|)
define|\
value|((td)->td_proc->p_flag& P_KTHREAD == FALSE)
end_define

begin_define
define|#
directive|define
name|AT_DISPATCH_LEVEL
parameter_list|(
name|td
parameter_list|)
define|\
value|((td)->td_base_pri == PI_REALTIME)
end_define

begin_define
define|#
directive|define
name|AT_DIRQL_LEVEL
parameter_list|(
name|td
parameter_list|)
define|\
value|((td)->td_priority<= PI_NET)
end_define

begin_define
define|#
directive|define
name|AT_HIGH_LEVEL
parameter_list|(
name|td
parameter_list|)
define|\
value|((td)->td_critnest != 0)
end_define

begin_struct
struct|struct
name|nt_objref
block|{
name|nt_dispatch_header
name|no_dh
decl_stmt|;
name|void
modifier|*
name|no_obj
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|nt_objref
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|nt_objref_head
argument_list|,
name|nt_objref
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|nt_objref
name|nt_objref
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EVENT_TYPE_NOTIFY
value|0
end_define

begin_define
define|#
directive|define
name|EVENT_TYPE_SYNC
value|1
end_define

begin_comment
comment|/*  * We need to use the timeout()/untimeout() API for ktimers  * since timers can be initialized, but not destroyed (so  * malloc()ing our own callout structures would mean a leak,  * since there'd be no way to free() them). This means we  * need to use struct callout_handle, which is really just a  * pointer. To make it easier to deal with, we use a union  * to overlay the callout_handle over the k_timerlistentry.  * The latter is a list_entry, which is two pointers, so  * there's enough space available to hide a callout_handle  * there.  */
end_comment

begin_struct
struct|struct
name|ktimer
block|{
name|nt_dispatch_header
name|k_header
decl_stmt|;
name|uint64_t
name|k_duetime
decl_stmt|;
union|union
block|{
name|list_entry
name|k_timerlistentry
decl_stmt|;
name|struct
name|callout_handle
name|k_handle
decl_stmt|;
block|}
name|u
union|;
name|void
modifier|*
name|k_dpc
decl_stmt|;
name|uint32_t
name|k_period
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|k_timerlistentry
value|u.k_timerlistentry
end_define

begin_define
define|#
directive|define
name|k_handle
value|u.k_handle
end_define

begin_typedef
typedef|typedef
name|struct
name|ktimer
name|ktimer
typedef|;
end_typedef

begin_struct
struct|struct
name|nt_kevent
block|{
name|nt_dispatch_header
name|k_header
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nt_kevent
name|nt_kevent
typedef|;
end_typedef

begin_comment
comment|/* Kernel defered procedure call (i.e. timer callback) */
end_comment

begin_struct_decl
struct_decl|struct
name|kdpc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|kdpc_func
function_decl|)
parameter_list|(
name|struct
name|kdpc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|kdpc
block|{
name|uint16_t
name|k_type
decl_stmt|;
name|uint8_t
name|k_num
decl_stmt|;
name|uint8_t
name|k_importance
decl_stmt|;
name|list_entry
name|k_dpclistentry
decl_stmt|;
name|kdpc_func
name|k_deferedfunc
decl_stmt|;
name|void
modifier|*
name|k_deferredctx
decl_stmt|;
name|void
modifier|*
name|k_sysarg1
decl_stmt|;
name|void
modifier|*
name|k_sysarg2
decl_stmt|;
name|register_t
name|k_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kdpc
name|kdpc
typedef|;
end_typedef

begin_comment
comment|/*  * Note: the acquisition count is BSD-specific. The Microsoft  * documentation says that mutexes can be acquired recursively  * by a given thread, but that you must release the mutex as  * many times as you acquired it before it will be set to the  * signalled state (i.e. before any other threads waiting on  * the object will be woken up). However the Windows KMUTANT  * structure has no field for keeping track of the number of  * acquisitions, so we need to add one ourselves. As long as  * driver code treats the mutex as opaque, we should be ok.  */
end_comment

begin_struct
struct|struct
name|kmutant
block|{
name|nt_dispatch_header
name|km_header
decl_stmt|;
union|union
block|{
name|list_entry
name|km_listentry
decl_stmt|;
name|uint32_t
name|km_acquirecnt
decl_stmt|;
block|}
name|u
union|;
name|void
modifier|*
name|km_ownerthread
decl_stmt|;
name|uint8_t
name|km_abandoned
decl_stmt|;
name|uint8_t
name|km_apcdisable
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|km_listentry
value|u.km_listentry
end_define

begin_define
define|#
directive|define
name|km_acquirecnt
value|u.km_acquirecnt
end_define

begin_typedef
typedef|typedef
name|struct
name|kmutant
name|kmutant
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOOKASIDE_DEPTH
value|256
end_define

begin_struct
struct|struct
name|general_lookaside
block|{
name|slist_header
name|gl_listhead
decl_stmt|;
name|uint16_t
name|gl_depth
decl_stmt|;
name|uint16_t
name|gl_maxdepth
decl_stmt|;
name|uint32_t
name|gl_totallocs
decl_stmt|;
union|union
block|{
name|uint32_t
name|gl_allocmisses
decl_stmt|;
name|uint32_t
name|gl_allochits
decl_stmt|;
block|}
name|u_a
union|;
name|uint32_t
name|gl_totalfrees
decl_stmt|;
union|union
block|{
name|uint32_t
name|gl_freemisses
decl_stmt|;
name|uint32_t
name|gl_freehits
decl_stmt|;
block|}
name|u_m
union|;
name|uint32_t
name|gl_type
decl_stmt|;
name|uint32_t
name|gl_tag
decl_stmt|;
name|uint32_t
name|gl_size
decl_stmt|;
name|void
modifier|*
name|gl_allocfunc
decl_stmt|;
name|void
modifier|*
name|gl_freefunc
decl_stmt|;
name|list_entry
name|gl_listent
decl_stmt|;
name|uint32_t
name|gl_lasttotallocs
decl_stmt|;
union|union
block|{
name|uint32_t
name|gl_lastallocmisses
decl_stmt|;
name|uint32_t
name|gl_lastallochits
decl_stmt|;
block|}
name|u_l
union|;
name|uint32_t
name|gl_rsvd
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|general_lookaside
name|general_lookaside
typedef|;
end_typedef

begin_struct
struct|struct
name|npaged_lookaside_list
block|{
name|general_lookaside
name|nll_l
decl_stmt|;
name|kspin_lock
name|nll_obsoletelock
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|npaged_lookaside_list
name|npaged_lookaside_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|npaged_lookaside_list
name|paged_lookaside_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|lookaside_alloc_func
function_decl|)
parameter_list|(
name|uint32_t
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lookaside_free_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|irp
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|kdevice_qentry
block|{
name|list_entry
name|kqe_devlistent
decl_stmt|;
name|uint32_t
name|kqe_sortkey
decl_stmt|;
name|uint8_t
name|kqe_inserted
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kdevice_qentry
name|kdevice_qentry
typedef|;
end_typedef

begin_struct
struct|struct
name|kdevice_queue
block|{
name|uint16_t
name|kq_type
decl_stmt|;
name|uint16_t
name|kq_size
decl_stmt|;
name|list_entry
name|kq_devlisthead
decl_stmt|;
name|kspin_lock
name|kq_lock
decl_stmt|;
name|uint8_t
name|kq_busy
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kdevice_queue
name|kdevice_queue
typedef|;
end_typedef

begin_struct
struct|struct
name|wait_ctx_block
block|{
name|kdevice_qentry
name|wcb_waitqueue
decl_stmt|;
name|void
modifier|*
name|wcb_devfunc
decl_stmt|;
name|void
modifier|*
name|wcb_devctx
decl_stmt|;
name|uint32_t
name|wcb_mapregcnt
decl_stmt|;
name|void
modifier|*
name|wcb_devobj
decl_stmt|;
name|void
modifier|*
name|wcb_curirp
decl_stmt|;
name|void
modifier|*
name|wcb_bufchaindpc
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|wait_ctx_block
name|wait_ctx_block
typedef|;
end_typedef

begin_struct
struct|struct
name|wait_block
block|{
name|list_entry
name|wb_waitlist
decl_stmt|;
name|void
modifier|*
name|wb_kthread
decl_stmt|;
name|nt_dispatch_header
modifier|*
name|wb_object
decl_stmt|;
name|struct
name|wait_block
modifier|*
name|wb_next
decl_stmt|;
name|uint16_t
name|wb_waitkey
decl_stmt|;
name|uint16_t
name|wb_waittype
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|wait_block
name|wait_block
typedef|;
end_typedef

begin_define
define|#
directive|define
name|THREAD_WAIT_OBJECTS
value|3
end_define

begin_define
define|#
directive|define
name|MAX_WAIT_OBJECTS
value|64
end_define

begin_define
define|#
directive|define
name|WAITTYPE_ALL
value|0
end_define

begin_define
define|#
directive|define
name|WAITTYPE_ANY
value|1
end_define

begin_struct
struct|struct
name|thread_context
block|{
name|void
modifier|*
name|tc_thrctx
decl_stmt|;
name|void
modifier|*
name|tc_thrfunc
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|thread_context
name|thread_context
typedef|;
end_typedef

begin_struct
struct|struct
name|device_object
block|{
name|uint16_t
name|do_type
decl_stmt|;
name|uint16_t
name|do_size
decl_stmt|;
name|uint32_t
name|do_refcnt
decl_stmt|;
name|struct
name|device_object
modifier|*
name|do_drvobj
decl_stmt|;
name|struct
name|device_object
modifier|*
name|do_nextdev
decl_stmt|;
name|struct
name|device_object
modifier|*
name|do_attacheddev
decl_stmt|;
name|struct
name|irp
modifier|*
name|do_currirp
decl_stmt|;
name|void
modifier|*
name|do_iotimer
decl_stmt|;
name|uint32_t
name|do_flags
decl_stmt|;
name|uint32_t
name|do_characteristics
decl_stmt|;
name|void
modifier|*
name|do_vpb
decl_stmt|;
name|void
modifier|*
name|do_devext
decl_stmt|;
name|uint8_t
name|do_stacksize
decl_stmt|;
union|union
block|{
name|list_entry
name|do_listent
decl_stmt|;
name|wait_ctx_block
name|do_wcb
decl_stmt|;
block|}
name|queue
union|;
name|uint32_t
name|do_alignreq
decl_stmt|;
name|kdevice_queue
name|do_devqueue
decl_stmt|;
name|struct
name|kdpc
name|do_dpc
decl_stmt|;
name|uint32_t
name|do_activethreads
decl_stmt|;
name|void
modifier|*
name|do_securitydesc
decl_stmt|;
name|struct
name|nt_kevent
name|do_devlock
decl_stmt|;
name|uint16_t
name|do_sectorsz
decl_stmt|;
name|uint16_t
name|do_spare1
decl_stmt|;
name|void
modifier|*
name|do_devobj_ext
decl_stmt|;
name|void
modifier|*
name|do_rsvd
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|device_object
name|device_object
typedef|;
end_typedef

begin_struct
struct|struct
name|irp
block|{
name|uint32_t
name|i_dummy
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|irp
name|irp
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|driver_dispatch
function_decl|)
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|irp
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|DEVPROP_DEVICE_DESCRIPTION
value|0x00000000
end_define

begin_define
define|#
directive|define
name|DEVPROP_HARDWARE_ID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DEVPROP_COMPATIBLE_IDS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEVPROP_BOOTCONF
value|0x00000003
end_define

begin_define
define|#
directive|define
name|DEVPROP_BOOTCONF_TRANSLATED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DEVPROP_CLASS_NAME
value|0x00000005
end_define

begin_define
define|#
directive|define
name|DEVPROP_CLASS_GUID
value|0x00000006
end_define

begin_define
define|#
directive|define
name|DEVPROP_DRIVER_KEYNAME
value|0x00000007
end_define

begin_define
define|#
directive|define
name|DEVPROP_MANUFACTURER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DEVPROP_FRIENDLYNAME
value|0x00000009
end_define

begin_define
define|#
directive|define
name|DEVPROP_LOCATION_INFO
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|DEVPROP_PHYSDEV_NAME
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|DEVPROP_BUSTYPE_GUID
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|DEVPROP_LEGACY_BUSTYPE
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|DEVPROP_BUS_NUMBER
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|DEVPROP_ENUMERATOR_NAME
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|DEVPROP_ADDRESS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DEVPROP_UINUMBER
value|0x00000011
end_define

begin_define
define|#
directive|define
name|DEVPROP_INSTALL_STATE
value|0x00000012
end_define

begin_define
define|#
directive|define
name|DEVPROP_REMOVAL_POLICY
value|0x00000013
end_define

begin_define
define|#
directive|define
name|STATUS_SUCCESS
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STATUS_USER_APC
value|0x000000C0
end_define

begin_define
define|#
directive|define
name|STATUS_KERNEL_APC
value|0x00000100
end_define

begin_define
define|#
directive|define
name|STATUS_ALERTED
value|0x00000101
end_define

begin_define
define|#
directive|define
name|STATUS_TIMEOUT
value|0x00000102
end_define

begin_define
define|#
directive|define
name|STATUS_INVALID_PARAMETER
value|0xC000000D
end_define

begin_define
define|#
directive|define
name|STATUS_INVALID_DEVICE_REQUEST
value|0xC0000010
end_define

begin_define
define|#
directive|define
name|STATUS_BUFFER_TOO_SMALL
value|0xC0000023
end_define

begin_define
define|#
directive|define
name|STATUS_MUTANT_NOT_OWNED
value|0xC0000046
end_define

begin_define
define|#
directive|define
name|STATUS_INVALID_PARAMETER_2
value|0xC00000F0
end_define

begin_define
define|#
directive|define
name|STATUS_WAIT_0
value|0x00000000
end_define

begin_comment
comment|/*  * FreeBSD's kernel stack is 2 pages in size by default. The  * Windows stack is larger, so we need to give our threads more  * stack pages. 4 should be enough, we use 8 just to extra safe.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_KSTACK_PAGES
value|8
end_define

begin_decl_stmt
specifier|extern
name|image_patch_table
name|ntoskrnl_functbl
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|ntoskrnl_libinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntoskrnl_libfini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|void
name|ntoskrnl_init_dpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_queue_dpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_dequeue_dpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|void
name|ntoskrnl_init_timer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|void
name|ntoskrnl_init_timer_ex
parameter_list|(
name|ktimer
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_set_timer
parameter_list|(
name|ktimer
modifier|*
parameter_list|,
name|int64_t
parameter_list|,
name|kdpc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_set_timer_ex
parameter_list|(
name|ktimer
modifier|*
parameter_list|,
name|int64_t
parameter_list|,
name|uint32_t
parameter_list|,
name|kdpc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_cancel_timer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint8_t
name|ntoskrnl_read_timer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint32_t
name|ntoskrnl_waitforobj
parameter_list|(
name|nt_dispatch_header
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|,
name|int64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|void
name|ntoskrnl_init_event
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|void
name|ntoskrnl_clear_event
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint32_t
name|ntoskrnl_read_event
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint32_t
name|ntoskrnl_set_event
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|__stdcall
specifier|extern
name|uint32_t
name|ntoskrnl_reset_event
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|__fastcall
specifier|extern
name|void
name|ntoskrnl_lock_dpc
argument_list|(
name|REGARGS1
argument_list|(
name|kspin_lock
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__fastcall
specifier|extern
name|void
name|ntoskrnl_unlock_dpc
argument_list|(
name|REGARGS1
argument_list|(
name|kspin_lock
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * On the Windows x86 arch, KeAcquireSpinLock() and KeReleaseSpinLock()  * routines live in the HAL. We try to imitate this behavior.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|ntoskrnl_acquire_spinlock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|*(b) = FASTCALL1(hal_lock, a)
end_define

begin_define
define|#
directive|define
name|ntoskrnl_release_spinlock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|FASTCALL2(hal_unlock, a, b)
end_define

begin_define
define|#
directive|define
name|ntoskrnl_raise_irql
parameter_list|(
name|a
parameter_list|)
value|FASTCALL1(hal_raise_irql, a)
end_define

begin_define
define|#
directive|define
name|ntoskrnl_lower_irql
parameter_list|(
name|a
parameter_list|)
value|FASTCALL1(hal_lower_irql, a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NTOSKRNL_VAR_H_ */
end_comment

end_unit

