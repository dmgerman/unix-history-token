begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m_tmpfil.c - construct a temporary file */
end_comment

begin_include
include|#
directive|include
file|"../h/mh.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|char
modifier|*
name|m_tmpfil
parameter_list|(
name|template
parameter_list|)
specifier|register
name|char
modifier|*
name|template
decl_stmt|;
block|{
specifier|static
name|char
name|tmpfil
index|[
name|BUFSIZ
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|tmpfil
argument_list|,
literal|"/tmp/%sXXXXXX"
argument_list|,
name|template
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unlink
argument_list|(
name|mktemp
argument_list|(
name|tmpfil
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|tmpfil
return|;
block|}
end_function

end_unit

