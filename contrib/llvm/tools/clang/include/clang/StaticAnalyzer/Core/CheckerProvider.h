begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CheckerProvider.h - Static Analyzer Checkers Provider --*- C++ -*-===//
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
comment|// Defines the Static Analyzer Checker Provider.
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
name|LLVM_CLANG_SA_CORE_CHECKERPROVIDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_CORE_CHECKERPROVIDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|class
name|CheckerOptInfo
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
name|bool
name|Enable
decl_stmt|;
name|bool
name|Claimed
decl_stmt|;
name|public
label|:
name|CheckerOptInfo
argument_list|(
argument|const char *name
argument_list|,
argument|bool enable
argument_list|)
block|:
name|Name
argument_list|(
name|name
argument_list|)
operator|,
name|Enable
argument_list|(
name|enable
argument_list|)
operator|,
name|Claimed
argument_list|(
argument|false
argument_list|)
block|{ }
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
return|;
block|}
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
name|Enable
return|;
block|}
name|bool
name|isDisabled
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isEnabled
argument_list|()
return|;
block|}
name|bool
name|isClaimed
argument_list|()
specifier|const
block|{
return|return
name|Claimed
return|;
block|}
name|bool
name|isUnclaimed
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isClaimed
argument_list|()
return|;
block|}
name|void
name|claim
parameter_list|()
block|{
name|Claimed
operator|=
name|true
expr_stmt|;
block|}
block|}
empty_stmt|;
name|class
name|CheckerProvider
block|{
name|public
label|:
name|virtual
operator|~
name|CheckerProvider
argument_list|()
expr_stmt|;
name|virtual
name|void
name|registerCheckers
parameter_list|(
name|CheckerManager
modifier|&
name|checkerMgr
parameter_list|,
name|CheckerOptInfo
modifier|*
name|checkOpts
parameter_list|,
name|unsigned
name|numCheckOpts
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|printHelp
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end ento namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

