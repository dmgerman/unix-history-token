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
comment|/*  File:		if_dda_bibus.c                                   */
end_comment

begin_comment
comment|/*			BI bus support routines for dda			 */
end_comment

begin_comment
comment|/*                                                                       */
end_comment

begin_comment
comment|/*  Project:		DDN-X.25 Network Interface Driver for ACP 7250   */
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

begin_include
include|#
directive|include
file|"../vaxif/if_uba.h"
end_include

begin_include
include|#
directive|include
file|"../vaxuba/ubavar.h"
end_include

begin_include
include|#
directive|include
file|"../vaxbi/bireg.h"
end_include

begin_include
include|#
directive|include
file|"../vaxif/if_ddabique.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SIMULATION
end_ifdef

begin_define
define|#
directive|define
name|KM_CLUSTER
value|28
end_define

begin_define
define|#
directive|define
name|KM_NOWAIT
value|1
end_define

begin_define
define|#
directive|define
name|KM_ALLOC
parameter_list|(
name|space
parameter_list|,
name|cast
parameter_list|,
name|size
parameter_list|,
name|type
parameter_list|,
name|flags
parameter_list|)
value|{ \ 	(space) = (cast)malloc(size); \ }
end_define

begin_define
define|#
directive|define
name|KM_FREE
parameter_list|(
name|addr
parameter_list|,
name|type
parameter_list|)
value|{ \ 	(void)free((caddr_t)(addr)); \ }
end_define

begin_undef
undef|#
directive|undef
name|svtophy
end_undef

begin_define
define|#
directive|define
name|svtophy
parameter_list|(
name|x
parameter_list|)
value|((int)(x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	private functions in this module  */
end_comment

begin_function_decl
name|PRIVATE
name|void
name|dda_shm_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_disable
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_dump_biic_regs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_dump_shm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|void
name|dda_unit_reset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PRIVATE
name|int
name|dda_dload
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|bidata
name|bidata
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* previous_unload contains this value if the request queue is *not* blocked */
end_comment

begin_define
define|#
directive|define
name|UL_NOT_BLOCKED
value|(RQSIZE+1)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|byte
name|fe_state
decl_stmt|;
name|byte
name|fe_soft_id
decl_stmt|;
name|byte
name|fe_soft_vers
decl_stmt|;
name|byte
name|fe_diag_status
decl_stmt|;
block|}
name|GP_REG3_USAGE
typedef|;
end_typedef

begin_decl_stmt
name|PRIVATE
name|u_short
name|ddastd
index|[]
init|=
block|{
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* standard addresses */
end_comment

begin_comment
comment|/* ddainfo is setup by OS */
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
block|,
comment|/* ptr to device info ptrs */
literal|"dda"
block|,
comment|/* device name */
literal|0
block|}
decl_stmt|;
end_decl_stmt

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
comment|/*  This routine is pretty much a dummy.  The real probe is done   */
end_comment

begin_comment
comment|/*  the operating system.					   */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*  Call:          ddaprobe(ui)	                                   */
end_comment

begin_comment
comment|/*  Argument:	   ui:   pointer to device data structure, used    */
end_comment

begin_comment
comment|/*                       for BI environment                        */
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
name|PRIVATE
name|int
name|savefirmrev
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* save between probe& attach */
end_comment

begin_macro
name|ddaprobe
argument_list|(
argument|nxv
argument_list|,
argument|nxp
argument_list|,
argument|cpup
argument_list|,
argument|binumber
argument_list|,
argument|binode
argument_list|,
argument|ui
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|bi_nodespace
modifier|*
name|nxv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|nxp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|cpusw
modifier|*
name|cpup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|binumber
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|binode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|GP_REG3_USAGE
modifier|*
name|gpreg3
decl_stmt|;
comment|/* check to see if this board was in system configuration */
if|if
condition|(
name|ui
operator|->
name|ui_unit
operator|>
name|NDDA
condition|)
return|return
literal|0
return|;
comment|/* extra board? punt */
name|gpreg3
operator|=
operator|(
name|GP_REG3_USAGE
operator|*
operator|)
operator|&
name|nxv
operator|->
name|biic
operator|.
name|biic_gpr3
expr_stmt|;
comment|/* check that the device is really a 7250 and save away */
comment|/* the firmware revision level for version dependent processing */
comment|/* If we just booted, the diagnostics may still be running as we */
comment|/* probe the device - it's still OK to read the ID and VERSION */
comment|/* numbers, which come valid within milliseconds after power is */
comment|/* applied to the board - so say the firmware gurus */
name|dda_hasmaint
operator|=
name|gpreg3
operator|->
name|fe_soft_vers
operator|&
literal|0x80
expr_stmt|;
name|savefirmrev
operator|=
name|gpreg3
operator|->
name|fe_soft_vers
operator|&
literal|0x7f
expr_stmt|;
switch|switch
condition|(
name|gpreg3
operator|->
name|fe_soft_id
condition|)
block|{
case|case
literal|0x68
case|:
name|dda_product
operator|=
literal|"ACP7250"
expr_stmt|;
break|break;
default|default:
ifdef|#
directive|ifdef
name|notdef
if|if
condition|(
name|dda_hasmaint
operator|==
literal|0
condition|)
comment|/* assume we know what we're doing */
return|return
literal|0
return|;
name|savefirmrev
operator|=
literal|255
expr_stmt|;
comment|/* assume high version */
name|dda_product
operator|=
literal|"ACP7250"
expr_stmt|;
break|break;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
return|return
literal|1
return|;
comment|/* return that we have found a board and are happy */
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
comment|/*-- 	Various other types of one-time initialization: 	    - allocate memory and setup queues 								 --*/
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
name|SYSGEN_BLOCK
modifier|*
name|SysGenPtr
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
name|dda_firmrev
operator|=
name|savefirmrev
expr_stmt|;
comment|/* saved firmware rev level */
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
name|initmsgs
argument_list|,
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
comment|/* allocate shared memory segment */
name|KM_ALLOC
argument_list|(
name|SysGenPtr
argument_list|,
name|SYSGEN_BLOCK
operator|*
argument_list|,
literal|1024
argument_list|,
name|KM_CLUSTER
argument_list|,
name|KM_NOWAIT
argument_list|)
expr_stmt|;
if|if
condition|(
name|SysGenPtr
operator|==
name|NULL
condition|)
block|{
name|DMESG
argument_list|(
name|ui
operator|->
name|ui_unit
argument_list|,
literal|0
argument_list|,
operator|(
name|DDALOG
argument_list|(
name|LOG_ERR
argument_list|)
literal|"dda%d: unable to get shared memory segment\n"
operator|,
name|ui
operator|->
name|ui_unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ds
operator|->
name|dda_mapreg
operator|=
operator|(
name|int
operator|)
name|SysGenPtr
expr_stmt|;
comment|/* save it in ds structure */
comment|/* hook the interrupt vector to scb */
ifndef|#
directive|ifndef
name|SIMULATION
name|bidev_vec
argument_list|(
name|ui
operator|->
name|ui_adpt
argument_list|,
name|ui
operator|->
name|ui_nexus
argument_list|,
name|LEVEL14
argument_list|,
name|ui
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dda_shm_setup
argument_list|(
name|ui
operator|->
name|ui_unit
argument_list|,
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
argument_list|,
name|SYSGEN_VALID
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

begin_function
name|PRIVATE
name|void
name|dda_shm_setup
parameter_list|(
name|unit
parameter_list|,
name|nxv
parameter_list|,
name|drvr_state
parameter_list|)
name|int
name|unit
decl_stmt|;
name|struct
name|biic_regs
modifier|*
name|nxv
decl_stmt|;
name|int
name|drvr_state
decl_stmt|;
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
name|unit
index|]
decl_stmt|;
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|ddainfo
index|[
name|unit
index|]
decl_stmt|;
name|SYSGEN_BLOCK
modifier|*
name|SysGenPtr
decl_stmt|;
name|char
modifier|*
name|mem
decl_stmt|;
name|SysGenPtr
operator|=
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
expr_stmt|;
name|mem
operator|=
operator|(
name|char
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
expr_stmt|;
name|SysGenPtr
operator|->
name|request
operator|=
operator|(
name|RQUEUE
operator|*
operator|)
operator|&
name|mem
index|[
literal|512
operator|-
literal|4
index|]
expr_stmt|;
comment|/* get entries on page */
name|SysGenPtr
operator|->
name|completion
operator|=
operator|(
name|CQUEUE
operator|*
operator|)
operator|&
name|mem
index|[
sizeof|sizeof
argument_list|(
name|SYSGEN_BLOCK
argument_list|)
operator|+
literal|7
operator|&
literal|0xff7c
index|]
expr_stmt|;
name|SysGenPtr
operator|->
name|prequest
operator|=
name|svtophy
argument_list|(
name|SysGenPtr
operator|->
name|request
argument_list|)
expr_stmt|;
name|SysGenPtr
operator|->
name|pcompletion
operator|=
name|svtophy
argument_list|(
name|SysGenPtr
operator|->
name|completion
argument_list|)
expr_stmt|;
name|SysGenPtr
operator|->
name|req_size
operator|=
name|RQSIZE
expr_stmt|;
name|SysGenPtr
operator|->
name|comp_size
operator|=
name|CQSIZE
expr_stmt|;
name|SysGenPtr
operator|->
name|intr_level
operator|=
literal|0
expr_stmt|;
comment|/* level 0 is lowest level */
name|SysGenPtr
operator|->
name|pwr_action
operator|=
literal|0
expr_stmt|;
comment|/* boot default code */
name|SysGenPtr
operator|->
name|previous_unload
operator|=
name|UL_NOT_BLOCKED
expr_stmt|;
comment|/* request queue not blocked */
name|SysGenPtr
operator|->
name|request
operator|->
name|load
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|request
operator|->
name|unload
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|completion
operator|->
name|load
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|completion
operator|->
name|unload
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
name|SysGenPtr
operator|->
name|completion
operator|->
name|entry
argument_list|,
sizeof|sizeof
argument_list|(
name|CENTRY
argument_list|)
operator|*
name|CQSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|SysGenPtr
operator|->
name|request
operator|->
name|entry
argument_list|,
sizeof|sizeof
argument_list|(
name|RENTRY
argument_list|)
operator|*
name|RQSIZE
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|SIMULATION
comment|/* set interrupt destination */
name|nxv
operator|->
name|biic_int_dst
operator|=
name|bidata
index|[
name|ui
operator|->
name|ui_adpt
index|]
operator|.
name|biintr_dst
expr_stmt|;
endif|#
directive|endif
name|nxv
operator|->
name|biic_err
operator|=
name|nxv
operator|->
name|biic_err
expr_stmt|;
comment|/* actually clears error reg */
name|nxv
operator|->
name|biic_gpr1
operator|=
name|svtophy
argument_list|(
name|SysGenPtr
argument_list|)
expr_stmt|;
comment|/* get BI physical address */
name|nxv
operator|->
name|biic_gpr0
operator|=
name|drvr_state
expr_stmt|;
comment|/* tell FE our state */
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|DDADEBUG
end_ifdef

begin_function
name|PRIVATE
name|void
name|dda_dump_biic_regs
parameter_list|(
name|nxv
parameter_list|)
name|struct
name|biic_regs
modifier|*
name|nxv
decl_stmt|;
block|{
name|uprintf
argument_list|(
literal|"biic register dump (nxv=0x%x 0x%x(p))\n"
argument_list|,
name|nxv
argument_list|,
name|svtophy
argument_list|(
name|nxv
argument_list|)
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"typ=0x%x ctrl=0x%x err=0x%x err_int=0x%x\n"
argument_list|,
name|nxv
operator|->
name|biic_typ
argument_list|,
name|nxv
operator|->
name|biic_ctrl
argument_list|,
name|nxv
operator|->
name|biic_err
argument_list|,
name|nxv
operator|->
name|biic_err_int
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"int_dst=0x%x ip_msk=0x%x ip_dst=0x%x ip_src=0x%x\n"
argument_list|,
name|nxv
operator|->
name|biic_int_dst
argument_list|,
name|nxv
operator|->
name|biic_ip_dst
argument_list|,
name|nxv
operator|->
name|biic_ip_dst
argument_list|,
name|nxv
operator|->
name|biic_ip_src
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"strt=0x%x end=0x%x bci_ctrl=0x%x wrt_stat=0x%x\n"
argument_list|,
name|nxv
operator|->
name|biic_strt
argument_list|,
name|nxv
operator|->
name|biic_end
argument_list|,
name|nxv
operator|->
name|biic_bci_ctrl
argument_list|,
name|nxv
operator|->
name|biic_wrt_stat
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"int_ctrl=0x%x\n"
argument_list|,
name|nxv
operator|->
name|biic_int_ctrl
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"gpr0=0x%x gpr1=0x%x gpr2=0x%x gpr3=0x%x\n"
argument_list|,
name|nxv
operator|->
name|biic_gpr0
argument_list|,
name|nxv
operator|->
name|biic_gpr1
argument_list|,
name|nxv
operator|->
name|biic_gpr2
argument_list|,
name|nxv
operator|->
name|biic_gpr3
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|PRIVATE
name|void
name|dda_dump_shm
parameter_list|(
name|shm
parameter_list|)
name|SYSGEN_BLOCK
modifier|*
name|shm
decl_stmt|;
block|{
name|uprintf
argument_list|(
literal|"request=0x%x 0x%x(p) completion=0x%x 0x%x(p)\n"
argument_list|,
name|shm
operator|->
name|request
argument_list|,
name|shm
operator|->
name|prequest
argument_list|,
name|shm
operator|->
name|completion
argument_list|,
name|shm
operator|->
name|pcompletion
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"req_size=%d comp_size=%d intr_level=%d pwr_act=%d\n"
argument_list|,
name|shm
operator|->
name|req_size
argument_list|,
name|shm
operator|->
name|comp_size
argument_list|,
name|shm
operator|->
name|intr_level
argument_list|,
name|shm
operator|->
name|pwr_action
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"req_load=%d req_un=%d comp_load=%d comp_ul=%d prev=%d\n"
argument_list|,
name|shm
operator|->
name|request
operator|->
name|load
argument_list|,
name|shm
operator|->
name|request
operator|->
name|unload
argument_list|,
name|shm
operator|->
name|completion
operator|->
name|load
argument_list|,
name|shm
operator|->
name|completion
operator|->
name|unload
argument_list|,
name|shm
operator|->
name|previous_unload
argument_list|)
expr_stmt|;
name|uprintf
argument_list|(
literal|"request queue is%s blocked\n"
argument_list|,
operator|(
name|shm
operator|->
name|previous_unload
operator|==
name|UL_NOT_BLOCKED
condition|?
literal|" not"
else|:
literal|""
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

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
comment|/*      Reset of interface.  Free mbufs if there is		   */
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
comment|/*		       uban:   Unibus adapter # (unused, but the   */
end_comment

begin_comment
comment|/*				kernel placed it on the stack)	   */
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
comment|/*		       hist_link_state()			   */
end_comment

begin_comment
comment|/*		       hist_all_lcns()				   */
end_comment

begin_comment
comment|/*		       dda_shm_setup()			           */
end_comment

begin_comment
comment|/*                                                                 */
end_comment

begin_comment
comment|/*##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
end_comment

begin_comment
comment|/*ARGSUSED*/
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
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uban
decl_stmt|;
end_decl_stmt

begin_block
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
literal|"dda%d: reset\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|dda_unit_reset
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|,
name|SYSGEN_VALID
argument_list|)
expr_stmt|;
block|}
end_block

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
literal|"dda%d: buffer reset\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|dda_unit_reset
argument_list|(
name|unit
argument_list|,
literal|0
argument_list|,
name|SYSGEN_VALID
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|PRIVATE
name|void
name|dda_unit_reset
parameter_list|(
name|unit
parameter_list|,
name|doreset
parameter_list|,
name|drvr_state
parameter_list|)
name|int
name|unit
decl_stmt|;
name|int
name|doreset
decl_stmt|;
name|int
name|drvr_state
decl_stmt|;
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|ddainfo
index|[
name|unit
index|]
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
name|int
name|lcn
decl_stmt|;
name|struct
name|biic_regs
modifier|*
name|nxv
decl_stmt|;
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
name|nxv
operator|=
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
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
comment|/* reset the board */
if|if
condition|(
name|doreset
condition|)
name|nxv
operator|->
name|biic_ctrl
operator|=
name|BICTRL_STS
operator||
name|BICTRL_SST
expr_stmt|;
name|DELAY
argument_list|(
literal|50000
argument_list|)
expr_stmt|;
comment|/* delay 50ms for BIIC to run tests */
name|ds
operator|->
name|dda_flags
operator|=
literal|0
expr_stmt|;
comment|/* clear ACP operational flag  */
comment|/* which will get us ready for B int */
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
name|ds
operator|->
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
name|dda_shm_setup
argument_list|(
name|unit
argument_list|,
name|nxv
argument_list|,
name|drvr_state
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
comment|/*  Calls to:         ddatimer()                                   */
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
specifier|register
name|struct
name|dda_softc
modifier|*
name|ds
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
name|int
name|lcn
decl_stmt|,
name|s
decl_stmt|;
name|ds
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
expr_stmt|;
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
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: ds->dda_if.if_addrlist=0x%x ds->dda_flags=0x%x\n"
operator|,
name|unit
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_addrlist
operator|,
name|ds
operator|->
name|dda_flags
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/* if we have no internet addr  if device not operational don't init yet */
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
return|return;
comment|/* set default options */
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
comment|/*    handshake events to process. Two types of interrupts are	   */
end_comment

begin_comment
comment|/*    processed:  I/O request acknowledge, and I/O completion.     */
end_comment

begin_comment
comment|/*    The interrupting HDX channel and interrupt type are	   */
end_comment

begin_comment
comment|/*    obtained. If interrupt is an I/O request acknowledge the	   */
end_comment

begin_comment
comment|/*    next I/O request is passed to the device.  If the interrupt  */
end_comment

begin_comment
comment|/*    is an I/O completion, check for errors, if ok process	   */
end_comment

begin_comment
comment|/*    according to whether supervisory or data channel.		   */
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
specifier|register
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
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
decl_stmt|;
name|CQUEUE
modifier|*
name|complq
decl_stmt|;
name|CENTRY
modifier|*
name|centry_ptr
decl_stmt|;
name|byte
name|flags
decl_stmt|;
name|int
name|chan
decl_stmt|,
name|cc
decl_stmt|,
name|subcc
decl_stmt|,
name|cnt
decl_stmt|;
name|SYSGEN_BLOCK
modifier|*
name|SysGenPtr
decl_stmt|;
name|ds
operator|=
operator|&
name|dda_softc
index|[
name|unit
index|]
expr_stmt|;
name|SysGenPtr
operator|=
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
expr_stmt|;
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
comment|/***********************************************************************/
comment|/* Check Request Queue if xmt was blocked				   */
comment|/***********************************************************************/
comment|/* was request queue blocked before? (previous unload = a blocked value) */
if|if
condition|(
name|SysGenPtr
operator|->
name|previous_unload
operator|!=
name|UL_NOT_BLOCKED
condition|)
block|{
comment|/* yes, so check to see if unload pointer has changed */
if|if
condition|(
name|SysGenPtr
operator|->
name|previous_unload
operator|!=
name|SysGenPtr
operator|->
name|request
operator|->
name|unload
condition|)
block|{
comment|/* if the unload pointer changed, we're no longer blocked */
name|SysGenPtr
operator|->
name|previous_unload
operator|=
name|UL_NOT_BLOCKED
expr_stmt|;
name|start_chn
argument_list|(
name|ds
argument_list|)
expr_stmt|;
comment|/* re-start I/O */
block|}
block|}
comment|/***********************************************************************/
comment|/* Check I/O Completion Queue                                          */
comment|/***********************************************************************/
name|complq
operator|=
name|SysGenPtr
operator|->
name|completion
expr_stmt|;
comment|/* point to completion q */
name|centry_ptr
operator|=
name|complq
operator|->
name|entry
operator|+
name|complq
operator|->
name|unload
expr_stmt|;
comment|/* new entry valid? I/O Completion Mailbox */
while|while
condition|(
operator|(
name|flags
operator|=
name|centry_ptr
operator|->
name|flags
operator|)
operator|&
name|CENTRY_VALID
condition|)
block|{
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
name|centry_ptr
operator|->
name|flags
operator|=
literal|0
expr_stmt|;
comment|/* clear valid bit */
comment|/* Get logical channel information. */
name|chan
operator|=
name|centry_ptr
operator|->
name|dpn
expr_stmt|;
if|if
condition|(
name|chan
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
goto|goto
name|bump_unload
goto|;
block|}
if|if
condition|(
name|flags
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
name|centry_ptr
operator|->
name|stat
expr_stmt|;
comment|/* Mailbox I/O completion status */
name|subcc
operator|=
name|centry_ptr
operator|->
name|sbstat
expr_stmt|;
comment|/* Mailbox I/O completion substatus */
name|cnt
operator|=
name|centry_ptr
operator|->
name|count
expr_stmt|;
comment|/* Mailbox I/O completion byte count */
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|33
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
name|prt_bytes
argument_list|(
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|,
literal|"incoming data"
argument_list|,
name|hc
operator|->
name|hc_curr
argument_list|,
name|cnt
argument_list|)
expr_stmt|;
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
literal|"dda%d: program error\n"
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
literal|"dda%d: overrun error\n"
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
literal|"dda%d: transfer count = 0\n"
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
literal|"dda%d: DMA completion error (%x)\n"
operator|,
name|unit
operator|,
name|subcc
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
literal|"dda%d: listen collision\n"
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
literal|"dda%d: invalid function\n"
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
literal|"dda%d: invalid dpn\n"
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
name|bump_unload
label|:
comment|/* Ack the interrupt.  Fix the Mailbox Ready and Done bits:  set DON 	   bits, and clear RDY bits so mailbox may be reused. */
name|complq
operator|->
name|unload
operator|=
operator|(
name|complq
operator|->
name|unload
operator|+
literal|1
operator|)
operator|%
name|CQSIZE
expr_stmt|;
name|centry_ptr
operator|=
name|complq
operator|->
name|entry
operator|+
name|complq
operator|->
name|unload
expr_stmt|;
block|}
block|}
end_block

begin_escape
end_escape

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
specifier|register
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|struct
name|biic_regs
modifier|*
name|nxv
init|=
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ddainfo
index|[
name|unit
index|]
operator|->
name|ui_addr
decl_stmt|;
name|int
name|stat_val
decl_stmt|;
name|stat_val
operator|=
operator|(
operator|(
name|GP_REG3_USAGE
operator|*
operator|)
operator|&
name|nxv
operator|->
name|biic_gpr3
operator|)
operator|->
name|fe_diag_status
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
name|stat_val
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
literal|0
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|(
name|stat_val
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
name|stat_val
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
name|dda_disable
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|stat_val
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
name|dda_disable
argument_list|(
name|unit
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|stat_val
operator|==
name|DDASTAT_OK
condition|)
block|{
name|SYSGEN_BLOCK
modifier|*
name|SysGenPtr
init|=
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
decl_stmt|;
name|ds
operator|->
name|dda_flags
operator||=
name|DDAF_OK
expr_stmt|;
comment|/* no longer expecting a B interrupt */
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
comment|/* clear output queue */
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
comment|/* free read mbufs */
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
comment|/* free write mbufs */
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
name|SysGenPtr
operator|->
name|request
operator|->
name|load
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|request
operator|->
name|unload
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|completion
operator|->
name|load
operator|=
literal|0
expr_stmt|;
name|SysGenPtr
operator|->
name|completion
operator|->
name|unload
operator|=
literal|0
expr_stmt|;
name|bzero
argument_list|(
name|SysGenPtr
operator|->
name|completion
operator|->
name|entry
argument_list|,
sizeof|sizeof
argument_list|(
name|CENTRY
argument_list|)
operator|*
name|CQSIZE
argument_list|)
expr_stmt|;
name|bzero
argument_list|(
name|SysGenPtr
operator|->
name|request
operator|->
name|entry
argument_list|,
sizeof|sizeof
argument_list|(
name|RENTRY
argument_list|)
operator|*
name|RQSIZE
argument_list|)
expr_stmt|;
name|SysGenPtr
operator|->
name|pwr_action
operator|=
literal|0xff
expr_stmt|;
comment|/* we are operational */
comment|/* this 10ms delay is here to give the FEP enough time to re-program 	   its interrupt vector to point to the A interrupt routine and 	   reset the MFP interrupt counter before the driver posts the 	   NDDACH reads in ddainit.  It's a kludge, but keep it for safety */
name|DELAY
argument_list|(
literal|10000
argument_list|)
expr_stmt|;
comment|/* delay 10 miliseconds */
name|ddainit
argument_list|(
name|unit
argument_list|)
expr_stmt|;
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
else|else
name|hc
operator|->
name|hc_func
operator|=
name|DDAWRT
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
comment|/*                   MCLGET()                                      */
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
if|#
directive|if
name|ACC_ULTRIX
operator|>
literal|12
name|struct
name|mbuf
modifier|*
name|p
decl_stmt|;
endif|#
directive|endif
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
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
comment|/* hc_mbuf set to zero during initialization */
comment|/* if hc->hc_mbuf is zero, then this is the first mbuf in the chain,        so be conservative and only queue up a small mbuf */
if|if
condition|(
name|hc
operator|->
name|hc_mbuf
operator|==
literal|0
condition|)
block|{
name|m
operator|->
name|m_len
operator|=
name|MLEN
expr_stmt|;
comment|/* set the size to a small mbuf */
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
comment|/* if it's not the first mbuf in the chain, we may be running a FTP        or something that deserves higher performance, so queue a cluster */
block|}
else|else
block|{
if|#
directive|if
name|ACC_ULTRIX
operator|>
literal|12
name|MCLGET
argument_list|(
name|m
argument_list|,
name|p
argument_list|)
expr_stmt|;
comment|/* associate a page cluster with this mbuf */
else|#
directive|else
name|MCLGET
argument_list|(
name|m
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
expr_stmt|;
name|hc
operator|->
name|hc_sbfc
operator|=
literal|0
expr_stmt|;
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
name|struct
name|biic_regs
modifier|*
name|nxv
decl_stmt|;
name|RQUEUE
modifier|*
name|requestq
decl_stmt|;
name|short
name|next_load
decl_stmt|;
name|SYSGEN_BLOCK
modifier|*
name|SysGenPtr
decl_stmt|;
name|SysGenPtr
operator|=
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
operator|(
name|ds
operator|->
name|dda_mapreg
operator|)
expr_stmt|;
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
name|nxv
operator|=
operator|(
expr|struct
name|biic_regs
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
name|s
operator|=
name|splimp
argument_list|()
expr_stmt|;
while|while
condition|(
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
condition|)
block|{
name|requestq
operator|=
name|SysGenPtr
operator|->
name|request
expr_stmt|;
name|next_load
operator|=
operator|(
name|requestq
operator|->
name|load
operator|+
literal|1
operator|)
operator|%
name|RQSIZE
expr_stmt|;
if|if
condition|(
name|next_load
operator|==
name|requestq
operator|->
name|unload
condition|)
block|{
comment|/* any room left in q? */
comment|/* no, say we're blocked */
name|SysGenPtr
operator|->
name|previous_unload
operator|=
name|requestq
operator|->
name|unload
expr_stmt|;
break|break;
block|}
comment|/*  *  Check sioq for invalid writes  */
comment|/* if write channel, but not supervisor, and it's marked invalid, 	   then either drop or abort it */
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
block|{
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
endif|#
directive|endif
endif|DDADEBUG
goto|goto
name|send
goto|;
comment|/* send an abort if output not complete */
block|}
else|else
block|{
comment|/* otherwise free it */
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
block|}
comment|/*  * Restart Output  */
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
comment|/* The following call may cause a re-entrant call to 		   start_chn, but only if the sioq is currently empty. In 		   that case, the re-entrant call is ok */
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
continue|continue;
block|}
block|}
name|send
label|:
block|{
comment|/* Read or Write request is valid */
name|RENTRY
modifier|*
name|rentry_ptr
decl_stmt|;
name|int
name|index
decl_stmt|;
comment|/* Set up queue element */
name|rentry_ptr
operator|=
name|requestq
operator|->
name|entry
operator|+
name|requestq
operator|->
name|load
expr_stmt|;
comment|/* Fill the slots starting at hc->hc_curr */
name|rentry_ptr
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|index
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|33
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|int
name|i
decl_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"hc->hc_mbuf=0x%x hc->hc_curr=0x%x\n"
operator|,
name|hc
operator|->
name|hc_mbuf
operator|,
name|hc
operator|->
name|hc_curr
name|DDAELOG
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|m
operator|=
name|hc
operator|->
name|hc_mbuf
init|;
name|m
operator|&&
name|m
operator|!=
name|hc
operator|->
name|hc_curr
condition|;
name|i
operator|++
operator|,
name|m
operator|=
name|m
operator|->
name|m_next
control|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"previous(%d): 0x%x\n"
operator|,
name|i
operator|,
name|m
name|DDAELOG
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|m
operator|=
name|hc
operator|->
name|hc_curr
init|;
name|m
condition|;
name|i
operator|++
operator|,
name|m
operator|=
name|m
operator|->
name|m_next
control|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"chain(%d): 0x%x\n"
operator|,
name|i
operator|,
name|m
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
comment|/* if it's a write, map as many mbufs on as we can */
if|if
condition|(
name|hc
operator|->
name|hc_chan
operator|&
literal|1
condition|)
block|{
specifier|register
name|struct
name|mbuf
modifier|*
name|last_mapped
decl_stmt|;
while|while
condition|(
name|hc
operator|->
name|hc_curr
condition|)
block|{
specifier|register
name|int
name|len
decl_stmt|,
name|seglen
decl_stmt|,
name|pages
decl_stmt|;
specifier|register
name|char
modifier|*
name|addr
decl_stmt|;
name|addr
operator|=
name|mtod
argument_list|(
name|hc
operator|->
name|hc_curr
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
name|len
operator|=
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
expr_stmt|;
name|pages
operator|=
operator|(
name|len
operator|-
literal|1
operator|>>
name|PGSHIFT
operator|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"start_chn: len was zero?!?\n"
argument_list|)
expr_stmt|;
comment|/* If we have enough slots left in this entry to map this 		       mbuf,  then do so */
if|if
condition|(
name|NUM_BI_ADDR
operator|-
name|index
operator|>
name|pages
condition|)
block|{
while|while
condition|(
operator|(
name|seglen
operator|=
name|MIN
argument_list|(
name|NBPG
argument_list|,
name|len
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|rentry_ptr
operator|->
name|BI_address
index|[
name|index
index|]
operator|=
name|svtophy
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_count
index|[
name|index
index|]
operator|=
name|seglen
expr_stmt|;
name|rentry_ptr
operator|->
name|count
operator|+=
name|seglen
expr_stmt|;
name|len
operator|-=
name|seglen
expr_stmt|;
name|addr
operator|+=
name|seglen
expr_stmt|;
name|index
operator|++
expr_stmt|;
block|}
comment|/* we've mapped this mbuf onto the queue, deal with next */
name|last_mapped
operator|=
name|hc
operator|->
name|hc_curr
expr_stmt|;
name|hc
operator|->
name|hc_curr
operator|=
name|hc
operator|->
name|hc_curr
operator|->
name|m_next
expr_stmt|;
block|}
else|else
block|{
comment|/* if this buffer can't ever fit, there is a major 			   problem (someone changed the size of a large mbuf 			   so it can't fit in NUM_BI_ADDR memory pages).  This 			   should never happen. */
if|if
condition|(
name|index
operator|==
literal|0
condition|)
name|panic
argument_list|(
literal|"dda driver: mbuf too large to map\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* if more mbufs to map, we're not at the end of stream */
if|if
condition|(
name|hc
operator|->
name|hc_curr
condition|)
name|hc
operator|->
name|hc_func
operator||=
name|DDASTR
expr_stmt|;
else|else
name|hc
operator|->
name|hc_func
operator||=
name|DDAEOS
expr_stmt|;
comment|/* higher up routines expect hc->hc_curr to be the last 		   mapped mbuf */
name|hc
operator|->
name|hc_curr
operator|=
name|last_mapped
expr_stmt|;
block|}
else|else
block|{
comment|/* otherwise it's a read, so process the one mbuf */
specifier|register
name|int
name|len
decl_stmt|,
name|seglen
decl_stmt|,
name|pages
decl_stmt|;
specifier|register
name|char
modifier|*
name|addr
decl_stmt|;
name|addr
operator|=
name|mtod
argument_list|(
name|hc
operator|->
name|hc_curr
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
name|len
operator|=
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
expr_stmt|;
name|pages
operator|=
operator|(
name|len
operator|-
literal|1
operator|>>
name|PGSHIFT
operator|)
operator|+
literal|1
expr_stmt|;
comment|/* if it's a read, zero out the mbuf's m_len field because 		   the mbuf currently contains no valid data */
name|hc
operator|->
name|hc_curr
operator|->
name|m_len
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
name|printf
argument_list|(
literal|"start_chn: len was zero?!?\n"
argument_list|)
expr_stmt|;
comment|/* If we have enough slots left in this entry to map this 		   mbuf,  then do so */
if|if
condition|(
name|NUM_BI_ADDR
operator|>=
name|pages
condition|)
while|while
condition|(
operator|(
name|seglen
operator|=
name|MIN
argument_list|(
name|NBPG
argument_list|,
name|len
argument_list|)
operator|)
operator|>
literal|0
condition|)
block|{
name|rentry_ptr
operator|->
name|BI_address
index|[
name|index
index|]
operator|=
name|svtophy
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_count
index|[
name|index
index|]
operator|=
name|seglen
expr_stmt|;
name|rentry_ptr
operator|->
name|count
operator|+=
name|seglen
expr_stmt|;
name|len
operator|-=
name|seglen
expr_stmt|;
name|addr
operator|+=
name|seglen
expr_stmt|;
name|index
operator|++
expr_stmt|;
block|}
comment|/* if this buffer can't ever fit, there is a major problem 		   (someone changed the size of a large mbuf so it can't 		   fit in NUM_BI_ADDR memory pages).  This should never 		   happen. */
else|else
name|panic
argument_list|(
literal|"dda driver: mbuf too large to map\n"
argument_list|)
expr_stmt|;
block|}
name|rentry_ptr
operator|->
name|opcode
operator|=
name|CMD_MPCPRQS
expr_stmt|;
name|rentry_ptr
operator|->
name|dpn
operator|=
name|hc
operator|->
name|hc_chan
operator|>>
literal|1
expr_stmt|;
name|rentry_ptr
operator|->
name|func
operator|=
name|hc
operator|->
name|hc_func
expr_stmt|;
name|rentry_ptr
operator|->
name|sbfunc
operator|=
name|hc
operator|->
name|hc_sbfc
expr_stmt|;
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|34
argument_list|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
argument_list|)
condition|)
block|{
name|int
name|i
decl_stmt|;
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dpn=0x%x func=0x%x sbfunc=0x%x count=0x%x index=%d\n"
operator|,
name|rentry_ptr
operator|->
name|dpn
operator|,
name|rentry_ptr
operator|->
name|func
operator|,
name|rentry_ptr
operator|->
name|sbfunc
operator|,
name|rentry_ptr
operator|->
name|count
operator|,
name|index
name|DDAELOG
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_BI_ADDR
condition|;
name|i
operator|++
control|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"addr[%d]=0x%x count[%d]=0x%x\n"
operator|,
name|rentry_ptr
operator|->
name|BI_address
index|[
name|i
index|]
operator|,
name|rentry_ptr
operator|->
name|BI_count
index|[
name|i
index|]
name|DDAELOG
expr_stmt|;
block|}
endif|#
directive|endif
endif|DDADEBUG
ifdef|#
directive|ifdef
name|DDADEBUG
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
name|struct
name|dda_cb
modifier|*
name|dc
decl_stmt|;
name|dc
operator|=
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
expr_stmt|;
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
comment|/* Wait 90 sec for completion */
block|}
if|if
condition|(
name|DDADBCH
argument_list|(
literal|30
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
literal|"dda%d: interrupting FE\n"
operator|,
name|ds
operator|->
name|dda_if
operator|.
name|if_unit
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
comment|/* TELL 7000 about new entry in request queue */
name|requestq
operator|->
name|load
operator|=
name|next_load
expr_stmt|;
comment|/* boom! */
name|nxv
operator|->
name|biic_gpr0
operator|=
name|SYSGEN_VALID
expr_stmt|;
comment|/* interrupt FE */
ifdef|#
directive|ifdef
name|SIMULATION
name|MFP_COUNTER_SIM
argument_list|()
expr_stmt|;
comment|/* simulate hardware action */
endif|#
directive|endif
block|}
name|next_sioq_element
label|:
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
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/*  * disable interrupts and forget about unit  */
end_comment

begin_function
name|PRIVATE
name|void
name|dda_disable
parameter_list|(
name|unit
parameter_list|)
name|int
name|unit
decl_stmt|;
block|{
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|ddainfo
index|[
name|unit
index|]
decl_stmt|;
name|struct
name|biic_regs
modifier|*
name|nxv
decl_stmt|;
name|nxv
operator|=
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
expr_stmt|;
name|nxv
operator|->
name|biic_int_dst
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_function
name|PRIVATE
name|int
name|dda_dload
parameter_list|(
name|unit
parameter_list|,
name|dl
parameter_list|)
name|int
name|unit
decl_stmt|;
name|struct
name|dda_dnload
modifier|*
name|dl
decl_stmt|;
block|{
specifier|register
name|struct
name|uba_device
modifier|*
name|ui
init|=
name|ddainfo
index|[
name|unit
index|]
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|static
name|unsigned
name|char
modifier|*
name|dlbuf
index|[
name|RQSIZE
index|]
decl_stmt|;
if|if
condition|(
name|unit
operator|>=
name|NDDA
condition|)
return|return
name|EFAULT
return|;
switch|switch
condition|(
name|dl
operator|->
name|lcommand
condition|)
block|{
case|case
name|DN_LCMD_SETUP
case|:
comment|/* allocate buffers, reset board/setup shared memory */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|RQSIZE
condition|;
name|i
operator|++
control|)
block|{
name|KM_ALLOC
argument_list|(
argument|dlbuf[i]
argument_list|,
argument|unsigned char *
argument_list|,
literal|512
argument_list|,
argument|KM_CLUSTER
argument_list|,
argument|KM_NOWAIT
argument_list|)
empty_stmt|;
if|if
condition|(
name|dlbuf
index|[
name|i
index|]
operator|==
name|NULL
condition|)
return|return
name|ENOMEM
return|;
block|}
name|dda_unit_reset
argument_list|(
name|unit
argument_list|,
literal|1
argument_list|,
name|SYSGEN_DLOAD
argument_list|)
expr_stmt|;
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
literal|"dda%d: download mode\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
case|case
name|DN_LCMD_CLEANUP
case|:
comment|/* deallocate buffers and restore shm to normal */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|RQSIZE
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|dlbuf
index|[
name|i
index|]
condition|)
name|KM_FREE
argument_list|(
name|dlbuf
index|[
name|i
index|]
argument_list|,
name|KM_CLUSTER
argument_list|)
expr_stmt|;
name|dda_shm_setup
argument_list|(
name|unit
argument_list|,
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
argument_list|,
name|SYSGEN_VALID
argument_list|)
expr_stmt|;
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
literal|"dda%d: operational mode\n"
operator|,
name|unit
name|DDAELOG
operator|)
argument_list|)
expr_stmt|;
comment|/* now we will expect a B interrupt from the unit which will 	       cause ddainit to be called and set up the driver */
return|return
literal|0
return|;
case|case
name|DN_LCMD_FEOP
case|:
block|{
comment|/* perform a front end operation */
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
name|struct
name|biic_regs
modifier|*
name|nxv
init|=
operator|(
expr|struct
name|biic_regs
operator|*
operator|)
name|ui
operator|->
name|ui_addr
decl_stmt|;
specifier|register
name|RQUEUE
modifier|*
name|requestq
decl_stmt|;
specifier|register
name|RENTRY
modifier|*
name|rentry_ptr
decl_stmt|;
specifier|register
name|unsigned
name|checksum
decl_stmt|;
specifier|register
name|unsigned
name|char
modifier|*
name|buffer
decl_stmt|;
name|short
name|next_load
decl_stmt|;
name|requestq
operator|=
operator|(
operator|(
name|SYSGEN_BLOCK
operator|*
operator|)
name|ds
operator|->
name|dda_mapreg
operator|)
operator|->
name|request
expr_stmt|;
name|next_load
operator|=
operator|(
name|requestq
operator|->
name|load
operator|+
literal|1
operator|)
operator|%
name|RQSIZE
expr_stmt|;
if|if
condition|(
name|next_load
operator|==
name|requestq
operator|->
name|unload
condition|)
block|{
comment|/* any room left in q? */
comment|/* no, say we're blocked */
return|return
name|ENOMEM
return|;
block|}
name|rentry_ptr
operator|=
name|requestq
operator|->
name|entry
operator|+
name|requestq
operator|->
name|load
expr_stmt|;
switch|switch
condition|(
name|dl
operator|->
name|type
condition|)
block|{
case|case
name|DN_TYPE_DATA
case|:
case|case
name|DN_TYPE_ID
case|:
case|case
name|DN_TYPE_VER
case|:
case|case
name|DN_TYPE_COPY
case|:
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|29
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: xfr type=%d buf=%d len=%d dest=0x%x\n"
operator|,
name|unit
operator|,
name|dl
operator|->
name|type
operator|,
name|requestq
operator|->
name|load
operator|,
name|dl
operator|->
name|len
operator|,
name|dl
operator|->
name|dest
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|buffer
operator|=
name|dlbuf
index|[
name|requestq
operator|->
name|load
index|]
expr_stmt|;
if|if
condition|(
name|copyin
argument_list|(
name|dl
operator|->
name|data
argument_list|,
name|buffer
argument_list|,
name|dl
operator|->
name|len
argument_list|)
condition|)
return|return
name|EFAULT
return|;
comment|/* Set up queue element */
name|rentry_ptr
operator|->
name|opcode
operator|=
name|dl
operator|->
name|type
expr_stmt|;
name|rentry_ptr
operator|->
name|count
operator|=
name|dl
operator|->
name|len
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_address
index|[
literal|0
index|]
operator|=
name|svtophy
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_address
index|[
literal|1
index|]
operator|=
name|dl
operator|->
name|dest
expr_stmt|;
for|for
control|(
name|checksum
operator|=
literal|0
operator|,
name|i
operator|=
name|dl
operator|->
name|len
init|;
name|i
operator|--
condition|;
control|)
name|checksum
operator|+=
operator|*
name|buffer
operator|++
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_address
index|[
literal|2
index|]
operator|=
name|checksum
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_address
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|DN_TYPE_XFR
case|:
ifdef|#
directive|ifdef
name|DDADEBUG
if|if
condition|(
name|DDADBCH
argument_list|(
literal|29
argument_list|,
name|unit
argument_list|)
condition|)
name|DDALOG
argument_list|(
name|LOG_DEBUG
argument_list|)
literal|"dda%d: execute buf=%d addr=0x%x\n"
operator|,
name|unit
operator|,
name|requestq
operator|->
name|load
operator|,
name|dl
operator|->
name|dest
name|DDAELOG
expr_stmt|;
endif|#
directive|endif
endif|DDADEBUG
name|rentry_ptr
operator|->
name|opcode
operator|=
name|dl
operator|->
name|type
expr_stmt|;
name|rentry_ptr
operator|->
name|BI_address
index|[
literal|1
index|]
operator|=
name|dl
operator|->
name|dest
expr_stmt|;
break|break;
block|}
comment|/* TELL 7000 about new entry in request queue */
name|requestq
operator|->
name|load
operator|=
name|next_load
expr_stmt|;
comment|/* boom! */
name|nxv
operator|->
name|biic_gpr0
operator|=
name|SYSGEN_DLOAD
expr_stmt|;
comment|/* interrupt FE */
ifdef|#
directive|ifdef
name|SIMULATION
name|MFP_COUNTER_SIM
argument_list|()
expr_stmt|;
comment|/* simulate hardware action */
endif|#
directive|endif
return|return
literal|0
return|;
block|}
default|default:
return|return
name|EFAULT
return|;
block|}
block|}
end_function

begin_comment
comment|/*  Revision history:  30-Nov-1989	Paul Traina 	First cut for beta release.  */
end_comment

end_unit

