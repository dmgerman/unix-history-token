begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)saioctl.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* ioctl's -- for disks just now */
end_comment

begin_define
define|#
directive|define
name|SAIOHDR
value|(('d'<<8)|1)
end_define

begin_comment
comment|/* next i/o includes header */
end_comment

begin_define
define|#
directive|define
name|SAIOCHECK
value|(('d'<<8)|2)
end_define

begin_comment
comment|/* next i/o checks data */
end_comment

begin_define
define|#
directive|define
name|SAIOHCHECK
value|(('d'<<8)|3)
end_define

begin_comment
comment|/* next i/o checks header& data */
end_comment

begin_define
define|#
directive|define
name|SAIONOBAD
value|(('d'<<8)|4)
end_define

begin_comment
comment|/* inhibit bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIODOBAD
value|(('d'<<8)|5)
end_define

begin_comment
comment|/* enable bad sector forwarding */
end_comment

begin_define
define|#
directive|define
name|SAIOECCLIM
value|(('d'<<8)|6)
end_define

begin_comment
comment|/* set limit to ecc correction, bits */
end_comment

begin_define
define|#
directive|define
name|SAIOECCUNL
value|(('d'<<8)|7)
end_define

begin_comment
comment|/* use standard ecc procedures */
end_comment

begin_define
define|#
directive|define
name|SAIORETRIES
value|(('d'<<8)|8)
end_define

begin_comment
comment|/* set retry count for unit */
end_comment

begin_define
define|#
directive|define
name|SAIODEVDATA
value|(('d'<<8)|9)
end_define

begin_comment
comment|/* get pointer to pack label */
end_comment

begin_define
define|#
directive|define
name|SAIOSSI
value|(('d'<<8)|10)
end_define

begin_comment
comment|/* set skip sector inhibit */
end_comment

begin_define
define|#
directive|define
name|SAIONOSSI
value|(('d'<<8)|11)
end_define

begin_comment
comment|/* inhibit skip sector handling */
end_comment

begin_define
define|#
directive|define
name|SAIOSSDEV
value|(('d'<<8)|12)
end_define

begin_comment
comment|/* is device skip sector type? */
end_comment

begin_define
define|#
directive|define
name|SAIODEBUG
value|(('d'<<8)|13)
end_define

begin_comment
comment|/* enable/disable debugging */
end_comment

begin_define
define|#
directive|define
name|SAIOGBADINFO
value|(('d'<<8)|14)
end_define

begin_comment
comment|/* get bad-sector table */
end_comment

end_unit

