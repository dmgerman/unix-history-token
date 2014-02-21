begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Attr.h - Classes for representing attributes ----------*- C++ -*-===//
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
comment|//  This file defines the Attr interface and subclasses.
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
name|LLVM_CLANG_AST_ATTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ATTR_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/AttrIterator.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/AttrKinds.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/VersionTuple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSwitch.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ObjCInterfaceDecl
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|TypeSourceInfo
decl_stmt|;
comment|/// Attr - This represents one attribute.
name|class
name|Attr
block|{
name|private
label|:
name|SourceRange
name|Range
decl_stmt|;
name|unsigned
name|AttrKind
range|:
literal|16
decl_stmt|;
name|protected
label|:
comment|/// An index into the spelling list of an
comment|/// attribute defined in Attr.td file.
name|unsigned
name|SpellingListIndex
range|:
literal|4
decl_stmt|;
name|bool
name|Inherited
range|:
literal|1
decl_stmt|;
name|bool
name|IsPackExpansion
range|:
literal|1
decl_stmt|;
name|virtual
operator|~
name|Attr
argument_list|()
expr_stmt|;
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|bytes
parameter_list|)
function|throw
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Attrs cannot be allocated with regular 'new'."
argument_list|)
expr_stmt|;
block|}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function|throw
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Attrs cannot be released with regular 'delete'."
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|// Forward so that the regular new and delete do not hide global ones.
name|void
modifier|*
name|operator
name|new
parameter_list|(
name|size_t
name|Bytes
parameter_list|,
name|ASTContext
modifier|&
name|C
parameter_list|,
name|size_t
name|Alignment
init|=
literal|16
parameter_list|)
function|throw
parameter_list|()
block|{
return|return
operator|::
name|operator
name|new
argument_list|(
name|Bytes
argument_list|,
name|C
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|void
name|operator
name|delete
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|,
name|ASTContext
modifier|&
name|C
parameter_list|,
name|size_t
name|Alignment
parameter_list|)
function|throw
parameter_list|()
block|{
return|return
operator|::
name|operator
name|delete
argument_list|(
name|Ptr
argument_list|,
name|C
argument_list|,
name|Alignment
argument_list|)
return|;
block|}
name|protected
label|:
name|Attr
argument_list|(
argument|attr::Kind AK
argument_list|,
argument|SourceRange R
argument_list|,
argument|unsigned SpellingListIndex =
literal|0
argument_list|)
block|:
name|Range
argument_list|(
name|R
argument_list|)
operator|,
name|AttrKind
argument_list|(
name|AK
argument_list|)
operator|,
name|SpellingListIndex
argument_list|(
name|SpellingListIndex
argument_list|)
operator|,
name|Inherited
argument_list|(
name|false
argument_list|)
operator|,
name|IsPackExpansion
argument_list|(
argument|false
argument_list|)
block|{}
name|public
operator|:
name|attr
operator|::
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|attr
operator|::
name|Kind
operator|>
operator|(
name|AttrKind
operator|)
return|;
block|}
name|unsigned
name|getSpellingListIndex
argument_list|()
specifier|const
block|{
return|return
name|SpellingListIndex
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Range
operator|.
name|getBegin
argument_list|()
return|;
block|}
name|SourceRange
name|getRange
argument_list|()
specifier|const
block|{
return|return
name|Range
return|;
block|}
name|void
name|setRange
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
name|Range
operator|=
name|R
expr_stmt|;
block|}
name|bool
name|isInherited
argument_list|()
specifier|const
block|{
return|return
name|Inherited
return|;
block|}
name|void
name|setPackExpansion
parameter_list|(
name|bool
name|PE
parameter_list|)
block|{
name|IsPackExpansion
operator|=
name|PE
expr_stmt|;
block|}
name|bool
name|isPackExpansion
argument_list|()
specifier|const
block|{
return|return
name|IsPackExpansion
return|;
block|}
comment|// Clone this attribute.
name|virtual
name|Attr
modifier|*
name|clone
argument_list|(
name|ASTContext
operator|&
name|C
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|bool
name|isLateParsed
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|// Pretty print this attribute.
name|virtual
name|void
name|printPretty
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|PrintingPolicy
operator|&
name|Policy
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
name|class
name|InheritableAttr
range|:
name|public
name|Attr
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|InheritableAttr
argument_list|(
argument|attr::Kind AK
argument_list|,
argument|SourceRange R
argument_list|,
argument|unsigned SpellingListIndex =
literal|0
argument_list|)
operator|:
name|Attr
argument_list|(
argument|AK
argument_list|,
argument|R
argument_list|,
argument|SpellingListIndex
argument_list|)
block|{}
name|public
operator|:
name|void
name|setInherited
argument_list|(
argument|bool I
argument_list|)
block|{
name|Inherited
operator|=
name|I
block|; }
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Attr *A
argument_list|)
block|{
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|<=
name|attr
operator|::
name|LAST_INHERITABLE
return|;
block|}
expr|}
block|;
name|class
name|InheritableParamAttr
operator|:
name|public
name|InheritableAttr
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|InheritableParamAttr
argument_list|(
argument|attr::Kind AK
argument_list|,
argument|SourceRange R
argument_list|,
argument|unsigned SpellingListIndex =
literal|0
argument_list|)
operator|:
name|InheritableAttr
argument_list|(
argument|AK
argument_list|,
argument|R
argument_list|,
argument|SpellingListIndex
argument_list|)
block|{}
name|public
operator|:
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Attr *A
argument_list|)
block|{
comment|// Relies on relative order of enum emission with respect to MS inheritance
comment|// attrs.
return|return
name|A
operator|->
name|getKind
argument_list|()
operator|<=
name|attr
operator|::
name|LAST_INHERITABLE_PARAM
return|;
block|}
expr|}
block|;
name|class
name|MSInheritanceAttr
operator|:
name|public
name|InheritableAttr
block|{
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|MSInheritanceAttr
argument_list|(
argument|attr::Kind AK
argument_list|,
argument|SourceRange R
argument_list|,
argument|unsigned SpellingListIndex =
literal|0
argument_list|)
operator|:
name|InheritableAttr
argument_list|(
argument|AK
argument_list|,
argument|R
argument_list|,
argument|SpellingListIndex
argument_list|)
block|{}
name|public
operator|:
comment|// Implement isa/cast/dyncast/etc.
specifier|static
name|bool
name|classof
argument_list|(
argument|const Attr *A
argument_list|)
block|{
comment|// Relies on relative order of enum emission with respect to param attrs.
return|return
operator|(
name|A
operator|->
name|getKind
argument_list|()
operator|<=
name|attr
operator|::
name|LAST_MS_INHERITANCE
operator|&&
name|A
operator|->
name|getKind
argument_list|()
operator|>
name|attr
operator|::
name|LAST_INHERITABLE_PARAM
operator|)
return|;
block|}
expr|}
block|;
include|#
directive|include
file|"clang/AST/Attrs.inc"
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

