begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)pow_ri.c	5.5 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|double
value|float
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tahoe */
end_comment

begin_function
name|float
name|pow_ri
parameter_list|(
name|ap
parameter_list|,
name|bp
parameter_list|)
name|float
modifier|*
name|ap
decl_stmt|;
name|long
modifier|*
name|bp
decl_stmt|;
block|{
specifier|register
name|long
name|n
init|=
operator|*
name|bp
decl_stmt|;
ifdef|#
directive|ifdef
name|tahoe
specifier|register
endif|#
directive|endif
comment|/* tahoe */
name|double
name|y
decl_stmt|,
name|x
init|=
operator|*
name|ap
decl_stmt|;
if|if
condition|(
operator|!
name|n
condition|)
return|return
operator|(
operator|(
name|double
operator|)
literal|1
operator|)
return|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
name|x
operator|=
operator|(
name|double
operator|)
literal|1
operator|/
name|x
expr_stmt|;
name|n
operator|=
operator|-
name|n
expr_stmt|;
block|}
while|while
condition|(
operator|!
operator|(
name|n
operator|&
literal|1
operator|)
condition|)
block|{
name|x
operator|*=
name|x
expr_stmt|;
name|n
operator|>>=
literal|1
expr_stmt|;
block|}
for|for
control|(
name|y
operator|=
name|x
init|;
operator|--
name|n
operator|>
literal|0
condition|;
name|y
operator|*=
name|x
control|)
while|while
condition|(
operator|!
operator|(
name|n
operator|&
literal|1
operator|)
condition|)
block|{
name|x
operator|*=
name|x
expr_stmt|;
name|n
operator|>>=
literal|1
expr_stmt|;
block|}
return|return
operator|(
name|y
operator|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_undef
undef|#
directive|undef
name|double
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tahoe */
end_comment

end_unit

