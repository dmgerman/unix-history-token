begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* objects.h - MIB objects */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/snmp/RCS/objects.h,v 7.15 91/02/22 09:43:47 mrose Interim $  *  * Contributed by NYSERNet Inc.  This work was partially supported by the  * U.S. Defense Advanced Research Projects Agency and the Rome Air Development  * Center of the U.S. Air Force Systems Command under contract number  * F30602-88-C-0016.  *  *  * $Log:	objects.h,v $  * Revision 7.15  91/02/22  09:43:47  mrose  * Interim 6.8  *   * Revision 7.14  91/01/11  15:34:54  mrose  * sets  *   * Revision 7.13  90/10/29  18:38:41  mrose  * updates  *   * Revision 7.12  90/10/23  20:36:24  mrose  * update  *   * Revision 7.11  90/07/09  14:48:57  mrose  * sync  *   * Revision 7.10  90/06/20  21:38:24  mrose  * update  *   * Revision 7.9  90/06/12  05:19:00  mrose  * again  *   * Revision 7.8  90/06/12  02:05:30  mrose  * views ...  *   * Revision 7.7  90/05/13  16:18:16  mrose  * views  *   * Revision 7.6  90/04/18  08:51:51  mrose  * oid_normalize  *   * Revision 7.5  90/02/23  17:47:47  mrose  * update  *   * Revision 7.4  90/02/19  15:54:07  mrose  * touch-up  *   * Revision 7.3  90/02/19  15:38:43  mrose  * one more time  *   * Revision 7.2  90/02/17  10:38:26  mrose  * smux  *   * Revision 7.1  90/01/11  18:34:27  mrose  * real-sync  *   * Revision 7.0  89/11/23  22:23:20  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEPYPATH
end_ifndef

begin_include
include|#
directive|include
file|<isode/psap.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"psap.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|object_syntax
block|{
name|char
modifier|*
name|os_name
decl_stmt|;
comment|/* syntax name */
name|IFP
name|os_encode
decl_stmt|;
comment|/* data -> PE */
name|IFP
name|os_decode
decl_stmt|;
comment|/* PE -> data */
name|IFP
name|os_free
decl_stmt|;
comment|/* free data */
name|IFP
name|os_parse
decl_stmt|;
comment|/* str -> data */
name|IFP
name|os_print
decl_stmt|;
comment|/* data -> tty */
name|char
modifier|*
modifier|*
name|os_data1
decl_stmt|;
comment|/* for moresyntax() in snmpi... */
name|int
name|os_data2
decl_stmt|;
comment|/*   .. */
block|}
name|object_syntax
operator|,
typedef|*
name|OS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLOS
value|((OS) 0)
end_define

begin_decl_stmt
name|int
name|readsyntax
argument_list|()
decl_stmt|,
name|add_syntax
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OS
name|text2syn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|object_type
block|{
name|char
modifier|*
name|ot_text
decl_stmt|;
comment|/* OBJECT DESCRIPTOR */
name|char
modifier|*
name|ot_id
decl_stmt|;
comment|/* OBJECT IDENTIFIER */
name|OID
name|ot_name
decl_stmt|;
comment|/*   .. */
name|OS
name|ot_syntax
decl_stmt|;
comment|/* SYNTAX */
name|int
name|ot_access
decl_stmt|;
comment|/* ACCESS */
define|#
directive|define
name|OT_NONE
value|0x00
define|#
directive|define
name|OT_RDONLY
value|0x01
define|#
directive|define
name|OT_WRONLY
value|0x02
define|#
directive|define
name|OT_RDWRITE
value|(OT_RDONLY | OT_WRONLY)
name|u_long
name|ot_views
decl_stmt|;
comment|/* for views */
name|int
name|ot_status
decl_stmt|;
comment|/* STATUS */
define|#
directive|define
name|OT_OBSOLETE
value|0x00
define|#
directive|define
name|OT_MANDATORY
value|0x01
define|#
directive|define
name|OT_OPTIONAL
value|0x02
define|#
directive|define
name|OT_DEPRECATED
value|0x03
name|caddr_t
name|ot_info
decl_stmt|;
comment|/* object information */
name|IFP
name|ot_getfnx
decl_stmt|;
comment|/* get/get-next method */
name|IFP
name|ot_setfnx
decl_stmt|;
comment|/* set method */
define|#
directive|define
name|type_SNMP_PDUs_commit
value|(-1)
define|#
directive|define
name|type_SNMP_PDUs_rollback
value|(-2)
name|caddr_t
name|ot_save
decl_stmt|;
comment|/* for set method */
name|caddr_t
name|ot_smux
decl_stmt|;
comment|/* for SMUX */
name|struct
name|object_type
modifier|*
name|ot_chain
decl_stmt|;
comment|/* hash-bucket for text2obj */
name|struct
name|object_type
modifier|*
name|ot_sibling
decl_stmt|;
comment|/* linked-list for name2obj */
name|struct
name|object_type
modifier|*
name|ot_children
decl_stmt|;
comment|/*   .. */
name|struct
name|object_type
modifier|*
name|ot_next
decl_stmt|;
comment|/* linked-list for get-next */
block|}
name|object_type
operator|,
typedef|*
name|OT
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLOT
value|((OT) 0)
end_define

begin_function_decl
name|int
name|readobjects
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|add_objects
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|OT
name|name2obj
argument_list|()
decl_stmt|,
name|text2obj
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OID
name|text2oid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|oid2ode_aux
parameter_list|()
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|object_instance
block|{
name|OID
name|oi_name
decl_stmt|;
comment|/* instance OID */
name|OT
name|oi_type
decl_stmt|;
comment|/* prototype */
block|}
name|object_instance
operator|,
typedef|*
name|OI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLOI
value|((OI) 0)
end_define

begin_decl_stmt
name|OI
name|name2inst
argument_list|()
decl_stmt|,
name|next2inst
argument_list|()
decl_stmt|,
name|text2inst
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|IFP
name|o_advise
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|o_generic
argument_list|()
decl_stmt|,
name|s_generic
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|o_number
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|o_longword
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|o_integer
parameter_list|(
name|oi
parameter_list|,
name|v
parameter_list|,
name|value
parameter_list|)
value|o_longword ((oi), (v), (integer) (value))
end_define

begin_function_decl
name|int
name|o_string
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|o_qbstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|o_specific
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|o_ipaddr
parameter_list|(
name|oi
parameter_list|,
name|v
parameter_list|,
name|value
parameter_list|)
value|o_specific ((oi), (v), (caddr_t) (value))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|o_clnpaddr
parameter_list|(
name|oi
parameter_list|,
name|v
parameter_list|,
name|value
parameter_list|)
value|o_specific ((oi), (v), (caddr_t) (value))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|mediaddr2oid
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ipaddr2oid
parameter_list|(
name|ip
parameter_list|,
name|addr
parameter_list|)
define|\
value|mediaddr2oid ((ip), (u_char*) (addr), sizeof (struct in_addr), 0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|clnpaddr2oid
parameter_list|(
name|ip
parameter_list|,
name|addr
parameter_list|)
define|\
value|mediaddr2oid ((ip), \ 		      (u_char *) (addr) -> isoa_genaddr, \ 		      (int) (addr) -> isoa_len, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|OID
name|oid_extend
argument_list|()
decl_stmt|,
name|oid_normalize
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|PY_pepy
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

end_unit

