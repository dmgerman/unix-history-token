begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set up the global argc/argv info for use by getarg_, iargc_, and    g77's inlined intrinsic equivalents.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_decl_stmt
name|int
name|f__xargc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|f__xargv
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|f_setarg
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|f__xargc
operator|=
name|argc
expr_stmt|;
name|f__xargv
operator|=
name|argv
expr_stmt|;
block|}
end_function

end_unit

