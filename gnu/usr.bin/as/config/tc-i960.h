begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-i960.h - Basic 80960 instruction formats.    Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I960
end_ifndef

begin_define
define|#
directive|define
name|TC_I960
value|1
end_define

begin_define
define|#
directive|define
name|NO_LISTING
end_define

begin_comment
comment|/*  * The 'COJ' instructions are actually COBR instructions with the 'b' in  * the mnemonic replaced by a 'j';  they are ALWAYS "de-optimized" if necessary:  * if the displacement will not fit in 13 bits, the assembler will replace them  * with the corresponding compare and branch instructions.  *  * All of the 'MEMn' instructions are the same format; the 'n' in the name  * indicates the default index scale factor (the size of the datum operated on).  *  * The FBRA formats are not actually an instruction format.  They are the  * "convenience directives" for branching on floating-point comparisons,  * each of which generates 2 instructions (a 'bno' and one other branch).  *  * The CALLJ format is not actually an instruction format.  It indicates that  * the instruction generated (a CTRL-format 'call') should have its relocation  * specially flagged for link-time replacement with a 'bal' or 'calls' if  * appropriate.  */
end_comment

begin_comment
comment|/* tailor gas */
end_comment

begin_define
define|#
directive|define
name|SYMBOLS_NEED_BACKPOINTERS
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
end_define

begin_define
define|#
directive|define
name|WANT_BITFIELDS
end_define

begin_comment
comment|/* tailor the coff format */
end_comment

begin_define
define|#
directive|define
name|OBJ_COFF_SECTION_HEADER_HAS_ALIGNMENT
end_define

begin_define
define|#
directive|define
name|OBJ_COFF_MAX_AUXENTRIES
value|(2)
end_define

begin_comment
comment|/* other */
end_comment

begin_define
define|#
directive|define
name|CTRL
value|0
end_define

begin_define
define|#
directive|define
name|COBR
value|1
end_define

begin_define
define|#
directive|define
name|COJ
value|2
end_define

begin_define
define|#
directive|define
name|REG
value|3
end_define

begin_define
define|#
directive|define
name|MEM1
value|4
end_define

begin_define
define|#
directive|define
name|MEM2
value|5
end_define

begin_define
define|#
directive|define
name|MEM4
value|6
end_define

begin_define
define|#
directive|define
name|MEM8
value|7
end_define

begin_define
define|#
directive|define
name|MEM12
value|8
end_define

begin_define
define|#
directive|define
name|MEM16
value|9
end_define

begin_define
define|#
directive|define
name|FBRA
value|10
end_define

begin_define
define|#
directive|define
name|CALLJ
value|11
end_define

begin_comment
comment|/* Masks for the mode bits in REG format instructions */
end_comment

begin_define
define|#
directive|define
name|M1
value|0x0800
end_define

begin_define
define|#
directive|define
name|M2
value|0x1000
end_define

begin_define
define|#
directive|define
name|M3
value|0x2000
end_define

begin_comment
comment|/* Generate the 12-bit opcode for a REG format instruction by placing the  * high 8 bits in instruction bits 24-31, the low 4 bits in instruction bits  * 7-10.  */
end_comment

begin_define
define|#
directive|define
name|REG_OPC
parameter_list|(
name|opc
parameter_list|)
value|((opc& 0xff0)<< 20) | ((opc& 0xf)<< 7)
end_define

begin_comment
comment|/* Generate a template for a REG format instruction:  place the opcode bits  * in the appropriate fields and OR in mode bits for the operands that will not  * be used.  I.e.,  *		set m1=1, if src1 will not be used  *		set m2=1, if src2 will not be used  *		set m3=1, if dst  will not be used  *  * Setting the "unused" mode bits to 1 speeds up instruction execution(!).  * The information is also useful to us because some 1-operand REG instructions  * use the src1 field, others the dst field; and some 2-operand REG instructions  * use src1/src2, others src1/dst.  The set mode bits enable us to distinguish.  */
end_comment

begin_define
define|#
directive|define
name|R_0
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) | M1 | M2 | M3 )
end_define

begin_comment
comment|/* No operands      */
end_comment

begin_define
define|#
directive|define
name|R_1
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) | M2 | M3 )
end_define

begin_comment
comment|/* 1 operand: src1  */
end_comment

begin_define
define|#
directive|define
name|R_1D
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) | M1 | M2 )
end_define

begin_comment
comment|/* 1 operand: dst   */
end_comment

begin_define
define|#
directive|define
name|R_2
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) | M3 )
end_define

begin_comment
comment|/* 2 ops: src1/src2 */
end_comment

begin_define
define|#
directive|define
name|R_2D
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) | M2 )
end_define

begin_comment
comment|/* 2 ops: src1/dst  */
end_comment

begin_define
define|#
directive|define
name|R_3
parameter_list|(
name|opc
parameter_list|)
value|( REG_OPC(opc) )
end_define

begin_comment
comment|/* 3 operands       */
end_comment

begin_comment
comment|/* DESCRIPTOR BYTES FOR REGISTER OPERANDS  *  * Interpret names as follows:  *	R:   global or local register only  *	RS:  global, local, or (if target allows) special-function register only  *	RL:  global or local register, or integer literal  *	RSL: global, local, or (if target allows) special-function register;  *		or integer literal  *	F:   global, local, or floating-point register  *	FL:  global, local, or floating-point register; or literal (including  *		floating point)  *  * A number appended to a name indicates that registers must be aligned,  * as follows:  *	2: register number must be multiple of 2  *	4: register number must be multiple of 4  */
end_comment

begin_define
define|#
directive|define
name|SFR
value|0x10
end_define

begin_comment
comment|/* Mask for the "sfr-OK" bit */
end_comment

begin_define
define|#
directive|define
name|LIT
value|0x08
end_define

begin_comment
comment|/* Mask for the "literal-OK" bit */
end_comment

begin_define
define|#
directive|define
name|FP
value|0x04
end_define

begin_comment
comment|/* Mask for "floating-point-OK" bit */
end_comment

begin_comment
comment|/* This macro ors the bits together.  Note that 'align' is a mask  * for the low 0, 1, or 2 bits of the register number, as appropriate.  */
end_comment

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|align
parameter_list|,
name|lit
parameter_list|,
name|fp
parameter_list|,
name|sfr
parameter_list|)
value|( align | lit | fp | sfr )
end_define

begin_define
define|#
directive|define
name|R
value|OP( 0, 0,   0,  0   )
end_define

begin_define
define|#
directive|define
name|RS
value|OP( 0, 0,   0,  SFR )
end_define

begin_define
define|#
directive|define
name|RL
value|OP( 0, LIT, 0,  0   )
end_define

begin_define
define|#
directive|define
name|RSL
value|OP( 0, LIT, 0,  SFR )
end_define

begin_define
define|#
directive|define
name|F
value|OP( 0, 0,   FP, 0   )
end_define

begin_define
define|#
directive|define
name|FL
value|OP( 0, LIT, FP, 0   )
end_define

begin_define
define|#
directive|define
name|R2
value|OP( 1, 0,   0,  0   )
end_define

begin_define
define|#
directive|define
name|RL2
value|OP( 1, LIT, 0,  0   )
end_define

begin_define
define|#
directive|define
name|F2
value|OP( 1, 0,   FP, 0   )
end_define

begin_define
define|#
directive|define
name|FL2
value|OP( 1, LIT, FP, 0   )
end_define

begin_define
define|#
directive|define
name|R4
value|OP( 3, 0,   0,  0   )
end_define

begin_define
define|#
directive|define
name|RL4
value|OP( 3, LIT, 0,  0   )
end_define

begin_define
define|#
directive|define
name|F4
value|OP( 3, 0,   FP, 0   )
end_define

begin_define
define|#
directive|define
name|FL4
value|OP( 3, LIT, FP, 0   )
end_define

begin_define
define|#
directive|define
name|M
value|0x7f
end_define

begin_comment
comment|/* Memory operand (MEMA& MEMB format instructions) */
end_comment

begin_comment
comment|/* Macros to extract info from the register operand descriptor byte 'od'.  */
end_comment

begin_define
define|#
directive|define
name|SFR_OK
parameter_list|(
name|od
parameter_list|)
value|(od& SFR)
end_define

begin_comment
comment|/* TRUE if sfr operand allowed */
end_comment

begin_define
define|#
directive|define
name|LIT_OK
parameter_list|(
name|od
parameter_list|)
value|(od& LIT)
end_define

begin_comment
comment|/* TRUE if literal operand allowed */
end_comment

begin_define
define|#
directive|define
name|FP_OK
parameter_list|(
name|od
parameter_list|)
value|(od& FP)
end_define

begin_comment
comment|/* TRUE if floating-point op allowed */
end_comment

begin_define
define|#
directive|define
name|REG_ALIGN
parameter_list|(
name|od
parameter_list|,
name|n
parameter_list|)
value|((od& 0x3& n) == 0)
end_define

begin_comment
comment|/* TRUE if reg #n is properly aligned */
end_comment

begin_define
define|#
directive|define
name|MEMOP
parameter_list|(
name|od
parameter_list|)
value|(od == M)
end_define

begin_comment
comment|/* TRUE if operand is a memory operand*/
end_comment

begin_comment
comment|/* Classes of 960 intructions:  *	- each instruction falls into one class.  *	- each target architecture supports one or more classes.  *  * EACH CONSTANT MUST CONTAIN 1 AND ONLY 1 SET BIT!:  see targ_has_iclass().  */
end_comment

begin_define
define|#
directive|define
name|I_BASE
value|0x01
end_define

begin_comment
comment|/* 80960 base instruction set	*/
end_comment

begin_define
define|#
directive|define
name|I_CX
value|0x02
end_define

begin_comment
comment|/* 80960Cx instruction		*/
end_comment

begin_define
define|#
directive|define
name|I_DEC
value|0x04
end_define

begin_comment
comment|/* Decimal instruction		*/
end_comment

begin_define
define|#
directive|define
name|I_FP
value|0x08
end_define

begin_comment
comment|/* Floating point instruction	*/
end_comment

begin_define
define|#
directive|define
name|I_KX
value|0x10
end_define

begin_comment
comment|/* 80960Kx instruction		*/
end_comment

begin_define
define|#
directive|define
name|I_MIL
value|0x20
end_define

begin_comment
comment|/* Military instruction		*/
end_comment

begin_comment
comment|/* MEANING OF 'n_other' in the symbol record.  *  * If non-zero, the 'n_other' fields indicates either a leaf procedure or  * a system procedure, as follows:  *  *	1<= n_other<= 32 :  *		The symbol is the entry point to a system procedure.  *		'n_value' is the address of the entry, as for any other  *		procedure.  The system procedure number (which can be used in  *		a 'calls' instruction) is (n_other-1).  These entries come from  *		'.sysproc' directives.  *  *	n_other == N_CALLNAME  *		the symbol is the 'call' entry point to a leaf procedure.  *		The *next* symbol in the symbol table must be the corresponding  *		'bal' entry point to the procedure (see following).  These  *		entries come from '.leafproc' directives in which two different  *		symbols are specified (the first one is represented here).  *  *  *	n_other == N_BALNAME  *		the symbol is the 'bal' entry point to a leaf procedure.  *		These entries result from '.leafproc' directives in which only  *		one symbol is specified, or in which the same symbol is  *		specified twice.  *  * Note that an N_CALLNAME entry *must* have a corresponding N_BALNAME entry,  * but not every N_BALNAME entry must have an N_CALLNAME entry.  */
end_comment

begin_define
define|#
directive|define
name|N_CALLNAME
value|(-1)
end_define

begin_define
define|#
directive|define
name|N_BALNAME
value|(-2)
end_define

begin_comment
comment|/* i960 uses a custom relocation record. */
end_comment

begin_comment
comment|/* let obj-aout.h know */
end_comment

begin_define
define|#
directive|define
name|CUSTOM_RELOC_FORMAT
value|1
end_define

begin_comment
comment|/* let a.out.gnu.h know */
end_comment

begin_define
define|#
directive|define
name|N_RELOCATION_INFO_DECLARED
value|1
end_define

begin_struct
struct|struct
name|relocation_info
block|{
name|int
name|r_address
decl_stmt|;
comment|/* File address of item to be relocated	*/
name|unsigned
name|r_index
range|:
literal|24
decl_stmt|,
comment|/* Index of symbol on which relocation is based*/
name|r_pcrel
range|:
literal|1
decl_stmt|,
comment|/* 1 => relocate PC-relative; else absolute 		 *	On i960, pc-relative implies 24-bit 		 *	address, absolute implies 32-bit. 		 */
name|r_length
range|:
literal|2
decl_stmt|,
comment|/* Number of bytes to relocate: 		 *	0 => 1 byte 		 *	1 => 2 bytes 		 *	2 => 4 bytes -- only value used for i960 		 */
name|r_extern
range|:
literal|1
decl_stmt|,
name|r_bsr
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_disp
range|:
literal|1
decl_stmt|,
comment|/* Something for the GNU NS32K assembler */
name|r_callj
range|:
literal|1
decl_stmt|,
comment|/* 1 if relocation target is an i960 'callj' */
name|nuthin
range|:
literal|1
decl_stmt|;
comment|/* Unused				*/
block|}
struct|;
end_struct

begin_comment
comment|/* hacks for tracking callj's */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJ_AOUT
argument_list|)
operator||
name|defined
argument_list|(
name|OBJ_BOUT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TC_S_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|((1<= S_GET_OTHER(s))&& (S_GET_OTHER(s)<= 32))
end_define

begin_define
define|#
directive|define
name|TC_S_IS_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(S_GET_OTHER(s) == N_BALNAME)
end_define

begin_define
define|#
directive|define
name|TC_S_IS_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(S_GET_OTHER(s) == N_CALLNAME)
end_define

begin_define
define|#
directive|define
name|TC_S_IS_BADPROC
parameter_list|(
name|s
parameter_list|)
value|((S_GET_OTHER(s) != 0)&& !TC_S_IS_CALLNAME(s)&& !TC_S_IS_BALNAME(s)&& !TC_S_IS_SYSPROC(s))
end_define

begin_define
define|#
directive|define
name|TC_S_SET_SYSPROC
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|(S_SET_OTHER((s), (p)+1))
end_define

begin_define
define|#
directive|define
name|TC_S_GET_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(S_GET_OTHER(s)-1)
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(S_SET_OTHER((s), N_BALNAME))
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(S_SET_OTHER((s), N_CALLNAME))
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|{;}
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|OBJ_COFF
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TC_S_IS_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(S_GET_STORAGE_CLASS(s) == C_SCALL)
end_define

begin_define
define|#
directive|define
name|TC_S_IS_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET_BALNAME(s))
end_define

begin_define
define|#
directive|define
name|TC_S_IS_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_GET_CALLNAME(s))
end_define

begin_define
define|#
directive|define
name|TC_S_IS_BADPROC
parameter_list|(
name|s
parameter_list|)
value|(TC_S_IS_SYSPROC(s)&& TC_S_GET_SYSPROC(s)< 0&& 31< TC_S_GET_SYSPROC(s))
end_define

begin_define
define|#
directive|define
name|TC_S_SET_SYSPROC
parameter_list|(
name|s
parameter_list|,
name|p
parameter_list|)
value|((s)->sy_symbol.ost_auxent[1].x_sc.x_stindx = (p))
end_define

begin_define
define|#
directive|define
name|TC_S_GET_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|((s)->sy_symbol.ost_auxent[1].x_sc.x_stindx)
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_BALNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_SET_BALNAME(s))
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_CALLNAME
parameter_list|(
name|s
parameter_list|)
value|(SF_SET_CALLNAME(s))
end_define

begin_define
define|#
directive|define
name|TC_S_FORCE_TO_SYSPROC
parameter_list|(
name|s
parameter_list|)
value|(S_SET_STORAGE_CLASS((s), C_SCALL))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* switch on OBJ */
end_comment

begin_function_decl
name|you
name|lose
endif|#
directive|endif
comment|/* witch on OBJ */
if|#
directive|if
name|__STDC__
operator|==
literal|1
name|void
name|brtab_emit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reloc_callj
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* this is really reloc_callj(fixS *fixP) but I don't want to change header inclusion order. */
end_comment

begin_function_decl
name|void
name|tc_set_bal_of_call
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* this is really tc_set_bal_of_call(symbolS *callP, symbolS *balP) */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|brtab_emit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|reloc_callj
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tc_set_bal_of_call
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|char
modifier|*
name|_tc_get_bal_of_call
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* this is really symbolS *tc_get_bal_of_call(symbolS *callP). */
end_comment

begin_define
define|#
directive|define
name|tc_get_bal_of_call
parameter_list|(
name|c
parameter_list|)
value|((symbolS *) _tc_get_bal_of_call(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of tc-i960.h */
end_comment

end_unit

