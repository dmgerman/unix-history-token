begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987 Xerox Corporation.  */
end_comment

begin_comment
comment|/* $Log:	filetypes.h,v $  * Revision 1.2  87/03/17  16:32:04  ed  * Yet more file types added.  *   * Revision 1.1  87/01/14  11:41:51  ed  * Initial revision  *   *   */
end_comment

begin_comment
comment|/*  * Common Viewpoint file types  */
end_comment

begin_define
define|#
directive|define
name|TYPE_I
value|0
end_define

begin_comment
comment|/* image and Type=tUnspecified */
end_comment

begin_define
define|#
directive|define
name|TYPE_Directory
value|1
end_define

begin_comment
comment|/* Type=tDirectory: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_A
value|2
end_define

begin_comment
comment|/* ASCII -- map CR<=> LF and Type=tText */
end_comment

begin_define
define|#
directive|define
name|TYPE_S
value|3
end_define

begin_comment
comment|/* Serialized file Type=tSerialized */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPMailNote
value|4
end_define

begin_comment
comment|/* VP Mail Note: ASCII */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPDrawer
value|4098
end_define

begin_comment
comment|/* VP File Drawer: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_Font
value|4290
end_define

begin_comment
comment|/* printer fonts: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VP
value|4353
end_define

begin_comment
comment|/* ViewPoint: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_Interpress
value|4361
end_define

begin_comment
comment|/* VP Interpress master: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPRecordsfile
value|4365
end_define

begin_comment
comment|/* VP Records file: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPSpreadsheet
value|4381
end_define

begin_comment
comment|/* VP Spreadsheet: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPDictionary
value|4383
end_define

begin_comment
comment|/* VP Dictionary: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPApplication
value|4387
end_define

begin_comment
comment|/* VP Application: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPApplication2
value|4423
end_define

begin_comment
comment|/* VP Application: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPReference
value|4427
end_define

begin_comment
comment|/* VP Reference Icon: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPCalendar
value|4436
end_define

begin_comment
comment|/* VP Calendar: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPBook
value|4444
end_define

begin_comment
comment|/* VP Book: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPCanvas
value|4428
end_define

begin_comment
comment|/* VP Canvas: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_860
value|5120
end_define

begin_comment
comment|/* 860 file: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_VPIcons
value|6010
end_define

begin_comment
comment|/* VP Icon file: image */
end_comment

begin_define
define|#
directive|define
name|TYPE_Guess
value|4294967295
end_define

begin_comment
comment|/* escape to use actual file type */
end_comment

begin_comment
comment|/*  * last type reserved for Filing  * files of type> will have attributes saved with file  */
end_comment

begin_define
define|#
directive|define
name|LAST_FILING_TYPE
value|4095
end_define

begin_comment
comment|/*  * Headers for common file types  * (lower case is used to ease string comparisons)  *  * NOTE: only Interpress and RES are "official" Xerox headers, the others  * 	 are merely a convenience for recognizing other Viewpoint related  *	 formats when stored locally.  */
end_comment

begin_define
define|#
directive|define
name|INTERPRESSHDR
value|"interpress/xerox"
end_define

begin_define
define|#
directive|define
name|RESHDR
value|"rasterencoding"
end_define

begin_define
define|#
directive|define
name|VPHDR
value|"viewpoint-file/xerox"
end_define

end_unit

