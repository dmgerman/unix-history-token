begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|DMA_CR
value|0x000
end_define

begin_comment
comment|/* Control */
end_comment

begin_define
define|#
directive|define
name|DMA_ES
value|0x004
end_define

begin_comment
comment|/* Error Status */
end_comment

begin_define
define|#
directive|define
name|DMA_ERQ
value|0x00C
end_define

begin_comment
comment|/* Enable Request */
end_comment

begin_define
define|#
directive|define
name|DMA_EEI
value|0x014
end_define

begin_comment
comment|/* Enable Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|DMA_CEEI
value|0x018
end_define

begin_comment
comment|/* Clear Enable Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|DMA_SEEI
value|0x019
end_define

begin_comment
comment|/* Set Enable Error Interrupt */
end_comment

begin_define
define|#
directive|define
name|DMA_CERQ
value|0x01A
end_define

begin_comment
comment|/* Clear Enable Request */
end_comment

begin_define
define|#
directive|define
name|DMA_SERQ
value|0x01B
end_define

begin_comment
comment|/* Set Enable Request */
end_comment

begin_define
define|#
directive|define
name|DMA_CDNE
value|0x01C
end_define

begin_comment
comment|/* Clear DONE Status Bit */
end_comment

begin_define
define|#
directive|define
name|DMA_SSRT
value|0x01D
end_define

begin_comment
comment|/* Set START Bit */
end_comment

begin_define
define|#
directive|define
name|DMA_CERR
value|0x01E
end_define

begin_comment
comment|/* Clear Error */
end_comment

begin_define
define|#
directive|define
name|CERR_CAEI
value|(1<< 6)
end_define

begin_comment
comment|/* Clear All Error Indicators */
end_comment

begin_define
define|#
directive|define
name|DMA_CINT
value|0x01F
end_define

begin_comment
comment|/* Clear Interrupt Request */
end_comment

begin_define
define|#
directive|define
name|CINT_CAIR
value|(1<< 6)
end_define

begin_comment
comment|/* Clear All Interrupt Requests */
end_comment

begin_define
define|#
directive|define
name|DMA_INT
value|0x024
end_define

begin_comment
comment|/* Interrupt Request */
end_comment

begin_define
define|#
directive|define
name|DMA_ERR
value|0x02C
end_define

begin_comment
comment|/* Error */
end_comment

begin_define
define|#
directive|define
name|DMA_HRS
value|0x034
end_define

begin_comment
comment|/* Hardware Request Status */
end_comment

begin_define
define|#
directive|define
name|DMA_EARS
value|0x044
end_define

begin_comment
comment|/* Enable Asynchronous Request in Stop */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI3
value|0x100
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI2
value|0x101
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI1
value|0x102
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI0
value|0x103
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI7
value|0x104
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI6
value|0x105
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI5
value|0x106
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI4
value|0x107
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI11
value|0x108
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI10
value|0x109
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI9
value|0x10A
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI8
value|0x10B
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI15
value|0x10C
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI14
value|0x10D
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI13
value|0x10E
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI12
value|0x10F
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI19
value|0x110
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI18
value|0x111
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI17
value|0x112
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI16
value|0x113
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI23
value|0x114
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI22
value|0x115
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI21
value|0x116
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI20
value|0x117
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI27
value|0x118
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI26
value|0x119
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI25
value|0x11A
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI24
value|0x11B
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI31
value|0x11C
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI30
value|0x11D
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI29
value|0x11E
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_DCHPRI28
value|0x11F
end_define

begin_comment
comment|/* Channel n Priority */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_SADDR
parameter_list|(
name|n
parameter_list|)
value|(0x00 + 0x20 * n)
end_define

begin_comment
comment|/* Source Address */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_SOFF
parameter_list|(
name|n
parameter_list|)
value|(0x04 + 0x20 * n)
end_define

begin_comment
comment|/* Signed Source Address Offset */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_ATTR
parameter_list|(
name|n
parameter_list|)
value|(0x06 + 0x20 * n)
end_define

begin_comment
comment|/* Transfer Attributes */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_NBYTES_MLNO
parameter_list|(
name|n
parameter_list|)
value|(0x08 + 0x20 * n)
end_define

begin_comment
comment|/* Minor Byte Count */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_NBYTES_MLOFFNO
parameter_list|(
name|n
parameter_list|)
value|(0x08 + 0x20 * n)
end_define

begin_comment
comment|/* Signed Minor Loop Offset */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_NBYTES_MLOFFYES
parameter_list|(
name|n
parameter_list|)
value|(0x08 + 0x20 * n)
end_define

begin_comment
comment|/* Signed Minor Loop Offset */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_SLAST
parameter_list|(
name|n
parameter_list|)
value|(0x0C + 0x20 * n)
end_define

begin_comment
comment|/* Last Source Address Adjustment */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_DADDR
parameter_list|(
name|n
parameter_list|)
value|(0x10 + 0x20 * n)
end_define

begin_comment
comment|/* Destination Address */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_DOFF
parameter_list|(
name|n
parameter_list|)
value|(0x14 + 0x20 * n)
end_define

begin_comment
comment|/* Signed Destination Address Offset */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_CITER_ELINKYES
parameter_list|(
name|n
parameter_list|)
value|(0x16 + 0x20 * n)
end_define

begin_comment
comment|/* Current Minor Loop Link, Major Loop Count */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_CITER_ELINKNO
parameter_list|(
name|n
parameter_list|)
value|(0x16 + 0x20 * n)
end_define

begin_define
define|#
directive|define
name|DMA_TCDn_DLASTSGA
parameter_list|(
name|n
parameter_list|)
value|(0x18 + 0x20 * n)
end_define

begin_comment
comment|/* Last Dst Addr Adjustment/Scatter Gather Address */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_CSR
parameter_list|(
name|n
parameter_list|)
value|(0x1C + 0x20 * n)
end_define

begin_comment
comment|/* Control and Status */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_BITER_ELINKYES
parameter_list|(
name|n
parameter_list|)
value|(0x1E + 0x20 * n)
end_define

begin_comment
comment|/* Beginning Minor Loop Link, Major Loop Count */
end_comment

begin_define
define|#
directive|define
name|DMA_TCDn_BITER_ELINKNO
parameter_list|(
name|n
parameter_list|)
value|(0x1E + 0x20 * n)
end_define

begin_comment
comment|/* Beginning Minor Loop Link, Major Loop Count */
end_comment

begin_define
define|#
directive|define
name|TCD_CSR_START
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_INTMAJOR
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_INTHALF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_DREQ
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_ESG
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_MAJORELINK
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_ACTIVE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_DONE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|TCD_CSR_MAJORELINKCH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|TCD_ATTR_SMOD_SHIFT
value|11
end_define

begin_comment
comment|/* Source Address Modulo */
end_comment

begin_define
define|#
directive|define
name|TCD_ATTR_SSIZE_SHIFT
value|8
end_define

begin_comment
comment|/* Source Data Transfer Size */
end_comment

begin_define
define|#
directive|define
name|TCD_ATTR_DMOD_SHIFT
value|3
end_define

begin_comment
comment|/* Dst Address Modulo */
end_comment

begin_define
define|#
directive|define
name|TCD_ATTR_DSIZE_SHIFT
value|0
end_define

begin_comment
comment|/* Dst Data Transfer Size */
end_comment

begin_define
define|#
directive|define
name|TCD_READ4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_4(_sc->bst_tcd, _sc->bsh_tcd, _reg)
end_define

begin_define
define|#
directive|define
name|TCD_WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4(_sc->bst_tcd, _sc->bsh_tcd, _reg, _val)
end_define

begin_define
define|#
directive|define
name|TCD_READ2
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_2(_sc->bst_tcd, _sc->bsh_tcd, _reg)
end_define

begin_define
define|#
directive|define
name|TCD_WRITE2
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_2(_sc->bst_tcd, _sc->bsh_tcd, _reg, _val)
end_define

begin_define
define|#
directive|define
name|TCD_READ1
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_1(_sc->bst_tcd, _sc->bsh_tcd, _reg)
end_define

begin_define
define|#
directive|define
name|TCD_WRITE1
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_1(_sc->bst_tcd, _sc->bsh_tcd, _reg, _val)
end_define

begin_define
define|#
directive|define
name|EDMA_NUM_DEVICES
value|2
end_define

begin_define
define|#
directive|define
name|EDMA_NUM_CHANNELS
value|32
end_define

begin_define
define|#
directive|define
name|NCHAN_PER_MUX
value|16
end_define

begin_struct
struct|struct
name|tcd_conf
block|{
name|bus_addr_t
name|saddr
decl_stmt|;
name|bus_addr_t
name|daddr
decl_stmt|;
name|uint32_t
name|nbytes
decl_stmt|;
name|uint32_t
name|nmajor
decl_stmt|;
name|uint32_t
name|majorelink
decl_stmt|;
name|uint32_t
name|majorelinkch
decl_stmt|;
name|uint32_t
name|esg
decl_stmt|;
name|uint32_t
name|smod
decl_stmt|;
name|uint32_t
name|dmod
decl_stmt|;
name|uint32_t
name|soff
decl_stmt|;
name|uint32_t
name|doff
decl_stmt|;
name|uint32_t
name|ssize
decl_stmt|;
name|uint32_t
name|dsize
decl_stmt|;
name|uint32_t
name|slast
decl_stmt|;
name|uint32_t
name|dlast_sga
decl_stmt|;
name|uint32_t
name|channel
decl_stmt|;
name|uint32_t
function_decl|(
modifier|*
name|ih
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
modifier|*
name|ih_user
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TCD struct is described at  * Vybrid Reference Manual, Rev. 5, 07/2013  *  * Should be used for Scatter/Gathering feature.  */
end_comment

begin_struct
struct|struct
name|TCD
block|{
name|uint32_t
name|saddr
decl_stmt|;
name|uint16_t
name|attr
decl_stmt|;
name|uint16_t
name|soff
decl_stmt|;
name|uint32_t
name|nbytes
decl_stmt|;
name|uint32_t
name|slast
decl_stmt|;
name|uint32_t
name|daddr
decl_stmt|;
name|uint16_t
name|citer
decl_stmt|;
name|uint16_t
name|doff
decl_stmt|;
name|uint32_t
name|dlast_sga
decl_stmt|;
name|uint16_t
name|biter
decl_stmt|;
name|uint16_t
name|csr
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_struct
struct|struct
name|edma_softc
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|4
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|bus_space_tag_t
name|bst_tcd
decl_stmt|;
name|bus_space_handle_t
name|bsh_tcd
decl_stmt|;
name|void
modifier|*
name|tc_ih
decl_stmt|;
name|void
modifier|*
name|err_ih
decl_stmt|;
name|uint32_t
name|device_id
decl_stmt|;
name|int
function_decl|(
modifier|*
name|channel_configure
function_decl|)
parameter_list|(
name|struct
name|edma_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|channel_free
function_decl|)
parameter_list|(
name|struct
name|edma_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_request
function_decl|)
parameter_list|(
name|struct
name|edma_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_setup
function_decl|)
parameter_list|(
name|struct
name|edma_softc
modifier|*
parameter_list|,
name|struct
name|tcd_conf
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_stop
function_decl|)
parameter_list|(
name|struct
name|edma_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

