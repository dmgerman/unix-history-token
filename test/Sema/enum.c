begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify -pedantic
end_comment

begin_enum
enum|enum
name|e
block|{
name|A
block|,
name|B
init|=
literal|42LL
operator|<<
literal|32
block|,
comment|// expected-warning {{ISO C restricts enumerator values to range of 'int'}}
name|C
init|=
operator|-
literal|4
block|,
name|D
init|=
literal|12456
block|}
enum|;
end_enum

begin_enum
enum|enum
name|f
block|{
name|a
init|=
operator|-
literal|2147483648
block|,
name|b
init|=
literal|2147483647
block|}
enum|;
end_enum

begin_comment
comment|// ok.
end_comment

begin_enum
enum|enum
name|g
block|{
comment|// too negative
name|c
init|=
operator|-
literal|2147483649
block|,
comment|// expected-warning {{ISO C restricts enumerator values to range of 'int'}}
name|d
init|=
literal|2147483647
block|}
enum|;
end_enum

begin_enum
enum|enum
name|h
block|{
name|e
init|=
operator|-
literal|2147483648
block|,
comment|// too pos
name|f
init|=
literal|2147483648
comment|// expected-warning {{ISO C restricts enumerator values to range of 'int'}}
block|}
enum|;
end_enum

begin_comment
comment|// minll maxull
end_comment

begin_enum
enum|enum
name|x
comment|// expected-warning {{enumeration values exceed range of largest integer}}
block|{
name|y
init|=
operator|-
literal|9223372036854775807LL
operator|-
literal|1
block|,
comment|// expected-warning {{ISO C restricts enumerator values to range of 'int'}}
name|z
init|=
literal|9223372036854775808ULL
block|}
enum|;
end_enum

begin_comment
comment|// expected-warning {{ISO C restricts enumerator values to range of 'int'}}
end_comment

begin_function
name|int
name|test
parameter_list|()
block|{
return|return
sizeof|sizeof
argument_list|(
expr|enum
name|e
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|enum
name|gccForwardEnumExtension
name|ve
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{ISO C forbids forward references to 'enum' types}} \
end_comment

begin_comment
comment|// expected-error{{tentative definition has type 'enum gccForwardEnumExtension' that is never completed}} \
end_comment

begin_comment
comment|// expected-note{{forward declaration of 'enum gccForwardEnumExtension'}}
end_comment

begin_function
name|int
name|test2
parameter_list|(
name|int
name|i
parameter_list|)
block|{
name|ve
operator|+
name|i
expr_stmt|;
comment|// expected-error{{invalid operands to binary expression}}
block|}
end_function

begin_comment
comment|// PR2020
end_comment

begin_union_decl
union_decl|union
name|u0
union_decl|;
end_union_decl

begin_comment
comment|// expected-note {{previous use is here}}
end_comment

begin_enum
enum|enum
name|u0
block|{
name|U0A
block|}
enum|;
end_enum

begin_comment
comment|// expected-error {{use of 'u0' with tag type that does not match previous declaration}}
end_comment

begin_comment
comment|// rdar://6095136
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|some_undefined_enum
name|ve2
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{ISO C forbids forward references to 'enum' types}}
end_comment

begin_function
name|void
name|test4
parameter_list|()
block|{
for|for
control|(
init|;
name|ve2
condition|;
control|)
comment|// expected-error {{statement requires expression of scalar type}}
empty_stmt|;
operator|(
name|_Bool
operator|)
name|ve2
expr_stmt|;
comment|// expected-error {{arithmetic or pointer type is required}}
for|for
control|(
init|;
condition|;
name|ve2
control|)
comment|// expected-warning {{expression result unused}}
empty_stmt|;
operator|(
name|void
operator|)
name|ve2
expr_stmt|;
name|ve2
expr_stmt|;
comment|// expected-warning {{expression result unused}}
block|}
end_function

begin_comment
comment|// PR2416
end_comment

begin_enum
enum|enum
name|someenum
block|{}
enum|;
end_enum

begin_comment
comment|// expected-warning {{use of empty enum extension}}
end_comment

begin_comment
comment|//<rdar://problem/6093889>
end_comment

begin_enum
enum|enum
name|e0
block|{
comment|// expected-note {{previous definition is here}}
name|E0
init|=
sizeof|sizeof
argument_list|(
expr|enum
name|e0
block|{
name|E1
block|}
argument_list|)
block|,
comment|// expected-error {{nested redefinition}}
block|}
enum|;
end_enum

begin_comment
comment|// PR3173
end_comment

begin_enum
enum|enum
block|{
name|PR3173A
block|,
name|PR3173B
init|=
name|PR3173A
operator|+
literal|50
block|}
enum|;
end_enum

begin_comment
comment|// PR2753
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
enum_decl|enum
name|xpto
enum_decl|;
comment|// expected-warning{{ISO C forbids forward references to 'enum' types}}
enum_decl|enum
name|xpto
enum_decl|;
comment|// expected-warning{{ISO C forbids forward references to 'enum' types}}
block|}
end_function

begin_comment
comment|//<rdar://problem/6503878>
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|X
init|=
literal|0
block|}
empty_stmt|;
end_typedef

begin_comment
comment|// expected-warning{{typedef requires a name}}
end_comment

begin_enum
enum|enum
name|NotYetComplete
block|{
comment|// expected-note{{definition of 'enum NotYetComplete' is not complete until the closing '}'}}
name|NYC1
init|=
expr|sizeof
operator|(
expr|enum
name|NotYetComplete
operator|)
comment|// expected-error{{invalid application of 'sizeof' to an incomplete type 'enum NotYetComplete'}}
block|}
enum|;
end_enum

begin_comment
comment|/// PR3688
end_comment

begin_struct
struct|struct
name|s1
block|{
name|enum
name|e1
function_decl|(
modifier|*
name|bar
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// expected-warning{{ISO C forbids forward references to 'enum' types}}
block|}
struct|;
end_struct

begin_enum
enum|enum
name|e1
block|{
name|YES
block|,
name|NO
block|}
enum|;
end_enum

begin_function
specifier|static
name|enum
name|e1
name|badfunc
parameter_list|(
name|struct
name|s1
modifier|*
name|q
parameter_list|)
block|{
return|return
name|q
operator|->
name|bar
argument_list|()
return|;
block|}
end_function

end_unit

