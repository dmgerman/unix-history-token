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
name|CLANG_CODEGEN_CODEGENTYPES_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CODEGENTYPES_H
end_define

begin_include
include|#
directive|include
file|"llvm/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"CGCall.h"
end_include

begin_include
include|#
directive|include
file|"GlobalDecl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|FunctionType
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|OpaqueType
decl_stmt|;
name|class
name|PATypeHolder
decl_stmt|;
name|class
name|TargetData
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ABIInfo
decl_stmt|;
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
name|namespace
name|CodeGen
block|{
name|class
name|CGRecordLayout
decl_stmt|;
comment|/// CodeGenTypes - This class organizes the cross-module state that is used
comment|/// while lowering AST types to LLVM types.
name|class
name|CodeGenTypes
block|{
name|ASTContext
modifier|&
name|Context
decl_stmt|;
specifier|const
name|TargetInfo
modifier|&
name|Target
decl_stmt|;
name|llvm
operator|::
name|Module
operator|&
name|TheModule
expr_stmt|;
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|TheTargetData
expr_stmt|;
specifier|const
name|ABIInfo
modifier|&
name|TheABIInfo
decl_stmt|;
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|QualType
operator|,
name|llvm
operator|::
name|OpaqueType
operator|*
operator|>
operator|,
literal|8
operator|>
name|PointersToResolve
expr_stmt|;
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
name|PATypeHolder
operator|>
name|TagDeclTypes
expr_stmt|;
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
name|PATypeHolder
operator|>
name|FunctionTypes
expr_stmt|;
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
specifier|const
name|llvm
operator|::
name|Type
operator|*
operator|>
name|InterfaceTypes
expr_stmt|;
comment|/// CGRecordLayouts - This maps llvm struct type with corresponding
comment|/// record layout info.
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
comment|/// FunctionInfos - Hold memoized CGFunctionInfo results.
name|llvm
operator|::
name|FoldingSet
operator|<
name|CGFunctionInfo
operator|>
name|FunctionInfos
expr_stmt|;
name|private
label|:
comment|/// TypeCache - This map keeps cache of llvm::Types (through PATypeHolder)
comment|/// and maps llvm::Types to corresponding clang::Type. llvm::PATypeHolder is
comment|/// used instead of llvm::Type because it allows us to bypass potential
comment|/// dangling type pointers due to type refinement on llvm side.
name|llvm
operator|::
name|DenseMap
operator|<
name|Type
operator|*
operator|,
name|llvm
operator|::
name|PATypeHolder
operator|>
name|TypeCache
expr_stmt|;
comment|/// ConvertNewType - Convert type T into a llvm::Type. Do not use this
comment|/// method directly because it does not do any type caching. This method
comment|/// is available only for ConvertType(). CovertType() is preferred
comment|/// interface to convert type T into a llvm::Type.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertNewType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
name|public
label|:
name|CodeGenTypes
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|,
name|llvm
operator|::
name|Module
operator|&
name|M
argument_list|,
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|TD
argument_list|,
specifier|const
name|ABIInfo
operator|&
name|Info
argument_list|)
expr_stmt|;
operator|~
name|CodeGenTypes
argument_list|()
expr_stmt|;
specifier|const
name|llvm
operator|::
name|TargetData
operator|&
name|getTargetData
argument_list|()
specifier|const
block|{
return|return
name|TheTargetData
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
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertType
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeRecursive
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// ConvertTypeForMem - Convert type T into a llvm::Type.  This differs from
comment|/// ConvertType in that it is used to convert to the memory representation for
comment|/// a type.  For example, the scalar representation for _Bool is i1, but the
comment|/// memory representation is usually i8 or i32, depending on the target.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMem
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTypeForMemRecursive
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// GetFunctionType - Get the LLVM function type for \arg Info.
specifier|const
name|llvm
operator|::
name|FunctionType
operator|*
name|GetFunctionType
argument_list|(
argument|const CGFunctionInfo&Info
argument_list|,
argument|bool IsVariadic
argument_list|)
expr_stmt|;
specifier|const
name|llvm
operator|::
name|FunctionType
operator|*
name|GetFunctionType
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// GetFunctionTypeForVTable - Get the LLVM function type for use in a vtable,
comment|/// given a CXXMethodDecl. If the method to has an incomplete return type,
comment|/// and/or incomplete argument types, this will return the opaque type.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|GetFunctionTypeForVTable
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
argument_list|)
expr_stmt|;
specifier|const
name|CGRecordLayout
modifier|&
name|getCGRecordLayout
argument_list|(
specifier|const
name|RecordDecl
operator|*
argument_list|)
decl|const
decl_stmt|;
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
comment|/// getFunctionInfo - Get the function info for the specified function decl.
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
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
name|getFunctionInfo
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
name|getFunctionInfo
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
name|getFunctionInfo
parameter_list|(
specifier|const
name|CXXConstructorDecl
modifier|*
name|D
parameter_list|,
name|CXXCtorType
name|Type
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
specifier|const
name|CXXDestructorDecl
modifier|*
name|D
parameter_list|,
name|CXXDtorType
name|Type
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
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
parameter_list|)
block|{
return|return
name|getFunctionInfo
argument_list|(
name|Ty
operator|->
name|getResultType
argument_list|()
argument_list|,
name|Args
argument_list|,
name|Ty
operator|->
name|getExtInfo
argument_list|()
argument_list|)
return|;
block|}
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|CanQual
operator|<
name|FunctionProtoType
operator|>
name|Ty
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|CanQual
operator|<
name|FunctionNoProtoType
operator|>
name|Ty
argument_list|)
decl_stmt|;
comment|// getFunctionInfo - Get the function info for a member function.
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
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
parameter_list|)
function_decl|;
comment|/// getFunctionInfo - Get the function info for a function described by a
comment|/// return type and argument types. If the calling convention is not
comment|/// specified, the "C" calling convention will be used.
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|QualType
name|ResTy
argument_list|,
specifier|const
name|CallArgList
operator|&
name|Args
argument_list|,
specifier|const
name|FunctionType
operator|::
name|ExtInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|QualType
name|ResTy
argument_list|,
specifier|const
name|FunctionArgList
operator|&
name|Args
argument_list|,
specifier|const
name|FunctionType
operator|::
name|ExtInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
comment|/// Retrieves the ABI information for the given function signature.
comment|///
comment|/// \param ArgTys - must all actually be canonical as params
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|CanQualType
name|RetTy
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|CanQualType
operator|>
operator|&
name|ArgTys
argument_list|,
specifier|const
name|FunctionType
operator|::
name|ExtInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
comment|/// \brief Compute a new LLVM record layout object for the given record.
name|CGRecordLayout
modifier|*
name|ComputeRecordLayout
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|public
label|:
comment|// These are internal details of CGT that shouldn't be used externally.
comment|/// ConvertTagDeclType - Lay out a tagged decl type like struct or union or
comment|/// enum.
specifier|const
name|llvm
operator|::
name|Type
operator|*
name|ConvertTagDeclType
argument_list|(
specifier|const
name|TagDecl
operator|*
name|TD
argument_list|)
expr_stmt|;
comment|/// GetExpandedTypes - Expand the type \arg Ty into the LLVM
comment|/// argument types it would be passed as on the provided vector \arg
comment|/// ArgTys. See ABIArgInfo::Expand.
name|void
name|GetExpandedTypes
argument_list|(
name|QualType
name|Ty
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|llvm
operator|::
name|Type
operator|*
operator|>
operator|&
name|ArgTys
argument_list|)
decl_stmt|;
comment|/// ContainsPointerToDataMember - Return whether the given type contains a
comment|/// pointer to a data member.
name|bool
name|ContainsPointerToDataMember
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
comment|/// ContainsPointerToDataMember - Return whether the record decl contains a
comment|/// pointer to a data member.
name|bool
name|ContainsPointerToDataMember
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
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

