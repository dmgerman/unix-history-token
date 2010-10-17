begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* The<dir.h> header gives the layout of a directory. */
end_comment

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_ifndef
ifndef|#
directive|ifndef
name|_DIR_H
end_ifndef

begin_define
define|#
directive|define
name|_DIR_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_TYPES_H
end_ifndef

begin_comment
comment|/* not quite right */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DIRBLKSIZ
value|512
end_define

begin_comment
comment|/* size of directory block */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRSIZ
end_ifndef

begin_define
define|#
directive|define
name|DIRSIZ
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|direct
block|{
name|ino_t
name|d_ino
decl_stmt|;
name|char
name|d_name
index|[
name|DIRSIZ
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DIR_H */
end_comment

end_unit

