begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for opcode table for the sparc.    Copyright 1989, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2000    Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and the GNU Binutils.  GAS/GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS/GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS or GDB; see the file COPYING.	If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_comment
comment|/* The SPARC opcode table (and other related data) is defined in    the opcodes library in sparc-opc.c.  If you change anything here, make    sure you fix up that file, and vice versa.  */
end_comment

begin_comment
comment|/* FIXME-someday: perhaps the ,a's and such should be embedded in the     instruction's name rather than the args.  This would make gas faster, pinsn     slower, but would mess up some macros a bit.  xoxorich. */
end_comment

begin_comment
comment|/* List of instruction sets variations.    These values are such that each element is either a superset of a    preceding each one or they conflict in which case SPARC_OPCODE_CONFLICT_P    returns non-zero.    The values are indices into `sparc_opcode_archs' defined in sparc-opc.c.    Don't change this without updating sparc-opc.c.  */
end_comment

begin_enum
enum|enum
name|sparc_opcode_arch_val
block|{
name|SPARC_OPCODE_ARCH_V6
init|=
literal|0
block|,
name|SPARC_OPCODE_ARCH_V7
block|,
name|SPARC_OPCODE_ARCH_V8
block|,
name|SPARC_OPCODE_ARCH_SPARCLET
block|,
name|SPARC_OPCODE_ARCH_SPARCLITE
block|,
comment|/* v9 variants must appear last */
name|SPARC_OPCODE_ARCH_V9
block|,
name|SPARC_OPCODE_ARCH_V9A
block|,
comment|/* v9 with ultrasparc additions */
name|SPARC_OPCODE_ARCH_V9B
block|,
comment|/* v9 with ultrasparc and cheetah additions */
name|SPARC_OPCODE_ARCH_BAD
comment|/* error return from sparc_opcode_lookup_arch */
block|}
enum|;
end_enum

begin_comment
comment|/* The highest architecture in the table.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OPCODE_ARCH_MAX
value|(SPARC_OPCODE_ARCH_BAD - 1)
end_define

begin_comment
comment|/* Given an enum sparc_opcode_arch_val, return the bitmask to use in    insn encoding/decoding.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OPCODE_ARCH_MASK
parameter_list|(
name|arch
parameter_list|)
value|(1<< (arch))
end_define

begin_comment
comment|/* Given a valid sparc_opcode_arch_val, return non-zero if it's v9.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OPCODE_ARCH_V9_P
parameter_list|(
name|arch
parameter_list|)
value|((arch)>= SPARC_OPCODE_ARCH_V9)
end_define

begin_comment
comment|/* Table of cpu variants.  */
end_comment

begin_struct
struct|struct
name|sparc_opcode_arch
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Mask of sparc_opcode_arch_val's supported.      EG: For v7 this would be      (SPARC_OPCODE_ARCH_MASK (..._V6) | SPARC_OPCODE_ARCH_MASK (..._V7)).      These are short's because sparc_opcode.architecture is.  */
name|short
name|supported
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_opcode_arch
name|sparc_opcode_archs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given architecture name, look up it's sparc_opcode_arch_val value.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|sparc_opcode_arch_val
name|sparc_opcode_lookup_arch
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the bitmask of supported architectures for ARCH.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OPCODE_SUPPORTED
parameter_list|(
name|ARCH
parameter_list|)
value|(sparc_opcode_archs[ARCH].supported)
end_define

begin_comment
comment|/* Non-zero if ARCH1 conflicts with ARCH2.    IE: ARCH1 as a supported bit set that ARCH2 doesn't, and vice versa.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_OPCODE_CONFLICT_P
parameter_list|(
name|ARCH1
parameter_list|,
name|ARCH2
parameter_list|)
define|\
value|(((SPARC_OPCODE_SUPPORTED (ARCH1)& SPARC_OPCODE_SUPPORTED (ARCH2)) \   != SPARC_OPCODE_SUPPORTED (ARCH1)) \&& ((SPARC_OPCODE_SUPPORTED (ARCH1)& SPARC_OPCODE_SUPPORTED (ARCH2)) \      != SPARC_OPCODE_SUPPORTED (ARCH2)))
end_define

begin_comment
comment|/* Structure of an opcode table entry.  */
end_comment

begin_struct
struct|struct
name|sparc_opcode
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|unsigned
name|long
name|match
decl_stmt|;
comment|/* Bits that must be set. */
name|unsigned
name|long
name|lose
decl_stmt|;
comment|/* Bits that must not be set. */
specifier|const
name|char
modifier|*
name|args
decl_stmt|;
comment|/* This was called "delayed" in versions before the flags. */
name|char
name|flags
decl_stmt|;
name|short
name|architecture
decl_stmt|;
comment|/* Bitmask of sparc_opcode_arch_val's.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|F_DELAYED
value|1
end_define

begin_comment
comment|/* Delayed branch */
end_comment

begin_define
define|#
directive|define
name|F_ALIAS
value|2
end_define

begin_comment
comment|/* Alias for a "real" instruction */
end_comment

begin_define
define|#
directive|define
name|F_UNBR
value|4
end_define

begin_comment
comment|/* Unconditional branch */
end_comment

begin_define
define|#
directive|define
name|F_CONDBR
value|8
end_define

begin_comment
comment|/* Conditional branch */
end_comment

begin_define
define|#
directive|define
name|F_JSR
value|16
end_define

begin_comment
comment|/* Subroutine call */
end_comment

begin_define
define|#
directive|define
name|F_FLOAT
value|32
end_define

begin_comment
comment|/* Floating point instruction (not a branch) */
end_comment

begin_define
define|#
directive|define
name|F_FBR
value|64
end_define

begin_comment
comment|/* Floating point branch */
end_comment

begin_comment
comment|/* FIXME: Add F_ANACHRONISTIC flag for v9.  */
end_comment

begin_comment
comment|/*  All sparc opcodes are 32 bits, except for the `set' instruction (really a macro), which is 64 bits. It is handled as a special case.  The match component is a mask saying which bits must match a particular opcode in order for an instruction to be an instance of that opcode.  The args component is a string containing one character for each operand of the instruction.  Kinds of operands: 	#	Number used by optimizer.	It is ignored. 	1	rs1 register. 	2	rs2 register. 	d	rd register. 	e	frs1 floating point register. 	v	frs1 floating point register (double/even). 	V	frs1 floating point register (quad/multiple of 4). 	f	frs2 floating point register. 	B	frs2 floating point register (double/even). 	R	frs2 floating point register (quad/multiple of 4). 	g	frsd floating point register. 	H	frsd floating point register (double/even). 	J	frsd floating point register (quad/multiple of 4). 	b	crs1 coprocessor register 	c	crs2 coprocessor register 	D	crsd coprocessor register 	m	alternate space register (asr) in rd 	M	alternate space register (asr) in rs1 	h	22 high bits. 	X	5 bit unsigned immediate 	Y	6 bit unsigned immediate 	3	SIAM mode (3 bits). (v9b) 	K	MEMBAR mask (7 bits). (v9) 	j	10 bit Immediate. (v9) 	I	11 bit Immediate. (v9) 	i	13 bit Immediate. 	n	22 bit immediate. 	k	2+14 bit PC relative immediate. (v9) 	G	19 bit PC relative immediate. (v9) 	l	22 bit PC relative immediate. 	L	30 bit PC relative immediate. 	a	Annul.	The annul bit is set. 	A	Alternate address space. Stored as 8 bits. 	C	Coprocessor state register. 	F	floating point state register. 	p	Processor state register. 	N	Branch predict clear ",pn" (v9) 	T	Branch predict set ",pt" (v9) 	z	%icc. (v9) 	Z	%xcc. (v9) 	q	Floating point queue. 	r	Single register that is both rs1 and rd. 	O	Single register that is both rs2 and rd. 	Q	Coprocessor queue. 	S	Special case. 	t	Trap base register. 	w	Window invalid mask register. 	y	Y register. 	u	sparclet coprocessor registers in rd position 	U	sparclet coprocessor registers in rs1 position 	E	%ccr. (v9) 	s	%fprs. (v9) 	P	%pc.  (v9) 	W	%tick.	(v9) 	o	%asi. (v9) 	6	%fcc0. (v9) 	7	%fcc1. (v9) 	8	%fcc2. (v9) 	9	%fcc3. (v9) 	!	Privileged Register in rd (v9) 	?	Privileged Register in rs1 (v9) 	*	Prefetch function constant. (v9) 	x	OPF field (v9 impdep). 	0	32/64 bit immediate for set or setx (v9) insns 	_	Ancillary state register in rd (v9a) 	/	Ancillary state register in rs1 (v9a)  The following chars are unused: (note: ,[] are used as punctuation) [45]  */
end_comment

begin_define
define|#
directive|define
name|OP2
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x7)<< 22)
end_define

begin_comment
comment|/* op2 field of format2 insns */
end_comment

begin_define
define|#
directive|define
name|OP3
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x3f)<< 19)
end_define

begin_comment
comment|/* op3 field of format3 insns */
end_comment

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|x
parameter_list|)
value|((unsigned)((x)&0x3)<< 30)
end_define

begin_comment
comment|/* op field of all insns */
end_comment

begin_define
define|#
directive|define
name|OPF
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x1ff)<< 5)
end_define

begin_comment
comment|/* opf field of float insns */
end_comment

begin_define
define|#
directive|define
name|OPF_LOW5
parameter_list|(
name|x
parameter_list|)
value|OPF((x)&0x1f)
end_define

begin_comment
comment|/* v9 */
end_comment

begin_define
define|#
directive|define
name|F3F
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(OP(x) | OP3(y) | OPF(z))
end_define

begin_comment
comment|/* format3 float insns */
end_comment

begin_define
define|#
directive|define
name|F3I
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x1)<< 13)
end_define

begin_comment
comment|/* immediate field of format 3 insns */
end_comment

begin_define
define|#
directive|define
name|F2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(OP(x) | OP2(y))
end_define

begin_comment
comment|/* format 2 insns */
end_comment

begin_define
define|#
directive|define
name|F3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|(OP(x) | OP3(y) | F3I(z))
end_define

begin_comment
comment|/* format3 insns */
end_comment

begin_define
define|#
directive|define
name|F1
parameter_list|(
name|x
parameter_list|)
value|(OP(x))
end_define

begin_define
define|#
directive|define
name|DISP30
parameter_list|(
name|x
parameter_list|)
value|((x)&0x3fffffff)
end_define

begin_define
define|#
directive|define
name|ASI
parameter_list|(
name|x
parameter_list|)
value|(((x)&0xff)<< 5)
end_define

begin_comment
comment|/* asi field of format3 insns */
end_comment

begin_define
define|#
directive|define
name|RS2
parameter_list|(
name|x
parameter_list|)
value|((x)&0x1f)
end_define

begin_comment
comment|/* rs2 field */
end_comment

begin_define
define|#
directive|define
name|SIMM13
parameter_list|(
name|x
parameter_list|)
value|((x)&0x1fff)
end_define

begin_comment
comment|/* simm13 field */
end_comment

begin_define
define|#
directive|define
name|RD
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x1f)<< 25)
end_define

begin_comment
comment|/* destination register field */
end_comment

begin_define
define|#
directive|define
name|RS1
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x1f)<< 14)
end_define

begin_comment
comment|/* rs1 field */
end_comment

begin_define
define|#
directive|define
name|ASI_RS2
parameter_list|(
name|x
parameter_list|)
value|(SIMM13(x))
end_define

begin_define
define|#
directive|define
name|MEMBAR
parameter_list|(
name|x
parameter_list|)
value|((x)&0x7f)
end_define

begin_define
define|#
directive|define
name|SLCPOP
parameter_list|(
name|x
parameter_list|)
value|(((x)&0x7f)<< 6)
end_define

begin_comment
comment|/* sparclet cpop */
end_comment

begin_define
define|#
directive|define
name|ANNUL
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|BPRED
value|(1<<19)
end_define

begin_comment
comment|/* v9 */
end_comment

begin_define
define|#
directive|define
name|IMMED
value|F3I(1)
end_define

begin_define
define|#
directive|define
name|RD_G0
value|RD(~0)
end_define

begin_define
define|#
directive|define
name|RS1_G0
value|RS1(~0)
end_define

begin_define
define|#
directive|define
name|RS2_G0
value|RS2(~0)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|sparc_opcode
name|sparc_opcodes
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|sparc_num_opcodes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_encode_asi
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_decode_asi
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_encode_membar
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_decode_membar
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_encode_prefetch
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_decode_prefetch
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparc_encode_sparclet_cpreg
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_decode_sparclet_cpreg
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Local Variables:  * fill-column: 131  * comment-column: 0  * End:  */
end_comment

begin_comment
comment|/* end of sparc.h */
end_comment

end_unit

