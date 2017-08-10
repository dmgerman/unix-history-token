begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2017 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_RISCVREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_RISCVREG_H_
end_define

begin_define
define|#
directive|define
name|EXCP_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|EXCP_MASK
value|(0xf<< EXCP_SHIFT)
end_define

begin_define
define|#
directive|define
name|EXCP_MISALIGNED_FETCH
value|0
end_define

begin_define
define|#
directive|define
name|EXCP_FAULT_FETCH
value|1
end_define

begin_define
define|#
directive|define
name|EXCP_ILLEGAL_INSTRUCTION
value|2
end_define

begin_define
define|#
directive|define
name|EXCP_BREAKPOINT
value|3
end_define

begin_define
define|#
directive|define
name|EXCP_MISALIGNED_LOAD
value|4
end_define

begin_define
define|#
directive|define
name|EXCP_FAULT_LOAD
value|5
end_define

begin_define
define|#
directive|define
name|EXCP_MISALIGNED_STORE
value|6
end_define

begin_define
define|#
directive|define
name|EXCP_FAULT_STORE
value|7
end_define

begin_define
define|#
directive|define
name|EXCP_USER_ECALL
value|8
end_define

begin_define
define|#
directive|define
name|EXCP_SUPERVISOR_ECALL
value|9
end_define

begin_define
define|#
directive|define
name|EXCP_HYPERVISOR_ECALL
value|10
end_define

begin_define
define|#
directive|define
name|EXCP_MACHINE_ECALL
value|11
end_define

begin_define
define|#
directive|define
name|EXCP_INST_PAGE_FAULT
value|12
end_define

begin_define
define|#
directive|define
name|EXCP_LOAD_PAGE_FAULT
value|13
end_define

begin_define
define|#
directive|define
name|EXCP_STORE_PAGE_FAULT
value|15
end_define

begin_define
define|#
directive|define
name|EXCP_INTR
value|(1ul<< 63)
end_define

begin_define
define|#
directive|define
name|SSTATUS_UIE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SSTATUS_SIE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SSTATUS_UPIE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SSTATUS_SPIE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SSTATUS_SPIE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|SSTATUS_SPP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|SSTATUS_SPP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_OFF
value|(0x0<< SSTATUS_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_INITIAL
value|(0x1<< SSTATUS_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_CLEAN
value|(0x2<< SSTATUS_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_DIRTY
value|(0x3<< SSTATUS_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_FS_MASK
value|(0x3<< SSTATUS_FS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_XS_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|SSTATUS_XS_MASK
value|(0x3<< SSTATUS_XS_SHIFT)
end_define

begin_define
define|#
directive|define
name|SSTATUS_SUM
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SSTATUS32_SD
value|(1<< 63)
end_define

begin_define
define|#
directive|define
name|SSTATUS64_SD
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|MSTATUS_UIE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MSTATUS_SIE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MSTATUS_HIE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MSTATUS_MIE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MSTATUS_UPIE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MSTATUS_SPIE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MSTATUS_SPIE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|MSTATUS_HPIE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPIE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPIE_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MSTATUS_SPP
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MSTATUS_SPP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MSTATUS_HPP_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MSTATUS_HPP_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPP_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPP_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|MSTATUS_FS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MSTATUS_FS_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|MSTATUS_XS_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|MSTATUS_XS_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPRV
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MSTATUS_PUM
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_MBARE
value|0
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_MBB
value|1
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_MBBID
value|2
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SV32
value|8
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SV39
value|9
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SV48
value|10
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SV57
value|11
end_define

begin_define
define|#
directive|define
name|MSTATUS_VM_SV64
value|12
end_define

begin_define
define|#
directive|define
name|MSTATUS32_SD
value|(1<< 63)
end_define

begin_define
define|#
directive|define
name|MSTATUS64_SD
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|MSTATUS_PRV_U
value|0
end_define

begin_comment
comment|/* user */
end_comment

begin_define
define|#
directive|define
name|MSTATUS_PRV_S
value|1
end_define

begin_comment
comment|/* supervisor */
end_comment

begin_define
define|#
directive|define
name|MSTATUS_PRV_H
value|2
end_define

begin_comment
comment|/* hypervisor */
end_comment

begin_define
define|#
directive|define
name|MSTATUS_PRV_M
value|3
end_define

begin_comment
comment|/* machine */
end_comment

begin_define
define|#
directive|define
name|MIE_USIE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MIE_SSIE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MIE_HSIE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MIE_MSIE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MIE_UTIE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MIE_STIE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MIE_HTIE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MIE_MTIE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MIP_USIP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MIP_SSIP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MIP_HSIP
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MIP_MSIP
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MIP_UTIP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MIP_STIP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MIP_HTIP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MIP_MTIP
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|SIE_USIE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SIE_SSIE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SIE_UTIE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|SIE_STIE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MIP_SEIP
value|(1<< 9)
end_define

begin_comment
comment|/* Note: sip register has no SIP_STIP bit in Spike simulator */
end_comment

begin_define
define|#
directive|define
name|SIP_SSIP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|SIP_STIP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|SATP_PPN_S
value|0
end_define

begin_define
define|#
directive|define
name|SATP_PPN_M
value|(0xfffffffffff<< SATP_PPN_S)
end_define

begin_define
define|#
directive|define
name|SATP_ASID_S
value|44
end_define

begin_define
define|#
directive|define
name|SATP_ASID_M
value|(0xffff<< SATP_ASID_S)
end_define

begin_define
define|#
directive|define
name|SATP_MODE_S
value|60
end_define

begin_define
define|#
directive|define
name|SATP_MODE_M
value|(0xf<< SATP_MODE_S)
end_define

begin_define
define|#
directive|define
name|SATP_MODE_SV39
value|(8ULL<< SATP_MODE_S)
end_define

begin_define
define|#
directive|define
name|SATP_MODE_SV48
value|(9ULL<< SATP_MODE_S)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* lowRISC TODO */
end_comment

begin_define
define|#
directive|define
name|NCSRS
value|4096
end_define

begin_define
define|#
directive|define
name|CSR_IPI
value|0x783
end_define

begin_define
define|#
directive|define
name|CSR_IO_IRQ
value|0x7c0
end_define

begin_comment
comment|/* lowRISC only? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|XLEN
value|8
end_define

begin_define
define|#
directive|define
name|INSN_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|RISCV_INSN_NOP
value|0x00000013
end_define

begin_define
define|#
directive|define
name|RISCV_INSN_BREAK
value|0x00100073
end_define

begin_define
define|#
directive|define
name|RISCV_INSN_RET
value|0x00008067
end_define

begin_define
define|#
directive|define
name|CSR_ZIMM
parameter_list|(
name|val
parameter_list|)
define|\
value|(__builtin_constant_p(val)&& ((u_long)(val)< 32))
end_define

begin_define
define|#
directive|define
name|csr_swap
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|({	if (CSR_ZIMM(val))  						\ 		__asm __volatile("csrrwi %0, " #csr ", %1"		\ 				: "=r" (val) : "i" (val));		\ 	else 								\ 		__asm __volatile("csrrw %0, " #csr ", %1"		\ 				: "=r" (val) : "r" (val));		\ 	val;								\ })
end_define

begin_define
define|#
directive|define
name|csr_write
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|({	if (CSR_ZIMM(val)) 						\ 		__asm __volatile("csrwi " #csr ", %0" :: "i" (val));	\ 	else 								\ 		__asm __volatile("csrw " #csr ", %0" ::  "r" (val));	\ })
end_define

begin_define
define|#
directive|define
name|csr_set
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|({	if (CSR_ZIMM(val)) 						\ 		__asm __volatile("csrsi " #csr ", %0" :: "i" (val));	\ 	else								\ 		__asm __volatile("csrs " #csr ", %0" :: "r" (val));	\ })
end_define

begin_define
define|#
directive|define
name|csr_clear
parameter_list|(
name|csr
parameter_list|,
name|val
parameter_list|)
define|\
value|({	if (CSR_ZIMM(val))						\ 		__asm __volatile("csrci " #csr ", %0" :: "i" (val));	\ 	else								\ 		__asm __volatile("csrc " #csr ", %0" :: "r" (val));	\ })
end_define

begin_define
define|#
directive|define
name|csr_read
parameter_list|(
name|csr
parameter_list|)
define|\
value|({	u_long val;							\ 	__asm __volatile("csrr %0, " #csr : "=r" (val));		\ 	val;								\ })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_RISCVREG_H_ */
end_comment

end_unit

