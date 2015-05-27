begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_leapsec.h - leap second processing for NTPD  *  * Written by Juergen Perlinger (perlinger@ntp.org) for the NTP project.  * The contents of 'html/copyright.html' apply.  * ----------------------------------------------------------------------  * This is an attempt to get the leap second handling into a dedicated  * module to make the somewhat convoluted logic testable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_LEAPSEC_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_LEAPSEC_H
end_define

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_comment
comment|/* function pointer types. Note that 'fprintf' and 'getc' can be casted  * to the dumper resp. reader type, provided the auxiliary argument is a  * valid FILE pointer in hat case.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|leapsec_dumper
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|leapsec_reader
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|leap_table
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|leap_table
name|leap_table_t
typedef|;
end_typedef

begin_comment
comment|/* Validate a stream containing a leap second file in the NIST / NTPD  * format that can also be loaded via 'leapsec_load()'. This uses  * the SHA1 hash and preprocessing as described in the NIST leapsecond  * file.  */
end_comment

begin_define
define|#
directive|define
name|LSVALID_GOODHASH
value|1
end_define

begin_comment
comment|/* valid signature         */
end_comment

begin_define
define|#
directive|define
name|LSVALID_NOHASH
value|0
end_define

begin_comment
comment|/* no signature in file    */
end_comment

begin_define
define|#
directive|define
name|LSVALID_BADHASH
value|-1
end_define

begin_comment
comment|/* signature mismatch      */
end_comment

begin_define
define|#
directive|define
name|LSVALID_BADFORMAT
value|-2
end_define

begin_comment
comment|/* signature not parseable */
end_comment

begin_function_decl
specifier|extern
name|int
name|leapsec_validate
parameter_list|(
name|leapsec_reader
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set/get electric mode  * Electric mode is defined as the operation mode where the system clock  * automagically manages the leap second, so we don't have to care about  * stepping the clock. (This should be the case with most systems,  * including the current implementation of the Win32 timekeeping.)  *  * The consequence of electric mode is that we do not 'see' the leap  * second, and no client actions are needed when crossing the leap era  * boundary.  In manual (aka non-electric) mode the clock will simply  * step forward untill *we* (that is, this module) tells the client app  * to step at the right time. This needs a slightly different type of  * processing, so switching between those two modes should not be done  * too close to a leap second. The transition might be lost in that  * case. (The limit is actual 2 sec before transition.)  *  * OTOH, this is a system characteristic, so it's expected to be set  * properly somewhere after system start and retain the value.  *  * Simply querying the state or setting it to the same value as before  * does not have any unwanted side effects.  You can query by giving a  * negative value for the switch.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_electric
parameter_list|(
name|int
comment|/*BOOL*/
name|on
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Query result for a leap second schedule  * 'ttime' is the transition point in full time scale, but only if  *	'tai_diff' is not zero. Nominal UTC time when the next leap  *      era starts.  * 'ddist' is the distance to the transition, in clock seconds.  *      This is the distance to the due time, which is different  *      from the transition time if the mode is non-electric.  *	Only valid if 'tai_diff' is not zero.  * 'tai_offs' is the CURRENT distance from clock (UTC) to TAI. Always valid.  * 'tai_diff' is the change in TAI offset after the next leap  *	transition. Zero if nothing is pending or too far ahead.  * 'warped' is set only once, when the the leap second occurred between  *	two queries. Always zero in electric mode. If non-zero,  *      immediately step the clock.  * 'proximity' is a proximity warning. See definitions below. This is  *	more useful than an absolute difference to the leap second.  * 'dynamic' != 0 if entry was requested by clock/peer  */
end_comment

begin_struct
struct|struct
name|leap_result
block|{
name|vint64
name|ttime
decl_stmt|;
name|uint32_t
name|ddist
decl_stmt|;
name|int16_t
name|tai_offs
decl_stmt|;
name|int16_t
name|tai_diff
decl_stmt|;
name|int16_t
name|warped
decl_stmt|;
name|uint8_t
name|proximity
decl_stmt|;
name|uint8_t
name|dynamic
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|leap_result
name|leap_result_t
typedef|;
end_typedef

begin_struct
struct|struct
name|leap_signature
block|{
name|uint32_t
name|etime
decl_stmt|;
comment|/* expiration time	*/
name|uint32_t
name|ttime
decl_stmt|;
comment|/* transition time	*/
name|int16_t
name|taiof
decl_stmt|;
comment|/* total offset to TAI	*/
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|leap_signature
name|leap_signature_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LSPROX_NOWARN
value|0
end_define

begin_comment
comment|/* clear radar screen         */
end_comment

begin_define
define|#
directive|define
name|LSPROX_SCHEDULE
value|1
end_define

begin_comment
comment|/* less than 1 month to target*/
end_comment

begin_define
define|#
directive|define
name|LSPROX_ANNOUNCE
value|2
end_define

begin_comment
comment|/* less than 1 day to target  */
end_comment

begin_define
define|#
directive|define
name|LSPROX_ALERT
value|3
end_define

begin_comment
comment|/* less than 10 sec to target */
end_comment

begin_comment
comment|/* Get the current or alternate table pointer. Getting the alternate  * pointer will automatically copy the primary table, so it can be  * subsequently modified.  */
end_comment

begin_function_decl
specifier|extern
name|leap_table_t
modifier|*
name|leapsec_get_table
parameter_list|(
name|int
name|alternate
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the current leap table. Accepts only return values from  * 'leapsec_get_table()', so it's hard to do something wrong. Returns  * TRUE if the current table is the requested one.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_set_table
parameter_list|(
name|leap_table_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Clear all leap second data. Use it for init& cleanup */
end_comment

begin_function_decl
specifier|extern
name|void
name|leapsec_clear
parameter_list|(
name|leap_table_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load a leap second file. If 'blimit' is set, do not store (but  * register with their TAI offset) leap entries before the build date.  * Update the leap signature data on the fly.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_load
parameter_list|(
name|leap_table_t
modifier|*
parameter_list|,
name|leapsec_reader
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
name|blimit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Dump the current leap table in readable format, using the provided  * dump formatter function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|leapsec_dump
parameter_list|(
specifier|const
name|leap_table_t
modifier|*
parameter_list|,
name|leapsec_dumper
name|func
parameter_list|,
name|void
modifier|*
name|farg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a leap second file from stream. This is a convenience wrapper  * around the generic load function, 'leapsec_load()'.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_load_stream
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|int
comment|/*BOOL*/
name|logall
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read a leap second file from file. It checks that the file exists and  * (if 'force' is not applied) the ctime/mtime has changed since the  * last load. If the file has to be loaded, either due to 'force' or  * changed time stamps, the 'stat()' results of the file are stored in  * '*sb' for the next cycle. Returns TRUE on successful load, FALSE  * otherwise. Uses 'leapsec_load_stream()' internally.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_load_file
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|,
name|struct
name|stat
modifier|*
name|sb
parameter_list|,
name|int
comment|/*BOOL*/
name|force
parameter_list|,
name|int
comment|/*BOOL*/
name|logall
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the current leap data signature. This consists of the last  * ransition, the table expiration, and the total TAI difference at the  * last transition. This is valid even if the leap transition itself was  * culled due to the build date limit.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|leapsec_getsig
parameter_list|(
name|leap_signature_t
modifier|*
name|psig
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check if the leap table is expired at the given time.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_expired
parameter_list|(
name|uint32_t
name|when
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the distance to expiration in days.  * Returns negative values if expired, zero if there are less than 24hrs  * left, and positive numbers otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|int32_t
name|leapsec_daystolive
parameter_list|(
name|uint32_t
name|when
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Reset the current leap frame, so the next query will do proper table  * lookup from fresh. Suppresses a possible leap era transition detection  * for the next query.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|leapsec_reset_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a transition time, the TAI offset valid after that and an  * expiration time, try to establish a system leap transition. Only  * works if the existing table is extended. On success, updates the  * signature data.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_add_fix
parameter_list|(
name|int
name|offset
parameter_list|,
name|uint32_t
name|ttime
parameter_list|,
name|uint32_t
name|etime
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Take a time stamp and create a leap second frame for it. This will  * schedule a leap second for the beginning of the next month, midnight  * UTC. The 'insert' argument tells if a leap second is added (!=0) or  * removed (==0). We do not handle multiple inserts (yet?)  *  * Returns 1 if the insert worked, 0 otherwise. (It's not possible to  * insert a leap second into the current history -- only appending  * towards the future is allowed!)  *  * 'ntp_now' is subject to era unfolding. The entry is marked  * dynamic. The leap signature is NOT updated.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_add_dyn
parameter_list|(
name|int
comment|/*BOOL*/
name|insert
parameter_list|,
name|uint32_t
name|ntp_now
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Take a time stamp and get the associated leap information. The time  * stamp is subject to era unfolding around the pivot or the current  * system time if pivot is NULL. Sets the information in '*qr' and  * returns TRUE if a leap second era boundary was crossed between the  * last and the current query. In that case, qr->warped contains the  * required clock stepping, which is always zero in electric mode.  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_query
parameter_list|(
name|leap_result_t
modifier|*
name|qr
parameter_list|,
name|uint32_t
name|ntpts
parameter_list|,
specifier|const
name|time_t
modifier|*
name|pivot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the current leap frame info. Returns TRUE if the result contains  * useable data, FALSE if there is currently no leap second frame.  * This merely replicates some results from a previous query, but since  * it does not check the current time, only the following entries are  * meaningful:  *  qr->ttime;  *  qr->tai_offs;  *  qr->tai_diff;  *  qr->dynamic;  */
end_comment

begin_function_decl
specifier|extern
name|int
comment|/*BOOL*/
name|leapsec_frame
parameter_list|(
name|leap_result_t
modifier|*
name|qr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(NTP_LEAPSEC_H) */
end_comment

end_unit

