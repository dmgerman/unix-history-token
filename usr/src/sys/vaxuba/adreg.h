begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)adreg.h	7.2 (Berkeley) 12/22/87  */
end_comment

begin_struct
struct|struct
name|addevice
block|{
name|short
name|int
name|ad_csr
decl_stmt|;
comment|/* Control status register */
name|short
name|int
name|ad_data
decl_stmt|;
comment|/* Data buffer */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|AD_CHAN
value|ADIOSCHAN
end_define

begin_define
define|#
directive|define
name|AD_READ
value|ADIOGETW
end_define

begin_define
define|#
directive|define
name|ADIOSCHAN
value|_IOW('a', 0, int)
end_define

begin_comment
comment|/* set channel */
end_comment

begin_define
define|#
directive|define
name|ADIOGETW
value|_IOR('a', 1, int)
end_define

begin_comment
comment|/* read one word */
end_comment

begin_comment
comment|/*  * Unibus CSR register bits  */
end_comment

begin_define
define|#
directive|define
name|AD_START
value|01
end_define

begin_define
define|#
directive|define
name|AD_SCHMITT
value|020
end_define

begin_define
define|#
directive|define
name|AD_CLOCK
value|040
end_define

begin_define
define|#
directive|define
name|AD_IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|AD_DONE
value|0200
end_define

begin_define
define|#
directive|define
name|AD_INCENABLE
value|040000
end_define

begin_define
define|#
directive|define
name|AD_ERROR
value|0100000
end_define

end_unit

