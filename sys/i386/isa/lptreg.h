begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  *      form: @(#)lptreg.h	1.1 (Berkeley) 12/19/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT Parallel Port (for lineprinter)  * Interface port and bit definitions  * Written by William Jolitz 12/18/90  * Copyright (C) William Jolitz 1990  */
end_comment

begin_define
define|#
directive|define
name|lpt_data
value|0
end_define

begin_comment
comment|/* Data to/from printer (R/W) */
end_comment

begin_define
define|#
directive|define
name|lpt_status
value|1
end_define

begin_comment
comment|/* Status of printer (R) */
end_comment

begin_define
define|#
directive|define
name|LPS_NERR
value|0x08
end_define

begin_comment
comment|/* printer no error */
end_comment

begin_define
define|#
directive|define
name|LPS_SEL
value|0x10
end_define

begin_comment
comment|/* printer selected */
end_comment

begin_define
define|#
directive|define
name|LPS_OUT
value|0x20
end_define

begin_comment
comment|/* printer out of paper */
end_comment

begin_define
define|#
directive|define
name|LPS_NACK
value|0x40
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|LPS_NBSY
value|0x80
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|lpt_control
value|2
end_define

begin_comment
comment|/* Control printer (R/W) */
end_comment

begin_define
define|#
directive|define
name|LPC_STB
value|0x01
end_define

begin_comment
comment|/* strobe data to printer */
end_comment

begin_define
define|#
directive|define
name|LPC_AUTOL
value|0x02
end_define

begin_comment
comment|/* automatic linefeed */
end_comment

begin_define
define|#
directive|define
name|LPC_NINIT
value|0x04
end_define

begin_comment
comment|/* initialize printer */
end_comment

begin_define
define|#
directive|define
name|LPC_SEL
value|0x08
end_define

begin_comment
comment|/* printer selected */
end_comment

begin_define
define|#
directive|define
name|LPC_ENA
value|0x10
end_define

begin_comment
comment|/* printer out of paper */
end_comment

end_unit

