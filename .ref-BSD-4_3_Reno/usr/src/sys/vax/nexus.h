begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)nexus.h	7.2 (Berkeley) 8/9/86  */
end_comment

begin_comment
comment|/*  * Information about nexus's.  *  * Each machine has an address of backplane slots (nexi).  * Each nexus is some type of adapter, whose code is the low  * byte of the first word of the adapter address space.  * At boot time the system looks through the array of available  * slots and finds the interconnects for the machine.  */
end_comment

begin_define
define|#
directive|define
name|NNEXSBI
value|16
end_define

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_define
define|#
directive|define
name|NNEX8600
value|NNEXSBI
end_define

begin_define
define|#
directive|define
name|NEXA8600
value|((struct nexus *)(0x20000000))
end_define

begin_define
define|#
directive|define
name|NEXB8600
value|((struct nexus *)(0x22000000))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|NNEX780
value|NNEXSBI
end_define

begin_define
define|#
directive|define
name|NEX780
value|((struct nexus *)0x20000000)
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
name|NNEX750
value|NNEXSBI
end_define

begin_define
define|#
directive|define
name|NEX750
value|((struct nexus *)0xf20000)
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
name|NNEX730
value|NNEXSBI
end_define

begin_define
define|#
directive|define
name|NEX730
value|((struct nexus *)0xf20000)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEXSIZE
value|0x2000
end_define

begin_if
if|#
directive|if
name|VAX8600
end_if

begin_define
define|#
directive|define
name|MAXNNEXUS
value|(2 * NNEXSBI)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAXNNEXUS
value|NNEXSBI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_struct
struct|struct
name|nexus
block|{
union|union
name|nexcsr
block|{
name|long
name|nex_csr
decl_stmt|;
name|u_char
name|nex_type
decl_stmt|;
block|}
name|nexcsr
union|;
name|long
name|nex_pad
index|[
name|NEXSIZE
operator|/
sizeof|sizeof
argument_list|(
name|long
argument_list|)
operator|-
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|nexus
name|nexus
index|[
name|MAXNNEXUS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Bits in high word of nexus's.  */
end_comment

begin_define
define|#
directive|define
name|SBI_PARFLT
value|(1<<31)
end_define

begin_comment
comment|/* sbi parity fault */
end_comment

begin_define
define|#
directive|define
name|SBI_WSQFLT
value|(1<<30)
end_define

begin_comment
comment|/* write sequence fault */
end_comment

begin_define
define|#
directive|define
name|SBI_URDFLT
value|(1<<29)
end_define

begin_comment
comment|/* unexpected read data fault */
end_comment

begin_define
define|#
directive|define
name|SBI_ISQFLT
value|(1<<28)
end_define

begin_comment
comment|/* interlock sequence fault */
end_comment

begin_define
define|#
directive|define
name|SBI_MXTFLT
value|(1<<27)
end_define

begin_comment
comment|/* multiple transmitter fault */
end_comment

begin_define
define|#
directive|define
name|SBI_XMTFLT
value|(1<<26)
end_define

begin_comment
comment|/* transmit fault */
end_comment

begin_define
define|#
directive|define
name|NEX_CFGFLT
value|(0xfc000000)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX780
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX8600
argument_list|)
end_if

begin_define
define|#
directive|define
name|NEXFLT_BITS
define|\
value|"\20\40PARFLT\37WSQFLT\36URDFLT\35ISQFLT\34MXTFLT\33XMTFLT"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NEX_APD
value|(1<<23)
end_define

begin_comment
comment|/* adaptor power down */
end_comment

begin_define
define|#
directive|define
name|NEX_APU
value|(1<<22)
end_define

begin_comment
comment|/* adaptor power up */
end_comment

begin_define
define|#
directive|define
name|MBA_OT
value|(1<<21)
end_define

begin_comment
comment|/* overtemperature */
end_comment

begin_define
define|#
directive|define
name|UBA_UBINIT
value|(1<<18)
end_define

begin_comment
comment|/* unibus init */
end_comment

begin_define
define|#
directive|define
name|UBA_UBPDN
value|(1<<17)
end_define

begin_comment
comment|/* unibus power down */
end_comment

begin_define
define|#
directive|define
name|UBA_UBIC
value|(1<<16)
end_define

begin_comment
comment|/* unibus initialization complete */
end_comment

begin_comment
comment|/*  * Types for nex_type.  */
end_comment

begin_define
define|#
directive|define
name|NEX_ANY
value|0
end_define

begin_comment
comment|/* pseudo for handling 11/750 */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM4
value|0x08
end_define

begin_comment
comment|/* 4K chips, non-interleaved mem */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM4I
value|0x09
end_define

begin_comment
comment|/* 4K chips, interleaved mem */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM16
value|0x10
end_define

begin_comment
comment|/* 16K chips, non-interleaved mem */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM16I
value|0x11
end_define

begin_comment
comment|/* 16K chips, interleaved mem */
end_comment

begin_define
define|#
directive|define
name|NEX_MBA
value|0x20
end_define

begin_comment
comment|/* Massbus adaptor */
end_comment

begin_define
define|#
directive|define
name|NEX_UBA0
value|0x28
end_define

begin_comment
comment|/* Unibus adaptor */
end_comment

begin_define
define|#
directive|define
name|NEX_UBA1
value|0x29
end_define

begin_comment
comment|/* 4 flavours for 4 addr spaces */
end_comment

begin_define
define|#
directive|define
name|NEX_UBA2
value|0x2a
end_define

begin_define
define|#
directive|define
name|NEX_UBA3
value|0x2b
end_define

begin_define
define|#
directive|define
name|NEX_DR32
value|0x30
end_define

begin_comment
comment|/* DR32 user i'face to SBI */
end_comment

begin_define
define|#
directive|define
name|NEX_CI
value|0x38
end_define

begin_comment
comment|/* CI adaptor */
end_comment

begin_define
define|#
directive|define
name|NEX_MPM0
value|0x40
end_define

begin_comment
comment|/* Multi-port mem */
end_comment

begin_define
define|#
directive|define
name|NEX_MPM1
value|0x41
end_define

begin_comment
comment|/* Who knows why 4 different ones ? */
end_comment

begin_define
define|#
directive|define
name|NEX_MPM2
value|0x42
end_define

begin_define
define|#
directive|define
name|NEX_MPM3
value|0x43
end_define

begin_define
define|#
directive|define
name|NEX_MEM64L
value|0x68
end_define

begin_comment
comment|/* 64K chips, non-interleaved, lower */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM64LI
value|0x69
end_define

begin_comment
comment|/* 64K chips, ext-interleaved, lower */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM64U
value|0x6a
end_define

begin_comment
comment|/* 64K chips, non-interleaved, upper */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM64UI
value|0x6b
end_define

begin_comment
comment|/* 64K chips, ext-interleaved, upper */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM64I
value|0x6c
end_define

begin_comment
comment|/* 64K chips, interleaved */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM256L
value|0x70
end_define

begin_comment
comment|/* 256K chips, non-interleaved, lower */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM256LI
value|0x71
end_define

begin_comment
comment|/* 256K chips, ext-interleaved, lower */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM256U
value|0x72
end_define

begin_comment
comment|/* 256K chips, non-interleaved, upper */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM256UI
value|0x73
end_define

begin_comment
comment|/* 256K chips, ext-interleaved, upper */
end_comment

begin_define
define|#
directive|define
name|NEX_MEM256I
value|0x74
end_define

begin_comment
comment|/* 256K chips, interleaved */
end_comment

end_unit

