begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* packed.h */
end_comment

begin_comment
comment|/* Packed array format for Ghostscript */
end_comment

begin_comment
comment|/*  Packed elements come in 2 different sizes, 2 bytes or 8 bytes.  The top bits of the first 16-bit subelement distinguish the 2 forms.  The 'size' of a packed array is the number of elements, not the number of bytes it occupies.  The encoding:  	00-ttttt texrwsnm	full 8-byte object 	01m0jjjj jjjjjjjj	executable operator (for bind) 	01m1vvvv vvvvvvvv	integer (biased by packed_min_intval) 	10miiiii iiiiiiii	literal name 	11miiiii iiiiiiii	executable name  The m bit is the mark bit for the garbage collector.  Note its slightly unusual placement.  The jjj index of executable operators is either the index of the operator in the op_def_table, if the index is less than op_def_count, or the index of the definition in the op_array_table (subtracting op_def_count first).  The iii index of names is the one that the name machinery already maintains.  A name whose index is larger than will fit in the packed representation must be represented as a full 8-byte element.  There are actually two packed array types, t_mixedarray and t_shortarray.  A t_mixedarray can have a mix of 2- and 8-bit elements; a t_shortarray has all 2-byte elements.  In both cases, the `size' is the number of elements.  Packed array elements can be distinguished from full-size elements, so we allow the interpreter to simply execute all the different kinds of arrays directly.  In theory, this could lead to unaligned accesses to full-size (8-byte) refs.  Some machines can't handle unaligned accesses of this kind.  Rather than try to tailor the algorithms to the machine's capabilities, we guarantee that full-size elements in mixed arrays are always properly aligned.  We do this by converting up to 3 preceding 2-byte elements into 8-byte elements so that the alignment is preserved.  The only code this actually affects is in make_packed_array.  However, the save/restore machinery in isave.c is sometimes used to save changes to packed arrays, and it currently only knows how to save full-size, aligned refs.  Note that code in zpacked.c and interp.c knows more about the representation of packed elements than the definitions in this file would imply.  Read the code carefully if you change the representation.   */
end_comment

begin_typedef
typedef|typedef
name|ushort
name|ref_packed
typedef|;
end_typedef

begin_define
define|#
directive|define
name|packed_type_shift
value|12
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|pt_full_ref
init|=
literal|0
block|,
define|#
directive|define
name|pt_min_packed
value|4
name|pt_executable_operator
init|=
literal|4
block|,
name|pt_integer
init|=
literal|5
block|,
name|pt_literal_name
init|=
literal|8
block|,
name|pt_executable_name
init|=
literal|12
block|}
name|packed_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pt_tag
parameter_list|(
name|pt
parameter_list|)
value|((ref_packed)(pt)<< packed_type_shift)
end_define

begin_define
define|#
directive|define
name|r_is_packed
parameter_list|(
name|rp
parameter_list|)
value|(*(ref_packed *)(rp)>= pt_tag(pt_min_packed))
end_define

begin_define
define|#
directive|define
name|packed_ref_is_name
parameter_list|(
name|prp
parameter_list|)
value|(*(prp)>= pt_tag(pt_literal_name))
end_define

begin_define
define|#
directive|define
name|packed_max_full_ref
value|(pt_tag(pt_min_packed) - 1)
end_define

begin_define
define|#
directive|define
name|packed_min_intval
value|(-(1<< (packed_type_shift - 1)))
end_define

begin_define
define|#
directive|define
name|packed_max_intval
value|((1<< (packed_type_shift - 1)) - 1)
end_define

begin_define
define|#
directive|define
name|packed_int_mask
value|((1<< packed_type_shift) - 1)
end_define

begin_define
define|#
directive|define
name|packed_max_name_index
value|((1<< (packed_type_shift + 1)) - 1)
end_define

begin_define
define|#
directive|define
name|packed_per_ref
value|(sizeof(ref) / sizeof(ref_packed))
end_define

begin_comment
comment|/* Packed ref marking */
end_comment

begin_define
define|#
directive|define
name|lp_mark
value|0x2000
end_define

begin_define
define|#
directive|define
name|r_has_pmark
parameter_list|(
name|rp
parameter_list|)
value|(*(rp)& lp_mark)
end_define

begin_define
define|#
directive|define
name|r_set_pmark
parameter_list|(
name|rp
parameter_list|)
value|(*(rp) |= lp_mark)
end_define

begin_define
define|#
directive|define
name|r_clear_pmark
parameter_list|(
name|rp
parameter_list|)
value|(*(rp)&= ~lp_mark)
end_define

begin_comment
comment|/* Procedures implemented in zpacked.c */
end_comment

begin_comment
comment|/* Make a packed array */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|make_packed_array
argument_list|(
name|P4
argument_list|(
name|ref
operator|*
argument_list|,
name|uint
argument_list|,
name|ref
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get an element from a packed array. */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|packed_get
argument_list|(
name|P2
argument_list|(
name|ref_packed
operator|*
argument_list|,
name|ref
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Advance to the next element in a packed array. */
end_comment

begin_define
define|#
directive|define
name|packed_next
parameter_list|(
name|packed
parameter_list|)
define|\
value|(*packed<= packed_max_full_ref ? packed + packed_per_ref : packed + 1)
end_define

end_unit

