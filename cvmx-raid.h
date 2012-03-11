begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Interface to RAID block. This is not available on all chips.  *  *<hr>$Revision: 70030 $<hr>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_RAID_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_RAID_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CVMX_BUILD_FOR_LINUX_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<asm/octeon/cvmx-rad-defs.h>
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
comment|/**  * This structure defines the type of command words the RAID block  * will accept.  */
typedef|typedef
union|union
block|{
name|uint64_t
name|u64
decl_stmt|;
struct|struct
block|{
name|uint64_t
name|reserved_37_63
range|:
literal|27
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|q_cmp
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the Q pipe is in normal mode (CWORD[Q_CMP]=0) or in non-zero                                                 byte detect mode (CWORD[Q_CMP]=1).                                                 In non-zero byte detect mode, the Q OWORD[PTR] result is the non-zero detect                                                 result, which indicates the position of the first non-zero byte in the pipe result bytes.                                                 CWORD[Q_CMP] must not be set when CWORD[QOUT]=0, and must not be set                                                 when CWORD[Q_XOR] is set. */
name|uint64_t
name|p_cmp
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the P pipe is in normal mode (CWORD[P_CMP]=0) or in non-zero                                                 byte detect mode (CWORD[P_CMP]=1).                                                 In non-zero byte detect mode, the P OWORD[PTR] result is the non-zero detect                                                 result, which indicates the position of the first non-zero byte in the pipe result bytes.                                                 CWORD[P_CMP] must not be set when CWORD[POUT]=0, and must not be set                                                 when CWORD[P_XOR] is set. */
name|uint64_t
name|q_xor
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the Q output buffer bytes are the normal Q pipe result or the                                                 normal Q pipe result exclusive-OR'ed with the P pipe result.                                                 When CWORD[Q_XOR]=0 (and CWORD[Q_CMP]=0), the Q output buffer bytes are                                                 the normal Q pipe result, which does not include the P pipe result in any way.                                                 When CWORD[Q_XOR]=1, the Q output buffer bytes are the normal Q pipe result                                                 exclusive-OR'ed with the P pipe result, as if the P pipe result were another Q IWORD                                                 for the Q pipe with QMULT=1.                                                 CWORD[Q_XOR] must not be set unless both CWORD[POUT,QOUT] are set, and                                                 must not be set when CWORD[Q_CMP] is set. */
name|uint64_t
name|p_xor
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the P output buffer bytes are the normal P pipe result or the                                                 normal P pipe result exclusive-OR'ed with the Q pipe result.                                                 When CWORD[P_XOR]=0 (and CWORD[P_CMP]=0), the P output buffer bytes are                                                 the normal P pipe result, which does not include the Q pipe result in any way.                                                 When CWORD[P_XOR]=1, the P output buffer bytes are the normal P pipe result                                                 exclusive-OR'ed with the Q pipe result, as if the Q pipe result were another P                                                 IWORD for the P pipe.                                                 CWORD[P_XOR] must not be set unless both CWORD[POUT,QOUT] are set, and                                                 must not be set when CWORD[P_CMP] is set. */
name|uint64_t
name|wqe
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether RAD submits a work queue entry or writes an L2/DRAM byte to                                                 zero after completing the instruction.                                                 When CWORD[WQE] is set and RESP[PTR]!=0, RAD adds the work queue entry                                                 indicated by RESP[PTR] to the selected POW input queue after completing the                                                 instruction.                                                 When CWORD[WQE] is clear and RESP[PTR]!=0, RAD writes the L2/DRAM byte                                                 indicated by RESP[PTR] to zero after completing the instruction. */
name|uint64_t
name|qout
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the Q pipe is used by this instruction.                                                 If CWORD[QOUT] is set, IWORD[QEN] must be set for at least one IWORD.                                                 At least one of CWORD[QOUT,POUT] must be set. */
name|uint64_t
name|pout
range|:
literal|1
decl_stmt|;
comment|/**< Indicates whether the P pipe is used by this instruction.                                                 If CWORD[POUT] is set, IWORD[PEN] must be set for at least one IWORD.                                                 At least one of CWORD[QOUT,POUT] must be set. */
name|uint64_t
name|iword
range|:
literal|6
decl_stmt|;
comment|/**< Indicates the number of input buffers used.                                                 1<= CWORD[IWORD]<= 32. */
name|uint64_t
name|size
range|:
literal|24
decl_stmt|;
comment|/**< Indicates the size in bytes of all input buffers. When CWORD[Q_CMP,P_CMP]=0,                                                 also indicates the size of the Q/P output buffers.                                                 CWORD[SIZE] must be a multiple of 8B (i.e.<2:0> must be zero). */
block|}
name|cword
struct|;
struct|struct
block|{
name|uint64_t
name|reserved_58_63
range|:
literal|6
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|fw
range|:
literal|1
decl_stmt|;
comment|/**< When set, indicates that RAD can modify any byte in any (128B) cache line touched                                                 by L2/DRAM addresses OWORD[PTR] through OWORD[PTR]+CWORD[SIZE]­1.                                                 Setting OWORD[FW] can improve hardware performance, as some DRAM loads can                                                 be avoided on L2 cache misses. The Q OWORD[FW] must not be set when                                                 CWORD[Q_CMP] is set, and the P OWORD[FW] must not be set when                                                 CWORD[P_CMP] is set. */
name|uint64_t
name|nc
range|:
literal|1
decl_stmt|;
comment|/**< When set, indicates that RAD should not allocate L2 cache space for the P/Q data on                                                 L2 cache misses.                                                 OWORD[NC] should typically be clear, though setting OWORD[NC] can improve                                                 performance in some circumstances, as the L2 cache will not be polluted by P/Q data.                                                 The Q OWORD[NC] must not be set when CWORD[Q_CMP] is set, and the P                                                 OWORD[NC] must not be set when CWORD[P_CMP] is set. */
name|uint64_t
name|reserved_40_55
range|:
literal|16
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|addr
range|:
literal|40
decl_stmt|;
comment|/**< When CWORD[P_CMP,Q_CMP]=0, OWORD[PTR] indicates the starting address of                                                 the L2/DRAM buffer that will receive the P/Q data. In the non-compare mode, the                                                 output buffer receives all of the output buffer bytes.                                                 When CWORD[P_CMP,Q_CMP]=1, the corresponding P/Q pipe is in compare mode,                                                 and the only output of the pipe is the non-zero detect result. In this case,                                                 OWORD[PTR] indicates the 8-byte location of the non-zero detect result. */
block|}
name|oword
struct|;
struct|struct
block|{
name|uint64_t
name|reserved_57_63
range|:
literal|7
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|nc
range|:
literal|1
decl_stmt|;
comment|/**< When set, indicates that RAD should not allocate L2 cache space for this input buffer                                                 data on L2 cache misses.                                                 Setting IWORD[NC] may improve performance in some circumstances, as the L2                                                 cache may not be polluted with input buffer data. */
name|uint64_t
name|reserved_50_55
range|:
literal|6
decl_stmt|;
comment|/**< Must be zero */
name|uint64_t
name|qen
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that this input buffer data should participate in the Q pipe result.                                                 The Q pipe hardware multiplies each participating input byte by IWORD[QMULT]                                                 before accumulating them by exclusive-OR'ing.                                                 IWORD[QEN] must not be set when CWORD[QOUT] is not set.                                                 If CWORD[QOUT] is set, IWORD[QEN] must be set for at least one IWORD. */
name|uint64_t
name|pen
range|:
literal|1
decl_stmt|;
comment|/**< Indicates that this input buffer data should participate in the P pipe result.                                                 The P pipe hardware accumulates each participating input byte by bit-wise                                                 exclusive-OR'ing it.                                                 IWORD[PEN] must not be set when CWORD[POUT] is not set.                                                 If CWORD[POUT] is set, IWORD[PEN] must be set for at least one IWORD. */
name|uint64_t
name|qmult
range|:
literal|8
decl_stmt|;
comment|/**< The Q pipe multiplier for the input buffer. Section 26.1 above describes the GF(28)                                                 multiplication algorithm.                                                 IWORD[QMULT] must be zero when IWORD[QEN] is not set.                                                 IWORD[QMULT] must not be zero when IWORD[QEN] is set.                                                 When IWORD[QMULT] is 1, the multiplication simplifies to the identity function,                                                 and the Q pipe performs the same XOR function as the P pipe. */
name|uint64_t
name|addr
range|:
literal|40
decl_stmt|;
comment|/**< The starting address of the input buffer in L2/DRAM.                                                 IWORD[PTR] must be naturally-aligned on an 8 byte boundary (i.e.<2:0> must be                                                 zero). */
block|}
name|iword
struct|;
block|}
name|cvmx_raid_word_t
typedef|;
comment|/**  * Initialize the RAID block  *  * @param polynomial Coefficients for the RAID polynomial  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_raid_initialize
parameter_list|(
name|cvmx_rad_reg_polynomial_t
name|polynomial
parameter_list|)
function_decl|;
comment|/**  * Shutdown the RAID block. RAID must be idle when  * this function is called.  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_raid_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/**  * Submit a command to the RAID block  *  * @param num_words Number of command words to submit  * @param words     Command words  *  * @return Zero on success, negative on failure  */
name|int
name|cvmx_raid_submit
parameter_list|(
name|int
name|num_words
parameter_list|,
name|cvmx_raid_word_t
name|words
index|[]
parameter_list|)
function_decl|;
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

