begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only
end_comment

begin_typedef
typedef|typedef
name|short
name|short_fixed
typedef|;
end_typedef

begin_enum
enum|enum
block|{
comment|// 8.8 short_fixed
name|SHORT_FIXED_FRACTIONAL_BITS
init|=
literal|8
block|,
name|SHORT_FIXED_ONE
init|=
literal|1
operator|<<
name|SHORT_FIXED_FRACTIONAL_BITS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FLOAT_TO_SHORT_FIXED
parameter_list|(
name|f
parameter_list|)
value|((short_fixed)((f)*SHORT_FIXED_ONE))
end_define

begin_enum
enum|enum
block|{
name|SOME_VALUE
init|=
name|FLOAT_TO_SHORT_FIXED
argument_list|(
literal|0.1
argument_list|)
comment|// expected-warning{{expression is not integer constant expression}}
block|}
enum|;
end_enum

end_unit

