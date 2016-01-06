begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCMutableSet.h -----------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFMutableSet_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFMutableSet_h_
end_define

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCMutableSet
range|:
name|public
name|CFCReleaser
operator|<
name|CFMutableSetRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCMutableSet
argument_list|(
argument|CFMutableSetRef s = NULL
argument_list|)
block|;
name|CFCMutableSet
argument_list|(
specifier|const
name|CFCMutableSet
operator|&
name|rhs
argument_list|)
block|;
name|virtual
operator|~
name|CFCMutableSet
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|// Operators
comment|//------------------------------------------------------------------
specifier|const
name|CFCMutableSet
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCMutableSet
operator|&
name|rhs
operator|)
block|;
name|CFIndex
name|GetCount
argument_list|()
specifier|const
block|;
name|CFIndex
name|GetCountOfValue
argument_list|(
argument|const void *value
argument_list|)
specifier|const
block|;
specifier|const
name|void
operator|*
name|GetValue
argument_list|(
argument|const void *value
argument_list|)
specifier|const
block|;
specifier|const
name|void
operator|*
name|AddValue
argument_list|(
argument|const void *value
argument_list|,
argument|bool can_create
argument_list|)
block|;
name|void
name|RemoveValue
argument_list|(
specifier|const
name|void
operator|*
name|value
argument_list|)
block|;
name|void
name|RemoveAllValues
argument_list|()
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from CFCMutableSet can see and modify these
comment|//------------------------------------------------------------------
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// For CFCMutableSet only
comment|//------------------------------------------------------------------
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// CoreFoundationCPP_CFMutableSet_h_
end_comment

end_unit

