begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  *      form: @(#)lptreg.h	1.1 (Berkeley) 12/19/90  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT Parallel Port (for lineprinter)  * Interface port and bit definitions  * Written by William Jolitz 12/18/90  * Copyright (C) William Jolitz 1990  */
end_comment

begin_comment
comment|/*  * modified for PC9801 by A.Kojima  *			Kyoto University Microcomputer Club (KMC)  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|lpt_pstb_ctrl
value|(-9)
end_define

begin_comment
comment|/* PSTB enable control */
end_comment

begin_define
define|#
directive|define
name|LPC_EN_PSTB
value|0xc
end_define

begin_comment
comment|/* PSTB enable */
end_comment

begin_define
define|#
directive|define
name|LPC_DIS_PSTB
value|0xd
end_define

begin_comment
comment|/* PSTB disable */
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
value|2
end_define

begin_comment
comment|/* Status of printer (R) */
end_comment

begin_define
define|#
directive|define
name|LPS_NBSY
value|0x4
end_define

begin_comment
comment|/* printer no ack of data */
end_comment

begin_define
define|#
directive|define
name|lpt_control
value|6
end_define

begin_comment
comment|/* Control printer (W) */
end_comment

begin_define
define|#
directive|define
name|LPC_MODE8255
value|0x82
end_define

begin_comment
comment|/* 8255 mode */
end_comment

begin_define
define|#
directive|define
name|LPC_IRQ8
value|0x6
end_define

begin_comment
comment|/* IRQ8 active */
end_comment

begin_define
define|#
directive|define
name|LPC_NIRQ8
value|0x7
end_define

begin_comment
comment|/* IRQ8 inactive */
end_comment

begin_define
define|#
directive|define
name|LPC_PSTB
value|0xe
end_define

begin_comment
comment|/* PSTB active */
end_comment

begin_define
define|#
directive|define
name|LPC_NPSTB
value|0xf
end_define

begin_comment
comment|/* PSTB inactive */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* IBM-PC */
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
comment|/* enable IRQ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

