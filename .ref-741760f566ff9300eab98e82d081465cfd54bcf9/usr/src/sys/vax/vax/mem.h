begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)mem.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Memory controller registers  *  * The way in which the data is stored in these registers varies  * per controller and cpu, so we define macros here to mask that.  */
end_comment

begin_struct
struct|struct
name|mcr
block|{
name|int
name|mc_reg
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Compute maximum possible number of memory controllers,  * for sizing of the mcraddr array.  */
end_comment

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|MAXNMCR
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNMCR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For each controller type we define 5 macros:  *	M???_INH(mcr)		inhibits further crd interrupts from mcr  *	M???_ENA(mcr)		enables another crd interrupt from mcr  *	M???_ERR(mcr)		tells whether an error is waiting  *	M???_SYN(mcr)		gives the syndrome bits of the error  *	M???_ADDR(mcr)		gives the address of the error  */
end_comment

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_comment
comment|/*  * 8600 register bit definitions  */
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
comment|/*  * ESPA register is used to address scratch pad registers in the Ebox.  * To access a register in the scratch pad, write the ESPA with the address  * and then read the ESPD register.    *  * NOTE:  In assmebly code, the the mfpr instruction that reads the ESPD  *	  register must immedately follow the mtpr instruction that setup  *	  the ESPA register -- per the VENUS processor register spec.  *  * The scratchpad registers that are supplied for a single bit ECC   * error are:  */
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
name|M8600_ENA
value|(mtpr(MERG, (mfpr(MERG)& ~M8600_ICRD)))
end_define

begin_define
define|#
directive|define
name|M8600_INH
value|(mtpr(EHSR, 0), mtpr(MERG, (mfpr(MERG) | M8600_ICRD)))
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
value|"\20\27BAD_DT_ERR\26SNG_BIT_ERR\25DBL_BIT_ERR\ \24ADDR_PE"
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

begin_endif
endif|#
directive|endif
endif|VAX8600
end_endif

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|M780_ICRD
value|0x40000000
end_define

begin_comment
comment|/* inhibit crd interrupts, in [2] */
end_comment

begin_define
define|#
directive|define
name|M780_HIER
value|0x20000000
end_define

begin_comment
comment|/* high error rate, in reg[2] */
end_comment

begin_define
define|#
directive|define
name|M780_ERLOG
value|0x10000000
end_define

begin_comment
comment|/* error log request, in reg[2] */
end_comment

begin_comment
comment|/* on a 780, memory crd's occur only when bit 15 is set in the SBIER */
end_comment

begin_comment
comment|/* register; bit 14 there is an error bit which we also clear */
end_comment

begin_comment
comment|/* these bits are in the back of the ``red book'' (or in the VMS code) */
end_comment

begin_define
define|#
directive|define
name|M780C_INH
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[2] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
end_define

begin_define
define|#
directive|define
name|M780C_ENA
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[2] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
end_define

begin_define
define|#
directive|define
name|M780C_ERR
parameter_list|(
name|mcr
parameter_list|)
define|\
value|((mcr)->mc_reg[2]& (M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780C_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2]& 0xff)
end_define

begin_define
define|#
directive|define
name|M780C_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[2]>> 8)& 0xfffff)
end_define

begin_define
define|#
directive|define
name|M780EL_INH
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[2] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
end_define

begin_define
define|#
directive|define
name|M780EL_ENA
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[2] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
end_define

begin_define
define|#
directive|define
name|M780EL_ERR
parameter_list|(
name|mcr
parameter_list|)
define|\
value|((mcr)->mc_reg[2]& (M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780EL_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2]& 0x7f)
end_define

begin_define
define|#
directive|define
name|M780EL_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[2]>> 11)& 0x1ffff)
end_define

begin_define
define|#
directive|define
name|M780EU_INH
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[3] = (M780_ICRD|M780_HIER|M780_ERLOG)), mtpr(SBIER, 0))
end_define

begin_define
define|#
directive|define
name|M780EU_ENA
parameter_list|(
name|mcr
parameter_list|)
define|\
value|(((mcr)->mc_reg[3] = (M780_HIER|M780_ERLOG)), mtpr(SBIER, 3<<14))
end_define

begin_define
define|#
directive|define
name|M780EU_ERR
parameter_list|(
name|mcr
parameter_list|)
define|\
value|((mcr)->mc_reg[3]& (M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780EU_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[3]& 0x7f)
end_define

begin_define
define|#
directive|define
name|M780EU_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[3]>> 11)& 0x1ffff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX750
end_if

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
value|((mcr)->mc_reg[1] = 0)
end_define

begin_define
define|#
directive|define
name|M750_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[0] = (M750_UNCORR|M750_CORERR), \ 			    (mcr)->mc_reg[1] = M750_ICRD)
end_define

begin_define
define|#
directive|define
name|M750_ERR
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[0]& (M750_UNCORR|M750_CORERR))
end_define

begin_define
define|#
directive|define
name|M750_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[0]& 0x7f)
end_define

begin_define
define|#
directive|define
name|M750_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[0]>> 9)& 0x7fff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX730
end_if

begin_define
define|#
directive|define
name|M730_UNCORR
value|0x80000000
end_define

begin_comment
comment|/* rds, uncorrectable error, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_CRD
value|0x40000000
end_define

begin_comment
comment|/* crd, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_FTBPE
value|0x20000000
end_define

begin_comment
comment|/* force tbuf parity error, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_ENACRD
value|0x10000000
end_define

begin_comment
comment|/* enable crd interrupt, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_MME
value|0x08000000
end_define

begin_comment
comment|/* mem-man enable (ala ipr), in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_DM
value|0x04000000
end_define

begin_comment
comment|/* diagnostic mode, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_DISECC
value|0x02000000
end_define

begin_comment
comment|/* disable ecc, in [1] */
end_comment

begin_define
define|#
directive|define
name|M730_INH
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[1] = M730_MME)
end_define

begin_define
define|#
directive|define
name|M730_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[1] = (M730_MME|M730_ENACRD))
end_define

begin_define
define|#
directive|define
name|M730_ERR
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[1]& (M730_UNCORR|M730_CRD))
end_define

begin_define
define|#
directive|define
name|M730_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[0]& 0x7f)
end_define

begin_define
define|#
directive|define
name|M730_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[0]>> 8)& 0x7fff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* controller types */
end_comment

begin_define
define|#
directive|define
name|M780C
value|1
end_define

begin_define
define|#
directive|define
name|M780EL
value|2
end_define

begin_define
define|#
directive|define
name|M780EU
value|3
end_define

begin_define
define|#
directive|define
name|M750
value|4
end_define

begin_define
define|#
directive|define
name|M730
value|5
end_define

begin_define
define|#
directive|define
name|MEMINTVL
value|(60*10)
end_define

begin_comment
comment|/* 10 minutes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|nmcr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mcr
modifier|*
name|mcraddr
index|[
name|MAXNMCR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|mcrtype
index|[
name|MAXNMCR
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

