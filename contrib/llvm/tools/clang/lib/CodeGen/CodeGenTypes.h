begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenTypes.h - Type translation for LLVM CodeGen -----*- C++ -*-===//
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
comment|// This is the code that handles AST -> LLVM type lowering.
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
name|LLVM_CLANG_LIB_CODEGEN_CODEGENTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_CODEGEN_CODEGENTYPES_H
end_define

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"clang/CodeGen/CGFunctionInfo.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Sema.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionType
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|StructType
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
name|template
operator|<
name|typename
operator|>
name|class
name|CanQual
expr_stmt|;
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
name|CodeGenOptions
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|FunctionProtoType
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCIvarDecl
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|RecordDecl
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
name|class
name|Type
decl_stmt|;
typedef|typedef
name|CanQual
operator|<
name|Type
operator|>
name|CanQualType
expr_stmt|;
name|class
name|GlobalDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|ABIInfo
decl_stmt|;
name|class
name|CGCXXABI
decl_stmt|;
name|class
name|CGRecordLayout
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|RequiredArgs
decl_stmt|;
name|enum
name|class
name|StructorType
block|{
name|Complete
operator|,
comment|// constructor or destructor
name|Base
operator|,
comment|// constructor or destructor
name|Deleting
comment|// destructor only
block|}
empty_stmt|;
specifier|inline
name|CXXCtorType
name|toCXXCtorType
parameter_list|(
name|StructorType
name|T
parameter_list|)
block|{
switch|switch
condition|(
name|T
condition|)
block|{
case|case
name|StructorType
operator|::
name|Complete
case|:
return|return
name|Ctor_Complete
return|;
case|case
name|StructorType
operator|::
name|Base
case|:
return|return
name|Ctor_Base
return|;
case|case
name|StructorType
operator|::
name|Deleting
case|:
name|llvm_unreachable
argument_list|(
literal|"cannot have a deleting ctor"
argument_list|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"not a StructorType"
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|StructorType
name|getFromCtorType
parameter_list|(
name|CXXCtorType
name|T
parameter_list|)
block|{
switch|switch
condition|(
name|T
condition|)
block|{
case|case
name|Ctor_Complete
case|:
return|return
name|StructorType
operator|::
name|Complete
return|;
case|case
name|Ctor_Base
case|:
return|return
name|StructorType
operator|::
name|Base
return|;
case|case
name|Ctor_Comdat
case|:
name|llvm_unreachable
argument_list|(
literal|"not expecting a COMDAT"
argument_list|)
expr_stmt|;
case|case
name|Ctor_CopyingClosure
case|:
case|case
name|Ctor_DefaultClosure
case|:
name|llvm_unreachable
argument_list|(
literal|"not expecting a closure"
argument_list|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"not a CXXCtorType"
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|CXXDtorType
name|toCXXDtorType
parameter_list|(
name|StructorType
name|T
parameter_list|)
block|{
switch|switch
condition|(
name|T
condition|)
block|{
case|case
name|StructorType
operator|::
name|Complete
case|:
return|return
name|Dtor_Complete
return|;
case|case
name|StructorType
operator|::
name|Base
case|:
return|return
name|Dtor_Base
return|;
case|case
name|StructorType
operator|::
name|Deleting
case|:
return|return
name|Dtor_Deleting
return|;
block|}
name|llvm_unreachable
argument_list|(
literal|"not a StructorType"
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|StructorType
name|getFromDtorType
parameter_list|(
name|CXXDtorType
name|T
parameter_list|)
block|{
switch|switch
condition|(
name|T
condition|)
block|{
case|case
name|Dtor_Deleting
case|:
return|return
name|StructorType
operator|::
name|Deleting
return|;
case|case
name|Dtor_Complete
case|:
return|return
name|StructorType
operator|::
name|Complete
return|;
case|case
name|Dtor_Base
case|:
return|return
name|StructorType
operator|::
name|Base
return|;
case|case
name|Dtor_Comdat
case|:
name|llvm_unreachable
argument_list|(
literal|"not expecting a COMDAT"
argument_list|)
expr_stmt|;
block|}
name|llvm_unreachable
argument_list|(
literal|"not a CXXDtorType"
argument_list|)
expr_stmt|;
block|}
comment|/// This class organizes the cross-module state that is used while lowering
comment|/// AST types to LLVM types.
name|class
name|CodeGenTypes
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|// Some of this stuff should probably be left on the CGM.
name|ASTContext
modifier|&
name|Context
decl_stmt|;
name|llvm
operator|::
name|Module
operator|&
name|TheModule
expr_stmt|;
specifier|const
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|CGCXXABI
modifier|&
name|TheCXXABI
decl_stmt|;
comment|// This should not be moved earlier, since its initialization depends on some
comment|// of the previous reference members being already initialized
specifier|const
name|ABIInfo
modifier|&
name|TheABIInfo
decl_stmt|;
comment|/// The opaque type map for Objective-C interfaces. All direct
comment|/// manipulation is done by the runtime interfaces, which are
comment|/// responsible for coercing to the appropriate type; these opaque
comment|/// types are never refined.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|ObjCInterfaceType
operator|*
operator|,
name|llvm
operator|::
name|Type
operator|*
operator|>
name|InterfaceTypes
expr_stmt|;
comment|/// Maps clang struct type with corresponding record layout info.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|CGRecordLayout
operator|*
operator|>
name|CGRecordLayouts
expr_stmt|;
comment|/// Contains the LLVM IR type for any converted RecordDecl.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|StructType
operator|*
operator|>
name|RecordDeclTypes
expr_stmt|;
comment|/// Hold memoized CGFunctionInfo results.
name|llvm
operator|::
name|FoldingSet
operator|<
name|CGFunctionInfo
operator|>
name|FunctionInfos
expr_stmt|;
comment|/// This set keeps track of records that we're currently converting
comment|/// to an IR type.  For example, when converting:
comment|/// struct A { struct B { int x; } } when processing 'x', the 'A' and 'B'
comment|/// types will be in this set.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|Type
operator|*
operator|,
literal|4
operator|>
name|RecordsBeingLaidOut
expr_stmt|;
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CGFunctionInfo
operator|*
operator|,
literal|4
operator|>
name|FunctionsBeingProcessed
expr_stmt|;
comment|/// True if we didn't layout a function due to a being inside
comment|/// a recursive struct conversion, set this to true.
name|bool
name|SkippedLayout
decl_stmt|;
name|SmallVector
operator|<
specifier|const
name|RecordDecl
operator|*
operator|,
literal|8
operator|>
name|DeferredRecords
expr_stmt|;
comment|/// This map keeps cache of llvm::Types and maps clang::Type to
comment|/// corresponding llvm::Type.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
name|llvm
operator|::
name|Type
operator|*
operator|>
name|TypeCache
expr_stmt|;
name|llvm
operator|::
name|SmallSet
operator|<
specifier|const
name|Type
operator|*
operator|,
literal|8
operator|>
name|RecordsWithOpaqueMemberPointers
expr_stmt|;
name|unsigned
name|ClangCallConvToLLVMCallConv
parameter_list|(
name|CallingConv
name|CC
parameter_list|)
function_decl|;
name|public
label|:
name|CodeGenTypes
argument_list|(
name|CodeGenModule
operator|&
name|cgm
argument_list|)
expr_stmt|;
operator|~
name|CodeGenTypes
argument_list|()
expr_stmt|;
specifier|const
name|llvm
operator|::
name|DataLayout
operator|&
name|getDataLayout
argument_list|()
specifier|const
block|{
return|return
name|TheModule
operator|.
name|getDataLayout
argument_list|()
return|;
block|}
name|ASTContext
operator|&
name|getContext
argument_list|()
specifier|const
block|{
return|return
name|Context
return|;
block|}
specifier|const
name|ABIInfo
operator|&
name|getABIInfo
argument_list|()
specifier|const
block|{
return|return
name|TheABIInfo
return|;
block|}
specifier|const
name|TargetInfo
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
name|CGCXXABI
operator|&
name|getCXXABI
argument_list|()
specifier|const
block|{
return|return
name|TheCXXABI
return|;
block|}
name|llvm
operator|::
name|LLVMContext
operator|&
name|getLLVMContext
argument_list|()
block|{
return|return
name|TheModule
operator|.
name|getContext
argument_list|()
return|;
block|}
comment|/// ConvertType - Convert type T into a llvm::Type.
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// \brief Converts the GlobalDecl into an llvm::Type. This should be used
comment|/// when we know the target of the function we want to convert.  This is
comment|/// because some functions (explicitly, those with pass_object_size
comment|/// parameters) may not have the same signature as their type portrays, and
comment|/// can only be called directly.
name|llvm
operator|::
name|Type
operator|*
name|ConvertFunctionType
argument_list|(
argument|QualType FT
argument_list|,
argument|const FunctionDecl *FD = nullptr
argument_list|)
expr_stmt|;
comment|/// ConvertTypeForMem - Convert type T into a llvm::Type.  This differs from
comment|/// ConvertType in that it is used to convert to the memory representation for
comment|/// a type.  For example, the scalar representation for _Bool is i1, but the
comment|/// memory representation is usually i8 or i32, depending on the target.
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMem
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// GetFunctionType - Get the LLVM function type for \arg Info.
name|llvm
operator|::
name|FunctionType
operator|*
name|GetFunctionType
argument_list|(
specifier|const
name|CGFunctionInfo
operator|&
name|Info
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|FunctionType
operator|*
name|GetFunctionType
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// isFuncTypeConvertible - Utility to check whether a function type can
comment|/// be converted to an LLVM type (i.e. doesn't depend on an incomplete tag
comment|/// type).
name|bool
name|isFuncTypeConvertible
parameter_list|(
specifier|const
name|FunctionType
modifier|*
name|FT
parameter_list|)
function_decl|;
name|bool
name|isFuncParamTypeConvertible
parameter_list|(
name|QualType
name|Ty
parameter_list|)
function_decl|;
comment|/// Determine if a C++ inheriting constructor should have parameters matching
comment|/// those of its inherited constructor.
name|bool
name|inheritingCtorHasParams
parameter_list|(
specifier|const
name|InheritedConstructor
modifier|&
name|Inherited
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|)
function_decl|;
comment|/// GetFunctionTypeForVTable - Get the LLVM function type for use in a vtable,
comment|/// given a CXXMethodDecl. If the method to has an incomplete return type,
comment|/// and/or incomplete argument types, this will return the opaque type.
name|llvm
operator|::
name|Type
operator|*
name|GetFunctionTypeForVTable
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
specifier|const
name|CGRecordLayout
modifier|&
name|getCGRecordLayout
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
parameter_list|)
function_decl|;
comment|/// UpdateCompletedType - When we find the full definition for a TagDecl,
comment|/// replace the 'opaque' type we previously made for it if applicable.
name|void
name|UpdateCompletedType
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|TD
parameter_list|)
function_decl|;
comment|/// \brief Remove stale types from the type cache when an inheritance model
comment|/// gets assigned to a class.
name|void
name|RefreshTypeCacheForClass
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|// The arrangement methods are split into three families:
comment|//   - those meant to drive the signature and prologue/epilogue
comment|//     of a function declaration or definition,
comment|//   - those meant for the computation of the LLVM type for an abstract
comment|//     appearance of a function, and
comment|//   - those meant for performing the IR-generation of a call.
comment|// They differ mainly in how they deal with optional (i.e. variadic)
comment|// arguments, as well as unprototyped functions.
comment|//
comment|// Key points:
comment|// - The CGFunctionInfo for emitting a specific call site must include
comment|//   entries for the optional arguments.
comment|// - The function type used at the call site must reflect the formal
comment|//   signature of the declaration being called, or else the call will
comment|//   go awry.
comment|// - For the most part, unprototyped functions are called by casting to
comment|//   a formal signature inferred from the specific argument types used
comment|//   at the call-site.  However, some targets (e.g. x86-64) screw with
comment|//   this for compatibility reasons.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeGlobalDeclaration
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
comment|/// Given a function info for a declaration, return the function info
comment|/// for a call with the given arguments.
comment|///
comment|/// Often this will be able to simply return the declaration info.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCall
parameter_list|(
specifier|const
name|CGFunctionInfo
modifier|&
name|declFI
parameter_list|,
specifier|const
name|CallArgList
modifier|&
name|args
parameter_list|)
function_decl|;
comment|/// Free functions are functions that are compatible with an ordinary
comment|/// C function pointer type.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFunctionDeclaration
parameter_list|(
specifier|const
name|FunctionDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFreeFunctionCall
parameter_list|(
specifier|const
name|CallArgList
modifier|&
name|Args
parameter_list|,
specifier|const
name|FunctionType
modifier|*
name|Ty
parameter_list|,
name|bool
name|ChainCall
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeFreeFunctionType
argument_list|(
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
name|CanQual
operator|<
name|FunctionNoProtoType
operator|>
name|Ty
argument_list|)
decl_stmt|;
comment|/// A nullary function is a freestanding function of type 'void ()'.
comment|/// This method works for both calls and declarations.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeNullaryFunction
parameter_list|()
function_decl|;
comment|/// A builtin function is a freestanding function using the default
comment|/// C conventions.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeBuiltinFunctionDeclaration
parameter_list|(
name|QualType
name|resultType
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|args
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeBuiltinFunctionDeclaration
argument_list|(
name|CanQualType
name|resultType
argument_list|,
name|ArrayRef
operator|<
name|CanQualType
operator|>
name|argTypes
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeBuiltinFunctionCall
parameter_list|(
name|QualType
name|resultType
parameter_list|,
specifier|const
name|CallArgList
modifier|&
name|args
parameter_list|)
function_decl|;
comment|/// Objective-C methods are C functions with some implicit parameters.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeObjCMethodDeclaration
parameter_list|(
specifier|const
name|ObjCMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeObjCMessageSendSignature
parameter_list|(
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
name|arrangeUnprototypedObjCMessageSend
parameter_list|(
name|QualType
name|returnType
parameter_list|,
specifier|const
name|CallArgList
modifier|&
name|args
parameter_list|)
function_decl|;
comment|/// Block invocation functions are C functions with an implicit parameter.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeBlockFunctionDeclaration
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|type
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|args
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeBlockFunctionCall
parameter_list|(
specifier|const
name|CallArgList
modifier|&
name|args
parameter_list|,
specifier|const
name|FunctionType
modifier|*
name|type
parameter_list|)
function_decl|;
comment|/// C++ methods have some special rules and also have implicit parameters.
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXMethodDeclaration
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXStructorDeclaration
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|,
name|StructorType
name|Type
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXConstructorCall
parameter_list|(
specifier|const
name|CallArgList
modifier|&
name|Args
parameter_list|,
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|CtorKind
parameter_list|,
name|unsigned
name|ExtraPrefixArgs
parameter_list|,
name|unsigned
name|ExtraSuffixArgs
parameter_list|,
name|bool
name|PassProtoArgs
init|=
name|true
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXMethodCall
parameter_list|(
specifier|const
name|CallArgList
modifier|&
name|args
parameter_list|,
specifier|const
name|FunctionProtoType
modifier|*
name|type
parameter_list|,
name|RequiredArgs
name|required
parameter_list|,
name|unsigned
name|numPrefixArgs
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeMSMemberPointerThunk
parameter_list|(
specifier|const
name|CXXMethodDecl
modifier|*
name|MD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeMSCtorClosure
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|CD
parameter_list|,
name|CXXCtorType
name|CT
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeCXXMethodType
parameter_list|(
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
comment|/// "Arrange" the LLVM information for a call or type with the given
comment|/// signature.  This is largely an internal method; other clients
comment|/// should use one of the above routines, which ultimately defer to
comment|/// this.
comment|///
comment|/// \param argTypes - must all actually be canonical as params
specifier|const
name|CGFunctionInfo
modifier|&
name|arrangeLLVMFunctionInfo
argument_list|(
name|CanQualType
name|returnType
argument_list|,
name|bool
name|instanceMethod
argument_list|,
name|bool
name|chainCall
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
name|ArrayRef
operator|<
name|FunctionProtoType
operator|::
name|ExtParameterInfo
operator|>
name|paramInfos
argument_list|,
name|RequiredArgs
name|args
argument_list|)
decl_stmt|;
comment|/// \brief Compute a new LLVM record layout object for the given record.
name|CGRecordLayout
modifier|*
name|ComputeRecordLayout
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|StructType
operator|*
name|Ty
argument_list|)
decl_stmt|;
comment|/// addRecordTypeName - Compute a name from the given record decl with an
comment|/// optional suffix and name the given LLVM type using it.
name|void
name|addRecordTypeName
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|RD
argument_list|,
name|llvm
operator|::
name|StructType
operator|*
name|Ty
argument_list|,
name|StringRef
name|suffix
argument_list|)
decl_stmt|;
name|public
label|:
comment|// These are internal details of CGT that shouldn't be used externally.
comment|/// ConvertRecordDeclType - Lay out a tagged decl type like struct or union.
name|llvm
operator|::
name|StructType
operator|*
name|ConvertRecordDeclType
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|TD
argument_list|)
expr_stmt|;
comment|/// getExpandedTypes - Expand the type \arg Ty into the LLVM
comment|/// argument types it would be passed as. See ABIArgInfo::Expand.
name|void
name|getExpandedTypes
argument_list|(
name|QualType
name|Ty
argument_list|,
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|>
operator|::
name|iterator
operator|&
name|TI
argument_list|)
decl_stmt|;
comment|/// IsZeroInitializable - Return whether a type can be
comment|/// zero-initialized (in the C++ sense) with an LLVM zeroinitializer.
name|bool
name|isZeroInitializable
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// Check if the pointer type can be zero-initialized (in the C++ sense)
comment|/// with an LLVM zeroinitializer.
name|bool
name|isPointerZeroInitializable
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// IsZeroInitializable - Return whether a record type can be
comment|/// zero-initialized (in the C++ sense) with an LLVM zeroinitializer.
name|bool
name|isZeroInitializable
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|bool
name|isRecordLayoutComplete
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
decl_stmt|;
name|bool
name|noRecordsBeingLaidOut
argument_list|()
specifier|const
block|{
return|return
name|RecordsBeingLaidOut
operator|.
name|empty
argument_list|()
return|;
block|}
name|bool
name|isRecordBeingLaidOut
argument_list|(
specifier|const
name|Type
operator|*
name|Ty
argument_list|)
decl|const
block|{
return|return
name|RecordsBeingLaidOut
operator|.
name|count
argument_list|(
name|Ty
argument_list|)
return|;
block|}
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

