begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bitblt_ext.h,v 10.1 86/11/19 10:51:57 jg Exp $ */
end_comment

begin_comment
comment|/*  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  *  * Written by Daniel Stone, Brown University/IRIS  (des@iris)  */
end_comment

begin_comment
comment|/*  * Rectangle.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Blt_Rectangle
block|{
name|short
name|origin_y
decl_stmt|;
comment|/* top */
name|short
name|origin_x
decl_stmt|;
comment|/* left */
name|short
name|corner_y
decl_stmt|;
comment|/* bottom */
name|short
name|corner_x
decl_stmt|;
comment|/* right */
block|}
name|Blt_Rectangle
typedef|;
end_typedef

begin_comment
comment|/*  * Bitmap.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|Blt_Bitmap
block|{
name|unsigned
name|short
modifier|*
name|base
decl_stmt|;
comment|/* pointer to the actual bits */
name|Blt_Rectangle
name|rect
decl_stmt|;
comment|/* bounding rectangle */
name|short
name|nshorts
decl_stmt|;
comment|/* number of shorts wide the bitmap is */
block|}
name|Blt_Bitmap
typedef|;
end_typedef

begin_comment
comment|/*  * Tile. (Texture,Pattern have your pick.)  */
end_comment

begin_define
define|#
directive|define
name|BLT_TILE_SIZE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
name|Blt_Tile
block|{
name|unsigned
name|short
name|tile
index|[
name|BLT_TILE_SIZE
index|]
decl_stmt|;
block|}
name|Blt_Tile
typedef|;
end_typedef

begin_comment
comment|/*  * Bitblt user data structure.  *  * bitblt() is passed a pointer to a user structure which contains all the  * necessary information to do the bit block transfer.  *  * NOTE: If the "comb_rule" does uses the source then tile_ptr does not have  * to be set.  Otherwise comb_rule is a tile combination rule and the  * src_bitmap and src_rect need not be filled in.  If the clip bit in  * blt_flags is off (0) then clp_rect need not be filled in. If the mask  * bit in blt_flags is off then msk_bitmap need not be filled in.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Blt_Bitmap
name|src_bitmap
decl_stmt|;
comment|/* Bitmap to be copied from */
name|Blt_Rectangle
name|src_rect
decl_stmt|;
comment|/* Specifies the area in the 					   src_bitmap */
name|Blt_Bitmap
name|dst_bitmap
decl_stmt|;
comment|/* Bitmap to be changed */
name|Blt_Rectangle
name|dst_rect
decl_stmt|;
comment|/* Specifies the area in the 					   dst_bitmap */
name|Blt_Rectangle
name|clp_rect
decl_stmt|;
comment|/* Another rectangle to clip against */
name|Blt_Tile
modifier|*
name|tile_ptr
decl_stmt|;
comment|/* The tile to be used if the 					   combination rule uses a tile */
name|Blt_Bitmap
name|msk_bitmap
decl_stmt|;
comment|/* Masking bitmap */
name|short
name|comb_rule
decl_stmt|;
comment|/* combination rule to be used */
name|short
name|blt_flags
decl_stmt|;
comment|/* A bit on means do a certain 					   operation.  For example if the first 					   bit is on then do clipping. */
block|}
name|Blt
typedef|;
end_typedef

begin_comment
comment|/*  * Flags blt_flags could be.  */
end_comment

begin_define
define|#
directive|define
name|BLT_CLIPON
value|0x1
end_define

begin_define
define|#
directive|define
name|BLT_MASKON
value|0x2
end_define

begin_define
define|#
directive|define
name|BLT_ECHO
value|0x4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BPW
end_ifndef

begin_comment
comment|/*  * Macros for division from words and bytes.  */
end_comment

begin_define
define|#
directive|define
name|BPW
value|16
end_define

begin_comment
comment|/* Bits per Word */
end_comment

begin_define
define|#
directive|define
name|LOG2_BPW
value|4
end_define

begin_define
define|#
directive|define
name|MOD_BPW
parameter_list|(
name|value
parameter_list|)
value|((value)& (BPW-1))
end_define

begin_define
define|#
directive|define
name|DIV_BPW
parameter_list|(
name|value
parameter_list|)
value|((value)>> LOG2_BPW)
end_define

begin_define
define|#
directive|define
name|MUL_BPW
parameter_list|(
name|value
parameter_list|)
value|((value)<< LOG2_BPW)
end_define

begin_comment
comment|/*  * Bits TO Words.  */
end_comment

begin_define
define|#
directive|define
name|BTOW
parameter_list|(
name|bits
parameter_list|)
value|(DIV_BPW((bits) + (BPW-1)))
end_define

begin_comment
comment|/*  * Macros for the division and multiplication by 2.  */
end_comment

begin_define
define|#
directive|define
name|DIV_2
parameter_list|(
name|n
parameter_list|)
value|((n)>> 1)
end_define

begin_define
define|#
directive|define
name|MUL_2
parameter_list|(
name|n
parameter_list|)
value|((n)<< 1)
end_define

begin_define
define|#
directive|define
name|MOD_2
parameter_list|(
name|n
parameter_list|)
value|((n)& 0x1)
end_define

begin_endif
endif|#
directive|endif
endif|BPW
end_endif

begin_comment
comment|/*  * Flags to indicate whether or not current screen is a hardware or  * software cursor.  */
end_comment

begin_define
define|#
directive|define
name|SOFT_CURSOR
value|0x1
end_define

begin_define
define|#
directive|define
name|HARD_CURSOR
value|0x2
end_define

begin_comment
comment|/*  * externs for X access.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|XIoAddr
modifier|*
name|XAddr
decl_stmt|;
end_decl_stmt

end_unit

