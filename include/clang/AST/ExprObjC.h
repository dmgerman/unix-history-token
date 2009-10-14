begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExprObjC.h - Classes for representing ObjC expressions -*- C++ -*-===//
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
comment|//  This file defines the ExprObjC interface and subclasses.
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
name|LLVM_CLANG_AST_EXPROBJC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXPROBJC_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|ObjCMethodDecl
decl_stmt|;
name|class
name|ObjCPropertyDecl
decl_stmt|;
comment|/// ObjCStringLiteral, used for Objective-C string literals
comment|/// i.e. @"foo".
name|class
name|ObjCStringLiteral
range|:
name|public
name|Expr
block|{
name|Stmt
operator|*
name|String
block|;
name|SourceLocation
name|AtLoc
block|;
name|public
operator|:
name|ObjCStringLiteral
argument_list|(
argument|StringLiteral *SL
argument_list|,
argument|QualType T
argument_list|,
argument|SourceLocation L
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCStringLiteralClass
argument_list|,
name|T
argument_list|)
block|,
name|String
argument_list|(
name|SL
argument_list|)
block|,
name|AtLoc
argument_list|(
argument|L
argument_list|)
block|{}
name|explicit
name|ObjCStringLiteral
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCStringLiteralClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|StringLiteral
operator|*
name|getString
argument_list|()
block|{
return|return
name|cast
operator|<
name|StringLiteral
operator|>
operator|(
name|String
operator|)
return|;
block|}
specifier|const
name|StringLiteral
operator|*
name|getString
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|StringLiteral
operator|>
operator|(
name|String
operator|)
return|;
block|}
name|void
name|setString
argument_list|(
argument|StringLiteral *S
argument_list|)
block|{
name|String
operator|=
name|S
block|; }
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|AtLoc
argument_list|,
name|String
operator|->
name|getLocEnd
argument_list|()
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCStringLiteralClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCStringLiteral *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCEncodeExpr, used for @encode in Objective-C.  @encode has the same type
comment|/// and behavior as StringLiteral except that the string initializer is obtained
comment|/// from ASTContext with the encoding type as an argument.
name|class
name|ObjCEncodeExpr
range|:
name|public
name|Expr
block|{
name|QualType
name|EncType
block|;
name|SourceLocation
name|AtLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCEncodeExpr
argument_list|(
argument|QualType T
argument_list|,
argument|QualType ET
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCEncodeExprClass
argument_list|,
name|T
argument_list|,
name|ET
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|ET
operator|->
name|isDependentType
argument_list|()
argument_list|)
block|,
name|EncType
argument_list|(
name|ET
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCEncodeExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCEncodeExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|QualType
name|getEncodedType
argument_list|()
specifier|const
block|{
return|return
name|EncType
return|;
block|}
name|void
name|setEncodedType
argument_list|(
argument|QualType T
argument_list|)
block|{
name|EncType
operator|=
name|T
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|AtLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCEncodeExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCEncodeExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCSelectorExpr used for @selector in Objective-C.
name|class
name|ObjCSelectorExpr
range|:
name|public
name|Expr
block|{
name|Selector
name|SelName
block|;
name|SourceLocation
name|AtLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCSelectorExpr
argument_list|(
argument|QualType T
argument_list|,
argument|Selector selInfo
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCSelectorExprClass
argument_list|,
name|T
argument_list|)
block|,
name|SelName
argument_list|(
name|selInfo
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCSelectorExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCSelectorExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
return|return
name|SelName
return|;
block|}
name|void
name|setSelector
argument_list|(
argument|Selector S
argument_list|)
block|{
name|SelName
operator|=
name|S
block|; }
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|AtLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
comment|/// getNumArgs - Return the number of actual arguments to this call.
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|SelName
operator|.
name|getNumArgs
argument_list|()
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCSelectorExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCSelectorExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCProtocolExpr used for protocol expression in Objective-C.  This is used
comment|/// as: @protocol(foo), as in:
comment|///   obj conformsToProtocol:@protocol(foo)]
comment|/// The return type is "Protocol*".
name|class
name|ObjCProtocolExpr
range|:
name|public
name|Expr
block|{
name|ObjCProtocolDecl
operator|*
name|TheProtocol
block|;
name|SourceLocation
name|AtLoc
block|,
name|RParenLoc
block|;
name|public
operator|:
name|ObjCProtocolExpr
argument_list|(
argument|QualType T
argument_list|,
argument|ObjCProtocolDecl *protocol
argument_list|,
argument|SourceLocation at
argument_list|,
argument|SourceLocation rp
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCProtocolExprClass
argument_list|,
name|T
argument_list|)
block|,
name|TheProtocol
argument_list|(
name|protocol
argument_list|)
block|,
name|AtLoc
argument_list|(
name|at
argument_list|)
block|,
name|RParenLoc
argument_list|(
argument|rp
argument_list|)
block|{}
name|explicit
name|ObjCProtocolExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCProtocolExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCProtocolDecl
operator|*
name|getProtocol
argument_list|()
specifier|const
block|{
return|return
name|TheProtocol
return|;
block|}
name|void
name|setProtocol
argument_list|(
argument|ObjCProtocolDecl *P
argument_list|)
block|{
name|TheProtocol
operator|=
name|P
block|; }
name|SourceLocation
name|getAtLoc
argument_list|()
specifier|const
block|{
return|return
name|AtLoc
return|;
block|}
name|SourceLocation
name|getRParenLoc
argument_list|()
specifier|const
block|{
return|return
name|RParenLoc
return|;
block|}
name|void
name|setAtLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|AtLoc
operator|=
name|L
block|; }
name|void
name|setRParenLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|RParenLoc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|AtLoc
argument_list|,
name|RParenLoc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCProtocolExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCProtocolExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCIvarRefExpr - A reference to an ObjC instance variable.
name|class
name|ObjCIvarRefExpr
range|:
name|public
name|Expr
block|{
name|class
name|ObjCIvarDecl
operator|*
name|D
block|;
name|SourceLocation
name|Loc
block|;
name|Stmt
operator|*
name|Base
block|;
name|bool
name|IsArrow
operator|:
literal|1
block|;
comment|// True if this is "X->F", false if this is "X.F".
name|bool
name|IsFreeIvar
operator|:
literal|1
block|;
comment|// True if ivar reference has no base (self assumed).
name|public
operator|:
name|ObjCIvarRefExpr
argument_list|(
argument|ObjCIvarDecl *d
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|,
argument|Expr *base=
literal|0
argument_list|,
argument|bool arrow = false
argument_list|,
argument|bool freeIvar = false
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCIvarRefExprClass
argument_list|,
name|t
argument_list|)
block|,
name|D
argument_list|(
name|d
argument_list|)
block|,
name|Loc
argument_list|(
name|l
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|IsArrow
argument_list|(
name|arrow
argument_list|)
block|,
name|IsFreeIvar
argument_list|(
argument|freeIvar
argument_list|)
block|{}
name|explicit
name|ObjCIvarRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCIvarRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCIvarDecl
operator|*
name|getDecl
argument_list|()
block|{
return|return
name|D
return|;
block|}
specifier|const
name|ObjCIvarDecl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
return|return
name|D
return|;
block|}
name|void
name|setDecl
argument_list|(
argument|ObjCIvarDecl *d
argument_list|)
block|{
name|D
operator|=
name|d
block|; }
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|Expr
operator|*
name|getBase
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|void
name|setBase
argument_list|(
argument|Expr * base
argument_list|)
block|{
name|Base
operator|=
name|base
block|; }
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
name|bool
name|isFreeIvar
argument_list|()
specifier|const
block|{
return|return
name|IsFreeIvar
return|;
block|}
name|void
name|setIsArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
name|void
name|setIsFreeIvar
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsFreeIvar
operator|=
name|A
block|; }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|isFreeIvar
argument_list|()
operator|?
name|SourceRange
argument_list|(
name|Loc
argument_list|)
operator|:
name|SourceRange
argument_list|(
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|Loc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCIvarRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCIvarRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCPropertyRefExpr - A dot-syntax expression to access an ObjC
comment|/// property.
comment|///
name|class
name|ObjCPropertyRefExpr
range|:
name|public
name|Expr
block|{
name|private
operator|:
name|ObjCPropertyDecl
operator|*
name|AsProperty
block|;
name|SourceLocation
name|IdLoc
block|;
name|Stmt
operator|*
name|Base
block|;
name|public
operator|:
name|ObjCPropertyRefExpr
argument_list|(
argument|ObjCPropertyDecl *PD
argument_list|,
argument|QualType t
argument_list|,
argument|SourceLocation l
argument_list|,
argument|Expr *base
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCPropertyRefExprClass
argument_list|,
name|t
argument_list|)
block|,
name|AsProperty
argument_list|(
name|PD
argument_list|)
block|,
name|IdLoc
argument_list|(
name|l
argument_list|)
block|,
name|Base
argument_list|(
argument|base
argument_list|)
block|{   }
name|explicit
name|ObjCPropertyRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCPropertyRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCPropertyDecl
operator|*
name|getProperty
argument_list|()
specifier|const
block|{
return|return
name|AsProperty
return|;
block|}
name|void
name|setProperty
argument_list|(
argument|ObjCPropertyDecl *D
argument_list|)
block|{
name|AsProperty
operator|=
name|D
block|; }
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|Expr
operator|*
name|getBase
argument_list|()
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|void
name|setBase
argument_list|(
argument|Expr *base
argument_list|)
block|{
name|Base
operator|=
name|base
block|; }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|IdLoc
return|;
block|}
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|IdLoc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|IdLoc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCPropertyRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCPropertyRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
comment|/// ObjCImplicitSetterGetterRefExpr - A dot-syntax expression to access two
comment|/// methods; one to set a value to an 'ivar' (Setter) and the other to access
comment|/// an 'ivar' (Setter).
comment|/// An example for use of this AST is:
comment|/// @code
comment|///  @interface Test { }
comment|///  - (Test *)crash;
comment|///  - (void)setCrash: (Test*)value;
comment|/// @end
comment|/// void  foo(Test *p1, Test *p2)
comment|/// {
comment|///    p2.crash  = p1.crash; // Uses ObjCImplicitSetterGetterRefExpr AST
comment|/// }
comment|/// @endcode
name|class
name|ObjCImplicitSetterGetterRefExpr
range|:
name|public
name|Expr
block|{
comment|/// Setter - Setter method user declared for setting its 'ivar' to a value
name|ObjCMethodDecl
operator|*
name|Setter
block|;
comment|/// Getter - Getter method user declared for accessing 'ivar' it controls.
name|ObjCMethodDecl
operator|*
name|Getter
block|;
comment|/// Location of the member in the dot syntax notation. This is location
comment|/// of the getter method.
name|SourceLocation
name|MemberLoc
block|;
comment|// FIXME: Swizzle these into a single pointer.
name|Stmt
operator|*
name|Base
block|;
name|ObjCInterfaceDecl
operator|*
name|InterfaceDecl
block|;
comment|/// Location of the receiver class in the dot syntax notation
comment|/// used to call a class method setter/getter.
name|SourceLocation
name|ClassLoc
block|;
name|public
operator|:
name|ObjCImplicitSetterGetterRefExpr
argument_list|(
argument|ObjCMethodDecl *getter
argument_list|,
argument|QualType t
argument_list|,
argument|ObjCMethodDecl *setter
argument_list|,
argument|SourceLocation l
argument_list|,
argument|Expr *base
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCImplicitSetterGetterRefExprClass
argument_list|,
name|t
argument_list|)
block|,
name|Setter
argument_list|(
name|setter
argument_list|)
block|,
name|Getter
argument_list|(
name|getter
argument_list|)
block|,
name|MemberLoc
argument_list|(
name|l
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|InterfaceDecl
argument_list|(
literal|0
argument_list|)
block|,
name|ClassLoc
argument_list|(
argument|SourceLocation()
argument_list|)
block|{     }
name|ObjCImplicitSetterGetterRefExpr
argument_list|(
argument|ObjCMethodDecl *getter
argument_list|,
argument|QualType t
argument_list|,
argument|ObjCMethodDecl *setter
argument_list|,
argument|SourceLocation l
argument_list|,
argument|ObjCInterfaceDecl *C
argument_list|,
argument|SourceLocation CL
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCImplicitSetterGetterRefExprClass
argument_list|,
name|t
argument_list|)
block|,
name|Setter
argument_list|(
name|setter
argument_list|)
block|,
name|Getter
argument_list|(
name|getter
argument_list|)
block|,
name|MemberLoc
argument_list|(
name|l
argument_list|)
block|,
name|Base
argument_list|(
literal|0
argument_list|)
block|,
name|InterfaceDecl
argument_list|(
name|C
argument_list|)
block|,
name|ClassLoc
argument_list|(
argument|CL
argument_list|)
block|{     }
name|explicit
name|ObjCImplicitSetterGetterRefExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCImplicitSetterGetterRefExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|ObjCMethodDecl
operator|*
name|getGetterMethod
argument_list|()
specifier|const
block|{
return|return
name|Getter
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getSetterMethod
argument_list|()
specifier|const
block|{
return|return
name|Setter
return|;
block|}
name|ObjCInterfaceDecl
operator|*
name|getInterfaceDecl
argument_list|()
specifier|const
block|{
return|return
name|InterfaceDecl
return|;
block|}
name|void
name|setGetterMethod
argument_list|(
argument|ObjCMethodDecl *D
argument_list|)
block|{
name|Getter
operator|=
name|D
block|; }
name|void
name|setSetterMethod
argument_list|(
argument|ObjCMethodDecl *D
argument_list|)
block|{
name|Setter
operator|=
name|D
block|; }
name|void
name|setInterfaceDecl
argument_list|(
argument|ObjCInterfaceDecl *D
argument_list|)
block|{
name|InterfaceDecl
operator|=
name|D
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Base
condition|)
return|return
name|SourceRange
argument_list|(
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|MemberLoc
argument_list|)
return|;
return|return
name|SourceRange
argument_list|(
name|ClassLoc
argument_list|,
name|MemberLoc
argument_list|)
return|;
block|}
specifier|const
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|Expr
modifier|*
name|getBase
parameter_list|()
block|{
return|return
name|cast_or_null
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|void
name|setBase
parameter_list|(
name|Expr
modifier|*
name|base
parameter_list|)
block|{
name|Base
operator|=
name|base
expr_stmt|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|MemberLoc
return|;
block|}
name|void
name|setLocation
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|MemberLoc
operator|=
name|L
expr_stmt|;
block|}
name|SourceLocation
name|getClassLoc
argument_list|()
specifier|const
block|{
return|return
name|ClassLoc
return|;
block|}
name|void
name|setClassLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|ClassLoc
operator|=
name|L
expr_stmt|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCImplicitSetterGetterRefExprClass
return|;
block|}
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ObjCImplicitSetterGetterRefExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
parameter_list|()
function_decl|;
name|virtual
name|child_iterator
name|child_end
parameter_list|()
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|ObjCMessageExpr
range|:
name|public
name|Expr
block|{
comment|// SubExprs - The receiver and arguments of the message expression.
name|Stmt
operator|*
operator|*
name|SubExprs
block|;
comment|// NumArgs - The number of arguments (not including the receiver) to the
comment|//  message expression.
name|unsigned
name|NumArgs
block|;
comment|// A unigue name for this message.
name|Selector
name|SelName
block|;
comment|// A method prototype for this message (optional).
comment|// FIXME: Since method decls contain the selector, and most messages have a
comment|// prototype, consider devising a scheme for unifying SelName/MethodProto.
name|ObjCMethodDecl
operator|*
name|MethodProto
block|;
name|SourceLocation
name|LBracloc
block|,
name|RBracloc
block|;
comment|// Constants for indexing into SubExprs.
block|enum
block|{
name|RECEIVER
operator|=
literal|0
block|,
name|ARGS_START
operator|=
literal|1
block|}
block|;
comment|// Bit-swizzling flags.
block|enum
block|{
name|IsInstMeth
operator|=
literal|0
block|,
name|IsClsMethDeclUnknown
block|,
name|IsClsMethDeclKnown
block|,
name|Flags
operator|=
literal|0x3
block|}
block|;
name|unsigned
name|getFlag
argument_list|()
specifier|const
block|{
return|return
operator|(
name|uintptr_t
operator|)
name|SubExprs
index|[
name|RECEIVER
index|]
operator|&
name|Flags
return|;
block|}
name|public
operator|:
comment|/// This constructor is used to represent class messages where the
comment|/// ObjCInterfaceDecl* of the receiver is not known.
name|ObjCMessageExpr
argument_list|(
argument|IdentifierInfo *clsName
argument_list|,
argument|Selector selInfo
argument_list|,
argument|QualType retType
argument_list|,
argument|ObjCMethodDecl *methDecl
argument_list|,
argument|SourceLocation LBrac
argument_list|,
argument|SourceLocation RBrac
argument_list|,
argument|Expr **ArgExprs
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
comment|/// This constructor is used to represent class messages where the
comment|/// ObjCInterfaceDecl* of the receiver is known.
comment|// FIXME: clsName should be typed to ObjCInterfaceType
name|ObjCMessageExpr
argument_list|(
argument|ObjCInterfaceDecl *cls
argument_list|,
argument|Selector selInfo
argument_list|,
argument|QualType retType
argument_list|,
argument|ObjCMethodDecl *methDecl
argument_list|,
argument|SourceLocation LBrac
argument_list|,
argument|SourceLocation RBrac
argument_list|,
argument|Expr **ArgExprs
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
comment|// constructor for instance messages.
name|ObjCMessageExpr
argument_list|(
argument|Expr *receiver
argument_list|,
argument|Selector selInfo
argument_list|,
argument|QualType retType
argument_list|,
argument|ObjCMethodDecl *methDecl
argument_list|,
argument|SourceLocation LBrac
argument_list|,
argument|SourceLocation RBrac
argument_list|,
argument|Expr **ArgExprs
argument_list|,
argument|unsigned NumArgs
argument_list|)
block|;
name|explicit
name|ObjCMessageExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCMessageExprClass
argument_list|,
name|Empty
argument_list|)
block|,
name|SubExprs
argument_list|(
literal|0
argument_list|)
block|,
name|NumArgs
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|ObjCMessageExpr
argument_list|()
block|{
name|delete
index|[]
name|SubExprs
block|;   }
comment|/// getReceiver - Returns the receiver of the message expression.
comment|///  This can be NULL if the message is for class methods.  For
comment|///  class methods, use getClassName.
comment|/// FIXME: need to handle/detect 'super' usage within a class method.
name|Expr
operator|*
name|getReceiver
argument_list|()
block|{
name|uintptr_t
name|x
operator|=
operator|(
name|uintptr_t
operator|)
name|SubExprs
index|[
name|RECEIVER
index|]
block|;
return|return
operator|(
name|x
operator|&
name|Flags
operator|)
operator|==
name|IsInstMeth
condition|?
operator|(
name|Expr
operator|*
operator|)
name|x
else|:
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getReceiver
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|ObjCMessageExpr
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getReceiver
argument_list|()
return|;
block|}
comment|// FIXME: need setters for different receiver types.
name|void
name|setReceiver
argument_list|(
argument|Expr *rec
argument_list|)
block|{
name|SubExprs
index|[
name|RECEIVER
index|]
operator|=
name|rec
block|; }
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
return|return
name|SelName
return|;
block|}
name|void
name|setSelector
argument_list|(
argument|Selector S
argument_list|)
block|{
name|SelName
operator|=
name|S
block|; }
specifier|const
name|ObjCMethodDecl
operator|*
name|getMethodDecl
argument_list|()
specifier|const
block|{
return|return
name|MethodProto
return|;
block|}
name|ObjCMethodDecl
operator|*
name|getMethodDecl
argument_list|()
block|{
return|return
name|MethodProto
return|;
block|}
name|void
name|setMethodDecl
argument_list|(
argument|ObjCMethodDecl *MD
argument_list|)
block|{
name|MethodProto
operator|=
name|MD
block|; }
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|ObjCInterfaceDecl
operator|*
operator|,
name|IdentifierInfo
operator|*
operator|>
name|ClassInfo
expr_stmt|;
comment|/// getClassInfo - For class methods, this returns both the ObjCInterfaceDecl*
comment|///  and IdentifierInfo* of the invoked class.  Both can be NULL if this
comment|///  is an instance message, and the ObjCInterfaceDecl* can be NULL if none
comment|///  was available when this ObjCMessageExpr object was constructed.
name|ClassInfo
name|getClassInfo
argument_list|()
specifier|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|setClassInfo
parameter_list|(
specifier|const
name|ClassInfo
modifier|&
name|C
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// getClassName - For class methods, this returns the invoked class,
end_comment

begin_comment
comment|///  and returns NULL otherwise.  For instance methods, use getReceiver.
end_comment

begin_expr_stmt
name|IdentifierInfo
operator|*
name|getClassName
argument_list|()
specifier|const
block|{
return|return
name|getClassInfo
argument_list|()
operator|.
name|second
return|;
block|}
end_expr_stmt

begin_comment
comment|/// getNumArgs - Return the number of actual arguments to this call.
end_comment

begin_expr_stmt
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArgs
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setNumArgs
parameter_list|(
name|unsigned
name|nArgs
parameter_list|)
block|{
name|NumArgs
operator|=
name|nArgs
expr_stmt|;
comment|// FIXME: should always allocate SubExprs via the ASTContext's
comment|// allocator.
if|if
condition|(
operator|!
name|SubExprs
condition|)
name|SubExprs
operator|=
name|new
name|Stmt
operator|*
index|[
name|NumArgs
operator|+
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/// getArg - Return the specified argument.
end_comment

begin_function
name|Expr
modifier|*
name|getArg
parameter_list|(
name|unsigned
name|Arg
parameter_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
index|]
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|Expr
modifier|*
name|getArg
argument_list|(
name|unsigned
name|Arg
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
index|]
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// setArg - Set the specified argument.
end_comment

begin_function
name|void
name|setArg
parameter_list|(
name|unsigned
name|Arg
parameter_list|,
name|Expr
modifier|*
name|ArgExpr
parameter_list|)
block|{
name|assert
argument_list|(
name|Arg
operator|<
name|NumArgs
operator|&&
literal|"Arg access out of range!"
argument_list|)
expr_stmt|;
name|SubExprs
index|[
name|Arg
operator|+
name|ARGS_START
index|]
operator|=
name|ArgExpr
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|SourceLocation
name|getLeftLoc
argument_list|()
specifier|const
block|{
return|return
name|LBracloc
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|SourceLocation
name|getRightLoc
argument_list|()
specifier|const
block|{
return|return
name|RBracloc
return|;
block|}
end_expr_stmt

begin_function
name|void
name|setLeftLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|LBracloc
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setRightLoc
parameter_list|(
name|SourceLocation
name|L
parameter_list|)
block|{
name|RBracloc
operator|=
name|L
expr_stmt|;
block|}
end_function

begin_function
name|void
name|setSourceRange
parameter_list|(
name|SourceRange
name|R
parameter_list|)
block|{
name|LBracloc
operator|=
name|R
operator|.
name|getBegin
argument_list|()
expr_stmt|;
name|RBracloc
operator|=
name|R
operator|.
name|getEnd
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|LBracloc
argument_list|,
name|RBracloc
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|T
parameter_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCMessageExprClass
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|ObjCMessageExpr
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|// Iterators
end_comment

begin_function_decl
name|virtual
name|child_iterator
name|child_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|virtual
name|child_iterator
name|child_end
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|ExprIterator
name|arg_iterator
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ConstExprIterator
name|const_arg_iterator
typedef|;
end_typedef

begin_function
name|arg_iterator
name|arg_begin
parameter_list|()
block|{
return|return
operator|&
name|SubExprs
index|[
name|ARGS_START
index|]
return|;
block|}
end_function

begin_function
name|arg_iterator
name|arg_end
parameter_list|()
block|{
return|return
operator|&
name|SubExprs
index|[
name|ARGS_START
index|]
operator|+
name|NumArgs
return|;
block|}
end_function

begin_expr_stmt
name|const_arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
operator|&
name|SubExprs
index|[
name|ARGS_START
index|]
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
operator|&
name|SubExprs
index|[
name|ARGS_START
index|]
operator|+
name|NumArgs
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// ObjCSuperExpr - Represents the "super" expression in Objective-C,
end_comment

begin_comment
comment|/// which refers to the object on which the current method is executing.
end_comment

begin_decl_stmt
name|class
name|ObjCSuperExpr
range|:
name|public
name|Expr
block|{
name|SourceLocation
name|Loc
block|;
name|public
operator|:
name|ObjCSuperExpr
argument_list|(
argument|SourceLocation L
argument_list|,
argument|QualType Type
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCSuperExprClass
argument_list|,
name|Type
argument_list|)
block|,
name|Loc
argument_list|(
argument|L
argument_list|)
block|{ }
name|explicit
name|ObjCSuperExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCSuperExprClass
argument_list|,
argument|Empty
argument_list|)
block|{}
name|SourceLocation
name|getLoc
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
name|void
name|setLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|Loc
argument_list|)
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCSuperExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCSuperExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// ObjCIsaExpr - Represent X->isa and X.isa when X is an ObjC 'id' type.
end_comment

begin_comment
comment|/// (similiar in spirit to MemberExpr).
end_comment

begin_decl_stmt
name|class
name|ObjCIsaExpr
range|:
name|public
name|Expr
block|{
comment|/// Base - the expression for the base object pointer.
name|Stmt
operator|*
name|Base
block|;
comment|/// IsaMemberLoc - This is the location of the 'isa'.
name|SourceLocation
name|IsaMemberLoc
block|;
comment|/// IsArrow - True if this is "X->F", false if this is "X.F".
name|bool
name|IsArrow
block|;
name|public
operator|:
name|ObjCIsaExpr
argument_list|(
argument|Expr *base
argument_list|,
argument|bool isarrow
argument_list|,
argument|SourceLocation l
argument_list|,
argument|QualType ty
argument_list|)
operator|:
name|Expr
argument_list|(
name|ObjCIsaExprClass
argument_list|,
name|ty
argument_list|)
block|,
name|Base
argument_list|(
name|base
argument_list|)
block|,
name|IsaMemberLoc
argument_list|(
name|l
argument_list|)
block|,
name|IsArrow
argument_list|(
argument|isarrow
argument_list|)
block|{}
comment|/// \brief Build an empty expression.
name|explicit
name|ObjCIsaExpr
argument_list|(
argument|EmptyShell Empty
argument_list|)
operator|:
name|Expr
argument_list|(
argument|ObjCIsaExprClass
argument_list|,
argument|Empty
argument_list|)
block|{ }
name|void
name|setBase
argument_list|(
argument|Expr *E
argument_list|)
block|{
name|Base
operator|=
name|E
block|; }
name|Expr
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|cast
operator|<
name|Expr
operator|>
operator|(
name|Base
operator|)
return|;
block|}
name|bool
name|isArrow
argument_list|()
specifier|const
block|{
return|return
name|IsArrow
return|;
block|}
name|void
name|setArrow
argument_list|(
argument|bool A
argument_list|)
block|{
name|IsArrow
operator|=
name|A
block|; }
comment|/// getMemberLoc - Return the location of the "member", in X->F, it is the
comment|/// location of 'F'.
name|SourceLocation
name|getIsaMemberLoc
argument_list|()
specifier|const
block|{
return|return
name|IsaMemberLoc
return|;
block|}
name|void
name|setIsaMemberLoc
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|IsaMemberLoc
operator|=
name|L
block|; }
name|virtual
name|SourceRange
name|getSourceRange
argument_list|()
specifier|const
block|{
return|return
name|SourceRange
argument_list|(
name|getBase
argument_list|()
operator|->
name|getLocStart
argument_list|()
argument_list|,
name|IsaMemberLoc
argument_list|)
return|;
block|}
name|virtual
name|SourceLocation
name|getExprLoc
argument_list|()
specifier|const
block|{
return|return
name|IsaMemberLoc
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const Stmt *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getStmtClass
argument_list|()
operator|==
name|ObjCIsaExprClass
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const ObjCIsaExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|// Iterators
name|virtual
name|child_iterator
name|child_begin
argument_list|()
block|;
name|virtual
name|child_iterator
name|child_end
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

