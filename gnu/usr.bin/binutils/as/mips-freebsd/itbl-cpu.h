begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* itbl-mips.h     Copyright (C) 1997  Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_comment
comment|/* Defines for Mips itbl cop support */
end_comment

begin_include
include|#
directive|include
file|"opcode/mips.h"
end_include

begin_comment
comment|/* Values for processors will be from 0 to NUMBER_OF_PROCESSORS-1 */
end_comment

begin_define
define|#
directive|define
name|NUMBER_OF_PROCESSORS
value|4
end_define

begin_define
define|#
directive|define
name|MAX_BITPOS
value|31
end_define

begin_comment
comment|/* Mips specifics */
end_comment

begin_define
define|#
directive|define
name|MIPS_OPCODE_COP0
value|(0x21)
end_define

begin_comment
comment|/* COPz+CO, bits 31-25: 0100zz1 */
end_comment

begin_define
define|#
directive|define
name|MIPS_ENCODE_COP_NUM
parameter_list|(
name|z
parameter_list|)
value|((MIPS_OPCODE_COP0|z<<1)<<25)
end_define

begin_define
define|#
directive|define
name|MIPS_IS_COP_INSN
parameter_list|(
name|insn
parameter_list|)
value|((MIPS_OPCODE_COP0&(insn>>25)) \ 	== MIPS_OPCODE_COP0)
end_define

begin_define
define|#
directive|define
name|MIPS_DECODE_COP_NUM
parameter_list|(
name|insn
parameter_list|)
value|((~MIPS_OPCODE_COP0&(insn>>25))>>1)
end_define

begin_define
define|#
directive|define
name|MIPS_DECODE_COP_COFUN
parameter_list|(
name|insn
parameter_list|)
value|((~MIPS_ENCODE_COP_NUM(3))&(insn))
end_define

begin_comment
comment|/* definitions required by generic code */
end_comment

begin_define
define|#
directive|define
name|ITBL_IS_INSN
parameter_list|(
name|insn
parameter_list|)
value|MIPS_IS_COP_INSN(insn)
end_define

begin_define
define|#
directive|define
name|ITBL_DECODE_PNUM
parameter_list|(
name|insn
parameter_list|)
value|MIPS_DECODE_COP_NUM(insn)
end_define

begin_define
define|#
directive|define
name|ITBL_ENCODE_PNUM
parameter_list|(
name|pnum
parameter_list|)
value|MIPS_ENCODE_COP_NUM(pnum)
end_define

begin_define
define|#
directive|define
name|ITBL_OPCODE_STRUCT
value|mips_opcode
end_define

begin_define
define|#
directive|define
name|ITBL_OPCODES
value|mips_opcodes
end_define

begin_define
define|#
directive|define
name|ITBL_NUM_OPCODES
value|NUMOPCODES
end_define

begin_define
define|#
directive|define
name|ITBL_NUM_MACROS
value|M_NUM_MACROS
end_define

end_unit

