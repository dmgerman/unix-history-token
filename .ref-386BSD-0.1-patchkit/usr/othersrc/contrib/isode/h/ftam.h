begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftam.h - include file for FTAM users (FS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/ftam.h,v 7.2 91/02/22 09:24:39 mrose Interim $  *  *  * $Log:	ftam.h,v $  * Revision 7.2  91/02/22  09:24:39  mrose  * Interim 6.8  *   * Revision 7.1  90/03/23  10:52:56  mrose  * update  *   * Revision 7.0  89/11/23  21:55:41  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FTAM_
end_ifndef

begin_define
define|#
directive|define
name|_FTAM_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_PSAP2_
end_ifndef

begin_include
include|#
directive|include
file|"psap2.h"
end_include

begin_comment
comment|/* definitions for PS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* FTAM-QoS */
end_comment

begin_define
define|#
directive|define
name|FQOS_NORECOVERY
value|0
end_define

begin_comment
comment|/*   no-recovery */
end_comment

begin_define
define|#
directive|define
name|FQOS_CLASS1
value|1
end_define

begin_comment
comment|/*   class-1-recovery */
end_comment

begin_define
define|#
directive|define
name|FQOS_CLASS2
value|2
end_define

begin_comment
comment|/*   class-2-recovery */
end_comment

begin_define
define|#
directive|define
name|FQOS_CLASS3
value|3
end_define

begin_comment
comment|/*   class-3-recovery */
end_comment

begin_define
define|#
directive|define
name|MY_FQOS
value|FQOS_NORECOVERY
end_define

begin_comment
comment|/* Service-Class */
end_comment

begin_define
define|#
directive|define
name|FCLASS_UNCONS
value|0x01
end_define

begin_comment
comment|/*   unconstrained-class */
end_comment

begin_define
define|#
directive|define
name|FCLASS_MANAGE
value|0x02
end_define

begin_comment
comment|/*   management-class */
end_comment

begin_define
define|#
directive|define
name|FCLASS_TRANSFER
value|0x04
end_define

begin_comment
comment|/*   transfer-class */
end_comment

begin_define
define|#
directive|define
name|FCLASS_TM
value|0x08
end_define

begin_comment
comment|/*   transfer-and-management-class */
end_comment

begin_define
define|#
directive|define
name|FCLASS_ACCESS
value|0x10
end_define

begin_comment
comment|/*   access-class */
end_comment

begin_comment
comment|/* Functional-Units */
end_comment

begin_define
define|#
directive|define
name|FUNIT_READ
value|0x001
end_define

begin_comment
comment|/*   read */
end_comment

begin_define
define|#
directive|define
name|FUNIT_WRITE
value|0x002
end_define

begin_comment
comment|/*   write */
end_comment

begin_define
define|#
directive|define
name|FUNIT_ACCESS
value|0x004
end_define

begin_comment
comment|/*   file-access */
end_comment

begin_define
define|#
directive|define
name|FUNIT_LIMITED
value|0x008
end_define

begin_comment
comment|/*   limited-file-managment */
end_comment

begin_define
define|#
directive|define
name|FUNIT_ENHANCED
value|0x010
end_define

begin_comment
comment|/*   enhanced-file-management */
end_comment

begin_define
define|#
directive|define
name|FUNIT_GROUPING
value|0x020
end_define

begin_comment
comment|/*   grouping */
end_comment

begin_define
define|#
directive|define
name|FUNIT_FADULOCK
value|0x040
end_define

begin_comment
comment|/*   fadu-locking */
end_comment

begin_define
define|#
directive|define
name|FUNIT_RECOVERY
value|0x080
end_define

begin_comment
comment|/*   recovery */
end_comment

begin_define
define|#
directive|define
name|FUNIT_RESTART
value|0x100
end_define

begin_comment
comment|/*   restart-data-transfer */
end_comment

begin_define
define|#
directive|define
name|MY_FUNIT
value|(FUNIT_READ | FUNIT_WRITE | FUNIT_ACCESS \ 				| FUNIT_LIMITED | FUNIT_ENHANCED \ 				| FUNIT_GROUPING | FUNIT_FADULOCK)
end_define

begin_comment
comment|/* Attribute-Groups */
end_comment

begin_define
define|#
directive|define
name|FATTR_STORAGE
value|0x01
end_define

begin_comment
comment|/*   storage */
end_comment

begin_define
define|#
directive|define
name|FATTR_SECURITY
value|0x02
end_define

begin_comment
comment|/*   security */
end_comment

begin_define
define|#
directive|define
name|FATTR_PRIVATE
value|0x04
end_define

begin_comment
comment|/*   private */
end_comment

begin_define
define|#
directive|define
name|MY_FATTR
value|(FATTR_STORAGE | FATTR_SECURITY)
end_define

begin_comment
comment|/* State-Result */
end_comment

begin_define
define|#
directive|define
name|FSTATE_SUCCESS
value|0
end_define

begin_comment
comment|/*   success */
end_comment

begin_define
define|#
directive|define
name|FSTATE_FAILURE
value|1
end_define

begin_comment
comment|/*   failure */
end_comment

begin_comment
comment|/* Action-Result */
end_comment

begin_define
define|#
directive|define
name|FACTION_SUCCESS
value|0
end_define

begin_comment
comment|/*   success */
end_comment

begin_define
define|#
directive|define
name|FACTION_TRANS
value|1
end_define

begin_comment
comment|/*   transient-error */
end_comment

begin_define
define|#
directive|define
name|FACTION_PERM
value|2
end_define

begin_comment
comment|/*   permanent-error */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMcontent
block|{
name|OID
name|fc_dtn
decl_stmt|;
comment|/* Document-Type-Name */
comment|/* associated presentation context info */
name|int
name|fc_id
decl_stmt|;
comment|/*   identifier */
name|int
name|fc_result
decl_stmt|;
comment|/*   status */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|FTAMcontentlist
block|{
comment|/* Contents-Type-List */
name|int
name|fc_ncontent
decl_stmt|;
comment|/* number of contents */
define|#
directive|define
name|NFCONT
value|(NPCTX - 2)
comment|/* not-so-arbitrary */
name|struct
name|FTAMcontent
name|fc_contents
index|[
name|NFCONT
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMdiagnostic
block|{
comment|/* Diagnostic */
name|int
name|ftd_type
decl_stmt|;
comment|/* diagnostic-type */
define|#
directive|define
name|DIAG_INFORM
value|0
comment|/*   informative */
define|#
directive|define
name|DIAG_TRANS
value|1
comment|/*   transient */
define|#
directive|define
name|DIAG_PERM
value|2
comment|/*   permanent */
name|int
name|ftd_identifier
decl_stmt|;
comment|/* error-identifier */
define|#
directive|define
name|FS_CODE2OFF
parameter_list|(
name|c
parameter_list|)
value|((c) % 1000)
define|#
directive|define
name|FS_GEN_BASE
value|0
comment|/* General FTAM diagnostics */
define|#
directive|define
name|FS_GEN_NOREASON
value|0
comment|/* No reason */
define|#
directive|define
name|FS_GEN_RESPONDER
value|1
comment|/* Responder error (unspecific) */
define|#
directive|define
name|FS_GEN_SHUTDOWN
value|2
comment|/* System shutdown */
define|#
directive|define
name|FS_GEN_MGMT
value|3
comment|/* FTAM management problem (unspecific) */
define|#
directive|define
name|FS_GEN_MGMTACCT
value|4
comment|/* FTAM management, bad account */
define|#
directive|define
name|FS_GEN_MGMTPASS
value|5
comment|/* FTAM management, security not passed */
define|#
directive|define
name|FS_GEN_DELAY
value|6
comment|/* Delay may be encountered */
define|#
directive|define
name|FS_GEN_INITIATOR
value|7
comment|/* Initiator error (unspecific) */
define|#
directive|define
name|FS_GEN_SUBSEQ
value|8
comment|/* Subsequent error */
define|#
directive|define
name|FS_GEN_TEMPORAL
value|9
comment|/* Temporal insufficiency of resources */
define|#
directive|define
name|FS_GEN_VFSECURE
value|10
comment|/* Access request violates VFS security */
define|#
directive|define
name|FS_GEN_LSECURE
value|11
comment|/* Access request violates local security */
define|#
directive|define
name|FS_GEN_WAITING
value|12
comment|/* Indications waiting (unofficial) */
define|#
directive|define
name|FS_PRO_BASE
value|1000
comment|/* Protocol and supporting service related 				   diagnostics */
define|#
directive|define
name|FS_PRO_CONFLICT
value|1000
comment|/* Conflicting parameter values */
define|#
directive|define
name|FS_PRO_UNSUPORT
value|1001
comment|/* Unsupported parameter values */
define|#
directive|define
name|FS_PRO_MANDATORY
value|1002
comment|/* Mandatory parameter not set */
define|#
directive|define
name|FS_PRO_UNPARAM
value|1003
comment|/* Unsupported parameter */
define|#
directive|define
name|FS_PRO_DUPARAM
value|1004
comment|/* Duplicated parameter */
define|#
directive|define
name|FS_PRO_ILLEGAL
value|1005
comment|/* Illegal parameter type */
define|#
directive|define
name|FS_PRO_UNTYPE
value|1006
comment|/* Unsupported parameter type */
define|#
directive|define
name|FS_PRO_ERR
value|1007
comment|/* FTAM protocol error (unspecific) */
define|#
directive|define
name|FS_PRO_ERRPROC
value|1008
comment|/* FTAM protocol error, procedure error */
define|#
directive|define
name|FS_PRO_ERRFUNIT
value|1009
comment|/* FTAM protocol error, functional unit error*/
define|#
directive|define
name|FS_PRO_ERRMSG
value|1010
comment|/* FTAM protocol error, corruption error */
define|#
directive|define
name|FS_PRO_LOWFAIL
value|1011
comment|/* Lower layer failure */
define|#
directive|define
name|FS_PRO_LOWADDR
value|1012
comment|/* Lower layer addressing error */
define|#
directive|define
name|FS_PRO_TIMEOUT
value|1013
comment|/* Timeout */
define|#
directive|define
name|FS_PRO_SHUTDOWN
value|1014
comment|/* System shutdown */
define|#
directive|define
name|FS_PRO_GROUPING
value|1015
comment|/* Illegal grouping sequence */
define|#
directive|define
name|FS_PRO_THRESH
value|1016
comment|/* Grouping threshold violation */
define|#
directive|define
name|FS_PRO_PDU
value|1017
comment|/* Specific PDU request inconsistent with the 				   current requested access */
define|#
directive|define
name|FS_ACS_BASE
value|2000
comment|/* Association related diagnostics */
define|#
directive|define
name|FS_ACS_USER
value|2000
comment|/* Association with user not allowed */
define|#
directive|define
name|FS_ACS_2001
value|2001
comment|/* not assigned, #2001  */
define|#
directive|define
name|FS_ACS_CLASS
value|2002
comment|/* Unsupported service class */
define|#
directive|define
name|FS_ACS_FUNIT
value|2003
comment|/* Unsupported functional unit */
define|#
directive|define
name|FS_ACS_GRP
value|2004
comment|/* Attribute group error (unspecific) */
define|#
directive|define
name|FS_ACS_GRPSUP
value|2005
comment|/* Attribute group not supported */
define|#
directive|define
name|FS_ACS_GRPALL
value|2006
comment|/* Attribute group not allowed */
define|#
directive|define
name|FS_ACS_ACCT
value|2007
comment|/* Bad account */
define|#
directive|define
name|FS_ACS_MGMT
value|2008
comment|/* Association management (unspecific) */
define|#
directive|define
name|FS_ACS_MGMTADDR
value|2009
comment|/* Association management - bad address */
define|#
directive|define
name|FS_ACS_MGMTACCT
value|2010
comment|/* Association management - bad account */
define|#
directive|define
name|FS_ACS_CKPLARGE
value|2011
comment|/* Checkpoint window error - too large */
define|#
directive|define
name|FS_ACS_CKPSMALL
value|2012
comment|/* Checkpoint window error - too small */
define|#
directive|define
name|FS_ACS_CKPERR
value|2013
comment|/* Checkpoint window error - unsupported */
define|#
directive|define
name|FS_ACS_QOS
value|2014
comment|/* Communications QoS not supported */
define|#
directive|define
name|FS_ACS_IDENTITY
value|2015
comment|/* Initiator identity unacceptable */
define|#
directive|define
name|FS_ACS_CONTEXT
value|2016
comment|/* Context management refused */
define|#
directive|define
name|FS_ACS_ROLLBACK
value|2017
comment|/* Rollback not available */
define|#
directive|define
name|FS_ACS_CNTRESP
value|2018
comment|/* Contents type list cut by responder */
define|#
directive|define
name|FS_ACS_CNTPSAP
value|2019
comment|/* Contents type list cut by Presentation 				   service */
define|#
directive|define
name|FS_ACS_PASSWORD
value|2020
comment|/* Invalid filestore password */
define|#
directive|define
name|FS_ACS_SERVICES
value|2021
comment|/* Incompatible service classes */
define|#
directive|define
name|FS_SEL_BASE
value|3000
comment|/* Selection related diagnostics */
define|#
directive|define
name|FS_SEL_FILENAME
value|3000
comment|/* Filename not found */
define|#
directive|define
name|FS_SEL_MATCHED
value|3001
comment|/* Selection attributes not matched */
define|#
directive|define
name|FS_SEL_INITIAL
value|3002
comment|/* Initial attributes not possible */
define|#
directive|define
name|FS_SEL_ATTRNAME
value|3003
comment|/* Bad attribute name */
define|#
directive|define
name|FS_SEL_NOEXIST
value|3004
comment|/* Non-existent file */
define|#
directive|define
name|FS_SEL_EXISTS
value|3005
comment|/* File already exists */
define|#
directive|define
name|FS_SEL_CREATE
value|3006
comment|/* File can not be created */
define|#
directive|define
name|FS_SEL_DELETE
value|3007
comment|/* File can not be deleted */
define|#
directive|define
name|FS_SEL_CONAVAIL
value|3008
comment|/* Concurrency control not available */
define|#
directive|define
name|FS_SEL_CONSUPRT
value|3009
comment|/* Concurrency control not supported */
define|#
directive|define
name|FS_SEL_CONPOSS
value|3010
comment|/* Concurrency control not possible */
define|#
directive|define
name|FS_SEL_RESTRICT
value|3011
comment|/* More restrictive lock */
define|#
directive|define
name|FS_SEL_BUSY
value|3012
comment|/* File busy */
define|#
directive|define
name|FS_SEL_AVAIL
value|3013
comment|/* File not available */
define|#
directive|define
name|FS_SEL_ACCAVAIL
value|3014
comment|/* Access control not available */
define|#
directive|define
name|FS_SEL_ACCSUPRT
value|3015
comment|/* Access control not supported */
define|#
directive|define
name|FS_SEL_ACCINCON
value|3016
comment|/* Access control inconsistent */
define|#
directive|define
name|FS_SEL_TRUNC
value|3017
comment|/* Filename truncated */
define|#
directive|define
name|FS_SEL_ALTER
value|3018
comment|/* Initial attributes altered */
define|#
directive|define
name|FS_SEL_ACCOUNT
value|3019
comment|/* Bad account */
define|#
directive|define
name|FS_SEL_CREEXIST
value|3020
comment|/* Override selected existing file */
define|#
directive|define
name|FS_SEL_CREOLD
value|3021
comment|/* Override deleted and recreated file 				   with old attributes */
define|#
directive|define
name|FS_SEL_CRENEW
value|3022
comment|/* Create override deleted and recreated file 				   with new attributes */
define|#
directive|define
name|FS_SEL_CRELOSE
value|3023
comment|/* Create override - not possible */
define|#
directive|define
name|FS_SEL_AMBIG
value|3024
comment|/* Ambiguous file specification */
define|#
directive|define
name|FS_SEL_CREPASS
value|3025
comment|/* Invalid create password */
define|#
directive|define
name|FS_SEL_DELPASS
value|3026
comment|/* Invalid delete password on override */
define|#
directive|define
name|FS_SEL_ATRVALUE
value|3027
comment|/* Bad attribute value */
define|#
directive|define
name|FS_SEL_VIOLATES
value|3028
comment|/* Requested access violates permitted 				   actions */
define|#
directive|define
name|FS_SEL_NOTAVAIL
value|3029
comment|/* Functional unit not available for requested 				   access */
define|#
directive|define
name|FS_SEL_CRENOSEL
value|3030
comment|/* File created but not selected */
define|#
directive|define
name|FS_MGT_BASE
value|4000
comment|/* File management related diagnostics */
define|#
directive|define
name|FS_MGT_EXIST
value|4000
comment|/* Attribute non-existant */
define|#
directive|define
name|FS_MGT_READ
value|4001
comment|/* Attribute cannot be read */
define|#
directive|define
name|FS_MGT_CHANGE
value|4002
comment|/* Attribute cannot be changed */
define|#
directive|define
name|FS_MGT_SUPPORT
value|4003
comment|/* Attribute not supported */
define|#
directive|define
name|FS_MGT_NAME
value|4004
comment|/* Bad attribute name */
define|#
directive|define
name|FS_MGT_VALUE
value|4005
comment|/* Bad attribute value */
define|#
directive|define
name|FS_MGT_PARTIAL
value|4006
comment|/* Attribute partially supported */
define|#
directive|define
name|FS_MGMT_DISTINCT
value|4007
comment|/* Additional set attribute not distinct */
define|#
directive|define
name|FS_ACC_BASE
value|5000
comment|/* Access related diagnostics */
define|#
directive|define
name|FS_ACC_FADU
value|5000
comment|/* Bad FADU (unspecific) */
define|#
directive|define
name|FS_ACC_FADUSIZE
value|5001
comment|/* Bad FADU - size error */
define|#
directive|define
name|FS_ACC_FADUTYPE
value|5002
comment|/* Bad FADU - type error */
define|#
directive|define
name|FS_ACC_FADUSPEC
value|5003
comment|/* Bad FADU - poorly specified */
define|#
directive|define
name|FS_ACC_FADULOC
value|5004
comment|/* Bad FADU - bad location */
define|#
directive|define
name|FS_ACC_EXIST
value|5005
comment|/* FADU does not exist */
define|#
directive|define
name|FS_ACC_AVL
value|5006
comment|/* FADU not available (unspecific) */
define|#
directive|define
name|FS_ACC_AVLREAD
value|5007
comment|/* FADU not available for reading */
define|#
directive|define
name|FS_ACC_AVLWRITE
value|5008
comment|/* FADU not available for writing */
define|#
directive|define
name|FS_ACC_AVLLOC
value|5009
comment|/* FADU not available for location */
define|#
directive|define
name|FS_ACC_AVLERASE
value|5010
comment|/* FADU not available for erasure */
define|#
directive|define
name|FS_ACC_INSERT
value|5011
comment|/* FADU cannot be inserted */
define|#
directive|define
name|FS_ACC_REPLACE
value|5012
comment|/* FADU cannot be replaced */
define|#
directive|define
name|FS_ACC_LOCATE
value|5013
comment|/* FADU cannot be located */
define|#
directive|define
name|FS_ACC_ELEMENT
value|5014
comment|/* Bad data element type */
define|#
directive|define
name|FS_ACC_OPAVAIL
value|5015
comment|/* Operation not available */
define|#
directive|define
name|FS_ACC_OPSUPRT
value|5016
comment|/* Operation not supported */
define|#
directive|define
name|FS_ACC_OPCONS
value|5017
comment|/* Operation inconsistent */
define|#
directive|define
name|FS_ACC_CONAVAIL
value|5018
comment|/* Concurrency control not available */
define|#
directive|define
name|FS_ACC_CONSUPRT
value|5019
comment|/* Concurrency control not supported */
define|#
directive|define
name|FS_ACC_CONINCON
value|5020
comment|/* Concurrency control inconsistent */
define|#
directive|define
name|FS_ACC_MODAVAIL
value|5021
comment|/* Processing mode not available */
define|#
directive|define
name|FS_ACC_MODSUPRT
value|5022
comment|/* Processing mode not supported */
define|#
directive|define
name|FS_ACC_MODINCON
value|5023
comment|/* Processing mode inconsistent */
define|#
directive|define
name|FS_ACC_CTXAVAIL
value|5024
comment|/* Access context not available */
define|#
directive|define
name|FS_ACC_CTXSUPRT
value|5025
comment|/* Access context not supported */
define|#
directive|define
name|FS_ACC_WRITE
value|5026
comment|/* Bad write (unspecific) */
define|#
directive|define
name|FS_ACC_READ
value|5027
comment|/* Bad read (unspecific) */
define|#
directive|define
name|FS_ACC_LCL
value|5028
comment|/* Local failure (unspecific) */
define|#
directive|define
name|FS_ACC_LCLSPACE
value|5029
comment|/* Local failure - file space exhausted */
define|#
directive|define
name|FS_ACC_LCLDATA
value|5030
comment|/* Local failure - data corrupted */
define|#
directive|define
name|FS_ACC_LCLDEV
value|5031
comment|/* Local failure - device failure */
define|#
directive|define
name|FS_ACC_FFSEXCEED
value|5032
comment|/* Future file size exceeded */
define|#
directive|define
name|FS_ACC_FFSINCRES
value|5034
comment|/* Future file size increased */
define|#
directive|define
name|FS_ACC_FUNIT
value|5035
comment|/* Functional unit invalid in processing 				   mode */
define|#
directive|define
name|FS_ACC_TYPINCON
value|5036
comment|/* Contents type inconsistent */
define|#
directive|define
name|FS_ACC_TYPSIMPL
value|5037
comment|/* Contents type simplified */
define|#
directive|define
name|FS_ACC_DUPLICATE
value|5038
comment|/* Duplicate FADU name */
define|#
directive|define
name|FS_ACC_DAMAGED
value|5039
comment|/* Damage to select/open regime */
define|#
directive|define
name|FS_ACC_NOLOCKS
value|5040
comment|/* FADU locking not available on file */
define|#
directive|define
name|FS_ACC_LOCKED
value|5041
comment|/* FADU locked by another user */
define|#
directive|define
name|FS_RVY_BASE
value|6000
comment|/* Recovery related diagnostics */
define|#
directive|define
name|FS_RVY_CKP
value|6000
comment|/* Bad checkpoint (unspecific) */
define|#
directive|define
name|FS_RVY_UNIQUE
value|6001
comment|/* Activity not unique */
define|#
directive|define
name|FS_RVY_WINDOW
value|6002
comment|/* Checkpoint outside window */
define|#
directive|define
name|FS_RVY_EXISTS
value|6003
comment|/* Activity no longer exists */
define|#
directive|define
name|FS_RVY_RECOG
value|6004
comment|/* Activity not recognized */
define|#
directive|define
name|FS_RVY_NODOCKET
value|6005
comment|/* No docket */
define|#
directive|define
name|FS_RVY_CODOCKET
value|6006
comment|/* Corrupt docket */
define|#
directive|define
name|FS_RVY_WAITING
value|6007
comment|/* File waiting restart */
define|#
directive|define
name|FS_RVY_RECOVERY
value|6008
comment|/* Bad recovery point */
define|#
directive|define
name|FS_RVY_NOPOINT
value|6009
comment|/* Non-existent recovery point */
define|#
directive|define
name|FS_RVY_MODAVAIL
value|6010
comment|/* Recovery mode not available */
define|#
directive|define
name|FS_RVY_MODINCON
value|6011
comment|/* Recovery mode inconsistent */
define|#
directive|define
name|FS_RVY_MODREDUCE
value|6012
comment|/* Recovery mode reduced */
define|#
directive|define
name|FS_RVY_ACCAVAIL
value|6013
comment|/* Access control not available */
define|#
directive|define
name|FS_RVY_ACCSUPRT
value|6014
comment|/* Access control not supported */
define|#
directive|define
name|FS_RVY_ACCINCON
value|6015
comment|/* Access control inconsistent */
define|#
directive|define
name|FS_RVY_TYPINCON
value|6016
comment|/* Contents type inconsistent */
define|#
directive|define
name|FS_RVY_TYPSIMPL
value|6017
comment|/* Contents type simplified */
name|int
name|ftd_observer
decl_stmt|;
comment|/* error-observer */
name|int
name|ftd_source
decl_stmt|;
comment|/* error-source */
define|#
directive|define
name|EREF_NONE
value|0
comment|/*   no-categorizaton-possible */
define|#
directive|define
name|EREF_IFSU
value|1
comment|/*   initiating-file-service-user */
define|#
directive|define
name|EREF_IFPM
value|2
comment|/*   initiating-file-protocol-machine */
define|#
directive|define
name|EREF_SERV
value|3
comment|/*   service-supporting-the-file-protocol-machine */
define|#
directive|define
name|EREF_RFPM
value|4
comment|/*   responding-file-protocol-machine */
define|#
directive|define
name|EREF_RFSU
value|5
comment|/*   responding-file-service-user */
name|int
name|ftd_delay
decl_stmt|;
comment|/* suggested-delay */
define|#
directive|define
name|DIAG_NODELAY
value|(-1)
comment|/* further-details */
define|#
directive|define
name|FTD_SIZE
value|512
comment|/* should be unlimited... */
name|int
name|ftd_cc
decl_stmt|;
comment|/*   length */
name|char
name|ftd_data
index|[
name|FTD_SIZE
index|]
decl_stmt|;
comment|/*   data */
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMcharging
block|{
comment|/* Charging */
name|int
name|fc_ncharge
decl_stmt|;
comment|/* number of charges */
define|#
directive|define
name|NFCHRG
value|5
comment|/* arbitrary */
struct|struct
name|fc_charge
block|{
name|char
modifier|*
name|fc_resource
decl_stmt|;
comment|/* resource-identifier */
name|char
modifier|*
name|fc_unit
decl_stmt|;
comment|/* charging-unit */
name|int
name|fc_value
decl_stmt|;
comment|/* charging-value */
block|}
name|fc_charges
index|[
name|NFCHRG
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMpasswords
block|{
comment|/* Access-Passwords */
name|char
modifier|*
name|fp_read
decl_stmt|;
comment|/* read-password */
name|int
name|fp_readlen
decl_stmt|;
name|char
modifier|*
name|fp_insert
decl_stmt|;
comment|/* insert-password */
name|int
name|fp_insertlen
decl_stmt|;
name|char
modifier|*
name|fp_replace
decl_stmt|;
comment|/* replace-password */
name|int
name|fp_replacelen
decl_stmt|;
name|char
modifier|*
name|fp_extend
decl_stmt|;
comment|/* extend-password */
name|int
name|fp_extendlen
decl_stmt|;
name|char
modifier|*
name|fp_erase
decl_stmt|;
comment|/* erase-password */
name|int
name|fp_eraselen
decl_stmt|;
name|char
modifier|*
name|fp_readattr
decl_stmt|;
comment|/* read-attribute-password */
name|int
name|fp_readattrlen
decl_stmt|;
name|char
modifier|*
name|fp_chngattr
decl_stmt|;
comment|/* change-attribute-password */
name|int
name|fp_chngattrlen
decl_stmt|;
name|char
modifier|*
name|fp_delete
decl_stmt|;
comment|/* delete-password */
name|int
name|fp_deletelen
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FPFREE
parameter_list|(
name|fp
parameter_list|)
define|\
value|{ \     register struct FTAMpasswords *FP = (fp); \  \     if (FP -> fp_read) \ 	free (FP -> fp_read), FP -> fp_read = NULL; \     if (FP -> fp_insert) \ 	free (FP -> fp_insert), FP -> fp_insert = NULL; \     if (FP -> fp_replace) \ 	free (FP -> fp_replace), FP -> fp_replace = NULL; \     if (FP -> fp_extend) \ 	free (FP -> fp_extend), FP -> fp_extend = NULL; \     if (FP -> fp_erase) \ 	free (FP -> fp_erase), FP -> fp_erase = NULL; \     if (FP -> fp_readattr) \ 	free (FP -> fp_readattr), FP -> fp_readattr = NULL; \     if (FP -> fp_chngattr) \ 	free (FP -> fp_chngattr), FP -> fp_chngattr = NULL; \     if (FP -> fp_delete) \ 	free (FP -> fp_delete), FP -> fp_delete = NULL; \ }
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMconcurrency
block|{
comment|/* Concurrency-Control/Concurrency-Access */
define|#
directive|define
name|FLOCK_SHARED
value|00
comment|/* shared */
define|#
directive|define
name|FLOCK_EXCLUSIVE
value|01
comment|/* exclusive */
define|#
directive|define
name|FLOCK_NOTREQD
value|02
comment|/* not-required */
define|#
directive|define
name|FLOCK_NOACCESS
value|03
comment|/* no-access */
define|#
directive|define
name|FLOCK_MASK
value|03
define|#
directive|define
name|FLOCK_PRESENT
value|FLOCK_EXCLUSIVE
define|#
directive|define
name|FLOCK_RESTRICT
value|01
name|char
name|fc_readlock
decl_stmt|;
name|char
name|fc_insertlock
decl_stmt|;
name|char
name|fc_replacelock
decl_stmt|;
name|char
name|fc_extendlock
decl_stmt|;
name|char
name|fc_eraselock
decl_stmt|;
name|char
name|fc_readattrlock
decl_stmt|;
name|char
name|fc_chngattrlock
decl_stmt|;
name|char
name|fc_deletelock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FCINIT
parameter_list|(
name|fc
parameter_list|)
define|\
value|{ \     (fc) -> fc_readlock = FLOCK_NOTREQD; \     (fc) -> fc_insertlock = FLOCK_NOTREQD; \     (fc) -> fc_replacelock = FLOCK_NOTREQD; \     (fc) -> fc_eraselock = FLOCK_NOTREQD; \     (fc) -> fc_extendlock = FLOCK_NOTREQD; \     (fc) -> fc_readattrlock = FLOCK_NOTREQD; \     (fc) -> fc_chngattrlock = FLOCK_NOTREQD; \     (fc) -> fc_deletelock = FLOCK_NOTREQD; \ }
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMacelement
block|{
comment|/* SET OF Access-Control-Element */
name|int
name|fe_actions
decl_stmt|;
comment|/* action-list */
define|#
directive|define
name|FA_PERM_READ
value|0x0001
comment|/* read */
define|#
directive|define
name|FA_PERM_INSERT
value|0x0002
comment|/* insert */
define|#
directive|define
name|FA_PERM_REPLACE
value|0x0004
comment|/* replace */
define|#
directive|define
name|FA_PERM_EXTEND
value|0x0008
comment|/* extend */
define|#
directive|define
name|FA_PERM_ERASE
value|0x0010
comment|/* erase */
define|#
directive|define
name|FA_PERM_READATTR
value|0x0020
comment|/* read-attribute */
define|#
directive|define
name|FA_PERM_CHNGATTR
value|0x0040
comment|/* change-attribute */
define|#
directive|define
name|FA_PERM_DELETE
value|0x0080
comment|/* delete-file */
name|struct
name|FTAMconcurrency
name|fe_concurrency
decl_stmt|;
comment|/* concurrency-access */
name|char
modifier|*
name|fe_identity
decl_stmt|;
comment|/* user-identity */
name|struct
name|FTAMpasswords
name|fe_passwords
decl_stmt|;
name|AEI
name|fe_aet
decl_stmt|;
comment|/* application-entity-title */
name|struct
name|FTAMacelement
modifier|*
name|fe_next
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FEFREE
parameter_list|(
name|fe
parameter_list|)
define|\
value|{ \     register struct FTAMacelement  *FE, \ 				   *FN; \  \     for (FE = (fe); FE; FE = FN) { \ 	FN = FE -> fe_next; \  \ 	if (FE -> fe_identity) \ 	    free (FE -> fe_identity), FE -> fe_identity = NULL; \  \ 	FPFREE (&FE -> fe_passwords); \  \ 	if (FE -> fe_aet) { \ 	    AEIFREE (FE -> fe_aet); \ 	    free ((char *) FE -> fe_aet), FE -> fe_aet = NULL; \ 	} \  \ 	FE -> fe_next = NULL; \  \ 	free ((char *) FE); \     } \ }
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMattributes
block|{
comment|/* {Change,Create,Read,Select}-Attributes */
name|long
name|fa_present
decl_stmt|;
comment|/* values present */
name|long
name|fa_novalue
decl_stmt|;
comment|/* no value available */
define|#
directive|define
name|FA_NULL
value|0x00000
define|#
directive|define
name|FA_FILENAME
value|0x00001
comment|/* filename */
define|#
directive|define
name|FA_ACTIONS
value|0x00002
comment|/* permitted-actions */
define|#
directive|define
name|FA_CONTENTS
value|0x00004
comment|/* contents-type */
define|#
directive|define
name|FA_ACCOUNT
value|0x00008
comment|/* account */
define|#
directive|define
name|FA_DATE_CREATE
value|0x00010
comment|/* date-and-time-of-creation */
define|#
directive|define
name|FA_DATE_MODIFY
value|0x00020
comment|/* date-and-time-of-last-modification */
define|#
directive|define
name|FA_DATE_READ
value|0x00040
comment|/* date-and-time-of-last-read-access */
define|#
directive|define
name|FA_DATE_ATTR
value|0x00080
comment|/* date-and-time-of-last-attribute-modification */
define|#
directive|define
name|FA_ID_CREATE
value|0x00100
comment|/* identity-of-creator */
define|#
directive|define
name|FA_ID_MODIFY
value|0x00200
comment|/* identity-of-last-modifier */
define|#
directive|define
name|FA_ID_READ
value|0x00400
comment|/* identity-of-last-reader */
define|#
directive|define
name|FA_ID_ATTR
value|0x00800
comment|/* identity-of-last-attribute-modifier */
define|#
directive|define
name|FA_AVAILABILITY
value|0x01000
comment|/* file-availability */
define|#
directive|define
name|FA_FILESIZE
value|0x02000
comment|/* filesize */
define|#
directive|define
name|FA_FUTURESIZE
value|0x04000
comment|/* future-filesize */
define|#
directive|define
name|FA_CONTROL
value|0x08000
comment|/* access-control */
define|#
directive|define
name|FA_LEGAL
value|0x10000
comment|/* legal-qualifications */
define|#
directive|define
name|FA_PRIVATE
value|0x20000
comment|/* private-use */
define|#
directive|define
name|FA_KERNEL
value|(FA_FILENAME | FA_ACTIONS | FA_CONTENTS)
define|#
directive|define
name|FA_STORAGE
value|(FA_ACCOUNT | FA_DATE_CREATE | FA_DATE_MODIFY \ 			    | FA_DATE_READ | FA_DATE_ATTR | FA_ID_CREATE \  			    | FA_ID_MODIFY | FA_ID_READ | FA_ID_ATTR \ 			    | FA_AVAILABILITY | FA_FILESIZE | FA_FUTURESIZE)
define|#
directive|define
name|FA_SECURITY
value|(FA_CONTROL | FA_LEGAL)
define|#
directive|define
name|NFFILE
value|5
comment|/* arbitrary */
name|int
name|fa_nfile
decl_stmt|;
comment|/* filename */
name|char
modifier|*
name|fa_files
index|[
name|NFFILE
index|]
decl_stmt|;
comment|/*   .. */
name|int
name|fa_permitted
decl_stmt|;
comment|/* permitted-actions, 				   same as fe_actions, plus: */
define|#
directive|define
name|FA_PERM_TRAV
value|0x0100
comment|/* traversal */
define|#
directive|define
name|FA_PERM_RVTRAV
value|0x0200
comment|/* reverse-traversal */
define|#
directive|define
name|FA_PERM_RANDOM
value|0x0400
comment|/* random-order */
define|#
directive|define
name|FA_PERM_TRAVERSAL
value|(FA_PERM_TRAV | FA_PERM_RVTRAV \ 					| FA_PERM_RANDOM)
name|OID
name|fa_contents
decl_stmt|;
comment|/* contents-type */
name|PE
name|fa_parameter
decl_stmt|;
comment|/*   .. parameter */
name|char
modifier|*
name|fa_account
decl_stmt|;
comment|/* account */
comment|/* date-and-time-of- ... */
name|struct
name|UTCtime
name|fa_date_create
decl_stmt|;
name|struct
name|UTCtime
name|fa_date_modify
decl_stmt|;
name|struct
name|UTCtime
name|fa_date_read
decl_stmt|;
name|struct
name|UTCtime
name|fa_date_attribute
decl_stmt|;
comment|/* identity-of- ... */
name|char
modifier|*
name|fa_id_create
decl_stmt|;
name|char
modifier|*
name|fa_id_modify
decl_stmt|;
name|char
modifier|*
name|fa_id_read
decl_stmt|;
name|char
modifier|*
name|fa_id_attribute
decl_stmt|;
name|int
name|fa_availability
decl_stmt|;
comment|/* file-availability */
define|#
directive|define
name|FA_AVAIL_IMMED
value|0
comment|/*   immediate */
define|#
directive|define
name|FA_AVAIL_DEFER
value|1
comment|/*   deferred */
name|int
name|fa_filesize
decl_stmt|;
comment|/* filesize */
name|int
name|fa_futuresize
decl_stmt|;
comment|/* future-filesize */
name|struct
name|FTAMacelement
modifier|*
name|fa_control
decl_stmt|;
comment|/* access-control */
name|char
modifier|*
name|fa_legal
decl_stmt|;
comment|/* legal-qualification */
name|char
modifier|*
name|fa_private
decl_stmt|;
comment|/* XXX */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|FAFREE
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FADUidentity
block|{
comment|/* FADU-Identity */
name|int
name|fa_type
decl_stmt|;
define|#
directive|define
name|FA_FIRSTLAST
value|0
comment|/* first-last */
define|#
directive|define
name|FA_RELATIVE
value|1
comment|/* relative */
define|#
directive|define
name|FA_BEGINEND
value|2
comment|/* begin-end */
define|#
directive|define
name|FA_SINGLE
value|3
comment|/* single-name */
define|#
directive|define
name|FA_NAMELIST
value|4
comment|/* name-list */
define|#
directive|define
name|FA_FADUNUMBER
value|5
comment|/* fadu-number */
union|union
block|{
name|int
name|fa_un_firstlast
decl_stmt|;
define|#
directive|define
name|FA_FIRST
value|0
define|#
directive|define
name|FA_LAST
value|1
name|int
name|fa_un_relative
decl_stmt|;
define|#
directive|define
name|FA_PREVIOUS
value|0
define|#
directive|define
name|FA_CURRENT
value|1
define|#
directive|define
name|FA_NEXT
value|2
name|int
name|fa_un_beginend
decl_stmt|;
define|#
directive|define
name|FA_BEGIN
value|0
define|#
directive|define
name|FA_END
value|1
name|char
modifier|*
name|fa_un_singlename
decl_stmt|;
define|#
directive|define
name|NANAME
value|5
comment|/* arbitrary */
struct|struct
block|{
name|char
modifier|*
name|fa_un_names
index|[
name|NANAME
index|]
decl_stmt|;
name|int
name|fa_un_nname
decl_stmt|;
block|}
name|fa_un_list
struct|;
name|int
name|fa_un_fadunumber
decl_stmt|;
block|}
name|fa_un
union|;
define|#
directive|define
name|fa_firstlast
value|fa_un.fa_un_firstlast
define|#
directive|define
name|fa_relative
value|fa_un.fa_un_relative
define|#
directive|define
name|fa_beginend
value|fa_un.fa_un_beginend
define|#
directive|define
name|fa_singlename
value|fa_un.fa_un_singlename
define|#
directive|define
name|fa_names
value|fa_un.fa_un_list.fa_un_names
define|#
directive|define
name|fa_nname
value|fa_un.fa_un_list.fa_un_nname
define|#
directive|define
name|fa_fadunumber
value|fa_un.fa_un_fadunumber
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FUFREE
parameter_list|(
name|fu
parameter_list|)
define|\
value|{ \     register int    FUI; \  \     if ((fu) -> fa_singlename) \ 	free ((fu) -> fa_singlename), (fu) -> fa_singlename = NULL; \  \     for (FUI = (fu) -> fa_nname - 1; FUI>= 0; FUI--) \ 	if ((fu) -> fa_names[FUI]) \ 	    free ((fu) -> fa_names[FUI]), (fu) -> fa_names[FUI] = NULL; \ }
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|FTAMstart
block|{
comment|/* F-INITIALIZE.INDICATION */
name|int
name|fts_sd
decl_stmt|;
comment|/* FTAM descriptor */
name|AEInfo
name|fts_callingtitle
decl_stmt|;
comment|/* info on calling application-entity */
name|AEInfo
name|fts_calledtitle
decl_stmt|;
comment|/* info called application-entity */
name|struct
name|PSAPaddr
name|fts_calledaddr
decl_stmt|;
comment|/* called presentation address */
name|struct
name|PSAPaddr
name|fts_callingaddr
decl_stmt|;
comment|/* calling presentation address */
name|OID
name|fts_context
decl_stmt|;
comment|/* application context name */
name|int
name|fts_manage
decl_stmt|;
comment|/* presentation-context-management */
name|int
name|fts_class
decl_stmt|;
comment|/* service-class */
name|int
name|fts_units
decl_stmt|;
comment|/* functional-units */
name|int
name|fts_attrs
decl_stmt|;
comment|/* attribute-groups */
name|PE
name|fts_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
name|int
name|fts_fqos
decl_stmt|;
comment|/* ftam-QoS */
name|struct
name|FTAMcontentlist
name|fts_contents
decl_stmt|;
comment|/* contents-type-list */
name|char
modifier|*
name|fts_initiator
decl_stmt|;
comment|/* initiator-identity */
name|char
modifier|*
name|fts_account
decl_stmt|;
comment|/* account */
name|char
modifier|*
name|fts_password
decl_stmt|;
comment|/* filestore-password */
name|int
name|fts_passlen
decl_stmt|;
comment|/*   .. */
name|int
name|fts_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|fts_qos
decl_stmt|;
comment|/* Communications QoS */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTSFREE
parameter_list|(
name|fts
parameter_list|)
define|\
value|{ \     register int FSI; \  \     AEIFREE (&(fts) -> fts_callingtitle); \     AEIFREE (&(fts) -> fts_calledtitle); \     if ((fts) -> fts_context) \ 	oid_free ((fts) -> fts_context), (fts) -> fts_context = NULLOID; \  \     if ((fts) -> fts_sharedASE) \ 	pe_free ((fts) -> fts_sharedASE), (fts) -> fts_sharedASE = NULLPE; \  \     for (FSI = (fts) -> fts_contents.fc_ncontent - 1; FSI>= 0; FSI--) \ 	oid_free ((fts) -> fts_contents.fc_contents[FSI].fc_dtn), \ 		(fts) -> fts_contents.fc_contents[FSI].fc_dtn = NULLOID; \     (fts) -> fts_contents.fc_ncontent = 0; \  \     if ((fts) -> fts_initiator) \ 	free ((fts) -> fts_initiator), (fts) -> fts_initiator = NULL; \     if ((fts) -> fts_account) \ 	free ((fts) -> fts_account), (fts) -> fts_account = NULL; \     if ((fts) -> fts_password) \ 	free ((fts) -> fts_password), (fts) -> fts_password = NULL; \ }
end_define

begin_struct
struct|struct
name|FTAMconnect
block|{
comment|/* F-INITIALIZE.CONFIRMATION */
name|int
name|ftc_sd
decl_stmt|;
comment|/* FTAM descriptor */
name|AEInfo
name|ftc_respondtitle
decl_stmt|;
comment|/* responding application-entity title */
name|struct
name|PSAPaddr
name|ftc_respondaddr
decl_stmt|;
comment|/* responding presentation address */
name|OID
name|ftc_context
decl_stmt|;
comment|/* application context name */
name|int
name|ftc_state
decl_stmt|;
comment|/* state-result */
name|int
name|ftc_action
decl_stmt|;
comment|/* action-result */
name|int
name|ftc_manage
decl_stmt|;
comment|/* presentation-context-management */
name|int
name|ftc_class
decl_stmt|;
comment|/* service-class */
name|int
name|ftc_units
decl_stmt|;
comment|/* functional-units */
name|int
name|ftc_attrs
decl_stmt|;
comment|/* attribute-groups */
name|PE
name|ftc_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
name|int
name|ftc_fqos
decl_stmt|;
comment|/* ftam-QoS */
name|struct
name|FTAMcontentlist
name|ftc_contents
decl_stmt|;
comment|/* contents-type-list */
define|#
directive|define
name|NFDIAG
value|5
comment|/* diagnostic */
name|int
name|ftc_ndiag
decl_stmt|;
name|struct
name|FTAMdiagnostic
name|ftc_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
name|int
name|ftc_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|struct
name|QOStype
name|ftc_qos
decl_stmt|;
comment|/* communications QoS */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTCFREE
parameter_list|(
name|ftc
parameter_list|)
define|\
value|{ \     register int FCI; \  \     AEIFREE (&(ftc) -> ftc_respondtitle); \     if ((ftc) -> ftc_context) \ 	oid_free ((ftc) -> ftc_context), (ftc) -> ftc_context = NULLOID; \  \     if ((ftc) -> ftc_sharedASE) \ 	pe_free ((ftc) -> ftc_sharedASE), (ftc) -> ftc_sharedASE = NULLPE; \  \     for (FCI = (ftc) -> ftc_contents.fc_ncontent - 1; FCI>= 0; FCI--) \ 	oid_free ((ftc) -> ftc_contents.fc_contents[FCI].fc_dtn), \ 		(ftc) -> ftc_contents.fc_contents[FCI].fc_dtn = NULLOID; \     (ftc) -> ftc_contents.fc_ncontent = 0; \ }
end_define

begin_struct
struct|struct
name|FTAMfinish
block|{
comment|/* F-TERMINATE.INDICATION */
name|PE
name|ftf_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTFFREE
parameter_list|(
name|ftf
parameter_list|)
define|\
value|{ \       if ((ftf) -> ftf_sharedASE) \ 	  pe_free ((ftf) -> ftf_sharedASE), (ftf) -> ftf_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMrelease
block|{
comment|/* F-TERMINATE.CONFIRMATION */
name|PE
name|ftr_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* charging */
name|struct
name|FTAMcharging
name|ftr_charges
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTRFREE
parameter_list|(
name|ftr
parameter_list|)
define|\
value|{ \     register int    FRI; \     register struct fc_charge  *FC; \  \     if ((ftr) -> ftr_sharedASE) \ 	pe_free ((ftr) -> ftr_sharedASE), (ftr) -> ftr_sharedASE = NULLPE; \  \     for (FC = (ftr) -> ftr_charges.fc_charges, FRI = (ftr) -> ftr_charges.fc_ncharge - 1; \ 	    FRI>= 0; \ 	    FC++, FRI--) { \ 	if (FC -> fc_resource) \ 	    free (FC -> fc_resource), FC -> fc_resource = NULL; \ 	if (FC -> fc_unit) \ 	    free (FC -> fc_unit), FC -> fc_unit = NULL; \     } \     (ftr) -> ftr_charges.fc_ncharge = 0; \ }
end_define

begin_struct
struct|struct
name|FTAMabort
block|{
comment|/* F-{U,P}-ABORT.INDICATION */
name|int
name|fta_peer
decl_stmt|;
comment|/* T   = F-U-ABORT.INDICATION 				   NIL = F-P-ABORT.INDICATION */
name|int
name|fta_action
decl_stmt|;
comment|/* action-result */
name|int
name|fta_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|fta_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|FTAMselect
block|{
comment|/* F-SELECT.* */
comment|/* RESPONSE only */
name|int
name|ftse_state
decl_stmt|;
comment|/* state-result */
name|int
name|ftse_action
decl_stmt|;
comment|/* action-result */
comment|/* attributes (FILENAME only) */
name|struct
name|FTAMattributes
name|ftse_attrs
decl_stmt|;
define|#
directive|define
name|FA_SEL_ATTRS
value|FA_FILENAME
comment|/* REQUEST only */
name|int
name|ftse_access
decl_stmt|;
comment|/* requested-access */
define|#
directive|define
name|FA_REQ_MASK
value|(FA_PERM_READ | FA_PERM_INSERT | FA_PERM_REPLACE \ 				| FA_PERM_EXTEND | FA_PERM_ERASE \ 				| FA_PERM_READATTR | FA_PERM_CHNGATTR \ 				| FA_PERM_DELETE)
comment|/* access-passwords */
name|struct
name|FTAMpasswords
name|ftse_pwds
decl_stmt|;
comment|/* concurrency-control */
name|struct
name|FTAMconcurrency
name|ftse_conctl
decl_stmt|;
name|PE
name|ftse_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
name|char
modifier|*
name|ftse_account
decl_stmt|;
comment|/* account */
comment|/* RESPONSE only */
name|int
name|ftse_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftse_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTSEFREE
parameter_list|(
name|ftse
parameter_list|)
define|\
value|{ \     FAFREE (&((ftse) -> ftse_attrs)); \     FPFREE (&((ftse) -> ftse_pwds)); \     if ((ftse) -> ftse_sharedASE) \ 	pe_free ((ftse) -> ftse_sharedASE), (ftse) -> ftse_sharedASE = NULLPE; \     if ((ftse) -> ftse_account) \ 	free ((ftse) -> ftse_account), (ftse) -> ftse_account = NULLCP; \ }
end_define

begin_struct
struct|struct
name|FTAMdeselect
block|{
comment|/* F-DESELECT.* */
comment|/* RESPONSE only */
name|int
name|ftde_action
decl_stmt|;
comment|/* action-result */
name|PE
name|ftde_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* RESPONSE only */
comment|/* charging */
name|struct
name|FTAMcharging
name|ftde_charges
decl_stmt|;
name|int
name|ftde_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftde_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTDEFREE
parameter_list|(
name|ftde
parameter_list|)
define|\
value|{ \     register int    FDEI; \     register struct fc_charge  *FC; \  \     for (FC = (ftde) -> ftde_charges.fc_charges, FDEI = (ftde) -> ftde_charges.fc_ncharge - 1; \ 	    FDEI>= 0; \ 	    FC++, FDEI--) { \ 	if (FC -> fc_resource) \ 	    free (FC -> fc_resource), FC -> fc_resource = NULL; \ 	if (FC -> fc_unit) \ 	    free (FC -> fc_unit), FC -> fc_unit = NULL; \     } \     (ftde) -> ftde_charges.fc_ncharge = 0; \     if ((ftde) -> ftde_sharedASE) \ 	pe_free ((ftde) -> ftde_sharedASE), (ftde) -> ftde_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMcreate
block|{
comment|/* F-CREATE.* */
comment|/* RESPONSE only */
name|int
name|ftce_state
decl_stmt|;
comment|/* state-result */
name|int
name|ftce_action
decl_stmt|;
comment|/* action-result */
comment|/* REQUEST only */
name|int
name|ftce_override
decl_stmt|;
comment|/* override */
define|#
directive|define
name|FOVER_FAIL
value|0
comment|/* fail, if already exists */
define|#
directive|define
name|FOVER_SELECT
value|1
comment|/* select, if it already exists */
define|#
directive|define
name|FOVER_WRITE
value|2
comment|/* zero-truncate, if it already exists */
define|#
directive|define
name|FOVER_DELETE
value|3
comment|/* delete, if it already exists */
comment|/* initial-attributes */
name|struct
name|FTAMattributes
name|ftce_attrs
decl_stmt|;
define|#
directive|define
name|FA_CRE_ATTRS
value|(FA_FILENAME | FA_ACTIONS | FA_CONTENTS | FA_ACCOUNT \ 			    | FA_AVAILABILITY | FA_FUTURESIZE | FA_CONTROL \ 			    | FA_LEGAL | FA_PRIVATE)
comment|/* REQUEST only */
name|char
modifier|*
name|ftce_create
decl_stmt|;
comment|/* create-password */
name|int
name|ftce_crelen
decl_stmt|;
comment|/*   .. */
name|int
name|ftce_access
decl_stmt|;
comment|/* requested-access */
comment|/* access-passwords */
name|struct
name|FTAMpasswords
name|ftce_pwds
decl_stmt|;
comment|/* concurrency-control */
name|struct
name|FTAMconcurrency
name|ftce_conctl
decl_stmt|;
name|PE
name|ftce_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* REQUEST only */
name|char
modifier|*
name|ftce_account
decl_stmt|;
comment|/* account */
comment|/* RESPONSE only */
name|int
name|ftce_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftce_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTCEFREE
parameter_list|(
name|ftce
parameter_list|)
define|\
value|{ \     FAFREE (&((ftce) -> ftce_attrs)); \     if ((ftce) -> ftce_create) \ 	free ((ftce) -> ftce_create), (ftce) -> ftce_create = NULLCP; \     FPFREE (&((ftce) -> ftce_pwds)); \     if ((ftce) -> ftce_sharedASE) \ 	pe_free ((ftce) -> ftce_sharedASE), (ftce) -> ftce_sharedASE = NULLPE; \     if ((ftce) -> ftce_account) \ 	free ((ftce) -> ftce_account), (ftce) -> ftce_account = NULLCP; \ }
end_define

begin_struct
struct|struct
name|FTAMdelete
block|{
comment|/* F-DELETE.* */
comment|/* RESPONSE only */
name|int
name|ftxe_action
decl_stmt|;
comment|/* action-result */
name|PE
name|ftxe_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* RESPONSE only */
comment|/* charging */
name|struct
name|FTAMcharging
name|ftxe_charges
decl_stmt|;
name|int
name|ftxe_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftxe_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTXEFREE
parameter_list|(
name|ftxe
parameter_list|)
define|\
value|{ \     register int    FXEI; \     register struct fc_charge  *FC; \  \     if ((ftxe) -> ftxe_sharedASE) \ 	pe_free ((ftxe) -> ftxe_sharedASE), (ftxe) -> ftxe_sharedASE = NULLPE; \  \     for (FC = (ftxe) -> ftxe_charges.fc_charges, FXEI = (ftxe) -> ftxe_charges.fc_ncharge - 1; \ 	    FXEI>= 0; \ 	    FC++, FXEI--) { \ 	if (FC -> fc_resource) \ 	    free (FC -> fc_resource), FC -> fc_resource = NULL; \ 	if (FC -> fc_unit) \ 	    free (FC -> fc_unit), FC -> fc_unit = NULL; \     } \     (ftxe) -> ftxe_charges.fc_ncharge = 0; \ }
end_define

begin_struct
struct|struct
name|FTAMreadattr
block|{
comment|/* F-READ-ATTRIB.* */
comment|/* RESPONSE only */
name|int
name|ftra_action
decl_stmt|;
comment|/* action-result */
comment|/* REQUEST only */
name|int
name|ftra_attrnames
decl_stmt|;
comment|/* attribute names (from fa_present) */
comment|/* RESPONSE only */
name|struct
name|FTAMattributes
name|ftra_attrs
decl_stmt|;
name|int
name|ftra_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftra_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTRAFREE
parameter_list|(
name|ftra
parameter_list|)
define|\
value|{ \     FAFREE (&((ftra) -> ftra_attrs)); \ }
end_define

begin_struct
struct|struct
name|FTAMchngattr
block|{
comment|/* F-CHANGE-ATTRIB.* */
comment|/* RESPONSE only */
name|int
name|ftca_action
decl_stmt|;
comment|/* action-result */
name|struct
name|FTAMattributes
name|ftca_attrs
decl_stmt|;
define|#
directive|define
name|FA_CHG_ATTRS
value|(FA_FILENAME | FA_ACCOUNT | FA_AVAILABILITY \ 			    | FA_FUTURESIZE | FA_CONTROL | FA_LEGAL \ 			    | FA_PRIVATE)
comment|/* RESPONSE only */
name|int
name|ftca_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftca_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTCAFREE
parameter_list|(
name|ftca
parameter_list|)
define|\
value|{ \     FAFREE (&((ftca) -> ftca_attrs)); \ }
end_define

begin_struct
struct|struct
name|FTAMopen
block|{
comment|/* F-OPEN.* */
comment|/* RESPONSE only */
name|int
name|ftop_state
decl_stmt|;
comment|/* state-result */
name|int
name|ftop_action
decl_stmt|;
comment|/* action-result */
comment|/* REQUEST only */
name|int
name|ftop_mode
decl_stmt|;
comment|/* processing-mode (read..erase) */
define|#
directive|define
name|FA_MODE_MASK
value|(FA_PERM_READ | FA_PERM_INSERT | FA_PERM_REPLACE \ 				| FA_PERM_EXTEND | FA_PERM_ERASE)
name|OID
name|ftop_contents
decl_stmt|;
comment|/* contents-type */
name|PE
name|ftop_parameter
decl_stmt|;
comment|/*   .. */
comment|/* concurrency-control */
name|struct
name|FTAMconcurrency
name|ftop_conctl
decl_stmt|;
name|PE
name|ftop_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* REQUEST only */
name|int
name|ftop_locking
decl_stmt|;
comment|/* enable-fadu-locking */
comment|/* RESPONSE only */
name|int
name|ftop_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftop_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTOPFREE
parameter_list|(
name|ftop
parameter_list|)
define|\
value|{ \     if ((ftop) -> ftop_contents) \ 	oid_free ((ftop) -> ftop_contents), \ 	    (ftop) -> ftop_contents = NULLOID; \     if ((ftop) -> ftop_parameter) \ 	pe_free ((ftop) -> ftop_parameter), \ 	    (ftop) -> ftop_parameter = NULLPE; \     if ((ftop) -> ftop_sharedASE) \ 	pe_free ((ftop) -> ftop_sharedASE), (ftop) -> ftop_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMclose
block|{
comment|/* F-CLOSE.* */
name|int
name|ftcl_action
decl_stmt|;
comment|/* action-result */
name|PE
name|ftcl_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
name|int
name|ftcl_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftcl_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTCLFREE
parameter_list|(
name|ftcl
parameter_list|)
define|\
value|{ \     if ((ftcl) -> ftcl_sharedASE) \ 	pe_free ((ftcl) -> ftcl_sharedASE), (ftcl) -> ftcl_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMgroup
block|{
name|int
name|ftg_threshold
decl_stmt|;
comment|/* threshold */
name|int
name|ftg_flags
decl_stmt|;
define|#
directive|define
name|FTG_NULL
value|0x0000
define|#
directive|define
name|FTG_BEGIN
value|0x0001
comment|/* have begin */
define|#
directive|define
name|FTG_SELECT
value|0x0002
comment|/*   .. select */
define|#
directive|define
name|FTG_CREATE
value|0x0004
comment|/*   .. create */
define|#
directive|define
name|FTG_RDATTR
value|0x0008
comment|/*   .. read attribute */
define|#
directive|define
name|FTG_CHATTR
value|0x0010
comment|/*   .. change attribute */
define|#
directive|define
name|FTG_OPEN
value|0x0020
comment|/*   .. open */
define|#
directive|define
name|FTG_CLOSE
value|0x0040
comment|/*   .. close */
define|#
directive|define
name|FTG_DESELECT
value|0x0080
comment|/*   .. deselect */
define|#
directive|define
name|FTG_DELETE
value|0x0100
comment|/*   .. delete */
define|#
directive|define
name|FTG_END
value|0x0200
comment|/*   .. end */
union|union
block|{
name|struct
name|FTAMselect
name|ftg_un1_select
decl_stmt|;
name|struct
name|FTAMcreate
name|ftg_un1_create
decl_stmt|;
name|struct
name|FTAMclose
name|ftg_un1_close
decl_stmt|;
block|}
name|ftg_un1
union|;
define|#
directive|define
name|ftg_select
value|ftg_un1.ftg_un1_select
define|#
directive|define
name|ftg_create
value|ftg_un1.ftg_un1_create
define|#
directive|define
name|ftg_close
value|ftg_un1.ftg_un1_close
name|struct
name|FTAMreadattr
name|ftg_readattr
decl_stmt|;
name|struct
name|FTAMchngattr
name|ftg_chngattr
decl_stmt|;
union|union
block|{
name|struct
name|FTAMdeselect
name|ftg_un2_deselect
decl_stmt|;
name|struct
name|FTAMdelete
name|ftg_un2_delete
decl_stmt|;
name|struct
name|FTAMopen
name|ftg_un2_open
decl_stmt|;
block|}
name|ftg_un2
union|;
define|#
directive|define
name|ftg_deselect
value|ftg_un2.ftg_un2_deselect
define|#
directive|define
name|ftg_delete
value|ftg_un2.ftg_un2_delete
define|#
directive|define
name|ftg_open
value|ftg_un2.ftg_un2_open
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTGFREE
parameter_list|(
name|ftg
parameter_list|)
define|\
value|{ \     if ((ftg) -> ftg_flags& FTG_SELECT) { \ 	FTSEFREE (&((ftg) -> ftg_select)); \     } \     else \ 	if ((ftg) -> ftg_flags& FTG_CREATE) { \ 	    FTCEFREE (&((ftg) -> ftg_create)); \ 	} \ 	else \ 	    if ((ftg) -> ftg_flags& FTG_CLOSE) \ 	        FTCLFREE (&((ftg) -> ftg_close)); \  \     if ((ftg) ->ftg_flags& FTG_RDATTR) \ 	FTRAFREE (&((ftg) -> ftg_readattr)); \  \     if ((ftg) ->ftg_flags& FTG_CHATTR) \ 	FTCAFREE (&((ftg) -> ftg_chngattr)); \  \     if ((ftg) -> ftg_flags& FTG_DESELECT) { \ 	FTDEFREE (&((ftg) -> ftg_deselect)); \     } \     else \ 	if ((ftg) -> ftg_flags& FTG_DELETE) { \ 	    FTXEFREE (&((ftg) -> ftg_delete)); \ 	} \ 	else \ 	    if ((ftg) -> ftg_flags& FTG_OPEN) \ 		FTOPFREE (&((ftg) -> ftg_open)); \ }
end_define

begin_struct
struct|struct
name|FTAMaccess
block|{
comment|/* F-{LOCATE,ERASE}.{INDICATION,CONFIRMATION} */
name|int
name|ftac_operation
decl_stmt|;
define|#
directive|define
name|FA_OPS_LOCATE
value|0
comment|/* locate */
define|#
directive|define
name|FA_OPS_ERASE
value|1
comment|/* erase */
comment|/* CONFIRMATION only */
name|int
name|ftac_action
decl_stmt|;
comment|/* action-result */
comment|/* *.INDICATION OR F-LOCATE.CONFIRMATION */
comment|/* fadu-identity */
name|struct
name|FADUidentity
name|ftac_identity
decl_stmt|;
comment|/* F-LOCATE.INDICATION only */
name|int
name|ftac_locking
decl_stmt|;
comment|/* fadu-lock (on, off) */
comment|/* CONFIRMATION only */
name|int
name|ftac_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftac_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTACFREE
parameter_list|(
name|ftac
parameter_list|)
define|\
value|{ \     FUFREE (&((ftac) -> ftac_identity)); \ }
end_define

begin_struct
struct|struct
name|FTAMreadwrite
block|{
comment|/* F-{READ,WRITE}.INDICATION */
name|int
name|ftrw_operation
decl_stmt|;
comment|/* fadu-operation */
define|#
directive|define
name|FA_OPS_READ
value|(-1)
comment|/*   read (pseudo) */
define|#
directive|define
name|FA_OPS_INSERT
value|0
comment|/*   insert */
define|#
directive|define
name|FA_OPS_REPLACE
value|1
comment|/*   replace */
define|#
directive|define
name|FA_OPS_EXTEND
value|2
comment|/*   extend */
comment|/* fadu-identity */
name|struct
name|FADUidentity
name|ftrw_identity
decl_stmt|;
comment|/* F-READ.INDICATION only */
name|int
name|ftrw_context
decl_stmt|;
comment|/* access-context */
define|#
directive|define
name|FA_ACC_HA
value|0
comment|/*   hierarchical-all-data-units */
define|#
directive|define
name|FA_ACC_HN
value|1
comment|/*   hierarchical-no-data-units */
define|#
directive|define
name|FA_ACC_FA
value|2
comment|/*   flat-all-data-units */
define|#
directive|define
name|FA_ACC_FL
value|3
comment|/*   flat-one-level-data-units */
define|#
directive|define
name|FA_ACC_FS
value|4
comment|/*   flat-single-data-unit */
define|#
directive|define
name|FA_ACC_UA
value|5
comment|/*   unstructured-all-data-units */
define|#
directive|define
name|FA_ACC_US
value|6
comment|/*   unstructured-single-data-unit */
name|int
name|ftrw_level
decl_stmt|;
comment|/* level for FL */
name|int
name|ftrw_locking
decl_stmt|;
comment|/* fadu-lock */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTRWFREE
parameter_list|(
name|ftrw
parameter_list|)
define|\
value|{ \     FUFREE (&((ftrw) -> ftrw_identity)); \ }
end_define

begin_struct
struct|struct
name|FTAMdataend
block|{
comment|/* F-DATA-END.INDICATION */
name|int
name|ftda_action
decl_stmt|;
comment|/* action-result */
name|int
name|ftda_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftda_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|FTAMtransend
block|{
comment|/* F-TRANSFER-END.{INDICATION,CONFIRMATION} */
comment|/* RESPONSE only */
name|int
name|ftre_action
decl_stmt|;
comment|/* action-result */
name|PE
name|ftre_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
comment|/* RESPONSE only */
name|int
name|ftre_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftre_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTREFREE
parameter_list|(
name|ftre
parameter_list|)
define|\
value|{ \     if ((ftre) -> ftre_sharedASE) \ 	pe_free ((ftre) -> ftre_sharedASE), (ftre) -> ftre_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMcancel
block|{
comment|/* F-CANCEL.{INDICATION,CONFIRMATION} */
name|int
name|ftcn_action
decl_stmt|;
comment|/* action-result */
name|PE
name|ftcn_sharedASE
decl_stmt|;
comment|/* shared-ASE-information */
name|int
name|ftcn_ndiag
decl_stmt|;
comment|/* diagnostic */
name|struct
name|FTAMdiagnostic
name|ftcn_diags
index|[
name|NFDIAG
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FTCNFREE
parameter_list|(
name|ftcn
parameter_list|)
define|\
value|{ \     if ((ftcn) -> ftcn_sharedASE) \ 	pe_free ((ftcn) -> ftcn_sharedASE), (ftcn) -> ftcn_sharedASE = NULLPE; \ }
end_define

begin_struct
struct|struct
name|FTAMindication
block|{
name|int
name|fti_type
decl_stmt|;
comment|/* the union element present */
define|#
directive|define
name|FTI_FINISH
value|0x00
define|#
directive|define
name|FTI_ABORT
value|0x01
define|#
directive|define
name|FTI_MANAGEMENT
value|0x02
define|#
directive|define
name|FTI_BULKBEGIN
value|0x03
define|#
directive|define
name|FTI_BULKEND
value|0x04
define|#
directive|define
name|FTI_ACCESS
value|0x05
define|#
directive|define
name|FTI_READWRITE
value|0x06
define|#
directive|define
name|FTI_DATA
value|0x07
define|#
directive|define
name|FTI_DATAEND
value|0x08
define|#
directive|define
name|FTI_CANCEL
value|0x09
define|#
directive|define
name|FTI_TRANSEND
value|0x10
union|union
block|{
name|struct
name|FTAMfinish
name|fti_un_finish
decl_stmt|;
name|struct
name|FTAMabort
name|fti_un_abort
decl_stmt|;
name|struct
name|FTAMgroup
name|fti_un_group
decl_stmt|;
name|struct
name|FTAMaccess
name|fti_un_access
decl_stmt|;
name|struct
name|FTAMreadwrite
name|fti_un_readwrite
decl_stmt|;
name|struct
name|PSAPdata
name|fti_un_data
decl_stmt|;
name|struct
name|FTAMdataend
name|fti_un_dataend
decl_stmt|;
name|struct
name|FTAMcancel
name|fti_un_cancel
decl_stmt|;
name|struct
name|FTAMtransend
name|fti_un_transend
decl_stmt|;
block|}
name|fti_un
union|;
define|#
directive|define
name|fti_finish
value|fti_un.fti_un_finish
define|#
directive|define
name|fti_abort
value|fti_un.fti_un_abort
define|#
directive|define
name|fti_group
value|fti_un.fti_un_group
define|#
directive|define
name|fti_access
value|fti_un.fti_un_access
define|#
directive|define
name|fti_readwrite
value|fti_un.fti_un_readwrite
define|#
directive|define
name|fti_data
value|fti_un.fti_un_data
define|#
directive|define
name|fti_dataend
value|fti_un.fti_un_dataend
define|#
directive|define
name|fti_cancel
value|fti_un.fti_un_cancel
define|#
directive|define
name|fti_transend
value|fti_un.fti_un_transend
block|}
struct|;
end_struct

begin_comment
comment|/* when FTAMindication has PSAPdata, the pe_context indicates whether    each data is from the FTAM PCI or is a data element.  	FTAM PCI	- PE_DFLT_CTX  	data element	- anything else     three different types of data in the FTAM PCI are handled by the user:  	Node-Descriptor-Data-Element ::=	[APPLICATION 0] ... 	Enter-Subtree-Data-Element ::=		[APPLICATION 1] ... 	Exit-Subtree-Data-Element ::=		[APPLICATION 2] ...  */
end_comment

begin_define
define|#
directive|define
name|FADU_NODESCR
value|0
end_define

begin_comment
comment|/* Node-Descriptor-Data-Element */
end_comment

begin_define
define|#
directive|define
name|FADU_ENTERTREE
value|1
end_define

begin_comment
comment|/* Enter-Subtree-Data-Element */
end_comment

begin_define
define|#
directive|define
name|FADU_EXITREE
value|2
end_define

begin_comment
comment|/* Exit-Subtree-Data-Element */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ftamversion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LLog
name|_ftam_log
decl_stmt|,
modifier|*
name|ftam_log
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|FInit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-INITIALIZE.INDICATION */
end_comment

begin_function_decl
name|int
name|FInitializeResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-INITIALIZE.RESPONSE */
end_comment

begin_function_decl
name|int
name|FInitializeRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-INITIALIZE.REQUEST */
end_comment

begin_function_decl
name|int
name|FTerminateRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-TERMINATE.REQUEST */
end_comment

begin_function_decl
name|int
name|FTerminateResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-TERMINATE.RESPONSE */
end_comment

begin_function_decl
name|int
name|FUAbortRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-U-ABORT.REQUEST */
end_comment

begin_function_decl
name|int
name|FWaitRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-WAIT.REQUEST (pseudo) */
end_comment

begin_function_decl
name|int
name|FManageRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-MANAGE.REQUEST (group) */
end_comment

begin_function_decl
name|int
name|FManageResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-MANAGE.RESPONSE (group) */
end_comment

begin_function_decl
name|int
name|FBulkBeginRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-BULK-BEGIN.REQUEST (group) */
end_comment

begin_function_decl
name|int
name|FBulkBeginResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-BULK-BEGIN.RESPONSE (group) */
end_comment

begin_function_decl
name|int
name|FBulkEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-BULK-END.REQUEST (group) */
end_comment

begin_function_decl
name|int
name|FBulkEndResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-BULK-END.RESPONSE (group) */
end_comment

begin_function_decl
name|int
name|FAccessRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-{LOCATE,ERASE}.REQUEST */
end_comment

begin_function_decl
name|int
name|FAccessResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-{LOCATE,ERASE}.RESPONSE */
end_comment

begin_function_decl
name|int
name|FReadWriteRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-{READ,WRITE}.REQUEST */
end_comment

begin_function_decl
name|int
name|FDataRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-DATA.REQUEST */
end_comment

begin_function_decl
name|int
name|FDataEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-DATA-END.REQUEST */
end_comment

begin_function_decl
name|int
name|FCancelRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-CANCEL.REQUEST */
end_comment

begin_function_decl
name|int
name|FCancelResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-CANCEL.RESPONSE */
end_comment

begin_function_decl
name|int
name|FTransEndRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-TRANSFER-END.REQUEST */
end_comment

begin_function_decl
name|int
name|FTransEndResponse
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* F-TRANSFER-END.RESPONSE */
end_comment

begin_function_decl
name|int
name|FSetIndications
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* define vector for INDICATION events */
end_comment

begin_function_decl
name|int
name|FSelectMask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* map ftam descriptors for select() */
end_comment

begin_function_decl
name|int
name|FHookRequest
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* set tracing */
end_comment

begin_function_decl
name|int
name|FTraceHook
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* user-defined tracing */
end_comment

begin_function_decl
name|char
modifier|*
name|FErrString
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return FTAM error code in string form */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|isodocument
block|{
name|char
modifier|*
name|id_entry
decl_stmt|;
name|OID
name|id_type
decl_stmt|;
name|OID
name|id_abstract
decl_stmt|;
name|OID
name|id_transfer
decl_stmt|;
name|OID
name|id_model
decl_stmt|;
name|OID
name|id_constraint
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|setisodocument
argument_list|()
decl_stmt|,
name|endisodocument
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|isodocument
modifier|*
name|getisodocument
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isodocument
modifier|*
name|getisodocumentbyentry
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isodocument
modifier|*
name|getisodocumentbytype
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

