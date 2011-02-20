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
name|LLVM_CLANG_CXCURSOR_H
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
file|"llvm/ADT/PointerUnion.h"
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
name|Attr
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|InclusionDirective
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|MacroInstantiation
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
name|OverloadedTemplateStorage
decl_stmt|;
name|class
name|OverloadExpr
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TemplateDecl
decl_stmt|;
name|class
name|TemplateName
decl_stmt|;
name|class
name|TypeDecl
decl_stmt|;
name|namespace
name|cxcursor
block|{
name|CXCursor
name|MakeCXCursor
argument_list|(
specifier|const
name|clang
operator|::
name|Attr
operator|*
name|A
argument_list|,
name|clang
operator|::
name|Decl
operator|*
name|Parent
argument_list|,
name|CXTranslationUnit
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
name|CXTranslationUnit
name|TU
argument_list|,
name|bool
name|FirstInDeclGroup
operator|=
name|true
argument_list|)
decl_stmt|;
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
name|CXTranslationUnit
name|TU
argument_list|)
decl_stmt|;
name|CXCursor
name|MakeCXCursorInvalid
parameter_list|(
name|CXCursorKind
name|K
parameter_list|)
function_decl|;
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
name|CXTranslationUnit
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
name|CXTranslationUnit
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
name|CXTranslationUnit
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
name|CXTranslationUnit
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
comment|/// \brief Create a reference to a template at the given location.
name|CXCursor
name|MakeCursorTemplateRef
parameter_list|(
name|TemplateDecl
modifier|*
name|Template
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a TemplateRef cursor into the template it references and
comment|/// the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|TemplateDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorTemplateRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create a reference to a namespace or namespace alias at the given
comment|/// location.
name|CXCursor
name|MakeCursorNamespaceRef
parameter_list|(
name|NamedDecl
modifier|*
name|NS
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a NamespaceRef cursor into the namespace or namespace alias
comment|/// it references and the location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|NamedDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorNamespaceRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create a reference to a field at the given location.
name|CXCursor
name|MakeCursorMemberRef
parameter_list|(
name|FieldDecl
modifier|*
name|Field
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a MemberRef cursor into the field it references and the
comment|/// location where the reference occurred.
name|std
operator|::
name|pair
operator|<
name|FieldDecl
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorMemberRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create a CXX base specifier cursor.
name|CXCursor
name|MakeCursorCXXBaseSpecifier
parameter_list|(
name|CXXBaseSpecifier
modifier|*
name|B
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a CXXBaseSpecifier cursor into a CXXBaseSpecifier.
name|CXXBaseSpecifier
modifier|*
name|getCursorCXXBaseSpecifier
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/// \brief Create a preprocessing directive cursor.
name|CXCursor
name|MakePreprocessingDirectiveCursor
parameter_list|(
name|SourceRange
name|Range
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a given preprocessing directive to retrieve its source range.
name|SourceRange
name|getCursorPreprocessingDirective
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/// \brief Create a macro definition cursor.
name|CXCursor
name|MakeMacroDefinitionCursor
parameter_list|(
name|MacroDefinition
modifier|*
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a given macro definition cursor to retrieve its
comment|/// source range.
name|MacroDefinition
modifier|*
name|getCursorMacroDefinition
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/// \brief Create a macro instantiation cursor.
name|CXCursor
name|MakeMacroInstantiationCursor
parameter_list|(
name|MacroInstantiation
modifier|*
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a given macro instantiation cursor to retrieve its
comment|/// source range.
name|MacroInstantiation
modifier|*
name|getCursorMacroInstantiation
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/// \brief Create an inclusion directive cursor.
name|CXCursor
name|MakeInclusionDirectiveCursor
parameter_list|(
name|InclusionDirective
modifier|*
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a given inclusion directive cursor to retrieve its
comment|/// source range.
name|InclusionDirective
modifier|*
name|getCursorInclusionDirective
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
comment|/// \brief Create a label reference at the given location.
name|CXCursor
name|MakeCursorLabelRef
parameter_list|(
name|LabelStmt
modifier|*
name|Label
parameter_list|,
name|SourceLocation
name|Loc
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Unpack a label reference into the label statement it refers to and
comment|/// the location of the reference.
name|std
operator|::
name|pair
operator|<
name|LabelStmt
operator|*
operator|,
name|SourceLocation
operator|>
name|getCursorLabelRef
argument_list|(
argument|CXCursor C
argument_list|)
expr_stmt|;
comment|/// \brief Create a overloaded declaration reference cursor for an expression.
name|CXCursor
name|MakeCursorOverloadedDeclRef
parameter_list|(
name|OverloadExpr
modifier|*
name|E
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Create a overloaded declaration reference cursor for a declaration.
name|CXCursor
name|MakeCursorOverloadedDeclRef
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|,
name|SourceLocation
name|Location
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Create a overloaded declaration reference cursor for a template name.
name|CXCursor
name|MakeCursorOverloadedDeclRef
parameter_list|(
name|TemplateName
name|Template
parameter_list|,
name|SourceLocation
name|Location
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
comment|/// \brief Internal storage for an overloaded declaration reference cursor;
typedef|typedef
name|llvm
operator|::
name|PointerUnion3
operator|<
name|OverloadExpr
operator|*
operator|,
name|Decl
operator|*
operator|,
name|OverloadedTemplateStorage
operator|*
operator|>
name|OverloadedDeclRefStorage
expr_stmt|;
comment|/// \brief Unpack an overloaded declaration reference into an expression,
comment|/// declaration, or template name along with the source location.
name|std
operator|::
name|pair
operator|<
name|OverloadedDeclRefStorage
operator|,
name|SourceLocation
operator|>
name|getCursorOverloadedDeclRef
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
name|Attr
modifier|*
name|getCursorAttr
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
name|CXTranslationUnit
name|getCursorTU
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
comment|/// \brief Return true if the cursor represents a declaration that is the
comment|/// first in a declaration group.
name|bool
name|isFirstInDeclGroup
parameter_list|(
name|CXCursor
name|C
parameter_list|)
function_decl|;
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

