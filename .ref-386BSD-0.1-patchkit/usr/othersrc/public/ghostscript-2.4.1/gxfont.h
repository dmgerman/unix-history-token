begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxfont.h */
end_comment

begin_comment
comment|/* Internal font definition for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gsmatrix.h, gxdevice.h */
end_comment

begin_include
include|#
directive|include
file|"gsfont.h"
end_include

begin_comment
comment|/* A font object as seen by clients. */
end_comment

begin_comment
comment|/* See the PostScript Language Reference Manual for details. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gs_show_enum_s_DEFINED
end_ifndef

begin_struct_decl
struct_decl|struct
name|gs_show_enum_s
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
argument_list|(
operator|*
name|gs_proc_build_char
argument_list|)
argument_list|(
name|P5
argument_list|(
expr|struct
name|gs_show_enum_s
operator|*
argument_list|,
expr|struct
name|gs_state_s
operator|*
argument_list|,
expr|struct
name|gs_font_s
operator|*
argument_list|,
name|char_code
argument_list|,
name|char
operator|*
comment|/* build_char_data */
argument_list|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|gs_no_build_char_proc
argument_list|(
name|P5
argument_list|(
expr|struct
name|gs_show_enum_s
operator|*
argument_list|,
expr|struct
name|gs_state_s
operator|*
argument_list|,
expr|struct
name|gs_font_s
operator|*
argument_list|,
name|char_code
argument_list|,
name|char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the known font types. */
end_comment

begin_comment
comment|/* These numbers must be the same as the values of FontType */
end_comment

begin_comment
comment|/* in font dictionaries. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ft_composite
init|=
literal|0
block|,
name|ft_encrypted
init|=
literal|1
block|,
name|ft_user_defined
init|=
literal|3
block|}
name|font_type
typedef|;
end_typedef

begin_comment
comment|/* Define the composite font mapping types. */
end_comment

begin_comment
comment|/* These numbers must be the same as the values of FMapType */
end_comment

begin_comment
comment|/* in type 0 font dictionaries. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|fmap_8_8
init|=
literal|2
block|,
name|fmap_escape
init|=
literal|3
block|,
name|fmap_1_7
init|=
literal|4
block|,
name|fmap_9_7
init|=
literal|5
block|,
name|fmap_SubsVector
init|=
literal|6
block|,
name|fmap_double_escape
init|=
literal|7
block|,
name|fmap_shift
init|=
literal|8
block|}
name|fmap_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|fmap_type_min
value|2
end_define

begin_define
define|#
directive|define
name|fmap_type_max
value|8
end_define

begin_define
define|#
directive|define
name|fmap_type_is_modal
parameter_list|(
name|fmt
parameter_list|)
define|\
value|((fmt) == fmap_escape || (fmt) == fmap_double_escape || (fmt) == fmap_shift)
end_define

begin_comment
comment|/* This is the type-specific information for a type 0 (composite) gs_font. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_type0_data_s
name|gs_type0_data
typedef|;
end_typedef

begin_struct
struct|struct
name|gs_type0_data_s
block|{
name|fmap_type
name|FMapType
decl_stmt|;
name|byte
name|EscChar
decl_stmt|,
name|ShiftIn
decl_stmt|,
name|ShiftOut
decl_stmt|;
name|byte
modifier|*
name|SubsVector
decl_stmt|;
name|uint
name|subs_size
decl_stmt|;
comment|/* bytes per entry */
name|uint
name|subs_width
decl_stmt|;
comment|/* # of entries */
name|uint
modifier|*
name|Encoding
decl_stmt|;
name|uint
name|encoding_size
decl_stmt|;
name|gs_font
modifier|*
modifier|*
name|FDepVector
decl_stmt|;
name|uint
name|fdep_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the type-specific information for a type 1 (encrypted) gs_font. */
end_comment

begin_define
define|#
directive|define
name|zone_table
parameter_list|(
name|tname
parameter_list|,
name|size
parameter_list|)
define|\
value|struct {\ 		int count;\ 		int data[(size)*2];\ 	} tname
end_define

begin_define
define|#
directive|define
name|stem_table
parameter_list|(
name|tname
parameter_list|,
name|size
parameter_list|)
define|\
value|struct {\ 		int count;\ 		float data[size];\ 	} tname
end_define

begin_typedef
typedef|typedef
name|struct
name|gs_type1_data_s
name|gs_type1_data
typedef|;
end_typedef

begin_struct
struct|struct
name|gs_type1_data_s
block|{
name|int
name|PaintType
decl_stmt|;
comment|/* PaintType */
name|int
argument_list|(
operator|*
name|subr_proc
argument_list|)
argument_list|(
name|P3
argument_list|(
argument|gs_type1_data *pdata
argument_list|,
argument|int index
argument_list|,
argument|byte **pcharstring
argument_list|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
operator|*
name|pop_proc
argument_list|)
argument_list|(
name|P2
argument_list|(
name|gs_type1_data
operator|*
argument_list|,
name|fixed
operator|*
argument_list|)
argument_list|)
expr_stmt|;
name|char
modifier|*
name|proc_data
decl_stmt|;
comment|/* data for subr_proc */
name|int
name|lenIV
decl_stmt|;
comment|/* # of leading garbage bytes */
comment|/* The following hint information is not used yet. */
comment|/* See chapter 5 of the "Adobe Type 1 Font Format" book. */
name|int
name|BlueFuzz
decl_stmt|;
name|float
name|BlueScale
decl_stmt|;
name|int
name|BlueShift
decl_stmt|;
define|#
directive|define
name|max_BlueValues
value|7
name|zone_table
argument_list|(
name|BlueValues
argument_list|,
name|max_BlueValues
argument_list|)
expr_stmt|;
name|float
name|ExpansionFactor
decl_stmt|;
name|int
name|ForceBold
decl_stmt|;
define|#
directive|define
name|max_FamilyBlues
value|7
name|zone_table
argument_list|(
name|FamilyBlues
argument_list|,
name|max_FamilyBlues
argument_list|)
expr_stmt|;
define|#
directive|define
name|max_FamilyOtherBlues
value|5
name|zone_table
argument_list|(
name|FamilyOtherBlues
argument_list|,
name|max_FamilyOtherBlues
argument_list|)
expr_stmt|;
name|int
name|LanguageGroup
decl_stmt|;
define|#
directive|define
name|max_OtherBlues
value|5
name|zone_table
argument_list|(
name|OtherBlues
argument_list|,
name|max_OtherBlues
argument_list|)
expr_stmt|;
name|int
name|RndStemUp
decl_stmt|;
name|stem_table
argument_list|(
name|StdHW
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|stem_table
argument_list|(
name|StdVW
argument_list|,
literal|1
argument_list|)
expr_stmt|;
define|#
directive|define
name|max_StemSnap
value|12
name|stem_table
argument_list|(
name|StemSnapH
argument_list|,
name|max_StemSnap
argument_list|)
expr_stmt|;
name|stem_table
argument_list|(
name|StemSnapV
argument_list|,
name|max_StemSnap
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|gs_type1_data_s_DEFINED
end_define

begin_comment
comment|/* Even though it costs a little extra space, it's more convenient to */
end_comment

begin_comment
comment|/* include all the necessary information for>>all<< known font types */
end_comment

begin_comment
comment|/* (user-defined, encrypted, and composite) in the font structure. */
end_comment

begin_struct
struct|struct
name|gs_font_s
block|{
name|gs_font
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* chain for scaled font cache */
name|gs_font
modifier|*
name|base
decl_stmt|;
comment|/* original (unscaled) base font */
name|gs_font_dir
modifier|*
name|dir
decl_stmt|;
comment|/* directory where registered */
name|char
modifier|*
name|client_data
decl_stmt|;
comment|/* additional client data */
name|gs_matrix
name|FontMatrix
decl_stmt|;
name|font_type
name|FontType
decl_stmt|;
name|int
name|WMode
decl_stmt|;
comment|/* 0 or 1 */
name|gs_proc_build_char
name|build_char_proc
decl_stmt|;
comment|/* BuildChar */
name|char
modifier|*
name|build_char_data
decl_stmt|;
comment|/* private data for BuildChar */
union|union
name|_d
block|{
comment|/* Composite (type 0) fonts */
name|gs_type0_data
name|type0_data
decl_stmt|;
comment|/* Base (non-type 0) fonts */
struct|struct
name|_b
block|{
name|gs_rect
name|FontBBox
decl_stmt|;
name|long
name|UniqueID
decl_stmt|;
comment|/* Type 1 data */
name|gs_type1_data
name|type1_data
decl_stmt|;
block|}
name|base
struct|;
block|}
name|data
union|;
block|}
struct|;
end_struct

end_unit

