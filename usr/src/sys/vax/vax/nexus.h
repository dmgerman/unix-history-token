begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	nexus.h	4.2	81/02/19	*/
end_comment

begin_comment
comment|/*  * Information about nexus's.  */
end_comment

begin_if
if|#
directive|if
name|VAX780
end_if

begin_define
define|#
directive|define
name|NNEX780
value|16
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
value|4
end_define

begin_define
define|#
directive|define
name|NEX750
value|((struct nexus *)0xf28000)
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
specifier|extern
name|struct
name|nexus
name|nexus
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

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
name|SBI_UIDFLT
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
comment|/* 4 flavours  for 4 addr spaces */
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

end_unit

