begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mem.h	4.4	81/03/03	*/
end_comment

begin_comment
comment|/*  * Memory controller registers  *  * The way in which the data is stored in these registers varies  * per cpu, so we define macros here to mask that.  */
end_comment

begin_struct
struct|struct
name|mcr
block|{
name|int
name|mc_reg
index|[
literal|3
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

begin_if
if|#
directive|if
name|VAX750
end_if

begin_comment
comment|/*  * For the 11/750 the memory controller is at the following address.  * On 11/780, memory controllers are located at one or more  * places in nexus space.  */
end_comment

begin_define
define|#
directive|define
name|MCR_750
value|((struct nexus *)0xf20000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * For each processor type we define 5 macros:  *	M???_INH(mcr)		inhibits further crd interrupts from mcr  *	M???_ENA(mcr)		enables another crd interrupt from mcr  *	M???_ERR(mcr)		tells whether an error is waiting  *	M???_SYN(mcr)		gives the syndrome bits of the error  *	M???_ADDR(mcr)		gives the address of the error  */
end_comment

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
name|M780_HIERR
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

begin_define
define|#
directive|define
name|M780_INH
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2] = (M780_ICRD|M780_HIERR|M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2] = (M780_HIERR|M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780_ERR
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2]& (M780_ERLOG))
end_define

begin_define
define|#
directive|define
name|M780_SYN
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[2]& 0xff)
end_define

begin_define
define|#
directive|define
name|M780_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[2]>> 8)& 0xfffff)
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
value|0x40000000
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
value|((mcr)->mc_reg[1] = M750_ICRD)
end_define

begin_define
define|#
directive|define
name|M750_ENA
parameter_list|(
name|mcr
parameter_list|)
value|((mcr)->mc_reg[0] = (M750_UNCORR|M750_CORR), \ 			    (mcr)->mc_reg[1] = 0)
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
value|((mcr)->mc_reg[0]& 0x3f)
end_define

begin_define
define|#
directive|define
name|M750_ADDR
parameter_list|(
name|mcr
parameter_list|)
value|(((mcr)->mc_reg[0]>> 8)& 0x7fff)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMINTVL
value|(60*60*10)
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

