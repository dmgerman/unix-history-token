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
name|CLANG_CODEGEN_CXXABI_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CXXABI_H
end_define

begin_include
include|#
directive|include
file|"CodeGenFunction.h"
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
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
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
name|CodeGenFunction
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
comment|/// Implements C++ ABI-specific code generation functions.
name|class
name|CGCXXABI
block|{
name|protected
label|:
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
name|llvm
operator|::
name|OwningPtr
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
operator|&
name|getThisDecl
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXThisDecl
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
operator|&
name|getThisValue
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXThisValue
return|;
block|}
name|ImplicitParamDecl
modifier|*
modifier|&
name|getVTTDecl
parameter_list|(
name|CodeGenFunction
modifier|&
name|CGF
parameter_list|)
block|{
return|return
name|CGF
operator|.
name|CXXVTTDecl
return|;
block|}
name|llvm
operator|::
name|Value
operator|*
operator|&
name|getVTTValue
argument_list|(
argument|CodeGenFunction&CGF
argument_list|)
block|{
return|return
name|CGF
operator|.
name|CXXVTTValue
return|;
block|}
comment|/// Build a parameter variable suitable for 'this'.
name|void
name|BuildThisParam
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
comment|/// Perform prolog initialization of the parameter variable suitable
comment|/// for 'this' emitted by BuildThisParam.
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
comment|/// Find the LLVM type used to represent the given member pointer
comment|/// type.
name|virtual
specifier|const
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
name|llvm
operator|::
name|Value
operator|*
name|EmitLoadOfMemberFunctionPointer
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
operator|&
name|This
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
comment|/// Calculate an l-value from an object and a data member pointer.
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|EmitMemberDataPointerAddress
argument_list|(
name|CodeGenFunction
operator|&
name|CGF
argument_list|,
name|llvm
operator|::
name|Value
operator|*
name|Base
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
comment|/// Perform a derived-to-base or base-to-derived member pointer
comment|/// conversion.
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
comment|/// Perform a derived-to-base or base-to-derived member pointer
comment|/// conversion on a constant member pointer.
name|virtual
name|llvm
operator|::
name|Constant
operator|*
name|EmitMemberPointerConversion
argument_list|(
name|llvm
operator|::
name|Constant
operator|*
name|C
argument_list|,
specifier|const
name|CastExpr
operator|*
name|E
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
name|EmitMemberPointer
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
comment|/// Build the signature of the given constructor variant by adding
comment|/// any required parameters.  For convenience, ResTy has been
comment|/// initialized to 'void', and ArgTys has been initialized with the
comment|/// type of 'this' (although this may be changed by the ABI) and
comment|/// will have the formal parameters added to it afterwards.
comment|///
comment|/// If there are ever any ABIs where the implicit parameters are
comment|/// intermixed with the formal parameters, we can address those
comment|/// then.
name|virtual
name|void
name|BuildConstructorSignature
argument_list|(
specifier|const
name|CXXConstructorDecl
operator|*
name|Ctor
argument_list|,
name|CXXCtorType
name|T
argument_list|,
name|CanQualType
operator|&
name|ResTy
argument_list|,
name|llvm
operator|::
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
comment|/// Build the signature of the given destructor variant by adding
comment|/// any required parameters.  For convenience, ResTy has been
comment|/// initialized to 'void' and ArgTys has been initialized with the
comment|/// type of 'this' (although this may be changed by the ABI).
name|virtual
name|void
name|BuildDestructorSignature
argument_list|(
specifier|const
name|CXXDestructorDecl
operator|*
name|Dtor
argument_list|,
name|CXXDtorType
name|T
argument_list|,
name|CanQualType
operator|&
name|ResTy
argument_list|,
name|llvm
operator|::
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
comment|/// Build the ABI-specific portion of the parameter list for a
comment|/// function.  This generally involves a 'this' parameter and
comment|/// possibly some extra data for constructors and destructors.
comment|///
comment|/// ABIs may also choose to override the return type, which has been
comment|/// initialized with the formal return type of the function.
name|virtual
name|void
name|BuildInstanceFunctionParams
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
comment|/**************************** Array cookies ******************************/
comment|/// Returns the extra size required in order to store the array
comment|/// cookie for the given type.  May return 0 to indicate that no
comment|/// array cookie is required.
comment|///
comment|/// Several cases are filtered out before this method is called:
comment|///   - non-array allocations never need a cookie
comment|///   - calls to ::operator new(size_t, void*) never need a cookie
comment|///
comment|/// \param ElementType - the allocated type of the expression,
comment|///   i.e. the pointee type of the expression result type
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
comment|///   potentially collapsed from the multidimensional array case
comment|/// \param ElementType - the base element allocated type,
comment|///   i.e. the allocated type after stripping all array types
name|virtual
name|llvm
operator|::
name|Value
operator|*
name|InitializeArrayCookie
argument_list|(
argument|CodeGenFunction&CGF
argument_list|,
argument|llvm::Value *NewPtr
argument_list|,
argument|llvm::Value *NumElements
argument_list|,
argument|const CXXNewExpr *expr
argument_list|,
argument|QualType ElementType
argument_list|)
expr_stmt|;
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
name|llvm
operator|::
name|Value
operator|*
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
comment|/*************************** Static local guards ****************************/
comment|/// Emits the guarded initializer and destructor setup for the given
comment|/// variable, given that it couldn't be emitted as a constant.
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
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// Creates an instance of a C++ ABI class.
name|CGCXXABI
modifier|*
name|CreateARMCXXABI
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
name|CGCXXABI
modifier|*
name|CreateItaniumCXXABI
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
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

