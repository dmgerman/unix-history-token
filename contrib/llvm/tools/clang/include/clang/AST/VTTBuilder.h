begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- VTTBuilder.h - C++ VTT layout builder --------------------*- C++ -*-=//
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
comment|// This contains code dealing with generation of the layout of virtual table
end_comment

begin_comment
comment|// tables (VTT).
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
name|LLVM_CLANG_AST_VTTBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_VTTBUILDER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/BaseSubobject.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CXXInheritance.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/GlobalDecl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/RecordLayout.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/ABI.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|VTTVTable
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|BaseAndIsVirtual
expr_stmt|;
name|CharUnits
name|BaseOffset
decl_stmt|;
name|public
label|:
name|VTTVTable
argument_list|()
block|{}
name|VTTVTable
argument_list|(
argument|const CXXRecordDecl *Base
argument_list|,
argument|CharUnits BaseOffset
argument_list|,
argument|bool BaseIsVirtual
argument_list|)
block|:
name|BaseAndIsVirtual
argument_list|(
name|Base
argument_list|,
name|BaseIsVirtual
argument_list|)
operator|,
name|BaseOffset
argument_list|(
argument|BaseOffset
argument_list|)
block|{}
name|VTTVTable
argument_list|(
argument|BaseSubobject Base
argument_list|,
argument|bool BaseIsVirtual
argument_list|)
operator|:
name|BaseAndIsVirtual
argument_list|(
name|Base
operator|.
name|getBase
argument_list|()
argument_list|,
name|BaseIsVirtual
argument_list|)
operator|,
name|BaseOffset
argument_list|(
argument|Base.getBaseOffset()
argument_list|)
block|{}
specifier|const
name|CXXRecordDecl
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|BaseAndIsVirtual
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|CharUnits
name|getBaseOffset
argument_list|()
specifier|const
block|{
return|return
name|BaseOffset
return|;
block|}
name|bool
name|isVirtual
argument_list|()
specifier|const
block|{
return|return
name|BaseAndIsVirtual
operator|.
name|getInt
argument_list|()
return|;
block|}
name|BaseSubobject
name|getBaseSubobject
argument_list|()
specifier|const
block|{
return|return
name|BaseSubobject
argument_list|(
name|getBase
argument_list|()
argument_list|,
name|getBaseOffset
argument_list|()
argument_list|)
return|;
block|}
block|}
empty_stmt|;
struct|struct
name|VTTComponent
block|{
name|uint64_t
name|VTableIndex
decl_stmt|;
name|BaseSubobject
name|VTableBase
decl_stmt|;
name|VTTComponent
argument_list|()
block|{}
name|VTTComponent
argument_list|(
argument|uint64_t VTableIndex
argument_list|,
argument|BaseSubobject VTableBase
argument_list|)
block|:
name|VTableIndex
argument_list|(
name|VTableIndex
argument_list|)
operator|,
name|VTableBase
argument_list|(
argument|VTableBase
argument_list|)
block|{}
block|}
struct|;
comment|/// \brief Class for building VTT layout information.
name|class
name|VTTBuilder
block|{
name|ASTContext
modifier|&
name|Ctx
decl_stmt|;
comment|/// \brief The most derived class for which we're building this vtable.
specifier|const
name|CXXRecordDecl
modifier|*
name|MostDerivedClass
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|VTTVTable
operator|,
literal|64
operator|>
name|VTTVTablesVectorTy
expr_stmt|;
comment|/// \brief The VTT vtables.
name|VTTVTablesVectorTy
name|VTTVTables
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|VTTComponent
operator|,
literal|64
operator|>
name|VTTComponentsVectorTy
expr_stmt|;
comment|/// \brief The VTT components.
name|VTTComponentsVectorTy
name|VTTComponents
decl_stmt|;
comment|/// \brief The AST record layout of the most derived class.
specifier|const
name|ASTRecordLayout
modifier|&
name|MostDerivedClassLayout
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|VisitedVirtualBasesSetTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
name|AddressPointsMapTy
expr_stmt|;
comment|/// \brief The sub-VTT indices for the bases of the most derived class.
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
name|SubVTTIndicies
expr_stmt|;
comment|/// \brief The secondary virtual pointer indices of all subobjects of
comment|/// the most derived class.
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
name|SecondaryVirtualPointerIndices
expr_stmt|;
comment|/// \brief Whether the VTT builder should generate LLVM IR for the VTT.
name|bool
name|GenerateDefinition
decl_stmt|;
comment|/// \brief Add a vtable pointer to the VTT currently being built.
name|void
name|AddVTablePointer
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
name|uint64_t
name|VTableIndex
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|)
function_decl|;
comment|/// \brief Lay out the secondary VTTs of the given base subobject.
name|void
name|LayoutSecondaryVTTs
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|)
function_decl|;
comment|/// \brief Lay out the secondary virtual pointers for the given base
comment|/// subobject.
comment|///
comment|/// \param BaseIsMorallyVirtual whether the base subobject is a virtual base
comment|/// or a direct or indirect base of a virtual base.
name|void
name|LayoutSecondaryVirtualPointers
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
name|bool
name|BaseIsMorallyVirtual
parameter_list|,
name|uint64_t
name|VTableIndex
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|VTableClass
parameter_list|,
name|VisitedVirtualBasesSetTy
modifier|&
name|VBases
parameter_list|)
function_decl|;
comment|/// \brief Lay out the secondary virtual pointers for the given base
comment|/// subobject.
name|void
name|LayoutSecondaryVirtualPointers
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
name|uint64_t
name|VTableIndex
parameter_list|)
function_decl|;
comment|/// \brief Lay out the VTTs for the virtual base classes of the given
comment|/// record declaration.
name|void
name|LayoutVirtualVTTs
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|VisitedVirtualBasesSetTy
modifier|&
name|VBases
parameter_list|)
function_decl|;
comment|/// \brief Lay out the VTT for the given subobject, including any
comment|/// secondary VTTs, secondary virtual pointers and virtual VTTs.
name|void
name|LayoutVTT
parameter_list|(
name|BaseSubobject
name|Base
parameter_list|,
name|bool
name|BaseIsVirtual
parameter_list|)
function_decl|;
name|public
label|:
name|VTTBuilder
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|const CXXRecordDecl *MostDerivedClass
argument_list|,
argument|bool GenerateDefinition
argument_list|)
empty_stmt|;
comment|// \brief Returns a reference to the VTT components.
specifier|const
name|VTTComponentsVectorTy
operator|&
name|getVTTComponents
argument_list|()
specifier|const
block|{
return|return
name|VTTComponents
return|;
block|}
comment|// \brief Returns a reference to the VTT vtables.
specifier|const
name|VTTVTablesVectorTy
operator|&
name|getVTTVTables
argument_list|()
specifier|const
block|{
return|return
name|VTTVTables
return|;
block|}
comment|/// \brief Returns a reference to the sub-VTT indices.
specifier|const
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
operator|&
name|getSubVTTIndicies
argument_list|()
specifier|const
block|{
return|return
name|SubVTTIndicies
return|;
block|}
comment|/// \brief Returns a reference to the secondary virtual pointer indices.
specifier|const
name|llvm
operator|::
name|DenseMap
operator|<
name|BaseSubobject
operator|,
name|uint64_t
operator|>
operator|&
name|getSecondaryVirtualPointerIndices
argument_list|()
specifier|const
block|{
return|return
name|SecondaryVirtualPointerIndices
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

