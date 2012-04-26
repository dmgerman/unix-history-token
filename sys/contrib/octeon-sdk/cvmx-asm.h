begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * This is file defines ASM primitives for the executive.   *<hr>$Revision: 70030 $<hr>  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_ASM_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_ASM_H__
end_define

begin_define
define|#
directive|define
name|CVMX_MAX_CORES
value|(32)
end_define

begin_define
define|#
directive|define
name|COP0_INDEX
value|$0,0
end_define

begin_comment
comment|/* TLB read/write index */
end_comment

begin_define
define|#
directive|define
name|COP0_RANDOM
value|$1,0
end_define

begin_comment
comment|/* TLB random index */
end_comment

begin_define
define|#
directive|define
name|COP0_ENTRYLO0
value|$2,0
end_define

begin_comment
comment|/* TLB entryLo0 */
end_comment

begin_define
define|#
directive|define
name|COP0_ENTRYLO1
value|$3,0
end_define

begin_comment
comment|/* TLB entryLo1 */
end_comment

begin_define
define|#
directive|define
name|COP0_CONTEXT
value|$4,0
end_define

begin_comment
comment|/* Context */
end_comment

begin_define
define|#
directive|define
name|COP0_PAGEMASK
value|$5,0
end_define

begin_comment
comment|/* TLB pagemask */
end_comment

begin_define
define|#
directive|define
name|COP0_PAGEGRAIN
value|$5,1
end_define

begin_comment
comment|/* TLB config for max page sizes */
end_comment

begin_define
define|#
directive|define
name|COP0_WIRED
value|$6,0
end_define

begin_comment
comment|/* TLB number of wired entries */
end_comment

begin_define
define|#
directive|define
name|COP0_HWRENA
value|$7,0
end_define

begin_comment
comment|/* rdhw instruction enable per register */
end_comment

begin_define
define|#
directive|define
name|COP0_BADVADDR
value|$8,0
end_define

begin_comment
comment|/* Bad virtual address */
end_comment

begin_define
define|#
directive|define
name|COP0_COUNT
value|$9,0
end_define

begin_comment
comment|/* Mips count register */
end_comment

begin_define
define|#
directive|define
name|COP0_CVMCOUNT
value|$9,6
end_define

begin_comment
comment|/* Cavium count register */
end_comment

begin_define
define|#
directive|define
name|COP0_CVMCTL
value|$9,7
end_define

begin_comment
comment|/* Cavium control */
end_comment

begin_define
define|#
directive|define
name|COP0_ENTRYHI
value|$10,0
end_define

begin_comment
comment|/* TLB entryHi */
end_comment

begin_define
define|#
directive|define
name|COP0_COMPARE
value|$11,0
end_define

begin_comment
comment|/* Mips compare register */
end_comment

begin_define
define|#
directive|define
name|COP0_POWTHROTTLE
value|$11,6
end_define

begin_comment
comment|/* Power throttle register */
end_comment

begin_define
define|#
directive|define
name|COP0_CVMMEMCTL
value|$11,7
end_define

begin_comment
comment|/* Cavium memory control */
end_comment

begin_define
define|#
directive|define
name|COP0_STATUS
value|$12,0
end_define

begin_comment
comment|/* Mips status register */
end_comment

begin_define
define|#
directive|define
name|COP0_INTCTL
value|$12,1
end_define

begin_comment
comment|/* Useless (Vectored interrupts) */
end_comment

begin_define
define|#
directive|define
name|COP0_SRSCTL
value|$12,2
end_define

begin_comment
comment|/* Useless (Shadow registers) */
end_comment

begin_define
define|#
directive|define
name|COP0_CAUSE
value|$13,0
end_define

begin_comment
comment|/* Mips cause register */
end_comment

begin_define
define|#
directive|define
name|COP0_EPC
value|$14,0
end_define

begin_comment
comment|/* Exception program counter */
end_comment

begin_define
define|#
directive|define
name|COP0_PRID
value|$15,0
end_define

begin_comment
comment|/* Processor ID */
end_comment

begin_define
define|#
directive|define
name|COP0_EBASE
value|$15,1
end_define

begin_comment
comment|/* Exception base */
end_comment

begin_define
define|#
directive|define
name|COP0_CONFIG
value|$16,0
end_define

begin_comment
comment|/* Misc config options */
end_comment

begin_define
define|#
directive|define
name|COP0_CONFIG1
value|$16,1
end_define

begin_comment
comment|/* Misc config options */
end_comment

begin_define
define|#
directive|define
name|COP0_CONFIG2
value|$16,2
end_define

begin_comment
comment|/* Misc config options */
end_comment

begin_define
define|#
directive|define
name|COP0_CONFIG3
value|$16,3
end_define

begin_comment
comment|/* Misc config options */
end_comment

begin_define
define|#
directive|define
name|COP0_WATCHLO0
value|$18,0
end_define

begin_comment
comment|/* Address watch registers */
end_comment

begin_define
define|#
directive|define
name|COP0_WATCHLO1
value|$18,1
end_define

begin_comment
comment|/* Address watch registers */
end_comment

begin_define
define|#
directive|define
name|COP0_WATCHHI0
value|$19,0
end_define

begin_comment
comment|/* Address watch registers */
end_comment

begin_define
define|#
directive|define
name|COP0_WATCHHI1
value|$19,1
end_define

begin_comment
comment|/* Address watch registers */
end_comment

begin_define
define|#
directive|define
name|COP0_XCONTEXT
value|$20,0
end_define

begin_comment
comment|/* OS context */
end_comment

begin_define
define|#
directive|define
name|COP0_MULTICOREDEBUG
value|$22,0
end_define

begin_comment
comment|/* Cavium debug */
end_comment

begin_define
define|#
directive|define
name|COP0_DEBUG
value|$23,0
end_define

begin_comment
comment|/* Debug status */
end_comment

begin_define
define|#
directive|define
name|COP0_DEPC
value|$24,0
end_define

begin_comment
comment|/* Debug PC */
end_comment

begin_define
define|#
directive|define
name|COP0_PERFCONTROL0
value|$25,0
end_define

begin_comment
comment|/* Performance counter control */
end_comment

begin_define
define|#
directive|define
name|COP0_PERFCONTROL1
value|$25,2
end_define

begin_comment
comment|/* Performance counter control */
end_comment

begin_define
define|#
directive|define
name|COP0_PERFVALUE0
value|$25,1
end_define

begin_comment
comment|/* Performance counter */
end_comment

begin_define
define|#
directive|define
name|COP0_PERFVALUE1
value|$25,3
end_define

begin_comment
comment|/* Performance counter */
end_comment

begin_define
define|#
directive|define
name|COP0_CACHEERRI
value|$27,0
end_define

begin_comment
comment|/* I cache error status */
end_comment

begin_define
define|#
directive|define
name|COP0_CACHEERRD
value|$27,1
end_define

begin_comment
comment|/* D cache error status */
end_comment

begin_define
define|#
directive|define
name|COP0_TAGLOI
value|$28,0
end_define

begin_comment
comment|/* I cache tagLo */
end_comment

begin_define
define|#
directive|define
name|COP0_TAGLOD
value|$28,2
end_define

begin_comment
comment|/* D cache tagLo */
end_comment

begin_define
define|#
directive|define
name|COP0_DATALOI
value|$28,1
end_define

begin_comment
comment|/* I cache dataLo */
end_comment

begin_define
define|#
directive|define
name|COP0_DATALOD
value|$28,3
end_define

begin_comment
comment|/* D cahce dataLo */
end_comment

begin_define
define|#
directive|define
name|COP0_TAGHI
value|$29,2
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|COP0_DATAHII
value|$29,1
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|COP0_DATAHID
value|$29,3
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|COP0_ERROREPC
value|$30,0
end_define

begin_comment
comment|/* Error PC */
end_comment

begin_define
define|#
directive|define
name|COP0_DESAVE
value|$31,0
end_define

begin_comment
comment|/* Debug scratch area */
end_comment

begin_comment
comment|/* This header file can be included from a .S file.  Keep non-preprocessor    things under !__ASSEMBLER__.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLER__
end_ifndef

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
comment|/* turn the variable name into a string */
define|#
directive|define
name|CVMX_TMP_STR
parameter_list|(
name|x
parameter_list|)
value|CVMX_TMP_STR2(x)
define|#
directive|define
name|CVMX_TMP_STR2
parameter_list|(
name|x
parameter_list|)
value|#x
comment|/* Since sync is required for Octeon2. */
ifdef|#
directive|ifdef
name|_MIPS_ARCH_OCTEON2
define|#
directive|define
name|CVMX_CAVIUM_OCTEON2
value|1
endif|#
directive|endif
comment|/* other useful stuff */
define|#
directive|define
name|CVMX_BREAK
value|asm volatile ("break")
define|#
directive|define
name|CVMX_SYNC
value|asm volatile ("sync" : : :"memory")
comment|/* String version of SYNCW macro for using in inline asm constructs */
define|#
directive|define
name|CVMX_SYNCW_STR_OCTEON2
value|"syncw\n"
ifdef|#
directive|ifdef
name|CVMX_CAVIUM_OCTEON2
define|#
directive|define
name|CVMX_SYNCW_STR
value|CVMX_SYNCW_STR_OCTEON2
else|#
directive|else
define|#
directive|define
name|CVMX_SYNCW_STR
value|"syncw\nsyncw\n"
endif|#
directive|endif
comment|/* CVMX_CAVIUM_OCTEON2 */
ifdef|#
directive|ifdef
name|__OCTEON__
define|#
directive|define
name|CVMX_SYNCIOBDMA
value|asm volatile ("synciobdma" : : :"memory")
comment|/* We actually use two syncw instructions in a row when we need a write         memory barrier. This is because the CN3XXX series of Octeons have         errata Core-401. This can cause a single syncw to not enforce         ordering under very rare conditions. Even if it is rare, better safe         than sorry */
define|#
directive|define
name|CVMX_SYNCW_OCTEON2
value|asm volatile ("syncw\n" : : :"memory")
ifdef|#
directive|ifdef
name|CVMX_CAVIUM_OCTEON2
define|#
directive|define
name|CVMX_SYNCW
value|CVMX_SYNCW_OCTEON2
else|#
directive|else
define|#
directive|define
name|CVMX_SYNCW
value|asm volatile ("syncw\nsyncw\n" : : :"memory")
endif|#
directive|endif
comment|/* CVMX_CAVIUM_OCTEON2 */
if|#
directive|if
name|defined
argument_list|(
name|VXWORKS
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux__
argument_list|)
comment|/* Define new sync instructions to be normal SYNC instructions for            operating systems that use threads */
define|#
directive|define
name|CVMX_SYNCWS
value|CVMX_SYNCW
define|#
directive|define
name|CVMX_SYNCS
value|CVMX_SYNC
define|#
directive|define
name|CVMX_SYNCWS_STR
value|CVMX_SYNCW_STR
define|#
directive|define
name|CVMX_SYNCWS_OCTEON2
value|CVMX_SYNCW_OCTEON2
define|#
directive|define
name|CVMX_SYNCWS_STR_OCTEON2
value|CVMX_SYNCW_STR_OCTEON2
else|#
directive|else
if|#
directive|if
name|defined
argument_list|(
name|CVMX_BUILD_FOR_TOOLCHAIN
argument_list|)
comment|/* While building simple exec toolchain, always use syncw to            support all Octeon models. */
define|#
directive|define
name|CVMX_SYNCWS
value|CVMX_SYNCW
define|#
directive|define
name|CVMX_SYNCS
value|CVMX_SYNC
define|#
directive|define
name|CVMX_SYNCWS_STR
value|CVMX_SYNCW_STR
define|#
directive|define
name|CVMX_SYNCWS_OCTEON2
value|CVMX_SYNCW_OCTEON2
define|#
directive|define
name|CVMX_SYNCWS_STR_OCTEON2
value|CVMX_SYNCW_STR_OCTEON2
else|#
directive|else
comment|/* Again, just like syncw, we may need two syncws instructions in a row due            errata Core-401. Only one syncws is required for Octeon2 models */
define|#
directive|define
name|CVMX_SYNCS
value|asm volatile ("syncs" : : :"memory")
define|#
directive|define
name|CVMX_SYNCWS_OCTEON2
value|asm volatile ("syncws\n" : : :"memory")
define|#
directive|define
name|CVMX_SYNCWS_STR_OCTEON2
value|"syncws\n"
ifdef|#
directive|ifdef
name|CVMX_CAVIUM_OCTEON2
define|#
directive|define
name|CVMX_SYNCWS
value|CVMX_SYNCWS_OCTEON2
define|#
directive|define
name|CVMX_SYNCWS_STR
value|CVMX_SYNCWS_STR_OCTEON2
else|#
directive|else
define|#
directive|define
name|CVMX_SYNCWS
value|asm volatile ("syncws\nsyncws\n" : : :"memory")
define|#
directive|define
name|CVMX_SYNCWS_STR
value|"syncws\nsyncws\n"
endif|#
directive|endif
comment|/* CVMX_CAVIUM_OCTEON2 */
endif|#
directive|endif
endif|#
directive|endif
else|#
directive|else
comment|/* !__OCTEON__ */
comment|/* Not using a Cavium compiler, always use the slower sync so the assembler stays happy */
define|#
directive|define
name|CVMX_SYNCIOBDMA
value|asm volatile ("sync" : : :"memory")
define|#
directive|define
name|CVMX_SYNCW
value|asm volatile ("sync" : : :"memory")
define|#
directive|define
name|CVMX_SYNCWS
value|CVMX_SYNCW
define|#
directive|define
name|CVMX_SYNCS
value|CVMX_SYNC
define|#
directive|define
name|CVMX_SYNCWS_STR
value|CVMX_SYNCW_STR
define|#
directive|define
name|CVMX_SYNCWS_OCTEON2
value|CVMX_SYNCW
define|#
directive|define
name|CVMX_SYNCWS_STR_OCTEON2
value|CVMX_SYNCW_STR
endif|#
directive|endif
define|#
directive|define
name|CVMX_SYNCI
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("synci " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address) )
define|#
directive|define
name|CVMX_PREFETCH0
parameter_list|(
name|address
parameter_list|)
value|CVMX_PREFETCH(address, 0)
define|#
directive|define
name|CVMX_PREFETCH128
parameter_list|(
name|address
parameter_list|)
value|CVMX_PREFETCH(address, 128)
comment|// a normal prefetch
define|#
directive|define
name|CVMX_PREFETCH
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREF0(address, offset)
comment|// normal prefetches that use the pref instruction
define|#
directive|define
name|CVMX_PREFETCH_PREFX
parameter_list|(
name|X
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("pref %[type], %[off](%[rbase])" : : [rbase] "d" (address), [off] "I" (offset), [type] "n" (X))
define|#
directive|define
name|CVMX_PREFETCH_PREF0
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(0, address, offset)
define|#
directive|define
name|CVMX_PREFETCH_PREF1
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(1, address, offset)
define|#
directive|define
name|CVMX_PREFETCH_PREF6
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(6, address, offset)
define|#
directive|define
name|CVMX_PREFETCH_PREF7
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(7, address, offset)
comment|// prefetch into L1, do not put the block in the L2
define|#
directive|define
name|CVMX_PREFETCH_NOTL2
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(4, address, offset)
define|#
directive|define
name|CVMX_PREFETCH_NOTL22
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(5, address, offset)
comment|// prefetch into L2, do not put the block in the L1
define|#
directive|define
name|CVMX_PREFETCH_L2
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(28, address, offset)
comment|// CVMX_PREPARE_FOR_STORE makes each byte of the block unpredictable (actually old value or zero) until
comment|// that byte is stored to (by this or another processor. Note that the value of each byte is not only
comment|// unpredictable, but may also change again - up until the point when one of the cores stores to the
comment|// byte.
define|#
directive|define
name|CVMX_PREPARE_FOR_STORE
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(30, address, offset)
comment|// This is a command headed to the L2 controller to tell it to clear its dirty bit for a
comment|// block. Basically, SW is telling HW that the current version of the block will not be
comment|// used.
define|#
directive|define
name|CVMX_DONT_WRITE_BACK
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_PREFETCH_PREFX(29, address, offset)
define|#
directive|define
name|CVMX_ICACHE_INVALIDATE
value|{ CVMX_SYNC; asm volatile ("synci 0($0)" : : ); }
comment|// flush stores, invalidate entire icache
define|#
directive|define
name|CVMX_ICACHE_INVALIDATE2
value|{ CVMX_SYNC; asm volatile ("cache 0, 0($0)" : : ); }
comment|// flush stores, invalidate entire icache
define|#
directive|define
name|CVMX_DCACHE_INVALIDATE
value|{ CVMX_SYNC; asm volatile ("cache 9, 0($0)" : : ); }
comment|// complete prefetches, invalidate entire dcache
define|#
directive|define
name|CVMX_CACHE
parameter_list|(
name|op
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("cache " CVMX_TMP_STR(op) ", " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address) )
define|#
directive|define
name|CVMX_CACHE_LCKL2
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_CACHE(31, address, offset)
comment|// fetch and lock the state.
define|#
directive|define
name|CVMX_CACHE_WBIL2
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_CACHE(23, address, offset)
comment|// unlock the state.
define|#
directive|define
name|CVMX_CACHE_WBIL2I
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_CACHE(3, address, offset)
comment|// invalidate the cache block and clear the USED bits for the block
define|#
directive|define
name|CVMX_CACHE_LTGL2I
parameter_list|(
name|address
parameter_list|,
name|offset
parameter_list|)
value|CVMX_CACHE(7, address, offset)
comment|// load virtual tag and data for the L2 cache block into L2C_TAD0_TAG register
comment|/* new instruction to make RC4 run faster */
define|#
directive|define
name|CVMX_BADDU
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|,
name|input2
parameter_list|)
value|asm ("baddu %[rd],%[rs],%[rt]" : [rd] "=d" (result) : [rs] "d" (input1) , [rt] "d" (input2))
comment|// misc v2 stuff
define|#
directive|define
name|CVMX_ROTR
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|,
name|shiftconst
parameter_list|)
value|asm ("rotr %[rd],%[rs]," CVMX_TMP_STR(shiftconst) : [rd] "=d" (result) : [rs] "d" (input1))
define|#
directive|define
name|CVMX_ROTRV
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|,
name|input2
parameter_list|)
value|asm ("rotrv %[rd],%[rt],%[rs]" : [rd] "=d" (result) : [rt] "d" (input1) , [rs] "d" (input2))
define|#
directive|define
name|CVMX_DROTR
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|,
name|shiftconst
parameter_list|)
value|asm ("drotr %[rd],%[rs]," CVMX_TMP_STR(shiftconst) : [rd] "=d" (result) : [rs] "d" (input1))
define|#
directive|define
name|CVMX_DROTRV
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|,
name|input2
parameter_list|)
value|asm ("drotrv %[rd],%[rt],%[rs]" : [rd] "=d" (result) : [rt] "d" (input1) , [rs] "d" (input2))
define|#
directive|define
name|CVMX_SEB
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|)
value|asm ("seb %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
define|#
directive|define
name|CVMX_SEH
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|)
value|asm ("seh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
define|#
directive|define
name|CVMX_DSBH
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|)
value|asm ("dsbh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
define|#
directive|define
name|CVMX_DSHD
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|)
value|asm ("dshd %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
define|#
directive|define
name|CVMX_WSBH
parameter_list|(
name|result
parameter_list|,
name|input1
parameter_list|)
value|asm ("wsbh %[rd],%[rt]" : [rd] "=d" (result) : [rt] "d" (input1))
comment|// Endian swap
define|#
directive|define
name|CVMX_ES64
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
define|\
value|do {\         CVMX_DSBH(result, input); \         CVMX_DSHD(result, result); \         } while (0)
define|#
directive|define
name|CVMX_ES32
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
define|\
value|do {\         CVMX_WSBH(result, input); \         CVMX_ROTR(result, result, 16); \         } while (0)
comment|/* extract and insert - NOTE that pos and len variables must be constants! */
comment|/* the P variants take len rather than lenm1 */
comment|/* the M1 variants take lenm1 rather than len */
define|#
directive|define
name|CVMX_EXTS
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|asm ("exts %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_EXTSP
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|CVMX_EXTS(result,input,pos,(len)-1)
define|#
directive|define
name|CVMX_DEXT
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("dext %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len) : [rt] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_DEXTM1
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_DEXT(result,input,pos,(lenm1)+1)
define|#
directive|define
name|CVMX_EXT
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("ext %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len) : [rt] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_EXTM1
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_EXT(result,input,pos,(lenm1)+1)
comment|// removed
comment|// #define CVMX_EXTU(result,input,pos,lenm1) asm ("extu %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
comment|// #define CVMX_EXTUP(result,input,pos,len) CVMX_EXTU(result,input,pos,(len)-1)
define|#
directive|define
name|CVMX_CINS
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|asm ("cins %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(lenm1) : [rt] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_CINSP
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|CVMX_CINS(result,input,pos,(len)-1)
define|#
directive|define
name|CVMX_DINS
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("dins %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
define|#
directive|define
name|CVMX_DINSM1
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_DINS(result,input,pos,(lenm1)+1)
define|#
directive|define
name|CVMX_DINSC
parameter_list|(
name|result
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("dins %[rt],$0," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len): [rt] "=d" (result): "[rt]" (result))
define|#
directive|define
name|CVMX_DINSCM1
parameter_list|(
name|result
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_DINSC(result,pos,(lenm1)+1)
define|#
directive|define
name|CVMX_INS
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("ins %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
define|#
directive|define
name|CVMX_INSM1
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_INS(result,input,pos,(lenm1)+1)
define|#
directive|define
name|CVMX_INSC
parameter_list|(
name|result
parameter_list|,
name|pos
parameter_list|,
name|len
parameter_list|)
value|asm ("ins %[rt],$0," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(len): [rt] "=d" (result): "[rt]" (result))
define|#
directive|define
name|CVMX_INSCM1
parameter_list|(
name|result
parameter_list|,
name|pos
parameter_list|,
name|lenm1
parameter_list|)
value|CVMX_INSC(result,pos,(lenm1)+1)
comment|// removed
comment|// #define CVMX_INS0(result,input,pos,lenm1) asm("ins0 %[rt],%[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(lenm1): [rt] "=d" (result): [rs] "d" (input), "[rt]" (result))
comment|// #define CVMX_INS0P(result,input,pos,len) CVMX_INS0(result,input,pos,(len)-1)
comment|// #define CVMX_INS0C(result,pos,lenm1) asm ("ins0 %[rt],$0," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(lenm1) : [rt] "=d" (result) : "[rt]" (result))
comment|// #define CVMX_INS0CP(result,pos,len) CVMX_INS0C(result,pos,(len)-1)
define|#
directive|define
name|CVMX_CLZ
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("clz %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_DCLZ
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("dclz %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_CLO
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("clo %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_DCLO
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("dclo %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_POP
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("pop %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
define|#
directive|define
name|CVMX_DPOP
parameter_list|(
name|result
parameter_list|,
name|input
parameter_list|)
value|asm ("dpop %[rd],%[rs]" : [rd] "=d" (result) : [rs] "d" (input))
ifdef|#
directive|ifdef
name|CVMX_ABI_O32
comment|/* rdhwr $31 is the 64 bit cmvcount register, it needs to be split      into one or two (depending on the width of the result) properly      sign extended registers.  All other registers are 32 bits wide      and already properly sign extended. */
define|#
directive|define
name|CVMX_RDHWRX
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|,
name|ASM_STMT
parameter_list|)
value|({			\   if (regstr == 31) {							\     if (sizeof(result) == 8) {						\       ASM_STMT (".set\tpush\n"						\ 		"\t.set\tmips64r2\n"					\ 		"\trdhwr\t%L0,$31\n"					\ 		"\tdsra\t%M0,%L0,32\n"					\ 		"\tsll\t%L0,%L0,0\n"					\ 		"\t.set\tpop": "=d"(result));				\     } else {								\       unsigned long _v;							\       ASM_STMT ("rdhwr\t%0,$31\n"					\ 		"\tsll\t%0,%0,0" : "=d"(_v));				\       result = (__typeof(result))_v;					\     }									\   } else {								\     unsigned long _v;							\     ASM_STMT ("rdhwr\t%0,$" CVMX_TMP_STR(regstr) : "=d"(_v));		\     result = (__typeof(result))_v;					\   }})
define|#
directive|define
name|CVMX_RDHWR
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|)
value|CVMX_RDHWRX(result, regstr, asm volatile)
define|#
directive|define
name|CVMX_RDHWRNV
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|)
value|CVMX_RDHWRX(result, regstr, asm)
else|#
directive|else
define|#
directive|define
name|CVMX_RDHWR
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|)
value|asm volatile ("rdhwr %[rt],$" CVMX_TMP_STR(regstr) : [rt] "=d" (result))
define|#
directive|define
name|CVMX_RDHWRNV
parameter_list|(
name|result
parameter_list|,
name|regstr
parameter_list|)
value|asm ("rdhwr %[rt],$" CVMX_TMP_STR(regstr) : [rt] "=d" (result))
endif|#
directive|endif
comment|// some new cop0-like stuff
define|#
directive|define
name|CVMX_DI
parameter_list|(
name|result
parameter_list|)
value|asm volatile ("di %[rt]" : [rt] "=d" (result))
define|#
directive|define
name|CVMX_DI_NULL
value|asm volatile ("di")
define|#
directive|define
name|CVMX_EI
parameter_list|(
name|result
parameter_list|)
value|asm volatile ("ei %[rt]" : [rt] "=d" (result))
define|#
directive|define
name|CVMX_EI_NULL
value|asm volatile ("ei")
define|#
directive|define
name|CVMX_EHB
value|asm volatile ("ehb")
comment|/* mul stuff */
define|#
directive|define
name|CVMX_MTM0
parameter_list|(
name|m
parameter_list|)
value|asm volatile ("mtm0 %[rs]" : : [rs] "d" (m))
define|#
directive|define
name|CVMX_MTM1
parameter_list|(
name|m
parameter_list|)
value|asm volatile ("mtm1 %[rs]" : : [rs] "d" (m))
define|#
directive|define
name|CVMX_MTM2
parameter_list|(
name|m
parameter_list|)
value|asm volatile ("mtm2 %[rs]" : : [rs] "d" (m))
define|#
directive|define
name|CVMX_MTP0
parameter_list|(
name|p
parameter_list|)
value|asm volatile ("mtp0 %[rs]" : : [rs] "d" (p))
define|#
directive|define
name|CVMX_MTP1
parameter_list|(
name|p
parameter_list|)
value|asm volatile ("mtp1 %[rs]" : : [rs] "d" (p))
define|#
directive|define
name|CVMX_MTP2
parameter_list|(
name|p
parameter_list|)
value|asm volatile ("mtp2 %[rs]" : : [rs] "d" (p))
define|#
directive|define
name|CVMX_VMULU
parameter_list|(
name|dest
parameter_list|,
name|mpcand
parameter_list|,
name|accum
parameter_list|)
value|asm volatile ("vmulu %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))
define|#
directive|define
name|CVMX_VMM0
parameter_list|(
name|dest
parameter_list|,
name|mpcand
parameter_list|,
name|accum
parameter_list|)
value|asm volatile ("vmm0 %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))
define|#
directive|define
name|CVMX_V3MULU
parameter_list|(
name|dest
parameter_list|,
name|mpcand
parameter_list|,
name|accum
parameter_list|)
value|asm volatile ("v3mulu %[rd],%[rs],%[rt]" : [rd] "=d" (dest) : [rs] "d" (mpcand), [rt] "d" (accum))
comment|/* branch stuff */
comment|// these are hard to make work because the compiler does not realize that the
comment|// instruction is a branch so may optimize away the label
comment|// the labels to these next two macros must not include a ":" at the end
define|#
directive|define
name|CVMX_BBIT1
parameter_list|(
name|var
parameter_list|,
name|pos
parameter_list|,
name|label
parameter_list|)
value|asm volatile ("bbit1 %[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(label) : : [rs] "d" (var))
define|#
directive|define
name|CVMX_BBIT0
parameter_list|(
name|var
parameter_list|,
name|pos
parameter_list|,
name|label
parameter_list|)
value|asm volatile ("bbit0 %[rs]," CVMX_TMP_STR(pos) "," CVMX_TMP_STR(label) : : [rs] "d" (var))
comment|// the label to this macro must include a ":" at the end
define|#
directive|define
name|CVMX_ASM_LABEL
parameter_list|(
name|label
parameter_list|)
value|label \                              asm volatile (CVMX_TMP_STR(label) : : )
comment|//
comment|// Low-latency memory stuff
comment|//
comment|// set can be 0-1
define|#
directive|define
name|CVMX_MT_LLM_READ_ADDR
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0400+(8*(" CVMX_TMP_STR(set) "))" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_LLM_WRITE_ADDR_INTERNAL
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0401+(8*(" CVMX_TMP_STR(set) "))" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_LLM_READ64_ADDR
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0404+(8*(" CVMX_TMP_STR(set) "))" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_LLM_WRITE64_ADDR_INTERNAL
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0405+(8*(" CVMX_TMP_STR(set) "))" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_LLM_DATA
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0402+(8*(" CVMX_TMP_STR(set) "))" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MF_LLM_DATA
parameter_list|(
name|set
parameter_list|,
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0402+(8*(" CVMX_TMP_STR(set) "))" : [rt] "=d" (val) : )
comment|// load linked, store conditional
define|#
directive|define
name|CVMX_LL
parameter_list|(
name|dest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("ll %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (dest) : [rbase] "d" (address) )
define|#
directive|define
name|CVMX_LLD
parameter_list|(
name|dest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("lld %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (dest) : [rbase] "d" (address) )
define|#
directive|define
name|CVMX_SC
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("sc %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
define|#
directive|define
name|CVMX_SCD
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("scd %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
comment|// load/store word left/right
define|#
directive|define
name|CVMX_LWR
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("lwr %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
define|#
directive|define
name|CVMX_LWL
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("lwl %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
define|#
directive|define
name|CVMX_LDR
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("ldr %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
define|#
directive|define
name|CVMX_LDL
parameter_list|(
name|srcdest
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("ldl %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : [rt] "=d" (srcdest) : [rbase] "d" (address), "[rt]" (srcdest) )
define|#
directive|define
name|CVMX_SWR
parameter_list|(
name|src
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("swr %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
define|#
directive|define
name|CVMX_SWL
parameter_list|(
name|src
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("swl %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
define|#
directive|define
name|CVMX_SDR
parameter_list|(
name|src
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("sdr %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
define|#
directive|define
name|CVMX_SDL
parameter_list|(
name|src
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
value|asm volatile ("sdl %[rt], " CVMX_TMP_STR(offset) "(%[rbase])" : : [rbase] "d" (address), [rt] "d" (src) )
comment|//
comment|// Useful crypto ASM's
comment|//
comment|// CRC
define|#
directive|define
name|CVMX_MT_CRC_POLYNOMIAL
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4200" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_IV
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0201" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_LEN
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x1202" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_BYTE
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0204" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_HALF
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0205" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_WORD
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0206" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_DWORD
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x1207" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_VAR
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x1208" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_POLYNOMIAL_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4210" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_IV_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0211" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_BYTE_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0214" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_HALF_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0215" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_WORD_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0216" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_DWORD_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x1217" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_CRC_VAR_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x1218" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MF_CRC_POLYNOMIAL
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0200" : [rt] "=d" (val) : )
define|#
directive|define
name|CVMX_MF_CRC_IV
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0201" : [rt] "=d" (val) : )
define|#
directive|define
name|CVMX_MF_CRC_IV_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0203" : [rt] "=d" (val) : )
define|#
directive|define
name|CVMX_MF_CRC_LEN
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0202" : [rt] "=d" (val) : )
comment|// MD5 and SHA-1
comment|// pos can be 0-6
define|#
directive|define
name|CVMX_MT_HSH_DAT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0040+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_HSH_DATZ
parameter_list|(
name|pos
parameter_list|)
value|asm volatile ("dmtc2    $0,0x0040+" CVMX_TMP_STR(pos) :                 :               )
comment|// pos can be 0-14
define|#
directive|define
name|CVMX_MT_HSH_DATW
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0240+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_HSH_DATWZ
parameter_list|(
name|pos
parameter_list|)
value|asm volatile ("dmtc2    $0,0x0240+" CVMX_TMP_STR(pos) :                 :               )
define|#
directive|define
name|CVMX_MT_HSH_STARTMD5
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4047"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_HSH_STARTSHA
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4057"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_HSH_STARTSHA256
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x404f"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_HSH_STARTSHA512
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x424f"                   :                 : [rt] "d" (val))
comment|// pos can be 0-3
define|#
directive|define
name|CVMX_MT_HSH_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0048+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
comment|// pos can be 0-7
define|#
directive|define
name|CVMX_MT_HSH_IVW
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0250+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
comment|// pos can be 0-6
define|#
directive|define
name|CVMX_MF_HSH_DAT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0040+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-14
define|#
directive|define
name|CVMX_MF_HSH_DATW
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0240+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-3
define|#
directive|define
name|CVMX_MF_HSH_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0048+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-7
define|#
directive|define
name|CVMX_MF_HSH_IVW
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0250+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// 3DES
comment|// pos can be 0-2
define|#
directive|define
name|CVMX_MT_3DES_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0080+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_IV
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0084"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_ENC_CBC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4088"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_ENC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x408a"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_DEC_CBC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x408c"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_DEC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x408e"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_3DES_RESULT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0098"                   :                 : [rt] "d" (val))
comment|// pos can be 0-2
define|#
directive|define
name|CVMX_MF_3DES_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0080+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MF_3DES_IV
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0084"                   : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MF_3DES_RESULT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0088"                   : [rt] "=d" (val) :               )
comment|// KASUMI
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_KAS_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|CVMX_MT_3DES_KEY(val,pos)
define|#
directive|define
name|CVMX_MT_KAS_ENC_CBC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x4089"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_KAS_ENC
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x408b"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_KAS_RESULT
parameter_list|(
name|val
parameter_list|)
value|CVMX_MT_3DES_RESULT(val)
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_KAS_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|CVMX_MF_3DES_KEY(val,pos)
define|#
directive|define
name|CVMX_MF_KAS_RESULT
parameter_list|(
name|val
parameter_list|)
value|CVMX_MF_3DES_RESULT(val)
comment|// AES
define|#
directive|define
name|CVMX_MT_AES_ENC_CBC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0108"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_ENC_CBC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x3109"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_ENC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010a"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_ENC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x310b"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_DEC_CBC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010c"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_DEC_CBC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x310d"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_DEC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010e"                   :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_DEC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x310f"                   :                 : [rt] "d" (val))
comment|// pos can be 0-3
define|#
directive|define
name|CVMX_MT_AES_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0104+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_AES_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0102+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_AES_KEYLENGTH
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0110"                   :                 : [rt] "d" (val))
comment|// write the keylen
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_AES_RESULT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0100+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_AES_RESULT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0100+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_AES_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0102+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-3
define|#
directive|define
name|CVMX_MF_AES_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0104+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MF_AES_KEYLENGTH
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0110"                   : [rt] "=d" (val) :               )
comment|// read the keylen
define|#
directive|define
name|CVMX_MF_AES_DAT0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0111"                   : [rt] "=d" (val) :               )
comment|// first piece of input data
comment|// GFM
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_GFM_MUL
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0258+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MF_GFM_POLY
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x025e"                    : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_GFM_RESINP
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x025a+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_GFM_RESINP_REFLECT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x005a+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_GFM_MUL
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0258+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_GFM_POLY
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x025e"                    :                 : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_GFM_RESINP
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x025a+" CVMX_TMP_STR(pos) :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_GFM_XOR0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x025c"                    :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_GFM_XORMUL1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x425d"                    :                 : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_GFM_MUL_REFLECT
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0058+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MT_GFM_XOR0_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x005c"                    :                 : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_GFM_XORMUL1_REFLECT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x405d"                    :                 : [rt] "d" (val))
comment|// SNOW 3G
comment|// pos can be 0-7
define|#
directive|define
name|CVMX_MF_SNOW3G_LFSR
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0240+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-2
define|#
directive|define
name|CVMX_MF_SNOW3G_FSM
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0251+" CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MF_SNOW3G_RESULT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0250"                    : [rt] "=d" (val) :               )
comment|// pos can be 0-7
define|#
directive|define
name|CVMX_MT_SNOW3G_LFSR
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0240+" CVMX_TMP_STR(pos) : : [rt] "d" (val))
comment|// pos can be 0-2
define|#
directive|define
name|CVMX_MT_SNOW3G_FSM
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0251+" CVMX_TMP_STR(pos) : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SNOW3G_RESULT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0250"                    : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SNOW3G_START
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x404d"                    : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SNOW3G_MORE
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x404e"                    : : [rt] "d" (val))
comment|// SMS4
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_SMS4_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0102+"CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_SMS4_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0104+"CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MF_SMS4_RESINP
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x0100+"CVMX_TMP_STR(pos) : [rt] "=d" (val) :               )
define|#
directive|define
name|CVMX_MT_SMS4_DEC_CBC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010c"                   : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_DEC_CBC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x311d"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_DEC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010e"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_DEC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x311f"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_ENC_CBC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0108"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_ENC_CBC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x3119"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_ENC0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x010a"      : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_SMS4_ENC1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x311b"      : : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_SMS4_IV
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0102+"CVMX_TMP_STR(pos) : : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_SMS4_KEY
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0104+"CVMX_TMP_STR(pos) : : [rt] "d" (val))
comment|// pos can be 0-1
define|#
directive|define
name|CVMX_MT_SMS4_RESINP
parameter_list|(
name|val
parameter_list|,
name|pos
parameter_list|)
value|asm volatile ("dmtc2 %[rt],0x0100+"CVMX_TMP_STR(pos) : : [rt] "d" (val))
comment|/* check_ordering stuff */
if|#
directive|if
literal|0
define|#
directive|define
name|CVMX_MF_CHORD
parameter_list|(
name|dest
parameter_list|)
value|asm volatile ("dmfc2 %[rt],0x400" : [rt] "=d" (dest) : )
else|#
directive|else
define|#
directive|define
name|CVMX_MF_CHORD
parameter_list|(
name|dest
parameter_list|)
value|CVMX_RDHWR(dest, 30)
endif|#
directive|endif
if|#
directive|if
literal|0
define|#
directive|define
name|CVMX_MF_CYCLE
parameter_list|(
name|dest
parameter_list|)
value|asm volatile ("dmfc0 %[rt],$9,6" : [rt] "=d" (dest) : )
comment|// Use (64-bit) CvmCount register rather than Count
else|#
directive|else
define|#
directive|define
name|CVMX_MF_CYCLE
parameter_list|(
name|dest
parameter_list|)
value|CVMX_RDHWR(dest, 31)
comment|/* reads the current (64-bit) CvmCount value */
endif|#
directive|endif
define|#
directive|define
name|CVMX_MT_CYCLE
parameter_list|(
name|src
parameter_list|)
value|asm volatile ("dmtc0 %[rt],$9,6" :: [rt] "d" (src))
define|#
directive|define
name|VASTR
parameter_list|(
modifier|...
parameter_list|)
value|#__VA_ARGS__
define|#
directive|define
name|CVMX_MF_COP0
parameter_list|(
name|val
parameter_list|,
name|cop0
parameter_list|)
value|asm volatile ("dmfc0 %[rt]," VASTR(cop0) : [rt] "=d" (val));
define|#
directive|define
name|CVMX_MT_COP0
parameter_list|(
name|val
parameter_list|,
name|cop0
parameter_list|)
value|asm volatile ("dmtc0 %[rt]," VASTR(cop0) : : [rt] "d" (val));
define|#
directive|define
name|CVMX_MF_CACHE_ERR
parameter_list|(
name|val
parameter_list|)
value|CVMX_MF_COP0(val, COP0_CACHEERRI)
define|#
directive|define
name|CVMX_MF_DCACHE_ERR
parameter_list|(
name|val
parameter_list|)
value|CVMX_MF_COP0(val, COP0_CACHEERRD)
define|#
directive|define
name|CVMX_MF_CVM_MEM_CTL
parameter_list|(
name|val
parameter_list|)
value|CVMX_MF_COP0(val, COP0_CVMMEMCTL)
define|#
directive|define
name|CVMX_MF_CVM_CTL
parameter_list|(
name|val
parameter_list|)
value|CVMX_MF_COP0(val, COP0_CVMCTL)
define|#
directive|define
name|CVMX_MT_CACHE_ERR
parameter_list|(
name|val
parameter_list|)
value|CVMX_MT_COP0(val, COP0_CACHEERRI)
define|#
directive|define
name|CVMX_MT_DCACHE_ERR
parameter_list|(
name|val
parameter_list|)
value|CVMX_MT_COP0(val, COP0_CACHEERRD)
define|#
directive|define
name|CVMX_MT_CVM_MEM_CTL
parameter_list|(
name|val
parameter_list|)
value|CVMX_MT_COP0(val, COP0_CVMMEMCTL)
define|#
directive|define
name|CVMX_MT_CVM_CTL
parameter_list|(
name|val
parameter_list|)
value|CVMX_MT_COP0(val, COP0_CVMCTL)
comment|/* Macros for TLB */
define|#
directive|define
name|CVMX_TLBWI
value|asm volatile ("tlbwi" : : )
define|#
directive|define
name|CVMX_TLBWR
value|asm volatile ("tlbwr" : : )
define|#
directive|define
name|CVMX_TLBR
value|asm volatile ("tlbr" : : )
define|#
directive|define
name|CVMX_TLBP
value|asm volatile ("tlbp" : : )
define|#
directive|define
name|CVMX_MT_ENTRY_HIGH
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc0 %[rt],$10,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_ENTRY_LO_0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc0 %[rt],$2,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_ENTRY_LO_1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc0 %[rt],$3,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_PAGEMASK
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mtc0 %[rt],$5,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_PAGEGRAIN
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mtc0 %[rt],$5,1" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_TLB_INDEX
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mtc0 %[rt],$0,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_TLB_CONTEXT
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmtc0 %[rt],$4,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_TLB_WIRED
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mtc0 %[rt],$6,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MT_TLB_RANDOM
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mtc0 %[rt],$1,0" : : [rt] "d" (val))
define|#
directive|define
name|CVMX_MF_ENTRY_LO_0
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc0 %[rt],$2,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_ENTRY_LO_1
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc0 %[rt],$3,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_ENTRY_HIGH
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("dmfc0 %[rt],$10,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_PAGEMASK
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mfc0 %[rt],$5,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_PAGEGRAIN
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mfc0 %[rt],$5,1" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_TLB_WIRED
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mfc0 %[rt],$6,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_TLB_INDEX
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mfc0 %[rt],$0,0" :  [rt] "=d" (val):)
define|#
directive|define
name|CVMX_MF_TLB_RANDOM
parameter_list|(
name|val
parameter_list|)
value|asm volatile ("mfc0 %[rt],$1,0" :  [rt] "=d" (val):)
define|#
directive|define
name|TLB_DIRTY
value|(0x1ULL<<2)
define|#
directive|define
name|TLB_VALID
value|(0x1ULL<<1)
define|#
directive|define
name|TLB_GLOBAL
value|(0x1ULL<<0)
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
comment|/* Macros to PUSH and POP Octeon2 ISA. */
define|#
directive|define
name|CVMX_PUSH_OCTEON2
value|asm volatile (".set push\n.set arch=octeon2")
define|#
directive|define
name|CVMX_POP_OCTEON2
value|asm volatile (".set pop")
endif|#
directive|endif
comment|/* assembler macros to guarantee byte loads/stores are used */
comment|/* for an unaligned 16-bit access (these use AT register) */
comment|/* we need the hidden argument (__a) so that GCC gets the dependencies right */
define|#
directive|define
name|CVMX_LOADUNA_INT16
parameter_list|(
name|result
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("ulh %[rdest], " CVMX_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : [rbase] "d" (__a), "m"(__a[offset]), "m"(__a[offset + 1])); }
define|#
directive|define
name|CVMX_LOADUNA_UINT16
parameter_list|(
name|result
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("ulhu %[rdest], " CVMX_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1])); }
define|#
directive|define
name|CVMX_STOREUNA_INT16
parameter_list|(
name|data
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("ush %[rsrc], " CVMX_TMP_STR(offset) "(%[rbase])" : "=m"(__a[offset + 0]), "=m"(__a[offset + 1]): [rsrc] "d" (data), [rbase] "d" (__a)); }
define|#
directive|define
name|CVMX_LOADUNA_INT32
parameter_list|(
name|result
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("ulw %[rdest], " CVMX_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : \ 	       [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1]), "m"(__a[offset + 2]), "m"(__a[offset + 3])); }
define|#
directive|define
name|CVMX_STOREUNA_INT32
parameter_list|(
name|data
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("usw %[rsrc], " CVMX_TMP_STR(offset) "(%[rbase])" : \ 	       "=m"(__a[offset + 0]), "=m"(__a[offset + 1]), "=m"(__a[offset + 2]), "=m"(__a[offset + 3]) : \ 	       [rsrc] "d" (data), [rbase] "d" (__a)); }
define|#
directive|define
name|CVMX_LOADUNA_INT64
parameter_list|(
name|result
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("uld %[rdest], " CVMX_TMP_STR(offset) "(%[rbase])" : [rdest] "=d" (result) : \ 	       [rbase] "d" (__a), "m"(__a[offset + 0]), "m"(__a[offset + 1]), "m"(__a[offset + 2]), "m"(__a[offset + 3]), \ 	       "m"(__a[offset + 4]), "m"(__a[offset + 5]), "m"(__a[offset + 6]), "m"(__a[offset + 7])); }
define|#
directive|define
name|CVMX_STOREUNA_INT64
parameter_list|(
name|data
parameter_list|,
name|address
parameter_list|,
name|offset
parameter_list|)
define|\
value|{ char *__a = (char *)(address); \ 	  asm ("usd %[rsrc], " CVMX_TMP_STR(offset) "(%[rbase])" : \ 	       "=m"(__a[offset + 0]), "=m"(__a[offset + 1]), "=m"(__a[offset + 2]), "=m"(__a[offset + 3]), \ 	       "=m"(__a[offset + 4]), "=m"(__a[offset + 5]), "=m"(__a[offset + 6]), "=m"(__a[offset + 7]) : \ 	       [rsrc] "d" (data), [rbase] "d" (__a)); }
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
comment|/* __ASSEMBLER__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_ASM_H__ */
end_comment

end_unit

