begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq_var.h,v 1.16 2003/10/03 05:05:15 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_VAR_H_
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
file|<sys/queue.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
end_ifdef

begin_comment
comment|/*  * filter structure for altq common classifier  */
end_comment

begin_struct
struct|struct
name|acc_filter
block|{
name|LIST_ENTRY
argument_list|(
argument|acc_filter
argument_list|)
name|f_chain
expr_stmt|;
name|void
modifier|*
name|f_class
decl_stmt|;
comment|/* pointer to the class */
name|u_long
name|f_handle
decl_stmt|;
comment|/* filter id */
name|u_int32_t
name|f_fbmask
decl_stmt|;
comment|/* filter bitmask */
name|struct
name|flow_filter
name|f_filter
decl_stmt|;
comment|/* filter value */
block|}
struct|;
end_struct

begin_comment
comment|/*  * XXX ACC_FILTER_TABLESIZE can't be larger than 2048 unless we fix  * the handle assignment.  */
end_comment

begin_define
define|#
directive|define
name|ACC_FILTER_TABLESIZE
value|(256+1)
end_define

begin_define
define|#
directive|define
name|ACC_FILTER_MASK
value|(ACC_FILTER_TABLESIZE - 2)
end_define

begin_define
define|#
directive|define
name|ACC_WILDCARD_INDEX
value|(ACC_FILTER_TABLESIZE - 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|ACC_GET_HASH_INDEX
parameter_list|(
name|addr
parameter_list|)
define|\
value|({int x = (addr) + ((addr)>> 16); (x + (x>> 8))& ACC_FILTER_MASK;})
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACC_GET_HASH_INDEX
parameter_list|(
name|addr
parameter_list|)
define|\
value|(((addr) + ((addr)>> 8) + ((addr)>> 16) + ((addr)>> 24)) \& ACC_FILTER_MASK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ACC_GET_HINDEX
parameter_list|(
name|handle
parameter_list|)
value|((handle)>> 20)
end_define

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|ACC_LOCK_INIT
parameter_list|(
name|ac
parameter_list|)
value|mtx_init(&(ac)->acc_mtx, "classifier", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ACC_LOCK_DESTROY
parameter_list|(
name|ac
parameter_list|)
value|mtx_destroy(&(ac)->acc_mtx)
end_define

begin_define
define|#
directive|define
name|ACC_LOCK
parameter_list|(
name|ac
parameter_list|)
value|mtx_lock(&(ac)->acc_mtx)
end_define

begin_define
define|#
directive|define
name|ACC_UNLOCK
parameter_list|(
name|ac
parameter_list|)
value|mtx_unlock(&(ac)->acc_mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ACC_LOCK_INIT
parameter_list|(
name|ac
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACC_LOCK_DESTROY
parameter_list|(
name|ac
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACC_LOCK
parameter_list|(
name|ac
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ACC_UNLOCK
parameter_list|(
name|ac
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|acc_classifier
block|{
name|u_int32_t
name|acc_fbmask
decl_stmt|;
name|LIST_HEAD
argument_list|(
argument|filt
argument_list|,
argument|acc_filter
argument_list|)
name|acc_filters
index|[
name|ACC_FILTER_TABLESIZE
index|]
expr_stmt|;
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>
literal|500000
operator|)
name|struct
name|mtx
name|acc_mtx
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * flowinfo mask bits used by classifier  */
end_comment

begin_comment
comment|/* for ipv4 */
end_comment

begin_define
define|#
directive|define
name|FIMB4_PROTO
value|0x0001
end_define

begin_define
define|#
directive|define
name|FIMB4_TOS
value|0x0002
end_define

begin_define
define|#
directive|define
name|FIMB4_DADDR
value|0x0004
end_define

begin_define
define|#
directive|define
name|FIMB4_SADDR
value|0x0008
end_define

begin_define
define|#
directive|define
name|FIMB4_DPORT
value|0x0010
end_define

begin_define
define|#
directive|define
name|FIMB4_SPORT
value|0x0020
end_define

begin_define
define|#
directive|define
name|FIMB4_GPI
value|0x0040
end_define

begin_define
define|#
directive|define
name|FIMB4_ALL
value|0x007f
end_define

begin_comment
comment|/* for ipv6 */
end_comment

begin_define
define|#
directive|define
name|FIMB6_PROTO
value|0x0100
end_define

begin_define
define|#
directive|define
name|FIMB6_TCLASS
value|0x0200
end_define

begin_define
define|#
directive|define
name|FIMB6_DADDR
value|0x0400
end_define

begin_define
define|#
directive|define
name|FIMB6_SADDR
value|0x0800
end_define

begin_define
define|#
directive|define
name|FIMB6_DPORT
value|0x1000
end_define

begin_define
define|#
directive|define
name|FIMB6_SPORT
value|0x2000
end_define

begin_define
define|#
directive|define
name|FIMB6_GPI
value|0x4000
end_define

begin_define
define|#
directive|define
name|FIMB6_FLABEL
value|0x8000
end_define

begin_define
define|#
directive|define
name|FIMB6_ALL
value|0xff00
end_define

begin_define
define|#
directive|define
name|FIMB_ALL
value|(FIMB4_ALL|FIMB6_ALL)
end_define

begin_define
define|#
directive|define
name|FIMB4_PORTS
value|(FIMB4_DPORT|FIMB4_SPORT|FIMB4_GPI)
end_define

begin_define
define|#
directive|define
name|FIMB6_PORTS
value|(FIMB6_DPORT|FIMB6_SPORT|FIMB6_GPI)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_CLFIER_COMPAT */
end_comment

begin_comment
comment|/*  * machine dependent clock  * a 64bit high resolution time counter.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|machclk_usepcc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|machclk_freq
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int32_t
name|machclk_per_tick
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|init_machclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int64_t
name|read_machclk
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * debug support  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ_DEBUG
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|e
parameter_list|)
value|((e) ? (void)0 : altq_assert(__FILE__, __LINE__, #e))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* PCC */
end_comment

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|e
parameter_list|)
value|((e) ? (void)0 : altq_assert(__FILE__, __LINE__, "e"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|e
parameter_list|)
value|((void)0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * misc stuff for compatibility  */
end_comment

begin_comment
comment|/* ioctl cmd type */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|__FreeBSD__
operator|<
literal|3
operator|)
end_if

begin_typedef
typedef|typedef
name|int
name|ioctlcmd_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|u_long
name|ioctlcmd_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * queue macros:  * the interface of TAILQ_LAST macro changed after the introduction  * of softupdate. redefine it here to make it work with pre-2.2.7.  */
end_comment

begin_undef
undef|#
directive|undef
name|TAILQ_LAST
end_undef

begin_define
define|#
directive|define
name|TAILQ_LAST
parameter_list|(
name|head
parameter_list|,
name|headname
parameter_list|)
define|\
value|(*(((struct headname *)((head)->tqh_last))->tqh_last))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TAILQ_EMPTY
end_ifndef

begin_define
define|#
directive|define
name|TAILQ_EMPTY
parameter_list|(
name|head
parameter_list|)
value|((head)->tqh_first == NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAILQ_FOREACH
end_ifndef

begin_define
define|#
directive|define
name|TAILQ_FOREACH
parameter_list|(
name|var
parameter_list|,
name|head
parameter_list|,
name|field
parameter_list|)
define|\
value|for (var = TAILQ_FIRST(head); var; var = TAILQ_NEXT(var, field))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* macro for timeout/untimeout */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>
literal|300000
operator|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_comment
comment|/* use callout */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>
literal|500000
operator|)
end_if

begin_define
define|#
directive|define
name|CALLOUT_INIT
parameter_list|(
name|c
parameter_list|)
value|callout_init((c), 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CALLOUT_INIT
parameter_list|(
name|c
parameter_list|)
value|callout_init((c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CALLOUT_RESET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|callout_reset((c),(t),(f),(a))
end_define

begin_define
define|#
directive|define
name|CALLOUT_STOP
parameter_list|(
name|c
parameter_list|)
value|callout_stop((c))
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CALLOUT_INITIALIZER
argument_list|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|600000
operator|)
end_if

begin_define
define|#
directive|define
name|CALLOUT_INITIALIZER
value|{ { { NULL } }, 0, NULL, NULL, 0 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/timeout.h>
end_include

begin_comment
comment|/* callout structure as a wrapper of struct timeout */
end_comment

begin_struct
struct|struct
name|callout
block|{
name|struct
name|timeout
name|c_to
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CALLOUT_INIT
parameter_list|(
name|c
parameter_list|)
value|do { bzero((c), sizeof(*(c))); } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|CALLOUT_RESET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|do { if (!timeout_initialized(&(c)->c_to))  \ 					 timeout_set(&(c)->c_to, (f), (a)); \ 				     timeout_add(&(c)->c_to, (t)); } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|CALLOUT_STOP
parameter_list|(
name|c
parameter_list|)
value|timeout_del(&(c)->c_to)
end_define

begin_define
define|#
directive|define
name|CALLOUT_INITIALIZER
value|{ { { NULL }, NULL, NULL, 0, 0 } }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* use old-style timeout/untimeout */
end_comment

begin_comment
comment|/* dummy callout structure */
end_comment

begin_struct
struct|struct
name|callout
block|{
name|void
modifier|*
name|c_arg
decl_stmt|;
comment|/* function argument */
name|void
function_decl|(
modifier|*
name|c_func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* functiuon to call */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CALLOUT_INIT
parameter_list|(
name|c
parameter_list|)
value|do { bzero((c), sizeof(*(c))); } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|CALLOUT_RESET
parameter_list|(
name|c
parameter_list|,
name|t
parameter_list|,
name|f
parameter_list|,
name|a
parameter_list|)
value|do {	(c)->c_arg = (a);	\ 					(c)->c_func = (f);	\ 					timeout((f),(a),(t)); } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|CALLOUT_STOP
parameter_list|(
name|c
parameter_list|)
value|untimeout((c)->c_func,(c)->c_arg)
end_define

begin_define
define|#
directive|define
name|CALLOUT_INITIALIZER
value|{ NULL, NULL }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|void
function_decl|(
name|timeout_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|m_pktlen
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pf_altq
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
end_ifdef

begin_struct_decl
struct_decl|struct
name|flowinfo
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
modifier|*
name|altq_lookup
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
end_ifdef

begin_function_decl
name|int
name|altq_extractflow
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|flowinfo
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acc_add_filter
parameter_list|(
name|struct
name|acc_classifier
modifier|*
parameter_list|,
name|struct
name|flow_filter
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_long
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acc_delete_filter
parameter_list|(
name|struct
name|acc_classifier
modifier|*
parameter_list|,
name|u_long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|acc_discard_filters
parameter_list|(
name|struct
name|acc_classifier
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|acc_classify
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|u_int8_t
name|read_dsfield
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_dsfield
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|struct
name|altq_pktattr
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|altq_assert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tbr_set
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|tb_profile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tbr_get
parameter_list|(
name|struct
name|ifaltq
modifier|*
parameter_list|,
name|struct
name|tb_profile
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_pfattach
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_pfdetach
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_add
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_remove
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_add_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_remove_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|altq_getqstats
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_pfattach
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_add_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_remove_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_add_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_remove_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cbq_getqstats
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_pfattach
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_add_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_remove_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_add_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_remove_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|priq_getqstats
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_pfattach
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_add_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_remove_altq
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_add_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_remove_queue
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hfsc_getqstats
parameter_list|(
name|struct
name|pf_altq
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
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
comment|/* _ALTQ_ALTQ_VAR_H_ */
end_comment

end_unit

