begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFBundle.h ----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 1/16/08.
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
name|__CFBundle_h__
end_ifndef

begin_define
define|#
directive|define
name|__CFBundle_h__
end_define

begin_include
include|#
directive|include
file|"CFUtils.h"
end_include

begin_decl_stmt
name|class
name|CFBundle
range|:
name|public
name|CFReleaser
operator|<
name|CFBundleRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFBundle
argument_list|(
specifier|const
name|char
operator|*
name|path
operator|=
name|NULL
argument_list|)
block|;
name|CFBundle
argument_list|(
specifier|const
name|CFBundle
operator|&
name|rhs
argument_list|)
block|;
name|CFBundle
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFBundle
operator|&
name|rhs
operator|)
block|;
name|virtual
operator|~
name|CFBundle
argument_list|()
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
name|CFStringRef
name|GetIdentifier
argument_list|()
specifier|const
block|;
name|CFURLRef
name|CopyExecutableURL
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|CFReleaser
operator|<
name|CFURLRef
operator|>
name|m_bundle_url
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __CFBundle_h__
end_comment

end_unit

