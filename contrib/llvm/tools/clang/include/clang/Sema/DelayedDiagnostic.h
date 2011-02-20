begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DelayedDiagnostic.h - Delayed declarator diagnostics ---*- C++ -*-===//
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
comment|// This file defines the DelayedDiagnostic class, which is used to
end_comment

begin_comment
comment|// record diagnostics that are being conditionally produced during
end_comment

begin_comment
comment|// declarator parsing.  Certain kinds of diagnostics --- notably
end_comment

begin_comment
comment|// deprecation and access control --- are suppressed based on
end_comment

begin_comment
comment|// semantic properties of the parsed declaration that aren't known
end_comment

begin_comment
comment|// until it is fully parsed.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file also defines AccessedEntity.
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
name|LLVM_CLANG_SEMA_DELAYED_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_DELAYED_DIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclCXX.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|sema
block|{
comment|/// A declaration being accessed, together with information about how
comment|/// it was accessed.
name|class
name|AccessedEntity
block|{
name|public
label|:
comment|/// A member declaration found through lookup.  The target is the
comment|/// member.
enum|enum
name|MemberNonce
block|{
name|Member
block|}
enum|;
comment|/// A hierarchy (base-to-derived or derived-to-base) conversion.
comment|/// The target is the base class.
enum|enum
name|BaseNonce
block|{
name|Base
block|}
enum|;
name|bool
name|isMemberAccess
argument_list|()
specifier|const
block|{
return|return
name|IsMember
return|;
block|}
name|AccessedEntity
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|MemberNonce _
argument_list|,
argument|CXXRecordDecl *NamingClass
argument_list|,
argument|DeclAccessPair FoundDecl
argument_list|,
argument|QualType BaseObjectType
argument_list|)
block|:
name|Access
argument_list|(
name|FoundDecl
operator|.
name|getAccess
argument_list|()
argument_list|)
operator|,
name|IsMember
argument_list|(
name|true
argument_list|)
operator|,
name|Target
argument_list|(
name|FoundDecl
operator|.
name|getDecl
argument_list|()
argument_list|)
operator|,
name|NamingClass
argument_list|(
name|NamingClass
argument_list|)
operator|,
name|BaseObjectType
argument_list|(
name|BaseObjectType
argument_list|)
operator|,
name|Diag
argument_list|(
literal|0
argument_list|,
argument|Context.getDiagAllocator()
argument_list|)
block|{   }
name|AccessedEntity
argument_list|(
argument|ASTContext&Context
argument_list|,
argument|BaseNonce _
argument_list|,
argument|CXXRecordDecl *BaseClass
argument_list|,
argument|CXXRecordDecl *DerivedClass
argument_list|,
argument|AccessSpecifier Access
argument_list|)
operator|:
name|Access
argument_list|(
name|Access
argument_list|)
operator|,
name|IsMember
argument_list|(
name|false
argument_list|)
operator|,
name|Target
argument_list|(
name|BaseClass
argument_list|)
operator|,
name|NamingClass
argument_list|(
name|DerivedClass
argument_list|)
operator|,
name|Diag
argument_list|(
literal|0
argument_list|,
argument|Context.getDiagAllocator()
argument_list|)
block|{   }
name|bool
name|isQuiet
argument_list|()
specifier|const
block|{
return|return
name|Diag
operator|.
name|getDiagID
argument_list|()
operator|==
literal|0
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
name|Access
argument_list|)
return|;
block|}
comment|// These apply to member decls...
name|NamedDecl
operator|*
name|getTargetDecl
argument_list|()
specifier|const
block|{
return|return
name|Target
return|;
block|}
name|CXXRecordDecl
operator|*
name|getNamingClass
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
return|;
block|}
comment|// ...and these apply to hierarchy conversions.
name|CXXRecordDecl
operator|*
name|getBaseClass
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|IsMember
argument_list|)
block|;
return|return
name|cast
operator|<
name|CXXRecordDecl
operator|>
operator|(
name|Target
operator|)
return|;
block|}
name|CXXRecordDecl
operator|*
name|getDerivedClass
argument_list|()
specifier|const
block|{
return|return
name|NamingClass
return|;
block|}
comment|/// Retrieves the base object type, important when accessing
comment|/// an instance member.
name|QualType
name|getBaseObjectType
argument_list|()
specifier|const
block|{
return|return
name|BaseObjectType
return|;
block|}
comment|/// Sets a diagnostic to be performed.  The diagnostic is given
comment|/// four (additional) arguments:
comment|///   %0 - 0 if the entity was private, 1 if protected
comment|///   %1 - the DeclarationName of the entity
comment|///   %2 - the TypeDecl type of the naming class
comment|///   %3 - the TypeDecl type of the declaring class
name|void
name|setDiag
parameter_list|(
specifier|const
name|PartialDiagnostic
modifier|&
name|PDiag
parameter_list|)
block|{
name|assert
argument_list|(
name|isQuiet
argument_list|()
operator|&&
literal|"partial diagnostic already defined"
argument_list|)
expr_stmt|;
name|Diag
operator|=
name|PDiag
expr_stmt|;
block|}
name|PartialDiagnostic
modifier|&
name|setDiag
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
block|{
name|assert
argument_list|(
name|isQuiet
argument_list|()
operator|&&
literal|"partial diagnostic already defined"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|DiagID
operator|&&
literal|"creating null diagnostic"
argument_list|)
expr_stmt|;
name|Diag
operator|.
name|Reset
argument_list|(
name|DiagID
argument_list|)
expr_stmt|;
return|return
name|Diag
return|;
block|}
specifier|const
name|PartialDiagnostic
operator|&
name|getDiag
argument_list|()
specifier|const
block|{
return|return
name|Diag
return|;
block|}
name|private
label|:
name|unsigned
name|Access
range|:
literal|2
decl_stmt|;
name|unsigned
name|IsMember
range|:
literal|1
decl_stmt|;
name|NamedDecl
modifier|*
name|Target
decl_stmt|;
name|CXXRecordDecl
modifier|*
name|NamingClass
decl_stmt|;
name|QualType
name|BaseObjectType
decl_stmt|;
name|PartialDiagnostic
name|Diag
decl_stmt|;
block|}
empty_stmt|;
comment|/// A diagnostic message which has been conditionally emitted pending
comment|/// the complete parsing of the current declaration.
name|class
name|DelayedDiagnostic
block|{
name|public
label|:
enum|enum
name|DDKind
block|{
name|Deprecation
block|,
name|Access
block|}
enum|;
name|unsigned
name|char
name|Kind
decl_stmt|;
comment|// actually a DDKind
name|bool
name|Triggered
decl_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
name|void
name|destroy
parameter_list|()
block|{
switch|switch
condition|(
name|Kind
condition|)
block|{
case|case
name|Access
case|:
name|getAccessData
argument_list|()
operator|.
operator|~
name|AccessedEntity
argument_list|()
expr_stmt|;
break|break;
case|case
name|Deprecation
case|:
break|break;
block|}
block|}
specifier|static
name|DelayedDiagnostic
name|makeDeprecation
argument_list|(
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|,
name|llvm
operator|::
name|StringRef
name|Msg
argument_list|)
block|{
name|DelayedDiagnostic
name|DD
decl_stmt|;
name|DD
operator|.
name|Kind
operator|=
name|Deprecation
expr_stmt|;
name|DD
operator|.
name|Triggered
operator|=
name|false
expr_stmt|;
name|DD
operator|.
name|Loc
operator|=
name|Loc
expr_stmt|;
name|DD
operator|.
name|DeprecationData
operator|.
name|Decl
operator|=
name|D
expr_stmt|;
name|DD
operator|.
name|DeprecationData
operator|.
name|Message
operator|=
name|Msg
operator|.
name|data
argument_list|()
expr_stmt|;
name|DD
operator|.
name|DeprecationData
operator|.
name|MessageLen
operator|=
name|Msg
operator|.
name|size
argument_list|()
expr_stmt|;
return|return
name|DD
return|;
block|}
specifier|static
name|DelayedDiagnostic
name|makeAccess
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|AccessedEntity
modifier|&
name|Entity
parameter_list|)
block|{
name|DelayedDiagnostic
name|DD
decl_stmt|;
name|DD
operator|.
name|Kind
operator|=
name|Access
expr_stmt|;
name|DD
operator|.
name|Triggered
operator|=
name|false
expr_stmt|;
name|DD
operator|.
name|Loc
operator|=
name|Loc
expr_stmt|;
name|new
argument_list|(
argument|&DD.getAccessData()
argument_list|)
name|AccessedEntity
argument_list|(
name|Entity
argument_list|)
expr_stmt|;
return|return
name|DD
return|;
block|}
name|AccessedEntity
modifier|&
name|getAccessData
parameter_list|()
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Access
operator|&&
literal|"Not an access diagnostic."
argument_list|)
expr_stmt|;
return|return
operator|*
name|reinterpret_cast
operator|<
name|AccessedEntity
operator|*
operator|>
operator|(
name|AccessData
operator|)
return|;
block|}
specifier|const
name|AccessedEntity
operator|&
name|getAccessData
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Access
operator|&&
literal|"Not an access diagnostic."
argument_list|)
block|;
return|return
operator|*
name|reinterpret_cast
operator|<
specifier|const
name|AccessedEntity
operator|*
operator|>
operator|(
name|AccessData
operator|)
return|;
block|}
specifier|const
name|NamedDecl
operator|*
name|getDeprecationDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Deprecation
operator|&&
literal|"Not a deprecation diagnostic."
argument_list|)
block|;
return|return
name|DeprecationData
operator|.
name|Decl
return|;
block|}
name|llvm
operator|::
name|StringRef
name|getDeprecationMessage
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Deprecation
operator|&&
literal|"Not a deprecation diagnostic."
argument_list|)
block|;
return|return
name|llvm
operator|::
name|StringRef
argument_list|(
name|DeprecationData
operator|.
name|Message
argument_list|,
name|DeprecationData
operator|.
name|MessageLen
argument_list|)
return|;
block|}
name|private
label|:
union|union
block|{
comment|/// Deprecation.
struct|struct
block|{
specifier|const
name|NamedDecl
modifier|*
name|Decl
decl_stmt|;
specifier|const
name|char
modifier|*
name|Message
decl_stmt|;
name|size_t
name|MessageLen
decl_stmt|;
block|}
name|DeprecationData
struct|;
comment|/// Access control.
name|char
name|AccessData
index|[
sizeof|sizeof
argument_list|(
name|AccessedEntity
argument_list|)
index|]
decl_stmt|;
block|}
union|;
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

