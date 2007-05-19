begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operations with long integers.    Copyright (C) 2006 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_INT_H
end_ifndef

begin_define
define|#
directive|define
name|DOUBLE_INT_H
end_define

begin_comment
comment|/* A large integer is currently represented as a pair of HOST_WIDE_INTs.    It therefore represents a number with precision of    2 * HOST_BITS_PER_WIDE_INT bits (it is however possible that the    internal representation will change, if numbers with greater precision    are needed, so the users should not rely on it).  The representation does    not contain any information about signedness of the represented value, so    it can be used to represent both signed and unsigned numbers.  For    operations where the results depend on signedness (division, comparisons),    it must be specified separately.  For each such operation, there are three    versions of the function -- double_int_op, that takes an extra UNS argument    giving the signedness of the values, and double_int_sop and double_int_uop    that stand for its specializations for signed and unsigned values.     You may also represent with numbers in smaller precision using double_int.    You however need to use double_int_ext (that fills in the bits of the    number over the prescribed precision with zeros or with the sign bit) before    operations that do not perform arithmetics modulo 2^precision (comparisons,    division), and possibly before storing the results, if you want to keep    them in some canonical form).  In general, the signedness of double_int_ext    should match the signedness of the operation.     ??? The components of double_int differ in signedness mostly for    historical reasons (they replace an older structure used to represent    numbers with precision higher than HOST_WIDE_INT).  It might be less    confusing to have them both signed or both unsigned.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|HOST_WIDE_INT
name|low
decl_stmt|;
name|HOST_WIDE_INT
name|high
decl_stmt|;
block|}
name|double_int
typedef|;
end_typedef

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_comment
comment|/* Constructors and conversions.  */
end_comment

begin_function_decl
name|union
name|tree_node
modifier|*
name|double_int_to_tree
parameter_list|(
name|union
name|tree_node
modifier|*
parameter_list|,
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|tree_to_double_int
parameter_list|(
name|union
name|tree_node
modifier|*
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Constructs double_int from integer CST.  The bits over the precision of    HOST_WIDE_INT are filled with the sign bit.  */
end_comment

begin_function
specifier|static
specifier|inline
name|double_int
name|shwi_to_double_int
parameter_list|(
name|HOST_WIDE_INT
name|cst
parameter_list|)
block|{
name|double_int
name|r
decl_stmt|;
name|r
operator|.
name|low
operator|=
operator|(
name|unsigned
name|HOST_WIDE_INT
operator|)
name|cst
expr_stmt|;
name|r
operator|.
name|high
operator|=
name|cst
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|0
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|/* Some useful constants.  */
end_comment

begin_define
define|#
directive|define
name|double_int_minus_one
value|(shwi_to_double_int (-1))
end_define

begin_define
define|#
directive|define
name|double_int_zero
value|(shwi_to_double_int (0))
end_define

begin_define
define|#
directive|define
name|double_int_one
value|(shwi_to_double_int (1))
end_define

begin_define
define|#
directive|define
name|double_int_two
value|(shwi_to_double_int (2))
end_define

begin_define
define|#
directive|define
name|double_int_ten
value|(shwi_to_double_int (10))
end_define

begin_comment
comment|/* Constructs double_int from unsigned integer CST.  The bits over the    precision of HOST_WIDE_INT are filled with zeros.  */
end_comment

begin_function
specifier|static
specifier|inline
name|double_int
name|uhwi_to_double_int
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
name|cst
parameter_list|)
block|{
name|double_int
name|r
decl_stmt|;
name|r
operator|.
name|low
operator|=
name|cst
expr_stmt|;
name|r
operator|.
name|high
operator|=
literal|0
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_comment
comment|/* The following operations perform arithmetics modulo 2^precision,    so you do not need to call double_int_ext between them, even if    you are representing numbers with precision less than    2 * HOST_BITS_PER_WIDE_INT bits.  */
end_comment

begin_function_decl
name|double_int
name|double_int_mul
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_add
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_neg
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* You must ensure that double_int_ext is called on the operands    of the following operations, if the precision of the numbers    is less than 2 * HOST_BITS_PER_WIDE_INT bits.  */
end_comment

begin_function_decl
name|bool
name|double_int_fits_in_hwi_p
parameter_list|(
name|double_int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|double_int_fits_in_shwi_p
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|double_int_fits_in_uhwi_p
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HOST_WIDE_INT
name|double_int_to_shwi
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|HOST_WIDE_INT
name|double_int_to_uhwi
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_div
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_sdiv
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_udiv
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_mod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_smod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_umod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_divmod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|bool
parameter_list|,
name|unsigned
parameter_list|,
name|double_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_sdivmod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|,
name|double_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_udivmod
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|unsigned
parameter_list|,
name|double_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|double_int_negative_p
parameter_list|(
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|double_int_cmp
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|double_int_scmp
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|double_int_ucmp
parameter_list|(
name|double_int
parameter_list|,
name|double_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dump_double_int
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|double_int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Zero and sign extension of numbers in smaller precisions.  */
end_comment

begin_function_decl
name|double_int
name|double_int_ext
parameter_list|(
name|double_int
parameter_list|,
name|unsigned
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_sext
parameter_list|(
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double_int
name|double_int_zext
parameter_list|(
name|double_int
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ALL_ONES
value|(~((unsigned HOST_WIDE_INT) 0))
end_define

begin_comment
comment|/* The operands of the following comparison functions must be processed    with double_int_ext, if their precision is less than    2 * HOST_BITS_PER_WIDE_INT bits.  */
end_comment

begin_comment
comment|/* Returns true if CST is zero.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|double_int_zero_p
parameter_list|(
name|double_int
name|cst
parameter_list|)
block|{
return|return
name|cst
operator|.
name|low
operator|==
literal|0
operator|&&
name|cst
operator|.
name|high
operator|==
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Returns true if CST is one.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|double_int_one_p
parameter_list|(
name|double_int
name|cst
parameter_list|)
block|{
return|return
name|cst
operator|.
name|low
operator|==
literal|1
operator|&&
name|cst
operator|.
name|high
operator|==
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Returns true if CST is minus one.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|double_int_minus_one_p
parameter_list|(
name|double_int
name|cst
parameter_list|)
block|{
return|return
operator|(
name|cst
operator|.
name|low
operator|==
name|ALL_ONES
operator|&&
name|cst
operator|.
name|high
operator|==
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Returns true if CST1 == CST2.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|double_int_equal_p
parameter_list|(
name|double_int
name|cst1
parameter_list|,
name|double_int
name|cst2
parameter_list|)
block|{
return|return
name|cst1
operator|.
name|low
operator|==
name|cst2
operator|.
name|low
operator|&&
name|cst1
operator|.
name|high
operator|==
name|cst2
operator|.
name|high
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DOUBLE_INT_H */
end_comment

end_unit

