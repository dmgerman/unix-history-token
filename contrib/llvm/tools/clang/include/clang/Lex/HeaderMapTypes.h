begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- HeaderMapTypes.h - Types for the header map format -------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LEX_HEADERMAPTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_HEADERMAPTYPES_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
enum|enum
block|{
name|HMAP_HeaderMagicNumber
init|=
operator|(
literal|'h'
operator|<<
literal|24
operator|)
operator||
operator|(
literal|'m'
operator|<<
literal|16
operator|)
operator||
operator|(
literal|'a'
operator|<<
literal|8
operator|)
operator||
literal|'p'
block|,
name|HMAP_HeaderVersion
init|=
literal|1
block|,
name|HMAP_EmptyBucketKey
init|=
literal|0
block|}
enum|;
struct|struct
name|HMapBucket
block|{
name|uint32_t
name|Key
decl_stmt|;
comment|// Offset (into strings) of key.
name|uint32_t
name|Prefix
decl_stmt|;
comment|// Offset (into strings) of value prefix.
name|uint32_t
name|Suffix
decl_stmt|;
comment|// Offset (into strings) of value suffix.
block|}
struct|;
struct|struct
name|HMapHeader
block|{
name|uint32_t
name|Magic
decl_stmt|;
comment|// Magic word, also indicates byte order.
name|uint16_t
name|Version
decl_stmt|;
comment|// Version number -- currently 1.
name|uint16_t
name|Reserved
decl_stmt|;
comment|// Reserved for future use - zero for now.
name|uint32_t
name|StringsOffset
decl_stmt|;
comment|// Offset to start of string pool.
name|uint32_t
name|NumEntries
decl_stmt|;
comment|// Number of entries in the string table.
name|uint32_t
name|NumBuckets
decl_stmt|;
comment|// Number of buckets (always a power of 2).
name|uint32_t
name|MaxValueLength
decl_stmt|;
comment|// Length of longest result path (excluding nul).
comment|// An array of 'NumBuckets' HMapBucket objects follows this header.
comment|// Strings follow the buckets, at StringsOffset.
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

