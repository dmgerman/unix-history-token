begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)gethostname.c	8.1 (Berkeley) 4/13/94"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/* Solaris doesn't include the gethostname call by default. */
end_comment

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
operator|)
return|;
block|}
end_function

end_unit

