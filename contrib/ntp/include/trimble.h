begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/trimble.h,v 4.4 1999/02/28 11:41:11 kardel RELEASE_19990228_A  *  * $Created: Sun Aug  2 16:16:49 1998 $  *  * Copyright (C) 1998 by Frank Kardel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRIMBLE_H
end_ifndef

begin_define
define|#
directive|define
name|TRIMBLE_H
end_define

begin_comment
comment|/*  * Trimble packet command codes - commands being sent/received  * keep comments formatted as shown - they are used to generate  * translation tables  */
end_comment

begin_define
define|#
directive|define
name|CMD_CCLROSC
value|0x1D
end_define

begin_comment
comment|/* clear oscillator offset */
end_comment

begin_define
define|#
directive|define
name|CMD_CCLRRST
value|0x1E
end_define

begin_comment
comment|/* clear battery backup and RESET */
end_comment

begin_define
define|#
directive|define
name|CMD_CVERSION
value|0x1F
end_define

begin_comment
comment|/* return software version */
end_comment

begin_define
define|#
directive|define
name|CMD_CALMANAC
value|0x20
end_define

begin_comment
comment|/* almanac */
end_comment

begin_define
define|#
directive|define
name|CMD_CCURTIME
value|0x21
end_define

begin_comment
comment|/* current time */
end_comment

begin_define
define|#
directive|define
name|CMD_CMODESEL
value|0x22
end_define

begin_comment
comment|/* mode select (2-d, 3-D, auto) */
end_comment

begin_define
define|#
directive|define
name|CMD_CINITPOS
value|0x23
end_define

begin_comment
comment|/* initial position */
end_comment

begin_define
define|#
directive|define
name|CMD_CRECVPOS
value|0x24
end_define

begin_comment
comment|/* receiver position fix mode */
end_comment

begin_define
define|#
directive|define
name|CMD_CRESET
value|0x25
end_define

begin_comment
comment|/* soft reset& selftest */
end_comment

begin_define
define|#
directive|define
name|CMD_CRECVHEALTH
value|0x26
end_define

begin_comment
comment|/* receiver health */
end_comment

begin_define
define|#
directive|define
name|CMD_CSIGNALLV
value|0x27
end_define

begin_comment
comment|/* signal levels */
end_comment

begin_define
define|#
directive|define
name|CMD_CMESSAGE
value|0x28
end_define

begin_comment
comment|/* GPS system message */
end_comment

begin_define
define|#
directive|define
name|CMD_CALMAHEALTH
value|0x29
end_define

begin_comment
comment|/* almanac healt page */
end_comment

begin_define
define|#
directive|define
name|CMD_C2DALTITUDE
value|0x2A
end_define

begin_comment
comment|/* altitude for 2-D mode */
end_comment

begin_define
define|#
directive|define
name|CMD_CINITPOSLLA
value|0x2B
end_define

begin_comment
comment|/* initial position LLA */
end_comment

begin_define
define|#
directive|define
name|CMD_COPERPARAM
value|0x2C
end_define

begin_comment
comment|/* operating parameters */
end_comment

begin_define
define|#
directive|define
name|CMD_COSCOFFSET
value|0x2D
end_define

begin_comment
comment|/* oscillator offset */
end_comment

begin_define
define|#
directive|define
name|CMD_CSETGPSTIME
value|0x2E
end_define

begin_comment
comment|/* set GPS time */
end_comment

begin_define
define|#
directive|define
name|CMD_CUTCPARAM
value|0x2F
end_define

begin_comment
comment|/* UTC parameters */
end_comment

begin_define
define|#
directive|define
name|CMD_CACCPOSXYZ
value|0x31
end_define

begin_comment
comment|/* accurate initial position (XYZ/ECEF) */
end_comment

begin_define
define|#
directive|define
name|CMD_CACCPOS
value|0x32
end_define

begin_comment
comment|/* accurate initial position */
end_comment

begin_define
define|#
directive|define
name|CMD_CANALOGDIG
value|0x33
end_define

begin_comment
comment|/* analog to digital */
end_comment

begin_define
define|#
directive|define
name|CMD_CSAT1SAT
value|0x34
end_define

begin_comment
comment|/* satellite for 1-Sat mode */
end_comment

begin_define
define|#
directive|define
name|CMD_CIOOPTIONS
value|0x35
end_define

begin_comment
comment|/* I/O options */
end_comment

begin_define
define|#
directive|define
name|CMD_CVELOCAID
value|0x36
end_define

begin_comment
comment|/* velocity aiding of acquisition */
end_comment

begin_define
define|#
directive|define
name|CMD_CSTATLSTPOS
value|0x37
end_define

begin_comment
comment|/* status and values of last pos. and vel. */
end_comment

begin_define
define|#
directive|define
name|CMD_CLOADSSATDT
value|0x38
end_define

begin_comment
comment|/* load satellite system data */
end_comment

begin_define
define|#
directive|define
name|CMD_CSATDISABLE
value|0x39
end_define

begin_comment
comment|/* satellite disable */
end_comment

begin_define
define|#
directive|define
name|CMD_CLASTRAW
value|0x3A
end_define

begin_comment
comment|/* last raw measurement */
end_comment

begin_define
define|#
directive|define
name|CMD_CSTATSATEPH
value|0x3B
end_define

begin_comment
comment|/* satellite ephemeris status */
end_comment

begin_define
define|#
directive|define
name|CMD_CSTATTRACK
value|0x3C
end_define

begin_comment
comment|/* tracking status */
end_comment

begin_define
define|#
directive|define
name|CMD_CCHANADGPS
value|0x3D
end_define

begin_comment
comment|/* configure channel A for differential GPS */
end_comment

begin_define
define|#
directive|define
name|CMD_CADDITFIX
value|0x3E
end_define

begin_comment
comment|/* additional fix data */
end_comment

begin_define
define|#
directive|define
name|CMD_CDGPSFIXMD
value|0x62
end_define

begin_comment
comment|/* set/request differential GPS position fix mode */
end_comment

begin_define
define|#
directive|define
name|CMD_CDGPSCORR
value|0x65
end_define

begin_comment
comment|/* differential correction status */
end_comment

begin_define
define|#
directive|define
name|CMD_CPOSFILT
value|0x71
end_define

begin_comment
comment|/* position filter parameters */
end_comment

begin_define
define|#
directive|define
name|CMD_CHEIGHTFILT
value|0x73
end_define

begin_comment
comment|/* height filter control */
end_comment

begin_define
define|#
directive|define
name|CMD_CHIGH8CNT
value|0x75
end_define

begin_comment
comment|/* high-8 (best 4) / high-6 (overdetermined) control */
end_comment

begin_define
define|#
directive|define
name|CMD_CMAXDGPSCOR
value|0x77
end_define

begin_comment
comment|/* maximum rate of DGPS corrections */
end_comment

begin_define
define|#
directive|define
name|CMD_CSUPER
value|0x8E
end_define

begin_comment
comment|/* super paket */
end_comment

begin_define
define|#
directive|define
name|CMD_RDATAA
value|0x3D
end_define

begin_comment
comment|/* data channel A configuration:trimble_channelA:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RALMANAC
value|0x40
end_define

begin_comment
comment|/* almanac data for sat:gps_almanac:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RCURTIME
value|0x41
end_define

begin_comment
comment|/* GPS time:gps_time:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSPOSXYZ
value|0x42
end_define

begin_comment
comment|/* single precision XYZ position:gps_position(XYZ):RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RVELOXYZ
value|0x43
end_define

begin_comment
comment|/* velocity fix (XYZ ECEF):gps_velocity(XYZ):RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RBEST4
value|0x44
end_define

begin_comment
comment|/* best 4 satellite selection:trimble_best4:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RVERSION
value|0x45
end_define

begin_comment
comment|/* software version:trimble_version:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RRECVHEALTH
value|0x46
end_define

begin_comment
comment|/* receiver health:trimble_receiver_health:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RSIGNALLV
value|0x47
end_define

begin_comment
comment|/* signal levels of all satellites:trimble_signal_levels:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RMESSAGE
value|0x48
end_define

begin_comment
comment|/* GPS system message:gps-message:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RALMAHEALTH
value|0x49
end_define

begin_comment
comment|/* almanac health page for all satellites:gps_almanac_health:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSLLAPOS
value|0x4A
end_define

begin_comment
comment|/* single LLA position:gps_position(LLA):RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RMACHSTAT
value|0x4B
end_define

begin_comment
comment|/* machine code / status:trimble_status:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_ROPERPARAM
value|0x4C
end_define

begin_comment
comment|/* operating parameters:trimble_opparam:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_ROSCOFFSET
value|0x4D
end_define

begin_comment
comment|/* oscillator offset:trimble_oscoffset:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSETGPSTIME
value|0x4E
end_define

begin_comment
comment|/* response to set GPS time:trimble_setgpstime:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RUTCPARAM
value|0x4F
end_define

begin_comment
comment|/* UTC parameters:gps_utc_correction:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RANALOGDIG
value|0x53
end_define

begin_comment
comment|/* analog to digital:trimble_analogdigital:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSAT1BIAS
value|0x54
end_define

begin_comment
comment|/* one-satellite bias& bias rate:trimble_sat1bias:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RIOOPTIONS
value|0x55
end_define

begin_comment
comment|/* I/O options:trimble_iooptions:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RVELOCFIX
value|0x56
end_define

begin_comment
comment|/* velocity fix (ENU):trimble_velocfix */
end_comment

begin_define
define|#
directive|define
name|CMD_RSTATLSTFIX
value|0x57
end_define

begin_comment
comment|/* status and values of last pos. and vel.:trimble_status_lastpos:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RLOADSSATDT
value|0x58
end_define

begin_comment
comment|/* response to load satellite system data:trimble_loaddata:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSATDISABLE
value|0x59
end_define

begin_comment
comment|/* satellite disable:trimble_satdisble:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RLASTRAW
value|0x5A
end_define

begin_comment
comment|/* last raw measurement:trimble_lastraw:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSTATSATEPH
value|0x5B
end_define

begin_comment
comment|/* satellite ephemeris status:trimble_ephstatus:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSTATTRACK
value|0x5C
end_define

begin_comment
comment|/* tracking status:trimble_tracking_status:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RADDITFIX
value|0x5E
end_define

begin_comment
comment|/* additional fix data:trimble_addfix:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RALLINVIEW
value|0x6D
end_define

begin_comment
comment|/* all in view satellite selection:trimble_satview:RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RPOSFILT
value|0x72
end_define

begin_comment
comment|/* position filter parameters:trimble_posfilt:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RHEIGHTFILT
value|0x74
end_define

begin_comment
comment|/* height filter control:trimble_heightfilt:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RHIGH8CNT
value|0x76
end_define

begin_comment
comment|/* high-8 (best 4) / high-6 (overdetermined) control:trimble_high8control:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RMAXAGE
value|0x78
end_define

begin_comment
comment|/* DC MaxAge:trimble_dgpsmaxage:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RDGPSFIX
value|0x82
end_define

begin_comment
comment|/* differential position fix mode:trimble_dgpsfixmode:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RDOUBLEXYZ
value|0x83
end_define

begin_comment
comment|/* double precision XYZ:gps_position_ext(XYZ):RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RDOUBLELLA
value|0x84
end_define

begin_comment
comment|/* double precision LLA:gps_position_ext(LLA):RO|DEF */
end_comment

begin_define
define|#
directive|define
name|CMD_RDGPSSTAT
value|0x85
end_define

begin_comment
comment|/* differential correction status:trimble_dgpsstatus:RO */
end_comment

begin_define
define|#
directive|define
name|CMD_RSUPER
value|0x8F
end_define

begin_comment
comment|/* super paket::0 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cmd_info
block|{
name|unsigned
name|char
name|cmd
decl_stmt|;
comment|/* command code */
specifier|const
name|char
modifier|*
name|cmdname
decl_stmt|;
comment|/* command name */
specifier|const
name|char
modifier|*
name|cmddesc
decl_stmt|;
comment|/* command description */
specifier|const
name|char
modifier|*
name|varname
decl_stmt|;
comment|/* name of variable */
name|int
name|varmode
decl_stmt|;
comment|/* mode of variable */
block|}
name|cmd_info_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|cmd_info_t
name|trimble_rcmds
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cmd_info_t
name|trimble_scmds
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|cmd_info_t
modifier|*
name|trimble_convert
name|P
argument_list|(
operator|(
name|unsigned
name|int
name|cmd
operator|,
name|cmd_info_t
operator|*
name|tbl
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * trimble.h,v  * Revision 4.4  1999/02/28 11:41:11  kardel  * (CMD_RUTCPARAM): control variable name unification  *  * Revision 4.3  1998/12/20 23:45:25  kardel  * fix types and warnings  *  * Revision 4.2  1998/08/16 18:45:05  kardel  * (CMD_RSTATTRACK): renamed mode 6 variable name  *  * Revision 4.1  1998/08/09 22:24:35  kardel  * Trimble TSIP support  *  */
end_comment

end_unit

