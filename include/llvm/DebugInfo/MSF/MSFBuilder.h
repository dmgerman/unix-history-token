begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MSFBuilder.h - MSF Directory& Metadata Builder ----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_MSFBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_MSFBUILDER_H
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
file|"llvm/DebugInfo/MSF/MSFCommon.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|class
name|MSFBuilder
block|{
name|public
label|:
comment|/// \brief Create a new `MSFBuilder`.
comment|///
comment|/// \param BlockSize The internal block size used by the PDB file.  See
comment|/// isValidBlockSize() for a list of valid block sizes.
comment|///
comment|/// \param MinBlockCount Causes the builder to reserve up front space for
comment|/// at least `MinBlockCount` blocks.  This is useful when using `MSFBuilder`
comment|/// to read an existing MSF that you want to write back out later.  The
comment|/// original MSF file's SuperBlock contains the exact number of blocks used
comment|/// by the file, so is a good hint as to how many blocks the new MSF file
comment|/// will contain.  Furthermore, it is actually necessary in this case.  To
comment|/// preserve stability of the file's layout, it is helpful to try to keep
comment|/// all streams mapped to their original block numbers.  To ensure that this
comment|/// is possible, space for all blocks must be allocated beforehand so that
comment|/// streams can be assigned to them.
comment|///
comment|/// \param CanGrow If true, any operation which results in an attempt to
comment|/// locate a free block when all available blocks have been exhausted will
comment|/// allocate a new block, thereby growing the size of the final MSF file.
comment|/// When false, any such attempt will result in an error.  This is especially
comment|/// useful in testing scenarios when you know your test isn't going to do
comment|/// anything to increase the size of the file, so having an Error returned if
comment|/// it were to happen would catch a programming error
comment|///
comment|/// \returns an llvm::Error representing whether the operation succeeded or
comment|/// failed.  Currently the only way this can fail is if an invalid block size
comment|/// is specified, or `MinBlockCount` does not leave enough room for the
comment|/// mandatory reserved blocks required by an MSF file.
specifier|static
name|Expected
operator|<
name|MSFBuilder
operator|>
name|create
argument_list|(
argument|BumpPtrAllocator&Allocator
argument_list|,
argument|uint32_t BlockSize
argument_list|,
argument|uint32_t MinBlockCount =
literal|0
argument_list|,
argument|bool CanGrow = true
argument_list|)
expr_stmt|;
comment|/// Request the block map to be at a specific block address.  This is useful
comment|/// when editing a MSF and you want the layout to be as stable as possible.
name|Error
name|setBlockMapAddr
parameter_list|(
name|uint32_t
name|Addr
parameter_list|)
function_decl|;
name|Error
name|setDirectoryBlocksHint
argument_list|(
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|DirBlocks
argument_list|)
decl_stmt|;
name|void
name|setFreePageMap
parameter_list|(
name|uint32_t
name|Fpm
parameter_list|)
function_decl|;
name|void
name|setUnknown1
parameter_list|(
name|uint32_t
name|Unk1
parameter_list|)
function_decl|;
comment|/// Add a stream to the MSF file with the given size, occupying the given
comment|/// list of blocks.  This is useful when reading a MSF file and you want a
comment|/// particular stream to occupy the original set of blocks.  If the given
comment|/// blocks are already allocated, or if the number of blocks specified is
comment|/// incorrect for the given stream size, this function will return an Error.
name|Expected
operator|<
name|uint32_t
operator|>
name|addStream
argument_list|(
argument|uint32_t Size
argument_list|,
argument|ArrayRef<uint32_t> Blocks
argument_list|)
expr_stmt|;
comment|/// Add a stream to the MSF file with the given size, occupying any available
comment|/// blocks that the builder decides to use.  This is useful when building a
comment|/// new PDB file from scratch and you don't care what blocks a stream occupies
comment|/// but you just want it to work.
name|Expected
operator|<
name|uint32_t
operator|>
name|addStream
argument_list|(
argument|uint32_t Size
argument_list|)
expr_stmt|;
comment|/// Update the size of an existing stream.  This will allocate or deallocate
comment|/// blocks as needed to match the requested size.  This can fail if `CanGrow`
comment|/// was set to false when initializing the `MSFBuilder`.
name|Error
name|setStreamSize
parameter_list|(
name|uint32_t
name|Idx
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
comment|/// Get the total number of streams in the MSF layout.  This should return 1
comment|/// for every call to `addStream`.
name|uint32_t
name|getNumStreams
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the size of a stream by index.
name|uint32_t
name|getStreamSize
argument_list|(
name|uint32_t
name|StreamIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the list of blocks allocated to a particular stream.
name|ArrayRef
operator|<
name|uint32_t
operator|>
name|getStreamBlocks
argument_list|(
argument|uint32_t StreamIdx
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get the total number of blocks that will be allocated to actual data in
comment|/// this MSF file.
name|uint32_t
name|getNumUsedBlocks
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the total number of blocks that exist in the MSF file but are not
comment|/// allocated to any valid data.
name|uint32_t
name|getNumFreeBlocks
argument_list|()
specifier|const
expr_stmt|;
comment|/// Get the total number of blocks in the MSF file.  In practice this is equal
comment|/// to `getNumUsedBlocks() + getNumFreeBlocks()`.
name|uint32_t
name|getTotalBlockCount
argument_list|()
specifier|const
expr_stmt|;
comment|/// Check whether a particular block is allocated or free.
name|bool
name|isBlockFree
argument_list|(
name|uint32_t
name|Idx
argument_list|)
decl|const
decl_stmt|;
comment|/// Finalize the layout and build the headers and structures that describe the
comment|/// MSF layout and can be written directly to the MSF file.
name|Expected
operator|<
name|MSFLayout
operator|>
name|build
argument_list|()
expr_stmt|;
name|BumpPtrAllocator
modifier|&
name|getAllocator
parameter_list|()
block|{
return|return
name|Allocator
return|;
block|}
name|private
label|:
name|MSFBuilder
argument_list|(
argument|uint32_t BlockSize
argument_list|,
argument|uint32_t MinBlockCount
argument_list|,
argument|bool CanGrow
argument_list|,
argument|BumpPtrAllocator&Allocator
argument_list|)
empty_stmt|;
name|Error
name|allocateBlocks
argument_list|(
name|uint32_t
name|NumBlocks
argument_list|,
name|MutableArrayRef
operator|<
name|uint32_t
operator|>
name|Blocks
argument_list|)
decl_stmt|;
name|uint32_t
name|computeDirectoryByteSize
argument_list|()
specifier|const
expr_stmt|;
name|using
name|BlockList
init|=
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
decl_stmt|;
name|BumpPtrAllocator
modifier|&
name|Allocator
decl_stmt|;
name|bool
name|IsGrowable
decl_stmt|;
name|uint32_t
name|FreePageMap
decl_stmt|;
name|uint32_t
name|Unknown1
init|=
literal|0
decl_stmt|;
name|uint32_t
name|BlockSize
decl_stmt|;
name|uint32_t
name|MininumBlocks
decl_stmt|;
name|uint32_t
name|BlockMapAddr
decl_stmt|;
name|BitVector
name|FreeBlocks
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|DirectoryBlocks
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|BlockList
operator|>>
name|StreamData
expr_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_MSF_MSFBUILDER_H
end_comment

end_unit

