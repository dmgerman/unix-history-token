begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SMLoc.h - Source location for use with diagnostics -------*- C++ -*-===//
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
comment|// This file declares the SMLoc class.  This class encapsulates a location in
end_comment

begin_comment
comment|// source code for use in diagnostics.
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
name|LLVM_SUPPORT_SMLOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_SMLOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/None.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Represents a location in source code.
name|class
name|SMLoc
block|{
specifier|const
name|char
modifier|*
name|Ptr
init|=
name|nullptr
decl_stmt|;
name|public
label|:
name|SMLoc
argument_list|()
operator|=
expr|default
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
name|nullptr
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|==
name|Ptr
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|SMLoc
operator|&
name|RHS
operator|)
specifier|const
block|{
return|return
name|RHS
operator|.
name|Ptr
operator|!=
name|Ptr
return|;
block|}
specifier|const
name|char
operator|*
name|getPointer
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
specifier|static
name|SMLoc
name|getFromPointer
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|)
block|{
name|SMLoc
name|L
decl_stmt|;
name|L
operator|.
name|Ptr
operator|=
name|Ptr
expr_stmt|;
return|return
name|L
return|;
block|}
block|}
empty_stmt|;
comment|/// Represents a range in source code.
comment|///
comment|/// SMRange is implemented using a half-open range, as is the convention in C++.
comment|/// In the string "abc", the range (1,3] represents the substring "bc", and the
comment|/// range (2,2] represents an empty range between the characters "b" and "c".
name|class
name|SMRange
block|{
name|public
label|:
name|SMLoc
name|Start
decl_stmt|,
name|End
decl_stmt|;
name|SMRange
argument_list|()
operator|=
expr|default
expr_stmt|;
name|SMRange
argument_list|(
argument|NoneType
argument_list|)
block|{}
name|SMRange
argument_list|(
argument|SMLoc St
argument_list|,
argument|SMLoc En
argument_list|)
block|:
name|Start
argument_list|(
name|St
argument_list|)
operator|,
name|End
argument_list|(
argument|En
argument_list|)
block|{
name|assert
argument_list|(
name|Start
operator|.
name|isValid
argument_list|()
operator|==
name|End
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Start and end should either both be valid or both be invalid!"
argument_list|)
block|;   }
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|Start
operator|.
name|isValid
argument_list|()
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

begin_comment
comment|// LLVM_SUPPORT_SMLOC_H
end_comment

end_unit

