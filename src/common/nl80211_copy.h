begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__LINUX_NL80211_H
end_ifndef

begin_define
define|#
directive|define
name|__LINUX_NL80211_H
end_define

begin_comment
comment|/*  * 802.11 netlink interface public header  *  * Copyright 2006, 2007, 2008 Johannes Berg<johannes@sipsolutions.net>  * Copyright 2008 Michael Wu<flamingice@sourmilk.net>  * Copyright 2008 Luis Carlos Cobo<luisca@cozybit.com>  * Copyright 2008 Michael Buesch<mb@bu3sch.de>  * Copyright 2008, 2009 Luis R. Rodriguez<lrodriguez@atheros.com>  * Copyright 2008 Jouni Malinen<jouni.malinen@atheros.com>  * Copyright 2008 Colin McCabe<colin@cozybit.com>  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  */
end_comment

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/**  * DOC: Station handling  *  * Stations are added per interface, but a special case exists with VLAN  * interfaces. When a station is bound to an AP interface, it may be moved  * into a VLAN identified by a VLAN interface index (%NL80211_ATTR_STA_VLAN).  * The station is still assumed to belong to the AP interface it was added  * to.  *  * TODO: need more info?  */
end_comment

begin_comment
comment|/**  * enum nl80211_commands - supported nl80211 commands  *  * @NL80211_CMD_UNSPEC: unspecified command to catch errors  *  * @NL80211_CMD_GET_WIPHY: request information about a wiphy or dump request  *	to get a list of all present wiphys.  * @NL80211_CMD_SET_WIPHY: set wiphy parameters, needs %NL80211_ATTR_WIPHY or  *	%NL80211_ATTR_IFINDEX; can be used to set %NL80211_ATTR_WIPHY_NAME,  *	%NL80211_ATTR_WIPHY_TXQ_PARAMS, %NL80211_ATTR_WIPHY_FREQ,  *	%NL80211_ATTR_WIPHY_CHANNEL_TYPE, %NL80211_ATTR_WIPHY_RETRY_SHORT,  *	%NL80211_ATTR_WIPHY_RETRY_LONG, %NL80211_ATTR_WIPHY_FRAG_THRESHOLD,  *	and/or %NL80211_ATTR_WIPHY_RTS_THRESHOLD.  * @NL80211_CMD_NEW_WIPHY: Newly created wiphy, response to get request  *	or rename notification. Has attributes %NL80211_ATTR_WIPHY and  *	%NL80211_ATTR_WIPHY_NAME.  * @NL80211_CMD_DEL_WIPHY: Wiphy deleted. Has attributes  *	%NL80211_ATTR_WIPHY and %NL80211_ATTR_WIPHY_NAME.  *  * @NL80211_CMD_GET_INTERFACE: Request an interface's configuration;  *	either a dump request on a %NL80211_ATTR_WIPHY or a specific get  *	on an %NL80211_ATTR_IFINDEX is supported.  * @NL80211_CMD_SET_INTERFACE: Set type of a virtual interface, requires  *	%NL80211_ATTR_IFINDEX and %NL80211_ATTR_IFTYPE.  * @NL80211_CMD_NEW_INTERFACE: Newly created virtual interface or response  *	to %NL80211_CMD_GET_INTERFACE. Has %NL80211_ATTR_IFINDEX,  *	%NL80211_ATTR_WIPHY and %NL80211_ATTR_IFTYPE attributes. Can also  *	be sent from userspace to request creation of a new virtual interface,  *	then requires attributes %NL80211_ATTR_WIPHY, %NL80211_ATTR_IFTYPE and  *	%NL80211_ATTR_IFNAME.  * @NL80211_CMD_DEL_INTERFACE: Virtual interface was deleted, has attributes  *	%NL80211_ATTR_IFINDEX and %NL80211_ATTR_WIPHY. Can also be sent from  *	userspace to request deletion of a virtual interface, then requires  *	attribute %NL80211_ATTR_IFINDEX.  *  * @NL80211_CMD_GET_KEY: Get sequence counter information for a key specified  *	by %NL80211_ATTR_KEY_IDX and/or %NL80211_ATTR_MAC.  * @NL80211_CMD_SET_KEY: Set key attributes %NL80211_ATTR_KEY_DEFAULT,  *	%NL80211_ATTR_KEY_DEFAULT_MGMT, or %NL80211_ATTR_KEY_THRESHOLD.  * @NL80211_CMD_NEW_KEY: add a key with given %NL80211_ATTR_KEY_DATA,  *	%NL80211_ATTR_KEY_IDX, %NL80211_ATTR_MAC, %NL80211_ATTR_KEY_CIPHER,  *	and %NL80211_ATTR_KEY_SEQ attributes.  * @NL80211_CMD_DEL_KEY: delete a key identified by %NL80211_ATTR_KEY_IDX  *	or %NL80211_ATTR_MAC.  *  * @NL80211_CMD_GET_BEACON: retrieve beacon information (returned in a  *	%NL80222_CMD_NEW_BEACON message)  * @NL80211_CMD_SET_BEACON: set the beacon on an access point interface  *	using the %NL80211_ATTR_BEACON_INTERVAL, %NL80211_ATTR_DTIM_PERIOD,  *	%NL80211_ATTR_BEACON_HEAD and %NL80211_ATTR_BEACON_TAIL attributes.  * @NL80211_CMD_NEW_BEACON: add a new beacon to an access point interface,  *	parameters are like for %NL80211_CMD_SET_BEACON.  * @NL80211_CMD_DEL_BEACON: remove the beacon, stop sending it  *  * @NL80211_CMD_GET_STATION: Get station attributes for station identified by  *	%NL80211_ATTR_MAC on the interface identified by %NL80211_ATTR_IFINDEX.  * @NL80211_CMD_SET_STATION: Set station attributes for station identified by  *	%NL80211_ATTR_MAC on the interface identified by %NL80211_ATTR_IFINDEX.  * @NL80211_CMD_NEW_STATION: Add a station with given attributes to the  *	the interface identified by %NL80211_ATTR_IFINDEX.  * @NL80211_CMD_DEL_STATION: Remove a station identified by %NL80211_ATTR_MAC  *	or, if no MAC address given, all stations, on the interface identified  *	by %NL80211_ATTR_IFINDEX.  *  * @NL80211_CMD_GET_MPATH: Get mesh path attributes for mesh path to  * 	destination %NL80211_ATTR_MAC on the interface identified by  * 	%NL80211_ATTR_IFINDEX.  * @NL80211_CMD_SET_MPATH:  Set mesh path attributes for mesh path to  * 	destination %NL80211_ATTR_MAC on the interface identified by  * 	%NL80211_ATTR_IFINDEX.  * @NL80211_CMD_NEW_PATH: Add a mesh path with given attributes to the  *	the interface identified by %NL80211_ATTR_IFINDEX.  * @NL80211_CMD_DEL_PATH: Remove a mesh path identified by %NL80211_ATTR_MAC  *	or, if no MAC address given, all mesh paths, on the interface identified  *	by %NL80211_ATTR_IFINDEX.  * @NL80211_CMD_SET_BSS: Set BSS attributes for BSS identified by  *	%NL80211_ATTR_IFINDEX.  *  * @NL80211_CMD_GET_REG: ask the wireless core to send us its currently set  * 	regulatory domain.  * @NL80211_CMD_SET_REG: Set current regulatory domain. CRDA sends this command  *	after being queried by the kernel. CRDA replies by sending a regulatory  *	domain structure which consists of %NL80211_ATTR_REG_ALPHA set to our  *	current alpha2 if it found a match. It also provides  * 	NL80211_ATTR_REG_RULE_FLAGS, and a set of regulatory rules. Each  * 	regulatory rule is a nested set of attributes  given by  * 	%NL80211_ATTR_REG_RULE_FREQ_[START|END] and  * 	%NL80211_ATTR_FREQ_RANGE_MAX_BW with an attached power rule given by  * 	%NL80211_ATTR_REG_RULE_POWER_MAX_ANT_GAIN and  * 	%NL80211_ATTR_REG_RULE_POWER_MAX_EIRP.  * @NL80211_CMD_REQ_SET_REG: ask the wireless core to set the regulatory domain  * 	to the the specified ISO/IEC 3166-1 alpha2 country code. The core will  * 	store this as a valid request and then query userspace for it.  *  * @NL80211_CMD_GET_MESH_PARAMS: Get mesh networking properties for the  *	interface identified by %NL80211_ATTR_IFINDEX  *  * @NL80211_CMD_SET_MESH_PARAMS: Set mesh networking properties for the  *      interface identified by %NL80211_ATTR_IFINDEX  *  * @NL80211_CMD_SET_MGMT_EXTRA_IE: Set extra IEs for management frames. The  *	interface is identified with %NL80211_ATTR_IFINDEX and the management  *	frame subtype with %NL80211_ATTR_MGMT_SUBTYPE. The extra IE data to be  *	added to the end of the specified management frame is specified with  *	%NL80211_ATTR_IE. If the command succeeds, the requested data will be  *	added to all specified management frames generated by  *	kernel/firmware/driver.  *	Note: This command has been removed and it is only reserved at this  *	point to avoid re-using existing command number. The functionality this  *	command was planned for has been provided with cleaner design with the  *	option to specify additional IEs in NL80211_CMD_TRIGGER_SCAN,  *	NL80211_CMD_AUTHENTICATE, NL80211_CMD_ASSOCIATE,  *	NL80211_CMD_DEAUTHENTICATE, and NL80211_CMD_DISASSOCIATE.  *  * @NL80211_CMD_GET_SCAN: get scan results  * @NL80211_CMD_TRIGGER_SCAN: trigger a new scan with the given parameters  * @NL80211_CMD_NEW_SCAN_RESULTS: scan notification (as a reply to  *	NL80211_CMD_GET_SCAN and on the "scan" multicast group)  * @NL80211_CMD_SCAN_ABORTED: scan was aborted, for unspecified reasons,  *	partial scan results may be available  *  * @NL80211_CMD_GET_SURVEY: get survey resuls, e.g. channel occupation  *      or noise level  * @NL80211_CMD_NEW_SURVEY_RESULTS: survey data notification (as a reply to  *	NL80211_CMD_GET_SURVEY and on the "scan" multicast group)  *  * @NL80211_CMD_REG_CHANGE: indicates to userspace the regulatory domain  * 	has been changed and provides details of the request information  * 	that caused the change such as who initiated the regulatory request  * 	(%NL80211_ATTR_REG_INITIATOR), the wiphy_idx  * 	(%NL80211_ATTR_REG_ALPHA2) on which the request was made from if  * 	the initiator was %NL80211_REGDOM_SET_BY_COUNTRY_IE or  * 	%NL80211_REGDOM_SET_BY_DRIVER, the type of regulatory domain  * 	set (%NL80211_ATTR_REG_TYPE), if the type of regulatory domain is  * 	%NL80211_REG_TYPE_COUNTRY the alpha2 to which we have moved on  * 	to (%NL80211_ATTR_REG_ALPHA2).  * @NL80211_CMD_REG_BEACON_HINT: indicates to userspace that an AP beacon  * 	has been found while world roaming thus enabling active scan or  * 	any mode of operation that initiates TX (beacons) on a channel  * 	where we would not have been able to do either before. As an example  * 	if you are world roaming (regulatory domain set to world or if your  * 	driver is using a custom world roaming regulatory domain) and while  * 	doing a passive scan on the 5 GHz band you find an AP there (if not  * 	on a DFS channel) you will now be able to actively scan for that AP  * 	or use AP mode on your card on that same channel. Note that this will  * 	never be used for channels 1-11 on the 2 GHz band as they are always  * 	enabled world wide. This beacon hint is only sent if your device had  * 	either disabled active scanning or beaconing on a channel. We send to  * 	userspace the wiphy on which we removed a restriction from  * 	(%NL80211_ATTR_WIPHY) and the channel on which this occurred  * 	before (%NL80211_ATTR_FREQ_BEFORE) and after (%NL80211_ATTR_FREQ_AFTER)  * 	the beacon hint was processed.  *  * @NL80211_CMD_AUTHENTICATE: authentication request and notification.  *	This command is used both as a command (request to authenticate) and  *	as an event on the "mlme" multicast group indicating completion of the  *	authentication process.  *	When used as a command, %NL80211_ATTR_IFINDEX is used to identify the  *	interface. %NL80211_ATTR_MAC is used to specify PeerSTAAddress (and  *	BSSID in case of station mode). %NL80211_ATTR_SSID is used to specify  *	the SSID (mainly for association, but is included in authentication  *	request, too, to help BSS selection. %NL80211_ATTR_WIPHY_FREQ is used  *	to specify the frequence of the channel in MHz. %NL80211_ATTR_AUTH_TYPE  *	is used to specify the authentication type. %NL80211_ATTR_IE is used to  *	define IEs (VendorSpecificInfo, but also including RSN IE and FT IEs)  *	to be added to the frame.  *	When used as an event, this reports reception of an Authentication  *	frame in station and IBSS modes when the local MLME processed the  *	frame, i.e., it was for the local STA and was received in correct  *	state. This is similar to MLME-AUTHENTICATE.confirm primitive in the  *	MLME SAP interface (kernel providing MLME, userspace SME). The  *	included %NL80211_ATTR_FRAME attribute contains the management frame  *	(including both the header and frame body, but not FCS). This event is  *	also used to indicate if the authentication attempt timed out. In that  *	case the %NL80211_ATTR_FRAME attribute is replaced with a  *	%NL80211_ATTR_TIMED_OUT flag (and %NL80211_ATTR_MAC to indicate which  *	pending authentication timed out).  * @NL80211_CMD_ASSOCIATE: association request and notification; like  *	NL80211_CMD_AUTHENTICATE but for Association and Reassociation  *	(similar to MLME-ASSOCIATE.request, MLME-REASSOCIATE.request,  *	MLME-ASSOCIATE.confirm or MLME-REASSOCIATE.confirm primitives).  * @NL80211_CMD_DEAUTHENTICATE: deauthentication request and notification; like  *	NL80211_CMD_AUTHENTICATE but for Deauthentication frames (similar to  *	MLME-DEAUTHENTICATION.request and MLME-DEAUTHENTICATE.indication  *	primitives).  * @NL80211_CMD_DISASSOCIATE: disassociation request and notification; like  *	NL80211_CMD_AUTHENTICATE but for Disassociation frames (similar to  *	MLME-DISASSOCIATE.request and MLME-DISASSOCIATE.indication primitives).  *  * @NL80211_CMD_MICHAEL_MIC_FAILURE: notification of a locally detected Michael  *	MIC (part of TKIP) failure; sent on the "mlme" multicast group; the  *	event includes %NL80211_ATTR_MAC to describe the source MAC address of  *	the frame with invalid MIC, %NL80211_ATTR_KEY_TYPE to show the key  *	type, %NL80211_ATTR_KEY_IDX to indicate the key identifier, and  *	%NL80211_ATTR_KEY_SEQ to indicate the TSC value of the frame; this  *	event matches with MLME-MICHAELMICFAILURE.indication() primitive  *  * @NL80211_CMD_JOIN_IBSS: Join a new IBSS -- given at least an SSID and a  *	FREQ attribute (for the initial frequency if no peer can be found)  *	and optionally a MAC (as BSSID) and FREQ_FIXED attribute if those  *	should be fixed rather than automatically determined. Can only be  *	executed on a network interface that is UP, and fixed BSSID/FREQ  *	may be rejected. Another optional parameter is the beacon interval,  *	given in the %NL80211_ATTR_BEACON_INTERVAL attribute, which if not  *	given defaults to 100 TU (102.4ms).  * @NL80211_CMD_LEAVE_IBSS: Leave the IBSS -- no special arguments, the IBSS is  *	determined by the network interface.  *  * @NL80211_CMD_TESTMODE: testmode command, takes a wiphy (or ifindex) attribute  *	to identify the device, and the TESTDATA blob attribute to pass through  *	to the driver.  *  * @NL80211_CMD_CONNECT: connection request and notification; this command  *	requests to connect to a specified network but without separating  *	auth and assoc steps. For this, you need to specify the SSID in a  *	%NL80211_ATTR_SSID attribute, and can optionally specify the association  *	IEs in %NL80211_ATTR_IE, %NL80211_ATTR_AUTH_TYPE, %NL80211_ATTR_MAC,  *	%NL80211_ATTR_WIPHY_FREQ and %NL80211_ATTR_CONTROL_PORT.  *	It is also sent as an event, with the BSSID and response IEs when the  *	connection is established or failed to be established. This can be  *	determined by the STATUS_CODE attribute.  * @NL80211_CMD_ROAM: request that the card roam (currently not implemented),  *	sent as an event when the card/driver roamed by itself.  * @NL80211_CMD_DISCONNECT: drop a given connection; also used to notify  *	userspace that a connection was dropped by the AP or due to other  *	reasons, for this the %NL80211_ATTR_DISCONNECTED_BY_AP and  *	%NL80211_ATTR_REASON_CODE attributes are used.  *  * @NL80211_CMD_SET_WIPHY_NETNS: Set a wiphy's netns. Note that all devices  *	associated with this wiphy must be down and will follow.  *  * @NL80211_CMD_MAX: highest used command number  * @__NL80211_CMD_AFTER_LAST: internal use  */
end_comment

begin_enum
enum|enum
name|nl80211_commands
block|{
comment|/* don't change the order or add anything inbetween, this is ABI! */
name|NL80211_CMD_UNSPEC
block|,
name|NL80211_CMD_GET_WIPHY
block|,
comment|/* can dump */
name|NL80211_CMD_SET_WIPHY
block|,
name|NL80211_CMD_NEW_WIPHY
block|,
name|NL80211_CMD_DEL_WIPHY
block|,
name|NL80211_CMD_GET_INTERFACE
block|,
comment|/* can dump */
name|NL80211_CMD_SET_INTERFACE
block|,
name|NL80211_CMD_NEW_INTERFACE
block|,
name|NL80211_CMD_DEL_INTERFACE
block|,
name|NL80211_CMD_GET_KEY
block|,
name|NL80211_CMD_SET_KEY
block|,
name|NL80211_CMD_NEW_KEY
block|,
name|NL80211_CMD_DEL_KEY
block|,
name|NL80211_CMD_GET_BEACON
block|,
name|NL80211_CMD_SET_BEACON
block|,
name|NL80211_CMD_NEW_BEACON
block|,
name|NL80211_CMD_DEL_BEACON
block|,
name|NL80211_CMD_GET_STATION
block|,
name|NL80211_CMD_SET_STATION
block|,
name|NL80211_CMD_NEW_STATION
block|,
name|NL80211_CMD_DEL_STATION
block|,
name|NL80211_CMD_GET_MPATH
block|,
name|NL80211_CMD_SET_MPATH
block|,
name|NL80211_CMD_NEW_MPATH
block|,
name|NL80211_CMD_DEL_MPATH
block|,
name|NL80211_CMD_SET_BSS
block|,
name|NL80211_CMD_SET_REG
block|,
name|NL80211_CMD_REQ_SET_REG
block|,
name|NL80211_CMD_GET_MESH_PARAMS
block|,
name|NL80211_CMD_SET_MESH_PARAMS
block|,
name|NL80211_CMD_SET_MGMT_EXTRA_IE
comment|/* reserved; not used */
block|,
name|NL80211_CMD_GET_REG
block|,
name|NL80211_CMD_GET_SCAN
block|,
name|NL80211_CMD_TRIGGER_SCAN
block|,
name|NL80211_CMD_NEW_SCAN_RESULTS
block|,
name|NL80211_CMD_SCAN_ABORTED
block|,
name|NL80211_CMD_REG_CHANGE
block|,
name|NL80211_CMD_AUTHENTICATE
block|,
name|NL80211_CMD_ASSOCIATE
block|,
name|NL80211_CMD_DEAUTHENTICATE
block|,
name|NL80211_CMD_DISASSOCIATE
block|,
name|NL80211_CMD_MICHAEL_MIC_FAILURE
block|,
name|NL80211_CMD_REG_BEACON_HINT
block|,
name|NL80211_CMD_JOIN_IBSS
block|,
name|NL80211_CMD_LEAVE_IBSS
block|,
name|NL80211_CMD_TESTMODE
block|,
name|NL80211_CMD_CONNECT
block|,
name|NL80211_CMD_ROAM
block|,
name|NL80211_CMD_DISCONNECT
block|,
name|NL80211_CMD_SET_WIPHY_NETNS
block|,
name|NL80211_CMD_GET_SURVEY
block|,
name|NL80211_CMD_NEW_SURVEY_RESULTS
block|,
comment|/* add new commands above here */
comment|/* used to define NL80211_CMD_MAX below */
name|__NL80211_CMD_AFTER_LAST
block|,
name|NL80211_CMD_MAX
init|=
name|__NL80211_CMD_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/*  * Allow user space programs to use #ifdef on new commands by defining them  * here  */
end_comment

begin_define
define|#
directive|define
name|NL80211_CMD_SET_BSS
value|NL80211_CMD_SET_BSS
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_SET_MGMT_EXTRA_IE
value|NL80211_CMD_SET_MGMT_EXTRA_IE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_REG_CHANGE
value|NL80211_CMD_REG_CHANGE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_AUTHENTICATE
value|NL80211_CMD_AUTHENTICATE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_ASSOCIATE
value|NL80211_CMD_ASSOCIATE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_DEAUTHENTICATE
value|NL80211_CMD_DEAUTHENTICATE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_DISASSOCIATE
value|NL80211_CMD_DISASSOCIATE
end_define

begin_define
define|#
directive|define
name|NL80211_CMD_REG_BEACON_HINT
value|NL80211_CMD_REG_BEACON_HINT
end_define

begin_comment
comment|/**  * enum nl80211_attrs - nl80211 netlink attributes  *  * @NL80211_ATTR_UNSPEC: unspecified attribute to catch errors  *  * @NL80211_ATTR_WIPHY: index of wiphy to operate on, cf.  *	/sys/class/ieee80211/<phyname>/index  * @NL80211_ATTR_WIPHY_NAME: wiphy name (used for renaming)  * @NL80211_ATTR_WIPHY_TXQ_PARAMS: a nested array of TX queue parameters  * @NL80211_ATTR_WIPHY_FREQ: frequency of the selected channel in MHz  * @NL80211_ATTR_WIPHY_CHANNEL_TYPE: included with NL80211_ATTR_WIPHY_FREQ  *	if HT20 or HT40 are allowed (i.e., 802.11n disabled if not included):  *	NL80211_CHAN_NO_HT = HT not allowed (i.e., same as not including  *		this attribute)  *	NL80211_CHAN_HT20 = HT20 only  *	NL80211_CHAN_HT40MINUS = secondary channel is below the primary channel  *	NL80211_CHAN_HT40PLUS = secondary channel is above the primary channel  * @NL80211_ATTR_WIPHY_RETRY_SHORT: TX retry limit for frames whose length is  *	less than or equal to the RTS threshold; allowed range: 1..255;  *	dot11ShortRetryLimit; u8  * @NL80211_ATTR_WIPHY_RETRY_LONG: TX retry limit for frames whose length is  *	greater than the RTS threshold; allowed range: 1..255;  *	dot11ShortLongLimit; u8  * @NL80211_ATTR_WIPHY_FRAG_THRESHOLD: fragmentation threshold, i.e., maximum  *	length in octets for frames; allowed range: 256..8000, disable  *	fragmentation with (u32)-1; dot11FragmentationThreshold; u32  * @NL80211_ATTR_WIPHY_RTS_THRESHOLD: RTS threshold (TX frames with length  *	larger than or equal to this use RTS/CTS handshake); allowed range:  *	0..65536, disable with (u32)-1; dot11RTSThreshold; u32  *  * @NL80211_ATTR_IFINDEX: network interface index of the device to operate on  * @NL80211_ATTR_IFNAME: network interface name  * @NL80211_ATTR_IFTYPE: type of virtual interface, see&enum nl80211_iftype  *  * @NL80211_ATTR_MAC: MAC address (various uses)  *  * @NL80211_ATTR_KEY_DATA: (temporal) key data; for TKIP this consists of  *	16 bytes encryption key followed by 8 bytes each for TX and RX MIC  *	keys  * @NL80211_ATTR_KEY_IDX: key ID (u8, 0-3)  * @NL80211_ATTR_KEY_CIPHER: key cipher suite (u32, as defined by IEEE 802.11  *	section 7.3.2.25.1, e.g. 0x000FAC04)  * @NL80211_ATTR_KEY_SEQ: transmit key sequence number (IV/PN) for TKIP and  *	CCMP keys, each six bytes in little endian  *  * @NL80211_ATTR_BEACON_INTERVAL: beacon interval in TU  * @NL80211_ATTR_DTIM_PERIOD: DTIM period for beaconing  * @NL80211_ATTR_BEACON_HEAD: portion of the beacon before the TIM IE  * @NL80211_ATTR_BEACON_TAIL: portion of the beacon after the TIM IE  *  * @NL80211_ATTR_STA_AID: Association ID for the station (u16)  * @NL80211_ATTR_STA_FLAGS: flags, nested element with NLA_FLAG attributes of  *&enum nl80211_sta_flags (deprecated, use %NL80211_ATTR_STA_FLAGS2)  * @NL80211_ATTR_STA_LISTEN_INTERVAL: listen interval as defined by  *	IEEE 802.11 7.3.1.6 (u16).  * @NL80211_ATTR_STA_SUPPORTED_RATES: supported rates, array of supported  *	rates as defined by IEEE 802.11 7.3.2.2 but without the length  *	restriction (at most %NL80211_MAX_SUPP_RATES).  * @NL80211_ATTR_STA_VLAN: interface index of VLAN interface to move station  *	to, or the AP interface the station was originally added to to.  * @NL80211_ATTR_STA_INFO: information about a station, part of station info  *	given for %NL80211_CMD_GET_STATION, nested attribute containing  *	info as possible, see&enum nl80211_sta_info.  *  * @NL80211_ATTR_WIPHY_BANDS: Information about an operating bands,  *	consisting of a nested array.  *  * @NL80211_ATTR_MESH_ID: mesh id (1-32 bytes).  * @NL80211_ATTR_PLINK_ACTION: action to perform on the mesh peer link.  * @NL80211_ATTR_MPATH_NEXT_HOP: MAC address of the next hop for a mesh path.  * @NL80211_ATTR_MPATH_INFO: information about a mesh_path, part of mesh path  * 	info given for %NL80211_CMD_GET_MPATH, nested attribute described at  *&enum nl80211_mpath_info.  *  * @NL80211_ATTR_MNTR_FLAGS: flags, nested element with NLA_FLAG attributes of  *&enum nl80211_mntr_flags.  *  * @NL80211_ATTR_REG_ALPHA2: an ISO-3166-alpha2 country code for which the  * 	current regulatory domain should be set to or is already set to.  * 	For example, 'CR', for Costa Rica. This attribute is used by the kernel  * 	to query the CRDA to retrieve one regulatory domain. This attribute can  * 	also be used by userspace to query the kernel for the currently set  * 	regulatory domain. We chose an alpha2 as that is also used by the  * 	IEEE-802.11d country information element to identify a country.  * 	Users can also simply ask the wireless core to set regulatory domain  * 	to a specific alpha2.  * @NL80211_ATTR_REG_RULES: a nested array of regulatory domain regulatory  *	rules.  *  * @NL80211_ATTR_BSS_CTS_PROT: whether CTS protection is enabled (u8, 0 or 1)  * @NL80211_ATTR_BSS_SHORT_PREAMBLE: whether short preamble is enabled  *	(u8, 0 or 1)  * @NL80211_ATTR_BSS_SHORT_SLOT_TIME: whether short slot time enabled  *	(u8, 0 or 1)  * @NL80211_ATTR_BSS_BASIC_RATES: basic rates, array of basic  *	rates in format defined by IEEE 802.11 7.3.2.2 but without the length  *	restriction (at most %NL80211_MAX_SUPP_RATES).  *  * @NL80211_ATTR_HT_CAPABILITY: HT Capability information element (from  *	association request when used with NL80211_CMD_NEW_STATION)  *  * @NL80211_ATTR_SUPPORTED_IFTYPES: nested attribute containing all  *	supported interface types, each a flag attribute with the number  *	of the interface mode.  *  * @NL80211_ATTR_MGMT_SUBTYPE: Management frame subtype for  *	%NL80211_CMD_SET_MGMT_EXTRA_IE.  *  * @NL80211_ATTR_IE: Information element(s) data (used, e.g., with  *	%NL80211_CMD_SET_MGMT_EXTRA_IE).  *  * @NL80211_ATTR_MAX_NUM_SCAN_SSIDS: number of SSIDs you can scan with  *	a single scan request, a wiphy attribute.  * @NL80211_ATTR_MAX_SCAN_IE_LEN: maximum length of information elements  *	that can be added to a scan request  *  * @NL80211_ATTR_SCAN_FREQUENCIES: nested attribute with frequencies (in MHz)  * @NL80211_ATTR_SCAN_SSIDS: nested attribute with SSIDs, leave out for passive  *	scanning and include a zero-length SSID (wildcard) for wildcard scan  * @NL80211_ATTR_BSS: scan result BSS  *  * @NL80211_ATTR_REG_INITIATOR: indicates who requested the regulatory domain  * 	currently in effect. This could be any of the %NL80211_REGDOM_SET_BY_*  * @NL80211_ATTR_REG_TYPE: indicates the type of the regulatory domain currently  * 	set. This can be one of the nl80211_reg_type (%NL80211_REGDOM_TYPE_*)  *  * @NL80211_ATTR_SUPPORTED_COMMANDS: wiphy attribute that specifies  *	an array of command numbers (i.e. a mapping index to command number)  *	that the driver for the given wiphy supports.  *  * @NL80211_ATTR_FRAME: frame data (binary attribute), including frame header  *	and body, but not FCS; used, e.g., with NL80211_CMD_AUTHENTICATE and  *	NL80211_CMD_ASSOCIATE events  * @NL80211_ATTR_SSID: SSID (binary attribute, 0..32 octets)  * @NL80211_ATTR_AUTH_TYPE: AuthenticationType, see&enum nl80211_auth_type,  *	represented as a u32  * @NL80211_ATTR_REASON_CODE: ReasonCode for %NL80211_CMD_DEAUTHENTICATE and  *	%NL80211_CMD_DISASSOCIATE, u16  *  * @NL80211_ATTR_KEY_TYPE: Key Type, see&enum nl80211_key_type, represented as  *	a u32  *  * @NL80211_ATTR_FREQ_BEFORE: A channel which has suffered a regulatory change  * 	due to considerations from a beacon hint. This attribute reflects  * 	the state of the channel _before_ the beacon hint processing. This  * 	attributes consists of a nested attribute containing  * 	NL80211_FREQUENCY_ATTR_*  * @NL80211_ATTR_FREQ_AFTER: A channel which has suffered a regulatory change  * 	due to considerations from a beacon hint. This attribute reflects  * 	the state of the channel _after_ the beacon hint processing. This  * 	attributes consists of a nested attribute containing  * 	NL80211_FREQUENCY_ATTR_*  *  * @NL80211_ATTR_CIPHER_SUITES: a set of u32 values indicating the supported  *	cipher suites  *  * @NL80211_ATTR_FREQ_FIXED: a flag indicating the IBSS should not try to look  *	for other networks on different channels  *  * @NL80211_ATTR_TIMED_OUT: a flag indicating than an operation timed out; this  *	is used, e.g., with %NL80211_CMD_AUTHENTICATE event  *  * @NL80211_ATTR_USE_MFP: Whether management frame protection (IEEE 802.11w) is  *	used for the association (&enum nl80211_mfp, represented as a u32);  *	this attribute can be used  *	with %NL80211_CMD_ASSOCIATE request  *  * @NL80211_ATTR_STA_FLAGS2: Attribute containing a  *&struct nl80211_sta_flag_update.  *  * @NL80211_ATTR_CONTROL_PORT: A flag indicating whether user space controls  *	IEEE 802.1X port, i.e., sets/clears %NL80211_STA_FLAG_AUTHORIZED, in  *	station mode. If the flag is included in %NL80211_CMD_ASSOCIATE  *	request, the driver will assume that the port is unauthorized until  *	authorized by user space. Otherwise, port is marked authorized by  *	default in station mode.  *  * @NL80211_ATTR_TESTDATA: Testmode data blob, passed through to the driver.  *	We recommend using nested, driver-specific attributes within this.  *  * @NL80211_ATTR_DISCONNECTED_BY_AP: A flag indicating that the DISCONNECT  *	event was due to the AP disconnecting the station, and not due to  *	a local disconnect request.  * @NL80211_ATTR_STATUS_CODE: StatusCode for the %NL80211_CMD_CONNECT  *	event (u16)  * @NL80211_ATTR_PRIVACY: Flag attribute, used with connect(), indicating  *	that protected APs should be used.  *  * @NL80211_ATTR_CIPHERS_PAIRWISE: Used with CONNECT and ASSOCIATE to  *	indicate which unicast key ciphers will be used with the connection  *	(an array of u32).  * @NL80211_ATTR_CIPHER_GROUP: Used with CONNECT and ASSOCIATE to indicate  *	which group key cipher will be used with the connection (a u32).  * @NL80211_ATTR_WPA_VERSIONS: Used with CONNECT and ASSOCIATE to indicate  *	which WPA version(s) the AP we want to associate with is using  *	(a u32 with flags from&enum nl80211_wpa_versions).  * @NL80211_ATTR_AKM_SUITES: Used with CONNECT and ASSOCIATE to indicate  *	which key management algorithm(s) to use (an array of u32).  *  * @NL80211_ATTR_REQ_IE: (Re)association request information elements as  *	sent out by the card, for ROAM and successful CONNECT events.  * @NL80211_ATTR_RESP_IE: (Re)association response information elements as  *	sent by peer, for ROAM and successful CONNECT events.  *  * @NL80211_ATTR_PREV_BSSID: previous BSSID, to be used by in ASSOCIATE  *	commands to specify using a reassociate frame  *  * @NL80211_ATTR_KEY: key information in a nested attribute with  *	%NL80211_KEY_* sub-attributes  * @NL80211_ATTR_KEYS: array of keys for static WEP keys for connect()  *	and join_ibss(), key information is in a nested attribute each  *	with %NL80211_KEY_* sub-attributes  *  * @NL80211_ATTR_PID: Process ID of a network namespace.  *  * @NL80211_ATTR_GENERATION: Used to indicate consistent snapshots for  *	dumps. This number increases whenever the object list being  *	dumped changes, and as such userspace can verify that it has  *	obtained a complete and consistent snapshot by verifying that  *	all dump messages contain the same generation number. If it  *	changed then the list changed and the dump should be repeated  *	completely from scratch.  *  * @NL80211_ATTR_4ADDR: Use 4-address frames on a virtual interface  *  * @NL80211_ATTR_SURVEY_INFO: survey information about a channel, part of  *      the survey response for %NL80211_CMD_GET_SURVEY, nested attribute  *      containing info as possible, see&enum survey_info.  *  * @NL80211_ATTR_MAX: highest attribute number currently defined  * @__NL80211_ATTR_AFTER_LAST: internal use  */
end_comment

begin_enum
enum|enum
name|nl80211_attrs
block|{
comment|/* don't change the order or add anything inbetween, this is ABI! */
name|NL80211_ATTR_UNSPEC
block|,
name|NL80211_ATTR_WIPHY
block|,
name|NL80211_ATTR_WIPHY_NAME
block|,
name|NL80211_ATTR_IFINDEX
block|,
name|NL80211_ATTR_IFNAME
block|,
name|NL80211_ATTR_IFTYPE
block|,
name|NL80211_ATTR_MAC
block|,
name|NL80211_ATTR_KEY_DATA
block|,
name|NL80211_ATTR_KEY_IDX
block|,
name|NL80211_ATTR_KEY_CIPHER
block|,
name|NL80211_ATTR_KEY_SEQ
block|,
name|NL80211_ATTR_KEY_DEFAULT
block|,
name|NL80211_ATTR_BEACON_INTERVAL
block|,
name|NL80211_ATTR_DTIM_PERIOD
block|,
name|NL80211_ATTR_BEACON_HEAD
block|,
name|NL80211_ATTR_BEACON_TAIL
block|,
name|NL80211_ATTR_STA_AID
block|,
name|NL80211_ATTR_STA_FLAGS
block|,
name|NL80211_ATTR_STA_LISTEN_INTERVAL
block|,
name|NL80211_ATTR_STA_SUPPORTED_RATES
block|,
name|NL80211_ATTR_STA_VLAN
block|,
name|NL80211_ATTR_STA_INFO
block|,
name|NL80211_ATTR_WIPHY_BANDS
block|,
name|NL80211_ATTR_MNTR_FLAGS
block|,
name|NL80211_ATTR_MESH_ID
block|,
name|NL80211_ATTR_STA_PLINK_ACTION
block|,
name|NL80211_ATTR_MPATH_NEXT_HOP
block|,
name|NL80211_ATTR_MPATH_INFO
block|,
name|NL80211_ATTR_BSS_CTS_PROT
block|,
name|NL80211_ATTR_BSS_SHORT_PREAMBLE
block|,
name|NL80211_ATTR_BSS_SHORT_SLOT_TIME
block|,
name|NL80211_ATTR_HT_CAPABILITY
block|,
name|NL80211_ATTR_SUPPORTED_IFTYPES
block|,
name|NL80211_ATTR_REG_ALPHA2
block|,
name|NL80211_ATTR_REG_RULES
block|,
name|NL80211_ATTR_MESH_PARAMS
block|,
name|NL80211_ATTR_BSS_BASIC_RATES
block|,
name|NL80211_ATTR_WIPHY_TXQ_PARAMS
block|,
name|NL80211_ATTR_WIPHY_FREQ
block|,
name|NL80211_ATTR_WIPHY_CHANNEL_TYPE
block|,
name|NL80211_ATTR_KEY_DEFAULT_MGMT
block|,
name|NL80211_ATTR_MGMT_SUBTYPE
block|,
name|NL80211_ATTR_IE
block|,
name|NL80211_ATTR_MAX_NUM_SCAN_SSIDS
block|,
name|NL80211_ATTR_SCAN_FREQUENCIES
block|,
name|NL80211_ATTR_SCAN_SSIDS
block|,
name|NL80211_ATTR_GENERATION
block|,
comment|/* replaces old SCAN_GENERATION */
name|NL80211_ATTR_BSS
block|,
name|NL80211_ATTR_REG_INITIATOR
block|,
name|NL80211_ATTR_REG_TYPE
block|,
name|NL80211_ATTR_SUPPORTED_COMMANDS
block|,
name|NL80211_ATTR_FRAME
block|,
name|NL80211_ATTR_SSID
block|,
name|NL80211_ATTR_AUTH_TYPE
block|,
name|NL80211_ATTR_REASON_CODE
block|,
name|NL80211_ATTR_KEY_TYPE
block|,
name|NL80211_ATTR_MAX_SCAN_IE_LEN
block|,
name|NL80211_ATTR_CIPHER_SUITES
block|,
name|NL80211_ATTR_FREQ_BEFORE
block|,
name|NL80211_ATTR_FREQ_AFTER
block|,
name|NL80211_ATTR_FREQ_FIXED
block|,
name|NL80211_ATTR_WIPHY_RETRY_SHORT
block|,
name|NL80211_ATTR_WIPHY_RETRY_LONG
block|,
name|NL80211_ATTR_WIPHY_FRAG_THRESHOLD
block|,
name|NL80211_ATTR_WIPHY_RTS_THRESHOLD
block|,
name|NL80211_ATTR_TIMED_OUT
block|,
name|NL80211_ATTR_USE_MFP
block|,
name|NL80211_ATTR_STA_FLAGS2
block|,
name|NL80211_ATTR_CONTROL_PORT
block|,
name|NL80211_ATTR_TESTDATA
block|,
name|NL80211_ATTR_PRIVACY
block|,
name|NL80211_ATTR_DISCONNECTED_BY_AP
block|,
name|NL80211_ATTR_STATUS_CODE
block|,
name|NL80211_ATTR_CIPHER_SUITES_PAIRWISE
block|,
name|NL80211_ATTR_CIPHER_SUITE_GROUP
block|,
name|NL80211_ATTR_WPA_VERSIONS
block|,
name|NL80211_ATTR_AKM_SUITES
block|,
name|NL80211_ATTR_REQ_IE
block|,
name|NL80211_ATTR_RESP_IE
block|,
name|NL80211_ATTR_PREV_BSSID
block|,
name|NL80211_ATTR_KEY
block|,
name|NL80211_ATTR_KEYS
block|,
name|NL80211_ATTR_PID
block|,
name|NL80211_ATTR_4ADDR
block|,
name|NL80211_ATTR_SURVEY_INFO
block|,
comment|/* add attributes here, update the policy in nl80211.c */
name|__NL80211_ATTR_AFTER_LAST
block|,
name|NL80211_ATTR_MAX
init|=
name|__NL80211_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/* source-level API compatibility */
end_comment

begin_define
define|#
directive|define
name|NL80211_ATTR_SCAN_GENERATION
value|NL80211_ATTR_GENERATION
end_define

begin_comment
comment|/*  * Allow user space programs to use #ifdef on new attributes by defining them  * here  */
end_comment

begin_define
define|#
directive|define
name|NL80211_CMD_CONNECT
value|NL80211_CMD_CONNECT
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_HT_CAPABILITY
value|NL80211_ATTR_HT_CAPABILITY
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_BSS_BASIC_RATES
value|NL80211_ATTR_BSS_BASIC_RATES
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_WIPHY_TXQ_PARAMS
value|NL80211_ATTR_WIPHY_TXQ_PARAMS
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_WIPHY_FREQ
value|NL80211_ATTR_WIPHY_FREQ
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_WIPHY_CHANNEL_TYPE
value|NL80211_ATTR_WIPHY_CHANNEL_TYPE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_MGMT_SUBTYPE
value|NL80211_ATTR_MGMT_SUBTYPE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_IE
value|NL80211_ATTR_IE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_REG_INITIATOR
value|NL80211_ATTR_REG_INITIATOR
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_REG_TYPE
value|NL80211_ATTR_REG_TYPE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_FRAME
value|NL80211_ATTR_FRAME
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_SSID
value|NL80211_ATTR_SSID
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_AUTH_TYPE
value|NL80211_ATTR_AUTH_TYPE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_REASON_CODE
value|NL80211_ATTR_REASON_CODE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_CIPHER_SUITES_PAIRWISE
value|NL80211_ATTR_CIPHER_SUITES_PAIRWISE
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_CIPHER_SUITE_GROUP
value|NL80211_ATTR_CIPHER_SUITE_GROUP
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_WPA_VERSIONS
value|NL80211_ATTR_WPA_VERSIONS
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_AKM_SUITES
value|NL80211_ATTR_AKM_SUITES
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_KEY
value|NL80211_ATTR_KEY
end_define

begin_define
define|#
directive|define
name|NL80211_ATTR_KEYS
value|NL80211_ATTR_KEYS
end_define

begin_define
define|#
directive|define
name|NL80211_MAX_SUPP_RATES
value|32
end_define

begin_define
define|#
directive|define
name|NL80211_MAX_SUPP_REG_RULES
value|32
end_define

begin_define
define|#
directive|define
name|NL80211_TKIP_DATA_OFFSET_ENCR_KEY
value|0
end_define

begin_define
define|#
directive|define
name|NL80211_TKIP_DATA_OFFSET_TX_MIC_KEY
value|16
end_define

begin_define
define|#
directive|define
name|NL80211_TKIP_DATA_OFFSET_RX_MIC_KEY
value|24
end_define

begin_define
define|#
directive|define
name|NL80211_HT_CAPABILITY_LEN
value|26
end_define

begin_define
define|#
directive|define
name|NL80211_MAX_NR_CIPHER_SUITES
value|5
end_define

begin_define
define|#
directive|define
name|NL80211_MAX_NR_AKM_SUITES
value|2
end_define

begin_comment
comment|/**  * enum nl80211_iftype - (virtual) interface types  *  * @NL80211_IFTYPE_UNSPECIFIED: unspecified type, driver decides  * @NL80211_IFTYPE_ADHOC: independent BSS member  * @NL80211_IFTYPE_STATION: managed BSS member  * @NL80211_IFTYPE_AP: access point  * @NL80211_IFTYPE_AP_VLAN: VLAN interface for access points  * @NL80211_IFTYPE_WDS: wireless distribution interface  * @NL80211_IFTYPE_MONITOR: monitor interface receiving all frames  * @NL80211_IFTYPE_MESH_POINT: mesh point  * @NL80211_IFTYPE_MAX: highest interface type number currently defined  * @__NL80211_IFTYPE_AFTER_LAST: internal use  *  * These values are used with the %NL80211_ATTR_IFTYPE  * to set the type of an interface.  *  */
end_comment

begin_enum
enum|enum
name|nl80211_iftype
block|{
name|NL80211_IFTYPE_UNSPECIFIED
block|,
name|NL80211_IFTYPE_ADHOC
block|,
name|NL80211_IFTYPE_STATION
block|,
name|NL80211_IFTYPE_AP
block|,
name|NL80211_IFTYPE_AP_VLAN
block|,
name|NL80211_IFTYPE_WDS
block|,
name|NL80211_IFTYPE_MONITOR
block|,
name|NL80211_IFTYPE_MESH_POINT
block|,
comment|/* keep last */
name|__NL80211_IFTYPE_AFTER_LAST
block|,
name|NL80211_IFTYPE_MAX
init|=
name|__NL80211_IFTYPE_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_sta_flags - station flags  *  * Station flags. When a station is added to an AP interface, it is  * assumed to be already associated (and hence authenticated.)  *  * @NL80211_STA_FLAG_AUTHORIZED: station is authorized (802.1X)  * @NL80211_STA_FLAG_SHORT_PREAMBLE: station is capable of receiving frames  *	with short barker preamble  * @NL80211_STA_FLAG_WME: station is WME/QoS capable  * @NL80211_STA_FLAG_MFP: station uses management frame protection  */
end_comment

begin_enum
enum|enum
name|nl80211_sta_flags
block|{
name|__NL80211_STA_FLAG_INVALID
block|,
name|NL80211_STA_FLAG_AUTHORIZED
block|,
name|NL80211_STA_FLAG_SHORT_PREAMBLE
block|,
name|NL80211_STA_FLAG_WME
block|,
name|NL80211_STA_FLAG_MFP
block|,
comment|/* keep last */
name|__NL80211_STA_FLAG_AFTER_LAST
block|,
name|NL80211_STA_FLAG_MAX
init|=
name|__NL80211_STA_FLAG_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct nl80211_sta_flag_update - station flags mask/set  * @mask: mask of station flags to set  * @set: which values to set them to  *  * Both mask and set contain bits as per&enum nl80211_sta_flags.  */
end_comment

begin_struct
struct|struct
name|nl80211_sta_flag_update
block|{
name|__u32
name|mask
decl_stmt|;
name|__u32
name|set
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/**  * enum nl80211_rate_info - bitrate information  *  * These attribute types are used with %NL80211_STA_INFO_TXRATE  * when getting information about the bitrate of a station.  *  * @__NL80211_RATE_INFO_INVALID: attribute number 0 is reserved  * @NL80211_RATE_INFO_BITRATE: total bitrate (u16, 100kbit/s)  * @NL80211_RATE_INFO_MCS: mcs index for 802.11n (u8)  * @NL80211_RATE_INFO_40_MHZ_WIDTH: 40 Mhz dualchannel bitrate  * @NL80211_RATE_INFO_SHORT_GI: 400ns guard interval  * @NL80211_RATE_INFO_MAX: highest rate_info number currently defined  * @__NL80211_RATE_INFO_AFTER_LAST: internal use  */
end_comment

begin_enum
enum|enum
name|nl80211_rate_info
block|{
name|__NL80211_RATE_INFO_INVALID
block|,
name|NL80211_RATE_INFO_BITRATE
block|,
name|NL80211_RATE_INFO_MCS
block|,
name|NL80211_RATE_INFO_40_MHZ_WIDTH
block|,
name|NL80211_RATE_INFO_SHORT_GI
block|,
comment|/* keep last */
name|__NL80211_RATE_INFO_AFTER_LAST
block|,
name|NL80211_RATE_INFO_MAX
init|=
name|__NL80211_RATE_INFO_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_sta_info - station information  *  * These attribute types are used with %NL80211_ATTR_STA_INFO  * when getting information about a station.  *  * @__NL80211_STA_INFO_INVALID: attribute number 0 is reserved  * @NL80211_STA_INFO_INACTIVE_TIME: time since last activity (u32, msecs)  * @NL80211_STA_INFO_RX_BYTES: total received bytes (u32, from this station)  * @NL80211_STA_INFO_TX_BYTES: total transmitted bytes (u32, to this station)  * @__NL80211_STA_INFO_AFTER_LAST: internal  * @NL80211_STA_INFO_MAX: highest possible station info attribute  * @NL80211_STA_INFO_SIGNAL: signal strength of last received PPDU (u8, dBm)  * @NL80211_STA_INFO_TX_BITRATE: current unicast tx rate, nested attribute  * 	containing info as possible, see&enum nl80211_sta_info_txrate.  * @NL80211_STA_INFO_RX_PACKETS: total received packet (u32, from this station)  * @NL80211_STA_INFO_TX_PACKETS: total transmitted packets (u32, to this  *	station)  */
end_comment

begin_enum
enum|enum
name|nl80211_sta_info
block|{
name|__NL80211_STA_INFO_INVALID
block|,
name|NL80211_STA_INFO_INACTIVE_TIME
block|,
name|NL80211_STA_INFO_RX_BYTES
block|,
name|NL80211_STA_INFO_TX_BYTES
block|,
name|NL80211_STA_INFO_LLID
block|,
name|NL80211_STA_INFO_PLID
block|,
name|NL80211_STA_INFO_PLINK_STATE
block|,
name|NL80211_STA_INFO_SIGNAL
block|,
name|NL80211_STA_INFO_TX_BITRATE
block|,
name|NL80211_STA_INFO_RX_PACKETS
block|,
name|NL80211_STA_INFO_TX_PACKETS
block|,
comment|/* keep last */
name|__NL80211_STA_INFO_AFTER_LAST
block|,
name|NL80211_STA_INFO_MAX
init|=
name|__NL80211_STA_INFO_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_mpath_flags - nl80211 mesh path flags  *  * @NL80211_MPATH_FLAG_ACTIVE: the mesh path is active  * @NL80211_MPATH_FLAG_RESOLVING: the mesh path discovery process is running  * @NL80211_MPATH_FLAG_SN_VALID: the mesh path contains a valid SN  * @NL80211_MPATH_FLAG_FIXED: the mesh path has been manually set  * @NL80211_MPATH_FLAG_RESOLVED: the mesh path discovery process succeeded  */
end_comment

begin_enum
enum|enum
name|nl80211_mpath_flags
block|{
name|NL80211_MPATH_FLAG_ACTIVE
init|=
literal|1
operator|<<
literal|0
block|,
name|NL80211_MPATH_FLAG_RESOLVING
init|=
literal|1
operator|<<
literal|1
block|,
name|NL80211_MPATH_FLAG_SN_VALID
init|=
literal|1
operator|<<
literal|2
block|,
name|NL80211_MPATH_FLAG_FIXED
init|=
literal|1
operator|<<
literal|3
block|,
name|NL80211_MPATH_FLAG_RESOLVED
init|=
literal|1
operator|<<
literal|4
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_mpath_info - mesh path information  *  * These attribute types are used with %NL80211_ATTR_MPATH_INFO when getting  * information about a mesh path.  *  * @__NL80211_MPATH_INFO_INVALID: attribute number 0 is reserved  * @NL80211_ATTR_MPATH_FRAME_QLEN: number of queued frames for this destination  * @NL80211_ATTR_MPATH_SN: destination sequence number  * @NL80211_ATTR_MPATH_METRIC: metric (cost) of this mesh path  * @NL80211_ATTR_MPATH_EXPTIME: expiration time for the path, in msec from now  * @NL80211_ATTR_MPATH_FLAGS: mesh path flags, enumerated in  *&enum nl80211_mpath_flags;  * @NL80211_ATTR_MPATH_DISCOVERY_TIMEOUT: total path discovery timeout, in msec  * @NL80211_ATTR_MPATH_DISCOVERY_RETRIES: mesh path discovery retries  */
end_comment

begin_enum
enum|enum
name|nl80211_mpath_info
block|{
name|__NL80211_MPATH_INFO_INVALID
block|,
name|NL80211_MPATH_INFO_FRAME_QLEN
block|,
name|NL80211_MPATH_INFO_SN
block|,
name|NL80211_MPATH_INFO_METRIC
block|,
name|NL80211_MPATH_INFO_EXPTIME
block|,
name|NL80211_MPATH_INFO_FLAGS
block|,
name|NL80211_MPATH_INFO_DISCOVERY_TIMEOUT
block|,
name|NL80211_MPATH_INFO_DISCOVERY_RETRIES
block|,
comment|/* keep last */
name|__NL80211_MPATH_INFO_AFTER_LAST
block|,
name|NL80211_MPATH_INFO_MAX
init|=
name|__NL80211_MPATH_INFO_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_band_attr - band attributes  * @__NL80211_BAND_ATTR_INVALID: attribute number 0 is reserved  * @NL80211_BAND_ATTR_FREQS: supported frequencies in this band,  *	an array of nested frequency attributes  * @NL80211_BAND_ATTR_RATES: supported bitrates in this band,  *	an array of nested bitrate attributes  * @NL80211_BAND_ATTR_HT_MCS_SET: 16-byte attribute containing the MCS set as  *	defined in 802.11n  * @NL80211_BAND_ATTR_HT_CAPA: HT capabilities, as in the HT information IE  * @NL80211_BAND_ATTR_HT_AMPDU_FACTOR: A-MPDU factor, as in 11n  * @NL80211_BAND_ATTR_HT_AMPDU_DENSITY: A-MPDU density, as in 11n  */
end_comment

begin_enum
enum|enum
name|nl80211_band_attr
block|{
name|__NL80211_BAND_ATTR_INVALID
block|,
name|NL80211_BAND_ATTR_FREQS
block|,
name|NL80211_BAND_ATTR_RATES
block|,
name|NL80211_BAND_ATTR_HT_MCS_SET
block|,
name|NL80211_BAND_ATTR_HT_CAPA
block|,
name|NL80211_BAND_ATTR_HT_AMPDU_FACTOR
block|,
name|NL80211_BAND_ATTR_HT_AMPDU_DENSITY
block|,
comment|/* keep last */
name|__NL80211_BAND_ATTR_AFTER_LAST
block|,
name|NL80211_BAND_ATTR_MAX
init|=
name|__NL80211_BAND_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NL80211_BAND_ATTR_HT_CAPA
value|NL80211_BAND_ATTR_HT_CAPA
end_define

begin_comment
comment|/**  * enum nl80211_frequency_attr - frequency attributes  * @NL80211_FREQUENCY_ATTR_FREQ: Frequency in MHz  * @NL80211_FREQUENCY_ATTR_DISABLED: Channel is disabled in current  *	regulatory domain.  * @NL80211_FREQUENCY_ATTR_PASSIVE_SCAN: Only passive scanning is  *	permitted on this channel in current regulatory domain.  * @NL80211_FREQUENCY_ATTR_NO_IBSS: IBSS networks are not permitted  *	on this channel in current regulatory domain.  * @NL80211_FREQUENCY_ATTR_RADAR: Radar detection is mandatory  *	on this channel in current regulatory domain.  * @NL80211_FREQUENCY_ATTR_MAX_TX_POWER: Maximum transmission power in mBm  *	(100 * dBm).  */
end_comment

begin_enum
enum|enum
name|nl80211_frequency_attr
block|{
name|__NL80211_FREQUENCY_ATTR_INVALID
block|,
name|NL80211_FREQUENCY_ATTR_FREQ
block|,
name|NL80211_FREQUENCY_ATTR_DISABLED
block|,
name|NL80211_FREQUENCY_ATTR_PASSIVE_SCAN
block|,
name|NL80211_FREQUENCY_ATTR_NO_IBSS
block|,
name|NL80211_FREQUENCY_ATTR_RADAR
block|,
name|NL80211_FREQUENCY_ATTR_MAX_TX_POWER
block|,
comment|/* keep last */
name|__NL80211_FREQUENCY_ATTR_AFTER_LAST
block|,
name|NL80211_FREQUENCY_ATTR_MAX
init|=
name|__NL80211_FREQUENCY_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NL80211_FREQUENCY_ATTR_MAX_TX_POWER
value|NL80211_FREQUENCY_ATTR_MAX_TX_POWER
end_define

begin_comment
comment|/**  * enum nl80211_bitrate_attr - bitrate attributes  * @NL80211_BITRATE_ATTR_RATE: Bitrate in units of 100 kbps  * @NL80211_BITRATE_ATTR_2GHZ_SHORTPREAMBLE: Short preamble supported  *	in 2.4 GHz band.  */
end_comment

begin_enum
enum|enum
name|nl80211_bitrate_attr
block|{
name|__NL80211_BITRATE_ATTR_INVALID
block|,
name|NL80211_BITRATE_ATTR_RATE
block|,
name|NL80211_BITRATE_ATTR_2GHZ_SHORTPREAMBLE
block|,
comment|/* keep last */
name|__NL80211_BITRATE_ATTR_AFTER_LAST
block|,
name|NL80211_BITRATE_ATTR_MAX
init|=
name|__NL80211_BITRATE_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_initiator - Indicates the initiator of a reg domain request  * @NL80211_REGDOM_SET_BY_CORE: Core queried CRDA for a dynamic world  * 	regulatory domain.  * @NL80211_REGDOM_SET_BY_USER: User asked the wireless core to set the  * 	regulatory domain.  * @NL80211_REGDOM_SET_BY_DRIVER: a wireless drivers has hinted to the  * 	wireless core it thinks its knows the regulatory domain we should be in.  * @NL80211_REGDOM_SET_BY_COUNTRY_IE: the wireless core has received an  * 	802.11 country information element with regulatory information it  * 	thinks we should consider.  */
end_comment

begin_enum
enum|enum
name|nl80211_reg_initiator
block|{
name|NL80211_REGDOM_SET_BY_CORE
block|,
name|NL80211_REGDOM_SET_BY_USER
block|,
name|NL80211_REGDOM_SET_BY_DRIVER
block|,
name|NL80211_REGDOM_SET_BY_COUNTRY_IE
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_reg_type - specifies the type of regulatory domain  * @NL80211_REGDOM_TYPE_COUNTRY: the regulatory domain set is one that pertains  *	to a specific country. When this is set you can count on the  *	ISO / IEC 3166 alpha2 country code being valid.  * @NL80211_REGDOM_TYPE_WORLD: the regulatory set domain is the world regulatory  * 	domain.  * @NL80211_REGDOM_TYPE_CUSTOM_WORLD: the regulatory domain set is a custom  * 	driver specific world regulatory domain. These do not apply system-wide  * 	and are only applicable to the individual devices which have requested  * 	them to be applied.  * @NL80211_REGDOM_TYPE_INTERSECTION: the regulatory domain set is the product  *	of an intersection between two regulatory domains -- the previously  *	set regulatory domain on the system and the last accepted regulatory  *	domain request to be processed.  */
end_comment

begin_enum
enum|enum
name|nl80211_reg_type
block|{
name|NL80211_REGDOM_TYPE_COUNTRY
block|,
name|NL80211_REGDOM_TYPE_WORLD
block|,
name|NL80211_REGDOM_TYPE_CUSTOM_WORLD
block|,
name|NL80211_REGDOM_TYPE_INTERSECTION
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_reg_rule_attr - regulatory rule attributes  * @NL80211_ATTR_REG_RULE_FLAGS: a set of flags which specify additional  * 	considerations for a given frequency range. These are the  *&enum nl80211_reg_rule_flags.  * @NL80211_ATTR_FREQ_RANGE_START: starting frequencry for the regulatory  * 	rule in KHz. This is not a center of frequency but an actual regulatory  * 	band edge.  * @NL80211_ATTR_FREQ_RANGE_END: ending frequency for the regulatory rule  * 	in KHz. This is not a center a frequency but an actual regulatory  * 	band edge.  * @NL80211_ATTR_FREQ_RANGE_MAX_BW: maximum allowed bandwidth for this  * 	frequency range, in KHz.  * @NL80211_ATTR_POWER_RULE_MAX_ANT_GAIN: the maximum allowed antenna gain  * 	for a given frequency range. The value is in mBi (100 * dBi).  * 	If you don't have one then don't send this.  * @NL80211_ATTR_POWER_RULE_MAX_EIRP: the maximum allowed EIRP for  * 	a given frequency range. The value is in mBm (100 * dBm).  */
end_comment

begin_enum
enum|enum
name|nl80211_reg_rule_attr
block|{
name|__NL80211_REG_RULE_ATTR_INVALID
block|,
name|NL80211_ATTR_REG_RULE_FLAGS
block|,
name|NL80211_ATTR_FREQ_RANGE_START
block|,
name|NL80211_ATTR_FREQ_RANGE_END
block|,
name|NL80211_ATTR_FREQ_RANGE_MAX_BW
block|,
name|NL80211_ATTR_POWER_RULE_MAX_ANT_GAIN
block|,
name|NL80211_ATTR_POWER_RULE_MAX_EIRP
block|,
comment|/* keep last */
name|__NL80211_REG_RULE_ATTR_AFTER_LAST
block|,
name|NL80211_REG_RULE_ATTR_MAX
init|=
name|__NL80211_REG_RULE_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_reg_rule_flags - regulatory rule flags  *  * @NL80211_RRF_NO_OFDM: OFDM modulation not allowed  * @NL80211_RRF_NO_CCK: CCK modulation not allowed  * @NL80211_RRF_NO_INDOOR: indoor operation not allowed  * @NL80211_RRF_NO_OUTDOOR: outdoor operation not allowed  * @NL80211_RRF_DFS: DFS support is required to be used  * @NL80211_RRF_PTP_ONLY: this is only for Point To Point links  * @NL80211_RRF_PTMP_ONLY: this is only for Point To Multi Point links  * @NL80211_RRF_PASSIVE_SCAN: passive scan is required  * @NL80211_RRF_NO_IBSS: no IBSS is allowed  */
end_comment

begin_enum
enum|enum
name|nl80211_reg_rule_flags
block|{
name|NL80211_RRF_NO_OFDM
init|=
literal|1
operator|<<
literal|0
block|,
name|NL80211_RRF_NO_CCK
init|=
literal|1
operator|<<
literal|1
block|,
name|NL80211_RRF_NO_INDOOR
init|=
literal|1
operator|<<
literal|2
block|,
name|NL80211_RRF_NO_OUTDOOR
init|=
literal|1
operator|<<
literal|3
block|,
name|NL80211_RRF_DFS
init|=
literal|1
operator|<<
literal|4
block|,
name|NL80211_RRF_PTP_ONLY
init|=
literal|1
operator|<<
literal|5
block|,
name|NL80211_RRF_PTMP_ONLY
init|=
literal|1
operator|<<
literal|6
block|,
name|NL80211_RRF_PASSIVE_SCAN
init|=
literal|1
operator|<<
literal|7
block|,
name|NL80211_RRF_NO_IBSS
init|=
literal|1
operator|<<
literal|8
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_survey_info - survey information  *  * These attribute types are used with %NL80211_ATTR_SURVEY_INFO  * when getting information about a survey.  *  * @__NL80211_SURVEY_INFO_INVALID: attribute number 0 is reserved  * @NL80211_SURVEY_INFO_FREQUENCY: center frequency of channel  * @NL80211_SURVEY_INFO_NOISE: noise level of channel (u8, dBm)  */
end_comment

begin_enum
enum|enum
name|nl80211_survey_info
block|{
name|__NL80211_SURVEY_INFO_INVALID
block|,
name|NL80211_SURVEY_INFO_FREQUENCY
block|,
name|NL80211_SURVEY_INFO_NOISE
block|,
comment|/* keep last */
name|__NL80211_SURVEY_INFO_AFTER_LAST
block|,
name|NL80211_SURVEY_INFO_MAX
init|=
name|__NL80211_SURVEY_INFO_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_mntr_flags - monitor configuration flags  *  * Monitor configuration flags.  *  * @__NL80211_MNTR_FLAG_INVALID: reserved  *  * @NL80211_MNTR_FLAG_FCSFAIL: pass frames with bad FCS  * @NL80211_MNTR_FLAG_PLCPFAIL: pass frames with bad PLCP  * @NL80211_MNTR_FLAG_CONTROL: pass control frames  * @NL80211_MNTR_FLAG_OTHER_BSS: disable BSSID filtering  * @NL80211_MNTR_FLAG_COOK_FRAMES: report frames after processing.  *	overrides all other flags.  *  * @__NL80211_MNTR_FLAG_AFTER_LAST: internal use  * @NL80211_MNTR_FLAG_MAX: highest possible monitor flag  */
end_comment

begin_enum
enum|enum
name|nl80211_mntr_flags
block|{
name|__NL80211_MNTR_FLAG_INVALID
block|,
name|NL80211_MNTR_FLAG_FCSFAIL
block|,
name|NL80211_MNTR_FLAG_PLCPFAIL
block|,
name|NL80211_MNTR_FLAG_CONTROL
block|,
name|NL80211_MNTR_FLAG_OTHER_BSS
block|,
name|NL80211_MNTR_FLAG_COOK_FRAMES
block|,
comment|/* keep last */
name|__NL80211_MNTR_FLAG_AFTER_LAST
block|,
name|NL80211_MNTR_FLAG_MAX
init|=
name|__NL80211_MNTR_FLAG_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_meshconf_params - mesh configuration parameters  *  * Mesh configuration parameters  *  * @__NL80211_MESHCONF_INVALID: internal use  *  * @NL80211_MESHCONF_RETRY_TIMEOUT: specifies the initial retry timeout in  * millisecond units, used by the Peer Link Open message  *  * @NL80211_MESHCONF_CONFIRM_TIMEOUT: specifies the inital confirm timeout, in  * millisecond units, used by the peer link management to close a peer link  *  * @NL80211_MESHCONF_HOLDING_TIMEOUT: specifies the holding timeout, in  * millisecond units  *  * @NL80211_MESHCONF_MAX_PEER_LINKS: maximum number of peer links allowed  * on this mesh interface  *  * @NL80211_MESHCONF_MAX_RETRIES: specifies the maximum number of peer link  * open retries that can be sent to establish a new peer link instance in a  * mesh  *  * @NL80211_MESHCONF_TTL: specifies the value of TTL field set at a source mesh  * point.  *  * @NL80211_MESHCONF_AUTO_OPEN_PLINKS: whether we should automatically  * open peer links when we detect compatible mesh peers.  *  * @NL80211_MESHCONF_HWMP_MAX_PREQ_RETRIES: the number of action frames  * containing a PREQ that an MP can send to a particular destination (path  * target)  *  * @NL80211_MESHCONF_PATH_REFRESH_TIME: how frequently to refresh mesh paths  * (in milliseconds)  *  * @NL80211_MESHCONF_MIN_DISCOVERY_TIMEOUT: minimum length of time to wait  * until giving up on a path discovery (in milliseconds)  *  * @NL80211_MESHCONF_HWMP_ACTIVE_PATH_TIMEOUT: The time (in TUs) for which mesh  * points receiving a PREQ shall consider the forwarding information from the  * root to be valid. (TU = time unit)  *  * @NL80211_MESHCONF_HWMP_PREQ_MIN_INTERVAL: The minimum interval of time (in  * TUs) during which an MP can send only one action frame containing a PREQ  * reference element  *  * @NL80211_MESHCONF_HWMP_NET_DIAM_TRVS_TIME: The interval of time (in TUs)  * that it takes for an HWMP information element to propagate across the mesh  *  * @NL80211_MESHCONF_ROOTMODE: whether root mode is enabled or not  *  * @NL80211_MESHCONF_ATTR_MAX: highest possible mesh configuration attribute  *  * @__NL80211_MESHCONF_ATTR_AFTER_LAST: internal use  */
end_comment

begin_enum
enum|enum
name|nl80211_meshconf_params
block|{
name|__NL80211_MESHCONF_INVALID
block|,
name|NL80211_MESHCONF_RETRY_TIMEOUT
block|,
name|NL80211_MESHCONF_CONFIRM_TIMEOUT
block|,
name|NL80211_MESHCONF_HOLDING_TIMEOUT
block|,
name|NL80211_MESHCONF_MAX_PEER_LINKS
block|,
name|NL80211_MESHCONF_MAX_RETRIES
block|,
name|NL80211_MESHCONF_TTL
block|,
name|NL80211_MESHCONF_AUTO_OPEN_PLINKS
block|,
name|NL80211_MESHCONF_HWMP_MAX_PREQ_RETRIES
block|,
name|NL80211_MESHCONF_PATH_REFRESH_TIME
block|,
name|NL80211_MESHCONF_MIN_DISCOVERY_TIMEOUT
block|,
name|NL80211_MESHCONF_HWMP_ACTIVE_PATH_TIMEOUT
block|,
name|NL80211_MESHCONF_HWMP_PREQ_MIN_INTERVAL
block|,
name|NL80211_MESHCONF_HWMP_NET_DIAM_TRVS_TIME
block|,
name|NL80211_MESHCONF_HWMP_ROOTMODE
block|,
comment|/* keep last */
name|__NL80211_MESHCONF_ATTR_AFTER_LAST
block|,
name|NL80211_MESHCONF_ATTR_MAX
init|=
name|__NL80211_MESHCONF_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_txq_attr - TX queue parameter attributes  * @__NL80211_TXQ_ATTR_INVALID: Attribute number 0 is reserved  * @NL80211_TXQ_ATTR_QUEUE: TX queue identifier (NL80211_TXQ_Q_*)  * @NL80211_TXQ_ATTR_TXOP: Maximum burst time in units of 32 usecs, 0 meaning  *	disabled  * @NL80211_TXQ_ATTR_CWMIN: Minimum contention window [a value of the form  *	2^n-1 in the range 1..32767]  * @NL80211_TXQ_ATTR_CWMAX: Maximum contention window [a value of the form  *	2^n-1 in the range 1..32767]  * @NL80211_TXQ_ATTR_AIFS: Arbitration interframe space [0..255]  * @__NL80211_TXQ_ATTR_AFTER_LAST: Internal  * @NL80211_TXQ_ATTR_MAX: Maximum TXQ attribute number  */
end_comment

begin_enum
enum|enum
name|nl80211_txq_attr
block|{
name|__NL80211_TXQ_ATTR_INVALID
block|,
name|NL80211_TXQ_ATTR_QUEUE
block|,
name|NL80211_TXQ_ATTR_TXOP
block|,
name|NL80211_TXQ_ATTR_CWMIN
block|,
name|NL80211_TXQ_ATTR_CWMAX
block|,
name|NL80211_TXQ_ATTR_AIFS
block|,
comment|/* keep last */
name|__NL80211_TXQ_ATTR_AFTER_LAST
block|,
name|NL80211_TXQ_ATTR_MAX
init|=
name|__NL80211_TXQ_ATTR_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nl80211_txq_q
block|{
name|NL80211_TXQ_Q_VO
block|,
name|NL80211_TXQ_Q_VI
block|,
name|NL80211_TXQ_Q_BE
block|,
name|NL80211_TXQ_Q_BK
block|}
enum|;
end_enum

begin_enum
enum|enum
name|nl80211_channel_type
block|{
name|NL80211_CHAN_NO_HT
block|,
name|NL80211_CHAN_HT20
block|,
name|NL80211_CHAN_HT40MINUS
block|,
name|NL80211_CHAN_HT40PLUS
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_bss - netlink attributes for a BSS  *  * @__NL80211_BSS_INVALID: invalid  * @NL80211_BSS_FREQUENCY: frequency in MHz (u32)  * @NL80211_BSS_TSF: TSF of the received probe response/beacon (u64)  * @NL80211_BSS_BEACON_INTERVAL: beacon interval of the (I)BSS (u16)  * @NL80211_BSS_CAPABILITY: capability field (CPU order, u16)  * @NL80211_BSS_INFORMATION_ELEMENTS: binary attribute containing the  *	raw information elements from the probe response/beacon (bin)  * @NL80211_BSS_SIGNAL_MBM: signal strength of probe response/beacon  *	in mBm (100 * dBm) (s32)  * @NL80211_BSS_SIGNAL_UNSPEC: signal strength of the probe response/beacon  *	in unspecified units, scaled to 0..100 (u8)  * @NL80211_BSS_STATUS: status, if this BSS is "used"  * @NL80211_BSS_SEEN_MS_AGO: age of this BSS entry in ms  * @__NL80211_BSS_AFTER_LAST: internal  * @NL80211_BSS_MAX: highest BSS attribute  */
end_comment

begin_enum
enum|enum
name|nl80211_bss
block|{
name|__NL80211_BSS_INVALID
block|,
name|NL80211_BSS_BSSID
block|,
name|NL80211_BSS_FREQUENCY
block|,
name|NL80211_BSS_TSF
block|,
name|NL80211_BSS_BEACON_INTERVAL
block|,
name|NL80211_BSS_CAPABILITY
block|,
name|NL80211_BSS_INFORMATION_ELEMENTS
block|,
name|NL80211_BSS_SIGNAL_MBM
block|,
name|NL80211_BSS_SIGNAL_UNSPEC
block|,
name|NL80211_BSS_STATUS
block|,
name|NL80211_BSS_SEEN_MS_AGO
block|,
comment|/* keep last */
name|__NL80211_BSS_AFTER_LAST
block|,
name|NL80211_BSS_MAX
init|=
name|__NL80211_BSS_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_bss_status - BSS "status"  */
end_comment

begin_enum
enum|enum
name|nl80211_bss_status
block|{
name|NL80211_BSS_STATUS_AUTHENTICATED
block|,
name|NL80211_BSS_STATUS_ASSOCIATED
block|,
name|NL80211_BSS_STATUS_IBSS_JOINED
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_auth_type - AuthenticationType  *  * @NL80211_AUTHTYPE_OPEN_SYSTEM: Open System authentication  * @NL80211_AUTHTYPE_SHARED_KEY: Shared Key authentication (WEP only)  * @NL80211_AUTHTYPE_FT: Fast BSS Transition (IEEE 802.11r)  * @NL80211_AUTHTYPE_NETWORK_EAP: Network EAP (some Cisco APs and mainly LEAP)  * @__NL80211_AUTHTYPE_NUM: internal  * @NL80211_AUTHTYPE_MAX: maximum valid auth algorithm  * @NL80211_AUTHTYPE_AUTOMATIC: determine automatically (if necessary by  *	trying multiple times); this is invalid in netlink -- leave out  *	the attribute for this on CONNECT commands.  */
end_comment

begin_enum
enum|enum
name|nl80211_auth_type
block|{
name|NL80211_AUTHTYPE_OPEN_SYSTEM
block|,
name|NL80211_AUTHTYPE_SHARED_KEY
block|,
name|NL80211_AUTHTYPE_FT
block|,
name|NL80211_AUTHTYPE_NETWORK_EAP
block|,
comment|/* keep last */
name|__NL80211_AUTHTYPE_NUM
block|,
name|NL80211_AUTHTYPE_MAX
init|=
name|__NL80211_AUTHTYPE_NUM
operator|-
literal|1
block|,
name|NL80211_AUTHTYPE_AUTOMATIC
block|}
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_key_type - Key Type  * @NL80211_KEYTYPE_GROUP: Group (broadcast/multicast) key  * @NL80211_KEYTYPE_PAIRWISE: Pairwise (unicast/individual) key  * @NL80211_KEYTYPE_PEERKEY: PeerKey (DLS)  */
end_comment

begin_enum
enum|enum
name|nl80211_key_type
block|{
name|NL80211_KEYTYPE_GROUP
block|,
name|NL80211_KEYTYPE_PAIRWISE
block|,
name|NL80211_KEYTYPE_PEERKEY
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_mfp - Management frame protection state  * @NL80211_MFP_NO: Management frame protection not used  * @NL80211_MFP_REQUIRED: Management frame protection required  */
end_comment

begin_enum
enum|enum
name|nl80211_mfp
block|{
name|NL80211_MFP_NO
block|,
name|NL80211_MFP_REQUIRED
block|, }
enum|;
end_enum

begin_enum
enum|enum
name|nl80211_wpa_versions
block|{
name|NL80211_WPA_VERSION_1
init|=
literal|1
operator|<<
literal|0
block|,
name|NL80211_WPA_VERSION_2
init|=
literal|1
operator|<<
literal|1
block|, }
enum|;
end_enum

begin_comment
comment|/**  * enum nl80211_key_attributes - key attributes  * @__NL80211_KEY_INVALID: invalid  * @NL80211_KEY_DATA: (temporal) key data; for TKIP this consists of  *	16 bytes encryption key followed by 8 bytes each for TX and RX MIC  *	keys  * @NL80211_KEY_IDX: key ID (u8, 0-3)  * @NL80211_KEY_CIPHER: key cipher suite (u32, as defined by IEEE 802.11  *	section 7.3.2.25.1, e.g. 0x000FAC04)  * @NL80211_KEY_SEQ: transmit key sequence number (IV/PN) for TKIP and  *	CCMP keys, each six bytes in little endian  * @NL80211_KEY_DEFAULT: flag indicating default key  * @NL80211_KEY_DEFAULT_MGMT: flag indicating default management key  * @__NL80211_KEY_AFTER_LAST: internal  * @NL80211_KEY_MAX: highest key attribute  */
end_comment

begin_enum
enum|enum
name|nl80211_key_attributes
block|{
name|__NL80211_KEY_INVALID
block|,
name|NL80211_KEY_DATA
block|,
name|NL80211_KEY_IDX
block|,
name|NL80211_KEY_CIPHER
block|,
name|NL80211_KEY_SEQ
block|,
name|NL80211_KEY_DEFAULT
block|,
name|NL80211_KEY_DEFAULT_MGMT
block|,
comment|/* keep last */
name|__NL80211_KEY_AFTER_LAST
block|,
name|NL80211_KEY_MAX
init|=
name|__NL80211_KEY_AFTER_LAST
operator|-
literal|1
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __LINUX_NL80211_H */
end_comment

end_unit

