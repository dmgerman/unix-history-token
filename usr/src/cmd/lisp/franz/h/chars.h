begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  @(#)chars.h	35.1  5/6/81  */
end_comment

begin_comment
comment|/* lexical table for input and output ***********************************/
end_comment

begin_comment
comment|/* the format of the entries are:       ab..xxxx			*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/* where a is set iff the atom containing the symbol must be quoted	*/
end_comment

begin_comment
comment|/* where b is set iff the character separates atoms normally		*/
end_comment

begin_comment
comment|/* where xxxx is a number unique to the class of symbol			*/
end_comment

begin_define
define|#
directive|define
name|VNUM
value|0000
end_define

begin_define
define|#
directive|define
name|VMINUS
value|0001
end_define

begin_define
define|#
directive|define
name|VSIGN
value|0001
end_define

begin_define
define|#
directive|define
name|VCHAR
value|0002
end_define

begin_define
define|#
directive|define
name|VSCA
value|0102
end_define

begin_define
define|#
directive|define
name|VLPARA
value|0303
end_define

begin_define
define|#
directive|define
name|VRPARA
value|0304
end_define

begin_define
define|#
directive|define
name|VPERD
value|0205
end_define

begin_define
define|#
directive|define
name|VLBRCK
value|0306
end_define

begin_define
define|#
directive|define
name|VRBRCK
value|0307
end_define

begin_define
define|#
directive|define
name|VEOF
value|0310
end_define

begin_define
define|#
directive|define
name|VSQ
value|0311
end_define

begin_define
define|#
directive|define
name|VDQ
value|0212
end_define

begin_define
define|#
directive|define
name|VSD
value|0211
end_define

begin_define
define|#
directive|define
name|VERR
value|0313
end_define

begin_define
define|#
directive|define
name|VSEP
value|0314
end_define

begin_define
define|#
directive|define
name|VSPL
value|0315
end_define

begin_define
define|#
directive|define
name|VMAC
value|0316
end_define

begin_define
define|#
directive|define
name|VESC
value|0217
end_define

begin_define
define|#
directive|define
name|VQUO
value|0326
end_define

begin_define
define|#
directive|define
name|QUTMASK
value|0200
end_define

begin_define
define|#
directive|define
name|SEPMASK
value|0100
end_define

begin_define
define|#
directive|define
name|TSCA
value|1
end_define

begin_define
define|#
directive|define
name|TLPARA
value|2
end_define

begin_define
define|#
directive|define
name|TRPARA
value|3
end_define

begin_define
define|#
directive|define
name|TPERD
value|4
end_define

begin_define
define|#
directive|define
name|TEOF
value|5
end_define

begin_define
define|#
directive|define
name|TSPL
value|6
end_define

begin_define
define|#
directive|define
name|TMAC
value|7
end_define

begin_define
define|#
directive|define
name|TSQ
value|8
end_define

begin_define
define|#
directive|define
name|TLBKT
value|9
end_define

end_unit

