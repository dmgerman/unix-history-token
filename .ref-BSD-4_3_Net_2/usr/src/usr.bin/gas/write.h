begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* write.h -> write.c    Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of GAS, the GNU Assembler.  GAS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GAS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GAS; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The bit_fix was implemented to support machines that need variables    to be inserted in bitfields other than 1, 2 and 4 bytes.     Furthermore it gives us a possibillity to mask in bits in the symbol    when it's fixed in the objectcode and check the symbols limits.     The or-mask is used to set the huffman bits in displacements for the    ns32k port.    The acbi, addqi, movqi, cmpqi instruction requires an assembler that    can handle bitfields. Ie handle an expression, evaluate it and insert    the result in an some bitfield. ( ex: 5 bits in a short field of a opcode)   */
end_comment

begin_struct
struct|struct
name|bit_fix
block|{
name|int
name|fx_bit_size
decl_stmt|;
comment|/* Length of bitfield		*/
name|int
name|fx_bit_offset
decl_stmt|;
comment|/* Bit offset to bitfield	*/
name|long
name|fx_bit_base
decl_stmt|;
comment|/* Where do we apply the bitfix. 					If this is zero, default is assumed. */
name|long
name|fx_bit_base_adj
decl_stmt|;
comment|/* Adjustment of base */
name|long
name|fx_bit_max
decl_stmt|;
comment|/* Signextended max for bitfield */
name|long
name|fx_bit_min
decl_stmt|;
comment|/* Signextended min for bitfield */
name|long
name|fx_bit_add
decl_stmt|;
comment|/* Or mask, used for huffman prefix */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|bit_fix
name|bit_fixS
typedef|;
end_typedef

begin_comment
comment|/*  * FixSs may be built up in any order.  */
end_comment

begin_struct
struct|struct
name|fix
block|{
name|fragS
modifier|*
name|fx_frag
decl_stmt|;
comment|/* Which frag? */
name|long
name|int
name|fx_where
decl_stmt|;
comment|/* Where is the 1st byte to fix up? */
name|symbolS
modifier|*
name|fx_addsy
decl_stmt|;
comment|/* NULL or Symbol whose value we add in. */
name|symbolS
modifier|*
name|fx_subsy
decl_stmt|;
comment|/* NULL or Symbol whose value we subtract. */
name|long
name|int
name|fx_offset
decl_stmt|;
comment|/* Absolute number we add in. */
name|struct
name|fix
modifier|*
name|fx_next
decl_stmt|;
comment|/* NULL or -> next fixS. */
name|short
name|int
name|fx_size
decl_stmt|;
comment|/* How many bytes are involved? */
name|char
name|fx_pcrel
decl_stmt|;
comment|/* TRUE: pc-relative. */
name|char
name|fx_pcrel_adjust
decl_stmt|;
comment|/* pc-relative offset adjust */
name|char
name|fx_im_disp
decl_stmt|;
comment|/* TRUE: value is a displacement */
name|bit_fixS
modifier|*
name|fx_bit_fixP
decl_stmt|;
comment|/* IF NULL no bitfix's to do */
name|char
name|fx_bsr
decl_stmt|;
comment|/* sequent-hack */
if|#
directive|if
name|defined
argument_list|(
name|SPARC
argument_list|)
operator|||
name|defined
argument_list|(
name|I860
argument_list|)
name|char
name|fx_r_type
decl_stmt|;
comment|/* Sparc hacks */
name|long
name|fx_addnumber
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

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|text_fix_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs. */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|data_fix_root
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs. */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
modifier|*
name|seg_fix_rootP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> one of above. */
end_comment

begin_function_decl
name|bit_fixS
modifier|*
name|bit_fix_new
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end: write.h */
end_comment

end_unit

