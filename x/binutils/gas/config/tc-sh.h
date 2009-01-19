begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-sh.h    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_SH
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_sh
end_define

begin_if
if|#
directive|if
name|ANSI_PROTOTYPES
end_if

begin_struct_decl
struct_decl|struct
name|segment_info_struct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|internal_reloc
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Whether -relax was used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_relax
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether -small was used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sh_small
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't try to break words.  */
end_comment

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_comment
comment|/* All SH instructions are multiples of 16 bits.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_comment
comment|/* We require .long, et. al., to be aligned correctly.  */
end_comment

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|sh_cons_align (nbytes)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sh_cons_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When relaxing, we need to generate relocations for alignment    directives.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|sh_handle_align (frag)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sh_handle_align
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(1 + 2)
end_define

begin_comment
comment|/* We need to force out some relocations when relaxing.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|fix
parameter_list|)
value|sh_force_relocation (fix)
end_define

begin_comment
comment|/* The type fixS is defined (to struct fix) in write.h, but write.h uses    definitions from this file.  To avoid problems with including write.h    after the "right" definitions, don't; just forward-declare struct fix    here.  */
end_comment

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|sh_force_relocation
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

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|obj_fix_adjustable
parameter_list|(
name|fixP
parameter_list|)
value|sh_fix_adjustable(fixP)
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|boolean
name|sh_fix_adjustable
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
comment|/* This arranges for gas/write.c to not apply a relocation if    obj_fix_adjustable() says it is not adjustable.  */
end_comment

begin_comment
comment|/* ??? fixups with symbols in SEC_MERGE sections are marked with    obj_fix_adjustable and have a non-section symbol, as in    "vwxyz"+1 in execute/string-opt-6.c .  Maybe the test of    (symbol_used_in_reloc_p should be done in the machine-independent code.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_ADJUSTABLE
parameter_list|(
name|fixP
parameter_list|)
define|\
value|(! symbol_used_in_reloc_p (fixP->fx_addsy)&& obj_fix_adjustable (fixP))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_PCREL_FROM_SECTION
parameter_list|(
name|FIXP
parameter_list|,
name|SEC
parameter_list|)
value|md_pcrel_from_section (FIXP, SEC)
end_define

begin_decl_stmt
specifier|extern
name|long
name|md_pcrel_from_section
name|PARAMS
argument_list|(
operator|(
expr|struct
name|fix
operator|*
operator|,
name|segT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IGNORE_NONSTANDARD_ESCAPES
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
define|\
value|(!target_big_endian \    ? "Hitachi Super-H GAS Little Endian" : "Hitachi Super-H GAS Big Endian")
end_define

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

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

begin_comment
comment|/* We record, for each section, whether we have most recently output a    CODE reloc or a DATA reloc.  */
end_comment

begin_struct
struct|struct
name|sh_segment_info_type
block|{
name|int
name|in_code
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|struct sh_segment_info_type
end_define

begin_comment
comment|/* We call a routine to emit a reloc for a label, so that the linker    can align loads and stores without crossing a label.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sh_frob_label
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|sym
parameter_list|)
value|sh_frob_label ()
end_define

begin_comment
comment|/* We call a routine to flush pending output in order to output a DATA    reloc when required.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sh_flush_pending_output
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_flush_pending_output
parameter_list|()
value|sh_flush_pending_output ()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|tc_frob_file_before_adjust
value|sh_frob_file
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tc_frob_file
value|sh_frob_file
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|sh_frob_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_comment
comment|/* COFF specific definitions.  */
end_comment

begin_define
define|#
directive|define
name|DO_NOT_STRIP
value|0
end_define

begin_comment
comment|/* This macro translates between an internal fix and an coff reloc type */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fix
parameter_list|)
value|((fix)->fx_r_type)
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|TARGET_ARCH
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|(!target_big_endian ? SH_ARCH_MAGIC_LITTLE : SH_ARCH_MAGIC_BIG)
end_define

begin_comment
comment|/* We need to write out relocs which have not been completed.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|fix
parameter_list|)
value|((fix)->fx_addsy != NULL)
end_define

begin_define
define|#
directive|define
name|TC_RELOC_MANGLE
parameter_list|(
name|seg
parameter_list|,
name|fix
parameter_list|,
name|int
parameter_list|,
name|paddr
parameter_list|)
define|\
value|sh_coff_reloc_mangle ((seg), (fix), (int), (paddr))
end_define

begin_decl_stmt
specifier|extern
name|void
name|sh_coff_reloc_mangle
name|PARAMS
argument_list|(
operator|(
expr|struct
name|segment_info_struct
operator|*
operator|,
expr|struct
name|fix
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|a
parameter_list|)
value|;
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|TC_KEEP_FX_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|TC_COFF_SIZEMACHDEP
parameter_list|(
name|frag
parameter_list|)
value|tc_coff_sizemachdep(frag)
end_define

begin_decl_stmt
specifier|extern
name|int
name|tc_coff_sizemachdep
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_define
define|#
directive|define
name|SEG_NAME
parameter_list|(
name|SEG
parameter_list|)
value|segment_name (SEG)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SEG_NAME
parameter_list|(
name|SEG
parameter_list|)
value|obj_segment_name (SEG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We align most sections to a 16 byte boundary.  */
end_comment

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
define|\
value|(strncmp (SEG_NAME (SEG), ".stabstr", 8) == 0		\    ? 0							\    : ((strncmp (SEG_NAME (SEG), ".stab", 5) == 0	\        || strcmp (SEG_NAME (SEG), ".ctors") == 0	\        || strcmp (SEG_NAME (SEG), ".dtors") == 0)	\       ? 2						\       : (sh_small ? 2 : 4)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_COFF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* ELF specific definitions.  */
end_comment

begin_comment
comment|/* Whether or not the target is big endian */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_big_endian
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TE_LINUX
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-sh-linux" : "elf32-shbig-linux")
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|TE_NetBSD
argument_list|)
end_elif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-shl-nbsd" : "elf32-sh-nbsd")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(!target_big_endian ? "elf32-shl" : "elf32-sh")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|sh_elf_final_processing
end_define

begin_decl_stmt
specifier|extern
name|void
name|sh_elf_final_processing
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_comment
comment|/* foo-. gets turned into PC relative relocs */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"_GLOBAL_OFFSET_TABLE_"
end_define

begin_comment
comment|/* This is the relocation type for direct references to    GLOBAL_OFFSET_TABLE.  It comes up in complicated expressions such    as _GLOBAL_OFFSET_TABLE_+[.-.L284], which cannot be expressed    normally with the regular expressions.  The fixup specified here    when used at runtime implies that we should add the address of the    GOT to the specified location, and as a result we have simplified    the expression into something we can use.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_GLOBAL_OFFSET_TABLE
value|BFD_RELOC_SH_GOTPC
end_define

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local object    for which we still want to do the relocation at runtime.  True if we    are willing to perform this relocation while building the .o file.    This is only used for pcrel relocations, so GOTOFF does not need to be    checked here.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry.     We can't resolve references to the GOT or the PLT when creating the    object file, since these tables are only created by the linker.    Also, if the symbol is global, weak, common or not defined, the    assembler can't compute the appropriate reloc, since its location    can only be determined at link time.  */
end_comment

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|((FIX)->fx_r_type != BFD_RELOC_32_PLT_PCREL			\&& (FIX)->fx_r_type != BFD_RELOC_32_GOT_PCREL		\&& (FIX)->fx_r_type != BFD_RELOC_SH_GOTPC			\&& ((FIX)->fx_addsy == NULL					\        || (! S_IS_EXTERNAL ((FIX)->fx_addsy)			\&& ! S_IS_WEAK ((FIX)->fx_addsy)			\&& S_IS_DEFINED ((FIX)->fx_addsy)			\&& ! S_IS_COMMON ((FIX)->fx_addsy))))
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
value|sh_parse_name ((name), (exprP), (nextcharP))
end_define

begin_decl_stmt
name|int
name|sh_parse_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|name
operator|,
name|expressionS
operator|*
name|exprP
operator|,
name|char
operator|*
name|nextchar
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
value|sh_cons_fix_new ((FRAG), (OFF), (LEN), (EXP))
end_define

begin_decl_stmt
name|void
name|sh_cons_fix_new
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OBJ_ELF */
end_comment

end_unit

