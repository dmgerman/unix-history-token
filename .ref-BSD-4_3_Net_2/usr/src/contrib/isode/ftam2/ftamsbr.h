begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ftamsbr.h - include file for FTAM initiator/responder subroutines */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/ftam2/RCS/ftamsbr.h,v 7.2 91/02/22 09:24:07 mrose Interim $  *  *  * $Log:	ftamsbr.h,v $  * Revision 7.2  91/02/22  09:24:07  mrose  * Interim 6.8  *   * Revision 7.1  90/07/01  21:03:34  mrose  * pepsy  *   * Revision 7.0  89/11/23  21:54:39  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_include
include|#
directive|include
file|"ftam.h"
end_include

begin_comment
comment|/* definitions for FS-USERs */
end_comment

begin_include
include|#
directive|include
file|"DOCS-types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NULL
end_ifdef

begin_undef
undef|#
directive|undef
name|NULL
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_define
define|#
directive|define
name|NULL
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYS5
end_ifndef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|L_SET
value|0
end_define

begin_comment
comment|/* absolute offset */
end_comment

begin_define
define|#
directive|define
name|L_INCR
value|1
end_define

begin_comment
comment|/* relative to current offset */
end_comment

begin_define
define|#
directive|define
name|L_XTND
value|2
end_define

begin_comment
comment|/* relative to end of file */
end_comment

begin_define
define|#
directive|define
name|F_OK
value|0
end_define

begin_comment
comment|/* file exists */
end_comment

begin_define
define|#
directive|define
name|X_OK
value|1
end_define

begin_comment
comment|/* executable by caller */
end_comment

begin_define
define|#
directive|define
name|W_OK
value|2
end_define

begin_comment
comment|/* writable by caller */
end_comment

begin_define
define|#
directive|define
name|R_OK
value|4
end_define

begin_comment
comment|/* readable by caller */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HPUX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|AUX
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"usr.dirent.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAXPATHLEN
end_ifndef

begin_define
define|#
directive|define
name|MAXPATHLEN
value|MAXNAMLEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MAXBSIZE
end_ifdef

begin_define
define|#
directive|define
name|BLKSIZE
value|MAXBSIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BLKSIZE
value|BUFSIZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*    Used to calculate the estimated integral FADU size:      FTAM-3 transfers -  	An FADU maps onto a single PSDU with the P-DATA service.  Because the 	DCS is non-empty and the FADU is not in the default context, the 	Fully-encoded-data encoding is used.  Further, since only one PSDU is 	present, the single-ASN1-type option is used.  Hence, the outer ASN.1 	wrapper consists of  	    [APPLICATION 1] IMPLICIT 		SEQUENCE OF {	-- 4 octets for the outer structure 		    SEQUENCE {	-- 4 octets for the one and only PDV-list  				-- 3 octets for the PCI 		        presentation-context-identifier 		            INTEGER,  		        presentation-data-values { 				-- 4 octets for the single-ASN1-type wrapper 		            single-ASN1-type[0] 				-- 4 octets for the id/length of the FADU 				-- n octets for the data in the FADU 			        ANY 			} 		    } 		}       4 + 4 + 3 + 4 + 4 = 19       For each structure, 4 octets is used for non-data encodings 		1 octet for the ID 		1 octet for an indefinite form 		2 octets for the EOC     If the data portion is smaller, then the definite form might be used which     requires 3 octets, not 4.      FTAM-1 transfers -  	FADUs are batched to the P-DATA service.  This means that the 	octet-aligned option is used.  Hence, the outer ASN.1 wrapper 	consists of    	    [APPLICATION 1] IMPLICIT 		SEQUENCE OF {	-- 4 octets for the outer structure  -- this sequence is repeated for each member of the batch  		    SEQUENCE {	-- 4 octets for the one and only PDV-list  				-- 3 octets for the PCI 		        presentation-context-identifier 		            INTEGER,  		        presentation-data-values { 				-- 4 octets for the octet-aligned wrapper 		            octet-aligned[1] 				-- 4 octets for the id/length of the FADU 				-- n octets for the data in the FADU 			        IMPLICIT OCTET STRING 			} 		    }   		}       4 + N*(4 + 3 + 4 + 4)  */
end_comment

begin_define
define|#
directive|define
name|MAGIC_SINGLE
value|19
end_define

begin_define
define|#
directive|define
name|MAGIC_OCTET1
value|4
end_define

begin_define
define|#
directive|define
name|MAGIC_OCTET2
value|15
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|vfsmap
block|{
name|char
modifier|*
name|vf_entry
decl_stmt|;
comment|/* document entry */
name|OID
name|vf_oid
decl_stmt|;
comment|/* object identifier */
name|caddr_t
name|vf_parameter
decl_stmt|;
comment|/* parameter, filled-in by vf_peek */
name|int
name|vf_flags
decl_stmt|;
comment|/* flags */
define|#
directive|define
name|VF_NULL
value|0x00
define|#
directive|define
name|VF_OK
value|0x01
comment|/* negotiated */
define|#
directive|define
name|VF_WARN
value|0x02
comment|/* warn if loses */
define|#
directive|define
name|VF_PARM
value|0x04
comment|/* parameter dynamically allocated */
name|int
name|vf_id
decl_stmt|;
comment|/* presentation context */
name|int
name|vf_mode
decl_stmt|;
comment|/* st.st_mode& S_IFMT bits */
name|IFP
name|vf_peek
decl_stmt|;
comment|/* sees if really this type of file */
name|char
name|vf_stat
decl_stmt|;
comment|/* stat character for 'ls' */
name|int
name|vf_simplify
decl_stmt|;
comment|/* the next document type to try */
define|#
directive|define
name|VFS_XXX
value|(-1)
name|int
name|vf_context
decl_stmt|;
comment|/* access context */
comment|/* really should have entire constraint set */
name|int
name|vf_mandatory
decl_stmt|;
comment|/*> 0 parameter required< 0 parameter optional 				  == 0 parameter illegal */
name|IFP
name|vf_check
decl_stmt|;
comment|/*   .. check */
name|int
name|vf_number
decl_stmt|;
comment|/* encode/decode index */
name|char
modifier|*
name|vf_text
decl_stmt|;
comment|/* textual description */
block|}
struct|;
end_struct

begin_function_decl
name|struct
name|vfsmap
modifier|*
name|st2vfs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* WATCHP is one pepsy people should use as the macro which is  * not expansion order dependant  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEBUG
end_ifndef

begin_define
define|#
directive|define
name|WATCH
parameter_list|(
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
end_define

begin_define
define|#
directive|define
name|WATCHP
parameter_list|(
name|args
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|WATCHP
parameter_list|(
name|args
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
define|\
value|pvpdu (ftam_log, print_##args##_P, pe, \ 	rw ? "F-DATA.INDICATION" : "F-DATA.REQUEST", rw)
end_define

begin_define
define|#
directive|define
name|WATCH
parameter_list|(
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
define|\
value|pvpdu (ftam_log, fnx
comment|/**/
value|_P, pe, \ 	rw ? "F-DATA.INDICATION" : "F-DATA.REQUEST", rw)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WATCHP
parameter_list|(
name|args
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
define|\
value|pvpdu (ftam_log, print_
comment|/**/
value|args
comment|/**/
value|_P, pe, \ 	rw ? "F-DATA.INDICATION" : "F-DATA.REQUEST", rw)
end_define

begin_define
define|#
directive|define
name|WATCH
parameter_list|(
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|rw
parameter_list|)
define|\
value|pvpdu (ftam_log, fnx
comment|/**/
value|_P, pe, \ 	rw ? "F-DATA.INDICATION" : "F-DATA.REQUEST", rw)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|binarypeek
argument_list|()
decl_stmt|,
name|textpeek
argument_list|()
decl_stmt|,
name|fdfpeek
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|binarycheck
argument_list|()
decl_stmt|,
name|textcheck
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_define
define|#
directive|define
name|FA_RDATTR
define|\
value|(FA_FILENAME | FA_ACTIONS | FA_CONTENTS | FA_ACCOUNT | FA_DATE_CREATE \ 	| FA_DATE_MODIFY | FA_DATE_READ | FA_DATE_ATTR | FA_ID_CREATE \ 	| FA_ID_MODIFY | FA_ID_READ | FA_ID_ATTR | FA_AVAILABILITY \ 	| FA_FILESIZE)
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BRIDGE
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|ftp_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ftp_directory
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|de2fd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|compath
parameter_list|()
function_decl|;
end_function_decl

end_unit

