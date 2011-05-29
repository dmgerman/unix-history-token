begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       tuklib_progname.c
end_comment

begin_comment
comment|/// \brief      Program name to be displayed in messages
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"tuklib_progname.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_if
if|#
directive|if
operator|!
name|HAVE_DECL_PROGRAM_INVOCATION_NAME
end_if

begin_decl_stmt
name|char
modifier|*
name|progname
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|extern
name|void
name|tuklib_progname_init
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|TUKLIB_DOSLIKE
comment|// On these systems, argv[0] always has the full path and .exe
comment|// suffix even if the user just types the plain program name.
comment|// We modify argv[0] to make it nicer to read.
comment|// Strip the leading path.
name|char
modifier|*
name|p
init|=
name|argv
index|[
literal|0
index|]
operator|+
name|strlen
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
while|while
condition|(
name|argv
index|[
literal|0
index|]
operator|<
name|p
operator|&&
name|p
index|[
operator|-
literal|1
index|]
operator|!=
literal|'/'
operator|&&
name|p
index|[
operator|-
literal|1
index|]
operator|!=
literal|'\\'
condition|)
operator|--
name|p
expr_stmt|;
name|argv
index|[
literal|0
index|]
operator|=
name|p
expr_stmt|;
comment|// Strip the .exe suffix.
name|p
operator|=
name|strrchr
argument_list|(
name|p
argument_list|,
literal|'.'
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|!=
name|NULL
condition|)
operator|*
name|p
operator|=
literal|'\0'
expr_stmt|;
comment|// Make it lowercase.
for|for
control|(
name|p
operator|=
name|argv
index|[
literal|0
index|]
init|;
operator|*
name|p
operator|!=
literal|'\0'
condition|;
operator|++
name|p
control|)
if|if
condition|(
operator|*
name|p
operator|>=
literal|'A'
operator|&&
operator|*
name|p
operator|<=
literal|'Z'
condition|)
operator|*
name|p
operator|=
operator|*
name|p
operator|-
literal|'A'
operator|+
literal|'a'
expr_stmt|;
endif|#
directive|endif
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
return|return;
block|}
end_function

end_unit

