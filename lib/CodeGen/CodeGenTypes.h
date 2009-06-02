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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
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
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenTypes
decl_stmt|;
comment|/// CGRecordLayout - This class handles struct and union layout info while
comment|/// lowering AST types to LLVM types.
name|class
name|CGRecordLayout
block|{
name|CGRecordLayout
argument_list|()
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|CGRecordLayout
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|T
argument_list|,
name|llvm
operator|::
name|SmallSet
operator|<
name|unsigned
argument_list|,
literal|8
operator|>
operator|&
name|PF
argument_list|)
operator|:
name|STy
argument_list|(
name|T
argument_list|)
operator|,
name|PaddingFields
argument_list|(
argument|PF
argument_list|)
block|{
comment|// FIXME : Collect info about fields that requires adjustments
comment|// (i.e. fields that do not directly map to llvm struct fields.)
block|}
comment|/// getLLVMType - Return llvm type associated with this record.
name|llvm
operator|::
name|Type
operator|*
name|getLLVMType
argument_list|()
specifier|const
block|{
return|return
name|STy
return|;
block|}
name|bool
name|isPaddingField
argument_list|(
name|unsigned
name|No
argument_list|)
decl|const
block|{
return|return
name|PaddingFields
operator|.
name|count
argument_list|(
name|No
argument_list|)
operator|!=
literal|0
return|;
block|}
name|unsigned
name|getNumPaddingFields
parameter_list|()
block|{
return|return
name|PaddingFields
operator|.
name|size
argument_list|()
return|;
block|}
name|private
label|:
name|llvm
operator|::
name|Type
operator|*
name|STy
expr_stmt|;
name|llvm
operator|::
name|SmallSet
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|PaddingFields
expr_stmt|;
block|}
empty_stmt|;
comment|/// CodeGenTypes - This class organizes the cross-module state that is used
comment|/// while lowering AST types to LLVM types.
name|class
name|CodeGenTypes
block|{
name|ASTContext
modifier|&
name|Context
decl_stmt|;
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
name|mutable
specifier|const
name|ABIInfo
modifier|*
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
comment|/// FIXME : If CGRecordLayout is less than 16 bytes then use
comment|/// inline it in the map.
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
comment|/// FieldInfo - This maps struct field with corresponding llvm struct type
comment|/// field no. This info is populated by record organizer.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|unsigned
operator|>
name|FieldInfo
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
name|public
label|:
name|class
name|BitFieldInfo
block|{
name|public
label|:
name|explicit
name|BitFieldInfo
argument_list|(
argument|unsigned short B
argument_list|,
argument|unsigned short S
argument_list|)
block|:
name|Begin
argument_list|(
name|B
argument_list|)
operator|,
name|Size
argument_list|(
argument|S
argument_list|)
block|{}
name|unsigned
name|short
name|Begin
expr_stmt|;
name|unsigned
name|short
name|Size
decl_stmt|;
block|}
empty_stmt|;
name|private
label|:
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
operator|,
name|BitFieldInfo
operator|>
name|BitFields
expr_stmt|;
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
expr_stmt|;
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
name|CGRecordLayout
modifier|*
name|getCGRecordLayout
argument_list|(
specifier|const
name|TagDecl
operator|*
argument_list|)
decl|const
decl_stmt|;
comment|/// getLLVMFieldNo - Return llvm::StructType element number
comment|/// that corresponds to the field FD.
name|unsigned
name|getLLVMFieldNo
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
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
comment|/// getFunctionInfo - Get the CGFunctionInfo for this function signature.
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
argument_list|(
name|QualType
name|RetTy
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallVector
operator|<
name|QualType
argument_list|,
literal|16
operator|>
operator|&
name|ArgTys
argument_list|)
decl_stmt|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
specifier|const
name|FunctionNoProtoType
modifier|*
name|FTNP
parameter_list|)
function_decl|;
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
specifier|const
name|FunctionProtoType
modifier|*
name|FTP
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
name|QualType
name|ResTy
parameter_list|,
specifier|const
name|CallArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
name|public
label|:
specifier|const
name|CGFunctionInfo
modifier|&
name|getFunctionInfo
parameter_list|(
name|QualType
name|ResTy
parameter_list|,
specifier|const
name|FunctionArgList
modifier|&
name|Args
parameter_list|)
function_decl|;
name|public
label|:
comment|// These are internal details of CGT that shouldn't be used externally.
comment|/// addFieldInfo - Assign field number to field FD.
name|void
name|addFieldInfo
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|unsigned
name|No
parameter_list|)
function_decl|;
comment|/// addBitFieldInfo - Assign a start bit and a size to field FD.
name|void
name|addBitFieldInfo
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|,
name|unsigned
name|Begin
parameter_list|,
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// getBitFieldInfo - Return the BitFieldInfo  that corresponds to the field
comment|/// FD.
name|BitFieldInfo
name|getBitFieldInfo
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|FD
parameter_list|)
function_decl|;
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

