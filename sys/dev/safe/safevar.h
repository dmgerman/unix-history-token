begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Sam Leffler, Errno Consulting  * Copyright (c) 2003 Global Technology Associates, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAFE_SAFEVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAFE_SAFEVAR_H_
end_define

begin_comment
comment|/* Maximum queue length */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SAFE_MAX_NQUEUE
end_ifndef

begin_define
define|#
directive|define
name|SAFE_MAX_NQUEUE
value|60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SAFE_MAX_PART
value|64
end_define

begin_comment
comment|/* Maximum scatter/gather depth */
end_comment

begin_define
define|#
directive|define
name|SAFE_DMA_BOUNDARY
value|0
end_define

begin_comment
comment|/* No boundary for source DMA ops */
end_comment

begin_define
define|#
directive|define
name|SAFE_MAX_DSIZE
value|MCLBYTES
end_define

begin_comment
comment|/* Fixed scatter particle size */
end_comment

begin_define
define|#
directive|define
name|SAFE_MAX_SSIZE
value|0x0ffff
end_define

begin_comment
comment|/* Maximum gather particle size */
end_comment

begin_define
define|#
directive|define
name|SAFE_MAX_DMA
value|0xfffff
end_define

begin_comment
comment|/* Maximum PE operand size (20 bits) */
end_comment

begin_comment
comment|/* total src+dst particle descriptors */
end_comment

begin_define
define|#
directive|define
name|SAFE_TOTAL_DPART
value|(SAFE_MAX_NQUEUE * SAFE_MAX_PART)
end_define

begin_define
define|#
directive|define
name|SAFE_TOTAL_SPART
value|(SAFE_MAX_NQUEUE * SAFE_MAX_PART)
end_define

begin_define
define|#
directive|define
name|SAFE_RNG_MAXBUFSIZ
value|128
end_define

begin_comment
comment|/* 32-bit words */
end_comment

begin_define
define|#
directive|define
name|SAFE_CARD
parameter_list|(
name|sid
parameter_list|)
value|(((sid)& 0xf0000000)>> 28)
end_define

begin_define
define|#
directive|define
name|SAFE_SESSION
parameter_list|(
name|sid
parameter_list|)
value|( (sid)& 0x0fffffff)
end_define

begin_define
define|#
directive|define
name|SAFE_SID
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
name|SAFE_DEF_RTY
value|0xff
end_define

begin_comment
comment|/* PCI Retry Timeout */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEF_TOUT
value|0xff
end_define

begin_comment
comment|/* PCI TRDY Timeout */
end_comment

begin_define
define|#
directive|define
name|SAFE_DEF_CACHELINE
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

begin_comment
comment|/*  * State associated with the allocation of each chunk  * of memory setup for DMA.  */
end_comment

begin_struct
struct|struct
name|safe_dma_alloc
block|{
name|u_int32_t
name|dma_paddr
decl_stmt|;
comment|/* physical address */
name|caddr_t
name|dma_vaddr
decl_stmt|;
comment|/* virtual address */
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
comment|/* bus dma tag used */
name|bus_dmamap_t
name|dma_map
decl_stmt|;
comment|/* associated map */
name|bus_dma_segment_t
name|dma_seg
decl_stmt|;
name|bus_size_t
name|dma_size
decl_stmt|;
comment|/* mapped memory size (bytes) */
name|int
name|dma_nseg
decl_stmt|;
comment|/* number of segments */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cryptographic operand state.  One of these exists for each  * source and destination operand passed in from the crypto  * subsystem.  When possible source and destination operands  * refer to the same memory.  More often they are distinct.  * We track the virtual address of each operand as well as  * where each is mapped for DMA.  */
end_comment

begin_struct
struct|struct
name|safe_operand
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
name|SAFE_MAX_PART
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Packet engine ring entry and cryptographic operation state.  * The packet engine requires a ring of descriptors that contain  * pointers to various cryptographic state.  However the ring  * configuration register allows you to specify an arbitrary size  * for ring entries.  We use this feature to collect most of the  * state for each cryptographic request into one spot.  Other than  * ring entries only the ``particle descriptors'' (scatter/gather  * lists) and the actual operand data are kept separate.  The  * particle descriptors must also be organized in rings.  The  * operand data can be located aribtrarily (modulo alignment constraints).  *  * Note that the descriptor ring is mapped onto the PCI bus so  * the hardware can DMA data.  This means the entire ring must be  * contiguous.  */
end_comment

begin_struct
struct|struct
name|safe_ringentry
block|{
name|struct
name|safe_desc
name|re_desc
decl_stmt|;
comment|/* command descriptor */
name|struct
name|safe_sarec
name|re_sa
decl_stmt|;
comment|/* SA record */
name|struct
name|safe_sastate
name|re_sastate
decl_stmt|;
comment|/* SA state record */
name|struct
name|cryptop
modifier|*
name|re_crp
decl_stmt|;
comment|/* crypto operation */
name|struct
name|safe_operand
name|re_src
decl_stmt|;
comment|/* source operand */
name|struct
name|safe_operand
name|re_dst
decl_stmt|;
comment|/* destination operand */
name|int
name|re_sesn
decl_stmt|;
comment|/* crypto session ID */
name|int
name|re_flags
decl_stmt|;
define|#
directive|define
name|SAFE_QFLAGS_COPYOUTIV
value|0x1
comment|/* copy back on completion */
define|#
directive|define
name|SAFE_QFLAGS_COPYOUTICV
value|0x2
comment|/* copy back on completion */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|re_src_m
value|re_src.u.m
end_define

begin_define
define|#
directive|define
name|re_src_io
value|re_src.u.io
end_define

begin_define
define|#
directive|define
name|re_src_map
value|re_src.map
end_define

begin_define
define|#
directive|define
name|re_src_nsegs
value|re_src.nsegs
end_define

begin_define
define|#
directive|define
name|re_src_segs
value|re_src.segs
end_define

begin_define
define|#
directive|define
name|re_src_mapsize
value|re_src.mapsize
end_define

begin_define
define|#
directive|define
name|re_dst_m
value|re_dst.u.m
end_define

begin_define
define|#
directive|define
name|re_dst_io
value|re_dst.u.io
end_define

begin_define
define|#
directive|define
name|re_dst_map
value|re_dst.map
end_define

begin_define
define|#
directive|define
name|re_dst_nsegs
value|re_dst.nsegs
end_define

begin_define
define|#
directive|define
name|re_dst_segs
value|re_dst.segs
end_define

begin_define
define|#
directive|define
name|re_dst_mapsize
value|re_dst.mapsize
end_define

begin_struct_decl
struct_decl|struct
name|rndstate_test
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|safe_session
block|{
name|u_int32_t
name|ses_used
decl_stmt|;
name|u_int32_t
name|ses_klen
decl_stmt|;
comment|/* key length in bits */
name|u_int32_t
name|ses_key
index|[
literal|8
index|]
decl_stmt|;
comment|/* DES/3DES/AES key */
name|u_int32_t
name|ses_mlen
decl_stmt|;
comment|/* hmac length in bytes */
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
literal|4
index|]
decl_stmt|;
comment|/* DES/3DES/AES iv */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|safe_softc
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
name|sc_srcdmat
decl_stmt|;
comment|/* source dma tag */
name|bus_dma_tag_t
name|sc_dstdmat
decl_stmt|;
comment|/* destination dma tag */
name|u_int
name|sc_chiprev
decl_stmt|;
comment|/* major/minor chip revision */
name|int
name|sc_flags
decl_stmt|;
comment|/* device specific flags */
define|#
directive|define
name|SAFE_FLAGS_KEY
value|0x01
comment|/* has key accelerator */
define|#
directive|define
name|SAFE_FLAGS_RNG
value|0x02
comment|/* hardware rng */
name|int
name|sc_suspended
decl_stmt|;
name|int
name|sc_needwakeup
decl_stmt|;
comment|/* notify crypto layer */
name|int32_t
name|sc_cid
decl_stmt|;
comment|/* crypto tag */
name|struct
name|safe_dma_alloc
name|sc_ringalloc
decl_stmt|;
comment|/* PE ring allocation state */
name|struct
name|safe_ringentry
modifier|*
name|sc_ring
decl_stmt|;
comment|/* PE ring */
name|struct
name|safe_ringentry
modifier|*
name|sc_ringtop
decl_stmt|;
comment|/* PE ring top */
name|struct
name|safe_ringentry
modifier|*
name|sc_front
decl_stmt|;
comment|/* next free entry */
name|struct
name|safe_ringentry
modifier|*
name|sc_back
decl_stmt|;
comment|/* next pending entry */
name|int
name|sc_nqchip
decl_stmt|;
comment|/* # passed to chip */
name|struct
name|mtx
name|sc_ringmtx
decl_stmt|;
comment|/* PE ring lock */
name|struct
name|safe_pdesc
modifier|*
name|sc_spring
decl_stmt|;
comment|/* src particle ring */
name|struct
name|safe_pdesc
modifier|*
name|sc_springtop
decl_stmt|;
comment|/* src particle ring top */
name|struct
name|safe_pdesc
modifier|*
name|sc_spfree
decl_stmt|;
comment|/* next free src particle */
name|struct
name|safe_dma_alloc
name|sc_spalloc
decl_stmt|;
comment|/* src particle ring state */
name|struct
name|safe_pdesc
modifier|*
name|sc_dpring
decl_stmt|;
comment|/* dest particle ring */
name|struct
name|safe_pdesc
modifier|*
name|sc_dpringtop
decl_stmt|;
comment|/* dest particle ring top */
name|struct
name|safe_pdesc
modifier|*
name|sc_dpfree
decl_stmt|;
comment|/* next free dest particle */
name|struct
name|safe_dma_alloc
name|sc_dpalloc
decl_stmt|;
comment|/* dst particle ring state */
name|int
name|sc_nsessions
decl_stmt|;
comment|/* # of sessions */
name|struct
name|safe_session
modifier|*
name|sc_sessions
decl_stmt|;
comment|/* sessions */
name|struct
name|callout
name|sc_rngto
decl_stmt|;
comment|/* rng timeout */
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
name|safe_stats
block|{
name|u_int64_t
name|st_ibytes
decl_stmt|;
name|u_int64_t
name|st_obytes
decl_stmt|;
name|u_int32_t
name|st_ipackets
decl_stmt|;
name|u_int32_t
name|st_opackets
decl_stmt|;
name|u_int32_t
name|st_invalid
decl_stmt|;
comment|/* invalid argument */
name|u_int32_t
name|st_badsession
decl_stmt|;
comment|/* invalid session id */
name|u_int32_t
name|st_badflags
decl_stmt|;
comment|/* flags indicate !(mbuf | uio) */
name|u_int32_t
name|st_nodesc
decl_stmt|;
comment|/* op submitted w/o descriptors */
name|u_int32_t
name|st_badalg
decl_stmt|;
comment|/* unsupported algorithm */
name|u_int32_t
name|st_ringfull
decl_stmt|;
comment|/* PE descriptor ring full */
name|u_int32_t
name|st_peoperr
decl_stmt|;
comment|/* PE marked error */
name|u_int32_t
name|st_dmaerr
decl_stmt|;
comment|/* PE DMA error */
name|u_int32_t
name|st_bypasstoobig
decl_stmt|;
comment|/* bypass> 96 bytes */
name|u_int32_t
name|st_skipmismatch
decl_stmt|;
comment|/* enc part begins before auth part */
name|u_int32_t
name|st_lenmismatch
decl_stmt|;
comment|/* enc length different auth length */
name|u_int32_t
name|st_coffmisaligned
decl_stmt|;
comment|/* crypto offset not 32-bit aligned */
name|u_int32_t
name|st_cofftoobig
decl_stmt|;
comment|/* crypto offset> 255 words */
name|u_int32_t
name|st_iovmisaligned
decl_stmt|;
comment|/* iov op not aligned */
name|u_int32_t
name|st_iovnotuniform
decl_stmt|;
comment|/* iov op not suitable */
name|u_int32_t
name|st_unaligned
decl_stmt|;
comment|/* unaligned src caused copy */
name|u_int32_t
name|st_notuniform
decl_stmt|;
comment|/* non-uniform src caused copy */
name|u_int32_t
name|st_nomap
decl_stmt|;
comment|/* bus_dmamap_create failed */
name|u_int32_t
name|st_noload
decl_stmt|;
comment|/* bus_dmamap_load_* failed */
name|u_int32_t
name|st_nombuf
decl_stmt|;
comment|/* MGET* failed */
name|u_int32_t
name|st_nomcl
decl_stmt|;
comment|/* MCLGET* failed */
name|u_int32_t
name|st_maxqchip
decl_stmt|;
comment|/* max mcr1 ops out for processing */
name|u_int32_t
name|st_rng
decl_stmt|;
comment|/* RNG requests */
name|u_int32_t
name|st_rngalarm
decl_stmt|;
comment|/* RNG alarm requests */
name|u_int32_t
name|st_noicvcopy
decl_stmt|;
comment|/* ICV data copies suppressed */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SAFE_SAFEVAR_H_ */
end_comment

end_unit

