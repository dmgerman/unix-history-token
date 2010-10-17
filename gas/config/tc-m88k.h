begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m88k.h -- Assembler for the Motorola 88000    Contributed by Devon Bowen of Buffalo University    and Torbjorn Granlund of the Swedish Institute of Computer Science.    Copyright 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2000,    2002 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_M88K
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M88KCOFF
end_ifdef

begin_define
define|#
directive|define
name|COFF_MAGIC
value|MC88OMAGIC
end_define

begin_define
define|#
directive|define
name|BFD_ARCH
value|bfd_arch_m88k
end_define

begin_define
define|#
directive|define
name|COFF_FLAGS
value|F_AR32W
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEED_FX_R_TYPE
end_define

begin_define
define|#
directive|define
name|TC_KEEP_FX_OFFSET
end_define

begin_define
define|#
directive|define
name|TC_CONS_RELOC
value|RELOC_32
end_define

begin_comment
comment|/* different type of relocation available in the m88k */
end_comment

begin_enum
enum|enum
name|reloc_type
block|{
name|RELOC_LO16
block|,
comment|/* lo16(sym) */
name|RELOC_HI16
block|,
comment|/* hi16(sym) */
name|RELOC_PC16
block|,
comment|/* bb0, bb1, bcnd */
name|RELOC_PC26
block|,
comment|/* br, bsr */
name|RELOC_32
block|,
comment|/* jump tables, etc */
name|RELOC_IW16
block|,
comment|/* global access through linker regs 28 */
name|NO_RELOC
block|}
enum|;
end_enum

begin_struct
struct|struct
name|reloc_info_m88k
block|{
name|unsigned
name|long
name|int
name|r_address
decl_stmt|;
name|unsigned
name|int
name|r_symbolnum
range|:
literal|24
decl_stmt|;
name|unsigned
name|int
name|r_extern
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|r_pad
range|:
literal|3
decl_stmt|;
name|enum
name|reloc_type
name|r_type
range|:
literal|4
decl_stmt|;
name|long
name|int
name|r_addend
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|relocation_info
value|reloc_info_m88k
end_define

begin_comment
comment|/* The m88k uses '@' to start local labels.  */
end_comment

begin_define
define|#
directive|define
name|LEX_AT
value|(LEX_BEGIN_NAME | LEX_NAME)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
define|\
value|((name[0] =='@'&& (name [1] == 'L' || name [1] == '.')) \    || (name[0] == 'L'&& name[1] == '0'&& name[2] == '\001'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The m88k uses pseudo-ops with no leading period.  */
end_comment

begin_define
define|#
directive|define
name|NO_PSEUDO_DOT
value|1
end_define

begin_comment
comment|/* Don't warn on word overflow; it happens on %hi relocs.  */
end_comment

begin_undef
undef|#
directive|undef
name|WARN_SIGNED_OVERFLOW_WORD
end_undef

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
value|{as_fatal (_("m88k convert_frag\n"));}
end_define

begin_comment
comment|/* We don't need to do anything special for undefined symbols.  */
end_comment

begin_define
define|#
directive|define
name|md_undefined_symbol
parameter_list|(
name|s
parameter_list|)
value|0
end_define

begin_comment
comment|/* We have no special operand handling.  */
end_comment

begin_define
define|#
directive|define
name|md_operand
parameter_list|(
name|e
parameter_list|)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|M88KCOFF
end_ifdef

begin_comment
comment|/* Whether a reloc should be output.  */
end_comment

begin_define
define|#
directive|define
name|TC_COUNT_RELOC
parameter_list|(
name|fixp
parameter_list|)
value|((fixp)->fx_addsy != NULL)
end_define

begin_comment
comment|/* Get the BFD reloc type to use for a gas fixS structure.  */
end_comment

begin_define
define|#
directive|define
name|TC_COFF_FIX2RTYPE
parameter_list|(
name|fixp
parameter_list|)
value|tc_coff_fix2rtype (fixp)
end_define

begin_comment
comment|/* No special hook needed for symbols.  */
end_comment

begin_define
define|#
directive|define
name|tc_coff_symbol_emit_hook
parameter_list|(
name|s
parameter_list|)
end_define

begin_comment
comment|/* Align sections to a four byte boundary.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|max
end_ifndef

begin_define
define|#
directive|define
name|max
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUB_SEGMENT_ALIGN
parameter_list|(
name|SEG
parameter_list|,
name|FRCHAIN
parameter_list|)
value|max (section_alignment[(int) (SEG)], 4)
end_define

begin_comment
comment|/* Fill in rs_align_code fragments.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|m88k_handle_align
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
name|HANDLE_ALIGN
parameter_list|(
name|frag
parameter_list|)
value|m88k_handle_align (frag)
end_define

begin_define
define|#
directive|define
name|MAX_MEM_FOR_RS_ALIGN_CODE
value|(3 + 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M88KCOFF */
end_comment

end_unit

