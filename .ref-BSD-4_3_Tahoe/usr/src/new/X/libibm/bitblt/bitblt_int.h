begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: bitblt_int.h,v 10.1 86/11/19 10:52:05 jg Exp $ */
end_comment

begin_comment
comment|/*  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software without  * specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  *  * Written by Daniel Stone, Brown University/IRIS  (des@iris)  */
end_comment

begin_comment
comment|/*  * BITBLT COMPILATION OPTIONS:  *	define APA16  	 	Bltter handles the APA16 screen.  *	define APA8   		Bltter handles the APA8 screen.  *	define APA8C   		Bltter handles the APA8C screen.  *	define AED   		Bltter handles the AED screen.  *	define BLT_DEBUG   	Bltter debug messages on.  *	define USE_APA16_HDWR   Bltter will use screen hardware where  *				implemented.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BLT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DEBUGF
parameter_list|(
name|cond
parameter_list|,
name|stmt
parameter_list|)
value|if (cond) { stmt; }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGF
parameter_list|(
name|cond
parameter_list|,
name|stmt
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * bitblt_ext.h needs this defined because of XAddr.  */
end_comment

begin_include
include|#
directive|include
file|<machinecons/xio.h>
end_include

begin_comment
comment|/*  * Include the external interface routine to the bitblt routine, bitblt_ext.h.  */
end_comment

begin_include
include|#
directive|include
file|"bitblt_ext.h"
end_include

begin_typedef
typedef|typedef
name|Blt
name|Blt_userdata
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Blt_screen_info
block|{
name|unsigned
name|short
modifier|*
name|firstaddr
decl_stmt|;
comment|/* first address on the screen bitmap */
name|unsigned
name|short
modifier|*
name|lastaddr
decl_stmt|;
comment|/* last address on the screen bitmap */
name|unsigned
name|long
name|cursortype
decl_stmt|;
comment|/* Indicate the type of cursor on this 					   screen. */
block|}
name|Blt_screen_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bitmap_info
block|{
name|unsigned
name|short
modifier|*
name|data
decl_stmt|;
comment|/* pointer to the starting place of the bit 				   blt. */
name|Blt_Rectangle
name|rect
decl_stmt|;
comment|/* bounds of the area to be used or changed */
name|long
name|nextline
decl_stmt|;
comment|/* The amount to be added to the pointer to 			   get to the next logical scanline */
block|}
name|Blt_bitmap_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|Blt_sysdata
block|{
name|long
name|height
decl_stmt|,
name|width
decl_stmt|;
comment|/* the height and width (in bits) of the 				   destination area to be changed */
name|short
name|nshorts
decl_stmt|;
comment|/* number of destination shorts to be changed */
name|short
name|top_to_bot
decl_stmt|;
comment|/* If non-zero it indicates the blt is to go 				   from right to left, bottom to top */
name|short
name|is_src
decl_stmt|;
comment|/* Indicates that the rule uses the source */
name|short
name|rule
decl_stmt|;
comment|/* combination rule or "mode" to be used with 				   the data */
name|short
name|preload_src
decl_stmt|;
comment|/* Indicates 2 source words are needed to make 				   the first destination word. */
name|short
name|preload_msk
decl_stmt|;
comment|/* Indicates 2 mask words are needed to make 				   the first destination word. */
name|short
name|skew_src
decl_stmt|;
comment|/* The amount the source must be shifted to 				   line up with the destination */
name|short
name|skew_msk
decl_stmt|;
comment|/* The amount the mask must be shifted to 				   line up with the destination */
name|unsigned
name|short
name|left_mask
decl_stmt|;
comment|/* left mask to protect those bits on the 				      left edge that are not to be changed */
name|unsigned
name|short
name|right_mask
decl_stmt|;
comment|/* right mask to protect those bits on the 				      right edge that are not to be changed */
name|unsigned
name|short
modifier|*
name|tile_ptr
decl_stmt|;
comment|/* Points to the Tile to be used to tile 				      the destination */
name|Blt_bitmap_info
name|dst
decl_stmt|;
comment|/* Internal information for the destination  				   bitmap. */
name|Blt_bitmap_info
name|src
decl_stmt|;
comment|/* Internal information for the source bitmap */
name|Blt_bitmap_info
name|msk
decl_stmt|;
comment|/* Internal information for the mask bitmap*/
if|#
directive|if
operator|(
name|APA8
operator|||
name|APA8C
operator|)
name|short
name|dst_plus
decl_stmt|;
comment|/* the amount to increment the destination 				   pointer to get to the next word. (usually 				   its 1, with the APA-8 its 2)*/
name|short
name|src_plus
decl_stmt|;
comment|/* the amount to increment the source  				   pointer to get to the next word. (usually 				   its 1, with the APA-8 its 2)*/
endif|#
directive|endif
block|}
name|Blt_sysdata
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SETRECT
parameter_list|(
name|dst
parameter_list|,
name|l
parameter_list|,
name|t
parameter_list|,
name|r
parameter_list|,
name|b
parameter_list|)
value|{			\ 	(dst)->origin_x = l;  (dst)->origin_y = t;	\ 	(dst)->corner_x = r; (dst)->corner_y = b;	\ }
end_define

begin_comment
comment|/*  * Macro to determine if a bitmap points to the APA-8 screen.  */
end_comment

begin_define
define|#
directive|define
name|APA8BASE
value|0xf4d00000
end_define

begin_define
define|#
directive|define
name|APA8_BYTE_SIZE
value|(128*512)
end_define

begin_comment
comment|/*  * Macro to determine if a bitmap points to the APA-8 screen.  */
end_comment

begin_define
define|#
directive|define
name|APA8CBASE
value|0xf4d20000
end_define

begin_define
define|#
directive|define
name|APA8C_BYTE_SIZE
value|(128*512)
end_define

begin_comment
comment|/*  * Macro to determine if a bitmap points to the APA-16 screen.  */
end_comment

begin_define
define|#
directive|define
name|APA16BASE
value|0xf4d80000
end_define

begin_define
define|#
directive|define
name|APA16_BYTE_SIZE
value|(128*1024)
end_define

begin_comment
comment|/*  * Macro to determine if a bitmap points to the AED's offscreen bitmap  */
end_comment

begin_define
define|#
directive|define
name|AEDBASE
value|0xEF100000
end_define

begin_define
define|#
directive|define
name|AED_BYTE_SIZE
value|(128*800)
end_define

begin_comment
comment|/*  * Macro to determine if a bitmap points to the screen.  */
end_comment

begin_define
define|#
directive|define
name|IS_APA8
parameter_list|(
name|BM
parameter_list|)
value|(APA8BASE<= (long)BM.base&& \ 			 (long)BM.base< (APA8BASE+(2*APA8_BYTE_SIZE)))
end_define

begin_define
define|#
directive|define
name|IS_APA8C
parameter_list|(
name|BM
parameter_list|)
value|(APA8CBASE<= (long)BM.base&& \ 			 (long)BM.base< (APA8CBASE+(2*APA8C_BYTE_SIZE)))
end_define

begin_define
define|#
directive|define
name|IS_APA8orAPA8C
parameter_list|(
name|BM
parameter_list|)
value|(APA8BASE<= (long)BM.base&& \ 				(long)BM.base< (APA8CBASE+(2*APA8C_BYTE_SIZE)))
end_define

begin_define
define|#
directive|define
name|IS_APA16
parameter_list|(
name|BM
parameter_list|)
value|(APA16BASE<= (long)BM.base&& \ 			(long)BM.base< (APA16BASE+APA16_BYTE_SIZE))
end_define

begin_define
define|#
directive|define
name|IS_AED
parameter_list|(
name|BM
parameter_list|)
value|(AEDBASE<= (long)BM.base&& \ 			(long)BM.base< (AEDBASE+AED_BYTE_SIZE))
end_define

begin_define
define|#
directive|define
name|DstClear
value|0
end_define

begin_define
define|#
directive|define
name|SrcAnd
value|1
end_define

begin_define
define|#
directive|define
name|SrcAndNotDst
value|2
end_define

begin_define
define|#
directive|define
name|SrcCopy
value|3
end_define

begin_define
define|#
directive|define
name|NotSrcAnd
value|4
end_define

begin_define
define|#
directive|define
name|DstCopy
value|5
end_define

begin_define
define|#
directive|define
name|SrcXor
value|6
end_define

begin_define
define|#
directive|define
name|SrcOr
value|7
end_define

begin_define
define|#
directive|define
name|NotSrcAndNotDst
value|8
end_define

begin_define
define|#
directive|define
name|NotSrcXor
value|9
end_define

begin_define
define|#
directive|define
name|NotDstCopy
value|10
end_define

begin_define
define|#
directive|define
name|SrcOrNotDst
value|11
end_define

begin_define
define|#
directive|define
name|NotSrcCopy
value|12
end_define

begin_define
define|#
directive|define
name|NotSrcOr
value|13
end_define

begin_define
define|#
directive|define
name|NotSrcOrNotDst
value|14
end_define

begin_define
define|#
directive|define
name|DstSet
value|15
end_define

begin_define
define|#
directive|define
name|TileDstClear
value|16
end_define

begin_define
define|#
directive|define
name|TileAnd
value|17
end_define

begin_define
define|#
directive|define
name|TileAndNotDst
value|18
end_define

begin_define
define|#
directive|define
name|TileCopy
value|19
end_define

begin_define
define|#
directive|define
name|NotTileAnd
value|20
end_define

begin_define
define|#
directive|define
name|TileDstCopy
value|21
end_define

begin_define
define|#
directive|define
name|TileXor
value|22
end_define

begin_define
define|#
directive|define
name|TileOr
value|23
end_define

begin_define
define|#
directive|define
name|NotTileAndNotDst
value|24
end_define

begin_define
define|#
directive|define
name|NotTileXor
value|25
end_define

begin_define
define|#
directive|define
name|TileNotDstCopy
value|26
end_define

begin_define
define|#
directive|define
name|TileOrNotDst
value|27
end_define

begin_define
define|#
directive|define
name|NotTileCopy
value|28
end_define

begin_define
define|#
directive|define
name|NotTileOr
value|29
end_define

begin_define
define|#
directive|define
name|NotTileOrNotDst
value|30
end_define

begin_define
define|#
directive|define
name|TileDstSet
value|31
end_define

begin_define
define|#
directive|define
name|SRC_TO_TILE
value|TileDstClear
end_define

begin_comment
comment|/*  * Macros to determine if the given rule refers to a tile or a source  * bitmap.  * NOTE: This Macro depends on the order of the defines above.  */
end_comment

begin_define
define|#
directive|define
name|IS_SRC
parameter_list|(
name|rule
parameter_list|)
value|((rule< TileDstClear)&& (rule != DstSet)&& \ 			 (rule != DstClear)&& (rule != NotDstCopy))
end_define

begin_define
define|#
directive|define
name|IS_SCREEN
parameter_list|(
name|bitmap
parameter_list|)
value|(blt_cur_screen.firstaddr<= bitmap.base&& \ 			   bitmap.base< blt_cur_screen.lastaddr)
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

begin_endif
endif|#
directive|endif
endif|BPW
end_endif

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

begin_comment
comment|/*  * Need to multiply by 4 when using the APA-8.  */
end_comment

begin_define
define|#
directive|define
name|MUL_4
parameter_list|(
name|n
parameter_list|)
value|((n)<< 2)
end_define

begin_comment
comment|/*  * Bits Per Byte.  */
end_comment

begin_define
define|#
directive|define
name|BPB
value|8
end_define

begin_define
define|#
directive|define
name|LOG2_BPB
value|3
end_define

begin_define
define|#
directive|define
name|MOD_BPB
parameter_list|(
name|value
parameter_list|)
value|((value)& (BPB-1))
end_define

begin_define
define|#
directive|define
name|DIV_BPB
parameter_list|(
name|value
parameter_list|)
value|((value)>> LOG2_BPB)
end_define

begin_define
define|#
directive|define
name|MUL_BPB
parameter_list|(
name|value
parameter_list|)
value|((value)<< LOG2_BPB)
end_define

begin_comment
comment|/*  * Bits TO Bytes.  */
end_comment

begin_define
define|#
directive|define
name|BTOB
parameter_list|(
name|bits
parameter_list|)
value|(DIV_BPB((bits) + (BPB-1)))
end_define

begin_decl_stmt
specifier|extern
name|Blt_screen_info
name|blt_cur_screen
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|BLT_DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|blt_debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a< b) ? (a) : (b))
end_define

begin_define
define|#
directive|define
name|MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a> b) ? (a) : (b))
end_define

end_unit

