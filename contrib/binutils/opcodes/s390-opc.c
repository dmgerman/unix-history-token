begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* s390-opc.c -- S390 opcode list    Copyright 2000, 2001 Free Software Foundation, Inc.    Contributed by Martin Schwidefsky (schwidefsky@de.ibm.com).     This file is part of GDB, GAS, and the GNU binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"opcode/s390.h"
end_include

begin_comment
comment|/* This file holds the S390 opcode table.  The opcode table    includes almost all of the extended instruction mnemonics.  This    permits the disassembler to use them, and simplifies the assembler    logic, at the cost of increasing the table size.  The table is    strictly constant data, so the compiler should be able to put it in    the .text section.     This file also holds the operand table.  All knowledge about    inserting operands into instructions and vice-versa is kept in this    file.  */
end_comment

begin_comment
comment|/* The operands table.    The fields are bits, shift, insert, extract, flags.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|s390_operand
name|s390_operands
index|[]
init|=
block|{
define|#
directive|define
name|UNUSED
value|0
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|}
block|,
comment|/* Indicates the end of the operand list */
define|#
directive|define
name|R_8
value|1
comment|/* GPR starting at position 8 */
block|{
literal|4
block|,
literal|8
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_12
value|2
comment|/* GPR starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_16
value|3
comment|/* GPR starting at position 16 */
block|{
literal|4
block|,
literal|16
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_20
value|4
comment|/* GPR starting at position 20 */
block|{
literal|4
block|,
literal|20
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_24
value|5
comment|/* GPR starting at position 24 */
block|{
literal|4
block|,
literal|24
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_28
value|6
comment|/* GPR starting at position 28 */
block|{
literal|4
block|,
literal|28
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|R_32
value|7
comment|/* GPR starting at position 32 */
block|{
literal|4
block|,
literal|32
block|,
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|F_8
value|8
comment|/* FPR starting at position 8 */
block|{
literal|4
block|,
literal|8
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_12
value|9
comment|/* FPR starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_16
value|10
comment|/* FPR starting at position 16 */
block|{
literal|4
block|,
literal|16
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_20
value|11
comment|/* FPR starting at position 16 */
block|{
literal|4
block|,
literal|16
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_24
value|12
comment|/* FPR starting at position 24 */
block|{
literal|4
block|,
literal|24
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_28
value|13
comment|/* FPR starting at position 28 */
block|{
literal|4
block|,
literal|28
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|F_32
value|14
comment|/* FPR starting at position 32 */
block|{
literal|4
block|,
literal|32
block|,
name|S390_OPERAND_FPR
block|}
block|,
define|#
directive|define
name|A_8
value|15
comment|/* Access reg. starting at position 8 */
block|{
literal|4
block|,
literal|8
block|,
name|S390_OPERAND_AR
block|}
block|,
define|#
directive|define
name|A_12
value|16
comment|/* Access reg. starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_AR
block|}
block|,
define|#
directive|define
name|A_24
value|17
comment|/* Access reg. starting at position 24 */
block|{
literal|4
block|,
literal|24
block|,
name|S390_OPERAND_AR
block|}
block|,
define|#
directive|define
name|A_28
value|18
comment|/* Access reg. starting at position 28 */
block|{
literal|4
block|,
literal|28
block|,
name|S390_OPERAND_AR
block|}
block|,
define|#
directive|define
name|C_8
value|19
comment|/* Control reg. starting at position 8 */
block|{
literal|4
block|,
literal|8
block|,
name|S390_OPERAND_CR
block|}
block|,
define|#
directive|define
name|C_12
value|20
comment|/* Control reg. starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_CR
block|}
block|,
define|#
directive|define
name|B_16
value|21
comment|/* Base register starting at position 16 */
block|{
literal|4
block|,
literal|16
block|,
name|S390_OPERAND_BASE
operator||
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|B_32
value|22
comment|/* Base register starting at position 32 */
block|{
literal|4
block|,
literal|32
block|,
name|S390_OPERAND_BASE
operator||
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|X_12
value|23
comment|/* Index register starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_INDEX
operator||
name|S390_OPERAND_GPR
block|}
block|,
define|#
directive|define
name|D_20
value|24
comment|/* Displacement starting at position 20 */
block|{
literal|12
block|,
literal|20
block|,
name|S390_OPERAND_DISP
block|}
block|,
define|#
directive|define
name|D_36
value|25
comment|/* Displacement starting at position 36 */
block|{
literal|12
block|,
literal|36
block|,
name|S390_OPERAND_DISP
block|}
block|,
define|#
directive|define
name|D20_20
value|26
comment|/* 20 bit displacement starting at 20 */
block|{
literal|20
block|,
literal|20
block|,
name|S390_OPERAND_DISP
operator||
name|S390_OPERAND_SIGNED
block|}
block|,
define|#
directive|define
name|L4_8
value|27
comment|/* 4 bit length starting at position 8 */
block|{
literal|4
block|,
literal|8
block|,
name|S390_OPERAND_LENGTH
block|}
block|,
define|#
directive|define
name|L4_12
value|28
comment|/* 4 bit length starting at position 12 */
block|{
literal|4
block|,
literal|12
block|,
name|S390_OPERAND_LENGTH
block|}
block|,
define|#
directive|define
name|L8_8
value|29
comment|/* 8 bit length starting at position 8 */
block|{
literal|8
block|,
literal|8
block|,
name|S390_OPERAND_LENGTH
block|}
block|,
define|#
directive|define
name|U4_8
value|30
comment|/* 4 bit unsigned value starting at 8 */
block|{
literal|4
block|,
literal|8
block|,
literal|0
block|}
block|,
define|#
directive|define
name|U4_12
value|31
comment|/* 4 bit unsigned value starting at 12 */
block|{
literal|4
block|,
literal|12
block|,
literal|0
block|}
block|,
define|#
directive|define
name|U4_16
value|32
comment|/* 4 bit unsigned value starting at 16 */
block|{
literal|4
block|,
literal|16
block|,
literal|0
block|}
block|,
define|#
directive|define
name|U4_20
value|33
comment|/* 4 bit unsigned value starting at 20 */
block|{
literal|4
block|,
literal|20
block|,
literal|0
block|}
block|,
define|#
directive|define
name|U8_8
value|34
comment|/* 8 bit unsigned value starting at 8 */
block|{
literal|8
block|,
literal|8
block|,
literal|0
block|}
block|,
define|#
directive|define
name|U8_16
value|35
comment|/* 8 bit unsigned value starting at 16 */
block|{
literal|8
block|,
literal|16
block|,
literal|0
block|}
block|,
define|#
directive|define
name|I16_16
value|36
comment|/* 16 bit signed value starting at 16 */
block|{
literal|16
block|,
literal|16
block|,
name|S390_OPERAND_SIGNED
block|}
block|,
define|#
directive|define
name|U16_16
value|37
comment|/* 16 bit unsigned value starting at 16 */
block|{
literal|16
block|,
literal|16
block|,
literal|0
block|}
block|,
define|#
directive|define
name|J16_16
value|38
comment|/* PC relative jump offset at 16 */
block|{
literal|16
block|,
literal|16
block|,
name|S390_OPERAND_PCREL
block|}
block|,
define|#
directive|define
name|J32_16
value|39
comment|/* PC relative long offset at 16 */
block|{
literal|32
block|,
literal|16
block|,
name|S390_OPERAND_PCREL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros used to form opcodes.  */
end_comment

begin_comment
comment|/* 8/16/48 bit opcodes.  */
end_comment

begin_define
define|#
directive|define
name|OP8
parameter_list|(
name|x
parameter_list|)
value|{ x, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|OP16
parameter_list|(
name|x
parameter_list|)
value|{ x>> 8, x& 255, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|OP48
parameter_list|(
name|x
parameter_list|)
value|{ x>> 40, (x>> 32)& 255, (x>> 24)& 255, \                   (x>> 16)& 255, (x>> 8)& 255, x& 255}
end_define

begin_comment
comment|/* The new format of the INSTR_x_y and MASK_x_y defines is based    on the following rules:    1) the middle part of the definition (x in INSTR_x_y) is the official       names of the instruction format that you can find in the principals       of operation.    2) the last part of the definition (y in INSTR_x_y) gives you an idea       which operands the binary represenation of the instruction has.       The meanings of the letters in y are:       a - access register       c - control register       d - displacement, 12 bit       f - floating pointer register       i - signed integer, 4 or 8 bit       l - length, 4 or 8 bit       p - pc relative       r - general purpose register       u - unsigned integer, 4 or 8 bit       0 - operand skipped.       The order of the letters reflects the layout of the format in       storage and not the order of the paramaters of the instructions.       The use of the letters is not a 100% match with the PoP but it is       quite close.        For example the instruction "mvo" is defined in the PoP as follows:              MVO  D1(L1,B1),D2(L2,B2)   [SS]        --------------------------------------       | 'F1' | L1 | L2 | B1 | D1 | B2 | D2 |       --------------------------------------        0      8    12   16   20   32   36        The instruction format is: INSTR_SS_LLRDRD / MASK_SS_LLRDRD.  */
end_comment

begin_define
define|#
directive|define
name|INSTR_E
value|2, { 0,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. pr    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RIE_RRP
value|6, { R_8,R_12,J16_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. brxhg */
end_comment

begin_define
define|#
directive|define
name|INSTR_RIL_0P
value|6, { J32_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. jg    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RIL_RP
value|6, { R_8,J32_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. brasl */
end_comment

begin_define
define|#
directive|define
name|INSTR_RIL_UP
value|6, { U4_8,J32_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. brcl  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RI_0P
value|4, { J16_16,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. j     */
end_comment

begin_define
define|#
directive|define
name|INSTR_RI_RI
value|4, { R_8,I16_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. ahi   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RI_RP
value|4, { R_8,J16_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. brct  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RI_RU
value|4, { R_8,U16_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. tml   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RI_UP
value|4, { U4_8,J16_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. brc   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_00
value|4, { 0,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. palb  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_0R
value|4, { R_28,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. tb    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_AA
value|4, { A_24,A_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. cpya  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_AR
value|4, { A_24,R_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. sar   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_F0
value|4, { F_24,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. sqer  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_FF
value|4, { F_24,F_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. debr  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_R0
value|4, { R_24,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. ipm   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_RA
value|4, { R_24,A_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. ear   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_RF
value|4, { R_24,F_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. cefbr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRE_RR
value|4, { R_24,R_28,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. lura  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_F0FF
value|4, { F_16,F_24,F_28,0,0,0 }
end_define

begin_comment
comment|/* e.g. madbr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_FUFF
value|4, { F_24,F_16,F_28,U4_20,0,0 }
end_define

begin_comment
comment|/* e.g. didbr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_RURR
value|4, { R_24,R_28,R_16,U4_20,0,0 }
end_define

begin_comment
comment|/* e.g. .insn */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_R0RR
value|4, { R_24,R_28,R_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. idte  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_U0FF
value|4, { F_24,U4_16,F_28,0,0,0 }
end_define

begin_comment
comment|/* e.g. cfxbr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_U0FR
value|4, { F_24,U4_16,R_28,0,0,0 }
end_define

begin_comment
comment|/* e.g. cfebr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RRF_U0FR
value|4, { F_24,U4_16,R_28,0,0,0 }
end_define

begin_comment
comment|/* e.g. cfxbr */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_0R
value|2, { R_12, 0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. br    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_FF
value|2, { F_8,F_12,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. adr   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_R0
value|2, { R_8, 0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. spm   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_RR
value|2, { R_8,R_12,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. lr    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_U0
value|2, { U8_8, 0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. svc   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RR_UR
value|2, { U4_8,R_12,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. bcr   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSE_RRRD
value|6, { R_8,R_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. lmh   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSE_RURD
value|6, { R_8,U4_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. icmh  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSL_R0RD
value|6, { R_8,D_20,B_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. tp    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSI_RRP
value|4, { R_8,R_12,J16_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. brxh  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSY_RRRD
value|6, { R_8,R_12,D20_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. stmy  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSY_RURD
value|6, { R_8,U4_12,D20_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. icmh  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RSY_AARD
value|6, { A_8,A_12,D20_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. lamy  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RS_AARD
value|4, { A_8,A_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. lam   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RS_CCRD
value|4, { C_8,C_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. lctl  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RS_R0RD
value|4, { R_8,D_20,B_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. sll   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RS_RRRD
value|4, { R_8,R_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. cs    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RS_RURD
value|4, { R_8,U4_12,D_20,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. icm   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXE_FRRD
value|6, { F_8,D_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. axbr  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXE_RRRD
value|6, { R_8,D_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. lg    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXF_FRRDF
value|6, { F_32,F_8,D_20,X_12,B_16,0 }
end_define

begin_comment
comment|/* e.g. madb  */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXF_RRRDR
value|6, { R_32,R_8,D_20,X_12,B_16,0 }
end_define

begin_comment
comment|/* e.g. .insn */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXY_RRRD
value|6, { R_8,D20_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. ly    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RXY_FRRD
value|6, { F_8,D20_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. ley   */
end_comment

begin_define
define|#
directive|define
name|INSTR_RX_0RRD
value|4, { D_20,X_12,B_16,0,0,0 }
end_define

begin_comment
comment|/* e.g. be    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RX_FRRD
value|4, { F_8,D_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. ae    */
end_comment

begin_define
define|#
directive|define
name|INSTR_RX_RRRD
value|4, { R_8,D_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. l     */
end_comment

begin_define
define|#
directive|define
name|INSTR_RX_URRD
value|4, { U4_8,D_20,X_12,B_16,0,0 }
end_define

begin_comment
comment|/* e.g. bc    */
end_comment

begin_define
define|#
directive|define
name|INSTR_SI_URD
value|4, { D_20,B_16,U8_8,0,0,0 }
end_define

begin_comment
comment|/* e.g. cli   */
end_comment

begin_define
define|#
directive|define
name|INSTR_SIY_URD
value|6, { D20_20,B_16,U8_8,0,0,0 }
end_define

begin_comment
comment|/* e.g. tmy   */
end_comment

begin_define
define|#
directive|define
name|INSTR_SSE_RDRD
value|6, { D_20,B_16,D_36,B_32,0,0 }
end_define

begin_comment
comment|/* e.g. mvsdk */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_L0RDRD
value|6, { D_20,L8_8,B_16,D_36,B_32,0     }
end_define

begin_comment
comment|/* e.g. mvc   */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_LIRDRD
value|6, { D_20,L4_8,B_16,D_36,B_32,U4_12 }
end_define

begin_comment
comment|/* e.g. srp   */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_LLRDRD
value|6, { D_20,L4_8,B_16,D_36,L4_12,B_32 }
end_define

begin_comment
comment|/* e.g. pack  */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_RRRDRD
value|6, { D_20,R_8,B_16,D_36,B_32,R_12 }
end_define

begin_comment
comment|/* e.g. mvck  */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_RRRDRD2
value|6, { R_8,D_20,B_16,R_12,D_36,B_32 }
end_define

begin_comment
comment|/* e.g. plo   */
end_comment

begin_define
define|#
directive|define
name|INSTR_SS_RRRDRD3
value|6, { R_8,R_12,D_20,B_16,D_36,B_32 }
end_define

begin_comment
comment|/* e.g. lmd   */
end_comment

begin_define
define|#
directive|define
name|INSTR_S_00
value|4, { 0,0,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. hsch  */
end_comment

begin_define
define|#
directive|define
name|INSTR_S_RD
value|4, { D_20,B_16,0,0,0,0 }
end_define

begin_comment
comment|/* e.g. lpsw  */
end_comment

begin_define
define|#
directive|define
name|MASK_E
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RIE_RRP
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RIL_0P
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RIL_RP
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RIL_UP
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RI_0P
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RI_RI
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RI_RP
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RI_RU
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RI_UP
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_00
value|{ 0xff, 0xff, 0xff, 0xff, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_0R
value|{ 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_AA
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_AR
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_F0
value|{ 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_FF
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_R0
value|{ 0xff, 0xff, 0xff, 0x0f, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_RA
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_RF
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRE_RR
value|{ 0xff, 0xff, 0xff, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_F0FF
value|{ 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_FUFF
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_RURR
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_R0RR
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_U0FF
value|{ 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_U0FR
value|{ 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RRF_U0FR
value|{ 0xff, 0xff, 0x0f, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_0R
value|{ 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_FF
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_R0
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_RR
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_U0
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RR_UR
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RSE_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RSE_RURD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RSL_R0RD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RSI_RRP
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RS_AARD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RS_CCRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RS_R0RD
value|{ 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RS_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RS_RURD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RSY_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RSY_RURD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RSY_AARD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXE_FRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXE_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXF_FRRDF
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXF_RRRDR
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXY_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RXY_FRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_RX_0RRD
value|{ 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RX_FRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RX_RRRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_RX_URRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SI_URD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SIY_URD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0xff }
end_define

begin_define
define|#
directive|define
name|MASK_SSE_RDRD
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_L0RDRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_LIRDRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_LLRDRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_RRRDRD
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_RRRDRD2
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_SS_RRRDRD3
value|{ 0xff, 0x00, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_S_00
value|{ 0xff, 0xff, 0xff, 0xff, 0x00, 0x00 }
end_define

begin_define
define|#
directive|define
name|MASK_S_RD
value|{ 0xff, 0xff, 0x00, 0x00, 0x00, 0x00 }
end_define

begin_comment
comment|/* The opcode formats table (blueprints for .insn pseudo mnemonic).  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|s390_opcode
name|s390_opformats
index|[]
init|=
block|{
block|{
literal|"e"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_E
block|,
name|INSTR_E
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"ri"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RI_RI
block|,
name|INSTR_RI_RI
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rie"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RIE_RRP
block|,
name|INSTR_RIE_RRP
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"ril"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RIL_RP
block|,
name|INSTR_RIL_RP
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rr"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RR_RR
block|,
name|INSTR_RR_RR
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rre"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RRE_RR
block|,
name|INSTR_RRE_RR
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rrf"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RRF_RURR
block|,
name|INSTR_RRF_RURR
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rs"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RS_RRRD
block|,
name|INSTR_RS_RRRD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rse"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RSE_RRRD
block|,
name|INSTR_RSE_RRRD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rsi"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RSI_RRP
block|,
name|INSTR_RSI_RRP
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rsy"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RSY_RRRD
block|,
name|INSTR_RSY_RRRD
block|,
literal|3
block|,
literal|3
block|}
block|,
block|{
literal|"rx"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RX_RRRD
block|,
name|INSTR_RX_RRRD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rxe"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RXE_RRRD
block|,
name|INSTR_RXE_RRRD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rxf"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RXF_RRRDR
block|,
name|INSTR_RXF_RRRDR
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"rxy"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_RXY_RRRD
block|,
name|INSTR_RXY_RRRD
block|,
literal|3
block|,
literal|3
block|}
block|,
block|{
literal|"s"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_S_RD
block|,
name|INSTR_S_RD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"si"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_SI_URD
block|,
name|INSTR_SI_URD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"siy"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_SIY_URD
block|,
name|INSTR_SIY_URD
block|,
literal|3
block|,
literal|3
block|}
block|,
block|{
literal|"ss"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_SS_RRRDRD
block|,
name|INSTR_SS_RRRDRD
block|,
literal|3
block|,
literal|0
block|}
block|,
block|{
literal|"sse"
block|,
name|OP8
argument_list|(
literal|0x00LL
argument_list|)
block|,
name|MASK_SSE_RDRD
block|,
name|INSTR_SSE_RDRD
block|,
literal|3
block|,
literal|0
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|int
name|s390_num_opformats
init|=
sizeof|sizeof
argument_list|(
name|s390_opformats
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|s390_opformats
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"s390-opc.tab"
end_include

end_unit

