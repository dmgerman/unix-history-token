begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: midwayvar.h,v 1.10 1997/03/20 21:34:46 chuck Exp $	*/
end_comment

begin_comment
comment|/*  *  * Copyright (c) 1996 Charles D. Cranor and Washington University.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Charles D. Cranor and  *	Washington University.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * m i d w a y v a r . h  *  * we define the en_softc here so that bus specific modules can allocate  * it as the first item in their softc.   note that BSD-required   * "struct device" is in the mid_softc!  *  * author: Chuck Cranor<chuck@ccrc.wustl.edu>  */
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

begin_define
define|#
directive|define
name|EN_MAXNRX
value|((2048-(EN_NTX*EN_TXSZ))/EN_RXSZ)
end_define

begin_comment
comment|/* largest possible NRX (depends on RAM size) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_if

begin_define
define|#
directive|define
name|EN_INTR_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|EN_INTR_RET
parameter_list|(
name|X
parameter_list|)
value|return(X)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|EN_IOCTL_CMDT
value|u_long
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EN_IOCTL_CMDT
value|int
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
name|__FreeBSD__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|EN_INTR_TYPE
value|void
end_define

begin_define
define|#
directive|define
name|EN_INTR_RET
parameter_list|(
name|X
parameter_list|)
value|return
end_define

begin_define
define|#
directive|define
name|EN_IOCTL_CMDT
value|u_long
end_define

begin_struct
struct|struct
name|device
block|{
name|char
name|dv_xname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DV_IFNET
value|1
end_define

begin_struct
struct|struct
name|cfdriver
block|{
name|int
name|zero
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|one
decl_stmt|;
name|int
name|cd_ndevs
decl_stmt|;
name|void
modifier|*
name|cd_devs
index|[
name|NEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * softc  */
end_comment

begin_struct
struct|struct
name|en_softc
block|{
comment|/* bsd glue */
name|struct
name|device
name|sc_dev
decl_stmt|;
comment|/* system device */
name|struct
name|ifnet
name|enif
decl_stmt|;
comment|/* network ifnet handle */
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
argument_list|(
argument|*en_busreset
argument_list|)
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* bus specific reset function */
comment|/* serv list */
name|u_int32_t
name|hwslistp
decl_stmt|;
comment|/* hw pointer to service list (byte offset) */
name|u_int16_t
name|swslist
index|[
name|MID_SL_N
index|]
decl_stmt|;
comment|/* software service list (see en_service()) */
name|u_int16_t
name|swsl_head
decl_stmt|,
comment|/* ends of swslist (index into swslist) */
name|swsl_tail
decl_stmt|;
name|u_int32_t
name|swsl_size
decl_stmt|;
comment|/* # of items in swsl */
comment|/* xmit dma */
name|u_int32_t
name|dtq
index|[
name|MID_DTQ_N
index|]
decl_stmt|;
comment|/* sw copy of dma q (see ENIDQ macros) */
name|u_int32_t
name|dtq_free
decl_stmt|;
comment|/* # of dtq's free */
name|u_int32_t
name|dtq_us
decl_stmt|;
comment|/* software copy of our pointer (byte offset) */
name|u_int32_t
name|dtq_chip
decl_stmt|;
comment|/* chip's pointer (byte offset) */
name|u_int32_t
name|need_dtqs
decl_stmt|;
comment|/* true if we ran out of DTQs */
comment|/* recv dma */
name|u_int32_t
name|drq
index|[
name|MID_DRQ_N
index|]
decl_stmt|;
comment|/* sw copy of dma q (see ENIDQ macros) */
name|u_int32_t
name|drq_free
decl_stmt|;
comment|/* # of drq's free */
name|u_int32_t
name|drq_us
decl_stmt|;
comment|/* software copy of our pointer (byte offset) */
name|u_int32_t
name|drq_chip
decl_stmt|;
comment|/* chip's pointer (byte offset) */
name|u_int32_t
name|need_drqs
decl_stmt|;
comment|/* true if we ran out of DRQs */
comment|/* xmit buf ctrl. (per channel) */
struct|struct
block|{
name|u_int32_t
name|mbsize
decl_stmt|;
comment|/* # mbuf bytes we are using (max=TXHIWAT) */
name|u_int32_t
name|bfree
decl_stmt|;
comment|/* # free bytes in buffer (not dma or xmit) */
name|u_int32_t
name|start
decl_stmt|,
name|stop
decl_stmt|;
comment|/* ends of buffer area (byte offset) */
name|u_int32_t
name|cur
decl_stmt|;
comment|/* next free area (byte offset) */
name|u_int32_t
name|nref
decl_stmt|;
comment|/* # of VCs using this channel */
name|struct
name|ifqueue
name|indma
decl_stmt|;
comment|/* mbufs being dma'd now */
name|struct
name|ifqueue
name|q
decl_stmt|;
comment|/* mbufs waiting for dma now */
block|}
name|txslot
index|[
name|MID_NTX_CH
index|]
struct|;
comment|/* xmit vc ctrl. (per vc) */
name|u_int8_t
name|txspeed
index|[
name|MID_N_VC
index|]
decl_stmt|;
comment|/* speed of tx on a VC */
name|u_int8_t
name|txvc2slot
index|[
name|MID_N_VC
index|]
decl_stmt|;
comment|/* map VC to slot */
comment|/* recv vc ctrl. (per vc).   maps VC number to recv slot */
name|u_int16_t
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
struct|struct
block|{
name|void
modifier|*
name|rxhand
decl_stmt|;
comment|/* recv. handle if doing direct delivery */
name|u_int32_t
name|mode
decl_stmt|;
comment|/* saved copy of mode info */
name|u_int32_t
name|start
decl_stmt|,
name|stop
decl_stmt|;
comment|/* ends of my buffer area */
name|u_int32_t
name|cur
decl_stmt|;
comment|/* where I am at */
name|u_int16_t
name|atm_vci
decl_stmt|;
comment|/* backpointer to VCI */
name|u_int8_t
name|atm_flags
decl_stmt|;
comment|/* copy of atm_flags from atm_ph */
name|u_int8_t
name|oth_flags
decl_stmt|;
comment|/* other flags */
name|u_int32_t
name|raw_threshold
decl_stmt|;
comment|/* for raw mode */
name|struct
name|ifqueue
name|indma
decl_stmt|;
comment|/* mbufs being dma'd now */
name|struct
name|ifqueue
name|q
decl_stmt|;
comment|/* mbufs waiting for dma now */
block|}
name|rxslot
index|[
name|EN_MAXNRX
index|]
struct|;
comment|/* recv info */
name|u_int8_t
name|macaddr
index|[
literal|6
index|]
decl_stmt|;
comment|/* card unique mac address */
comment|/* stats */
name|u_int32_t
name|vtrash
decl_stmt|;
comment|/* sw copy of counter */
name|u_int32_t
name|otrash
decl_stmt|;
comment|/* sw copy of counter */
name|u_int32_t
name|ttrash
decl_stmt|;
comment|/* # of RBD's with T bit set */
name|u_int32_t
name|mfix
decl_stmt|;
comment|/* # of times we had to call mfix */
name|u_int32_t
name|mfixfail
decl_stmt|;
comment|/* # of times mfix failed */
name|u_int32_t
name|headbyte
decl_stmt|;
comment|/* # of times we used BYTE DMA at front */
name|u_int32_t
name|tailbyte
decl_stmt|;
comment|/* # of times we used BYTE DMA at end */
name|u_int32_t
name|tailflush
decl_stmt|;
comment|/* # of times we had to FLUSH out DMA bytes */
name|u_int32_t
name|txmbovr
decl_stmt|;
comment|/* # of times we dropped due to mbsize */
name|u_int32_t
name|dmaovr
decl_stmt|;
comment|/* tx dma overflow count */
name|u_int32_t
name|txoutspace
decl_stmt|;
comment|/* out of space in xmit buffer */
name|u_int32_t
name|txdtqout
decl_stmt|;
comment|/* out of DTQs */
name|u_int32_t
name|launch
decl_stmt|;
comment|/* total # of launches */
name|u_int32_t
name|lheader
decl_stmt|;
comment|/* # of launches without OB header */
name|u_int32_t
name|ltail
decl_stmt|;
comment|/* # of launches without OB tail */
name|u_int32_t
name|hwpull
decl_stmt|;
comment|/* # of pulls off hardware service list */
name|u_int32_t
name|swadd
decl_stmt|;
comment|/* # of pushes on sw service list */
name|u_int32_t
name|rxqnotus
decl_stmt|;
comment|/* # of times we pull from rx q, but fail */
name|u_int32_t
name|rxqus
decl_stmt|;
comment|/* # of good pulls from rx q */
name|u_int32_t
name|rxoutboth
decl_stmt|;
comment|/* # of times out of mbufs and DRQs */
name|u_int32_t
name|rxdrqout
decl_stmt|;
comment|/* # of times out of DRQs */
name|u_int32_t
name|rxmbufout
decl_stmt|;
comment|/* # of time out of mbufs */
comment|/* random stuff */
name|u_int32_t
name|ipl
decl_stmt|;
comment|/* sbus interrupt lvl (1 on pci?) */
name|u_int8_t
name|bestburstcode
decl_stmt|;
comment|/* code of best burst we can use */
name|u_int8_t
name|bestburstlen
decl_stmt|;
comment|/* length of best burst (bytes) */
name|u_int8_t
name|bestburstshift
decl_stmt|;
comment|/* (x>> shift) == (x / bestburstlen) */
name|u_int8_t
name|bestburstmask
decl_stmt|;
comment|/* bits to check if not multiple of burst */
name|u_int8_t
name|alburst
decl_stmt|;
comment|/* align dma bursts? */
name|u_int8_t
name|is_adaptec
decl_stmt|;
comment|/* adaptec version of midway? */
block|}
struct|;
end_struct

begin_comment
comment|/*  * exported functions  */
end_comment

begin_decl_stmt
name|void
name|en_attach
name|__P
argument_list|(
operator|(
expr|struct
name|en_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EN_INTR_TYPE
name|en_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|en_reset
name|__P
argument_list|(
operator|(
expr|struct
name|en_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

