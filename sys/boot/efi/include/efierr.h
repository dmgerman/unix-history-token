begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EFI_ERR_H
end_ifndef

begin_define
define|#
directive|define
name|_EFI_ERR_H
end_define

begin_comment
comment|/*++  Copyright (c) 1998  Intel Corporation  Module Name:      efierr.h  Abstract:      EFI error codes     Revision History  --*/
end_comment

begin_define
define|#
directive|define
name|EFIWARN
parameter_list|(
name|a
parameter_list|)
value|(a)
end_define

begin_define
define|#
directive|define
name|EFI_ERROR
parameter_list|(
name|a
parameter_list|)
value|(((INTN) a)< 0)
end_define

begin_define
define|#
directive|define
name|EFI_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|EFI_LOAD_ERROR
value|EFIERR(1)
end_define

begin_define
define|#
directive|define
name|EFI_INVALID_PARAMETER
value|EFIERR(2)
end_define

begin_define
define|#
directive|define
name|EFI_UNSUPPORTED
value|EFIERR(3)
end_define

begin_define
define|#
directive|define
name|EFI_BAD_BUFFER_SIZE
value|EFIERR(4)
end_define

begin_define
define|#
directive|define
name|EFI_BUFFER_TOO_SMALL
value|EFIERR(5)
end_define

begin_define
define|#
directive|define
name|EFI_NOT_READY
value|EFIERR(6)
end_define

begin_define
define|#
directive|define
name|EFI_DEVICE_ERROR
value|EFIERR(7)
end_define

begin_define
define|#
directive|define
name|EFI_WRITE_PROTECTED
value|EFIERR(8)
end_define

begin_define
define|#
directive|define
name|EFI_OUT_OF_RESOURCES
value|EFIERR(9)
end_define

begin_define
define|#
directive|define
name|EFI_VOLUME_CORRUPTED
value|EFIERR(10)
end_define

begin_define
define|#
directive|define
name|EFI_VOLUME_FULL
value|EFIERR(11)
end_define

begin_define
define|#
directive|define
name|EFI_NO_MEDIA
value|EFIERR(12)
end_define

begin_define
define|#
directive|define
name|EFI_MEDIA_CHANGED
value|EFIERR(13)
end_define

begin_define
define|#
directive|define
name|EFI_NOT_FOUND
value|EFIERR(14)
end_define

begin_define
define|#
directive|define
name|EFI_ACCESS_DENIED
value|EFIERR(15)
end_define

begin_define
define|#
directive|define
name|EFI_NO_RESPONSE
value|EFIERR(16)
end_define

begin_define
define|#
directive|define
name|EFI_NO_MAPPING
value|EFIERR(17)
end_define

begin_define
define|#
directive|define
name|EFI_TIMEOUT
value|EFIERR(18)
end_define

begin_define
define|#
directive|define
name|EFI_NOT_STARTED
value|EFIERR(19)
end_define

begin_define
define|#
directive|define
name|EFI_ALREADY_STARTED
value|EFIERR(20)
end_define

begin_define
define|#
directive|define
name|EFI_ABORTED
value|EFIERR(21)
end_define

begin_define
define|#
directive|define
name|EFI_ICMP_ERROR
value|EFIERR(22)
end_define

begin_define
define|#
directive|define
name|EFI_TFTP_ERROR
value|EFIERR(23)
end_define

begin_define
define|#
directive|define
name|EFI_PROTOCOL_ERROR
value|EFIERR(24)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_UNKOWN_GLYPH
value|EFIWARN(1)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_DELETE_FAILURE
value|EFIWARN(2)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_WRITE_FAILURE
value|EFIWARN(3)
end_define

begin_define
define|#
directive|define
name|EFI_WARN_BUFFER_TOO_SMALL
value|EFIWARN(4)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

