begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- GlobalDecl.h - Global declaration holder ---------------*- C++ -*-===//
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
comment|// A GlobalDecl can hold either a regular variable/function or a C++ ctor/dtor
end_comment

begin_comment
comment|// together with its type.
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
name|CLANG_CODEGEN_GLOBALDECL_H
end_ifndef

begin_define
define|#
directive|define
name|CLANG_CODEGEN_GLOBALDECL_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|CodeGen
block|{
comment|/// GlobalDecl - represents a global declaration. This can either be a
comment|/// CXXConstructorDecl and the constructor type (Base, Complete).
comment|/// a CXXDestructorDecl and the destructor type (Base, Complete) or
comment|/// a VarDecl, a FunctionDecl or a BlockDecl.
name|class
name|GlobalDecl
block|{
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|Decl
operator|*
operator|,
literal|2
operator|>
name|Value
expr_stmt|;
name|void
name|Init
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|D
operator|)
operator|&&
literal|"Use other ctor with ctor decls!"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
name|isa
operator|<
name|CXXDestructorDecl
operator|>
operator|(
name|D
operator|)
operator|&&
literal|"Use other ctor with dtor decls!"
argument_list|)
expr_stmt|;
name|Value
operator|.
name|setPointer
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|GlobalDecl
argument_list|()
block|{}
name|GlobalDecl
argument_list|(
argument|const VarDecl *D
argument_list|)
block|{
name|Init
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|GlobalDecl
argument_list|(
argument|const FunctionDecl *D
argument_list|)
block|{
name|Init
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|GlobalDecl
argument_list|(
argument|const BlockDecl *D
argument_list|)
block|{
name|Init
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|GlobalDecl
argument_list|(
argument|const ObjCMethodDecl *D
argument_list|)
block|{
name|Init
argument_list|(
name|D
argument_list|)
expr_stmt|;
block|}
name|GlobalDecl
argument_list|(
argument|const CXXConstructorDecl *D
argument_list|,
argument|CXXCtorType Type
argument_list|)
block|:
name|Value
argument_list|(
argument|D
argument_list|,
argument|Type
argument_list|)
block|{}
name|GlobalDecl
argument_list|(
argument|const CXXDestructorDecl *D
argument_list|,
argument|CXXDtorType Type
argument_list|)
block|:
name|Value
argument_list|(
argument|D
argument_list|,
argument|Type
argument_list|)
block|{}
specifier|const
name|Decl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|CXXCtorType
name|getCtorType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isa
operator|<
name|CXXConstructorDecl
operator|>
operator|(
name|getDecl
argument_list|()
operator|)
operator|&&
literal|"Decl is not a ctor!"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|CXXCtorType
operator|>
operator|(
name|Value
operator|.
name|getInt
argument_list|()
operator|)
return|;
block|}
name|CXXDtorType
name|getDtorType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isa
operator|<
name|CXXDestructorDecl
operator|>
operator|(
name|getDecl
argument_list|()
operator|)
operator|&&
literal|"Decl is not a dtor!"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|CXXDtorType
operator|>
operator|(
name|Value
operator|.
name|getInt
argument_list|()
operator|)
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|GlobalDecl
operator|&
name|LHS
operator|,
specifier|const
name|GlobalDecl
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Value
operator|==
name|RHS
operator|.
name|Value
return|;
block|}
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
name|GlobalDecl
name|getFromOpaquePtr
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
block|{
name|GlobalDecl
name|GD
decl_stmt|;
name|GD
operator|.
name|Value
operator|.
name|setFromOpaqueValue
argument_list|(
name|P
argument_list|)
expr_stmt|;
return|return
name|GD
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
operator|::
name|getFromOpaquePtr
argument_list|(
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|clang::CodeGen::GlobalDecl GD
argument_list|)
block|{
return|return
name|DenseMapInfo
operator|<
name|void
operator|*
operator|>
operator|::
name|getHashValue
argument_list|(
name|GD
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|clang::CodeGen::GlobalDecl LHS
argument_list|,
argument|clang::CodeGen::GlobalDecl RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
comment|// GlobalDecl isn't *technically* a POD type. However, its copy constructor,
comment|// copy assignment operator, and destructor are all trivial.
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|CodeGen
operator|::
name|GlobalDecl
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

