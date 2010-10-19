begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2000, 2003 Free Software Foundation    Contributed by Alexandre Oliva<aoliva@cygnus.com>     This file is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.       You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Generator of tests for insns introduced in AM33 2.0.       See the following file for usage and documentation.  */
end_comment

begin_include
include|#
directive|include
file|"../all/test-gen.c"
end_include

begin_comment
comment|/* Define any char*[]s you may need here.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|named_regs
index|[]
init|=
block|{
literal|"a"
block|,
literal|"b"
block|,
literal|"c"
block|,
literal|"d"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define helper macros to generate register accesses here.  */
end_comment

begin_define
define|#
directive|define
name|namedregs
parameter_list|(
name|shift
parameter_list|)
define|\
value|reg_r (named_regs, shift, 0x3, mk_get_bits (2u))
end_define

begin_define
define|#
directive|define
name|numberedregs
parameter_list|(
name|shift
parameter_list|)
define|\
value|reg_p ("f", shift, mk_get_bits (2u))
end_define

begin_comment
comment|/* Define helper functions here.  */
end_comment

begin_function
name|int
name|jmp_cond
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
name|jmp_cond
parameter_list|(
name|shift
parameter_list|)
value|{ jmp_cond, { i1: shift } }
block|{
specifier|static
specifier|const
name|char
name|conds
index|[
literal|4
index|]
index|[
literal|2
index|]
init|=
block|{
literal|"z"
block|,
literal|"n"
block|,
literal|"g"
block|,
literal|"l"
block|}
decl_stmt|;
name|unsigned
name|val
init|=
name|get_bits
argument_list|(
literal|2u
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
name|data
operator|->
name|bits
operator|=
name|val
operator|<<
name|arg
operator|->
name|i1
expr_stmt|;
comment|/* Do not forget to return 0, otherwise the insn will be skipped.  */
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Define convenience wrappers to define_insn.  */
end_comment

begin_define
define|#
directive|define
name|cond_jmp_insn
parameter_list|(
name|insname
parameter_list|,
name|word
parameter_list|,
name|funcs
modifier|...
parameter_list|)
define|\
value|define_insn (insname, \ 	       insn_size_bits (insname, 1, word), \ 	       jmp_cond (4), \ 	       tab, \ 	       ## funcs)
end_define

begin_comment
comment|/* Define insns.  */
end_comment

begin_expr_stmt
name|cond_jmp_insn
argument_list|(
name|j
argument_list|,
literal|0x40
argument_list|,
name|numberedregs
argument_list|(
literal|2
argument_list|)
argument_list|,
name|comma
argument_list|,
name|namedregs
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Define an insn group.  */
end_comment

begin_decl_stmt
name|func
modifier|*
name|jmp_insns
index|[]
init|=
block|{
name|insn
argument_list|(
name|j
argument_list|)
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the set of all groups.  */
end_comment

begin_decl_stmt
name|group_t
name|groups
index|[]
init|=
block|{
block|{
literal|"jumps"
block|,
name|jmp_insns
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
literal|"#name: Foo Digital Processor\n"
literal|"#as: -mfood\n"
literal|"\n"
literal|"# Test the instructions of FooD\n"
literal|"\n"
literal|".*: +file format.*food.*\n"
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

