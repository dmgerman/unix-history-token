begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: param.h,v 10.1 86/11/29 13:53:49 jg Rel $ */
end_comment

begin_comment
comment|/* $Header: param.h,v 10.1 86/11/29 13:53:49 jg Rel $ */
end_comment

begin_comment
comment|/* param.h	Definitions for primitive objects in Workstation Graphics  *		Architecture  *  *	Each object has two definitions.  The more human-readable one  *	has "reasonable" definitions, the one beginning with a_ expresses  *	the structure as an array of shorts so that the C compiler doesn't  *	move it around for silly alignment reasons.  *  * Author:	Paul J. Asente  * 		Digital Equipment Corporation  * 		Western Reseach Lab  * Date:	June 1983  */
end_comment

begin_comment
comment|/****************************************************************************  *									    *  *  Copyright (c) 1983, 1984 by						    *  *  DIGITAL EQUIPMENT CORPORATION, Maynard, Massachusetts.		    *  *  All rights reserved.						    *  * 									    *  *  This software is furnished on an as-is basis and may be used and copied *  *  only with inclusion of the above copyright notice. This software or any *  *  other copies thereof may be provided or otherwise made available to     *  *  others only for non-commercial purposes.  No title to or ownership of   *  *  the software is hereby transferred.					    *  * 									    *  *  The information in this software is  subject to change without notice   *  *  and  should  not  be  construed as  a commitment by DIGITAL EQUIPMENT   *  *  CORPORATION.							    *  * 									    *  *  DIGITAL assumes no responsibility for the use  or  reliability of its   *  *  software on equipment which is not supplied by DIGITAL.		    *  * 									    *  *									    *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WGA_PARAMS
end_ifndef

begin_define
define|#
directive|define
name|WGA_PARAMS
end_define

begin_typedef
typedef|typedef
name|short
name|Constant
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Point
block|{
name|short
name|p_x
decl_stmt|;
name|short
name|p_y
decl_stmt|;
block|}
name|Point
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Point
modifier|*
name|PointPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Point
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_PointPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Extent
block|{
name|short
name|e_width
decl_stmt|;
name|short
name|e_height
decl_stmt|;
block|}
name|Extent
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Extent
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Rectangle
block|{
name|a_Point
name|r_origin
decl_stmt|;
name|a_Extent
name|r_size
decl_stmt|;
block|}
name|Rectangle
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Rectangle
modifier|*
name|RectanglePtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Rectangle
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_RectanglePtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|r_x
value|r_origin[0]
end_define

begin_define
define|#
directive|define
name|r_y
value|r_origin[1]
end_define

begin_define
define|#
directive|define
name|r_width
value|r_size[0]
end_define

begin_define
define|#
directive|define
name|r_height
value|r_size[1]
end_define

begin_typedef
typedef|typedef
struct|struct
name|_RectangleList
block|{
name|a_RectanglePtr
name|r_first
decl_stmt|;
name|short
name|r_count
decl_stmt|;
block|}
name|RectangleList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_RectangleList
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|BitmapEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|BitmapEntry
modifier|*
name|BitmapEntryPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_BitmapEntryPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Bitmap
block|{
name|a_BitmapEntryPtr
name|bm_address
decl_stmt|;
name|short
name|bm_width
decl_stmt|;
name|short
name|bm_height
decl_stmt|;
name|short
name|bm_bitsPerPixel
decl_stmt|;
block|}
name|BitMap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Bitmap
index|[
literal|5
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SubBitmap
block|{
name|a_Bitmap
name|sb_base
decl_stmt|;
name|a_Point
name|sb_offset
decl_stmt|;
block|}
name|SubBitmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_SubBitmap
index|[
literal|7
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|sb_address
value|sb_base
end_define

begin_define
define|#
directive|define
name|sb_width
value|sb_base[2]
end_define

begin_define
define|#
directive|define
name|sb_height
value|sb_base[3]
end_define

begin_define
define|#
directive|define
name|sb_bitsPerPixel
value|sb_base[4]
end_define

begin_define
define|#
directive|define
name|sb_x
value|sb_offset[0]
end_define

begin_define
define|#
directive|define
name|sb_y
value|sb_offset[1]
end_define

begin_typedef
typedef|typedef
struct|struct
name|_Halftone
block|{
name|a_Bitmap
name|ht_base
decl_stmt|;
name|a_Point
name|ht_offset
decl_stmt|;
block|}
name|Halftone
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Halftone
index|[
literal|7
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ht_address
value|ht_base
end_define

begin_define
define|#
directive|define
name|ht_width
value|ht_base[2]
end_define

begin_define
define|#
directive|define
name|ht_height
value|ht_base[3]
end_define

begin_define
define|#
directive|define
name|ht_bitsPerPixel
value|ht_base[4]
end_define

begin_define
define|#
directive|define
name|ht_x
value|ht_offset[0]
end_define

begin_define
define|#
directive|define
name|ht_y
value|ht_offset[1]
end_define

begin_typedef
typedef|typedef
name|long
name|Map
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Map
modifier|*
name|MapPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Map
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_MapPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Segment
block|{
name|a_Point
name|seg_p
decl_stmt|;
name|short
name|seg_flags
decl_stmt|;
block|}
name|Segment
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Segment
modifier|*
name|SegmentPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Segment
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_SegmentPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|seg_x
value|seg_p[0]
end_define

begin_define
define|#
directive|define
name|seg_y
value|seg_p[1]
end_define

begin_comment
comment|/* Meanings of bits in seg_flags.  Bit on means the predicate is true */
end_comment

begin_define
define|#
directive|define
name|seg_relative
value|0x0001
end_define

begin_define
define|#
directive|define
name|seg_dontDraw
value|0x0002
end_define

begin_define
define|#
directive|define
name|seg_curved
value|0x0004
end_define

begin_define
define|#
directive|define
name|seg_startClosed
value|0x0008
end_define

begin_define
define|#
directive|define
name|seg_endClosed
value|0x0010
end_define

begin_define
define|#
directive|define
name|seg_drawLastPoint
value|0x0020
end_define

begin_typedef
typedef|typedef
struct|struct
name|_SegmentList
block|{
name|a_SegmentPtr
name|seg_first
decl_stmt|;
name|short
name|seg_count
decl_stmt|;
block|}
name|SegmentList
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_SegmentList
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PatternString
block|{
name|short
name|p_length
decl_stmt|;
name|unsigned
name|short
name|p_pattern
decl_stmt|;
name|short
name|p_multiplier
decl_stmt|;
block|}
name|PatternString
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_PatternString
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_PatternState
block|{
name|short
name|p_position
decl_stmt|;
name|short
name|p_count
decl_stmt|;
block|}
name|PatternState
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|PatternState
modifier|*
name|PatternStatePtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_PatternState
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_PatternStatePtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|FontWidthEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FontWidthEntry
modifier|*
name|FontWidthEntryPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_FontWidthEntryPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FontData
block|{
name|a_Bitmap
name|f_characters
decl_stmt|;
name|short
name|f_firstChar
decl_stmt|;
name|short
name|f_lastChar
decl_stmt|;
name|a_FontWidthEntryPtr
name|f_leftArray
decl_stmt|;
name|short
name|f_baseline
decl_stmt|;
name|short
name|f_spaceIndex
decl_stmt|;
name|short
name|f_fixedWidth
decl_stmt|;
block|}
name|FontData
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|FontData
modifier|*
name|FontPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_FontData
index|[
literal|12
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_FontPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CharPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_CharPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_TextString
block|{
name|a_CharPtr
name|t_first
decl_stmt|;
name|short
name|t_count
decl_stmt|;
block|}
name|TextString
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_TextString
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ControlElement
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ControlElement
modifier|*
name|ControlElementPtr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_ControlElementPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ControlString
block|{
name|a_ControlElementPtr
name|c_first
decl_stmt|;
name|short
name|c_count
decl_stmt|;
block|}
name|ControlString
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_ControlString
index|[
literal|3
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|MemSize
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_MemSize
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MemArea
block|{
name|a_CharPtr
name|m_base
decl_stmt|;
name|a_MemSize
name|m_size
decl_stmt|;
block|}
name|MemArea
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_MemArea
index|[
literal|4
index|]
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

