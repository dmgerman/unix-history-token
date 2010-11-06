begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Driver interface list  * Copyright (c) 2004-2005, Jouni Malinen<j@w1.fi>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  * Alternatively, this software may be distributed under the terms of BSD  * license.  *  * See README and COPYING for more details.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_WEXT
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_wext_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_wext.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_WEXT */
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
name|CONFIG_DRIVER_HERMES
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_hermes_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_hermes.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_HERMES */
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
name|CONFIG_DRIVER_ATMEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_atmel_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_atmel.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_ATMEL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NDISWRAPPER
end_ifdef

begin_comment
comment|/* driver_ndiswrapper.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_ndiswrapper_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_NDISWRAPPER */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_BROADCOM
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_broadcom_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_broadcom.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_BROADCOM */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_IPW
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_ipw_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_ipw.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_IPW */
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
name|CONFIG_DRIVER_NDIS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_ndis_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_ndis.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_NDIS */
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
name|CONFIG_DRIVER_RALINK
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_ralink_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_ralink.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_RALINK */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_OSX
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_osx_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_osx.m */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_OSX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_IPHONE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_iphone_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_iphone.m */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_IPHONE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_ROBOSWITCH
end_ifdef

begin_comment
comment|/* driver_roboswitch.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_roboswitch_ops
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_ROBOSWITCH */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_ATHEROS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|wpa_driver_ops
name|wpa_driver_atheros_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* driver_atheros.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONFIG_DRIVER_ATHEROS */
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
name|wpa_drivers
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_WEXT
operator|&
name|wpa_driver_wext_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_WEXT */
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
name|CONFIG_DRIVER_HOSTAP
operator|&
name|wpa_driver_hostap_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_HOSTAP */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_HERMES
operator|&
name|wpa_driver_hermes_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_HERMES */
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
name|CONFIG_DRIVER_ATMEL
operator|&
name|wpa_driver_atmel_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_ATMEL */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_NDISWRAPPER
operator|&
name|wpa_driver_ndiswrapper_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_NDISWRAPPER */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_BROADCOM
operator|&
name|wpa_driver_broadcom_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_BROADCOM */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_IPW
operator|&
name|wpa_driver_ipw_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_IPW */
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
name|CONFIG_DRIVER_NDIS
operator|&
name|wpa_driver_ndis_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_NDIS */
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
name|CONFIG_DRIVER_RALINK
operator|&
name|wpa_driver_ralink_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_RALINK */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_OSX
operator|&
name|wpa_driver_osx_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_OSX */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_IPHONE
operator|&
name|wpa_driver_iphone_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_IPHONE */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_ROBOSWITCH
operator|&
name|wpa_driver_roboswitch_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_ROBOSWITCH */
ifdef|#
directive|ifdef
name|CONFIG_DRIVER_ATHEROS
operator|&
name|wpa_driver_atheros_ops
block|,
endif|#
directive|endif
comment|/* CONFIG_DRIVER_ATHEROS */
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

