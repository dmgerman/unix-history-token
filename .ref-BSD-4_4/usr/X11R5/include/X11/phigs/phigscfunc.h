begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: phigscfunc.h,v 5.1 91/02/16 09:49:14 rws Exp $ */
end_comment

begin_comment
comment|/*********************************************************** Copyright 1989, 1990, 1991 by Sun Microsystems, Inc. and the X Consortium.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Sun Microsystems, the X Consortium, and MIT not be used in advertising or publicity  pertaining to distribution of the software without specific, written  prior permission.    SUN MICROSYSTEMS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT  SHALL SUN MICROSYSTEMS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|Pfn_open_phigs
value|(0)
end_define

begin_define
define|#
directive|define
name|Pfn_close_phigs
value|(1)
end_define

begin_define
define|#
directive|define
name|Pfn_open_ws
value|(2)
end_define

begin_define
define|#
directive|define
name|Pfn_close_ws
value|(3)
end_define

begin_define
define|#
directive|define
name|Pfn_redraw_all_structs
value|(4)
end_define

begin_define
define|#
directive|define
name|Pfn_upd_ws
value|(5)
end_define

begin_define
define|#
directive|define
name|Pfn_set_disp_upd_st
value|(6)
end_define

begin_define
define|#
directive|define
name|Pfn_message
value|(7)
end_define

begin_define
define|#
directive|define
name|Pfn_polyline3
value|(8)
end_define

begin_define
define|#
directive|define
name|Pfn_polyline
value|(9)
end_define

begin_define
define|#
directive|define
name|Pfn_polymarker3
value|(10)
end_define

begin_define
define|#
directive|define
name|Pfn_polymarker
value|(11)
end_define

begin_define
define|#
directive|define
name|Pfn_text3
value|(12)
end_define

begin_define
define|#
directive|define
name|Pfn_text
value|(13)
end_define

begin_define
define|#
directive|define
name|Pfn_anno_text_rel3
value|(14)
end_define

begin_define
define|#
directive|define
name|Pfn_anno_text_rel
value|(15)
end_define

begin_define
define|#
directive|define
name|Pfn_fill_area3
value|(16)
end_define

begin_define
define|#
directive|define
name|Pfn_fill_area
value|(17)
end_define

begin_define
define|#
directive|define
name|Pfn_fill_area_set3
value|(18)
end_define

begin_define
define|#
directive|define
name|Pfn_fill_area_set
value|(19)
end_define

begin_define
define|#
directive|define
name|Pfn_cell_array3
value|(20)
end_define

begin_define
define|#
directive|define
name|Pfn_cell_array
value|(21)
end_define

begin_define
define|#
directive|define
name|Pfn_gdp3
value|(22)
end_define

begin_define
define|#
directive|define
name|Pfn_gdp
value|(23)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_ind
value|(24)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_ind
value|(25)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_ind
value|(26)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_ind
value|(27)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_ind
value|(28)
end_define

begin_define
define|#
directive|define
name|Pfn_set_linetype
value|(29)
end_define

begin_define
define|#
directive|define
name|Pfn_set_linewidth
value|(30)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_colr_ind
value|(31)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_type
value|(32)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_size
value|(33)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_colr_ind
value|(34)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_font
value|(35)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_prec
value|(36)
end_define

begin_define
define|#
directive|define
name|Pfn_set_char_expan
value|(37)
end_define

begin_define
define|#
directive|define
name|Pfn_set_char_space
value|(38)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_colr_ind
value|(39)
end_define

begin_define
define|#
directive|define
name|Pfn_char_ht
value|(40)
end_define

begin_define
define|#
directive|define
name|Pfn_char_up_vec
value|(41)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_path
value|(42)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_align
value|(43)
end_define

begin_define
define|#
directive|define
name|Pfn_set_anno_char_ht
value|(44)
end_define

begin_define
define|#
directive|define
name|Pfn_set_anno_char_up_vec
value|(45)
end_define

begin_define
define|#
directive|define
name|Pfn_set_anno_path
value|(46)
end_define

begin_define
define|#
directive|define
name|Pfn_set_anno_align
value|(47)
end_define

begin_define
define|#
directive|define
name|Pfn_set_anno_style
value|(48)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_style
value|(49)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_style_ind
value|(50)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_colr_ind
value|(51)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_flag
value|(52)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edgetype
value|(53)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edgewidth
value|(54)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_colr_ind
value|(55)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pat_size
value|(56)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pat_ref_point_vecs
value|(57)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pat_ref_point
value|(58)
end_define

begin_define
define|#
directive|define
name|Pfn_add_names_set
value|(59)
end_define

begin_define
define|#
directive|define
name|Pfn_remove_names_set
value|(60)
end_define

begin_define
define|#
directive|define
name|Pfn_set_indiv_asf
value|(61)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_rep
value|(62)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_rep
value|(63)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_rep
value|(64)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_rep
value|(65)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_rep
value|(66)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pat_rep
value|(67)
end_define

begin_define
define|#
directive|define
name|Pfn_set_colr_rep
value|(68)
end_define

begin_define
define|#
directive|define
name|Pfn_set_highl_filter
value|(69)
end_define

begin_define
define|#
directive|define
name|Pfn_set_invis_filter
value|(70)
end_define

begin_define
define|#
directive|define
name|Pfn_set_colr_model
value|(71)
end_define

begin_define
define|#
directive|define
name|Pfn_set_hlhsr_id
value|(72)
end_define

begin_define
define|#
directive|define
name|Pfn_set_hlhsr_mode
value|(73)
end_define

begin_define
define|#
directive|define
name|Pfn_set_local_tran3
value|(74)
end_define

begin_define
define|#
directive|define
name|Pfn_set_local_tran
value|(75)
end_define

begin_define
define|#
directive|define
name|Pfn_set_global_tran3
value|(76)
end_define

begin_define
define|#
directive|define
name|Pfn_set_global_tran
value|(77)
end_define

begin_define
define|#
directive|define
name|Pfn_set_model_clip_vol3
value|(78)
end_define

begin_define
define|#
directive|define
name|Pfn_set_model_clip_vol
value|(79)
end_define

begin_define
define|#
directive|define
name|Pfn_set_model_clip_ind
value|(80)
end_define

begin_define
define|#
directive|define
name|Pfn_restore_model_clip_vol
value|(81)
end_define

begin_define
define|#
directive|define
name|Pfn_set_view_ind
value|(82)
end_define

begin_define
define|#
directive|define
name|Pfn_set_view_rep3
value|(83)
end_define

begin_define
define|#
directive|define
name|Pfn_set_view_rep
value|(84)
end_define

begin_define
define|#
directive|define
name|Pfn_set_view_tran_in_pri
value|(85)
end_define

begin_define
define|#
directive|define
name|Pfn_set_ws_win3
value|(86)
end_define

begin_define
define|#
directive|define
name|Pfn_set_ws_win
value|(87)
end_define

begin_define
define|#
directive|define
name|Pfn_set_ws_vp3
value|(88)
end_define

begin_define
define|#
directive|define
name|Pfn_set_ws_vp
value|(89)
end_define

begin_define
define|#
directive|define
name|Pfn_open_struct
value|(90)
end_define

begin_define
define|#
directive|define
name|Pfn_close_struct
value|(91)
end_define

begin_define
define|#
directive|define
name|Pfn_exec_struct
value|(92)
end_define

begin_define
define|#
directive|define
name|Pfn_label
value|(93)
end_define

begin_define
define|#
directive|define
name|Pfn_appl_data
value|(94)
end_define

begin_define
define|#
directive|define
name|Pfn_gse
value|(95)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edit_mode
value|(96)
end_define

begin_define
define|#
directive|define
name|Pfn_copy_all_elems_struct
value|(97)
end_define

begin_define
define|#
directive|define
name|Pfn_set_elem_ptr
value|(98)
end_define

begin_define
define|#
directive|define
name|Pfn_offset_elem_ptr
value|(99)
end_define

begin_define
define|#
directive|define
name|Pfn_set_elem_ptr_label
value|(100)
end_define

begin_define
define|#
directive|define
name|Pfn_del_elem
value|(101)
end_define

begin_define
define|#
directive|define
name|Pfn_del_elem_range
value|(102)
end_define

begin_define
define|#
directive|define
name|Pfn_del_elems_labels
value|(103)
end_define

begin_define
define|#
directive|define
name|Pfn_empty_struct
value|(104)
end_define

begin_define
define|#
directive|define
name|Pfn_del_struct
value|(105)
end_define

begin_define
define|#
directive|define
name|Pfn_del_struct_net
value|(106)
end_define

begin_define
define|#
directive|define
name|Pfn_del_all_struct
value|(107)
end_define

begin_define
define|#
directive|define
name|Pfn_change_struct_id
value|(108)
end_define

begin_define
define|#
directive|define
name|Pfn_change_struct_refs
value|(109)
end_define

begin_define
define|#
directive|define
name|Pfn_change_struct_id_refs
value|(110)
end_define

begin_define
define|#
directive|define
name|Pfn_post_struct
value|(111)
end_define

begin_define
define|#
directive|define
name|Pfn_unpost_struct
value|(112)
end_define

begin_define
define|#
directive|define
name|Pfn_unpost_all_structs
value|(113)
end_define

begin_define
define|#
directive|define
name|Pfn_open_ar_file
value|(114)
end_define

begin_define
define|#
directive|define
name|Pfn_close_ar_file
value|(115)
end_define

begin_define
define|#
directive|define
name|Pfn_ar_structs
value|(116)
end_define

begin_define
define|#
directive|define
name|Pfn_ar_struct_nets
value|(117)
end_define

begin_define
define|#
directive|define
name|Pfn_ar_all_structs
value|(118)
end_define

begin_define
define|#
directive|define
name|Pfn_set_conf_res
value|(119)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_struct_ids
value|(120)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_structs
value|(121)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_struct_nets
value|(122)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_all_structs
value|(123)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_paths_ancest
value|(124)
end_define

begin_define
define|#
directive|define
name|Pfn_ret_paths_descs
value|(125)
end_define

begin_define
define|#
directive|define
name|Pfn_del_structs_ar
value|(126)
end_define

begin_define
define|#
directive|define
name|Pfn_del_struct_nets_ar
value|(127)
end_define

begin_define
define|#
directive|define
name|Pfn_del_all_structs_ar
value|(128)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pick_id
value|(129)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pick_filter
value|(130)
end_define

begin_define
define|#
directive|define
name|Pfn_init_loc3
value|(131)
end_define

begin_define
define|#
directive|define
name|Pfn_init_loc
value|(132)
end_define

begin_define
define|#
directive|define
name|Pfn_init_stroke3
value|(133)
end_define

begin_define
define|#
directive|define
name|Pfn_init_stroke
value|(134)
end_define

begin_define
define|#
directive|define
name|Pfn_init_val3
value|(135)
end_define

begin_define
define|#
directive|define
name|Pfn_init_val
value|(136)
end_define

begin_define
define|#
directive|define
name|Pfn_init_choice3
value|(137)
end_define

begin_define
define|#
directive|define
name|Pfn_init_choice
value|(138)
end_define

begin_define
define|#
directive|define
name|Pfn_init_pick3
value|(139)
end_define

begin_define
define|#
directive|define
name|Pfn_init_pick
value|(140)
end_define

begin_define
define|#
directive|define
name|Pfn_init_string3
value|(141)
end_define

begin_define
define|#
directive|define
name|Pfn_init_string
value|(142)
end_define

begin_define
define|#
directive|define
name|Pfn_set_loc_mode
value|(143)
end_define

begin_define
define|#
directive|define
name|Pfn_set_stroke_mode
value|(144)
end_define

begin_define
define|#
directive|define
name|Pfn_set_val_mode
value|(145)
end_define

begin_define
define|#
directive|define
name|Pfn_set_choice_mode
value|(146)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pick_mode
value|(147)
end_define

begin_define
define|#
directive|define
name|Pfn_set_string_mode
value|(148)
end_define

begin_define
define|#
directive|define
name|Pfn_req_loc3
value|(149)
end_define

begin_define
define|#
directive|define
name|Pfn_req_loc
value|(150)
end_define

begin_define
define|#
directive|define
name|Pfn_req_stroke3
value|(151)
end_define

begin_define
define|#
directive|define
name|Pfn_req_stroke
value|(152)
end_define

begin_define
define|#
directive|define
name|Pfn_req_val
value|(153)
end_define

begin_define
define|#
directive|define
name|Pfn_req_choice
value|(154)
end_define

begin_define
define|#
directive|define
name|Pfn_req_pick
value|(155)
end_define

begin_define
define|#
directive|define
name|Pfn_req_string
value|(156)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_loc3
value|(157)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_loc
value|(158)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_stroke3
value|(159)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_stroke
value|(160)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_val
value|(161)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_choice
value|(162)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_pick
value|(163)
end_define

begin_define
define|#
directive|define
name|Pfn_sample_string
value|(164)
end_define

begin_define
define|#
directive|define
name|Pfn_await_event
value|(165)
end_define

begin_define
define|#
directive|define
name|Pfn_flush_events
value|(166)
end_define

begin_define
define|#
directive|define
name|Pfn_get_loc3
value|(167)
end_define

begin_define
define|#
directive|define
name|Pfn_get_loc
value|(168)
end_define

begin_define
define|#
directive|define
name|Pfn_get_stroke3
value|(169)
end_define

begin_define
define|#
directive|define
name|Pfn_get_stroke
value|(170)
end_define

begin_define
define|#
directive|define
name|Pfn_get_val
value|(171)
end_define

begin_define
define|#
directive|define
name|Pfn_get_choice
value|(172)
end_define

begin_define
define|#
directive|define
name|Pfn_get_pick
value|(173)
end_define

begin_define
define|#
directive|define
name|Pfn_get_string
value|(174)
end_define

begin_define
define|#
directive|define
name|Pfn_write_item
value|(175)
end_define

begin_define
define|#
directive|define
name|Pfn_get_item_type
value|(176)
end_define

begin_define
define|#
directive|define
name|Pfn_read_item
value|(177)
end_define

begin_define
define|#
directive|define
name|Pfn_interpret_item
value|(178)
end_define

begin_define
define|#
directive|define
name|Pfn_set_err_hand_mode
value|(179)
end_define

begin_define
define|#
directive|define
name|Pfn_escape
value|(180)
end_define

begin_comment
comment|/* Note: 181 and 182 are reserved for FORTRAN error handling names:    EPREC and EUREC. */
end_comment

begin_comment
comment|/* Note: 238 is reserved for FORTRAN error handling name: EADDTC. */
end_comment

begin_comment
comment|/* PHIGS PLUS functions.  If these numbers change then they have to be  * changed in PHIGSfnc.txt too.  */
end_comment

begin_define
define|#
directive|define
name|Pfn_phigs_plus_base
value|300
end_define

begin_define
define|#
directive|define
name|Pfn_polyline_set3_data
value|(Pfn_phigs_plus_base + 1)
end_define

begin_define
define|#
directive|define
name|Pfn_fill_area_set3_data
value|(Pfn_phigs_plus_base + 2)
end_define

begin_define
define|#
directive|define
name|Pfn_cell_array3_plus
value|(Pfn_phigs_plus_base + 3)
end_define

begin_define
define|#
directive|define
name|Pfn_set_of_fill_area_set3_data
value|(Pfn_phigs_plus_base + 4)
end_define

begin_define
define|#
directive|define
name|Pfn_tri_strip3_data
value|(Pfn_phigs_plus_base + 5)
end_define

begin_define
define|#
directive|define
name|Pfn_quad_mesh3_data
value|(Pfn_phigs_plus_base + 6)
end_define

begin_define
define|#
directive|define
name|Pfn_nuni_bsp_curv
value|(Pfn_phigs_plus_base + 7)
end_define

begin_define
define|#
directive|define
name|Pfn_nuni_bsp_surf
value|(Pfn_phigs_plus_base + 8)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_int_ind
value|(Pfn_phigs_plus_base + 9)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_colr
value|(Pfn_phigs_plus_base + 10)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_shad_meth
value|(Pfn_phigs_plus_base + 11)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_colr
value|(Pfn_phigs_plus_base + 12)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_colr
value|(Pfn_phigs_plus_base + 13)
end_define

begin_define
define|#
directive|define
name|Pfn_set_face_disting_mode
value|(Pfn_phigs_plus_base + 14)
end_define

begin_define
define|#
directive|define
name|Pfn_set_face_cull_mode
value|(Pfn_phigs_plus_base + 15)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_colr
value|(Pfn_phigs_plus_base + 16)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_shad_meth
value|(Pfn_phigs_plus_base + 17)
end_define

begin_define
define|#
directive|define
name|Pfn_set_area_prop
value|(Pfn_phigs_plus_base + 18)
end_define

begin_define
define|#
directive|define
name|Pfn_set_refl_eqn
value|(Pfn_phigs_plus_base + 19)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_int_style
value|(Pfn_phigs_plus_base + 20)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_int_style_ind
value|(Pfn_phigs_plus_base + 21)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_int_colr
value|(Pfn_phigs_plus_base + 22)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_int_shad_meth
value|(Pfn_phigs_plus_base + 23)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_area_prop
value|(Pfn_phigs_plus_base + 24)
end_define

begin_define
define|#
directive|define
name|Pfn_set_back_refl_eqn
value|(Pfn_phigs_plus_base + 25)
end_define

begin_define
define|#
directive|define
name|Pfn_set_light_src_state
value|(Pfn_phigs_plus_base + 26)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_colr
value|(Pfn_phigs_plus_base + 27)
end_define

begin_define
define|#
directive|define
name|Pfn_set_curve_approx
value|(Pfn_phigs_plus_base + 28)
end_define

begin_define
define|#
directive|define
name|Pfn_set_surf_approx
value|(Pfn_phigs_plus_base + 29)
end_define

begin_define
define|#
directive|define
name|Pfn_set_para_surf_characs
value|(Pfn_phigs_plus_base + 30)
end_define

begin_define
define|#
directive|define
name|Pfn_set_rendering_colr_model
value|(Pfn_phigs_plus_base + 31)
end_define

begin_define
define|#
directive|define
name|Pfn_set_dcue_ind
value|(Pfn_phigs_plus_base + 32)
end_define

begin_define
define|#
directive|define
name|Pfn_set_colr_map_ind
value|(Pfn_phigs_plus_base + 33)
end_define

begin_define
define|#
directive|define
name|Pfn_set_line_rep_plus
value|(Pfn_phigs_plus_base + 34)
end_define

begin_define
define|#
directive|define
name|Pfn_set_marker_rep_plus
value|(Pfn_phigs_plus_base + 35)
end_define

begin_define
define|#
directive|define
name|Pfn_set_text_rep_plus
value|(Pfn_phigs_plus_base + 36)
end_define

begin_define
define|#
directive|define
name|Pfn_set_int_rep_plus
value|(Pfn_phigs_plus_base + 37)
end_define

begin_define
define|#
directive|define
name|Pfn_set_edge_rep_plus
value|(Pfn_phigs_plus_base + 38)
end_define

begin_define
define|#
directive|define
name|Pfn_set_pat_rep_plus
value|(Pfn_phigs_plus_base + 39)
end_define

begin_define
define|#
directive|define
name|Pfn_set_light_src_rep
value|(Pfn_phigs_plus_base + 40)
end_define

begin_define
define|#
directive|define
name|Pfn_set_dcue_rep
value|(Pfn_phigs_plus_base + 41)
end_define

begin_define
define|#
directive|define
name|Pfn_set_colr_map_rep
value|(Pfn_phigs_plus_base + 42)
end_define

begin_comment
comment|/* Binding specific functions */
end_comment

begin_define
define|#
directive|define
name|Pfn_set_err_hand
value|(204)
end_define

begin_define
define|#
directive|define
name|Pfn_create_store
value|(205)
end_define

begin_define
define|#
directive|define
name|Pfn_delete_store
value|(206)
end_define

begin_comment
comment|/* SI specific functions */
end_comment

begin_define
define|#
directive|define
name|Pfn_phigs_ws_type_create
value|(-1)
end_define

begin_define
define|#
directive|define
name|Pfn_phigs_ws_type_set
value|(-2)
end_define

begin_define
define|#
directive|define
name|Pfn_phigs_ws_type_get
value|(-3)
end_define

begin_define
define|#
directive|define
name|Pfn_phigs_ws_type_destroy
value|(-4)
end_define

begin_define
define|#
directive|define
name|Pfn_popenpex
value|(-5)
end_define

begin_comment
comment|/* Internal -1 */
end_comment

begin_define
define|#
directive|define
name|Pfn_INQUIRY
value|(-9999)
end_define

end_unit

