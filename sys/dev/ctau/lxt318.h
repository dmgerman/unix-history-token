begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Level One LXT318 E1 transceiver registers.  * Crystal CS61318 E1 Line Interface Unit registers.  * Crystal CS61581 T1/E1 Line Interface Unit registers.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * Copyright (C) 2003 Cronyx Engineering.  * Author: Roman Kurakin,<rik@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: lxt318.h,v 1.2.4.4 2003/11/14 19:08:45 rik Exp $  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|LX_WRITE
value|0x00
end_define

begin_define
define|#
directive|define
name|LX_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|LX_CCR1
value|0x10
end_define

begin_define
define|#
directive|define
name|LX_CCR2
value|0x11
end_define

begin_comment
comment|/* CS61318 */
end_comment

begin_define
define|#
directive|define
name|LX_EQGAIN
value|0x12
end_define

begin_comment
comment|/* CS61318 */
end_comment

begin_define
define|#
directive|define
name|LX_RAM
value|0x13
end_define

begin_comment
comment|/* CS61318 */
end_comment

begin_define
define|#
directive|define
name|LX_CCR3
value|0x14
end_define

begin_comment
comment|/* CS61581 */
end_comment

begin_define
define|#
directive|define
name|LX_DPEC
value|0x15
end_define

begin_comment
comment|/* CS61581 */
end_comment

begin_define
define|#
directive|define
name|LX_LOS
value|0x01
end_define

begin_comment
comment|/* loss of signal condition */
end_comment

begin_define
define|#
directive|define
name|LX_HDB3
value|0x04
end_define

begin_comment
comment|/* HDB3 encoding enable */
end_comment

begin_define
define|#
directive|define
name|LX_RLOOP
value|0x20
end_define

begin_comment
comment|/* remote loopback */
end_comment

begin_define
define|#
directive|define
name|LX_LLOOP
value|0x40
end_define

begin_comment
comment|/* local loopback */
end_comment

begin_define
define|#
directive|define
name|LX_TAOS
value|0x80
end_define

begin_comment
comment|/* transmit all ones */
end_comment

begin_define
define|#
directive|define
name|LX_RESET
value|(LX_RLOOP | LX_LLOOP)
end_define

begin_comment
comment|/* reset the chip */
end_comment

begin_define
define|#
directive|define
name|LX_CCR2_LH
value|0x00
end_define

begin_comment
comment|/* Long Haul mode */
end_comment

begin_define
define|#
directive|define
name|LX_CCR2_SH
value|0x01
end_define

begin_comment
comment|/* Long Haul mode */
end_comment

begin_define
define|#
directive|define
name|LX_CCR3_E1_LH
value|0x60
end_define

begin_comment
comment|/* Long Haul mode */
end_comment

end_unit

