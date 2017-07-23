begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DebugUnknownSubsection.h -----------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGUNKNOWNFRAGMENT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGUNKNOWNFRAGMENT_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/DebugSubsection.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|DebugUnknownSubsectionRef
name|final
range|:
name|public
name|DebugSubsectionRef
block|{
name|public
operator|:
name|DebugUnknownSubsectionRef
argument_list|(
argument|DebugSubsectionKind Kind
argument_list|,
argument|BinaryStreamRef Data
argument_list|)
operator|:
name|DebugSubsectionRef
argument_list|(
name|Kind
argument_list|)
block|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|BinaryStreamRef
name|getData
argument_list|()
specifier|const
block|{
return|return
name|Data
return|;
block|}
name|private
operator|:
name|BinaryStreamRef
name|Data
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

