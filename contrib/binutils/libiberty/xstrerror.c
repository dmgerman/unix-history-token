begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* xstrerror.c -- jacket routine for more robust strerror() usage.    Fri Jun 16 18:30:00 1995  Pat Rankin<rankin@eql.caltech.edu>    This code is in the public domain.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|VMS
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__STRICT_ANSI__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__HIDE_FORBIDDEN_NAMES
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DONT_DECLARE_STRERROR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DONT_DECLARE_STRERROR
end_ifndef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strerror
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If strerror returns NULL, we'll format the number into a static buffer.  */
end_comment

begin_define
define|#
directive|define
name|ERRSTR_FMT
value|"undocumented error #%d"
end_define

begin_decl_stmt
specifier|static
name|char
name|xstrerror_buf
index|[
sizeof|sizeof
name|ERRSTR_FMT
operator|+
literal|20
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like strerror, but result is never a null pointer.  */
end_comment

begin_function
name|char
modifier|*
name|xstrerror
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
name|char
modifier|*
name|errstr
decl_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|char
operator|*
operator|(
operator|*
name|vmslib_strerror
operator|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
expr_stmt|;
comment|/* Override any possibly-conflicting declaration from system header.  */
name|vmslib_strerror
operator|=
operator|(
name|char
operator|*
operator|(
operator|*
operator|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
operator|...
operator|)
argument_list|)
operator|)
name|strerror
expr_stmt|;
comment|/* Second argument matters iff first is EVMSERR, but it's simpler to      pass it unconditionally.  `vaxc$errno' is declared in<errno.h>      and maintained by the run-time library in parallel to `errno'.      We assume that `errnum' corresponds to the last value assigned to      errno by the run-time library, hence vaxc$errno will be relevant.  */
name|errstr
operator|=
call|(
modifier|*
name|vmslib_strerror
call|)
argument_list|(
name|errnum
argument_list|,
name|vaxc$errno
argument_list|)
expr_stmt|;
else|#
directive|else
name|errstr
operator|=
name|strerror
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* If `errnum' is out of range, result might be NULL.  We'll fix that.  */
if|if
condition|(
operator|!
name|errstr
condition|)
block|{
name|sprintf
argument_list|(
name|xstrerror_buf
argument_list|,
name|ERRSTR_FMT
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
name|errstr
operator|=
name|xstrerror_buf
expr_stmt|;
block|}
return|return
name|errstr
return|;
block|}
end_function

end_unit

