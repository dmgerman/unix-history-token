begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$OpenBSD: ubsecvar.h,v 1.35 2002/09/24 18:33:26 jason Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Theo de Raadt  * Copyright (c) 2001 Patrik Lindergren (patrik@ipunplugged.com)  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Effort sponsored in part by the Defense Advanced Research Projects  * Agency (DARPA) and Air Force Research Laboratory, Air Force  * Materiel Command, USAF, under agreement number F30602-01-2-0537.  *  */
end_comment

begin_comment
comment|/* Maximum queue length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UBS_MAX_NQUEUE
end_ifndef

begin_define
define|#
directive|define
name|UBS_MAX_NQUEUE
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UBS_MAX_SCATTER
value|64
end_define

begin_comment
comment|/* Maximum scatter/gather depth */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UBS_MAX_AGGR
end_ifndef

begin_define
define|#
directive|define
name|UBS_MAX_AGGR
value|5
end_define

begin_comment
comment|/* Maximum aggregation count */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UBSEC_CARD
parameter_list|(
name|sid
parameter_list|)
value|(((sid)& 0xf0000000)>> 28)
end_define

begin_define
define|#
directive|define
name|UBSEC_SESSION
parameter_list|(
name|sid
parameter_list|)
value|( (sid)& 0x0fffffff)
end_define

begin_define
define|#
directive|define
name|UBSEC_SID
parameter_list|(
name|crd
parameter_list|,
name|sesn
parameter_list|)
value|(((crd)<< 28) | ((sesn)& 0x0fffffff))
end_define

begin_define
define|#
directive|define
name|UBS_DEF_RTY
value|0xff
end_define

begin_comment
comment|/* PCI Retry Timeout */
end_comment

begin_define
define|#
directive|define
name|UBS_DEF_TOUT
value|0xff
end_define

begin_comment
comment|/* PCI TRDY Timeout */
end_comment

begin_define
define|#
directive|define
name|UBS_DEF_CACHELINE
value|0x01
end_define

begin_comment
comment|/* Cache Line setting */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|ubsec_dma_alloc
block|{
name|u_int32_t
name|dma_paddr
decl_stmt|;
name|caddr_t
name|dma_vaddr
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|bus_dma_segment_t
name|dma_seg
decl_stmt|;
name|bus_size_t
name|dma_size
decl_stmt|;
name|int
name|dma_nseg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_q2
block|{
name|SIMPLEQ_ENTRY
argument_list|(
argument|ubsec_q2
argument_list|)
name|q_next
expr_stmt|;
name|struct
name|ubsec_dma_alloc
name|q_mcr
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|q_ctx
decl_stmt|;
name|u_int
name|q_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_q2_rng
block|{
name|struct
name|ubsec_q2
name|rng_q
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|rng_buf
decl_stmt|;
name|int
name|rng_used
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* C = (M ^ E) mod N */
end_comment

begin_define
define|#
directive|define
name|UBS_MODEXP_PAR_M
value|0
end_define

begin_define
define|#
directive|define
name|UBS_MODEXP_PAR_E
value|1
end_define

begin_define
define|#
directive|define
name|UBS_MODEXP_PAR_N
value|2
end_define

begin_define
define|#
directive|define
name|UBS_MODEXP_PAR_C
value|3
end_define

begin_struct
struct|struct
name|ubsec_q2_modexp
block|{
name|struct
name|ubsec_q2
name|me_q
decl_stmt|;
name|struct
name|cryptkop
modifier|*
name|me_krp
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|me_M
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|me_E
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|me_C
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|me_epb
decl_stmt|;
name|int
name|me_modbits
decl_stmt|;
name|int
name|me_shiftbits
decl_stmt|;
name|int
name|me_normbits
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_P
value|0
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_Q
value|1
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_DP
value|2
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_DQ
value|3
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_PINV
value|4
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_MSGIN
value|5
end_define

begin_define
define|#
directive|define
name|UBS_RSAPRIV_PAR_MSGOUT
value|6
end_define

begin_struct
struct|struct
name|ubsec_q2_rsapriv
block|{
name|struct
name|ubsec_q2
name|rpr_q
decl_stmt|;
name|struct
name|cryptkop
modifier|*
name|rpr_krp
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|rpr_msgin
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|rpr_msgout
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBSEC_RNG_BUFSIZ
value|16
end_define

begin_comment
comment|/* measured in 32bit words */
end_comment

begin_struct
struct|struct
name|ubsec_dmachunk
block|{
name|struct
name|ubsec_mcr
name|d_mcr
decl_stmt|;
name|struct
name|ubsec_mcr_add
name|d_mcradd
index|[
name|UBS_MAX_AGGR
operator|-
literal|1
index|]
decl_stmt|;
name|struct
name|ubsec_pktbuf
name|d_sbuf
index|[
name|UBS_MAX_SCATTER
operator|-
literal|1
index|]
decl_stmt|;
name|struct
name|ubsec_pktbuf
name|d_dbuf
index|[
name|UBS_MAX_SCATTER
operator|-
literal|1
index|]
decl_stmt|;
name|u_int32_t
name|d_macbuf
index|[
literal|5
index|]
decl_stmt|;
union|union
block|{
name|struct
name|ubsec_pktctx_long
name|ctxl
decl_stmt|;
name|struct
name|ubsec_pktctx
name|ctx
decl_stmt|;
block|}
name|d_ctx
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_dma
block|{
name|SIMPLEQ_ENTRY
argument_list|(
argument|ubsec_dma
argument_list|)
name|d_next
expr_stmt|;
name|struct
name|ubsec_dmachunk
modifier|*
name|d_dma
decl_stmt|;
name|struct
name|ubsec_dma_alloc
name|d_alloc
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBS_FLAGS_KEY
value|0x01
end_define

begin_comment
comment|/* has key accelerator */
end_comment

begin_define
define|#
directive|define
name|UBS_FLAGS_LONGCTX
value|0x02
end_define

begin_comment
comment|/* uses long ipsec ctx */
end_comment

begin_define
define|#
directive|define
name|UBS_FLAGS_BIGKEY
value|0x04
end_define

begin_comment
comment|/* 2048bit keys */
end_comment

begin_define
define|#
directive|define
name|UBS_FLAGS_HWNORM
value|0x08
end_define

begin_comment
comment|/* hardware normalization */
end_comment

begin_define
define|#
directive|define
name|UBS_FLAGS_RNG
value|0x10
end_define

begin_comment
comment|/* hardware rng */
end_comment

begin_struct
struct|struct
name|ubsec_operand
block|{
union|union
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|struct
name|uio
modifier|*
name|io
decl_stmt|;
block|}
name|u
union|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_size_t
name|mapsize
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
name|bus_dma_segment_t
name|segs
index|[
name|UBS_MAX_SCATTER
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ubsec_q
block|{
name|SIMPLEQ_ENTRY
argument_list|(
argument|ubsec_q
argument_list|)
name|q_next
expr_stmt|;
name|int
name|q_nstacked_mcrs
decl_stmt|;
name|struct
name|ubsec_q
modifier|*
name|q_stacked_mcr
index|[
name|UBS_MAX_AGGR
operator|-
literal|1
index|]
decl_stmt|;
name|struct
name|cryptop
modifier|*
name|q_crp
decl_stmt|;
name|struct
name|ubsec_dma
modifier|*
name|q_dma
decl_stmt|;
name|struct
name|ubsec_operand
name|q_src
decl_stmt|;
name|struct
name|ubsec_operand
name|q_dst
decl_stmt|;
name|int
name|q_sesn
decl_stmt|;
name|int
name|q_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|q_src_m
value|q_src.u.m
end_define

begin_define
define|#
directive|define
name|q_src_io
value|q_src.u.io
end_define

begin_define
define|#
directive|define
name|q_src_map
value|q_src.map
end_define

begin_define
define|#
directive|define
name|q_src_nsegs
value|q_src.nsegs
end_define

begin_define
define|#
directive|define
name|q_src_segs
value|q_src.segs
end_define

begin_define
define|#
directive|define
name|q_src_mapsize
value|q_src.mapsize
end_define

begin_define
define|#
directive|define
name|q_dst_m
value|q_dst.u.m
end_define

begin_define
define|#
directive|define
name|q_dst_io
value|q_dst.u.io
end_define

begin_define
define|#
directive|define
name|q_dst_map
value|q_dst.map
end_define

begin_define
define|#
directive|define
name|q_dst_nsegs
value|q_dst.nsegs
end_define

begin_define
define|#
directive|define
name|q_dst_segs
value|q_dst.segs
end_define

begin_define
define|#
directive|define
name|q_dst_mapsize
value|q_dst.mapsize
end_define

begin_struct_decl
struct_decl|struct
name|rndstate_test
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ubsec_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device backpointer */
name|struct
name|resource
modifier|*
name|sc_irq
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt handler cookie */
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
comment|/* memory handle */
name|bus_space_tag_t
name|sc_st
decl_stmt|;
comment|/* memory tag */
name|struct
name|resource
modifier|*
name|sc_sr
decl_stmt|;
comment|/* memory resource */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* dma tag */
name|int
name|sc_flags
decl_stmt|;
comment|/* device specific flags */
name|int
name|sc_suspended
decl_stmt|;
name|int
name|sc_needwakeup
decl_stmt|;
comment|/* notify crypto layer */
name|u_int32_t
name|sc_statmask
decl_stmt|;
comment|/* interrupt status mask */
name|int32_t
name|sc_cid
decl_stmt|;
comment|/* crypto tag */
name|struct
name|mtx
name|sc_mcr1lock
decl_stmt|;
comment|/* mcr1 operation lock */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q
argument_list|)
name|sc_queue
expr_stmt|;
comment|/* packet queue, mcr1 */
name|int
name|sc_nqueue
decl_stmt|;
comment|/* count enqueued, mcr1 */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q
argument_list|)
name|sc_qchip
expr_stmt|;
comment|/* on chip, mcr1 */
name|int
name|sc_nqchip
decl_stmt|;
comment|/* count on chip, mcr1 */
name|struct
name|mtx
name|sc_freeqlock
decl_stmt|;
comment|/* freequeue lock */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q
argument_list|)
name|sc_freequeue
expr_stmt|;
comment|/* list of free queue elements */
name|struct
name|mtx
name|sc_mcr2lock
decl_stmt|;
comment|/* mcr2 operation lock */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q2
argument_list|)
name|sc_queue2
expr_stmt|;
comment|/* packet queue, mcr2 */
name|int
name|sc_nqueue2
decl_stmt|;
comment|/* count enqueued, mcr2 */
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q2
argument_list|)
name|sc_qchip2
expr_stmt|;
comment|/* on chip, mcr2 */
name|int
name|sc_nsessions
decl_stmt|;
comment|/* # of sessions */
name|struct
name|ubsec_session
modifier|*
name|sc_sessions
decl_stmt|;
comment|/* sessions */
name|struct
name|callout
name|sc_rngto
decl_stmt|;
comment|/* rng timeout */
name|int
name|sc_rnghz
decl_stmt|;
comment|/* rng poll time */
name|struct
name|ubsec_q2_rng
name|sc_rng
decl_stmt|;
name|struct
name|rndtest_state
modifier|*
name|sc_rndtest
decl_stmt|;
comment|/* RNG test state */
name|void
function_decl|(
modifier|*
name|sc_harvest
function_decl|)
parameter_list|(
name|struct
name|rndtest_state
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
name|struct
name|ubsec_dma
name|sc_dmaa
index|[
name|UBS_MAX_NQUEUE
index|]
decl_stmt|;
name|struct
name|ubsec_q
modifier|*
name|sc_queuea
index|[
name|UBS_MAX_NQUEUE
index|]
decl_stmt|;
name|SIMPLEQ_HEAD
argument_list|(
argument_list|,
argument|ubsec_q2
argument_list|)
name|sc_q2free
expr_stmt|;
comment|/* free list */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UBSEC_QFLAGS_COPYOUTIV
value|0x1
end_define

begin_struct
struct|struct
name|ubsec_session
block|{
name|u_int32_t
name|ses_used
decl_stmt|;
name|u_int32_t
name|ses_deskey
index|[
literal|6
index|]
decl_stmt|;
comment|/* 3DES key */
name|u_int32_t
name|ses_hminner
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac inner state */
name|u_int32_t
name|ses_hmouter
index|[
literal|5
index|]
decl_stmt|;
comment|/* hmac outer state */
name|u_int32_t
name|ses_iv
index|[
literal|2
index|]
decl_stmt|;
comment|/* [3]DES iv */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_struct
struct|struct
name|ubsec_stats
block|{
name|u_int64_t
name|hst_ibytes
decl_stmt|;
name|u_int64_t
name|hst_obytes
decl_stmt|;
name|u_int32_t
name|hst_ipackets
decl_stmt|;
name|u_int32_t
name|hst_opackets
decl_stmt|;
name|u_int32_t
name|hst_invalid
decl_stmt|;
comment|/* invalid argument */
name|u_int32_t
name|hst_badsession
decl_stmt|;
comment|/* invalid session id */
name|u_int32_t
name|hst_badflags
decl_stmt|;
comment|/* flags indicate !(mbuf | uio) */
name|u_int32_t
name|hst_nodesc
decl_stmt|;
comment|/* op submitted w/o descriptors */
name|u_int32_t
name|hst_badalg
decl_stmt|;
comment|/* unsupported algorithm */
name|u_int32_t
name|hst_nomem
decl_stmt|;
name|u_int32_t
name|hst_queuefull
decl_stmt|;
name|u_int32_t
name|hst_dmaerr
decl_stmt|;
name|u_int32_t
name|hst_mcrerr
decl_stmt|;
name|u_int32_t
name|hst_nodmafree
decl_stmt|;
name|u_int32_t
name|hst_lenmismatch
decl_stmt|;
comment|/* enc/auth lengths different */
name|u_int32_t
name|hst_skipmismatch
decl_stmt|;
comment|/* enc part begins before auth part */
name|u_int32_t
name|hst_iovmisaligned
decl_stmt|;
comment|/* iov op not aligned */
name|u_int32_t
name|hst_noirq
decl_stmt|;
comment|/* IRQ for no reason */
name|u_int32_t
name|hst_unaligned
decl_stmt|;
comment|/* unaligned src caused copy */
name|u_int32_t
name|hst_nomap
decl_stmt|;
comment|/* bus_dmamap_create failed */
name|u_int32_t
name|hst_noload
decl_stmt|;
comment|/* bus_dmamap_load_* failed */
name|u_int32_t
name|hst_nombuf
decl_stmt|;
comment|/* MGET* failed */
name|u_int32_t
name|hst_nomcl
decl_stmt|;
comment|/* MCLGET* failed */
name|u_int32_t
name|hst_totbatch
decl_stmt|;
comment|/* ops submitted w/o interrupt */
name|u_int32_t
name|hst_maxbatch
decl_stmt|;
comment|/* max ops submitted together */
name|u_int32_t
name|hst_maxqueue
decl_stmt|;
comment|/* max ops queued for submission */
name|u_int32_t
name|hst_maxqchip
decl_stmt|;
comment|/* max mcr1 ops out for processing */
name|u_int32_t
name|hst_mcr1full
decl_stmt|;
comment|/* MCR1 too busy to take ops */
name|u_int32_t
name|hst_rng
decl_stmt|;
comment|/* RNG requests */
name|u_int32_t
name|hst_modexp
decl_stmt|;
comment|/* MOD EXP requests */
name|u_int32_t
name|hst_modexpcrt
decl_stmt|;
comment|/* MOD EXP CRT requests */
block|}
struct|;
end_struct

end_unit

