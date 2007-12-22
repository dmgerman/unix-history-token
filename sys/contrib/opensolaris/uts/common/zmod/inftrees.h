begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inftrees.h -- header to use inftrees.c  * Copyright (C) 1995-2005 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

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
comment|/* Maximum size of dynamic tree.  The maximum found in a long but non-    exhaustive search was 1444 code structures (852 for length/literals    and 592 for distances, the latter actually the result of an    exhaustive search).  The true maximum is not known, but the value    below is more than safe. */
end_comment

begin_define
define|#
directive|define
name|ENOUGH
value|2048
end_define

begin_define
define|#
directive|define
name|MAXD
value|592
end_define

begin_comment
comment|/* Type of code to build for inftable() */
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
specifier|extern
name|int
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

