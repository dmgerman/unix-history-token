begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       crc_macros.h
end_comment

begin_comment
comment|/// \brief      Some endian-dependent macros for CRC32 and CRC64
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|)
value|((x)>> 24)
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|S8
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|S32
parameter_list|(
name|x
parameter_list|)
value|((x)<< 32)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|A
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFF)
end_define

begin_define
define|#
directive|define
name|D
parameter_list|(
name|x
parameter_list|)
value|((x)>> 24)
end_define

begin_define
define|#
directive|define
name|S8
parameter_list|(
name|x
parameter_list|)
value|((x)>> 8)
end_define

begin_define
define|#
directive|define
name|S32
parameter_list|(
name|x
parameter_list|)
value|((x)>> 32)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

