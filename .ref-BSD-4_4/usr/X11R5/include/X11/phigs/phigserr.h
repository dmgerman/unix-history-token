begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: phigserr.h,v 5.2 91/07/12 20:22:21 hersh Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************/
end_comment

begin_comment
comment|/* Implementation Dependent Errors */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_SUPP
value|-500
end_define

begin_comment
comment|/* Ignoring function, this function 					   is not supported */
end_comment

begin_define
define|#
directive|define
name|PE_EL_TOO_LARGE
value|-501
end_define

begin_comment
comment|/* Ignoring function, the element 					   is too large */
end_comment

begin_comment
comment|/* PEX/PHIGS errors */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_NO_XSRVR
value|-200
end_define

begin_comment
comment|/* Ignoring function, cannot connect 					   to the designated or default 					   server */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_NO_PEX
value|-201
end_define

begin_comment
comment|/* Ignoring function, the specified 					   or default X server does not 					   support a compatible PEX extension */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_ALLOC
value|-202
end_define

begin_comment
comment|/* Ignoring function, an X 					   allocation error has occurred */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_NO_WIN_CREATE
value|-203
end_define

begin_comment
comment|/* Ignoring function, can't create 					   an X window */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_NO_SHELL_CREATE
value|-204
end_define

begin_comment
comment|/* Ignoring function, can't create 					   an Xt shell */
end_comment

begin_comment
comment|/* TODO: These are only defined until the correct mapping can be determined. */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_CTE
value|-250
end_define

begin_comment
comment|/* PEX colour type error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_RSE
value|-251
end_define

begin_comment
comment|/* PEX rendering state error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_FPFE
value|-252
end_define

begin_comment
comment|/* PEX floating point format error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_LE
value|-253
end_define

begin_comment
comment|/* PEX label error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_LTE
value|-254
end_define

begin_comment
comment|/* PEX lookup table error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_NSE
value|-255
end_define

begin_comment
comment|/* PEX name set error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_PE
value|-256
end_define

begin_comment
comment|/* PEX path error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_FE
value|-257
end_define

begin_comment
comment|/* PEX font error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_PWE
value|-258
end_define

begin_comment
comment|/* PEX phigs workstation error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_PME
value|-259
end_define

begin_comment
comment|/* PEX pick measure error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_PCE
value|-260
end_define

begin_comment
comment|/* PEX pipeline context error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_RE
value|-261
end_define

begin_comment
comment|/* PEX renderer error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_SCE
value|-262
end_define

begin_comment
comment|/* PEX search context error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_SE
value|-263
end_define

begin_comment
comment|/* PEX structure error */
end_comment

begin_define
define|#
directive|define
name|PE_PEX_OCE
value|-264
end_define

begin_comment
comment|/* PEX output command error */
end_comment

begin_comment
comment|/* X Errors */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_REQUEST
value|-301
end_define

begin_comment
comment|/*X Bad Request Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_VALUE
value|-302
end_define

begin_comment
comment|/*X Bad Value Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_WINDOW
value|-303
end_define

begin_comment
comment|/*X Bad Window Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_PIXMAP
value|-304
end_define

begin_comment
comment|/*X Bad Pixmap Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_ATOM
value|-305
end_define

begin_comment
comment|/*X Bad Atom Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_CURSOR
value|-306
end_define

begin_comment
comment|/*X Bad Cursor Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_FONT
value|-307
end_define

begin_comment
comment|/*X Bad Font Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_MATCH
value|-308
end_define

begin_comment
comment|/*X Bad Match Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_DRAWABLE
value|-309
end_define

begin_comment
comment|/*X Bad Drawable Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_ACCESS
value|-310
end_define

begin_comment
comment|/*X Bad Access Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_ALLOC
value|-311
end_define

begin_comment
comment|/*X Bad Alloc Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_COLOR
value|-312
end_define

begin_comment
comment|/*X Bad Colour Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_GC
value|-313
end_define

begin_comment
comment|/*X Bad GC Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_ID_CHOICE
value|-314
end_define

begin_comment
comment|/*X Bad ID Choice Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_NAME
value|-315
end_define

begin_comment
comment|/*X Bad Name Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_LENGTH
value|-316
end_define

begin_comment
comment|/*X Bad Length Error */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_IMPL
value|-317
end_define

begin_comment
comment|/*X Bad Implementation Error */
end_comment

begin_comment
comment|/* Miscellaneous*/
end_comment

begin_define
define|#
directive|define
name|PE_BAD_DC_VAL
value|-171
end_define

begin_comment
comment|/*Ignoring function, the specified DC 				    limits are less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_NO_DC_SET
value|-170
end_define

begin_comment
comment|/*Ignoring function, DC limits cannot be 				    set for this workstation */
end_comment

begin_define
define|#
directive|define
name|PE_X_NO_CMAP
value|-169
end_define

begin_comment
comment|/*Ignoring function, cannot create an X  			          colormap resource */
end_comment

begin_define
define|#
directive|define
name|PE_X_BAD_VISUAL
value|-168
end_define

begin_comment
comment|/*Ignoring function, cannot open workstation 				  on a read-only visual with no predefined 				  colormap properties */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_NUM_VTX_LT_0
value|-164
end_define

begin_comment
comment|/*Ignoring function, the specified number of 				  vertices or sets of vertices is less than  				  zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_EDGE_FLAG_INFO
value|-163
end_define

begin_comment
comment|/*Ignoring function, the 				  specified edge data flag is invalid*/
end_comment

begin_define
define|#
directive|define
name|PE_BAD_VERT_FLAG
value|-162
end_define

begin_comment
comment|/*Ignoring function, the specified vertex 				  flag is invalid*/
end_comment

begin_define
define|#
directive|define
name|PE_BAD_FACET_FLAG
value|-161
end_define

begin_comment
comment|/*Ignoring function, the specified facet 				  flag is invalid*/
end_comment

begin_define
define|#
directive|define
name|PE_NO_FUNC
value|-160
end_define

begin_comment
comment|/*Ignoring function, the specified                                    function is not available on the speci-                                   fied workstation */
end_comment

begin_define
define|#
directive|define
name|PE_NO_INFO
value|-159
end_define

begin_comment
comment|/*Ignoring function, the requested 				  information is not available */
end_comment

begin_define
define|#
directive|define
name|PE_NO_FONT_CS
value|-156
end_define

begin_comment
comment|/*Ignoring Function, specified font is not  				  available for character set */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_CHAR_SET
value|-155
end_define

begin_comment
comment|/*Specified character set is invalid */
end_comment

begin_define
define|#
directive|define
name|PE_LENGTH_LT_0
value|-153
end_define

begin_comment
comment|/*List length is less than zero -- zero will 				  be used */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_IMPL
value|-152
end_define

begin_comment
comment|/*Ignoring function, not implemented */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_NAME
value|-151
end_define

begin_comment
comment|/*Ignoring function, nameset or filter 				  contains name outside supported range */
end_comment

begin_define
define|#
directive|define
name|PE_NUM_PTS_LT_0
value|-150
end_define

begin_comment
comment|/*Ignoring function, the specified number of 				  points or sets of points is less than zero */
end_comment

begin_comment
comment|/* Workstation Configuration */
end_comment

begin_define
define|#
directive|define
name|PE_WST_BOUND
value|-100
end_define

begin_comment
comment|/*Ignoring function, workstation type is 				  a default type or bound to a workstation 				  and cannot be modified */
end_comment

begin_comment
comment|/* Unusable Environment */
end_comment

begin_define
define|#
directive|define
name|PE_NO_SHMEM
value|-57
end_define

begin_comment
comment|/*Kernel not configured with shared-memory IPC 				    facility needed for PEX SI communication */
end_comment

begin_define
define|#
directive|define
name|PE_NO_FONT
value|-55
end_define

begin_comment
comment|/*Ignoring function, cannot open PHIGS, 				    cannot open font files */
end_comment

begin_define
define|#
directive|define
name|PE_NO_FILE
value|-54
end_define

begin_comment
comment|/*Ignoring function, cannot locate SI 				    support file */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_FILE_PATH
value|-53
end_define

begin_comment
comment|/*Ignoring function, SI support file 				    path invalid */
end_comment

begin_define
define|#
directive|define
name|PE_PATH_TOO_LONG
value|-52
end_define

begin_comment
comment|/*Ignoring function, PEXAPIDIR path is too 				     long */
end_comment

begin_define
define|#
directive|define
name|PE_NO_SRVR_FILE
value|-51
end_define

begin_comment
comment|/*Ignoring function, cannot open PHIGS, 				     cannot locate SI file "phigsmon" */
end_comment

begin_define
define|#
directive|define
name|PE_COMM
value|-50
end_define

begin_comment
comment|/*Communication error */
end_comment

begin_comment
comment|/* Expended or Failing System Resources */
end_comment

begin_define
define|#
directive|define
name|PE_NO_TRAV_MEM
value|-6
end_define

begin_comment
comment|/*Could not allocate additional dynamic 				     memory during structure traversal */
end_comment

begin_define
define|#
directive|define
name|PE_EXEC
value|-2
end_define

begin_comment
comment|/*Ignoring function, cannot open PHIGS, 				     cannot create server */
end_comment

begin_define
define|#
directive|define
name|PE_COMM_CREAT
value|-1
end_define

begin_comment
comment|/*Ignoring function, cannot open PHIGS, 				    cannot create communication channel */
end_comment

begin_define
define|#
directive|define
name|PE_NO_ERROR
value|0
end_define

begin_comment
comment|/*No Error */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_PHCL
value|1
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHCL,WSCL,STCL,ARCL) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_PHOP
value|2
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,*,*,*) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_WSOP
value|3
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,WSOP,*,*) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_CL
value|4
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,WSCL,STCL,ARCL) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_STOP
value|5
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,*,STOP,*) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_STCL
value|6
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,*,STCL,*) */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_AROP
value|7
end_define

begin_comment
comment|/*Ignoring function, function requires                                      state (PHOP,*,*,AROP) */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_CONN_ID
value|50
end_define

begin_comment
comment|/*Ignoring function, connection identi-                                      fier not recognized by the implementa-                                      tion */
end_comment

begin_define
define|#
directive|define
name|PE_WS_TYPE
value|51
end_define

begin_comment
comment|/*Ignoring function, this information is                                      not yet available for this generic 				     workstation type; open a workstation of 				     this type and use the specific 				     workstation type */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_WS_TYPE
value|52
end_define

begin_comment
comment|/*Ignoring function, workstation type                                      not recognized by the implementation                                      */
end_comment

begin_define
define|#
directive|define
name|PE_DUP_WS_ID
value|53
end_define

begin_comment
comment|/*Ignoring function, workstation iden-                                      tifier already is in use */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NOT_OPEN
value|54
end_define

begin_comment
comment|/*Ignoring function, the specified                                      workstation is not open */
end_comment

begin_define
define|#
directive|define
name|PE_NO_OPEN_WS
value|55
end_define

begin_comment
comment|/*Ignoring function, workstation cannot                                      be opened for an implementation depen-                                      dent reason */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NOT_MO
value|56
end_define

begin_comment
comment|/*Ignoring function, specified                                      workstation is not of category MO */
end_comment

begin_define
define|#
directive|define
name|PE_WS_MI
value|57
end_define

begin_comment
comment|/*Ignoring function, specified worksta-                                      tion is of category MI */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NOT_MI
value|58
end_define

begin_comment
comment|/*Ignoring function, specified                                      workstation is not of category MI */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NO_OUTPUT
value|59
end_define

begin_comment
comment|/*Ignoring function, the specified                                      workstation does not have output capa-                                      bility (i.e., the workstation category                                      is neither OUTPUT, OUTIN, nor MO) */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NOT_OUTIN
value|60
end_define

begin_comment
comment|/*Ignoring function, specified worksta-                                      tion is not of category OUTIN */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NO_INPUT
value|61
end_define

begin_comment
comment|/*Ignoring function, specified worksta-                                      tion is neither of category INPUT nor                                      of category OUTIN */
end_comment

begin_define
define|#
directive|define
name|PE_WS_NOT_OUT
value|62
end_define

begin_comment
comment|/*Ignoring function, this information is                                      not available for this MO workstation 				     type */
end_comment

begin_define
define|#
directive|define
name|PE_MAX_WS
value|63
end_define

begin_comment
comment|/*Ignoring function, opening this                                      workstation would exceed the maximum                                      number of simultaneously open                                      workstations */
end_comment

begin_define
define|#
directive|define
name|PE_NO_GDP
value|64
end_define

begin_comment
comment|/*Ignoring function, the specified                                      workstation type is not able to gen-                                      erate the specified generalized draw-                                      ing primitive */
end_comment

begin_define
define|#
directive|define
name|PE_BUN_INDX_LT_1
value|100
end_define

begin_comment
comment|/*Ignoring function, the bundle index                                      value is less than one */
end_comment

begin_define
define|#
directive|define
name|PE_REP_UNDEF
value|101
end_define

begin_comment
comment|/*The specified representation has not                                      been defined */
end_comment

begin_define
define|#
directive|define
name|PE_REP_NOT_PREDEF
value|102
end_define

begin_comment
comment|/*Ignoring function, the specified                                      representation has not be predefined                                      on this workstation */
end_comment

begin_define
define|#
directive|define
name|PE_MAX_BUN
value|103
end_define

begin_comment
comment|/*Ignoring function, setting this bundle                                      table entry would exceed the maximum                                      number of entries allowed in the                                      workstation bundle table */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_LINETYPE
value|104
end_define

begin_comment
comment|/*Ignoring function, the specified line-                                      type is not available on the specified                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_MARKERTYPE
value|105
end_define

begin_comment
comment|/*Ignoring function, the specified mark-                                      er type is not available on the speci-                                      fied workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_FONT
value|106
end_define

begin_comment
comment|/*Ignoring function, the specified font                                      is not available for the requested                                      text precision on the specified                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_EDGETYPE
value|107
end_define

begin_comment
comment|/*Ignoring function, the specified edge-                                      type is not available on the specified                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_INT_STYLE
value|108
end_define

begin_comment
comment|/*Ignoring function, the specified                                      interior style is not available on the                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_NO_PAT
value|109
end_define

begin_comment
comment|/*Ignoring function, interior style PAT-                                      TERN  is not supported on the worksta-                                      tion */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLR_MODEL
value|110
end_define

begin_comment
comment|/*Ignoring function, the specified 				     colour model is not available on the 				     workstation. */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_HLHSR_MODE
value|111
end_define

begin_comment
comment|/*Ignoring function, the specified HLHSR                                      mode is not available on the specified                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_PAT_INDX_LT_1
value|112
end_define

begin_comment
comment|/*Ignoring function, the pattern index                                      value is less than one */
end_comment

begin_define
define|#
directive|define
name|PE_COLR_INDX_LT_0
value|113
end_define

begin_comment
comment|/*Ignoring function, the colour index                                      value is less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_VIEW_INDX_LT_0
value|114
end_define

begin_comment
comment|/*Ignoring function, the view index                                      value is less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_VIEW_INDX_LT_1
value|115
end_define

begin_comment
comment|/*Ignoring function, the view index                                      value is less than one */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PAT_DIM
value|116
end_define

begin_comment
comment|/*Ignoring function, one of the dimen-                                      sions of pattern colour array is less                                      than one */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLR_DIM
value|117
end_define

begin_comment
comment|/*Ignoring function, one of the dimen-                                      sions of the colour index array is                                      less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLR
value|118
end_define

begin_comment
comment|/*Ignoring function, one of the com-                                      ponents of the colour specification is                                      out of range.  The valid range is                                      dependent upon the current colour                                      model */
end_comment

begin_define
define|#
directive|define
name|PE_DCUE_INDX_LT_0
value|119
end_define

begin_comment
comment|/*Ignoring function, depth cue index 				     is less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_DCUE_INDX_LT_1
value|120
end_define

begin_comment
comment|/*Ignoring function, depth cue index 				     is less than one */
end_comment

begin_define
define|#
directive|define
name|PE_COLRMAP_INDX_LT_0
value|121
end_define

begin_comment
comment|/*Ignoring function, the colour mapping 				     index is less than zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_LINE_SHADE
value|122
end_define

begin_comment
comment|/*Ignoring function, the specified poly-                                      line shading method is not available 				     on the workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_INT_SHADE
value|123
end_define

begin_comment
comment|/*Ignoring function, the specified interior                                      shading method is not available 				     on the workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_REF_EQN
value|124
end_define

begin_comment
comment|/*Ignoring function, the specified interior                                      reflectance equation is not available 				     on the workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLRMAP_RANGE
value|125
end_define

begin_comment
comment|/*Ignoring function, the total of the 				     colour range fields in all the table 				     entries is too large  */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLRMAP_METHOD
value|126
end_define

begin_comment
comment|/*Ignoring function, the specified colour                                      mapping method is not available 				     on the specified workstation */
end_comment

begin_define
define|#
directive|define
name|PE_LTSRC_INDX_LT_1
value|129
end_define

begin_comment
comment|/*Ignoring function, the light source index 				     is less than 1 */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_REF_PLANES
value|130
end_define

begin_comment
comment|/*Ignoring function, invalid reference                                      planes; DQMIN> DQMAX */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_LTSRCTYPE
value|131
end_define

begin_comment
comment|/*Ignoring function, the specified light 				     source type is not available on the  				     workstation */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_LTANGLE
value|132
end_define

begin_comment
comment|/*Ignoring function, the specified spot 				     light spread angle is out of range */
end_comment

begin_define
define|#
directive|define
name|PE_ENTRY_LT_1
value|133
end_define

begin_comment
comment|/*Ignoring function, one of the entries 				     in the activation list or the 				     deactivation list is less than 1 */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_INDIRECT
value|134
end_define

begin_comment
comment|/*Ignoring function, the requested 				       entry contains a general colour 				       specification with colour type other 				       than INDIRECT */
end_comment

begin_define
define|#
directive|define
name|PE_DUP_ENTRY
value|135
end_define

begin_comment
comment|/*Ignoring function, the same entry                                      exists in both the activation and the 				     deactivation list */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_COLR_RANGE
value|136
end_define

begin_comment
comment|/*Ignoring function, one of the 				      components of the colour specification 				      is out of range. */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_DATA
value|138
end_define

begin_comment
comment|/*Ignoring function, one or more fields 				      in the specified data record is 				      inconsistent */
end_comment

begin_define
define|#
directive|define
name|PE_MAX_VIEW
value|150
end_define

begin_comment
comment|/*Ignoring function, setting this view                                      table entry would exceed the maximum                                      number of entries allowed in the                                      workstation's view table */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_WINDOW
value|151
end_define

begin_comment
comment|/*Ignoring function, invalid window;                                      XMIN>= XMAX, YMIN>= YMAX, or 				     ZMIN> ZMAX */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_VIEWPORT
value|152
end_define

begin_comment
comment|/*Ignoring function, invalid viewport;                                      XMIN>= XMAX, YMIN>= YMAX, or 				     ZMIN> ZMAX */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_CLIP
value|153
end_define

begin_comment
comment|/*Ignoring function, invalid view clipping 				     limits; XMIN>= XMAX, YMIN>= YMAX, or 				     ZMIN> ZMAX */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_CLIP
value|154
end_define

begin_comment
comment|/*Ignoring function, the view clipping 				     limits are not within NPC range */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PROJ_VIEWPORT
value|155
end_define

begin_comment
comment|/*Ignoring function, the projection                                      viewport limits are not within NPC range */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_WS_WINDOW
value|156
end_define

begin_comment
comment|/*Ignoring function, the workstation                                      window limits are not within NPC range */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_WS_VIEWPORT
value|157
end_define

begin_comment
comment|/*Ignoring function, the workstation                                      viewport is not within display space */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PLANES
value|158
end_define

begin_comment
comment|/*Ignoring function, front plane and back                                      plane distances are equal when z-extent 				     of the projection viewport is zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_VPN
value|159
end_define

begin_comment
comment|/*Ignoring function, the view plane nor-                                      mal vector has length zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_VUP
value|160
end_define

begin_comment
comment|/*Ignoring function, the view up vector                                      has length zero */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_VUP_VPN
value|161
end_define

begin_comment
comment|/*Ignoring function, the view up and                                      view plane normal vectors are parallel                                      thus the viewing coordinate system                                      cannot be established */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PRP
value|162
end_define

begin_comment
comment|/*Ignoring function, the projection                                      reference point is between the front                                      and back planes */
end_comment

begin_define
define|#
directive|define
name|PE_PRP_VIEW_PLANE
value|163
end_define

begin_comment
comment|/*Ignoring function, the projection                                      reference point cannot be positioned                                      on the view plane */
end_comment

begin_define
define|#
directive|define
name|PE_FRONT_BACK
value|164
end_define

begin_comment
comment|/*Ignoring function, the back                                      plane is in front of the front plane */
end_comment

begin_define
define|#
directive|define
name|PE_IGNORE_STRUCTS
value|200
end_define

begin_comment
comment|/*Warning, ignoring structures that do                                      not exist */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_STRUCT
value|201
end_define

begin_comment
comment|/*Ignoring function, the specified                                      structure does not exist */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ELEMENT
value|202
end_define

begin_comment
comment|/*Ignoring function, the specified ele-                                      ment does not exist */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PATH
value|203
end_define

begin_comment
comment|/*Ignoring function, specified starting                                      path not found in CSS */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_CEILING_INDX
value|204
end_define

begin_comment
comment|/*Ignoring function, specified search                                      ceiling index out of range */
end_comment

begin_define
define|#
directive|define
name|PE_NO_LABEL
value|205
end_define

begin_comment
comment|/*Ignoring function, the label does not                                      exist in the open structure between                                      the element pointer and the end of the                                      structure */
end_comment

begin_define
define|#
directive|define
name|PE_NO_LABELS
value|206
end_define

begin_comment
comment|/*Ignoring function, one or both of the                                      labels does not exist in the open                                      structure between the element pointer                                      and the end of the structure */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PATH_DEPTH
value|207
end_define

begin_comment
comment|/*Ignoring function, the specified path                                      depth is less than zero (0) */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_DIPS_PRI
value|208
end_define

begin_comment
comment|/*Ignoring function, the display priority 				     is out of range */
end_comment

begin_define
define|#
directive|define
name|PE_NO_DEVICE
value|250
end_define

begin_comment
comment|/*Ignoring function, the specified                                      device is not available on the specified                                      workstation */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_REQUEST
value|251
end_define

begin_comment
comment|/*Ignoring function, the function re-                                      quires the input device to be in RE-                                      QUEST mode */
end_comment

begin_define
define|#
directive|define
name|PE_NOT_SAMPLE
value|252
end_define

begin_comment
comment|/*Ignoring function, the function re-                                      quires the input device to be in SAM-                                      PLE Mode */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PET
value|253
end_define

begin_comment
comment|/*Warning, the specified prompt/echo                                      type is not available on the specified                                      workstation.  Prompt/echo type one                                      will be used in its place */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_ECHO
value|254
end_define

begin_comment
comment|/*Ignoring function, invalid echo 				     area/volume; XMIN>= XMAX, YMIN>= YMAX, 				     or ZMIN> ZMAX */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ECHO
value|255
end_define

begin_comment
comment|/*Ignoring function, one of the echo 				     area/volume boundary points is 				     outside the range of the device */
end_comment

begin_define
define|#
directive|define
name|PE_QUEUE_OFLOW
value|256
end_define

begin_comment
comment|/*Warning, the input queue has over-                                      flowed */
end_comment

begin_define
define|#
directive|define
name|PE_NO_QUEUE_OFLOW
value|257
end_define

begin_comment
comment|/*Ignoring function, input queue has not                                      overflowed */
end_comment

begin_define
define|#
directive|define
name|PE_OFLOW_NO_GO
value|258
end_define

begin_comment
comment|/*Warning, input queue has over-                                      flowed, but associated workstation has 				     been closed */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_CLASS
value|259
end_define

begin_comment
comment|/*Ignoring function, the input device                                      class of the current input report does                                      not match the class being requested */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_DATA_REC
value|260
end_define

begin_comment
comment|/*Ignoring function, one of the fields                                      within the input device data record is                                      in error */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_VALUE
value|261
end_define

begin_comment
comment|/*Ignoring function, initial value is 				     invalid */
end_comment

begin_define
define|#
directive|define
name|PE_STROKE_BUF_SIZE
value|262
end_define

begin_comment
comment|/*Ignoring function, number of points in 				     the initial stroke is greater than the 				     buffer size */
end_comment

begin_define
define|#
directive|define
name|PE_STRING_BUF_SIZE
value|263
end_define

begin_comment
comment|/*Ignoring function, length of the initial 				     string is greater than the buffer size */
end_comment

begin_define
define|#
directive|define
name|PE_ILLEGAL_ITEM_TYPE
value|300
end_define

begin_comment
comment|/*Ignoring function, item type is not                                      allowed for user items */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_ITEM_LEN
value|301
end_define

begin_comment
comment|/*Ignoring function, item length is in-                                      valid */
end_comment

begin_define
define|#
directive|define
name|PE_METAFILE_EMPTY
value|302
end_define

begin_comment
comment|/*Ignoring function, no item is left in                                      metafile input */
end_comment

begin_define
define|#
directive|define
name|PE_INVALID_ITEM
value|303
end_define

begin_comment
comment|/*Ignoring function, metafile item is                                      invalid */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ITEM_TYPE
value|304
end_define

begin_comment
comment|/*Ignoring function, item type is                                      unknown */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ITEM_REC
value|305
end_define

begin_comment
comment|/*Ignoring function, content of item                                      data record is invalid for the speci-                                      fied item type */
end_comment

begin_define
define|#
directive|define
name|PE_MAX_ITEM_LEN
value|306
end_define

begin_comment
comment|/*Ignoring function, maximum item data                                      record length is invalid */
end_comment

begin_define
define|#
directive|define
name|PE_USER_ITEM
value|307
end_define

begin_comment
comment|/*Ignoring function, user item cannot be                                      interpreted */
end_comment

begin_define
define|#
directive|define
name|PE_ESC_NOT_AVAIL
value|350
end_define

begin_comment
comment|/*Warning, the specified escape is not                                      available on one or more workstations                                      in this implementation.  The escape                                      will be processed by those worksta-                                      tions on which it is available */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ESC_DATA_REC
value|351
end_define

begin_comment
comment|/*Ignoring function, one of the fields                                      within the escape data record is in                                      error */
end_comment

begin_define
define|#
directive|define
name|PE_AR_CANT_OPEN
value|400
end_define

begin_comment
comment|/*Ignoring function, the archive file                                      cannot be opened */
end_comment

begin_define
define|#
directive|define
name|PE_MAX_AR
value|401
end_define

begin_comment
comment|/*Ignoring function, opening this ar-                                      chive file would exceed the maximum                                      number of simultaneously open archive                                      files */
end_comment

begin_define
define|#
directive|define
name|PE_DUP_AR_ID
value|402
end_define

begin_comment
comment|/*Ignoring function, archive file iden-                                      tifier already in use */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_AR
value|403
end_define

begin_comment
comment|/*Ignoring function, the archive file is                                      not a PHIGS archive file */
end_comment

begin_define
define|#
directive|define
name|PE_AR_NOT_OPEN
value|404
end_define

begin_comment
comment|/*Ignoring function, the specified ar-                                      chive file is not open */
end_comment

begin_define
define|#
directive|define
name|PE_NAME_CONFLICT
value|405
end_define

begin_comment
comment|/*Ignoring function, name conflict oc-                                      cured while conflict resolution flag                                      has value ABANDON */
end_comment

begin_define
define|#
directive|define
name|PE_AR_FULL
value|406
end_define

begin_comment
comment|/*Warning, the archive file is full.                                      Any structures that were archived were                                      archived in total */
end_comment

begin_define
define|#
directive|define
name|PE_AR_NO_STRUCT
value|407
end_define

begin_comment
comment|/*Warning, some of the specified struc-                                      tures do not exist on the archive file */
end_comment

begin_define
define|#
directive|define
name|PE_AR_NO_STRUCT_EMPTY
value|408
end_define

begin_comment
comment|/*Warning, some of the specified struc-                                      tures do not exist on the archive                                      file.  PHIGS will create empty struc-                                      tures in their places */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ERROR_FILE
value|450
end_define

begin_comment
comment|/*Ignoring function, the specified                                      error file is invalid */
end_comment

begin_comment
comment|/* PHIGS+ errors */
end_comment

begin_define
define|#
directive|define
name|PE_ORDER_LT_1
value|500
end_define

begin_comment
comment|/*Ignoring function, the specified order                                      is less than 1 */
end_comment

begin_define
define|#
directive|define
name|PE_CTL_POINTS
value|501
end_define

begin_comment
comment|/*Ignoring function, not enough control                                      points for specified order */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_ORDER
value|502
end_define

begin_comment
comment|/*Ignoring function, the specified order                                      is inconsistent with number of knots                                      and control points */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_KNOTS
value|503
end_define

begin_comment
comment|/*Ignoring function, the knot sequence is                                      not non-decreasing */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_VERT_INDX
value|504
end_define

begin_comment
comment|/*Ignoring function, one or more of the                                      vertex indices is out of range */
end_comment

begin_define
define|#
directive|define
name|PE_DEGEN_FAS
value|505
end_define

begin_comment
comment|/*Warning, the fill area is degenerate */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_PARAM_RANGE
value|506
end_define

begin_comment
comment|/*Ignoring function, parameter range is                                      inconsistent with the knots */
end_comment

begin_define
define|#
directive|define
name|PE_BAD_EDGE_FLAG
value|513
end_define

begin_comment
comment|/*Ignoring function, inconsistent edge                                      flag specification */
end_comment

begin_define
define|#
directive|define
name|PE_OFLOOW_PHIGS
value|900
end_define

begin_comment
comment|/*Storage overflow has occurred in PHIGS */
end_comment

begin_define
define|#
directive|define
name|PE_OFLOW_CSS
value|901
end_define

begin_comment
comment|/*Storage overflow has occurred in CSS */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_READ
value|902
end_define

begin_comment
comment|/*Input/Output error has occurred while 				     reading */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_WRITE
value|903
end_define

begin_comment
comment|/*Input/Output error has occurred while 				     writing */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_TO_WS
value|904
end_define

begin_comment
comment|/*Input/Output error has occurred while 				     sending data to a workstation */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_FROM_WS
value|905
end_define

begin_comment
comment|/*Input/Output error has occurred while 				     receiving data from a workstation */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_LIB
value|906
end_define

begin_comment
comment|/*Input/Output error has occurred during 				     program library management */
end_comment

begin_define
define|#
directive|define
name|PE_IO_ERROR_WDT
value|907
end_define

begin_comment
comment|/*Input/Output error has occurred while 				     reading workstation description table */
end_comment

begin_define
define|#
directive|define
name|PE_ARITHMETIC_ERROR
value|908
end_define

begin_comment
comment|/*Arithmetic error has occurred */
end_comment

begin_comment
comment|/* C Binding specific errors */
end_comment

begin_define
define|#
directive|define
name|PE_START_IND_INVAL
value|2200
end_define

begin_comment
comment|/*Buffer overflow in input or inquiry                                      function */
end_comment

begin_define
define|#
directive|define
name|PE_LIST_LEN_LT_ZERO
value|2201
end_define

begin_comment
comment|/*Start index out of range */
end_comment

begin_define
define|#
directive|define
name|PE_ENUM_TYPE_INVAL
value|2202
end_define

begin_comment
comment|/* Enumeration type out of range */
end_comment

begin_comment
comment|/* FORTRAN Binding specific errors - these are defined here only to allow    translation of fortran binding error numbers to messages */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2000
value|2000
end_define

begin_comment
comment|/*Ignoring function, enumeration type out of 				     range */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2001
value|2001
end_define

begin_comment
comment|/*Ignoring function, output parameter size 				     insufficient */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2002
value|2002
end_define

begin_comment
comment|/*Ignoring function, list or set element 				     not available */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2003
value|2003
end_define

begin_comment
comment|/*Ignoring function, invalid data record */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2004
value|2004
end_define

begin_comment
comment|/*Ignoring function, input parameter size 				     out of range */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2005
value|2005
end_define

begin_comment
comment|/*Ignoring function, invalid list of point 				     lists */
end_comment

begin_define
define|#
directive|define
name|PE_FTN_2006
value|2006
end_define

begin_comment
comment|/*Ignoring function, invalid list of  				     filters */
end_comment

end_unit

