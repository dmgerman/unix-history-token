begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * ====================================================  * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.  *  * Developed at SunPro, a Sun Microsystems, Inc. business.  * Permission to use, copy, modify, and distribute this  * software is freely granted, provided that this notice  * is preserved.  * ====================================================  *  * k_sinf.c and k_cosf.c merged by Steven G. Kargl.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* |sin(x)/x - s(x)|< 2**-37.5 (~[-4.89e-12, 4.824e-12]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|S1
init|=
operator|-
literal|0x15555554cbac77
literal|.0p
operator|-
literal|55
decl_stmt|,
comment|/* -0.166666666416265235595 */
name|S2
init|=
literal|0x111110896efbb2
literal|.0p
operator|-
literal|59
decl_stmt|,
comment|/*  0.0083333293858894631756 */
name|S3
init|=
operator|-
literal|0x1a00f9e2cae774
literal|.0p
operator|-
literal|65
decl_stmt|,
comment|/* -0.000198393348360966317347 */
name|S4
init|=
literal|0x16cd878c3b46a7
literal|.0p
operator|-
literal|71
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.0000027183114939898219064 */
end_comment

begin_comment
comment|/* |cos(x) - c(x)|< 2**-34.1 (~[-5.37e-11, 5.295e-11]). */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|double
name|C0
init|=
operator|-
literal|0x1ffffffd0c5e81
literal|.0p
operator|-
literal|54
decl_stmt|,
comment|/* -0.499999997251031003120 */
name|C1
init|=
literal|0x155553e1053a42
literal|.0p
operator|-
literal|57
decl_stmt|,
comment|/*  0.0416666233237390631894 */
name|C2
init|=
operator|-
literal|0x16c087e80f1e27
literal|.0p
operator|-
literal|62
decl_stmt|,
comment|/* -0.00138867637746099294692 */
name|C3
init|=
literal|0x199342e0ee5069
literal|.0p
operator|-
literal|68
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  0.0000243904487962774090654 */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|__kernel_sincosdf
parameter_list|(
name|double
name|x
parameter_list|,
name|float
modifier|*
name|sn
parameter_list|,
name|float
modifier|*
name|cs
parameter_list|)
block|{
name|double
name|r
decl_stmt|,
name|s
decl_stmt|,
name|w
decl_stmt|,
name|z
decl_stmt|;
name|z
operator|=
name|x
operator|*
name|x
expr_stmt|;
name|w
operator|=
name|z
operator|*
name|z
expr_stmt|;
name|r
operator|=
name|S3
operator|+
name|z
operator|*
name|S4
expr_stmt|;
name|s
operator|=
name|z
operator|*
name|x
expr_stmt|;
operator|*
name|sn
operator|=
operator|(
name|x
operator|+
name|s
operator|*
operator|(
name|S1
operator|+
name|z
operator|*
name|S2
operator|)
operator|)
operator|+
name|s
operator|*
name|w
operator|*
name|r
expr_stmt|;
name|r
operator|=
name|C2
operator|+
name|z
operator|*
name|C3
expr_stmt|;
operator|*
name|cs
operator|=
operator|(
operator|(
literal|1
operator|+
name|z
operator|*
name|C0
operator|)
operator|+
name|w
operator|*
name|C1
operator|)
operator|+
operator|(
name|w
operator|*
name|z
operator|)
operator|*
name|r
expr_stmt|;
block|}
end_function

end_unit

