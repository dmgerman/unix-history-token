begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Ownership.h - Parser ownership helpers -----------------*- C++ -*-===//
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
comment|//  This file contains classes for managing ownership of Stmt and Expr nodes.
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
name|LLVM_CLANG_SEMA_OWNERSHIP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_OWNERSHIP_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// OpaquePtr
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Attr
decl_stmt|;
name|class
name|CXXCtorInitializer
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclGroupRef
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|QualType
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TemplateName
decl_stmt|;
name|class
name|TemplateParameterList
decl_stmt|;
comment|/// OpaquePtr - This is a very simple POD type that wraps a pointer that the
comment|/// Parser doesn't know about but that Sema or another client does.  The UID
comment|/// template argument is used to make sure that "Decl" pointers are not
comment|/// compatible with "Type" pointers for example.
name|template
operator|<
name|class
name|PtrTy
operator|>
name|class
name|OpaquePtr
block|{
name|void
operator|*
name|Ptr
block|;
name|explicit
name|OpaquePtr
argument_list|(
name|void
operator|*
name|Ptr
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|Ptr
argument_list|)
block|{}
typedef|typedef
name|llvm
operator|::
name|PointerLikeTypeTraits
operator|<
name|PtrTy
operator|>
name|Traits
expr_stmt|;
name|public
operator|:
name|OpaquePtr
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{}
specifier|static
name|OpaquePtr
name|make
argument_list|(
argument|PtrTy P
argument_list|)
block|{
name|OpaquePtr
name|OP
block|;
name|OP
operator|.
name|set
argument_list|(
name|P
argument_list|)
block|;
return|return
name|OP
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getAs
argument_list|()
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|getAsVal
argument_list|()
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
name|PtrTy
name|get
argument_list|()
specifier|const
block|{
return|return
name|Traits
operator|::
name|getFromVoidPointer
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
name|void
name|set
parameter_list|(
name|PtrTy
name|P
parameter_list|)
block|{
name|Ptr
operator|=
name|Traits
operator|::
name|getAsVoidPointer
argument_list|(
name|P
argument_list|)
expr_stmt|;
block|}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
name|void
operator|*
name|getAsOpaquePtr
argument_list|()
specifier|const
block|{
return|return
name|Ptr
return|;
block|}
specifier|static
name|OpaquePtr
name|getFromOpaquePtr
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
block|{
return|return
name|OpaquePtr
argument_list|(
name|P
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// UnionOpaquePtr - A version of OpaquePtr suitable for membership
end_comment

begin_comment
comment|/// in a union.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|UnionOpaquePtr
block|{
name|void
operator|*
name|Ptr
block|;
specifier|static
name|UnionOpaquePtr
name|make
argument_list|(
argument|OpaquePtr<T> P
argument_list|)
block|{
name|UnionOpaquePtr
name|OP
operator|=
block|{
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
block|}
block|;
return|return
name|OP
return|;
block|}
name|OpaquePtr
operator|<
name|T
operator|>
name|get
argument_list|()
specifier|const
block|{
return|return
name|OpaquePtr
operator|<
name|T
operator|>
operator|::
name|getFromOpaquePtr
argument_list|(
name|Ptr
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|OpaquePtr
operator|<
name|T
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|UnionOpaquePtr
modifier|&
name|operator
init|=
operator|(
name|OpaquePtr
operator|<
name|T
operator|>
name|P
operator|)
block|{
name|Ptr
operator|=
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_macro
unit|}; }  namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|clang
operator|::
name|OpaquePtr
operator|<
name|T
operator|>
expr|>
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|clang::OpaquePtr<T> P
argument_list|)
block|{
comment|// FIXME: Doesn't work? return P.getAs< void>();
return|return
name|P
operator|.
name|getAsOpaquePtr
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|OpaquePtr
operator|<
name|T
operator|>
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|clang
operator|::
name|OpaquePtr
operator|<
name|T
operator|>
operator|::
name|getFromOpaquePtr
argument_list|(
name|P
argument_list|)
return|;
block|}
enum|enum
block|{
name|NumLowBitsAvailable
init|=
literal|0
block|}
enum|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|OpaquePtr
operator|<
name|T
operator|>
expr|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// -------------------------- About Move Emulation -------------------------- //
end_comment

begin_comment
comment|// The smart pointer classes in this file attempt to emulate move semantics
end_comment

begin_comment
comment|// as they appear in C++0x with rvalue references. Since C++03 doesn't have
end_comment

begin_comment
comment|// rvalue references, some tricks are needed to get similar results.
end_comment

begin_comment
comment|// Move semantics in C++0x have the following properties:
end_comment

begin_comment
comment|// 1) "Moving" means transferring the value of an object to another object,
end_comment

begin_comment
comment|//    similar to copying, but without caring what happens to the old object.
end_comment

begin_comment
comment|//    In particular, this means that the new object can steal the old object's
end_comment

begin_comment
comment|//    resources instead of creating a copy.
end_comment

begin_comment
comment|// 2) Since moving can modify the source object, it must either be explicitly
end_comment

begin_comment
comment|//    requested by the user, or the modifications must be unnoticeable.
end_comment

begin_comment
comment|// 3) As such, C++0x moving is only allowed in three contexts:
end_comment

begin_comment
comment|//    * By explicitly using std::move() to request it.
end_comment

begin_comment
comment|//    * From a temporary object, since that object cannot be accessed
end_comment

begin_comment
comment|//      afterwards anyway, thus making the state unobservable.
end_comment

begin_comment
comment|//    * On function return, since the object is not observable afterwards.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// To sum up: moving from a named object should only be possible with an
end_comment

begin_comment
comment|// explicit std::move(), or on function return. Moving from a temporary should
end_comment

begin_comment
comment|// be implicitly done. Moving from a const object is forbidden.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The emulation is not perfect, and has the following shortcomings:
end_comment

begin_comment
comment|// * move() is not in namespace std.
end_comment

begin_comment
comment|// * move() is required on function return.
end_comment

begin_comment
comment|// * There are difficulties with implicit conversions.
end_comment

begin_comment
comment|// * Microsoft's compiler must be given the /Za switch to successfully compile.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------- Implementation -------------------------------- //
end_comment

begin_comment
comment|// The move emulation relies on the peculiar reference binding semantics of
end_comment

begin_comment
comment|// C++03: as a rule, a non-const reference may not bind to a temporary object,
end_comment

begin_comment
comment|// except for the implicit object parameter in a member function call, which
end_comment

begin_comment
comment|// can refer to a temporary even when not being const.
end_comment

begin_comment
comment|// The moveable object has five important functions to facilitate moving:
end_comment

begin_comment
comment|// * A private, unimplemented constructor taking a non-const reference to its
end_comment

begin_comment
comment|//   own class. This constructor serves a two-fold purpose.
end_comment

begin_comment
comment|//   - It prevents the creation of a copy constructor that takes a const
end_comment

begin_comment
comment|//     reference. Temporaries would be able to bind to the argument of such a
end_comment

begin_comment
comment|//     constructor, and that would be bad.
end_comment

begin_comment
comment|//   - Named objects will bind to the non-const reference, but since it's
end_comment

begin_comment
comment|//     private, this will fail to compile. This prevents implicit moving from
end_comment

begin_comment
comment|//     named objects.
end_comment

begin_comment
comment|//   There's also a copy assignment operator for the same purpose.
end_comment

begin_comment
comment|// * An implicit, non-const conversion operator to a special mover type. This
end_comment

begin_comment
comment|//   type represents the rvalue reference of C++0x. Being a non-const member,
end_comment

begin_comment
comment|//   its implicit this parameter can bind to temporaries.
end_comment

begin_comment
comment|// * A constructor that takes an object of this mover type. This constructor
end_comment

begin_comment
comment|//   performs the actual move operation. There is an equivalent assignment
end_comment

begin_comment
comment|//   operator.
end_comment

begin_comment
comment|// There is also a free move() function that takes a non-const reference to
end_comment

begin_comment
comment|// an object and returns a temporary. Internally, this function uses explicit
end_comment

begin_comment
comment|// constructor calls to move the value from the referenced object to the return
end_comment

begin_comment
comment|// value.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// There are now three possible scenarios of use.
end_comment

begin_comment
comment|// * Copying from a const object. Constructor overload resolution will find the
end_comment

begin_comment
comment|//   non-const copy constructor, and the move constructor. The first is not
end_comment

begin_comment
comment|//   viable because the const object cannot be bound to the non-const reference.
end_comment

begin_comment
comment|//   The second fails because the conversion to the mover object is non-const.
end_comment

begin_comment
comment|//   Moving from a const object fails as intended.
end_comment

begin_comment
comment|// * Copying from a named object. Constructor overload resolution will select
end_comment

begin_comment
comment|//   the non-const copy constructor, but fail as intended, because this
end_comment

begin_comment
comment|//   constructor is private.
end_comment

begin_comment
comment|// * Copying from a temporary. Constructor overload resolution cannot select
end_comment

begin_comment
comment|//   the non-const copy constructor, because the temporary cannot be bound to
end_comment

begin_comment
comment|//   the non-const reference. It thus selects the move constructor. The
end_comment

begin_comment
comment|//   temporary can be bound to the implicit this parameter of the conversion
end_comment

begin_comment
comment|//   operator, because of the special binding rule. Construction succeeds.
end_comment

begin_comment
comment|//   Note that the Microsoft compiler, as an extension, allows binding
end_comment

begin_comment
comment|//   temporaries against non-const references. The compiler thus selects the
end_comment

begin_comment
comment|//   non-const copy constructor and fails, because the constructor is private.
end_comment

begin_comment
comment|//   Passing /Za (disable extensions) disables this behaviour.
end_comment

begin_comment
comment|// The free move() function is used to move from a named object.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note that when passing an object of a different type (the classes below
end_comment

begin_comment
comment|// have OwningResult and OwningPtr, which should be mixable), you get a problem.
end_comment

begin_comment
comment|// Argument passing and function return use copy initialization rules. The
end_comment

begin_comment
comment|// effect of this is that, when the source object is not already of the target
end_comment

begin_comment
comment|// type, the compiler will first seek a way to convert the source object to the
end_comment

begin_comment
comment|// target type, and only then attempt to copy the resulting object. This means
end_comment

begin_comment
comment|// that when passing an OwningResult where an OwningPtr is expected, the
end_comment

begin_comment
comment|// compiler will first seek a conversion from OwningResult to OwningPtr, then
end_comment

begin_comment
comment|// copy the OwningPtr. The resulting conversion sequence is:
end_comment

begin_comment
comment|// OwningResult object -> ResultMover -> OwningResult argument to
end_comment

begin_comment
comment|// OwningPtr(OwningResult) -> OwningPtr -> PtrMover -> final OwningPtr
end_comment

begin_comment
comment|// This conversion sequence is too complex to be allowed. Thus the special
end_comment

begin_comment
comment|// move_* functions, which help the compiler out with some explicit
end_comment

begin_comment
comment|// conversions.
end_comment

begin_macro
unit|namespace
name|clang
end_macro

begin_block
block|{
comment|// Basic
name|class
name|DiagnosticBuilder
decl_stmt|;
comment|// Determines whether the low bit of the result pointer for the
comment|// given UID is always zero. If so, ActionResult will use that bit
comment|// for it's "invalid" flag.
name|template
operator|<
name|class
name|Ptr
operator|>
expr|struct
name|IsResultPtrLowBitFree
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|false
block|;   }
expr_stmt|;
comment|/// ActionResult - This structure is used while parsing/acting on
comment|/// expressions, stmts, etc.  It encapsulates both the object returned by
comment|/// the action, plus a sense of whether or not it is valid.
comment|/// When CompressInvalid is true, the "invalid" flag will be
comment|/// stored in the low bit of the Val pointer.
name|template
operator|<
name|class
name|PtrTy
operator|,
name|bool
name|CompressInvalid
operator|=
name|IsResultPtrLowBitFree
operator|<
name|PtrTy
operator|>
operator|::
name|value
operator|>
name|class
name|ActionResult
block|{
name|PtrTy
name|Val
block|;
name|bool
name|Invalid
block|;
name|public
operator|:
name|ActionResult
argument_list|(
argument|bool Invalid = false
argument_list|)
operator|:
name|Val
argument_list|(
name|PtrTy
argument_list|()
argument_list|)
block|,
name|Invalid
argument_list|(
argument|Invalid
argument_list|)
block|{}
name|ActionResult
argument_list|(
argument|PtrTy val
argument_list|)
operator|:
name|Val
argument_list|(
name|val
argument_list|)
block|,
name|Invalid
argument_list|(
argument|false
argument_list|)
block|{}
name|ActionResult
argument_list|(
specifier|const
name|DiagnosticBuilder
operator|&
argument_list|)
operator|:
name|Val
argument_list|(
name|PtrTy
argument_list|()
argument_list|)
block|,
name|Invalid
argument_list|(
argument|true
argument_list|)
block|{}
comment|// These two overloads prevent void* -> bool conversions.
name|ActionResult
argument_list|(
specifier|const
name|void
operator|*
argument_list|)
block|;
name|ActionResult
argument_list|(
specifier|volatile
name|void
operator|*
argument_list|)
block|;
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|Invalid
return|;
block|}
name|bool
name|isUsable
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Invalid
operator|&&
name|Val
return|;
block|}
name|PtrTy
name|get
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|PtrTy
name|release
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|PtrTy
name|take
argument_list|()
specifier|const
block|{
return|return
name|Val
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|takeAs
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|get
argument_list|()
operator|)
return|;
block|}
name|void
name|set
parameter_list|(
name|PtrTy
name|V
parameter_list|)
block|{
name|Val
operator|=
name|V
expr_stmt|;
block|}
specifier|const
name|ActionResult
modifier|&
name|operator
init|=
operator|(
name|PtrTy
name|RHS
operator|)
block|{
name|Val
operator|=
name|RHS
block|;
name|Invalid
operator|=
name|false
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This ActionResult partial specialization places the "invalid"
end_comment

begin_comment
comment|// flag into the low bit of the pointer.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PtrTy
operator|>
name|class
name|ActionResult
operator|<
name|PtrTy
operator|,
name|true
operator|>
block|{
comment|// A pointer whose low bit is 1 if this result is invalid, 0
comment|// otherwise.
name|uintptr_t
name|PtrWithInvalid
block|;
typedef|typedef
name|llvm
operator|::
name|PointerLikeTypeTraits
operator|<
name|PtrTy
operator|>
name|PtrTraits
expr_stmt|;
name|public
operator|:
name|ActionResult
argument_list|(
argument|bool Invalid = false
argument_list|)
operator|:
name|PtrWithInvalid
argument_list|(
argument|static_cast<uintptr_t>(Invalid)
argument_list|)
block|{ }
name|ActionResult
argument_list|(
argument|PtrTy V
argument_list|)
block|{
name|void
operator|*
name|VP
operator|=
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|V
argument_list|)
block|;
name|PtrWithInvalid
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|VP
operator|)
block|;
name|assert
argument_list|(
operator|(
name|PtrWithInvalid
operator|&
literal|0x01
operator|)
operator|==
literal|0
operator|&&
literal|"Badly aligned pointer"
argument_list|)
block|;     }
name|ActionResult
argument_list|(
specifier|const
name|DiagnosticBuilder
operator|&
argument_list|)
operator|:
name|PtrWithInvalid
argument_list|(
literal|0x01
argument_list|)
block|{ }
comment|// These two overloads prevent void* -> bool conversions.
name|ActionResult
argument_list|(
specifier|const
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ActionResult
argument_list|(
specifier|volatile
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
name|PtrWithInvalid
operator|&
literal|0x01
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|isUsable
argument_list|()
specifier|const
block|{
return|return
name|PtrWithInvalid
operator|>
literal|0x01
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|PtrTy
name|get
argument_list|()
specifier|const
block|{
name|void
operator|*
name|VP
operator|=
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|PtrWithInvalid
operator|&
operator|~
literal|0x01
operator|)
block|;
return|return
name|PtrTraits
operator|::
name|getFromVoidPointer
argument_list|(
name|VP
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|PtrTy
name|take
argument_list|()
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|PtrTy
name|release
argument_list|()
specifier|const
block|{
return|return
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|takeAs
argument_list|()
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|get
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|void
name|set
parameter_list|(
name|PtrTy
name|V
parameter_list|)
block|{
name|void
modifier|*
name|VP
init|=
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|V
argument_list|)
decl_stmt|;
name|PtrWithInvalid
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|VP
operator|)
expr_stmt|;
name|assert
argument_list|(
operator|(
name|PtrWithInvalid
operator|&
literal|0x01
operator|)
operator|==
literal|0
operator|&&
literal|"Badly aligned pointer"
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|const
name|ActionResult
modifier|&
name|operator
init|=
operator|(
name|PtrTy
name|RHS
operator|)
block|{
name|void
operator|*
name|VP
operator|=
name|PtrTraits
operator|::
name|getAsVoidPointer
argument_list|(
name|RHS
argument_list|)
block|;
name|PtrWithInvalid
operator|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|VP
operator|)
block|;
name|assert
argument_list|(
operator|(
name|PtrWithInvalid
operator|&
literal|0x01
operator|)
operator|==
literal|0
operator|&&
literal|"Badly aligned pointer"
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// ASTMultiPtr - A moveable smart pointer to multiple AST nodes. Only owns
end_comment

begin_comment
comment|/// the individual pointers, not the array holding them.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PtrTy
operator|>
name|class
name|ASTMultiPtr
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|PtrTy
operator|>
name|class
name|ASTMultiPtr
block|{
name|PtrTy
operator|*
name|Nodes
block|;
name|unsigned
name|Count
block|;
name|public
operator|:
comment|// Normal copying implicitly defined
name|ASTMultiPtr
argument_list|()
operator|:
name|Nodes
argument_list|(
literal|0
argument_list|)
block|,
name|Count
argument_list|(
literal|0
argument_list|)
block|{}
name|explicit
name|ASTMultiPtr
argument_list|(
name|Sema
operator|&
argument_list|)
operator|:
name|Nodes
argument_list|(
literal|0
argument_list|)
block|,
name|Count
argument_list|(
literal|0
argument_list|)
block|{}
name|ASTMultiPtr
argument_list|(
argument|Sema&
argument_list|,
argument|PtrTy *nodes
argument_list|,
argument|unsigned count
argument_list|)
operator|:
name|Nodes
argument_list|(
name|nodes
argument_list|)
block|,
name|Count
argument_list|(
argument|count
argument_list|)
block|{}
comment|// Fake mover in Parse/AstGuard.h needs this:
name|ASTMultiPtr
argument_list|(
argument|PtrTy *nodes
argument_list|,
argument|unsigned count
argument_list|)
operator|:
name|Nodes
argument_list|(
name|nodes
argument_list|)
block|,
name|Count
argument_list|(
argument|count
argument_list|)
block|{}
comment|/// Access to the raw pointers.
name|PtrTy
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Nodes
return|;
block|}
comment|/// Access to the count.
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
end_expr_stmt

begin_function
name|PtrTy
modifier|*
name|release
parameter_list|()
block|{
return|return
name|Nodes
return|;
block|}
end_function

begin_decl_stmt
unit|};
name|class
name|ParsedTemplateArgument
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|ASTTemplateArgsPtr
block|{
name|ParsedTemplateArgument
modifier|*
name|Args
decl_stmt|;
name|mutable
name|unsigned
name|Count
decl_stmt|;
name|public
label|:
name|ASTTemplateArgsPtr
argument_list|(
argument|Sema&actions
argument_list|,
argument|ParsedTemplateArgument *args
argument_list|,
argument|unsigned count
argument_list|)
block|:
name|Args
argument_list|(
name|args
argument_list|)
operator|,
name|Count
argument_list|(
argument|count
argument_list|)
block|{ }
comment|// FIXME: Lame, not-fully-type-safe emulation of 'move semantics'.
name|ASTTemplateArgsPtr
argument_list|(
name|ASTTemplateArgsPtr
operator|&
name|Other
argument_list|)
operator|:
name|Args
argument_list|(
name|Other
operator|.
name|Args
argument_list|)
operator|,
name|Count
argument_list|(
argument|Other.Count
argument_list|)
block|{     }
comment|// FIXME: Lame, not-fully-type-safe emulation of 'move semantics'.
name|ASTTemplateArgsPtr
operator|&
name|operator
operator|=
operator|(
name|ASTTemplateArgsPtr
operator|&
name|Other
operator|)
block|{
name|Args
operator|=
name|Other
operator|.
name|Args
block|;
name|Count
operator|=
name|Other
operator|.
name|Count
block|;
return|return
operator|*
name|this
return|;
block|}
name|ParsedTemplateArgument
operator|*
name|getArgs
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Count
return|;
block|}
name|void
name|reset
parameter_list|(
name|ParsedTemplateArgument
modifier|*
name|args
parameter_list|,
name|unsigned
name|count
parameter_list|)
block|{
name|Args
operator|=
name|args
expr_stmt|;
name|Count
operator|=
name|count
expr_stmt|;
block|}
specifier|const
name|ParsedTemplateArgument
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|Arg
argument_list|)
decl|const
decl_stmt|;
name|ParsedTemplateArgument
operator|*
name|release
argument_list|()
specifier|const
block|{
return|return
name|Args
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A small vector that owns a set of AST nodes.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|PtrTy
operator|,
name|unsigned
name|N
operator|=
literal|8
operator|>
name|class
name|ASTOwningVector
operator|:
name|public
name|llvm
operator|::
name|SmallVector
operator|<
name|PtrTy
operator|,
name|N
operator|>
block|{
name|ASTOwningVector
argument_list|(
name|ASTOwningVector
operator|&
argument_list|)
block|;
comment|// do not implement
name|ASTOwningVector
operator|&
name|operator
operator|=
operator|(
name|ASTOwningVector
operator|&
operator|)
block|;
comment|// do not implement
name|public
operator|:
name|explicit
name|ASTOwningVector
argument_list|(
argument|Sema&Actions
argument_list|)
block|{ }
name|PtrTy
operator|*
name|take
argument_list|()
block|{
return|return
operator|&
name|this
operator|->
name|front
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
operator|*
name|takeAs
argument_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|*
operator|>
operator|(
name|take
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// An opaque type for threading parsed type information through the
end_comment

begin_comment
comment|/// parser.
end_comment

begin_typedef
typedef|typedef
name|OpaquePtr
operator|<
name|QualType
operator|>
name|ParsedType
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|UnionOpaquePtr
operator|<
name|QualType
operator|>
name|UnionParsedType
expr_stmt|;
end_typedef

begin_comment
comment|/// A SmallVector of statements, with stack size 32 (as that is the only one
end_comment

begin_comment
comment|/// used.)
end_comment

begin_typedef
typedef|typedef
name|ASTOwningVector
operator|<
name|Stmt
operator|*
operator|,
literal|32
operator|>
name|StmtVector
expr_stmt|;
end_typedef

begin_comment
comment|/// A SmallVector of expressions, with stack size 12 (the maximum used.)
end_comment

begin_typedef
typedef|typedef
name|ASTOwningVector
operator|<
name|Expr
operator|*
operator|,
literal|12
operator|>
name|ExprVector
expr_stmt|;
end_typedef

begin_comment
comment|/// A SmallVector of types.
end_comment

begin_typedef
typedef|typedef
name|ASTOwningVector
operator|<
name|ParsedType
operator|,
literal|12
operator|>
name|TypeVector
expr_stmt|;
end_typedef

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|unsigned
name|N
operator|>
specifier|inline
name|ASTMultiPtr
operator|<
name|T
operator|>
name|move_arg
argument_list|(
argument|ASTOwningVector<T
argument_list|,
argument|N>&vec
argument_list|)
block|{
return|return
name|ASTMultiPtr
operator|<
name|T
operator|>
operator|(
name|vec
operator|.
name|take
argument_list|()
operator|,
name|vec
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// These versions are hopefully no-ops.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
name|bool
name|C
operator|>
specifier|inline
name|ActionResult
operator|<
name|T
operator|,
name|C
operator|>
name|move
argument_list|(
argument|ActionResult<T
argument_list|,
argument|C>&ptr
argument_list|)
block|{
return|return
name|ptr
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|ASTMultiPtr
operator|<
name|T
operator|>
operator|&
name|move
argument_list|(
argument|ASTMultiPtr<T>&ptr
argument_list|)
block|{
return|return
name|ptr
return|;
block|}
end_expr_stmt

begin_comment
comment|// We can re-use the low bit of expression, statement, base, and
end_comment

begin_comment
comment|// member-initializer pointers for the "invalid" flag of
end_comment

begin_comment
comment|// ActionResult.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
name|Expr
operator|*
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
name|Stmt
operator|*
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
name|CXXBaseSpecifier
operator|*
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|IsResultPtrLowBitFree
operator|<
name|CXXCtorInitializer
operator|*
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|;   }
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|Expr
operator|*
operator|>
name|ExprResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|Stmt
operator|*
operator|>
name|StmtResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|ParsedType
operator|>
name|TypeResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|CXXBaseSpecifier
operator|*
operator|>
name|BaseResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|CXXCtorInitializer
operator|*
operator|>
name|MemInitResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ActionResult
operator|<
name|Decl
operator|*
operator|>
name|DeclResult
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|OpaquePtr
operator|<
name|TemplateName
operator|>
name|ParsedTemplateTy
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|Expr
modifier|*
name|move
parameter_list|(
name|Expr
modifier|*
name|E
parameter_list|)
block|{
return|return
name|E
return|;
block|}
end_function

begin_function
specifier|inline
name|Stmt
modifier|*
name|move
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
return|return
name|S
return|;
block|}
end_function

begin_typedef
typedef|typedef
name|ASTMultiPtr
operator|<
name|Expr
operator|*
operator|>
name|MultiExprArg
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ASTMultiPtr
operator|<
name|Stmt
operator|*
operator|>
name|MultiStmtArg
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ASTMultiPtr
operator|<
name|ParsedType
operator|>
name|MultiTypeArg
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ASTMultiPtr
operator|<
name|TemplateParameterList
operator|*
operator|>
name|MultiTemplateParamsArg
expr_stmt|;
end_typedef

begin_function
specifier|inline
name|ExprResult
name|ExprError
parameter_list|()
block|{
return|return
name|ExprResult
argument_list|(
name|true
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|StmtResult
name|StmtError
parameter_list|()
block|{
return|return
name|StmtResult
argument_list|(
name|true
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|ExprResult
name|ExprError
parameter_list|(
specifier|const
name|DiagnosticBuilder
modifier|&
parameter_list|)
block|{
return|return
name|ExprError
argument_list|()
return|;
block|}
end_function

begin_function
specifier|inline
name|StmtResult
name|StmtError
parameter_list|(
specifier|const
name|DiagnosticBuilder
modifier|&
parameter_list|)
block|{
return|return
name|StmtError
argument_list|()
return|;
block|}
end_function

begin_function
specifier|inline
name|ExprResult
name|ExprEmpty
parameter_list|()
block|{
return|return
name|ExprResult
argument_list|(
name|false
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|StmtResult
name|StmtEmpty
parameter_list|()
block|{
return|return
name|StmtResult
argument_list|(
name|false
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|Expr
modifier|*
name|AssertSuccess
parameter_list|(
name|ExprResult
name|R
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|R
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"operation was asserted to never fail!"
argument_list|)
expr_stmt|;
return|return
name|R
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_function
specifier|inline
name|Stmt
modifier|*
name|AssertSuccess
parameter_list|(
name|StmtResult
name|R
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|R
operator|.
name|isInvalid
argument_list|()
operator|&&
literal|"operation was asserted to never fail!"
argument_list|)
expr_stmt|;
return|return
name|R
operator|.
name|get
argument_list|()
return|;
block|}
end_function

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

