begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** **  Editline system header file for Unix. */
end_comment

begin_define
define|#
directive|define
name|CRLF
value|"\r\n"
end_define

begin_define
define|#
directive|define
name|FORWARD
value|STATIC
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USE_DIRENT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|dirent
name|DIRENTRY
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|direct
name|DIRENTRY
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(USE_DIRENT) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|S_ISDIR
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|m
parameter_list|)
value|(((m)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(S_ISDIR) */
end_comment

end_unit

