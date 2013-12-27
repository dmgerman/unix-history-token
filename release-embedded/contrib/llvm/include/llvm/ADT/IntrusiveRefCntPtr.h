begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/ADT/IntrusiveRefCntPtr.h - Smart Refcounting Pointer ---*- C++ -*-==//
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
comment|// This file defines IntrusiveRefCntPtr, a template class that
end_comment

begin_comment
comment|// implements a "smart" pointer for objects that maintain their own
end_comment

begin_comment
comment|// internal reference count, and RefCountedBase/RefCountedBaseVPTR, two
end_comment

begin_comment
comment|// generic base classes for objects that wish to have their lifetimes
end_comment

begin_comment
comment|// managed using reference counting.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// IntrusiveRefCntPtr is similar to Boost's intrusive_ptr with added
end_comment

begin_comment
comment|// LLVM-style casting.
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
file|"llvm/Support/Casting.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|IntrusiveRefCntPtr
expr_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// RefCountedBase - A generic base class for objects that wish to
comment|///  have their lifetimes managed using reference counts. Classes
comment|///  subclass RefCountedBase to obtain such functionality, and are
comment|///  typically handled with IntrusiveRefCntPtr "smart pointers" (see below)
comment|///  which automatically handle the management of reference counts.
comment|///  Objects that subclass RefCountedBase should not be allocated on
comment|///  the stack, as invoking "delete" (which is called when the
comment|///  reference count hits 0) on such objects is an error.
comment|//===----------------------------------------------------------------------===//
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
name|ref_cnt
block|;
name|public
operator|:
name|RefCountedBase
argument_list|()
operator|:
name|ref_cnt
argument_list|(
literal|0
argument_list|)
block|{}
name|RefCountedBase
argument_list|(
specifier|const
name|RefCountedBase
operator|&
argument_list|)
operator|:
name|ref_cnt
argument_list|(
literal|0
argument_list|)
block|{}
name|void
name|Retain
argument_list|()
specifier|const
block|{
operator|++
name|ref_cnt
block|; }
name|void
name|Release
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ref_cnt
operator|>
literal|0
operator|&&
literal|"Reference count is already zero."
argument_list|)
block|;
if|if
condition|(
operator|--
name|ref_cnt
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
comment|//===----------------------------------------------------------------------===//
comment|/// RefCountedBaseVPTR - A class that has the same function as
comment|///  RefCountedBase, but with a virtual destructor. Should be used
comment|///  instead of RefCountedBase for classes that already have virtual
comment|///  methods to enforce dynamic allocation via 'new'. Classes that
comment|///  inherit from RefCountedBaseVPTR can't be allocated on stack -
comment|///  attempting to do this will produce a compile error.
comment|//===----------------------------------------------------------------------===//
name|class
name|RefCountedBaseVPTR
block|{
name|mutable
name|unsigned
name|ref_cnt
block|;
name|virtual
name|void
name|anchor
argument_list|()
block|;
name|protected
operator|:
name|RefCountedBaseVPTR
argument_list|()
operator|:
name|ref_cnt
argument_list|(
literal|0
argument_list|)
block|{}
name|RefCountedBaseVPTR
argument_list|(
specifier|const
name|RefCountedBaseVPTR
operator|&
argument_list|)
operator|:
name|ref_cnt
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
operator|~
name|RefCountedBaseVPTR
argument_list|()
block|{}
name|void
name|Retain
argument_list|()
specifier|const
block|{
operator|++
name|ref_cnt
block|; }
name|void
name|Release
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|ref_cnt
operator|>
literal|0
operator|&&
literal|"Reference count is already zero."
argument_list|)
block|;
if|if
condition|(
operator|--
name|ref_cnt
operator|==
literal|0
condition|)
name|delete
name|this
decl_stmt|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
name|friend
expr|struct
name|IntrusiveRefCntPtrInfo
block|;   }
block|;
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
comment|//===----------------------------------------------------------------------===//
comment|/// IntrusiveRefCntPtr - A template class that implements a "smart pointer"
comment|///  that assumes the wrapped object has a reference count associated
comment|///  with it that can be managed via calls to
comment|///  IntrusivePtrAddRef/IntrusivePtrRelease.  The smart pointers
comment|///  manage reference counts via the RAII idiom: upon creation of
comment|///  smart pointer the reference count of the wrapped object is
comment|///  incremented and upon destruction of the smart pointer the
comment|///  reference count is decremented.  This class also safely handles
comment|///  wrapping NULL pointers.
comment|///
comment|/// Reference counting is implemented via calls to
comment|///  Obj->Retain()/Obj->Release(). Release() is required to destroy
comment|///  the object when the reference count reaches zero. Inheriting from
comment|///  RefCountedBase/RefCountedBaseVPTR takes care of this
comment|///  automatically.
comment|//===----------------------------------------------------------------------===//
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
block|;
typedef|typedef
name|IntrusiveRefCntPtr
name|this_type
typedef|;
name|public
operator|:
typedef|typedef
name|T
name|element_type
typedef|;
name|explicit
name|IntrusiveRefCntPtr
argument_list|()
operator|:
name|Obj
argument_list|(
literal|0
argument_list|)
block|{}
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
block|;     }
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
block|;     }
if|#
directive|if
name|LLVM_HAS_RVALUE_REFERENCES
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
literal|0
block|;     }
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
argument|S.getPtr()
argument_list|)
block|{
name|S
operator|.
name|Obj
operator|=
literal|0
block|;     }
endif|#
directive|endif
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
argument|S.getPtr()
argument_list|)
block|{
name|retain
argument_list|()
block|;     }
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
operator|~
name|IntrusiveRefCntPtr
argument_list|()
block|{
name|release
argument_list|()
block|; }
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
decl|const
block|{
return|return
name|Obj
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|T
operator|*
name|getPtr
argument_list|()
specifier|const
block|{
return|return
name|Obj
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|T
operator|*
operator|(
name|IntrusiveRefCntPtr
operator|::
operator|*
name|unspecified_bool_type
operator|)
operator|(
operator|)
specifier|const
expr_stmt|;
end_typedef

begin_expr_stmt
name|operator
name|unspecified_bool_type
argument_list|()
specifier|const
block|{
return|return
name|Obj
operator|==
literal|0
operator|?
literal|0
operator|:
operator|&
name|IntrusiveRefCntPtr
operator|::
name|getPtr
return|;
block|}
end_expr_stmt

begin_function
name|void
name|swap
parameter_list|(
name|IntrusiveRefCntPtr
modifier|&
name|other
parameter_list|)
block|{
name|T
modifier|*
name|tmp
init|=
name|other
operator|.
name|Obj
decl_stmt|;
name|other
operator|.
name|Obj
operator|=
name|Obj
expr_stmt|;
name|Obj
operator|=
name|tmp
expr_stmt|;
block|}
end_function

begin_function
name|void
name|reset
parameter_list|()
block|{
name|release
argument_list|()
expr_stmt|;
name|Obj
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|void
name|resetWithoutRelease
parameter_list|()
block|{
name|Obj
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_function
name|void
name|retain
parameter_list|()
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
end_function

begin_function
name|void
name|release
parameter_list|()
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
end_function

begin_expr_stmt
unit|};
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
operator|==
name|B
operator|.
name|getPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
operator|!=
name|B
operator|.
name|getPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
operator|==
name|B
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
operator|!=
name|B
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|,
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
name|getPtr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// LLVM-style downcasting support for IntrusiveRefCntPtr objects
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_expr_stmt
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
operator|>
expr|>
block|{
typedef|typedef
name|T
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|IntrusiveRefCntPtr<T>& Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getPtr
argument_list|()
return|;
block|}
block|}
end_expr_stmt

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
name|simplify_type
operator|<
specifier|const
name|IntrusiveRefCntPtr
operator|<
name|T
operator|>
expr|>
block|{
typedef|typedef
comment|/*const*/
name|T
modifier|*
name|SimpleType
typedef|;
specifier|static
name|SimpleType
name|getSimplifiedValue
argument_list|(
argument|const IntrusiveRefCntPtr<T>& Val
argument_list|)
block|{
return|return
name|Val
operator|.
name|getPtr
argument_list|()
return|;
block|}
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
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

