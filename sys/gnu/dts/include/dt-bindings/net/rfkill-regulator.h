begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides macros for rfkill-regulator bindings.  *  * Copyright (C) 2014 Marek Belisko<marek@goldelico.com>  *  * GPLv2 only  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_RFKILL_REGULATOR_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_RFKILL_REGULATOR_H__
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_ALL
value|(0)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_WLAN
value|(1)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_BLUETOOTH
value|(2)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_UWB
value|(3)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_WIMAX
value|(4)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_WWAN
value|(5)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_GPS
value|(6)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_FM
value|(7)
end_define

begin_define
define|#
directive|define
name|RFKILL_TYPE_NFC
value|(8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_RFKILL_REGULATOR_H__ */
end_comment

end_unit

