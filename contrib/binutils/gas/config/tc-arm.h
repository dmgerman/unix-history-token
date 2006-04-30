begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is tc-arm.h    Copyright 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2004    Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rwe@pegasus.esprit.ec.org) 	Modified by David Taylor (dtaylor@armltd.co.uk)     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_ARM
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTES_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|WORKING_DOT_WORD
end_define

begin_define
define|#
directive|define
name|COFF_MAGIC
value|ARMMAGIC
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_arm
end_define

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|0
end_define

begin_define
define|#
directive|define
name|DIFF_EXPR_OK
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|LITTLE_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|LITTLE_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BIG_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|BIG_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_struct_decl
struct_decl|struct
name|fix
struct_decl|;
end_struct_decl

begin_if
if|#
directive|if
name|defined
name|OBJ_AOUT
end_if

begin_if
if|#
directive|if
name|defined
name|TE_RISCIX
end_if

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-riscix"
end_define

begin_elif
elif|#
directive|elif
name|defined
name|TE_LINUX
end_elif

begin_define
define|#
directive|define
name|ARM_BI_ENDIAN
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-arm-linux"
end_define

begin_elif
elif|#
directive|elif
name|defined
name|TE_NetBSD
end_elif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-arm-netbsd"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_BI_ENDIAN
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "a.out-arm-big" : "a.out-arm-little")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|OBJ_AIF
end_elif

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"aif"
end_define

begin_elif
elif|#
directive|elif
name|defined
name|OBJ_COFF
end_elif

begin_define
define|#
directive|define
name|ARM_BI_ENDIAN
end_define

begin_if
if|#
directive|if
name|defined
name|TE_PE
end_if

begin_if
if|#
directive|if
name|defined
name|TE_EPOC
end_if

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "epoc-pe-arm-big" : "epoc-pe-arm-little")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "pe-arm-big" : "pe-arm-little")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|(target_big_endian ? "coff-arm-big" : "coff-arm-little")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
name|OBJ_ELF
end_elif

begin_define
define|#
directive|define
name|ARM_BI_ENDIAN
end_define

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|elf32_arm_target_format ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIX
parameter_list|)
value|arm_force_relocation (FIX)
end_define

begin_define
define|#
directive|define
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|{ as_fatal (_("arm convert_frag\n")); }
end_define

begin_define
define|#
directive|define
name|md_cleanup
parameter_list|()
value|arm_cleanup ()
end_define

begin_define
define|#
directive|define
name|md_start_line_hook
parameter_list|()
value|arm_start_line_hook ()
end_define

begin_define
define|#
directive|define
name|tc_frob_label
parameter_list|(
name|S
parameter_list|)
value|arm_frob_label (S)
end_define

begin_comment
comment|/* We also need to mark assembler created symbols:  */
end_comment

begin_define
define|#
directive|define
name|tc_frob_fake_label
parameter_list|(
name|S
parameter_list|)
value|arm_frob_label (S)
end_define

begin_comment
comment|/* NOTE: The fake label creation in stabs.c:s_stab_generic() has    deliberately not been updated to mark assembler created stabs    symbols as Thumb.  */
end_comment

begin_define
define|#
directive|define
name|TC_FIX_TYPE
value|PTR
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|FIX
parameter_list|)
value|((FIX)->tc_fix_data = NULL)
end_define

begin_comment
comment|/* We need to keep some local information on symbols.  */
end_comment

begin_define
define|#
directive|define
name|TC_SYMFIELD_TYPE
value|unsigned int
end_define

begin_define
define|#
directive|define
name|ARM_GET_FLAG
parameter_list|(
name|s
parameter_list|)
value|(*symbol_get_tc (s))
end_define

begin_define
define|#
directive|define
name|ARM_SET_FLAG
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(*symbol_get_tc (s) |= (v))
end_define

begin_define
define|#
directive|define
name|ARM_RESET_FLAG
parameter_list|(
name|s
parameter_list|,
name|v
parameter_list|)
value|(*symbol_get_tc (s)&= ~(v))
end_define

begin_define
define|#
directive|define
name|ARM_FLAG_THUMB
value|(1<< 0)
end_define

begin_comment
comment|/* The symbol is a Thumb symbol rather than an Arm symbol.  */
end_comment

begin_define
define|#
directive|define
name|ARM_FLAG_INTERWORK
value|(1<< 1)
end_define

begin_comment
comment|/* The symbol is attached to code that supports interworking.  */
end_comment

begin_define
define|#
directive|define
name|THUMB_FLAG_FUNC
value|(1<< 2)
end_define

begin_comment
comment|/* The symbol is attached to the start of a Thumb function.  */
end_comment

begin_define
define|#
directive|define
name|ARM_IS_THUMB
parameter_list|(
name|s
parameter_list|)
value|(ARM_GET_FLAG (s)& ARM_FLAG_THUMB)
end_define

begin_define
define|#
directive|define
name|ARM_IS_INTERWORK
parameter_list|(
name|s
parameter_list|)
value|(ARM_GET_FLAG (s)& ARM_FLAG_INTERWORK)
end_define

begin_define
define|#
directive|define
name|THUMB_IS_FUNC
parameter_list|(
name|s
parameter_list|)
value|(ARM_GET_FLAG (s)& THUMB_FLAG_FUNC)
end_define

begin_define
define|#
directive|define
name|ARM_SET_THUMB
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((t) ? ARM_SET_FLAG (s, ARM_FLAG_THUMB)     : ARM_RESET_FLAG (s, ARM_FLAG_THUMB))
end_define

begin_define
define|#
directive|define
name|ARM_SET_INTERWORK
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((t) ? ARM_SET_FLAG (s, ARM_FLAG_INTERWORK) : ARM_RESET_FLAG (s, ARM_FLAG_INTERWORK))
end_define

begin_define
define|#
directive|define
name|THUMB_SET_FUNC
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|((t) ? ARM_SET_FLAG (s, THUMB_FLAG_FUNC)    : ARM_RESET_FLAG (s, THUMB_FLAG_FUNC))
end_define

begin_define
define|#
directive|define
name|TC_START_LABEL
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|(c == ':' || (c == '/'&& arm_data_in_code ()))
end_define

begin_define
define|#
directive|define
name|tc_canonicalize_symbol_name
parameter_list|(
name|str
parameter_list|)
value|arm_canonicalize_symbol_name (str);
end_define

begin_define
define|#
directive|define
name|obj_adjust_symtab
parameter_list|()
value|arm_adjust_symtab ()
end_define

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"ARM GAS "
end_define

begin_define
define|#
directive|define
name|OPTIONAL_REGISTER_PREFIX
value|'%'
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name[0] == '.'&& (name[1] == 'L'))
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_comment
comment|/* This expression evaluates to true if the relocation is for a local    object for which we still want to do the relocation at runtime.    False if we are willing to perform this relocation while building    the .o file.  GOTOFF does not need to be checked here because it is    not pcrel.  I am not sure if some of the others are ever used with    pcrel, but it is easier to be safe than sorry.  */
end_comment

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION_LOCAL
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(!(FIX)->fx_pcrel					\    || (FIX)->fx_plt					\    || (FIX)->fx_r_type == BFD_RELOC_ARM_GOT12		\    || (FIX)->fx_r_type == BFD_RELOC_ARM_GOT32		\    || (FIX)->fx_r_type == BFD_RELOC_32			\    || TC_FORCE_RELOCATION (FIX))
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|cons_fix_new_arm
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|31
end_define

begin_comment
comment|/* For frags in code sections we need to record whether they contain    ARM code or THUMB code.  This is that if they have to be aligned,    they can contain the correct type of no-op instruction.  */
end_comment

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|fragp
parameter_list|)
value|arm_init_frag (fragp)
end_define

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragp
parameter_list|)
value|arm_handle_align (fragp)
end_define

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|N
parameter_list|,
name|FILL
parameter_list|,
name|LEN
parameter_list|,
name|MAX
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|if (FILL == NULL&& (N) != 0&& ! need_pass_2&& subseg_text_p (now_seg))	\     {										\       arm_frag_align_code (N, MAX);						\       goto LABEL;								\     }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|DWARF2_LINE_MIN_INSN_LENGTH
value|2
end_define

begin_define
define|#
directive|define
name|obj_frob_symbol
parameter_list|(
name|sym
parameter_list|,
name|punt
parameter_list|)
value|armelf_frob_symbol ((sym),& (punt))
end_define

begin_define
define|#
directive|define
name|md_elf_section_change_hook
parameter_list|()
value|arm_elf_change_section ()
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
name|LOCAL_LABEL_PREFIX
value|'.'
end_define

begin_define
define|#
directive|define
name|TC_SEGMENT_INFO_TYPE
value|enum mstate
end_define

begin_enum
enum|enum
name|mstate
block|{
name|MAP_UNDEFINED
init|=
literal|0
block|,
comment|/* Must be zero, for seginfo in new sections.  */
name|MAP_DATA
block|,
name|MAP_ARM
block|,
name|MAP_THUMB
block|}
enum|;
end_enum

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not OBJ_ELF.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_OFFSET_TABLE_NAME
value|"__GLOBAL_OFFSET_TABLE_"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
name|OBJ_ELF
operator|||
name|defined
name|OBJ_COFF
end_if

begin_define
define|#
directive|define
name|EXTERN_FORCE_RELOC
value|1
end_define

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
value|arm_fix_adjustable (FIX)
end_define

begin_comment
comment|/* Values passed to md_apply_fix3 don't include the symbol value.  */
end_comment

begin_define
define|#
directive|define
name|MD_APPLY_SYM_VALUE
parameter_list|(
name|FIX
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|TC_VALIDATE_FIX
parameter_list|(
name|FIX
parameter_list|,
name|SEGTYPE
parameter_list|,
name|LABEL
parameter_list|)
value|arm_validate_fix (FIX)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|arm_frag_align_code
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_validate_fix
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|elf32_arm_target_format
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_elf_change_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arm_force_relocation
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_cleanup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_start_line_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_frob_label
parameter_list|(
name|symbolS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|arm_data_in_code
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|arm_canonicalize_symbol_name
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_adjust_symtab
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|armelf_frob_symbol
parameter_list|(
name|symbolS
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cons_fix_new_arm
parameter_list|(
name|fragS
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|expressionS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_init_frag
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|arm_handle_align
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|arm_fix_adjustable
parameter_list|(
name|struct
name|fix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

