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
comment|// This file defines
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
name|LLVM_CLANG_CHECKER_DS_COCOA
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CHECKER_DS_COCOA
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|cocoa
block|{
enum|enum
name|NamingConvention
block|{
name|NoConvention
block|,
name|CreateRule
block|,
name|InitRule
block|}
enum|;
name|NamingConvention
name|deriveNamingConvention
parameter_list|(
name|Selector
name|S
parameter_list|)
function_decl|;
specifier|static
specifier|inline
name|bool
name|followsFundamentalRule
parameter_list|(
name|Selector
name|S
parameter_list|)
block|{
return|return
name|deriveNamingConvention
argument_list|(
name|S
argument_list|)
operator|==
name|CreateRule
return|;
block|}
name|bool
name|isRefType
argument_list|(
name|QualType
name|RetTy
argument_list|,
name|llvm
operator|::
name|StringRef
name|Prefix
argument_list|,
name|llvm
operator|::
name|StringRef
name|Name
operator|=
name|llvm
operator|::
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
name|bool
name|isCFObjectRef
parameter_list|(
name|QualType
name|T
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

