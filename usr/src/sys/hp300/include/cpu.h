begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cpu.h 1.13 89/06/23$  *  *	@(#)cpu.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* values for machineid */
end_comment

begin_define
define|#
directive|define
name|HP_320
value|0
end_define

begin_comment
comment|/* 16Mhz 68020+HP MMU+16K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_330
value|1
end_define

begin_comment
comment|/* 16Mhz 68020+68851 MMU */
end_comment

begin_define
define|#
directive|define
name|HP_350
value|2
end_define

begin_comment
comment|/* 25Mhz 68020+HP MMU+32K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_360
value|3
end_define

begin_comment
comment|/* 25Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_370
value|4
end_define

begin_comment
comment|/* 33Mhz 68030+64K external cache */
end_comment

begin_define
define|#
directive|define
name|HP_340
value|5
end_define

begin_comment
comment|/* 16Mhz 68030 */
end_comment

begin_define
define|#
directive|define
name|HP_375
value|6
end_define

begin_comment
comment|/* 50Mhz 68030+32K external cache */
end_comment

begin_comment
comment|/* values for mmutype (assigned for quick testing) */
end_comment

begin_define
define|#
directive|define
name|MMU_68030
value|-1
end_define

begin_comment
comment|/* 68030 on-chip subset of 68851 */
end_comment

begin_define
define|#
directive|define
name|MMU_HP
value|0
end_define

begin_comment
comment|/* HP proprietary */
end_comment

begin_define
define|#
directive|define
name|MMU_68851
value|1
end_define

begin_comment
comment|/* Motorola 68851 */
end_comment

begin_comment
comment|/* values for ectype */
end_comment

begin_define
define|#
directive|define
name|EC_PHYS
value|-1
end_define

begin_comment
comment|/* external physical address cache */
end_comment

begin_define
define|#
directive|define
name|EC_NONE
value|0
end_define

begin_comment
comment|/* no external cache */
end_comment

begin_define
define|#
directive|define
name|EC_VIRT
value|1
end_define

begin_comment
comment|/* external virtual address cache */
end_comment

begin_comment
comment|/* values for cpuspeed (not really related to clock speed due to caches) */
end_comment

begin_define
define|#
directive|define
name|MHZ_8
value|1
end_define

begin_define
define|#
directive|define
name|MHZ_16
value|2
end_define

begin_define
define|#
directive|define
name|MHZ_25
value|3
end_define

begin_define
define|#
directive|define
name|MHZ_33
value|4
end_define

begin_define
define|#
directive|define
name|MHZ_50
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|machineid
decl_stmt|,
name|mmutype
decl_stmt|,
name|ectype
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|IObase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* what is this supposed to do? i.e. how is it different than startrtclock? */
end_comment

begin_define
define|#
directive|define
name|enablertclock
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* physical memory sections */
end_comment

begin_define
define|#
directive|define
name|ROMBASE
value|(0x00000000)
end_define

begin_define
define|#
directive|define
name|IOBASE
value|(0x00200000)
end_define

begin_define
define|#
directive|define
name|IOTOP
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|MAXADDR
value|(0xFFFFF000)
end_define

begin_comment
comment|/* IO space stuff */
end_comment

begin_define
define|#
directive|define
name|EXTIOBASE
value|(0x00600000)
end_define

begin_define
define|#
directive|define
name|IOCARDSIZE
value|(0x10000)
end_define

begin_define
define|#
directive|define
name|IOMAPSIZE
value|(btoc(IOTOP-IOBASE))
end_define

begin_define
define|#
directive|define
name|IOP
parameter_list|(
name|x
parameter_list|)
value|((x) - IOBASE)
end_define

begin_define
define|#
directive|define
name|IOV
parameter_list|(
name|x
parameter_list|)
value|(((x) - IOBASE) + (int)&IObase)
end_define

begin_define
define|#
directive|define
name|UNIOV
parameter_list|(
name|x
parameter_list|)
value|((x) - (int)&IObase + IOBASE)
end_define

begin_comment
comment|/* DIO II uncached address space */
end_comment

begin_define
define|#
directive|define
name|DIOIIBASE
value|(0x01000000)
end_define

begin_define
define|#
directive|define
name|DIOIITOP
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|DIOIICSIZE
value|(0x00400000)
end_define

begin_comment
comment|/* offsets for longword read/write */
end_comment

begin_define
define|#
directive|define
name|MMUSSTP
value|IOP(0x5F4000)
end_define

begin_define
define|#
directive|define
name|MMUUSTP
value|IOP(0x5F4004)
end_define

begin_define
define|#
directive|define
name|MMUTBINVAL
value|IOP(0x5F4008)
end_define

begin_define
define|#
directive|define
name|MMUSTAT
value|IOP(0x5F400C)
end_define

begin_define
define|#
directive|define
name|MMUCMD
value|MMUSTAT
end_define

begin_define
define|#
directive|define
name|MMU_UMEN
value|0x0001
end_define

begin_comment
comment|/* enable user mapping */
end_comment

begin_define
define|#
directive|define
name|MMU_SMEN
value|0x0002
end_define

begin_comment
comment|/* enable supervisor mapping */
end_comment

begin_define
define|#
directive|define
name|MMU_CEN
value|0x0004
end_define

begin_comment
comment|/* enable data cache */
end_comment

begin_define
define|#
directive|define
name|MMU_BERR
value|0x0008
end_define

begin_comment
comment|/* bus error */
end_comment

begin_define
define|#
directive|define
name|MMU_IEN
value|0x0020
end_define

begin_comment
comment|/* enable instruction cache */
end_comment

begin_define
define|#
directive|define
name|MMU_FPE
value|0x0040
end_define

begin_comment
comment|/* enable 68881 FP coprocessor */
end_comment

begin_define
define|#
directive|define
name|MMU_WPF
value|0x2000
end_define

begin_comment
comment|/* write protect fault */
end_comment

begin_define
define|#
directive|define
name|MMU_PF
value|0x4000
end_define

begin_comment
comment|/* page fault */
end_comment

begin_define
define|#
directive|define
name|MMU_PTF
value|0x8000
end_define

begin_comment
comment|/* page table fault */
end_comment

begin_define
define|#
directive|define
name|MMU_FAULT
value|(MMU_PTF|MMU_PF|MMU_WPF|MMU_BERR)
end_define

begin_define
define|#
directive|define
name|MMU_ENAB
value|(MMU_UMEN|MMU_SMEN|MMU_IEN|MMU_FPE)
end_define

begin_define
define|#
directive|define
name|PMMU_LVLMASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|PMMU_INV
value|0x0400
end_define

begin_define
define|#
directive|define
name|PMMU_WP
value|0x0800
end_define

begin_define
define|#
directive|define
name|PMMU_ALV
value|0x1000
end_define

begin_define
define|#
directive|define
name|PMMU_SO
value|0x2000
end_define

begin_define
define|#
directive|define
name|PMMU_LV
value|0x4000
end_define

begin_define
define|#
directive|define
name|PMMU_BE
value|0x8000
end_define

begin_define
define|#
directive|define
name|PMMU_FAULT
value|(PMMU_WP|PMMU_INV)
end_define

begin_comment
comment|/* function code for user data space */
end_comment

begin_define
define|#
directive|define
name|FC_USERD
value|1
end_define

begin_comment
comment|/* methinks the following is used to selectively clear TLB entries */
end_comment

begin_define
define|#
directive|define
name|FC_PURGE
value|3
end_define

begin_comment
comment|/* fields in the 68020 cache control register */
end_comment

begin_define
define|#
directive|define
name|IC_ENABLE
value|0x0001
end_define

begin_comment
comment|/* enable instruction cache */
end_comment

begin_define
define|#
directive|define
name|IC_FREEZE
value|0x0002
end_define

begin_comment
comment|/* freeze instruction cache */
end_comment

begin_define
define|#
directive|define
name|IC_CE
value|0x0004
end_define

begin_comment
comment|/* clear instruction cache entry */
end_comment

begin_define
define|#
directive|define
name|IC_CLR
value|0x0008
end_define

begin_comment
comment|/* clear entire instruction cache */
end_comment

begin_comment
comment|/* additional fields in the 68030 cache control register */
end_comment

begin_define
define|#
directive|define
name|IC_BE
value|0x0010
end_define

begin_comment
comment|/* instruction burst enable */
end_comment

begin_define
define|#
directive|define
name|DC_ENABLE
value|0x0100
end_define

begin_comment
comment|/* data cache enable */
end_comment

begin_define
define|#
directive|define
name|DC_FREEZE
value|0x0200
end_define

begin_comment
comment|/* data cache freeze */
end_comment

begin_define
define|#
directive|define
name|DC_CE
value|0x0400
end_define

begin_comment
comment|/* clear data cache entry */
end_comment

begin_define
define|#
directive|define
name|DC_CLR
value|0x0800
end_define

begin_comment
comment|/* clear entire data cache */
end_comment

begin_define
define|#
directive|define
name|DC_BE
value|0x1000
end_define

begin_comment
comment|/* data burst enable */
end_comment

begin_define
define|#
directive|define
name|DC_WA
value|0x2000
end_define

begin_comment
comment|/* write allocate */
end_comment

begin_define
define|#
directive|define
name|CACHE_ON
value|(DC_WA|DC_BE|DC_CLR|DC_ENABLE|IC_BE|IC_CLR|IC_ENABLE)
end_define

begin_define
define|#
directive|define
name|CACHE_OFF
value|(DC_CLR|IC_CLR)
end_define

begin_define
define|#
directive|define
name|CACHE_CLR
value|(CACHE_ON)
end_define

begin_define
define|#
directive|define
name|IC_CLEAR
value|(DC_WA|DC_BE|DC_ENABLE|IC_BE|IC_CLR|IC_ENABLE)
end_define

begin_define
define|#
directive|define
name|DC_CLEAR
value|(DC_WA|DC_BE|DC_CLR|DC_ENABLE|IC_BE|IC_ENABLE)
end_define

end_unit

