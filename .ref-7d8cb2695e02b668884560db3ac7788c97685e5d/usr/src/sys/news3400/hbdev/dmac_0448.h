begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: dmac_0448.h,v 4.300 91/06/09 06:21:36 root Rel41 $ SONY  *  *	@(#)dmac_0448.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Copyright (c) 1989- by SONY Corporation.  */
end_comment

begin_comment
comment|/*  *	dmac_0448.h  *		DMAC L7A0448  */
end_comment

begin_comment
comment|/*	dmac register base address	*/
end_comment

begin_define
define|#
directive|define
name|DMAC_BASE
value|0xbfe00000
end_define

begin_comment
comment|/*	register definition	*/
end_comment

begin_define
define|#
directive|define
name|DMAC_GSTAT
value|(DMAC_BASE + 0xf)
end_define

begin_define
define|#
directive|define
name|DMAC_GSEL
value|(DMAC_BASE + 0xe)
end_define

begin_define
define|#
directive|define
name|DMAC_CSTAT
value|(DMAC_BASE + 0x2)
end_define

begin_define
define|#
directive|define
name|DMAC_CCTL
value|(DMAC_BASE + 0x3)
end_define

begin_define
define|#
directive|define
name|DMAC_CTRCL
value|(DMAC_BASE + 0x4)
end_define

begin_define
define|#
directive|define
name|DMAC_CTRCM
value|(DMAC_BASE + 0x5)
end_define

begin_define
define|#
directive|define
name|DMAC_CTRCH
value|(DMAC_BASE + 0x6)
end_define

begin_define
define|#
directive|define
name|DMAC_CTAG
value|(DMAC_BASE + 0x7)
end_define

begin_define
define|#
directive|define
name|DMAC_CWID
value|(DMAC_BASE + 0x8)
end_define

begin_define
define|#
directive|define
name|DMAC_COFSL
value|(DMAC_BASE + 0x9)
end_define

begin_define
define|#
directive|define
name|DMAC_COFSH
value|(DMAC_BASE + 0xa)
end_define

begin_define
define|#
directive|define
name|DMAC_CMAP
value|(DMAC_BASE + 0xc)
end_define

begin_define
define|#
directive|define
name|DMAC_CMAPH
value|(DMAC_BASE + 0xc)
end_define

begin_define
define|#
directive|define
name|DMAC_CMAPL
value|(DMAC_BASE + 0xd)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|VOLATILE
value|volatile
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VOLATILE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U_CHAR
end_ifndef

begin_define
define|#
directive|define
name|U_CHAR
value|unsigned VOLATILE char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|U_SHORT
end_ifndef

begin_define
define|#
directive|define
name|U_SHORT
value|unsigned VOLATILE short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|dmac_gstat
value|*(U_CHAR *)DMAC_GSTAT
end_define

begin_define
define|#
directive|define
name|dmac_gsel
value|*(U_CHAR *)DMAC_GSEL
end_define

begin_define
define|#
directive|define
name|dmac_cstat
value|*(U_CHAR *)DMAC_CSTAT
end_define

begin_define
define|#
directive|define
name|dmac_cctl
value|*(U_CHAR *)DMAC_CCTL
end_define

begin_define
define|#
directive|define
name|dmac_ctrcl
value|*(U_CHAR *)DMAC_CTRCL
end_define

begin_define
define|#
directive|define
name|dmac_ctrcm
value|*(U_CHAR *)DMAC_CTRCM
end_define

begin_define
define|#
directive|define
name|dmac_ctrch
value|*(U_CHAR *)DMAC_CTRCH
end_define

begin_define
define|#
directive|define
name|dmac_ctag
value|*(U_CHAR *)DMAC_CTAG
end_define

begin_define
define|#
directive|define
name|dmac_cwid
value|*(U_CHAR *)DMAC_CWID
end_define

begin_define
define|#
directive|define
name|dmac_cofsl
value|*(U_CHAR *)DMAC_COFSL
end_define

begin_define
define|#
directive|define
name|dmac_cofsh
value|*(U_CHAR *)DMAC_COFSH
end_define

begin_define
define|#
directive|define
name|dmac_cmap
value|*(U_SHORT *)DMAC_CMAP
end_define

begin_define
define|#
directive|define
name|dmac_cmaph
value|*(U_CHAR *)DMAC_CMAPH
end_define

begin_define
define|#
directive|define
name|dmac_cmapl
value|*(U_CHAR *)DMAC_CMAPL
end_define

begin_comment
comment|/*	status/control bit definition	*/
end_comment

begin_define
define|#
directive|define
name|DM_TCZ
value|0x80
end_define

begin_define
define|#
directive|define
name|DM_A28
value|0x40
end_define

begin_define
define|#
directive|define
name|DM_AFIX
value|0x20
end_define

begin_define
define|#
directive|define
name|DM_APAD
value|0x10
end_define

begin_define
define|#
directive|define
name|DM_ZINTEN
value|0x8
end_define

begin_define
define|#
directive|define
name|DM_RST
value|0x4
end_define

begin_define
define|#
directive|define
name|DM_MODE
value|0x2
end_define

begin_define
define|#
directive|define
name|DM_ENABLE
value|1
end_define

begin_comment
comment|/*	general status bit definition	*/
end_comment

begin_define
define|#
directive|define
name|CH_INT
parameter_list|(
name|x
parameter_list|)
value|(u_char)(1<< (2 * x))
end_define

begin_define
define|#
directive|define
name|CH0_INT
value|1
end_define

begin_define
define|#
directive|define
name|CH1_INT
value|4
end_define

begin_define
define|#
directive|define
name|CH2_INT
value|0x10
end_define

begin_define
define|#
directive|define
name|CH3_INT
value|0x40
end_define

begin_define
define|#
directive|define
name|CH_MRQ
parameter_list|(
name|x
parameter_list|)
value|(u_char)(1<< (2 * x + 1))
end_define

begin_define
define|#
directive|define
name|CH0_MRQ
value|2
end_define

begin_define
define|#
directive|define
name|CH1_MRQ
value|8
end_define

begin_define
define|#
directive|define
name|CH2_MRQ
value|0x20
end_define

begin_define
define|#
directive|define
name|CH3_MRQ
value|0x80
end_define

begin_comment
comment|/*	channel definition	*/
end_comment

begin_define
define|#
directive|define
name|CH_SCSI
value|0
end_define

begin_define
define|#
directive|define
name|CH_FDC
value|1
end_define

begin_define
define|#
directive|define
name|CH_AUDIO
value|2
end_define

begin_define
define|#
directive|define
name|CH_VIDEO
value|3
end_define

begin_comment
comment|/*	dma status		*/
end_comment

begin_struct
struct|struct
name|dm_stat
block|{
name|unsigned
name|int
name|dm_gstat
decl_stmt|;
name|unsigned
name|int
name|dm_cstat
decl_stmt|;
name|unsigned
name|int
name|dm_cctl
decl_stmt|;
name|unsigned
name|int
name|dm_tcnt
decl_stmt|;
name|unsigned
name|int
name|dm_offset
decl_stmt|;
name|unsigned
name|int
name|dm_tag
decl_stmt|;
name|unsigned
name|int
name|dm_width
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DMAC_WAIT
value|nops(10)
end_define

begin_define
define|#
directive|define
name|PINTEN
value|0xbfc80001
end_define

begin_define
define|#
directive|define
name|DMA_INTEN
value|0x10
end_define

begin_define
define|#
directive|define
name|PINTSTAT
value|0xbfc80003
end_define

end_unit

