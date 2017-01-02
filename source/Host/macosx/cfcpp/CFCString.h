begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCString.h ---------------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFString_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFString_h_
end_define

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|"CFCReleaser.h"
end_include

begin_decl_stmt
name|class
name|CFCString
range|:
name|public
name|CFCReleaser
operator|<
name|CFStringRef
operator|>
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|CFCString
argument_list|(
argument|CFStringRef cf_str = NULL
argument_list|)
block|;
name|CFCString
argument_list|(
argument|const char *s
argument_list|,
argument|CFStringEncoding encoding = kCFStringEncodingUTF8
argument_list|)
block|;
name|CFCString
argument_list|(
specifier|const
name|CFCString
operator|&
name|rhs
argument_list|)
block|;
name|CFCString
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCString
operator|&
name|rhs
operator|)
block|;
name|virtual
operator|~
name|CFCString
argument_list|()
block|;
specifier|const
name|char
operator|*
name|GetFileSystemRepresentation
argument_list|(
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|;
name|CFStringRef
name|SetFileSystemRepresentation
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
name|CFStringRef
name|SetFileSystemRepresentationFromCFType
argument_list|(
argument|CFTypeRef cf_type
argument_list|)
block|;
name|CFStringRef
name|SetFileSystemRepresentationAndExpandTilde
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|)
block|;
specifier|const
name|char
operator|*
name|UTF8
argument_list|(
name|std
operator|::
name|string
operator|&
name|str
argument_list|)
block|;
name|CFIndex
name|GetLength
argument_list|()
specifier|const
block|;
specifier|static
specifier|const
name|char
operator|*
name|UTF8
argument_list|(
argument|CFStringRef cf_str
argument_list|,
argument|std::string&str
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|FileSystemRepresentation
argument_list|(
argument|CFStringRef cf_str
argument_list|,
argument|std::string&str
argument_list|)
block|;
specifier|static
specifier|const
name|char
operator|*
name|ExpandTildeInPath
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|std
operator|::
name|string
operator|&
name|expanded_path
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef CoreFoundationCPP_CFString_h_
end_comment

end_unit

