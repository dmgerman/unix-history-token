begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/localzone.h - local zones authority service.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains functions to enable local zone authority service.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_LOCALZONE_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_LOCALZONE_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|edns_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Local zone type  * This type determines processing for queries that did not match  * local-data directly.  */
end_comment

begin_enum
enum|enum
name|localzone_type
block|{
comment|/** drop query */
name|local_zone_deny
init|=
literal|0
block|,
comment|/** answer with error */
name|local_zone_refuse
block|,
comment|/** answer nxdomain or nodata */
name|local_zone_static
block|,
comment|/** resolve normally */
name|local_zone_transparent
block|,
comment|/** do not block types at localdata names */
name|local_zone_typetransparent
block|,
comment|/** answer with data at zone apex */
name|local_zone_redirect
block|,
comment|/** remove default AS112 blocking contents for zone 	 * nodefault is used in config not during service. */
name|local_zone_nodefault
block|}
enum|;
end_enum

begin_comment
comment|/**  * Authoritative local zones storage, shared.  */
end_comment

begin_struct
struct|struct
name|local_zones
block|{
comment|/** lock on the localzone tree */
name|lock_rw_t
name|lock
decl_stmt|;
comment|/** rbtree of struct local_zone */
name|rbtree_t
name|ztree
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Local zone. A locally served authoritative zone.  */
end_comment

begin_struct
struct|struct
name|local_zone
block|{
comment|/** rbtree node, key is name and class */
name|rbnode_t
name|node
decl_stmt|;
comment|/** parent zone, if any. */
name|struct
name|local_zone
modifier|*
name|parent
decl_stmt|;
comment|/** zone name, in uncompressed wireformat */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of zone name */
name|size_t
name|namelen
decl_stmt|;
comment|/** number of labels in zone name */
name|int
name|namelabs
decl_stmt|;
comment|/** the class of this zone.  	 * uses 'dclass' to not conflict with c++ keyword class. */
name|uint16_t
name|dclass
decl_stmt|;
comment|/** lock on the data in the structure 	 * For the node, parent, name, namelen, namelabs, dclass, you 	 * need to also hold the zones_tree lock to change them (or to 	 * delete this zone) */
name|lock_rw_t
name|lock
decl_stmt|;
comment|/** how to process zone */
name|enum
name|localzone_type
name|type
decl_stmt|;
comment|/** in this region the zone's data is allocated. 	 * the struct local_zone itself is malloced. */
name|struct
name|regional
modifier|*
name|region
decl_stmt|;
comment|/** local data for this zone 	 * rbtree of struct local_data */
name|rbtree_t
name|data
decl_stmt|;
comment|/** if data contains zone apex SOA data, this is a ptr to it. */
name|struct
name|ub_packed_rrset_key
modifier|*
name|soa
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Local data. One domain name, and the RRs to go with it.  */
end_comment

begin_struct
struct|struct
name|local_data
block|{
comment|/** rbtree node, key is name only */
name|rbnode_t
name|node
decl_stmt|;
comment|/** domain name */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|namelen
decl_stmt|;
comment|/** number of labels in name */
name|int
name|namelabs
decl_stmt|;
comment|/** the data rrsets, with different types, linked list. 	 * If this list is NULL, the node is an empty non-terminal. */
name|struct
name|local_rrset
modifier|*
name|rrsets
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A local data RRset  */
end_comment

begin_struct
struct|struct
name|local_rrset
block|{
comment|/** next in list */
name|struct
name|local_rrset
modifier|*
name|next
decl_stmt|;
comment|/** RRset data item */
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create local zones storage  * @return new struct or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|local_zones
modifier|*
name|local_zones_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete local zones storage  * @param zones: to delete.  */
end_comment

begin_function_decl
name|void
name|local_zones_delete
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Apply config settings; setup the local authoritative data.   * Takes care of locking.  * @param zones: is set up.  * @param cfg: config data.  * @return false on error.  */
end_comment

begin_function_decl
name|int
name|local_zones_apply_cfg
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two local_zone entries in rbtree. Sort hierarchical but not  * canonical  * @param z1: zone 1  * @param z2: zone 2  * @return: -1, 0, +1 comparison value.  */
end_comment

begin_function_decl
name|int
name|local_zone_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|z1
parameter_list|,
specifier|const
name|void
modifier|*
name|z2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Compare two local_data entries in rbtree. Sort canonical.  * @param d1: data 1  * @param d2: data 2  * @return: -1, 0, +1 comparison value.  */
end_comment

begin_function_decl
name|int
name|local_data_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|d1
parameter_list|,
specifier|const
name|void
modifier|*
name|d2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete one zone  * @param z: to delete.  */
end_comment

begin_function_decl
name|void
name|local_zone_delete
parameter_list|(
name|struct
name|local_zone
modifier|*
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup zone that contains the given name, class.  * User must lock the tree or result zone.  * @param zones: the zones tree  * @param name: dname to lookup  * @param len: length of name.  * @param labs: labelcount of name.  * @param dclass: class to lookup.  * @return closest local_zone or NULL if no covering zone is found.  */
end_comment

begin_function_decl
name|struct
name|local_zone
modifier|*
name|local_zones_lookup
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Debug helper. Print all zones   * Takes care of locking.  * @param zones: the zones tree  */
end_comment

begin_function_decl
name|void
name|local_zones_print
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Answer authoritatively for local zones.  * Takes care of locking.  * @param zones: the stored zones (shared, read only).  * @param qinfo: query info (parsed).  * @param edns: edns info (parsed).  * @param buf: buffer with query ID and flags, also for reply.  * @param temp: temporary storage region.  * @return true if answer is in buffer. false if query is not answered   * by authority data. If the reply should be dropped altogether, the return   * value is true, but the buffer is cleared (empty).  */
end_comment

begin_function_decl
name|int
name|local_zones_answer
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|edns_data
modifier|*
name|edns
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|struct
name|regional
modifier|*
name|temp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Parse the string into localzone type.  *  * @param str: string to parse  * @param t: local zone type returned here.  * @return 0 on parse error.  */
end_comment

begin_function_decl
name|int
name|local_zone_str2type
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|enum
name|localzone_type
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Print localzone type to a string.  Pointer to a constant string.  *  * @param t: local zone type.  * @return constant string that describes type.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|local_zone_type2str
parameter_list|(
name|enum
name|localzone_type
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find zone that with exactly given name, class.  * User must lock the tree or result zone.  * @param zones: the zones tree  * @param name: dname to lookup  * @param len: length of name.  * @param labs: labelcount of name.  * @param dclass: class to lookup.  * @return the exact local_zone or NULL.  */
end_comment

begin_function_decl
name|struct
name|local_zone
modifier|*
name|local_zones_find
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add a new zone. Caller must hold the zones lock.  * Adjusts the other zones as well (parent pointers) after insertion.  * The zone must NOT exist (returns NULL and logs error).  * @param zones: the zones tree  * @param name: dname to add  * @param len: length of name.  * @param labs: labelcount of name.  * @param dclass: class to add.  * @param tp: type.  * @return local_zone or NULL on error, caller must printout memory error.  */
end_comment

begin_function_decl
name|struct
name|local_zone
modifier|*
name|local_zones_add_zone
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|enum
name|localzone_type
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete a zone. Caller must hold the zones lock.  * Adjusts the other zones as well (parent pointers) after insertion.  * @param zones: the zones tree  * @param zone: the zone to delete from tree. Also deletes zone from memory.  */
end_comment

begin_function_decl
name|void
name|local_zones_del_zone
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|struct
name|local_zone
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add RR data into the localzone data.  * Looks up the zone, if no covering zone, a transparent zone with the  * name of the RR is created.  * @param zones: the zones tree. Not locked by caller.  * @param rr: string with on RR.  * @return false on failure.  */
end_comment

begin_function_decl
name|int
name|local_zones_add_RR
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
specifier|const
name|char
modifier|*
name|rr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove data from domain name in the tree.  * All types are removed. No effect if zone or name does not exist.  * @param zones: zones tree.  * @param name: dname to remove  * @param len: length of name.  * @param labs: labelcount of name.  * @param dclass: class to remove.  */
end_comment

begin_function_decl
name|void
name|local_zones_del_data
parameter_list|(
name|struct
name|local_zones
modifier|*
name|zones
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|int
name|labs
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Form wireformat from text format domain name.   * @param str: the domain name in text "www.example.com"  * @param res: resulting wireformat is stored here with malloc.  * @param len: length of resulting wireformat.  * @param labs: number of labels in resulting wireformat.  * @return false on error, syntax or memory. Also logged.  */
end_comment

begin_function_decl
name|int
name|parse_dname
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|res
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|,
name|int
modifier|*
name|labs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_LOCALZONE_H */
end_comment

end_unit

