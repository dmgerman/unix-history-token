begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of opcodes for the DLX microprocess.    Copyright 2002 Free Software Foundation, Inc.     This file is part of GDB and GAS.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.     Initially created by Kuang Hwa Lin, 2002.   */
end_comment

begin_comment
comment|/* Following are the function codes for the Special OP (ALU).  */
end_comment

begin_define
define|#
directive|define
name|ALUOP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SPECIALOP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|NOPF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SLLF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|SRLF
value|0x00000006
end_define

begin_define
define|#
directive|define
name|SRAF
value|0x00000007
end_define

begin_define
define|#
directive|define
name|SEQUF
value|0x00000010
end_define

begin_define
define|#
directive|define
name|SNEUF
value|0x00000011
end_define

begin_define
define|#
directive|define
name|SLTUF
value|0x00000012
end_define

begin_define
define|#
directive|define
name|SGTUF
value|0x00000013
end_define

begin_define
define|#
directive|define
name|SLEUF
value|0x00000014
end_define

begin_define
define|#
directive|define
name|SGEUF
value|0x00000015
end_define

begin_define
define|#
directive|define
name|ADDF
value|0x00000020
end_define

begin_define
define|#
directive|define
name|ADDUF
value|0x00000021
end_define

begin_define
define|#
directive|define
name|SUBF
value|0x00000022
end_define

begin_define
define|#
directive|define
name|SUBUF
value|0x00000023
end_define

begin_define
define|#
directive|define
name|ANDF
value|0x00000024
end_define

begin_define
define|#
directive|define
name|ORF
value|0x00000025
end_define

begin_define
define|#
directive|define
name|XORF
value|0x00000026
end_define

begin_define
define|#
directive|define
name|SEQF
value|0x00000028
end_define

begin_define
define|#
directive|define
name|SNEF
value|0x00000029
end_define

begin_define
define|#
directive|define
name|SLTF
value|0x0000002A
end_define

begin_define
define|#
directive|define
name|SGTF
value|0x0000002B
end_define

begin_define
define|#
directive|define
name|SLEF
value|0x0000002C
end_define

begin_define
define|#
directive|define
name|SGEF
value|0x0000002D
end_define

begin_comment
comment|/* Following special functions was not mentioned in the      Hennessy's book but was implemented in the RTL.  */
end_comment

begin_define
define|#
directive|define
name|MVTSF
value|0x00000030
end_define

begin_define
define|#
directive|define
name|MVFSF
value|0x00000031
end_define

begin_define
define|#
directive|define
name|BSWAPF
value|0x00000032
end_define

begin_define
define|#
directive|define
name|LUTF
value|0x00000033
end_define

begin_comment
comment|/* Following special functions was mentioned in the    Hennessy's book but was not implemented in the RTL.  */
end_comment

begin_define
define|#
directive|define
name|MULTF
value|0x00000005
end_define

begin_define
define|#
directive|define
name|MULTUF
value|0x00000006
end_define

begin_define
define|#
directive|define
name|DIVF
value|0x00000007
end_define

begin_define
define|#
directive|define
name|DIVUF
value|0x00000008
end_define

begin_comment
comment|/* Following are the rest of the OPcodes:    JOP    = (0x002<< 26), JALOP  = (0x003<< 26), BEQOP = (0x004<< 26),   BNEOP  = (0x005<< 26)    ADDIOP = (0x008<< 26), ADDUIOP= (0x009<< 26), SUBIOP	= (0x00A<< 26), SUBUIOP= (0x00B<< 26)    ANDIOP = (0x00C<< 26), ORIOP  = (0x00D<< 26), XORIOP = (0x00E<< 26),  LHIOP  = (0x00F<< 26)    RFEOP  = (0x010<< 26), TRAPOP = (0x011<< 26), JROP	= (0x012<< 26), JALROP = (0x013<< 26)    BREAKOP= (0x014<< 26)    SEQIOP = (0x018<< 26), SNEIOP = (0x019<< 26), SLTIOP = (0x01A<< 26),  SGTIOP = (0x01B<< 26)    SLEIOP = (0x01C<< 26), SGEIOP = (0x01D<< 26)    LBOP   = (0x020<< 26), LHOP   = (0x021<< 26), LWOP   = (0x023<< 26),  LBUOP  = (0x024<< 26)    LHUOP  = (0x025<< 26), SBOP   = (0x028<< 26), SHOP   = (0x029<< 26),  SWOP   = (0x02B<< 26)    LSBUOP = (0x026<< 26), LSHU   = (0x027<< 26), LSW    = (0x02C<< 26),    SEQUIOP= (0x030<< 26), SNEUIOP= (0x031<< 26), SLTUIOP= (0x032<< 26),  SGTUIOP= (0x033<< 26)    SLEUIOP= (0x034<< 26), SGEUIOP= (0x035<< 26)    SLLIOP = (0x036<< 26), SRLIOP = (0x037<< 26), SRAIOP = (0x038<< 26).  */
end_comment

begin_define
define|#
directive|define
name|JOP
value|0x08000000
end_define

begin_define
define|#
directive|define
name|JALOP
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|BEQOP
value|0x10000000
end_define

begin_define
define|#
directive|define
name|BNEOP
value|0x14000000
end_define

begin_define
define|#
directive|define
name|ADDIOP
value|0x20000000
end_define

begin_define
define|#
directive|define
name|ADDUIOP
value|0x24000000
end_define

begin_define
define|#
directive|define
name|SUBIOP
value|0x28000000
end_define

begin_define
define|#
directive|define
name|SUBUIOP
value|0x2c000000
end_define

begin_define
define|#
directive|define
name|ANDIOP
value|0x30000000
end_define

begin_define
define|#
directive|define
name|ORIOP
value|0x34000000
end_define

begin_define
define|#
directive|define
name|XORIOP
value|0x38000000
end_define

begin_define
define|#
directive|define
name|LHIOP
value|0x3c000000
end_define

begin_define
define|#
directive|define
name|RFEOP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TRAPOP
value|0x44000000
end_define

begin_define
define|#
directive|define
name|JROP
value|0x48000000
end_define

begin_define
define|#
directive|define
name|JALROP
value|0x4c000000
end_define

begin_define
define|#
directive|define
name|BREAKOP
value|0x50000000
end_define

begin_define
define|#
directive|define
name|SEQIOP
value|0x60000000
end_define

begin_define
define|#
directive|define
name|SNEIOP
value|0x64000000
end_define

begin_define
define|#
directive|define
name|SLTIOP
value|0x68000000
end_define

begin_define
define|#
directive|define
name|SGTIOP
value|0x6c000000
end_define

begin_define
define|#
directive|define
name|SLEIOP
value|0x70000000
end_define

begin_define
define|#
directive|define
name|SGEIOP
value|0x74000000
end_define

begin_define
define|#
directive|define
name|LBOP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|LHOP
value|0x84000000
end_define

begin_define
define|#
directive|define
name|LWOP
value|0x8c000000
end_define

begin_define
define|#
directive|define
name|LBUOP
value|0x90000000
end_define

begin_define
define|#
directive|define
name|LHUOP
value|0x94000000
end_define

begin_define
define|#
directive|define
name|LDSTBU
end_define

begin_define
define|#
directive|define
name|LDSTHU
end_define

begin_define
define|#
directive|define
name|SBOP
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|SHOP
value|0xa4000000
end_define

begin_define
define|#
directive|define
name|SWOP
value|0xac000000
end_define

begin_define
define|#
directive|define
name|LDST
end_define

begin_define
define|#
directive|define
name|SEQUIOP
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|SNEUIOP
value|0xc4000000
end_define

begin_define
define|#
directive|define
name|SLTUIOP
value|0xc8000000
end_define

begin_define
define|#
directive|define
name|SGTUIOP
value|0xcc000000
end_define

begin_define
define|#
directive|define
name|SLEUIOP
value|0xd0000000
end_define

begin_define
define|#
directive|define
name|SGEUIOP
value|0xd4000000
end_define

begin_define
define|#
directive|define
name|SLLIOP
value|0xd8000000
end_define

begin_define
define|#
directive|define
name|SRLIOP
value|0xdc000000
end_define

begin_define
define|#
directive|define
name|SRAIOP
value|0xe0000000
end_define

begin_comment
comment|/* Following 3 ops was added to provide the MP atonmic operation.  */
end_comment

begin_define
define|#
directive|define
name|LSBUOP
value|0x98000000
end_define

begin_define
define|#
directive|define
name|LSHUOP
value|0x9c000000
end_define

begin_define
define|#
directive|define
name|LSWOP
value|0xb0000000
end_define

begin_comment
comment|/* Following opcode was defined in the Hennessy's book as    "normal" opcode but was implemented in the RTL as special    functions.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|MVTSOP
value|0x50000000
end_define

begin_define
define|#
directive|define
name|MVFSOP
value|0x54000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|dlx_opcode
block|{
comment|/* Name of the instruction.  */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Opcode word.  */
name|unsigned
name|long
name|opcode
decl_stmt|;
comment|/* A string of characters which describe the operands.      Valid characters are:      ,        Itself.  The character appears in the assembly code.      a        rs1      The register number is in bits 21-25 of the instruction.      b        rs2/rd   The register number is in bits 16-20 of the instruction.      c        rd.      The register number is in bits 11-15 of the instruction.      f        FUNC bits 0-10 of the instruction.      i        An immediate operand is in bits 0-16 of the instruction. 0 extended      I        An immediate operand is in bits 0-16 of the instruction. sign extended      d	      An 16 bit PC relative displacement.      D	      An immediate operand is in bits 0-25 of the instruction.      N	      No opperands needed, for nops.      P	      it can be a register or a 16 bit operand.  */
name|char
modifier|*
name|args
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|dlx_opcode
name|dlx_opcodes
index|[]
init|=
block|{
comment|/* Arithmetic and Logic R-TYPE instructions.  */
block|{
literal|"nop"
block|,
operator|(
name|ALUOP
operator||
name|NOPF
operator|)
block|,
literal|"N"
block|}
block|,
comment|/* NOP                          */
block|{
literal|"add"
block|,
operator|(
name|ALUOP
operator||
name|ADDF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Add                          */
block|{
literal|"addu"
block|,
operator|(
name|ALUOP
operator||
name|ADDUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Add Unsigned                 */
block|{
literal|"sub"
block|,
operator|(
name|ALUOP
operator||
name|SUBF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* SUB                          */
block|{
literal|"subu"
block|,
operator|(
name|ALUOP
operator||
name|SUBUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Sub Unsigned                 */
block|{
literal|"mult"
block|,
operator|(
name|ALUOP
operator||
name|MULTF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* MULTIPLY                     */
block|{
literal|"multu"
block|,
operator|(
name|ALUOP
operator||
name|MULTUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* MULTIPLY Unsigned            */
block|{
literal|"div"
block|,
operator|(
name|ALUOP
operator||
name|DIVF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* DIVIDE                       */
block|{
literal|"divu"
block|,
operator|(
name|ALUOP
operator||
name|DIVUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* DIVIDE Unsigned              */
block|{
literal|"and"
block|,
operator|(
name|ALUOP
operator||
name|ANDF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* AND                          */
block|{
literal|"or"
block|,
operator|(
name|ALUOP
operator||
name|ORF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* OR                           */
block|{
literal|"xor"
block|,
operator|(
name|ALUOP
operator||
name|XORF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Exclusive OR                 */
block|{
literal|"sll"
block|,
operator|(
name|ALUOP
operator||
name|SLLF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* SHIFT LEFT LOGICAL           */
block|{
literal|"sra"
block|,
operator|(
name|ALUOP
operator||
name|SRAF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* SHIFT RIGHT ARITHMETIC       */
block|{
literal|"srl"
block|,
operator|(
name|ALUOP
operator||
name|SRLF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* SHIFT RIGHT LOGICAL          */
block|{
literal|"seq"
block|,
operator|(
name|ALUOP
operator||
name|SEQF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if equal                 */
block|{
literal|"sne"
block|,
operator|(
name|ALUOP
operator||
name|SNEF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if not equal             */
block|{
literal|"slt"
block|,
operator|(
name|ALUOP
operator||
name|SLTF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if less                  */
block|{
literal|"sgt"
block|,
operator|(
name|ALUOP
operator||
name|SGTF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if greater               */
block|{
literal|"sle"
block|,
operator|(
name|ALUOP
operator||
name|SLEF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if less or equal         */
block|{
literal|"sge"
block|,
operator|(
name|ALUOP
operator||
name|SGEF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if greater or equal      */
block|{
literal|"sequ"
block|,
operator|(
name|ALUOP
operator||
name|SEQUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if equal unsigned        */
block|{
literal|"sneu"
block|,
operator|(
name|ALUOP
operator||
name|SNEUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if not equal unsigned    */
block|{
literal|"sltu"
block|,
operator|(
name|ALUOP
operator||
name|SLTUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if less unsigned         */
block|{
literal|"sgtu"
block|,
operator|(
name|ALUOP
operator||
name|SGTUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if greater unsigned      */
block|{
literal|"sleu"
block|,
operator|(
name|ALUOP
operator||
name|SLEUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if less or equal unsigned*/
block|{
literal|"sgeu"
block|,
operator|(
name|ALUOP
operator||
name|SGEUF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* Set if greater or equal      */
block|{
literal|"mvts"
block|,
operator|(
name|ALUOP
operator||
name|MVTSF
operator|)
block|,
literal|"c,a"
block|}
block|,
comment|/* Move to special register     */
block|{
literal|"mvfs"
block|,
operator|(
name|ALUOP
operator||
name|MVFSF
operator|)
block|,
literal|"c,a"
block|}
block|,
comment|/* Move from special register   */
block|{
literal|"bswap"
block|,
operator|(
name|ALUOP
operator||
name|BSWAPF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* ??? Was not documented       */
block|{
literal|"lut"
block|,
operator|(
name|ALUOP
operator||
name|LUTF
operator|)
block|,
literal|"c,a,b"
block|}
block|,
comment|/* ????? same as above          */
comment|/* Arithmetic and Logical Immediate I-TYPE instructions.  */
block|{
literal|"addi"
block|,
name|ADDIOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Add Immediate                */
block|{
literal|"addui"
block|,
name|ADDUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Add Usigned Immediate        */
block|{
literal|"subi"
block|,
name|SUBIOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Sub Immediate                */
block|{
literal|"subui"
block|,
name|SUBUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Sub Unsigned Immedated       */
block|{
literal|"andi"
block|,
name|ANDIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* AND Immediate                */
block|{
literal|"ori"
block|,
name|ORIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* OR  Immediate                */
block|{
literal|"xori"
block|,
name|XORIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Exclusive OR  Immediate      */
block|{
literal|"slli"
block|,
name|SLLIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* SHIFT LEFT LOCICAL Immediate */
block|{
literal|"srai"
block|,
name|SRAIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* SHIFT RIGHT ARITH. Immediate */
block|{
literal|"srli"
block|,
name|SRLIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* SHIFT RIGHT LOGICAL Immediate*/
block|{
literal|"seqi"
block|,
name|SEQIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if equal                 */
block|{
literal|"snei"
block|,
name|SNEIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if not equal             */
block|{
literal|"slti"
block|,
name|SLTIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if less                  */
block|{
literal|"sgti"
block|,
name|SGTIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if greater               */
block|{
literal|"slei"
block|,
name|SLEIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if less or equal         */
block|{
literal|"sgei"
block|,
name|SGEIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if greater or equal      */
block|{
literal|"sequi"
block|,
name|SEQUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if equal                 */
block|{
literal|"sneui"
block|,
name|SNEUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if not equal             */
block|{
literal|"sltui"
block|,
name|SLTUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if less                  */
block|{
literal|"sgtui"
block|,
name|SGTUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if greater               */
block|{
literal|"sleui"
block|,
name|SLEUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if less or equal         */
block|{
literal|"sgeui"
block|,
name|SGEUIOP
block|,
literal|"b,a,i"
block|}
block|,
comment|/* Set if greater or equal      */
comment|/* Macros for I type instructions.  */
block|{
literal|"mov"
block|,
name|ADDIOP
block|,
literal|"b,P"
block|}
block|,
comment|/* a move macro                 */
block|{
literal|"movu"
block|,
name|ADDUIOP
block|,
literal|"b,P"
block|}
block|,
comment|/* a move macro, unsigned       */
if|#
directive|if
literal|0
comment|/* Move special.  */
block|{ "mvts",     MVTSOP,         "b,a"   },
comment|/* Move From Integer to Special */
block|{ "mvfs",     MVFSOP,         "b,a"   },
comment|/* Move From Special to Integer */
endif|#
directive|endif
comment|/* Load high Immediate I-TYPE instruction.  */
block|{
literal|"lhi"
block|,
name|LHIOP
block|,
literal|"b,i"
block|}
block|,
comment|/* Load High Immediate          */
block|{
literal|"lui"
block|,
name|LHIOP
block|,
literal|"b,i"
block|}
block|,
comment|/* Load High Immediate          */
block|{
literal|"sethi"
block|,
name|LHIOP
block|,
literal|"b,i"
block|}
block|,
comment|/* Load High Immediate          */
comment|/* LOAD/STORE BYTE 8 bits I-TYPE.  */
block|{
literal|"lb"
block|,
name|LBOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Byte                    */
block|{
literal|"lbu"
block|,
name|LBUOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Byte Unsigned           */
block|{
literal|"ldstbu"
block|,
name|LSBUOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load store Byte Unsigned     */
block|{
literal|"sb"
block|,
name|SBOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Store Byte                   */
comment|/* LOAD/STORE HALFWORD 16 bits.  */
block|{
literal|"lh"
block|,
name|LHOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Halfword                */
block|{
literal|"lhu"
block|,
name|LHUOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Halfword Unsigned       */
block|{
literal|"ldsthu"
block|,
name|LSHUOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Store Halfword Unsigned */
block|{
literal|"sh"
block|,
name|SHOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Store Halfword               */
comment|/* LOAD/STORE WORD 32 bits.  */
block|{
literal|"lw"
block|,
name|LWOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Word                    */
block|{
literal|"sw"
block|,
name|SWOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Store Word                   */
block|{
literal|"ldstw"
block|,
name|LSWOP
block|,
literal|"b,a,I"
block|}
block|,
comment|/* Load Store Word              */
comment|/* Branch PC-relative, 16 bits offset.  */
block|{
literal|"beqz"
block|,
name|BEQOP
block|,
literal|"a,d"
block|}
block|,
comment|/* Branch if a == 0             */
block|{
literal|"bnez"
block|,
name|BNEOP
block|,
literal|"a,d"
block|}
block|,
comment|/* Branch if a != 0             */
block|{
literal|"beq"
block|,
name|BEQOP
block|,
literal|"a,d"
block|}
block|,
comment|/* Branch if a == 0             */
block|{
literal|"bne"
block|,
name|BNEOP
block|,
literal|"a,d"
block|}
block|,
comment|/* Branch if a != 0             */
comment|/* Jumps Trap and RFE J-TYPE.  */
block|{
literal|"j"
block|,
name|JOP
block|,
literal|"D"
block|}
block|,
comment|/* Jump, PC-relative 26 bits    */
block|{
literal|"jal"
block|,
name|JALOP
block|,
literal|"D"
block|}
block|,
comment|/* JAL, PC-relative 26 bits     */
block|{
literal|"break"
block|,
name|BREAKOP
block|,
literal|"D"
block|}
block|,
comment|/* break to OS                  */
block|{
literal|"trap"
block|,
name|TRAPOP
block|,
literal|"D"
block|}
block|,
comment|/* TRAP to OS                   */
block|{
literal|"rfe"
block|,
name|RFEOP
block|,
literal|"N"
block|}
block|,
comment|/* Return From Exception        */
comment|/* Macros.  */
block|{
literal|"call"
block|,
name|JOP
block|,
literal|"D"
block|}
block|,
comment|/* Jump, PC-relative 26 bits    */
comment|/* Jumps Trap and RFE I-TYPE.  */
block|{
literal|"jr"
block|,
name|JROP
block|,
literal|"a"
block|}
block|,
comment|/* Jump Register, Abs (32 bits) */
block|{
literal|"jalr"
block|,
name|JALROP
block|,
literal|"a"
block|}
block|,
comment|/* JALR, Abs (32 bits)          */
comment|/* Macros.  */
block|{
literal|"retr"
block|,
name|JROP
block|,
literal|"a"
block|}
block|,
comment|/* Jump Register, Abs (32 bits) */
block|{
literal|""
block|,
literal|0x0
block|,
literal|""
block|}
comment|/* Dummy entry, not included in NUM_OPCODES. 				   This lets code examine entry i + 1 without 				   checking if we've run off the end of the table.  */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|unsigned
name|int
name|num_dlx_opcodes
init|=
operator|(
operator|(
operator|(
sizeof|sizeof
name|dlx_opcodes
operator|)
operator|/
operator|(
sizeof|sizeof
name|dlx_opcodes
index|[
literal|0
index|]
operator|)
operator|)
operator|-
literal|1
operator|)
decl_stmt|;
end_decl_stmt

end_unit

