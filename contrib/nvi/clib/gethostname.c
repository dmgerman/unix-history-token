begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/*  * Solaris doesn't include the gethostname call by default.  */
end_comment

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_include
include|#
directive|include
file|<sys/systeminfo.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_comment
comment|/*  * PUBLIC: #ifndef HAVE_GETHOSTNAME  * PUBLIC: int gethostname __P((char *, int));  * PUBLIC: #endif  */
end_comment

begin_function
name|int
name|gethostname
parameter_list|(
name|host
parameter_list|,
name|len
parameter_list|)
name|char
modifier|*
name|host
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
return|return
operator|(
name|sysinfo
argument_list|(
name|SI_HOSTNAME
argument_list|,
name|host
argument_list|,
name|len
argument_list|)
operator|==
operator|-
literal|1
condition|?
operator|-
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

end_unit

