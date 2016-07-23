begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// Test checks that 'mode' attribute is handled correctly with enums, i. e. code
end_comment

begin_comment
comment|//   1. "typedef enum { A } __attribute__((mode(HI))) T;" is accepted,
end_comment

begin_comment
comment|//   2. "enum X __attribute__((mode(QI))) var;" forms a complete integer type.
end_comment

begin_comment
comment|//   3. "enum { A } __attribute__((mode(V4SI))) var;" is not accepted (vector mode).
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|E4
block|}
name|EnumType
typedef|;
end_typedef

begin_function
name|int
name|main
parameter_list|()
block|{
comment|// Vector mode are not allowed with enums.
typedef|typedef
enum|enum
block|{
name|E1
block|}
name|__attribute__
typedef|((
name|mode
typedef|(
name|V4QI
typedef|)))
name|RejectedType1
typedef|;
comment|// expected-error{{mode 'V4QI' is not supported for enumeration types}}
comment|// expected-warning@-1{{specifying vector types with the 'mode' attribute is deprecated}}
typedef|typedef
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V8HI
argument_list|)
operator|)
argument_list|)
block|{
name|E2
block|}
name|RejectedType2
expr_stmt|;
comment|// expected-error{{mode 'V8HI' is not supported for enumeration types}}
comment|// expected-warning@-1{{deprecated}}
typedef|typedef
name|enum
name|E3
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V2SI
argument_list|)
operator|)
argument_list|)
name|RejectedType3
typedef|;
comment|// expected-error{{mode 'V2SI' is not supported for enumeration types}}
comment|// expected-warning@-1{{deprecated}}
typedef|typedef
name|EnumType
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V4DI
argument_list|)
operator|)
argument_list|)
name|RejectedType4
typedef|;
comment|// expected-error{{mode 'V4DI' is not supported for enumeration types}}
comment|// expected-warning@-1{{deprecated}}
name|EnumType
name|v1
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V4QI
argument_list|)
operator|)
argument_list|)
decl_stmt|;
comment|// expected-error{{mode 'V4QI' is not supported for enumeration types}}
comment|// expected-warning@-1{{deprecated}}
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|V8HI
argument_list|)
operator|)
argument_list|)
block|{
name|E5
block|}
name|v2
expr_stmt|;
comment|// expected-error{{mode 'V8HI' is not supported for enumeration types}}
comment|// expected-warning@-1{{deprecated}}
comment|// Incomplete enums without mode attribute are not allowed.
typedef|typedef
name|enum
name|Y
name|IncompleteYType
typedef|;
comment|// expected-note{{forward declaration of 'enum Y'}}
name|enum
name|X
name|a1
decl_stmt|;
comment|// expected-error{{variable has incomplete type 'enum X'}}
comment|// expected-note@-1{{forward declaration of 'enum X'}}
name|IncompleteYType
name|a2
decl_stmt|;
comment|// expected-error{{variable has incomplete type 'IncompleteYType' (aka 'enum Y')}}
comment|// OK with 'mode' attribute.
typedef|typedef
name|enum
name|Y
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|CompleteYType1
typedef|;
typedef|typedef
name|enum
name|Y
name|CompleteYType2
name|__attribute__
typedef|((
name|mode
typedef|(
name|HI
typedef|)));
typedef|typedef
enum|enum
block|{
name|A1
block|,
name|B1
block|}
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)))
name|CompleteType3
typedef|;
typedef|typedef
enum|enum
block|{
name|A2
block|,
name|B2
block|}
name|CompleteType4
name|__attribute__
typedef|((
name|mode
typedef|(
name|QI
typedef|)));
typedef|typedef
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
block|{
name|A3
operator|,
name|B3
block|}
name|CompleteType5
expr_stmt|;
name|enum
name|X
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|a3
decl_stmt|;
name|enum
name|X
name|a4
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|HI
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|IncompleteYType
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
name|a5
decl_stmt|;
name|IncompleteYType
name|a6
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|HI
argument_list|)
operator|)
argument_list|)
decl_stmt|;
name|CompleteYType1
name|a7
decl_stmt|;
name|CompleteYType2
name|a8
decl_stmt|;
name|CompleteType3
name|a9
decl_stmt|;
name|CompleteType4
name|a10
decl_stmt|;
name|CompleteType5
name|a11
decl_stmt|;
name|enum
name|__attribute__
argument_list|(
operator|(
name|mode
argument_list|(
name|QI
argument_list|)
operator|)
argument_list|)
block|{
name|A4
operator|,
name|B4
block|}
name|a12
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

