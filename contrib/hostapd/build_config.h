begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * wpa_supplicant/hostapd - Build time configuration defines  * Copyright (c) 2005-2006, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  *  * This header file can be used to define configuration defines that were  * originally defined in Makefile. This is mainly meant for IDE use or for  * systems that do not have suitable 'make' tool. In these cases, it may be  * easier to have a single place for defining all the needed C pre-processor  * defines.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUILD_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|BUILD_CONFIG_H
end_define

begin_comment
comment|/* Insert configuration defines, e.g., #define EAP_MD5, here, if needed. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_WIN32_DEFAULTS
end_ifdef

begin_define
define|#
directive|define
name|CONFIG_NATIVE_WINDOWS
end_define

begin_define
define|#
directive|define
name|CONFIG_ANSI_C_EXTRA
end_define

begin_define
define|#
directive|define
name|CONFIG_WINPCAP
end_define

begin_define
define|#
directive|define
name|IEEE8021X_EAPOL
end_define

begin_define
define|#
directive|define
name|EAP_TLS_FUNCS
end_define

begin_define
define|#
directive|define
name|PKCS12_FUNCS
end_define

begin_define
define|#
directive|define
name|PCSC_FUNCS
end_define

begin_define
define|#
directive|define
name|CONFIG_CTRL_IFACE
end_define

begin_define
define|#
directive|define
name|CONFIG_CTRL_IFACE_NAMED_PIPE
end_define

begin_define
define|#
directive|define
name|CONFIG_DRIVER_NDIS
end_define

begin_define
define|#
directive|define
name|CONFIG_NDIS_EVENTS_INTEGRATED
end_define

begin_define
define|#
directive|define
name|CONFIG_DEBUG_FILE
end_define

begin_define
define|#
directive|define
name|EAP_MD5
end_define

begin_define
define|#
directive|define
name|EAP_TLS
end_define

begin_define
define|#
directive|define
name|EAP_MSCHAPv2
end_define

begin_define
define|#
directive|define
name|EAP_PEAP
end_define

begin_define
define|#
directive|define
name|EAP_TTLS
end_define

begin_define
define|#
directive|define
name|EAP_GTC
end_define

begin_define
define|#
directive|define
name|EAP_OTP
end_define

begin_define
define|#
directive|define
name|EAP_LEAP
end_define

begin_define
define|#
directive|define
name|_CRT_SECURE_NO_DEPRECATE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_WIN32_DEFAULTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BUILD_CONFIG_H */
end_comment

end_unit

