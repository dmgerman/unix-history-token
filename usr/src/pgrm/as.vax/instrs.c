begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|##
end_empty

begin_empty
empty|## Copyright (c) 1982 Regents of the University of California.
end_empty

begin_empty
empty|## All rights reserved.  The Berkeley software License Agreement
end_empty

begin_empty
empty|## specifies the terms and conditions for redistribution.
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	@(#)instrs	5.1 (Berkeley) 4/30/85
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	Robert R. Henry
end_empty

begin_empty
empty|##	University of California, Berkeley
end_empty

begin_empty
empty|##	Berkeley, CA
end_empty

begin_empty
empty|##	February 6, 1982
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	Updated 19 May 83 to include the page number in the
end_empty

begin_empty
empty|##	architecture reference manual (1981 edition) the instruction
end_empty

begin_empty
empty|##	is documented on, and to enumerate the instructions in the same
end_empty

begin_empty
empty|##	order as the reference manual does.
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	THIS FILE IS BOTH AN AWK SCRIPT AND THE DATA
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	Instruction definitions for the VAX
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	This file is processed by an awk script, viz:
end_empty

begin_empty
empty|##	(echo "FLAVOR AS"; cat instrs) | awk -f instrs> as.instrs
end_empty

begin_empty
empty|##	(echo "FLAVOR ADB"; cat instrs) | awk -f instrs> as.instrs
end_empty

begin_empty
empty|##	(echo "FLAVOR SDB"; cat instrs) | awk -f instrs> as.instrs
end_empty

begin_empty
empty|##	(echo "FLAVOR C2"; cat instrs) | awk -f instrs> c2.instrs
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	The data in this file is shared between:
end_empty

begin_empty
empty|##	as	assembler
end_empty

begin_empty
empty|##	c2	optimizer
end_empty

begin_empty
empty|##	adb	debugger
end_empty

begin_empty
empty|##	sdb	symbolic debugger
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	The awk script reads itself, and produces macros understood
end_empty

begin_empty
empty|##	by the appropriate consumer. The awk script determines how
end_empty

begin_empty
empty|##	to interpret the file by looking for a line of the form:
end_empty

begin_empty
empty|##	FLAVOR	AS
end_empty

begin_empty
empty|##	FLAVOR	ADB		(same as AS, but without pseudo instructions)
end_empty

begin_empty
empty|##	FLAVOR	SDB		(same as ADB)
end_empty

begin_empty
empty|##	FLAVOR	C2		(radically different format for instructions)
end_empty

begin_empty
empty|##	and proceeding accordingly.  This line should be prepended to
end_empty

begin_empty
empty|##	the front of this file.
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	Lines starting with # are always comments to awk
end_empty

begin_empty
empty|##	Lines starting with ## are always comments
end_empty

begin_empty
empty|##	Lines starting with a single # are data lines, to be output.
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	Empty lines are passed through
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	field	user(s)		what
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$2	awk		#: comment to awk
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$3	as, c2, adb	instruction name
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$4	c2		instruction class
end_empty

begin_empty
empty|##	$5	c2		instruction sub class
end_empty

begin_empty
empty|##				HARD, TN1, TN2, TN3, TNX2, OP
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$6	as, adb		escape opcode byte (NONE, NEW, ESCD, ESCF)
end_empty

begin_empty
empty|##	$7	as, adb		primary opcode byte
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$8	as, adb		number of arguments
end_empty

begin_empty
empty|##	$9	as, adb		1st operand: access A,V,R,W,M,I,B
end_empty

begin_empty
empty|##	$10	as, adb		1st operand: type, BWLQOFDGH
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	$11	as, adb		2nd operand: access
end_empty

begin_empty
empty|##		...
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	These are the definitions used in this file:
end_empty

begin_empty
empty|##	instruction class (c2)
end_empty

begin_empty
empty|##		understood only by c2.  If it is HARD, the second field
end_empty

begin_empty
empty|##		is ignored.
end_empty

begin_empty
empty|##	instruction subclass: (c2)
end_empty

begin_empty
empty|##		HARD		paired with the class
end_empty

begin_empty
empty|##		S		single valued attribute to C2
end_empty

begin_empty
empty|##		TN1		class + type of 1st operand
end_empty

begin_empty
empty|##		TN2		class + type of 2nd operand
end_empty

begin_empty
empty|##		TN3		class + type of 3rd operand
end_empty

begin_empty
empty|##		TNX2		class + type of 1st and 2nd operand
end_empty

begin_empty
empty|##		OP		class + type of 1st operand and # of args
end_empty

begin_empty
empty|##		default		class + subclass
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	escape byte:
end_empty

begin_empty
empty|##		CORE		1 byte opcodes in all VAXen
end_empty

begin_empty
empty|##		NEW		1 byte opcodes only in newer VAXen
end_empty

begin_empty
empty|##		ESCD		2 byte opcodes, escape byte of 0xFD, newer VAXen
end_empty

begin_empty
empty|##		ESCF		2 byte opcodes, escape byte of 0xFF, newer VAXen
end_empty

begin_empty
empty|##	code byte
end_empty

begin_empty
empty|##	number of arguments
end_empty

begin_empty
empty|##	Access type
end_empty

begin_empty
empty|##		A		for address, only in memory
end_empty

begin_empty
empty|##		V		for address [sic], either in memory or register
end_empty

begin_empty
empty|##		W		for writing
end_empty

begin_empty
empty|##		R		for reading
end_empty

begin_empty
empty|##		M		for modifying
end_empty

begin_empty
empty|##		B		for branch displacement
end_empty

begin_empty
empty|##		I		for xfc code
end_empty

begin_empty
empty|##	Data types
end_empty

begin_empty
empty|##		B	byte
end_empty

begin_empty
empty|##		W	word
end_empty

begin_empty
empty|##		L	long
end_empty

begin_empty
empty|##		Q	quad
end_empty

begin_empty
empty|##		O	octa
end_empty

begin_empty
empty|##		F	f_float
end_empty

begin_empty
empty|##		D	d_float
end_empty

begin_empty
empty|##		G	g_float
end_empty

begin_empty
empty|##		H	h_float
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	The order of instructions in this table is not critical;
end_empty

begin_empty
empty|##	the clients take care of their own table construction and ordering.
end_empty

begin_empty
empty|##	The instructions are grouped (more or less) into functional groups.
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##	The following is the awk program to interpret this table.
end_empty

begin_macro
name|BEGIN
end_macro

begin_block
block|{
name|flavor
operator|=
name|AS
expr_stmt|;
empty|##
empty|##	magic padding before the string for AS
empty|##	4 bytes of 0's: seek position of the string
empty|##	2 bytes, value 2, indicating core resident
empty|##	2 bytes, value 0, length
empty|##
name|ASpad
operator|=
literal|"\\0\\0\\0\\0"
literal|"\\2\\0"
expr_stmt|;
block|}
end_block

begin_block
block|{
if|if
condition|(
name|NF
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$1
operator|==
literal|"FLAVOR"
condition|)
block|{
name|flavor
operator|=
name|$2
expr_stmt|;
if|if
condition|(
name|flavor
operator|==
literal|"SDB"
condition|)
block|{
name|flavor
operator|=
literal|"ADB"
expr_stmt|;
block|}
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$1
operator|!=
literal|"#"
condition|)
block|{
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$6
operator|==
literal|"MACR"
condition|)
block|{
if|if
condition|(
name|flavor
operator|==
literal|"ADB"
condition|)
block|{
name|next
expr_stmt|;
block|}
if|if
condition|(
name|flavor
operator|==
literal|"AS"
condition|)
block|{
if|if
condition|(
name|$4
operator|==
literal|"CBR"
condition|)
name|$4
operator|=
literal|"IJXXX"
expr_stmt|;
name|printf
argument_list|(
literal|"PSEUDO(\"%s\\0%o\\0%s\","
argument_list|,
name|ASpad
argument_list|,
name|length
argument_list|(
name|$3
argument_list|)
argument_list|,
name|$3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s, %s),\n"
argument_list|,
name|$7
argument_list|,
name|$4
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|flavor
operator|==
literal|"C2"
condition|)
block|{
if|if
condition|(
name|$5
operator|==
literal|"C2X"
condition|)
name|next
expr_stmt|;
name|printf
argument_list|(
literal|"\"%s\","
argument_list|,
name|$3
argument_list|)
expr_stmt|;
if|if
condition|(
name|$4
operator|==
literal|"CBR"
operator|&&
name|$5
operator|!=
literal|"JBR"
condition|)
block|{
name|printf
argument_list|(
literal|"T(CBR,%s),\n"
argument_list|,
name|$5
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"%s,\n"
argument_list|,
name|$5
argument_list|)
expr_stmt|;
block|}
name|next
expr_stmt|;
block|}
block|}
if|if
condition|(
name|flavor
operator|==
literal|"C2"
condition|)
block|{
name|printf
argument_list|(
literal|"\"%s\","
argument_list|,
name|$3
argument_list|)
expr_stmt|;
if|if
condition|(
name|$4
operator|==
literal|"HARD"
condition|)
block|{
operator|#
literal|0
name|value
name|printf
argument_list|(
literal|"0,\n"
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$5
operator|==
literal|"S"
condition|)
block|{
operator|#
name|single
name|value
name|printf
argument_list|(
literal|"%s,\n"
argument_list|,
name|$4
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$5
operator|==
literal|"TN1"
condition|)
block|{
operator|#
name|use
name|type
name|of
literal|1st
name|operand
name|printf
argument_list|(
literal|"T(%s,TYP%s),\n"
argument_list|,
name|$4
argument_list|,
name|$10
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$5
operator|==
literal|"TN3"
condition|)
block|{
operator|#
name|use
name|type
name|of
literal|3rd
name|operand
name|printf
argument_list|(
literal|"T(%s,TYP%s),\n"
argument_list|,
name|$4
argument_list|,
name|$14
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$5
operator|==
literal|"TNX2"
condition|)
block|{
operator|#
name|cross
name|product
name|of
literal|1st
name|and
literal|2nd
name|operand
name|printf
argument_list|(
literal|"T(%s,U(TYP%s,TYP%s)),\n"
argument_list|,
name|$4
argument_list|,
name|$10
argument_list|,
name|$12
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
if|if
condition|(
name|$5
operator|==
literal|"OP"
condition|)
block|{
operator|#
name|arithmetic
name|operator
name|printf
argument_list|(
literal|"T(%s,U(TYP%s,OP%d)),\n"
argument_list|,
name|$4
argument_list|,
name|$10
argument_list|,
name|$8
argument_list|)
expr_stmt|;
name|next
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"T(%s,%s),\n"
argument_list|,
name|$4
argument_list|,
name|$5
argument_list|)
expr_stmt|;
operator|#
name|special
name|value
name|next
expr_stmt|;
block|}
if|if
condition|(
name|flavor
operator|==
literal|"AS"
condition|)
block|{
name|printf
argument_list|(
literal|"OP(\"%s\\0%o\\0%s\", "
argument_list|,
name|ASpad
argument_list|,
name|length
argument_list|(
name|$3
argument_list|)
argument_list|,
name|$3
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s, %s, %d"
argument_list|,
name|$6
argument_list|,
name|$7
argument_list|,
name|$8
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"OP(\"%s\", %s, %s, %d"
argument_list|,
name|$3
argument_list|,
name|$6
argument_list|,
name|$7
argument_list|,
name|$8
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|flavor
operator|==
literal|"AS"
operator|||
name|flavor
operator|==
literal|"ADB"
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|9
init|;
name|i
operator|+
literal|1
operator|<=
name|NF
condition|;
name|i
operator|=
name|i
operator|+
literal|2
control|)
block|{
name|printf
argument_list|(
literal|", A_%s%s"
argument_list|,
name|$i
argument_list|,
name|$
argument_list|(
name|i
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
name|$8
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
block|{
name|printf
argument_list|(
literal|",0"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"),\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_empty
empty|##
end_empty

begin_empty
empty|##-------------------------------------------------------
end_empty

begin_empty
empty|##1 2		3     4  	5    6	        7  8 9
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|## PSEUDO (MACR) operators come first
end_empty

begin_empty
empty|## Data initializers
end_empty

begin_empty
empty|# 000a .byte	IBYTE	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000b .word	IWORD	WGEN	MACR 0		VAR
end_empty

begin_empty
empty|# 000c .int	IINT	LGEN	MACR 0		VAR
end_empty

begin_empty
empty|# 000d .long	ILONG	LGEN	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .quad	IQUAD	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .octa	IOCTA	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .float	IFFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .double	IDFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .ffloat	IFFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .dfloat	IDFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .gfloat	IGFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .hfloat	IHFLOAT	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .space	ISPACE	C2X	MACR 0		1
end_empty

begin_empty
empty|# 000a .fill	IFILL	C2X	MACR 0		2
end_empty

begin_empty
empty|# 000a .ascii	IASCII	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .asciz	IASCIZ	C2X	MACR 0		VAR
end_empty

begin_empty
empty|# 000a .data	IDATA	DATA	MACR 0		1
end_empty

begin_empty
empty|# 000a .text	ITEXT	TEXT	MACR 0		1
end_empty

begin_empty
empty|# 000a .align	IALIGN	ALIGN	MACR 0		1
end_empty

begin_empty
empty|# 000a .line	ILINENO	C2X	MACR 0		1
end_empty

begin_empty
empty|# 000a .file	IFILE	C2X	MACR 0		1
end_empty

begin_empty
empty|# 000a .globl	IGLOBAL	EROU	MACR 0		1
end_empty

begin_empty
empty|# 000a .comm	ICOMM	COMM	MACR 0		2
end_empty

begin_empty
empty|# 000a .lcomm	ILCOMM	LCOMM	MACR 0		2
end_empty

begin_empty
empty|# 000a .set	ISET	SET	MACR 0		2
end_empty

begin_empty
empty|# 000a .lsym	ILSYM	C2X	MACR 0		2
end_empty

begin_empty
empty|# 000a .org	IORG	C2X	MACR 0		1
end_empty

begin_empty
empty|# 000a .stab	ISTAB	C2X	MACR 0		6
end_empty

begin_empty
empty|# 000a .stabd	ISTABDOT	C2X	MACR 0	3
end_empty

begin_empty
empty|# 000a .stabn	ISTABNONE	C2X	MACR 0	3
end_empty

begin_empty
empty|# 000a .stabs	ISTABSTR	C2X	MACR 0	3
end_empty

begin_empty
empty|# 000a .ABORT	IABORT	C2X	MACR 0		0
end_empty

begin_empty
empty|## Pseudo jumps
end_empty

begin_empty
empty|# 000a jbc	CBR	JBC	MACR 0xe1	1	B B
end_empty

begin_empty
empty|# 000a jlbc	CBR	JLBC	MACR 0xe9	1	B B
end_empty

begin_empty
empty|# 000a jbs	CBR	JBS	MACR 0xe0	1	B B
end_empty

begin_empty
empty|# 000a jlbs	CBR	JLBS	MACR 0xe8	1	B B
end_empty

begin_empty
empty|# 000a jbcc	CBR	JBCC	MACR 0xe5	1	B B
end_empty

begin_empty
empty|# 000a jbsc	CBR	JBSC	MACR 0xe4	1	B B
end_empty

begin_empty
empty|# 000a jbcs	CBR	JBCS	MACR 0xe3	1	B B
end_empty

begin_empty
empty|# 000a jbss	CBR	JBSS	MACR 0xe2	1	B B
end_empty

begin_empty
empty|# 000a jbr	CBR	JBR	MACR 0x11	1	B B
end_empty

begin_empty
empty|# 000a jcc	CBR	C2X	MACR 0x1e	1	B B
end_empty

begin_empty
empty|# 000a jcs	CBR	C2X	MACR 0x1f	1	B B
end_empty

begin_empty
empty|# 000a jvc	CBR	C2X	MACR 0x1c	1	B B
end_empty

begin_empty
empty|# 000a jvs	CBR	C2X	MACR 0x1d	1	B B
end_empty

begin_empty
empty|# 000a jlss	CBR	JLT	MACR 0x19	1	B B
end_empty

begin_empty
empty|# 000a jlssu	CBR	JLO	MACR 0x1f	1	B B
end_empty

begin_empty
empty|# 000a jleq	CBR	JLE	MACR 0x15	1	B B
end_empty

begin_empty
empty|# 000a jlequ	CBR	JLOS	MACR 0x1b	1	B B
end_empty

begin_empty
empty|# 000a jeql	CBR	JEQ	MACR 0x13	1	B B
end_empty

begin_empty
empty|# 000a jeqlu	CBR	JEQ	MACR 0x13	1	B B
end_empty

begin_empty
empty|# 000a jneq	CBR	JNE	MACR 0x12	1	B B
end_empty

begin_empty
empty|# 000a jnequ	CBR	JNE	MACR 0x12	1	B B
end_empty

begin_empty
empty|# 000a jgeq	CBR	JGE	MACR 0x18	1	B B
end_empty

begin_empty
empty|# 000a jgequ	CBR	JHIS	MACR 0x1e	1	B B
end_empty

begin_empty
empty|# 000a jgtr	CBR	JGT	MACR 0x14	1	B B
end_empty

begin_empty
empty|# 000a jgtru	CBR	JHI	MACR 0x1a	1	B B
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|## Registers
end_empty

begin_empty
empty|##
end_empty

begin_empty
empty|# 000a r0	REG	C2X	MACR 0		0
end_empty

begin_empty
empty|# 000a r1	REG	C2X	MACR 1		0
end_empty

begin_empty
empty|# 000a r2	REG	C2X	MACR 2		0
end_empty

begin_empty
empty|# 000a r3	REG	C2X	MACR 3		0
end_empty

begin_empty
empty|# 000a r4	REG	C2X	MACR 4		0
end_empty

begin_empty
empty|# 000a r5	REG	C2X	MACR 5		0
end_empty

begin_empty
empty|# 000a r6	REG	C2X	MACR 6		0
end_empty

begin_empty
empty|# 000a r7	REG	C2X	MACR 7		0
end_empty

begin_empty
empty|# 000a r8	REG	C2X	MACR 8		0
end_empty

begin_empty
empty|# 000a r9	REG	C2X	MACR 9		0
end_empty

begin_empty
empty|# 000a r10	REG	C2X	MACR 10		0
end_empty

begin_empty
empty|# 000a r11	REG	C2X	MACR 11		0
end_empty

begin_empty
empty|# 000a r12	REG	C2X	MACR 12		0
end_empty

begin_empty
empty|# 000a r13	REG	C2X	MACR 13		0
end_empty

begin_empty
empty|# 000a r14	REG	C2X	MACR 14		0
end_empty

begin_empty
empty|# 000a r15	REG	C2X	MACR 15		0
end_empty

begin_empty
empty|# 000a ap	REG	C2X	MACR 12		0
end_empty

begin_empty
empty|# 000a fp	REG	C2X	MACR 13		0
end_empty

begin_empty
empty|# 000a sp	REG	C2X	MACR 14		0
end_empty

begin_empty
empty|# 000a pc	REG	C2X	MACR 15		0
end_empty

begin_empty
empty|## Normal instructions
end_empty

begin_empty
empty|# 158a chmk	HARD HARD	CORE 0xbc	1  R W
end_empty

begin_empty
empty|# 158b chme	HARD HARD	CORE 0xbd	1  R W
end_empty

begin_empty
empty|# 158c chms	HARD HARD	CORE 0xbe	1  R W
end_empty

begin_empty
empty|# 158d chmu	HARD HARD	CORE 0xbf	1  R W
end_empty

begin_empty
empty|# 160a prober	PROBER TN1	CORE 0x0c	3  R B  R W  A B
end_empty

begin_empty
empty|# 160a probew	PROBEW TN1	CORE 0x0d	3  R B  R W  A B
end_empty

begin_empty
empty|# 161a rei	HARD HARD	CORE 0x02	0
end_empty

begin_empty
empty|# 163a ldpctx	HARD HARD	CORE 0x06	0
end_empty

begin_empty
empty|# 163b svpctx	HARD HARD	CORE 0x07	0
end_empty

begin_empty
empty|# 165a mtpr	MTPR TN1	CORE 0xda	2  R L  R L
end_empty

begin_empty
empty|# 165b mfpr	MFPR TN1	CORE 0xdb	2  R L  W L
end_empty

begin_empty
empty|# 168a xfc	HARD HARD	CORE 0xfc	0
end_empty

begin_empty
empty|# 169a bpt	HARD HARD	CORE 0x03	0
end_empty

begin_empty
empty|# 170a bugw	HARD HARD	ESCF 0xfe	1  R W
end_empty

begin_empty
empty|# 170b bugl	HARD HARD	ESCF 0xfd	1  R L
end_empty

begin_empty
empty|# 171a halt	HARD HARD	CORE 0x00	0
end_empty

begin_empty
empty|# 179a movb	MOV TN1		CORE 0x90	2  R B  W B
end_empty

begin_empty
empty|# 179b movw	MOV TN1		CORE 0xb0	2  R W  W W
end_empty

begin_empty
empty|# 179c movl	MOV TN1		CORE 0xd0	2  R L  W L
end_empty

begin_empty
empty|# 179d movq	MOV TN1		CORE 0x7d	2  R Q  W Q
end_empty

begin_empty
empty|# 179e movo	MOV TN1		ESCD 0x7d	2  R O  W O
end_empty

begin_empty
empty|# 179f movf	MOV TN1		CORE 0x50	2  R F  W F
end_empty

begin_empty
empty|# 179g movd	MOV TN1		CORE 0x70	2  R D  W D
end_empty

begin_empty
empty|# 179h movg	MOV TN1		ESCD 0x50	2  R G  W G
end_empty

begin_empty
empty|# 179i movh	MOV TN1		ESCD 0x70	2  R H  W H
end_empty

begin_empty
empty|# 180a pushl	PUSH TN1	CORE 0xdd	1  R L
end_empty

begin_empty
empty|# 181a clrb	CLR TN1		CORE 0x94	1  W B
end_empty

begin_empty
empty|# 181b clrw	CLR TN1		CORE 0xb4	1  W W
end_empty

begin_empty
empty|# 181c clrf	CLR TN1		CORE 0xd4	1  W F
end_empty

begin_empty
empty|# 181c clrl	CLR TN1		CORE 0xd4	1  W L
end_empty

begin_empty
empty|# 181d clrd	CLR TN1		CORE 0x7c	1  W D
end_empty

begin_empty
empty|# 181d clrg	CLR TN1		CORE 0x7c	1  W G
end_empty

begin_empty
empty|# 181d clrq	CLR TN1		CORE 0x7c	1  W Q
end_empty

begin_empty
empty|# 181e clrh	CLR TN1		ESCD 0x7c	1  W H
end_empty

begin_empty
empty|# 181e clro	CLR TN1		ESCD 0x7c	1  W O
end_empty

begin_empty
empty|# 182a mnegb	NEG TN1		CORE 0x8e	2  R B  W B
end_empty

begin_empty
empty|# 182b mnegw	NEG TN1		CORE 0xae	2  R W  W W
end_empty

begin_empty
empty|# 182c mnegl	NEG TN1		CORE 0xce	2  R L  W L
end_empty

begin_empty
empty|# 182d mnegf	NEG TN1		CORE 0x52	2  R F  W F
end_empty

begin_empty
empty|# 182e mnegg	NEG TN1		ESCD 0x52	2  R G  W G
end_empty

begin_empty
empty|# 182f mnegd	NEG TN1		CORE 0x72	2  R D  W D
end_empty

begin_empty
empty|# 182g mnegh	NEG TN1		ESCD 0x72	2  R H  W H
end_empty

begin_empty
empty|# 183a mcomb	COM TN1		CORE 0x92	2  R B  W B
end_empty

begin_empty
empty|# 183b mcomw	COM TN1		CORE 0xb2	2  R W  W W
end_empty

begin_empty
empty|# 183c mcoml	COM TN1		CORE 0xd2	2  R L  W L
end_empty

begin_empty
empty|# 184A cvtbw	CVT TNX2	CORE 0x99	2  R B  W W
end_empty

begin_empty
empty|# 184B cvtbl	CVT TNX2	CORE 0x98	2  R B  W L
end_empty

begin_empty
empty|# 184C cvtwb	CVT TNX2	CORE 0x33	2  R W  W B
end_empty

begin_empty
empty|# 184D cvtwl	CVT TNX2	CORE 0x32	2  R W  W L
end_empty

begin_empty
empty|# 184E cvtlb	CVT TNX2	CORE 0xf6	2  R L  W B
end_empty

begin_empty
empty|# 184F cvtlw	CVT TNX2	CORE 0xf7	2  R L  W W
end_empty

begin_empty
empty|# 184G cvtbf	CVT TNX2	CORE 0x4c	2  R B  W F
end_empty

begin_empty
empty|# 184H cvtbd	CVT TNX2	CORE 0x6c	2  R B  W D
end_empty

begin_empty
empty|# 184I cvtbg	CVT TNX2	ESCD 0x4c	2  R B  W G
end_empty

begin_empty
empty|# 184J cvtbh	CVT TNX2	ESCD 0x6c	2  R B  W H
end_empty

begin_empty
empty|# 184K cvtwf	CVT TNX2	CORE 0x4d	2  R W  W F
end_empty

begin_empty
empty|# 184L cvtwd	CVT TNX2	CORE 0x6d	2  R W  W D
end_empty

begin_empty
empty|# 184M cvtwg	CVT TNX2	ESCD 0x4d	2  R W  W G
end_empty

begin_empty
empty|# 184N cvtwh	CVT TNX2	ESCD 0x6d	2  R W  W H
end_empty

begin_empty
empty|# 184O cvtlf	CVT TNX2	CORE 0x4e	2  R L  W F
end_empty

begin_empty
empty|# 184P cvtld	CVT TNX2	CORE 0x6e	2  R L  W D
end_empty

begin_empty
empty|# 184Q cvtlg	CVT TNX2	ESCD 0x4e	2  R L  W G
end_empty

begin_empty
empty|# 184R cvtlh	CVT TNX2	ESCD 0x6e	2  R L  W H
end_empty

begin_empty
empty|# 184S cvtfb	CVT TNX2	CORE 0x48	2  R F  W B
end_empty

begin_empty
empty|# 184T cvtdb	CVT TNX2	CORE 0x68	2  R D  W B
end_empty

begin_empty
empty|# 184U cvtgb	CVT TNX2	ESCD 0x48	2  R G  W B
end_empty

begin_empty
empty|# 184V cvthb	CVT TNX2	ESCD 0x68	2  R H  W B
end_empty

begin_empty
empty|# 184W cvtfw	CVT TNX2	CORE 0x49	2  R F  W W
end_empty

begin_empty
empty|# 184X cvtdw	CVT TNX2	CORE 0x69	2  R D  W W
end_empty

begin_empty
empty|# 184Y cvtgw	CVT TNX2	ESCD 0x49	2  R G  W W
end_empty

begin_empty
empty|# 184Z cvthw	CVT TNX2	ESCD 0x69	2  R H  W W
end_empty

begin_empty
empty|# 184a cvtfl	CVT TNX2	CORE 0x4a	2  R F  W L
end_empty

begin_empty
empty|# 184b cvtrfl	CVT TNX2	CORE 0x4b	2  R F  W L
end_empty

begin_empty
empty|# 184c cvtdl	CVT TNX2	CORE 0x6a	2  R D  W L
end_empty

begin_empty
empty|# 184d cvtrdl	CVT TNX2	CORE 0x6b	2  R D  W L
end_empty

begin_empty
empty|# 184e cvtgl	CVT TNX2	ESCD 0x4a	2  R G  W L
end_empty

begin_empty
empty|# 184f cvtrgl	CVT TNX2	ESCD 0x4b	2  R G  W L
end_empty

begin_empty
empty|# 184g cvthl	CVT TNX2	ESCD 0x6a	2  R H  W L
end_empty

begin_empty
empty|# 184h cvtrhl	CVT TNX2	ESCD 0x6b	2  R H  W L
end_empty

begin_empty
empty|# 184i cvtfd	CVT TNX2	CORE 0x56	2  R F  W D
end_empty

begin_empty
empty|# 184j cvtfg	CVT TNX2	ESCD 0x99	2  R F  W G
end_empty

begin_empty
empty|# 184k cvtfh	CVT TNX2	ESCD 0x98	2  R F  W H
end_empty

begin_empty
empty|# 184l cvtdf	CVT TNX2	CORE 0x76	2  R D  W F
end_empty

begin_empty
empty|# 184m cvtdh	CVT TNX2	ESCD 0x32	2  R D  W H
end_empty

begin_empty
empty|# 184n cvtgf	CVT TNX2	ESCD 0x33	2  R G  W F
end_empty

begin_empty
empty|# 184o cvtgh	CVT TNX2	ESCD 0x56	2  R G  W H
end_empty

begin_empty
empty|# 184p cvthf	CVT TNX2	ESCD 0xf6	2  R H  W F
end_empty

begin_empty
empty|# 184q cvthd	CVT TNX2	ESCD 0xf7	2  R H  W D
end_empty

begin_empty
empty|# 184r cvthg	CVT TNX2	ESCD 0x76	2  R H  W G
end_empty

begin_empty
empty|# 187a movzbw	MOVZ TNX2	CORE 0x9b	2  R B  W W
end_empty

begin_empty
empty|# 187b movzbl	MOVZ TNX2	CORE 0x9a	2  R B  W L
end_empty

begin_empty
empty|# 187c movzwl	MOVZ TNX2	CORE 0x3c	2  R W  W L
end_empty

begin_empty
empty|# 188a cmpb	CMP TN1		CORE 0x91	2  R B  R B
end_empty

begin_empty
empty|# 188b cmpw	CMP TN1		CORE 0xb1	2  R W  R W
end_empty

begin_empty
empty|# 188c cmpl	CMP TN1		CORE 0xd1	2  R L  R L
end_empty

begin_empty
empty|# 188d cmpf	CMP TN1		CORE 0x51	2  R F  R F
end_empty

begin_empty
empty|# 188e cmpd	CMP TN1		CORE 0x71	2  R D  R D
end_empty

begin_empty
empty|# 188f cmpg	CMP TN1		ESCD 0x51	2  R G  R G
end_empty

begin_empty
empty|# 188g cmph	CMP TN1		ESCD 0x71	2  R H  R H
end_empty

begin_empty
empty|# 189a incb	INC TN1		CORE 0x96	1  M B
end_empty

begin_empty
empty|# 189b incw	INC TN1		CORE 0xb6	1  M W
end_empty

begin_empty
empty|# 189c incl	INC TN1		CORE 0xd6	1  M L
end_empty

begin_empty
empty|# 190a tstb	TST TN1		CORE 0x95	1  R B
end_empty

begin_empty
empty|# 190b tstw	TST TN1		CORE 0xb5	1  R W
end_empty

begin_empty
empty|# 190c tstl	TST TN1		CORE 0xd5	1  R L
end_empty

begin_empty
empty|# 190d tstf	TST TN1		CORE 0x53	1  R F
end_empty

begin_empty
empty|# 190e tstd	TST TN1		CORE 0x73	1  R D
end_empty

begin_empty
empty|# 190g tstg	TST TN1		ESCD 0x53	1  R G
end_empty

begin_empty
empty|# 190h tsth	TST TN1		ESCD 0x73	1  R H
end_empty

begin_empty
empty|# 191a addb2	ADD OP		CORE 0x80	2  R B  M B
end_empty

begin_empty
empty|# 191a addh2	ADD OP		ESCD 0x60	2  R H  M H
end_empty

begin_empty
empty|# 191b addb3	ADD OP		CORE 0x81	3  R B  R B  W B
end_empty

begin_empty
empty|# 191b addh3	ADD OP		ESCD 0x61	3  R H  R H  W H
end_empty

begin_empty
empty|# 191c addw2	ADD OP		CORE 0xa0	2  R W  M W
end_empty

begin_empty
empty|# 191d addw3	ADD OP		CORE 0xa1	3  R W  R W  W W
end_empty

begin_empty
empty|# 191e addl2	ADD OP		CORE 0xc0	2  R L  M L
end_empty

begin_empty
empty|# 191f addl3	ADD OP		CORE 0xc1	3  R L  R L  W L
end_empty

begin_empty
empty|# 191g addf2	ADD OP		CORE 0x40	2  R F  M F
end_empty

begin_empty
empty|# 191h addf3	ADD OP		CORE 0x41	3  R F  R F  W F
end_empty

begin_empty
empty|# 191i addd2	ADD OP		CORE 0x60	2  R D  M D
end_empty

begin_empty
empty|# 191j addd3	ADD OP		CORE 0x61	3  R D  R D  W D
end_empty

begin_empty
empty|# 191k addg2	ADD OP		ESCD 0x40	2  R G  M G
end_empty

begin_empty
empty|# 191l addg3	ADD OP		ESCD 0x41	3  R G  R G  W G
end_empty

begin_empty
empty|# 193a adwc	HARD HARD	CORE 0xd8	2  R L  M L
end_empty

begin_empty
empty|# 194a adawi	HARD HARD	CORE 0x58	2  R W  M W
end_empty

begin_empty
empty|# 195c subb2	SUB OP		CORE 0x82	2  R B  M B
end_empty

begin_empty
empty|# 195d subb3	SUB OP		CORE 0x83	3  R B  R B  W B
end_empty

begin_empty
empty|# 195e subw2	SUB OP		CORE 0xa2	2  R W  M W
end_empty

begin_empty
empty|# 195f subw3	SUB OP		CORE 0xa3	3  R W  R W  W W
end_empty

begin_empty
empty|# 195g subl2	SUB OP		CORE 0xc2	2  R L  M L
end_empty

begin_empty
empty|# 195h subl3	SUB OP		CORE 0xc3	3  R L  R L  W L
end_empty

begin_empty
empty|# 195i subf2	SUB OP		CORE 0x42	2  R F  M F
end_empty

begin_empty
empty|# 195j subf3	SUB OP		CORE 0x43	3  R F  R F  W F
end_empty

begin_empty
empty|# 195k subd2	SUB OP		CORE 0x62	2  R D  M D
end_empty

begin_empty
empty|# 195l subd3	SUB OP		CORE 0x63	3  R D  R D  W D
end_empty

begin_empty
empty|# 195m subg2	SUB OP		ESCD 0x42	2  R G  M G
end_empty

begin_empty
empty|# 195n subg3	SUB OP		ESCD 0x43	3  R G  R G  W G
end_empty

begin_empty
empty|# 195o subh2	SUB OP		ESCD 0x62	2  R H  M H
end_empty

begin_empty
empty|# 195p subh3	SUB OP		ESCD 0x63	3  R H  R H  W H
end_empty

begin_empty
empty|# 197a decb	DEC TN1		CORE 0x97	1  M B
end_empty

begin_empty
empty|# 197b decw	DEC TN1		CORE 0xb7	1  M W
end_empty

begin_empty
empty|# 197c decl	DEC TN1		CORE 0xd7	1  M L
end_empty

begin_empty
empty|# 198a sbwc	HARD HARD	CORE 0xd9	2  R L  M L
end_empty

begin_empty
empty|# 199a mulb2	MUL OP		CORE 0x84	2  R B  M B
end_empty

begin_empty
empty|# 199b mulb3	MUL OP		CORE 0x85	3  R B  R B  W B
end_empty

begin_empty
empty|# 199c mulw2	MUL OP		CORE 0xa4	2  R W  M W
end_empty

begin_empty
empty|# 199d mulw3	MUL OP		CORE 0xa5	3  R W  R W  W W
end_empty

begin_empty
empty|# 199e mull2	MUL OP		CORE 0xc4	2  R L  M L
end_empty

begin_empty
empty|# 199f mull3	MUL OP		CORE 0xc5	3  R L  R L  W L
end_empty

begin_empty
empty|# 199g mulf2	MUL OP		CORE 0x44	2  R F  M F
end_empty

begin_empty
empty|# 199h mulf3	MUL OP		CORE 0x45	3  R F  R F  W F
end_empty

begin_empty
empty|# 199i muld2	MUL OP		CORE 0x64	2  R D  M D
end_empty

begin_empty
empty|# 199j muld3	MUL OP		CORE 0x65	3  R D  R D  W D
end_empty

begin_empty
empty|# 199k mulg2	MUL OP		ESCD 0x44	2  R G  M G
end_empty

begin_empty
empty|# 199l mulg3	MUL OP		ESCD 0x45	3  R G  R G  W G
end_empty

begin_empty
empty|# 199m mulh2	MUL OP		ESCD 0x64	2  R H  M H
end_empty

begin_empty
empty|# 199n mulh3	MUL OP		ESCD 0x65	3  R H  R H  W H
end_empty

begin_empty
empty|# 201a emodf	HARD HARD	CORE 0x54	5  R F  R B  R F  W L  W F
end_empty

begin_empty
empty|# 201a emul	HARD HARD	CORE 0x7a	4  R L  R L  R L  W Q
end_empty

begin_empty
empty|# 201b emodd	HARD HARD	CORE 0x74	5  R D  R B  R D  W L  W D
end_empty

begin_empty
empty|# 201c emodg	HARD HARD	ESCD 0x54	5  R G  R W  R G  W L  W G
end_empty

begin_empty
empty|# 201d emodh	HARD HARD	ESCD 0x74	5  R H  R W  R H  W L  W H
end_empty

begin_empty
empty|# 204a divb2	DIV OP		CORE 0x86	2  R B  M B
end_empty

begin_empty
empty|# 204b divb3	DIV OP		CORE 0x87	3  R B  R B  W B
end_empty

begin_empty
empty|# 204c divw2	DIV OP		CORE 0xa6	2  R W  M W
end_empty

begin_empty
empty|# 204d divw3	DIV OP		CORE 0xa7	3  R W  R W  W W
end_empty

begin_empty
empty|# 204e divl2	DIV OP		CORE 0xc6	2  R L  M L
end_empty

begin_empty
empty|# 204f divl3	DIV OP		CORE 0xc7	3  R L  R L  W L
end_empty

begin_empty
empty|# 204g divf2	DIV OP		CORE 0x46	2  R F  M F
end_empty

begin_empty
empty|# 204h divf3	DIV OP		CORE 0x47	3  R F  R F  W F
end_empty

begin_empty
empty|# 204i divd2	DIV OP		CORE 0x66	2  R D  M D
end_empty

begin_empty
empty|# 204j divd3	DIV OP		CORE 0x67	3  R D  R D  R D
end_empty

begin_empty
empty|# 204k divg2	DIV OP		ESCD 0x46	2  R G  M G
end_empty

begin_empty
empty|# 204l divg3	DIV OP		ESCD 0x47	3  R G  R G  W G
end_empty

begin_empty
empty|# 204m divh2	DIV OP		ESCD 0x66	2  R H  M H
end_empty

begin_empty
empty|# 204n divh3	DIV OP		ESCD 0x67	3  R H  R H  R H
end_empty

begin_empty
empty|# 205a ediv	HARD HARD	CORE 0x7b	4  R L  R Q  W L  W L
end_empty

begin_empty
empty|# 207a bitb	BIT TN1		CORE 0x93	2  R B  R B
end_empty

begin_empty
empty|# 207a bitl	BIT TN1		CORE 0xd3	2  R L  R L
end_empty

begin_empty
empty|# 207a bitw	BIT TN1		CORE 0xb3	2  R W  R W
end_empty

begin_empty
empty|# 208a bisb2	BIS OP		CORE 0x88	2  R B  M B
end_empty

begin_empty
empty|# 208b bisb3	BIS OP		CORE 0x89	3  R B  R B  W B
end_empty

begin_empty
empty|# 208c bisw2	BIS OP		CORE 0xa8	2  R W  M W
end_empty

begin_empty
empty|# 208d bisw3	BIS OP		CORE 0xa9	3  R W  R W  W W
end_empty

begin_empty
empty|# 208e bisl2	BIS OP		CORE 0xc8	2  R L  M L
end_empty

begin_empty
empty|# 208f bisl3	BIS OP		CORE 0xc9	3  R L  R L  W L
end_empty

begin_empty
empty|# 209a bicb2	BIC OP		CORE 0x8a	2  R B  M B
end_empty

begin_empty
empty|# 209b bicb3	BIC OP		CORE 0x8b	3  R B  R B  W B
end_empty

begin_empty
empty|# 209c bicw2	BIC OP		CORE 0xaa	2  R W  M W
end_empty

begin_empty
empty|# 209d bicw3	BIC OP		CORE 0xab	3  R W  R W  W W
end_empty

begin_empty
empty|# 209e bicl2	BIC OP		CORE 0xca	2  R L  M L
end_empty

begin_empty
empty|# 209f bicl3	BIC OP		CORE 0xcb	3  R L  R L  W L
end_empty

begin_empty
empty|# 210a xorb2	XOR OP		CORE 0x8c	2  R B  M B
end_empty

begin_empty
empty|# 210b xorb3	XOR OP		CORE 0x8d	3  R B  R B  W B
end_empty

begin_empty
empty|# 210c xorw2	XOR OP		CORE 0xac	2  R W  M W
end_empty

begin_empty
empty|# 210d xorw3	XOR OP		CORE 0xad	3  R W  R W  W W
end_empty

begin_empty
empty|# 210e xorl2	XOR OP		CORE 0xcc	2  R L  M L
end_empty

begin_empty
empty|# 210f xorl3	XOR OP		CORE 0xcd	3  R L  R L  W L
end_empty

begin_empty
empty|# 211a ashl	ASH TN3		CORE 0x78	3  R B  R L  W L
end_empty

begin_empty
empty|# 211b ashq	ASH TN3		CORE 0x79	3  R B  R Q  W Q
end_empty

begin_empty
empty|# 212a rotl	HARD HARD	CORE 0x9c	3  R B  R L  W L
end_empty

begin_empty
empty|# 214a polyf	HARD HARD	CORE 0x55	3  R F  R W  A B
end_empty

begin_empty
empty|# 214b polyd	HARD HARD	CORE 0x75	3  R D  R W  A B
end_empty

begin_empty
empty|# 214c polyg	HARD HARD	ESCD 0x55	3  R G  R W  A B
end_empty

begin_empty
empty|# 214d polyh	HARD HARD	ESCD 0x75	3  R H  R W  A B
end_empty

begin_empty
empty|# 220a pushr	HARD HARD	CORE 0xbb	1  R W
end_empty

begin_empty
empty|# 221a popr	HARD HARD	CORE 0xba	1  R W
end_empty

begin_empty
empty|# 222a movpsl	HARD HARD	CORE 0xdc	1  W L
end_empty

begin_empty
empty|# 223a bispsw	HARD HARD	CORE 0xb8	1  R W
end_empty

begin_empty
empty|# 223b bicpsw	HARD HARD	CORE 0xb9	1  R W
end_empty

begin_empty
empty|# 224a movab	MOVA TN1	CORE 0x9e	2  A B  W L
end_empty

begin_empty
empty|# 224a pushab	PUSHA TN1	CORE 0x9f	1  A B
end_empty

begin_empty
empty|# 224b movaw	MOVA TN1	CORE 0x3e	2  A W  W L
end_empty

begin_empty
empty|# 224b pushaw	PUSHA TN1	CORE 0x3f	1  A W
end_empty

begin_empty
empty|# 224c movaf	MOVA TN1	CORE 0xde	2  A F  W L
end_empty

begin_empty
empty|# 224c moval	MOVA TN1	CORE 0xde	2  A L  W L
end_empty

begin_empty
empty|# 224c pushaf	PUSHA TN1	CORE 0xdf	1  A F
end_empty

begin_empty
empty|# 224c pushal	PUSHA TN1	CORE 0xdf	1  A L
end_empty

begin_empty
empty|# 224d pushad	PUSHA TN1	CORE 0x7f	1  A D
end_empty

begin_empty
empty|# 224d pushag	PUSHA TN1	CORE 0x7f	1  A G
end_empty

begin_empty
empty|# 224d pushaq	PUSHA TN1	CORE 0x7f	1  A Q
end_empty

begin_empty
empty|# 224e pushah	PUSHA TN1	ESCD 0x7f	1  A H
end_empty

begin_empty
empty|# 224e pushao	PUSHA TN1	ESCD 0x7f	1  A O
end_empty

begin_empty
empty|# 224f movad	MOVA TN1	CORE 0x7e	2  A D  W L
end_empty

begin_empty
empty|# 224f movag	MOVA TN1	CORE 0x7e	2  A G  W L
end_empty

begin_empty
empty|# 224f movaq	MOVA TN1	CORE 0x7e	2  A Q  W L
end_empty

begin_empty
empty|# 224g movah	MOVA TN1	ESCD 0x7e	2  A H  W L
end_empty

begin_empty
empty|# 224g movao	MOVA TN1	ESCD 0x7e	2  A O  W L
end_empty

begin_empty
empty|# 226a index	HARD HARD	CORE 0x0a	6  R L  R L  R L  R L  R L  W L
end_empty

begin_empty
empty|# 232a insque	HARD HARD	CORE 0x0e	2  A B  A B
end_empty

begin_empty
empty|# 234a remque	HARD HARD	CORE 0x0f	2  A B  W L
end_empty

begin_empty
empty|# 240a insqhi	HARD HARD	NEW  0x5c	2  A B  A Q
end_empty

begin_empty
empty|# 241a insqti	HARD HARD	NEW  0x5d	2  A B  A Q
end_empty

begin_empty
empty|# 245a remqhi	HARD HARD	NEW  0x5e	2  A Q  W L
end_empty

begin_empty
empty|# 248a remqti	HARD HARD	NEW  0x5f	2  A Q  W L
end_empty

begin_empty
empty|# 251a ffc	HARD HARD	CORE 0xeb	4  R L  R B  V B  W L
end_empty

begin_empty
empty|# 251b ffs	HARD HARD	CORE 0xea	4  R L  R B  V B  W L
end_empty

begin_empty
empty|# 253a extv	EXTV TN1	CORE 0xee	4  R L  R B  V B  W L
end_empty

begin_empty
empty|# 253b extzv	EXTZV TN1	CORE 0xef	4  R L  R B  V B  W L
end_empty

begin_empty
empty|# 255a cmpv	HARD HARD	CORE 0xec	4  R L  R B  V B  R L
end_empty

begin_empty
empty|# 255b cmpzv	HARD HARD	CORE 0xed	4  R L  R B  V B  R L
end_empty

begin_empty
empty|# 257a insv	INSV -1		CORE 0xf0	4  R L  R L  R B  V B
end_empty

begin_empty
empty|# 261a bneq	CBR JNE		CORE 0x12	1  B B
end_empty

begin_empty
empty|# 261b bnequ	CBR JNE		CORE 0x12	1  B B
end_empty

begin_empty
empty|# 261c beql	CBR JEQ		CORE 0x13	1  B B
end_empty

begin_empty
empty|# 261d beqlu	CBR JEQ		CORE 0x13	1  B B
end_empty

begin_empty
empty|# 261e bgtr	CBR JGT		CORE 0x14	1  B B
end_empty

begin_empty
empty|# 261f bleq	CBR JLE		CORE 0x15	1  B B
end_empty

begin_empty
empty|# 261g bgeq	CBR JGE		CORE 0x18	1  B B
end_empty

begin_empty
empty|# 261h blss	CBR JLT		CORE 0x19	1  B B
end_empty

begin_empty
empty|# 261i bgtru	CBR JHI		CORE 0x1a	1  B B
end_empty

begin_empty
empty|# 261j blequ	CBR JLOS	CORE 0x1b	1  B B
end_empty

begin_empty
empty|# 261k bvc	CBR 0		CORE 0x1c	1  B B
end_empty

begin_empty
empty|# 261l bvs	CBR 0		CORE 0x1d	1  B B
end_empty

begin_empty
empty|# 261m bgequ	CBR JHIS	CORE 0x1e	1  B B
end_empty

begin_empty
empty|# 261n bcc	CBR JHIS	CORE 0x1e	1  B B
end_empty

begin_empty
empty|# 261o blssu	CBR JLO		CORE 0x1f	1  B B
end_empty

begin_empty
empty|# 261p bcs	CBR JLO		CORE 0x1f	1  B B
end_empty

begin_empty
empty|# 263a brb	JBR S		CORE 0x11	1  B B
end_empty

begin_empty
empty|# 263b brw	JBR S		CORE 0x31	1  B W
end_empty

begin_empty
empty|# 263c jmp	JMP S		CORE 0x17	1  A B
end_empty

begin_empty
empty|# 264a bbs	CBR JBS		CORE 0xe0	3  R L  V B  B B
end_empty

begin_empty
empty|# 264b bbc	CBR JBC		CORE 0xe1	3  R L  V B  B B
end_empty

begin_empty
empty|# 265a bbss	CBR JBSS	CORE 0xe2	3  R L  V B  B B
end_empty

begin_empty
empty|# 265b bbcs	CBR JBCS	CORE 0xe3	3  R L  V B  B B
end_empty

begin_empty
empty|# 265c bbsc	CBR JBSC	CORE 0xe4	3  R L  V B  B B
end_empty

begin_empty
empty|# 265d bbcc	CBR JBCC	CORE 0xe5	3  R L  V B  B B
end_empty

begin_empty
empty|# 266a bbssi	CBR JBSS	CORE 0xe6	3  R L  V B  B B
end_empty

begin_empty
empty|# 266b bbcci	CBR JBCC	CORE 0xe7	3  R L  V B  B B
end_empty

begin_empty
empty|# 267a blbs	CBR JLBS	CORE 0xe8	2  R L  B B
end_empty

begin_empty
empty|# 267b blbc	CBR JLBC	CORE 0xe9	2  R L  B B
end_empty

begin_empty
empty|# 268a acbb	ACB TN1		CORE 0x9d	4  R B  R B  M B  B W
end_empty

begin_empty
empty|# 268b acbw	ACB TN1		CORE 0x3d	4  R W  R W  M W  B W
end_empty

begin_empty
empty|# 268c acbl	ACB TN1		CORE 0xf1	4  R L  R L  M L  B W
end_empty

begin_empty
empty|# 268d acbf	ACB TN1		CORE 0x4f	4  R F  R F  M F  B W
end_empty

begin_empty
empty|# 268e acbd	ACB TN1		CORE 0x6f	4  R D  R D  M D  B W
end_empty

begin_empty
empty|# 268f acbg	ACB TN1		ESCD 0x4f	4  R G  R G  M G  B W
end_empty

begin_empty
empty|# 268g acbh	ACB TN1		ESCD 0x6f	4  R H  R H  M H  B W
end_empty

begin_empty
empty|# 270a aoblss	AOBLSS S	CORE 0xf2	3  R L  M L  B B
end_empty

begin_empty
empty|# 270b aobleq	AOBLEQ S	CORE 0xf3	3  R L  M L  B B
end_empty

begin_empty
empty|# 271a sobgeq	SOBGEQ S	CORE 0xf4	2  M L  B B
end_empty

begin_empty
empty|# 271b sobgtr	SOBGTR S	CORE 0xf5	2  M L  B B
end_empty

begin_empty
empty|# 273a caseb	CASE TN1	CORE 0x8f	3  R B  R B  R B
end_empty

begin_empty
empty|# 273b casew	CASE TN1	CORE 0xaf	3  R W  R W  R W
end_empty

begin_empty
empty|# 273c casel	CASE TN1	CORE 0xcf	3  R L  R L  R L
end_empty

begin_empty
empty|# 275a bsbb	HARD HARD	CORE 0x10	1  B B
end_empty

begin_empty
empty|# 275b bsbw	HARD HARD	CORE 0x30	1  B W
end_empty

begin_empty
empty|# 275c jsb	JSB S		CORE 0x16	1  A B
end_empty

begin_empty
empty|# 276a rsb	JBR RSB		CORE 0x05	0
end_empty

begin_empty
empty|# 280a callg	CALLS S		CORE 0xfa	2  A B  A B
end_empty

begin_empty
empty|# 282a calls	CALLS S		CORE 0xfb	2  R L  A B
end_empty

begin_empty
empty|# 284a ret	JBR RET		CORE 0x04	0
end_empty

begin_empty
empty|# 288a movc3	MOVC3 S		CORE 0x28	3  R W  A B  A B
end_empty

begin_empty
empty|# 288b movc5	HARD HARD	CORE 0x2c	5  R W  A B  R B  R W  A B
end_empty

begin_empty
empty|# 290a movtc	HARD HARD	CORE 0x2e	6  R W  A B  R B  A B  R W  A B
end_empty

begin_empty
empty|# 292a movtuc	HARD HARD	CORE 0x2f	6  R W  A B  R B  A B  R W  A B
end_empty

begin_empty
empty|# 294a cmpc3	HARD HARD	CORE 0x29	3  R W  A B  A B
end_empty

begin_empty
empty|# 294b cmpc5	HARD HARD	CORE 0x2d	5  R W  A B  R B  R W  A B
end_empty

begin_empty
empty|# 297a scanc	HARD HARD	CORE 0x2a	4  R W  A B  A B  R B
end_empty

begin_empty
empty|# 297b spanc	HARD HARD	CORE 0x2b	4  R W  A B  A B  R B
end_empty

begin_empty
empty|# 299a locc	HARD HARD	CORE 0x3a	3  R B  R W  A B
end_empty

begin_empty
empty|# 299b skpc	HARD HARD	CORE 0x3b	3  R B  R W  A B
end_empty

begin_empty
empty|# 301a matchc	HARD HARD	CORE 0x39	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 304a crc	HARD HARD	CORE 0x0b	4  A B  R L  R W  A B
end_empty

begin_empty
empty|# 312a movp	HARD HARD	CORE 0x34	3  R W  A B  A B
end_empty

begin_empty
empty|# 313a cmpp3	HARD HARD	CORE 0x35	3  R W  A B  A B
end_empty

begin_empty
empty|# 313b cmpp4	HARD HARD	CORE 0x37	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 314a addp4	HARD HARD	CORE 0x20	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 314b addp6	HARD HARD	CORE 0x21	6  R W  A B  R W  A B  R W  A B
end_empty

begin_empty
empty|# 316a subp4	HARD HARD	CORE 0x22	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 316b subp6	HARD HARD	CORE 0x23	6  R W  A B  R W  A B  R W  A B
end_empty

begin_empty
empty|# 318a mulp	HARD HARD	CORE 0x25	6  R W  A B  R W  A B  R W  A B
end_empty

begin_empty
empty|# 319a divp	HARD HARD	CORE 0x27	6  R W  A B  R W  A B  R W  A B
end_empty

begin_empty
empty|# 321a cvtlp	HARD HARD	CORE 0xf9	3  R L  R W  A B
end_empty

begin_empty
empty|# 322a cvtpl	HARD HARD	CORE 0x36	3  R W  A B  W L
end_empty

begin_empty
empty|# 323a cvtpt	HARD HARD	CORE 0x24	5  R W  A B  A B  R W  A B
end_empty

begin_empty
empty|# 325a cvttp	HARD HARD	CORE 0x26	5  R W  A B  A B  R W  A B
end_empty

begin_empty
empty|# 327a cvtps	HARD HARD	CORE 0x08	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 329a cvtsp	HARD HARD	CORE 0x09	4  R W  A B  R W  A B
end_empty

begin_empty
empty|# 330a ashp	HARD HARD	CORE 0xf8	6  R B  R W  A B  R B  R W  A B
end_empty

begin_empty
empty|# 335a editpc	HARD HARD	CORE 0x38	4  R W  A B  A B  A B
end_empty

begin_empty
empty|# 385a nop	HARD HARD	CORE 0x01	0
end_empty

begin_empty
empty|# 392a escd	HARD HARD	CORE 0xfd	0
end_empty

begin_empty
empty|# 392b esce	HARD HARD	CORE 0xfe	0
end_empty

begin_empty
empty|# 393c escf	HARD HARD	CORE 0xff	0
end_empty

end_unit

