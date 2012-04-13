begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005-2006 The FreeBSD Project  * All rights reserved.  *  * Author: Shteryana Shopova<syrinx@FreeBSD.org>  *  * Redistribution of this software and documentation and use in source and  * binary forms, with or without modification, are permitted provided that  * the following conditions are met:  *  * 1. Redistributions of source code or documentation must retain the above  *    copyright notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Helper functions common for all tools.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSNMP_TOOLS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSNMP_TOOLS_H_
end_define

begin_comment
comment|/* From asn1.h + 1 byte for trailing zero. */
end_comment

begin_define
define|#
directive|define
name|MAX_OCTSTRING_LEN
value|ASN_MAXOCTETSTRING + 1
end_define

begin_define
define|#
directive|define
name|MAX_CMD_SYNTAX_LEN
value|12
end_define

begin_comment
comment|/* Arbitrary upper limit on node names and function names - gensnmptree.c. */
end_comment

begin_define
define|#
directive|define
name|MAXSTR
value|1000
end_define

begin_comment
comment|/* Should be enough to fetch the biggest allowed octet string. */
end_comment

begin_define
define|#
directive|define
name|MAX_BUFF_SIZE
value|(ASN_MAXOCTETSTRING + 50)
end_define

begin_define
define|#
directive|define
name|SNMP_DEFS_DIR
value|"/usr/share/snmp/defs/"
end_define

begin_define
define|#
directive|define
name|SNMP_DEFAULT_LOCAL
value|"/var/run/snmpd.sock"
end_define

begin_define
define|#
directive|define
name|SNMP_MAX_REPETITIONS
value|10
end_define

begin_enum
enum|enum
name|snmp_access
block|{
name|SNMP_ACCESS_NONE
init|=
literal|0
block|,
name|SNMP_ACCESS_GET
block|,
name|SNMP_ACCESS_SET
block|,
name|SNMP_ACCESS_GETSET
block|, }
enum|;
end_enum

begin_comment
comment|/* A structure for integer-string enumerations. */
end_comment

begin_struct
struct|struct
name|enum_pair
block|{
name|int32_t
name|enum_val
decl_stmt|;
name|char
modifier|*
name|enum_str
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|enum_pair
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|enum_pairs
argument_list|,
name|enum_pair
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|enum_type
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|uint32_t
name|syntax
decl_stmt|;
name|int32_t
name|is_enum
decl_stmt|;
name|int32_t
name|is_bits
decl_stmt|;
name|struct
name|enum_pairs
modifier|*
name|snmp_enum
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|enum_type
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|snmp_enum_tc
argument_list|,
name|enum_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|index
block|{
name|enum
name|snmp_tc
name|tc
decl_stmt|;
name|enum
name|snmp_syntax
name|syntax
decl_stmt|;
name|struct
name|enum_pairs
modifier|*
name|snmp_enum
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|index
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|snmp_idxlist
argument_list|,
name|index
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|snmp_index_entry
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|uint32_t
name|strlen
decl_stmt|;
name|struct
name|asn_oid
name|var
decl_stmt|;
name|struct
name|snmp_idxlist
name|index_list
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|snmp_index_entry
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information needed for oid to string conversion. */
end_comment

begin_struct
struct|struct
name|snmp_oid2str
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|uint32_t
name|strlen
decl_stmt|;
name|enum
name|snmp_tc
name|tc
decl_stmt|;
name|enum
name|snmp_syntax
name|syntax
decl_stmt|;
name|enum
name|snmp_access
name|access
decl_stmt|;
name|struct
name|asn_oid
name|var
decl_stmt|;
comment|/* A pointer to a entry from the table list - OK if NULL. */
name|struct
name|snmp_index_entry
modifier|*
name|table_idx
decl_stmt|;
comment|/* 	 * A singly-linked tail queue of all (int, string) pairs - 	 * for INTEGER syntax only. 	 */
name|struct
name|enum_pairs
modifier|*
name|snmp_enum
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|snmp_oid2str
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A structure to hold each oid input by user. */
end_comment

begin_struct
struct|struct
name|snmp_object
block|{
comment|/* Flag - if set, the variable caused error in a previous request. */
name|int32_t
name|error
decl_stmt|;
comment|/* 	 * A pointer in the mapping lists - not used if OIDs are input as 	 * numericals. 	 */
name|struct
name|snmp_oid2str
modifier|*
name|info
decl_stmt|;
comment|/* A snmp value to hold the actual oid, syntax and value. */
name|struct
name|snmp_value
name|val
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|snmp_object
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fname
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int32_t
name|done
decl_stmt|;
name|struct
name|asn_oid
name|cut
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|fname
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|snmp_mapping
argument_list|,
name|snmp_oid2str
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|fname_list
argument_list|,
name|fname
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|snmp_table_index
argument_list|,
name|snmp_index_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Keep a list for every syntax type.  */
end_comment

begin_struct
struct|struct
name|snmp_mappings
block|{
comment|/* The list containing all non-leaf nodes. */
name|struct
name|snmp_mapping
name|nodelist
decl_stmt|;
comment|/* INTEGER/INTEGER32 types. */
name|struct
name|snmp_mapping
name|intlist
decl_stmt|;
comment|/* OCTETSTRING types. */
name|struct
name|snmp_mapping
name|octlist
decl_stmt|;
comment|/* OID types. */
name|struct
name|snmp_mapping
name|oidlist
decl_stmt|;
comment|/* IPADDRESS types. */
name|struct
name|snmp_mapping
name|iplist
decl_stmt|;
comment|/* TIMETICKS types. */
name|struct
name|snmp_mapping
name|ticklist
decl_stmt|;
comment|/* COUNTER types. */
name|struct
name|snmp_mapping
name|cntlist
decl_stmt|;
comment|/* GAUGE types. */
name|struct
name|snmp_mapping
name|gaugelist
decl_stmt|;
comment|/* COUNTER64 types. */
name|struct
name|snmp_mapping
name|cnt64list
decl_stmt|;
comment|/* ENUM values for oid types. */
name|struct
name|snmp_mapping
name|enumlist
decl_stmt|;
comment|/* Description of all table entry types. */
name|struct
name|snmp_table_index
name|tablelist
decl_stmt|;
comment|/* Defined enumerated textual conventions. */
name|struct
name|snmp_enum_tc
name|tclist
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|snmp_toolinfo
block|{
name|uint32_t
name|flags
decl_stmt|;
comment|/* Number of initially input OIDs. */
name|int32_t
name|objects
decl_stmt|;
comment|/* List of all input OIDs. */
name|SLIST_HEAD
argument_list|(
argument|snmp_objectlist
argument_list|,
argument|snmp_object
argument_list|)
name|snmp_objectlist
expr_stmt|;
comment|/* All known OID to string mapping data. */
name|struct
name|snmp_mappings
modifier|*
name|mappings
decl_stmt|;
comment|/* A list of .defs filenames to search oid<->string mapping. */
name|struct
name|fname_list
name|filelist
decl_stmt|;
comment|/* SNMPv3 USM user credentials */
name|char
modifier|*
name|passwd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX we might want to get away with this and will need to touch  * XXX the MACROS then too */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|snmp_toolinfo
name|snmptool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Definitions for some flags' bits. */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_BITS
value|0x00000003
end_define

begin_comment
comment|/* bits 0-1 for output type */
end_comment

begin_define
define|#
directive|define
name|NUMERIC_BIT
value|0x00000004
end_define

begin_comment
comment|/* bit 2 for numeric oids */
end_comment

begin_define
define|#
directive|define
name|RETRY_BIT
value|0x00000008
end_define

begin_comment
comment|/* bit 3 for retry on error response */
end_comment

begin_define
define|#
directive|define
name|ERRIGNORE_BIT
value|0x00000010
end_define

begin_comment
comment|/* bit 4 for skip sanity checking */
end_comment

begin_define
define|#
directive|define
name|ERRIGNORE_BIT
value|0x00000010
end_define

begin_comment
comment|/* bit 4 for skip sanity checking */
end_comment

begin_define
define|#
directive|define
name|EDISCOVER_BIT
value|0x00000020
end_define

begin_comment
comment|/* bit 5 for SNMP Engine Discovery */
end_comment

begin_define
define|#
directive|define
name|LOCALKEY_BIT
value|0x00000040
end_define

begin_comment
comment|/* bit 6 for using localized key */
end_comment

begin_comment
comment|/*	0x00000080 */
end_comment

begin_comment
comment|/* bit 7 reserved */
end_comment

begin_define
define|#
directive|define
name|PDUTYPE_BITS
value|0x00000f00
end_define

begin_comment
comment|/* bits 8-11 for pdu type */
end_comment

begin_comment
comment|/*	0x0000f000 */
end_comment

begin_comment
comment|/* bit 12-15 reserved */
end_comment

begin_define
define|#
directive|define
name|MAXREP_BITS
value|0x00ff0000
end_define

begin_comment
comment|/* bits 16-23 for max-repetit. value */
end_comment

begin_define
define|#
directive|define
name|NONREP_BITS
value|0xff000000
end_define

begin_comment
comment|/* bits 24-31 for non-repeaters value */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_SHORT
value|0x0
end_define

begin_define
define|#
directive|define
name|OUTPUT_VERBOSE
value|0x1
end_define

begin_define
define|#
directive|define
name|OUTPUT_TABULAR
value|0x2
end_define

begin_define
define|#
directive|define
name|OUTPUT_QUIET
value|0x3
end_define

begin_comment
comment|/* Macros for playing with flags' bits. */
end_comment

begin_define
define|#
directive|define
name|SET_OUTPUT
parameter_list|(
name|ctx
parameter_list|,
name|type
parameter_list|)
value|((ctx)->flags |= ((type)& OUTPUT_BITS))
end_define

begin_define
define|#
directive|define
name|GET_OUTPUT
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& OUTPUT_BITS)
end_define

begin_define
define|#
directive|define
name|SET_NUMERIC
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags |= NUMERIC_BIT)
end_define

begin_define
define|#
directive|define
name|ISSET_NUMERIC
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& NUMERIC_BIT)
end_define

begin_define
define|#
directive|define
name|SET_RETRY
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags |= RETRY_BIT)
end_define

begin_define
define|#
directive|define
name|ISSET_RETRY
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& RETRY_BIT)
end_define

begin_define
define|#
directive|define
name|SET_ERRIGNORE
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags |= ERRIGNORE_BIT)
end_define

begin_define
define|#
directive|define
name|ISSET_ERRIGNORE
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& ERRIGNORE_BIT)
end_define

begin_define
define|#
directive|define
name|SET_EDISCOVER
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags |= EDISCOVER_BIT)
end_define

begin_define
define|#
directive|define
name|ISSET_EDISCOVER
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& EDISCOVER_BIT)
end_define

begin_define
define|#
directive|define
name|SET_LOCALKEY
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags |= LOCALKEY_BIT)
end_define

begin_define
define|#
directive|define
name|ISSET_LOCALKEY
parameter_list|(
name|ctx
parameter_list|)
value|((ctx)->flags& LOCALKEY_BIT)
end_define

begin_define
define|#
directive|define
name|SET_PDUTYPE
parameter_list|(
name|ctx
parameter_list|,
name|type
parameter_list|)
value|(((ctx)->flags |= (((type)& 0xf)<< 8)))
end_define

begin_define
define|#
directive|define
name|GET_PDUTYPE
parameter_list|(
name|ctx
parameter_list|)
value|(((ctx)->flags& PDUTYPE_BITS)>> 8)
end_define

begin_define
define|#
directive|define
name|SET_MAXREP
parameter_list|(
name|ctx
parameter_list|,
name|i
parameter_list|)
value|(((ctx)->flags |= (((i)& 0xff)<< 16)))
end_define

begin_define
define|#
directive|define
name|GET_MAXREP
parameter_list|(
name|ctx
parameter_list|)
value|(((ctx)->flags& MAXREP_BITS)>> 16)
end_define

begin_define
define|#
directive|define
name|SET_NONREP
parameter_list|(
name|ctx
parameter_list|,
name|i
parameter_list|)
value|(((ctx)->flags |= (((i)& 0xff)<< 24)))
end_define

begin_define
define|#
directive|define
name|GET_NONREP
parameter_list|(
name|ctx
parameter_list|)
value|(((ctx)->flags& NONREP_BITS)>> 24)
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|asn_oid
name|IsoOrgDod_OID
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|snmptool_init
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_import_file
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|fname
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_import_all
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|add_filename
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_filelist
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_tool_freeall
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_import_dump
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* bsnmpmap.c */
end_comment

begin_function_decl
name|struct
name|snmp_mappings
modifier|*
name|snmp_mapping_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_mapping_free
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_index_listfree
parameter_list|(
name|struct
name|snmp_idxlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_dump_oid2str
parameter_list|(
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_node_insert
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_leaf_insert
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_enum_insert
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|enum_pairs
modifier|*
name|enum_pairs_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|enum_pairs_free
parameter_list|(
name|struct
name|enum_pairs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_mapping_entryfree
parameter_list|(
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|enum_pair_insert
parameter_list|(
name|struct
name|enum_pairs
modifier|*
parameter_list|,
name|int32_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|enum_string_lookup
parameter_list|(
name|struct
name|enum_pairs
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|enum_number_lookup
parameter_list|(
name|struct
name|enum_pairs
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_syntax_insert
parameter_list|(
name|struct
name|snmp_idxlist
modifier|*
parameter_list|,
name|struct
name|enum_pairs
modifier|*
parameter_list|,
name|enum
name|snmp_syntax
parameter_list|,
name|enum
name|snmp_tc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_table_insert
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_index_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|enum_type
modifier|*
name|snmp_enumtc_init
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_enumtc_free
parameter_list|(
name|struct
name|enum_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_enumtc_insert
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|enum_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|enum_type
modifier|*
name|snmp_enumtc_lookup
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_mapping_dump
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_leafstring
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_enumstring
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_oidstring
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_nonleaf_string
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_allstring
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_nodestring
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_oidall
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_enumoid
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_lookup_oid
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions parsing common options for all tools. */
end_comment

begin_function_decl
name|int32_t
name|parse_server
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_timeout
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_retry
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_version
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_local_path
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_buflen
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_debug
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_discovery
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_local_key
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_num_oids
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_file
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_include
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_output
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_errors
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_skip_access
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_authentication
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_privacy
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_context
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|parse_user_security
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|snmp_verify_inoid_f
function_decl|)
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int32_t
name|snmp_object_add
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|snmp_verify_inoid_f
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_object_remove
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
name|oid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_object_seterror
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|snmp_syntax
name|parse_syntax
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|snmp_parse_suboid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|snmp_parse_index
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_parse_numoid
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_suboid_append
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|,
name|asn_subid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_suboid_pop
parameter_list|(
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|snmp_verify_vbind_f
function_decl|)
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
function_decl|(
modifier|*
name|snmp_add_vbind_f
function_decl|)
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_object
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int32_t
name|snmp_pdu_add_bindings
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|snmp_verify_vbind_f
parameter_list|,
name|snmp_add_vbind_f
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_parse_get_resp
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_parse_getbulk_resp
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_parse_getnext_resp
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_parse_resp
parameter_list|(
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_output_numval
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_value
modifier|*
parameter_list|,
name|struct
name|snmp_oid2str
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_output_val
parameter_list|(
name|struct
name|snmp_value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int32_t
name|snmp_output_resp
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|,
name|struct
name|asn_oid
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_output_err_resp
parameter_list|(
name|struct
name|snmp_toolinfo
modifier|*
parameter_list|,
name|struct
name|snmp_pdu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_output_engine
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|snmp_output_keys
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSNMP_TOOLS_H_ */
end_comment

end_unit

