begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|FILE
modifier|*
name|popen
parameter_list|(
name|command
parameter_list|,
name|mode
parameter_list|)
specifier|const
name|char
modifier|*
name|command
decl_stmt|;
specifier|const
name|char
modifier|*
name|mode
decl_stmt|;
block|{
return|return
name|_IO_popen
argument_list|(
name|command
argument_list|,
name|mode
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|pclose
parameter_list|(
name|fp
parameter_list|)
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
if|#
directive|if
literal|0
comment|/* Does not actually test that stream was created by popen(). Instead,      it depends on the filebuf::sys_close() virtual to Do The Right Thing. */
block|if (fp is not a proc_file)     return -1;
endif|#
directive|endif
return|return
name|_IO_fclose
argument_list|(
name|fp
argument_list|)
return|;
block|}
end_function

end_unit

