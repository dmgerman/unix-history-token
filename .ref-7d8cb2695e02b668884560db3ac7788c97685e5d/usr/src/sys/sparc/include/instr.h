begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This software was developed by the Computer Systems Engineering group  * at Lawrence Berkeley Laboratory under DARPA contract BG 91-66 and  * contributed to Berkeley.  *  * All advertising materials mentioning features or use of this software  * must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Lawrence Berkeley Laboratory.  *  * %sccs.include.redist.c%  *  *	@(#)instr.h	7.3 (Berkeley) %G%  *  * from: $Header: instr.h,v 1.6 92/11/26 02:04:37 torek Exp $  */
end_comment

begin_comment
comment|/* see also Appendix F of the SPARC version 8 document */
end_comment

begin_enum
enum|enum
name|IOP
block|{
name|IOP_OP2
block|,
name|IOP_CALL
block|,
name|IOP_reg
block|,
name|IOP_mem
block|}
enum|;
end_enum

begin_enum
enum|enum
name|IOP2
block|{
name|IOP2_UNIMP
block|,
name|IOP2_err1
block|,
name|IOP2_Bicc
block|,
name|IOP2_err3
block|,
name|IOP2_SETHI
block|,
name|IOP2_err5
block|,
name|IOP2_FBfcc
block|,
name|IOP2_CBccc
block|}
enum|;
end_enum

begin_enum
enum|enum
name|IOP3_reg
block|{
name|IOP3_ADD
block|,
name|IOP3_AND
block|,
name|IOP3_OR
block|,
name|IOP3_XOR
block|,
name|IOP3_SUB
block|,
name|IOP3_ANDN
block|,
name|IOP3_ORN
block|,
name|IOP3_XNOR
block|,
name|IOP3_ADDX
block|,
name|IOP3_rerr09
block|,
name|IOP3_UMUL
block|,
name|IOP3_SMUL
block|,
name|IOP3_SUBX
block|,
name|IOP3_rerr0d
block|,
name|IOP3_UDIV
block|,
name|IOP3_SDIV
block|,
name|IOP3_ADDcc
block|,
name|IOP3_ANDcc
block|,
name|IOP3_ORcc
block|,
name|IOP3_XORcc
block|,
name|IOP3_SUBcc
block|,
name|IOP3_ANDNcc
block|,
name|IOP3_ORNcc
block|,
name|IOP3_XNORcc
block|,
name|IOP3_ADDXcc
block|,
name|IOP3_rerr19
block|,
name|IOP3_UMULcc
block|,
name|IOP3_SMULcc
block|,
name|IOP3_SUBXcc
block|,
name|IOP3_rerr1d
block|,
name|IOP3_UDIVcc
block|,
name|IOP3_SDIVcc
block|,
name|IOP3_TADDcc
block|,
name|IOP3_TSUBcc
block|,
name|IOP3_TADDccTV
block|,
name|IOP3_TSUBccTV
block|,
name|IOP3_MULScc
block|,
name|IOP3_SLL
block|,
name|IOP3_SRL
block|,
name|IOP3_SRA
block|,
name|IOP3_RDASR_RDY_STBAR
block|,
name|IOP3_RDPSR
block|,
name|IOP3_RDWIM
block|,
name|IOP3_RDTGBR
block|,
name|IOP3_rerr2c
block|,
name|IOP3_rerr2d
block|,
name|IOP3_rerr2e
block|,
name|IOP3_rerr2f
block|,
name|IOP3_WRASR_WRY
block|,
name|IOP3_WRPSR
block|,
name|IOP3_WRWIM
block|,
name|IOP3_WRTBR
block|,
name|IOP3_FPop1
block|,
name|IOP3_FPop2
block|,
name|IOP3_CPop1
block|,
name|IOP3_CPop2
block|,
name|IOP3_JMPL
block|,
name|IOP3_RETT
block|,
name|IOP3_Ticc
block|,
name|IOP3_FLUSH
block|,
name|IOP3_SAVE
block|,
name|IOP3_RESTORE
block|,
name|IOP3_rerr3e
block|,
name|IOP3_rerr3f
block|}
enum|;
end_enum

begin_enum
enum|enum
name|IOP3_mem
block|{
name|IOP3_LD
block|,
name|IOP3_LDUB
block|,
name|IOP3_LDUH
block|,
name|IOP3_LDD
block|,
name|IOP3_ST
block|,
name|IOP3_STB
block|,
name|IOP3_STH
block|,
name|IOP3_STD
block|,
name|IOP3_merr08
block|,
name|IOP3_LDSB
block|,
name|IOP3_LDSH
block|,
name|IOP3_merr0b
block|,
name|IOP3_merr0c
block|,
name|IOP3_LDSTUB
block|,
name|IOP3_merr0f
block|,
name|IOP3_SWAP
block|,
name|IOP3_LDA
block|,
name|IOP3_LDUBA
block|,
name|IOP3_LDUHA
block|,
name|IOP3_LDDA
block|,
name|IOP3_STA
block|,
name|IOP3_STBA
block|,
name|IOP3_STHA
block|,
name|IOP3_STDA
block|,
name|IOP3_merr18
block|,
name|IOP3_LDSBA
block|,
name|IOP3_LDSHA
block|,
name|IOP3_merr1b
block|,
name|IOP3_merr1c
block|,
name|IOP3_LDSTUBA
block|,
name|IOP3_merr1f
block|,
name|IOP3_SWAPA
block|,
name|IOP3_LDF
block|,
name|IOP3_LDFSR
block|,
name|IOP3_merr22
block|,
name|IOP3_LDDF
block|,
name|IOP3_STF
block|,
name|IOP3_STFSR
block|,
name|IOP3_STDFQ
block|,
name|IOP3_STDF
block|,
name|IOP3_merr28
block|,
name|IOP3_merr29
block|,
name|IOP3_merr2a
block|,
name|IOP3_merr2b
block|,
name|IOP3_merr2c
block|,
name|IOP3_merr2d
block|,
name|IOP3_merr2e
block|,
name|IOP3_merr2f
block|,
name|IOP3_LFC
block|,
name|IOP3_LDCSR
block|,
name|IOP3_merr32
block|,
name|IOP3_LDDC
block|,
name|IOP3_STC
block|,
name|IOP3_STCSR
block|,
name|IOP3_STDCQ
block|,
name|IOP3_STDC
block|,
name|IOP3_merr38
block|,
name|IOP3_merr39
block|,
name|IOP3_merr3a
block|,
name|IOP3_merr3b
block|,
name|IOP3_merr3c
block|,
name|IOP3_merr3d
block|,
name|IOP3_merr3e
block|,
name|IOP3_merr3f
block|}
enum|;
end_enum

begin_comment
comment|/*  * Integer condition codes.  */
end_comment

begin_define
define|#
directive|define
name|Icc_N
value|0x0
end_define

begin_comment
comment|/* never */
end_comment

begin_define
define|#
directive|define
name|Icc_E
value|0x1
end_define

begin_comment
comment|/* equal (equiv. zero) */
end_comment

begin_define
define|#
directive|define
name|Icc_LE
value|0x2
end_define

begin_comment
comment|/* less or equal */
end_comment

begin_define
define|#
directive|define
name|Icc_L
value|0x3
end_define

begin_comment
comment|/* less */
end_comment

begin_define
define|#
directive|define
name|Icc_LEU
value|0x4
end_define

begin_comment
comment|/* less or equal unsigned */
end_comment

begin_define
define|#
directive|define
name|Icc_CS
value|0x5
end_define

begin_comment
comment|/* carry set (equiv. less unsigned) */
end_comment

begin_define
define|#
directive|define
name|Icc_NEG
value|0x6
end_define

begin_comment
comment|/* negative */
end_comment

begin_define
define|#
directive|define
name|Icc_VS
value|0x7
end_define

begin_comment
comment|/* overflow set */
end_comment

begin_define
define|#
directive|define
name|Icc_A
value|0x8
end_define

begin_comment
comment|/* always */
end_comment

begin_define
define|#
directive|define
name|Icc_NE
value|0x9
end_define

begin_comment
comment|/* not equal (equiv. not zero) */
end_comment

begin_define
define|#
directive|define
name|Icc_G
value|0xa
end_define

begin_comment
comment|/* greater */
end_comment

begin_define
define|#
directive|define
name|Icc_GE
value|0xb
end_define

begin_comment
comment|/* greater or equal */
end_comment

begin_define
define|#
directive|define
name|Icc_GU
value|0xc
end_define

begin_comment
comment|/* greater unsigned */
end_comment

begin_define
define|#
directive|define
name|Icc_CC
value|0xd
end_define

begin_comment
comment|/* carry clear (equiv. gtr or eq unsigned) */
end_comment

begin_define
define|#
directive|define
name|Icc_POS
value|0xe
end_define

begin_comment
comment|/* positive */
end_comment

begin_define
define|#
directive|define
name|Icc_VC
value|0xf
end_define

begin_comment
comment|/* overflow clear */
end_comment

begin_comment
comment|/*  * Integer registers.  */
end_comment

begin_define
define|#
directive|define
name|I_G0
value|0
end_define

begin_define
define|#
directive|define
name|I_G1
value|1
end_define

begin_define
define|#
directive|define
name|I_G2
value|2
end_define

begin_define
define|#
directive|define
name|I_G3
value|3
end_define

begin_define
define|#
directive|define
name|I_G4
value|4
end_define

begin_define
define|#
directive|define
name|I_G5
value|5
end_define

begin_define
define|#
directive|define
name|I_G6
value|6
end_define

begin_define
define|#
directive|define
name|I_G7
value|7
end_define

begin_define
define|#
directive|define
name|I_O0
value|8
end_define

begin_define
define|#
directive|define
name|I_O1
value|9
end_define

begin_define
define|#
directive|define
name|I_O2
value|10
end_define

begin_define
define|#
directive|define
name|I_O3
value|11
end_define

begin_define
define|#
directive|define
name|I_O4
value|12
end_define

begin_define
define|#
directive|define
name|I_O5
value|13
end_define

begin_define
define|#
directive|define
name|I_O6
value|14
end_define

begin_define
define|#
directive|define
name|I_O7
value|15
end_define

begin_define
define|#
directive|define
name|I_L0
value|16
end_define

begin_define
define|#
directive|define
name|I_L1
value|17
end_define

begin_define
define|#
directive|define
name|I_L2
value|18
end_define

begin_define
define|#
directive|define
name|I_L3
value|19
end_define

begin_define
define|#
directive|define
name|I_L4
value|20
end_define

begin_define
define|#
directive|define
name|I_L5
value|21
end_define

begin_define
define|#
directive|define
name|I_L6
value|22
end_define

begin_define
define|#
directive|define
name|I_L7
value|23
end_define

begin_define
define|#
directive|define
name|I_I0
value|24
end_define

begin_define
define|#
directive|define
name|I_I1
value|25
end_define

begin_define
define|#
directive|define
name|I_I2
value|26
end_define

begin_define
define|#
directive|define
name|I_I3
value|27
end_define

begin_define
define|#
directive|define
name|I_I4
value|28
end_define

begin_define
define|#
directive|define
name|I_I5
value|29
end_define

begin_define
define|#
directive|define
name|I_I6
value|30
end_define

begin_define
define|#
directive|define
name|I_I7
value|31
end_define

begin_comment
comment|/*  * An instruction.  */
end_comment

begin_union
union|union
name|instr
block|{
name|int
name|i_int
decl_stmt|;
comment|/* as a whole */
comment|/* 	 * The first level of decoding is to use the top 2 bits. 	 * This gives us one of three `formats', which usually give 	 * a second level of decoding. 	 */
struct|struct
block|{
name|u_int
name|i_op
range|:
literal|2
decl_stmt|;
comment|/* first-level decode */
name|u_int
label|:
literal|30
expr_stmt|;
block|}
name|i_any
struct|;
comment|/* 	 * Format 1 instructions: CALL (undifferentiated). 	 */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 01 */
name|int
name|i_disp
range|:
literal|30
decl_stmt|;
comment|/* displacement */
block|}
name|i_call
struct|;
comment|/* 	 * Format 2 instructions (SETHI, UNIMP, and branches, plus illegal 	 * unused codes). 	 */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 00 */
name|u_int
label|:
literal|5
expr_stmt|;
name|u_int
name|i_op2
range|:
literal|3
decl_stmt|;
comment|/* second-level decode */
name|u_int
label|:
literal|22
expr_stmt|;
block|}
name|i_op2
struct|;
comment|/* UNIMP, SETHI */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 00 */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op2
range|:
literal|3
decl_stmt|;
comment|/* opcode: UNIMP or SETHI */
name|u_int
name|i_imm
range|:
literal|22
decl_stmt|;
comment|/* immediate value */
block|}
name|i_imm22
struct|;
comment|/* branches: Bicc, FBfcc, CBccc */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 00 */
name|u_int
name|i_annul
range|:
literal|1
decl_stmt|;
comment|/* annul bit */
name|u_int
name|i_cond
range|:
literal|4
decl_stmt|;
comment|/* condition codes */
name|u_int
name|i_op2
range|:
literal|3
decl_stmt|;
comment|/* opcode: {Bi,FBf,CBc}cc */
name|int
name|i_disp
range|:
literal|22
decl_stmt|;
comment|/* branch displacement */
block|}
name|i_branch
struct|;
comment|/* 	 * Format 3 instructions (memory reference; arithmetic, logical, 	 * shift, and other miscellaneous operations).  The second-level 	 * decode almost always makes use of an `rd' and `rs1', however 	 * (see also IOP3_reg and IOP3_mem). 	 * 	 * Beyond that, the low 14 bits may be broken up in one of three 	 * different ways, if at all: 	 *	1 bit of imm=0 + 8 bits of asi + 5 bits of rs2 [reg& mem] 	 *	1 bit of imm=1 + 13 bits of signed immediate [reg& mem] 	 *	9 bits of copressor `opf' opcode + 5 bits of rs2 [reg only] 	 */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 10 or 11 */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op3
range|:
literal|6
decl_stmt|;
comment|/* second-level decode */
name|u_int
name|i_rs1
range|:
literal|5
decl_stmt|;
comment|/* source register 1 */
name|u_int
name|i_low14
range|:
literal|14
decl_stmt|;
comment|/* varies */
block|}
name|i_op3
struct|;
comment|/* 	 * Memory forms.  These set i_op=3 and use simm13 or asi layout. 	 * Memory references without an ASI should use 0, but the actual 	 * ASI field is simply ignored. 	 */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 11 only */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op3
range|:
literal|6
decl_stmt|;
comment|/* second-level decode (see IOP3_mem) */
name|u_int
name|i_i
range|:
literal|1
decl_stmt|;
comment|/* immediate vs asi */
name|u_int
name|i_low13
range|:
literal|13
decl_stmt|;
comment|/* depend on i bit */
block|}
name|i_loadstore
struct|;
comment|/* 	 * Memory and register forms. 	 * These come in quite a variety and we do not 	 * attempt to break them down much. 	 */
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 10 or 11 */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op3
range|:
literal|6
decl_stmt|;
comment|/* second-level decode */
name|u_int
name|i_rs1
range|:
literal|5
decl_stmt|;
comment|/* source register 1 */
name|u_int
name|i_i
range|:
literal|1
decl_stmt|;
comment|/* immediate bit (1) */
name|int
name|i_simm13
range|:
literal|13
decl_stmt|;
comment|/* signed immediate */
block|}
name|i_simm13
struct|;
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 10 or 11 */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op3
range|:
literal|6
decl_stmt|;
comment|/* second-level decode */
name|u_int
name|i_rs1
range|:
literal|5
decl_stmt|;
comment|/* source register 1 */
name|u_int
name|i_asi
range|:
literal|8
decl_stmt|;
comment|/* asi */
name|u_int
name|i_rs2
range|:
literal|5
decl_stmt|;
comment|/* source register 2 */
block|}
name|i_asi
struct|;
struct|struct
block|{
name|u_int
label|:
literal|2
expr_stmt|;
comment|/* 10 only (register, no memory) */
name|u_int
name|i_rd
range|:
literal|5
decl_stmt|;
comment|/* destination register */
name|u_int
name|i_op3
range|:
literal|6
decl_stmt|;
comment|/* second-level decode (see IOP3_reg) */
name|u_int
name|i_rs1
range|:
literal|5
decl_stmt|;
comment|/* source register 1 */
name|u_int
name|i_opf
range|:
literal|9
decl_stmt|;
comment|/* coprocessor 3rd-level decode */
name|u_int
name|i_rs2
range|:
literal|5
decl_stmt|;
comment|/* source register 2 */
block|}
name|i_opf
struct|;
block|}
union|;
end_union

begin_comment
comment|/*  * Internal macros for building instructions.  These correspond 1-to-1 to  * the names above.  Note that x<< y | z == (x<< y) | z.  */
end_comment

begin_define
define|#
directive|define
name|_I_ANY
parameter_list|(
name|op
parameter_list|,
name|b
parameter_list|)
value|((op)<< 30 | (b))
end_define

begin_define
define|#
directive|define
name|_I_OP2
parameter_list|(
name|high
parameter_list|,
name|op2
parameter_list|,
name|low
parameter_list|)
define|\
value|_I_ANY(IOP_OP2, (high)<< 25 | (op2)<< 22 | (low))
end_define

begin_define
define|#
directive|define
name|_I_IMM22
parameter_list|(
name|rd
parameter_list|,
name|op2
parameter_list|,
name|imm
parameter_list|)
define|\
value|_I_ANY(IOP_OP2, (rd)<< 25 | (op2)<< 22 | (imm))
end_define

begin_define
define|#
directive|define
name|_I_BRANCH
parameter_list|(
name|a
parameter_list|,
name|c
parameter_list|,
name|op2
parameter_list|,
name|disp
parameter_list|)
define|\
value|_I_ANY(IOP_OP2, (a)<< 29 | (c)<< 25 | (op2)<< 22 | (disp))
end_define

begin_define
define|#
directive|define
name|_I_FBFCC
parameter_list|(
name|a
parameter_list|,
name|cond
parameter_list|,
name|disp
parameter_list|)
define|\
value|_I_BRANCH(a, cond, IOP2_FBfcc, disp)
end_define

begin_define
define|#
directive|define
name|_I_CBCCC
parameter_list|(
name|a
parameter_list|,
name|cond
parameter_list|,
name|disp
parameter_list|)
define|\
value|_I_BRANCH(a, cond, IOP2_CBccc, disp)
end_define

begin_define
define|#
directive|define
name|_I_SIMM
parameter_list|(
name|simm
parameter_list|)
value|(1<< 13 | ((simm)& 0x1fff))
end_define

begin_define
define|#
directive|define
name|_I_OP3_GEN
parameter_list|(
name|form
parameter_list|,
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|low14
parameter_list|)
define|\
value|_I_ANY(form, (rd)<< 25 | (op3)<< 19 | (rs1)<< 14 | (low14))
end_define

begin_define
define|#
directive|define
name|_I_OP3_LS_RAR
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|asi
parameter_list|,
name|rs2
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_mem, rd, op3, rs1, (asi)<< 5 | (rs2))
end_define

begin_define
define|#
directive|define
name|_I_OP3_LS_RI
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|simm13
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_mem, rd, op3, rs1, _I_SIMM(simm13))
end_define

begin_define
define|#
directive|define
name|_I_OP3_LS_RR
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|rs2
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_mem, rd, op3, rs1, rs2)
end_define

begin_define
define|#
directive|define
name|_I_OP3_R_RAR
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|asi
parameter_list|,
name|rs2
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_reg, rd, op3, rs1, (asi)<< 5 | (rs2))
end_define

begin_define
define|#
directive|define
name|_I_OP3_R_RI
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|simm13
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_reg, rd, op3, rs1, _I_SIMM(simm13))
end_define

begin_define
define|#
directive|define
name|_I_OP3_R_RR
parameter_list|(
name|rd
parameter_list|,
name|op3
parameter_list|,
name|rs1
parameter_list|,
name|rs2
parameter_list|)
define|\
value|_I_OP3_GEN(IOP_reg, rd, op3, rs1, rs2)
end_define

begin_define
define|#
directive|define
name|I_CALL
parameter_list|(
name|d
parameter_list|)
value|_I_ANY(IOP_CALL, d)
end_define

begin_define
define|#
directive|define
name|I_UNIMP
parameter_list|(
name|v
parameter_list|)
value|_I_IMM22(0, IOP2_UNIMP, v)
end_define

begin_define
define|#
directive|define
name|I_BN
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_N, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BE
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_E, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BZ
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_E, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BLE
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_LE, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BL
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_L, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BLEU
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_LEU, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BCS
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_CS, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BLU
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_CS, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BNEG
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_NEG, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BVS
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_VS, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BA
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_A, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_B
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_A, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BNE
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_NE, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BNZ
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_NE, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BG
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_G, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BGE
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_GE, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BGU
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_GU, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BCC
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_CC, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BGEU
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_CC, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BPOS
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_POS, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_BVC
parameter_list|(
name|a
parameter_list|,
name|d
parameter_list|)
value|_I_BRANCH(a, Icc_VC, IOP2_Bicc, d)
end_define

begin_define
define|#
directive|define
name|I_SETHI
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|_I_IMM22(r, 4, v)
end_define

begin_define
define|#
directive|define
name|I_ORri
parameter_list|(
name|rd
parameter_list|,
name|rs1
parameter_list|,
name|imm
parameter_list|)
value|_I_OP3_R_RI(rd, IOP3_OR, rs1, imm)
end_define

begin_define
define|#
directive|define
name|I_ORrr
parameter_list|(
name|rd
parameter_list|,
name|rs1
parameter_list|,
name|rs2
parameter_list|)
value|_I_OP3_R_RR(rd, IOP3_OR, rs1, rs2)
end_define

begin_define
define|#
directive|define
name|I_MOVi
parameter_list|(
name|rd
parameter_list|,
name|imm
parameter_list|)
value|_I_OP3_R_RI(rd, IOP3_OR, I_G0, imm)
end_define

begin_define
define|#
directive|define
name|I_MOVr
parameter_list|(
name|rd
parameter_list|,
name|rs
parameter_list|)
value|_I_OP3_R_RR(rd, IOP3_OR, I_G0, rs)
end_define

begin_define
define|#
directive|define
name|I_RDPSR
parameter_list|(
name|rd
parameter_list|)
value|_I_OP3_R_RR(rd, IOP3_RDPSR, 0, 0)
end_define

begin_define
define|#
directive|define
name|I_JMPLri
parameter_list|(
name|rd
parameter_list|,
name|rs1
parameter_list|,
name|imm
parameter_list|)
value|_I_OP3_R_RI(rd, IOP3_JMPL, rs1, imm)
end_define

begin_define
define|#
directive|define
name|I_JMPLrr
parameter_list|(
name|rd
parameter_list|,
name|rs1
parameter_list|,
name|rs2
parameter_list|)
value|_I_OP3_R_RR(rd, IOP3_JMPL, rs1, rs2)
end_define

begin_comment
comment|/*  * (Since these are sparse, we skip the enumerations for now.)  * FPop values.  All appear in both FPop1 and FPop2 spaces, but arithmetic  * ops should happen only with FPop1 and comparison only with FPop2.  * The type sits in the low two bits; those bits are given as zero here.  */
end_comment

begin_define
define|#
directive|define
name|FMOV
value|0x00
end_define

begin_define
define|#
directive|define
name|FNEG
value|0x04
end_define

begin_define
define|#
directive|define
name|FABS
value|0x08
end_define

begin_define
define|#
directive|define
name|FSQRT
value|0x28
end_define

begin_define
define|#
directive|define
name|FADD
value|0x40
end_define

begin_define
define|#
directive|define
name|FSUB
value|0x44
end_define

begin_define
define|#
directive|define
name|FMUL
value|0x48
end_define

begin_define
define|#
directive|define
name|FDIV
value|0x4c
end_define

begin_define
define|#
directive|define
name|FCMP
value|0x50
end_define

begin_define
define|#
directive|define
name|FCMPE
value|0x54
end_define

begin_define
define|#
directive|define
name|FSMULD
value|0x68
end_define

begin_define
define|#
directive|define
name|FDMULX
value|0x6c
end_define

begin_define
define|#
directive|define
name|FTOS
value|0xc4
end_define

begin_define
define|#
directive|define
name|FTOD
value|0xc8
end_define

begin_define
define|#
directive|define
name|FTOX
value|0xcc
end_define

begin_define
define|#
directive|define
name|FTOI
value|0xd0
end_define

begin_comment
comment|/*  * FPU data types.  */
end_comment

begin_define
define|#
directive|define
name|FTYPE_INT
value|0
end_define

begin_comment
comment|/* data = 32-bit signed integer */
end_comment

begin_define
define|#
directive|define
name|FTYPE_SNG
value|1
end_define

begin_comment
comment|/* data = 32-bit float */
end_comment

begin_define
define|#
directive|define
name|FTYPE_DBL
value|2
end_define

begin_comment
comment|/* data = 64-bit double */
end_comment

begin_define
define|#
directive|define
name|FTYPE_EXT
value|3
end_define

begin_comment
comment|/* data = 128-bit extended (quad-prec) */
end_comment

end_unit

