begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* generated file, don't edit - use ./genfiles */
end_comment

begin_function_decl
name|int
name|op_interfaces
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifNumber
value|1
end_define

begin_function_decl
name|int
name|op_ifentry
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifIndex
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ifDescr
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ifType
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ifMtu
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_ifSpeed
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_ifPhysAddress
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_ifAdminStatus
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_ifOperStatus
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_ifLastChange
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_ifInOctets
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_ifInUcastPkts
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_ifInNUcastPkts
value|12
end_define

begin_define
define|#
directive|define
name|LEAF_ifInDiscards
value|13
end_define

begin_define
define|#
directive|define
name|LEAF_ifInErrors
value|14
end_define

begin_define
define|#
directive|define
name|LEAF_ifInUnknownProtos
value|15
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutOctets
value|16
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutUcastPkts
value|17
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutNUcastPkts
value|18
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutDiscards
value|19
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutErrors
value|20
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutQLen
value|21
end_define

begin_define
define|#
directive|define
name|LEAF_ifSpecific
value|22
end_define

begin_function_decl
name|int
name|op_ip
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipForwarding
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ipDefaultTTL
value|2
end_define

begin_function_decl
name|int
name|op_ipstat
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipInReceives
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ipInHdrErrors
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_ipInAddrErrors
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_ipForwDatagrams
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_ipInUnknownProtos
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_ipInDiscards
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_ipInDelivers
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_ipOutRequests
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_ipOutDiscards
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_ipOutNoRoutes
value|12
end_define

begin_define
define|#
directive|define
name|LEAF_ipReasmTimeout
value|13
end_define

begin_define
define|#
directive|define
name|LEAF_ipReasmReqds
value|14
end_define

begin_define
define|#
directive|define
name|LEAF_ipReasmOKs
value|15
end_define

begin_define
define|#
directive|define
name|LEAF_ipReasmFails
value|16
end_define

begin_define
define|#
directive|define
name|LEAF_ipFragOKs
value|17
end_define

begin_define
define|#
directive|define
name|LEAF_ipFragFails
value|18
end_define

begin_define
define|#
directive|define
name|LEAF_ipFragCreates
value|19
end_define

begin_function_decl
name|int
name|op_ipaddr
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipAdEntAddr
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ipAdEntIfIndex
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ipAdEntNetMask
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ipAdEntBcastAddr
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_ipAdEntReasmMaxSize
value|5
end_define

begin_function_decl
name|int
name|op_nettomedia
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipNetToMediaIfIndex
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ipNetToMediaPhysAddress
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ipNetToMediaNetAddress
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ipNetToMediaType
value|4
end_define

begin_function_decl
name|int
name|op_route
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteNumber
value|3
end_define

begin_function_decl
name|int
name|op_route_table
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteDest
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMask
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteTos
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteNextHop
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteIfIndex
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteType
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteProto
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteAge
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteInfo
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteNextHopAS
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMetric1
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMetric2
value|12
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMetric3
value|13
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMetric4
value|14
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteMetric5
value|15
end_define

begin_define
define|#
directive|define
name|LEAF_ipCidrRouteStatus
value|16
end_define

begin_function_decl
name|int
name|op_icmpstat
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_icmpInMsgs
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInErrors
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInDestUnreachs
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInTimeExcds
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInParmProbs
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInSrcQuenchs
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInRedirects
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInEchos
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInEchoReps
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInTimestamps
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInTimestampReps
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInAddrMasks
value|12
end_define

begin_define
define|#
directive|define
name|LEAF_icmpInAddrMaskReps
value|13
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutMsgs
value|14
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutErrors
value|15
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutDestUnreachs
value|16
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutTimeExcds
value|17
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutParmProbs
value|18
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutSrcQuenchs
value|19
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutRedirects
value|20
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutEchos
value|21
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutEchoReps
value|22
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutTimestamps
value|23
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutTimestampReps
value|24
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutAddrMasks
value|25
end_define

begin_define
define|#
directive|define
name|LEAF_icmpOutAddrMaskReps
value|26
end_define

begin_function_decl
name|int
name|op_tcp
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_tcpRtoAlgorithm
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_tcpRtoMin
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_tcpRtoMax
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_tcpMaxConn
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_tcpActiveOpens
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_tcpPassiveOpens
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_tcpAttemptFails
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_tcpEstabResets
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_tcpCurrEstab
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_tcpInSegs
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_tcpOutSegs
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_tcpRetransSegs
value|12
end_define

begin_function_decl
name|int
name|op_tcpconn
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_tcpConnState
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_tcpConnLocalAddress
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_tcpConnLocalPort
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_tcpConnRemAddress
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_tcpConnRemPort
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_tcpInErrs
value|14
end_define

begin_function_decl
name|int
name|op_udp
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_udpInDatagrams
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_udpNoPorts
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_udpInErrors
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_udpOutDatagrams
value|4
end_define

begin_function_decl
name|int
name|op_udptable
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_udpLocalAddress
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_udpLocalPort
value|2
end_define

begin_function_decl
name|int
name|op_ifxtable
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifName
value|1
end_define

begin_define
define|#
directive|define
name|LEAF_ifInMulticastPkts
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ifInBroadcastPkts
value|3
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutMulticastPkts
value|4
end_define

begin_define
define|#
directive|define
name|LEAF_ifOutBroadcastPkts
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCInOctets
value|6
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCInUcastPkts
value|7
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCInMulticastPkts
value|8
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCInBroadcastPkts
value|9
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCOutOctets
value|10
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCOutUcastPkts
value|11
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCOutMulticastPkts
value|12
end_define

begin_define
define|#
directive|define
name|LEAF_ifHCOutBroadcastPkts
value|13
end_define

begin_define
define|#
directive|define
name|LEAF_ifLinkUpDownTrapEnable
value|14
end_define

begin_define
define|#
directive|define
name|LEAF_ifHighSpeed
value|15
end_define

begin_define
define|#
directive|define
name|LEAF_ifPromiscuousMode
value|16
end_define

begin_define
define|#
directive|define
name|LEAF_ifConnectorPresent
value|17
end_define

begin_define
define|#
directive|define
name|LEAF_ifAlias
value|18
end_define

begin_define
define|#
directive|define
name|LEAF_ifCounterDiscontinuityTime
value|19
end_define

begin_function_decl
name|int
name|op_ifstack
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifStackStatus
value|3
end_define

begin_function_decl
name|int
name|op_rcvaddr
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifRcvAddressStatus
value|2
end_define

begin_define
define|#
directive|define
name|LEAF_ifRcvAddressType
value|3
end_define

begin_function_decl
name|int
name|op_ifmib
parameter_list|(
name|struct
name|snmp_context
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|enum
name|snmp_op
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LEAF_ifTableLastChange
value|5
end_define

begin_define
define|#
directive|define
name|LEAF_ifStackLastChange
value|6
end_define

begin_define
define|#
directive|define
name|mibII_CTREE_SIZE
value|142
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|snmp_node
name|mibII_ctree
index|[]
decl_stmt|;
end_decl_stmt

end_unit

