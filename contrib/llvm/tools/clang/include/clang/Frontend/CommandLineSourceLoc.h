begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CommandLineSourceLoc.h - Parsing for source locations-*- C++ -*---===//
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
comment|// Command line parsing for source locations.
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
name|LLVM_CLANG_FRONTEND_COMMANDLINESOURCELOC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMMANDLINESOURCELOC_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/CommandLine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief A source location that has been parsed on the command line.
struct|struct
name|ParsedSourceLocation
block|{
name|std
operator|::
name|string
name|FileName
expr_stmt|;
name|unsigned
name|Line
decl_stmt|;
name|unsigned
name|Column
decl_stmt|;
name|public
label|:
comment|/// Construct a parsed source location from a string; the Filename is empty on
comment|/// error.
specifier|static
name|ParsedSourceLocation
name|FromString
argument_list|(
name|llvm
operator|::
name|StringRef
name|Str
argument_list|)
block|{
name|ParsedSourceLocation
name|PSL
decl_stmt|;
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|StringRef
operator|,
name|llvm
operator|::
name|StringRef
operator|>
name|ColSplit
operator|=
name|Str
operator|.
name|rsplit
argument_list|(
literal|':'
argument_list|)
expr_stmt|;
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|StringRef
operator|,
name|llvm
operator|::
name|StringRef
operator|>
name|LineSplit
operator|=
name|ColSplit
operator|.
name|first
operator|.
name|rsplit
argument_list|(
literal|':'
argument_list|)
expr_stmt|;
comment|// If both tail splits were valid integers, return success.
if|if
condition|(
operator|!
name|ColSplit
operator|.
name|second
operator|.
name|getAsInteger
argument_list|(
literal|10
argument_list|,
name|PSL
operator|.
name|Column
argument_list|)
operator|&&
operator|!
name|LineSplit
operator|.
name|second
operator|.
name|getAsInteger
argument_list|(
literal|10
argument_list|,
name|PSL
operator|.
name|Line
argument_list|)
condition|)
name|PSL
operator|.
name|FileName
operator|=
name|LineSplit
operator|.
name|first
expr_stmt|;
return|return
name|PSL
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|cl
block|{
comment|/// \brief Command-line option parser that parses source locations.
comment|///
comment|/// Source locations are of the form filename:line:column.
name|template
operator|<
operator|>
name|class
name|parser
operator|<
name|clang
operator|::
name|ParsedSourceLocation
operator|>
operator|:
name|public
name|basic_parser
operator|<
name|clang
operator|::
name|ParsedSourceLocation
operator|>
block|{
name|public
operator|:
specifier|inline
name|bool
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef ArgValue
argument_list|,
argument|clang::ParsedSourceLocation&Val
argument_list|)
block|;     }
expr_stmt|;
name|bool
name|parser
operator|<
name|clang
operator|::
name|ParsedSourceLocation
operator|>
operator|::
name|parse
argument_list|(
argument|Option&O
argument_list|,
argument|StringRef ArgName
argument_list|,
argument|StringRef ArgValue
argument_list|,
argument|clang::ParsedSourceLocation&Val
argument_list|)
block|{
name|using
name|namespace
name|clang
block|;
name|Val
operator|=
name|ParsedSourceLocation
operator|::
name|FromString
argument_list|(
name|ArgValue
argument_list|)
block|;
if|if
condition|(
name|Val
operator|.
name|FileName
operator|.
name|empty
argument_list|()
condition|)
block|{
name|errs
argument_list|()
operator|<<
literal|"error: "
operator|<<
literal|"source location must be of the form filename:line:column\n"
expr_stmt|;
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

