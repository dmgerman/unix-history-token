begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPU ELF support for BFD.     Copyright 2006 Free Software Foundation, Inc.     This file is part of GDB, GAS, and the GNU binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* These two enums are from rel_apu/common/spu_asm_format.h */
end_comment

begin_comment
comment|/* definition of instruction format */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|RRR
block|,
name|RI18
block|,
name|RI16
block|,
name|RI10
block|,
name|RI8
block|,
name|RI7
block|,
name|RR
block|,
name|LBT
block|,
name|LBTI
block|,
name|IDATA
block|,
name|UNKNOWN_IFORMAT
block|}
name|spu_iformat
typedef|;
end_typedef

begin_comment
comment|/* These values describe assembly instruction arguments.  They indicate  * how to encode, range checking and which relocation to use. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|A_T
block|,
comment|/* register at pos 0 */
name|A_A
block|,
comment|/* register at pos 7 */
name|A_B
block|,
comment|/* register at pos 14 */
name|A_C
block|,
comment|/* register at pos 21 */
name|A_S
block|,
comment|/* special purpose register at pos 7 */
name|A_H
block|,
comment|/* channel register at pos 7 */
name|A_P
block|,
comment|/* parenthesis, this has to separate regs from immediates */
name|A_S3
block|,
name|A_S6
block|,
name|A_S7N
block|,
name|A_S7
block|,
name|A_U7A
block|,
name|A_U7B
block|,
name|A_S10B
block|,
name|A_S10
block|,
name|A_S11
block|,
name|A_S11I
block|,
name|A_S14
block|,
name|A_S16
block|,
name|A_S18
block|,
name|A_R18
block|,
name|A_U3
block|,
name|A_U5
block|,
name|A_U6
block|,
name|A_U7
block|,
name|A_U14
block|,
name|A_X16
block|,
name|A_U18
block|,
name|A_MAX
block|}
name|spu_aformat
typedef|;
end_typedef

begin_enum
enum|enum
name|spu_insns
block|{
define|#
directive|define
name|APUOP
parameter_list|(
name|TAG
parameter_list|,
name|MACFORMAT
parameter_list|,
name|OPCODE
parameter_list|,
name|MNEMONIC
parameter_list|,
name|ASMFORMAT
parameter_list|,
name|DEP
parameter_list|,
name|PIPE
parameter_list|)
define|\
value|TAG,
define|#
directive|define
name|APUOPFB
parameter_list|(
name|TAG
parameter_list|,
name|MACFORMAT
parameter_list|,
name|OPCODE
parameter_list|,
name|FB
parameter_list|,
name|MNEMONIC
parameter_list|,
name|ASMFORMAT
parameter_list|,
name|DEP
parameter_list|,
name|PIPE
parameter_list|)
define|\
value|TAG,
include|#
directive|include
file|"opcode/spu-insns.h"
undef|#
directive|undef
name|APUOP
undef|#
directive|undef
name|APUOPFB
name|M_SPU_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|spu_opcode
block|{
name|spu_iformat
name|insn_type
decl_stmt|;
name|unsigned
name|int
name|opcode
decl_stmt|;
name|char
modifier|*
name|mnemonic
decl_stmt|;
name|int
name|arg
index|[
literal|5
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIGNED_EXTRACT
parameter_list|(
name|insn
parameter_list|,
name|size
parameter_list|,
name|pos
parameter_list|)
value|(((int)((insn)<< (32-size-pos)))>> (32-size))
end_define

begin_define
define|#
directive|define
name|UNSIGNED_EXTRACT
parameter_list|(
name|insn
parameter_list|,
name|size
parameter_list|,
name|pos
parameter_list|)
value|(((insn)>> pos)& ((1<< size)-1))
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_RT
parameter_list|(
name|insn
parameter_list|)
value|(insn& 0x7f)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_RA
parameter_list|(
name|insn
parameter_list|)
value|((insn>> 7)& 0x7f)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_RB
parameter_list|(
name|insn
parameter_list|)
value|((insn>> 14)& 0x7f)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_RC
parameter_list|(
name|insn
parameter_list|)
value|((insn>> 21)& 0x7f)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_I10
parameter_list|(
name|insn
parameter_list|)
value|SIGNED_EXTRACT(insn,10,14)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U10
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,10,14)
end_define

begin_comment
comment|/* For branching, immediate loads, hbr and  lqa/stqa. */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_I16
parameter_list|(
name|insn
parameter_list|)
value|SIGNED_EXTRACT(insn,16,7)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U16
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,16,7)
end_define

begin_comment
comment|/* for stop */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_U14
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,14,0)
end_define

begin_comment
comment|/* For ila */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_I18
parameter_list|(
name|insn
parameter_list|)
value|SIGNED_EXTRACT(insn,18,7)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U18
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,18,7)
end_define

begin_comment
comment|/* For rotate and shift and generate control mask */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_I7
parameter_list|(
name|insn
parameter_list|)
value|SIGNED_EXTRACT(insn,7,14)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U7
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,7,14)
end_define

begin_comment
comment|/* For float<-> int conversion */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_I8
parameter_list|(
name|insn
parameter_list|)
value|SIGNED_EXTRACT(insn,8,14)
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U8
parameter_list|(
name|insn
parameter_list|)
value|UNSIGNED_EXTRACT(insn,8,14)
end_define

begin_comment
comment|/* For hbr  */
end_comment

begin_define
define|#
directive|define
name|DECODE_INSN_I9a
parameter_list|(
name|insn
parameter_list|)
value|((SIGNED_EXTRACT(insn,2,23)<< 7) | UNSIGNED_EXTRACT(insn,7,0))
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_I9b
parameter_list|(
name|insn
parameter_list|)
value|((SIGNED_EXTRACT(insn,2,14)<< 7) | UNSIGNED_EXTRACT(insn,7,0))
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U9a
parameter_list|(
name|insn
parameter_list|)
value|((UNSIGNED_EXTRACT(insn,2,23)<< 7) | UNSIGNED_EXTRACT(insn,7,0))
end_define

begin_define
define|#
directive|define
name|DECODE_INSN_U9b
parameter_list|(
name|insn
parameter_list|)
value|((UNSIGNED_EXTRACT(insn,2,14)<< 7) | UNSIGNED_EXTRACT(insn,7,0))
end_define

end_unit

