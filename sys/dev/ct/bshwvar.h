begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NecBSD: bshwvar.h,v 1.3.14.3 2001/06/21 04:07:37 honda Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*  * [NetBSD for NEC PC-98 series]  *  Copyright (c) 1994, 1995, 1996, 1997, 1998  *	NetBSD/pc98 porting staff. All rights reserved.  *   *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  3. The name of the author may not be used to endorse or promote products  *     derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSHWVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSHWVAR_H_
end_define

begin_comment
comment|/*  * bshwvar.h  * NEC 55 compatible board specific definitions  */
end_comment

begin_define
define|#
directive|define
name|BSHW_DEFAULT_CHIPCLK
value|20
end_define

begin_comment
comment|/* 20MHz */
end_comment

begin_define
define|#
directive|define
name|BSHW_DEFAULT_HOSTID
value|7
end_define

begin_struct
struct|struct
name|bshw
block|{
define|#
directive|define
name|BSHW_SYNC_RELOAD
value|0x01
define|#
directive|define
name|BSHW_SMFIFO
value|0x02
define|#
directive|define
name|BSHW_DOUBLE_DMACHAN
value|0x04
name|u_int
name|hw_flags
decl_stmt|;
name|u_int
name|hw_sregaddr
decl_stmt|;
name|int
argument_list|(
operator|(
operator|*
name|hw_dma_init
operator|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|(
operator|*
name|hw_dma_start
operator|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
operator|(
operator|*
name|hw_dma_stop
operator|)
name|__P
argument_list|(
operator|(
expr|struct
name|ct_softc
operator|*
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bshw_softc
block|{
name|int
name|sc_hostid
decl_stmt|;
name|int
name|sc_irq
decl_stmt|;
comment|/* irq */
name|int
name|sc_drq
decl_stmt|;
comment|/* drq */
comment|/* dma transfer */
name|u_int8_t
modifier|*
name|sc_segaddr
decl_stmt|;
name|u_int8_t
modifier|*
name|sc_bufp
decl_stmt|;
name|int
name|sc_seglen
decl_stmt|;
name|u_int
name|sc_sdatalen
decl_stmt|;
comment|/* SMIT */
name|u_int
name|sc_edatalen
decl_stmt|;
comment|/* SMIT */
comment|/* private bounce */
name|u_int8_t
modifier|*
name|sc_bounce_phys
decl_stmt|;
name|u_int8_t
modifier|*
name|sc_bounce_addr
decl_stmt|;
name|u_int
name|sc_bounce_size
decl_stmt|;
name|bus_addr_t
name|sc_minphys
decl_stmt|;
comment|/* io control */
define|#
directive|define
name|BSHW_READ_INTERRUPT_DRIVEN
value|0x0001
define|#
directive|define
name|BSHW_WRITE_INTERRUPT_DRIVEN
value|0x0002
define|#
directive|define
name|BSHW_DMA_BLOCK
value|0x0010
define|#
directive|define
name|BSHW_SMIT_BLOCK
value|0x0020
name|u_int
name|sc_io_control
decl_stmt|;
comment|/* hardware */
name|struct
name|bshw
modifier|*
name|sc_hw
decl_stmt|;
name|void
argument_list|(
argument|(*sc_dmasync_before)
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
argument|(*sc_dmasync_after)
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
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|bshw_synch_setup
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bshw_bus_reset
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
name|bshw_read_settings
name|__P
argument_list|(
operator|(
expr|struct
name|ct_bus_access_handle
operator|*
operator|,
expr|struct
name|bshw_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bshw_smit_xfer_start
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
name|void
name|bshw_smit_xfer_stop
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
name|bshw_dma_xfer_start
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
name|void
name|bshw_dma_xfer_stop
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
specifier|extern
name|struct
name|dvcfg_hwsel
name|bshw_hwsel
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSHWVAR_H_ */
end_comment

end_unit

