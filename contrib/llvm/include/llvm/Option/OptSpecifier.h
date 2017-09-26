begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OptSpecifier.h - Option Specifiers -----------------------*- C++ -*-===//
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
name|LLVM_OPTION_OPTSPECIFIER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_OPTION_OPTSPECIFIER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|opt
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
init|=
literal|0
decl_stmt|;
name|public
label|:
name|OptSpecifier
argument_list|()
operator|=
expr|default
expr_stmt|;
name|explicit
name|OptSpecifier
parameter_list|(
name|bool
parameter_list|)
init|=
name|delete
function_decl|;
comment|/*implicit*/
name|OptSpecifier
argument_list|(
argument|unsigned ID
argument_list|)
block|:
name|ID
argument_list|(
argument|ID
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
comment|// end namespace opt
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
comment|// LLVM_OPTION_OPTSPECIFIER_H
end_comment

end_unit

