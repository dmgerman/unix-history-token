begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -analyzer-checker=core -analyzer-store=region -fblocks -verify %s
end_comment

begin_struct
struct|struct
name|FPRec
block|{
name|void
function_decl|(
modifier|*
name|my_func
function_decl|)
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|bar
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f1_a
parameter_list|(
name|struct
name|FPRec
modifier|*
name|foo
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
call|(
modifier|*
name|foo
operator|->
name|my_func
call|)
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
return|return
name|bar
argument_list|(
name|x
argument_list|)
operator|+
literal|1
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|f1_b
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
return|return
name|bar
argument_list|(
name|x
argument_list|)
operator|+
literal|1
return|;
comment|// expected-warning{{1st function call argument is an uninitialized value}}
block|}
end_function

begin_function
name|int
name|f2
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|x
operator|+
literal|1
condition|)
comment|// expected-warning{{The left operand of '+' is a garbage value}}
return|return
literal|1
return|;
return|return
literal|2
return|;
block|}
end_function

begin_function
name|int
name|f2_b
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
return|return
operator|(
operator|(
literal|1
operator|+
name|x
operator|)
operator|+
literal|2
operator|+
operator|(
operator|(
name|x
operator|)
operator|)
operator|)
operator|+
literal|1
condition|?
literal|1
else|:
literal|2
return|;
comment|// expected-warning{{The right operand of '+' is a garbage value}}
block|}
end_function

begin_function
name|int
name|f3
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|&
name|i
decl_stmt|;
if|if
condition|(
operator|*
name|p
operator|>
literal|0
condition|)
comment|// expected-warning{{The left operand of '>' is a garbage value}}
return|return
literal|0
return|;
else|else
return|return
literal|1
return|;
block|}
end_function

begin_function_decl
name|void
name|f4_aux
parameter_list|(
name|float
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|float
name|f4
parameter_list|(
name|void
parameter_list|)
block|{
name|float
name|x
decl_stmt|;
name|f4_aux
argument_list|(
operator|&
name|x
argument_list|)
expr_stmt|;
return|return
name|x
return|;
comment|// no-warning
block|}
end_function

begin_struct
struct|struct
name|f5_struct
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|f5_aux
parameter_list|(
name|struct
name|f5_struct
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|f5
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|f5_struct
name|s
decl_stmt|;
name|f5_aux
argument_list|(
operator|&
name|s
argument_list|)
expr_stmt|;
return|return
name|s
operator|.
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|f6
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|a
index|[
literal|20
index|]
decl_stmt|;
if|if
condition|(
name|x
operator|==
literal|25
condition|)
block|{}
if|if
condition|(
name|a
index|[
name|x
index|]
operator|==
literal|123
condition|)
block|{}
comment|// expected-warning{{The left operand of '==' is a garbage value due to array index out of bounds}}
block|}
end_function

begin_function
name|int
name|ret_uninit
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|int
modifier|*
name|p
init|=
operator|&
name|i
decl_stmt|;
return|return
operator|*
name|p
return|;
comment|// expected-warning{{Undefined or garbage value returned to caller}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6451816>
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Boolean
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFNumber
modifier|*
name|CFNumberRef
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|CFIndex
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CFIndex
name|CFNumberType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|UInt32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UInt32
name|CFStringEncoding
typedef|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|struct
name|__CFString
modifier|*
name|CFStringRef
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|Boolean
name|CFNumberGetValue
parameter_list|(
name|CFNumberRef
name|number
parameter_list|,
name|CFNumberType
name|theType
parameter_list|,
name|void
modifier|*
name|valuePtr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CFStringRef
name|CFStringConvertEncodingToIANACharSetName
parameter_list|(
name|CFStringEncoding
name|encoding
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|CFStringRef
name|rdar_6451816
parameter_list|(
name|CFNumberRef
name|nr
parameter_list|)
block|{
name|CFStringEncoding
name|encoding
decl_stmt|;
comment|//&encoding is casted to void*.  This test case tests whether or not
comment|// we properly invalidate the value of 'encoding'.
name|CFNumberGetValue
argument_list|(
name|nr
argument_list|,
literal|9
argument_list|,
operator|&
name|encoding
argument_list|)
expr_stmt|;
return|return
name|CFStringConvertEncodingToIANACharSetName
argument_list|(
name|encoding
argument_list|)
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|// PR 4630 - false warning with nonnull attribute
end_comment

begin_comment
comment|//  This false positive (due to a regression) caused the analyzer to falsely
end_comment

begin_comment
comment|//  flag a "return of uninitialized value" warning in the first branch due to
end_comment

begin_comment
comment|//  the nonnull attribute.
end_comment

begin_function_decl
name|void
name|pr_4630_aux
parameter_list|(
name|char
modifier|*
name|x
parameter_list|,
name|int
modifier|*
name|y
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(nonnull
parameter_list|(
function_decl|1
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|pr_4630_aux_2
parameter_list|(
name|char
modifier|*
name|x
parameter_list|,
name|int
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|pr_4630
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|int
name|y
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
if|if
condition|(
name|y
condition|)
block|{
name|pr_4630_aux
argument_list|(
name|a
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
return|return
name|x
return|;
comment|// no-warning
block|}
else|else
block|{
name|pr_4630_aux_2
argument_list|(
name|a
argument_list|,
operator|&
name|x
argument_list|)
expr_stmt|;
return|return
name|x
return|;
comment|// no-warning
block|}
block|}
end_function

begin_comment
comment|// PR 4631 - False positive with union initializer
end_comment

begin_comment
comment|//  Previously the analyzer didn't examine the compound initializers of unions,
end_comment

begin_comment
comment|//  resulting in some false positives for initializers with side-effects.
end_comment

begin_union
union|union
name|u_4631
block|{
name|int
name|a
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|s_4631
block|{
name|int
name|a
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|pr4631_f2
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pr4631_f3
parameter_list|(
name|void
modifier|*
name|q
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|pr4631_f1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|union
name|u_4631
name|m
init|=
block|{
name|pr4631_f2
argument_list|(
argument|&x
argument_list|)
block|}
decl_stmt|;
name|pr4631_f3
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
comment|// tell analyzer that we use m
return|return
name|x
return|;
comment|// no-warning
block|}
end_function

begin_function
name|int
name|pr4631_f1_b
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
decl_stmt|;
name|struct
name|s_4631
name|m
init|=
block|{
name|pr4631_f2
argument_list|(
argument|&x
argument_list|)
block|}
decl_stmt|;
name|pr4631_f3
argument_list|(
operator|&
name|m
argument_list|)
expr_stmt|;
comment|// tell analyzer that we use m
return|return
name|x
return|;
comment|// no-warning
block|}
end_function

begin_comment
comment|//<rdar://problem/12278788> - FP when returning a void-valued expression from
end_comment

begin_comment
comment|// a void function...or block.
end_comment

begin_function
name|void
name|foo_radar12278788
parameter_list|()
block|{
return|return;
block|}
end_function

begin_function
name|void
name|test_radar12278788
parameter_list|()
block|{
return|return
name|foo_radar12278788
argument_list|()
return|;
comment|// no-warning
block|}
end_function

begin_function
name|void
name|foo_radar12278788_fp
parameter_list|()
block|{
return|return;
block|}
end_function

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|RetIntFuncType
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|RetVoidFuncType
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function
name|int
name|test_radar12278788_FP
parameter_list|()
block|{
name|RetVoidFuncType
name|f
init|=
name|foo_radar12278788_fp
decl_stmt|;
return|return
operator|(
operator|(
name|RetIntFuncType
operator|)
name|f
operator|)
operator|(
operator|)
return|;
comment|//expected-warning {{Undefined or garbage value returned to caller}}
block|}
end_function

begin_function
name|void
name|rdar13665798
parameter_list|()
block|{
lambda|^
parameter_list|()
block|{
return|return
name|foo_radar12278788
argument_list|()
return|;
comment|// no-warning
block|}
argument_list|()
expr_stmt|;
lambda|^
name|void
parameter_list|()
block|{
return|return
name|foo_radar12278788
argument_list|()
return|;
comment|// no-warning
block|}
argument_list|()
expr_stmt|;
lambda|^
name|int
parameter_list|()
block|{
name|RetVoidFuncType
name|f
init|=
name|foo_radar12278788_fp
decl_stmt|;
return|return
operator|(
operator|(
name|RetIntFuncType
operator|)
name|f
operator|)
operator|(
operator|)
return|;
comment|//expected-warning {{Undefined or garbage value returned to caller}}
block|}
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

