begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: phigs.h,v 5.10 91/08/23 17:16:47 hersh Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PHIGS_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|PHIGS_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xresource.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* #include<sys/types.h> Xlib.h does this */
end_comment

begin_include
include|#
directive|include
file|"attr.h"
end_include

begin_include
include|#
directive|include
file|"phigscfunc.h"
end_include

begin_include
include|#
directive|include
file|"phigsextrn.h"
end_include

begin_include
include|#
directive|include
file|"phigserr.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|min
end_ifdef

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|max
end_ifdef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|major
end_ifdef

begin_undef
undef|#
directive|undef
name|major
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|minor
end_ifdef

begin_undef
undef|#
directive|undef
name|minor
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FALSE
end_ifndef

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TRUE
end_ifndef

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|Pconnid
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|Pconnid
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
name|Display
modifier|*
name|display
decl_stmt|;
name|XID
name|drawable_id
decl_stmt|;
block|}
name|Pconnid_x_drawable
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|Pint
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|Plong
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
name|Pfloat
typedef|;
end_typedef

begin_if
if|#
directive|if
name|NeedFunctionPrototypes
end_if

begin_typedef
typedef|typedef
name|void
modifier|*
name|Pstore
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|Pstore
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|Pfloat
name|Pmatrix3
index|[
literal|4
index|]
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Pfloat
name|Pmatrix
index|[
literal|3
index|]
index|[
literal|3
index|]
typedef|;
end_typedef

begin_comment
comment|/* These are the base ws types */
end_comment

begin_decl_stmt
specifier|extern
name|Pint
name|phigs_ws_type_x_tool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Pint
name|phigs_ws_type_x_drawable
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
enum|enum
block|{
name|PWS_INDEP
block|,
name|PWS_DEP
block|}
name|Pws_dep_ind
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSYS_ST_PHCL
block|,
name|PSYS_ST_PHOP
block|}
name|Psys_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PWS_ST_WSCL
block|,
name|PWS_ST_WSOP
block|}
name|Pws_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSTRUCT_ST_STCL
block|,
name|PSTRUCT_ST_STOP
block|}
name|Pstruct_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSTRUCT_STATUS_NON_EXISTENT
block|,
name|PSTRUCT_STATUS_EMPTY
block|,
name|PSTRUCT_STATUS_NOT_EMPTY
block|}
name|Pstruct_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PST_ARCL
block|,
name|PST_AROP
block|}
name|Par_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCLASS_VEC
block|,
name|PCLASS_RASTER
block|,
name|PCLASS_OTHER
block|}
name|Pws_class
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCAT_OUT
block|,
name|PCAT_IN
block|,
name|PCAT_OUTIN
block|,
name|PCAT_MO
block|,
name|PCAT_MI
block|}
name|Pws_cat
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PFLAG_COND
block|,
name|PFLAG_ALWAYS
block|}
name|Pctrl_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PFLAG_POSTPONE
block|,
name|PFLAG_PERFORM
block|}
name|Pregen_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDEFER_ASAP
block|,
name|PDEFER_BNIG
block|,
name|PDEFER_BNIL
block|,
name|PDEFER_ASTI
block|,
name|PDEFER_WAIT
block|}
name|Pdefer_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDISTING_NO
block|,
name|PDISTING_YES
block|}
name|Pdisting_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCULL_NONE
block|,
name|PCULL_BACKFACE
block|,
name|PCULL_FRONTFACE
block|}
name|Pcull_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PMODE_NIVE
block|,
name|PMODE_UWOR
block|,
name|PMODE_UQUM
block|}
name|Pmod_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSIMULT_NO_MORE
block|,
name|PSIMULT_MORE
block|}
name|Pmore_simult_events
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PNET_CSS
block|,
name|PNET_AR
block|}
name|Pstruct_net_source
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSURF_NOT_EMPTY
block|,
name|PSURF_EMPTY
block|}
name|Pdisp_surf_empty
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PVISUAL_ST_CORRECT
block|,
name|PVISUAL_ST_DEFER
block|,
name|PVISUAL_ST_SIMULATED
block|}
name|Pvisual_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PPREC_STRING
block|,
name|PPREC_CHAR
block|,
name|PPREC_STROKE
block|}
name|Ptext_prec
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PPATH_RIGHT
block|,
name|PPATH_LEFT
block|,
name|PPATH_UP
block|,
name|PPATH_DOWN
block|}
name|Ptext_path
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHOR_NORM
block|,
name|PHOR_LEFT
block|,
name|PHOR_CTR
block|,
name|PHOR_RIGHT
block|}
name|Phor_text_align
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PVERT_NORM
block|,
name|PVERT_TOP
block|,
name|PVERT_CAP
block|,
name|PVERT_HALF
block|,
name|PVERT_BASE
block|,
name|PVERT_BOTTOM
block|}
name|Pvert_text_align
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSTYLE_HOLLOW
block|,
name|PSTYLE_SOLID
block|,
name|PSTYLE_PAT
block|,
name|PSTYLE_HATCH
block|,
name|PSTYLE_EMPTY
block|}
name|Pint_style
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PEDGE_OFF
block|,
name|PEDGE_ON
block|}
name|Pedge_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PASPECT_LINETYPE
block|,
name|PASPECT_LINEWIDTH
block|,
name|PASPECT_LINE_COLR_IND
block|,
name|PASPECT_MARKER_TYPE
block|,
name|PASPECT_MARKER_SIZE
block|,
name|PASPECT_MARKER_COLR_IND
block|,
name|PASPECT_TEXT_FONT
block|,
name|PASPECT_TEXT_PREC
block|,
name|PASPECT_CHAR_EXPAN
block|,
name|PASPECT_CHAR_SPACE
block|,
name|PASPECT_TEXT_COLR_IND
block|,
name|PASPECT_INT_STYLE
block|,
name|PASPECT_INT_STYLE_IND
block|,
name|PASPECT_INT_COLR_IND
block|,
name|PASPECT_EDGE_FLAG
block|,
name|PASPECT_EDGETYPE
block|,
name|PASPECT_EDGEWIDTH
block|,
name|PASPECT_EDGE_COLR_IND
block|,
name|PASPECT_LINE_SHAD_METH
block|,
name|PASPECT_INT_SHAD_METH
block|,
name|PASPECT_REFL_PROPS
block|,
name|PASPECT_INT_REFL_EQN
block|,
name|PASPECT_BACK_INT_STYLE
block|,
name|PASPECT_BACK_INT_STYLE_IND
block|,
name|PASPECT_BACK_INT_COLR
block|,
name|PASPECT_BACK_INT_SHAD_METH
block|,
name|PASPECT_BACK_REFL_PROPS
block|,
name|PASPECT_BACK_INT_REFL_EQN
block|,
name|PASPECT_CURVE_APPROX_CRIT
block|,
name|PASPECT_SURF_APPROX_CRIT
block|}
name|Paspect
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PASF_BUNDLED
block|,
name|PASF_INDIV
block|}
name|Pasf
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PAVAIL_MONOCHR
block|,
name|PAVAIL_COLR
block|}
name|Pcolr_avail
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PTYPE_PRECONCAT
block|,
name|PTYPE_POSTCONCAT
block|,
name|PTYPE_REPLACE
block|}
name|Pcompose_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PTYPE_PARAL
block|,
name|PTYPE_PERSPECT
block|}
name|Pproj_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PIND_NO_CLIP
block|,
name|PIND_CLIP
block|}
name|Pclip_ind
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PPRI_HIGHER
block|,
name|PPRI_LOWER
block|}
name|Prel_pri
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PRES_MAINTAIN
block|,
name|PRES_ABANDON
block|,
name|PRES_UPD
block|}
name|Pconf_res
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PFLAG_LINE
block|,
name|PFLAG_FILL
block|,
name|PFLAG_FILL_SET
block|}
name|Pline_fill_ctrl_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PORDER_TOP_FIRST
block|,
name|PORDER_BOTTOM_FIRST
block|}
name|Ppath_order
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|POP_REQ
block|,
name|POP_SAMPLE
block|,
name|POP_EVENT
block|}
name|Pop_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSWITCH_NO_ECHO
block|,
name|PSWITCH_ECHO
block|}
name|Pecho_switch
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PIN_STATUS_NONE
block|,
name|PIN_STATUS_OK
block|,
name|PIN_STATUS_NO_IN
block|}
name|Pin_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSTRUCT_NONE
block|,
name|PSTRUCT_OPEN
block|}
name|Popen_struct_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PIN_NONE
block|,
name|PIN_LOC
block|,
name|PIN_STROKE
block|,
name|PIN_VAL
block|,
name|PIN_CHOICE
block|,
name|PIN_PICK
block|,
name|PIN_STRING
block|}
name|Pin_class
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PPR_OFF
block|,
name|PPR_ON
block|}
name|Ppr_switch
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PINQ_SET
block|,
name|PINQ_REALIZED
block|}
name|Pinq_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PUPD_NOT_PEND
block|,
name|PUPD_PEND
block|}
name|Pupd_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDC_METRES
block|,
name|PDC_OTHER
block|}
name|Pdc_units
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDYN_IRG
block|,
name|PDYN_IMM
block|,
name|PDYN_CBS
block|}
name|Pdyn_mod
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PATTR_LINE
block|,
name|PATTR_MARKER
block|,
name|PATTR_TEXT
block|,
name|PATTR_INT
block|,
name|PATTR_EDGE
block|}
name|Pattrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PELEM_ALL
block|,
name|PELEM_NIL
block|,
name|PELEM_POLYLINE3
block|,
name|PELEM_POLYLINE
block|,
name|PELEM_POLYMARKER3
block|,
name|PELEM_POLYMARKER
block|,
name|PELEM_TEXT3
block|,
name|PELEM_TEXT
block|,
name|PELEM_ANNO_TEXT_REL3
block|,
name|PELEM_ANNO_TEXT_REL
block|,
name|PELEM_FILL_AREA3
block|,
name|PELEM_FILL_AREA
block|,
name|PELEM_FILL_AREA_SET3
block|,
name|PELEM_FILL_AREA_SET
block|,
name|PELEM_CELL_ARRAY3
block|,
name|PELEM_CELL_ARRAY
block|,
name|PELEM_GDP3
block|,
name|PELEM_GDP
block|,
name|PELEM_LINE_IND
block|,
name|PELEM_MARKER_IND
block|,
name|PELEM_TEXT_IND
block|,
name|PELEM_INT_IND
block|,
name|PELEM_EDGE_IND
block|,
name|PELEM_LINETYPE
block|,
name|PELEM_LINEWIDTH
block|,
name|PELEM_LINE_COLR_IND
block|,
name|PELEM_MARKER_TYPE
block|,
name|PELEM_MARKER_SIZE
block|,
name|PELEM_MARKER_COLR_IND
block|,
name|PELEM_TEXT_FONT
block|,
name|PELEM_TEXT_PREC
block|,
name|PELEM_CHAR_EXPAN
block|,
name|PELEM_CHAR_SPACE
block|,
name|PELEM_TEXT_COLR_IND
block|,
name|PELEM_CHAR_HT
block|,
name|PELEM_CHAR_UP_VEC
block|,
name|PELEM_TEXT_PATH
block|,
name|PELEM_TEXT_ALIGN
block|,
name|PELEM_ANNO_CHAR_HT
block|,
name|PELEM_ANNO_CHAR_UP_VEC
block|,
name|PELEM_ANNO_PATH
block|,
name|PELEM_ANNO_ALIGN
block|,
name|PELEM_ANNO_STYLE
block|,
name|PELEM_INT_STYLE
block|,
name|PELEM_INT_STYLE_IND
block|,
name|PELEM_INT_COLR_IND
block|,
name|PELEM_EDGE_FLAG
block|,
name|PELEM_EDGETYPE
block|,
name|PELEM_EDGEWIDTH
block|,
name|PELEM_EDGE_COLR_IND
block|,
name|PELEM_PAT_SIZE
block|,
name|PELEM_PAT_REF_POINT_VECS
block|,
name|PELEM_PAT_REF_POINT
block|,
name|PELEM_ADD_NAMES_SET
block|,
name|PELEM_REMOVE_NAMES_SET
block|,
name|PELEM_INDIV_ASF
block|,
name|PELEM_HLHSR_ID
block|,
name|PELEM_LOCAL_MODEL_TRAN3
block|,
name|PELEM_LOCAL_MODEL_TRAN
block|,
name|PELEM_GLOBAL_MODEL_TRAN3
block|,
name|PELEM_GLOBAL_MODEL_TRAN
block|,
name|PELEM_MODEL_CLIP_VOL3
block|,
name|PELEM_MODEL_CLIP_VOL
block|,
name|PELEM_MODEL_CLIP_IND
block|,
name|PELEM_RESTORE_MODEL_CLIP_VOL
block|,
name|PELEM_VIEW_IND
block|,
name|PELEM_EXEC_STRUCT
block|,
name|PELEM_LABEL
block|,
name|PELEM_APPL_DATA
block|,
name|PELEM_GSE
block|,
name|PELEM_PICK_ID
block|,
name|PELEM_POLYLINE_SET3_DATA
block|,
name|PELEM_FILL_AREA_SET3_DATA
block|,
name|PELEM_TRI_STRIP3_DATA
block|,
name|PELEM_QUAD_MESH3_DATA
block|,
name|PELEM_SET_OF_FILL_AREA_SET3_DATA
block|,
name|PELEM_NUNI_BSP_CURVE
block|,
name|PELEM_NUNI_BSP_SURF
block|,
name|PELEM_CELL_ARRAY3_PLUS
block|,
name|PELEM_TEXT_COLR
block|,
name|PELEM_MARKER_COLR
block|,
name|PELEM_EDGE_COLR
block|,
name|PELEM_LINE_COLR
block|,
name|PELEM_CURVE_APPROX_CRIT
block|,
name|PELEM_LINE_SHAD_METH
block|,
name|PELEM_INT_COLR
block|,
name|PELEM_BACK_INT_COLR
block|,
name|PELEM_BACK_INT_STYLE
block|,
name|PELEM_BACK_INT_STYLE_IND
block|,
name|PELEM_REFL_PROPS
block|,
name|PELEM_BACK_REFL_PROPS
block|,
name|PELEM_INT_SHAD_METH
block|,
name|PELEM_BACK_INT_SHAD_METH
block|,
name|PELEM_INT_REFL_EQN
block|,
name|PELEM_BACK_INT_REFL_EQN
block|,
name|PELEM_SURF_APPROX_CRIT
block|,
name|PELEM_PARA_SURF_CHARACS
block|,
name|PELEM_FACE_DISTING_MODE
block|,
name|PELEM_FACE_CULL_MODE
block|,
name|PELEM_LIGHT_SRC_STATE
block|,
name|PELEM_DCUE_IND
block|,
name|PELEM_COLR_MAP_IND
block|,
name|PELEM_RENDERING_COLR_MODEL
block|,
name|PELEM_NUM_EL_TYPES
block|}
name|Pelem_type
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PEDIT_INSERT
block|,
name|PEDIT_REPLACE
block|}
name|Pedit_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PFLAG_DEL
block|,
name|PFLAG_KEEP
block|}
name|Pref_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PERR_OFF
block|,
name|PERR_ON
block|}
name|Perr_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PDIR_BACKWARD
block|,
name|PDIR_FORWARD
block|}
name|Psearch_dir
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSEARCH_STATUS_FAILURE
block|,
name|PSEARCH_STATUS_SUCCESS
block|}
name|Psearch_status
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PNON_RATIONAL
init|=
literal|0
block|,
name|PRATIONAL
init|=
literal|1
block|}
name|Prational
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|size
decl_stmt|;
comment|/* sizeof data */
if|#
directive|if
name|NeedFunctionPrototypes
name|void
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data */
else|#
directive|else
name|char
modifier|*
name|data
decl_stmt|;
comment|/* pointer to data */
endif|#
directive|endif
block|}
name|Pdata
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|red
decl_stmt|;
comment|/* red, hue, etc */
name|Pfloat
name|green
decl_stmt|;
comment|/* green, saturation, lightness, etc */
name|Pfloat
name|blue
decl_stmt|;
comment|/* blue, value, saturation, etc */
block|}
name|Prgb
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|cieluv_x
decl_stmt|;
comment|/* x coefficient */
name|Pfloat
name|cieluv_y
decl_stmt|;
comment|/* y coefficient */
name|Pfloat
name|cieluv_y_lum
decl_stmt|;
comment|/* y luminance */
block|}
name|Pcieluv
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|hue
decl_stmt|;
comment|/* hue */
name|Pfloat
name|satur
decl_stmt|;
comment|/* saturation */
name|Pfloat
name|value
decl_stmt|;
comment|/* value */
block|}
name|Phsv
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|hue
decl_stmt|;
comment|/* hue */
name|Pfloat
name|lightness
decl_stmt|;
comment|/* lightness; */
name|Pfloat
name|satur
decl_stmt|;
comment|/* saturation */
block|}
name|Phls
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Prgb
name|rgb
decl_stmt|;
name|Pcieluv
name|cieluv
decl_stmt|;
name|Phls
name|hls
decl_stmt|;
name|Phsv
name|hsv
decl_stmt|;
name|Pdata
name|unsupp
decl_stmt|;
block|}
name|Pcolr_rep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|size_x
decl_stmt|;
name|Pint
name|size_y
decl_stmt|;
block|}
name|Pint_size
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|size_x
decl_stmt|;
name|Pint
name|size_y
decl_stmt|;
name|Pint
name|size_z
decl_stmt|;
block|}
name|Pint_size3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|size_x
decl_stmt|;
name|Pfloat
name|size_y
decl_stmt|;
block|}
name|Pfloat_size
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|size_x
decl_stmt|;
name|Pfloat
name|size_y
decl_stmt|;
name|Pfloat
name|size_z
decl_stmt|;
block|}
name|Pfloat_size3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_ints
decl_stmt|;
comment|/* number of Pints in list */
name|Pint
modifier|*
name|ints
decl_stmt|;
comment|/* list of integers        */
block|}
name|Pint_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_lists
decl_stmt|;
comment|/* number of Pintlists in list */
name|Pint_list
modifier|*
name|lists
decl_stmt|;
comment|/* list of integer lists */
block|}
name|Pint_list_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_floats
decl_stmt|;
comment|/* number of Pfloats in list */
name|Pfloat
modifier|*
name|floats
decl_stmt|;
comment|/* list of floats */
block|}
name|Pfloat_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_lists
decl_stmt|;
comment|/* number of lists in list */
name|Pfloat_list
modifier|*
name|lists
decl_stmt|;
comment|/* list of float lists */
block|}
name|Pfloat_list_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* GSE identifier */
name|Pws_dep_ind
name|ind
decl_stmt|;
comment|/* WS independent/dependent ind */
block|}
name|Pgse_id_dep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_id_facs
decl_stmt|;
comment|/* number of identifiers/dependency element */
name|Pgse_id_dep
modifier|*
name|id_facs
decl_stmt|;
comment|/* list */
block|}
name|Pgse_id_dep_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* archive file identifier */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* archive file name       */
block|}
name|Par_file
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_ar_files
decl_stmt|;
comment|/* number of archive files */
name|Par_file
modifier|*
name|ar_files
decl_stmt|;
comment|/* list of archive files */
block|}
name|Par_file_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|struct_id
decl_stmt|;
comment|/* structure identifier */
name|Pint
name|elem_pos
decl_stmt|;
comment|/* element number */
block|}
name|Pelem_ref
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_elem_refs
decl_stmt|;
comment|/* number of execute refs */
name|Pelem_ref
modifier|*
name|elem_refs
decl_stmt|;
comment|/* list of execute refs */
block|}
name|Pelem_ref_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_elem_ref_lists
decl_stmt|;
comment|/* number of execute refs */
name|Pelem_ref_list
modifier|*
name|elem_ref_lists
decl_stmt|;
comment|/* list of execute ref lists */
block|}
name|Pelem_ref_list_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|incl_set
decl_stmt|;
comment|/* inclusion set */
name|Pint_list
name|excl_set
decl_stmt|;
comment|/* exclusion set */
block|}
name|Pfilter
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_filters
decl_stmt|;
comment|/* number of filters */
name|Pfilter
modifier|*
name|filters
decl_stmt|;
comment|/* list of filters */
block|}
name|Pfilter_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* structure id */
name|Pfloat
name|disp_pri
decl_stmt|;
comment|/* structure disp_pri */
block|}
name|Pposted_struct
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_postings
decl_stmt|;
comment|/* number of structure postings */
name|Pposted_struct
modifier|*
name|postings
decl_stmt|;
comment|/* list of postings */
block|}
name|Pposted_struct_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_strings
decl_stmt|;
comment|/* number of strings */
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
comment|/* list of strings */
block|}
name|Pstring_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|x
decl_stmt|;
comment|/* x coordinate */
name|Pfloat
name|y
decl_stmt|;
comment|/* y coordinate */
block|}
name|Ppoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|x
decl_stmt|;
comment|/* x coordinate */
name|Pfloat
name|y
decl_stmt|;
comment|/* y coordinate */
name|Pfloat
name|z
decl_stmt|;
comment|/* z coordinate */
block|}
name|Ppoint3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|x
decl_stmt|;
comment|/* x coordinate */
name|Pfloat
name|y
decl_stmt|;
comment|/* y coordinate */
name|Pfloat
name|z
decl_stmt|;
comment|/* z coordinate */
name|Pfloat
name|w
decl_stmt|;
comment|/* w coordinate */
block|}
name|Ppoint4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|delta_x
decl_stmt|;
comment|/* x magnitude */
name|Pfloat
name|delta_y
decl_stmt|;
comment|/* y magnitude */
block|}
name|Pvec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|delta_x
decl_stmt|;
comment|/* x magnitude */
name|Pfloat
name|delta_y
decl_stmt|;
comment|/* y magnitude */
name|Pfloat
name|delta_z
decl_stmt|;
comment|/* z magnitude */
block|}
name|Pvec3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint
name|point
decl_stmt|;
comment|/* point */
name|Pvec
name|norm
decl_stmt|;
comment|/* normal */
block|}
name|Phalf_space
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint3
name|point
decl_stmt|;
comment|/* point */
name|Pvec3
name|norm
decl_stmt|;
comment|/* normal */
block|}
name|Phalf_space3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint
name|p
decl_stmt|;
comment|/* lower left */
name|Ppoint
name|q
decl_stmt|;
comment|/* upper right */
block|}
name|Prect
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint3
name|p
decl_stmt|;
comment|/* point p */
name|Ppoint3
name|q
decl_stmt|;
comment|/* point q */
name|Ppoint3
name|r
decl_stmt|;
comment|/* point r */
block|}
name|Pparal
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|x_min
decl_stmt|;
comment|/* x min */
name|Pfloat
name|x_max
decl_stmt|;
comment|/* x max */
name|Pfloat
name|y_min
decl_stmt|;
comment|/* y min */
name|Pfloat
name|y_max
decl_stmt|;
comment|/* y max */
name|Pfloat
name|z_min
decl_stmt|;
comment|/* z min */
name|Pfloat
name|z_max
decl_stmt|;
comment|/* z max */
block|}
name|Plimit3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|x_min
decl_stmt|;
comment|/* x min */
name|Pfloat
name|x_max
decl_stmt|;
comment|/* x max */
name|Pfloat
name|y_min
decl_stmt|;
comment|/* y min */
name|Pfloat
name|y_max
decl_stmt|;
comment|/* y max */
block|}
name|Plimit
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|u_dim
decl_stmt|;
comment|/* dimension (number of divisions) along U */
name|Pint
name|v_dim
decl_stmt|;
comment|/* dimension (number of divisions) along V */
block|}
name|Ppcs_dims
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_points
decl_stmt|;
comment|/* number of Ppoints in the list */
name|Ppoint
modifier|*
name|points
decl_stmt|;
comment|/* list of points */
block|}
name|Ppoint_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_points
decl_stmt|;
comment|/* number of Ppoint3s in the list */
name|Ppoint3
modifier|*
name|points
decl_stmt|;
comment|/* list of points */
block|}
name|Ppoint_list3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_points
decl_stmt|;
comment|/* number of Ppoint4s in the list */
name|Ppoint4
modifier|*
name|points
decl_stmt|;
comment|/* list of points */
block|}
name|Ppoint_list4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* list of 2D or 3D  points */
name|Pint
name|num_points
decl_stmt|;
comment|/* number of points */
union|union
block|{
name|Ppoint
modifier|*
name|point2d
decl_stmt|;
comment|/* array of 2D points */
name|Ppoint3
modifier|*
name|point3d
decl_stmt|;
comment|/* array of 3D points */
block|}
name|points
union|;
block|}
name|Ppoint_list23
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* list of 3D or 4D  points */
name|Pint
name|num_points
decl_stmt|;
union|union
block|{
name|Ppoint3
modifier|*
name|point3d
decl_stmt|;
comment|/* array of 3D points */
name|Ppoint4
modifier|*
name|point4d
decl_stmt|;
comment|/* array of 4D points */
block|}
name|points
union|;
block|}
name|Ppoint_list34
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* grid of 3D or 4D points, [u_dim][v_dim] */
name|Ppcs_dims
name|num_points
decl_stmt|;
comment|/* number of points in each dimension */
union|union
block|{
name|Ppoint3
modifier|*
name|point3d
decl_stmt|;
comment|/* array of 3D points */
name|Ppoint4
modifier|*
name|point4d
decl_stmt|;
comment|/* array of 4D points */
block|}
name|points
union|;
block|}
name|Ppoint_grid34
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* list of 2d point lists */
name|Pint
name|num_point_lists
decl_stmt|;
comment|/* number of point lists  */
name|Ppoint_list
modifier|*
name|point_lists
decl_stmt|;
comment|/* list of point lists    */
block|}
name|Ppoint_list_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* list of 3d point lists */
name|Pint
name|num_point_lists
decl_stmt|;
comment|/* number of point lists  */
name|Ppoint_list3
modifier|*
name|point_lists
decl_stmt|;
comment|/* list of point lists    */
block|}
name|Ppoint_list_list3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_half_spaces
decl_stmt|;
comment|/* number of half-spaces */
name|Phalf_space3
modifier|*
name|half_spaces
decl_stmt|;
comment|/* list of half-spaces */
block|}
name|Phalf_space_list3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_half_spaces
decl_stmt|;
comment|/* number of half spaces */
name|Phalf_space
modifier|*
name|half_spaces
decl_stmt|;
comment|/* list of half-spaces */
block|}
name|Phalf_space_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pedge_flag
name|visible
decl_stmt|;
comment|/* curve visibility flag */
name|Prational
name|rationality
decl_stmt|;
comment|/* rationality */
name|Pint
name|order
decl_stmt|;
comment|/* curve order */
name|Pint
name|approx_type
decl_stmt|;
comment|/* approximation type */
name|Pfloat
name|approx_val
decl_stmt|;
comment|/* approximation value */
name|Pfloat_list
name|knots
decl_stmt|;
comment|/* curve knot vector */
name|Pfloat
name|tmin
decl_stmt|,
name|tmax
decl_stmt|;
comment|/* curve parameter range */
name|Ppoint_list23
name|cpts
decl_stmt|;
comment|/* control points */
block|}
name|Ptrimcurve
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_curves
decl_stmt|;
comment|/* number of trim curve in list */
name|Ptrimcurve
modifier|*
name|curves
decl_stmt|;
comment|/* list of curves */
block|}
name|Ptrimcurve_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Phor_text_align
name|hor
decl_stmt|;
comment|/* horizontal component */
name|Pvert_text_align
name|vert
decl_stmt|;
comment|/* vertical component */
block|}
name|Ptext_align
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Pint
name|ind
decl_stmt|;
comment|/* index in workstation colour bundle table */
name|Pcolr_rep
name|direct
decl_stmt|;
comment|/* direct colour components */
block|}
name|Pcoval
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_colr_reps
decl_stmt|;
comment|/* number of colours */
name|Pcolr_rep
modifier|*
name|colr_reps
decl_stmt|;
comment|/* array of colours */
block|}
name|Pcolr_rep_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pcoval
name|colr
decl_stmt|;
comment|/* colour */
name|Pvec3
name|norm
decl_stmt|;
comment|/* normal */
block|}
name|Pconorm3
typedef|;
end_typedef

begin_comment
comment|/* colour and normal */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint3
name|point
decl_stmt|;
comment|/* point coordinates */
name|Pcoval
name|colr
decl_stmt|;
comment|/* colour */
block|}
name|Pptco3
typedef|;
end_typedef

begin_comment
comment|/* point with colour */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint3
name|point
decl_stmt|;
comment|/* point coordinates */
name|Pvec3
name|norm
decl_stmt|;
comment|/* normal */
block|}
name|Pptnorm3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Ppoint3
name|point
decl_stmt|;
comment|/* point coordinates */
name|Pcoval
name|colr
decl_stmt|;
comment|/* colour */
name|Pvec3
name|norm
decl_stmt|;
comment|/* normal */
block|}
name|Pptconorm3
typedef|;
end_typedef

begin_comment
comment|/* point with colour and normal */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|Ppoint3
modifier|*
name|points
decl_stmt|;
comment|/* point */
name|Pptco3
modifier|*
name|ptcolrs
decl_stmt|;
comment|/* point and color */
name|Pptnorm3
modifier|*
name|ptnorms
decl_stmt|;
comment|/* point and normal */
name|Pptconorm3
modifier|*
name|ptconorms
decl_stmt|;
comment|/* point, color and normal */
comment|/* implementation dependent data pointer */
block|}
name|Pfacet_vdata_arr3
typedef|;
end_typedef

begin_comment
comment|/* facet vertex data array */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_vertices
decl_stmt|;
comment|/* number of vertices */
name|Pfacet_vdata_arr3
name|vertex_data
decl_stmt|;
comment|/* array of facet vertex data */
block|}
name|Pfacet_vdata_list3
typedef|;
end_typedef

begin_comment
comment|/* facet vertex data list */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|Ppoint3
modifier|*
name|points
decl_stmt|;
comment|/* points */
name|Pptco3
modifier|*
name|ptcolrs
decl_stmt|;
comment|/* points& colours */
comment|/* implementation dependent data */
block|}
name|Pline_vdata_arr3
typedef|;
end_typedef

begin_comment
comment|/* line vertex data array */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_vertices
decl_stmt|;
comment|/* number of vertices */
name|Pline_vdata_arr3
name|vertex_data
decl_stmt|;
comment|/* array of line vertex data */
block|}
name|Pline_vdata_list3
typedef|;
end_typedef

begin_comment
comment|/* polyline vertex data */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|Pedge_flag
modifier|*
name|edges
decl_stmt|;
comment|/* edge flags */
comment|/* implementation dependent data */
block|}
name|Pedge_data_arr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_edges
decl_stmt|;
comment|/* number of edges */
name|Pedge_data_arr
name|edgedata
decl_stmt|;
comment|/* array of edge data */
block|}
name|Pedge_data_list
typedef|;
end_typedef

begin_comment
comment|/* edge data list */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_lists
decl_stmt|;
comment|/* number of edges */
name|Pedge_data_list
modifier|*
name|edgelist
decl_stmt|;
comment|/* list of edge data list */
block|}
name|Pedge_data_list_list
typedef|;
end_typedef

begin_comment
comment|/* edge data list list */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|Pcoval
name|colr
decl_stmt|;
comment|/* colour */
name|Pvec3
name|norm
decl_stmt|;
comment|/* normal */
name|Pconorm3
name|conorm
decl_stmt|;
comment|/* colour and normal */
comment|/* implementation dependent data pointer */
block|}
name|Pfacet_data3
typedef|;
end_typedef

begin_comment
comment|/* array of facet data */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|Pcoval
modifier|*
name|colrs
decl_stmt|;
comment|/* colour */
name|Pvec3
modifier|*
name|norms
decl_stmt|;
comment|/* normal */
name|Pconorm3
modifier|*
name|conorms
decl_stmt|;
comment|/* colour and normal */
comment|/* implementation dependent data pointer */
block|}
name|Pfacet_data_arr3
typedef|;
end_typedef

begin_comment
comment|/* array of facet data */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* indirect, RGB, CIE, HSV, HLS */
union|union
block|{
name|Pint
name|ind
decl_stmt|;
comment|/* index in workstation colour bundle table */
struct|struct
block|{
name|Pfloat
name|x
decl_stmt|;
comment|/* red, hue, etc */
name|Pfloat
name|y
decl_stmt|;
comment|/* green, saturation, lightness, etc */
name|Pfloat
name|z
decl_stmt|;
comment|/* blue, value, saturation, etc */
block|}
name|general
struct|;
block|}
name|val
union|;
block|}
name|Pgcolr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* line type */
name|Pfloat
name|width
decl_stmt|;
comment|/* linewidth scale factor */
name|Pint
name|colr_ind
decl_stmt|;
comment|/* colour index */
block|}
name|Pline_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* line type */
name|Pfloat
name|width
decl_stmt|;
comment|/* linewidth scale factor */
name|Pgcolr
name|colr
decl_stmt|;
comment|/* polyline colour */
name|Pint
name|shad_meth
decl_stmt|;
comment|/* polyline shading method */
name|Pint
name|approx_type
decl_stmt|;
comment|/* curve approximation criteria */
name|Pfloat
name|approx_val
decl_stmt|;
comment|/* curve approximation criteria */
block|}
name|Pline_bundle_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* marker type */
name|Pfloat
name|size
decl_stmt|;
comment|/* marker size scale factor */
name|Pint
name|colr_ind
decl_stmt|;
comment|/* colour index */
block|}
name|Pmarker_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* marker type */
name|Pfloat
name|size
decl_stmt|;
comment|/* marker size scale factor */
name|Pgcolr
name|colr
decl_stmt|;
comment|/* marker colour */
block|}
name|Pmarker_bundle_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|font
decl_stmt|;
comment|/* text font */
name|Ptext_prec
name|prec
decl_stmt|;
comment|/* text precision */
name|Pfloat
name|char_expan
decl_stmt|;
comment|/* character char_expansion factor */
name|Pfloat
name|char_space
decl_stmt|;
comment|/* character spacing */
name|Pint
name|colr_ind
decl_stmt|;
comment|/* text colour index */
block|}
name|Ptext_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|font
decl_stmt|;
comment|/* text font */
name|Ptext_prec
name|prec
decl_stmt|;
comment|/* text precision */
name|Pfloat
name|char_expan
decl_stmt|;
comment|/* character char_expansion factor */
name|Pfloat
name|char_space
decl_stmt|;
comment|/* character spacing */
name|Pgcolr
name|colr
decl_stmt|;
comment|/* text colour */
block|}
name|Ptext_bundle_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_style
name|style
decl_stmt|;
comment|/* interior style */
name|Pint
name|style_ind
decl_stmt|;
comment|/* interior style index */
name|Pint
name|colr_ind
decl_stmt|;
comment|/* interior colour index */
block|}
name|Pint_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|ambient_coef
decl_stmt|;
comment|/* ambient reflectance coefficient */
name|Pfloat
name|diffuse_coef
decl_stmt|;
comment|/* diffuse reflectance coefficient */
name|Pfloat
name|specular_coef
decl_stmt|;
comment|/* specular reflectance coefficient */
name|Pgcolr
name|specular_colr
decl_stmt|;
comment|/* specular colour */
name|Pfloat
name|specular_exp
decl_stmt|;
comment|/* specular exponent */
block|}
name|Prefl_props
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_style
name|style
decl_stmt|;
comment|/* interior style */
name|Pint
name|style_ind
decl_stmt|;
comment|/* interior style index */
name|Pgcolr
name|colr
decl_stmt|;
comment|/* interior colour */
name|Pint
name|refl_eqn
decl_stmt|;
comment|/* reflectance equation */
name|Pint
name|shad_meth
decl_stmt|;
comment|/* shading method */
name|Prefl_props
name|refl_props
decl_stmt|;
comment|/* reflectance properties */
name|Pint_style
name|back_style
decl_stmt|;
comment|/* interior style */
name|Pint
name|back_style_ind
decl_stmt|;
comment|/* interior style index */
name|Pgcolr
name|back_colr
decl_stmt|;
comment|/* interior colour */
name|Pint
name|back_refl_eqn
decl_stmt|;
comment|/* back reflectance equation */
name|Pint
name|back_shad_meth
decl_stmt|;
comment|/* back shading method */
name|Prefl_props
name|back_refl_props
decl_stmt|;
comment|/* back reflectance properties */
name|Pint
name|approx_type
decl_stmt|;
comment|/* approximation meth */
name|Pfloat
name|approx_val
index|[
literal|2
index|]
decl_stmt|;
comment|/* approximation values, u and v */
block|}
name|Pint_bundle_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pedge_flag
name|flag
decl_stmt|;
comment|/* edge flag */
name|Pint
name|type
decl_stmt|;
comment|/* edgetype */
name|Pfloat
name|width
decl_stmt|;
comment|/* edgewidth scale factor */
name|Pint
name|colr_ind
decl_stmt|;
comment|/* edge colour index */
block|}
name|Pedge_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pedge_flag
name|flag
decl_stmt|;
comment|/* edge flag */
name|Pint
name|type
decl_stmt|;
comment|/* edgetype */
name|Pfloat
name|width
decl_stmt|;
comment|/* edgewidth scale factor */
name|Pgcolr
name|colr
decl_stmt|;
comment|/* edge colour */
block|}
name|Pedge_bundle_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_size
name|dims
decl_stmt|;
comment|/* pattern's dimensions */
name|Pint
modifier|*
name|colr_array
decl_stmt|;
comment|/* colour index array */
block|}
name|Ppat_rep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_size
name|dims
decl_stmt|;
comment|/* pattern's dimensions */
name|Pint
name|type
decl_stmt|;
comment|/* colour type */
name|Pcoval
modifier|*
name|colr_array
decl_stmt|;
comment|/* array of colours */
block|}
name|Ppat_rep_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pmatrix3
name|ori_matrix
decl_stmt|;
comment|/* orientation matrix */
name|Pmatrix3
name|map_matrix
decl_stmt|;
comment|/* mapping matrix */
name|Plimit3
name|clip_limit
decl_stmt|;
comment|/* clipping limits */
name|Pclip_ind
name|xy_clip
decl_stmt|;
comment|/* X-Y clipping indicator */
name|Pclip_ind
name|back_clip
decl_stmt|;
comment|/* back clipping indicator */
name|Pclip_ind
name|front_clip
decl_stmt|;
comment|/* front clipping indicator */
block|}
name|Pview_rep3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pmatrix
name|ori_matrix
decl_stmt|;
comment|/* orientation matrix */
name|Pmatrix
name|map_matrix
decl_stmt|;
comment|/* mapping matrix */
name|Plimit
name|clip_limit
decl_stmt|;
comment|/* clipping limits */
name|Pclip_ind
name|xy_clip
decl_stmt|;
comment|/* X-Y clipping ind */
block|}
name|Pview_rep
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Plimit
name|win
decl_stmt|;
comment|/* window limits */
name|Plimit3
name|proj_vp
decl_stmt|;
comment|/* viewport limits */
name|Pproj_type
name|proj_type
decl_stmt|;
comment|/* projection type */
name|Ppoint3
name|proj_ref_point
decl_stmt|;
comment|/* projection reference point */
name|Pfloat
name|view_plane
decl_stmt|;
comment|/* view plane distance */
name|Pfloat
name|back_plane
decl_stmt|;
comment|/* back plane distance */
name|Pfloat
name|front_plane
decl_stmt|;
comment|/* front plane distance */
block|}
name|Pview_map3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Plimit
name|win
decl_stmt|;
comment|/* window limits */
name|Plimit
name|proj_vp
decl_stmt|;
comment|/* viewport limits */
block|}
name|Pview_map
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pasf
name|type_asf
decl_stmt|;
comment|/* line type asf */
name|Pasf
name|width_asf
decl_stmt|;
comment|/* line width asf */
name|Pasf
name|colr_ind_asf
decl_stmt|;
comment|/* line colour index asf */
name|Pint
name|ind
decl_stmt|;
comment|/* line index */
name|Pline_bundle
name|bundle
decl_stmt|;
comment|/* line bundle */
block|}
name|Pline_attrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pasf
name|style_asf
decl_stmt|;
comment|/* interior asf */
name|Pasf
name|style_ind_asf
decl_stmt|;
comment|/* interior style asf */
name|Pasf
name|colr_ind_asf
decl_stmt|;
comment|/* interior colour index asf */
name|Pint
name|ind
decl_stmt|;
comment|/* interior index */
name|Pint_bundle
name|bundle
decl_stmt|;
comment|/* interior bundle */
block|}
name|Pint_attrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pasf
name|flag_asf
decl_stmt|;
comment|/* edge flag asf */
name|Pasf
name|type_asf
decl_stmt|;
comment|/* edge type asf */
name|Pasf
name|width_asf
decl_stmt|;
comment|/* edge width asf */
name|Pasf
name|colr_ind_asf
decl_stmt|;
comment|/* edge colour index asf */
name|Pint
name|ind
decl_stmt|;
comment|/* edge index */
name|Pedge_bundle
name|bundle
decl_stmt|;
comment|/* edge bundle */
block|}
name|Pedge_attrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pasf
name|type_asf
decl_stmt|;
comment|/* marker type asf */
name|Pasf
name|size_asf
decl_stmt|;
comment|/* marker style asf */
name|Pasf
name|colr_ind_asf
decl_stmt|;
comment|/* marker colour index asf */
name|Pint
name|ind
decl_stmt|;
comment|/* marker index */
name|Pmarker_bundle
name|bundle
decl_stmt|;
comment|/* marker bundle */
block|}
name|Pmarker_attrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pgcolr
name|colr
decl_stmt|;
comment|/* light source colour */
block|}
name|Pamb_light_src_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pgcolr
name|colr
decl_stmt|;
comment|/* light source colour */
name|Pvec3
name|dir
decl_stmt|;
comment|/* light source direction */
block|}
name|Pdir_light_src_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pgcolr
name|colr
decl_stmt|;
comment|/* light source colour */
name|Ppoint3
name|pos
decl_stmt|;
comment|/* light source position */
name|Pfloat
name|coef
index|[
literal|2
index|]
decl_stmt|;
comment|/* attenuation coefficients */
block|}
name|Ppos_light_src_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pgcolr
name|colr
decl_stmt|;
comment|/* light source colour */
name|Ppoint3
name|pos
decl_stmt|;
comment|/* light source position */
name|Pvec3
name|dir
decl_stmt|;
comment|/* light source direction */
name|Pfloat
name|exp
decl_stmt|;
comment|/* concentration exponent */
name|Pfloat
name|coef
index|[
literal|2
index|]
decl_stmt|;
comment|/* attenuation coefficients */
name|Pfloat
name|angle
decl_stmt|;
comment|/* spread angle */
block|}
name|Pspot_light_src_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Pamb_light_src_rec
name|ambient
decl_stmt|;
name|Pdir_light_src_rec
name|directional
decl_stmt|;
name|Ppos_light_src_rec
name|positional
decl_stmt|;
name|Pspot_light_src_rec
name|spot
decl_stmt|;
block|}
name|Plight_src_rec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
comment|/* light source type */
name|Plight_src_rec
name|rec
decl_stmt|;
comment|/* light source data record */
block|}
name|Plight_src_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|types
decl_stmt|;
comment|/* types of light source supported */
name|Pint
name|max
decl_stmt|;
comment|/* max. no. of simultaneously active lights */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Plight_src_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|struct_id
decl_stmt|;
comment|/* structure identifier */
name|Pint
name|pick_id
decl_stmt|;
comment|/* hierarchical pick identifier */
name|Pint
name|elem_pos
decl_stmt|;
comment|/* element sequence number */
block|}
name|Ppick_path_elem
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|depth
decl_stmt|;
comment|/* pick path_list depth */
name|Ppick_path_elem
modifier|*
name|path_list
decl_stmt|;
comment|/* pick path */
block|}
name|Ppick_path
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdc_units
name|dc_units
decl_stmt|;
comment|/* device coordinate units */
name|Pfloat_size
name|size_dc
decl_stmt|;
comment|/* device size in coordinate units */
name|Pint_size
name|size_raster
decl_stmt|;
comment|/* device size in raster units */
block|}
name|Pdisp_space_size
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdc_units
name|dc_units
decl_stmt|;
comment|/* device coordinate units */
name|Pfloat_size3
name|size_dc
decl_stmt|;
comment|/* device volume in coordinate units */
name|Pint_size3
name|size_raster
decl_stmt|;
comment|/* device volume in raster units */
block|}
name|Pdisp_space_size3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdyn_mod
name|line_bundle
decl_stmt|;
comment|/* polyline representation */
name|Pdyn_mod
name|marker_bundle
decl_stmt|;
comment|/* polymarker representation */
name|Pdyn_mod
name|text_bundle
decl_stmt|;
comment|/* text representation */
name|Pdyn_mod
name|int_bundle
decl_stmt|;
comment|/* interior representation */
name|Pdyn_mod
name|edge_bundle
decl_stmt|;
comment|/* edge representation */
name|Pdyn_mod
name|pat_rep
decl_stmt|;
comment|/* pattern representation */
name|Pdyn_mod
name|colr_rep
decl_stmt|;
comment|/* colour representation */
name|Pdyn_mod
name|view_rep
decl_stmt|;
comment|/* view representation */
name|Pdyn_mod
name|ws_tran
decl_stmt|;
comment|/* workstation transform */
name|Pdyn_mod
name|highl_filter
decl_stmt|;
comment|/* highlight filter */
name|Pdyn_mod
name|invis_filter
decl_stmt|;
comment|/* invisibility filter */
name|Pdyn_mod
name|hlhsr_mode
decl_stmt|;
comment|/* HLHSR mode */
block|}
name|Pdyns_ws_attrs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdyn_mod
name|light_src_rep
decl_stmt|;
comment|/* light source representation */
name|Pdyn_mod
name|dcue_rep
decl_stmt|;
comment|/* depth cue representation */
name|Pdyn_mod
name|colr_map_rep
decl_stmt|;
comment|/* colour mapping representation */
block|}
name|Pdyns_ws_attrs_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|types
decl_stmt|;
comment|/* list of line types */
name|Pint
name|num_widths
decl_stmt|;
comment|/* number of available line widths */
name|Pfloat
name|nom_width
decl_stmt|;
comment|/* nominal line width */
name|Pfloat
name|min_width
decl_stmt|;
comment|/* min line width */
name|Pfloat
name|max_width
decl_stmt|;
comment|/* max line width */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Pline_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|types
decl_stmt|;
comment|/* list of line types */
name|Pint
name|num_widths
decl_stmt|;
comment|/* number of available line widths */
name|Pfloat
name|nom_width
decl_stmt|;
comment|/* nominal line width */
name|Pfloat
name|min_width
decl_stmt|;
comment|/* min line width */
name|Pfloat
name|max_width
decl_stmt|;
comment|/* max line width */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
name|Pint_list
name|shads
decl_stmt|;
comment|/* list of shad_meth meths */
block|}
name|Pline_facs_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|types
decl_stmt|;
comment|/* list of marker types */
name|Pint
name|num_sizes
decl_stmt|;
comment|/* number of available marker sizes */
name|Pfloat
name|nom_size
decl_stmt|;
comment|/* nominal marker size */
name|Pfloat
name|min_size
decl_stmt|;
comment|/* min marker size */
name|Pfloat
name|max_size
decl_stmt|;
comment|/* max marker size */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Pmarker_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|font
decl_stmt|;
comment|/* text font */
name|Ptext_prec
name|prec
decl_stmt|;
comment|/* text precision */
block|}
name|Ptext_font_prec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_font_precs
decl_stmt|;
comment|/* number of fonts and precisions */
name|Ptext_font_prec
modifier|*
name|font_precs
decl_stmt|;
comment|/* list of fonts and precisions */
name|Pint
name|num_char_hts
decl_stmt|;
comment|/* number of character heights */
name|Pfloat
name|min_char_ht
decl_stmt|;
comment|/* minimum height */
name|Pfloat
name|max_char_ht
decl_stmt|;
comment|/* maximum height */
name|Pint
name|num_char_expans
decl_stmt|;
comment|/* number of character expansion factors */
name|Pfloat
name|min_char_expan
decl_stmt|;
comment|/* minimum expansion factor */
name|Pfloat
name|max_char_expan
decl_stmt|;
comment|/* maximum expansion factor */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Ptext_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_int_styles
decl_stmt|;
comment|/* number of interior styles */
name|Pint_style
name|int_styles
index|[
literal|5
index|]
decl_stmt|;
comment|/* list of available interior styles */
name|Pint_list
name|hatch_styles
decl_stmt|;
comment|/* list of available hatch styles */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Pint_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_int_styles
decl_stmt|;
comment|/* number of interior styles */
name|Pint_style
modifier|*
name|int_styles
decl_stmt|;
comment|/* list of available interior styles */
name|Pint_list
name|hatch_styles
decl_stmt|;
comment|/* list of available hatch styles */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined interior indices */
name|Pint_list
name|refl_eqns
decl_stmt|;
comment|/* list of available reflectance equations */
name|Pint_list
name|shad_meths
decl_stmt|;
comment|/* list of available shading methods */
block|}
name|Pint_facs_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|max_bsp_order
decl_stmt|;
comment|/* maximum B-spline order */
name|Pint
name|max_tc_order
decl_stmt|;
comment|/* maximum trim curve order */
name|Pint_list
name|cat_types
decl_stmt|;
comment|/* list of curve approx types */
name|Pint_list
name|sat_types
decl_stmt|;
comment|/* list of surface approx types */
name|Pint_list
name|tcat_types
decl_stmt|;
comment|/* list of trim curve approx types */
name|Pint_list
name|psc_types
decl_stmt|;
comment|/* list of parametric surface 				    characteristics */
block|}
name|Pcurvsurf_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PCP_UNIFORM
block|,
name|PCP_NON_UNIFORM
block|}
name|Pcurve_placement
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|psc_1
struct|;
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|psc_2
struct|;
struct|struct
block|{
name|Pcurve_placement
name|placement
decl_stmt|;
name|Pint
name|u_count
decl_stmt|;
name|Pint
name|v_count
decl_stmt|;
block|}
name|psc_3
struct|;
struct|struct
block|{
name|Ppoint3
name|origin
decl_stmt|;
name|Pvec3
name|direction
decl_stmt|;
name|Pfloat_list
name|params
decl_stmt|;
block|}
name|psc_4
struct|;
struct|struct
block|{
name|Ppoint3
name|origin
decl_stmt|;
name|Pvec3
name|direction
decl_stmt|;
name|Pfloat_list
name|params
decl_stmt|;
block|}
name|psc_5
struct|;
block|}
name|Ppara_surf_characs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|types
decl_stmt|;
comment|/* list of edge types */
name|Pint
name|num_widths
decl_stmt|;
comment|/* number of available edge widths */
name|Pfloat
name|nom_width
decl_stmt|;
comment|/* nominal edge width */
name|Pfloat
name|min_width
decl_stmt|;
comment|/* min edge width */
name|Pfloat
name|max_width
decl_stmt|;
comment|/* max edge width */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
block|}
name|Pedge_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_colrs
decl_stmt|;
comment|/* number of colours */
name|Pcolr_avail
name|colr_avail
decl_stmt|;
comment|/* colour availability */
name|Pint
name|num_pred_inds
decl_stmt|;
comment|/* number of predefined bundles */
name|Pcieluv
name|prim_colrs
index|[
literal|3
index|]
decl_stmt|;
comment|/* primary colours */
block|}
name|Pcolr_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PSUPPRESSED
block|,
name|PALLOWED
block|}
name|Pdcue_mode
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdcue_mode
name|mode
decl_stmt|;
comment|/* depth cue mode */
name|Pfloat
name|ref_planes
index|[
literal|2
index|]
decl_stmt|;
comment|/* depth cue ref planes */
name|Pfloat
name|scaling
index|[
literal|2
index|]
decl_stmt|;
comment|/* depth cue scaling*/
name|Pgcolr
name|colr
decl_stmt|;
comment|/* depth cue colour */
block|}
name|Pdcue_bundle
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
comment|/* method 1 has no data associated with it */
struct|struct
block|{
name|Pint
name|colr_model
decl_stmt|;
name|Pfloat_list
name|weights
decl_stmt|;
name|Pcolr_rep_list
name|colrs
decl_stmt|;
block|}
name|meth_r2
struct|;
struct|struct
block|{
name|Pint
name|colr_model
decl_stmt|;
name|Pfloat_list_list
name|colr_lists
decl_stmt|;
block|}
name|meth_r3
struct|;
block|}
name|Pcolr_map_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint_list
name|meths
decl_stmt|;
name|Pint
name|num_pred_inds
decl_stmt|;
block|}
name|Pcolr_map_facs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|int_data
decl_stmt|;
comment|/* for map methods 1 and 2 */
block|}
name|Pcolr_map_st
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_attrs
decl_stmt|;
comment|/* number of attributes in list */
name|Pattrs
modifier|*
name|attrs
decl_stmt|;
comment|/* list of attributes           */
block|}
name|Pattrs_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|line_bundles
decl_stmt|;
comment|/* polyline tables */
name|Pint
name|mark_bundles
decl_stmt|;
comment|/* polymarker tables */
name|Pint
name|text_bundles
decl_stmt|;
comment|/* text tables */
name|Pint
name|int_bundles
decl_stmt|;
comment|/* interior tables */
name|Pint
name|edge_bundles
decl_stmt|;
comment|/* edge tables */
name|Pint
name|pat_reps
decl_stmt|;
comment|/* pattern tables */
name|Pint
name|colr_reps
decl_stmt|;
comment|/* colour tables */
name|Pint
name|view_reps
decl_stmt|;
comment|/* view tables */
block|}
name|Pws_st_tables
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|line_bundles
decl_stmt|;
comment|/* polyline tables */
name|Pint
name|mark_bundles
decl_stmt|;
comment|/* polymarker tables */
name|Pint
name|text_bundles
decl_stmt|;
comment|/* text tables */
name|Pint
name|int_bundles
decl_stmt|;
comment|/* interior tables */
name|Pint
name|edge_bundles
decl_stmt|;
comment|/* edge tables */
name|Pint
name|pat_reps
decl_stmt|;
comment|/* pattern tables */
name|Pint
name|colr_reps
decl_stmt|;
comment|/* colour tables */
name|Pint
name|view_reps
decl_stmt|;
comment|/* view tables */
name|Pint
name|dcue_rep
decl_stmt|;
comment|/* depth cue tables */
name|Pint
name|light_src_rep
decl_stmt|;
comment|/* light source tables */
name|Pint
name|colr_map_rep
decl_stmt|;
comment|/* colour mapping tables */
block|}
name|Pws_tables_plus
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pdyn_mod
name|content
decl_stmt|;
comment|/* structure content */
name|Pdyn_mod
name|post
decl_stmt|;
comment|/* post structure  */
name|Pdyn_mod
name|unpost
decl_stmt|;
comment|/* unpost structure  */
name|Pdyn_mod
name|del
decl_stmt|;
comment|/* del structure  */
name|Pdyn_mod
name|ref
decl_stmt|;
comment|/* structure references  */
block|}
name|Pdyns_structs
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|loc
decl_stmt|;
comment|/* locators */
name|Pint
name|stroke
decl_stmt|;
comment|/* strokes */
name|Pint
name|val
decl_stmt|;
comment|/* valuators */
name|Pint
name|choice
decl_stmt|;
comment|/* choices */
name|Pint
name|pick
decl_stmt|;
comment|/* picks */
name|Pint
name|string
decl_stmt|;
comment|/* strings */
block|}
name|Pnum_in
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|num_elem_types
decl_stmt|;
comment|/* number of elements */
name|Pelem_type
modifier|*
name|elem_types
decl_stmt|;
comment|/* list of elements */
block|}
name|Pelem_type_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Pdata
name|unsupp
decl_stmt|;
comment|/* unsupp Metafile item data */
block|}
name|Pitem_data
typedef|;
end_typedef

begin_comment
comment|/* Plocator_data -- locator data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r2
struct|;
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r3
struct|;
struct|struct
block|{
name|Pline_attrs
name|line_attrs
decl_stmt|;
comment|/* polyline attributes */
block|}
name|pet_r4
struct|;
struct|struct
block|{
name|Pline_fill_ctrl_flag
name|line_fill_ctrl_flag
decl_stmt|;
union|union
block|{
name|Pline_attrs
name|line_attrs
decl_stmt|;
comment|/* polyline attributes */
name|Pint_attrs
name|int_attrs
decl_stmt|;
comment|/* interior attributes */
struct|struct
block|{
name|Pint_attrs
name|int_attrs
decl_stmt|;
comment|/* interior attributes */
name|Pedge_attrs
name|edge_attrs
decl_stmt|;
comment|/* edge attributes */
block|}
name|fill_set
struct|;
block|}
name|attrs
union|;
block|}
name|pet_r5
struct|;
block|}
name|pets
union|;
block|}
name|Ploc_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Ploc_data
name|Ploc_data3
typedef|;
end_typedef

begin_comment
comment|/* Pvaluator_data -- valuator data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pfloat
name|low
decl_stmt|;
comment|/* low range limit */
name|Pfloat
name|high
decl_stmt|;
comment|/* high range limit */
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
struct|struct
block|{
name|char
modifier|*
name|label
decl_stmt|;
name|char
modifier|*
name|format
decl_stmt|;
name|char
modifier|*
name|low_label
decl_stmt|;
name|char
modifier|*
name|high_label
decl_stmt|;
block|}
name|pet_u1
struct|;
block|}
name|pets
union|;
block|}
name|Pval_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Pval_data
name|Pval_data3
typedef|;
end_typedef

begin_comment
comment|/* Pchoice_data -- choice data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
struct|struct
block|{
name|Pint
name|num_prompts
decl_stmt|;
comment|/* number of alternatives	*/
name|Ppr_switch
modifier|*
name|prompts
decl_stmt|;
comment|/* array of prompts		*/
block|}
name|pet_r2
struct|;
struct|struct
block|{
name|Pint
name|num_strings
decl_stmt|;
comment|/* number of choice strings	*/
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
comment|/* array of choice strings	*/
block|}
name|pet_r3
struct|;
struct|struct
block|{
name|Pint
name|num_strings
decl_stmt|;
comment|/* number of alternatives	*/
name|char
modifier|*
modifier|*
name|strings
decl_stmt|;
comment|/* array of strings		*/
block|}
name|pet_r4
struct|;
struct|struct
block|{
name|Pint
name|struct_id
decl_stmt|;
comment|/* struct identifier		*/
name|Pint
name|num_pick_ids
decl_stmt|;
comment|/* number of alternatives	*/
name|Pint
modifier|*
name|pick_ids
decl_stmt|;
comment|/* array of pick identifiers	*/
block|}
name|pet_r5
struct|;
block|}
name|pets
union|;
block|}
name|Pchoice_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Pchoice_data
name|Pchoice_data3
typedef|;
end_typedef

begin_comment
comment|/* Ppick_data -- pick data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
block|}
name|pets
union|;
block|}
name|Ppick_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Ppick_data
name|Ppick_data3
typedef|;
end_typedef

begin_comment
comment|/* Pstroke_data -- stroke data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|buffer_size
decl_stmt|;
comment|/* input buffer size */
name|Pint
name|init_pos
decl_stmt|;
comment|/* initial editing position		*/
name|Pfloat
name|x_interval
decl_stmt|;
comment|/* x interval				*/
name|Pfloat
name|y_interval
decl_stmt|;
comment|/* y interval				*/
name|Pfloat
name|time_interval
decl_stmt|;
comment|/* time interval			*/
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r2
struct|;
struct|struct
block|{
name|Pmarker_attrs
name|marker_attrs
decl_stmt|;
comment|/* marker attributes */
block|}
name|pet_r3
struct|;
struct|struct
block|{
name|Pline_attrs
name|line_attrs
decl_stmt|;
comment|/* line attributes */
block|}
name|pet_r4
struct|;
block|}
name|pets
union|;
block|}
name|Pstroke_data
typedef|;
end_typedef

begin_comment
comment|/* Pstroke_data3 -- stroke data record 3 */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|buffer_size
decl_stmt|;
comment|/* input buffer size */
name|Pint
name|init_pos
decl_stmt|;
comment|/* initial editing position	*/
name|Pfloat
name|x_interval
decl_stmt|;
comment|/* x interval			*/
name|Pfloat
name|y_interval
decl_stmt|;
comment|/* y interval			*/
name|Pfloat
name|z_interval
decl_stmt|;
comment|/* z interval			*/
name|Pfloat
name|time_interval
decl_stmt|;
comment|/* time interval		*/
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r2
struct|;
struct|struct
block|{
name|Pmarker_attrs
name|marker_attrs
decl_stmt|;
comment|/* marker attributes */
block|}
name|pet_r3
struct|;
struct|struct
block|{
name|Pline_attrs
name|line_attrs
decl_stmt|;
comment|/* marker attributes */
block|}
name|pet_r4
struct|;
block|}
name|pets
union|;
block|}
name|Pstroke_data3
typedef|;
end_typedef

begin_comment
comment|/* Pstring_data -- string data record */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Pint
name|buffer_size
decl_stmt|;
comment|/* input buffer size		*/
name|Pint
name|init_pos
decl_stmt|;
comment|/* initial editing position	*/
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|pet_r1
struct|;
block|}
name|pets
union|;
block|}
name|Pstring_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|Pstring_data
name|Pstring_data3
typedef|;
end_typedef

begin_comment
comment|/* Pgdp_data -- gdp data record */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|gdp_r1
struct|;
name|Pdata
name|unsupp
decl_stmt|;
comment|/* unsupp GDP data record	*/
comment|/* implementation dependent     */
block|}
name|Pgdp_data
typedef|;
end_typedef

begin_comment
comment|/* Pgdp_data3 -- gdp data record 3 */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|gdp3_r1
struct|;
name|Pdata
name|unsupp
decl_stmt|;
comment|/* nusupported GDP data record	*/
comment|/* implementation dependent     */
block|}
name|Pgdp_data3
typedef|;
end_typedef

begin_comment
comment|/* Pgse_data -- gse data record */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Pint
name|unused
decl_stmt|;
block|}
name|gse_r1
struct|;
name|Pdata
name|unsupp
decl_stmt|;
comment|/* unsupp GSE data record	*/
comment|/* implementation dependent     */
block|}
name|Pgse_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PERRSYNC_OFF
init|=
literal|0
block|,
name|PERRSYNC_ON
init|=
literal|1
block|}
name|Perrsync
typedef|;
end_typedef

begin_comment
comment|/* Pescape_in_data -- escape in data record */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Perrsync
name|sync_on
decl_stmt|;
block|}
name|escape_in_u1
struct|;
struct|struct
block|{
name|Pint
name|ws_id
decl_stmt|;
block|}
name|escape_in_u2
struct|;
struct|struct
block|{
name|Pint
name|ignore_DC_errors
decl_stmt|;
comment|/* ignore errors if non-zero */
block|}
name|escape_in_u3
struct|;
struct|struct
block|{
name|Pint
name|ws_id
decl_stmt|;
name|Ppoint
name|point
decl_stmt|;
comment|/* a drawable point -- not DC */
name|Pfloat
name|ap_size
decl_stmt|;
comment|/* aperture size, DC length */
name|Ppath_order
name|order
decl_stmt|;
name|Pint
name|depth
decl_stmt|;
comment|/* depth of path to return */
name|Pint
name|pet
decl_stmt|;
name|Pecho_switch
name|echo_switch
decl_stmt|;
name|Plimit3
name|echo_volume
decl_stmt|;
name|Pfilter
name|filter
decl_stmt|;
comment|/* detectibility filter */
block|}
name|escape_in_u4
struct|;
comment|/* drawable point to pick */
struct|struct
block|{
name|Pint
name|ws_id
decl_stmt|;
name|Ppoint_list3
name|points
decl_stmt|;
comment|/* x,y are drawable coords, z is DC*/
block|}
name|escape_in_u5
struct|;
comment|/* drawable points to WC */
struct|struct
block|{
name|Pint
name|ws_id
decl_stmt|;
name|Pint
name|num_regions
decl_stmt|;
name|XRectangle
modifier|*
name|regions
decl_stmt|;
block|}
name|escape_in_u6
struct|;
comment|/* redraw regions */
struct|struct
block|{
name|Pint
name|ws_id
decl_stmt|;
block|}
name|escape_in_u7
struct|;
comment|/* ws synch */
block|}
name|Pescape_in_data
typedef|;
end_typedef

begin_comment
comment|/* Pescape_out_data -- escape out data record */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|Pint
name|err_ind
decl_stmt|;
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* may be returned as NULL */
name|XID
name|drawable_id
decl_stmt|;
name|XID
name|input_overlay_id
decl_stmt|;
comment|/* will be 0 if category not OUTIN */
name|char
modifier|*
name|display_name
decl_stmt|;
block|}
name|escape_out_u2
struct|;
struct|struct
block|{
name|Pin_status
name|status
decl_stmt|;
name|Ppick_path
name|pick
decl_stmt|;
block|}
name|escape_out_u4
struct|;
struct|struct
block|{
name|Pint
name|view_index
decl_stmt|;
name|Ppoint_list3
name|points
decl_stmt|;
block|}
name|escape_out_u5
struct|;
block|}
name|Pescape_out_data
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|Pint
name|int_data
decl_stmt|;
comment|/* integer valued data */
name|Pfloat
name|float_data
decl_stmt|;
comment|/* float valued data */
name|Ppoint_list3
name|point_list3
decl_stmt|;
comment|/* list of 3d points */
name|Ppoint_list
name|point_list
decl_stmt|;
comment|/* list of 2d points */
name|Ppoint_list_list3
name|point_list_list3
decl_stmt|;
comment|/* list of 3d point lists */
name|Ppoint_list_list
name|point_list_list
decl_stmt|;
comment|/* list of 2d point lists */
struct|struct
block|{
name|Ppoint3
name|pos
decl_stmt|;
comment|/* text pt */
name|Pvec3
name|dir
index|[
literal|2
index|]
decl_stmt|;
comment|/* direction vectors */
name|char
modifier|*
name|char_string
decl_stmt|;
comment|/* text string */
block|}
name|text3
struct|;
struct|struct
block|{
name|Ppoint
name|pos
decl_stmt|;
comment|/* text pt */
name|char
modifier|*
name|char_string
decl_stmt|;
comment|/* text string */
block|}
name|text
struct|;
struct|struct
block|{
name|Ppoint3
name|ref_point
decl_stmt|;
comment|/* reference pt */
name|Pvec3
name|offset
decl_stmt|;
comment|/* anno. pt/offset */
name|char
modifier|*
name|char_string
decl_stmt|;
comment|/* text string */
block|}
name|anno_text_rel3
struct|;
struct|struct
block|{
name|Ppoint
name|ref_point
decl_stmt|;
comment|/* reference pt */
name|Pvec
name|offset
decl_stmt|;
comment|/* anno. pt/offset */
name|char
modifier|*
name|char_string
decl_stmt|;
comment|/* text string */
block|}
name|anno_text_rel
struct|;
struct|struct
block|{
name|Pparal
name|paral
decl_stmt|;
comment|/* parallelogram */
name|Ppat_rep
name|colr_array
decl_stmt|;
comment|/* colour array */
block|}
name|cell_array3
struct|;
struct|struct
block|{
name|Prect
name|rect
decl_stmt|;
comment|/* rectangle */
name|Ppat_rep
name|colr_array
decl_stmt|;
comment|/* colour array */
block|}
name|cell_array
struct|;
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* GDP3 id */
name|Ppoint_list3
name|point_list
decl_stmt|;
comment|/* pts */
name|Pgdp_data3
name|data
decl_stmt|;
comment|/* data record */
block|}
name|gdp3
struct|;
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* GDP id */
name|Ppoint_list
name|point_list
decl_stmt|;
comment|/* pts */
name|Pgdp_data
name|data
decl_stmt|;
comment|/* data record */
block|}
name|gdp
struct|;
name|Ptext_prec
name|text_prec
decl_stmt|;
comment|/* text precision */
name|Pvec
name|char_up_vec
decl_stmt|;
comment|/* char up vector */
name|Ptext_path
name|text_path
decl_stmt|;
comment|/* text path */
name|Ptext_align
name|text_align
decl_stmt|;
comment|/* text alignment */
name|Pint_style
name|int_style
decl_stmt|;
comment|/* interior style */
name|Pedge_flag
name|edge_flag
decl_stmt|;
comment|/* edge flag */
name|Ppoint
name|pat_ref_point
decl_stmt|;
comment|/* pat ref pt */
name|Pfloat_size
name|pat_size
decl_stmt|;
comment|/* pattern size */
struct|struct
block|{
name|Ppoint3
name|ref_point
decl_stmt|;
comment|/* pattern ref. pt */
name|Pvec3
name|ref_vec
index|[
literal|2
index|]
decl_stmt|;
comment|/* vectors */
block|}
name|pat_ref_point_vecs
struct|;
name|Pint_list
name|names
decl_stmt|;
comment|/* name sets */
struct|struct
block|{
name|Paspect
name|id
decl_stmt|;
comment|/* attribute id */
name|Pasf
name|source
decl_stmt|;
comment|/* asf */
block|}
name|asf
struct|;
struct|struct
block|{
name|Pcompose_type
name|compose_type
decl_stmt|;
comment|/* composition type */
name|Pmatrix3
name|matrix
decl_stmt|;
comment|/* transformation matrix */
block|}
name|local_tran3
struct|;
struct|struct
block|{
name|Pcompose_type
name|compose_type
decl_stmt|;
comment|/* composition type */
name|Pmatrix
name|matrix
decl_stmt|;
comment|/* transformation matrix */
block|}
name|local_tran
struct|;
name|Pmatrix3
name|global_tran3
decl_stmt|;
comment|/* global transform3 */
name|Pmatrix
name|global_tran
decl_stmt|;
comment|/* global transform */
struct|struct
block|{
name|Pint
name|op
decl_stmt|;
comment|/* operator */
name|Phalf_space_list3
name|half_spaces
decl_stmt|;
comment|/* half-space list */
block|}
name|model_clip3
struct|;
struct|struct
block|{
name|Pint
name|op
decl_stmt|;
comment|/* operator */
name|Phalf_space_list
name|half_spaces
decl_stmt|;
comment|/* half-space list */
block|}
name|model_clip
struct|;
name|Pclip_ind
name|clip_ind
decl_stmt|;
comment|/* clipping indicator */
name|Pdata
name|appl_data
decl_stmt|;
comment|/* application data */
struct|struct
block|{
name|Pint
name|id
decl_stmt|;
comment|/* GSE id */
name|Pgse_data
name|data
decl_stmt|;
comment|/* GSE data record */
block|}
name|gse
struct|;
comment|/* PHIGS PLUS structure elements */
struct|struct
block|{
name|Pint
name|order
decl_stmt|;
name|Pfloat_list
name|knots
decl_stmt|;
name|Prational
name|rationality
decl_stmt|;
name|Ppoint_list34
name|cpts
decl_stmt|;
name|Pfloat
name|min
decl_stmt|;
name|Pfloat
name|max
decl_stmt|;
block|}
name|nurb_curve
struct|;
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
name|Pfloat
name|value
decl_stmt|;
block|}
name|curv_approx
struct|;
struct|struct
block|{
name|Pint
name|u_order
decl_stmt|;
name|Pint
name|v_order
decl_stmt|;
name|Prational
name|rationality
decl_stmt|;
name|Pfloat_list
name|uknots
decl_stmt|;
name|Pfloat_list
name|vknots
decl_stmt|;
name|Ppoint_grid34
name|grid
decl_stmt|;
name|Pint
name|num_trim_loops
decl_stmt|;
name|Ptrimcurve_list
modifier|*
name|trim_loops
decl_stmt|;
block|}
name|nurb_surf
struct|;
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
name|Pfloat
name|u_val
decl_stmt|;
name|Pfloat
name|v_val
decl_stmt|;
block|}
name|surf_approx
struct|;
struct|struct
block|{
name|Pint
name|vflag
decl_stmt|;
name|Pint
name|colr_model
decl_stmt|;
name|Pint
name|npl
decl_stmt|;
name|Pline_vdata_list3
modifier|*
name|vdata
decl_stmt|;
block|}
name|plsd3
struct|;
struct|struct
block|{
name|Pint
name|fflag
decl_stmt|;
name|Pint
name|eflag
decl_stmt|;
name|Pint
name|vflag
decl_stmt|;
name|Pint
name|colr_model
decl_stmt|;
name|Pfacet_data3
name|fdata
decl_stmt|;
name|Pint
name|nfa
decl_stmt|;
name|Pedge_data_list
modifier|*
name|edata
decl_stmt|;
name|Pfacet_vdata_list3
modifier|*
name|vdata
decl_stmt|;
block|}
name|fasd3
struct|;
struct|struct
block|{
name|Pint
name|fflag
decl_stmt|;
name|Pint
name|vflag
decl_stmt|;
name|Pint
name|colr_model
decl_stmt|;
name|Pint
name|nv
decl_stmt|;
comment|/* number of vertices */
name|Pfacet_data_arr3
name|fdata
decl_stmt|;
name|Pfacet_vdata_arr3
name|vdata
decl_stmt|;
block|}
name|tsd3
struct|;
struct|struct
block|{
name|Pint
name|fflag
decl_stmt|;
name|Pint
name|vflag
decl_stmt|;
name|Pint
name|colr_model
decl_stmt|;
name|Pint_size
name|dim
decl_stmt|;
name|Pfacet_data_arr3
name|fdata
decl_stmt|;
name|Pfacet_vdata_arr3
name|vdata
decl_stmt|;
block|}
name|qmd3
struct|;
struct|struct
block|{
name|Pint
name|fflag
decl_stmt|;
name|Pint
name|eflag
decl_stmt|;
name|Pint
name|vflag
decl_stmt|;
name|Pint
name|colr_model
decl_stmt|;
name|Pint
name|num_sets
decl_stmt|;
name|Pfacet_data_arr3
name|fdata
decl_stmt|;
name|Pedge_data_list_list
modifier|*
name|edata
decl_stmt|;
name|Pint_list_list
modifier|*
name|vlist
decl_stmt|;
name|Pfacet_vdata_list3
name|vdata
decl_stmt|;
block|}
name|sofas3
struct|;
struct|struct
block|{
name|Pparal
name|paral
decl_stmt|;
comment|/* parallelogram */
name|Ppat_rep_plus
name|colr_array
decl_stmt|;
comment|/* colour array */
block|}
name|cell_array_plus
struct|;
name|Pgcolr
name|colr
decl_stmt|;
name|Prefl_props
name|props
decl_stmt|;
struct|struct
block|{
name|Pint_list
name|activation
decl_stmt|;
name|Pint_list
name|deactivation
decl_stmt|;
block|}
name|lss
struct|;
name|Pcull_mode
name|cull_mode
decl_stmt|;
comment|/* culling mode */
name|Pdisting_mode
name|disting_mode
decl_stmt|;
comment|/* distinguishing mode */
struct|struct
block|{
name|Pint
name|type
decl_stmt|;
name|Ppara_surf_characs
name|data
decl_stmt|;
block|}
name|para_surf_characs
struct|;
comment|/* parametric surface characteristics */
block|}
name|Pelem_data
typedef|;
end_typedef

begin_comment
comment|/* Explicitly defined portions of unbounded ranges. */
end_comment

begin_comment
comment|/* Colour models */
end_comment

begin_define
define|#
directive|define
name|PINDIRECT
value|(0)
end_define

begin_define
define|#
directive|define
name|PMODEL_RGB
value|(1)
end_define

begin_define
define|#
directive|define
name|PMODEL_CIELUV
value|(2)
end_define

begin_define
define|#
directive|define
name|PMODEL_HSV
value|(3)
end_define

begin_define
define|#
directive|define
name|PMODEL_HLS
value|(4)
end_define

begin_comment
comment|/* Rendering colour models */
end_comment

begin_define
define|#
directive|define
name|PRCM_WS_DEP
value|(0)
end_define

begin_define
define|#
directive|define
name|PRCM_RGB
value|(PMODEL_RGB)
end_define

begin_define
define|#
directive|define
name|PRCM_CIE
value|(PMODEL_CIELUV)
end_define

begin_define
define|#
directive|define
name|PRCM_HSV
value|(PMODEL_HSV)
end_define

begin_define
define|#
directive|define
name|PRCM_HLS
value|(PMODEL_HLS)
end_define

begin_comment
comment|/* Vertex data flags */
end_comment

begin_define
define|#
directive|define
name|PVERT_COORD
value|(0)
end_define

begin_define
define|#
directive|define
name|PVERT_COORD_COLOUR
value|(1)
end_define

begin_define
define|#
directive|define
name|PVERT_COORD_NORMAL
value|(2)
end_define

begin_define
define|#
directive|define
name|PVERT_COORD_COLOUR_NORMAL
value|(3)
end_define

begin_comment
comment|/* Edge data flags */
end_comment

begin_define
define|#
directive|define
name|PEDGE_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|PEDGE_VISIBILITY
value|(1)
end_define

begin_comment
comment|/* Facet data flags */
end_comment

begin_define
define|#
directive|define
name|PFACET_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|PFACET_COLOUR
value|(1)
end_define

begin_define
define|#
directive|define
name|PFACET_NORMAL
value|(2)
end_define

begin_define
define|#
directive|define
name|PFACET_COLOUR_NORMAL
value|(3)
end_define

begin_comment
comment|/* Line types */
end_comment

begin_define
define|#
directive|define
name|PLINE_SOLID
value|(1)
end_define

begin_define
define|#
directive|define
name|PLINE_DASH
value|(2)
end_define

begin_define
define|#
directive|define
name|PLINE_DOT
value|(3)
end_define

begin_define
define|#
directive|define
name|PLINE_DASH_DOT
value|(4)
end_define

begin_comment
comment|/* Marker types */
end_comment

begin_define
define|#
directive|define
name|PMARKER_DOT
value|(1)
end_define

begin_define
define|#
directive|define
name|PMARKER_PLUS
value|(2)
end_define

begin_define
define|#
directive|define
name|PMARKER_ASTERISK
value|(3)
end_define

begin_define
define|#
directive|define
name|PMARKER_CIRCLE
value|(4)
end_define

begin_define
define|#
directive|define
name|PMARKER_CROSS
value|(5)
end_define

begin_comment
comment|/* Annotation styles */
end_comment

begin_define
define|#
directive|define
name|PANNO_STYLE_UNCONNECTED
value|(1)
end_define

begin_define
define|#
directive|define
name|PANNO_STYLE_LEAD_LINE
value|(2)
end_define

begin_comment
comment|/* Prompt and echo types */
end_comment

begin_define
define|#
directive|define
name|PLOC_DEF
value|(1)
end_define

begin_define
define|#
directive|define
name|PLOC_CROSS_HAIR
value|(2)
end_define

begin_define
define|#
directive|define
name|PLOC_TRACK_CROSS
value|(3)
end_define

begin_define
define|#
directive|define
name|PLOC_RUB_BAND
value|(4)
end_define

begin_define
define|#
directive|define
name|PLOC_RECT
value|(5)
end_define

begin_define
define|#
directive|define
name|PLOC_DIGIT
value|(6)
end_define

begin_define
define|#
directive|define
name|PSTROKE_DEF
value|(1)
end_define

begin_define
define|#
directive|define
name|PSTROKE_DIGIT
value|(2)
end_define

begin_define
define|#
directive|define
name|PSTROKE_MARKER
value|(3)
end_define

begin_define
define|#
directive|define
name|PSTROKE_LINE
value|(4)
end_define

begin_define
define|#
directive|define
name|PVAL_DEF
value|(1)
end_define

begin_define
define|#
directive|define
name|PVAL_GRAPH
value|(2)
end_define

begin_define
define|#
directive|define
name|PVAL_DIGIT
value|(3)
end_define

begin_define
define|#
directive|define
name|PCHOICE_DEF
value|(1)
end_define

begin_define
define|#
directive|define
name|PCHOICE_PR_ECHO
value|(2)
end_define

begin_define
define|#
directive|define
name|PCHOICE_STRING_PR
value|(3)
end_define

begin_define
define|#
directive|define
name|PCHOICE_STRING_IN
value|(4)
end_define

begin_define
define|#
directive|define
name|PCHOICE_STRUCT
value|(5)
end_define

begin_define
define|#
directive|define
name|PPICK_DEF
value|(1)
end_define

begin_define
define|#
directive|define
name|PPICK_GROUP_HIGHL
value|(2)
end_define

begin_define
define|#
directive|define
name|PPICK_STRUCT_NETWORK
value|(3)
end_define

begin_define
define|#
directive|define
name|PSTRING_DEF
value|(1)
end_define

begin_comment
comment|/* Modelling clip operator */
end_comment

begin_define
define|#
directive|define
name|PMC_REPLACE
value|(1)
end_define

begin_define
define|#
directive|define
name|PMC_INTERSECT
value|(2)
end_define

begin_comment
comment|/* curve approximation methods */
end_comment

begin_define
define|#
directive|define
name|PCURV_WS_DEP
value|(1)
end_define

begin_define
define|#
directive|define
name|PCURV_CONSTANT_PARAMETRIC_BETWEEN_KNOTS
value|(2)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_SIZE_WC
value|(3)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_SIZE_NPC
value|(4)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_SIZE_DC
value|(5)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_DEVIATION_WC
value|(6)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_DEVIATION_NPC
value|(7)
end_define

begin_define
define|#
directive|define
name|PCURV_CHORDAL_DEVIATION_DC
value|(8)
end_define

begin_comment
comment|/* surface approximation methods */
end_comment

begin_define
define|#
directive|define
name|PSURF_WS_DEP
value|(1)
end_define

begin_define
define|#
directive|define
name|PSURF_CONSTANT_PARAMETRIC_BETWEEN_KNOTS
value|(2)
end_define

begin_define
define|#
directive|define
name|PSURF_CHORDAL_SIZE_WC
value|(3)
end_define

begin_define
define|#
directive|define
name|PSURF_CHORDAL_SIZE_NPC
value|(4)
end_define

begin_define
define|#
directive|define
name|PSURF_CHORDAL_SIZE_DC
value|(5)
end_define

begin_define
define|#
directive|define
name|PSURF_PLANAR_DEVIATION_WC
value|(6)
end_define

begin_define
define|#
directive|define
name|PSURF_PLANAR_DEVIATION_NPC
value|(7)
end_define

begin_define
define|#
directive|define
name|PSURF_PLANAR_DEVIATION_DC
value|(8)
end_define

begin_comment
comment|/* Polyline shading methods */
end_comment

begin_define
define|#
directive|define
name|PSD_NONE
value|(1)
end_define

begin_define
define|#
directive|define
name|PSD_COLOUR
value|(2)
end_define

begin_comment
comment|/* Additional shading method constants for interior shading method */
end_comment

begin_define
define|#
directive|define
name|PSD_DOT_PRODUCT
value|(3)
end_define

begin_define
define|#
directive|define
name|PSD_NORMAL
value|(4)
end_define

begin_comment
comment|/* Parametric surface characteristics types */
end_comment

begin_define
define|#
directive|define
name|PSC_NONE
value|(1)
end_define

begin_define
define|#
directive|define
name|PSC_WS_DEP
value|(2)
end_define

begin_define
define|#
directive|define
name|PSC_ISOPARAMETRIC_CURVES
value|(3)
end_define

begin_define
define|#
directive|define
name|PSC_LEVEL_CURVES_MC
value|(4)
end_define

begin_define
define|#
directive|define
name|PSC_LEVEL_CURVES_WC
value|(5)
end_define

begin_comment
comment|/* Reflectance Equation Constants */
end_comment

begin_define
define|#
directive|define
name|PREFL_NONE
value|(1)
end_define

begin_comment
comment|/* No reflectance calculation */
end_comment

begin_define
define|#
directive|define
name|PREFL_AMBIENT
value|(2)
end_define

begin_comment
comment|/* Use ambient term */
end_comment

begin_define
define|#
directive|define
name|PREFL_AMB_DIFF
value|(3)
end_define

begin_comment
comment|/* Use ambient and diffuse terms */
end_comment

begin_define
define|#
directive|define
name|PREFL_AMB_DIFF_SPEC
value|(4)
end_define

begin_comment
comment|/* Use ambient, diffuse& spec. terms */
end_comment

begin_comment
comment|/* Light Source Types */
end_comment

begin_define
define|#
directive|define
name|PLIGHT_AMBIENT
value|(1)
end_define

begin_define
define|#
directive|define
name|PLIGHT_DIRECTIONAL
value|(2)
end_define

begin_define
define|#
directive|define
name|PLIGHT_POSITIONAL
value|(3)
end_define

begin_define
define|#
directive|define
name|PLIGHT_SPOT
value|(4)
end_define

begin_comment
comment|/* Colour Mapping Methods */
end_comment

begin_define
define|#
directive|define
name|PCOLR_MAP_TRUE
value|(1)
end_define

begin_define
define|#
directive|define
name|PCOLR_MAP_PSEUDO
value|(2)
end_define

begin_define
define|#
directive|define
name|PCOLR_MAP_PSEUDO_N
value|(3)
end_define

begin_comment
comment|/* Global to hold specified X server */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|phg_x_server_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Preferred argument to OPEN PHIGS */
end_comment

begin_define
define|#
directive|define
name|PDEF_MEM_SIZE
value|((size_t) (-1))
end_define

begin_define
define|#
directive|define
name|PDEF_ERR_FILE
value|((char *) (0))
end_define

begin_define
define|#
directive|define
name|PHIGS_MAX_NAME_LEN
value|(255)
end_define

begin_comment
comment|/* Character set numbers */
end_comment

begin_define
define|#
directive|define
name|PCS_ASCII
value|(0)
end_define

begin_comment
comment|/* Font numbers */
end_comment

begin_define
define|#
directive|define
name|PFONT_MONO
value|(1)
end_define

begin_comment
comment|/* Implementation dependent escape numbers */
end_comment

begin_define
define|#
directive|define
name|PUESC_ERRSYNC
value|(-1)
end_define

begin_define
define|#
directive|define
name|PUESC_DPYINFO
value|(-2)
end_define

begin_define
define|#
directive|define
name|PUESC_IGNORE_DC_ERRORS
value|(-3)
end_define

begin_define
define|#
directive|define
name|PUESC_DRAWABLE_POINT_TO_PICK
value|(-4)
end_define

begin_define
define|#
directive|define
name|PUESC_DRAWABLE_POINTS_TO_WC
value|(-5)
end_define

begin_define
define|#
directive|define
name|PUESC_REDRAW_REGIONS
value|(-6)
end_define

begin_define
define|#
directive|define
name|PUESC_WS_SYNCH
value|(-7)
end_define

begin_comment
comment|/* HLHSR constants */
end_comment

begin_define
define|#
directive|define
name|PHIGS_HLHSR_MODE_NONE
value|(0)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_MODE_ZBUFF
value|(1)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_MODE_PAINTERS
value|(2)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_MODE_SCANLINE
value|(3)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_MODE_LINE_ONLY
value|(4)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_ID_OFF
value|(0)
end_define

begin_define
define|#
directive|define
name|PHIGS_HLHSR_ID_ON
value|(1)
end_define

begin_comment
comment|/* Multi-buffering constants. */
end_comment

begin_define
define|#
directive|define
name|PHIGS_BUF_SINGLE
value|(0)
end_define

begin_define
define|#
directive|define
name|PHIGS_BUF_DOUBLE
value|(1)
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHIGS_X_TOOL
block|,
name|PHIGS_X_DRAWABLE
block|}
name|Phigs_base_name
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|PHIGS_DC_LIMITS_FIXED
block|,
name|PHIGS_DC_LIMITS_ADJUST_TO_WINDOW
block|}
name|Phigs_DC_model
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ATTR_PKG_PHIGS
value|(PHG_ATTR_PKG_UNUSED_FIRST + 1)
end_define

begin_define
define|#
directive|define
name|PHIGS_FIRST_ATTR
value|(1)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_DC_DEPTH
value|(1.0)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_X
value|(50)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_Y
value|(50)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_WIDTH
value|(600)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_HEIGHT
value|(600)
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_LABEL
value|("PHIGS Workstation")
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_ICON_LABEL
value|("")
end_define

begin_define
define|#
directive|define
name|PHIGS_DEFAULT_TOOL_BORDER_WIDTH
value|(0)
end_define

begin_define
define|#
directive|define
name|PHIGS_ATTR
parameter_list|(
name|type
parameter_list|,
name|ordinal
parameter_list|)
define|\
value|PHG_ATTR( ATTR_PKG_PHIGS, type, ordinal)
end_define

begin_define
define|#
directive|define
name|PHIGS_ATTR_ORDINAL
parameter_list|(
name|attr
parameter_list|)
define|\
value|PHG_ATTR_ORDINAL((attr)) - PHIGS_FIRST_ATTR
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
comment|/* generic attributes start at 1 */
name|PHG_BASE_NAME
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_ENUM
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|5
argument_list|)
block|,
define|#
directive|define
name|PHIGS_BASE_NAME
value|(char *)PHG_BASE_NAME
comment|/* generic X attributes start at 25 */
comment|/* PHIGS_X_DISPLAY can only be set.  Only the name is remembered. */
name|PHG_X_DISPLAY
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_STRING
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|25
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_DISPLAY
value|(char *)PHG_X_DISPLAY
name|PHG_X_DISPLAY_NAME
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_STRING
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|26
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_DISPLAY_NAME
value|(char *)PHG_X_DISPLAY_NAME
name|PHG_X_DISPLAY_WINDOW
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT_PAIR
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|27
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_DISPLAY_WINDOW
value|(char *)PHG_X_DISPLAY_WINDOW
name|PHG_X_BUF_MODE
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|29
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_BUF_MODE
value|(char *)PHG_X_BUF_MODE
name|PHG_X_HANDLE_EXPOSE
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_BOOLEAN
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|31
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_HANDLE_EXPOSE
value|(char *)PHG_X_HANDLE_EXPOSE
name|PHG_X_HANDLE_DESTROY
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_BOOLEAN
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|32
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_HANDLE_DESTROY
value|(char *)PHG_X_HANDLE_DESTROY
name|PHG_DC_MODEL
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_ENUM
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|33
argument_list|)
block|,
define|#
directive|define
name|PHIGS_DC_MODEL
value|(char *)PHG_DC_MODEL
name|PHG_X_CMAP_PROP_ATOM
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|34
argument_list|)
block|,
define|#
directive|define
name|PHIGS_X_CMAP_PROP_ATOM
value|(char *)PHG_X_CMAP_PROP_ATOM
comment|/* tool attributes start at 50 */
name|PHG_TOOL_WIDTH
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|50
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_WIDTH
value|(char *)PHG_TOOL_WIDTH
name|PHG_TOOL_HEIGHT
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|51
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_HEIGHT
value|(char *)PHG_TOOL_HEIGHT
name|PHG_TOOL_X
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|52
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_X
value|(char *)PHG_TOOL_X
name|PHG_TOOL_Y
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|53
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_Y
value|(char *)PHG_TOOL_Y
name|PHG_TOOL_LABEL
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_STRING
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|54
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_LABEL
value|(char *)PHG_TOOL_LABEL
name|PHG_TOOL_ICON_LABEL
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_STRING
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|55
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_ICON_LABEL
value|(char *)PHG_TOOL_ICON_LABEL
name|PHG_TOOL_BORDER_WIDTH
init|=
name|PHIGS_ATTR
argument_list|(
name|PHG_ATTR_INT
argument_list|,
name|PHIGS_FIRST_ATTR
operator|+
literal|56
argument_list|)
block|,
define|#
directive|define
name|PHIGS_TOOL_BORDER_WIDTH
value|(char *)PHG_TOOL_BORDER_WIDTH
comment|/* Phigs attributes start at 150 */
name|PHG_WS_CATEGORY
init|=
name|PHIGS_ATTR
argument_list|(
argument|PHG_ATTR_ENUM
argument_list|,
argument|PHIGS_FIRST_ATTR +
literal|150
argument_list|)
define|#
directive|define
name|PHIGS_WS_CATEGORY
value|(char *)PHG_WS_CATEGORY
block|}
name|Phigs_ws_type_attr
typedef|;
end_typedef

begin_comment
comment|/* Pxphigs_info_mask values */
end_comment

begin_define
define|#
directive|define
name|PXPHIGS_INFO_DISPLAY
value|(1L<< 0)
end_define

begin_define
define|#
directive|define
name|PXPHIGS_INFO_RMDB
value|(1L<< 1)
end_define

begin_define
define|#
directive|define
name|PXPHIGS_INFO_APPL_ID
value|(1L<< 2)
end_define

begin_define
define|#
directive|define
name|PXPHIGS_INFO_ARGS
value|(1L<< 3)
end_define

begin_define
define|#
directive|define
name|PXPHIGS_INFO_FLAGS_NO_MON
value|(1L<< 4)
end_define

begin_define
define|#
directive|define
name|PXPHIGS_INFO_FLAGS_CLIENT_SS
value|(1L<< 5)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Display
modifier|*
name|display
decl_stmt|;
comment|/* valid display pointer.  */
name|XrmDatabase
name|rmdb
decl_stmt|;
comment|/* a valid database */
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|class_name
decl_stmt|;
block|}
name|appl_id
struct|;
comment|/* for resolving database attributes */
struct|struct
block|{
name|int
modifier|*
name|argc_p
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|}
name|args
struct|;
comment|/* for merging args into specified database */
struct|struct
block|{
name|unsigned
name|no_monitor
range|:
literal|1
decl_stmt|;
comment|/* 1 ==> monitor will not be executed */
name|unsigned
name|force_client_SS
decl_stmt|;
comment|/* 1 ==> always use client-side CSS */
block|}
name|flags
struct|;
block|}
name|Pxphigs_info
typedef|;
end_typedef

begin_comment
comment|/* These are declared here because they return types defined here. */
end_comment

begin_function_decl
specifier|extern
name|Pint
name|phigs_ws_type_create
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|Pint
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|NeedVarargsPrototypes
end_if

begin_typedef
typedef|typedef
name|struct
name|_Wst
modifier|*
name|_PxphigsWst
typedef|;
end_typedef

begin_comment
comment|/* kludge! */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|caddr_t
name|phigs_ws_type_set
parameter_list|(
if|#
directive|if
name|NeedVarargsPrototypes
name|_PxphigsWst
parameter_list|,
modifier|...
endif|#
directive|endif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|caddr_t
name|phigs_ws_type_get
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

