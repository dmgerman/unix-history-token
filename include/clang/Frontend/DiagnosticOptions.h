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
comment|/// Column limit for formatting message diagnostics, or 0 if unused.
name|unsigned
name|MessageLength
decl_stmt|;
name|public
label|:
name|DiagnosticOptions
argument_list|()
block|{
name|ShowColumn
operator|=
literal|1
expr_stmt|;
name|ShowLocation
operator|=
literal|1
expr_stmt|;
name|ShowCarets
operator|=
literal|1
expr_stmt|;
name|ShowFixits
operator|=
literal|1
expr_stmt|;
name|ShowSourceRanges
operator|=
literal|0
expr_stmt|;
name|ShowOptionNames
operator|=
literal|0
expr_stmt|;
name|ShowColors
operator|=
literal|0
expr_stmt|;
name|MessageLength
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

