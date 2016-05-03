begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__IOAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IOAT_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * This file defines the public interface to the IOAT driver.  */
end_comment

begin_comment
comment|/*  * Enables an interrupt for this operation. Typically, you would only enable  * this on the last operation in a group  */
end_comment

begin_define
define|#
directive|define
name|DMA_INT_EN
value|0x1
end_define

begin_comment
comment|/*  * Like M_NOWAIT.  Operations will return NULL if they cannot allocate a  * descriptor without blocking.  */
end_comment

begin_define
define|#
directive|define
name|DMA_NO_WAIT
value|0x2
end_define

begin_comment
comment|/*  * Disallow prefetching the source of the following operation.  Ordinarily, DMA  * operations can be pipelined on some hardware.  E.g., operation 2's source  * may be prefetched before operation 1 completes.  */
end_comment

begin_define
define|#
directive|define
name|DMA_FENCE
value|0x4
end_define

begin_define
define|#
directive|define
name|_DMA_GENERIC_FLAGS
value|(DMA_INT_EN | DMA_NO_WAIT | DMA_FENCE)
end_define

begin_comment
comment|/*  * Emit a CRC32C as the result of a ioat_copy_crc() or ioat_crc().  */
end_comment

begin_define
define|#
directive|define
name|DMA_CRC_STORE
value|0x8
end_define

begin_comment
comment|/*  * Compare the CRC32C of a ioat_copy_crc() or ioat_crc() against an expeceted  * value.  It is invalid to specify both TEST and STORE.  */
end_comment

begin_define
define|#
directive|define
name|DMA_CRC_TEST
value|0x10
end_define

begin_define
define|#
directive|define
name|_DMA_CRC_TESTSTORE
value|(DMA_CRC_STORE | DMA_CRC_TEST)
end_define

begin_comment
comment|/*  * Use an inline comparison CRC32C or emit an inline CRC32C result.  Invalid  * without one of STORE or TEST.  */
end_comment

begin_define
define|#
directive|define
name|DMA_CRC_INLINE
value|0x20
end_define

begin_define
define|#
directive|define
name|_DMA_CRC_FLAGS
value|(DMA_CRC_STORE | DMA_CRC_TEST | DMA_CRC_INLINE)
end_define

begin_comment
comment|/*  * Hardware revision number.  Different hardware revisions support different  * features.  For example, 3.2 cannot read from MMIO space, while 3.3 can.  */
end_comment

begin_define
define|#
directive|define
name|IOAT_VER_3_0
value|0x30
end_define

begin_define
define|#
directive|define
name|IOAT_VER_3_2
value|0x32
end_define

begin_define
define|#
directive|define
name|IOAT_VER_3_3
value|0x33
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_dmaengine_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|bus_dmadesc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bus_dmaengine_callback_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|error
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Called first to acquire a reference to the DMA channel  *  * Flags may be M_WAITOK or M_NOWAIT.  */
end_comment

begin_function_decl
name|bus_dmaengine_t
name|ioat_get_dmaengine
parameter_list|(
name|uint32_t
name|channel_index
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Release the DMA channel */
end_comment

begin_function_decl
name|void
name|ioat_put_dmaengine
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check the DMA engine's HW version */
end_comment

begin_function_decl
name|int
name|ioat_get_hwversion
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|ioat_get_max_io_size
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Set interrupt coalescing on a DMA channel.  *  * The argument is in microseconds.  A zero value disables coalescing.  Any  * other value delays interrupt generation for N microseconds to provide  * opportunity to coalesce multiple operations into a single interrupt.  *  * Returns an error status, or zero on success.  *  * - ERANGE if the given value exceeds the delay supported by the hardware.  *   (All current hardware supports a maximum of 0x3fff microseconds delay.)  * - ENODEV if the hardware does not support interrupt coalescing.  */
end_comment

begin_function_decl
name|int
name|ioat_set_interrupt_coalesce
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|uint16_t
name|delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return the maximum supported coalescing period, for use in  * ioat_set_interrupt_coalesce().  If the hardware does not support coalescing,  * returns zero.  */
end_comment

begin_function_decl
name|uint16_t
name|ioat_get_max_coalesce_period
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquire must be called before issuing an operation to perform. Release is  * called after.  Multiple operations can be issued within the context of one  * acquire and release  */
end_comment

begin_function_decl
name|void
name|ioat_acquire
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ioat_release
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquire_reserve can be called to ensure there is room for N descriptors.  If  * it succeeds, the next N valid operations will successfully enqueue.  *  * It may fail with:  *   - ENXIO if the channel is in an errored state, or the driver is being  *     unloaded  *   - EAGAIN if mflags included M_NOWAIT  *  * On failure, the caller does not hold the dmaengine.  */
end_comment

begin_function_decl
name|int
name|ioat_acquire_reserve
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|unsigned
name|n
parameter_list|,
name|int
name|mflags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Issue a blockfill operation.  The 64-bit pattern 'fillpattern' is written to  * 'len' physically contiguous bytes at 'dst'.  *  * Only supported on devices with the BFILL capability.  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_blockfill
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|dst
parameter_list|,
name|uint64_t
name|fillpattern
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Issues the copy data operation */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_copy
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|dst
parameter_list|,
name|bus_addr_t
name|src
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Issue a copy data operation, with constraints:  *  - src1, src2, dst1, dst2 are all page-aligned addresses  *  - The quantity to copy is exactly 2 pages;  *  - src1 -> dst1, src2 -> dst2  *  * Why use this instead of normal _copy()?  You can copy two non-contiguous  * pages (src, dst, or both) with one descriptor.  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_copy_8k_aligned
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|dst1
parameter_list|,
name|bus_addr_t
name|dst2
parameter_list|,
name|bus_addr_t
name|src1
parameter_list|,
name|bus_addr_t
name|src2
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy len bytes from dst to src, like ioat_copy().  *  * Additionally, accumulate a CRC32C of the data.  *  * If initialseed is not NULL, the value it points to is used to seed the  * initial value of the CRC32C.  *  * If flags include DMA_CRC_STORE and not DMA_CRC_INLINE, crcptr is written  * with the 32-bit CRC32C result (in wire format).  *  * If flags include DMA_CRC_TEST and not DMA_CRC_INLINE, the computed CRC32C is  * compared with the 32-bit CRC32C pointed to by crcptr.  If they do not match,  * a channel error is raised.  *  * If the DMA_CRC_INLINE flag is set, crcptr is ignored and the DMA engine uses  * the 4 bytes trailing the source data (TEST) or the destination data (STORE).  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_copy_crc
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|dst
parameter_list|,
name|bus_addr_t
name|src
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|uint32_t
modifier|*
name|initialseed
parameter_list|,
name|bus_addr_t
name|crcptr
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * ioat_crc() is nearly identical to ioat_copy_crc(), but does not actually  * move data around.  *  * Like ioat_copy_crc, ioat_crc computes a CRC32C over len bytes pointed to by  * src.  The flags affect its operation in the same way, with one exception:  *  * If flags includes both DMA_CRC_STORE and DMA_CRC_INLINE, the computed CRC32C  * is written to the 4 bytes trailing the *source* data.  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_crc
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|src
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|uint32_t
modifier|*
name|initialseed
parameter_list|,
name|bus_addr_t
name|crcptr
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Issues a null operation. This issues the operation to the hardware, but the  * hardware doesn't do anything with it.  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_null
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IOAT_H__ */
end_comment

end_unit

