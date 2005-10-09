begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/include/mbg_gps166.h,v 4.1 1998/06/12 15:07:30 kardel RELEASE_19990228_A  *  * $Created: Sun Jul 20 09:20:50 1997 $  *  * Copyright (C) 1997, 1998 by Frank Kardel  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MBG_GPS166_H
end_ifndef

begin_define
define|#
directive|define
name|MBG_GPS166_H
end_define

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   File:         GPSSERIO.H                    4.1          */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Project:      Common C Library                                        */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Compiler:     Borland C++                                             */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Author:       M. Burnicki,  Meinberg Funkuhren                        */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Description:                                                          */
end_comment

begin_comment
comment|/*     This file defines structures and codes to be used to access GPS166  */
end_comment

begin_comment
comment|/*     via its serial interface COM0. COM0 should be set to a high baud    */
end_comment

begin_comment
comment|/*     rate, default is 19200.                                             */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*     Standard GPS166 serial operation is to send a time string that is   */
end_comment

begin_comment
comment|/*     compatible with Meinberg UA31 or PZF535 DCF77 radio remote clocks.  */
end_comment

begin_comment
comment|/*     That string can be transmitted automatically once per second, once  */
end_comment

begin_comment
comment|/*     per minute or on request per ASCII '?'.                             */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*     Parameter setup or parameter readout works using blocks of binary   */
end_comment

begin_comment
comment|/*     data which have to be isolated from the standard string. A block of */
end_comment

begin_comment
comment|/*     data starts with a SOH code (ASCII Start Of Header, 0x01) followed  */
end_comment

begin_comment
comment|/*     by a message header with constant length and a data portion with    */
end_comment

begin_comment
comment|/*     variable length. The first field (cmd) of the message header holds  */
end_comment

begin_comment
comment|/*     the command code rsp. the type of data to be transmitted. The next  */
end_comment

begin_comment
comment|/*     field (len) gives the number of data bytes that are transmitted     */
end_comment

begin_comment
comment|/*     after the header. This number ranges from 0 to sizeof( MSG_DATA ).  */
end_comment

begin_comment
comment|/*     The third field (data_csum) holds a checksum of all data bytes and  */
end_comment

begin_comment
comment|/*     the last field of the header finally holds the checksum of the.     */
end_comment

begin_comment
comment|/*     header.                                                             */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/* the control codes defined below are to be or'ed with a command/type code */
end_comment

begin_define
define|#
directive|define
name|GPS_REQACK
value|0x8000
end_define

begin_comment
comment|/* to GPS166: request acknowledge */
end_comment

begin_define
define|#
directive|define
name|GPS_ACK
value|0x4000
end_define

begin_comment
comment|/* from GPS166: acknowledge a command */
end_comment

begin_define
define|#
directive|define
name|GPS_NACK
value|0x2000
end_define

begin_comment
comment|/* from GPS166: error receiving command */
end_comment

begin_define
define|#
directive|define
name|GPS_CTRL_MSK
value|0xF000
end_define

begin_comment
comment|/* masks control code from command */
end_comment

begin_comment
comment|/* The codes below specify commands/types of data to be supplied to GPS166: */
end_comment

begin_comment
comment|/*                            GPS166 auto-message to host            */
end_comment

begin_comment
comment|/*                            þ   host request, GPS166 response      */
end_comment

begin_comment
comment|/*                            þ   þ   host download to GPS166        */
end_comment

begin_comment
comment|/*                            þ   þ   þ                              */
end_comment

begin_enum
enum|enum
block|{
comment|/*                    þ   þ   þ                              */
comment|/* system data */
name|GPS_AUTO_ON
init|=
literal|0x000
block|,
comment|/* þ   þ   þ X þ enable auto-messages from GPS166 */
name|GPS_AUTO_OFF
block|,
comment|/* þ   þ   þ X þ disable auto-messages from GPS166 */
name|GPS_SW_REV
block|,
comment|/* þ   þ X þ   þ request software revision */
name|GPS_STAT
block|,
comment|/* þ   þ X þ   þ request status of buffered variables */
name|GPS_TIME
block|,
comment|/* þ X þ   þ X þ current time or capture or init board time */
name|GPS_POS_XYZ
block|,
comment|/* þ   þ X þ X þ current position in ECEF coords */
name|GPS_POS_LLA
block|,
comment|/* þ   þ X þ X þ current position in geographic coords */
name|GPS_TZDL
block|,
comment|/* þ   þ X þ X þ time zone / daylight saving */
name|GPS_PORT_PARM
block|,
comment|/* þ   þ X þ X þ parameters of the serial ports */
name|GPS_SYNTH
block|,
comment|/* þ   þ X þ X þ synthesizer's frequency and phase */
name|GPS_ANT_INFO
block|,
comment|/* þ X þ X þ   þ time diff after antenna disconnect */
name|GPS_UCAP
block|,
comment|/* þ X þ X þ   þ user capture */
comment|/* GPS data */
name|GPS_CFGH
init|=
literal|0x100
block|,
comment|/* þ   þ X þ X þ SVs' configuration and health codes */
name|GPS_ALM
block|,
comment|/* þ   þ X þ X þ one SV's almanac */
name|GPS_EPH
block|,
comment|/* þ   þ X þ X þ one SV's ephemeris */
name|GPS_UTC
block|,
comment|/* þ   þ X þ X þ UTC correction parameters */
name|GPS_IONO
block|,
comment|/* þ   þ X þ X þ ionospheric correction parameters */
name|GPS_ASCII_MSG
comment|/* þ   þ X þ   þ the GPS ASCII message */
block|}
enum|;
end_enum

begin_comment
comment|/*  * modelled after GPSDEFS.H Revision 1.5  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   File:         GPSDEFS.H                     4.1          */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Project:      Common C Library                                        */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Compiler:     Borland C++                                             */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Author:       M. Burnicki,  Meinberg Funkuhren                        */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Description:                                                          */
end_comment

begin_comment
comment|/*     General definitions to be used with GPS166                          */
end_comment

begin_comment
comment|/*     GPS166 Rev. 1.23 or above                                           */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/*   Modifications: see file GPSLIB.TXT                                    */
end_comment

begin_comment
comment|/*                                                                         */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|_GPSDEFS_H
end_define

begin_comment
comment|/* the type of various checksums */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CSUM_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CSUM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_CSUM_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the message header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|gps_cmd
decl_stmt|;
name|unsigned
name|short
name|gps_len
decl_stmt|;
name|unsigned
name|short
name|gps_data_csum
decl_stmt|;
name|unsigned
name|short
name|gps_hdr_csum
decl_stmt|;
block|}
name|GPS_MSG_HDR
typedef|;
end_typedef

begin_comment
comment|/* a struct used to hold the software revision information */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|code
decl_stmt|;
comment|/* e.g. 0x0120 means rev. 1.20 */
name|unsigned
name|char
name|name
index|[
literal|17
index|]
decl_stmt|;
comment|/* used to identify customized versions */
block|}
name|SW_REV
typedef|;
end_typedef

begin_comment
comment|/* GPS ASCII message */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/* checksum of the remaining bytes */
name|short
name|valid
decl_stmt|;
comment|/* flag data are valid */
name|char
name|s
index|[
literal|23
index|]
decl_stmt|;
comment|/* 22 chars GPS ASCII message plus trailing zero */
block|}
name|ASCII_MSG
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MIN_SVNO
value|1
end_define

begin_comment
comment|/* min. SV number */
end_comment

begin_define
define|#
directive|define
name|MAX_SVNO
value|32
end_define

begin_comment
comment|/* max. SV number */
end_comment

begin_define
define|#
directive|define
name|N_SVNO
value|( MAX_SVNO - MIN_SVNO + 1)
end_define

begin_comment
comment|/* number of possibly active SVs */
end_comment

begin_typedef
typedef|typedef
name|short
name|SVNO
typedef|;
end_typedef

begin_comment
comment|/* the number of a SV */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|HEALTH
typedef|;
end_typedef

begin_comment
comment|/* a SV's health code */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CFG
typedef|;
end_typedef

begin_comment
comment|/* a SV's configuration code */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|IOD
typedef|;
end_typedef

begin_comment
comment|/* Issue-Of-Data code */
end_comment

begin_comment
comment|/* Date and time referred to the linear time scale defined by GPS. */
end_comment

begin_comment
comment|/* GPS time is defined by the number of weeks since midnight from */
end_comment

begin_comment
comment|/* January 5, 1980 to January 6, 1980 plus the number of seconds of */
end_comment

begin_comment
comment|/* the current week plus fractions of a second. GPS time differs from */
end_comment

begin_comment
comment|/* UTC because UTC is corrected with leap seconds while GPS time scale */
end_comment

begin_comment
comment|/* is continuous. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|short
name|wn
decl_stmt|;
comment|/* the week number since GPS has been installed */
name|unsigned
name|long
name|sec
decl_stmt|;
comment|/* the second of that week */
name|unsigned
name|long
name|tick
decl_stmt|;
comment|/* fractions of a second; scale: 1E-7 */
block|}
name|T_GPS
typedef|;
end_typedef

begin_comment
comment|/* Local date and time computed from GPS time. The current number */
end_comment

begin_comment
comment|/* of leap seconds have to be added to get UTC from GPS time. */
end_comment

begin_comment
comment|/* Additional corrections could have been made according to the */
end_comment

begin_comment
comment|/* time zone/daylight saving parameters (TZDL, see below) defined */
end_comment

begin_comment
comment|/* by the user. The status field can be checked to see which corrections */
end_comment

begin_comment
comment|/* have been applied. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TM_DEFINED
end_ifndef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|year
decl_stmt|;
comment|/* 0..9999 */
name|char
name|month
decl_stmt|;
comment|/* 1..12 */
name|char
name|mday
decl_stmt|;
comment|/* 1..31 */
name|short
name|yday
decl_stmt|;
comment|/* 1..366 */
name|char
name|wday
decl_stmt|;
comment|/* 0..6 == Sun..Sat */
name|char
name|hour
decl_stmt|;
comment|/* 0..23 */
name|char
name|minute
decl_stmt|;
comment|/* 0..59 */
name|char
name|second
decl_stmt|;
comment|/* 0..59 */
name|long
name|frac
decl_stmt|;
comment|/* fractions of a second, scale 1E-7 */
name|long
name|offs_from_utc
decl_stmt|;
comment|/* local time's offset from UTC */
name|unsigned
name|short
name|status
decl_stmt|;
comment|/* flags */
block|}
name|TM
typedef|;
end_typedef

begin_comment
comment|/* status flags used with conversion from GPS time to local time */
end_comment

begin_define
define|#
directive|define
name|TM_UTC
value|0x01
end_define

begin_comment
comment|/* UTC correction has been made */
end_comment

begin_define
define|#
directive|define
name|TM_LOCAL
value|0x02
end_define

begin_comment
comment|/* UTC has been converted to local time */
end_comment

begin_define
define|#
directive|define
name|TM_DL_ANN
value|0x04
end_define

begin_comment
comment|/* state of daylight saving is going to change */
end_comment

begin_define
define|#
directive|define
name|TM_DL_ENB
value|0x08
end_define

begin_comment
comment|/* daylight saving is enabled */
end_comment

begin_define
define|#
directive|define
name|TM_LS_ANN
value|0x10
end_define

begin_comment
comment|/* leap second will be inserted */
end_comment

begin_define
define|#
directive|define
name|TM_LS_ENB
value|0x20
end_define

begin_comment
comment|/* current second is leap second */
end_comment

begin_define
define|#
directive|define
name|_TM_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the status flags below are defined starting with rev. 1.32 */
end_comment

begin_define
define|#
directive|define
name|TM_ANT_DISCONN
value|0x1000
end_define

begin_comment
comment|/* antenna currently disconnected */
end_comment

begin_define
define|#
directive|define
name|TM_SYN_FLAG
value|0x2000
end_define

begin_comment
comment|/* TIME_SYN output is low */
end_comment

begin_define
define|#
directive|define
name|TM_NO_SYNC
value|0x4000
end_define

begin_comment
comment|/* not sync'ed after reset */
end_comment

begin_define
define|#
directive|define
name|TM_NO_POS
value|0x8000
end_define

begin_comment
comment|/* position not computed after reset, */
end_comment

begin_comment
comment|/*   LOCK LED off */
end_comment

begin_comment
comment|/* a struct used to transmit information on date and time */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|channel
decl_stmt|;
comment|/* -1: the current time; 0, 1: capture 0, 1 */
name|T_GPS
name|t
decl_stmt|;
comment|/* time in GPS format */
name|TM
name|tm
decl_stmt|;
comment|/* that time converted to local time */
block|}
name|TTM
typedef|;
end_typedef

begin_comment
comment|/* Two types of variables used to store a position. Type XYZ is */
end_comment

begin_comment
comment|/* used with a position in earth centered, earth fixed (ECEF) */
end_comment

begin_comment
comment|/* coordinates whereas type LLA holds such a position converted */
end_comment

begin_comment
comment|/* to geographic coordinates as defined by WGS84 (World Geodetic */
end_comment

begin_comment
comment|/* System from 1984). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XYZ_DEFINED
end_ifndef

begin_comment
comment|/* sequence and number of components of a cartesian position */
end_comment

begin_enum
enum|enum
block|{
name|XP
block|,
name|YP
block|,
name|ZP
block|,
name|N_XYZ
block|}
enum|;
end_enum

begin_comment
comment|/* a type of array holding a cartesian position */
end_comment

begin_typedef
typedef|typedef
name|l_fp
name|XYZ
index|[
name|N_XYZ
index|]
typedef|;
end_typedef

begin_comment
comment|/* values are in [m] */
end_comment

begin_define
define|#
directive|define
name|_XYZ_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_LLA_DEFINED
end_ifndef

begin_comment
comment|/* sequence and number of components of a geographic position */
end_comment

begin_enum
enum|enum
block|{
name|LAT
block|,
name|LON
block|,
name|ALT
block|,
name|N_LLA
block|}
enum|;
end_enum

begin_comment
comment|/* latitude, longitude, altitude */
end_comment

begin_comment
comment|/* a type of array holding a geographic position */
end_comment

begin_typedef
typedef|typedef
name|l_fp
name|LLA
index|[
name|N_LLA
index|]
typedef|;
end_typedef

begin_comment
comment|/* lon, lat in [rad], alt in [m] */
end_comment

begin_define
define|#
directive|define
name|_LLA_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Synthesizer parameters. Synthesizer frequency is expressed as a */
end_comment

begin_comment
comment|/* four digit decimal number (freq) to be multiplied by 0.1 Hz and an */
end_comment

begin_comment
comment|/* base 10 exponent (range). If the effective frequency is less than */
end_comment

begin_comment
comment|/* 10 kHz its phase is synchronized corresponding to the variable phase. */
end_comment

begin_comment
comment|/* Phase may be in a range from -360° to +360° with a resolution of 0.1°, */
end_comment

begin_comment
comment|/* so the resulting numbers to be stored are in a range of -3600 to +3600. */
end_comment

begin_comment
comment|/* Example: */
end_comment

begin_comment
comment|/* Assume the value of freq is 2345 (decimal) and the value of phase is 900. */
end_comment

begin_comment
comment|/* If range == 0 the effective frequency is 234.5 Hz with a phase of +90°. */
end_comment

begin_comment
comment|/* If range == 1 the synthesizer will generate a 2345 Hz output frequency */
end_comment

begin_comment
comment|/* and so on. */
end_comment

begin_comment
comment|/* Limitations: */
end_comment

begin_comment
comment|/* If freq == 0 the synthesizer is disabled. If range == 0 the least */
end_comment

begin_comment
comment|/* significant digit of freq is limited to 0, 3, 5 or 6. The resulting */
end_comment

begin_comment
comment|/* frequency is shown in the examples below: */
end_comment

begin_comment
comment|/*     freq == 1230  -->  123.0 Hz */
end_comment

begin_comment
comment|/*     freq == 1233  -->  123 1/3 Hz (real 1/3 Hz, NOT 123.3 Hz) */
end_comment

begin_comment
comment|/*     freq == 1235  -->  123.5 Hz */
end_comment

begin_comment
comment|/*     freq == 1236  -->  123 2/3 Hz (real 2/3 Hz, NOT 123.6 Hz) */
end_comment

begin_comment
comment|/* If range == MAX_RANGE the value of freq must not exceed 1200, so the */
end_comment

begin_comment
comment|/* output frequency is limited to 12 MHz. */
end_comment

begin_comment
comment|/* Phase will be ignored if the resulting frequency is greater or equal */
end_comment

begin_comment
comment|/* to 10 kHz. */
end_comment

begin_define
define|#
directive|define
name|MAX_SYNTH_FREQ
value|1200
end_define

begin_comment
comment|/* if range == MAX_SYNTH_RANGE */
end_comment

begin_define
define|#
directive|define
name|MIN_SYNTH_RANGE
value|0
end_define

begin_define
define|#
directive|define
name|MAX_SYNTH_RANGE
value|5
end_define

begin_define
define|#
directive|define
name|MAX_SYNTH_PHASE
value|3600
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|freq
decl_stmt|;
comment|/* four digits used; scale: 0.1; e.g. 1234 -> 123.4 Hz */
name|short
name|range
decl_stmt|;
comment|/* scale factor for freq; 0..MAX_SYNTH_RANGE */
name|short
name|phase
decl_stmt|;
comment|/* -MAX_SYNTH_PHASE..+MAX_SYNTH_PHASE;>0 -> pulses later */
block|}
name|SYNTH
typedef|;
end_typedef

begin_comment
comment|/* Time zone/daylight saving parameters. */
end_comment

begin_comment
comment|/* the name of a time zone, 5 characters plus trailing zero */
end_comment

begin_typedef
typedef|typedef
name|char
name|TZ_NAME
index|[
literal|6
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|offs
decl_stmt|;
comment|/* offset from UTC to local time [sec] */
name|long
name|offs_dl
decl_stmt|;
comment|/* additional offset if daylight saving enabled [sec] */
name|TM
name|tm_on
decl_stmt|;
comment|/* date/time when daylight saving starts */
name|TM
name|tm_off
decl_stmt|;
comment|/* date/time when daylight saving ends */
name|TZ_NAME
name|name
index|[
literal|2
index|]
decl_stmt|;
comment|/* names without and with daylight saving enabled */
block|}
name|TZDL
typedef|;
end_typedef

begin_comment
comment|/* The constant below is defined beginning with software rev. 1.29. */
end_comment

begin_comment
comment|/* If the year in tzdl.tmon and tzdl.tm_off is or'ed with that constant, */
end_comment

begin_comment
comment|/* the receiver automatically generates daylight saving year by year. */
end_comment

begin_comment
comment|/* See GPSLIB.TXT for more information. */
end_comment

begin_define
define|#
directive|define
name|DL_AUTO_FLAG
value|0x8000
end_define

begin_comment
comment|/* Example: */
end_comment

begin_comment
comment|/* for automatic daylight saving enable/disable in Central Europe, */
end_comment

begin_comment
comment|/* the variables are to be set as shown below: */
end_comment

begin_comment
comment|/*   offs = 3600L           one hour from UTC */
end_comment

begin_comment
comment|/*   offs_dl = 3600L        one additional hour if daylight saving enabled */
end_comment

begin_comment
comment|/*   tm_on = first Sunday from March 25, 02:00:00h ( year |= DL_AUTO_FLAG ) */
end_comment

begin_comment
comment|/*   tm_off = first Sunday from Sept 24, 03:00:00h ( year |= DL_AUTO_FLAG ) */
end_comment

begin_comment
comment|/*   name[0] == "MEZ  "     name if daylight saving not enabled */
end_comment

begin_comment
comment|/*   name[1] == "MESZ "     name if daylight saving is enabled */
end_comment

begin_comment
comment|/* the structure below was defined in rev. 1.31. It reflects the status */
end_comment

begin_comment
comment|/* of the antenna, the times of last disconnect/reconnect and the boards */
end_comment

begin_comment
comment|/* clock offset after the phase of disconnection. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|status
decl_stmt|;
comment|/* current status of antenna */
name|TM
name|tm_disconn
decl_stmt|;
comment|/* time of antenna disconnect */
name|TM
name|tm_reconn
decl_stmt|;
comment|/* time of antenna reconnect */
name|long
name|delta_t
decl_stmt|;
comment|/* clock offset at reconnect time, units: TICKS_PER_SEC */
block|}
name|ANT_INFO
typedef|;
end_typedef

begin_comment
comment|/* the status field may be set to one of the values below: */
end_comment

begin_enum
enum|enum
block|{
name|ANT_INVALID
block|,
comment|/* struct not set yet because ant. has not been disconn. */
name|ANT_DISCONN
block|,
comment|/* ant. now disconn., tm_reconn and delta_t not set */
name|ANT_RECONN
comment|/* ant. has been disconn. and reconn., all fields valid */
block|}
enum|;
end_enum

begin_comment
comment|/* Summary of configuration and health data of all SVs. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/* checksum of the remaining bytes */
name|short
name|valid
decl_stmt|;
comment|/* flag data are valid */
name|T_GPS
name|tot_51
decl_stmt|;
comment|/* time of transmission, page 51 */
name|T_GPS
name|tot_63
decl_stmt|;
comment|/* time of transmission, page 63 */
name|T_GPS
name|t0a
decl_stmt|;
comment|/* complete reference time almanac */
name|CFG
name|cfg
index|[
name|N_SVNO
index|]
decl_stmt|;
comment|/* SV configuration from page 63 */
name|HEALTH
name|health
index|[
name|N_SVNO
index|]
decl_stmt|;
comment|/* SV health from pages 51, 63 */
block|}
name|CFGH
typedef|;
end_typedef

begin_comment
comment|/* UTC correction parameters */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/*    checksum of the remaining bytes                  */
name|short
name|valid
decl_stmt|;
comment|/*    flag data are valid                              */
name|T_GPS
name|t0t
decl_stmt|;
comment|/*    Reference Time UTC Parameters              [sec] */
name|l_fp
name|A0
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 0             [sec] */
name|l_fp
name|A1
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 1         [sec/sec] */
name|ushort
name|WNlsf
decl_stmt|;
comment|/*  week number of nearest leap second                 */
name|short
name|DNt
decl_stmt|;
comment|/*  the day number at the end of which LS is inserted  */
name|char
name|delta_tls
decl_stmt|;
comment|/*                                                     */
name|char
name|delta_tlsf
decl_stmt|;
comment|/*                                                     */
block|}
name|UTC
typedef|;
end_typedef

begin_comment
comment|/* a struct used to hold the settings of a serial port */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COM_PARM_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|long
name|BAUD_RATE
typedef|;
end_typedef

begin_comment
comment|/* indices used to identify a parameter in the framing string */
end_comment

begin_enum
enum|enum
block|{
name|F_DBITS
block|,
name|F_PRTY
block|,
name|F_STBITS
block|}
enum|;
end_enum

begin_comment
comment|/* types of handshake */
end_comment

begin_enum
enum|enum
block|{
name|HS_NONE
block|,
name|HS_XONXOFF
block|,
name|HS_RTSCTS
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
struct|struct
block|{
name|BAUD_RATE
name|baud_rate
decl_stmt|;
comment|/* e.g. 19200L */
name|char
name|framing
index|[
literal|4
index|]
decl_stmt|;
comment|/* e.g. "8N1" */
name|short
name|handshake
decl_stmt|;
comment|/* a numeric value, only HS_NONE supported yet */
block|}
name|COM_PARM
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_COM_PARM_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the codes below define what has to comes out of the serial ports */
end_comment

begin_enum
enum|enum
block|{
name|STR_ON_REQ
block|,
name|STR_PER_SEC
block|,
name|STR_PER_MIN
block|,
name|N_STR_MODE_0
block|,
comment|/* COM0 and COM1 */
name|STR_UCAP
init|=
name|N_STR_MODE_0
block|,
name|STR_UCAP_REQ
block|,
name|N_STR_MODE_1
comment|/* COM1 only */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|N_COM
value|2
end_define

begin_comment
comment|/* the number of serial ports */
end_comment

begin_comment
comment|/* the structure used to store the modes of both serial ports */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|COM_PARM
name|com
index|[
name|N_COM
index|]
decl_stmt|;
comment|/* COM0 and COM1 settings */
name|u_char
name|mode
index|[
name|N_COM
index|]
decl_stmt|;
comment|/* COM0 and COM1 output mode */
block|}
name|PORT_PARM
typedef|;
end_typedef

begin_comment
comment|/* Ephemeris parameters of one specific SV. Needed to compute the position */
end_comment

begin_comment
comment|/* of a satellite at a given time with high precision. Valid for an */
end_comment

begin_comment
comment|/* interval of 4 to 6 hours from start of transmission. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/*    checksum of the remaining bytes                  */
name|short
name|valid
decl_stmt|;
comment|/*    flag data are valid                              */
name|HEALTH
name|health
decl_stmt|;
comment|/*    health indication of transmitting SV      [---]  */
name|IOD
name|IODC
decl_stmt|;
comment|/*    Issue Of Data, Clock                             */
name|IOD
name|IODE2
decl_stmt|;
comment|/*    Issue of Data, Ephemeris (Subframe 2)            */
name|IOD
name|IODE3
decl_stmt|;
comment|/*    Issue of Data, Ephemeris (Subframe 3)            */
name|T_GPS
name|tt
decl_stmt|;
comment|/*    time of transmission                             */
name|T_GPS
name|t0c
decl_stmt|;
comment|/*    Reference Time Clock                      [---]  */
name|T_GPS
name|t0e
decl_stmt|;
comment|/*    Reference Time Ephemeris                  [---]  */
name|l_fp
name|sqrt_A
decl_stmt|;
comment|/*    Square Root of semi-major Axis        [sqrt(m)]  */
name|l_fp
name|e
decl_stmt|;
comment|/*    Eccentricity                              [---]  */
name|l_fp
name|M0
decl_stmt|;
comment|/*  ± Mean Anomaly at Ref. Time                 [rad]  */
name|l_fp
name|omega
decl_stmt|;
comment|/*  ± Argument of Perigee                       [rad]  */
name|l_fp
name|OMEGA0
decl_stmt|;
comment|/*  ± Longit. of Asc. Node of orbit plane       [rad]  */
name|l_fp
name|OMEGADOT
decl_stmt|;
comment|/*  ± Rate of Right Ascension               [rad/sec]  */
name|l_fp
name|deltan
decl_stmt|;
comment|/*  ± Mean Motion Diff. from computed value [rad/sec]  */
name|l_fp
name|i0
decl_stmt|;
comment|/*  ± Inclination Angle                         [rad]  */
name|l_fp
name|idot
decl_stmt|;
comment|/*  ± Rate of Inclination Angle             [rad/sec]  */
name|l_fp
name|crc
decl_stmt|;
comment|/*  ± Cosine Corr. Term to Orbit Radius           [m]  */
name|l_fp
name|crs
decl_stmt|;
comment|/*  ± Sine Corr. Term to Orbit Radius             [m]  */
name|l_fp
name|cuc
decl_stmt|;
comment|/*  ± Cosine Corr. Term to Arg. of Latitude     [rad]  */
name|l_fp
name|cus
decl_stmt|;
comment|/*  ± Sine Corr. Term to Arg. of Latitude       [rad]  */
name|l_fp
name|cic
decl_stmt|;
comment|/*  ± Cosine Corr. Term to Inclination Angle    [rad]  */
name|l_fp
name|cis
decl_stmt|;
comment|/*  ± Sine Corr. Term to Inclination Angle      [rad]  */
name|l_fp
name|af0
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 0            [sec]  */
name|l_fp
name|af1
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 1        [sec/sec]  */
name|l_fp
name|af2
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 2       [sec/sec²]  */
name|l_fp
name|tgd
decl_stmt|;
comment|/*  ± estimated group delay differential        [sec]  */
name|u_short
name|URA
decl_stmt|;
comment|/*    predicted User Range Accuracy                    */
name|u_char
name|L2code
decl_stmt|;
comment|/*    code on L2 channel                         [---] */
name|u_char
name|L2flag
decl_stmt|;
comment|/*    L2 P data flag                             [---] */
block|}
name|EPH
typedef|;
end_typedef

begin_comment
comment|/* Almanac parameters of one specific SV. A reduced precision set of */
end_comment

begin_comment
comment|/* parameters used to check if a satellite is in view at a given time. */
end_comment

begin_comment
comment|/* Valid for an interval of more than 7 days from start of transmission. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/*    checksum of the remaining bytes                  */
name|short
name|valid
decl_stmt|;
comment|/*    flag data are valid                              */
name|HEALTH
name|health
decl_stmt|;
comment|/*                                               [---] */
name|T_GPS
name|t0a
decl_stmt|;
comment|/*    Reference Time Almanac                     [sec] */
name|l_fp
name|sqrt_A
decl_stmt|;
comment|/*    Square Root of semi-major Axis         [sqrt(m)] */
name|l_fp
name|e
decl_stmt|;
comment|/*    Eccentricity                               [---] */
name|l_fp
name|M0
decl_stmt|;
comment|/*  ± Mean Anomaly at Ref. Time                  [rad] */
name|l_fp
name|omega
decl_stmt|;
comment|/*  ± Argument of Perigee                        [rad] */
name|l_fp
name|OMEGA0
decl_stmt|;
comment|/*  ± Longit. of Asc. Node of orbit plane        [rad] */
name|l_fp
name|OMEGADOT
decl_stmt|;
comment|/*  ± Rate of Right Ascension                [rad/sec] */
name|l_fp
name|deltai
decl_stmt|;
comment|/*  ±                                            [rad] */
name|l_fp
name|af0
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 0             [sec] */
name|l_fp
name|af1
decl_stmt|;
comment|/*  ± Clock Correction Coefficient 1         [sec/sec] */
block|}
name|ALM
typedef|;
end_typedef

begin_comment
comment|/* ionospheric correction parameters */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|/*    checksum of the remaining bytes                  */
name|short
name|valid
decl_stmt|;
comment|/*    flag data are valid                              */
name|l_fp
name|alpha_0
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Alpha 0              [sec] */
name|l_fp
name|alpha_1
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Alpha 1          [sec/deg] */
name|l_fp
name|alpha_2
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Alpha 2        [sec/deg^2] */
name|l_fp
name|alpha_3
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Alpha 3        [sec/deg^3] */
name|l_fp
name|beta_0
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Beta 0               [sec] */
name|l_fp
name|beta_1
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Beta 1           [sec/deg] */
name|l_fp
name|beta_2
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Beta 2         [sec/deg^2] */
name|l_fp
name|beta_3
decl_stmt|;
comment|/*    Ionosph. Corr. Coeff. Beta 3         [sec/deg^3] */
block|}
name|IONO
typedef|;
end_typedef

begin_decl_stmt
name|void
name|mbg_tm_str
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|TM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mbg_tgps_str
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|T_GPS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_header
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|GPS_MSG_HDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|put_mbg_header
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|GPS_MSG_HDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_sw_rev
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|SW_REV
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_ascii_msg
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|ASCII_MSG
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_svno
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|SVNO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_health
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|HEALTH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_cfg
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|CFG
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_tgps
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|T_GPS
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_tm
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|TM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_ttm
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|TTM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_synth
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|SYNTH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_tzdl
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|TZDL
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_antinfo
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|ANT_INFO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_cfgh
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|CFGH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_utc
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|UTC
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_lla
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|LLA
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_xyz
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|XYZ
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_portparam
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|PORT_PARM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_eph
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|EPH
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_alm
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|ALM
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_mbg_iono
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|*
operator|,
name|IONO
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|long
name|mbg_csum
name|P
argument_list|(
operator|(
name|unsigned
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * mbg_gps166.h,v  * Revision 4.1  1998/06/12 15:07:30  kardel  * fixed prototyping  *  * Revision 4.0  1998/04/10 19:50:42  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:34  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:38  kardel  * new parse structure  *  */
end_comment

end_unit

