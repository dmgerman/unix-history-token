begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ia64-opc.h -- IA-64 opcode table.    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by David Mosberger-Tang<davidm@hpl.hp.com>     This file is part of GDB, GAS, and the GNU binutils.     GDB, GAS, and the GNU binutils are free software; you can redistribute    them and/or modify them under the terms of the GNU General Public    License as published by the Free Software Foundation; either version    2, or (at your option) any later version.     GDB, GAS, and the GNU binutils are distributed in the hope that they    will be useful, but WITHOUT ANY WARRANTY; without even the implied    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this file; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IA64_OPC_H
end_ifndef

begin_define
define|#
directive|define
name|IA64_OPC_H
end_define

begin_include
include|#
directive|include
file|"opcode/ia64.h"
end_include

begin_comment
comment|/* define a couple of abbreviations: */
end_comment

begin_define
define|#
directive|define
name|bOp
parameter_list|(
name|x
parameter_list|)
value|(((ia64_insn) ((x)& 0xf))<< 37)
end_define

begin_define
define|#
directive|define
name|mOp
value|bOp (-1)
end_define

begin_define
define|#
directive|define
name|Op
parameter_list|(
name|x
parameter_list|)
value|bOp (x), mOp
end_define

begin_define
define|#
directive|define
name|FIRST
value|IA64_OPCODE_FIRST
end_define

begin_define
define|#
directive|define
name|X_IN_MLX
value|IA64_OPCODE_X_IN_MLX
end_define

begin_define
define|#
directive|define
name|LAST
value|IA64_OPCODE_LAST
end_define

begin_define
define|#
directive|define
name|PRIV
value|IA64_OPCODE_PRIV
end_define

begin_define
define|#
directive|define
name|NO_PRED
value|IA64_OPCODE_NO_PRED
end_define

begin_define
define|#
directive|define
name|SLOT2
value|IA64_OPCODE_SLOT2
end_define

begin_define
define|#
directive|define
name|PSEUDO
value|IA64_OPCODE_PSEUDO
end_define

begin_define
define|#
directive|define
name|F2_EQ_F3
value|IA64_OPCODE_F2_EQ_F3
end_define

begin_define
define|#
directive|define
name|LEN_EQ_64MCNT
value|IA64_OPCODE_LEN_EQ_64MCNT
end_define

begin_define
define|#
directive|define
name|MOD_RRBS
value|IA64_OPCODE_MOD_RRBS
end_define

begin_define
define|#
directive|define
name|POSTINC
value|IA64_OPCODE_POSTINC
end_define

begin_define
define|#
directive|define
name|AR_CCV
value|IA64_OPND_AR_CCV
end_define

begin_define
define|#
directive|define
name|AR_PFS
value|IA64_OPND_AR_PFS
end_define

begin_define
define|#
directive|define
name|AR_CSD
value|IA64_OPND_AR_CSD
end_define

begin_define
define|#
directive|define
name|C1
value|IA64_OPND_C1
end_define

begin_define
define|#
directive|define
name|C8
value|IA64_OPND_C8
end_define

begin_define
define|#
directive|define
name|C16
value|IA64_OPND_C16
end_define

begin_define
define|#
directive|define
name|GR0
value|IA64_OPND_GR0
end_define

begin_define
define|#
directive|define
name|IP
value|IA64_OPND_IP
end_define

begin_define
define|#
directive|define
name|PR
value|IA64_OPND_PR
end_define

begin_define
define|#
directive|define
name|PR_ROT
value|IA64_OPND_PR_ROT
end_define

begin_define
define|#
directive|define
name|PSR
value|IA64_OPND_PSR
end_define

begin_define
define|#
directive|define
name|PSR_L
value|IA64_OPND_PSR_L
end_define

begin_define
define|#
directive|define
name|PSR_UM
value|IA64_OPND_PSR_UM
end_define

begin_define
define|#
directive|define
name|AR3
value|IA64_OPND_AR3
end_define

begin_define
define|#
directive|define
name|B1
value|IA64_OPND_B1
end_define

begin_define
define|#
directive|define
name|B2
value|IA64_OPND_B2
end_define

begin_define
define|#
directive|define
name|CR3
value|IA64_OPND_CR3
end_define

begin_define
define|#
directive|define
name|F1
value|IA64_OPND_F1
end_define

begin_define
define|#
directive|define
name|F2
value|IA64_OPND_F2
end_define

begin_define
define|#
directive|define
name|F3
value|IA64_OPND_F3
end_define

begin_define
define|#
directive|define
name|F4
value|IA64_OPND_F4
end_define

begin_define
define|#
directive|define
name|P1
value|IA64_OPND_P1
end_define

begin_define
define|#
directive|define
name|P2
value|IA64_OPND_P2
end_define

begin_define
define|#
directive|define
name|R1
value|IA64_OPND_R1
end_define

begin_define
define|#
directive|define
name|R2
value|IA64_OPND_R2
end_define

begin_define
define|#
directive|define
name|R3
value|IA64_OPND_R3
end_define

begin_define
define|#
directive|define
name|R3_2
value|IA64_OPND_R3_2
end_define

begin_define
define|#
directive|define
name|CPUID_R3
value|IA64_OPND_CPUID_R3
end_define

begin_define
define|#
directive|define
name|DBR_R3
value|IA64_OPND_DBR_R3
end_define

begin_define
define|#
directive|define
name|DTR_R3
value|IA64_OPND_DTR_R3
end_define

begin_define
define|#
directive|define
name|ITR_R3
value|IA64_OPND_ITR_R3
end_define

begin_define
define|#
directive|define
name|IBR_R3
value|IA64_OPND_IBR_R3
end_define

begin_define
define|#
directive|define
name|MR3
value|IA64_OPND_MR3
end_define

begin_define
define|#
directive|define
name|MSR_R3
value|IA64_OPND_MSR_R3
end_define

begin_define
define|#
directive|define
name|PKR_R3
value|IA64_OPND_PKR_R3
end_define

begin_define
define|#
directive|define
name|PMC_R3
value|IA64_OPND_PMC_R3
end_define

begin_define
define|#
directive|define
name|PMD_R3
value|IA64_OPND_PMD_R3
end_define

begin_define
define|#
directive|define
name|RR_R3
value|IA64_OPND_RR_R3
end_define

begin_define
define|#
directive|define
name|CCNT5
value|IA64_OPND_CCNT5
end_define

begin_define
define|#
directive|define
name|CNT2a
value|IA64_OPND_CNT2a
end_define

begin_define
define|#
directive|define
name|CNT2b
value|IA64_OPND_CNT2b
end_define

begin_define
define|#
directive|define
name|CNT2c
value|IA64_OPND_CNT2c
end_define

begin_define
define|#
directive|define
name|CNT5
value|IA64_OPND_CNT5
end_define

begin_define
define|#
directive|define
name|CNT6
value|IA64_OPND_CNT6
end_define

begin_define
define|#
directive|define
name|CPOS6a
value|IA64_OPND_CPOS6a
end_define

begin_define
define|#
directive|define
name|CPOS6b
value|IA64_OPND_CPOS6b
end_define

begin_define
define|#
directive|define
name|CPOS6c
value|IA64_OPND_CPOS6c
end_define

begin_define
define|#
directive|define
name|IMM1
value|IA64_OPND_IMM1
end_define

begin_define
define|#
directive|define
name|IMM14
value|IA64_OPND_IMM14
end_define

begin_define
define|#
directive|define
name|IMM17
value|IA64_OPND_IMM17
end_define

begin_define
define|#
directive|define
name|IMM22
value|IA64_OPND_IMM22
end_define

begin_define
define|#
directive|define
name|IMM44
value|IA64_OPND_IMM44
end_define

begin_define
define|#
directive|define
name|SOF
value|IA64_OPND_SOF
end_define

begin_define
define|#
directive|define
name|SOL
value|IA64_OPND_SOL
end_define

begin_define
define|#
directive|define
name|SOR
value|IA64_OPND_SOR
end_define

begin_define
define|#
directive|define
name|IMM8
value|IA64_OPND_IMM8
end_define

begin_define
define|#
directive|define
name|IMM8U4
value|IA64_OPND_IMM8U4
end_define

begin_define
define|#
directive|define
name|IMM8M1
value|IA64_OPND_IMM8M1
end_define

begin_define
define|#
directive|define
name|IMM8M1U4
value|IA64_OPND_IMM8M1U4
end_define

begin_define
define|#
directive|define
name|IMM8M1U8
value|IA64_OPND_IMM8M1U8
end_define

begin_define
define|#
directive|define
name|IMM9a
value|IA64_OPND_IMM9a
end_define

begin_define
define|#
directive|define
name|IMM9b
value|IA64_OPND_IMM9b
end_define

begin_define
define|#
directive|define
name|IMMU2
value|IA64_OPND_IMMU2
end_define

begin_define
define|#
directive|define
name|IMMU21
value|IA64_OPND_IMMU21
end_define

begin_define
define|#
directive|define
name|IMMU24
value|IA64_OPND_IMMU24
end_define

begin_define
define|#
directive|define
name|IMMU62
value|IA64_OPND_IMMU62
end_define

begin_define
define|#
directive|define
name|IMMU64
value|IA64_OPND_IMMU64
end_define

begin_define
define|#
directive|define
name|IMMU7a
value|IA64_OPND_IMMU7a
end_define

begin_define
define|#
directive|define
name|IMMU7b
value|IA64_OPND_IMMU7b
end_define

begin_define
define|#
directive|define
name|IMMU9
value|IA64_OPND_IMMU9
end_define

begin_define
define|#
directive|define
name|INC3
value|IA64_OPND_INC3
end_define

begin_define
define|#
directive|define
name|LEN4
value|IA64_OPND_LEN4
end_define

begin_define
define|#
directive|define
name|LEN6
value|IA64_OPND_LEN6
end_define

begin_define
define|#
directive|define
name|MBTYPE4
value|IA64_OPND_MBTYPE4
end_define

begin_define
define|#
directive|define
name|MHTYPE8
value|IA64_OPND_MHTYPE8
end_define

begin_define
define|#
directive|define
name|POS6
value|IA64_OPND_POS6
end_define

begin_define
define|#
directive|define
name|TAG13
value|IA64_OPND_TAG13
end_define

begin_define
define|#
directive|define
name|TAG13b
value|IA64_OPND_TAG13b
end_define

begin_define
define|#
directive|define
name|TGT25
value|IA64_OPND_TGT25
end_define

begin_define
define|#
directive|define
name|TGT25b
value|IA64_OPND_TGT25b
end_define

begin_define
define|#
directive|define
name|TGT25c
value|IA64_OPND_TGT25c
end_define

begin_define
define|#
directive|define
name|TGT64
value|IA64_OPND_TGT64
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

