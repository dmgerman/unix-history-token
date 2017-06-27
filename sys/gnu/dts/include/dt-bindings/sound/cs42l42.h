begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * cs42l42.h -- CS42L42 ALSA SoC audio driver DT bindings header  *  * Copyright 2016 Cirrus Logic, Inc.  *  * Author: James Schulman<james.schulman@cirrus.com>  * Author: Brian Austin<brian.austin@cirrus.com>  * Author: Michael White<michael.white@cirrus.com>  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License version 2 as  * published by the Free Software Foundation.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_CS42L42_H
end_ifndef

begin_define
define|#
directive|define
name|__DT_CS42L42_H
end_define

begin_comment
comment|/* HPOUT Load Capacity */
end_comment

begin_define
define|#
directive|define
name|CS42L42_HPOUT_LOAD_1NF
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_HPOUT_LOAD_10NF
value|1
end_define

begin_comment
comment|/* HPOUT Clamp to GND Override */
end_comment

begin_define
define|#
directive|define
name|CS42L42_HPOUT_CLAMP_EN
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_HPOUT_CLAMP_DIS
value|1
end_define

begin_comment
comment|/* Tip Sense Inversion */
end_comment

begin_define
define|#
directive|define
name|CS42L42_TS_INV_DIS
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_INV_EN
value|1
end_define

begin_comment
comment|/* Tip Sense Debounce */
end_comment

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_0
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_125
value|1
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_250
value|2
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_500
value|3
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_750
value|4
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_1000
value|5
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_1250
value|6
end_define

begin_define
define|#
directive|define
name|CS42L42_TS_DBNCE_1500
value|7
end_define

begin_comment
comment|/* Button Press Software Debounce Times */
end_comment

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_INIT_DBNCE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_INIT_DBNCE_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_INIT_DBNCE_MAX
value|200
end_define

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_EVENT_DBNCE_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_EVENT_DBNCE_DEFAULT
value|10
end_define

begin_define
define|#
directive|define
name|CS42L42_BTN_DET_EVENT_DBNCE_MAX
value|20
end_define

begin_comment
comment|/* Button Detect Level Sensitivities */
end_comment

begin_define
define|#
directive|define
name|CS42L42_NUM_BIASES
value|4
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_15
value|0x0F
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_8
value|0x08
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_4
value|0x04
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_1
value|0x01
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_MIN
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_HS_DET_LEVEL_MAX
value|0x3F
end_define

begin_comment
comment|/* HS Bias Ramp Rate */
end_comment

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_FAST_RISE_SLOW_FALL
value|0
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_FAST
value|1
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_SLOW
value|2
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_SLOWEST
value|3
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_TIME0
value|10
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_TIME1
value|40
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_TIME2
value|90
end_define

begin_define
define|#
directive|define
name|CS42L42_HSBIAS_RAMP_TIME3
value|170
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_CS42L42_H */
end_comment

end_unit

