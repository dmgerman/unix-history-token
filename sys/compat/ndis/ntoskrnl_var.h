begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Bill Paul<wpaul@windriver.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|MTX_NTOSKRNL_SPIN_LOCK
value|"NDIS thread lock"
end_define

begin_comment
comment|/*  * us_buf is really a wchar_t *, but it's inconvenient to include  * all the necessary header goop needed to define it, and it's a  * pointer anyway, so for now, just make it a uint16_t *.  */
end_comment

begin_struct
struct|struct
name|unicode_string
block|{
name|uint16_t
name|us_len
decl_stmt|;
name|uint16_t
name|us_maxlen
decl_stmt|;
name|uint16_t
modifier|*
name|us_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|unicode_string
name|unicode_string
typedef|;
end_typedef

begin_struct
struct|struct
name|ansi_string
block|{
name|uint16_t
name|as_len
decl_stmt|;
name|uint16_t
name|as_maxlen
decl_stmt|;
name|char
modifier|*
name|as_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ansi_string
name|ansi_string
typedef|;
end_typedef

begin_comment
comment|/*  * Windows memory descriptor list. In Windows, it's possible for  * buffers to be passed between user and kernel contexts without  * copying. Buffers may also be allocated in either paged or  * non-paged memory regions. An MDL describes the pages of memory  * used to contain a particular buffer. Note that a single MDL  * may describe a buffer that spans multiple pages. An array of  * page addresses appears immediately after the MDL structure itself.  * MDLs are therefore implicitly variably sized, even though they  * don't look it.  *  * Note that in FreeBSD, we can take many shortcuts in the way  * we handle MDLs because:  *  * - We are only concerned with pages in kernel context. This means  *   we will only ever use the kernel's memory map, and remapping  *   of buffers is never needed.  *  * - Kernel pages can never be paged out, so we don't have to worry  *   about whether or not a page is actually mapped before going to  *   touch it.  */
end_comment

begin_struct
struct|struct
name|mdl
block|{
name|struct
name|mdl
modifier|*
name|mdl_next
decl_stmt|;
name|uint16_t
name|mdl_size
decl_stmt|;
name|uint16_t
name|mdl_flags
decl_stmt|;
name|void
modifier|*
name|mdl_process
decl_stmt|;
name|void
modifier|*
name|mdl_mappedsystemva
decl_stmt|;
name|void
modifier|*
name|mdl_startva
decl_stmt|;
name|uint32_t
name|mdl_bytecount
decl_stmt|;
name|uint32_t
name|mdl_byteoffset
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mdl
name|mdl
typedef|,
name|ndis_buffer
typedef|;
end_typedef

begin_comment
comment|/* MDL flags */
end_comment

begin_define
define|#
directive|define
name|MDL_MAPPED_TO_SYSTEM_VA
value|0x0001
end_define

begin_define
define|#
directive|define
name|MDL_PAGES_LOCKED
value|0x0002
end_define

begin_define
define|#
directive|define
name|MDL_SOURCE_IS_NONPAGED_POOL
value|0x0004
end_define

begin_define
define|#
directive|define
name|MDL_ALLOCATED_FIXED_SIZE
value|0x0008
end_define

begin_define
define|#
directive|define
name|MDL_PARTIAL
value|0x0010
end_define

begin_define
define|#
directive|define
name|MDL_PARTIAL_HAS_BEEN_MAPPED
value|0x0020
end_define

begin_define
define|#
directive|define
name|MDL_IO_PAGE_READ
value|0x0040
end_define

begin_define
define|#
directive|define
name|MDL_WRITE_OPERATION
value|0x0080
end_define

begin_define
define|#
directive|define
name|MDL_PARENT_MAPPED_SYSTEM_VA
value|0x0100
end_define

begin_define
define|#
directive|define
name|MDL_FREE_EXTRA_PTES
value|0x0200
end_define

begin_define
define|#
directive|define
name|MDL_IO_SPACE
value|0x0800
end_define

begin_define
define|#
directive|define
name|MDL_NETWORK_HEADER
value|0x1000
end_define

begin_define
define|#
directive|define
name|MDL_MAPPING_CAN_FAIL
value|0x2000
end_define

begin_define
define|#
directive|define
name|MDL_ALLOCATED_MUST_SUCCEED
value|0x4000
end_define

begin_define
define|#
directive|define
name|MDL_ZONE_ALLOCED
value|0x8000
end_define

begin_comment
comment|/* BSD private */
end_comment

begin_define
define|#
directive|define
name|MDL_ZONE_PAGES
value|16
end_define

begin_define
define|#
directive|define
name|MDL_ZONE_SIZE
value|(sizeof(mdl) + (sizeof(vm_offset_t) * MDL_ZONE_PAGES))
end_define

begin_comment
comment|/* Note: assumes x86 page size of 4K. */
end_comment

begin_if
if|#
directive|if
name|PAGE_SIZE
operator|==
literal|4096
end_if

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_elif
elif|#
directive|elif
name|PAGE_SIZE
operator|==
literal|8192
end_elif

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|13
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|PAGE_SHIFT undefined!
end_error

begin_endif
endif|#
directive|endif
end_endif

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
value|((uint32_t)((((uintptr_t)(ptr)& (PAGE_SIZE - 1)) +	\ 	(len) + (PAGE_SIZE - 1))>> PAGE_SHIFT))
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
name|MDL_PAGES
parameter_list|(
name|m
parameter_list|)
value|(vm_offset_t *)(m + 1)
end_define

begin_define
define|#
directive|define
name|MmInitializeMdl
parameter_list|(
name|b
parameter_list|,
name|baseva
parameter_list|,
name|len
parameter_list|)
define|\
value|(b)->mdl_next = NULL;						\ 	(b)->mdl_size = (uint16_t)(sizeof(mdl) +			\ 		(sizeof(vm_offset_t) * SPAN_PAGES((baseva), (len))));	\ 	(b)->mdl_flags = 0;						\ 	(b)->mdl_startva = (void *)PAGE_ALIGN((baseva));		\ 	(b)->mdl_byteoffset = BYTE_OFFSET((baseva));			\ 	(b)->mdl_bytecount = (uint32_t)(len);
end_define

begin_define
define|#
directive|define
name|MmGetMdlByteOffset
parameter_list|(
name|mdl
parameter_list|)
value|((mdl)->mdl_byteoffset)
end_define

begin_define
define|#
directive|define
name|MmGetMdlByteCount
parameter_list|(
name|mdl
parameter_list|)
value|((mdl)->mdl_bytecount)
end_define

begin_define
define|#
directive|define
name|MmGetMdlVirtualAddress
parameter_list|(
name|mdl
parameter_list|)
define|\
value|((void *)((char *)((mdl)->mdl_startva) + (mdl)->mdl_byteoffset))
end_define

begin_define
define|#
directive|define
name|MmGetMdlStartVa
parameter_list|(
name|mdl
parameter_list|)
value|((mdl)->mdl_startva)
end_define

begin_define
define|#
directive|define
name|MmGetMdlPfnArray
parameter_list|(
name|mdl
parameter_list|)
value|MDL_PAGES(mdl)
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
name|InitializeListHead
parameter_list|(
name|l
parameter_list|)
define|\
value|(l)->nle_flink = (l)->nle_blink = (l)
end_define

begin_define
define|#
directive|define
name|IsListEmpty
parameter_list|(
name|h
parameter_list|)
define|\
value|((h)->nle_flink == (h))
end_define

begin_define
define|#
directive|define
name|RemoveEntryList
parameter_list|(
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*b;	\ 		list_entry		*f;	\ 						\ 		f = (e)->nle_flink;		\ 		b = (e)->nle_blink;		\ 		b->nle_flink = f;		\ 		f->nle_blink = b;		\ 	} while (0)
end_define

begin_comment
comment|/* These two have to be inlined since they return things. */
end_comment

begin_function
specifier|static
name|__inline__
name|list_entry
modifier|*
name|RemoveHeadList
parameter_list|(
name|list_entry
modifier|*
name|l
parameter_list|)
block|{
name|list_entry
modifier|*
name|f
decl_stmt|;
name|list_entry
modifier|*
name|e
decl_stmt|;
name|e
operator|=
name|l
operator|->
name|nle_flink
expr_stmt|;
name|f
operator|=
name|e
operator|->
name|nle_flink
expr_stmt|;
name|l
operator|->
name|nle_flink
operator|=
name|f
expr_stmt|;
name|f
operator|->
name|nle_blink
operator|=
name|l
expr_stmt|;
return|return
operator|(
name|e
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|list_entry
modifier|*
name|RemoveTailList
parameter_list|(
name|list_entry
modifier|*
name|l
parameter_list|)
block|{
name|list_entry
modifier|*
name|b
decl_stmt|;
name|list_entry
modifier|*
name|e
decl_stmt|;
name|e
operator|=
name|l
operator|->
name|nle_blink
expr_stmt|;
name|b
operator|=
name|e
operator|->
name|nle_blink
expr_stmt|;
name|l
operator|->
name|nle_blink
operator|=
name|b
expr_stmt|;
name|b
operator|->
name|nle_flink
operator|=
name|l
expr_stmt|;
return|return
operator|(
name|e
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|InsertTailList
parameter_list|(
name|l
parameter_list|,
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*b;	\ 						\ 		b = l->nle_blink;		\ 		e->nle_flink = l;		\ 		e->nle_blink = b;		\ 		b->nle_flink = (e);		\ 		l->nle_blink = (e);		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|InsertHeadList
parameter_list|(
name|l
parameter_list|,
name|e
parameter_list|)
define|\
value|do {					\ 		list_entry		*f;	\ 						\ 		f = l->nle_flink;		\ 		e->nle_flink = f;		\ 		e->nle_blink = l;		\ 		f->nle_blink = e;		\ 		l->nle_flink = e;		\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|CONTAINING_RECORD
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|,
name|field
parameter_list|)
define|\
value|((type *)((vm_offset_t)(addr) - (vm_offset_t)(&((type *)0)->field)))
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
name|int32_t
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

begin_comment
comment|/* Dispatcher object types */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_NOTIFICATION_EVENT
value|0
end_define

begin_comment
comment|/* KEVENT */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_SYNCHRONIZATION_EVENT
value|1
end_define

begin_comment
comment|/* KEVENT */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_MUTANT
value|2
end_define

begin_comment
comment|/* KMUTANT/KMUTEX */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_PROCESS
value|3
end_define

begin_comment
comment|/* KPROCESS */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_QUEUE
value|4
end_define

begin_comment
comment|/* KQUEUE */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_SEMAPHORE
value|5
end_define

begin_comment
comment|/* KSEMAPHORE */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_THREAD
value|6
end_define

begin_comment
comment|/* KTHREAD */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_NOTIFICATION_TIMER
value|8
end_define

begin_comment
comment|/* KTIMER */
end_comment

begin_define
define|#
directive|define
name|DISP_TYPE_SYNCHRONIZATION_TIMER
value|9
end_define

begin_comment
comment|/* KTIMER */
end_comment

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
name|callout
modifier|*
name|k_callout
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
name|k_callout
value|u.k_callout
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
comment|/* CPU number */
name|uint8_t
name|k_importance
decl_stmt|;
comment|/* priority */
name|list_entry
name|k_dpclistentry
decl_stmt|;
name|void
modifier|*
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
name|void
modifier|*
name|k_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KDPC_IMPORTANCE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|KDPC_IMPORTANCE_MEDIUM
value|1
end_define

begin_define
define|#
directive|define
name|KDPC_IMPORTANCE_HIGH
value|2
end_define

begin_define
define|#
directive|define
name|KDPC_CPU_DEFAULT
value|255
end_define

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
name|list_entry
name|km_listentry
decl_stmt|;
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
ifdef|#
directive|ifdef
name|__i386__
name|kspin_lock
name|nll_obsoletelock
decl_stmt|;
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|notdef
name|uint16_t
name|wb_waitkey
decl_stmt|;
name|uint16_t
name|wb_waittype
decl_stmt|;
endif|#
directive|endif
name|uint8_t
name|wb_waitkey
decl_stmt|;
name|uint8_t
name|wb_waittype
decl_stmt|;
name|uint8_t
name|wb_awakened
decl_stmt|;
name|uint8_t
name|wb_oldpri
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
name|wb_ext
value|wb_kthread
end_define

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

begin_define
define|#
directive|define
name|WAITKEY_VALID
value|0x8000
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

begin_comment
comment|/* Forward declaration */
end_comment

begin_struct_decl
struct_decl|struct
name|driver_object
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|devobj_extension
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|driver_extension
block|{
name|struct
name|driver_object
modifier|*
name|dre_driverobj
decl_stmt|;
name|void
modifier|*
name|dre_adddevicefunc
decl_stmt|;
name|uint32_t
name|dre_reinitcnt
decl_stmt|;
name|unicode_string
name|dre_srvname
decl_stmt|;
comment|/* 	 * Drivers are allowed to add one or more custom extensions 	 * to the driver object, but there's no special pointer 	 * for them. Hang them off here for now. 	 */
name|list_entry
name|dre_usrext
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|driver_extension
name|driver_extension
typedef|;
end_typedef

begin_struct
struct|struct
name|custom_extension
block|{
name|list_entry
name|ce_list
decl_stmt|;
name|void
modifier|*
name|ce_clid
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|custom_extension
name|custom_extension
typedef|;
end_typedef

begin_comment
comment|/*  * The KINTERRUPT structure in Windows is opaque to drivers.  * We define our own custom version with things we need.  */
end_comment

begin_struct
struct|struct
name|kinterrupt
block|{
name|list_entry
name|ki_list
decl_stmt|;
name|device_t
name|ki_dev
decl_stmt|;
name|int
name|ki_rid
decl_stmt|;
name|void
modifier|*
name|ki_cookie
decl_stmt|;
name|struct
name|resource
modifier|*
name|ki_irq
decl_stmt|;
name|kspin_lock
name|ki_lock_priv
decl_stmt|;
name|kspin_lock
modifier|*
name|ki_lock
decl_stmt|;
name|void
modifier|*
name|ki_svcfunc
decl_stmt|;
name|void
modifier|*
name|ki_svcctx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kinterrupt
name|kinterrupt
typedef|;
end_typedef

begin_comment
comment|/*  * In Windows, there are Physical Device Objects (PDOs) and  * Functional Device Objects (FDOs). Physical Device Objects are  * created and maintained by bus drivers. For example, the PCI  * bus driver might detect two PCI ethernet cards on a given  * bus. The PCI bus driver will then allocate two device_objects  * for its own internal bookeeping purposes. This is analagous  * to the device_t that the FreeBSD PCI code allocates and passes  * into each PCI driver's probe and attach routines.  *  * When an ethernet driver claims one of the ethernet cards  * on the bus, it will create its own device_object. This is  * the Functional Device Object. This object is analagous to the  * device-specific softc structure.  */
end_comment

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
name|driver_object
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
name|uint32_t
name|do_devtype
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
name|struct
name|devobj_extension
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
name|devobj_extension
block|{
name|uint16_t
name|dve_type
decl_stmt|;
name|uint16_t
name|dve_size
decl_stmt|;
name|device_object
modifier|*
name|dve_devobj
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|devobj_extension
name|devobj_extension
typedef|;
end_typedef

begin_comment
comment|/* Device object flags */
end_comment

begin_define
define|#
directive|define
name|DO_VERIFY_VOLUME
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DO_BUFFERED_IO
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DO_EXCLUSIVE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DO_DIRECT_IO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DO_MAP_IO_BUFFER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DO_DEVICE_HAS_NAME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DO_DEVICE_INITIALIZING
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DO_SYSTEM_BOOT_PARTITION
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DO_LONG_TERM_REQUESTS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DO_NEVER_LAST_DEVICE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DO_SHUTDOWN_REGISTERED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DO_BUS_ENUMERATED_DEVICE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DO_POWER_PAGABLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DO_POWER_INRUSH
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DO_LOW_PRIORITY_FILESYSTEM
value|0x00010000
end_define

begin_comment
comment|/* Priority boosts */
end_comment

begin_define
define|#
directive|define
name|IO_NO_INCREMENT
value|0
end_define

begin_define
define|#
directive|define
name|IO_CD_ROM_INCREMENT
value|1
end_define

begin_define
define|#
directive|define
name|IO_DISK_INCREMENT
value|1
end_define

begin_define
define|#
directive|define
name|IO_KEYBOARD_INCREMENT
value|6
end_define

begin_define
define|#
directive|define
name|IO_MAILSLOT_INCREMENT
value|2
end_define

begin_define
define|#
directive|define
name|IO_MOUSE_INCREMENT
value|6
end_define

begin_define
define|#
directive|define
name|IO_NAMED_PIPE_INCREMENT
value|2
end_define

begin_define
define|#
directive|define
name|IO_NETWORK_INCREMENT
value|2
end_define

begin_define
define|#
directive|define
name|IO_PARALLEL_INCREMENT
value|1
end_define

begin_define
define|#
directive|define
name|IO_SERIAL_INCREMENT
value|2
end_define

begin_define
define|#
directive|define
name|IO_SOUND_INCREMENT
value|8
end_define

begin_define
define|#
directive|define
name|IO_VIDEO_INCREMENT
value|1
end_define

begin_comment
comment|/* IRP major codes */
end_comment

begin_define
define|#
directive|define
name|IRP_MJ_CREATE
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MJ_CREATE_NAMED_PIPE
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MJ_CLOSE
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MJ_READ
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MJ_WRITE
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MJ_QUERY_INFORMATION
value|0x05
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SET_INFORMATION
value|0x06
end_define

begin_define
define|#
directive|define
name|IRP_MJ_QUERY_EA
value|0x07
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SET_EA
value|0x08
end_define

begin_define
define|#
directive|define
name|IRP_MJ_FLUSH_BUFFERS
value|0x09
end_define

begin_define
define|#
directive|define
name|IRP_MJ_QUERY_VOLUME_INFORMATION
value|0x0a
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SET_VOLUME_INFORMATION
value|0x0b
end_define

begin_define
define|#
directive|define
name|IRP_MJ_DIRECTORY_CONTROL
value|0x0c
end_define

begin_define
define|#
directive|define
name|IRP_MJ_FILE_SYSTEM_CONTROL
value|0x0d
end_define

begin_define
define|#
directive|define
name|IRP_MJ_DEVICE_CONTROL
value|0x0e
end_define

begin_define
define|#
directive|define
name|IRP_MJ_INTERNAL_DEVICE_CONTROL
value|0x0f
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SHUTDOWN
value|0x10
end_define

begin_define
define|#
directive|define
name|IRP_MJ_LOCK_CONTROL
value|0x11
end_define

begin_define
define|#
directive|define
name|IRP_MJ_CLEANUP
value|0x12
end_define

begin_define
define|#
directive|define
name|IRP_MJ_CREATE_MAILSLOT
value|0x13
end_define

begin_define
define|#
directive|define
name|IRP_MJ_QUERY_SECURITY
value|0x14
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SET_SECURITY
value|0x15
end_define

begin_define
define|#
directive|define
name|IRP_MJ_POWER
value|0x16
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SYSTEM_CONTROL
value|0x17
end_define

begin_define
define|#
directive|define
name|IRP_MJ_DEVICE_CHANGE
value|0x18
end_define

begin_define
define|#
directive|define
name|IRP_MJ_QUERY_QUOTA
value|0x19
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SET_QUOTA
value|0x1a
end_define

begin_define
define|#
directive|define
name|IRP_MJ_PNP
value|0x1b
end_define

begin_define
define|#
directive|define
name|IRP_MJ_PNP_POWER
value|IRP_MJ_PNP
end_define

begin_comment
comment|// Obsolete....
end_comment

begin_define
define|#
directive|define
name|IRP_MJ_MAXIMUM_FUNCTION
value|0x1b
end_define

begin_define
define|#
directive|define
name|IRP_MJ_SCSI
value|IRP_MJ_INTERNAL_DEVICE_CONTROL
end_define

begin_comment
comment|/* IRP minor codes */
end_comment

begin_define
define|#
directive|define
name|IRP_MN_QUERY_DIRECTORY
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_NOTIFY_CHANGE_DIRECTORY
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_USER_FS_REQUEST
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MN_MOUNT_VOLUME
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_VERIFY_VOLUME
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_LOAD_FILE_SYSTEM
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MN_TRACK_LINK
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_KERNEL_CALL
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_LOCK
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_UNLOCK_SINGLE
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_UNLOCK_ALL
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MN_UNLOCK_ALL_BY_KEY
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MN_DPC
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_MDL
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_COMPLETE
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_COMPRESSED
value|0x08
end_define

begin_define
define|#
directive|define
name|IRP_MN_MDL_DPC
value|(IRP_MN_MDL | IRP_MN_DPC)
end_define

begin_define
define|#
directive|define
name|IRP_MN_COMPLETE_MDL
value|(IRP_MN_COMPLETE | IRP_MN_MDL)
end_define

begin_define
define|#
directive|define
name|IRP_MN_COMPLETE_MDL_DPC
value|(IRP_MN_COMPLETE_MDL | IRP_MN_DPC)
end_define

begin_define
define|#
directive|define
name|IRP_MN_SCSI_CLASS
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_START_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_REMOVE_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_REMOVE_DEVICE
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_CANCEL_REMOVE_DEVICE
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MN_STOP_DEVICE
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_STOP_DEVICE
value|0x05
end_define

begin_define
define|#
directive|define
name|IRP_MN_CANCEL_STOP_DEVICE
value|0x06
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_DEVICE_RELATIONS
value|0x07
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_INTERFACE
value|0x08
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_CAPABILITIES
value|0x09
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_RESOURCES
value|0x0A
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_RESOURCE_REQUIREMENTS
value|0x0B
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_DEVICE_TEXT
value|0x0C
end_define

begin_define
define|#
directive|define
name|IRP_MN_FILTER_RESOURCE_REQUIREMENTS
value|0x0D
end_define

begin_define
define|#
directive|define
name|IRP_MN_READ_CONFIG
value|0x0F
end_define

begin_define
define|#
directive|define
name|IRP_MN_WRITE_CONFIG
value|0x10
end_define

begin_define
define|#
directive|define
name|IRP_MN_EJECT
value|0x11
end_define

begin_define
define|#
directive|define
name|IRP_MN_SET_LOCK
value|0x12
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_ID
value|0x13
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_PNP_DEVICE_STATE
value|0x14
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_BUS_INFORMATION
value|0x15
end_define

begin_define
define|#
directive|define
name|IRP_MN_DEVICE_USAGE_NOTIFICATION
value|0x16
end_define

begin_define
define|#
directive|define
name|IRP_MN_SURPRISE_REMOVAL
value|0x17
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_LEGACY_BUS_INFORMATION
value|0x18
end_define

begin_define
define|#
directive|define
name|IRP_MN_WAIT_WAKE
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MN_POWER_SEQUENCE
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_SET_POWER
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_POWER
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_ALL_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|IRP_MN_QUERY_SINGLE_INSTANCE
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_MN_CHANGE_SINGLE_INSTANCE
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_MN_CHANGE_SINGLE_ITEM
value|0x03
end_define

begin_define
define|#
directive|define
name|IRP_MN_ENABLE_EVENTS
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_MN_DISABLE_EVENTS
value|0x05
end_define

begin_define
define|#
directive|define
name|IRP_MN_ENABLE_COLLECTION
value|0x06
end_define

begin_define
define|#
directive|define
name|IRP_MN_DISABLE_COLLECTION
value|0x07
end_define

begin_define
define|#
directive|define
name|IRP_MN_REGINFO
value|0x08
end_define

begin_define
define|#
directive|define
name|IRP_MN_EXECUTE_METHOD
value|0x09
end_define

begin_define
define|#
directive|define
name|IRP_MN_REGINFO_EX
value|0x0b
end_define

begin_comment
comment|/* IRP flags */
end_comment

begin_define
define|#
directive|define
name|IRP_NOCACHE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IRP_PAGING_IO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IRP_MOUNT_COMPLETION
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IRP_SYNCHRONOUS_API
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IRP_ASSOCIATED_IRP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IRP_BUFFERED_IO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IRP_DEALLOCATE_BUFFER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IRP_INPUT_OPERATION
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IRP_SYNCHRONOUS_PAGING_IO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IRP_CREATE_OPERATION
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IRP_READ_OPERATION
value|0x00000100
end_define

begin_define
define|#
directive|define
name|IRP_WRITE_OPERATION
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IRP_CLOSE_OPERATION
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IRP_DEFER_IO_COMPLETION
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IRP_OB_QUERY_NAME
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IRP_HOLD_DEVICE_QUEUE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IRP_RETRY_IO_COMPLETION
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IRP_CLASS_CACHE_OPERATION
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IRP_SET_USER_EVENT
value|IRP_CLOSE_OPERATION
end_define

begin_comment
comment|/* IRP I/O control flags */
end_comment

begin_define
define|#
directive|define
name|IRP_QUOTA_CHARGED
value|0x01
end_define

begin_define
define|#
directive|define
name|IRP_ALLOCATED_MUST_SUCCEED
value|0x02
end_define

begin_define
define|#
directive|define
name|IRP_ALLOCATED_FIXED_SIZE
value|0x04
end_define

begin_define
define|#
directive|define
name|IRP_LOOKASIDE_ALLOCATION
value|0x08
end_define

begin_comment
comment|/* I/O method types */
end_comment

begin_define
define|#
directive|define
name|METHOD_BUFFERED
value|0
end_define

begin_define
define|#
directive|define
name|METHOD_IN_DIRECT
value|1
end_define

begin_define
define|#
directive|define
name|METHOD_OUT_DIRECT
value|2
end_define

begin_define
define|#
directive|define
name|METHOD_NEITHER
value|3
end_define

begin_comment
comment|/* File access types */
end_comment

begin_define
define|#
directive|define
name|FILE_ANY_ACCESS
value|0x0000
end_define

begin_define
define|#
directive|define
name|FILE_SPECIAL_ACCESS
value|FILE_ANY_ACCESS
end_define

begin_define
define|#
directive|define
name|FILE_READ_ACCESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|FILE_WRITE_ACCESS
value|0x0002
end_define

begin_comment
comment|/* Recover I/O access method from IOCTL code. */
end_comment

begin_define
define|#
directive|define
name|IO_METHOD
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFFFFFC)
end_define

begin_comment
comment|/* Recover function code from IOCTL code */
end_comment

begin_define
define|#
directive|define
name|IO_FUNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFC)>> 2)
end_define

begin_comment
comment|/* Macro to construct an IOCTL code. */
end_comment

begin_define
define|#
directive|define
name|IOCTL_CODE
parameter_list|(
name|dev
parameter_list|,
name|func
parameter_list|,
name|iomethod
parameter_list|,
name|acc
parameter_list|)
define|\
value|((dev)<< 16) | (acc<< 14) | (func<< 2) | (iomethod))
end_define

begin_struct
struct|struct
name|io_status_block
block|{
union|union
block|{
name|uint32_t
name|isb_status
decl_stmt|;
name|void
modifier|*
name|isb_ptr
decl_stmt|;
block|}
name|u
union|;
name|register_t
name|isb_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|isb_status
value|u.isb_status
end_define

begin_define
define|#
directive|define
name|isb_ptr
value|u.isb_ptr
end_define

begin_typedef
typedef|typedef
name|struct
name|io_status_block
name|io_status_block
typedef|;
end_typedef

begin_struct
struct|struct
name|kapc
block|{
name|uint16_t
name|apc_type
decl_stmt|;
name|uint16_t
name|apc_size
decl_stmt|;
name|uint32_t
name|apc_spare0
decl_stmt|;
name|void
modifier|*
name|apc_thread
decl_stmt|;
name|list_entry
name|apc_list
decl_stmt|;
name|void
modifier|*
name|apc_kernfunc
decl_stmt|;
name|void
modifier|*
name|apc_rundownfunc
decl_stmt|;
name|void
modifier|*
name|apc_normalfunc
decl_stmt|;
name|void
modifier|*
name|apc_normctx
decl_stmt|;
name|void
modifier|*
name|apc_sysarg1
decl_stmt|;
name|void
modifier|*
name|apc_sysarg2
decl_stmt|;
name|uint8_t
name|apc_stateidx
decl_stmt|;
name|uint8_t
name|apc_cpumode
decl_stmt|;
name|uint8_t
name|apc_inserted
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|kapc
name|kapc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|completion_func
function_decl|)
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|struct
name|irp
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
function_decl|(
modifier|*
name|cancel_func
function_decl|)
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|struct
name|irp
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|io_stack_location
block|{
name|uint8_t
name|isl_major
decl_stmt|;
name|uint8_t
name|isl_minor
decl_stmt|;
name|uint8_t
name|isl_flags
decl_stmt|;
name|uint8_t
name|isl_ctl
decl_stmt|;
comment|/* 	 * There's a big-ass union here in the actual Windows 	 * definition of the stucture, but it contains stuff 	 * that doesn't really apply to BSD, and defining it 	 * all properly would require duplicating over a dozen 	 * other structures that we'll never use. Since the 	 * io_stack_location structure is opaque to drivers 	 * anyway, I'm not going to bother with the extra crap. 	 */
union|union
block|{
struct|struct
block|{
name|uint32_t
name|isl_len
decl_stmt|;
name|uint32_t
modifier|*
name|isl_key
decl_stmt|;
name|uint64_t
name|isl_byteoff
decl_stmt|;
block|}
name|isl_read
struct|;
struct|struct
block|{
name|uint32_t
name|isl_len
decl_stmt|;
name|uint32_t
modifier|*
name|isl_key
decl_stmt|;
name|uint64_t
name|isl_byteoff
decl_stmt|;
block|}
name|isl_write
struct|;
struct|struct
block|{
name|uint32_t
name|isl_obuflen
decl_stmt|;
name|uint32_t
name|isl_ibuflen
decl_stmt|;
name|uint32_t
name|isl_iocode
decl_stmt|;
name|void
modifier|*
name|isl_type3ibuf
decl_stmt|;
block|}
name|isl_ioctl
struct|;
struct|struct
block|{
name|void
modifier|*
name|isl_arg1
decl_stmt|;
name|void
modifier|*
name|isl_arg2
decl_stmt|;
name|void
modifier|*
name|isl_arg3
decl_stmt|;
name|void
modifier|*
name|isl_arg4
decl_stmt|;
block|}
name|isl_others
struct|;
block|}
name|isl_parameters
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
union|;
name|void
modifier|*
name|isl_devobj
decl_stmt|;
name|void
modifier|*
name|isl_fileobj
decl_stmt|;
name|completion_func
name|isl_completionfunc
decl_stmt|;
name|void
modifier|*
name|isl_completionctx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|io_stack_location
name|io_stack_location
typedef|;
end_typedef

begin_comment
comment|/* Stack location control flags */
end_comment

begin_define
define|#
directive|define
name|SL_PENDING_RETURNED
value|0x01
end_define

begin_define
define|#
directive|define
name|SL_INVOKE_ON_CANCEL
value|0x20
end_define

begin_define
define|#
directive|define
name|SL_INVOKE_ON_SUCCESS
value|0x40
end_define

begin_define
define|#
directive|define
name|SL_INVOKE_ON_ERROR
value|0x80
end_define

begin_struct
struct|struct
name|irp
block|{
name|uint16_t
name|irp_type
decl_stmt|;
name|uint16_t
name|irp_size
decl_stmt|;
name|mdl
modifier|*
name|irp_mdl
decl_stmt|;
name|uint32_t
name|irp_flags
decl_stmt|;
union|union
block|{
name|struct
name|irp
modifier|*
name|irp_master
decl_stmt|;
name|uint32_t
name|irp_irpcnt
decl_stmt|;
name|void
modifier|*
name|irp_sysbuf
decl_stmt|;
block|}
name|irp_assoc
union|;
name|list_entry
name|irp_thlist
decl_stmt|;
name|io_status_block
name|irp_iostat
decl_stmt|;
name|uint8_t
name|irp_reqmode
decl_stmt|;
name|uint8_t
name|irp_pendingreturned
decl_stmt|;
name|uint8_t
name|irp_stackcnt
decl_stmt|;
name|uint8_t
name|irp_currentstackloc
decl_stmt|;
name|uint8_t
name|irp_cancel
decl_stmt|;
name|uint8_t
name|irp_cancelirql
decl_stmt|;
name|uint8_t
name|irp_apcenv
decl_stmt|;
name|uint8_t
name|irp_allocflags
decl_stmt|;
name|io_status_block
modifier|*
name|irp_usriostat
decl_stmt|;
name|nt_kevent
modifier|*
name|irp_usrevent
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|void
modifier|*
name|irp_apcfunc
decl_stmt|;
name|void
modifier|*
name|irp_apcctx
decl_stmt|;
block|}
name|irp_asyncparms
struct|;
name|uint64_t
name|irp_allocsz
decl_stmt|;
block|}
name|irp_overlay
union|;
name|cancel_func
name|irp_cancelfunc
decl_stmt|;
name|void
modifier|*
name|irp_userbuf
decl_stmt|;
comment|/* Windows kernel info */
union|union
block|{
struct|struct
block|{
union|union
block|{
name|kdevice_qentry
name|irp_dqe
decl_stmt|;
struct|struct
block|{
name|void
modifier|*
name|irp_drvctx
index|[
literal|4
index|]
decl_stmt|;
block|}
name|s1
struct|;
block|}
name|u1
union|;
name|void
modifier|*
name|irp_thread
decl_stmt|;
name|char
modifier|*
name|irp_auxbuf
decl_stmt|;
struct|struct
block|{
name|list_entry
name|irp_list
decl_stmt|;
union|union
block|{
name|io_stack_location
modifier|*
name|irp_csl
decl_stmt|;
name|uint32_t
name|irp_pkttype
decl_stmt|;
block|}
name|u2
union|;
block|}
name|s2
struct|;
name|void
modifier|*
name|irp_fileobj
decl_stmt|;
block|}
name|irp_overlay
struct|;
name|kapc
name|irp_apc
decl_stmt|;
name|void
modifier|*
name|irp_compkey
decl_stmt|;
block|}
name|irp_tail
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|irp_csl
value|s2.u2.irp_csl
end_define

begin_define
define|#
directive|define
name|irp_pkttype
value|s2.u2.irp_pkttype
end_define

begin_typedef
typedef|typedef
name|struct
name|irp
name|irp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|InterlockedExchangePointer
parameter_list|(
name|dst
parameter_list|,
name|val
parameter_list|)
define|\
value|(void *)InterlockedExchange((uint32_t *)(dst), (uintptr_t)(val))
end_define

begin_define
define|#
directive|define
name|IoSizeOfIrp
parameter_list|(
name|ssize
parameter_list|)
define|\
value|((uint16_t) (sizeof(irp) + ((ssize) * (sizeof(io_stack_location)))))
end_define

begin_define
define|#
directive|define
name|IoSetCancelRoutine
parameter_list|(
name|irp
parameter_list|,
name|func
parameter_list|)
define|\
value|(cancel_func)InterlockedExchangePointer(			\ 	(void *)&(ip)->irp_cancelfunc, (void *)(func))
end_define

begin_define
define|#
directive|define
name|IoGetCurrentIrpStackLocation
parameter_list|(
name|irp
parameter_list|)
define|\
value|(irp)->irp_tail.irp_overlay.irp_csl
end_define

begin_define
define|#
directive|define
name|IoGetNextIrpStackLocation
parameter_list|(
name|irp
parameter_list|)
define|\
value|((irp)->irp_tail.irp_overlay.irp_csl - 1)
end_define

begin_define
define|#
directive|define
name|IoSetNextIrpStackLocation
parameter_list|(
name|irp
parameter_list|)
define|\
value|do {								\ 		irp->irp_currentstackloc--;				\ 		irp->irp_tail.irp_overlay.irp_csl--;			\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IoSetCompletionRoutine
parameter_list|(
name|irp
parameter_list|,
name|func
parameter_list|,
name|ctx
parameter_list|,
name|ok
parameter_list|,
name|err
parameter_list|,
name|cancel
parameter_list|)
define|\
value|do {								\ 		io_stack_location		*s;			\ 		s = IoGetNextIrpStackLocation((irp));			\ 		s->isl_completionfunc = (func);				\ 		s->isl_completionctx = (ctx);				\ 		s->isl_ctl = 0;						\ 		if (ok) s->isl_ctl = SL_INVOKE_ON_SUCCESS;		\ 		if (err) s->isl_ctl |= SL_INVOKE_ON_ERROR;		\ 		if (cancel) s->isl_ctl |= SL_INVOKE_ON_CANCEL;		\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IoMarkIrpPending
parameter_list|(
name|irp
parameter_list|)
define|\
value|IoGetCurrentIrpStackLocation(irp)->isl_ctl |= SL_PENDING_RETURNED
end_define

begin_define
define|#
directive|define
name|IoCopyCurrentIrpStackLocationToNext
parameter_list|(
name|irp
parameter_list|)
define|\
value|do {								\ 		io_stack_location *src, *dst;				\ 		src = IoGetCurrentIrpStackLocation(irp);		\ 		dst = IoGetNextIrpStackLocation(irp);			\ 		bcopy((char *)src, (char *)dst,				\ 		    offsetof(io_stack_location, isl_completionfunc));	\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IoSkipCurrentIrpStackLocation
parameter_list|(
name|irp
parameter_list|)
define|\
value|do {								\ 		(irp)->irp_currentstackloc++;				\ 		(irp)->irp_tail.irp_overlay.irp_csl++;			\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|IoInitializeDpcRequest
parameter_list|(
name|dobj
parameter_list|,
name|dpcfunc
parameter_list|)
define|\
value|KeInitializeDpc(&(dobj)->do_dpc, dpcfunc, dobj)
end_define

begin_define
define|#
directive|define
name|IoRequestDpc
parameter_list|(
name|dobj
parameter_list|,
name|irp
parameter_list|,
name|ctx
parameter_list|)
define|\
value|KeInsertQueueDpc(&(dobj)->do_dpc, irp, ctx)
end_define

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

begin_comment
comment|/*  * The driver_object is allocated once for each driver that's loaded  * into the system. A new one is allocated for each driver and  * populated a bit via the driver's DriverEntry function.  * In general, a Windows DriverEntry() function will provide a pointer  * to its AddDevice() method and set up the dispatch table.  * For NDIS drivers, this is all done behind the scenes in the  * NdisInitializeWrapper() and/or NdisMRegisterMiniport() routines.  */
end_comment

begin_struct
struct|struct
name|driver_object
block|{
name|uint16_t
name|dro_type
decl_stmt|;
name|uint16_t
name|dro_size
decl_stmt|;
name|device_object
modifier|*
name|dro_devobj
decl_stmt|;
name|uint32_t
name|dro_flags
decl_stmt|;
name|void
modifier|*
name|dro_driverstart
decl_stmt|;
name|uint32_t
name|dro_driversize
decl_stmt|;
name|void
modifier|*
name|dro_driversection
decl_stmt|;
name|driver_extension
modifier|*
name|dro_driverext
decl_stmt|;
name|unicode_string
name|dro_drivername
decl_stmt|;
name|unicode_string
modifier|*
name|dro_hwdb
decl_stmt|;
name|void
modifier|*
name|dro_pfastiodispatch
decl_stmt|;
name|void
modifier|*
name|dro_driverinitfunc
decl_stmt|;
name|void
modifier|*
name|dro_driverstartiofunc
decl_stmt|;
name|void
modifier|*
name|dro_driverunloadfunc
decl_stmt|;
name|driver_dispatch
name|dro_dispatch
index|[
name|IRP_MJ_MAXIMUM_FUNCTION
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|driver_object
name|driver_object
typedef|;
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

begin_comment
comment|/* Various supported device types (used with IoCreateDevice()) */
end_comment

begin_define
define|#
directive|define
name|FILE_DEVICE_BEEP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_CD_ROM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_CD_ROM_FILE_SYSTEM
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_CONTROLLER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DATALINK
value|0x00000005
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DFS
value|0x00000006
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DISK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DISK_FILE_SYSTEM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_FILE_SYSTEM
value|0x00000009
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_INPORT_PORT
value|0x0000000A
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_KEYBOARD
value|0x0000000B
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MAILSLOT
value|0x0000000C
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MIDI_IN
value|0x0000000D
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MIDI_OUT
value|0x0000000E
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MOUSE
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MULTI_UNC_PROVIDER
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NAMED_PIPE
value|0x00000011
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NETWORK
value|0x00000012
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NETWORK_BROWSER
value|0x00000013
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NETWORK_FILE_SYSTEM
value|0x00000014
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NULL
value|0x00000015
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_PARALLEL_PORT
value|0x00000016
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_PHYSICAL_NETCARD
value|0x00000017
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_PRINTER
value|0x00000018
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SCANNER
value|0x00000019
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SERIAL_MOUSE_PORT
value|0x0000001A
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SERIAL_PORT
value|0x0000001B
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SCREEN
value|0x0000001C
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SOUND
value|0x0000001D
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_STREAMS
value|0x0000001E
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_TAPE
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_TAPE_FILE_SYSTEM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_TRANSPORT
value|0x00000021
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_UNKNOWN
value|0x00000022
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_VIDEO
value|0x00000023
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_VIRTUAL_DISK
value|0x00000024
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_WAVE_IN
value|0x00000025
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_WAVE_OUT
value|0x00000026
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_8042_PORT
value|0x00000027
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_NETWORK_REDIRECTOR
value|0x00000028
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_BATTERY
value|0x00000029
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_BUS_EXTENDER
value|0x0000002A
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MODEM
value|0x0000002B
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_VDM
value|0x0000002C
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_MASS_STORAGE
value|0x0000002D
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SMB
value|0x0000002E
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_KS
value|0x0000002F
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_CHANGER
value|0x00000030
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SMARTCARD
value|0x00000031
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_ACPI
value|0x00000032
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DVD
value|0x00000033
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_FULLSCREEN_VIDEO
value|0x00000034
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DFS_FILE_SYSTEM
value|0x00000035
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_DFS_VOLUME
value|0x00000036
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SERENUM
value|0x00000037
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_TERMSRV
value|0x00000038
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_KSEC
value|0x00000039
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_FIPS
value|0x0000003A
end_define

begin_comment
comment|/* Device characteristics */
end_comment

begin_define
define|#
directive|define
name|FILE_REMOVABLE_MEDIA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FILE_READ_ONLY_DEVICE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FILE_FLOPPY_DISKETTE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FILE_WRITE_ONCE_MEDIA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|FILE_REMOTE_DEVICE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_IS_MOUNTED
value|0x00000020
end_define

begin_define
define|#
directive|define
name|FILE_VIRTUAL_VOLUME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FILE_AUTOGENERATED_DEVICE_NAME
value|0x00000080
end_define

begin_define
define|#
directive|define
name|FILE_DEVICE_SECURE_OPEN
value|0x00000100
end_define

begin_comment
comment|/* Status codes */
end_comment

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
name|STATUS_PENDING
value|0x00000103
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
name|STATUS_MORE_PROCESSING_REQUIRED
value|0xC0000016
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
name|STATUS_INSUFFICIENT_RESOURCES
value|0xC000009A
end_define

begin_define
define|#
directive|define
name|STATUS_NOT_FOUND
value|0xC0000225
end_define

begin_define
define|#
directive|define
name|STATUS_WAIT_0
value|0x00000000
end_define

begin_comment
comment|/* Memory pool types, for ExAllocatePoolWithTag() */
end_comment

begin_define
define|#
directive|define
name|NonPagedPool
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PagedPool
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NonPagedPoolMustSucceed
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DontUseThisType
value|0x00000003
end_define

begin_define
define|#
directive|define
name|NonPagedPoolCacheAligned
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PagedPoolCacheAligned
value|0x00000005
end_define

begin_define
define|#
directive|define
name|NonPagedPoolCacheAlignedMustS
value|0x00000006
end_define

begin_define
define|#
directive|define
name|MaxPoolType
value|0x00000007
end_define

begin_comment
comment|/*  * IO_WORKITEM is an opaque structures that must be allocated  * via IoAllocateWorkItem() and released via IoFreeWorkItem().  * Consequently, we can define it any way we want.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|io_workitem_func
function_decl|)
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|io_workitem
block|{
name|io_workitem_func
name|iw_func
decl_stmt|;
name|void
modifier|*
name|iw_ctx
decl_stmt|;
name|list_entry
name|iw_listentry
decl_stmt|;
name|device_object
modifier|*
name|iw_dobj
decl_stmt|;
name|int
name|iw_idx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|io_workitem
name|io_workitem
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORKQUEUE_CRITICAL
value|0
end_define

begin_define
define|#
directive|define
name|WORKQUEUE_DELAYED
value|1
end_define

begin_define
define|#
directive|define
name|WORKQUEUE_HYPERCRITICAL
value|2
end_define

begin_define
define|#
directive|define
name|WORKITEM_THREADS
value|4
end_define

begin_define
define|#
directive|define
name|WORKITEM_LEGACY_THREAD
value|3
end_define

begin_define
define|#
directive|define
name|WORKIDX_INC
parameter_list|(
name|x
parameter_list|)
value|(x) = (x + 1) % WORKITEM_LEGACY_THREAD
end_define

begin_comment
comment|/*  * Older, deprecated work item API, needed to support NdisQueueWorkItem().  */
end_comment

begin_struct_decl
struct_decl|struct
name|work_queue_item
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|work_item_func
function_decl|)
parameter_list|(
name|struct
name|work_queue_item
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|work_queue_item
block|{
name|list_entry
name|wqi_entry
decl_stmt|;
name|work_item_func
name|wqi_func
decl_stmt|;
name|void
modifier|*
name|wqi_ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|work_queue_item
name|work_queue_item
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ExInitializeWorkItem
parameter_list|(
name|w
parameter_list|,
name|func
parameter_list|,
name|ctx
parameter_list|)
define|\
value|do {						\ 		(w)->wqi_func = (func);			\ 		(w)->wqi_ctx = (ctx);			\ 		InitializeListHead(&((w)->wqi_entry));	\ 	} while (0);
end_define

begin_comment
unit|\
comment|/*  * FreeBSD's kernel stack is 2 pages in size by default. The  * Windows stack is larger, so we need to give our threads more  * stack pages. 4 should be enough, we use 8 just to extra safe.  */
end_comment

begin_define
define|#
directive|define
name|NDIS_KSTACK_PAGES
value|8
end_define

begin_comment
comment|/*  * Different kinds of function wrapping we can do.  */
end_comment

begin_define
define|#
directive|define
name|WINDRV_WRAP_STDCALL
value|1
end_define

begin_define
define|#
directive|define
name|WINDRV_WRAP_FASTCALL
value|2
end_define

begin_define
define|#
directive|define
name|WINDRV_WRAP_REGPARM
value|3
end_define

begin_define
define|#
directive|define
name|WINDRV_WRAP_CDECL
value|4
end_define

begin_define
define|#
directive|define
name|WINDRV_WRAP_AMD64
value|5
end_define

begin_struct
struct|struct
name|drvdb_ent
block|{
name|driver_object
modifier|*
name|windrv_object
decl_stmt|;
name|void
modifier|*
name|windrv_devlist
decl_stmt|;
name|ndis_cfg
modifier|*
name|windrv_regvals
decl_stmt|;
name|interface_type
name|windrv_bustype
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|drvdb_ent
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|image_patch_table
name|ntoskrnl_functbl
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|funcptr
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|matchfuncptr
function_decl|)
parameter_list|(
name|interface_type
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|__BEGIN_DECLS
specifier|extern
name|int
name|windrv_libinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_libfini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|driver_object
modifier|*
name|windrv_lookup
parameter_list|(
name|vm_offset_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|drvdb_ent
modifier|*
name|windrv_match
parameter_list|(
name|matchfuncptr
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_load
parameter_list|(
name|module_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|,
name|interface_type
parameter_list|,
name|void
modifier|*
parameter_list|,
name|ndis_cfg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_unload
parameter_list|(
name|module_t
parameter_list|,
name|vm_offset_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_create_pdo
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|windrv_destroy_pdo
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|device_object
modifier|*
name|windrv_find_pdo
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_bus_attach
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_wrap
parameter_list|(
name|funcptr
parameter_list|,
name|funcptr
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|windrv_unwrap
parameter_list|(
name|funcptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ctxsw_utow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ctxsw_wtou
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
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
specifier|extern
name|void
name|ntoskrnl_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint16_t
name|ExQueryDepthSList
parameter_list|(
name|slist_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|slist_entry
modifier|*
name|InterlockedPushEntrySList
parameter_list|(
name|slist_header
modifier|*
parameter_list|,
name|slist_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|slist_entry
modifier|*
name|InterlockedPopEntrySList
parameter_list|(
name|slist_header
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|RtlUnicodeStringToAnsiString
parameter_list|(
name|ansi_string
modifier|*
parameter_list|,
name|unicode_string
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|RtlAnsiStringToUnicodeString
parameter_list|(
name|unicode_string
modifier|*
parameter_list|,
name|ansi_string
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RtlInitAnsiString
parameter_list|(
name|ansi_string
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RtlInitUnicodeString
parameter_list|(
name|unicode_string
modifier|*
parameter_list|,
name|uint16_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RtlFreeUnicodeString
parameter_list|(
name|unicode_string
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RtlFreeAnsiString
parameter_list|(
name|ansi_string
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeInitializeDpc
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
specifier|extern
name|uint8_t
name|KeInsertQueueDpc
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
specifier|extern
name|uint8_t
name|KeRemoveQueueDpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeSetImportanceDpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeSetTargetProcessorDpc
parameter_list|(
name|kdpc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeFlushQueuedDpcs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|KeGetCurrentProcessorNumber
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeInitializeTimer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeInitializeTimerEx
parameter_list|(
name|ktimer
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|KeSetTimer
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
specifier|extern
name|uint8_t
name|KeSetTimerEx
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
specifier|extern
name|uint8_t
name|KeCancelTimer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|KeReadStateTimer
parameter_list|(
name|ktimer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|KeWaitForSingleObject
parameter_list|(
name|void
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
specifier|extern
name|void
name|KeInitializeEvent
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
specifier|extern
name|void
name|KeClearEvent
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|KeReadStateEvent
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|KeSetEvent
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
specifier|extern
name|uint32_t
name|KeResetEvent
parameter_list|(
name|nt_kevent
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_function_decl
specifier|extern
name|void
name|KefAcquireSpinLockAtDpcLevel
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KefReleaseSpinLockFromDpcLevel
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|KeAcquireSpinLockRaiseToDpc
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|KeAcquireSpinLockAtDpcLevel
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeReleaseSpinLockFromDpcLevel
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|KeInitializeSpinLock
parameter_list|(
name|kspin_lock
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|KeAcquireInterruptSpinLock
parameter_list|(
name|kinterrupt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|KeReleaseInterruptSpinLock
parameter_list|(
name|kinterrupt
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|KeSynchronizeExecution
parameter_list|(
name|kinterrupt
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
specifier|extern
name|uintptr_t
name|InterlockedExchange
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|ExAllocatePoolWithTag
parameter_list|(
name|uint32_t
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ExFreePool
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|IoConnectInterrupt
parameter_list|(
name|kinterrupt
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|kspin_lock
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|MmMapIoSpace
parameter_list|(
name|uint64_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MmUnmapIoSpace
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|MmBuildMdlForNonPagedPool
parameter_list|(
name|mdl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoDisconnectInterrupt
parameter_list|(
name|kinterrupt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|IoAllocateDriverObjectExtension
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|IoGetDriverObjectExtension
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|IoCreateDevice
parameter_list|(
name|driver_object
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|unicode_string
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|,
name|device_object
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoDeleteDevice
parameter_list|(
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|device_object
modifier|*
name|IoGetAttachedDevice
parameter_list|(
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|IofCallDriver
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|irp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IofCompleteRequest
parameter_list|(
name|irp
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoAcquireCancelSpinLock
parameter_list|(
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoReleaseCancelSpinLock
parameter_list|(
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|IoCancelIrp
parameter_list|(
name|irp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoDetachDevice
parameter_list|(
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|device_object
modifier|*
name|IoAttachDeviceToDeviceStack
parameter_list|(
name|device_object
modifier|*
parameter_list|,
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|mdl
modifier|*
name|IoAllocateMdl
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|irp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoFreeMdl
parameter_list|(
name|mdl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|io_workitem
modifier|*
name|IoAllocateWorkItem
parameter_list|(
name|device_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ExQueueWorkItem
parameter_list|(
name|work_queue_item
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoFreeWorkItem
parameter_list|(
name|io_workitem
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|IoQueueWorkItem
parameter_list|(
name|io_workitem
modifier|*
parameter_list|,
name|io_workitem_func
parameter_list|,
name|uint32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IoCallDriver
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|IofCallDriver(a, b)
end_define

begin_define
define|#
directive|define
name|IoCompleteRequest
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|IofCompleteRequest(a, b)
end_define

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
name|KeAcquireSpinLock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|*(b) = KfAcquireSpinLock(a)
end_define

begin_define
define|#
directive|define
name|KeReleaseSpinLock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|KfReleaseSpinLock(a, b)
end_define

begin_define
define|#
directive|define
name|KeRaiseIrql
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|*(b) = KfRaiseIrql(a)
end_define

begin_define
define|#
directive|define
name|KeLowerIrql
parameter_list|(
name|a
parameter_list|)
value|KfLowerIrql(a)
end_define

begin_define
define|#
directive|define
name|KeAcquireSpinLockAtDpcLevel
parameter_list|(
name|a
parameter_list|)
value|KefAcquireSpinLockAtDpcLevel(a)
end_define

begin_define
define|#
directive|define
name|KeReleaseSpinLockFromDpcLevel
parameter_list|(
name|a
parameter_list|)
value|KefReleaseSpinLockFromDpcLevel(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __i386__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|KeAcquireSpinLock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|*(b) = KfAcquireSpinLock(a)
end_define

begin_define
define|#
directive|define
name|KeReleaseSpinLock
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|KfReleaseSpinLock(a, b)
end_define

begin_comment
comment|/*  * These may need to be redefined later;  * not sure where they live on amd64 yet.  */
end_comment

begin_define
define|#
directive|define
name|KeRaiseIrql
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|*(b) = KfRaiseIrql(a)
end_define

begin_define
define|#
directive|define
name|KeLowerIrql
parameter_list|(
name|a
parameter_list|)
value|KfLowerIrql(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __amd64__ */
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

