begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_open_h
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUG__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_pragma
pragma|#
directive|pragma
name|interface
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_open_h
value|1
end_define

begin_include
include|#
directive|include
file|<File.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_comment
comment|// needed to determine values of O_RDONLY...
end_comment

begin_comment
comment|/*   translation stuff for opening files.   */
end_comment

begin_enum
enum|enum
name|sys_open_cmd_io_mode
comment|// These should be correct for most systems
block|{
name|sio_read
init|=
name|O_RDONLY
block|,
name|sio_write
init|=
name|O_WRONLY
block|,
name|sio_readwrite
init|=
name|O_RDWR
block|,
name|sio_append
init|=
name|O_APPEND
block|}
enum|;
end_enum

begin_enum
enum|enum
name|sys_open_cmd_access_mode
block|{
name|sa_create
init|=
name|O_CREAT
block|,
name|sa_truncate
init|=
name|O_TRUNC
block|,
name|sa_createonly
init|=
name|O_EXCL
operator||
name|O_CREAT
block|}
enum|;
end_enum

begin_function_decl
name|int
name|open_cmd_arg
parameter_list|(
name|io_mode
name|i
parameter_list|,
name|access_mode
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// decode modes
end_comment

begin_function_decl
name|char
modifier|*
name|fopen_cmd_arg
parameter_list|(
name|io_mode
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_cmd_arg
parameter_list|(
specifier|const
name|char
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

