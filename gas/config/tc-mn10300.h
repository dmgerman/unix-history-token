begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-mn10300.h -- Header file for tc-mn10300.c.    Copyright 1996, 1997, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_MN10300
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_error
error|#
directive|error
error|MN10300 support requires BFD_ASSEMBLER
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_32_PLT_PCREL			\&& (FIX)->fx_r_type != BFD_RELOC_MN10300_GOT32		\&& (FIX)->fx_r_type != BFD_RELOC_32_GOT_PCREL		\&& ((FIX)->fx_addsy == NULL					\        || (! S_IS_EXTERNAL ((FIX)->fx_addsy)			\&& ! S_IS_WEAK ((FIX)->fx_addsy)			\&& S_IS_DEFINED ((FIX)->fx_addsy)			\&& ! S_IS_COMMON ((FIX)->fx_addsy))))
end_define

begin_define
define|#
directive|define
name|md_parse_name
parameter_list|(
name|name
parameter_list|,
name|exprP
parameter_list|,
name|nextcharP
parameter_list|)
define|\
value|mn10300_parse_name ((name), (exprP), (nextcharP))
end_define

begin_decl_stmt
name|int
name|mn10300_parse_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|expressionS
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
parameter_list|(
name|FRAG
parameter_list|,
name|OFF
parameter_list|,
name|LEN
parameter_list|,
name|EXP
parameter_list|)
define|\
value|mn10300_cons_fix_new ((FRAG), (OFF), (LEN), (EXP))
end_define

begin_decl_stmt
name|void
name|mn10300_cons_fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|expressionS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is used to construct expressions out of @GOTOFF, @PLT and @GOT    symbols.  The relocation type is stored in X_md.  */
end_comment

begin_define
define|#
directive|define
name|O_PIC_reloc
value|O_md1
end_define

begin_comment
comment|/* The target BFD architecture.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_mn10300
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LINUX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-am33lin"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"elf32-mn10300"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do not adjust relocations involving symbols in code sections,    because it breaks linker relaxations.  This could be fixed in the    linker, but this fix is simpler, and it pretty much only affects    object size a little bit.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_SUB_SAME
parameter_list|(
name|FIX
parameter_list|,
name|SEC
parameter_list|)
define|\
value|(((SEC)->flags& SEC_CODE) != 0		\    || ! SEG_NORMAL (SEC)			\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_comment
comment|/* We validate subtract arguments within tc_gen_reloc(), so don't    report errors at this point.  */
end_comment

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX_SUB
parameter_list|(
name|FIX
parameter_list|)
value|1
end_define

begin_comment
comment|/* Fixup debug sections since we will never relax them.  Ideally, we    could do away with this and instead check every single fixup with    TC_FORCE_RELOCATION and TC_FORCE_RELOCATION_SUB_NAME, verifying    that the sections of the referenced symbols (and not the sections    in which the fixup appears) may be subject to relaxation.  We'd    still have to check the section in which the fixup appears, because    we want to do some simplifications in debugging info that might    break in real code.     Using the infrastructure in write.c to simplify subtraction fixups    would enable us to remove a lot of code from tc_gen_reloc(), but    this is simpler, faster, and produces almost the same effect.    Also, in the macros above, we can't check whether the fixup is in a    debugging section or not, so we have to use this for now.  */
end_comment

begin_define
define|#
directive|define
name|TC_LINKRELAX_FIXUP
parameter_list|(
name|seg
parameter_list|)
value|(seg->flags& SEC_ALLOC)
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* Permit temporary numeric labels.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* We don't need to handle .word strangely.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|md_number_to_chars
value|number_to_chars_littleendian
end_define

begin_comment
comment|/* Don't bother to adjust relocs.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_comment
comment|/* #define tc_fix_adjustable(FIX) mn10300_fix_adjustable (FIX) */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mn10300_fix_adjustable
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We do relaxing in the assembler as well as the linker.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|relax_type
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TC_GENERIC_RELAX_TABLE
value|md_relax_table
end_define

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|1
end_define

end_unit

