begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id: asnames.h,v 1.8 1997/09/13 16:00:30 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ASNAMES_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ASNAMES_H_
end_define

begin_comment
comment|/*  * This file is used by the kernel assembly language sources to provide  * the proper mapping between the global names used in assembly language  * code and the corresponding C symbols.  By convention, all C symbols  * that are referenced from assembly language are prefixed with `_'.  * That happens to be the same prefix that the a.out compiler attaches  * to each C symbol.  *  * When using the ELF compiler, C symbols are identical to the corresponding  * assembly language symbols.  Thus the extra underscores cause problems.  * The defines in this file map the underscore names back to the proper  * unadorned names.  *  * Every global symbol that is referenced from both C source and assembly  * language source must have an entry in this file, or the kernel will  * not build properly using the ELF compiler.  *  * This file is included by<machine/asmacros.h>, and it is OK to rely  * on that.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ELF__
end_ifdef

begin_define
define|#
directive|define
name|_APTD
value|APTD
end_define

begin_define
define|#
directive|define
name|_APTDpde
value|APTDpde
end_define

begin_define
define|#
directive|define
name|_APTmap
value|APTmap
end_define

begin_define
define|#
directive|define
name|_CONST_QNaN
value|CONST_QNaN
end_define

begin_define
define|#
directive|define
name|_IdlePTD
value|IdlePTD
end_define

begin_define
define|#
directive|define
name|_KPTphys
value|KPTphys
end_define

begin_define
define|#
directive|define
name|_MP_GDT
value|MP_GDT
end_define

begin_define
define|#
directive|define
name|_MPgetlock
value|MPgetlock
end_define

begin_define
define|#
directive|define
name|_MPrellock
value|MPrellock
end_define

begin_define
define|#
directive|define
name|_MPtrylock
value|MPtrylock
end_define

begin_define
define|#
directive|define
name|_PTD
value|PTD
end_define

begin_define
define|#
directive|define
name|_PTDpde
value|PTDpde
end_define

begin_define
define|#
directive|define
name|_PTmap
value|PTmap
end_define

begin_define
define|#
directive|define
name|_SMP_ioapic
value|SMP_ioapic
end_define

begin_define
define|#
directive|define
name|_SMP_prvpt
value|SMP_prvpt
end_define

begin_define
define|#
directive|define
name|_Xalign
value|Xalign
end_define

begin_define
define|#
directive|define
name|_Xbnd
value|Xbnd
end_define

begin_define
define|#
directive|define
name|_Xbpt
value|Xbpt
end_define

begin_define
define|#
directive|define
name|_Xcpustop
value|Xcpustop
end_define

begin_define
define|#
directive|define
name|_Xdbg
value|Xdbg
end_define

begin_define
define|#
directive|define
name|_Xdiv
value|Xdiv
end_define

begin_define
define|#
directive|define
name|_Xdna
value|Xdna
end_define

begin_define
define|#
directive|define
name|_Xfastintr0
value|Xfastintr0
end_define

begin_define
define|#
directive|define
name|_Xfastintr1
value|Xfastintr1
end_define

begin_define
define|#
directive|define
name|_Xfastintr10
value|Xfastintr10
end_define

begin_define
define|#
directive|define
name|_Xfastintr11
value|Xfastintr11
end_define

begin_define
define|#
directive|define
name|_Xfastintr12
value|Xfastintr12
end_define

begin_define
define|#
directive|define
name|_Xfastintr13
value|Xfastintr13
end_define

begin_define
define|#
directive|define
name|_Xfastintr14
value|Xfastintr14
end_define

begin_define
define|#
directive|define
name|_Xfastintr15
value|Xfastintr15
end_define

begin_define
define|#
directive|define
name|_Xfastintr16
value|Xfastintr16
end_define

begin_define
define|#
directive|define
name|_Xfastintr17
value|Xfastintr17
end_define

begin_define
define|#
directive|define
name|_Xfastintr18
value|Xfastintr18
end_define

begin_define
define|#
directive|define
name|_Xfastintr19
value|Xfastintr19
end_define

begin_define
define|#
directive|define
name|_Xfastintr2
value|Xfastintr2
end_define

begin_define
define|#
directive|define
name|_Xfastintr20
value|Xfastintr20
end_define

begin_define
define|#
directive|define
name|_Xfastintr21
value|Xfastintr21
end_define

begin_define
define|#
directive|define
name|_Xfastintr22
value|Xfastintr22
end_define

begin_define
define|#
directive|define
name|_Xfastintr23
value|Xfastintr23
end_define

begin_define
define|#
directive|define
name|_Xfastintr3
value|Xfastintr3
end_define

begin_define
define|#
directive|define
name|_Xfastintr4
value|Xfastintr4
end_define

begin_define
define|#
directive|define
name|_Xfastintr5
value|Xfastintr5
end_define

begin_define
define|#
directive|define
name|_Xfastintr6
value|Xfastintr6
end_define

begin_define
define|#
directive|define
name|_Xfastintr7
value|Xfastintr7
end_define

begin_define
define|#
directive|define
name|_Xfastintr8
value|Xfastintr8
end_define

begin_define
define|#
directive|define
name|_Xfastintr9
value|Xfastintr9
end_define

begin_define
define|#
directive|define
name|_Xfpu
value|Xfpu
end_define

begin_define
define|#
directive|define
name|_Xfpusegm
value|Xfpusegm
end_define

begin_define
define|#
directive|define
name|_Xill
value|Xill
end_define

begin_define
define|#
directive|define
name|_Xint0x80_syscall
value|Xint0x80_syscall
end_define

begin_define
define|#
directive|define
name|_Xintr0
value|Xintr0
end_define

begin_define
define|#
directive|define
name|_Xintr1
value|Xintr1
end_define

begin_define
define|#
directive|define
name|_Xintr10
value|Xintr10
end_define

begin_define
define|#
directive|define
name|_Xintr11
value|Xintr11
end_define

begin_define
define|#
directive|define
name|_Xintr12
value|Xintr12
end_define

begin_define
define|#
directive|define
name|_Xintr13
value|Xintr13
end_define

begin_define
define|#
directive|define
name|_Xintr14
value|Xintr14
end_define

begin_define
define|#
directive|define
name|_Xintr15
value|Xintr15
end_define

begin_define
define|#
directive|define
name|_Xintr16
value|Xintr16
end_define

begin_define
define|#
directive|define
name|_Xintr17
value|Xintr17
end_define

begin_define
define|#
directive|define
name|_Xintr18
value|Xintr18
end_define

begin_define
define|#
directive|define
name|_Xintr19
value|Xintr19
end_define

begin_define
define|#
directive|define
name|_Xintr2
value|Xintr2
end_define

begin_define
define|#
directive|define
name|_Xintr20
value|Xintr20
end_define

begin_define
define|#
directive|define
name|_Xintr21
value|Xintr21
end_define

begin_define
define|#
directive|define
name|_Xintr22
value|Xintr22
end_define

begin_define
define|#
directive|define
name|_Xintr23
value|Xintr23
end_define

begin_define
define|#
directive|define
name|_Xintr3
value|Xintr3
end_define

begin_define
define|#
directive|define
name|_Xintr4
value|Xintr4
end_define

begin_define
define|#
directive|define
name|_Xintr5
value|Xintr5
end_define

begin_define
define|#
directive|define
name|_Xintr6
value|Xintr6
end_define

begin_define
define|#
directive|define
name|_Xintr7
value|Xintr7
end_define

begin_define
define|#
directive|define
name|_Xintr8
value|Xintr8
end_define

begin_define
define|#
directive|define
name|_Xintr8254
value|Xintr8254
end_define

begin_define
define|#
directive|define
name|_Xintr9
value|Xintr9
end_define

begin_define
define|#
directive|define
name|_XintrRTC
value|XintrRTC
end_define

begin_define
define|#
directive|define
name|_Xinvltlb
value|Xinvltlb
end_define

begin_define
define|#
directive|define
name|_Xmchk
value|Xmchk
end_define

begin_define
define|#
directive|define
name|_Xmissing
value|Xmissing
end_define

begin_define
define|#
directive|define
name|_Xnmi
value|Xnmi
end_define

begin_define
define|#
directive|define
name|_Xofl
value|Xofl
end_define

begin_define
define|#
directive|define
name|_Xpage
value|Xpage
end_define

begin_define
define|#
directive|define
name|_Xprot
value|Xprot
end_define

begin_define
define|#
directive|define
name|_Xrsvd
value|Xrsvd
end_define

begin_define
define|#
directive|define
name|_Xspuriousint
value|Xspuriousint
end_define

begin_define
define|#
directive|define
name|_Xstk
value|Xstk
end_define

begin_define
define|#
directive|define
name|_Xsyscall
value|Xsyscall
end_define

begin_define
define|#
directive|define
name|_Xtss
value|Xtss
end_define

begin_define
define|#
directive|define
name|__default_ldt
value|_default_ldt
end_define

begin_define
define|#
directive|define
name|__ucodesel
value|_ucodesel
end_define

begin_define
define|#
directive|define
name|__udatasel
value|_udatasel
end_define

begin_define
define|#
directive|define
name|_alltraps
value|alltraps
end_define

begin_define
define|#
directive|define
name|_ap_init
value|ap_init
end_define

begin_define
define|#
directive|define
name|_apic_base
value|apic_base
end_define

begin_define
define|#
directive|define
name|_apic_id_to_logical
value|apic_id_to_logical
end_define

begin_define
define|#
directive|define
name|_apic_imen
value|apic_imen
end_define

begin_define
define|#
directive|define
name|_apic_pin_trigger
value|apic_pin_trigger
end_define

begin_define
define|#
directive|define
name|_apm_addr
value|apm_addr
end_define

begin_define
define|#
directive|define
name|_apm_bios_call
value|apm_bios_call
end_define

begin_define
define|#
directive|define
name|_apm_cs16_base
value|apm_cs16_base
end_define

begin_define
define|#
directive|define
name|_apm_cs32_base
value|apm_cs32_base
end_define

begin_define
define|#
directive|define
name|_apm_cs_entry
value|apm_cs_entry
end_define

begin_define
define|#
directive|define
name|_apm_cs_limit
value|apm_cs_limit
end_define

begin_define
define|#
directive|define
name|_apm_current_gdt_pdesc
value|apm_current_gdt_pdesc
end_define

begin_define
define|#
directive|define
name|_apm_ds_base
value|apm_ds_base
end_define

begin_define
define|#
directive|define
name|_apm_ds_limit
value|apm_ds_limit
end_define

begin_define
define|#
directive|define
name|_apm_flags
value|apm_flags
end_define

begin_define
define|#
directive|define
name|_apm_init_image
value|apm_init_image
end_define

begin_define
define|#
directive|define
name|_apm_init_image_size
value|apm_init_image_size
end_define

begin_define
define|#
directive|define
name|_apm_setup
value|apm_setup
end_define

begin_define
define|#
directive|define
name|_apm_version
value|apm_version
end_define

begin_define
define|#
directive|define
name|_arith_invalid
value|arith_invalid
end_define

begin_define
define|#
directive|define
name|_arith_overflow
value|arith_overflow
end_define

begin_define
define|#
directive|define
name|_arith_underflow
value|arith_underflow
end_define

begin_define
define|#
directive|define
name|_bcopy
value|bcopy
end_define

begin_define
define|#
directive|define
name|_bcopy_vector
value|bcopy_vector
end_define

begin_define
define|#
directive|define
name|_bigJump
value|bigJump
end_define

begin_define
define|#
directive|define
name|_bio_imask
value|bio_imask
end_define

begin_define
define|#
directive|define
name|_bluetrap
value|bluetrap
end_define

begin_define
define|#
directive|define
name|_bootCodeSeg
value|bootCodeSeg
end_define

begin_define
define|#
directive|define
name|_bootDataSeg
value|bootDataSeg
end_define

begin_define
define|#
directive|define
name|_bootMP
value|bootMP
end_define

begin_define
define|#
directive|define
name|_bootMP_size
value|bootMP_size
end_define

begin_define
define|#
directive|define
name|_bootPTD
value|bootPTD
end_define

begin_define
define|#
directive|define
name|_boot_get_mplock
value|boot_get_mplock
end_define

begin_define
define|#
directive|define
name|_bootdev
value|bootdev
end_define

begin_define
define|#
directive|define
name|_boothowto
value|boothowto
end_define

begin_define
define|#
directive|define
name|_bootinfo
value|bootinfo
end_define

begin_define
define|#
directive|define
name|_bootstrap_gdt
value|bootstrap_gdt
end_define

begin_define
define|#
directive|define
name|_bzero
value|bzero
end_define

begin_define
define|#
directive|define
name|_clock_lock
value|clock_lock
end_define

begin_define
define|#
directive|define
name|_cnt
value|cnt
end_define

begin_define
define|#
directive|define
name|_common_tss
value|common_tss
end_define

begin_define
define|#
directive|define
name|_common_tssd
value|common_tssd
end_define

begin_define
define|#
directive|define
name|_copyin_vector
value|copyin_vector
end_define

begin_define
define|#
directive|define
name|_copyout_vector
value|copyout_vector
end_define

begin_define
define|#
directive|define
name|_cpl
value|cpl
end_define

begin_define
define|#
directive|define
name|_cpl_lock
value|cpl_lock
end_define

begin_define
define|#
directive|define
name|_cpu
value|cpu
end_define

begin_define
define|#
directive|define
name|_cpu0prvpage
value|cpu0prvpage
end_define

begin_define
define|#
directive|define
name|_cpu0prvpt
value|cpu0prvpt
end_define

begin_define
define|#
directive|define
name|_cpu_apic_versions
value|cpu_apic_versions
end_define

begin_define
define|#
directive|define
name|_cpu_class
value|cpu_class
end_define

begin_define
define|#
directive|define
name|_cpu_feature
value|cpu_feature
end_define

begin_define
define|#
directive|define
name|_cpu_high
value|cpu_high
end_define

begin_define
define|#
directive|define
name|_cpu_id
value|cpu_id
end_define

begin_define
define|#
directive|define
name|_cpu_switch
value|cpu_switch
end_define

begin_define
define|#
directive|define
name|_cpu_vendor
value|cpu_vendor
end_define

begin_define
define|#
directive|define
name|_cpuid
value|cpuid
end_define

begin_define
define|#
directive|define
name|_curpcb
value|curpcb
end_define

begin_define
define|#
directive|define
name|_curproc
value|curproc
end_define

begin_define
define|#
directive|define
name|_currentldt
value|currentldt
end_define

begin_define
define|#
directive|define
name|_cypoll
value|cypoll
end_define

begin_define
define|#
directive|define
name|_default_halt
value|default_halt
end_define

begin_define
define|#
directive|define
name|_denormal_operand
value|denormal_operand
end_define

begin_define
define|#
directive|define
name|_div_small
value|div_small
end_define

begin_define
define|#
directive|define
name|_divide_by_zero
value|divide_by_zero
end_define

begin_define
define|#
directive|define
name|_divide_kernel
value|divide_kernel
end_define

begin_define
define|#
directive|define
name|_do_page_zero_idle
value|do_page_zero_idle
end_define

begin_define
define|#
directive|define
name|_edata
value|edata
end_define

begin_define
define|#
directive|define
name|_eintrcnt
value|eintrcnt
end_define

begin_define
define|#
directive|define
name|_eintrnames
value|eintrnames
end_define

begin_define
define|#
directive|define
name|_end
value|end
end_define

begin_define
define|#
directive|define
name|_etext
value|etext
end_define

begin_define
define|#
directive|define
name|_exception
value|exception
end_define

begin_define
define|#
directive|define
name|_fast_intr_lock
value|fast_intr_lock
end_define

begin_define
define|#
directive|define
name|_fastmove
value|fastmove
end_define

begin_define
define|#
directive|define
name|_gdt
value|gdt
end_define

begin_define
define|#
directive|define
name|_generic_bcopy
value|generic_bcopy
end_define

begin_define
define|#
directive|define
name|_generic_bzero
value|generic_bzero
end_define

begin_define
define|#
directive|define
name|_generic_copyin
value|generic_copyin
end_define

begin_define
define|#
directive|define
name|_generic_copyout
value|generic_copyout
end_define

begin_define
define|#
directive|define
name|_get_align_lock
value|get_align_lock
end_define

begin_define
define|#
directive|define
name|_get_altsyscall_lock
value|get_altsyscall_lock
end_define

begin_define
define|#
directive|define
name|_get_fpu_lock
value|get_fpu_lock
end_define

begin_define
define|#
directive|define
name|_get_mplock
value|get_mplock
end_define

begin_define
define|#
directive|define
name|_get_syscall_lock
value|get_syscall_lock
end_define

begin_define
define|#
directive|define
name|_i586_ctr_bias
value|i586_ctr_bias
end_define

begin_define
define|#
directive|define
name|_i586_ctr_freq
value|i586_ctr_freq
end_define

begin_define
define|#
directive|define
name|_i586_ctr_multiplier
value|i586_ctr_multiplier
end_define

begin_define
define|#
directive|define
name|_idqs
value|idqs
end_define

begin_define
define|#
directive|define
name|_imen
value|imen
end_define

begin_define
define|#
directive|define
name|_imen_lock
value|imen_lock
end_define

begin_define
define|#
directive|define
name|_init386
value|init386
end_define

begin_define
define|#
directive|define
name|_init_secondary
value|init_secondary
end_define

begin_define
define|#
directive|define
name|_inside_intr
value|inside_intr
end_define

begin_define
define|#
directive|define
name|_intr_countp
value|intr_countp
end_define

begin_define
define|#
directive|define
name|_intr_handler
value|intr_handler
end_define

begin_define
define|#
directive|define
name|_intr_mask
value|intr_mask
end_define

begin_define
define|#
directive|define
name|_intr_nesting_level
value|intr_nesting_level
end_define

begin_define
define|#
directive|define
name|_intr_unit
value|intr_unit
end_define

begin_define
define|#
directive|define
name|_intrcnt
value|intrcnt
end_define

begin_define
define|#
directive|define
name|_intrnames
value|intrnames
end_define

begin_define
define|#
directive|define
name|_ioapic
value|ioapic
end_define

begin_define
define|#
directive|define
name|_ipending
value|ipending
end_define

begin_define
define|#
directive|define
name|_isr_lock
value|isr_lock
end_define

begin_define
define|#
directive|define
name|_ivectors
value|ivectors
end_define

begin_define
define|#
directive|define
name|_kernelname
value|kernelname
end_define

begin_define
define|#
directive|define
name|_kstack
value|kstack
end_define

begin_define
define|#
directive|define
name|_lapic
value|lapic
end_define

begin_define
define|#
directive|define
name|_linux_sigcode
value|linux_sigcode
end_define

begin_define
define|#
directive|define
name|_linux_szsigcode
value|linux_szsigcode
end_define

begin_define
define|#
directive|define
name|_main
value|main
end_define

begin_define
define|#
directive|define
name|_mask8254
value|mask8254
end_define

begin_define
define|#
directive|define
name|_maskRTC
value|maskRTC
end_define

begin_define
define|#
directive|define
name|_microtime
value|microtime
end_define

begin_define
define|#
directive|define
name|_mp_gdtbase
value|mp_gdtbase
end_define

begin_define
define|#
directive|define
name|_mp_lock
value|mp_lock
end_define

begin_define
define|#
directive|define
name|_mp_ncpus
value|mp_ncpus
end_define

begin_define
define|#
directive|define
name|_mul64
value|mul64
end_define

begin_define
define|#
directive|define
name|_my_idlePTD
value|my_idlePTD
end_define

begin_define
define|#
directive|define
name|_my_tr
value|my_tr
end_define

begin_define
define|#
directive|define
name|_net_imask
value|net_imask
end_define

begin_define
define|#
directive|define
name|_netisr
value|netisr
end_define

begin_define
define|#
directive|define
name|_netisrs
value|netisrs
end_define

begin_define
define|#
directive|define
name|_nfs_diskless
value|nfs_diskless
end_define

begin_define
define|#
directive|define
name|_nfs_diskless_valid
value|nfs_diskless_valid
end_define

begin_define
define|#
directive|define
name|_normalize
value|normalize
end_define

begin_define
define|#
directive|define
name|_normalize_nuo
value|normalize_nuo
end_define

begin_define
define|#
directive|define
name|_npx_intrs_while_probing
value|npx_intrs_while_probing
end_define

begin_define
define|#
directive|define
name|_npx_traps_while_probing
value|npx_traps_while_probing
end_define

begin_define
define|#
directive|define
name|_npxintr
value|npxintr
end_define

begin_define
define|#
directive|define
name|_npxproc
value|npxproc
end_define

begin_define
define|#
directive|define
name|_npxsave
value|npxsave
end_define

begin_define
define|#
directive|define
name|_other_cpus
value|other_cpus
end_define

begin_define
define|#
directive|define
name|_ovbcopy_vector
value|ovbcopy_vector
end_define

begin_define
define|#
directive|define
name|_panic
value|panic
end_define

begin_define
define|#
directive|define
name|_poly_div16
value|poly_div16
end_define

begin_define
define|#
directive|define
name|_poly_div2
value|poly_div2
end_define

begin_define
define|#
directive|define
name|_poly_div4
value|poly_div4
end_define

begin_define
define|#
directive|define
name|_polynomial
value|polynomial
end_define

begin_define
define|#
directive|define
name|_private_tss
value|private_tss
end_define

begin_define
define|#
directive|define
name|_probeintr
value|probeintr
end_define

begin_define
define|#
directive|define
name|_probetrap
value|probetrap
end_define

begin_define
define|#
directive|define
name|_proc0paddr
value|proc0paddr
end_define

begin_define
define|#
directive|define
name|_prv_CMAP1
value|prv_CMAP1
end_define

begin_define
define|#
directive|define
name|_prv_CMAP2
value|prv_CMAP2
end_define

begin_define
define|#
directive|define
name|_prv_CMAP3
value|prv_CMAP3
end_define

begin_define
define|#
directive|define
name|_prv_CPAGE1
value|prv_CPAGE1
end_define

begin_define
define|#
directive|define
name|_prv_CPAGE2
value|prv_CPAGE2
end_define

begin_define
define|#
directive|define
name|_prv_CPAGE3
value|prv_CPAGE3
end_define

begin_define
define|#
directive|define
name|_qs
value|qs
end_define

begin_define
define|#
directive|define
name|_rcpoll
value|rcpoll
end_define

begin_define
define|#
directive|define
name|_real_2op_NaN
value|real_2op_NaN
end_define

begin_define
define|#
directive|define
name|_reg_div
value|reg_div
end_define

begin_define
define|#
directive|define
name|_reg_u_add
value|reg_u_add
end_define

begin_define
define|#
directive|define
name|_reg_u_div
value|reg_u_div
end_define

begin_define
define|#
directive|define
name|_reg_u_mul
value|reg_u_mul
end_define

begin_define
define|#
directive|define
name|_reg_u_sub
value|reg_u_sub
end_define

begin_define
define|#
directive|define
name|_rel_mplock
value|rel_mplock
end_define

begin_define
define|#
directive|define
name|_round_reg
value|round_reg
end_define

begin_define
define|#
directive|define
name|_rtqs
value|rtqs
end_define

begin_define
define|#
directive|define
name|_runtime
value|runtime
end_define

begin_define
define|#
directive|define
name|_s_lock
value|s_lock
end_define

begin_define
define|#
directive|define
name|_s_unlock
value|s_unlock
end_define

begin_define
define|#
directive|define
name|_secondary_main
value|secondary_main
end_define

begin_define
define|#
directive|define
name|_set_precision_flag_down
value|set_precision_flag_down
end_define

begin_define
define|#
directive|define
name|_set_precision_flag_up
value|set_precision_flag_up
end_define

begin_define
define|#
directive|define
name|_set_user_ldt
value|set_user_ldt
end_define

begin_define
define|#
directive|define
name|_shrx
value|shrx
end_define

begin_define
define|#
directive|define
name|_shrxs
value|shrxs
end_define

begin_define
define|#
directive|define
name|_sigcode
value|sigcode
end_define

begin_define
define|#
directive|define
name|_siopoll
value|siopoll
end_define

begin_define
define|#
directive|define
name|_smp_active
value|smp_active
end_define

begin_define
define|#
directive|define
name|_soft_imask
value|soft_imask
end_define

begin_define
define|#
directive|define
name|_softclock
value|softclock
end_define

begin_define
define|#
directive|define
name|_softnet_imask
value|softnet_imask
end_define

begin_define
define|#
directive|define
name|_softtty_imask
value|softtty_imask
end_define

begin_define
define|#
directive|define
name|_spl0
value|spl0
end_define

begin_define
define|#
directive|define
name|_splz
value|splz
end_define

begin_define
define|#
directive|define
name|_ss_lock
value|ss_lock
end_define

begin_define
define|#
directive|define
name|_ss_unlock
value|ss_unlock
end_define

begin_define
define|#
directive|define
name|_started_cpus
value|started_cpus
end_define

begin_define
define|#
directive|define
name|_stopped_cpus
value|stopped_cpus
end_define

begin_define
define|#
directive|define
name|_syscall
value|syscall
end_define

begin_define
define|#
directive|define
name|_szsigcode
value|szsigcode
end_define

begin_define
define|#
directive|define
name|_time
value|time
end_define

begin_define
define|#
directive|define
name|_timer0_max_count
value|timer0_max_count
end_define

begin_define
define|#
directive|define
name|_timer0_overflow_threshold
value|timer0_overflow_threshold
end_define

begin_define
define|#
directive|define
name|_timer0_prescaler_count
value|timer0_prescaler_count
end_define

begin_define
define|#
directive|define
name|_trap
value|trap
end_define

begin_define
define|#
directive|define
name|_trap_by_wrmsr
value|trap_by_wrmsr
end_define

begin_define
define|#
directive|define
name|_trapwrite
value|trapwrite
end_define

begin_define
define|#
directive|define
name|_tty_imask
value|tty_imask
end_define

begin_define
define|#
directive|define
name|_userconfig_from_boot
value|userconfig_from_boot
end_define

begin_define
define|#
directive|define
name|_vec
value|vec
end_define

begin_define
define|#
directive|define
name|_vec8254
value|vec8254
end_define

begin_define
define|#
directive|define
name|_vecRTC
value|vecRTC
end_define

begin_define
define|#
directive|define
name|_vm_page_zero_idle
value|vm_page_zero_idle
end_define

begin_define
define|#
directive|define
name|_want_resched
value|want_resched
end_define

begin_define
define|#
directive|define
name|_whichidqs
value|whichidqs
end_define

begin_define
define|#
directive|define
name|_whichqs
value|whichqs
end_define

begin_define
define|#
directive|define
name|_whichrtqs
value|whichrtqs
end_define

begin_define
define|#
directive|define
name|_wm_sqrt
value|wm_sqrt
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ELF__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ASNAMES_H_ */
end_comment

end_unit

