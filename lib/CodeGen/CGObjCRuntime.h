begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGObjCRuntime.h - Interface to ObjC Runtimes ---------*- C++ -*-===//
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
comment|// This provides an abstract class for Objective-C code generation.  Concrete
end_comment

begin_comment
comment|// subclasses of this implement code generation for specific Objective-C
end_comment

begin_comment
comment|// runtime libraries.
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
name|CLANG_CODEGEN_OBCJRUNTIME_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_OBCJRUNTIME_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_comment
comment|// Selector
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"CGBuilder.h"
end_include

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"CGValue.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|StructLayout
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenFunction
decl_stmt|;
block|}
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ObjCAtTryStmt
decl_stmt|;
name|class
name|ObjCAtThrowStmt
decl_stmt|;
name|class
name|ObjCAtSynchronizedStmt
decl_stmt|;
name|class
name|ObjCContainerDecl
decl_stmt|;
name|class
name|ObjCCategoryImplDecl
decl_stmt|;
name|class
name|ObjCImplementationDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCMessageExpr
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|Selector
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|ObjCStringLiteral
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
comment|// FIXME: Several methods should be pure virtual but aren't to avoid the
comment|// partially-implemented subclass breaking.
comment|/// Implements runtime-specific code generation functions.
name|class
name|CGObjCRuntime
block|{
name|public
label|:
comment|// Utility functions for unified ivar access. These need to
comment|// eventually be folded into other places (the structure layout
comment|// code).
name|protected
label|:
comment|/// Compute an offset to the given ivar, suitable for passing to
comment|/// EmitValueForIvarAtOffset.  Note that the correct handling of
comment|/// bit-fields is carefully coordinated by these two, use caution!
comment|///
comment|/// The latter overload is suitable for computing the offset of a
comment|/// sythesized ivar.
name|uint64_t
name|ComputeIvarBaseOffset
argument_list|(
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OID
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|)
decl_stmt|;
name|uint64_t
name|ComputeIvarBaseOffset
argument_list|(
name|CodeGen
operator|::
name|CodeGenModule
operator|&
name|CGM
argument_list|,
specifier|const
name|ObjCImplementationDecl
operator|*
name|OID
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|)
decl_stmt|;
name|LValue
name|EmitValueForIvarAtOffset
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OID
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|BaseValue
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Offset
argument_list|)
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|CGObjCRuntime
argument_list|()
expr_stmt|;
comment|/// Generate the function required to register all Objective-C components in
comment|/// this compilation unit with the runtime library.
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|ModuleInitFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Get a selector for the specified name and type values. The
comment|/// return value should have the LLVM type for pointer-to
comment|/// ASTContext::getObjCSelType().
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|GetSelector
argument_list|(
argument|CGBuilderTy&Builder
argument_list|,
argument|Selector Sel
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Get a typed selector.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|GetSelector
argument_list|(
name|CGBuilderTy
operator|&
name|Builder
argument_list|,
specifier|const
name|ObjCMethodDecl
operator|*
name|Method
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Generate a constant string object.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|GenerateConstantString
argument_list|(
specifier|const
name|StringLiteral
operator|*
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Generate a category.  A category contains a list of methods (and
comment|/// accompanying metadata) and a list of protocols.
name|virtual
name|void
name|GenerateCategory
parameter_list|(
specifier|const
name|ObjCCategoryImplDecl
modifier|*
name|OCD
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Generate a class stucture for this class.
name|virtual
name|void
name|GenerateClass
parameter_list|(
specifier|const
name|ObjCImplementationDecl
modifier|*
name|OID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Generate an Objective-C message send operation.
comment|///
comment|/// \param Method - The method being called, this may be null if synthesizing
comment|/// a property setter or getter.
name|virtual
name|CodeGen
operator|::
name|RValue
name|GenerateMessageSend
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|QualType ResultType
argument_list|,
argument|Selector Sel
argument_list|,
argument|llvm::Value *Receiver
argument_list|,
argument|bool IsClassMessage
argument_list|,
argument|const CallArgList&CallArgs
argument_list|,
argument|const ObjCMethodDecl *Method =
literal|0
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Generate an Objective-C message send operation to the super
comment|/// class initiated in a method for Class and with the given Self
comment|/// object.
comment|///
comment|/// \param Method - The method being called, this may be null if synthesizing
comment|/// a property setter or getter.
name|virtual
name|CodeGen
operator|::
name|RValue
name|GenerateMessageSendSuper
argument_list|(
argument|CodeGen::CodeGenFunction&CGF
argument_list|,
argument|QualType ResultType
argument_list|,
argument|Selector Sel
argument_list|,
argument|const ObjCInterfaceDecl *Class
argument_list|,
argument|bool isCategoryImpl
argument_list|,
argument|llvm::Value *Self
argument_list|,
argument|bool IsClassMessage
argument_list|,
argument|const CallArgList&CallArgs
argument_list|,
argument|const ObjCMethodDecl *Method =
literal|0
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Emit the code to return the named protocol as an object, as in a
comment|/// @protocol expression.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|GenerateProtocolRef
argument_list|(
name|CGBuilderTy
operator|&
name|Builder
argument_list|,
specifier|const
name|ObjCProtocolDecl
operator|*
name|OPD
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Generate the named protocol.  Protocols contain method metadata but no
comment|/// implementations.
name|virtual
name|void
name|GenerateProtocol
parameter_list|(
specifier|const
name|ObjCProtocolDecl
modifier|*
name|OPD
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Generate a function preamble for a method with the specified
comment|/// types.
comment|// FIXME: Current this just generates the Function definition, but really this
comment|// should also be generating the loads of the parameters, as the runtime
comment|// should have full control over how parameters are passed.
name|virtual
name|llvm
operator|::
name|Function
operator|*
name|GenerateMethod
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|OMD
argument_list|,
specifier|const
name|ObjCContainerDecl
operator|*
name|CD
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Return the runtime function for getting properties.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|GetPropertyGetFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// Return the runtime function for setting properties.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|GetPropertySetFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
comment|/// GetClass - Return a reference to the class for the given
comment|/// interface decl.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|GetClass
argument_list|(
name|CGBuilderTy
operator|&
name|Builder
argument_list|,
specifier|const
name|ObjCInterfaceDecl
operator|*
name|OID
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// EnumerationMutationFunction - Return the function that's called by the
comment|/// compiler when a mutation is detected during foreach iteration.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EnumerationMutationFunction
argument_list|()
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|EmitTryOrSynchronizedStmt
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|Stmt
operator|&
name|S
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|EmitThrowStmt
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|ObjCAtThrowStmt
operator|&
name|S
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitObjCWeakRead
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|AddrWeakObj
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|EmitObjCWeakAssign
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|dest
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|EmitObjCGlobalAssign
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|dest
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|EmitObjCIvarAssign
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|dest
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|ivarOffset
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|EmitObjCStrongCastAssign
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|src
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|dest
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|LValue
name|EmitObjCValueForIvar
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|QualType
name|ObjectTy
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|BaseValue
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|,
name|unsigned
name|CVRQualifiers
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitIvarOffset
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|ObjCInterfaceDecl
operator|*
name|Interface
argument_list|,
specifier|const
name|ObjCIvarDecl
operator|*
name|Ivar
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|EmitGCMemmoveCollectable
argument_list|(
name|CodeGen
operator|::
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|DestPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|SrcPtr
argument_list|,
name|QualType
name|Ty
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
comment|/// Creates an instance of an Objective-C runtime class.
comment|//TODO: This should include some way of selecting which runtime to target.
name|CGObjCRuntime
modifier|*
name|CreateGNUObjCRuntime
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
name|CGObjCRuntime
modifier|*
name|CreateMacObjCRuntime
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
name|CGObjCRuntime
modifier|*
name|CreateMacNonFragileABIObjCRuntime
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
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

