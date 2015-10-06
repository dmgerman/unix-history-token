begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- UriParser.h ---------------------------------------------*- C++ -*-===//
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
name|utility_UriParser_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_UriParser_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_decl_stmt
name|class
name|UriParser
block|{
name|public
label|:
comment|// Parses
comment|// RETURN VALUE
comment|//   if url is valid, function returns true and
comment|//   scheme/hostname/port/path are set to the parsed values
comment|//   port it set to -1 if it is not included in the URL
comment|//
comment|//   if the url is invalid, function returns false and
comment|//   output parameters remain unchanged
specifier|static
name|bool
name|Parse
argument_list|(
specifier|const
name|char
operator|*
name|uri
argument_list|,
name|std
operator|::
name|string
operator|&
name|scheme
argument_list|,
name|std
operator|::
name|string
operator|&
name|hostname
argument_list|,
name|int
operator|&
name|port
argument_list|,
name|std
operator|::
name|string
operator|&
name|path
argument_list|)
decl_stmt|;
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
comment|// utility_UriParser_h_
end_comment

end_unit

