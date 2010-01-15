begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DiagnosticOptions.h ------------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_DIAGNOSTICOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_DIAGNOSTICOPTIONS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// DiagnosticOptions - Options for controlling the compiler diagnostics
comment|/// engine.
name|class
name|DiagnosticOptions
block|{
name|public
label|:
name|unsigned
name|IgnoreWarnings
range|:
literal|1
decl_stmt|;
comment|/// -w
name|unsigned
name|NoRewriteMacros
range|:
literal|1
decl_stmt|;
comment|/// -Wno-rewrite-macros
name|unsigned
name|Pedantic
range|:
literal|1
decl_stmt|;
comment|/// -pedantic
name|unsigned
name|PedanticErrors
range|:
literal|1
decl_stmt|;
comment|/// -pedantic-errors
name|unsigned
name|ShowColumn
range|:
literal|1
decl_stmt|;
comment|/// Show column number on diagnostics.
name|unsigned
name|ShowLocation
range|:
literal|1
decl_stmt|;
comment|/// Show source location information.
name|unsigned
name|ShowCarets
range|:
literal|1
decl_stmt|;
comment|/// Show carets in diagnostics.
name|unsigned
name|ShowFixits
range|:
literal|1
decl_stmt|;
comment|/// Show fixit information.
name|unsigned
name|ShowSourceRanges
range|:
literal|1
decl_stmt|;
comment|/// Show source ranges in numeric form.
name|unsigned
name|ShowOptionNames
range|:
literal|1
decl_stmt|;
comment|/// Show the diagnostic name for mappable
comment|/// diagnostics.
name|unsigned
name|ShowColors
range|:
literal|1
decl_stmt|;
comment|/// Show diagnostics with ANSI color sequences.
name|unsigned
name|VerifyDiagnostics
decl_stmt|;
comment|/// Check that diagnostics match the expected
comment|/// diagnostics, indicated by markers in the
comment|/// input source file.
comment|/// The distance between tab stops.
name|unsigned
name|TabStop
decl_stmt|;
enum|enum
block|{
name|DefaultTabStop
init|=
literal|8
block|,
name|MaxTabStop
init|=
literal|100
block|}
enum|;
comment|/// Column limit for formatting message diagnostics, or 0 if unused.
name|unsigned
name|MessageLength
decl_stmt|;
comment|/// If non-empty, a file to log extended build information to, for development
comment|/// testing and analysis.
name|std
operator|::
name|string
name|DumpBuildInformation
expr_stmt|;
comment|/// The list of -W... options used to alter the diagnostic mappings, with the
comment|/// prefixes removed.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Warnings
expr_stmt|;
name|public
label|:
name|DiagnosticOptions
argument_list|()
block|{
name|IgnoreWarnings
operator|=
literal|0
expr_stmt|;
name|TabStop
operator|=
name|DefaultTabStop
expr_stmt|;
name|MessageLength
operator|=
literal|0
expr_stmt|;
name|NoRewriteMacros
operator|=
literal|0
expr_stmt|;
name|Pedantic
operator|=
literal|0
expr_stmt|;
name|PedanticErrors
operator|=
literal|0
expr_stmt|;
name|ShowCarets
operator|=
literal|1
expr_stmt|;
name|ShowColors
operator|=
literal|0
expr_stmt|;
name|ShowColumn
operator|=
literal|1
expr_stmt|;
name|ShowFixits
operator|=
literal|1
expr_stmt|;
name|ShowLocation
operator|=
literal|1
expr_stmt|;
name|ShowOptionNames
operator|=
literal|0
expr_stmt|;
name|ShowSourceRanges
operator|=
literal|0
expr_stmt|;
name|VerifyDiagnostics
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

