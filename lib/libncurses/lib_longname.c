begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This work is copyrighted. See COPYRIGHT.OLD& COPYRIGHT.NEW for   * *  details. If they are missing then this copy is in violation of    * *  the copyright conditions.                                        */
end_comment

begin_comment
comment|/* **	lib_longname.c ** **	The routine longname(). ** */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"curses.priv.h"
end_include

begin_include
include|#
directive|include
file|<nterm.h>
end_include

begin_function
name|char
modifier|*
name|longname
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|MYTINFO
name|char
modifier|*
name|ptr
decl_stmt|;
endif|#
directive|endif
name|T
argument_list|(
operator|(
literal|"longname() called"
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|MYTINFO
return|return
name|cur_term
operator|->
name|name_long
return|;
else|#
directive|else
for|for
control|(
name|ptr
operator|=
name|ttytype
operator|+
name|strlen
argument_list|(
name|ttytype
argument_list|)
init|;
name|ptr
operator|>
name|ttytype
condition|;
name|ptr
operator|--
control|)
if|if
condition|(
operator|*
name|ptr
operator|==
literal|'|'
condition|)
return|return
operator|(
name|ptr
operator|+
literal|1
operator|)
return|;
return|return
operator|(
name|ttytype
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

