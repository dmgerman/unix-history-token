begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	xfont.h	1.1	87/02/05  *  * This file defines the structure that lives at the beginning of the  * "strike" format font file - the font format used for the X window system.  * The strike bitmap has the following structure.  Characters are layed  * out logically right next to each other in consecutive bits in the bitmap.  * The "leftArray" contains the bit offset of the character in the stream  * of bits.  A sample bitmap and resulting offsets are shown below:  *  * leftArray:	0     6     12   17    23        33   38    44   49  53   58      *		|     |     |    |     |         |    |     |    |   |    |     * start:	..@...@@@@...@@@.@@@@...@@...@@..@@@@..@@@@.@..@.@@@.@@@@. . .  * each line	.@.@..@...@.@.....@..@.@..@.@..@.@....@.....@..@..@....@..  * continues	@...@.@@@@..@.....@..@.@...@...@.@@@..@.@@@.@@@@..@....@... . .  * at the next	@@@@@.@...@.@.....@..@..@@...@@..@....@...@.@..@..@..@.@..  * short after	@...@.@@@@...@@@.@@@@.....@.@....@.....@@@@.@..@.@@@.@.@.. . .  * the last line...........................@..............@...........@...  */
end_comment

begin_struct
struct|struct
name|FontData
block|{
name|int
name|bitmapPtr
decl_stmt|;
comment|/* offset to strike bitmap in the file */
name|short
name|bmWidth
decl_stmt|;
comment|/* width of the bitmap (in pixels) */
name|short
name|bmHeight
decl_stmt|;
comment|/* bitmap height (pixels) */
name|short
name|bitsPerPixel
decl_stmt|;
comment|/* for color? */
name|short
name|firstChar
decl_stmt|;
comment|/* first character in the font (usually 0) */
name|short
name|lastChar
decl_stmt|;
comment|/* index of last character (usually 127) */
name|short
name|leftArray
decl_stmt|;
comment|/* offset in file to array of char offsets */
name|short
name|waste
decl_stmt|;
name|short
name|baseline
decl_stmt|;
comment|/* offset from top to baseline (or zero) */
name|short
name|spaceIndex
decl_stmt|;
comment|/* the space character (always 32?) */
name|short
name|fixedWidth
decl_stmt|;
comment|/* the width of each character or zero */
block|}
struct|;
end_struct

end_unit

