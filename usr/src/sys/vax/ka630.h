begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ka630.h	7.3 (Berkeley) 7/9/88  */
end_comment

begin_comment
comment|/*  * Definitions specific to the ka630 uvax2 cpu card. Includes the tod  * clock chip and the cpu registers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VAX630
end_ifdef

begin_comment
comment|/* Bdr register bits */
end_comment

begin_define
define|#
directive|define
name|KA630BDR_PWROK
value|0x8000
end_define

begin_define
define|#
directive|define
name|KA630BDR_HLTENB
value|0x4000
end_define

begin_define
define|#
directive|define
name|KA630BDR_CPU
value|0x0c00
end_define

begin_define
define|#
directive|define
name|KA630BDR_BDG
value|0x0300
end_define

begin_define
define|#
directive|define
name|KA630BDR_DSPL
value|0x000f
end_define

begin_comment
comment|/* Memory system err reg. */
end_comment

begin_define
define|#
directive|define
name|KA630MSER_CD
value|0x00000300
end_define

begin_define
define|#
directive|define
name|KA630MSER_NXM
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KA630MSER_LPE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KA630MSER_QPE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KA630MSER_MERR
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|KA630MSER_CPUER
value|0x00000060
end_define

begin_define
define|#
directive|define
name|KA630MSER_DQPE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KA630MSER_LEB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KA630MSER_WRWP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KA630MSER_PAREN
value|0x00000001
end_define

begin_comment
comment|/* Mem. error address regs. */
end_comment

begin_define
define|#
directive|define
name|KA630CEAR_PG
value|0x00007fff
end_define

begin_define
define|#
directive|define
name|KA630DEAR_PG
value|0x00007fff
end_define

begin_comment
comment|/* Clock registers and constants */
end_comment

begin_define
define|#
directive|define
name|MINSEC
value|60
end_define

begin_define
define|#
directive|define
name|HRSEC
value|3600
end_define

begin_define
define|#
directive|define
name|KA630CLK_VRT
value|0200
end_define

begin_define
define|#
directive|define
name|KA630CLK_UIP
value|0200
end_define

begin_define
define|#
directive|define
name|KA630CLK_RATE
value|040
end_define

begin_define
define|#
directive|define
name|KA630CLK_ENABLE
value|06
end_define

begin_define
define|#
directive|define
name|KA630CLK_SET
value|0206
end_define

begin_comment
comment|/* cpmbx bits */
end_comment

begin_define
define|#
directive|define
name|KA630CLK_HLTACT
value|03
end_define

begin_comment
comment|/* halt action values */
end_comment

begin_define
define|#
directive|define
name|KA630CLK_RESTRT
value|01
end_define

begin_define
define|#
directive|define
name|KA630CLK_REBOOT
value|02
end_define

begin_define
define|#
directive|define
name|KA630CLK_HALT
value|03
end_define

begin_comment
comment|/* in progress flags */
end_comment

begin_define
define|#
directive|define
name|KA630CLK_BOOT
value|04
end_define

begin_define
define|#
directive|define
name|KA630CLK_RSTRT
value|010
end_define

begin_define
define|#
directive|define
name|KA630CLK_LANG
value|0360
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|ka630clock
block|{
name|u_short
name|sec
decl_stmt|;
name|u_short
name|secalrm
decl_stmt|;
name|u_short
name|min
decl_stmt|;
name|u_short
name|minalrm
decl_stmt|;
name|u_short
name|hr
decl_stmt|;
name|u_short
name|hralrm
decl_stmt|;
name|u_short
name|dayofwk
decl_stmt|;
name|u_short
name|day
decl_stmt|;
name|u_short
name|mon
decl_stmt|;
name|u_short
name|yr
decl_stmt|;
name|u_short
name|csr0
decl_stmt|;
name|u_short
name|csr1
decl_stmt|;
name|u_short
name|csr2
decl_stmt|;
name|u_short
name|csr3
decl_stmt|;
name|u_short
name|cpmbx
decl_stmt|;
comment|/* CPMBX is used by the boot rom. see ka630-ug-3.3.3 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ka630cpu
block|{
name|u_short
name|ka630_bdr
decl_stmt|;
name|u_short
name|ka630_xxx
decl_stmt|;
name|u_long
name|ka630_mser
decl_stmt|;
name|u_long
name|ka630_cear
decl_stmt|;
name|u_long
name|ka630_dear
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

