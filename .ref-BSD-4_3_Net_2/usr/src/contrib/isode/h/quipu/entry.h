begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* entry.h - */
end_comment

begin_comment
comment|/*  * $Header: /f/osi/h/quipu/RCS/entry.h,v 7.3 91/03/09 11:54:08 mrose Exp $  *  *  * $Log:	entry.h,v $  * Revision 7.3  91/03/09  11:54:08  mrose  * update  *   * Revision 7.2  91/02/22  09:25:53  mrose  * Interim 6.8  *   * Revision 7.1  90/10/17  11:46:28  mrose  * sync  *   * Revision 7.0  89/11/23  21:56:36  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUIPUENTRY
end_ifndef

begin_define
define|#
directive|define
name|QUIPUENTRY
end_define

begin_include
include|#
directive|include
file|"quipu/config.h"
end_include

begin_include
include|#
directive|include
file|"quipu/attrvalue.h"
end_include

begin_include
include|#
directive|include
file|"quipu/dsp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_AVL
end_ifdef

begin_include
include|#
directive|include
file|"quipu/turbo.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|acl_attr
block|{
name|struct
name|oid_seq
modifier|*
name|aa_types
decl_stmt|;
name|struct
name|acl_info
modifier|*
name|aa_acl
decl_stmt|;
name|struct
name|acl_attr
modifier|*
name|aa_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLACL_ATTR
value|((struct acl_attr *)0)
end_define

begin_define
define|#
directive|define
name|acl_attr_alloc
parameter_list|()
value|(struct acl_attr *) smalloc (sizeof (struct acl_attr));
end_define

begin_function_decl
name|struct
name|acl_attr
modifier|*
name|acl_attr_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|acl
block|{
comment|/* represents ACL                       */
name|struct
name|acl_info
modifier|*
name|ac_child
decl_stmt|;
name|struct
name|acl_info
modifier|*
name|ac_entry
decl_stmt|;
name|struct
name|acl_info
modifier|*
name|ac_default
decl_stmt|;
name|struct
name|acl_attr
modifier|*
name|ac_attributes
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|acl_alloc
parameter_list|()
value|(struct acl *) smalloc (sizeof (struct acl));
end_define

begin_define
define|#
directive|define
name|NULLACL
value|(struct acl *)NULL
end_define

begin_function_decl
name|struct
name|acl
modifier|*
name|acl_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|acl
modifier|*
name|str2acl
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Entry is the structure which is used to hold the DIT in core         */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|entry
block|{
comment|/* First components refer to the entry  */
comment|/* itself                               */
name|RDN
name|e_name
decl_stmt|;
name|Attr_Sequence
name|e_attributes
decl_stmt|;
comment|/* the attributes of the entry          */
comment|/* ALL attributes held, including the   */
comment|/* special ones                         */
name|InheritAttr
name|e_iattr
decl_stmt|;
comment|/* Attributes to inherit into the entry */
comment|/* MAYBE specials			*/
name|char
name|e_leaf
decl_stmt|;
comment|/* TRUE if entry is leaf                */
name|char
name|e_complete
decl_stmt|;
comment|/* TRUE if all attributes present       */
name|char
name|e_data
decl_stmt|;
comment|/* Info on data in entry                */
define|#
directive|define
name|E_DATA_MASTER
value|1
define|#
directive|define
name|E_TYPE_SLAVE
value|2
define|#
directive|define
name|E_TYPE_CACHE_FROM_MASTER
value|3
define|#
directive|define
name|E_TYPE_CONSTRUCTOR
value|4
name|char
name|e_allchildrenpresent
decl_stmt|;
comment|/* set  FALSE if none                   */
comment|/* else 1 if children at onelevel	*/
comment|/*> 1 imples subtree			*/
comment|/* structures referring to special      */
comment|/* attributes in the entry              */
name|struct
name|acl
modifier|*
name|e_acl
decl_stmt|;
comment|/* The ACL for the entry                */
name|DN
name|e_alias
decl_stmt|;
comment|/* if present, entry is alias           */
name|struct
name|dsa_info
modifier|*
name|e_dsainfo
decl_stmt|;
comment|/* only present if entry represents DSA */
comment|/* Second block refer to children of    */
comment|/* entry                                */
name|char
modifier|*
name|e_edbversion
decl_stmt|;
comment|/* only present for non leaf - non-cache */
comment|/* this refers to all the child entries  */
comment|/* NULL if edb is not held               */
name|AV_Sequence
name|e_oc
decl_stmt|;
comment|/* Objectclass attribute		*/
name|AV_Sequence
name|e_inherit
decl_stmt|;
comment|/* COPY of inherit attribute		*/
comment|/* Final block is the linkage of the    */
comment|/* structure to the tree                */
comment|/* across the tree                      */
name|struct
name|entry
modifier|*
name|e_parent
decl_stmt|;
ifdef|#
directive|ifdef
name|TURBO_AVL
name|Avlnode
modifier|*
name|e_children
decl_stmt|;
else|#
directive|else
name|struct
name|entry
modifier|*
name|e_sibling
decl_stmt|;
name|struct
name|entry
modifier|*
name|e_child
decl_stmt|;
endif|#
directive|endif
name|time_t
name|e_age
decl_stmt|;
comment|/* time entry created (for cache use only) */
name|char
name|e_lock
decl_stmt|;
comment|/* TRUE if EDB locked -> no write to disk */
name|char
name|e_external
decl_stmt|;
comment|/* 0 -> Quipu, 1 -> External */
union|union
block|{
struct|struct
block|{
name|AV_Sequence
name|un_master
decl_stmt|;
comment|/* Master DSA(s) of EDB                 */
name|AV_Sequence
name|un_slave
decl_stmt|;
comment|/* Slave DSAs of EDB                    */
block|}
name|un_in
struct|;
struct|struct
block|{
name|int
name|un_reftype
decl_stmt|;
name|AV_Sequence
name|un_reference
decl_stmt|;
block|}
name|un_out
struct|;
block|}
name|e_un
union|;
name|int
name|e_refcount
decl_stmt|;
comment|/* How many things pointing to it */
define|#
directive|define
name|e_master
value|e_un.un_in.un_master
define|#
directive|define
name|e_slave
value|e_un.un_in.un_slave
define|#
directive|define
name|e_reference
value|e_un.un_out.un_reference
define|#
directive|define
name|e_reftype
value|e_un.un_out.un_reftype
block|}
name|entry
operator|,
typedef|*
name|Entry
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLENTRY
value|((Entry)0)
end_define

begin_define
define|#
directive|define
name|entry_alloc
parameter_list|()
value|(Entry) calloc (1,sizeof(entry));
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_AVL
end_ifdef

begin_function_decl
name|Avlnode
modifier|*
name|getentry_block
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|Entry
name|getentry_block
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|Entry
name|directory_load
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_master_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|really_find_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Entry
name|local_find_entry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|Entry
name|get_default_entry
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|TURBO_AVL
end_ifdef

begin_define
define|#
directive|define
name|isleaf
parameter_list|(
name|x
parameter_list|)
value|((x)->e_leaf || \ 		((x)->e_children == NULLAVL&& \ 		(x)->e_allchildrenpresent != FALSE))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|isleaf
parameter_list|(
name|x
parameter_list|)
value|((x)->e_leaf || \ 		((x)->e_child == NULLENTRY&& \ 		(x)->e_allchildrenpresent != FALSE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|oid_seq
block|{
name|OID
name|oid_oid
decl_stmt|;
name|struct
name|oid_seq
modifier|*
name|oid_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLOIDSEQ
value|((struct oid_seq*) 0)
end_define

begin_define
define|#
directive|define
name|oid_seq_alloc
parameter_list|()
value|(struct oid_seq  *) smalloc (sizeof (struct oid_seq))
end_define

begin_function_decl
name|struct
name|oid_seq
modifier|*
name|oid_seq_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|oid_seq
modifier|*
name|oid_seq_merge
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|tree_struct
block|{
comment|/* represents TreeStructure             */
name|objectclass
modifier|*
name|tree_object
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLTREE
value|((struct tree_struct *)0)
end_define

begin_define
define|#
directive|define
name|tree_struct_alloc
parameter_list|()
value|(struct tree_struct *) smalloc (sizeof (struct tree_struct))
end_define

begin_function_decl
name|struct
name|tree_struct
modifier|*
name|tree_struct_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tree_struct
modifier|*
name|str2schema
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|dn_seq
block|{
name|DN
name|dns_dn
decl_stmt|;
name|struct
name|dn_seq
modifier|*
name|dns_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLDNSEQ
value|((struct dn_seq *)  0)
end_define

begin_define
define|#
directive|define
name|dn_seq_alloc
parameter_list|()
value|(struct dn_seq *) smalloc (sizeof (struct dn_seq))
end_define

begin_function_decl
name|struct
name|dn_seq
modifier|*
name|dn_seq_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dn_seq
modifier|*
name|str2dnseq
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|dsa_info
block|{
comment|/* represents DSA information           */
comment|/* UpdateInfoSyntax                     */
name|struct
name|PSAPaddr
modifier|*
name|dsa_addr
decl_stmt|;
comment|/* type from ISODE                      */
comment|/* might need to allow for multiple     */
comment|/* addresses, but not now               */
comment|/* also OR Address                      */
comment|/* leave for now                        */
comment|/* List of EDBs handled                 */
comment|/* by this dsa                          */
name|AV_Sequence
name|dsa_attr
decl_stmt|;
name|char
modifier|*
name|dsa_version
decl_stmt|;
comment|/* info to assess reliability of a DSA */
name|time_t
name|dsa_last_success
decl_stmt|;
name|time_t
name|dsa_last_attempt
decl_stmt|;
name|int
name|dsa_failures
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLDSA
value|((struct dsa_info *)0)
end_define

begin_define
define|#
directive|define
name|dsa_info_alloc
parameter_list|()
value|(struct dsa_info *) smalloc (sizeof (struct dsa_info));
end_define

begin_struct
struct|struct
name|edb_info
block|{
comment|/* represent EDBInfo                    */
name|DN
name|edb_name
decl_stmt|;
name|DN
name|edb_getfrom
decl_stmt|;
comment|/* DSA I get EDBupdates from            */
name|struct
name|dn_seq
modifier|*
name|edb_sendto
decl_stmt|;
comment|/* where I send EDB updates to          */
name|struct
name|dn_seq
modifier|*
name|edb_allowed
decl_stmt|;
comment|/* Who is allowed updates */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLEDB
value|((struct edb_info *) 0)
end_define

begin_define
define|#
directive|define
name|edb_info_alloc
parameter_list|()
value|(struct edb_info *) smalloc (sizeof (struct edb_info));
end_define

begin_function_decl
name|struct
name|edb_info
modifier|*
name|edb_info_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|edb_info
modifier|*
name|str2update
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|DN
name|get_copy_dn
parameter_list|()
function_decl|;
end_function_decl

begin_struct
struct|struct
name|getedb_arg
block|{
name|DN
name|ga_entry
decl_stmt|;
name|char
modifier|*
name|ga_version
decl_stmt|;
name|struct
name|getedb_arg
modifier|*
name|get_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_GETARG
value|(struct getedb_arg *) NULL
end_define

begin_struct
struct|struct
name|getedb_result
block|{
name|char
modifier|*
name|gr_version
decl_stmt|;
ifdef|#
directive|ifdef
name|TURBO_AVL
name|Avlnode
modifier|*
name|gr_edb
decl_stmt|;
else|#
directive|else
name|Entry
name|gr_edb
decl_stmt|;
endif|#
directive|endif
name|struct
name|getedb_result
modifier|*
name|gr_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULL_GETRESULT
value|(struct getedb_result *) NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

