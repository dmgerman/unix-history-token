begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1982, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: cpu.h 1.16 91/03/25$  *  *	@(#)cpu.h	8.4 (Berkeley) %G%  */
end_comment

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

begin_define
define|#
directive|define
name|cpu_swapin
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|cpu_wait
parameter_list|(
name|p
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|cpu_setstack
parameter_list|(
name|p
parameter_list|,
name|ap
parameter_list|)
value|(p)->p_md.md_regs[SP] = ap
end_define

begin_define
define|#
directive|define
name|cpu_set_init_frame
parameter_list|(
name|p
parameter_list|,
name|fp
parameter_list|)
value|(p)->p_md.md_regs = fp
end_define

begin_comment
comment|/*  * Arguments to hardclock and gatherstats encapsulate the previous  * machine state in an opaque clockframe.  One the hp300, we use  * what the hardware pushes on an interrupt (frame format 0).  */
end_comment

begin_struct
struct|struct
name|clockframe
block|{
name|u_short
name|sr
decl_stmt|;
comment|/* sr at time of interrupt */
name|u_long
name|pc
decl_stmt|;
comment|/* pc at time of interrupt */
name|u_short
name|vo
decl_stmt|;
comment|/* vector offset (4-word frame) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CLKF_USERMODE
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->sr& PSL_S) == 0)
end_define

begin_define
define|#
directive|define
name|CLKF_BASEPRI
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->sr& PSL_IPL) == 0)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* We would like to do it this way... */
end_comment

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(((framep)->sr& PSL_M) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* but until we start using PSL_M, we have to do this instead */
end_comment

begin_define
define|#
directive|define
name|CLKF_INTR
parameter_list|(
name|framep
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* XXX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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
comment|/*  * Give a profiling tick to the current process when the user profiling  * buffer pages are invalid.  On the hp300, request an ast to send us  * through trap, marking the proc as needing a profiling tick.  */
end_comment

begin_define
define|#
directive|define
name|need_proftick
parameter_list|(
name|p
parameter_list|)
value|{ (p)->p_flag |= P_OWEUPC; aston(); }
end_define

begin_comment
comment|/*  * Notify the current process (p) that it has a signal pending,  * process as soon as possible.  */
end_comment

begin_define
define|#
directive|define
name|signotify
parameter_list|(
name|p
parameter_list|)
value|aston()
end_define

begin_define
define|#
directive|define
name|aston
parameter_list|()
value|(astpending++)
end_define

begin_decl_stmt
name|int
name|astpending
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* need to trap before returning to user mode */
end_comment

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
comment|/*  * CTL_MACHDEP definitions.  */
end_comment

begin_define
define|#
directive|define
name|CPU_CONSDEV
value|1
end_define

begin_comment
comment|/* dev_t: console terminal device */
end_comment

begin_define
define|#
directive|define
name|CPU_MAXID
value|2
end_define

begin_comment
comment|/* number of valid machdep ids */
end_comment

begin_define
define|#
directive|define
name|CTL_MACHDEP_NAMES
value|{ \ 	{ 0, 0 }, \ 	{ "console_device", CTLTYPE_STRUCT }, \ }
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

begin_define
define|#
directive|define
name|HP_380
value|7
end_define

begin_comment
comment|/* 25Mhz 68040 */
end_comment

begin_define
define|#
directive|define
name|HP_433
value|8
end_define

begin_comment
comment|/* 33Mhz 68040 */
end_comment

begin_comment
comment|/* values for mmutype (assigned for quick testing) */
end_comment

begin_define
define|#
directive|define
name|MMU_68040
value|-2
end_define

begin_comment
comment|/* 68040 on-chip MMU */
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
name|char
modifier|*
name|intiobase
decl_stmt|,
modifier|*
name|intiolimit
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
name|INTIOBASE
value|(0x00400000)
end_define

begin_define
define|#
directive|define
name|INTIOTOP
value|(0x00600000)
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
name|EXTIOTOP
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|MAXADDR
value|(0xFFFFF000)
end_define

begin_comment
comment|/*  * Internal IO space:  *  * Ranges from 0x400000 to 0x600000 (IIOMAPSIZE).  *  * Internal IO space is mapped in the kernel from ``intiobase'' to  * ``intiolimit'' (defined in locore.s).  Since it is always mapped,  * conversion between physical and kernel virtual addresses is easy.  */
end_comment

begin_define
define|#
directive|define
name|ISIIOVA
parameter_list|(
name|va
parameter_list|)
define|\
value|((char *)(va)>= intiobase&& (char *)(va)< intiolimit)
end_define

begin_define
define|#
directive|define
name|IIOV
parameter_list|(
name|pa
parameter_list|)
value|((int)(pa)-INTIOBASE+(int)intiobase)
end_define

begin_define
define|#
directive|define
name|IIOP
parameter_list|(
name|va
parameter_list|)
value|((int)(va)-(int)intiobase+INTIOBASE)
end_define

begin_define
define|#
directive|define
name|IIOPOFF
parameter_list|(
name|pa
parameter_list|)
value|((int)(pa)-INTIOBASE)
end_define

begin_define
define|#
directive|define
name|IIOMAPSIZE
value|btoc(INTIOTOP-INTIOBASE)
end_define

begin_comment
comment|/* 2mb */
end_comment

begin_comment
comment|/*  * External IO space:  *  * DIO ranges from select codes 0-63 at physical addresses given by:  *	0x600000 + (sc - 32) * 0x10000  * DIO cards are addressed in the range 0-31 [0x600000-0x800000) for  * their control space and the remaining areas, [0x200000-0x400000) and  * [0x800000-0x1000000), are for additional space required by a card;  * e.g. a display framebuffer.  *  * DIO-II ranges from select codes 132-255 at physical addresses given by:  *	0x1000000 + (sc - 132) * 0x400000  * The address range of DIO-II space is thus [0x1000000-0x20000000).  *  * DIO/DIO-II space is too large to map in its entirety, instead devices  * are mapped into kernel virtual address space allocated from a range  * of EIOMAPSIZE pages (vmparam.h) starting at ``extiobase''.  */
end_comment

begin_define
define|#
directive|define
name|DIOBASE
value|(0x600000)
end_define

begin_define
define|#
directive|define
name|DIOTOP
value|(0x1000000)
end_define

begin_define
define|#
directive|define
name|DIOCSIZE
value|(0x10000)
end_define

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
comment|/*  * HP MMU  */
end_comment

begin_define
define|#
directive|define
name|MMUBASE
value|IIOPOFF(0x5F4000)
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

begin_comment
comment|/*  * 68851 and 68030 MMU  */
end_comment

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
comment|/*  * 68040 MMU  */
end_comment

begin_define
define|#
directive|define
name|MMU4_RES
value|0x001
end_define

begin_define
define|#
directive|define
name|MMU4_TTR
value|0x002
end_define

begin_define
define|#
directive|define
name|MMU4_WP
value|0x004
end_define

begin_define
define|#
directive|define
name|MMU4_MOD
value|0x010
end_define

begin_define
define|#
directive|define
name|MMU4_CMMASK
value|0x060
end_define

begin_define
define|#
directive|define
name|MMU4_SUP
value|0x080
end_define

begin_define
define|#
directive|define
name|MMU4_U0
value|0x100
end_define

begin_define
define|#
directive|define
name|MMU4_U1
value|0x200
end_define

begin_define
define|#
directive|define
name|MMU4_GLB
value|0x400
end_define

begin_define
define|#
directive|define
name|MMU4_BE
value|0x800
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

begin_comment
comment|/* 68040 cache control register */
end_comment

begin_define
define|#
directive|define
name|IC4_ENABLE
value|0x8000
end_define

begin_comment
comment|/* instruction cache enable bit */
end_comment

begin_define
define|#
directive|define
name|DC4_ENABLE
value|0x80000000
end_define

begin_comment
comment|/* data cache enable bit */
end_comment

begin_define
define|#
directive|define
name|CACHE4_ON
value|(IC4_ENABLE|DC4_ENABLE)
end_define

begin_define
define|#
directive|define
name|CACHE4_OFF
value|(0)
end_define

end_unit

