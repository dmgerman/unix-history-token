begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: db.h,v 1.67.12.8 2004/05/14 05:06:41 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS_DB_H
end_ifndef

begin_define
define|#
directive|define
name|DNS_DB_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * DNS DB  *  * The DNS DB interface allows named rdatasets to be stored and retrieved.  *  * The dns_db_t type is like a "virtual class".  To actually use  * DBs, an implementation of the class is required.  *  * XXX<more> XXX  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/*****  ***** Imports  *****/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/ondestroy.h>
end_include

begin_include
include|#
directive|include
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<dns/name.h>
end_include

begin_include
include|#
directive|include
file|<dns/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*****  ***** Types  *****/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dns_dbmethods
block|{
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|source
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|beginload
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_addrdatasetfunc_t
modifier|*
name|addp
parameter_list|,
name|dns_dbload_t
modifier|*
modifier|*
name|dbloadp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|endload
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbload_t
modifier|*
modifier|*
name|dbloadp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|dump
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|currentversion
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|newversion
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|attachversion
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|source
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|closeversion
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|,
name|isc_boolean_t
name|commit
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|findnode
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|create
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|find
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|findzonecut
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|attachnode
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|source
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detachnode
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|expirenode
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|printnode
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|createiterator
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_boolean_t
name|relative_names
parameter_list|,
name|dns_dbiterator_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|findrdataset
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|allrdatasets
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdatasetiter_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|addrdataset
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdataset_t
modifier|*
name|addedrdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|subtractrdataset
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdataset_t
modifier|*
name|newrdataset
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|deleterdataset
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|issecure
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|nodecount
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|ispersistent
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|overmem
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_boolean_t
name|overmem
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|settask
function_decl|)
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_task_t
modifier|*
parameter_list|)
function_decl|;
block|}
name|dns_dbmethods_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|dns_dbcreatefunc_t
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_dbtype_t
name|type
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|unsigned
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|DNS_DB_MAGIC
value|ISC_MAGIC('D','N','S','D')
end_define

begin_define
define|#
directive|define
name|DNS_DB_VALID
parameter_list|(
name|db
parameter_list|)
value|ISC_MAGIC_VALID(db, DNS_DB_MAGIC)
end_define

begin_comment
comment|/*  * This structure is actually just the common prefix of a DNS db  * implementation's version of a dns_db_t.  *  * Direct use of this structure by clients is forbidden.  DB implementations  * may change the structure.  'magic' must be DNS_DB_MAGIC for any of the  * dns_db_ routines to work.  DB implementations must maintain all DB  * invariants.  */
end_comment

begin_struct
struct|struct
name|dns_db
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|dns_dbmethods_t
modifier|*
name|methods
decl_stmt|;
name|isc_uint16_t
name|attributes
decl_stmt|;
name|dns_rdataclass_t
name|rdclass
decl_stmt|;
name|dns_name_t
name|origin
decl_stmt|;
name|isc_ondestroy_t
name|ondest
decl_stmt|;
name|isc_mem_t
modifier|*
name|mctx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DNS_DBATTR_CACHE
value|0x01
end_define

begin_define
define|#
directive|define
name|DNS_DBATTR_STUB
value|0x02
end_define

begin_comment
comment|/*  * Options that can be specified for dns_db_find().  */
end_comment

begin_define
define|#
directive|define
name|DNS_DBFIND_GLUEOK
value|0x01
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_VALIDATEGLUE
value|0x02
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_NOWILD
value|0x04
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_PENDINGOK
value|0x08
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_NOEXACT
value|0x10
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_FORCENSEC
value|0x20
end_define

begin_define
define|#
directive|define
name|DNS_DBFIND_COVERINGNSEC
value|0x40
end_define

begin_comment
comment|/*  * Options that can be specified for dns_db_addrdataset().  */
end_comment

begin_define
define|#
directive|define
name|DNS_DBADD_MERGE
value|0x01
end_define

begin_define
define|#
directive|define
name|DNS_DBADD_FORCE
value|0x02
end_define

begin_define
define|#
directive|define
name|DNS_DBADD_EXACT
value|0x04
end_define

begin_define
define|#
directive|define
name|DNS_DBADD_EXACTTTL
value|0x08
end_define

begin_comment
comment|/*  * Options that can be specified for dns_db_subtractrdataset().  */
end_comment

begin_define
define|#
directive|define
name|DNS_DBSUB_EXACT
value|0x01
end_define

begin_comment
comment|/*****  ***** Methods  *****/
end_comment

begin_comment
comment|/***  *** Basic DB Methods  ***/
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
specifier|const
name|char
modifier|*
name|db_type
parameter_list|,
name|dns_name_t
modifier|*
name|origin
parameter_list|,
name|dns_dbtype_t
name|type
parameter_list|,
name|dns_rdataclass_t
name|rdclass
parameter_list|,
name|unsigned
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create a new database using implementation 'db_type'.  *  * Notes:  *	All names in the database must be subdomains of 'origin' and in class  *	'rdclass'.  The database makes its own copy of the origin, so the  *	caller may do whatever they like with 'origin' and its storage once the  *	call returns.  *  *	DB implementation-specific parameters are passed using argc and argv.  *  * Requires:  *  *	dbp != NULL and *dbp == NULL  *  *	'origin' is a valid absolute domain name.  *  *	mctx is a valid memory context  *  * Ensures:  *  *	A copy of 'origin' has been made for the databases use, and the  *	caller is free to do whatever they want with the name and storage  *	associated with 'origin'.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_NOTFOUND				db_type not found  *  *	Many other errors are possible, depending on what db_type was  *	specified.  */
end_comment

begin_function_decl
name|void
name|dns_db_attach
parameter_list|(
name|dns_db_t
modifier|*
name|source
parameter_list|,
name|dns_db_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to source.  *  * Requires:  *  *	'source' is a valid database.  *  *	'targetp' points to a NULL dns_db_t *.  *  * Ensures:  *  *	*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_db_detach
parameter_list|(
name|dns_db_t
modifier|*
modifier|*
name|dbp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *dbp from its database.  *  * Requires:  *  *	'dbp' points to a valid database.  *  * Ensures:  *  *	*dbp is NULL.  *  *	If '*dbp' is the last reference to the database,  *  *		All resources used by the database will be freed  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_ondestroy
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Causes 'eventp' to be sent to be sent to 'task' when the database is  * destroyed.  *  * Note; ownership of the eventp is taken from the caller (and *eventp is  * set to NULL). The sender field of the event is set to 'db' before it is  * sent to the task.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_db_iscache
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Does 'db' have cache semantics?  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *	ISC_TRUE	'db' has cache semantics  *	ISC_FALSE	otherwise  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_db_iszone
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Does 'db' have zone semantics?  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *	ISC_TRUE	'db' has zone semantics  *	ISC_FALSE	otherwise  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_db_isstub
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Does 'db' have stub semantics?  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *	ISC_TRUE	'db' has zone semantics  *	ISC_FALSE	otherwise  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_db_issecure
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Is 'db' secure?  *  * Requires:  *  *	'db' is a valid database with zone semantics.  *  * Returns:  *	ISC_TRUE	'db' is secure.  *	ISC_FALSE	'db' is not secure.  */
end_comment

begin_function_decl
name|dns_name_t
modifier|*
name|dns_db_origin
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The origin of the database.  *  * Note: caller must not try to change this name.  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *  *	The origin of the database.  */
end_comment

begin_function_decl
name|dns_rdataclass_t
name|dns_db_class
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The class of the database.  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *  *	The class of the database.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_beginload
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_addrdatasetfunc_t
modifier|*
name|addp
parameter_list|,
name|dns_dbload_t
modifier|*
modifier|*
name|dbloadp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Begin loading 'db'.  *  * Requires:  *  *	'db' is a valid database.  *  *	This is the first attempt to load 'db'.  *  *	addp != NULL&& *addp == NULL  *  *	dbloadp != NULL&& *dbloadp == NULL  *  * Ensures:  *  *	On success, *addp will be a valid dns_addrdatasetfunc_t suitable  *	for loading 'db'.  *dbloadp will be a valid DB load context which  *	should be used as 'arg' when *addp is called.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other results are possible, depending upon the database  *	implementation used, syntax errors in the master file, etc.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_endload
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbload_t
modifier|*
modifier|*
name|dbloadp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Finish loading 'db'.  *  * Requires:  *  *	'db' is a valid database that is being loaded.  *  *	dbloadp != NULL and *dbloadp is a valid database load context.  *  * Ensures:  *  *	*dbloadp == NULL  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other results are possible, depending upon the database  *	implementation used, syntax errors in the master file, etc.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_load
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Load master file 'filename' into 'db'.  *  * Notes:  *	This routine is equivalent to calling  *  *		dns_db_beginload();  *		dns_master_loadfile();  *		dns_db_endload();  *  * Requires:  *  *	'db' is a valid database.  *  *	This is the first attempt to load 'db'.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other results are possible, depending upon the database  *	implementation used, syntax errors in the master file, etc.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_dump
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Dump version 'version' of 'db' to master file 'filename'.  *  * Requires:  *  *	'db' is a valid database.  *  *	'version' is a valid version.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other results are possible, depending upon the database  *	implementation used, OS file errors, etc.  */
end_comment

begin_comment
comment|/***  *** Version Methods  ***/
end_comment

begin_function_decl
name|void
name|dns_db_currentversion
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Open the current version for reading.  *  * Requires:  *  *	'db' is a valid database with zone semantics.  *  *	versionp != NULL&& *verisonp == NULL  *  * Ensures:  *  *	On success, '*versionp' is attached to the current version.  *  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_newversion
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Open a new version for reading and writing.  *  * Requires:  *  *	'db' is a valid database with zone semantics.  *  *	versionp != NULL&& *verisonp == NULL  *  * Ensures:  *  *	On success, '*versionp' is attached to the current version.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|void
name|dns_db_attachversion
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|source
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach '*targetp' to 'source'.  *  * Requires:  *  *	'db' is a valid database with zone semantics.  *  *	source is a valid open version  *  *	targetp != NULL&& *targetp == NULL  *  * Ensures:  *  *	'*targetp' is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_db_closeversion
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
modifier|*
name|versionp
parameter_list|,
name|isc_boolean_t
name|commit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Close version '*versionp'.  *  * Note: if '*versionp' is a read-write version and 'commit' is ISC_TRUE,  * then all changes made in the version will take effect, otherwise they  * will be rolled back.  The value if 'commit' is ignored for read-only  * versions.  *  * Requires:  *  *	'db' is a valid database with zone semantics.  *  *	'*versionp' refers to a valid version.  *  *	If committing a writable version, then there must be no other  *	outstanding references to the version (e.g. an active rdataset  *	iterator).  *  * Ensures:  *  *	*versionp == NULL  *  *	If *versionp is a read-write version, and commit is ISC_TRUE, then  *	the version will become the current version.  If !commit, then all  *	changes made in the version will be undone, and the version will  *	not become the current version.  */
end_comment

begin_comment
comment|/***  *** Node Methods  ***/
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_findnode
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|isc_boolean_t
name|create
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the node with name 'name'.  *  * Notes:  *	If 'create' is ISC_TRUE and no node with name 'name' exists, then  *	such a node will be created.  *  *	This routine is for finding or creating a node with the specified  *	name.  There are no partial matches.  It is not suitable for use  *	in building responses to ordinary DNS queries; clients which wish  *	to do that should use dns_db_find() instead.  *  * Requires:  *  *	'db' is a valid database.  *  *	'name' is a valid, non-empty, absolute name.  *  *	nodep != NULL&& *nodep == NULL  *  * Ensures:  *  *	On success, *nodep is attached to the node with name 'name'.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND			If !create and name not found.  *	ISC_R_NOMEMORY		        Can only happen if create is ISC_TRUE.  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_find
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the best match for 'name' and 'type' in version 'version' of 'db'.  *  * Notes:  *  *	If type == dns_rdataset_any, then rdataset will not be bound.  *  *	If 'options' does not have DNS_DBFIND_GLUEOK set, then no glue will  *	be returned.  For zone databases, glue is as defined in RFC 2181.  *	For cache databases, glue is any rdataset with a trust of  *	dns_trust_glue.  *  *	If 'options' does not have DNS_DBFIND_PENDINGOK set, then no  *	pending data will be returned.  This option is only meaningful for  *	cache databases.  *  *	If the DNS_DBFIND_NOWILD option is set, then wildcard matching will  *	be disabled.  This option is only meaningful for zone databases.  *  *	If the DNS_DBFIND_FORCENSEC option is set, the database is assumed to  *	have NSEC records, and these will be returned when appropriate.  This  *	is only necessary when querying a database that was not secure  *	when created.  *  *	If the DNS_DBFIND_COVERINGNSEC option is set, then look for a  *	NSEC record that potentially covers 'name' if a answer cannot  *	be found.  Note the returned NSEC needs to be checked to ensure  *	that it is correct.  This only affects answers returned from the  *	cache.  *  *	To respond to a query for SIG records, the caller should create a  *	rdataset iterator and extract the signatures from each rdataset.  *  *	Making queries of type ANY with DNS_DBFIND_GLUEOK is not recommended,  *	because the burden of determining whether a given rdataset is valid  *	glue or not falls upon the caller.  *  *	The 'now' field is ignored if 'db' is a zone database.  If 'db' is a  *	cache database, an rdataset will not be found unless it expires after  *	'now'.  Any ANY query will not match unless at least one rdataset at  *	the node expires after 'now'.  If 'now' is zero, then the current time  *	will be used.  *  * Requires:  *  *	'db' is a valid database.  *  *	'type' is not SIG, or a meta-RR type other than 'ANY' (e.g. 'OPT').  *  *	'nodep' is NULL, or nodep is a valid pointer and *nodep == NULL.  *  *	'foundname' is a valid name with a dedicated buffer.  *  *	'rdataset' is NULL, or is a valid unassociated rdataset.  *  * Ensures:  *	On a non-error completion:  *  *		If nodep != NULL, then it is bound to the found node.  *  *		If foundname != NULL, then it contains the full name of the  *		found node.  *  *		If rdataset != NULL and type != dns_rdatatype_any, then  *		rdataset is bound to the found rdataset.  *  * Returns:  *  *	Non-error results are:  *  *		ISC_R_SUCCESS			The desired node and type were  *						found.  *  *		DNS_R_WILDCARD			The desired node and type were  *						found after performing  *						wildcard matching.  This is  *						only returned if the  *						DNS_DBFIND_INDICATEWILD  *						option is set; otherwise  *						ISC_R_SUCCESS is returned.  *  *		DNS_R_GLUE			The desired node and type were  *						found, but are glue.  This  *						result can only occur if  *						the DNS_DBFIND_GLUEOK option  *						is set.  This result can only  *						occur if 'db' is a zone  *						database.  If type ==  *						dns_rdatatype_any, then the  *						node returned may contain, or  *						consist entirely of invalid  *						glue (i.e. data occluded by a  *						zone cut).  The caller must  *						take care not to return invalid  *						glue to a client.  *  *		DNS_R_DELEGATION		The data requested is beneath  *						a zone cut.  node, foundname,  *						and rdataset reference the  *						NS RRset of the zone cut.  *						If 'db' is a cache database,  *						then this is the deepest known  *						delegation.  *  *		DNS_R_ZONECUT			type == dns_rdatatype_any, and  *						the desired node is a zonecut.  *						The caller must take care not  *						to return inappropriate glue  *						to a client.  This result can  *						only occur if 'db' is a zone  *						database and DNS_DBFIND_GLUEOK  *						is set.  *  *		DNS_R_DNAME			The data requested is beneath  *						a DNAME.  node, foundname,  *						and rdataset reference the  *						DNAME RRset.  *  *		DNS_R_CNAME			The rdataset requested was not  *						found, but there is a CNAME  *						at the desired name.  node,  *						foundname, and rdataset  *						reference the CNAME RRset.  *  *		DNS_R_NXDOMAIN			The desired name does not  *						exist.  *  *		DNS_R_NXRRSET			The desired name exists, but  *						the desired type does not.  *  *		ISC_R_NOTFOUND			The desired name does not  *						exist, and no delegation could  *						be found.  This result can only  *						occur if 'db' is a cache  *						database.  The caller should  *						use its nameserver(s) of last  *						resort (e.g. root hints).  *  *		DNS_R_NCACHENXDOMAIN		The desired name does not  *						exist.  'node' is bound to the  *						cache node with the desired  *						name, and 'rdataset' contains  *						the negative caching proof.  *  *		DNS_R_NCACHENXRRSET		The desired type does not  *						exist.  'node' is bound to the  *						cache node with the desired  *						name, and 'rdataset' contains  *						the negative caching proof.  *  *		DNS_R_EMPTYNAME			The name exists but there is  *						no data at the name.   *  *		DNS_R_COVERINGNSEC		The returned data is a NSEC  *						that potentially covers 'name'.  *  *	Error results:  *  *		ISC_R_NOMEMORY  *  *		DNS_R_BADDB			Data that is required to be  *						present in the DB, e.g. an NSEC  *						record in a secure zone, is not  *						present.  *  *		Other results are possible, and should all be treated as  *		errors.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_findzonecut
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_name_t
modifier|*
name|name
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|,
name|dns_name_t
modifier|*
name|foundname
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Find the deepest known zonecut which encloses 'name' in 'db'.  *  * Notes:  *  *	If the DNS_DBFIND_NOEXACT option is set, then the zonecut returned  *	(if any) will be the deepest known ancestor of 'name'.  *  *	If 'now' is zero, then the current time will be used.  *  * Requires:  *  *	'db' is a valid database with cache semantics.  *  *	'nodep' is NULL, or nodep is a valid pointer and *nodep == NULL.  *  *	'foundname' is a valid name with a dedicated buffer.  *  *	'rdataset' is NULL, or is a valid unassociated rdataset.  *  * Ensures:  *	On a non-error completion:  *  *		If nodep != NULL, then it is bound to the found node.  *  *		If foundname != NULL, then it contains the full name of the  *		found node.  *  *		If rdataset != NULL and type != dns_rdatatype_any, then  *		rdataset is bound to the found rdataset.  *  * Returns:  *  *	Non-error results are:  *  *		ISC_R_SUCCESS  *  *		ISC_R_NOTFOUND  *  *		Other results are possible, and should all be treated as  *		errors.  */
end_comment

begin_function_decl
name|void
name|dns_db_attachnode
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|source
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Attach *targetp to source.  *  * Requires:  *  *	'db' is a valid database.  *  *	'source' is a valid node.  *  *	'targetp' points to a NULL dns_node_t *.  *  * Ensures:  *  *	*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|dns_db_detachnode
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
modifier|*
name|nodep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Detach *nodep from its node.  *  * Requires:  *  *	'db' is a valid database.  *  *	'nodep' points to a valid node.  *  * Ensures:  *  *	*nodep is NULL.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_expirenode
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Mark as stale all records at 'node' which expire at or before 'now'.  *  * Note: if 'now' is zero, then the current time will be used.  *  * Requires:  *  *	'db' is a valid cache database.  *  *	'node' is a valid node.  */
end_comment

begin_function_decl
name|void
name|dns_db_printnode
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|FILE
modifier|*
name|out
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Print a textual representation of the contents of the node to  * 'out'.  *  * Note: this function is intended for debugging, not general use.  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  */
end_comment

begin_comment
comment|/***  *** DB Iterator Creation  ***/
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_createiterator
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_boolean_t
name|relative_names
parameter_list|,
name|dns_dbiterator_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Create an iterator for version 'version' of 'db'.  *  * Notes:  *  *	If 'relative_names' is ISC_TRUE, then node names returned by the  *	iterator will be relative to the iterator's current origin.  If  *	ISC_FALSE, then the node names will be absolute.  *  * Requires:  *  *	'db' is a valid database.  *  *	iteratorp != NULL&& *iteratorp == NULL  *  * Ensures:  *  *	On success, *iteratorp will be a valid database iterator.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_comment
comment|/***  *** Rdataset Methods  ***/
end_comment

begin_comment
comment|/*  * XXXRTH  Should we check for glue and pending data in dns_db_findrdataset()?  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_findrdataset
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|dns_rdataset_t
modifier|*
name|sigrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Search for an rdataset of type 'type' at 'node' that are in version  * 'version' of 'db'.  If found, make 'rdataset' refer to it.  *  * Notes:  *  *	If 'version' is NULL, then the current version will be used.  *  *	Care must be used when using this routine to build a DNS response:  *	'node' should have been found with dns_db_find(), not  *	dns_db_findnode().  No glue checking is done.  No checking for  *	pending data is done.  *  *	The 'now' field is ignored if 'db' is a zone database.  If 'db' is a  *	cache database, an rdataset will not be found unless it expires after  *	'now'.  If 'now' is zero, then the current time will be used.  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  *  *	'rdataset' is a valid, disassociated rdataset.  *  *	'sigrdataset' is a valid, disassociated rdataset, or it is NULL.  *  *	If 'covers' != 0, 'type' must be SIG.  *  *	'type' is not a meta-RR type such as 'ANY' or 'OPT'.  *  * Ensures:  *  *	On success, 'rdataset' is associated with the found rdataset.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_allrdatasets
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdatasetiter_t
modifier|*
modifier|*
name|iteratorp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make '*iteratorp' an rdataset iteratator for all rdatasets at 'node' in  * version 'version' of 'db'.  *  * Notes:  *  *	If 'version' is NULL, then the current version will be used.  *  *	The 'now' field is ignored if 'db' is a zone database.  If 'db' is a  *	cache database, an rdataset will not be found unless it expires after  *	'now'.  Any ANY query will not match unless at least one rdataset at  *	the node expires after 'now'.  If 'now' is zero, then the current time  *	will be used.  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  *  *	iteratorp != NULL&& *iteratorp == NULL  *  * Ensures:  *  *	On success, '*iteratorp' is a valid rdataset iterator.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOTFOUND  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_addrdataset
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|isc_stdtime_t
name|now
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdataset_t
modifier|*
name|addedrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Add 'rdataset' to 'node' in version 'version' of 'db'.  *  * Notes:  *  *	If the database has zone semantics, the DNS_DBADD_MERGE option is set,  *	and an rdataset of the same type as 'rdataset' already exists at  *	'node' then the contents of 'rdataset' will be merged with the existing  *	rdataset.  If the option is not set, then rdataset will replace any  *	existing rdataset of the same type.  If not merging and the  *	DNS_DBADD_FORCE option is set, then the data will update the database  *	without regard to trust levels.  If not forcing the data, then the  *	rdataset will only be added if its trust level is>= the trust level of  *	any existing rdataset.  Forcing is only meaningful for cache databases.  *	If DNS_DBADD_EXACT is set then there must be no rdata in common between  *	the old and new rdata sets.  If DNS_DBADD_EXACTTTL is set then both  *	the old and new rdata sets must have the same ttl.  *  *	The 'now' field is ignored if 'db' is a zone database.  If 'db' is  *	a cache database, then the added rdataset will expire no later than  *	now + rdataset->ttl.  *  *	If 'addedrdataset' is not NULL, then it will be attached to the  *	resulting new rdataset in the database, or to the existing data if  *	the existing data was better.  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  *  *	'rdataset' is a valid, associated rdataset with the same class  *	as 'db'.  *  *	'addedrdataset' is NULL, or a valid, unassociated rdataset.  *  *	The database has zone semantics and 'version' is a valid  *	read-write version, or the database has cache semantics  *	and version is NULL.  *  *	If the database has cache semantics, the DNS_DBADD_MERGE option must  *	not be set.  *  * Returns:  *  *	ISC_R_SUCCESS  *	DNS_R_UNCHANGED			The operation did not change anything.  *	ISC_R_NOMEMORY  *	DNS_R_NOTEXACT  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_subtractrdataset
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdataset_t
modifier|*
name|rdataset
parameter_list|,
name|unsigned
name|int
name|options
parameter_list|,
name|dns_rdataset_t
modifier|*
name|newrdataset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Remove any rdata in 'rdataset' from 'node' in version 'version' of  * 'db'.  *  * Notes:  *  *	If 'newrdataset' is not NULL, then it will be attached to the  *	resulting new rdataset in the database, unless the rdataset has  *	become nonexistent.  If DNS_DBSUB_EXACT is set then all elements  *	of 'rdataset' must exist at 'node'.  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  *  *	'rdataset' is a valid, associated rdataset with the same class  *	as 'db'.  *  *	'newrdataset' is NULL, or a valid, unassociated rdataset.  *  *	The database has zone semantics and 'version' is a valid  *	read-write version.  *  * Returns:  *  *	ISC_R_SUCCESS  *	DNS_R_UNCHANGED			The operation did not change anything.  *	DNS_R_NXRRSET			All rdata of the same type as those  *					in 'rdataset' have been deleted.  *	DNS_R_NOTEXACT			Some part of 'rdataset' did not  *					exist and DNS_DBSUB_EXACT was set.  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_deleterdataset
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbnode_t
modifier|*
name|node
parameter_list|,
name|dns_dbversion_t
modifier|*
name|version
parameter_list|,
name|dns_rdatatype_t
name|type
parameter_list|,
name|dns_rdatatype_t
name|covers
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make it so that no rdataset of type 'type' exists at 'node' in version  * version 'version' of 'db'.  *  * Notes:  *  *	If 'type' is dns_rdatatype_any, then no rdatasets will exist in  *	'version' (provided that the dns_db_deleterdataset() isn't followed  *	by one or more dns_db_addrdataset() calls).  *  * Requires:  *  *	'db' is a valid database.  *  *	'node' is a valid node.  *  *	The database has zone semantics and 'version' is a valid  *	read-write version, or the database has cache semantics  *	and version is NULL.  *  *	'type' is not a meta-RR type, except for dns_rdatatype_any, which is  *	allowed.  *  *	If 'covers' != 0, 'type' must be SIG.  *  * Returns:  *  *	ISC_R_SUCCESS  *	DNS_R_UNCHANGED			No rdatasets of 'type' existed before  *					the operation was attempted.  *  *	Other results are possible, depending upon the database  *	implementation used.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_getsoaserial
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|dns_dbversion_t
modifier|*
name|ver
parameter_list|,
name|isc_uint32_t
modifier|*
name|serialp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Get the current SOA serial number from a zone database.  *  * Requires:  *      'db' is a valid database with zone semantics.  *      'ver' is a valid version.  */
end_comment

begin_function_decl
name|void
name|dns_db_overmem
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_boolean_t
name|overmem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Enable / disable agressive cache cleaning.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|dns_db_nodecount
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Count the number of nodes in 'db'.  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  * 	The number of nodes in the database  */
end_comment

begin_function_decl
name|void
name|dns_db_settask
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If task is set then the final detach maybe performed asynchronously.  *  * Requires:  *	'db' is a valid database.  *	'task' to be valid or NULL.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|dns_db_ispersistent
parameter_list|(
name|dns_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Is 'db' persistent?  A persistent database does not need to be loaded  * from disk or written to disk.  *  * Requires:  *  *	'db' is a valid database.  *  * Returns:  *	ISC_TRUE	'db' is persistent.  *	ISC_FALSE	'db' is not persistent.  */
end_comment

begin_function_decl
name|isc_result_t
name|dns_db_register
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|dns_dbcreatefunc_t
name|create
parameter_list|,
name|void
modifier|*
name|driverarg
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|dns_dbimplementation_t
modifier|*
modifier|*
name|dbimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Register a new database implementation and add it to the list of  * supported implementations.  *  * Requires:  *  * 	'name' is not NULL  * 	'order' is a valid function pointer  * 	'mctx' is a valid memory context  * 	dbimp != NULL&& *dbimp == NULL  *  * Returns:  * 	ISC_R_SUCCESS	The registration succeeded  * 	ISC_R_NOMEMORY	Out of memory  * 	ISC_R_EXISTS	A database implementation with the same name exists  *  * Ensures:  *  *	*dbimp points to an opaque structure which must be passed to  *	dns_db_unregister().  */
end_comment

begin_function_decl
name|void
name|dns_db_unregister
parameter_list|(
name|dns_dbimplementation_t
modifier|*
modifier|*
name|dbimp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Remove a database implementation from the the list of supported  * implementations.  No databases of this type can be active when this  * is called.  *  * Requires:  * 	dbimp != NULL&& *dbimp == NULL  *  * Ensures:  *  * 	Any memory allocated in *dbimp will be freed.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS_DB_H */
end_comment

end_unit

