begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	up.c	4.1	11/9/80	*/
end_comment

begin_define
define|#
directive|define
name|OLDUCODE
end_define

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/inode.h"
end_include

begin_include
include|#
directive|include
file|"../h/pte.h"
end_include

begin_include
include|#
directive|include
file|"../h/uba.h"
end_include

begin_include
include|#
directive|include
file|"saio.h"
end_include

begin_define
define|#
directive|define
name|EMULEX
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EMULEX
end_ifdef

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|N
parameter_list|)
value|{ register int d; d = N; while (--d> 0); }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|N
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|upregs
block|{
name|short
name|upcs1
decl_stmt|;
comment|/* Control and Status register 1 */
name|short
name|upwc
decl_stmt|;
comment|/* Word count register */
name|short
name|upba
decl_stmt|;
comment|/* UNIBUS address register */
name|short
name|upda
decl_stmt|;
comment|/* Desired address register */
name|short
name|upcs2
decl_stmt|;
comment|/* Control and Status register 2*/
name|short
name|upds
decl_stmt|;
comment|/* Drive Status */
name|short
name|uper1
decl_stmt|;
comment|/* Error register 1 */
name|short
name|upas
decl_stmt|;
comment|/* Attention Summary */
name|short
name|upla
decl_stmt|;
comment|/* Look ahead */
name|short
name|updb
decl_stmt|;
comment|/* Data buffer */
name|short
name|upmr
decl_stmt|;
comment|/* Maintenance register */
name|short
name|updt
decl_stmt|;
comment|/* Drive type */
name|short
name|upsn
decl_stmt|;
comment|/* Serial number */
name|short
name|upof
decl_stmt|;
comment|/* Offset register */
name|short
name|upca
decl_stmt|;
comment|/* Desired Cylinder address register*/
name|short
name|upcc
decl_stmt|;
comment|/* Current Cylinder */
name|short
name|uper2
decl_stmt|;
comment|/* Error register 2 */
name|short
name|uper3
decl_stmt|;
comment|/* Error register 3 */
name|short
name|uppos
decl_stmt|;
comment|/* Burst error bit position */
name|short
name|uppat
decl_stmt|;
comment|/* Burst error bit pattern */
name|short
name|upbae
decl_stmt|;
comment|/* 11/70 bus extension */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|OLDUCODE
end_ifdef

begin_define
define|#
directive|define
name|SDELAY
value|500
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SDELAY
value|25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|sdelay
init|=
name|SDELAY
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|idelay
init|=
literal|500
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|UPADDR
value|((struct upregs *)(PHYSUMEM + 0776700 - UNIBASE))
end_define

begin_comment
comment|/* Drive commands, placed in upcs1 */
end_comment

begin_define
define|#
directive|define
name|GO
value|01
end_define

begin_comment
comment|/* Go bit, set in all commands */
end_comment

begin_define
define|#
directive|define
name|PRESET
value|020
end_define

begin_comment
comment|/* Preset drive at init or after errors */
end_comment

begin_define
define|#
directive|define
name|OFFSET
value|014
end_define

begin_comment
comment|/* Offset heads to try to recover error */
end_comment

begin_define
define|#
directive|define
name|RTC
value|016
end_define

begin_comment
comment|/* Return to center-line after OFFSET */
end_comment

begin_define
define|#
directive|define
name|SEARCH
value|030
end_define

begin_comment
comment|/* Search for cylinder+sector */
end_comment

begin_define
define|#
directive|define
name|SEEK
value|04
end_define

begin_comment
comment|/* Seek to cylinder */
end_comment

begin_define
define|#
directive|define
name|RECAL
value|06
end_define

begin_comment
comment|/* Recalibrate, needed after seek error */
end_comment

begin_define
define|#
directive|define
name|DCLR
value|010
end_define

begin_comment
comment|/* Drive clear, after error */
end_comment

begin_define
define|#
directive|define
name|WCOM
value|060
end_define

begin_comment
comment|/* Write */
end_comment

begin_define
define|#
directive|define
name|RCOM
value|070
end_define

begin_comment
comment|/* Read */
end_comment

begin_comment
comment|/* Other bits of upcs1 */
end_comment

begin_define
define|#
directive|define
name|IE
value|0100
end_define

begin_comment
comment|/* Controller wide interrupt enable */
end_comment

begin_define
define|#
directive|define
name|TRE
value|040000
end_define

begin_comment
comment|/* Transfer error */
end_comment

begin_define
define|#
directive|define
name|RDY
value|0200
end_define

begin_comment
comment|/* Transfer terminated */
end_comment

begin_comment
comment|/* Drive status bits of upds */
end_comment

begin_define
define|#
directive|define
name|PIP
value|020000
end_define

begin_comment
comment|/* Positioning in progress */
end_comment

begin_define
define|#
directive|define
name|ERR
value|040000
end_define

begin_comment
comment|/* Error has occurred, DCLR necessary */
end_comment

begin_define
define|#
directive|define
name|VV
value|0100
end_define

begin_comment
comment|/* Volume is valid, set by PRESET */
end_comment

begin_define
define|#
directive|define
name|DPR
value|0400
end_define

begin_comment
comment|/* Drive has been preset */
end_comment

begin_define
define|#
directive|define
name|MOL
value|010000
end_define

begin_comment
comment|/* Drive is online, heads loaded, etc */
end_comment

begin_define
define|#
directive|define
name|DRY
value|0200
end_define

begin_comment
comment|/* Drive ready */
end_comment

begin_comment
comment|/* Bits of upcs2 */
end_comment

begin_define
define|#
directive|define
name|CLR
value|040
end_define

begin_comment
comment|/* Controller clear */
end_comment

begin_comment
comment|/* Bits of uper1 */
end_comment

begin_define
define|#
directive|define
name|DCK
value|0100000
end_define

begin_comment
comment|/* Ecc error occurred */
end_comment

begin_define
define|#
directive|define
name|ECH
value|0100
end_define

begin_comment
comment|/* Ecc error was unrecoverable */
end_comment

begin_define
define|#
directive|define
name|WLE
value|04000
end_define

begin_comment
comment|/* Attempt to write read-only drive */
end_comment

begin_comment
comment|/* Bits of upof; the offset bits above are also in this register */
end_comment

begin_define
define|#
directive|define
name|FMT22
value|010000
end_define

begin_comment
comment|/* 16 bits/word, must be always set */
end_comment

begin_struct
struct|struct
name|devsize
block|{
name|daddr_t
name|cyloff
decl_stmt|;
block|}
name|up_sizes
index|[]
init|=
block|{
literal|0
block|,
literal|27
block|,
literal|68
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|82
block|}
struct|;
end_struct

begin_expr_stmt
name|upopen
argument_list|(
name|io
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|up_sizes
index|[
name|io
operator|->
name|i_boff
index|]
operator|.
name|cyloff
operator|==
operator|-
literal|1
operator|||
name|io
operator|->
name|i_boff
operator|<
literal|0
operator|||
name|io
operator|->
name|i_boff
operator|>
literal|7
condition|)
name|_stop
argument_list|(
literal|"up bad unit"
argument_list|)
expr_stmt|;
name|io
operator|->
name|i_boff
operator|=
name|up_sizes
index|[
name|io
operator|->
name|i_boff
index|]
operator|.
name|cyloff
operator|*
literal|32
operator|*
literal|19
expr_stmt|;
block|}
end_block

begin_expr_stmt
name|upstrategy
argument_list|(
name|io
argument_list|,
name|func
argument_list|)
specifier|register
expr|struct
name|iob
operator|*
name|io
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|int
name|unit
decl_stmt|,
name|nspc
decl_stmt|,
name|ns
decl_stmt|,
name|cn
decl_stmt|,
name|tn
decl_stmt|,
name|sn
decl_stmt|;
name|daddr_t
name|bn
decl_stmt|;
name|int
name|info
decl_stmt|;
specifier|register
name|short
modifier|*
name|rp
decl_stmt|;
name|int
name|occ
init|=
name|io
operator|->
name|i_cc
decl_stmt|;
specifier|register
name|struct
name|upregs
modifier|*
name|upaddr
init|=
name|UPADDR
decl_stmt|;
name|unit
operator|=
name|io
operator|->
name|i_unit
expr_stmt|;
name|bn
operator|=
name|io
operator|->
name|i_bn
expr_stmt|;
name|nspc
operator|=
literal|32
operator|*
literal|19
expr_stmt|;
name|ns
operator|=
literal|32
expr_stmt|;
name|cn
operator|=
name|bn
operator|/
name|nspc
expr_stmt|;
name|sn
operator|=
name|bn
operator|%
name|nspc
expr_stmt|;
name|tn
operator|=
name|sn
operator|/
name|ns
expr_stmt|;
name|sn
operator|=
name|sn
operator|%
name|ns
expr_stmt|;
name|upaddr
operator|->
name|upcs2
operator|=
name|unit
expr_stmt|;
name|DELAY
argument_list|(
name|sdelay
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|upaddr
operator|->
name|upds
operator|&
name|VV
operator|)
operator|==
literal|0
condition|)
block|{
name|upaddr
operator|->
name|upcs1
operator|=
name|DCLR
operator||
name|GO
expr_stmt|;
name|DELAY
argument_list|(
name|idelay
argument_list|)
expr_stmt|;
name|upaddr
operator|->
name|upcs1
operator|=
name|PRESET
operator||
name|GO
expr_stmt|;
name|DELAY
argument_list|(
name|idelay
argument_list|)
expr_stmt|;
name|upaddr
operator|->
name|upof
operator|=
name|FMT22
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|upaddr
operator|->
name|upds
operator|&
operator|(
name|DPR
operator||
name|MOL
operator|)
operator|)
operator|!=
operator|(
name|DPR
operator||
name|MOL
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"after fmt22 upds %o\n"
argument_list|,
name|upaddr
operator|->
name|upds
argument_list|)
expr_stmt|;
name|_stop
argument_list|(
literal|"up !DPR || !MOL"
argument_list|)
expr_stmt|;
block|}
name|info
operator|=
name|ubasetup
argument_list|(
name|io
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|rp
operator|=
operator|(
name|short
operator|*
operator|)
operator|&
name|upaddr
operator|->
name|upda
expr_stmt|;
name|upaddr
operator|->
name|upca
operator|=
name|cn
expr_stmt|;
operator|*
name|rp
operator|=
operator|(
name|tn
operator|<<
literal|8
operator|)
operator|+
name|sn
expr_stmt|;
operator|*
operator|--
name|rp
operator|=
name|info
expr_stmt|;
operator|*
operator|--
name|rp
operator|=
operator|-
name|io
operator|->
name|i_cc
operator|/
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
if|if
condition|(
name|func
operator|==
name|READ
condition|)
operator|*
operator|--
name|rp
operator|=
name|GO
operator||
name|RCOM
expr_stmt|;
else|else
operator|*
operator|--
name|rp
operator|=
name|GO
operator||
name|WCOM
expr_stmt|;
name|DELAY
argument_list|(
name|sdelay
argument_list|)
expr_stmt|;
do|do
block|{
name|DELAY
argument_list|(
literal|25
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|upaddr
operator|->
name|upcs1
operator|&
name|RDY
operator|)
operator|==
literal|0
condition|)
do|;
name|DELAY
argument_list|(
literal|200
argument_list|)
expr_stmt|;
if|if
condition|(
name|upaddr
operator|->
name|upcs1
operator|&
name|ERR
condition|)
block|{
name|printf
argument_list|(
literal|"disk error: cyl=%d track=%d sect=%d cs1=%X, er1=%X\n"
argument_list|,
name|cn
argument_list|,
name|tn
argument_list|,
name|sn
argument_list|,
name|upaddr
operator|->
name|upcs1
argument_list|,
name|upaddr
operator|->
name|uper1
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|io
operator|->
name|i_cc
operator|!=
name|occ
condition|)
name|printf
argument_list|(
literal|"returned %d\n"
argument_list|,
name|io
operator|->
name|i_cc
argument_list|)
expr_stmt|;
name|ubafree
argument_list|(
name|info
argument_list|)
expr_stmt|;
return|return
operator|(
name|io
operator|->
name|i_cc
operator|)
return|;
block|}
end_block

end_unit

