begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: attr.h,v 5.5 91/07/18 12:57:51 hersh Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PHG_ATTR_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|PHG_ATTR_H_INCLUDED
end_define

begin_typedef
typedef|typedef
name|caddr_t
modifier|*
name|Phg_attr_avlist
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|Phg_attr_attribute
typedef|;
end_typedef

begin_comment
comment|/* 32 bit quantity */
end_comment

begin_comment
comment|/* Phg_attr_avlist is not an array of Phg_attr_attributes, because it is an array  * of intermixed attributes and values.  */
end_comment

begin_comment
comment|/* This macro is machine dependent in that it assumes  * the cardinality will be in the lower 5 bits of the type-cardinality  * pair.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_TYPE
parameter_list|(
name|base_type
parameter_list|,
name|cardinality
parameter_list|)
define|\
value|(((((unsigned)(base_type))& 0x07f)<< 5) |	\      (((unsigned)(cardinality))& 0x0f))
end_define

begin_comment
comment|/* Base types in the range PHG_ATTR_BASE_UNUSED_FIRST  * to PHG_ATTR_BASE_UNUSED_LAST are available for  * client use.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_BASE_UNUSED_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_BASE_UNUSED_LAST
value|31
end_define

begin_comment
comment|/* Base types 32 through 63 are  * reserved for future use.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_BASE_FIRST
value|64
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_BASE_INT
init|=
name|PHG_ATTR_BASE_FIRST
block|,
name|PHG_ATTR_BASE_INT_PAIR
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|1
block|,
name|PHG_ATTR_BASE_X
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|2
block|,
name|PHG_ATTR_BASE_INDEX_X
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|3
block|,
name|PHG_ATTR_BASE_Y
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|4
block|,
name|PHG_ATTR_BASE_INDEX_Y
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|5
block|,
name|PHG_ATTR_BASE_XY
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|6
block|,
name|PHG_ATTR_BASE_INDEX_XY
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|7
block|,
name|PHG_ATTR_BASE_BOOLEAN
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|8
block|,
name|PHG_ATTR_BASE_ENUM
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|9
block|,
name|PHG_ATTR_BASE_CHAR
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|10
block|,
name|PHG_ATTR_BASE_STRING
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|11
block|,
name|PHG_ATTR_BASE_RECT_PTR
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|15
block|,
name|PHG_ATTR_BASE_OPAQUE
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|16
block|,
name|PHG_ATTR_BASE_NO_VALUE
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|17
block|,
name|PHG_ATTR_BASE_AV
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|18
block|,
name|PHG_ATTR_BASE_FUNCTION_PTR
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|19
block|,
name|PHG_ATTR_BASE_ICON_PTR
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|20
block|,
name|PHG_ATTR_BASE_INT_TRIPLE
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|23
block|,
name|PHG_ATTR_BASE_LONG
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|24
block|,
name|PHG_ATTR_BASE_SHORT
init|=
name|PHG_ATTR_BASE_FIRST
operator|+
literal|25
block|}
name|Phg_attr_base_type
typedef|;
end_typedef

begin_comment
comment|/* Clients of the attribute value package should use  * Phg_attr_base_cardinality elements to define the base type  * and cardinality of their attributes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_INT
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INT
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_INT_PAIR
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INT_PAIR
argument_list|,
literal|2
argument_list|)
block|,
name|PHG_ATTR_INT_TRIPLE
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INT_TRIPLE
argument_list|,
literal|3
argument_list|)
block|,
name|PHG_ATTR_X
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_X
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_INDEX_X
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INDEX_X
argument_list|,
literal|2
argument_list|)
block|,
name|PHG_ATTR_Y
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_Y
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_INDEX_Y
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INDEX_Y
argument_list|,
literal|2
argument_list|)
block|,
name|PHG_ATTR_XY
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_XY
argument_list|,
literal|2
argument_list|)
block|,
name|PHG_ATTR_INDEX_XY
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_INDEX_XY
argument_list|,
literal|3
argument_list|)
block|,
name|PHG_ATTR_BOOLEAN
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_BOOLEAN
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_ENUM
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_ENUM
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_CHAR
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_CHAR
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_STRING
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_STRING
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_RECT_PTR
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_RECT_PTR
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_OPAQUE
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_OPAQUE
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_NO_VALUE
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_NO_VALUE
argument_list|,
literal|0
argument_list|)
block|,
name|PHG_ATTR_AV
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_AV
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_FUNCTION_PTR
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_FUNCTION_PTR
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_ICON_PTR
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_ICON_PTR
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_LONG
init|=
name|PHG_ATTR_TYPE
argument_list|(
name|PHG_ATTR_BASE_LONG
argument_list|,
literal|1
argument_list|)
block|,
name|PHG_ATTR_SHORT
init|=
name|PHG_ATTR_TYPE
argument_list|(
argument|PHG_ATTR_BASE_SHORT
argument_list|,
literal|1
argument_list|)
block|}
name|Phg_attr_base_cardinality
typedef|;
end_typedef

begin_comment
comment|/* Note that this macro is machine dependent in that it assumes the  * base_type-cardinality pair will be in the lower 13 bits of the   * list_type-base_cardinality pair.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_OF
parameter_list|(
name|list_type
parameter_list|,
name|list_ptr_type
parameter_list|,
name|base_cardinality
parameter_list|)
define|\
value|(((((unsigned)(list_type))& 0x3)<< 14) | \      (((unsigned)(list_ptr_type)& 0x1)<< 13) | \      (((unsigned)(base_cardinality))& 0x3fff))
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_LIST_IS_INLINE
init|=
literal|0
block|,
name|PHG_ATTR_LIST_IS_PTR
init|=
literal|1
block|}
name|Phg_attr_list_ptr_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_INLINE
parameter_list|(
name|list_type
parameter_list|,
name|base_cardinality
parameter_list|)
define|\
value|PHG_ATTR_LIST_OF(list_type, PHG_ATTR_LIST_IS_INLINE, base_cardinality)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_PTR
parameter_list|(
name|list_type
parameter_list|,
name|base_cardinality
parameter_list|)
define|\
value|PHG_ATTR_LIST_OF(list_type, PHG_ATTR_LIST_IS_PTR, base_cardinality)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* Note that PHG_ATTR_NONE must have a value of zero,      * since a no-list type is assumed for each of the      * types in Phg_attr_base_cardinality.      */
name|PHG_ATTR_NONE
init|=
literal|0
block|,
name|PHG_ATTR_RECURSIVE
init|=
literal|1
block|,
name|PHG_ATTR_NULL
init|=
literal|2
block|,
name|PHG_ATTR_COUNTED
init|=
literal|3
block|}
name|Phg_attr_list_type
typedef|;
end_typedef

begin_comment
comment|/*  * Note that 0 is NEVER a valid package id.  *  * The range from PHG_ATTR_PKG_UNUSED_FIRST to  * PHG_ATTR_PKG_UNUSED_LAST is reserved for non-Sun packages.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_PKG_UNUSED_FIRST
value|1
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_PKG_UNUSED_LAST
value|31
end_define

begin_comment
comment|/* 32 through 63 are reserved for   * future use.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_PKG_FIRST
value|64
end_define

begin_comment
comment|/* #define	PHG_ATTR_PKG_LAST		127 */
end_comment

begin_comment
comment|/* 128 through 255 are spare */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_PKG_ZERO
init|=
literal|0
block|,
name|PHG_ATTR_PKG_GENERIC
init|=
name|PHG_ATTR_PKG_FIRST
block|,
name|PHG_ATTR_PKG_LAST
init|=
name|PHG_ATTR_PKG_FIRST
operator|+
literal|18
block|}
name|Phg_attr_pkg
typedef|;
end_typedef

begin_comment
comment|/* Change PHG_ATTR_PKG_LAST to be EQUAL to the last legal pkg id. */
end_comment

begin_comment
comment|/* The procedure counter(), called by phg_attr_make, aborts if */
end_comment

begin_comment
comment|/* PKG_ID> PHG_ATTR_PKG_LAST */
end_comment

begin_comment
comment|/* PKG name should also be added to phg_attr_names[] in phg_attr.c */
end_comment

begin_comment
comment|/* An attribute is composed of   * pkg     ( 8 bits): id of package that uses the attribute  * ordinal ( 8 bits): ordinal number of the attribute  * type    (16 bits): list type, list pointer type, base type, and cardinality  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR
parameter_list|(
name|pkg
parameter_list|,
name|type
parameter_list|,
name|ordinal
parameter_list|)
define|\
value|( ((((unsigned)(pkg))& 0x7f)<< 24) | \       ((((unsigned)(ordinal))& 0xff)<< 16) | \        (((unsigned)(type))& 0xefef)	)
end_define

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|unsigned
name|pkg
range|:
literal|8
decl_stmt|;
name|unsigned
name|ordinal
range|:
literal|8
decl_stmt|;
name|unsigned
name|list_type
range|:
literal|2
decl_stmt|;
name|unsigned
name|list_ptr_type
range|:
literal|1
decl_stmt|;
name|unsigned
name|spare1
range|:
literal|1
decl_stmt|;
comment|/* unused */
name|unsigned
name|base_type
range|:
literal|7
decl_stmt|;
name|unsigned
name|spare2
range|:
literal|1
decl_stmt|;
comment|/* unused */
name|unsigned
name|cardinality
range|:
literal|4
decl_stmt|;
block|}
name|info
struct|;
name|Phg_attr_attribute
name|code
decl_stmt|;
block|}
name|Phg_attr_union
typedef|;
end_typedef

begin_comment
comment|/* Generic attributes  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_LIST
init|=
name|PHG_ATTR
argument_list|(
argument|PHG_ATTR_PKG_GENERIC
argument_list|,
argument|PHG_ATTR_LIST_PTR(PHG_ATTR_RECURSIVE, PHG_ATTR_NO_VALUE)
argument_list|,
literal|0
argument_list|)
block|}
name|Phg_attr_generic
typedef|;
end_typedef

begin_comment
comment|/* PHG_ATTR_STANDARD_SIZE is large enough to allow for   * most attribute-value lists.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_STANDARD_SIZE
value|250
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/* Note that in these macros, attr must not be   * in a register or be a constant.  * Since this is deemed too restrictive, we use  * shifting& masking instead.    */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_UNION
parameter_list|(
name|attr
parameter_list|)
value|((Phg_attr_union *)&((Phg_attr_attribute) (attr)))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_INFO
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_UNION(attr)->info)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CODE
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_UNION(attr)->code)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_TYPE
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).list_type)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_PTR_TYPE
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).list_ptr_type)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_BASE_TYPE
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).base_type)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CARDINALITY
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).cardinality)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_PKG
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).pkg)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_ORDINAL
parameter_list|(
name|attr
parameter_list|)
value|(PHG_ATTR_INFO(attr).ordinal)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notdef */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_CODE
parameter_list|(
name|attr
parameter_list|)
value|((unsigned)(attr))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_PKG
parameter_list|(
name|attr
parameter_list|)
define|\
value|((Phg_attr_pkg) ((PHG_ATTR_CODE(attr)>> 24)& 0xFF))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_VALID_PKG_ID
parameter_list|(
name|attr
parameter_list|)
define|\
value|(((int)PHG_ATTR_PKG(attr))> ((int) PHG_ATTR_PKG_ZERO)&& \ 	 ((int)PHG_ATTR_PKG(attr))<= ((int)PHG_ATTR_PKG_LAST))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_ORDINAL
parameter_list|(
name|attr
parameter_list|)
define|\
value|((unsigned) ((PHG_ATTR_CODE(attr)>> 16)& 0xFF))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_TYPE
parameter_list|(
name|attr
parameter_list|)
define|\
value|((Phg_attr_list_type) ((PHG_ATTR_CODE(attr)>> 14)& 0x3))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LIST_PTR_TYPE
parameter_list|(
name|attr
parameter_list|)
define|\
value|((Phg_attr_list_ptr_type) ((PHG_ATTR_CODE(attr)>> 13)& 0x1))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_BASE_TYPE
parameter_list|(
name|attr
parameter_list|)
define|\
value|((Phg_attr_base_type) ((PHG_ATTR_CODE(attr)>> 5)& 0x7F))
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CARDINALITY
parameter_list|(
name|attr
parameter_list|)
define|\
value|((unsigned) (PHG_ATTR_CODE(attr)& 0xF))
end_define

begin_comment
comment|/* Character unit support */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* The following #ifndef fixes kernel lint warnings, but is pretty strange */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_function_decl
specifier|extern
name|void
name|phg_attr_replace_cu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|phg_attr_cu_to_x
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|phg_attr_cu_to_y
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* lint */
end_comment

begin_define
define|#
directive|define
name|phg_attr_replace_cu
parameter_list|(
name|avlist
parameter_list|,
name|font
parameter_list|,
name|lmargin
parameter_list|,
name|tmargin
parameter_list|,
name|rgap
parameter_list|)
define|\
value|phg_attr_rc_units_to_pixels(avlist, font->pf_defaultsize.x, \ 	font->pf_defaultsize.y, lmargin, tmargin, 0, rgap)
end_define

begin_define
define|#
directive|define
name|phg_attr_cu_to_x
parameter_list|(
name|encoded_value
parameter_list|,
name|font
parameter_list|,
name|left_margin
parameter_list|)
define|\
value|phg_attr_rc_unit_to_x(encoded_value, font->pf_defaultsize.x, left_margin, 0)
end_define

begin_define
define|#
directive|define
name|phg_attr_cu_to_y
parameter_list|(
name|encoded_value
parameter_list|,
name|font
parameter_list|,
name|top_margin
parameter_list|,
name|row_gap
parameter_list|)
define|\
value|phg_attr_rc_unit_to_y(encoded_value, font->pf_defaultsize.y, top_margin, row_gap)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHG_ATTR_CU_POSITION
init|=
literal|0x0
block|,
comment|/* bit 29 is off */
name|PHG_ATTR_CU_LENGTH
init|=
literal|0x20000000
comment|/* bit 29 is on */
block|}
name|Phg_attr_cu_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PHG_ATTR_CU_TAG
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_PIXEL_OFFSET
value|0x00008000
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CU
parameter_list|(
name|unit
parameter_list|,
name|n
parameter_list|)
define|\
value|(((unsigned)(unit)) | (((unsigned)(n)& 0x1FFF)<< 16) |	\     PHG_ATTR_CU_TAG | PHG_ATTR_PIXEL_OFFSET)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CU_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CU_TYPE
parameter_list|(
name|n
parameter_list|)
define|\
value|((Phg_attr_cu_type) ((n)& (unsigned) (PHG_ATTR_CU_LENGTH)))
end_define

begin_comment
comment|/* phg_attr_is_cu(n) returns non-zero if n has   * been encoded using PHG_ATTR_CU()  */
end_comment

begin_define
define|#
directive|define
name|phg_attr_is_cu
parameter_list|(
name|n
parameter_list|)
value|(((n)& PHG_ATTR_CU_MASK) == PHG_ATTR_CU_TAG)
end_define

begin_comment
comment|/* Macros for position including  * margins.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_COL
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_POSITION, n)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_ROW
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_POSITION, n)
end_define

begin_comment
comment|/* Macros for length excluding  * margins.  */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_COLS
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_LENGTH, n)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_ROWS
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_LENGTH, n)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CHARS
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_LENGTH, n)
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_LINES
parameter_list|(
name|n
parameter_list|)
value|PHG_ATTR_CU(PHG_ATTR_CU_LENGTH, n)
end_define

begin_comment
comment|/* phg_attr_make() is not interested in the  * count from phg_attr_make_count().  */
end_comment

begin_define
define|#
directive|define
name|phg_attr_make
parameter_list|(
name|array
parameter_list|,
name|max_size
parameter_list|,
name|argv
parameter_list|)
define|\
value|phg_attr_make_count(array, max_size, argv, (int *)0)
end_define

begin_comment
comment|/* Following are useful for multi-pass avlist processing. */
end_comment

begin_define
define|#
directive|define
name|PHG_ATTR_NOP
parameter_list|(
name|attr
parameter_list|)
define|\
value|( (((unsigned)PHG_ATTR_PKG_NOP)<< 24) | (PHG_ATTR_CODE(attr)& 0xffffff) )
end_define

begin_define
define|#
directive|define
name|PHG_ATTR_CONSUME
parameter_list|(
name|attr
parameter_list|)
value|(attr) = ((caddr_t)PHG_ATTR_NOP(attr))
end_define

begin_define
define|#
directive|define
name|phg_attr_skip
parameter_list|(
name|attr
parameter_list|,
name|argv
parameter_list|)
define|\
value|((PHG_ATTR_LIST_TYPE((attr)) == PHG_ATTR_NONE) \ 	? (argv) + PHG_ATTR_CARDINALITY((attr)) \ 	: ((Phg_attr_avlist)phg_attr_skip_value((Phg_attr_attribute)(attr), (argv))))
end_define

begin_define
define|#
directive|define
name|phg_attr_next
parameter_list|(
name|attrs
parameter_list|)
value|phg_attr_skip((*(attrs)), ((attrs)+1))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_comment
comment|/* Available functions  */
end_comment

begin_function_decl
specifier|extern
name|Phg_attr_avlist
name|phg_attr_create_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Phg_attr_avlist
name|phg_attr_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Phg_attr_avlist
name|phg_attr_make_count
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|phg_attr_copy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|phg_attr_count
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|phg_attr_sprint
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|phg_attr_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Phg_attr_avlist
name|phg_attr_skip_value
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

