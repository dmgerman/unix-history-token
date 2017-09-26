begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugSubsection.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugSubsectionRef
block|{
name|public
label|:
name|explicit
name|DebugSubsectionRef
argument_list|(
argument|DebugSubsectionKind Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|virtual
operator|~
name|DebugSubsectionRef
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|DebugSubsectionRef
modifier|*
name|S
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|DebugSubsectionKind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|protected
label|:
name|DebugSubsectionKind
name|Kind
decl_stmt|;
block|}
empty_stmt|;
name|class
name|DebugSubsection
block|{
name|public
label|:
name|explicit
name|DebugSubsection
argument_list|(
argument|DebugSubsectionKind Kind
argument_list|)
block|:
name|Kind
argument_list|(
argument|Kind
argument_list|)
block|{}
name|virtual
operator|~
name|DebugSubsection
argument_list|()
expr_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|DebugSubsection
modifier|*
name|S
parameter_list|)
block|{
return|return
name|true
return|;
block|}
name|DebugSubsectionKind
name|kind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|virtual
name|Error
name|commit
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|uint32_t
name|calculateSerializedSize
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|DebugSubsectionKind
name|Kind
decl_stmt|;
block|}
empty_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENT_H
end_comment

end_unit

