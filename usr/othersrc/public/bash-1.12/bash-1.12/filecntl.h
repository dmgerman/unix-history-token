begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* filecntl.h - Definitions to set file descriptors to close-on-exec. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_FILECNTL_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_FILECNTL_H_
end_define

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* Definitions to set file descriptors to close-on-exec, the Posix way. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FD_CLOEXEC
argument_list|)
end_if

begin_define
define|#
directive|define
name|FD_CLOEXEC
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FD_NCLOEXEC
value|0
end_define

begin_define
define|#
directive|define
name|SET_CLOSE_ON_EXEC
parameter_list|(
name|fd
parameter_list|)
value|(fcntl ((fd), F_SETFD, FD_CLOEXEC))
end_define

begin_define
define|#
directive|define
name|SET_OPEN_ON_EXEC
parameter_list|(
name|fd
parameter_list|)
value|(fcntl ((fd), F_SETFD, FD_NCLOEXEC))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _FILECNTL_H_ */
end_comment

end_unit

