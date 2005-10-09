begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lsi64854var.h,v 1.6 2005/02/04 02:10:36 perry Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*	$FreeBSD$ */
end_comment

begin_struct
struct|struct
name|lsi64854_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int
name|sc_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_res
decl_stmt|;
name|bus_space_handle_t
name|sc_regh
decl_stmt|;
name|bus_space_tag_t
name|sc_regt
decl_stmt|;
name|u_int
name|sc_rev
decl_stmt|;
comment|/* revision */
name|int
name|sc_burst
decl_stmt|;
comment|/* max suported burst size */
name|int
name|sc_channel
decl_stmt|;
define|#
directive|define
name|L64854_CHANNEL_SCSI
value|1
define|#
directive|define
name|L64854_CHANNEL_ENET
value|2
define|#
directive|define
name|L64854_CHANNEL_PP
value|3
name|void
modifier|*
name|sc_client
decl_stmt|;
name|int
name|sc_active
decl_stmt|;
comment|/* DMA active ? */
name|bus_dmamap_t
name|sc_dmamap
decl_stmt|;
comment|/* DMA map for bus_dma_* */
name|bus_dma_tag_t
name|sc_parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|sc_buffer_dmat
decl_stmt|;
name|int
name|sc_datain
decl_stmt|;
name|size_t
name|sc_dmasize
decl_stmt|;
name|caddr_t
modifier|*
name|sc_dmaaddr
decl_stmt|;
name|size_t
modifier|*
name|sc_dmalen
decl_stmt|;
name|void
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|struct
name|lsi64854_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* reset routine */
name|int
function_decl|(
modifier|*
name|setup
function_decl|)
parameter_list|(
name|struct
name|lsi64854_softc
modifier|*
parameter_list|,
name|caddr_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
comment|/* DMA setup */
name|int
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* interrupt handler */
name|driver_intr_t
modifier|*
name|sc_intrchain
decl_stmt|;
comment|/* next handler in intr chain */
name|void
modifier|*
name|sc_intrchainarg
decl_stmt|;
comment|/* arg for next intr handler */
name|u_int
name|sc_dmactl
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|L64854_GCSR
parameter_list|(
name|sc
parameter_list|)
define|\
value|(bus_space_read_4((sc)->sc_regt, (sc)->sc_regh, L64854_REG_CSR))
end_define

begin_define
define|#
directive|define
name|L64854_SCSR
parameter_list|(
name|sc
parameter_list|,
name|csr
parameter_list|)
define|\
value|bus_space_write_4((sc)->sc_regt, (sc)->sc_regh, L64854_REG_CSR, csr)
end_define

begin_comment
comment|/*  * DMA engine interface functions.  */
end_comment

begin_define
define|#
directive|define
name|DMA_RESET
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->reset)(sc))
end_define

begin_define
define|#
directive|define
name|DMA_INTR
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->intr)(sc))
end_define

begin_define
define|#
directive|define
name|DMA_SETUP
parameter_list|(
name|sc
parameter_list|,
name|a
parameter_list|,
name|l
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|(((sc)->setup)(sc, a, l, d, s))
end_define

begin_define
define|#
directive|define
name|DMA_ISACTIVE
parameter_list|(
name|sc
parameter_list|)
value|((sc)->sc_active)
end_define

begin_define
define|#
directive|define
name|DMA_ENINTR
parameter_list|(
name|sc
parameter_list|)
value|do {			\ 	uint32_t csr = L64854_GCSR(sc);		\ 	csr |= L64854_INT_EN;			\ 	L64854_SCSR(sc, csr);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DMA_ISINTR
parameter_list|(
name|sc
parameter_list|)
value|(L64854_GCSR(sc)& (D_INT_PEND|D_ERR_PEND))
end_define

begin_define
define|#
directive|define
name|DMA_GO
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	uint32_t csr = L64854_GCSR(sc);		\ 	csr |= D_EN_DMA;			\ 	L64854_SCSR(sc, csr);			\ 	sc->sc_active = 1;			\ } while (0)
end_define

begin_function_decl
name|int
name|lsi64854_attach
parameter_list|(
name|struct
name|lsi64854_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lsi64854_detach
parameter_list|(
name|struct
name|lsi64854_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lsi64854_scsi_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lsi64854_enet_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lsi64854_pp_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

