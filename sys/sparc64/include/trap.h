begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_TRAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_TRAP_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|T_RESERVED
value|0x0
end_define

begin_define
define|#
directive|define
name|T_POWER_ON
value|0x1
end_define

begin_define
define|#
directive|define
name|T_WATCHDOG
value|0x2
end_define

begin_define
define|#
directive|define
name|T_RESET_EXT
value|0x3
end_define

begin_define
define|#
directive|define
name|T_RESET_SOFT
value|0x4
end_define

begin_define
define|#
directive|define
name|T_RED_STATE
value|0x5
end_define

begin_define
define|#
directive|define
name|T_INSN_EXCPTN
value|0x6
end_define

begin_define
define|#
directive|define
name|T_INSN_ERROR
value|0x7
end_define

begin_define
define|#
directive|define
name|T_INSN_ILLEGAL
value|0x8
end_define

begin_define
define|#
directive|define
name|T_PRIV_OPCODE
value|0x9
end_define

begin_define
define|#
directive|define
name|T_FP_DISABLED
value|0xa
end_define

begin_define
define|#
directive|define
name|T_FP_IEEE
value|0xb
end_define

begin_define
define|#
directive|define
name|T_FP_OTHER
value|0xc
end_define

begin_define
define|#
directive|define
name|T_TAG_OVFLW
value|0xd
end_define

begin_define
define|#
directive|define
name|T_DIVIDE
value|0xe
end_define

begin_define
define|#
directive|define
name|T_DATA_EXCPTN
value|0xf
end_define

begin_define
define|#
directive|define
name|T_DATA_ERROR
value|0x10
end_define

begin_define
define|#
directive|define
name|T_ALIGN
value|0x11
end_define

begin_define
define|#
directive|define
name|T_ALIGN_LDDF
value|0x12
end_define

begin_define
define|#
directive|define
name|T_ALIGN_STDF
value|0x13
end_define

begin_define
define|#
directive|define
name|T_PRIV_ACTION
value|0x14
end_define

begin_define
define|#
directive|define
name|T_INTR
value|0x15
end_define

begin_define
define|#
directive|define
name|T_WATCH_PHYS
value|0x16
end_define

begin_define
define|#
directive|define
name|T_WATCH_VIRT
value|0x17
end_define

begin_define
define|#
directive|define
name|T_ECC
value|0x18
end_define

begin_define
define|#
directive|define
name|T_IMMU_MISS
value|0x19
end_define

begin_define
define|#
directive|define
name|T_DMMU_MISS
value|0x1a
end_define

begin_define
define|#
directive|define
name|T_DMMU_PROT
value|0x1b
end_define

begin_define
define|#
directive|define
name|T_SPILL
value|0x1c
end_define

begin_define
define|#
directive|define
name|T_FILL
value|0x1d
end_define

begin_define
define|#
directive|define
name|T_FILL_RET
value|0x1e
end_define

begin_define
define|#
directive|define
name|T_BREAKPOINT
value|0x1f
end_define

begin_define
define|#
directive|define
name|T_SYSCALL
value|0x20
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_PHYS
value|0x21
end_define

begin_define
define|#
directive|define
name|T_RSTRWP_VIRT
value|0x22
end_define

begin_define
define|#
directive|define
name|T_SOFT
value|0x23
end_define

begin_define
define|#
directive|define
name|T_KERNEL
value|0x40
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|trap_msg
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ST_BREAKPOINT
value|0x1
end_define

begin_define
define|#
directive|define
name|ST_SYSCALL
value|0x9
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_TRAP_H_ */
end_comment

end_unit

