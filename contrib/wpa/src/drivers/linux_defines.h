begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Linux defines for values that are not yet included in common C libraries  * Copyright (c) 2014, Jouni Malinen<j@w1.fi>  *  * This software may be distributed under the terms of the BSD license.  * See README for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_DEFINES_H
end_ifndef

begin_define
define|#
directive|define
name|LINUX_DEFINES_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SO_WIFI_STATUS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SO_WIFI_STATUS
value|0x0025
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__parisc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|SO_WIFI_STATUS
value|0x4022
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SO_WIFI_STATUS
value|41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SCM_WIFI_STATUS
value|SO_WIFI_STATUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SO_EE_ORIGIN_TXSTATUS
end_ifndef

begin_define
define|#
directive|define
name|SO_EE_ORIGIN_TXSTATUS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PACKET_TX_TIMESTAMP
end_ifndef

begin_define
define|#
directive|define
name|PACKET_TX_TIMESTAMP
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFF_LOWER_UP
end_ifndef

begin_define
define|#
directive|define
name|IFF_LOWER_UP
value|0x10000
end_define

begin_comment
comment|/* driver signals L1 up         */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IFF_DORMANT
end_ifndef

begin_define
define|#
directive|define
name|IFF_DORMANT
value|0x20000
end_define

begin_comment
comment|/* driver signals dormant       */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IF_OPER_DORMANT
end_ifndef

begin_define
define|#
directive|define
name|IF_OPER_DORMANT
value|5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|IF_OPER_UP
end_ifndef

begin_define
define|#
directive|define
name|IF_OPER_UP
value|6
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
comment|/* LINUX_DEFINES_H */
end_comment

end_unit

