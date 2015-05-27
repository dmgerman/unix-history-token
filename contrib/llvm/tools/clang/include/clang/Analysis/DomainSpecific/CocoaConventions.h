begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CocoaConventions.h - Special handling of Cocoa conventions -*- C++ -*--//
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
comment|// This file implements cocoa naming convention analysis.
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
name|LLVM_CLANG_ANALYSIS_DOMAINSPECIFIC_COCOACONVENTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_DOMAINSPECIFIC_COCOACONVENTIONS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|namespace
name|ento
block|{
name|namespace
name|cocoa
block|{
name|bool
name|isRefType
parameter_list|(
name|QualType
name|RetTy
parameter_list|,
name|StringRef
name|Prefix
parameter_list|,
name|StringRef
name|Name
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
name|bool
name|isCocoaObjectRef
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
block|}
name|namespace
name|coreFoundation
block|{
name|bool
name|isCFObjectRef
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|bool
name|followsCreateRule
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end: "clang:ento"
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

