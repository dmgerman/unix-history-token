begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CodeView.h - On-disk record types for CodeView ----------*- C++ -*-===//
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

begin_comment
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file provides data structures useful for consuming on-disk
end_comment

begin_comment
comment|/// CodeView. It is based on information published by Microsoft at
end_comment

begin_comment
comment|/// https://github.com/Microsoft/microsoft-pdb/.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// FIXME: Find a home for this in include/llvm/DebugInfo/CodeView/.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_READOBJ_CODEVIEW_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_READOBJ_CODEVIEW_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|using
name|llvm
operator|::
name|support
operator|::
name|ulittle16_t
expr_stmt|;
name|using
name|llvm
operator|::
name|support
operator|::
name|ulittle32_t
expr_stmt|;
comment|/// Data in the the SUBSEC_FRAMEDATA subection.
struct|struct
name|FrameData
block|{
name|ulittle32_t
name|RvaStart
decl_stmt|;
name|ulittle32_t
name|CodeSize
decl_stmt|;
name|ulittle32_t
name|LocalSize
decl_stmt|;
name|ulittle32_t
name|ParamsSize
decl_stmt|;
name|ulittle32_t
name|MaxStackSize
decl_stmt|;
name|ulittle32_t
name|FrameFunc
decl_stmt|;
name|ulittle16_t
name|PrologSize
decl_stmt|;
name|ulittle16_t
name|SavedRegsSize
decl_stmt|;
name|ulittle32_t
name|Flags
decl_stmt|;
enum_decl|enum :
name|uint32_t
block|{
name|HasSEH
init|=
literal|1
operator|<<
literal|0
block|,
name|HasEH
init|=
literal|1
operator|<<
literal|1
block|,
name|IsFunctionStart
init|=
literal|1
operator|<<
literal|2
block|,   }
enum_decl|;
block|}
struct|;
block|}
comment|// namespace codeview
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
comment|// LLVM_READOBJ_CODEVIEW_H
end_comment

end_unit

