begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|LINT
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$Id: ftruncate.c,v 1.1 2001/03/29 06:30:32 marka Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * ftruncate - set file size, BSD Style  *  * shortens or enlarges the file as neeeded  * uses some undocumented locking call. It is known to work on SCO unix,  * other vendors should try.  * The #error directive prevents unsupported OSes  */
end_comment

begin_include
include|#
directive|include
file|"port_before.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|M_UNIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|OWN_FTRUNCATE
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_XOPEN_SOURCE
end_ifdef

begin_undef
undef|#
directive|undef
name|_XOPEN_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SOURCE
end_ifdef

begin_undef
undef|#
directive|undef
name|_POSIX_SOURCE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|"port_after.h"
end_include

begin_function
name|int
name|__ftruncate
parameter_list|(
name|int
name|fd
parameter_list|,
name|long
name|wantsize
parameter_list|)
block|{
name|long
name|cursize
decl_stmt|;
comment|/* determine current file size */
if|if
condition|(
operator|(
name|cursize
operator|=
name|lseek
argument_list|(
name|fd
argument_list|,
literal|0L
argument_list|,
literal|2
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* maybe lengthen... */
if|if
condition|(
name|cursize
operator|<
name|wantsize
condition|)
block|{
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
name|wantsize
operator|-
literal|1
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
operator|||
name|write
argument_list|(
name|fd
argument_list|,
literal|""
argument_list|,
literal|1
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* maybe shorten... */
if|if
condition|(
name|wantsize
operator|<
name|cursize
condition|)
block|{
name|struct
name|flock
name|fl
decl_stmt|;
name|fl
operator|.
name|l_whence
operator|=
literal|0
expr_stmt|;
name|fl
operator|.
name|l_len
operator|=
literal|0
expr_stmt|;
name|fl
operator|.
name|l_start
operator|=
name|wantsize
expr_stmt|;
name|fl
operator|.
name|l_type
operator|=
name|F_WRLCK
expr_stmt|;
return|return
operator|(
name|fcntl
argument_list|(
name|fd
argument_list|,
name|F_FREESP
argument_list|,
operator|&
name|fl
argument_list|)
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OWN_FTRUNCATE
end_ifndef

begin_decl_stmt
name|int
name|__bindcompat_ftruncate
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

