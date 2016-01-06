begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCBundle.h ---------------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFBundle_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFBundle_h_
end_define

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCBundle
range|:
name|public
name|CFCReleaser
operator|<
name|CFBundleRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCBundle
argument_list|(
specifier|const
name|char
operator|*
name|path
operator|=
name|NULL
argument_list|)
block|;
name|CFCBundle
argument_list|(
argument|CFURLRef url
argument_list|)
block|;
name|virtual
operator|~
name|CFCBundle
argument_list|()
block|;
name|CFURLRef
name|CopyExecutableURL
argument_list|()
specifier|const
block|;
name|CFStringRef
name|GetIdentifier
argument_list|()
specifier|const
block|;
name|CFTypeRef
name|GetValueForInfoDictionaryKey
argument_list|(
argument|CFStringRef key
argument_list|)
specifier|const
block|;
name|bool
name|GetPath
argument_list|(
argument|char *dst
argument_list|,
argument|size_t dst_len
argument_list|)
block|;
name|bool
name|SetPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|private
operator|:
comment|// Disallow copy and assignment constructors
name|CFCBundle
argument_list|(
specifier|const
name|CFCBundle
operator|&
argument_list|)
block|;
specifier|const
name|CFCBundle
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCBundle
operator|&
operator|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef CoreFoundationCPP_CFBundle_h_
end_comment

end_unit

