begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ATH_AR9300_BTCOEX_H__
end_ifndef

begin_define
define|#
directive|define
name|__ATH_AR9300_BTCOEX_H__
end_define

begin_comment
comment|/*  * Weight table configurations.  */
end_comment

begin_define
define|#
directive|define
name|AR9300_BT_WGHT
value|0xcccc4444
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_WLAN_WGHT0
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_WLAN_WGHT1
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_WLAN_WGHT0
value|0x88888880
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_WLAN_WGHT1
value|0x88888880
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_NONE_WLAN_WGHT0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_NONE_WLAN_WGHT1
value|0x00000000
end_define

begin_comment
comment|/* Stomp BT even when WLAN is idle */
end_comment

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_FORCE_WLAN_WGHT0
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_ALL_FORCE_WLAN_WGHT1
value|0xffffffff
end_define

begin_comment
comment|/* Stomp BT even when WLAN is idle */
end_comment

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_FORCE_WLAN_WGHT0
value|0x88888888
end_define

begin_define
define|#
directive|define
name|AR9300_STOMP_LOW_FORCE_WLAN_WGHT1
value|0x88888888
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT0
value|0x00007d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT1
value|0x7d7d7d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT2
value|0x7d7d7d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_WLAN_WGHT3
value|0x7d7d7d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT0
value|0x00007d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT1
value|0x7d3b3b00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT2
value|0x3b3b3b00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_WLAN_WGHT3
value|0x3b3b3b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT0
value|0x00007d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT1
value|0x7d000000
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT2
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_NONE_WLAN_WGHT3
value|0x00000000
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT0
value|0x00007d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT1
value|0x7d7d7d00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT2
value|0x7d7d7d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_ALL_FORCE_WLAN_WGHT3
value|0x7d7d7d7d
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT0
value|0x00003b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT1
value|0x3b3b3b00
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT2
value|0x3b3b3b3b
end_define

begin_define
define|#
directive|define
name|JUPITER_STOMP_LOW_FORCE_WLAN_WGHT3
value|0x3b3b3b3b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ATH_AR9300_BTCOEX_H__ */
end_comment

end_unit

