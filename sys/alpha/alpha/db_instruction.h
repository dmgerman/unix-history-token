begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* $NetBSD: db_instruction.h,v 1.4 1997/09/16 22:53:32 thorpej Exp $ */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1993,1992 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie Mellon  * the rights to redistribute these changes.  */
end_comment

begin_comment
comment|/*  *	File: alpha_instruction.h  * 	Author: Alessandro Forin, Carnegie Mellon University  *	Date:	11/91  *  *	Alpha Instruction set definition  *  *	Reference: "Alpha System Reference Manual", V4.0, April 1991  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALPHA_INSTRUCTION_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALPHA_INSTRUCTION_H_
value|1
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ASSEMBLER
argument_list|)
end_if

begin_comment
comment|/*  *	All instructions are in one of five formats:  *		Memory, Branch, Operate, Floating-point Operate, PAL  *  *	One minor departure from DEC's conventions is we use names  *	for registers that are more akin their software use, e.g.  *	rather then bluntly call them Ra/Rb/Rc we make clear which  *	one is a source (Rs) and which one is a destination (Rd).  *	When a second source register is defined we call it Rt.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
comment|/* 	 *	All instructions are 32 bits wide 	 */
name|unsigned
name|int
name|bits
decl_stmt|;
comment|/* 	 *	Generic instruction pseudo format; look at 	 *	opcode to see how to interpret the rest. 	 */
struct|struct
block|{
name|unsigned
name|bits
range|:
literal|26
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|generic_format
struct|;
comment|/* 	 *	Memory instructions contain a 16 bit 	 *	signed immediate value and two register 	 *	specifiers 	 */
struct|struct
block|{
name|signed
name|short
name|displacement
decl_stmt|;
name|unsigned
name|rs
range|:
literal|5
decl_stmt|,
name|rd
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|mem_format
struct|;
comment|/* 	 *	Branch instruction contain a 21 bit offset, 	 *	which is sign-extended, shifted and combined 	 *	with the PC to form a 64 bit destination address. 	 * 	 *	In computed jump instructions the opcode is further 	 *	specified in the offset field, the rest of it is 	 *	used as branch target hint.  The destination of the 	 *	jump is the source register. 	 */
struct|struct
block|{
name|signed
name|int
name|displacement
range|:
literal|21
decl_stmt|;
name|unsigned
name|rd
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|branch_format
struct|;
struct|struct
block|{
name|signed
name|int
name|hint
range|:
literal|14
decl_stmt|;
name|unsigned
name|action
range|:
literal|2
decl_stmt|,
name|rs
range|:
literal|5
decl_stmt|,
name|rd
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|jump_format
struct|;
struct|struct
block|{
name|signed
name|int
name|offset
range|:
literal|16
decl_stmt|;
name|unsigned
name|rb
range|:
literal|5
decl_stmt|;
name|unsigned
name|ra
range|:
literal|5
decl_stmt|;
name|unsigned
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|memory_format
struct|;
comment|/* 	 *	Operate instructions are of two types, with 	 *	a second source register or with a literal 	 *	specifier.  Bit 12 sez which is which. 	 */
struct|struct
block|{
name|unsigned
name|rc
range|:
literal|5
decl_stmt|,
name|function
range|:
literal|7
decl_stmt|,
name|is_lit
range|:
literal|1
decl_stmt|,
name|sbz_or_litlo
range|:
literal|3
decl_stmt|,
name|rb_or_lithi
range|:
literal|5
decl_stmt|,
name|ra
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|operate_generic_format
struct|;
struct|struct
block|{
name|unsigned
name|rd
range|:
literal|5
decl_stmt|,
name|function
range|:
literal|7
decl_stmt|,
name|sbz
range|:
literal|4
decl_stmt|,
name|rt
range|:
literal|5
decl_stmt|,
name|rs
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|operate_reg_format
struct|;
struct|struct
block|{
name|unsigned
name|rd
range|:
literal|5
decl_stmt|,
name|function
range|:
literal|7
decl_stmt|,
name|one
range|:
literal|1
decl_stmt|,
name|literal
range|:
literal|8
decl_stmt|,
name|rs
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|operate_lit_format
struct|;
comment|/* 	 *	Floating point operate instruction are quite 	 *	uniform in the encoding.  As for the semantics.. 	 */
struct|struct
block|{
name|unsigned
name|fd
range|:
literal|5
decl_stmt|,
name|function
range|:
literal|11
decl_stmt|,
name|ft
range|:
literal|5
decl_stmt|,
name|fs
range|:
literal|5
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|float_format
struct|;
comment|/* 	 *	PAL instructions just define the major opcode 	 */
struct|struct
block|{
name|unsigned
name|function
range|:
literal|26
decl_stmt|,
name|opcode
range|:
literal|6
decl_stmt|;
block|}
name|pal_format
struct|;
block|}
name|alpha_instruction
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(ASSEMBLER) */
end_comment

begin_comment
comment|/*  *  *	Encoding of regular instructions  (Appendix C op cit)  *  */
end_comment

begin_comment
comment|/* OPCODE, bits 26..31 */
end_comment

begin_define
define|#
directive|define
name|op_pal
value|0x00
end_define

begin_comment
comment|/* see PAL sub-table */
end_comment

begin_comment
comment|/* 1..7 reserved */
end_comment

begin_define
define|#
directive|define
name|op_lda
value|0x08
end_define

begin_define
define|#
directive|define
name|op_ldah
value|0x09
end_define

begin_define
define|#
directive|define
name|op_ldbu
value|0x0a
end_define

begin_define
define|#
directive|define
name|op_ldq_u
value|0x0b
end_define

begin_define
define|#
directive|define
name|op_ldwu
value|0x0c
end_define

begin_define
define|#
directive|define
name|op_stw
value|0x0d
end_define

begin_define
define|#
directive|define
name|op_stb
value|0x0e
end_define

begin_define
define|#
directive|define
name|op_stq_u
value|0x0f
end_define

begin_define
define|#
directive|define
name|op_arit
value|0x10
end_define

begin_comment
comment|/* see ARIT sub-table */
end_comment

begin_define
define|#
directive|define
name|op_logical
value|0x11
end_define

begin_comment
comment|/* see LOGICAL sub-table */
end_comment

begin_define
define|#
directive|define
name|op_bit
value|0x12
end_define

begin_comment
comment|/* see BIT sub-table */
end_comment

begin_define
define|#
directive|define
name|op_mul
value|0x13
end_define

begin_comment
comment|/* see MUL sub-table */
end_comment

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|op_vax_float
value|0x15
end_define

begin_comment
comment|/* see FLOAT sub-table */
end_comment

begin_define
define|#
directive|define
name|op_ieee_float
value|0x16
end_define

begin_comment
comment|/* see FLOAT sub-table */
end_comment

begin_define
define|#
directive|define
name|op_any_float
value|0x17
end_define

begin_comment
comment|/* see FLOAT sub-table */
end_comment

begin_define
define|#
directive|define
name|op_special
value|0x18
end_define

begin_comment
comment|/* see SPECIAL sub-table */
end_comment

begin_define
define|#
directive|define
name|op_pal19
value|0x19
end_define

begin_comment
comment|/* reserved for pal code */
end_comment

begin_define
define|#
directive|define
name|op_j
value|0x1a
end_define

begin_comment
comment|/* see JUMP sub-table */
end_comment

begin_define
define|#
directive|define
name|op_pal1b
value|0x1b
end_define

begin_comment
comment|/* reserved for pal code */
end_comment

begin_define
define|#
directive|define
name|op_intmisc
value|0x1c
end_define

begin_comment
comment|/* see INTMISC sub-table */
end_comment

begin_define
define|#
directive|define
name|op_pal1d
value|0x1d
end_define

begin_comment
comment|/* reserved for pal code */
end_comment

begin_define
define|#
directive|define
name|op_pal1e
value|0x1e
end_define

begin_comment
comment|/* reserved for pal code */
end_comment

begin_define
define|#
directive|define
name|op_pal1f
value|0x1f
end_define

begin_comment
comment|/* reserved for pal code */
end_comment

begin_define
define|#
directive|define
name|op_ldf
value|0x20
end_define

begin_define
define|#
directive|define
name|op_ldg
value|0x21
end_define

begin_define
define|#
directive|define
name|op_lds
value|0x22
end_define

begin_define
define|#
directive|define
name|op_ldt
value|0x23
end_define

begin_define
define|#
directive|define
name|op_stf
value|0x24
end_define

begin_define
define|#
directive|define
name|op_stg
value|0x25
end_define

begin_define
define|#
directive|define
name|op_sts
value|0x26
end_define

begin_define
define|#
directive|define
name|op_stt
value|0x27
end_define

begin_define
define|#
directive|define
name|op_ldl
value|0x28
end_define

begin_define
define|#
directive|define
name|op_ldq
value|0x29
end_define

begin_define
define|#
directive|define
name|op_ldl_l
value|0x2a
end_define

begin_define
define|#
directive|define
name|op_ldq_l
value|0x2b
end_define

begin_define
define|#
directive|define
name|op_stl
value|0x2c
end_define

begin_define
define|#
directive|define
name|op_stq
value|0x2d
end_define

begin_define
define|#
directive|define
name|op_stl_c
value|0x2e
end_define

begin_define
define|#
directive|define
name|op_stq_c
value|0x2f
end_define

begin_define
define|#
directive|define
name|op_br
value|0x30
end_define

begin_define
define|#
directive|define
name|op_fbeq
value|0x31
end_define

begin_define
define|#
directive|define
name|op_fblt
value|0x32
end_define

begin_define
define|#
directive|define
name|op_fble
value|0x33
end_define

begin_define
define|#
directive|define
name|op_bsr
value|0x34
end_define

begin_define
define|#
directive|define
name|op_fbne
value|0x35
end_define

begin_define
define|#
directive|define
name|op_fbge
value|0x36
end_define

begin_define
define|#
directive|define
name|op_fbgt
value|0x37
end_define

begin_define
define|#
directive|define
name|op_blbc
value|0x38
end_define

begin_define
define|#
directive|define
name|op_beq
value|0x39
end_define

begin_define
define|#
directive|define
name|op_blt
value|0x3a
end_define

begin_define
define|#
directive|define
name|op_ble
value|0x3b
end_define

begin_define
define|#
directive|define
name|op_blbs
value|0x3c
end_define

begin_define
define|#
directive|define
name|op_bne
value|0x3d
end_define

begin_define
define|#
directive|define
name|op_bge
value|0x3e
end_define

begin_define
define|#
directive|define
name|op_bgt
value|0x3f
end_define

begin_comment
comment|/* PAL, "function" opcodes (bits 0..25) */
end_comment

begin_comment
comment|/*  * What we will implement is TBD.  These are the unprivileged ones  * that we probably have to support for compat reasons.  */
end_comment

begin_comment
comment|/* See<machine/pal.h> */
end_comment

begin_comment
comment|/* ARIT, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_addl
value|0x00
end_define

begin_define
define|#
directive|define
name|op_s4addl
value|0x02
end_define

begin_define
define|#
directive|define
name|op_subl
value|0x09
end_define

begin_define
define|#
directive|define
name|op_s4subl
value|0x0b
end_define

begin_define
define|#
directive|define
name|op_cmpbge
value|0x0f
end_define

begin_define
define|#
directive|define
name|op_s8addl
value|0x12
end_define

begin_define
define|#
directive|define
name|op_s8subl
value|0x1b
end_define

begin_define
define|#
directive|define
name|op_cmpult
value|0x1d
end_define

begin_define
define|#
directive|define
name|op_addq
value|0x20
end_define

begin_define
define|#
directive|define
name|op_s4addq
value|0x22
end_define

begin_define
define|#
directive|define
name|op_subq
value|0x29
end_define

begin_define
define|#
directive|define
name|op_s4subq
value|0x2b
end_define

begin_define
define|#
directive|define
name|op_cmpeq
value|0x2d
end_define

begin_define
define|#
directive|define
name|op_s8addq
value|0x32
end_define

begin_define
define|#
directive|define
name|op_s8subq
value|0x3b
end_define

begin_define
define|#
directive|define
name|op_cmpule
value|0x3d
end_define

begin_define
define|#
directive|define
name|op_addl_v
value|0x40
end_define

begin_define
define|#
directive|define
name|op_subl_v
value|0x49
end_define

begin_define
define|#
directive|define
name|op_cmplt
value|0x4d
end_define

begin_define
define|#
directive|define
name|op_addq_v
value|0x60
end_define

begin_define
define|#
directive|define
name|op_subq_v
value|0x69
end_define

begin_define
define|#
directive|define
name|op_cmple
value|0x6d
end_define

begin_comment
comment|/* LOGICAL, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_and
value|0x00
end_define

begin_define
define|#
directive|define
name|op_andnot
value|0x08
end_define

begin_comment
comment|/* bic */
end_comment

begin_define
define|#
directive|define
name|op_cmovlbs
value|0x14
end_define

begin_define
define|#
directive|define
name|op_cmovlbc
value|0x16
end_define

begin_define
define|#
directive|define
name|op_or
value|0x20
end_define

begin_comment
comment|/* bis */
end_comment

begin_define
define|#
directive|define
name|op_cmoveq
value|0x24
end_define

begin_define
define|#
directive|define
name|op_cmovne
value|0x26
end_define

begin_define
define|#
directive|define
name|op_ornot
value|0x28
end_define

begin_define
define|#
directive|define
name|op_xor
value|0x40
end_define

begin_define
define|#
directive|define
name|op_cmovlt
value|0x44
end_define

begin_define
define|#
directive|define
name|op_cmovge
value|0x46
end_define

begin_define
define|#
directive|define
name|op_xornot
value|0x48
end_define

begin_comment
comment|/* eqv */
end_comment

begin_define
define|#
directive|define
name|op_amask
value|0x61
end_define

begin_define
define|#
directive|define
name|op_cmovle
value|0x64
end_define

begin_define
define|#
directive|define
name|op_cmovgt
value|0x66
end_define

begin_define
define|#
directive|define
name|op_implver
value|0x6c
end_define

begin_comment
comment|/* BIT, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_mskbl
value|0x02
end_define

begin_define
define|#
directive|define
name|op_extbl
value|0x06
end_define

begin_define
define|#
directive|define
name|op_insbl
value|0x0b
end_define

begin_define
define|#
directive|define
name|op_mskwl
value|0x12
end_define

begin_define
define|#
directive|define
name|op_extwl
value|0x16
end_define

begin_define
define|#
directive|define
name|op_inswl
value|0x1b
end_define

begin_define
define|#
directive|define
name|op_mskll
value|0x22
end_define

begin_define
define|#
directive|define
name|op_extll
value|0x26
end_define

begin_define
define|#
directive|define
name|op_insll
value|0x2b
end_define

begin_define
define|#
directive|define
name|op_zap
value|0x30
end_define

begin_define
define|#
directive|define
name|op_zapnot
value|0x31
end_define

begin_define
define|#
directive|define
name|op_mskql
value|0x32
end_define

begin_define
define|#
directive|define
name|op_srl
value|0x34
end_define

begin_define
define|#
directive|define
name|op_extql
value|0x36
end_define

begin_define
define|#
directive|define
name|op_sll
value|0x39
end_define

begin_define
define|#
directive|define
name|op_insql
value|0x3b
end_define

begin_define
define|#
directive|define
name|op_sra
value|0x3c
end_define

begin_define
define|#
directive|define
name|op_mskwh
value|0x52
end_define

begin_define
define|#
directive|define
name|op_inswh
value|0x57
end_define

begin_define
define|#
directive|define
name|op_extwh
value|0x5a
end_define

begin_define
define|#
directive|define
name|op_msklh
value|0x62
end_define

begin_define
define|#
directive|define
name|op_inslh
value|0x67
end_define

begin_define
define|#
directive|define
name|op_extlh
value|0x6a
end_define

begin_define
define|#
directive|define
name|op_extqh
value|0x7a
end_define

begin_define
define|#
directive|define
name|op_insqh
value|0x77
end_define

begin_define
define|#
directive|define
name|op_mskqh
value|0x72
end_define

begin_comment
comment|/* MUL, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_mull
value|0x00
end_define

begin_define
define|#
directive|define
name|op_mulq_v
value|0x60
end_define

begin_define
define|#
directive|define
name|op_mull_v
value|0x40
end_define

begin_define
define|#
directive|define
name|op_umulh
value|0x30
end_define

begin_define
define|#
directive|define
name|op_mulq
value|0x20
end_define

begin_comment
comment|/* SPECIAL, "displacement" opcodes (bits 0..15)  */
end_comment

begin_define
define|#
directive|define
name|op_draint
value|0x0000
end_define

begin_define
define|#
directive|define
name|op_mb
value|0x4000
end_define

begin_define
define|#
directive|define
name|op_fetch
value|0x8000
end_define

begin_define
define|#
directive|define
name|op_fetch_m
value|0xa000
end_define

begin_define
define|#
directive|define
name|op_rpcc
value|0xc000
end_define

begin_define
define|#
directive|define
name|op_rc
value|0xe000
end_define

begin_define
define|#
directive|define
name|op_rs
value|0xf000
end_define

begin_comment
comment|/* JUMP, "action" opcodes (bits 14..15) */
end_comment

begin_define
define|#
directive|define
name|op_jmp
value|0x0
end_define

begin_define
define|#
directive|define
name|op_jsr
value|0x1
end_define

begin_define
define|#
directive|define
name|op_ret
value|0x2
end_define

begin_define
define|#
directive|define
name|op_jcr
value|0x3
end_define

begin_comment
comment|/* INTMISC, "function" opcodes (operate format) */
end_comment

begin_define
define|#
directive|define
name|op_sextb
value|0x00
end_define

begin_define
define|#
directive|define
name|op_sextw
value|0x01
end_define

begin_define
define|#
directive|define
name|op_ctpop
value|0x30
end_define

begin_define
define|#
directive|define
name|op_perr
value|0x31
end_define

begin_define
define|#
directive|define
name|op_ctlz
value|0x32
end_define

begin_define
define|#
directive|define
name|op_cttz
value|0x33
end_define

begin_define
define|#
directive|define
name|op_unpkbw
value|0x34
end_define

begin_define
define|#
directive|define
name|op_unpkbl
value|0x35
end_define

begin_define
define|#
directive|define
name|op_pkwb
value|0x36
end_define

begin_define
define|#
directive|define
name|op_pklb
value|0x37
end_define

begin_define
define|#
directive|define
name|op_minsb8
value|0x38
end_define

begin_define
define|#
directive|define
name|op_minsw4
value|0x39
end_define

begin_define
define|#
directive|define
name|op_minub8
value|0x3a
end_define

begin_define
define|#
directive|define
name|op_minuw4
value|0x3b
end_define

begin_define
define|#
directive|define
name|op_maxub8
value|0x3c
end_define

begin_define
define|#
directive|define
name|op_maxuw4
value|0x3d
end_define

begin_define
define|#
directive|define
name|op_maxsb8
value|0x3e
end_define

begin_define
define|#
directive|define
name|op_maxsw4
value|0x3f
end_define

begin_define
define|#
directive|define
name|op_ftoit
value|0x70
end_define

begin_define
define|#
directive|define
name|op_ftois
value|0x78
end_define

begin_comment
comment|/*  *  *	Encoding of floating point instructions (pagg. C-5..6 op cit)  *  *	Load and store operations use opcodes op_ldf..op_stt  */
end_comment

begin_comment
comment|/* any FLOAT, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_cvtlq
value|0x010
end_define

begin_define
define|#
directive|define
name|op_cpys
value|0x020
end_define

begin_define
define|#
directive|define
name|op_cpysn
value|0x021
end_define

begin_define
define|#
directive|define
name|op_cpyse
value|0x022
end_define

begin_define
define|#
directive|define
name|op_mt_fpcr
value|0x024
end_define

begin_define
define|#
directive|define
name|op_mf_fpcr
value|0x025
end_define

begin_define
define|#
directive|define
name|op_fcmoveq
value|0x02a
end_define

begin_define
define|#
directive|define
name|op_fcmovne
value|0x02b
end_define

begin_define
define|#
directive|define
name|op_fcmovlt
value|0x02c
end_define

begin_define
define|#
directive|define
name|op_fcmovge
value|0x02d
end_define

begin_define
define|#
directive|define
name|op_fcmovle
value|0x02e
end_define

begin_define
define|#
directive|define
name|op_fcmovgt
value|0x02f
end_define

begin_define
define|#
directive|define
name|op_cvtql
value|0x030
end_define

begin_define
define|#
directive|define
name|op_cvtql_v
value|0x130
end_define

begin_define
define|#
directive|define
name|op_cvtql_sv
value|0x330
end_define

begin_comment
comment|/* ieee FLOAT, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_adds_c
value|0x000
end_define

begin_define
define|#
directive|define
name|op_subs_c
value|0x001
end_define

begin_define
define|#
directive|define
name|op_muls_c
value|0x002
end_define

begin_define
define|#
directive|define
name|op_divs_c
value|0x003
end_define

begin_define
define|#
directive|define
name|op_addt_c
value|0x020
end_define

begin_define
define|#
directive|define
name|op_subt_c
value|0x021
end_define

begin_define
define|#
directive|define
name|op_mult_c
value|0x022
end_define

begin_define
define|#
directive|define
name|op_divt_c
value|0x023
end_define

begin_define
define|#
directive|define
name|op_cvtts_c
value|0x02c
end_define

begin_define
define|#
directive|define
name|op_cvttq_c
value|0x02f
end_define

begin_define
define|#
directive|define
name|op_cvtqs_c
value|0x03c
end_define

begin_define
define|#
directive|define
name|op_cvtqt_c
value|0x03e
end_define

begin_define
define|#
directive|define
name|op_adds_m
value|0x040
end_define

begin_define
define|#
directive|define
name|op_subs_m
value|0x041
end_define

begin_define
define|#
directive|define
name|op_muls_m
value|0x042
end_define

begin_define
define|#
directive|define
name|op_divs_m
value|0x043
end_define

begin_define
define|#
directive|define
name|op_addt_m
value|0x060
end_define

begin_define
define|#
directive|define
name|op_subt_m
value|0x061
end_define

begin_define
define|#
directive|define
name|op_mult_m
value|0x062
end_define

begin_define
define|#
directive|define
name|op_divt_m
value|0x063
end_define

begin_define
define|#
directive|define
name|op_cvtts_m
value|0x06c
end_define

begin_define
define|#
directive|define
name|op_cvtqs_m
value|0x07c
end_define

begin_define
define|#
directive|define
name|op_cvtqt_m
value|0x07e
end_define

begin_define
define|#
directive|define
name|op_adds
value|0x080
end_define

begin_define
define|#
directive|define
name|op_subs
value|0x081
end_define

begin_define
define|#
directive|define
name|op_muls
value|0x082
end_define

begin_define
define|#
directive|define
name|op_divs
value|0x083
end_define

begin_define
define|#
directive|define
name|op_addt
value|0x0a0
end_define

begin_define
define|#
directive|define
name|op_subt
value|0x0a1
end_define

begin_define
define|#
directive|define
name|op_mult
value|0x0a2
end_define

begin_define
define|#
directive|define
name|op_divt
value|0x0a3
end_define

begin_define
define|#
directive|define
name|op_cmptun
value|0x0a4
end_define

begin_define
define|#
directive|define
name|op_cmpteq
value|0x0a5
end_define

begin_define
define|#
directive|define
name|op_cmptlt
value|0x0a6
end_define

begin_define
define|#
directive|define
name|op_cmptle
value|0x0a7
end_define

begin_define
define|#
directive|define
name|op_cvtts
value|0x0ac
end_define

begin_define
define|#
directive|define
name|op_cvttq
value|0x0af
end_define

begin_define
define|#
directive|define
name|op_cvtqs
value|0x0bc
end_define

begin_define
define|#
directive|define
name|op_cvtqt
value|0x0be
end_define

begin_define
define|#
directive|define
name|op_adds_d
value|0x0c0
end_define

begin_define
define|#
directive|define
name|op_subs_d
value|0x0c1
end_define

begin_define
define|#
directive|define
name|op_muls_d
value|0x0c2
end_define

begin_define
define|#
directive|define
name|op_divs_d
value|0x0c3
end_define

begin_define
define|#
directive|define
name|op_addt_d
value|0x0e0
end_define

begin_define
define|#
directive|define
name|op_subt_d
value|0x0e1
end_define

begin_define
define|#
directive|define
name|op_mult_d
value|0x0e2
end_define

begin_define
define|#
directive|define
name|op_divt_d
value|0x0e3
end_define

begin_define
define|#
directive|define
name|op_cvtts_d
value|0x0ec
end_define

begin_define
define|#
directive|define
name|op_cvtqs_d
value|0x0fc
end_define

begin_define
define|#
directive|define
name|op_cvtqt_d
value|0x0fe
end_define

begin_define
define|#
directive|define
name|op_adds_uc
value|0x100
end_define

begin_define
define|#
directive|define
name|op_subs_uc
value|0x101
end_define

begin_define
define|#
directive|define
name|op_muls_uc
value|0x102
end_define

begin_define
define|#
directive|define
name|op_divs_uc
value|0x103
end_define

begin_define
define|#
directive|define
name|op_addt_uc
value|0x120
end_define

begin_define
define|#
directive|define
name|op_subt_uc
value|0x121
end_define

begin_define
define|#
directive|define
name|op_mult_uc
value|0x122
end_define

begin_define
define|#
directive|define
name|op_divt_uc
value|0x123
end_define

begin_define
define|#
directive|define
name|op_cvtts_uc
value|0x12c
end_define

begin_define
define|#
directive|define
name|op_cvttq_vc
value|0x12f
end_define

begin_define
define|#
directive|define
name|op_adds_um
value|0x140
end_define

begin_define
define|#
directive|define
name|op_subs_um
value|0x141
end_define

begin_define
define|#
directive|define
name|op_muls_um
value|0x142
end_define

begin_define
define|#
directive|define
name|op_divs_um
value|0x143
end_define

begin_define
define|#
directive|define
name|op_addt_um
value|0x160
end_define

begin_define
define|#
directive|define
name|op_subt_um
value|0x161
end_define

begin_define
define|#
directive|define
name|op_mult_um
value|0x162
end_define

begin_define
define|#
directive|define
name|op_divt_um
value|0x163
end_define

begin_define
define|#
directive|define
name|op_cvtts_um
value|0x16c
end_define

begin_define
define|#
directive|define
name|op_adds_u
value|0x180
end_define

begin_define
define|#
directive|define
name|op_subs_u
value|0x181
end_define

begin_define
define|#
directive|define
name|op_muls_u
value|0x182
end_define

begin_define
define|#
directive|define
name|op_divs_u
value|0x183
end_define

begin_define
define|#
directive|define
name|op_addt_u
value|0x1a0
end_define

begin_define
define|#
directive|define
name|op_subt_u
value|0x1a1
end_define

begin_define
define|#
directive|define
name|op_mult_u
value|0x1a2
end_define

begin_define
define|#
directive|define
name|op_divt_u
value|0x1a3
end_define

begin_define
define|#
directive|define
name|op_cvtts_u
value|0x1ac
end_define

begin_define
define|#
directive|define
name|op_cvttq_v
value|0x1af
end_define

begin_define
define|#
directive|define
name|op_adds_ud
value|0x1c0
end_define

begin_define
define|#
directive|define
name|op_subs_ud
value|0x1c1
end_define

begin_define
define|#
directive|define
name|op_muls_ud
value|0x1c2
end_define

begin_define
define|#
directive|define
name|op_divs_ud
value|0x1c3
end_define

begin_define
define|#
directive|define
name|op_addt_ud
value|0x1e0
end_define

begin_define
define|#
directive|define
name|op_subt_ud
value|0x1e1
end_define

begin_define
define|#
directive|define
name|op_mult_ud
value|0x1e2
end_define

begin_define
define|#
directive|define
name|op_divt_ud
value|0x1e3
end_define

begin_define
define|#
directive|define
name|op_cvtts_ud
value|0x1ec
end_define

begin_define
define|#
directive|define
name|op_adds_suc
value|0x500
end_define

begin_define
define|#
directive|define
name|op_subs_suc
value|0x501
end_define

begin_define
define|#
directive|define
name|op_muls_suc
value|0x502
end_define

begin_define
define|#
directive|define
name|op_divs_suc
value|0x503
end_define

begin_define
define|#
directive|define
name|op_addt_suc
value|0x520
end_define

begin_define
define|#
directive|define
name|op_subt_suc
value|0x521
end_define

begin_define
define|#
directive|define
name|op_mult_suc
value|0x522
end_define

begin_define
define|#
directive|define
name|op_divt_suc
value|0x523
end_define

begin_define
define|#
directive|define
name|op_cvtts_suc
value|0x52c
end_define

begin_define
define|#
directive|define
name|op_cvttq_svc
value|0x52f
end_define

begin_define
define|#
directive|define
name|op_adds_sum
value|0x540
end_define

begin_define
define|#
directive|define
name|op_subs_sum
value|0x541
end_define

begin_define
define|#
directive|define
name|op_muls_sum
value|0x542
end_define

begin_define
define|#
directive|define
name|op_divs_sum
value|0x543
end_define

begin_define
define|#
directive|define
name|op_addt_sum
value|0x560
end_define

begin_define
define|#
directive|define
name|op_subt_sum
value|0x561
end_define

begin_define
define|#
directive|define
name|op_mult_sum
value|0x562
end_define

begin_define
define|#
directive|define
name|op_divt_sum
value|0x563
end_define

begin_define
define|#
directive|define
name|op_cvtts_sum
value|0x56c
end_define

begin_define
define|#
directive|define
name|op_adds_su
value|0x580
end_define

begin_define
define|#
directive|define
name|op_subs_su
value|0x581
end_define

begin_define
define|#
directive|define
name|op_muls_su
value|0x582
end_define

begin_define
define|#
directive|define
name|op_divs_su
value|0x583
end_define

begin_define
define|#
directive|define
name|op_addt_su
value|0x5a0
end_define

begin_define
define|#
directive|define
name|op_subt_su
value|0x5a1
end_define

begin_define
define|#
directive|define
name|op_mult_su
value|0x5a2
end_define

begin_define
define|#
directive|define
name|op_divt_su
value|0x5a3
end_define

begin_define
define|#
directive|define
name|op_cmptun_su
value|0x5a4
end_define

begin_define
define|#
directive|define
name|op_cmpteq_su
value|0x5a5
end_define

begin_define
define|#
directive|define
name|op_cmptlt_su
value|0x5a6
end_define

begin_define
define|#
directive|define
name|op_cmptle_su
value|0x5a7
end_define

begin_define
define|#
directive|define
name|op_cvtts_su
value|0x5ac
end_define

begin_define
define|#
directive|define
name|op_cvttq_sv
value|0x5af
end_define

begin_define
define|#
directive|define
name|op_adds_sud
value|0x5c0
end_define

begin_define
define|#
directive|define
name|op_subs_sud
value|0x5c1
end_define

begin_define
define|#
directive|define
name|op_muls_sud
value|0x5c2
end_define

begin_define
define|#
directive|define
name|op_divs_sud
value|0x5c3
end_define

begin_define
define|#
directive|define
name|op_addt_sud
value|0x5e0
end_define

begin_define
define|#
directive|define
name|op_subt_sud
value|0x5e1
end_define

begin_define
define|#
directive|define
name|op_mult_sud
value|0x5e2
end_define

begin_define
define|#
directive|define
name|op_divt_sud
value|0x5e3
end_define

begin_define
define|#
directive|define
name|op_cvtts_sud
value|0x5ec
end_define

begin_define
define|#
directive|define
name|op_adds_suic
value|0x700
end_define

begin_define
define|#
directive|define
name|op_subs_suic
value|0x701
end_define

begin_define
define|#
directive|define
name|op_muls_suic
value|0x702
end_define

begin_define
define|#
directive|define
name|op_divs_suic
value|0x703
end_define

begin_define
define|#
directive|define
name|op_addt_suic
value|0x720
end_define

begin_define
define|#
directive|define
name|op_subt_suic
value|0x721
end_define

begin_define
define|#
directive|define
name|op_mult_suic
value|0x722
end_define

begin_define
define|#
directive|define
name|op_divt_suic
value|0x723
end_define

begin_define
define|#
directive|define
name|op_cvtts_suic
value|0x72c
end_define

begin_define
define|#
directive|define
name|op_cvttq_svic
value|0x72f
end_define

begin_define
define|#
directive|define
name|op_cvtqs_suic
value|0x73c
end_define

begin_define
define|#
directive|define
name|op_cvtqt_suic
value|0x73e
end_define

begin_define
define|#
directive|define
name|op_adds_suim
value|0x740
end_define

begin_define
define|#
directive|define
name|op_subs_suim
value|0x741
end_define

begin_define
define|#
directive|define
name|op_muls_suim
value|0x742
end_define

begin_define
define|#
directive|define
name|op_divs_suim
value|0x743
end_define

begin_define
define|#
directive|define
name|op_addt_suim
value|0x760
end_define

begin_define
define|#
directive|define
name|op_subt_suim
value|0x761
end_define

begin_define
define|#
directive|define
name|op_mult_suim
value|0x762
end_define

begin_define
define|#
directive|define
name|op_divt_suim
value|0x763
end_define

begin_define
define|#
directive|define
name|op_cvtts_suim
value|0x76c
end_define

begin_define
define|#
directive|define
name|op_cvtqs_suim
value|0x77c
end_define

begin_define
define|#
directive|define
name|op_cvtqt_suim
value|0x77e
end_define

begin_define
define|#
directive|define
name|op_adds_sui
value|0x780
end_define

begin_define
define|#
directive|define
name|op_subs_sui
value|0x781
end_define

begin_define
define|#
directive|define
name|op_muls_sui
value|0x782
end_define

begin_define
define|#
directive|define
name|op_divs_sui
value|0x783
end_define

begin_define
define|#
directive|define
name|op_addt_sui
value|0x7a0
end_define

begin_define
define|#
directive|define
name|op_subt_sui
value|0x7a1
end_define

begin_define
define|#
directive|define
name|op_mult_sui
value|0x7a2
end_define

begin_define
define|#
directive|define
name|op_divt_sui
value|0x7a3
end_define

begin_define
define|#
directive|define
name|op_cvtts_sui
value|0x7ac
end_define

begin_define
define|#
directive|define
name|op_cvttq_svi
value|0x7af
end_define

begin_define
define|#
directive|define
name|op_cvtqs_sui
value|0x7bc
end_define

begin_define
define|#
directive|define
name|op_cvtqt_sui
value|0x7be
end_define

begin_define
define|#
directive|define
name|op_adds_suid
value|0x7c0
end_define

begin_define
define|#
directive|define
name|op_subs_suid
value|0x7c1
end_define

begin_define
define|#
directive|define
name|op_muls_suid
value|0x7c2
end_define

begin_define
define|#
directive|define
name|op_divs_suid
value|0x7c3
end_define

begin_define
define|#
directive|define
name|op_addt_suid
value|0x7e0
end_define

begin_define
define|#
directive|define
name|op_subt_suid
value|0x7e1
end_define

begin_define
define|#
directive|define
name|op_mult_suid
value|0x7e2
end_define

begin_define
define|#
directive|define
name|op_divt_suid
value|0x7e3
end_define

begin_define
define|#
directive|define
name|op_cvtts_suid
value|0x7ec
end_define

begin_define
define|#
directive|define
name|op_cvtqs_suid
value|0x7fc
end_define

begin_define
define|#
directive|define
name|op_cvtqt_suid
value|0x7fe
end_define

begin_comment
comment|/* vax FLOAT, "function" opcodes (bits 5..11)  */
end_comment

begin_define
define|#
directive|define
name|op_addf_c
value|0x000
end_define

begin_define
define|#
directive|define
name|op_subf_c
value|0x001
end_define

begin_define
define|#
directive|define
name|op_mulf_c
value|0x002
end_define

begin_define
define|#
directive|define
name|op_divf_c
value|0x003
end_define

begin_define
define|#
directive|define
name|op_cvtdg_c
value|0x01e
end_define

begin_define
define|#
directive|define
name|op_addg_c
value|0x020
end_define

begin_define
define|#
directive|define
name|op_subg_c
value|0x021
end_define

begin_define
define|#
directive|define
name|op_mulg_c
value|0x022
end_define

begin_define
define|#
directive|define
name|op_divg_c
value|0x023
end_define

begin_define
define|#
directive|define
name|op_cvtgf_c
value|0x02c
end_define

begin_define
define|#
directive|define
name|op_cvtgd_c
value|0x02d
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_c
value|0x02f
end_define

begin_define
define|#
directive|define
name|op_cvtqf_c
value|0x03c
end_define

begin_define
define|#
directive|define
name|op_cvtqg_c
value|0x03e
end_define

begin_define
define|#
directive|define
name|op_addf
value|0x080
end_define

begin_define
define|#
directive|define
name|op_subf
value|0x081
end_define

begin_define
define|#
directive|define
name|op_mulf
value|0x082
end_define

begin_define
define|#
directive|define
name|op_divf
value|0x083
end_define

begin_define
define|#
directive|define
name|op_cvtdg
value|0x09e
end_define

begin_define
define|#
directive|define
name|op_addg
value|0x0a0
end_define

begin_define
define|#
directive|define
name|op_subg
value|0x0a1
end_define

begin_define
define|#
directive|define
name|op_mulg
value|0x0a2
end_define

begin_define
define|#
directive|define
name|op_divg
value|0x0a3
end_define

begin_define
define|#
directive|define
name|op_cmpgeq
value|0x0a5
end_define

begin_define
define|#
directive|define
name|op_cmpglt
value|0x0a6
end_define

begin_define
define|#
directive|define
name|op_cmpgle
value|0x0a7
end_define

begin_define
define|#
directive|define
name|op_cvtgf
value|0x0ac
end_define

begin_define
define|#
directive|define
name|op_cvtgd
value|0x0ad
end_define

begin_define
define|#
directive|define
name|op_cvtgq
value|0x0af
end_define

begin_define
define|#
directive|define
name|op_cvtqf
value|0x0bc
end_define

begin_define
define|#
directive|define
name|op_cvtqg
value|0x0be
end_define

begin_define
define|#
directive|define
name|op_addf_uc
value|0x100
end_define

begin_define
define|#
directive|define
name|op_subf_uc
value|0x101
end_define

begin_define
define|#
directive|define
name|op_mulf_uc
value|0x102
end_define

begin_define
define|#
directive|define
name|op_divf_uc
value|0x103
end_define

begin_define
define|#
directive|define
name|op_cvtdg_uc
value|0x11e
end_define

begin_define
define|#
directive|define
name|op_addg_uc
value|0x120
end_define

begin_define
define|#
directive|define
name|op_subg_uc
value|0x121
end_define

begin_define
define|#
directive|define
name|op_mulg_uc
value|0x122
end_define

begin_define
define|#
directive|define
name|op_divg_uc
value|0x123
end_define

begin_define
define|#
directive|define
name|op_cvtgf_uc
value|0x12c
end_define

begin_define
define|#
directive|define
name|op_cvtgd_uc
value|0x12d
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_vc
value|0x12f
end_define

begin_define
define|#
directive|define
name|op_addf_u
value|0x180
end_define

begin_define
define|#
directive|define
name|op_subf_u
value|0x181
end_define

begin_define
define|#
directive|define
name|op_mulf_u
value|0x182
end_define

begin_define
define|#
directive|define
name|op_divf_u
value|0x183
end_define

begin_define
define|#
directive|define
name|op_cvtdg_u
value|0x19e
end_define

begin_define
define|#
directive|define
name|op_addg_u
value|0x1a0
end_define

begin_define
define|#
directive|define
name|op_subg_u
value|0x1a1
end_define

begin_define
define|#
directive|define
name|op_mulg_u
value|0x1a2
end_define

begin_define
define|#
directive|define
name|op_divg_u
value|0x1a3
end_define

begin_define
define|#
directive|define
name|op_cvtgf_u
value|0x1ac
end_define

begin_define
define|#
directive|define
name|op_cvtgd_u
value|0x1ad
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_v
value|0x1af
end_define

begin_define
define|#
directive|define
name|op_addf_sc
value|0x400
end_define

begin_define
define|#
directive|define
name|op_subf_sc
value|0x401
end_define

begin_define
define|#
directive|define
name|op_mulf_sc
value|0x402
end_define

begin_define
define|#
directive|define
name|op_divf_sc
value|0x403
end_define

begin_define
define|#
directive|define
name|op_cvtdg_sc
value|0x41e
end_define

begin_define
define|#
directive|define
name|op_addg_sc
value|0x420
end_define

begin_define
define|#
directive|define
name|op_subg_sc
value|0x421
end_define

begin_define
define|#
directive|define
name|op_mulg_sc
value|0x422
end_define

begin_define
define|#
directive|define
name|op_divg_sc
value|0x423
end_define

begin_define
define|#
directive|define
name|op_cvtgf_sc
value|0x42c
end_define

begin_define
define|#
directive|define
name|op_cvtgd_sc
value|0x42d
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_sc
value|0x42f
end_define

begin_define
define|#
directive|define
name|op_cvtqf_sc
value|0x43c
end_define

begin_define
define|#
directive|define
name|op_cvtqg_sc
value|0x43e
end_define

begin_define
define|#
directive|define
name|op_addf_s
value|0x480
end_define

begin_define
define|#
directive|define
name|op_subf_s
value|0x481
end_define

begin_define
define|#
directive|define
name|op_mulf_s
value|0x482
end_define

begin_define
define|#
directive|define
name|op_divf_s
value|0x483
end_define

begin_define
define|#
directive|define
name|op_cvtdg_s
value|0x49e
end_define

begin_define
define|#
directive|define
name|op_addg_s
value|0x4a0
end_define

begin_define
define|#
directive|define
name|op_subg_s
value|0x4a1
end_define

begin_define
define|#
directive|define
name|op_mulg_s
value|0x4a2
end_define

begin_define
define|#
directive|define
name|op_divg_s
value|0x4a3
end_define

begin_define
define|#
directive|define
name|op_cmpgeq_s
value|0x4a5
end_define

begin_define
define|#
directive|define
name|op_cmpglt_s
value|0x4a6
end_define

begin_define
define|#
directive|define
name|op_cmpgle_s
value|0x4a7
end_define

begin_define
define|#
directive|define
name|op_cvtgf_s
value|0x4ac
end_define

begin_define
define|#
directive|define
name|op_cvtgd_s
value|0x4ad
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_s
value|0x4af
end_define

begin_define
define|#
directive|define
name|op_cvtqf_s
value|0x4bc
end_define

begin_define
define|#
directive|define
name|op_cvtqg_s
value|0x4be
end_define

begin_define
define|#
directive|define
name|op_addf_suc
value|0x500
end_define

begin_define
define|#
directive|define
name|op_subf_suc
value|0x501
end_define

begin_define
define|#
directive|define
name|op_mulf_suc
value|0x502
end_define

begin_define
define|#
directive|define
name|op_divf_suc
value|0x503
end_define

begin_define
define|#
directive|define
name|op_cvtdg_suc
value|0x51e
end_define

begin_define
define|#
directive|define
name|op_addg_suc
value|0x520
end_define

begin_define
define|#
directive|define
name|op_subg_suc
value|0x521
end_define

begin_define
define|#
directive|define
name|op_mulg_suc
value|0x522
end_define

begin_define
define|#
directive|define
name|op_divg_suc
value|0x523
end_define

begin_define
define|#
directive|define
name|op_cvtgf_suc
value|0x52c
end_define

begin_define
define|#
directive|define
name|op_cvtgd_suc
value|0x52d
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_svc
value|0x52f
end_define

begin_define
define|#
directive|define
name|op_addf_su
value|0x580
end_define

begin_define
define|#
directive|define
name|op_subf_su
value|0x581
end_define

begin_define
define|#
directive|define
name|op_mulf_su
value|0x582
end_define

begin_define
define|#
directive|define
name|op_divf_su
value|0x583
end_define

begin_define
define|#
directive|define
name|op_cvtdg_su
value|0x59e
end_define

begin_define
define|#
directive|define
name|op_addg_su
value|0x5a0
end_define

begin_define
define|#
directive|define
name|op_subg_su
value|0x5a1
end_define

begin_define
define|#
directive|define
name|op_mulg_su
value|0x5a2
end_define

begin_define
define|#
directive|define
name|op_divg_su
value|0x5a3
end_define

begin_define
define|#
directive|define
name|op_cvtgf_su
value|0x5ac
end_define

begin_define
define|#
directive|define
name|op_cvtgd_su
value|0x5ad
end_define

begin_define
define|#
directive|define
name|op_cvtgqg_sv
value|0x5af
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALPHA_INSTRUCTION_H_ */
end_comment

end_unit

