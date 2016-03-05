begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TrailingObjects.h - Variable-length classes ------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// This header defines support for implementing classes that have
end_comment

begin_comment
comment|/// some trailing object (or arrays of objects) appended to them. The
end_comment

begin_comment
comment|/// main purpose is to make it obvious where this idiom is being used,
end_comment

begin_comment
comment|/// and to make the usage more idiomatic and more difficult to get
end_comment

begin_comment
comment|/// wrong.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The TrailingObject template abstracts away the reinterpret_cast,
end_comment

begin_comment
comment|/// pointer arithmetic, and size calculations used for the allocation
end_comment

begin_comment
comment|/// and access of appended arrays of objects, and takes care that they
end_comment

begin_comment
comment|/// are all allocated at their required alignment. Additionally, it
end_comment

begin_comment
comment|/// ensures that the base type is final -- deriving from a class that
end_comment

begin_comment
comment|/// expects data appended immediately after it is typically not safe.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Users are expected to derive from this template, and provide
end_comment

begin_comment
comment|/// numTrailingObjects implementations for each trailing type except
end_comment

begin_comment
comment|/// the last, e.g. like this sample:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// class VarLengthObj : private TrailingObjects<VarLengthObj, int, double> {
end_comment

begin_comment
comment|///   friend TrailingObjects;
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   unsigned NumInts, NumDoubles;
end_comment

begin_comment
comment|///   size_t numTrailingObjects(OverloadToken<int>) const { return NumInts; }
end_comment

begin_comment
comment|///  };
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// You can access the appended arrays via 'getTrailingObjects', and
end_comment

begin_comment
comment|/// determine the size needed for allocation via
end_comment

begin_comment
comment|/// 'additionalSizeToAlloc' and 'totalSizeToAlloc'.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// All the methods implemented by this class are are intended for use
end_comment

begin_comment
comment|/// by the implementation of the class, not as part of its interface
end_comment

begin_comment
comment|/// (thus, private inheritance is suggested).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_TRAILINGOBJECTS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_TRAILINGOBJECTS_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MathExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_include
include|#
directive|include
file|<new>
end_include

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|trailing_objects_internal
block|{
comment|/// Helper template to calculate the max alignment requirement for a set of
comment|/// objects.
name|template
operator|<
name|typename
name|First
operator|,
name|typename
operator|...
name|Rest
operator|>
name|class
name|AlignmentCalcHelper
block|{
name|private
operator|:
expr|enum
block|{
name|FirstAlignment
operator|=
name|AlignOf
operator|<
name|First
operator|>
operator|::
name|Alignment
block|,
name|RestAlignment
operator|=
name|AlignmentCalcHelper
operator|<
name|Rest
operator|...
operator|>
operator|::
name|Alignment
block|,   }
block|;
name|public
operator|:
expr|enum
block|{
name|Alignment
operator|=
name|FirstAlignment
operator|>
name|RestAlignment
operator|?
name|FirstAlignment
operator|:
name|RestAlignment
block|}
block|; }
expr_stmt|;
name|template
operator|<
name|typename
name|First
operator|>
name|class
name|AlignmentCalcHelper
operator|<
name|First
operator|>
block|{
name|public
operator|:
expr|enum
block|{
name|Alignment
operator|=
name|AlignOf
operator|<
name|First
operator|>
operator|::
name|Alignment
block|}
block|; }
expr_stmt|;
comment|/// The base class for TrailingObjects* classes.
name|class
name|TrailingObjectsBase
block|{
name|protected
label|:
comment|/// OverloadToken's purpose is to allow specifying function overloads
comment|/// for different types, without actually taking the types as
comment|/// parameters. (Necessary because member function templates cannot
comment|/// be specialized, so overloads must be used instead of
comment|/// specialization.)
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|OverloadToken
block|{}
expr_stmt|;
block|}
empty_stmt|;
comment|/// This helper template works-around MSVC 2013's lack of useful
comment|/// alignas() support. The argument to LLVM_ALIGNAS(), in MSVC, is
comment|/// required to be a literal integer. But, you *can* use template
comment|/// specialization to select between a bunch of different LLVM_ALIGNAS
comment|/// expressions...
name|template
operator|<
name|int
name|Align
operator|>
name|class
name|TrailingObjectsAligner
operator|:
name|public
name|TrailingObjectsBase
block|{}
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|1
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|1
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{}
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|2
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|2
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{}
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|4
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|4
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{}
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|8
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|8
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{}
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|16
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|16
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{ }
expr_stmt|;
name|template
operator|<
operator|>
name|class
name|LLVM_ALIGNAS
argument_list|(
literal|32
argument_list|)
name|TrailingObjectsAligner
operator|<
literal|32
operator|>
operator|:
name|public
name|TrailingObjectsBase
block|{ }
expr_stmt|;
comment|// Just a little helper for transforming a type pack into the same
comment|// number of a different type. e.g.:
comment|//   ExtractSecondType<Foo..., int>::type
name|template
operator|<
name|typename
name|Ty1
operator|,
name|typename
name|Ty2
operator|>
expr|struct
name|ExtractSecondType
block|{
typedef|typedef
name|Ty2
name|type
typedef|;
block|}
empty_stmt|;
comment|// TrailingObjectsImpl is somewhat complicated, because it is a
comment|// recursively inheriting template, in order to handle the template
comment|// varargs. Each level of inheritance picks off a single trailing type
comment|// then recurses on the rest. The "Align", "BaseTy", and
comment|// "TopTrailingObj" arguments are passed through unchanged through the
comment|// recursion. "PrevTy" is, at each level, the type handled by the
comment|// level right above it.
name|template
operator|<
name|int
name|Align
operator|,
name|typename
name|BaseTy
operator|,
name|typename
name|TopTrailingObj
operator|,
name|typename
name|PrevTy
operator|,
name|typename
operator|...
name|MoreTys
operator|>
expr|struct
name|TrailingObjectsImpl
block|{
comment|// The main template definition is never used -- the two
comment|// specializations cover all possibilities.
block|}
expr_stmt|;
name|template
operator|<
name|int
name|Align
operator|,
name|typename
name|BaseTy
operator|,
name|typename
name|TopTrailingObj
operator|,
name|typename
name|PrevTy
operator|,
name|typename
name|NextTy
operator|,
name|typename
operator|...
name|MoreTys
operator|>
expr|struct
name|TrailingObjectsImpl
operator|<
name|Align
operator|,
name|BaseTy
operator|,
name|TopTrailingObj
operator|,
name|PrevTy
operator|,
name|NextTy
operator|,
name|MoreTys
operator|...
operator|>
operator|:
name|public
name|TrailingObjectsImpl
operator|<
name|Align
operator|,
name|BaseTy
operator|,
name|TopTrailingObj
operator|,
name|NextTy
operator|,
name|MoreTys
operator|...
operator|>
block|{
typedef|typedef
name|TrailingObjectsImpl
operator|<
name|Align
operator|,
name|BaseTy
operator|,
name|TopTrailingObj
operator|,
name|NextTy
operator|,
name|MoreTys
operator|...
operator|>
name|ParentType
expr_stmt|;
comment|// Ensure the methods we inherit are not hidden.
name|using
name|ParentType
operator|::
name|getTrailingObjectsImpl
expr_stmt|;
name|using
name|ParentType
operator|::
name|additionalSizeToAllocImpl
expr_stmt|;
specifier|static
name|LLVM_CONSTEXPR
name|bool
name|requiresRealignment
parameter_list|()
block|{
return|return
name|llvm
operator|::
name|AlignOf
operator|<
name|PrevTy
operator|>
operator|::
name|Alignment
operator|<
name|llvm
operator|::
name|AlignOf
operator|<
name|NextTy
operator|>
operator|::
name|Alignment
return|;
block|}
comment|// These two functions are helper functions for
comment|// TrailingObjects::getTrailingObjects. They recurse to the left --
comment|// the result for each type in the list of trailing types depends on
comment|// the result of calling the function on the type to the
comment|// left. However, the function for the type to the left is
comment|// implemented by a *subclass* of this class, so we invoke it via
comment|// the TopTrailingObj, which is, via the
comment|// curiously-recurring-template-pattern, the most-derived type in
comment|// this recursion, and thus, contains all the overloads.
specifier|static
specifier|const
name|NextTy
modifier|*
name|getTrailingObjectsImpl
argument_list|(
specifier|const
name|BaseTy
operator|*
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|NextTy
operator|>
argument_list|)
block|{
name|auto
operator|*
name|Ptr
operator|=
name|TopTrailingObj
operator|::
name|getTrailingObjectsImpl
argument_list|(
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|PrevTy
operator|>
operator|(
operator|)
argument_list|)
operator|+
name|TopTrailingObj
operator|::
name|callNumTrailingObjects
argument_list|(
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|PrevTy
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|requiresRealignment
argument_list|()
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|NextTy
operator|*
operator|>
operator|(
name|llvm
operator|::
name|alignAddr
argument_list|(
name|Ptr
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|NextTy
operator|>
operator|(
operator|)
argument_list|)
operator|)
return|;
else|else
return|return
name|reinterpret_cast
operator|<
specifier|const
name|NextTy
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
specifier|static
name|NextTy
modifier|*
name|getTrailingObjectsImpl
argument_list|(
name|BaseTy
operator|*
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|NextTy
operator|>
argument_list|)
block|{
name|auto
operator|*
name|Ptr
operator|=
name|TopTrailingObj
operator|::
name|getTrailingObjectsImpl
argument_list|(
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|PrevTy
operator|>
operator|(
operator|)
argument_list|)
operator|+
name|TopTrailingObj
operator|::
name|callNumTrailingObjects
argument_list|(
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|PrevTy
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|requiresRealignment
argument_list|()
condition|)
return|return
name|reinterpret_cast
operator|<
name|NextTy
operator|*
operator|>
operator|(
name|llvm
operator|::
name|alignAddr
argument_list|(
name|Ptr
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|NextTy
operator|>
operator|(
operator|)
argument_list|)
operator|)
return|;
else|else
return|return
name|reinterpret_cast
operator|<
name|NextTy
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
comment|// Helper function for TrailingObjects::additionalSizeToAlloc: this
comment|// function recurses to superclasses, each of which requires one
comment|// fewer size_t argument, and adds its own size.
specifier|static
name|LLVM_CONSTEXPR
name|size_t
name|additionalSizeToAllocImpl
argument_list|(
name|size_t
name|SizeSoFar
argument_list|,
name|size_t
name|Count1
argument_list|,
name|typename
name|ExtractSecondType
operator|<
name|MoreTys
argument_list|,
name|size_t
operator|>
operator|::
name|type
operator|...
name|MoreCounts
argument_list|)
block|{
return|return
name|additionalSizeToAllocImpl
argument_list|(
operator|(
name|requiresRealignment
argument_list|()
condition|?
name|llvm
operator|::
name|RoundUpToAlignment
argument_list|(
name|SizeSoFar
argument_list|,
name|llvm
operator|::
name|alignOf
operator|<
name|NextTy
operator|>
operator|(
operator|)
argument_list|)
else|:
name|SizeSoFar
operator|)
operator|+
sizeof|sizeof
argument_list|(
name|NextTy
argument_list|)
operator|*
name|Count1
argument_list|,
name|MoreCounts
operator|...
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|// The base case of the TrailingObjectsImpl inheritance recursion,
comment|// when there's no more trailing types.
name|template
operator|<
name|int
name|Align
operator|,
name|typename
name|BaseTy
operator|,
name|typename
name|TopTrailingObj
operator|,
name|typename
name|PrevTy
operator|>
expr|struct
name|TrailingObjectsImpl
operator|<
name|Align
operator|,
name|BaseTy
operator|,
name|TopTrailingObj
operator|,
name|PrevTy
operator|>
operator|:
name|public
name|TrailingObjectsAligner
operator|<
name|Align
operator|>
block|{
comment|// This is a dummy method, only here so the "using" doesn't fail --
comment|// it will never be called, because this function recurses backwards
comment|// up the inheritance chain to subclasses.
specifier|static
name|void
name|getTrailingObjectsImpl
argument_list|()
block|;
specifier|static
name|LLVM_CONSTEXPR
name|size_t
name|additionalSizeToAllocImpl
argument_list|(
argument|size_t SizeSoFar
argument_list|)
block|{
return|return
name|SizeSoFar
return|;
block|}
name|template
operator|<
name|bool
name|CheckAlignment
operator|>
specifier|static
name|void
name|verifyTrailingObjectsAlignment
argument_list|()
block|{}
expr|}
block|;  }
comment|// end namespace trailing_objects_internal
comment|// Finally, the main type defined in this file, the one intended for users...
comment|/// See the file comment for details on the usage of the
comment|/// TrailingObjects type.
name|template
operator|<
name|typename
name|BaseTy
operator|,
name|typename
operator|...
name|TrailingTys
operator|>
name|class
name|TrailingObjects
operator|:
name|private
name|trailing_objects_internal
operator|::
name|TrailingObjectsImpl
operator|<
name|trailing_objects_internal
operator|::
name|AlignmentCalcHelper
operator|<
name|TrailingTys
operator|...
operator|>
operator|::
name|Alignment
operator|,
name|BaseTy
operator|,
name|TrailingObjects
operator|<
name|BaseTy
operator|,
name|TrailingTys
operator|...
operator|>
operator|,
name|BaseTy
operator|,
name|TrailingTys
operator|...
operator|>
block|{
name|template
operator|<
name|int
name|A
block|,
name|typename
name|B
block|,
name|typename
name|T
block|,
name|typename
name|P
block|,
name|typename
operator|...
name|M
operator|>
name|friend
expr|struct
name|trailing_objects_internal
operator|::
name|TrailingObjectsImpl
block|;
name|template
operator|<
name|typename
operator|...
name|Tys
operator|>
name|class
name|Foo
block|{}
block|;
typedef|typedef
name|trailing_objects_internal
operator|::
name|TrailingObjectsImpl
operator|<
name|trailing_objects_internal
operator|::
name|AlignmentCalcHelper
operator|<
name|TrailingTys
operator|...
operator|>
operator|::
name|Alignment
operator|,
name|BaseTy
operator|,
name|TrailingObjects
operator|<
name|BaseTy
operator|,
name|TrailingTys
operator|...
operator|>
operator|,
name|BaseTy
operator|,
name|TrailingTys
operator|...
operator|>
name|ParentType
expr_stmt|;
name|using
name|TrailingObjectsBase
operator|=
name|trailing_objects_internal
operator|::
name|TrailingObjectsBase
expr_stmt|;
name|using
name|ParentType
operator|::
name|getTrailingObjectsImpl
expr_stmt|;
comment|// This function contains only a static_assert BaseTy is final. The
comment|// static_assert must be in a function, and not at class-level
comment|// because BaseTy isn't complete at class instantiation time, but
comment|// will be by the time this function is instantiated.
specifier|static
name|void
name|verifyTrailingObjectsAssertions
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|LLVM_IS_FINAL
name|static_assert
argument_list|(
name|LLVM_IS_FINAL
argument_list|(
name|BaseTy
argument_list|)
argument_list|,
literal|"BaseTy must be final."
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|// These two methods are the base of the recursion for this method.
specifier|static
specifier|const
name|BaseTy
modifier|*
name|getTrailingObjectsImpl
argument_list|(
specifier|const
name|BaseTy
operator|*
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|BaseTy
operator|>
argument_list|)
block|{
return|return
name|Obj
return|;
block|}
specifier|static
name|BaseTy
modifier|*
name|getTrailingObjectsImpl
argument_list|(
name|BaseTy
operator|*
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|BaseTy
operator|>
argument_list|)
block|{
return|return
name|Obj
return|;
block|}
comment|// callNumTrailingObjects simply calls numTrailingObjects on the
comment|// provided Obj -- except when the type being queried is BaseTy
comment|// itself. There is always only one of the base object, so that case
comment|// is handled here. (An additional benefit of indirecting through
comment|// this function is that consumers only say "friend
comment|// TrailingObjects", and thus, only this class itself can call the
comment|// numTrailingObjects function.)
specifier|static
name|size_t
name|callNumTrailingObjects
argument_list|(
specifier|const
name|BaseTy
operator|*
name|Obj
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|BaseTy
operator|>
argument_list|)
block|{
return|return
literal|1
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|size_t
name|callNumTrailingObjects
argument_list|(
argument|const BaseTy *Obj
argument_list|,
argument|TrailingObjectsBase::OverloadToken<T>
argument_list|)
block|{
return|return
name|Obj
operator|->
name|numTrailingObjects
argument_list|(
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
name|public
label|:
comment|// make this (privately inherited) class public.
name|using
name|ParentType
operator|::
name|OverloadToken
expr_stmt|;
comment|/// Returns a pointer to the trailing object array of the given type
comment|/// (which must be one of those specified in the class template). The
comment|/// array may have zero or more elements in it.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|getTrailingObjects
argument_list|()
specifier|const
block|{
name|verifyTrailingObjectsAssertions
argument_list|()
block|;
comment|// Forwards to an impl function with overloads, since member
comment|// function templates can't be specialized.
return|return
name|this
operator|->
name|getTrailingObjectsImpl
argument_list|(
name|static_cast
operator|<
specifier|const
name|BaseTy
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
comment|/// Returns a pointer to the trailing object array of the given type
comment|/// (which must be one of those specified in the class template). The
comment|/// array may have zero or more elements in it.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|getTrailingObjects
argument_list|()
block|{
name|verifyTrailingObjectsAssertions
argument_list|()
block|;
comment|// Forwards to an impl function with overloads, since member
comment|// function templates can't be specialized.
return|return
name|this
operator|->
name|getTrailingObjectsImpl
argument_list|(
name|static_cast
operator|<
name|BaseTy
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|,
name|TrailingObjectsBase
operator|::
name|OverloadToken
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
return|;
block|}
comment|/// Returns the size of the trailing data, if an object were
comment|/// allocated with the given counts (The counts are in the same order
comment|/// as the template arguments). This does not include the size of the
comment|/// base object.  The template arguments must be the same as those
comment|/// used in the class; they are supplied here redundantly only so
comment|/// that it's clear what the counts are counting in callers.
name|template
operator|<
name|typename
operator|...
name|Tys
operator|>
specifier|static
name|LLVM_CONSTEXPR
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|Foo
operator|<
name|TrailingTys
operator|...
operator|>
operator|,
name|Foo
operator|<
name|Tys
operator|...
operator|>>
operator|::
name|value
operator|,
name|size_t
operator|>
operator|::
name|type
name|additionalSizeToAlloc
argument_list|(
argument|typename trailing_objects_internal::ExtractSecondType<               TrailingTys
argument_list|,
argument|size_t>::type... Counts
argument_list|)
block|{
return|return
name|ParentType
operator|::
name|additionalSizeToAllocImpl
argument_list|(
literal|0
argument_list|,
name|Counts
operator|...
argument_list|)
return|;
block|}
comment|/// Returns the total size of an object if it were allocated with the
comment|/// given trailing object counts. This is the same as
comment|/// additionalSizeToAlloc, except it *does* include the size of the base
comment|/// object.
name|template
operator|<
name|typename
operator|...
name|Tys
operator|>
specifier|static
name|LLVM_CONSTEXPR
name|typename
name|std
operator|::
name|enable_if
operator|<
name|std
operator|::
name|is_same
operator|<
name|Foo
operator|<
name|TrailingTys
operator|...
operator|>
operator|,
name|Foo
operator|<
name|Tys
operator|...
operator|>>
operator|::
name|value
operator|,
name|size_t
operator|>
operator|::
name|type
name|totalSizeToAlloc
argument_list|(
argument|typename trailing_objects_internal::ExtractSecondType<                        TrailingTys
argument_list|,
argument|size_t>::type... Counts
argument_list|)
block|{
return|return
sizeof|sizeof
argument_list|(
name|BaseTy
argument_list|)
operator|+
name|ParentType
operator|::
name|additionalSizeToAllocImpl
argument_list|(
literal|0
argument_list|,
name|Counts
operator|...
argument_list|)
return|;
block|}
block|}
end_decl_stmt

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

end_unit

