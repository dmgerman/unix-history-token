begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- llvm/ADT/IntrusiveRefCntPtr.h - Smart Refcounting Pointer --*- C++ -*-==//
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
comment|// This file defines the RefCountedBase, ThreadSafeRefCountedBase, and
end_comment

begin_comment
comment|// IntrusiveRefCntPtr classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IntrusiveRefCntPtr is a smart pointer to an object which maintains a
end_comment

begin_comment
comment|// reference count.  (ThreadSafe)RefCountedBase is a mixin class that adds a
end_comment

begin_comment
comment|// refcount member variable and methods for updating the refcount.  An object
end_comment

begin_comment
comment|// that inherits from (ThreadSafe)RefCountedBase deletes itself when its
end_comment

begin_comment
comment|// refcount hits zero.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// For example:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   class MyClass : public RefCountedBase<MyClass> {};
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   void foo() {
end_comment

begin_comment
comment|//     // Constructing an IntrusiveRefCntPtr increases the pointee's refcount by
end_comment

begin_comment
comment|//     // 1 (from 0 in this case).
end_comment

begin_comment
comment|//     IntrusiveRefCntPtr<MyClass> Ptr1(new MyClass());
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     // Copying an IntrusiveRefCntPtr increases the pointee's refcount by 1.
end_comment

begin_comment
comment|//     IntrusiveRefCntPtr<MyClass> Ptr2(Ptr1);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     // Constructing an IntrusiveRefCntPtr has no effect on the object's
end_comment

begin_comment
comment|//     // refcount.  After a move, the moved-from pointer is null.
end_comment

begin_comment
comment|//     IntrusiveRefCntPtr<MyClass> Ptr3(std::move(Ptr1));
end_comment

begin_comment
comment|//     assert(Ptr1 == nullptr);
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     // Clearing an IntrusiveRefCntPtr decreases the pointee's refcount by 1.
end_comment

begin_comment
comment|//     Ptr2.reset();
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     // The object deletes itself when we return from the function, because
end_comment

begin_comment
comment|//     // Ptr3's destructor decrements its refcount to 0.
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// You can use IntrusiveRefCntPtr with isa<T>(), dyn_cast<T>(), etc.:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   IntrusiveRefCntPtr<MyClass> Ptr(new MyClass());
end_comment

begin_comment
comment|//   OtherClass *Other = dyn_cast<OtherClass>(Ptr);  // Ptr.get() not required
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IntrusiveRefCntPtr works with any class that
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  - inherits from (ThreadSafe)RefCountedBase,
end_comment

begin_comment
comment|//  - has Retain() and Release() methods, or
end_comment

begin_comment
comment|//  - specializes IntrusiveRefCntPtrInfo.
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
name|LLVM_ADT_INTRUSIVEREFCNTPTR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_INTRUSIVEREFCNTPTR_H
end_define

begin_include
include|#
directive|include
file|<atomic>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A CRTP mixin class that adds reference counting to a type.
comment|///
comment|/// The lifetime of an object which inherits from RefCountedBase is managed by
comment|/// calls to Release() and Retain(), which increment and decrement the object's
comment|/// refcount, respectively.  When a Release() call decrements the refcount to 0,
comment|/// the object deletes itself.
name|template
operator|<
name|class
name|Derived
operator|>
name|class
name|RefCountedBase
block|{
name|mutable
name|unsigned
name|RefCount
operator|=
literal|0
block|;
name|public
operator|:
name|RefCountedBase
argument_list|()
operator|=
expr|default
block|;
name|RefCountedBase
argument_list|(
argument|const RefCountedBase&
argument_list|)
block|{}
name|void
name|Retain
argument_list|()
specifier|const
block|{
operator|++
name|RefCount
block|; }
name|void
name|Release
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RefCount
operator|>
literal|0
operator|&&
literal|"Reference count is already zero."
argument_list|)
block|;
if|if
condition|(
operator|--
name|RefCount
operator|==
literal|0
condition|)
name|delete
name|static_cast
operator|<
specifier|const
name|Derived
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
block|}
expr|}
block|;
comment|/// A thread-safe version of \c RefCountedBase.
name|template
operator|<
name|class
name|Derived
operator|>
name|class
name|ThreadSafeRefCountedBase
block|{
name|mutable
name|std
operator|::
name|atomic
operator|<
name|int
operator|>
name|RefCount
block|;
name|protected
operator|:
name|ThreadSafeRefCountedBase
argument_list|()
operator|:
name|RefCount
argument_list|(
literal|0
argument_list|)
block|{}
name|public
operator|:
name|void
name|Retain
argument_list|()
specifier|const
block|{
name|RefCount
operator|.
name|fetch_add
argument_list|(
literal|1
argument_list|,
name|std
operator|::
name|memory_order_relaxed
argument_list|)
block|; }
name|void
name|Release
argument_list|()
specifier|const
block|{
name|int
name|NewRefCount
operator|=
name|RefCount
operator|.
name|fetch_sub
argument_list|(
literal|1
argument_list|,
name|std
operator|::
name|memory_order_acq_rel
argument_list|)
operator|-
literal|1
block|;
name|assert
argument_list|(
name|NewRefCount
operator|>=
literal|0
operator|&&
literal|"Reference count was already zero."
argument_list|)
block|;
if|if
condition|(
name|NewRefCount
operator|==
literal|0
condition|)
name|delete
name|static_cast
operator|<
specifier|const
name|Derived
operator|*
operator|>
operator|(
name|this
operator|)
expr_stmt|;
block|}
expr|}
block|;
comment|/// Class you can specialize to provide custom retain/release functionality for
comment|/// a type.
comment|///
comment|/// Usually specializing this class is not necessary, as IntrusiveRefCntPtr
comment|/// works with any type which defines Retain() and Release() functions -- you
comment|/// can define those functions yourself if RefCountedBase doesn't work for you.
comment|///
comment|/// One case when you might want to specialize this type is if you have
comment|///  - Foo.h defines type Foo and includes Bar.h, and
comment|///  - Bar.h uses IntrusiveRefCntPtr<Foo> in inline functions.
comment|///
comment|/// Because Foo.h includes Bar.h, Bar.h can't include Foo.h in order to pull in
comment|/// the declaration of Foo.  Without the declaration of Foo, normally Bar.h
comment|/// wouldn't be able to use IntrusiveRefCntPtr<Foo>, which wants to call
comment|/// T::Retain and T::Release.
comment|///
comment|/// To resolve this, Bar.h could include a third header, FooFwd.h, which
comment|/// forward-declares Foo and specializes IntrusiveRefCntPtrInfo<Foo>.  Then
comment|/// Bar.h could use IntrusiveRefCntPtr<Foo>, although it still couldn't call any
comment|/// functions on Foo itself, because Foo would be an incomplete type.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|IntrusiveRefCntPtrInfo
block|{
specifier|static
name|void
name|retain
argument_list|(
argument|T *obj
argument_list|)
block|{
name|obj
operator|->
name|Retain
argument_list|()
block|; }
specifier|static
name|void
name|release
argument_list|(
argument|T *obj
argument_list|)
block|{
name|obj
operator|->
name|Release
argument_list|()
block|; }
block|}
block|;
comment|/// A smart pointer to a reference-counted object that inherits from
comment|/// RefCountedBase or ThreadSafeRefCountedBase.
comment|///
comment|/// This class increments its pointee's reference count when it is created, and
comment|/// decrements its refcount when it's destroyed (or is changed to point to a
comment|/// different object).
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|IntrusiveRefCntPtr
block|{
name|T
operator|*
name|Obj
operator|=
name|nullptr
block|;
name|public
operator|:
name|using
name|element_type
operator|=
name|T
block|;
name|explicit
name|IntrusiveRefCntPtr
argument_list|()
operator|=
expr|default
block|;
name|IntrusiveRefCntPtr
argument_list|(
name|T
operator|*
name|obj
argument_list|)
operator|:
name|Obj
argument_list|(
argument|obj
argument_list|)
block|{
name|retain
argument_list|()
block|; }
name|IntrusiveRefCntPtr
argument_list|(
specifier|const
name|IntrusiveRefCntPtr
operator|&
name|S
argument_list|)
operator|:
name|Obj
argument_list|(
argument|S.Obj
argument_list|)
block|{
name|retain
argument_list|()
block|; }
name|IntrusiveRefCntPtr
argument_list|(
name|IntrusiveRefCntPtr
operator|&&
name|S
argument_list|)
operator|:
name|Obj
argument_list|(
argument|S.Obj
argument_list|)
block|{
name|S
operator|.
name|Obj
operator|=
name|nullptr
block|; }
name|template
operator|<
name|class
name|X
operator|>
name|IntrusiveRefCntPtr
argument_list|(
name|IntrusiveRefCntPtr
operator|<
name|X
operator|>
operator|&&
name|S
argument_list|)
operator|:
name|Obj
argument_list|(
argument|S.get()
argument_list|)
block|{
name|S
operator|.
name|Obj
operator|=
name|nullptr
block|;   }
name|template
operator|<
name|class
name|X
operator|>
name|IntrusiveRefCntPtr
argument_list|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|X
operator|>
operator|&
name|S
argument_list|)
operator|:
name|Obj
argument_list|(
argument|S.get()
argument_list|)
block|{
name|retain
argument_list|()
block|;   }
operator|~
name|IntrusiveRefCntPtr
argument_list|()
block|{
name|release
argument_list|()
block|; }
name|IntrusiveRefCntPtr
operator|&
name|operator
operator|=
operator|(
name|IntrusiveRefCntPtr
name|S
operator|)
block|{
name|swap
argument_list|(
name|S
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|Obj
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
block|)
specifier|const
block|{
return|return
name|Obj
return|;
block|}
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|Obj
return|;
block|}
name|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Obj
return|;
block|}
name|void
name|swap
argument_list|(
argument|IntrusiveRefCntPtr&other
argument_list|)
block|{
name|T
operator|*
name|tmp
operator|=
name|other
operator|.
name|Obj
block|;
name|other
operator|.
name|Obj
operator|=
name|Obj
block|;
name|Obj
operator|=
name|tmp
block|;   }
name|void
name|reset
argument_list|()
block|{
name|release
argument_list|()
block|;
name|Obj
operator|=
name|nullptr
block|;   }
name|void
name|resetWithoutRelease
argument_list|()
block|{
name|Obj
operator|=
name|nullptr
block|; }
name|private
operator|:
name|void
name|retain
argument_list|()
block|{
if|if
condition|(
name|Obj
condition|)
name|IntrusiveRefCntPtrInfo
operator|<
name|T
operator|>
operator|::
name|retain
argument_list|(
name|Obj
argument_list|)
expr_stmt|;
block|}
name|void
name|release
argument_list|()
block|{
if|if
condition|(
name|Obj
condition|)
name|IntrusiveRefCntPtrInfo
operator|<
name|T
operator|>
operator|::
name|release
argument_list|(
name|Obj
argument_list|)
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|X
operator|>
name|friend
name|class
name|IntrusiveRefCntPtr
block|; }
block|;
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|U
operator|>
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|get
argument_list|()
operator|==
name|B
operator|.
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|U
operator|>
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|get
argument_list|()
operator|!=
name|B
operator|.
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
name|U
operator|*
name|B
operator|)
block|{
return|return
name|A
operator|.
name|get
argument_list|()
operator|==
name|B
return|;
block|}
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
name|U
operator|*
name|B
operator|)
block|{
return|return
name|A
operator|.
name|get
argument_list|()
operator|!=
name|B
return|;
block|}
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|U
operator|>
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|==
name|B
operator|.
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|T
block|,
name|class
name|U
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|U
operator|>
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|!=
name|B
operator|.
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
name|std
operator|::
name|nullptr_t
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|B
operator|)
block|{
return|return
operator|!
name|B
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|==
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
name|std
operator|::
name|nullptr_t
name|B
operator|)
block|{
return|return
name|B
operator|==
name|A
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
name|std
operator|::
name|nullptr_t
name|A
operator|,
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|B
operator|)
block|{
return|return
operator|!
operator|(
name|A
operator|==
name|B
operator|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
operator|&
name|A
operator|,
name|std
operator|::
name|nullptr_t
name|B
operator|)
block|{
return|return
operator|!
operator|(
name|A
operator|==
name|B
operator|)
return|;
block|}
comment|// Make IntrusiveRefCntPtr work with dyn_cast, isa, and the other idioms from
comment|// Casting.h.
name|template
operator|<
name|typename
name|From
operator|>
expr|struct
name|simplify_type
block|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|simplify_type
operator|<
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>>
block|{
name|using
name|SimpleType
operator|=
name|T
operator|*
block|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|IntrusiveRefCntPtr<T>&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|get
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|class
name|T
operator|>
expr|struct
name|simplify_type
operator|<
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>>
block|{
name|using
name|SimpleType
operator|=
comment|/*const*/
name|T
operator|*
block|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const IntrusiveRefCntPtr<T>&Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|get
argument_list|()
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ADT_INTRUSIVEREFCNTPTR_H
end_comment

end_unit

