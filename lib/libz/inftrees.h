begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inftrees.h -- header to use inftrees.c  * Copyright (C) 1995-2002 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
end_comment

begin_comment
comment|/* WARNING: this file should *not* be used by applications. It is    part of the implementation of the compression library and is    subject to change. Applications should only use zlib.h.  */
end_comment

begin_comment
comment|/* Huffman code lookup table entry--this entry is four bytes for machines    that have 16-bit pointers (e.g. PC's in the small or medium model). */
end_comment

begin_typedef
typedef|typedef
name|struct
name|inflate_huft_s
name|FAR
name|inflate_huft
typedef|;
end_typedef

begin_struct
struct|struct
name|inflate_huft_s
block|{
union|union
block|{
struct|struct
block|{
name|Byte
name|Exop
decl_stmt|;
comment|/* number of extra bits or operation */
name|Byte
name|Bits
decl_stmt|;
comment|/* number of bits in this code or subcode */
block|}
name|what
struct|;
name|uInt
name|pad
decl_stmt|;
comment|/* pad structure to a power of 2 (4 bytes for */
block|}
name|word
union|;
comment|/*  16-bit, 8 bytes for 32-bit int's) */
name|uInt
name|base
decl_stmt|;
comment|/* literal, length base, distance base,                            or table offset */
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum size of dynamic tree.  The maximum found in a long but non-    exhaustive search was 1004 huft structures (850 for length/literals    and 154 for distances, the latter actually the result of an    exhaustive search).  The actual maximum is not known, but the    value below is more than safe. */
end_comment

begin_define
define|#
directive|define
name|MANY
value|1440
end_define

begin_decl_stmt
specifier|extern
name|int
name|inflate_trees_bits
name|OF
argument_list|(
operator|(
name|uIntf
operator|*
operator|,
comment|/* 19 code lengths */
name|uIntf
operator|*
operator|,
comment|/* bits tree desired/actual depth */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* bits tree result */
name|inflate_huft
operator|*
operator|,
comment|/* space for trees */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_trees_dynamic
name|OF
argument_list|(
operator|(
name|uInt
operator|,
comment|/* number of literal/length codes */
name|uInt
operator|,
comment|/* number of distance codes */
name|uIntf
operator|*
operator|,
comment|/* that many (total) code lengths */
name|uIntf
operator|*
operator|,
comment|/* literal desired/actual bit depth */
name|uIntf
operator|*
operator|,
comment|/* distance desired/actual bit depth */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* literal/length tree result */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* distance tree result */
name|inflate_huft
operator|*
operator|,
comment|/* space for trees */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_trees_fixed
name|OF
argument_list|(
operator|(
name|uIntf
operator|*
operator|,
comment|/* literal desired/actual bit depth */
name|uIntf
operator|*
operator|,
comment|/* distance desired/actual bit depth */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* literal/length tree result */
name|inflate_huft
operator|*
name|FAR
operator|*
operator|,
comment|/* distance tree result */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for memory allocation */
end_comment

end_unit

