begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<regexp.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_function
name|void
name|regerror
parameter_list|(
name|s
parameter_list|)
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|ERRAVAIL
name|error
argument_list|(
literal|"regexp: %s"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* 	fprintf(stderr, "regexp(3): %s\n", s); 	exit(1); */
return|return;
comment|/* let std. egrep handle errors */
endif|#
directive|endif
comment|/* NOTREACHED */
block|}
end_function

end_unit

