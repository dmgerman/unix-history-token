begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This is based on Linux Wireless Extensions header file from WIRELESS_EXT 18.  * I have just removed kernel related headers and added some typedefs etc. to  * make this easier to include into user space programs.  * Jouni Malinen, 2005-03-12.  */
end_comment

begin_comment
comment|/*  * This file define a set of standard wireless extensions  *  * Version :	19	18.3.05  *  * Authors :	Jean Tourrilhes - HPL -<jt@hpl.hp.com>  * Copyright (c) 1997-2005 Jean Tourrilhes, All Rights Reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_WIRELESS_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_WIRELESS_H
end_define

begin_comment
comment|/************************** DOCUMENTATION **************************/
end_comment

begin_comment
comment|/*  * Initial APIs (1996 -> onward) :  * -----------------------------  * Basically, the wireless extensions are for now a set of standard ioctl  * call + /proc/net/wireless  *  * The entry /proc/net/wireless give statistics and information on the  * driver.  * This is better than having each driver having its entry because  * its centralised and we may remove the driver module safely.  *  * Ioctl are used to configure the driver and issue commands.  This is  * better than command line options of insmod because we may want to  * change dynamically (while the driver is running) some parameters.  *  * The ioctl mechanimsm are copied from standard devices ioctl.  * We have the list of command plus a structure descibing the  * data exchanged...  * Note that to add these ioctl, I was obliged to modify :  *	# net/core/dev.c (two place + add include)  *	# net/ipv4/af_inet.c (one place + add include)  *  * /proc/net/wireless is a copy of /proc/net/dev.  * We have a structure for data passed from the driver to /proc/net/wireless  * Too add this, I've modified :  *	# net/core/dev.c (two other places)  *	# include/linux/netdevice.h (one place)  *	# include/linux/proc_fs.h (one place)  *  * New driver API (2002 -> onward) :  * -------------------------------  * This file is only concerned with the user space API and common definitions.  * The new driver API is defined and documented in :  *	# include/net/iw_handler.h  *  * Note as well that /proc/net/wireless implementation has now moved in :  *	# net/core/wireless.c  *  * Wireless Events (2002 -> onward) :  * --------------------------------  * Events are defined at the end of this file, and implemented in :  *	# net/core/wireless.c  *  * Other comments :  * --------------  * Do not add here things that are redundant with other mechanisms  * (drivers init, ifconfig, /proc/net/dev, ...) and with are not  * wireless specific.  *  * These wireless extensions are not magic : each driver has to provide  * support for them...  *  * IMPORTANT NOTE : As everything in the kernel, this is very much a  * work in progress. Contact me if you have ideas of improvements...  */
end_comment

begin_comment
comment|/***************************** INCLUDES *****************************/
end_comment

begin_comment
comment|/* jkm - replaced linux headers with C library headers, added typedefs */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* To minimise problems in user space, I might remove those headers  * at some point. Jean II */
end_comment

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_comment
comment|/* for "caddr_t" et al		*/
end_comment

begin_include
include|#
directive|include
file|<linux/socket.h>
end_include

begin_comment
comment|/* for "struct sockaddr" et al	*/
end_comment

begin_include
include|#
directive|include
file|<linux/if.h>
end_include

begin_comment
comment|/* for IFNAMSIZ and co... */
end_comment

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_typedef
typedef|typedef
name|__uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32_t
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16_t
name|__s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint8_t
name|__u8
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__user
end_ifndef

begin_define
define|#
directive|define
name|__user
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __user */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/***************************** VERSION *****************************/
end_comment

begin_comment
comment|/*  * This constant is used to know the availability of the wireless  * extensions and to know which version of wireless extensions it is  * (there is some stuff that will be added in the future...)  * I just plan to increment with each new version.  */
end_comment

begin_define
define|#
directive|define
name|WIRELESS_EXT
value|19
end_define

begin_comment
comment|/*  * Changes :  *  * V2 to V3  * --------  *	Alan Cox start some incompatibles changes. I've integrated a bit more.  *	- Encryption renamed to Encode to avoid US regulation problems  *	- Frequency changed from float to struct to avoid problems on old 386  *  * V3 to V4  * --------  *	- Add sensitivity  *  * V4 to V5  * --------  *	- Missing encoding definitions in range  *	- Access points stuff  *  * V5 to V6  * --------  *	- 802.11 support (ESSID ioctls)  *  * V6 to V7  * --------  *	- define IW_ESSID_MAX_SIZE and IW_MAX_AP  *  * V7 to V8  * --------  *	- Changed my e-mail address  *	- More 802.11 support (nickname, rate, rts, frag)  *	- List index in frequencies  *  * V8 to V9  * --------  *	- Support for 'mode of operation' (ad-hoc, managed...)  *	- Support for unicast and multicast power saving  *	- Change encoding to support larger tokens (>64 bits)  *	- Updated iw_params (disable, flags) and use it for NWID  *	- Extracted iw_point from iwreq for clarity  *  * V9 to V10  * ---------  *	- Add PM capability to range structure  *	- Add PM modifier : MAX/MIN/RELATIVE  *	- Add encoding option : IW_ENCODE_NOKEY  *	- Add TxPower ioctls (work like TxRate)  *  * V10 to V11  * ----------  *	- Add WE version in range (help backward/forward compatibility)  *	- Add retry ioctls (work like PM)  *  * V11 to V12  * ----------  *	- Add SIOCSIWSTATS to get /proc/net/wireless programatically  *	- Add DEV PRIVATE IOCTL to avoid collisions in SIOCDEVPRIVATE space  *	- Add new statistics (frag, retry, beacon)  *	- Add average quality (for user space calibration)  *  * V12 to V13  * ----------  *	- Document creation of new driver API.  *	- Extract union iwreq_data from struct iwreq (for new driver API).  *	- Rename SIOCSIWNAME as SIOCSIWCOMMIT  *  * V13 to V14  * ----------  *	- Wireless Events support : define struct iw_event  *	- Define additional specific event numbers  *	- Add "addr" and "param" fields in union iwreq_data  *	- AP scanning stuff (SIOCSIWSCAN and friends)  *  * V14 to V15  * ----------  *	- Add IW_PRIV_TYPE_ADDR for struct sockaddr private arg  *	- Make struct iw_freq signed (both m& e), add explicit padding  *	- Add IWEVCUSTOM for driver specific event/scanning token  *	- Add IW_MAX_GET_SPY for driver returning a lot of addresses  *	- Add IW_TXPOW_RANGE for range of Tx Powers  *	- Add IWEVREGISTERED& IWEVEXPIRED events for Access Points  *	- Add IW_MODE_MONITOR for passive monitor  *  * V15 to V16  * ----------  *	- Increase the number of bitrates in iw_range to 32 (for 802.11g)  *	- Increase the number of frequencies in iw_range to 32 (for 802.11b+a)  *	- Reshuffle struct iw_range for increases, add filler  *	- Increase IW_MAX_AP to 64 for driver returning a lot of addresses  *	- Remove IW_MAX_GET_SPY because conflict with enhanced spy support  *	- Add SIOCSIWTHRSPY/SIOCGIWTHRSPY and "struct iw_thrspy"  *	- Add IW_ENCODE_TEMP and iw_range->encoding_login_index  *  * V16 to V17  * ----------  *	- Add flags to frequency -> auto/fixed  *	- Document (struct iw_quality *)->updated, add new flags (INVALID)  *	- Wireless Event capability in struct iw_range  *	- Add support for relative TxPower (yick !)  *  * V17 to V18 (From Jouni Malinen<j@w1.fi>)  * ----------  *	- Add support for WPA/WPA2  *	- Add extended encoding configuration (SIOCSIWENCODEEXT and  *	  SIOCGIWENCODEEXT)  *	- Add SIOCSIWGENIE/SIOCGIWGENIE  *	- Add SIOCSIWMLME  *	- Add SIOCSIWPMKSA  *	- Add struct iw_range bit field for supported encoding capabilities  *	- Add optional scan request parameters for SIOCSIWSCAN  *	- Add SIOCSIWAUTH/SIOCGIWAUTH for setting authentication and WPA  *	  related parameters (extensible up to 4096 parameter values)  *	- Add wireless events: IWEVGENIE, IWEVMICHAELMICFAILURE,  *	  IWEVASSOCREQIE, IWEVASSOCRESPIE, IWEVPMKIDCAND  *  * V18 to V19  * ----------  *	- Remove (struct iw_point *)->pointer from events and streams  *	- Remove header includes to help user space  *	- Increase IW_ENCODING_TOKEN_MAX from 32 to 64  *	- Add IW_QUAL_ALL_UPDATED and IW_QUAL_ALL_INVALID macros  *	- Add explicit flag to tell stats are in dBm : IW_QUAL_DBM  *	- Add IW_IOCTL_IDX() and IW_EVENT_IDX() macros  */
end_comment

begin_comment
comment|/**************************** CONSTANTS ****************************/
end_comment

begin_comment
comment|/* -------------------------- IOCTL LIST -------------------------- */
end_comment

begin_comment
comment|/* Wireless Identification */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWCOMMIT
value|0x8B00
end_define

begin_comment
comment|/* Commit pending changes to driver */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWNAME
value|0x8B01
end_define

begin_comment
comment|/* get name == wireless protocol */
end_comment

begin_comment
comment|/* SIOCGIWNAME is used to verify the presence of Wireless Extensions.  * Common values : "IEEE 802.11-DS", "IEEE 802.11-FH", "IEEE 802.11b"...  * Don't put the name of your driver there, it's useless. */
end_comment

begin_comment
comment|/* Basic operations */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWNWID
value|0x8B02
end_define

begin_comment
comment|/* set network id (pre-802.11) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWNWID
value|0x8B03
end_define

begin_comment
comment|/* get network id (the cell) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWFREQ
value|0x8B04
end_define

begin_comment
comment|/* set channel/frequency (Hz) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWFREQ
value|0x8B05
end_define

begin_comment
comment|/* get channel/frequency (Hz) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWMODE
value|0x8B06
end_define

begin_comment
comment|/* set operation mode */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWMODE
value|0x8B07
end_define

begin_comment
comment|/* get operation mode */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWSENS
value|0x8B08
end_define

begin_comment
comment|/* set sensitivity (dBm) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWSENS
value|0x8B09
end_define

begin_comment
comment|/* get sensitivity (dBm) */
end_comment

begin_comment
comment|/* Informative stuff */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWRANGE
value|0x8B0A
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWRANGE
value|0x8B0B
end_define

begin_comment
comment|/* Get range of parameters */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWPRIV
value|0x8B0C
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWPRIV
value|0x8B0D
end_define

begin_comment
comment|/* get private ioctl interface info */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWSTATS
value|0x8B0E
end_define

begin_comment
comment|/* Unused */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWSTATS
value|0x8B0F
end_define

begin_comment
comment|/* Get /proc/net/wireless stats */
end_comment

begin_comment
comment|/* SIOCGIWSTATS is strictly used between user space and the kernel, and  * is never passed to the driver (i.e. the driver will never see it). */
end_comment

begin_comment
comment|/* Spy support (statistics per MAC address - used for Mobile IP support) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWSPY
value|0x8B10
end_define

begin_comment
comment|/* set spy addresses */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWSPY
value|0x8B11
end_define

begin_comment
comment|/* get spy info (quality of link) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWTHRSPY
value|0x8B12
end_define

begin_comment
comment|/* set spy threshold (spy event) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWTHRSPY
value|0x8B13
end_define

begin_comment
comment|/* get spy threshold */
end_comment

begin_comment
comment|/* Access Point manipulation */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWAP
value|0x8B14
end_define

begin_comment
comment|/* set access point MAC addresses */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWAP
value|0x8B15
end_define

begin_comment
comment|/* get access point MAC addresses */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWAPLIST
value|0x8B17
end_define

begin_comment
comment|/* Deprecated in favor of scanning */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWSCAN
value|0x8B18
end_define

begin_comment
comment|/* trigger scanning (list cells) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWSCAN
value|0x8B19
end_define

begin_comment
comment|/* get scanning results */
end_comment

begin_comment
comment|/* 802.11 specific support */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWESSID
value|0x8B1A
end_define

begin_comment
comment|/* set ESSID (network name) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWESSID
value|0x8B1B
end_define

begin_comment
comment|/* get ESSID */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWNICKN
value|0x8B1C
end_define

begin_comment
comment|/* set node name/nickname */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWNICKN
value|0x8B1D
end_define

begin_comment
comment|/* get node name/nickname */
end_comment

begin_comment
comment|/* As the ESSID and NICKN are strings up to 32 bytes long, it doesn't fit  * within the 'iwreq' structure, so we need to use the 'data' member to  * point to a string in user space, like it is done for RANGE... */
end_comment

begin_comment
comment|/* Other parameters useful in 802.11 and some other devices */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWRATE
value|0x8B20
end_define

begin_comment
comment|/* set default bit rate (bps) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWRATE
value|0x8B21
end_define

begin_comment
comment|/* get default bit rate (bps) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWRTS
value|0x8B22
end_define

begin_comment
comment|/* set RTS/CTS threshold (bytes) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWRTS
value|0x8B23
end_define

begin_comment
comment|/* get RTS/CTS threshold (bytes) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWFRAG
value|0x8B24
end_define

begin_comment
comment|/* set fragmentation thr (bytes) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWFRAG
value|0x8B25
end_define

begin_comment
comment|/* get fragmentation thr (bytes) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWTXPOW
value|0x8B26
end_define

begin_comment
comment|/* set transmit power (dBm) */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWTXPOW
value|0x8B27
end_define

begin_comment
comment|/* get transmit power (dBm) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWRETRY
value|0x8B28
end_define

begin_comment
comment|/* set retry limits and lifetime */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWRETRY
value|0x8B29
end_define

begin_comment
comment|/* get retry limits and lifetime */
end_comment

begin_comment
comment|/* Encoding stuff (scrambling, hardware security, WEP...) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWENCODE
value|0x8B2A
end_define

begin_comment
comment|/* set encoding token& mode */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWENCODE
value|0x8B2B
end_define

begin_comment
comment|/* get encoding token& mode */
end_comment

begin_comment
comment|/* Power saving stuff (power management, unicast and multicast) */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWPOWER
value|0x8B2C
end_define

begin_comment
comment|/* set Power Management settings */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWPOWER
value|0x8B2D
end_define

begin_comment
comment|/* get Power Management settings */
end_comment

begin_comment
comment|/* WPA : Generic IEEE 802.11 informatiom element (e.g., for WPA/RSN/WMM).  * This ioctl uses struct iw_point and data buffer that includes IE id and len  * fields. More than one IE may be included in the request. Setting the generic  * IE to empty buffer (len=0) removes the generic IE from the driver. Drivers  * are allowed to generate their own WPA/RSN IEs, but in these cases, drivers  * are required to report the used IE as a wireless event, e.g., when  * associating with an AP. */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWGENIE
value|0x8B30
end_define

begin_comment
comment|/* set generic IE */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWGENIE
value|0x8B31
end_define

begin_comment
comment|/* get generic IE */
end_comment

begin_comment
comment|/* WPA : IEEE 802.11 MLME requests */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWMLME
value|0x8B16
end_define

begin_comment
comment|/* request MLME operation; uses 					 * struct iw_mlme */
end_comment

begin_comment
comment|/* WPA : Authentication mode parameters */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWAUTH
value|0x8B32
end_define

begin_comment
comment|/* set authentication mode params */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWAUTH
value|0x8B33
end_define

begin_comment
comment|/* get authentication mode params */
end_comment

begin_comment
comment|/* WPA : Extended version of encoding configuration */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWENCODEEXT
value|0x8B34
end_define

begin_comment
comment|/* set encoding token& mode */
end_comment

begin_define
define|#
directive|define
name|SIOCGIWENCODEEXT
value|0x8B35
end_define

begin_comment
comment|/* get encoding token& mode */
end_comment

begin_comment
comment|/* WPA2 : PMKSA cache management */
end_comment

begin_define
define|#
directive|define
name|SIOCSIWPMKSA
value|0x8B36
end_define

begin_comment
comment|/* PMKSA cache operation */
end_comment

begin_comment
comment|/* -------------------- DEV PRIVATE IOCTL LIST -------------------- */
end_comment

begin_comment
comment|/* These 32 ioctl are wireless device private, for 16 commands.  * Each driver is free to use them for whatever purpose it chooses,  * however the driver *must* export the description of those ioctls  * with SIOCGIWPRIV and *must* use arguments as defined below.  * If you don't follow those rules, DaveM is going to hate you (reason :  * it make mixed 32/64bit operation impossible).  */
end_comment

begin_define
define|#
directive|define
name|SIOCIWFIRSTPRIV
value|0x8BE0
end_define

begin_define
define|#
directive|define
name|SIOCIWLASTPRIV
value|0x8BFF
end_define

begin_comment
comment|/* Previously, we were using SIOCDEVPRIVATE, but we now have our  * separate range because of collisions with other tools such as  * 'mii-tool'.  * We now have 32 commands, so a bit more space ;-).  * Also, all 'odd' commands are only usable by root and don't return the  * content of ifr/iwr to user (but you are not obliged to use the set/get  * convention, just use every other two command). More details in iwpriv.c.  * And I repeat : you are not forced to use them with iwpriv, but you  * must be compliant with it.  */
end_comment

begin_comment
comment|/* ------------------------- IOCTL STUFF ------------------------- */
end_comment

begin_comment
comment|/* The first and the last (range) */
end_comment

begin_define
define|#
directive|define
name|SIOCIWFIRST
value|0x8B00
end_define

begin_define
define|#
directive|define
name|SIOCIWLAST
value|SIOCIWLASTPRIV
end_define

begin_comment
comment|/* 0x8BFF */
end_comment

begin_define
define|#
directive|define
name|IW_IOCTL_IDX
parameter_list|(
name|cmd
parameter_list|)
value|((cmd) - SIOCIWFIRST)
end_define

begin_comment
comment|/* Even : get (world access), odd : set (root access) */
end_comment

begin_define
define|#
directive|define
name|IW_IS_SET
parameter_list|(
name|cmd
parameter_list|)
value|(!((cmd)& 0x1))
end_define

begin_define
define|#
directive|define
name|IW_IS_GET
parameter_list|(
name|cmd
parameter_list|)
value|((cmd)& 0x1)
end_define

begin_comment
comment|/* ----------------------- WIRELESS EVENTS ----------------------- */
end_comment

begin_comment
comment|/* Those are *NOT* ioctls, do not issue request on them !!! */
end_comment

begin_comment
comment|/* Most events use the same identifier as ioctl requests */
end_comment

begin_define
define|#
directive|define
name|IWEVTXDROP
value|0x8C00
end_define

begin_comment
comment|/* Packet dropped to excessive retry */
end_comment

begin_define
define|#
directive|define
name|IWEVQUAL
value|0x8C01
end_define

begin_comment
comment|/* Quality part of statistics (scan) */
end_comment

begin_define
define|#
directive|define
name|IWEVCUSTOM
value|0x8C02
end_define

begin_comment
comment|/* Driver specific ascii string */
end_comment

begin_define
define|#
directive|define
name|IWEVREGISTERED
value|0x8C03
end_define

begin_comment
comment|/* Discovered a new node (AP mode) */
end_comment

begin_define
define|#
directive|define
name|IWEVEXPIRED
value|0x8C04
end_define

begin_comment
comment|/* Expired a node (AP mode) */
end_comment

begin_define
define|#
directive|define
name|IWEVGENIE
value|0x8C05
end_define

begin_comment
comment|/* Generic IE (WPA, RSN, WMM, ..) 					 * (scan results); This includes id and 					 * length fields. One IWEVGENIE may 					 * contain more than one IE. Scan 					 * results may contain one or more 					 * IWEVGENIE events. */
end_comment

begin_define
define|#
directive|define
name|IWEVMICHAELMICFAILURE
value|0x8C06
end_define

begin_comment
comment|/* Michael MIC failure 					 * (struct iw_michaelmicfailure) 					 */
end_comment

begin_define
define|#
directive|define
name|IWEVASSOCREQIE
value|0x8C07
end_define

begin_comment
comment|/* IEs used in (Re)Association Request. 					 * The data includes id and length 					 * fields and may contain more than one 					 * IE. This event is required in 					 * Managed mode if the driver 					 * generates its own WPA/RSN IE. This 					 * should be sent just before 					 * IWEVREGISTERED event for the 					 * association. */
end_comment

begin_define
define|#
directive|define
name|IWEVASSOCRESPIE
value|0x8C08
end_define

begin_comment
comment|/* IEs used in (Re)Association 					 * Response. The data includes id and 					 * length fields and may contain more 					 * than one IE. This may be sent 					 * between IWEVASSOCREQIE and 					 * IWEVREGISTERED events for the 					 * association. */
end_comment

begin_define
define|#
directive|define
name|IWEVPMKIDCAND
value|0x8C09
end_define

begin_comment
comment|/* PMKID candidate for RSN 					 * pre-authentication 					 * (struct iw_pmkid_cand) */
end_comment

begin_define
define|#
directive|define
name|IWEVFIRST
value|0x8C00
end_define

begin_define
define|#
directive|define
name|IW_EVENT_IDX
parameter_list|(
name|cmd
parameter_list|)
value|((cmd) - IWEVFIRST)
end_define

begin_comment
comment|/* ------------------------- PRIVATE INFO ------------------------- */
end_comment

begin_comment
comment|/*  * The following is used with SIOCGIWPRIV. It allow a driver to define  * the interface (name, type of data) for its private ioctl.  * Privates ioctl are SIOCIWFIRSTPRIV -> SIOCIWLASTPRIV  */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_MASK
value|0x7000
end_define

begin_comment
comment|/* Type of arguments */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_BYTE
value|0x1000
end_define

begin_comment
comment|/* Char as number */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_CHAR
value|0x2000
end_define

begin_comment
comment|/* Char as character */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_INT
value|0x4000
end_define

begin_comment
comment|/* 32 bits int */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_FLOAT
value|0x5000
end_define

begin_comment
comment|/* struct iw_freq */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_TYPE_ADDR
value|0x6000
end_define

begin_comment
comment|/* struct sockaddr */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_SIZE_FIXED
value|0x0800
end_define

begin_comment
comment|/* Variable or fixed number of args */
end_comment

begin_define
define|#
directive|define
name|IW_PRIV_SIZE_MASK
value|0x07FF
end_define

begin_comment
comment|/* Max number of those args */
end_comment

begin_comment
comment|/*  * Note : if the number of args is fixed and the size< 16 octets,  * instead of passing a pointer we will put args in the iwreq struct...  */
end_comment

begin_comment
comment|/* ----------------------- OTHER CONSTANTS ----------------------- */
end_comment

begin_comment
comment|/* Maximum frequencies in the range struct */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_FREQUENCIES
value|32
end_define

begin_comment
comment|/* Note : if you have something like 80 frequencies,  * don't increase this constant and don't fill the frequency list.  * The user will be able to set by channel anyway... */
end_comment

begin_comment
comment|/* Maximum bit rates in the range struct */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_BITRATES
value|32
end_define

begin_comment
comment|/* Maximum tx powers in the range struct */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_TXPOWER
value|8
end_define

begin_comment
comment|/* Note : if you more than 8 TXPowers, just set the max and min or  * a few of them in the struct iw_range. */
end_comment

begin_comment
comment|/* Maximum of address that you may set with SPY */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_SPY
value|8
end_define

begin_comment
comment|/* Maximum of address that you may get in the    list of access points in range */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_AP
value|64
end_define

begin_comment
comment|/* Maximum size of the ESSID and NICKN strings */
end_comment

begin_define
define|#
directive|define
name|IW_ESSID_MAX_SIZE
value|32
end_define

begin_comment
comment|/* Modes of operation */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_AUTO
value|0
end_define

begin_comment
comment|/* Let the driver decides */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_ADHOC
value|1
end_define

begin_comment
comment|/* Single cell network */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_INFRA
value|2
end_define

begin_comment
comment|/* Multi cell network, roaming, ... */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_MASTER
value|3
end_define

begin_comment
comment|/* Synchronisation master or Access Point */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_REPEAT
value|4
end_define

begin_comment
comment|/* Wireless Repeater (forwarder) */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_SECOND
value|5
end_define

begin_comment
comment|/* Secondary master/repeater (backup) */
end_comment

begin_define
define|#
directive|define
name|IW_MODE_MONITOR
value|6
end_define

begin_comment
comment|/* Passive monitor (listen only) */
end_comment

begin_comment
comment|/* Statistics flags (bitmask in updated) */
end_comment

begin_define
define|#
directive|define
name|IW_QUAL_QUAL_UPDATED
value|0x01
end_define

begin_comment
comment|/* Value was updated since last read */
end_comment

begin_define
define|#
directive|define
name|IW_QUAL_LEVEL_UPDATED
value|0x02
end_define

begin_define
define|#
directive|define
name|IW_QUAL_NOISE_UPDATED
value|0x04
end_define

begin_define
define|#
directive|define
name|IW_QUAL_ALL_UPDATED
value|0x07
end_define

begin_define
define|#
directive|define
name|IW_QUAL_DBM
value|0x08
end_define

begin_comment
comment|/* Level + Noise are dBm */
end_comment

begin_define
define|#
directive|define
name|IW_QUAL_QUAL_INVALID
value|0x10
end_define

begin_comment
comment|/* Driver doesn't provide value */
end_comment

begin_define
define|#
directive|define
name|IW_QUAL_LEVEL_INVALID
value|0x20
end_define

begin_define
define|#
directive|define
name|IW_QUAL_NOISE_INVALID
value|0x40
end_define

begin_define
define|#
directive|define
name|IW_QUAL_ALL_INVALID
value|0x70
end_define

begin_comment
comment|/* Frequency flags */
end_comment

begin_define
define|#
directive|define
name|IW_FREQ_AUTO
value|0x00
end_define

begin_comment
comment|/* Let the driver decides */
end_comment

begin_define
define|#
directive|define
name|IW_FREQ_FIXED
value|0x01
end_define

begin_comment
comment|/* Force a specific value */
end_comment

begin_comment
comment|/* Maximum number of size of encoding token available  * they are listed in the range structure */
end_comment

begin_define
define|#
directive|define
name|IW_MAX_ENCODING_SIZES
value|8
end_define

begin_comment
comment|/* Maximum size of the encoding token in bytes */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODING_TOKEN_MAX
value|64
end_define

begin_comment
comment|/* 512 bits (for now) */
end_comment

begin_comment
comment|/* Flags for encoding (along with the token) */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_INDEX
value|0x00FF
end_define

begin_comment
comment|/* Token index (if needed) */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_FLAGS
value|0xFF00
end_define

begin_comment
comment|/* Flags defined below */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_MODE
value|0xF000
end_define

begin_comment
comment|/* Modes defined below */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_DISABLED
value|0x8000
end_define

begin_comment
comment|/* Encoding disabled */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_ENABLED
value|0x0000
end_define

begin_comment
comment|/* Encoding enabled */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_RESTRICTED
value|0x4000
end_define

begin_comment
comment|/* Refuse non-encoded packets */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_OPEN
value|0x2000
end_define

begin_comment
comment|/* Accept non-encoded packets */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_NOKEY
value|0x0800
end_define

begin_comment
comment|/* Key is write only, so not present */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_TEMP
value|0x0400
end_define

begin_comment
comment|/* Temporary key */
end_comment

begin_comment
comment|/* Power management flags available (along with the value, if any) */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_ON
value|0x0000
end_define

begin_comment
comment|/* No details... */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_TYPE
value|0xF000
end_define

begin_comment
comment|/* Type of parameter */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_PERIOD
value|0x1000
end_define

begin_comment
comment|/* Value is a period/duration of  */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_TIMEOUT
value|0x2000
end_define

begin_comment
comment|/* Value is a timeout (to go asleep) */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_MODE
value|0x0F00
end_define

begin_comment
comment|/* Power Management mode */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_UNICAST_R
value|0x0100
end_define

begin_comment
comment|/* Receive only unicast messages */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_MULTICAST_R
value|0x0200
end_define

begin_comment
comment|/* Receive only multicast messages */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_ALL_R
value|0x0300
end_define

begin_comment
comment|/* Receive all messages though PM */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_FORCE_S
value|0x0400
end_define

begin_comment
comment|/* Force PM procedure for sending unicast */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_REPEATER
value|0x0800
end_define

begin_comment
comment|/* Repeat broadcast messages in PM period */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_MODIFIER
value|0x000F
end_define

begin_comment
comment|/* Modify a parameter */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_MIN
value|0x0001
end_define

begin_comment
comment|/* Value is a minimum  */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_MAX
value|0x0002
end_define

begin_comment
comment|/* Value is a maximum */
end_comment

begin_define
define|#
directive|define
name|IW_POWER_RELATIVE
value|0x0004
end_define

begin_comment
comment|/* Value is not in seconds/ms/us */
end_comment

begin_comment
comment|/* Transmit Power flags available */
end_comment

begin_define
define|#
directive|define
name|IW_TXPOW_TYPE
value|0x00FF
end_define

begin_comment
comment|/* Type of value */
end_comment

begin_define
define|#
directive|define
name|IW_TXPOW_DBM
value|0x0000
end_define

begin_comment
comment|/* Value is in dBm */
end_comment

begin_define
define|#
directive|define
name|IW_TXPOW_MWATT
value|0x0001
end_define

begin_comment
comment|/* Value is in mW */
end_comment

begin_define
define|#
directive|define
name|IW_TXPOW_RELATIVE
value|0x0002
end_define

begin_comment
comment|/* Value is in arbitrary units */
end_comment

begin_define
define|#
directive|define
name|IW_TXPOW_RANGE
value|0x1000
end_define

begin_comment
comment|/* Range of value between min/max */
end_comment

begin_comment
comment|/* Retry limits and lifetime flags available */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_ON
value|0x0000
end_define

begin_comment
comment|/* No details... */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_TYPE
value|0xF000
end_define

begin_comment
comment|/* Type of parameter */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_LIMIT
value|0x1000
end_define

begin_comment
comment|/* Maximum number of retries*/
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_LIFETIME
value|0x2000
end_define

begin_comment
comment|/* Maximum duration of retries in us */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_MODIFIER
value|0x000F
end_define

begin_comment
comment|/* Modify a parameter */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_MIN
value|0x0001
end_define

begin_comment
comment|/* Value is a minimum  */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_MAX
value|0x0002
end_define

begin_comment
comment|/* Value is a maximum */
end_comment

begin_define
define|#
directive|define
name|IW_RETRY_RELATIVE
value|0x0004
end_define

begin_comment
comment|/* Value is not in seconds/ms/us */
end_comment

begin_comment
comment|/* Scanning request flags */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_DEFAULT
value|0x0000
end_define

begin_comment
comment|/* Default scan of the driver */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_ALL_ESSID
value|0x0001
end_define

begin_comment
comment|/* Scan all ESSIDs */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_THIS_ESSID
value|0x0002
end_define

begin_comment
comment|/* Scan only this ESSID */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_ALL_FREQ
value|0x0004
end_define

begin_comment
comment|/* Scan all Frequencies */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_THIS_FREQ
value|0x0008
end_define

begin_comment
comment|/* Scan only this Frequency */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_ALL_MODE
value|0x0010
end_define

begin_comment
comment|/* Scan all Modes */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_THIS_MODE
value|0x0020
end_define

begin_comment
comment|/* Scan only this Mode */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_ALL_RATE
value|0x0040
end_define

begin_comment
comment|/* Scan all Bit-Rates */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_THIS_RATE
value|0x0080
end_define

begin_comment
comment|/* Scan only this Bit-Rate */
end_comment

begin_comment
comment|/* struct iw_scan_req scan_type */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_TYPE_ACTIVE
value|0
end_define

begin_define
define|#
directive|define
name|IW_SCAN_TYPE_PASSIVE
value|1
end_define

begin_comment
comment|/* Maximum size of returned data */
end_comment

begin_define
define|#
directive|define
name|IW_SCAN_MAX_DATA
value|4096
end_define

begin_comment
comment|/* In bytes */
end_comment

begin_comment
comment|/* Max number of char in custom event - use multiple of them if needed */
end_comment

begin_define
define|#
directive|define
name|IW_CUSTOM_MAX
value|256
end_define

begin_comment
comment|/* In bytes */
end_comment

begin_comment
comment|/* Generic information element */
end_comment

begin_define
define|#
directive|define
name|IW_GENERIC_IE_MAX
value|1024
end_define

begin_comment
comment|/* MLME requests (SIOCSIWMLME / struct iw_mlme) */
end_comment

begin_define
define|#
directive|define
name|IW_MLME_DEAUTH
value|0
end_define

begin_define
define|#
directive|define
name|IW_MLME_DISASSOC
value|1
end_define

begin_comment
comment|/* SIOCSIWAUTH/SIOCGIWAUTH struct iw_param flags */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_INDEX
value|0x0FFF
end_define

begin_define
define|#
directive|define
name|IW_AUTH_FLAGS
value|0xF000
end_define

begin_comment
comment|/* SIOCSIWAUTH/SIOCGIWAUTH parameters (0 .. 4095)  * (IW_AUTH_INDEX mask in struct iw_param flags; this is the index of the  * parameter that is being set/get to; value will be read/written to  * struct iw_param value field) */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_WPA_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_PAIRWISE
value|1
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_GROUP
value|2
end_define

begin_define
define|#
directive|define
name|IW_AUTH_KEY_MGMT
value|3
end_define

begin_define
define|#
directive|define
name|IW_AUTH_TKIP_COUNTERMEASURES
value|4
end_define

begin_define
define|#
directive|define
name|IW_AUTH_DROP_UNENCRYPTED
value|5
end_define

begin_define
define|#
directive|define
name|IW_AUTH_80211_AUTH_ALG
value|6
end_define

begin_define
define|#
directive|define
name|IW_AUTH_WPA_ENABLED
value|7
end_define

begin_define
define|#
directive|define
name|IW_AUTH_RX_UNENCRYPTED_EAPOL
value|8
end_define

begin_define
define|#
directive|define
name|IW_AUTH_ROAMING_CONTROL
value|9
end_define

begin_define
define|#
directive|define
name|IW_AUTH_PRIVACY_INVOKED
value|10
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_GROUP_MGMT
value|11
end_define

begin_define
define|#
directive|define
name|IW_AUTH_MFP
value|12
end_define

begin_comment
comment|/* IW_AUTH_WPA_VERSION values (bit field) */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_WPA_VERSION_DISABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IW_AUTH_WPA_VERSION_WPA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IW_AUTH_WPA_VERSION_WPA2
value|0x00000004
end_define

begin_comment
comment|/* IW_AUTH_PAIRWISE_CIPHER and IW_AUTH_GROUP_CIPHER values (bit field) */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_NONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_WEP40
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_TKIP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_CCMP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IW_AUTH_CIPHER_WEP104
value|0x00000010
end_define

begin_comment
comment|/* IW_AUTH_KEY_MGMT values (bit field) */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_KEY_MGMT_802_1X
value|1
end_define

begin_define
define|#
directive|define
name|IW_AUTH_KEY_MGMT_PSK
value|2
end_define

begin_comment
comment|/* IW_AUTH_80211_AUTH_ALG values (bit field) */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_ALG_OPEN_SYSTEM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IW_AUTH_ALG_SHARED_KEY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IW_AUTH_ALG_LEAP
value|0x00000004
end_define

begin_comment
comment|/* IW_AUTH_ROAMING_CONTROL values */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_ROAMING_ENABLE
value|0
end_define

begin_comment
comment|/* driver/firmware based roaming */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_ROAMING_DISABLE
value|1
end_define

begin_comment
comment|/* user space program used for roaming 					 * control */
end_comment

begin_comment
comment|/* IW_AUTH_MFP (management frame protection) values */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_MFP_DISABLED
value|0
end_define

begin_comment
comment|/* MFP disabled */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_MFP_OPTIONAL
value|1
end_define

begin_comment
comment|/* MFP optional */
end_comment

begin_define
define|#
directive|define
name|IW_AUTH_MFP_REQUIRED
value|2
end_define

begin_comment
comment|/* MFP required */
end_comment

begin_comment
comment|/* SIOCSIWENCODEEXT definitions */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_SEQ_MAX_SIZE
value|8
end_define

begin_comment
comment|/* struct iw_encode_ext ->alg */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_NONE
value|0
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_WEP
value|1
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_TKIP
value|2
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_CCMP
value|3
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_PMK
value|4
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_ALG_AES_CMAC
value|5
end_define

begin_comment
comment|/* struct iw_encode_ext ->ext_flags */
end_comment

begin_define
define|#
directive|define
name|IW_ENCODE_EXT_TX_SEQ_VALID
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_EXT_RX_SEQ_VALID
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_EXT_GROUP_KEY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IW_ENCODE_EXT_SET_TX_KEY
value|0x00000008
end_define

begin_comment
comment|/* IWEVMICHAELMICFAILURE : struct iw_michaelmicfailure ->flags */
end_comment

begin_define
define|#
directive|define
name|IW_MICFAILURE_KEY_ID
value|0x00000003
end_define

begin_comment
comment|/* Key ID 0..3 */
end_comment

begin_define
define|#
directive|define
name|IW_MICFAILURE_GROUP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IW_MICFAILURE_PAIRWISE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IW_MICFAILURE_STAKEY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IW_MICFAILURE_COUNT
value|0x00000060
end_define

begin_comment
comment|/* 1 or 2 (0 = count not supported) 					    */
end_comment

begin_comment
comment|/* Bit field values for enc_capa in struct iw_range */
end_comment

begin_define
define|#
directive|define
name|IW_ENC_CAPA_WPA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IW_ENC_CAPA_WPA2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IW_ENC_CAPA_CIPHER_TKIP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IW_ENC_CAPA_CIPHER_CCMP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IW_ENC_CAPA_4WAY_HANDSHAKE
value|0x00000010
end_define

begin_comment
comment|/* Event capability macros - in (struct iw_range *)->event_capa  * Because we have more than 32 possible events, we use an array of  * 32 bit bitmasks. Note : 32 bits = 0x20 = 2^5. */
end_comment

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_BASE
parameter_list|(
name|cmd
parameter_list|)
value|((cmd>= SIOCIWFIRSTPRIV) ? \ 					 (cmd - SIOCIWFIRSTPRIV + 0x60) : \ 					 (cmd - SIOCSIWCOMMIT))
end_define

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_INDEX
parameter_list|(
name|cmd
parameter_list|)
value|(IW_EVENT_CAPA_BASE(cmd)>> 5)
end_define

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_MASK
parameter_list|(
name|cmd
parameter_list|)
value|(1<< (IW_EVENT_CAPA_BASE(cmd)& 0x1F))
end_define

begin_comment
comment|/* Event capability constants - event autogenerated by the kernel  * This list is valid for most 802.11 devices, customise as needed... */
end_comment

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_K_0
value|(IW_EVENT_CAPA_MASK(0x8B04) | \ 				 IW_EVENT_CAPA_MASK(0x8B06) | \ 				 IW_EVENT_CAPA_MASK(0x8B1A))
end_define

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_K_1
value|(IW_EVENT_CAPA_MASK(0x8B2A))
end_define

begin_comment
comment|/* "Easy" macro to set events in iw_range (less efficient) */
end_comment

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_SET
parameter_list|(
name|event_capa
parameter_list|,
name|cmd
parameter_list|)
value|(event_capa[IW_EVENT_CAPA_INDEX(cmd)] |= IW_EVENT_CAPA_MASK(cmd))
end_define

begin_define
define|#
directive|define
name|IW_EVENT_CAPA_SET_KERNEL
parameter_list|(
name|event_capa
parameter_list|)
value|{event_capa[0] |= IW_EVENT_CAPA_K_0; event_capa[1] |= IW_EVENT_CAPA_K_1; }
end_define

begin_comment
comment|/****************************** TYPES ******************************/
end_comment

begin_comment
comment|/* --------------------------- SUBTYPES --------------------------- */
end_comment

begin_comment
comment|/*  *	Generic format for most parameters that fit in an int  */
end_comment

begin_struct
struct|struct
name|iw_param
block|{
name|__s32
name|value
decl_stmt|;
comment|/* The value of the parameter itself */
name|__u8
name|fixed
decl_stmt|;
comment|/* Hardware should not use auto select */
name|__u8
name|disabled
decl_stmt|;
comment|/* Disable the feature */
name|__u16
name|flags
decl_stmt|;
comment|/* Various specifc flags (if any) */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	For all data larger than 16 octets, we need to use a  *	pointer to memory allocated in user space.  */
end_comment

begin_struct
struct|struct
name|iw_point
block|{
name|void
name|__user
modifier|*
name|pointer
decl_stmt|;
comment|/* Pointer to the data  (in user space) */
name|__u16
name|length
decl_stmt|;
comment|/* number of fields or size in bytes */
name|__u16
name|flags
decl_stmt|;
comment|/* Optional params */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	A frequency  *	For numbers lower than 10^9, we encode the number in 'm' and  *	set 'e' to 0  *	For number greater than 10^9, we divide it by the lowest power  *	of 10 to get 'm' lower than 10^9, with 'm'= f / (10^'e')...  *	The power of 10 is in 'e', the result of the division is in 'm'.  */
end_comment

begin_struct
struct|struct
name|iw_freq
block|{
name|__s32
name|m
decl_stmt|;
comment|/* Mantissa */
name|__s16
name|e
decl_stmt|;
comment|/* Exponent */
name|__u8
name|i
decl_stmt|;
comment|/* List index (when in range struct) */
name|__u8
name|flags
decl_stmt|;
comment|/* Flags (fixed/auto) */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Quality of the link  */
end_comment

begin_struct
struct|struct
name|iw_quality
block|{
name|__u8
name|qual
decl_stmt|;
comment|/* link quality (%retries, SNR, 					   %missed beacons or better...) */
name|__u8
name|level
decl_stmt|;
comment|/* signal level (dBm) */
name|__u8
name|noise
decl_stmt|;
comment|/* noise level (dBm) */
name|__u8
name|updated
decl_stmt|;
comment|/* Flags to know if updated */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Packet discarded in the wireless adapter due to  *	"wireless" specific problems...  *	Note : the list of counter and statistics in net_device_stats  *	is already pretty exhaustive, and you should use that first.  *	This is only additional stats...  */
end_comment

begin_struct
struct|struct
name|iw_discarded
block|{
name|__u32
name|nwid
decl_stmt|;
comment|/* Rx : Wrong nwid/essid */
name|__u32
name|code
decl_stmt|;
comment|/* Rx : Unable to code/decode (WEP) */
name|__u32
name|fragment
decl_stmt|;
comment|/* Rx : Can't perform MAC reassembly */
name|__u32
name|retries
decl_stmt|;
comment|/* Tx : Max MAC retries num reached */
name|__u32
name|misc
decl_stmt|;
comment|/* Others cases */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Packet/Time period missed in the wireless adapter due to  *	"wireless" specific problems...  */
end_comment

begin_struct
struct|struct
name|iw_missed
block|{
name|__u32
name|beacon
decl_stmt|;
comment|/* Missed beacons/superframe */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Quality range (for spy threshold)  */
end_comment

begin_struct
struct|struct
name|iw_thrspy
block|{
name|struct
name|sockaddr
name|addr
decl_stmt|;
comment|/* Source address (hw/mac) */
name|struct
name|iw_quality
name|qual
decl_stmt|;
comment|/* Quality of the link */
name|struct
name|iw_quality
name|low
decl_stmt|;
comment|/* Low threshold */
name|struct
name|iw_quality
name|high
decl_stmt|;
comment|/* High threshold */
block|}
struct|;
end_struct

begin_comment
comment|/*  *	Optional data for scan request  *  *	Note: these optional parameters are controlling parameters for the  *	scanning behavior, these do not apply to getting scan results  *	(SIOCGIWSCAN). Drivers are expected to keep a local BSS table and  *	provide a merged results with all BSSes even if the previous scan  *	request limited scanning to a subset, e.g., by specifying an SSID.  *	Especially, scan results are required to include an entry for the  *	current BSS if the driver is in Managed mode and associated with an AP.  */
end_comment

begin_struct
struct|struct
name|iw_scan_req
block|{
name|__u8
name|scan_type
decl_stmt|;
comment|/* IW_SCAN_TYPE_{ACTIVE,PASSIVE} */
name|__u8
name|essid_len
decl_stmt|;
name|__u8
name|num_channels
decl_stmt|;
comment|/* num entries in channel_list; 				       * 0 = scan all allowed channels */
name|__u8
name|flags
decl_stmt|;
comment|/* reserved as padding; use zero, this may 				* be used in the future for adding flags 				* to request different scan behavior */
name|struct
name|sockaddr
name|bssid
decl_stmt|;
comment|/* ff:ff:ff:ff:ff:ff for broadcast BSSID or 				* individual address of a specific BSS */
comment|/* 	 * Use this ESSID if IW_SCAN_THIS_ESSID flag is used instead of using 	 * the current ESSID. This allows scan requests for specific ESSID 	 * without having to change the current ESSID and potentially breaking 	 * the current association. 	 */
name|__u8
name|essid
index|[
name|IW_ESSID_MAX_SIZE
index|]
decl_stmt|;
comment|/* 	 * Optional parameters for changing the default scanning behavior. 	 * These are based on the MLME-SCAN.request from IEEE Std 802.11. 	 * TU is 1.024 ms. If these are set to 0, driver is expected to use 	 * reasonable default values. min_channel_time defines the time that 	 * will be used to wait for the first reply on each channel. If no 	 * replies are received, next channel will be scanned after this. If 	 * replies are received, total time waited on the channel is defined by 	 * max_channel_time. 	 */
name|__u32
name|min_channel_time
decl_stmt|;
comment|/* in TU */
name|__u32
name|max_channel_time
decl_stmt|;
comment|/* in TU */
name|struct
name|iw_freq
name|channel_list
index|[
name|IW_MAX_FREQUENCIES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ------------------------- WPA SUPPORT ------------------------- */
end_comment

begin_comment
comment|/*  *	Extended data structure for get/set encoding (this is used with  *	SIOCSIWENCODEEXT/SIOCGIWENCODEEXT. struct iw_point and IW_ENCODE_*  *	flags are used in the same way as with SIOCSIWENCODE/SIOCGIWENCODE and  *	only the data contents changes (key data -> this structure, including  *	key data).  *  *	If the new key is the first group key, it will be set as the default  *	TX key. Otherwise, default TX key index is only changed if  *	IW_ENCODE_EXT_SET_TX_KEY flag is set.  *  *	Key will be changed with SIOCSIWENCODEEXT in all cases except for  *	special "change TX key index" operation which is indicated by setting  *	key_len = 0 and ext_flags |= IW_ENCODE_EXT_SET_TX_KEY.  *  *	tx_seq/rx_seq are only used when respective  *	IW_ENCODE_EXT_{TX,RX}_SEQ_VALID flag is set in ext_flags. Normal  *	TKIP/CCMP operation is to set RX seq with SIOCSIWENCODEEXT and start  *	TX seq from zero whenever key is changed. SIOCGIWENCODEEXT is normally  *	used only by an Authenticator (AP or an IBSS station) to get the  *	current TX sequence number. Using TX_SEQ_VALID for SIOCSIWENCODEEXT and  *	RX_SEQ_VALID for SIOCGIWENCODEEXT are optional, but can be useful for  *	debugging/testing.  */
end_comment

begin_struct
struct|struct
name|iw_encode_ext
block|{
name|__u32
name|ext_flags
decl_stmt|;
comment|/* IW_ENCODE_EXT_* */
name|__u8
name|tx_seq
index|[
name|IW_ENCODE_SEQ_MAX_SIZE
index|]
decl_stmt|;
comment|/* LSB first */
name|__u8
name|rx_seq
index|[
name|IW_ENCODE_SEQ_MAX_SIZE
index|]
decl_stmt|;
comment|/* LSB first */
name|struct
name|sockaddr
name|addr
decl_stmt|;
comment|/* ff:ff:ff:ff:ff:ff for broadcast/multicast 			       * (group) keys or unicast address for 			       * individual keys */
name|__u16
name|alg
decl_stmt|;
comment|/* IW_ENCODE_ALG_* */
name|__u16
name|key_len
decl_stmt|;
name|__u8
name|key
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SIOCSIWMLME data */
end_comment

begin_struct
struct|struct
name|iw_mlme
block|{
name|__u16
name|cmd
decl_stmt|;
comment|/* IW_MLME_* */
name|__u16
name|reason_code
decl_stmt|;
name|struct
name|sockaddr
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* SIOCSIWPMKSA data */
end_comment

begin_define
define|#
directive|define
name|IW_PMKSA_ADD
value|1
end_define

begin_define
define|#
directive|define
name|IW_PMKSA_REMOVE
value|2
end_define

begin_define
define|#
directive|define
name|IW_PMKSA_FLUSH
value|3
end_define

begin_define
define|#
directive|define
name|IW_PMKID_LEN
value|16
end_define

begin_struct
struct|struct
name|iw_pmksa
block|{
name|__u32
name|cmd
decl_stmt|;
comment|/* IW_PMKSA_* */
name|struct
name|sockaddr
name|bssid
decl_stmt|;
name|__u8
name|pmkid
index|[
name|IW_PMKID_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* IWEVMICHAELMICFAILURE data */
end_comment

begin_struct
struct|struct
name|iw_michaelmicfailure
block|{
name|__u32
name|flags
decl_stmt|;
name|struct
name|sockaddr
name|src_addr
decl_stmt|;
name|__u8
name|tsc
index|[
name|IW_ENCODE_SEQ_MAX_SIZE
index|]
decl_stmt|;
comment|/* LSB first */
block|}
struct|;
end_struct

begin_comment
comment|/* IWEVPMKIDCAND data */
end_comment

begin_define
define|#
directive|define
name|IW_PMKID_CAND_PREAUTH
value|0x00000001
end_define

begin_comment
comment|/* RNS pre-authentication enabled */
end_comment

begin_struct
struct|struct
name|iw_pmkid_cand
block|{
name|__u32
name|flags
decl_stmt|;
comment|/* IW_PMKID_CAND_* */
name|__u32
name|index
decl_stmt|;
comment|/* the smaller the index, the higher the 				* priority */
name|struct
name|sockaddr
name|bssid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ------------------------ WIRELESS STATS ------------------------ */
end_comment

begin_comment
comment|/*  * Wireless statistics (used for /proc/net/wireless)  */
end_comment

begin_struct
struct|struct
name|iw_statistics
block|{
name|__u16
name|status
decl_stmt|;
comment|/* Status 					 * - device dependent for now */
name|struct
name|iw_quality
name|qual
decl_stmt|;
comment|/* Quality of the link 						 * (instant/mean/max) */
name|struct
name|iw_discarded
name|discard
decl_stmt|;
comment|/* Packet discarded counts */
name|struct
name|iw_missed
name|miss
decl_stmt|;
comment|/* Packet missed counts */
block|}
struct|;
end_struct

begin_comment
comment|/* ------------------------ IOCTL REQUEST ------------------------ */
end_comment

begin_comment
comment|/*  * This structure defines the payload of an ioctl, and is used   * below.  *  * Note that this structure should fit on the memory footprint  * of iwreq (which is the same as ifreq), which mean a max size of  * 16 octets = 128 bits. Warning, pointers might be 64 bits wide...  * You should check this when increasing the structures defined  * above in this file...  */
end_comment

begin_union
union|union
name|iwreq_data
block|{
comment|/* Config - generic */
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Name : used to verify the presence of  wireless extensions. 	 * Name of the protocol/provider... */
name|struct
name|iw_point
name|essid
decl_stmt|;
comment|/* Extended network name */
name|struct
name|iw_param
name|nwid
decl_stmt|;
comment|/* network id (or domain - the cell) */
name|struct
name|iw_freq
name|freq
decl_stmt|;
comment|/* frequency or channel : 					 * 0-1000 = channel 					 *> 1000 = frequency in Hz */
name|struct
name|iw_param
name|sens
decl_stmt|;
comment|/* signal level threshold */
name|struct
name|iw_param
name|bitrate
decl_stmt|;
comment|/* default bit rate */
name|struct
name|iw_param
name|txpower
decl_stmt|;
comment|/* default transmit power */
name|struct
name|iw_param
name|rts
decl_stmt|;
comment|/* RTS threshold threshold */
name|struct
name|iw_param
name|frag
decl_stmt|;
comment|/* Fragmentation threshold */
name|__u32
name|mode
decl_stmt|;
comment|/* Operation mode */
name|struct
name|iw_param
name|retry
decl_stmt|;
comment|/* Retry limits& lifetime */
name|struct
name|iw_point
name|encoding
decl_stmt|;
comment|/* Encoding stuff : tokens */
name|struct
name|iw_param
name|power
decl_stmt|;
comment|/* PM duration/timeout */
name|struct
name|iw_quality
name|qual
decl_stmt|;
comment|/* Quality part of statistics */
name|struct
name|sockaddr
name|ap_addr
decl_stmt|;
comment|/* Access point address */
name|struct
name|sockaddr
name|addr
decl_stmt|;
comment|/* Destination address (hw/mac) */
name|struct
name|iw_param
name|param
decl_stmt|;
comment|/* Other small parameters */
name|struct
name|iw_point
name|data
decl_stmt|;
comment|/* Other large parameters */
block|}
union|;
end_union

begin_comment
comment|/*  * The structure to exchange data for ioctl.  * This structure is the same as 'struct ifreq', but (re)defined for  * convenience...  * Do I need to remind you about structure size (32 octets) ?  */
end_comment

begin_struct
struct|struct
name|iwreq
block|{
union|union
block|{
name|char
name|ifrn_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "eth0" */
block|}
name|ifr_ifrn
union|;
comment|/* Data part (defined just above) */
name|union
name|iwreq_data
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* -------------------------- IOCTL DATA -------------------------- */
end_comment

begin_comment
comment|/*  *	For those ioctl which want to exchange mode data that what could  *	fit in the above structure...  */
end_comment

begin_comment
comment|/*  *	Range of parameters  */
end_comment

begin_struct
struct|struct
name|iw_range
block|{
comment|/* Informative stuff (to choose between different interface) */
name|__u32
name|throughput
decl_stmt|;
comment|/* To give an idea... */
comment|/* In theory this value should be the maximum benchmarked 	 * TCP/IP throughput, because with most of these devices the 	 * bit rate is meaningless (overhead an co) to estimate how 	 * fast the connection will go and pick the fastest one. 	 * I suggest people to play with Netperf or any benchmark... 	 */
comment|/* NWID (or domain id) */
name|__u32
name|min_nwid
decl_stmt|;
comment|/* Minimal NWID we are able to set */
name|__u32
name|max_nwid
decl_stmt|;
comment|/* Maximal NWID we are able to set */
comment|/* Old Frequency (backward compat - moved lower ) */
name|__u16
name|old_num_channels
decl_stmt|;
name|__u8
name|old_num_frequency
decl_stmt|;
comment|/* Wireless event capability bitmasks */
name|__u32
name|event_capa
index|[
literal|6
index|]
decl_stmt|;
comment|/* signal level threshold range */
name|__s32
name|sensitivity
decl_stmt|;
comment|/* Quality of link& SNR stuff */
comment|/* Quality range (link, level, noise) 	 * If the quality is absolute, it will be in the range [0 ; max_qual], 	 * if the quality is dBm, it will be in the range [max_qual ; 0]. 	 * Don't forget that we use 8 bit arithmetics... */
name|struct
name|iw_quality
name|max_qual
decl_stmt|;
comment|/* Quality of the link */
comment|/* This should contain the average/typical values of the quality 	 * indicator. This should be the threshold between a "good" and 	 * a "bad" link (example : monitor going from green to orange). 	 * Currently, user space apps like quality monitors don't have any 	 * way to calibrate the measurement. With this, they can split 	 * the range between 0 and max_qual in different quality level 	 * (using a geometric subdivision centered on the average). 	 * I expect that people doing the user space apps will feedback 	 * us on which value we need to put in each driver... */
name|struct
name|iw_quality
name|avg_qual
decl_stmt|;
comment|/* Quality of the link */
comment|/* Rates */
name|__u8
name|num_bitrates
decl_stmt|;
comment|/* Number of entries in the list */
name|__s32
name|bitrate
index|[
name|IW_MAX_BITRATES
index|]
decl_stmt|;
comment|/* list, in bps */
comment|/* RTS threshold */
name|__s32
name|min_rts
decl_stmt|;
comment|/* Minimal RTS threshold */
name|__s32
name|max_rts
decl_stmt|;
comment|/* Maximal RTS threshold */
comment|/* Frag threshold */
name|__s32
name|min_frag
decl_stmt|;
comment|/* Minimal frag threshold */
name|__s32
name|max_frag
decl_stmt|;
comment|/* Maximal frag threshold */
comment|/* Power Management duration& timeout */
name|__s32
name|min_pmp
decl_stmt|;
comment|/* Minimal PM period */
name|__s32
name|max_pmp
decl_stmt|;
comment|/* Maximal PM period */
name|__s32
name|min_pmt
decl_stmt|;
comment|/* Minimal PM timeout */
name|__s32
name|max_pmt
decl_stmt|;
comment|/* Maximal PM timeout */
name|__u16
name|pmp_flags
decl_stmt|;
comment|/* How to decode max/min PM period */
name|__u16
name|pmt_flags
decl_stmt|;
comment|/* How to decode max/min PM timeout */
name|__u16
name|pm_capa
decl_stmt|;
comment|/* What PM options are supported */
comment|/* Encoder stuff */
name|__u16
name|encoding_size
index|[
name|IW_MAX_ENCODING_SIZES
index|]
decl_stmt|;
comment|/* Different token sizes */
name|__u8
name|num_encoding_sizes
decl_stmt|;
comment|/* Number of entry in the list */
name|__u8
name|max_encoding_tokens
decl_stmt|;
comment|/* Max number of tokens */
comment|/* For drivers that need a "login/passwd" form */
name|__u8
name|encoding_login_index
decl_stmt|;
comment|/* token index for login token */
comment|/* Transmit power */
name|__u16
name|txpower_capa
decl_stmt|;
comment|/* What options are supported */
name|__u8
name|num_txpower
decl_stmt|;
comment|/* Number of entries in the list */
name|__s32
name|txpower
index|[
name|IW_MAX_TXPOWER
index|]
decl_stmt|;
comment|/* list, in bps */
comment|/* Wireless Extension version info */
name|__u8
name|we_version_compiled
decl_stmt|;
comment|/* Must be WIRELESS_EXT */
name|__u8
name|we_version_source
decl_stmt|;
comment|/* Last update of source */
comment|/* Retry limits and lifetime */
name|__u16
name|retry_capa
decl_stmt|;
comment|/* What retry options are supported */
name|__u16
name|retry_flags
decl_stmt|;
comment|/* How to decode max/min retry limit */
name|__u16
name|r_time_flags
decl_stmt|;
comment|/* How to decode max/min retry life */
name|__s32
name|min_retry
decl_stmt|;
comment|/* Minimal number of retries */
name|__s32
name|max_retry
decl_stmt|;
comment|/* Maximal number of retries */
name|__s32
name|min_r_time
decl_stmt|;
comment|/* Minimal retry lifetime */
name|__s32
name|max_r_time
decl_stmt|;
comment|/* Maximal retry lifetime */
comment|/* Frequency */
name|__u16
name|num_channels
decl_stmt|;
comment|/* Number of channels [0; num - 1] */
name|__u8
name|num_frequency
decl_stmt|;
comment|/* Number of entry in the list */
name|struct
name|iw_freq
name|freq
index|[
name|IW_MAX_FREQUENCIES
index|]
decl_stmt|;
comment|/* list */
comment|/* Note : this frequency list doesn't need to fit channel numbers, 	 * because each entry contain its channel index */
name|__u32
name|enc_capa
decl_stmt|;
comment|/* IW_ENC_CAPA_* bit field */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Private ioctl interface information  */
end_comment

begin_struct
struct|struct
name|iw_priv_args
block|{
name|__u32
name|cmd
decl_stmt|;
comment|/* Number of the ioctl to issue */
name|__u16
name|set_args
decl_stmt|;
comment|/* Type and number of args */
name|__u16
name|get_args
decl_stmt|;
comment|/* Type and number of args */
name|char
name|name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Name of the extension */
block|}
struct|;
end_struct

begin_comment
comment|/* ----------------------- WIRELESS EVENTS ----------------------- */
end_comment

begin_comment
comment|/*  * Wireless events are carried through the rtnetlink socket to user  * space. They are encapsulated in the IFLA_WIRELESS field of  * a RTM_NEWLINK message.  */
end_comment

begin_comment
comment|/*  * A Wireless Event. Contains basically the same data as the ioctl...  */
end_comment

begin_struct
struct|struct
name|iw_event
block|{
name|__u16
name|len
decl_stmt|;
comment|/* Real lenght of this stuff */
name|__u16
name|cmd
decl_stmt|;
comment|/* Wireless IOCTL */
name|union
name|iwreq_data
name|u
decl_stmt|;
comment|/* IOCTL fixed payload */
block|}
struct|;
end_struct

begin_comment
comment|/* Size of the Event prefix (including padding and alignement junk) */
end_comment

begin_define
define|#
directive|define
name|IW_EV_LCP_LEN
value|(sizeof(struct iw_event) - sizeof(union iwreq_data))
end_define

begin_comment
comment|/* Size of the various events */
end_comment

begin_define
define|#
directive|define
name|IW_EV_CHAR_LEN
value|(IW_EV_LCP_LEN + IFNAMSIZ)
end_define

begin_define
define|#
directive|define
name|IW_EV_UINT_LEN
value|(IW_EV_LCP_LEN + sizeof(__u32))
end_define

begin_define
define|#
directive|define
name|IW_EV_FREQ_LEN
value|(IW_EV_LCP_LEN + sizeof(struct iw_freq))
end_define

begin_define
define|#
directive|define
name|IW_EV_PARAM_LEN
value|(IW_EV_LCP_LEN + sizeof(struct iw_param))
end_define

begin_define
define|#
directive|define
name|IW_EV_ADDR_LEN
value|(IW_EV_LCP_LEN + sizeof(struct sockaddr))
end_define

begin_define
define|#
directive|define
name|IW_EV_QUAL_LEN
value|(IW_EV_LCP_LEN + sizeof(struct iw_quality))
end_define

begin_comment
comment|/* iw_point events are special. First, the payload (extra data) come at  * the end of the event, so they are bigger than IW_EV_POINT_LEN. Second,  * we omit the pointer, so start at an offset. */
end_comment

begin_define
define|#
directive|define
name|IW_EV_POINT_OFF
value|(((char *)&(((struct iw_point *) NULL)->length)) - \ 			  (char *) NULL)
end_define

begin_define
define|#
directive|define
name|IW_EV_POINT_LEN
value|(IW_EV_LCP_LEN + sizeof(struct iw_point) - \ 			 IW_EV_POINT_OFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_WIRELESS_H */
end_comment

end_unit

