begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Some known programs (xterm, pdksh?) non-portably change the _file    field of s struct _iobuf.  This kludge allows the same "functionality".    This code is an undocumented feature for iostream/stdio. Use it at    your own risk. */
end_comment

begin_include
include|#
directive|include
file|"libioP.h"
end_include

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_function
name|void
name|setfileno
parameter_list|(
name|fp
parameter_list|,
name|fd
parameter_list|)
name|_IO_FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|fd
decl_stmt|;
block|{
name|CHECK_FILE
argument_list|(
name|fp
argument_list|, )
expr_stmt|;
if|if
condition|(
operator|(
name|fp
operator|->
name|_flags
operator|&
name|_IO_IS_FILEBUF
operator|)
operator|!=
literal|0
condition|)
name|fp
operator|->
name|_fileno
operator|=
name|fd
expr_stmt|;
block|}
end_function

end_unit

