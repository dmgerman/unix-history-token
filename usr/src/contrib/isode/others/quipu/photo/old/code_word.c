begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* code_word.c - define code words for one dimensional encoding */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid
init|=
literal|"$Header: /f/osi/others/quipu/photo/RCS/code_word.c,v 7.0 89/11/23 22:01:34 mrose Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * $Header: /f/osi/others/quipu/photo/RCS/code_word.c,v 7.0 89/11/23 22:01:34 mrose Rel $  *  *  * $Log:	code_word.c,v $  * Revision 7.0  89/11/23  22:01:34  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"quipu/photo.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|PIC_LINESIZE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following are declarations of the code words that are used with one /* dimensional encoding.   The first number in each pair give the length /* of the string, the second gives the string in hex, starting at the 13th bit /* position. /* The declarations are made this way so that the arays are made at compile /* time as opposed to run time. */
end_comment

begin_comment
comment|/* White terminal run lengths */
end_comment

begin_decl_stmt
specifier|static
name|code_word
name|wt_term
index|[]
init|=
block|{
block|{
literal|8
block|,
literal|0x6a0
block|}
block|,
comment|/* 0 : 00110101      */
block|{
literal|6
block|,
literal|0x380
block|}
block|,
comment|/* 1 : 000111        */
block|{
literal|4
block|,
literal|0xe00
block|}
block|,
comment|/* 2 : 0111          */
block|{
literal|4
block|,
literal|0x1000
block|}
block|,
comment|/* 3 : 1000          */
block|{
literal|4
block|,
literal|0x1600
block|}
block|,
comment|/* 4 : 1011          */
block|{
literal|4
block|,
literal|0x1800
block|}
block|,
comment|/* 5 : 1100          */
block|{
literal|4
block|,
literal|0x1c00
block|}
block|,
comment|/* 6 : 1110          */
block|{
literal|4
block|,
literal|0x1e00
block|}
block|,
comment|/* 7 : 1111          */
block|{
literal|5
block|,
literal|0x1300
block|}
block|,
comment|/* 8 : 10011         */
block|{
literal|5
block|,
literal|0x1400
block|}
block|,
comment|/* 9 : 10100         */
block|{
literal|5
block|,
literal|0x700
block|}
block|,
comment|/* 10: 00111         */
block|{
literal|5
block|,
literal|0x800
block|}
block|,
comment|/* 11: 01000         */
block|{
literal|6
block|,
literal|0x400
block|}
block|,
comment|/* 12: 001000        */
block|{
literal|6
block|,
literal|0x180
block|}
block|,
comment|/* 13: 000011        */
block|{
literal|6
block|,
literal|0x1a00
block|}
block|,
comment|/* 14: 110100        */
block|{
literal|6
block|,
literal|0x1a80
block|}
block|,
comment|/* 15: 110101        */
block|{
literal|6
block|,
literal|0x1500
block|}
block|,
comment|/* 16: 101010        */
block|{
literal|6
block|,
literal|0x1580
block|}
block|,
comment|/* 17: 101011        */
block|{
literal|7
block|,
literal|0x9c0
block|}
block|,
comment|/* 18: 0100111       */
block|{
literal|7
block|,
literal|0x300
block|}
block|,
comment|/* 19: 0001100       */
block|{
literal|7
block|,
literal|0x200
block|}
block|,
comment|/* 20: 0001000       */
block|{
literal|7
block|,
literal|0x5c0
block|}
block|,
comment|/* 21: 0010111       */
block|{
literal|7
block|,
literal|0xc0
block|}
block|,
comment|/* 22: 0000011       */
block|{
literal|7
block|,
literal|0x100
block|}
block|,
comment|/* 23: 0000100       */
block|{
literal|7
block|,
literal|0xa00
block|}
block|,
comment|/* 24: 0101000       */
block|{
literal|7
block|,
literal|0xac0
block|}
block|,
comment|/* 25: 0101011       */
block|{
literal|7
block|,
literal|0x4c0
block|}
block|,
comment|/* 26: 0010011       */
block|{
literal|7
block|,
literal|0x900
block|}
block|,
comment|/* 27: 0100100       */
block|{
literal|7
block|,
literal|0x600
block|}
block|,
comment|/* 28: 0011000       */
block|{
literal|8
block|,
literal|0x40
block|}
block|,
comment|/* 29: 00000010      */
block|{
literal|8
block|,
literal|0x60
block|}
block|,
comment|/* 30: 00000011      */
block|{
literal|8
block|,
literal|0x340
block|}
block|,
comment|/* 31: 00011010      */
block|{
literal|8
block|,
literal|0x360
block|}
block|,
comment|/* 32: 00011011      */
block|{
literal|8
block|,
literal|0x240
block|}
block|,
comment|/* 33: 00010010      */
block|{
literal|8
block|,
literal|0x260
block|}
block|,
comment|/* 34: 00010011      */
block|{
literal|8
block|,
literal|0x280
block|}
block|,
comment|/* 35: 00010100      */
block|{
literal|8
block|,
literal|0x2a0
block|}
block|,
comment|/* 36: 00010101      */
block|{
literal|8
block|,
literal|0x2c0
block|}
block|,
comment|/* 37: 00010110      */
block|{
literal|8
block|,
literal|0x2e0
block|}
block|,
comment|/* 38: 00010111      */
block|{
literal|8
block|,
literal|0x500
block|}
block|,
comment|/* 39: 00101000      */
block|{
literal|8
block|,
literal|0x520
block|}
block|,
comment|/* 40: 00101001      */
block|{
literal|8
block|,
literal|0x540
block|}
block|,
comment|/* 41: 00101010      */
block|{
literal|8
block|,
literal|0x560
block|}
block|,
comment|/* 42: 00101011      */
block|{
literal|8
block|,
literal|0x580
block|}
block|,
comment|/* 43: 00101100      */
block|{
literal|8
block|,
literal|0x5a0
block|}
block|,
comment|/* 44: 00101101      */
block|{
literal|8
block|,
literal|0x80
block|}
block|,
comment|/* 45: 00000100      */
block|{
literal|8
block|,
literal|0xa0
block|}
block|,
comment|/* 46: 00000101      */
block|{
literal|8
block|,
literal|0x140
block|}
block|,
comment|/* 47: 00001010      */
block|{
literal|8
block|,
literal|0x160
block|}
block|,
comment|/* 48: 00001011      */
block|{
literal|8
block|,
literal|0xa40
block|}
block|,
comment|/* 49: 01010010      */
block|{
literal|8
block|,
literal|0xa60
block|}
block|,
comment|/* 50: 01010011      */
block|{
literal|8
block|,
literal|0xa80
block|}
block|,
comment|/* 51: 01010100      */
block|{
literal|8
block|,
literal|0xaa0
block|}
block|,
comment|/* 52: 01010101      */
block|{
literal|8
block|,
literal|0x480
block|}
block|,
comment|/* 53: 00100100      */
block|{
literal|8
block|,
literal|0x4a0
block|}
block|,
comment|/* 54: 00100101      */
block|{
literal|8
block|,
literal|0xb00
block|}
block|,
comment|/* 55: 01011000      */
block|{
literal|8
block|,
literal|0xb20
block|}
block|,
comment|/* 56: 01011001      */
block|{
literal|8
block|,
literal|0xb40
block|}
block|,
comment|/* 57: 01011010      */
block|{
literal|8
block|,
literal|0xb60
block|}
block|,
comment|/* 58: 01011011      */
block|{
literal|8
block|,
literal|0x940
block|}
block|,
comment|/* 59: 01001010      */
block|{
literal|8
block|,
literal|0x960
block|}
block|,
comment|/* 60: 01001011      */
block|{
literal|8
block|,
literal|0x640
block|}
block|,
comment|/* 61: 00110010      */
block|{
literal|8
block|,
literal|0x660
block|}
block|,
comment|/* 62: 00110011      */
block|{
literal|8
block|,
literal|0x680
block|}
block|,
comment|/* 63: 00110100      */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Black terminal run lengths */
end_comment

begin_decl_stmt
specifier|static
name|code_word
name|bl_term
index|[]
init|=
block|{
block|{
literal|10
block|,
literal|0x1b8
block|}
block|,
comment|/* 0 : 0000110111    */
block|{
literal|3
block|,
literal|0x800
block|}
block|,
comment|/* 1 : 010           */
block|{
literal|2
block|,
literal|0x1800
block|}
block|,
comment|/* 2 : 11            */
block|{
literal|2
block|,
literal|0x1000
block|}
block|,
comment|/* 3 : 10            */
block|{
literal|3
block|,
literal|0xc00
block|}
block|,
comment|/* 4 : 011           */
block|{
literal|4
block|,
literal|0x600
block|}
block|,
comment|/* 5 : 0011          */
block|{
literal|4
block|,
literal|0x400
block|}
block|,
comment|/* 6 : 0010          */
block|{
literal|5
block|,
literal|0x300
block|}
block|,
comment|/* 7 : 00011         */
block|{
literal|6
block|,
literal|0x280
block|}
block|,
comment|/* 8 : 000101        */
block|{
literal|6
block|,
literal|0x200
block|}
block|,
comment|/* 9 : 000100        */
block|{
literal|7
block|,
literal|0x100
block|}
block|,
comment|/* 10: 0000100       */
block|{
literal|7
block|,
literal|0x140
block|}
block|,
comment|/* 11: 0000101       */
block|{
literal|7
block|,
literal|0x1c0
block|}
block|,
comment|/* 12: 0000111       */
block|{
literal|8
block|,
literal|0x80
block|}
block|,
comment|/* 13: 00000100      */
block|{
literal|8
block|,
literal|0xe0
block|}
block|,
comment|/* 14: 00000111      */
block|{
literal|9
block|,
literal|0x180
block|}
block|,
comment|/* 15: 000011000     */
block|{
literal|10
block|,
literal|0xb8
block|}
block|,
comment|/* 16: 0000010111    */
block|{
literal|10
block|,
literal|0xc0
block|}
block|,
comment|/* 17: 0000011000    */
block|{
literal|10
block|,
literal|0x40
block|}
block|,
comment|/* 18: 0000001000    */
block|{
literal|11
block|,
literal|0x19c
block|}
block|,
comment|/* 19: 00001100111   */
block|{
literal|11
block|,
literal|0x1a0
block|}
block|,
comment|/* 20: 00001101000   */
block|{
literal|11
block|,
literal|0x1b0
block|}
block|,
comment|/* 21: 00001101100   */
block|{
literal|11
block|,
literal|0xdc
block|}
block|,
comment|/* 22: 00000110111   */
block|{
literal|11
block|,
literal|0xa0
block|}
block|,
comment|/* 23: 00000101000   */
block|{
literal|11
block|,
literal|0x5c
block|}
block|,
comment|/* 24: 00000010111   */
block|{
literal|11
block|,
literal|0x60
block|}
block|,
comment|/* 25: 00000011000   */
block|{
literal|12
block|,
literal|0x194
block|}
block|,
comment|/* 26: 000011001010  */
block|{
literal|12
block|,
literal|0x196
block|}
block|,
comment|/* 27: 000011001011  */
block|{
literal|12
block|,
literal|0x198
block|}
block|,
comment|/* 28: 000011001100  */
block|{
literal|12
block|,
literal|0x19a
block|}
block|,
comment|/* 29: 000011001101  */
block|{
literal|12
block|,
literal|0xd0
block|}
block|,
comment|/* 30: 000001101000  */
block|{
literal|12
block|,
literal|0xd2
block|}
block|,
comment|/* 31: 000001101001  */
block|{
literal|12
block|,
literal|0xd4
block|}
block|,
comment|/* 32: 000001101010  */
block|{
literal|12
block|,
literal|0xd6
block|}
block|,
comment|/* 33: 000001101011  */
block|{
literal|12
block|,
literal|0x1a4
block|}
block|,
comment|/* 34: 000011010010  */
block|{
literal|12
block|,
literal|0x1a6
block|}
block|,
comment|/* 35: 000011010011  */
block|{
literal|12
block|,
literal|0x1a8
block|}
block|,
comment|/* 36: 000011010100  */
block|{
literal|12
block|,
literal|0x1aa
block|}
block|,
comment|/* 37: 000011010101  */
block|{
literal|12
block|,
literal|0x1ac
block|}
block|,
comment|/* 38: 000011010110  */
block|{
literal|12
block|,
literal|0x1ae
block|}
block|,
comment|/* 39: 000011010111  */
block|{
literal|12
block|,
literal|0xd8
block|}
block|,
comment|/* 40: 000001101100  */
block|{
literal|12
block|,
literal|0xda
block|}
block|,
comment|/* 41: 000001101101  */
block|{
literal|12
block|,
literal|0x1b4
block|}
block|,
comment|/* 42: 000011011010  */
block|{
literal|12
block|,
literal|0x1b6
block|}
block|,
comment|/* 43: 000011011011  */
block|{
literal|12
block|,
literal|0xa8
block|}
block|,
comment|/* 44: 000001010100  */
block|{
literal|12
block|,
literal|0xaa
block|}
block|,
comment|/* 45: 000001010101  */
block|{
literal|12
block|,
literal|0xac
block|}
block|,
comment|/* 46: 000001010110  */
block|{
literal|12
block|,
literal|0xae
block|}
block|,
comment|/* 47: 000001010111  */
block|{
literal|12
block|,
literal|0xc8
block|}
block|,
comment|/* 48: 000001100100  */
block|{
literal|12
block|,
literal|0xca
block|}
block|,
comment|/* 49: 000001100101  */
block|{
literal|12
block|,
literal|0xa4
block|}
block|,
comment|/* 50: 000001010010  */
block|{
literal|12
block|,
literal|0xa6
block|}
block|,
comment|/* 51: 000001010011  */
block|{
literal|12
block|,
literal|0x48
block|}
block|,
comment|/* 52: 000000100100  */
block|{
literal|12
block|,
literal|0x6e
block|}
block|,
comment|/* 53: 000000110111  */
block|{
literal|12
block|,
literal|0x70
block|}
block|,
comment|/* 54: 000000111000  */
block|{
literal|12
block|,
literal|0x4e
block|}
block|,
comment|/* 55: 000000100111  */
block|{
literal|12
block|,
literal|0x50
block|}
block|,
comment|/* 56: 000000101000  */
block|{
literal|12
block|,
literal|0xb0
block|}
block|,
comment|/* 57: 000001011000  */
block|{
literal|12
block|,
literal|0xb2
block|}
block|,
comment|/* 58: 000001011001  */
block|{
literal|12
block|,
literal|0x56
block|}
block|,
comment|/* 59: 000000101011  */
block|{
literal|12
block|,
literal|0x58
block|}
block|,
comment|/* 60: 000000101100  */
block|{
literal|12
block|,
literal|0xb4
block|}
block|,
comment|/* 61: 000001011010  */
block|{
literal|12
block|,
literal|0xcc
block|}
block|,
comment|/* 62: 000001100110  */
block|{
literal|12
block|,
literal|0xce
block|}
block|,
comment|/* 63: 000001100111  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* White make up codes */
end_comment

begin_decl_stmt
specifier|static
name|code_word
name|wt_make
index|[]
init|=
block|{
block|{
literal|5
block|,
literal|0x1b00
block|}
block|,
comment|/* 64  : 11011         */
block|{
literal|5
block|,
literal|0x1200
block|}
block|,
comment|/* 128 : 10010         */
block|{
literal|6
block|,
literal|0xb80
block|}
block|,
comment|/* 192 : 010111        */
block|{
literal|7
block|,
literal|0xdc0
block|}
block|,
comment|/* 256 : 0110111       */
block|{
literal|8
block|,
literal|0x6c0
block|}
block|,
comment|/* 320 : 00110110      */
block|{
literal|8
block|,
literal|0x6e0
block|}
block|,
comment|/* 384 : 00110111      */
block|{
literal|8
block|,
literal|0xc80
block|}
block|,
comment|/* 448 : 01100100      */
block|{
literal|8
block|,
literal|0xca0
block|}
block|,
comment|/* 512 : 01100101      */
block|{
literal|8
block|,
literal|0xd00
block|}
block|,
comment|/* 576 : 01101000      */
block|{
literal|8
block|,
literal|0xce0
block|}
block|,
comment|/* 640 : 01100111      */
block|{
literal|9
block|,
literal|0xcc0
block|}
block|,
comment|/* 704 : 011001100     */
block|{
literal|9
block|,
literal|0xcd0
block|}
block|,
comment|/* 768 : 011001101     */
block|{
literal|9
block|,
literal|0xd20
block|}
block|,
comment|/* 832 : 011010010     */
block|{
literal|9
block|,
literal|0xd30
block|}
block|,
comment|/* 896 : 011010011     */
block|{
literal|9
block|,
literal|0xd40
block|}
block|,
comment|/* 960 : 011010100     */
block|{
literal|9
block|,
literal|0xd50
block|}
block|,
comment|/* 1024: 011010101     */
block|{
literal|9
block|,
literal|0xd60
block|}
block|,
comment|/* 1088: 011010110     */
block|{
literal|9
block|,
literal|0xd70
block|}
block|,
comment|/* 1152: 011010111     */
block|{
literal|9
block|,
literal|0xd80
block|}
block|,
comment|/* 1216: 011011000     */
block|{
literal|9
block|,
literal|0xd90
block|}
block|,
comment|/* 1280: 011011001     */
block|{
literal|9
block|,
literal|0xda0
block|}
block|,
comment|/* 1344: 011011010     */
block|{
literal|9
block|,
literal|0xdb0
block|}
block|,
comment|/* 1408: 011011011     */
block|{
literal|9
block|,
literal|0x980
block|}
block|,
comment|/* 1472: 010011000     */
block|{
literal|9
block|,
literal|0x990
block|}
block|,
comment|/* 1536: 010011001     */
block|{
literal|9
block|,
literal|0x9a0
block|}
block|,
comment|/* 1600: 010011010     */
block|{
literal|6
block|,
literal|0xc00
block|}
block|,
comment|/* 1664: 011000        */
block|{
literal|9
block|,
literal|0x9b0
block|}
block|,
comment|/* 1728: 010011011     */
block|{
literal|11
block|,
literal|0x20
block|}
block|,
comment|/* 1792: 00000001000   */
block|{
literal|11
block|,
literal|0x30
block|}
block|,
comment|/* 1856: 00000001100   */
block|{
literal|11
block|,
literal|0x34
block|}
block|,
comment|/* 1920: 00000001101   */
block|{
literal|12
block|,
literal|0x24
block|}
block|,
comment|/* 1984: 000000010010  */
block|{
literal|12
block|,
literal|0x26
block|}
block|,
comment|/* 2048: 000000010011  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Black make up codes */
end_comment

begin_decl_stmt
specifier|static
name|code_word
name|bl_make
index|[]
init|=
block|{
block|{
literal|10
block|,
literal|0x78
block|}
block|,
comment|/* 64  : 0000001111    */
block|{
literal|12
block|,
literal|0x190
block|}
block|,
comment|/* 128 : 000011001000  */
block|{
literal|12
block|,
literal|0x192
block|}
block|,
comment|/* 192 : 000011001001  */
block|{
literal|12
block|,
literal|0xb6
block|}
block|,
comment|/* 256 : 000001011011  */
block|{
literal|12
block|,
literal|0x66
block|}
block|,
comment|/* 320 : 000000110011  */
block|{
literal|12
block|,
literal|0x68
block|}
block|,
comment|/* 384 : 000000110100  */
block|{
literal|12
block|,
literal|0x6a
block|}
block|,
comment|/* 448 : 000000110101  */
block|{
literal|13
block|,
literal|0x6c
block|}
block|,
comment|/* 512 : 0000001101100 */
block|{
literal|13
block|,
literal|0x6d
block|}
block|,
comment|/* 576 : 0000001101101 */
block|{
literal|13
block|,
literal|0x4a
block|}
block|,
comment|/* 640 : 0000001001010 */
block|{
literal|13
block|,
literal|0x4b
block|}
block|,
comment|/* 704 : 0000001001011 */
block|{
literal|13
block|,
literal|0x4c
block|}
block|,
comment|/* 768 : 0000001001100 */
block|{
literal|13
block|,
literal|0x4d
block|}
block|,
comment|/* 832 : 0000001001101 */
block|{
literal|13
block|,
literal|0x72
block|}
block|,
comment|/* 896 : 0000001110010 */
block|{
literal|13
block|,
literal|0x73
block|}
block|,
comment|/* 960 : 0000001110011 */
block|{
literal|13
block|,
literal|0x74
block|}
block|,
comment|/* 1024: 0000001110100 */
block|{
literal|13
block|,
literal|0x75
block|}
block|,
comment|/* 1088: 0000001110101 */
block|{
literal|13
block|,
literal|0x76
block|}
block|,
comment|/* 1152: 0000001110110 */
block|{
literal|13
block|,
literal|0x77
block|}
block|,
comment|/* 1216: 0000001110111 */
block|{
literal|13
block|,
literal|0x52
block|}
block|,
comment|/* 1280: 0000001010010 */
block|{
literal|13
block|,
literal|0x53
block|}
block|,
comment|/* 1344: 0000001010011 */
block|{
literal|13
block|,
literal|0x54
block|}
block|,
comment|/* 1408: 0000001010100 */
block|{
literal|13
block|,
literal|0x55
block|}
block|,
comment|/* 1472: 0000001010101 */
block|{
literal|13
block|,
literal|0x5a
block|}
block|,
comment|/* 1536: 0000001011010 */
block|{
literal|13
block|,
literal|0x5b
block|}
block|,
comment|/* 1600: 0000001011011 */
block|{
literal|13
block|,
literal|0x64
block|}
block|,
comment|/* 1664: 0000001100100 */
block|{
literal|13
block|,
literal|0x65
block|}
block|,
comment|/* 1728: 0000001100101 */
block|{
literal|11
block|,
literal|0x20
block|}
block|,
comment|/* 1792: 00000001000   */
block|{
literal|11
block|,
literal|0x30
block|}
block|,
comment|/* 1856: 00000001100   */
block|{
literal|11
block|,
literal|0x34
block|}
block|,
comment|/* 1920: 00000001101   */
block|{
literal|12
block|,
literal|0x24
block|}
block|,
comment|/* 1984: 000000010010  */
block|{
literal|12
block|,
literal|0x26
block|}
block|,
comment|/* 2048: 000000010011  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ROUTINE:     Get_code ()                                             */
end_comment

begin_comment
comment|/*                                                                      */
end_comment

begin_comment
comment|/* SYNOPSIS:    Gets a code word from an array given the run_length     */
end_comment

begin_comment
comment|/*              and the colour (0 = white, 1 = black)                   */
end_comment

begin_function
name|full_code
name|get_code
parameter_list|(
name|run
parameter_list|,
name|colour
parameter_list|)
name|char
name|colour
decl_stmt|;
name|int
name|run
decl_stmt|;
block|{
name|full_code
name|result
decl_stmt|;
name|result
operator|.
name|make
operator|.
name|length
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|run
operator|>
name|PIC_LINESIZE
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Run too long\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|colour
operator|==
name|WHITE
condition|)
block|{
if|if
condition|(
name|run
operator|>
literal|63
condition|)
name|result
operator|.
name|make
operator|=
name|wt_make
index|[
operator|(
name|run
operator|/
literal|64
operator|)
operator|-
literal|1
index|]
expr_stmt|;
name|result
operator|.
name|term
operator|=
name|wt_term
index|[
name|run
operator|%
literal|64
index|]
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|run
operator|>
literal|63
condition|)
name|result
operator|.
name|make
operator|=
name|bl_make
index|[
operator|(
name|run
operator|/
literal|64
operator|)
operator|-
literal|1
index|]
expr_stmt|;
name|result
operator|.
name|term
operator|=
name|bl_term
index|[
name|run
operator|%
literal|64
index|]
expr_stmt|;
block|}
return|return
operator|(
name|result
operator|)
return|;
block|}
end_function

end_unit

