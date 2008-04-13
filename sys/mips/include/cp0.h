begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001, 2005, Juniper Networks, Inc.  * All rights reserved.  *  * Truman Joe, March 2001.  *  * cp0.h -- MIPS coprocessor 0 defines.  *  *	JNPR: cp0.h,v 1.4 2006/12/02 09:53:40 katta  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * This header file is updated from:  * pfe/include/mips/cp0.h  */
end_comment

begin_comment
comment|/*  * Note: Registers and bit descriptions that do NOT adhere to  * the MIPS64 descriptions as defined in the "MIPS64  * Architecture for Programmers, Volume III: The MIPS64  * Privileged Resource Architecture" document (doc # MD00091)  * are considered to be processor specific and must have the  * processor type included in the constant name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CP0_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CP0_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASMINCLUDE
end_ifndef

begin_comment
comment|/* Coprocessor 0 set 0 */
end_comment

begin_define
define|#
directive|define
name|C0_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|C0_RANDOM
value|1
end_define

begin_define
define|#
directive|define
name|C0_ENTRYLO0
value|2
end_define

begin_define
define|#
directive|define
name|C0_ENTRYLO1
value|3
end_define

begin_define
define|#
directive|define
name|C0_CONTEXT
value|4
end_define

begin_define
define|#
directive|define
name|C0_PAGEMASK
value|5
end_define

begin_define
define|#
directive|define
name|C0_WIRED
value|6
end_define

begin_define
define|#
directive|define
name|R7K_C0_INFO
value|7
end_define

begin_define
define|#
directive|define
name|R9K_C0_INFO
value|7
end_define

begin_define
define|#
directive|define
name|C0_BADVADDR
value|8
end_define

begin_define
define|#
directive|define
name|C0_COUNT
value|9
end_define

begin_define
define|#
directive|define
name|C0_ENTRYHI
value|10
end_define

begin_define
define|#
directive|define
name|C0_COMPARE
value|11
end_define

begin_define
define|#
directive|define
name|C0_STATUS
value|12
end_define

begin_define
define|#
directive|define
name|C0_CAUSE
value|13
end_define

begin_define
define|#
directive|define
name|C0_EPC
value|14
end_define

begin_define
define|#
directive|define
name|C0_PRID
value|15
end_define

begin_define
define|#
directive|define
name|C0_CONFIG
value|16
end_define

begin_define
define|#
directive|define
name|C0_LLADDR
value|17
end_define

begin_define
define|#
directive|define
name|C0_WATCH1
value|18
end_define

begin_define
define|#
directive|define
name|C0_WATCH2
value|19
end_define

begin_define
define|#
directive|define
name|C0_XCONTEXT
value|20
end_define

begin_define
define|#
directive|define
name|R7K_C0_PERFCTL
value|22
end_define

begin_define
define|#
directive|define
name|C0_DEBUG
value|23
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DEBUG
value|23
end_define

begin_define
define|#
directive|define
name|R7K_C0_WATCHMASK
value|24
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DEPC
value|24
end_define

begin_define
define|#
directive|define
name|C0_PERFCOUNT
value|25
end_define

begin_define
define|#
directive|define
name|C0_ECC
value|26
end_define

begin_define
define|#
directive|define
name|C0_CACHEERR
value|27
end_define

begin_define
define|#
directive|define
name|C0_TAGLO
value|28
end_define

begin_define
define|#
directive|define
name|C0_TAGHI
value|29
end_define

begin_define
define|#
directive|define
name|C0_ERROREPC
value|30
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DESAV
value|31
end_define

begin_comment
comment|/* Coprocessor 0 Set 1 */
end_comment

begin_define
define|#
directive|define
name|R7K_C0_1_IPLLO
value|18
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_IPLHI
value|19
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_INTCTL
value|20
end_define

begin_define
define|#
directive|define
name|R9K_C0_1_TBCTL
value|22
end_define

begin_define
define|#
directive|define
name|R9K_C0_1_TBIDX
value|24
end_define

begin_define
define|#
directive|define
name|R9K_C0_1_TBOUT
value|25
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_DERRADDR0
value|26
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_DERRADDR1
value|27
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ASMINCLUDE */
end_comment

begin_comment
comment|/* Coprocessor 0 set 0 */
end_comment

begin_define
define|#
directive|define
name|C0_INDEX
value|$0
end_define

begin_define
define|#
directive|define
name|C0_RANDOM
value|$1
end_define

begin_define
define|#
directive|define
name|C0_ENTRYLO0
value|$2
end_define

begin_define
define|#
directive|define
name|C0_ENTRYLO1
value|$3
end_define

begin_define
define|#
directive|define
name|C0_CONTEXT
value|$4
end_define

begin_define
define|#
directive|define
name|C0_PAGEMASK
value|$5
end_define

begin_define
define|#
directive|define
name|C0_WIRED
value|$6
end_define

begin_define
define|#
directive|define
name|C0_INFO
value|$7
end_define

begin_define
define|#
directive|define
name|C0_BADVADDR
value|$8
end_define

begin_define
define|#
directive|define
name|C0_COUNT
value|$9
end_define

begin_define
define|#
directive|define
name|C0_ENTRYHI
value|$10
end_define

begin_define
define|#
directive|define
name|C0_COMPARE
value|$11
end_define

begin_define
define|#
directive|define
name|C0_STATUS
value|$12
end_define

begin_define
define|#
directive|define
name|C0_CAUSE
value|$13
end_define

begin_define
define|#
directive|define
name|C0_EPC
value|$14
end_define

begin_define
define|#
directive|define
name|C0_PRID
value|$15
end_define

begin_define
define|#
directive|define
name|C0_CONFIG
value|$16
end_define

begin_define
define|#
directive|define
name|C0_LLADDR
value|$17
end_define

begin_define
define|#
directive|define
name|C0_WATCH1
value|$18
end_define

begin_define
define|#
directive|define
name|C0_WATCH2
value|$19
end_define

begin_define
define|#
directive|define
name|C0_XCONTEXT
value|$20
end_define

begin_define
define|#
directive|define
name|R7K_C0_PERFCTL
value|$22
end_define

begin_define
define|#
directive|define
name|C0_DEBUG
value|$23
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DEBUG
value|$23
end_define

begin_define
define|#
directive|define
name|R7K_C0_WATCHMASK
value|$24
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DEPC
value|$24
end_define

begin_define
define|#
directive|define
name|C0_PERFCOUNT
value|$25
end_define

begin_define
define|#
directive|define
name|C0_ECC
value|$26
end_define

begin_define
define|#
directive|define
name|C0_CACHEERR
value|$27
end_define

begin_define
define|#
directive|define
name|C0_TAGLO
value|$28
end_define

begin_define
define|#
directive|define
name|C0_TAGHI
value|$29
end_define

begin_define
define|#
directive|define
name|C0_ERROREPC
value|$30
end_define

begin_define
define|#
directive|define
name|R9K_C0_JTAG_DESAV
value|$31
end_define

begin_comment
comment|/* Coprocessor 0 Set 1 */
end_comment

begin_define
define|#
directive|define
name|R7K_C0_1_IPLLO
value|$18
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_IPLHI
value|$19
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_INTCTL
value|$20
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_DERRADDR0
value|$26
end_define

begin_define
define|#
directive|define
name|R7K_C0_1_DERRADDR1
value|$27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ASMINCLUDE */
end_comment

begin_comment
comment|/* CACHE INSTR OPERATIONS */
end_comment

begin_define
define|#
directive|define
name|CACHE_I
value|0
end_define

begin_define
define|#
directive|define
name|CACHE_D
value|1
end_define

begin_define
define|#
directive|define
name|CACHE_T
value|2
end_define

begin_define
define|#
directive|define
name|CACHE_S
value|3
end_define

begin_define
define|#
directive|define
name|INDEX_INVL_I
value|((0<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|INDEX_WB_INVL_D
value|((0<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|FLASH_INVL_T
value|((0<< 2) | CACHE_T)
end_define

begin_define
define|#
directive|define
name|INDEX_WB_INVL_S
value|((0<< 2) | CACHE_S)
end_define

begin_define
define|#
directive|define
name|INDEX_LD_TAG_I
value|((1<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|INDEX_LD_TAG_D
value|((1<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|INDEX_LD_TAG_T
value|((1<< 2) | CACHE_T)
end_define

begin_define
define|#
directive|define
name|INDEX_LD_TAG_S
value|((1<< 2) | CACHE_S)
end_define

begin_define
define|#
directive|define
name|INDEX_ST_TAG_I
value|((2<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|INDEX_ST_TAG_D
value|((2<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|INDEX_ST_TAG_T
value|((2<< 2) | CACHE_T)
end_define

begin_define
define|#
directive|define
name|INDEX_ST_TAG_S
value|((2<< 2) | CACHE_S)
end_define

begin_define
define|#
directive|define
name|CREATE_DRTY_EXCL_D
value|((3<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|HIT_INVL_I
value|((4<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|HIT_INVL_D
value|((4<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|HIT_INVL_S
value|((4<< 2) | CACHE_S)
end_define

begin_define
define|#
directive|define
name|HIT_WB_INVL_D
value|((5<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|FILL_I
value|((5<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|HIT_WB_INVL_S
value|((5<< 2) | CACHE_S)
end_define

begin_define
define|#
directive|define
name|PAGE_INVL_T
value|((5<< 2) | CACHE_T)
end_define

begin_define
define|#
directive|define
name|HIT_WB_D
value|((6<< 2) | CACHE_D)
end_define

begin_define
define|#
directive|define
name|HIT_WB_I
value|((6<< 2) | CACHE_I)
end_define

begin_define
define|#
directive|define
name|HIT_WB_S
value|((6<< 2) | CACHE_S)
end_define

begin_comment
comment|/* CO_CONFIG bit definitions */
end_comment

begin_define
define|#
directive|define
name|R7K_CFG_TE
value|(0x1<< 12)
end_define

begin_comment
comment|/* diff from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R7K_CFG_SE
value|(0x1<< 3)
end_define

begin_comment
comment|/* diff from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_SE
value|(0x1<< 3)
end_define

begin_comment
comment|/* diff from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_SC
value|(0x1<< 31)
end_define

begin_comment
comment|/* diff from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|CFG_K0_MASK
value|(0x7<< 0)
end_define

begin_define
define|#
directive|define
name|CFG_K0_UNC
value|(0x2<< 0)
end_define

begin_define
define|#
directive|define
name|CFG_K0_WB
value|(0x3<< 0)
end_define

begin_define
define|#
directive|define
name|R9K_CFG_K0_WT
value|0x0
end_define

begin_comment
comment|/* Write thru */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_WTWA
value|0x1
end_define

begin_comment
comment|/* Write thru with write alloc */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_UNCB
value|0x2
end_define

begin_comment
comment|/* Uncached, blocking */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_WB
value|0x3
end_define

begin_comment
comment|/* Write Back */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_CWBEA
value|0x4
end_define

begin_comment
comment|/* Coherent WB wih exclusive alloc */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_CWB
value|0x5
end_define

begin_comment
comment|/* Coherent WB */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_UNCNB
value|0x6
end_define

begin_comment
comment|/* Uncached, nonblocking */
end_comment

begin_define
define|#
directive|define
name|R9K_CFG_K0_FPC
value|0x7
end_define

begin_comment
comment|/* Fast Packet Cache (bypass 2nd cache) */
end_comment

begin_comment
comment|/* Special C0_INFO bit descriptions for the R9K processor */
end_comment

begin_define
define|#
directive|define
name|R9K_INFO_AE
value|(1<< 0)
end_define

begin_comment
comment|/* atomic SR_IE for R9K */
end_comment

begin_define
define|#
directive|define
name|R9K_INFO_64_TLB
value|(1<< 29)
end_define

begin_comment
comment|/* R9K C0_INFO bit - chip has 64 TLB entries */
end_comment

begin_comment
comment|/* CO_PAGEMASK bit definitions */
end_comment

begin_comment
comment|/*  * These look wierd because the 'size' used is twice what you  * think it is, but remember that the MIPs TLB maps even odd  * pages so that you need to acount for the 2x page size  * R9K supports 256M pages (it has a 16 bit Mask field in the  * PageMask register).  */
end_comment

begin_define
define|#
directive|define
name|PAGEMASK_256M
value|((0x20000000 - 1)& ~0x1fff)
end_define

begin_comment
comment|/* R9K only */
end_comment

begin_define
define|#
directive|define
name|PAGEMASK_64M
value|((0x08000000 - 1)& ~0x1fff)
end_define

begin_comment
comment|/* R9K only */
end_comment

begin_define
define|#
directive|define
name|PAGEMASK_16M
value|((0x02000000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_4M
value|((0x00800000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_1M
value|((0x00200000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_256K
value|((0x00080000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_64K
value|((0x00020000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_16K
value|((0x00008000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|PAGEMASK_4K
value|((0x00002000 - 1)& ~0x1fff)
end_define

begin_define
define|#
directive|define
name|R9K_PAGEMASK
value|0xffff
end_define

begin_comment
comment|/* R9K has a 16 bit of PageMask reg */
end_comment

begin_define
define|#
directive|define
name|PAGEMASK_SHIFT
value|13
end_define

begin_comment
comment|/*  * Cache Coherency Attributes  * These are different for R7K and R9K  */
end_comment

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_WTNA
value|0x0
end_define

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_WTWA
value|0x1
end_define

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_UNCBLK
value|0x2
end_define

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_WB
value|0x3
end_define

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_UNCNBLK
value|0x6
end_define

begin_define
define|#
directive|define
name|R7K_TLB_COHERENCY_BYPASS
value|0x7
end_define

begin_define
define|#
directive|define
name|ENTRYHI_ASID_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R9K_ENTRYHI_ASID_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|R7K_ENTRYHI_VPNMASK
value|0x7ffffff
end_define

begin_define
define|#
directive|define
name|ENTRYHI_VPNSHIFT
value|13
end_define

begin_define
define|#
directive|define
name|ENTRYHI_R_SHIFT
value|62
end_define

begin_define
define|#
directive|define
name|R7K_ENTRYLO_PFNMASK
value|0xffffff
end_define

begin_define
define|#
directive|define
name|ENTRYLO_PFNSHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ENTRYLO_C_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R9K_ENTRYHI_VPNMASK
value|0x7ffffff
end_define

begin_comment
comment|/* same as r7k */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_PFNMASK
value|0xffffff
end_define

begin_comment
comment|/* same as r7k */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_WTNWA
value|(0x0<< 3)
end_define

begin_comment
comment|/* Cache NonCoher WriteThru No Alloc */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_WTWA
value|(0x1<< 3)
end_define

begin_comment
comment|/* Cache NonCoher WriteThru Wr Alloc */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_UNCACHED
value|(0x2<< 3)
end_define

begin_comment
comment|/* Uncached, blocking */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_CNONC_WB
value|(0x3<< 3)
end_define

begin_comment
comment|/* Cacheable NonCoherent WriteBack */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_CCEXCLU
value|(0x4<< 3)
end_define

begin_comment
comment|/* Cacheable Coherent Exclusive */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_CC_WB
value|(0x5<< 3)
end_define

begin_comment
comment|/* Cacheable Coherent Write Back */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_UNCNBLK
value|(0x6<< 3)
end_define

begin_comment
comment|/* Uncached, Nonblocking */
end_comment

begin_define
define|#
directive|define
name|R9K_ENTRYLO_C_FPC
value|(0x7<< 3)
end_define

begin_comment
comment|/* Fast Packet Cache */
end_comment

begin_define
define|#
directive|define
name|R7K_ENTRYLO_C_WB
value|(R7K_TLB_COHERENCY_WB<< 3)
end_define

begin_define
define|#
directive|define
name|R7K_ENTRYLO_C_UNCBLK
value|(R7K_TLB_COHERENCY_UNCBLK<< 3)
end_define

begin_define
define|#
directive|define
name|R7K_ENTRYLO_C_UNCNBLK
value|(R7K_TLB_COHERENCY_UNCNBLK<< 3)
end_define

begin_define
define|#
directive|define
name|R7K_ENTRYLO_C_BYPASS
value|(R7K_TLB_COHERENCY_BYPASS<< 3)
end_define

begin_define
define|#
directive|define
name|ENTRYLO_D
value|(0x1<< 2)
end_define

begin_define
define|#
directive|define
name|ENTRYLO_V
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|ENTRYLO_G
value|(0x1<< 0)
end_define

begin_comment
comment|/* C0_CAUSE bit definitions */
end_comment

begin_define
define|#
directive|define
name|CAUSE_BD
value|(0x1<< 31)
end_define

begin_define
define|#
directive|define
name|CAUSE_CE_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|CAUSE_CE_MASK
value|3
end_define

begin_define
define|#
directive|define
name|R7K_CAUSE_IV
value|(0x1<< 24)
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CAUSE_IV
value|(0x1<< 24)
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CAUSE_W1
value|(0x1<< 25)
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CAUSE_W2
value|(0x1<< 26)
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|CAUSE_IV
value|(0x1<< 23)
end_define

begin_define
define|#
directive|define
name|CAUSE_WP
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CAUSE_IP_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|R7K_CAUSE_IP_MASK
value|0xffff
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|R9K_CAUSE_IP_MASK
value|0xffff
end_define

begin_comment
comment|/* different from MIPS64 standard */
end_comment

begin_define
define|#
directive|define
name|CAUSE_IP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|CAUSE_IP
parameter_list|(
name|num
parameter_list|)
value|(0x1<< ((num) + CAUSE_IP_SHIFT))
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_INT
value|(0<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_MOD
value|(1<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_TLBL
value|(2<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_TLBS
value|(3<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_ADEL
value|(4<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_ADES
value|(5<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_IBE
value|(6<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_DBE
value|(7<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_SYS
value|(8<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_BP
value|(9<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_RI
value|(10<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_CPU
value|(11<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_OV
value|(12<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_TR
value|(13<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_FPE
value|(15<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|R7K_CAUSE_EXCCODE_IWE
value|(16<< CAUSE_EXCCODE_SHIFT)
end_define

begin_comment
comment|/* r7k implementation */
end_comment

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_C2E
value|(18<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_MDMX
value|(22<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|R7K_CAUSE_EXCCODE_DWE
value|(23<< CAUSE_EXCCODE_SHIFT)
end_define

begin_comment
comment|/* diff from standard */
end_comment

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_WATCH
value|(23<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_MACH_CHK
value|(24<< CAUSE_EXCCODE_SHIFT)
end_define

begin_define
define|#
directive|define
name|CAUSE_EXCCODE_CACHE_ERR
value|(30<< CAUSE_EXCCODE_SHIFT)
end_define

begin_comment
comment|/* C0_PRID bit definitions */
end_comment

begin_define
define|#
directive|define
name|PRID_GET_REV
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xff)
end_define

begin_define
define|#
directive|define
name|PRID_GET_RPID
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|R9K_PRID_GET_IMP
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|PRID_GET_CID
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|PRID_GET_OPT
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 24)& 0xff)
end_define

begin_comment
comment|/* C0_PRID bit definitions for R9K multiprocessor */
end_comment

begin_define
define|#
directive|define
name|R9K_PRID_GET_PNUM
parameter_list|(
name|val
parameter_list|)
value|(((val)>> 24)& 0x07)
end_define

begin_comment
comment|/* only 0& 1 are valid */
end_comment

begin_comment
comment|/* C0_1_INTCTL bit definitions for R7K and R9K */
end_comment

begin_define
define|#
directive|define
name|R7K_INTCTL_VS_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|R7K_INTCTL_VS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R7K_INTCTL_IMASK
value|0xff00
end_define

begin_comment
comment|/* C0_Watch bit definitions */
end_comment

begin_define
define|#
directive|define
name|WATCHLO_STORE
value|0x00000001
end_define

begin_comment
comment|/* watch stores */
end_comment

begin_define
define|#
directive|define
name|WATCHLO_LOAD
value|0x00000002
end_define

begin_comment
comment|/* watch loads */
end_comment

begin_define
define|#
directive|define
name|WATCHLO_FETCH
value|0x00000003
end_define

begin_comment
comment|/* watch loads */
end_comment

begin_define
define|#
directive|define
name|WATCHLO_PADDR0_MASK
value|0xfffffff8
end_define

begin_comment
comment|/* bits 31:3 of the paddr */
end_comment

begin_define
define|#
directive|define
name|WATCHHI_GLOBAL_BIT
value|(1<< 30)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MACHINE_CP0_H__ */
end_comment

begin_comment
comment|/* end of file */
end_comment

end_unit

