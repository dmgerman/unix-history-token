begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **	@(#)rdboot.c	7.1 (Berkeley) 1/22/88 */
end_comment

begin_comment
comment|/* ** This is a VMB boot block for microvax.  For more info, see ** the KA-630 User's manual. */
end_comment

begin_comment
comment|/* **          --------------------------------------------------- ** BB + 0: |      1     |      N     |      any value          | **          --------------------------------------------------- */
end_comment

begin_label
name|xxx
label|:
end_label

begin_expr_stmt
operator|.
name|long
literal|0x001040000
comment|/* **          --------------------------------------------------- **      4: |        low  lbn         |      high lbn           | **          --------------------------------------------------- */
operator|.
name|long
literal|0x000010000
comment|/* ** BB + 2*N **          --------------------------------------------------- **    + 0: | check byte |      K     |     0     |   18 (HEX)  | **          --------------------------------------------------- */
operator|.
name|long
literal|0x0e7000018
comment|/* **          --------------------------------------------------- **    + 4: |     any  value          |  1 or 81  |      0      | **          --------------------------------------------------- */
operator|.
name|long
literal|0x000008100
comment|/* **          --------------------------------------------------- **    + 8: |     size in blocks of the image                   | **          --------------------------------------------------- */
operator|.
name|long
literal|0x00000000f
comment|/* **          --------------------------------------------------- **    +12: |     load offset from default load address         | **          --------------------------------------------------- */
operator|.
name|long
literal|0x000000000
comment|/* **          --------------------------------------------------- **    +16: |     offset into image to start execution          | **          --------------------------------------------------- */
operator|.
name|long
literal|0x000000002
comment|/* **          --------------------------------------------------- **    +20: |     sum of previous three longwords               | **          --------------------------------------------------- */
operator|.
name|long
literal|0x000000011
end_expr_stmt

begin_comment
comment|/* ** ** BB +0:	These two bytes can have any value ** ** BB+2:	This value is the word offset from the start of the **		bootblock to the identification area described below. ** ** BB+3:	This byte must be one. ** ** BB+4:	This longword contains the logical block number **		(word swapped) of the secondary image. ** ** BB+(2*n)+0:	This byte defines the expected instruction set. **		18(hex) means VAX. ** ** BB+(2*n)+1:	This byte defines the expected controller type, 0 **		means unknown. ** ** BB+(2*n)+2:	This byte defines the file structure on the volume, **		it may be any value. ** ** BB+(2*n)+3:	This byte must be the ones complement of the sum of **		the previous three bytes. ** ** BB+(2*n)+4:	This byte must be zero. ** ** BB+(2*n)+5:	This byte must be 1 or 81 (hex).  This byte defines **		the version number of the format standard and the **		type of disk.  The version is one, the high bit is 0 **		for single sided, 1 for double sided. ** ** BB+(2*n)+6:	These two bytes may be any value, but generally they **		are zero. ** ** BB+(2*n)+8:	This entry is a longword containing the size in **		blocks of the secondary bootstrap image. ** ** BB+(2*n)+12:	This entry is a longword containing a load offset **		(usually zero) from the default load address of the **		secondary bootstrap. ** ** BB+(2*n)+16:	This entry is a longword containing the byte offset **		into the secondary bootstrap where execution is to **		begin. ** ** BB+(2*n)+20:	This entry is a longword containing the sum of the **		previous three longwords. */
end_comment

end_unit

