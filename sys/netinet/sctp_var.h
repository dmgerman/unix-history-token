begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001-2008, by Cisco Systems, Inc. All rights reserved.  * Copyright (c) 2008-2012, by Randall Stewart. All rights reserved.  * Copyright (c) 2008-2012, by Michael Tuexen. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  * a) Redistributions of source code must retain the above copyright notice,  *    this list of conditions and the following disclaimer.  *  * b) Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the distribution.  *  * c) Neither the name of Cisco Systems, Inc. nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
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
name|_NETINET_SCTP_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETINET_SCTP_VAR_H_
end_define

begin_include
include|#
directive|include
file|<netinet/sctp_uio.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__Userspace__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|struct
name|pr_usrreqs
name|sctp_usrreqs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|sctp_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_features |= feature)
end_define

begin_define
define|#
directive|define
name|sctp_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_features&= ~feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|((inp->sctp_features& feature) == feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|((inp->sctp_features& feature) == 0)
end_define

begin_define
define|#
directive|define
name|sctp_stcb_feature_on
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|feature
parameter_list|)
value|{\ 	if (stcb) { \ 		stcb->asoc.sctp_features |= feature; \ 	} else if (inp) { \ 		inp->sctp_features |= feature; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_stcb_feature_off
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|feature
parameter_list|)
value|{\ 	if (stcb) { \ 		stcb->asoc.sctp_features&= ~feature; \ 	} else if (inp) { \ 		inp->sctp_features&= ~feature; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_stcb_is_feature_on
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|feature
parameter_list|)
define|\
value|(((stcb != NULL)&& \ 	  ((stcb->asoc.sctp_features& feature) == feature)) || \ 	 ((stcb == NULL)&& (inp != NULL)&& \ 	  ((inp->sctp_features& feature) == feature)))
end_define

begin_define
define|#
directive|define
name|sctp_stcb_is_feature_off
parameter_list|(
name|inp
parameter_list|,
name|stcb
parameter_list|,
name|feature
parameter_list|)
define|\
value|(((stcb != NULL)&& \ 	  ((stcb->asoc.sctp_features& feature) == 0)) || \ 	 ((stcb == NULL)&& (inp != NULL)&& \ 	  ((inp->sctp_features& feature) == 0)) || \ 	 ((stcb == NULL)&& (inp == NULL)))
end_define

begin_comment
comment|/* managing mobility_feature in inpcb (by micchie) */
end_comment

begin_define
define|#
directive|define
name|sctp_mobility_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_mobility_features |= feature)
end_define

begin_define
define|#
directive|define
name|sctp_mobility_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_mobility_features&= ~feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_mobility_feature_on
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|(inp->sctp_mobility_features& feature)
end_define

begin_define
define|#
directive|define
name|sctp_is_mobility_feature_off
parameter_list|(
name|inp
parameter_list|,
name|feature
parameter_list|)
value|((inp->sctp_mobility_features& feature) == 0)
end_define

begin_define
define|#
directive|define
name|sctp_maxspace
parameter_list|(
name|sb
parameter_list|)
value|(max((sb)->sb_hiwat,SCTP_MINIMAL_RWND))
end_define

begin_define
define|#
directive|define
name|sctp_sbspace
parameter_list|(
name|asoc
parameter_list|,
name|sb
parameter_list|)
value|((long) ((sctp_maxspace(sb)> (asoc)->sb_cc) ? (sctp_maxspace(sb) - (asoc)->sb_cc) : 0))
end_define

begin_define
define|#
directive|define
name|sctp_sbspace_failedmsgs
parameter_list|(
name|sb
parameter_list|)
value|((long) ((sctp_maxspace(sb)> (sb)->sb_cc) ? (sctp_maxspace(sb) - (sb)->sb_cc) : 0))
end_define

begin_define
define|#
directive|define
name|sctp_sbspace_sub
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? ((a) - (b)) : 0)
end_define

begin_comment
comment|/*  * I tried to cache the readq entries at one point. But the reality  * is that it did not add any performance since this meant we had to  * lock the STCB on read. And at that point once you have to do an  * extra lock, it really does not matter if the lock is in the ZONE  * stuff or in our code. Note that this same problem would occur with  * an mbuf cache as well so it is not really worth doing, at least  * right now :-D  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|sctp_free_a_readq
parameter_list|(
name|_stcb
parameter_list|,
name|_readq
parameter_list|)
value|{ \ 	if ((_readq)->on_strm_q) \ 		panic("On strm q stcb:%p readq:%p", (_stcb), (_readq)); \ 	SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_readq), (_readq)); \ 	SCTP_DECR_READQ_COUNT(); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sctp_free_a_readq
parameter_list|(
name|_stcb
parameter_list|,
name|_readq
parameter_list|)
value|{ \ 	SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_readq), (_readq)); \ 	SCTP_DECR_READQ_COUNT(); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sctp_alloc_a_readq
parameter_list|(
name|_stcb
parameter_list|,
name|_readq
parameter_list|)
value|{ \ 	(_readq) = SCTP_ZONE_GET(SCTP_BASE_INFO(ipi_zone_readq), struct sctp_queued_to_read); \ 	if ((_readq)) { \ 	     SCTP_INCR_READQ_COUNT(); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_a_strmoq
parameter_list|(
name|_stcb
parameter_list|,
name|_strmoq
parameter_list|,
name|_so_locked
parameter_list|)
value|{ \ 	if ((_strmoq)->holds_key_ref) { \ 		sctp_auth_key_release(stcb, sp->auth_keyid, _so_locked); \ 		(_strmoq)->holds_key_ref = 0; \ 	} \ 	SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_strmoq), (_strmoq)); \ 	SCTP_DECR_STRMOQ_COUNT(); \ }
end_define

begin_define
define|#
directive|define
name|sctp_alloc_a_strmoq
parameter_list|(
name|_stcb
parameter_list|,
name|_strmoq
parameter_list|)
value|{ \ 	(_strmoq) = SCTP_ZONE_GET(SCTP_BASE_INFO(ipi_zone_strmoq), struct sctp_stream_queue_pending); \ 	if ((_strmoq)) { \ 		memset(_strmoq, 0, sizeof(struct sctp_stream_queue_pending)); \ 		SCTP_INCR_STRMOQ_COUNT(); \ 		(_strmoq)->holds_key_ref = 0; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_a_chunk
parameter_list|(
name|_stcb
parameter_list|,
name|_chk
parameter_list|,
name|_so_locked
parameter_list|)
value|{ \ 	if ((_chk)->holds_key_ref) {\ 		sctp_auth_key_release((_stcb), (_chk)->auth_keyid, _so_locked); \ 		(_chk)->holds_key_ref = 0; \ 	} \ 	if (_stcb) { \ 		SCTP_TCB_LOCK_ASSERT((_stcb)); \ 		if ((_chk)->whoTo) { \ 			sctp_free_remote_addr((_chk)->whoTo); \ 			(_chk)->whoTo = NULL; \ 		} \ 		if (((_stcb)->asoc.free_chunk_cnt> SCTP_BASE_SYSCTL(sctp_asoc_free_resc_limit)) || \ 		    (SCTP_BASE_INFO(ipi_free_chunks)> SCTP_BASE_SYSCTL(sctp_system_free_resc_limit))) { \ 			SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_chunk), (_chk)); \ 			SCTP_DECR_CHK_COUNT(); \ 		} else { \ 			TAILQ_INSERT_TAIL(&(_stcb)->asoc.free_chunks, (_chk), sctp_next); \ 			(_stcb)->asoc.free_chunk_cnt++; \ 			atomic_add_int(&SCTP_BASE_INFO(ipi_free_chunks), 1); \ 		} \ 	} else { \ 		SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_chunk), (_chk)); \ 		SCTP_DECR_CHK_COUNT(); \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_alloc_a_chunk
parameter_list|(
name|_stcb
parameter_list|,
name|_chk
parameter_list|)
value|{ \ 	if (TAILQ_EMPTY(&(_stcb)->asoc.free_chunks)) { \ 		(_chk) = SCTP_ZONE_GET(SCTP_BASE_INFO(ipi_zone_chunk), struct sctp_tmit_chunk); \ 		if ((_chk)) { \ 			SCTP_INCR_CHK_COUNT(); \ 			(_chk)->whoTo = NULL; \ 			(_chk)->holds_key_ref = 0; \ 		} \ 	} else { \ 		(_chk) = TAILQ_FIRST(&(_stcb)->asoc.free_chunks); \ 		TAILQ_REMOVE(&(_stcb)->asoc.free_chunks, (_chk), sctp_next); \ 		atomic_subtract_int(&SCTP_BASE_INFO(ipi_free_chunks), 1); \ 		(_chk)->holds_key_ref = 0; \ 		SCTP_STAT_INCR(sctps_cached_chk); \ 		(_stcb)->asoc.free_chunk_cnt--; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_free_remote_addr
parameter_list|(
name|__net
parameter_list|)
value|{ \ 	if ((__net)) {  \ 		if (SCTP_DECREMENT_AND_CHECK_REFCOUNT(&(__net)->ref_count)) { \ 			(void)SCTP_OS_TIMER_STOP(&(__net)->rxt_timer.timer); \ 			(void)SCTP_OS_TIMER_STOP(&(__net)->pmtu_timer.timer); \ 			(void)SCTP_OS_TIMER_STOP(&(__net)->hb_timer.timer); \ 			if ((__net)->ro.ro_rt) { \ 				RTFREE((__net)->ro.ro_rt); \ 				(__net)->ro.ro_rt = NULL; \ 			} \ 			if ((__net)->src_addr_selected) { \ 				sctp_free_ifa((__net)->ro._s_addr); \ 				(__net)->ro._s_addr = NULL; \ 			} \ 			(__net)->src_addr_selected = 0; \ 			(__net)->dest_state&= ~SCTP_ADDR_REACHABLE; \ 			SCTP_ZONE_FREE(SCTP_BASE_INFO(ipi_zone_net), (__net)); \ 			SCTP_DECR_RADDR_COUNT(); \ 		} \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_sbfree
parameter_list|(
name|ctl
parameter_list|,
name|stcb
parameter_list|,
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	SCTP_SAVE_ATOMIC_DECREMENT(&(sb)->sb_cc, SCTP_BUF_LEN((m))); \ 	SCTP_SAVE_ATOMIC_DECREMENT(&(sb)->sb_mbcnt, MSIZE); \ 	if (((ctl)->do_not_ref_stcb == 0)&& stcb) {\ 		SCTP_SAVE_ATOMIC_DECREMENT(&(stcb)->asoc.sb_cc, SCTP_BUF_LEN((m))); \ 		SCTP_SAVE_ATOMIC_DECREMENT(&(stcb)->asoc.my_rwnd_control_len, MSIZE); \ 	} \ 	if (SCTP_BUF_TYPE(m) != MT_DATA&& SCTP_BUF_TYPE(m) != MT_HEADER&& \ 	    SCTP_BUF_TYPE(m) != MT_OOBDATA) \ 		atomic_subtract_int(&(sb)->sb_ctl,SCTP_BUF_LEN((m))); \ }
end_define

begin_define
define|#
directive|define
name|sctp_sballoc
parameter_list|(
name|stcb
parameter_list|,
name|sb
parameter_list|,
name|m
parameter_list|)
value|{ \ 	atomic_add_int(&(sb)->sb_cc,SCTP_BUF_LEN((m))); \ 	atomic_add_int(&(sb)->sb_mbcnt, MSIZE); \ 	if (stcb) { \ 		atomic_add_int(&(stcb)->asoc.sb_cc, SCTP_BUF_LEN((m))); \ 		atomic_add_int(&(stcb)->asoc.my_rwnd_control_len, MSIZE); \ 	} \ 	if (SCTP_BUF_TYPE(m) != MT_DATA&& SCTP_BUF_TYPE(m) != MT_HEADER&& \ 	    SCTP_BUF_TYPE(m) != MT_OOBDATA) \ 		atomic_add_int(&(sb)->sb_ctl,SCTP_BUF_LEN((m))); \ }
end_define

begin_define
define|#
directive|define
name|sctp_ucount_incr
parameter_list|(
name|val
parameter_list|)
value|{ \ 	val++; \ }
end_define

begin_define
define|#
directive|define
name|sctp_ucount_decr
parameter_list|(
name|val
parameter_list|)
value|{ \ 	if (val> 0) { \ 		val--; \ 	} else { \ 		val = 0; \ 	} \ }
end_define

begin_define
define|#
directive|define
name|sctp_mbuf_crush
parameter_list|(
name|data
parameter_list|)
value|do { \ 	struct mbuf *_m; \ 	_m = (data); \ 	while (_m&& (SCTP_BUF_LEN(_m) == 0)) { \ 		(data)  = SCTP_BUF_NEXT(_m); \ 		SCTP_BUF_NEXT(_m) = NULL; \ 		sctp_m_free(_m); \ 		_m = (data); \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_flight_size_decrease
parameter_list|(
name|tp1
parameter_list|)
value|do { \ 	if (tp1->whoTo->flight_size>= tp1->book_size) \ 		tp1->whoTo->flight_size -= tp1->book_size; \ 	else \ 		tp1->whoTo->flight_size = 0; \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_flight_size_increase
parameter_list|(
name|tp1
parameter_list|)
value|do { \ 	(tp1)->whoTo->flight_size += (tp1)->book_size; \ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SCTP_FS_SPEC_LOG
end_ifdef

begin_define
define|#
directive|define
name|sctp_total_flight_decrease
parameter_list|(
name|stcb
parameter_list|,
name|tp1
parameter_list|)
value|do { \ 	if (stcb->asoc.fs_index> SCTP_FS_SPEC_LOG_SIZE) \ 		stcb->asoc.fs_index = 0;\ 	stcb->asoc.fslog[stcb->asoc.fs_index].total_flight = stcb->asoc.total_flight; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].tsn = tp1->rec.data.tsn; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].book = tp1->book_size; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].sent = tp1->sent; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].incr = 0; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].decr = 1; \ 	stcb->asoc.fs_index++; \ 	tp1->window_probe = 0; \ 	if (stcb->asoc.total_flight>= tp1->book_size) { \ 		stcb->asoc.total_flight -= tp1->book_size; \ 		if (stcb->asoc.total_flight_count> 0) \ 			stcb->asoc.total_flight_count--; \ 	} else { \ 		stcb->asoc.total_flight = 0; \ 		stcb->asoc.total_flight_count = 0; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_total_flight_increase
parameter_list|(
name|stcb
parameter_list|,
name|tp1
parameter_list|)
value|do { \ 	if (stcb->asoc.fs_index> SCTP_FS_SPEC_LOG_SIZE) \ 		stcb->asoc.fs_index = 0;\ 	stcb->asoc.fslog[stcb->asoc.fs_index].total_flight = stcb->asoc.total_flight; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].tsn = tp1->rec.data.tsn; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].book = tp1->book_size; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].sent = tp1->sent; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].incr = 1; \ 	stcb->asoc.fslog[stcb->asoc.fs_index].decr = 0; \ 	stcb->asoc.fs_index++; \ 	(stcb)->asoc.total_flight_count++; \ 	(stcb)->asoc.total_flight += (tp1)->book_size; \ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|sctp_total_flight_decrease
parameter_list|(
name|stcb
parameter_list|,
name|tp1
parameter_list|)
value|do { \ 	tp1->window_probe = 0; \ 	if (stcb->asoc.total_flight>= tp1->book_size) { \ 		stcb->asoc.total_flight -= tp1->book_size; \ 		if (stcb->asoc.total_flight_count> 0) \ 			stcb->asoc.total_flight_count--; \ 	} else { \ 		stcb->asoc.total_flight = 0; \ 		stcb->asoc.total_flight_count = 0; \ 	} \ } while (0)
end_define

begin_define
define|#
directive|define
name|sctp_total_flight_increase
parameter_list|(
name|stcb
parameter_list|,
name|tp1
parameter_list|)
value|do { \ 	(stcb)->asoc.total_flight_count++; \ 	(stcb)->asoc.total_flight += (tp1)->book_size; \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCTP_PF_ENABLED
parameter_list|(
name|_net
parameter_list|)
value|(_net->pf_threshold< _net->failure_threshold)
end_define

begin_define
define|#
directive|define
name|SCTP_NET_IS_PF
parameter_list|(
name|_net
parameter_list|)
value|(_net->pf_threshold< _net->error_count)
end_define

begin_struct_decl
struct_decl|struct
name|sctp_nets
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctp_inpcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctp_tcb
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sctphdr
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|sctp_close
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_disconnect
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_ctlinput
parameter_list|(
name|int
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_ctloutput
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockopt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_function_decl
name|void
name|sctp_input_with_port
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_input
parameter_list|(
name|struct
name|mbuf
modifier|*
modifier|*
parameter_list|,
name|int
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
name|void
name|sctp_pathmtu_adjustment
parameter_list|(
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_drain
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sctp_notify
parameter_list|(
name|struct
name|sctp_inpcb
modifier|*
parameter_list|,
name|struct
name|sctp_tcb
modifier|*
parameter_list|,
name|struct
name|sctp_nets
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_flush
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_shutdown
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_bindx
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* can't use sctp_assoc_t here */
end_comment

begin_function_decl
name|int
name|sctp_peeloff
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_ingetaddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_peeraddr
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_listen
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sctp_accept
parameter_list|(
name|struct
name|socket
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
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
comment|/* !_NETINET_SCTP_VAR_H_ */
end_comment

end_unit

