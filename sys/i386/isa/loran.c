begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: loran.c,v 1.2 1998/03/28 13:24:31 bde Exp $  *  * This device-driver helps the userland controlprogram for a LORAN-C  * receiver avoid monopolizing the CPU.  *  * This is clearly a candidate for the "most weird hardware support in  * FreeBSD" prize.  At this time only two copies of the receiver are  * known to exist in the entire world.  *  * Details can be found at:  *     ftp://ftp.eecis.udel.edu/pub/ntp/loran.tar.Z  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"loran.h"
end_include

begin_include
include|#
directive|include
file|"opt_devfs.h"
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DEVFS
end_ifdef

begin_include
include|#
directive|include
file|<sys/devfsext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*DEVFS*/
end_comment

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_struct
struct|struct
name|datapoint
block|{
name|void
modifier|*
name|ident
decl_stmt|;
name|int
name|index
decl_stmt|;
name|u_int64_t
name|scheduled
decl_stmt|;
name|u_int
name|delay
decl_stmt|;
name|u_int
name|code
decl_stmt|;
name|u_int
name|gri
decl_stmt|;
name|u_int
name|agc
decl_stmt|;
name|u_int
name|phase
decl_stmt|;
name|u_int
name|par
decl_stmt|;
name|u_int
name|isig
decl_stmt|;
name|u_int
name|qsig
decl_stmt|;
name|u_int
name|ssig
decl_stmt|;
name|u_int64_t
name|epoch
decl_stmt|;
name|struct
name|timespec
name|actual
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|datapoint
argument_list|)
name|list
expr_stmt|;
name|double
name|ival
decl_stmt|;
name|double
name|qval
decl_stmt|;
name|double
name|mval
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Mode register (PAR) hardware definitions  */
end_comment

begin_define
define|#
directive|define
name|INTEG
value|0x03
end_define

begin_comment
comment|/* integrator mask */
end_comment

begin_define
define|#
directive|define
name|INTEG_1000us
value|0
end_define

begin_define
define|#
directive|define
name|INTEG_264us
value|1
end_define

begin_define
define|#
directive|define
name|INTEG_36us
value|2
end_define

begin_define
define|#
directive|define
name|INTEG_SHORT
value|3
end_define

begin_define
define|#
directive|define
name|GATE
value|0x0C
end_define

begin_comment
comment|/* gate source mask */
end_comment

begin_define
define|#
directive|define
name|GATE_OPEN
value|0x4
end_define

begin_define
define|#
directive|define
name|GATE_GRI
value|0x8
end_define

begin_define
define|#
directive|define
name|GATE_PCI
value|0xc
end_define

begin_define
define|#
directive|define
name|GATE_STB
value|0xf
end_define

begin_define
define|#
directive|define
name|MSB
value|0x10
end_define

begin_comment
comment|/* load dac high-order bits */
end_comment

begin_define
define|#
directive|define
name|IEN
value|0x20
end_define

begin_comment
comment|/* enable interrupt bit */
end_comment

begin_define
define|#
directive|define
name|EN5
value|0x40
end_define

begin_comment
comment|/* enable counter 5 bit */
end_comment

begin_define
define|#
directive|define
name|ENG
value|0x80
end_define

begin_comment
comment|/* enable gri bit */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|VCO
value|2048
end_define

begin_comment
comment|/* initial vco dac (0 V)*/
end_comment

begin_define
define|#
directive|define
name|PORT
value|0x0300
end_define

begin_comment
comment|/* controller port address */
end_comment

begin_define
define|#
directive|define
name|PGUARD
value|990
end_define

begin_comment
comment|/* program guard time (cycle) (990!) */
end_comment

begin_define
define|#
directive|define
name|GRI
value|800
end_define

begin_comment
comment|/* pulse-group gate (cycle) */
end_comment

begin_comment
comment|/*  * Analog/digital converter (ADC) hardware definitions  */
end_comment

begin_define
define|#
directive|define
name|ADC
value|PORT+2
end_define

begin_comment
comment|/* adc buffer (r)/address (w) */
end_comment

begin_define
define|#
directive|define
name|ADCGO
value|PORT+3
end_define

begin_comment
comment|/* adc status (r)/adc start (w) */
end_comment

begin_define
define|#
directive|define
name|ADC_START
value|0x01
end_define

begin_comment
comment|/* converter start bit (w) */
end_comment

begin_define
define|#
directive|define
name|ADC_BUSY
value|0x01
end_define

begin_comment
comment|/* converter busy bit (r) */
end_comment

begin_define
define|#
directive|define
name|ADC_DONE
value|0x80
end_define

begin_comment
comment|/* converter done bit (r) */
end_comment

begin_define
define|#
directive|define
name|ADC_I
value|0
end_define

begin_comment
comment|/* i channel (phase) */
end_comment

begin_define
define|#
directive|define
name|ADC_Q
value|1
end_define

begin_comment
comment|/* q channel (amplitude) */
end_comment

begin_define
define|#
directive|define
name|ADC_S
value|2
end_define

begin_comment
comment|/* s channel (agc) */
end_comment

begin_comment
comment|/*  * Digital/analog converter (DAC) hardware definitions  * Note: output voltage increases with value programmed; the buffer  * is loaded in two 8-bit bytes, the lsb 8 bits with the MSB bit off in  * the PAR register, the msb 4 bits with the MSB on.  */
end_comment

begin_define
define|#
directive|define
name|DACA
value|PORT+4
end_define

begin_comment
comment|/* vco (dac a) buffer (w) */
end_comment

begin_define
define|#
directive|define
name|DACB
value|PORT+5
end_define

begin_comment
comment|/* agc (dac b) buffer (w) */
end_comment

begin_comment
comment|/*  * Pulse-code generator (CODE) hardware definitions  * Note: bits are shifted out from the lsb first  */
end_comment

begin_define
define|#
directive|define
name|CODE
value|PORT+6
end_define

begin_comment
comment|/* pulse-code buffer (w) */
end_comment

begin_define
define|#
directive|define
name|MPCA
value|0xCA
end_define

begin_comment
comment|/* LORAN-C master pulse code group a */
end_comment

begin_define
define|#
directive|define
name|MPCB
value|0x9F
end_define

begin_comment
comment|/* LORAN-C master pulse code group b */
end_comment

begin_define
define|#
directive|define
name|SPCA
value|0xF9
end_define

begin_comment
comment|/* LORAN-C slave pulse code group a */
end_comment

begin_define
define|#
directive|define
name|SPCB
value|0xAC
end_define

begin_comment
comment|/* LORAN-C slave pulse code group b */
end_comment

begin_comment
comment|/*  * Mode register (PAR) hardware definitions  */
end_comment

begin_define
define|#
directive|define
name|PAR
value|PORT+7
end_define

begin_comment
comment|/* parameter buffer (w) */
end_comment

begin_define
define|#
directive|define
name|TGC
value|PORT+0
end_define

begin_comment
comment|/* stc control port (r/w) */
end_comment

begin_define
define|#
directive|define
name|TGD
value|PORT+1
end_define

begin_comment
comment|/* stc data port (r/w) */
end_comment

begin_comment
comment|/*  * Timing generator (STC) hardware commands  */
end_comment

begin_comment
comment|/* argument sssss = counter numbers 5-1 */
end_comment

begin_define
define|#
directive|define
name|TG_LOADDP
value|0x00
end_define

begin_comment
comment|/* load data pointer */
end_comment

begin_comment
comment|/* argument ee = element (all groups except ggg = 000 or 111) */
end_comment

begin_define
define|#
directive|define
name|MODEREG
value|0x00
end_define

begin_comment
comment|/* mode register */
end_comment

begin_define
define|#
directive|define
name|LOADREG
value|0x08
end_define

begin_comment
comment|/* load register */
end_comment

begin_define
define|#
directive|define
name|HOLDREG
value|0x10
end_define

begin_comment
comment|/* hold register */
end_comment

begin_define
define|#
directive|define
name|HOLDINC
value|0x18
end_define

begin_comment
comment|/* hold register (hold cycle increm) */
end_comment

begin_comment
comment|/* argument ee = element (group ggg = 111) */
end_comment

begin_define
define|#
directive|define
name|ALARM1
value|0x07
end_define

begin_comment
comment|/* alarm register 1 */
end_comment

begin_define
define|#
directive|define
name|ALARM2
value|0x0F
end_define

begin_comment
comment|/* alarm register 2 */
end_comment

begin_define
define|#
directive|define
name|MASTER
value|0x17
end_define

begin_comment
comment|/* master mode register */
end_comment

begin_define
define|#
directive|define
name|STATUS
value|0x1F
end_define

begin_comment
comment|/* status register */
end_comment

begin_define
define|#
directive|define
name|ARM
value|0x20
end_define

begin_comment
comment|/* arm counters */
end_comment

begin_define
define|#
directive|define
name|LOAD
value|0x40
end_define

begin_comment
comment|/* load counters */
end_comment

begin_define
define|#
directive|define
name|TG_LOADARM
value|0x60
end_define

begin_comment
comment|/* load and arm counters */
end_comment

begin_define
define|#
directive|define
name|DISSAVE
value|0x80
end_define

begin_comment
comment|/* disarm and save counters */
end_comment

begin_define
define|#
directive|define
name|TG_SAVE
value|0xA0
end_define

begin_comment
comment|/* save counters */
end_comment

begin_define
define|#
directive|define
name|DISARM
value|0xC0
end_define

begin_comment
comment|/* disarm counters */
end_comment

begin_comment
comment|/* argument nnn = counter number */
end_comment

begin_define
define|#
directive|define
name|SETTOG
value|0xE8
end_define

begin_comment
comment|/* set toggle output HIGH for counter */
end_comment

begin_define
define|#
directive|define
name|CLRTOG
value|0xE0
end_define

begin_comment
comment|/* set toggle output LOW for counter */
end_comment

begin_define
define|#
directive|define
name|STEP
value|0xF0
end_define

begin_comment
comment|/* step counter */
end_comment

begin_comment
comment|/* argument eeggg, where ee = element, ggg - counter group */
end_comment

begin_comment
comment|/* no arguments */
end_comment

begin_define
define|#
directive|define
name|ENABDPS
value|0xE0
end_define

begin_comment
comment|/* enable data pointer sequencing */
end_comment

begin_define
define|#
directive|define
name|ENABFOUT
value|0xE6
end_define

begin_comment
comment|/* enable fout */
end_comment

begin_define
define|#
directive|define
name|ENAB8
value|0xE7
end_define

begin_comment
comment|/* enable 8-bit data bus */
end_comment

begin_define
define|#
directive|define
name|DSABDPS
value|0xE8
end_define

begin_comment
comment|/* disable data pointer sequencing */
end_comment

begin_define
define|#
directive|define
name|ENAB16
value|0xEF
end_define

begin_comment
comment|/* enable 16-bit data bus */
end_comment

begin_define
define|#
directive|define
name|DSABFOUT
value|0xEE
end_define

begin_comment
comment|/* disable fout */
end_comment

begin_define
define|#
directive|define
name|ENABPFW
value|0xF8
end_define

begin_comment
comment|/* enable prefetch for write */
end_comment

begin_define
define|#
directive|define
name|DSABPFW
value|0xF9
end_define

begin_comment
comment|/* disable prefetch for write */
end_comment

begin_define
define|#
directive|define
name|TG_RESET
value|0xFF
end_define

begin_comment
comment|/* master reset */
end_comment

begin_define
define|#
directive|define
name|NENV
value|40
end_define

begin_comment
comment|/* size of envelope filter */
end_comment

begin_define
define|#
directive|define
name|CLOCK
value|50
end_define

begin_comment
comment|/* clock period (clock) */
end_comment

begin_define
define|#
directive|define
name|CYCLE
value|10
end_define

begin_comment
comment|/* carrier period (us) */
end_comment

begin_define
define|#
directive|define
name|PCX
value|(NENV * CLOCK)
end_define

begin_comment
comment|/* envelope gate (clock) */
end_comment

begin_define
define|#
directive|define
name|STROBE
value|50
end_define

begin_comment
comment|/* strobe gate (clock) */
end_comment

begin_decl_stmt
name|u_short
name|tg_init
index|[]
init|=
block|{
comment|/* stc initialization vector	*/
literal|0x0562
block|,
literal|12
block|,
literal|13
block|,
comment|/* counter 1 (p0)		*/
literal|0x0262
block|,
name|PGUARD
block|,
name|GRI
block|,
comment|/* counter 2 (gri)		*/
literal|0x8562
block|,
name|PCX
block|,
literal|5000
operator|-
name|PCX
block|,
comment|/* counter 3 (pcx)		*/
literal|0xc562
block|,
literal|0
block|,
name|STROBE
block|,
comment|/* counter 4 (stb)		*/
literal|0x052a
block|,
literal|0
block|,
literal|0
comment|/* counter 5 (out)		*/
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**********************************************************************/
end_comment

begin_expr_stmt
specifier|static
name|TAILQ_HEAD
argument_list|(
argument|qhead
argument_list|,
argument|datapoint
argument_list|)
name|qdone
operator|,
name|qready
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|struct
name|datapoint
name|dummy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int64_t
name|ticker
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_char
name|par
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|datapoint
modifier|*
name|this
decl_stmt|,
modifier|*
name|next
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|MALLOC_DEFINE
argument_list|(
name|M_LORAN
argument_list|,
literal|"Loran"
argument_list|,
literal|"Loran datapoints"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|static
name|int
name|loranerror
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|lorantext
index|[
literal|40
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**********************************************************************/
end_comment

begin_function_decl
specifier|static
name|int
name|loranprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|loranattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|isdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|loranenqueue
parameter_list|(
name|struct
name|datapoint
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|static
name|d_open_t
name|loranopen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_close_t
name|loranclose
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_read_t
name|loranread
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|d_write_t
name|loranwrite
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|timecounter
name|loran_timecounter
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/**********************************************************************/
end_comment

begin_function
name|int
name|loranprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dvp
parameter_list|)
block|{
comment|/* We need to be a "fast-intr" */
name|dvp
operator|->
name|id_ri_flags
operator||=
name|RI_FAST
expr_stmt|;
name|dvp
operator|->
name|id_iobase
operator|=
name|PORT
expr_stmt|;
return|return
operator|(
literal|8
operator|)
return|;
block|}
end_function

begin_function
name|int
name|loranattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|isdp
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|/* We need to be a "fast-intr" */
name|isdp
operator|->
name|id_ri_flags
operator||=
name|RI_FAST
expr_stmt|;
name|printf
argument_list|(
literal|"loran0: LORAN-C Receiver\n"
argument_list|)
expr_stmt|;
comment|/* Initialize the 9513A */
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_RESET
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGC
argument_list|,
name|LOAD
operator|+
literal|0x1f
argument_list|)
expr_stmt|;
comment|/* reset STC chip */
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
name|MASTER
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
literal|0xf0
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
literal|0x8a
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|1
argument_list|)
expr_stmt|;
name|tg_init
index|[
literal|4
index|]
operator|=
literal|7499
operator|-
name|GRI
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|5
operator|*
literal|3
condition|;
name|i
operator|++
control|)
block|{
name|outb
argument_list|(
name|TGD
argument_list|,
name|tg_init
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|tg_init
index|[
name|i
index|]
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADARM
operator|+
literal|0x1f
argument_list|)
expr_stmt|;
comment|/* let the good times roll */
comment|/* Load the VCO DAC */
name|outb
argument_list|(
name|PAR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|DACA
argument_list|,
name|VCO
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|MSB
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|DACA
argument_list|,
name|VCO
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|init_timecounter
argument_list|(
name|loran_timecounter
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|qdone
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|qready
argument_list|)
expr_stmt|;
name|dummy
operator|.
name|agc
operator|=
literal|2000
expr_stmt|;
name|dummy
operator|.
name|code
operator|=
literal|0x55
expr_stmt|;
name|dummy
operator|.
name|delay
operator|=
name|PGUARD
operator|-
name|GRI
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|qready
argument_list|,
operator|&
name|dummy
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|this
operator|=
operator|&
name|dummy
expr_stmt|;
name|next
operator|=
operator|&
name|dummy
expr_stmt|;
name|inb
argument_list|(
name|ADC
argument_list|)
expr_stmt|;
comment|/* Flush any old result */
name|outb
argument_list|(
name|ADC
argument_list|,
name|ADC_S
argument_list|)
expr_stmt|;
name|par
operator|=
name|ENG
operator||
name|IEN
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|loranopen
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fmt
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
name|u_long
name|ef
decl_stmt|;
name|struct
name|datapoint
modifier|*
name|this
decl_stmt|;
while|while
condition|(
operator|!
name|TAILQ_EMPTY
argument_list|(
operator|&
name|qdone
argument_list|)
condition|)
block|{
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|this
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|qdone
argument_list|)
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|qdone
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|this
argument_list|,
name|M_LORAN
argument_list|)
expr_stmt|;
block|}
name|loranerror
operator|=
literal|0
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|loranclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fmt
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
block|{
comment|/* 	 * Lower ENG 	 */
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|loranread
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
block|{
name|u_long
name|ef
decl_stmt|;
name|struct
name|datapoint
modifier|*
name|this
decl_stmt|;
name|int
name|err
decl_stmt|,
name|c
decl_stmt|;
if|if
condition|(
name|loranerror
condition|)
block|{
name|printf
argument_list|(
literal|"Loran0: %s"
argument_list|,
name|lorantext
argument_list|)
expr_stmt|;
return|return
operator|(
name|EIO
operator|)
return|;
block|}
if|if
condition|(
name|TAILQ_EMPTY
argument_list|(
operator|&
name|qdone
argument_list|)
condition|)
name|tsleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|qdone
argument_list|,
name|PZERO
operator|+
literal|8
operator||
name|PCATCH
argument_list|,
literal|"loranrd"
argument_list|,
name|hz
operator|*
literal|2
argument_list|)
expr_stmt|;
if|if
condition|(
name|TAILQ_EMPTY
argument_list|(
operator|&
name|qdone
argument_list|)
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|this
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|qdone
argument_list|)
expr_stmt|;
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|qdone
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
name|c
operator|=
name|imin
argument_list|(
name|uio
operator|->
name|uio_resid
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
expr|*
name|this
argument_list|)
expr_stmt|;
name|err
operator|=
name|uiomove
argument_list|(
operator|(
name|caddr_t
operator|)
name|this
argument_list|,
name|c
argument_list|,
name|uio
argument_list|)
expr_stmt|;
name|FREE
argument_list|(
name|this
argument_list|,
name|M_LORAN
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|loranenqueue
parameter_list|(
name|struct
name|datapoint
modifier|*
name|this
parameter_list|)
block|{
name|struct
name|datapoint
modifier|*
name|p
decl_stmt|,
modifier|*
name|q
decl_stmt|;
name|u_long
name|ef
decl_stmt|;
name|u_int64_t
name|x
decl_stmt|;
if|if
condition|(
name|this
operator|->
name|scheduled
operator|<
name|ticker
condition|)
block|{
name|x
operator|=
operator|(
name|ticker
operator|-
name|this
operator|->
name|scheduled
operator|)
operator|/
operator|(
literal|2
operator|*
name|this
operator|->
name|gri
operator|)
expr_stmt|;
name|this
operator|->
name|scheduled
operator|+=
name|x
operator|*
literal|2
operator|*
name|this
operator|->
name|gri
expr_stmt|;
block|}
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|p
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|qready
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
while|while
condition|(
name|this
operator|->
name|scheduled
operator|<
name|p
operator|->
name|scheduled
operator|+
name|PGUARD
condition|)
name|this
operator|->
name|scheduled
operator|+=
literal|2
operator|*
name|this
operator|->
name|gri
expr_stmt|;
name|q
operator|=
name|TAILQ_NEXT
argument_list|(
name|p
argument_list|,
name|list
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
condition|)
block|{
name|this
operator|->
name|delay
operator|=
name|this
operator|->
name|scheduled
operator|-
name|p
operator|->
name|scheduled
operator|-
name|GRI
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|qready
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|this
operator|->
name|scheduled
operator|+
name|PGUARD
operator|<
name|q
operator|->
name|scheduled
condition|)
block|{
name|this
operator|->
name|delay
operator|=
name|this
operator|->
name|scheduled
operator|-
name|p
operator|->
name|scheduled
operator|-
name|GRI
expr_stmt|;
name|TAILQ_INSERT_BEFORE
argument_list|(
name|q
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|q
operator|->
name|delay
operator|=
name|q
operator|->
name|scheduled
operator|-
name|this
operator|->
name|scheduled
operator|-
name|GRI
expr_stmt|;
break|break;
block|}
name|p
operator|=
name|q
expr_stmt|;
block|}
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|loranwrite
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|ioflag
parameter_list|)
block|{
name|int
name|err
init|=
literal|0
decl_stmt|,
name|c
decl_stmt|;
name|struct
name|datapoint
modifier|*
name|this
decl_stmt|;
name|MALLOC
argument_list|(
name|this
argument_list|,
expr|struct
name|datapoint
operator|*
argument_list|,
sizeof|sizeof
expr|*
name|this
argument_list|,
name|M_LORAN
argument_list|,
name|M_WAITOK
argument_list|)
expr_stmt|;
name|c
operator|=
name|imin
argument_list|(
name|uio
operator|->
name|uio_resid
argument_list|,
operator|(
name|int
operator|)
sizeof|sizeof
expr|*
name|this
argument_list|)
expr_stmt|;
name|err
operator|=
name|uiomove
argument_list|(
operator|(
name|caddr_t
operator|)
name|this
argument_list|,
name|c
argument_list|,
name|uio
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|err
operator|&&
name|this
operator|->
name|gri
operator|==
literal|0
condition|)
name|err
operator|=
name|EINVAL
expr_stmt|;
if|if
condition|(
operator|!
name|err
condition|)
name|loranenqueue
argument_list|(
name|this
argument_list|)
expr_stmt|;
else|else
name|FREE
argument_list|(
name|this
argument_list|,
name|M_LORAN
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_function
name|void
name|loranintr
parameter_list|(
name|int
name|unit
parameter_list|)
block|{
name|u_long
name|ef
decl_stmt|;
name|int
name|status
decl_stmt|,
name|count
init|=
literal|0
decl_stmt|;
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|this
operator|->
name|ssig
operator|=
name|inb
argument_list|(
name|ADC
argument_list|)
expr_stmt|;
name|par
operator|&=
operator|~
operator|(
name|ENG
operator||
name|IEN
operator|)
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|ADC
argument_list|,
name|ADC_I
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|ADCGO
argument_list|,
name|ADC_START
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
operator|(
name|inb
argument_list|(
name|ADCGO
argument_list|)
operator|&
name|ADC_DONE
operator|)
condition|)
continue|continue;
name|this
operator|->
name|isig
operator|=
name|inb
argument_list|(
name|ADC
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|ADC
argument_list|,
name|ADC_Q
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|ADCGO
argument_list|,
name|ADC_START
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
operator|(
name|inb
argument_list|(
name|ADCGO
argument_list|)
operator|&
name|ADC_DONE
operator|)
condition|)
continue|continue;
name|this
operator|->
name|qsig
operator|=
name|inb
argument_list|(
name|ADC
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|ADC
argument_list|,
name|ADC_S
argument_list|)
expr_stmt|;
name|this
operator|->
name|epoch
operator|=
name|ticker
expr_stmt|;
if|if
condition|(
name|this
operator|!=
operator|&
name|dummy
condition|)
block|{
name|nanotime
argument_list|(
operator|&
name|this
operator|->
name|actual
argument_list|)
expr_stmt|;
comment|/* XXX */
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|qdone
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|qdone
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|next
operator|!=
operator|&
name|dummy
operator|||
name|TAILQ_NEXT
argument_list|(
name|next
argument_list|,
name|list
argument_list|)
condition|)
name|TAILQ_REMOVE
argument_list|(
operator|&
name|qready
argument_list|,
name|next
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|this
operator|=
name|next
expr_stmt|;
name|ticker
operator|+=
name|GRI
expr_stmt|;
name|ticker
operator|+=
name|this
operator|->
name|delay
expr_stmt|;
name|next
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|qready
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|next
condition|)
block|{
name|next
operator|=
operator|&
name|dummy
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|qready
argument_list|,
name|next
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|next
operator|->
name|delay
operator|+
name|GRI
operator|>
name|PGUARD
operator|*
literal|2
condition|)
block|{
name|next
operator|->
name|delay
operator|-=
name|PGUARD
expr_stmt|;
name|next
operator|=
operator|&
name|dummy
expr_stmt|;
name|TAILQ_INSERT_HEAD
argument_list|(
operator|&
name|qready
argument_list|,
name|next
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|next
operator|==
operator|&
name|dummy
condition|)
name|next
operator|->
name|scheduled
operator|=
name|ticker
operator|+
name|GRI
operator|+
name|next
operator|->
name|delay
expr_stmt|;
comment|/* load this->params */
name|par
operator|&=
operator|~
operator|(
name|INTEG
operator||
name|GATE
operator|)
expr_stmt|;
name|par
operator||=
name|this
operator|->
name|par
expr_stmt|;
name|par
operator|&=
operator|~
name|MSB
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|DACB
argument_list|,
name|this
operator|->
name|agc
argument_list|)
expr_stmt|;
name|par
operator||=
name|MSB
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|DACB
argument_list|,
name|this
operator|->
name|agc
operator|>>
literal|8
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|this
operator|->
name|code
condition|)
block|{
case|case
literal|256
operator|+
literal|0
case|:
name|outb
argument_list|(
name|CODE
argument_list|,
name|MPCA
argument_list|)
expr_stmt|;
break|break;
case|case
literal|256
operator|+
literal|1
case|:
name|outb
argument_list|(
name|CODE
argument_list|,
name|MPCB
argument_list|)
expr_stmt|;
break|break;
case|case
literal|256
operator|+
literal|2
case|:
name|outb
argument_list|(
name|CODE
argument_list|,
name|SPCA
argument_list|)
expr_stmt|;
break|break;
case|case
literal|256
operator|+
literal|3
case|:
name|outb
argument_list|(
name|CODE
argument_list|,
name|SPCB
argument_list|)
expr_stmt|;
break|break;
default|default:
name|outb
argument_list|(
name|CODE
argument_list|,
name|this
operator|->
name|code
argument_list|)
expr_stmt|;
break|break;
block|}
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|0x0c
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|this
operator|->
name|phase
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|this
operator|->
name|phase
operator|>>
literal|8
argument_list|)
expr_stmt|;
comment|/* load next->delay into 9513 */
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|0x0a
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|next
operator|->
name|delay
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|next
operator|->
name|delay
operator|>>
literal|8
argument_list|)
expr_stmt|;
name|status
operator|=
name|inb
argument_list|(
name|TGC
argument_list|)
expr_stmt|;
name|status
operator|&=
literal|0x1c
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_SAVE
operator|+
literal|2
argument_list|)
expr_stmt|;
comment|/* save counter #2 */
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|0x12
argument_list|)
expr_stmt|;
comment|/* hold counter #2 */
name|count
operator|=
name|inb
argument_list|(
name|TGD
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|count
operator||=
name|inb
argument_list|(
name|TGD
argument_list|)
operator|<<
literal|8
expr_stmt|;
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|0x12
argument_list|)
expr_stmt|;
comment|/* hold counter #2 */
name|outb
argument_list|(
name|TGD
argument_list|,
name|GRI
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGD
argument_list|,
name|GRI
operator|>>
literal|8
argument_list|)
expr_stmt|;
block|}
name|par
operator||=
name|ENG
operator||
name|IEN
expr_stmt|;
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
condition|)
block|{
name|sprintf
argument_list|(
name|lorantext
argument_list|,
literal|"Missed: %02x %d %d\n"
argument_list|,
name|status
argument_list|,
name|count
argument_list|,
name|next
operator|->
name|delay
argument_list|)
expr_stmt|;
name|loranerror
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|next
operator|->
name|delay
operator|<
name|PGUARD
operator|-
name|GRI
condition|)
block|{
name|sprintf
argument_list|(
name|lorantext
argument_list|,
literal|"Bogus: %02x %d %d\n"
argument_list|,
name|status
argument_list|,
name|count
argument_list|,
name|next
operator|->
name|delay
argument_list|)
expr_stmt|;
name|loranerror
operator|=
literal|1
expr_stmt|;
block|}
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**********************************************************************/
end_comment

begin_function
specifier|static
name|u_int64_t
name|loran_get_timecount
parameter_list|(
name|void
parameter_list|)
block|{
name|u_int32_t
name|count
decl_stmt|;
name|u_long
name|ef
decl_stmt|;
name|u_int
name|high
decl_stmt|,
name|low
decl_stmt|;
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_SAVE
operator|+
literal|0x10
argument_list|)
expr_stmt|;
comment|/* save counter #5 */
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADDP
operator|+
literal|0x15
argument_list|)
expr_stmt|;
comment|/* hold counter #5 */
name|count
operator|=
name|inb
argument_list|(
name|TGD
argument_list|)
expr_stmt|;
name|count
operator||=
name|inb
argument_list|(
name|TGD
argument_list|)
operator|<<
literal|8
expr_stmt|;
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
return|return
operator|(
name|count
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|struct
name|timecounter
name|loran_timecounter
index|[
literal|3
index|]
init|=
block|{
literal|0
block|,
comment|/* get_timedelta */
name|loran_get_timecount
block|,
comment|/* get_timecount */
literal|0xffff
block|,
comment|/* counter_mask */
literal|5000000
block|,
comment|/* frequency */
literal|"loran"
comment|/* name */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_OPAQUE
argument_list|(
name|_debug
argument_list|,
name|OID_AUTO
argument_list|,
name|loran_timecounter
argument_list|,
name|CTLFLAG_RD
argument_list|,
name|loran_timecounter
argument_list|,
sizeof|sizeof
argument_list|(
name|loran_timecounter
argument_list|)
argument_list|,
literal|"S,timecounter"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**********************************************************************/
end_comment

begin_decl_stmt
name|struct
name|isa_driver
name|lorandriver
init|=
block|{
name|loranprobe
block|,
name|loranattach
block|,
literal|"loran"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CDEV_MAJOR
value|94
end_define

begin_decl_stmt
specifier|static
name|struct
name|cdevsw
name|loran_cdevsw
init|=
block|{
name|loranopen
block|,
name|loranclose
block|,
name|loranread
block|,
name|loranwrite
block|,
name|noioctl
block|,
name|nullstop
block|,
name|nullreset
block|,
name|nodevtotty
block|,
name|seltrue
block|,
name|nommap
block|,
name|nostrat
block|,
literal|"loran"
block|,
name|NULL
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|loran_devsw_installed
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|loran_drvinit
parameter_list|(
name|void
modifier|*
name|unused
parameter_list|)
block|{
name|dev_t
name|dev
decl_stmt|;
if|if
condition|(
operator|!
name|loran_devsw_installed
condition|)
block|{
name|dev
operator|=
name|makedev
argument_list|(
name|CDEV_MAJOR
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|cdevsw_add
argument_list|(
operator|&
name|dev
argument_list|,
operator|&
name|loran_cdevsw
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|loran_devsw_installed
operator|=
literal|1
expr_stmt|;
block|}
block|}
end_function

begin_macro
name|SYSINIT
argument_list|(
argument|lorandev
argument_list|,
argument|SI_SUB_DRIVERS
argument_list|,
argument|SI_ORDER_MIDDLE+CDEV_MAJOR
argument_list|,
argument|loran_drvinit
argument_list|,
argument|NULL
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

