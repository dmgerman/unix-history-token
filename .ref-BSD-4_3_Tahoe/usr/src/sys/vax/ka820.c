begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)ka820.c	7.2 (Berkeley) 7/9/88  */
end_comment

begin_if
if|#
directive|if
name|VAX8200
end_if

begin_comment
comment|/*  * KA820 specific CPU code.  (Note that the VAX8200 uses a KA820, not  * a KA8200.  Sigh.)  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"vmmac.h"
end_include

begin_include
include|#
directive|include
file|"cpu.h"
end_include

begin_include
include|#
directive|include
file|"clock.h"
end_include

begin_include
include|#
directive|include
file|"ka820.h"
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

begin_include
include|#
directive|include
file|"pte.h"
end_include

begin_include
include|#
directive|include
file|"../vaxbi/bireg.h"
end_include

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Clockmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|RX50map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|Ka820map
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ka820clock
name|ka820clock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ka820port
name|ka820port
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|BRAMmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pte
name|EEPROMmap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|bootram
index|[
name|KA820_BRPAGES
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|eeprom
index|[
name|KA820_EEPAGES
operator|*
name|NBPG
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|ka820_init
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|csr
decl_stmt|;
comment|/* map in the various devices */
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|Ka820map
index|[
literal|0
index|]
operator|=
name|PG_V
operator||
name|PG_KW
operator||
name|btop
argument_list|(
name|KA820_PORTADDR
argument_list|)
expr_stmt|;
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|RX50map
index|[
literal|0
index|]
operator|=
name|PG_V
operator||
name|PG_KW
operator||
name|btop
argument_list|(
name|KA820_RX50ADDR
argument_list|)
expr_stmt|;
operator|*
operator|(
name|int
operator|*
operator|)
operator|&
name|Clockmap
index|[
literal|0
index|]
operator|=
name|PG_V
operator||
name|PG_KW
operator||
name|btop
argument_list|(
name|KA820_CLOCKADDR
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|notyet
name|ioaccess
argument_list|(
name|bootram
argument_list|,
name|BRAMmap
argument_list|,
name|KA820_BRPAGES
operator|*
name|NBPG
argument_list|)
expr_stmt|;
name|ioaccess
argument_list|(
name|eeprom
argument_list|,
name|EEPROMmap
argument_list|,
name|KA820_EEPAGES
operator|*
name|NBPG
argument_list|)
expr_stmt|;
else|#
directive|else
name|mtpr
argument_list|(
name|TBIA
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* reset the console and enable the RX50 */
name|csr
operator|=
name|ka820port
operator|.
name|csr
expr_stmt|;
name|csr
operator|&=
operator|~
name|KA820PORT_RSTHALT
expr_stmt|;
comment|/* ??? */
name|csr
operator||=
name|KA820PORT_CONSCLR
operator||
name|KA820PORT_CRDCLR
operator||
name|KA820PORT_CONSEN
operator||
name|KA820PORT_RXIE
expr_stmt|;
name|ka820port
operator|.
name|csr
operator|=
name|csr
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Set system time from clock */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|ka820_clkread
argument_list|(
argument|base
argument_list|)
end_macro

begin_decl_stmt
name|time_t
name|base
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|ka820clock
modifier|*
name|clock
init|=
operator|&
name|ka820clock
decl_stmt|;
name|struct
name|chiptime
name|c
decl_stmt|;
name|int
name|s
decl_stmt|,
name|rv
decl_stmt|;
name|rv
operator|=
name|CLKREAD_OK
expr_stmt|;
comment|/* I wish I knew the differences between these */
if|if
condition|(
operator|(
name|clock
operator|->
name|csr3
operator|&
name|KA820CLK_3_VALID
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"WARNING: TOY clock not marked valid\n"
argument_list|)
expr_stmt|;
name|rv
operator|=
name|CLKREAD_WARN
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|clock
operator|->
name|csr1
operator|&
name|KA820CLK_1_GO
operator|)
operator|!=
name|KA820CLK_1_GO
condition|)
block|{
name|printf
argument_list|(
literal|"WARNING: TOY clock stopped\n"
argument_list|)
expr_stmt|;
name|rv
operator|=
name|CLKREAD_WARN
expr_stmt|;
block|}
comment|/* THIS IS NOT RIGHT (clock may change on us) */
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
while|while
condition|(
name|clock
operator|->
name|csr0
operator|&
name|KA820CLK_0_BUSY
condition|)
comment|/* void */
empty_stmt|;
name|c
operator|.
name|sec
operator|=
name|clock
operator|->
name|sec
expr_stmt|;
name|c
operator|.
name|min
operator|=
name|clock
operator|->
name|min
expr_stmt|;
name|c
operator|.
name|hour
operator|=
name|clock
operator|->
name|hr
expr_stmt|;
name|c
operator|.
name|day
operator|=
name|clock
operator|->
name|day
expr_stmt|;
name|c
operator|.
name|mon
operator|=
name|clock
operator|->
name|mon
expr_stmt|;
name|c
operator|.
name|year
operator|=
name|clock
operator|->
name|yr
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* the darn thing needs tweaking! */
name|c
operator|.
name|sec
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|min
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|hour
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|day
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|mon
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|year
operator|>>=
literal|1
expr_stmt|;
comment|/* tweak */
name|time
operator|.
name|tv_sec
operator|=
name|chiptotime
argument_list|(
operator|&
name|c
argument_list|)
expr_stmt|;
return|return
operator|(
name|time
operator|.
name|tv_sec
condition|?
name|rv
else|:
name|CLKREAD_BAD
operator|)
return|;
block|}
end_block

begin_comment
comment|/* store time into clock */
end_comment

begin_macro
name|ka820_clkwrite
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|ka820clock
modifier|*
name|clock
init|=
operator|&
name|ka820clock
decl_stmt|;
name|struct
name|chiptime
name|c
decl_stmt|;
name|int
name|s
decl_stmt|;
name|timetochip
argument_list|(
operator|&
name|c
argument_list|)
expr_stmt|;
comment|/* play it again, sam (or mike or kirk or ...) */
name|c
operator|.
name|sec
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|min
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|hour
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|day
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|mon
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|c
operator|.
name|year
operator|<<=
literal|1
expr_stmt|;
comment|/* tweak */
name|s
operator|=
name|splhigh
argument_list|()
expr_stmt|;
name|clock
operator|->
name|csr1
operator|=
name|KA820CLK_1_SET
expr_stmt|;
while|while
condition|(
name|clock
operator|->
name|csr0
operator|&
name|KA820CLK_0_BUSY
condition|)
comment|/* void */
empty_stmt|;
name|clock
operator|->
name|sec
operator|=
name|c
operator|.
name|sec
expr_stmt|;
name|clock
operator|->
name|min
operator|=
name|c
operator|.
name|min
expr_stmt|;
name|clock
operator|->
name|hr
operator|=
name|c
operator|.
name|hour
expr_stmt|;
name|clock
operator|->
name|day
operator|=
name|c
operator|.
name|day
expr_stmt|;
name|clock
operator|->
name|mon
operator|=
name|c
operator|.
name|mon
expr_stmt|;
name|clock
operator|->
name|yr
operator|=
name|c
operator|.
name|year
expr_stmt|;
comment|/* should we set a `rate'? */
name|clock
operator|->
name|csr1
operator|=
name|KA820CLK_1_GO
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * MS820 support.  */
end_comment

begin_struct
struct|struct
name|ms820regs
block|{
name|struct
name|biiregs
name|biic
decl_stmt|;
comment|/* BI interface chip */
name|u_long
name|ms_gpr
index|[
literal|4
index|]
decl_stmt|;
comment|/* the four gprs (unused) */
name|int
name|ms_csr1
decl_stmt|;
comment|/* control/status register 1 */
name|int
name|ms_csr2
decl_stmt|;
comment|/* control/status register 2 */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bits in CSR1.  */
end_comment

begin_define
define|#
directive|define
name|MS1_ERRSUM
value|0x80000000
end_define

begin_comment
comment|/* error summary (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_ECCDIAG
value|0x40000000
end_define

begin_comment
comment|/* ecc diagnostic (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_ECCDISABLE
value|0x20000000
end_define

begin_comment
comment|/* ecc disable (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_MSIZEMASK
value|0x1ffc0000
end_define

begin_comment
comment|/* mask for memory size (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_RAMTYMASK
value|0x00030000
end_define

begin_comment
comment|/* mask for ram type (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_RAMTY64K
value|0x00000000
end_define

begin_comment
comment|/* 64K chips */
end_comment

begin_define
define|#
directive|define
name|MS1_RAMTY256K
value|0x00010000
end_define

begin_comment
comment|/* 256K chips */
end_comment

begin_comment
comment|/* types 2 and 3 reserved */
end_comment

begin_define
define|#
directive|define
name|MS1_CRDINH
value|0x00008000
end_define

begin_comment
comment|/* inhibit crd interrupts (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_MEMVALID
value|0x00004000
end_define

begin_comment
comment|/* memory has been written (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_INTLK
value|0x00002000
end_define

begin_comment
comment|/* interlock flag (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_BROKE
value|0x00001000
end_define

begin_comment
comment|/* broken (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_MBZ
value|0x00000880
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|MS1_MWRITEERR
value|0x00000400
end_define

begin_comment
comment|/* rds during masked write (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_CNTLERR
value|0x00000200
end_define

begin_comment
comment|/* internal timing busted (rw) */
end_comment

begin_define
define|#
directive|define
name|MS1_INTLV
value|0x00000100
end_define

begin_comment
comment|/* internally interleaved (ro) */
end_comment

begin_define
define|#
directive|define
name|MS1_DIAGC
value|0x0000007f
end_define

begin_comment
comment|/* ecc diagnostic bits (rw) */
end_comment

begin_comment
comment|/*  * Bits in CSR2.  */
end_comment

begin_define
define|#
directive|define
name|MS2_RDSERR
value|0x80000000
end_define

begin_comment
comment|/* rds error (rw) */
end_comment

begin_define
define|#
directive|define
name|MS2_HIERR
value|0x40000000
end_define

begin_comment
comment|/* high error rate (rw) */
end_comment

begin_define
define|#
directive|define
name|MS2_CRDERR
value|0x20000000
end_define

begin_comment
comment|/* crd error (rw) */
end_comment

begin_define
define|#
directive|define
name|MS2_ADRSERR
value|0x10000000
end_define

begin_comment
comment|/* rds due to addr par err (rw) */
end_comment

begin_define
define|#
directive|define
name|MS2_MBZ
value|0x0f000080
end_define

begin_comment
comment|/* zero */
end_comment

begin_define
define|#
directive|define
name|MS2_ADDR
value|0x00fffe00
end_define

begin_comment
comment|/* address in error (relative) (ro) */
end_comment

begin_define
define|#
directive|define
name|MS2_INTLVADDR
value|0x00000100
end_define

begin_comment
comment|/* error was in bank 1 (ro) */
end_comment

begin_define
define|#
directive|define
name|MS2_SYN
value|0x0000007f
end_define

begin_comment
comment|/* error syndrome (ro, rw diag) */
end_comment

begin_macro
name|ka820_memenable
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|ms820regs
modifier|*
name|mcr
decl_stmt|;
specifier|register
name|int
name|m
decl_stmt|;
for|for
control|(
name|m
operator|=
literal|0
init|;
name|m
operator|<
name|nmcr
condition|;
name|m
operator|++
control|)
block|{
name|mcr
operator|=
operator|(
expr|struct
name|ms820regs
operator|*
operator|)
name|mcraddr
index|[
name|m
index|]
expr_stmt|;
comment|/* 		 * This will be noisy.  Should we do anything 		 * about that? 		 */
if|if
condition|(
operator|(
name|mcr
operator|->
name|biic
operator|.
name|bi_csr
operator|&
name|BICSR_STS
operator|)
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"mcr%d: failed self test\n"
argument_list|,
name|m
argument_list|)
expr_stmt|;
else|else
block|{
name|mcr
operator|->
name|ms_csr1
operator|=
name|MS1_MWRITEERR
operator||
name|MS1_CNTLERR
expr_stmt|;
name|mcr
operator|->
name|ms_csr2
operator|=
name|MS2_RDSERR
operator||
name|MS2_HIERR
operator||
name|MS2_CRDERR
operator||
name|MS2_ADRSERR
expr_stmt|;
block|}
block|}
block|}
end_block

begin_macro
name|ka820_memerr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|ms820regs
modifier|*
name|mcr
decl_stmt|;
specifier|register
name|int
name|m
decl_stmt|,
name|hard
decl_stmt|;
specifier|register
name|char
modifier|*
name|type
decl_stmt|;
specifier|static
name|char
name|b1
index|[]
init|=
literal|"\20\40ERRSUM\37ECCDIAG\36ECCDISABLE\20CRDINH\17VALID\ \16INTLK\15BROKE\13MWRITEERR\12CNTLERR\11INTLV"
decl_stmt|;
specifier|static
name|char
name|b2
index|[]
init|=
literal|"\20\40RDS\37HIERR\36CRD\35ADRS"
decl_stmt|;
for|for
control|(
name|m
operator|=
literal|0
init|;
name|m
operator|<
name|nmcr
condition|;
name|m
operator|++
control|)
block|{
name|mcr
operator|=
operator|(
expr|struct
name|ms820regs
operator|*
operator|)
name|mcraddr
index|[
name|m
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"mcr%d: csr1=%b csr2=%b\n"
argument_list|,
name|m
argument_list|,
name|mcr
operator|->
name|ms_csr1
argument_list|,
name|b1
argument_list|,
name|mcr
operator|->
name|ms_csr2
argument_list|,
name|b2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|mcr
operator|->
name|ms_csr1
operator|&
name|MS1_ERRSUM
operator|)
operator|==
literal|0
condition|)
continue|continue;
name|hard
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|mcr
operator|->
name|ms_csr1
operator|&
name|MS1_BROKE
condition|)
name|type
operator|=
literal|"broke"
expr_stmt|;
elseif|else
if|if
condition|(
name|mcr
operator|->
name|ms_csr1
operator|&
name|MS1_CNTLERR
condition|)
name|type
operator|=
literal|"cntl err"
expr_stmt|;
elseif|else
if|if
condition|(
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_ADRSERR
condition|)
name|type
operator|=
literal|"address parity err"
expr_stmt|;
elseif|else
if|if
condition|(
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_RDSERR
condition|)
name|type
operator|=
literal|"rds err"
expr_stmt|;
elseif|else
if|if
condition|(
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_CRDERR
condition|)
block|{
name|hard
operator|=
literal|0
expr_stmt|;
name|type
operator|=
literal|""
expr_stmt|;
block|}
else|else
name|type
operator|=
literal|"mysterious error"
expr_stmt|;
name|printf
argument_list|(
literal|"mcr%d: %s%s%s addr %x bank %x syn %x\n"
argument_list|,
name|m
argument_list|,
name|hard
condition|?
literal|"hard error: "
else|:
literal|"soft ecc"
argument_list|,
name|type
argument_list|,
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_HIERR
condition|?
literal|" (+ other rds or crd err)"
else|:
literal|""
argument_list|,
operator|(
operator|(
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_ADDR
operator|)
operator|+
name|mcr
operator|->
name|biic
operator|.
name|bi_sadr
operator|)
operator|>>
literal|9
argument_list|,
operator|(
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_INTLVADDR
operator|)
operator|!=
literal|0
argument_list|,
name|mcr
operator|->
name|ms_csr2
operator|&
name|MS2_SYN
argument_list|)
expr_stmt|;
name|mcr
operator|->
name|ms_csr1
operator|=
name|mcr
operator|->
name|ms_csr1
operator||
name|MS1_CRDINH
expr_stmt|;
name|mcr
operator|->
name|ms_csr2
operator|=
name|mcr
operator|->
name|ms_csr2
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/* these are bits 0 to 6 in the summary field */
end_comment

begin_decl_stmt
name|char
modifier|*
name|mc8200
index|[]
init|=
block|{
literal|"cpu bad ipl"
block|,
literal|"ucode lost err"
block|,
literal|"ucode par err"
block|,
literal|"DAL par err"
block|,
literal|"BI bus err"
block|,
literal|"BTB tag par"
block|,
literal|"cache tag par"
block|, }
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MC8200_BADIPL
value|0x01
end_define

begin_define
define|#
directive|define
name|MC8200_UERR
value|0x02
end_define

begin_define
define|#
directive|define
name|MC8200_UPAR
value|0x04
end_define

begin_define
define|#
directive|define
name|MC8200_DPAR
value|0x08
end_define

begin_define
define|#
directive|define
name|MC8200_BIERR
value|0x10
end_define

begin_define
define|#
directive|define
name|MC8200_BTAGPAR
value|0x20
end_define

begin_define
define|#
directive|define
name|MC8200_CTAGPAR
value|0x40
end_define

begin_struct
struct|struct
name|mc8200frame
block|{
name|int
name|mc82_bcnt
decl_stmt|;
comment|/* byte count == 0x20 */
name|int
name|mc82_summary
decl_stmt|;
comment|/* summary parameter */
name|int
name|mc82_param1
decl_stmt|;
comment|/* parameter 1 */
name|int
name|mc82_va
decl_stmt|;
comment|/* va register */
name|int
name|mc82_vap
decl_stmt|;
comment|/* va prime register */
name|int
name|mc82_ma
decl_stmt|;
comment|/* memory address */
name|int
name|mc82_status
decl_stmt|;
comment|/* status word */
name|int
name|mc82_epc
decl_stmt|;
comment|/* error pc */
name|int
name|mc82_upc
decl_stmt|;
comment|/* micro pc */
name|int
name|mc82_pc
decl_stmt|;
comment|/* current pc */
name|int
name|mc82_psl
decl_stmt|;
comment|/* current psl */
block|}
struct|;
end_struct

begin_macro
name|ka820_mchk
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
name|mc8200frame
modifier|*
name|mcf
init|=
operator|(
expr|struct
name|mc8200frame
operator|*
operator|)
name|cmcf
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|,
name|type
init|=
name|mcf
operator|->
name|mc82_summary
decl_stmt|;
specifier|extern
name|int
name|cold
decl_stmt|;
comment|/* ignore BI bus errors during configuration */
if|if
condition|(
name|cold
operator|&&
name|type
operator|==
name|MC8200_BIERR
condition|)
block|{
name|mtpr
argument_list|(
name|MCESR
argument_list|,
literal|0xf
argument_list|)
expr_stmt|;
return|return
operator|(
name|MCHK_RECOVERED
operator|)
return|;
block|}
comment|/* 	 * SOME ERRORS ARE RECOVERABLE 	 * do it later 	 */
name|printf
argument_list|(
literal|"machine check %x: "
argument_list|,
name|type
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|mc8200
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mc8200
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|type
operator|&
operator|(
literal|1
operator|<<
name|i
operator|)
condition|)
name|printf
argument_list|(
literal|" %s,"
argument_list|,
name|mc8200
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|" param1 %x\n"
argument_list|,
name|mcf
operator|->
name|mc82_param1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\tva %x va' %x ma %x pc %x psl %x\n\tstatus %x errpc %x upc %x\n"
argument_list|,
name|mcf
operator|->
name|mc82_va
argument_list|,
name|mcf
operator|->
name|mc82_vap
argument_list|,
name|mcf
operator|->
name|mc82_ma
argument_list|,
name|mcf
operator|->
name|mc82_pc
argument_list|,
name|mcf
operator|->
name|mc82_psl
argument_list|,
name|mcf
operator|->
name|mc82_status
argument_list|,
name|mcf
operator|->
name|mc82_epc
argument_list|,
name|mcf
operator|->
name|mc82_upc
argument_list|)
expr_stmt|;
return|return
operator|(
name|MCHK_PANIC
operator|)
return|;
block|}
end_block

begin_comment
comment|/*  * Receive a character from logical console.  */
end_comment

begin_macro
name|rxcdintr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|c
init|=
name|mfpr
argument_list|(
name|RXCD
argument_list|)
decl_stmt|;
comment|/* not sure what (if anything) to do with these */
name|printf
argument_list|(
literal|"rxcd node %x c=0x%x\n"
argument_list|,
operator|(
name|c
operator|>>
literal|8
operator|)
operator|&
literal|0xf
argument_list|,
name|c
operator|&
literal|0xff
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

