begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 John D. Polstra  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|_MPgetlock_edx
value|MPgetlock_edx
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
name|_MPrellock_edx
value|MPrellock_edx
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
name|_SMP_prvspace
value|SMP_prvspace
end_define

begin_define
define|#
directive|define
name|_SMPpt
value|SMPpt
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
name|_Xcpuast
value|Xcpuast
end_define

begin_define
define|#
directive|define
name|_Xcpucheckstate
value|Xcpucheckstate
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
name|_Xforward_irq
value|Xforward_irq
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
name|_Xintr9
value|Xintr9
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
name|_Xrendezvous
value|Xrendezvous
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
name|_Xxmm
value|Xxmm
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
name|_apic_imen
value|apic_imen
end_define

begin_define
define|#
directive|define
name|_apic_isrbit_location
value|apic_isrbit_location
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
name|_bintr
value|bintr
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
name|_bioscall_vector
value|bioscall_vector
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
name|_bootSTK
value|bootSTK
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
name|_btrap
value|btrap
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
name|_cam_imask
value|cam_imask
end_define

begin_define
define|#
directive|define
name|_checkstate_cpus
value|checkstate_cpus
end_define

begin_define
define|#
directive|define
name|_checkstate_cpustate
value|checkstate_cpustate
end_define

begin_define
define|#
directive|define
name|_checkstate_curproc
value|checkstate_curproc
end_define

begin_define
define|#
directive|define
name|_checkstate_need_ast
value|checkstate_need_ast
end_define

begin_define
define|#
directive|define
name|_checkstate_pc
value|checkstate_pc
end_define

begin_define
define|#
directive|define
name|_checkstate_pending_ast
value|checkstate_pending_ast
end_define

begin_define
define|#
directive|define
name|_checkstate_probed_cpus
value|checkstate_probed_cpus
end_define

begin_define
define|#
directive|define
name|_chooseproc
value|chooseproc
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
name|_cpu_fxsr
value|cpu_fxsr
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
name|_cpu_num_to_apic_id
value|cpu_num_to_apic_id
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
name|_doreti
value|doreti
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
name|_get_isrlock
value|get_isrlock
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
name|_idle
value|idle
end_define

begin_define
define|#
directive|define
name|_ihandlers
value|ihandlers
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
name|_in_vm86call
value|in_vm86call
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
name|_invltlb_ok
value|invltlb_ok
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
name|_kernbase
value|kernbase
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
name|_mi_startup
value|mi_startup
end_define

begin_define
define|#
directive|define
name|_microuptime
value|microuptime
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
name|_npx_intr
value|npx_intr
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
name|_szosigcode
value|szosigcode
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
name|_pc98_system_parameter
value|pc98_system_parameter
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
name|_proc0
value|proc0
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
name|_procrunnable
value|procrunnable
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
name|_smp_active
value|smp_active
end_define

begin_define
define|#
directive|define
name|_smp_rendezvous_action
value|smp_rendezvous_action
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
name|_svr4_sigcode
value|svr4_sigcode
end_define

begin_define
define|#
directive|define
name|_svr4_sys_context
value|svr4_sys_context
end_define

begin_define
define|#
directive|define
name|_svr4_szsigcode
value|svr4_szsigcode
end_define

begin_define
define|#
directive|define
name|_swi_dispatcher
value|swi_dispatcher
end_define

begin_define
define|#
directive|define
name|_swi_generic
value|swi_generic
end_define

begin_define
define|#
directive|define
name|_swi_null
value|swi_null
end_define

begin_define
define|#
directive|define
name|_swi_vm
value|swi_vm
end_define

begin_define
define|#
directive|define
name|_syscall2
value|syscall2
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
name|_ticks
value|ticks
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
name|_trap
value|trap
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
name|_vm86_prepcall
value|vm86_prepcall
end_define

begin_define
define|#
directive|define
name|_vm86pa
value|vm86pa
end_define

begin_define
define|#
directive|define
name|_vm86paddr
value|vm86paddr
end_define

begin_define
define|#
directive|define
name|_vm86pcb
value|vm86pcb
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP
argument_list|)
operator|||
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_define
define|#
directive|define
name|FS
parameter_list|(
name|x
parameter_list|)
value|%fs:gd_ ## x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FS
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_common_tss
value|FS(common_tss)
end_define

begin_define
define|#
directive|define
name|_common_tssd
value|FS(common_tssd)
end_define

begin_define
define|#
directive|define
name|_cpuid
value|FS(cpuid)
end_define

begin_define
define|#
directive|define
name|_cpu_lockid
value|FS(cpu_lockid)
end_define

begin_define
define|#
directive|define
name|_curpcb
value|FS(curpcb)
end_define

begin_define
define|#
directive|define
name|_curproc
value|FS(curproc)
end_define

begin_define
define|#
directive|define
name|_astpending
value|FS(astpending)
end_define

begin_define
define|#
directive|define
name|_currentldt
value|FS(currentldt)
end_define

begin_define
define|#
directive|define
name|_inside_intr
value|FS(inside_intr)
end_define

begin_define
define|#
directive|define
name|_npxproc
value|FS(npxproc)
end_define

begin_define
define|#
directive|define
name|_other_cpus
value|FS(other_cpus)
end_define

begin_define
define|#
directive|define
name|_prv_CADDR1
value|FS(prv_CADDR1)
end_define

begin_define
define|#
directive|define
name|_prv_CADDR2
value|FS(prv_CADDR2)
end_define

begin_define
define|#
directive|define
name|_prv_CADDR3
value|FS(prv_CADDR3)
end_define

begin_define
define|#
directive|define
name|_prv_CMAP1
value|FS(prv_CMAP1)
end_define

begin_define
define|#
directive|define
name|_prv_CMAP2
value|FS(prv_CMAP2)
end_define

begin_define
define|#
directive|define
name|_prv_CMAP3
value|FS(prv_CMAP3)
end_define

begin_define
define|#
directive|define
name|_prv_PADDR1
value|FS(prv_PADDR1)
end_define

begin_define
define|#
directive|define
name|_prv_PMAP1
value|FS(prv_PMAP1)
end_define

begin_define
define|#
directive|define
name|_ss_eflags
value|FS(ss_eflags)
end_define

begin_define
define|#
directive|define
name|_switchticks
value|FS(switchticks)
end_define

begin_define
define|#
directive|define
name|_switchtime
value|FS(switchtime)
end_define

begin_define
define|#
directive|define
name|_tss_gdt
value|FS(tss_gdt)
end_define

begin_define
define|#
directive|define
name|_idlestack
value|FS(idlestack)
end_define

begin_define
define|#
directive|define
name|_idlestack_top
value|FS(idlestack_top)
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
comment|/* !_MACHINE_ASNAMES_H_ */
end_comment

end_unit

