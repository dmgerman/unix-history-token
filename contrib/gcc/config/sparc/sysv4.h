begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Sparc running System V.4    Copyright (C) 1991, 1992, 1995, 1996, 1997, 1998, 2000    Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (sparc ELF)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ??? Put back the SIZE_TYPE/PTRDIFF_TYPE definitions set by sparc.h.    Why, exactly, is svr4.h messing with this?  Seems like the chip     would know best.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|(TARGET_ARCH64 ? "long unsigned int" : "unsigned int")
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|(TARGET_ARCH64 ? "long int" : "int")
end_define

begin_comment
comment|/* Undefined some symbols which are defined in "svr4.h" but which are    appropriate only for typical svr4 systems, but not for the specific    case of svr4 running on a Sparc.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

begin_undef
undef|#
directive|undef
name|PUSHSECTION_FORMAT
end_undef

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SKIP_ASM_OP
end_undef

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_comment
comment|/* Has no equivalent.  See ASM_OUTPUT_DEF below.  */
end_comment

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the Sparc running svr4.  __svr4__ is our extension.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dsparc -Dunix -D__svr4__ -Asystem=unix -Asystem=svr4"
end_define

begin_comment
comment|/* The native assembler can't compute differences between symbols in different    sections when generating pic code, so we must put jump tables in the    text section.  */
end_comment

begin_comment
comment|/* But we now defer the tables to the end of the function, so we make    this 0 to not confuse the branch shortening code.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|0
end_define

begin_comment
comment|/* Pass -K to the assembler when PIC.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*} \    %{fpic:-K PIC} %{fPIC:-K PIC} %(asm_cpu)"
end_define

begin_comment
comment|/* Must use data section for relocatable constants when pic.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|{						\   if (flag_pic&& symbolic_operand ((RTX), (MODE))) \     data_section ();				\   else						\     const_section ();				\ }
end_define

begin_comment
comment|/* Define the names of various pseudo-op used by the Sparc/svr4 assembler.    Note that many of these are different from the typical pseudo-ops used    by most svr4 assemblers.  That is probably due to a (misguided?) attempt    to keep the Sparc/svr4 assembler somewhat compatible with the Sparc/SunOS    assembler.  */
end_comment

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|"\t.asciz\t"
end_define

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|"\t.common\t"
end_define

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|"\t.skip\t"
end_define

begin_define
define|#
directive|define
name|PUSHSECTION_ASM_OP
value|"\t.pushsection\t"
end_define

begin_define
define|#
directive|define
name|POPSECTION_ASM_OP
value|"\t.popsection"
end_define

begin_comment
comment|/* This is the format used to print the second operand of a .type pseudo-op    for the Sparc/svr4 assembler.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"#%s"
end_define

begin_comment
comment|/* This is the format used to print a .pushsection pseudo-op (and its operand)    for the Sparc/svr4 assembler.  */
end_comment

begin_define
define|#
directive|define
name|PUSHSECTION_FORMAT
value|"%s\"%s\"\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|do { ASM_OUTPUT_ALIGN ((FILE), Pmode == SImode ? 2 : 3);		\      ASM_OUTPUT_INTERNAL_LABEL ((FILE), PREFIX, NUM);			\    } while (0)
end_define

begin_comment
comment|/* This is how to equate one symbol to another symbol.  The syntax used is    `SYM1=SYM2'.  Note that this is different from the way equates are done    with most svr4 assemblers, where the syntax is `.set SYM1,SYM2'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {	fprintf ((FILE), "\t");						\ 	assemble_name (FILE, LABEL1);					\ 	fprintf (FILE, " = ");						\ 	assemble_name (FILE, LABEL2);					\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* Define how the Sparc registers should be numbered for Dwarf output.    The numbering provided here should be compatible with the native    svr4 SDB debugger in the Sparc/svr4 reference port.  The numbering    is as follows:     Assembly name	gcc internal regno	Dwarf regno    ----------------------------------------------------------    g0-g7		0-7			0-7    o0-o7		8-15			8-15    l0-l7		16-23			16-23    i0-i7		24-31			24-31    f0-f31		32-63			40-71 */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO)< 32 ? (REGNO) : (REGNO) + 8)
end_define

begin_comment
comment|/* A set of symbol definitions for assembly pseudo-ops which will    get us switched to various sections of interest.  These are used    in all places where we simply want to switch to a section, and    *not* to push the previous section name onto the assembler's    section names stack (as we do often in dwarfout.c).  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.section\t\".text\""
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.section\t\".data\""
end_define

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t\".bss\""
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|"\t.section\t\".rodata\""
end_define

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t\".init\""
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section\t\".fini\""
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.      Note that we want to give these sections the SHF_WRITE attribute    because these sections will actually contain data (i.e. tables of    addresses of functions in the current root executable or shared library    file) and, in the case of a shared library, the relocatable addresses    will have to be properly resolved/relocated (and then written into) by    the dynamic linker when it actually attaches the given shared library    to the executing process.  (Note that on SVR4, you may wish to use the    `-z text' option to the ELF linker, when building a shared library, as    an additional check that you are doing everything right.  But if you do    use the `-z text' option when building a shared library, you will get    errors unless the .ctors and .dtors sections are marked as writable    via the SHF_WRITE attribute.)  */
end_comment

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section\t\".ctors\",#alloc,#write"
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section\t\".dtors\",#alloc,#write"
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|sparc_elf_asm_named_section
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    FILE the assembler definition of uninitialized global DECL named    NAME whose size is SIZE bytes and alignment is ALIGN bytes.    Try to use asm_output_aligned_bss to implement this macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* Override the name of the mcount profiling function.  */
end_comment

begin_undef
undef|#
directive|undef
name|MCOUNT_FUNCTION
end_undef

begin_define
define|#
directive|define
name|MCOUNT_FUNCTION
value|"*_mcount"
end_define

end_unit

