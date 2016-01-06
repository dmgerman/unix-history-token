begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCData.h -----------------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFData_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFData_h_
end_define

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCData
range|:
name|public
name|CFCReleaser
operator|<
name|CFDataRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCData
argument_list|(
argument|CFDataRef data = NULL
argument_list|)
block|;
name|CFCData
argument_list|(
specifier|const
name|CFCData
operator|&
name|rhs
argument_list|)
block|;
name|CFCData
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCData
operator|&
name|rhs
operator|)
block|;
name|virtual
operator|~
name|CFCData
argument_list|()
block|;
name|CFDataRef
name|Serialize
argument_list|(
argument|CFPropertyListRef plist
argument_list|,
argument|CFPropertyListFormat format
argument_list|)
block|;
specifier|const
name|uint8_t
operator|*
name|GetBytePtr
argument_list|()
specifier|const
block|;
name|CFIndex
name|GetLength
argument_list|()
specifier|const
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from CFCData can see and modify these
comment|//------------------------------------------------------------------
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef CoreFoundationCPP_CFData_h_
end_comment

end_unit

