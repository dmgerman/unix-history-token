begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to the PCI / PCIe DMA engines. These are only avialable  * on chips with PCI / PCIe.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_DMA_ENGINES_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_DMA_ENGINES_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-dpi-defs.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"cvmx-dpi-defs.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
typedef|typedef
enum|enum
block|{
name|CVMX_DMA_ENGINE_TRANSFER_OUTBOUND
init|=
literal|0
block|,
comment|/**< OUTBOUND (read from L2/DRAM, write into PCI / PCIe memory space) */
name|CVMX_DMA_ENGINE_TRANSFER_INBOUND
init|=
literal|1
block|,
comment|/**< INBOUND (read from PCI / PCIe memory space, write into L2/DRAM) */
name|CVMX_DMA_ENGINE_TRANSFER_INTERNAL
init|=
literal|2
block|,
comment|/**< INTERNAL-ONLY (read from L2/DRAM, write into L2/DRAM). Only available on chips with PCIe */
name|CVMX_DMA_ENGINE_TRANSFER_EXTERNAL
init|=
literal|3
block|,
comment|/**< EXTERNAL-ONLY (read from PCIe memory space, write into PCIe memory space). Only available on chips with PCIe */
block|}
name|cvmx_dma_engine_transfer_t
typedef|;
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved_60_63
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|fport
range|:
literal|2
decl_stmt|;
comment|/**< First port. FPort indicates the physical PCIe port used for the                                                 PCIe memory space pointers in the FIRST POINTERS block in the                                                 EXTERNAL-ONLY case. Must be zero in the OUTBOUND, INBOUND and                                                 INTERNAL-ONLY cases. Must be zero on chips with PCI */
name|uint64_t
name|lport
range|:
literal|2
decl_stmt|;
comment|/**< Last port. LPort indicates the physical PCIe port used for the                                                 PCIe memory space pointers in the LAST POINTERS block in the                                                 OUTBOUND, INBOUND, and EXTERNAL-ONLY cases. Must be zero in the                                                 INTERNAL-ONLY case. Must be zero on chips with PCI */
name|cvmx_dma_engine_transfer_t
name|type
range|:
literal|2
decl_stmt|;
comment|/**< Type ­ A given PCI DMA transfer is either OUTBOUND (read from L2/DRAM,                                                 write into PCI / PCIe memory space), INBOUND (read from PCI / PCIe memory space, write                                                 into L2/DRAM), INTERNAL-ONLY (read from L2/DRAM, write into L2/DRAM), or                                                 EXTERNAL-ONLY (read from PCIe memory space, write into PCIe memory space). */
name|uint64_t
name|wqp
range|:
literal|1
decl_stmt|;
comment|/**< Work-queue pointer. When WQP = 1, PTR (if non-zero) is a pointer to a                                                 work-queue entry that is submitted by the hardware after completing the DMA;                                                 when WQP = 0, PTR (if non-zero) is a pointer to a byte in local memory that                                                 is written to 0 by the hardware after completing the DMA. */
name|uint64_t
name|c
range|:
literal|1
decl_stmt|;
comment|/**< C ­ Counter. 1 = use counter 1, 0 = use counter 0.                                                 The C bit selects between the two counters (NPEI_DMA_CNTS[DMA0,DMA1])                                                 that can optionally be updated after an OUTBOUND or EXTERNAL-ONLY                                                 transfer, and also selects between the two forced-interrupt bits                                                 (NPEI_INT_SUMn[DMA0_FI, DMA1_FI]) that can optionally be set after an                                                 OUTBOUND or EXTERNAL-ONLY transfer. C must be zero for INBOUND or                                                 INTERNAL-ONLY transfers. */
name|uint64_t
name|ca
range|:
literal|1
decl_stmt|;
comment|/**< CA ­ Counter add.                                                 When CA = 1, the hardware updates the selected counter after it completes the                                                 PCI DMA OUTBOUND or EXTERNAL-ONLY Instruction.                                                     - If C = 0, PCIE_DMA_CNT0 is updated                                                     - If C = 1, PCIE_DMA_CNT1 is updated.                                                 Note that this update may indirectly cause                                                 NPEI_INT_SUM[DCNT0,DCNT1,DTIME0,DTIME1] to become set (depending                                                 on the NPEI_DMA*_INT_LEVEL settings), so may cause interrupts to occur on a                                                 remote PCI host.                                                     - If NPEI_DMA_CONTROL[O_ADD1] = 1, the counter is updated by 1.                                                     - If NPEI_DMA_CONTROL[O_ADD1] = 0, the counter is updated by the total                                                     bytes in the transfer.                                                 When CA = 0, the hardware does not update any counters.                                                 For an INBOUND or INTERNAL-ONLY PCI DMA transfer, CA must never be                                                 set, and the hardware never adds to the counters. */
name|uint64_t
name|fi
range|:
literal|1
decl_stmt|;
comment|/**< FI ­ Force interrupt.                                                 When FI is set for an OUTBOUND or EXTERNAL-ONLY transfer, the hardware                                                 sets a forced interrupt bit after it completes the PCI DMA Instruction. If C = 0,                                                 NPEI_INT_SUMn[DMA0_FI] is set, else NPEI_INT_SUMn[DMA1_FI] is set. For                                                 an INBOUND or INTERNAL-ONLY PCI DMA operation, FI must never be set,                                                 and the hardware never generates interrupts. */
name|uint64_t
name|ii
range|:
literal|1
decl_stmt|;
comment|/**< II­ Ignore the I bit (i.e. the I bit of the PCI DMA instruction local pointer).                                                 For OUTBOUND transfers when II = 1, ignore the I bit and the FL bit in the                                                 DMA HDR alone determines whether the hardware frees any/all of the local                                                 buffers in the FIRST POINTERS area:                                                     - when FL = 1, the hardware frees the local buffer when II=1.                                                     - when FL = 0, the hardware does not free the local buffer when II=1.                                                 For OUTBOUND transfers when II = 0, the I bit in the local pointer selects                                                 whether local buffers are freed on a pointer-by-pointer basis:                                                     - when (FL  I) is true, the hardware frees the local buffer when II=0.                                                 For INBOUND, INTERNAL-ONLY, and EXTERNAL-ONLY PCI DMA transfers,                                                 II must never be set, and local buffers are never freed. */
name|uint64_t
name|fl
range|:
literal|1
decl_stmt|;
comment|/**< FL ­ Free local buffer.                                                 When FL = 1, for an OUTBOUND operation, it indicates that the local buffers in                                                 the FIRST BUFFERS area should be freed.                                                 If II = 1, the FL bit alone indicates whether the local buffer should be freed:                                                     - when FL = 1, the hardware frees the local buffer when II=1.                                                     - when FL = 0, the hardware does not free the local buffer when II=1.                                                 If II = 0, the I bit in the local pointer (refer to Section 9.5.2) determines whether                                                 the local buffer is freed:                                                     - when (FL  I) is true, the hardware frees the local buffer when II=0.                                                 For an INBOUND, INTERNAL-ONLY, or EXTERNAL-ONLY PCI DMA transfer,                                                 FL must never be set, and local buffers are never freed. */
name|uint64_t
name|nlst
range|:
literal|4
decl_stmt|;
comment|/**< NLST ­ Number Last pointers.                                                 The number of pointers in the LAST POINTERS area.                                                 In the INBOUND, OUTBOUND, and EXTERNAL-ONLY cases, the LAST                                                 POINTERS area contains PCI components, and the number of 64-bit words                                                 required in the LAST POINTERS area is:                                                     - HDR.NLST + ((HDR.NLST + 3)/4) where the division removes the fraction.                                                 In the INTERNAL-ONLY case, the LAST POINTERS area contains local                                                 pointers, and the number of 64-bit words required in the LAST POINTERS area is:                                                     - HDR.NLST                                                 Note that the sum of the number of 64-bit words in the LAST POINTERS and                                                 FIRST POINTERS area must never exceed 31. */
name|uint64_t
name|nfst
range|:
literal|4
decl_stmt|;
comment|/**< NFST ­ Number First pointers.                                                 The number of pointers in the FIRST POINTERS area.                                                 In the INBOUND, OUTBOUND, and INTERNAL-ONLY cases, the FIRST                                                 POINTERS area contains local pointers, and the number of 64-bit words required                                                 in the FIRST POINTERS area is:                                                     - HDR.NFST                                                 In the EXTERNAL-ONLY case, the FIRST POINTERS area contains PCI                                                 components, and the number of 64-bit words required in the FIRST POINTERS                                                 area is:                                                     - HDR.NFST + ((HDR.NFST + 3)/4) where the division removes the fraction. */
name|uint64_t
name|addr
range|:
literal|40
decl_stmt|;
comment|/**< PTR ­ Pointer, either a work-queue-entry pointer (when WQP = 1) or a local                                                 memory pointer (WQP = 0).                                                 When WQP = 1 and PTR  0x0, the hardware inserts the work-queue entry                                                 indicated by PTR into a POW input queue after the PCI DMA operation is                                                 complete. (Section 5.4 describes the work queue entry requirements in this                                                 case.) When WQP = 1, PTR<2:0> must be 0x0.                                                 When WQP = 0 and PTR  0x0, the hardware writes the single byte in local                                                 memory indicated by PTR to 0x0 after the PCI DMA operation is complete.                                                 NPEI_DMA_CONTROL[B0_LEND] selects the endian-ness of PTR in this                                                 case.                                                 When PTR = 0x0, the hardware performs no operation after the PCI DMA                                                 operation is complete. */
block|}
name|s
struct|;
block|}
name|cvmx_dma_engine_header_t
typedef|;
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|i
range|:
literal|1
decl_stmt|;
comment|/**< I ­ Invert free.                                                 This bit gives the software the ability to free buffers independently for an                                                 OUTBOUND PCI DMA transfer. I is not used by the hardware when II is set. I                                                 must not be set, and buffers are never freed, for INBOUND, INTERNAL-ONLY,                                                 and EXTERNAL-ONLY PCI DMA transfers. */
name|uint64_t
name|back
range|:
literal|4
decl_stmt|;
comment|/**< Back ­ Backup amount.                                                 Allows the start of a buffer that is to be freed during an OUTBOUND transfer to                                                 be different from the ptr value. Back specifies the amount to subtract from the                                                 pointer to reach the start when freeing a buffer.                                                 The address that is the start of the buffer being freed is:                                                     - Buffer start address = ((ptr>> 7) - Back)<< 7.                                                 Back is only used by the hardware when the buffer corresponding to ptr is freed.                                                 Back must be 0x0, and buffers are never freed, for INBOUND, INTERNAL-ONLY,                                                 and EXTERNAL-ONLY PCI DMA transfers. */
name|uint64_t
name|pool
range|:
literal|3
decl_stmt|;
comment|/**< Pool ­ Free pool.                                                 Specifies which pool (of the eight hardware-managed FPA free pools) receives the                                                 buffer associated with ptr when freed during an OUTBOUND transfer.                                                 Pool is only used when the buffer corresponding to ptr is freed. Pool must be 0x0,                                                 and buffers are never freed, for INBOUND, INTERNAL-ONLY, and EXTERNAL-ONLY                                                 PCI DMA transfers. */
name|uint64_t
name|f
range|:
literal|1
decl_stmt|;
comment|/**< F ­ Full-block writes are allowed.                                                 When set, the hardware is permitted to write all the bytes in the cache blocks                                                 covered by ptr, ptr + Size - 1. This can improve memory system performance                                                 when the write misses in the L2 cache.                                                 F can only be set for local pointers that can be written to:                                                     - The local pointers in the FIRST POINTERS area that are write pointers for                                                     INBOUND transfers.                                                     - The local pointers in the LAST POINTERS area that are always write                                                     pointers (when present for INTERNAL-ONLY transfers).                                                 F must not be set for local pointers that are not written to:                                                     - The local pointers in the FIRST POINTERS area for OUTBOUND and                                                     INTERNAL-ONLY transfers. */
name|uint64_t
name|a
range|:
literal|1
decl_stmt|;
comment|/**< A ­ Allocate L2.                                                 This is a hint to the hardware that the cache blocks should be allocated in the L2                                                 cache (if they were not already). */
name|uint64_t
name|l
range|:
literal|1
decl_stmt|;
comment|/**< L ­ Little-endian.                                                 When L is set, the data at ptr is in little-endian format rather than big-endian. */
name|uint64_t
name|size
range|:
literal|13
decl_stmt|;
comment|/**< Size ­ Size in bytes of the contiguous space specified by ptr. A Size value of 0 is                                                 illegal. Note that the sum of the sizes in the FIRST POINTERS area must always                                                 exactly equal the sum of the sizes/lengths in the LAST POINTERS area:                                                     - In the OUTBOUND and INBOUND cases, the HDR.NFST size fields in the                                                     local pointers in the FIRST POINTERS area must exactly equal the lengths                                                     of the HDR.NLST fragments in the PCI components in the LAST POINTERS                                                     area.                                                     - In the INTERNAL-ONLY case, the HDR.NFST size fields in the local                                                     pointers in the FIRST POINTERS area must equal the HDR.NLST size                                                     fields in the local pointers in the LAST POINTERS area. */
name|uint64_t
name|reserved_36_39
range|:
literal|4
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|addr
range|:
literal|36
decl_stmt|;
comment|/**< L2/DRAM byte pointer. Points to where the packet data starts.                                                 Ptr can be any byte alignment. Note that ptr is interpreted as a big-endian byte                                                 pointer when L is clear, a little-endian byte pointer when L is set. */
block|}
name|internal
struct|;
struct|struct
block|{
name|uint64_t
name|len0
range|:
literal|16
decl_stmt|;
comment|/**< Length of PCI / PCIe memory for address 0 */
name|uint64_t
name|len1
range|:
literal|16
decl_stmt|;
comment|/**< Length of PCI / PCIe memory for address 1 */
name|uint64_t
name|len2
range|:
literal|16
decl_stmt|;
comment|/**< Length of PCI / PCIe memory for address 2 */
name|uint64_t
name|len3
range|:
literal|16
decl_stmt|;
comment|/**< Length of PCI / PCIe memory for address 3 */
block|}
name|pcie_length
struct|;
block|}
name|cvmx_dma_engine_buffer_t
typedef|;
comment|/**  * Initialize the DMA engines for use  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_dma_engine_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Shutdown all DMA engines. The engeines must be idle when this  * function is called.  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_dma_engine_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Return the number of DMA engimes supported by this chip  *  * @return Number of DMA engines  */
name|int
name|cvmx_dma_engine_get_num
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Submit a series of DMA command to the DMA engines.  *  * @param engine  Engine to submit to (0 to cvmx_dma_engine_get_num()-1)  * @param header  Command header  * @param num_buffers  *                The number of data pointers  * @param buffers Command data pointers  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_dma_engine_submit
parameter_list|(
name|int
name|engine
parameter_list|,
name|cvmx_dma_engine_header_t
name|header
parameter_list|,
name|int
name|num_buffers
parameter_list|,
name|cvmx_dma_engine_buffer_t
name|buffers
index|[]
parameter_list|)
function_decl|;
comment|/**  * Build the first and last pointers based on a DMA engine header  * and submit them to the engine. The purpose of this function is  * to simplify the building of DMA engine commands by automatically  * converting a simple address and size into the apropriate internal  * or PCI / PCIe address list. This function does not support gather lists,  * so you will need to build your own lists in that case.  *  * @param engine Engine to submit to (0 to cvmx_dma_engine_get_num()-1)  * @param header DMA Command header. Note that the nfst and nlst fields do not  *               need to be filled in. All other fields must be set properly.  * @param first_address  *               Address to use for the first pointers. In the case of INTERNAL,  *               INBOUND, and OUTBOUND this is an Octeon memory address. In the  *               case of EXTERNAL, this is the source PCI / PCIe address.  * @param last_address  *               Address to use for the last pointers. In the case of EXTERNAL,  *               INBOUND, and OUTBOUND this is a PCI / PCIe address. In the  *               case of INTERNAL, this is the Octeon memory destination address.  * @param size   Size of the transfer to perform.  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_dma_engine_transfer
parameter_list|(
name|int
name|engine
parameter_list|,
name|cvmx_dma_engine_header_t
name|header
parameter_list|,
name|uint64_t
name|first_address
parameter_list|,
name|uint64_t
name|last_address
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
comment|/**  * Simplified interface to the DMA engines to emulate memcpy()  *  * @param engine Engine to submit to (0 to cvmx_dma_engine_get_num()-1)  * @param dest   Pointer to the destination memory. cvmx_ptr_to_phys() will be  *               used to turn this into a physical address. It cannot be a local  *               or CVMX_SHARED block.  * @param source Pointer to the source memory.  *               cvmx_ptr_to_phys() will be used to turn this  *               into a physical address. It cannot be a local  *               or CVMX_SHARED block.  * @param length Number of bytes to copy  *  * @return Zero on success, negative on failure  */
specifier|static
specifier|inline
name|int
name|cvmx_dma_engine_memcpy
parameter_list|(
name|int
name|engine
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|void
modifier|*
name|source
parameter_list|,
name|int
name|length
parameter_list|)
block|{
name|cvmx_dma_engine_header_t
name|header
decl_stmt|;
name|header
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
name|header
operator|.
name|s
operator|.
name|type
operator|=
name|CVMX_DMA_ENGINE_TRANSFER_INTERNAL
expr_stmt|;
return|return
name|cvmx_dma_engine_transfer
argument_list|(
name|engine
argument_list|,
name|header
argument_list|,
name|cvmx_ptr_to_phys
argument_list|(
name|source
argument_list|)
argument_list|,
name|cvmx_ptr_to_phys
argument_list|(
name|dest
argument_list|)
argument_list|,
name|length
argument_list|)
return|;
block|}
comment|/**  * Simplified interface to the DMA engines to emulate memcpy()  * When dici_mode is enabled, send zero byte.  *  * @param engine Engine to submit to (0 to cvmx_dma_engine_get_num()-1)  * @param dest   Pointer to the destination memory. cvmx_ptr_to_phys() will be  *               used to turn this into a physical address. It cannot be a local  *               or CVMX_SHARED block.  * @param source Pointer to the source memory.  *               cvmx_ptr_to_phys() will be used to turn this  *               into a physical address. It cannot be a local  *               or CVMX_SHARED block.  * @param length Number of bytes to copy  * @param core   core number for zero byte write  *  * @return Zero on success, negative on failure  */
specifier|static
specifier|inline
name|int
name|cvmx_dma_engine_memcpy_zero_byte
parameter_list|(
name|int
name|engine
parameter_list|,
name|void
modifier|*
name|dest
parameter_list|,
name|void
modifier|*
name|source
parameter_list|,
name|int
name|length
parameter_list|,
name|int
name|core
parameter_list|)
block|{
name|cvmx_dma_engine_header_t
name|header
decl_stmt|;
name|header
operator|.
name|u64
operator|=
literal|0
expr_stmt|;
name|header
operator|.
name|s
operator|.
name|type
operator|=
name|CVMX_DMA_ENGINE_TRANSFER_INTERNAL
expr_stmt|;
comment|/* If dici_mode is set, DPI increments the DPI_DMA_PPn_CNT[CNT], where the        value of core n is PTR<5:0>-1 when WQP=0 and PTR != 0&& PTR< 64. */
if|if
condition|(
name|octeon_has_feature
argument_list|(
name|OCTEON_FEATURE_DICI_MODE
argument_list|)
condition|)
block|{
name|cvmx_dpi_dma_control_t
name|dma_control
decl_stmt|;
name|dma_control
operator|.
name|u64
operator|=
name|cvmx_read_csr
argument_list|(
name|CVMX_DPI_DMA_CONTROL
argument_list|)
expr_stmt|;
if|if
condition|(
name|dma_control
operator|.
name|s
operator|.
name|dici_mode
condition|)
block|{
name|header
operator|.
name|s
operator|.
name|wqp
operator|=
literal|0
expr_stmt|;
comment|// local memory pointer
name|header
operator|.
name|s
operator|.
name|addr
operator|=
name|core
operator|+
literal|1
expr_stmt|;
block|}
block|}
return|return
name|cvmx_dma_engine_transfer
argument_list|(
name|engine
argument_list|,
name|header
argument_list|,
name|cvmx_ptr_to_phys
argument_list|(
name|source
argument_list|)
argument_list|,
name|cvmx_ptr_to_phys
argument_list|(
name|dest
argument_list|)
argument_list|,
name|length
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __CVMX_CMD_QUEUE_H__
end_comment

end_unit

