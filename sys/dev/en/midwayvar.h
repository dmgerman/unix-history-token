begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: midwayvar.h,v 1.10 1997/03/20 21:34:46 chuck Exp $	*/
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *	Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * m i d w a y v a r . h  *  * we define the en_softc here so that bus specific modules can allocate  * it as the first item in their softc.   *  * author: Chuck Cranor<chuck@ccrc.wustl.edu>  */
end_comment

begin_comment
comment|/*  * params needed to determine softc size  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EN_NTX
end_ifndef

begin_define
define|#
directive|define
name|EN_NTX
value|8
end_define

begin_comment
comment|/* number of tx bufs to use */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EN_TXSZ
end_ifndef

begin_define
define|#
directive|define
name|EN_TXSZ
value|32
end_define

begin_comment
comment|/* trasmit buf size in KB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EN_RXSZ
end_ifndef

begin_define
define|#
directive|define
name|EN_RXSZ
value|32
end_define

begin_comment
comment|/* recv buf size in KB */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* largest possible NRX (depends on RAM size) */
end_comment

begin_define
define|#
directive|define
name|EN_MAXNRX
value|((2048 - (EN_NTX * EN_TXSZ)) / EN_RXSZ)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EN_MAX_DMASEG
end_ifndef

begin_define
define|#
directive|define
name|EN_MAX_DMASEG
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* number of bytes to use in the first receive buffer. This must not be larger  * than MHLEN, should be a multiple of 64 and must be a multiple of 4. */
end_comment

begin_define
define|#
directive|define
name|EN_RX1BUF
value|128
end_define

begin_comment
comment|/*  * Structure to hold DMA maps. These are handle via a typestable uma zone.  */
end_comment

begin_struct
struct|struct
name|en_map
block|{
name|uintptr_t
name|flags
decl_stmt|;
comment|/* map flags */
name|struct
name|en_map
modifier|*
name|rsvd2
decl_stmt|;
comment|/* see uma_zalloc(9) */
name|struct
name|en_softc
modifier|*
name|sc
decl_stmt|;
comment|/* back pointer */
name|bus_dmamap_t
name|map
decl_stmt|;
comment|/* the map */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ENMAP_LOADED
value|0x02
end_define

begin_define
define|#
directive|define
name|ENMAP_ALLOC
value|0x01
end_define

begin_define
define|#
directive|define
name|EN_MAX_MAPS
value|400
end_define

begin_comment
comment|/*  * Statistics  */
end_comment

begin_struct
struct|struct
name|en_stats
block|{
name|uint32_t
name|vtrash
decl_stmt|;
comment|/* sw copy of counter */
name|uint32_t
name|otrash
decl_stmt|;
comment|/* sw copy of counter */
name|uint32_t
name|ttrash
decl_stmt|;
comment|/* # of RBD's with T bit set */
name|uint32_t
name|mfixaddr
decl_stmt|;
comment|/* # of times we had to mfix an address */
name|uint32_t
name|mfixlen
decl_stmt|;
comment|/* # of times we had to mfix a lenght*/
name|uint32_t
name|mfixfail
decl_stmt|;
comment|/* # of times mfix failed */
name|uint32_t
name|txmbovr
decl_stmt|;
comment|/* # of times we dropped due to mbsize */
name|uint32_t
name|dmaovr
decl_stmt|;
comment|/* tx dma overflow count */
name|uint32_t
name|txoutspace
decl_stmt|;
comment|/* out of space in xmit buffer */
name|uint32_t
name|txdtqout
decl_stmt|;
comment|/* out of DTQs */
name|uint32_t
name|launch
decl_stmt|;
comment|/* total # of launches */
name|uint32_t
name|hwpull
decl_stmt|;
comment|/* # of pulls off hardware service list */
name|uint32_t
name|swadd
decl_stmt|;
comment|/* # of pushes on sw service list */
name|uint32_t
name|rxqnotus
decl_stmt|;
comment|/* # of times we pull from rx q, but fail */
name|uint32_t
name|rxqus
decl_stmt|;
comment|/* # of good pulls from rx q */
name|uint32_t
name|rxdrqout
decl_stmt|;
comment|/* # of times out of DRQs */
name|uint32_t
name|rxmbufout
decl_stmt|;
comment|/* # of time out of mbufs */
name|uint32_t
name|txnomap
decl_stmt|;
comment|/* out of DMA maps in TX */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each of these structures describes one of the eight transmit channels  */
end_comment

begin_struct
struct|struct
name|en_txslot
block|{
name|uint32_t
name|mbsize
decl_stmt|;
comment|/* # mbuf bytes in use (max=TXHIWAT) */
name|uint32_t
name|bfree
decl_stmt|;
comment|/* # free bytes in buffer */
name|uint32_t
name|start
decl_stmt|;
comment|/* start of buffer area (byte offset) */
name|uint32_t
name|stop
decl_stmt|;
comment|/* ends of buffer area (byte offset) */
name|uint32_t
name|cur
decl_stmt|;
comment|/* next free area (byte offset) */
name|uint32_t
name|nref
decl_stmt|;
comment|/* # of VCs using this channel */
name|struct
name|ifqueue
name|q
decl_stmt|;
comment|/* mbufs waiting for DMA now */
name|struct
name|ifqueue
name|indma
decl_stmt|;
comment|/* mbufs waiting for DMA now */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Each of these structures is used for each of the receive buffers on the  * card.  */
end_comment

begin_struct
struct|struct
name|en_rxslot
block|{
name|void
modifier|*
name|rxhand
decl_stmt|;
comment|/* recv. handle for direct delivery */
name|uint32_t
name|mode
decl_stmt|;
comment|/* saved copy of mode info */
name|uint32_t
name|start
decl_stmt|;
comment|/* begin of my buffer area */
name|uint32_t
name|stop
decl_stmt|;
comment|/* end of my buffer area */
name|uint32_t
name|cur
decl_stmt|;
comment|/* where I am at in the buffer */
name|uint16_t
name|atm_vci
decl_stmt|;
comment|/* backpointer to VCI */
name|uint8_t
name|atm_flags
decl_stmt|;
comment|/* copy of atm_flags from atm_ph */
name|uint8_t
name|oth_flags
decl_stmt|;
comment|/* other flags */
name|uint32_t
name|raw_threshold
decl_stmt|;
comment|/* for raw mode */
name|struct
name|ifqueue
name|q
decl_stmt|;
comment|/* mbufs waiting for dma now */
name|struct
name|ifqueue
name|indma
decl_stmt|;
comment|/* mbufs being dma'd now */
block|}
struct|;
end_struct

begin_comment
comment|/*  * softc  */
end_comment

begin_struct
struct|struct
name|en_softc
block|{
comment|/* bsd glue */
name|struct
name|ifatm
name|ifatm
decl_stmt|;
comment|/* ATM network ifnet handle */
name|device_t
name|dev
decl_stmt|;
comment|/* bus glue */
name|bus_space_tag_t
name|en_memt
decl_stmt|;
comment|/* for EN_READ/EN_WRITE */
name|bus_space_handle_t
name|en_base
decl_stmt|;
comment|/* base of en card */
name|bus_size_t
name|en_obmemsz
decl_stmt|;
comment|/* size of en card (bytes) */
name|void
function_decl|(
modifier|*
name|en_busreset
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* bus specific reset function */
name|bus_dma_tag_t
name|txtag
decl_stmt|;
comment|/* TX DMA tag */
comment|/* serv list */
name|uint32_t
name|hwslistp
decl_stmt|;
comment|/* hw pointer to service list (byte offset) */
name|uint16_t
name|swslist
index|[
name|MID_SL_N
index|]
decl_stmt|;
comment|/* software svc list (see en_service()) */
name|uint16_t
name|swsl_head
decl_stmt|;
comment|/* ends of swslist (index into swslist) */
name|uint16_t
name|swsl_tail
decl_stmt|;
name|uint32_t
name|swsl_size
decl_stmt|;
comment|/* # of items in swsl */
comment|/* xmit dma */
name|uint32_t
name|dtq
index|[
name|MID_DTQ_N
index|]
decl_stmt|;
comment|/* sw copy of dma q (see EN_DQ_MK macros) */
name|uint32_t
name|dtq_free
decl_stmt|;
comment|/* # of dtq's free */
name|uint32_t
name|dtq_us
decl_stmt|;
comment|/* software copy of our pointer (byte offset) */
name|uint32_t
name|dtq_chip
decl_stmt|;
comment|/* chip's pointer (byte offset) */
name|uint32_t
name|need_dtqs
decl_stmt|;
comment|/* true if we ran out of DTQs */
comment|/* recv dma */
name|uint32_t
name|drq
index|[
name|MID_DRQ_N
index|]
decl_stmt|;
comment|/* sw copy of dma q (see ENIDQ macros) */
name|uint32_t
name|drq_free
decl_stmt|;
comment|/* # of drq's free */
name|uint32_t
name|drq_us
decl_stmt|;
comment|/* software copy of our pointer (byte offset) */
name|uint32_t
name|drq_chip
decl_stmt|;
comment|/* chip's pointer (byte offset) */
name|uint32_t
name|need_drqs
decl_stmt|;
comment|/* true if we ran out of DRQs */
comment|/* xmit buf ctrl. (per channel) */
name|struct
name|en_txslot
name|txslot
index|[
name|MID_NTX_CH
index|]
decl_stmt|;
comment|/* xmit vc ctrl. (per vc) */
name|uint8_t
name|txspeed
index|[
name|MID_N_VC
index|]
decl_stmt|;
comment|/* speed of tx on a VC */
name|uint8_t
name|txvc2slot
index|[
name|MID_N_VC
index|]
decl_stmt|;
comment|/* map VC to slot */
comment|/* recv vc ctrl. (per vc).   maps VC number to recv slot */
name|uint16_t
name|rxvc2slot
index|[
name|MID_N_VC
index|]
decl_stmt|;
name|int
name|en_nrx
decl_stmt|;
comment|/* # of active rx slots */
comment|/* recv buf ctrl. (per recv slot) */
name|struct
name|en_rxslot
name|rxslot
index|[
name|EN_MAXNRX
index|]
decl_stmt|;
comment|/* stats */
name|struct
name|en_stats
name|stats
decl_stmt|;
comment|/* random stuff */
name|uint32_t
name|ipl
decl_stmt|;
comment|/* sbus interrupt lvl (1 on pci?) */
name|uint8_t
name|bestburstcode
decl_stmt|;
comment|/* code of best burst we can use */
name|uint8_t
name|bestburstlen
decl_stmt|;
comment|/* length of best burst (bytes) */
name|uint8_t
name|bestburstshift
decl_stmt|;
comment|/* (x>> shift) == (x / bestburstlen) */
name|uint8_t
name|bestburstmask
decl_stmt|;
comment|/* bits to check if not multiple of burst */
name|uint8_t
name|alburst
decl_stmt|;
comment|/* align dma bursts? */
name|uint8_t
name|noalbursts
decl_stmt|;
comment|/* don't use unaligned> 4 byte bursts */
name|uint8_t
name|is_adaptec
decl_stmt|;
comment|/* adaptec version of midway? */
name|struct
name|mbuf
modifier|*
name|padbuf
decl_stmt|;
comment|/* buffer of zeros for TX padding */
comment|/* mutex to protect this structure and the associated hardware */
name|struct
name|mtx
name|en_mtx
decl_stmt|;
comment|/* sysctl support */
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
decl_stmt|;
comment|/* memory zones */
name|uma_zone_t
name|map_zone
decl_stmt|;
comment|/* media and phy */
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|utopia
name|utopia
decl_stmt|;
ifdef|#
directive|ifdef
name|EN_DEBUG
comment|/* debugging */
name|u_int
name|debug
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * exported functions  */
end_comment

begin_function_decl
name|int
name|en_attach
parameter_list|(
name|struct
name|en_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|en_destroy
parameter_list|(
name|struct
name|en_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|en_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|en_reset
parameter_list|(
name|struct
name|en_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

