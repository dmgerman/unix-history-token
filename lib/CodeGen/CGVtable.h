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

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXMethodDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|CodeGenModule
decl_stmt|;
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
specifier|const
name|CXXMethodDecl
operator|*
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
name|int64_t
name|getMethodVtableIndex
argument_list|(
specifier|const
name|CXXMethodDecl
operator|*
name|MD
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

