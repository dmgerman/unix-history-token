begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)roll.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  *	This routine rolls ndie nside-sided dice.  */
end_comment

begin_define
define|#
directive|define
name|reg
value|register
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|vax
end_ifndef

begin_define
define|#
directive|define
name|MAXRAND
value|32767L
end_define

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|long
name|tot
decl_stmt|;
name|reg
name|unsigned
name|n
decl_stmt|,
name|r
decl_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
name|n
operator|=
name|ndie
expr_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
name|tot
operator|+=
name|rand
argument_list|()
expr_stmt|;
return|return
call|(
name|int
call|)
argument_list|(
operator|(
name|tot
operator|*
operator|(
name|long
operator|)
name|nsides
operator|)
operator|/
operator|(
operator|(
name|long
operator|)
name|MAXRAND
operator|+
literal|1
operator|)
argument_list|)
operator|+
name|ndie
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|roll
argument_list|(
argument|ndie
argument_list|,
argument|nsides
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|int
name|ndie
decl_stmt|,
name|nsides
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|reg
name|int
name|tot
decl_stmt|,
name|r
decl_stmt|;
name|reg
name|double
name|num_sides
decl_stmt|;
name|num_sides
operator|=
name|nsides
expr_stmt|;
name|tot
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|ndie
operator|--
condition|)
name|tot
operator|+=
operator|(
name|r
operator|=
name|rand
argument_list|()
operator|)
operator|*
operator|(
name|num_sides
operator|/
literal|017777777777
operator|)
operator|+
literal|1
expr_stmt|;
return|return
name|tot
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

