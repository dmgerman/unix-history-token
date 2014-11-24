begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wswitch-enum -Wcovered-switch-default %s
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
name|z
parameter_list|)
block|{
while|while
condition|(
name|z
condition|)
block|{
default|default:
name|z
operator|--
expr_stmt|;
comment|// expected-error {{statement not in switch}}
block|}
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|int
name|X
parameter_list|)
block|{
switch|switch
condition|(
name|X
condition|)
block|{
case|case
literal|42
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|5000000000LL
case|:
comment|// expected-warning {{overflow}}
case|case
literal|42
case|:
comment|// expected-error {{duplicate case value '42'}}
empty_stmt|;
case|case
literal|100
operator|...
literal|99
case|:
empty_stmt|;
comment|// expected-warning {{empty case range}}
case|case
literal|43
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|43
operator|...
literal|45
case|:
empty_stmt|;
comment|// expected-error {{duplicate case value}}
case|case
literal|100
operator|...
literal|20000
case|:
empty_stmt|;
comment|// expected-note {{previous case}}
case|case
literal|15000
operator|...
literal|40000000
case|:
empty_stmt|;
comment|// expected-error {{duplicate case value}}
block|}
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|void
parameter_list|)
block|{
comment|// empty switch;
switch|switch
condition|(
literal|0
condition|)
empty_stmt|;
comment|// expected-warning {{no case matching constant switch condition '0'}} \
comment|// expected-warning {{switch statement has empty body}} \
comment|// expected-note{{put the semicolon on a separate line to silence this warning}}
block|}
end_function

begin_function_decl
specifier|extern
name|int
name|g
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|test4
parameter_list|()
block|{
name|int
name|cond
decl_stmt|;
switch|switch
condition|(
name|cond
condition|)
block|{
case|case
literal|0
operator|&&
name|g
argument_list|()
case|:
case|case
literal|1
operator|||
name|g
argument_list|()
case|:
break|break;
block|}
switch|switch
condition|(
name|cond
condition|)
block|{
case|case
name|g
argument_list|()
case|:
comment|// expected-error {{expression is not an integer constant expression}}
case|case
literal|0
operator|...
name|g
argument_list|()
case|:
comment|// expected-error {{expression is not an integer constant expression}}
break|break;
block|}
switch|switch
condition|(
name|cond
condition|)
block|{
case|case
literal|0
operator|&&
name|g
argument_list|()
operator|...
literal|1
operator|||
name|g
argument_list|()
case|:
break|break;
block|}
switch|switch
condition|(
name|cond
condition|)
block|{
case|case
name|g
argument_list|()
comment|// expected-error {{expression is not an integer constant expression}}
operator|&&
literal|0
case|:
break|break;
block|}
switch|switch
condition|(
name|cond
condition|)
block|{
case|case
literal|0
operator|...
name|g
argument_list|()
comment|// expected-error {{expression is not an integer constant expression}}
operator|||
literal|1
case|:
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test5
parameter_list|(
name|int
name|z
parameter_list|)
block|{
switch|switch
condition|(
name|z
condition|)
block|{
default|default:
comment|// expected-note {{previous case defined here}}
default|default:
comment|// expected-error {{multiple default labels in one switch}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|()
block|{
name|char
name|ch
init|=
literal|'a'
decl_stmt|;
switch|switch
condition|(
name|ch
condition|)
block|{
case|case
literal|1234
case|:
comment|// expected-warning {{overflow converting case value}}
break|break;
block|}
block|}
end_function

begin_comment
comment|// PR5606
end_comment

begin_function
name|int
name|f0
parameter_list|(
name|int
name|var
parameter_list|)
block|{
switch|switch
condition|(
name|va
condition|)
block|{
comment|// expected-error{{use of undeclared identifier 'va'}}
case|case
literal|1
case|:
break|break;
case|case
literal|2
case|:
return|return
literal|1
return|;
block|}
return|return
literal|2
return|;
block|}
end_function

begin_function
name|void
name|test7
parameter_list|()
block|{
enum|enum
block|{
name|A
init|=
literal|1
block|,
name|B
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
comment|//expected-warning{{enumeration value 'B' not handled in switch}}
case|case
name|A
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|B
case|:
case|case
name|A
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
case|case
name|B
case|:
case|case
literal|3
case|:
comment|// expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
case|case
name|B
case|:
case|case
literal|3
operator|...
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
literal|4
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|1
operator|...
literal|2
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|0
operator|...
literal|2
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|1
operator|...
literal|3
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|0
operator|...
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
literal|3
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
enum|enum
block|{
name|A
block|,
name|B
block|,
name|C
init|=
literal|1
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
case|case
name|B
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
case|case
name|C
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
comment|//expected-warning{{enumeration value 'B' not handled in switch}}
case|case
name|A
case|:
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test9
parameter_list|()
block|{
enum|enum
block|{
name|A
init|=
literal|3
block|,
name|C
init|=
literal|1
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|0
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
case|case
literal|1
case|:
case|case
literal|2
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
case|case
literal|3
case|:
case|case
literal|4
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test10
parameter_list|()
block|{
enum|enum
block|{
name|A
init|=
literal|10
block|,
name|C
init|=
literal|2
block|,
name|B
init|=
literal|4
block|,
name|D
init|=
literal|12
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
literal|0
operator|...
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
literal|1
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
case|case
literal|2
operator|...
literal|4
case|:
case|case
literal|5
operator|...
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
literal|9
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
case|case
literal|10
operator|...
literal|12
case|:
case|case
literal|13
operator|...
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
literal|16
case|:
comment|//expected-warning{{case value not in enumerated type 'enum (anonymous enum}}
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test11
parameter_list|()
block|{
enum|enum
block|{
name|A
init|=
operator|-
literal|1
block|,
name|B
block|,
name|C
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
comment|//expected-warning{{enumeration value 'A' not handled in switch}}
case|case
name|B
case|:
case|case
name|C
case|:
break|break;
block|}
switch|switch
condition|(
name|a
condition|)
block|{
comment|//expected-warning{{enumeration value 'A' not explicitly handled in switch}}
case|case
name|B
case|:
case|case
name|C
case|:
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test12
parameter_list|()
block|{
enum|enum
block|{
name|A
init|=
operator|-
literal|1
block|,
name|B
init|=
literal|4294967286
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
case|case
name|B
case|:
break|break;
block|}
block|}
end_function

begin_comment
comment|//<rdar://problem/7643909>
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|val1
block|,
name|val2
block|,
name|val3
block|}
name|my_type_t
typedef|;
end_typedef

begin_function
name|int
name|test13
parameter_list|(
name|my_type_t
name|t
parameter_list|)
block|{
switch|switch
condition|(
name|t
condition|)
block|{
comment|// expected-warning{{enumeration value 'val3' not handled in switch}}
case|case
name|val1
case|:
return|return
literal|1
return|;
case|case
name|val2
case|:
return|return
literal|2
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|//<rdar://problem/7658121>
end_comment

begin_enum
enum|enum
block|{
name|EC0
init|=
literal|0xFFFF0000
block|,
name|EC1
init|=
literal|0xFFFF0001
block|, }
enum|;
end_enum

begin_function
name|int
name|test14
parameter_list|(
name|int
name|a
parameter_list|)
block|{
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|EC0
case|:
return|return
literal|0
return|;
case|case
name|EC1
case|:
return|return
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
name|void
name|f1
parameter_list|(
name|unsigned
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
operator|-
literal|1
case|:
break|break;
default|default:
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test15
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
literal|1
condition|)
block|{
comment|// expected-warning {{no case matching constant switch condition '1'}}
case|case
literal|0
case|:
name|i
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|i
operator|++
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
name|void
name|test16
parameter_list|()
block|{
specifier|const
name|char
name|c
init|=
literal|'5'
decl_stmt|;
switch|switch
condition|(
name|c
condition|)
block|{
comment|// expected-warning {{no case matching constant switch condition '53'}}
case|case
literal|'6'
case|:
return|return;
block|}
block|}
end_function

begin_comment
comment|// PR7359
end_comment

begin_function
name|void
name|test17
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
operator|>=
literal|17
condition|)
block|{
comment|// expected-warning {{switch condition has boolean value}}
case|case
literal|0
case|:
return|return;
block|}
switch|switch
condition|(
call|(
name|int
call|)
argument_list|(
name|x
operator|<=
literal|17
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
return|return;
block|}
block|}
end_function

begin_function
name|int
name|test18
parameter_list|()
block|{
enum|enum
block|{
name|A
block|,
name|B
block|}
name|a
enum|;
switch|switch
condition|(
name|a
condition|)
block|{
case|case
name|A
case|:
return|return
literal|0
return|;
case|case
name|B
case|:
return|return
literal|1
return|;
case|case
literal|7
case|:
return|return
literal|1
return|;
comment|// expected-warning {{case value not in enumerated type}}
default|default:
return|return
literal|2
return|;
comment|// expected-warning {{default label in switch which covers all enumeration values}}
block|}
block|}
end_function

begin_comment
comment|// rdar://110822110
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|kOne
init|=
literal|1
block|, }
name|Ints
typedef|;
end_typedef

begin_function
name|void
name|rdar110822110
parameter_list|(
name|Ints
name|i
parameter_list|)
block|{
switch|switch
condition|(
name|i
condition|)
block|{
case|case
name|kOne
case|:
break|break;
case|case
literal|2
case|:
comment|// expected-warning {{case value not in enumerated type 'Ints'}}
break|break;
default|default:
comment|// expected-warning {{default label in switch which covers all enumeration values}}
break|break;
block|}
block|}
end_function

begin_comment
comment|// PR9243
end_comment

begin_define
define|#
directive|define
name|TEST19MACRO
value|5
end_define

begin_function
name|void
name|test19
parameter_list|(
name|int
name|i
parameter_list|)
block|{
enum|enum
block|{
name|kTest19Enum1
init|=
literal|7
block|,
name|kTest19Enum2
init|=
name|kTest19Enum1
block|}
enum|;
specifier|const
name|int
name|a
init|=
literal|3
decl_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
literal|5
case|:
comment|// expected-note {{previous case}}
case|case
name|TEST19MACRO
case|:
comment|// expected-error {{duplicate case value '5'}}
case|case
literal|7
case|:
comment|// expected-note {{previous case}}
case|case
name|kTest19Enum1
case|:
comment|// expected-error {{duplicate case value: '7' and 'kTest19Enum1' both equal '7'}} \
comment|// expected-note {{previous case}}
case|case
name|kTest19Enum1
case|:
comment|// expected-error {{duplicate case value 'kTest19Enum1'}} \
comment|// expected-note {{previous case}}
case|case
name|kTest19Enum2
case|:
comment|// expected-error {{duplicate case value: 'kTest19Enum1' and 'kTest19Enum2' both equal '7'}} \
comment|// expected-note {{previous case}}
case|case
operator|(
name|int
operator|)
name|kTest19Enum2
case|:
comment|//expected-error {{duplicate case value 'kTest19Enum2'}}
case|case
literal|3
case|:
comment|// expected-note {{previous case}}
case|case
name|a
case|:
comment|// expected-error {{duplicate case value: '3' and 'a' both equal '3'}} \
comment|// expected-note {{previous case}}
case|case
name|a
case|:
comment|// expected-error {{duplicate case value 'a'}}
break|break;
block|}
block|}
end_function

begin_comment
comment|// Allow the warning 'case value not in enumerated type' to be silenced with
end_comment

begin_comment
comment|// the following pattern.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// If 'case' expression refers to a static const variable of the correct enum
end_comment

begin_comment
comment|// type, then we count this as a sufficient declaration of intent by the user,
end_comment

begin_comment
comment|// so we silence the warning.
end_comment

begin_enum
enum|enum
name|ExtendedEnum1
block|{
name|EE1_a
block|,
name|EE1_b
block|}
enum|;
end_enum

begin_enum
enum|enum
name|ExtendedEnum1_unrelated
block|{
name|EE1_misc
block|}
enum|;
end_enum

begin_decl_stmt
specifier|static
specifier|const
name|enum
name|ExtendedEnum1
name|EE1_c
init|=
literal|100
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|enum
name|ExtendedEnum1_unrelated
name|EE1_d
init|=
literal|101
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|switch_on_ExtendedEnum1
parameter_list|(
name|enum
name|ExtendedEnum1
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
condition|)
block|{
case|case
name|EE1_a
case|:
break|break;
case|case
name|EE1_b
case|:
break|break;
case|case
name|EE1_c
case|:
break|break;
comment|// no-warning
case|case
name|EE1_d
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type 'enum ExtendedEnum1'}}
block|}
block|}
end_function

end_unit

