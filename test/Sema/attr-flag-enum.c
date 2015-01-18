begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -std=c11 -Wassign-enum %s
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|flag_enum
operator|)
argument_list|)
name|flag
block|{
name|ea
operator|=
literal|0x1
operator|,
name|eb
operator|=
literal|0x2
operator|,
name|ec
operator|=
literal|0x8
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|flag_enum
operator|)
argument_list|)
name|flag2
block|{
name|ga
operator|=
literal|0x1
operator|,
name|gb
operator|=
literal|0x4
operator|,
name|gc
operator|=
literal|0x5
operator|,
comment|// no-warning
name|gd
operator|=
literal|0x7
operator|,
comment|// expected-warning {{enumeration value 'gd' is out of range}}
name|ge
operator|=
operator|~
literal|0x2
operator|,
comment|// expected-warning {{enumeration value 'ge' is out of range}}
name|gf
operator|=
operator|~
literal|0x4
operator|,
comment|// no-warning
name|gg
operator|=
operator|~
literal|0x1
operator|,
comment|// no-warning
name|gh
operator|=
operator|~
literal|0x5
operator|,
comment|// no-warning
name|gi
operator|=
operator|~
literal|0x11
operator|,
comment|// expected-warning {{enumeration value 'gi' is out of range}}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|flag_enum
operator|)
argument_list|)
name|flag3
block|{
name|fa
operator|=
literal|0x1
operator|,
name|fb
operator|=
operator|~
literal|0x1u
operator|,
comment|// no-warning
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// What happens here is that ~0x2 is negative, and so the enum must be signed.
end_comment

begin_comment
comment|// But ~0x1u is unsigned and has the high bit set, so the enum must be 64-bit.
end_comment

begin_comment
comment|// The result is that ~0x1u does not have high bits set, and so it is considered
end_comment

begin_comment
comment|// to be an invalid value. See Sema::IsValueInFlagEnum in SemaDecl.cpp for more
end_comment

begin_comment
comment|// discussion.
end_comment

begin_decl_stmt
name|enum
name|__attribute__
argument_list|(
operator|(
name|flag_enum
operator|)
argument_list|)
name|flag4
block|{
name|ha
operator|=
literal|0x1
operator|,
name|hb
operator|=
literal|0x2
operator|,
name|hc
operator|=
operator|~
literal|0x1u
operator|,
comment|// expected-warning {{enumeration value 'hc' is out of range}}
name|hd
operator|=
operator|~
literal|0x2
operator|,
comment|// no-warning
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
name|void
name|f
parameter_list|(
name|void
parameter_list|)
block|{
name|enum
name|flag
name|e
init|=
literal|0
decl_stmt|;
comment|// no-warning
name|e
operator|=
literal|0x1
expr_stmt|;
comment|// no-warning
name|e
operator|=
literal|0x3
expr_stmt|;
comment|// no-warning
name|e
operator|=
literal|0xa
expr_stmt|;
comment|// no-warning
name|e
operator|=
literal|0x4
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type}}
name|e
operator|=
literal|0xf
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type}}
name|e
operator|=
operator|~
literal|0
expr_stmt|;
comment|// no-warning
name|e
operator|=
operator|~
literal|0x1
expr_stmt|;
comment|// no-warning
name|e
operator|=
operator|~
literal|0x2
expr_stmt|;
comment|// no-warning
name|e
operator|=
operator|~
literal|0x3
expr_stmt|;
comment|// no-warning
name|e
operator|=
operator|~
literal|0x4
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type}}
switch|switch
condition|(
name|e
condition|)
block|{
case|case
literal|0
case|:
break|break;
comment|// no-warning
case|case
literal|0x1
case|:
break|break;
comment|// no-warning
case|case
literal|0x3
case|:
break|break;
comment|// no-warning
case|case
literal|0xa
case|:
break|break;
comment|// no-warning
case|case
literal|0x4
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
literal|0xf
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
operator|~
literal|0
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
operator|~
literal|0x1
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
operator|~
literal|0x2
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
operator|~
literal|0x3
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
case|case
operator|~
literal|0x4
case|:
break|break;
comment|// expected-warning {{case value not in enumerated type}}
default|default:
break|break;
block|}
name|enum
name|flag2
name|f
init|=
operator|~
literal|0x1
decl_stmt|;
comment|// no-warning
name|f
operator|=
operator|~
literal|0x1u
expr_stmt|;
comment|// no-warning
name|enum
name|flag4
name|h
init|=
operator|~
literal|0x1
decl_stmt|;
comment|// no-warning
name|h
operator|=
operator|~
literal|0x1u
expr_stmt|;
comment|// expected-warning {{integer constant not in range of enumerated type}}
block|}
end_function

end_unit

