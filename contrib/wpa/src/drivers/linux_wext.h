begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Driver interaction with generic Linux Wireless Extensions  * Copyright (c) 2003-2011, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_WEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LINUX_WEXT_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ANDROID
end_ifndef

begin_comment
comment|/*  * Avoid including other kernel header to avoid conflicts with C library  * headers.  */
end_comment

begin_define
define|#
directive|define
name|_LINUX_TYPES_H
end_define

begin_define
define|#
directive|define
name|_LINUX_SOCKET_H
end_define

begin_define
define|#
directive|define
name|_LINUX_IF_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_typedef
typedef|typedef
name|__uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16_t
name|__s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint8_t
name|__u8
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__user
end_ifndef

begin_define
define|#
directive|define
name|__user
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ANDROID */
end_comment

begin_include
include|#
directive|include
file|<linux/wireless.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|IW_ENCODE_ALG_PMK
end_ifndef

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_PMK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IW_ENC_CAPA_4WAY_HANDSHAKE
end_ifndef

begin_define
define|#
directive|define
name|IW_ENC_CAPA_4WAY_HANDSHAKE
value|0x00000010
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
comment|/* LINUX_WEXT_H */
end_comment

end_unit

