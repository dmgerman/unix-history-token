begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    sound/aedsp16.c     Audio Excel DSP 16 software configuration routines     Copyright (C) 1995  Riccardo Facchetti (riccardo@cdc8g5.cdc.polimi.it)     Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are    met: 1. Redistributions of source code must retain the above copyright    notice, this list of conditions and the following disclaimer. 2.    Redistributions in binary form must reproduce the above copyright notice,    this list of conditions and the following disclaimer in the documentation    and/or other materials provided with the distribution.     THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE    DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF    SUCH DAMAGE.     READ THIS     This module is intended for Audio Excel DSP 16 Sound Card.     Audio Excel DSP 16 is an SB pro II, Microsoft Sound System    and MPU-401 compatible card.    It is software-only configurable (no jumpers to hard-set irq/dma/mpu-irq),    so before this module, the only way to configure the DSP under linux was    boot the MS-BAU loading the sound.sys device driver (this driver soft-    configure the sound board hardware by massaging someone of its registers),    and then ctrl-alt-del to boot linux with the DSP configured by the DOG    driver.     This module works configuring your Audio Excel DSP 16's    irq, dma and mpu-401-irq. The voxware probe routines rely on the    fact that if the hardware is there, they can detect it. The problem    with AEDSP16 is that no hardware can be found by the probe routines    if the sound card is not well configured. Sometimes the kernel probe    routines can find an SBPRO even when the card is not configured (this    is the standard setup of the card), but the SBPRO emulation don't work    well if the card is not properly initialized. For this reason     InitAEDSP16_...()     routines are called before the voxware probe routines try to detect the    hardware.     NOTE (READ THE NOTE TOO, IT CONTAIN USEFUL INFORMATIONS)     The Audio Excel DSP 16 Sound Card emulates both SBPRO and MSS;    the voxware sound driver can be configured for SBPRO and MSS cards    at the same time, but the aedsp16 can't be two cards!!    When we configure it, we have to choose the SBPRO or the MSS emulation    for AEDSP16. We also can install a *REAL* card of the other type    (see [1], not tested but I can't see any reason for it to fail).     NOTE: If someone can test the combination AEDSP16+MSS or AEDSP16+SBPRO    please let me know if it works.     The MPU-401 support can be compiled in together with one of the other    two operating modes.     The board configuration calls, are in the probe_...() routines because    we have to configure the board before probing it for a particular    hardware. After card configuration, we can probe the hardware.     NOTE: This is something like plug-and-play: we have only to plug    the AEDSP16 board in the socket, and then configure and compile    a kernel that uses the AEDSP16 software configuration capability.    No jumper setting is needed!     For example, if you want AEDSP16 to be an SBPro, on irq 10, dma 3    you have just to make config the voxware package, configuring    the SBPro sound card with that parameters, then when configure    asks if you have an AEDSP16, answer yes. That's it.    Compile the kernel and run it.     NOTE: This means that you can choose irq and dma, but not the    I/O addresses. To change I/O addresses you have to set them    with jumpers.     NOTE: InitAEDSP16_...() routines get as parameter the hw_config,    the hardware configuration of the - to be configured - board.    The InitAEDSP16() routine, configure the board following our    wishes, that are in the hw_config structure.     You can change the irq/dma/mirq settings WITHOUT THE NEED to open    your computer and massage the jumpers (there are no irq/dma/mirq    jumpers to be configured anyway, only I/O port ones have to be    configured with jumpers)     For some ununderstandable reason, the card default of irq 7, dma 1,    don't work for me. Seems to be an IRQ or DMA conflict. Under heavy    HDD work, the kernel start to erupt out a lot of messages like:     'Sound: DMA timed out - IRQ/DRQ config error?'     For what I can say, I have NOT any conflict at irq 7 (under linux I'm    using the lp polling driver), and dma line 1 is unused as stated by    /proc/dma. I can suppose this is a bug of AEDSP16. I know my hardware so    I'm pretty sure I have not any conflict, but may be I'm wrong. Who knows!    Anyway a setting of irq 10, dma 3 works really fine.     NOTE: if someone can use AEDSP16 with irq 7, dma 1, please let me know    the emulation mode, all the installed hardware and the hardware    configuration (irq and dma settings of all the hardware).     This init module should work with SBPRO+MSS, when one of the two is    the AEDSP16 emulation and the other the real card. (see [1])    For example:     AEDSP16 (0x220) in SBPRO emu (0x220) + real MSS + other    AEDSP16 (0x220) in MSS emu + real SBPRO (0x240) + other     MPU401 should work. (see [1])     [1] Not tested by me for lack of hardware.     TODO, WISHES AND TECH     May be there's lot of redundant delays, but for now I want to leave it    this way.     Should be interesting eventually write down a new ioctl for the    aedsp16, to let the suser() change the irq/dma/mirq on the fly.    The thing is not trivial.    In the real world, there's no need to have such an ioctl because    when we configure the kernel for compile, we can choose the config    parameters. If we change our mind, we can easily re-config the kernel    and re-compile.    Why let the suser() change the config parameters on the fly ?    If anyone have a reasonable answer to this question, I will write down    the code to do it.     More integration with voxware, using voxware low level routines to    read-write dsp is not possible because you may want to have MSS    support and in that case we can not rely on the functions included    in sb_dsp.c to control 0x2yy I/O ports. I will continue to use my    own I/O functions.     - About I/O ports allocation -     The request_region should be done at device probe in every sound card    module. This module is not the best site for requesting regions.    When the request_region code will be added to the main modules such as    sb, adlib, gus, ad1848, etc, the requesting code in this module should    go away.     I think the request regions should be done this way:     if (check_region(...))    return ERR; // I/O region alredy reserved    device_probe(...);    device_attach(...);    request_region(...); // reserve only when we are sure all is okay     Request the 2x0h region in any case if we are using this card.     NOTE: the "(sbpro)" string with which we are requesting the aedsp16 region    (see code) does not mean necessarly that we are emulating sbpro.    It mean that the region is the sbpro I/O ports region. We use this    region to access the control registers of the card, and if emulating    sbpro, I/O sbpro registers too. If we are emulating MSS, the sbpro    registers are not used, in no way, to emulate an sbpro: they are    used only for configuration pourposes.     Someone pointed out that should be possible use both the SBPRO and MSS    modes because the sound card have all the two chipsets, supposing that    the card is really two cards. I have tried something to have the two    modes work together, but, for some reason unknown to me, without success.     I think all the soft-config only cards have an init sequence similar to    this. If you have a card that is not an aedsp16, you can try to start    with this module changing it (mainly in the CMD? I think) to fit your    needs.     Started Fri Mar 17 16:13:18 MET 1995     v0.1 (ALPHA, was an user-level program called AudioExcelDSP16.c)    - Initial code.    v0.2 (ALPHA)    - Cleanups.    - Integrated with Linux voxware v 2.90-2 kernel sound driver.    - SoundBlaster Pro mode configuration.    - Microsoft Sound System mode configuration.    - MPU-401 mode configuration.    v0.3 (ALPHA)    - Cleanups.    - Rearranged the code to let InitAEDSP16 be more general.    - Erased the REALLY_SLOW_IO. We don't need it. Erased the linux/io.h    inclusion too. We rely on os.h    - Used the INB and OUTB #defined in os.h instead of inb and outb.    - Corrected the code for GetCardName (DSP Copyright) to get a variable    len string (we are not sure about the len of Copyright string).    This works with any SB and compatible.    - Added the code to request_region at device init (should go in    the main body of voxware).    v0.4 (BETA)    - Better configure.c patch for aedsp16 configuration (better    logic of inclusion of AEDSP16 support)    - Modified the conditional compilation to better support more than    one sound card of the emulated type (read the NOTES above)    - Moved the sb init routine from the attach to the very first    probe in sb_card.c    - Rearrangemens and cleanups    - Wiped out some unnecessary code and variables: this is kernel    code so it is better save some TEXT and DATA    - Fixed the request_region code. We must allocate the aedsp16 (sbpro)    I/O ports in any case because they are used to access the DSP    configuration registers and we can not allow anyone to get them.    v0.5    - cleanups on comments    - prep for diffs against v3.0-proto-950402   */
end_comment

begin_comment
comment|/*  * Include the main voxware header file. It include all the os/voxware/etc  * headers needed by this source.  */
end_comment

begin_include
include|#
directive|include
file|"sound_config.h"
end_include

begin_comment
comment|/*  * all but ioport.h :)  */
end_comment

begin_include
include|#
directive|include
file|<linux/ioport.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONFIGURE_SOUNDCARD
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXCLUDE_AEDSP16
argument_list|)
end_if

begin_define
define|#
directive|define
name|VERSION
value|"0.5"
end_define

begin_comment
comment|/* Version of Audio Excel DSP 16 driver */
end_comment

begin_undef
undef|#
directive|undef
name|AEDSP16_DEBUG
end_undef

begin_comment
comment|/* Define this to enable debug code     */
end_comment

begin_comment
comment|/* Actually no debug code is activated  */
end_comment

begin_comment
comment|/*  * Hardware related defaults  */
end_comment

begin_define
define|#
directive|define
name|IRQ
value|7
end_define

begin_comment
comment|/* 5 7(default) 9 10 11                 */
end_comment

begin_define
define|#
directive|define
name|MIRQ
value|0
end_define

begin_comment
comment|/* 5 7 9 10 0(default), 0 means disable */
end_comment

begin_define
define|#
directive|define
name|DMA
value|1
end_define

begin_comment
comment|/* 0 1(default) 3                       */
end_comment

begin_comment
comment|/*  * Commands of AEDSP16's DSP (SBPRO+special).  * For now they are CMDn, in the future they may change.  */
end_comment

begin_define
define|#
directive|define
name|CMD1
value|0xe3
end_define

begin_comment
comment|/* Get DSP Copyright                    */
end_comment

begin_define
define|#
directive|define
name|CMD2
value|0xe1
end_define

begin_comment
comment|/* Get DSP Version                      */
end_comment

begin_define
define|#
directive|define
name|CMD3
value|0x88
end_define

begin_comment
comment|/*                                      */
end_comment

begin_define
define|#
directive|define
name|CMD4
value|0x5c
end_define

begin_comment
comment|/*                                      */
end_comment

begin_define
define|#
directive|define
name|CMD5
value|0x50
end_define

begin_comment
comment|/* Set M&I&DRQ mask (the real config)   */
end_comment

begin_define
define|#
directive|define
name|CMD6
value|0x8c
end_define

begin_comment
comment|/* Enable Microsoft Sound System mode   */
end_comment

begin_comment
comment|/*  * Offsets of AEDSP16 DSP I/O ports. The offest is added to portbase  * to have the actual I/O port.  * Register permissions are:  * (wo) == Write Only  * (ro) == Read  Only  * (w-) == Write  * (r-) == Read  */
end_comment

begin_define
define|#
directive|define
name|DSP_RESET
value|0x06
end_define

begin_comment
comment|/* offset of DSP RESET             (wo) */
end_comment

begin_define
define|#
directive|define
name|DSP_READ
value|0x0a
end_define

begin_comment
comment|/* offset of DSP READ              (ro) */
end_comment

begin_define
define|#
directive|define
name|DSP_WRITE
value|0x0c
end_define

begin_comment
comment|/* offset of DSP WRITE             (w-) */
end_comment

begin_define
define|#
directive|define
name|DSP_COMMAND
value|0x0c
end_define

begin_comment
comment|/* offset of DSP COMMAND           (w-) */
end_comment

begin_define
define|#
directive|define
name|DSP_STATUS
value|0x0c
end_define

begin_comment
comment|/* offset of DSP STATUS            (r-) */
end_comment

begin_define
define|#
directive|define
name|DSP_DATAVAIL
value|0x0e
end_define

begin_comment
comment|/* offset of DSP DATA AVAILABLE    (ro) */
end_comment

begin_define
define|#
directive|define
name|RETRY
value|10
end_define

begin_comment
comment|/* Various retry values on I/O opera-   */
end_comment

begin_define
define|#
directive|define
name|STATUSRETRY
value|1000
end_define

begin_comment
comment|/* tions. Sometimes we have to          */
end_comment

begin_define
define|#
directive|define
name|HARDRETRY
value|500000
end_define

begin_comment
comment|/* wait for previous cmd to complete    */
end_comment

begin_comment
comment|/*  * Size of character arrays that store name and version of sound card  */
end_comment

begin_define
define|#
directive|define
name|CARDNAMELEN
value|15
end_define

begin_comment
comment|/* Size of the card's name in chars     */
end_comment

begin_define
define|#
directive|define
name|CARDVERLEN
value|2
end_define

begin_comment
comment|/* Size of the card's version in chars  */
end_comment

begin_comment
comment|/*  * Bit mapped flags for calling InitAEDSP16(), and saving the current  * emulation mode.  */
end_comment

begin_define
define|#
directive|define
name|INIT_NONE
value|(0   )
end_define

begin_define
define|#
directive|define
name|INIT_SBPRO
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|INIT_MSS
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|INIT_MPU401
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RESET_DSP16
value|(1<<3)
end_define

begin_comment
comment|/* Base HW Port for Audio Card          */
end_comment

begin_decl_stmt
specifier|static
name|int
name|portbase
init|=
name|AEDSP16_BASE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|irq
init|=
name|IRQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* irq for DSP I/O                      */
end_comment

begin_decl_stmt
specifier|static
name|int
name|mirq
init|=
name|MIRQ
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* irq for MPU-401 I/O                  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|dma
init|=
name|DMA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dma for DSP I/O                      */
end_comment

begin_comment
comment|/* Init status of the card              */
end_comment

begin_decl_stmt
specifier|static
name|int
name|ae_init
init|=
name|INIT_NONE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* (bitmapped variable)                 */
end_comment

begin_decl_stmt
specifier|static
name|int
name|oredparams
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Will contain or'ed values of params  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|gc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* generic counter (utility counter)    */
end_comment

begin_struct
struct|struct
name|orVals
block|{
comment|/* Contain the values to be or'ed       */
name|int
name|val
decl_stmt|;
comment|/* irq|mirq|dma                         */
name|int
name|or
decl_stmt|;
comment|/* oredparams |= TheStruct.or           */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Magic values that the DSP will eat when configuring irq/mirq/dma  */
end_comment

begin_comment
comment|/* DSP IRQ conversion array             */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|orVals
name|orIRQ
index|[]
init|=
block|{
block|{
literal|0x05
block|,
literal|0x28
block|}
block|,
block|{
literal|0x07
block|,
literal|0x08
block|}
block|,
block|{
literal|0x09
block|,
literal|0x10
block|}
block|,
block|{
literal|0x0a
block|,
literal|0x18
block|}
block|,
block|{
literal|0x0b
block|,
literal|0x20
block|}
block|,
block|{
literal|0x00
block|,
literal|0x00
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* MPU-401 IRQ conversion array         */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|orVals
name|orMIRQ
index|[]
init|=
block|{
block|{
literal|0x05
block|,
literal|0x04
block|}
block|,
block|{
literal|0x07
block|,
literal|0x44
block|}
block|,
block|{
literal|0x09
block|,
literal|0x84
block|}
block|,
block|{
literal|0x0a
block|,
literal|0xc4
block|}
block|,
block|{
literal|0x00
block|,
literal|0x00
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DMA Channels conversion array        */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|orVals
name|orDMA
index|[]
init|=
block|{
block|{
literal|0x00
block|,
literal|0x01
block|}
block|,
block|{
literal|0x01
block|,
literal|0x02
block|}
block|,
block|{
literal|0x03
block|,
literal|0x03
block|}
block|,
block|{
literal|0x00
block|,
literal|0x00
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Buffers to store audio card informations  */
end_comment

begin_decl_stmt
specifier|static
name|char
name|AudioExcelName
index|[
name|CARDNAMELEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
name|AudioExcelVersion
index|[
name|CARDVERLEN
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|tenmillisec
parameter_list|(
name|void
parameter_list|)
block|{
for|for
control|(
name|gc
operator|=
literal|0
init|;
name|gc
operator|<
literal|1000
condition|;
name|gc
operator|++
control|)
name|tenmicrosec
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|WaitForDataAvail
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|int
name|loop
init|=
name|STATUSRETRY
decl_stmt|;
name|unsigned
name|char
name|ret
init|=
literal|0
decl_stmt|;
do|do
block|{
name|ret
operator|=
name|INB
argument_list|(
name|port
operator|+
name|DSP_DATAVAIL
argument_list|)
expr_stmt|;
comment|/*          * Wait for data available (bit 7 of ret == 1)        */
block|}
do|while
condition|(
operator|!
operator|(
name|ret
operator|&
literal|0x80
operator|)
operator|&&
name|loop
operator|--
condition|)
do|;
if|if
condition|(
name|ret
operator|&
literal|0x80
condition|)
return|return
literal|0
return|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ReadData
parameter_list|(
name|int
name|port
parameter_list|)
block|{
if|if
condition|(
name|WaitForDataAvail
argument_list|(
name|port
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|INB
argument_list|(
name|port
operator|+
name|DSP_READ
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|CheckDSPOkay
parameter_list|(
name|int
name|port
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ReadData
argument_list|(
name|port
argument_list|)
operator|==
literal|0xaa
operator|)
condition|?
literal|0
else|:
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|ResetBoard
parameter_list|(
name|int
name|port
parameter_list|)
block|{
comment|/*      * Reset DSP    */
name|OUTB
argument_list|(
literal|1
argument_list|,
operator|(
name|port
operator|+
name|DSP_RESET
operator|)
argument_list|)
expr_stmt|;
name|tenmicrosec
argument_list|()
expr_stmt|;
name|OUTB
argument_list|(
literal|0
argument_list|,
operator|(
name|port
operator|+
name|DSP_RESET
operator|)
argument_list|)
expr_stmt|;
name|tenmicrosec
argument_list|()
expr_stmt|;
name|tenmicrosec
argument_list|()
expr_stmt|;
return|return
name|CheckDSPOkay
argument_list|(
name|port
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|WriteDSPCommand
parameter_list|(
name|int
name|port
parameter_list|,
name|int
name|cmd
parameter_list|)
block|{
name|unsigned
name|char
name|ret
decl_stmt|;
name|int
name|loop
init|=
name|HARDRETRY
decl_stmt|;
do|do
block|{
name|ret
operator|=
name|INB
argument_list|(
name|port
operator|+
name|DSP_STATUS
argument_list|)
expr_stmt|;
comment|/*          * DSP ready to receive data if bit 7 of ret == 0        */
if|if
condition|(
operator|!
operator|(
name|ret
operator|&
literal|0x80
operator|)
condition|)
block|{
name|OUTB
argument_list|(
name|cmd
argument_list|,
name|port
operator|+
name|DSP_COMMAND
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
do|while
condition|(
name|loop
operator|--
condition|)
do|;
name|printk
argument_list|(
literal|"[aedsp16] DSP Command (0x%x) timeout.\n"
argument_list|,
name|cmd
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function

begin_function
name|int
name|InitMSS
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|tenmillisec
argument_list|()
expr_stmt|;
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|port
argument_list|,
name|CMD6
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD6
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|tenmillisec
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|SetUpBoard
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|int
name|loop
init|=
name|RETRY
decl_stmt|;
do|do
block|{
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|CMD3
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD3
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|tenmillisec
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|WaitForDataAvail
argument_list|(
name|port
argument_list|)
operator|&&
name|loop
operator|--
condition|)
do|;
if|#
directive|if
name|defined
argument_list|(
name|THIS_SHOULD_GO_AWAY
argument_list|)
if|if
condition|(
name|CheckDSPOkay
argument_list|(
name|port
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16]     CheckDSPOkay: failed\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
else|#
directive|else
if|if
condition|(
name|ReadData
argument_list|(
name|port
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] ReadData after CMD 0x%x: failed\n"
argument_list|,
name|CMD3
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|CMD4
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD4
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|CMD5
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD5
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|oredparams
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] Initialization of (M)IRQ and DMA: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|GetCardVersion
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|int
name|len
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|int
name|ver
index|[
literal|3
index|]
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
name|ret
operator|=
name|ReadData
argument_list|(
name|port
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
return|return
operator|-
literal|1
return|;
comment|/*          * We alredy know how many int are stored (2), so we know when the          * string is finished.        */
name|ver
index|[
name|len
operator|++
index|]
operator|=
name|ret
expr_stmt|;
block|}
do|while
condition|(
name|len
operator|<
name|CARDVERLEN
condition|)
do|;
name|sprintf
argument_list|(
name|AudioExcelVersion
argument_list|,
literal|"%d.%d"
argument_list|,
name|ver
index|[
literal|0
index|]
argument_list|,
name|ver
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|GetCardName
parameter_list|(
name|int
name|port
parameter_list|)
block|{
name|int
name|len
init|=
literal|0
decl_stmt|;
name|int
name|ret
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
name|ret
operator|=
name|ReadData
argument_list|(
name|port
argument_list|)
operator|)
operator|==
operator|-
literal|1
condition|)
comment|/* 	   * If no more data availabe, return to the caller, no error if len>0. 	   * We have no other way to know when the string is finished. 	 */
return|return
operator|(
name|len
condition|?
literal|0
else|:
operator|-
literal|1
operator|)
return|;
name|AudioExcelName
index|[
name|len
operator|++
index|]
operator|=
name|ret
expr_stmt|;
block|}
do|while
condition|(
name|len
operator|<
name|CARDNAMELEN
condition|)
do|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|InitializeHardParams
parameter_list|(
name|void
parameter_list|)
block|{
name|memset
argument_list|(
name|AudioExcelName
argument_list|,
literal|0
argument_list|,
name|CARDNAMELEN
operator|+
literal|1
argument_list|)
expr_stmt|;
name|memset
argument_list|(
name|AudioExcelVersion
argument_list|,
literal|0
argument_list|,
name|CARDVERLEN
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|gc
operator|=
literal|0
init|;
name|orIRQ
index|[
name|gc
index|]
operator|.
name|or
condition|;
name|gc
operator|++
control|)
if|if
condition|(
name|orIRQ
index|[
name|gc
index|]
operator|.
name|val
operator|==
name|irq
condition|)
name|oredparams
operator||=
name|orIRQ
index|[
name|gc
index|]
operator|.
name|or
expr_stmt|;
for|for
control|(
name|gc
operator|=
literal|0
init|;
name|orMIRQ
index|[
name|gc
index|]
operator|.
name|or
condition|;
name|gc
operator|++
control|)
if|if
condition|(
name|orMIRQ
index|[
name|gc
index|]
operator|.
name|or
operator|==
name|mirq
condition|)
name|oredparams
operator||=
name|orMIRQ
index|[
name|gc
index|]
operator|.
name|or
expr_stmt|;
for|for
control|(
name|gc
operator|=
literal|0
init|;
name|orDMA
index|[
name|gc
index|]
operator|.
name|or
condition|;
name|gc
operator|++
control|)
if|if
condition|(
name|orDMA
index|[
name|gc
index|]
operator|.
name|val
operator|==
name|dma
condition|)
name|oredparams
operator||=
name|orDMA
index|[
name|gc
index|]
operator|.
name|or
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|InitAEDSP16
parameter_list|(
name|int
name|which
parameter_list|)
block|{
specifier|static
name|char
modifier|*
name|InitName
init|=
name|NULL
decl_stmt|;
name|InitializeHardParams
argument_list|()
expr_stmt|;
if|if
condition|(
name|ResetBoard
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] ResetBoard: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|THIS_SHOULD_GO_AWAY
argument_list|)
if|if
condition|(
name|CheckDSPOkay
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CheckDSPOkay: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
endif|#
directive|endif
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|CMD1
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD1
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|GetCardName
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] GetCardName: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/*      * My AEDSP16 card return SC-6000 in AudioExcelName, so      * if we have something different, we have to be warned.    */
if|if
condition|(
name|strcmp
argument_list|(
literal|"SC-6000"
argument_list|,
name|AudioExcelName
argument_list|)
condition|)
name|printk
argument_list|(
literal|"[aedsp16] Warning: non SC-6000 audio card!\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|WriteDSPCommand
argument_list|(
name|portbase
argument_list|,
name|CMD2
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] CMD 0x%x: failed!\n"
argument_list|,
name|CMD2
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|GetCardVersion
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] GetCardVersion: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|SetUpBoard
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] SetUpBoard: failed!\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
if|if
condition|(
name|which
operator|==
name|INIT_MSS
condition|)
block|{
if|if
condition|(
name|InitMSS
argument_list|(
name|portbase
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"[aedsp16] Can't initialize Microsoft Sound System mode.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
comment|/*      * If we are resetting, do not print any message because we may be      * in playing and we do not want lost too much time.    */
if|if
condition|(
operator|!
operator|(
name|which
operator|&
name|RESET_DSP16
operator|)
condition|)
block|{
if|if
condition|(
name|which
operator|&
name|INIT_MPU401
condition|)
name|InitName
operator|=
literal|"MPU401"
expr_stmt|;
elseif|else
if|if
condition|(
name|which
operator|&
name|INIT_SBPRO
condition|)
name|InitName
operator|=
literal|"SBPro"
expr_stmt|;
elseif|else
if|if
condition|(
name|which
operator|&
name|INIT_MSS
condition|)
name|InitName
operator|=
literal|"MSS"
expr_stmt|;
else|else
name|InitName
operator|=
literal|"None"
expr_stmt|;
name|printk
argument_list|(
literal|"Audio Excel DSP 16 init v%s (%s %s) [%s]\n"
argument_list|,
name|VERSION
argument_list|,
name|AudioExcelName
argument_list|,
name|AudioExcelVersion
argument_list|,
name|InitName
argument_list|)
expr_stmt|;
block|}
name|tenmillisec
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AEDSP16_SBPRO
argument_list|)
end_if

begin_function
name|int
name|InitAEDSP16_SBPRO
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
comment|/*      * If the card is alredy init'ed MSS, we can not init it to SBPRO too      * because the board can not emulate simultaneously MSS and SBPRO.    */
if|if
condition|(
name|ae_init
operator|&
name|INIT_MSS
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|ae_init
operator|&
name|INIT_SBPRO
condition|)
return|return
literal|0
return|;
comment|/*      * For now we will leave this      * code included only when INCLUDE_AEDSP16 is configured in, but it should      * be better include it every time.    */
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
name|INIT_MPU401
operator|)
condition|)
block|{
if|if
condition|(
name|check_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x0f
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"AEDSP16/SBPRO I/O port region is alredy in use.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
comment|/*      * Set up the internal hardware parameters, to let the driver reach      * the Sound Card.    */
name|portbase
operator|=
name|hw_config
operator|->
name|io_base
expr_stmt|;
name|irq
operator|=
name|hw_config
operator|->
name|irq
expr_stmt|;
name|dma
operator|=
name|hw_config
operator|->
name|dma
expr_stmt|;
if|if
condition|(
name|InitAEDSP16
argument_list|(
name|INIT_SBPRO
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
name|INIT_MPU401
operator|)
condition|)
name|request_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x0f
argument_list|,
literal|"aedsp16 (sbpro)"
argument_list|)
expr_stmt|;
name|ae_init
operator||=
name|INIT_SBPRO
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AEDSP16_SBPRO */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AEDSP16_MSS
argument_list|)
end_if

begin_function
name|int
name|InitAEDSP16_MSS
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
comment|/*      * If the card is alredy init'ed SBPRO, we can not init it to MSS too      * because the board can not emulate simultaneously MSS and SBPRO.    */
if|if
condition|(
name|ae_init
operator|&
name|INIT_SBPRO
condition|)
return|return
operator|-
literal|1
return|;
if|if
condition|(
name|ae_init
operator|&
name|INIT_MSS
condition|)
return|return
literal|0
return|;
comment|/*      * For now we will leave this      * code included only when INCLUDE_AEDSP16 is configured in, but it should      * be better include it every time.    */
if|if
condition|(
name|check_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x08
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"MSS I/O port region is alredy in use.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/*      * We must allocate the AEDSP16 region too because these are the I/O ports      * to access card's control registers.    */
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
name|INIT_MPU401
operator|)
condition|)
block|{
if|if
condition|(
name|check_region
argument_list|(
name|AEDSP16_BASE
argument_list|,
literal|0x0f
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"AEDSP16 I/O port region is alredy in use.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
comment|/*      * If we are configuring the card for MSS, the portbase for card configuration      * is the default one (0x220 unless you have changed the factory default      * with board switches), so no need to modify the portbase variable.      * The default is AEDSP16_BASE, that is the right value.    */
name|irq
operator|=
name|hw_config
operator|->
name|irq
expr_stmt|;
name|dma
operator|=
name|hw_config
operator|->
name|dma
expr_stmt|;
if|if
condition|(
name|InitAEDSP16
argument_list|(
name|INIT_MSS
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|request_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x08
argument_list|,
literal|"aedsp16 (mss)"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
name|INIT_MPU401
operator|)
condition|)
name|request_region
argument_list|(
name|AEDSP16_BASE
argument_list|,
literal|0x0f
argument_list|,
literal|"aedsp16 (sbpro)"
argument_list|)
expr_stmt|;
name|ae_init
operator||=
name|INIT_MSS
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AEDSP16_MSS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AEDSP16_MPU401
argument_list|)
end_if

begin_function
name|int
name|InitAEDSP16_MPU401
parameter_list|(
name|struct
name|address_info
modifier|*
name|hw_config
parameter_list|)
block|{
if|if
condition|(
name|ae_init
operator|&
name|INIT_MPU401
condition|)
return|return
literal|0
return|;
comment|/*      * For now we will leave this      * code included only when INCLUDE_AEDSP16 is configured in, but it should      * be better include it every time.    */
if|if
condition|(
name|check_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x02
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"SB I/O port region is alredy in use.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
comment|/*      * We must allocate the AEDSP16 region too because these are the I/O ports      * to access card's control registers.    */
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
operator|(
name|INIT_MSS
operator||
name|INIT_SBPRO
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|check_region
argument_list|(
name|AEDSP16_BASE
argument_list|,
literal|0x0f
argument_list|)
condition|)
block|{
name|printk
argument_list|(
literal|"AEDSP16 I/O port region is alredy in use.\n"
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
block|}
comment|/*      * If mpu401, the irq and dma are not important, do not touch it      * because we may use the default if sbpro is not yet configured,      * we may use the sbpro ones if configured, and nothing wrong      * should happen.      *      * The mirq default is 0, but once set it to non-0 value, we should      * not touch it anymore (unless I write an ioctl to do it, of course).    */
name|mirq
operator|=
name|hw_config
operator|->
name|irq
expr_stmt|;
if|if
condition|(
name|InitAEDSP16
argument_list|(
name|INIT_MPU401
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|request_region
argument_list|(
name|hw_config
operator|->
name|io_base
argument_list|,
literal|0x02
argument_list|,
literal|"aedsp16 (mpu401)"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|ae_init
operator|&
operator|(
name|INIT_MSS
operator||
name|INIT_SBPRO
operator|)
operator|)
condition|)
name|request_region
argument_list|(
name|AEDSP16_BASE
argument_list|,
literal|0x0f
argument_list|,
literal|"aedsp16 (sbpro)"
argument_list|)
expr_stmt|;
name|ae_init
operator||=
name|INIT_MPU401
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AEDSP16_MPU401 */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Leave it out for now. We are not using this portion of code. */
end_comment

begin_comment
comment|/*  * Entry point for a reset function.  * May be I will write the infamous ioctl :)  */
end_comment

begin_if
unit|int ResetAEDSP16 (void) {
if|#
directive|if
name|defined
argument_list|(
name|AEDSP16_DEBUG
argument_list|)
end_if

begin_endif
unit|printk ("[aedsp16] ResetAEDSP16 called.\n");
endif|#
directive|endif
end_endif

begin_endif
unit|return InitAEDSP16 (RESET_DSP16); }
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !EXCLUDE_AEDSP16 */
end_comment

end_unit

