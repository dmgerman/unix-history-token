begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *   Character mapping generated 04/29/11 15:43:58  *  *  This file contains the character classifications  *  used by AutoGen and AutoOpts for identifying tokens.  *  This file is part of AutoGen.  *  AutoGen Copyright (c) 1992-2011 by Bruce Korb - all rights reserved  *  AutoGen is free software: you can redistribute it and/or modify it under the  *  terms of the GNU General Public License as published by the Free Software  *  Foundation, either version 3 of the License, or (at your option) any later  *  version.  *  AutoGen is distributed in the hope that it will be useful, but WITHOUT ANY  *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR  *  A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  *  You should have received a copy of the GNU General Public License along  *  with this program.  If not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AG_CHAR_MAP_H_GUARD
end_ifndef

begin_define
define|#
directive|define
name|AG_CHAR_MAP_H_GUARD
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_INTTYPES_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT8_T
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT8_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT16_T
end_ifndef

begin_typedef
typedef|typedef
name|signed
name|short
name|int16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT16_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INT32_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_INT
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|signed
name|int
name|int32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|signed
name|long
name|int32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINT32_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_INT
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uint32_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_*INT*_H header */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not HAVE_CONFIG_H -- */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__sun
end_ifdef

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* mapping specification source (from autogen.map) */
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// %guard          autoopts_internal
end_comment

begin_comment
comment|// %file           ag-char-map.h
end_comment

begin_comment
comment|// %static-table   option-char-category
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// %comment
end_comment

begin_comment
comment|//   This file contains the character classifications
end_comment

begin_comment
comment|//   used by AutoGen and AutoOpts for identifying tokens.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   This file is part of AutoGen.
end_comment

begin_comment
comment|//   AutoGen Copyright (c) 1992-2011 by Bruce Korb - all rights reserved
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   AutoGen is free software: you can redistribute it and/or modify it under the
end_comment

begin_comment
comment|//   terms of the GNU General Public License as published by the Free Software
end_comment

begin_comment
comment|//   Foundation, either version 3 of the License, or (at your option) any later
end_comment

begin_comment
comment|//   version.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   AutoGen is distributed in the hope that it will be useful, but WITHOUT ANY
end_comment

begin_comment
comment|//   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
end_comment

begin_comment
comment|//   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   You should have received a copy of the GNU General Public License along
end_comment

begin_comment
comment|//   with this program.  If not, see<http://www.gnu.org/licenses/>.
end_comment

begin_comment
comment|// %
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// lower-case      "a-z"
end_comment

begin_comment
comment|// upper-case      "A-Z"
end_comment

begin_comment
comment|// alphabetic      +lower-case   +upper-case
end_comment

begin_comment
comment|// oct-digit       "0-7"
end_comment

begin_comment
comment|// dec-digit       "89"          +oct-digit
end_comment

begin_comment
comment|// hex-digit       "a-fA-F"      +dec-digit
end_comment

begin_comment
comment|// alphanumeric    +alphabetic   +dec-digit
end_comment

begin_comment
comment|// var-first       "_"           +alphabetic
end_comment

begin_comment
comment|// variable-name   +var-first    +dec-digit
end_comment

begin_comment
comment|// option-name     "^-"          +variable-name
end_comment

begin_comment
comment|// value-name      ":"           +option-name
end_comment

begin_comment
comment|// horiz-white     "\t "
end_comment

begin_comment
comment|// compound-name   "[.]"         +value-name   +horiz-white
end_comment

begin_comment
comment|// whitespace      "\v\f\r\n\b"  +horiz-white
end_comment

begin_comment
comment|// unquotable      "!-~"         -"\"#(),;<=>[\\]`{}?*'"
end_comment

begin_comment
comment|// end-xml-token   "/>"          +whitespace
end_comment

begin_comment
comment|// graphic         "!-~"
end_comment

begin_comment
comment|// plus-n-space    "+"           +whitespace
end_comment

begin_comment
comment|// punctuation     "!-~"         -alphanumeric -"_"
end_comment

begin_comment
comment|// suffix          "-._"         +alphanumeric
end_comment

begin_comment
comment|// suffix-fmt      "%/"          +suffix
end_comment

begin_comment
comment|// false-type      "nNfF0\x00"
end_comment

begin_comment
comment|// file-name       "/"           +suffix
end_comment

begin_comment
comment|// end-token       "\x00"        +whitespace
end_comment

begin_comment
comment|// end-list-entry  ","           +end-token
end_comment

begin_comment
comment|//
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 -- mapping spec. source */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|option_char_category_mask_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|option_char_category_mask_t
specifier|const
name|option_char_category
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|int
name|is_option_char_category_char
parameter_list|(
name|char
name|ch
parameter_list|,
name|option_char_category_mask_t
name|mask
parameter_list|)
block|{
name|unsigned
name|int
name|ix
init|=
operator|(
name|unsigned
name|char
operator|)
name|ch
decl_stmt|;
return|return
operator|(
operator|(
name|ix
operator|<
literal|128
operator|)
operator|&&
operator|(
operator|(
name|option_char_category
index|[
name|ix
index|]
operator|&
name|mask
operator|)
operator|!=
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|IS_LOWER_CASE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000001)
end_define

begin_define
define|#
directive|define
name|IS_UPPER_CASE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000002)
end_define

begin_define
define|#
directive|define
name|IS_ALPHABETIC_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000003)
end_define

begin_define
define|#
directive|define
name|IS_OCT_DIGIT_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000004)
end_define

begin_define
define|#
directive|define
name|IS_DEC_DIGIT_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x00000C)
end_define

begin_define
define|#
directive|define
name|IS_HEX_DIGIT_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x00001C)
end_define

begin_define
define|#
directive|define
name|IS_ALPHANUMERIC_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x00000F)
end_define

begin_define
define|#
directive|define
name|IS_VAR_FIRST_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000023)
end_define

begin_define
define|#
directive|define
name|IS_VARIABLE_NAME_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x00002F)
end_define

begin_define
define|#
directive|define
name|IS_OPTION_NAME_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x00006F)
end_define

begin_define
define|#
directive|define
name|IS_VALUE_NAME_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x0000EF)
end_define

begin_define
define|#
directive|define
name|IS_HORIZ_WHITE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000100)
end_define

begin_define
define|#
directive|define
name|IS_COMPOUND_NAME_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x0003EF)
end_define

begin_define
define|#
directive|define
name|IS_WHITESPACE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000500)
end_define

begin_define
define|#
directive|define
name|IS_UNQUOTABLE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x000800)
end_define

begin_define
define|#
directive|define
name|IS_END_XML_TOKEN_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x001500)
end_define

begin_define
define|#
directive|define
name|IS_GRAPHIC_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x002000)
end_define

begin_define
define|#
directive|define
name|IS_PLUS_N_SPACE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x004500)
end_define

begin_define
define|#
directive|define
name|IS_PUNCTUATION_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x008000)
end_define

begin_define
define|#
directive|define
name|IS_SUFFIX_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x01000F)
end_define

begin_define
define|#
directive|define
name|IS_SUFFIX_FMT_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x03000F)
end_define

begin_define
define|#
directive|define
name|IS_FALSE_TYPE_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x040000)
end_define

begin_define
define|#
directive|define
name|IS_FILE_NAME_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x09000F)
end_define

begin_define
define|#
directive|define
name|IS_END_TOKEN_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x100500)
end_define

begin_define
define|#
directive|define
name|IS_END_LIST_ENTRY_CHAR
parameter_list|(
name|_c
parameter_list|)
value|is_option_char_category_char((_c), 0x300500)
end_define

begin_if
if|#
directive|if
literal|1
end_if

begin_comment
comment|/* def AUTOOPTS_INTERNAL */
end_comment

begin_decl_stmt
specifier|static
name|option_char_category_mask_t
specifier|const
name|option_char_category
index|[
literal|128
index|]
init|=
block|{
comment|/*x00*/
literal|0x140000
block|,
comment|/*x01*/
literal|0x000000
block|,
comment|/*x02*/
literal|0x000000
block|,
comment|/*x03*/
literal|0x000000
block|,
comment|/*x04*/
literal|0x000000
block|,
comment|/*x05*/
literal|0x000000
block|,
comment|/*x06*/
literal|0x000000
block|,
comment|/*\a */
literal|0x000000
block|,
comment|/*\b */
literal|0x000400
block|,
comment|/*\t */
literal|0x000100
block|,
comment|/*\n */
literal|0x000400
block|,
comment|/*\v */
literal|0x000400
block|,
comment|/*\f */
literal|0x000400
block|,
comment|/*\r */
literal|0x000400
block|,
comment|/*x0E*/
literal|0x000000
block|,
comment|/*x0F*/
literal|0x000000
block|,
comment|/*x10*/
literal|0x000000
block|,
comment|/*x11*/
literal|0x000000
block|,
comment|/*x12*/
literal|0x000000
block|,
comment|/*x13*/
literal|0x000000
block|,
comment|/*x14*/
literal|0x000000
block|,
comment|/*x15*/
literal|0x000000
block|,
comment|/*x16*/
literal|0x000000
block|,
comment|/*x17*/
literal|0x000000
block|,
comment|/*x18*/
literal|0x000000
block|,
comment|/*x19*/
literal|0x000000
block|,
comment|/*x1A*/
literal|0x000000
block|,
comment|/*x1B*/
literal|0x000000
block|,
comment|/*x1C*/
literal|0x000000
block|,
comment|/*x1D*/
literal|0x000000
block|,
comment|/*x1E*/
literal|0x000000
block|,
comment|/*x1F*/
literal|0x000000
block|,
comment|/*   */
literal|0x000100
block|,
comment|/* ! */
literal|0x00A800
block|,
comment|/* " */
literal|0x00A000
block|,
comment|/* # */
literal|0x00A000
block|,
comment|/* $ */
literal|0x00A800
block|,
comment|/* % */
literal|0x02A800
block|,
comment|/*& */
literal|0x00A800
block|,
comment|/* ' */
literal|0x00A000
block|,
comment|/* ( */
literal|0x00A000
block|,
comment|/* ) */
literal|0x00A000
block|,
comment|/* * */
literal|0x00A000
block|,
comment|/* + */
literal|0x00E800
block|,
comment|/* , */
literal|0x20A000
block|,
comment|/* - */
literal|0x01A840
block|,
comment|/* . */
literal|0x01AA00
block|,
comment|/* / */
literal|0x0AB800
block|,
comment|/* 0 */
literal|0x042804
block|,
comment|/* 1 */
literal|0x002804
block|,
comment|/* 2 */
literal|0x002804
block|,
comment|/* 3 */
literal|0x002804
block|,
comment|/* 4 */
literal|0x002804
block|,
comment|/* 5 */
literal|0x002804
block|,
comment|/* 6 */
literal|0x002804
block|,
comment|/* 7 */
literal|0x002804
block|,
comment|/* 8 */
literal|0x002808
block|,
comment|/* 9 */
literal|0x002808
block|,
comment|/* : */
literal|0x00A880
block|,
comment|/* ; */
literal|0x00A000
block|,
comment|/*< */
literal|0x00A000
block|,
comment|/* = */
literal|0x00A000
block|,
comment|/*> */
literal|0x00B000
block|,
comment|/* ? */
literal|0x00A000
block|,
comment|/* @ */
literal|0x00A800
block|,
comment|/* A */
literal|0x002812
block|,
comment|/* B */
literal|0x002812
block|,
comment|/* C */
literal|0x002812
block|,
comment|/* D */
literal|0x002812
block|,
comment|/* E */
literal|0x002812
block|,
comment|/* F */
literal|0x042812
block|,
comment|/* G */
literal|0x002802
block|,
comment|/* H */
literal|0x002802
block|,
comment|/* I */
literal|0x002802
block|,
comment|/* J */
literal|0x002802
block|,
comment|/* K */
literal|0x002802
block|,
comment|/* L */
literal|0x002802
block|,
comment|/* M */
literal|0x002802
block|,
comment|/* N */
literal|0x042802
block|,
comment|/* O */
literal|0x002802
block|,
comment|/* P */
literal|0x002802
block|,
comment|/* Q */
literal|0x002802
block|,
comment|/* R */
literal|0x002802
block|,
comment|/* S */
literal|0x002802
block|,
comment|/* T */
literal|0x002802
block|,
comment|/* U */
literal|0x002802
block|,
comment|/* V */
literal|0x002802
block|,
comment|/* W */
literal|0x002802
block|,
comment|/* X */
literal|0x002802
block|,
comment|/* Y */
literal|0x002802
block|,
comment|/* Z */
literal|0x002802
block|,
comment|/* [ */
literal|0x00A200
block|,
comment|/* \ */
literal|0x00A000
block|,
comment|/* ] */
literal|0x00A200
block|,
comment|/* ^ */
literal|0x00A840
block|,
comment|/* _ */
literal|0x012820
block|,
comment|/* ` */
literal|0x00A000
block|,
comment|/* a */
literal|0x002811
block|,
comment|/* b */
literal|0x002811
block|,
comment|/* c */
literal|0x002811
block|,
comment|/* d */
literal|0x002811
block|,
comment|/* e */
literal|0x002811
block|,
comment|/* f */
literal|0x042811
block|,
comment|/* g */
literal|0x002801
block|,
comment|/* h */
literal|0x002801
block|,
comment|/* i */
literal|0x002801
block|,
comment|/* j */
literal|0x002801
block|,
comment|/* k */
literal|0x002801
block|,
comment|/* l */
literal|0x002801
block|,
comment|/* m */
literal|0x002801
block|,
comment|/* n */
literal|0x042801
block|,
comment|/* o */
literal|0x002801
block|,
comment|/* p */
literal|0x002801
block|,
comment|/* q */
literal|0x002801
block|,
comment|/* r */
literal|0x002801
block|,
comment|/* s */
literal|0x002801
block|,
comment|/* t */
literal|0x002801
block|,
comment|/* u */
literal|0x002801
block|,
comment|/* v */
literal|0x002801
block|,
comment|/* w */
literal|0x002801
block|,
comment|/* x */
literal|0x002801
block|,
comment|/* y */
literal|0x002801
block|,
comment|/* z */
literal|0x002801
block|,
comment|/* { */
literal|0x00A000
block|,
comment|/* | */
literal|0x00A800
block|,
comment|/* } */
literal|0x00A000
block|,
comment|/* ~ */
literal|0x00A800
block|,
comment|/*x7F*/
literal|0x000000
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTOOPTS_INTERNAL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AG_CHAR_MAP_H_GUARD */
end_comment

end_unit

