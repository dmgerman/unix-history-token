begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inftrees.h -- header to use inftrees.c  * Copyright (C) 1995-1996 Mark Adler  * For conditions of distribution and use, see copyright notice in zlib.h   */
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
name|Bytef
modifier|*
name|pad
decl_stmt|;
comment|/* pad structure to a power of 2 (4 bytes for */
block|}
name|word
union|;
comment|/*  16-bit, 8 bytes for 32-bit machines) */
union|union
block|{
name|uInt
name|Base
decl_stmt|;
comment|/* literal, length base, or distance base */
name|inflate_huft
modifier|*
name|Next
decl_stmt|;
comment|/* pointer to next level of table */
block|}
name|more
union|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|uInt
name|inflate_hufts
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for zalloc, zfree functions */
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
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for zalloc, zfree functions */
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* distance tree result */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inflate_trees_free
name|OF
argument_list|(
operator|(
name|inflate_huft
operator|*
operator|,
comment|/* tables to free */
name|z_streamp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* for zfree function */
end_comment

end_unit

