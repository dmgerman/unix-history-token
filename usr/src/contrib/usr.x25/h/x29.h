begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ---------------------------------------------------------------------        X.29 Manifest Constants     --------------------------------------------------------------------- */
end_comment

begin_comment
comment|/* Message types for level-1 messages. */
end_comment

begin_define
define|#
directive|define
name|X29_SET_PARMS
value|2
end_define

begin_comment
comment|/* Host to Pad */
end_comment

begin_define
define|#
directive|define
name|X29_READ_PARMS
value|4
end_define

begin_comment
comment|/* Host to Pad */
end_comment

begin_define
define|#
directive|define
name|X29_SET_AND_READ_PARMS
value|6
end_define

begin_comment
comment|/* Host to Pad */
end_comment

begin_define
define|#
directive|define
name|X29_INVITATION_TO_CLEAR
value|1
end_define

begin_comment
comment|/* Host to Pad */
end_comment

begin_define
define|#
directive|define
name|X29_PARAMETER_INDICATION
value|0
end_define

begin_comment
comment|/* Pad to Host */
end_comment

begin_define
define|#
directive|define
name|X29_INDICATION_OF_BREAK
value|3
end_define

begin_comment
comment|/* Both directions */
end_comment

begin_define
define|#
directive|define
name|X29_ERROR
value|5
end_define

begin_comment
comment|/* Pad to Host */
end_comment

begin_comment
comment|/* Parameter code definitions as per CCITT 1978 recommendation */
end_comment

begin_define
define|#
directive|define
name|X29_NATIONAL_PARAMETER_MARKER
value|0
end_define

begin_define
define|#
directive|define
name|X29_ESCAPE_TO_CMD_CODE
value|1
end_define

begin_define
define|#
directive|define
name|X29_ECHO_CODE
value|2
end_define

begin_define
define|#
directive|define
name|X29_FORWARDING_SIGNAL_CODE
value|3
end_define

begin_define
define|#
directive|define
name|X29_IDLE_TIMER_CODE
value|4
end_define

begin_define
define|#
directive|define
name|X29_AUX_DEV_CONTROL_CODE
value|5
end_define

begin_define
define|#
directive|define
name|X29_RECEIVE_NET_MSGS_CODE
value|6
end_define

begin_define
define|#
directive|define
name|X29_BREAK_PROCEDURE_CODE
value|7
end_define

begin_define
define|#
directive|define
name|X29_DISCARD_OUTPUT_CODE
value|8
end_define

begin_define
define|#
directive|define
name|X29_PADDING_CODE
value|9
end_define

begin_define
define|#
directive|define
name|X29_LINE_FOLDING_CODE
value|10
end_define

begin_define
define|#
directive|define
name|X29_TRANSMISSION_SPEED_CODE
value|11
end_define

begin_define
define|#
directive|define
name|X29_XON_XOFF_CODE
value|12
end_define

begin_comment
comment|/* PAD parameters specific to 1980 CCITT X.3 recommendation */
end_comment

begin_define
define|#
directive|define
name|X29_LF_AFTER_CR
value|13
end_define

begin_define
define|#
directive|define
name|X29_PADDING_AFTER_LF
value|14
end_define

begin_define
define|#
directive|define
name|X29_EDITING
value|15
end_define

begin_define
define|#
directive|define
name|X29_CHARACTER_DELETE
value|16
end_define

begin_define
define|#
directive|define
name|X29_LINE_DELETE
value|17
end_define

begin_define
define|#
directive|define
name|X29_LINE_DISPLAY
value|18
end_define

begin_define
define|#
directive|define
name|NX29_1978_PARMS
value|12
end_define

begin_comment
comment|/* # of parameters in 1978 spec */
end_comment

begin_define
define|#
directive|define
name|NX29_1980_PARMS
value|18
end_define

begin_comment
comment|/* # of parameters in 1980 spec */
end_comment

begin_define
define|#
directive|define
name|NX29_PARMS
value|18
end_define

begin_comment
comment|/* # of parameters from any spec */
end_comment

begin_define
define|#
directive|define
name|PACKET_SIZE
value|512
end_define

begin_comment
comment|/* maximum network packet size */
end_comment

begin_comment
comment|/*  * Standard ITI call protocol type.  * This should really be extracted from /etc/services  * but since it is not likely to ever change we define  * it here to save cpu cycles.  */
end_comment

begin_define
define|#
directive|define
name|ITI_CALL
value|1
end_define

begin_struct
struct|struct
name|x25packet
block|{
name|u_char
name|p_x25flag
decl_stmt|;
comment|/* flag byte, either M_BIT or Q_BIT */
define|#
directive|define
name|Q_BIT
value|0x80
define|#
directive|define
name|M_BIT
value|0x40
name|u_char
name|p_x25data
index|[
name|PACKET_SIZE
index|]
decl_stmt|;
comment|/* actual size varies */
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure of x.29 parameter entry  */
end_comment

begin_struct
struct|struct
name|x29param
block|{
name|u_char
name|x29_pnum
decl_stmt|;
comment|/* x29 parameter number */
name|u_char
name|x29_value
decl_stmt|;
comment|/* parameter value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|x29packet
block|{
name|u_char
name|p_x29flag
decl_stmt|;
comment|/* flag byte, either M_BIT or Q_BIT */
name|u_char
name|p_x29code
decl_stmt|;
comment|/* message type */
union|union
block|{
name|struct
name|x29param
name|x29paramlist
index|[
name|NX29_PARMS
index|]
decl_stmt|;
struct|struct
block|{
name|u_char
name|x29errno
decl_stmt|;
name|u_char
name|x29mtype
decl_stmt|;
block|}
name|x29error
struct|;
block|}
name|x29_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|p_x29param
value|x29_un.x29paramlist
end_define

begin_define
define|#
directive|define
name|p_x29errno
value|x29_un.x29error.x29errno
end_define

begin_define
define|#
directive|define
name|p_x29mtype
value|x29_un.x29error.x29mtype
end_define

end_unit

