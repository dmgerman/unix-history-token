begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)lconv.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_decl_stmt
specifier|static
name|char
name|empty
index|[]
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Default (C) locale conversion.  */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|lconv
name|C_lconv
init|=
block|{
literal|"."
block|,
comment|/* decimal_point */
name|empty
block|,
comment|/* thousands_sep */
name|empty
block|,
comment|/* grouping */
name|empty
block|,
comment|/* int_curr_symbol */
name|empty
block|,
comment|/* currency_symbol */
name|empty
block|,
comment|/* mon_decimal_point */
name|empty
block|,
comment|/* mon_thousands_sep */
name|empty
block|,
comment|/* mon_grouping */
name|empty
block|,
comment|/* positive_sign */
name|empty
block|,
comment|/* negative_sign */
name|CHAR_MAX
block|,
comment|/* int_frac_digits */
name|CHAR_MAX
block|,
comment|/* frac_digits */
name|CHAR_MAX
block|,
comment|/* p_cs_precedes */
name|CHAR_MAX
block|,
comment|/* p_sep_by_space */
name|CHAR_MAX
block|,
comment|/* n_cs_precedes */
name|CHAR_MAX
block|,
comment|/* n_sep_by_space */
name|CHAR_MAX
block|,
comment|/* p_sign_posn */
name|CHAR_MAX
block|,
comment|/* n_sign_posn */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Current locale conversion.  */
end_comment

begin_decl_stmt
name|struct
name|lconv
modifier|*
name|__lconv
init|=
operator|&
name|C_lconv
decl_stmt|;
end_decl_stmt

end_unit

