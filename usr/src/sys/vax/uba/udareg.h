begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)udareg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * UDA-50 registers and structures  */
end_comment

begin_struct
struct|struct
name|udadevice
block|{
name|short
name|udaip
decl_stmt|;
comment|/* initialization and polling */
name|short
name|udasa
decl_stmt|;
comment|/* status and address */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDA_ERR
value|0100000
end_define

begin_comment
comment|/* error bit */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP4
value|0040000
end_define

begin_comment
comment|/* step 4 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP3
value|0020000
end_define

begin_comment
comment|/* step 3 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP2
value|0010000
end_define

begin_comment
comment|/* step 2 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP1
value|0004000
end_define

begin_comment
comment|/* step 1 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_NV
value|0002000
end_define

begin_comment
comment|/* no host settable interrupt vector */
end_comment

begin_define
define|#
directive|define
name|UDA_QB
value|0001000
end_define

begin_comment
comment|/* controller supports Q22 bus */
end_comment

begin_define
define|#
directive|define
name|UDA_DI
value|0000400
end_define

begin_comment
comment|/* controller implements diagnostics */
end_comment

begin_define
define|#
directive|define
name|UDA_IE
value|0000200
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UDA_PI
value|0000001
end_define

begin_comment
comment|/* host requests adapter purge interrupts */
end_comment

begin_define
define|#
directive|define
name|UDA_GO
value|0000001
end_define

begin_comment
comment|/* start operation, after init */
end_comment

begin_comment
comment|/*  * UDA Communications Area  */
end_comment

begin_struct
struct|struct
name|udaca
block|{
name|short
name|ca_xxx1
decl_stmt|;
comment|/* unused */
name|char
name|ca_xxx2
decl_stmt|;
comment|/* unused */
name|char
name|ca_bdp
decl_stmt|;
comment|/* BDP to purge */
name|short
name|ca_cmdint
decl_stmt|;
comment|/* command queue transition interrupt flag */
name|short
name|ca_rspint
decl_stmt|;
comment|/* response queue transition interrupt flag */
name|long
name|ca_rspdsc
index|[
name|NRSP
index|]
decl_stmt|;
comment|/* response descriptors */
name|long
name|ca_cmddsc
index|[
name|NCMD
index|]
decl_stmt|;
comment|/* command descriptors */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ca_ringbase
value|ca_rspdsc[0]
end_define

begin_define
define|#
directive|define
name|UDA_OWN
value|0x80000000
end_define

begin_comment
comment|/* UDA owns this descriptor */
end_comment

begin_define
define|#
directive|define
name|UDA_INT
value|0x40000000
end_define

begin_comment
comment|/* allow interrupt on ring transition */
end_comment

begin_comment
comment|/*  * MSCP packet info  */
end_comment

begin_struct
struct|struct
name|mscp_header
block|{
name|short
name|uda_msglen
decl_stmt|;
comment|/* length of MSCP packet */
name|char
name|uda_credits
decl_stmt|;
comment|/* low 4 bits: credits, high 4 bits: msgtype */
name|char
name|uda_vcid
decl_stmt|;
comment|/* virtual circuit id */
block|}
struct|;
end_struct

end_unit

