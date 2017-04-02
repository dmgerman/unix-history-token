begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- IMSFFile.h - Abstract base class for an MSF file ---------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_IMSFFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_IMSFFILE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
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
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|msf
block|{
name|class
name|IMSFFile
block|{
name|public
label|:
name|virtual
operator|~
name|IMSFFile
argument_list|()
operator|=
expr|default
expr_stmt|;
name|virtual
name|uint32_t
name|getBlockSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getBlockCount
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getNumStreams
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|uint32_t
name|getStreamByteSize
argument_list|(
name|uint32_t
name|StreamIndex
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|ArrayRef
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|getStreamBlockList
argument_list|(
argument|uint32_t StreamIndex
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|Expected
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
name|getBlockData
argument_list|(
argument|uint32_t BlockIndex
argument_list|,
argument|uint32_t NumBytes
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|Error
name|setBlockData
argument_list|(
name|uint32_t
name|BlockIndex
argument_list|,
name|uint32_t
name|Offset
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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
comment|// LLVM_DEBUGINFO_MSF_IMSFFILE_H
end_comment

end_unit

