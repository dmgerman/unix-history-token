begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ports/winnt/include/gaa_compat.h  *  * This header allows systems without a recent-enough SDK to build NTP  * which can use GetAdaptersAddresses(), related functions and macros.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GAA_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|GAA_COMPAT_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_W64
end_ifdef

begin_include
include|#
directive|include
file|<iphlpapi.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_W64 follows */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_comment
comment|/* warning C4201: nonstandard extension used : nameless struct/union */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4201
name|)
end_pragma

begin_comment
comment|/* warning C4214: nonstandard extension used : bit field types other than int */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4214
name|)
end_pragma

begin_comment
comment|/* +++++++++++++++++++++++ from nldef.h */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// These values are from iptypes.h.
comment|// They need to fit in a 4 bit field.
comment|//
name|IpPrefixOriginOther
init|=
literal|0
block|,
name|IpPrefixOriginManual
block|,
name|IpPrefixOriginWellKnown
block|,
name|IpPrefixOriginDhcp
block|,
name|IpPrefixOriginRouterAdvertisement
block|,
name|IpPrefixOriginUnchanged
init|=
literal|1
operator|<<
literal|4
block|}
name|NL_PREFIX_ORIGIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// These values are from in iptypes.h.
comment|// They need to fit in a 4 bit field.
comment|//
name|IpSuffixOriginOther
init|=
literal|0
block|,
name|IpSuffixOriginManual
block|,
name|IpSuffixOriginWellKnown
block|,
name|IpSuffixOriginDhcp
block|,
name|IpSuffixOriginLinkLayerAddress
block|,
name|IpSuffixOriginRandom
block|,
name|IpSuffixOriginUnchanged
init|=
literal|1
operator|<<
literal|4
block|}
name|NL_SUFFIX_ORIGIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|//
comment|// These values are from in iptypes.h.
comment|//
name|IpDadStateInvalid
init|=
literal|0
block|,
name|IpDadStateTentative
block|,
name|IpDadStateDuplicate
block|,
name|IpDadStateDeprecated
block|,
name|IpDadStatePreferred
block|, }
name|NL_DAD_STATE
typedef|;
end_typedef

begin_comment
comment|/* +++++++++++++++++++++++ from nldef.h */
end_comment

begin_comment
comment|/* +++++++++++++++++++++++ from ifdef.h */
end_comment

begin_typedef
typedef|typedef
name|ULONG32
name|NET_IF_OBJECT_ID
typedef|,
modifier|*
name|PNET_IF_OBJECT_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_ADMIN_STATUS
comment|// ifAdminStatus
block|{
name|NET_IF_ADMIN_STATUS_UP
init|=
literal|1
block|,
name|NET_IF_ADMIN_STATUS_DOWN
init|=
literal|2
block|,
name|NET_IF_ADMIN_STATUS_TESTING
init|=
literal|3
block|}
name|NET_IF_ADMIN_STATUS
operator|,
typedef|*
name|PNET_IF_ADMIN_STATUS
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_OPER_STATUS
comment|// ifOperStatus
block|{
name|NET_IF_OPER_STATUS_UP
init|=
literal|1
block|,
name|NET_IF_OPER_STATUS_DOWN
init|=
literal|2
block|,
name|NET_IF_OPER_STATUS_TESTING
init|=
literal|3
block|,
name|NET_IF_OPER_STATUS_UNKNOWN
init|=
literal|4
block|,
name|NET_IF_OPER_STATUS_DORMANT
init|=
literal|5
block|,
name|NET_IF_OPER_STATUS_NOT_PRESENT
init|=
literal|6
block|,
name|NET_IF_OPER_STATUS_LOWER_LAYER_DOWN
init|=
literal|7
block|}
name|NET_IF_OPER_STATUS
operator|,
typedef|*
name|PNET_IF_OPER_STATUS
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags to extend operational status
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NET_IF_OPER_STATUS_DORMANT_PAUSED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NET_IF_OPER_STATUS_DORMANT_LOW_POWER
value|0x00000008
end_define

begin_typedef
typedef|typedef
name|UINT32
name|NET_IF_COMPARTMENT_ID
typedef|,
modifier|*
name|PNET_IF_COMPARTMENT_ID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define compartment ID type:
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NET_IF_COMPARTMENT_ID_UNSPECIFIED
value|(NET_IF_COMPARTMENT_ID)0
end_define

begin_define
define|#
directive|define
name|NET_IF_COMPARTMENT_ID_PRIMARY
value|(NET_IF_COMPARTMENT_ID)1
end_define

begin_define
define|#
directive|define
name|NET_IF_OID_IF_ALIAS
value|0x00000001
end_define

begin_comment
comment|// identifies the ifAlias string for an interface
end_comment

begin_define
define|#
directive|define
name|NET_IF_OID_COMPARTMENT_ID
value|0x00000002
end_define

begin_comment
comment|// identifies the compartment ID for an interface.
end_comment

begin_define
define|#
directive|define
name|NET_IF_OID_NETWORK_GUID
value|0x00000003
end_define

begin_comment
comment|// identifies the NetworkGuid for an interface.
end_comment

begin_define
define|#
directive|define
name|NET_IF_OID_IF_ENTRY
value|0x00000004
end_define

begin_comment
comment|// identifies statistics for an interface.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Define NetworkGUID type:
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|GUID
name|NET_IF_NETWORK_GUID
typedef|,
modifier|*
name|PNET_IF_NETWORK_GUID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define macros for an "unspecified" NetworkGUID value to be used in structures
end_comment

begin_comment
comment|// that haven't had the NET_LUID field filled in yet.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NET_SET_UNSPECIFIED_NETWORK_GUID
parameter_list|(
name|_pNetworkGuid
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NET_IS_UNSPECIFIED_NETWORK_GUID
parameter_list|(
name|_NetworkGuidValue
parameter_list|)
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// To prevent collisions between user-assigned and system-assigend site-ids,
end_comment

begin_comment
comment|// we partition the site-id space into two:
end_comment

begin_comment
comment|// 1. User-Assigned: NET_SITEID_UNSPECIFIED< SiteId< NET_SITEID_MAXUSER
end_comment

begin_comment
comment|// 2. System-Assigned: NET_SITEID_MAXUSER< SiteId< NET_SITEID_MAXSYSTEM
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: A network's SiteId doesn't really need to be settable.
end_comment

begin_comment
comment|// 1. The network profile manager creates a network per network profile.
end_comment

begin_comment
comment|// 2. NDIS/IF assigns a unique SiteId to each network.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NET_SITEID_UNSPECIFIED
value|(0)
end_define

begin_define
define|#
directive|define
name|NET_SITEID_MAXUSER
value|(0x07ffffff)
end_define

begin_define
define|#
directive|define
name|NET_SITEID_MAXSYSTEM
value|(0x0fffffff)
end_define

begin_expr_stmt
name|C_ASSERT
argument_list|(
name|NET_SITEID_MAXUSER
operator|<
name|NET_SITEID_MAXSYSTEM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_RCV_ADDRESS_TYPE
comment|// ifRcvAddressType
block|{
name|NET_IF_RCV_ADDRESS_TYPE_OTHER
init|=
literal|1
block|,
name|NET_IF_RCV_ADDRESS_TYPE_VOLATILE
init|=
literal|2
block|,
name|NET_IF_RCV_ADDRESS_TYPE_NON_VOLATILE
init|=
literal|3
block|}
name|NET_IF_RCV_ADDRESS_TYPE
operator|,
typedef|*
name|PNET_IF_RCV_ADDRESS_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NET_IF_RCV_ADDRESS_LH
block|{
name|NET_IF_RCV_ADDRESS_TYPE
name|ifRcvAddressType
decl_stmt|;
name|USHORT
name|ifRcvAddressLength
decl_stmt|;
name|USHORT
name|ifRcvAddressOffset
decl_stmt|;
comment|// from beginning of this struct
block|}
name|NET_IF_RCV_ADDRESS_LH
operator|,
typedef|*
name|PNET_IF_RCV_ADDRESS_LH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_NET_IF_ALIAS_LH
block|{
name|USHORT
name|ifAliasLength
decl_stmt|;
comment|// in bytes, of ifAlias string
name|USHORT
name|ifAliasOffset
decl_stmt|;
comment|// in bytes, from beginning of this struct
block|}
name|NET_IF_ALIAS_LH
operator|,
typedef|*
name|PNET_IF_ALIAS_LH
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4214
name|)
end_pragma

begin_comment
comment|// bit field types other than int
end_comment

begin_typedef
typedef|typedef
union|union
name|_NET_LUID_LH
block|{
name|ULONG64
name|Value
decl_stmt|;
struct|struct
block|{
name|ULONG64
name|Reserved
range|:
literal|24
decl_stmt|;
name|ULONG64
name|NetLuidIndex
range|:
literal|24
decl_stmt|;
name|ULONG64
name|IfType
range|:
literal|16
decl_stmt|;
comment|// equal to IANA IF type
block|}
name|Info
struct|;
block|}
name|NET_LUID_LH
operator|,
typedef|*
name|PNET_LUID_LH
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|NET_IF_RCV_ADDRESS_LH
name|NET_IF_RCV_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NET_IF_RCV_ADDRESS
modifier|*
name|PNET_IF_RCV_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NET_IF_ALIAS_LH
name|NET_IF_ALIAS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NET_IF_ALIAS
modifier|*
name|PNET_IF_ALIAS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//NTDDI_LONGHORN
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Need to make this visible on all platforms (for the purpose of IF_LUID).
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|NET_LUID_LH
name|NET_LUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NET_LUID
modifier|*
name|PNET_LUID
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// IF_LUID
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Define the locally unique datalink interface identifier type.
end_comment

begin_comment
comment|// This type is persistable.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|NET_LUID
name|IF_LUID
typedef|,
modifier|*
name|PIF_LUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|ULONG
name|NET_IFINDEX
typedef|,
modifier|*
name|PNET_IFINDEX
typedef|;
end_typedef

begin_comment
comment|// Interface Index (ifIndex)
end_comment

begin_typedef
typedef|typedef
name|UINT16
name|NET_IFTYPE
typedef|,
modifier|*
name|PNET_IFTYPE
typedef|;
end_typedef

begin_comment
comment|// Interface Type (IANA ifType)
end_comment

begin_define
define|#
directive|define
name|NET_IFINDEX_UNSPECIFIED
value|(NET_IFINDEX)(0)
end_define

begin_comment
comment|// Not a valid ifIndex
end_comment

begin_define
define|#
directive|define
name|NET_IFLUID_UNSPECIFIED
value|(0)
end_define

begin_comment
comment|// Not a valid if Luid
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for NET_IF_INFORMATION.Flags
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|NIIF_HARDWARE_INTERFACE
value|0x00000001
end_define

begin_comment
comment|// Set iff hardware
end_comment

begin_define
define|#
directive|define
name|NIIF_FILTER_INTERFACE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NIIF_NDIS_RESERVED1
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NIIF_NDIS_RESERVED2
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NIIF_NDIS_RESERVED3
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NIIF_NDIS_WDM_INTERFACE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NIIF_NDIS_ENDPOINT_INTERFACE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NIIF_WAN_TUNNEL_TYPE_UNKNOWN
value|((ULONG)(-1))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Define datalink interface access types.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_ACCESS_TYPE
block|{
name|NET_IF_ACCESS_LOOPBACK
init|=
literal|1
block|,
name|NET_IF_ACCESS_BROADCAST
init|=
literal|2
block|,
name|NET_IF_ACCESS_POINT_TO_POINT
init|=
literal|3
block|,
name|NET_IF_ACCESS_POINT_TO_MULTI_POINT
init|=
literal|4
block|,
name|NET_IF_ACCESS_MAXIMUM
init|=
literal|5
block|}
name|NET_IF_ACCESS_TYPE
operator|,
typedef|*
name|PNET_IF_ACCESS_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Define datalink interface direction types.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_DIRECTION_TYPE
block|{
name|NET_IF_DIRECTION_SENDRECEIVE
block|,
name|NET_IF_DIRECTION_SENDONLY
block|,
name|NET_IF_DIRECTION_RECEIVEONLY
block|,
name|NET_IF_DIRECTION_MAXIMUM
block|}
name|NET_IF_DIRECTION_TYPE
operator|,
typedef|*
name|PNET_IF_DIRECTION_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_CONNECTION_TYPE
block|{
name|NET_IF_CONNECTION_DEDICATED
init|=
literal|1
block|,
name|NET_IF_CONNECTION_PASSIVE
init|=
literal|2
block|,
name|NET_IF_CONNECTION_DEMAND
init|=
literal|3
block|,
name|NET_IF_CONNECTION_MAXIMUM
init|=
literal|4
block|}
name|NET_IF_CONNECTION_TYPE
operator|,
typedef|*
name|PNET_IF_CONNECTION_TYPE
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_MEDIA_CONNECT_STATE
block|{
name|MediaConnectStateUnknown
block|,
name|MediaConnectStateConnected
block|,
name|MediaConnectStateDisconnected
block|}
name|NET_IF_MEDIA_CONNECT_STATE
operator|,
typedef|*
name|PNET_IF_MEDIA_CONNECT_STATE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NET_IF_LINK_SPEED_UNKNOWN
value|((ULONG64)(-1))
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Defines the duplex state of media
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_NET_IF_MEDIA_DUPLEX_STATE
block|{
name|MediaDuplexStateUnknown
block|,
name|MediaDuplexStateHalf
block|,
name|MediaDuplexStateFull
block|}
name|NET_IF_MEDIA_DUPLEX_STATE
operator|,
typedef|*
name|PNET_IF_MEDIA_DUPLEX_STATE
typedef|;
end_typedef

begin_comment
comment|// Special values for fields in NET_PHYSICAL_LOCATION
end_comment

begin_define
define|#
directive|define
name|NIIF_BUS_NUMBER_UNKNOWN
value|((ULONG)(-1))
end_define

begin_define
define|#
directive|define
name|NIIF_SLOT_NUMBER_UNKNOWN
value|((ULONG)(-1))
end_define

begin_define
define|#
directive|define
name|NIIF_FUNCTION_NUMBER_UNKNOWN
value|((ULONG)(-1))
end_define

begin_typedef
typedef|typedef
struct|struct
name|_NET_PHYSICAL_LOCATION_LH
block|{
name|ULONG
name|BusNumber
decl_stmt|;
comment|// Physical location
name|ULONG
name|SlotNumber
decl_stmt|;
comment|// ... for hardware
name|ULONG
name|FunctionNumber
decl_stmt|;
comment|// ... devices.
block|}
name|NET_PHYSICAL_LOCATION_LH
operator|,
typedef|*
name|PNET_PHYSICAL_LOCATION_LH
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// maximum string size in -wchar- units
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IF_MAX_STRING_SIZE
value|256
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IF_COUNTED_STRING_LH
block|{
name|USHORT
name|Length
decl_stmt|;
comment|// in -Bytes-
name|WCHAR
name|String
index|[
name|IF_MAX_STRING_SIZE
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|IF_COUNTED_STRING_LH
operator|,
typedef|*
name|PIF_COUNTED_STRING_LH
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IF_MAX_PHYS_ADDRESS_LENGTH
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IF_PHYSICAL_ADDRESS_LH
block|{
name|USHORT
name|Length
decl_stmt|;
name|UCHAR
name|Address
index|[
name|IF_MAX_PHYS_ADDRESS_LENGTH
index|]
decl_stmt|;
block|}
name|IF_PHYSICAL_ADDRESS_LH
operator|,
typedef|*
name|PIF_PHYSICAL_ADDRESS_LH
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|NET_PHYSICAL_LOCATION_LH
name|NET_PHYSICAL_LOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NET_PHYSICAL_LOCATION
modifier|*
name|PNET_PHYSICAL_LOCATION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IF_COUNTED_STRING_LH
name|IF_COUNTED_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IF_COUNTED_STRING
modifier|*
name|PIF_COUNTED_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IF_PHYSICAL_ADDRESS_LH
name|IF_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IF_PHYSICAL_ADDRESS
modifier|*
name|PIF_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// IF_INDEX
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Define the interface index type.
end_comment

begin_comment
comment|// This type is not persistable.
end_comment

begin_comment
comment|// This must be unsigned (not an enum) to replace previous uses of
end_comment

begin_comment
comment|// an index that used a DWORD type.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|NET_IFINDEX
name|IF_INDEX
typedef|,
modifier|*
name|PIF_INDEX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IFI_UNSPECIFIED
value|NET_IFINDEX_UNSPECIFIED
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Get definitions for IFTYPE and IF_ACCESS_TYPE.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<ipifcons.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Types of tunnels (sub-type of IF_TYPE when IF_TYPE is IF_TYPE_TUNNEL).
end_comment

begin_comment
comment|// See http://www.iana.org/assignments/ianaiftype-mib.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|TUNNEL_TYPE_NONE
init|=
literal|0
block|,
name|TUNNEL_TYPE_OTHER
init|=
literal|1
block|,
name|TUNNEL_TYPE_DIRECT
init|=
literal|2
block|,
name|TUNNEL_TYPE_6TO4
init|=
literal|11
block|,
name|TUNNEL_TYPE_ISATAP
init|=
literal|13
block|,
name|TUNNEL_TYPE_TEREDO
init|=
literal|14
block|, }
name|TUNNEL_TYPE
operator|,
typedef|*
name|PTUNNEL_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// IF_ADMINISTRATIVE_STATE
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Datalink Interface Administrative State.
end_comment

begin_comment
comment|// Indicates whether the interface has been administratively enabled.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_IF_ADMINISTRATIVE_STATE
block|{
name|IF_ADMINISTRATIVE_DISABLED
block|,
name|IF_ADMINISTRATIVE_ENABLED
block|,
name|IF_ADMINISTRATIVE_DEMANDDIAL
block|, }
name|IF_ADMINISTRATIVE_STATE
operator|,
typedef|*
name|PIF_ADMINISTRATIVE_STATE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: Interface is Operational iff
end_comment

begin_comment
comment|// ((MediaSense is Connected) and (AdministrativeState is Enabled))
end_comment

begin_comment
comment|// or
end_comment

begin_comment
comment|// ((MediaSense is Connected) and (AdministrativeState is OnDemand))
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// !Operational iff
end_comment

begin_comment
comment|// ((MediaSense != Connected) or (AdministrativeState is Disabled))
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// OperStatus values from RFC 2863
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|IfOperStatusUp
init|=
literal|1
block|,
name|IfOperStatusDown
block|,
name|IfOperStatusTesting
block|,
name|IfOperStatusUnknown
block|,
name|IfOperStatusDormant
block|,
name|IfOperStatusNotPresent
block|,
name|IfOperStatusLowerLayerDown
block|}
name|IF_OPER_STATUS
typedef|;
end_typedef

begin_comment
comment|/* +++++++++++++++++++++++ from ifdef.h */
end_comment

begin_comment
comment|/* +++++++++++++++++++++++ from iptypes.h */
end_comment

begin_comment
comment|// Definitions and structures used by getnetworkparams and getadaptersinfo apis
end_comment

begin_define
define|#
directive|define
name|MAX_ADAPTER_DESCRIPTION_LENGTH
value|128
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_ADAPTER_NAME_LENGTH
value|256
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_ADAPTER_ADDRESS_LENGTH
value|8
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MINIMUM_ENTITIES
value|32
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_HOSTNAME_LEN
value|128
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_DOMAIN_NAME_LEN
value|128
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_SCOPE_ID_LEN
value|256
end_define

begin_comment
comment|// arb.
end_comment

begin_define
define|#
directive|define
name|MAX_DHCPV6_DUID_LENGTH
value|130
end_define

begin_comment
comment|// RFC 3315.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// types
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Node Type
end_comment

begin_define
define|#
directive|define
name|BROADCAST_NODETYPE
value|1
end_define

begin_define
define|#
directive|define
name|PEER_TO_PEER_NODETYPE
value|2
end_define

begin_define
define|#
directive|define
name|MIXED_NODETYPE
value|4
end_define

begin_define
define|#
directive|define
name|HYBRID_NODETYPE
value|8
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// IP_ADDRESS_STRING - store an IP address as a dotted decimal string
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|String
index|[
literal|4
operator|*
literal|4
index|]
decl_stmt|;
block|}
name|IP_ADDRESS_STRING
operator|,
typedef|*
name|PIP_ADDRESS_STRING
operator|,
name|IP_MASK_STRING
operator|,
typedef|*
name|PIP_MASK_STRING
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// IP_ADDR_STRING - store an IP address with its corresponding subnet mask,
end_comment

begin_comment
comment|// both as dotted decimal strings
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADDR_STRING
block|{
name|struct
name|_IP_ADDR_STRING
modifier|*
name|Next
decl_stmt|;
name|IP_ADDRESS_STRING
name|IpAddress
decl_stmt|;
name|IP_MASK_STRING
name|IpMask
decl_stmt|;
name|DWORD
name|Context
decl_stmt|;
block|}
name|IP_ADDR_STRING
operator|,
typedef|*
name|PIP_ADDR_STRING
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// ADAPTER_INFO - per-adapter information. All IP addresses are stored as
end_comment

begin_comment
comment|// strings
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_INFO
block|{
name|struct
name|_IP_ADAPTER_INFO
modifier|*
name|Next
decl_stmt|;
name|DWORD
name|ComboIndex
decl_stmt|;
name|char
name|AdapterName
index|[
name|MAX_ADAPTER_NAME_LENGTH
operator|+
literal|4
index|]
decl_stmt|;
name|char
name|Description
index|[
name|MAX_ADAPTER_DESCRIPTION_LENGTH
operator|+
literal|4
index|]
decl_stmt|;
name|UINT
name|AddressLength
decl_stmt|;
name|BYTE
name|Address
index|[
name|MAX_ADAPTER_ADDRESS_LENGTH
index|]
decl_stmt|;
name|DWORD
name|Index
decl_stmt|;
name|UINT
name|Type
decl_stmt|;
name|UINT
name|DhcpEnabled
decl_stmt|;
name|PIP_ADDR_STRING
name|CurrentIpAddress
decl_stmt|;
name|IP_ADDR_STRING
name|IpAddressList
decl_stmt|;
name|IP_ADDR_STRING
name|GatewayList
decl_stmt|;
name|IP_ADDR_STRING
name|DhcpServer
decl_stmt|;
name|BOOL
name|HaveWins
decl_stmt|;
name|IP_ADDR_STRING
name|PrimaryWinsServer
decl_stmt|;
name|IP_ADDR_STRING
name|SecondaryWinsServer
decl_stmt|;
name|time_t
name|LeaseObtained
decl_stmt|;
name|time_t
name|LeaseExpires
decl_stmt|;
block|}
name|IP_ADAPTER_INFO
operator|,
typedef|*
name|PIP_ADAPTER_INFO
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_WINSOCK2API_
end_ifdef

begin_comment
comment|//
end_comment

begin_comment
comment|// The following types require Winsock2.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|NL_PREFIX_ORIGIN
name|IP_PREFIX_ORIGIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NL_SUFFIX_ORIGIN
name|IP_SUFFIX_ORIGIN
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|NL_DAD_STATE
name|IP_DAD_STATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_UNICAST_ADDRESS_LH
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_UNICAST_ADDRESS_LH
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
name|IP_PREFIX_ORIGIN
name|PrefixOrigin
decl_stmt|;
name|IP_SUFFIX_ORIGIN
name|SuffixOrigin
decl_stmt|;
name|IP_DAD_STATE
name|DadState
decl_stmt|;
name|ULONG
name|ValidLifetime
decl_stmt|;
name|ULONG
name|PreferredLifetime
decl_stmt|;
name|ULONG
name|LeaseLifetime
decl_stmt|;
name|UINT8
name|OnLinkPrefixLength
decl_stmt|;
block|}
name|IP_ADAPTER_UNICAST_ADDRESS_LH
operator|,
typedef|*
name|PIP_ADAPTER_UNICAST_ADDRESS_LH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_UNICAST_ADDRESS_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_UNICAST_ADDRESS_XP
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
name|IP_PREFIX_ORIGIN
name|PrefixOrigin
decl_stmt|;
name|IP_SUFFIX_ORIGIN
name|SuffixOrigin
decl_stmt|;
name|IP_DAD_STATE
name|DadState
decl_stmt|;
name|ULONG
name|ValidLifetime
decl_stmt|;
name|ULONG
name|PreferredLifetime
decl_stmt|;
name|ULONG
name|LeaseLifetime
decl_stmt|;
block|}
name|IP_ADAPTER_UNICAST_ADDRESS_XP
operator|,
typedef|*
name|PIP_ADAPTER_UNICAST_ADDRESS_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_UNICAST_ADDRESS_LH
name|IP_ADAPTER_UNICAST_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_UNICAST_ADDRESS_LH
modifier|*
name|PIP_ADAPTER_UNICAST_ADDRESS
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_elif

begin_typedef
typedef|typedef
name|IP_ADAPTER_UNICAST_ADDRESS_XP
name|IP_ADAPTER_UNICAST_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_UNICAST_ADDRESS_XP
modifier|*
name|PIP_ADAPTER_UNICAST_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit values of IP_ADAPTER_UNICAST_ADDRESS Flags field.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IP_ADAPTER_ADDRESS_DNS_ELIGIBLE
value|0x01
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_ADDRESS_TRANSIENT
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_ANYCAST_ADDRESS_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_ANYCAST_ADDRESS_XP
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
block|}
name|IP_ADAPTER_ANYCAST_ADDRESS_XP
operator|,
typedef|*
name|PIP_ADAPTER_ANYCAST_ADDRESS_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_ANYCAST_ADDRESS_XP
name|IP_ADAPTER_ANYCAST_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_ANYCAST_ADDRESS_XP
modifier|*
name|PIP_ADAPTER_ANYCAST_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_MULTICAST_ADDRESS_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_MULTICAST_ADDRESS_XP
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
block|}
name|IP_ADAPTER_MULTICAST_ADDRESS_XP
operator|,
typedef|*
name|PIP_ADAPTER_MULTICAST_ADDRESS_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_MULTICAST_ADDRESS_XP
name|IP_ADAPTER_MULTICAST_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_MULTICAST_ADDRESS_XP
modifier|*
name|PIP_ADAPTER_MULTICAST_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_DNS_SERVER_ADDRESS_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Reserved
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_DNS_SERVER_ADDRESS_XP
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
block|}
name|IP_ADAPTER_DNS_SERVER_ADDRESS_XP
operator|,
typedef|*
name|PIP_ADAPTER_DNS_SERVER_ADDRESS_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_DNS_SERVER_ADDRESS_XP
name|IP_ADAPTER_DNS_SERVER_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_DNS_SERVER_ADDRESS_XP
modifier|*
name|PIP_ADAPTER_DNS_SERVER_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_WINS_SERVER_ADDRESS_LH
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Reserved
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_WINS_SERVER_ADDRESS_LH
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
block|}
name|IP_ADAPTER_WINS_SERVER_ADDRESS_LH
operator|,
typedef|*
name|PIP_ADAPTER_WINS_SERVER_ADDRESS_LH
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_WINS_SERVER_ADDRESS_LH
name|IP_ADAPTER_WINS_SERVER_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_WINS_SERVER_ADDRESS_LH
modifier|*
name|PIP_ADAPTER_WINS_SERVER_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_GATEWAY_ADDRESS_LH
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Reserved
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_GATEWAY_ADDRESS_LH
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
block|}
name|IP_ADAPTER_GATEWAY_ADDRESS_LH
operator|,
typedef|*
name|PIP_ADAPTER_GATEWAY_ADDRESS_LH
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_GATEWAY_ADDRESS_LH
name|IP_ADAPTER_GATEWAY_ADDRESS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_GATEWAY_ADDRESS_LH
modifier|*
name|PIP_ADAPTER_GATEWAY_ADDRESS
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_PREFIX_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_PREFIX_XP
modifier|*
name|Next
decl_stmt|;
name|SOCKET_ADDRESS
name|Address
decl_stmt|;
name|ULONG
name|PrefixLength
decl_stmt|;
block|}
name|IP_ADAPTER_PREFIX_XP
operator|,
typedef|*
name|PIP_ADAPTER_PREFIX_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_PREFIX_XP
name|IP_ADAPTER_PREFIX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_PREFIX_XP
modifier|*
name|PIP_ADAPTER_PREFIX
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Bit values of IP_ADAPTER_ADDRESSES Flags field.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|IP_ADAPTER_DDNS_ENABLED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_REGISTER_ADAPTER_SUFFIX
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_DHCP_ENABLED
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_RECEIVE_ONLY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_NO_MULTICAST
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_IPV4_ENABLED
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IP_ADAPTER_IPV6_ENABLED
value|0x00000100
end_define

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_ADDRESSES_LH
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|IF_INDEX
name|IfIndex
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_ADDRESSES_LH
modifier|*
name|Next
decl_stmt|;
name|PCHAR
name|AdapterName
decl_stmt|;
name|PIP_ADAPTER_UNICAST_ADDRESS_LH
name|FirstUnicastAddress
decl_stmt|;
name|PIP_ADAPTER_ANYCAST_ADDRESS_XP
name|FirstAnycastAddress
decl_stmt|;
name|PIP_ADAPTER_MULTICAST_ADDRESS_XP
name|FirstMulticastAddress
decl_stmt|;
name|PIP_ADAPTER_DNS_SERVER_ADDRESS_XP
name|FirstDnsServerAddress
decl_stmt|;
name|PWCHAR
name|DnsSuffix
decl_stmt|;
name|PWCHAR
name|Description
decl_stmt|;
name|PWCHAR
name|FriendlyName
decl_stmt|;
name|BYTE
name|PhysicalAddress
index|[
name|MAX_ADAPTER_ADDRESS_LENGTH
index|]
decl_stmt|;
name|ULONG
name|PhysicalAddressLength
decl_stmt|;
union|union
block|{
name|ULONG
name|Flags
decl_stmt|;
struct|struct
block|{
name|ULONG
name|DdnsEnabled
range|:
literal|1
decl_stmt|;
name|ULONG
name|RegisterAdapterSuffix
range|:
literal|1
decl_stmt|;
name|ULONG
name|Dhcpv4Enabled
range|:
literal|1
decl_stmt|;
name|ULONG
name|ReceiveOnly
range|:
literal|1
decl_stmt|;
name|ULONG
name|NoMulticast
range|:
literal|1
decl_stmt|;
name|ULONG
name|Ipv6OtherStatefulConfig
range|:
literal|1
decl_stmt|;
name|ULONG
name|NetbiosOverTcpipEnabled
range|:
literal|1
decl_stmt|;
name|ULONG
name|Ipv4Enabled
range|:
literal|1
decl_stmt|;
name|ULONG
name|Ipv6Enabled
range|:
literal|1
decl_stmt|;
name|ULONG
name|Ipv6ManagedAddressConfigurationSupported
range|:
literal|1
decl_stmt|;
block|}
struct|;
block|}
union|;
name|ULONG
name|Mtu
decl_stmt|;
name|IFTYPE
name|IfType
decl_stmt|;
name|IF_OPER_STATUS
name|OperStatus
decl_stmt|;
name|IF_INDEX
name|Ipv6IfIndex
decl_stmt|;
name|ULONG
name|ZoneIndices
index|[
literal|16
index|]
decl_stmt|;
name|PIP_ADAPTER_PREFIX_XP
name|FirstPrefix
decl_stmt|;
name|ULONG64
name|TransmitLinkSpeed
decl_stmt|;
name|ULONG64
name|ReceiveLinkSpeed
decl_stmt|;
name|PIP_ADAPTER_WINS_SERVER_ADDRESS_LH
name|FirstWinsServerAddress
decl_stmt|;
name|PIP_ADAPTER_GATEWAY_ADDRESS_LH
name|FirstGatewayAddress
decl_stmt|;
name|ULONG
name|Ipv4Metric
decl_stmt|;
name|ULONG
name|Ipv6Metric
decl_stmt|;
name|IF_LUID
name|Luid
decl_stmt|;
name|SOCKET_ADDRESS
name|Dhcpv4Server
decl_stmt|;
name|NET_IF_COMPARTMENT_ID
name|CompartmentId
decl_stmt|;
name|NET_IF_NETWORK_GUID
name|NetworkGuid
decl_stmt|;
name|NET_IF_CONNECTION_TYPE
name|ConnectionType
decl_stmt|;
name|TUNNEL_TYPE
name|TunnelType
decl_stmt|;
comment|//
comment|// DHCP v6 Info.
comment|//
name|SOCKET_ADDRESS
name|Dhcpv6Server
decl_stmt|;
name|BYTE
name|Dhcpv6ClientDuid
index|[
name|MAX_DHCPV6_DUID_LENGTH
index|]
decl_stmt|;
name|ULONG
name|Dhcpv6ClientDuidLength
decl_stmt|;
name|ULONG
name|Dhcpv6Iaid
decl_stmt|;
block|}
name|IP_ADAPTER_ADDRESSES_LH
operator|,
typedef|*
name|PIP_ADAPTER_ADDRESSES_LH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_IP_ADAPTER_ADDRESSES_XP
block|{
union|union
block|{
name|ULONGLONG
name|Alignment
decl_stmt|;
struct|struct
block|{
name|ULONG
name|Length
decl_stmt|;
name|DWORD
name|IfIndex
decl_stmt|;
block|}
struct|;
block|}
union|;
name|struct
name|_IP_ADAPTER_ADDRESSES_XP
modifier|*
name|Next
decl_stmt|;
name|PCHAR
name|AdapterName
decl_stmt|;
name|PIP_ADAPTER_UNICAST_ADDRESS_XP
name|FirstUnicastAddress
decl_stmt|;
name|PIP_ADAPTER_ANYCAST_ADDRESS_XP
name|FirstAnycastAddress
decl_stmt|;
name|PIP_ADAPTER_MULTICAST_ADDRESS_XP
name|FirstMulticastAddress
decl_stmt|;
name|PIP_ADAPTER_DNS_SERVER_ADDRESS_XP
name|FirstDnsServerAddress
decl_stmt|;
name|PWCHAR
name|DnsSuffix
decl_stmt|;
name|PWCHAR
name|Description
decl_stmt|;
name|PWCHAR
name|FriendlyName
decl_stmt|;
name|BYTE
name|PhysicalAddress
index|[
name|MAX_ADAPTER_ADDRESS_LENGTH
index|]
decl_stmt|;
name|DWORD
name|PhysicalAddressLength
decl_stmt|;
name|DWORD
name|Flags
decl_stmt|;
name|DWORD
name|Mtu
decl_stmt|;
name|DWORD
name|IfType
decl_stmt|;
name|IF_OPER_STATUS
name|OperStatus
decl_stmt|;
name|DWORD
name|Ipv6IfIndex
decl_stmt|;
name|DWORD
name|ZoneIndices
index|[
literal|16
index|]
decl_stmt|;
name|PIP_ADAPTER_PREFIX_XP
name|FirstPrefix
decl_stmt|;
block|}
name|IP_ADAPTER_ADDRESSES_XP
operator|,
typedef|*
name|PIP_ADAPTER_ADDRESSES_XP
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_LONGHORN
operator|)
end_if

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_LH
name|IP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_LH
modifier|*
name|PIP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
operator|(
name|NTDDI_VERSION
operator|>=
name|NTDDI_WINXP
operator|)
end_elif

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_XP
name|IP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_XP
modifier|*
name|PIP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|//
end_comment

begin_comment
comment|// For platforms other platforms that are including
end_comment

begin_comment
comment|// the file but not using the types.
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_XP
name|IP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|IP_ADAPTER_ADDRESSES_XP
modifier|*
name|PIP_ADAPTER_ADDRESSES
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags used as argument to GetAdaptersAddresses().
end_comment

begin_comment
comment|// "SKIP" flags are added when the default is to include the information.
end_comment

begin_comment
comment|// "INCLUDE" flags are added when the default is to skip the information.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|GAA_FLAG_SKIP_UNICAST
value|0x0001
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_SKIP_ANYCAST
value|0x0002
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_SKIP_MULTICAST
value|0x0004
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_SKIP_DNS_SERVER
value|0x0008
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_PREFIX
value|0x0010
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_SKIP_FRIENDLY_NAME
value|0x0020
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_WINS_INFO
value|0x0040
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_GATEWAYS
value|0x0080
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_ALL_INTERFACES
value|0x0100
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_ALL_COMPARTMENTS
value|0x0200
end_define

begin_define
define|#
directive|define
name|GAA_FLAG_INCLUDE_TUNNEL_BINDINGORDER
value|0x0400
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WINSOCK2API_ */
end_comment

begin_comment
comment|/* +++++++++++++++++++++++ from iptypes.h */
end_comment

begin_comment
comment|/* +++++++++++++++++++++++ from iphlpapi.h */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_WINSOCK2API_
end_ifdef

begin_comment
comment|//
end_comment

begin_comment
comment|// The following functions require Winsock2.
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|ULONG
name|WINAPI
name|GetAdaptersAddresses
argument_list|(
name|IN
name|ULONG
name|Family
argument_list|,
name|IN
name|ULONG
name|Flags
argument_list|,
name|IN
name|PVOID
name|Reserved
argument_list|,
name|__out_bcount_opt
argument_list|(
argument|*SizePointer
argument_list|)
name|PIP_ADAPTER_ADDRESSES
name|AdapterAddresses
argument_list|,
name|IN
name|OUT
name|PULONG
name|SizePointer
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* +++++++++++++++++++++++ from iphlpapi.h */
end_comment

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_W64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GAA_COMPAT_H */
end_comment

end_unit

