begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* trimcpy.c - strip [lt]wsp and replace newlines with spaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|ident
index|[]
init|=
literal|"@(#)$Id: trimcpy.c,v 1.3 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*        lint */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|trimcpy
parameter_list|(
name|cp
parameter_list|)
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|sp
decl_stmt|;
while|while
condition|(
name|isspace
argument_list|(
operator|*
name|cp
argument_list|)
condition|)
name|cp
operator|++
expr_stmt|;
for|for
control|(
name|sp
operator|=
name|cp
operator|+
name|strlen
argument_list|(
name|cp
argument_list|)
operator|-
literal|1
init|;
name|sp
operator|>=
name|cp
condition|;
name|sp
operator|--
control|)
if|if
condition|(
name|isspace
argument_list|(
operator|*
name|sp
argument_list|)
condition|)
operator|*
name|sp
operator|=
literal|0
expr_stmt|;
else|else
break|break;
for|for
control|(
name|sp
operator|=
name|cp
init|;
operator|*
name|sp
condition|;
name|sp
operator|++
control|)
if|if
condition|(
name|isspace
argument_list|(
operator|*
name|sp
argument_list|)
condition|)
operator|*
name|sp
operator|=
literal|' '
expr_stmt|;
return|return
name|getcpy
argument_list|(
name|cp
argument_list|)
return|;
block|}
end_function

end_unit

