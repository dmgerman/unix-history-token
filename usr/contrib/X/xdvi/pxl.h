begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Written by Eric C. Cooper, CMU  *  */
end_comment

begin_comment
comment|/* $Header: pxl.h,v 10.5 86/02/01 15:45:03 tony Rel $ */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|BITS_PER_SHORT
value|16
end_define

begin_define
define|#
directive|define
name|BITS_PER_BYTE
value|8
end_define

begin_define
define|#
directive|define
name|BYTES_PER_LONG
value|(BITS_PER_LONG/BITS_PER_BYTE)
end_define

begin_define
define|#
directive|define
name|BYTES_PER_SHORT
value|(BITS_PER_SHORT/BITS_PER_BYTE)
end_define

begin_define
define|#
directive|define
name|SHORTS_PER_LONG
value|(BITS_PER_LONG/BITS_PER_SHORT)
end_define

begin_define
define|#
directive|define
name|ROUNDUP
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x)+(y)-1)/(y))
end_define

begin_comment
comment|/*  * Raster ops.  */
end_comment

begin_define
define|#
directive|define
name|ROP_CLEAR
value|0
end_define

begin_define
define|#
directive|define
name|ROP_ERASE
value|2
end_define

begin_define
define|#
directive|define
name|ROP_COPYREV
value|3
end_define

begin_define
define|#
directive|define
name|ROP_COPY
value|12
end_define

begin_define
define|#
directive|define
name|ROP_PAINT
value|14
end_define

begin_define
define|#
directive|define
name|ROP_FILL
value|15
end_define

begin_comment
comment|/*  * Bitmap structure for raster ops.  */
end_comment

begin_struct
struct|struct
name|bitmap
block|{
name|short
name|h
decl_stmt|,
name|w
decl_stmt|;
comment|/* height and width in pixels */
name|short
name|bytes_wide
decl_stmt|;
comment|/* scan-line width in bytes */
name|char
modifier|*
name|bits
decl_stmt|;
comment|/* pointer to the bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAXCHARS
value|128
end_define

begin_comment
comment|/* make 256 for 8 bit characters */
end_comment

begin_comment
comment|/*  * Per-character information.  * There is one of these for each character in a font.  * All fields are filled in at font definition time,  * except for the bitmap, which is "faulted in"  * when the character is first referenced.  */
end_comment

begin_struct
struct|struct
name|glyph
block|{
name|long
name|addr
decl_stmt|;
comment|/* address of bitmap in PXL file */
name|long
name|dvi_adv
decl_stmt|;
comment|/* DVI units to move reference point */
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
comment|/* x and y offset in pixels */
name|struct
name|bitmap
name|bitmap
decl_stmt|;
comment|/* bitmap for character */
name|short
name|pxl_adv
decl_stmt|;
comment|/* pixels to move reference point */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The layout of a font information block.  * There is one of these for every loaded font or  * magnification thereof.  *  * Also note the strange units.  The design size is in 1/2^20 point  * units (also called micro-points), and the individual character widths  * are in the TFM file in 1/2^20 ems units, i.e. relative to the design size.  */
end_comment

begin_struct
struct|struct
name|font
block|{
name|struct
name|font
modifier|*
name|next
decl_stmt|;
comment|/* link to next font info block */
name|struct
name|font
modifier|*
name|prev
decl_stmt|;
comment|/* link to previous font info block */
name|int
name|TeXnumber
decl_stmt|;
comment|/* font number (in DVI file) */
name|int
name|scale
decl_stmt|;
comment|/* scaled size in DVI units */
name|int
name|design
decl_stmt|;
comment|/* design size in DVI units */
name|char
modifier|*
name|fontname
decl_stmt|;
comment|/* PXL file name */
name|FILE
modifier|*
name|file
decl_stmt|;
comment|/* open PXL file or NULL */
name|struct
name|glyph
name|glyph
index|[
name|MAXCHARS
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

