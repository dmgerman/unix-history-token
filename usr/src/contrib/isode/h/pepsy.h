begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pepsy.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/h/RCS/pepsy.h,v 7.9 91/02/22 09:24:51 mrose Interim $  *  *  * $Log:	pepsy.h,v $  * Revision 7.9  91/02/22  09:24:51  mrose  * Interim 6.8  *   * Revision 7.8  90/12/23  18:41:51  mrose  * update  *   * Revision 7.7  90/12/11  10:33:01  mrose  * sync  *   * Revision 7.5  90/11/11  10:01:21  mrose  * touch-up  *   * Revision 7.4  90/11/04  19:17:54  mrose  * update  *   * Revision 7.3  90/08/18  00:43:47  mrose  * touch-up  *   * Revision 7.2  90/08/08  14:12:29  mrose  * update  *   * Revision 7.1  90/07/09  14:37:55  mrose  * sync  *   * Revision 7.0  90/07/01  19:52:37  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEPSY_DEFINITIONS
end_ifndef

begin_define
define|#
directive|define
name|PEPSY_DEFINITIONS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|PEPYPARM
end_ifndef

begin_define
define|#
directive|define
name|PEPYPARM
value|char *
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Definitions for pep tables  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|pe_type
decl_stmt|;
comment|/* Type of entry */
name|integer
name|pe_ucode
decl_stmt|;
comment|/* index to user's code if any */
name|int
name|pe_tag
decl_stmt|;
comment|/* Tag of this entry if any */
name|int
name|pe_flags
decl_stmt|;
comment|/* Flags */
block|}
name|tpe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLTPE
value|((tpe *)0)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|pe_type
decl_stmt|;
comment|/* Type of entry */
name|integer
name|pe_ucode
decl_stmt|;
comment|/* index to user's code if any */
name|int
name|pe_tag
decl_stmt|;
comment|/* Tag of this entry if any */
name|int
name|pe_flags
decl_stmt|;
comment|/* Flags */
name|char
modifier|*
name|pe_typename
decl_stmt|;
comment|/* User defined name of variable */
block|}
name|ptpe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLPTPE
value|((ptpe *)0)
end_define

begin_comment
comment|/* extract a pointer from the pointer table */
end_comment

begin_define
define|#
directive|define
name|GPTR
parameter_list|(
name|mod
parameter_list|,
name|ind
parameter_list|,
name|type
parameter_list|)
value|((type )(mod)->md_ptrtab[ind])
end_define

begin_comment
comment|/* tricky situation with the "type" - it must not contain the brackets of the  * cast because we supply them here   */
end_comment

begin_comment
comment|/* macros for getting values of default flexibly */
end_comment

begin_define
define|#
directive|define
name|IVAL
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|((x)->pe_ucode)
end_define

begin_comment
comment|/* Integer value */
end_comment

begin_define
define|#
directive|define
name|PVAL
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|(GPTR(mod, (x)->pe_tag, char *))
end_define

begin_comment
comment|/* (char *) */
end_comment

begin_define
define|#
directive|define
name|TVAL
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|((x)->pe_flags)
end_define

begin_comment
comment|/* Type - Integer value */
end_comment

begin_define
define|#
directive|define
name|RVAL
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|(*GPTR(mod, (x)->pe_tag, double *))
end_define

begin_comment
comment|/* double */
end_comment

begin_comment
comment|/* macros for getting the function pointer (for a FN_CALL entry) */
end_comment

begin_define
define|#
directive|define
name|FN_PTR
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|(*GPTR(mod, (x)->pe_ucode, IFP ))
end_define

begin_comment
comment|/* function ptr */
end_comment

begin_comment
comment|/* macros for getting other more general pointers transparently */
end_comment

begin_define
define|#
directive|define
name|EXT2MOD
parameter_list|(
name|mod
parameter_list|,
name|x
parameter_list|)
value|(GPTR(mod, (x)->pe_ucode, modtyp *))
end_define

begin_comment
comment|/* Types */
end_comment

begin_define
define|#
directive|define
name|PE_START
value|(-1)
end_define

begin_define
define|#
directive|define
name|PE_END
value|0
end_define

begin_define
define|#
directive|define
name|XOBJECT
value|3
end_define

begin_define
define|#
directive|define
name|UCODE
value|6
end_define

begin_define
define|#
directive|define
name|MEMALLOC
value|7
end_define

begin_define
define|#
directive|define
name|SCTRL
value|8
end_define

begin_define
define|#
directive|define
name|CH_ACT
value|9
end_define

begin_define
define|#
directive|define
name|OPTL
value|10
end_define

begin_comment
comment|/* Optionals field offset */
end_comment

begin_define
define|#
directive|define
name|BOPTIONAL
value|11
end_define

begin_comment
comment|/* optional test for next */
end_comment

begin_define
define|#
directive|define
name|FFN_CALL
value|12
end_define

begin_comment
comment|/* call the free function */
end_comment

begin_define
define|#
directive|define
name|FREE_ONLY
value|13
end_define

begin_comment
comment|/* the next item is only for freeing code */
end_comment

begin_comment
comment|/* types that generate data */
end_comment

begin_define
define|#
directive|define
name|TYPE_DATA
value|20
end_define

begin_define
define|#
directive|define
name|ANY
value|(TYPE_DATA + 0)
end_define

begin_define
define|#
directive|define
name|INTEGER
value|(TYPE_DATA + 1)
end_define

begin_define
define|#
directive|define
name|BOOLEAN
value|(TYPE_DATA + 2)
end_define

begin_define
define|#
directive|define
name|OBJECT
value|(TYPE_DATA + 3)
end_define

begin_comment
comment|/* This generates data */
end_comment

begin_define
define|#
directive|define
name|BITSTRING
value|(TYPE_DATA + 4)
end_define

begin_define
define|#
directive|define
name|OCTETSTRING
value|(TYPE_DATA + 5)
end_define

begin_define
define|#
directive|define
name|SET_START
value|(TYPE_DATA + 6)
end_define

begin_define
define|#
directive|define
name|SEQ_START
value|(TYPE_DATA + 7)
end_define

begin_define
define|#
directive|define
name|SEQOF_START
value|(TYPE_DATA + 8)
end_define

begin_define
define|#
directive|define
name|SETOF_START
value|(TYPE_DATA + 9)
end_define

begin_define
define|#
directive|define
name|CHOICE_START
value|(TYPE_DATA + 10)
end_define

begin_define
define|#
directive|define
name|REALTYPE
value|(TYPE_DATA + 11)
end_define

begin_comment
comment|/* ASN.1 Real */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|(TYPE_DATA + 12)
end_define

begin_define
define|#
directive|define
name|T_OID
value|(TYPE_DATA + 13)
end_define

begin_define
define|#
directive|define
name|ETAG
value|(TYPE_DATA + 14)
end_define

begin_comment
comment|/*so set_find in pr_set is executed*/
end_comment

begin_define
define|#
directive|define
name|IMP_OBJ
value|(TYPE_DATA + 15)
end_define

begin_comment
comment|/*so set_find in pr_set is executed*/
end_comment

begin_define
define|#
directive|define
name|EXTOBJ
value|(TYPE_DATA + 16)
end_define

begin_comment
comment|/* External reference object */
end_comment

begin_define
define|#
directive|define
name|EXTMOD
value|(TYPE_DATA + 17)
end_define

begin_comment
comment|/* External module for above object */
end_comment

begin_define
define|#
directive|define
name|OBJID
value|(TYPE_DATA + 18)
end_define

begin_comment
comment|/* Object Identifier */
end_comment

begin_define
define|#
directive|define
name|DFLT_F
value|(TYPE_DATA + 19)
end_define

begin_comment
comment|/* Default value for following entry */
end_comment

begin_define
define|#
directive|define
name|DFLT_B
value|(TYPE_DATA + 20)
end_define

begin_comment
comment|/* default value for previous entry */
end_comment

begin_define
define|#
directive|define
name|T_STRING
value|(TYPE_DATA + 21)
end_define

begin_comment
comment|/* [[ s ptr ]] supporting entry */
end_comment

begin_define
define|#
directive|define
name|OCTET_PTR
value|(TYPE_DATA + 22)
end_define

begin_comment
comment|/* [[ o ptr $ len]] str entry */
end_comment

begin_define
define|#
directive|define
name|OCTET_LEN
value|(TYPE_DATA + 23)
end_define

begin_comment
comment|/* [[ o ptr $ len]] len entry */
end_comment

begin_define
define|#
directive|define
name|BITSTR_PTR
value|(TYPE_DATA + 24)
end_define

begin_comment
comment|/* [[ x ptr $ len]] str entry */
end_comment

begin_define
define|#
directive|define
name|BITSTR_LEN
value|(TYPE_DATA + 25)
end_define

begin_comment
comment|/* [[ x ptr $ len]] len entry */
end_comment

begin_define
define|#
directive|define
name|FN_CALL
value|(TYPE_DATA + 26)
end_define

begin_comment
comment|/* call a function to do the work */
end_comment

begin_if
if|#
directive|if
name|PEPSY_VERSION
operator|>=
literal|2
end_if

begin_define
define|#
directive|define
name|STYPE_DATA
value|(TYPE_DATA + 50)
end_define

begin_comment
comment|/* Below here are the S* items */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STYPE_DATA
value|(TYPE_DATA + 30)
end_define

begin_comment
comment|/* Below here are the S* items */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Optimised - No indirection to cope with ISODE optimisation */
end_comment

begin_define
define|#
directive|define
name|SBITSTRING
value|(STYPE_DATA + 0)
end_define

begin_comment
comment|/* No offset */
end_comment

begin_define
define|#
directive|define
name|SOBJID
value|(STYPE_DATA + 1)
end_define

begin_comment
comment|/* Object Identifier - No offset */
end_comment

begin_define
define|#
directive|define
name|SREALTYPE
value|(STYPE_DATA + 2)
end_define

begin_comment
comment|/* ASN.1 Real */
end_comment

begin_define
define|#
directive|define
name|SANY
value|(STYPE_DATA + 3)
end_define

begin_define
define|#
directive|define
name|SEXTOBJ
value|(STYPE_DATA + 4)
end_define

begin_comment
comment|/* External reference object */
end_comment

begin_define
define|#
directive|define
name|SOBJECT
value|(STYPE_DATA + 5)
end_define

begin_comment
comment|/* This generates data */
end_comment

begin_define
define|#
directive|define
name|SOCTETSTRING
value|(STYPE_DATA + 6)
end_define

begin_comment
comment|/* No offset */
end_comment

begin_define
define|#
directive|define
name|SEXTERNAL
value|(STYPE_DATA + 7)
end_define

begin_comment
comment|/* External to be encoded */
end_comment

begin_define
define|#
directive|define
name|SSEQ_START
value|(STYPE_DATA + 8)
end_define

begin_comment
comment|/* SEQUENCE don't indirect */
end_comment

begin_define
define|#
directive|define
name|SSET_START
value|(STYPE_DATA + 9)
end_define

begin_comment
comment|/* SET don't do an indirection */
end_comment

begin_define
define|#
directive|define
name|SSEQOF_START
value|(STYPE_DATA + 10)
end_define

begin_comment
comment|/* SEQOF - no indirection */
end_comment

begin_define
define|#
directive|define
name|SSETOF_START
value|(STYPE_DATA + 11)
end_define

begin_comment
comment|/* SETOF - no indirection */
end_comment

begin_define
define|#
directive|define
name|SCHOICE_START
value|(STYPE_DATA + 12)
end_define

begin_comment
comment|/* CHOICE - no indirection */
end_comment

begin_define
define|#
directive|define
name|ISDTYPE
parameter_list|(
name|p
parameter_list|)
value|(p->pe_type>= TYPE_DATA)
end_define

begin_comment
comment|/* User code indexes */
end_comment

begin_define
define|#
directive|define
name|NONE
value|0
end_define

begin_comment
comment|/* No User code */
end_comment

begin_comment
comment|/* Standard Tags */
end_comment

begin_define
define|#
directive|define
name|T_BOOL
value|1
end_define

begin_define
define|#
directive|define
name|T_INTEGER
value|2
end_define

begin_define
define|#
directive|define
name|T_OCTETSTRING
value|4
end_define

begin_define
define|#
directive|define
name|T_OBJIDENT
value|6
end_define

begin_define
define|#
directive|define
name|T_EXTERNAL
value|8
end_define

begin_define
define|#
directive|define
name|T_REAL
value|9
end_define

begin_define
define|#
directive|define
name|T_ENUMERATED
value|10
end_define

begin_define
define|#
directive|define
name|T_SEQ
value|16
end_define

begin_define
define|#
directive|define
name|T_SET
value|17
end_define

begin_define
define|#
directive|define
name|T_IA5
value|22
end_define

begin_define
define|#
directive|define
name|T_GRAPHIC
value|25
end_define

begin_comment
comment|/* Flags */
end_comment

begin_comment
comment|/* Use values 0-3 bottom two bits at the moment */
end_comment

begin_comment
comment|/* This has to be changed if the values for the 4 below are changed in ISODE */
end_comment

begin_define
define|#
directive|define
name|FL_CLASS
value|0xf
end_define

begin_comment
comment|/* Class specification */
end_comment

begin_define
define|#
directive|define
name|FL_UNIVERSAL
value|PE_CLASS_UNIV
end_define

begin_define
define|#
directive|define
name|FL_APPLICATION
value|PE_CLASS_APPL
end_define

begin_define
define|#
directive|define
name|FL_CONTEXT
value|PE_CLASS_CONT
end_define

begin_define
define|#
directive|define
name|FL_PRIVATE
value|PE_CLASS_PRIV
end_define

begin_define
define|#
directive|define
name|FL_IMPLICIT
value|0100
end_define

begin_define
define|#
directive|define
name|FL_DEFAULT
value|0200
end_define

begin_define
define|#
directive|define
name|FL_OPTIONAL
value|0400
end_define

begin_define
define|#
directive|define
name|OPTIONAL
parameter_list|(
name|p
parameter_list|)
value|((p)->pe_flags& FL_OPTIONAL)
end_define

begin_define
define|#
directive|define
name|DEFAULT
parameter_list|(
name|p
parameter_list|)
value|((p)->pe_flags& FL_DEFAULT)
end_define

begin_define
define|#
directive|define
name|FL_PRTAG
value|01000
end_define

begin_comment
comment|/* only for printing - print the tag */
end_comment

begin_define
define|#
directive|define
name|PRINT_TAG
parameter_list|(
name|p
parameter_list|)
value|((p)->pe_flags& FL_PRTAG)
end_define

begin_define
define|#
directive|define
name|FL_USELECT
value|02000
end_define

begin_comment
comment|/* user code selects */
end_comment

begin_define
define|#
directive|define
name|IF_USELECT
parameter_list|(
name|p
parameter_list|)
value|((p) -> pe_flags& FL_USELECT)
end_define

begin_define
define|#
directive|define
name|CLASS
parameter_list|(
name|p
parameter_list|)
value|((PElementClass)((p)->pe_flags& FL_CLASS))
end_define

begin_define
define|#
directive|define
name|TAG
parameter_list|(
name|p
parameter_list|)
value|((PElementID)((p)->pe_tag))
end_define

begin_comment
comment|/* signed version of above - needed for tag == -1 */
end_comment

begin_define
define|#
directive|define
name|STAG
parameter_list|(
name|p
parameter_list|)
value|((p)->pe_tag)
end_define

begin_define
define|#
directive|define
name|TESTBIT
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|((p)& (1<< (bit)))
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|((p) |= (1<< (bit)))
end_define

begin_define
define|#
directive|define
name|CLRBIT
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|((p)&= ~(1<< (bit)))
end_define

begin_comment
comment|/* To support the OPTIONAL<< field $ bitno>> construct */
end_comment

begin_define
define|#
directive|define
name|BITTEST
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|(((p)[(bit)/8])& (0x80>> (bit) % 8))
end_define

begin_define
define|#
directive|define
name|BITSET
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|(((p)[(bit)/8]) |= (0x80>> (bit) % 8))
end_define

begin_define
define|#
directive|define
name|BITCLR
parameter_list|(
name|p
parameter_list|,
name|bit
parameter_list|)
value|(((p)[(bit)/8])&= ~(0x80>> (bit) % 8))
end_define

begin_comment
comment|/* compute the number of char's required to support x bits */
end_comment

begin_define
define|#
directive|define
name|NBITS2NCHARS
parameter_list|(
name|x
parameter_list|)
value|(((x) + 7)/8)
end_define

begin_comment
comment|/*  * The module table. One per module which gives access to everything one needs  * to know about the modules types  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|md_name
decl_stmt|;
comment|/* Name of this module */
name|int
name|md_nentries
decl_stmt|;
comment|/* Number of entries */
name|tpe
modifier|*
modifier|*
name|md_etab
decl_stmt|;
comment|/* Pointer to encoding tables */
name|tpe
modifier|*
modifier|*
name|md_dtab
decl_stmt|;
comment|/* Pointer to decoding tables */
name|ptpe
modifier|*
modifier|*
name|md_ptab
decl_stmt|;
comment|/* Pointer to printing tables */
name|int
function_decl|(
modifier|*
name|md_eucode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for encoding */
name|int
function_decl|(
modifier|*
name|md_ducode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for decoding */
name|int
function_decl|(
modifier|*
name|md_pucode
function_decl|)
parameter_list|()
function_decl|;
comment|/* User code for printing */
name|caddr_t
modifier|*
name|md_ptrtab
decl_stmt|;
comment|/* pointer table */
block|}
name|modtyp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NULLMODTYP
value|((modtyp *)0)
end_define

begin_define
define|#
directive|define
name|LOTSOFBITS
value|128
end_define

begin_decl_stmt
name|int
name|enc_f
argument_list|()
decl_stmt|,
name|dec_f
argument_list|()
decl_stmt|,
name|fre_obj
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

