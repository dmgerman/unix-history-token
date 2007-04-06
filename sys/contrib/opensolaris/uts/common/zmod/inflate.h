begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inflate.h -- internal inflate state definition  * Copyright (C) 1995-2004 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
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
comment|/* define NO_GZIP when compiling if you want to disable gzip header and    trailer decoding by inflate().  NO_GZIP would be used to avoid linking in    the crc code when it is not needed.  For shared libraries, gzip decoding    should be left enabled. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NO_GZIP
end_ifndef

begin_define
define|#
directive|define
name|GUNZIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Possible inflate modes between inflate() calls */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|HEAD
block|,
comment|/* i: waiting for magic header */
name|FLAGS
block|,
comment|/* i: waiting for method and flags (gzip) */
name|TIME
block|,
comment|/* i: waiting for modification time (gzip) */
name|OS
block|,
comment|/* i: waiting for extra flags and operating system (gzip) */
name|EXLEN
block|,
comment|/* i: waiting for extra length (gzip) */
name|EXTRA
block|,
comment|/* i: waiting for extra bytes (gzip) */
name|NAME
block|,
comment|/* i: waiting for end of file name (gzip) */
name|COMMENT
block|,
comment|/* i: waiting for end of comment (gzip) */
name|HCRC
block|,
comment|/* i: waiting for header crc (gzip) */
name|DICTID
block|,
comment|/* i: waiting for dictionary check value */
name|DICT
block|,
comment|/* waiting for inflateSetDictionary() call */
name|TYPE
block|,
comment|/* i: waiting for type bits, including last-flag bit */
name|TYPEDO
block|,
comment|/* i: same, but skip check to exit inflate on new block */
name|STORED
block|,
comment|/* i: waiting for stored size (length and complement) */
name|COPY
block|,
comment|/* i/o: waiting for input or output to copy stored block */
name|TABLE
block|,
comment|/* i: waiting for dynamic block table lengths */
name|LENLENS
block|,
comment|/* i: waiting for code length code lengths */
name|CODELENS
block|,
comment|/* i: waiting for length/lit and distance code lengths */
name|LEN
block|,
comment|/* i: waiting for length/lit code */
name|LENEXT
block|,
comment|/* i: waiting for length extra bits */
name|DIST
block|,
comment|/* i: waiting for distance code */
name|DISTEXT
block|,
comment|/* i: waiting for distance extra bits */
name|MATCH
block|,
comment|/* o: waiting for output space to copy string */
name|LIT
block|,
comment|/* o: waiting for output space to write literal */
name|CHECK
block|,
comment|/* i: waiting for 32-bit check value */
name|LENGTH
block|,
comment|/* i: waiting for 32-bit length (gzip) */
name|DONE
block|,
comment|/* finished check, done -- remain here until reset */
name|BAD
block|,
comment|/* got a data error -- remain here until reset */
name|MEM
block|,
comment|/* got an inflate() memory error -- remain here until reset */
name|SYNC
comment|/* looking for synchronization bytes to restart inflate() */
block|}
name|inflate_mode
typedef|;
end_typedef

begin_comment
comment|/*     State transitions between above modes -      (most modes can go to the BAD or MEM mode -- not shown for clarity)      Process header:         HEAD -> (gzip) or (zlib)         (gzip) -> FLAGS -> TIME -> OS -> EXLEN -> EXTRA -> NAME         NAME -> COMMENT -> HCRC -> TYPE         (zlib) -> DICTID or TYPE         DICTID -> DICT -> TYPE     Read deflate blocks:             TYPE -> STORED or TABLE or LEN or CHECK             STORED -> COPY -> TYPE             TABLE -> LENLENS -> CODELENS -> LEN     Read deflate codes:                 LEN -> LENEXT or LIT or TYPE                 LENEXT -> DIST -> DISTEXT -> MATCH -> LEN                 LIT -> LEN     Process trailer:         CHECK -> LENGTH -> DONE  */
end_comment

begin_comment
comment|/* state maintained between inflate() calls.  Approximately 7K bytes. */
end_comment

begin_struct
struct|struct
name|inflate_state
block|{
name|inflate_mode
name|mode
decl_stmt|;
comment|/* current inflate mode */
name|int
name|last
decl_stmt|;
comment|/* true if processing last block */
name|int
name|wrap
decl_stmt|;
comment|/* bit 0 true for zlib, bit 1 true for gzip */
name|int
name|havedict
decl_stmt|;
comment|/* true if dictionary provided */
name|int
name|flags
decl_stmt|;
comment|/* gzip header method and flags (0 if zlib) */
name|unsigned
name|dmax
decl_stmt|;
comment|/* zlib header max distance (INFLATE_STRICT) */
name|unsigned
name|long
name|check
decl_stmt|;
comment|/* protected copy of check value */
name|unsigned
name|long
name|total
decl_stmt|;
comment|/* protected copy of output count */
name|gz_headerp
name|head
decl_stmt|;
comment|/* where to save gzip header information */
comment|/* sliding window */
name|unsigned
name|wbits
decl_stmt|;
comment|/* log base 2 of requested window size */
name|unsigned
name|wsize
decl_stmt|;
comment|/* window size or zero if not using window */
name|unsigned
name|whave
decl_stmt|;
comment|/* valid bytes in the window */
name|unsigned
name|write
decl_stmt|;
comment|/* window write index */
name|unsigned
name|char
name|FAR
modifier|*
name|window
decl_stmt|;
comment|/* allocated sliding window, if needed */
comment|/* bit accumulator */
name|unsigned
name|long
name|hold
decl_stmt|;
comment|/* input bit accumulator */
name|unsigned
name|bits
decl_stmt|;
comment|/* number of bits in "in" */
comment|/* for string and stored block copying */
name|unsigned
name|length
decl_stmt|;
comment|/* literal or length of data to copy */
name|unsigned
name|offset
decl_stmt|;
comment|/* distance back to copy string from */
comment|/* for table and code decoding */
name|unsigned
name|extra
decl_stmt|;
comment|/* extra bits needed */
comment|/* fixed and dynamic code tables */
name|code
specifier|const
name|FAR
modifier|*
name|lencode
decl_stmt|;
comment|/* starting table for length/literal codes */
name|code
specifier|const
name|FAR
modifier|*
name|distcode
decl_stmt|;
comment|/* starting table for distance codes */
name|unsigned
name|lenbits
decl_stmt|;
comment|/* index bits for lencode */
name|unsigned
name|distbits
decl_stmt|;
comment|/* index bits for distcode */
comment|/* dynamic table building */
name|unsigned
name|ncode
decl_stmt|;
comment|/* number of code length code lengths */
name|unsigned
name|nlen
decl_stmt|;
comment|/* number of length code lengths */
name|unsigned
name|ndist
decl_stmt|;
comment|/* number of distance code lengths */
name|unsigned
name|have
decl_stmt|;
comment|/* number of code lengths in lens[] */
name|code
name|FAR
modifier|*
name|next
decl_stmt|;
comment|/* next available space in codes[] */
name|unsigned
name|short
name|lens
index|[
literal|320
index|]
decl_stmt|;
comment|/* temporary storage for code lengths */
name|unsigned
name|short
name|work
index|[
literal|288
index|]
decl_stmt|;
comment|/* work area for code table building */
name|code
name|codes
index|[
name|ENOUGH
index|]
decl_stmt|;
comment|/* space for code tables */
block|}
struct|;
end_struct

end_unit

