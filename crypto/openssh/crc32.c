begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The implementation here was originally done by Gary S. Brown.  * I have borrowed the tables directly, and made some minor changes  * to the crc32-function (including changing the interface).  * //ylo  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: crc32.c,v 1.4 1999/11/24 00:26:01 deraadt Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|"crc32.h"
end_include

begin_comment
comment|/* ============================================================= */
end_comment

begin_comment
comment|/*  COPYRIGHT (C) 1986 Gary S. Brown.  You may use this program, or       */
end_comment

begin_comment
comment|/*  code or tables extracted from it, as desired without restriction.     */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*  First, the polynomial itself and its table of feedback terms.  The    */
end_comment

begin_comment
comment|/*  polynomial is                                                         */
end_comment

begin_comment
comment|/*  X^32+X^26+X^23+X^22+X^16+X^12+X^11+X^10+X^8+X^7+X^5+X^4+X^2+X^1+X^0   */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*  Note that we take it "backwards" and put the highest-order term in    */
end_comment

begin_comment
comment|/*  the lowest-order bit.  The X^32 term is "implied"; the LSB is the     */
end_comment

begin_comment
comment|/*  X^31 term, etc.  The X^0 term (usually shown as "+1") results in      */
end_comment

begin_comment
comment|/*  the MSB being 1.                                                      */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*  Note that the usual hardware shift register implementation, which     */
end_comment

begin_comment
comment|/*  is what we're using (we're merely optimizing it by doing eight-bit    */
end_comment

begin_comment
comment|/*  chunks at a time) shifts bits into the lowest-order term.  In our     */
end_comment

begin_comment
comment|/*  implementation, that means shifting towards the right.  Why do we     */
end_comment

begin_comment
comment|/*  do it this way?  Because the calculated CRC must be transmitted in    */
end_comment

begin_comment
comment|/*  order from highest-order term to lowest-order term.  UARTs transmit   */
end_comment

begin_comment
comment|/*  characters in order from LSB to MSB.  By storing the CRC this way,    */
end_comment

begin_comment
comment|/*  we hand it to the UART in the order low-byte to high-byte; the UART   */
end_comment

begin_comment
comment|/*  sends each low-bit to hight-bit; and the result is transmission bit   */
end_comment

begin_comment
comment|/*  by bit from highest- to lowest-order term without requiring any bit   */
end_comment

begin_comment
comment|/*  shuffling on our part.  Reception works similarly.                    */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*  The feedback terms table consists of 256, 32-bit entries.  Notes:     */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*      The table can be generated at runtime if desired; code to do so   */
end_comment

begin_comment
comment|/*      is shown later.  It might not be obvious, but the feedback        */
end_comment

begin_comment
comment|/*      terms simply represent the results of eight shift/xor opera-      */
end_comment

begin_comment
comment|/*      tions for all combinations of data and CRC register values.       */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*      The values must be right-shifted by eight bits by the "updcrc"    */
end_comment

begin_comment
comment|/*      logic; the shift must be unsigned (bring in zeroes).  On some     */
end_comment

begin_comment
comment|/*      hardware you could probably optimize the shift in assembler by    */
end_comment

begin_comment
comment|/*      using byte-swap instructions.                                     */
end_comment

begin_comment
comment|/*      polynomial $edb88320                                              */
end_comment

begin_comment
comment|/*                                                                        */
end_comment

begin_comment
comment|/*  --------------------------------------------------------------------  */
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|crc32_tab
index|[]
init|=
block|{
literal|0x00000000L
block|,
literal|0x77073096L
block|,
literal|0xee0e612cL
block|,
literal|0x990951baL
block|,
literal|0x076dc419L
block|,
literal|0x706af48fL
block|,
literal|0xe963a535L
block|,
literal|0x9e6495a3L
block|,
literal|0x0edb8832L
block|,
literal|0x79dcb8a4L
block|,
literal|0xe0d5e91eL
block|,
literal|0x97d2d988L
block|,
literal|0x09b64c2bL
block|,
literal|0x7eb17cbdL
block|,
literal|0xe7b82d07L
block|,
literal|0x90bf1d91L
block|,
literal|0x1db71064L
block|,
literal|0x6ab020f2L
block|,
literal|0xf3b97148L
block|,
literal|0x84be41deL
block|,
literal|0x1adad47dL
block|,
literal|0x6ddde4ebL
block|,
literal|0xf4d4b551L
block|,
literal|0x83d385c7L
block|,
literal|0x136c9856L
block|,
literal|0x646ba8c0L
block|,
literal|0xfd62f97aL
block|,
literal|0x8a65c9ecL
block|,
literal|0x14015c4fL
block|,
literal|0x63066cd9L
block|,
literal|0xfa0f3d63L
block|,
literal|0x8d080df5L
block|,
literal|0x3b6e20c8L
block|,
literal|0x4c69105eL
block|,
literal|0xd56041e4L
block|,
literal|0xa2677172L
block|,
literal|0x3c03e4d1L
block|,
literal|0x4b04d447L
block|,
literal|0xd20d85fdL
block|,
literal|0xa50ab56bL
block|,
literal|0x35b5a8faL
block|,
literal|0x42b2986cL
block|,
literal|0xdbbbc9d6L
block|,
literal|0xacbcf940L
block|,
literal|0x32d86ce3L
block|,
literal|0x45df5c75L
block|,
literal|0xdcd60dcfL
block|,
literal|0xabd13d59L
block|,
literal|0x26d930acL
block|,
literal|0x51de003aL
block|,
literal|0xc8d75180L
block|,
literal|0xbfd06116L
block|,
literal|0x21b4f4b5L
block|,
literal|0x56b3c423L
block|,
literal|0xcfba9599L
block|,
literal|0xb8bda50fL
block|,
literal|0x2802b89eL
block|,
literal|0x5f058808L
block|,
literal|0xc60cd9b2L
block|,
literal|0xb10be924L
block|,
literal|0x2f6f7c87L
block|,
literal|0x58684c11L
block|,
literal|0xc1611dabL
block|,
literal|0xb6662d3dL
block|,
literal|0x76dc4190L
block|,
literal|0x01db7106L
block|,
literal|0x98d220bcL
block|,
literal|0xefd5102aL
block|,
literal|0x71b18589L
block|,
literal|0x06b6b51fL
block|,
literal|0x9fbfe4a5L
block|,
literal|0xe8b8d433L
block|,
literal|0x7807c9a2L
block|,
literal|0x0f00f934L
block|,
literal|0x9609a88eL
block|,
literal|0xe10e9818L
block|,
literal|0x7f6a0dbbL
block|,
literal|0x086d3d2dL
block|,
literal|0x91646c97L
block|,
literal|0xe6635c01L
block|,
literal|0x6b6b51f4L
block|,
literal|0x1c6c6162L
block|,
literal|0x856530d8L
block|,
literal|0xf262004eL
block|,
literal|0x6c0695edL
block|,
literal|0x1b01a57bL
block|,
literal|0x8208f4c1L
block|,
literal|0xf50fc457L
block|,
literal|0x65b0d9c6L
block|,
literal|0x12b7e950L
block|,
literal|0x8bbeb8eaL
block|,
literal|0xfcb9887cL
block|,
literal|0x62dd1ddfL
block|,
literal|0x15da2d49L
block|,
literal|0x8cd37cf3L
block|,
literal|0xfbd44c65L
block|,
literal|0x4db26158L
block|,
literal|0x3ab551ceL
block|,
literal|0xa3bc0074L
block|,
literal|0xd4bb30e2L
block|,
literal|0x4adfa541L
block|,
literal|0x3dd895d7L
block|,
literal|0xa4d1c46dL
block|,
literal|0xd3d6f4fbL
block|,
literal|0x4369e96aL
block|,
literal|0x346ed9fcL
block|,
literal|0xad678846L
block|,
literal|0xda60b8d0L
block|,
literal|0x44042d73L
block|,
literal|0x33031de5L
block|,
literal|0xaa0a4c5fL
block|,
literal|0xdd0d7cc9L
block|,
literal|0x5005713cL
block|,
literal|0x270241aaL
block|,
literal|0xbe0b1010L
block|,
literal|0xc90c2086L
block|,
literal|0x5768b525L
block|,
literal|0x206f85b3L
block|,
literal|0xb966d409L
block|,
literal|0xce61e49fL
block|,
literal|0x5edef90eL
block|,
literal|0x29d9c998L
block|,
literal|0xb0d09822L
block|,
literal|0xc7d7a8b4L
block|,
literal|0x59b33d17L
block|,
literal|0x2eb40d81L
block|,
literal|0xb7bd5c3bL
block|,
literal|0xc0ba6cadL
block|,
literal|0xedb88320L
block|,
literal|0x9abfb3b6L
block|,
literal|0x03b6e20cL
block|,
literal|0x74b1d29aL
block|,
literal|0xead54739L
block|,
literal|0x9dd277afL
block|,
literal|0x04db2615L
block|,
literal|0x73dc1683L
block|,
literal|0xe3630b12L
block|,
literal|0x94643b84L
block|,
literal|0x0d6d6a3eL
block|,
literal|0x7a6a5aa8L
block|,
literal|0xe40ecf0bL
block|,
literal|0x9309ff9dL
block|,
literal|0x0a00ae27L
block|,
literal|0x7d079eb1L
block|,
literal|0xf00f9344L
block|,
literal|0x8708a3d2L
block|,
literal|0x1e01f268L
block|,
literal|0x6906c2feL
block|,
literal|0xf762575dL
block|,
literal|0x806567cbL
block|,
literal|0x196c3671L
block|,
literal|0x6e6b06e7L
block|,
literal|0xfed41b76L
block|,
literal|0x89d32be0L
block|,
literal|0x10da7a5aL
block|,
literal|0x67dd4accL
block|,
literal|0xf9b9df6fL
block|,
literal|0x8ebeeff9L
block|,
literal|0x17b7be43L
block|,
literal|0x60b08ed5L
block|,
literal|0xd6d6a3e8L
block|,
literal|0xa1d1937eL
block|,
literal|0x38d8c2c4L
block|,
literal|0x4fdff252L
block|,
literal|0xd1bb67f1L
block|,
literal|0xa6bc5767L
block|,
literal|0x3fb506ddL
block|,
literal|0x48b2364bL
block|,
literal|0xd80d2bdaL
block|,
literal|0xaf0a1b4cL
block|,
literal|0x36034af6L
block|,
literal|0x41047a60L
block|,
literal|0xdf60efc3L
block|,
literal|0xa867df55L
block|,
literal|0x316e8eefL
block|,
literal|0x4669be79L
block|,
literal|0xcb61b38cL
block|,
literal|0xbc66831aL
block|,
literal|0x256fd2a0L
block|,
literal|0x5268e236L
block|,
literal|0xcc0c7795L
block|,
literal|0xbb0b4703L
block|,
literal|0x220216b9L
block|,
literal|0x5505262fL
block|,
literal|0xc5ba3bbeL
block|,
literal|0xb2bd0b28L
block|,
literal|0x2bb45a92L
block|,
literal|0x5cb36a04L
block|,
literal|0xc2d7ffa7L
block|,
literal|0xb5d0cf31L
block|,
literal|0x2cd99e8bL
block|,
literal|0x5bdeae1dL
block|,
literal|0x9b64c2b0L
block|,
literal|0xec63f226L
block|,
literal|0x756aa39cL
block|,
literal|0x026d930aL
block|,
literal|0x9c0906a9L
block|,
literal|0xeb0e363fL
block|,
literal|0x72076785L
block|,
literal|0x05005713L
block|,
literal|0x95bf4a82L
block|,
literal|0xe2b87a14L
block|,
literal|0x7bb12baeL
block|,
literal|0x0cb61b38L
block|,
literal|0x92d28e9bL
block|,
literal|0xe5d5be0dL
block|,
literal|0x7cdcefb7L
block|,
literal|0x0bdbdf21L
block|,
literal|0x86d3d2d4L
block|,
literal|0xf1d4e242L
block|,
literal|0x68ddb3f8L
block|,
literal|0x1fda836eL
block|,
literal|0x81be16cdL
block|,
literal|0xf6b9265bL
block|,
literal|0x6fb077e1L
block|,
literal|0x18b74777L
block|,
literal|0x88085ae6L
block|,
literal|0xff0f6a70L
block|,
literal|0x66063bcaL
block|,
literal|0x11010b5cL
block|,
literal|0x8f659effL
block|,
literal|0xf862ae69L
block|,
literal|0x616bffd3L
block|,
literal|0x166ccf45L
block|,
literal|0xa00ae278L
block|,
literal|0xd70dd2eeL
block|,
literal|0x4e048354L
block|,
literal|0x3903b3c2L
block|,
literal|0xa7672661L
block|,
literal|0xd06016f7L
block|,
literal|0x4969474dL
block|,
literal|0x3e6e77dbL
block|,
literal|0xaed16a4aL
block|,
literal|0xd9d65adcL
block|,
literal|0x40df0b66L
block|,
literal|0x37d83bf0L
block|,
literal|0xa9bcae53L
block|,
literal|0xdebb9ec5L
block|,
literal|0x47b2cf7fL
block|,
literal|0x30b5ffe9L
block|,
literal|0xbdbdf21cL
block|,
literal|0xcabac28aL
block|,
literal|0x53b39330L
block|,
literal|0x24b4a3a6L
block|,
literal|0xbad03605L
block|,
literal|0xcdd70693L
block|,
literal|0x54de5729L
block|,
literal|0x23d967bfL
block|,
literal|0xb3667a2eL
block|,
literal|0xc4614ab8L
block|,
literal|0x5d681b02L
block|,
literal|0x2a6f2b94L
block|,
literal|0xb40bbe37L
block|,
literal|0xc30c8ea1L
block|,
literal|0x5a05df1bL
block|,
literal|0x2d02ef8dL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a 32-bit CRC of the contents of the buffer. */
end_comment

begin_function
name|unsigned
name|int
name|crc32
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
name|unsigned
name|int
name|crc32val
decl_stmt|;
name|crc32val
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|len
condition|;
name|i
operator|++
control|)
block|{
name|crc32val
operator|=
name|crc32_tab
index|[
operator|(
name|crc32val
operator|^
name|s
index|[
name|i
index|]
operator|)
operator|&
literal|0xff
index|]
operator|^
operator|(
name|crc32val
operator|>>
literal|8
operator|)
expr_stmt|;
block|}
return|return
name|crc32val
return|;
block|}
end_function

end_unit

