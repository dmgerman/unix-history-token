begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-sparc.h - Macros and type defines for the sparc.    Copyright (C) 1989, 90-96, 97, 1998 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2,    or (at your option) any later version.     GAS is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See    the GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with GAS; see the file COPYING.  If not, write    to the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_SPARC
end_ifndef

begin_define
define|#
directive|define
name|TC_SPARC
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_struct_decl
struct_decl|struct
name|frag
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is used to set the default value for `target_big_endian'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_sparc
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|sparc_target_format
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
name|TARGET_FORMAT
value|sparc_target_format ()
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TE_SPARCAOUT
end_ifdef

begin_comment
comment|/* Bi-endian support may eventually be unconditional, but until things are    working well it's only provided for targets that need it.  */
end_comment

begin_define
define|#
directive|define
name|SPARC_BIENDIAN
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
name|md_convert_frag
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|{as_fatal ("sparc convert_frag\n");}
end_define

begin_define
define|#
directive|define
name|md_create_long_jump
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|fr
parameter_list|,
name|s
parameter_list|)
value|as_fatal("sparc_create_long_jump")
end_define

begin_define
define|#
directive|define
name|md_create_short_jump
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|t
parameter_list|,
name|fr
parameter_list|,
name|s
parameter_list|)
value|as_fatal("sparc_create_short_jump")
end_define

begin_define
define|#
directive|define
name|md_estimate_size_before_relax
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|)
define|\
value|(as_fatal("estimate_size_before_relax called"),1)
end_define

begin_define
define|#
directive|define
name|LISTING_HEADER
value|"SPARC GAS "
end_define

begin_decl_stmt
specifier|extern
name|int
name|sparc_pic_code
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|md_do_align
parameter_list|(
name|n
parameter_list|,
name|fill
parameter_list|,
name|len
parameter_list|,
name|max
parameter_list|,
name|around
parameter_list|)
define|\
value|if ((n)&& (n)<= 10&& !need_pass_2&& !(fill)				\&& now_seg != data_section&& now_seg != bss_section)		\   {									\     char *p;								\     p = frag_var (rs_align_code, 1024, 1, (relax_substateT) 1024,	\                   (symbolS *) 0, (offsetT) (n), (char *) 0);		\     *p = 0x00;								\     goto around;							\   }
end_define

begin_comment
comment|/* We require .word, et. al., to be aligned correctly.  */
end_comment

begin_define
define|#
directive|define
name|md_cons_align
parameter_list|(
name|nbytes
parameter_list|)
value|sparc_cons_align (nbytes)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_cons_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HANDLE_ALIGN
parameter_list|(
name|fragp
parameter_list|)
value|sparc_handle_align (fragp)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_handle_align
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|OBJ_ELF
argument_list|)
operator|||
name|defined
argument_list|(
name|OBJ_AOUT
argument_list|)
end_if

begin_comment
comment|/* This expression evaluates to false if the relocation is for a local    object for which we still want to do the relocation at runtime.    True if we are willing to perform this relocation while building    the .o file.     If the reloc is against an externally visible symbol, then the    a.out assembler should not do the relocation if generating PIC, and    the ELF assembler should never do the relocation.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_define
define|#
directive|define
name|obj_relocate_extern
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|obj_relocate_extern
value|(! sparc_pic_code)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TC_RELOC_RTSYM_LOC_FIXUP
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(obj_relocate_extern \    || (FIX)->fx_addsy == NULL \    || (! S_IS_EXTERNAL ((FIX)->fx_addsy) \&& ! S_IS_WEAK ((FIX)->fx_addsy) \&& S_IS_DEFINED ((FIX)->fx_addsy) \&& ! S_IS_COMMON ((FIX)->fx_addsy)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I know that "call 0" fails in sparc-coff if this doesn't return 1.  I    don't know about other relocation types, or other formats, yet.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_COFF
end_ifdef

begin_define
define|#
directive|define
name|TC_FORCE_RELOCATION
parameter_list|(
name|FIXP
parameter_list|)
define|\
value|((FIXP)->fx_r_type == BFD_RELOC_32_PCREL_S2 \&& ((FIXP)->fx_addsy == 0 \ 	     || S_GET_SEGMENT ((FIXP)->fx_addsy) == absolute_section))
end_define

begin_define
define|#
directive|define
name|RELOC_REQUIRES_SYMBOL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_APPLY_FIX3
end_define

begin_define
define|#
directive|define
name|TC_HANDLES_FX_DONE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_ELF
end_ifdef

begin_comment
comment|/* Keep relocations against global symbols.  Don't turn them into    relocations against sections.  This is required for the dynamic    linker to operate properly.  When generating PIC, we need to keep    any non PC relative reloc.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(! S_IS_EXTERNAL ((FIX)->fx_addsy)					\&& ! S_IS_WEAK ((FIX)->fx_addsy)					\&& (! sparc_pic_code							\        || (FIX)->fx_pcrel						\        || ((FIX)->fx_subsy != NULL					\&& (S_GET_SEGMENT ((FIX)->fx_subsy)				\ 	       == S_GET_SEGMENT ((FIX)->fx_addsy)))			\        || strchr (S_GET_NAME ((FIX)->fx_addsy), '\001') != NULL		\        || strchr (S_GET_NAME ((FIX)->fx_addsy), '\002') != NULL))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|OBJ_AOUT
end_ifdef

begin_comment
comment|/* When generating PIC code, we must not adjust any reloc which will    turn into a reloc against the global offset table.  */
end_comment

begin_define
define|#
directive|define
name|tc_fix_adjustable
parameter_list|(
name|FIX
parameter_list|)
define|\
value|(! sparc_pic_code \    || (FIX)->fx_pcrel \    || (FIX)->fx_r_type == BFD_RELOC_16 \    || (FIX)->fx_r_type == BFD_RELOC_32)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|elf_tc_final_processing
value|sparc_elf_final_processing
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_elf_final_processing
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
name|md_operand
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sparc_md_end
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
name|md_end
parameter_list|()
value|sparc_md_end ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* end of tc-sparc.h */
end_comment

end_unit

