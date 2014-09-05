begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This header provides macros for ams AS3722 device bindings.  *  * Copyright (c) 2013, NVIDIA Corporation.  *  * Author: Laxman Dewangan<ldewangan@nvidia.com>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_AS3722_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_AS3722_H__
end_define

begin_comment
comment|/* External control pins */
end_comment

begin_define
define|#
directive|define
name|AS3722_EXT_CONTROL_PIN_ENABLE1
value|1
end_define

begin_define
define|#
directive|define
name|AS3722_EXT_CONTROL_PIN_ENABLE2
value|2
end_define

begin_define
define|#
directive|define
name|AS3722_EXT_CONTROL_PIN_ENABLE3
value|3
end_define

begin_comment
comment|/* Interrupt numbers for AS3722 */
end_comment

begin_define
define|#
directive|define
name|AS3722_IRQ_LID
value|0
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ACOK
value|1
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ENABLE1
value|2
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_OCCUR_ALARM_SD0
value|3
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ONKEY_LONG_PRESS
value|4
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ONKEY
value|5
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_OVTMP
value|6
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_LOWBAT
value|7
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_SD0_LV
value|8
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_SD1_LV
value|9
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_SD2_LV
value|10
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_PWM1_OV_PROT
value|11
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_PWM2_OV_PROT
value|12
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ENABLE2
value|13
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_SD6_LV
value|14
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_RTC_REP
value|15
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_RTC_ALARM
value|16
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_GPIO1
value|17
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_GPIO2
value|18
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_GPIO3
value|19
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_GPIO4
value|20
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_GPIO5
value|21
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_WATCHDOG
value|22
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ENABLE3
value|23
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD0_SHUTDOWN
value|24
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD1_SHUTDOWN
value|25
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD2_SHUTDOWN
value|26
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD0_ALARM
value|27
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD1_ALARM
value|28
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_TEMP_SD6_ALARM
value|29
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_OCCUR_ALARM_SD6
value|30
end_define

begin_define
define|#
directive|define
name|AS3722_IRQ_ADC
value|31
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_AS3722_H__ */
end_comment

end_unit

