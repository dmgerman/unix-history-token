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

begin_comment
comment|/* NOTE:  This geline function is different from _IO_getline.  */
end_comment

begin_function
name|_IO_ssize_t
name|getline
parameter_list|(
name|lineptr
parameter_list|,
name|linelen
parameter_list|,
name|fp
parameter_list|)
name|char
modifier|*
modifier|*
name|lineptr
decl_stmt|;
name|size_t
modifier|*
name|linelen
decl_stmt|;
name|FILE
modifier|*
name|fp
decl_stmt|;
block|{
return|return
name|_IO_getdelim
argument_list|(
name|lineptr
argument_list|,
name|linelen
argument_list|,
literal|'\n'
argument_list|,
name|fp
argument_list|)
return|;
block|}
end_function

end_unit

