begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * mkversion.c  *  * By Ross Ridge  * Public Domain   * 92/02/01 07:30:09  *  * generates version.c  *  */
end_comment

begin_define
define|#
directive|define
name|NOTLIB
end_define

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_decl_stmt
specifier|const
name|char
name|SCCSid
index|[]
init|=
literal|"@(#) mytinfo mkversion.c 3.2 92/02/01 public domain, By Ross Ridge"
decl_stmt|;
end_decl_stmt

begin_function
name|int
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
name|puts
argument_list|(
literal|"/*"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" * version.c "
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" *"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" * This file was generated automatically."
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" *"
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|" */"
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"char _mytinfo_version[] = \"@(#) mytinfo: Release %d, Patchlevel %d (ache).\";\n"
argument_list|,
name|RELEASE
argument_list|,
name|PATCHLEVEL
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

