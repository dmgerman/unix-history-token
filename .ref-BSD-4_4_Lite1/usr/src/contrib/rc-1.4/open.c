begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* open.c: to insulate<fcntl.h> from the rest of rc. */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|"rc.h"
end_include

begin_comment
comment|/* prototype for open() follows. comment out if necessary */
end_comment

begin_comment
comment|/*extern int open(const char *, int,...);*/
end_comment

begin_comment
comment|/*    Opens a file with the necessary flags. Assumes the following    declaration for redirtype:  	enum redirtype { 		rFrom, rCreate, rAppend, rHeredoc, rHerestring 	}; */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|int
name|mode_masks
index|[]
init|=
block|{
comment|/* rFrom */
name|O_RDONLY
block|,
comment|/* rCreate */
name|O_TRUNC
operator||
name|O_CREAT
operator||
name|O_WRONLY
block|,
comment|/* rAppend */
name|O_APPEND
operator||
name|O_CREAT
operator||
name|O_WRONLY
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|extern
name|int
name|rc_open
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|redirtype
name|m
parameter_list|)
block|{
if|if
condition|(
operator|(
name|unsigned
operator|)
name|m
operator|>=
name|arraysize
argument_list|(
name|mode_masks
argument_list|)
condition|)
name|panic
argument_list|(
literal|"bad mode passed to rc_open"
argument_list|)
expr_stmt|;
return|return
name|open
argument_list|(
name|name
argument_list|,
name|mode_masks
index|[
name|m
index|]
argument_list|,
literal|0666
argument_list|)
return|;
block|}
end_function

end_unit

