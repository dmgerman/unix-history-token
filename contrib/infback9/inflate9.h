begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inflate9.h -- internal inflate state definition  * Copyright (C) 1995-2003 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h  */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_comment
comment|/* Possible inflate modes between inflate() calls */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TYPE
block|,
comment|/* i: waiting for type bits, including last-flag bit */
name|STORED
block|,
comment|/* i: waiting for stored size (length and complement) */
name|TABLE
block|,
comment|/* i: waiting for dynamic block table lengths */
name|LEN
block|,
comment|/* i: waiting for length/lit code */
name|DONE
block|,
comment|/* finished check, done -- remain here until reset */
name|BAD
comment|/* got a data error -- remain here until reset */
block|}
name|inflate_mode
typedef|;
end_typedef

begin_comment
comment|/*     State transitions between above modes -      (most modes can go to the BAD mode -- not shown for clarity)      Read deflate blocks:             TYPE -> STORED or TABLE or LEN or DONE             STORED -> TYPE             TABLE -> LENLENS -> CODELENS -> LEN     Read deflate codes:                 LEN -> LEN or TYPE  */
end_comment

begin_comment
comment|/* state maintained between inflate() calls.  Approximately 7K bytes. */
end_comment

begin_struct
struct|struct
name|inflate_state
block|{
comment|/* sliding window */
name|unsigned
name|char
name|FAR
modifier|*
name|window
decl_stmt|;
comment|/* allocated sliding window, if needed */
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

