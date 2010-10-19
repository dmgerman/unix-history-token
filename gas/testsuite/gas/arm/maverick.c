begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2000, 2003 Free Software Foundation    Contributed by Alexandre Oliva<aoliva@cygnus.com>     This file is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Generator of tests for Maverick.     See the following file for usage and documentation.  */
end_comment

begin_include
include|#
directive|include
file|"../all/test-gen.c"
end_include

begin_comment
comment|/* These are the ARM registers.  Some of them have canonical names    other than r##, so we'll use both in the asm input, but only the    canonical names in the expected disassembler output.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|arm_regs
index|[]
init|=
block|{
comment|/* Canonical names.  */
literal|"r0"
block|,
literal|"r1"
block|,
literal|"r2"
block|,
literal|"r3"
block|,
literal|"r4"
block|,
literal|"r5"
block|,
literal|"r6"
block|,
literal|"r7"
block|,
literal|"r8"
block|,
literal|"r9"
block|,
literal|"sl"
block|,
literal|"fp"
block|,
literal|"ip"
block|,
literal|"sp"
block|,
literal|"lr"
block|,
literal|"pc"
block|,
comment|/* Alternate names, i.e., those that can be used in the assembler,      * but that will never be emitted by the disassembler.  */
literal|"r0"
block|,
literal|"r1"
block|,
literal|"r2"
block|,
literal|"r3"
block|,
literal|"r4"
block|,
literal|"r5"
block|,
literal|"r6"
block|,
literal|"r7"
block|,
literal|"r8"
block|,
literal|"r9"
block|,
literal|"r10"
block|,
literal|"r11"
block|,
literal|"r12"
block|,
literal|"r13"
block|,
literal|"r14"
block|,
literal|"r15"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The various types of registers: ARM's registers, Maverick's    f/d/fx/dx registers, Maverick's accumulators and Maverick's    status register.  */
end_comment

begin_define
define|#
directive|define
name|armreg
parameter_list|(
name|shift
parameter_list|)
define|\
value|reg_r (arm_regs, shift, 0xf, mk_get_bits (5u))
end_define

begin_define
define|#
directive|define
name|mvreg
parameter_list|(
name|prefix
parameter_list|,
name|shift
parameter_list|)
define|\
value|reg_p ("mv" prefix, shift, mk_get_bits (4u))
end_define

begin_define
define|#
directive|define
name|acreg
parameter_list|(
name|shift
parameter_list|)
define|\
value|reg_p ("mvax", shift, mk_get_bits (2u))
end_define

begin_define
define|#
directive|define
name|dspsc
define|\
value|literal ("dspsc"), tick_random
end_define

begin_comment
comment|/* This outputs the condition flag that may follow each ARM insn.    Since the condition 15 is invalid, we use it to check that the    assembler recognizes the absence of a condition as `al'.  However,    the disassembler won't ever output `al', so, if we emit it in the    assembler, expect the condition to be omitted in the disassembler    output.  */
end_comment

begin_function
name|int
name|arm_cond
parameter_list|(
name|func_arg
modifier|*
name|arg
parameter_list|,
name|insn_data
modifier|*
name|data
parameter_list|)
define|#
directive|define
name|arm_cond
value|{ arm_cond }
block|{
specifier|static
specifier|const
name|char
name|conds
index|[
literal|16
index|]
index|[
literal|3
index|]
init|=
block|{
literal|"eq"
block|,
literal|"ne"
block|,
literal|"cs"
block|,
literal|"cc"
block|,
literal|"mi"
block|,
literal|"pl"
block|,
literal|"vs"
block|,
literal|"vc"
block|,
literal|"hi"
block|,
literal|"ls"
block|,
literal|"ge"
block|,
literal|"lt"
block|,
literal|"gt"
block|,
literal|"le"
block|,
literal|"al"
block|,
literal|""
block|}
decl_stmt|;
name|unsigned
name|val
init|=
name|get_bits
argument_list|(
literal|4u
argument_list|)
decl_stmt|;
name|data
operator|->
name|as_in
operator|=
name|data
operator|->
name|dis_out
operator|=
name|strdup
argument_list|(
name|conds
index|[
name|val
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|==
literal|14
condition|)
name|data
operator|->
name|dis_out
operator|=
name|strdup
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|data
operator|->
name|bits
operator|=
operator|(
name|val
operator|==
literal|15
condition|?
literal|14
else|:
name|val
operator|)
operator|<<
literal|28
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* The sign of an offset is actually used to determined whether the    absolute value of the offset should be added or subtracted, so we    must adjust negative values so that they do not overflow: -1024 is    not valid, but -0 is distinct from +0.  */
end_comment

begin_function
name|int
name|off8s
parameter_list|(
name|func_arg
modifier|*
name|arg
parameter_list|,
name|insn_data
modifier|*
name|data
parameter_list|)
define|#
directive|define
name|off8s
value|{ off8s }
block|{
name|int
name|val
decl_stmt|;
name|char
name|value
index|[
literal|9
index|]
decl_stmt|;
comment|/* Zero values are problematical.      The assembler performs translations on the addressing modes      for these values, meaning that we cannot just recreate the      disassembler string in the LDST macro without knowing what      value had been generated in off8s.  */
do|do
block|{
name|val
operator|=
name|get_bits
argument_list|(
literal|9s
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|val
operator|==
operator|-
literal|1
operator|||
name|val
operator|==
literal|0
condition|)
do|;
name|val
operator|<<=
literal|2
expr_stmt|;
if|if
condition|(
name|val
operator|<
literal|0
condition|)
block|{
name|val
operator|=
operator|-
literal|4
operator|-
name|val
expr_stmt|;
name|sprintf
argument_list|(
name|value
argument_list|,
literal|", #-%i"
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|data
operator|->
name|dis_out
operator|=
name|strdup
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|value
argument_list|,
literal|", #-%i"
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|data
operator|->
name|as_in
operator|=
name|strdup
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|data
operator|->
name|bits
operator|=
name|val
operator|>>
literal|2
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|value
argument_list|,
literal|", #%i"
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|data
operator|->
name|as_in
operator|=
name|data
operator|->
name|dis_out
operator|=
name|strdup
argument_list|(
name|value
argument_list|)
expr_stmt|;
name|data
operator|->
name|bits
operator|=
operator|(
name|val
operator|>>
literal|2
operator|)
operator||
operator|(
literal|1
operator|<<
literal|23
operator|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* This function generates a 7-bit signed constant, emitted as    follows: the 4 least-significant bits are stored in the 4    least-significant bits of the word; the 3 most-significant bits are    stored in bits 7:5, i.e., bit 4 is skipped.  */
end_comment

begin_function
name|int
name|imm7
parameter_list|(
name|func_arg
modifier|*
name|arg
parameter_list|,
name|insn_data
modifier|*
name|data
parameter_list|)
define|#
directive|define
name|imm7
value|{ imm7 }
block|{
name|int
name|val
init|=
name|get_bits
argument_list|(
literal|7s
argument_list|)
decl_stmt|;
name|char
name|value
index|[
literal|6
index|]
decl_stmt|;
name|data
operator|->
name|bits
operator|=
operator|(
name|val
operator|&
literal|0x0f
operator|)
operator||
operator|(
literal|2
operator|*
operator|(
name|val
operator|&
literal|0x70
operator|)
operator|)
expr_stmt|;
name|sprintf
argument_list|(
name|value
argument_list|,
literal|"#%i"
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|data
operator|->
name|as_in
operator|=
name|data
operator|->
name|dis_out
operator|=
name|strdup
argument_list|(
name|value
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Convenience wrapper to define_insn, that prefixes every insn with    `cf' (so, if you specify command-line arguments, remember that `cf'    must *not* be part of the string), and post-fixes a condition code.    insname and insnvar specify the main insn name and a variant;    they're just concatenated, and insnvar is often empty.  word is the    bit pattern that defines the insn, properly shifted, and funcs is a    sequence of funcs that define the operands and the syntax of the    insn.  */
end_comment

begin_define
define|#
directive|define
name|mv_insn
parameter_list|(
name|insname
parameter_list|,
name|insnvar
parameter_list|,
name|word
parameter_list|,
name|funcs
modifier|...
parameter_list|)
define|\
value|define_insn (insname ## insnvar, \ 	      literal ("cf"), \ 	      insn_bits (insname, word), \ 	      arm_cond, \ 	      tab, \ 	      ## funcs)
end_define

begin_comment
comment|/* Define a single LDC/STC variant.  op is the main insn opcode; ld    stands for load (it should be 0 on stores), dword selects 64-bit    operations, pre should be enabled for pre-increment, and wb, for    write-back.  sep1, sep2 and sep3 are syntactical elements ([]!)    that the assembler will use to enable pre and wb.  It would    probably have been cleaner to couple the syntactical elements with    the pre/wb bits directly, but it would have required the definition    of more functions.  */
end_comment

begin_define
define|#
directive|define
name|LDST
parameter_list|(
name|insname
parameter_list|,
name|insnvar
parameter_list|,
name|op
parameter_list|,
name|ld
parameter_list|,
name|dword
parameter_list|,
name|regname
parameter_list|,
name|pre
parameter_list|,
name|wb
parameter_list|,
name|sep1
parameter_list|,
name|sep2
parameter_list|,
name|sep3
parameter_list|)
define|\
value|mv_insn (insname, insnvar, \ 	   (12<< 24) | (op<< 8) | (ld<< 20) | (pre<< 24) | (dword<< 22) | (wb<< 21), \ 	    mvreg (regname, 12), comma, \ 	    lsqbkt, armreg (16), sep1, off8s, sep2, sep3, \ 	    tick_random)
end_define

begin_comment
comment|/* Define all variants of an LDR or STR instruction, namely,    pre-indexed without write-back, pre-indexed with write-back and    post-indexed.  */
end_comment

begin_define
define|#
directive|define
name|LDSTall
parameter_list|(
name|insname
parameter_list|,
name|op
parameter_list|,
name|ld
parameter_list|,
name|dword
parameter_list|,
name|regname
parameter_list|)
define|\
value|LDST (insname, _p, op, ld, dword, regname, 1, 0, nothing, rsqbkt, nothing); \   LDST (insname, _pw, op, ld, dword, regname, 1, 1, nothing, rsqbkt, literal ("!")); \   LDST (insname, ,op, ld, dword, regname, 0, 1, rsqbkt, nothing, nothing)
end_define

begin_comment
comment|/* Produce the insn identifiers of all LDST variants of a given insn.    To be used in the initialization of an insn group array.  */
end_comment

begin_define
define|#
directive|define
name|insns_LDSTall
parameter_list|(
name|insname
parameter_list|)
define|\
value|insn (insname ## _p), insn (insname ## _pw), insn (insname)
end_define

begin_comment
comment|/* Define a CDP variant that uses two registers, at offsets 12 and 16.    The two opcodes and the co-processor number identify the CDP    insn.  */
end_comment

begin_define
define|#
directive|define
name|CDP2
parameter_list|(
name|insname
parameter_list|,
name|var
parameter_list|,
name|cpnum
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|,
name|reg1name
parameter_list|,
name|reg2name
parameter_list|)
define|\
value|mv_insn (insname##var, , \ 	   (14<< 24) | ((opcode1)<< 20) | ((cpnum)<< 8) | ((opcode2)<< 5), \ 	   mvreg (reg1name, 12), comma, mvreg (reg2name, 16))
end_define

begin_comment
comment|/* Define a 32-bit integer CDP instruction with two operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP2fx
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP2 (insname, 32, 5, opcode1, opcode2, "fx", "fx")
end_define

begin_comment
comment|/* Define a 64-bit integer CDP instruction with two operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP2dx
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP2 (insname, 64, 5, opcode1, opcode2, "dx", "dx")
end_define

begin_comment
comment|/* Define a float CDP instruction with two operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP2f
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP2 (insname, s, 4, opcode1, opcode2, "f", "f")
end_define

begin_comment
comment|/* Define a double CDP instruction with two operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP2d
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP2 (insname, d, 4, opcode1, opcode2, "d", "d")
end_define

begin_comment
comment|/* Define a CDP instruction with two register operands and one 7-bit    signed immediate generated with imm7.  */
end_comment

begin_define
define|#
directive|define
name|CDP2_imm7
parameter_list|(
name|insname
parameter_list|,
name|cpnum
parameter_list|,
name|opcode1
parameter_list|,
name|reg1name
parameter_list|,
name|reg2name
parameter_list|)
define|\
value|mv_insn (insname, , (14<< 24) | ((opcode1)<< 20) | ((cpnum)<< 8), \ 	   mvreg (reg1name, 12), comma, mvreg (reg2name, 16), comma, imm7, \ 	   tick_random)
end_define

begin_comment
comment|/* Produce the insn identifiers of CDP floating-point or integer insn    pairs (i.e., it appends the suffixes for 32-bit and 64-bit    insns.  */
end_comment

begin_define
define|#
directive|define
name|CDPfp_insns
parameter_list|(
name|insname
parameter_list|)
define|\
value|insn (insname ## s), insn (insname ## d)
end_define

begin_define
define|#
directive|define
name|CDPx_insns
parameter_list|(
name|insname
parameter_list|)
define|\
value|insn (insname ## 32), insn (insname ## 64)
end_define

begin_comment
comment|/* Define a CDP instruction with 3 operands, at offsets 12, 16, 0.  */
end_comment

begin_define
define|#
directive|define
name|CDP3
parameter_list|(
name|insname
parameter_list|,
name|var
parameter_list|,
name|cpnum
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|,
name|reg1name
parameter_list|,
name|reg2name
parameter_list|,
name|reg3name
parameter_list|)
define|\
value|mv_insn (insname##var, , \ 	   (14<< 24) | ((opcode1)<< 20) | ((cpnum)<< 8) | ((opcode2)<< 5), \ 	   mvreg (reg1name, 12), comma, mvreg (reg2name, 16), comma, \ 	   mvreg (reg3name, 0), tick_random)
end_define

begin_comment
comment|/* Define a 32-bit integer CDP instruction with three operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP3fx
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP3 (insname, 32, 5, opcode1, opcode2, "fx", "fx", "fx")
end_define

begin_comment
comment|/* Define a 64-bit integer CDP instruction with three operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP3dx
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP3 (insname, 64, 5, opcode1, opcode2, "dx", "dx", "dx")
end_define

begin_comment
comment|/* Define a float CDP instruction with three operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP3f
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP3 (insname, s, 4, opcode1, opcode2, "f", "f", "f")
end_define

begin_comment
comment|/* Define a double CDP instruction with three operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP3d
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|CDP3 (insname, d, 4, opcode1, opcode2, "d", "d", "d")
end_define

begin_comment
comment|/* Define a CDP instruction with four operands, at offsets 5, 12, 16  * and 0.  Used only for ACC instructions.  */
end_comment

begin_define
define|#
directive|define
name|CDP4
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|reg2spec
parameter_list|,
name|reg3name
parameter_list|,
name|reg4name
parameter_list|)
define|\
value|mv_insn (insname, , (14<< 24) | ((opcode1)<< 20) | (6<< 8), \ 	   acreg (5), comma, reg2spec, comma, \ 	   mvreg (reg3name, 16), comma, mvreg (reg4name, 0))
end_define

begin_comment
comment|/* Define a CDP4 instruction with one accumulator operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP41A
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|)
define|\
value|CDP4 (insname, opcode1, mvreg ("fx", 12), "fx", "fx")
end_define

begin_comment
comment|/* Define a CDP4 instruction with two accumulator operands.  */
end_comment

begin_define
define|#
directive|define
name|CDP42A
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|)
define|\
value|CDP4 (insname, opcode1, acreg (12), "fx", "fx")
end_define

begin_comment
comment|/* Define a MCR or MRC instruction with two register operands.  */
end_comment

begin_define
define|#
directive|define
name|MCRC2
parameter_list|(
name|insname
parameter_list|,
name|cpnum
parameter_list|,
name|opcode1
parameter_list|,
name|dir
parameter_list|,
name|opcode2
parameter_list|,
name|reg1spec
parameter_list|,
name|reg2spec
parameter_list|)
define|\
value|mv_insn (insname, , \ 	   ((14<< 24) | ((opcode1)<< 21) | ((dir)<< 20)| \ 	    ((cpnum)<< 8) | ((opcode2)<< 5) | (1<< 4)), \ 	   reg1spec, comma, reg2spec)
end_define

begin_comment
comment|/* Define a move from a DSP register to an ARM register.  */
end_comment

begin_define
define|#
directive|define
name|MVDSPARM
parameter_list|(
name|insname
parameter_list|,
name|cpnum
parameter_list|,
name|opcode2
parameter_list|,
name|regDSPname
parameter_list|)
define|\
value|MCRC2 (mv ## insname, cpnum, 0, 0, opcode2, \ 	 mvreg (regDSPname, 16), armreg (12))
end_define

begin_comment
comment|/* Define a move from an ARM register to a DSP register.  */
end_comment

begin_define
define|#
directive|define
name|MVARMDSP
parameter_list|(
name|insname
parameter_list|,
name|cpnum
parameter_list|,
name|opcode2
parameter_list|,
name|regDSPname
parameter_list|)
define|\
value|MCRC2 (mv ## insname, cpnum, 0, 1, opcode2, \ 	 armreg (12), mvreg (regDSPname, 16))
end_define

begin_comment
comment|/* Move between coprocessor registers. A two operand CDP insn.   */
end_comment

begin_define
define|#
directive|define
name|MCC2
parameter_list|(
name|insname
parameter_list|,
name|opcode1
parameter_list|,
name|opcode2
parameter_list|,
name|reg1spec
parameter_list|,
name|reg2spec
parameter_list|)
define|\
value|mv_insn (insname, , \ 	   ((14<< 24) | ((opcode1)<< 20) | \ 	    (4<< 8) | ((opcode2)<< 5)), \ 	   reg1spec, comma, reg2spec)
end_define

begin_comment
comment|/* Define a move from a DSP register to a DSP accumulator.  */
end_comment

begin_define
define|#
directive|define
name|MVDSPACC
parameter_list|(
name|insname
parameter_list|,
name|opcode2
parameter_list|,
name|regDSPname
parameter_list|)
define|\
value|MCC2 (mv ## insname, 2, opcode2, acreg (12), mvreg (regDSPname, 16))
end_define

begin_comment
comment|/* Define a move from a DSP accumulator to a DSP register.  */
end_comment

begin_define
define|#
directive|define
name|MVACCDSP
parameter_list|(
name|insname
parameter_list|,
name|opcode2
parameter_list|,
name|regDSPname
parameter_list|)
define|\
value|MCC2 (mv ## insname, 1, opcode2, mvreg (regDSPname, 12), acreg (16))
end_define

begin_comment
comment|/* Define move insns between a float DSP register and an ARM    register.  */
end_comment

begin_define
define|#
directive|define
name|MVf
parameter_list|(
name|nameAD
parameter_list|,
name|nameDA
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPARM (nameAD, 4, opcode2, "f"); \   MVARMDSP (nameDA, 4, opcode2, "f")
end_define

begin_comment
comment|/* Define move insns between a double DSP register and an ARM    register.  */
end_comment

begin_define
define|#
directive|define
name|MVd
parameter_list|(
name|nameAD
parameter_list|,
name|nameDA
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPARM (nameAD, 4, opcode2, "d"); \   MVARMDSP (nameDA, 4, opcode2, "d")
end_define

begin_comment
comment|/* Define move insns between a 32-bit integer DSP register and an ARM    register.  */
end_comment

begin_define
define|#
directive|define
name|MVfx
parameter_list|(
name|nameAD
parameter_list|,
name|nameDA
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPARM (nameAD, 5, opcode2, "fx"); \   MVARMDSP (nameDA, 5, opcode2, "fx")
end_define

begin_comment
comment|/* Define move insns between a 64-bit integer DSP register and an ARM    register.  */
end_comment

begin_define
define|#
directive|define
name|MVdx
parameter_list|(
name|nameAD
parameter_list|,
name|nameDA
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPARM (nameAD, 5, opcode2, "dx"); \   MVARMDSP (nameDA, 5, opcode2, "dx")
end_define

begin_comment
comment|/* Define move insns between a 32-bit DSP register and a DSP    accumulator.  */
end_comment

begin_define
define|#
directive|define
name|MVfxa
parameter_list|(
name|nameFA
parameter_list|,
name|nameAF
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPACC (nameFA, opcode2, "fx"); \   MVACCDSP (nameAF, opcode2, "fx")
end_define

begin_comment
comment|/* Define move insns between a 64-bit DSP register and a DSP    accumulator.  */
end_comment

begin_define
define|#
directive|define
name|MVdxa
parameter_list|(
name|nameDA
parameter_list|,
name|nameAD
parameter_list|,
name|opcode2
parameter_list|)
define|\
value|MVDSPACC (nameDA, opcode2, "dx"); \   MVACCDSP (nameAD, opcode2, "dx")
end_define

begin_comment
comment|/* Produce the insn identifiers for a pair of mv insns.  */
end_comment

begin_define
define|#
directive|define
name|insns_MV
parameter_list|(
name|name1
parameter_list|,
name|name2
parameter_list|)
define|\
value|insn (mv ## name1), insn (mv ## name2)
end_define

begin_comment
comment|/* Define a MCR or MRC instruction with three register operands.  */
end_comment

begin_define
define|#
directive|define
name|MCRC3
parameter_list|(
name|insname
parameter_list|,
name|cpnum
parameter_list|,
name|opcode1
parameter_list|,
name|dir
parameter_list|,
name|opcode2
parameter_list|,
name|reg1spec
parameter_list|,
name|reg2spec
parameter_list|,
name|reg3spec
parameter_list|)
define|\
value|mv_insn (insname, , \ 	   ((14<< 24) | ((opcode1)<< 21) | ((dir)<< 20)| \ 	    ((cpnum)<< 8) | ((opcode2)<< 5) | (1<< 4)), \ 	   reg1spec, comma, reg2spec, comma, reg3spec, \ 	   tick_random)
end_define

begin_comment
comment|/* Define all load_store insns.  */
end_comment

begin_expr_stmt
name|LDSTall
argument_list|(
name|ldrs
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|ldrd
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|ldr32
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|"fx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|ldr64
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|"dx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|strs
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|strd
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|str32
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|"fx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|LDSTall
argument_list|(
name|str64
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|"dx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the load_store insn group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|load_store_insns
index|[]
init|=
block|{
name|insns_LDSTall
argument_list|(
name|ldrs
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|ldrd
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|ldr32
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|ldr64
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|strs
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|strd
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|str32
argument_list|)
block|,
name|insns_LDSTall
argument_list|(
name|str64
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all move insns.  */
end_comment

begin_expr_stmt
name|MVf
argument_list|(
name|sr
argument_list|,
name|rs
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVd
argument_list|(
name|dlr
argument_list|,
name|rdl
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVd
argument_list|(
name|dhr
argument_list|,
name|rdh
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVdx
argument_list|(
literal|64lr
argument_list|,
name|r64l
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVdx
argument_list|(
literal|64hr
argument_list|,
name|r64h
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVfxa
argument_list|(
name|al32
argument_list|,
literal|32al
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVfxa
argument_list|(
name|am32
argument_list|,
literal|32am
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVfxa
argument_list|(
name|ah32
argument_list|,
literal|32ah
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVfxa
argument_list|(
name|a32
argument_list|,
literal|32a
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MVdxa
argument_list|(
name|a64
argument_list|,
literal|64a
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCC2
argument_list|(
name|mvsc32
argument_list|,
literal|2
argument_list|,
literal|7
argument_list|,
name|dspsc
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|12
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCC2
argument_list|(
name|mv32sc
argument_list|,
literal|1
argument_list|,
literal|7
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|12
argument_list|)
argument_list|,
name|dspsc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cpys
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|"f"
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cpyd
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|"d"
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the move insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|move_insns
index|[]
init|=
block|{
name|insns_MV
argument_list|(
name|sr
argument_list|,
name|rs
argument_list|)
block|,
name|insns_MV
argument_list|(
name|dlr
argument_list|,
name|rdl
argument_list|)
block|,
name|insns_MV
argument_list|(
name|dhr
argument_list|,
name|rdh
argument_list|)
block|,
name|insns_MV
argument_list|(
literal|64lr
argument_list|,
name|r64l
argument_list|)
block|,
name|insns_MV
argument_list|(
literal|64hr
argument_list|,
name|r64h
argument_list|)
block|,
name|insns_MV
argument_list|(
name|al32
argument_list|,
literal|32al
argument_list|)
block|,
name|insns_MV
argument_list|(
name|am32
argument_list|,
literal|32am
argument_list|)
block|,
name|insns_MV
argument_list|(
name|ah32
argument_list|,
literal|32ah
argument_list|)
block|,
name|insns_MV
argument_list|(
name|a32
argument_list|,
literal|32a
argument_list|)
block|,
name|insns_MV
argument_list|(
name|a64
argument_list|,
literal|64a
argument_list|)
block|,
name|insn
argument_list|(
name|mvsc32
argument_list|)
block|,
name|insn
argument_list|(
name|mv32sc
argument_list|)
block|,
name|insn
argument_list|(
name|cpys
argument_list|)
block|,
name|insn
argument_list|(
name|cpyd
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all conversion insns.  */
end_comment

begin_expr_stmt
name|CDP2
argument_list|(
name|cvtsd
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|"d"
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvtds
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|"f"
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvt32s
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|,
literal|"f"
argument_list|,
literal|"fx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvt32d
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|"d"
argument_list|,
literal|"fx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvt64s
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|6
argument_list|,
literal|"f"
argument_list|,
literal|"dx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvt64d
argument_list|, ,
literal|4
argument_list|,
literal|0
argument_list|,
literal|7
argument_list|,
literal|"d"
argument_list|,
literal|"dx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvts32
argument_list|, ,
literal|5
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
literal|"fx"
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|cvtd32
argument_list|, ,
literal|5
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
literal|"fx"
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|truncs32
argument_list|, ,
literal|5
argument_list|,
literal|1
argument_list|,
literal|6
argument_list|,
literal|"fx"
argument_list|,
literal|"f"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2
argument_list|(
name|truncd32
argument_list|, ,
literal|5
argument_list|,
literal|1
argument_list|,
literal|7
argument_list|,
literal|"fx"
argument_list|,
literal|"d"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the conv insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|conv_insns
index|[]
init|=
block|{
name|insn
argument_list|(
name|cvtsd
argument_list|)
block|,
name|insn
argument_list|(
name|cvtds
argument_list|)
block|,
name|insn
argument_list|(
name|cvt32s
argument_list|)
block|,
name|insn
argument_list|(
name|cvt32d
argument_list|)
block|,
name|insn
argument_list|(
name|cvt64s
argument_list|)
block|,
name|insn
argument_list|(
name|cvt64d
argument_list|)
block|,
name|insn
argument_list|(
name|cvts32
argument_list|)
block|,
name|insn
argument_list|(
name|cvtd32
argument_list|)
block|,
name|insn
argument_list|(
name|truncs32
argument_list|)
block|,
name|insn
argument_list|(
name|truncd32
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all shift insns.  */
end_comment

begin_expr_stmt
name|MCRC3
argument_list|(
name|rshl32
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
name|mvreg
argument_list|(
literal|"fx"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"fx"
argument_list|,
literal|0
argument_list|)
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCRC3
argument_list|(
name|rshl64
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|0
argument_list|)
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2_imm7
argument_list|(
name|sh32
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|"fx"
argument_list|,
literal|"fx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2_imm7
argument_list|(
name|sh64
argument_list|,
literal|5
argument_list|,
literal|2
argument_list|,
literal|"dx"
argument_list|,
literal|"dx"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the shift insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|shift_insns
index|[]
init|=
block|{
name|insn
argument_list|(
name|rshl32
argument_list|)
block|,
name|insn
argument_list|(
name|rshl64
argument_list|)
block|,
name|insn
argument_list|(
name|sh32
argument_list|)
block|,
name|insn
argument_list|(
name|sh64
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all comparison insns.  */
end_comment

begin_expr_stmt
name|MCRC3
argument_list|(
name|cmps
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"f"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"f"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCRC3
argument_list|(
name|cmpd
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"d"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"d"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCRC3
argument_list|(
name|cmp32
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"fx"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"fx"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MCRC3
argument_list|(
name|cmp64
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|5
argument_list|,
name|armreg
argument_list|(
literal|12
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|16
argument_list|)
argument_list|,
name|mvreg
argument_list|(
literal|"dx"
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the comp insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|comp_insns
index|[]
init|=
block|{
name|insn
argument_list|(
name|cmps
argument_list|)
block|,
name|insn
argument_list|(
name|cmpd
argument_list|)
block|,
name|insn
argument_list|(
name|cmp32
argument_list|)
block|,
name|insn
argument_list|(
name|cmp64
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all floating-point arithmetic insns.  */
end_comment

begin_expr_stmt
name|CDP2f
argument_list|(
name|abs
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2d
argument_list|(
name|abs
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2f
argument_list|(
name|neg
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2d
argument_list|(
name|neg
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3f
argument_list|(
name|add
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3d
argument_list|(
name|add
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3f
argument_list|(
name|sub
argument_list|,
literal|3
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3d
argument_list|(
name|sub
argument_list|,
literal|3
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3f
argument_list|(
name|mul
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3d
argument_list|(
name|mul
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the fp-arith insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|fp_arith_insns
index|[]
init|=
block|{
name|CDPfp_insns
argument_list|(
name|abs
argument_list|)
block|,
name|CDPfp_insns
argument_list|(
name|neg
argument_list|)
block|,
name|CDPfp_insns
argument_list|(
name|add
argument_list|)
block|,
name|CDPfp_insns
argument_list|(
name|sub
argument_list|)
block|,
name|CDPfp_insns
argument_list|(
name|mul
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all integer arithmetic insns.  */
end_comment

begin_expr_stmt
name|CDP2fx
argument_list|(
name|abs
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2dx
argument_list|(
name|abs
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2fx
argument_list|(
name|neg
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP2dx
argument_list|(
name|neg
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3fx
argument_list|(
name|add
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3dx
argument_list|(
name|add
argument_list|,
literal|3
argument_list|,
literal|5
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3fx
argument_list|(
name|sub
argument_list|,
literal|3
argument_list|,
literal|6
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3dx
argument_list|(
name|sub
argument_list|,
literal|3
argument_list|,
literal|7
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3fx
argument_list|(
name|mul
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3dx
argument_list|(
name|mul
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3fx
argument_list|(
name|mac
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP3fx
argument_list|(
name|msc
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the int-arith insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|int_arith_insns
index|[]
init|=
block|{
name|CDPx_insns
argument_list|(
name|abs
argument_list|)
block|,
name|CDPx_insns
argument_list|(
name|neg
argument_list|)
block|,
name|CDPx_insns
argument_list|(
name|add
argument_list|)
block|,
name|CDPx_insns
argument_list|(
name|sub
argument_list|)
block|,
name|CDPx_insns
argument_list|(
name|mul
argument_list|)
block|,
name|insn
argument_list|(
name|mac32
argument_list|)
block|,
name|insn
argument_list|(
name|msc32
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define all accumulator arithmetic insns.  */
end_comment

begin_expr_stmt
name|CDP41A
argument_list|(
name|madd32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP41A
argument_list|(
name|msub32
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP42A
argument_list|(
name|madda32
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CDP42A
argument_list|(
name|msuba32
argument_list|,
literal|3
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Create the acc-arith insns group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|acc_arith_insns
index|[]
init|=
block|{
name|insn
argument_list|(
name|madd32
argument_list|)
block|,
name|insn
argument_list|(
name|msub32
argument_list|)
block|,
name|insn
argument_list|(
name|madda32
argument_list|)
block|,
name|insn
argument_list|(
name|msuba32
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create the set of all groups.  */
end_comment

begin_decl_stmt
name|group_t
name|groups
index|[]
init|=
block|{
block|{
literal|"load_store"
block|,
name|load_store_insns
block|}
block|,
block|{
literal|"move"
block|,
name|move_insns
block|}
block|,
block|{
literal|"conv"
block|,
name|conv_insns
block|}
block|,
block|{
literal|"shift"
block|,
name|shift_insns
block|}
block|,
block|{
literal|"comp"
block|,
name|comp_insns
block|}
block|,
block|{
literal|"fp_arith"
block|,
name|fp_arith_insns
block|}
block|,
block|{
literal|"int_arith"
block|,
name|int_arith_insns
block|}
block|,
block|{
literal|"acc_arith"
block|,
name|acc_arith_insns
block|}
block|,
block|{
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|FILE
modifier|*
name|as_in
init|=
name|stdout
decl_stmt|,
modifier|*
name|dis_out
init|=
name|stderr
decl_stmt|;
comment|/* Check whether we're filtering insns.  */
if|if
condition|(
name|argc
operator|>
literal|1
condition|)
name|skip_list
operator|=
name|argv
operator|+
literal|1
expr_stmt|;
comment|/* Output assembler header.  */
name|fputs
argument_list|(
literal|"\t.text\n"
literal|"\t.align\n"
argument_list|,
name|as_in
argument_list|)
expr_stmt|;
comment|/* Output comments for the testsuite-driver and the initial      disassembler output.  */
name|fputs
argument_list|(
literal|"#objdump: -dr --prefix-address --show-raw-insn\n"
literal|"#name: Maverick\n"
literal|"#as: -mcpu=ep9312\n"
literal|"\n"
literal|"# Test the instructions of the Cirrus Maverick floating point co-processor\n"
literal|"\n"
literal|".*: +file format.*arm.*\n"
literal|"\n"
literal|"Disassembly of section .text:\n"
argument_list|,
name|dis_out
argument_list|)
expr_stmt|;
comment|/* Now emit all (selected) insns.  */
name|output_groups
argument_list|(
name|groups
argument_list|,
name|as_in
argument_list|,
name|dis_out
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

