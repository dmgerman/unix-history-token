begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)udareg.h	7.2 (Berkeley) 10/23/87  */
end_comment

begin_comment
comment|/*  * UDA50 registers and structures  */
end_comment

begin_comment
comment|/*  * Writing any value to udaip starts initialisation.  Reading from it  * when the UDA is running makes the UDA look through the command ring  * to find any new commands.  Reading udasa gives status; writing it  * during initialisation sets things up.  */
end_comment

begin_struct
struct|struct
name|udadevice
block|{
name|u_short
name|udaip
decl_stmt|;
comment|/* initialisation and polling */
name|u_short
name|udasa
decl_stmt|;
comment|/* status and address */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in UDA status register during initialisation  */
end_comment

begin_define
define|#
directive|define
name|UDA_ERR
value|0x8000
end_define

begin_comment
comment|/* error */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP4
value|0x4000
end_define

begin_comment
comment|/* step 4 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP3
value|0x2000
end_define

begin_comment
comment|/* step 3 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP2
value|0x1000
end_define

begin_comment
comment|/* step 2 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_STEP1
value|0x0800
end_define

begin_comment
comment|/* step 1 has started */
end_comment

begin_define
define|#
directive|define
name|UDA_NV
value|0x0400
end_define

begin_comment
comment|/* no host settable interrupt vector */
end_comment

begin_define
define|#
directive|define
name|UDA_QB
value|0x0200
end_define

begin_comment
comment|/* controller supports Q22 bus */
end_comment

begin_define
define|#
directive|define
name|UDA_DI
value|0x0100
end_define

begin_comment
comment|/* controller implements diagnostics */
end_comment

begin_define
define|#
directive|define
name|UDA_IE
value|0x0080
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|UDA_NCNRMASK
value|0x003f
end_define

begin_comment
comment|/* in STEP1, bits 0-2=NCMDL2, 3-5=NRSPL2 */
end_comment

begin_define
define|#
directive|define
name|UDA_IVECMASK
value|0x007f
end_define

begin_comment
comment|/* in STEP2, bits 0-6 are interruptvec / 4 */
end_comment

begin_define
define|#
directive|define
name|UDA_PI
value|0x0001
end_define

begin_comment
comment|/* host requests adapter purge interrupts */
end_comment

begin_comment
comment|/*  * Bits in UDA status register after initialisation  */
end_comment

begin_define
define|#
directive|define
name|UDA_GO
value|0x0001
end_define

begin_comment
comment|/* run */
end_comment

begin_define
define|#
directive|define
name|UDASR_BITS
define|\
value|"\20\20ERR\17STEP4\16STEP3\15STEP2\14STEP1\13NV\12QB\11DI\10IE\1GO"
end_define

begin_comment
comment|/*  * UDA Communications Area.  Note that this structure definition  * requires NRSP and NCMD to be defined already.  */
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
comment|/* command ring transition flag */
name|short
name|ca_rspint
decl_stmt|;
comment|/* response ring transition flag */
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

begin_comment
comment|/*  * Simplified routines (e.g., uddump) reprogram the UDA50 for one command  * and one response at a time; uda1ca is like udaca except that it provides  * exactly one command and response descriptor.  */
end_comment

begin_struct
struct|struct
name|uda1ca
block|{
name|short
name|ca_xxx1
decl_stmt|;
name|char
name|ca_xxx2
decl_stmt|;
name|char
name|ca_bdp
decl_stmt|;
name|short
name|ca_cmdint
decl_stmt|;
name|short
name|ca_rspint
decl_stmt|;
name|long
name|ca_rspdsc
decl_stmt|;
name|long
name|ca_cmddsc
decl_stmt|;
block|}
struct|;
end_struct

end_unit

