begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* isoaddrs.h - ISODE addressing */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/isoaddrs.h,v 7.8 91/02/22 09:24:44 mrose Interim $  *  *  * $Log:	isoaddrs.h,v $  * Revision 7.8  91/02/22  09:24:44  mrose  * Interim 6.8  *   * Revision 7.7  90/12/11  10:54:02  mrose  * lock-and-load  *   * Revision 7.6  90/10/29  18:38:09  mrose  * updates  *   * Revision 7.5  90/10/15  18:20:37  mrose  * unused  *   * Revision 7.4  90/07/09  14:37:47  mrose  * sync  *   * Revision 7.3  90/05/08  08:54:34  mrose  * touch-up  *   * Revision 7.2  90/03/15  11:17:58  mrose  * quipu-sync  *   * Revision 7.1  89/11/30  23:54:02  mrose  * pa2str  *   * Revision 7.0  89/11/23  21:55:46  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ISOADDRS_
end_ifndef

begin_define
define|#
directive|define
name|_ISOADDRS_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MANIFEST_
end_ifndef

begin_include
include|#
directive|include
file|"manifest.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_GENERAL_
end_ifndef

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NULLPE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|AEInfo
block|{
comment|/* "real" directory services! */
name|PE
name|aei_ap_title
decl_stmt|;
name|PE
name|aei_ae_qualifier
decl_stmt|;
name|int
name|aei_ap_id
decl_stmt|;
name|int
name|aei_ae_id
decl_stmt|;
name|int
name|aei_flags
decl_stmt|;
define|#
directive|define
name|AEI_NULL
value|0x00
define|#
directive|define
name|AEI_AP_ID
value|0x01
define|#
directive|define
name|AEI_AE_ID
value|0x02
block|}
name|AEInfo
operator|,
typedef|*
name|AEI
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLAEI
value|((AEI) 0)
end_define

begin_define
define|#
directive|define
name|AEIFREE
parameter_list|(
name|aei
parameter_list|)
value|{ \     if ((aei) -> aei_ap_title) \ 	pe_free ((aei) -> aei_ap_title), \ 	    (aei) -> aei_ap_title = NULLPE; \     if ((aei) -> aei_ae_qualifier) \ 	pe_free ((aei) -> aei_ae_qualifier), \ 	    (aei) -> aei_ae_qualifier = NULLPE; \ }
end_define

begin_define
define|#
directive|define
name|str2aei
parameter_list|(
name|d
parameter_list|,
name|q
parameter_list|)
value|_str2aei ((d), (q), NULLCP, 0, NULLCP, NULLCP)
end_define

begin_define
define|#
directive|define
name|str2aeinfo
parameter_list|(
name|string
parameter_list|,
name|context
parameter_list|,
name|interactive
parameter_list|,
name|userdn
parameter_list|,
name|passwd
parameter_list|)
define|\
value|_str2aei ((string), NULLCP, (context), (interactive), (userdn), \ 		  (passwd))
end_define

begin_function_decl
name|AEI
name|_str2aei
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sprintaei
parameter_list|()
function_decl|;
end_function_decl

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
name|NSAPaddr
block|{
comment|/* this structure shouldn't have holes in it */
name|long
name|na_stack
decl_stmt|;
comment|/* TS-stack */
define|#
directive|define
name|NA_NSAP
value|0
comment|/*   native COTS */
define|#
directive|define
name|NA_TCP
value|1
comment|/*   RFC1006/TCP */
define|#
directive|define
name|NA_X25
value|2
comment|/*   TP0/X.25 */
define|#
directive|define
name|NA_BRG
value|3
comment|/*   TP0-bridge */
name|long
name|na_community
decl_stmt|;
comment|/* internal community # */
define|#
directive|define
name|SUBNET_REALNS
value|(-1)
comment|/* hard-wired */
define|#
directive|define
name|SUBNET_INT_X25
value|1
comment|/* (unused) #define	SUBNET_JANET		2  */
define|#
directive|define
name|SUBNET_INTERNET
value|3
define|#
directive|define
name|SUBNET_DYNAMIC
value|100
comment|/* dynamic start here... */
union|union
block|{
struct|struct
name|na_nsap
block|{
comment|/* real network service */
define|#
directive|define
name|NASIZE
value|64
comment|/* 20 ought to do it */
name|char
name|na_nsap_address
index|[
name|NASIZE
index|]
decl_stmt|;
name|char
name|na_nsap_addrlen
decl_stmt|;
block|}
name|un_na_nsap
struct|;
struct|struct
name|na_tcp
block|{
comment|/* emulation via RFC1006 */
define|#
directive|define
name|NSAP_DOMAINLEN
value|63
name|char
name|na_tcp_domain
index|[
name|NSAP_DOMAINLEN
operator|+
literal|1
index|]
decl_stmt|;
name|u_short
name|na_tcp_port
decl_stmt|;
comment|/* non-standard TCP port */
name|u_short
name|na_tcp_tset
decl_stmt|;
comment|/* transport set */
define|#
directive|define
name|NA_TSET_TCP
value|0x0001
comment|/*   .. TCP */
define|#
directive|define
name|NA_TSET_UDP
value|0x0002
comment|/*   .. UDP */
block|}
name|un_na_tcp
struct|;
struct|struct
name|na_x25
block|{
comment|/* X.25 (assume single subnet) */
define|#
directive|define
name|NSAP_DTELEN
value|36
name|char
name|na_x25_dte
index|[
name|NSAP_DTELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* Numeric DTE + Link */
name|char
name|na_x25_dtelen
decl_stmt|;
comment|/* number of digits used */
comment|/* Conventionally, the PID sits at the first head bytes of user data and so  * should probably not be mentioned specially. A macro might do it, if  * necessary.  */
define|#
directive|define
name|NPSIZE
value|4
name|char
name|na_x25_pid
index|[
name|NPSIZE
index|]
decl_stmt|;
comment|/* X.25 protocol id */
name|char
name|na_x25_pidlen
decl_stmt|;
comment|/*   .. */
define|#
directive|define
name|CUDFSIZE
value|16
name|char
name|na_x25_cudf
index|[
name|CUDFSIZE
index|]
decl_stmt|;
comment|/* call user data field */
name|char
name|na_x25_cudflen
decl_stmt|;
comment|/* .. */
comment|/*  * X25 Facilities field.   */
define|#
directive|define
name|FACSIZE
value|6
name|char
name|na_x25_fac
index|[
name|FACSIZE
index|]
decl_stmt|;
comment|/* X.25 facilities */
name|char
name|na_x25_faclen
decl_stmt|;
comment|/*   .. */
block|}
name|un_na_x25
struct|;
block|}
name|na_un
union|;
define|#
directive|define
name|na_address
value|na_un.un_na_nsap.na_nsap_address
define|#
directive|define
name|na_addrlen
value|na_un.un_na_nsap.na_nsap_addrlen
define|#
directive|define
name|na_domain
value|na_un.un_na_tcp.na_tcp_domain
define|#
directive|define
name|na_port
value|na_un.un_na_tcp.na_tcp_port
define|#
directive|define
name|na_tset
value|na_un.un_na_tcp.na_tcp_tset
define|#
directive|define
name|na_dte
value|na_un.un_na_x25.na_x25_dte
define|#
directive|define
name|na_dtelen
value|na_un.un_na_x25.na_x25_dtelen
define|#
directive|define
name|na_pid
value|na_un.un_na_x25.na_x25_pid
define|#
directive|define
name|na_pidlen
value|na_un.un_na_x25.na_x25_pidlen
define|#
directive|define
name|na_cudf
value|na_un.un_na_x25.na_x25_cudf
define|#
directive|define
name|na_cudflen
value|na_un.un_na_x25.na_x25_cudflen
define|#
directive|define
name|na_fac
value|na_un.un_na_x25.na_x25_fac
define|#
directive|define
name|na_faclen
value|na_un.un_na_x25.na_x25_faclen
comment|/* for backwards compatibility... these two will be removed after ISODE 7.0 */
define|#
directive|define
name|na_type
value|na_stack
define|#
directive|define
name|na_subnet
value|na_community
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLNA
value|((struct NSAPaddr *) 0)
end_define

begin_struct
struct|struct
name|TSAPaddr
block|{
define|#
directive|define
name|NTADDR
value|8
comment|/* according to NIST OIW */
name|struct
name|NSAPaddr
name|ta_addrs
index|[
name|NTADDR
index|]
decl_stmt|;
comment|/* choice of network addresses */
name|int
name|ta_naddr
decl_stmt|;
define|#
directive|define
name|TSSIZE
value|64
name|int
name|ta_selectlen
decl_stmt|;
union|union
block|{
comment|/* TSAP selector */
name|char
name|ta_un_selector
index|[
name|TSSIZE
index|]
decl_stmt|;
name|u_short
name|ta_un_port
decl_stmt|;
block|}
name|un_ta
union|;
define|#
directive|define
name|ta_selector
value|un_ta.ta_un_selector
define|#
directive|define
name|ta_port
value|un_ta.ta_un_port
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLTA
value|((struct TSAPaddr *) 0)
end_define

begin_struct
struct|struct
name|SSAPaddr
block|{
name|struct
name|TSAPaddr
name|sa_addr
decl_stmt|;
comment|/* transport address */
define|#
directive|define
name|SSSIZE
value|64
name|int
name|sa_selectlen
decl_stmt|;
union|union
block|{
comment|/* SSAP selector */
name|char
name|sa_un_selector
index|[
name|SSSIZE
index|]
decl_stmt|;
name|u_short
name|sa_un_port
decl_stmt|;
block|}
name|un_sa
union|;
define|#
directive|define
name|sa_selector
value|un_sa.sa_un_selector
define|#
directive|define
name|sa_port
value|un_sa.sa_un_port
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLSA
value|((struct SSAPaddr *) 0)
end_define

begin_struct
struct|struct
name|PSAPaddr
block|{
name|struct
name|SSAPaddr
name|pa_addr
decl_stmt|;
comment|/* session address */
define|#
directive|define
name|PSSIZE
value|64
name|int
name|pa_selectlen
decl_stmt|;
union|union
block|{
comment|/* PSAP selector */
name|char
name|pa_un_selector
index|[
name|PSSIZE
index|]
decl_stmt|;
name|u_short
name|pa_un_port
decl_stmt|;
block|}
name|un_pa
union|;
define|#
directive|define
name|pa_selector
value|un_pa.pa_un_selector
define|#
directive|define
name|pa_port
value|un_pa.pa_un_port
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLPA
value|((struct PSAPaddr *) 0)
end_define

begin_function_decl
name|struct
name|PSAPaddr
modifier|*
name|aei2addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* application entity title to PSAPaddr */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NULLPE
end_ifdef

begin_function_decl
name|char
modifier|*
name|alias2name
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|PE
function_decl|(
modifier|*
name|acsap_lookup
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NULLOID
end_ifdef

begin_struct
struct|struct
name|isoentity
block|{
comment|/* for stub directory service */
name|OIDentifier
name|ie_identifier
decl_stmt|;
name|char
modifier|*
name|ie_descriptor
decl_stmt|;
name|struct
name|PSAPaddr
name|ie_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|setisoentity
argument_list|()
decl_stmt|,
name|endisoentity
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|isoentity
modifier|*
name|getisoentity
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|AEI
name|oid2aei
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* old-style */
end_comment

begin_function_decl
name|struct
name|PSAPaddr
modifier|*
name|is2paddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* service entry to PSAPaddr */
end_comment

begin_function_decl
name|struct
name|SSAPaddr
modifier|*
name|is2saddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* service entry to SSAPaddr */
end_comment

begin_function_decl
name|struct
name|TSAPaddr
modifier|*
name|is2taddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* service entry to TSAPaddr */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|struct
name|PSAPaddr
modifier|*
name|str2paddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string encoding to PSAPaddr */
end_comment

begin_function_decl
name|struct
name|SSAPaddr
modifier|*
name|str2saddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string encoding to SSAPaddr */
end_comment

begin_function_decl
name|struct
name|TSAPaddr
modifier|*
name|str2taddr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* string encoding to TSAPaddr */
end_comment

begin_define
define|#
directive|define
name|paddr2str
parameter_list|(
name|pa
parameter_list|,
name|na
parameter_list|)
value|_paddr2str ((pa), (na), 0)
end_define

begin_function_decl
name|char
modifier|*
name|_paddr2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* PSAPaddr to string encoding */
end_comment

begin_function_decl
name|char
modifier|*
name|saddr2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* SSAPaddr to string encoding */
end_comment

begin_function_decl
name|char
modifier|*
name|taddr2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* TSAPaddr to string encoding */
end_comment

begin_function_decl
name|struct
name|NSAPaddr
modifier|*
name|na2norm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* normalize NSAPaddr */
end_comment

begin_function_decl
name|char
modifier|*
name|na2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* pretty-print NSAPaddr */
end_comment

begin_function_decl
name|char
modifier|*
name|pa2str
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* pretty-print PSAPaddr */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_function_decl
name|int
name|isodeserver
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generic server dispatch */
end_comment

begin_function_decl
name|int
name|iserver_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* phase 1 */
end_comment

begin_function_decl
name|int
name|iserver_wait
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* phase 2 */
end_comment

begin_function_decl
name|fd_set
name|iserver_mask
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* linkage */
end_comment

begin_comment
comment|/*
comment|*/
end_comment

begin_comment
comment|/* all of this really should be in "isoqos.h" ... */
end_comment

begin_struct
struct|struct
name|QOStype
block|{
comment|/* transport QOS */
name|int
name|qos_reliability
decl_stmt|;
comment|/* "reliability" element */
define|#
directive|define
name|HIGH_QUALITY
value|0
define|#
directive|define
name|LOW_QUALITY
value|1
comment|/* session QOS */
name|int
name|qos_sversion
decl_stmt|;
comment|/* session version required */
name|int
name|qos_extended
decl_stmt|;
comment|/* extended control */
name|int
name|qos_maxtime
decl_stmt|;
comment|/* for SPM response during S-CONNECT */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NULLQOS
value|((struct QOStype *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

