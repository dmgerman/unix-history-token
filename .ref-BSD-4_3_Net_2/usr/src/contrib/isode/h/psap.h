begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* psap.h - include file for presentation users (PS-USER) */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/psap.h,v 7.7 91/02/22 09:24:54 mrose Interim $  *  *  * $Log:	psap.h,v $  * Revision 7.7  91/02/22  09:24:54  mrose  * Interim 6.8  *   * Revision 7.6  91/02/20  17:26:47  mrose  * update  *   * Revision 7.5  91/01/07  12:39:28  mrose  * update  *   * Revision 7.4  90/10/23  20:35:50  mrose  * update  *   * Revision 7.3  90/07/27  08:44:43  mrose  * update  *   * Revision 7.2  90/07/01  21:03:50  mrose  * pepsy  *   * Revision 7.1  90/03/22  08:39:21  mrose  * touch-up  *   * Revision 7.0  89/11/23  21:55:52  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PSAP_
end_ifndef

begin_define
define|#
directive|define
name|_PSAP_
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

begin_ifndef
ifndef|#
directive|ifndef
name|OSX
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|BSD42
end_ifndef

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|timerisset
end_ifndef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|<math.h>
end_include

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|OIDentifier
block|{
name|int
name|oid_nelem
decl_stmt|;
comment|/* number of sub-identifiers */
name|unsigned
name|int
modifier|*
name|oid_elements
decl_stmt|;
comment|/* the (ordered) list of sub-identifiers */
block|}
name|OIDentifier
operator|,
typedef|*
name|OID
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLOID
value|((OID) 0)
end_define

begin_function_decl
name|OID
name|ode2oid
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|oid_cmp
argument_list|()
decl_stmt|,
name|elem_cmp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|OID
name|oid_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|oid_free
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|oid2ode
parameter_list|(
name|i
parameter_list|)
value|oid2ode_aux ((i), 1)
end_define

begin_function_decl
name|char
modifier|*
name|oid2ode_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|sprintoid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|OID
name|str2oid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
name|u_char
name|PElementClass
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|PElementForm
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_short
name|PElementID
typedef|;
end_typedef

begin_comment
comment|/* 0..16383 are meaningful (14 bits) */
end_comment

begin_define
define|#
directive|define
name|PE_ID_BITS
value|14
end_define

begin_define
define|#
directive|define
name|PE_ID
parameter_list|(
name|class
parameter_list|,
name|code
parameter_list|)
define|\
value|((int) ((((code)& 0x3fff)<< 2) | ((class)& 0x0003)))
end_define

begin_typedef
typedef|typedef
name|int
name|PElementLen
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|byte
typedef|,
modifier|*
name|PElementData
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLPED
value|((PElementData) 0)
end_define

begin_define
define|#
directive|define
name|PEDalloc
parameter_list|(
name|s
parameter_list|)
value|((PElementData) malloc ((unsigned int) (s)))
end_define

begin_define
define|#
directive|define
name|PEDrealloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|((PElementData) \ 				    realloc ((char *) (p), (unsigned int) (s)))
end_define

begin_define
define|#
directive|define
name|PEDfree
parameter_list|(
name|p
parameter_list|)
value|free ((char *) (p))
end_define

begin_define
define|#
directive|define
name|PEDcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
define|\
value|bcmp ((char *) (b1), (char *) (b2), (int) (length))
end_define

begin_define
define|#
directive|define
name|PEDcpy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|length
parameter_list|)
define|\
value|bcopy ((char *) (b1), (char *) (b2), (int) (length))
end_define

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|PElement
block|{
name|int
name|pe_errno
decl_stmt|;
comment|/* Error codes */
define|#
directive|define
name|PE_ERR_NONE
value|0
comment|/*   No error */
define|#
directive|define
name|PE_ERR_OVER
value|1
comment|/*   Overflow */
define|#
directive|define
name|PE_ERR_NMEM
value|2
comment|/*   Out of memory */
define|#
directive|define
name|PE_ERR_BIT
value|3
comment|/*   No such bit */
define|#
directive|define
name|PE_ERR_UTCT
value|4
comment|/*   Malformed universal timestring */
define|#
directive|define
name|PE_ERR_GENT
value|5
comment|/*   Malformed generalized timestring */
define|#
directive|define
name|PE_ERR_MBER
value|6
comment|/*   No such member */
define|#
directive|define
name|PE_ERR_PRIM
value|7
comment|/*   Not a primitive form */
define|#
directive|define
name|PE_ERR_CONS
value|8
comment|/*   Not a constructor form */
define|#
directive|define
name|PE_ERR_TYPE
value|9
comment|/*   Class/ID mismatch in constructor */
define|#
directive|define
name|PE_ERR_OID
value|10
comment|/*   Malformed object identifier */
define|#
directive|define
name|PE_ERR_BITS
value|11
comment|/*   Malformed bitstring */
define|#
directive|define
name|PE_ERR_NOSUPP
value|12
comment|/*   Type not supported */
define|#
directive|define
name|PE_ERR_SIGNED
value|13
comment|/*   Signed integer not expected */
comment|/* for the PSAP */
name|int
name|pe_context
decl_stmt|;
comment|/* indirect reference */
define|#
directive|define
name|PE_DFLT_CTX
value|0
comment|/*   the default context */
define|#
directive|define
name|PE_ID_XTND
value|0x1f
comment|/* distinguished ID for extension bits */
define|#
directive|define
name|PE_ID_MORE
value|0x80
comment|/* more to come flag */
define|#
directive|define
name|PE_ID_MASK
value|0x7f
comment|/* value in extension byte */
define|#
directive|define
name|PE_ID_SHIFT
value|7
define|#
directive|define
name|PE_CLASS_MASK
value|0xc0
comment|/* identifier class bits (8-7) */
define|#
directive|define
name|PE_CLASS_SHIFT
value|6
define|#
directive|define
name|PE_FORM_MASK
value|0x20
comment|/* identifier form bit (6) */
define|#
directive|define
name|PE_FORM_SHIFT
value|5
define|#
directive|define
name|PE_CODE_MASK
value|0x1f
comment|/* identifier code bits (5-1) + ... */
define|#
directive|define
name|PE_CODE_SHIFT
value|0
name|PElementClass
name|pe_class
decl_stmt|;
define|#
directive|define
name|PE_CLASS_UNIV
value|0x0
comment|/*   Universal */
define|#
directive|define
name|PE_CLASS_APPL
value|0x1
comment|/*   Application-wide */
define|#
directive|define
name|PE_CLASS_CONT
value|0x2
comment|/*   Context-specific */
define|#
directive|define
name|PE_CLASS_PRIV
value|0x3
comment|/*   Private-use */
name|PElementForm
name|pe_form
decl_stmt|;
define|#
directive|define
name|PE_FORM_PRIM
value|0x0
comment|/*   PRIMitive */
define|#
directive|define
name|PE_FORM_CONS
value|0x1
comment|/*   CONStructor */
define|#
directive|define
name|PE_FORM_ICONS
value|0x2
comment|/*   internal: Inline CONStructor */
name|PElementID
name|pe_id
decl_stmt|;
comment|/* should be extensible, 14 bits for now */
comment|/* Pseudo Types */
define|#
directive|define
name|PE_UNIV_EOC
value|0x000
comment|/*   End-of-contents */
comment|/* Built-in Types */
define|#
directive|define
name|PE_PRIM_BOOL
value|0x001
comment|/*   Boolean */
define|#
directive|define
name|PE_PRIM_INT
value|0x002
comment|/*   Integer */
define|#
directive|define
name|PE_PRIM_BITS
value|0x003
comment|/*   Bitstring */
define|#
directive|define
name|PE_PRIM_OCTS
value|0x004
comment|/*   Octetstring */
define|#
directive|define
name|PE_PRIM_NULL
value|0x005
comment|/*   Null */
define|#
directive|define
name|PE_PRIM_OID
value|0x006
comment|/*   Object identifier */
define|#
directive|define
name|PE_PRIM_ODE
value|0x007
comment|/*   Object descriptor */
define|#
directive|define
name|PE_CONS_EXTN
value|0x008
comment|/*   External */
define|#
directive|define
name|PE_PRIM_REAL
value|0x009
comment|/*   Real */
define|#
directive|define
name|PE_PRIM_ENUM
value|0x00a
comment|/*   Enumerated type */
define|#
directive|define
name|PE_PRIM_ENCR
value|0x00b
comment|/*   Encrypted */
define|#
directive|define
name|PE_CONS_SEQ
value|0x010
comment|/*   Sequence */
define|#
directive|define
name|PE_CONS_SET
value|0x011
comment|/*   Set */
comment|/* Defined Types */
define|#
directive|define
name|PE_DEFN_NUMS
value|0x012
comment|/*   Numeric String */
define|#
directive|define
name|PE_DEFN_PRTS
value|0x013
comment|/*   Printable String */
define|#
directive|define
name|PE_DEFN_T61S
value|0x014
comment|/*   T.61 String */
define|#
directive|define
name|PE_DEFN_VTXS
value|0x015
comment|/*   Videotex String */
define|#
directive|define
name|PE_DEFN_IA5S
value|0x016
comment|/*   IA5 String */
define|#
directive|define
name|PE_DEFN_UTCT
value|0x017
comment|/*   UTC Time */
define|#
directive|define
name|PE_DEFN_GENT
value|0x018
comment|/*   Generalized Time */
define|#
directive|define
name|PE_DEFN_GFXS
value|0x019
comment|/*   Graphics string (ISO2375) */
define|#
directive|define
name|PE_DEFN_VISS
value|0x01a
comment|/*   Visible string */
define|#
directive|define
name|PE_DEFN_GENS
value|0x01b
comment|/*   General string */
define|#
directive|define
name|PE_DEFN_CHRS
value|0x01c
comment|/*   Character string */
name|PElementLen
name|pe_len
decl_stmt|;
define|#
directive|define
name|PE_LEN_XTND
value|0x80
comment|/* long or indefinite form */
define|#
directive|define
name|PE_LEN_SMAX
value|127
comment|/* largest short form */
define|#
directive|define
name|PE_LEN_MASK
value|0x7f
comment|/* mask to get number of bytes in length */
define|#
directive|define
name|PE_LEN_INDF
value|(-1)
comment|/* indefinite length */
name|PElementLen
name|pe_ilen
decl_stmt|;
union|union
block|{
name|PElementData
name|un_pe_prim
decl_stmt|;
comment|/* PRIMitive value */
name|struct
name|PElement
modifier|*
name|un_pe_cons
decl_stmt|;
comment|/* CONStructor head */
block|}
name|pe_un1
union|;
define|#
directive|define
name|pe_prim
value|pe_un1.un_pe_prim
define|#
directive|define
name|pe_cons
value|pe_un1.un_pe_cons
union|union
block|{
name|int
name|un_pe_cardinal
decl_stmt|;
comment|/* cardinality of list */
name|int
name|un_pe_nbits
decl_stmt|;
comment|/* number of bits in string */
block|}
name|pe_un2
union|;
define|#
directive|define
name|pe_cardinal
value|pe_un2.un_pe_cardinal
define|#
directive|define
name|pe_nbits
value|pe_un2.un_pe_nbits
name|int
name|pe_inline
decl_stmt|;
comment|/* for "ultra-efficient" PElements */
name|char
modifier|*
name|pe_realbase
decl_stmt|;
comment|/*   .. */
name|int
name|pe_offset
decl_stmt|;
comment|/* offset of element in sequence */
name|struct
name|PElement
modifier|*
name|pe_next
decl_stmt|;
name|int
name|pe_refcnt
decl_stmt|;
comment|/* hack for ANYs in pepy */
ifdef|#
directive|ifdef
name|DEBUG
name|struct
name|PElement
modifier|*
name|pe_link
decl_stmt|;
comment|/* malloc debugging... */
endif|#
directive|endif
block|}
name|PElement
operator|,
typedef|*
name|PE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLPE
value|((PE) 0)
end_define

begin_define
define|#
directive|define
name|NULLPEP
value|((PE *) 0)
end_define

begin_define
define|#
directive|define
name|pe_seterr
parameter_list|(
name|pe
parameter_list|,
name|e
parameter_list|,
name|v
parameter_list|)
value|((pe) -> pe_errno = (e), (v))
end_define

begin_decl_stmt
specifier|extern
name|int
name|pe_allocs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_frees
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_most
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PE
name|pe_list
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|PE
name|pe_active
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|PE
name|pe_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe_cmp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|pe_cpy
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe_pullup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|pe_expunge
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe_extract
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|str2pe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|qb2pe
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|pe_maxclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pe_classlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_maxuniv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pe_univlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_maxappl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|pe_applist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_maxpriv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|pe_privlist
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*
comment|*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|UTCtime
block|{
name|int
name|ut_year
decl_stmt|;
name|int
name|ut_mon
decl_stmt|;
name|int
name|ut_mday
decl_stmt|;
name|int
name|ut_hour
decl_stmt|;
name|int
name|ut_min
decl_stmt|;
name|int
name|ut_sec
decl_stmt|;
name|int
name|ut_usec
decl_stmt|;
name|int
name|ut_zone
decl_stmt|;
name|int
name|ut_flags
decl_stmt|;
define|#
directive|define
name|UT_NULL
value|0x00
define|#
directive|define
name|UT_ZONE
value|0x01
define|#
directive|define
name|UT_SEC
value|0x02
define|#
directive|define
name|UT_USEC
value|0x04
block|}
name|UTCtime
operator|,
typedef|*
name|UTC
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLUTC
value|((UTC) 0)
end_define

begin_function_decl
name|void
name|tm2ut
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|gtime
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tm
modifier|*
name|ut2tm
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|psapversion
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|prim2flag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|flag2prim
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bool2prim
parameter_list|(
name|b
parameter_list|)
value|flag2prim ((b), PE_CLASS_UNIV, PE_PRIM_BOOL)
end_define

begin_function_decl
name|integer
name|prim2num
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|num2prim
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|int2prim
parameter_list|(
name|i
parameter_list|)
value|num2prim ((integer) (i), PE_CLASS_UNIV, PE_PRIM_INT)
end_define

begin_define
define|#
directive|define
name|prim2enum
parameter_list|(
name|i
parameter_list|)
value|prim2num((i))
end_define

begin_define
define|#
directive|define
name|enum2prim
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|num2prim((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|enumint2prim
parameter_list|(
name|i
parameter_list|)
value|enum2prim ((i), PE_CLASS_UNIV, PE_PRIM_ENUM)
end_define

begin_comment
comment|/* psap REAL parameters - tons of 'em */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_FLAGS
value|0300
end_define

begin_comment
comment|/* flag bits of real */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_BINENC
value|0200
end_define

begin_comment
comment|/* binary encoding */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_DECENC
value|0000
end_define

begin_comment
comment|/* decimal encoding */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_SPECENC
value|0100
end_define

begin_comment
comment|/* special encoding */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_B_S
value|0100
end_define

begin_comment
comment|/* sign bit */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_B_BASE
value|0060
end_define

begin_comment
comment|/* base bits */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_B_B2
value|0000
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_B8
value|0020
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_B16
value|0040
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_F
value|0014
end_define

begin_comment
comment|/* factor bits */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_B_EXP
value|0003
end_define

begin_comment
comment|/* exponent type bits */
end_comment

begin_define
define|#
directive|define
name|PE_REAL_B_EF1
value|0000
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_EF2
value|0001
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_EF3
value|0002
end_define

begin_define
define|#
directive|define
name|PE_REAL_B_EF4
value|0003
end_define

begin_define
define|#
directive|define
name|PE_REAL_PLUSINF
value|0200
end_define

begin_define
define|#
directive|define
name|PE_REAL_MINUSINF
value|0201
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HUGE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAXFLOAT
end_ifdef

begin_define
define|#
directive|define
name|PE_REAL_INFINITY
value|MAXFLOAT
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PE_REAL_INFINITY
value|99.e99
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
name|PE_REAL_INFINITY
value|HUGE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|double
name|prim2real
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|real2prim
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|double2prim
parameter_list|(
name|i
parameter_list|)
value|real2prim ((i), PE_CLASS_UNIV, PE_PRIM_REAL)
end_define

begin_function_decl
name|char
modifier|*
name|prim2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|str2prim
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|qbuf
modifier|*
name|prim2qb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|qb2prim_aux
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* really should be qb2pe () */
end_comment

begin_define
define|#
directive|define
name|qb2prim
parameter_list|(
name|q
parameter_list|,
name|c
parameter_list|,
name|i
parameter_list|)
value|qb2prim_aux ((q), (c), (i), 0)
end_define

begin_define
define|#
directive|define
name|oct2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_PRIM_OCTS)
end_define

begin_define
define|#
directive|define
name|ia5s2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_IA5S)
end_define

begin_define
define|#
directive|define
name|nums2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_NUMS)
end_define

begin_define
define|#
directive|define
name|prts2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_PRTS)
end_define

begin_define
define|#
directive|define
name|t61s2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_T61S)
end_define

begin_define
define|#
directive|define
name|vtxs2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_VTXS)
end_define

begin_define
define|#
directive|define
name|gfxs2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_GFXS)
end_define

begin_define
define|#
directive|define
name|viss2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_VISS)
end_define

begin_define
define|#
directive|define
name|gens2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_GENS)
end_define

begin_define
define|#
directive|define
name|chrs2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_DEFN_CHRS)
end_define

begin_define
define|#
directive|define
name|ode2prim
parameter_list|(
name|s
parameter_list|,
name|len
parameter_list|)
value|str2prim ((s), (len), \ 					    PE_CLASS_UNIV, PE_PRIM_ODE)
end_define

begin_function_decl
name|PE
name|prim2bit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|bit2prim
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|bit_on
argument_list|()
decl_stmt|,
name|bit_off
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|bit_test
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|OID
name|prim2oid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|obj2prim
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|oid2prim
parameter_list|(
name|o
parameter_list|)
value|obj2prim ((o), PE_CLASS_UNIV, PE_PRIM_OID)
end_define

begin_function_decl
name|UTC
name|prim2time
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|prim2utct
parameter_list|(
name|pe
parameter_list|)
value|prim2time ((pe), 0)
end_define

begin_define
define|#
directive|define
name|prim2gent
parameter_list|(
name|pe
parameter_list|)
value|prim2time ((pe), 1)
end_define

begin_function_decl
name|PE
name|time2prim
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|utct2prim
parameter_list|(
name|u
parameter_list|)
value|time2prim ((u), 0, PE_CLASS_UNIV, PE_DEFN_UTCT)
end_define

begin_define
define|#
directive|define
name|gent2prim
parameter_list|(
name|u
parameter_list|)
value|time2prim ((u), 1, PE_CLASS_UNIV, PE_DEFN_GENT)
end_define

begin_function_decl
name|char
modifier|*
name|time2str
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|utct2str
parameter_list|(
name|u
parameter_list|)
value|time2str ((u), 0)
end_define

begin_define
define|#
directive|define
name|gent2str
parameter_list|(
name|u
parameter_list|)
value|time2str ((u), 1)
end_define

begin_decl_stmt
name|UTC
name|str2utct
argument_list|()
decl_stmt|,
name|str2gent
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PE
name|prim2set
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|set2prim
parameter_list|(
name|pe
parameter_list|)
value|(pe)
end_define

begin_decl_stmt
name|int
name|set_add
argument_list|()
decl_stmt|,
name|set_addon
argument_list|()
decl_stmt|,
name|set_del
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PE
name|set_find
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|first_member
parameter_list|(
name|pe
parameter_list|)
value|((pe) -> pe_cons)
end_define

begin_define
define|#
directive|define
name|next_member
parameter_list|(
name|pe
parameter_list|,
name|p
parameter_list|)
value|((p) -> pe_next)
end_define

begin_define
define|#
directive|define
name|prim2seq
parameter_list|(
name|pe
parameter_list|)
value|(prim2set (pe))
end_define

begin_define
define|#
directive|define
name|seq2prim
parameter_list|(
name|pe
parameter_list|)
value|(pe)
end_define

begin_decl_stmt
name|int
name|seq_add
argument_list|()
decl_stmt|,
name|seq_addon
argument_list|()
decl_stmt|,
name|seq_del
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|PE
name|seq_find
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|pe_error
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
block|{
name|int
name|ps_errno
decl_stmt|;
comment|/* Error codes */
define|#
directive|define
name|PS_ERR_NONE
value|0
comment|/*   No error */
define|#
directive|define
name|PS_ERR_OVERID
value|1
comment|/*   Overflow in ID */
define|#
directive|define
name|PS_ERR_OVERLEN
value|2
comment|/*   Overflow in length */
define|#
directive|define
name|PS_ERR_NMEM
value|3
comment|/*   Out of memory */
define|#
directive|define
name|PS_ERR_EOF
value|4
comment|/*   End of file */
define|#
directive|define
name|PS_ERR_EOFID
value|5
comment|/*   End of file reading extended ID */
define|#
directive|define
name|PS_ERR_EOFLEN
value|6
comment|/*   End of file reading extended length */
define|#
directive|define
name|PS_ERR_LEN
value|7
comment|/*   Length mismatch */
define|#
directive|define
name|PS_ERR_TRNC
value|8
comment|/*   Truncated */
define|#
directive|define
name|PS_ERR_INDF
value|9
comment|/*   Indefinite length in primitive form */
define|#
directive|define
name|PS_ERR_IO
value|10
comment|/*   I/O error */
define|#
directive|define
name|PS_ERR_EXTRA
value|11
comment|/*   Extraneous octets */
define|#
directive|define
name|PS_ERR_XXX
value|12
comment|/*   XXX */
union|union
block|{
name|caddr_t
name|un_ps_addr
decl_stmt|;
struct|struct
block|{
name|char
modifier|*
name|st_ps_base
decl_stmt|;
name|int
name|st_ps_cnt
decl_stmt|;
name|char
modifier|*
name|st_ps_ptr
decl_stmt|;
name|int
name|st_ps_bufsiz
decl_stmt|;
block|}
name|un_ps_st
struct|;
struct|struct
block|{
name|struct
name|udvec
modifier|*
name|uv_ps_head
decl_stmt|;
name|struct
name|udvec
modifier|*
name|uv_ps_cur
decl_stmt|;
name|struct
name|udvec
modifier|*
name|uv_ps_end
decl_stmt|;
name|int
name|uv_ps_elems
decl_stmt|;
name|int
name|uv_ps_slop
decl_stmt|;
name|int
name|uv_ps_cc
decl_stmt|;
block|}
name|un_ps_uv
struct|;
block|}
name|ps_un
union|;
define|#
directive|define
name|ps_addr
value|ps_un.un_ps_addr
define|#
directive|define
name|ps_base
value|ps_un.un_ps_st.st_ps_base
define|#
directive|define
name|ps_cnt
value|ps_un.un_ps_st.st_ps_cnt
define|#
directive|define
name|ps_ptr
value|ps_un.un_ps_st.st_ps_ptr
define|#
directive|define
name|ps_bufsiz
value|ps_un.un_ps_st.st_ps_bufsiz
define|#
directive|define
name|ps_head
value|ps_un.un_ps_uv.uv_ps_head
define|#
directive|define
name|ps_cur
value|ps_un.un_ps_uv.uv_ps_cur
define|#
directive|define
name|ps_end
value|ps_un.un_ps_uv.uv_ps_end
define|#
directive|define
name|ps_elems
value|ps_un.un_ps_uv.uv_ps_elems
define|#
directive|define
name|ps_slop
value|ps_un.un_ps_uv.uv_ps_slop
define|#
directive|define
name|ps_cc
value|ps_un.un_ps_uv.uv_ps_cc
name|caddr_t
name|ps_extra
decl_stmt|;
comment|/* for George's recursive PStreams */
name|int
name|ps_inline
decl_stmt|;
comment|/* for "ultra-efficient" PStreams */
name|int
name|ps_scratch
decl_stmt|;
comment|/* XXX */
name|int
name|ps_byteno
decl_stmt|;
comment|/* byte position */
name|IFP
name|ps_primeP
decl_stmt|;
name|IFP
name|ps_readP
decl_stmt|;
name|IFP
name|ps_writeP
decl_stmt|;
name|IFP
name|ps_flushP
decl_stmt|;
name|IFP
name|ps_closeP
decl_stmt|;
block|}
name|PStream
operator|,
typedef|*
name|PS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLPS
value|((PS) 0)
end_define

begin_define
define|#
directive|define
name|ps_seterr
parameter_list|(
name|ps
parameter_list|,
name|e
parameter_list|,
name|v
parameter_list|)
value|((ps) -> ps_errno = (e), (v))
end_define

begin_function_decl
name|PS
name|ps_alloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ps_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ps_io
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ps_read
parameter_list|(
name|ps
parameter_list|,
name|data
parameter_list|,
name|cc
parameter_list|)
value|ps_io ((ps), (ps) -> ps_readP, (data), (cc), 0)
end_define

begin_define
define|#
directive|define
name|ps_write
parameter_list|(
name|ps
parameter_list|,
name|data
parameter_list|,
name|cc
parameter_list|)
value|ps_write_aux ((ps), (data), (cc), 0)
end_define

begin_define
define|#
directive|define
name|ps_write_aux
parameter_list|(
name|ps
parameter_list|,
name|data
parameter_list|,
name|cc
parameter_list|,
name|in_line
parameter_list|)
define|\
value|ps_io ((ps), (ps) -> ps_writeP, (data), (cc), (in_line))
end_define

begin_function_decl
name|int
name|ps_flush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|std_open
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|std_setup
parameter_list|(
name|ps
parameter_list|,
name|fp
parameter_list|)
value|((ps) -> ps_addr = (caddr_t) (fp), OK)
end_define

begin_function_decl
name|int
name|str_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|str_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dg_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dg_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdx_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fdx_setup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qbuf_open
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|qbuf_setup
parameter_list|(
name|ps
parameter_list|,
name|qb
parameter_list|)
value|((ps) -> ps_addr = (caddr_t) (qb), OK)
end_define

begin_define
define|#
directive|define
name|ts_open
value|dg_open
end_define

begin_define
define|#
directive|define
name|ts_setup
parameter_list|(
name|p
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
value|dg_setup ((p), (f), (s), ts_read, ts_write)
end_define

begin_decl_stmt
name|int
name|ts_read
argument_list|()
decl_stmt|,
name|ts_write
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|uvec_open
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uvec_setup
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ps2pe
parameter_list|(
name|ps
parameter_list|)
value|ps2pe_aux ((ps), 1, 1)
end_define

begin_function_decl
name|PE
name|ps2pe_aux
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|pe2ps
parameter_list|(
name|ps
parameter_list|,
name|pe
parameter_list|)
value|pe2ps_aux ((ps), (pe), 1)
end_define

begin_function_decl
name|int
name|pe2ps_aux
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|pl2pe
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe2pl
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|ps_len_strategy
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PS_LEN_SPAG
value|0
end_define

begin_define
define|#
directive|define
name|PS_LEN_INDF
value|1
end_define

begin_define
define|#
directive|define
name|PS_LEN_LONG
value|2
end_define

begin_function_decl
name|int
name|ps_get_abs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ps_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_struct
struct|struct
name|isobject
block|{
name|char
modifier|*
name|io_descriptor
decl_stmt|;
name|OIDentifier
name|io_identity
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|setisobject
argument_list|()
decl_stmt|,
name|endisobject
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|struct
name|isobject
modifier|*
name|getisobject
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isobject
modifier|*
name|getisobjectbyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|isobject
modifier|*
name|getisobjectbyoid
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|int
name|Len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Qcp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ecp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|pe2qb_f
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|Byteno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Qbrefs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|qbuf
modifier|*
name|Hqb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|qbuf
modifier|*
name|Fqb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|qbuf
modifier|*
name|Qb
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|qbuf2pe
parameter_list|(
name|qb
parameter_list|,
name|len
parameter_list|,
name|result
parameter_list|)
value|(Byteno = 0, Hqb = qb, \                                         Fqb = (Qb = (qb) -> qb_forw), \                                         qbuf2pe_f (result))
end_define

begin_function_decl
name|PE
name|qbuf2pe_f
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|qb2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|qbuf
modifier|*
name|str2qb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|qb_free
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pe2ssdu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|ssdu2pe
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|pe2text
argument_list|()
decl_stmt|,
name|text2pe
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|pe2uvec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|int2strb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|strb2int
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|PE
name|strb2bitstr
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|bitstr2strb
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*
comment|*/
end_comment

begin_decl_stmt
specifier|extern
name|char
name|PY_pepy
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|PY_advise
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PY_pp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|testdebug
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|vpush
argument_list|()
decl_stmt|,
name|vpop
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vname
argument_list|()
decl_stmt|,
name|vtag
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|vprint
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|vstring
argument_list|()
decl_stmt|,
name|vunknown
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|bit2str
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|int
name|vpushfp
argument_list|()
decl_stmt|,
name|vpopfp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vpushstr
argument_list|()
decl_stmt|,
name|vpopstr
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|vpushpp
argument_list|()
decl_stmt|,
name|vpopp
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|PEPSY_VERSION
end_ifdef

begin_comment
comment|/* handle calls to the vunknown print routine */
end_comment

begin_define
define|#
directive|define
name|vunknown_P
value|0, ((modtyp *) 0)
end_define

begin_comment
comment|/*  * vpdu now comes out of the closet as a real pepsy function "pvpdu" we  * keep the #define for vpdu for backwards compatiability of other peoples'  * code  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|vpdu
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|{ \     pvpdu ((lp), fnx##_P, (pe), (text), (rw)); \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __STDC__ */
end_comment

begin_define
define|#
directive|define
name|vpdu
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|{ \     pvpdu ((lp), fnx
comment|/**/
value|_P, (pe), (text), (rw)); \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __STDC__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Backwards compatibility with posy/pepy */
end_comment

begin_define
define|#
directive|define
name|vpdu
parameter_list|(
name|lp
parameter_list|,
name|fnx
parameter_list|,
name|pe
parameter_list|,
name|text
parameter_list|,
name|rw
parameter_list|)
define|\
value|{ \     int    fnx (); \  \     _vpdu ((lp), fnx, (pe), (text), (rw)); \ }
end_define

begin_function_decl
name|int
name|_vpdu
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pepy string definitions */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pepy_strings
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PEPY_ERR_BAD
value|(pepy_strings[0])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_BITS
value|(pepy_strings[1])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_BOOLEAN
value|(pepy_strings[2])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_CLASS
value|(pepy_strings[3])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_CLASS_FORM_ID
value|(pepy_strings[4])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_FORM
value|(pepy_strings[5])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_INTEGER
value|(pepy_strings[6])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_OID
value|(pepy_strings[7])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_OCTET
value|(pepy_strings[8])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_REAL
value|(pepy_strings[9])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_SEQ
value|(pepy_strings[10])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_BAD_SET
value|(pepy_strings[11])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_TOO_MANY_BITS
value|(pepy_strings[12])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_TOO_MANY_ELEMENTS
value|(pepy_strings[13])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_UNKNOWN_CHOICE
value|(pepy_strings[14])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_UNK_COMP
value|(pepy_strings[15])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_INIT_FAILED
value|(pepy_strings[16])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_INVALID_CHOICE
value|(pepy_strings[17])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_MISSING
value|(pepy_strings[18])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_NOMEM
value|(pepy_strings[19])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_TOO_MANY_TAGGED
value|(pepy_strings[20])
end_define

begin_define
define|#
directive|define
name|PEPY_ERR_EXTRA_MEMBERS
value|(pepy_strings[21])
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

