begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of opcodes for the OpenRISC 1000 ISA.    Copyright 2002, 2003 Free Software Foundation, Inc.    Contributed by Damjan Lampret (lampret@opencores.org).        This file is part of or1k_gen_isa, or1ksim, GDB and GAS.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* We treat all letters the same in encode/decode routines so    we need to assign some characteristics to them like signess etc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OR32_H_ISA
end_ifndef

begin_define
define|#
directive|define
name|OR32_H_ISA
end_define

begin_define
define|#
directive|define
name|NUM_UNSIGNED
value|(0)
end_define

begin_define
define|#
directive|define
name|NUM_SIGNED
value|(1)
end_define

begin_define
define|#
directive|define
name|MAX_GPRS
value|32
end_define

begin_define
define|#
directive|define
name|PAGE_SIZE
value|4096
end_define

begin_undef
undef|#
directive|undef
name|__HALF_WORD_INSN__
end_undef

begin_define
define|#
directive|define
name|OPERAND_DELIM
value|(',')
end_define

begin_define
define|#
directive|define
name|OR32_IF_DELAY
value|(1)
end_define

begin_define
define|#
directive|define
name|OR32_W_FLAG
value|(2)
end_define

begin_define
define|#
directive|define
name|OR32_R_FLAG
value|(4)
end_define

begin_struct
struct|struct
name|or32_letter
block|{
name|char
name|letter
decl_stmt|;
name|int
name|sign
decl_stmt|;
comment|/* int  reloc; relocation per letter ??  */
block|}
struct|;
end_struct

begin_comment
comment|/* Main instruction specification array.  */
end_comment

begin_struct
struct|struct
name|or32_opcode
block|{
comment|/* Name of the instruction.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* A string of characters which describe the operands.      Valid characters are:      ,() Itself.  Characters appears in the assembly code.      rA	 Register operand.      rB  Register operand.      rD  Register operand.      I	 An immediate operand, range -32768 to 32767.      J	 An immediate operand, range . (unused)      K	 An immediate operand, range 0 to 65535.      L	 An immediate operand, range 0 to 63.      M	 An immediate operand, range . (unused)      N	 An immediate operand, range -33554432 to 33554431.      O	 An immediate operand, range . (unused).  */
name|char
modifier|*
name|args
decl_stmt|;
comment|/* Opcode and operand encoding.  */
name|char
modifier|*
name|encoding
decl_stmt|;
name|void
function_decl|(
modifier|*
name|exec
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OPTYPE_LAST
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_OP
value|(0x40000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_REG
value|(0x20000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_SIG
value|(0x10000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_DIS
value|(0x08000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_DST
value|(0x04000000)
end_define

begin_define
define|#
directive|define
name|OPTYPE_SBIT
value|(0x00001F00)
end_define

begin_define
define|#
directive|define
name|OPTYPE_SHR
value|(0x0000001F)
end_define

begin_define
define|#
directive|define
name|OPTYPE_SBIT_SHR
value|(8)
end_define

begin_comment
comment|/* MM: Data how to decode operands.  */
end_comment

begin_struct
specifier|extern
struct|struct
name|insn_op_struct
block|{
name|unsigned
name|long
name|type
decl_stmt|;
name|unsigned
name|long
name|data
decl_stmt|;
block|}
modifier|*
modifier|*
name|op_start
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|HAS_EXECUTION
end_ifdef

begin_function_decl
specifier|extern
name|void
name|l_invalid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfne
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_bf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_add
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sw
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sh
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_lwz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_lbs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_lbz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_lhs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_lhz
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_movhi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_and
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_or
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_xor
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sub
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_mul
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_div
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_divu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sll
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sra
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_srl
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_j
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_jal
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_jalr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_jr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_rfe
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_nop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_bnf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfeq
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfgts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sflts
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfles
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfgtu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfgeu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfltu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sfleu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_mtspr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_mfspr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_sys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* CZ 21/06/01.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|l_macrc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_mac
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_msb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_invalid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_cust1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_cust2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_cust3
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|l_cust4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|l_none
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|or32_letter
name|or32_letters
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|or32_opcode
name|or32_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|unsigned
name|int
name|or32_num_opcodes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Calculates instruction length in bytes.  Always 4 for OR32.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|insn_len
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is individual insn's operand signed or unsigned?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|letter_signed
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Number of letters in the individual lettered operand.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|letter_range
parameter_list|(
name|char
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MM: Returns index of given instruction name.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|insn_index
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MM: Returns instruction name from index.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|insn_name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MM: Constructs new FSM, based on or32_opcodes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|build_automata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MM: Destructs FSM.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|destruct_automata
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MM: Decodes instruction using FSM.  Call build_automata first.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|insn_decode
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disassemble one instruction from insn to disassemble.    Return the size of the instruction.  */
end_comment

begin_function_decl
name|int
name|disassemble_insn
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

