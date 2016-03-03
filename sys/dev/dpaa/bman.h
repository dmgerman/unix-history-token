begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BMAN_H
end_ifndef

begin_define
define|#
directive|define
name|_BMAN_H
end_define

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<contrib/ncsw/inc/Peripherals/bm_ext.h>
end_include

begin_comment
comment|/*  * BMAN Configuration  */
end_comment

begin_comment
comment|/* Maximum number of buffers in all BMAN pools */
end_comment

begin_define
define|#
directive|define
name|BMAN_MAX_BUFFERS
value|4096
end_define

begin_comment
comment|/*  * Portal definitions  */
end_comment

begin_define
define|#
directive|define
name|BMAN_CE_PA
parameter_list|(
name|base
parameter_list|)
value|(base)
end_define

begin_define
define|#
directive|define
name|BMAN_CI_PA
parameter_list|(
name|base
parameter_list|)
value|((base) + 0x100000)
end_define

begin_define
define|#
directive|define
name|BMAN_PORTAL_CE_PA
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|)
define|\
value|(BMAN_CE_PA(base) + ((n) * BMAN_PORTAL_CE_SIZE))
end_define

begin_define
define|#
directive|define
name|BMAN_PORTAL_CI_PA
parameter_list|(
name|base
parameter_list|,
name|n
parameter_list|)
define|\
value|(BMAN_CI_PA(base) + ((n) * BMAN_PORTAL_CI_SIZE))
end_define

begin_define
define|#
directive|define
name|BMAN_CCSR_SIZE
value|0x1000
end_define

begin_struct
struct|struct
name|bman_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device handle */
name|int
name|sc_rrid
decl_stmt|;
comment|/* register rid */
name|struct
name|resource
modifier|*
name|sc_rres
decl_stmt|;
comment|/* register resource */
name|int
name|sc_irid
decl_stmt|;
comment|/* interrupt rid */
name|struct
name|resource
modifier|*
name|sc_ires
decl_stmt|;
comment|/* interrupt resource */
name|bool
name|sc_regs_mapped
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* register mapping status */
name|t_Handle
name|sc_bh
decl_stmt|;
comment|/* BMAN handle */
name|t_Handle
name|sc_bph
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* BMAN portal handles */
name|vm_paddr_t
name|sc_bp_pa
decl_stmt|;
comment|/* BMAN portals PA */
name|unsigned
name|int
name|sc_bpool_cpu
index|[
name|BM_MAX_NUM_OF_POOLS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * External API  */
end_comment

begin_comment
comment|/*  * @brief Function to create BMAN pool.  *  * @param bpid		The pointer to variable where Buffer Pool ID will be  *			stored.  *  * @param bufferSize	The size of buffers in newly created pool.  *  * @param maxBuffers	The maximum number of buffers in software stockpile.  *			Set to 0 if software stockpile should not be created.  *  * @param minBuffers	The minimum number of buffers in software stockpile.  *			Set to 0 if software stockpile should not be created.  *  * @param allocBuffers	The number of buffers to preallocate during pool  *			creation.  *  * @param f_GetBuf	The buffer allocating function. Called only by  *			bman_pool_create() and bman_pool_fill().  *  * @param f_PutBuf	The buffer freeing function. Called only by  *			bman_pool_destroy().  *  * @param dep_sw_entry	The software portal depletion entry threshold.  *			Set to 0 if depletion should not be signaled on  *			software portal.  *  * @param dep_sw_exit	The software portal depletion exit threshold.  *			Set to 0 if depletion should not be signaled on  *			software portal.  *  * @param dep_hw_entry	The hardware portal depletion entry threshold.  *			Set to 0 if depletion should not be signaled on  *			hardware portal.  *  * @param dep_hw_exit	The hardware portal depletion exit threshold.  *			Set to 0 if depletion should not be signaled on  *			hardware portal.  *  * @param f_Depletion	The software portal depletion notification function.  *			Set to NULL if depletion notification is not used.  *  * @param h_BufferPool	The user provided buffer pool context passed to  *			f_GetBuf, f_PutBuf and f_Depletion functions.  *  * @param f_PhysToVirt	The PA to VA translation function. Set to NULL if  *			default	one should be used.  *  * @param f_VirtToPhys	The VA to PA translation function. Set to NULL if  *			default one should be used.  *  * @returns		Handle to newly created BMAN pool or NULL on error.  *  * @cautions		If pool uses software stockpile, all accesses to given  *			pool must be protected by lock. Even if only hardware  *			portal depletion notification is used, the caller must  *			provide valid @p f_Depletion function.  */
end_comment

begin_function_decl
name|t_Handle
name|bman_pool_create
parameter_list|(
name|uint8_t
modifier|*
name|bpid
parameter_list|,
name|uint16_t
name|bufferSize
parameter_list|,
name|uint16_t
name|maxBuffers
parameter_list|,
name|uint16_t
name|minBuffers
parameter_list|,
name|uint16_t
name|allocBuffers
parameter_list|,
name|t_GetBufFunction
modifier|*
name|f_GetBuf
parameter_list|,
name|t_PutBufFunction
modifier|*
name|f_PutBuf
parameter_list|,
name|uint32_t
name|dep_sw_entry
parameter_list|,
name|uint32_t
name|dep_sw_exit
parameter_list|,
name|uint32_t
name|dep_hw_entry
parameter_list|,
name|uint32_t
name|dep_hw_exit
parameter_list|,
name|t_BmDepletionCallback
modifier|*
name|f_Depletion
parameter_list|,
name|t_Handle
name|h_BufferPool
parameter_list|,
name|t_PhysToVirt
modifier|*
name|f_PhysToVirt
parameter_list|,
name|t_VirtToPhys
modifier|*
name|f_VirtToPhys
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @brief Fill pool with buffers.  *  * The bman_pool_fill() function fills the BMAN pool with buffers. The buffers  * are allocated through f_GetBuf function (see bman_pool_create() description).  *  * @param pool		The BMAN pool handle.  * @param nbufs		The number of buffers to allocate. To maximize  *			performance this value should be multiple of 8.  *  * @returns		Zero on success or error code on failure.  */
end_comment

begin_function_decl
name|int
name|bman_pool_fill
parameter_list|(
name|t_Handle
name|pool
parameter_list|,
name|uint16_t
name|nbufs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @brief Destroy pool.  *  * The bman_pool_destroy() function destroys the BMAN pool. Buffers for pool  * are free through f_PutBuf function (see bman_pool_create() description).  *  * @param pool		The BMAN pool handle.  *  * @returns		Zero on success or error code on failure.  */
end_comment

begin_function_decl
name|int
name|bman_pool_destroy
parameter_list|(
name|t_Handle
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @brief Get a buffer from BMAN pool.  *  * @param pool		The BMAN pool handle.  *  * @returns		Pointer to the buffer or NULL if pool is empty.  */
end_comment

begin_function_decl
name|void
modifier|*
name|bman_get_buffer
parameter_list|(
name|t_Handle
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @brief Put a buffer to BMAN pool.  *  * @param pool		The BMAN pool handle.  * @param buffer	The pointer to buffer.  *  * @returns		Zero on success or error code on failure.  */
end_comment

begin_function_decl
name|int
name|bman_put_buffer
parameter_list|(
name|t_Handle
name|pool
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * @brief Count free buffers in given pool.  *  * @param pool		The BMAN pool handle.  *  * @returns		Number of free buffers in pool.  */
end_comment

begin_function_decl
name|uint32_t
name|bman_count
parameter_list|(
name|t_Handle
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bus i/f  */
end_comment

begin_function_decl
name|int
name|bman_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bman_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bman_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bman_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bman_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BMAN_H */
end_comment

end_unit

