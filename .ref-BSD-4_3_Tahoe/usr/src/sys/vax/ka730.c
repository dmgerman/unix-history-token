begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ka730.c	7.2 (Berkeley) 7/9/88  */
end_comment

begin_if
if|#
directive|if
name|VAX730
end_if

begin_comment
comment|/*  * 730-specific code.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"cpu.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"mtpr.h"
end_include

begin_struct
struct|struct
name|mcr730
block|{
name|int
name|mc_addr
decl_stmt|;
comment|/* address and syndrome */
name|int
name|mc_err
decl_stmt|;
comment|/* error bits */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|M730_UNCORR
value|0x80000000
end_define

begin_comment
comment|/* rds, uncorrectable error */
end_comment

begin_define
define|#
directive|define
name|M730_CRD
value|0x40000000
end_define

begin_comment
comment|/* crd */
end_comment

begin_define
define|#
directive|define
name|M730_FTBPE
value|0x20000000
end_define

begin_comment
comment|/* force tbuf parity error */
end_comment

begin_define
define|#
directive|define
name|M730_ENACRD
value|0x10000000
end_define

begin_comment
comment|/* enable crd interrupt */
end_comment

begin_define
define|#
directive|define
name|M730_MME
value|0x08000000
end_define

begin_comment
comment|/* mem-man enable (ala ipr) */
end_comment

begin_define
define|#
directive|define
name|M730_DM
value|0x04000000
end_define

begin_comment
comment|/* diagnostic mode */
end_comment

begin_define
define|#
directive|define
name|M730_DISECC
value|0x02000000
end_define

begin_comment
comment|/* disable ecc */
end_comment

begin_define
define|#
directive|define
name|M730_INH
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_err = M730_MME)
end_define

begin_define
define|#
directive|define
name|M730_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_err = (M730_MME|M730_ENACRD))
end_define

begin_define
define|#
directive|define
name|M730_ERR
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_err& (M730_UNCORR|M730_CRD))
end_define

begin_define
define|#
directive|define
name|M730_SYN
parameter_list|(
name|addr
parameter_list|)
value|((mcr)->mc_addr& 0x7f)
end_define

begin_define
define|#
directive|define
name|M730_ADDR
parameter_list|(
name|addr
parameter_list|)
value|(((mcr)->mc_addr>> 8)& 0x7fff)
end_define

begin_comment
comment|/* enable crd interrupts */
end_comment

begin_macro
name|ka730_memenable
argument_list|()
end_macro

begin_block
block|{
name|M730_ENA
argument_list|(
operator|(
expr|struct
name|mcr730
operator|*
operator|)
name|mcraddr
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* log crd errors */
end_comment

begin_macro
name|ka730_memerr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|mcr730
modifier|*
name|mcr
init|=
operator|(
expr|struct
name|mcr730
operator|*
operator|)
name|mcraddr
index|[
literal|0
index|]
decl_stmt|;
name|struct
name|mcr730
name|amcr
decl_stmt|;
comment|/* 	 * Must be careful on the 730 not to use invalid 	 * instructions in I/O space, so make a copy; 	 */
name|amcr
operator|.
name|mc_addr
operator|=
name|mcr
operator|->
name|mc_addr
expr_stmt|;
name|amcr
operator|.
name|mc_err
operator|=
name|mcr
operator|->
name|mc_err
expr_stmt|;
if|if
condition|(
name|M730_ERR
argument_list|(
operator|&
name|amcr
argument_list|)
condition|)
block|{
name|printf
argument_list|(
literal|"mcr0: %s"
argument_list|,
operator|(
name|amcr
operator|.
name|mc_err
operator|&
name|M730_UNCORR
operator|)
condition|?
literal|"hard error"
else|:
literal|"soft ecc"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" addr %x syn %x\n"
argument_list|,
name|M730_ADDR
argument_list|(
operator|&
name|amcr
argument_list|)
argument_list|,
name|M730_SYN
argument_list|(
operator|&
name|amcr
argument_list|)
argument_list|)
expr_stmt|;
name|M730_INH
argument_list|(
name|mcr
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_define
define|#
directive|define
name|NMC730
value|12
end_define

begin_decl_stmt
name|char
modifier|*
name|mc730
index|[]
init|=
block|{
literal|"tb par"
block|,
literal|"bad retry"
block|,
literal|"bad intr id"
block|,
literal|"cant write ptem"
block|,
literal|"unkn mcr err"
block|,
literal|"iib rd err"
block|,
literal|"nxm ref"
block|,
literal|"cp rds"
block|,
literal|"unalgn ioref"
block|,
literal|"nonlw ioref"
block|,
literal|"bad ioaddr"
block|,
literal|"unalgn ubaddr"
block|, }
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|mc730frame
block|{
name|int
name|mc3_bcnt
decl_stmt|;
comment|/* byte count == 0xc */
name|int
name|mc3_summary
decl_stmt|;
comment|/* summary parameter */
name|int
name|mc3_parm
index|[
literal|2
index|]
decl_stmt|;
comment|/* parameter 1 and 2 */
name|int
name|mc3_pc
decl_stmt|;
comment|/* trapped pc */
name|int
name|mc3_psl
decl_stmt|;
comment|/* trapped psl */
block|}
struct|;
end_struct

begin_macro
name|ka730_mchk
argument_list|(
argument|cmcf
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|cmcf
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|mc730frame
modifier|*
name|mcf
init|=
operator|(
expr|struct
name|mc730frame
operator|*
operator|)
name|cmcf
decl_stmt|;
specifier|register
name|u_int
name|type
init|=
name|mcf
operator|->
name|mc3_summary
decl_stmt|;
name|printf
argument_list|(
literal|"machine check %x: %s\n"
argument_list|,
name|type
argument_list|,
name|type
operator|<
name|NMC730
condition|?
name|mc730
index|[
name|type
index|]
else|:
literal|"???"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tparams %x,%x pc %x psl %x mcesr %x\n"
argument_list|,
name|mcf
operator|->
name|mc3_parm
index|[
literal|0
index|]
argument_list|,
name|mcf
operator|->
name|mc3_parm
index|[
literal|1
index|]
argument_list|,
name|mcf
operator|->
name|mc3_pc
argument_list|,
name|mcf
operator|->
name|mc3_psl
argument_list|,
name|mfpr
argument_list|(
name|MCESR
argument_list|)
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|MCESR
argument_list|,
literal|0xf
argument_list|)
expr_stmt|;
return|return
operator|(
name|MCHK_PANIC
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

