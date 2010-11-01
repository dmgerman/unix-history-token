begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* subsegs.h -> subsegs.c    Copyright 1987, 1992, 1993, 1994, 1995, 1996, 1998, 2000, 2003, 2005,    2006 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_comment
comment|/*  * For every sub-segment the user mentions in the ASsembler program,  * we make one struct frchain. Each sub-segment has exactly one struct frchain  * and vice versa.  *  * Struct frchain's are forward chained (in ascending order of sub-segment  * code number). The chain runs through frch_next of each subsegment.  * This makes it hard to find a subsegment's frags  * if programmer uses a lot of them. Most programs only use text0 and  * data0, so they don't suffer. At least this way:  * (1)	There are no "arbitrary" restrictions on how many subsegments  *	can be programmed;  * (2)	Subsegments' frchain-s are (later) chained together in the order in  *	which they are emitted for object file viz text then data.  *  * From each struct frchain dangles a chain of struct frags. The frags  * represent code fragments, for that sub-segment, forward chained.  */
end_comment

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_struct_decl
struct_decl|struct
name|frch_cfi_data
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|frchain
comment|/* control building of a frag chain */
block|{
comment|/* FRCH = FRagment CHain control */
name|struct
name|frag
modifier|*
name|frch_root
decl_stmt|;
comment|/* 1st struct frag in chain, or NULL */
name|struct
name|frag
modifier|*
name|frch_last
decl_stmt|;
comment|/* last struct frag in chain, or NULL */
name|struct
name|frchain
modifier|*
name|frch_next
decl_stmt|;
comment|/* next in chain of struct frchain-s */
name|subsegT
name|frch_subseg
decl_stmt|;
comment|/* subsegment number of this chain */
name|fixS
modifier|*
name|fix_root
decl_stmt|;
comment|/* Root of fixups for this subsegment.  */
name|fixS
modifier|*
name|fix_tail
decl_stmt|;
comment|/* Last fixup for this subsegment.  */
name|struct
name|obstack
name|frch_obstack
decl_stmt|;
comment|/* for objects in this frag chain */
name|fragS
modifier|*
name|frch_frag_now
decl_stmt|;
comment|/* frag_now for this subsegment */
name|struct
name|frch_cfi_data
modifier|*
name|frch_cfi_data
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|frchain
name|frchainS
typedef|;
end_typedef

begin_comment
comment|/* Frchain we are assembling into now.  That is, the current segment's    frag chain, even if it contains no (complete) frags.  */
end_comment

begin_decl_stmt
specifier|extern
name|frchainS
modifier|*
name|frchain_now
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
struct|struct
name|segment_info_struct
block|{
name|frchainS
modifier|*
name|frchainP
decl_stmt|;
name|unsigned
name|int
name|hadone
range|:
literal|1
decl_stmt|;
comment|/* This field is set if this is a .bss section which does not really      have any contents.  Once upon a time a .bss section did not have      any frags, but that is no longer true.  This field prevent the      SEC_HAS_CONTENTS flag from being set for the section even if      there are frags.  */
name|unsigned
name|int
name|bss
range|:
literal|1
decl_stmt|;
name|int
name|user_stuff
decl_stmt|;
comment|/* Fixups for this segment.  This is only valid after the frchains      are run together.  */
name|fixS
modifier|*
name|fix_root
decl_stmt|;
name|fixS
modifier|*
name|fix_tail
decl_stmt|;
name|symbolS
modifier|*
name|dot
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_head
decl_stmt|;
name|struct
name|lineno_list
modifier|*
name|lineno_list_tail
decl_stmt|;
comment|/* Which BFD section does this gas segment correspond to?  */
name|asection
modifier|*
name|bfd_section
decl_stmt|;
comment|/* NULL, or pointer to the gas symbol that is the section symbol for      this section.  sym->bsym and bfd_section->symbol should be the same.  */
name|symbolS
modifier|*
name|sym
decl_stmt|;
union|union
block|{
comment|/* Current size of section holding stabs strings.  */
name|unsigned
name|long
name|stab_string_size
decl_stmt|;
comment|/* Initial frag for ELF.  */
name|char
modifier|*
name|p
decl_stmt|;
block|}
name|stabu
union|;
ifdef|#
directive|ifdef
name|NEED_LITERAL_POOL
name|unsigned
name|long
name|literal_pool_size
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|TC_SEGMENT_INFO_TYPE
name|TC_SEGMENT_INFO_TYPE
name|tc_segment_info_data
decl_stmt|;
endif|#
directive|endif
block|}
name|segment_info_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|seg_info
parameter_list|(
name|sec
parameter_list|)
define|\
value|((segment_info_type *) bfd_get_section_userdata (stdoutput, sec))
end_define

begin_function_decl
specifier|extern
name|symbolS
modifier|*
name|section_symbol
parameter_list|(
name|segT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|subsegs_print_statistics
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

