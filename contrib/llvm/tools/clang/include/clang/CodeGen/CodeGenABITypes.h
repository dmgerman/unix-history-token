begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==---- CodeGenABITypes.h - Convert Clang types to LLVM types for ABI -----==//
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
comment|// CodeGenABITypes is a simple interface for getting LLVM types for
end_comment

begin_comment
comment|// the parameters and the return value of a function given the Clang
end_comment

begin_comment
comment|// types.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The class is implemented as a public wrapper around the private
end_comment

begin_comment
comment|// CodeGenTypes class in lib/CodeGen.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// It allows other clients, like LLDB, to determine the LLVM types that are
end_comment

begin_comment
comment|// actually used in function calls, which makes it possible to then determine
end_comment

begin_comment
comment|// the actual ABI locations (e.g. registers, stack locations, etc.) that
end_comment

begin_comment
comment|// these parameters are stored in.
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
name|LLVM_CLANG_CODEGEN_CODEGENABITYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_CODEGENABITYPES_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/CodeGen/CGFunctionInfo.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|Type
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|CoverageSourceInfo
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGFunctionInfo
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeObjCMessageSendSignature
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|,
name|QualType
name|receiverType
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFreeFunctionType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CanQual
operator|<
name|FunctionProtoType
operator|>
name|Ty
argument_list|,
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFreeFunctionType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CanQual
operator|<
name|FunctionNoProtoType
operator|>
name|Ty
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXMethodType
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|FTP
parameter_list|,
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFreeFunctionCall
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CanQualType
name|returnType
argument_list|,
name|ArrayRef
operator|<
name|CanQualType
operator|>
name|argTypes
argument_list|,
name|FunctionType
operator|::
name|ExtInfo
name|info
argument_list|,
name|RequiredArgs
name|args
argument_list|)
decl_stmt|;
comment|// Returns null if the function type is incomplete and can't be lowered.
name|llvm
operator|::
name|FunctionType
operator|*
name|convertFreeFunctionType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|FunctionDecl
operator|*
name|FD
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|convertTypeForMemory
argument_list|(
argument|CodeGenModule&CGM
argument_list|,
argument|QualType T
argument_list|)
expr_stmt|;
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

