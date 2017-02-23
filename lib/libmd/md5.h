begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MD5_H_
end_ifndef

begin_define
define|#
directive|define
name|_MD5_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_comment
comment|/* Ensure libmd symbols do not clash with libcrypto */
end_comment

begin_define
define|#
directive|define
name|MD5Init
value|_libmd_MD5Init
end_define

begin_define
define|#
directive|define
name|MD5Update
value|_libmd_MD5Update
end_define

begin_define
define|#
directive|define
name|MD5Pad
value|_libmd_MD5Pad
end_define

begin_define
define|#
directive|define
name|MD5Final
value|_libmd_MD5Final
end_define

begin_define
define|#
directive|define
name|MD5Transform
value|_libmd_MD5Transform
end_define

begin_define
define|#
directive|define
name|MD5End
value|_libmd_MD5End
end_define

begin_define
define|#
directive|define
name|MD5File
value|_libmd_MD5File
end_define

begin_define
define|#
directive|define
name|MD5FileChunk
value|_libmd_MD5FileChunk
end_define

begin_define
define|#
directive|define
name|MD5Data
value|_libmd_MD5Data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/md5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MD5_H_ */
end_comment

end_unit

