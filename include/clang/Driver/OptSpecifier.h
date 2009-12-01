begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- OptSpecifier.h - Option Specifiers ---------------------*- C++ -*-===//
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
name|CLANG_DRIVER_OPTSPECIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_OPTSPECIFIER_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|driver
block|{
name|class
name|Option
decl_stmt|;
comment|/// OptSpecifier - Wrapper class for abstracting references to option IDs.
name|class
name|OptSpecifier
block|{
name|unsigned
name|ID
decl_stmt|;
name|private
label|:
name|explicit
name|OptSpecifier
parameter_list|(
name|bool
parameter_list|)
function_decl|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|OptSpecifier
argument_list|()
operator|:
name|ID
argument_list|(
literal|0
argument_list|)
block|{}
comment|/*implicit*/
name|OptSpecifier
argument_list|(
argument|unsigned _ID
argument_list|)
operator|:
name|ID
argument_list|(
argument|_ID
argument_list|)
block|{}
comment|/*implicit*/
name|OptSpecifier
argument_list|(
specifier|const
name|Option
operator|*
name|Opt
argument_list|)
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|ID
operator|!=
literal|0
return|;
block|}
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|OptSpecifier
name|Opt
operator|)
specifier|const
block|{
return|return
name|ID
operator|==
name|Opt
operator|.
name|getID
argument_list|()
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|OptSpecifier
name|Opt
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Opt
operator|)
return|;
block|}
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

