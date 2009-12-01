begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CGVtable.h - Emit LLVM Code for C++ vtables ----------------------===//
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
comment|// This contains code dealing with C++ code generation of virtual tables.
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
name|CLANG_CODEGEN_CGVTABLE_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_CGVTABLE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
name|Constant
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXRecordDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
comment|/// ThunkAdjustment - Virtual and non-virtual adjustment for thunks.
name|class
name|ThunkAdjustment
block|{
name|public
label|:
name|ThunkAdjustment
argument_list|(
argument|int64_t NonVirtual
argument_list|,
argument|int64_t Virtual
argument_list|)
block|:
name|NonVirtual
argument_list|(
name|NonVirtual
argument_list|)
operator|,
name|Virtual
argument_list|(
argument|Virtual
argument_list|)
block|{ }
name|ThunkAdjustment
argument_list|()
operator|:
name|NonVirtual
argument_list|(
literal|0
argument_list|)
operator|,
name|Virtual
argument_list|(
literal|0
argument_list|)
block|{ }
comment|// isEmpty - Return whether this thunk adjustment is empty.
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|NonVirtual
operator|==
literal|0
operator|&&
name|Virtual
operator|==
literal|0
return|;
block|}
comment|/// NonVirtual - The non-virtual adjustment.
name|int64_t
name|NonVirtual
decl_stmt|;
comment|/// Virtual - The virtual adjustment.
name|int64_t
name|Virtual
decl_stmt|;
block|}
empty_stmt|;
comment|/// CovariantThunkAdjustment - Adjustment of the 'this' pointer and the
comment|/// return pointer for covariant thunks.
name|class
name|CovariantThunkAdjustment
block|{
name|public
label|:
name|CovariantThunkAdjustment
argument_list|(
specifier|const
name|ThunkAdjustment
operator|&
name|ThisAdjustment
argument_list|,
specifier|const
name|ThunkAdjustment
operator|&
name|ReturnAdjustment
argument_list|)
operator|:
name|ThisAdjustment
argument_list|(
name|ThisAdjustment
argument_list|)
operator|,
name|ReturnAdjustment
argument_list|(
argument|ReturnAdjustment
argument_list|)
block|{ }
name|CovariantThunkAdjustment
argument_list|()
block|{ }
name|ThunkAdjustment
name|ThisAdjustment
expr_stmt|;
name|ThunkAdjustment
name|ReturnAdjustment
decl_stmt|;
block|}
empty_stmt|;
name|class
name|CGVtableInfo
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
comment|/// MethodVtableIndices - Contains the index (relative to the vtable address
comment|/// point) where the function pointer for a virtual function is stored.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|GlobalDecl
operator|,
name|int64_t
operator|>
name|MethodVtableIndicesTy
expr_stmt|;
name|MethodVtableIndicesTy
name|MethodVtableIndices
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
specifier|const
name|CXXRecordDecl
operator|*
operator|>
name|ClassPairTy
expr_stmt|;
comment|/// VirtualBaseClassIndicies - Contains the index into the vtable where the
comment|/// offsets for virtual bases of a class are stored.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ClassPairTy
operator|,
name|int64_t
operator|>
name|VirtualBaseClassIndiciesTy
expr_stmt|;
name|VirtualBaseClassIndiciesTy
name|VirtualBaseClassIndicies
decl_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|llvm
operator|::
name|Constant
operator|*
operator|>
name|Vtables
expr_stmt|;
comment|/// NumVirtualFunctionPointers - Contains the number of virtual function
comment|/// pointers in the vtable for a given record decl.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|uint64_t
operator|>
name|NumVirtualFunctionPointers
expr_stmt|;
comment|/// getNumVirtualFunctionPointers - Return the number of virtual function
comment|/// pointers in the vtable for a given record decl.
name|uint64_t
name|getNumVirtualFunctionPointers
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|void
name|ComputeMethodVtableIndices
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
comment|/// GenerateClassData - Generate all the class data requires to be generated
comment|/// upon definition of a KeyFunction.  This includes the vtable, the
comment|/// rtti data structure and the VTT.
name|void
name|GenerateClassData
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|)
function_decl|;
name|public
label|:
name|CGVtableInfo
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
argument|CGM
argument_list|)
block|{ }
comment|/// getMethodVtableIndex - Return the index (relative to the vtable address
comment|/// point) where the function pointer for the given virtual function is
comment|/// stored.
name|uint64_t
name|getMethodVtableIndex
argument_list|(
argument|GlobalDecl GD
argument_list|)
expr_stmt|;
comment|/// getVirtualBaseOffsetIndex - Return the index (relative to the vtable
comment|/// address point) where the offset of the virtual base that contains the
comment|/// given Base is stored, otherwise, if no virtual base contains the given
comment|/// class, return 0.  Base must be a virtual base class or an unambigious
comment|/// base.
name|int64_t
name|getVirtualBaseOffsetIndex
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VBase
parameter_list|)
function_decl|;
name|llvm
operator|::
name|Constant
operator|*
name|getVtable
argument_list|(
specifier|const
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Constant
operator|*
name|getCtorVtable
argument_list|(
argument|const CXXRecordDecl *RD
argument_list|,
argument|const CXXRecordDecl *Class
argument_list|,
argument|uint64_t Offset
argument_list|)
expr_stmt|;
name|void
name|MaybeEmitVtable
parameter_list|(
name|GlobalDecl
name|GD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

