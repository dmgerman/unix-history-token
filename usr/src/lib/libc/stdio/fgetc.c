begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)fgetc.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|fgetc
argument_list|(
argument|fp
argument_list|)
end_macro

begin_decl_stmt
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|getc
argument_list|(
name|fp
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

