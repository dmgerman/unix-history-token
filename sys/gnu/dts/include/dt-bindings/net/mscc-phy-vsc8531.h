begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device Tree constants for Microsemi VSC8531 PHY  *  * Author: Nagaraju Lakkaraju  *  * License: Dual MIT/GPL  * Copyright (c) 2017 Microsemi Corporation  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DT_BINDINGS_MSCC_VSC8531_H
end_ifndef

begin_define
define|#
directive|define
name|_DT_BINDINGS_MSCC_VSC8531_H
end_define

begin_comment
comment|/* PHY LED Modes */
end_comment

begin_define
define|#
directive|define
name|VSC8531_LINK_ACTIVITY
value|0
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_1000_ACTIVITY
value|1
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_100_ACTIVITY
value|2
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_10_ACTIVITY
value|3
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_100_1000_ACTIVITY
value|4
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_10_1000_ACTIVITY
value|5
end_define

begin_define
define|#
directive|define
name|VSC8531_LINK_10_100_ACTIVITY
value|6
end_define

begin_define
define|#
directive|define
name|VSC8531_DUPLEX_COLLISION
value|8
end_define

begin_define
define|#
directive|define
name|VSC8531_COLLISION
value|9
end_define

begin_define
define|#
directive|define
name|VSC8531_ACTIVITY
value|10
end_define

begin_define
define|#
directive|define
name|VSC8531_AUTONEG_FAULT
value|12
end_define

begin_define
define|#
directive|define
name|VSC8531_SERIAL_MODE
value|13
end_define

begin_define
define|#
directive|define
name|VSC8531_FORCE_LED_OFF
value|14
end_define

begin_define
define|#
directive|define
name|VSC8531_FORCE_LED_ON
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

