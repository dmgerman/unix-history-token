begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* write.h    Copyright 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__write_h__
end_ifndef

begin_define
define|#
directive|define
name|__write_h__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I960
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|EXEC_MACHINE_TYPE
value|HP9000S200_ID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABEL
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name [0] == 'L' )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|S_LOCAL_NAME
parameter_list|(
name|s
parameter_list|)
value|(LOCAL_LABEL (S_GET_NAME (s)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! BFD_ASSEMBLER */
end_comment

begin_comment
comment|/* This is the name of a fake symbol which will never appear in the    assembler output.  S_IS_LOCAL detects it because of the \001.  */
end_comment

begin_define
define|#
directive|define
name|FAKE_LABEL_NAME
value|"L0\001"
end_define

begin_include
include|#
directive|include
file|"bit_fix.h"
end_include

begin_comment
comment|/*  * FixSs may be built up in any order.  */
end_comment

begin_struct
struct|struct
name|fix
block|{
comment|/* These small fields are grouped together for compactness of      this structure, and efficiency of access on some architectures.  */
comment|/* pc-relative offset adjust (only used by m68k) */
name|char
name|fx_pcrel_adjust
decl_stmt|;
comment|/* How many bytes are involved? */
name|unsigned
name|char
name|fx_size
decl_stmt|;
comment|/* Is this a pc-relative relocation?  */
name|unsigned
name|fx_pcrel
range|:
literal|1
decl_stmt|;
comment|/* Is this a relocation to a procedure linkage table entry?  If so,      some of the reductions we try to apply are invalid.  A better way      might be to represent PLT entries with different kinds of      symbols, and use normal relocations (with undefined symbols);      look into it for version 2.6.  */
name|unsigned
name|fx_plt
range|:
literal|1
decl_stmt|;
comment|/* Is this value an immediate displacement?  */
comment|/* Only used on i960 and ns32k; merge it into TC_FIX_TYPE sometime.  */
name|unsigned
name|fx_im_disp
range|:
literal|2
decl_stmt|;
comment|/* A bit for the CPU specific code.      This probably can be folded into tc_fix_data, below.  */
name|unsigned
name|fx_tcbit
range|:
literal|1
decl_stmt|;
comment|/* Has this relocation already been applied?  */
name|unsigned
name|fx_done
range|:
literal|1
decl_stmt|;
comment|/* Suppress overflow complaints on large addends.  This is used      in the PowerPC ELF config to allow large addends on the      BFD_RELOC_{LO16,HI16,HI16_S} relocations.       @@ Can this be determined from BFD?  */
name|unsigned
name|fx_no_overflow
range|:
literal|1
decl_stmt|;
comment|/* The value is signed when checking for overflow.  */
name|unsigned
name|fx_signed
range|:
literal|1
decl_stmt|;
comment|/* Which frag does this fix apply to?  */
name|fragS
modifier|*
name|fx_frag
decl_stmt|;
comment|/* Where is the first byte to fix up?  */
name|long
name|fx_where
decl_stmt|;
comment|/* NULL or Symbol whose value we add in.  */
name|symbolS
modifier|*
name|fx_addsy
decl_stmt|;
comment|/* NULL or Symbol whose value we subtract.  */
name|symbolS
modifier|*
name|fx_subsy
decl_stmt|;
comment|/* Absolute number we add in.  */
name|valueT
name|fx_offset
decl_stmt|;
comment|/* Next fixS in linked list, or NULL.  */
name|struct
name|fix
modifier|*
name|fx_next
decl_stmt|;
comment|/* If NULL, no bitfix's to do.  */
comment|/* Only i960-coff and ns32k use this, and i960-coff stores an      integer.  This can probably be folded into tc_fix_data, below.      @@ Alpha also uses it, but only to disable certain relocation      processing.  */
name|bit_fixS
modifier|*
name|fx_bit_fixP
decl_stmt|;
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
name|bfd_reloc_code_real_type
name|fx_r_type
decl_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|NEED_FX_R_TYPE
comment|/* Hack for machines where the type of reloc can't be      worked out by looking at how big it is.  */
name|int
name|fx_r_type
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* This field is sort of misnamed.  It appears to be a sort of random      scratch field, for use by the back ends.  The main gas code doesn't      do anything but initialize it to zero.  The use of it does need to      be coordinated between the cpu and format files, though.  E.g., some      coff targets pass the `addend' field from the cpu file via this      field.  I don't know why the `fx_offset' field above can't be used      for that; investigate later and document. KR  */
name|valueT
name|fx_addnumber
decl_stmt|;
comment|/* The location of the instruction which created the reloc, used      in error messages.  */
name|char
modifier|*
name|fx_file
decl_stmt|;
name|unsigned
name|fx_line
decl_stmt|;
ifdef|#
directive|ifdef
name|USING_CGEN
struct|struct
block|{
comment|/* CGEN_INSN entry for this instruction.  */
specifier|const
name|struct
name|cgen_insn
modifier|*
name|insn
decl_stmt|;
comment|/* Target specific data, usually reloc number.  */
name|int
name|opinfo
decl_stmt|;
block|}
name|fx_cgen
struct|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TC_FIX_TYPE
comment|/* Location where a backend can attach additional data      needed to perform fixups.  */
name|TC_FIX_TYPE
name|tc_fix_data
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fix
name|fixS
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|BFD_ASSEMBLER
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|next_object_file_charP
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MANY_SEGMENTS
end_ifndef

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|text_fix_root
decl_stmt|,
modifier|*
name|text_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs.  */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|data_fix_root
decl_stmt|,
modifier|*
name|data_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs.  */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|bss_fix_root
decl_stmt|,
modifier|*
name|bss_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|frag
modifier|*
name|text_last_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last frag in segment.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|frag
modifier|*
name|data_last_frag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last frag in segment.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
modifier|*
name|seg_fix_rootP
decl_stmt|,
modifier|*
modifier|*
name|seg_fix_tailP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> one of above.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|long
name|string_byte_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|section_alignment
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bit_fixS
modifier|*
name|bit_fix_new
name|PARAMS
argument_list|(
operator|(
name|int
name|size
operator|,
name|int
name|offset
operator|,
name|long
name|base_type
operator|,
name|long
name|base_adj
operator|,
name|long
name|min
operator|,
name|long
name|max
operator|,
name|long
name|add
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|append
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|*
name|charPP
operator|,
name|char
operator|*
name|fromP
operator|,
name|unsigned
name|long
name|length
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_alignment
name|PARAMS
argument_list|(
operator|(
name|segT
name|seg
operator|,
name|int
name|align
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_recorded_alignment
name|PARAMS
argument_list|(
operator|(
name|segT
name|seg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|subsegs_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|write_object_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|relax_frag
name|PARAMS
argument_list|(
operator|(
name|segT
operator|,
name|fragS
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|relax_segment
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frag
operator|*
name|seg_frag_root
operator|,
name|segT
name|seg_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|number_to_chars_littleendian
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|valueT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|number_to_chars_bigendian
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|valueT
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ASSEMBLER
end_ifdef

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|frag
operator|,
name|int
name|where
operator|,
name|int
name|size
operator|,
name|symbolS
operator|*
name|add_symbol
operator|,
name|offsetT
name|offset
operator|,
name|int
name|pcrel
operator|,
name|bfd_reloc_code_real_type
name|r_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|fix_new_exp
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|frag
operator|,
name|int
name|where
operator|,
name|int
name|size
operator|,
name|expressionS
operator|*
name|exp
operator|,
name|int
name|pcrel
operator|,
name|bfd_reloc_code_real_type
name|r_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|fix_new
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|frag
operator|,
name|int
name|where
operator|,
name|int
name|size
operator|,
name|symbolS
operator|*
name|add_symbol
operator|,
name|offsetT
name|offset
operator|,
name|int
name|pcrel
operator|,
name|int
name|r_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fixS
modifier|*
name|fix_new_exp
name|PARAMS
argument_list|(
operator|(
name|fragS
operator|*
name|frag
operator|,
name|int
name|where
operator|,
name|int
name|size
operator|,
name|expressionS
operator|*
name|exp
operator|,
name|int
name|pcrel
operator|,
name|int
name|r_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|write_print_statistics
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __write_h__ */
end_comment

end_unit

