begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************/
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*       ________________________________________________________        */
end_comment

begin_comment
comment|/*      /                                                        \       */
end_comment

begin_comment
comment|/*     |          AAA          CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*     |         AAAAA        CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     |        AAAAAAA       CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |       AAAA AAAA      CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |      AAAA   AAAA     CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |     AAAA     AAAA    CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |    AAAA       AAAA   CCCC              CCCC              |      */
end_comment

begin_comment
comment|/*     |   AAAA  AAAAAAAAAAA  CCCCCCCCCCCCCCCCC CCCCCCCCCCCCCCCCC |      */
end_comment

begin_comment
comment|/*     |  AAAA    AAAAAAAAAAA CCCCCCCCCCCCCCCC  CCCCCCCCCCCCCCCC  |      */
end_comment

begin_comment
comment|/*     | AAAA      AAAAAAAAA   CCCCCCCCCCCCCC    CCCCCCCCCCCCCC   |      */
end_comment

begin_comment
comment|/*      \________________________________________________________/       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  	Copyright (c) 1986 by Advanced Computer Communications           */
end_comment

begin_comment
comment|/*  	720 Santa Barbara Street, Santa Barbara, California  93101       */
end_comment

begin_comment
comment|/*  	(805) 963-9431                                                   */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  File:		if_dda_uqbus.c                                   */
end_comment

begin_comment
comment|/*			Unibus& Q22bus support routines for dda	 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		DDN-X.25 Network Interface Driver for ACP 5250   */
end_comment

begin_comment
comment|/*			and ACP 6250                                     */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  revision history at the end of if_dda.c				 */
end_comment

begin_comment
comment|/*************************************************************************/
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|SIMULATION
end_ifndef

begin_include
include|#
directive|include
file|"../vaxif/if_uba.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubavar.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"vaxif/if_uba.h"
end_include

begin_include
include|#
directive|include
file|"vaxuba/ubareg.h"
end_include

begin_include
include|#
directive|include
file|"vaxuba/ubavar.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PRIVATE
name|u_short
name|ddastd
index|[]
init|=
block|{
literal|0767000
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* standard addresses */
end_comment

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ddainfo
index|[
name|NDDA
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ptrs to device info */
end_comment

begin_decl_stmt
name|struct
name|uba_driver
name|ddadriver
init|=
comment|/* device driver info */
block|{
name|ddaprobe
block|,
comment|/* device probe routine */
literal|0
block|,
comment|/* slave probe routine */
name|ddaattach
block|,
comment|/* device attach routine */
literal|0
block|,
comment|/* "dmago" routine */
name|ddastd
block|,
comment|/* device address */
literal|"dda"
block|,
comment|/* device name */
name|ddainfo
comment|/* ptr to device info ptrs */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* figure out if this machine is a QBUS machine */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MVAX
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX3400
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX3600
argument_list|)
operator|||
name|defined
argument_list|(
name|DS5400
argument_list|)
end_if

begin_define
define|#
directive|define
name|QBUS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following definitions declare the structure of the UNIBUS/QBUS  * mapped pages (which are 512 bytes long).  In previous versions we  * assumed that the bus pages were the same size as the memory pages,  * but the mips PMAX cpu uses 4k memory pages but 512 byte bus pages.  */
end_comment

begin_define
define|#
directive|define
name|BUS_NBPG
value|512
end_define

begin_comment
comment|/* bytes/unibus mapped page */
end_comment

begin_define
define|#
directive|define
name|BUS_PGOFSET
value|(BUS_NBPG-1)
end_define

begin_comment
comment|/* offset into bus page */
end_comment

begin_define
define|#
directive|define
name|BUS_PGSHIFT
value|9
end_define

begin_comment
comment|/* number of bits to shift for page */
end_comment

begin_comment
comment|/*  * If we're not running on a PMAX cpu, we don't need to do write buffer  * pipeline flushes nor do we need to declare I/O space pointers to  * be volatile.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|mips
end_ifndef

begin_define
define|#
directive|define
name|wbflush
parameter_list|()
end_define

begin_define
define|#
directive|define
name|volatile
value|register
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAPROBE()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/* Purpose:                                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  This routine probes the device to obtain the UNIBUS interrupt  */
end_comment

begin_comment
comment|/*  vector.  Since the ACP is a soft vector device, we obtain an   */
end_comment

begin_comment
comment|/*  unused vector from the uba structure and return that.  The ACP */
end_comment

begin_comment
comment|/*  is given the vector and the board is reset.  In order to save  */
end_comment

begin_comment
comment|/*  the vector in the device info structure, we place it in a      */
end_comment

begin_comment
comment|/*  static temporary where the attach routine can find it and save */
end_comment

begin_comment
comment|/*  it in the device info structure.  This is necessary because    */
end_comment

begin_comment
comment|/*  probe only provides a pointer to the device and we have no     */
end_comment

begin_comment
comment|/*  idea which unit is being referenced.  This works in 4.2BSD     */
end_comment

begin_comment
comment|/*  because the attach routine is called immediately after a       */
end_comment

begin_comment
comment|/*  successful probe.                                              */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          ddaprobe(reg, ui)                               */
end_comment

begin_comment
comment|/*  Argument:      reg:  caddr_t address in virtual memory of the  */
end_comment

begin_comment
comment|/*                        control-status register                  */
end_comment

begin_comment
comment|/*                 ui:   pointer to device data structure, used    */
end_comment

begin_comment
comment|/*                       for TWG environment                       */
end_comment

begin_comment
comment|/*  Returns:       length of register structure for ACP device     */
end_comment

begin_comment
comment|/*  Called by:     network software, part of autoconfiguration on  */
end_comment

begin_comment
comment|/*                 the VAX, the address of this routine is one of  */
end_comment

begin_comment
comment|/*                 the fields of the uba_driver structure          */
end_comment

begin_comment
comment|/*  Calls to:      none                                            */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_decl_stmt
specifier|static
name|int
name|savevec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* static variable for vector */
end_comment

begin_decl_stmt
specifier|static
name|int
name|savefirmrev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* firmware rev has same problem as vector */
end_comment

begin_macro
name|ddaprobe
argument_list|(
argument|reg
argument_list|,
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|caddr_t
name|reg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TWG VAX/VMS ONLY! */
end_comment

begin_block
block|{
comment|/* In 2.0 ULTRIX and newer, br and cvec are global (ubavar.h) */
comment|/* while multinet needs them external */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MULTINET
argument_list|)
operator|&&
name|ACC_ULTRIX
operator|<
literal|20
specifier|register
name|int
name|br
decl_stmt|,
name|cvec
decl_stmt|;
comment|/* r11, r10 value-result */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MULTINET
specifier|extern
name|int
name|br
decl_stmt|,
name|cvec
decl_stmt|;
comment|/* must define external */
endif|#
directive|endif
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|reg
decl_stmt|;
ifdef|#
directive|ifdef
name|lint
name|br
operator|=
literal|0
expr_stmt|;
name|cvec
operator|=
name|br
expr_stmt|;
name|br
operator|=
name|cvec
expr_stmt|;
if|#
directive|if
name|ACC_VMS
operator|==
literal|00
name|ui
operator|=
name|ui
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
name|cvec
operator|=
name|savevec
operator|=
name|ui
operator|->
name|ui_flags
operator|&
literal|0x1f8
expr_stmt|;
comment|/* flags from config file */
else|#
directive|else
name|cvec
operator|=
name|savevec
operator|=
operator|(
operator|(
name|uba_hd
index|[
name|numuba
index|]
operator|.
name|uh_lastiv
operator|-
literal|8
operator|)
operator|&
operator|~
literal|7
operator|)
expr_stmt|;
name|uba_hd
index|[
name|numuba
index|]
operator|.
name|uh_lastiv
operator|=
name|cvec
expr_stmt|;
endif|#
directive|endif
comment|/* return a vector aligned on a */
comment|/* QUADWORD boundary */
comment|/* cvec is the interrupt vector */
comment|/* address on the UNIBUS */
ifdef|#
directive|ifdef
name|QBUS
name|br
operator|=
literal|0x17
expr_stmt|;
comment|/* bus level for MicroVAX */
else|#
directive|else
name|br
operator|=
literal|0x15
expr_stmt|;
comment|/* bus level for VAX */
endif|#
directive|endif
comment|/* check that the device is really a 5250/6250 and save away */
comment|/* the firmware revision level for version dependent processing */
comment|/* If we just booted, the diagnostics may still be running as we */
comment|/* probe the device - it's still OK to read the ID and VERSION */
comment|/* numbers, which come valid within milliseconds after power is */
comment|/* applied to the board - so say the firmware gurus */
name|dda_hasmaint
operator|=
operator|!
operator|(
name|addr
operator|->
name|csr
operator|&
name|CSR_MAINT
operator|)
expr_stmt|;
name|savefirmrev
operator|=
name|addr
operator|->
name|sys_vers
expr_stmt|;
switch|switch
condition|(
name|addr
operator|->
name|sys_id
condition|)
block|{
case|case
literal|0x8
case|:
name|dda_product
operator|=
literal|"ACP6250"
expr_stmt|;
break|break;
case|case
literal|0x28
case|:
name|dda_product
operator|=
literal|"ACP5250"
expr_stmt|;
break|break;
case|case
literal|0x2C
case|:
name|dda_product
operator|=
literal|"ACP5250-W"
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|!
name|dda_hasmaint
condition|)
return|return
literal|0
return|;
name|savefirmrev
operator|=
literal|0xff
expr_stmt|;
name|dda_product
operator|=
literal|"ACPx250"
expr_stmt|;
break|break;
block|}
comment|/* clear communications registers */
name|addr
operator|->
name|req_flags
operator|=
literal|0
expr_stmt|;
comment|/* I/O request flags            */
name|addr
operator|->
name|cmp_flags
operator|=
literal|0
expr_stmt|;
comment|/* I/O completion flags         */
name|addr
operator|->
name|xfr_flags
operator|=
literal|0
expr_stmt|;
comment|/* transfer request/grant flags */
name|addr
operator|->
name|req_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|req_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|req_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|req_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|req_fcn
operator|=
literal|0
expr_stmt|;
comment|/* I/O function                 */
name|addr
operator|->
name|req_sbf
operator|=
literal|0
expr_stmt|;
comment|/* I/O subfunction              */
name|addr
operator|->
name|cmp_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|cmp_unused
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|cmp_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|cmp_stat
operator|=
literal|0
expr_stmt|;
comment|/* I/O status                   */
name|addr
operator|->
name|cmp_sbst
operator|=
literal|0
expr_stmt|;
comment|/* I/O substatus                */
name|addr
operator|->
name|xfr_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|xfr_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|xfr_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|xfr_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|sys_stat
operator|=
literal|0
expr_stmt|;
comment|/* system status                */
name|addr
operator|->
name|sys_vect
operator|=
name|cvec
operator|>>
literal|2
expr_stmt|;
comment|/* pass interrupt vector to ACP */
name|addr
operator|->
name|csr
operator|=
name|CSR_RESET
expr_stmt|;
comment|/* reset the board */
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
comment|/* enable status intr */
return|return
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|ddaregs
argument_list|)
operator|)
return|;
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAATTACH()                            %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  This routine attaches the device to the network software.  The */
end_comment

begin_comment
comment|/*  network interface structure is filled in.  The device will be  */
end_comment

begin_comment
comment|/*  initialized when the system is ready to accept packets.  The   */
end_comment

begin_comment
comment|/*  dda_init initialization/service flag is zeroed, DDN standard   */
end_comment

begin_comment
comment|/*  X.25 service is implemented by default unless otherwise        */
end_comment

begin_comment
comment|/*  specified by the user via the acpconfig program.               */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:           ddaattach(ui)                                  */
end_comment

begin_comment
comment|/*  Argument:       ui:  ptr to the uba_device data structure      */
end_comment

begin_comment
comment|/*  Returns:        nothing                                        */
end_comment

begin_comment
comment|/*  Called by:      network software, part of network system       */
end_comment

begin_comment
comment|/*                  configuration, identification to the network   */
end_comment

begin_comment
comment|/*                  software,  the address of this routine is one  */
end_comment

begin_comment
comment|/*                  of the fields of the uba_driver structure      */
end_comment

begin_comment
comment|/*  Calls to:       if_attach()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|ddaattach
argument_list|(
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|ui
operator|->
name|ui_unit
index|]
decl_stmt|;
specifier|static
name|long
name|initmsgs
index|[]
init|=
block|{
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|1
block|,
operator|-
literal|2
block|}
decl_stmt|;
name|ds
operator|->
name|dda_init
operator|=
name|DDA_STANDARD
expr_stmt|;
comment|/* init/service flag<- default  */
name|ds
operator|->
name|dda_vector
operator|=
name|savevec
expr_stmt|;
comment|/* save vector from probe() */
name|ds
operator|->
name|dda_firmrev
operator|=
name|savefirmrev
expr_stmt|;
comment|/* save firmware rev level */
name|ds
operator|->
name|dda_net_id
operator|=
literal|0
expr_stmt|;
comment|/* default */
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|=
name|ui
operator|->
name|ui_unit
expr_stmt|;
comment|/* set unit number */
name|ds
operator|->
name|dda_if
operator|.
name|if_name
operator|=
literal|"dda"
expr_stmt|;
comment|/* set device name */
name|ds
operator|->
name|dda_if
operator|.
name|if_mtu
operator|=
name|DDAMTU
expr_stmt|;
comment|/* set max msg size */
name|ds
operator|->
name|dda_if
operator|.
name|if_init
operator|=
name|ddainit
expr_stmt|;
comment|/* set init routine addr */
name|ds
operator|->
name|dda_if
operator|.
name|if_ioctl
operator|=
name|ddaioctl
expr_stmt|;
comment|/* set ioctl routine addr */
name|ds
operator|->
name|dda_if
operator|.
name|if_output
operator|=
name|ddaoutput
expr_stmt|;
comment|/* set output routine addr */
name|ds
operator|->
name|dda_if
operator|.
name|if_reset
operator|=
name|ddareset
expr_stmt|;
comment|/* set reset routine addr */
name|ds
operator|->
name|dda_if
operator|.
name|if_watchdog
operator|=
name|ddatimer
expr_stmt|;
comment|/* set timer routine addr */
name|bcopy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|initmsgs
argument_list|,
operator|(
name|char
operator|*
operator|)
name|ddamsgs
index|[
name|ui
operator|->
name|ui_unit
index|]
argument_list|,
sizeof|sizeof
argument_list|(
name|initmsgs
argument_list|)
argument_list|)
expr_stmt|;
name|if_attach
argument_list|(
operator|&
name|ds
operator|->
name|dda_if
argument_list|)
expr_stmt|;
comment|/* attach new network device */
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDARESET()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*      Reset of interface after UNIBUS reset.  If interface is on */
end_comment

begin_comment
comment|/*      specified uba, reset its state.  Free mbufs if there is    */
end_comment

begin_comment
comment|/*      queued output data.                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              ddareset(unit, uban)                        */
end_comment

begin_comment
comment|/*  Arguments:         unit:   ACP device unit number              */
end_comment

begin_comment
comment|/*		       uban:   Unibus Adapter # (do not use!)	   */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         network software, address of routine is     */
end_comment

begin_comment
comment|/*                     defined in dda_if network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                     IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  NOTE: the uban parameter is NOT USED, and may be garbage under */
end_comment

begin_comment
comment|/*	  some circumnstances.  It is there because the kerenel    */
end_comment

begin_comment
comment|/*	  expects to pass two parameters to ddareset()		   */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|ddareset
argument_list|(
argument|unit
argument_list|,
argument|uban
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|,
name|uban
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NDDA
operator|||
operator|(
name|ui
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_alive
operator|==
literal|0
operator|)
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: ddareset: invalid unit\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: reset\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
name|hist_link_state
argument_list|(
name|unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
name|addr
operator|->
name|cmp_flags
operator|=
literal|0
expr_stmt|;
comment|/* I/O completion flags         */
name|addr
operator|->
name|xfr_flags
operator|=
literal|0
expr_stmt|;
comment|/* transfer request/grant flags */
name|addr
operator|->
name|req_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|req_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|req_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|req_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|req_fcn
operator|=
literal|0
expr_stmt|;
comment|/* I/O function                 */
name|addr
operator|->
name|req_sbf
operator|=
literal|0
expr_stmt|;
comment|/* I/O subfunction              */
name|addr
operator|->
name|cmp_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|cmp_unused
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|cmp_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|cmp_stat
operator|=
literal|0
expr_stmt|;
comment|/* I/O status                   */
name|addr
operator|->
name|cmp_sbst
operator|=
literal|0
expr_stmt|;
comment|/* I/O substatus                */
name|addr
operator|->
name|xfr_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|xfr_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|xfr_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|xfr_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|sys_stat
operator|=
literal|0
expr_stmt|;
comment|/* system status                */
name|addr
operator|->
name|req_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear handshake flags, mailbox     */
comment|/* pass interrupt vector to ACP */
name|addr
operator|->
name|sys_vect
operator|=
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_vector
operator|>>
literal|2
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
name|CSR_RESET
expr_stmt|;
comment|/* reset the board                    */
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear ACP operational flag  */
name|ds
operator|->
name|dda_init
operator|&=
operator|~
name|DDA_INTCLOCK
expr_stmt|;
comment|/* reset internal-clocking-set bit */
name|nddach
index|[
name|unit
index|]
operator|=
name|NDDACH_DEFAULT
expr_stmt|;
comment|/* reset SVC limit */
name|dc
operator|=
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_cb
expr_stmt|;
comment|/* flush any queued output data */
comment|/* LCNLINK */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|NDDACH
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's ... */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* clear remote internet addr */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* must save for x29 */
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
comment|/* init LCN state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn LCN timer off */
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
name|dc
operator|->
name|dc_out_t
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn FE completion timer off */
endif|#
directive|endif
name|dc
operator|++
expr_stmt|;
block|}
name|hist_all_lcns
argument_list|(
name|unit
argument_list|,
name|LC_IDLE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_RAWOPT
name|pi_init
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_PADOPT
name|x29_init
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
name|wbflush
argument_list|()
expr_stmt|;
comment|/* flush write cache pipeline */
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAINIT()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    This routine initializes the interface for operation.  The   */
end_comment

begin_comment
comment|/*    device control blocks are initialized, UNIBUS resources are  */
end_comment

begin_comment
comment|/*    allocated and an initialization message is sent to the ACP.  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    Note that interrupt "b" is enabled here to avoid a possible  */
end_comment

begin_comment
comment|/*    race condition at power up time - it was previously done in  */
end_comment

begin_comment
comment|/*    the probe and reset routines.                                */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:             ddainit(unit)                                */
end_comment

begin_comment
comment|/*  Argument:         unit:  ACP device unit number                */
end_comment

begin_comment
comment|/*  Returns:          nothing                                      */
end_comment

begin_comment
comment|/*  Called by:        network software, address of this routine is */
end_comment

begin_comment
comment|/*                    defined in dda_if network interface struct   */
end_comment

begin_comment
comment|/*                    ddaioctl()                                   */
end_comment

begin_comment
comment|/*                    ddaintb()                                    */
end_comment

begin_comment
comment|/*  Calls to:         in_netof() return the network number from    */
end_comment

begin_comment
comment|/*                               internet address                  */
end_comment

begin_comment
comment|/*                    spl6()                                       */
end_comment

begin_comment
comment|/*                    uballoc()                                    */
end_comment

begin_comment
comment|/*                    ddatimer()                                   */
end_comment

begin_comment
comment|/*                    btoc()                                       */
end_comment

begin_comment
comment|/*                    splimp()                                     */
end_comment

begin_comment
comment|/*                    dda_rrq()                                    */
end_comment

begin_comment
comment|/*                    splx()                                       */
end_comment

begin_comment
comment|/*                    if_rtinit()                                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|ddainit
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|struct
name|sockaddr_in
modifier|*
name|sin
decl_stmt|;
endif|#
directive|endif
name|int
name|lcn
decl_stmt|,
name|s
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|0
argument_list|,
name|unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddainit()\n"
operator|,
name|unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/* if we have no internet addr  if device not operational don't init yet */
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|sin
operator|=
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
operator|&
name|ds
operator|->
name|dda_if
operator|.
name|if_addr
expr_stmt|;
if|if
condition|(
operator|(
name|in_netof
argument_list|(
name|sin
operator|->
name|sin_addr
argument_list|)
operator|==
literal|0
operator|)
operator|||
operator|(
operator|(
name|ds
operator|->
name|dda_flags
operator|&
name|DDAF_OK
operator|)
operator|==
literal|0
operator|)
condition|)
else|#
directive|else
if|if
condition|(
name|ds
operator|->
name|dda_if
operator|.
name|if_addrlist
operator|==
operator|(
expr|struct
name|ifaddr
operator|*
operator|)
literal|0
operator|||
operator|(
operator|(
name|ds
operator|->
name|dda_flags
operator|&
name|DDAF_OK
operator|)
operator|==
literal|0
operator|)
condition|)
endif|#
directive|endif
return|return;
comment|/* enable intrpt "b" */
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
if|if
condition|(
operator|(
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&
name|IFF_RUNNING
operator|)
operator|==
literal|0
condition|)
block|{
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
comment|/* setup ptr to first LCN cntl block */
comment|/* LCNLINK */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|NDDACH
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's ... */
name|dc
operator|->
name|dc_lcn
operator|=
name|lcn
expr_stmt|;
comment|/* record LCN */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* clear remote internet addr */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_DOWN
expr_stmt|;
comment|/* init LCN state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn LCN timer off */
ifdef|#
directive|ifdef
name|DDADEBUG
name|dc
operator|->
name|dc_out_t
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn FE completion timer off */
endif|#
directive|endif
comment|/* init LCN output queue */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_head
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_tail
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_maxlen
operator|=
name|DDA_OQMAX
expr_stmt|;
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_drops
operator|=
literal|0
expr_stmt|;
comment|/* init HDX channels */
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_next
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_chan
operator|=
name|lcn
operator|*
literal|2
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_next
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_chan
operator|=
operator|(
name|lcn
operator|*
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_mbuf
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_rchan
operator|.
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_mbuf
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wchan
operator|.
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
comment|/* initialize flags */
name|dc
operator|++
expr_stmt|;
comment|/* point at next cntl blk */
block|}
name|hist_all_lcns
argument_list|(
name|unit
argument_list|,
name|LC_DOWN
argument_list|)
expr_stmt|;
comment|/* allocate UNIBUS mapping registers, uballoc() */
comment|/* returns ubinfo, CLBYTES = (CLSIZE * NBPG)    */
comment|/* rev 2.0 and above: we are now attempting to handle interrupt */
comment|/* B by resetting the board and bringing it back on line.  So   */
comment|/* have to deal with the possibility that we already did this.  */
comment|/* It's more serious to let mapping registers "leak" than mbufs */
comment|/* (see above) and it's easy to handle too so THIS we do check. */
ifndef|#
directive|ifndef
name|MULTINET
name|s
operator|=
name|spl6
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ds
operator|->
name|dda_mapreg
operator|==
literal|0
condition|)
comment|/* don't have one yet, allocate */
name|ds
operator|->
name|dda_mapreg
operator|=
name|uballoc
argument_list|(
name|ui
operator|->
name|ui_ubanum
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|dda_softc
index|[
name|unit
index|]
argument_list|,
name|CLBYTES
argument_list|,
literal|0
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|MULTINET
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ds
operator|->
name|dda_mapreg
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: failed getting UBA resources for lcn %d\n"
operator|,
name|unit
operator|,
name|lcn
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
operator|(
name|IFF_RUNNING
operator||
name|IFF_UP
operator|)
expr_stmt|;
name|hist_link_state
argument_list|(
name|unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
return|return;
block|}
comment|/* leave the UNIBUS mapping register */
ifdef|#
directive|ifdef
name|UBAI_MR
comment|/* if the macro exists, use it, because it's always right */
name|ds
operator|->
name|dda_mapreg
operator|=
name|UBAI_MR
argument_list|(
name|ds
operator|->
name|dda_mapreg
argument_list|)
expr_stmt|;
else|#
directive|else
name|ds
operator|->
name|dda_mapreg
operator|=
operator|(
name|ds
operator|->
name|dda_mapreg
operator|>>
name|BUS_PGSHIFT
operator|)
operator|&
name|BUS_PGOFSET
expr_stmt|;
endif|#
directive|endif
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
literal|0
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator||=
name|IFF_RUNNING
expr_stmt|;
block|}
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|dc
operator|=
name|ds
operator|->
name|dda_cb
expr_stmt|;
comment|/* setup ptr to first LCN cntl block */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|nddach
index|[
name|unit
index|]
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* issue reads on all LCNs */
name|dda_rrq
argument_list|(
name|ds
argument_list|,
operator|&
operator|(
name|dc
operator|->
name|dc_rchan
operator|)
argument_list|)
expr_stmt|;
name|dc
operator|++
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|ddatimer
argument_list|(
name|unit
argument_list|)
expr_stmt|;
comment|/* start timers */
if|#
directive|if
name|ACC_BSD
operator|==
literal|42
operator|||
name|ACC_ULTRIX
operator|==
literal|12
name|if_rtinit
argument_list|(
operator|&
name|ds
operator|->
name|dda_if
argument_list|,
name|RTF_UP
argument_list|)
expr_stmt|;
comment|/* initialize the routing table */
comment|/* for network, give address of ifnet structure and RTF_UP   */
comment|/* which means route is useable */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_RAWOPT
name|pi_init
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* initialize progammer interface */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_PADOPT
name|x29_init
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAINTA()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    This is the interrupt handler for I/O interrupts (interrupt  */
end_comment

begin_comment
comment|/*    "a") from the ACP device.  The I/O mailboxes are scanned for */
end_comment

begin_comment
comment|/*    handshake events to process. Three types of interrupts are   */
end_comment

begin_comment
comment|/*    processed:  Transfer Request, I/O request acknowledge, and   */
end_comment

begin_comment
comment|/*    I/O completion.  The interrupting HDX channel and interrupt  */
end_comment

begin_comment
comment|/*    type are obtained.  If the interrupt is Transfer Request,    */
end_comment

begin_comment
comment|/*    quit if there is no data, otherwise supply values for the    */
end_comment

begin_comment
comment|/*    Transfer Request Mailbox.  Note the mapping of the system    */
end_comment

begin_comment
comment|/*    page table entry, pte, and the UNIBUS Mapping Register,      */
end_comment

begin_comment
comment|/*    ddamapreg.  The mapping algorithm is different for the TWG   */
end_comment

begin_comment
comment|/*    Eunice/IPTCP environments because Sysmap is not present as   */
end_comment

begin_comment
comment|/*    it is in UNIX 4.2 BSD.  If interrupt is an I/O request       */
end_comment

begin_comment
comment|/*    acknowledge the next I/O request is passed to the ACP        */
end_comment

begin_comment
comment|/*    device.  If the interrupt is an I/O completion, check for    */
end_comment

begin_comment
comment|/*    errors, if ok process according to whether supervisory or    */
end_comment

begin_comment
comment|/*    data channel.                                                */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              ddainta(unit)                               */
end_comment

begin_comment
comment|/*  Arguments:         unit:  ACP device unit number               */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         network software, address of this routine   */
end_comment

begin_comment
comment|/*                     is defined in af_inet network interface     */
end_comment

begin_comment
comment|/*                     data structure                              */
end_comment

begin_comment
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                     btop() - byte to page w/o rounding (>> 9 ) */
end_comment

begin_comment
comment|/*                     btoc()                                      */
end_comment

begin_comment
comment|/*                     start_chn()                                 */
end_comment

begin_comment
comment|/*                     dda_data()                                  */
end_comment

begin_comment
comment|/*                     dda_supr()                                  */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WINS
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pte
modifier|*
name|mmg$gl_sptbase
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* base of system page table */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ADP
modifier|*
name|ioc$gl_adplist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Adapter control blocks */
end_comment

begin_endif
endif|#
directive|endif
endif|WINS
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MULTINET
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|pte
modifier|*
name|vms_sptbase
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|mmg$gl_sptbase
value|vms_sptbase
end_define

begin_endif
endif|#
directive|endif
endif|MULTINET
end_endif

begin_macro
name|ddainta
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
init|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
operator|->
name|ui_addr
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|uba_hd
modifier|*
name|uh
init|=
operator|&
name|uba_hd
index|[
name|ddainfo
index|[
name|unit
index|]
operator|->
name|ui_ubanum
index|]
decl_stmt|;
name|struct
name|pte
modifier|*
name|pte
decl_stmt|;
comment|/* page table entry pointers */
name|int
name|chan
decl_stmt|,
name|cc
decl_stmt|,
name|subcc
decl_stmt|,
name|cnt
decl_stmt|,
name|npf
decl_stmt|,
name|uadr
decl_stmt|,
name|pgoff
decl_stmt|;
specifier|register
name|int
name|page_to_map
decl_stmt|;
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
name|int
name|temp
decl_stmt|;
specifier|register
name|struct
name|ADP
modifier|*
name|adp
decl_stmt|;
comment|/* TWG or TGV, UNIBUS adapter */
name|int
modifier|*
name|io
decl_stmt|;
else|#
directive|else
name|struct
name|pte
modifier|*
name|io
decl_stmt|;
comment|/* page table entry pointers */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|5
argument_list|,
name|unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddainta()\n"
operator|,
name|unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
comment|/***********************************************************************/
comment|/*   Check Transfer Request Mailbox  (note VAXVMS dependent code)      */
comment|/***********************************************************************/
if|if
condition|(
name|addr
operator|->
name|xfr_flags
operator|&
name|FLAGS_RDY
condition|)
block|{
comment|/* Transfer Request Mailbox */
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(tx)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Get logical channel information.  	 */
if|if
condition|(
operator|(
name|chan
operator|=
name|addr
operator|->
name|xfr_chan
operator|)
operator|>
name|nddach
index|[
name|unit
index|]
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|4
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: unknown transfer channel, lcn=%d\n"
operator|,
name|unit
operator|,
name|chan
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|addr
operator|->
name|xfr_flags
operator|&
name|FLAGS_DIR
condition|)
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_wchan
operator|)
expr_stmt|;
comment|/* write channel */
else|else
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_rchan
operator|)
expr_stmt|;
comment|/* read channel */
name|cnt
operator|=
name|addr
operator|->
name|xfr_cnt
expr_stmt|;
comment|/* Transfer Request byte count */
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|5
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: transfer request lcn %d: no mbuf\n"
operator|,
name|unit
operator|,
name|chan
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|addr
operator|->
name|xfr_cnt
operator|=
literal|0
expr_stmt|;
comment|/* Abort the transfer */
return|return;
block|}
name|pgoff
operator|=
operator|(
name|int
operator|)
name|hc
operator|->
name|hc_addr
operator|&
name|PGOFSET
expr_stmt|;
if|#
directive|if
name|ACC_VMS
operator|>
literal|00
comment|/* System page table entry for VMS */
name|temp
operator|=
operator|(
operator|(
operator|(
name|int
operator|)
name|hc
operator|->
name|hc_addr
operator|&
operator|(
operator|~
name|PG_V
operator|&
operator|~
operator|(
name|NBPG
operator|-
literal|1
operator|)
operator|)
operator|)
operator|/
name|NBPG
operator|)
expr_stmt|;
name|pte
operator|=
operator|(
expr|struct
name|pte
operator|*
operator|)
operator|(
operator|(
name|int
operator|)
name|mmg$gl_sptbase
operator|+
operator|(
literal|4
operator|*
name|temp
operator|)
operator|)
expr_stmt|;
comment|/* 	 * Find the adapter  	 */
ifdef|#
directive|ifdef
name|WINS
name|adp
operator|=
name|ioc$gl_adplist
expr_stmt|;
while|while
condition|(
name|adp
condition|)
block|{
if|if
condition|(
operator|(
name|adp
operator|->
name|adp$w_adptype
operator|==
name|AT$_UBA
operator|)
operator|&&
operator|(
name|adp
operator|->
name|adp$b_number
operator|==
name|ui
operator|->
name|ui_ubanum
operator|)
condition|)
break|break;
name|adp
operator|=
name|adp
operator|->
name|adp$l_link
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|adp
condition|)
return|return;
comment|/* adp not found */
name|io
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
operator|(
name|int
operator|)
name|adp
operator|->
name|adp$l_csr
operator|+
literal|0x800
operator|+
operator|(
literal|4
operator|*
operator|(
name|ds
operator|->
name|dda_mapreg
operator|)
operator|)
operator|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MULTINET
name|adp
operator|=
operator|(
expr|struct
name|ADP
operator|*
operator|)
literal|0
expr_stmt|;
while|while
condition|(
literal|1
condition|)
block|{
name|char
modifier|*
modifier|*
name|vector
decl_stmt|;
name|int
name|number
decl_stmt|,
name|csr
decl_stmt|;
comment|/* 	     * Get the next adapter  	     */
name|adp
operator|=
operator|(
expr|struct
name|ADP
operator|*
operator|)
name|vms_next_uba
argument_list|(
name|adp
argument_list|,
operator|&
name|vector
argument_list|,
operator|&
name|number
argument_list|,
operator|&
name|csr
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|adp
condition|)
return|return;
comment|/* 	     * Is this the one we are looking for?  	     */
if|if
condition|(
name|number
operator|==
name|ui
operator|->
name|ui_ubanum
condition|)
block|{
comment|/* yes */
name|io
operator|=
operator|(
name|int
operator|*
operator|)
operator|(
operator|(
name|int
operator|)
name|csr
operator|+
literal|0x800
operator|+
operator|(
literal|4
operator|*
operator|(
name|ds
operator|->
name|dda_mapreg
operator|)
operator|)
operator|)
expr_stmt|;
break|break;
block|}
block|}
endif|#
directive|endif
else|#
directive|else
comment|/* not VMS */
ifdef|#
directive|ifdef
name|kvtopte
comment|/* if the macro exists, use it for compatibility */
comment|/* this will be in 4.3tahoe and newer */
name|pte
operator|=
name|kvtopte
argument_list|(
name|hc
operator|->
name|hc_addr
argument_list|)
expr_stmt|;
name|io
operator|=
operator|&
name|uh
operator|->
name|uh_mr
index|[
name|ds
operator|->
name|dda_mapreg
index|]
expr_stmt|;
else|#
directive|else
ifdef|#
directive|ifdef
name|svtopte
comment|/* under ultrix, kvtopte is svtopte */
comment|/* but the map registers are in the right place */
name|pte
operator|=
name|svtopte
argument_list|(
name|hc
operator|->
name|hc_addr
argument_list|)
expr_stmt|;
name|io
operator|=
operator|&
name|uh
operator|->
name|uh_uba
operator|->
name|uba_map
index|[
name|ds
operator|->
name|dda_mapreg
index|]
expr_stmt|;
else|#
directive|else
comment|/* not 4.3tahoe or a new ultrix flavor */
name|pte
operator|=
operator|&
name|Sysmap
index|[
name|btop
argument_list|(
operator|(
name|int
operator|)
name|hc
operator|->
name|hc_addr
operator|&
operator|~
name|PG_V
argument_list|)
index|]
expr_stmt|;
name|io
operator|=
operator|&
name|uh
operator|->
name|uh_uba
operator|->
name|uba_map
index|[
name|ds
operator|->
name|dda_mapreg
index|]
expr_stmt|;
endif|#
directive|endif
comment|/* not 4.3tahoe or a new ultrix flavor */
endif|#
directive|endif
endif|#
directive|endif
comment|/* pte now points to system memory page table entry */
comment|/* io points to UNIBUS/QBUS mapping register */
ifndef|#
directive|ifndef
name|SIMULATION
comment|/* calculate number of page frames */
name|npf
operator|=
operator|(
name|hc
operator|->
name|hc_cnt
operator|+
name|BUS_PGOFSET
operator|)
operator|>>
name|BUS_PGSHIFT
expr_stmt|;
comment|/* page_to_map is all but nine bits of the physical address 	   in other words, the 512-byte page the bus wants us to map */
name|page_to_map
operator|=
operator|(
operator|(
name|pte
operator|++
operator|)
operator|->
name|pg_pfnum
operator|<<
operator|(
name|PGSHIFT
operator|-
name|BUS_PGSHIFT
operator|)
operator|)
operator||
operator|(
name|pgoff
operator|>>
name|BUS_PGSHIFT
operator|)
expr_stmt|;
while|while
condition|(
name|npf
operator|--
condition|)
block|{
comment|/* UBAMR_MRV = mapping register valid */
operator|*
operator|(
name|int
operator|*
operator|)
name|io
operator|++
operator|=
name|page_to_map
operator|++
operator||
name|UBAMR_MRV
expr_stmt|;
comment|/* when page_to_map crosses a memory page boundary, we 	       need to get the new physical address from the next pte 	       (on a vax, this happens every time, on a mips, only when 	       the lower 3 bits go from 111 to 000) */
if|if
condition|(
name|page_to_map
operator|&
operator|(
name|PGOFSET
operator|>>
name|BUS_PGSHIFT
operator|)
operator|==
literal|0
condition|)
comment|/* we know page offset is now going to be zero, so don't 		   bother adding it in (like we had to do above) */
name|page_to_map
operator|=
operator|(
name|pte
operator|++
operator|)
operator|->
name|pg_pfnum
operator|<<
operator|(
name|PGSHIFT
operator|-
name|BUS_PGSHIFT
operator|)
expr_stmt|;
block|}
operator|*
operator|(
name|int
operator|*
operator|)
name|io
operator|++
operator|=
literal|0
expr_stmt|;
comment|/* invalidate last UMR */
comment|/* supply values for Transfer Request Mailbox */
name|addr
operator|->
name|xfr_chan
operator|=
name|chan
expr_stmt|;
comment|/* data path number */
name|uadr
operator|=
operator|(
name|ds
operator|->
name|dda_mapreg
operator|<<
name|BUS_PGSHIFT
operator|)
operator|+
operator|(
name|pgoff
operator|&
name|BUS_PGOFSET
operator|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QBUS
name|addr
operator|->
name|xfr_adx
operator|=
operator|(
name|uadr
operator|&
literal|0x3f0000
operator|)
operator|>>
literal|16
expr_stmt|;
comment|/* ext address bits 23-16  */
else|#
directive|else
else|QBUS
name|addr
operator|->
name|xfr_adx
operator|=
operator|(
name|uadr
operator|&
literal|0x30000
operator|)
operator|>>
literal|16
expr_stmt|;
comment|/* ext address bits 18-16  */
endif|#
directive|endif
endif|QBUS
else|#
directive|else
else|SIMULATION
name|uadr
operator|=
operator|(
name|int
operator|)
name|hc
operator|->
name|hc_addr
expr_stmt|;
comment|/* just use the direct address */
name|addr
operator|->
name|xfr_adx
operator|=
operator|(
name|uadr
operator|&
literal|0xFF0000
operator|)
operator|>>
literal|16
expr_stmt|;
comment|/* ext ms address bits */
endif|#
directive|endif
endif|SIMULATION
name|addr
operator|->
name|xfr_addr
operator|=
name|uadr
operator|&
literal|0xffff
expr_stmt|;
comment|/* grnt transfer address bits 15-0 */
name|hc
operator|->
name|hc_cnt
operator|-=
name|cnt
expr_stmt|;
name|hc
operator|->
name|hc_addr
operator|+=
name|cnt
expr_stmt|;
name|addr
operator|->
name|xfr_flags
operator|=
operator|(
name|addr
operator|->
name|xfr_flags
operator|&
operator|~
name|FLAGS_RDY
operator|)
operator||
name|FLAGS_DON
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
comment|/* enable interrupt "a" */
block|}
comment|/***********************************************************************/
comment|/*   Check I/O Request Mailbox                                         */
comment|/***********************************************************************/
if|if
condition|(
name|addr
operator|->
name|req_flags
operator|&
name|FLAGS_DON
condition|)
block|{
comment|/* I/O Request Mailbox */
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(rx)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|addr
operator|->
name|req_flags
operator|&=
operator|~
name|FLAGS_DON
expr_stmt|;
comment|/* dequeue old request by copying link to queue head */
comment|/* and start next I/O request if queue is not empty */
if|if
condition|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|=
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|->
name|hc_next
condition|)
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
block|}
comment|/***********************************************************************/
comment|/*   Check I/O Completion Mailbox                                      */
comment|/***********************************************************************/
if|if
condition|(
name|addr
operator|->
name|cmp_flags
operator|&
name|FLAGS_RDY
condition|)
block|{
comment|/* I/O Completion Mailbox */
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(cx)"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Get logical channel information.  	 */
if|if
condition|(
operator|(
name|chan
operator|=
name|addr
operator|->
name|cmp_chan
operator|)
operator|>
name|nddach
index|[
name|unit
index|]
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|6
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: unknown completion channel, lcn=%d\n"
operator|,
name|unit
operator|,
name|chan
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|addr
operator|->
name|cmp_flags
operator|&
name|FLAGS_DIR
condition|)
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_wchan
operator|)
expr_stmt|;
comment|/* write channel */
else|else
name|hc
operator|=
operator|&
operator|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_rchan
operator|)
expr_stmt|;
comment|/* read channel */
name|cc
operator|=
name|addr
operator|->
name|cmp_stat
expr_stmt|;
comment|/* Mailbox I/O completion status */
name|subcc
operator|=
name|addr
operator|->
name|cmp_sbst
expr_stmt|;
comment|/* Mailbox I/O completion substatus */
name|cnt
operator|=
name|addr
operator|->
name|cmp_cnt
expr_stmt|;
comment|/* Mailbox I/O completion byte count */
ifdef|#
directive|ifdef
name|mips
comment|/* if it was a read completion, invalidate the mbuf data portion */
comment|/* NOTE: the direction check has been commented out because it  	   seemed like we got it backwards and forgot to check it later. 	   This is now believed to be correct, but is left commented out until 	   a beta site checks it for us. */
comment|/* if (!(hc->hc_chan& 1)) */
block|{
name|int
name|phys_begin
init|=
name|svtophy
argument_list|(
name|mtod
argument_list|(
name|hc
operator|->
name|hc_cur
argument_list|,
name|u_char
operator|*
argument_list|)
argument_list|)
decl_stmt|;
name|clean_dcache
argument_list|(
name|PHYS_TO_K0
argument_list|(
name|phys_begin
argument_list|)
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
switch|switch
condition|(
name|cc
condition|)
block|{
comment|/* check for unsuccessful I/O completion status */
case|case
name|DDAIOCABT
case|:
comment|/* probably VCN flush */
if|if
condition|(
name|LOG_ABT
condition|)
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: abort completed on chan %d\n"
operator|,
name|unit
operator|,
name|hc
operator|->
name|hc_chan
name|DDAELOG
expr_stmt|;
break|break;
case|case
name|DDAIOCERR
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|7
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: program error "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIOCOVR
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|8
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: overrun error "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIOCUBE
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|9
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: transfer count = 0 "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIODMAE
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|10
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: DMA completion error (%x) "
operator|,
name|unit
operator|,
name|addr
operator|->
name|cmp_sbst
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIOLCOL
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|11
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: listen collision "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIOFUNC
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|12
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: invalid function "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
case|case
name|DDAIODPN
case|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|13
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: invalid dpn "
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
goto|goto
name|daterr
goto|;
name|daterr
label|:
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|14
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"lcn=%d func=%x\n"
operator|,
name|chan
operator|,
name|hc
operator|->
name|hc_func
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_func
operator|&
name|DDARDB
condition|)
name|ds
operator|->
name|dda_if
operator|.
name|if_ierrors
operator|++
expr_stmt|;
else|else
name|ds
operator|->
name|dda_if
operator|.
name|if_oerrors
operator|++
expr_stmt|;
block|}
comment|/* was it supervisor or data traffic? */
if|if
condition|(
name|chan
operator|>
name|DDA_SUPR
condition|)
block|{
ifdef|#
directive|ifdef
name|DDA_PADOPT
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_flags
operator|&
name|DC_X29
condition|)
name|x29_data
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|,
name|subcc
argument_list|)
expr_stmt|;
elseif|else
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_RAWOPT
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
name|chan
index|]
operator|.
name|dc_flags
operator|&
name|DC_RAW
condition|)
name|pi_data
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|,
name|subcc
argument_list|)
expr_stmt|;
else|else
endif|#
directive|endif
name|dda_data
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
block|}
else|else
name|dda_supr
argument_list|(
name|ds
argument_list|,
name|hc
argument_list|,
name|cc
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
comment|/* 	 * Ack the interrupt.  Fix the Mailbox Ready and Done bits:  set DON 	 * bits, and clear RDY bits so mailbox may be reused.  	 */
name|addr
operator|->
name|cmp_flags
operator|=
operator|(
name|addr
operator|->
name|cmp_flags
operator|&
operator|~
name|FLAGS_RDY
operator|)
operator||
name|FLAGS_DON
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
comment|/* enable interrupt "a" */
block|}
block|}
end_block

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDAINTB()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*   Service interrupt "b", system interrupt, from the ACP device. */
end_comment

begin_comment
comment|/*   If the ACP device is operational, interrupt is unexpected,    */
end_comment

begin_comment
comment|/*   disable the device.  If the interrupt indicates a powerup     */
end_comment

begin_comment
comment|/*   diagnostic failure, disable the device.  Otherwise, set ACP   */
end_comment

begin_comment
comment|/*   flag for device operational, enable interrupt a, enable DMA,  */
end_comment

begin_comment
comment|/*   and perform initialization tasks.                             */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:             ddaintb(unit)                                */
end_comment

begin_comment
comment|/*  Argument:         unit: DDA device unit number                 */
end_comment

begin_comment
comment|/*  Returns:          nothing                                      */
end_comment

begin_comment
comment|/*  Called by:        network software, address of this routine is */
end_comment

begin_comment
comment|/*                    defined in af_inet network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:         DDALOG()                                     */
end_comment

begin_comment
comment|/*                    ddainit()                                    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_macro
name|ddaintb
argument_list|(
argument|unit
argument_list|)
end_macro

begin_decl_stmt
name|int
name|unit
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|u_char
name|diag_stat
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|6
argument_list|,
name|unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ddaintb()\n"
operator|,
name|unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
if|if
condition|(
name|ds
operator|->
name|dda_flags
operator|&
name|DDAF_OK
condition|)
block|{
comment|/* 	 * Change to rev2.0 and above driver: attempt to handle an unexpected 	 * B interrupt sanely by reinitializing the world. We turn off all 	 * the flavors of UP and OK flags and call ddareset().  This will 	 * restart the diagnostics and enable interrupt B.  After the 	 * diagnostics run, we'll come back here to the B interrupt handler 	 * and with DDAF_OK off will enter the "else" below.  With luck the 	 * board will report success and we'll call ddainit() to bring the 	 * link back on line.  	 */
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|15
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: asynchronous restart, status = %d\n"
operator|,
name|unit
operator|,
name|addr
operator|->
name|sys_stat
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_flags
operator|=
literal|0
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
operator|(
name|IFF_RUNNING
operator||
name|IFF_UP
operator|)
expr_stmt|;
name|hist_link_state
argument_list|(
name|unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
name|ddareset
argument_list|(
name|unit
argument_list|,
name|ui
operator|->
name|ui_ubanum
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|diag_stat
operator|=
name|addr
operator|->
name|sys_stat
expr_stmt|;
if|if
condition|(
operator|(
name|diag_stat
operator|&
name|DDASTAT_ERR
operator|)
operator|!=
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|16
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: Diagnostic failure = %d\n"
operator|,
name|unit
operator|,
name|addr
operator|->
name|sys_stat
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|diag_stat
operator|==
name|DDASTAT_NMC
condition|)
block|{
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|17
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: No Microcode Present!\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|diag_stat
operator|==
name|DDASTAT_OK
condition|)
block|{
comment|/*  * For each lcn, clear the output queue and free hdx read and write mbufs  */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|NDDACH
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCNs */
name|dc
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_cb
index|[
name|lcn
index|]
expr_stmt|;
while|while
condition|(
name|dc
operator|->
name|dc_oq
operator|.
name|ifq_len
condition|)
block|{
name|IF_DEQUEUE
argument_list|(
operator|&
name|dc
operator|->
name|dc_oq
argument_list|,
name|m
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
condition|)
name|m_freem
argument_list|(
name|m
argument_list|)
expr_stmt|;
block|}
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_rchan
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
condition|)
block|{
name|m_freem
argument_list|(
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
block|}
name|hc
operator|=
operator|&
name|dc
operator|->
name|dc_wchan
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
condition|)
block|{
name|m_freem
argument_list|(
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
block|}
block|}
name|ds
operator|->
name|dda_flags
operator||=
name|DDAF_OK
expr_stmt|;
name|addr
operator|->
name|csr
operator||=
operator|(
name|CSR_IENA
operator||
name|CSR_DMAEN
operator|)
expr_stmt|;
name|ddainit
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDA_WRQ()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    Process write requests.  Put I/O request values in           */
end_comment

begin_comment
comment|/*    half-duplex control channel structure:  set function code    */
end_comment

begin_comment
comment|/*    for write to ACP with Transfer Grant set.  If there are no   */
end_comment

begin_comment
comment|/*    more mbufs in chain, mark DDAEOS for end of stream.  Set     */
end_comment

begin_comment
comment|/*    count from data length (byte count) in mbuf, and subfunction */
end_comment

begin_comment
comment|/*    is zero.  If the COMREGs are busy, queue for start later.    */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            dda_wrq(ds, hc, abt)                          */
end_comment

begin_comment
comment|/*  Argument:        ds:   pointer to device control block struct  */
end_comment

begin_comment
comment|/*                   hc:   pointer to half-duplex channel cntl blk */
end_comment

begin_comment
comment|/*		     abt:  indication of whether request is an     */
end_comment

begin_comment
comment|/*			   abort request.			   */
end_comment

begin_comment
comment|/*  Returns:         nothing                                       */
end_comment

begin_comment
comment|/*  Called by:         dda_start()                                 */
end_comment

begin_comment
comment|/*                     dda_data()                                  */
end_comment

begin_comment
comment|/*  Calls to:          mtod()                                      */
end_comment

begin_comment
comment|/*                     start_chn()                                 */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|dda_wrq
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|,
name|abt
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
name|u_char
name|abt
decl_stmt|;
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
comment|/* set channel info */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|m
operator|=
name|hc
operator|->
name|hc_curr
expr_stmt|;
name|hc
operator|->
name|hc_addr
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
comment|/* point to data in mbuf */
name|hc
operator|->
name|hc_cnt
operator|=
name|m
operator|->
name|m_len
expr_stmt|;
comment|/* byte count            */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
comment|/* set Transfer Request Write, mark DDAEOS if end of stream */
comment|/* note: non-unibus products ignore the address invalid (DDAXFR) bit */
if|if
condition|(
name|abt
condition|)
name|hc
operator|->
name|hc_func
operator|=
name|DDAABT
expr_stmt|;
elseif|else
if|if
condition|(
name|m
operator|->
name|m_next
operator|==
literal|0
condition|)
name|hc
operator|->
name|hc_func
operator|=
name|DDAWRT
operator|+
name|DDAEOS
operator|+
name|DDAXFR
expr_stmt|;
else|else
name|hc
operator|->
name|hc_func
operator|=
name|DDAWRT
operator|+
name|DDASTR
operator|+
name|DDAXFR
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|15
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_wrq: chan=%d func=%x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
operator|,
name|hc
operator|->
name|hc_func
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/*      * If ACP comm regs busy, queue start i/o for later.       */
if|if
condition|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
condition|)
block|{
operator|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|)
operator|->
name|hc_next
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* start i/o on channel now */
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      DDA_RRQ()                              %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    Process read requests.  Quit if attempt to get an mbuf is    */
end_comment

begin_comment
comment|/*    unsuccessful.  Put I/O request values in half-duplex control */
end_comment

begin_comment
comment|/*    channel structure:  set function code for read from ACP with */
end_comment

begin_comment
comment|/*    Transfer Grant set, set count from data length (byte count)  */
end_comment

begin_comment
comment|/*    in mbuf, and subfunction is zero.                            */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:            dda_rrq(ds, hc)                               */
end_comment

begin_comment
comment|/*  Argument:        ds:   pointer to device control block struct  */
end_comment

begin_comment
comment|/*                   hc:   pointer to half-duplex control chan     */
end_comment

begin_comment
comment|/*  Returns:         nothing                                       */
end_comment

begin_comment
comment|/*  Called by:       ddainit()                                     */
end_comment

begin_comment
comment|/*                   dda_data()                                    */
end_comment

begin_comment
comment|/*                   dda_supr()                                    */
end_comment

begin_comment
comment|/*  Calls to:        MGET()                                        */
end_comment

begin_comment
comment|/*                   DDALOG()                                      */
end_comment

begin_comment
comment|/*                   start_chn()                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|dda_rrq
parameter_list|(
name|ds
parameter_list|,
name|hc
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|16
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: dda_rrq()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
name|MGET
argument_list|(
name|m
argument_list|,
name|M_DONTWAIT
argument_list|,
name|MT_DATA
argument_list|)
expr_stmt|;
if|if
condition|(
name|m
operator|==
literal|0
condition|)
block|{
name|DMESG
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|25
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d:  couldn't get buffer for read\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|m
operator|->
name|m_len
operator|=
literal|0
expr_stmt|;
comment|/* new mbuf, doesn't contain data yet */
comment|/* hc_mbuf set to zero during initialization */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
operator|==
literal|0
condition|)
block|{
name|hc
operator|->
name|hc_mbuf
operator|=
name|m
expr_stmt|;
name|hc
operator|->
name|hc_curr
operator|=
name|m
expr_stmt|;
block|}
else|else
block|{
name|hc
operator|->
name|hc_curr
operator|->
name|m_next
operator|=
name|m
expr_stmt|;
name|hc
operator|->
name|hc_curr
operator|=
name|m
expr_stmt|;
name|m
operator|->
name|m_next
operator|=
literal|0
expr_stmt|;
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_func
operator|=
name|DDARDB
operator|+
name|DDASTR
operator|+
name|DDAXFR
expr_stmt|;
name|hc
operator|->
name|hc_sbfc
operator|=
literal|0
expr_stmt|;
comment|/* hc_cnt determines size of read request, addr->req_cnt */
comment|/* MLEN is 112 bytes, the data portion of a small mbuf   */
name|hc
operator|->
name|hc_cnt
operator|=
name|MLEN
expr_stmt|;
comment|/* just got the mbuf */
name|hc
operator|->
name|hc_addr
operator|=
name|mtod
argument_list|(
name|m
argument_list|,
name|u_char
operator|*
argument_list|)
expr_stmt|;
comment|/* point to mbuf data */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/*      * If ACP comm regs busy, queue start i/o for later.       */
if|if
condition|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
condition|)
block|{
operator|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|)
operator|->
name|hc_next
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* start i/o on channel now */
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|=
name|hc
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_tail
operator|=
name|hc
expr_stmt|;
name|hc
operator|->
name|hc_next
operator|=
literal|0
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      START_CHN()                            %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*    This routine copies ACP I/O requests into the ACP            */
end_comment

begin_comment
comment|/*    Communications Registers (COMREGs) and notifies the ACP.     */
end_comment

begin_comment
comment|/*    If the channel number is odd, indicating write, then the     */
end_comment

begin_comment
comment|/*    direction flag is set to indicate a transfer from the host   */
end_comment

begin_comment
comment|/*    to the front end.                                            */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              start_chn(ds)                               */
end_comment

begin_comment
comment|/*  Argument:          ds:  pointer to device control block struct */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         ddainta()                                   */
end_comment

begin_comment
comment|/*                     dda_rrq()                                   */
end_comment

begin_comment
comment|/*                     dda_wrq()                                   */
end_comment

begin_comment
comment|/*  Calls to:          none                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|int
name|start_chn
parameter_list|(
name|ds
parameter_list|)
name|struct
name|dda_softc
modifier|*
name|ds
decl_stmt|;
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|hdx_chan
modifier|*
name|hc
decl_stmt|;
specifier|register
name|int
name|s
decl_stmt|;
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
operator|(
name|ddainfo
index|[
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
index|]
operator|)
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|17
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: start_chn()\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/*  *  Scan sioq for invalid writes  */
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
name|hc
operator|=
operator|(
expr|struct
name|hdx_chan
operator|*
operator|)
operator|(
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|)
expr_stmt|;
if|if
condition|(
name|hc
operator|&&
operator|(
operator|(
name|addr
operator|->
name|req_flags
operator|&
name|FLAGS_RDY
operator|)
operator|==
literal|0
operator|)
condition|)
block|{
for|for
control|(
init|;
name|hc
condition|;
name|hc
operator|=
name|hc
operator|->
name|hc_next
control|)
block|{
comment|/* scan sioq */
if|if
condition|(
operator|(
name|hc
operator|->
name|hc_chan
operator|&
literal|0x01
operator|)
operator|&&
operator|(
name|hc
operator|->
name|hc_chan
operator|!=
literal|1
operator|)
operator|&&
operator|(
name|hc
operator|->
name|hc_inv
operator|&
name|INVALID_MBUF
operator|)
condition|)
block|{
if|if
condition|(
name|ds
operator|->
name|dda_cb
index|[
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
index|]
operator|.
name|dc_flags
operator|&
name|DC_OBUSY
condition|)
goto|goto
name|send
goto|;
comment|/* send an abort */
else|else
block|{
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
condition|)
block|{
comment|/* free pending request */
name|m_freem
argument_list|(
name|hc
operator|->
name|hc_mbuf
argument_list|)
expr_stmt|;
name|hc
operator|->
name|hc_mbuf
operator|=
name|hc
operator|->
name|hc_curr
operator|=
operator|(
expr|struct
name|mbuf
operator|*
operator|)
literal|0
expr_stmt|;
name|hc
operator|->
name|hc_inv
operator|&=
operator|~
name|INVALID_MBUF
expr_stmt|;
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|=
name|ds
operator|->
name|dda_sioq
operator|.
name|sq_head
operator|->
name|hc_next
expr_stmt|;
block|}
comment|/*  * Restart Output  */
comment|/* 		     * not needed ds->dda_cb[hc->hc_chan>>1].dc_flags&= 		     * ~DC_OBUSY;  		     */
comment|/* 		     * this should be changed to drop ipl before calling 		     * dda_start  		     */
name|dda_start
argument_list|(
name|ds
argument_list|,
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
index|]
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* Read or Write request is valid */
comment|/* 		 * Set up comm regs.  		 */
name|send
label|:
name|addr
operator|->
name|req_chan
operator|=
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
expr_stmt|;
name|addr
operator|->
name|req_cnt
operator|=
name|hc
operator|->
name|hc_cnt
expr_stmt|;
name|addr
operator|->
name|req_fcn
operator|=
name|hc
operator|->
name|hc_func
expr_stmt|;
name|addr
operator|->
name|req_sbf
operator|=
name|hc
operator|->
name|hc_sbfc
expr_stmt|;
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|1
condition|)
block|{
comment|/* write */
ifdef|#
directive|ifdef
name|DDADEBUG
name|struct
name|dda_cb
modifier|*
name|dc
init|=
operator|&
name|ds
operator|->
name|dda_cb
index|[
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|DDADBCH
argument_list|(
literal|17
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: start_chn: WRITE on lcn %d func %x\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
operator|,
name|hc
operator|->
name|hc_func
name|DDAELOG
expr_stmt|;
if|if
condition|(
name|dc
operator|->
name|dc_lcn
condition|)
comment|/* don't start timer on lcn 0 */
name|dc
operator|->
name|dc_out_t
operator|=
name|TMO_RESTART
expr_stmt|;
comment|/* Wait 90 sec for 							 * completion */
endif|#
directive|endif
name|addr
operator|->
name|req_flags
operator|=
name|FLAGS_RDY
operator||
name|FLAGS_DIR
expr_stmt|;
block|}
else|else
name|addr
operator|->
name|req_flags
operator|=
name|FLAGS_RDY
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|28
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
if|if
condition|(
name|hc
operator|->
name|hc_func
operator|==
name|DDAABT
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: start_chn: aborting chan %d\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
operator|,
name|hc
operator|->
name|hc_chan
name|DDAELOG
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DDA_MSGQ
name|dda_mqstr
argument_list|(
literal|"(sc "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|addr
operator|->
name|req_flags
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|hc
operator|->
name|hc_cnt
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqnum
argument_list|(
name|hc
operator|->
name|hc_func
argument_list|,
name|MQHEX
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|" "
argument_list|)
expr_stmt|;
name|dda_mqstr
argument_list|(
literal|")"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DDA_MSGQ
endif|#
directive|endif
endif|DDADEBUG
name|addr
operator|->
name|csr
operator||=
name|CSR_INTRA
expr_stmt|;
comment|/* interrupt FE */
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
comment|/* no valid requests found */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*@@%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*%%                      BUFRESET()                             %%*/
end_comment

begin_comment
comment|/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Purpose:                                                       */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*      Reset of interface after UNIBUS reset.  If interface is on */
end_comment

begin_comment
comment|/*      specified uba, reset its state.  Free mbufs if there is    */
end_comment

begin_comment
comment|/*      queued output data.                                        */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:              bufreset(unit)                              */
end_comment

begin_comment
comment|/*  Arguments:         unit:   ACP device unit number              */
end_comment

begin_comment
comment|/*  Returns:           nothing                                     */
end_comment

begin_comment
comment|/*  Called by:         network software, address of routine is     */
end_comment

begin_comment
comment|/*                     defined in dda_if network interface struct  */
end_comment

begin_comment
comment|/*  Calls to:          DDALOG()                                    */
end_comment

begin_comment
comment|/*                     IF_DEQUEUE()                                */
end_comment

begin_comment
comment|/*                     m_freem()                                   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_function
name|PRIVATE
name|void
name|bufreset
parameter_list|(
name|unit
parameter_list|)
name|int
name|unit
decl_stmt|;
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
init|=
operator|&
name|dda_softc
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|int
name|lcn
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NDDA
operator|||
operator|(
name|ui
operator|==
literal|0
operator|||
name|ui
operator|->
name|ui_alive
operator|==
literal|0
operator|)
condition|)
return|return;
name|DMESG
argument_list|(
name|unit
argument_list|,
literal|38
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: buffer size reset\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_if
operator|.
name|if_flags
operator|&=
operator|~
name|IFF_UP
expr_stmt|;
name|hist_link_state
argument_list|(
name|unit
argument_list|,
name|ds
operator|->
name|dda_state
argument_list|,
name|S_DISABLED
argument_list|)
expr_stmt|;
name|ds
operator|->
name|dda_state
operator|=
name|S_DISABLED
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
name|addr
operator|->
name|cmp_flags
operator|=
literal|0
expr_stmt|;
comment|/* I/O completion flags         */
name|addr
operator|->
name|xfr_flags
operator|=
literal|0
expr_stmt|;
comment|/* transfer request/grant flags */
name|addr
operator|->
name|req_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|req_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|req_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|req_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|req_fcn
operator|=
literal|0
expr_stmt|;
comment|/* I/O function                 */
name|addr
operator|->
name|req_sbf
operator|=
literal|0
expr_stmt|;
comment|/* I/O subfunction              */
name|addr
operator|->
name|cmp_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|cmp_unused
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|cmp_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|cmp_stat
operator|=
literal|0
expr_stmt|;
comment|/* I/O status                   */
name|addr
operator|->
name|cmp_sbst
operator|=
literal|0
expr_stmt|;
comment|/* I/O substatus                */
name|addr
operator|->
name|xfr_chan
operator|=
literal|0
expr_stmt|;
comment|/* FDX channel number           */
name|addr
operator|->
name|xfr_adx
operator|=
literal|0
expr_stmt|;
comment|/* address bits 17-16           */
name|addr
operator|->
name|xfr_addr
operator|=
literal|0
expr_stmt|;
comment|/* address bits 15-00           */
name|addr
operator|->
name|xfr_cnt
operator|=
literal|0
expr_stmt|;
comment|/* byte count                   */
name|addr
operator|->
name|sys_stat
operator|=
literal|0
expr_stmt|;
comment|/* system status                */
name|addr
operator|->
name|req_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear handshake flags, mailbox     */
comment|/* pass interrupt vector to ACP */
name|addr
operator|->
name|sys_vect
operator|=
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_vector
operator|>>
literal|2
expr_stmt|;
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear ACP operational flag  */
name|ds
operator|->
name|dda_init
operator|&=
operator|~
name|DDA_INTCLOCK
expr_stmt|;
comment|/* reset internal-clocking-set bit */
name|nddach
index|[
name|unit
index|]
operator|=
name|NDDACH_DEFAULT
expr_stmt|;
comment|/* reset SVC limit */
comment|/* LCNLINK */
name|dc
operator|=
name|dda_softc
index|[
name|unit
index|]
operator|.
name|dda_cb
expr_stmt|;
comment|/* flush any queued output data */
for|for
control|(
name|lcn
operator|=
literal|0
init|;
name|lcn
operator|<=
name|NDDACH
condition|;
name|lcn
operator|++
control|)
block|{
comment|/* for all LCN's ... */
name|dc
operator|->
name|dc_inaddr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
comment|/* clear remote internet addr */
name|dc
operator|->
name|dc_key
operator|.
name|key_addr
operator|.
name|s_addr
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_wsizein
operator|=
name|dc
operator|->
name|dc_wsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_pktsizein
operator|=
name|dc
operator|->
name|dc_pktsizeout
operator|=
literal|0
expr_stmt|;
name|dc
operator|->
name|dc_state
operator|=
name|LC_IDLE
expr_stmt|;
comment|/* init LCN state */
name|dc
operator|->
name|dc_timer
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn LCN timer off */
name|dc
operator|->
name|dc_flags
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
name|dc
operator|->
name|dc_out_t
operator|=
name|TMO_OFF
expr_stmt|;
comment|/* turn FE completion timer off */
endif|#
directive|endif
name|dc
operator|++
expr_stmt|;
block|}
name|hist_all_lcns
argument_list|(
name|unit
argument_list|,
name|LC_IDLE
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DDA_RAWOPT
name|pi_init
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DDA_PADOPT
name|x29_init
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|addr
operator|->
name|csr
operator||=
name|CSR_IENB
expr_stmt|;
name|wbflush
argument_list|()
expr_stmt|;
comment|/* flush write pipeline cache */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  * Disable all interrrupts and forget about board  */
end_comment

begin_function
name|PRIVATE
name|void
name|dda_disable
parameter_list|(
name|unit
parameter_list|)
block|{
specifier|volatile
name|struct
name|ddaregs
modifier|*
name|addr
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
name|ui
operator|=
operator|(
expr|struct
name|uba_device
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
expr_stmt|;
name|addr
operator|=
operator|(
expr|struct
name|ddaregs
operator|*
operator|)
operator|(
name|ui
operator|->
name|ui_addr
operator|)
expr_stmt|;
name|addr
operator|->
name|csr
operator|=
literal|0
expr_stmt|;
name|wbflush
argument_list|()
expr_stmt|;
comment|/* flush write pipeline cache */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/*  Revision History:  13-Jul-1989: PST	Used PRIVATE convention on functions 01-Aug-1989: PST	Added initialization of ddamsgs in attach routine. 01-Sep-1989: PST	Ignore uban parameter to ddareset. 14-Nov-1989: PST	Added support for MIPS PMAX architecture and 			fixed a QBUS bug (we were not using all 22 addr bits). 			Moved rrq and wrq routines here. 30-Nov-1989: PST	Moved unibus defines here. 01-Dec-1989: PST	Fixed typos. */
end_comment

end_unit

