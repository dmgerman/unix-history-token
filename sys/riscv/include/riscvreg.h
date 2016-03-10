begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* Machine mode requests */
end_comment

begin_define
define|#
directive|define
name|ECALL_MTIMECMP
value|0x01
end_define

begin_define
define|#
directive|define
name|ECALL_CLEAR_PENDING
value|0x02
end_define

begin_define
define|#
directive|define
name|ECALL_HTIF_CMD
value|0x03
end_define

begin_define
define|#
directive|define
name|ECALL_HTIF_GET_ENTRY
value|0x04
end_define

begin_define
define|#
directive|define
name|ECALL_MCPUID_GET
value|0x05
end_define

begin_define
define|#
directive|define
name|ECALL_MIMPID_GET
value|0x06
end_define

begin_define
define|#
directive|define
name|ECALL_SEND_IPI
value|0x07
end_define

begin_define
define|#
directive|define
name|ECALL_CLEAR_IPI
value|0x08
end_define

begin_define
define|#
directive|define
name|ECALL_HTIF_LOWPUTC
value|0x09
end_define

begin_define
define|#
directive|define
name|ECALL_MIE_SET
value|0x10
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
name|EXCP_INSTR_ADDR_MISALIGNED
value|0
end_define

begin_define
define|#
directive|define
name|EXCP_INSTR_ACCESS_FAULT
value|1
end_define

begin_define
define|#
directive|define
name|EXCP_INSTR_ILLEGAL
value|2
end_define

begin_define
define|#
directive|define
name|EXCP_INSTR_BREAKPOINT
value|3
end_define

begin_define
define|#
directive|define
name|EXCP_LOAD_ADDR_MISALIGNED
value|4
end_define

begin_define
define|#
directive|define
name|EXCP_LOAD_ACCESS_FAULT
value|5
end_define

begin_define
define|#
directive|define
name|EXCP_STORE_ADDR_MISALIGNED
value|6
end_define

begin_define
define|#
directive|define
name|EXCP_STORE_ACCESS_FAULT
value|7
end_define

begin_define
define|#
directive|define
name|EXCP_UMODE_ENV_CALL
value|8
end_define

begin_define
define|#
directive|define
name|EXCP_SMODE_ENV_CALL
value|9
end_define

begin_define
define|#
directive|define
name|EXCP_HMODE_ENV_CALL
value|10
end_define

begin_define
define|#
directive|define
name|EXCP_MMODE_ENV_CALL
value|11
end_define

begin_define
define|#
directive|define
name|EXCP_INTR
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|EXCP_INTR_SOFTWARE
value|0
end_define

begin_define
define|#
directive|define
name|EXCP_INTR_TIMER
value|1
end_define

begin_define
define|#
directive|define
name|EXCP_INTR_HTIF
value|2
end_define

begin_define
define|#
directive|define
name|SSTATUS_IE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SSTATUS_PIE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SSTATUS_PS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MSTATUS_MPRV
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MSTATUS_PRV_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|MSTATUS_PRV1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|MSTATUS_PRV2_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|MSTATUS_PRV_MASK
value|(0x3<< MSTATUS_PRV_SHIFT)
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
name|MSTATUS_VM_SHIFT
value|17
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
name|SR_IE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SR_IE1
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|SR_IE2
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|SR_IE3
value|(1<< 9)
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
name|SIE_STIE
value|(1<< 5)
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

