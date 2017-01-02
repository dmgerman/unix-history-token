begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCMutableArray.h ---------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFMutableArray_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFMutableArray_h_
end_define

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCMutableArray
range|:
name|public
name|CFCReleaser
operator|<
name|CFMutableArrayRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCMutableArray
argument_list|(
argument|CFMutableArrayRef array = NULL
argument_list|)
block|;
name|CFCMutableArray
argument_list|(
specifier|const
name|CFCMutableArray
operator|&
name|rhs
argument_list|)
block|;
comment|// This will copy the array
comment|// contents into a new array
name|CFCMutableArray
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCMutableArray
operator|&
name|rhs
operator|)
block|;
comment|// This will re-use
comment|// the same array and
comment|// just bump the ref
comment|// count
name|virtual
operator|~
name|CFCMutableArray
argument_list|()
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
name|CFIndex
name|GetCountOfValue
argument_list|(
argument|CFRange range
argument_list|,
argument|const void *value
argument_list|)
specifier|const
block|;
specifier|const
name|void
operator|*
name|GetValueAtIndex
argument_list|(
argument|CFIndex idx
argument_list|)
specifier|const
block|;
name|bool
name|SetValueAtIndex
argument_list|(
argument|CFIndex idx
argument_list|,
argument|const void *value
argument_list|)
block|;
name|bool
name|AppendValue
argument_list|(
argument|const void *value
argument_list|,
argument|bool can_create = true
argument_list|)
block|;
comment|// Appends value and optionally
comment|// creates a CFCMutableArray if this
comment|// class doesn't contain one
name|bool
name|AppendCStringAsCFString
argument_list|(
argument|const char *cstr
argument_list|,
argument|CFStringEncoding encoding = kCFStringEncodingUTF8
argument_list|,
argument|bool can_create = true
argument_list|)
block|;
name|bool
name|AppendFileSystemRepresentationAsCFString
argument_list|(
argument|const char *s
argument_list|,
argument|bool can_create = true
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef CoreFoundationCPP_CFMutableArray_h_
end_comment

end_unit

