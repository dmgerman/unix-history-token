begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NecBSD: ctvar.h,v 1.4.14.3 2001/06/20 06:13:34 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2001  *	NetBSD/pc98 porting staff. All rights reserved.  *  Copyright (c) 1995, 1996, 1997, 1998, 1999, 2000, 2001  *	Naofumi HONDA. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTVAR_H_
end_define

begin_comment
comment|/*  * ctvar.h  * Generic wd33c93 chip driver's definitions  */
end_comment

begin_comment
comment|/*****************************************************************  * Host adapter structure  *****************************************************************/
end_comment

begin_struct
struct|struct
name|ct_bus_access_handle
block|{
name|bus_space_tag_t
name|ch_iot
decl_stmt|;
comment|/* core chip ctrl port tag */
name|bus_space_tag_t
name|ch_delayt
decl_stmt|;
comment|/* delay port tag */
name|bus_space_tag_t
name|ch_datat
decl_stmt|;
comment|/* data port tag (pio) */
name|bus_space_tag_t
name|ch_memt
decl_stmt|;
comment|/* data port tag (shm) */
name|bus_space_handle_t
name|ch_ioh
decl_stmt|;
name|bus_space_handle_t
name|ch_delaybah
decl_stmt|;
name|bus_space_handle_t
name|ch_datah
decl_stmt|;
name|bus_space_handle_t
name|ch_memh
decl_stmt|;
name|void
argument_list|(
argument|*ch_bus_weight
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_bus_access_handle
operator|*
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CT_USE_RELOCATE_OFFSET
name|bus_addr_t
name|ch_offset
index|[
literal|4
index|]
decl_stmt|;
endif|#
directive|endif
comment|/* CT_USE_RELOCATE_OFFSET */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ct_softc
block|{
name|struct
name|scsi_low_softc
name|sc_sclow
decl_stmt|;
comment|/* generic data */
name|struct
name|ct_bus_access_handle
name|sc_ch
decl_stmt|;
comment|/* bus access handle */
ifdef|#
directive|ifdef
name|__NetBSD__
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* data DMA tag */
name|void
modifier|*
name|sc_ih
decl_stmt|;
endif|#
directive|endif
comment|/* __NetBSD__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|drq_res
decl_stmt|;
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* data DMA tag */
name|bus_dmamap_t
name|sc_dmamapt
decl_stmt|;
comment|/* data DMAMAP tag */
name|void
modifier|*
name|sc_ih
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|int
name|sc_chiprev
decl_stmt|;
comment|/* chip version */
define|#
directive|define
name|CT_WD33C93
value|0x00000
define|#
directive|define
name|CT_WD33C93_A
value|0x10000
define|#
directive|define
name|CT_AM33C93_A
value|0x10001
define|#
directive|define
name|CT_WD33C93_B
value|0x20000
define|#
directive|define
name|CT_WD33C93_C
value|0x30000
name|int
name|sc_xmode
decl_stmt|;
define|#
directive|define
name|CT_XMODE_PIO
value|1
define|#
directive|define
name|CT_XMODE_DMA
value|2
name|int
name|sc_dma
decl_stmt|;
comment|/* dma transfer start */
define|#
directive|define
name|CT_DMA_PIOSTART
value|1
define|#
directive|define
name|CT_DMA_DMASTART
value|2
name|int
name|sc_satgo
decl_stmt|;
comment|/* combination cmd start */
define|#
directive|define
name|CT_SAT_GOING
value|1
name|int
name|sc_tmaxcnt
decl_stmt|;
name|int
name|sc_atten
decl_stmt|;
comment|/* attention */
name|u_int8_t
name|sc_creg
decl_stmt|;
comment|/* control register value */
name|int
name|sc_chipclk
decl_stmt|;
comment|/* chipclk 0, 10, 15, 20 */
struct|struct
name|ct_synch_data
block|{
name|u_int
name|cs_period
decl_stmt|;
name|u_int
name|cs_syncr
decl_stmt|;
block|}
modifier|*
name|sc_sdp
struct|;
comment|/* synchronous data table pt */
name|struct
name|ct_synch_data
name|sc_default_sdt
index|[
literal|16
index|]
decl_stmt|;
comment|/* 	 * Machdep stuff. 	 */
name|void
modifier|*
name|ct_hw
decl_stmt|;
comment|/* point to bshw_softc etc ... */
name|int
argument_list|(
argument|*ct_dma_xfer_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*ct_pio_xfer_start
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ct_dma_xfer_stop
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ct_pio_xfer_stop
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ct_bus_reset
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*ct_synch_setup
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|,
expr|struct
name|targ_info
operator|*
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************  * Lun information   *****************************************************************/
end_comment

begin_struct
struct|struct
name|ct_targ_info
block|{
name|struct
name|targ_info
name|cti_ti
decl_stmt|;
name|u_int8_t
name|cti_syncreg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*****************************************************************  * PROTO  *****************************************************************/
end_comment

begin_decl_stmt
name|int
name|ctprobesubr
name|__P
argument_list|(
operator|(
expr|struct
name|ct_bus_access_handle
operator|*
operator|,
name|u_int
operator|,
name|int
operator|,
name|u_int
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|ctattachsubr
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctprint
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ctintr
name|__P
argument_list|(
operator|(
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_CTVAR_H_ */
end_comment

end_unit

