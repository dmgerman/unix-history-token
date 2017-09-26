begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MSFCommon.h - Common types and functions for MSF files ---*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_MSFCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_MSFCOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|msf
block|{
specifier|static
specifier|const
name|char
name|Magic
index|[]
init|=
block|{
literal|'M'
block|,
literal|'i'
block|,
literal|'c'
block|,
literal|'r'
block|,
literal|'o'
block|,
literal|'s'
block|,
literal|'o'
block|,
literal|'f'
block|,
literal|'t'
block|,
literal|' '
block|,
literal|'C'
block|,
literal|'/'
block|,
literal|'C'
block|,
literal|'+'
block|,
literal|'+'
block|,
literal|' '
block|,
literal|'M'
block|,
literal|'S'
block|,
literal|'F'
block|,
literal|' '
block|,
literal|'7'
block|,
literal|'.'
block|,
literal|'0'
block|,
literal|'0'
block|,
literal|'\r'
block|,
literal|'\n'
block|,
literal|'\x1a'
block|,
literal|'D'
block|,
literal|'S'
block|,
literal|'\0'
block|,
literal|'\0'
block|,
literal|'\0'
block|}
decl_stmt|;
comment|// The superblock is overlaid at the beginning of the file (offset 0).
comment|// It starts with a magic header and is followed by information which
comment|// describes the layout of the file system.
struct|struct
name|SuperBlock
block|{
name|char
name|MagicBytes
index|[
sizeof|sizeof
argument_list|(
name|Magic
argument_list|)
index|]
decl_stmt|;
comment|// The file system is split into a variable number of fixed size elements.
comment|// These elements are referred to as blocks.  The size of a block may vary
comment|// from system to system.
name|support
operator|::
name|ulittle32_t
name|BlockSize
expr_stmt|;
comment|// The index of the free block map.
name|support
operator|::
name|ulittle32_t
name|FreeBlockMapBlock
expr_stmt|;
comment|// This contains the number of blocks resident in the file system.  In
comment|// practice, NumBlocks * BlockSize is equivalent to the size of the MSF
comment|// file.
name|support
operator|::
name|ulittle32_t
name|NumBlocks
expr_stmt|;
comment|// This contains the number of bytes which make up the directory.
name|support
operator|::
name|ulittle32_t
name|NumDirectoryBytes
expr_stmt|;
comment|// This field's purpose is not yet known.
name|support
operator|::
name|ulittle32_t
name|Unknown1
expr_stmt|;
comment|// This contains the block # of the block map.
name|support
operator|::
name|ulittle32_t
name|BlockMapAddr
expr_stmt|;
block|}
struct|;
struct|struct
name|MSFLayout
block|{
name|MSFLayout
argument_list|()
operator|=
expr|default
expr_stmt|;
specifier|const
name|SuperBlock
modifier|*
name|SB
init|=
name|nullptr
decl_stmt|;
name|BitVector
name|FreePageMap
decl_stmt|;
name|ArrayRef
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|DirectoryBlocks
expr_stmt|;
name|ArrayRef
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|StreamSizes
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ArrayRef
operator|<
name|support
operator|::
name|ulittle32_t
operator|>>
name|StreamMap
expr_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|isValidBlockSize
parameter_list|(
name|uint32_t
name|Size
parameter_list|)
block|{
switch|switch
condition|(
name|Size
condition|)
block|{
case|case
literal|512
case|:
case|case
literal|1024
case|:
case|case
literal|2048
case|:
case|case
literal|4096
case|:
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|// Super Block, Fpm0, Fpm1, and Block Map
specifier|inline
name|uint32_t
name|getMinimumBlockCount
parameter_list|()
block|{
return|return
literal|4
return|;
block|}
comment|// Super Block, Fpm0, and Fpm1 are reserved.  The Block Map, although required
comment|// need not be at block 3.
specifier|inline
name|uint32_t
name|getFirstUnreservedBlock
parameter_list|()
block|{
return|return
literal|3
return|;
block|}
specifier|inline
name|uint64_t
name|bytesToBlocks
parameter_list|(
name|uint64_t
name|NumBytes
parameter_list|,
name|uint64_t
name|BlockSize
parameter_list|)
block|{
return|return
name|alignTo
argument_list|(
name|NumBytes
argument_list|,
name|BlockSize
argument_list|)
operator|/
name|BlockSize
return|;
block|}
specifier|inline
name|uint64_t
name|blockToOffset
parameter_list|(
name|uint64_t
name|BlockNumber
parameter_list|,
name|uint64_t
name|BlockSize
parameter_list|)
block|{
return|return
name|BlockNumber
operator|*
name|BlockSize
return|;
block|}
specifier|inline
name|uint32_t
name|getFpmIntervalLength
parameter_list|(
specifier|const
name|MSFLayout
modifier|&
name|L
parameter_list|)
block|{
return|return
name|L
operator|.
name|SB
operator|->
name|BlockSize
return|;
block|}
specifier|inline
name|uint32_t
name|getNumFpmIntervals
parameter_list|(
specifier|const
name|MSFLayout
modifier|&
name|L
parameter_list|)
block|{
name|uint32_t
name|Length
init|=
name|getFpmIntervalLength
argument_list|(
name|L
argument_list|)
decl_stmt|;
return|return
name|alignTo
argument_list|(
name|L
operator|.
name|SB
operator|->
name|NumBlocks
argument_list|,
name|Length
argument_list|)
operator|/
name|Length
return|;
block|}
specifier|inline
name|uint32_t
name|getFullFpmByteSize
parameter_list|(
specifier|const
name|MSFLayout
modifier|&
name|L
parameter_list|)
block|{
return|return
name|alignTo
argument_list|(
name|L
operator|.
name|SB
operator|->
name|NumBlocks
argument_list|,
literal|8
argument_list|)
operator|/
literal|8
return|;
block|}
name|Error
name|validateSuperBlock
parameter_list|(
specifier|const
name|SuperBlock
modifier|&
name|SB
parameter_list|)
function_decl|;
block|}
comment|// end namespace msf
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_MSF_MSFCOMMON_H
end_comment

end_unit

