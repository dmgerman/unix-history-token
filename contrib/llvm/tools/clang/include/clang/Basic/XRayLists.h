begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- XRayLists.h - XRay automatic attribution ---------------*- C++ -*-===//
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
comment|// User-provided filters for always/never XRay instrumenting certain functions.
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
name|LLVM_CLANG_BASIC_XRAYLISTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_XRAYLISTS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SpecialCaseList.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|XRayFunctionFilter
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|SpecialCaseList
operator|>
name|AlwaysInstrument
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|llvm
operator|::
name|SpecialCaseList
operator|>
name|NeverInstrument
expr_stmt|;
name|SourceManager
modifier|&
name|SM
decl_stmt|;
name|public
label|:
name|XRayFunctionFilter
argument_list|(
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|AlwaysInstrumentPaths
argument_list|,
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|NeverInstrumentPaths
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|)
expr_stmt|;
name|enum
name|class
name|ImbueAttribute
block|{
name|NONE
operator|,
name|ALWAYS
operator|,
name|NEVER
operator|,
name|ALWAYS_ARG1
operator|,
block|}
empty_stmt|;
name|ImbueAttribute
name|shouldImbueFunction
argument_list|(
name|StringRef
name|FunctionName
argument_list|)
decl|const
decl_stmt|;
name|ImbueAttribute
name|shouldImbueFunctionsInFile
argument_list|(
name|StringRef
name|Filename
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|ImbueAttribute
name|shouldImbueLocation
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|Category
operator|=
name|StringRef
argument_list|()
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

