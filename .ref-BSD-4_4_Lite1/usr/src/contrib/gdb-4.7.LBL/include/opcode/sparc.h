begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for opcode table for the sparc. 	Copyright 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler, GDB, the GNU debugger, and the GNU Binutils.   GAS/GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS/GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS or GDB; see the file COPYING.	If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.	*/
end_comment

begin_comment
comment|/* The SPARC opcode table (and other related data) is defined in    the BFD library in opc-sparc.c.  If you change anything here, make    sure you fix up that file, and vice versa.  */
end_comment

begin_comment
comment|/* FIXME-someday: perhaps the ,a's and such should be embedded in the     instruction's name rather than the args.  This would make gas faster, pinsn     slower, but would mess up some macros a bit.  xoxorich. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
specifier|const
argument_list|)
end_if

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sparc_architecture
value|bfd_sparc_architecture
end_define

begin_define
define|#
directive|define
name|architecture_pname
value|bfd_sparc_architecture_pname
end_define

begin_define
define|#
directive|define
name|sparc_opcode
value|bfd_sparc_opcode
end_define

begin_define
define|#
directive|define
name|sparc_opcodes
value|bfd_sparc_opcodes
end_define

begin_comment
comment|/*  * Structure of an opcode table entry.  * This enumerator must parallel the architecture_pname array  * in bfd/opc-sparc.c.  */
end_comment

begin_enum
enum|enum
name|sparc_architecture
block|{
name|v6
init|=
literal|0
block|,
name|v7
block|,
name|v8
block|,
name|sparclite
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|architecture_pname
index|[]
decl_stmt|;
end_decl_stmt

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
name|enum
name|sparc_architecture
name|architecture
decl_stmt|;
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

begin_comment
comment|/*  All sparc opcodes are 32 bits, except for the `set' instruction (really a macro), which is 64 bits. It is handled as a special case.  The match component is a mask saying which bits must match a particular opcode in order for an instruction to be an instance of that opcode.  The args component is a string containing one character for each operand of the instruction.  Kinds of operands: 	#	Number used by optimizer.	It is ignored. 	1	rs1 register. 	2	rs2 register. 	d	rd register. 	e	frs1 floating point register. 	v	frs1 floating point register (double/even). 	V	frs1 floating point register (quad/multiple of 4). 	f	frs2 floating point register. 	B	frs2 floating point register (double/even). 	R	frs2 floating point register (quad/multiple of 4). 	g	frsd floating point register. 	H	frsd floating point register (double/even). 	J	frsd floating point register (quad/multiple of 4). 	b	crs1 coprocessor register 	c	crs2 coprocessor register 	D	crsd coprocessor register 	m	alternate space register (asr) in rd 	M	alternate space register (asr) in rs1 	h	22 high bits. 	i	13 bit Immediate. 	n	22 bit immediate. 	l	22 bit PC relative immediate. 	L	30 bit PC relative immediate. 	a	Annul.	The annul bit is set. 	A	Alternate address space. Stored as 8 bits. 	C	Coprocessor state register. 	F	floating point state register. 	p	Processor state register. 	q	Floating point queue. 	r	Single register that is both rs1 and rsd. 	Q	Coprocessor queue. 	S	Special case. 	t	Trap base register. 	w	Window invalid mask register. 	y	Y register.  The following chars are unused: (note: ,[] are used as punctuation) [uxOUXY3450]  */
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
name|ANNUL
value|(1<<29)
end_define

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
name|bfd_sparc_num_opcodes
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NUMOPCODES
value|bfd_sparc_num_opcodes
end_define

begin_comment
comment|/*  * Local Variables:  * fill-column: 131  * comment-column: 0  * End:  */
end_comment

begin_comment
comment|/* end of sparc.h */
end_comment

end_unit

