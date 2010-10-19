begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Table of opcodes for the Motorola M88k family.    Copyright 1989, 1990, 1991, 1993, 2001, 2002    Free Software Foundation, Inc.  This file is part of GDB and GAS.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/*  *			Disassembler Instruction Table  *  *	The first field of the table is the opcode field. If an opcode  *	is specified which has any non-opcode bits on, a system error  *	will occur when the system attempts the install it into the  *	instruction table.  The second parameter is a pointer to the  *	instruction mnemonic. Each operand is specified by offset, width,  *	and type. The offset is the bit number of the least significant  *	bit of the operand with bit 0 being the least significant bit of  *	the instruction. The width is the number of bits used to specify  *	the operand. The type specifies the output format to be used for  *	the operand. The valid formats are: register, register indirect,  *	hex constant, and bit field specification.  The last field is a  *	pointer to the next instruction in the linked list.  These pointers  *	are initialized by init_disasm().  *  *				Revision History  *  *	Revision 1.0	11/08/85	Creation date  *		 1.1	02/05/86	Updated instruction mnemonic table MD  *		 1.2	06/16/86	Updated SIM_FLAGS for floating point  *		 1.3	09/20/86	Updated for new encoding  *		 	05/11/89	R. Trawick adapted from Motorola disassembler  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Define the number of bits in the primary opcode field of the instruction,    the destination field, the source 1 and source 2 fields.  */
end_comment

begin_comment
comment|/* Size of opcode field.  */
end_comment

begin_define
define|#
directive|define
name|OP
value|8
end_define

begin_comment
comment|/* Size of destination.  */
end_comment

begin_define
define|#
directive|define
name|DEST
value|6
end_define

begin_comment
comment|/* Size of source1.  */
end_comment

begin_define
define|#
directive|define
name|SOURCE1
value|6
end_define

begin_comment
comment|/* Size of source2.  */
end_comment

begin_define
define|#
directive|define
name|SOURCE2
value|6
end_define

begin_comment
comment|/* Number of registers.  */
end_comment

begin_define
define|#
directive|define
name|REGs
value|32
end_define

begin_comment
comment|/* Type definitions.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|UINT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|WORD
value|long
end_define

begin_define
define|#
directive|define
name|FLAG
value|unsigned
end_define

begin_define
define|#
directive|define
name|STATE
value|short
end_define

begin_comment
comment|/* The next four equates define the priorities that the various classes  * of instructions have regarding writing results back into registers and  * signalling exceptions.  */
end_comment

begin_comment
comment|/* PMEM is also defined in<sys/param.h> on Delta 88's.  Sigh!  */
end_comment

begin_undef
undef|#
directive|undef
name|PMEM
end_undef

begin_comment
comment|/* Integer priority.  */
end_comment

begin_define
define|#
directive|define
name|PINT
value|0
end_define

begin_comment
comment|/* Floating point priority.  */
end_comment

begin_define
define|#
directive|define
name|PFLT
value|1
end_define

begin_comment
comment|/* Memory priority.  */
end_comment

begin_define
define|#
directive|define
name|PMEM
value|2
end_define

begin_comment
comment|/* Not applicable, instruction doesn't write to regs.  */
end_comment

begin_define
define|#
directive|define
name|NA
value|3
end_define

begin_comment
comment|/* Highest of these priorities.  */
end_comment

begin_define
define|#
directive|define
name|HIPRI
value|3
end_define

begin_comment
comment|/* The instruction registers are an artificial mechanism to speed up  * simulator execution.  In the real processor, an instruction register  * is 32 bits wide.  In the simulator, the 32 bit instruction is kept in  * a structure field called rawop, and the instruction is partially decoded,  * and split into various fields and flags which make up the other fields  * of the structure.  * The partial decode is done when the instructions are initially loaded  * into simulator memory.  The simulator code memory is not an array of  * 32 bit words, but is an array of instruction register structures.  * Yes this wastes memory, but it executes much quicker.  */
end_comment

begin_struct
struct|struct
name|IR_FIELDS
block|{
name|unsigned
name|op
range|:
name|OP
decl_stmt|,
name|dest
range|:
name|DEST
decl_stmt|,
name|src1
range|:
name|SOURCE1
decl_stmt|,
name|src2
range|:
name|SOURCE2
decl_stmt|;
name|int
name|ltncy
decl_stmt|,
name|extime
decl_stmt|,
comment|/* Writeback priority.  */
name|wb_pri
decl_stmt|;
comment|/* Immediate size.  */
name|unsigned
name|imm_flags
range|:
literal|2
decl_stmt|,
comment|/* Register source 1 used.  */
name|rs1_used
range|:
literal|1
decl_stmt|,
comment|/* Register source 2 used. */
name|rs2_used
range|:
literal|1
decl_stmt|,
comment|/* Register source/dest. used.  */
name|rsd_used
range|:
literal|1
decl_stmt|,
comment|/* Complement.  */
name|c_flag
range|:
literal|1
decl_stmt|,
comment|/* Upper half word.  */
name|u_flag
range|:
literal|1
decl_stmt|,
comment|/* Execute next.  */
name|n_flag
range|:
literal|1
decl_stmt|,
comment|/* Uses writeback slot.  */
name|wb_flag
range|:
literal|1
decl_stmt|,
comment|/* Dest size.  */
name|dest_64
range|:
literal|1
decl_stmt|,
comment|/* Source 1 size.  */
name|s1_64
range|:
literal|1
decl_stmt|,
comment|/* Source 2 size.  */
name|s2_64
range|:
literal|1
decl_stmt|,
name|scale_flag
range|:
literal|1
decl_stmt|,
comment|/* Scaled register.  */
name|brk_flg
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mem_segs
block|{
comment|/* Pointer (returned by calloc) to segment.  */
name|struct
name|mem_wrd
modifier|*
name|seg
decl_stmt|;
comment|/* Base load address from file headers.  */
name|unsigned
name|long
name|baseaddr
decl_stmt|;
comment|/* Ending address of segment.  */
name|unsigned
name|long
name|endaddr
decl_stmt|;
comment|/* Segment control flags (none defined).  */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXSEGS
value|(10)
end_define

begin_comment
comment|/* max number of segment allowed */
end_comment

begin_define
define|#
directive|define
name|MEMSEGSIZE
value|(sizeof(struct mem_segs))
end_define

begin_comment
comment|/* size of mem_segs structure */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BRK_RD
value|(0x01)
end_define

begin_comment
comment|/* break on memory read */
end_comment

begin_define
define|#
directive|define
name|BRK_WR
value|(0x02)
end_define

begin_comment
comment|/* break on memory write */
end_comment

begin_define
define|#
directive|define
name|BRK_EXEC
value|(0x04)
end_define

begin_comment
comment|/* break on execution */
end_comment

begin_define
define|#
directive|define
name|BRK_CNT
value|(0x08)
end_define

begin_comment
comment|/* break on terminal count */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|mem_wrd
block|{
comment|/* Simulator instruction break down.  */
name|struct
name|IR_FIELDS
name|opcode
decl_stmt|;
union|union
block|{
comment|/* Memory element break down.  */
name|unsigned
name|long
name|l
decl_stmt|;
name|unsigned
name|short
name|s
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|c
index|[
literal|4
index|]
decl_stmt|;
block|}
name|mem
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* Size of each 32 bit memory model.  */
end_comment

begin_define
define|#
directive|define
name|MEMWRDSIZE
value|(sizeof (struct mem_wrd))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|mem_segs
name|memory
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|PROCESSOR
name|m78000
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|PROCESSOR
block|{
name|unsigned
name|WORD
comment|/* Execute instruction pointer.  */
name|ip
decl_stmt|,
comment|/* Vector base register.  */
name|vbr
decl_stmt|,
comment|/* Processor status register.  */
name|psr
decl_stmt|;
comment|/* Source 1.  */
name|WORD
name|S1bus
decl_stmt|,
comment|/* Source 2.  */
name|S2bus
decl_stmt|,
comment|/* Destination.  */
name|Dbus
decl_stmt|,
comment|/* Data address bus.  */
name|DAbus
decl_stmt|,
name|ALU
decl_stmt|,
comment|/* Data registers.  */
name|Regs
index|[
name|REGs
index|]
decl_stmt|,
comment|/* Max clocks before reg is available.  */
name|time_left
index|[
name|REGs
index|]
decl_stmt|,
comment|/* Writeback priority of reg.  */
name|wb_pri
index|[
name|REGs
index|]
decl_stmt|,
comment|/* Integer unit control regs.  */
name|SFU0_regs
index|[
name|REGs
index|]
decl_stmt|,
comment|/* Floating point control regs.  */
name|SFU1_regs
index|[
name|REGs
index|]
decl_stmt|,
name|Scoreboard
index|[
name|REGs
index|]
decl_stmt|,
name|Vbr
decl_stmt|;
name|unsigned
name|WORD
name|scoreboard
decl_stmt|,
name|Psw
decl_stmt|,
name|Tpsw
decl_stmt|;
comment|/* Waiting for a jump instruction.  */
name|FLAG
name|jump_pending
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Size of immediate field.  */
end_comment

begin_define
define|#
directive|define
name|i26bit
value|1
end_define

begin_define
define|#
directive|define
name|i16bit
value|2
end_define

begin_define
define|#
directive|define
name|i10bit
value|3
end_define

begin_comment
comment|/* Definitions for fields in psr.  */
end_comment

begin_define
define|#
directive|define
name|psr_mode
value|31
end_define

begin_define
define|#
directive|define
name|psr_rbo
value|30
end_define

begin_define
define|#
directive|define
name|psr_ser
value|29
end_define

begin_define
define|#
directive|define
name|psr_carry
value|28
end_define

begin_define
define|#
directive|define
name|psr_sf7m
value|11
end_define

begin_define
define|#
directive|define
name|psr_sf6m
value|10
end_define

begin_define
define|#
directive|define
name|psr_sf5m
value|9
end_define

begin_define
define|#
directive|define
name|psr_sf4m
value|8
end_define

begin_define
define|#
directive|define
name|psr_sf3m
value|7
end_define

begin_define
define|#
directive|define
name|psr_sf2m
value|6
end_define

begin_define
define|#
directive|define
name|psr_sf1m
value|5
end_define

begin_define
define|#
directive|define
name|psr_mam
value|4
end_define

begin_define
define|#
directive|define
name|psr_inm
value|3
end_define

begin_define
define|#
directive|define
name|psr_exm
value|2
end_define

begin_define
define|#
directive|define
name|psr_trm
value|1
end_define

begin_define
define|#
directive|define
name|psr_ovfm
value|0
end_define

begin_comment
comment|/* The 1 clock operations.  */
end_comment

begin_define
define|#
directive|define
name|ADDU
value|1
end_define

begin_define
define|#
directive|define
name|ADDC
value|2
end_define

begin_define
define|#
directive|define
name|ADDUC
value|3
end_define

begin_define
define|#
directive|define
name|ADD
value|4
end_define

begin_define
define|#
directive|define
name|SUBU
value|ADD+1
end_define

begin_define
define|#
directive|define
name|SUBB
value|ADD+2
end_define

begin_define
define|#
directive|define
name|SUBUB
value|ADD+3
end_define

begin_define
define|#
directive|define
name|SUB
value|ADD+4
end_define

begin_define
define|#
directive|define
name|AND_
value|ADD+5
end_define

begin_define
define|#
directive|define
name|OR
value|ADD+6
end_define

begin_define
define|#
directive|define
name|XOR
value|ADD+7
end_define

begin_define
define|#
directive|define
name|CMP
value|ADD+8
end_define

begin_comment
comment|/* Loads.  */
end_comment

begin_define
define|#
directive|define
name|LDAB
value|CMP+1
end_define

begin_define
define|#
directive|define
name|LDAH
value|CMP+2
end_define

begin_define
define|#
directive|define
name|LDA
value|CMP+3
end_define

begin_define
define|#
directive|define
name|LDAD
value|CMP+4
end_define

begin_define
define|#
directive|define
name|LDB
value|LDAD+1
end_define

begin_define
define|#
directive|define
name|LDH
value|LDAD+2
end_define

begin_define
define|#
directive|define
name|LD
value|LDAD+3
end_define

begin_define
define|#
directive|define
name|LDD
value|LDAD+4
end_define

begin_define
define|#
directive|define
name|LDBU
value|LDAD+5
end_define

begin_define
define|#
directive|define
name|LDHU
value|LDAD+6
end_define

begin_comment
comment|/* Stores.  */
end_comment

begin_define
define|#
directive|define
name|STB
value|LDHU+1
end_define

begin_define
define|#
directive|define
name|STH
value|LDHU+2
end_define

begin_define
define|#
directive|define
name|ST
value|LDHU+3
end_define

begin_define
define|#
directive|define
name|STD
value|LDHU+4
end_define

begin_comment
comment|/* Exchange.  */
end_comment

begin_define
define|#
directive|define
name|XMEMBU
value|LDHU+5
end_define

begin_define
define|#
directive|define
name|XMEM
value|LDHU+6
end_define

begin_comment
comment|/* Branches.  */
end_comment

begin_define
define|#
directive|define
name|JSR
value|STD+1
end_define

begin_define
define|#
directive|define
name|BSR
value|STD+2
end_define

begin_define
define|#
directive|define
name|BR
value|STD+3
end_define

begin_define
define|#
directive|define
name|JMP
value|STD+4
end_define

begin_define
define|#
directive|define
name|BB1
value|STD+5
end_define

begin_define
define|#
directive|define
name|BB0
value|STD+6
end_define

begin_define
define|#
directive|define
name|RTN
value|STD+7
end_define

begin_define
define|#
directive|define
name|BCND
value|STD+8
end_define

begin_comment
comment|/* Traps.  */
end_comment

begin_define
define|#
directive|define
name|TB1
value|BCND+1
end_define

begin_define
define|#
directive|define
name|TB0
value|BCND+2
end_define

begin_define
define|#
directive|define
name|TCND
value|BCND+3
end_define

begin_define
define|#
directive|define
name|RTE
value|BCND+4
end_define

begin_define
define|#
directive|define
name|TBND
value|BCND+5
end_define

begin_comment
comment|/* Misc.  */
end_comment

begin_define
define|#
directive|define
name|MUL
value|TBND + 1
end_define

begin_define
define|#
directive|define
name|DIV
value|MUL  +2
end_define

begin_define
define|#
directive|define
name|DIVU
value|MUL  +3
end_define

begin_define
define|#
directive|define
name|MASK
value|MUL  +4
end_define

begin_define
define|#
directive|define
name|FF0
value|MUL  +5
end_define

begin_define
define|#
directive|define
name|FF1
value|MUL  +6
end_define

begin_define
define|#
directive|define
name|CLR
value|MUL  +7
end_define

begin_define
define|#
directive|define
name|SET
value|MUL  +8
end_define

begin_define
define|#
directive|define
name|EXT
value|MUL  +9
end_define

begin_define
define|#
directive|define
name|EXTU
value|MUL  +10
end_define

begin_define
define|#
directive|define
name|MAK
value|MUL  +11
end_define

begin_define
define|#
directive|define
name|ROT
value|MUL  +12
end_define

begin_comment
comment|/* Control register manipulations.  */
end_comment

begin_define
define|#
directive|define
name|LDCR
value|ROT  +1
end_define

begin_define
define|#
directive|define
name|STCR
value|ROT  +2
end_define

begin_define
define|#
directive|define
name|XCR
value|ROT  +3
end_define

begin_define
define|#
directive|define
name|FLDCR
value|ROT  +4
end_define

begin_define
define|#
directive|define
name|FSTCR
value|ROT  +5
end_define

begin_define
define|#
directive|define
name|FXCR
value|ROT  +6
end_define

begin_define
define|#
directive|define
name|NOP
value|XCR +1
end_define

begin_comment
comment|/* Floating point instructions.  */
end_comment

begin_define
define|#
directive|define
name|FADD
value|NOP +1
end_define

begin_define
define|#
directive|define
name|FSUB
value|NOP +2
end_define

begin_define
define|#
directive|define
name|FMUL
value|NOP +3
end_define

begin_define
define|#
directive|define
name|FDIV
value|NOP +4
end_define

begin_define
define|#
directive|define
name|FSQRT
value|NOP +5
end_define

begin_define
define|#
directive|define
name|FCMP
value|NOP +6
end_define

begin_define
define|#
directive|define
name|FIP
value|NOP +7
end_define

begin_define
define|#
directive|define
name|FLT
value|NOP +8
end_define

begin_define
define|#
directive|define
name|INT
value|NOP +9
end_define

begin_define
define|#
directive|define
name|NINT
value|NOP +10
end_define

begin_define
define|#
directive|define
name|TRNC
value|NOP +11
end_define

begin_define
define|#
directive|define
name|FLDC
value|NOP +12
end_define

begin_define
define|#
directive|define
name|FSTC
value|NOP +13
end_define

begin_define
define|#
directive|define
name|FXC
value|NOP +14
end_define

begin_define
define|#
directive|define
name|UEXT
parameter_list|(
name|src
parameter_list|,
name|off
parameter_list|,
name|wid
parameter_list|)
define|\
value|((((unsigned int)(src))>> (off))& ((1<< (wid)) - 1))
end_define

begin_define
define|#
directive|define
name|SEXT
parameter_list|(
name|src
parameter_list|,
name|off
parameter_list|,
name|wid
parameter_list|)
define|\
value|(((((int)(src))<<(32 - ((off) + (wid))))>>(32 - (wid))) )
end_define

begin_define
define|#
directive|define
name|MAKE
parameter_list|(
name|src
parameter_list|,
name|off
parameter_list|,
name|wid
parameter_list|)
define|\
value|((((unsigned int)(src))& ((1<< (wid)) - 1))<< (off))
end_define

begin_define
define|#
directive|define
name|opword
parameter_list|(
name|n
parameter_list|)
value|(unsigned long) (memaddr->mem.l)
end_define

begin_comment
comment|/* Constants and masks.  */
end_comment

begin_define
define|#
directive|define
name|SFU0
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SFU1
value|0x84000000
end_define

begin_define
define|#
directive|define
name|SFU7
value|0x9c000000
end_define

begin_define
define|#
directive|define
name|RRI10
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|RRR
value|0xf4000000
end_define

begin_define
define|#
directive|define
name|SFUMASK
value|0xfc00ffe0
end_define

begin_define
define|#
directive|define
name|RRRMASK
value|0xfc00ffe0
end_define

begin_define
define|#
directive|define
name|RRI10MASK
value|0xfc00fc00
end_define

begin_define
define|#
directive|define
name|DEFMASK
value|0xfc000000
end_define

begin_define
define|#
directive|define
name|CTRL
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|CTRLMASK
value|0xfc00f800
end_define

begin_comment
comment|/* Operands types.  */
end_comment

begin_enum
enum|enum
name|operand_type
block|{
name|HEX
init|=
literal|1
block|,
name|REG
init|=
literal|2
block|,
name|CONT
init|=
literal|3
block|,
name|IND
init|=
literal|3
block|,
name|BF
init|=
literal|4
block|,
comment|/* Scaled register.  */
name|REGSC
init|=
literal|5
block|,
comment|/* Control register.  */
name|CRREG
init|=
literal|6
block|,
comment|/* Floating point control register.  */
name|FCRREG
init|=
literal|7
block|,
name|PCREL
init|=
literal|8
block|,
name|CONDMASK
init|=
literal|9
block|,
comment|/* Extended register.  */
name|XREG
init|=
literal|10
block|,
comment|/* Decimal.  */
name|DEC
init|=
literal|11
block|}
enum|;
end_enum

begin_comment
comment|/* Hashing specification.  */
end_comment

begin_define
define|#
directive|define
name|HASHVAL
value|79
end_define

begin_comment
comment|/* Structure templates.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|width
decl_stmt|;
name|enum
name|operand_type
name|type
decl_stmt|;
block|}
name|OPSPEC
typedef|;
end_typedef

begin_struct
struct|struct
name|SIM_FLAGS
block|{
name|int
name|ltncy
decl_stmt|,
comment|/* latency (max number of clocks needed to execute).  */
name|extime
decl_stmt|,
comment|/* execution time (min number of clocks needed to execute).  */
name|wb_pri
decl_stmt|;
comment|/* writeback slot priority.  */
name|unsigned
name|op
range|:
name|OP
decl_stmt|,
comment|/* simulator version of opcode.  */
name|imm_flags
range|:
literal|2
decl_stmt|,
comment|/* 10,16 or 26 bit immediate flags.  */
name|rs1_used
range|:
literal|1
decl_stmt|,
comment|/* register source 1 used.  */
name|rs2_used
range|:
literal|1
decl_stmt|,
comment|/* register source 2 used.  */
name|rsd_used
range|:
literal|1
decl_stmt|,
comment|/* register source/dest used.  */
name|c_flag
range|:
literal|1
decl_stmt|,
comment|/* complement.  */
name|u_flag
range|:
literal|1
decl_stmt|,
comment|/* upper half word.  */
name|n_flag
range|:
literal|1
decl_stmt|,
comment|/* execute next.  */
name|wb_flag
range|:
literal|1
decl_stmt|,
comment|/* uses writeback slot.  */
name|dest_64
range|:
literal|1
decl_stmt|,
comment|/* double precision dest.  */
name|s1_64
range|:
literal|1
decl_stmt|,
comment|/* double precision source 1.  */
name|s2_64
range|:
literal|1
decl_stmt|,
comment|/* double precision source 2.  */
name|scale_flag
range|:
literal|1
decl_stmt|;
comment|/* register is scaled.  */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|INSTRUCTAB
block|{
name|unsigned
name|int
name|opcode
decl_stmt|;
name|char
modifier|*
name|mnemonic
decl_stmt|;
name|OPSPEC
name|op1
decl_stmt|,
name|op2
decl_stmt|,
name|op3
decl_stmt|;
name|struct
name|SIM_FLAGS
name|flgs
decl_stmt|;
block|}
name|INSTAB
typedef|;
end_typedef

begin_escape
end_escape

begin_define
define|#
directive|define
name|NO_OPERAND
value|{0,0,0}
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|INSTAB
name|instructions
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local Variables:  * fill-column: 131  * End:  */
end_comment

end_unit

