begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	DATAKIT VCS User Level definitions  *		@(#)dk.h	2.1 DKHOST 84/07/03  */
end_comment

begin_comment
comment|/*  *	ioctl codes  */
end_comment

begin_comment
comment|/*  * Note: these take paramters, but the copyin-copyout must be handled in  * the driver.  */
end_comment

begin_define
define|#
directive|define
name|DKIODIAL
value|_IO('k', 0)
end_define

begin_comment
comment|/* dial out */
end_comment

begin_define
define|#
directive|define
name|DKIOCNEW
value|_IO('k', 1)
end_define

begin_comment
comment|/* offer a service */
end_comment

begin_define
define|#
directive|define
name|DKIOCREQ
value|_IO('k', 2)
end_define

begin_comment
comment|/* request service (SU only) */
end_comment

begin_define
define|#
directive|define
name|DKIOCSPL
value|_IO('s', 1)
end_define

begin_comment
comment|/* splice two circuits (SU only) */
end_comment

begin_define
define|#
directive|define
name|DIOCSWAIT
value|_IO('s', 2)
end_define

begin_comment
comment|/* wait for splice to take place */
end_comment

begin_comment
comment|/*     driver control        */
end_comment

begin_define
define|#
directive|define
name|DIOCEXCL
value|_IO('d', 1)
end_define

begin_comment
comment|/* exclusive use */
end_comment

begin_define
define|#
directive|define
name|DIOCNXCL
value|_IO('d', 2)
end_define

begin_comment
comment|/* reset exclusive use */
end_comment

begin_define
define|#
directive|define
name|DIOCRMODE
value|_IOW('d', 3, short)
end_define

begin_comment
comment|/* set receiver termination modes */
end_comment

begin_define
define|#
directive|define
name|DIOCQQABO
value|_IOR('d', 4, struct dkqqabo)
end_define

begin_comment
comment|/* inquire status of last read */
end_comment

begin_define
define|#
directive|define
name|DIOCXCTL
value|_IOW('d', 8, short)
end_define

begin_comment
comment|/* send ctl envelope on next write */
end_comment

begin_define
define|#
directive|define
name|DIOCFLUSH
value|_IO('d', 9)
end_define

begin_comment
comment|/* flush output */
end_comment

begin_define
define|#
directive|define
name|DIOCSETK
value|_IOW('d', 10, short)
end_define

begin_comment
comment|/* debug info from kmc xmit&recv */
end_comment

begin_define
define|#
directive|define
name|DIOCXWIN
value|_IOW('d', 11, struct diocxwin)
end_define

begin_comment
comment|/* Set window size */
end_comment

begin_define
define|#
directive|define
name|KIOCINIT
value|_IO('d', 12)
end_define

begin_comment
comment|/* Reinitialize transmitter */
end_comment

begin_define
define|#
directive|define
name|DIOCRESET
value|_IOW('d', 13, short)
end_define

begin_comment
comment|/* Reset a channel */
end_comment

begin_define
define|#
directive|define
name|DIOCCTYPE
value|_IOW('d', 14, struct diocctype)
end_define

begin_comment
comment|/* Set conn type */
end_comment

begin_define
define|#
directive|define
name|DIOCINFO
value|_IOR('d', 15, struct diocinfo)
end_define

begin_comment
comment|/* Get chan #, max # */
end_comment

begin_define
define|#
directive|define
name|DIOCSTAT
value|_IOWR('d', 16, int)
end_define

begin_comment
comment|/* Check if channel open */
end_comment

begin_comment
comment|/*	special codes used by dkxstdio	*/
end_comment

begin_define
define|#
directive|define
name|DXIOEXIT
value|_IOW('D', 'T', int)
end_define

begin_comment
comment|/* process exit code */
end_comment

begin_comment
comment|/*  *	structure returned from DIOCQQABO giving receive status  */
end_comment

begin_struct
struct|struct
name|dkqqabo
block|{
name|short
name|rcv_resid
decl_stmt|;
comment|/* residual length in buffer */
name|short
name|rcv_reason
decl_stmt|;
comment|/* set of bits giving reasons */
name|short
name|rcv_ctlchar
decl_stmt|;
comment|/* ctl char that finished block */
block|}
struct|;
end_struct

begin_comment
comment|/*  *   receive mode, and completion indicators  *	also defined in sys/dkit.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DKR_FULL
end_ifndef

begin_define
define|#
directive|define
name|DKR_FULL
value|01
end_define

begin_comment
comment|/* buffer full, normal read done */
end_comment

begin_define
define|#
directive|define
name|DKR_CNTL
value|02
end_define

begin_comment
comment|/* read terminated on control character */
end_comment

begin_define
define|#
directive|define
name|DKR_ABORT
value|010
end_define

begin_comment
comment|/* receive aborted by higher level command */
end_comment

begin_define
define|#
directive|define
name|DKR_BLOCK
value|040
end_define

begin_comment
comment|/* end of block */
end_comment

begin_define
define|#
directive|define
name|DKR_TIME
value|0100
end_define

begin_comment
comment|/* end of time limit reached */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *	structure passed with ioctl to request a service  */
end_comment

begin_struct
struct|struct
name|diocreq
block|{
name|short
name|req_traffic
decl_stmt|;
comment|/* traffic intensity generated */
name|short
name|req_1param
decl_stmt|;
comment|/* typ:  service requested */
name|short
name|req_2param
decl_stmt|;
comment|/* parameter to server */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	structure passed to dial a number  */
end_comment

begin_struct
struct|struct
name|diocdial
block|{
name|struct
name|diocreq
name|iocb
decl_stmt|;
name|char
name|dialstring
index|[
literal|112
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|diocreq
argument_list|)
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure passed to set URP limits  */
end_comment

begin_struct
struct|struct
name|diocxwin
block|{
name|int
name|xwin_msgsize
decl_stmt|;
comment|/* Size of one message */
name|unsigned
name|char
name|xwin_nmsg
decl_stmt|;
comment|/* Number of outstanding messages */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure passed to request configuration info  */
end_comment

begin_struct
struct|struct
name|diocinfo
block|{
name|short
name|dioc_nchan
decl_stmt|;
comment|/* Number of channels configured */
name|short
name|dioc_channum
decl_stmt|;
comment|/* This channel number */
name|short
name|dioc_commchan
decl_stmt|;
comment|/* Common supervisory channel */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	structure passed with ioctl to request a splice  */
end_comment

begin_struct
struct|struct
name|diocspl
block|{
name|short
name|spl_fdin
decl_stmt|;
comment|/* the other file descriptor */
name|short
name|spl_un1used
decl_stmt|;
name|short
name|spl_un2used
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|diocctype
block|{
name|int
name|dct_type
decl_stmt|;
comment|/* Annotation type */
name|char
name|dct_name
index|[
literal|112
operator|-
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|-
literal|1
index|]
decl_stmt|;
comment|/* Connection type */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DCT_DIAL
value|1
end_define

begin_comment
comment|/* Dialstring uttered */
end_comment

begin_define
define|#
directive|define
name|DCT_SERVE
value|2
end_define

begin_comment
comment|/* Server name */
end_comment

begin_define
define|#
directive|define
name|DCT_FROM
value|3
end_define

begin_comment
comment|/* Connection source */
end_comment

begin_comment
comment|/*  *	values returned from service request  */
end_comment

begin_define
define|#
directive|define
name|req_error
value|req_traffic
end_define

begin_define
define|#
directive|define
name|req_driver
value|req_traffic
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_comment
comment|/*  *	structure received by server when new connection made  */
end_comment

begin_struct
struct|struct
name|mgrmsg
block|{
name|short
name|m_chan
decl_stmt|;
comment|/* channel number of connection */
name|unsigned
name|short
name|m_tstamp
decl_stmt|;
comment|/* time stamp of request */
name|char
modifier|*
name|m_protocol
decl_stmt|;
comment|/* protocol options from user */
name|char
modifier|*
name|m_origtype
decl_stmt|;
comment|/* type of originating device */
name|char
modifier|*
name|m_parm
decl_stmt|;
comment|/* parameter string from user */
name|char
modifier|*
name|m_uid
decl_stmt|;
comment|/* param from system/user, aka UID */
name|char
modifier|*
name|m_dial
decl_stmt|;
comment|/* dial string entered */
name|char
modifier|*
name|m_source
decl_stmt|;
comment|/* originator, as known to remote node */
name|char
modifier|*
name|m_lname
decl_stmt|;
comment|/* originator, as known to local node */
name|char
modifier|*
name|m_service
decl_stmt|;
comment|/* service type requested by user */
name|char
modifier|*
name|m_lflag
decl_stmt|;
comment|/* L == call from local node, 					 * R == call from a remote one.   */
name|char
modifier|*
name|m_srcnode
decl_stmt|;
comment|/* originating node (last segment)   */
name|char
modifier|*
name|m_srcmod
decl_stmt|;
comment|/* originating mod		     */
name|char
modifier|*
name|m_srcchan
decl_stmt|;
comment|/* originating channel		     */
name|char
modifier|*
name|m_cflag
decl_stmt|;
comment|/* call flag: F=first, P=previous    */
name|char
modifier|*
name|m_errmsg
decl_stmt|;
comment|/* possible error msg if m_chan<= 0 */
name|char
modifier|*
name|m_baudrate
decl_stmt|;
comment|/* incoming terminal baud rate */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	routines declared in libdk.a  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|dknamer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dtnamer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dxnamer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dinamer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|dketcf
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dkfcanon
argument_list|()
decl_stmt|,
modifier|*
name|dktcanon
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|dkerr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|maphost
argument_list|()
decl_stmt|,
modifier|*
name|miscfield
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|mh_hostname
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|mgrmsg
modifier|*
name|dkmgr
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|dk_verbose
decl_stmt|,
name|dk_errno
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

