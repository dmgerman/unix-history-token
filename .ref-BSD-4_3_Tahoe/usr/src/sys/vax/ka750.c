begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ka750.c	7.2 (Berkeley) 7/9/88  */
end_comment

begin_if
if|#
directive|if
name|VAX750
end_if

begin_comment
comment|/*  * 750-specific code.  */
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
name|mcr750
block|{
name|int
name|mc_err
decl_stmt|;
comment|/* error bits */
name|int
name|mc_inh
decl_stmt|;
comment|/* inhibit crd */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|M750_ICRD
value|0x10000000
end_define

begin_comment
comment|/* inhibit crd interrupts, in [1] */
end_comment

begin_define
define|#
directive|define
name|M750_UNCORR
value|0xc0000000
end_define

begin_comment
comment|/* uncorrectable error, in [0] */
end_comment

begin_define
define|#
directive|define
name|M750_CORERR
value|0x20000000
end_define

begin_comment
comment|/* correctable error, in [0] */
end_comment

begin_define
define|#
directive|define
name|M750_INH
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_inh = 0)
end_define

begin_define
define|#
directive|define
name|M750_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_err = (M750_UNCORR|M750_CORERR), \ 			 (mcr)->mc_inh = M750_ICRD)
end_define

begin_define
define|#
directive|define
name|M750_ERR
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_err& (M750_UNCORR|M750_CORERR))
end_define

begin_define
define|#
directive|define
name|M750_SYN
parameter_list|(
name|err
parameter_list|)
value|((err)& 0x7f)
end_define

begin_define
define|#
directive|define
name|M750_ADDR
parameter_list|(
name|err
parameter_list|)
value|(((err)>> 9)& 0x7fff)
end_define

begin_comment
comment|/* enable crd interrupts */
end_comment

begin_macro
name|ka750_memenable
argument_list|()
end_macro

begin_block
block|{
name|M750_ENA
argument_list|(
operator|(
expr|struct
name|mcr750
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
name|ka750_memerr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|mcr750
modifier|*
name|mcr
init|=
operator|(
expr|struct
name|mcr750
operator|*
operator|)
name|mcraddr
index|[
literal|0
index|]
decl_stmt|;
specifier|register
name|int
name|err
decl_stmt|;
if|if
condition|(
name|M750_ERR
argument_list|(
name|mcr
argument_list|)
condition|)
block|{
name|err
operator|=
name|mcr
operator|->
name|mc_err
expr_stmt|;
comment|/* careful with i/o space refs */
name|printf
argument_list|(
literal|"mcr0: %s"
argument_list|,
name|err
operator|&
name|M750_UNCORR
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
name|M750_ADDR
argument_list|(
name|err
argument_list|)
argument_list|,
name|M750_SYN
argument_list|(
name|err
argument_list|)
argument_list|)
expr_stmt|;
name|M750_INH
argument_list|(
name|mcr
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mc780750
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|mc750frame
block|{
name|int
name|mc5_bcnt
decl_stmt|;
comment|/* byte count == 0x28 */
name|int
name|mc5_summary
decl_stmt|;
comment|/* summary parameter (as above) */
name|int
name|mc5_va
decl_stmt|;
comment|/* virtual address register */
name|int
name|mc5_errpc
decl_stmt|;
comment|/* error pc */
name|int
name|mc5_mdr
decl_stmt|;
name|int
name|mc5_svmode
decl_stmt|;
comment|/* saved mode register */
name|int
name|mc5_rdtimo
decl_stmt|;
comment|/* read lock timeout */
name|int
name|mc5_tbgpar
decl_stmt|;
comment|/* tb group parity error register */
name|int
name|mc5_cacherr
decl_stmt|;
comment|/* cache error register */
name|int
name|mc5_buserr
decl_stmt|;
comment|/* bus error register */
name|int
name|mc5_mcesr
decl_stmt|;
comment|/* machine check status register */
name|int
name|mc5_pc
decl_stmt|;
comment|/* trapped pc */
name|int
name|mc5_psl
decl_stmt|;
comment|/* trapped psl */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MC750_TBERR
value|2
end_define

begin_comment
comment|/* type code of cp tbuf par */
end_comment

begin_define
define|#
directive|define
name|MC750_TBPAR
value|4
end_define

begin_comment
comment|/* tbuf par bit in mcesr */
end_comment

begin_macro
name|ka750_mchk
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
name|mc750frame
modifier|*
name|mcf
init|=
operator|(
expr|struct
name|mc750frame
operator|*
operator|)
name|cmcf
decl_stmt|;
specifier|register
name|int
name|type
init|=
name|mcf
operator|->
name|mc5_summary
decl_stmt|;
name|int
name|mcsr
init|=
name|mfpr
argument_list|(
name|MCSR
argument_list|)
decl_stmt|;
name|printf
argument_list|(
literal|"machine check %x: %s%s\n"
argument_list|,
name|type
argument_list|,
name|mc780750
index|[
name|type
operator|&
literal|0xf
index|]
argument_list|,
operator|(
name|type
operator|&
literal|0xf0
operator|)
condition|?
literal|" abort"
else|:
literal|" fault"
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|TBIA
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|MCESR
argument_list|,
literal|0xf
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tva %x errpc %x mdr %x smr %x rdtimo %x tbgpar %x cacherr %x\n"
argument_list|,
name|mcf
operator|->
name|mc5_va
argument_list|,
name|mcf
operator|->
name|mc5_errpc
argument_list|,
name|mcf
operator|->
name|mc5_mdr
argument_list|,
name|mcf
operator|->
name|mc5_svmode
argument_list|,
name|mcf
operator|->
name|mc5_rdtimo
argument_list|,
name|mcf
operator|->
name|mc5_tbgpar
argument_list|,
name|mcf
operator|->
name|mc5_cacherr
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tbuserr %x mcesr %x pc %x psl %x mcsr %x\n"
argument_list|,
name|mcf
operator|->
name|mc5_buserr
argument_list|,
name|mcf
operator|->
name|mc5_mcesr
argument_list|,
name|mcf
operator|->
name|mc5_pc
argument_list|,
name|mcf
operator|->
name|mc5_psl
argument_list|,
name|mcsr
argument_list|)
expr_stmt|;
if|if
condition|(
name|type
operator|==
name|MC750_TBERR
operator|&&
operator|(
name|mcf
operator|->
name|mc5_mcesr
operator|&
literal|0xe
operator|)
operator|==
name|MC750_TBPAR
condition|)
block|{
name|printf
argument_list|(
literal|"tbuf par: flushing and returning\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|MCHK_RECOVERED
operator|)
return|;
block|}
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

