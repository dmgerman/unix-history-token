begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)slip.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Ioctls operating on SLIP ttys. */
end_comment

begin_define
define|#
directive|define
name|SLIOCGUNIT
value|_IOR('t', 88, int)
end_define

begin_comment
comment|/* get slip unit number */
end_comment

begin_comment
comment|/*  * Definitions of the pseudo-link-level header attached to slip  * packets grabbed by the packet filter (bpf) traffic monitor.  */
end_comment

begin_define
define|#
directive|define
name|SLIP_HDRLEN
value|16
end_define

begin_comment
comment|/* BPF SLIP header length */
end_comment

begin_comment
comment|/* Offsets into BPF SLIP header. */
end_comment

begin_define
define|#
directive|define
name|SLX_DIR
value|0
end_define

begin_comment
comment|/* direction; see below */
end_comment

begin_define
define|#
directive|define
name|SLX_CHDR
value|1
end_define

begin_comment
comment|/* compressed header data */
end_comment

begin_define
define|#
directive|define
name|CHDR_LEN
value|15
end_define

begin_comment
comment|/* length of compressed header data */
end_comment

begin_define
define|#
directive|define
name|SLIPDIR_IN
value|0
end_define

begin_comment
comment|/* incoming */
end_comment

begin_define
define|#
directive|define
name|SLIPDIR_OUT
value|1
end_define

begin_comment
comment|/* outgoing */
end_comment

end_unit

