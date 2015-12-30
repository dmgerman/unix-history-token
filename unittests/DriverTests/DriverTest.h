begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/unittest/DriverTest.h ------------------------------------------===//
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

begin_include
include|#
directive|include
file|"lld/Driver/Driver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_macro
name|namespace
end_macro

begin_block
block|{
name|using
name|namespace
name|llvm
decl_stmt|;
name|using
name|namespace
name|lld
decl_stmt|;
name|template
operator|<
name|typename
name|D
operator|,
name|typename
name|T
operator|>
name|class
name|ParserTest
operator|:
name|public
name|testing
operator|::
name|Test
block|{
name|protected
operator|:
name|virtual
specifier|const
name|LinkingContext
operator|*
name|linkingContext
argument_list|()
operator|=
literal|0
block|;
name|std
operator|::
name|string
operator|&
name|errorMessage
argument_list|()
block|{
return|return
name|_errorMessage
return|;
block|}
comment|// Convenience method for getting number of input files.
name|int
name|inputFileCount
argument_list|()
block|{
return|return
name|linkingContext
argument_list|()
operator|->
name|getNodes
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
comment|// Convenience method for getting i'th input files name.
name|std
operator|::
name|string
name|inputFile
argument_list|(
argument|int index
argument_list|)
block|{
name|Node
operator|&
name|node
operator|=
operator|*
name|linkingContext
argument_list|()
operator|->
name|getNodes
argument_list|()
index|[
name|index
index|]
block|;
if|if
condition|(
name|node
operator|.
name|kind
argument_list|()
operator|==
name|Node
operator|::
name|Kind
operator|::
name|File
condition|)
return|return
name|cast
operator|<
name|FileNode
operator|>
operator|(
operator|&
name|node
operator|)
operator|->
name|getFile
argument_list|()
operator|->
name|path
argument_list|()
return|;
name|llvm_unreachable
argument_list|(
literal|"not handling other types of input files"
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|// For unit tests to call driver with various command lines.
end_comment

begin_function
name|bool
name|parse
parameter_list|(
specifier|const
name|char
modifier|*
name|args
parameter_list|,
modifier|...
parameter_list|)
block|{
comment|// Construct command line options from varargs.
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|vec
expr_stmt|;
name|vec
operator|.
name|push_back
argument_list|(
name|args
argument_list|)
expr_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|args
argument_list|)
expr_stmt|;
while|while
condition|(
specifier|const
name|char
modifier|*
name|arg
init|=
name|va_arg
argument_list|(
name|ap
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
condition|)
name|vec
operator|.
name|push_back
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
comment|// Call the parser.
name|raw_string_ostream
name|os
argument_list|(
name|_errorMessage
argument_list|)
decl_stmt|;
return|return
name|D
operator|::
name|parse
argument_list|(
name|vec
argument_list|,
name|_ctx
argument_list|,
name|os
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|T
name|_ctx
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|_errorMessage
expr_stmt|;
end_expr_stmt

unit|};  }
end_unit

