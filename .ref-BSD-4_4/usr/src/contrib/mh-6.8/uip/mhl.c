begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mhl.c - the MH message listing program */
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
literal|"@(#)$Id: mhl.c,v 1.3 1992/12/15 00:20:22 jromine Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LOCALE
end_ifdef

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|LOCALE
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|done
argument_list|(
name|mhl
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* Cheat:  we are loaded with adrparse, which wants a routine called    OfficialName().  We call adrparse:getm() with the correct arguments    to prevent OfficialName() from being called.  Hence, the following    is to keep the loader happy.  */
end_comment

begin_function
name|char
modifier|*
name|OfficialName
parameter_list|(
name|name
parameter_list|)
specifier|register
name|char
modifier|*
name|name
decl_stmt|;
block|{
return|return
name|name
return|;
block|}
end_function

end_unit

