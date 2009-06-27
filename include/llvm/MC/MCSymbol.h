begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbol.h - Machine Code Symbols ------------------------*- C++ -*-===//
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
name|LLVM_MC_MCSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOL_H
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
name|class
name|MCSymbol
block|{
name|MCSection
modifier|*
name|Section
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|unsigned
name|IsTemporary
range|:
literal|1
decl_stmt|;
name|public
label|:
name|MCSymbol
argument_list|(
argument|const char *_Name
argument_list|,
argument|bool _IsTemporary
argument_list|)
block|:
name|Section
argument_list|(
literal|0
argument_list|)
operator|,
name|Name
argument_list|(
name|_Name
argument_list|)
operator|,
name|IsTemporary
argument_list|(
argument|_IsTemporary
argument_list|)
block|{}
name|MCSection
operator|*
name|getSection
argument_list|()
specifier|const
block|{
return|return
name|Section
return|;
block|}
name|void
name|setSection
parameter_list|(
name|MCSection
modifier|*
name|Value
parameter_list|)
block|{
name|Section
operator|=
name|Value
expr_stmt|;
block|}
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

