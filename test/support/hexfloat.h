begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Define a hexfloat literal emulator since we can't depend on being able to
end_comment

begin_comment
comment|//   for hexfloat literals
end_comment

begin_comment
comment|// 0x10.F5p-10 == hexfloat<double>(0x10, 0xF5, -10)
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEXFLOAT_H
end_ifndef

begin_define
define|#
directive|define
name|HEXFLOAT_H
end_define

begin_include
include|#
directive|include
file|<cmath>
end_include

begin_include
include|#
directive|include
file|<climits>
end_include

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|hexfloat
block|{
name|T
name|value_
block|;
specifier|static
name|int
name|CountLeadingZeros
argument_list|(
argument|unsigned long long n
argument_list|)
block|{
specifier|const
name|std
operator|::
name|size_t
name|Digits
operator|=
expr|sizeof
operator|(
name|unsigned
name|long
name|long
operator|)
operator|*
name|CHAR_BIT
block|;
specifier|const
name|unsigned
name|long
name|long
name|TopBit
operator|=
literal|1ull
operator|<<
operator|(
name|Digits
operator|-
literal|1
operator|)
block|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return
name|Digits
return|;
name|int
name|LeadingZeros
operator|=
literal|0
block|;
while|while
condition|(
operator|(
name|n
operator|&
name|TopBit
operator|)
operator|==
literal|0
condition|)
block|{
operator|++
name|LeadingZeros
expr_stmt|;
name|n
operator|<<=
literal|1
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
name|LeadingZeros
return|;
end_return

begin_macro
unit|}  public:
name|hexfloat
argument_list|(
argument|long long m1
argument_list|,
argument|unsigned long long m0
argument_list|,
argument|int exp
argument_list|)
end_macro

begin_block
block|{
specifier|const
name|std
operator|::
name|size_t
name|Digits
operator|=
expr|sizeof
operator|(
name|unsigned
name|long
name|long
operator|)
operator|*
name|CHAR_BIT
expr_stmt|;
name|int
name|s
init|=
name|m1
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
decl_stmt|;
name|int
name|exp2
init|=
operator|-
name|static_cast
operator|<
name|int
operator|>
operator|(
name|Digits
operator|-
name|CountLeadingZeros
argument_list|(
name|m0
argument_list|)
operator|/
literal|4
operator|*
literal|4
operator|)
decl_stmt|;
name|value_
operator|=
name|std
operator|::
name|ldexp
argument_list|(
name|m1
operator|+
name|s
operator|*
name|std
operator|::
name|ldexp
argument_list|(
name|T
argument_list|(
name|m0
argument_list|)
argument_list|,
name|exp2
argument_list|)
argument_list|,
name|exp
argument_list|)
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|operator
name|T
argument_list|()
specifier|const
block|{
return|return
name|value_
return|;
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

end_unit

