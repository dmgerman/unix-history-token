begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DeclReferenceMap.h - Map Decls to their references -----*- C++ -*-===//
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
comment|//  DeclReferenceMap creates a mapping from Decls to the ASTLocations that
end_comment

begin_comment
comment|//  reference them.
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
name|LLVM_CLANG_INDEX_DECLREFERENCEMAP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_DECLREFERENCEMAP_H
end_define

begin_include
include|#
directive|include
file|"clang/Index/ASTLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Index/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|namespace
name|idx
block|{
comment|/// \brief Maps NamedDecls with the ASTLocations that reference them.
comment|///
comment|/// References are mapped and retrieved using the canonical decls.
name|class
name|DeclReferenceMap
block|{
name|public
label|:
name|explicit
name|DeclReferenceMap
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
function_decl|;
typedef|typedef
name|std
operator|::
name|multimap
operator|<
name|NamedDecl
operator|*
operator|,
name|ASTLocation
operator|>
name|MapTy
expr_stmt|;
typedef|typedef
name|pair_value_iterator
operator|<
name|MapTy
operator|::
name|iterator
operator|>
name|astlocation_iterator
expr_stmt|;
name|astlocation_iterator
name|refs_begin
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
name|astlocation_iterator
name|refs_end
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
name|bool
name|refs_empty
argument_list|(
name|NamedDecl
operator|*
name|D
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|mutable
name|MapTy
name|Map
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// end idx namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

