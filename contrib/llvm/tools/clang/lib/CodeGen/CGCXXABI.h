begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- CGCXXABI.h - Interface to C++ ABIs -------------------*- C++ -*-===//
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
comment|// This provides an abstract class for C++ code generation. Concrete subclasses
end_comment

begin_comment
comment|// of this implement code generation for specific C++ ABIs.
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
name|LLVM_CLANG_LIB_CODEGEN_CGCXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CGCXXABI_H
end_define

begin_include
include|#
directive|include
file|"CodeGenFunction.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|CallInst
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CastExpr
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXDestructorDecl
decl_stmt|;
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|MangleContext
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CGCallee
decl_stmt|;
name|class
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
struct_decl|struct
name|CatchTypeInfo
struct_decl|;
comment|/// \brief Implements C++ ABI-specific code generation functions.
name|class
name|CGCXXABI
block|{
name|protected
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|MangleContext
operator|>
name|MangleCtx
expr_stmt|;
name|CGCXXABI
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
name|CGM
argument_list|)
operator|,
name|MangleCtx
argument_list|(
argument|CGM.getContext().createMangleContext()
argument_list|)
block|{}
name|protected
operator|:
name|ImplicitParamDecl
operator|*
name|getThisDecl
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXABIThisDecl
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
name|getThisValue
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXABIThisValue
return|;
block|}
name|Address
name|getThisAddress
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
return|return
name|Address
argument_list|(
name|CGF
operator|.
name|CXXABIThisValue
argument_list|,
name|CGF
operator|.
name|CXXABIThisAlignment
argument_list|)
return|;
block|}
comment|/// Issue a diagnostic about unsupported features in the ABI.
name|void
name|ErrorUnsupportedABI
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|StringRef
name|S
parameter_list|)
function_decl|;
comment|/// Get a null value for unsupported member pointers.
name|llvm
operator|::
name|Constant
operator|*
name|GetBogusMemberPointer
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
name|ImplicitParamDecl
modifier|*
modifier|&
name|getStructorImplicitParamDecl
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
return|return
name|CGF
operator|.
name|CXXStructorImplicitParamDecl
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
operator|&
name|getStructorImplicitParamValue
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXStructorImplicitParamValue
return|;
block|}
comment|/// Perform prolog initialization of the parameter variable suitable
comment|/// for 'this' emitted by buildThisParam.
name|void
name|EmitThisParam
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
function_decl|;
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|CGM
operator|.
name|getContext
argument_list|()
return|;
block|}
name|virtual
name|bool
name|requiresArrayCookie
parameter_list|(
specifier|const
name|CXXDeleteExpr
modifier|*
name|E
parameter_list|,
name|QualType
name|eltType
parameter_list|)
function_decl|;
name|virtual
name|bool
name|requiresArrayCookie
parameter_list|(
specifier|const
name|CXXNewExpr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|/// Determine whether there's something special about the rules of
comment|/// the ABI tell us that 'this' is a complete object within the
comment|/// given function.  Obvious common logic like being defined on a
comment|/// final class will have been taken care of by the caller.
name|virtual
name|bool
name|isThisCompleteObject
argument_list|(
name|GlobalDecl
name|GD
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|CGCXXABI
argument_list|()
expr_stmt|;
comment|/// Gets the mangle context.
name|MangleContext
modifier|&
name|getMangleContext
parameter_list|()
block|{
return|return
operator|*
name|MangleCtx
return|;
block|}
comment|/// Returns true if the given constructor or destructor is one of the
comment|/// kinds that the ABI says returns 'this' (only applies when called
comment|/// non-virtually for destructors).
comment|///
comment|/// There currently is no way to indicate if a destructor returns 'this'
comment|/// when called virtually, and code generation does not support the case.
name|virtual
name|bool
name|HasThisReturn
argument_list|(
name|GlobalDecl
name|GD
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|bool
name|hasMostDerivedReturn
argument_list|(
name|GlobalDecl
name|GD
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// Returns true if the target allows calling a function through a pointer
comment|/// with a different signature than the actual function (or equivalently,
comment|/// bitcasting a function or function pointer to a different function type).
comment|/// In principle in the most general case this could depend on the target, the
comment|/// calling convention, and the actual types of the arguments and return
comment|/// value. Here it just means whether the signature mismatch could *ever* be
comment|/// allowed; in other words, does the target do strict checking of signatures
comment|/// for all calls.
name|virtual
name|bool
name|canCallMismatchedFunctionType
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// If the C++ ABI requires the given type be returned in a particular way,
comment|/// this method sets RetAI and returns true.
name|virtual
name|bool
name|classifyReturnType
argument_list|(
name|CGFunctionInfo
operator|&
name|FI
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Specify how one should pass an argument of a record type.
enum|enum
name|RecordArgABI
block|{
comment|/// Pass it using the normal C aggregate rules for the ABI, potentially
comment|/// introducing extra copies and passing some or all of it in registers.
name|RAA_Default
init|=
literal|0
block|,
comment|/// Pass it on the stack using its defined layout.  The argument must be
comment|/// evaluated directly into the correct stack position in the arguments area,
comment|/// and the call machinery must not move it or introduce extra copies.
name|RAA_DirectInMemory
block|,
comment|/// Pass it as a pointer to temporary memory.
name|RAA_Indirect
block|}
enum|;
comment|/// Returns true if C++ allows us to copy the memory of an object of type RD
comment|/// when it is passed as an argument.
name|bool
name|canCopyArgument
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns how an argument of the given record type should be passed.
name|virtual
name|RecordArgABI
name|getRecordArgABI
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Returns true if the implicit 'sret' parameter comes after the implicit
comment|/// 'this' parameter of C++ instance methods.
name|virtual
name|bool
name|isSRetParameterAfterThis
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Find the LLVM type used to represent the given member pointer
comment|/// type.
name|virtual
name|llvm
operator|::
name|Type
operator|*
name|ConvertMemberPointerType
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
expr_stmt|;
comment|/// Load a member function from an object and a member function
comment|/// pointer.  Apply the this-adjustment and set 'This' to the
comment|/// adjusted value.
name|virtual
name|CGCallee
name|EmitLoadOfMemberFunctionPointer
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|Expr
operator|*
name|E
argument_list|,
name|Address
name|This
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|ThisPtrForCall
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|MemPtr
argument_list|,
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
decl_stmt|;
comment|/// Calculate an l-value from an object and a data member pointer.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitMemberDataPointerAddress
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const Expr *E
argument_list|,
argument|Address Base
argument_list|,
argument|llvm::Value *MemPtr
argument_list|,
argument|const MemberPointerType *MPT
argument_list|)
expr_stmt|;
comment|/// Perform a derived-to-base, base-to-derived, or bitcast member
comment|/// pointer conversion.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitMemberPointerConversion
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|CastExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Src
argument_list|)
expr_stmt|;
comment|/// Perform a derived-to-base, base-to-derived, or bitcast member
comment|/// pointer conversion on a constant value.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitMemberPointerConversion
argument_list|(
specifier|const
name|CastExpr
operator|*
name|E
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Src
argument_list|)
expr_stmt|;
comment|/// Return true if the given member pointer can be zero-initialized
comment|/// (in the C++ sense) with an LLVM zeroinitializer.
name|virtual
name|bool
name|isZeroInitializable
parameter_list|(
specifier|const
name|MemberPointerType
modifier|*
name|MPT
parameter_list|)
function_decl|;
comment|/// Return whether or not a member pointers type is convertible to an IR type.
name|virtual
name|bool
name|isMemberPointerConvertible
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
decl|const
block|{
return|return
name|true
return|;
block|}
comment|/// Create a null member pointer of the given type.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitNullMemberPointer
argument_list|(
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
expr_stmt|;
comment|/// Create a member pointer for the given method.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitMemberFunctionPointer
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|)
expr_stmt|;
comment|/// Create a member pointer for the given field.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitMemberDataPointer
argument_list|(
argument|const MemberPointerType *MPT
argument_list|,
argument|CharUnits offset
argument_list|)
expr_stmt|;
comment|/// Create a member pointer for the given member pointer constant.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitMemberPointer
argument_list|(
argument|const APValue&MP
argument_list|,
argument|QualType MPT
argument_list|)
expr_stmt|;
comment|/// Emit a comparison between two member pointers.  Returns an i1.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitMemberPointerComparison
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *L
argument_list|,
argument|llvm::Value *R
argument_list|,
argument|const MemberPointerType *MPT
argument_list|,
argument|bool Inequality
argument_list|)
expr_stmt|;
comment|/// Determine if a member pointer is non-null.  Returns an i1.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitMemberPointerIsNotNull
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|MemPtr
argument_list|,
specifier|const
name|MemberPointerType
operator|*
name|MPT
argument_list|)
expr_stmt|;
name|protected
label|:
comment|/// A utility method for computing the offset required for the given
comment|/// base-to-derived or derived-to-base member-pointer conversion.
comment|/// Does not handle virtual conversions (in case we ever fully
comment|/// support an ABI that allows this).  Returns null if no adjustment
comment|/// is required.
name|llvm
operator|::
name|Constant
operator|*
name|getMemberPointerAdjustment
argument_list|(
specifier|const
name|CastExpr
operator|*
name|E
argument_list|)
expr_stmt|;
comment|/// \brief Computes the non-virtual adjustment needed for a member pointer
comment|/// conversion along an inheritance path stored in an APValue.  Unlike
comment|/// getMemberPointerAdjustment(), the adjustment can be negative if the path
comment|/// is from a derived type to a base type.
name|CharUnits
name|getMemberPointerPathAdjustment
parameter_list|(
specifier|const
name|APValue
modifier|&
name|MP
parameter_list|)
function_decl|;
name|public
label|:
name|virtual
name|void
name|emitVirtualObjectDelete
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXDeleteExpr
modifier|*
name|DE
parameter_list|,
name|Address
name|Ptr
parameter_list|,
name|QualType
name|ElementType
parameter_list|,
specifier|const
name|CXXDestructorDecl
modifier|*
name|Dtor
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|emitRethrow
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|bool
name|isNoReturn
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|emitThrow
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXThrowExpr
modifier|*
name|E
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getThrowInfo
argument_list|(
argument|QualType T
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
comment|/// \brief Determine whether it's possible to emit a vtable for \p RD, even
comment|/// though we do not know that the vtable has been marked as used by semantic
comment|/// analysis.
name|virtual
name|bool
name|canSpeculativelyEmitVTable
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|emitBeginCatch
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXCatchStmt
modifier|*
name|C
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|llvm
operator|::
name|CallInst
operator|*
name|emitTerminateForUnexpectedException
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Exn
argument_list|)
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|getAddrOfRTTIDescriptor
argument_list|(
argument|QualType Ty
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|CatchTypeInfo
name|getAddrOfCXXCatchHandlerType
parameter_list|(
name|QualType
name|Ty
parameter_list|,
name|QualType
name|CatchHandlerType
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|CatchTypeInfo
name|getCatchAllTypeInfo
parameter_list|()
function_decl|;
name|virtual
name|bool
name|shouldTypeidBeNullChecked
parameter_list|(
name|bool
name|IsDeref
parameter_list|,
name|QualType
name|SrcRecordTy
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|EmitBadTypeidCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitTypeid
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|QualType SrcRecordTy
argument_list|,
argument|Address ThisPtr
argument_list|,
argument|llvm::Type *StdTypeInfoPtrTy
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|shouldDynamicCastCallBeNullChecked
parameter_list|(
name|bool
name|SrcIsPtr
parameter_list|,
name|QualType
name|SrcRecordTy
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitDynamicCastCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address Value
argument_list|,
argument|QualType SrcRecordTy
argument_list|,
argument|QualType DestTy
argument_list|,
argument|QualType DestRecordTy
argument_list|,
argument|llvm::BasicBlock *CastEnd
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitDynamicCastToVoid
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address Value
argument_list|,
argument|QualType SrcRecordTy
argument_list|,
argument|QualType DestTy
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|EmitBadCastCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|GetVirtualBaseClassOffset
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address This
argument_list|,
argument|const CXXRecordDecl *ClassDecl
argument_list|,
argument|const CXXRecordDecl *BaseClassDecl
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|llvm
operator|::
name|BasicBlock
operator|*
name|EmitCtorCompleteObjectHandler
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// Emit the code to initialize hidden members required
comment|/// to handle virtual inheritance, if needed by the ABI.
name|virtual
name|void
name|initializeHiddenVirtualInheritanceMembers
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
block|{}
comment|/// Emit constructor variants required by this ABI.
name|virtual
name|void
name|EmitCXXConstructors
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Notes how many arguments were added to the beginning (Prefix) and ending
comment|/// (Suffix) of an arg list.
comment|///
comment|/// Note that Prefix actually refers to the number of args *after* the first
comment|/// one: `this` arguments always come first.
struct|struct
name|AddedStructorArgs
block|{
name|unsigned
name|Prefix
init|=
literal|0
decl_stmt|;
name|unsigned
name|Suffix
init|=
literal|0
decl_stmt|;
name|AddedStructorArgs
argument_list|()
operator|=
expr|default
expr_stmt|;
name|AddedStructorArgs
argument_list|(
argument|unsigned P
argument_list|,
argument|unsigned S
argument_list|)
block|:
name|Prefix
argument_list|(
name|P
argument_list|)
operator|,
name|Suffix
argument_list|(
argument|S
argument_list|)
block|{}
specifier|static
name|AddedStructorArgs
name|prefix
argument_list|(
argument|unsigned N
argument_list|)
block|{
return|return
block|{
name|N
block|,
literal|0
block|}
return|;
block|}
specifier|static
name|AddedStructorArgs
name|suffix
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
return|return
block|{
literal|0
block|,
name|N
block|}
return|;
block|}
block|}
struct|;
comment|/// Build the signature of the given constructor or destructor variant by
comment|/// adding any required parameters.  For convenience, ArgTys has been
comment|/// initialized with the type of 'this'.
name|virtual
name|AddedStructorArgs
name|buildStructorSignature
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|,
name|StructorType
name|T
argument_list|,
name|SmallVectorImpl
operator|<
name|CanQualType
operator|>
operator|&
name|ArgTys
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Returns true if the given destructor type should be emitted as a linkonce
comment|/// delegating thunk, regardless of whether the dtor is defined in this TU or
comment|/// not.
name|virtual
name|bool
name|useThunkForDtorVariant
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|Dtor
argument_list|,
name|CXXDtorType
name|DT
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Emit destructor variants required by this ABI.
name|virtual
name|void
name|EmitCXXDestructors
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Get the type of the implicit "this" parameter used by a method. May return
comment|/// zero if no specific type is applicable, e.g. if the ABI expects the "this"
comment|/// parameter to point to some artificial offset in a complete object due to
comment|/// vbases being reordered.
name|virtual
specifier|const
name|CXXRecordDecl
modifier|*
name|getThisArgumentTypeForMethod
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
block|{
return|return
name|MD
operator|->
name|getParent
argument_list|()
return|;
block|}
comment|/// Perform ABI-specific "this" argument adjustment required prior to
comment|/// a call of a virtual function.
comment|/// The "VirtualCall" argument is true iff the call itself is virtual.
name|virtual
name|Address
name|adjustThisArgumentForVirtualFunctionCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|GlobalDecl
name|GD
parameter_list|,
name|Address
name|This
parameter_list|,
name|bool
name|VirtualCall
parameter_list|)
block|{
return|return
name|This
return|;
block|}
comment|/// Build a parameter variable suitable for 'this'.
name|void
name|buildThisParam
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|FunctionArgList
modifier|&
name|Params
parameter_list|)
function_decl|;
comment|/// Insert any ABI-specific implicit parameters into the parameter list for a
comment|/// function.  This generally involves extra data for constructors and
comment|/// destructors.
comment|///
comment|/// ABIs may also choose to override the return type, which has been
comment|/// initialized with the type of 'this' if HasThisReturn(CGF.CurGD) is true or
comment|/// the formal return type of the function otherwise.
name|virtual
name|void
name|addImplicitStructorParams
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|QualType
modifier|&
name|ResTy
parameter_list|,
name|FunctionArgList
modifier|&
name|Params
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Get the ABI-specific "this" parameter adjustment to apply in the prologue
comment|/// of a virtual function.
name|virtual
name|CharUnits
name|getVirtualFunctionPrologueThisAdjustment
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
block|{
return|return
name|CharUnits
operator|::
name|Zero
argument_list|()
return|;
block|}
comment|/// Perform ABI-specific "this" parameter adjustment in a virtual function
comment|/// prologue.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|adjustThisParameterInVirtualFunctionPrologue
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|GlobalDecl GD
argument_list|,
argument|llvm::Value *This
argument_list|)
block|{
return|return
name|This
return|;
block|}
comment|/// Emit the ABI-specific prolog for the function.
name|virtual
name|void
name|EmitInstanceFunctionProlog
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Add any ABI-specific implicit arguments needed to call a constructor.
comment|///
comment|/// \return The number of arguments added at the beginning and end of the
comment|/// call, which is typically zero or one.
name|virtual
name|AddedStructorArgs
name|addImplicitConstructorArgs
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|CallArgList
modifier|&
name|Args
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit the destructor call.
name|virtual
name|void
name|EmitDestructorCall
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|CXXDestructorDecl
modifier|*
name|DD
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|,
name|bool
name|ForVirtualBase
parameter_list|,
name|bool
name|Delegating
parameter_list|,
name|Address
name|This
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emits the VTable definitions required for the given record type.
name|virtual
name|void
name|emitVTableDefinitions
parameter_list|(
name|CodeGenVTables
modifier|&
name|CGVT
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Checks if ABI requires extra virtual offset for vtable field.
name|virtual
name|bool
name|isVirtualOffsetNeededForVTableField
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|CodeGenFunction
operator|::
name|VPtr
name|Vptr
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Checks if ABI requires to initialize vptrs for given dynamic class.
name|virtual
name|bool
name|doStructorsInitializeVPtrs
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Get the address point of the vtable for the given base subobject.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|getVTableAddressPoint
argument_list|(
argument|BaseSubobject Base
argument_list|,
argument|const CXXRecordDecl *VTableClass
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Get the address point of the vtable for the given base subobject while
comment|/// building a constructor or a destructor.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|getVTableAddressPointInStructor
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const CXXRecordDecl *RD
argument_list|,
argument|BaseSubobject Base
argument_list|,
argument|const CXXRecordDecl *NearestVBase
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Get the address point of the vtable for the given base subobject while
comment|/// building a constexpr.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|getVTableAddressPointForConstExpr
argument_list|(
argument|BaseSubobject Base
argument_list|,
argument|const CXXRecordDecl *VTableClass
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Get the address of the vtable for the given record decl which should be
comment|/// used for the vptr at the given offset in RD.
name|virtual
name|llvm
operator|::
name|GlobalVariable
operator|*
name|getAddrOfVTable
argument_list|(
argument|const CXXRecordDecl *RD
argument_list|,
argument|CharUnits VPtrOffset
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Build a virtual function pointer in the ABI-specific way.
name|virtual
name|CGCallee
name|getVirtualFunctionPointer
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
name|Address
name|This
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|Ty
argument_list|,
name|SourceLocation
name|Loc
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Emit the ABI-specific virtual destructor call.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitVirtualDestructorCall
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|const CXXDestructorDecl *Dtor
argument_list|,
argument|CXXDtorType DtorType
argument_list|,
argument|Address This
argument_list|,
argument|const CXXMemberCallExpr *CE
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|adjustCallArgsForDestructorThunk
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|GlobalDecl
name|GD
parameter_list|,
name|CallArgList
modifier|&
name|CallArgs
parameter_list|)
block|{}
comment|/// Emit any tables needed to implement virtual inheritance.  For Itanium,
comment|/// this emits virtual table tables.  For the MSVC++ ABI, this emits virtual
comment|/// base tables.
name|virtual
name|void
name|emitVirtualInheritanceTables
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|setThunkLinkage
argument_list|(
name|llvm
operator|::
name|Function
operator|*
name|Thunk
argument_list|,
name|bool
name|ForVTable
argument_list|,
name|GlobalDecl
name|GD
argument_list|,
name|bool
name|ReturnAdjustment
argument_list|)
init|=
literal|0
decl_stmt|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|performThisAdjustment
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address This
argument_list|,
argument|const ThisAdjustment&TA
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|performReturnAdjustment
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|Address Ret
argument_list|,
argument|const ReturnAdjustment&RA
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|EmitReturnFromThunk
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
name|RValue
name|RV
parameter_list|,
name|QualType
name|ResultType
parameter_list|)
function_decl|;
name|virtual
name|size_t
name|getSrcArgforCopyCtor
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
argument_list|,
name|FunctionArgList
operator|&
name|Args
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Gets the offsets of all the virtual base pointers in a given class.
name|virtual
name|std
operator|::
name|vector
operator|<
name|CharUnits
operator|>
name|getVBPtrOffsets
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
comment|/// Gets the pure virtual member call function.
name|virtual
name|StringRef
name|GetPureVirtualCallName
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Gets the deleted virtual member call name.
name|virtual
name|StringRef
name|GetDeletedVirtualCallName
parameter_list|()
init|=
literal|0
function_decl|;
comment|/**************************** Array cookies ******************************/
comment|/// Returns the extra size required in order to store the array
comment|/// cookie for the given new-expression.  May return 0 to indicate that no
comment|/// array cookie is required.
comment|///
comment|/// Several cases are filtered out before this method is called:
comment|///   - non-array allocations never need a cookie
comment|///   - calls to \::operator new(size_t, void*) never need a cookie
comment|///
comment|/// \param expr - the new-expression being allocated.
name|virtual
name|CharUnits
name|GetArrayCookieSize
parameter_list|(
specifier|const
name|CXXNewExpr
modifier|*
name|expr
parameter_list|)
function_decl|;
comment|/// Initialize the array cookie for the given allocation.
comment|///
comment|/// \param NewPtr - a char* which is the presumed-non-null
comment|///   return value of the allocation function
comment|/// \param NumElements - the computed number of elements,
comment|///   potentially collapsed from the multidimensional array case;
comment|///   always a size_t
comment|/// \param ElementType - the base element allocated type,
comment|///   i.e. the allocated type after stripping all array types
name|virtual
name|Address
name|InitializeArrayCookie
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|Address
name|NewPtr
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|NumElements
argument_list|,
specifier|const
name|CXXNewExpr
operator|*
name|expr
argument_list|,
name|QualType
name|ElementType
argument_list|)
decl_stmt|;
comment|/// Reads the array cookie associated with the given pointer,
comment|/// if it has one.
comment|///
comment|/// \param Ptr - a pointer to the first element in the array
comment|/// \param ElementType - the base element type of elements of the array
comment|/// \param NumElements - an out parameter which will be initialized
comment|///   with the number of elements allocated, or zero if there is no
comment|///   cookie
comment|/// \param AllocPtr - an out parameter which will be initialized
comment|///   with a char* pointing to the address returned by the allocation
comment|///   function
comment|/// \param CookieSize - an out parameter which will be initialized
comment|///   with the size of the cookie, or zero if there is no cookie
name|virtual
name|void
name|ReadArrayCookie
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|Address
name|Ptr
argument_list|,
specifier|const
name|CXXDeleteExpr
operator|*
name|expr
argument_list|,
name|QualType
name|ElementType
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|NumElements
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|AllocPtr
argument_list|,
name|CharUnits
operator|&
name|CookieSize
argument_list|)
decl_stmt|;
comment|/// Return whether the given global decl needs a VTT parameter.
name|virtual
name|bool
name|NeedsVTTParameter
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
name|protected
label|:
comment|/// Returns the extra size required in order to store the array
comment|/// cookie for the given type.  Assumes that an array cookie is
comment|/// required.
name|virtual
name|CharUnits
name|getArrayCookieSizeImpl
parameter_list|(
name|QualType
name|elementType
parameter_list|)
function_decl|;
comment|/// Reads the array cookie for an allocation which is known to have one.
comment|/// This is called by the standard implementation of ReadArrayCookie.
comment|///
comment|/// \param ptr - a pointer to the allocation made for an array, as a char*
comment|/// \param cookieSize - the computed cookie size of an array
comment|///
comment|/// Other parameters are as above.
comment|///
comment|/// \return a size_t
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|readArrayCookieImpl
argument_list|(
argument|CodeGenFunction&IGF
argument_list|,
argument|Address ptr
argument_list|,
argument|CharUnits cookieSize
argument_list|)
expr_stmt|;
name|public
label|:
comment|/*************************** Static local guards ****************************/
comment|/// Emits the guarded initializer and destructor setup for the given
comment|/// variable, given that it couldn't be emitted as a constant.
comment|/// If \p PerformInit is false, the initialization has been folded to a
comment|/// constant and should not be performed.
comment|///
comment|/// The variable may be:
comment|///   - a static local variable
comment|///   - a static data member of a class template instantiation
name|virtual
name|void
name|EmitGuardedInit
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|GlobalVariable
operator|*
name|DeclPtr
argument_list|,
name|bool
name|PerformInit
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// Emit code to force the execution of a destructor during global
comment|/// teardown.  The default implementation of this uses atexit.
comment|///
comment|/// \param Dtor - a function taking a single pointer argument
comment|/// \param Addr - a pointer to pass to the destructor function.
name|virtual
name|void
name|registerGlobalDtor
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
specifier|const
name|VarDecl
operator|&
name|D
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Dtor
argument_list|,
name|llvm
operator|::
name|Constant
operator|*
name|Addr
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/*************************** thread_local initialization ********************/
comment|/// Emits ABI-required functions necessary to initialize thread_local
comment|/// variables in this translation unit.
comment|///
comment|/// \param CXXThreadLocals - The thread_local declarations in this translation
comment|///        unit.
comment|/// \param CXXThreadLocalInits - If this translation unit contains any
comment|///        non-constant initialization or non-trivial destruction for
comment|///        thread_local variables, a list of functions to perform the
comment|///        initialization.
name|virtual
name|void
name|EmitThreadLocalInitFuncs
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|CXXThreadLocals
argument_list|,
name|ArrayRef
operator|<
name|llvm
operator|::
name|Function
operator|*
operator|>
name|CXXThreadLocalInits
argument_list|,
name|ArrayRef
operator|<
specifier|const
name|VarDecl
operator|*
operator|>
name|CXXThreadLocalInitVars
argument_list|)
init|=
literal|0
decl_stmt|;
comment|// Determine if references to thread_local global variables can be made
comment|// directly or require access through a thread wrapper function.
name|virtual
name|bool
name|usesThreadWrapperFunction
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Emit a reference to a non-local thread_local variable (including
comment|/// triggering the initialization of all thread_local variables in its
comment|/// translation unit).
name|virtual
name|LValue
name|EmitThreadLocalVarDeclLValue
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|,
name|QualType
name|LValType
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a single constructor/destructor with the given type from a C++
comment|/// constructor Decl.
name|virtual
name|void
name|emitCXXStructor
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|StructorType
name|Type
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|// Create an instance of a C++ ABI class:
comment|/// Creates an Itanium-family ABI.
name|CGCXXABI
modifier|*
name|CreateItaniumCXXABI
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
comment|/// Creates a Microsoft-family ABI.
name|CGCXXABI
modifier|*
name|CreateMicrosoftCXXABI
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

