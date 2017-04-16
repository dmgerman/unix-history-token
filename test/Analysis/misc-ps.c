begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_analyze_cc1 -triple x86_64-apple-darwin10 -disable-free -analyzer-eagerly-assume -analyzer-checker=core,deadcode,debug.ExprInspection -verify %s
end_comment

begin_function_decl
name|void
name|clang_analyzer_eval
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|size_rdar9373039
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|foo_rdar9373039
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|rdar93730392
parameter_list|()
block|{
name|int
name|x
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|x
operator|=
literal|1
expr_stmt|;
name|int
name|extra
init|=
operator|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"Clang"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"Clang"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
operator|+
operator|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"1.0"
argument_list|)
operator|+
operator|(
operator|(
literal|4
operator|-
operator|(
call|(
name|unsigned
name|int
call|)
argument_list|(
literal|2
operator|+
name|foo_rdar9373039
argument_list|(
literal|"1.0"
argument_list|)
argument_list|)
operator|%
literal|4
operator|)
operator|)
operator|%
literal|4
operator|)
operator|)
decl_stmt|;
comment|// expected-warning {{never read}}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|size_rdar9373039
condition|;
operator|++
name|i
control|)
name|j
operator|+=
name|x
expr_stmt|;
comment|// expected-warning {{garbage}}
return|return
name|j
return|;
block|}
end_function

begin_function
name|int
name|PR8962
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// This should look through the __extension__ no-op.
if|if
condition|(
name|__extension__
argument_list|(
name|t
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// expected-warning {{null pointer}}
block|}
end_function

begin_function
name|int
name|PR8962_b
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// This should still ignore the nested casts
comment|// which aren't handled by a single IgnoreParens()
if|if
condition|(
operator|(
call|(
name|int
call|)
argument_list|(
operator|(
name|int
operator|)
name|t
argument_list|)
operator|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// expected-warning {{null pointer}}
block|}
end_function

begin_function
name|int
name|PR8962_c
parameter_list|(
name|int
modifier|*
name|t
parameter_list|)
block|{
comment|// If the last element in a StmtExpr was a ParenExpr, it's still live
if|if
condition|(
operator|(
block|{
operator|(
name|t
condition|?
operator|(
name|_Bool
operator|)
literal|0
else|:
operator|(
name|_Bool
operator|)
literal|1
operator|)
expr_stmt|;
block|}
block|)
end_function

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_d
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// If the last element in a StmtExpr is an __extension__, it's still live
if|if
condition|(
operator|(
block|{
name|__extension__
argument_list|(
name|t
condition|?
operator|(
name|_Bool
operator|)
literal|0
else|:
operator|(
name|_Bool
operator|)
literal|1
argument_list|)
expr_stmt|;
block|}
block|)
end_block

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_e
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// Redundant casts can mess things up!
comment|// Environment used to skip through NoOp casts, but LiveVariables didn't!
if|if
condition|(
operator|(
block|{
operator|(
name|t
condition|?
call|(
name|int
call|)
argument_list|(
name|int
argument_list|)
literal|0L
else|:
call|(
name|int
call|)
argument_list|(
name|int
argument_list|)
literal|1L
operator|)
expr_stmt|;
block|}
block|)
end_block

begin_return
unit|)
return|return
literal|0
return|;
end_return

begin_return
return|return
operator|*
name|t
return|;
end_return

begin_comment
comment|// no-warning
end_comment

begin_macro
unit|}  int
name|PR8962_f
argument_list|(
argument|int *t
argument_list|)
end_macro

begin_block
block|{
comment|// The StmtExpr isn't a block-level expression here,
comment|// the __extension__ is. But the value should be attached to the StmtExpr
comment|// anyway. Make sure the block-level check is /before/ IgnoreParens.
if|if
condition|(
name|__extension__
argument_list|(
argument|{     _Bool r;     if (t) r =
literal|0
argument|;     else r =
literal|1
argument|;     r;   }
argument_list|)
condition|)
return|return
literal|0
return|;
return|return
operator|*
name|t
return|;
comment|// no-warning
block|}
end_block

begin_comment
comment|// This previously crashed logic in the analyzer engine when evaluating locations.
end_comment

begin_function_decl
name|void
name|rdar10308201_aux
parameter_list|(
name|unsigned
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|rdar10308201
parameter_list|(
name|int
name|valA
parameter_list|,
name|void
modifier|*
name|valB
parameter_list|,
name|unsigned
name|valC
parameter_list|)
block|{
name|unsigned
name|actual_base
decl_stmt|,
name|lines
decl_stmt|;
if|if
condition|(
name|valC
operator|==
literal|0
condition|)
block|{
name|actual_base
operator|=
operator|(
name|unsigned
operator|)
name|valB
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
name|valA
operator|&
operator|(
literal|1
operator|<<
literal|0
operator|)
condition|)
name|rdar10308201_aux
argument_list|(
name|actual_base
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_typedef
typedef|typedef
struct|struct
name|Struct103
block|{
name|unsigned
name|i
decl_stmt|;
block|}
name|Struct103
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_function_decl
name|void
name|__my_memset_chk
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|radar10367606
parameter_list|(
name|int
name|t
parameter_list|)
block|{
name|Struct103
name|overall
decl_stmt|;
operator|(
operator|(
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|overall
argument_list|,
literal|0
argument_list|)
operator|!=
operator|(
name|size_t
operator|)
operator|-
literal|1
operator|)
condition|?
name|__builtin___memset_chk
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|overall
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|Struct103
argument_list|)
argument_list|,
name|__builtin_object_size
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|overall
argument_list|,
literal|0
argument_list|)
argument_list|)
else|:
name|__my_memset_chk
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|overall
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|Struct103
argument_list|)
argument_list|)
operator|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* Caching out on a sink node. */
end_comment

begin_function_decl
specifier|extern
name|int
name|fooR10376675
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|bazR10376675
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|nR10376675
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|barR10376675
parameter_list|(
name|int
modifier|*
name|x
parameter_list|)
block|{
name|int
modifier|*
name|pm
decl_stmt|;
if|if
condition|(
name|nR10376675
operator|*
literal|2
condition|)
block|{
name|int
modifier|*
name|pk
init|=
name|bazR10376675
argument_list|()
decl_stmt|;
name|pm
operator|=
name|pk
expr_stmt|;
comment|//expected-warning {{never read}}
block|}
do|do
block|{
operator|*
name|x
operator|=
name|fooR10376675
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
literal|0
condition|)
do|;
block|}
end_function

begin_comment
comment|// Test accesses to wide character strings doesn't break the analyzer.
end_comment

begin_typedef
typedef|typedef
name|int
name|wchar_t
typedef|;
end_typedef

begin_struct
struct|struct
name|rdar10385775
block|{
name|wchar_t
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_function
name|void
name|RDar10385775
parameter_list|(
name|struct
name|rdar10385775
modifier|*
name|p
parameter_list|)
block|{
name|p
operator|->
name|name
operator|=
literal|L"a"
expr_stmt|;
block|}
end_function

begin_comment
comment|// Test double loop of array and array literals.  Previously this
end_comment

begin_comment
comment|// resulted in a false positive uninitailized value warning.
end_comment

begin_function
name|void
name|rdar10686586
parameter_list|()
block|{
name|int
name|array1
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|0
block|}
decl_stmt|;
name|int
name|array2
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|0
block|}
decl_stmt|;
name|int
modifier|*
name|array
index|[]
init|=
block|{
name|array1
block|,
name|array2
block|}
decl_stmt|;
name|int
name|sum
init|=
literal|0
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
literal|4
condition|;
name|j
operator|++
control|)
block|{
name|sum
operator|+=
name|array
index|[
name|i
index|]
index|[
name|j
index|]
expr_stmt|;
comment|// no-warning
block|}
block|}
block|}
end_function

begin_comment
comment|// This example tests CFG handling of '||' nested in a ternary expression,
end_comment

begin_comment
comment|// and seeing that the analyzer doesn't crash.
end_comment

begin_function
name|int
name|isctype
parameter_list|(
name|char
name|c
parameter_list|,
name|unsigned
name|long
name|f
parameter_list|)
block|{
return|return
operator|(
name|c
operator|<
literal|1
operator|||
name|c
operator|>
literal|10
operator|)
condition|?
literal|0
else|:
operator|!
operator|!
operator|(
name|c
operator|&
name|f
operator|)
return|;
block|}
end_function

begin_comment
comment|// Test that symbolic array offsets are modeled conservatively.
end_comment

begin_comment
comment|// This was triggering a false "use of uninitialized value" warning.
end_comment

begin_function_decl
name|void
name|rdar_12075238__aux
parameter_list|(
name|unsigned
name|long
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|int
name|rdar_12075238_
parameter_list|(
name|unsigned
name|long
name|count
parameter_list|)
block|{
if|if
condition|(
operator|(
name|count
operator|<
literal|3
operator|)
operator|||
operator|(
name|count
operator|>
literal|6
operator|)
condition|)
return|return
literal|0
return|;
name|unsigned
name|long
name|array
index|[
literal|6
index|]
decl_stmt|;
name|unsigned
name|long
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|i
operator|<=
name|count
operator|-
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|array
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
block|}
name|array
index|[
name|count
operator|-
literal|1
index|]
operator|=
name|i
expr_stmt|;
name|rdar_12075238__aux
argument_list|(
name|array
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
comment|// no-warning
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// Test that we handle an uninitialized value within a logical expression.
end_comment

begin_function
name|void
name|PR14635
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|a
init|=
literal|0
decl_stmt|,
name|b
decl_stmt|;
operator|*
name|p
operator|=
name|a
operator|||
name|b
expr_stmt|;
comment|// expected-warning {{Assigned value is garbage or undefined}}
block|}
end_function

begin_comment
comment|// Test handling floating point values with unary '!'.
end_comment

begin_function
name|int
name|PR14634
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|double
name|y
init|=
operator|(
name|double
operator|)
name|x
decl_stmt|;
return|return
operator|!
name|y
return|;
block|}
end_function

begin_comment
comment|// PR15684: If a checker generates a sink node after generating a regular node
end_comment

begin_comment
comment|// and no state changes between the two, graph trimming would consider the two
end_comment

begin_comment
comment|// the same node, forming a loop.
end_comment

begin_struct
struct|struct
name|PR15684
block|{
name|void
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function
name|void
name|sinkAfterRegularNode
parameter_list|(
name|struct
name|PR15684
modifier|*
name|context
parameter_list|)
block|{
name|int
name|uninitialized
decl_stmt|;
name|context
operator|->
name|callback
argument_list|(
name|uninitialized
argument_list|)
expr_stmt|;
comment|// expected-warning {{uninitialized}}
block|}
end_function

begin_comment
comment|// PR16131: C permits variables to be declared extern void.
end_comment

begin_function
specifier|static
name|void
name|PR16131
parameter_list|(
name|int
name|x
parameter_list|)
block|{
specifier|extern
name|void
name|v
decl_stmt|;
name|int
modifier|*
name|ip
init|=
operator|(
name|int
operator|*
operator|)
operator|&
name|v
decl_stmt|;
name|char
modifier|*
name|cp
init|=
operator|(
name|char
operator|*
operator|)
operator|&
name|v
decl_stmt|;
name|clang_analyzer_eval
argument_list|(
name|ip
operator|==
name|cp
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
comment|// expected-warning@-1 {{comparison of distinct pointer types}}
operator|*
name|ip
operator|=
literal|42
expr_stmt|;
name|clang_analyzer_eval
argument_list|(
operator|*
name|ip
operator|==
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
name|clang_analyzer_eval
argument_list|(
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|v
operator|==
literal|42
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
end_function

begin_comment
comment|// PR15623: Currently the analyzer doesn't handle symbolic expressions of the
end_comment

begin_comment
comment|// form "(exp comparison_op expr) != 0" very well. We perform a simplification
end_comment

begin_comment
comment|// translating an assume of a constraint of the form "(exp comparison_op expr)
end_comment

begin_comment
comment|// != 0" to true into an assume of "exp comparison_op expr" to true.
end_comment

begin_function
name|void
name|PR15623
parameter_list|(
name|int
name|n
parameter_list|)
block|{
if|if
condition|(
operator|(
name|n
operator|==
literal|0
operator|)
operator|!=
literal|0
condition|)
block|{
name|clang_analyzer_eval
argument_list|(
name|n
operator|==
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning{{TRUE}}
block|}
block|}
end_function

end_unit

