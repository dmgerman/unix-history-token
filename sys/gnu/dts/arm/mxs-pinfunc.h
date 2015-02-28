begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Header providing constants for i.MX28 pinctrl bindings.  *  * Copyright (C) 2013 Lothar WaÃmann<LW@KARO-electronics.de>  *  * The code contained herein is licensed under the GNU General Public  * License. You may obtain a copy of the GNU General Public License  * Version 2 at the following locations:  *  * http://www.opensource.org/licenses/gpl-license.html  * http://www.gnu.org/copyleft/gpl.html  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DT_BINDINGS_MXS_PINCTRL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DT_BINDINGS_MXS_PINCTRL_H__
end_define

begin_comment
comment|/* fsl,drive-strength property */
end_comment

begin_define
define|#
directive|define
name|MXS_DRIVE_4mA
value|0
end_define

begin_define
define|#
directive|define
name|MXS_DRIVE_8mA
value|1
end_define

begin_define
define|#
directive|define
name|MXS_DRIVE_12mA
value|2
end_define

begin_define
define|#
directive|define
name|MXS_DRIVE_16mA
value|3
end_define

begin_comment
comment|/* fsl,voltage property */
end_comment

begin_define
define|#
directive|define
name|MXS_VOLTAGE_LOW
value|0
end_define

begin_define
define|#
directive|define
name|MXS_VOLTAGE_HIGH
value|1
end_define

begin_comment
comment|/* fsl,pull-up property */
end_comment

begin_define
define|#
directive|define
name|MXS_PULL_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|MXS_PULL_ENABLE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DT_BINDINGS_MXS_PINCTRL_H__ */
end_comment

end_unit

