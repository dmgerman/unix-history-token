begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_RCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_RCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|__progname
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|setprogname
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|strrchr
argument_list|(
name|progname
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
name|__progname
operator|=
name|p
condition|?
name|p
operator|+
literal|1
else|:
name|progname
expr_stmt|;
block|}
end_function

end_unit

