begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ka860.c	7.2 (Berkeley) 7/9/88  */
end_comment

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_comment
comment|/*  * VAX 8600 specific routines.  */
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
file|"mtpr.h"
end_include

begin_comment
comment|/*  * 8600 memory register (MERG) bit definitions  */
end_comment

begin_define
define|#
directive|define
name|M8600_ICRD
value|0x400
end_define

begin_comment
comment|/* inhibit crd interrupts */
end_comment

begin_define
define|#
directive|define
name|M8600_TB_ERR
value|0xf00
end_define

begin_comment
comment|/* translation buffer error mask */
end_comment

begin_comment
comment|/*  * MDECC register  */
end_comment

begin_define
define|#
directive|define
name|M8600_ADDR_PE
value|0x080000
end_define

begin_comment
comment|/* address parity error */
end_comment

begin_define
define|#
directive|define
name|M8600_DBL_ERR
value|0x100000
end_define

begin_comment
comment|/* data double bit error */
end_comment

begin_define
define|#
directive|define
name|M8600_SNG_ERR
value|0x200000
end_define

begin_comment
comment|/* data single bit error */
end_comment

begin_define
define|#
directive|define
name|M8600_BDT_ERR
value|0x400000
end_define

begin_comment
comment|/* bad data error */
end_comment

begin_comment
comment|/*  * ESPA register is used to address scratch pad registers in the Ebox.  * To access a register in the scratch pad, write the ESPA with the address  * and then read the ESPD register.    *  * NOTE:  In assmebly code, the mfpr instruction that reads the ESPD  *	  register must immedately follow the mtpr instruction that setup  *	  the ESPA register -- per the VENUS processor register spec.  *  * The scratchpad registers that are supplied for a single bit ECC   * error are:  */
end_comment

begin_define
define|#
directive|define
name|SPAD_MSTAT1
value|0x25
end_define

begin_comment
comment|/* scratch pad mstat1 register	*/
end_comment

begin_define
define|#
directive|define
name|SPAD_MSTAT2
value|0x26
end_define

begin_comment
comment|/* scratch pad mstat2 register	*/
end_comment

begin_define
define|#
directive|define
name|SPAD_MDECC
value|0x27
end_define

begin_comment
comment|/* scratch pad mdecc register	*/
end_comment

begin_define
define|#
directive|define
name|SPAD_MEAR
value|0x2a
end_define

begin_comment
comment|/* scratch pad mear register	*/
end_comment

begin_define
define|#
directive|define
name|M8600_MEMERR
parameter_list|(
name|mdecc
parameter_list|)
value|((mdecc)& 0x780000)
end_define

begin_define
define|#
directive|define
name|M8600_HRDERR
parameter_list|(
name|mdecc
parameter_list|)
value|((mdecc)& 0x580000)
end_define

begin_define
define|#
directive|define
name|M8600_SYN
parameter_list|(
name|mdecc
parameter_list|)
value|(((mdecc)>> 9)& 0x3f)
end_define

begin_define
define|#
directive|define
name|M8600_ADDR
parameter_list|(
name|mear
parameter_list|)
value|((mear)& 0x3ffffffc)
end_define

begin_define
define|#
directive|define
name|M8600_ARRAY
parameter_list|(
name|mear
parameter_list|)
value|(((mear)>> 22)& 0x0f)
end_define

begin_define
define|#
directive|define
name|M8600_MDECC_BITS
define|\
value|"\20\27BAD_DT_ERR\26SNG_BIT_ERR\25DBL_BIT_ERR\24ADDR_PE"
end_define

begin_define
define|#
directive|define
name|M8600_MSTAT1_BITS
value|"\20\30CPR_PE_A\27CPR_PE_B\26ABUS_DT_PE\ \25ABUS_CTL_MSK_PE\24ABUS_ADR_PE\23ABUS_C/A_CYCLE\22ABUS_ADP_1\21ABUS_ADP_0\ \20TB_MISS\17BLK_HIT\16C0_TAG_MISS\15CHE_MISS\14TB_VAL_ERR\13TB_PTE_B_PE\ \12TB_PTE_A_PE\11TB_TAG_PE\10WR_DT_PE_B3\7WR_DT_PE_B2\6WR_DT_PE_B1\ \5WR_DT_PE_B0\4CHE_RD_DT_PE\3CHE_SEL\2ANY_REFL\1CP_BW_CHE_DT_PE"
end_define

begin_define
define|#
directive|define
name|M8600_MSTAT2_BITS
value|"\20\20CP_BYT_WR\17ABUS_BD_DT_CODE\10MULT_ERR\ \7CHE_TAG_PE\6CHE_TAG_W_PE\5CHE_WRTN_BIT\4NXM\3CP-IO_BUF_ERR\2MBOX_LOCK"
end_define

begin_comment
comment|/* enable CRD reports */
end_comment

begin_macro
name|ka860_memenable
argument_list|()
end_macro

begin_block
block|{
name|mtpr
argument_list|(
name|MERG
argument_list|,
name|mfpr
argument_list|(
name|MERG
argument_list|)
operator|&
operator|~
name|M8600_ICRD
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* log CRD errors */
end_comment

begin_macro
name|ka860_memerr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|reg11
decl_stmt|;
comment|/* known to be r11 below */
name|int
name|mdecc
decl_stmt|,
name|mear
decl_stmt|,
name|mstat1
decl_stmt|,
name|mstat2
decl_stmt|,
name|array
decl_stmt|;
comment|/* 	 * Scratchpad registers in the Ebox must be read by 	 * storing their ID number in ESPA and then immediately 	 * reading ESPD's contents with no other intervening 	 * machine instructions! 	 * 	 * The asm's below have a number of constants which 	 * are defined correctly above and in mtpr.h. 	 */
ifdef|#
directive|ifdef
name|lint
name|reg11
operator|=
literal|0
expr_stmt|;
else|#
directive|else
asm|asm("mtpr $0x27,$0x4e; mfpr $0x4f,r11");
endif|#
directive|endif
name|mdecc
operator|=
name|reg11
expr_stmt|;
comment|/* must acknowledge interrupt? */
if|if
condition|(
name|M8600_MEMERR
argument_list|(
name|mdecc
argument_list|)
condition|)
block|{
asm|asm("mtpr $0x2a,$0x4e; mfpr $0x4f,r11");
name|mear
operator|=
name|reg11
expr_stmt|;
asm|asm("mtpr $0x25,$0x4e; mfpr $0x4f,r11");
name|mstat1
operator|=
name|reg11
expr_stmt|;
asm|asm("mtpr $0x26,$0x4e; mfpr $0x4f,r11");
name|mstat2
operator|=
name|reg11
expr_stmt|;
name|array
operator|=
name|M8600_ARRAY
argument_list|(
name|mear
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"mcr0: ecc error, addr %x (array %d) syn %x\n"
argument_list|,
name|M8600_ADDR
argument_list|(
name|mear
argument_list|)
argument_list|,
name|array
argument_list|,
name|M8600_SYN
argument_list|(
name|mdecc
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tMSTAT1 = %b\n\tMSTAT2 = %b\n"
argument_list|,
name|mstat1
argument_list|,
name|M8600_MSTAT1_BITS
argument_list|,
name|mstat2
argument_list|,
name|M8600_MSTAT2_BITS
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|EHSR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|MERG
argument_list|,
name|mfpr
argument_list|(
name|MERG
argument_list|)
operator||
name|M8600_ICRD
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_define
define|#
directive|define
name|NMC8600
value|7
end_define

begin_decl_stmt
name|char
modifier|*
name|mc8600
index|[]
init|=
block|{
literal|"unkn type"
block|,
literal|"fbox error"
block|,
literal|"ebox error"
block|,
literal|"ibox error"
block|,
literal|"mbox error"
block|,
literal|"tbuf error"
block|,
literal|"mbox 1D error"
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* codes for above */
end_comment

begin_define
define|#
directive|define
name|MC_FBOX
value|1
end_define

begin_define
define|#
directive|define
name|MC_EBOX
value|2
end_define

begin_define
define|#
directive|define
name|MC_IBOX
value|3
end_define

begin_define
define|#
directive|define
name|MC_MBOX
value|4
end_define

begin_define
define|#
directive|define
name|MC_TBUF
value|5
end_define

begin_define
define|#
directive|define
name|MC_MBOX1D
value|6
end_define

begin_comment
comment|/* error bits */
end_comment

begin_define
define|#
directive|define
name|MBOX_FE
value|0x8000
end_define

begin_comment
comment|/* Mbox fatal error */
end_comment

begin_define
define|#
directive|define
name|FBOX_SERV
value|0x10000000
end_define

begin_comment
comment|/* Fbox service error */
end_comment

begin_define
define|#
directive|define
name|IBOX_ERR
value|0x2000
end_define

begin_comment
comment|/* Ibox error */
end_comment

begin_define
define|#
directive|define
name|EBOX_ERR
value|0x1e00
end_define

begin_comment
comment|/* Ebox error */
end_comment

begin_define
define|#
directive|define
name|MBOX_1D
value|0x81d0000
end_define

begin_comment
comment|/* Mbox 1D error */
end_comment

begin_define
define|#
directive|define
name|EDP_PE
value|0x200
end_define

begin_struct
struct|struct
name|mc8600frame
block|{
name|int
name|mc86_bcnt
decl_stmt|;
comment|/* byte count == 0x58 */
name|int
name|mc86_ehmsts
decl_stmt|;
name|int
name|mc86_evmqsav
decl_stmt|;
name|int
name|mc86_ebcs
decl_stmt|;
name|int
name|mc86_edpsr
decl_stmt|;
name|int
name|mc86_cslint
decl_stmt|;
name|int
name|mc86_ibesr
decl_stmt|;
name|int
name|mc86_ebxwd1
decl_stmt|;
name|int
name|mc86_ebxwd2
decl_stmt|;
name|int
name|mc86_ivasav
decl_stmt|;
name|int
name|mc86_vibasav
decl_stmt|;
name|int
name|mc86_esasav
decl_stmt|;
name|int
name|mc86_isasav
decl_stmt|;
name|int
name|mc86_cpc
decl_stmt|;
name|int
name|mc86_mstat1
decl_stmt|;
name|int
name|mc86_mstat2
decl_stmt|;
name|int
name|mc86_mdecc
decl_stmt|;
name|int
name|mc86_merg
decl_stmt|;
name|int
name|mc86_cshctl
decl_stmt|;
name|int
name|mc86_mear
decl_stmt|;
name|int
name|mc86_medr
decl_stmt|;
name|int
name|mc86_accs
decl_stmt|;
name|int
name|mc86_cses
decl_stmt|;
name|int
name|mc86_pc
decl_stmt|;
comment|/* trapped pc */
name|int
name|mc86_psl
decl_stmt|;
comment|/* trapped psl */
block|}
struct|;
end_struct

begin_comment
comment|/* machine check */
end_comment

begin_macro
name|ka860_mchk
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
name|mc8600frame
modifier|*
name|mcf
init|=
operator|(
expr|struct
name|mc8600frame
operator|*
operator|)
name|cmcf
decl_stmt|;
specifier|register
name|int
name|type
decl_stmt|;
if|if
condition|(
name|mcf
operator|->
name|mc86_ebcs
operator|&
name|MBOX_FE
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_MBOX
expr_stmt|;
elseif|else
if|if
condition|(
name|mcf
operator|->
name|mc86_ehmsts
operator|&
name|FBOX_SERV
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_FBOX
expr_stmt|;
elseif|else
if|if
condition|(
name|mcf
operator|->
name|mc86_ebcs
operator|&
name|EBOX_ERR
condition|)
block|{
if|if
condition|(
name|mcf
operator|->
name|mc86_ebcs
operator|&
name|EDP_PE
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_MBOX
expr_stmt|;
else|else
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_EBOX
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|mcf
operator|->
name|mc86_ehmsts
operator|&
name|IBOX_ERR
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_IBOX
expr_stmt|;
elseif|else
if|if
condition|(
name|mcf
operator|->
name|mc86_mstat1
operator|&
name|M8600_TB_ERR
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_TBUF
expr_stmt|;
elseif|else
if|if
condition|(
operator|(
name|mcf
operator|->
name|mc86_cslint
operator|&
name|MBOX_1D
operator|)
operator|==
name|MBOX_1D
condition|)
name|mcf
operator|->
name|mc86_ehmsts
operator||=
name|MC_MBOX1D
expr_stmt|;
name|type
operator|=
name|mcf
operator|->
name|mc86_ehmsts
operator|&
literal|0x7
expr_stmt|;
name|printf
argument_list|(
literal|"machine check %x: %s\n"
argument_list|,
name|type
argument_list|,
name|type
operator|<
name|NMC8600
condition|?
name|mc8600
index|[
name|type
index|]
else|:
literal|"???"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tehm.sts %x evmqsav %x ebcs %x edpsr %x cslint %x\n"
argument_list|,
name|mcf
operator|->
name|mc86_ehmsts
argument_list|,
name|mcf
operator|->
name|mc86_evmqsav
argument_list|,
name|mcf
operator|->
name|mc86_ebcs
argument_list|,
name|mcf
operator|->
name|mc86_edpsr
argument_list|,
name|mcf
operator|->
name|mc86_cslint
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tibesr %x ebxwd %x %x ivasav %x vibasav %x\n"
argument_list|,
name|mcf
operator|->
name|mc86_ibesr
argument_list|,
name|mcf
operator|->
name|mc86_ebxwd1
argument_list|,
name|mcf
operator|->
name|mc86_ebxwd2
argument_list|,
name|mcf
operator|->
name|mc86_ivasav
argument_list|,
name|mcf
operator|->
name|mc86_vibasav
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tesasav %x isasav %x cpc %x mstat %x %x mdecc %x\n"
argument_list|,
name|mcf
operator|->
name|mc86_esasav
argument_list|,
name|mcf
operator|->
name|mc86_isasav
argument_list|,
name|mcf
operator|->
name|mc86_cpc
argument_list|,
name|mcf
operator|->
name|mc86_mstat1
argument_list|,
name|mcf
operator|->
name|mc86_mstat2
argument_list|,
name|mcf
operator|->
name|mc86_mdecc
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tmerg %x cshctl %x mear %x medr %x accs %x cses %x\n"
argument_list|,
name|mcf
operator|->
name|mc86_merg
argument_list|,
name|mcf
operator|->
name|mc86_cshctl
argument_list|,
name|mcf
operator|->
name|mc86_mear
argument_list|,
name|mcf
operator|->
name|mc86_medr
argument_list|,
name|mcf
operator|->
name|mc86_accs
argument_list|,
name|mcf
operator|->
name|mc86_cses
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tpc %x psl %x\n"
argument_list|,
name|mcf
operator|->
name|mc86_pc
argument_list|,
name|mcf
operator|->
name|mc86_psl
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|EHSR
argument_list|,
literal|0
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

