begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sector1.h - VTPM: sector 1 definitions */
end_comment

begin_comment
comment|/*   * $Header: /f/osi/vt/RCS/sector1.h,v 7.1 91/02/22 09:48:08 mrose Interim $  *  *  * $Log:	sector1.h,v $  * Revision 7.1  91/02/22  09:48:08  mrose  * Interim 6.8  *   * Revision 7.0  89/11/23  22:31:39  mrose  * Release 6.0  *   */
end_comment

begin_comment
comment|/*  *				  NOTICE  *  *    Acquisition, use, and distribution of this module and related  *    materials are subject to the restrictions of a license agreement.  *    Consult the Preface in the User's Manual for the full terms of  *    this agreement.  *  */
end_comment

begin_define
define|#
directive|define
name|MAXSPARGS
value|2
end_define

begin_comment
comment|/*Max Special Profile Arguments (2 for TLENET)*/
end_comment

begin_define
define|#
directive|define
name|MAXCDSOBJ
value|2
end_define

begin_comment
comment|/*Max Display Objects (2 for TRANSPARENT)*/
end_comment

begin_define
define|#
directive|define
name|MAXCSSOBJ
value|1
end_define

begin_comment
comment|/*Max Control Objects to negotiate*/
end_comment

begin_define
define|#
directive|define
name|MAXDEVOBJ
value|1
end_define

begin_comment
comment|/*Max Device Objects*/
end_comment

begin_define
define|#
directive|define
name|MAXFONTS
value|1
end_define

begin_define
define|#
directive|define
name|MAXREPS
value|1
end_define

begin_comment
comment|/*Maximum Repertoires*/
end_comment

begin_define
define|#
directive|define
name|MAXEMPS
value|1
end_define

begin_comment
comment|/*Max Background Emphasis*/
end_comment

begin_define
define|#
directive|define
name|MAXCOLORS
value|1
end_define

begin_comment
comment|/*Aw C'mon*/
end_comment

begin_comment
comment|/* ASQ PDU Fields*/
end_comment

begin_define
define|#
directive|define
name|ASQ_basic
value|0
end_define

begin_define
define|#
directive|define
name|ASQ_Imp_Ident
value|1
end_define

begin_define
define|#
directive|define
name|ASQ_Func_Units
value|2
end_define

begin_define
define|#
directive|define
name|ASQ_Profile
value|3
end_define

begin_define
define|#
directive|define
name|ASQ_P_Version
value|4
end_define

begin_define
define|#
directive|define
name|ASQ_Coll_Win
value|5
end_define

begin_comment
comment|/* ASR PDU Fields */
end_comment

begin_define
define|#
directive|define
name|ASR_Fail_String
value|0
end_define

begin_define
define|#
directive|define
name|ASR_Fail_Reason
value|1
end_define

begin_define
define|#
directive|define
name|ASR_Result
value|2
end_define

begin_define
define|#
directive|define
name|ASR_Imp_Ident
value|3
end_define

begin_define
define|#
directive|define
name|ASR_P_Version
value|4
end_define

begin_define
define|#
directive|define
name|ASR_Arg_List
value|5
end_define

begin_define
define|#
directive|define
name|ASR_Func_Units
value|6
end_define

begin_define
define|#
directive|define
name|ASR_Coll_Win
value|7
end_define

begin_comment
comment|/* Functional Units Bit Map*/
end_comment

begin_define
define|#
directive|define
name|profileSwitch
value|0x01
end_define

begin_define
define|#
directive|define
name|profileMIN
value|0x02
end_define

begin_define
define|#
directive|define
name|negRelease
value|0x04
end_define

begin_define
define|#
directive|define
name|urgData
value|0x08
end_define

begin_define
define|#
directive|define
name|destBreak
value|0x10
end_define

begin_comment
comment|/* NDQ ASN.1 Types */
end_comment

begin_define
define|#
directive|define
name|ECHO_ON
value|0
end_define

begin_define
define|#
directive|define
name|ECHO_OFF
value|1
end_define

begin_define
define|#
directive|define
name|DISPLAY_OBJ
value|0
end_define

begin_define
define|#
directive|define
name|CTRL_OBJ
value|1
end_define

begin_define
define|#
directive|define
name|DO_NEXT_X
value|0
end_define

begin_define
define|#
directive|define
name|DO_NEXT_Y
value|1
end_define

begin_define
define|#
directive|define
name|DO_PTR_REL
value|2
end_define

begin_define
define|#
directive|define
name|DO_PTR_ABS
value|3
end_define

begin_define
define|#
directive|define
name|DO_TEXT
value|4
end_define

begin_define
define|#
directive|define
name|DO_RPT_TEXT
value|5
end_define

begin_define
define|#
directive|define
name|DO_ATTR
value|6
end_define

begin_define
define|#
directive|define
name|DO_ERASE
value|7
end_define

begin_define
define|#
directive|define
name|DO_PREV_X
value|8
end_define

begin_define
define|#
directive|define
name|DO_PREV_Y
value|9
end_define

begin_comment
comment|/*DI/KB Control Objects*/
end_comment

begin_define
define|#
directive|define
name|KB_SIZE
value|5
end_define

begin_comment
comment|/* network bit ordering */
end_comment

begin_define
define|#
directive|define
name|IP_OBJ
value|0x80
end_define

begin_define
define|#
directive|define
name|AO_OBJ
value|0x40
end_define

begin_define
define|#
directive|define
name|AYT_OBJ
value|0x20
end_define

begin_define
define|#
directive|define
name|DM_OBJ
value|0x10
end_define

begin_define
define|#
directive|define
name|BRK_OBJ
value|0x08
end_define

begin_comment
comment|/*NI/NA Control Objects*/
end_comment

begin_define
define|#
directive|define
name|NA_SIZE
value|4
end_define

begin_comment
comment|/* network bit ordering */
end_comment

begin_define
define|#
directive|define
name|ECHO_OBJ
value|0x80
end_define

begin_comment
comment|/*0 is Local; 1 is Remote*/
end_comment

begin_define
define|#
directive|define
name|SUP_GA
value|0x40
end_define

begin_comment
comment|/*0 is Use Go Ahead; 1 is Suppress Go Ahead*/
end_comment

begin_define
define|#
directive|define
name|DISP_BIN
value|0x20
end_define

begin_comment
comment|/*1 = WACA is Binary; 0 = WACA is ASCII*/
end_comment

begin_define
define|#
directive|define
name|KBD_BIN
value|0x10
end_define

begin_comment
comment|/*1 = WACI is Binary; 0 = WACI is ASCII*/
end_comment

begin_comment
comment|/*Go Ahead Control Object*/
end_comment

begin_define
define|#
directive|define
name|GA_SIZE
value|1
end_define

begin_comment
comment|/* network bit ordering */
end_comment

begin_define
define|#
directive|define
name|GO_AHEAD
value|0x80
end_define

begin_comment
comment|/*Synch Control Object*/
end_comment

begin_define
define|#
directive|define
name|SYNC_SIZE
value|1
end_define

begin_comment
comment|/* network bit ordering */
end_comment

begin_define
define|#
directive|define
name|SYNC
value|0x80
end_define

begin_comment
comment|/*Default Profile Control Object*/
end_comment

begin_define
define|#
directive|define
name|DEF_SIZE
value|1
end_define

begin_comment
comment|/* network bit ordering */
end_comment

begin_define
define|#
directive|define
name|DEF_ECHO
value|0x80
end_define

begin_comment
comment|/*True for local echo*/
end_comment

begin_define
define|#
directive|define
name|FULL_ASCII
value|"ASCII"
end_define

begin_comment
comment|/*TEMP repertoire ID*/
end_comment

begin_define
define|#
directive|define
name|ASCII_GO
value|"GO"
end_define

begin_define
define|#
directive|define
name|TRANSPARENT
value|"TRANS"
end_define

begin_typedef
typedef|typedef
struct|struct
name|trans_args
comment|/*Arguments for transparent profile*/
block|{
name|int
name|num_reps
decl_stmt|;
name|char
modifier|*
name|rep_ptr
index|[
name|MAXREPS
index|]
decl_stmt|;
name|char
modifier|*
name|cur_rep
decl_stmt|;
comment|/*Currently active repertoire*/
block|}
name|TRANS_ARGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|telnet_args
comment|/*Arguments for telnet profile*/
block|{
name|int
name|x_window
decl_stmt|;
name|char
name|full_ascii
decl_stmt|;
comment|/*If 1, Full ASCII.  If 0, graphics only*/
block|}
name|TELNET_ARGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|vt_profile
comment|/*Structure for profile parameters*/
block|{
name|char
modifier|*
name|profile_name
decl_stmt|;
union|union
block|{
name|TRANS_ARGS
name|tr_arg_list
decl_stmt|;
name|TELNET_ARGS
name|tel_arg_list
decl_stmt|;
block|}
name|arg_val
union|;
block|}
name|VT_PROFILE
typedef|;
end_typedef

begin_comment
comment|/* Data Structures for PDU's */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ex_pointer
comment|/*Explicit Pointer*/
block|{
name|int
name|x_true
decl_stmt|;
name|int
name|x_value
decl_stmt|;
name|int
name|y_true
decl_stmt|;
name|int
name|y_value
decl_stmt|;
name|int
name|z_true
decl_stmt|;
name|int
name|z_value
decl_stmt|;
block|}
name|EX_POINTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pointer
comment|/*General Pointer*/
block|{
name|int
name|ptr_type
decl_stmt|;
comment|/*Values 0 - 6 */
name|EX_POINTER
name|e_ptr
decl_stmt|;
block|}
name|POINTER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rpt_text
comment|/*Repeat text*/
block|{
name|POINTER
name|fin_addr
decl_stmt|;
name|int
name|text_count
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
name|RPT_TEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|erase_text
comment|/*Erase*/
block|{
name|POINTER
name|start_erase
decl_stmt|;
name|POINTER
name|end_erase
decl_stmt|;
name|int
name|erase_attr
decl_stmt|;
comment|/*Boolean*/
block|}
name|ERASE_TEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|text
block|{
name|int
name|text_count
decl_stmt|;
name|char
modifier|*
name|text_ptr
decl_stmt|;
block|}
name|TEXT_CONTENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|attrib
block|{
name|int
name|attr_id
decl_stmt|;
comment|/* 0 - 4*/
name|int
name|attr_val
decl_stmt|;
name|int
name|attr_ext
decl_stmt|;
name|POINTER
name|beg_p
decl_stmt|;
name|POINTER
name|end_p
decl_stmt|;
block|}
name|ATTRIB
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bool_u
block|{
name|int
name|val_count
decl_stmt|;
name|char
modifier|*
name|value
decl_stmt|;
name|int
name|mask_count
decl_stmt|;
name|char
modifier|*
name|mask
decl_stmt|;
block|}
name|BOOL_U
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|bit_str
block|{
name|int
name|bitcount
decl_stmt|;
name|int
name|bitstring
decl_stmt|;
block|}
name|BIT_STR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|do_update
comment|/*Display Object Update*/
block|{
name|char
modifier|*
name|do_name
decl_stmt|;
name|int
name|do_type
decl_stmt|;
comment|/* 0 - 9 */
union|union
block|{
name|EX_POINTER
name|ptr_rel
decl_stmt|;
name|POINTER
name|ptr_abs
decl_stmt|;
name|TEXT_CONTENT
name|text_ud
decl_stmt|;
name|RPT_TEXT
name|rpt_seq
decl_stmt|;
name|ATTRIB
name|wrt_attrib
decl_stmt|;
name|ERASE_TEXT
name|erase
decl_stmt|;
block|}
name|do_cmd
union|;
block|}
name|DO_UPDATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|co_update
comment|/*Control Object Update*/
block|{
name|char
modifier|*
name|co_name
decl_stmt|;
name|int
name|co_type
decl_stmt|;
comment|/* 0 - 4 */
union|union
block|{
name|char
modifier|*
name|char_update
decl_stmt|;
name|BOOL_U
name|bool_update
decl_stmt|;
name|int
name|sym_update
decl_stmt|;
name|int
name|int_update
decl_stmt|;
name|BIT_STR
name|bit_update
decl_stmt|;
block|}
name|co_cmd
union|;
block|}
name|CO_UPDATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|text_update
block|{
name|struct
name|text_update
modifier|*
name|ndq_elem
decl_stmt|;
comment|/*Pointer to next one in queue*/
name|int
name|echo_sw
decl_stmt|;
comment|/*0 = Echo Now; 1 = Not Echo Now*/
name|int
name|type_sw
decl_stmt|;
comment|/*0 = display; 1 = control*/
union|union
block|{
name|DO_UPDATE
name|do_list
decl_stmt|;
name|CO_UPDATE
name|co_list
decl_stmt|;
block|}
name|updates
union|;
block|}
name|TEXT_UPDATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|implem_id
block|{
name|int
name|oid_true
decl_stmt|;
name|OID
name|imp_oid
decl_stmt|;
comment|/*Optional*/
name|int
name|name_true
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/*Optional*/
name|int
name|version_true
decl_stmt|;
name|char
modifier|*
name|version
decl_stmt|;
comment|/*Optional*/
block|}
name|IMPLEM_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|int_offer
block|{
name|int
name|type
decl_stmt|;
comment|/*0 for single value, 1 for range*/
name|int
name|value
decl_stmt|;
name|int
name|min_val
decl_stmt|;
name|int
name|max_val
decl_stmt|;
block|}
name|INT_OFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rep_font
comment|/*Repertoire Font Offer*/
block|{
name|int
name|rep_type
decl_stmt|;
comment|/*1 = NULL; 2 = SEQUENCE....*/
name|char
modifier|*
name|rep_assign
decl_stmt|;
comment|/*0 value for pointer means not used*/
name|int
name|valid_font_cap
decl_stmt|;
name|INT_OFFER
name|capability
decl_stmt|;
name|int
name|num_fonts
decl_stmt|;
name|char
modifier|*
name|font_names
index|[
name|MAXFONTS
index|]
decl_stmt|;
block|}
name|REP_FONT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dimen_param
block|{
name|int
name|bound_type
decl_stmt|;
comment|/*0 for no bound, 1 for unbounded, 2 for 				  INT_OFFER */
name|INT_OFFER
name|bound
decl_stmt|;
name|BIT_STR
name|addressing
decl_stmt|;
comment|/*NOT optional according to 9041*/
name|BIT_STR
name|absolute
decl_stmt|;
comment|/*Optional*/
name|int
name|window_type
decl_stmt|;
comment|/*0 for not used, 1 for unbounded, 2 for 				  INT_OFFER */
name|INT_OFFER
name|window
decl_stmt|;
block|}
name|DIMEN_PARAM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rep_list
comment|/*Repertoire list*/
block|{
name|int
name|valid_cap
decl_stmt|;
name|INT_OFFER
name|capability
decl_stmt|;
comment|/*Listed as optional but seems you should 				  have it. */
name|int
name|num_reps
decl_stmt|;
comment|/*Number of repertoires -- seems it should 				  usually equal capability. */
name|REP_FONT
name|repertoire
index|[
name|MAXREPS
index|]
decl_stmt|;
block|}
name|REP_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|emp_list
block|{
name|int
name|valid_cap
decl_stmt|;
name|INT_OFFER
name|capability
decl_stmt|;
comment|/*Technically Optional*/
name|int
name|num_emps
decl_stmt|;
name|char
modifier|*
name|emp_string
index|[
name|MAXEMPS
index|]
decl_stmt|;
block|}
name|EMP_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|color_list
block|{
name|int
name|valid_cap
decl_stmt|;
name|INT_OFFER
name|capability
decl_stmt|;
name|int
name|num_colors
decl_stmt|;
name|char
modifier|*
name|color_string
index|[
name|MAXCOLORS
index|]
decl_stmt|;
block|}
name|COLOR_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cds_offer
block|{
name|char
modifier|*
name|obj_name
decl_stmt|;
name|BIT_STR
name|dimensions
decl_stmt|;
name|int
name|valid_x_dim
decl_stmt|;
name|DIMEN_PARAM
name|x_dim
decl_stmt|;
name|int
name|valid_y_dim
decl_stmt|;
name|DIMEN_PARAM
name|y_dim
decl_stmt|;
name|int
name|valid_z_dim
decl_stmt|;
name|DIMEN_PARAM
name|z_dim
decl_stmt|;
name|BIT_STR
name|erasure
decl_stmt|;
name|int
name|valid_rep_list
decl_stmt|;
name|REP_LIST
name|rep_offer
decl_stmt|;
name|int
name|valid_emp_list
decl_stmt|;
name|EMP_LIST
name|emp_offer
decl_stmt|;
name|int
name|valid_fore_color
decl_stmt|;
name|COLOR_LIST
name|fore_color_list
decl_stmt|;
name|int
name|valid_back_color
decl_stmt|;
name|COLOR_LIST
name|back_color_list
decl_stmt|;
name|BIT_STR
name|access_right
decl_stmt|;
block|}
name|CDS_OFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|css_offer
comment|/*Unused in TELNET (and hopefully Forms)*/
block|{
name|int
name|i
decl_stmt|;
comment|/*For compiler*/
block|}
name|CSS_OFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dev_offer
comment|/*Also unused*/
block|{
name|int
name|i
decl_stmt|;
comment|/*For compiler*/
block|}
name|DEV_OFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|special_offer
block|{
name|int
name|param_num
decl_stmt|;
name|int
name|param_type
decl_stmt|;
comment|/*0,1,or2*/
union|union
block|{
name|char
modifier|*
name|bool_arg
decl_stmt|;
comment|/*Turns into bitstring = 0 or 1*/
name|INT_OFFER
name|int_arg
decl_stmt|;
name|char
modifier|*
name|string_arg
decl_stmt|;
block|}
name|args
union|;
block|}
name|SPECIAL_OFFER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|arg_offer_list
block|{
name|int
name|oid_true
decl_stmt|;
comment|/*Optional--Use Default Profile if not specified*/
name|OID
name|prof_oid
decl_stmt|;
name|int
name|num_sp_param
decl_stmt|;
comment|/*Number of special profile arguments*/
name|int
name|num_cds_objects
decl_stmt|;
comment|/*Number of Conceptual Data Store objects*/
name|int
name|num_css_objects
decl_stmt|;
comment|/*Number of Control Signal Status objects*/
name|int
name|num_dev_objects
decl_stmt|;
comment|/*Number of Device Object identifiers*/
name|SPECIAL_OFFER
name|sp_offer_list
index|[
name|MAXSPARGS
index|]
decl_stmt|;
name|CDS_OFFER
name|cds_offer_list
index|[
name|MAXCDSOBJ
index|]
decl_stmt|;
name|CSS_OFFER
name|css_offer_list
index|[
name|MAXCSSOBJ
index|]
decl_stmt|;
name|DEV_OFFER
name|dev_offer_list
index|[
name|MAXDEVOBJ
index|]
decl_stmt|;
name|BIT_STR
name|del_ctrl
decl_stmt|;
comment|/*Delivery Control*/
block|}
name|ARG_OFFER_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asq_msg
block|{
name|int
name|class
decl_stmt|;
comment|/*Basic only (=1)*/
name|int
name|valid_imp
decl_stmt|;
name|IMPLEM_ID
name|imp_id
decl_stmt|;
comment|/*Optional*/
name|BIT_STR
name|func_units
decl_stmt|;
name|int
name|valid_prof
decl_stmt|;
name|ARG_OFFER_LIST
name|asq_profile
decl_stmt|;
comment|/*Profile is optional*/
name|BIT_STR
name|version
decl_stmt|;
comment|/*Default = '1'B*/
name|int
name|valid_coll
decl_stmt|;
name|int
name|coll_winner
decl_stmt|;
comment|/*Optional*/
block|}
name|ASQ_MSG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|fail_reason
block|{
name|int
name|type
decl_stmt|;
comment|/*0 or 1*/
name|char
modifier|*
name|usr_reason
decl_stmt|;
name|int
name|provider_reason
decl_stmt|;
comment|/* 1,2,3,or 4*/
block|}
name|FAIL_REASON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|font_value
comment|/*Repertoire Font Value*/
block|{
name|int
name|rep_type
decl_stmt|;
comment|/*1 = NULL; 2 = SEQUENCE....*/
name|char
modifier|*
name|rep_assign
decl_stmt|;
comment|/*0 value for pointer means not used*/
name|int
name|valid_font_cap
decl_stmt|;
name|int
name|capability
decl_stmt|;
name|int
name|num_fonts
decl_stmt|;
name|char
modifier|*
name|font_names
index|[
name|MAXFONTS
index|]
decl_stmt|;
block|}
name|FONT_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dimen_value
block|{
name|int
name|bound_type
decl_stmt|;
comment|/*0 for no bound, 1 for unbounded, 2 for 				  integer */
name|int
name|bound
decl_stmt|;
name|int
name|valid_addr
decl_stmt|;
name|int
name|addressing
decl_stmt|;
comment|/*NOT optional according to 9041*/
name|int
name|valid_abs
decl_stmt|;
name|int
name|absolute
decl_stmt|;
comment|/*Optional*/
name|int
name|window_type
decl_stmt|;
comment|/*0 for not used, 1 for unbounded, 2 for 				  integer */
name|int
name|window
decl_stmt|;
block|}
name|DIMEN_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rep_val_list
comment|/*Repertoire value list*/
block|{
name|int
name|valid_cap
decl_stmt|;
name|int
name|capability
decl_stmt|;
name|int
name|num_reps
decl_stmt|;
comment|/*Number of repertoires */
name|FONT_VALUE
name|repertoire
index|[
name|MAXREPS
index|]
decl_stmt|;
block|}
name|REP_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|emp_value
block|{
name|int
name|valid_cap
decl_stmt|;
name|int
name|capability
decl_stmt|;
name|int
name|num_emps
decl_stmt|;
name|char
modifier|*
name|emp_string
index|[
name|MAXEMPS
index|]
decl_stmt|;
block|}
name|EMP_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|color_value
block|{
name|int
name|valid_cap
decl_stmt|;
name|int
name|capability
decl_stmt|;
name|int
name|num_colors
decl_stmt|;
name|char
modifier|*
name|color_string
index|[
name|MAXCOLORS
index|]
decl_stmt|;
block|}
name|COLOR_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|cds_value
block|{
name|char
modifier|*
name|obj_name
decl_stmt|;
name|int
name|dimensions
decl_stmt|;
comment|/*0 if not valid*/
name|int
name|valid_x_dim
decl_stmt|;
name|DIMEN_VALUE
name|x_dim
decl_stmt|;
name|int
name|valid_y_dim
decl_stmt|;
name|DIMEN_VALUE
name|y_dim
decl_stmt|;
name|int
name|valid_z_dim
decl_stmt|;
name|DIMEN_VALUE
name|z_dim
decl_stmt|;
name|int
name|valid_erasure
decl_stmt|;
name|int
name|erasure
decl_stmt|;
name|int
name|valid_rep_list
decl_stmt|;
name|REP_VALUE
name|rep_value
decl_stmt|;
name|int
name|valid_emp_list
decl_stmt|;
name|EMP_VALUE
name|emp_value
decl_stmt|;
name|int
name|valid_fore_color
decl_stmt|;
name|COLOR_VALUE
name|fore_color_list
decl_stmt|;
name|int
name|valid_back_color
decl_stmt|;
name|COLOR_VALUE
name|back_color_list
decl_stmt|;
name|int
name|valid_access_right
decl_stmt|;
name|int
name|access_right
decl_stmt|;
block|}
name|CDS_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|css_value
comment|/*Unused in TELNET */
block|{
name|int
name|i
decl_stmt|;
comment|/*For compiler*/
block|}
name|CSS_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|dev_value
comment|/*Also unused*/
block|{
name|int
name|i
decl_stmt|;
comment|/*For compiler*/
block|}
name|DEV_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|special_value
block|{
name|int
name|param_num
decl_stmt|;
name|int
name|param_type
decl_stmt|;
comment|/*0,1,or2*/
union|union
block|{
name|int
name|bool_arg
decl_stmt|;
comment|/*Turns into bitstring = 0 or 1*/
name|int
name|int_arg
decl_stmt|;
name|char
modifier|*
name|string_arg
decl_stmt|;
block|}
name|args
union|;
block|}
name|SPECIAL_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|arg_val_list
block|{
name|int
name|num_sp_param
decl_stmt|;
comment|/*Number of special profile arguments*/
name|int
name|num_cds_objects
decl_stmt|;
comment|/*Number of Conceptual Data Store objects*/
name|int
name|num_css_objects
decl_stmt|;
comment|/*Number of Control Signal Status objects*/
name|int
name|num_dev_objects
decl_stmt|;
comment|/*Number of Device Object identifiers*/
name|SPECIAL_VALUE
name|sp_val
index|[
name|MAXSPARGS
index|]
decl_stmt|;
name|CDS_VALUE
name|cds_val
index|[
name|MAXCDSOBJ
index|]
decl_stmt|;
name|CSS_VALUE
name|css_val
index|[
name|MAXCSSOBJ
index|]
decl_stmt|;
name|DEV_VALUE
name|dev_val
index|[
name|MAXDEVOBJ
index|]
decl_stmt|;
name|int
name|del_ctrl
decl_stmt|;
comment|/*Delivery Control*/
block|}
name|ARG_VAL_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|asr_msg
block|{
name|int
name|valid_reason
decl_stmt|;
comment|/*1 if reason is supplied*/
name|FAIL_REASON
name|reason
decl_stmt|;
comment|/*Optional*/
name|int
name|result
decl_stmt|;
comment|/*0,1, or 2*/
name|int
name|valid_imp
decl_stmt|;
comment|/*1 if implementation i.d is supplied*/
name|IMPLEM_ID
name|imp_id
decl_stmt|;
comment|/*Optional*/
name|BIT_STR
name|version
decl_stmt|;
comment|/*Only '1'B now valid*/
name|int
name|valid_arg_list
decl_stmt|;
name|ARG_VAL_LIST
name|arg_list
decl_stmt|;
name|BIT_STR
name|func_units
decl_stmt|;
name|int
name|valid_coll
decl_stmt|;
comment|/*Is collision_winner valid?*/
name|int
name|coll_winner
decl_stmt|;
comment|/*Optional (0,1,2)*/
block|}
name|ASR_MSG
typedef|;
end_typedef

end_unit

