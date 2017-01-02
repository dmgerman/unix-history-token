begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MSFStreamLayout.h - Describes the layout of a stream -----*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_MSFSTREAMLAYOUT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_MSFSTREAMLAYOUT_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
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
comment|/// \brief Describes the layout of a stream in an MSF layout.  A "stream" here
comment|/// is defined as any logical unit of data which may be arranged inside the MSF
comment|/// file as a sequence of (possibly discontiguous) blocks.  When we want to read
comment|/// from a particular MSF Stream, we fill out a stream layout structure and the
comment|/// reader uses it to determine which blocks in the underlying MSF file contain
comment|/// the data, so that it can be pieced together in the right order.
name|class
name|MSFStreamLayout
block|{
name|public
label|:
name|uint32_t
name|Length
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|Blocks
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace msf
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_MSF_MSFSTREAMLAYOUT_H
end_comment

end_unit

