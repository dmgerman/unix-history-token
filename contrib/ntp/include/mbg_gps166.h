begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/REPOSITORY/ntp4-dev/include/mbg_gps166.h,v 4.7 2006/06/22 18:41:43 kardel RELEASE_20060622_A  *  * mbg_gps166.h,v 4.7 2006/06/22 18:41:43 kardel RELEASE_20060622_A  *  * $Created: Sun Jul 20 09:20:50 1997 $  *  * File GPSSERIO.H Copyright (c) by Meinberg Funkuhren (www.meinberg.de)  *  * Linkage to PARSE:  * Copyright (c) 1997-2005 by Frank Kardel<kardel<AT> ntp.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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
comment|/***************************************************************************  *  *  Definitions taken from Meinberg's gpsserio.h and gpsdefs.h files.  *  *  Author:  Martin Burnicki, Meinberg Funkuhren  *  *  Copyright (c) Meinberg Funkuhren, Bad Pyrmont, Germany  *  *  Description:  *    Structures and codes to be used to access Meinberg GPS clocks via  *    their serial interface COM0. COM0 should be set to a high baud rate,  *    default is 19200.  *  *    Standard Meinberg GPS serial operation is to send the Meinberg  *    standard time string automatically once per second, once per  *    minute, or on request per ASCII '?'.  *  *    GPS parameter setup or parameter readout uses blocks of binary  *    data which have to be isolated from the standard string. A block  *    of data starts with a SOH code (ASCII Start Of Header, 0x01)  *    followed by a message header with constant length and a block of  *    data with variable length.  *  *    The first field (cmd) of the message header holds the command  *    code resp. the type of data to be transmitted. The next field (len)  *    gives the number of data bytes that follow the header. This number  *    ranges from 0 to sizeof( MSG_DATA ). The third field (data_csum)  *    holds a checksum of all data bytes and the last field of the header  *    finally holds the checksum of the header itself.  *  ***************************************************************************/
end_comment

begin_comment
comment|/**  * @brief GPS epoch bias from ordinary time_t epoch  *  * The Unix time_t epoch is usually 1970-01-01 00:00 whereas  * the GPS epoch is 1980-01-06 00:00, so the difference is 10 years,  * plus 2 days due to leap years (1972 and 1976), plus the difference  * of the day-of-month (6 - 1), so:<br>  *  * time_t t = ( gps_week * ::SECS_PER_WEEK ) + sec_of_week + ::GPS_SEC_BIAS  */
end_comment

begin_define
define|#
directive|define
name|GPS_SEC_BIAS
value|315964800UL
end_define

begin_comment
comment|// ( ( ( 10UL * 365UL ) + 2 + 5 ) * SECS_PER_DAY )
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COM_HS_DEFINED
end_ifndef

begin_comment
comment|/**    * @brief Enumeration of handshake modes    */
end_comment

begin_enum
enum|enum
name|COM_HANSHAKE_MODES
block|{
name|HS_NONE
block|,
name|HS_XONXOFF
block|,
name|HS_RTSCTS
block|,
name|N_COM_HS
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_COM_HS_DEFINED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_COM_PARM_DEFINED
end_ifndef

begin_comment
comment|/**    * @brief A data type to configure a serial port's baud rate    *    * @see ::MBG_BAUD_RATES    */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|BAUD_RATE
typedef|;
end_typedef

begin_comment
comment|/**    * @brief Indices used to identify a parameter in the framing string    *    * @see ::MBG_FRAMING_STRS    */
end_comment

begin_enum
enum|enum
name|MBG_FRAMING_STR_IDXS
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
comment|/**    * @brief A structure to store the configuration of a serial port    */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|BAUD_RATE
name|baud_rate
decl_stmt|;
comment|///< transmission speed, e.g. 19200L, see ::MBG_BAUD_RATES
name|char
name|framing
index|[
literal|4
index|]
decl_stmt|;
comment|///< ASCIIZ framing string, e.g. "8N1" or "7E2", see ::MBG_FRAMING_STRS
name|int16_t
name|handshake
decl_stmt|;
comment|///< handshake mode, yet only ::HS_NONE supported
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
comment|/**  * @brief Enumeration of modes supported for time string transmission  *  * This determines e.g. at which point in time a string starts  * to be transmitted via the serial port.  * Used with ::PORT_SETTINGS::mode.  *  * @see ::STR_MODE_MASKS  */
end_comment

begin_enum
enum|enum
name|STR_MODES
block|{
name|STR_ON_REQ
block|,
comment|///< transmission on request by received '?' character only
name|STR_PER_SEC
block|,
comment|///< transmission automatically if second changes
name|STR_PER_MIN
block|,
comment|///< transmission automatically if minute changes
name|STR_AUTO
block|,
comment|///< transmission automatically if required, e.g. on capture event
name|STR_ON_REQ_SEC
block|,
comment|///< transmission if second changes and a request has been received before
name|N_STR_MODE
comment|///< the number of known modes
block|}
enum|;
end_enum

begin_comment
comment|/**  * The number of serial ports which are at least available  * even with very old GPS receiver models. For devices providing  * a ::RECEIVER_INFO structure the number of provided COM ports  * is available in ::RECEIVER_INFO::n_com_ports.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_N_COM
value|2
end_define

begin_comment
comment|/**  * @brief A The structure used to store the configuration of two serial ports  *  * @deprecated This structure is deprecated, ::PORT_SETTINGS and related structures  * should be used instead, if supported by the device.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|COM_PARM
name|com
index|[
name|DEFAULT_N_COM
index|]
decl_stmt|;
comment|///< COM0 and COM1 settings
name|uint8_t
name|mode
index|[
name|DEFAULT_N_COM
index|]
decl_stmt|;
comment|///< COM0 and COM1 output mode
block|}
name|PORT_PARM
typedef|;
end_typedef

begin_comment
comment|/**  * @brief The type of a GPS command code  *  * @see ::GPS_CMD_CODES  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|GPS_CMD
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Control codes to be or'ed with a particular command/type code  */
end_comment

begin_enum
enum|enum
name|GPS_CMD_CTRL_CODES
block|{
name|GPS_REQACK
init|=
literal|0x8000
block|,
comment|///< to device: request acknowledge
name|GPS_ACK
init|=
literal|0x4000
block|,
comment|///< from device: acknowledge a command
name|GPS_NACK
init|=
literal|0x2000
block|,
comment|///< from device: error evaluating a command
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|GPS_CTRL_MSK
value|0xF000
end_define

begin_comment
comment|///< bit mask of all ::GPS_CMD_CTRL_CODES
end_comment

begin_comment
comment|/**  * @brief Command codes for the binary protocol  *  * These codes specify commands and associated data types used by Meinberg's  * binary protocol to exchange data with a device via serial port, direct USB,  * or socket I/O.  *  * Some commands and associated data structures can be read (r) from a device, others  * can be written (w) to the device, and some can also be sent automatically (a) by  * a device after a ::GPS_AUTO_ON command has been sent to the device.  * The individual command codes are marked with (rwa) accordingly, where '-' is used  * to indicate that a particular mode is not supported.  *  * @note Not all command code are supported by all devices.  * See the hints for a particular command.  *  * @note If ::GPS_ALM, ::GPS_EPH or a code named ..._IDX is sent to retrieve  * some data from a device then an uint16_t parameter must be also supplied  * in order to specify the index number of the data set to be returned.  * The valid index range depends on the command code.  * For ::GPS_ALM and ::GPS_EPH the index is the SV number which may be 0 or  * ::MIN_SVNO_GPS to ::MAX_SVNO_GPS. If the number is 0 then all ::N_SVNO_GPS  * almanacs or ephemeris data structures are returned.  *  * @see ::GPS_CMD_CODES_TABLE  */
end_comment

begin_enum
enum|enum
name|GPS_CMD_CODES
block|{
comment|/* system data */
name|GPS_AUTO_ON
init|=
literal|0x000
block|,
comment|///< (-w-) no data, enable auto-msgs from device
name|GPS_AUTO_OFF
block|,
comment|///< (-w-) no data, disable auto-msgs from device
name|GPS_SW_REV
block|,
comment|///< (r--) deprecated, ::SW_REV, software revision, use only if ::GPS_RECEIVER_INFO not supp.
name|GPS_BVAR_STAT
block|,
comment|///< (r--) ::BVAR_STAT, status of buffered variables, only if ::GPS_MODEL_HAS_BVAR_STAT
name|GPS_TIME
block|,
comment|///< (-wa) ::TTM, current time or capture, or init board time
name|GPS_POS_XYZ
block|,
comment|///< (rw-) ::XYZ, current position in ECEF coordinates, only if ::GPS_MODEL_HAS_POS_XYZ
name|GPS_POS_LLA
block|,
comment|///< (rw-) ::LLA, current position in geographic coordinates, only if ::GPS_MODEL_HAS_POS_LLA
name|GPS_TZDL
block|,
comment|///< (rw-) ::TZDL, time zone / daylight saving, only if ::GPS_MODEL_HAS_TZDL
name|GPS_PORT_PARM
block|,
comment|///< (rw-) deprecated, ::PORT_PARM, use ::PORT_SETTINGS etc. if ::GPS_RECEIVER_INFO supported
name|GPS_SYNTH
block|,
comment|///< (rw-) ::SYNTH, synthesizer settings, only if ::GPS_HAS_SYNTH
name|GPS_ANT_INFO
block|,
comment|///< (r-a) ::ANT_INFO, time diff after antenna disconnect, only if ::GPS_MODEL_HAS_ANT_INFO
name|GPS_UCAP
block|,
comment|///< (r-a) ::TTM, user capture events, only if ::RECEIVER_INFO::n_ucaps> 0
comment|/* GPS data */
name|GPS_CFGH
init|=
literal|0x100
block|,
comment|///< (rw-) ::CFGH, SVs' configuration and health codes
name|GPS_ALM
block|,
comment|///< (rw-) req: uint16_t SV num, ::SV_ALM, one SV's almanac
name|GPS_EPH
block|,
comment|///< (rw-) req: uint16_t SV num, ::SV_EPH, one SV's ephemeris
name|GPS_UTC
block|,
comment|///< (rw-) ::UTC, GPS %UTC correction parameters
name|GPS_IONO
block|,
comment|///< (rw-) ::IONO, GPS ionospheric correction parameters
name|GPS_ASCII_MSG
comment|///< (r--) ::ASCII_MSG, the GPS ASCII message
block|}
enum|;
end_enum

begin_ifndef
ifndef|#
directive|ifndef
name|_CSUM_DEFINED
end_ifndef

begin_typedef
typedef|typedef
name|uint16_t
name|CSUM
typedef|;
end_typedef

begin_comment
comment|/* checksum used by some structures stored in non-volatile memory */
end_comment

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
comment|/**  * @brief The header of a binary message.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|GPS_CMD
name|cmd
decl_stmt|;
comment|///< see ::GPS_CMD_CODES
name|uint16_t
name|len
decl_stmt|;
comment|///< length of the data portion appended after the header
name|CSUM
name|data_csum
decl_stmt|;
comment|///< checksum of the data portion appended after the header
name|CSUM
name|hdr_csum
decl_stmt|;
comment|///< checksum of the preceding header bytes
block|}
name|GPS_MSG_HDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GPS_ID_STR_LEN
value|16
end_define

begin_define
define|#
directive|define
name|GPS_ID_STR_SIZE
value|( GPS_ID_STR_LEN + 1 )
end_define

begin_comment
comment|/**  * @brief Software revision information  *  * Contains a software revision code, plus an optional  * identifier for a customized version.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|code
decl_stmt|;
comment|///< Version number, e.g. 0x0120 means v1.20
name|char
name|name
index|[
name|GPS_ID_STR_SIZE
index|]
decl_stmt|;
comment|///< Optional string identifying a customized version
name|uint8_t
name|reserved
decl_stmt|;
comment|///< Reserved field to yield even structure size
block|}
name|SW_REV
typedef|;
end_typedef

begin_comment
comment|/**  * @brief GNSS satellite numbers  *  * @todo: Check if MAX_SVNO_GLN is 94 instead of 95, and thus  *        N_SVNO_GLN is 30 instead of 31, as reported by Wikipedia.  */
end_comment

begin_enum
enum|enum
name|GNSS_SVNOS
block|{
name|MIN_SVNO_GPS
init|=
literal|1
block|,
comment|///< min. GPS satellite PRN number
name|MAX_SVNO_GPS
init|=
literal|32
block|,
comment|///< max. GPS satellite PRN number
name|N_SVNO_GPS
init|=
literal|32
block|,
comment|///< max. number of active GPS satellites
name|MIN_SVNO_WAAS
init|=
literal|33
block|,
comment|///< min. WAAS satellite number
name|MAX_SVNO_WAAS
init|=
literal|64
block|,
comment|///< max. WAAS satellite number
name|N_SVNO_WAAS
init|=
literal|32
block|,
comment|///< max. number of active WAAS satellites
name|MIN_SVNO_GLONASS
init|=
literal|65
block|,
comment|///< min. Glonass satellite number (64 + sat slot ID)
name|MAX_SVNO_GLONASS
init|=
literal|95
block|,
comment|///< max. Glonass satellite number (64 + sat slot ID)
name|N_SVNO_GLONASS
init|=
literal|31
comment|///< max. number of active Glonass satellites
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|uint16_t
name|SVNO
typedef|;
end_typedef

begin_comment
comment|///< the number of an SV (Space Vehicle, i.e. satellite)
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|HEALTH
typedef|;
end_typedef

begin_comment
comment|///< an SV's 6 bit health code
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|CFG
typedef|;
end_typedef

begin_comment
comment|///< an SV's 4 bit configuration code
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|IOD
typedef|;
end_typedef

begin_comment
comment|///< Issue-Of-Data code
end_comment

begin_comment
comment|/**  * @brief Status flags of battery buffered data  *  * Related to data received from the satellites, or data derived thereof.  *  * All '0' means OK, single bits set to '1' indicate  * the associated type of GPS data is not available.  *  * @see ::BVAR_FLAGS  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|BVAR_STAT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_mbg_swab_bvar_stat
parameter_list|(
name|_p
parameter_list|)
value|_mbg_swab16( (_p) )
end_define

begin_comment
comment|/**  * @brief Enumeration of flag bits used to define ::BVAR_FLAGS  *  * For each bit which is set this means the associated data set in  * non-volatile memory is not available, or incomplete.  * Most data sets will just be re-collected from the data streams sent  * by the satellites. However, the receiver position has usually been  * computed earlier during normal operation, and will be re-computed  * when a sufficient number of satellites can be received.  *  * @see ::BVAR_STAT  * @see ::BVAR_FLAGS  * @see ::BVAR_FLAG_NAMES  */
end_comment

begin_enum
enum|enum
name|BVAR_FLAG_BITS
block|{
name|BVAR_BIT_CFGH_INVALID
block|,
comment|///< Satellite configuration and health parameters incomplete
name|BVAR_BIT_ALM_NOT_COMPLETE
block|,
comment|///< Almanac parameters incomplete
name|BVAR_BIT_UTC_INVALID
block|,
comment|///< %UTC offset parameters incomplete
name|BVAR_BIT_IONO_INVALID
block|,
comment|///< Ionospheric correction parameters incomplete
name|BVAR_BIT_RCVR_POS_INVALID
block|,
comment|///< No valid receiver position available
name|N_BVAR_BIT
comment|///< number of defined ::BVAR_STAT bits
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief Bit masks associated with ::BVAR_FLAG_BITS  *  * Used with ::BVAR_STAT.  *  * @see ::BVAR_STAT  * @see ::BVAR_FLAG_BITS  * @see ::BVAR_FLAG_NAMES  */
end_comment

begin_enum
enum|enum
name|BVAR_FLAGS
block|{
name|BVAR_CFGH_INVALID
init|=
operator|(
literal|1UL
operator|<<
name|BVAR_BIT_CFGH_INVALID
operator|)
block|,
comment|///< see ::BVAR_BIT_CFGH_INVALID
name|BVAR_ALM_NOT_COMPLETE
init|=
operator|(
literal|1UL
operator|<<
name|BVAR_BIT_ALM_NOT_COMPLETE
operator|)
block|,
comment|///< see ::BVAR_BIT_ALM_NOT_COMPLETE
name|BVAR_UTC_INVALID
init|=
operator|(
literal|1UL
operator|<<
name|BVAR_BIT_UTC_INVALID
operator|)
block|,
comment|///< see ::BVAR_BIT_UTC_INVALID
name|BVAR_IONO_INVALID
init|=
operator|(
literal|1UL
operator|<<
name|BVAR_BIT_IONO_INVALID
operator|)
block|,
comment|///< see ::BVAR_BIT_IONO_INVALID
name|BVAR_RCVR_POS_INVALID
init|=
operator|(
literal|1UL
operator|<<
name|BVAR_BIT_RCVR_POS_INVALID
operator|)
block|,
comment|///< see ::BVAR_BIT_RCVR_POS_INVALID
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief A structure used to hold time in GPS format  *  * Date and time refer to the linear time scale defined by GPS, with  * the epoch starting at %UTC midnight at the beginning of January 6, 1980.  *  * GPS time is counted by the week numbers since the epoch, plus second  * of the week, plus fraction of the second. The week number transmitted  * by the satellites rolls over from 1023 to 0, but Meinberg devices  * just continue to count the weeks beyond the 1024 week limit to keep  * the receiver's internal time.  *  * %UTC time differs from GPS time since a number of leap seconds have  * been inserted in the %UTC time scale after the GPS epoche. The number  * of leap seconds is disseminated by the satellites using the ::UTC  * parameter set, which also provides info on pending leap seconds.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint16_t
name|wn
decl_stmt|;
comment|///< the week number since GPS has been installed
name|uint32_t
name|sec
decl_stmt|;
comment|///< the second of that week
name|uint32_t
name|tick
decl_stmt|;
comment|///< fractions of a second, 1/::RECEIVER_INFO::ticks_per_sec units
block|}
name|T_GPS
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Local date and time computed from GPS time  *  * The current number of leap seconds have to be added to get %UTC  * from GPS time. Additional corrections could have been made according  * to the time zone/daylight saving parameters ::TZDL defined by the user.  * The status field can be checked to see which corrections  * have actually been applied.  *  * @note Conversion from GPS time to %UTC and/or local time can only be  * done if some valid ::UTC correction parameters are available in the  * receiver's non-volatile memory.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int16_t
name|year
decl_stmt|;
comment|///< year number, 0..9999
name|int8_t
name|month
decl_stmt|;
comment|///< month, 1..12
name|int8_t
name|mday
decl_stmt|;
comment|///< day of month, 1..31
name|int16_t
name|yday
decl_stmt|;
comment|///< day of year, 1..365, or 366 in case of leap year
name|int8_t
name|wday
decl_stmt|;
comment|///< day of week, 0..6 == Sun..Sat
name|int8_t
name|hour
decl_stmt|;
comment|///< hours, 0..23
name|int8_t
name|min
decl_stmt|;
comment|///< minutes, 0..59
name|int8_t
name|sec
decl_stmt|;
comment|///< seconds, 0..59, or 60 in case of inserted leap second
name|int32_t
name|frac
decl_stmt|;
comment|///< fractions of a second, 1/::RECEIVER_INFO::ticks_per_sec units
name|int32_t
name|offs_from_utc
decl_stmt|;
comment|///< local time offset from %UTC [sec]
name|uint16_t
name|status
decl_stmt|;
comment|///< status flags, see ::TM_GPS_STATUS_BIT_MASKS
block|}
name|TM_GPS
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Status flag bits used to define ::TM_GPS_STATUS_BIT_MASKS  *  * These bits report info on the time conversion from GPS time to %UTC  * and/or local time as well as device status info.  *  * @see ::TM_GPS_STATUS_BIT_MASKS  */
end_comment

begin_enum
enum|enum
name|TM_GPS_STATUS_BITS
block|{
name|TM_BIT_UTC
block|,
comment|///< %UTC correction has been made
name|TM_BIT_LOCAL
block|,
comment|///< %UTC has been converted to local time according to ::TZDL settings
name|TM_BIT_DL_ANN
block|,
comment|///< state of daylight saving is going to change
name|TM_BIT_DL_ENB
block|,
comment|///< daylight saving is in effect
name|TM_BIT_LS_ANN
block|,
comment|///< leap second pending
name|TM_BIT_LS_ENB
block|,
comment|///< current second is leap second
name|TM_BIT_LS_ANN_NEG
block|,
comment|///< set in addition to ::TM_BIT_LS_ANN if leap sec is negative
name|TM_BIT_INVT
block|,
comment|///< invalid time, e.g. if RTC battery bas been empty
name|TM_BIT_EXT_SYNC
block|,
comment|///< synchronized externally
name|TM_BIT_HOLDOVER
block|,
comment|///< in holdover mode after previous synchronization
name|TM_BIT_ANT_SHORT
block|,
comment|///< antenna cable short circuited
name|TM_BIT_NO_WARM
block|,
comment|///< OCXO has not warmed up
name|TM_BIT_ANT_DISCONN
block|,
comment|///< antenna currently disconnected
name|TM_BIT_SYN_FLAG
block|,
comment|///< TIME_SYN output is low
name|TM_BIT_NO_SYNC
block|,
comment|///< time sync actually not verified
name|TM_BIT_NO_POS
comment|///< position actually not verified, LOCK LED off
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief Status flag masks used with ::TM_GPS::status  *  * These bits report info on the time conversion from GPS time to %UTC  * and/or local time as well as device status info.  *  * @see ::TM_GPS_STATUS_BITS  */
end_comment

begin_enum
enum|enum
name|TM_GPS_STATUS_BIT_MASKS
block|{
name|TM_UTC
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_UTC
operator|)
block|,
comment|///< see ::TM_BIT_UTC
name|TM_LOCAL
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_LOCAL
operator|)
block|,
comment|///< see ::TM_BIT_LOCAL
name|TM_DL_ANN
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_DL_ANN
operator|)
block|,
comment|///< see ::TM_BIT_DL_ANN
name|TM_DL_ENB
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_DL_ENB
operator|)
block|,
comment|///< see ::TM_BIT_DL_ENB
name|TM_LS_ANN
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_LS_ANN
operator|)
block|,
comment|///< see ::TM_BIT_LS_ANN
name|TM_LS_ENB
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_LS_ENB
operator|)
block|,
comment|///< see ::TM_BIT_LS_ENB
name|TM_LS_ANN_NEG
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_LS_ANN_NEG
operator|)
block|,
comment|///< see ::TM_BIT_LS_ANN_NEG
name|TM_INVT
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_INVT
operator|)
block|,
comment|///< see ::TM_BIT_INVT
name|TM_EXT_SYNC
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_EXT_SYNC
operator|)
block|,
comment|///< see ::TM_BIT_EXT_SYNC
name|TM_HOLDOVER
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_HOLDOVER
operator|)
block|,
comment|///< see ::TM_BIT_HOLDOVER
name|TM_ANT_SHORT
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_ANT_SHORT
operator|)
block|,
comment|///< see ::TM_BIT_ANT_SHORT
name|TM_NO_WARM
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_NO_WARM
operator|)
block|,
comment|///< see ::TM_BIT_NO_WARM
name|TM_ANT_DISCONN
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_ANT_DISCONN
operator|)
block|,
comment|///< see ::TM_BIT_ANT_DISCONN
name|TM_SYN_FLAG
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_SYN_FLAG
operator|)
block|,
comment|///< see ::TM_BIT_SYN_FLAG
name|TM_NO_SYNC
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_NO_SYNC
operator|)
block|,
comment|///< see ::TM_BIT_NO_SYNC
name|TM_NO_POS
init|=
operator|(
literal|1UL
operator|<<
name|TM_BIT_NO_POS
operator|)
comment|///< see ::TM_BIT_NO_POS
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief A structure used to transmit information on date and time  *  * This structure can be used to transfer the current time, in which  * case the channel field has to be set to -1, or an event capture time  * retrieved from the on-board FIFO, in which case the channel field  * contains the index of the time capture input, e.g. 0 or 1.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int16_t
name|channel
decl_stmt|;
comment|///< -1: the current on-board time;>= 0 the capture channel number
name|T_GPS
name|t
decl_stmt|;
comment|///< time in GPS scale and format
name|TM_GPS
name|tm
decl_stmt|;
comment|///< time converted to %UTC and/or local time according to ::TZDL settings
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

begin_comment
comment|/**  * @brief Sequence and number of components of a cartesian position  */
end_comment

begin_enum
enum|enum
name|XYZ_FIELDS
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
comment|// x, y, z
end_comment

begin_comment
comment|/**  * @brief A position in cartesian coordinates  *  * Usually earth centered, earth fixed (ECEF) coordinates,  * in [m].  *  * @note In the original code this is an array of double.  *  * @see ::XYZ_FIELDS  */
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
comment|/**  * @brief Sequence and number of components of a geographic position  */
end_comment

begin_enum
enum|enum
name|LLA_FIELDS
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
comment|/**  * @brief A geographic position based on latitude, longitude, and altitude  *  * The geographic position associated to specific cartesian coordinates  * depends on the characteristics of the ellipsoid used for the computation,  * the so-called geographic datum. GPS uses the WGS84 (World Geodetic System  * from 1984) ellipsoid by default.  *  * lon, lat in [rad], alt in [m]  *  * @note In the original code this is an array of double.  *  * @see ::LLA_FIELDS  */
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
comment|/**  * @defgroup group_synth Synthesizer parameters  *  * Synthesizer frequency is expressed as a  * four digit decimal number (freq) to be multiplied by 0.1 Hz and an  * base 10 exponent (range). If the effective frequency is less than  * 10 kHz its phase is synchronized corresponding to the variable phase.  * Phase may be in a range from -360 deg to +360 deg with a resolution  * of 0.1 deg, so the resulting numbers to be stored are in a range of  * -3600 to +3600.  *  * Example:<br>  * Assume the value of freq is 2345 (decimal) and the value of phase is 900.  * If range == 0 the effective frequency is 234.5 Hz with a phase of +90 deg.  * If range == 1 the synthesizer will generate a 2345 Hz output frequency  * and so on.  *  * Limitations:<br>  * If freq == 0 the synthesizer is disabled. If range == 0 the least  * significant digit of freq is limited to 0, 3, 5 or 6. The resulting  * frequency is shown in the examples below:  *    - freq == 1230  -->  123.0 Hz  *    - freq == 1233  -->  123 1/3 Hz (real 1/3 Hz, NOT 123.3 Hz)  *    - freq == 1235  -->  123.5 Hz  *    - freq == 1236  -->  123 2/3 Hz (real 2/3 Hz, NOT 123.6 Hz)  *  * If range == ::MAX_SYNTH_RANGE the value of freq must not exceed 1000, so  * the output frequency is limited to 10 MHz (see ::MAX_SYNTH_FREQ_VAL).  *  * @{ */
end_comment

begin_define
define|#
directive|define
name|N_SYNTH_FREQ_DIGIT
value|4
end_define

begin_comment
comment|///< number of digits to edit
end_comment

begin_define
define|#
directive|define
name|MAX_SYNTH_FREQ
value|1000
end_define

begin_comment
comment|///< if range == ::MAX_SYNTH_RANGE
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
name|N_SYNTH_RANGE
value|( MAX_SYNTH_RANGE - MIN_SYNTH_RANGE + 1 )
end_define

begin_define
define|#
directive|define
name|N_SYNTH_PHASE_DIGIT
value|4
end_define

begin_define
define|#
directive|define
name|MAX_SYNTH_PHASE
value|3600
end_define

begin_define
define|#
directive|define
name|MAX_SYNTH_FREQ_EDIT
value|9999
end_define

begin_comment
comment|///< max sequence of digits when editing
end_comment

begin_comment
comment|/**  * @brief The maximum frequency that can be configured for the synthesizer  */
end_comment

begin_define
define|#
directive|define
name|MAX_SYNTH_FREQ_VAL
value|10000000UL
end_define

begin_comment
comment|///< 10 MHz
end_comment

begin_comment
comment|/*   == MAX_SYNTH_FREQ * 10^(MAX_SYNTH_RANGE-1) */
end_comment

begin_comment
comment|/**  * @brief The synthesizer's phase is only be synchronized if the frequency is below this limit  */
end_comment

begin_define
define|#
directive|define
name|SYNTH_PHASE_SYNC_LIMIT
value|10000UL
end_define

begin_comment
comment|///< 10 kHz
end_comment

begin_comment
comment|/**  * A Macro used to determine the position of the decimal point  * when printing the synthesizer frequency as 4 digit value  */
end_comment

begin_define
define|#
directive|define
name|_synth_dp_pos_from_range
parameter_list|(
name|_r
parameter_list|)
define|\
value|( ( ( N_SYNTH_RANGE - (_r) ) % ( N_SYNTH_FREQ_DIGIT - 1 ) ) + 1 )
end_define

begin_comment
comment|/**  * @brief Synthesizer frequency units  *  * An initializer for commonly displayed synthesizer frequency units  * (::N_SYNTH_RANGE strings)  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FREQ_RANGES
define|\
value|{                           \   "Hz",                     \   "kHz",                    \   "kHz",                    \   "kHz",                    \   "MHz",                    \   "MHz",                    \ }
end_define

begin_comment
comment|/**  * @brief Synthesizer configuration parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int16_t
name|freq
decl_stmt|;
comment|///< four digits used; scale: 0.1 Hz; e.g. 1234 -> 123.4 Hz
name|int16_t
name|range
decl_stmt|;
comment|///< scale factor for freq; 0..::MAX_SYNTH_RANGE
name|int16_t
name|phase
decl_stmt|;
comment|///< -::MAX_SYNTH_PHASE..+::MAX_SYNTH_PHASE;>0 -> pulses later
block|}
name|SYNTH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_mbg_swab_synth
parameter_list|(
name|_p
parameter_list|)
define|\
value|{                               \   _mbg_swab16(&(_p)->freq );   \   _mbg_swab16(&(_p)->range );  \   _mbg_swab16(&(_p)->phase );  \ }
end_define

begin_comment
comment|/**  * @brief Enumeration of synthesizer states  */
end_comment

begin_enum
enum|enum
name|SYNTH_STATES
block|{
name|SYNTH_DISABLED
block|,
comment|///< disbled by cfg, i.e. freq == 0.0
name|SYNTH_OFF
block|,
comment|///< not enabled after power-up
name|SYNTH_FREE
block|,
comment|///< enabled, but not synchronized
name|SYNTH_DRIFTING
block|,
comment|///< has initially been sync'd, but now running free
name|SYNTH_SYNC
block|,
comment|///< fully synchronized
name|N_SYNTH_STATE
comment|///< the number of known states
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief A structure used to report the synthesizer state  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint8_t
name|state
decl_stmt|;
comment|///< state code as enumerated in ::SYNTH_STATES
name|uint8_t
name|flags
decl_stmt|;
comment|///< reserved, currently always 0
block|}
name|SYNTH_STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_mbg_swab_synth_state
parameter_list|(
name|_p
parameter_list|)
value|_nop_macro_fnc()
end_define

begin_define
define|#
directive|define
name|SYNTH_FLAG_PHASE_IGNORED
value|0x01
end_define

begin_comment
comment|/** @} defgroup group_synth */
end_comment

begin_comment
comment|/**  * @defgroup group_tzdl Time zone / daylight saving parameters  *  * Example:<br>  * For automatic daylight saving enable/disable in Central Europe,  * the variables are to be set as shown below:<br>  *   - offs = 3600L           one hour from %UTC  *   - offs_dl = 3600L        one additional hour if daylight saving enabled  *   - tm_on = first Sunday from March 25, 02:00:00h ( year |= ::DL_AUTO_FLAG )  *   - tm_off = first Sunday from October 25, 03:00:00h ( year |= ::DL_AUTO_FLAG )  *   - name[0] == "CET  "     name if daylight saving not enabled  *   - name[1] == "CEST "     name if daylight saving is enabled  *  * @{ */
end_comment

begin_comment
comment|/**  * @brief The name of a time zone  *  * @note Up to 5 printable characters, plus trailing zero  */
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

begin_comment
comment|/**  * @brief Time zone / daylight saving parameters  *  * This structure is used to specify how a device converts on-board %UTC  * to local time, including computation of beginning and end of daylight  * saving time (DST), if required.  *  * @note The ::TZDL structure contains members of type ::TM_GPS to specify  * the times for beginning and end of DST. However, the ::TM_GPS::frac,  * ::TM_GPS::offs_from_utc, and ::TM_GPS::status fields of these ::TZDL::tm_on  * and ::TZDL::tm_off members are ignored for the conversion to local time,  * and thus should be 0.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int32_t
name|offs
decl_stmt|;
comment|///< standard offset from %UTC to local time [sec]
name|int32_t
name|offs_dl
decl_stmt|;
comment|///< additional offset if daylight saving enabled [sec]
name|TM_GPS
name|tm_on
decl_stmt|;
comment|///< date/time when daylight saving starts
name|TM_GPS
name|tm_off
decl_stmt|;
comment|///< date/time when daylight saving ends
name|TZ_NAME
name|name
index|[
literal|2
index|]
decl_stmt|;
comment|///< names without and with daylight saving enabled
block|}
name|TZDL
typedef|;
end_typedef

begin_comment
comment|/**  * @brief A flag indicating automatic computation of DST  *  * If this flag is or'ed to the year numbers in ::TZDL::tm_on and ::TZDL::tm_off  * then daylight saving is computed automatically year by year.  */
end_comment

begin_define
define|#
directive|define
name|DL_AUTO_FLAG
value|0x8000
end_define

begin_comment
comment|/** @} defgroup group_tzdl */
end_comment

begin_comment
comment|/**  * @brief Antenna status and error at reconnect information  *  * The structure below reflects the status of the antenna,  * the times of last disconnect/reconnect, and the board's  * clock offset when it has synchronized again after the  * disconnection interval.  *  * @note ::ANT_INFO::status changes back to ::ANT_RECONN only  * after the antenna has been reconnected<b>and</b> the  * receiver has re-synchronized to the satellite signal.  * In this case ::ANT_INFO::delta_t reports the time offset  * before resynchronization, i.e. how much the internal  * time has drifted while the antenna was disconnected.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int16_t
name|status
decl_stmt|;
comment|///< current status of antenna, see ::ANT_STATUS_CODES
name|TM_GPS
name|tm_disconn
decl_stmt|;
comment|///< time of antenna disconnect
name|TM_GPS
name|tm_reconn
decl_stmt|;
comment|///< time of antenna reconnect
name|int32_t
name|delta_t
decl_stmt|;
comment|///< clock offs at reconn. time in 1/::RECEIVER_INFO::ticks_per_sec units
block|}
name|ANT_INFO
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Status code used with ::ANT_INFO::status  */
end_comment

begin_enum
enum|enum
name|ANT_STATUS_CODES
block|{
name|ANT_INVALID
block|,
comment|///< No other fields valid since antenna has not yet been disconnected
name|ANT_DISCONN
block|,
comment|///< Antenna is disconnected, tm_reconn and delta_t not yet set
name|ANT_RECONN
block|,
comment|///< Antenna has been disconnect, and receiver sync. after reconnect, so all fields valid
name|N_ANT_STATUS_CODES
comment|///< the number of known status codes
block|}
enum|;
end_enum

begin_comment
comment|/**  * @brief Summary of configuration and health data of all satellites  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///< checksum of the remaining bytes
name|int16_t
name|valid
decl_stmt|;
comment|///< flag data are valid
name|T_GPS
name|tot_51
decl_stmt|;
comment|///< time of transmission, page 51
name|T_GPS
name|tot_63
decl_stmt|;
comment|///< time of transmission, page 63
name|T_GPS
name|t0a
decl_stmt|;
comment|///< complete reference time almanac
name|CFG
name|cfg
index|[
name|N_SVNO_GPS
index|]
decl_stmt|;
comment|///< 4 bit SV configuration code from page 63
name|HEALTH
name|health
index|[
name|N_SVNO_GPS
index|]
decl_stmt|;
comment|///< 6 bit SV health codes from pages 51, 63
block|}
name|CFGH
typedef|;
end_typedef

begin_comment
comment|/**  * @brief GPS %UTC correction parameters  *  * %UTC correction parameters basically as sent by the GPS satellites.  *  * The csum field is only used by the card's firmware to check the  * consistency of the structure in non-volatile memory.  *  * The field labeled valid indicates if the parameter set is valid, i.e.  * if it contains data received from the satellites.  *  * t0t, A0 and A1 contain fractional correction parameters for the current  * GPS-%UTC time offset in addition to the whole seconds. This is evaluated  * by the receivers' firmware to convert GPS time to %UTC time.  *  * The delta_tls field contains the current full seconds offset between  * GPS time and %UTC, which corresponds to the number of leap seconds inserted  * into the %UTC time scale since GPS was put into operation in January 1980.  *  * delta_tlfs holds the number of "future" leap seconds, i.e. the %UTC offset  * after the next leap second event defined by WNlsf and DNt.  *  * The fields WNlsf and DNt specify the GPS week number and the day number  * in that week for the end of which a leap second has been scheduled.  *  * @note: The satellites transmit WNlsf only as a signed 8 bit value, so it  * can only define a point in time which is +/- 127 weeks off the current time.  * The firmware tries to expand this based on the current week number, but  * the result is ambiguous if the leap second occurs or occurred more  * than 127 weeks in the future or past.  *  * So the leap second date should<b>only</b> be evaluated and displayed  * in a user interface if the fields delta_tls and delta_tlsf have  * different values, in which case there is indeed a leap second announcement  * inside the +/- 127 week range.  *  * @note In the original code the type of A0 and A1 is double.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///<  Checksum of the remaining bytes
name|int16_t
name|valid
decl_stmt|;
comment|///<  Flag indicating %UTC parameters are valid
name|T_GPS
name|t0t
decl_stmt|;
comment|///<  Reference Time %UTC Parameters [wn|sec]
name|l_fp
name|A0
decl_stmt|;
comment|///<  +- Clock Correction Coefficient 0 [sec]
name|l_fp
name|A1
decl_stmt|;
comment|///<  +- Clock Correction Coefficient 1 [sec/sec]
name|uint16_t
name|WNlsf
decl_stmt|;
comment|///<  Week number of nearest leap second
name|int16_t
name|DNt
decl_stmt|;
comment|///<  The day number at the end of which a leap second occurs
name|int8_t
name|delta_tls
decl_stmt|;
comment|///<  Current %UTC offset to GPS system time [sec]
name|int8_t
name|delta_tlsf
decl_stmt|;
comment|///<  Future %UTC offset to GPS system time after next leap second transition [sec]
block|}
name|UTC
typedef|;
end_typedef

begin_comment
comment|/**  * @brief GPS ASCII message  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///< checksum of the remaining bytes */
name|int16_t
name|valid
decl_stmt|;
comment|///< flag data are valid
name|char
name|s
index|[
literal|23
index|]
decl_stmt|;
comment|///< 22 chars GPS ASCII message plus trailing zero
block|}
name|ASCII_MSG
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Ephemeris parameters of one specific satellite  *  * Needed to compute the position of a satellite at a given time with  * high precision. Valid for an interval of 4 to 6 hours from start  * of transmission.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///<    checksum of the remaining bytes
name|int16_t
name|valid
decl_stmt|;
comment|///<    flag data are valid
name|HEALTH
name|health
decl_stmt|;
comment|///<    health indication of transmitting SV      [---]
name|IOD
name|IODC
decl_stmt|;
comment|///<    Issue Of Data, Clock
name|IOD
name|IODE2
decl_stmt|;
comment|///<    Issue of Data, Ephemeris (Subframe 2)
name|IOD
name|IODE3
decl_stmt|;
comment|///<    Issue of Data, Ephemeris (Subframe 3)
name|T_GPS
name|tt
decl_stmt|;
comment|///<    time of transmission
name|T_GPS
name|t0c
decl_stmt|;
comment|///<    Reference Time Clock                      [---]
name|T_GPS
name|t0e
decl_stmt|;
comment|///<    Reference Time Ephemeris                  [---]
name|l_fp
name|sqrt_A
decl_stmt|;
comment|///<    Square Root of semi-major Axis        [sqrt(m)]
name|l_fp
name|e
decl_stmt|;
comment|///<    Eccentricity                              [---]
name|l_fp
name|M0
decl_stmt|;
comment|///< +- Mean Anomaly at Ref. Time                 [rad]
name|l_fp
name|omega
decl_stmt|;
comment|///< +- Argument of Perigee                       [rad]
name|l_fp
name|OMEGA0
decl_stmt|;
comment|///< +- Longit. of Asc. Node of orbit plane       [rad]
name|l_fp
name|OMEGADOT
decl_stmt|;
comment|///< +- Rate of Right Ascension               [rad/sec]
name|l_fp
name|deltan
decl_stmt|;
comment|///< +- Mean Motion Diff. from computed value [rad/sec]
name|l_fp
name|i0
decl_stmt|;
comment|///< +- Inclination Angle                         [rad]
name|l_fp
name|idot
decl_stmt|;
comment|///< +- Rate of Inclination Angle             [rad/sec]
name|l_fp
name|crc
decl_stmt|;
comment|///< +- Cosine Corr. Term to Orbit Radius           [m]
name|l_fp
name|crs
decl_stmt|;
comment|///< +- Sine Corr. Term to Orbit Radius             [m]
name|l_fp
name|cuc
decl_stmt|;
comment|///< +- Cosine Corr. Term to Arg. of Latitude     [rad]
name|l_fp
name|cus
decl_stmt|;
comment|///< +- Sine Corr. Term to Arg. of Latitude       [rad]
name|l_fp
name|cic
decl_stmt|;
comment|///< +- Cosine Corr. Term to Inclination Angle    [rad]
name|l_fp
name|cis
decl_stmt|;
comment|///< +- Sine Corr. Term to Inclination Angle      [rad]
name|l_fp
name|af0
decl_stmt|;
comment|///< +- Clock Correction Coefficient 0            [sec]
name|l_fp
name|af1
decl_stmt|;
comment|///< +- Clock Correction Coefficient 1        [sec/sec]
name|l_fp
name|af2
decl_stmt|;
comment|///< +- Clock Correction Coefficient 2      [sec/sec^2]
name|l_fp
name|tgd
decl_stmt|;
comment|///< +- estimated group delay differential        [sec]
name|uint16_t
name|URA
decl_stmt|;
comment|///<    predicted User Range Accuracy
name|uint8_t
name|L2code
decl_stmt|;
comment|///<    code on L2 channel                         [---]
name|uint8_t
name|L2flag
decl_stmt|;
comment|///<    L2 P data flag                             [---]
block|}
name|EPH
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Almanac parameters of one specific satellite  *  * A reduced precision set of parameters used to check if a satellite  * is in view at a given time. Valid for an interval of more than 7 days  * from start of transmission.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///<    checksum of the remaining bytes
name|int16_t
name|valid
decl_stmt|;
comment|///<    flag data are valid
name|HEALTH
name|health
decl_stmt|;
comment|///<                                               [---]
name|T_GPS
name|t0a
decl_stmt|;
comment|///<    Reference Time Almanac                     [sec]
name|l_fp
name|sqrt_A
decl_stmt|;
comment|///<    Square Root of semi-major Axis         [sqrt(m)]
name|l_fp
name|e
decl_stmt|;
comment|///<    Eccentricity                               [---]
name|l_fp
name|M0
decl_stmt|;
comment|///< +- Mean Anomaly at Ref. Time                  [rad]
name|l_fp
name|omega
decl_stmt|;
comment|///< +- Argument of Perigee                        [rad]
name|l_fp
name|OMEGA0
decl_stmt|;
comment|///< +- Longit. of Asc. Node of orbit plane        [rad]
name|l_fp
name|OMEGADOT
decl_stmt|;
comment|///< +- Rate of Right Ascension                [rad/sec]
name|l_fp
name|deltai
decl_stmt|;
comment|///< +-                                            [rad]
name|l_fp
name|af0
decl_stmt|;
comment|///< +- Clock Correction Coefficient 0             [sec]
name|l_fp
name|af1
decl_stmt|;
comment|///< +- Clock Correction Coefficient 1         [sec/sec]
block|}
name|ALM
typedef|;
end_typedef

begin_comment
comment|/**  * @brief Ionospheric correction parameters  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|CSUM
name|csum
decl_stmt|;
comment|///<    checksum of the remaining bytes
name|int16_t
name|valid
decl_stmt|;
comment|///<    flag data are valid
name|l_fp
name|alpha_0
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Alpha 0              [sec]
name|l_fp
name|alpha_1
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Alpha 1          [sec/deg]
name|l_fp
name|alpha_2
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Alpha 2        [sec/deg^2]
name|l_fp
name|alpha_3
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Alpha 3        [sec/deg^3]
name|l_fp
name|beta_0
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Beta 0               [sec]
name|l_fp
name|beta_1
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Beta 1           [sec/deg]
name|l_fp
name|beta_2
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Beta 2         [sec/deg^2]
name|l_fp
name|beta_3
decl_stmt|;
comment|///<    Ionosph. Corr. Coeff. Beta 3         [sec/deg^3]
block|}
name|IONO
typedef|;
end_typedef

begin_function_decl
name|void
name|mbg_tm_str
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|TM_GPS
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbg_tgps_str
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|T_GPS
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_header
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|GPS_MSG_HDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|put_mbg_header
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|GPS_MSG_HDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_sw_rev
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|SW_REV
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_ascii_msg
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|ASCII_MSG
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_svno
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|SVNO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_health
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|HEALTH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_cfg
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|CFG
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_tgps
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|T_GPS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_tm
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|TM_GPS
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_ttm
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|TTM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_synth
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|SYNTH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_tzdl
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|TZDL
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_antinfo
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|ANT_INFO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_cfgh
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|CFGH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_utc
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|UTC
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_lla
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|LLA
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_xyz
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|XYZ
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_portparam
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|PORT_PARM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_eph
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|EPH
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_alm
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|ALM
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_mbg_iono
parameter_list|(
name|unsigned
name|char
modifier|*
modifier|*
parameter_list|,
name|IONO
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|CSUM
name|mbg_csum
parameter_list|(
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * History:  *  * mbg_gps166.h,v  * Revision 4.7  2006/06/22 18:41:43  kardel  * clean up signedness (gcc 4)  *  * Revision 4.6  2005/10/07 22:11:56  kardel  * bounded buffer implementation  *  * Revision 4.5.2.1  2005/09/25 10:23:48  kardel  * support bounded buffers  *  * Revision 4.5  2005/06/25 10:58:45  kardel  * add missing log keywords  *  * Revision 4.1  1998/06/12 15:07:30  kardel  * fixed prototyping  *  * Revision 4.0  1998/04/10 19:50:42  kardel  * Start 4.0 release version numbering  *  * Revision 1.1  1998/04/10 19:27:34  kardel  * initial NTP VERSION 4 integration of PARSE with GPS166 binary support  *  * Revision 1.1  1997/10/06 20:55:38  kardel  * new parse structure  *  */
end_comment

end_unit

