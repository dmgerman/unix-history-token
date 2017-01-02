begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|REP_H
end_ifndef

begin_define
define|#
directive|define
name|REP_H
end_define

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_decl_stmt
name|class
name|Rep
block|{
name|int
name|data_
decl_stmt|;
name|public
label|:
name|TEST_CONSTEXPR
name|Rep
argument_list|()
operator|:
name|data_
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|explicit
name|TEST_CONSTEXPR
name|Rep
argument_list|(
argument|int i
argument_list|)
operator|:
name|data_
argument_list|(
argument|i
argument_list|)
block|{}
name|bool
name|TEST_CONSTEXPR
name|operator
operator|==
operator|(
name|int
name|i
operator|)
specifier|const
block|{
return|return
name|data_
operator|==
name|i
return|;
block|}
name|bool
name|TEST_CONSTEXPR
name|operator
operator|==
operator|(
specifier|const
name|Rep
operator|&
name|r
operator|)
specifier|const
block|{
return|return
name|data_
operator|==
name|r
operator|.
name|data_
return|;
block|}
name|Rep
operator|&
name|operator
operator|*=
operator|(
name|Rep
name|x
operator|)
block|{
name|data_
operator|*=
name|x
operator|.
name|data_
block|;
return|return
operator|*
name|this
return|;
block|}
name|Rep
operator|&
name|operator
operator|/=
operator|(
name|Rep
name|x
operator|)
block|{
name|data_
operator|/=
name|x
operator|.
name|data_
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// REP_H
end_comment

end_unit

