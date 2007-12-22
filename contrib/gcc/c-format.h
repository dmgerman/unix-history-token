begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Check calls to formatted I/O functions (-Wformat).    Copyright (C) 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_C_FORMAT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_C_FORMAT_H
end_define

begin_comment
comment|/* The meaningfully distinct length modifiers for format checking recognized    by GCC.  */
end_comment

begin_enum
enum|enum
name|format_lengths
block|{
name|FMT_LEN_none
block|,
name|FMT_LEN_hh
block|,
name|FMT_LEN_h
block|,
name|FMT_LEN_l
block|,
name|FMT_LEN_ll
block|,
name|FMT_LEN_L
block|,
name|FMT_LEN_z
block|,
name|FMT_LEN_t
block|,
name|FMT_LEN_j
block|,
name|FMT_LEN_H
block|,
name|FMT_LEN_D
block|,
name|FMT_LEN_DD
block|,
name|FMT_LEN_MAX
block|}
enum|;
end_enum

begin_comment
comment|/* The standard versions in which various format features appeared.  */
end_comment

begin_enum
enum|enum
name|format_std_version
block|{
name|STD_C89
block|,
name|STD_C94
block|,
name|STD_C9L
block|,
comment|/* C99, but treat as C89 if -Wno-long-long.  */
name|STD_C99
block|,
name|STD_EXT
block|}
enum|;
end_enum

begin_comment
comment|/* Flags that may apply to a particular kind of format checked by GCC.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* This format converts arguments of types determined by the      format string.  */
name|FMT_FLAG_ARG_CONVERT
init|=
literal|1
block|,
comment|/* The scanf allocation 'a' kludge applies to this format kind.  */
name|FMT_FLAG_SCANF_A_KLUDGE
init|=
literal|2
block|,
comment|/* A % during parsing a specifier is allowed to be a modified % rather      that indicating the format is broken and we are out-of-sync.  */
name|FMT_FLAG_FANCY_PERCENT_OK
init|=
literal|4
block|,
comment|/* With $ operand numbers, it is OK to reference the same argument more      than once.  */
name|FMT_FLAG_DOLLAR_MULTIPLE
init|=
literal|8
block|,
comment|/* This format type uses $ operand numbers (strfmon doesn't).  */
name|FMT_FLAG_USE_DOLLAR
init|=
literal|16
block|,
comment|/* Zero width is bad in this type of format (scanf).  */
name|FMT_FLAG_ZERO_WIDTH_BAD
init|=
literal|32
block|,
comment|/* Empty precision specification is OK in this type of format (printf).  */
name|FMT_FLAG_EMPTY_PREC_OK
init|=
literal|64
block|,
comment|/* Gaps are allowed in the arguments with $ operand numbers if all      arguments are pointers (scanf).  */
name|FMT_FLAG_DOLLAR_GAP_POINTER_OK
init|=
literal|128
block|,
comment|/* Not included here: details of whether width or precision may occur      (controlled by width_char and precision_char); details of whether      '*' can be used for these (width_type and precision_type); details      of whether length modifiers can occur (length_char_specs).  */
name|FMT_FLAG_NULL_FORMAT_OK
init|=
literal|256
block|}
enum|;
end_enum

begin_comment
comment|/* Structure describing a length modifier supported in format checking, and    possibly a doubled version such as "hh".  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Name of the single-character length modifier.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Index into a format_char_info.types array.  */
name|enum
name|format_lengths
name|index
decl_stmt|;
comment|/* Standard version this length appears in.  */
name|enum
name|format_std_version
name|std
decl_stmt|;
comment|/* Same, if the modifier can be repeated, or NULL if it can't.  */
specifier|const
name|char
modifier|*
name|double_name
decl_stmt|;
name|enum
name|format_lengths
name|double_index
decl_stmt|;
name|enum
name|format_std_version
name|double_std
decl_stmt|;
block|}
name|format_length_info
typedef|;
end_typedef

begin_comment
comment|/* Structure describing the combination of a conversion specifier    (or a set of specifiers which act identically) and a length modifier.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The standard version this combination of length and type appeared in.      This is only relevant if greater than those for length and type      individually; otherwise it is ignored.  */
name|enum
name|format_std_version
name|std
decl_stmt|;
comment|/* The name to use for the type, if different from that generated internally      (e.g., "signed size_t").  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* The type itself.  */
name|tree
modifier|*
name|type
decl_stmt|;
block|}
name|format_type_detail
typedef|;
end_typedef

begin_comment
comment|/* Macros to fill out tables of these.  */
end_comment

begin_define
define|#
directive|define
name|NOARGUMENTS
value|{ T89_V, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN }
end_define

begin_define
define|#
directive|define
name|BADLEN
value|{ 0, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|NOLENGTHS
value|{ BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN, BADLEN }
end_define

begin_comment
comment|/* Structure describing a format conversion specifier (or a set of specifiers    which act identically), and the length modifiers used with it.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|format_char_info
block|{
specifier|const
name|char
modifier|*
name|format_chars
decl_stmt|;
name|int
name|pointer_count
decl_stmt|;
name|enum
name|format_std_version
name|std
decl_stmt|;
comment|/* Types accepted for each length modifier.  */
name|format_type_detail
name|types
index|[
name|FMT_LEN_MAX
index|]
decl_stmt|;
comment|/* List of other modifier characters allowed with these specifiers.      This lists flags, and additionally "w" for width, "p" for precision      (right precision, for strfmon), "#" for left precision (strfmon),      "a" for scanf "a" allocation extension (not applicable in C99 mode),      "*" for scanf suppression, and "E" and "O" for those strftime      modifiers.  */
specifier|const
name|char
modifier|*
name|flag_chars
decl_stmt|;
comment|/* List of additional flags describing these conversion specifiers.      "c" for generic character pointers being allowed, "2" for strftime      two digit year formats, "3" for strftime formats giving two digit      years in some locales, "4" for "2" which becomes "3" with an "E" modifier,      "o" if use of strftime "O" is a GNU extension beyond C99,      "W" if the argument is a pointer which is dereferenced and written into,      "R" if the argument is a pointer which is dereferenced and read from,      "i" for printf integer formats where the '0' flag is ignored with      precision, and "[" for the starting character of a scanf scanset.  */
specifier|const
name|char
modifier|*
name|flags2
decl_stmt|;
comment|/* If this format conversion character consumes more than one argument,      CHAIN points to information about the next argument.  For later      arguments, only POINTER_COUNT, TYPES, and the "c", "R", and "W" flags      in FLAGS2 are used.  */
specifier|const
name|struct
name|format_char_info
modifier|*
name|chain
decl_stmt|;
block|}
name|format_char_info
typedef|;
end_typedef

begin_comment
comment|/* Structure describing a flag accepted by some kind of format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The flag character in question (0 for end of array).  */
name|int
name|flag_char
decl_stmt|;
comment|/* Zero if this entry describes the flag character in general, or a      nonzero character that may be found in flags2 if it describes the      flag when used with certain formats only.  If the latter, only      the first such entry found that applies to the current conversion      specifier is used; the values of 'name' and 'long_name' it supplies      will be used, if non-NULL and the standard version is higher than      the unpredicated one, for any pedantic warning.  For example, 'o'      for strftime formats (meaning 'O' is an extension over C99).  */
name|int
name|predicate
decl_stmt|;
comment|/* Nonzero if the next character after this flag in the format should      be skipped ('=' in strfmon), zero otherwise.  */
name|int
name|skip_next_char
decl_stmt|;
comment|/* The name to use for this flag in diagnostic messages.  For example,      N_("'0' flag"), N_("field width").  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Long name for this flag in diagnostic messages; currently only used for      "ISO C does not support ...".  For example, N_("the 'I' printf flag").  */
specifier|const
name|char
modifier|*
name|long_name
decl_stmt|;
comment|/* The standard version in which it appeared.  */
name|enum
name|format_std_version
name|std
decl_stmt|;
block|}
name|format_flag_spec
typedef|;
end_typedef

begin_comment
comment|/* Structure describing a combination of flags that is bad for some kind    of format.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The first flag character in question (0 for end of array).  */
name|int
name|flag_char1
decl_stmt|;
comment|/* The second flag character.  */
name|int
name|flag_char2
decl_stmt|;
comment|/* Nonzero if the message should say that the first flag is ignored with      the second, zero if the combination should simply be objected to.  */
name|int
name|ignored
decl_stmt|;
comment|/* Zero if this entry applies whenever this flag combination occurs,      a nonzero character from flags2 if it only applies in some      circumstances (e.g. 'i' for printf formats ignoring 0 with precision).  */
name|int
name|predicate
decl_stmt|;
block|}
name|format_flag_pair
typedef|;
end_typedef

begin_comment
comment|/* Structure describing a particular kind of format processed by GCC.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The name of this kind of format, for use in diagnostics.  Also      the name of the attribute (without preceding and following __).  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Specifications of the length modifiers accepted; possibly NULL.  */
specifier|const
name|format_length_info
modifier|*
name|length_char_specs
decl_stmt|;
comment|/* Details of the conversion specification characters accepted.  */
specifier|const
name|format_char_info
modifier|*
name|conversion_specs
decl_stmt|;
comment|/* String listing the flag characters that are accepted.  */
specifier|const
name|char
modifier|*
name|flag_chars
decl_stmt|;
comment|/* String listing modifier characters (strftime) accepted.  May be NULL.  */
specifier|const
name|char
modifier|*
name|modifier_chars
decl_stmt|;
comment|/* Details of the flag characters, including pseudo-flags.  */
specifier|const
name|format_flag_spec
modifier|*
name|flag_specs
decl_stmt|;
comment|/* Details of bad combinations of flags.  */
specifier|const
name|format_flag_pair
modifier|*
name|bad_flag_pairs
decl_stmt|;
comment|/* Flags applicable to this kind of format.  */
name|int
name|flags
decl_stmt|;
comment|/* Flag character to treat a width as, or 0 if width not used.  */
name|int
name|width_char
decl_stmt|;
comment|/* Flag character to treat a left precision (strfmon) as,      or 0 if left precision not used.  */
name|int
name|left_precision_char
decl_stmt|;
comment|/* Flag character to treat a precision (for strfmon, right precision) as,      or 0 if precision not used.  */
name|int
name|precision_char
decl_stmt|;
comment|/* If a flag character has the effect of suppressing the conversion of      an argument ('*' in scanf), that flag character, otherwise 0.  */
name|int
name|suppression_char
decl_stmt|;
comment|/* Flag character to treat a length modifier as (ignored if length      modifiers not used).  Need not be placed in flag_chars for conversion      specifiers, but is used to check for bad combinations such as length      modifier with assignment suppression in scanf.  */
name|int
name|length_code_char
decl_stmt|;
comment|/* Pointer to type of argument expected if '*' is used for a width,      or NULL if '*' not used for widths.  */
name|tree
modifier|*
name|width_type
decl_stmt|;
comment|/* Pointer to type of argument expected if '*' is used for a precision,      or NULL if '*' not used for precisions.  */
name|tree
modifier|*
name|precision_type
decl_stmt|;
block|}
name|format_kind_info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|T_I
value|&integer_type_node
end_define

begin_define
define|#
directive|define
name|T89_I
value|{ STD_C89, NULL, T_I }
end_define

begin_define
define|#
directive|define
name|T_L
value|&long_integer_type_node
end_define

begin_define
define|#
directive|define
name|T89_L
value|{ STD_C89, NULL, T_L }
end_define

begin_define
define|#
directive|define
name|T_LL
value|&long_long_integer_type_node
end_define

begin_define
define|#
directive|define
name|T9L_LL
value|{ STD_C9L, NULL, T_LL }
end_define

begin_define
define|#
directive|define
name|TEX_LL
value|{ STD_EXT, NULL, T_LL }
end_define

begin_define
define|#
directive|define
name|T_S
value|&short_integer_type_node
end_define

begin_define
define|#
directive|define
name|T89_S
value|{ STD_C89, NULL, T_S }
end_define

begin_define
define|#
directive|define
name|T_UI
value|&unsigned_type_node
end_define

begin_define
define|#
directive|define
name|T89_UI
value|{ STD_C89, NULL, T_UI }
end_define

begin_define
define|#
directive|define
name|T_UL
value|&long_unsigned_type_node
end_define

begin_define
define|#
directive|define
name|T89_UL
value|{ STD_C89, NULL, T_UL }
end_define

begin_define
define|#
directive|define
name|T_ULL
value|&long_long_unsigned_type_node
end_define

begin_define
define|#
directive|define
name|T9L_ULL
value|{ STD_C9L, NULL, T_ULL }
end_define

begin_define
define|#
directive|define
name|TEX_ULL
value|{ STD_EXT, NULL, T_ULL }
end_define

begin_define
define|#
directive|define
name|T_US
value|&short_unsigned_type_node
end_define

begin_define
define|#
directive|define
name|T89_US
value|{ STD_C89, NULL, T_US }
end_define

begin_define
define|#
directive|define
name|T_F
value|&float_type_node
end_define

begin_define
define|#
directive|define
name|T89_F
value|{ STD_C89, NULL, T_F }
end_define

begin_define
define|#
directive|define
name|T99_F
value|{ STD_C99, NULL, T_F }
end_define

begin_define
define|#
directive|define
name|T_D
value|&double_type_node
end_define

begin_define
define|#
directive|define
name|T89_D
value|{ STD_C89, NULL, T_D }
end_define

begin_define
define|#
directive|define
name|T99_D
value|{ STD_C99, NULL, T_D }
end_define

begin_define
define|#
directive|define
name|T_LD
value|&long_double_type_node
end_define

begin_define
define|#
directive|define
name|T89_LD
value|{ STD_C89, NULL, T_LD }
end_define

begin_define
define|#
directive|define
name|T99_LD
value|{ STD_C99, NULL, T_LD }
end_define

begin_define
define|#
directive|define
name|T_C
value|&char_type_node
end_define

begin_define
define|#
directive|define
name|T89_C
value|{ STD_C89, NULL, T_C }
end_define

begin_define
define|#
directive|define
name|T_SC
value|&signed_char_type_node
end_define

begin_define
define|#
directive|define
name|T99_SC
value|{ STD_C99, NULL, T_SC }
end_define

begin_define
define|#
directive|define
name|T_UC
value|&unsigned_char_type_node
end_define

begin_define
define|#
directive|define
name|T99_UC
value|{ STD_C99, NULL, T_UC }
end_define

begin_define
define|#
directive|define
name|T_V
value|&void_type_node
end_define

begin_define
define|#
directive|define
name|T89_V
value|{ STD_C89, NULL, T_V }
end_define

begin_define
define|#
directive|define
name|T_W
value|&wchar_type_node
end_define

begin_define
define|#
directive|define
name|T94_W
value|{ STD_C94, "wchar_t", T_W }
end_define

begin_define
define|#
directive|define
name|TEX_W
value|{ STD_EXT, "wchar_t", T_W }
end_define

begin_define
define|#
directive|define
name|T_WI
value|&wint_type_node
end_define

begin_define
define|#
directive|define
name|T94_WI
value|{ STD_C94, "wint_t", T_WI }
end_define

begin_define
define|#
directive|define
name|TEX_WI
value|{ STD_EXT, "wint_t", T_WI }
end_define

begin_define
define|#
directive|define
name|T_ST
value|&size_type_node
end_define

begin_define
define|#
directive|define
name|T99_ST
value|{ STD_C99, "size_t", T_ST }
end_define

begin_define
define|#
directive|define
name|T_SST
value|&signed_size_type_node
end_define

begin_define
define|#
directive|define
name|T99_SST
value|{ STD_C99, "signed size_t", T_SST }
end_define

begin_define
define|#
directive|define
name|T_PD
value|&ptrdiff_type_node
end_define

begin_define
define|#
directive|define
name|T99_PD
value|{ STD_C99, "ptrdiff_t", T_PD }
end_define

begin_define
define|#
directive|define
name|T_UPD
value|&unsigned_ptrdiff_type_node
end_define

begin_define
define|#
directive|define
name|T99_UPD
value|{ STD_C99, "unsigned ptrdiff_t", T_UPD }
end_define

begin_define
define|#
directive|define
name|T_IM
value|&intmax_type_node
end_define

begin_define
define|#
directive|define
name|T99_IM
value|{ STD_C99, "intmax_t", T_IM }
end_define

begin_define
define|#
directive|define
name|T_UIM
value|&uintmax_type_node
end_define

begin_define
define|#
directive|define
name|T99_UIM
value|{ STD_C99, "uintmax_t", T_UIM }
end_define

begin_define
define|#
directive|define
name|T_D32
value|&dfloat32_type_node
end_define

begin_define
define|#
directive|define
name|TEX_D32
value|{ STD_EXT, "_Decimal32", T_D32 }
end_define

begin_define
define|#
directive|define
name|T_D64
value|&dfloat64_type_node
end_define

begin_define
define|#
directive|define
name|TEX_D64
value|{ STD_EXT, "_Decimal64", T_D64 }
end_define

begin_define
define|#
directive|define
name|T_D128
value|&dfloat128_type_node
end_define

begin_define
define|#
directive|define
name|TEX_D128
value|{ STD_EXT, "_Decimal128", T_D128 }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_C_FORMAT_H */
end_comment

end_unit

