begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)mips_opcode.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Define the instruction formats and opcode values for the  * MIPS instruction set.  */
end_comment

begin_comment
comment|/*  * Define the instruction formats.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|unsigned
name|word
decl_stmt|;
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
struct|struct
block|{
name|unsigned
name|imm
range|:
literal|16
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|IType
struct|;
struct|struct
block|{
name|unsigned
name|target
range|:
literal|26
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|JType
struct|;
struct|struct
block|{
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
name|unsigned
name|shamt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rd
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
block|}
name|RType
struct|;
struct|struct
block|{
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
name|unsigned
name|fd
range|:
literal|5
decl_stmt|;
name|unsigned
name|fs
range|:
literal|5
decl_stmt|;
name|unsigned
name|ft
range|:
literal|5
decl_stmt|;
name|unsigned
name|fmt
range|:
literal|4
decl_stmt|;
name|unsigned
label|:
literal|1
expr_stmt|;
comment|/* always '1' */
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
comment|/* always '0x11' */
block|}
name|FRType
struct|;
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|imm
range|:
literal|16
decl_stmt|;
block|}
name|IType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|target
range|:
literal|26
decl_stmt|;
block|}
name|JType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|;
name|unsigned
name|rt
range|:
literal|5
decl_stmt|;
name|unsigned
name|rd
range|:
literal|5
decl_stmt|;
name|unsigned
name|shamt
range|:
literal|5
decl_stmt|;
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
block|}
name|RType
struct|;
struct|struct
block|{
name|unsigned
name|op
range|:
literal|6
decl_stmt|;
comment|/* always '0x11' */
name|unsigned
label|:
literal|1
expr_stmt|;
comment|/* always '1' */
name|unsigned
name|fmt
range|:
literal|4
decl_stmt|;
name|unsigned
name|ft
range|:
literal|5
decl_stmt|;
name|unsigned
name|fs
range|:
literal|5
decl_stmt|;
name|unsigned
name|fd
range|:
literal|5
decl_stmt|;
name|unsigned
name|func
range|:
literal|6
decl_stmt|;
block|}
name|FRType
struct|;
endif|#
directive|endif
block|}
name|InstFmt
typedef|;
end_typedef

begin_comment
comment|/*  * Values for the 'op' field.  */
end_comment

begin_define
define|#
directive|define
name|OP_SPECIAL
value|000
end_define

begin_define
define|#
directive|define
name|OP_BCOND
value|001
end_define

begin_define
define|#
directive|define
name|OP_J
value|002
end_define

begin_define
define|#
directive|define
name|OP_JAL
value|003
end_define

begin_define
define|#
directive|define
name|OP_BEQ
value|004
end_define

begin_define
define|#
directive|define
name|OP_BNE
value|005
end_define

begin_define
define|#
directive|define
name|OP_BLEZ
value|006
end_define

begin_define
define|#
directive|define
name|OP_BGTZ
value|007
end_define

begin_define
define|#
directive|define
name|OP_ADDI
value|010
end_define

begin_define
define|#
directive|define
name|OP_ADDIU
value|011
end_define

begin_define
define|#
directive|define
name|OP_SLTI
value|012
end_define

begin_define
define|#
directive|define
name|OP_SLTIU
value|013
end_define

begin_define
define|#
directive|define
name|OP_ANDI
value|014
end_define

begin_define
define|#
directive|define
name|OP_ORI
value|015
end_define

begin_define
define|#
directive|define
name|OP_XORI
value|016
end_define

begin_define
define|#
directive|define
name|OP_LUI
value|017
end_define

begin_define
define|#
directive|define
name|OP_COP0
value|020
end_define

begin_define
define|#
directive|define
name|OP_COP1
value|021
end_define

begin_define
define|#
directive|define
name|OP_COP2
value|022
end_define

begin_define
define|#
directive|define
name|OP_COP3
value|023
end_define

begin_define
define|#
directive|define
name|OP_LB
value|040
end_define

begin_define
define|#
directive|define
name|OP_LH
value|041
end_define

begin_define
define|#
directive|define
name|OP_LWL
value|042
end_define

begin_define
define|#
directive|define
name|OP_LW
value|043
end_define

begin_define
define|#
directive|define
name|OP_LBU
value|044
end_define

begin_define
define|#
directive|define
name|OP_LHU
value|045
end_define

begin_define
define|#
directive|define
name|OP_LWR
value|046
end_define

begin_define
define|#
directive|define
name|OP_SB
value|050
end_define

begin_define
define|#
directive|define
name|OP_SH
value|051
end_define

begin_define
define|#
directive|define
name|OP_SWL
value|052
end_define

begin_define
define|#
directive|define
name|OP_SW
value|053
end_define

begin_define
define|#
directive|define
name|OP_SWR
value|056
end_define

begin_define
define|#
directive|define
name|OP_LWC0
value|060
end_define

begin_define
define|#
directive|define
name|OP_LWC1
value|061
end_define

begin_define
define|#
directive|define
name|OP_LWC2
value|062
end_define

begin_define
define|#
directive|define
name|OP_LWC3
value|063
end_define

begin_define
define|#
directive|define
name|OP_SWC0
value|070
end_define

begin_define
define|#
directive|define
name|OP_SWC1
value|071
end_define

begin_define
define|#
directive|define
name|OP_SWC2
value|072
end_define

begin_define
define|#
directive|define
name|OP_SWC3
value|073
end_define

begin_comment
comment|/*  * Values for the 'func' field when 'op' == OP_SPECIAL.  */
end_comment

begin_define
define|#
directive|define
name|OP_SLL
value|000
end_define

begin_define
define|#
directive|define
name|OP_SRL
value|002
end_define

begin_define
define|#
directive|define
name|OP_SRA
value|003
end_define

begin_define
define|#
directive|define
name|OP_SLLV
value|004
end_define

begin_define
define|#
directive|define
name|OP_SRLV
value|006
end_define

begin_define
define|#
directive|define
name|OP_SRAV
value|007
end_define

begin_define
define|#
directive|define
name|OP_JR
value|010
end_define

begin_define
define|#
directive|define
name|OP_JALR
value|011
end_define

begin_define
define|#
directive|define
name|OP_SYSCALL
value|014
end_define

begin_define
define|#
directive|define
name|OP_BREAK
value|015
end_define

begin_define
define|#
directive|define
name|OP_MFHI
value|020
end_define

begin_define
define|#
directive|define
name|OP_MTHI
value|021
end_define

begin_define
define|#
directive|define
name|OP_MFLO
value|022
end_define

begin_define
define|#
directive|define
name|OP_MTLO
value|023
end_define

begin_define
define|#
directive|define
name|OP_MULT
value|030
end_define

begin_define
define|#
directive|define
name|OP_MULTU
value|031
end_define

begin_define
define|#
directive|define
name|OP_DIV
value|032
end_define

begin_define
define|#
directive|define
name|OP_DIVU
value|033
end_define

begin_define
define|#
directive|define
name|OP_ADD
value|040
end_define

begin_define
define|#
directive|define
name|OP_ADDU
value|041
end_define

begin_define
define|#
directive|define
name|OP_SUB
value|042
end_define

begin_define
define|#
directive|define
name|OP_SUBU
value|043
end_define

begin_define
define|#
directive|define
name|OP_AND
value|044
end_define

begin_define
define|#
directive|define
name|OP_OR
value|045
end_define

begin_define
define|#
directive|define
name|OP_XOR
value|046
end_define

begin_define
define|#
directive|define
name|OP_NOR
value|047
end_define

begin_define
define|#
directive|define
name|OP_SLT
value|052
end_define

begin_define
define|#
directive|define
name|OP_SLTU
value|053
end_define

begin_comment
comment|/*  * Values for the 'func' field when 'op' == OP_BCOND.  */
end_comment

begin_define
define|#
directive|define
name|OP_BLTZ
value|000
end_define

begin_define
define|#
directive|define
name|OP_BGEZ
value|001
end_define

begin_define
define|#
directive|define
name|OP_BLTZAL
value|020
end_define

begin_define
define|#
directive|define
name|OP_BGEZAL
value|021
end_define

begin_comment
comment|/*  * Values for the 'rs' field when 'op' == OP_COPz.  */
end_comment

begin_define
define|#
directive|define
name|OP_MF
value|000
end_define

begin_define
define|#
directive|define
name|OP_MT
value|004
end_define

begin_define
define|#
directive|define
name|OP_BCx
value|010
end_define

begin_define
define|#
directive|define
name|OP_BCy
value|014
end_define

begin_define
define|#
directive|define
name|OP_CF
value|002
end_define

begin_define
define|#
directive|define
name|OP_CT
value|006
end_define

begin_comment
comment|/*  * Values for the 'rt' field when 'op' == OP_COPz.  */
end_comment

begin_define
define|#
directive|define
name|COPz_BC_TF_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|COPz_BC_TRUE
value|0x01
end_define

begin_define
define|#
directive|define
name|COPz_BC_FALSE
value|0x00
end_define

end_unit

