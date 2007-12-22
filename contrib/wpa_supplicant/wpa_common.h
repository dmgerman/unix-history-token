begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * WPA definitions shared between hostapd and wpa_supplicant  * Copyright (c) 2002-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WPA_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|WPA_COMMON_H
end_define

begin_define
define|#
directive|define
name|WPA_REPLAY_COUNTER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|WPA_NONCE_LEN
value|32
end_define

begin_define
define|#
directive|define
name|WPA_KEY_RSC_LEN
value|8
end_define

begin_comment
comment|/* IEEE Std 802.1X-2004 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|push
name|,
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_struct
struct|struct
name|ieee802_1x_hdr
block|{
name|u8
name|version
decl_stmt|;
name|u8
name|type
decl_stmt|;
name|u16
name|length
decl_stmt|;
comment|/* followed by length octets of data */
block|}
name|STRUCT_PACKED
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MSC_VER */
end_comment

begin_define
define|#
directive|define
name|EAPOL_VERSION
value|2
end_define

begin_enum
enum|enum
block|{
name|IEEE802_1X_TYPE_EAP_PACKET
init|=
literal|0
block|,
name|IEEE802_1X_TYPE_EAPOL_START
init|=
literal|1
block|,
name|IEEE802_1X_TYPE_EAPOL_LOGOFF
init|=
literal|2
block|,
name|IEEE802_1X_TYPE_EAPOL_KEY
init|=
literal|3
block|,
name|IEEE802_1X_TYPE_EAPOL_ENCAPSULATED_ASF_ALERT
init|=
literal|4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|EAPOL_KEY_TYPE_RC4
init|=
literal|1
block|,
name|EAPOL_KEY_TYPE_RSN
init|=
literal|2
block|,
name|EAPOL_KEY_TYPE_WPA
init|=
literal|254
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_IEEE80211W
end_ifdef

begin_define
define|#
directive|define
name|WPA_DGTK_LEN
value|16
end_define

begin_define
define|#
directive|define
name|WPA_DHV_LEN
value|16
end_define

begin_define
define|#
directive|define
name|WPA_IGTK_LEN
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_IEEE80211W */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WPA_COMMON_H */
end_comment

end_unit

