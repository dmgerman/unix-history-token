begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ns16550.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * NS16550 UART registers  */
end_comment

begin_define
define|#
directive|define
name|com_data
value|0
end_define

begin_comment
comment|/* data register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbl
value|0
end_define

begin_comment
comment|/* divisor latch low (W) */
end_comment

begin_define
define|#
directive|define
name|com_dlbh
value|1
end_define

begin_comment
comment|/* divisor latch high (W) */
end_comment

begin_define
define|#
directive|define
name|com_ier
value|1
end_define

begin_comment
comment|/* interrupt enable (W) */
end_comment

begin_define
define|#
directive|define
name|com_iir
value|2
end_define

begin_comment
comment|/* interrupt identification (R) */
end_comment

begin_define
define|#
directive|define
name|com_fifo
value|2
end_define

begin_comment
comment|/* FIFO control (W) */
end_comment

begin_define
define|#
directive|define
name|com_lctl
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_cfcr
value|3
end_define

begin_comment
comment|/* line control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_mcr
value|4
end_define

begin_comment
comment|/* modem control register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_lsr
value|5
end_define

begin_comment
comment|/* line status register (R/W) */
end_comment

begin_define
define|#
directive|define
name|com_msr
value|6
end_define

begin_comment
comment|/* modem status register (R/W) */
end_comment

end_unit

