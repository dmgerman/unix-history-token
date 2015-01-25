begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SanitizerMetadata.h - Metadata for sanitizers ----------*- C++ -*-===//
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
comment|// Class which emits metadata consumed by sanitizer instrumentation passes.
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
name|LLVM_CLANG_LIB_CODEGEN_SANITIZERMETADATA_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_SANITIZERMETADATA_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|MDNode
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|VarDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|SanitizerMetadata
block|{
name|SanitizerMetadata
argument_list|(
argument|const SanitizerMetadata&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|SanitizerMetadata
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|public
label|:
name|SanitizerMetadata
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
expr_stmt|;
name|void
name|reportGlobalToASan
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|bool
name|IsDynInit
operator|=
name|false
argument_list|)
decl_stmt|;
name|void
name|reportGlobalToASan
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
name|StringRef
name|Name
argument_list|,
name|QualType
name|Ty
argument_list|,
name|bool
name|IsDynInit
operator|=
name|false
argument_list|,
name|bool
name|IsBlacklisted
operator|=
name|false
argument_list|)
decl_stmt|;
name|void
name|disableSanitizerForGlobal
argument_list|(
name|llvm
operator|::
name|GlobalVariable
operator|*
name|GV
argument_list|)
decl_stmt|;
name|void
name|disableSanitizerForInstruction
argument_list|(
name|llvm
operator|::
name|Instruction
operator|*
name|I
argument_list|)
decl_stmt|;
name|private
label|:
name|llvm
operator|::
name|MDNode
operator|*
name|getLocationMetadata
argument_list|(
argument|SourceLocation Loc
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace CodeGen
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

