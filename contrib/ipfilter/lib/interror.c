begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * $Id: interror.c,v 1.9.2.12 2012/07/22 08:03:39 darren_r Exp $  */
end_comment

begin_include
include|#
directive|include
file|"ipf.h"
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|iee_number
decl_stmt|;
name|char
modifier|*
name|iee_text
decl_stmt|;
block|}
name|ipf_error_entry_t
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|ipf_error_entry_t
modifier|*
name|find_error
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPF_NUM_ERRORS
value|475
end_define

begin_comment
comment|/*  * NO REUSE OF NUMBERS!  *  * IF YOU WANT TO ADD AN ERROR TO THIS TABLE, _ADD_ A NEW NUMBER.  * DO _NOT_ USE AN EMPTY NUMBER OR FILL IN A GAP.  */
end_comment

begin_decl_stmt
specifier|static
name|ipf_error_entry_t
name|ipf_errors
index|[
name|IPF_NUM_ERRORS
index|]
init|=
block|{
block|{
literal|1
block|,
literal|"auth table locked/full"
block|}
block|,
block|{
literal|2
block|,
literal|""
block|}
block|,
block|{
literal|3
block|,
literal|"copyinptr received bad address"
block|}
block|,
block|{
literal|4
block|,
literal|"copyoutptr received bad address"
block|}
block|,
block|{
literal|5
block|,
literal|""
block|}
block|,
block|{
literal|6
block|,
literal|"cannot load a rule with FR_T_BUILTIN flag set"
block|}
block|,
block|{
literal|7
block|,
literal|"internal rule without FR_T_BUILDINT flag set"
block|}
block|,
block|{
literal|8
block|,
literal|"no data provided with filter rule"
block|}
block|,
block|{
literal|9
block|,
literal|"invalid ioctl for rule"
block|}
block|,
block|{
literal|10
block|,
literal|"rule protocol is not 4 or 6"
block|}
block|,
block|{
literal|11
block|,
literal|"cannot find rule function"
block|}
block|,
block|{
literal|12
block|,
literal|"cannot find rule group"
block|}
block|,
block|{
literal|13
block|,
literal|"group in/out does not match rule in/out"
block|}
block|,
block|{
literal|14
block|,
literal|"rule without in/out does not belong to a group"
block|}
block|,
block|{
literal|15
block|,
literal|"cannot determine where to append rule"
block|}
block|,
block|{
literal|16
block|,
literal|"malloc for rule data failed"
block|}
block|,
block|{
literal|17
block|,
literal|"copyin for rule data failed"
block|}
block|,
block|{
literal|18
block|,
literal|""
block|}
block|,
block|{
literal|19
block|,
literal|"zero data size for BPF rule"
block|}
block|,
block|{
literal|20
block|,
literal|"BPF validation failed"
block|}
block|,
block|{
literal|21
block|,
literal|"incorrect data size for IPF rule"
block|}
block|,
block|{
literal|22
block|,
literal|"'keep state' rule included 'with oow'"
block|}
block|,
block|{
literal|23
block|,
literal|"bad interface index with dynamic source address"
block|}
block|,
block|{
literal|24
block|,
literal|"bad interface index with dynamic dest. address"
block|}
block|,
block|{
literal|25
block|,
literal|"match array verif failed for filter rule"
block|}
block|,
block|{
literal|26
block|,
literal|"bad filter rule type"
block|}
block|,
block|{
literal|27
block|,
literal|"rule not found for zero'stats"
block|}
block|,
block|{
literal|28
block|,
literal|"copyout failed for zero'ing stats"
block|}
block|,
block|{
literal|29
block|,
literal|"rule not found for removing"
block|}
block|,
block|{
literal|30
block|,
literal|"cannot remove internal rule"
block|}
block|,
block|{
literal|31
block|,
literal|"rule in use"
block|}
block|,
block|{
literal|32
block|,
literal|"rule already exists"
block|}
block|,
block|{
literal|33
block|,
literal|"no memory for another rule"
block|}
block|,
block|{
literal|34
block|,
literal|"could not find function"
block|}
block|,
block|{
literal|35
block|,
literal|"copyout failed for resolving function name -> addr"
block|}
block|,
block|{
literal|36
block|,
literal|"copyout failed for resolving function addr -> name"
block|}
block|,
block|{
literal|37
block|,
literal|"function name/addr resolving search failed"
block|}
block|,
block|{
literal|38
block|,
literal|"group map cannot find it's hash table"
block|}
block|,
block|{
literal|39
block|,
literal|"group map hash-table in/out do not match rule"
block|}
block|,
block|{
literal|40
block|,
literal|"bcopyout failed for SIOCIPFINTERROR"
block|}
block|,
block|{
literal|41
block|,
literal|""
block|}
block|,
block|{
literal|42
block|,
literal|"ipfilter not enabled for NAT ioctl"
block|}
block|,
block|{
literal|43
block|,
literal|"ipfilter not enabled for state ioctl"
block|}
block|,
block|{
literal|44
block|,
literal|"ipfilter not enabled for auth ioctl"
block|}
block|,
block|{
literal|45
block|,
literal|"ipfilter not enbaled for sync ioctl"
block|}
block|,
block|{
literal|46
block|,
literal|"ipfilter not enabled for scan ioctl"
block|}
block|,
block|{
literal|47
block|,
literal|"ipfilter not enabled for lookup ioctl"
block|}
block|,
block|{
literal|48
block|,
literal|"unrecognised device minor number for ioctl"
block|}
block|,
block|{
literal|49
block|,
literal|"unrecognised object type for copying in ipfobj"
block|}
block|,
block|{
literal|50
block|,
literal|"mismatching object type for copying in ipfobj"
block|}
block|,
block|{
literal|51
block|,
literal|"object size too small for copying in ipfobj"
block|}
block|,
block|{
literal|52
block|,
literal|"object size mismatch for copying in ipfobj"
block|}
block|,
block|{
literal|53
block|,
literal|"compat object size too small for copying in ipfobj"
block|}
block|,
block|{
literal|54
block|,
literal|"compat object size mismatch for copying in ipfobj"
block|}
block|,
block|{
literal|55
block|,
literal|"error doing copyin of data for in ipfobj"
block|}
block|,
block|{
literal|56
block|,
literal|"unrecognised object type for size copy in ipfobj"
block|}
block|,
block|{
literal|57
block|,
literal|"object size too small for size copy in ipfobj"
block|}
block|,
block|{
literal|58
block|,
literal|"mismatching object type for size copy in ipfobj"
block|}
block|,
block|{
literal|59
block|,
literal|"object size mismatch for size copy in ipfobj"
block|}
block|,
block|{
literal|60
block|,
literal|"compat object size mismatch for size copy in ipfobj"
block|}
block|,
block|{
literal|61
block|,
literal|"error doing size copyin of data for in ipfobj"
block|}
block|,
block|{
literal|62
block|,
literal|"bad object type for size copy out ipfobj"
block|}
block|,
block|{
literal|63
block|,
literal|"mismatching object type for size copy out ipfobj"
block|}
block|,
block|{
literal|64
block|,
literal|"object size mismatch for size copy out ipfobj"
block|}
block|,
block|{
literal|65
block|,
literal|"compat object size wrong for size copy out ipfobj"
block|}
block|,
block|{
literal|66
block|,
literal|"error doing size copyout of data for out ipfobj"
block|}
block|,
block|{
literal|67
block|,
literal|"unrecognised object type for copying out ipfobj"
block|}
block|,
block|{
literal|68
block|,
literal|"mismatching object type for copying out ipfobj"
block|}
block|,
block|{
literal|69
block|,
literal|"object size too small for copying out ipfobj"
block|}
block|,
block|{
literal|70
block|,
literal|"object size mismatch for copying out ipfobj"
block|}
block|,
block|{
literal|71
block|,
literal|"compat object size too small for copying out ipfobj"
block|}
block|,
block|{
literal|72
block|,
literal|"compat object size mismatch for copying out ipfobj"
block|}
block|,
block|{
literal|73
block|,
literal|"error doing copyout of data for out ipfobj"
block|}
block|,
block|{
literal|74
block|,
literal|"attempt to add existing tunable name"
block|}
block|,
block|{
literal|75
block|,
literal|"cannot find tunable name to delete"
block|}
block|,
block|{
literal|76
block|,
literal|"internal data too big for next tunable"
block|}
block|,
block|{
literal|77
block|,
literal|"could not find tunable"
block|}
block|,
block|{
literal|78
block|,
literal|"tunable can only be changed when ipfilter disabled"
block|}
block|,
block|{
literal|79
block|,
literal|"new tunable value outside accepted range"
block|}
block|,
block|{
literal|80
block|,
literal|"ipftune called for unrecognised ioctl"
block|}
block|,
block|{
literal|81
block|,
literal|""
block|}
block|,
block|{
literal|82
block|,
literal|"could not find token to delete"
block|}
block|,
block|{
literal|83
block|,
literal|""
block|}
block|,
block|{
literal|84
block|,
literal|"attempt to get next rule when no more exist"
block|}
block|,
block|{
literal|85
block|,
literal|"value for iri_inout outside accepted range"
block|}
block|,
block|{
literal|86
block|,
literal|"value for iri_active outside accepted range"
block|}
block|,
block|{
literal|87
block|,
literal|"value for iri_nrules is 0"
block|}
block|,
block|{
literal|88
block|,
literal|"NULL pointer specified for where to copy rule to"
block|}
block|,
block|{
literal|89
block|,
literal|"copyout of rule failed"
block|}
block|,
block|{
literal|90
block|,
literal|""
block|}
block|,
block|{
literal|91
block|,
literal|"could not get token for rule iteration"
block|}
block|,
block|{
literal|92
block|,
literal|"unrecognised generic iterator"
block|}
block|,
block|{
literal|93
block|,
literal|"could not find token for generic iterator"
block|}
block|,
block|{
literal|94
block|,
literal|"need write permissions to disable/enable ipfilter"
block|}
block|,
block|{
literal|95
block|,
literal|"error copying in enable/disable value"
block|}
block|,
block|{
literal|96
block|,
literal|"need write permissions to set ipf tunable"
block|}
block|,
block|{
literal|97
block|,
literal|"need write permissions to set ipf flags"
block|}
block|,
block|{
literal|98
block|,
literal|"error doing copyin of ipf flags"
block|}
block|,
block|{
literal|99
block|,
literal|"error doing copyout of ipf flags"
block|}
block|,
block|{
literal|100
block|,
literal|"need write permissions to add another rule"
block|}
block|,
block|{
literal|101
block|,
literal|"need write permissions to insert another rule"
block|}
block|,
block|{
literal|102
block|,
literal|"need write permissions to swap active rule set"
block|}
block|,
block|{
literal|103
block|,
literal|"error copying out current active rule set"
block|}
block|,
block|{
literal|104
block|,
literal|"need write permissions to zero ipf stats"
block|}
block|,
block|{
literal|105
block|,
literal|"need write permissions to flush ipf v4 rules"
block|}
block|,
block|{
literal|106
block|,
literal|"error copying out v4 flush results"
block|}
block|,
block|{
literal|107
block|,
literal|"error copying in v4 flush command"
block|}
block|,
block|{
literal|108
block|,
literal|"need write permissions to flush ipf v6 rules"
block|}
block|,
block|{
literal|109
block|,
literal|"error copying out v6 flush results"
block|}
block|,
block|{
literal|110
block|,
literal|"error copying in v6 flush command"
block|}
block|,
block|{
literal|111
block|,
literal|"error copying in new lock state for ipfilter"
block|}
block|,
block|{
literal|112
block|,
literal|"need write permissions to flush ipf logs"
block|}
block|,
block|{
literal|113
block|,
literal|"error copying out results of log flush"
block|}
block|,
block|{
literal|114
block|,
literal|"need write permissions to resync ipf"
block|}
block|,
block|{
literal|115
block|,
literal|"unrecognised ipf ioctl"
block|}
block|,
block|{
literal|116
block|,
literal|"error copying in match array"
block|}
block|,
block|{
literal|117
block|,
literal|"match array type is not IPFOBJ_IPFEXPR"
block|}
block|,
block|{
literal|118
block|,
literal|"bad size for match array"
block|}
block|,
block|{
literal|119
block|,
literal|"cannot allocate memory for match aray"
block|}
block|,
block|{
literal|120
block|,
literal|"error copying in match array"
block|}
block|,
block|{
literal|121
block|,
literal|"error verifying contents of match array"
block|}
block|,
block|{
literal|122
block|,
literal|"need write permissions to set ipf lock status"
block|}
block|,
block|{
literal|123
block|,
literal|"error copying in data for function resolution"
block|}
block|,
block|{
literal|124
block|,
literal|"error copying in ipfobj structure"
block|}
block|,
block|{
literal|125
block|,
literal|"error copying in ipfobj structure"
block|}
block|,
block|{
literal|126
block|,
literal|"error copying in ipfobj structure"
block|}
block|,
block|{
literal|127
block|,
literal|"error copying in ipfobj structure"
block|}
block|,
block|{
literal|128
block|,
literal|"no memory for filter rule comment"
block|}
block|,
block|{
literal|129
block|,
literal|"error copying in filter rule comment"
block|}
block|,
block|{
literal|130
block|,
literal|"error copying out filter rule comment"
block|}
block|,
block|{
literal|131
block|,
literal|"no memory for new rule alloc buffer"
block|}
block|,
block|{
literal|132
block|,
literal|"cannot find source lookup pool"
block|}
block|,
block|{
literal|133
block|,
literal|"unknown source address type"
block|}
block|,
block|{
literal|134
block|,
literal|"cannot find destination lookup pool"
block|}
block|,
block|{
literal|135
block|,
literal|"unknown destination address type"
block|}
block|,
block|{
literal|136
block|,
literal|"icmp head group name index incorrect"
block|}
block|,
block|{
literal|137
block|,
literal|"group head name index incorrect"
block|}
block|,
block|{
literal|138
block|,
literal|"group name index incorrect"
block|}
block|,
block|{
literal|139
block|,
literal|"to interface name index incorrect"
block|}
block|,
block|{
literal|140
block|,
literal|"dup-to interface name index incorrect"
block|}
block|,
block|{
literal|141
block|,
literal|"reply-to interface name index incorrect"
block|}
block|,
block|{
literal|142
block|,
literal|"could not initialise call now function"
block|}
block|,
block|{
literal|143
block|,
literal|"could not initialise call function"
block|}
block|,
block|{
literal|144
block|,
literal|"could not find destination list"
block|}
block|,
block|{
literal|145
block|,
literal|"auth rules cannot have dup/to/fastroute"
block|}
block|,
block|{
literal|146
block|,
literal|"incorrect size for object to copy out"
block|}
block|,
block|{
literal|147
block|,
literal|"object type out of bounds for kernel copyout"
block|}
block|,
block|{
literal|148
block|,
literal|"object size too small for kernel copyout"
block|}
block|,
block|{
literal|149
block|,
literal|"object size validation failed for kernel copyout"
block|}
block|,
block|{
literal|150
block|,
literal|"error copying data out for kernel copyout"
block|}
block|,
block|{
literal|151
block|,
literal|"version mismatch for kernel copyout"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|10001
block|,
literal|"could not find token for auth iterator"
block|}
block|,
block|{
literal|10002
block|,
literal|"write permissions require to add/remove auth rule"
block|}
block|,
block|{
literal|10003
block|,
literal|"need write permissions to set auth lock"
block|}
block|,
block|{
literal|10004
block|,
literal|"error copying out results of auth flush"
block|}
block|,
block|{
literal|10005
block|,
literal|"unknown auth ioctl"
block|}
block|,
block|{
literal|10006
block|,
literal|"can only append or remove preauth rules"
block|}
block|,
block|{
literal|10007
block|,
literal|"NULL pointers passed in for preauth remove"
block|}
block|,
block|{
literal|10008
block|,
literal|"preauth rule not found to remove"
block|}
block|,
block|{
literal|10009
block|,
literal|"could not malloc memory for preauth entry"
block|}
block|,
block|{
literal|10010
block|,
literal|"unrecognised preauth rule ioctl command"
block|}
block|,
block|{
literal|10011
block|,
literal|"iterator data supplied with NULL pointer"
block|}
block|,
block|{
literal|10012
block|,
literal|"unknown auth iterator type"
block|}
block|,
block|{
literal|10013
block|,
literal|"iterator error copying out auth data"
block|}
block|,
block|{
literal|10014
block|,
literal|"sleep waiting for auth packet interrupted"
block|}
block|,
block|{
literal|10015
block|,
literal|"bad index supplied in auth reply"
block|}
block|,
block|{
literal|10016
block|,
literal|"error injecting outbound packet back into kernel"
block|}
block|,
block|{
literal|10017
block|,
literal|"error injecting inbound packet back into kernel"
block|}
block|,
block|{
literal|10018
block|,
literal|"could not attempt to inject packet back into kernel"
block|}
block|,
block|{
literal|10019
block|,
literal|"packet id does not match"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|20001
block|,
literal|"invalid frag token data pointer supplied"
block|}
block|,
block|{
literal|20002
block|,
literal|"error copying out frag token data"
block|}
block|,
block|{
literal|20003
block|,
literal|"can only copy one fragment state entry at a time"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|30001
block|,
literal|"incorrect object size to get hash table stats"
block|}
block|,
block|{
literal|30002
block|,
literal|"could not malloc memory for new hash table"
block|}
block|,
block|{
literal|30003
block|,
literal|"error coping in hash table structure"
block|}
block|,
block|{
literal|30004
block|,
literal|"hash table already exists"
block|}
block|,
block|{
literal|30005
block|,
literal|"mismach between new hash table and operation unit"
block|}
block|,
block|{
literal|30006
block|,
literal|"could not malloc memory for hash table base"
block|}
block|,
block|{
literal|30007
block|,
literal|"could not find hash table"
block|}
block|,
block|{
literal|30008
block|,
literal|"mismatch between hash table and operation unit"
block|}
block|,
block|{
literal|30009
block|,
literal|"could not find hash table for iterators next node"
block|}
block|,
block|{
literal|30010
block|,
literal|"unknown iterator tpe"
block|}
block|,
block|{
literal|30011
block|,
literal|"iterator error copying out hash table"
block|}
block|,
block|{
literal|30012
block|,
literal|"iterator error copying out hash table entry"
block|}
block|,
block|{
literal|30013
block|,
literal|"error copying out hash table statistics"
block|}
block|,
block|{
literal|30014
block|,
literal|"table node delete structure wrong size"
block|}
block|,
block|{
literal|30015
block|,
literal|"error copying in node to delete"
block|}
block|,
block|{
literal|30016
block|,
literal|"table to delete node from does not exist"
block|}
block|,
block|{
literal|30017
block|,
literal|"could not find table to remove node from"
block|}
block|,
block|{
literal|30018
block|,
literal|"table node add structure wrong size"
block|}
block|,
block|{
literal|30019
block|,
literal|"error copying in node to add"
block|}
block|,
block|{
literal|30020
block|,
literal|"could not find table to add node to"
block|}
block|,
block|{
literal|30021
block|,
literal|"node already exists in the table"
block|}
block|,
block|{
literal|30022
block|,
literal|"could not find node to delete in table"
block|}
block|,
block|{
literal|30023
block|,
literal|"uid mismatch on node to delete"
block|}
block|,
block|{
literal|30024
block|,
literal|"object size incorrect for hash table"
block|}
block|,
block|{
literal|30025
block|,
literal|"hash table size must be at least 1"
block|}
block|,
block|{
literal|30026
block|,
literal|"cannot allocate memory for hash table context"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|40001
block|,
literal|"invalid minor device numebr for log read"
block|}
block|,
block|{
literal|40002
block|,
literal|"read size too small"
block|}
block|,
block|{
literal|40003
block|,
literal|"interrupted waiting for log data to read"
block|}
block|,
block|{
literal|40004
block|,
literal|"interrupted waiting for log data to read"
block|}
block|,
block|{
literal|40005
block|,
literal|"read size too large"
block|}
block|,
block|{
literal|40006
block|,
literal|"uiomove for read operation failed"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|50001
block|,
literal|"unknown lookup ioctl"
block|}
block|,
block|{
literal|50002
block|,
literal|"error copying in object data for add node"
block|}
block|,
block|{
literal|50003
block|,
literal|"invalid unit for lookup add node"
block|}
block|,
block|{
literal|50004
block|,
literal|"incorrect size for adding a pool node"
block|}
block|,
block|{
literal|50005
block|,
literal|"error copying in pool node structure"
block|}
block|,
block|{
literal|50006
block|,
literal|"mismatch in pool node address/mask families"
block|}
block|,
block|{
literal|50007
block|,
literal|"could not find pool name"
block|}
block|,
block|{
literal|50008
block|,
literal|"node already exists in pool"
block|}
block|,
block|{
literal|50009
block|,
literal|"incorrect size for adding a hash node"
block|}
block|,
block|{
literal|50010
block|,
literal|"error copying in hash node structure"
block|}
block|,
block|{
literal|50011
block|,
literal|"could not find hash table name"
block|}
block|,
block|{
literal|50012
block|,
literal|"unrecognised object type for lookup add node"
block|}
block|,
block|{
literal|50013
block|,
literal|"invalid unit for lookup delete node"
block|}
block|,
block|{
literal|50014
block|,
literal|"incorrect size for deleting a pool node"
block|}
block|,
block|{
literal|50015
block|,
literal|"error copying in pool node structure"
block|}
block|,
block|{
literal|50016
block|,
literal|"could not find pool name"
block|}
block|,
block|{
literal|50017
block|,
literal|"could not find pool node"
block|}
block|,
block|{
literal|50018
block|,
literal|"incorrect size for removing a hash node"
block|}
block|,
block|{
literal|50019
block|,
literal|"error copying in hash node structure"
block|}
block|,
block|{
literal|50020
block|,
literal|"could not find hash table name"
block|}
block|,
block|{
literal|50021
block|,
literal|"unrecognised object type for lookup delete node"
block|}
block|,
block|{
literal|50022
block|,
literal|"error copying in add table data"
block|}
block|,
block|{
literal|50023
block|,
literal|"invalid unit for lookup add table"
block|}
block|,
block|{
literal|50024
block|,
literal|"pool name already exists"
block|}
block|,
block|{
literal|50025
block|,
literal|"hash table name already exists"
block|}
block|,
block|{
literal|50026
block|,
literal|"unrecognised object type for lookup add table"
block|}
block|,
block|{
literal|50027
block|,
literal|"error copying table data back out"
block|}
block|,
block|{
literal|50028
block|,
literal|"error copying in remove table data"
block|}
block|,
block|{
literal|50029
block|,
literal|"invalid unit for lookup remove table"
block|}
block|,
block|{
literal|50030
block|,
literal|"unrecognised object type for lookup remove table"
block|}
block|,
block|{
literal|50031
block|,
literal|"error copying in lookup stats structure"
block|}
block|,
block|{
literal|50032
block|,
literal|"invalid unit for lookup stats"
block|}
block|,
block|{
literal|50033
block|,
literal|"unrecognised object type for lookup stats"
block|}
block|,
block|{
literal|50034
block|,
literal|"error copying in flush lookup data"
block|}
block|,
block|{
literal|50035
block|,
literal|"invalid unit for lookup flush"
block|}
block|,
block|{
literal|50036
block|,
literal|"incorrect table type for lookup flush"
block|}
block|,
block|{
literal|50037
block|,
literal|"error copying out lookup flush results"
block|}
block|,
block|{
literal|50038
block|,
literal|"invalid unit for lookup iterator"
block|}
block|,
block|{
literal|50039
block|,
literal|"invalid unit for lookup iterator"
block|}
block|,
block|{
literal|50040
block|,
literal|"could not find token for lookup iterator"
block|}
block|,
block|{
literal|50041
block|,
literal|"unrecognised object type for lookup interator"
block|}
block|,
block|{
literal|50042
block|,
literal|"error copying in lookup delete node operation"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|60001
block|,
literal|"insufficient privilege for NAT write operation"
block|}
block|,
block|{
literal|60002
block|,
literal|"need write permissions to flush NAT logs"
block|}
block|,
block|{
literal|60003
block|,
literal|"need write permissions to turn NAT logging on/off"
block|}
block|,
block|{
literal|60004
block|,
literal|"error copying out current NAT log setting"
block|}
block|,
block|{
literal|60005
block|,
literal|"error copying out bytes waiting to be read in NAT \ log"
block|}
block|,
block|{
literal|60006
block|,
literal|"need write permissions to add NAT rule"
block|}
block|,
block|{
literal|60007
block|,
literal|"NAT rule already exists"
block|}
block|,
block|{
literal|60008
block|,
literal|"could not allocate memory for NAT rule"
block|}
block|,
block|{
literal|60009
block|,
literal|"need write permissions to remove NAT rule"
block|}
block|,
block|{
literal|60010
block|,
literal|"NAT rule could not be found"
block|}
block|,
block|{
literal|60011
block|,
literal|"could not find NAT entry for redirect lookup"
block|}
block|,
block|{
literal|60012
block|,
literal|"need write permissions to flush NAT table"
block|}
block|,
block|{
literal|60013
block|,
literal|"error copying in NAT flush command"
block|}
block|,
block|{
literal|60014
block|,
literal|"need write permissions to do matching NAT flush"
block|}
block|,
block|{
literal|60015
block|,
literal|"need write permissions to set NAT lock"
block|}
block|,
block|{
literal|60016
block|,
literal|"need write permissions to add entry to NAT table"
block|}
block|,
block|{
literal|60017
block|,
literal|"NAT not locked for size retrieval"
block|}
block|,
block|{
literal|60018
block|,
literal|"NAT not locked for fetching NAT table entry"
block|}
block|,
block|{
literal|60019
block|,
literal|"error copying in NAT token data for deletion"
block|}
block|,
block|{
literal|60020
block|,
literal|"unknown NAT ioctl"
block|}
block|,
block|{
literal|60021
block|,
literal|""
block|}
block|,
block|{
literal|60022
block|,
literal|"resolving proxy name in NAT rule failed"
block|}
block|,
block|{
literal|60023
block|,
literal|"only reply age specified in NAT rule"
block|}
block|,
block|{
literal|60024
block|,
literal|"error doing copyin to determine NAT entry size"
block|}
block|,
block|{
literal|60025
block|,
literal|"error copying out NAT size of 0"
block|}
block|,
block|{
literal|60026
block|,
literal|"NAT entry not found"
block|}
block|,
block|{
literal|60027
block|,
literal|"error doing copyout of NAT entry size"
block|}
block|,
block|{
literal|60028
block|,
literal|"invalid data size for getting NAT entry"
block|}
block|,
block|{
literal|60029
block|,
literal|"could not malloc temporary space for NAT entry"
block|}
block|,
block|{
literal|60030
block|,
literal|"no NAT table entries present"
block|}
block|,
block|{
literal|60031
block|,
literal|"NAT entry to get next from not found"
block|}
block|,
block|{
literal|60032
block|,
literal|"not enough space for proxy structure"
block|}
block|,
block|{
literal|60033
block|,
literal|"not enough space for private proxy data"
block|}
block|,
block|{
literal|60034
block|,
literal|"NAT entry size is too large"
block|}
block|,
block|{
literal|60035
block|,
literal|"could not malloc memory for NAT entry sratch space"
block|}
block|,
block|{
literal|60036
block|,
literal|""
block|}
block|,
block|{
literal|60037
block|,
literal|"could not malloc memory for NAT entry"
block|}
block|,
block|{
literal|60038
block|,
literal|"could not malloc memory for NAT entry rule"
block|}
block|,
block|{
literal|60039
block|,
literal|"could not resolve NAT entry rule's proxy"
block|}
block|,
block|{
literal|60040
block|,
literal|"cannot add outbound duplicate NAT entry"
block|}
block|,
block|{
literal|60041
block|,
literal|"cannot add inbound duplicate NAT entry"
block|}
block|,
block|{
literal|60042
block|,
literal|"cannot add NAT entry that is neither IN nor OUT"
block|}
block|,
block|{
literal|60043
block|,
literal|"could not malloc memory for NAT proxy data"
block|}
block|,
block|{
literal|60044
block|,
literal|"proxy data size too big"
block|}
block|,
block|{
literal|60045
block|,
literal|"could not malloc proxy private data for NAT entry"
block|}
block|,
block|{
literal|60046
block|,
literal|"could not malloc memory for new NAT filter rule"
block|}
block|,
block|{
literal|60047
block|,
literal|"could not find existing filter rule for NAT entry"
block|}
block|,
block|{
literal|60048
block|,
literal|"insertion into NAT table failed"
block|}
block|,
block|{
literal|60049
block|,
literal|"iterator error copying out hostmap data"
block|}
block|,
block|{
literal|60050
block|,
literal|"iterator error copying out NAT rule data"
block|}
block|,
block|{
literal|60051
block|,
literal|"iterator error copying out NAT entry data"
block|}
block|,
block|{
literal|60052
block|,
literal|"iterator data supplied with NULL pointer"
block|}
block|,
block|{
literal|60053
block|,
literal|"unknown NAT iterator type"
block|}
block|,
block|{
literal|60054
block|,
literal|"unknwon next address type"
block|}
block|,
block|{
literal|60055
block|,
literal|"iterator suppled with unknown type for get-next"
block|}
block|,
block|{
literal|60056
block|,
literal|"unknown lookup group for next address"
block|}
block|,
block|{
literal|60057
block|,
literal|"error copying out NAT log flush results"
block|}
block|,
block|{
literal|60058
block|,
literal|"bucket table type is incorrect"
block|}
block|,
block|{
literal|60059
block|,
literal|"error copying out NAT bucket table"
block|}
block|,
block|{
literal|60060
block|,
literal|"function not found for lookup"
block|}
block|,
block|{
literal|60061
block|,
literal|"address family not supported with SIOCSTPUT"
block|}
block|,
block|{
literal|60062
block|,
literal|"unknown timeout name"
block|}
block|,
block|{
literal|60063
block|,
literal|"cannot allocate new inbound NAT entry table"
block|}
block|,
block|{
literal|60064
block|,
literal|"cannot allocate new outbound NAT entry table"
block|}
block|,
block|{
literal|60065
block|,
literal|"cannot allocate new inbound NAT bucketlen table"
block|}
block|,
block|{
literal|60066
block|,
literal|"cannot allocate new outbound NAT bucketlen table"
block|}
block|,
block|{
literal|60067
block|,
literal|"cannot allocate new NAT rules table"
block|}
block|,
block|{
literal|60068
block|,
literal|"cannot allocate new NAT hostmap table"
block|}
block|,
block|{
literal|60069
block|,
literal|"new source lookup type is not dstlist"
block|}
block|,
block|{
literal|60070
block|,
literal|"cannot allocate NAT rule scratch space"
block|}
block|,
block|{
literal|60071
block|,
literal|"new destination lookup type is not dstlist"
block|}
block|,
block|{
literal|60072
block|,
literal|"function not found for lookup (ipv6)"
block|}
block|,
block|{
literal|60073
block|,
literal|"unknown lookup group for next address (ipv6)"
block|}
block|,
block|{
literal|60074
block|,
literal|"unknown next address type (ipv6)"
block|}
block|,
block|{
literal|60075
block|,
literal|"one object at a time must be copied"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|70001
block|,
literal|"incorrect object size to get pool stats"
block|}
block|,
block|{
literal|70002
block|,
literal|"could not malloc memory for new pool node"
block|}
block|,
block|{
literal|70003
block|,
literal|"invalid addresss length for new pool node"
block|}
block|,
block|{
literal|70004
block|,
literal|"invalid mask length for new pool node"
block|}
block|,
block|{
literal|70005
block|,
literal|"error adding node to pool"
block|}
block|,
block|{
literal|70006
block|,
literal|"pool already exists"
block|}
block|,
block|{
literal|70007
block|,
literal|"could not malloc memory for new pool"
block|}
block|,
block|{
literal|70008
block|,
literal|"could not allocate radix tree for new pool"
block|}
block|,
block|{
literal|70009
block|,
literal|"could not find pool"
block|}
block|,
block|{
literal|70010
block|,
literal|"unknown pool name for iteration"
block|}
block|,
block|{
literal|70011
block|,
literal|"unknown pool iterator"
block|}
block|,
block|{
literal|70012
block|,
literal|"error copying out pool head"
block|}
block|,
block|{
literal|70013
block|,
literal|"error copying out pool node"
block|}
block|,
block|{
literal|70014
block|,
literal|"add node size incorrect"
block|}
block|,
block|{
literal|70015
block|,
literal|"error copying in pool node"
block|}
block|,
block|{
literal|70016
block|,
literal|""
block|}
block|,
block|{
literal|70017
block|,
literal|"cannot find pool for node"
block|}
block|,
block|{
literal|70018
block|,
literal|"node entry already present in pool"
block|}
block|,
block|{
literal|70019
block|,
literal|"delete node size incorrect"
block|}
block|,
block|{
literal|70020
block|,
literal|"error copying in node to delete"
block|}
block|,
block|{
literal|70021
block|,
literal|"cannot find pool to delete node from"
block|}
block|,
block|{
literal|70022
block|,
literal|"cannot find node to delete in pool"
block|}
block|,
block|{
literal|70023
block|,
literal|"pool name already exists"
block|}
block|,
block|{
literal|70024
block|,
literal|"uid mismatch for node removal"
block|}
block|,
block|{
literal|70025
block|,
literal|"stats device unit is invalid"
block|}
block|,
block|{
literal|70026
block|,
literal|"error copying out statistics"
block|}
block|,
block|{
literal|70027
block|,
literal|"could not remove node from radix tree"
block|}
block|,
block|{
literal|70028
block|,
literal|"incorrect address length in pool node add"
block|}
block|,
block|{
literal|70029
block|,
literal|"incorrect mask length in pool node add"
block|}
block|,
block|{
literal|70030
block|,
literal|"incorrect address length in pool node remove"
block|}
block|,
block|{
literal|70031
block|,
literal|"incorrect mask length in pool node remove"
block|}
block|,
block|{
literal|70032
block|,
literal|"cannot allocate memory for pool context"
block|}
block|,
block|{
literal|70033
block|,
literal|"cannot allocate memory for radix tree context"
block|}
block|,
block|{
literal|70034
block|,
literal|"adding IPv6 node with incorrect address length"
block|}
block|,
block|{
literal|70035
block|,
literal|"IPv4 address not masked"
block|}
block|,
block|{
literal|70036
block|,
literal|"IPv6 address not masked"
block|}
block|,
block|{
literal|70037
block|,
literal|"removing IPv6 node with incorrect address length"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|80001
block|,
literal|"could not find proxy"
block|}
block|,
block|{
literal|80002
block|,
literal|"proxy does not support control operations"
block|}
block|,
block|{
literal|80003
block|,
literal|"could not allocate data to hold proxy operation"
block|}
block|,
block|{
literal|80004
block|,
literal|"unknown proxy ioctl"
block|}
block|,
block|{
literal|80005
block|,
literal|"could not copyin proxy control structure"
block|}
block|,
block|{
literal|80006
block|,
literal|"DNS proxy could not find rule to delete"
block|}
block|,
block|{
literal|80007
block|,
literal|"DNS proxy found existing matching rule"
block|}
block|,
block|{
literal|80008
block|,
literal|"DNS proxy could not allocate memory for new rule"
block|}
block|,
block|{
literal|80009
block|,
literal|"DNS proxy unknown command request"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|90001
block|,
literal|"could not malloc space for new scan structure"
block|}
block|,
block|{
literal|90002
block|,
literal|"scan tag already exists"
block|}
block|,
block|{
literal|90003
block|,
literal|"scan structure in use"
block|}
block|,
block|{
literal|90004
block|,
literal|"could not find matching scan tag for filter rule"
block|}
block|,
block|{
literal|90005
block|,
literal|"could not copyout scan statistics"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|100001
block|,
literal|"cannot find matching state entry to remove"
block|}
block|,
block|{
literal|100002
block|,
literal|"error copying in v4 state flush command"
block|}
block|,
block|{
literal|100003
block|,
literal|"error copying out v4 state flush results"
block|}
block|,
block|{
literal|100004
block|,
literal|"error copying in v6 state flush command"
block|}
block|,
block|{
literal|100005
block|,
literal|"error copying out v6 state flush results"
block|}
block|,
block|{
literal|100006
block|,
literal|""
block|}
block|,
block|{
literal|100007
block|,
literal|""
block|}
block|,
block|{
literal|100008
block|,
literal|"need write permissions to flush state log"
block|}
block|,
block|{
literal|100009
block|,
literal|"erorr copyout results of flushing state log"
block|}
block|,
block|{
literal|100010
block|,
literal|"need write permissions to turn state logging on/off"
block|}
block|,
block|{
literal|100011
block|,
literal|"error copying in new state logging state"
block|}
block|,
block|{
literal|100012
block|,
literal|"error copying out current state logging state"
block|}
block|,
block|{
literal|100013
block|,
literal|"error copying out bytes waiting to be read in state \ log"
block|}
block|,
block|{
literal|100014
block|,
literal|"need write permissions to set state lock"
block|}
block|,
block|{
literal|100015
block|,
literal|"need write permissions to add entry to state table"
block|}
block|,
block|{
literal|100016
block|,
literal|"state not locked for size retrieval"
block|}
block|,
block|{
literal|100017
block|,
literal|"error copying out hash table bucket lengths"
block|}
block|,
block|{
literal|100018
block|,
literal|"could not find token for state iterator"
block|}
block|,
block|{
literal|100019
block|,
literal|"error copying in state token data for deletion"
block|}
block|,
block|{
literal|100020
block|,
literal|"unknown state ioctl"
block|}
block|,
block|{
literal|100021
block|,
literal|"no state table entries present"
block|}
block|,
block|{
literal|100022
block|,
literal|"state entry to get next from not found"
block|}
block|,
block|{
literal|100023
block|,
literal|"could not malloc memory for state entry"
block|}
block|,
block|{
literal|100024
block|,
literal|"could not malloc memory for state entry rule"
block|}
block|,
block|{
literal|100025
block|,
literal|"could not copy back state entry to user space"
block|}
block|,
block|{
literal|100026
block|,
literal|"iterator data supplied with NULL pointer"
block|}
block|,
block|{
literal|100027
block|,
literal|"iterator supplied with 0 item count"
block|}
block|,
block|{
literal|100028
block|,
literal|"iterator type is incorrect"
block|}
block|,
block|{
literal|100029
block|,
literal|"invalid state token data pointer supplied"
block|}
block|,
block|{
literal|100030
block|,
literal|"error copying out next state entry"
block|}
block|,
block|{
literal|100031
block|,
literal|"unrecognised table request"
block|}
block|,
block|{
literal|100032
block|,
literal|"error copying out bucket length data"
block|}
block|,
block|{
literal|100033
block|,
literal|"could not find existing filter rule for state entry"
block|}
block|,
block|{
literal|100034
block|,
literal|"could not find timeout name"
block|}
block|,
block|{
literal|100035
block|,
literal|"could not allocate new state table"
block|}
block|,
block|{
literal|100036
block|,
literal|"could not allocate new state bucket length table"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|110001
block|,
literal|"sync write header magic number is incorrect"
block|}
block|,
block|{
literal|110002
block|,
literal|"sync write header protocol is incorrect"
block|}
block|,
block|{
literal|110003
block|,
literal|"sync write header command is incorrect"
block|}
block|,
block|{
literal|110004
block|,
literal|"sync write header table number is incorrect"
block|}
block|,
block|{
literal|110005
block|,
literal|"data structure too small for sync write operation"
block|}
block|,
block|{
literal|110006
block|,
literal|"zero length data with sync write header"
block|}
block|,
block|{
literal|110007
block|,
literal|"insufficient data for sync write"
block|}
block|,
block|{
literal|110008
block|,
literal|"bad sync read size"
block|}
block|,
block|{
literal|110009
block|,
literal|"interrupted sync read (solaris)"
block|}
block|,
block|{
literal|110010
block|,
literal|"interrupted sync read (hpux)"
block|}
block|,
block|{
literal|110011
block|,
literal|"interrupted sync read (osf)"
block|}
block|,
block|{
literal|110012
block|,
literal|"interrupted sync read"
block|}
block|,
block|{
literal|110013
block|,
literal|"could not malloc memory for sync'd state"
block|}
block|,
block|{
literal|110014
block|,
literal|"could not malloc memory for sync-state list item"
block|}
block|,
block|{
literal|110015
block|,
literal|"sync update could not find state"
block|}
block|,
block|{
literal|110016
block|,
literal|"unrecognised sync state command"
block|}
block|,
block|{
literal|110017
block|,
literal|"could not malloc memory for new sync'd NAT entry"
block|}
block|,
block|{
literal|110018
block|,
literal|"could not malloc memory for sync-NAT list item"
block|}
block|,
block|{
literal|110019
block|,
literal|"sync update could not find NAT entry"
block|}
block|,
block|{
literal|110020
block|,
literal|"unrecognised sync NAT command"
block|}
block|,
block|{
literal|110021
block|,
literal|"ioctls are not handled with sync"
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|120001
block|,
literal|"null data pointer for iterator"
block|}
block|,
block|{
literal|120002
block|,
literal|"unit outside of acceptable range"
block|}
block|,
block|{
literal|120003
block|,
literal|"unknown iterator subtype"
block|}
block|,
block|{
literal|120004
block|,
literal|"cannot find dest. list for iteration"
block|}
block|,
block|{
literal|120005
block|,
literal|"error copying out destination iteration list"
block|}
block|,
block|{
literal|120006
block|,
literal|"error copying out destination iteration node"
block|}
block|,
block|{
literal|120007
block|,
literal|"wrong size for frdest_t structure"
block|}
block|,
block|{
literal|120008
block|,
literal|"cannot allocate memory for new destination node"
block|}
block|,
block|{
literal|120009
block|,
literal|"error copying in destination node to add"
block|}
block|,
block|{
literal|120010
block|,
literal|"could not find destination list to add node to"
block|}
block|,
block|{
literal|120011
block|,
literal|"error copying in destination node to remove"
block|}
block|,
block|{
literal|120012
block|,
literal|"could not find dest. list to remove node from"
block|}
block|,
block|{
literal|120013
block|,
literal|"destination list already exists"
block|}
block|,
block|{
literal|120014
block|,
literal|"could not allocate new destination table"
block|}
block|,
block|{
literal|120015
block|,
literal|"could not find destination list to remove"
block|}
block|,
block|{
literal|120016
block|,
literal|"destination list cannot be removed - it is busy"
block|}
block|,
block|{
literal|120017
block|,
literal|"error copying in names for destination"
block|}
block|,
block|{
literal|120018
block|,
literal|"destination name is too long/short"
block|}
block|,
block|{
literal|120019
block|,
literal|"unrecognised address family in destination"
block|}
block|,
block|{
literal|120020
block|,
literal|""
block|}
block|,
block|{
literal|120021
block|,
literal|"error copying in new destination table"
block|}
block|,
block|{
literal|120022
block|,
literal|"cannot allocate memory for node table"
block|}
block|,
block|{
literal|120023
block|,
literal|"stats object size is incorrect for dest. lists"
block|}
block|,
block|{
literal|120024
block|,
literal|"stats device unit is invalid for dest. lists"
block|}
block|,
block|{
literal|120025
block|,
literal|"error copying out dest. list statistics"
block|}
block|,
block|{
literal|120026
block|,
literal|"cannot allocate memory for destination node"
block|}
block|,
block|{
literal|120027
block|,
literal|"error copying in destination node"
block|}
block|,
block|{
literal|120028
block|,
literal|"cannot allocate memory for destination context "
block|}
block|,
comment|/* -------------------------------------------------------------------------- */
block|{
literal|130001
block|,
literal|"ioctl denied by system security level"
block|}
block|,
block|{
literal|130002
block|,
literal|"ioctl operation on invalid minor device"
block|}
block|,
block|{
literal|130003
block|,
literal|"ioctl on device denied, ipfitler is disabled"
block|}
block|,
block|{
literal|130004
block|,
literal|"ioctl command not allowed when disabled"
block|}
block|,
block|{
literal|130005
block|,
literal|"ioctl denied due to insufficient authorisation"
block|}
block|,
block|{
literal|130006
block|,
literal|"cannot read while ipfilter is disabled"
block|}
block|,
block|{
literal|130007
block|,
literal|"read on minor device not supported"
block|}
block|,
block|{
literal|130008
block|,
literal|"cannot write while ipfilter is disabled"
block|}
block|,
block|{
literal|130009
block|,
literal|"write on minor device not supported"
block|}
block|,
block|{
literal|130010
block|,
literal|"poll on minor device is not supported"
block|}
block|,
block|{
literal|130011
block|,
literal|"error removing IPv4 filter hooks"
block|}
block|,
block|{
literal|130012
block|,
literal|"error removing IPv6 filter hooks"
block|}
block|,
block|{
literal|130013
block|,
literal|"attaching IPv4 hook failed"
block|}
block|,
block|{
literal|130014
block|,
literal|"attaching IPv6 hook failed"
block|}
block|,
block|{
literal|130015
block|,
literal|"ipf_init_all failed"
block|}
block|,
block|{
literal|130016
block|,
literal|"finding pfil head failed"
block|}
block|,
block|{
literal|130017
block|,
literal|"ipfilter is already initialised and running"
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|ipf_error_entry_t
modifier|*
name|find_error
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
name|ipf_error_entry_t
modifier|*
name|ie
decl_stmt|;
name|int
name|l
init|=
operator|-
literal|1
decl_stmt|,
name|r
init|=
name|IPF_NUM_ERRORS
operator|+
literal|1
decl_stmt|,
name|step
decl_stmt|;
name|step
operator|=
operator|(
name|r
operator|-
name|l
operator|)
operator|/
literal|2
expr_stmt|;
empty_stmt|;
while|while
condition|(
name|step
operator|!=
literal|0
condition|)
block|{
name|ie
operator|=
name|ipf_errors
operator|+
name|l
operator|+
name|step
expr_stmt|;
if|if
condition|(
name|ie
operator|->
name|iee_number
operator|==
name|errnum
condition|)
return|return
name|ie
return|;
name|step
operator|=
name|l
operator|+
name|step
expr_stmt|;
if|if
condition|(
name|ie
operator|->
name|iee_number
operator|>
name|errnum
condition|)
name|r
operator|=
name|step
expr_stmt|;
else|else
name|l
operator|=
name|step
expr_stmt|;
name|step
operator|=
operator|(
name|r
operator|-
name|l
operator|)
operator|/
literal|2
expr_stmt|;
empty_stmt|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|ipf_geterror
parameter_list|(
name|fd
parameter_list|,
name|func
parameter_list|)
name|int
name|fd
decl_stmt|;
name|ioctlfunc_t
modifier|*
name|func
decl_stmt|;
block|{
specifier|static
name|char
name|text
index|[
literal|80
index|]
decl_stmt|;
name|ipf_error_entry_t
modifier|*
name|ie
decl_stmt|;
name|int
name|errnum
decl_stmt|;
if|if
condition|(
call|(
modifier|*
name|func
call|)
argument_list|(
name|fd
argument_list|,
name|SIOCIPFINTERROR
argument_list|,
operator|&
name|errnum
argument_list|)
operator|==
literal|0
condition|)
block|{
name|ie
operator|=
name|find_error
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
if|if
condition|(
name|ie
operator|!=
name|NULL
condition|)
return|return
name|ie
operator|->
name|iee_text
return|;
name|sprintf
argument_list|(
name|text
argument_list|,
literal|"unknown error %d"
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|text
argument_list|,
literal|"retrieving error number failed (%d)"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
return|return
name|text
return|;
block|}
end_function

begin_function
name|char
modifier|*
name|ipf_strerror
parameter_list|(
name|errnum
parameter_list|)
name|int
name|errnum
decl_stmt|;
block|{
specifier|static
name|char
name|text
index|[
literal|80
index|]
decl_stmt|;
name|ipf_error_entry_t
modifier|*
name|ie
decl_stmt|;
name|ie
operator|=
name|find_error
argument_list|(
name|errnum
argument_list|)
expr_stmt|;
if|if
condition|(
name|ie
operator|!=
name|NULL
condition|)
return|return
name|ie
operator|->
name|iee_text
return|;
name|sprintf
argument_list|(
name|text
argument_list|,
literal|"unknown error %d"
argument_list|,
name|errnum
argument_list|)
expr_stmt|;
return|return
name|text
return|;
block|}
end_function

end_unit

