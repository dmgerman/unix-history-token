begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The following is the structure which defines what a 3270 keystroke  * can do.  */
end_comment

begin_struct
struct|struct
name|hits
block|{
name|unsigned
name|char
name|keynumber
decl_stmt|;
struct|struct
name|hit
block|{
enum|enum
name|type
block|{
name|undefined
init|=
literal|0
block|,
name|illegal
block|,
name|character
block|,
name|function
block|,
name|aid
block|}
name|type
enum|;
name|unsigned
name|char
name|code
decl_stmt|;
comment|/* AID value; 3270 display code; function id */
block|}
name|hit
index|[
literal|4
index|]
struct|;
comment|/* plain, shifted, alted, shiftalted */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|hits
name|hits
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The following are the various functions which the keyboard can ask  * the controller to perform.  *  * Note that this file (the following entries) are scanned by mkhit.c,  * and that the format must remain more-or-less consistent  * (#define\tFCN_name\t[\t]*TOKEN)  */
end_comment

begin_define
define|#
directive|define
name|FCN_NULL
value|131
end_define

begin_comment
comment|/* Illegal sequence */
end_comment

begin_define
define|#
directive|define
name|FCN_VERTICAL_BAR
value|132
end_define

begin_define
define|#
directive|define
name|FCN_CAPS_LOCK
value|134
end_define

begin_define
define|#
directive|define
name|FCN_MAKE_SHIFT
value|135
end_define

begin_define
define|#
directive|define
name|FCN_DVCNL
value|136
end_define

begin_define
define|#
directive|define
name|FCN_MAKE_ALT
value|137
end_define

begin_define
define|#
directive|define
name|FCN_SPACE
value|138
end_define

begin_define
define|#
directive|define
name|FCN_LEFT2
value|139
end_define

begin_define
define|#
directive|define
name|FCN_RIGHT2
value|140
end_define

begin_define
define|#
directive|define
name|FCN_MONOCASE
value|141
end_define

begin_define
define|#
directive|define
name|FCN_BREAK_SHIFT
value|142
end_define

begin_define
define|#
directive|define
name|FCN_BREAK_ALT
value|143
end_define

begin_define
define|#
directive|define
name|FCN_ATTN
value|144
end_define

begin_define
define|#
directive|define
name|FCN_LPRT
value|145
end_define

begin_define
define|#
directive|define
name|FCN_DP
value|146
end_define

begin_define
define|#
directive|define
name|FCN_FM
value|147
end_define

begin_define
define|#
directive|define
name|FCN_CURSEL
value|148
end_define

begin_define
define|#
directive|define
name|FCN_CENTSIGN
value|149
end_define

begin_define
define|#
directive|define
name|FCN_RESHOW
value|150
end_define

begin_define
define|#
directive|define
name|FCN_EINP
value|151
end_define

begin_define
define|#
directive|define
name|FCN_EEOF
value|152
end_define

begin_define
define|#
directive|define
name|FCN_DELETE
value|153
end_define

begin_define
define|#
directive|define
name|FCN_INSRT
value|154
end_define

begin_define
define|#
directive|define
name|FCN_TAB
value|155
end_define

begin_define
define|#
directive|define
name|FCN_BTAB
value|156
end_define

begin_define
define|#
directive|define
name|FCN_COLTAB
value|157
end_define

begin_define
define|#
directive|define
name|FCN_COLBAK
value|158
end_define

begin_define
define|#
directive|define
name|FCN_INDENT
value|159
end_define

begin_define
define|#
directive|define
name|FCN_UNDENT
value|160
end_define

begin_define
define|#
directive|define
name|FCN_NL
value|161
end_define

begin_define
define|#
directive|define
name|FCN_HOME
value|162
end_define

begin_define
define|#
directive|define
name|FCN_UP
value|163
end_define

begin_define
define|#
directive|define
name|FCN_DOWN
value|164
end_define

begin_define
define|#
directive|define
name|FCN_RIGHT
value|165
end_define

begin_define
define|#
directive|define
name|FCN_LEFT
value|166
end_define

begin_define
define|#
directive|define
name|FCN_SETTAB
value|167
end_define

begin_define
define|#
directive|define
name|FCN_DELTAB
value|168
end_define

begin_define
define|#
directive|define
name|FCN_SETMRG
value|169
end_define

begin_define
define|#
directive|define
name|FCN_SETHOM
value|170
end_define

begin_define
define|#
directive|define
name|FCN_CLRTAB
value|171
end_define

begin_define
define|#
directive|define
name|FCN_APLON
value|172
end_define

begin_define
define|#
directive|define
name|FCN_APLOFF
value|173
end_define

begin_define
define|#
directive|define
name|FCN_APLEND
value|174
end_define

begin_define
define|#
directive|define
name|FCN_PCON
value|175
end_define

begin_define
define|#
directive|define
name|FCN_PCOFF
value|176
end_define

begin_define
define|#
directive|define
name|FCN_DISC
value|177
end_define

begin_define
define|#
directive|define
name|FCN_INIT
value|178
end_define

begin_define
define|#
directive|define
name|FCN_ALTK
value|179
end_define

begin_define
define|#
directive|define
name|FCN_FLINP
value|180
end_define

begin_define
define|#
directive|define
name|FCN_ERASE
value|181
end_define

begin_define
define|#
directive|define
name|FCN_WERASE
value|182
end_define

begin_define
define|#
directive|define
name|FCN_FERASE
value|183
end_define

begin_define
define|#
directive|define
name|FCN_SYNCH
value|184
end_define

begin_define
define|#
directive|define
name|FCN_RESET
value|185
end_define

begin_define
define|#
directive|define
name|FCN_MASTER_RESET
value|186
end_define

begin_define
define|#
directive|define
name|FCN_XOFF
value|187
end_define

begin_define
define|#
directive|define
name|FCN_XON
value|188
end_define

begin_define
define|#
directive|define
name|FCN_ESCAPE
value|189
end_define

begin_define
define|#
directive|define
name|FCN_WORDTAB
value|190
end_define

begin_define
define|#
directive|define
name|FCN_WORDBACKTAB
value|191
end_define

begin_define
define|#
directive|define
name|FCN_WORDEND
value|192
end_define

begin_define
define|#
directive|define
name|FCN_FIELDEND
value|193
end_define

begin_define
define|#
directive|define
name|FCN_MAKE_CTRL
value|194
end_define

begin_define
define|#
directive|define
name|FCN_TEST
value|195
end_define

end_unit

