begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: vt100.h,v 4.300 91/06/09 06:14:58 root Rel41 $ SONY  *  *	@(#)vt100.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  vt100 emulator header  */
end_comment

begin_include
include|#
directive|include
file|<news3400/bm/vt100esc.h>
end_include

begin_comment
comment|/*  *  terminal mode  */
end_comment

begin_define
define|#
directive|define
name|KAM
value|0x00000001
end_define

begin_comment
comment|/*  k-action(lock or not) */
end_comment

begin_define
define|#
directive|define
name|IRM
value|0x00000002
end_define

begin_comment
comment|/*  insert mode 	*/
end_comment

begin_define
define|#
directive|define
name|SRM
value|0x00000004
end_define

begin_comment
comment|/*  local echo disable	*/
end_comment

begin_define
define|#
directive|define
name|LNM
value|0x00000008
end_define

begin_comment
comment|/*  new line mode	*/
end_comment

begin_define
define|#
directive|define
name|DECCKM
value|0x00000010
end_define

begin_comment
comment|/*  cursor application	*/
end_comment

begin_define
define|#
directive|define
name|DECCOLM
value|0x00000020
end_define

begin_comment
comment|/*  132 column mode	*/
end_comment

begin_define
define|#
directive|define
name|DECSCLM
value|0x00000040
end_define

begin_comment
comment|/*  jump scroll		*/
end_comment

begin_define
define|#
directive|define
name|DECSCNM
value|0x00000080
end_define

begin_comment
comment|/*  screen reverse	*/
end_comment

begin_define
define|#
directive|define
name|DECOM
value|0x00000100
end_define

begin_comment
comment|/*  origin mode		*/
end_comment

begin_define
define|#
directive|define
name|DECAWM
value|0x00000200
end_define

begin_comment
comment|/*  auto wrap mode	*/
end_comment

begin_define
define|#
directive|define
name|DECARM
value|0x00000400
end_define

begin_comment
comment|/*  auto repeat mode	*/
end_comment

begin_define
define|#
directive|define
name|DECKPA_NM
value|0x00000800
end_define

begin_comment
comment|/*  ten key application	*/
end_comment

begin_define
define|#
directive|define
name|DECCSR_ACTV
value|0x00001000
end_define

begin_comment
comment|/*  cursor active	*/
end_comment

begin_comment
comment|/*  *  cursor attributes  */
end_comment

begin_define
define|#
directive|define
name|NORMALM
value|0x0000
end_define

begin_comment
comment|/*  attributes clear	*/
end_comment

begin_define
define|#
directive|define
name|BOLD
value|0x0001
end_define

begin_comment
comment|/*  bold	*/
end_comment

begin_define
define|#
directive|define
name|USCORE
value|0x0002
end_define

begin_comment
comment|/*  under line	*/
end_comment

begin_define
define|#
directive|define
name|BLINK
value|0x0004
end_define

begin_comment
comment|/*  blinking	*/
end_comment

begin_define
define|#
directive|define
name|REVERSE
value|0x0008
end_define

begin_comment
comment|/*  reverse	*/
end_comment

begin_comment
comment|/*  *  cursor current status  */
end_comment

begin_define
define|#
directive|define
name|ESCAPE
value|0x00000001
end_define

begin_comment
comment|/*  processing esc sequence	*/
end_comment

begin_define
define|#
directive|define
name|WRAP
value|0x00000002
end_define

begin_comment
comment|/*  local flag in addch()	*/
end_comment

begin_define
define|#
directive|define
name|SKANJI
value|0x00000004
end_define

begin_comment
comment|/*  receive kanji shift jis code  */
end_comment

begin_define
define|#
directive|define
name|JKANJI
value|0x00000008
end_define

begin_comment
comment|/*  kanji mode (JIS)	*/
end_comment

begin_define
define|#
directive|define
name|EKANA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EKANJI
value|0x00000020
end_define

begin_comment
comment|/*  *  shift jis code conversion table  */
end_comment

begin_define
define|#
directive|define
name|JVR1S
value|0x81
end_define

begin_comment
comment|/*  starting of vertical range  1	*/
end_comment

begin_define
define|#
directive|define
name|JVR1E
value|0x9f
end_define

begin_comment
comment|/*  ending of vertical range  1		*/
end_comment

begin_define
define|#
directive|define
name|JVR2S
value|0xe0
end_define

begin_comment
comment|/*  starting of vertical range  2	*/
end_comment

begin_define
define|#
directive|define
name|JVR2E
value|0xfc
end_define

begin_comment
comment|/*  ending of vertical range  2		*/
end_comment

begin_define
define|#
directive|define
name|JHR1S
value|0x40
end_define

begin_comment
comment|/*  starting of horizontal range  1	*/
end_comment

begin_define
define|#
directive|define
name|JHR1E
value|0x7e
end_define

begin_comment
comment|/*  ending of horizontal range  1	*/
end_comment

begin_define
define|#
directive|define
name|JHR2S
value|0x80
end_define

begin_comment
comment|/*  starting of horizontal range  2	*/
end_comment

begin_define
define|#
directive|define
name|JHR2E
value|0x9e
end_define

begin_comment
comment|/*  ending of horizontal range  2	*/
end_comment

begin_define
define|#
directive|define
name|JHR3S
value|0x9f
end_define

begin_comment
comment|/*  starting of horizontal range  3	*/
end_comment

begin_define
define|#
directive|define
name|JHR3E
value|0xfc
end_define

begin_comment
comment|/*  ending of horizontal range  3	*/
end_comment

begin_comment
comment|/*  *  EUC conversion table  */
end_comment

begin_define
define|#
directive|define
name|SS2
value|0x8e
end_define

begin_define
define|#
directive|define
name|CS1S
value|0xa1
end_define

begin_define
define|#
directive|define
name|CS1E
value|0xfe
end_define

begin_comment
comment|/*  *  screen width  */
end_comment

begin_define
define|#
directive|define
name|TOP_M
value|1
end_define

begin_comment
comment|/*  screen top margin	*/
end_comment

begin_define
define|#
directive|define
name|LFT_M
value|1
end_define

begin_comment
comment|/*  screen left margin	*/
end_comment

begin_comment
comment|/*  *  default value  */
end_comment

begin_define
define|#
directive|define
name|DIM_CNT_DFLT
value|10
end_define

begin_comment
comment|/*  initial dimmer count	*/
end_comment

begin_define
define|#
directive|define
name|BELL_LEN_DFLT
value|32
end_define

begin_comment
comment|/*  bell length	*/
end_comment

begin_comment
comment|/*  *  max and min value of above values  */
end_comment

begin_define
define|#
directive|define
name|FONT_W_MAX
value|16
end_define

begin_define
define|#
directive|define
name|FONT_W_MIN
value|5
end_define

begin_define
define|#
directive|define
name|FONT_H_MAX
value|32
end_define

begin_define
define|#
directive|define
name|FONT_H_MIN
value|8
end_define

begin_define
define|#
directive|define
name|CHAR_W_MAX
value|16
end_define

begin_define
define|#
directive|define
name|CHAR_W_MIN
value|6
end_define

begin_define
define|#
directive|define
name|CHAR_H_MAX
value|32
end_define

begin_define
define|#
directive|define
name|CHAR_H_MIN
value|9
end_define

begin_define
define|#
directive|define
name|CH_POS_MAX
value|32
end_define

begin_define
define|#
directive|define
name|CH_POS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|UL_POS_MAX
value|32
end_define

begin_define
define|#
directive|define
name|UL_POS_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCR_W_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|SCR_W_MIN
value|0
end_define

begin_define
define|#
directive|define
name|SCR_H_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|SCR_H_MIN
value|0
end_define

begin_define
define|#
directive|define
name|X_OFST_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|X_OFST_MIN
value|0
end_define

begin_define
define|#
directive|define
name|Y_OFST_MAX
value|1024
end_define

begin_define
define|#
directive|define
name|Y_OFST_MIN
value|0
end_define

begin_define
define|#
directive|define
name|RIT_M_MAX
value|136
end_define

begin_define
define|#
directive|define
name|RIT_M_MIN
value|2
end_define

begin_define
define|#
directive|define
name|BTM_M_MAX
value|100
end_define

begin_define
define|#
directive|define
name|BTM_M_MIN
value|1
end_define

begin_define
define|#
directive|define
name|DIM_CNT_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|DIM_CNT_MIN
value|1
end_define

begin_define
define|#
directive|define
name|BELL_LEN_MAX
value|19200
end_define

begin_define
define|#
directive|define
name|BELL_LEN_MIN
value|1
end_define

begin_comment
comment|/*  *  scroll region  */
end_comment

begin_struct
struct|struct
name|region
block|{
name|int
name|top_margin
decl_stmt|;
name|int
name|btm_margin
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  cursor position and status  */
end_comment

begin_struct
struct|struct
name|cursor
block|{
name|int
name|csr_x
decl_stmt|;
comment|/*  cursor position x	*/
name|int
name|csr_y
decl_stmt|;
comment|/*  cursor position y	*/
name|lPoint
name|csr_p
decl_stmt|;
comment|/*  cursor point	*/
name|int
name|csr_attributes
decl_stmt|;
comment|/*  cursor attributes	*/
block|}
struct|;
end_struct

begin_comment
comment|/*  *  screen information  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|screen
block|{
name|int
name|s_term_mode
decl_stmt|;
name|int
name|s_current_stat
decl_stmt|;
comment|/*  current status	*/
name|struct
name|esc_sequence
modifier|*
name|s_estp
decl_stmt|;
comment|/*  for escape handler	*/
name|int
function_decl|(
modifier|*
name|s_esc_handler
function_decl|)
parameter_list|()
function_decl|;
name|int
name|s_plane
decl_stmt|;
comment|/*  color bitmap plane #  */
name|int
name|s_bgcol
decl_stmt|;
comment|/*  back ground color	*/
name|char
name|s_tab_pos
index|[
name|RIT_M_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/*  tab stop position	*/
name|struct
name|cursor
name|s_csr
decl_stmt|;
name|struct
name|region
name|s_region
decl_stmt|;
block|}
name|SCREEN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ESC_BUF_SIZ
value|32
end_define

begin_define
define|#
directive|define
name|PARM_BUF_SIZ
value|8
end_define

begin_define
define|#
directive|define
name|AN_BUF_SIZ
value|32
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|fbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fpn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lPoint
name|fpp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|fpa
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INVALID
value|-1
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|C_MESS_SIZ
value|32
end_define

begin_decl_stmt
specifier|extern
name|int
name|fcolor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bcolor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lRectangle
name|char_r1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lRectangle
name|char_r2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lRectangle
name|font_r1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lRectangle
name|font_r2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font_len1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font_len2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|char_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|char_h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|char_wx2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|font_h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ch_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ul_pos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|x_ofst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|y_ofst
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rit_m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|btm_m
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scr_w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|scr_h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dim_cnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|bell_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|a_dim_on
decl_stmt|;
end_decl_stmt

end_unit

