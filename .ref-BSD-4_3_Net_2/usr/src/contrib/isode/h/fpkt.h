begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fpkt.h - include file for FTAM provider (FS-PROVIDER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/fpkt.h,v 7.5 91/02/22 09:24:37 mrose Interim $  *  *  * $Log:	fpkt.h,v $  * Revision 7.5  91/02/22  09:24:37  mrose  * Interim 6.8  *   * Revision 7.4  90/11/21  11:32:05  mrose  * sun  *   * Revision 7.3  90/07/01  21:03:44  mrose  * pepsy  *   * Revision 7.2  90/03/23  10:52:53  mrose  * update  *   * Revision 7.1  89/12/14  10:03:41  mrose  * bdt  *   * Revision 7.0  89/11/23  21:55:40  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"FTAM-types.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_FTAM_
end_ifndef

begin_include
include|#
directive|include
file|"ftam.h"
end_include

begin_comment
comment|/* definitions for FS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_AcSAP_
end_ifndef

begin_include
include|#
directive|include
file|"acsap.h"
end_include

begin_comment
comment|/* definitions for AcS-USERs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|FS_GEN
parameter_list|(
name|fsb
parameter_list|)
define|\
value|((fsb -> fsb_flags& FSB_INIT) ? FS_GEN_INITIATOR : FS_GEN_RESPONDER)
end_define

begin_define
define|#
directive|define
name|ftamPsig
parameter_list|(
name|fsb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((fsb = findfsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN_NOREASON, 0, NULLCP, \ 			    "invalid ftam descriptor"); \     } \     if (!(fsb -> fsb_flags& FSB_CONN)) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN (fsb), 0, NULLCP, \ 			    "ftam descriptor not connected"); \     } \     if (fsb -> fsb_flags& FSB_FINN) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN (fsb), 0, NULLCP, \ 			    "ftam descriptor finishing"); \     } \ }
end_define

begin_define
define|#
directive|define
name|ftamFsig
parameter_list|(
name|fsb
parameter_list|,
name|sd
parameter_list|)
define|\
value|{ \     if ((fsb = findfsblk (sd)) == NULL) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN_NOREASON, 0, NULLCP, \ 			    "invalid ftam descriptor"); \     } \     if (!(fsb -> fsb_flags& FSB_CONN)) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN (fsb), 0, NULLCP, \ 			    "ftam descriptor not connected"); \     } \     if (!(fsb -> fsb_flags& FSB_FINN)) { \ 	(void) sigiomask (smask); \ 	return ftamlose (fti, FS_GEN (fsb), 0, NULLCP, \ 			    "ftam descriptor not finishing"); \     } \ }
end_define

begin_define
define|#
directive|define
name|toomuchP
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|,
name|p
parameter_list|)
define|\
value|{ \     if (b == NULL) \ 	n = 0; \     else \ 	if (n> m) \ 	    return ftamlose (fti, FS_GEN_NOREASON, 0, NULLCP, \ 			    "too many %ss", p); \ }
end_define

begin_define
define|#
directive|define
name|missingP
parameter_list|(
name|p
parameter_list|)
define|\
value|{ \     if (p == NULL) \ 	return ftamlose (fti, FS_GEN_NOREASON, 0, NULLCP, \ 			    "mandatory parameter \"%s\" missing", "p"); \ }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__STDC__
end_ifndef

begin_define
define|#
directive|define
name|copyFTAMdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d
comment|/* */
value|_cc = min (i, sizeof d -> d
comment|/* */
value|_data))> 0) \ 	bcopy (base, d -> d
comment|/* */
value|_data, d -> d
comment|/* */
value|_cc); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyFTAMdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
define|\
value|{ \     register int i = len; \     if ((d -> d##_cc = min (i, sizeof d -> d##_data))> 0) \ 	bcopy (base, d -> d##_data, d -> d##_cc); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|copyFTAMdata
parameter_list|(
name|base
parameter_list|,
name|len
parameter_list|,
name|d
parameter_list|)
value|bcopy (base, (char *) d, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|ftamlose
argument_list|()
decl_stmt|,
name|fpktlose
argument_list|()
decl_stmt|,
name|ftamoops
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|ftamblk
block|{
name|struct
name|ftamblk
modifier|*
name|fsb_forw
decl_stmt|;
comment|/* doubly-linked list */
name|struct
name|ftamblk
modifier|*
name|fsb_back
decl_stmt|;
comment|/*   .. */
name|int
name|fsb_fd
decl_stmt|;
comment|/* association descriptor */
name|short
name|fsb_flags
decl_stmt|;
comment|/* our state */
define|#
directive|define
name|FSB_NULL
value|0x0000
define|#
directive|define
name|FSB_CONN
value|0x0001
comment|/* connected */
define|#
directive|define
name|FSB_FINN
value|0x0002
comment|/* other side wants to finish */
define|#
directive|define
name|FSB_INIT
value|0x0004
comment|/* this side initiated the association */
define|#
directive|define
name|FSB_ASYN
value|0x0008
comment|/* asynchronous */
define|#
directive|define
name|FSB_DECHARGE
value|0x0010
comment|/* responder can using charging on deselect */
define|#
directive|define
name|FSB_CANCEL
value|0x0020
comment|/* this side started F-CANCEL */
define|#
directive|define
name|FSB_COLLIDE
value|0x0040
comment|/* collision */
name|short
name|fsb_state
decl_stmt|;
comment|/* more state */
define|#
directive|define
name|FSB_INITIALIZED
value|0
comment|/*   initialized */
define|#
directive|define
name|FSB_MANAGEMENT
value|1
comment|/*   management */
define|#
directive|define
name|FSB_BULKBEGIN
value|2
comment|/*   bulk data begin */
define|#
directive|define
name|FSB_BULKEND
value|3
comment|/*   bulk data end */
define|#
directive|define
name|FSB_DATAIDLE
value|4
comment|/*   data transfer idle */
define|#
directive|define
name|FSB_LOCATE
value|5
comment|/*   locate in progress */
define|#
directive|define
name|FSB_ERASE
value|6
comment|/*   erase in progress */
define|#
directive|define
name|FSB_DATAREAD
value|7
comment|/*   data transfer read */
define|#
directive|define
name|FSB_DATAWRITE
value|8
comment|/*   data transfer write */
define|#
directive|define
name|FSB_DATAFIN1
value|9
comment|/*   data transfer done */
define|#
directive|define
name|FSB_DATAFIN2
value|10
comment|/*     .. */
define|#
directive|define
name|FSB_DATACANCEL
value|11
comment|/*   cancel in progress */
name|int
name|fsb_group
decl_stmt|;
comment|/* group flags */
name|int
name|fsb_srequirements
decl_stmt|;
comment|/* session requirements */
name|int
name|fsb_owned
decl_stmt|;
comment|/* session tokens we own */
name|int
name|fsb_avail
decl_stmt|;
comment|/* session tokens available */
name|int
name|fsb_settings
decl_stmt|;
comment|/* initial and resync settings */
name|long
name|fsb_ssn
decl_stmt|;
comment|/* serial number */
name|struct
name|SSAPref
name|fsb_connect
decl_stmt|;
comment|/* session connection reference */
name|int
name|fsb_ssdusize
decl_stmt|;
comment|/* largest atomic SSDU */
name|int
name|fsb_id
decl_stmt|;
comment|/* FTAM context id */
name|int
name|fsb_prequirements
decl_stmt|;
comment|/* presentation requirements */
name|struct
name|PSAPctxlist
name|fsb_contexts
decl_stmt|;
comment|/* presentation contexts */
name|struct
name|FTAMcontentlist
name|fsb_contents
decl_stmt|;
comment|/* FTAM document types */
name|OID
name|fsb_context
decl_stmt|;
comment|/* application context */
name|int
name|fsb_fqos
decl_stmt|;
comment|/* ftam-QoS */
name|int
name|fsb_class
decl_stmt|;
comment|/* service-class */
name|int
name|fsb_units
decl_stmt|;
comment|/* functional-units */
comment|/* mandatory functional-units */
define|#
directive|define
name|FUNITS_TRANSFER
value|(FUNIT_GROUPING)
define|#
directive|define
name|FUNITS_ACCESS
value|(FUNIT_READ | FUNIT_WRITE | FUNIT_ACCESS)
define|#
directive|define
name|FUNITS_MANAGE
value|(FUNIT_LIMITED | FUNIT_GROUPING)
define|#
directive|define
name|FUNITS_TM
value|(FUNIT_LIMITED | FUNIT_GROUPING)
define|#
directive|define
name|FUNITS_UNCONS
value|(0)
name|int
name|fsb_attrs
decl_stmt|;
comment|/* attribute-groups */
name|IFP
name|fsb_indication
decl_stmt|;
comment|/* event handler */
name|struct
name|PSAPdata
name|fsb_data
decl_stmt|;
comment|/* for screwy BDT stuff */
name|int
name|fsb_cancelaction
decl_stmt|;
comment|/* handle CANCEL collisions */
name|PE
name|fsb_cancelshared
decl_stmt|;
name|struct
name|FTAMdiagnostic
modifier|*
name|fsb_canceldiags
decl_stmt|;
name|int
name|fsb_cancelndiag
decl_stmt|;
name|IFP
name|fsb_trace
decl_stmt|;
comment|/* user-defined tracing function */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLFSB
value|((struct ftamblk *) 0)
end_define

begin_function_decl
name|int
name|freefsblk
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|ftamblk
modifier|*
name|newfsblk
argument_list|()
decl_stmt|,
modifier|*
name|findfsblk
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|fsbtrace
parameter_list|(
name|fsb
parameter_list|,
name|a
parameter_list|)
value|if ((fsb) -> fsb_trace) (*((fsb) -> fsb_trace)) a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|fsbtrace
parameter_list|(
name|fsb
parameter_list|,
name|a
parameter_list|)
value|FTraceHook a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|pair
block|{
name|int
name|p_mask
decl_stmt|;
name|int
name|p_bitno
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|pair
name|fclass_pairs
index|[]
decl_stmt|,
name|funit_pairs
index|[]
decl_stmt|,
name|fattr_pairs
index|[]
decl_stmt|,
name|fname_pairs
index|[]
decl_stmt|,
name|fmode_pairs
index|[]
decl_stmt|,
name|frequested_pairs
index|[]
decl_stmt|,
name|fpermitted_pairs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|struct
name|type_FTAM_Access__Control__List
modifier|*
name|acl2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2acl
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_Read__Attributes
modifier|*
name|attr2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2attr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|bits2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2bits
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_Charging
modifier|*
name|chrg2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2chrg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_Concurrency__Access
modifier|*
name|conacc2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2conacc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_Concurrency__Control
modifier|*
name|conctl2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2conctl
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|conctl_present
parameter_list|(
name|fc
parameter_list|)
define|\
value|((fc) -> fc_readlock != FLOCK_NOTREQD \ 	|| (fc) -> fc_insertlock != FLOCK_NOTREQD \ 	|| (fc) -> fc_replacelock != FLOCK_NOTREQD \ 	|| (fc) -> fc_extendlock != FLOCK_NOTREQD \ 	|| (fc) -> fc_eraselock != FLOCK_NOTREQD \ 	|| (fc) -> fc_readattrlock != FLOCK_NOTREQD \ 	|| (fc) -> fc_chngattrlock != FLOCK_NOTREQD \ 	|| (fc) -> fc_deletelock != FLOCK_NOTREQD) \   struct type_FTAM_Diagnostic *diag2fpm ();
end_define

begin_function_decl
name|int
name|fpm2diag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_FADU__Identity
modifier|*
name|faduid2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2faduid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|type_FTAM_Access__Passwords
modifier|*
name|pass2fpm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fpm2pass
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|passes_present
parameter_list|(
name|fp
parameter_list|)
define|\
value|((fp) -> fp_read || (fp) -> fp_insert || (fp) -> fp_replace \ 	|| (fp) -> fp_extend || (fp) -> fp_erase || (fp) -> fp_readattr \ 	|| (fp) -> fp_chngattr || (fp) -> fp_delete) \  struct type_FTAM_Shared__ASE__Information *shared2fpm ();
end_define

begin_function_decl
name|int
name|fpm2shared
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
name|int
name|acs2ftamlose
argument_list|()
decl_stmt|,
name|acs2ftamabort
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ps2ftamlose
parameter_list|()
function_decl|;
end_function_decl

end_unit

