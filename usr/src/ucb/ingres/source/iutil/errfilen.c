begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<aux.h>
end_include

begin_include
include|#
directive|include
file|<version.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)errfilen.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* ** Errfilen() -- Returns the pathname where the error file can be found ** **	It is assumed that the error digit cannot be more than 999 */
end_comment

begin_function
name|char
modifier|*
name|errfilen
parameter_list|(
name|digit
parameter_list|)
name|int
name|digit
decl_stmt|;
block|{
specifier|extern
name|char
modifier|*
name|ztack
argument_list|()
decl_stmt|,
modifier|*
name|iocv
argument_list|()
decl_stmt|;
return|return
operator|(
name|ztack
argument_list|(
name|ztack
argument_list|(
name|ztack
argument_list|(
name|ztack
argument_list|(
name|Pathname
argument_list|,
literal|"/files/error"
argument_list|)
argument_list|,
name|VERSION
argument_list|)
argument_list|,
literal|"_"
argument_list|)
argument_list|,
name|iocv
argument_list|(
name|digit
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

