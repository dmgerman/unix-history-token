begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pass2.h */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/pepsy/RCS/pass2.h,v 7.7 91/02/22 09:49:23 mrose Interim $  *  *  * $Log:	pass2.h,v $  * Revision 7.7  91/02/22  09:49:23  mrose  * Interim 6.8  *   * Revision 7.6  90/12/23  17:24:56  mrose  * patches  *   * Revision 7.5  90/11/11  10:54:03  mrose  * update  *   * Revision 7.4  90/11/04  19:19:01  mrose  * update  *   * Revision 7.3  90/07/27  08:49:28  mrose  * update  *   * Revision 7.2  90/07/09  14:52:47  mrose  * sync  *   * Revision 7.1  90/07/01  20:01:13  mrose  * update  *   * Revision 7.0  90/07/01  19:54:43  mrose  * *** empty log message ***  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_comment
comment|/* Change the version number only important features change - so people can  * #ifdef on the version number. Also used to provide backwards compatible  * macro definitions for posy/pepy.  */
end_comment

begin_define
define|#
directive|define
name|PEPSY_VERSION_NUMBER
value|2
end_define

begin_define
define|#
directive|define
name|NBPC
value|8
end_define

begin_comment
comment|/* Number of Bits per character - machine dependant */
end_comment

begin_define
define|#
directive|define
name|NBPI
value|sizeof (int)*NBPC
end_define

begin_comment
comment|/* Number of bits per integer */
end_comment

begin_define
define|#
directive|define
name|PSAP_DOT_H
value|"\"psap.h\""
end_define

begin_define
define|#
directive|define
name|I_PSAP_DOT_H
value|"<isode/psap.h>"
end_define

begin_define
define|#
directive|define
name|UNIV_TYPES_DOT_H
value|"\"UNIV-types.h\""
end_define

begin_define
define|#
directive|define
name|I_UNIV_TYPES_DOT_H
value|"<isode/pepsy/UNIV-types.h>"
end_define

begin_define
define|#
directive|define
name|HFILE1
value|"_defs.h"
end_define

begin_define
define|#
directive|define
name|HFILE2
value|"_pre_defs.h"
end_define

begin_define
define|#
directive|define
name|ACTIONDEFS
value|"_action.h"
end_define

begin_define
define|#
directive|define
name|GENTYPES
value|"-types.h"
end_define

begin_define
define|#
directive|define
name|INCFILE1
value|"pepsy.h"
end_define

begin_comment
comment|/* #define INCFILE2	"pepdefs.h" - not used any more */
end_comment

begin_define
define|#
directive|define
name|ACT1
value|"_act1"
end_define

begin_define
define|#
directive|define
name|ACT2
value|"_act2"
end_define

begin_define
define|#
directive|define
name|ACT3
value|"_act3"
end_define

begin_define
define|#
directive|define
name|ACT4
value|"_act4"
end_define

begin_define
define|#
directive|define
name|ACT05
value|"_act05"
end_define

begin_define
define|#
directive|define
name|PREFIX
value|"_Z"
end_define

begin_define
define|#
directive|define
name|ETABLE
value|"et_"
end_define

begin_define
define|#
directive|define
name|DTABLE
value|"dt_"
end_define

begin_define
define|#
directive|define
name|PTABLE
value|"pt_"
end_define

begin_define
define|#
directive|define
name|ENCFNCNAME
value|"enc_f"
end_define

begin_define
define|#
directive|define
name|DECFNCNAME
value|"dec_f"
end_define

begin_define
define|#
directive|define
name|PRNTFNCNAME
value|"prnt_f"
end_define

begin_define
define|#
directive|define
name|ENC_FNCNAME
value|"enc_f_"
end_define

begin_define
define|#
directive|define
name|DEC_FNCNAME
value|"dec_f_"
end_define

begin_define
define|#
directive|define
name|PRNT_FNCNAME
value|"prnt_f_"
end_define

begin_define
define|#
directive|define
name|ENCFILENAME
value|"_enc.c"
end_define

begin_define
define|#
directive|define
name|DECFILENAME
value|"_dec.c"
end_define

begin_define
define|#
directive|define
name|PRNTFILENAME
value|"_prnt.c"
end_define

begin_define
define|#
directive|define
name|TBLNAME
value|"_tables.c"
end_define

begin_define
define|#
directive|define
name|MODTYP_SUFFIX
value|"_mod"
end_define

begin_define
define|#
directive|define
name|MAXPTRS
value|200
end_define

begin_comment
comment|/* maximum number of pointers in pointer table */
end_comment

begin_define
define|#
directive|define
name|PTR_TABNAME
value|"ptrtab"
end_define

begin_decl_stmt
specifier|extern
name|int
name|p_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DEB
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEB
end_ifdef

begin_define
define|#
directive|define
name|Printf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|if (x<= p_debug) printf y
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Printf
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * info for handling a Universal type  */
end_comment

begin_struct
struct|struct
name|univ_typ
block|{
name|char
modifier|*
name|univ_name
decl_stmt|;
comment|/* Name of this Universal type */
name|char
modifier|*
name|univ_data
decl_stmt|;
comment|/* type to generate for it */
name|char
modifier|*
name|univ_tab
decl_stmt|;
comment|/* type of table entry it needs */
name|int
name|univ_id
decl_stmt|;
comment|/* tag of the type */
name|int
name|univ_class
decl_stmt|;
comment|/* class - probably Universal primative */
name|char
modifier|*
name|univ_mod
decl_stmt|;
comment|/* Name of its module if it has one  */
name|int
name|univ_flags
decl_stmt|;
comment|/* Information about entry */
name|int
name|univ_type
decl_stmt|;
comment|/* Type we can use for its contents */
define|#
directive|define
name|UNF_EXTMOD
value|1
comment|/* Use an external module reference */
define|#
directive|define
name|UNF_HASDATA
value|2
comment|/* Has data structure - allocate data for it */
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|univ_typ
modifier|*
name|univtyp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* How many entries in an array */
end_comment

begin_define
define|#
directive|define
name|NENTRIES
parameter_list|(
name|x
parameter_list|)
value|(sizeof (x)/sizeof ((x)[0]))
end_define

begin_comment
comment|/* used to specify which tables a routine is to generate */
end_comment

begin_define
define|#
directive|define
name|G_ENC
value|0
end_define

begin_comment
comment|/* encoding */
end_comment

begin_define
define|#
directive|define
name|G_DEC
value|1
end_define

begin_comment
comment|/* decoding */
end_comment

begin_define
define|#
directive|define
name|G_PNT
value|2
end_define

begin_comment
comment|/* printing */
end_comment

begin_define
define|#
directive|define
name|hflag
value|(options[0])
end_define

begin_define
define|#
directive|define
name|Hflag
value|(options[1])
end_define

begin_define
define|#
directive|define
name|h2flag
value|(options[2])
end_define

begin_define
define|#
directive|define
name|NOPTIONS
value|3
end_define

begin_decl_stmt
specifier|extern
name|int
name|options
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STRSIZE
value|128
end_define

begin_comment
comment|/* general buffer size */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|proc_name
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getfield
argument_list|()
decl_stmt|,
modifier|*
name|getfldbit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|class2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gen_ventry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generate a Value Passing Entry */
end_comment

begin_function_decl
specifier|extern
name|int
name|gen_fnentry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generate a function calling entry */
end_comment

begin_comment
comment|/* extern Action	start_action, final_action; */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|int2tstr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* integer to temporary string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getfield
argument_list|()
decl_stmt|,
modifier|*
name|getfldbit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|class2str
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gen_ventry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generate a Value Passing Entry */
end_comment

begin_function_decl
specifier|extern
name|int
name|gen_fnentry
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* generate a function calling entry */
end_comment

begin_comment
comment|/* extern Action	start_action, final_action; */
end_comment

end_unit

