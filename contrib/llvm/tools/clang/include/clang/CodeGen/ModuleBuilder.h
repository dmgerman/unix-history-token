begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGen/ModuleBuilder.h - Build LLVM from ASTs ---------*- C++ -*-===//
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
comment|//  This file defines the ModuleBuilder interface.
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
name|LLVM_CLANG_CODEGEN_MODULEBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_MODULEBUILDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTConsumer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CodeGenOptions
decl_stmt|;
name|class
name|CoverageSourceInfo
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|GlobalDecl
decl_stmt|;
name|class
name|HeaderSearchOptions
decl_stmt|;
name|class
name|LangOptions
decl_stmt|;
name|class
name|PreprocessorOptions
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CGDebugInfo
decl_stmt|;
block|}
comment|/// The primary public interface to the Clang code generator.
comment|///
comment|/// This is not really an abstract interface.
name|class
name|CodeGenerator
range|:
name|public
name|ASTConsumer
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|public
operator|:
comment|/// Return an opaque reference to the CodeGenModule object, which can
comment|/// be used in various secondary APIs.  It is valid as long as the
comment|/// CodeGenerator exists.
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|CGM
argument_list|()
block|;
comment|/// Return the module that this code generator is building into.
comment|///
comment|/// This may return null after HandleTranslationUnit is called;
comment|/// this signifies that there was an error generating code.  A
comment|/// diagnostic will have been generated in this case, and the module
comment|/// will be deleted.
comment|///
comment|/// It will also return null if the module is released.
name|llvm
operator|::
name|Module
operator|*
name|GetModule
argument_list|()
block|;
comment|/// Release ownership of the module to the caller.
comment|///
comment|/// It is illegal to call methods other than GetModule on the
comment|/// CodeGenerator after releasing its module.
name|llvm
operator|::
name|Module
operator|*
name|ReleaseModule
argument_list|()
block|;
comment|/// Return debug info code generator.
name|CodeGen
operator|::
name|CGDebugInfo
operator|*
name|getCGDebugInfo
argument_list|()
block|;
comment|/// Given a mangled name, return a declaration which mangles that way
comment|/// which has been added to this code generator via a Handle method.
comment|///
comment|/// This may return null if there was no matching declaration.
specifier|const
name|Decl
operator|*
name|GetDeclForMangledName
argument_list|(
argument|llvm::StringRef MangledName
argument_list|)
block|;
comment|/// Return the LLVM address of the given global entity.
comment|///
comment|/// \param isForDefinition If true, the caller intends to define the
comment|///   entity; the object returned will be an llvm::GlobalValue of
comment|///   some sort.  If false, the caller just intends to use the entity;
comment|///   the object returned may be any sort of constant value, and the
comment|///   code generator will schedule the entity for emission if a
comment|///   definition has been registered with this code generator.
name|llvm
operator|::
name|Constant
operator|*
name|GetAddrOfGlobal
argument_list|(
argument|GlobalDecl decl
argument_list|,
argument|bool isForDefinition
argument_list|)
block|; }
decl_stmt|;
comment|/// CreateLLVMCodeGen - Create a CodeGenerator instance.
comment|/// It is the responsibility of the caller to call delete on
comment|/// the allocated CodeGenerator instance.
name|CodeGenerator
modifier|*
name|CreateLLVMCodeGen
argument_list|(
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|,
name|llvm
operator|::
name|StringRef
name|ModuleName
argument_list|,
specifier|const
name|HeaderSearchOptions
operator|&
name|HeaderSearchOpts
argument_list|,
specifier|const
name|PreprocessorOptions
operator|&
name|PreprocessorOpts
argument_list|,
specifier|const
name|CodeGenOptions
operator|&
name|CGO
argument_list|,
name|llvm
operator|::
name|LLVMContext
operator|&
name|C
argument_list|,
name|CoverageSourceInfo
operator|*
name|CoverageInfo
operator|=
name|nullptr
argument_list|)
decl_stmt|;
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

