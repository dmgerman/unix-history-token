begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cpu.h 1.13 89/06/23$  *  *	@(#)cpu.h	7.4 (Berkeley) %G%  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_include
include|#
directive|include
file|"../hp300/psl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Exported definitions unique to hp300/68k cpu support.  */
end_comment

begin_comment
comment|/*  * definitions of cpu-dependent requirements  * referenced in generic code  */
end_comment

begin_define
define|#
directive|define
name|COPY_SIGCODE
end_define

begin_comment
comment|/* copy sigcode above user stack in exec */
end_comment

begin_comment
comment|/*  * function vs. inline configuration;  * these are defined to get generic functions  * rather than inline or machine-dependent implementations  */
end_comment

begin_define
define|#
directive|define
name|NEED_MINMAX
end_define

begin_comment
comment|/* need {,i,l,ul}{min,max} functions */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_FFS
end_undef

begin_comment
comment|/* don't need ffs function */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_BCMP
end_undef

begin_comment
comment|/* don't need bcmp function */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_STRLEN
end_undef

begin_comment
comment|/* don't need strlen function */
end_comment

begin_define
define|#
directive|define
name|cpu_exec
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_comment
comment|/*  * Arguments to hardclock, softclock and gatherstats  * encapsulate the previous machine state in an opaque  * clockframe; for hp300, use just what the hardware  * leaves on the stack.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|intrframe
block|{
name|int
name|pc
decl_stmt|;
name|int
name|ps
decl_stmt|;
block|}
name|clockframe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|USERMODE((framep)->ps)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|BASEPRI((framep)->ps)
end_define

begin_define
define|#
directive|define
name|CLKF_PC
parameter_list|(
name|framep
parameter_list|)
value|((framep)->pc)
end_define

begin_comment
comment|/*  * Preempt the current process if in interrupt from user mode,  * or after the current trap/syscall if in system mode.  */
end_comment

begin_define
define|#
directive|define
name|need_resched
parameter_list|()
value|{ want_resched++; aston(); }
end_define

begin_comment
comment|/*  * Give a profiling tick to the current process from the softclock  * interrupt.  On hp300, request an ast to send us through trap(),  * marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|profile_tick
parameter_list|(
name|p
parameter_list|,
name|framep
parameter_list|)
value|{ (p)->p_flag |= SOWEUPC; aston(); }
end_define

begin_decl_stmt
name|int
name|want_resched
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* resched() was called */
end_comment

begin_comment
comment|/*  * simulated software interrupt register  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|ssir
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SIR_NET
value|0x1
end_define

begin_define
define|#
directive|define
name|SIR_CLOCK
value|0x2
end_define

begin_define
define|#
directive|define
name|siroff
parameter_list|(
name|x
parameter_list|)
value|ssir&= ~(x)
end_define

begin_define
define|#
directive|define
name|setsoftnet
parameter_list|()
value|ssir |= SIR_NET
end_define

begin_define
define|#
directive|define
name|setsoftclock
parameter_list|()
value|ssir |= SIR_CLOCK
end_define

begin_comment
comment|/*  * The rest of this should probably be moved to ../hp300/hp300cpu.h,  * although some of it could probably be put into generic 68k headers.  */
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
name|unsigned
name|long
name|DIObase
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
comment|/* DIO space stuff */
end_comment

begin_define
define|#
directive|define
name|INTERNALHPIB
value|(0x00478000)
end_define

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
value|(((x) - IOBASE) + DIObase)
end_define

begin_define
define|#
directive|define
name|UNIOV
parameter_list|(
name|x
parameter_list|)
value|((x) - DIObase + IOBASE)
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
comment|/* base/offsets for longword read/write (for locore.s) */
end_comment

begin_define
define|#
directive|define
name|MMUBASE
value|IOP(0x5F4000)
end_define

begin_define
define|#
directive|define
name|MMUSSTP
value|0x0
end_define

begin_define
define|#
directive|define
name|MMUUSTP
value|0x4
end_define

begin_define
define|#
directive|define
name|MMUTBINVAL
value|0x8
end_define

begin_define
define|#
directive|define
name|MMUSTAT
value|0xC
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
comment|/* 680X0 function codes */
end_comment

begin_define
define|#
directive|define
name|FC_USERD
value|1
end_define

begin_comment
comment|/* user data space */
end_comment

begin_define
define|#
directive|define
name|FC_USERP
value|2
end_define

begin_comment
comment|/* user program space */
end_comment

begin_define
define|#
directive|define
name|FC_PURGE
value|3
end_define

begin_comment
comment|/* HPMMU: clear TLB entries */
end_comment

begin_define
define|#
directive|define
name|FC_SUPERD
value|5
end_define

begin_comment
comment|/* supervisor data space */
end_comment

begin_define
define|#
directive|define
name|FC_SUPERP
value|6
end_define

begin_comment
comment|/* supervisor program space */
end_comment

begin_define
define|#
directive|define
name|FC_CPU
value|7
end_define

begin_comment
comment|/* CPU space */
end_comment

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

