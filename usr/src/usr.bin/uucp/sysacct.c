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
literal|"@(#)sysacct.c	5.3 (Berkeley) 6/23/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	output accounting info  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|sysacct
argument_list|(
argument|bytes
argument_list|,
argument|time
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bytes
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return;
block|}
end_block

end_unit

