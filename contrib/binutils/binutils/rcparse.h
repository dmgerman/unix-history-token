begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
union|union
block|{
name|struct
name|accelerator
name|acc
decl_stmt|;
name|struct
name|accelerator
modifier|*
name|pacc
decl_stmt|;
name|struct
name|dialog_control
modifier|*
name|dialog_control
decl_stmt|;
name|struct
name|menuitem
modifier|*
name|menuitem
decl_stmt|;
struct|struct
block|{
name|struct
name|rcdata_item
modifier|*
name|first
decl_stmt|;
name|struct
name|rcdata_item
modifier|*
name|last
decl_stmt|;
block|}
name|rcdata
struct|;
name|struct
name|rcdata_item
modifier|*
name|rcdata_item
decl_stmt|;
name|struct
name|stringtable_data
modifier|*
name|stringtable
decl_stmt|;
name|struct
name|fixed_versioninfo
modifier|*
name|fixver
decl_stmt|;
name|struct
name|ver_info
modifier|*
name|verinfo
decl_stmt|;
name|struct
name|ver_stringinfo
modifier|*
name|verstring
decl_stmt|;
name|struct
name|ver_varinfo
modifier|*
name|vervar
decl_stmt|;
name|struct
name|res_id
name|id
decl_stmt|;
name|struct
name|res_res_info
name|res_info
decl_stmt|;
struct|struct
block|{
name|unsigned
name|short
name|on
decl_stmt|;
name|unsigned
name|short
name|off
decl_stmt|;
block|}
name|memflags
struct|;
struct|struct
block|{
name|unsigned
name|long
name|val
decl_stmt|;
comment|/* Nonzero if this number was explicitly specified as long.  */
name|int
name|dword
decl_stmt|;
block|}
name|i
struct|;
name|unsigned
name|long
name|il
decl_stmt|;
name|unsigned
name|short
name|is
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|length
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
block|}
name|ss
struct|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BEG
value|257
end_define

begin_define
define|#
directive|define
name|END
value|258
end_define

begin_define
define|#
directive|define
name|ACCELERATORS
value|259
end_define

begin_define
define|#
directive|define
name|VIRTKEY
value|260
end_define

begin_define
define|#
directive|define
name|ASCII
value|261
end_define

begin_define
define|#
directive|define
name|NOINVERT
value|262
end_define

begin_define
define|#
directive|define
name|SHIFT
value|263
end_define

begin_define
define|#
directive|define
name|CONTROL
value|264
end_define

begin_define
define|#
directive|define
name|ALT
value|265
end_define

begin_define
define|#
directive|define
name|BITMAP
value|266
end_define

begin_define
define|#
directive|define
name|CURSOR
value|267
end_define

begin_define
define|#
directive|define
name|DIALOG
value|268
end_define

begin_define
define|#
directive|define
name|DIALOGEX
value|269
end_define

begin_define
define|#
directive|define
name|EXSTYLE
value|270
end_define

begin_define
define|#
directive|define
name|CAPTION
value|271
end_define

begin_define
define|#
directive|define
name|CLASS
value|272
end_define

begin_define
define|#
directive|define
name|STYLE
value|273
end_define

begin_define
define|#
directive|define
name|AUTO3STATE
value|274
end_define

begin_define
define|#
directive|define
name|AUTOCHECKBOX
value|275
end_define

begin_define
define|#
directive|define
name|AUTORADIOBUTTON
value|276
end_define

begin_define
define|#
directive|define
name|CHECKBOX
value|277
end_define

begin_define
define|#
directive|define
name|COMBOBOX
value|278
end_define

begin_define
define|#
directive|define
name|CTEXT
value|279
end_define

begin_define
define|#
directive|define
name|DEFPUSHBUTTON
value|280
end_define

begin_define
define|#
directive|define
name|EDITTEXT
value|281
end_define

begin_define
define|#
directive|define
name|GROUPBOX
value|282
end_define

begin_define
define|#
directive|define
name|LISTBOX
value|283
end_define

begin_define
define|#
directive|define
name|LTEXT
value|284
end_define

begin_define
define|#
directive|define
name|PUSHBOX
value|285
end_define

begin_define
define|#
directive|define
name|PUSHBUTTON
value|286
end_define

begin_define
define|#
directive|define
name|RADIOBUTTON
value|287
end_define

begin_define
define|#
directive|define
name|RTEXT
value|288
end_define

begin_define
define|#
directive|define
name|SCROLLBAR
value|289
end_define

begin_define
define|#
directive|define
name|STATE3
value|290
end_define

begin_define
define|#
directive|define
name|USERBUTTON
value|291
end_define

begin_define
define|#
directive|define
name|BEDIT
value|292
end_define

begin_define
define|#
directive|define
name|HEDIT
value|293
end_define

begin_define
define|#
directive|define
name|IEDIT
value|294
end_define

begin_define
define|#
directive|define
name|FONT
value|295
end_define

begin_define
define|#
directive|define
name|ICON
value|296
end_define

begin_define
define|#
directive|define
name|LANGUAGE
value|297
end_define

begin_define
define|#
directive|define
name|CHARACTERISTICS
value|298
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|299
end_define

begin_define
define|#
directive|define
name|MENU
value|300
end_define

begin_define
define|#
directive|define
name|MENUEX
value|301
end_define

begin_define
define|#
directive|define
name|MENUITEM
value|302
end_define

begin_define
define|#
directive|define
name|SEPARATOR
value|303
end_define

begin_define
define|#
directive|define
name|POPUP
value|304
end_define

begin_define
define|#
directive|define
name|CHECKED
value|305
end_define

begin_define
define|#
directive|define
name|GRAYED
value|306
end_define

begin_define
define|#
directive|define
name|HELP
value|307
end_define

begin_define
define|#
directive|define
name|INACTIVE
value|308
end_define

begin_define
define|#
directive|define
name|MENUBARBREAK
value|309
end_define

begin_define
define|#
directive|define
name|MENUBREAK
value|310
end_define

begin_define
define|#
directive|define
name|MESSAGETABLE
value|311
end_define

begin_define
define|#
directive|define
name|RCDATA
value|312
end_define

begin_define
define|#
directive|define
name|STRINGTABLE
value|313
end_define

begin_define
define|#
directive|define
name|VERSIONINFO
value|314
end_define

begin_define
define|#
directive|define
name|FILEVERSION
value|315
end_define

begin_define
define|#
directive|define
name|PRODUCTVERSION
value|316
end_define

begin_define
define|#
directive|define
name|FILEFLAGSMASK
value|317
end_define

begin_define
define|#
directive|define
name|FILEFLAGS
value|318
end_define

begin_define
define|#
directive|define
name|FILEOS
value|319
end_define

begin_define
define|#
directive|define
name|FILETYPE
value|320
end_define

begin_define
define|#
directive|define
name|FILESUBTYPE
value|321
end_define

begin_define
define|#
directive|define
name|BLOCKSTRINGFILEINFO
value|322
end_define

begin_define
define|#
directive|define
name|BLOCKVARFILEINFO
value|323
end_define

begin_define
define|#
directive|define
name|VALUE
value|324
end_define

begin_define
define|#
directive|define
name|BLOCK
value|325
end_define

begin_define
define|#
directive|define
name|MOVEABLE
value|326
end_define

begin_define
define|#
directive|define
name|FIXED
value|327
end_define

begin_define
define|#
directive|define
name|PURE
value|328
end_define

begin_define
define|#
directive|define
name|IMPURE
value|329
end_define

begin_define
define|#
directive|define
name|PRELOAD
value|330
end_define

begin_define
define|#
directive|define
name|LOADONCALL
value|331
end_define

begin_define
define|#
directive|define
name|DISCARDABLE
value|332
end_define

begin_define
define|#
directive|define
name|NOT
value|333
end_define

begin_define
define|#
directive|define
name|QUOTEDSTRING
value|334
end_define

begin_define
define|#
directive|define
name|STRING
value|335
end_define

begin_define
define|#
directive|define
name|NUMBER
value|336
end_define

begin_define
define|#
directive|define
name|SIZEDSTRING
value|337
end_define

begin_define
define|#
directive|define
name|IGNORED_TOKEN
value|338
end_define

begin_define
define|#
directive|define
name|NEG
value|339
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

