begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: loran.c,v 1.17 1999/05/06 22:13:04 peter Exp $  *  * This device-driver helps the userland controlprogram for a LORAN-C  * receiver avoid monopolizing the CPU.  *  * This is clearly a candidate for the "most weird hardware support in  * FreeBSD" prize.  At this time only two copies of the receiver are  * known to exist in the entire world.  *  * Details can be found at:  *     ftp://ftp.eecis.udel.edu/pub/ntp/loran.tar.Z  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

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
file|<sys/malloc.h>
end_include

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

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|datapoint
argument_list|)
name|dphead_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|datapoint
block|{
comment|/* Fields used by kernel */
name|u_int64_t
name|scheduled
decl_stmt|;
name|u_int
name|code
decl_stmt|;
name|u_int
name|fri
decl_stmt|;
name|u_int
name|agc
decl_stmt|;
name|u_int
name|phase
decl_stmt|;
name|u_int
name|width
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
name|TAILQ_ENTRY
argument_list|(
argument|datapoint
argument_list|)
name|list
expr_stmt|;
name|u_char
name|status
decl_stmt|;
name|int
name|vco
decl_stmt|;
name|int
name|bounce
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|struct
name|timespec
name|when
decl_stmt|;
name|int
name|priority
decl_stmt|;
name|dphead_t
modifier|*
name|home
decl_stmt|;
comment|/* Fields used only in userland */
name|void
function_decl|(
modifier|*
name|proc
function_decl|)
parameter_list|(
name|struct
name|datapoint
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ident
decl_stmt|;
name|int
name|index
decl_stmt|;
name|char
modifier|*
name|name
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
value|0x0
end_define

begin_define
define|#
directive|define
name|GATE_GRI
value|0x4
end_define

begin_define
define|#
directive|define
name|GATE_PCI
value|0x8
end_define

begin_define
define|#
directive|define
name|GATE_STB
value|0xc
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

begin_define
define|#
directive|define
name|VCO_SHIFT
value|8
end_define

begin_comment
comment|/* bits of fraction on VCO value */
end_comment

begin_define
define|#
directive|define
name|VCO
value|(2048<< VCO_SHIFT)
end_define

begin_comment
comment|/* initial vco dac (0 V)*/
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|NLORAN
value|10
end_define

begin_comment
comment|/* Allow ten minor devices */
end_comment

begin_define
define|#
directive|define
name|NDUMMY
value|4
end_define

begin_comment
comment|/* How many idlers we want */
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

begin_define
define|#
directive|define
name|LOAD_DAC
parameter_list|(
name|dac
parameter_list|,
name|val
parameter_list|)
value|if (0) { } else {				\ 	par&= ~MSB; outb(PAR, par); outb((dac), (val)& 0xff);		\ 	par |=  MSB; outb(PAR, par); outb((dac), ((val)>> 8)& 0xff);	\ 	}
end_define

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
name|LOAD_9513
parameter_list|(
name|index
parameter_list|,
name|val
parameter_list|)
value|if (0) {} else {		\ 	outb(TGC, TG_LOADDP + (index));			\ 	outb(TGD, (val)& 0xff);					\ 	outb(TGD, ((val)>> 8)& 0xff);				\ 	}
end_define

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

begin_comment
comment|/**********************************************************************/
end_comment

begin_decl_stmt
specifier|static
name|dphead_t
name|minors
index|[
name|NLORAN
index|]
decl_stmt|,
name|working
decl_stmt|,
name|holding
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|datapoint
name|dummy
index|[
name|NDUMMY
index|]
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
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|vco_is
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|vco_should
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|vco_want
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int64_t
name|vco_when
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int64_t
name|vco_error
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
name|void
name|init_tgc
parameter_list|(
name|void
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
name|ointhand2_t
name|loranintr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timecounter
name|loran_timecounter
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

begin_decl_stmt
specifier|static
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
comment|/* counter 1 (p0)  Mode J	*/
literal|0x0262
block|,
name|PGUARD
block|,
name|GRI
block|,
comment|/* counter 2 (gri) Mode J	*/
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
comment|/* counter 4 (stb) Mode L	*/
literal|0x052a
block|,
literal|0
block|,
literal|0
comment|/* counter 5 (out)		*/
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|init_tgc
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
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
name|LOAD_9513
argument_list|(
name|MASTER
argument_list|,
literal|0x8af0
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
name|isdp
operator|->
name|id_ointr
operator|=
name|loranintr
expr_stmt|;
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
name|vco_should
operator|=
name|VCO
expr_stmt|;
name|vco_is
operator|=
name|vco_should
operator|>>
name|VCO_SHIFT
expr_stmt|;
name|LOAD_DAC
argument_list|(
name|DACA
argument_list|,
name|vco_is
argument_list|)
expr_stmt|;
name|init_tgc
argument_list|()
expr_stmt|;
name|init_timecounter
argument_list|(
operator|&
name|loran_timecounter
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|working
argument_list|)
expr_stmt|;
name|TAILQ_INIT
argument_list|(
operator|&
name|holding
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
name|NLORAN
condition|;
name|i
operator|++
control|)
block|{
name|TAILQ_INIT
argument_list|(
operator|&
name|minors
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NDUMMY
condition|;
name|i
operator|++
control|)
block|{
name|dummy
index|[
name|i
index|]
operator|.
name|agc
operator|=
literal|4095
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|code
operator|=
literal|0xac
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|fri
operator|=
name|PGUARD
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|phase
operator|=
literal|50
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|width
operator|=
literal|50
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|priority
operator|=
literal|9999
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|working
argument_list|,
operator|&
name|dummy
index|[
name|i
index|]
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
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
name|int
name|idx
decl_stmt|;
name|idx
operator|=
name|minor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|idx
operator|>=
name|NLORAN
condition|)
return|return
operator|(
name|ENODEV
operator|)
return|;
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
name|int
name|idx
decl_stmt|;
name|idx
operator|=
name|minor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
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
name|minors
index|[
name|idx
index|]
argument_list|)
condition|)
name|tsleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|minors
index|[
name|idx
index|]
argument_list|,
operator|(
name|PZERO
operator|+
literal|8
operator|)
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
name|minors
index|[
name|idx
index|]
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
name|minors
index|[
name|idx
index|]
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
name|minors
index|[
name|idx
index|]
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
name|dp
parameter_list|)
block|{
name|struct
name|datapoint
modifier|*
name|dpp
decl_stmt|,
modifier|*
name|dpn
decl_stmt|;
while|while
condition|(
name|dp
condition|)
block|{
comment|/* 		 * The first two elements on "working" are sacred, 		 * they're already partly setup in hardware, so the 		 * earliest slot we can use is #3 		 */
name|dpp
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|working
argument_list|)
expr_stmt|;
name|dpp
operator|=
name|TAILQ_NEXT
argument_list|(
name|dpp
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|dpn
operator|=
name|TAILQ_NEXT
argument_list|(
name|dpp
argument_list|,
name|list
argument_list|)
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
comment|/*  			 * We cannot bump "dpp", so if "dp" overlaps it 			 * skip a beat. 			 * XXX: should use better algorithm ? 			 */
if|if
condition|(
name|dpp
operator|->
name|scheduled
operator|+
name|PGUARD
operator|>
name|dp
operator|->
name|scheduled
condition|)
block|{
name|dp
operator|->
name|scheduled
operator|+=
name|dp
operator|->
name|fri
expr_stmt|;
continue|continue;
block|}
comment|/* 			 * If "dpn" will be done before "dp" wants to go, 			 * we must look further down the list. 			 */
if|if
condition|(
name|dpn
operator|&&
name|dpn
operator|->
name|scheduled
operator|+
name|PGUARD
operator|<
name|dp
operator|->
name|scheduled
condition|)
block|{
name|dpp
operator|=
name|dpn
expr_stmt|;
name|dpn
operator|=
name|TAILQ_NEXT
argument_list|(
name|dpp
argument_list|,
name|list
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/*  			 * If at end of list, put "dp" there 			 */
if|if
condition|(
operator|!
name|dpn
condition|)
block|{
name|TAILQ_INSERT_AFTER
argument_list|(
operator|&
name|working
argument_list|,
name|dpp
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* 			 * If "dp" fits before "dpn", insert it there 			 */
if|if
condition|(
name|dpn
operator|->
name|scheduled
operator|>
name|dp
operator|->
name|scheduled
operator|+
name|PGUARD
condition|)
block|{
name|TAILQ_INSERT_AFTER
argument_list|(
operator|&
name|working
argument_list|,
name|dpp
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
break|break;
block|}
comment|/* 			 * If "dpn" is less important, bump it. 			 */
if|if
condition|(
name|dp
operator|->
name|priority
operator|<
name|dpn
operator|->
name|priority
condition|)
block|{
name|TAILQ_REMOVE
argument_list|(
operator|&
name|working
argument_list|,
name|dpn
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|holding
argument_list|,
name|dpn
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|dpn
operator|=
name|TAILQ_NEXT
argument_list|(
name|dpp
argument_list|,
name|list
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|/* 			 * "dpn" was more or equally important, "dp" must 			 * take yet turn. 			 */
name|dp
operator|->
name|scheduled
operator|+=
name|dp
operator|->
name|fri
expr_stmt|;
block|}
do|do
block|{
comment|/* 			 * If anything was bumped, put it back as best we can 			 */
if|if
condition|(
name|TAILQ_EMPTY
argument_list|(
operator|&
name|holding
argument_list|)
condition|)
block|{
name|dp
operator|=
literal|0
expr_stmt|;
break|break;
block|}
name|dp
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|holding
argument_list|)
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|holding
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
if|if
condition|(
name|dp
operator|->
name|home
condition|)
block|{
if|if
condition|(
operator|!
operator|--
name|dp
operator|->
name|bounce
condition|)
block|{
name|TAILQ_INSERT_TAIL
argument_list|(
name|dp
operator|->
name|home
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|dp
operator|->
name|home
argument_list|)
expr_stmt|;
name|dp
operator|=
literal|0
expr_stmt|;
block|}
block|}
block|}
do|while
condition|(
operator|!
name|dp
condition|)
do|;
block|}
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
name|u_long
name|ef
decl_stmt|;
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
name|int
name|idx
decl_stmt|;
name|u_int64_t
name|dt
decl_stmt|;
name|idx
operator|=
name|minor
argument_list|(
name|dev
argument_list|)
expr_stmt|;
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
name|fri
operator|==
literal|0
condition|)
name|err
operator|=
name|EINVAL
expr_stmt|;
comment|/* XXX more checks */
name|this
operator|->
name|home
operator|=
operator|&
name|minors
index|[
name|idx
index|]
expr_stmt|;
name|this
operator|->
name|priority
operator|=
name|idx
expr_stmt|;
if|if
condition|(
name|ticker
operator|>
name|this
operator|->
name|scheduled
condition|)
block|{
name|dt
operator|=
name|ticker
operator|-
name|this
operator|->
name|scheduled
expr_stmt|;
name|dt
operator|-=
name|dt
operator|%
name|this
operator|->
name|fri
expr_stmt|;
name|this
operator|->
name|scheduled
operator|+=
name|dt
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|err
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
name|loranenqueue
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|write_eflags
argument_list|(
name|ef
argument_list|)
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|vco
operator|>=
literal|0
condition|)
name|vco_want
operator|=
name|this
operator|->
name|vco
expr_stmt|;
block|}
else|else
block|{
name|FREE
argument_list|(
name|this
argument_list|,
name|M_LORAN
argument_list|)
expr_stmt|;
block|}
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
init|=
literal|0
decl_stmt|,
name|count
init|=
literal|0
decl_stmt|,
name|i
decl_stmt|;
name|struct
name|datapoint
modifier|*
name|this
decl_stmt|,
modifier|*
name|next
decl_stmt|;
name|int
name|delay
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
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|working
argument_list|)
expr_stmt|;
name|TAILQ_REMOVE
argument_list|(
operator|&
name|working
argument_list|,
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|nanotime
argument_list|(
operator|&
name|this
operator|->
name|when
argument_list|)
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
name|this
operator|->
name|vco
operator|=
name|vco_is
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|home
condition|)
block|{
name|TAILQ_INSERT_TAIL
argument_list|(
name|this
operator|->
name|home
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
name|this
operator|->
name|home
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|loranenqueue
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
name|this
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|working
argument_list|)
expr_stmt|;
name|next
operator|=
name|TAILQ_NEXT
argument_list|(
name|this
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|delay
operator|=
name|next
operator|->
name|scheduled
operator|-
name|this
operator|->
name|scheduled
expr_stmt|;
name|delay
operator|-=
name|GRI
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
operator|&
operator|(
name|INTEG
operator||
name|GATE
operator|)
expr_stmt|;
name|LOAD_DAC
argument_list|(
name|DACB
argument_list|,
name|this
operator|->
name|agc
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|CODE
argument_list|,
name|this
operator|->
name|code
argument_list|)
expr_stmt|;
name|LOAD_9513
argument_list|(
literal|0x0a
argument_list|,
name|delay
argument_list|)
expr_stmt|;
comment|/* 	 * We need to load this from the opposite register * due to some  	 * weirdness which you can read about in in the 9513 manual on  	 * page 1-26 under "LOAD" 	 */
name|LOAD_9513
argument_list|(
literal|0x0c
argument_list|,
name|this
operator|->
name|phase
argument_list|)
expr_stmt|;
name|LOAD_9513
argument_list|(
literal|0x14
argument_list|,
name|this
operator|->
name|phase
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|TGC
argument_list|,
name|TG_LOADARM
operator|+
literal|0x08
argument_list|)
expr_stmt|;
name|LOAD_9513
argument_list|(
literal|0x14
argument_list|,
name|this
operator|->
name|width
argument_list|)
expr_stmt|;
name|vco_error
operator|+=
operator|(
operator|(
name|vco_is
operator|<<
name|VCO_SHIFT
operator|)
operator|-
name|vco_should
operator|)
operator|*
operator|(
name|ticker
operator|-
name|vco_when
operator|)
expr_stmt|;
name|vco_should
operator|=
name|vco_want
expr_stmt|;
name|i
operator|=
name|vco_should
operator|>>
name|VCO_SHIFT
expr_stmt|;
if|if
condition|(
name|vco_error
operator|<
literal|0
condition|)
name|i
operator|++
expr_stmt|;
if|if
condition|(
name|vco_is
operator|!=
name|i
condition|)
block|{
name|LOAD_DAC
argument_list|(
name|DACA
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|vco_is
operator|=
name|i
expr_stmt|;
block|}
name|vco_when
operator|=
name|ticker
expr_stmt|;
name|this
operator|->
name|status
operator|=
name|inb
argument_list|(
name|TGC
argument_list|)
expr_stmt|;
if|#
directive|if
literal|1
comment|/* Check if we overran */
name|status
operator|=
name|this
operator|->
name|status
operator|&
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
name|LOAD_9513
argument_list|(
literal|0x12
argument_list|,
argument|GRI
argument_list|)
block|}
endif|#
directive|endif
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
name|snprintf
argument_list|(
name|lorantext
argument_list|,
sizeof|sizeof
argument_list|(
name|lorantext
argument_list|)
argument_list|,
literal|"Missed: %02x %d %d this:%p next:%p (dummy=%p)\n"
argument_list|,
name|status
argument_list|,
name|count
argument_list|,
name|delay
argument_list|,
name|this
argument_list|,
name|next
argument_list|,
operator|&
name|dummy
argument_list|)
expr_stmt|;
name|loranerror
operator|=
literal|1
expr_stmt|;
block|}
name|ticker
operator|=
name|this
operator|->
name|scheduled
expr_stmt|;
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
name|unsigned
name|loran_get_timecount
parameter_list|(
name|struct
name|timecounter
modifier|*
name|tc
parameter_list|)
block|{
name|unsigned
name|count
decl_stmt|;
name|u_long
name|ef
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
init|=
block|{
name|loran_get_timecount
block|,
comment|/* get_timecount */
literal|0
block|,
comment|/* no pps_poll */
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
operator|&
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

begin_decl_stmt
specifier|static
name|int
name|loran_devsw_installed
decl_stmt|;
end_decl_stmt

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

