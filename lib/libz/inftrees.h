begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inftrees.h -- header to use inftrees.c  * Copyright (C) 1995-2005, 2010 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_comment
comment|/* Structure for decoding tables.  Each entry provides either the    information needed to do the operation requested by the code that    indexed that table entry, or it provides a pointer to another    table that indexes more bits of the code.  op indicates whether    the entry is a pointer to another table, a literal, a length or    distance, an end-of-block, or an invalid code.  For a table    pointer, the low four bits of op is the number of index bits of    that table.  For a length or distance, the low four bits of op    is the number of extra bits to get after the code.  bits is    the number of bits in this code or part of the code to drop off    of the bit buffer.  val is the actual byte to output in the case    of a literal, the base length or distance, or the offset from    the current table to the next table.  Each entry is four bytes. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|op
decl_stmt|;
comment|/* operation, extra bits, table bits */
name|unsigned
name|char
name|bits
decl_stmt|;
comment|/* bits in this part of the code */
name|unsigned
name|short
name|val
decl_stmt|;
comment|/* offset in table or code value */
block|}
name|code
typedef|;
end_typedef

begin_comment
comment|/* op values as set by inflate_table():     00000000 - literal     0000tttt - table link, tttt != 0 is the number of table index bits     0001eeee - length or distance, eeee is the number of extra bits     01100000 - end of block     01000000 - invalid code  */
end_comment

begin_comment
comment|/* Maximum size of the dynamic table.  The maximum number of code structures is    1444, which is the sum of 852 for literal/length codes and 592 for distance    codes.  These values were found by exhaustive searches using the program    examples/enough.c found in the zlib distribtution.  The arguments to that    program are the number of symbols, the initial root table size, and the    maximum bit length of a code.  "enough 286 9 15" for literal/length codes    returns returns 852, and "enough 30 6 15" for distance codes returns 592.    The initial root table size (9 or 6) is found in the fifth argument of the    inflate_table() calls in inflate.c and infback.c.  If the root table size is    changed, then these maximum sizes would be need to be recalculated and    updated. */
end_comment

begin_define
define|#
directive|define
name|ENOUGH_LENS
value|852
end_define

begin_define
define|#
directive|define
name|ENOUGH_DISTS
value|592
end_define

begin_define
define|#
directive|define
name|ENOUGH
value|(ENOUGH_LENS+ENOUGH_DISTS)
end_define

begin_comment
comment|/* Type of code to build for inflate_table() */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CODES
block|,
name|LENS
block|,
name|DISTS
block|}
name|codetype
typedef|;
end_typedef

begin_decl_stmt
name|int
name|ZLIB_INTERNAL
name|inflate_table
name|OF
argument_list|(
operator|(
name|codetype
name|type
operator|,
name|unsigned
name|short
name|FAR
operator|*
name|lens
operator|,
name|unsigned
name|codes
operator|,
name|code
name|FAR
operator|*
name|FAR
operator|*
name|table
operator|,
name|unsigned
name|FAR
operator|*
name|bits
operator|,
name|unsigned
name|short
name|FAR
operator|*
name|work
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

