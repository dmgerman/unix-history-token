begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSection.h - Machine Code Sections ----------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file declares the MCSection class.
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
name|LLVM_MC_MCSECTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSECTION_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCSection - Instances of this class represent a uniqued identifier for a
comment|/// section in the current translation unit.  The MCContext class uniques and
comment|/// creates these.
name|class
name|MCSection
block|{
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|private
label|:
name|friend
name|class
name|MCContext
decl_stmt|;
name|MCSection
argument_list|(
specifier|const
name|char
operator|*
name|_Name
argument_list|)
operator|:
name|Name
argument_list|(
argument|_Name
argument_list|)
block|{}
name|MCSection
argument_list|(
specifier|const
name|MCSection
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCSection
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

