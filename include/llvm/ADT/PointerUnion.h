begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/ADT/PointerUnion.h - Discriminated Union of 2 Ptrs --*- C++ -*-===//
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
comment|// This file defines the PointerUnion class, which is a discriminated union of
end_comment

begin_comment
comment|// pointer types.
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
name|LLVM_ADT_POINTERUNION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ADT_POINTERUNION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// getPointerUnionTypeNum - If the argument has type PT1* or PT2* return
comment|/// false or true respectively.
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
specifier|static
specifier|inline
name|int
name|getPointerUnionTypeNum
argument_list|(
argument|PT1 *P
argument_list|)
block|{
return|return
literal|0
return|;
block|}
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
specifier|static
specifier|inline
name|int
name|getPointerUnionTypeNum
argument_list|(
argument|PT2 *P
argument_list|)
block|{
return|return
literal|1
return|;
block|}
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
specifier|static
specifier|inline
name|int
name|getPointerUnionTypeNum
argument_list|(
argument|...
argument_list|)
block|{
return|return
operator|-
literal|1
return|;
block|}
comment|/// Provide PointerLikeTypeTraits for void* that is used by PointerUnion
comment|/// for the two template arguments.
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
name|class
name|PointerUnionUIntTraits
block|{
name|public
operator|:
specifier|static
specifier|inline
name|void
operator|*
name|getAsVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
specifier|static
specifier|inline
name|void
operator|*
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|P
return|;
block|}
expr|enum
block|{
name|PT1BitsAv
operator|=
name|PointerLikeTypeTraits
operator|<
name|PT1
operator|>
operator|::
name|NumLowBitsAvailable
block|,
name|PT2BitsAv
operator|=
name|PointerLikeTypeTraits
operator|<
name|PT2
operator|>
operator|::
name|NumLowBitsAvailable
block|,
name|NumLowBitsAvailable
operator|=
name|PT1BitsAv
operator|<
name|PT2BitsAv
operator|?
name|PT1BitsAv
operator|:
name|PT2BitsAv
block|}
block|;   }
expr_stmt|;
comment|/// PointerUnion - This implements a discriminated union of two pointer types,
comment|/// and keeps the discriminator bit-mangled into the low bits of the pointer.
comment|/// This allows the implementation to be extremely efficient in space, but
comment|/// permits a very natural and type-safe API.
comment|///
comment|/// Common use patterns would be something like this:
comment|///    PointerUnion<int*, float*> P;
comment|///    P = (int*)0;
comment|///    printf("%d %d", P.is<int*>(), P.is<float*>());  // prints "1 0"
comment|///    X = P.get<int*>();     // ok.
comment|///    Y = P.get<float*>();   // runtime assertion failure.
comment|///    Z = P.get<double*>();  // runtime assertion failure (regardless of tag)
comment|///    P = (float*)0;
comment|///    Y = P.get<float*>();   // ok.
comment|///    X = P.get<int*>();     // runtime assertion failure.
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
name|class
name|PointerUnion
block|{
name|public
operator|:
typedef|typedef
name|PointerIntPair
operator|<
name|void
operator|*
operator|,
literal|1
operator|,
name|bool
operator|,
name|PointerUnionUIntTraits
operator|<
name|PT1
operator|,
name|PT2
operator|>
expr|>
name|ValTy
expr_stmt|;
name|private
operator|:
name|ValTy
name|Val
expr_stmt|;
name|public
label|:
name|PointerUnion
argument_list|()
block|{}
name|PointerUnion
argument_list|(
argument|PT1 V
argument_list|)
block|{
name|Val
operator|.
name|setPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|PointerLikeTypeTraits
operator|<
name|PT1
operator|>
operator|::
name|getAsVoidPointer
argument_list|(
name|V
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|Val
operator|.
name|setInt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
name|PointerUnion
argument_list|(
argument|PT2 V
argument_list|)
block|{
name|Val
operator|.
name|setPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|PointerLikeTypeTraits
operator|<
name|PT2
operator|>
operator|::
name|getAsVoidPointer
argument_list|(
name|V
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|Val
operator|.
name|setInt
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/// isNull - Return true if the pointer held in the union is null,
comment|/// regardless of which type it is.
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getPointer
argument_list|()
operator|==
literal|0
return|;
block|}
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
comment|/// is<T>() return true if the Union currently holds the type matching T.
name|template
operator|<
name|typename
name|T
operator|>
name|int
name|is
argument_list|()
specifier|const
block|{
name|int
name|TyNo
operator|=
operator|::
name|llvm
operator|::
name|getPointerUnionTypeNum
operator|<
name|PT1
block|,
name|PT2
operator|>
operator|(
operator|(
name|T
operator|*
operator|)
literal|0
operator|)
block|;
name|assert
argument_list|(
name|TyNo
operator|!=
operator|-
literal|1
operator|&&
literal|"Type query could never succeed on PointerUnion!"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|Val
operator|.
name|getInt
argument_list|()
operator|)
operator|==
name|TyNo
return|;
block|}
comment|/// get<T>() - Return the value of the specified pointer type. If the
comment|/// specified pointer type is incorrect, assert.
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|get
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
operator|&&
literal|"Invalid accessor called"
argument_list|)
block|;
return|return
name|PointerLikeTypeTraits
operator|<
name|T
operator|>
operator|::
name|getFromVoidPointer
argument_list|(
name|Val
operator|.
name|getPointer
argument_list|()
argument_list|)
return|;
block|}
comment|/// dyn_cast<T>() - If the current value is of the specified pointer type,
comment|/// return it, otherwise return null.
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|dyn_cast
argument_list|()
specifier|const
block|{
if|if
condition|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
condition|)
return|return
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
return|return
name|T
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Assignment operators - Allow assigning into this union from either
end_comment

begin_comment
comment|/// pointer type, setting the discriminator to remember what it came from.
end_comment

begin_decl_stmt
specifier|const
name|PointerUnion
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT1
operator|&
name|RHS
operator|)
block|{
name|Val
operator|.
name|setPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|PointerLikeTypeTraits
operator|<
name|PT1
operator|>
operator|::
name|getAsVoidPointer
argument_list|(
name|RHS
argument_list|)
operator|)
argument_list|)
block|;
name|Val
operator|.
name|setInt
argument_list|(
literal|0
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT2
operator|&
name|RHS
operator|)
block|{
name|Val
operator|.
name|setPointer
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|PointerLikeTypeTraits
operator|<
name|PT2
operator|>
operator|::
name|getAsVoidPointer
argument_list|(
name|RHS
argument_list|)
operator|)
argument_list|)
block|;
name|Val
operator|.
name|setInt
argument_list|(
literal|1
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|PointerUnion
name|getFromOpaqueValue
parameter_list|(
name|void
modifier|*
name|VP
parameter_list|)
block|{
name|PointerUnion
name|V
decl_stmt|;
name|V
operator|.
name|Val
operator|=
name|ValTy
operator|::
name|getFromOpaqueValue
argument_list|(
name|VP
argument_list|)
expr_stmt|;
return|return
name|V
return|;
block|}
end_function

begin_comment
unit|};
comment|// Teach SmallPtrSet that PointerUnion is "basically a pointer", that has
end_comment

begin_comment
comment|// # low bits available = min(PT1bits,PT2bits)-1.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|PointerUnion
operator|<
name|PT1
operator|,
name|PT2
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
argument|const PointerUnion<PT1
argument_list|,
argument|PT2>&P
argument_list|)
block|{
return|return
name|P
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|PointerUnion
operator|<
name|PT1
operator|,
name|PT2
operator|>
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|PointerUnion
operator|<
name|PT1
operator|,
name|PT2
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
name|P
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// The number of bits available are the min of the two pointer types.
end_comment

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
name|PointerLikeTypeTraits
operator|<
name|typename
name|PointerUnion
operator|<
name|PT1
block|,
name|PT2
decl|>::
name|ValTy
decl|>           ::
name|NumLowBitsAvailable
block|}
enum|;
end_enum

begin_comment
unit|};
comment|/// PointerUnion3 - This is a pointer union of three pointer types.  See
end_comment

begin_comment
comment|/// documentation for PointerUnion for usage.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|,
name|typename
name|PT3
operator|>
name|class
name|PointerUnion3
block|{
name|public
operator|:
typedef|typedef
name|PointerUnion
operator|<
name|PT1
operator|,
name|PT2
operator|>
name|InnerUnion
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|PointerUnion
operator|<
name|InnerUnion
operator|,
name|PT3
operator|>
name|ValTy
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|ValTy
name|Val
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|PointerUnion3
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|PointerUnion3
argument_list|(
argument|PT1 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|PointerUnion3
argument_list|(
argument|PT2 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|PointerUnion3
argument_list|(
argument|PT3 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|V
expr_stmt|;
block|}
end_block

begin_comment
comment|/// isNull - Return true if the pointer held in the union is null,
end_comment

begin_comment
comment|/// regardless of which type it is.
end_comment

begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// is<T>() return true if the Union currently holds the type matching T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|int
name|is
argument_list|()
specifier|const
block|{
comment|// Is it PT1/PT2?
if|if
condition|(
operator|::
name|llvm
operator|::
name|getPointerUnionTypeNum
operator|<
name|PT1
operator|,
name|PT2
operator|>
operator|(
operator|(
name|T
operator|*
operator|)
literal|0
operator|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|Val
operator|.
name|is
operator|<
name|InnerUnion
operator|>
operator|(
operator|)
operator|&&
name|Val
operator|.
name|get
operator|<
name|InnerUnion
operator|>
operator|(
operator|)
operator|.
name|is
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|Val
operator|.
name|is
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// get<T>() - Return the value of the specified pointer type. If the
end_comment

begin_comment
comment|/// specified pointer type is incorrect, assert.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|T
name|get
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
operator|&&
literal|"Invalid accessor called"
argument_list|)
block|;
comment|// Is it PT1/PT2?
if|if
condition|(
operator|::
name|llvm
operator|::
name|getPointerUnionTypeNum
operator|<
name|PT1
operator|,
name|PT2
operator|>
operator|(
operator|(
name|T
operator|*
operator|)
literal|0
operator|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|Val
operator|.
name|get
operator|<
name|InnerUnion
operator|>
operator|(
operator|)
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|Val
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// dyn_cast<T>() - If the current value is of the specified pointer type,
end_comment

begin_comment
comment|/// return it, otherwise return null.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|T
name|dyn_cast
argument_list|()
specifier|const
block|{
if|if
condition|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
condition|)
return|return
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|T
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Assignment operators - Allow assigning into this union from either
end_comment

begin_comment
comment|/// pointer type, setting the discriminator to remember what it came from.
end_comment

begin_decl_stmt
unit|const
name|PointerUnion3
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT1
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion3
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT2
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion3
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT3
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|RHS
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|PointerUnion3
name|getFromOpaqueValue
parameter_list|(
name|void
modifier|*
name|VP
parameter_list|)
block|{
name|PointerUnion3
name|V
decl_stmt|;
name|V
operator|.
name|Val
operator|=
name|ValTy
operator|::
name|getFromOpaqueValue
argument_list|(
name|VP
argument_list|)
expr_stmt|;
return|return
name|V
return|;
block|}
end_function

begin_comment
unit|};
comment|// Teach SmallPtrSet that PointerUnion3 is "basically a pointer", that has
end_comment

begin_comment
comment|// # low bits available = min(PT1bits,PT2bits,PT2bits)-2.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|,
name|typename
name|PT3
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|PointerUnion3
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
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
argument|const PointerUnion3<PT1
argument_list|,
argument|PT2
argument_list|,
argument|PT3>&P
argument_list|)
block|{
return|return
name|P
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|PointerUnion3
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
operator|>
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|PointerUnion3
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
name|P
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// The number of bits available are the min of the two pointer types.
end_comment

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
name|PointerLikeTypeTraits
operator|<
name|typename
name|PointerUnion3
operator|<
name|PT1
block|,
name|PT2
block|,
name|PT3
decl|>::
name|ValTy
decl|>           ::
name|NumLowBitsAvailable
block|}
enum|;
end_enum

begin_comment
unit|};
comment|/// PointerUnion4 - This is a pointer union of four pointer types.  See
end_comment

begin_comment
comment|/// documentation for PointerUnion for usage.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|,
name|typename
name|PT3
operator|,
name|typename
name|PT4
operator|>
name|class
name|PointerUnion4
block|{
name|public
operator|:
typedef|typedef
name|PointerUnion
operator|<
name|PT1
operator|,
name|PT2
operator|>
name|InnerUnion1
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|PointerUnion
operator|<
name|PT3
operator|,
name|PT4
operator|>
name|InnerUnion2
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|PointerUnion
operator|<
name|InnerUnion1
operator|,
name|InnerUnion2
operator|>
name|ValTy
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|ValTy
name|Val
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_macro
name|PointerUnion4
argument_list|()
end_macro

begin_block
block|{}
end_block

begin_macro
name|PointerUnion4
argument_list|(
argument|PT1 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion1
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|PointerUnion4
argument_list|(
argument|PT2 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion1
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|PointerUnion4
argument_list|(
argument|PT3 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion2
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|PointerUnion4
argument_list|(
argument|PT4 V
argument_list|)
end_macro

begin_block
block|{
name|Val
operator|=
name|InnerUnion2
argument_list|(
name|V
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/// isNull - Return true if the pointer held in the union is null,
end_comment

begin_comment
comment|/// regardless of which type it is.
end_comment

begin_expr_stmt
name|bool
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isNull
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// is<T>() return true if the Union currently holds the type matching T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|int
name|is
argument_list|()
specifier|const
block|{
comment|// Is it PT1/PT2?
if|if
condition|(
operator|::
name|llvm
operator|::
name|getPointerUnionTypeNum
operator|<
name|PT1
operator|,
name|PT2
operator|>
operator|(
operator|(
name|T
operator|*
operator|)
literal|0
operator|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|Val
operator|.
name|is
operator|<
name|InnerUnion1
operator|>
operator|(
operator|)
operator|&&
name|Val
operator|.
name|get
operator|<
name|InnerUnion1
operator|>
operator|(
operator|)
operator|.
name|is
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|Val
operator|.
name|is
operator|<
name|InnerUnion2
operator|>
operator|(
operator|)
operator|&&
name|Val
operator|.
name|get
operator|<
name|InnerUnion2
operator|>
operator|(
operator|)
operator|.
name|is
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// get<T>() - Return the value of the specified pointer type. If the
end_comment

begin_comment
comment|/// specified pointer type is incorrect, assert.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|T
name|get
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
operator|&&
literal|"Invalid accessor called"
argument_list|)
block|;
comment|// Is it PT1/PT2?
if|if
condition|(
operator|::
name|llvm
operator|::
name|getPointerUnionTypeNum
operator|<
name|PT1
operator|,
name|PT2
operator|>
operator|(
operator|(
name|T
operator|*
operator|)
literal|0
operator|)
operator|!=
operator|-
literal|1
condition|)
return|return
name|Val
operator|.
name|get
operator|<
name|InnerUnion1
operator|>
operator|(
operator|)
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|Val
operator|.
name|get
operator|<
name|InnerUnion2
operator|>
operator|(
operator|)
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_return

begin_comment
unit|}
comment|/// dyn_cast<T>() - If the current value is of the specified pointer type,
end_comment

begin_comment
comment|/// return it, otherwise return null.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|T
name|dyn_cast
argument_list|()
specifier|const
block|{
if|if
condition|(
name|is
operator|<
name|T
operator|>
operator|(
operator|)
condition|)
return|return
name|get
operator|<
name|T
operator|>
operator|(
operator|)
return|;
end_expr_stmt

begin_return
return|return
name|T
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|/// Assignment operators - Allow assigning into this union from either
end_comment

begin_comment
comment|/// pointer type, setting the discriminator to remember what it came from.
end_comment

begin_decl_stmt
unit|const
name|PointerUnion4
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT1
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion1
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion4
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT2
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion1
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion4
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT3
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion2
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_decl_stmt
specifier|const
name|PointerUnion4
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PT4
operator|&
name|RHS
operator|)
block|{
name|Val
operator|=
name|InnerUnion2
argument_list|(
name|RHS
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|void
operator|*
name|getOpaqueValue
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|PointerUnion4
name|getFromOpaqueValue
parameter_list|(
name|void
modifier|*
name|VP
parameter_list|)
block|{
name|PointerUnion4
name|V
decl_stmt|;
name|V
operator|.
name|Val
operator|=
name|ValTy
operator|::
name|getFromOpaqueValue
argument_list|(
name|VP
argument_list|)
expr_stmt|;
return|return
name|V
return|;
block|}
end_function

begin_comment
unit|};
comment|// Teach SmallPtrSet that PointerUnion4 is "basically a pointer", that has
end_comment

begin_comment
comment|// # low bits available = min(PT1bits,PT2bits,PT2bits)-2.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|PT1
operator|,
name|typename
name|PT2
operator|,
name|typename
name|PT3
operator|,
name|typename
name|PT4
operator|>
name|class
name|PointerLikeTypeTraits
operator|<
name|PointerUnion4
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
operator|,
name|PT4
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
argument|const PointerUnion4<PT1
argument_list|,
argument|PT2
argument_list|,
argument|PT3
argument_list|,
argument|PT4>&P
argument_list|)
block|{
return|return
name|P
operator|.
name|getOpaqueValue
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|PointerUnion4
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
operator|,
name|PT4
operator|>
name|getFromVoidPointer
argument_list|(
argument|void *P
argument_list|)
block|{
return|return
name|PointerUnion4
operator|<
name|PT1
operator|,
name|PT2
operator|,
name|PT3
operator|,
name|PT4
operator|>
operator|::
name|getFromOpaqueValue
argument_list|(
name|P
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// The number of bits available are the min of the two pointer types.
end_comment

begin_enum
enum|enum
block|{
name|NumLowBitsAvailable
init|=
name|PointerLikeTypeTraits
operator|<
name|typename
name|PointerUnion4
operator|<
name|PT1
block|,
name|PT2
block|,
name|PT3
block|,
name|PT4
decl|>::
name|ValTy
decl|>           ::
name|NumLowBitsAvailable
block|}
enum|;
end_enum

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

