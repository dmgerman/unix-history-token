begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-ns32k.h -- Opcode table for National Semi 32k processor    Copyright 1987, 1992, 1993, 1994, 1995, 1997, 2000, 2002, 2005    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TC_NS32K
end_define

begin_define
define|#
directive|define
name|TARGET_BYTES_BIG_ENDIAN
value|0
end_define

begin_define
define|#
directive|define
name|TC_PCREL_ADJUST
parameter_list|(
name|F
parameter_list|)
value|md_pcrel_adjust(F)
end_define

begin_function_decl
specifier|extern
name|int
name|md_pcrel_adjust
parameter_list|(
name|fragS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NO_RELOC
value|BFD_RELOC_NONE
end_define

begin_define
define|#
directive|define
name|TARGET_ARCH
value|bfd_arch_ns32k
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FORMAT
end_ifndef

begin_comment
comment|/* Maybe defined in te-*.h.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORMAT
value|"a.out-pc532-mach"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
value|1
end_define

begin_include
include|#
directive|include
file|"bit_fix.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SEQUENT_COMPATABILITY
end_ifdef

begin_define
define|#
directive|define
name|DEF_MODEC
value|20
end_define

begin_define
define|#
directive|define
name|DEF_MODEL
value|21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_MODEC
end_ifndef

begin_define
define|#
directive|define
name|DEF_MODEC
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_MODEL
end_ifndef

begin_define
define|#
directive|define
name|DEF_MODEL
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_ARGS
value|4
end_define

begin_define
define|#
directive|define
name|ARG_LEN
value|50
end_define

begin_define
define|#
directive|define
name|TC_CONS_FIX_NEW
value|cons_fix_new_ns32k
end_define

begin_function_decl
specifier|extern
name|void
name|cons_fix_new_ns32k
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

begin_comment
comment|/* The NS32x32 has a non 0 nop instruction which should be used in aligns.  */
end_comment

begin_define
define|#
directive|define
name|NOP_OPCODE
value|0xa2
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

begin_define
define|#
directive|define
name|TC_FRAG_TYPE
define|\
value|struct 					\     { 						\       fragS *      fr_opcode_fragP;		\       unsigned int fr_opcode_offset;		\       char         fr_bsr;			\     }
end_define

begin_define
define|#
directive|define
name|TC_FRAG_INIT
parameter_list|(
name|X
parameter_list|)
define|\
value|do						\      {						\        frag_opcode_frag (X) = NULL;		\        frag_opcode_offset (X) = 0;		\        frag_bsr (X) = 0;			\      }						\   while (0)
end_define

begin_comment
comment|/* Accessor macros for things which may move around.  */
end_comment

begin_define
define|#
directive|define
name|frag_opcode_frag
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_frag_data.fr_opcode_fragP
end_define

begin_define
define|#
directive|define
name|frag_opcode_offset
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_frag_data.fr_opcode_offset
end_define

begin_define
define|#
directive|define
name|frag_bsr
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_frag_data.fr_bsr
end_define

begin_define
define|#
directive|define
name|TC_FIX_TYPE
define|\
value|struct					\     {						\       fragS *      opcode_fragP;		\       unsigned int opcode_offset;		\       unsigned int bsr : 1;			\     }
end_define

begin_comment
comment|/* Accessor macros for things which may move around.    See comments in write.h.  */
end_comment

begin_define
define|#
directive|define
name|fix_im_disp
parameter_list|(
name|X
parameter_list|)
value|(X)->fx_im_disp
end_define

begin_define
define|#
directive|define
name|fix_bit_fixP
parameter_list|(
name|X
parameter_list|)
value|(X)->fx_bit_fixP
end_define

begin_define
define|#
directive|define
name|fix_opcode_frag
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_fix_data.opcode_fragP
end_define

begin_define
define|#
directive|define
name|fix_opcode_offset
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_fix_data.opcode_offset
end_define

begin_define
define|#
directive|define
name|fix_bsr
parameter_list|(
name|X
parameter_list|)
value|(X)->tc_fix_data.bsr
end_define

begin_define
define|#
directive|define
name|TC_INIT_FIX_DATA
parameter_list|(
name|X
parameter_list|)
define|\
value|do						\      {						\        fix_opcode_frag(X) = NULL;		\        fix_opcode_offset(X) = 0;		\        fix_bsr(X) = 0;				\      }						\   while (0)
end_define

begin_define
define|#
directive|define
name|TC_FIX_DATA_PRINT
parameter_list|(
name|FILE
parameter_list|,
name|FIX
parameter_list|)
define|\
value|do									\     {									\       fprintf ((FILE), "opcode_frag=%ld, operand offset=%d, bsr=%d\n",	\ 	      (unsigned long) fix_opcode_frag (FIX),			\ 	      fix_opcode_offset (FIX),					\ 	      fix_bsr (FIX));						\     }									\   while (0)
end_define

end_unit

