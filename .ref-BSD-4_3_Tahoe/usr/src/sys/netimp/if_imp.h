begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)if_imp.h	7.5 (Berkeley) 6/29/88  */
end_comment

begin_comment
comment|/*  * Structure of IMP 1822 long leader.  */
end_comment

begin_struct
struct|struct
name|control_leader
block|{
name|u_char
name|dl_format
decl_stmt|;
comment|/* 1-8   leader format */
name|u_char
name|dl_network
decl_stmt|;
comment|/* 9-16  src/dest network */
name|u_char
name|dl_flags
decl_stmt|;
comment|/* 17-24 leader flags */
name|u_char
name|dl_mtype
decl_stmt|;
comment|/* 25-32 message type */
name|u_char
name|dl_htype
decl_stmt|;
comment|/* 33-40 handling type */
name|u_char
name|dl_host
decl_stmt|;
comment|/* 41-48 host number */
name|u_short
name|dl_imp
decl_stmt|;
comment|/* 49-64 imp field */
name|u_char
name|dl_link
decl_stmt|;
comment|/* 65-72 link number */
name|u_char
name|dl_subtype
decl_stmt|;
comment|/* 73-80 message subtype */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|imp_leader
block|{
name|struct
name|control_leader
name|il_dl
decl_stmt|;
define|#
directive|define
name|il_format
value|il_dl.dl_format
define|#
directive|define
name|il_network
value|il_dl.dl_network
define|#
directive|define
name|il_flags
value|il_dl.dl_flags
define|#
directive|define
name|il_mtype
value|il_dl.dl_mtype
define|#
directive|define
name|il_htype
value|il_dl.dl_htype
define|#
directive|define
name|il_host
value|il_dl.dl_host
define|#
directive|define
name|il_imp
value|il_dl.dl_imp
define|#
directive|define
name|il_link
value|il_dl.dl_link
define|#
directive|define
name|il_subtype
value|il_dl.dl_subtype
name|u_short
name|il_length
decl_stmt|;
comment|/* message length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IMP_MAXHOSTMSG
value|8
end_define

begin_comment
comment|/* max messages in flight to a host */
end_comment

begin_define
define|#
directive|define
name|IMP_NOOPCNT
value|3
end_define

begin_comment
comment|/* # of noops to send imp on reset */
end_comment

begin_comment
comment|/* insure things are even... */
end_comment

begin_define
define|#
directive|define
name|IMPMTU
value|((8159 / NBBY)& ~01)
end_define

begin_define
define|#
directive|define
name|IMP_RCVBUF
value|((8159 / NBBY + 2)& ~01)
end_define

begin_comment
comment|/*  * IMP-host flags  */
end_comment

begin_define
define|#
directive|define
name|IMP_1822L_H2I
value|0xd
end_define

begin_comment
comment|/* 1822L host-to-imp, 96-bit format */
end_comment

begin_define
define|#
directive|define
name|IMP_1822L_I2H
value|0xe
end_define

begin_comment
comment|/* 1822L imp-to-host, 96-bit format */
end_comment

begin_define
define|#
directive|define
name|IMP_NFF
value|0xf
end_define

begin_comment
comment|/* 96-bit (new) format */
end_comment

begin_define
define|#
directive|define
name|IMP_TRACE
value|0x8
end_define

begin_comment
comment|/* trace message route */
end_comment

begin_comment
comment|/*  * IMP-host message types.  */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_DATA
value|0
end_define

begin_comment
comment|/* data for protocol */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_BADLEADER
value|1
end_define

begin_comment
comment|/* leader error */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_DOWN
value|2
end_define

begin_comment
comment|/* imp going down */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_NOOP
value|4
end_define

begin_comment
comment|/* noop seen during initialization */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_RFNM
value|5
end_define

begin_comment
comment|/* request for new messages */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_HOSTDEAD
value|6
end_define

begin_comment
comment|/* host doesn't respond */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_HOSTUNREACH
value|7
end_define

begin_comment
comment|/* host unreachable */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_BADDATA
value|8
end_define

begin_comment
comment|/* data error */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_INCOMPLETE
value|9
end_define

begin_comment
comment|/* incomplete message, send rest */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_RESET
value|10
end_define

begin_comment
comment|/* reset complete */
end_comment

begin_comment
comment|/* non-blocking IMP interface */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_RETRY
value|11
end_define

begin_comment
comment|/* IMP refused, try again */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_NOTIFY
value|12
end_define

begin_comment
comment|/* IMP refused, will notify */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_TRYING
value|13
end_define

begin_comment
comment|/* IMP refused, still rexmt'ng */
end_comment

begin_define
define|#
directive|define
name|IMPTYPE_READY
value|14
end_define

begin_comment
comment|/* ready for next message */
end_comment

begin_comment
comment|/*  * IMPTYPE_DOWN subtypes, in link number field.  */
end_comment

begin_define
define|#
directive|define
name|IMP_DMASK
value|0x3
end_define

begin_comment
comment|/* host going down mask */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_GOING
value|0
end_define

begin_comment
comment|/* 30 secs */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_PM
value|1
end_define

begin_comment
comment|/* hardware PM */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_RELOAD
value|2
end_define

begin_comment
comment|/* software reload */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_RESTART
value|3
end_define

begin_comment
comment|/* emergency restart */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_WHENMASK
value|0x3c
end_define

begin_comment
comment|/* mask for "how soon" */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_WHENSHIFT
value|2
end_define

begin_comment
comment|/* shift for "how soon" */
end_comment

begin_define
define|#
directive|define
name|IMPDOWN_WHENUNIT
value|5
end_define

begin_comment
comment|/* unit for "how soon", 5 min. */
end_comment

begin_define
define|#
directive|define
name|IMPTV_DOWN
value|30
end_define

begin_comment
comment|/* going down timer 30 secs */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IMPMESSAGES
end_ifdef

begin_comment
comment|/*  * Messages from IMP regarding why  * it's going down.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|impmessage
index|[]
init|=
block|{
literal|"in 30 seconds"
block|,
literal|"for hardware PM"
block|,
literal|"to reload software"
block|,
literal|"for emergency reset"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * IMPTYPE_BADLEADER subtypes.  */
end_comment

begin_define
define|#
directive|define
name|IMPLEADER_ERR
value|0
end_define

begin_comment
comment|/* error flip-flop set */
end_comment

begin_define
define|#
directive|define
name|IMPLEADER_SHORT
value|1
end_define

begin_comment
comment|/* leader< 80 bits */
end_comment

begin_define
define|#
directive|define
name|IMPLEADER_TYPE
value|2
end_define

begin_comment
comment|/* illegal type field */
end_comment

begin_define
define|#
directive|define
name|IMPLEADER_OPPOSITE
value|3
end_define

begin_comment
comment|/* opposite leader type */
end_comment

begin_comment
comment|/*  * IMPTYPE_HOSTDEAD subtypes.  */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_NORDY
value|1
end_define

begin_comment
comment|/* ready-line negated */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_TARDY
value|2
end_define

begin_comment
comment|/* tardy receiving mesgs */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_NOEXIST
value|3
end_define

begin_comment
comment|/* NCC doesn't know host */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_IMPSOFT
value|4
end_define

begin_comment
comment|/* IMP software won't allow mesgs */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_PM
value|5
end_define

begin_comment
comment|/* host down for scheduled PM */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_HARDSCHED
value|6
end_define

begin_comment
comment|/* " " " " hardware work */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_SOFTSCHED
value|7
end_define

begin_comment
comment|/* " " " " software work */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_RESTART
value|8
end_define

begin_comment
comment|/* host down for emergency restart */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_POWER
value|9
end_define

begin_comment
comment|/* down because of power outage */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_BREAKPOINT
value|10
end_define

begin_comment
comment|/* host stopped at a breakpoint */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_HARDWARE
value|11
end_define

begin_comment
comment|/* hardware failure */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_NOTUP
value|12
end_define

begin_comment
comment|/* host not scheduled to be up */
end_comment

begin_comment
comment|/* 13-14 currently unused */
end_comment

begin_define
define|#
directive|define
name|IMPHOST_COMINGUP
value|15
end_define

begin_comment
comment|/* host in process of coming up */
end_comment

begin_comment
comment|/*  * IMPTYPE_HOSTUNREACH subtypes.  */
end_comment

begin_define
define|#
directive|define
name|IMPREACH_IMP
value|0
end_define

begin_comment
comment|/* destination IMP can't be reached */
end_comment

begin_define
define|#
directive|define
name|IMPREACH_HOSTUP
value|1
end_define

begin_comment
comment|/* destination host isn't up */
end_comment

begin_define
define|#
directive|define
name|IMPREACH_LEADER
value|2
end_define

begin_comment
comment|/* host doesn't support long leader */
end_comment

begin_define
define|#
directive|define
name|IMPREACH_PROHIBITED
value|3
end_define

begin_comment
comment|/* communication is prohibited */
end_comment

begin_comment
comment|/*  * IMPTYPE_INCOMPLETE subtypes.  */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_SLOW
value|0
end_define

begin_comment
comment|/* host didn't take data fast enough */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_TOOLONG
value|1
end_define

begin_comment
comment|/* message was too long */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_TIMEOUT
value|2
end_define

begin_comment
comment|/* mesg transmission time> 15 sec. */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_FAILURE
value|3
end_define

begin_comment
comment|/* IMP/circuit failure */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_NOSPACE
value|4
end_define

begin_comment
comment|/* no resources within 15 sec. */
end_comment

begin_define
define|#
directive|define
name|IMPCOMPLETE_IMPIO
value|5
end_define

begin_comment
comment|/* src IMP I/O failure during receipt */
end_comment

begin_comment
comment|/*  * IMPTYPE_RETRY subtypes.  */
end_comment

begin_define
define|#
directive|define
name|IMPRETRY_BUFFER
value|0
end_define

begin_comment
comment|/* IMP buffer wasn't available */
end_comment

begin_define
define|#
directive|define
name|IMPRETRY_BLOCK
value|1
end_define

begin_comment
comment|/* connection block unavailable */
end_comment

begin_define
define|#
directive|define
name|RFNMTIMER
value|(120*PR_SLOWHZ)
end_define

begin_comment
comment|/* time to wait for RFNM for msg. */
end_comment

begin_define
define|#
directive|define
name|IMP_OTIMER
value|(5*IFNET_SLOWHZ)
end_define

begin_comment
comment|/* max output time unless blocked */
end_comment

begin_comment
comment|/*  * Data structure shared between IMP protocol module and hardware  * interface driver.  Used to allow layering of IMP routines on top  * of varying device drivers.  */
end_comment

begin_struct
struct|struct
name|impcb
block|{
name|int
name|ic_hwunit
decl_stmt|;
comment|/* H/W unit number */
name|char
modifier|*
name|ic_hwname
decl_stmt|;
comment|/* H/W type name */
name|char
name|ic_oactive
decl_stmt|;
comment|/* output in progress */
name|int
function_decl|(
modifier|*
name|ic_init
function_decl|)
parameter_list|()
function_decl|;
comment|/* hardware init routine */
name|int
function_decl|(
modifier|*
name|ic_output
function_decl|)
parameter_list|()
function_decl|;
comment|/* hardware output routine */
name|int
function_decl|(
modifier|*
name|ic_down
function_decl|)
parameter_list|()
function_decl|;
comment|/* hardware "drop ready" routine */
block|}
struct|;
end_struct

begin_comment
comment|/*  * IMP software status per interface.  * (partially shared with the hardware specific module)  *  * Each interface is referenced by a network interface structure,  * imp_if, which the routing code uses to locate the interface.  * This structure contains the output queue for the interface, its  * address, ...  IMP specific structures used in connecting the  * IMP software modules to the hardware specific interface routines  * are stored here.  The common structures are made visible to the  * interface driver by passing a pointer to the hardware routine  * at "attach" time.  */
end_comment

begin_struct
struct|struct
name|imp_softc
block|{
name|struct
name|ifnet
name|imp_if
decl_stmt|;
comment|/* network visible interface */
name|struct
name|impcb
name|imp_cb
decl_stmt|;
comment|/* hooks to hardware module */
name|int
name|imp_state
decl_stmt|;
comment|/* current state of IMP */
name|int
name|imp_dropcnt
decl_stmt|;
comment|/* used during initialization */
name|struct
name|mbuf
modifier|*
name|imp_hosts
decl_stmt|;
comment|/* Head of host table hash chains. */
name|struct
name|mbuf
modifier|*
name|imp_hostq
decl_stmt|;
comment|/* current round-robin-output mark */
name|u_int
name|imp_hostent
decl_stmt|;
comment|/* current round-robin-output mark */
name|int
name|imp_msgready
decl_stmt|;
comment|/* number of messages ready to send */
name|u_long
name|imp_block
decl_stmt|;
comment|/* times imp blocked output */
name|u_long
name|imp_lostrfnm
decl_stmt|;
comment|/* rfnm's timed out */
name|u_long
name|imp_badrfnm
decl_stmt|;
comment|/* rfnm/incompl after timeout/bogus */
name|u_long
name|imp_incomplete
decl_stmt|;
comment|/* incomplete's received */
name|u_long
name|imp_garbage
decl_stmt|;
comment|/* bad messages received */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|imp_softc
modifier|*
name|impattach
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * State of an IMP.  */
end_comment

begin_define
define|#
directive|define
name|IMPS_DOWN
value|0
end_define

begin_comment
comment|/* unavailable, host not ready */
end_comment

begin_define
define|#
directive|define
name|IMPS_WINIT
value|1
end_define

begin_comment
comment|/* imp not ready, waiting for init */
end_comment

begin_define
define|#
directive|define
name|IMPS_INIT
value|2
end_define

begin_comment
comment|/* coming up */
end_comment

begin_define
define|#
directive|define
name|IMPS_UP
value|3
end_define

begin_comment
comment|/* ready to go */
end_comment

begin_define
define|#
directive|define
name|IMPS_GOINGDOWN
value|4
end_define

begin_comment
comment|/* been told we go down soon */
end_comment

begin_define
define|#
directive|define
name|IMPS_RUNNING
parameter_list|(
name|s
parameter_list|)
value|((s)>= IMPS_UP)
end_define

begin_comment
comment|/* ready for messages */
end_comment

begin_define
define|#
directive|define
name|IMPS_IMPREADY
parameter_list|(
name|s
parameter_list|)
value|((s)>= IMPS_INIT)
end_define

begin_comment
comment|/* IMP ready line on */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IMPLEADERS
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|impleaders
index|[
name|IMPTYPE_READY
operator|+
literal|1
index|]
init|=
block|{
literal|"DATA"
block|,
literal|"BADLEADER"
block|,
literal|"DOWN"
block|,
literal|"bad"
block|,
literal|"NOOP"
block|,
literal|"RFNM"
block|,
literal|"HOSTDEAD"
block|,
literal|"HOSTUNREACH"
block|,
literal|"BADDATA"
block|,
literal|"INCOMPLETE"
block|,
literal|"RESET"
block|,
literal|"RETRY"
block|,
literal|"NOTIFY"
block|,
literal|"TRYING"
block|,
literal|"READY"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

