begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  * This device-driver helps the userland controlprogram for a LORAN-C  * receiver avoid monopolizing the CPU.  *  * This is clearly a candidate for the "most weird hardware support in  * FreeBSD" prize.  At this time only two copies of the receiver are  * known to exist in the entire world.  *  * Details can be found at:  *     ftp://ftp.eecis.udel.edu/pub/ntp/loran.tar.Z  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
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
comment|/* _KERNEL */
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
comment|/* Fields used only in userland */
name|double
name|ival
decl_stmt|;
name|double
name|qval
decl_stmt|;
name|double
name|sval
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
name|_KERNEL
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
specifier|extern
name|struct
name|cdevsw
name|loran_cdevsw
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|dphead_t
name|minors
index|[
name|NLORAN
operator|+
literal|1
index|]
decl_stmt|,
name|working
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
decl_stmt|,
modifier|*
name|first
decl_stmt|,
modifier|*
name|second
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
literal|160
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
specifier|static
name|int
name|once
decl_stmt|;
if|if
condition|(
operator|!
name|once
operator|++
condition|)
name|cdevsw_add
argument_list|(
operator|&
name|loran_cdevsw
argument_list|)
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
comment|/* isdp->id_ri_flags |= RI_FAST; XXX unimplemented - use newbus! */
name|printf
argument_list|(
literal|"loran0: LORAN-C Receiver\n"
argument_list|)
expr_stmt|;
name|vco_want
operator|=
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
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NLORAN
operator|+
literal|1
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
name|scheduled
operator|=
name|PGUARD
operator|*
literal|2
operator|*
name|i
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
name|NLORAN
operator|*
literal|256
expr_stmt|;
name|dummy
index|[
name|i
index|]
operator|.
name|home
operator|=
operator|&
name|minors
index|[
name|NLORAN
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|first
operator|=
operator|&
name|dummy
index|[
name|i
index|]
expr_stmt|;
elseif|else
if|if
condition|(
name|i
operator|==
literal|1
condition|)
name|second
operator|=
operator|&
name|dummy
index|[
name|i
index|]
expr_stmt|;
else|else
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
name|loranerror
operator|=
literal|0
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
decl_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|dpp
argument_list|,
argument|&working
argument_list|,
argument|list
argument_list|)
block|{
if|if
condition|(
name|dpp
operator|->
name|priority
operator|<=
name|dp
operator|->
name|priority
condition|)
continue|continue;
name|TAILQ_INSERT_BEFORE
argument_list|(
name|dpp
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
return|return;
block|}
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|working
argument_list|,
name|dp
argument_list|,
name|list
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
name|u_int64_t
name|when
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
name|err
condition|)
block|{
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
if|if
condition|(
name|this
operator|->
name|fri
operator|==
literal|0
condition|)
block|{
name|FREE
argument_list|(
name|this
argument_list|,
name|M_LORAN
argument_list|)
expr_stmt|;
return|return
operator|(
name|EINVAL
operator|)
return|;
block|}
name|this
operator|->
name|par
operator|&=
name|INTEG
operator||
name|GATE
expr_stmt|;
comment|/* XXX more checks needed! */
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
operator|&=
literal|0xff
expr_stmt|;
name|this
operator|->
name|priority
operator|+=
name|idx
operator|*
literal|256
expr_stmt|;
name|this
operator|->
name|bounce
operator|=
literal|0
expr_stmt|;
name|when
operator|=
name|second
operator|->
name|scheduled
operator|+
name|PGUARD
expr_stmt|;
if|if
condition|(
name|when
operator|>
name|this
operator|->
name|scheduled
condition|)
block|{
name|dt
operator|=
name|when
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
name|i
decl_stmt|;
if|#
directive|if
literal|0
block|int count = 0;
endif|#
directive|endif
name|int
name|delay
decl_stmt|;
name|u_int64_t
name|when
decl_stmt|;
name|struct
name|timespec
name|there
decl_stmt|,
name|then
decl_stmt|;
name|struct
name|datapoint
modifier|*
name|dp
decl_stmt|,
modifier|*
name|done
decl_stmt|;
name|ef
operator|=
name|read_eflags
argument_list|()
expr_stmt|;
name|disable_intr
argument_list|()
expr_stmt|;
comment|/* 	 * Pick up the measurement which just completed, and setup 	 * the next measurement.  We have 1100 microseconds for this 	 * of which some eaten by the A/D of the S channel and the  	 * interrupt to get us here. 	 */
name|done
operator|=
name|first
expr_stmt|;
name|nanotime
argument_list|(
operator|&
name|there
argument_list|)
expr_stmt|;
name|done
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
comment|/* Interlude: while we wait: setup the next measurement */
name|LOAD_DAC
argument_list|(
name|DACB
argument_list|,
name|second
operator|->
name|agc
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|CODE
argument_list|,
name|second
operator|->
name|code
argument_list|)
expr_stmt|;
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
name|second
operator|->
name|par
expr_stmt|;
name|par
operator||=
name|ENG
operator||
name|IEN
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
name|done
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
comment|/* Interlude: while we wait: setup the next measurement */
comment|/* 		 * We need to load this from the opposite register due to some  		 * weirdness which you can read about in in the 9513 manual on  		 * page 1-26 under "LOAD" 		 */
name|LOAD_9513
argument_list|(
literal|0x0c
argument_list|,
name|second
operator|->
name|phase
argument_list|)
expr_stmt|;
name|LOAD_9513
argument_list|(
literal|0x14
argument_list|,
name|second
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
name|second
operator|->
name|width
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
name|done
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
name|outb
argument_list|(
name|PAR
argument_list|,
name|par
argument_list|)
expr_stmt|;
comment|/* 	 * End of VERY time critical stuff, we have 8 msec to find 	 * the next measurement and program the delay. 	 */
name|status
operator|=
name|inb
argument_list|(
name|TGC
argument_list|)
expr_stmt|;
name|nanotime
argument_list|(
operator|&
name|then
argument_list|)
expr_stmt|;
name|first
operator|=
name|second
expr_stmt|;
name|second
operator|=
literal|0
expr_stmt|;
name|when
operator|=
name|first
operator|->
name|scheduled
operator|+
name|PGUARD
expr_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|dp
argument_list|,
argument|&working
argument_list|,
argument|list
argument_list|)
block|{
while|while
condition|(
name|dp
operator|->
name|scheduled
operator|<
name|when
condition|)
name|dp
operator|->
name|scheduled
operator|+=
name|dp
operator|->
name|fri
expr_stmt|;
if|if
condition|(
name|second
operator|&&
name|dp
operator|->
name|scheduled
operator|+
name|PGUARD
operator|>=
name|second
operator|->
name|scheduled
condition|)
continue|continue;
name|second
operator|=
name|dp
expr_stmt|;
block|}
name|delay
operator|=
operator|(
name|second
operator|->
name|scheduled
operator|-
name|first
operator|->
name|scheduled
operator|)
operator|-
name|GRI
expr_stmt|;
name|LOAD_9513
argument_list|(
literal|0x0a
argument_list|,
name|delay
argument_list|)
expr_stmt|;
comment|/* Done, the rest is leisure work */
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
comment|/* Check if we overran */
name|status
operator|&=
literal|0x0c
expr_stmt|;
if|#
directive|if
literal|0
block|if (status) { 		outb(TGC, TG_SAVE + 2);
comment|/* save counter #2 */
block|outb(TGC, TG_LOADDP + 0x12);
comment|/* hold counter #2 */
block|count = inb(TGD); 		count |= inb(TGD)<< 8; 		LOAD_9513(0x12, GRI) 	}
endif|#
directive|endif
if|if
condition|(
name|status
condition|)
block|{
name|printf
argument_list|(
literal|"Missed: %02x %d first:%p second:%p %.09ld\n"
argument_list|,
name|status
argument_list|,
name|delay
argument_list|,
name|first
argument_list|,
name|second
argument_list|,
name|then
operator|.
name|tv_nsec
operator|-
name|there
operator|.
name|tv_nsec
argument_list|)
expr_stmt|;
name|first
operator|->
name|bounce
operator|++
expr_stmt|;
block|}
name|TAILQ_REMOVE
argument_list|(
operator|&
name|working
argument_list|,
name|second
argument_list|,
name|list
argument_list|)
expr_stmt|;
if|if
condition|(
name|done
operator|->
name|bounce
condition|)
block|{
name|done
operator|->
name|bounce
operator|=
literal|0
expr_stmt|;
name|loranenqueue
argument_list|(
name|done
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|done
operator|->
name|epoch
operator|=
name|ticker
expr_stmt|;
name|done
operator|->
name|vco
operator|=
name|vco_is
expr_stmt|;
name|done
operator|->
name|when
operator|=
name|there
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
name|done
operator|->
name|home
argument_list|,
name|done
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
name|done
operator|->
name|home
argument_list|)
expr_stmt|;
block|}
name|ticker
operator|=
name|first
operator|->
name|scheduled
expr_stmt|;
while|while
condition|(
operator|(
name|dp
operator|=
name|TAILQ_FIRST
argument_list|(
operator|&
name|minors
index|[
name|NLORAN
index|]
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|TAILQ_REMOVE
argument_list|(
operator|&
name|minors
index|[
name|NLORAN
index|]
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
name|TAILQ_INSERT_TAIL
argument_list|(
operator|&
name|working
argument_list|,
name|dp
argument_list|,
name|list
argument_list|)
expr_stmt|;
block|}
name|when
operator|=
name|second
operator|->
name|scheduled
operator|+
name|PGUARD
expr_stmt|;
name|TAILQ_FOREACH
argument_list|(
argument|dp
argument_list|,
argument|&working
argument_list|,
argument|list
argument_list|)
block|{
while|while
condition|(
name|dp
operator|->
name|scheduled
operator|<
name|when
condition|)
name|dp
operator|->
name|scheduled
operator|+=
name|dp
operator|->
name|fri
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
comment|/* open */
name|loranopen
block|,
comment|/* close */
name|loranclose
block|,
comment|/* read */
name|loranread
block|,
comment|/* write */
name|loranwrite
block|,
comment|/* ioctl */
name|noioctl
block|,
comment|/* poll */
name|nopoll
block|,
comment|/* mmap */
name|nommap
block|,
comment|/* strategy */
name|nostrategy
block|,
comment|/* name */
literal|"loran"
block|,
comment|/* maj */
name|CDEV_MAJOR
block|,
comment|/* dump */
name|nodump
block|,
comment|/* psize */
name|nopsize
block|,
comment|/* flags */
literal|0
block|,
comment|/* bmaj */
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

end_unit

