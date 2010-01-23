begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXCursor.h - Routines for manipulating CXCursors -------------------===//
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
comment|// This file defines routines for manipulating CXCursors.
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
name|LLVM_CLANG_CXCURSOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CXCursor_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
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
name|ASTContext
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|ObjCProtocolDecl
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TypeDecl
decl_stmt|;
name|namespace
name|cxcursor
block|{
name|CXCursor
name|MakeCXCursorInvalid
parameter_list|(
name|CXCursorKind
name|K
parameter_list|)
function_decl|;
name|CXCursor
name|MakeCXCursor
argument_list|(
name|clang
operator|::
name|Stmt
operator|*
name|S
argument_list|,
name|clang
operator|::
name|Decl
operator|*
name|Parent
argument_list|,
name|ASTUnit
operator|*
name|TU
argument_list|)
decl_stmt|;
name|CXCursor
name|MakeCXCursor
argument_list|(
name|clang
operator|::
name|Decl
operator|*
name|D
argument_list|,
name|ASTUnit
operator|*
name|TU
argument_list|)
decl_stmt|;
comment|/// \brief Create an Objective-C superclass reference at the given location.
name|CXCursor
name|MakeCursorObjCSuperClassRef
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Super
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ASTUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack an ObjCSuperClassRef cursor into the interface it references
comment|/// and optionally the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|ObjCInterfaceDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorObjCSuperClassRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create an Objective-C protocol reference at the given location.
name|CXCursor
name|MakeCursorObjCProtocolRef
parameter_list|(
name|ObjCProtocolDecl
modifier|*
name|Proto
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ASTUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack an ObjCProtocolRef cursor into the protocol it references
comment|/// and optionally the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|ObjCProtocolDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorObjCProtocolRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create an Objective-C class reference at the given location.
name|CXCursor
name|MakeCursorObjCClassRef
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Class
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ASTUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack an ObjCClassRef cursor into the class it references
comment|/// and optionally the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|ObjCInterfaceDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorObjCClassRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create a type reference at the given location.
name|CXCursor
name|MakeCursorTypeRef
parameter_list|(
name|TypeDecl
modifier|*
name|Type
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|ASTUnit
modifier|*
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a TypeRef cursor into the class it references
comment|/// and optionally the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|TypeDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorTypeRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
name|Decl
modifier|*
name|getCursorDecl
parameter_list|(
name|CXCursor
name|Cursor
parameter_list|)
function_decl|;
name|Expr
modifier|*
name|getCursorExpr
parameter_list|(
name|CXCursor
name|Cursor
parameter_list|)
function_decl|;
name|Stmt
modifier|*
name|getCursorStmt
parameter_list|(
name|CXCursor
name|Cursor
parameter_list|)
function_decl|;
name|ASTContext
modifier|&
name|getCursorContext
parameter_list|(
name|CXCursor
name|Cursor
parameter_list|)
function_decl|;
name|ASTUnit
modifier|*
name|getCursorASTUnit
parameter_list|(
name|CXCursor
name|Cursor
parameter_list|)
function_decl|;
name|bool
name|operator
operator|==
operator|(
name|CXCursor
name|X
operator|,
name|CXCursor
name|Y
operator|)
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|CXCursor
name|X
operator|,
name|CXCursor
name|Y
operator|)
block|{
return|return
operator|!
operator|(
name|X
operator|==
name|Y
operator|)
return|;
block|}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace: clang::cxcursor
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

