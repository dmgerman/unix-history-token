begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ** fcntl.h ** ** Emulation of the Unix fcntl.h header file for PRIMOS ** ** Author: Peter Eriksson<pen@lysator.liu.se> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FCNTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__FCNTL_H__
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|0
end_define

begin_define
define|#
directive|define
name|O_WRONLY
value|1
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|2
end_define

begin_define
define|#
directive|define
name|O_BINARY
value|0
end_define

begin_define
define|#
directive|define
name|O_EXCL
value|0
end_define

begin_define
define|#
directive|define
name|O_NDELAY
value|0
end_define

begin_define
define|#
directive|define
name|O_CREAT
value|0
end_define

begin_define
define|#
directive|define
name|O_TRUNC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

