begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008-2009 Semihalf, Piotr Ziecik  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SEC_H
end_ifndef

begin_define
define|#
directive|define
name|_SEC_H
end_define

begin_comment
comment|/*  * Each SEC channel can hold up to 24 descriptors. All 4 channels can be  * simultaneously active holding 96 descriptors. Each descriptor can use 0 or  * more link table entries depending of size and granulation of input/output  * data. One link table entry is needed for each 65535 bytes of data.  */
end_comment

begin_comment
comment|/* Driver settings */
end_comment

begin_define
define|#
directive|define
name|SEC_TIMEOUT
value|100000
end_define

begin_define
define|#
directive|define
name|SEC_MAX_SESSIONS
value|256
end_define

begin_define
define|#
directive|define
name|SEC_DESCRIPTORS
value|256
end_define

begin_comment
comment|/* Must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|SEC_LT_ENTRIES
value|1024
end_define

begin_comment
comment|/* Must be power of 2 */
end_comment

begin_define
define|#
directive|define
name|SEC_MAX_IV_LEN
value|16
end_define

begin_define
define|#
directive|define
name|SEC_MAX_KEY_LEN
value|64
end_define

begin_comment
comment|/* SEC information */
end_comment

begin_define
define|#
directive|define
name|SEC_20_ID
value|0x0000000000000040ULL
end_define

begin_define
define|#
directive|define
name|SEC_30_ID
value|0x0030030000000000ULL
end_define

begin_define
define|#
directive|define
name|SEC_31_ID
value|0x0030030100000000ULL
end_define

begin_define
define|#
directive|define
name|SEC_CHANNELS
value|4
end_define

begin_define
define|#
directive|define
name|SEC_POINTERS
value|7
end_define

begin_define
define|#
directive|define
name|SEC_MAX_DMA_BLOCK_SIZE
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|SEC_MAX_FIFO_LEVEL
value|24
end_define

begin_define
define|#
directive|define
name|SEC_DMA_ALIGNMENT
value|8
end_define

begin_define
define|#
directive|define
name|__packed__
value|__attribute__ ((__packed__))
end_define

begin_struct_decl
struct_decl|struct
name|sec_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sec_session
struct_decl|;
end_struct_decl

begin_comment
comment|/* SEC descriptor definition */
end_comment

begin_struct
struct|struct
name|sec_hw_desc_ptr
block|{
name|u_int
name|shdp_length
range|:
literal|16
decl_stmt|;
name|u_int
name|shdp_j
range|:
literal|1
decl_stmt|;
name|u_int
name|shdp_extent
range|:
literal|7
decl_stmt|;
name|u_int
name|__padding0
range|:
literal|4
decl_stmt|;
name|uint64_t
name|shdp_ptr
range|:
literal|36
decl_stmt|;
block|}
name|__packed__
struct|;
end_struct

begin_struct
struct|struct
name|sec_hw_desc
block|{
union|union
name|__packed__
block|{
struct|struct
name|__packed__
block|{
name|u_int
name|eu_sel0
range|:
literal|4
decl_stmt|;
name|u_int
name|mode0
range|:
literal|8
decl_stmt|;
name|u_int
name|eu_sel1
range|:
literal|4
decl_stmt|;
name|u_int
name|mode1
range|:
literal|8
decl_stmt|;
name|u_int
name|desc_type
range|:
literal|5
decl_stmt|;
name|u_int
name|__padding0
range|:
literal|1
decl_stmt|;
name|u_int
name|dir
range|:
literal|1
decl_stmt|;
name|u_int
name|dn
range|:
literal|1
decl_stmt|;
name|u_int
name|__padding1
range|:
literal|32
decl_stmt|;
block|}
name|request
struct|;
struct|struct
name|__packed__
block|{
name|u_int
name|done
range|:
literal|8
decl_stmt|;
name|u_int
name|__padding0
range|:
literal|27
decl_stmt|;
name|u_int
name|iccr0
range|:
literal|2
decl_stmt|;
name|u_int
name|__padding1
range|:
literal|6
decl_stmt|;
name|u_int
name|iccr1
range|:
literal|2
decl_stmt|;
name|u_int
name|__padding2
range|:
literal|19
decl_stmt|;
block|}
name|feedback
struct|;
block|}
name|shd_control
union|;
name|struct
name|sec_hw_desc_ptr
name|shd_pointer
index|[
name|SEC_POINTERS
index|]
decl_stmt|;
comment|/* Data below is mapped to descriptor pointers */
name|uint8_t
name|shd_iv
index|[
name|SEC_MAX_IV_LEN
index|]
decl_stmt|;
name|uint8_t
name|shd_key
index|[
name|SEC_MAX_KEY_LEN
index|]
decl_stmt|;
name|uint8_t
name|shd_mkey
index|[
name|SEC_MAX_KEY_LEN
index|]
decl_stmt|;
block|}
name|__packed__
struct|;
end_struct

begin_define
define|#
directive|define
name|shd_eu_sel0
value|shd_control.request.eu_sel0
end_define

begin_define
define|#
directive|define
name|shd_mode0
value|shd_control.request.mode0
end_define

begin_define
define|#
directive|define
name|shd_eu_sel1
value|shd_control.request.eu_sel1
end_define

begin_define
define|#
directive|define
name|shd_mode1
value|shd_control.request.mode1
end_define

begin_define
define|#
directive|define
name|shd_desc_type
value|shd_control.request.desc_type
end_define

begin_define
define|#
directive|define
name|shd_dir
value|shd_control.request.dir
end_define

begin_define
define|#
directive|define
name|shd_dn
value|shd_control.request.dn
end_define

begin_define
define|#
directive|define
name|shd_done
value|shd_control.feedback.done
end_define

begin_define
define|#
directive|define
name|shd_iccr0
value|shd_control.feedback.iccr0
end_define

begin_define
define|#
directive|define
name|shd_iccr1
value|shd_control.feedback.iccr1
end_define

begin_comment
comment|/* SEC link table entries definition */
end_comment

begin_struct
struct|struct
name|sec_hw_lt
block|{
name|u_int
name|shl_length
range|:
literal|16
decl_stmt|;
name|u_int
name|__padding0
range|:
literal|6
decl_stmt|;
name|u_int
name|shl_r
range|:
literal|1
decl_stmt|;
name|u_int
name|shl_n
range|:
literal|1
decl_stmt|;
name|u_int
name|__padding1
range|:
literal|4
decl_stmt|;
name|uint64_t
name|shl_ptr
range|:
literal|36
decl_stmt|;
block|}
name|__packed__
struct|;
end_struct

begin_struct
struct|struct
name|sec_dma_mem
block|{
name|void
modifier|*
name|dma_vaddr
decl_stmt|;
name|bus_addr_t
name|dma_paddr
decl_stmt|;
name|bus_dma_tag_t
name|dma_tag
decl_stmt|;
name|bus_dmamap_t
name|dma_map
decl_stmt|;
name|u_int
name|dma_is_map
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_desc
block|{
name|struct
name|sec_hw_desc
modifier|*
name|sd_desc
decl_stmt|;
name|bus_addr_t
name|sd_desc_paddr
decl_stmt|;
name|struct
name|sec_dma_mem
name|sd_ptr_dmem
index|[
name|SEC_POINTERS
index|]
decl_stmt|;
name|struct
name|cryptop
modifier|*
name|sd_crp
decl_stmt|;
name|u_int
name|sd_lt_used
decl_stmt|;
name|u_int
name|sd_error
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_lt
block|{
name|struct
name|sec_hw_lt
modifier|*
name|sl_lt
decl_stmt|;
name|bus_addr_t
name|sl_lt_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_eu_methods
block|{
name|int
function_decl|(
modifier|*
name|sem_newsession
function_decl|)
parameter_list|(
name|struct
name|sec_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|sec_session
modifier|*
name|ses
parameter_list|,
name|struct
name|cryptoini
modifier|*
name|enc
parameter_list|,
name|struct
name|cryptoini
modifier|*
name|mac
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sem_make_desc
function_decl|)
parameter_list|(
name|struct
name|sec_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|sec_session
modifier|*
name|ses
parameter_list|,
name|struct
name|sec_desc
modifier|*
name|desc
parameter_list|,
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|,
name|int
name|buftype
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_session
block|{
name|u_int
name|ss_used
decl_stmt|;
name|struct
name|sec_eu_methods
modifier|*
name|ss_eu
decl_stmt|;
name|uint8_t
name|ss_key
index|[
name|SEC_MAX_KEY_LEN
index|]
decl_stmt|;
name|uint8_t
name|ss_mkey
index|[
name|SEC_MAX_KEY_LEN
index|]
decl_stmt|;
name|u_int
name|ss_klen
decl_stmt|;
name|u_int
name|ss_mklen
decl_stmt|;
name|u_int
name|ss_ivlen
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_desc_map_info
block|{
name|struct
name|sec_softc
modifier|*
name|sdmi_sc
decl_stmt|;
name|bus_size_t
name|sdmi_size
decl_stmt|;
name|bus_size_t
name|sdmi_offset
decl_stmt|;
name|struct
name|sec_lt
modifier|*
name|sdmi_lt_first
decl_stmt|;
name|struct
name|sec_lt
modifier|*
name|sdmi_lt_last
decl_stmt|;
name|u_int
name|sdmi_lt_used
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sec_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|int32_t
name|sc_cid
decl_stmt|;
name|int
name|sc_blocked
decl_stmt|;
name|int
name|sc_shutdown
decl_stmt|;
name|u_int
name|sc_version
decl_stmt|;
name|uint64_t
name|sc_int_error_mask
decl_stmt|;
name|uint64_t
name|sc_channel_idle_mask
decl_stmt|;
name|struct
name|sec_session
name|sc_sessions
index|[
name|SEC_MAX_SESSIONS
index|]
decl_stmt|;
name|struct
name|mtx
name|sc_controller_lock
decl_stmt|;
name|struct
name|mtx
name|sc_descriptors_lock
decl_stmt|;
name|struct
name|mtx
name|sc_sessions_lock
decl_stmt|;
name|struct
name|sec_desc
name|sc_desc
index|[
name|SEC_DESCRIPTORS
index|]
decl_stmt|;
name|u_int
name|sc_free_desc_get_cnt
decl_stmt|;
name|u_int
name|sc_free_desc_put_cnt
decl_stmt|;
name|u_int
name|sc_ready_desc_get_cnt
decl_stmt|;
name|u_int
name|sc_ready_desc_put_cnt
decl_stmt|;
name|u_int
name|sc_queued_desc_get_cnt
decl_stmt|;
name|u_int
name|sc_queued_desc_put_cnt
decl_stmt|;
name|struct
name|sec_lt
name|sc_lt
index|[
name|SEC_LT_ENTRIES
operator|+
literal|1
index|]
decl_stmt|;
name|u_int
name|sc_lt_alloc_cnt
decl_stmt|;
name|u_int
name|sc_lt_free_cnt
decl_stmt|;
name|struct
name|sec_dma_mem
name|sc_desc_dmem
decl_stmt|;
comment|/* descriptors DMA memory */
name|struct
name|sec_dma_mem
name|sc_lt_dmem
decl_stmt|;
comment|/* link tables DMA memory */
name|struct
name|resource
modifier|*
name|sc_rres
decl_stmt|;
comment|/* register resource */
name|int
name|sc_rrid
decl_stmt|;
comment|/* register rid */
struct|struct
block|{
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
block|}
name|sc_bas
struct|;
name|struct
name|resource
modifier|*
name|sc_pri_ires
decl_stmt|;
comment|/* primary irq resource */
name|void
modifier|*
name|sc_pri_ihand
decl_stmt|;
comment|/* primary irq handler */
name|int
name|sc_pri_irid
decl_stmt|;
comment|/* primary irq resource id */
name|struct
name|resource
modifier|*
name|sc_sec_ires
decl_stmt|;
comment|/* secondary irq resource */
name|void
modifier|*
name|sc_sec_ihand
decl_stmt|;
comment|/* secondary irq handler */
name|int
name|sc_sec_irid
decl_stmt|;
comment|/* secondary irq resource id */
block|}
struct|;
end_struct

begin_comment
comment|/* Locking macros */
end_comment

begin_define
define|#
directive|define
name|SEC_LOCK
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
define|\
value|mtx_lock(&(sc)->sc_ ## what ## _lock)
end_define

begin_define
define|#
directive|define
name|SEC_UNLOCK
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
define|\
value|mtx_unlock(&(sc)->sc_ ## what ## _lock)
end_define

begin_define
define|#
directive|define
name|SEC_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
define|\
value|mtx_assert(&(sc)->sc_ ## what ## _lock, MA_OWNED)
end_define

begin_comment
comment|/* Read/Write definitions */
end_comment

begin_define
define|#
directive|define
name|SEC_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_8((sc)->sc_bas.bst, (sc)->sc_bas.bsh, (reg))
end_define

begin_define
define|#
directive|define
name|SEC_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_8((sc)->sc_bas.bst, (sc)->sc_bas.bsh, (reg), (val))
end_define

begin_comment
comment|/* Base allocation macros (warning: wrap must be 2^n) */
end_comment

begin_define
define|#
directive|define
name|SEC_CNT_INIT
parameter_list|(
name|sc
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|)
define|\
value|(((sc)->cnt) = ((wrap) - 1))
end_define

begin_define
define|#
directive|define
name|SEC_ADD
parameter_list|(
name|sc
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|,
name|val
parameter_list|)
define|\
value|((sc)->cnt = (((sc)->cnt) + (val))& ((wrap) - 1))
end_define

begin_define
define|#
directive|define
name|SEC_INC
parameter_list|(
name|sc
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|)
define|\
value|SEC_ADD(sc, cnt, wrap, 1)
end_define

begin_define
define|#
directive|define
name|SEC_DEC
parameter_list|(
name|sc
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|)
define|\
value|SEC_ADD(sc, cnt, wrap, -1)
end_define

begin_define
define|#
directive|define
name|SEC_GET_GENERIC
parameter_list|(
name|sc
parameter_list|,
name|tab
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|)
define|\
value|((sc)->tab[SEC_INC(sc, cnt, wrap)])
end_define

begin_define
define|#
directive|define
name|SEC_PUT_GENERIC
parameter_list|(
name|sc
parameter_list|,
name|tab
parameter_list|,
name|cnt
parameter_list|,
name|wrap
parameter_list|,
name|val
parameter_list|)
define|\
value|((sc)->tab[SEC_INC(sc, cnt, wrap)] = val)
end_define

begin_comment
comment|/* Interface for descriptors */
end_comment

begin_define
define|#
directive|define
name|SEC_GET_FREE_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&SEC_GET_GENERIC(sc, sc_desc, sc_free_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_PUT_BACK_FREE_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_DEC(sc, sc_free_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_FREE2READY
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_INC(sc, sc_ready_desc_put_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_GET_READY_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&SEC_GET_GENERIC(sc, sc_desc, sc_ready_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_PUT_BACK_READY_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_DEC(sc, sc_ready_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_READY2QUEUED
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_INC(sc, sc_queued_desc_put_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_GET_QUEUED_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|&SEC_GET_GENERIC(sc, sc_desc, sc_queued_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_PUT_BACK_QUEUED_DESC
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_DEC(sc, sc_queued_desc_get_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_QUEUED2FREE
parameter_list|(
name|sc
parameter_list|)
define|\
value|SEC_INC(sc, sc_free_desc_put_cnt, SEC_DESCRIPTORS)
end_define

begin_define
define|#
directive|define
name|SEC_FREE_DESC_CNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->sc_free_desc_put_cnt - (sc)->sc_free_desc_get_cnt - 1)	\& (SEC_DESCRIPTORS - 1))
end_define

begin_define
define|#
directive|define
name|SEC_READY_DESC_CNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->sc_ready_desc_put_cnt - (sc)->sc_ready_desc_get_cnt)&	\ 	(SEC_DESCRIPTORS - 1))
end_define

begin_define
define|#
directive|define
name|SEC_QUEUED_DESC_CNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->sc_queued_desc_put_cnt - (sc)->sc_queued_desc_get_cnt)	\& (SEC_DESCRIPTORS - 1))
end_define

begin_define
define|#
directive|define
name|SEC_DESC_SYNC
parameter_list|(
name|sc
parameter_list|,
name|mode
parameter_list|)
value|do {					\ 	sec_sync_dma_mem(&((sc)->sc_desc_dmem), (mode));		\ 	sec_sync_dma_mem(&((sc)->sc_lt_dmem), (mode));			\ } while (0)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_SYNC_POINTERS
parameter_list|(
name|desc
parameter_list|,
name|mode
parameter_list|)
value|do {				\ 	u_int i;							\ 	for (i = 0; i< SEC_POINTERS; i++)				\ 		sec_sync_dma_mem(&((desc)->sd_ptr_dmem[i]), (mode));	\ } while (0)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_FREE_POINTERS
parameter_list|(
name|desc
parameter_list|)
value|do {				\ 	u_int i;							\ 	for (i = 0; i< SEC_POINTERS; i++)				\ 		sec_free_dma_mem(&(desc)->sd_ptr_dmem[i]);		\ } while (0);
end_define

begin_define
define|#
directive|define
name|SEC_DESC_PUT_BACK_LT
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|)
define|\
value|SEC_PUT_BACK_LT(sc, (desc)->sd_lt_used)
end_define

begin_define
define|#
directive|define
name|SEC_DESC_FREE_LT
parameter_list|(
name|sc
parameter_list|,
name|desc
parameter_list|)
define|\
value|SEC_FREE_LT(sc, (desc)->sd_lt_used)
end_define

begin_comment
comment|/* Interface for link tables */
end_comment

begin_define
define|#
directive|define
name|SEC_ALLOC_LT_ENTRY
parameter_list|(
name|sc
parameter_list|)
define|\
value|&SEC_GET_GENERIC(sc, sc_lt, sc_lt_alloc_cnt, SEC_LT_ENTRIES)
end_define

begin_define
define|#
directive|define
name|SEC_PUT_BACK_LT
parameter_list|(
name|sc
parameter_list|,
name|num
parameter_list|)
define|\
value|SEC_ADD(sc, sc_lt_alloc_cnt, SEC_LT_ENTRIES, -(num))
end_define

begin_define
define|#
directive|define
name|SEC_FREE_LT
parameter_list|(
name|sc
parameter_list|,
name|num
parameter_list|)
define|\
value|SEC_ADD(sc, sc_lt_free_cnt, SEC_LT_ENTRIES, num)
end_define

begin_define
define|#
directive|define
name|SEC_FREE_LT_CNT
parameter_list|(
name|sc
parameter_list|)
define|\
value|(((sc)->sc_lt_free_cnt - (sc)->sc_lt_alloc_cnt - 1)		\& (SEC_LT_ENTRIES - 1))
end_define

begin_comment
comment|/* DMA Maping defines */
end_comment

begin_define
define|#
directive|define
name|SEC_MEMORY
value|0
end_define

begin_define
define|#
directive|define
name|SEC_UIO
value|1
end_define

begin_define
define|#
directive|define
name|SEC_MBUF
value|2
end_define

begin_comment
comment|/* Size of SEC registers area */
end_comment

begin_define
define|#
directive|define
name|SEC_IO_SIZE
value|0x10000
end_define

begin_comment
comment|/* SEC Controller registers */
end_comment

begin_define
define|#
directive|define
name|SEC_IER
value|0x1008
end_define

begin_define
define|#
directive|define
name|SEC_INT_CH_DN
parameter_list|(
name|n
parameter_list|)
value|(1ULL<< (((n) * 2) + 32))
end_define

begin_define
define|#
directive|define
name|SEC_INT_CH_ERR
parameter_list|(
name|n
parameter_list|)
value|(1ULL<< (((n) * 2) + 33))
end_define

begin_define
define|#
directive|define
name|SEC_INT_ITO
value|(1ULL<< 55)
end_define

begin_define
define|#
directive|define
name|SEC_ISR
value|0x1010
end_define

begin_define
define|#
directive|define
name|SEC_ICR
value|0x1018
end_define

begin_define
define|#
directive|define
name|SEC_ID
value|0x1020
end_define

begin_define
define|#
directive|define
name|SEC_EUASR
value|0x1028
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_RNGU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 0)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_PKEU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_KEU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_CRCU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 20)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_DEU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 32)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_AESU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 40)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_MDEU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 48)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_EUASR_AFEU
parameter_list|(
name|r
parameter_list|)
value|(((r)>> 56)& 0xF)
end_define

begin_define
define|#
directive|define
name|SEC_MCR
value|0x1030
end_define

begin_define
define|#
directive|define
name|SEC_MCR_SWR
value|(1ULL<< 32)
end_define

begin_comment
comment|/* SEC Channel registers */
end_comment

begin_define
define|#
directive|define
name|SEC_CHAN_CCR
parameter_list|(
name|n
parameter_list|)
value|(((n) * 0x100) + 0x1108)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_CDIE
value|(1ULL<< 1)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_NT
value|(1ULL<< 2)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_AWSE
value|(1ULL<< 3)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_CDWE
value|(1ULL<< 4)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_BS
value|(1ULL<< 8)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_WGN
value|(1ULL<< 13)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_R
value|(1ULL<< 32)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CCR_CON
value|(1ULL<< 33)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR
parameter_list|(
name|n
parameter_list|)
value|(((n) * 0x100) + 0x1110)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_FFLVL_M
value|0x1FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_FFLVL_S
value|56
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_GSTATE_M
value|0x0FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_GSTATE_S
value|48
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_PSTATE_M
value|0x0FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_PSTATE_S
value|40
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_MSTATE_M
value|0x3FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR2_MSTATE_S
value|32
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_FFLVL_M
value|0x1FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_FFLVL_S
value|24
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_MSTATE_M
value|0x1FFULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_MSTATE_S
value|32
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_PSTATE_M
value|0x7FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_PSTATE_S
value|48
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_GSTATE_M
value|0x7FULL
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CSR3_GSTATE_S
value|56
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_CDPR
parameter_list|(
name|n
parameter_list|)
value|(((n) * 0x100) + 0x1140)
end_define

begin_define
define|#
directive|define
name|SEC_CHAN_FF
parameter_list|(
name|n
parameter_list|)
value|(((n) * 0x100) + 0x1148)
end_define

begin_comment
comment|/* SEC Execution Units numbers */
end_comment

begin_define
define|#
directive|define
name|SEC_EU_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|SEC_EU_AFEU
value|0x1
end_define

begin_define
define|#
directive|define
name|SEC_EU_DEU
value|0x2
end_define

begin_define
define|#
directive|define
name|SEC_EU_MDEU_A
value|0x3
end_define

begin_define
define|#
directive|define
name|SEC_EU_MDEU_B
value|0xB
end_define

begin_define
define|#
directive|define
name|SEC_EU_RNGU
value|0x4
end_define

begin_define
define|#
directive|define
name|SEC_EU_PKEU
value|0x5
end_define

begin_define
define|#
directive|define
name|SEC_EU_AESU
value|0x6
end_define

begin_define
define|#
directive|define
name|SEC_EU_KEU
value|0x7
end_define

begin_define
define|#
directive|define
name|SEC_EU_CRCU
value|0x8
end_define

begin_comment
comment|/* SEC descriptor types */
end_comment

begin_define
define|#
directive|define
name|SEC_DT_COMMON_NONSNOOP
value|0x02
end_define

begin_define
define|#
directive|define
name|SEC_DT_HMAC_SNOOP
value|0x04
end_define

begin_comment
comment|/* SEC AESU declarations and definitions */
end_comment

begin_define
define|#
directive|define
name|SEC_AESU_MODE_ED
value|(1ULL<< 0)
end_define

begin_define
define|#
directive|define
name|SEC_AESU_MODE_CBC
value|(1ULL<< 1)
end_define

begin_comment
comment|/* SEC DEU declarations and definitions */
end_comment

begin_define
define|#
directive|define
name|SEC_DEU_MODE_ED
value|(1ULL<< 0)
end_define

begin_define
define|#
directive|define
name|SEC_DEU_MODE_TS
value|(1ULL<< 1)
end_define

begin_define
define|#
directive|define
name|SEC_DEU_MODE_CBC
value|(1ULL<< 2)
end_define

begin_comment
comment|/* SEC MDEU declarations and definitions */
end_comment

begin_define
define|#
directive|define
name|SEC_HMAC_HASH_LEN
value|12
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SHA1
value|0x00
end_define

begin_comment
comment|/* MDEU A */
end_comment

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SHA384
value|0x00
end_define

begin_comment
comment|/* MDEU B */
end_comment

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SHA256
value|0x01
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_MD5
value|0x02
end_define

begin_comment
comment|/* MDEU A */
end_comment

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SHA512
value|0x02
end_define

begin_comment
comment|/* MDEU B */
end_comment

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SHA224
value|0x03
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_PD
value|(1ULL<< 2)
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_HMAC
value|(1ULL<< 3)
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_INIT
value|(1ULL<< 4)
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_SMAC
value|(1ULL<< 5)
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_CICV
value|(1ULL<< 6)
end_define

begin_define
define|#
directive|define
name|SEC_MDEU_MODE_CONT
value|(1ULL<< 7)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

