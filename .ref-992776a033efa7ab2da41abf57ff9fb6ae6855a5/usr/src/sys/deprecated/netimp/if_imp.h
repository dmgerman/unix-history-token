begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	if_imp.h	4.6	82/03/19	*/
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
comment|/* leader format */
name|u_char
name|dl_network
decl_stmt|;
comment|/* src/dest network */
name|u_char
name|dl_flags
decl_stmt|;
comment|/* leader flags */
name|u_char
name|dl_mtype
decl_stmt|;
comment|/* message type */
name|u_char
name|dl_htype
decl_stmt|;
comment|/* handling type */
name|u_char
name|dl_host
decl_stmt|;
comment|/* host number */
name|u_short
name|dl_imp
decl_stmt|;
comment|/* imp field */
name|u_char
name|dl_link
decl_stmt|;
comment|/* link number */
name|u_char
name|dl_subtype
decl_stmt|;
comment|/* message subtype */
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
name|IMP_DROPCNT
value|2
end_define

begin_comment
comment|/* # of noops from imp to ignore */
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

begin_comment
comment|/*  * IMP-host flags  */
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

begin_define
define|#
directive|define
name|IMP_DMASK
value|0x3
end_define

begin_comment
comment|/* host going down mask */
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
comment|/*  * IMPTYPE_DOWN subtypes.  */
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

begin_comment
comment|/*  * Data structure shared between IMP protocol module and hardware  * interface driver.  Used to allow layering of IMP routines on top  * of varying device drivers.  NOTE: there's a possible problem   * with ambiguity in the ``unit'' definition which is implicitly  * shared by the both IMP and device code.  If we have two IMPs,  * with each on top of a device of the same unit, things won't work.  * The assumption is if you've got multiple IMPs, then they all run  * on top of the same type of device, or they must have different units.  */
end_comment

begin_struct
struct|struct
name|impcb
block|{
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
name|ic_start
function_decl|)
parameter_list|()
function_decl|;
comment|/* hardware start output routine */
block|}
struct|;
end_struct

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
comment|/* unavailable, don't use */
end_comment

begin_define
define|#
directive|define
name|IMPS_GOINGDOWN
value|1
end_define

begin_comment
comment|/* been told we go down soon */
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
name|IMPS_RESET
value|4
end_define

begin_comment
comment|/* reset in progress */
end_comment

begin_define
define|#
directive|define
name|IMPTV_DOWN
value|(30*60)
end_define

begin_comment
comment|/* going down timer 30 secs */
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

