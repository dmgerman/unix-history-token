begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* write.h    Copyright 1987, 1992, 1993, 1994, 1995, 1996, 1997, 1999, 2000, 2001,    2002, 2003, 2005, 2006, 2007    Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
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

begin_comment
comment|/* This is the name of a fake symbol which will never appear in the    assembler output.  S_IS_LOCAL detects it because of the \001.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FAKE_LABEL_NAME
end_ifndef

begin_define
define|#
directive|define
name|FAKE_LABEL_NAME
value|"L0\001"
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Is this a pc-relative relocation?  */
name|unsigned
name|fx_pcrel
range|:
literal|1
decl_stmt|;
comment|/* Is this value an immediate displacement?  */
comment|/* Only used on ns32k; merge it into TC_FIX_TYPE sometime.  */
name|unsigned
name|fx_im_disp
range|:
literal|2
decl_stmt|;
comment|/* Some bits for the CPU specific code.  */
name|unsigned
name|fx_tcbit
range|:
literal|1
decl_stmt|;
name|unsigned
name|fx_tcbit2
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
comment|/* pc-relative offset adjust (only used by m68k and m68hc11) */
name|char
name|fx_pcrel_adjust
decl_stmt|;
comment|/* How many bytes are involved? */
name|unsigned
name|char
name|fx_size
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
comment|/* The value of dot when the fixup expression was parsed.  */
name|addressT
name|fx_dot_value
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
name|bfd_reloc_code_real_type
name|fx_r_type
decl_stmt|;
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
comment|/* Which ifield this fixup applies to. */
name|struct
name|cgen_maybe_multi_ifield
modifier|*
name|field
decl_stmt|;
comment|/* is this field is the MSB field in a set? */
name|int
name|msb_field_p
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

begin_struct
struct|struct
name|reloc_list
block|{
name|struct
name|reloc_list
modifier|*
name|next
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|symbolS
modifier|*
name|offset_sym
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|symbolS
modifier|*
name|sym
decl_stmt|;
name|bfd_vma
name|addend
decl_stmt|;
block|}
name|a
struct|;
struct|struct
block|{
name|asection
modifier|*
name|sec
decl_stmt|;
name|asymbol
modifier|*
name|s
decl_stmt|;
name|arelent
name|r
decl_stmt|;
block|}
name|b
struct|;
block|}
name|u
union|;
name|char
modifier|*
name|file
decl_stmt|;
name|unsigned
name|int
name|line
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|finalize_syms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|symbolS
modifier|*
name|abs_section_sym
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|addressT
name|dot_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|reloc_list
modifier|*
name|reloc_list
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|append
parameter_list|(
name|char
modifier|*
modifier|*
name|charPP
parameter_list|,
name|char
modifier|*
name|fromP
parameter_list|,
name|unsigned
name|long
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_alignment
parameter_list|(
name|segT
name|seg
parameter_list|,
name|int
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_recorded_alignment
parameter_list|(
name|segT
name|seg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|subsegs_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_object_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|relax_frag
parameter_list|(
name|segT
parameter_list|,
name|fragS
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|relax_segment
parameter_list|(
name|struct
name|frag
modifier|*
parameter_list|,
name|segT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|number_to_chars_littleendian
parameter_list|(
name|char
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|number_to_chars_bigendian
parameter_list|(
name|char
modifier|*
parameter_list|,
name|valueT
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fixS
modifier|*
name|fix_new
parameter_list|(
name|fragS
modifier|*
name|frag
parameter_list|,
name|int
name|where
parameter_list|,
name|int
name|size
parameter_list|,
name|symbolS
modifier|*
name|add_symbol
parameter_list|,
name|offsetT
name|offset
parameter_list|,
name|int
name|pcrel
parameter_list|,
name|bfd_reloc_code_real_type
name|r_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|fixS
modifier|*
name|fix_new_exp
parameter_list|(
name|fragS
modifier|*
name|frag
parameter_list|,
name|int
name|where
parameter_list|,
name|int
name|size
parameter_list|,
name|expressionS
modifier|*
name|exp
parameter_list|,
name|int
name|pcrel
parameter_list|,
name|bfd_reloc_code_real_type
name|r_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __write_h__ */
end_comment

end_unit

