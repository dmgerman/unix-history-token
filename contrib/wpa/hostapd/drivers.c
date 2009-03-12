begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hostapd / driver interface list  * Copyright (c) 2007, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_HOSTAP
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_hostap_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_hostap.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_HOSTAP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NL80211
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_nl80211_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_nl80211.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_NL80211 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_PRISM54
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_prism54_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_prism54.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_PRISM54 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_MADWIFI
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_madwifi_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_madwifi.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_MADWIFI */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_BSD
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_bsd_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_bsd.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_WIRED
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_wired_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_wired.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_WIRED */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_TEST
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_test_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_test.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_TEST */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NONE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_none_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_none.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_NONE */
end_comment

begin_decl_stmt
name|struct
name|wpa_driver_ops
modifier|*
name|hostapd_drivers
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_HOSTAP
operator|&
name|wpa_driver_hostap_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_HOSTAP */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NL80211
operator|&
name|wpa_driver_nl80211_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_NL80211 */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_PRISM54
operator|&
name|wpa_driver_prism54_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_PRISM54 */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_MADWIFI
operator|&
name|wpa_driver_madwifi_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_MADWIFI */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_BSD
operator|&
name|wpa_driver_bsd_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_BSD */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_WIRED
operator|&
name|wpa_driver_wired_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_WIRED */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_TEST
operator|&
name|wpa_driver_test_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_TEST */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NONE
operator|&
name|wpa_driver_none_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_NONE */
name|NULL
block|}
decl_stmt|;
end_decl_stmt

end_unit

