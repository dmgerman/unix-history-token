begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.1 $ ** **  Encapsulate dirent/direct differences. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DIR_DIRENT
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DIR_DIRENT) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DIR_DIRECT
argument_list|)
end_if

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
comment|/* defined(DIR_DIRECT) */
end_comment

end_unit

