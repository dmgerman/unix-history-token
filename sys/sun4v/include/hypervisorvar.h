begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Kip Macy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_HYPERVISORVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_HYPERVISORVAR_H_
end_define

begin_comment
comment|/*  * Trap types  */
end_comment

begin_define
define|#
directive|define
name|FAST_TRAP
value|0x80
end_define

begin_comment
comment|/* Function # in %o5 */
end_comment

begin_define
define|#
directive|define
name|CPU_TICK_NPT
value|0x81
end_define

begin_define
define|#
directive|define
name|CPU_STICK_NPT
value|0x82
end_define

begin_define
define|#
directive|define
name|MMU_MAP_ADDR
value|0x83
end_define

begin_define
define|#
directive|define
name|MMU_UNMAP_ADDR
value|0x84
end_define

begin_define
define|#
directive|define
name|TTRACE_ADDENTRY
value|0x85
end_define

begin_comment
comment|/*  * Error returns in %o0.  * (Additional result is returned in %o1.)  */
end_comment

begin_define
define|#
directive|define
name|H_EOK
value|0
end_define

begin_comment
comment|/* Successful return */
end_comment

begin_define
define|#
directive|define
name|H_ENOCPU
value|1
end_define

begin_comment
comment|/* Invalid CPU id */
end_comment

begin_define
define|#
directive|define
name|H_ENORADDR
value|2
end_define

begin_comment
comment|/* Invalid real address */
end_comment

begin_define
define|#
directive|define
name|H_ENOINTR
value|3
end_define

begin_comment
comment|/* Invalid interrupt id */
end_comment

begin_define
define|#
directive|define
name|H_EBADPGSZ
value|4
end_define

begin_comment
comment|/* Invalid pagesize encoding */
end_comment

begin_define
define|#
directive|define
name|H_EBADTSB
value|5
end_define

begin_comment
comment|/* Invalid TSB description */
end_comment

begin_define
define|#
directive|define
name|H_EINVAL
value|6
end_define

begin_comment
comment|/* Invalid argument */
end_comment

begin_define
define|#
directive|define
name|H_EBADTRAP
value|7
end_define

begin_comment
comment|/* Invalid function number */
end_comment

begin_define
define|#
directive|define
name|H_EBADALIGN
value|8
end_define

begin_comment
comment|/* Invalid address alignment */
end_comment

begin_define
define|#
directive|define
name|H_EWOULDBLOCK
value|9
end_define

begin_comment
comment|/* Cannot complete operation */
end_comment

begin_comment
comment|/* without blocking */
end_comment

begin_define
define|#
directive|define
name|H_ENOACCESS
value|10
end_define

begin_comment
comment|/* No access to resource */
end_comment

begin_define
define|#
directive|define
name|H_EIO
value|11
end_define

begin_comment
comment|/* I/O error */
end_comment

begin_define
define|#
directive|define
name|H_ECPUERROR
value|12
end_define

begin_comment
comment|/* CPU is in error state */
end_comment

begin_define
define|#
directive|define
name|H_ENOTSUPPORTED
value|13
end_define

begin_comment
comment|/* Function not supported */
end_comment

begin_define
define|#
directive|define
name|H_ENOMAP
value|14
end_define

begin_comment
comment|/* Mapping is not valid, */
end_comment

begin_comment
comment|/* no translation exists */
end_comment

begin_define
define|#
directive|define
name|H_BREAK
value|-1
end_define

begin_comment
comment|/* Console Break */
end_comment

begin_define
define|#
directive|define
name|H_HUP
value|-2
end_define

begin_comment
comment|/* Console Break */
end_comment

begin_comment
comment|/*  * Mondo CPU ID argument processing.  */
end_comment

begin_define
define|#
directive|define
name|HV_SEND_MONDO_ENTRYDONE
value|0xffff
end_define

begin_comment
comment|/*  * Function numbers for FAST_TRAP.  */
end_comment

begin_define
define|#
directive|define
name|HV_MACH_EXIT
value|0x00
end_define

begin_define
define|#
directive|define
name|HV_MACH_DESC
value|0x01
end_define

begin_define
define|#
directive|define
name|HV_CPU_YIELD
value|0x12
end_define

begin_define
define|#
directive|define
name|CPU_QCONF
value|0x14
end_define

begin_define
define|#
directive|define
name|HV_CPU_STATE
value|0x17
end_define

begin_define
define|#
directive|define
name|MMU_TSB_CTX0
value|0x20
end_define

begin_define
define|#
directive|define
name|MMU_TSB_CTXNON0
value|0x21
end_define

begin_define
define|#
directive|define
name|MMU_DEMAP_PAGE
value|0x22
end_define

begin_define
define|#
directive|define
name|MMU_DEMAP_CTX
value|0x23
end_define

begin_define
define|#
directive|define
name|MMU_DEMAP_ALL
value|0x24
end_define

begin_define
define|#
directive|define
name|MAP_PERM_ADDR
value|0x25
end_define

begin_define
define|#
directive|define
name|MMU_SET_INFOPTR
value|0x26
end_define

begin_define
define|#
directive|define
name|UNMAP_PERM_ADDR
value|0x28
end_define

begin_define
define|#
directive|define
name|HV_MEM_SCRUB
value|0x31
end_define

begin_define
define|#
directive|define
name|HV_MEM_SYNC
value|0x32
end_define

begin_define
define|#
directive|define
name|HV_INTR_SEND
value|0x42
end_define

begin_define
define|#
directive|define
name|TOD_GET
value|0x50
end_define

begin_define
define|#
directive|define
name|TOD_SET
value|0x51
end_define

begin_define
define|#
directive|define
name|CONS_GETCHAR
value|0x60
end_define

begin_define
define|#
directive|define
name|CONS_PUTCHAR
value|0x61
end_define

begin_define
define|#
directive|define
name|CONS_READ
value|0x62
end_define

begin_define
define|#
directive|define
name|CONS_WRITE
value|0x63
end_define

begin_define
define|#
directive|define
name|SVC_SEND
value|0x80
end_define

begin_define
define|#
directive|define
name|SVC_RECV
value|0x81
end_define

begin_define
define|#
directive|define
name|SVC_GETSTATUS
value|0x82
end_define

begin_define
define|#
directive|define
name|SVC_SETSTATUS
value|0x83
end_define

begin_define
define|#
directive|define
name|SVC_CLRSTATUS
value|0x84
end_define

begin_define
define|#
directive|define
name|TTRACE_BUF_CONF
value|0x90
end_define

begin_define
define|#
directive|define
name|TTRACE_BUF_INFO
value|0x91
end_define

begin_define
define|#
directive|define
name|TTRACE_ENABLE
value|0x92
end_define

begin_define
define|#
directive|define
name|TTRACE_FREEZE
value|0x93
end_define

begin_define
define|#
directive|define
name|DUMP_BUF_UPDATE
value|0x94
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_DEVINO2SYSINO
value|0xa0
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_GETENABLED
value|0xa1
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_SETENABLED
value|0xa2
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_GETSTATE
value|0xa3
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_SETSTATE
value|0xa4
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_GETTARGET
value|0xa5
end_define

begin_define
define|#
directive|define
name|HVIO_INTR_SETTARGET
value|0xa6
end_define

begin_define
define|#
directive|define
name|HVIO_IOMMU_MAP
value|0xb0
end_define

begin_define
define|#
directive|define
name|HVIO_IOMMU_DEMAP
value|0xb1
end_define

begin_define
define|#
directive|define
name|HVIO_IOMMU_GETMAP
value|0xb2
end_define

begin_define
define|#
directive|define
name|HVIO_IOMMU_GETBYPASS
value|0xb3
end_define

begin_define
define|#
directive|define
name|HVIO_CONFIG_GET
value|0xb4
end_define

begin_define
define|#
directive|define
name|HVIO_CONFIG_PUT
value|0xb5
end_define

begin_define
define|#
directive|define
name|HVIO_PEEK
value|0xb6
end_define

begin_define
define|#
directive|define
name|HVIO_POKE
value|0xb7
end_define

begin_define
define|#
directive|define
name|HVIO_DMA_SYNC
value|0xb8
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_CONF
value|0xc0
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_INFO
value|0xc1
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_GETVALID
value|0xc2
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_SETVALID
value|0xc3
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_GETSTATE
value|0xc4
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_SETSTATE
value|0xc5
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_GETHEAD
value|0xc6
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_SETHEAD
value|0xc7
end_define

begin_define
define|#
directive|define
name|HVIO_MSIQ_GETTAIL
value|0xc8
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_GETVALID
value|0xc9
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_SETVALID
value|0xca
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_GETMSIQ
value|0xcb
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_SETMSIQ
value|0xcc
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_GETSTATE
value|0xcd
end_define

begin_define
define|#
directive|define
name|HVIO_MSI_SETSTATE
value|0xce
end_define

begin_define
define|#
directive|define
name|HVIO_MSG_GETMSIQ
value|0xd0
end_define

begin_define
define|#
directive|define
name|HVIO_MSG_SETMSIQ
value|0xd1
end_define

begin_define
define|#
directive|define
name|HVIO_MSG_GETVALID
value|0xd2
end_define

begin_define
define|#
directive|define
name|HVIO_MSG_SETVALID
value|0xd3
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_TX_QCONF
value|0xe0
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_TX_QINFO
value|0xe1
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_TX_GET_STATE
value|0xe2
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_TX_SET_QTAIL
value|0xe3
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_RX_QCONF
value|0xe4
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_RX_QINFO
value|0xe5
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_RX_GET_STATE
value|0xe6
end_define

begin_define
define|#
directive|define
name|HVIO_LDC_RX_SET_QHEAD
value|0xe7
end_define

begin_define
define|#
directive|define
name|HVIO_SIM_READ
value|0xf0
end_define

begin_define
define|#
directive|define
name|HVIO_SIM_WRITE
value|0xf1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SET_MMU_STATS
end_ifdef

begin_define
define|#
directive|define
name|MMU_STAT_AREA
value|0xfc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SET_MMU_STATS */
end_comment

begin_define
define|#
directive|define
name|HV_NCS_REQUEST
value|0x110
end_define

begin_define
define|#
directive|define
name|FIRE_GET_PERFREG
value|0x120
end_define

begin_define
define|#
directive|define
name|FIRE_SET_PERFREG
value|0x121
end_define

begin_define
define|#
directive|define
name|HV_RA2PA
value|0x200
end_define

begin_define
define|#
directive|define
name|HV_HPRIV
value|0x201
end_define

begin_comment
comment|/*  * Bits for MMU functions flags argument:  *	arg3 of MMU_MAP_ADDR  *	arg3 of MMU_DEMAP_CTX  *	arg2 of MMU_DEMAP_ALL  */
end_comment

begin_define
define|#
directive|define
name|MAP_DTLB
value|0x1
end_define

begin_define
define|#
directive|define
name|MAP_ITLB
value|0x2
end_define

begin_comment
comment|/*  * Interrupt state manipulation definitions.  */
end_comment

begin_define
define|#
directive|define
name|HV_INTR_IDLE_STATE
value|0
end_define

begin_define
define|#
directive|define
name|HV_INTR_RECEIVED_STATE
value|1
end_define

begin_define
define|#
directive|define
name|HV_INTR_DELIVERED_STATE
value|2
end_define

begin_define
define|#
directive|define
name|HV_INTR_NOTVALID
value|0
end_define

begin_define
define|#
directive|define
name|HV_INTR_VALID
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_comment
comment|/*  * TSB description structure for MMU_TSB_CTX0 and MMU_TSB_CTXNON0.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|hv_tsb_info
block|{
name|uint16_t
name|hvtsb_idxpgsz
decl_stmt|;
comment|/* page size used to index TSB */
name|uint16_t
name|hvtsb_assoc
decl_stmt|;
comment|/* TSB associativity */
name|uint32_t
name|hvtsb_ntte
decl_stmt|;
comment|/* TSB size (#TTE entries) */
name|uint32_t
name|hvtsb_ctx_index
decl_stmt|;
comment|/* context reg index */
name|uint32_t
name|hvtsb_pgszs
decl_stmt|;
comment|/* sizes in use */
name|uint64_t
name|hvtsb_pa
decl_stmt|;
comment|/* real address of TSB base */
name|uint64_t
name|hvtsb_rsvd
decl_stmt|;
comment|/* reserved */
block|}
name|hv_tsb_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HVTSB_SHARE_INDEX
value|((uint32_t)-1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SET_MMU_STATS
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|TTE4V_NPGSZ
end_ifndef

begin_define
define|#
directive|define
name|TTE4V_NPGSZ
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TTE4V_NPGSZ */
end_comment

begin_comment
comment|/*  * MMU statistics structure for MMU_STAT_AREA  */
end_comment

begin_struct
struct|struct
name|mmu_stat_one
block|{
name|uint64_t
name|hit_ctx0
index|[
name|TTE4V_NPGSZ
index|]
decl_stmt|;
name|uint64_t
name|hit_ctxn0
index|[
name|TTE4V_NPGSZ
index|]
decl_stmt|;
name|uint64_t
name|tsb_miss
decl_stmt|;
name|uint64_t
name|tlb_miss
decl_stmt|;
comment|/* miss, no TSB set */
name|uint64_t
name|map_ctx0
index|[
name|TTE4V_NPGSZ
index|]
decl_stmt|;
name|uint64_t
name|map_ctxn0
index|[
name|TTE4V_NPGSZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mmu_stat
block|{
name|struct
name|mmu_stat_one
name|immu_stat
decl_stmt|;
name|struct
name|mmu_stat_one
name|dmmu_stat
decl_stmt|;
name|uint64_t
name|set_ctx0
decl_stmt|;
name|uint64_t
name|set_ctxn0
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SET_MMU_STATS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ASM */
end_comment

begin_comment
comment|/*  * CPU States  */
end_comment

begin_define
define|#
directive|define
name|CPU_STATE_INVALID
value|0x0
end_define

begin_define
define|#
directive|define
name|CPU_STATE_IDLE
value|0x1
end_define

begin_comment
comment|/* cpu not started */
end_comment

begin_define
define|#
directive|define
name|CPU_STATE_GUEST
value|0x2
end_define

begin_comment
comment|/* cpu running guest code */
end_comment

begin_define
define|#
directive|define
name|CPU_STATE_ERROR
value|0x3
end_define

begin_comment
comment|/* cpu is in the error state */
end_comment

begin_define
define|#
directive|define
name|CPU_STATE_LAST_PUBLIC
value|CPU_STATE_ERROR
end_define

begin_comment
comment|/* last valid state */
end_comment

begin_comment
comment|/*  * MMU fault status area  */
end_comment

begin_define
define|#
directive|define
name|MMFSA_TYPE_
value|0x00
end_define

begin_comment
comment|/* fault type */
end_comment

begin_define
define|#
directive|define
name|MMFSA_ADDR_
value|0x08
end_define

begin_comment
comment|/* fault address */
end_comment

begin_define
define|#
directive|define
name|MMFSA_CTX_
value|0x10
end_define

begin_comment
comment|/* fault context */
end_comment

begin_define
define|#
directive|define
name|MMFSA_I_
value|0x00
end_define

begin_comment
comment|/* start of fields for I */
end_comment

begin_define
define|#
directive|define
name|MMFSA_I_TYPE
value|(MMFSA_I_ + MMFSA_TYPE_)
end_define

begin_comment
comment|/* instruction fault type */
end_comment

begin_define
define|#
directive|define
name|MMFSA_I_ADDR
value|(MMFSA_I_ + MMFSA_ADDR_)
end_define

begin_comment
comment|/* instruction fault address */
end_comment

begin_define
define|#
directive|define
name|MMFSA_I_CTX
value|(MMFSA_I_ + MMFSA_CTX_)
end_define

begin_comment
comment|/* instruction fault context */
end_comment

begin_define
define|#
directive|define
name|MMFSA_D_
value|0x40
end_define

begin_comment
comment|/* start of fields for D */
end_comment

begin_define
define|#
directive|define
name|MMFSA_D_TYPE
value|(MMFSA_D_ + MMFSA_TYPE_)
end_define

begin_comment
comment|/* data fault type */
end_comment

begin_define
define|#
directive|define
name|MMFSA_D_ADDR
value|(MMFSA_D_ + MMFSA_ADDR_)
end_define

begin_comment
comment|/* data fault address */
end_comment

begin_define
define|#
directive|define
name|MMFSA_D_CTX
value|(MMFSA_D_ + MMFSA_CTX_)
end_define

begin_comment
comment|/* data fault context */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_FMISS
value|1
end_define

begin_comment
comment|/* fast miss */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_FPROT
value|2
end_define

begin_comment
comment|/* fast protection */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_MISS
value|3
end_define

begin_comment
comment|/* mmu miss */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_INVRA
value|4
end_define

begin_comment
comment|/* invalid RA */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_PRIV
value|5
end_define

begin_comment
comment|/* privilege violation */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_PROT
value|6
end_define

begin_comment
comment|/* protection violation */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_NFO
value|7
end_define

begin_comment
comment|/* NFO access */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_SOPG
value|8
end_define

begin_comment
comment|/* so page */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_INVVA
value|9
end_define

begin_comment
comment|/* invalid VA */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_INVASI
value|10
end_define

begin_comment
comment|/* invalid ASI */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_NCATM
value|11
end_define

begin_comment
comment|/* non-cacheable atomic */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_PRVACT
value|12
end_define

begin_comment
comment|/* privileged action */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_WPT
value|13
end_define

begin_comment
comment|/* watchpoint hit */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_UNALIGN
value|14
end_define

begin_comment
comment|/* unaligned access */
end_comment

begin_define
define|#
directive|define
name|MMFSA_F_INVPGSZ
value|15
end_define

begin_comment
comment|/* invalid page size */
end_comment

begin_define
define|#
directive|define
name|MMFSA_SIZE
value|0x80
end_define

begin_comment
comment|/* in bytes, 64 byte aligned */
end_comment

begin_comment
comment|/*  * MMU fault status - MMFSA_IFS and MMFSA_DFS  */
end_comment

begin_define
define|#
directive|define
name|MMFS_FV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MMFS_OW
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MMFS_W
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MMFS_PR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MMFS_CT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|MMFS_E
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MMFS_FT
value|0x00003f80
end_define

begin_define
define|#
directive|define
name|MMFS_ME
value|0x00004000
end_define

begin_define
define|#
directive|define
name|MMFS_TM
value|0x00008000
end_define

begin_define
define|#
directive|define
name|MMFS_ASI
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|MMFS_NF
value|0x01000000
end_define

begin_comment
comment|/*  * DMA sync parameter definitions  */
end_comment

begin_define
define|#
directive|define
name|HVIO_DMA_SYNC_DIR_TO_DEV
value|0x01
end_define

begin_define
define|#
directive|define
name|HVIO_DMA_SYNC_DIR_FROM_DEV
value|0x02
end_define

begin_comment
comment|/*  * Performance counter register definitions.  */
end_comment

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_JBC_SEL
value|0
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_JBC_CNT0
value|1
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_JBC_CNT1
value|2
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_IMU_SEL
value|3
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_IMU_CNT0
value|4
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_IMU_CNT1
value|5
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_MMU_SEL
value|6
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_MMU_CNT0
value|7
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_MMU_CNT1
value|8
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_TLU_SEL
value|9
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_TLU_CNT0
value|10
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_TLU_CNT1
value|11
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_TLU_CNT2
value|12
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_LNK_SEL
value|13
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_LNK_CNT1
value|14
end_define

begin_define
define|#
directive|define
name|HVIO_FIRE_PERFREG_PCIE_LNK_CNT2
value|15
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATOR
end_ifdef

begin_define
define|#
directive|define
name|MAGIC_TRAP_ON
value|ta	0x77
end_define

begin_define
define|#
directive|define
name|MAGIC_TRAP_OFF
value|ta	0x78
end_define

begin_define
define|#
directive|define
name|MAGIC_EXIT
value|ta	0x71
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAGIC_TRAP_ON
value|nop
end_define

begin_define
define|#
directive|define
name|MAGIC_TRAP_OFF
value|nop
end_define

begin_define
define|#
directive|define
name|MAGIC_EXIT
value|nop
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_MACHINE_HYPERVISORVAR_H_ */
end_comment

end_unit

