begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*    sv.h  *  *    Copyright (c) 1991-2001, Larry Wall  *  *    You may distribute under the terms of either the GNU General Public  *    License or the Artistic License, as specified in the README file.  *  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sv_flags
end_ifdef

begin_undef
undef|#
directive|undef
name|sv_flags
end_undef

begin_comment
comment|/* Convex has this in<signal.h> for sigvec() */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* =for apidoc AmU||svtype An enum of flags for Perl types.  These are found in the file B<sv.h>  in the C<svtype> enum.  Test these flags with the C<SvTYPE> macro.  =for apidoc AmU||SVt_PV Pointer type flag for scalars.  See C<svtype>.  =for apidoc AmU||SVt_IV Integer type flag for scalars.  See C<svtype>.  =for apidoc AmU||SVt_NV Double type flag for scalars.  See C<svtype>.  =for apidoc AmU||SVt_PVMG Type flag for blessed scalars.  See C<svtype>.  =for apidoc AmU||SVt_PVAV Type flag for arrays.  See C<svtype>.  =for apidoc AmU||SVt_PVHV Type flag for hashes.  See C<svtype>.  =for apidoc AmU||SVt_PVCV Type flag for code refs.  See C<svtype>.  =cut */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SVt_NULL
block|,
comment|/* 0 */
name|SVt_IV
block|,
comment|/* 1 */
name|SVt_NV
block|,
comment|/* 2 */
name|SVt_RV
block|,
comment|/* 3 */
name|SVt_PV
block|,
comment|/* 4 */
name|SVt_PVIV
block|,
comment|/* 5 */
name|SVt_PVNV
block|,
comment|/* 6 */
name|SVt_PVMG
block|,
comment|/* 7 */
name|SVt_PVBM
block|,
comment|/* 8 */
name|SVt_PVLV
block|,
comment|/* 9 */
name|SVt_PVAV
block|,
comment|/* 10 */
name|SVt_PVHV
block|,
comment|/* 11 */
name|SVt_PVCV
block|,
comment|/* 12 */
name|SVt_PVGV
block|,
comment|/* 13 */
name|SVt_PVFM
block|,
comment|/* 14 */
name|SVt_PVIO
comment|/* 15 */
block|}
name|svtype
typedef|;
end_typedef

begin_comment
comment|/* Using C's structural equivalence to help emulate C++ inheritance here... */
end_comment

begin_struct
struct|struct
name|STRUCT_SV
block|{
name|void
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gv
block|{
name|XPVGV
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cv
block|{
name|XPVCV
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|av
block|{
name|XPVAV
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hv
block|{
name|XPVHV
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|io
block|{
name|XPVIO
modifier|*
name|sv_any
decl_stmt|;
comment|/* pointer to something */
name|U32
name|sv_refcnt
decl_stmt|;
comment|/* how many references to us */
name|U32
name|sv_flags
decl_stmt|;
comment|/* what we are */
block|}
struct|;
end_struct

begin_comment
comment|/* =for apidoc Am|U32|SvREFCNT|SV* sv Returns the value of the object's reference count.  =for apidoc Am|SV*|SvREFCNT_inc|SV* sv Increments the reference count of the given SV.  =for apidoc Am|void|SvREFCNT_dec|SV* sv Decrements the reference count of the given SV.  =for apidoc Am|svtype|SvTYPE|SV* sv Returns the type of the SV.  See C<svtype>.  =for apidoc Am|void|SvUPGRADE|SV* sv|svtype type Used to upgrade an SV to a more complex form.  Uses C<sv_upgrade> to perform the upgrade if necessary.  See C<svtype>.  =cut */
end_comment

begin_define
define|#
directive|define
name|SvANY
parameter_list|(
name|sv
parameter_list|)
value|(sv)->sv_any
end_define

begin_define
define|#
directive|define
name|SvFLAGS
parameter_list|(
name|sv
parameter_list|)
value|(sv)->sv_flags
end_define

begin_define
define|#
directive|define
name|SvREFCNT
parameter_list|(
name|sv
parameter_list|)
value|(sv)->sv_refcnt
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_THREADS
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|count
parameter_list|)
value|__ATOMIC_INCREMENT_LONG(&count)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC_AND_TEST
parameter_list|(
name|res
parameter_list|,
name|count
parameter_list|)
value|res=(1==__ATOMIC_DECREMENT_LONG(&count))
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|EMULATE_ATOMIC_REFCOUNTS
end_ifdef

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|count
parameter_list|)
value|STMT_START {	\ 	  MUTEX_LOCK(&PL_svref_mutex);		\ 	  ++count;				\ 	  MUTEX_UNLOCK(&PL_svref_mutex);		\        } STMT_END
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC_AND_TEST
parameter_list|(
name|res
parameter_list|,
name|count
parameter_list|)
value|STMT_START {	\ 	  MUTEX_LOCK(&PL_svref_mutex);			\ 	  res = (--count == 0);				\ 	  MUTEX_UNLOCK(&PL_svref_mutex);			\        } STMT_END
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|count
parameter_list|)
value|atomic_inc(&count)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC_AND_TEST
parameter_list|(
name|res
parameter_list|,
name|count
parameter_list|)
value|(res = atomic_dec_and_test(&count))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMULATE_ATOMIC_REFCOUNTS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VMS */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATOMIC_INC
parameter_list|(
name|count
parameter_list|)
value|(++count)
end_define

begin_define
define|#
directive|define
name|ATOMIC_DEC_AND_TEST
parameter_list|(
name|res
parameter_list|,
name|count
parameter_list|)
value|(res = (--count == 0))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_THREADS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|SvREFCNT_inc
parameter_list|(
name|sv
parameter_list|)
define|\
value|({					\ 	SV *nsv = (SV*)(sv);		\ 	if (nsv)			\ 	     ATOMIC_INC(SvREFCNT(nsv));	\ 	nsv;				\     })
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CRIPPLED_CC
argument_list|)
operator|||
name|defined
argument_list|(
name|USE_THREADS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ALPHA
argument_list|)
end_if

begin_define
define|#
directive|define
name|SvREFCNT_inc
parameter_list|(
name|sv
parameter_list|)
define|\
value|(PL_Sv=(SV*)(sv), (PL_Sv&& __ATOMIC_INCREMENT_LONG(&(SvREFCNT(PL_Sv)))), (SV *)PL_Sv)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SvREFCNT_inc
parameter_list|(
name|sv
parameter_list|)
value|sv_newref((SV*)sv)
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
name|SvREFCNT_inc
parameter_list|(
name|sv
parameter_list|)
define|\
value|((PL_Sv=(SV*)(sv)), (PL_Sv&& ATOMIC_INC(SvREFCNT(PL_Sv))), (SV*)PL_Sv)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SvREFCNT_dec
parameter_list|(
name|sv
parameter_list|)
value|sv_free((SV*)sv)
end_define

begin_define
define|#
directive|define
name|SVTYPEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|SvTYPE
parameter_list|(
name|sv
parameter_list|)
value|((sv)->sv_flags& SVTYPEMASK)
end_define

begin_define
define|#
directive|define
name|SvUPGRADE
parameter_list|(
name|sv
parameter_list|,
name|mt
parameter_list|)
value|(SvTYPE(sv)>= mt || sv_upgrade(sv, mt))
end_define

begin_define
define|#
directive|define
name|SVs_PADBUSY
value|0x00000100
end_define

begin_comment
comment|/* reserved for tmp or my already */
end_comment

begin_define
define|#
directive|define
name|SVs_PADTMP
value|0x00000200
end_define

begin_comment
comment|/* in use as tmp */
end_comment

begin_define
define|#
directive|define
name|SVs_PADMY
value|0x00000400
end_define

begin_comment
comment|/* in use a "my" variable */
end_comment

begin_define
define|#
directive|define
name|SVs_TEMP
value|0x00000800
end_define

begin_comment
comment|/* string is stealable? */
end_comment

begin_define
define|#
directive|define
name|SVs_OBJECT
value|0x00001000
end_define

begin_comment
comment|/* is "blessed" */
end_comment

begin_define
define|#
directive|define
name|SVs_GMG
value|0x00002000
end_define

begin_comment
comment|/* has magical get method */
end_comment

begin_define
define|#
directive|define
name|SVs_SMG
value|0x00004000
end_define

begin_comment
comment|/* has magical set method */
end_comment

begin_define
define|#
directive|define
name|SVs_RMG
value|0x00008000
end_define

begin_comment
comment|/* has random magical methods */
end_comment

begin_define
define|#
directive|define
name|SVf_IOK
value|0x00010000
end_define

begin_comment
comment|/* has valid public integer value */
end_comment

begin_define
define|#
directive|define
name|SVf_NOK
value|0x00020000
end_define

begin_comment
comment|/* has valid public numeric value */
end_comment

begin_define
define|#
directive|define
name|SVf_POK
value|0x00040000
end_define

begin_comment
comment|/* has valid public pointer value */
end_comment

begin_define
define|#
directive|define
name|SVf_ROK
value|0x00080000
end_define

begin_comment
comment|/* has a valid reference pointer */
end_comment

begin_define
define|#
directive|define
name|SVf_FAKE
value|0x00100000
end_define

begin_comment
comment|/* glob or lexical is just a copy */
end_comment

begin_define
define|#
directive|define
name|SVf_OOK
value|0x00200000
end_define

begin_comment
comment|/* has valid offset value */
end_comment

begin_define
define|#
directive|define
name|SVf_BREAK
value|0x00400000
end_define

begin_comment
comment|/* refcnt is artificially low */
end_comment

begin_define
define|#
directive|define
name|SVf_READONLY
value|0x00800000
end_define

begin_comment
comment|/* may not be modified */
end_comment

begin_define
define|#
directive|define
name|SVp_IOK
value|0x01000000
end_define

begin_comment
comment|/* has valid non-public integer value */
end_comment

begin_define
define|#
directive|define
name|SVp_NOK
value|0x02000000
end_define

begin_comment
comment|/* has valid non-public numeric value */
end_comment

begin_define
define|#
directive|define
name|SVp_POK
value|0x04000000
end_define

begin_comment
comment|/* has valid non-public pointer value */
end_comment

begin_define
define|#
directive|define
name|SVp_SCREAM
value|0x08000000
end_define

begin_comment
comment|/* has been studied? */
end_comment

begin_define
define|#
directive|define
name|SVf_UTF8
value|0x20000000
end_define

begin_comment
comment|/* SvPVX is UTF-8 encoded */
end_comment

begin_define
define|#
directive|define
name|SVf_THINKFIRST
value|(SVf_READONLY|SVf_ROK|SVf_FAKE|SVf_UTF8)
end_define

begin_define
define|#
directive|define
name|SVf_OK
value|(SVf_IOK|SVf_NOK|SVf_POK|SVf_ROK| \ 			 SVp_IOK|SVp_NOK|SVp_POK)
end_define

begin_define
define|#
directive|define
name|SVf_AMAGIC
value|0x10000000
end_define

begin_comment
comment|/* has magical overloaded methods */
end_comment

begin_define
define|#
directive|define
name|PRIVSHIFT
value|8
end_define

begin_comment
comment|/* Some private flags. */
end_comment

begin_comment
comment|/* SVpad_OUR may be set on SVt_PV{NV,MG,GV} types */
end_comment

begin_define
define|#
directive|define
name|SVpad_OUR
value|0x80000000
end_define

begin_comment
comment|/* pad name is "our" instead of "my" */
end_comment

begin_define
define|#
directive|define
name|SVf_IVisUV
value|0x80000000
end_define

begin_comment
comment|/* use XPVUV instead of XPVIV */
end_comment

begin_define
define|#
directive|define
name|SVpfm_COMPILED
value|0x80000000
end_define

begin_comment
comment|/* FORMLINE is compiled */
end_comment

begin_define
define|#
directive|define
name|SVpbm_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SVpbm_TAIL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|SVrepl_EVAL
value|0x40000000
end_define

begin_comment
comment|/* Replacement part of s///e */
end_comment

begin_define
define|#
directive|define
name|SVphv_SHAREKEYS
value|0x20000000
end_define

begin_comment
comment|/* keys live on shared string table */
end_comment

begin_define
define|#
directive|define
name|SVphv_LAZYDEL
value|0x40000000
end_define

begin_comment
comment|/* entry in xhv_eiter must be deleted */
end_comment

begin_define
define|#
directive|define
name|SVprv_WEAKREF
value|0x80000000
end_define

begin_comment
comment|/* Weak reference */
end_comment

begin_struct
struct|struct
name|xrv
block|{
name|SV
modifier|*
name|xrv_rv
decl_stmt|;
comment|/* pointer to another SV */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpviv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvuv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|UV
name|xuv_uv
decl_stmt|;
comment|/* unsigned value or pv offset */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvnv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
block|}
struct|;
end_struct

begin_comment
comment|/* These structure must match the beginning of struct xpvhv in hv.h. */
end_comment

begin_struct
struct|struct
name|xpvmg
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvlv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|STRLEN
name|xlv_targoff
decl_stmt|;
name|STRLEN
name|xlv_targlen
decl_stmt|;
name|SV
modifier|*
name|xlv_targ
decl_stmt|;
name|char
name|xlv_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvgv
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|GP
modifier|*
name|xgv_gp
decl_stmt|;
name|char
modifier|*
name|xgv_name
decl_stmt|;
name|STRLEN
name|xgv_namelen
decl_stmt|;
name|HV
modifier|*
name|xgv_stash
decl_stmt|;
name|U8
name|xgv_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvbm
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|I32
name|xbm_useful
decl_stmt|;
comment|/* is this constant pattern being useful? */
name|U16
name|xbm_previous
decl_stmt|;
comment|/* how many characters in string before rare? */
name|U8
name|xbm_rare
decl_stmt|;
comment|/* rarest character in string */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure much match XPVCV in cv.h */
end_comment

begin_typedef
typedef|typedef
name|U16
name|cv_flags_t
typedef|;
end_typedef

begin_struct
struct|struct
name|xpvfm
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|HV
modifier|*
name|xcv_stash
decl_stmt|;
name|OP
modifier|*
name|xcv_start
decl_stmt|;
name|OP
modifier|*
name|xcv_root
decl_stmt|;
name|void
function_decl|(
modifier|*
name|xcv_xsub
function_decl|)
parameter_list|(
name|pTHXo_
name|CV
modifier|*
parameter_list|)
function_decl|;
name|ANY
name|xcv_xsubany
decl_stmt|;
name|GV
modifier|*
name|xcv_gv
decl_stmt|;
name|char
modifier|*
name|xcv_file
decl_stmt|;
name|long
name|xcv_depth
decl_stmt|;
comment|/*>= 2 indicates recursive call */
name|AV
modifier|*
name|xcv_padlist
decl_stmt|;
name|CV
modifier|*
name|xcv_outside
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_THREADS
name|perl_mutex
modifier|*
name|xcv_mutexp
decl_stmt|;
comment|/* protects xcv_owner */
name|struct
name|perl_thread
modifier|*
name|xcv_owner
decl_stmt|;
comment|/* current owner thread */
endif|#
directive|endif
comment|/* USE_THREADS */
name|cv_flags_t
name|xcv_flags
decl_stmt|;
name|I32
name|xfm_lines
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xpvio
block|{
name|char
modifier|*
name|xpv_pv
decl_stmt|;
comment|/* pointer to malloced string */
name|STRLEN
name|xpv_cur
decl_stmt|;
comment|/* length of xpv_pv as a C string */
name|STRLEN
name|xpv_len
decl_stmt|;
comment|/* allocated size */
name|IV
name|xiv_iv
decl_stmt|;
comment|/* integer value or pv offset */
name|NV
name|xnv_nv
decl_stmt|;
comment|/* numeric value, if any */
name|MAGIC
modifier|*
name|xmg_magic
decl_stmt|;
comment|/* linked list of magicalness */
name|HV
modifier|*
name|xmg_stash
decl_stmt|;
comment|/* class package */
name|PerlIO
modifier|*
name|xio_ifp
decl_stmt|;
comment|/* ifp and ofp are normally the same */
name|PerlIO
modifier|*
name|xio_ofp
decl_stmt|;
comment|/* but sockets need separate streams */
comment|/* Cray addresses everything by word boundaries (64 bits) and      * code and data pointers cannot be mixed (which is exactly what      * Perl_filter_add() tries to do with the dirp), hence the following      * union trick (as suggested by Gurusamy Sarathy).      * For further information see Geir Johansen's problem report titled        [ID 20000612.002] Perl problem on Cray system      * The any pointer (known as IoANY()) will also be a good place      * to hang any IO disciplines to.      */
union|union
block|{
name|DIR
modifier|*
name|xiou_dirp
decl_stmt|;
comment|/* for opendir, readdir, etc */
name|void
modifier|*
name|xiou_any
decl_stmt|;
comment|/* for alignment */
block|}
name|xio_dirpu
union|;
name|long
name|xio_lines
decl_stmt|;
comment|/* $. */
name|long
name|xio_page
decl_stmt|;
comment|/* $% */
name|long
name|xio_page_len
decl_stmt|;
comment|/* $= */
name|long
name|xio_lines_left
decl_stmt|;
comment|/* $- */
name|char
modifier|*
name|xio_top_name
decl_stmt|;
comment|/* $^ */
name|GV
modifier|*
name|xio_top_gv
decl_stmt|;
comment|/* $^ */
name|char
modifier|*
name|xio_fmt_name
decl_stmt|;
comment|/* $~ */
name|GV
modifier|*
name|xio_fmt_gv
decl_stmt|;
comment|/* $~ */
name|char
modifier|*
name|xio_bottom_name
decl_stmt|;
comment|/* $^B */
name|GV
modifier|*
name|xio_bottom_gv
decl_stmt|;
comment|/* $^B */
name|short
name|xio_subprocess
decl_stmt|;
comment|/* -| or |- */
name|char
name|xio_type
decl_stmt|;
name|char
name|xio_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|xio_dirp
value|xio_dirpu.xiou_dirp
end_define

begin_define
define|#
directive|define
name|xio_any
value|xio_dirpu.xiou_any
end_define

begin_define
define|#
directive|define
name|IOf_ARGV
value|1
end_define

begin_comment
comment|/* this fp iterates over ARGV */
end_comment

begin_define
define|#
directive|define
name|IOf_START
value|2
end_define

begin_comment
comment|/* check for null ARGV and substitute '-' */
end_comment

begin_define
define|#
directive|define
name|IOf_FLUSH
value|4
end_define

begin_comment
comment|/* this fp wants a flush after write op */
end_comment

begin_define
define|#
directive|define
name|IOf_DIDTOP
value|8
end_define

begin_comment
comment|/* just did top of form */
end_comment

begin_define
define|#
directive|define
name|IOf_UNTAINT
value|16
end_define

begin_comment
comment|/* consider this fp (and its data) "safe" */
end_comment

begin_define
define|#
directive|define
name|IOf_NOLINE
value|32
end_define

begin_comment
comment|/* slurped a pseudo-line from empty file */
end_comment

begin_define
define|#
directive|define
name|IOf_FAKE_DIRP
value|64
end_define

begin_comment
comment|/* xio_dirp is fake (source filters kludge) */
end_comment

begin_comment
comment|/* The following macros define implementation-independent predicates on SVs. */
end_comment

begin_comment
comment|/* =for apidoc Am|bool|SvNIOK|SV* sv Returns a boolean indicating whether the SV contains a number, integer or double.  =for apidoc Am|bool|SvNIOKp|SV* sv Returns a boolean indicating whether the SV contains a number, integer or double.  Checks the B<private> setting.  Use C<SvNIOK>.  =for apidoc Am|void|SvNIOK_off|SV* sv Unsets the NV/IV status of an SV.  =for apidoc Am|bool|SvOK|SV* sv Returns a boolean indicating whether the value is an SV.  =for apidoc Am|bool|SvIOKp|SV* sv Returns a boolean indicating whether the SV contains an integer.  Checks the B<private> setting.  Use C<SvIOK>.  =for apidoc Am|bool|SvNOKp|SV* sv Returns a boolean indicating whether the SV contains a double.  Checks the B<private> setting.  Use C<SvNOK>.  =for apidoc Am|bool|SvPOKp|SV* sv Returns a boolean indicating whether the SV contains a character string. Checks the B<private> setting.  Use C<SvPOK>.  =for apidoc Am|bool|SvIOK|SV* sv Returns a boolean indicating whether the SV contains an integer.  =for apidoc Am|void|SvIOK_on|SV* sv Tells an SV that it is an integer.  =for apidoc Am|void|SvIOK_off|SV* sv Unsets the IV status of an SV.  =for apidoc Am|void|SvIOK_only|SV* sv Tells an SV that it is an integer and disables all other OK bits.  =for apidoc Am|void|SvIOK_only_UV|SV* sv Tells and SV that it is an unsigned integer and disables all other OK bits.  =for apidoc Am|void|SvIOK_UV|SV* sv Returns a boolean indicating whether the SV contains an unsigned integer.  =for apidoc Am|void|SvIOK_notUV|SV* sv Returns a boolean indicating whether the SV contains an signed integer.  =for apidoc Am|bool|SvNOK|SV* sv Returns a boolean indicating whether the SV contains a double.  =for apidoc Am|void|SvNOK_on|SV* sv Tells an SV that it is a double.  =for apidoc Am|void|SvNOK_off|SV* sv Unsets the NV status of an SV.  =for apidoc Am|void|SvNOK_only|SV* sv Tells an SV that it is a double and disables all other OK bits.  =for apidoc Am|bool|SvPOK|SV* sv Returns a boolean indicating whether the SV contains a character string.  =for apidoc Am|void|SvPOK_on|SV* sv Tells an SV that it is a string.  =for apidoc Am|void|SvPOK_off|SV* sv Unsets the PV status of an SV.  =for apidoc Am|void|SvPOK_only|SV* sv Tells an SV that it is a string and disables all other OK bits.  =for apidoc Am|bool|SvOOK|SV* sv Returns a boolean indicating whether the SvIVX is a valid offset value for the SvPVX.  This hack is used internally to speed up removal of characters from the beginning of a SvPV.  When SvOOK is true, then the start of the allocated string buffer is really (SvPVX - SvIVX).  =for apidoc Am|bool|SvROK|SV* sv Tests if the SV is an RV.  =for apidoc Am|void|SvROK_on|SV* sv Tells an SV that it is an RV.  =for apidoc Am|void|SvROK_off|SV* sv Unsets the RV status of an SV.  =for apidoc Am|SV*|SvRV|SV* sv Dereferences an RV to return the SV.  =for apidoc Am|IV|SvIVX|SV* sv Returns the integer which is stored in the SV, assuming SvIOK is true.  =for apidoc Am|UV|SvUVX|SV* sv Returns the unsigned integer which is stored in the SV, assuming SvIOK is true.  =for apidoc Am|NV|SvNVX|SV* sv Returns the double which is stored in the SV, assuming SvNOK is true.  =for apidoc Am|char*|SvPVX|SV* sv Returns a pointer to the string in the SV.  The SV must contain a string.  =for apidoc Am|STRLEN|SvCUR|SV* sv Returns the length of the string which is in the SV.  See C<SvLEN>.  =for apidoc Am|STRLEN|SvLEN|SV* sv Returns the size of the string buffer in the SV, not including any part attributable to C<SvOOK>.  See C<SvCUR>.  =for apidoc Am|char*|SvEND|SV* sv Returns a pointer to the last character in the string which is in the SV. See C<SvCUR>.  Access the character as *(SvEND(sv)).  =for apidoc Am|HV*|SvSTASH|SV* sv Returns the stash of the SV.  =for apidoc Am|void|SvCUR_set|SV* sv|STRLEN len Set the length of the string which is in the SV.  See C<SvCUR>.  =cut */
end_comment

begin_define
define|#
directive|define
name|SvNIOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& (SVf_IOK|SVf_NOK))
end_define

begin_define
define|#
directive|define
name|SvNIOKp
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& (SVp_IOK|SVp_NOK))
end_define

begin_define
define|#
directive|define
name|SvNIOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_IOK|SVf_NOK| \ 						  SVp_IOK|SVp_NOK|SVf_IVisUV))
end_define

begin_define
define|#
directive|define
name|SvOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_OK)
end_define

begin_define
define|#
directive|define
name|SvOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&=	~(SVf_OK|SVf_AMAGIC|	\ 						  SVf_IVisUV|SVf_UTF8),	\ 							SvOOK_off(sv))
end_define

begin_define
define|#
directive|define
name|SvOK_off_exc_UV
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&=	~(SVf_OK|SVf_AMAGIC|	\ 						  SVf_UTF8),		\ 							SvOOK_off(sv))
end_define

begin_define
define|#
directive|define
name|SvOKp
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& (SVp_IOK|SVp_NOK|SVp_POK))
end_define

begin_define
define|#
directive|define
name|SvIOKp
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVp_IOK)
end_define

begin_define
define|#
directive|define
name|SvIOKp_on
parameter_list|(
name|sv
parameter_list|)
value|((void)SvOOK_off(sv), SvFLAGS(sv) |= SVp_IOK)
end_define

begin_define
define|#
directive|define
name|SvNOKp
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVp_NOK)
end_define

begin_define
define|#
directive|define
name|SvNOKp_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVp_NOK)
end_define

begin_define
define|#
directive|define
name|SvPOKp
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVp_POK)
end_define

begin_define
define|#
directive|define
name|SvPOKp_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVp_POK)
end_define

begin_define
define|#
directive|define
name|SvIOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_IOK)
end_define

begin_define
define|#
directive|define
name|SvIOK_on
parameter_list|(
name|sv
parameter_list|)
value|((void)SvOOK_off(sv), \ 				    SvFLAGS(sv) |= (SVf_IOK|SVp_IOK))
end_define

begin_define
define|#
directive|define
name|SvIOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_IOK|SVp_IOK|SVf_IVisUV))
end_define

begin_define
define|#
directive|define
name|SvIOK_only
parameter_list|(
name|sv
parameter_list|)
value|((void)SvOK_off(sv), \ 				    SvFLAGS(sv) |= (SVf_IOK|SVp_IOK))
end_define

begin_define
define|#
directive|define
name|SvIOK_only_UV
parameter_list|(
name|sv
parameter_list|)
value|((void)SvOK_off_exc_UV(sv), \ 				    SvFLAGS(sv) |= (SVf_IOK|SVp_IOK))
end_define

begin_define
define|#
directive|define
name|SvIOK_UV
parameter_list|(
name|sv
parameter_list|)
value|((SvFLAGS(sv)& (SVf_IOK|SVf_IVisUV))	\ 				 == (SVf_IOK|SVf_IVisUV))
end_define

begin_define
define|#
directive|define
name|SvIOK_notUV
parameter_list|(
name|sv
parameter_list|)
value|((SvFLAGS(sv)& (SVf_IOK|SVf_IVisUV))	\ 				 == SVf_IOK)
end_define

begin_define
define|#
directive|define
name|SvIsUV
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_IVisUV)
end_define

begin_define
define|#
directive|define
name|SvIsUV_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVf_IVisUV)
end_define

begin_define
define|#
directive|define
name|SvIsUV_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVf_IVisUV)
end_define

begin_define
define|#
directive|define
name|SvNOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_NOK)
end_define

begin_define
define|#
directive|define
name|SvNOK_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= (SVf_NOK|SVp_NOK))
end_define

begin_define
define|#
directive|define
name|SvNOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_NOK|SVp_NOK))
end_define

begin_define
define|#
directive|define
name|SvNOK_only
parameter_list|(
name|sv
parameter_list|)
value|((void)SvOK_off(sv), \ 				    SvFLAGS(sv) |= (SVf_NOK|SVp_NOK))
end_define

begin_comment
comment|/* =for apidoc Am|void|SvUTF8|SV* sv Returns a boolean indicating whether the SV contains UTF-8 encoded data.  =for apidoc Am|void|SvUTF8_on|SV *sv Tells an SV that it is a string and encoded in UTF8.  Do not use frivolously.  =for apidoc Am|void|SvUTF8_off|SV *sv Unsets the UTF8 status of an SV.  =for apidoc Am|void|SvPOK_only_UTF8|SV* sv Tells an SV that it is a UTF8 string (do not use frivolously) and disables all other OK bits.    =cut  */
end_comment

begin_define
define|#
directive|define
name|SvUTF8
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_UTF8)
end_define

begin_define
define|#
directive|define
name|SvUTF8_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= (SVf_UTF8))
end_define

begin_define
define|#
directive|define
name|SvUTF8_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_UTF8))
end_define

begin_define
define|#
directive|define
name|SvPOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_POK)
end_define

begin_define
define|#
directive|define
name|SvPOK_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= (SVf_POK|SVp_POK))
end_define

begin_define
define|#
directive|define
name|SvPOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_POK|SVp_POK))
end_define

begin_define
define|#
directive|define
name|SvPOK_only
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_OK|SVf_AMAGIC|	\ 						  SVf_IVisUV|SVf_UTF8),	\ 				    SvFLAGS(sv) |= (SVf_POK|SVp_POK))
end_define

begin_define
define|#
directive|define
name|SvPOK_only_UTF8
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_OK|SVf_AMAGIC|	\ 						  SVf_IVisUV),		\ 				    SvFLAGS(sv) |= (SVf_POK|SVp_POK))
end_define

begin_define
define|#
directive|define
name|SvOOK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_OOK)
end_define

begin_define
define|#
directive|define
name|SvOOK_on
parameter_list|(
name|sv
parameter_list|)
value|((void)SvIOK_off(sv), SvFLAGS(sv) |= SVf_OOK)
end_define

begin_define
define|#
directive|define
name|SvOOK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvOOK(sv)&& sv_backoff(sv))
end_define

begin_define
define|#
directive|define
name|SvFAKE
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_FAKE)
end_define

begin_define
define|#
directive|define
name|SvFAKE_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVf_FAKE)
end_define

begin_define
define|#
directive|define
name|SvFAKE_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVf_FAKE)
end_define

begin_define
define|#
directive|define
name|SvROK
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_ROK)
end_define

begin_define
define|#
directive|define
name|SvROK_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVf_ROK)
end_define

begin_define
define|#
directive|define
name|SvROK_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_ROK|SVf_AMAGIC))
end_define

begin_define
define|#
directive|define
name|SvMAGICAL
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& (SVs_GMG|SVs_SMG|SVs_RMG))
end_define

begin_define
define|#
directive|define
name|SvMAGICAL_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= (SVs_GMG|SVs_SMG|SVs_RMG))
end_define

begin_define
define|#
directive|define
name|SvMAGICAL_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVs_GMG|SVs_SMG|SVs_RMG))
end_define

begin_define
define|#
directive|define
name|SvGMAGICAL
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_GMG)
end_define

begin_define
define|#
directive|define
name|SvGMAGICAL_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_GMG)
end_define

begin_define
define|#
directive|define
name|SvGMAGICAL_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_GMG)
end_define

begin_define
define|#
directive|define
name|SvSMAGICAL
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_SMG)
end_define

begin_define
define|#
directive|define
name|SvSMAGICAL_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_SMG)
end_define

begin_define
define|#
directive|define
name|SvSMAGICAL_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_SMG)
end_define

begin_define
define|#
directive|define
name|SvRMAGICAL
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_RMG)
end_define

begin_define
define|#
directive|define
name|SvRMAGICAL_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_RMG)
end_define

begin_define
define|#
directive|define
name|SvRMAGICAL_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_RMG)
end_define

begin_define
define|#
directive|define
name|SvAMAGIC
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_AMAGIC)
end_define

begin_define
define|#
directive|define
name|SvAMAGIC_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVf_AMAGIC)
end_define

begin_define
define|#
directive|define
name|SvAMAGIC_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVf_AMAGIC)
end_define

begin_define
define|#
directive|define
name|SvGAMAGIC
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& (SVs_GMG|SVf_AMAGIC))
end_define

begin_comment
comment|/* #define Gv_AMG(stash) \         (HV_AMAGICmb(stash)&& \          ((!HV_AMAGICbad(stash)&& HV_AMAGIC(stash)) || Gv_AMupdate(stash))) */
end_comment

begin_define
define|#
directive|define
name|Gv_AMG
parameter_list|(
name|stash
parameter_list|)
value|(PL_amagic_generation&& Gv_AMupdate(stash))
end_define

begin_define
define|#
directive|define
name|SvWEAKREF
parameter_list|(
name|sv
parameter_list|)
value|((SvFLAGS(sv)& (SVf_ROK|SVprv_WEAKREF)) \ 				  == (SVf_ROK|SVprv_WEAKREF))
end_define

begin_define
define|#
directive|define
name|SvWEAKREF_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |=  (SVf_ROK|SVprv_WEAKREF))
end_define

begin_define
define|#
directive|define
name|SvWEAKREF_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~(SVf_ROK|SVprv_WEAKREF))
end_define

begin_define
define|#
directive|define
name|SvTHINKFIRST
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_THINKFIRST)
end_define

begin_define
define|#
directive|define
name|SvPADBUSY
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_PADBUSY)
end_define

begin_define
define|#
directive|define
name|SvPADTMP
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_PADTMP)
end_define

begin_define
define|#
directive|define
name|SvPADTMP_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_PADTMP|SVs_PADBUSY)
end_define

begin_define
define|#
directive|define
name|SvPADTMP_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_PADTMP)
end_define

begin_define
define|#
directive|define
name|SvPADMY
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_PADMY)
end_define

begin_define
define|#
directive|define
name|SvPADMY_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_PADMY|SVs_PADBUSY)
end_define

begin_define
define|#
directive|define
name|SvTEMP
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_TEMP)
end_define

begin_define
define|#
directive|define
name|SvTEMP_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_TEMP)
end_define

begin_define
define|#
directive|define
name|SvTEMP_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_TEMP)
end_define

begin_define
define|#
directive|define
name|SvOBJECT
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVs_OBJECT)
end_define

begin_define
define|#
directive|define
name|SvOBJECT_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVs_OBJECT)
end_define

begin_define
define|#
directive|define
name|SvOBJECT_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVs_OBJECT)
end_define

begin_define
define|#
directive|define
name|SvREADONLY
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVf_READONLY)
end_define

begin_define
define|#
directive|define
name|SvREADONLY_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVf_READONLY)
end_define

begin_define
define|#
directive|define
name|SvREADONLY_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVf_READONLY)
end_define

begin_define
define|#
directive|define
name|SvSCREAM
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVp_SCREAM)
end_define

begin_define
define|#
directive|define
name|SvSCREAM_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVp_SCREAM)
end_define

begin_define
define|#
directive|define
name|SvSCREAM_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVp_SCREAM)
end_define

begin_define
define|#
directive|define
name|SvCOMPILED
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVpfm_COMPILED)
end_define

begin_define
define|#
directive|define
name|SvCOMPILED_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVpfm_COMPILED)
end_define

begin_define
define|#
directive|define
name|SvCOMPILED_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVpfm_COMPILED)
end_define

begin_define
define|#
directive|define
name|SvEVALED
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVrepl_EVAL)
end_define

begin_define
define|#
directive|define
name|SvEVALED_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVrepl_EVAL)
end_define

begin_define
define|#
directive|define
name|SvEVALED_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVrepl_EVAL)
end_define

begin_define
define|#
directive|define
name|SvTAIL
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVpbm_TAIL)
end_define

begin_define
define|#
directive|define
name|SvTAIL_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVpbm_TAIL)
end_define

begin_define
define|#
directive|define
name|SvTAIL_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVpbm_TAIL)
end_define

begin_define
define|#
directive|define
name|SvVALID
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)& SVpbm_VALID)
end_define

begin_define
define|#
directive|define
name|SvVALID_on
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv) |= SVpbm_VALID)
end_define

begin_define
define|#
directive|define
name|SvVALID_off
parameter_list|(
name|sv
parameter_list|)
value|(SvFLAGS(sv)&= ~SVpbm_VALID)
end_define

begin_define
define|#
directive|define
name|SvRV
parameter_list|(
name|sv
parameter_list|)
value|((XRV*)  SvANY(sv))->xrv_rv
end_define

begin_define
define|#
directive|define
name|SvRVx
parameter_list|(
name|sv
parameter_list|)
value|SvRV(sv)
end_define

begin_define
define|#
directive|define
name|SvIVX
parameter_list|(
name|sv
parameter_list|)
value|((XPVIV*)  SvANY(sv))->xiv_iv
end_define

begin_define
define|#
directive|define
name|SvIVXx
parameter_list|(
name|sv
parameter_list|)
value|SvIVX(sv)
end_define

begin_define
define|#
directive|define
name|SvUVX
parameter_list|(
name|sv
parameter_list|)
value|((XPVUV*)  SvANY(sv))->xuv_uv
end_define

begin_define
define|#
directive|define
name|SvUVXx
parameter_list|(
name|sv
parameter_list|)
value|SvUVX(sv)
end_define

begin_define
define|#
directive|define
name|SvNVX
parameter_list|(
name|sv
parameter_list|)
value|((XPVNV*)SvANY(sv))->xnv_nv
end_define

begin_define
define|#
directive|define
name|SvNVXx
parameter_list|(
name|sv
parameter_list|)
value|SvNVX(sv)
end_define

begin_define
define|#
directive|define
name|SvPVX
parameter_list|(
name|sv
parameter_list|)
value|((XPV*)  SvANY(sv))->xpv_pv
end_define

begin_define
define|#
directive|define
name|SvPVXx
parameter_list|(
name|sv
parameter_list|)
value|SvPVX(sv)
end_define

begin_define
define|#
directive|define
name|SvCUR
parameter_list|(
name|sv
parameter_list|)
value|((XPV*)  SvANY(sv))->xpv_cur
end_define

begin_define
define|#
directive|define
name|SvLEN
parameter_list|(
name|sv
parameter_list|)
value|((XPV*)  SvANY(sv))->xpv_len
end_define

begin_define
define|#
directive|define
name|SvLENx
parameter_list|(
name|sv
parameter_list|)
value|SvLEN(sv)
end_define

begin_define
define|#
directive|define
name|SvEND
parameter_list|(
name|sv
parameter_list|)
value|(((XPV*)  SvANY(sv))->xpv_pv + ((XPV*)SvANY(sv))->xpv_cur)
end_define

begin_define
define|#
directive|define
name|SvENDx
parameter_list|(
name|sv
parameter_list|)
value|((PL_Sv = (sv)), SvEND(PL_Sv))
end_define

begin_define
define|#
directive|define
name|SvMAGIC
parameter_list|(
name|sv
parameter_list|)
value|((XPVMG*)  SvANY(sv))->xmg_magic
end_define

begin_define
define|#
directive|define
name|SvSTASH
parameter_list|(
name|sv
parameter_list|)
value|((XPVMG*)  SvANY(sv))->xmg_stash
end_define

begin_define
define|#
directive|define
name|SvIV_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv) == SVt_IV || SvTYPE(sv)>= SVt_PVIV); \ 		(((XPVIV*)  SvANY(sv))->xiv_iv = val); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvNV_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv) == SVt_NV || SvTYPE(sv)>= SVt_PVNV); \ 		(((XPVNV*)  SvANY(sv))->xnv_nv = val); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvPV_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv)>= SVt_PV); \ 		(((XPV*)  SvANY(sv))->xpv_pv = val); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvCUR_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv)>= SVt_PV); \ 		(((XPV*)  SvANY(sv))->xpv_cur = val); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvLEN_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv)>= SVt_PV); \ 		(((XPV*)  SvANY(sv))->xpv_len = val); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvEND_set
parameter_list|(
name|sv
parameter_list|,
name|val
parameter_list|)
define|\
value|STMT_START { assert(SvTYPE(sv)>= SVt_PV); \ 		(((XPV*)  SvANY(sv))->xpv_cur = val - SvPVX(sv)); } STMT_END
end_define

begin_define
define|#
directive|define
name|BmRARE
parameter_list|(
name|sv
parameter_list|)
value|((XPVBM*)  SvANY(sv))->xbm_rare
end_define

begin_define
define|#
directive|define
name|BmUSEFUL
parameter_list|(
name|sv
parameter_list|)
value|((XPVBM*)  SvANY(sv))->xbm_useful
end_define

begin_define
define|#
directive|define
name|BmPREVIOUS
parameter_list|(
name|sv
parameter_list|)
value|((XPVBM*)  SvANY(sv))->xbm_previous
end_define

begin_define
define|#
directive|define
name|FmLINES
parameter_list|(
name|sv
parameter_list|)
value|((XPVFM*)  SvANY(sv))->xfm_lines
end_define

begin_define
define|#
directive|define
name|LvTYPE
parameter_list|(
name|sv
parameter_list|)
value|((XPVLV*)  SvANY(sv))->xlv_type
end_define

begin_define
define|#
directive|define
name|LvTARG
parameter_list|(
name|sv
parameter_list|)
value|((XPVLV*)  SvANY(sv))->xlv_targ
end_define

begin_define
define|#
directive|define
name|LvTARGOFF
parameter_list|(
name|sv
parameter_list|)
value|((XPVLV*)  SvANY(sv))->xlv_targoff
end_define

begin_define
define|#
directive|define
name|LvTARGLEN
parameter_list|(
name|sv
parameter_list|)
value|((XPVLV*)  SvANY(sv))->xlv_targlen
end_define

begin_define
define|#
directive|define
name|IoIFP
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_ifp
end_define

begin_define
define|#
directive|define
name|IoOFP
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_ofp
end_define

begin_define
define|#
directive|define
name|IoDIRP
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_dirp
end_define

begin_define
define|#
directive|define
name|IoANY
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_any
end_define

begin_define
define|#
directive|define
name|IoLINES
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_lines
end_define

begin_define
define|#
directive|define
name|IoPAGE
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_page
end_define

begin_define
define|#
directive|define
name|IoPAGE_LEN
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_page_len
end_define

begin_define
define|#
directive|define
name|IoLINES_LEFT
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_lines_left
end_define

begin_define
define|#
directive|define
name|IoTOP_NAME
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_top_name
end_define

begin_define
define|#
directive|define
name|IoTOP_GV
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_top_gv
end_define

begin_define
define|#
directive|define
name|IoFMT_NAME
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_fmt_name
end_define

begin_define
define|#
directive|define
name|IoFMT_GV
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_fmt_gv
end_define

begin_define
define|#
directive|define
name|IoBOTTOM_NAME
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*) SvANY(sv))->xio_bottom_name
end_define

begin_define
define|#
directive|define
name|IoBOTTOM_GV
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_bottom_gv
end_define

begin_define
define|#
directive|define
name|IoSUBPROCESS
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_subprocess
end_define

begin_define
define|#
directive|define
name|IoTYPE
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_type
end_define

begin_define
define|#
directive|define
name|IoFLAGS
parameter_list|(
name|sv
parameter_list|)
value|((XPVIO*)  SvANY(sv))->xio_flags
end_define

begin_comment
comment|/* IoTYPE(sv) is a single character telling the type of I/O connection. */
end_comment

begin_define
define|#
directive|define
name|IoTYPE_RDONLY
value|'<'
end_define

begin_define
define|#
directive|define
name|IoTYPE_WRONLY
value|'>'
end_define

begin_define
define|#
directive|define
name|IoTYPE_RDWR
value|'+'
end_define

begin_define
define|#
directive|define
name|IoTYPE_APPEND
value|'a'
end_define

begin_define
define|#
directive|define
name|IoTYPE_PIPE
value|'|'
end_define

begin_define
define|#
directive|define
name|IoTYPE_STD
value|'-'
end_define

begin_comment
comment|/* stdin or stdout */
end_comment

begin_define
define|#
directive|define
name|IoTYPE_SOCKET
value|'s'
end_define

begin_define
define|#
directive|define
name|IoTYPE_CLOSED
value|' '
end_define

begin_comment
comment|/* =for apidoc Am|bool|SvTAINTED|SV* sv Checks to see if an SV is tainted. Returns TRUE if it is, FALSE if not.  =for apidoc Am|void|SvTAINTED_on|SV* sv Marks an SV as tainted.  =for apidoc Am|void|SvTAINTED_off|SV* sv Untaints an SV. Be I<very> careful with this routine, as it short-circuits some of Perl's fundamental security features. XS module authors should not use this function unless they fully understand all the implications of unconditionally untainting the value. Untainting should be done in the standard perl fashion, via a carefully crafted regexp, rather than directly untainting variables.  =for apidoc Am|void|SvTAINT|SV* sv Taints an SV if tainting is enabled  =cut */
end_comment

begin_define
define|#
directive|define
name|SvTAINTED
parameter_list|(
name|sv
parameter_list|)
value|(SvMAGICAL(sv)&& sv_tainted(sv))
end_define

begin_define
define|#
directive|define
name|SvTAINTED_on
parameter_list|(
name|sv
parameter_list|)
value|STMT_START{ if(PL_tainting){sv_taint(sv);}   }STMT_END
end_define

begin_define
define|#
directive|define
name|SvTAINTED_off
parameter_list|(
name|sv
parameter_list|)
value|STMT_START{ if(PL_tainting){sv_untaint(sv);} }STMT_END
end_define

begin_define
define|#
directive|define
name|SvTAINT
parameter_list|(
name|sv
parameter_list|)
define|\
value|STMT_START {			\ 	if (PL_tainting) {		\ 	    if (PL_tainted)		\ 		SvTAINTED_on(sv);	\ 	}				\     } STMT_END
end_define

begin_comment
comment|/* =for apidoc Am|char*|SvPV_force|SV* sv|STRLEN len Like<SvPV> but will force the SV into becoming a string (SvPOK).  You want force if you are going to update the SvPVX directly.  =for apidoc Am|char*|SvPV|SV* sv|STRLEN len Returns a pointer to the string in the SV, or a stringified form of the SV if the SV does not contain a string.  Handles 'get' magic.  =for apidoc Am|char*|SvPV_nolen|SV* sv Returns a pointer to the string in the SV, or a stringified form of the SV if the SV does not contain a string.  Handles 'get' magic.  =for apidoc Am|IV|SvIV|SV* sv Coerces the given SV to an integer and returns it.  =for apidoc Am|NV|SvNV|SV* sv Coerce the given SV to a double and return it.  =for apidoc Am|UV|SvUV|SV* sv Coerces the given SV to an unsigned integer and returns it.  =for apidoc Am|bool|SvTRUE|SV* sv Returns a boolean indicating whether Perl would evaluate the SV as true or false, defined or undefined.  Does not handle 'get' magic.  =cut */
end_comment

begin_define
define|#
directive|define
name|SvPV_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvn_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPV
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvn(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPV_nolen
parameter_list|(
name|sv
parameter_list|)
value|sv_pv(sv)
end_define

begin_define
define|#
directive|define
name|SvPVutf8_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvutf8n_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVutf8
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvutf8n(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVutf8_nolen
parameter_list|(
name|sv
parameter_list|)
value|sv_pvutf8(sv)
end_define

begin_define
define|#
directive|define
name|SvPVbyte_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvbyte_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVbyte
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvbyten(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVbyte_nolen
parameter_list|(
name|sv
parameter_list|)
value|sv_pvbyte(sv)
end_define

begin_define
define|#
directive|define
name|SvPVx
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvn(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVx_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvn_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVutf8x
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvutf8n(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVutf8x_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvutf8n_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVbytex
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvbyten(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvPVbytex_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|sv_pvbyten_force(sv,&lp)
end_define

begin_define
define|#
directive|define
name|SvIVx
parameter_list|(
name|sv
parameter_list|)
value|sv_iv(sv)
end_define

begin_define
define|#
directive|define
name|SvUVx
parameter_list|(
name|sv
parameter_list|)
value|sv_uv(sv)
end_define

begin_define
define|#
directive|define
name|SvNVx
parameter_list|(
name|sv
parameter_list|)
value|sv_nv(sv)
end_define

begin_define
define|#
directive|define
name|SvTRUEx
parameter_list|(
name|sv
parameter_list|)
value|sv_true(sv)
end_define

begin_define
define|#
directive|define
name|SvIV
parameter_list|(
name|sv
parameter_list|)
value|SvIVx(sv)
end_define

begin_define
define|#
directive|define
name|SvNV
parameter_list|(
name|sv
parameter_list|)
value|SvNVx(sv)
end_define

begin_define
define|#
directive|define
name|SvUV
parameter_list|(
name|sv
parameter_list|)
value|SvUVx(sv)
end_define

begin_define
define|#
directive|define
name|SvTRUE
parameter_list|(
name|sv
parameter_list|)
value|SvTRUEx(sv)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CRIPPLED_CC
end_ifndef

begin_comment
comment|/* redefine some things to more efficient inlined versions */
end_comment

begin_comment
comment|/* Let us hope that bitmaps for UV and IV are the same */
end_comment

begin_undef
undef|#
directive|undef
name|SvIV
end_undef

begin_define
define|#
directive|define
name|SvIV
parameter_list|(
name|sv
parameter_list|)
value|(SvIOK(sv) ? SvIVX(sv) : sv_2iv(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvUV
end_undef

begin_define
define|#
directive|define
name|SvUV
parameter_list|(
name|sv
parameter_list|)
value|(SvIOK(sv) ? SvUVX(sv) : sv_2uv(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvNV
end_undef

begin_define
define|#
directive|define
name|SvNV
parameter_list|(
name|sv
parameter_list|)
value|(SvNOK(sv) ? SvNVX(sv) : sv_2nv(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvPV
end_undef

begin_define
define|#
directive|define
name|SvPV
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK)) == SVf_POK \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pv(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPV_force
end_undef

begin_define
define|#
directive|define
name|SvPV_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_THINKFIRST)) == SVf_POK \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_pvn_force(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPV_nolen
end_undef

begin_define
define|#
directive|define
name|SvPV_nolen
parameter_list|(
name|sv
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK)) == SVf_POK \      ? SvPVX(sv) : sv_2pv_nolen(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8
end_undef

begin_define
define|#
directive|define
name|SvPVutf8
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK|SVf_UTF8) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pvutf8(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8_force
end_undef

begin_define
define|#
directive|define
name|SvPVutf8_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_THINKFIRST)) == (SVf_POK|SVf_UTF8) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_pvutf8n_force(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8_nolen
end_undef

begin_define
define|#
directive|define
name|SvPVutf8_nolen
parameter_list|(
name|sv
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK|SVf_UTF8)\      ? SvPVX(sv) : sv_2pvutf8_nolen(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8
end_undef

begin_define
define|#
directive|define
name|SvPVutf8
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK|SVf_UTF8) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pvutf8(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8_force
end_undef

begin_define
define|#
directive|define
name|SvPVutf8_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_THINKFIRST)) == (SVf_POK|SVf_UTF8) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_pvutf8n_force(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVutf8_nolen
end_undef

begin_define
define|#
directive|define
name|SvPVutf8_nolen
parameter_list|(
name|sv
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK|SVf_UTF8)\      ? SvPVX(sv) : sv_2pvutf8_nolen(sv))
end_define

begin_undef
undef|#
directive|undef
name|SvPVbyte
end_undef

begin_define
define|#
directive|define
name|SvPVbyte
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_2pvbyte(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVbyte_force
end_undef

begin_define
define|#
directive|define
name|SvPVbyte_force
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8|SVf_THINKFIRST)) == (SVf_POK) \      ? ((lp = SvCUR(sv)), SvPVX(sv)) : sv_pvbyte_force(sv,&lp))
end_define

begin_undef
undef|#
directive|undef
name|SvPVbyte_nolen
end_undef

begin_define
define|#
directive|define
name|SvPVbyte_nolen
parameter_list|(
name|sv
parameter_list|)
define|\
value|((SvFLAGS(sv)& (SVf_POK|SVf_UTF8)) == (SVf_POK)\      ? SvPVX(sv) : sv_2pvbyte_nolen(sv))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_undef
undef|#
directive|undef
name|SvIVx
end_undef

begin_undef
undef|#
directive|undef
name|SvUVx
end_undef

begin_undef
undef|#
directive|undef
name|SvNVx
end_undef

begin_undef
undef|#
directive|undef
name|SvPVx
end_undef

begin_undef
undef|#
directive|undef
name|SvPVutf8x
end_undef

begin_undef
undef|#
directive|undef
name|SvPVbytex
end_undef

begin_undef
undef|#
directive|undef
name|SvTRUE
end_undef

begin_undef
undef|#
directive|undef
name|SvTRUEx
end_undef

begin_define
define|#
directive|define
name|SvIVx
parameter_list|(
name|sv
parameter_list|)
value|({SV *nsv = (SV*)(sv); SvIV(nsv); })
end_define

begin_define
define|#
directive|define
name|SvUVx
parameter_list|(
name|sv
parameter_list|)
value|({SV *nsv = (SV*)(sv); SvUV(nsv); })
end_define

begin_define
define|#
directive|define
name|SvNVx
parameter_list|(
name|sv
parameter_list|)
value|({SV *nsv = (SV*)(sv); SvNV(nsv); })
end_define

begin_define
define|#
directive|define
name|SvPVx
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|({SV *nsv = (sv); SvPV(nsv, lp); })
end_define

begin_define
define|#
directive|define
name|SvPVutf8x
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|({SV *nsv = (sv); SvPVutf8(nsv, lp); })
end_define

begin_define
define|#
directive|define
name|SvPVbytex
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|({SV *nsv = (sv); SvPVbyte(nsv, lp); })
end_define

begin_define
define|#
directive|define
name|SvTRUE
parameter_list|(
name|sv
parameter_list|)
value|(						\     !sv								\     ? 0								\     :    SvPOK(sv)						\ 	?   (({XPV *nxpv = (XPV*)SvANY(sv);			\ 	     nxpv&&						\ 	     (nxpv->xpv_cur> 1 ||				\ 	      (nxpv->xpv_cur&& *nxpv->xpv_pv != '0')); })	\ 	     ? 1						\ 	     : 0)						\ 	:							\ 	    SvIOK(sv)						\ 	    ? SvIVX(sv) != 0					\ 	    :   SvNOK(sv)					\ 		? SvNVX(sv) != 0.0				\ 		: sv_2bool(sv) )
end_define

begin_define
define|#
directive|define
name|SvTRUEx
parameter_list|(
name|sv
parameter_list|)
value|({SV *nsv = (sv); SvTRUE(nsv); })
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __GNUC__ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_THREADS
end_ifndef

begin_comment
comment|/* These inlined macros use globals, which will require a thread  * declaration in user code, so we avoid them under threads */
end_comment

begin_undef
undef|#
directive|undef
name|SvIVx
end_undef

begin_undef
undef|#
directive|undef
name|SvUVx
end_undef

begin_undef
undef|#
directive|undef
name|SvNVx
end_undef

begin_undef
undef|#
directive|undef
name|SvPVx
end_undef

begin_undef
undef|#
directive|undef
name|SvPVutf8x
end_undef

begin_undef
undef|#
directive|undef
name|SvPVbytex
end_undef

begin_undef
undef|#
directive|undef
name|SvTRUE
end_undef

begin_undef
undef|#
directive|undef
name|SvTRUEx
end_undef

begin_define
define|#
directive|define
name|SvIVx
parameter_list|(
name|sv
parameter_list|)
value|((PL_Sv = (sv)), SvIV(PL_Sv))
end_define

begin_define
define|#
directive|define
name|SvUVx
parameter_list|(
name|sv
parameter_list|)
value|((PL_Sv = (sv)), SvUV(PL_Sv))
end_define

begin_define
define|#
directive|define
name|SvNVx
parameter_list|(
name|sv
parameter_list|)
value|((PL_Sv = (sv)), SvNV(PL_Sv))
end_define

begin_define
define|#
directive|define
name|SvPVx
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|((PL_Sv = (sv)), SvPV(PL_Sv, lp))
end_define

begin_define
define|#
directive|define
name|SvPVutf8x
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|((PL_Sv = (sv)), SvPVutf8(PL_Sv, lp))
end_define

begin_define
define|#
directive|define
name|SvPVbytex
parameter_list|(
name|sv
parameter_list|,
name|lp
parameter_list|)
value|((PL_Sv = (sv)), SvPVbyte(PL_Sv, lp))
end_define

begin_define
define|#
directive|define
name|SvTRUE
parameter_list|(
name|sv
parameter_list|)
value|(						\     !sv								\     ? 0								\     :    SvPOK(sv)						\ 	?   ((PL_Xpv = (XPV*)SvANY(sv))&&			\ 	     (PL_Xpv->xpv_cur> 1 ||				\ 	      (PL_Xpv->xpv_cur&& *PL_Xpv->xpv_pv != '0'))	\ 	     ? 1						\ 	     : 0)						\ 	:							\ 	    SvIOK(sv)						\ 	    ? SvIVX(sv) != 0					\ 	    :   SvNOK(sv)					\ 		? SvNVX(sv) != 0.0				\ 		: sv_2bool(sv) )
end_define

begin_define
define|#
directive|define
name|SvTRUEx
parameter_list|(
name|sv
parameter_list|)
value|((PL_Sv = (sv)), SvTRUE(PL_Sv))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_THREADS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNU__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !CRIPPLED_CC */
end_comment

begin_comment
comment|/* =for apidoc Am|SV*|newRV_inc|SV* sv  Creates an RV wrapper for an SV.  The reference count for the original SV is incremented.  =cut */
end_comment

begin_define
define|#
directive|define
name|newRV_inc
parameter_list|(
name|sv
parameter_list|)
value|newRV(sv)
end_define

begin_comment
comment|/* the following macros update any magic values this sv is associated with */
end_comment

begin_comment
comment|/* =for apidoc Am|void|SvGETMAGIC|SV* sv Invokes C<mg_get> on an SV if it has 'get' magic.  This macro evaluates its argument more than once.  =for apidoc Am|void|SvSETMAGIC|SV* sv Invokes C<mg_set> on an SV if it has 'set' magic.  This macro evaluates its argument more than once.  =for apidoc Am|void|SvSetSV|SV* dsb|SV* ssv Calls C<sv_setsv> if dsv is not the same as ssv.  May evaluate arguments more than once.  =for apidoc Am|void|SvSetSV_nosteal|SV* dsv|SV* ssv Calls a non-destructive version of C<sv_setsv> if dsv is not the same as ssv. May evaluate arguments more than once.  =for apidoc Am|void|SvGROW|SV* sv|STRLEN len Expands the character buffer in the SV so that it has room for the indicated number of bytes (remember to reserve space for an extra trailing NUL character).  Calls C<sv_grow> to perform the expansion if necessary.  Returns a pointer to the character buffer.  =cut */
end_comment

begin_define
define|#
directive|define
name|SvGETMAGIC
parameter_list|(
name|x
parameter_list|)
value|STMT_START { if (SvGMAGICAL(x)) mg_get(x); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvSETMAGIC
parameter_list|(
name|x
parameter_list|)
value|STMT_START { if (SvSMAGICAL(x)) mg_set(x); } STMT_END
end_define

begin_define
define|#
directive|define
name|SvSetSV_and
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|finally
parameter_list|)
define|\
value|STMT_START {					\ 	    if ((dst) != (src)) {			\ 		sv_setsv(dst, src);			\ 		finally;				\ 	    }						\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|SvSetSV_nosteal_and
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|finally
parameter_list|)
define|\
value|STMT_START {					\ 	    if ((dst) != (src)) {			\ 		U32 tMpF = SvFLAGS(src)& SVs_TEMP;	\ 		SvTEMP_off(src);			\ 		sv_setsv(dst, src);			\ 		SvFLAGS(src) |= tMpF;			\ 		finally;				\ 	    }						\ 	} STMT_END
end_define

begin_define
define|#
directive|define
name|SvSetSV
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|SvSetSV_and(dst,src,
comment|/*nothing*/
value|;)
end_define

begin_define
define|#
directive|define
name|SvSetSV_nosteal
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|SvSetSV_nosteal_and(dst,src,
comment|/*nothing*/
value|;)
end_define

begin_define
define|#
directive|define
name|SvSetMagicSV
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|SvSetSV_and(dst,src,SvSETMAGIC(dst))
end_define

begin_define
define|#
directive|define
name|SvSetMagicSV_nosteal
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|SvSetSV_nosteal_and(dst,src,SvSETMAGIC(dst))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUGGING
end_ifdef

begin_define
define|#
directive|define
name|SvPEEK
parameter_list|(
name|sv
parameter_list|)
value|sv_peek(sv)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SvPEEK
parameter_list|(
name|sv
parameter_list|)
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SvIMMORTAL
parameter_list|(
name|sv
parameter_list|)
value|((sv)==&PL_sv_undef || (sv)==&PL_sv_yes || (sv)==&PL_sv_no)
end_define

begin_define
define|#
directive|define
name|boolSV
parameter_list|(
name|b
parameter_list|)
value|((b) ?&PL_sv_yes :&PL_sv_no)
end_define

begin_define
define|#
directive|define
name|isGV
parameter_list|(
name|sv
parameter_list|)
value|(SvTYPE(sv) == SVt_PVGV)
end_define

begin_define
define|#
directive|define
name|SvGROW
parameter_list|(
name|sv
parameter_list|,
name|len
parameter_list|)
value|(SvLEN(sv)< (len) ? sv_grow(sv,len) : SvPVX(sv))
end_define

begin_define
define|#
directive|define
name|Sv_Grow
value|sv_grow
end_define

begin_define
define|#
directive|define
name|CLONEf_COPY_STACKS
value|1
end_define

begin_define
define|#
directive|define
name|CLONEf_KEEP_PTR_TABLE
value|2
end_define

end_unit

