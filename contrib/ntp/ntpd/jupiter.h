begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /cvs/ntp/ntpd/jupiter.h,v 1.1.1.1 1999/05/26 00:48:19 stenn Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Rockwell Jupiter GPS receiver definitions  *  * This is all based on the "Zodiac GPS Receiver Family Designer's  * Guide" (dated 12/96)  */
end_comment

begin_define
define|#
directive|define
name|JUPITER_SYNC
value|0x81ff
end_define

begin_comment
comment|/* sync word (book says 0xff81 !?!?) */
end_comment

begin_define
define|#
directive|define
name|JUPITER_ALL
value|0xffff
end_define

begin_comment
comment|/* disable all output messages */
end_comment

begin_comment
comment|/* Output messages (sent by the Jupiter board) */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_GPOS
value|1000
end_define

begin_comment
comment|/* geodetic position status */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_EPOS
value|1001
end_define

begin_comment
comment|/* ECEF position status */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_CHAN
value|1002
end_define

begin_comment
comment|/* channel summary */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_VIS
value|1003
end_define

begin_comment
comment|/* visible satellites */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_DGPS
value|1005
end_define

begin_comment
comment|/* differential GPS status */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_MEAS
value|1007
end_define

begin_comment
comment|/* channel measurement */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_ID
value|1011
end_define

begin_comment
comment|/* receiver id */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_USER
value|1012
end_define

begin_comment
comment|/* user-settings output */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_TEST
value|1100
end_define

begin_comment
comment|/* built-in test results */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_MARK
value|1102
end_define

begin_comment
comment|/* measurement time mark */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_PULSE
value|1108
end_define

begin_comment
comment|/* UTC time mark pulse output */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_PORT
value|1130
end_define

begin_comment
comment|/* serial port com parameters in use */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_EUP
value|1135
end_define

begin_comment
comment|/* EEPROM update */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_ESTAT
value|1136
end_define

begin_comment
comment|/* EEPROM status */
end_comment

begin_comment
comment|/* Input messages (sent to the Jupiter board) */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT
value|1200
end_define

begin_comment
comment|/* geodetic position and velocity */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_USER
value|1210
end_define

begin_comment
comment|/* user-defined datum */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_MAPSEL
value|1211
end_define

begin_comment
comment|/* map datum select */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_ELEV
value|1212
end_define

begin_comment
comment|/* satellite elevation mask control */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_CAND
value|1213
end_define

begin_comment
comment|/* satellite candidate select */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_DGPS
value|1214
end_define

begin_comment
comment|/* differential GPS control */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_COLD
value|1216
end_define

begin_comment
comment|/* cold start control */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_VALID
value|1217
end_define

begin_comment
comment|/* solution validity criteria */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_ALT
value|1219
end_define

begin_comment
comment|/* user-entered altitude input */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PLAT
value|1220
end_define

begin_comment
comment|/* application platform control */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_NAV
value|1221
end_define

begin_comment
comment|/* nav configuration */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_TEST
value|1300
end_define

begin_comment
comment|/* preform built-in test command */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_RESTART
value|1303
end_define

begin_comment
comment|/* restart command */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PORT
value|1330
end_define

begin_comment
comment|/* serial port com parameters */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PROTO
value|1331
end_define

begin_comment
comment|/* message protocol control */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_RDGPS
value|1351
end_define

begin_comment
comment|/* raw DGPS RTCM SC-104 data */
end_comment

begin_struct
struct|struct
name|jheader
block|{
name|u_short
name|sync
decl_stmt|;
comment|/* (JUPITER_SYNC) */
name|u_short
name|id
decl_stmt|;
comment|/* message id */
name|u_short
name|len
decl_stmt|;
comment|/* number of data short wordss (w/o cksum) */
name|u_char
name|reqid
decl_stmt|;
comment|/* JUPITER_REQID_MASK bits available as id */
name|u_char
name|flags
decl_stmt|;
comment|/* flags */
name|u_short
name|hsum
decl_stmt|;
comment|/* header cksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_REQID_MASK
value|0x3f
end_define

begin_comment
comment|/* bits available as id */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_NAK
value|0x01
end_define

begin_comment
comment|/* negative acknowledgement */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_ACK
value|0x02
end_define

begin_comment
comment|/* acknowledgement */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_REQUEST
value|0x04
end_define

begin_comment
comment|/* request ACK or NAK */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_QUERY
value|0x08
end_define

begin_comment
comment|/* request one shot output message */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_LOG
value|0x20
end_define

begin_comment
comment|/* request periodic output message */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_CONN
value|0x40
end_define

begin_comment
comment|/* enable periodic message */
end_comment

begin_define
define|#
directive|define
name|JUPITER_FLAG_DISC
value|0x80
end_define

begin_comment
comment|/* disable periodic message */
end_comment

begin_define
define|#
directive|define
name|JUPITER_H_FLAG_BITS
define|\
value|"\020\1NAK\2ACK\3REQUEST\4QUERY\5MBZ\6LOG\7CONN\10DISC"
end_define

begin_comment
comment|/* Log request messages (data payload when using JUPITER_FLAG_LOG) */
end_comment

begin_struct
struct|struct
name|jrequest
block|{
name|u_short
name|trigger
decl_stmt|;
comment|/* if 0, trigger on time trigger on 					   update (e.g. new almanac) */
name|u_short
name|interval
decl_stmt|;
comment|/* frequency in seconds */
name|u_short
name|offset
decl_stmt|;
comment|/* offset into minute */
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_O_GPOS (1000) */
end_comment

begin_struct
struct|struct
name|jgpos
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|sseq
decl_stmt|;
comment|/* sat measurement sequence number */
name|u_short
name|navval
decl_stmt|;
comment|/* navigation soltuion validity */
name|u_short
name|navtype
decl_stmt|;
comment|/* navigation solution type */
name|u_short
name|nmeas
decl_stmt|;
comment|/* # of measurements used in solution */
name|u_short
name|polar
decl_stmt|;
comment|/* if 1 then polar navigation */
name|u_short
name|gweek
decl_stmt|;
comment|/* GPS week number */
name|u_short
name|sweek
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS seconds into week */
name|u_short
name|nsweek
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS nanoseconds into second */
name|u_short
name|utcday
decl_stmt|;
comment|/* 1 to 31 */
name|u_short
name|utcmon
decl_stmt|;
comment|/* 1 to 12 */
name|u_short
name|utcyear
decl_stmt|;
comment|/* 1980 to 2079 */
name|u_short
name|utchour
decl_stmt|;
comment|/* 0 to 23 */
name|u_short
name|utcmin
decl_stmt|;
comment|/* 0 to 59 */
name|u_short
name|utcsec
decl_stmt|;
comment|/* 0 to 59 */
name|u_short
name|utcnsec
index|[
literal|2
index|]
decl_stmt|;
comment|/* 0 to 999999999 */
name|u_short
name|lat
index|[
literal|2
index|]
decl_stmt|;
comment|/* latitude (radians) */
name|u_short
name|lon
index|[
literal|2
index|]
decl_stmt|;
comment|/* longitude (radians) */
name|u_short
name|height
index|[
literal|2
index|]
decl_stmt|;
comment|/* height (meters) */
name|u_short
name|gsep
decl_stmt|;
comment|/* geoidal separation */
name|u_short
name|speed
index|[
literal|2
index|]
decl_stmt|;
comment|/* ground speed (meters/sec) */
name|u_short
name|course
decl_stmt|;
comment|/* true course (radians) */
name|u_short
name|mvar
decl_stmt|;
name|u_short
name|climb
decl_stmt|;
name|u_short
name|mapd
decl_stmt|;
name|u_short
name|herr
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|verr
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|terr
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|hverr
decl_stmt|;
name|u_short
name|bias
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|biassd
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|drift
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|driftsd
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_O_GPOS_NAV_NOALT
value|0x01
end_define

begin_comment
comment|/* altitude used */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_GPOS_NAV_NODGPS
value|0x02
end_define

begin_comment
comment|/* no differential GPS */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_GPOS_NAV_NOSAT
value|0x04
end_define

begin_comment
comment|/* not enough satellites */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_GPOS_NAV_MAXH
value|0x08
end_define

begin_comment
comment|/* exceeded max EHPE */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_GPOS_NAV_MAXV
value|0x10
end_define

begin_comment
comment|/* exceeded max EVPE */
end_comment

begin_comment
comment|/* JUPITER_O_CHAN (1002) */
end_comment

begin_struct
struct|struct
name|jchan
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|sseq
decl_stmt|;
comment|/* sat measurement sequence number */
name|u_short
name|gweek
decl_stmt|;
comment|/* GPS week number */
name|u_short
name|sweek
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS seconds into week */
name|u_short
name|gpsns
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS nanoseconds from epoch */
struct|struct
name|jchan2
block|{
name|u_short
name|flags
decl_stmt|;
comment|/* flags */
name|u_short
name|prn
decl_stmt|;
comment|/* satellite PRN */
name|u_short
name|chan
decl_stmt|;
comment|/* channel number */
block|}
name|sat
index|[
literal|12
index|]
struct|;
name|u_short
name|dsum
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_O_VIS (1003) */
end_comment

begin_struct
struct|struct
name|jvis
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|gdop
decl_stmt|;
comment|/* best possible GDOP */
name|u_short
name|pdop
decl_stmt|;
comment|/* best possible PDOP */
name|u_short
name|hdop
decl_stmt|;
comment|/* best possible HDOP */
name|u_short
name|vdop
decl_stmt|;
comment|/* best possible VDOP */
name|u_short
name|tdop
decl_stmt|;
comment|/* best possible TDOP */
name|u_short
name|nvis
decl_stmt|;
comment|/* number of visible satellites */
struct|struct
name|jvis2
block|{
name|u_short
name|prn
decl_stmt|;
comment|/* satellite PRN */
name|u_short
name|azi
decl_stmt|;
comment|/* satellite azimuth (radians) */
name|u_short
name|elev
decl_stmt|;
comment|/* satellite elevation (radians) */
block|}
name|sat
index|[
literal|12
index|]
struct|;
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_O_ID (1011) */
end_comment

begin_struct
struct|struct
name|jid
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|char
name|chans
index|[
literal|20
index|]
decl_stmt|;
comment|/* number of channels (ascii) */
name|char
name|vers
index|[
literal|20
index|]
decl_stmt|;
comment|/* software version (ascii) */
name|char
name|date
index|[
literal|20
index|]
decl_stmt|;
comment|/* software date (ascii) */
name|char
name|opts
index|[
literal|20
index|]
decl_stmt|;
comment|/* software options (ascii) */
name|char
name|reserved
index|[
literal|20
index|]
decl_stmt|;
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_O_USER (1012) */
end_comment

begin_struct
struct|struct
name|juser
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|status
decl_stmt|;
comment|/* operatinoal status */
name|u_short
name|coldtmo
decl_stmt|;
comment|/* cold start time-out */
name|u_short
name|dgpstmo
decl_stmt|;
comment|/* DGPS correction time-out*/
name|u_short
name|emask
decl_stmt|;
comment|/* elevation mask */
name|u_short
name|selcand
index|[
literal|2
index|]
decl_stmt|;
comment|/* selected candidate */
name|u_short
name|solflags
decl_stmt|;
comment|/* solution validity criteria */
name|u_short
name|nsat
decl_stmt|;
comment|/* number of satellites in track */
name|u_short
name|herr
index|[
literal|2
index|]
decl_stmt|;
comment|/* minimum expected horizontal error */
name|u_short
name|verr
index|[
literal|2
index|]
decl_stmt|;
comment|/* minimum expected vertical error */
name|u_short
name|platform
decl_stmt|;
comment|/* application platform */
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_O_PULSE (1108) */
end_comment

begin_struct
struct|struct
name|jpulse
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|reserved
index|[
literal|5
index|]
decl_stmt|;
name|u_short
name|sweek
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS seconds into week */
name|short
name|offs
decl_stmt|;
comment|/* GPS to UTC time offset (seconds) */
name|u_short
name|offns
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS to UTC offset (nanoseconds) */
name|u_short
name|flags
decl_stmt|;
comment|/* flags */
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_O_PULSE_VALID
value|0x1
end_define

begin_comment
comment|/* time mark validity */
end_comment

begin_define
define|#
directive|define
name|JUPITER_O_PULSE_UTC
value|0x2
end_define

begin_comment
comment|/* GPS/UTC sync */
end_comment

begin_comment
comment|/* JUPITER_O_EUP (1135) */
end_comment

begin_struct
struct|struct
name|jeup
block|{
name|u_short
name|stime
index|[
literal|2
index|]
decl_stmt|;
comment|/* set time (10 ms ticks) */
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_char
name|dataid
decl_stmt|;
comment|/* data id */
name|u_char
name|prn
decl_stmt|;
comment|/* satellite PRN */
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_comment
comment|/* JUPITER_I_RESTART (1303) */
end_comment

begin_struct
struct|struct
name|jrestart
block|{
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|flags
decl_stmt|;
name|u_short
name|dsum
decl_stmt|;
comment|/* checksum */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_I_RESTART_INVRAM
value|0x01
end_define

begin_define
define|#
directive|define
name|JUPITER_I_RESTART_INVEEPROM
value|0x02
end_define

begin_define
define|#
directive|define
name|JUPITER_I_RESTART_INVRTC
value|0x04
end_define

begin_define
define|#
directive|define
name|JUPITER_I_RESTART_COLD
value|0x80
end_define

begin_comment
comment|/* JUPITER_I_PVTINIT (1200) */
end_comment

begin_struct
struct|struct
name|jpvtinit
block|{
name|u_short
name|flags
decl_stmt|;
name|u_short
name|gweek
decl_stmt|;
comment|/* GPS week number */
name|u_short
name|sweek
index|[
literal|2
index|]
decl_stmt|;
comment|/* GPS seconds into week */
name|u_short
name|utcday
decl_stmt|;
comment|/* 1 to 31 */
name|u_short
name|utcmon
decl_stmt|;
comment|/* 1 to 12 */
name|u_short
name|utcyear
decl_stmt|;
comment|/* 1980 to 2079 */
name|u_short
name|utchour
decl_stmt|;
comment|/* 0 to 23 */
name|u_short
name|utcmin
decl_stmt|;
comment|/* 0 to 59 */
name|u_short
name|utcsec
decl_stmt|;
comment|/* 0 to 59 */
name|u_short
name|lat
index|[
literal|2
index|]
decl_stmt|;
comment|/* latitude (radians) */
name|u_short
name|lon
index|[
literal|2
index|]
decl_stmt|;
comment|/* longitude (radians) */
name|u_short
name|height
index|[
literal|2
index|]
decl_stmt|;
comment|/* height (meters) */
name|u_short
name|speed
index|[
literal|2
index|]
decl_stmt|;
comment|/* ground speed (meters/sec) */
name|u_short
name|course
decl_stmt|;
comment|/* true course (radians) */
name|u_short
name|climb
decl_stmt|;
name|u_short
name|dsum
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_FORCE
value|0x01
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_GPSVAL
value|0x02
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_UTCVAL
value|0x04
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_POSVAL
value|0x08
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_ALTVAL
value|0x10
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_SPDVAL
value|0x12
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_MAGVAL
value|0x14
end_define

begin_define
define|#
directive|define
name|JUPITER_I_PVTINIT_CLIMBVAL
value|0x18
end_define

begin_comment
comment|/* JUPITER_I_PLAT (1220) */
end_comment

begin_struct
struct|struct
name|jplat
block|{
name|u_short
name|seq
decl_stmt|;
comment|/* sequence number */
name|u_short
name|platform
decl_stmt|;
comment|/* application platform */
name|u_short
name|dsum
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JUPITER_I_PLAT_DEFAULT
value|0
end_define

begin_comment
comment|/* default dynamics */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PLAT_LOW
value|2
end_define

begin_comment
comment|/* pedestrian */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PLAT_MED
value|5
end_define

begin_comment
comment|/* land (e.g. automobile) */
end_comment

begin_define
define|#
directive|define
name|JUPITER_I_PLAT_HIGH
value|6
end_define

begin_comment
comment|/* air */
end_comment

end_unit

