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
file|<algorithm>
end_include

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
name|public
operator|:
name|hexfloat
argument_list|(
argument|long long m1
argument_list|,
argument|unsigned long long m0
argument_list|,
argument|int exp
argument_list|)
block|{
specifier|const
name|std
operator|::
name|size_t
name|n
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
name|int
name|s
operator|=
name|m1
operator|<
literal|0
condition|?
operator|-
literal|1
else|:
literal|1
block|;
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
operator|-
name|static_cast
operator|<
name|int
operator|>
operator|(
name|n
operator|-
name|std
operator|::
name|__clz
argument_list|(
name|m0
argument_list|)
operator|/
literal|4
operator|*
literal|4
operator|)
argument_list|)
argument_list|,
name|exp
argument_list|)
block|;     }
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

