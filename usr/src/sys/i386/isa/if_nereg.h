begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)if_nereg.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * NE2000 Ethernet Card registers  */
end_comment

begin_comment
comment|/* The NE2000 uses a DS8390 Ethernet controller in at the beginning of    its i/o space */
end_comment

begin_include
include|#
directive|include
file|<i386/isa/ic/ds8390.h>
end_include

begin_define
define|#
directive|define
name|ne_data
value|0x10
end_define

begin_comment
comment|/* Data Transfer port */
end_comment

begin_define
define|#
directive|define
name|ne_reset
value|0x1f
end_define

begin_comment
comment|/* Card Reset port */
end_comment

begin_define
define|#
directive|define
name|PKTSZ
value|3*512
end_define

begin_define
define|#
directive|define
name|TBUF
value|(16*1024)
end_define

begin_comment
comment|/* Starting location of Transmit Buffer */
end_comment

begin_define
define|#
directive|define
name|RBUF
value|(16*1024+PKTSZ)
end_define

begin_comment
comment|/* Starting location of Receive Buffer */
end_comment

begin_define
define|#
directive|define
name|RBUFEND
value|(32*1024)
end_define

begin_comment
comment|/* Ending location of Transmit Buffer */
end_comment

end_unit

