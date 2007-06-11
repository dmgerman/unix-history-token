begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2007 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET80211_IEEE80211_SCAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET80211_IEEE80211_SCAN_H_
end_define

begin_define
define|#
directive|define
name|IEEE80211_SCAN_MAX
value|IEEE80211_CHAN_MAX
end_define

begin_struct_decl
struct_decl|struct
name|ieee80211_scanner
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|ieee80211_scan_ssid
block|{
name|int
name|len
decl_stmt|;
comment|/* length in bytes */
name|uint8_t
name|ssid
index|[
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
comment|/* ssid contents */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IEEE80211_SCAN_MAX_SSID
value|1
end_define

begin_struct
struct|struct
name|ieee80211_scan_state
block|{
name|struct
name|ieee80211com
modifier|*
name|ss_ic
decl_stmt|;
specifier|const
name|struct
name|ieee80211_scanner
modifier|*
name|ss_ops
decl_stmt|;
comment|/* policy hookup, see below */
name|void
modifier|*
name|ss_priv
decl_stmt|;
comment|/* scanner private state */
name|uint16_t
name|ss_flags
decl_stmt|;
define|#
directive|define
name|IEEE80211_SCAN_NOPICK
value|0x0001
comment|/* scan only, no selection */
define|#
directive|define
name|IEEE80211_SCAN_ACTIVE
value|0x0002
comment|/* active scan (probe req) */
define|#
directive|define
name|IEEE80211_SCAN_PICK1ST
value|0x0004
comment|/* ``hey sailor'' mode */
define|#
directive|define
name|IEEE80211_SCAN_BGSCAN
value|0x0008
comment|/* bg scan, exit ps at end */
define|#
directive|define
name|IEEE80211_SCAN_ONCE
value|0x0010
comment|/* do one complete pass */
define|#
directive|define
name|IEEE80211_SCAN_GOTPICK
value|0x1000
comment|/* got candidate, can stop */
name|uint8_t
name|ss_nssid
decl_stmt|;
comment|/* # ssid's to probe/match */
name|struct
name|ieee80211_scan_ssid
name|ss_ssid
index|[
name|IEEE80211_SCAN_MAX_SSID
index|]
decl_stmt|;
comment|/* ssid's to probe/match */
comment|/* ordered channel set */
name|struct
name|ieee80211_channel
modifier|*
name|ss_chans
index|[
name|IEEE80211_SCAN_MAX
index|]
decl_stmt|;
name|uint16_t
name|ss_next
decl_stmt|;
comment|/* ix of next chan to scan */
name|uint16_t
name|ss_last
decl_stmt|;
comment|/* ix+1 of last chan to scan */
name|unsigned
name|long
name|ss_mindwell
decl_stmt|;
comment|/* min dwell on channel */
name|unsigned
name|long
name|ss_maxdwell
decl_stmt|;
comment|/* max dwell on channel */
block|}
struct|;
end_struct

begin_comment
comment|/*  * The upper 16 bits of the flags word is used to communicate  * information to the scanning code that is NOT recorded in  * ss_flags.  It might be better to split this stuff out into  * a separate variable to avoid confusion.  */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SCAN_FLUSH
value|0x10000
end_define

begin_comment
comment|/* flush candidate table */
end_comment

begin_define
define|#
directive|define
name|IEEE80211_SCAN_NOSSID
value|0x20000
end_define

begin_comment
comment|/* don't update ssid list */
end_comment

begin_struct_decl
struct_decl|struct
name|ieee80211com
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_scan_attach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_detach
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_dump_channels
parameter_list|(
specifier|const
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_scan_update
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE80211_SCAN_FOREVER
value|0x7fffffff
end_define

begin_function_decl
name|int
name|ieee80211_start_scan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|,
name|u_int
name|duration
parameter_list|,
name|u_int
name|nssid
parameter_list|,
specifier|const
name|struct
name|ieee80211_scan_ssid
name|ssids
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_check_scan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|,
name|u_int
name|duration
parameter_list|,
name|u_int
name|nssid
parameter_list|,
specifier|const
name|struct
name|ieee80211_scan_ssid
name|ssids
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ieee80211_bg_scan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_cancel_scan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_next
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_scanparams
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ieee80211_add_scan
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanparams
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
name|int
name|subtype
parameter_list|,
name|int
name|rssi
parameter_list|,
name|int
name|noise
parameter_list|,
name|int
name|rstamp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_timeout
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_assoc_success
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|IEEE80211_SCAN_FAIL_TIMEOUT
init|=
literal|1
block|,
comment|/* no response to mgmt frame */
name|IEEE80211_SCAN_FAIL_STATUS
init|=
literal|2
comment|/* negative response to " " */
block|}
enum|;
end_enum

begin_function_decl
name|void
name|ieee80211_scan_assoc_fail
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|mac
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scan_flush
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ieee80211_scan_entry
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|ieee80211_scan_iter_func
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scan_entry
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|ieee80211_scan_iterate
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|ieee80211_scan_iter_func
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Parameters supplied when adding/updating an entry in a  * scan cache.  Pointer variables should be set to NULL  * if no data is available.  Pointer references can be to  * local data; any information that is saved will be copied.  * All multi-byte values must be in host byte order.  */
end_comment

begin_struct
struct|struct
name|ieee80211_scanparams
block|{
name|uint16_t
name|capinfo
decl_stmt|;
comment|/* 802.11 capabilities */
name|uint16_t
name|fhdwell
decl_stmt|;
comment|/* FHSS dwell interval */
name|uint8_t
name|chan
decl_stmt|;
comment|/* */
name|uint8_t
name|bchan
decl_stmt|;
name|uint8_t
name|fhindex
decl_stmt|;
name|uint8_t
name|erp
decl_stmt|;
name|uint16_t
name|bintval
decl_stmt|;
name|uint8_t
name|timoff
decl_stmt|;
name|uint8_t
modifier|*
name|tim
decl_stmt|;
name|uint8_t
modifier|*
name|tstamp
decl_stmt|;
name|uint8_t
modifier|*
name|country
decl_stmt|;
name|uint8_t
modifier|*
name|ssid
decl_stmt|;
name|uint8_t
modifier|*
name|rates
decl_stmt|;
name|uint8_t
modifier|*
name|xrates
decl_stmt|;
name|uint8_t
modifier|*
name|doth
decl_stmt|;
name|uint8_t
modifier|*
name|wpa
decl_stmt|;
name|uint8_t
modifier|*
name|rsn
decl_stmt|;
name|uint8_t
modifier|*
name|wme
decl_stmt|;
name|uint8_t
modifier|*
name|htcap
decl_stmt|;
name|uint8_t
modifier|*
name|htinfo
decl_stmt|;
name|uint8_t
modifier|*
name|ath
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Scan cache entry format used when exporting data from a policy  * module; this data may be represented some other way internally.  */
end_comment

begin_struct
struct|struct
name|ieee80211_scan_entry
block|{
name|uint8_t
name|se_macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|se_bssid
index|[
name|IEEE80211_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|se_ssid
index|[
literal|2
operator|+
name|IEEE80211_NWID_LEN
index|]
decl_stmt|;
name|uint8_t
name|se_rates
index|[
literal|2
operator|+
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|uint8_t
name|se_xrates
index|[
literal|2
operator|+
name|IEEE80211_RATE_MAXSIZE
index|]
decl_stmt|;
name|uint32_t
name|se_rstamp
decl_stmt|;
comment|/* recv timestamp */
union|union
block|{
name|uint8_t
name|data
index|[
literal|8
index|]
decl_stmt|;
name|uint64_t
name|tsf
decl_stmt|;
block|}
name|se_tstamp
union|;
comment|/* from last rcv'd beacon */
name|uint16_t
name|se_intval
decl_stmt|;
comment|/* beacon interval (host byte order) */
name|uint16_t
name|se_capinfo
decl_stmt|;
comment|/* capabilities (host byte order) */
name|struct
name|ieee80211_channel
modifier|*
name|se_chan
decl_stmt|;
comment|/* channel where sta found */
name|uint16_t
name|se_timoff
decl_stmt|;
comment|/* byte offset to TIM ie */
name|uint16_t
name|se_fhdwell
decl_stmt|;
comment|/* FH only (host byte order) */
name|uint8_t
name|se_fhindex
decl_stmt|;
comment|/* FH only */
name|uint8_t
name|se_erp
decl_stmt|;
comment|/* ERP from beacon/probe resp */
name|int8_t
name|se_rssi
decl_stmt|;
comment|/* avg'd recv ssi */
name|int8_t
name|se_noise
decl_stmt|;
comment|/* noise floor */
name|uint8_t
name|se_dtimperiod
decl_stmt|;
comment|/* DTIM period */
name|uint8_t
modifier|*
name|se_wpa_ie
decl_stmt|;
comment|/* captured WPA ie */
name|uint8_t
modifier|*
name|se_rsn_ie
decl_stmt|;
comment|/* captured RSN ie */
name|uint8_t
modifier|*
name|se_wme_ie
decl_stmt|;
comment|/* captured WME ie */
name|uint8_t
modifier|*
name|se_htcap_ie
decl_stmt|;
comment|/* captured HTP cap ie */
name|uint8_t
modifier|*
name|se_htinfo_ie
decl_stmt|;
comment|/* captured HTP info ie */
name|uint8_t
modifier|*
name|se_ath_ie
decl_stmt|;
comment|/* captured Atheros ie */
name|u_int
name|se_age
decl_stmt|;
comment|/* age of entry (0 on create) */
block|}
struct|;
end_struct

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_80211_SCAN
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Template for an in-kernel scan policy module.  * Modules register with the scanning code and are  * typically loaded as needed.  */
end_comment

begin_struct
struct|struct
name|ieee80211_scanner
block|{
specifier|const
name|char
modifier|*
name|scan_name
decl_stmt|;
comment|/* printable name */
name|int
function_decl|(
modifier|*
name|scan_attach
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_detach
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_start
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_restart
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_cancel
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_end
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|scan_flush
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
comment|/* add an entry to the cache */
name|int
function_decl|(
modifier|*
name|scan_add
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanparams
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_frame
modifier|*
parameter_list|,
name|int
name|subtype
parameter_list|,
name|int
name|rssi
parameter_list|,
name|int
name|noise
parameter_list|,
name|int
name|rstamp
parameter_list|)
function_decl|;
comment|/* age and/or purge entries in the cache */
name|void
function_decl|(
modifier|*
name|scan_age
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|)
function_decl|;
comment|/* note that association failed for an entry */
name|void
function_decl|(
modifier|*
name|scan_assoc_fail
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|,
name|int
name|reason
parameter_list|)
function_decl|;
comment|/* note that association succeed for an entry */
name|void
function_decl|(
modifier|*
name|scan_assoc_success
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
specifier|const
name|uint8_t
name|macaddr
index|[
name|IEEE80211_ADDR_LEN
index|]
parameter_list|)
function_decl|;
comment|/* iterate over entries in the scan cache */
name|void
function_decl|(
modifier|*
name|scan_iterate
function_decl|)
parameter_list|(
name|struct
name|ieee80211_scan_state
modifier|*
parameter_list|,
name|ieee80211_scan_iter_func
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|ieee80211_scanner_register
parameter_list|(
name|enum
name|ieee80211_opmode
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanner
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scanner_unregister
parameter_list|(
name|enum
name|ieee80211_opmode
parameter_list|,
specifier|const
name|struct
name|ieee80211_scanner
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ieee80211_scanner_unregister_all
parameter_list|(
specifier|const
name|struct
name|ieee80211_scanner
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ieee80211_scanner
modifier|*
name|ieee80211_scanner_get
parameter_list|(
name|enum
name|ieee80211_opmode
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NET80211_IEEE80211_SCAN_H_ */
end_comment

end_unit

