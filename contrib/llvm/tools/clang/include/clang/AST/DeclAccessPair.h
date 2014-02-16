begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DeclAccessPair.h - A decl bundled with its path access -*- C++ -*-===//
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
comment|//  This file defines the DeclAccessPair class, which provides an
end_comment

begin_comment
comment|//  efficient representation of a pair of a NamedDecl* and an
end_comment

begin_comment
comment|//  AccessSpecifier.  Generally the access specifier gives the
end_comment

begin_comment
comment|//  natural access of a declaration when named in a class, as
end_comment

begin_comment
comment|//  defined in C++ [class.access.base]p1.
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
name|LLVM_CLANG_AST_DECLACCESSPAIR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_DECLACCESSPAIR_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/Specifiers.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|NamedDecl
decl_stmt|;
comment|/// A POD class for pairing a NamedDecl* with an access specifier.
comment|/// Can be put into unions.
name|class
name|DeclAccessPair
block|{
name|uintptr_t
name|Ptr
decl_stmt|;
comment|// we'd use llvm::PointerUnion, but it isn't trivial
enum|enum
block|{
name|Mask
init|=
literal|0x3
block|}
enum|;
name|public
label|:
specifier|static
name|DeclAccessPair
name|make
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|DeclAccessPair
name|p
decl_stmt|;
name|p
operator|.
name|set
argument_list|(
name|D
argument_list|,
name|AS
argument_list|)
expr_stmt|;
return|return
name|p
return|;
block|}
name|NamedDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|NamedDecl
operator|*
operator|>
operator|(
operator|~
name|Mask
operator|&
name|Ptr
operator|)
return|;
block|}
name|AccessSpecifier
name|getAccess
argument_list|()
specifier|const
block|{
return|return
name|AccessSpecifier
argument_list|(
name|Mask
operator|&
name|Ptr
argument_list|)
return|;
block|}
name|void
name|setDecl
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|)
block|{
name|set
argument_list|(
name|D
argument_list|,
name|getAccess
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|setAccess
parameter_list|(
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|set
argument_list|(
name|getDecl
argument_list|()
argument_list|,
name|AS
argument_list|)
expr_stmt|;
block|}
name|void
name|set
parameter_list|(
name|NamedDecl
modifier|*
name|D
parameter_list|,
name|AccessSpecifier
name|AS
parameter_list|)
block|{
name|Ptr
operator|=
name|uintptr_t
argument_list|(
name|AS
argument_list|)
operator||
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|D
operator|)
expr_stmt|;
block|}
name|operator
name|NamedDecl
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|getDecl
argument_list|()
return|;
block|}
name|NamedDecl
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|getDecl
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// Take a moment to tell SmallVector that DeclAccessPair is POD.
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
name|typename
operator|>
expr|struct
name|isPodLike
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|DeclAccessPair
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

